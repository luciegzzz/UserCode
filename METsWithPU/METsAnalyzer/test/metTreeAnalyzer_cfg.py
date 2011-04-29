import FWCore.ParameterSet.Config as cms

process = cms.Process("ANALYSIS")

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )
process.options = cms.untracked.PSet(
    SkipEvent = cms.untracked.vstring('ProductNotFound'),
    )

process.source = cms.Source("PoolSource",
                            fileNames = cms.untracked.vstring(
    #MET files, no pv link strict
#'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_NoPVLinkS/METsNoPileUpNoPVLink_10_1_zhC.root',
#'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_NoPVLinkS/METsNoPileUpNoPVLink_11_1_Jij.root',
#'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_NoPVLinkS/METsNoPileUpNoPVLink_12_1_OSv.root',
#'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_NoPVLinkS/METsNoPileUpNoPVLink_13_1_ypl.root',
#'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_NoPVLinkS/METsNoPileUpNoPVLink_14_1_TZd.root',
#'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_NoPVLinkS/METsNoPileUpNoPVLink_15_1_29g.root',
#'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_NoPVLinkS/METsNoPileUpNoPVLink_16_1_YtE.root',
#'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_NoPVLinkS/METsNoPileUpNoPVLink_17_1_GnQ.root',
#'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_NoPVLinkS/METsNoPileUpNoPVLink_18_1_PWW.root',
#'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_NoPVLinkS/METsNoPileUpNoPVLink_19_1_YfQ.root',
#'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_NoPVLinkS/METsNoPileUpNoPVLink_1_1_TjA.root',
#'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_NoPVLinkS/METsNoPileUpNoPVLink_20_1_umu.root',
#'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_NoPVLinkS/METsNoPileUpNoPVLink_21_1_APk.root',
#'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_NoPVLinkS/METsNoPileUpNoPVLink_22_1_rMy.root',
#'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_NoPVLinkS/METsNoPileUpNoPVLink_23_1_Gfe.root',
#'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_NoPVLinkS/METsNoPileUpNoPVLink_24_1_SMk.root',
#'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_NoPVLinkS/METsNoPileUpNoPVLink_25_1_NLf.root',
#'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_NoPVLinkS/METsNoPileUpNoPVLink_26_1_Lsf.root',
#'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_NoPVLinkS/METsNoPileUpNoPVLink_2_1_QxV.root',
#'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_NoPVLinkS/METsNoPileUpNoPVLink_3_1_nR0.root',
#'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_NoPVLinkS/METsNoPileUpNoPVLink_4_1_wi4.root',
#'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_NoPVLinkS/METsNoPileUpNoPVLink_5_1_H9e.root',
#'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_NoPVLinkS/METsNoPileUpNoPVLink_6_1_Dww.root',
#'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_NoPVLinkS/METsNoPileUpNoPVLink_7_1_ncb.root',
#'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_NoPVLinkS/METsNoPileUpNoPVLink_8_1_zdc.root',
#'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_NoPVLinkS/METsNoPileUpNoPVLink_9_1_YOL.root'



## ##no pv link, at least 1 PU
##'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_NoPVLinkAL1PU/METsNoPileUpNoPVLinkAL1PU_10_1_bhn.root',
##'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_NoPVLinkAL1PU/METsNoPileUpNoPVLinkAL1PU_11_1_gx3.root',
##'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_NoPVLinkAL1PU/METsNoPileUpNoPVLinkAL1PU_12_1_hDU.root',
##'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_NoPVLinkAL1PU/METsNoPileUpNoPVLinkAL1PU_13_1_KLm.root',
##'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_NoPVLinkAL1PU/METsNoPileUpNoPVLinkAL1PU_14_1_5cU.root',
##'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_NoPVLinkAL1PU/METsNoPileUpNoPVLinkAL1PU_15_1_S0C.root',
##'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_NoPVLinkAL1PU/METsNoPileUpNoPVLinkAL1PU_16_1_y8q.root',
##'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_NoPVLinkAL1PU/METsNoPileUpNoPVLinkAL1PU_17_1_j8T.root',
##'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_NoPVLinkAL1PU/METsNoPileUpNoPVLinkAL1PU_18_1_WaZ.root',
##'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_NoPVLinkAL1PU/METsNoPileUpNoPVLinkAL1PU_19_1_Und.root',
##'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_NoPVLinkAL1PU/METsNoPileUpNoPVLinkAL1PU_1_1_kWn.root',
##'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_NoPVLinkAL1PU/METsNoPileUpNoPVLinkAL1PU_20_1_JpQ.root',
##'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_NoPVLinkAL1PU/METsNoPileUpNoPVLinkAL1PU_21_1_22G.root',
##'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_NoPVLinkAL1PU/METsNoPileUpNoPVLinkAL1PU_22_1_Ox3.root',
##'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_NoPVLinkAL1PU/METsNoPileUpNoPVLinkAL1PU_23_1_zVW.root',
##'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_NoPVLinkAL1PU/METsNoPileUpNoPVLinkAL1PU_24_1_2hy.root',
##'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_NoPVLinkAL1PU/METsNoPileUpNoPVLinkAL1PU_25_1_yqi.root',
##'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_NoPVLinkAL1PU/METsNoPileUpNoPVLinkAL1PU_26_1_5gz.root',
##'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_NoPVLinkAL1PU/METsNoPileUpNoPVLinkAL1PU_2_1_M27.root',
##'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_NoPVLinkAL1PU/METsNoPileUpNoPVLinkAL1PU_3_1_5Ad.root',
##'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_NoPVLinkAL1PU/METsNoPileUpNoPVLinkAL1PU_4_1_yOC.root',
##'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_NoPVLinkAL1PU/METsNoPileUpNoPVLinkAL1PU_5_1_I1h.root',
##'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_NoPVLinkAL1PU/METsNoPileUpNoPVLinkAL1PU_6_1_RQm.root',
##'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_NoPVLinkAL1PU/METsNoPileUpNoPVLinkAL1PU_7_1_IJJ.root',
##'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_NoPVLinkAL1PU/METsNoPileUpNoPVLinkAL1PU_8_1_YHA.root',
##'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_NoPVLinkAL1PU/METsNoPileUpNoPVLinkAL1PU_9_1_sU0.root'

#'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_nPUgtnPV/METsNoPileUpnPUgtnPV_10_1_0Oy.root',
#'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_nPUgtnPV/METsNoPileUpnPUgtnPV_11_1_1eI.root',
#'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_nPUgtnPV/METsNoPileUpnPUgtnPV_12_1_sXj.root',
#'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_nPUgtnPV/METsNoPileUpnPUgtnPV_13_1_pE0.root',
#'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_nPUgtnPV/METsNoPileUpnPUgtnPV_14_1_QVL.root',
#'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_nPUgtnPV/METsNoPileUpnPUgtnPV_15_1_w2o.root',
#'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_nPUgtnPV/METsNoPileUpnPUgtnPV_16_1_07j.root',
#'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_nPUgtnPV/METsNoPileUpnPUgtnPV_17_1_b8k.root',
#'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_nPUgtnPV/METsNoPileUpnPUgtnPV_18_1_SDq.root',
#'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_nPUgtnPV/METsNoPileUpnPUgtnPV_19_1_bV7.root',
#'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_nPUgtnPV/METsNoPileUpnPUgtnPV_1_1_92q.root',
#'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_nPUgtnPV/METsNoPileUpnPUgtnPV_20_1_6ne.root',
#'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_nPUgtnPV/METsNoPileUpnPUgtnPV_21_1_22E.root',
#'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_nPUgtnPV/METsNoPileUpnPUgtnPV_22_1_TBF.root',
#'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_nPUgtnPV/METsNoPileUpnPUgtnPV_23_1_1XD.root',
#'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_nPUgtnPV/METsNoPileUpnPUgtnPV_24_1_t0H.root',
#'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_nPUgtnPV/METsNoPileUpnPUgtnPV_25_1_Jl0.root',
#'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_nPUgtnPV/METsNoPileUpnPUgtnPV_26_1_BBP.root',
#'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_nPUgtnPV/METsNoPileUpnPUgtnPV_2_1_cMJ.root',
#'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_nPUgtnPV/METsNoPileUpnPUgtnPV_3_1_1Uo.root',
#'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_nPUgtnPV/METsNoPileUpnPUgtnPV_4_1_jNw.root',
#'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_nPUgtnPV/METsNoPileUpnPUgtnPV_5_1_EMm.root',
#'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_nPUgtnPV/METsNoPileUpnPUgtnPV_6_1_gE9.root',
#'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_nPUgtnPV/METsNoPileUpnPUgtnPV_7_1_Xyc.root',
#'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_nPUgtnPV/METsNoPileUpnPUgtnPV_8_1_QAT.root',
#'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_nPUgtnPV/METsNoPileUpnPUgtnPV_9_1_nbj.root'

#'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_PUgt0p8/METsNoPileUpfPUgt0p8_10_1_FRO.root',
#'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_PUgt0p8/METsNoPileUpfPUgt0p8_11_1_EFy.root',
#'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_PUgt0p8/METsNoPileUpfPUgt0p8_12_1_Pz1.root',
#'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_PUgt0p8/METsNoPileUpfPUgt0p8_13_1_BRu.root',
#'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_PUgt0p8/METsNoPileUpfPUgt0p8_14_1_IQp.root',
#'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_PUgt0p8/METsNoPileUpfPUgt0p8_15_1_Nbw.root',
#'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_PUgt0p8/METsNoPileUpfPUgt0p8_16_1_NFQ.root',
#'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_PUgt0p8/METsNoPileUpfPUgt0p8_17_1_Vsp.root',
#'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_PUgt0p8/METsNoPileUpfPUgt0p8_18_1_TnJ.root',
#'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_PUgt0p8/METsNoPileUpfPUgt0p8_19_1_MqK.root',
#'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_PUgt0p8/METsNoPileUpfPUgt0p8_1_1_h3h.root',
#'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_PUgt0p8/METsNoPileUpfPUgt0p8_20_1_4Pi.root',
#'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_PUgt0p8/METsNoPileUpfPUgt0p8_21_1_bqm.root',
#'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_PUgt0p8/METsNoPileUpfPUgt0p8_22_1_wjQ.root',
#'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_PUgt0p8/METsNoPileUpfPUgt0p8_23_1_Zw7.root',
#'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_PUgt0p8/METsNoPileUpfPUgt0p8_24_1_L3p.root',
#'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_PUgt0p8/METsNoPileUpfPUgt0p8_25_1_pmn.root',
#'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_PUgt0p8/METsNoPileUpfPUgt0p8_26_1_T4Q.root',
#'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_PUgt0p8/METsNoPileUpfPUgt0p8_2_1_WCH.root',
#'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_PUgt0p8/METsNoPileUpfPUgt0p8_3_1_5pj.root',
#'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_PUgt0p8/METsNoPileUpfPUgt0p8_4_1_mFc.root',
#'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_PUgt0p8/METsNoPileUpfPUgt0p8_5_1_uHf.root',
#'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_PUgt0p8/METsNoPileUpfPUgt0p8_6_1_SkK.root',
#'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_PUgt0p8/METsNoPileUpfPUgt0p8_7_1_1tP.root',
#'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_PUgt0p8/METsNoPileUpfPUgt0p8_8_1_qfs.root',
#'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_PUgt0p8/METsNoPileUpfPUgt0p8_9_1_SxP.root'

##'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_all_genMet/METs_10_1_NpM.root',
##'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_all_genMet/METs_11_1_3Nn.root',
##'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_all_genMet/METs_12_1_mpe.root',
##'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_all_genMet/METs_13_1_V01.root',
##'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_all_genMet/METs_14_1_5N2.root',
##'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_all_genMet/METs_15_1_9Sa.root',
##'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_all_genMet/METs_16_1_Ere.root',
##'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_all_genMet/METs_17_1_GmT.root',
##'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_all_genMet/METs_18_1_QyG.root',
##'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_all_genMet/METs_19_1_GuB.root',
##'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_all_genMet/METs_1_1_P50.root',
##'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_all_genMet/METs_20_1_hUl.root',
##'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_all_genMet/METs_21_1_7OY.root',
##'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_all_genMet/METs_22_1_NNY.root',
##'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_all_genMet/METs_23_1_dBq.root',
##'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_all_genMet/METs_24_1_tjZ.root',
##'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_all_genMet/METs_25_1_JBV.root',
##'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_all_genMet/METs_26_1_mYu.root',
##'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_all_genMet/METs_2_1_GUp.root',
##'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_all_genMet/METs_3_1_eix.root',
##'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_all_genMet/METs_4_1_Mfl.root',
##'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_all_genMet/METs_5_1_pWj.root',
##'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_all_genMet/METs_6_1_ow5.root',
##'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_all_genMet/METs_7_1_M1c.root',
##'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_all_genMet/METs_8_1_QqD.root',
##'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_all_genMet/METs_9_1_Iap.root'

'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_PUgt0p5/METsNoPileUpfPUgt0p5_10_1_Ots.root',
'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_PUgt0p5/METsNoPileUpfPUgt0p5_11_1_nci.root',
'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_PUgt0p5/METsNoPileUpfPUgt0p5_12_1_JBz.root',
'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_PUgt0p5/METsNoPileUpfPUgt0p5_13_1_Gq7.root',
'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_PUgt0p5/METsNoPileUpfPUgt0p5_14_1_FBj.root',
'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_PUgt0p5/METsNoPileUpfPUgt0p5_15_1_CdO.root',
'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_PUgt0p5/METsNoPileUpfPUgt0p5_16_1_UMC.root',
'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_PUgt0p5/METsNoPileUpfPUgt0p5_17_1_ZNu.root',
'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_PUgt0p5/METsNoPileUpfPUgt0p5_18_1_E5U.root',
'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_PUgt0p5/METsNoPileUpfPUgt0p5_19_1_cpN.root',
'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_PUgt0p5/METsNoPileUpfPUgt0p5_1_1_Eg9.root',
'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_PUgt0p5/METsNoPileUpfPUgt0p5_20_1_7od.root',
'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_PUgt0p5/METsNoPileUpfPUgt0p5_21_1_erU.root',
'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_PUgt0p5/METsNoPileUpfPUgt0p5_22_1_h2J.root',
'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_PUgt0p5/METsNoPileUpfPUgt0p5_23_1_xkR.root',
'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_PUgt0p5/METsNoPileUpfPUgt0p5_24_1_LnA.root',
'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_PUgt0p5/METsNoPileUpfPUgt0p5_25_1_oVc.root',
'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_PUgt0p5/METsNoPileUpfPUgt0p5_26_1_s3p.root',
'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_PUgt0p5/METsNoPileUpfPUgt0p5_2_1_vup.root',
'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_PUgt0p5/METsNoPileUpfPUgt0p5_3_1_Hcu.root',
'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_PUgt0p5/METsNoPileUpfPUgt0p5_4_1_hJa.root',
'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_PUgt0p5/METsNoPileUpfPUgt0p5_5_1_4dW.root',
'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_PUgt0p5/METsNoPileUpfPUgt0p5_6_1_2Xi.root',
'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_PUgt0p5/METsNoPileUpfPUgt0p5_7_1_SEv.root',
'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_PUgt0p5/METsNoPileUpfPUgt0p5_8_1_Y8x.root',
'dcache:/pnfs/cms/WAX/resilient/lucieg/MET/QCD_Pt_15to3000_TuneZ2_Flat_7TeV_pythia6_Spring11-PU_S1_START311_V1G1-v1_PUgt0p5/METsNoPileUpfPUgt0p5_9_1_iLf.root'


    )
)

process.load("METsWithPU.METsAnalyzer.mettreeanalyzer_cfi")

#process.analysis.HistOutFile = cms.untracked.string('metTreeNoPVLinkPfMetPileUp.root')
#process.analysis.HistOutFile = cms.untracked.string('metTreeNoPVLinkAl1PU.root')
#process.analysis.HistOutFile = cms.untracked.string('metTreenPUgtnPV.root')
process.analysis.HistOutFile = cms.untracked.string('metTreefPUgt0p5.root')
#process.analysis.HistOutFile = cms.untracked.string('metTreePfNoPileUpNNC.root') 
process.p = cms.Path(process.analysis)


process.load("FWCore.MessageLogger.MessageLogger_cfi")
process.MessageLogger.cerr.FwkReport.reportEvery = 1000
#process.SimpleMemoryCheck = cms.Service("SimpleMemoryCheck",
 #                                       ignoreTotal=cms.untracked.int32(1))


