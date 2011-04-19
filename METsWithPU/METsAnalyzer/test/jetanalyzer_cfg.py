import FWCore.ParameterSet.Config as cms

process = cms.Process("ANALYSIS")

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(100) )
process.options = cms.untracked.PSet(
    SkipEvent = cms.untracked.vstring('ProductNotFound'),
    )

process.source = cms.Source("PoolSource",
                            fileNames = cms.untracked.vstring(
  #  'rfio:/castor/cern.ch/user/l/lucieg/MET/QCD/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_GEN-SIM-RECODEBUG_PU_S1_START311_V1G1-v1_FC5ACFBD-774E-E011-AB6B-00215E21D690.root'
   # 'file:/tmp/lucieg/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_GEN-SIM-RECODEBUG_PU_S1_START311_V1G1-v1_FC5ACFBD-774E-E011-AB6B-00215E21D690.root'
'file:/tmp/lucieg/METs.root'
#    'file:/tmp/lucieg/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_GEN-SIM-RECODEBUG_PU_S1_START311_V1G1-v1_FC5ACFBD-774E-E011-AB6B-00215E21D690.root'
    )
)

process.load("METsWithPU.METsAnalyzer.jetanalyzer_cfi")

process.p = cms.Path(process.analysis)


process.load("FWCore.MessageLogger.MessageLogger_cfi")
process.MessageLogger.cerr.FwkReport.reportEvery = 1
#process.SimpleMemoryCheck = cms.Service("SimpleMemoryCheck",
 #                                       ignoreTotal=cms.untracked.int32(1))


