import copy
import CMGTools.RootTools.fwlite.Config as cfg

from   CMGTools.H2TauTau.proto.samples.getFiles import getFiles

ana = cfg.Analyzer(
    'MergedTopCandidateAnalyzer',
    verbose = False,
        listOfTopCandidates = [
    'buildTopCandidatesAkt0p71p75',
    'buildTopCandidatesKt0p71p75',
    'buildTopCandidatesCa0p71p75'
    ]
    )


#files = getFiles('/T2tt/TEST/TopTuple/','lucieg', 'topTupleAllHadronic_.*root')[:1]

T2tt = cfg.MCComponent(
    name = 'T2tt',
#    files = files,
    files = '/data/lucieg/boostedTops/NoPU/533/topTupleAllHadronic_T2tt.root',
    xSection = 1., 
    nGenEvents = 1,
    triggers = [],
    effCorrFactor = 1 )


#TTJets = 

selectedComponents =  [T2tt]

sequence = cfg.Sequence( [
    ana
    ] )

config = cfg.Config( components = selectedComponents,
                     sequence = sequence )

T2tt.splitFactor = 1



