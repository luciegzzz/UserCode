import FWCore.ParameterSet.Config as cms

from CMGTools.Common.skims.cmgDiMuonSel_cfi import cmgDiMuonSel
from CMGTools.Common.skims.cmgDiMuonCount_cfi import cmgDiMuonCount

Zevents     = cmgDiMuonSel.clone()
Zevents.src = cms.InputTag('cmgDiMuonSel')
Zevents.cut = cms.string( "mass() > 80. && mass() < 100. && leg1().pt() > 20. && leg2().pt() > 10. && leg1().relIso() < 0.2 && leg2().relIso() < 0.2 ")

ZeventsCount = cmgDiMuonCount.clone ( minNumber = 1,
                                       src = 'Zevents')


selectZevents = cms.Sequence(
    Zevents +
    ZeventsCount
    )

