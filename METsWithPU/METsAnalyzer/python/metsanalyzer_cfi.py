import FWCore.ParameterSet.Config as cms

analysis = cms.EDAnalyzer('METsAnalyzer',
                          met0     = cms.InputTag("met"),
                          met1     = cms.InputTag("pfMet"),
                          met2     = cms.InputTag("pfMetNoPileUp"),#to be renamed 
                          vertices = cms.InputTag("offlinePrimaryVertices"),
                          HepMCEvent = cms.InputTag("PileUpEvents"),
                          inputType  = cms.InputTag("FastSim"),
                          HistOutFile = cms.untracked.string('plotsPU5.root')
)
