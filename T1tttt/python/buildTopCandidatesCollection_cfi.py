import FWCore.ParameterSet.Config as cms



buildTopCandidatesAkt0p7p8 = cms.EDProducer(
    "MergingTopCandidates",
    jets0 = cms.InputTag("topCandidatesAktRecluster0p7"),
    jets1 = cms.InputTag("topCandidatesAktRecluster0p8")
    )

buildTopCandidatesAkt0p7p9 = cms.EDProducer(
    "MergingTopCandidates",
    jets0 = cms.InputTag("buildTopCandidatesAkt0p7p8", "topCandidates"),
    jets1 = cms.InputTag("topCandidatesAktRecluster0p9")
    )

buildTopCandidatesAkt0p71p0 = cms.EDProducer(
    "MergingTopCandidates",
    jets0 = cms.InputTag("buildTopCandidatesAkt0p7p9", "topCandidates"),
    jets1 = cms.InputTag("topCandidatesAktRecluster1p0")
    )

buildTopCandidatesAkt0p71p25 = cms.EDProducer(
    "MergingTopCandidates",
    jets0 = cms.InputTag("buildTopCandidatesAkt0p71p0", "topCandidates"),
    jets1 = cms.InputTag("topCandidatesAktRecluster1p25")
    )

buildTopCandidatesAkt0p71p5 = cms.EDProducer(
    "MergingTopCandidates",
    jets0 = cms.InputTag("buildTopCandidatesAkt0p71p25", "topCandidates"),
    jets1 = cms.InputTag("topCandidatesAktRecluster1p5")
    )

buildTopCandidatesAkt0p71p75 = cms.EDProducer(
    "MergingTopCandidates",
    jets0 = cms.InputTag("buildTopCandidatesAkt0p71p5", "topCandidates"),
    jets1 = cms.InputTag("topCandidatesAktRecluster1p75")
    )
#########
buildTopCandidatesKt0p7p8 = cms.EDProducer(
    "MergingTopCandidates",
    jets0 = cms.InputTag("topCandidatesKtRecluster0p7"),
    jets1 = cms.InputTag("topCandidatesKtRecluster0p8")
    )

buildTopCandidatesKt0p7p9 = cms.EDProducer(
    "MergingTopCandidates",
    jets0 = cms.InputTag("buildTopCandidatesKt0p7p8", "topCandidates"),
    jets1 = cms.InputTag("topCandidatesKtRecluster0p9")
    )

buildTopCandidatesKt0p71p0 = cms.EDProducer(
    "MergingTopCandidates",
    jets0 = cms.InputTag("buildTopCandidatesKt0p7p9", "topCandidates"),
    jets1 = cms.InputTag("topCandidatesKtRecluster1p0")
    )

buildTopCandidatesKt0p71p25 = cms.EDProducer(
    "MergingTopCandidates",
    jets0 = cms.InputTag("buildTopCandidatesKt0p71p0", "topCandidates"),
    jets1 = cms.InputTag("topCandidatesKtRecluster1p25")
    )

buildTopCandidatesKt0p71p5 = cms.EDProducer(
    "MergingTopCandidates",
    jets0 = cms.InputTag("buildTopCandidatesKt0p71p25", "topCandidates"),
    jets1 = cms.InputTag("topCandidatesKtRecluster1p5")
    )

buildTopCandidatesKt0p71p75 = cms.EDProducer(
    "MergingTopCandidates",
    jets0 = cms.InputTag("buildTopCandidatesKt0p71p5", "topCandidates"),
    jets1 = cms.InputTag("topCandidatesKtRecluster1p75")
    )

#########
buildTopCandidatesCa0p7p8 = cms.EDProducer(
    "MergingTopCandidates",
    jets0 = cms.InputTag("topCandidatesCaRecluster0p7"),
    jets1 = cms.InputTag("topCandidatesCaRecluster0p8")
    )

buildTopCandidatesCa0p7p9 = cms.EDProducer(
    "MergingTopCandidates",
    jets0 = cms.InputTag("buildTopCandidatesCa0p7p8", "topCandidates"),
    jets1 = cms.InputTag("topCandidatesCaRecluster0p9")
    )

buildTopCandidatesCa0p71p0 = cms.EDProducer(
    "MergingTopCandidates",
    jets0 = cms.InputTag("buildTopCandidatesCa0p7p9", "topCandidates"),
    jets1 = cms.InputTag("topCandidatesCaRecluster1p0")
    )

buildTopCandidatesCa0p71p25 = cms.EDProducer(
    "MergingTopCandidates",
    jets0 = cms.InputTag("buildTopCandidatesCa0p71p0", "topCandidates"),
    jets1 = cms.InputTag("topCandidatesCaRecluster1p25")
    )

buildTopCandidatesCa0p71p5 = cms.EDProducer(
    "MergingTopCandidates",
    jets0 = cms.InputTag("buildTopCandidatesCa0p71p25", "topCandidates"),
    jets1 = cms.InputTag("topCandidatesCaRecluster1p5")
    )

buildTopCandidatesCa0p71p75 = cms.EDProducer(
    "MergingTopCandidates",
    jets0 = cms.InputTag("buildTopCandidatesCa0p71p5", "topCandidates"),
    jets1 = cms.InputTag("topCandidatesCaRecluster1p75")
    )

countTopCandidatesAkt0p71p75 = cms.EDFilter("CandViewCountFilter",
                                            src = cms.InputTag('buildTopCandidatesAkt0p71p75','topCandidates'),
                                            minNumber = cms.uint32(1),
                                 )


buildTopCandidatesCollection = cms.Sequence(
    buildTopCandidatesAkt0p7p8   +
    buildTopCandidatesAkt0p7p9   +
    buildTopCandidatesAkt0p71p0  +
    buildTopCandidatesAkt0p71p25 +
    buildTopCandidatesAkt0p71p5  +
    buildTopCandidatesAkt0p71p75 +
    buildTopCandidatesKt0p7p8    +
    buildTopCandidatesKt0p7p9    +
    buildTopCandidatesKt0p71p0   +
    buildTopCandidatesKt0p71p25  +
    buildTopCandidatesKt0p71p5   +
    buildTopCandidatesKt0p71p75  +
    buildTopCandidatesCa0p7p8    +
    buildTopCandidatesCa0p7p9    +
    buildTopCandidatesCa0p71p0   +
    buildTopCandidatesCa0p71p25  +
    buildTopCandidatesCa0p71p5   +
    buildTopCandidatesCa0p71p75  #+
#    countTopCandidatesAkt0p71p75
    )
