import FWCore.ParameterSet.Config as cms

from METsWithPU.METsAnalyzer.pfMET_cfi import *
from PhysicsTools.PFCandProducer.pfNoPileUp_cff import *

pfMetNoPileUp = pfMET.clone()
pfMetNoPileUp.src = 'pfNoPileUp'
