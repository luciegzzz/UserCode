import FWCore.ParameterSet.Config as cms

process = cms.Process("REPROD")

################################
#---------source---------------#
################################    
##FastSim samples
process.load("METsWithPU.METsAnalyzer.source_QCD_15_500_7TeV_MCStartup_cff")

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(100) )

################################
#------detector conditions-----#
################################ 
#GT -for type I corrections
process.load("Configuration.StandardSequences.FrontierConditions_GlobalTag_cff")
#process.GlobalTag.globaltag = cms.string('START311_V1::All') #MC official samples
from Configuration.PyReleaseValidation.autoCond import autoCond
process.GlobalTag.globaltag = autoCond['startup']
#needed for vertices
process.load("Configuration.StandardSequences.MagneticField_38T_cff")
process.load("Configuration.StandardSequences.Geometry_cff")

################################
#------jet stuff --------------#
################################ 
#load jet corrections + MET type I corrections
process.load("JetMETCorrections.Configuration.DefaultJEC_cff")
process.load("JetMETCorrections.Type1MET.MetType1Corrections_cff")


################################
#----playing with pfNoPileUp---#
################################ 


################################
#------MET stuff --------------#
################################
#make pfMetNoPileUp with old vertices
process.load("METsWithPU.METsAnalyzer.pfMetNoPileUp_cff")

#make pfMetFancy = no pile up with offline primary vertices with deterministic annealing, also removing pf candidates from neutral jets within the barrel (eta <2.4)
process.load("METsWithPU.METsAnalyzer.pfMetFancy_cff")

################################
#---------Vertices-------------#
################################
#Vertices with Deterministic Annealing (...) -from V01-04-04 RecoVertex/PrimaryVertexProducer 3111 looks outdated
process.load("RecoVertex.Configuration.RecoVertex_cff")
from RecoVertex.PrimaryVertexProducer.OfflinePrimaryVertices_cfi import *
process.load("RecoVertex.PrimaryVertexProducer.OfflinePrimaryVertices_cfi")
process.offlinePrimaryVerticesDA = process.offlinePrimaryVertices.clone()

#Good Vertices producer on offline PV 
process.load("METsWithPU.METsAnalyzer.goodVertices_cff")
#Good Vertices with Deterministic Annealing
process.load("METsWithPU.METsAnalyzer.goodVerticesDA_cff")


########################################
#--------Messing around----------------#
########################################
#use HEAD for CommonTools/ParticleFlow so as to get PFNoPileUp.cc wo the assert() when 2 tracks match different vertices
process.load("CommonTools.ParticleFlow.PF2PAT_cff")
#modifies the input vertices forpfNoPileUp and redo PF2PAT sequence (nothing else from PAT), without taus, + pfMetNoPileUPDA
process.pfPileUp.Vertices = cms.InputTag("offlinePrimaryVerticesDA")
process.pfMET.alias = cms.string("pfMetNoPileUpDA")
#makes collection of pfCandidates wo candidates from neutral jets within the barrel
process.load("METsWithPU.METsAnalyzer.pfNoNeutralJetsCand_cff")

#debugging
process.dump = cms.EDAnalyzer("EventContentAnalyzer")


process.makeMET = cms.Path(
    #process.dump +
    process.offlinePrimaryVerticesDA +
    process.goodVertices +
    process.goodVerticesDA +
    process.metJESCorAK5PFJet +
    process.pfNoPileUpOldVtcesSequence +
    process.pfMetNoPileUp  +
    process.PF2PAT  +
    process.pfNoNeutralJetsCandSequence +
    process.pfMetFancy ##  +
##     process.dump
)


process.out = cms.OutputModule("PoolOutputModule",
                               fileName = cms.untracked.string('METsFS.root'),
                               outputCommands = cms.untracked.vstring('drop *',
                                                   'keep recoPFMETs_*_*_*',
                                                   'keep *_pfPileUp*_*_*',
                                                   'keep recoPFCandidates_*_*_*',
                                                   'keep recoVertexs_*_*_*',
                                                   'keep *_metJESCorAK5PFJet_*_*',
                                                   'keep edmHepMCProduct_*_*_*',
                                                   'keep PileupSummaryInfo_*_*_*',
                                                   'keep _addPileupInfo_*_*',         
                                                   'keep recoTracks_*_*_*',
                                                   'keep recoPFJets_*_*_*',
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
