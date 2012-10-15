import copy
import CMGTools.RootTools.fwlite.Config as cfg

from   CMGTools.H2TauTau.proto.samples.getFiles import getFiles

ana = cfg.Analyzer(
    'AnalysisTreeGenStudy',
    verbose = False,
    listOfBtagsAlgos = [
    'csv_tight',
    'csv_medium',
    'csv_loose',
    'jp_tight',
    'jp_medium',
    'jp_loose',
    ] )

files = getFiles('/SMS-T2tt_FineBin_Mstop-225to1200_mLSP-0to1000_8TeV-Pythia6Z/Summer12-START52_V9_FSIM-v1/AODSIM/V5_B/PAT_CMG_V5_6_0_B/TOP/','lucieg', 'topTuple_.*root')

T2tt = cfg.MCComponent(
    name = 'T2tt',
    files = files,
    xSection = 1., 
    nGenEvents = 1,
    triggers = [],
    effCorrFactor = 1 )




selectedComponents =  [T2tt]

sequence = cfg.Sequence( [
    ana
    ] )

config = cfg.Config( components = selectedComponents,
                     sequence = sequence )

#TTJets.splitFactor = 1
T2tt.splitFactor   = 98

