import FWCore.ParameterSet.Config as cms

zMuMuCands = cms.EDProducer("DiMuonProducer",
    srcLeg1 = cms.InputTag("selectedPatMuons"),
    srcLeg2 = cms.InputTag("selectedPatMuons"),
    scaleFuncImprovedCollinearApprox = cms.string('1'),
    srcMET = cms.InputTag(''),
    recoMode = cms.string('') ,
    useLeadingTausOnly = cms.bool(False),
    dRmin12 = cms.double(0.)
)

zMuMuCandsMuPt = cms.EDFilter('PATMuPairSelector',
                          src = cms.InputTag('zMuMuCands'),
                          cut = cms.string('leg1().pt()>5. & leg2.pt()>5.'),
                          filter = cms.bool(True)
                        )



zMuMuCandsMuEta = cms.EDFilter('PATMuPairSelector',
                          src = cms.InputTag('zMuMuCands'),
                          cut = cms.string('abs(leg1().eta())<2.4 & abs(leg2.eta())<2.4'),
                          filter = cms.bool(True)
                        )


#LOAD TRIGGER BITS FOR DATA
from L1TriggerConfig.L1GtConfigProducers.L1GtTriggerMaskTechTrigConfig_cff import *
from HLTrigger.HLTfilters.hltLevel1GTSeed_cfi import *
hltLevel1GTSeed.L1TechTriggerSeeding = cms.bool(True)
hltLevel1GTSeed.L1SeedsLogicalExpression = cms.string('(0 AND (40 OR 41) AND NOT (36 OR 37 OR 38 OR 39))')

#Scraping
scrapping = cms.EDFilter("FilterOutScraping",
                                 applyfilter = cms.untracked.bool(True),
                                 debugOn = cms.untracked.bool(False),
                                 numtrack = cms.untracked.uint32(10),
                                 thresh = cms.untracked.double(0.25)
)

#Tracker ON
tkHVON = cms.EDFilter("PhysDecl",
                              applyFilter=cms.untracked.bool(True)
)

from HLTrigger.HLTfilters.hltHighLevel_cfi import *
hltHighLevel.TriggerResultsTag = cms.InputTag("TriggerResults","","HLT")
hltHighLevel.HLTPaths = cms.vstring("HLT_Mu9") # provide list of HLT paths (or patterns) you want
hltHighLevel.andOr = cms.bool(True)  # how to deal with multiple triggers: True (OR) accept if ANY is true, False (AND) accept if ALL are true

