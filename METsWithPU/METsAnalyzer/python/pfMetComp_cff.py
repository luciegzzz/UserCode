import FWCore.ParameterSet.Config as cms

from METsWithPU.METsAnalyzer.pfMET_cfi import *
from METsWithPU.METsAnalyzer.pfCandNeutral_cfi import *
from METsWithPU.METsAnalyzer.pfCandCharged_cfi import *
from METsWithPU.METsAnalyzer.pfCandBarrel_cfi import *
from METsWithPU.METsAnalyzer.pfCandFwdBwd_cfi import *

#produce pfMetNoPileUp with the pfNoPileUpDA 
pfMetBarrel     = pfMET.clone(alias = 'pfMetBarrel')
pfMetBarrel.src = 'pfCandBarrel'

pfMetFwdBwd     = pfMET.clone(alias = 'pfMetFwdBwd')
pfMetFwdBwd.src = 'pfCandFwdBwd'

pfMetNeutral     = pfMET.clone(alias = 'pfMetNeutral')
pfMetNeutral.src = 'pfCandNeutral'

pfMetCharged     = pfMET.clone(alias = 'pfMetCharged')
pfMetCharged.src = 'pfCandCharged'

pfMetCompSequence = cms.Sequence(
    pfCandBarrel +
    pfMetBarrel +
    pfCandFwdBwd +
    pfMetFwdBwd +
    pfCandCharged +
    pfMetCharged  +
    pfCandNeutral +
    pfMetNeutral    
    )
