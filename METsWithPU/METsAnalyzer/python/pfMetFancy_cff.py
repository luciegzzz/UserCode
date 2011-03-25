import FWCore.ParameterSet.Config as cms

from METsWithPU.METsAnalyzer.pfMET_cfi import *
#from CommonTools.ParticleFlow.pfNoPileUp_cff import *
#from METsWithPU.METsAnalyzer.pfNoNeutralJetsCand_cff import *

pfMetFancy = pfMET.clone()
pfMetFancy.src = 'pfNoNeutralJetsCand'

