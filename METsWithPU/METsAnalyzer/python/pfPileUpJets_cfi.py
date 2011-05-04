import FWCore.ParameterSet.Config as cms


pfPileUpJets = cms.EDProducer(
    "PFPileUpJets",
    jets = cms.InputTag("ak5PFJets"),
    genJets = cms.InputTag("ak5GenJets"),
    vertices = cms.InputTag("offlinePrimaryVerticesDA")
    )
