import copy
import CMGTools.RootTools.fwlite.Config as cfg

from   CMGTools.H2TauTau.proto.samples.getFiles import getFiles

ana = cfg.Analyzer(
    'Analysis',
    verbose = False,
    listOfTopCandidates = [
    'topCandidatesAkt0p71p75',
    'topCandidatesKt0p71p75',
    'topCandidatesCa0p71p75'
    ],
    listOfBtagsAlgos = [
    'csv_tight',
    'csv_medium',
    'csv_loose',
    'jp_tight',
    'jp_medium',
    'jp_loose',
    ] )



T2tt = cfg.MCComponent(
    name = 'T2tt',
    files = '/data/lucieg/boostedTops/SAMPLES/skim_1.root',
    xSection = 1., 
    nGenEvents = 1,#3675,#after trg
    triggers = [],
    effCorrFactor = 1 )



## TTJets = cfg.MCComponent(
##     name = 'TTJets',
##     #files = filesTTJets,
##     files = ['/data/lucieg/boostedTops/SAMPLES/TTJetsSkimDiJetMET/skim.root'],
##     xSection = 136.3, 
##     nGenEvents = 207,
##     triggers = [],
##     effCorrFactor = 1 )

filesQCD = getFiles('/QCD_HT-1000ToInf_TuneZ2star_8TeV-madgraph-pythia6/Summer12-PU_S7_START52_V9-v1/AODSIM/V5_B/PAT_CMG_V5_6_0_B/TOP/SKIMDiJetMET/','lucieg', 'skim_.*root')

QCDHT1000Inf = cfg.MCComponent(
    name = 'QCDHT1000Inf',
    files = filesQCD,
    #files = ['/data/lucieg/boostedTops/SAMPLES/QCDHighHTSKIMDiJetMET/skim.root'],
    xSection = 204., 
    nGenEvents = 1.,#1535
    triggers = [],
    effCorrFactor = 1 )



selectedComponents =  [T2tt, QCDHT1000Inf]

sequence = cfg.Sequence( [
    ana
    ] )

config = cfg.Config( components = selectedComponents,
                     sequence = sequence )

#TTJets.splitFactor = 1
T2tt.splitFactor   = 1
QCDHT1000Inf.splitFactor = 56

