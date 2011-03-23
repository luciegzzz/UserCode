import FWCore.ParameterSet.Config as cms

source = cms.Source("PoolSource",
                    fileNames = cms.untracked.vstring(
'dcache:/pnfs/cms/WAX/resilient/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_0_10_1_5gR.root',
'dcache:/pnfs/cms/WAX/resilient/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_0_1_1_6vx.root',
'dcache:/pnfs/cms/WAX/resilient/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_0_2_1_H2a.root',
'dcache:/pnfs/cms/WAX/resilient/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_0_3_1_2ZF.root',
'dcache:/pnfs/cms/WAX/resilient/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_0_4_1_tMd.root',
'dcache:/pnfs/cms/WAX/resilient/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_0_5_1_9Gs.root',
'dcache:/pnfs/cms/WAX/resilient/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_0_6_1_Xvg.root',
'dcache:/pnfs/cms/WAX/resilient/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_0_7_1_FnW.root',
'dcache:/pnfs/cms/WAX/resilient/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_0_8_1_dTW.root',
'dcache:/pnfs/cms/WAX/resilient/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_0_9_1_Cfl.root',
'dcache:/pnfs/cms/WAX/resilient/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_10_10_1_C1c.root',
'dcache:/pnfs/cms/WAX/resilient/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_10_1_1_yBP.root',
'dcache:/pnfs/cms/WAX/resilient/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_10_2_1_BLF.root',
'dcache:/pnfs/cms/WAX/resilient/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_10_3_1_Ltc.root',
'dcache:/pnfs/cms/WAX/resilient/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_10_4_1_nGX.root',
'dcache:/pnfs/cms/WAX/resilient/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_10_5_1_Dzj.root',
'dcache:/pnfs/cms/WAX/resilient/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_10_6_1_fLe.root',
'dcache:/pnfs/cms/WAX/resilient/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_10_7_1_ywV.root',
'dcache:/pnfs/cms/WAX/resilient/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_10_8_1_W3g.root',
'dcache:/pnfs/cms/WAX/resilient/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_10_9_1_zPw.root',
'dcache:/pnfs/cms/WAX/resilient/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_15_10_1_HHJ.root',
'dcache:/pnfs/cms/WAX/resilient/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_15_1_1_1Yz.root',
'dcache:/pnfs/cms/WAX/resilient/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_15_2_1_YUg.root',
'dcache:/pnfs/cms/WAX/resilient/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_15_3_1_dQJ.root',
'dcache:/pnfs/cms/WAX/resilient/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_15_4_1_puB.root',
'dcache:/pnfs/cms/WAX/resilient/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_15_5_1_zcB.root',
'dcache:/pnfs/cms/WAX/resilient/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_15_6_1_Q2b.root',
'dcache:/pnfs/cms/WAX/resilient/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_15_7_1_Vpx.root',
'dcache:/pnfs/cms/WAX/resilient/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_15_8_1_XOt.root',
'dcache:/pnfs/cms/WAX/resilient/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_15_9_1_3Is.root',
'dcache:/pnfs/cms/WAX/resilient/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_20_10_1_QC2.root',
'dcache:/pnfs/cms/WAX/resilient/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_20_1_1_Qi9.root',
'dcache:/pnfs/cms/WAX/resilient/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_20_2_1_SX9.root',
'dcache:/pnfs/cms/WAX/resilient/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_20_3_1_Qvy.root',
'dcache:/pnfs/cms/WAX/resilient/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_20_4_1_ghL.root',
'dcache:/pnfs/cms/WAX/resilient/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_20_5_1_RKF.root',
'dcache:/pnfs/cms/WAX/resilient/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_20_6_1_adr.root',
'dcache:/pnfs/cms/WAX/resilient/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_20_7_1_y3s.root',
'dcache:/pnfs/cms/WAX/resilient/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_20_8_1_xR5.root',
'dcache:/pnfs/cms/WAX/resilient/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_20_9_1_d1V.root',
'dcache:/pnfs/cms/WAX/resilient/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_25_10_1_Hlo.root',
'dcache:/pnfs/cms/WAX/resilient/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_25_1_1_QW7.root',
'dcache:/pnfs/cms/WAX/resilient/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_25_2_1_uqY.root',
'dcache:/pnfs/cms/WAX/resilient/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_25_3_1_MHs.root',
'dcache:/pnfs/cms/WAX/resilient/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_25_4_1_YxB.root',
'dcache:/pnfs/cms/WAX/resilient/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_25_5_1_cnZ.root',
'dcache:/pnfs/cms/WAX/resilient/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_25_6_1_fXa.root',
'dcache:/pnfs/cms/WAX/resilient/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_25_7_1_yV5.root',
'dcache:/pnfs/cms/WAX/resilient/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_25_8_1_tmz.root',
'dcache:/pnfs/cms/WAX/resilient/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_25_9_1_gxu.root',
'dcache:/pnfs/cms/WAX/resilient/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_5_10_1_gWf.root',
'dcache:/pnfs/cms/WAX/resilient/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_5_1_1_LTC.root',
'dcache:/pnfs/cms/WAX/resilient/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_5_2_1_aeh.root',
'dcache:/pnfs/cms/WAX/resilient/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_5_3_1_lBT.root',
'dcache:/pnfs/cms/WAX/resilient/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_5_4_1_zAX.root',
'dcache:/pnfs/cms/WAX/resilient/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_5_5_1_bgF.root',
'dcache:/pnfs/cms/WAX/resilient/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_5_6_1_wD3.root',
'dcache:/pnfs/cms/WAX/resilient/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_5_7_1_LiG.root',
'dcache:/pnfs/cms/WAX/resilient/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_5_8_1_qDz.root',
'dcache:/pnfs/cms/WAX/resilient/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_5_9_1_1NW.root'

    )
                    )
