import FWCore.ParameterSet.Config as cms

process = cms.Process("ANA")

process.load("FWCore.MessageService.MessageLogger_cfi")

## process.source = cms.Source("PoolSource",
##                             # replace 'myfile.root',' with the source file you want to use
##                          #   fileNames = cms.untracked.vstring('file:test.root')
##                             fileNames = cms.untracked.vstring('/store/cmst3/user/lucieg/CMG/HLT/PFJets/hlt_15.root')## ,
## ##                             eventsToProcess = cms.untracked.VEventRange('191721:88639503')
##                            )

from CMGTools.Production.datasetToSource import *
process.source = datasetToSource(
   'lucieg',
   '/HLT/PFJets/'
   )

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32( -1 ) )
#process.source.duplicateCheckMode = cms.untracked.string('checkEachFile')

process.load('Lucie.HLTPFJetsAnalyzer.selectZevents_cfi')

process.load('Lucie.HLTPFJetsAnalyzer.hltpfjetsanalyzer_cfi')

process.out = cms.OutputModule("PoolOutputModule",
                               fileName = cms.untracked.string('checkZ.root'),
                               SelectEvents   = cms.untracked.PSet( SelectEvents = cms.vstring('p') ),
                               outputCommands = cms.untracked.vstring('drop *',
                                                                      'keep *_Zevents_*_*')
                                                                      
                               )

import HLTrigger.HLTfilters.hltHighLevel_cfi as hlt
process.cleaningfilter = hlt.hltHighLevel.clone(
    TriggerResultsTag = cms.InputTag("TriggerResults","","PAT"),
    HLTPaths = ['EcalDeadCellBoundaryEnergyFilterPath',
                'simpleDRfilterPath',
                'EcalDeadCellTriggerPrimitiveFilterPath',
                'greedyMuonPFCandidateFilterPath',
                'hcalLaserEventFilterPath',
                'inconsistentMuonPFCandidateFilterPath',
                'trackingFailureFilterPath',
                'CSCTightHaloFilterPath',
                'HBHENoiseFilterPath',
                'primaryVertexFilterPath',
                'noscrapingFilterPath',
                'hcalLaserFilterFromAODPath'
                ],
    andOr = False
	)

process.p = cms.Path(
    process.cleaningfilter +
    process.selectZeventsFromMu         +
   # process.HltCaloCmgPfJetsAnalyzer +
    process.HltCmgPfJetsAnalyzer +
    process.HltPFNoPUCmgPfJetsAnalyzer +
  #  process.HltCaloCmgCHSPfJetsAnalyzer + 
    process.HltCmgCHSPfJetsAnalyzer + 
    process.HltPFNoPUCmgchsPfJetsAnalyzer  
    )


process.outpath = cms.EndPath()

process.outpath += process.out

process.MessageLogger.cerr.FwkReport.reportEvery = 1000




