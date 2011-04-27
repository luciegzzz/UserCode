import FWCore.ParameterSet.Config as cms

analysis = cms.EDAnalyzer('METsTreeAnalyzer',
                          vertices        = cms.InputTag("offlinePrimaryVerticesDA"),
                          pfmet           = cms.InputTag("pfMet"),
                          pfmetRecomputed = cms.InputTag("pfMetNoPileUp"),
                          pfmetDiscarded  = cms.InputTag("pfMetPileUp"),
                          HistOutFile     = cms.untracked.string('metTree.root')
)
