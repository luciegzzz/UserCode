import FWCore.ParameterSet.Config as cms

pfNeutralJetsCand = cms.EDProducer(
    "PFNeutralJetsCand",
    PFJets = cms.InputTag("ak5PFJet"),
    Enable = cms.bool(True)
    )
