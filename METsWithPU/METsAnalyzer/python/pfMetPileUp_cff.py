import FWCore.ParameterSet.Config as cms

from METsWithPU.METsAnalyzer.pfMET_cfi import *
from METsWithPU.METsAnalyzer.pfPileUpJetsCand_cfi import *

#produce pfMetNoPileUp with the pfNoPileUpDA 
pfMetPileUpJets       = pfMET.clone()
pfMetPileUpJets.alias = 'pfMetPileUpJets'
pfMetPileUpJets.src   = 'pfPileUpJetsCand'

#produce pfMetNoPileUp with the pfNoPileUpDA
pfMetPileUp       = pfMET.clone()
pfMetPileUp.alias = 'pfMetPileUp'
pfMetPileUp.src   = 'pfPileUp'



pfMetPileUpSequence = cms.Sequence(
    pfPileUpJetsCand +
    pfMetPileUpJets +
    pfMetPileUp
    )


