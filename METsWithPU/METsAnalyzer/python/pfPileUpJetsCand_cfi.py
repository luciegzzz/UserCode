import FWCore.ParameterSet.Config as cms

from METsWithPU.METsAnalyzer.pfPileUpJets_cfi  import *

pfPileUpJetsCand = cms.EDProducer(
    "TPPFCandidatesOnPFCandidates",
    name = cms.untracked.string("pileUpJetsCandsOnPFCandidates"),
    enable =  cms.bool( True ),
    verbose = cms.untracked.bool( False ),
    topCollection = cms.InputTag("pfNoPileUpJetsCand"),
    bottomCollection = cms.InputTag("particleFlow"),
)
