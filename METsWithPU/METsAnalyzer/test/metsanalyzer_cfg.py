import FWCore.ParameterSet.Config as cms

process = cms.Process("ANALYSIS")

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )

process.source = cms.Source("PoolSource",
    # replace 'myfile.root' with the source file you want to use
    fileNames = cms.untracked.vstring(
    'file:rfio:/castor/cern.ch/user/l/lucieg/MET/METs_QCD_15-500_PU0.root'       
    )
)

process.load("METsWithPU.METsAnalyzer.metsanalyzer_cfi")

process.analysis.HistOutFile = cms.untracked.string('plotsPU0.root')

process.p = cms.Path(process.analysis)


process.load("FWCore.MessageLogger.MessageLogger_cfi")
process.MessageLogger.cerr.FwkReport.reportEvery = 100
