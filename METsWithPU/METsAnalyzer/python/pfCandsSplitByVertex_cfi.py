import FWCore.ParameterSet.Config as cms

pfCandsSplitByVertex = cms.EDProducer(
    "PFCandSplitByVtx",
    verbose   = cms.untracked.bool( False ),
    vtxIndex  = cms.untracked.uint32(1),
    vertices  = cms.InputTag("offlinePrimaryVerticesDA"),
    pfCands   = cms.InputTag("particleFlow"),
    outfile   = cms.untracked.string("pfCands.root")
    )

 
