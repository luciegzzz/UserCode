import FWCore.ParameterSet.Config as cms

neutralJetFilter = cms.EDFilter(
    "PFJetSelector",
    cut = cms.string("eta < 2.4 & chargedMultiplicity == 0 "),
    src = cms.InputTag("pfJets"),
    filter = cms.bool(False)
)

