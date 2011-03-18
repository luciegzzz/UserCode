import FWCore.ParameterSet.Config as cms

process = cms.Process("ANALYSIS")

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )
process.options = cms.untracked.PSet(
    SkipEvent = cms.untracked.vstring('ProductNotFound'),
    )

#process.source = cms.Source("PoolSource",
#     replace 'myfile.root' with the source file you want to use
#   fileNames = cms.untracked.vstring(
#    'file:rfio:/castor/cern.ch/user/l/lucieg/MET/METs_QCD_15-500_PU0.root'       
#    'file:/afs/fnal.gov/files/home/room1/lucieg/cms_nb/METs_QCD_15_500_FastSim.root'
#    'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_Flat_FlatDist10_Spring2011/METs_QCD_15_3000Flat_FlatDist10_9_1_wvw.root',
#    'file:rfio:/castor/cern.ch/user/l/lucieg/MET/METs_QCD_15-500_PU0.root'       
#    'file:METs_QCD_15_500_FastSimMarch15.root'

 #   )
#)

process.load("METsWithPU.METsAnalyzer.source_QCD_Pt_15to3000_Flat_FlatDist10_Spring2011GV500k_cfi")

process.load("METsWithPU.METsAnalyzer.metsanalyzer_cfi")

process.analysis.HistOutFile = cms.untracked.string('plotsQCDGV500k_3.root')

process.p = cms.Path(process.analysis)


process.load("FWCore.MessageLogger.MessageLogger_cfi")
process.MessageLogger.cerr.FwkReport.reportEvery = 1000
#process.SimpleMemoryCheck = cms.Service("SimpleMemoryCheck",
 #                                       ignoreTotal=cms.untracked.int32(1))


