import FWCore.ParameterSet.Config as cms

analysis = cms.EDAnalyzer('JetAnalyzer',
                          jets         = cms.InputTag("ak5PFJets"),
                          genJets      = cms.InputTag("ak5GenJets"),
                          vertices     = cms.InputTag("offlinePrimaryVerticesDA"),
                          HistOutFile  = cms.untracked.string('histosJetsPVStrict.root')
)
