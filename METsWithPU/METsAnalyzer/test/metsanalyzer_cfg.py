import FWCore.ParameterSet.Config as cms

process = cms.Process("ANALYSIS")

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(1000) )

process.source = cms.Source("PoolSource",
    # replace 'myfile.root' with the source file you want to use
    fileNames = cms.untracked.vstring(
  '/store/mc/Spring10/QCD_Pt-15_7TeV-pythia6/GEN-SIM-RECO/START3X_V26B-v1/0051/FA72BA34-555E-DF11-AB7E-00304865C2D0.root',
       
    )
)

process.load("METsWithPU.METsAnalyzer.metsanalyzer_cfi")

#process.analyze = cms.EDAnalyzer('METsAnalyzer')


process.p = cms.Path(process.analysis)


process.load("FWCore.MessageLogger.MessageLogger_cfi")
process.MessageLogger.cerr.FwkReport.reportEvery = 1
