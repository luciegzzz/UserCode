import FWCore.ParameterSet.Config as cms

process = cms.Process("ANA")

process.load("FWCore.MessageService.MessageLogger_cfi")

## process.source = cms.Source("PoolSource",
##                             # replace 'myfile.root',' with the source file you want to use
##                          #   fileNames = cms.untracked.vstring('file:test.root')
##                             fileNames = cms.untracked.vstring('/store/cmst3/user/lucieg/CMG/DoubleMu/PAT_CMG/191718_191810/HLT/hlt_2.root')
##                            )

from CMGTools.Production.datasetToSource import *
process.source = datasetToSource(
   'lucieg',
#   '/DoubleMu/PAT_CMG/191718/HLT/'   
   '/DoubleMu/PAT_CMG/191718_191810/HLT/'   
   )

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )
#process.source.duplicateCheckMode = cms.untracked.string('checkEachFile')

process.load('Lucie.HLTPFJetsAnalyzer.selectZevents_cfi')

process.load('Lucie.HLTPFJetsAnalyzer.hltpfjetsanalyzer_cfi')

process.out = cms.OutputModule("PoolOutputModule",
                               fileName = cms.untracked.string('checkZ.root'),
                               SelectEvents   = cms.untracked.PSet( SelectEvents = cms.vstring('p') ),
                               outputCommands = cms.untracked.vstring('drop *',
                                                                      'keep *_Zevents_*_*')
                               )
process.p = cms.Path(
    process.selectZevents         +
    process.HltCaloRecoPfJetsAnalyzer +
    process.HltRecoPfJetsAnalyzer +
    process.HltPFNoPURecoPfJetsAnalyzer +
    process.HltPFNoPUL1L2L3RecoPfJetsAnalyzer +
    process.HltL1L2L3RecoPfJetsAnalyzer +
    process.HltCaloCmgPfJetsAnalyzer +
    process.HltCmgPfJetsAnalyzer +
    process.HltPFNoPUCmgPfJetsAnalyzer +
    process.HltPFNoPUL1L2L3CmgPfJetsAnalyzer +
    process.HltL1L2L3CmgPfJetsAnalyzer + 
    process.HltCaloCmgCHSPfJetsAnalyzer + 
    process.HltCmgCHSPfJetsAnalyzer + 
    process.HltPFNoPUCmgchsPfJetsAnalyzer + 
    process.HltPFNoPUL1L2L3CmgchsPfJetsAnalyzer +
    process.HltL1L2L3CmgchsPfJetsAnalyzer 
    )


process.outpath = cms.EndPath()

process.outpath += process.out

process.MessageLogger.cerr.FwkReport.reportEvery = 1000




