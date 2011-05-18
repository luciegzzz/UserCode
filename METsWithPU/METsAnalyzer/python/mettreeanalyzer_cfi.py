import FWCore.ParameterSet.Config as cms

analysis = cms.EDAnalyzer('METsTreeAnalyzer',
                          vertices        = cms.InputTag("offlinePrimaryVerticesDA"),
                          stdPfMet        = cms.InputTag("pfMet"),
                          pfMet           = cms.InputTag("pfMetNoPileUp"),
                          pfMetDiscarded  = cms.InputTag("pfMetPileUp"),
                          pfJets          = cms.InputTag("ak5PFJets"),
                          pileUpPfJets    = cms.InputTag("pfPileUpJets"),
                          pfCands         = cms.InputTag("particleFlow"),
                          pfPileUpCands   = cms.InputTag("pfPileUpJetsCand"),
                          pfNoPileUpCands = cms.InputTag("pfNoPileUpJetsCand"),
                          HistOutFile     = cms.untracked.string('metTreeNoPUJets.root')
)
