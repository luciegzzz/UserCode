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
  # '/TTJets_TuneZ2star_8TeV-madgraph-tauola/Summer12-PU_S7_START52_V9-v1/AODSIM/V5_B/PAT_CMG_V5_6_0_B',
  # '/QCD_HT-1000ToInf_TuneZ2star_8TeV-madgraph-pythia6/Summer12-PU_S7_START52_V9-v1/AODSIM/V5_B/PAT_CMG_V5_6_0_B/',
   '/SMS-T2tt_FineBin_Mstop-225to1200_mLSP-0to1000_8TeV-Pythia6Z/Summer12-START52_V9_FSIM-v1/AODSIM/V5_B/PAT_CMG_V5_6_0_B',
   'cmgTuple_.*root'
   )

#process.source.fileNames = process.source.fileNames[1:2]
process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )


########################
##   PATHS            ##
########################

process.load('Lucie.T1tttt.playingWithTop_cff')
process.load('Lucie.T1tttt.skimmingTopTuple_cfi')
process.load('Lucie.T1tttt.mergingTopCandidates_cfi')


process.pAllHadronic = cms.Path(
    process.playingWithTopAllHadronic + #select all hadr + cluster jets
    process.skimmingTopTupleSequence  + #select top candidates
    process.mergingTopCandidates  #merge top cands 
    )


########################
## OUTPUTS DEFINITION ##
########################
process.outAllHadronic = cms.OutputModule(
    "PoolOutputModule",
    fileName = cms.untracked.string('topTuple.root'),
 #   fileName = cms.untracked.string('/data/lucieg/boostedTops/SAMPLES/topTuple_1.root'),
    SelectEvents   = cms.untracked.PSet( SelectEvents = cms.vstring('pAllHadronic') ),
    dropMetaData = cms.untracked.string('PRIOR'),
    outputCommands = cms.untracked.vstring(
    'drop *',
    'keep *_topCandidatesAkt0p71p75_*_*',
    'keep *_topCandidatesKt0p71p75_*_*',
    'keep *_topCandidatesCa0p71p75_*_*',
    'keep recoBasicJets_aktRecluster*_*_*',
    'keep cmgPFJets_*_*_*',
    'keep *_cmgPFMET*_*_*',
    'keep *_cmgElectronSel_*_*',
    'keep *_cmgMuonSel_*_*',
    'keep *_cmgPhotonSel_*_*',
    'keep *_genJetSel_*_*',
    'keep *_cmgTriggerObjectSel_*_*',
    'keep *_genParticlesPruned_*_*',
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

