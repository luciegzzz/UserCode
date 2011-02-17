
import FWCore.ParameterSet.Config as cms

process = cms.Process("PLOT")

process.maxEvents = cms.untracked.PSet( input = cms.untracked.int32(-1) )

process.source = cms.Source("PoolSource",
    fileNames = cms.untracked.vstring(
#    'file:/uscms/home/gerstein/lpcgg/cmsdas/fsim_1TeV_Wprime-Mpp150.root'
#    'file:/uscms/home/gerstein/lpcgg/cmsdas/fsim_1TeV_Wprime-Mpp175.root'
#    'file:/uscms/home/gerstein/lpcgg/cmsdas/fsim_1TeV_Wprime-Mpp200.root'
#    'file:/uscms/home/gerstein/lpcgg/cmsdas/fsim_1TeV_Wprime-Mpp225.root'
#    'file:/uscms/home/marat/lpcegm/out_forcmsdas_wpu_2keach/condor_dir0/3gamma_backgd_yuri_afterfastsim_testfake.root'    
#    'file:/uscms/home/marat/lpcegm/out_forcmsdas_wpu_2keach/condor_dir1/multiphoton-Mpp150_afterfastsim_testfake.root'
#    'file:/uscms/home/marat/lpcegm/out_forcmsdas_wpu_2keach/condor_dir2/multiphoton-Mpp175_afterfastsim_testfake.root'
#    'file:/uscms/home/marat/lpcegm/out_forcmsdas_wpu_2keach/condor_dir3/multiphoton-Mpp200_afterfastsim_testfake.root'
#    'file:/uscms/home/marat/lpcegm/out_forcmsdas_wpu_2keach/condor_dir4/multiphoton-Mpp225_afterfastsim_testfake.root'
#    'file:/uscms/home/marat/lpcegm/out_forcmsdas_wpu_2keach/condor_dir5/multiphoton-Mpp250_afterfastsim_testfake.root'
#    'file:/uscms/home/marat/lpcegm/out_forcmsdas_wpu_2keach/condor_dir6/multiphoton_with_Wprime-Mpp150_afterfastsim_testfake.root'
#    'file:/uscms/home/marat/lpcegm/out_forcmsdas_wpu_2keach/condor_dir7/multiphoton_with_Wprime-Mpp175_afterfastsim_testfake.root'
#    'file:/uscms/home/marat/lpcegm/out_forcmsdas_wpu_2keach/condor_dir8/multiphoton_with_Wprime-Mpp200_afterfastsim_testfake.root'
#    'file:/uscms/home/marat/lpcegm/out_forcmsdas_wpu_2keach/condor_dir9/multiphoton_with_Wprime-Mpp225_afterfastsim_testfake.root'
    'file:/uscms/home/marat/lpcegm/out_forcmsdas_wpu_2keach/condor_dir10/multiphoton_with_Wprime-Mpp250_afterfastsim_testfake.root'

    )
)
## process.options = cms.untracked.PSet(
##   fileMode = cms.untracked.string('NOMERGE')
## )
process.analyzer = cms.EDAnalyzer('PhotonPlots',
                                  HistOutFile = cms.untracked.string('PhotonPlotsMCWprime-Mpp250.root')
                                  )



process.p = cms.Path(process.analyzer)

process.load("FWCore.MessageLogger.MessageLogger_cfi")
process.MessageLogger.cerr.FwkReport.reportEvery = 1
