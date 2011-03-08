import FWCore.ParameterSet.Config as cms

process = cms.Process("REPROD")

process.source = cms.Source("PoolSource", 
     fileNames = cms.untracked.vstring(#'rfio:/castor/cern.ch/user/l/lucieg/FastSimQCD/QCD_80-120_PU_0_1_1_XND.root'#,
                                       #'rfio:/castor/cern.ch/user/l/lucieg/FastSimQCD/QCD_80-120_PU_5_1_1_Khx.root'#,
                                      # 'rfio:/castor/cern.ch/user/l/lucieg/FastSimQCD/QCD_80-120_PU_10_1_1_r5j.root'
                                       # 'rfio:/castor/cern.ch/user/l/lucieg/FastSimQCD/QCD_80-120_PU_15_1_1_fc8.root'
                                       # 'rfio:/castor/cern.ch/user/l/lucieg/FastSimQCD/QCD_80-120_PU_20_1_1_LoH.root'
                                        'rfio:/castor/cern.ch/user/l/lucieg/FastSimQCD/QCD_80-120_PU_25_1_1_Cal.root'
                                        )
)

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
                               fileName = cms.untracked.string('METsPU25.root'),
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
