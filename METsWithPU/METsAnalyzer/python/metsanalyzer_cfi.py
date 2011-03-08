import FWCore.ParameterSet.Config as cms

analysis = cms.EDAnalyzer('METsAnalyzer',
                          met0     = cms.InputTag("met"),
                          met1     = cms.InputTag("pfMet"),
                          met2     = cms.InputTag("pfMETNoPileUp"),#to be renamed 
                          vertices = cms.InputTag("offlinePrimaryVertices"),
                          HistOutFile = cms.untracked.string('plotsPU5.root')
)
