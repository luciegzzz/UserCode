import FWCore.ParameterSet.Config as cms

analysis = cms.EDAnalyzer('METsAnalyzer',
                          calomet = cms.InputTag("met"),
                          pfmet   = cms.InputTag("pfMet"),
                          tcmet   = cms.InputTag("tcMet"),
                          HistOutFile = cms.untracked.string('plots.root')
)
