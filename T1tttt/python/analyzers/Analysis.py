import operator, pickle, pprint, math, re
#from CMGTools.RootTools.fwlite.Analyzer import Analyzer
from CMGTools.RootTools.analyzers.TreeAnalyzerNumpy import TreeAnalyzerNumpy
from CMGTools.RootTools.analyzers.GenParticleAnalyzer import GenParticleAnalyzer
from Lucie.T1tttt.analyzers.TopTupleReader import TopTupleReader
from CMGTools.RootTools.statistics.Counter import Counter, Counters
from CMGTools.RootTools.fwlite.AutoHandle import AutoHandle
from CMGTools.RootTools.utils.DeltaR import deltaR
from CMGTools.RootTools.fwlite.Analyzer import Analyzer
from Lucie.T1tttt.physicsobjects.PhysicsObjects import GenJet, Jet, RecoJet, Met
from CMGTools.H2TauTau.proto.analyzers.ntuple import *

from CMGTools.RootTools.physicsobjects.PileUpSummaryInfo import PileUpSummaryInfo
from ROOT import TH1F, TH2F, TH1I, TH2I, TFile, TF1, TFitResultPtr, TGraphErrors
from math import sqrt
from array import array

class Analysis( TreeAnalyzerNumpy, GenParticleAnalyzer ): 
    '''Makes plots towards analysis.'''

    def __init__( self, cfg_ana, cfg_comp, looperName ):
        self.listOfTopCandidates       = cfg_ana.listOfTopCandidates
        self.listOfBtagsAlgos          = cfg_ana.listOfBtagsAlgos
        super(Analysis,self).__init__( cfg_ana, cfg_comp, looperName )
       
    def declareVariables(self):
        tr = self.tree
        for algo in self.listOfTopCandidates :
            var( tr, 'numberOfTopCandidates_' + algo,      int )
        for algoBtag in self.listOfBtagsAlgos :
            var( tr, 'numberOfBTags_' + algoBtag,          int )
        for i in range(0, 20) :
            var( tr, 'jetMultiplicity_' + str(10*i),       int )
        var( tr, 'met'                     , float )
        var( tr, 'fourthJetPt'             , float )
        var( tr, 'secondJetPt'             , float )
        var( tr, 'genTopHighPt'            , float )
        var( tr, 'genTopLowPt'             , float )
        var( tr, 'genTopHighPtMinusLowPt'  , float )
        var( tr, 'topCandsHighPtMinusLowPt', float )
        var( tr, 'genTopHighPtPhi'         , float )
        var( tr, 'genTopHighPtEta'         , float )
        var( tr, 'genTopLowPtPhi'          , float )
        var( tr, 'genTopLowPtEta'          , float )
        var( tr, 'genTopsDeltaPhi'         , float )
        var( tr, 'genTopsDeltaEta'         , float )
        var( tr, 'genTopsDeltaR'           , float )
        var( tr, 'minDeltaPhiMETJets'      , float )
        var( tr, 'deltaPhiMETHighPtTopCand', float )
        var( tr, 'deltaPhiMETLowPtTopCand' , float )
        var( tr, 'topCandsdeltaPhi'        , float )
        var( tr, 'topCandsdeltaEta'        , float )
        var( tr, 'topCandsdeltaR'          , float )
        
    def beginLoop(self):
        super(Analysis,self).beginLoop()
        #self.file = TFile ('/'.join ([self.dirName, 'output.root']),
        #                         'recreate')
        #helpers
        self.nTotEvents = 0

        #histos
        #selection
        #jet multiplicity
        self.jetMultiplicityVsMinPt        =  \
        TH2F("jetMultiplicityVsMinPt","jet multiplicity versus min Pt", 20, 0., 200., 20, 0, 20)
       
        #T2tt specific : #jets in stop / LSP mass plane  -- plot requiring full plane...
        self.jetMultiplicityStopLSPMassPlane = \
        TH2F("jetMultiplicityStopLSPMassPlane","average jet multiplicity (>30GeV) in (stop, LSP) mass plane", 39, 225., 1200., 48, 0., 1200 )
        self.StopLSPMassPlane = \
        TH2F("StopLSPMassPlane","(stop, LSP) mass plane", 39, 225., 1200., 48, 0., 1200 )
        self.medianPtStopLSPMassPlane = \
        TH2F("medianGenTopsPtStopLSPMassPlane","median gen tops pt in (stop, LSP) mass plane", 39, 225., 1200., 48, 0., 1200 )
        
        #jets in MET / sumPt plane
        self.jetMultiplicityMETSumPtPlane = \
        TH2F("jetMultiplicityMETSumPtPlane","average jet multiplicity (>30GeV)  in (MET, sumPt) plane", 50, 0., 1000., 250, 0., 5000.)
        self.jetMultiplicityMETSumPtPlane.SetXTitle("MET, GeV")
        self.jetMultiplicityMETSumPtPlane.SetYTitle("SumPt, GeV")
        self.METSumPtPlane = \
        TH2F("METSumPtPlane","(MET, sumPt) plane", 50, 0., 1000., 250, 0., 5000.)
       
        #trigger -- plot requiring full plane...
        self.effDiJetMet                   =  \
        TH2F("effDiJetMet","expected efficiency for DiJetMET trigger ", 39, 225., 1200., 48, 0., 1200)
        self.effQuadJet                    =  \
        TH2F("effQuadJet","expected efficiency for QuadJet trigger ", 39, 225., 1200., 48, 0., 1200)
     
        #gen level tops
        self.genTopsLowPtPhiVsHighPtPhi = \
        TH2F("genTopsLowPtPhiVsHighPtPhi", "gen top low pt phi vs gen top high pt phi", 62, -3.2, 3.2, 62, -3.2, 3.2 )

        self.genTopsLowPtEtaVsHighPtEta = \
        TH2F("genTopsLowPtEtaVsHighPtEta", "gen top low pt eta vs gen top high pt eta", 100, -5., 5., 100, -5., 5. )

        self.genTopsHighPtVsLowPt = \
        TH2F("genTopsHighPtVsLowPt", "gen top high pt vs gen top low pt", 100, 0., 500., 100, 0., 500. )

        self.topCandsLowPtPhiVsHighPtPhi = {}
        self.topCandsLowPtEtaVsHighPtEta = {}
        self.topCandsHighPtVsLowPt       = {}
        
        for algo in self.listOfTopCandidates :
            self.topCandsLowPtPhiVsHighPtPhi[algo] = \
            TH2F("topCandsLowPtPhiVsHighPtPhi_"+algo, "reco top low pt phi vs reco top high pt phi "+algo, 62, -3.2, 3.2, 62, -3.2, 3.2 )

            self.topCandsLowPtEtaVsHighPtEta[algo] = \
            TH2F("topCandsLowPtEtaVsHighPtEta_"+algo, "reco top low pt eta vs reco top high pt eta "+algo, 100, -5., 5., 100, -5., 5. )

            self.topCandsHighPtVsLowPt[algo] = \
            TH2F("topCandsHighPtVsLowPt_"+algo, "reco top high pt vs reco top low pt "+algo, 100, 0., 500., 100, 0., 500. )

        
        self.histos = [
            self.jetMultiplicityVsMinPt,
            self.jetMultiplicityStopLSPMassPlane,
            self.jetMultiplicityMETSumPtPlane,
            self.StopLSPMassPlane,
            self.METSumPtPlane,
            self.effDiJetMet,
            self.effQuadJet,
            self.genTopsLowPtPhiVsHighPtPhi,
            self.genTopsLowPtEtaVsHighPtEta,
            self.genTopsHighPtVsLowPt,
            ]
        for algo in self.listOfTopCandidates :
            self.histos.append(self.topCandsLowPtPhiVsHighPtPhi[algo])
            self.histos.append(self.topCandsLowPtEtaVsHighPtEta[algo])
            self.histos.append(self.topCandsHighPtVsLowPt[algo])
            
    def process(self, iEvent, event):
        self.nTotEvents+=1
        
        super(Analysis,self).process(iEvent, event)
        self.readCollections( iEvent )
        tr = self.tree

        event.stdJets       = self.buildRecoJets( self.mchandles['stdJets'].product(), event )
        event.met           = self.buildMet( self.mchandles['met'].product(), event )
        met                 = event.met[0].pt()
        
        #ntops
        event.topCandidates = {}
        algoBin = 0

        for algo in self.listOfTopCandidates : 
            event.topCandidates[algo] = self.buildTopCandidates( self.mchandles[algo].product(), event )
            fill( tr, 'numberOfTopCandidates_' + algo, len( event.topCandidates[algo] ) )
            topCands = []
            for topCand in event.topCandidates[algo] :
                topCandCoor = {"pt": topCand.pt(), "eta": topCand.eta(), "phi":topCand.phi()}
                topCands.append( topCandCoor )
            orderedTops = sorted(topCands, key=operator.itemgetter('pt'),reverse=True)
            #print event.iEv, algo, orderedTops
            if ( len(orderedTops) > 0):
                fill( tr, 'deltaPhiMETHighPtTopCand', abs(orderedTops[0]["phi"] - event.met[0].phi()) )
                if ( len(orderedTops) > 1):
                    fill( tr, 'deltaPhiMETLowPtTopCand',  abs(orderedTops[1]["phi"] - event.met[0].phi()) )
                    fill( tr, 'topCandsHighPtMinusLowPt', orderedTops[0]["pt"] - orderedTops[1]["pt"] ) 
                    fill( tr, 'topCandsdeltaPhi', orderedTops[0]["phi"] - orderedTops[1]["phi"] ) 
                    fill( tr, 'topCandsdeltaEta', orderedTops[0]["eta"] - orderedTops[1]["eta"] ) 
                    fill( tr, 'topCandsdeltaR', deltaR(orderedTops[0]["eta"], orderedTops[0]["phi"], orderedTops[1]["eta"], orderedTops[1]["phi"] )) 
                    self.topCandsLowPtPhiVsHighPtPhi[algo].Fill( (orderedTops[1])["phi"], (orderedTops[0])["phi"] )
                    self.topCandsLowPtEtaVsHighPtEta[algo].Fill( (orderedTops[1])["eta"], (orderedTops[0])["eta"] )
                    self.topCandsHighPtVsLowPt[algo].Fill( (orderedTops[0])["pt"], (orderedTops[1])["pt"] )
       
      
        #nbtags
        nBtags = dict.fromkeys(self.listOfBtagsAlgos,0)
        for tagger in self.listOfBtagsAlgos :
            for jet in event.stdJets :
                if jet.getSelection('cuts_'+tagger) :
                    nBtags[tagger]+=1
            fill( tr, 'numberOfBTags_' + tagger, nBtags[tagger]  )

        #get gen-level info 
        mLSP    = 0
        mStop   = 0
        genTops = []
        for gen in event.genParticles :
            if (gen.pdgId() == 1000006) :
                mStop = gen.mass()
            elif (gen.pdgId() == 1000022):
                mLSP = gen.mass()
            elif (abs(gen.pdgId())==6) :
                top = {"pt": gen.pt(), "eta": gen.eta(), "phi":gen.phi()}
                genTops.append(top)
        orderedGenTops = sorted(genTops, key=operator.itemgetter('pt')) #sort by increasing pt

        if len(orderedGenTops) > 1 :
            fill( tr, 'genTopHighPt'            , (orderedGenTops[1])["pt"] ) 
            fill( tr, 'genTopLowPt'             , (orderedGenTops[0])["pt"] )
            fill( tr, 'genTopHighPtMinusLowPt'  , (orderedGenTops[1]["pt"] - orderedGenTops[0]["pt"]) ) 
            fill( tr, 'genTopHighPtPhi'         , (orderedGenTops[1])["phi"] ) 
            fill( tr, 'genTopLowPtPhi'          , (orderedGenTops[0])["phi"] ) 
            fill( tr, 'genTopHighPtEta'         , (orderedGenTops[1])["eta"] ) 
            fill( tr, 'genTopLowPtEta'          , (orderedGenTops[0])["eta"] ) 
            self.genTopsLowPtPhiVsHighPtPhi.Fill( (orderedGenTops[0])["phi"], (orderedGenTops[1])["phi"] )
            self.genTopsLowPtEtaVsHighPtEta.Fill( (orderedGenTops[0])["eta"], (orderedGenTops[1])["eta"] )
        
            fill( tr, 'genTopsDeltaPhi'         , (orderedGenTops[1])["phi"] - (orderedGenTops[0])["phi"]) 
            fill( tr, 'genTopsDeltaEta'         , (orderedGenTops[1])["eta"] - (orderedGenTops[0])["eta"]) 
            fill( tr, 'genTopsDeltaR'           , deltaR( (orderedGenTops[0])["eta"], (orderedGenTops[0])["phi"], (orderedGenTops[1])["eta"], (orderedGenTops[1])["phi"]  ) )

            self.genTopsHighPtVsLowPt.Fill( orderedGenTops[1]["pt"], orderedGenTops[0]["pt"])
    
        #jet multiplicity
        nJets = array( "d", [0.] * 20 )
        minDeltaPhiMETJets = 10.
        sumPt = array( "d", [0.] * 20 )
        for i in range(0, 20):
            for jet in event.stdJets :
                if i == 1 :
                    fill( tr, 'secondJetPt'             , jet.pt() )
                if i == 3 :
                    fill( tr, 'fourthJetPt'             , jet.pt() )
                if jet.pt() > i*10. and abs(jet.eta()) < 2.4 :
                    nJets[i]+=1
                    sumPt[i] += jet.pt()
                    
                    if i == 3 :
                        minDeltaPhiMETJets = min( minDeltaPhiMETJets, abs(jet.phi() - event.met[0].phi()))
                    
            self.jetMultiplicityVsMinPt.Fill(i*10., nJets[i])
            fill( tr, 'jetMultiplicity_' + str(10*i), nJets[i]  )

        self.jetMultiplicityStopLSPMassPlane.Fill(  mStop, mLSP, nJets[2] )
        self.StopLSPMassPlane.Fill(  mStop, mLSP )
        self.jetMultiplicityMETSumPtPlane.Fill(  met, sumPt[3], nJets[2] )
        self.METSumPtPlane.Fill(  met, sumPt[3], 1. )

        #met
        fill( tr, 'met', met )
        fill( tr, 'minDeltaPhiMETJets'      , minDeltaPhiMETJets )
     
          
      
        # trg / baseline selection efficiency
        if (nJets[7] > 3):
            self.effQuadJet.Fill(mStop, mLSP)
        if (nJets[7] > 1 and met > 0.):
            self.effDiJetMet.Fill(mStop, mLSP)
      
        self.tree.tree.Fill()

        return True

    def buildTopCandidates(self, topJet, event):
        '''Creates python topJets from the topJets read from the disk.
        to be overloaded if needed.'''
        return map( RecoJet, topJet )

    def buildRecoJets(self, cmgRecoJet, event):
        '''Creates python genJets from the recoJets read from the disk.
        to be overloaded if needed.'''
        return map( Jet, cmgRecoJet )
 
    def buildMet(self, cmgMet, event):
        '''Creates python genJets from the recoJets read from the disk.
        to be overloaded if needed.'''
        return map( Met, cmgMet )
 

    def write(self):
        self.file.cd()
        self.jetMultiplicityStopLSPMassPlane.Divide(self.StopLSPMassPlane)
        self.jetMultiplicityMETSumPtPlane.Divide(self.METSumPtPlane)
        
        for histo in self.histos :
            histo.Write( histo.GetName() )
        super(Analysis,self).write()
       
           
         
    def declareHandles(self):
        super(Analysis,self).declareHandles()
        self.mchandles['stdJets'] =  AutoHandle(
            'cmgPFJetSelCHS',
            'std::vector<cmg::PFJet>'
            )   

        self.mchandles['met'] =  AutoHandle(
            'cmgPFMET',
            'std::vector<cmg::BaseMET>'
            )   

        for algo in self.listOfTopCandidates : 
            self.mchandles[ algo ] = AutoHandle(
            (algo,"topCandidates","TOP"),
             'std::vector<reco::BasicJet>' 
            )
       
       
