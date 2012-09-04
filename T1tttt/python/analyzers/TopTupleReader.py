import operator, pickle
from CMGTools.RootTools.fwlite.Analyzer import Analyzer
from CMGTools.RootTools.analyzers.GenParticleAnalyzer import GenParticleAnalyzer
from CMGTools.RootTools.statistics.Counter import Counter, Counters
from CMGTools.RootTools.fwlite.AutoHandle import AutoHandle
from CMGTools.RootTools.utils.DeltaR import deltaR
from Lucie.T1tttt.physicsobjects.PhysicsObjects import GenJet, Jet, RecoJet
from CMGTools.RootTools.physicsobjects.PileUpSummaryInfo import PileUpSummaryInfo
from ROOT import TH1F, TH2F, TH1I, TFile, TF1, TFitResultPtr, TGraphErrors
from math import sqrt
from array import array


class TopTupleReader( GenParticleAnalyzer ):
    '''An analyzer that plots jet mass distribution for a list of jet collections, fit the top peak with a gaussian, plots sigma vs radius'''

    def __init__( self, cfg_ana, cfg_comp, looperName ):
        super(TopTupleReader,self).__init__( cfg_ana, cfg_comp, looperName )
        self.jetCollections       = cfg_ana.jetCollections
        self.listOfJetCollections = self.jetCollections.keys()
        self.listOfBTagsAlgos     = cfg_ana.listOfBTagsAlgos 
       
    def beginLoop(self):
        super(TopTupleReader,self).beginLoop()
        self.file = TFile ('/'.join ([self.dirName, 'output.root']),
                                 'recreate')     
     
    def buildTopJets(self, topJet, event):
        '''Creates python topJets from the topJets read from the disk.
        to be overloaded if needed.'''
        return map( RecoJet, topJet )

    def buildRecoJets(self, cmgRecoJet, event):
        '''Creates python genJets from the recoJets read from the disk.
        to be overloaded if needed.'''
        return map( Jet, cmgRecoJet )
        
    def declareHandles(self):
        super(TopTupleReader,self).declareHandles()

        for jetColl in self.listOfJetCollections : 
            self.mchandles[ jetColl ] = AutoHandle(
                jetColl,
                'std::vector<reco::BasicJet>' 
                )
        self.mchandles['stdJets'] =  AutoHandle(
            'cmgPFJetSelCHS',
            'std::vector<cmg::PFJet>'
            )   

   
