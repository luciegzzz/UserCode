import FWCore.ParameterSet.Config as cms

process = cms.Process("ANALYSIS")

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(5000) )
process.options = cms.untracked.PSet(
    SkipEvent = cms.untracked.vstring('ProductNotFound'),
    )

process.source = cms.Source("PoolSource",
                            fileNames = cms.untracked.vstring(
    #'rfio:/castor/cern.ch/user/l/lucieg/MET/MinBias/MinBias_TuneZ2_7TeV-pythia6_GEN-SIM-RECODEBUG_START311_V1G1-v2_44FD2E01-2550-E011-B3FB-00261894385A.root'
    'file:/tmp/lucieg/MinBias_TuneZ2_7TeV-pythia6_GEN-SIM-RECODEBUG_START311_V1G1-v2_44FD2E01-2550-E011-B3FB-00261894385A.root'
    )
)

process.load("METsWithPU.METsAnalyzer.pileupanalyzer_cfi")

process.p = cms.Path(process.analysis)


process.load("FWCore.MessageLogger.MessageLogger_cfi")
process.MessageLogger.cerr.FwkReport.reportEvery = 1000
#process.SimpleMemoryCheck = cms.Service("SimpleMemoryCheck",
 #                                       ignoreTotal=cms.untracked.int32(1))


