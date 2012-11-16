import FWCore.ParameterSet.Config as cms

from CMGTools.Common.skims.cmgPFJetSel_cfi import cmgPFJetSel
from CMGTools.Common.skims.cmgCandCount_cfi import cmgCandCount
#####Jet Selection
cmgPFJetSelPt       = cmgPFJetSel.clone(
    src = 'cmgPFJetSel',
    cut = 'pt > 80. && abs(eta)<2.4')

cmgPFJetSelQuadJet  = cmgCandCount.clone(
    src = 'cmgPFJetSelPt',
    minNumber = 4
    )

cmgPFJetSelDiJet  = cmgCandCount.clone(
    src = 'cmgPFJetSelPt',
    minNumber = 2
    )
######MET selection
cmgPFMETSelPt       = cms.EDFilter(
    "CandViewSelector",
    src = cms.InputTag("cmgPFMET"),
    cut = cms.string( "pt()>200." )
    )

cmgPFMETSelCut      = cmgCandCount.clone(
    src = 'cmgPFMETSelPt',
    minNumber = 1
    )

skimmingTopTupleTrgSequence = cms.Sequence(
    cmgPFJetSelPt +
 ##   cmgPFJetSelQuadJet

    cmgPFJetSelDiJet +
    cmgPFMETSelPt +
    cmgPFMETSelCut
    )
