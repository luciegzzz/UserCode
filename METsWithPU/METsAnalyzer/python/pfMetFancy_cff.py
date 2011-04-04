import FWCore.ParameterSet.Config as cms

from METsWithPU.METsAnalyzer.pfMET_cfi import *

pfMetFancy = pfMET.clone()
pfMetFancy.src = 'pfNoNeutralJetsCand'

