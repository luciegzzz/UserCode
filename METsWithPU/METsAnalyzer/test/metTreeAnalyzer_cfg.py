import FWCore.ParameterSet.Config as cms

process = cms.Process("ANALYSIS")

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )
process.options = cms.untracked.PSet(
    SkipEvent = cms.untracked.vstring('ProductNotFound'),
    )

process.load("METsWithPU.METsAnalyzer.Sources.source_QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11_PU_S1_START311_V1G1_v1_notmatched_cff")

#process.source = cms.Source("PoolSource",
#                            fileNames = cms.untracked.vstring(
#'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_unmatched/METsNoPileUp_26_1_Cqa.root'
#    )
#)

process.load("METsWithPU.METsAnalyzer.mettreeanalyzer_cfi")

#process.analysis.HistOutFile = cms.untracked.string('metTreeNoPVLinkPfMetPileUp.root')
#process.analysis.HistOutFile = cms.untracked.string('metTreeNoPVLinkAl1PU.root')
#process.analysis.HistOutFile = cms.untracked.string('metTreenPUgtnPV.root')
process.analysis.HistOutFile = cms.untracked.string('metTree.root')
#process.analysis.HistOutFile = cms.untracked.string('metTreePfNoPileUpNNC.root') 
process.p = cms.Path(process.analysis)


process.load("FWCore.MessageLogger.MessageLogger_cfi")
process.MessageLogger.cerr.FwkReport.reportEvery = 1000
#process.SimpleMemoryCheck = cms.Service("SimpleMemoryCheck",
 #                                       ignoreTotal=cms.untracked.int32(1))


