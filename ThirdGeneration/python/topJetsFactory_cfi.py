import FWCore.ParameterSet.Config as cms

#convert basic jets to top jets, e.g. basic jets + top tag
weightsfile = "/afs/cern.ch/work/l/lucieg/private/Nov9/CMGTools/CMSSW_5_3_3_patch3/src/Lucie/ThirdGeneration/data/Tagging/weights/TMVAClassificationTagging_Nov12_BDT.weights.xml"

topJets = cms.EDProducer(
    "TopJetFactory",
    fatjets = cms.InputTag("aktRecluster1p75Hadronic"),
    weightsfile = cms.untracked.string( weightsfile )
    )

topJetsAktRecluster1p75 = topJets.clone( fatjets = "aktRecluster1p75Hadronic")
topJetsAktRecluster1p5  = topJets.clone( fatjets = "aktRecluster1p5Hadronic" )
topJetsAktRecluster1p25 = topJets.clone( fatjets = 'aktRecluster1p25Hadronic')
topJetsAktRecluster1p0  = topJets.clone( fatjets = 'aktRecluster1p0Hadronic' )
topJetsAktRecluster0p9  = topJets.clone( fatjets = 'aktRecluster0p9Hadronic' )
topJetsAktRecluster0p8  = topJets.clone( fatjets = 'aktRecluster0p8Hadronic' )
topJetsAktRecluster0p7  = topJets.clone( fatjets = 'aktRecluster0p7Hadronic' )

topJetsCaRecluster1p75  = topJets.clone( fatjets = "aktRecluster1p75Hadronic")
topJetsCaRecluster1p5   = topJets.clone( fatjets = "aktRecluster1p5Hadronic" )
topJetsCaRecluster1p25  = topJets.clone( fatjets = 'aktRecluster1p25Hadronic')
topJetsCaRecluster1p0   = topJets.clone( fatjets = 'aktRecluster1p0Hadronic' )
topJetsCaRecluster0p9   = topJets.clone( fatjets = 'aktRecluster0p9Hadronic' )
topJetsCaRecluster0p8   = topJets.clone( fatjets = 'aktRecluster0p8Hadronic' )
topJetsCaRecluster0p7   = topJets.clone( fatjets = 'aktRecluster0p7Hadronic' )

