import FWCore.ParameterSet.Config as cms

#from CMGTools.Common.skims.cmgPFJetSel_cfi import cmgPFJetSel

topCandidates = cms.EDFilter("BasicJetSelector",
    src = cms.InputTag('aktRecluster3p0Hadronic'),
    cut = cms.string('mass() > 130 && mass() < 220')
    )

topCandidatesAktRecluster3p0  = topCandidates.clone( src = 'aktRecluster3p0Hadronic')
topCandidatesAktRecluster2p0  = topCandidates.clone( src = 'aktRecluster2p0Hadronic')
topCandidatesAktRecluster1p75 = topCandidates.clone( src = 'aktRecluster1p75Hadronic')
topCandidatesAktRecluster1p5  = topCandidates.clone( src = 'aktRecluster1p5Hadronic')
topCandidatesAktRecluster1p25 = topCandidates.clone( src = 'aktRecluster1p25Hadronic')
topCandidatesAktRecluster1p0  = topCandidates.clone( src = 'aktRecluster1p0Hadronic')
topCandidatesAktRecluster0p9  = topCandidates.clone( src = 'aktRecluster0p9Hadronic')
topCandidatesAktRecluster0p8  = topCandidates.clone( src = 'aktRecluster0p8Hadronic')
topCandidatesAktRecluster0p7  = topCandidates.clone( src = 'aktRecluster0p7Hadronic')

topCandidatesCaRecluster3p0  = topCandidates.clone( src = 'caRecluster3p0Hadronic')
topCandidatesCaRecluster2p0  = topCandidates.clone( src = 'caRecluster2p0Hadronic')
topCandidatesCaRecluster1p75 = topCandidates.clone( src = 'caRecluster1p75Hadronic')
topCandidatesCaRecluster1p5  = topCandidates.clone( src = 'caRecluster1p5Hadronic')
topCandidatesCaRecluster1p25 = topCandidates.clone( src = 'caRecluster1p25Hadronic')
topCandidatesCaRecluster1p0  = topCandidates.clone( src = 'caRecluster1p0Hadronic')
topCandidatesCaRecluster0p9  = topCandidates.clone( src = 'caRecluster0p9Hadronic')
topCandidatesCaRecluster0p8  = topCandidates.clone( src = 'caRecluster0p8Hadronic')
topCandidatesCaRecluster0p7  = topCandidates.clone( src = 'caRecluster0p7Hadronic')

topCandidatesKtRecluster3p0  = topCandidates.clone( src = 'ktRecluster3p0Hadronic')
topCandidatesKtRecluster2p0  = topCandidates.clone( src = 'ktRecluster2p0Hadronic')
topCandidatesKtRecluster1p75 = topCandidates.clone( src = 'ktRecluster1p75Hadronic')
topCandidatesKtRecluster1p5  = topCandidates.clone( src = 'ktRecluster1p5Hadronic')
topCandidatesKtRecluster1p25 = topCandidates.clone( src = 'ktRecluster1p25Hadronic')
topCandidatesKtRecluster1p0  = topCandidates.clone( src = 'ktRecluster1p0Hadronic')
topCandidatesKtRecluster0p9  = topCandidates.clone( src = 'ktRecluster0p9Hadronic')
topCandidatesKtRecluster0p8  = topCandidates.clone( src = 'ktRecluster0p8Hadronic')
topCandidatesKtRecluster0p7  = topCandidates.clone( src = 'ktRecluster0p7Hadronic')




skimmingTopTupleSequence = cms.Sequence(
    #topCandidatesAktRecluster3p0  +
    #topCandidatesAktRecluster2p0  +
    topCandidatesAktRecluster1p75 +
    topCandidatesAktRecluster1p5  +
    topCandidatesAktRecluster1p25 +
    topCandidatesAktRecluster1p0  +
    topCandidatesAktRecluster0p9  +
    topCandidatesAktRecluster0p8  +
    topCandidatesAktRecluster0p7  +
    #topCandidatesKtRecluster3p0   +
    #topCandidatesKtRecluster2p0   +
    topCandidatesKtRecluster1p75  +
    topCandidatesKtRecluster1p5   +
    topCandidatesKtRecluster1p25  +
    topCandidatesKtRecluster1p0   +
    topCandidatesKtRecluster0p9   +
    topCandidatesKtRecluster0p8   +
    topCandidatesKtRecluster0p7   +
    #topCandidatesCaRecluster3p0   +
    #topCandidatesCaRecluster2p0   +
    topCandidatesCaRecluster1p75  +
    topCandidatesCaRecluster1p5   +
    topCandidatesCaRecluster1p25  +
    topCandidatesCaRecluster1p0   +
    topCandidatesCaRecluster0p9   +
    topCandidatesCaRecluster0p8   +
    topCandidatesCaRecluster0p7  
    )
