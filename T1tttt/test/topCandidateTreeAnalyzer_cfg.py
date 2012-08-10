import copy
import CMGTools.RootTools.fwlite.Config as cfg

from   CMGTools.H2TauTau.proto.samples.getFiles import getFiles
files = getFiles('/TTJets_TuneZ2star_8TeV-madgraph-tauola/Summer12-PU_S7_START52_V9-v1/AODSIM/V5/PAT_CMG_V5_4_0_NewType1MET/','cmgtools', 'cmgTuple_.*root')[:1]

ana = cfg.Analyzer(
    'TopCandidateTreeAnalyzer',
    verbose = False,
 #   jetMassParametersFile = 'JetMassAnalyzer300_400/TTJets/JetMassAnalyzer/fitParameters.txt',
 #   jetMassParametersFile = 'JetMassAnalyzer600_700/TTJets/JetMassAnalyzer/fitParameters.txt',
    jetMassParametersFile = 'JetMassAnalyzer900_1000/TTJets/JetMassAnalyzer/fitParameters.txt',
    jetCollections = {
    'aktRecluster1p0Hadronic':0.8,
    },
     listOfBTagsAlgos = [
    'csv_tight',
    'csv_medium',
    'csv_loose',
    'jp_tight',
    'jp_medium',
    'jp_loose',
   ##  'tchp_tight',#forgot this on in cmgtuplization

    ]
    )




##private sample
TTJets = cfg.MCComponent(
    name = 'TTJets',
    files = '/data/lucieg/boostedTops/NoPU/topTupleAllHadronic600_700.root',
    xSection = 1., 
    nGenEvents = 1,
    triggers = [],
    effCorrFactor = 1 )

QCD600_700 = cfg.MCComponent(
    name = 'QCD600_700',
    files = '/data/lucieg/boostedTops/NoPU/topTupleAllHadronic_QCD_600_700.root',
    xSection = 1., 
    nGenEvents = 1,
    triggers = [],
    effCorrFactor = 1 ) 

QCD15_3000 = cfg.MCComponent(
    name = 'QCD15_3000',
    files = '/data/lucieg/boostedTops/NoPU/topTupleAllHadronic_QCD_15_3000.root',
    xSection = 1., 
    nGenEvents = 1,
    triggers = [],
    effCorrFactor = 1 ) 

selectedComponents =  [TTJets, QCD600_700, QCD15_3000]

sequence = cfg.Sequence( [
    ana   
    ] )

config = cfg.Config( components = selectedComponents,
                     sequence = sequence )

TTJets.splitFactor = 1
QCD600_700.splitFactor = 1
QCD15_3000.splitFactor = 1


