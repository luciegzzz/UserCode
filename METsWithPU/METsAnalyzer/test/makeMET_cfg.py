import FWCore.ParameterSet.Config as cms

process = cms.Process("REPROD")

################################
#---------source---------------#
################################    
##FastSim samples
#process.load("METsWithPU.METsAnalyzer.source_QCD_15_500_7TeV_MCStartup_cff")

##QCD official MC sample
process.source =cms.Source("PoolSource",
                                               fileNames = cms.untracked.vstring(
    '/store/mc/Spring11/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6/GEN-SIM-RECODEBUG/PU_S1_START311_V1G1-v1/0002/FC5ACFBD-774E-E011-AB6B-00215E21D690.root'
    )
                           )

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(100) )

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
#load jet corrections + MET type I corrections
process.load("JetMETCorrections.Configuration.DefaultJEC_cff")
process.load('RecoJets.Configuration.RecoPFJets_cff')

#for L1Fastjet corrections
process.kt6PFJets.doRhoFastjet = True
process.kt6PFJets.Rho_EtaMax = cms.double(2.5)

###re-do jet clustering with pfNoPileUp candidates minus candidates from neutral jets. Filter not enough since need to add "some" fastjet stuff
#module to make collection of pfCandidates wo candidates from neutral jets within the barrel (to recompute the met) & pfCandidates from non-neutralJets within the barrel (for re-clustering)
process.load("METsWithPU.METsAnalyzer.pfNoNeutralJetsCand_cff")

process.pfNoNeutralJetsCandJets.bottomCollection = cms.InputTag("pfNoElectron")

from RecoJets.JetProducers.ak5PFJets_cfi import ak5PFJets
process.ak5PFJetsC = ak5PFJets.clone()
process.ak5PFJetsC.src = cms.InputTag('pfNoNeutralJetsCandJets')#need only candidates from non-neutral jets (don't want isolated leptons)
process.ak5PFJetsC.doAreaFastjet = True
process.ak5PFJetsC.Rho_EtaMax = cms.double(5.0)

################################
#------MET stuff --------------#
################################
#make pfMetNoPileUp with old vertices
process.load("METsWithPU.METsAnalyzer.pfMetNoPileUp_cff")

#make pfMetFancy = no pile up with offline primary vertices with deterministic annealing, also removing pf candidates from neutral jets within the barrel (eta <2.4)
process.load("METsWithPU.METsAnalyzer.pfMetFancy_cff")

#met corrections
process.load("JetMETCorrections.Type1MET.MetType1Corrections_cff")

process.metJESCorAK5PFJet.inpuUncorJetsLabel = cms.string('ak5PFJetsC')
process.metJESCorAK5PFJet.inputUncorMetLabel  = cms.string('pfMetFancy') #pf Met, on pfNoPileUp minus candidates from neutral only
process.metJESCorAK5PFJet.corrector = cms.string('ak5PFL1FastL2L3')


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
process.load("CommonTools.ParticleFlow.PF2PAT_cff")

#modifies the input vertices forpfNoPileUp and redo PF2PAT sequence (nothing else from PAT), without taus, + pfMetNoPileUPDA
process.pfPileUp.Vertices = cms.InputTag("offlinePrimaryVerticesDA") #subsequent steps (pfAll* and pfNoMuon) take pfNoPileUp as input
process.pfMET.alias = cms.string("pfMetNoPileUpDA")

#debugging
process.dump = cms.EDAnalyzer("EventContentAnalyzer")


process.makeMET = cms.Path(
#    process.dump +
    process.offlinePrimaryVerticesDA +
    process.goodVertices +
    process.goodVerticesDA +
    process.pfNoPileUpOldVtcesSequence +
    process.pfMetNoPileUp  +
    process.PF2PAT  +
    process.pfNoNeutralJetsCandSequence +
    process.pfMetFancy +
    process.kt6PFJets* # need for L1FastJet corrections
    process.ak5PFJetsC* # jet clustering after neutral jets removal
    process.ak5PFJetsL2L3+ # compute JEC
    process.metJESCorAK5PFJet ##+
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
