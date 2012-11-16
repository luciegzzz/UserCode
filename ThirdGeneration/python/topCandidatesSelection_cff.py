import FWCore.ParameterSet.Config as cms

from Lucie.ThirdGeneration.topJetsFactory_cfi import *
from Lucie.ThirdGeneration.topCandidatesSelection_cfi import *

topCandidatesSelectionSequence = cms.Sequence(
    #build top jets = basic jets + mva output
    topJetsAktRecluster1p75 +
    topJetsAktRecluster1p5  +
    topJetsAktRecluster1p25 +
    topJetsAktRecluster1p0  +
    topJetsAktRecluster0p9  +
    topJetsAktRecluster0p8  +
    topJetsAktRecluster0p7  +
    topJetsCaRecluster1p75  +
    topJetsCaRecluster1p5   +
    topJetsCaRecluster1p25  +
    topJetsCaRecluster1p0   +
    topJetsCaRecluster0p9   +
    topJetsCaRecluster0p8   +
    topJetsCaRecluster0p7   +
    #select "best" top jets as top candidates
    topCandidatesAktRecluster1p75 +
    topCandidatesAktRecluster1p5  +
    topCandidatesAktRecluster1p25 +
    topCandidatesAktRecluster1p0  +
    topCandidatesAktRecluster0p9  +
    topCandidatesAktRecluster0p8  +
    topCandidatesAktRecluster0p7  +
    topCandidatesCaRecluster1p75  +
    topCandidatesCaRecluster1p5   +
    topCandidatesCaRecluster1p25  +
    topCandidatesCaRecluster1p0   +
    topCandidatesCaRecluster0p9   +
    topCandidatesCaRecluster0p8   +
    topCandidatesCaRecluster0p7  
    )

