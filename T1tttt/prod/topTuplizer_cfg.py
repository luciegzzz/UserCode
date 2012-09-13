import FWCore.ParameterSet.Config as cms

process = cms.Process("TOP")

########################
## SOURCES            ##
########################

from CMGTools.Production.datasetToSource import *
## process.source = datasetToSource(
##    'lucieg',
##    '/T2tt/TEST/',
##    'cmgTuple_.*root'
##    )
process.source = datasetToSource(
   'cmgtools',
   ## '/TTJets_TuneZ2star_8TeV-madgraph-tauola/Summer12-PU_S7_START52_V9-v1/AODSIM/V5/PAT_CMG_V5_5_1/',
   
   'cmgTuple_.*root'
   )

#process.source.fileNames = cms.untracked.vstring('file:/data/lucieg/boostedTops/NoPU/533/cmgTuple_TTbar_300_400.root')

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )


########################
##   PATHS            ##
########################

process.load('Lucie.T1tttt.playingWithTop_cff')
process.load('Lucie.T1tttt.skimmingTopTuple_cfi')
process.load('Lucie.T1tttt.buildTopCandidatesCollection_cfi')


process.pAllHadronic = cms.Path(
    process.playingWithTopAllHadronic +
    process.skimmingTopTupleSequence  +
    process.buildTopCandidatesCollection  
    )


########################
## OUTPUTS DEFINITION ##
########################
process.outAllHadronic = cms.OutputModule(
    "PoolOutputModule",
 #   fileName = cms.untracked.string('/data/lucieg/boostedTops/NoPU/533/topTupleAllHadronic_T2tt.root'),
    fileName = cms.untracked.string('test.root'),
    SelectEvents   = cms.untracked.PSet( SelectEvents = cms.vstring('pAllHadronic') ),
    dropMetaData = cms.untracked.string('PRIOR'),
    outputCommands = cms.untracked.vstring(
    'keep *_*_*_PAT',
    'keep *_buildTopCandidatesAkt0p71p75_*_*',
    'keep *_buildTopCandidatesKt0p71p75_*_*',
    'keep *_buildTopCandidatesCa0p71p75_*_*'
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

