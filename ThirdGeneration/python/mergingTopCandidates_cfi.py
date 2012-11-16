import FWCore.ParameterSet.Config as cms

topCandidatesAkt0p7p8 = cms.EDProducer(
    "MergingTopCandidates",
    jets0 = cms.InputTag("topCandidatesAktRecluster0p7"),
    jets1 = cms.InputTag("topCandidatesAktRecluster0p8"),
    weightsfile = cms.untracked.string("/afs/cern.ch/work/l/lucieg/private/Nov9/CMGTools/CMSSW_5_3_3_patch3/src/Lucie/ThirdGeneration/data/TMVAClassificationNov9_BDTG.weights.xml")
    )

topCandidatesAkt0p7p9 = cms.EDProducer(
    "MergingTopCandidates",
    jets0 = cms.InputTag("topCandidatesAkt0p7p8", "topCandidates"),
    jets1 = cms.InputTag("topCandidatesAktRecluster0p9"),
    weightsfile = cms.untracked.string("/afs/cern.ch/work/l/lucieg/private/Nov9/CMGTools/CMSSW_5_3_3_patch3/src/Lucie/ThirdGeneration/data/TMVAClassificationNov9_BDTG.weights.xml")
    )

topCandidatesAkt0p71p0 = cms.EDProducer(
    "MergingTopCandidates",
    jets0 = cms.InputTag("topCandidatesAkt0p7p9", "topCandidates"),
    jets1 = cms.InputTag("topCandidatesAktRecluster1p0"),
    weightsfile = cms.untracked.string("/afs/cern.ch/work/l/lucieg/private/Nov9/CMGTools/CMSSW_5_3_3_patch3/src/Lucie/ThirdGeneration/data/TMVAClassificationNov9_BDTG.weights.xml")
    )

topCandidatesAkt0p71p25 = cms.EDProducer(
    "MergingTopCandidates",
    jets0 = cms.InputTag("topCandidatesAkt0p71p0", "topCandidates"),
    jets1 = cms.InputTag("topCandidatesAktRecluster1p25"),
    weightsfile = cms.untracked.string("/afs/cern.ch/work/l/lucieg/private/Nov9/CMGTools/CMSSW_5_3_3_patch3/src/Lucie/ThirdGeneration/data/TMVAClassificationNov9_BDTG.weights.xml")
    )

topCandidatesAkt0p71p5 = cms.EDProducer(
    "MergingTopCandidates",
    jets0 = cms.InputTag("topCandidatesAkt0p71p25", "topCandidates"),
    jets1 = cms.InputTag("topCandidatesAktRecluster1p5"),
    weightsfile = cms.untracked.string("/afs/cern.ch/work/l/lucieg/private/Nov9/CMGTools/CMSSW_5_3_3_patch3/src/Lucie/ThirdGeneration/data/TMVAClassificationNov9_BDTG.weights.xml")
    )

topCandidatesAkt0p71p75 = cms.EDProducer(
    "MergingTopCandidates",
    jets0 = cms.InputTag("topCandidatesAkt0p71p5", "topCandidates"),
    jets1 = cms.InputTag("topCandidatesAktRecluster1p75"),
    weightsfile = cms.untracked.string("/afs/cern.ch/work/l/lucieg/private/Nov9/CMGTools/CMSSW_5_3_3_patch3/src/Lucie/ThirdGeneration/data/TMVAClassificationNov9_BDTG.weights.xml")
    )

#########
topCandidatesCa0p7p8 = cms.EDProducer(
    "MergingTopCandidates",
    jets0 = cms.InputTag("topCandidatesCaRecluster0p7"),
    jets1 = cms.InputTag("topCandidatesCaRecluster0p8"),
    weightsfile = cms.untracked.string("/afs/cern.ch/work/l/lucieg/private/Nov9/CMGTools/CMSSW_5_3_3_patch3/src/Lucie/ThirdGeneration/data/TMVAClassificationNov9_BDTG.weights.xml")
    )

topCandidatesCa0p7p9 = cms.EDProducer(
    "MergingTopCandidates",
    jets0 = cms.InputTag("topCandidatesCa0p7p8", "topCandidates"),
    jets1 = cms.InputTag("topCandidatesCaRecluster0p9"),
    weightsfile = cms.untracked.string("/afs/cern.ch/work/l/lucieg/private/Nov9/CMGTools/CMSSW_5_3_3_patch3/src/Lucie/ThirdGeneration/data/TMVAClassificationNov9_BDTG.weights.xml")
    )

topCandidatesCa0p71p0 = cms.EDProducer(
    "MergingTopCandidates",
    jets0 = cms.InputTag("topCandidatesCa0p7p9", "topCandidates"),
    jets1 = cms.InputTag("topCandidatesCaRecluster1p0"),
    weightsfile = cms.untracked.string("/afs/cern.ch/work/l/lucieg/private/Nov9/CMGTools/CMSSW_5_3_3_patch3/src/Lucie/ThirdGeneration/data/TMVAClassificationNov9_BDTG.weights.xml")
    )

topCandidatesCa0p71p25 = cms.EDProducer(
    "MergingTopCandidates",
    jets0 = cms.InputTag("topCandidatesCa0p71p0", "topCandidates"),
    jets1 = cms.InputTag("topCandidatesCaRecluster1p25"),
    weightsfile = cms.untracked.string("/afs/cern.ch/work/l/lucieg/private/Nov9/CMGTools/CMSSW_5_3_3_patch3/src/Lucie/ThirdGeneration/data/TMVAClassificationNov9_BDTG.weights.xml")
    )

topCandidatesCa0p71p5 = cms.EDProducer(
    "MergingTopCandidates",
    jets0 = cms.InputTag("topCandidatesCa0p71p25", "topCandidates"),
    jets1 = cms.InputTag("topCandidatesCaRecluster1p5"),
    weightsfile = cms.untracked.string("/afs/cern.ch/work/l/lucieg/private/Nov9/CMGTools/CMSSW_5_3_3_patch3/src/Lucie/ThirdGeneration/data/TMVAClassificationNov9_BDTG.weights.xml")
    )

topCandidatesCa0p71p75 = cms.EDProducer(
    "MergingTopCandidates",
    jets0 = cms.InputTag("topCandidatesCa0p71p5", "topCandidates"),
    jets1 = cms.InputTag("topCandidatesCaRecluster1p75"),
    weightsfile = cms.untracked.string("/afs/cern.ch/work/l/lucieg/private/Nov9/CMGTools/CMSSW_5_3_3_patch3/src/Lucie/ThirdGeneration/data/TMVAClassificationNov9_BDTG.weights.xml")
    )

