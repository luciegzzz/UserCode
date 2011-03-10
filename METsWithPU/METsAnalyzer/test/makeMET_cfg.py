import FWCore.ParameterSet.Config as cms

process = cms.Process("REPROD")

process.load("METsWithPU.METsAnalyzer.source_QCD_15-500_7TeV_MCIdl_cff")

process.options   = cms.untracked.PSet( wantSummary = cms.untracked.bool(False))
process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )

#met producer
process.load("PhysicsTools.PFCandProducer.pfMET_cfi")

process.load("PhysicsTools.PFCandProducer.pfNoPileUp_cff")

process.pfMETNoPileUp = process.pfMET.clone()
process.pfMETNoPileUp.src = 'pfNoPileUp'

process.p = cms.Path(
  #  process.pfMET + #already in the AOD from FastSim
    process.pfNoPileUpSequence +
    process.pfMETNoPileUp 
)


process.out = cms.OutputModule("PoolOutputModule",
                               fileName = cms.untracked.string('METs_QCD_15-500_PU15.root'),
                               outputCommands = cms.untracked.vstring('drop *',
                                                   'keep recoPFCandidates_particleFlow_*_*',
                                                   'keep recoPFMETs_*_*_*',
                                                   'keep *_pfPileUp_*_*',
                                                   'keep recoCaloMETs_*_*_*',
                                                   'keep recoVertexs_*_*_*' 
                                                                      )
                               )

process.outpath = cms.EndPath(process.out)
 
process.load("FWCore.MessageLogger.MessageLogger_cfi")
process.MessageLogger.cerr.FwkReport.reportEvery = 100
