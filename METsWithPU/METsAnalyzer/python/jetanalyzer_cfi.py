import FWCore.ParameterSet.Config as cms

analysis = cms.EDAnalyzer('JetAnalyzer',
                          vertices     = cms.InputTag("offlinePrimaryVerticesDA"),
                          jets         = cms.InputTag("ak5PFJets"),
                          genJets      = cms.InputTag("ak5GenJets"),
                          pfmet        = cms.InputTag("pfMet"),
                          pfCandidates = cms.InputTag("particleFlow"),
                          HistOutFile  = cms.untracked.string('histosJets.root')
)
