import FWCore.ParameterSet.Config as cms

pfCandCharged = cms.EDFilter(
    "GenericPFCandidateSelector",
    alias = cms.string('pfCandCharged'),
    cut = cms.string("charge != 0 "),
    src = cms.InputTag("particleFlow"),
    filter = cms.bool(False)
)
