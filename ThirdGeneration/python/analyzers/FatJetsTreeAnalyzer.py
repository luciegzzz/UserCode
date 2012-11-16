import operator, pickle, pprint, math, re
#from CMGTools.RootTools.fwlite.Analyzer import Analyzer
from CMGTools.RootTools.analyzers.TreeAnalyzerNumpy import TreeAnalyzerNumpy
from CMGTools.RootTools.analyzers.GenParticleAnalyzer import GenParticleAnalyzer
from CMGTools.RootTools.statistics.Counter import Counter, Counters
from CMGTools.RootTools.fwlite.AutoHandle import AutoHandle
from CMGTools.RootTools.utils.DeltaR import deltaR
from CMGTools.RootTools.fwlite.Analyzer import Analyzer
from CMGTools.RootTools.fwlite.Output import Output
from Lucie.ThirdGeneration.physicsobjects.PhysicsObjects import GenJet, Jet, RecoJet, Met
from CMGTools.H2TauTau.proto.analyzers.ntuple import *

from CMGTools.RootTools.physicsobjects.PileUpSummaryInfo import PileUpSummaryInfo
from ROOT import TH1F, TH2F, TH1I, TH2I, TFile, TF1, TFitResultPtr, TGraphErrors
from math import sqrt
from array import array

class FatJetsTreeAnalyzer( TreeAnalyzerNumpy, GenParticleAnalyzer, Output ): 
    '''Makes tree for top tagging mva training.'''

    def __init__( self, cfg_ana, cfg_comp, looperName ):
        self.listOfFatJetAlgos         = cfg_ana.listOfFatJetAlgos 
        super(FatJetsTreeAnalyzer,self).__init__( cfg_ana, cfg_comp, looperName )
        self.nTotEvents = 0

        self.mStopmLSP = TH2F("h_mStopmLSP", "mStopmLSP", 60, 200., 800., 60, 0., 600.)

        self.histos = [
            self.mStopmLSP
            ]
        
    def declareVariables(self):
        tr = self.tree
        # should have one entry per fat jet.
        # Mixing all fat jets of any radius :
        # cleaning / merging of top candidates should be done at a later stage,
        # radius to be given as input to mvs in case it matters (e.g. mass, pt, correlated to radius)
        var( tr, 'pt'                , float )
        var( tr, 'eta'               , float )
        var( tr, 'phi'               , float )
        var( tr, 'mass'              , float )
        var( tr, 'radius'            , float )
        var( tr, 'sumPtOvernConst'   , float )
        var( tr, 'firstBtag_btag'    , float )
        var( tr, 'firstBtag_pt'      , float )
        var( tr, 'firstBtag_mass'    , float )
        var( tr, 'secondBtag_btag'   , float )
        var( tr, 'secondBtag_pt'     , float )
        var( tr, 'secondBtag_mass'   , float )
        var( tr, 'thirdBtag_btag'    , float )
        var( tr, 'thirdBtag_pt'      , float )
        var( tr, 'thirdBtag_mass'    , float )            
        var( tr, 'invMassClosestToW' , float )#not yet filled
        var( tr, 'isMatched'         , int )
        
    def beginLoop(self):
        super(FatJetsTreeAnalyzer,self).beginLoop()
            
    def process(self, iEvent, event):
        
        super(FatJetsTreeAnalyzer,self).process(iEvent, event)
        self.readCollections( iEvent )
        tr = self.tree
        self.nTotEvents +=1
        event.topCandidates = {}
       
        for algo in self.listOfFatJetAlgos :
            event.topCandidates[algo] = self.buildTopCandidates( self.mchandles[algo].product(), event )
            for topCand in event.topCandidates[algo] :
                fill( tr, 'pt',  topCand.pt() )
                fill( tr, 'eta', topCand.eta() )
                fill( tr, 'phi', topCand.phi() )
                fill( tr, 'mass', topCand.mass() )
                radius =  re.sub('p','.',re.findall("[0-9]p[0-9]+",algo)[0])
                fill( tr, 'radius', radius )
                sumPt  = 0.
                nConst = 0.
                csvValues = []
                for const in topCand.getJetConstituents():
                    sumPt+= const.pt()
                    nConst+=1.
                    fill( tr, 'sumPtOvernConst', sumPt / nConst )
                    csvValues.append({"btag":const.btag("combinedSecondaryVertexBJetTags"),"mass":const.mass(), "pt":const.pt()})
                csvValues = sorted(csvValues, key=lambda csvValues: csvValues["btag"], reverse = True)
                if len(csvValues)>1:
                    fill( tr, 'secondBtag_btag' , csvValues[1]["btag"] )
                    fill( tr, 'secondBtag_pt'   , csvValues[1]["pt"]   )
                    fill( tr, 'secondBtag_mass' , csvValues[1]["mass"] )
                    fill( tr, 'firstBtag_btag'  , csvValues[0]["btag"] )
                    fill( tr, 'firstBtag_pt'    , csvValues[0]["pt"]   )
                    fill( tr, 'firstBtag_mass'  , csvValues[0]["mass"] )
                elif len(csvValues)>0 :
                    fill( tr, 'secondBtag_btag' , -1. )
                    fill( tr, 'secondBtag_pt'   , -1. )
                    fill( tr, 'secondBtag_mass' , -1. )
                    fill( tr, 'firstBtag_btag'  , csvValues[0]["btag"] )
                    fill( tr, 'firstBtag_pt'    , csvValues[0]["pt"]   )
                    fill( tr, 'firstBtag_mass'  , csvValues[0]["mass"] )
                else :
                    fill( tr, 'secondBtag_btag' , -1. )
                    fill( tr, 'secondBtag_pt'   , -1. )
                    fill( tr, 'secondBtag_mass' , -1. )
                    fill( tr, 'firstBtag_btag'  , -1. )
                    fill( tr, 'firstBtag_pt'    , -1. )
                    fill( tr, 'firstBtag_mass'  , -1. )
            
                   
