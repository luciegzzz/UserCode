import FWCore.ParameterSet.Config as cms

analysis = cms.EDAnalyzer('METsAnalyzer',
                          met0     = cms.InputTag("pfMetNoPileUpDA"),
                          met1     = cms.InputTag("pfMet"),
                          met2     = cms.InputTag("pfMetNoPileUp"),
                          vertices = cms.InputTag("offlinePrimaryVerticesDA"),
                          goodVertices = cms.InputTag("goodVerticesDA"),
                          inputType  = cms.untracked.string("FastSim"),#FastSim or MCOfficial
                          HistOutFile = cms.untracked.string('plots.root')
)
