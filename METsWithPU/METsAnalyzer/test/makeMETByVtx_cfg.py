import FWCore.ParameterSet.Config as cms

process = cms.Process("PROD")

process.load("FWCore.Framework.test.cmsExceptionsFatal_cff")

################################
#---------source---------------#
################################    
##QCD official MC sample
process.source = cms.Source("PoolSource",
                                               fileNames = cms.untracked.vstring(
  #  '/store/mc/Spring11/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6/GEN-SIM-RECODEBUG/PU_S1_START311_V1G1-v1/0002/FC5ACFBD-774E-E011-AB6B-00215E21D690.root'
   'rfio:/castor/cern.ch/user/l/lucieg/MET/QCD/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_GEN-SIM-RECODEBUG_PU_S1_START311_V1G1-v1_FC5ACFBD-774E-E011-AB6B-00215E21D690.root'
 )#,
# skipEvents = cms.untracked.uint32(2000)
                           )

process.options = cms.untracked.PSet(
    SkipEvent = cms.untracked.vstring('ProductNotFound')
)

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(1000) )

################################
#------detector conditions-----#
################################ 
#GT -for type I corrections
process.load("Configuration.StandardSequences.FrontierConditions_GlobalTag_cff")
from Configuration.PyReleaseValidation.autoCond import autoCond
process.GlobalTag.globaltag = autoCond['startup']

#needed for vertices
process.load("Configuration.StandardSequences.MagneticField_38T_cff")
process.load("Configuration.StandardSequences.Geometry_cff")

################################
#------jet stuff --------------#
################################ 



################################
#------MET stuff --------------#
################################
process.load("METsWithPU.METsAnalyzer.pfCandsSplitByVertex_cfi")


################################
#---------Vertices-------------#
################################
#Vertices with Deterministic Annealing (...) -from V01-04-04 RecoVertex/PrimaryVertexProducer 3111 looks outdated
process.load("RecoVertex.Configuration.RecoVertex_cff")
from RecoVertex.PrimaryVertexProducer.OfflinePrimaryVertices_cfi import *
process.load("RecoVertex.PrimaryVertexProducer.OfflinePrimaryVertices_cfi")
process.offlinePrimaryVerticesDA = process.offlinePrimaryVertices.clone()


#debugging
#process.dump = cms.EDAnalyzer("EventContentAnalyzer")


process.makeMET = cms.Path(
    process.offlinePrimaryVerticesDA +
    process.pfCandsSplitByVertex  #+
    # process.dump
)


process.out = cms.OutputModule("PoolOutputModule",
                               fileName = cms.untracked.string('METs.root'),
                               outputCommands = cms.untracked.vstring('drop *',
                                                   'keep recoPFMETs_*_*_*',
                                                   'keep recoPFCandidates_*_*_*',
                                                   'keep recoVertexs_*_*_*',
                                                   'keep edmHepMCProduct_*_*_*',
                                                   'keep PileupSummaryInfos_*_*_*',
                                                   'keep _addPileupInfo_*_*',         
                                                   'keep recoPFJets_*_*_*',
                                                   'keep *_*_*_REPROD',
                                                   'keep *_*_*_PROD'
                                                                      )
                               )

process.outpath = cms.EndPath(process.out)

###############################
###-----log-----------------###
###############################
process.load("FWCore.MessageLogger.MessageLogger_cfi")
process.MessageLogger.cerr.FwkReport.reportEvery = 1
process.options   = cms.untracked.PSet( wantSummary = cms.untracked.bool(False))
