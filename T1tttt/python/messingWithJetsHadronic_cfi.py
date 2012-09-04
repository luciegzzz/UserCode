import FWCore.ParameterSet.Config as cms

from RecoJets.JetProducers.ak5PFJets_cfi import *
from RecoJets.JetProducers.kt4PFJets_cfi import *
from RecoJets.JetProducers.ca4PFJets_cfi import *


from CMGTools.Common.skims.cmgPFJetSel_cfi import cmgPFJetSel


##################################
#####def input jet collection ####
##################################

#########playing with PU ID
cmgPFJetSelCHSNoPU = cmgPFJetSel.clone(
    src = 'cmgPFJetSelCHS',
    cut = 'puId("simple") > 5'#'puId("full") > 5'#passPuJetId("full", PileupJetIdentifier::kMedium )' #does not work
    )

#########playing with gen jet matching
#produce a collection of jets NOT matched to gen jet
deltaRJetGenJet = cms.EDProducer(
    "DeltaRVetoProducerPFJet",
    inputCollection = cms.InputTag('cmgPFJetSelCHS'),
    MatchingParams = cms.VPSet(
    cms.PSet(                                     
    vetoCollection=cms.InputTag("genJetSel"),
    minDeltaR=cms.double(0.4),
    removeMatchedObject=cms.bool(True)
    )
    ),
    verbose = cms.untracked.bool(False)
    )

#extract the collection of jets matched to gen jets
cmgPFJetSelCHSMatchedToGen = cms.EDProducer(
    "TPCMGPFJetOnPFJet",
    enable = cms.bool(True),
    verbose =  cms.untracked.bool( False ),
    name = cms.untracked.string("cmgPFJetSelCHSMatchedToGen"),
    topCollection = cms.InputTag("deltaRJetGenJet"),
    bottomCollection = cms.InputTag("cmgPFJetSelCHS"),
    )

inputJetCollection = 'cmgPFJetSelCHS' 
#inputJetCollection = 'cmgPFJetSelCHSNoPU' 
#inputJetCollection = 'cmgPFJetSelCHSMatchedToGen' 
###############
### anti kt ###
###############

##jets from jets
aktRecluster1p0Hadronic          = ak5PFJets.clone()
aktRecluster1p0Hadronic.src      = inputJetCollection
aktRecluster1p0Hadronic.jetPtMin = cms.double(10.0)
aktRecluster1p0Hadronic.rParam   = cms.double(1.0)
aktRecluster1p0Hadronic.jetType  = 'BasicJet'

aktRecluster3p0Hadronic          = aktRecluster1p0Hadronic.clone()
aktRecluster3p0Hadronic.rParam   = cms.double(3.0)

aktRecluster2p0Hadronic          = aktRecluster1p0Hadronic.clone()
aktRecluster2p0Hadronic.rParam   = cms.double(2.0)

aktRecluster1p75Hadronic          = aktRecluster1p0Hadronic.clone()
aktRecluster1p75Hadronic.rParam   = cms.double(1.75)

aktRecluster1p5Hadronic          = aktRecluster1p0Hadronic.clone()
aktRecluster1p5Hadronic.rParam   = cms.double(1.5)

aktRecluster1p25Hadronic         = aktRecluster1p0Hadronic.clone()
aktRecluster1p25Hadronic.rParam  = cms.double(1.25)

aktRecluster0p9Hadronic          = aktRecluster1p0Hadronic.clone()
aktRecluster0p9Hadronic.rParam   = cms.double(0.9)

aktRecluster0p8Hadronic          = aktRecluster1p0Hadronic.clone()
aktRecluster0p8Hadronic.rParam   = cms.double(0.8)

aktRecluster0p7Hadronic          = aktRecluster1p0Hadronic.clone()
aktRecluster0p7Hadronic.rParam   = cms.double(0.7)

    
#kt
ktRecluster1p0Hadronic          = kt4PFJets.clone()
ktRecluster1p0Hadronic.src      = inputJetCollection
ktRecluster1p0Hadronic.jetPtMin = cms.double(10.0)
ktRecluster1p0Hadronic.rParam   = cms.double(1.0)
ktRecluster1p0Hadronic.jetType  = 'BasicJet'

