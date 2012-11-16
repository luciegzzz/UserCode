import operator, pickle, pprint, math, re
from CMGTools.RootTools.analyzers.TreeAnalyzerNumpy import TreeAnalyzerNumpy
from CMGTools.RootTools.analyzers.GenParticleAnalyzer import GenParticleAnalyzer
from CMGTools.RootTools.fwlite.AutoHandle import AutoHandle
from CMGTools.RootTools.utils.DeltaR import deltaR, deltaPhi
#from CMGTools.RootTools.fwlite.Output import Output
from Lucie.ThirdGeneration.physicsobjects.PhysicsObjects import GenJet, Jet, RecoJet, Met
from CMGTools.H2TauTau.proto.analyzers.ntuple import *

from CMGTools.RootTools.physicsobjects.PileUpSummaryInfo import PileUpSummaryInfo
from ROOT import TH1F, TH2F, TH1I, TH2I, TFile, TF1, TFitResultPtr, TGraphErrors
from math import sqrt
from array import array

class Analysis( TreeAnalyzerNumpy, GenParticleAnalyzer ):
    '''Makes analysis tree.'''

    def __init__( self, cfg_ana, cfg_comp, looperName ):
        self.topCandidates       = cfg_ana.topCandidates
        super(Analysis,self).__init__( cfg_ana, cfg_comp, looperName )

        #helpers
        self.nTotEvents = 0
    
    def declareVariables(self):
        tr = self.tree
        #mva
        var( tr, 'topTag0_mva'            , float )
        var( tr, 'topTag0_mass'           , float )
        var( tr, 'topTag0_pt'             , float )
        var( tr, 'topTag1_mva'            , float )
        var( tr, 'topTag1_mass'           , float )
        var( tr, 'topTag1_pt'             , float )
        var( tr, 'bTag0_csv'              , float )
        var( tr, 'bTag0_mass'             , float )
        var( tr, 'bTag0_pt'               , float )
        var( tr, 'bTag1_csv'              , float )
        var( tr, 'bTag1_mass'             , float )
        var( tr, 'bTag1_pt'               , float )

        var( tr, 'deltaRtopTag0topTag1'    , float )
        var( tr, 'deltaRtopTag0Btag0'      , float )
        var( tr, 'deltaRtopTag0Btag1'      , float )
        var( tr, 'deltaRtopTag1Btag0'      , float )
        var( tr, 'deltaRtopTag1Btag1'      , float )
        var( tr, 'deltaRBtag0Btag1'        , float )

        var( tr, 'deltaPhiMETTopTag0'      , float )
        var( tr, 'deltaPhiMETTopTag1'      , float )
        var( tr, 'deltaPhiMETBTag0'        , float )
        var( tr, 'deltaPhiMETBTag1'        , float )
        var( tr, 'minDeltaPhiMETJets'      , float )

        var( tr, 'sumPtOvernJets'          , float )

        ##FI
        var( tr, 'met'                     , float )
        var( tr, 'fourthJetPt'             , float )
        var( tr, 'secondJetPt'             , float )
        var( tr, 'stopMass'                , float )
        var( tr, 'LSPMass'                 , float )
        
        
    def beginLoop(self):
        super(Analysis,self).beginLoop()
            
    def process(self, iEvent, event):
        self.nTotEvents+=1
        
        super(Analysis,self).process(iEvent, event)
        self.readCollections( iEvent )
        tr = self.tree

        event.stdJets       = self.buildRecoJets( self.mchandles['stdJets'].product(), event )
        event.met           = self.buildMet( self.mchandles['met'].product(), event )
        met                 = event.met[0].pt()
        
        #tops
        topCands = []
        event.topCandidates = self.buildTopCandidates( self.mchandles["tops"].product(), event )
        for topCand in event.topCandidates :   
            topCands.append({
                "topTag":topCand.topTag(),
                "mass"  :topCand.mass()  ,  
                "pt"    :topCand.pt()    ,    
                "eta"   :topCand.eta()   ,   
                "phi"   :topCand.phi()
                })
        #btags
        jets               = []
        nJets              = 0.
        sumPtOvernJets     = 0.
        minDeltaPhiMETJets = 1000.
        for jet in event.stdJets :
            nJets+=1.
            jets.append({
                "bTag"  :jet.btag(6),#csv
                "mass"  :jet.mass(),
                "pt"    :jet.pt()  ,  
                "eta"   :jet.eta() , 
                "phi"   :jet.phi()
                })
            if jet.pt()> 30.:
                minDeltaPhiMETJets = min( minDeltaPhiMETJets, abs(deltaPhi(jet.phi(), event.met[0].phi())))
            sumPtOvernJets+=jet.pt()
            if (nJets==4):
                fill( tr, 'fourthJetPt'             , jet.pt() )
            if (nJets==2):
                fill( tr, 'secondJetPt'             , jet.pt() )

        if nJets < 2 :
            fill( tr, 'fourthJetPt'             , -10. )
            fill( tr, 'secondJetPt'             , -10. )
        elif nJets < 4 :
            fill( tr, 'fourthJetPt'             , -10. )
            
        sumPtOvernJets/= nJets

        topCands = sorted(topCands, key=operator.itemgetter('topTag'),reverse=True)
        jets     = sorted(jets,     key=operator.itemgetter('bTag'),  reverse=True)

        if len(topCands) < 2 :
            topCands.append({
                "topTag":-10.,
                "mass"  :-10., 
                "pt"    :-10.,    
                "eta"   :-10.,   
                "phi"   :-10.
                })
            if len(topCands) < 2 :
                topCands.append({
                "topTag":-10.,
                "mass"  :-10., 
                "pt"    :-10.,    
                "eta"   :-10.,   
                "phi"   :-10.
                })

        if len(jets) < 2 :
            jets.append({
                "bTag"  :-10.,
                "mass"  :-10., 
                "pt"    :-10.,    
                "eta"   :-10.,   
                "phi"   :-10.
                })
            if len(jets) < 2 :
                jets.append({
                "bTag"  :-10.,
                "mass"  :-10., 
                "pt"    :-10.,    
                "eta"   :-10.,   
                "phi"   :-10.
                })

        deltaRtopTag0topTag1 = deltaR( topCands[0]["eta"], topCands[0]["phi"], topCands[1]["eta"], topCands[1]["phi"] )
        deltaRtopTag0Btag0   = deltaR( topCands[0]["eta"], topCands[0]["phi"], jets[0]["eta"]    , jets[0]["phi"]     )
        deltaRtopTag0Btag1   = deltaR( topCands[0]["eta"], topCands[0]["phi"], jets[1]["eta"]    , jets[1]["phi"]     )
        deltaRtopTag1Btag0   = deltaR( topCands[1]["eta"], topCands[1]["phi"], jets[0]["eta"]    , jets[0]["phi"]     )
        deltaRtopTag1Btag1   = deltaR( topCands[1]["eta"], topCands[1]["phi"], jets[1]["eta"]    , jets[1]["phi"]     )
        deltaRBtag0Btag1     = deltaR( jets[0]["eta"]    , jets[0]["phi"]    , jets[1]["eta"]    , jets[1]["phi"]     )

        deltaPhiMETTopTag0   = deltaPhi( event.met[0].phi(), topCands[0]["phi"] )
        deltaPhiMETTopTag1   = deltaPhi( event.met[0].phi(), topCands[1]["phi"] )
        deltaPhiMETBTag0     = deltaPhi( event.met[0].phi(), jets[0]["phi"]     )
        deltaPhiMETBTag1     = deltaPhi( event.met[0].phi(), jets[1]["phi"]     )
     
        fill( tr, 'topTag0_mva' , topCands[0]["topTag"])
        fill( tr, 'topTag0_mass', topCands[0]["mass"  ])
        fill( tr, 'topTag0_pt'  , topCands[0]["pt"    ])
        fill( tr, 'topTag1_mva' , topCands[1]["topTag"])
        fill( tr, 'topTag1_mass', topCands[1]["mass"  ])
        fill( tr, 'topTag1_pt'  , topCands[1]["pt"    ])
        fill( tr, 'bTag0_csv'   , jets[0]["bTag"  ])
        fill( tr, 'bTag0_mass'  , jets[0]["mass"  ])
        fill( tr, 'bTag0_pt'    , jets[0]["pt"    ])
        fill( tr, 'bTag1_csv'   , jets[1]["bTag"  ])
        fill( tr, 'bTag1_mass'  , jets[1]["mass"  ])
        fill( tr, 'bTag1_pt'    , jets[1]["pt"    ])
        fill( tr, 'deltaRtopTag0topTag1'    ,  deltaRtopTag0topTag1 )
        fill( tr, 'deltaRtopTag0Btag0'      ,  deltaRtopTag0Btag0   )
        fill( tr, 'deltaRtopTag0Btag1'      ,  deltaRtopTag0Btag1   )
        fill( tr, 'deltaRtopTag1Btag0'      ,  deltaRtopTag1Btag0   )
        fill( tr, 'deltaRtopTag1Btag1'      ,  deltaRtopTag1Btag1   )
        fill( tr, 'deltaRBtag0Btag1'        ,  deltaRBtag0Btag1     )
        fill( tr, 'deltaPhiMETTopTag0'      ,  deltaPhiMETTopTag0   )
        fill( tr, 'deltaPhiMETTopTag1'      ,  deltaPhiMETTopTag1   )
        fill( tr, 'deltaPhiMETBTag0'        ,  deltaPhiMETBTag0     )
        fill( tr, 'deltaPhiMETBTag1'        ,  deltaPhiMETBTag1     )
        fill( tr, 'minDeltaPhiMETJets'      ,  minDeltaPhiMETJets   )
        fill( tr, 'sumPtOvernJets'          ,  sumPtOvernJets       )

      
        #get gen-level info 
        LSPMass    = 0
        stopMass   = 0
        genTops = []
        for gen in event.genParticles :
            if (gen.pdgId() == 1000006) :
                stopMass = gen.mass()
            elif (gen.pdgId() == 1000022):
                LSPMass = gen.mass()
           
        fill( tr, 'stopMass', stopMass )
        fill( tr, 'LSPMass' , LSPMass  )
        
        #met
        fill( tr, 'met'                     , met )
        fill( tr, 'minDeltaPhiMETJets'      , minDeltaPhiMETJets )
     
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

        self.mchandles['tops'] = AutoHandle(
            (self.topCandidates,"topCandidates","TOP"),
             'std::vector<reco::TopJet>' 
            )
       
       
