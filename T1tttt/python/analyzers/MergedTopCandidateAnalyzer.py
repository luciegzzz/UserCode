import operator, pickle, pprint, math, re
#from CMGTools.RootTools.fwlite.Analyzer import Analyzer
from CMGTools.RootTools.analyzers.GenParticleAnalyzer import GenParticleAnalyzer
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

class MergedTopCandidateAnalyzer( GenParticleAnalyzer ): # maybe could inherit from reclustered jets...or have some mother class for both
    '''Analyze top candidates in topTuples..'''

    def __init__( self, cfg_ana, cfg_comp, looperName ):
        super(MergedTopCandidateAnalyzer,self).__init__( cfg_ana, cfg_comp, looperName )
        self.listOfTopCandidates       = cfg_ana.listOfTopCandidates
        
    def beginLoop(self):
        super(MergedTopCandidateAnalyzer,self).beginLoop()
        self.file = TFile ('/'.join ([self.dirName, 'output.root']),
                                 'recreate')
        #helpers
        self.nTotEvents = 0

        #histos
        self.matchingTopCandidates        =  \
        TH1F("matchingTopCandidates","matched / not matched top candidates, algo by algo", 2*len(self.listOfTopCandidates), 0, 2*len(self.listOfTopCandidates))
        self.matchingWhenTwoTopCandidates =  \
        TH1F("matchingTopCandidatesWhenTwoTopCandidates","matched / not matched top candidates, algo by algo, when 2 top candidates", 2*len(self.listOfTopCandidates), 0, 2*len(self.listOfTopCandidates))
        self.matchingWhenOneTopCandidate =  \
        TH1F("matchingTopCandidateWhenOneTopCandidate","matched / not matched top candidates, algo by algo, when 1 top candidate", 2*len(self.listOfTopCandidates), 0, 2*len(self.listOfTopCandidates))

        
        self.histos = [
            self.matchingTopCandidates,
            self.matchingWhenTwoTopCandidates,
            self.matchingWhenOneTopCandidate
            ]
        
        self.histosdRtopGenTop            = {}
        self.matchingTopCandidatesPt      = {}
        self.histosGendRWhenTwoCandidates = {}
        self.histosGenPtWhenTwoCandidates = {}
        self.histosGendRWhenOneCandidate  = {}
        self.histosGenPtWhenOneCandidate  = {}
        self.histosGendRWhenNoCandidate   = {}
        self.histosGenPtWhenNoCandidate   = {}
        
        for algo in self.listOfTopCandidates :
            self.histosdRtopGenTop[algo]       = TH1F("dRtopGenTop_"+algo, "dRtopGenTop, "+algo, 100, 0., 5.)
            self.matchingTopCandidatesPt[algo] =  \
            TH2F("matchingTopCandidatesPt_"+algo,"pt reco vs pt gen matched", 200, 0., 1000., 200, 0., 1000.)
            self.histosGendRWhenTwoCandidates[algo] = \
            TH1F("histosGendRWhenTwoCandidates_"+algo,"dR between gen tops when 2 candidates", 100, 0., 5.)
            self.histosGenPtWhenTwoCandidates[algo] = \
            TH2F("histosGenPtWhenTwoCandidates_"+algo,"pt top 1 vs pt top 0 when 2 candidates", 200, 0., 1000., 200, 0., 1000.)
            self.histosGendRWhenOneCandidate[algo] = \
            TH1F("histosGendRWhenOneCandidate_"+algo,"dR between gen tops when 1 candidate", 100, 0., 5.)
            self.histosGenPtWhenOneCandidate[algo] = \
            TH2F("histosGenPtWhenOneCandidate_"+algo,"pt top 1 vs pt top 0 when 1 candidate", 200, 0., 1000., 200, 0., 1000.)
            self.histosGendRWhenNoCandidate[algo] = \
            TH1F("histosGendRWhenNoCandidate_"+algo,"dR between gen tops when no candidate", 100, 0., 5.)
            self.histosGenPtWhenNoCandidate[algo] = \
            TH2F("histosGenPtWhenNoCandidate_"+algo,"pt top 1 vs pt top 0 when no candidate", 200, 0., 1000., 200, 0., 1000.)
           
    def process(self, iEvent, event):
        self.nTotEvents+=1
        
        super(MergedTopCandidateAnalyzer,self).process(iEvent, event)
        event.topCandidates = {}
        algoBin = 0
        for algo in self.listOfTopCandidates : 
            event.topCandidates[algo] = self.buildTopCandidates( self.mchandles[algo].product(), event )
            self.matchingTopCandidates.GetXaxis().SetBinLabel( algoBin*2 + 1, re.sub('0p71p75','',re.sub( 'build', '',algo))+", not matched")
            self.matchingTopCandidates.GetXaxis().SetBinLabel( algoBin*2 + 2, re.sub('0p71p75','',re.sub( 'build', '',algo))+", matched")

            #for gen tops analysis
            genTopsPt  = []
            genTopsEta = []
            genTopsPhi = []
            for gen in event.genParticles :
                    if (gen.status() == 3):
                        if ( abs( gen.pdgId() ) == 6 ):
                            genTopsPt.append( gen.pt() )
                            genTopsEta.append( gen.eta() )
                            genTopsPhi.append( gen.phi() )
            if not ( len( genTopsPt )  == 2 ) :
                print 'found ', len( genTopsPt ), 'gen tops'
            dRGenTops = deltaR( genTopsEta[0], genTopsPhi[0], genTopsEta[1], genTopsPhi[1] )

            #analyze top candidates
            for top in event.topCandidates[algo] :
                dRtopGenTop = 1000.
                matchedPt   = -10.
                for gen in event.genParticles :
                    if (gen.status() == 3):
                        if ( abs( gen.pdgId() ) == 6 ):
                            self.histosdRtopGenTop[algo].Fill( deltaR( top.eta(), top.phi(), gen.eta(), gen.phi() ) )
                            dRtopGenTopTmp = dRtopGenTop
                            dRtopGenTop    = min( dRtopGenTop, deltaR( top.eta(), top.phi(), gen.eta(), gen.phi() ) )
                            if (not( dRtopGenTop == dRtopGenTopTmp )): 
                                matchedPt = gen.pt()
                                
                self.matchingTopCandidates.Fill((dRtopGenTop < 0.4)+2*algoBin)
                if ( dRtopGenTop < 0.4 ):
                    self.matchingTopCandidatesPt[algo].Fill( matchedPt, top.pt() )
                
                if (len(event.topCandidates[algo]) == 2) :
                    self.matchingWhenTwoTopCandidates.Fill((dRtopGenTop < 0.4)+2*algoBin)
                elif (len(event.topCandidates[algo]) == 1) :
                    self.matchingWhenOneTopCandidate.Fill((dRtopGenTop < 0.4)+2*algoBin)


            #analyze gen tops
            
            if ( len(event.topCandidates[algo]) == 2 ):
                self.histosGendRWhenTwoCandidates[algo].Fill( dRGenTops )
                self.histosGenPtWhenTwoCandidates[algo].Fill( genTopsPt[0], genTopsPt[1] )
            elif ( len(event.topCandidates[algo]) == 1 ):
                self.histosGendRWhenOneCandidate[algo].Fill( dRGenTops )
                self.histosGenPtWhenOneCandidate[algo].Fill( genTopsPt[0], genTopsPt[1] )
            else :
                self.histosGendRWhenNoCandidate[algo].Fill( dRGenTops )
                self.histosGenPtWhenNoCandidate[algo].Fill( genTopsPt[0], genTopsPt[1] )
          
            algoBin+=1
           
        return True

    def buildTopCandidates(self, topJet, event):
        '''Creates python topJets from the topJets read from the disk.
        to be overloaded if needed.'''
        return map( RecoJet, topJet )

    def write(self): 
       for histo in self.histos :
            histo.Write( histo.GetName() )
       for algo in self.listOfTopCandidates :
           self.histosdRtopGenTop[algo].Write()
           self.matchingTopCandidatesPt[algo].Write()
           self.histosGendRWhenTwoCandidates[algo] .Write()
           self.histosGenPtWhenTwoCandidates[algo] .Write()
           self.histosGendRWhenOneCandidate[algo]  .Write()
           self.histosGenPtWhenOneCandidate[algo]  .Write()
           self.histosGendRWhenNoCandidate[algo]   .Write()
           self.histosGenPtWhenNoCandidate[algo]   .Write()
           
    def endLoop(self):#should called before write
        super(MergedTopCandidateAnalyzer,self).endLoop()
        self.matchingTopCandidates.Scale(1./ (2*self.nTotEvents))
        self.matchingWhenTwoTopCandidates.Scale(1./ (2*self.nTotEvents))
        self.matchingWhenOneTopCandidate.Scale(1./ (2*self.nTotEvents))
        
    def declareHandles(self):
        super(MergedTopCandidateAnalyzer,self).declareHandles()

        for algo in self.listOfTopCandidates : 
            self.mchandles[ algo ] = AutoHandle(
            (algo,"topCandidates","TOP"),
             'std::vector<reco::BasicJet>' 
            )
       
       
