import operator, pickle, pprint, math
from CMGTools.RootTools.fwlite.Analyzer import Analyzer
#from CMGTools.RootTools.analyzers.GenParticleAnalyzer import GenParticleAnalyzer
from Lucie.T1tttt.analyzers.TopTupleReader import TopTupleReader
from CMGTools.RootTools.statistics.Counter import Counter, Counters
from CMGTools.RootTools.fwlite.AutoHandle import AutoHandle
from CMGTools.RootTools.utils.DeltaR import deltaR
from CMGTools.RootTools.physicsobjects.PhysicsObjects import GenJet, Jet, RecoJet
from CMGTools.RootTools.physicsobjects.PileUpSummaryInfo import PileUpSummaryInfo
from ROOT import TH1F, TH2F, TH1I, TH2I, TFile, TF1, TFitResultPtr, TGraphErrors
from math import sqrt
from array import array

class TopCandidateAnalyzer( TopTupleReader ): # maybe could inherit from reclustered jets...or have some mother class for both
    '''Analyze top candidates in topTuples..'''

    def __init__( self, cfg_ana, cfg_comp, looperName ):
        super(TopCandidateAnalyzer,self).__init__( cfg_ana, cfg_comp, looperName )
        #grab fit parameters from text file with piclke-dumped fit parameters
        self.jetMassParametersFile = open ( cfg_ana.jetMassParametersFile, 'r' )
        self.fitParameters         = pickle.load( self.jetMassParametersFile )
        
    def beginLoop(self):
        super(TopCandidateAnalyzer,self).beginLoop()
        #helpers
        nJetAlgos       = len( self.listOfJetCollections )
        nBtagsAlgos     = len ( self.listOfBTagsAlgos )
        self.nTotEvents = 0
        
        ##histograms
        #gen level info
        self.gentop_pt                           = TH1F ('gentop_pt', 'gen level top pt', 300, 0., 1500.) 
        self.gentop_eta                          = TH1F ('gentop_eta', 'gen level top eta', 100, -5., 5.) 
        #top cand
        self.numberOfTopCandidatesRAW            = TH1I ('numberOfTopCandidatesRAW', 'raw number of top candidates', nJetAlgos , 0, nJetAlgos) 
        self.numberOfTopCandidatesPerEvent       = TH2I ('numberOfTopCandidatesPerEvent', 'number of top candidates per event, no matching', nJetAlgos , 0, nJetAlgos, 5, 0, 5) 
        self.numberOfTopCandidatesPerEventMatched= TH2I ('numberOfTopCandidatesPerEventMatched', 'number of top candidates per, matched', nJetAlgos , 0, nJetAlgos, 5, 0, 5) 
        self.numberOfTopCandidates               = TH1F ('numberOfTopCandidates', 'number of top matched to gen', nJetAlgos , 0, nJetAlgos) 
        #Btag
        self.numberOfBTags                       = TH1F ('numberOfBTags', 'number of btags candidates', nBtagsAlgos , 0, nBtagsAlgos)
        self.numberOfBTagsPerEvent               = TH2I ('numberOfBTagsPerEvent', 'number of btags candidates per event, no matching to gen', nBtagsAlgos , 0, nBtagsAlgos, 10, 0, 10)
        
       
        self.histos = [
      #QCD      self.gentop_pt,
      #QCD       self.gentop_eta,
            self.numberOfTopCandidatesRAW,
            self.numberOfTopCandidatesPerEvent,
            self.numberOfTopCandidatesPerEventMatched,
            self.numberOfTopCandidates#,
      #QCD       self.numberOfBTags,
      #QCD       self.numberOfBTagsPerEvent
            ]
        
        self.histosdRjetGenTop                    = {}
        self.histosPtRatioVsPtGen                 = {}
        self.histosRecoPtVsMatchedPt              = {}

        self.numberOfTopMatchedVsBTagNotTopMatchedLargedR = {}
        self.numberOfTopMatchedVsBTagNotTopMatchedSmalldR = {}
        self.dRTopCandidatesBTags                 = {}

        self.nConstituentsInTopCandidates         = {}
        self.massOfConstituents                   = {}
        self.ptOfConstituents                     = {}
        self.numberOfConstituentsBTagged          = {}
        self.massOfConstituentsBTagged            = {}
        self.ptOfConstituentsBTagged              = {}
        self.invMassClosestToW                    = {}
        self.dRBTaggedInTopGenB                   = {}
        self.ptBTaggedInTopVsGenB                 = {}
        self.hepInvMass2DPlot                     = {}
        self.twoMOverPt                           = {}
        self.massOfConstituentsMatchedBTagged     = {}
        
        for jetColl in self.listOfJetCollections :           
            self.histosdRjetGenTop[jetColl]\
            = TH1F( jetColl + '_dRjetGenTop', jetColl + 'dR(top candidate, gen tops)', 100, 0., 10. )

            self.histosPtRatioVsPtGen[jetColl]\
            = TH2F( jetColl + '_matchedPtRatioVsPt', jetColl + ', reco pt over  gen (matched) pt vs  gen (matched) pt', 200, 0, 1000., 200, 0., 2. )

            self.histosRecoPtVsMatchedPt[jetColl]\
            = TH2F( jetColl + '_matchedPtVsPtGen', jetColl + ', reco pt vs gen (matched) pt', 200, 0., 1000., 200, 0., 1000. )

            self.nConstituentsInTopCandidates[jetColl]\
             = TH1F( jetColl + '_nConstituentsInTopCandidates', jetColl + 'number of jets in  matched to gen top candidate, '+ jetColl, 10, 0., 10. )

            self.massOfConstituents[jetColl]\
            = TH1F( jetColl + '_massOfConstituentsInTopCandidates', jetColl + 'mass of jets in  matched to gen top candidates, '+ jetColl, 200, 0., 1000. )

            self.ptOfConstituents[jetColl]\
            = TH1F( jetColl + '_ptOfConstituentsInTopCandidates', jetColl + 'pt of jets in  matched to gen top candidates, '+ jetColl, 200, 0., 1000. )

            self.invMassClosestToW[jetColl]\
            = TH1F( jetColl + 'invMassClosestToW', jetColl + ' inv mass closest to W', 100, 0., 500.)

            self.hepInvMass2DPlot[jetColl]\
            = TH2F(jetColl +'hepInvMass2DPlot', 'HEP top tagger 2D minv plt, '+ jetColl, 150, 0., 1.5, 100, 0., 1.)

            self.twoMOverPt[jetColl]\
            = TH1F(jetColl + '2mOverPt', '2m / pt, '+ jetColl, 200, 0., 2.)
            
            for tagger in self.listOfBTagsAlgos :

                self.numberOfTopMatchedVsBTagNotTopMatchedLargedR[jetColl +'_'+ tagger]\
                = TH2I( jetColl + '_' + tagger+'nTopVsnBTagsLargedR', jetColl +'_'+ tagger + 'number of top matched vs number of btag matched to gen tops, but not to top candidates, dR < 1.5', 5, 0, 5, 5, 0, 5  )

                self.numberOfTopMatchedVsBTagNotTopMatchedSmalldR[jetColl +'_'+ tagger]\
                = TH2I( jetColl + '_' + tagger+'nTopVsnBTagsSmalldR', jetColl +'_'+ tagger + 'number of top matched vs number of btag matched to gen tops, but not to top candidates, dR < 0.5', 5, 0, 5, 5, 0, 5  )

                self.numberOfConstituentsBTagged[jetColl+'_'+ tagger]\
                = TH1I( jetColl + '_' + tagger+'_numberOfConstituentsBTaggedInTopCandidates', 'number of btags in matched to gen top candidates, '+ jetColl +', '+tagger, 10, 0, 10 )

                self.massOfConstituentsBTagged[jetColl+'_'+ tagger]\
                = TH1F( jetColl + '_' + tagger+'_massOfConstituentsBTaggedInTopCandidates', 'mass of btags jets in  matched to gen top candidates, '+ jetColl +', '+tagger, 200, 0., 1000. )

                self.ptOfConstituentsBTagged[jetColl+'_'+ tagger]\
                = TH1F( jetColl + '_' + tagger+'_ptOfConstituentsBTaggedInTopCandidates', 'pt of jets in  matched to gen top candidates, '+ jetColl+', '+tagger, 200, 0., 1000. )

                self.dRBTaggedInTopGenB[jetColl+'_'+tagger]\
                = TH1F( jetColl + '_' + tagger+'_dRBTaggedInTopGenB', 'dR(b tag in  matched to gen top cand, gen b)', 100, 0., 10.)

                self.ptBTaggedInTopVsGenB[jetColl+'_'+tagger]\
                = TH2F( jetColl + '_' + tagger+'_ptBTaggedInTopVsGenB', 'pt b tag in  matched to gen top cand vs gen bpt', 200, 0., 1000., 200, 0., 1000.)

                self.massOfConstituentsMatchedBTagged[jetColl+'_'+ tagger]\
                = TH1F( jetColl + '_' + tagger+'_massOfConstituentsMatchedBTaggedInTopCandidates', 'mass of matched to gen btagged jets in  matched to gen top candidates, '+ jetColl +', '+tagger, 200, 0., 1000. )

                self.dRTopCandidatesBTags[jetColl+'_'+tagger]\
                 = TH1F(  jetColl+'_' +tagger + '_dRTopCandBTag', tagger + ', dR reco top btag ,' + jetColl, 100 , 0., 10.  )

        self.histosdRBTagGenTop                    = {}    
        for tagger in self.listOfBTagsAlgos :
          
            self.histosdRBTagGenTop[tagger]\
            = TH1F(  tagger + '_dRBTagGenTop', tagger + ', dR gen top btag', 100 , 0., 10.  )

            self.numberOfConstituentsBTagged[tagger]\
            =  TH2F ('numberOfConstituentsBTagged_'+tagger , 'number of btags in  matched to gen top candidates constituents, '+ tagger, nJetAlgos , 0, nJetAlgos, 10, 0, 10)                                                 
                                              
    def process(self, iEvent, event):
        
        self.nTotEvents+=1
        super(TopCandidateAnalyzer,self).process(iEvent, event)

         #print '******************** reading event', event.iEv, '****************************'

        ##getting gen level info
        for gen in event.genParticles :
            if (abs( gen.pdgId() ) == 6):
                self.gentop_pt.Fill( gen.pt() )
                self.gentop_eta.Fill( gen.eta() )

        #grab jets collections, or prepare for it
        event.jetsAlgos       = {}
        event.stdJets = self.buildRecoJets( self.mchandles['stdJets'].product(), event )

        ################################################
        ##LOOP OVER JET COLLECTIONS FOR TOP CANDIDATES##
        ################################################
        #counters
        jetCollBin            = 0
        nTopCandidates        = dict.fromkeys(self.listOfJetCollections,0)
     
        for jetColl in self.listOfJetCollections :
            #grab jet collection with label jetColl
            event.jetsAlgos[jetColl] = self.buildTopJets( self.mchandles[jetColl].product(), event )
            #grab fit parameters for this collection
            r      = self.fitParameters[jetColl][0]
            sigma  = self.fitParameters[jetColl][1]
            esigma = self.fitParameters[jetColl][2]
            mean   = self.fitParameters[jetColl][3]
            emean  = self.fitParameters[jetColl][4]

            #set labels
            self.numberOfTopCandidatesRAW.GetXaxis().SetBinLabel(jetCollBin+1, jetColl)
            self.numberOfTopCandidatesPerEvent.GetXaxis().SetBinLabel(jetCollBin+1, jetColl)
            self.numberOfTopCandidatesPerEventMatched.GetXaxis().SetBinLabel(jetCollBin+1, jetColl)
            self.numberOfTopCandidates.GetXaxis().SetBinLabel(jetCollBin+1, jetColl)
           
            self.numberOfTopCandidatesPerEvent.SetMaximum(400)
            self.numberOfTopCandidatesPerEventMatched.SetMaximum(400)
            nTopCands = 0

            ###analyze top candidates
            for jet in event.jetsAlgos[jetColl] :
                ## DEBUG
                ##  if event.iEv == 1 :
                ##      print jetColl, mean, mean - 3*sigma, mean + 3*sigma
                if (jet.mass() > ( mean - 3*sigma ) and jet.mass() < ( mean + 3*sigma ) ) :
                    #1 top candidate
                    nTopCands+=1
                    self.numberOfTopCandidatesRAW.Fill( jetCollBin )

                    ###matching 
                    #to gen tops
                    dRjetGenTop    = 1000.
                    matchedPt      = -10.
                    
                    for gen in event.genParticles :
                        if (gen.status() == 3):
                            if ( abs( gen.pdgId() ) == 6 ):
                                dRjetGenTopTmp = dRjetGenTop
                                self.histosdRjetGenTop[jetColl].Fill( deltaR( jet.eta(), jet.phi(), gen.eta(), gen.phi() ) )
                                dRjetGenTop    = min( dRjetGenTop, deltaR( jet.eta(), jet.phi(), gen.eta(), gen.phi() ) )
                                if ( dRjetGenTopTmp != dRjetGenTop ) :
                                    matchedPt = gen.pt()
                    
                    self.histosRecoPtVsMatchedPt[jetColl].Fill(  jet.pt(), matchedPt )
                    if ( dRjetGenTop < 10000 ):##FOR QCD FOR QCD FOR QCD FOR QCD FOR QCD FOR QCD FOR QCD FOR QCD FOR QCD FOR QCD FOR QCD 
                        self.histosPtRatioVsPtGen[jetColl].Fill( matchedPt,  jet.pt()  /  matchedPt  )
                        self.numberOfTopCandidates.Fill( jetCollBin )
                        nTopCandidates[jetColl]+=1
                        self.twoMOverPt[jetColl].Fill( 2* jet.mass() / jet.pt() )

                    #analyze constituents of matched candidates
                    nConstituents = len(jet.getJetConstituents())

                    if( dRjetGenTop < 10000. ):##FOR QCD FOR QCD FOR QCD FOR QCD FOR QCD FOR QCD FOR QCD FOR QCD FOR QCD FOR QCD FOR QCD 
                        self.nConstituentsInTopCandidates[jetColl].Fill( nConstituents )

                        p4 = []
                        nBtagsinConstituents =  dict.fromkeys(self.listOfBTagsAlgos, 0)
                        for const in  jet.getJetConstituents() :
                            p4.append(const.p())
                            self.massOfConstituents[jetColl].Fill( const.mass() )
                            self.ptOfConstituents[jetColl].Fill( const.pt() )
                            #is btag, matched to gen ?
                            for tagger in self.listOfBTagsAlgos :
                                self.numberOfConstituentsBTagged[tagger].GetXaxis().SetBinLabel(jetCollBin+1, jetColl)

                                if const.getSelection('cuts_'+tagger) :
                                    nBtagsinConstituents[tagger]+=1
                                    self.massOfConstituentsBTagged[jetColl+'_'+tagger].Fill( const.mass() )
                                    self.ptOfConstituentsBTagged[jetColl+'_'+tagger].Fill( const.pt() )
                                                        
                                    dRminJetGen = 1000
                                    genPt = -10.
                                    genStatus = -10.
                                    for gen in event.genParticles :
                                        if (abs(gen.pdgId()) == 5 and gen.status() == 3) :
                                            dRminJetGenTmp = dRminJetGen 
                                            dRminJetGen = min(dRminJetGen, deltaR( const.eta(), const.phi(), gen.eta(), gen.phi()))
                                            if ( not(dRminJetGen == dRminJetGenTmp) ) :
                                                genPt = gen.pt()
                                                genStatus = gen.status()
                                                self.dRBTaggedInTopGenB[jetColl+'_'+tagger].Fill( dRminJetGen )
                                            if (dRminJetGen < 0.5):
                                                self.ptBTaggedInTopVsGenB[jetColl+'_'+tagger].Fill(genPt, const.pt())
                                                self.massOfConstituentsMatchedBTagged[jetColl+'_'+tagger].Fill( const.mass() )

                        for tagger in self.listOfBTagsAlgos :
                            self.numberOfConstituentsBTagged[tagger].Fill( jetCollBin, nBtagsinConstituents[tagger] )
                    
                        #looking for Ws
                        m12 = 1000.
                        m13 = 1000.
                        m23 = 1000.
                    
                        if nConstituents > 1 :
                            m12 = sqrt( (p4[0]+p4[1])*(p4[0]+p4[1]) ) 
                            if nConstituents > 2 :
                                m13 = sqrt( (p4[0]+p4[2])*(p4[0]+p4[2]) )
                                m23 = sqrt( (p4[1]+p4[2])*(p4[1]+p4[2]) )

                        self.invMassClosestToW[jetColl].Fill( min( min(abs(m13 - 80.), abs(m23 - 80.)), abs(m12 - 80.) ))
                        self.hepInvMass2DPlot[jetColl].Fill( math.atan( m13 / m12 ), m23 / jet.mass() )
                    
            self.numberOfTopCandidatesPerEvent.Fill( jetCollBin, nTopCands )
            self.numberOfTopCandidatesPerEventMatched.Fill( jetCollBin, nTopCandidates[jetColl] )
            jetCollBin+=1
            
        ################################################
