import FWCore.ParameterSet.Config as cms

#dir = '/data/lucieg/HltPfJetsAnalyzerNoMatchingHLTMay10/'
dir = ''

turnonanalyzer = cms.EDAnalyzer('TurnOnAnalyzer',
                                triggerResults = cms.InputTag('cmgTriggerObjectSel'),
                                jets           = cms.InputTag('cmgPFJetSelCHS'),
                                met            = cms.InputTag('cmgPFMETRaw'),
                                filename       = cms.untracked.string(dir+'turnOn.root') 
)

