import operator, pickle, pprint, math, random
from CMGTools.RootTools.analyzers.TreeAnalyzerNumpy import TreeAnalyzerNumpy
from CMGTools.RootTools.analyzers.GenParticleAnalyzer import GenParticleAnalyzer
from Lucie.T1tttt.analyzers.TopTupleReader import TopTupleReader
from CMGTools.RootTools.fwlite.AutoHandle import AutoHandle
from Lucie.T1tttt.physicsobjects.PhysicsObjects import GenJet, Jet, RecoJet
from CMGTools.RootTools.physicsobjects.PileUpSummaryInfo import PileUpSummaryInfo
from CMGTools.H2TauTau.proto.analyzers.ntuple import *
from CMGTools.RootTools.utils.DeltaR import deltaR
from ROOT import TH1F, TH2F, TH1I, TH2I, TFile, TF1, TFitResultPtr, TGraphErrors, TTree
from math import sqrt
from array import array

class TopCandidateTreeAnalyzer( TreeAnalyzerNumpy, GenParticleAnalyzer ): # maybe could inherit from reclustered jets...or have some mother class for both
    '''Analyze top candidates in topTuples..'''

    def __init__( self, cfg_ana, cfg_comp, looperName ):
        self.jetCollections       = cfg_ana.jetCollections
        self.listOfJetCollections = self.jetCollections.keys()
        self.listOfBTagsAlgos     = cfg_ana.listOfBTagsAlgos
        #grab fit parameters from text file with piclke-dumped fit parameters
        self.jetMassParametersFile = open ( cfg_ana.jetMassParametersFile, 'r' )
        self.fitParameters         = pickle.load( self.jetMassParametersFile )
        super(TopCandidateTreeAnalyzer,self).__init__( cfg_ana, cfg_comp, looperName )
  
    def declareVariables(self):#do I need to duplicate for many top cand ?
        super(TopCandidateTreeAnalyzer,self).declareVariables()
        tr = self.tree
        for jetColl in self.listOfJetCollections :
            var( tr, 'massOfTopCandidate_' + jetColl,          float ) 
            var( tr, 'ptOfTopCandidate_' + jetColl,            float ) 
            var( tr, 'nConstituentsOfTopCandidate_' + jetColl, float )
            var( tr, 'isMatched_' + jetColl,                   int )
            for tagger in self.listOfBTagsAlgos :
                var( tr, 'nBTags_' + tagger + '_OfTopCandidate_' + jetColl, float )
        
    def process(self, iEvent, event):
        super(TopCandidateTreeAnalyzer,self).process(iEvent, event)
        self.readCollections( iEvent )
        tr = self.tree
        event.jetsAlgos       = {}

       # massTopCandidates        = dict.fromkeys(self.listOfJetCollections,[])
         
        for jetColl in self.listOfJetCollections :
            
            #grab jet collection with label jetColl
            event.jetsAlgos[jetColl] = self.buildTopJets( self.mchandles[jetColl].product(), event )
            #grab fit parameters for this collection
            r      = self.fitParameters[jetColl][0]
            sigma  = self.fitParameters[jetColl][1]
            esigma = self.fitParameters[jetColl][2]
            mean   = self.fitParameters[jetColl][3]
            emean  = self.fitParameters[jetColl][4]

            
            for jet in event.jetsAlgos[jetColl] :
                if (jet.mass() > ( mean - 3*sigma ) and jet.mass() < ( mean + 3*sigma ) ) :
                    fill( tr, 'massOfTopCandidate_' + jetColl, jet.mass())
                    fill( tr, 'ptOfTopCandidate_' + jetColl,   jet.pt())
                    fill( tr, 'nConstituentsOfTopCandidate_' + jetColl, len( jet.getJetConstituents()) )
                    for tagger in self.listOfBTagsAlgos :
                            nBTags = 0
                            for constituent in jet.getJetConstituents() :
                                if constituent.getSelection('cuts_'+tagger) :
                                    nBTags+=1
                            fill( tr, 'nBTags_' + tagger + '_OfTopCandidate_' + jetColl, nBTags )

                    dRjetGenTop = 1000.
                    for gen in event.genParticles :
                        if (gen.status() == 3):
                            if ( abs( gen.pdgId() ) == 6 ):
                                dRjetGenTop    = min( dRjetGenTop, deltaR( jet.eta(), jet.phi(), gen.eta(), gen.phi() ) )
                    fill( tr, 'isMatched_' + jetColl, dRjetGenTop < 0.5 )
                    self.tree.tree.Fill() # analyze each top cand
                
            #474self.tree.tree.Fill() # analyze each top cand

                    
        return True
        
            
    def buildTopJets(self, topJet, event):
        '''Creates python topJets from the topJets read from the disk.
        to be overloaded if needed.'''
        return map( RecoJet, topJet )

    
    def declareHandles(self):
        super(TopCandidateTreeAnalyzer,self).declareHandles()

        for jetColl in self.listOfJetCollections : 
            self.mchandles[ jetColl ] = AutoHandle(
                jetColl,
                'std::vector<reco::BasicJet>' 
                )
        self.mchandles['stdJets'] =  AutoHandle(
            'cmgPFJetSelCHS',
            'std::vector<cmg::PFJet>'
            )   

   