##         ##LOOP OVER BTAGGERS FOR BTAGS / Gen TOP      ##
##         ################################################
##         #counters
##         taggerBin = 0
## #        nBTagsMatched  = dict.fromkeys(self.listOfBTagsAlgos,0)
##         nBTagsMatchedSmalldR = {}
##         nBTagsMatchedLargedR = {}

##         for jetColl in self.listOfJetCollections :
##             for tagger in self.listOfBTagsAlgos :
##                 nBTagsMatchedSmalldR[jetColl +'_'+tagger] = 0
##                 nBTagsMatchedLargedR[jetColl +'_'+tagger] = 0
        
##         #prepare histos
##         for tagger in self.listOfBTagsAlgos :
##             self.numberOfBTags.GetXaxis().SetBinLabel(taggerBin+1, tagger )
##             self.numberOfBTagsPerEvent.GetXaxis().SetBinLabel(taggerBin+1, tagger)
##             nBTags = 0
##             for stdJet in event.stdJets :
##                 if (stdJet.getSelection('cuts_'+ tagger )):
##                     self.numberOfBTags.Fill( taggerBin )
##                     nBTags+=1

##                 #marching to gen top
##                     dRjetGenTop   = 1000.
##                     for gen in event.genParticles :
##                         if (gen.status() == 3):
##                             if ( abs( gen.pdgId() ) == 6 ):
                                
