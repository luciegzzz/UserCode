import FWCore.ParameterSet.Config as cms

process = cms.Process("ANALYSIS")

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )
process.options = cms.untracked.PSet(
    SkipEvent = cms.untracked.vstring('ProductNotFound'),
    )

process.source = cms.Source("PoolSource",
                           fileNames = cms.untracked.vstring(
   # '/store/cmst3/user/cbern/CMG/HT/Run2011A-May10ReReco-v1/AOD/PAT_CMG_MAX/tree_CMG_10.root'
#'/store/cmst3/user/lucieg/CMG/DoubleMu/Run2011A-May10ReReco-v1/AOD/PAT_CMG/patTuple_PF2PAT_44.root'
  #  'file:/tmp/lucieg/patTuple_PF2PAT.root'
    'file:/data/lucieg/RelValZEE423/tree_CMG_0.root'
    )
                            )

process.load("AnalyzerForTests.Analyzer.analyzer_cfi")

process.analysis.HistOutFile = cms.untracked.string('test.root')
process.p = cms.Path(process.analysis)

process.load("FWCore.MessageLogger.MessageLogger_cfi")
process.MessageLogger.cerr.FwkReport.reportEvery = 1
