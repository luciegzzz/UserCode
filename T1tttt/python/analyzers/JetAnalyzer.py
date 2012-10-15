import operator, pickle, pprint, math, re, os, logging
from CMGTools.RootTools.analyzers.TreeAnalyzerNumpy import TreeAnalyzerNumpy
from CMGTools.RootTools.statistics.TreeNumpy import TreeNumpy as Tree
from CMGTools.RootTools.analyzers.GenParticleAnalyzer import GenParticleAnalyzer
from Lucie.T1tttt.analyzers.TopTupleReader import TopTupleReader
from CMGTools.RootTools.statistics.Counter import Counter, Counters
from CMGTools.RootTools.fwlite.AutoHandle import AutoHandle
from CMGTools.RootTools.utils.DeltaR import *
from CMGTools.RootTools.fwlite.Analyzer import Analyzer
from Lucie.T1tttt.physicsobjects.PhysicsObjects import GenJet, Jet, RecoJet, Met
from CMGTools.H2TauTau.proto.analyzers.ntuple import *

from CMGTools.RootTools.physicsobjects.PileUpSummaryInfo import PileUpSummaryInfo
from ROOT import TH1F, TH2F, TH1I, TH2I, TFile, TF1, TFitResultPtr, TGraphErrors
from math import sqrt
from array import array

class JetAnalyzer( TreeAnalyzerNumpy, GenParticleAnalyzer ): 
    '''Makes plots towards analysis.'''

    def __init__( self, cfg_ana, cfg_comp, looperName ):
        #jetAnalyzer specifics
        self.jetType     = cfg_ana.jetType
        self.jetLabel    = cfg_ana.jetLabel
        self.refjetType  = cfg_ana.refjetType
        self.refjetLabel = cfg_ana.refjetLabel
      
        #from mother classes - or so
        '''see Analyzer, TreeAnalyzerNumpy classes. Copy-pasted, just modified the dir name     '''
        self.name = cfg_ana.name
        self.verbose = cfg_ana.verbose
        self.cfg_ana = cfg_ana
        self.cfg_comp = cfg_comp
        self.looperName = looperName
        self.dirName = '/'.join( [self.looperName, self.name + '_' + self.jetLabel] )
        print self.dirName, self.looperName, self.name
        os.mkdir( self.dirName )

        # this is the main logger corresponding to the looper.
        # each analyzer could also declare its own logger
        self.mainLogger = logging.getLogger( looperName )
        self.beginLoopCalled = False

        #TreeAnalyzerNumpy
        fileName = '/'.join([self.dirName,
                             self.name+'_tree.root'])
        self.file = TFile( fileName, 'recreate' )
        self.tree0 = Tree(self.name+"_JetByJet",self.name+"_JetByJet")
        self.tree1 = Tree(self.name+"_EvByEv",self.name+"_EvByEv")
        self.declareVariables()
       
        
       
    def declareVariables(self):#do I need to duplicate for many top cand ?
        super(JetAnalyzer,self).declareVariables()
        tr0 = self.tree0
        tr1 = self.tree1
        for i in range(0, 20) :
            var( tr1, 'jetMultiplicity_' + str(10*i)        , int )
            
        var( tr0, 'jetPt'                         , float )
        var( tr0, 'jetEta'                        , float )
        var( tr0, 'jetPhi'                        , float )
        var( tr0, 'deltaRmin'                     , float )  
        var( tr0, 'ptDiffRecoMatched'             , float )
        var( tr0, 'etaDiffRecoMatched'            , float )
        var( tr0, 'phiDiffRecoMatched'            , float )
             
    def beginLoop(self):
        super(JetAnalyzer,self).beginLoop()
        #helpers
        self.nTotEvents = 0

        #histos
        self.histos = []
        
    def process(self, iEvent, event):
        self.nTotEvents+=1
        
        super(JetAnalyzer,self).process(iEvent, event)
        self.readCollections( iEvent )
        tr0 = self.tree0
        tr1 = self.tree1

        event.jets         = self.buildJets ( self.mchandles['jets'].product()     , event )
        event.refJets      = self.buildJets ( self.mchandles['refjets'].product()     , event )

        nJets = array( "d", [0.] * 20 )
        for jet in event.jets :
            if ( not( self.jetLabel == 'genJetSel' ) and not(jet.passPuJetId("full",2 )) ) :
                continue
            if ( abs(jet.eta()) > 2.4 ):
                continue
            fill( tr0, 'jetPt'              , jet.pt()  )
            fill( tr0, 'jetEta'             , jet.eta() )
            fill( tr0, 'jetPhi'             , jet.phi() )
            for i in range(0, 20):
                if (jet.pt() > i*10.):# and abs(jet.eta())<2.4 :
                    nJets[i]+=1
            if ( not( self.jetLabel == 'genJetSel' ) ):
                 bm, deltaRmin = bestMatch(jet, event.refJets)
                 fill( tr0, 'deltaRmin', deltaRmin)
                 if (deltaRmin < 0.3) :
                     fill(tr0, 'ptDiffRecoMatched',  jet.pt()  - bm.pt()) 
                     fill(tr0, 'etaDiffRecoMatched', jet.eta() - bm.eta()) 
                     fill(tr0, 'phiDiffRecoMatched', deltaPhi(jet.phi(),bm.phi())) 
            tr0.tree.Fill()
                  
        for i in range(0, 20):
            fill( tr1, 'jetMultiplicity_' + str(10*i)              , nJets[i] )
        tr1.tree.Fill()
                 
        return True

    def buildJets(self, cmgRecoJet, event):
        '''Creates python genJets from the recoJets read from the disk.
        to be overloaded if needed.'''
        return map( Jet, cmgRecoJet )
 
    def buildGenJets(self, genJet, event):
        '''Creates python genJets from the recoJets read from the disk.
        to be overloaded if needed.'''
        return map( GenJet, genJet )
 
    def write(self):
        self.file.cd()
        for histo in self.histos :
            histo.Write( histo.GetName() )
        
        super(JetAnalyzer,self).write()
       
           
    def endLoop(self):#should called before write
        super(JetAnalyzer,self).endLoop()
         
    def declareHandles(self):
        super(JetAnalyzer,self).declareHandles()
        self.mchandles['jets'] =  AutoHandle(
            self.jetLabel,
            self.jetType
            #'std::vector<cmg::PhysicsObjectWithPtr<edm::Ptr<reco::GenJet> > >'
            )   
        self.mchandles['refjets'] =  AutoHandle(
            self.refjetLabel,
            self.refjetType
            #'std::vector<cmg::PhysicsObjectWithPtr<edm::Ptr<reco::GenJet> > >'
            )   

       
       
       