ktRecluster3p0Hadronic          = ktRecluster1p0Hadronic.clone()
ktRecluster3p0Hadronic.rParam   = cms.double(3.0)

ktRecluster2p0Hadronic          = ktRecluster1p0Hadronic.clone()
ktRecluster2p0Hadronic.rParam   = cms.double(2.0)

ktRecluster1p75Hadronic          = ktRecluster1p0Hadronic.clone()
ktRecluster1p75Hadronic.rParam   = cms.double(1.75)

ktRecluster1p5Hadronic          = ktRecluster1p0Hadronic.clone()
ktRecluster1p5Hadronic.rParam   = cms.double(1.5)

ktRecluster1p25Hadronic         = ktRecluster1p0Hadronic.clone()
ktRecluster1p25Hadronic.rParam  = cms.double(1.25)

ktRecluster0p9Hadronic          = ktRecluster1p0Hadronic.clone()
ktRecluster0p9Hadronic.rParam   = cms.double(0.9)

ktRecluster0p8Hadronic          = ktRecluster1p0Hadronic.clone()
ktRecluster0p8Hadronic.rParam   = cms.double(0.8)

ktRecluster0p7Hadronic          = ktRecluster1p0Hadronic.clone()
ktRecluster0p7Hadronic.rParam   = cms.double(0.7)


#ca
caRecluster1p0Hadronic          = ca4PFJets.clone()
caRecluster1p0Hadronic.src      = inputJetCollection
caRecluster1p0Hadronic.jetPtMin = cms.double(10.0)
caRecluster1p0Hadronic.rParam   = cms.double(1.0)
caRecluster1p0Hadronic.jetType  = 'BasicJet'

caRecluster3p0Hadronic          = caRecluster1p0Hadronic.clone()
caRecluster3p0Hadronic.rParam   = cms.double(3.0)

caRecluster2p0Hadronic          = caRecluster1p0Hadronic.clone()
caRecluster2p0Hadronic.rParam   = cms.double(2.0)

caRecluster1p75Hadronic          = caRecluster1p0Hadronic.clone()
caRecluster1p75Hadronic.rParam   = cms.double(1.75)

caRecluster1p5Hadronic          = caRecluster1p0Hadronic.clone()
caRecluster1p5Hadronic.rParam   = cms.double(1.5)

caRecluster1p25Hadronic         = caRecluster1p0Hadronic.clone()
caRecluster1p25Hadronic.rParam  = cms.double(1.25)

caRecluster0p9Hadronic          = caRecluster1p0Hadronic.clone()
caRecluster0p9Hadronic.rParam   = cms.double(0.9)

caRecluster0p8Hadronic          = caRecluster1p0Hadronic.clone()
caRecluster0p8Hadronic.rParam   = cms.double(0.8)

caRecluster0p7Hadronic          = caRecluster1p0Hadronic.clone()
caRecluster0p7Hadronic.rParam   = cms.double(0.7)

messingWithJetsHadronicSequence = cms.Sequence(
    deltaRJetGenJet          +
    cmgPFJetSelCHSMatchedToGen +
   # cmgPFJetSelCHSNoPU       +
    aktRecluster3p0Hadronic  +
    aktRecluster2p0Hadronic  +
    aktRecluster1p75Hadronic +
    aktRecluster1p5Hadronic  +
    aktRecluster1p25Hadronic +
    aktRecluster1p0Hadronic  +
    aktRecluster0p9Hadronic  +
    aktRecluster0p8Hadronic  +
    aktRecluster0p7Hadronic  +
    ktRecluster3p0Hadronic   +
    ktRecluster2p0Hadronic   +
    ktRecluster1p75Hadronic  +
    ktRecluster1p5Hadronic   +
    ktRecluster1p25Hadronic  +
    ktRecluster1p0Hadronic   +
    ktRecluster0p9Hadronic   +
    ktRecluster0p8Hadronic   +
    ktRecluster0p7Hadronic   +
    caRecluster3p0Hadronic   +
    caRecluster2p0Hadronic   +
    caRecluster1p75Hadronic  +
    caRecluster1p5Hadronic   +
    caRecluster1p25Hadronic  +
    caRecluster1p0Hadronic   +
    caRecluster0p9Hadronic   +
    caRecluster0p8Hadronic   +
    caRecluster0p7Hadronic  
    )
