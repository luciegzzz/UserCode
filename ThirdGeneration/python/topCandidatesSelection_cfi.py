import FWCore.ParameterSet.Config as cms

#select "best candidates" collection by collection
topCandidates = cms.EDFilter("TopJetSelector",
    src = cms.InputTag('topJetsAktRecluster1p75'),
    cut = cms.string('topTag() > 0.')
    )

topCandidatesAktRecluster1p75 = topCandidates.clone( src = cms.InputTag('topJetsAktRecluster1p75', 'topCandidates', 'TOP'))
topCandidatesAktRecluster1p5  = topCandidates.clone( src = cms.InputTag('topJetsAktRecluster1p5' , 'topCandidates', 'TOP'))
topCandidatesAktRecluster1p25 = topCandidates.clone( src = cms.InputTag('topJetsAktRecluster1p25', 'topCandidates', 'TOP'))
topCandidatesAktRecluster1p0  = topCandidates.clone( src = cms.InputTag('topJetsAktRecluster1p0' , 'topCandidates', 'TOP'))
topCandidatesAktRecluster0p9  = topCandidates.clone( src = cms.InputTag('topJetsAktRecluster0p9' , 'topCandidates', 'TOP'))
topCandidatesAktRecluster0p8  = topCandidates.clone( src = cms.InputTag('topJetsAktRecluster0p8' , 'topCandidates', 'TOP'))
topCandidatesAktRecluster0p7  = topCandidates.clone( src = cms.InputTag('topJetsAktRecluster0p7' , 'topCandidates', 'TOP'))

topCandidatesCaRecluster1p75  = topCandidates.clone( src = cms.InputTag('topJetsCaRecluster1p75' , 'topCandidates', 'TOP'))
topCandidatesCaRecluster1p5   = topCandidates.clone( src = cms.InputTag('topJetsCaRecluster1p5'  , 'topCandidates', 'TOP'))
topCandidatesCaRecluster1p25  = topCandidates.clone( src = cms.InputTag('topJetsCaRecluster1p25' , 'topCandidates', 'TOP'))
topCandidatesCaRecluster1p0   = topCandidates.clone( src = cms.InputTag('topJetsCaRecluster1p0'  , 'topCandidates', 'TOP'))
topCandidatesCaRecluster0p9   = topCandidates.clone( src = cms.InputTag('topJetsCaRecluster0p9'  , 'topCandidates', 'TOP'))
topCandidatesCaRecluster0p8   = topCandidates.clone( src = cms.InputTag('topJetsCaRecluster0p8'  , 'topCandidates', 'TOP'))
topCandidatesCaRecluster0p7   = topCandidates.clone( src = cms.InputTag('topJetsCaRecluster0p7'  , 'topCandidates', 'TOP'))

