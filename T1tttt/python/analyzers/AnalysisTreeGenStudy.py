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

class AnalysisTreeGenStudy( TreeAnalyzerNumpy, GenParticleAnalyzer ): 
    '''Makes plots towards analysis.'''

    def __init__( self, cfg_ana, cfg_comp, looperName ):
        super(AnalysisTreeGenStudy,self).__init__( cfg_ana, cfg_comp, looperName )
       
    def declareVariables(self):
        super(AnalysisTreeGenStudy,self).declareVariables()
        tr = self.tree
        for i in range(0, 20) :
            var( tr, 'genJetMultiplicity_' + str(10*i),       int )
        var( tr, 'fourthJetPt'             , float )
        var( tr, 'secondJetPt'             , float )
     
    def beginLoop(self):
        super(AnalysisTreeGenStudy,self).beginLoop()
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
        TH2F("jetMultiplicityStopLSPMassPlane","average jet multiplicity (>30GeV) in (stop, LSP) mass plane", 80, 0., 800., 80, 0., 800. )
        self.StopLSPMassPlane = \
        TH2F("StopLSPMassPlane","(stop, LSP) mass plane", 80, 0., 800., 80, 0., 800. )
        
        
        #trigger -- plot requiring full plane...
        self.effDiJetMet                   =  \
        TH2F("effDiJetMet","expected efficiency for DiJetMET trigger ", 80, 0., 800., 80, 0., 800.)
        self.effQuadJet                    =  \
        TH2F("effQuadJet","expected efficiency for QuadJet trigger ", 80, 0., 800., 80, 0., 800.)
     
      
        self.histos = [
            self.jetMultiplicityVsMinPt,
            self.StopLSPMassPlane,
            self.effDiJetMet,
            self.effQuadJet,
            ]
             
    def process(self, iEvent, event):
        self.nTotEvents+=1
        
        super(AnalysisTreeGenStudy,self).process(iEvent, event)
        self.readCollections( iEvent )
        tr = self.tree

        event.stdJets       = self.buildRecoJets( self.mchandles['stdJets'].product(), event )
        event.genJets       = self.buildRecoJets( self.mchandles['genJets'].product(), event )
        event.met           = self.buildMet( self.mchandles['met'].product(), event )
        met                 = event.met[0].pt()
        
        #ntops
        event.topCandidates = {}
        algoBin = 0

        #get gen-level info 
        mLSP    = 0
        mStop   = 0
        genTops = []
        for gen in event.genParticles :
            if (gen.pdgId() == 1000006) :
                mStop = gen.mass()
            elif (gen.pdgId() == 1000022):
                mLSP = gen.mass()
        self.StopLSPMassPlane.Fill(  mStop, mLSP )
        
        #jet multiplicity
        nGenJets = array( "d", [0.] * 20 )
        for i in range(0, 20):
            for genJet in event.genJets :
                if genJet.pt() > i*10. and abs(genJet.eta()) < 2.4 :
                    nGenJets[i]+=1
                                       
            self.jetMultiplicityVsMinPt.Fill(i*10., nGenJets[i])
            fill( tr, 'genJetMultiplicity_' + str(10*i), nGenJets[i]  )

        
        # trg / baseline selection efficiency
        nJets = 0
        for jet in event.stdJets :
            if jet.pt() > 80. and abs(jet.eta()) < 2.4:
                nJets+=1
            if nJets == 2 :
                fill( tr, 'secondJetPt'             , jet.pt() )
            if nJets == 4 :
                fill( tr, 'fourthJetPt'             , jet.pt() )
       
        if (nJets > 3):
            self.effQuadJet.Fill(mStop, mLSP)
        if (nJets > 1 and met > 200.):
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
        
        for histo in self.histos :
            histo.Write( histo.GetName() )
        super(AnalysisTreeGenStudy,self).write()
       
           
    def endLoop(self):#should called before write
        super(AnalysisTreeGenStudy,self).endLoop()
         
    def declareHandles(self):
        super(AnalysisTreeGenStudy,self).declareHandles()
        self.mchandles['stdJets'] =  AutoHandle(
            'cmgPFJetSelCHS',
            'std::vector<cmg::PFJet>'
            )   

        self.mchandles['met'] =  AutoHandle(
            'cmgPFMET',
            'std::vector<cmg::BaseMET>'
            )   

        self.mchandles['genJets'] =  AutoHandle(
            'genJetSel',
            'std::vector<cmg::PhysicsObjectWithPtr<edm::Ptr<reco::GenJet> > >'
            )   

              
