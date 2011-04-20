import FWCore.ParameterSet.Config as cms

pfCandNeutral = cms.EDFilter(
    "GenericPFCandidateSelector",
    alias = cms.string('pfCandNeutral'),
    cut = cms.string("charge == 0 "),
    src = cms.InputTag("particleFlow"),
    filter = cms.bool(False)
)
