import FWCore.ParameterSet.Config as cms

from METsWithPU.METsAnalyzer.neutralJetFilter_cfi import *
from METsWithPU.METsAnalyzer.pfNoNeutralJetsCand_cfi import *

pfNoNeutralJetsCandSequence = cms.Sequence(
    neutralJetFilter +
    pfNoNeutralJetsCand
    )