##                                 self.histosdRBTagGenTop[tagger].Fill( deltaR( stdJet.eta(), stdJet.phi(), gen.eta(), gen.phi() ) )
##                                 dRjetGenTop    = min( dRjetGenTop, deltaR( stdJet.eta(), stdJet.phi(), gen.eta(), gen.phi() ) )
                                
##                     if ( dRjetGenTop < 1.5 ):
                
##                         #matching to top candidate's btag
##                         for jetColl in self.listOfJetCollections :
##                             for jet in event.jetsAlgos[jetColl] :
##                                 sigma  = self.fitParameters[jetColl][1]
##                                 mean   = self.fitParameters[jetColl][3]
           
##                                 if (jet.mass() > ( mean - 3*sigma ) and jet.mass() < ( mean + 3*sigma ) ) :#top cand
##                                     dRjetTopCand = 1000
##                                     for const in jet.getJetConstituents() :
##                                         if ( const.getSelection('cuts_'+ tagger ) ) :
##                                             dRjetTopCand = min( dRjetTopCand , deltaR( stdJet.eta(), stdJet.phi(), const.eta(), const.phi() ) )
##                                     self.dRTopCandidatesBTags[jetColl+'_'+tagger].Fill(dRjetTopCand)
##                                     if ( dRjetTopCand > 0.3  ):  
##                                         nBTagsMatchedLargedR[jetColl +'_'+tagger] += 1
##                                         if ( dRjetGenTop < 0.5 ):
##                                             nBTagsMatchedSmalldR[jetColl +'_'+tagger] += 1

