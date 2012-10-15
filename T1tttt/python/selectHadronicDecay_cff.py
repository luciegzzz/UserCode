import FWCore.ParameterSet.Config as cms

from Lucie.T1tttt.sortDecayTypes_cfi import *

selectHadronicDecaySequence = cms.Sequence(
    topDaughters      +
    genParticlesFromW +
    leptonicDecay     +
    ~countLeptonicDecay 
    )


