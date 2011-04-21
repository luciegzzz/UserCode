import FWCore.ParameterSet.Config as cms


pfPileUpJets = cms.EDProducer(
    "PFPileUpJets",
    jets = cms.InputTag("ak5PFJets"),
    vertices = cms.InputTag("offlinePrimaryVerticesDA")
    )
