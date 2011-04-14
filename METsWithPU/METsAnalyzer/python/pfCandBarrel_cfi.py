import FWCore.ParameterSet.Config as cms

from METsWithPU.METsAnalyzer.pfMetNoPileUpDA_cff import *

pfCandBarrel = cms.EDFilter(
    "CandSelector",
    alias = cms.string('pfCandBarrel'),
    cut = cms.string("abs(eta)<2.4"),
    src = cms.InputTag('pfNoPileUpDA'),
    filter = cms.bool(False)
)

