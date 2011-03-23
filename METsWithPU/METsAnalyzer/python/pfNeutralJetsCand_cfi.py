import FWCore.ParameterSet.Config as cms

pfNeutralJetsCand = cms.EDProducer(
    "PFNeutralJetsCand",
    PFJets = cms.InputTag("ak5PFJets"),
    Enable = cms.bool(True)
    )
