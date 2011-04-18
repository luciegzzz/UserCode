import FWCore.ParameterSet.Config as cms

pfCandNeutral = cms.EDFilter(
    "GenericPFCandidateSelector",
    alias = cms.string('pfCandNeutral'),
    #cut = cms.string("charge == 0 "),
    cut = cms.string("particleId != h"),
    src = cms.InputTag("particleFlow"),
    filter = cms.bool(False)
)

