import FWCore.ParameterSet.Config as cms

from METsWithPU.METsAnalyzer.pfPileUpJets_cfi  import *

pfNoPileUpJetsCand = cms.EDProducer(
    "TPPFJetsOnPFCandidates",
    name = cms.untracked.string("pileUpJetsOnPFCandidates"),
    enable =  cms.bool( True ),
    verbose = cms.untracked.bool( False ),
    topCollection = cms.InputTag("pfPileUpJets"),
    bottomCollection = cms.InputTag("particleFlow"),
)
