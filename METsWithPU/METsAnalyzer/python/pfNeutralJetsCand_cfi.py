import FWCore.ParameterSet.Config as cms

pfNeutralJetsCand = cms.EDProducer(
    "PFNeutralJetsCand",
    PFJets = cms.InputTag("recoPFJets_pfJets__REPROD."),
    Enable = cms.bool(True)
    )
