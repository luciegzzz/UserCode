import FWCore.ParameterSet.Config as cms

from METsWithPU.METsAnalyzer.pfMET_cfi import *
from METsWithPU.METsAnalyzer.pfNoPileUpJetsCand_cff import *
from CommonTools.ParticleFlow.pfNoPileUp_cff import *

#produce pf pile up candidates with offlinePrimaryVerticesDA
pfPileUp.Vertices     = cms.InputTag('offlinePrimaryVerticesDA')
pfPileUp.src          = cms.InputTag('pfNoPileUpJetsCand')

pfNoPileUp.bottomCollection = 'pfNoPileUpJetsCand'

#produce pfMetNoPileUp with the pfNoPileUpDA
pfMetNoPileUpJets       = pfMET.clone()
pfMetNoPileUpJets.alias = 'pfMetNoPileUpJets'
pfMetNoPileUpJets.src   = 'pfNoPileUpJetsCand'

#produce pfMetNoPileUp with the pfNoPileUpDA 
pfMetNoPileUp       = pfMET.clone()
pfMetNoPileUp.alias = 'pfMetNoPileUp'
pfMetNoPileUp.src   = 'pfNoPileUp'


pfMetNoPileUpSequence = cms.Sequence(
    pfNoPileUpJetsCandSequence +
    pfNoPileUpSequence +
    pfMetNoPileUpJets +
    pfMetNoPileUp
    )

