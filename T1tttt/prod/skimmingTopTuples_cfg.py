import FWCore.ParameterSet.Config as cms

process = cms.Process("SKIM")

########################
## SOURCES            ##
########################

from CMGTools.Production.datasetToSource import *
process.source = datasetToSource(
   'lucieg',
   '/T2tt/TEST/',
   'cmgTuple_.*root'
   )


#process.source.fileNames = cms.untracked.vstring('file:/data/lucieg/boostedTops/NoPU/533/topTupleAllHadronic_T2tt.root')
process.source.fileNames = cms.untracked.vstring('/store/cmst3/user/lucieg/CMG/T2tt/TEST/TopTuple/topTupleAllHadronic_0.root')
process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )


########################
##   PATHS            ##
########################

process.load('Lucie.T1tttt.skimmingTopTuple_cfi')
process.load('Lucie.T1tttt.buildTopCandidatesCollection_cfi')

process.skim = cms.Path(
    process.skimmingTopTupleSequence  +
    process.buildTopCandidatesCollection
    )


########################
## OUTPUTS DEFINITION ##
########################
process.outAllHadronic = cms.OutputModule(
    "PoolOutputModule",
    fileName = cms.untracked.string('/data/lucieg/boostedTops/NoPU/533/skim_topTupleAllHadronic_T2tt.root'),
   # fileName = cms.untracked.string('test.root'),
#    SelectEvents   = cms.untracked.PSet( SelectEvents = cms.vstring('skim') ),
    dropMetaData = cms.untracked.string('PRIOR'),
    outputCommands = cms.untracked.vstring(
    'keep *_*_*_SKIM',
    'keep *_genParticlesPruned_*_*'
    )
    )

process.outpath = cms.EndPath(
    process.outAllHadronic
    )

## MessageLogger
process.load("FWCore.MessageLogger.MessageLogger_cfi")
process.MessageLogger.cerr.FwkReport.reportEvery = 100

## Options and Output Report
process.options   = cms.untracked.PSet( wantSummary = cms.untracked.bool(True) )

print 'starting CMSSW'

