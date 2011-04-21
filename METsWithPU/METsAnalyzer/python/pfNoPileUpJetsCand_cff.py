import FWCore.ParameterSet.Config as cms

from METsWithPU.METsAnalyzer.pfPileUpJets_cfi  import *
from METsWithPU.METsAnalyzer.pfNoPileUpJetsCand_cfi import *

pfNoPileUpJetsCandSequence = cms.Sequence(
    pfPileUpJets +
    pfNoPileUpJetsCand 
    )
