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
from math import sqrt, ceil
from array import array

class TaggingAndMergingAnalyzer( TreeAnalyzerNumpy, GenParticleAnalyzer ):
    '''Makes analysis tree.'''

    def __init__( self, cfg_ana, cfg_comp, looperName ):
        self.topCandidates       = cfg_ana.topCandidates
        self.topJets             = cfg_ana.topJets
        self.dRmax               = cfg_ana.dR
        super(TaggingAndMergingAnalyzer,self).__init__( cfg_ana, cfg_comp, looperName )

        #helpers
        self.nTotEvents                    = 0
        self.nTopCands                     = 0
        self.nMatchedTopCands              = 0
        self.nFatJets                      = 0
        #histos
        self.massOfTopCandidates           = TH1F("mass","mass of top candidates", 100, 0., 500.)
        self.h_dR                          = TH1F("h_dR", "deltaR gen / top candidates", 100, 0., 10.)
        self.topCandsVsPt                  = TH1F("topCandsVsPt", " top candidates yields as a function of pt", 200, 0., 1000.)
        self.topCandsVsEta                 = TH1F("topCandsVsEta", " top candidates yields as a function of eta", 200, -10., 10.)
        self.topCandsForFRVsPt             = TH1F("topCandsForFRVsPt", " top candidates yields as a function of pt, for fake rate", 200, 0., 1000.)
        self.topCandsForFRVsEta            = TH1F("topCandsForFRVsEta", " top candidates yields as a function of eta, for fake rate", 200, -10., 10.)
        self.topCandsVsDeltaM              = TH1F("topCandsVsDeltaM", " top candidates yields as a function of mass splitting", 80, 0., 800.)
        self.matchedTopCandsVsPt           = TH1F("matchedTopCandsVsPt", "matched top candidates yields as a function of pt", 200, 0., 1000.)
        self.matchedTopCandsVsEta          = TH1F("matchedTopCandsVsEta", "matched top candidates yields as a function of eta", 200, -10., 10.)
        self.matchedTopCandsVsDeltaM       = TH1F("matchedTopCandsVsDeltaM", "matched top candidates yields as a function of mass splitting", 80, 0., 800.)
        self.genTopVsPt                    = TH1F("genTopVsPt", "gen yields versus pt", 200, 0., 1000.)
        self.genTopVsEta                   = TH1F("genTopVsEta", "gen yields versus eta", 200, -10., 10.)
        self.genTopVsDeltaM                = TH1F("genTopVsDeltaM", "gen yields versus mass splitting", 80, 0., 800.)
        self.fatJetsPt                     = TH1F("fatJetsPt", "fat jets yield as a function of pt", 200, 0., 1000.)
        self.fatJetsEta                    = TH1F("fatJetsEta", "fat jets yield as a function of eta", 200, -10., 10.)
       
        self.genPtVsRecoPt                 = TH2F("genPtVsRecoPt","gen vs reco pt", 200, 0., 1000., 200, 0., 1000. )
        self.stopLSPMassPlane              = TH2F("stopLSPMassPlane","stopLSPMassPLane", 80, 0., 800., 80, 0., 800 )
      
        self.histos = [
            self.massOfTopCandidates,    
            self.h_dR,                          
            self.topCandsVsPt,                  
            self.topCandsVsEta,                 
            self.topCandsForFRVsPt,                  
            self.topCandsForFRVsEta,                 
            self.topCandsVsDeltaM,              
            self.matchedTopCandsVsPt,                  
            self.matchedTopCandsVsEta,                 
            self.matchedTopCandsVsDeltaM,              
            self.genTopVsPt,                    
            self.genTopVsEta,                   
            self.genTopVsDeltaM,                
            self.fatJetsPt,                     
            self.fatJetsEta,                    
             #self.fakesVsEff,                  
            self.genPtVsRecoPt,               
            self.stopLSPMassPlane
            ]
    
    def declareVariables(self):
         tr = self.tree

         var( tr, 'numberOfTopsCandidatesPerEvent'       , int )
         
    def process(self, iEvent, event):
        self.nTotEvents+=1
        
        super(TaggingAndMergingAnalyzer,self).process(iEvent, event)
        self.readCollections( iEvent )
        tr = self.tree

        ###################################
        #             gen info            #
        ###################################
        mLSP  = 0
        mStop = 0
        dM    = 0
        for gen in event.genParticles:
            #stop mass
            if abs(gen.pdgId())==1000006 :
                mStop = gen.mass()
            #LSP mass
            if abs(gen.pdgId())==1000022 :
                mLSP  =  gen.mass()
            # mass splitting
            dM = mStop - mLSP
            #gen-level tops
            if abs(gen.pdgId())==6 :
                self.genTopVsPt.Fill(gen.pt())
                self.genTopVsEta.Fill(gen.eta())
                self.genTopVsDeltaM.Fill(dM) 
        #saving        
        self.stopLSPMassPlane.Fill(mStop, mLSP)
        dM     = mStop - mLSP
        
        ###################################
        #     tops candidates             #
        ###################################
        event.topCandidates = self.buildTopCandidates( self.mchandles["tops"].product(), event )
        nCands              = len(event.topCandidates)
        fill(tr, 'numberOfTopsCandidatesPerEvent', nCands)   
        self.tree.tree.Fill()
        
        for top in event.topCandidates :
            dR = 1000.
            matchedPt = -10.
            matchedEta = -10.
            for gen in event.genParticles :
                if abs(gen.pdgId()) == 6 :
                    dRtmp = dR
                    dR = min ( dR, deltaR(gen.eta(), gen.phi(), top.eta(), top.phi()))
                    if not(dR == dRtmp) :
                        matchedPt  = gen.pt()
                        matchedEta = gen.eta()
            self.h_dR.Fill(dR)
            self.genPtVsRecoPt.Fill(matchedPt, top.pt())
            self.topCandsVsPt.Fill(matchedPt)
            self.topCandsVsEta.Fill(matchedEta)
            self.topCandsVsDeltaM.Fill(dM)
            if ( dR < self.dRmax ) and abs(top.mass()-185.)<50. :
                 self.matchedTopCandsVsPt.Fill(matchedPt)
                 self.matchedTopCandsVsEta.Fill(matchedEta)
                 self.matchedTopCandsVsDeltaM.Fill(dM)
            self.topCandsForFRVsPt.Fill(top.pt())
            self.topCandsForFRVsEta.Fill(top.eta())
          
         
            self.massOfTopCandidates.Fill(top.mass())
                
        #fakes in pure background. Num : number of top candidates, Den : number of distinct fat jets. Need to classify by reco variables
        #find distinct jets
        event.topJets    = {}
        distinctJets     = []
        firstAlgo        = True
        for topJetsAlgo in self.topJets :
            event.topJets[topJetsAlgo] = self.buildTopCandidates( self.mchandles[topJetsAlgo].product(), event )
            for topJet in event.topJets[topJetsAlgo] :
                if firstAlgo :
                    distinctJets.append({"pt":topJet.pt(), "eta":topJet.eta(), "phi":topJet.phi(), "topTag":topJet.topTag()})
                else :
                    dR = 1000.
                    index = 0
                    matchedTag   = -10.
                    matchedIndex = -10
                    for jet in distinctJets :
                        dRtmp = dR
                        dR = min(dR, deltaR( jet["eta"], jet["phi"], topJet.eta(), topJet.phi()))
                        if not(dR == dRtmp) :
                            matchedTag   = jet["topTag"]
                            matchedIndex = index
                        index+=1
                    if dR > 0.3 :
                        distinctJets.append({"pt":topJet.pt(), "eta":topJet.eta(), "phi":topJet.phi(), "topTag":topJet.topTag()})
                    elif topJet.topTag() > matchedTag :
                        distinctJets.pop(matchedIndex)
                        distinctJets.append({"pt":topJet.pt(), "eta":topJet.eta(), "phi":topJet.phi(), "topTag":topJet.topTag()})
                        
            firstAlgo = False
        #fill histos        
        for jet in distinctJets :
            self.fatJetsPt.Fill(jet["pt"])                     
            self.fatJetsEta.Fill(jet["eta"])                    
           
        return True

    def endLoop(self):
        super(TaggingAndMergingAnalyzer,self).endLoop()
        print #-----------end loop-----------#
        print 'efficiency', self.nTopCands / (2.*self.nTotEvents)
        print 'efficiency with matching', self.nMatchedTopCands / (2.*self.nTotEvents)
        if self.nFatJets > 0 :
            print 'fake rate', self.nTopCands / self.nFatJets
      

    def buildTopCandidates(self, topJet, event):
        '''Creates python topJets from the topJets read from the disk.
        to be overloaded if needed.'''
        return map( RecoJet, topJet )

    def write(self):
        super(TaggingAndMergingAnalyzer,self).write()
        self.file.cd()
        for histo in self.histos :
            histo.Write()
        
    def declareHandles(self):
        super(TaggingAndMergingAnalyzer,self).declareHandles()
    
        self.mchandles['tops'] = AutoHandle(
            (self.topCandidates,"topCandidates","TOP"),
             'std::vector<reco::TopJet>' 
            )
        for topJetsAlgo in self.topJets :
            self.mchandles[topJetsAlgo] = AutoHandle(
                (topJetsAlgo,"topJets","TOP"),
                'std::vector<reco::TopJet>' 
                )
       
