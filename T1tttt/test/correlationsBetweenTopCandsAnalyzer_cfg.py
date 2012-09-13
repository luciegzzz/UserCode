import copy
import CMGTools.RootTools.fwlite.Config as cfg

from   CMGTools.H2TauTau.proto.samples.getFiles import getFiles

ana = cfg.Analyzer(
    'CorrelationsBetweenTopCandsAnalyzer',
    verbose = False,
        jetCollections = {
    'topCandidatesAktRecluster0p7':0.7,
    'topCandidatesAktRecluster0p8':0.8,
    'topCandidatesAktRecluster0p9':0.9,
    'topCandidatesAktRecluster1p0':1.0,
    'topCandidatesAktRecluster1p25':1.25,
    'topCandidatesAktRecluster1p5':1.5,
    'topCandidatesAktRecluster1p75':1.75,
    'topCandidatesAktRecluster2p0':2.0,
    'topCandidatesAktRecluster3p0':3.0,
  ##   'ktRecluster0p7':0.7,
##     'ktRecluster0p8':0.8,
##     'ktRecluster0p9':0.9,
##     'ktRecluster1p0':1.0,
##     'ktRecluster1p25':1.25,
##     'ktRecluster1p5':1.5,
##     'ktRecluster1p75':1.75,
##     'ktRecluster2p0':2.0,
##     'ktRecluster3p0':3.0,
##     'caRecluster0p7':0.7,
##     'caRecluster0p8':0.8,
##     'caRecluster0p9':0.9,
##     'caRecluster1p0':1.0,
##     'caRecluster1p25':1.25,
##     'caRecluster1p5':1.5,
##     'caRecluster1p75':1.75,
##     'caRecluster2p0':2.0,
##     'caRecluster3p0':3.0
    },

    )


files = getFiles('/T2tt/TEST/TopTuple/','lucieg', 'topTupleAllHadronic_.*root')[:1]

T2tt = cfg.MCComponent(
    name = 'T2tt',
#    files = files,
    files = '/data/lucieg/boostedTops/NoPU/533/skim_topTupleAllHadronic_T2tt_FatJetsFromGen.root',
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

T2tt.splitFactor = 1



