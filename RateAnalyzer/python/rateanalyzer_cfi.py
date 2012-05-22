import FWCore.ParameterSet.Config as cms


dir = ''

rateanalyzer= cms.EDAnalyzer('RateAnalyzer',
                         #    triggerResults      = cms.InputTag("TriggerResults", "", "L1SKIM"),
                             triggerResults      = cms.InputTag("TriggerResults", "", "TEST"),
                             normalizationFactor = cms.untracked.double(1.88), # to 5e33
                             filename            = cms.untracked.string(dir+'dummy.root'),
                             )

