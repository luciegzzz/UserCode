import FWCore.ParameterSet.Config as cms

source = cms.Source("PoolSource",
                    fileNames = cms.untracked.vstring(
##       ##PU 0##
##     'rfio:/castor/cern.ch/user/l/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_0_10_1_ySn.root',
##     'rfio:/castor/cern.ch/user/l/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_0_1_1_g3c.root',
##     'rfio:/castor/cern.ch/user/l/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_0_2_1_vlI.root',
##     'rfio:/castor/cern.ch/user/l/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_0_3_1_8sb.root',
##     'rfio:/castor/cern.ch/user/l/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_0_4_1_MSD.root',
##     'rfio:/castor/cern.ch/user/l/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_0_5_1_bOC.root',
##     'rfio:/castor/cern.ch/user/l/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_0_6_1_jSp.root',
##     'rfio:/castor/cern.ch/user/l/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_0_7_1_XYX.root',
##     'rfio:/castor/cern.ch/user/l/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_0_8_1_0RS.root',
##     'rfio:/castor/cern.ch/user/l/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_0_9_1_BUd.root'#,
 ##     ##PU 5##
##     'rfio:/castor/cern.ch/user/l/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_5_10_1_ZR3.root',
##     'rfio:/castor/cern.ch/user/l/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_5_1_1_5XM.root',
##     'rfio:/castor/cern.ch/user/l/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_5_2_1_Ev7.root',
##     'rfio:/castor/cern.ch/user/l/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_5_3_1_Pyj.root',
##     'rfio:/castor/cern.ch/user/l/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_5_4_1_Pig.root',
##     'rfio:/castor/cern.ch/user/l/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_5_5_1_262.root',
##     'rfio:/castor/cern.ch/user/l/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_5_6_1_2bR.root',
##     'rfio:/castor/cern.ch/user/l/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_5_7_1_o4R.root',
##     'rfio:/castor/cern.ch/user/l/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_5_8_1_wl0.root',
##     'rfio:/castor/cern.ch/user/l/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_5_9_1_gME.root'
##     ##PU 10##
##     'rfio:/castor/cern.ch/user/l/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_10_10_1_f7A.root',
##     'rfio:/castor/cern.ch/user/l/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_10_1_1_FgJ.root',
##     'rfio:/castor/cern.ch/user/l/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_10_2_1_Lpz.root',
##     'rfio:/castor/cern.ch/user/l/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_10_3_1_cYk.root',
##     'rfio:/castor/cern.ch/user/l/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_10_4_1_uFi.root',
##     'rfio:/castor/cern.ch/user/l/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_10_5_1_aMx.root',
##     'rfio:/castor/cern.ch/user/l/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_10_6_1_2z4.root',
##     'rfio:/castor/cern.ch/user/l/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_10_7_1_P14.root',
##     'rfio:/castor/cern.ch/user/l/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_10_8_1_KPz.root',
##     'rfio:/castor/cern.ch/user/l/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_10_9_1_UV3.root'#,
##     ##PU 15##
##     'rfio:/castor/cern.ch/user/l/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_15_10_1_IbO.root',
##     'rfio:/castor/cern.ch/user/l/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_15_1_1_WKy.root',
##     'rfio:/castor/cern.ch/user/l/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_15_2_1_WxX.root',
##     'rfio:/castor/cern.ch/user/l/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_15_3_1_uNp.root',
##     'rfio:/castor/cern.ch/user/l/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_15_4_1_OXW.root',
##     'rfio:/castor/cern.ch/user/l/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_15_5_1_7Hr.root',
##     'rfio:/castor/cern.ch/user/l/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_15_6_1_4eI.root',
##     'rfio:/castor/cern.ch/user/l/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_15_7_1_9OR.root',
##     'rfio:/castor/cern.ch/user/l/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_15_8_1_8r5.root',
##     'rfio:/castor/cern.ch/user/l/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_15_9_1_IPA.root'#,
##     ##PU 20##
##     'rfio:/castor/cern.ch/user/l/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_20_10_1_RzB.root',
##     'rfio:/castor/cern.ch/user/l/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_20_1_1_Tuq.root',
##     'rfio:/castor/cern.ch/user/l/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_20_2_1_Vpe.root',
##     'rfio:/castor/cern.ch/user/l/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_20_3_1_6hq.root',
##     'rfio:/castor/cern.ch/user/l/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_20_4_1_rUh.root',
##     'rfio:/castor/cern.ch/user/l/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_20_5_1_go9.root',
##     'rfio:/castor/cern.ch/user/l/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_20_6_1_MK7.root',
##     'rfio:/castor/cern.ch/user/l/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_20_7_1_PQL.root',
##     'rfio:/castor/cern.ch/user/l/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_20_8_1_KRr.root',
##     'rfio:/castor/cern.ch/user/l/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_20_9_1_51H.root'#,
## #
    #     ##PU 25##
    'rfio:/castor/cern.ch/user/l/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_25_10_1_KtF.root',
    'rfio:/castor/cern.ch/user/l/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_25_1_1_CDs.root',
    'rfio:/castor/cern.ch/user/l/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_25_2_1_lMt.root',
    'rfio:/castor/cern.ch/user/l/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_25_3_1_u4f.root',
    'rfio:/castor/cern.ch/user/l/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_25_4_1_k0F.root',
    'rfio:/castor/cern.ch/user/l/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_25_5_1_8zW.root',
    'rfio:/castor/cern.ch/user/l/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_25_6_1_dyY.root',
    'rfio:/castor/cern.ch/user/l/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_25_7_1_gqh.root',
    'rfio:/castor/cern.ch/user/l/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_25_8_1_omY.root',
    'rfio:/castor/cern.ch/user/l/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_25_9_1_zRZ.root'#,
   
    
     )
                    )
