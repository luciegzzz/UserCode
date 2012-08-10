import FWCore.ParameterSet.Config as cms

process = cms.Process("TOP")

########################
## SOURCES            ##
########################

from CMGTools.Production.datasetToSource import *
process.source = datasetToSource(
   'cmgtools',
   '/TTJets_TuneZ2star_8TeV-madgraph-tauola/Summer12-PU_S7_START52_V9-v1/AODSIM/V5/PAT_CMG_V5_4_0_NewType1MET/'
   )


## process.source.fileNames = cms.untracked.vstring('file:/data/lucieg/boostedTops/NoPU/cmgTuple_QCD_300_400.root')
## process.source.fileNames = cms.untracked.vstring('file:/data/lucieg/boostedTops/NoPU/cmgTuple_QCD_600_700.root')
process.source.fileNames = cms.untracked.vstring('file:/data/lucieg/boostedTops/NoPU/cmgTuple_QCD_15_3000.root')
## process.source.fileNames = cms.untracked.vstring('file:/data/lucieg/boostedTops/NoPU/cmgTuple_QCD_15_3000.root')
#process.source.fileNames = cms.untracked.vstring('file:test.root')

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
##    fileName = cms.untracked.string('/data/lucieg/boostedTops/NoPU/topTupleAllHadronic_QCD_300_400.root'),
##    fileName = cms.untracked.string('/data/lucieg/boostedTops/NoPU/topTupleAllHadronic_QCD_600_700.root'),
##     fileName = cms.untracked.string('/data/lucieg/boostedTops/NoPU/topTupleAllHadronic_QCD_900_1000.root'),
     fileName = cms.untracked.string('/data/lucieg/boostedTops/NoPU/topTupleAllHadronic_QCD_15_3000.root'),
 
    SelectEvents   = cms.untracked.PSet( SelectEvents = cms.vstring('pAllHadronic') ),
    dropMetaData = cms.untracked.string('PRIOR'),
    outputCommands = cms.untracked.vstring(
    'keep *_*_*_PAT',
    'keep *'
    #'keep recoJets_*_*_*'
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

