import FWCore.ParameterSet.Config as cms

pfNoNeutralJetsCand = cms.EDProducer(
    "TPPFJetsOnPFCandidates",
    enable =  cms.bool( True ),
    verbose = cms.untracked.bool( False ),
    name = cms.untracked.string("pfNeutralJetsOnPFCandidates"),
    topCollection = cms.InputTag("neutralJetFilter"),
    bottomCollection = cms.InputTag("pfNoPileUp"),
    )

pfNoNeutralJetsCandJets = cms.EDProducer(
    "TPPFJetsOnPFCandidates",
    enable =  cms.bool( True ),
    verbose = cms.untracked.bool( False ),
    name = cms.untracked.string("pfNeutralJetsOnPFCandidates"),
    topCollection = cms.InputTag("neutralJetFilter"),
    bottomCollection = cms.InputTag("pfNoElectronPFlow"),
    )

