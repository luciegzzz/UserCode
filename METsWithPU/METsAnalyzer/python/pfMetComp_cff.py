import FWCore.ParameterSet.Config as cms

from METsWithPU.METsAnalyzer.pfMET_cfi import *
from METsWithPU.METsAnalyzer.pfCandNeutral_cfi import *
from METsWithPU.METsAnalyzer.pfCandCharged_cfi import *
from METsWithPU.METsAnalyzer.pfCandBarrel_cfi import *
from METsWithPU.METsAnalyzer.pfCandFwdBwd_cfi import *
from CommonTools.ParticleFlow.ParticleSelectors.pfSortByType_cff import *

#produce pfMetNoPileUp with the pfNoPileUpDA 
pfMetBarrel     = pfMET.clone(alias = 'pfMetBarrel')
pfMetBarrel.src = 'pfCandBarrel'

pfMetFwdBwd     = pfMET.clone(alias = 'pfMetFwdBwd')
pfMetFwdBwd.src = 'pfCandFwdBwd'

pfMetNeutral     = pfMET.clone(alias = 'pfMetNeutral')
pfMetNeutral.src = 'pfCandNeutral'

pfMetCharged     = pfMET.clone(alias = 'pfMetCharged')
pfMetCharged.src = 'pfCandCharged'

pfAllChargedHadronsFromAllPFC     = pfAllChargedHadrons.clone()
pfAllChargedHadronsFromAllPFC.src = 'particleFlow'
pfMetAllChargedHadrons            = pfMET.clone(alias = 'pfMetAllChargedHadrons')
pfMetAllChargedHadrons.src        = 'pfAllChargedHadronsFromAllPFC' 

pfAllChargedHadronsFromAllPFCCompl= ~pfAllChargedHadronsFromAllPFC
pfMetAllChargedHadronsCompl       = pfMET.clone(alias = 'pfMetAllChargedHadrons')
pfMetAllChargedHadronsCompl       = pfMET.clone(alias = 'pfMetAllChargedHadrons')
pfMetAllChargedHadronsCompl.src   = 'pfAllChargedHadronsFromAllPFC' 


pfMetCompSequence = cms.Sequence(
    pfCandBarrel +
    pfMetBarrel +
    pfCandFwdBwd +
    pfMetFwdBwd +
    pfCandCharged +
    pfMetCharged  +
    pfCandNeutral +
    pfMetNeutral +
    pfAllChargedHadronsFromAllPFC +
    pfMetAllChargedHadrons +
    pfAllChargedHadronsFromAllPFCCompl +
    pfMetAllChargedHadronsCompl
    )