##             self.numberOfBTagsPerEvent.Fill( taggerBin, nBTags )
##             taggerBin+=1
          
##         ################################################
##         ##BTags & Top Cand                            ##
##         ################################################
##         for jetColl in self.listOfJetCollections :
##             for tagger in self.listOfBTagsAlgos :
        
##                 self.numberOfTopMatchedVsBTagNotTopMatchedSmalldR[jetColl +'_'+ tagger].Fill(nBTagsMatchedSmalldR[jetColl +'_'+tagger], nTopCandidates[jetColl])
##                 self.numberOfTopMatchedVsBTagNotTopMatchedSmalldR[jetColl +'_'+ tagger].SetXTitle('number of btags matched to gen tops dR<0.5, not top cands '+ tagger)
##                 self.numberOfTopMatchedVsBTagNotTopMatchedSmalldR[jetColl +'_'+ tagger].SetYTitle('number of top candidates matched, '+ jetColl)
                
##                 self.numberOfTopMatchedVsBTagNotTopMatchedLargedR[jetColl +'_'+ tagger].Fill(nBTagsMatchedLargedR[jetColl +'_'+tagger], nTopCandidates[jetColl])
##                 self.numberOfTopMatchedVsBTagNotTopMatchedLargedR[jetColl +'_'+ tagger].SetXTitle('number of btags matched to gen tops dR<1.5, not top cands '+ tagger)
##                 self.numberOfTopMatchedVsBTagNotTopMatchedLargedR[jetColl +'_'+ tagger].SetYTitle('number of top candidates matched, '+ jetColl)
                
        return True
        
    def write(self): 
        print self.dirName
        self.file.cd
        for histo in self.histos :
            histo.Write( histo.GetName() )
            
        for jetColl in self.listOfJetCollections :           
     #QCD       self.histosPtRatioVsPtGen[jetColl].Write()
     #QCD       self.histosRecoPtVsMatchedPt[jetColl].Write()
     #QCD       self.histosdRjetGenTop[jetColl].Write()
            self.nConstituentsInTopCandidates[jetColl].Write()
            self.massOfConstituents[jetColl].Write()
            self.ptOfConstituents[jetColl].Write()
            self.invMassClosestToW[jetColl].Write()
            self.hepInvMass2DPlot[jetColl].Write()
            self.twoMOverPt[jetColl].Write()
            
            for tagger in self.listOfBTagsAlgos :
    #QCD            self.numberOfTopMatchedVsBTagNotTopMatchedLargedR[jetColl +'_'+ tagger].Write()
    #QCD            self.numberOfTopMatchedVsBTagNotTopMatchedSmalldR[jetColl +'_'+ tagger].Write()
                self.massOfConstituentsBTagged[jetColl +'_'+ tagger].Write()
                self.ptOfConstituentsBTagged[jetColl +'_'+ tagger].Write()
    #QCD            self.dRBTaggedInTopGenB[jetColl+'_'+tagger].Write()
    #QCD            self.ptBTaggedInTopVsGenB[jetColl+'_'+tagger].Write()
    #QCD            self.massOfConstituentsMatchedBTagged[jetColl+'_'+tagger].Write()
    #QCD            self.dRTopCandidatesBTags[jetColl+'_'+tagger].Write()
        
        for tagger in self.listOfBTagsAlgos :
          #QCD  self.histosdRBTagGenTop[tagger].Write()
            self.numberOfConstituentsBTagged[tagger].Write()
            
    def endLoop(self):#should called before write
        super(TopCandidateAnalyzer,self).endLoop()
        self.numberOfTopCandidates.Scale(1./(2.*self.nTotEvents))
        
