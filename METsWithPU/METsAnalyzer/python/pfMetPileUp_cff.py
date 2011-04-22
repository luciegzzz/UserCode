import FWCore.ParameterSet.Config as cms

from METsWithPU.METsAnalyzer.pfMET_cfi import *
from METsWithPU.METsAnalyzer.pfPileUpJetsCand_cfi import *

#produce pfMetNoPileUp with the pfNoPileUpDA 
pfMetPileUp     = pfMET.clone()
pfMetPileUp.src = 'pfPileUpJetsCand'

pfMetPileUpSequence = cms.Sequence(
    pfPileUpJetsCand +
    pfMetPileUp
    )


