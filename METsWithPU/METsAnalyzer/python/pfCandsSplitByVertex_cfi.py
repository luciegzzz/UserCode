import FWCore.ParameterSet.Config as cms

pfCandsSplitByVertex = cms.EDProducer(
    "PFCandSplitByVtx",
    verbose   = cms.untracked.bool( True ),
    vertices  = cms.InputTag("offlinePrimaryVerticesDA"),
    pfCands   = cms.InputTag("particleFlow"),
    outfile   = cms.untracked.string("METs.root")
    )

