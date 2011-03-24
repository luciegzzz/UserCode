import FWCore.ParameterSet.Config as cms

pfNeutralJetsCand = cms.EDProducer(
    "PFNeutralJetsCand",
    PFJets = cms.InputTag("pfJets"),
    Enable = cms.bool(True)
    )