##                 fill( tr, 'invMassClosestToW' , topCand.pt() )
                dR = 1000.
                matchedMass = -1000.
                for gen in event.genParticles:
                    if abs(gen.pdgId())==6 :
                        dRtmp = dR
                        dR = min(dR, deltaR( topCand.eta(), topCand.phi(), gen.eta(), gen.phi()))
                        if not(dR == dRtmp):
                            matchedMass = gen.mass()
                if dR < 0.3 and (abs(topCand.mass() - 185.)< 50.):
                    fill( tr, 'isMatched' , 1 )
                else :
                    fill( tr, 'isMatched' , 0 )
        
                self.tree.tree.Fill()

            mLSP  = 0
            mStop = 0
            for gen in event.genParticles:
                if (self.nTotEvents % 100 == 0):
                    if abs(gen.pdgId())==1000006 :
                        mStop = gen.mass()
                    if abs(gen.pdgId())==1000022 :
                        mLSP  =  gen.mass()
            self.mStopmLSP.Fill(mLSP, mStop)
            
        return True

    def buildTopCandidates(self, topJet, event):
        '''Creates python topJets from the topJets read from the disk.
        to be overloaded if needed.'''
        return map( RecoJet, topJet )

    def buildRecoJets(self, cmgRecoJet, event):
        '''Creates python genJets from the recoJets read from the disk.
        to be overloaded if needed.'''
        return map( Jet, cmgRecoJet )
 
    def write(self):
        self.file.cd()

        for histo in self.histos :
            histo.Write()
        super(FatJetsTreeAnalyzer,self).write()
           
         
    def declareHandles(self):
        super(FatJetsTreeAnalyzer,self).declareHandles()
        self.mchandles['stdJets'] =  AutoHandle(
            'cmgPFJetSelCHS',
            'std::vector<cmg::PFJet>'
            )   

        for algo in self.listOfFatJetAlgos : 
            self.mchandles[ algo ] = AutoHandle(
           # (algo,"topCandidates","TOP"),
            (algo,"","TOP"),
             'std::vector<reco::BasicJet>' 
            )
       
       
