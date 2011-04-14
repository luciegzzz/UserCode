import FWCore.ParameterSet.Config as cms

analysis = cms.EDAnalyzer('METsAnalyzer',
                          met     = cms.InputTag("pfMet"),
                          rawmet     = cms.InputTag("pfMet"),
                          vertices = cms.InputTag("offlinePrimaryVertices"),
                          verticesDA = cms.InputTag("offlinePrimaryVerticesDA"),
                          goodVertices = cms.InputTag("goodVertices"),
                          goodVerticesDA = cms.InputTag("goodVerticesDA"),
                          inputType  = cms.untracked.string("MCOfficial"),#FastSim or MCOfficial
                          fillVerticesHistos = cms.untracked.bool(True),
                          HistOutFile = cms.untracked.string('plots.root')
)
