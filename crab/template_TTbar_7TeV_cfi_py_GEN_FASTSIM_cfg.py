# Auto generated configuration file
# using: 
# Revision: 1.172 
# Source: /cvs_server/repositories/CMSSW/CMSSW/Configuration/PyReleaseValidation/python/ConfigBuilder.py,v 
# with command line options: TTbar_7TeV_cfi.py -s GEN,FASTSIM --pileup=NoPileUp --geometry DB --conditions=MC_36Y_V8::All --eventcontent=AODSIM --datatier GEN-SIM-DIGI-RECO -n 10 --no_exec
import FWCore.ParameterSet.Config as cms

process = cms.Process('PROD')

process.maxEvents = cms.untracked.PSet(
    input = cms.untracked.int32(100)
)

#generation
process.source = cms.Source("EmptySource")
process.load('Configuration.Generator.TTbar_7TeV_cfi')

#fastsim
process.load('FastSimulation.Configuration.RandomServiceInitialization_cff')
process.load('FastSimulation.Configuration.CommonInputs_cff')
process.load('FastSimulation.Configuration.FamosSequences_cff')

#simulateCalo and tracking set to true by default
process.famosPileUp.PileUpSimulator.averageNumber = 0.0

#frontier conditions....
process.GlobalTag.globaltag = 'MC_36Y_V8::All'

#mag field
process.load('Configuration.StandardSequences.MagneticField_38T_cff')#used 40 before...no need for volume sth, use tracker sth automatically set to true

## ##"new" stuff from cmsDriver...##################################
##process.generation_step = cms.Path(cms.SequencePlaceholder("randomEngineStateProducer"))

##process.load('Configuration.StandardSequences.Services_cff')#???
#process.load('Configuration.StandardSequences.Generator_cff')#???
##process.load('FastSimulation.Configuration.HLT_1E31_cff')#????

## # set correct vertex smearing
process.Early10TeVCollisionVtxSmearingParameters.type = cms.string("BetaFunc")
process.famosSimHits.VertexGenerator = process.Early10TeVCollisionVtxSmearingParameters
process.famosPileUp.VertexGenerator = process.Early10TeVCollisionVtxSmearingParameters
process.famosSimHits.ApplyAlignment = True#default is False

## # Apply Tracker and Muon misalignment (default is false for tracker,CSC and DT)<Geometries_cff< FastSim, CommonInputs
process.misalignedTrackerGeometry.applyAlignment = True
process.misalignedDTGeometry.applyAlignment = True
process.misalignedCSCGeometry.applyAlignment = True


## # Path and EndPath definitions
## #
####################################################################

##MET corrections
process.load("UserCode.lucieg.corCaloMet_cfi")#reco pf prod pfSimPart comes with famosSeq

#got rid of meta data

#path

process.p1 = cms.Path(
    process.generator+
    process.famosWithEverything+ # = reconstructionWithFamos+simulationWithFamos
    process.particleFlowSimParticle+
    process.metCorSequence
    )


#output definition
process.load('FastSimulation.Configuration.EventContent_cff')
process.aod = cms.OutputModule("PoolOutputModule",
                               process.AODSIMEventContent,
                               fileName = cms.untracked.string('ttbarPU_0.root')
                               )
###from QCD cfg
process.load("RecoParticleFlow.Configuration.Display_EventContent_cff")
process.display = cms.OutputModule("PoolOutputModule",
    process.DisplayEventContent,
    fileName = cms.untracked.string('display.root')
)

#process.outpath = cms.EndPath(process.aod + process.reco + process.display)
process.outpath = cms.EndPath(process.aod+process.display)

#Message logger
process.load("FWCore.MessageLogger.MessageLogger_cfi")
process.options = cms.untracked.PSet(
    makeTriggerResults = cms.untracked.bool(False),
    wantSummary = cms.untracked.bool(False),
    Rethrow = cms.untracked.vstring('Unknown', 
        'ProductNotFound', 
        'DictionaryNotFound', 
        'InsertFailure', 
        'Configuration', 
        'LogicError', 
        'UnimplementedFeature', 
        'InvalidReference', 
        'NullPointerError', 
        'NoProductSpecified', 
        'EventTimeout', 
        'EventCorruption', 
        'ModuleFailure', 
        'ScheduleExecutionFailure', 
        'EventProcessorFailure', 
        'FileInPathError', 
        'FatalRootError', 
        'NotFound')
)
process.MessageLogger.cerr.FwkReport.reportEvery = 20
#
