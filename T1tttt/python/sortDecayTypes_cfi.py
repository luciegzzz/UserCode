import FWCore.ParameterSet.Config as cms

from CMGTools.Common.skims.cmgCandSel_cfi import cmgCandSel #CandViewSelector. Access quantities through data branch : some sort of ptr not a cloned & skimmed branch
from CMGTools.Common.skims.cmgCandCount_cfi import cmgCandCount


#################################
##  select hadronic decays     ##
#################################

genParticlesFromW = cms.EDProducer(
   "GenParticlePruner",
   src = cms.InputTag("genParticlesPruned"),
   select = cms.vstring(
       "drop  *  ",
       "keep++ pdgId =   24",##W direct daughters 
       "keep++ pdgId =   -24",
       )
)

leptonicDecay = cmgCandSel.clone(
    src = 'genParticlesFromW',
    cut = 'abs(pdgId()) == 12 || abs(pdgId()) == 14 || abs(pdgId()) == 16 '
    )

countLeptonicDecay = cmgCandCount.clone(
    src = 'leptonicDecay',
    minNumber = 1
    )


countDiLeptonicDecay = cmgCandCount.clone(
    src = 'leptonicDecay',
    minNumber = 2
    )
