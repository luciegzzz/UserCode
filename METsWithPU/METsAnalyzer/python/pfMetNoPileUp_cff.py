import FWCore.ParameterSet.Config as cms

from METsWithPU.METsAnalyzer.pfMET_cfi import *
from CommonTools.ParticleFlow.pfNoPileUp_cff import *

#produce pf pile up candidates with offlinePrimaryVerticesDA
pfPileUpOldVtces = pfPileUp.clone()
pfPileUpOldVtces.Vertices = cms.InputTag("offlinePrimaryVertices")

#replace the top collection used by pfNoPileUp 
pfNoPileUpOldVtces = pfNoPileUp.clone()
pfNoPileUpOldVtces.topCollection = 'pfPileUpOldVtces'

pfNoPileUpOldVtcesSequence = cms.Sequence(
    pfPileUpOldVtces +
    pfNoPileUpOldVtces 
    )

#produce pfMetNoPileUp with the pfNoPileUpDA 
pfMetNoPileUp     = pfMET.clone()
pfMetNoPileUp.src = 'pfNoPileUpOldVtces'

