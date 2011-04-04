import FWCore.ParameterSet.Config as cms

process = cms.Process("ANALYSIS")

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )
process.options = cms.untracked.PSet(
    SkipEvent = cms.untracked.vstring('ProductNotFound'),
    )

process.source = cms.Source("PoolSource",
#     replace 'myfile.root' with the source file you want to use
                            fileNames = cms.untracked.vstring(
    'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1/METs_10_1_iLx.root'
                            ),
#                            skipEvents = cms.untracked.uint32()
)

#process.load("METsWithPU.METsAnalyzer.source_QCD_Pt_15to3000_Flat_FlatDist10_Spring2011GV500k_cfi")

process.load("METsWithPU.METsAnalyzer.metsanalyzer_cfi")

process.analysis.HistOutFile = cms.untracked.string('plotspfMetNoPileUp.root')

process.p = cms.Path(process.analysis)


process.load("FWCore.MessageLogger.MessageLogger_cfi")
process.MessageLogger.cerr.FwkReport.reportEvery = 1
#process.SimpleMemoryCheck = cms.Service("SimpleMemoryCheck",
 #                                       ignoreTotal=cms.untracked.int32(1))


