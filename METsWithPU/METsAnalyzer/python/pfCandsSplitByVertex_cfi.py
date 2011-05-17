import FWCore.ParameterSet.Config as cms

pfCandsSplitByVertex = cms.EDProducer(
    "PFCandSplitByVtx",
    verbose   = cms.bool( True ),
    vertices  = cms.InputTag("offlinePrimaryVerticesDA"),
    pfCands   = cms.InputTag("particleFlow")
    )

