import FWCore.ParameterSet.Config as cms

process = cms.Process("ANA")

process.load("FWCore.MessageService.MessageLogger_cfi")

process.source = cms.Source("PoolSource",
                            # replace 'myfile.root',' with the source file you want to use
                         
                            fileNames = cms.untracked.vstring(

#    "/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_0.root",
#"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_1.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_10.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_100.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_101.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_102.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_103.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_104.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_105.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_106.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_107.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_108.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_109.root",
#"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_11.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_110.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_111.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_112.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_113.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_114.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_115.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_116.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_117.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_118.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_119.root",
#"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_12.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_120.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_121.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_122.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_123.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_124.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_125.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_126.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_127.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_128.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_129.root",
#"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_13.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_130.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_131.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_132.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_133.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_134.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_135.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_136.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_137.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_138.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_139.root",
#"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_14.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_15.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_16.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_17.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_18.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_19.root",
#"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_2.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_20.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_21.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_22.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_23.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_24.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_25.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_26.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_27.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_28.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_29.root",
#"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_3.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_30.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_31.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_32.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_33.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_34.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_35.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_36.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_37.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_38.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_39.root",
#"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_4.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_40.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_41.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_42.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_43.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_44.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_45.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_46.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_47.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_48.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_49.root",
#"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_5.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_50.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_51.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_52.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_53.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_54.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_55.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_56.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_57.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_58.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_59.root",
#"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_6.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_60.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_61.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_62.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_63.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_64.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_65.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_66.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_67.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_68.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_69.root",
#"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_7.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_70.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_71.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_72.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_73.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_74.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_75.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_76.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_77.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_78.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_79.root",
#"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_8.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_80.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_81.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_82.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_83.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_84.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_85.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_86.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_87.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_88.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_89.root",
#"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_9.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_90.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_91.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_92.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_93.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_94.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_95.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_96.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_97.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_98.root",
"/store/cmst3/user/lucieg/CMG/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/hltL1Skim_99.root",


    )
    #'/store/cmst3/user/lucieg/CMG/HLT/GCT/SingleMu191718_191810/HLT/hltTestL1Skim_7.root')
                            )

## from CMGTools.Production.datasetToSource import *
## process.source = datasetToSource(
##     'lucieg',
## #    '/HLT/GCTAndHF/ZB191718_191810/HLT/',
##     '/HLT/GCTAndHF/ZB191718_191810/NoHF/HLT/',
## #    '/HLT/GCT/SingleMu191718_191810/HLT/'
## #    '/HLT/GCTAndHF/ZB191718_191810/HLT/HLT/'
## )



process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )

process.load('Lucie.RateAnalyzer.rateanalyzer_cfi')

process.p = cms.Path(
    process.rateanalyzer
    )


process.MessageLogger.cerr.FwkReport.reportEvery = 1000




