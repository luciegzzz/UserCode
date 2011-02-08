import FWCore.ParameterSet.Config as cms

process = cms.Process("PLOT")

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )

process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
    'file:/uscms/home/gerstein/lpcgg/cmsdas/fsim_1TeV_Wprime-Mpp150.root'
    )
)
## process.options = cms.untracked.PSet(
##   fileMode = cms.untracked.string('NOMERGE')
## )
process.analyzer = cms.EDAnalyzer('PhotonPlots',
                                  HistOutFile = cms.untracked.string('PhotonPlotsMC.root')
                                  )



process.p = cms.Path(process.analyzer)

process.load("FWCore.MessageLogger.MessageLogger_cfi")
process.MessageLogger.cerr.FwkReport.reportEvery = 1000
