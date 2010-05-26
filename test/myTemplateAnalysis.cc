import FWCore.ParameterSet.Config as cms

#########################################################
# IMPORTANT: 
# this file can be used with cmsRun (full framework), or
# with readEventsDemo (FWLite, see ../bin/ directory )

process = cms.Process("ANA")

# initialize MessageLogger and output report
process.load("FWCore.MessageLogger.MessageLogger_cfi")
process.MessageLogger.cerr.FwkReport.reportEvery = 1

#########################################################
# Configuration of the FWLiteTreeAnalyzer,
# USED ONLY IN FWLITE MODE

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )

process.load("PFAnalyses.myTemplateAnalysis.Sources.source_ZInvJet7TeV_cff")

# BEGINNERS, DON'T HAVE A LOOK AT THIS PART YET. 
##In the metadata we pass the preselection efficiency and the
##sample name. The sample name will be added to the name of the
##output ROOT file with the histograms
##The output file location is defined by outputPath parameter
process.configurationMetadata = cms.untracked.PSet(
     version = cms.untracked.string('1.0'),
     name = cms.untracked.string('Test'),
     annotation = cms.untracked.string('None'),
     # If you don't know what it is, you don't care yet :)
     preselectionEff = cms.untracked.double(1.0),
     outputPath = cms.untracked.string('./'),
 )

process.Summary =  cms.PSet(
    selectionFlavours = cms.untracked.vstring("")
    ) #dunno what this is doing


########################################################
# Configuration of the WenuAnalyzer used
# in the example analysis, USED ONLY IN FWLITE MODE
# There is no path, and no sequence in FWLite mode.
# Please have a look at
#   ../bin/readEventsDemo.cc
#   ../src/WenuAnalyzer.cc
# for more information 

# master verbose flag
verbose = False

process.myTemplateAnalyzer =  cms.PSet(
    verbose  = cms.bool( verbose ),
    muonLabel = cms.InputTag("selectedPatMuons"),
    metLabel = cms.InputTag("patMETs"),
    jetLabel = cms.InputTag("selectedPatJets")
)

