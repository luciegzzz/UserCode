import FWCore.ParameterSet.Config as cms



topCandidatesAkt0p7p8 = cms.EDProducer(
    "MergingTopCandidates",
    jets0 = cms.InputTag("topCandidatesAktRecluster0p7"),
    jets1 = cms.InputTag("topCandidatesAktRecluster0p8"),
    refMass = cms.untracked.double(185.)
    )

topCandidatesAkt0p7p9 = cms.EDProducer(
    "MergingTopCandidates",
    jets0 = cms.InputTag("topCandidatesAkt0p7p8", "topCandidates"),
    jets1 = cms.InputTag("topCandidatesAktRecluster0p9"),
    refMass = cms.untracked.double(185.)
    )

topCandidatesAkt0p71p0 = cms.EDProducer(
    "MergingTopCandidates",
    jets0 = cms.InputTag("topCandidatesAkt0p7p9", "topCandidates"),
    jets1 = cms.InputTag("topCandidatesAktRecluster1p0"),
    refMass = cms.untracked.double(185.)
    )

topCandidatesAkt0p71p25 = cms.EDProducer(
    "MergingTopCandidates",
    jets0 = cms.InputTag("topCandidatesAkt0p71p0", "topCandidates"),
    jets1 = cms.InputTag("topCandidatesAktRecluster1p25"),
    refMass = cms.untracked.double(185.)
    )

topCandidatesAkt0p71p5 = cms.EDProducer(
    "MergingTopCandidates",
    jets0 = cms.InputTag("topCandidatesAkt0p71p25", "topCandidates"),
    jets1 = cms.InputTag("topCandidatesAktRecluster1p5"),
    refMass = cms.untracked.double(185.)
    )

topCandidatesAkt0p71p75 = cms.EDProducer(
    "MergingTopCandidates",
    jets0 = cms.InputTag("topCandidatesAkt0p71p5", "topCandidates"),
    jets1 = cms.InputTag("topCandidatesAktRecluster1p75"),
    refMass = cms.untracked.double(185.)
    )
#########
topCandidatesKt0p7p8 = cms.EDProducer(
    "MergingTopCandidates",
    jets0 = cms.InputTag("topCandidatesKtRecluster0p7"),
    jets1 = cms.InputTag("topCandidatesKtRecluster0p8"),
    refMass = cms.untracked.double(185.)
    )

topCandidatesKt0p7p9 = cms.EDProducer(
    "MergingTopCandidates",
    jets0 = cms.InputTag("topCandidatesKt0p7p8", "topCandidates"),
    jets1 = cms.InputTag("topCandidatesKtRecluster0p9"),
    refMass = cms.untracked.double(185.)
    )

topCandidatesKt0p71p0 = cms.EDProducer(
    "MergingTopCandidates",
    jets0 = cms.InputTag("topCandidatesKt0p7p9", "topCandidates"),
    jets1 = cms.InputTag("topCandidatesKtRecluster1p0"),
    refMass = cms.untracked.double(185.)
    )

topCandidatesKt0p71p25 = cms.EDProducer(
    "MergingTopCandidates",
    jets0 = cms.InputTag("topCandidatesKt0p71p0", "topCandidates"),
    jets1 = cms.InputTag("topCandidatesKtRecluster1p25"),
    refMass = cms.untracked.double(185.)
    )

topCandidatesKt0p71p5 = cms.EDProducer(
    "MergingTopCandidates",
    jets0 = cms.InputTag("topCandidatesKt0p71p25", "topCandidates"),
    jets1 = cms.InputTag("topCandidatesKtRecluster1p5"),
    refMass = cms.untracked.double(185.)
    )

topCandidatesKt0p71p75 = cms.EDProducer(
    "MergingTopCandidates",
    jets0 = cms.InputTag("topCandidatesKt0p71p5", "topCandidates"),
    jets1 = cms.InputTag("topCandidatesKtRecluster1p75"),
    refMass = cms.untracked.double(185.)
    )

#########
topCandidatesCa0p7p8 = cms.EDProducer(
    "MergingTopCandidates",
    jets0 = cms.InputTag("topCandidatesCaRecluster0p7"),
    jets1 = cms.InputTag("topCandidatesCaRecluster0p8"),
    refMass = cms.untracked.double(185.)
    )

topCandidatesCa0p7p9 = cms.EDProducer(
    "MergingTopCandidates",
    jets0 = cms.InputTag("topCandidatesCa0p7p8", "topCandidates"),
    jets1 = cms.InputTag("topCandidatesCaRecluster0p9"),
    refMass = cms.untracked.double(185.)
    )

topCandidatesCa0p71p0 = cms.EDProducer(
    "MergingTopCandidates",
    jets0 = cms.InputTag("topCandidatesCa0p7p9", "topCandidates"),
    jets1 = cms.InputTag("topCandidatesCaRecluster1p0"),
    refMass = cms.untracked.double(185.)
    )

topCandidatesCa0p71p25 = cms.EDProducer(
    "MergingTopCandidates",
    jets0 = cms.InputTag("topCandidatesCa0p71p0", "topCandidates"),
    jets1 = cms.InputTag("topCandidatesCaRecluster1p25"),
    refMass = cms.untracked.double(185.)
    )

topCandidatesCa0p71p5 = cms.EDProducer(
    "MergingTopCandidates",
    jets0 = cms.InputTag("topCandidatesCa0p71p25", "topCandidates"),
    jets1 = cms.InputTag("topCandidatesCaRecluster1p5"),
    refMass = cms.untracked.double(185.)
    )

topCandidatesCa0p71p75 = cms.EDProducer(
    "MergingTopCandidates",
    jets0 = cms.InputTag("topCandidatesCa0p71p5", "topCandidates"),
    jets1 = cms.InputTag("topCandidatesCaRecluster1p75"),
    refMass = cms.untracked.double(185.)
    )



mergingTopCandidates = cms.Sequence(
    topCandidatesAkt0p7p8   +
    topCandidatesAkt0p7p9   +
    topCandidatesAkt0p71p0  +
    topCandidatesAkt0p71p25 +
    topCandidatesAkt0p71p5  +
    topCandidatesAkt0p71p75 +
    topCandidatesKt0p7p8    +
    topCandidatesKt0p7p9    +
    topCandidatesKt0p71p0   +
    topCandidatesKt0p71p25  +
    topCandidatesKt0p71p5   +
    topCandidatesKt0p71p75  +
    topCandidatesCa0p7p8    +
    topCandidatesCa0p7p9    +
    topCandidatesCa0p71p0   +
    topCandidatesCa0p71p25  +
    topCandidatesCa0p71p5   +
    topCandidatesCa0p71p75  
    )
