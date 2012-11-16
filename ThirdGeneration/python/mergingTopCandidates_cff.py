import FWCore.ParameterSet.Config as cms

from Lucie.ThirdGeneration.mergingTopCandidates_cfi import *

mergingTopCandidatesSequence = cms.Sequence(
    topCandidatesAkt0p7p8   +
    topCandidatesAkt0p7p9  +
    topCandidatesAkt0p71p0  +
    topCandidatesAkt0p71p25 +
    topCandidatesAkt0p71p5  +
    topCandidatesAkt0p71p75 +
    topCandidatesCa0p7p8    +
    topCandidatesCa0p7p9    +
    topCandidatesCa0p71p0   +
    topCandidatesCa0p71p25  +
    topCandidatesCa0p71p5   +
    topCandidatesCa0p71p75  
    )
