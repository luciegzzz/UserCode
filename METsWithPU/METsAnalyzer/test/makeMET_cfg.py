import FWCore.ParameterSet.Config as cms

process = cms.Process("REPROD")

################################
#---------source---------------#
################################    
##FastSim samples
#process.load("METsWithPU.METsAnalyzer.source_QCD_15_500_7TeV_MCStartupFnal_cff")
##MC official sample -for testing purposes. Otherwise, use crab
process.source = cms.Source ("PoolSource",
                             fileNames = cms.untracked.vstring('/store/mc/Spring11/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6/GEN-SIM-RECODEBUG/E7TeV_FlatDist10_2011EarlyData_50ns_START311_V1G1-v1/0002/FEA7702A-033E-E011-989F-00215E21DD26.root')
                             )

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
#------MET stuff --------------#
################################
#METNoPileUp module
process.load("METsWithPU.METsAnalyzer.pfMetNoPileUp_cff")

################################
#####-----Vertices-------#######
################################
#Good Vertices producer (on offline PV for now)
process.load("METsWithPU.METsAnalyzer.goodVertices_cff")
#Vertices with Deterministic Annealing (...)
process.load("RecoVertex.Configuration.RecoVertex_cff")
from RecoVertex.PrimaryVertexProducer.OfflinePrimaryVerticesDA_cfi import *
process.load("RecoVertex.PrimaryVertexProducer.OfflinePrimaryVerticesDA_cfi")
#modifications to match what's on the twiki https://twiki.cern.ch/twiki/bin/view/CMS/PrimaryVertex2011 /cvs - should come with 4_2_0_pre7. Relevant with 3111 ?
process.offlinePrimaryVerticesDA.TkFilterParameters.maxNormalisedChi2 = cms.double(5.0)
process.offlinePrimaryVerticesDA.TkClusParameters.TkDAClusParameters.coolingFactor = cms.double(0.6)
process.offlinePrimaryVerticesDA.TkClusParameters.TkDAClusParameters.Tmin = cms.double(4.)
process.offlinePrimaryVerticesDA.TkClusParameters.TkDAClusParameters.vertexSize = cms.double(0.01)
process.offlinePrimaryVerticesDA.TkClusParameters.TkDAClusParameters.d0CutOff = cms.double(3.)
process.offlinePrimaryVerticesDA.TkClusParameters.TkDAClusParameters.dzCutOff = cms.double(4.)

#Good Vertices with Deterministic Annealing
process.load("METsWithPU.METsAnalyzer.goodVerticesDA_cff")

########################################

## ##L1Offset
## ##-------------------- Communicate with the DB -----------------------
## process.load('Configuration.StandardSequences.Services_cff')
## ##-------------------- Import the JEC services -----------------------
## #process.load('JetMETCorrections.Configuration.DefaultJEC_cff')
## ##-------------------- Disable the CondDB for the L1Offset (until they are included in a new global tag) -------
## process.ak5CaloL1Offset.useCondDB = False
## process.ak5PFL1Offset.useCondDB = False
## process.ak5JPTL1Offset.useCondDB = False
## #.............................................................................................
## ##-------------------- User analyzer  --------------------------------
## ## process.MyAnalyzer  = cms.EDAnalyzer('MyAnalyzer',
## ## ...............................................................................................
## ## JetCorrectionService = cms.string('ak5CaloL1L2L3Residual'), ## or 'ak5PFL1L2L3Residual' or 'ak5JPTL1L2L3Residual'
## ## ...............................................................................................
## ## )

#process.load("JetMETCorrections.Configuration.JetCorrectionServices_cff")
             

####

process.makeMET = cms.Path(
  #  process.pfMET + #already in the AOD from FastSim
    process.offlinePrimaryVerticesDA +
    process.goodVertices +
    process.goodVerticesDA +
    process.metJESCorAK5PFJet +
    process.pfNoPileUpSequence +
    process.pfMetNoPileUp##  +
##     process.ak5PFL1Offset
)


process.out = cms.OutputModule("PoolOutputModule",
                               fileName = cms.untracked.string('METs_QCD_15_500_FastSimMarch15.root'),
                               outputCommands = cms.untracked.vstring('drop *',
                                                   'keep recoPFCandidates_particleFlow_*_*',
                                                   'keep recoPFMETs_*_*_*',
                                                   'keep *_pfPileUp_*_*',
                                                   'keep recoCaloMETs_*_*_*',
                                                   'keep recoVertexs_*_*_*',
                                                   'keep *_metJESCorAK5PFJet_*_*',
#                                                   'keep *_ak5PFL1Offset_*_*',
                                                   'keep edmHepMCProduct_*_*_*',
                                                   'keep PileupSummaryInfo_*_*_*',
                                                   'keep _addPileupInfo_*_*'         
                                                                      )
                               )

process.outpath = cms.EndPath(process.out)

###############################
###-----log-----------------###
###############################
process.load("FWCore.MessageLogger.MessageLogger_cfi")
process.MessageLogger.cerr.FwkReport.reportEvery = 1
process.options   = cms.untracked.PSet( wantSummary = cms.untracked.bool(False))
