import FWCore.ParameterSet.Config as cms

pfCandFwdBwd = cms.EDFilter(
    "CandSelector",
    alias = cms.string('pfCandFwdBwd'),
    cut = cms.string("abs(eta)<2.4 "),
    src = cms.InputTag("particleFlow"),
    filter = cms.bool(False)
)

