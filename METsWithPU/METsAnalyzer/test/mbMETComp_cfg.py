import FWCore.ParameterSet.Config as cms

process = cms.Process("REPROD")

################################
#---------source---------------#
################################    

##QCD official MC sample
process.source =cms.Source("PoolSource",
                           fileNames = cms.untracked.vstring(
#    '/store/relval/CMSSW_4_2_0_pre4/RelValMinBias/GEN-SIM-RECO/MC_42_V1-v1/0000/A4505C44-DC38-E011-9FD3-002618943940.root'
#'file:/tmp/lucieg/A4505C44-DC38-E011-9FD3-002618943940.root'
#'/store/mc/Spring11/MinBias_TuneZ2_7TeV-pythia6/GEN-SIM-RECODEBUG/START311_V1G1-v2/0016/44FD2E01-2550-E011-B3FB-00261894385A.root'#,
#'rfio:/castor/cern.ch/user/l/lucieg/MET/MinBias/MinBias_TuneZ2_7TeV-pythia6_GEN-SIM-RECODEBUG_START311_V1G1-v2_44FD2E01-2550-E011-B3FB-00261894385A.root'
'file:/tmp/lucieg/MinBias_TuneZ2_7TeV-pythia6_GEN-SIM-RECODEBUG_START311_V1G1-v2_44FD2E01-2550-E011-B3FB-00261894385A.root'
 )
                           )

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )

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

###############################
#---------Vertices-------------#
################################
#Vertices with Deterministic Annealing (...) -from V01-04-04 RecoVertex/PrimaryVertexProducer 3111 looks outdated
process.load("RecoVertex.Configuration.RecoVertex_cff")
from RecoVertex.PrimaryVertexProducer.OfflinePrimaryVertices_cfi import *
process.load("RecoVertex.PrimaryVertexProducer.OfflinePrimaryVertices_cfi")
process.offlinePrimaryVerticesDA = process.offlinePrimaryVertices.clone()


################################
#------MET stuff --------------#
################################
#before PFNoPileUp
process.load("METsWithPU.METsAnalyzer.pfMetComp_cff")

#after PFNoPileUp
from METsWithPU.METsAnalyzer.pfMetNoPileUpDA_cff import *
process.load("METsWithPU.METsAnalyzer.pfMetNoPileUpDA_cff")

## from PhysicsTools.PatAlgos.tools.helpers import *

## postfix = "NPU"
## pfMetCompSequenceAfterPFNoPileUp = applyPostfix(process, "pfMetCompSequence", postfix)

process.pfCandBarrelNPU       = process.pfCandBarrel.clone(alias="pfCandBarrelNPU")
process.pfCandBarrelNPU.src   = 'pfNoPileUpDA'
process.pfCandFwdBwdNPU       = process.pfCandFwdBwd.clone(alias="pfCandFwdBwdNPU")
process.pfCandFwdBwdNPU.src   = 'pfNoPileUpDA'
process.pfCandNeutralNPU      = process.pfCandNeutral.clone(alias="pfCandNeutralNPU")
process.pfCandNeutralNPU.src  = 'pfNoPileUpDA'
process.pfCandChargedNPU      = process.pfCandCharged.clone(alias="pfCandChargedNPU")
process.pfCandChargedNPU.src  = 'pfNoPileUpDA'
process.pfMetBarrelNPU        = process.pfMetBarrel.clone(alias="pfMetBarrelNPU")
process.pfMetFwdBwdNPU        = process.pfMetFwdBwd.clone(alias="pfMetFwdBwdNPU")
process.pfMetNeutralNPU       = process.pfMetNeutral.clone(alias="pfMetNeutralNPU")
process.pfMetChargedNPU       = process.pfMetCharged.clone(alias="pfMetChargedNPU")

process.pfMetCompSequenceAfterPFNoPileUp = cms.Sequence(
    process.pfCandBarrelNPU +
    process.pfMetBarrelNPU +
    process.pfCandFwdBwdNPU +
    process.pfMetFwdBwdNPU +
    process.pfCandChargedNPU +
    process.pfMetChargedNPU  +
    process.pfCandNeutralNPU +
    process.pfMetNeutralNPU
    )

process.dump = cms.EDAnalyzer("EventContentAnalyzer")


process.makeMET = cms.Path(
   # process.dump +
    process.pfMetCompSequence +
    process.offlinePrimaryVerticesDA +
    process.pfNoPileUpDASequence +
    process.pfMetNoPileUpDA +
    process.pfMetCompSequenceAfterPFNoPileUp
    

)


process.out = cms.OutputModule("PoolOutputModule",
                               fileName = cms.untracked.string('METCompsMB.root'),
                               outputCommands = cms.untracked.vstring('drop *',
                                                   'keep *_particleFlow_*_*',
                                                   'keep recoPFMETs_*_*_*',
                                                   'keep recoPFCandidates_*_*_*',
                                                   'keep edmHepMCProduct_*_*_*',
                                                   'keep *_*_*_REPROD'
                                                                      )
                               )

process.outpath = cms.EndPath(process.out)

###############################
###-----log-----------------###
###############################
process.load("FWCore.MessageLogger.MessageLogger_cfi")
process.MessageLogger.cerr.FwkReport.reportEvery = 1
process.options   = cms.untracked.PSet( wantSummary = cms.untracked.bool(False))
