import FWCore.ParameterSet.Config as cms

from METsWithPU.METsAnalyzer.pfNeutralJetsCand_cfi import *
from METsWithPU.METsAnalyzer.pfNoNeutralJetsCand_cfi import *

pfNoNeutralJetsCandSequence = cms.Sequence(
    pfNeutralJetsCand +
    pfNoNeutralJetsCand
    )
