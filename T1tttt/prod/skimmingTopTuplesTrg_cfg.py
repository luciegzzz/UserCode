import FWCore.ParameterSet.Config as cms

process = cms.Process("SKIM")

########################
## SOURCES            ##
########################

from CMGTools.Production.datasetToSource import *
process.source = datasetToSource(
   'lucieg',
   '/QCD_HT-1000ToInf_TuneZ2star_8TeV-madgraph-pythia6/Summer12-PU_S7_START52_V9-v1/AODSIM/V5_B/PAT_CMG_V5_6_0_B/TOP/',
#   '/TTJets_TuneZ2star_8TeV-madgraph-tauola/Summer12-PU_S7_START52_V9-v1/AODSIM/V5_B/PAT_CMG_V5_6_0_B/TOP/',
#   '/QCD_HT-100To250_TuneZ2star_8TeV-madgraph-pythia/Summer12-PU_S7_START52_V9-v1/AODSIM/V5_B/PAT_CMG_V5_6_0_B/TOP/',
#   '/QCD_HT-250To500_TuneZ2star_8TeV-madgraph-pythia/Summer12-PU_S7_START52_V9-v1/AODSIM/V5_B/PAT_CMG_V5_6_0_B/TOP/',
#   '/QCD_HT-500To1000_TuneZ2star_8TeV-madgraph-pythia/Summer12-PU_S7_START52_V9-v1/AODSIM/V5_B/PAT_CMG_V5_6_0_B/TOP/',
#   '/SMS-T2tt_FineBin_Mstop-225to1200_mLSP-0to1000_8TeV-Pythia6Z/Summer12-START52_V9_FSIM-v1/AODSIM/V5_B/PAT_CMG_V5_6_0_B/TOP/',
   'topTuple_.*root'
   )

#process.source.fileNames = cms.untracked.vstring('file:/data/lucieg/boostedTops/SAMPLES/topTuple_1.root')
process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )


########################
##   PATHS            ##
########################

process.load('Lucie.T1tttt.skimmingTopTupleTrg_cfi')

process.skim = cms.Path(
    process.skimmingTopTupleTrgSequence
    )


########################
## OUTPUTS DEFINITION ##
########################
process.out = cms.OutputModule(
    "PoolOutputModule",
   # fileName = cms.untracked.string('/data/lucieg/boostedTops/SAMPLES/skim.root'),
    fileName = cms.untracked.string('skim.root'),
    SelectEvents   = cms.untracked.PSet( SelectEvents = cms.vstring('skim') ),
    dropMetaData = cms.untracked.string('PRIOR'),
    outputCommands = cms.untracked.vstring(
    'keep *'
    )
    )

process.outpath = cms.EndPath(
    process.out
    )

## MessageLogger
process.load("FWCore.MessageLogger.MessageLogger_cfi")
process.MessageLogger.cerr.FwkReport.reportEvery = 100

## Options and Output Report
process.options   = cms.untracked.PSet( wantSummary = cms.untracked.bool(True) )

print 'starting CMSSW'

