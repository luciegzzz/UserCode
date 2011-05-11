import FWCore.ParameterSet.Config as cms

analysis = cms.EDAnalyzer('METsTreeAnalyzer',
                          vertices        = cms.InputTag("offlinePrimaryVerticesDA"),
                          stdPfMet        = cms.InputTag("stdPfMet"),
                          pfMet           = cms.InputTag("pfMetNoPileUpJets"),
                          pfmetDiscarded  = cms.InputTag("pfMetPileUpJets"),
                          pfJets          = cms.InputTag("ak5PFJets"),
                          pileUpPfJets    = cms.InputTag("PileUpJets"),
                          pfCands         = cms.InputTag("pfCands"),
                          pfPileUpCands   = cms.InputTag("pfPileUpJetsCands"),
                          pfNoPileUpCands = cms.InputTag("pfNoPileUpJetsCands"),
                          HistOutFile     = cms.untracked.string('metTreeNoPUJets.root')
)
