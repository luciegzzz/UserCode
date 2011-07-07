import FWCore.ParameterSet.Config as cms

analysis = cms.EDAnalyzer('Analyzer',
                          patElectrons      = cms.InputTag("selectedPatElectronsAK5"),
                          cmgElectrons      = cms.InputTag("cmgElectronSel"),
)
