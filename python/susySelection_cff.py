import FWCore.ParameterSet.Config as cms

#from PFAnalyses.ZMuMuForMET.susySelection_cfi import*

#-----EVENT PRESELECTION----#

## ##------ Nvtx >=1----------- ##
selectedVertices = cms.EDFilter("VtxCountFilter",
                                src = cms.InputTag("offlinePrimaryVertices"),
                                minNumber = cms.uint32(1),
                                maxNumber = cms.uint32(999999),
                                #filter = cms.bool(True)
                                )

## #NEED TO WRITE STH SIMILAR TO WHAT WRITTEN FOR MHT
## preselectedJetsEEMF = cms.EDFilter("PATEEMFSelector",
##                                   src = cms.InputTag("selectedPatJets"),
##                                   cut = cms.string(" eemf > 0.175 "),
##                                   filter= cms.bool(True)                    
##                                   )###PRODUCES A NEW COLLECTION preselectedJetsEEMF

## -----Lepton veto------#

selectedMuons = cms.EDFilter("PATMuonSelector",
                                  src = cms.InputTag("selectedPatMuons"),
                                  cut = cms.string("pt > 10 && abs(eta) < 2.4 && normChi2 < 10 && numberOfValidHits > 11"),##ISOLATION TO BE ADDED, dxyBS!!!
                                  #filter = cms.bool(True)
                                  )

selectedElectrons = cms.EDFilter("PATMuonSelector",
                                  src = cms.InputTag("selectedPatMuons"),
                                  cut = cms.string("pt > 10 && abs(eta) < 2.4 && normChi2 < 10 && numberOfValidHits > 11"),##ISOLATION TO BE ADDED, dxyBS!!!
                                  #filter = cms.bool(True)
                                  )

#-----EVENT SELECTION----#

##------JETS-----------------##
###-----Drop jets if eta < 2.6 and EMF < 0.01------###
selectedJetsEtacEMF =  cms.EDFilter("PATJetSelector",
                                    src = cms.InputTag("selectedPatJets"),
                                    cut = cms.string(" !((chargedEmEnergyFraction+neutralEmEnergyFraction)< 0.01 & abs(eta) <2.6) "),
                                   # filter= cms.bool(True)                    
                                    )###PRODUCES A NEW COLLECTION selectedJetsEtacEMF

###-----NJets st eta < 2.5 and pt > 50GeV > 3------###
selectedJetsPtEta = cms.EDFilter("PATJetSelector",
                                 src = cms.InputTag("selectedJetsEtacEMF"),
                                 cut = cms.string(" pt > 50 && abs(eta) < 2.5  "),
                                 #filter= cms.bool(True)                    
                                 )###PRODUCES A NEW COLLECTION selectedJetsPtEta, DOES NOT MODIFY THE PATJET COLLECTION


selectedJetsNr = cms.EDFilter("PATCandViewCountFilter",
                              src = cms.InputTag("selectedJetsPtEta"),
                              minNumber = cms.uint32(3),
                              maxNumber = cms.uint32(999999),
                              filter = cms.bool(True)
                              )###ACTS DIRECTLY ON THE PATJET COLLECTION


##-------MHT and HT------------##
selectedMHT = cms.EDFilter("PATMHTSelector",
                           src = cms.InputTag("PFpatMHTs"),
                           cut = cms.string("ht > 300 && mht > 150"),
                           #filter = cms.bool(True)
                           )### PRODUCES A NEW COLLECTION selectedMHT

susySelection = cms.Sequence(
    selectedVertices +
    selectedJetsEtacEMF*selectedJetsPtEta*selectedJetsNr +
    selectedMHT
    )
