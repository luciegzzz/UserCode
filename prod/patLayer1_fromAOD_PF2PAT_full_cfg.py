# This is an example PAT configuration showing the usage of PF2PAT+PAT

# Starting with a skeleton process which gets imported with the following line
from PhysicsTools.PatAlgos.patTemplate_cfg import *

from PhysicsTools.PatAlgos.tools.jetTools import *
process.patJets.addTagInfos = False

#source
process.load("PFAnalyses.CommonTools.Sources.RD.RECO.source_ZInvisibleJetsMadgraph7TeV_cff")
#process.source = cms.untracked.PSet( skipBadFiles = cms.untracked.bool(True))#diff

process.options   = cms.untracked.PSet( wantSummary = cms.untracked.bool(False))
process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(200000) )
process.out.fileName = cms.untracked.string('/uscmst1b_scratch/lpc1/cmsjtmet/lucieg/DATA/patLayer1_fromAOD_PF2PAT_full_ZInvJets7TeV.root')

process.GlobalTag.globaltag = cms.string('GR09_R_35X_V4::All')#SHOULD IT BE CHANGED ??
# load the PAT config
process.load("PhysicsTools.PatAlgos.patSequences_cff")

# Configure PAT to use PF2PAT instead of AOD sources
# this function will modify the PAT sequences. It is currently 
# not possible to run PF2PAT+PAT and standart PAT at the same time
from PhysicsTools.PatAlgos.tools.pfTools import *

# running on the Monte-Carlo?
runOnMC = True
# Disable the filters used for the commissioning ?
disableFilters = True

usePF2PAT(process,runPF2PAT=True, jetAlgo='AK5', runOnMC=runOnMC) 

# turn to false when running on data
process.patElectrons.embedGenMatch = False
process.patMuons.embedGenMatch = False

process.load("PFAnalyses.CommonTools.filters_cff")
process.load("PFAnalyses.LucieAnalysis.susySelection_cff")

#################PATH BLOCK DIFF
# Let it run
process.p = cms.Path(
    process.pfFilter *
    process.patDefaultSequence *
    process.susySelection
    )

###################



if disableFilters:
    process.p.remove(process.pfFilter)


# Add PF2PAT output to the created file
from PhysicsTools.PatAlgos.patEventContent_cff import patEventContentNoCleaning
#process.load("PhysicsTools.PFCandProducer.PF2PAT_EventContent_cff")
#process.out.outputCommands =  cms.untracked.vstring('drop *')
process.out.outputCommands = cms.untracked.vstring('drop *',
                                                   *patEventContentNoCleaning )

process.out.outputCommands.extend(cms.untracked.vstring( 'keep *_particleFlow_*_*',
                                                         'keep *recoPFCandidates_*_*_*',
                                                         'keep *_offlinePrimaryVertices_*_*',
                                                         'keep *_PFJets_*_*',##no real need to keep this since the filter cleans the collection selectedPatJets
                                                         'keep *_CaloJets_*_*',
                                                         'keep *_PFpatMHTs_*_*',
                                                         'keep *_patElectrons_*_*',
                                                         'keep *_*vertices*_*_*',
                                                         'keep *_selectedMHT_*_*',
                                                          'keep *_selectedJetsNr_*_*',
                                                          'keep *_selectedJetsPtEta_*_*'
                                                        ))
# writing only the events getting to the end of path p (the filtered events)
process.out.SelectEvents = cms.untracked.PSet( SelectEvents = cms.vstring('p') )

# In addition you usually want to change the following parameters:
#
#   process.GlobalTag.globaltag =  ...      (according to https://twiki.cern.ch/twiki/bin/view/CMS/SWGuideFrontierConditions)
#   process.out.outputCommands = [ ... ]    (e.g. taken from PhysicsTools/PatAlgos/python/patEventContent_cff.py)

process.MessageLogger.cerr.FwkReport.reportEvery = 10
