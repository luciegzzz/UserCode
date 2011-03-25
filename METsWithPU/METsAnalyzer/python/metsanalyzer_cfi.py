import FWCore.ParameterSet.Config as cms

analysis = cms.EDAnalyzer('METsAnalyzer',
                          met     = cms.InputTag("pfMetNoPileUp"),
                          rawmet     = cms.InputTag("pfMet"),
                          vertices = cms.InputTag("offlinePrimaryVerticesDA"),
                          verticesDA = cms.InputTag("offlinePrimaryVerticesDA"),
                          goodVertices = cms.InputTag("goodVertices"),
                          goodVerticesDA = cms.InputTag("goodVerticesDA"),
                          inputType  = cms.untracked.string("FastSim"),#FastSim or MCOfficial
                          HistOutFile = cms.untracked.string('plotspfMetNoPileUp.root')
)
