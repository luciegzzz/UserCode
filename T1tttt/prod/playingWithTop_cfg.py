import FWCore.ParameterSet.Config as cms

process = cms.Process("TOP")

########################
## SOURCES            ##
########################

from CMGTools.Production.datasetToSource import *
process.source = datasetToSource(
   'lucieg',
   '/T2tt/TEST/',
   'cmgTuple_.*root'
   )


#process.source.fileNames = cms.untracked.vstring('file:/data/lucieg/boostedTops/NoPU/533/cmgTuple_TTbar_300_400.root')

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )


########################
##   PATHS            ##
########################

process.load('Lucie.T1tttt.playingWithTop_cff')

process.pAllHadronic = cms.Path(
    process.playingWithTopAllHadronic
    )


########################
## OUTPUTS DEFINITION ##
########################
process.outAllHadronic = cms.OutputModule(
    "PoolOutputModule",
    fileName = cms.untracked.string('/data/lucieg/boostedTops/NoPU/533/topTupleAllHadronic_T2tt_FatJetsFromGen.root'),
    SelectEvents   = cms.untracked.PSet( SelectEvents = cms.vstring('pAllHadronic') ),
    dropMetaData = cms.untracked.string('PRIOR'),
    outputCommands = cms.untracked.vstring(
    'keep *'
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

