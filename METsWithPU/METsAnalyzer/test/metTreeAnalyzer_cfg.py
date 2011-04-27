import FWCore.ParameterSet.Config as cms

process = cms.Process("ANALYSIS")

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )
process.options = cms.untracked.PSet(
    SkipEvent = cms.untracked.vstring('ProductNotFound'),
    )

process.source = cms.Source("PoolSource",
                            fileNames = cms.untracked.vstring(
    #MET files, no pv link strict
 'rfio:/castor/cern.ch/user/l/lucieg/METNoPileUp/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_NoPVLinkS/METsNoPileUpNoPVLink_10_1_MHN.root',
 'rfio:/castor/cern.ch/user/l/lucieg/METNoPileUp/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_NoPVLinkS/METsNoPileUpNoPVLink_11_1_j7s.root',
 'rfio:/castor/cern.ch/user/l/lucieg/METNoPileUp/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_NoPVLinkS/METsNoPileUpNoPVLink_1_1_95Q.root',
 'rfio:/castor/cern.ch/user/l/lucieg/METNoPileUp/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_NoPVLinkS/METsNoPileUpNoPVLink_2_1_bsx.root',
 'rfio:/castor/cern.ch/user/l/lucieg/METNoPileUp/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_NoPVLinkS/METsNoPileUpNoPVLink_3_1_W0q.root',
 'rfio:/castor/cern.ch/user/l/lucieg/METNoPileUp/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_NoPVLinkS/METsNoPileUpNoPVLink_4_1_z0r.root',
 'rfio:/castor/cern.ch/user/l/lucieg/METNoPileUp/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_NoPVLinkS/METsNoPileUpNoPVLink_5_1_xYf.root',
 'rfio:/castor/cern.ch/user/l/lucieg/METNoPileUp/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_NoPVLinkS/METsNoPileUpNoPVLink_6_1_nmW.root',
 'rfio:/castor/cern.ch/user/l/lucieg/METNoPileUp/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_NoPVLinkS/METsNoPileUpNoPVLink_7_1_uoX.root',
 'rfio:/castor/cern.ch/user/l/lucieg/METNoPileUp/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_NoPVLinkS/METsNoPileUpNoPVLink_8_1_YtS.root',
 'rfio:/castor/cern.ch/user/l/lucieg/METNoPileUp/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_NoPVLinkS/METsNoPileUpNoPVLink_9_1_Pnc.root',

## ##no pv link, at least 1 PU
##  'rfio:/castor/cern.ch/user/l/lucieg/METNoPileUp/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_NoPVLinkAL1PU/METsNoPileUpNoPVLinkAL1PU_10_1_92a.root',
##  'rfio:/castor/cern.ch/user/l/lucieg/METNoPileUp/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_NoPVLinkAL1PU/METsNoPileUpNoPVLinkAL1PU_11_1_l7X.root',
##  'rfio:/castor/cern.ch/user/l/lucieg/METNoPileUp/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_NoPVLinkAL1PU/METsNoPileUpNoPVLinkAL1PU_1_1_zAl.root',
##  'rfio:/castor/cern.ch/user/l/lucieg/METNoPileUp/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_NoPVLinkAL1PU/METsNoPileUpNoPVLinkAL1PU_2_1_gt2.root',
##  'rfio:/castor/cern.ch/user/l/lucieg/METNoPileUp/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_NoPVLinkAL1PU/METsNoPileUpNoPVLinkAL1PU_3_1_f7L.root',
##  'rfio:/castor/cern.ch/user/l/lucieg/METNoPileUp/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_NoPVLinkAL1PU/METsNoPileUpNoPVLinkAL1PU_4_1_dBD.root',
##  'rfio:/castor/cern.ch/user/l/lucieg/METNoPileUp/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_NoPVLinkAL1PU/METsNoPileUpNoPVLinkAL1PU_5_1_xM0.root',
##  'rfio:/castor/cern.ch/user/l/lucieg/METNoPileUp/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_NoPVLinkAL1PU/METsNoPileUpNoPVLinkAL1PU_6_1_b4l.root',
##  'rfio:/castor/cern.ch/user/l/lucieg/METNoPileUp/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_NoPVLinkAL1PU/METsNoPileUpNoPVLinkAL1PU_7_1_xSF.root',
##  'rfio:/castor/cern.ch/user/l/lucieg/METNoPileUp/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_NoPVLinkAL1PU/METsNoPileUpNoPVLinkAL1PU_8_1_Cfy.root',
##  'rfio:/castor/cern.ch/user/l/lucieg/METNoPileUp/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_NoPVLinkAL1PU/METsNoPileUpNoPVLinkAL1PU_9_1_sT0.root'

## 'rfio:/castor/cern.ch/user/l/lucieg/METNoPileUp/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_nPUgtnPV/METsNoPileUpnPUgtnPV_10_1_hau.root',
## 'rfio:/castor/cern.ch/user/l/lucieg/METNoPileUp/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_nPUgtnPV/METsNoPileUpnPUgtnPV_11_1_z6I.root',
## 'rfio:/castor/cern.ch/user/l/lucieg/METNoPileUp/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_nPUgtnPV/METsNoPileUpnPUgtnPV_1_1_MW7.root',
## 'rfio:/castor/cern.ch/user/l/lucieg/METNoPileUp/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_nPUgtnPV/METsNoPileUpnPUgtnPV_2_1_bEL.root',
## 'rfio:/castor/cern.ch/user/l/lucieg/METNoPileUp/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_nPUgtnPV/METsNoPileUpnPUgtnPV_3_1_Atl.root',
## 'rfio:/castor/cern.ch/user/l/lucieg/METNoPileUp/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_nPUgtnPV/METsNoPileUpnPUgtnPV_4_1_wbh.root',
## 'rfio:/castor/cern.ch/user/l/lucieg/METNoPileUp/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_nPUgtnPV/METsNoPileUpnPUgtnPV_5_1_thY.root',
## 'rfio:/castor/cern.ch/user/l/lucieg/METNoPileUp/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_nPUgtnPV/METsNoPileUpnPUgtnPV_6_1_tYK.root',
## 'rfio:/castor/cern.ch/user/l/lucieg/METNoPileUp/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_nPUgtnPV/METsNoPileUpnPUgtnPV_7_1_aza.root',
## 'rfio:/castor/cern.ch/user/l/lucieg/METNoPileUp/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_nPUgtnPV/METsNoPileUpnPUgtnPV_8_1_Yhw.root',
## 'rfio:/castor/cern.ch/user/l/lucieg/METNoPileUp/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_nPUgtnPV/METsNoPileUpnPUgtnPV_9_1_FTd.root'


    )
)

process.load("METsWithPU.METsAnalyzer.mettreeanalyzer_cfi")
process.analysis.pfmetNoPileUp = cms.InputTag('pfMetPileUp')
process.analysis.HistOutFile = cms.untracked.string('metTreeNoPVLinkPfMetPileUp.root')
#process.analysis.HistOutFile = cms.untracked.string('metTreeNoPVLinkAl1PU.root')
#process.analysis.HistOutFile = cms.untracked.string('metTreenPUgtnPV.root')

process.p = cms.Path(process.analysis)


process.load("FWCore.MessageLogger.MessageLogger_cfi")
process.MessageLogger.cerr.FwkReport.reportEvery = 1000
#process.SimpleMemoryCheck = cms.Service("SimpleMemoryCheck",
 #                                       ignoreTotal=cms.untracked.int32(1))


