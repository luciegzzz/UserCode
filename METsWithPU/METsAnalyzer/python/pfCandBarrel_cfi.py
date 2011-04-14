import FWCore.ParameterSet.Config as cms

from METsWithPU.METsAnalyzer.pfMetNoPileUpDA_cff import *

pfCandBarrel = cms.EDFilter(
    "GenericPFCandidateSelector",
    alias = cms.string('pfCandBarrel'),
    cut = cms.string("abs(eta)<2.4"),
    src = cms.InputTag('particleFlow'),
    filter = cms.bool(False)
)

