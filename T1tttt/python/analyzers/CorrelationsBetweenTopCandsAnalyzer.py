import operator, pickle, pprint, math, re
from CMGTools.RootTools.fwlite.Analyzer import Analyzer
#from CMGTools.RootTools.analyzers.GenParticleAnalyzer import GenParticleAnalyzer
from Lucie.T1tttt.analyzers.TopTupleReader import TopTupleReader
from CMGTools.RootTools.statistics.Counter import Counter, Counters
from CMGTools.RootTools.fwlite.AutoHandle import AutoHandle
from CMGTools.RootTools.utils.DeltaR import deltaR
from CMGTools.RootTools.fwlite.Analyzer import Analyzer
from Lucie.T1tttt.physicsobjects.PhysicsObjects import GenJet, Jet, RecoJet
from CMGTools.RootTools.physicsobjects.PileUpSummaryInfo import PileUpSummaryInfo
from ROOT import TH1F, TH2F, TH1I, TH2I, TFile, TF1, TFitResultPtr, TGraphErrors
from math import sqrt
from array import array

class CorrelationsBetweenTopCandsAnalyzer( Analyzer ): # maybe could inherit from reclustered jets...or have some mother class for both
    '''Analyze top candidates in topTuples..'''

    def __init__( self, cfg_ana, cfg_comp, looperName ):
        super(CorrelationsBetweenTopCandsAnalyzer,self).__init__( cfg_ana, cfg_comp, looperName )
        self.jetCollections       = cfg_ana.jetCollections
        self.listOfJetCollections = self.jetCollections.keys()
     
    def beginLoop(self):
        super(CorrelationsBetweenTopCandsAnalyzer,self).beginLoop()
        self.file = TFile ('/'.join ([self.dirName, 'output.root']),
                                 'recreate')     
     
        nJetAlgos                          = len( self.listOfJetCollections )
        self.numberOfTopCandidates         = TH1I ('numberOfTopCandidates', 'number Of Top Candidates', nJetAlgos, 0, nJetAlgos) 
        self.numberOfTopCandidatesAvsA     = TH2I ('numberOfTopCandidatesAvsA', 'number Of Top Candidates, algo vs algo', 4*nJetAlgos, 0, 4*nJetAlgos, 4*nJetAlgos, 0, 4*nJetAlgos) 

        self.histos = [
            self.numberOfTopCandidates,
            self.numberOfTopCandidatesAvsA
            ]

        self.histosdR = {}
        self.histosPtMatchedTopCandidates  = {}
        self.histosEtaMatchedTopCandidates = {}
        self.histosPhiMatchedTopCandidates = {}
        
        for jetColl0 in self.listOfJetCollections :
            for jetColl1 in self.listOfJetCollections :
            
                self.histosdR[jetColl0+'_'+jetColl1] = TH1F("dR"+jetColl0+'_'+jetColl1, "dR "+jetColl0+'_'+jetColl1, 1000, 0., 100.)
                self.histosPtMatchedTopCandidates[jetColl0+'_'+jetColl1] = TH2F("ptMatchedTopCandidates"+jetColl0+'_'+jetColl1, "pt matched top candidates "+jetColl0+'_'+jetColl1, 200, 0., 1000., 200, 0., 1000. )
                self.histosEtaMatchedTopCandidates[jetColl0+'_'+jetColl1]= TH2F("etaMatchedTopCandidates"+jetColl0+'_'+jetColl1, "eta matched top candidates "+jetColl0+'_'+jetColl1, 200, -10., 10., 200, -10., 10. )
                self.histosPhiMatchedTopCandidates[jetColl0+'_'+jetColl1]= TH2F("phiMatchedTopCandidates"+jetColl0+'_'+jetColl1, "phi matched top candidates "+jetColl0+'_'+jetColl1, 64, -3.2, 3.2, 64, -3.2, 3.2 )
        
        
    def process(self, iEvent, event):
        self.readCollections( iEvent )
        event.topCandidates = {}

        jetCollBin = 0
        for jetColl in self.listOfJetCollections :
            #grab jet collection with label jetColl
            event.topCandidates[jetColl] = self.buildTopJets( self.mchandles[jetColl].product(), event )
            self.numberOfTopCandidates.Fill(jetCollBin, len(event.topCandidates[jetColl]) )
            self.numberOfTopCandidates.GetXaxis().SetBinLabel(jetCollBin+1, jetColl)
            jetCollBin+=1

        jetCollBin0 = 0
        for jetColl0 in self.listOfJetCollections :
            jetCollBin1 = 0
            for jetColl1 in self.listOfJetCollections :
                if ( jetColl0 == jetColl1 and not ( jetCollBin0*4 + len(event.topCandidates[jetColl0]) == jetCollBin1*4 +len(event.topCandidates[jetColl1]) ) ) :
                    print jetColl0, jetColl1
                self.numberOfTopCandidatesAvsA.Fill( jetCollBin0*4 + len(event.topCandidates[jetColl0]), jetCollBin1*4 +len(event.topCandidates[jetColl1]) )
                self.numberOfTopCandidatesAvsA.GetXaxis().SetBinLabel(jetCollBin0*4  +1, re.sub('Recluster','',re.sub('topCandidates','',jetColl0)))
                self.numberOfTopCandidatesAvsA.GetYaxis().SetBinLabel(jetCollBin1*4  +1, re.sub('Recluster','',re.sub('topCandidates','',jetColl1)))
                jetCollBin1+=1

                if ( len( event.topCandidates[jetColl0] ) == len( event.topCandidates[jetColl1] )) :
                    for topCand0 in event.topCandidates[jetColl0] :
                        dRtop0top1 = 100
                        for topCand1 in event.topCandidates[jetColl1] :
                            dRtop0top1 = min(dRtop0top1, deltaR(topCand0.eta(), topCand0.phi(),topCand1.eta(),topCand1.phi() ))
                        self.histosdR[jetColl0+'_'+jetColl1].Fill( dRtop0top1 )
                        if (dRtop0top1 < 0.3):
                            self.histosPtMatchedTopCandidates[jetColl0+'_'+jetColl1].Fill( topCand0.pt(), topCand1.pt())
                            self.histosEtaMatchedTopCandidates[jetColl0+'_'+jetColl1].Fill( topCand0.eta(), topCand1.eta())
                            self.histosPhiMatchedTopCandidates[jetColl0+'_'+jetColl1].Fill( topCand0.phi(), topCand1.phi())
                            
                        
            jetCollBin0+=1
               
           
      
        return True

    def buildTopJets(self, topJet, event):
        '''Creates python topJets from the topJets read from the disk.
        to be overloaded if needed.'''
        return map( RecoJet, topJet )

    def write(self): 
       for histo in self.histos :
            histo.Write( histo.GetName() )
       for jetColl0 in self.listOfJetCollections :
            for jetColl1 in self.listOfJetCollections :
                self.histosdR[jetColl0+'_'+jetColl1].Write()
                self.histosPtMatchedTopCandidates[jetColl0+'_'+jetColl1].Write()
                self.histosEtaMatchedTopCandidates[jetColl0+'_'+jetColl1].Write()
                self.histosPhiMatchedTopCandidates[jetColl0+'_'+jetColl1].Write()
        
    def endLoop(self):#should called before write
        super(CorrelationsBetweenTopCandsAnalyzer,self).endLoop()
       
    def declareHandles(self):
        super(CorrelationsBetweenTopCandsAnalyzer,self).declareHandles()

        for jetColl in self.listOfJetCollections : 
            self.mchandles[ jetColl ] = AutoHandle(
            jetColl,
            'edm::OwnVector<reco::Candidate,edm::ClonePolicy<reco::Candidate> >'
            # 'std::vector<reco::BasicJet>' 
            )
       
