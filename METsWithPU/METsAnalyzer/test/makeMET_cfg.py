import FWCore.ParameterSet.Config as cms

process = cms.Process("REPROD")

process.load("METsWithPU.METsAnalyzer.source_QCD_15_500_7TeV_MCStartup_cff")

process.options   = cms.untracked.PSet( wantSummary = cms.untracked.bool(False))
process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(100) )

#GT -for type I corrections
process.load("Configuration.StandardSequences.FrontierConditions_GlobalTag_cff")
#process.GlobalTag.globaltag = cms.string('START311_V1::All') #MC official samples
from Configuration.PyReleaseValidation.autoCond import autoCond
process.GlobalTag.globaltag = autoCond['startup']


#load jet corrections + MET type I corrections
process.load("JetMETCorrections.Configuration.DefaultJEC_cff")
process.load("JetMETCorrections.Type1MET.MetType1Corrections_cff")

#METNoPileUp module
process.load("METsWithPU.METsAnalyzer.pfMetNoPileUp_cff")

#Good Vertices producer
process.load("METsWithPU.METsAnalyzer.goodVertices_cff")


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
    process.goodVertices +
    process.metJESCorAK5PFJet +
    process.pfNoPileUpSequence +
    process.pfMetNoPileUp##  +
##     process.ak5PFL1Offset
)


process.out = cms.OutputModule("PoolOutputModule",
                               fileName = cms.untracked.string('METs_QCD_15_500_FastSim10k.root'),
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
 
process.load("FWCore.MessageLogger.MessageLogger_cfi")
process.MessageLogger.cerr.FwkReport.reportEvery = 1000
