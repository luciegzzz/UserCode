import copy
import CMGTools.RootTools.fwlite.Config as cfg

from   CMGTools.H2TauTau.proto.samples.getFiles import getFiles
#files = getFiles('/T2tt/TEST/TopTuple/','lucieg', 'topTupleAllHadronic_.*root')[:1]
#files = getFiles('/T2tt/TEST/TopTuple/','lucieg', 'topTupleAllHadronicPUIDFullMedium_.*root')[:1]
#files = getFiles('/T2tt/TEST/TopTuple/','lucieg', 'topTupleAllHadronicPUIDSimpleMedium_.*root')[:1]
#files = getFiles('/T2tt/TEST/TopTuple/','lucieg', 'topTupleAllHadronicMatchingToGenJets_.*root')[:1]


ana = cfg.Analyzer(
    'TopCandidateAnalyzer',
    verbose = False,
    jetMassParametersFile = 'JetMassAnalyzerT2tt/T2tt_1/JetMassAnalyzer/fitParameters.txt',
   # jetMassParametersFile = 'JetMassAnalyzer300_400/TTJets/JetMassAnalyzer/fitParameters.txt',
   # jetMassParametersFile = 'JetMassAnalyzer600_700/TTJets/JetMassAnalyzer/fitParameters.txt',
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
T2tt = cfg.MCComponent(
    name = 'T2tt',
    files = files,
#    files = '/data/lucieg/boostedTops/topTupleAllHadronic300_400.root',
    xSection = 1., 
    nGenEvents = 1,
    triggers = [],
    effCorrFactor = 1 )

## T2ttPUID = cfg.MCComponent(
##     name = 'T2ttPUID',
##     files = files2,
##     xSection = 1., 
##     nGenEvents = 1,
##     triggers = [],
##     effCorrFactor = 1 )

TTJets = cfg.MCComponent(
    name = 'TTJets',
    files = '/data/lucieg/boostedTops/NoPU/topTupleAllHadronic_300_400.root',
    #  files = '/data/lucieg/boostedTops/NoPU/topTupleAllHadronic600_700.root',
    #  files = '/data/lucieg/boostedTops/NoPU/topTupleAllHadronic900_1000.root',
    # files = '/data/lucieg/boostedTops/NoPU/topTupleAllHadronic_QCD_15_3000.root',
    #  files = '/data/lucieg/boostedTops/NoPU/topTupleAllHadronic_QCD_600_700.root',
    #  files = '/data/lucieg/boostedTops/NoPU/topTupleAllHadronic_QCD_900_1000.root',
    xSection = 1., 
    nGenEvents = 1,
    triggers = [],
    effCorrFactor = 1 )


selectedComponents =  [T2tt, TTJets]

sequence = cfg.Sequence( [
    ana
    ] )

config = cfg.Config( components = selectedComponents,
                     sequence = sequence )

T2tt.splitFactor = 1
TTJets.splitFactor = 1


