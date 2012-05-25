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
   '/DoubleMu/PAT_CMG/191718_191810/',
   'cmgTuple_.*root'
   )

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )
#process.source.duplicateCheckMode = cms.untracked.string('checkEachFile')

process.load('Lucie.HLTPFJetsAnalyzer.selectZevents_cfi')
process.load('Lucie.TurnOnAnalyzer.turnonanalyzer_cfi')
#process.dir = 'data/lucieg/turnOn/'

process.p = cms.Path(
 #   process.selectZevents +
    process.turnonanalyzer
    )


process.MessageLogger.cerr.FwkReport.reportEvery = 1000




