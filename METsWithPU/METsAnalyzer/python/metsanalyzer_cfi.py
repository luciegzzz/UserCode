import FWCore.ParameterSet.Config as cms

analysis = cms.EDAnalyzer('METsAnalyzer',
                          met0     = cms.InputTag("met"),
                          met1     = cms.InputTag("pfMet"),
                          met2     = cms.InputTag("pfMetNoPileUp"),#to be renamed 
                          vertices = cms.InputTag("offlinePrimaryVertices"),
                          goodVertices = cms.InputTag("goodVertices"),
                          inputType  = cms.untracked.string("MCOfficial"),#FastSim or MCOfficial
                          HistOutFile = cms.untracked.string('plots.root')
)
