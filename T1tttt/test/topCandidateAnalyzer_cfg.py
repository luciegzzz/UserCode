import copy
import CMGTools.RootTools.fwlite.Config as cfg

from   CMGTools.H2TauTau.proto.samples.getFiles import getFiles
files = getFiles('/TTJets_TuneZ2star_8TeV-madgraph-tauola/Summer12-PU_S7_START52_V9-v1/AODSIM/V5/PAT_CMG_V5_4_0_NewType1MET/','cmgtools', 'cmgTuple_.*root')[:1]

ana = cfg.Analyzer(
    'TopCandidateAnalyzer',
    verbose = False,
   # jetMassParametersFile = 'JetMassAnalyzer300_400/TTJets/JetMassAnalyzer/fitParameters.txt',
    jetMassParametersFile = 'JetMassAnalyzer600_700/TTJets/JetMassAnalyzer/fitParameters.txt',
   # jetMassParametersFile = 'JetMassAnalyzer900_1000/TTJets/JetMassAnalyzer/fitParameters.txt',
    jetCollections = {
    'aktRecluster0p7Hadronic':0.7,
    'aktRecluster0p8Hadronic':0.8,
    'aktRecluster0p9Hadronic':0.9,
    'aktRecluster1p0Hadronic':1.0,
    'aktRecluster1p25Hadronic':1.25,
    'aktRecluster1p5Hadronic':1.5,
    'aktRecluster1p75Hadronic':1.75,
    'aktRecluster2p0Hadronic':2.0,
    'aktRecluster3p0Hadronic':3.0,
    'ktRecluster0p7Hadronic':0.7,
    'ktRecluster0p8Hadronic':0.8,
    'ktRecluster0p9Hadronic':0.9,
    'ktRecluster1p0Hadronic':1.0,
    'ktRecluster1p25Hadronic':1.25,
    'ktRecluster1p5Hadronic':1.5,
    'ktRecluster1p75Hadronic':1.75,
    'ktRecluster2p0Hadronic':2.0,
    'ktRecluster3p0Hadronic':3.0,
    'caRecluster0p7Hadronic':0.7,
    'caRecluster0p8Hadronic':0.8,
    'caRecluster0p9Hadronic':0.9,
    'caRecluster1p0Hadronic':1.0,
    'caRecluster1p25Hadronic':1.25,
    'caRecluster1p5Hadronic':1.5,
    'caRecluster1p75Hadronic':1.75,
    'caRecluster2p0Hadronic':2.0,
    'caRecluster3p0Hadronic':3.0
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
BoostedTTJets = cfg.MCComponent(
    name = 'TTJets',
    # files = '/data/lucieg/boostedTops/NoPU/topTupleAllHadronic300_400.root',
    #  files = '/data/lucieg/boostedTops/NoPU/topTupleAllHadronic600_700.root',
    #  files = '/data/lucieg/boostedTops/NoPU/topTupleAllHadronic900_1000.root',
     files = '/data/lucieg/boostedTops/NoPU/topTupleAllHadronic_QCD_15_3000.root',
    #  files = '/data/lucieg/boostedTops/NoPU/topTupleAllHadronic_QCD_600_700.root',
    #  files = '/data/lucieg/boostedTops/NoPU/topTupleAllHadronic_QCD_900_1000.root',
 
    xSection = 1., 
    nGenEvents = 1,
    triggers = [],
    effCorrFactor = 1 )

selectedComponents =  [BoostedTTJets]

sequence = cfg.Sequence( [
    ana
    ] )

config = cfg.Config( components = selectedComponents,
                     sequence = sequence )

BoostedTTJets.splitFactor = 1


