import operator, pickle, pprint, math
from CMGTools.RootTools.fwlite.Analyzer import Analyzer
#from CMGTools.RootTools.analyzers.GenParticleAnalyzer import GenParticleAnalyzer
from Lucie.T1tttt.analyzers.TopTupleReader import TopTupleReader
from CMGTools.RootTools.statistics.Counter import Counter, Counters
from CMGTools.RootTools.fwlite.AutoHandle import AutoHandle
from CMGTools.RootTools.utils.DeltaR import deltaR
from Lucie.T1tttt.physicsobjects.PhysicsObjects import GenJet, Jet, RecoJet
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
        self.nEventsB2B = 0
        self.nEventsB2BPtGt300 = 0
        
        ##histograms
        #gen level info
        self.gentop_pt                           = TH1F ('gentop_pt', 'gen level top pt', 300, 0., 1500.) 
        self.gentop_ptdRGt2                      = TH2F ('gentop_ptdRGt2', 'gen level top pt, dRGenTops > 2', 300, 0., 1500., 300, 0., 1500.) 
        self.gentop_ptdRLt2                      = TH2F ('gentop_ptdRLt2', 'gen level top pt, dRGenTops < 2', 300, 0., 1500., 300, 0., 1500.) 
        self.gentop_eta                          = TH1F ('gentop_eta', 'gen level top eta', 100, -5., 5.) 
        #top cand
        self.numberOfTopCandidatesRAW            = TH1F ('numberOfTopCandidatesRAW', 'raw number of top candidates', nJetAlgos , 0, nJetAlgos) 
        self.numberOfDistinctTopCandidates       = TH1F ('numberOfDistinctTopCandidates', 'number of distinct top candidates', 10 , 0., 10.) 
        self.numberOfTopCandidatesPerEvent       = TH2I ('numberOfTopCandidatesPerEvent', 'number of top candidates per event, no matching', nJetAlgos , 0, nJetAlgos, 5, 0, 5) 
        self.numberOfTopCandidatesPerEventMatched= TH2I ('numberOfTopCandidatesPerEventMatched', 'number of top candidates per, matched', nJetAlgos , 0, nJetAlgos, 5, 0, 5) 
        self.numberOfTopCandidates               = TH1F ('numberOfTopCandidates', 'number of top matched to gen', nJetAlgos , 0, nJetAlgos) 
        self.numberOfTopCandidatesOOB2B          = TH1F ('numberOfTopCandidatesOOB2B', 'number of top matched to gen, candidates out of back to back (dR > 2) ', nJetAlgos , 0, nJetAlgos) 
        self.numberOfTopCandidatesOOB2BGt300     = TH1F ('numberOfTopCandidatesOOB2BGt300', 'number of top matched to gen candidates out of "back to back (dR > 2) + pt > 300GeV', nJetAlgos , 0, nJetAlgos)
        self.dRTopCandidates                     = TH1F('dRTopCandidates','dR between top candidates from all collections', 1000, 0., 100.)
        #Btag
        self.numberOfBTags                       = TH1F ('numberOfBTags', 'number of btags candidates', nBtagsAlgos , 0, nBtagsAlgos)
        self.numberOfBTagsPerEvent               = TH2I ('numberOfBTagsPerEvent', 'number of btags candidates per event, no matching to gen', nBtagsAlgos , 0, nBtagsAlgos, 10, 0, 10)
        
       
        self.histos = [
            self.gentop_pt,
            self.gentop_ptdRGt2,
            self.gentop_ptdRLt2,
            self.gentop_eta,
            self.numberOfTopCandidatesRAW,
            self.numberOfTopCandidatesPerEvent,
            self.numberOfTopCandidatesPerEventMatched,
            self.numberOfTopCandidates,
            self.numberOfTopCandidatesOOB2B,
            self.numberOfTopCandidatesOOB2BGt300,
            self.numberOfBTags,
            self.numberOfBTagsPerEvent,
            self.dRTopCandidates,
            self.numberOfDistinctTopCandidates
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
        self.histosdRGenTops2Cand                 = {}
        self.histosdRGenTops1Cand                 = {}
        self.histosdRGenTops0Cand                 = {}
        self.histosPt2FoundTops                   = {}
        self.histosPtFoundTop1VsFoundTop0         = {}
        self.histosPt1MissedTop                   = {}
        self.histosPt1FoundTop                    = {}
        self.histosPt1MissedTopVs1FoundTop        = {}
        self.histosPt2MissedTops                  = {}
        self.histosPtMissedTop1VsMissedTop0       = {}
        self.histosCorrelationTopCandidates       = {}
        
        for jetColl in self.listOfJetCollections :           
            self.histosdRGenTops2Cand[jetColl]\
            = TH1F( jetColl + '_dRGenTops2Cand', jetColl + 'dR between gen top when 2 candidates', 100, 0., 10. )

            self.histosdRGenTops1Cand[jetColl]\
            = TH1F( jetColl + '_dRGenTops1Cand', jetColl + 'dR between gen top when <2 candidates', 100, 0., 10. )

            self.histosdRGenTops0Cand[jetColl]\
            = TH1F( jetColl + '_dRGenTops0Cand', jetColl + 'dR between gen top when <2 candidates', 100, 0., 10. )

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

            self.histosPtFoundTop1VsFoundTop0[jetColl]\
            = TH2F(jetColl + 'PtFoundTop1VsFoundTop0', 'pt of top 1 vs top 0 when 2 tops found(matched cnadidates)', 100, 0., 1000., 100, 0., 1000.)

            self.histosPt1MissedTopVs1FoundTop[jetColl]\
            = TH2F(jetColl + 'Pt1MissedTopVs1FoundTop', 'pt missing top vs found top when 1 top found(matched cnadidates)', 100, 0., 1000., 100, 0., 1000.)

            self.histosPtMissedTop1VsMissedTop0[jetColl]\
            = TH2F(jetColl + 'PtMissedTop1VsMissedTop0', 'pt of top 1 vs top 0 when 2 missing tops (no matched cnadidates)', 100, 0., 1000., 100, 0., 1000.)

            self.histosPt2FoundTops[jetColl]\
            = TH1F(jetColl + 'Pt2FoundTops', 'tops\' pt when 2 tops found(matched candidates)', 100, 0., 1000.)
    
            self.histosPt1FoundTop[jetColl]\
            = TH1F(jetColl + 'Pt1FoundTop1', 'found top pt when 1 top found(matched candidate)', 100, 0., 1000.)
    
            self.histosPt1MissedTop[jetColl]\
            = TH1F(jetColl + 'Pt1MissedTop1', 'missing top pt when 1 top found(matched candidate)', 100, 0., 1000.)
    
            self.histosPt2MissedTops[jetColl]\
            = TH1F(jetColl + 'Pt2MissedTops', 'tops\' pt when 2 tops missing(no matched cnadidates)', 100, 0., 1000.)
    
            self.histosCorrelationTopCandidates[jetColl]\
            = TH2F(jetColl + '_CorrelationTopCandidates', "CorrelationTopCandidates "+ jetColl, nJetAlgos, 0, nJetAlgos, 1000, 0., 100.)                                               
            
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
        self.distinctTopCandidates = []
        super(TopCandidateAnalyzer,self).process(iEvent, event)

         #print '******************** reading event', event.iEv, '****************************'

        ##getting gen level info
        ptTop0  = -10.
        etaTop0 = -10.
        phiTop0 = -10.
        ptTop1  = -10.
        etaTop1 = -10.
        phiTop1 = -10.
        
        for gen in event.genParticles :
            if (abs( gen.pdgId() ) == 6):
                self.gentop_pt.Fill( gen.pt() )
                self.gentop_eta.Fill( gen.eta() )
                if etaTop0 == -10. :
                    ptTop0  = gen.pt()
                    etaTop0 = gen.eta()
                    phiTop0 = gen.phi()
                else :
                    ptTop1  = gen.pt()
                    etaTop1 = gen.eta()
                    phiTop1 = gen.phi()
        dRGenTops = deltaR(etaTop0, phiTop0, etaTop1, phiTop1)
        if ( dRGenTops > 2.) :
            self.nEventsB2B+=1
            self.gentop_ptdRGt2.Fill( ptTop0, ptTop1 )
            
            if ( min( ptTop0, ptTop1) > 300.) :
                self.nEventsB2BPtGt300+=1

        else :
            self.gentop_ptdRLt2.Fill( ptTop0, ptTop1 )
            
        #grab jets collections, or prepare for it
        event.jetsAlgos       = {}
        event.stdJets = self.buildRecoJets( self.mchandles['stdJets'].product(), event )

        ################################################
        ##LOOP OVER JET COLLECTIONS FOR TOP CANDIDATES##
        ################################################
        #counters
        jetCollBin            = 0
        nTopCandidates        = dict.fromkeys(self.listOfJetCollections,0)
        ptTopCands            = dict.fromkeys(self.listOfJetCollections,[])
        etaTopCands           = dict.fromkeys(self.listOfJetCollections,[])
        phiTopCands           = dict.fromkeys(self.listOfJetCollections,[])
         
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
            self.numberOfTopCandidatesOOB2B.GetXaxis().SetBinLabel(jetCollBin+1, jetColl)
            self.numberOfTopCandidatesOOB2BGt300.GetXaxis().SetBinLabel(jetCollBin+1, jetColl)
            
            #self.numberOfTopCandidatesPerEvent.SetMaximum(400)
            #self.numberOfTopCandidatesPerEventMatched.SetMaximum(400)
            nTopCands = 0
          
            ###analyze top candidates
            for jet in event.jetsAlgos[jetColl] :
                ## DEBUG
               ##  if event.iEv == 1 :
##                     print jetColl, mean, mean - 3*sigma, mean + 3*sigma
                if (jet.mass() > ( mean - 3*sigma ) and jet.mass() < ( mean + 3*sigma ) ) :
                    #1 top candidate
                    nTopCands+=1
                    self.numberOfTopCandidatesRAW.Fill( jetCollBin )

                    #looking for distinct candidates
                    dRTopCands = 100.
                    for topCand in self.distinctTopCandidates :
                        dRTopCands = min( dRTopCands, deltaR( jet.eta(), jet.phi(), topCand["eta"], topCand["phi"] ))
                        self.dRTopCandidates.Fill(dRTopCands)
                    if ( dRTopCands > 1.):
                        newTopCand = {"pt": jet.pt(), "eta":jet.eta(), "phi":jet.phi()}
                        self.distinctTopCandidates.append(newTopCand)
                    
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
                    if ( dRjetGenTop < 0.4 ): 
                        self.histosPtRatioVsPtGen[jetColl].Fill( matchedPt,  jet.pt()  /  matchedPt  )
                        self.numberOfTopCandidates.Fill( jetCollBin )
                        if ( dRGenTops > 2. ) :
                            self.numberOfTopCandidatesOOB2B.Fill( jetCollBin )
                            if ( min(ptTop0, ptTop1) > 300. ):
                                self.numberOfTopCandidatesOOB2BGt300.Fill( jetCollBin )
                        nTopCandidates[jetColl]+=1
                        self.twoMOverPt[jetColl].Fill( 2* jet.mass() / jet.pt() )
                   #     print event.iEv, jetColl,  ptTopCands[jetColl]
                        ptTopCands[jetColl].append(jet.pt() )
                        etaTopCands[jetColl].append( jet.eta() )
                        phiTopCands[jetColl].append( jet.phi() )
                 #       print event.iEv, jetColl,  ptTopCands[jetColl]
                         
                    #analyze constituents of matched candidates
                    nConstituents = len(jet.getJetConstituents())

                    if( dRjetGenTop < 0.4 ) :
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

            if ( dRGenTops > 2.) :
                if ( nTopCandidates[jetColl] == 2 ) :
                    self.histosdRGenTops2Cand[jetColl].Fill( deltaR(etaTop0, phiTop0, etaTop1, phiTop1) )
                    self.histosPt2FoundTops[jetColl].Fill( ptTop0 )
                    self.histosPt2FoundTops[jetColl].Fill( ptTop1 )
                    self.histosPtFoundTop1VsFoundTop0[jetColl].Fill( ptTop0, ptTop1)
                
                elif ( nTopCandidates[jetColl] == 1 )  :
                    self.histosdRGenTops1Cand[jetColl].Fill( deltaR(etaTop0, phiTop0, etaTop1, phiTop1) )
                    if ( deltaR( etaTop0, phiTop0, etaTopCands[jetColl][0], phiTopCands[jetColl][0]) < 0.4  ) : #top 0 has been found
                        self.histosPt1MissedTop[jetColl].Fill( ptTop1 )
                        self.histosPt1FoundTop[jetColl].Fill( ptTop0 )
                        self.histosPt1MissedTopVs1FoundTop[jetColl].Fill(ptTop0, ptTop1)
                    else :
                        self.histosPt1MissedTop[jetColl].Fill( ptTop0 )
                        self.histosPt1FoundTop[jetColl].Fill( ptTop1 )
                        self.histosPt1MissedTopVs1FoundTop[jetColl].Fill(ptTop1, ptTop0)
                
                else :
                    self.histosdRGenTops0Cand[jetColl].Fill( deltaR(etaTop0, phiTop0, etaTop1, phiTop1) )
                    self.histosPt2MissedTops[jetColl].Fill(ptTop0)
                    self.histosPt2MissedTops[jetColl].Fill(ptTop1)
                    self.histosPtMissedTop1VsMissedTop0[jetColl].Fill(ptTop1, ptTop0)

      ##   print event.iEv
##         pprint.pprint(phiTopCands)
##         pprint.pprint(ptTopCands)
##         pprint.pprint(etaTopCands)

        for jetColl0 in self.listOfJetCollections :
            jetCollBin = 0
            for jetColl1 in self.listOfJetCollections :
                self.histosCorrelationTopCandidates[jetColl0].GetXaxis().SetBinLabel(jetCollBin+1, jetColl1)
                for eta0 in etaTopCands[jetColl0] :#topCands0
                    dR0 = 100.
                    i = 0
                    for eta1 in etaTopCands[jetColl1] :#topCands1
                        dR0 = min(dR0, deltaR( eta0, phiTopCands[jetColl0][0], eta1, phiTopCands[jetColl1][i]) )
                        i+=1
                    self.histosCorrelationTopCandidates[jetColl0].Fill( jetCollBin, dR0)
                jetCollBin+=1
        self.numberOfDistinctTopCandidates.Fill(len(self.distinctTopCandidates))
     
        return True
        
    def write(self): 
        print self.dirName
        self.file.cd
        for histo in self.histos :
            histo.Write( histo.GetName() )
            
        for jetColl in self.listOfJetCollections :           
            self.histosPtRatioVsPtGen[jetColl].Write()
            self.histosRecoPtVsMatchedPt[jetColl].Write()
            self.histosdRjetGenTop[jetColl].Write()
            self.nConstituentsInTopCandidates[jetColl].Write()
            self.massOfConstituents[jetColl].Write()
            self.ptOfConstituents[jetColl].Write()
            self.invMassClosestToW[jetColl].Write()
            self.hepInvMass2DPlot[jetColl].Write()
            self.twoMOverPt[jetColl].Write()
            self.histosdRGenTops2Cand[jetColl].Write()
            self.histosdRGenTops1Cand[jetColl].Write()
            self.histosdRGenTops0Cand[jetColl].Write()
            self.histosPt2FoundTops[jetColl].Write()
            self.histosPtFoundTop1VsFoundTop0[jetColl].Write()
            self.histosPt1MissedTop[jetColl].Write()            
            self.histosPt1FoundTop[jetColl].Write()             
            self.histosPt1MissedTopVs1FoundTop[jetColl].Write() 
            self.histosPt2MissedTops[jetColl].Write()           
            self.histosPtMissedTop1VsMissedTop0[jetColl].Write()
            self.histosCorrelationTopCandidates[jetColl].Write()
            
            for tagger in self.listOfBTagsAlgos :
                self.numberOfTopMatchedVsBTagNotTopMatchedLargedR[jetColl +'_'+ tagger].Write()
                self.numberOfTopMatchedVsBTagNotTopMatchedSmalldR[jetColl +'_'+ tagger].Write()
                self.massOfConstituentsBTagged[jetColl +'_'+ tagger].Write()
                self.ptOfConstituentsBTagged[jetColl +'_'+ tagger].Write()
                self.dRBTaggedInTopGenB[jetColl+'_'+tagger].Write()
                self.ptBTaggedInTopVsGenB[jetColl+'_'+tagger].Write()
                self.massOfConstituentsMatchedBTagged[jetColl+'_'+tagger].Write()
                self.dRTopCandidatesBTags[jetColl+'_'+tagger].Write()
        
        for tagger in self.listOfBTagsAlgos :
            self.histosdRBTagGenTop[tagger].Write()
            self.numberOfConstituentsBTagged[tagger].Write()
            
    def endLoop(self):#should called before write
        super(TopCandidateAnalyzer,self).endLoop()
        self.numberOfTopCandidates.Scale(1./(2.*self.nTotEvents))
        self.numberOfTopCandidatesRAW.Scale(1./(2.*self.nTotEvents))
        self.numberOfTopCandidatesOOB2B.Scale(1./(2.*self.nEventsB2B))
        self.numberOfTopCandidatesOOB2BGt300.Scale(1./(2.*self.nEventsB2BPtGt300))
        self.numberOfDistinctTopCandidates.Scale(1./(self.nTotEvents))
