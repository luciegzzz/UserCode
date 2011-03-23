import FWCore.ParameterSet.Config as cms

from CommonTools.ParticleFlow.pfPileUp_cfi import *
from CommonTools.ParticleFlow.pfNoPileUp_cff import *
from METsWithPU.METsAnalyzer.pfMET_cfi import *

#produce pf pile up candidates with offlinePrimaryVerticesDA
pfPileUpDA = pfPileUp.clone()
pfPileUpDA.Vertices = cms.InputTag("offlinePrimaryVerticesDA")

#replace the top collection used by pfNoPileUp 
pfNoPileUpDA = pfNoPileUp.clone()
pfNoPileUpDA.topCollection = 'pfPileUpDA'

pfNoPileUpDASequence = cms.Sequence(
    pfPileUpDA +
    pfNoPileUpDA 
    )

#produce pfMetNoPileUp with the pfNoPileUpDA 
pfMetNoPileUpDA = pfMET.clone()
pfMetNoPileUpDA.src = 'pfNoPileUpDA'


