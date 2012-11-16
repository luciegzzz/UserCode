import FWCore.ParameterSet.Config as cms

from Lucie.ThirdGeneration.sortDecayTypes_cfi import *

selectHadronicDecaySequence = cms.Sequence(
    topDaughters      +
    genParticlesFromW +
    leptonicDecay     +
    ~countLeptonicDecay 
    )


