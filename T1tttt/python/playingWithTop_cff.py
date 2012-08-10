import FWCore.ParameterSet.Config as cms

from Lucie.T1tttt.selectHadronicDecay_cff import *

from Lucie.T1tttt.messingWithJetsHadronic_cfi import *

playingWithTopAllHadronic = cms.Sequence(
    selectHadronicDecaySequence  +
    messingWithJetsHadronicSequence
    )



