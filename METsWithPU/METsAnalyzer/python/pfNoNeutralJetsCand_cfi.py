import FWCore.ParameterSet.Config as cms

pfNoNeutralJetsCand = cms.EDProducer(
    "TPPFCandidatesOnPFCandidates",
    enable =  cms.bool( True ),
    verbose = cms.untracked.bool( False ),
    name = cms.untracked.string("pfNeutralJetCandOnPFCandidates"),
    topCollection = cms.InputTag("pfNeutralJetsCand"),
    bottomCollection = cms.InputTag("recoPFCandidates_pfNoPileUp__REPROD."),
    )
