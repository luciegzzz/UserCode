import FWCore.ParameterSet.Config as cms

#dir = '/data/lucieg/HltPfJetsAnalyzerMatchingRestoredHLTMay10/'
#dir = '/data/lucieg/HltPfJetsAnalyzerNoMatchingMuonDisentangledHLTMay16/'
dir = '/data/lucieg/HltPfJetsAnalyzerNoMatchingMuonDisentangledEvenAtHLTHLTMay16/'
#dir = ''
##various HLT
####various reco
####AK5
HltRecoPfJetsAnalyzer = cms.EDAnalyzer('HLTrecoPFJetsAnalyzer',
                                       hltjets         = cms.InputTag('hltAntiKT5PFJets'),
                                       recojets        = cms.InputTag('ak5PFJets'),
                                       muons           = cms.InputTag('cmgMuonSel'),
                                       dRMatched       = cms.untracked.double( 1000. ),  ###note : set it to 1000 to avoid matching
                                       etaBinning      = cms.untracked.uint32( 12 ),
                                       etaBinningResp  = cms.untracked.double( 1. ),
                                       ptBinningResp   = cms.untracked.double( 20. ),
                                       filename        = cms.untracked.string(dir+'analyzerHLTReco.root') 
)

HltPFNoPURecoPfJetsAnalyzer = cms.EDAnalyzer('HLTrecoPFJetsAnalyzer',
                                       hltjets         = cms.InputTag('hltAntiKT5PFJetsNoPU'),
                                       recojets        = cms.InputTag('ak5PFJets'),
                                       muons           = cms.InputTag('cmgMuonSel'),
                                       dRMatched       = cms.untracked.double( 1000. ),
                                       etaBinning      = cms.untracked.uint32( 12 ),
                                       etaBinningResp  = cms.untracked.double( 1. ),
                                       ptBinningResp   = cms.untracked.double( 20. ),
                                       filename        = cms.untracked.string(dir+'analyzerHLTPFNoPUReco.root') 
)

HltPFNoPUL1L2L3RecoPfJetsAnalyzer = cms.EDAnalyzer('HLTrecoPFJetsAnalyzer',
                                       hltjets         = cms.InputTag('hltAK5PFJetNoPUL1FastL2L3Corrected'),
                                       recojets        = cms.InputTag('ak5PFJets'),
                                       muons           = cms.InputTag('cmgMuonSel'),            
                                       dRMatched       = cms.untracked.double( 1000. ),
                                       etaBinning      = cms.untracked.uint32( 12 ),
                                       etaBinningResp  = cms.untracked.double( 1. ),
                                       ptBinningResp   = cms.untracked.double( 20. ),
                                       filename        = cms.untracked.string(dir+'analyzerHLTPFNoPUL1L2L3Reco.root') 
)

HltL1L2L3RecoPfJetsAnalyzer = cms.EDAnalyzer('HLTrecoPFJetsAnalyzer',
                                       hltjets         = cms.InputTag('hltAK5PFJetL1FastL2L3Corrected'),
                                       recojets        = cms.InputTag('ak5PFJets'),
                                       muons           = cms.InputTag('cmgMuonSel'),      
                                       dRMatched       = cms.untracked.double( 1000. ),
                                       etaBinning      = cms.untracked.uint32( 12 ),
                                       etaBinningResp  = cms.untracked.double( 1. ),
                                       ptBinningResp   = cms.untracked.double( 20. ),
                                       filename        = cms.untracked.string(dir+'analyzerHLTL1L2L3Reco.root') 
)

HltCaloRecoPfJetsAnalyzer = cms.EDAnalyzer('HLTcalorecoPFJetsAnalyzer',
                                       hltjets         = cms.InputTag('hltCaloJetL1FastJetCorrected'),
                                       recojets        = cms.InputTag('ak5PFJets'),
                                       muons           = cms.InputTag('cmgMuonSel'),    
                                       dRMatched       = cms.untracked.double( 1000. ),
                                       etaBinning      = cms.untracked.uint32( 12 ),
                                       etaBinningResp  = cms.untracked.double( 1. ),
                                       ptBinningResp   = cms.untracked.double( 20. ),
                                       filename        = cms.untracked.string(dir+'analyzerHLTCaloReco.root') 
)


####CMG
HltCmgPfJetsAnalyzer = cms.EDAnalyzer('HLTcmgPFJetsAnalyzer',
                                      hltjets         = cms.InputTag('hltAntiKT5PFJets'),
                                      recojets        = cms.InputTag('cmgPFJetSel'),
                                      muons           = cms.InputTag('cmgMuonSel'),
                                      dRMatched       = cms.untracked.double( 1000. ),
                                      etaBinning      = cms.untracked.uint32( 12 ),
                                      etaBinningResp  = cms.untracked.double( 1. ),
                                      ptBinningResp   = cms.untracked.double( 20. ),
                                      filename        = cms.untracked.string(dir+'analyzerHLTCMG.root') 
)

HltPFNoPUCmgPfJetsAnalyzer = cms.EDAnalyzer('HLTcmgPFJetsAnalyzer',
                                       hltjets         = cms.InputTag('hltAntiKT5PFJetsNoPU'),
                                       recojets        = cms.InputTag('cmgPFJetSel'),
                                       muons           = cms.InputTag('cmgMuonSel'),      
                                       dRMatched       = cms.untracked.double( 1000. ),
                                       etaBinning      = cms.untracked.uint32( 12 ),
                                       etaBinningResp  = cms.untracked.double( 1. ),
                                       ptBinningResp   = cms.untracked.double( 20. ),
                                       filename        = cms.untracked.string(dir+'analyzerHLTPFNoPUCMG.root') 
)

HltPFNoPUL1L2L3CmgPfJetsAnalyzer = cms.EDAnalyzer('HLTcmgPFJetsAnalyzer',
                                       hltjets         = cms.InputTag('hltAK5PFJetNoPUL1FastL2L3Corrected'),
                                       recojets        = cms.InputTag('cmgPFJetSel'),
                                       muons           = cms.InputTag('cmgMuonSel'),            
                                       dRMatched       = cms.untracked.double( 1000. ),
                                       etaBinning      = cms.untracked.uint32( 12 ),
                                       etaBinningResp  = cms.untracked.double( 1. ),
                                       ptBinningResp   = cms.untracked.double( 20. ),
                                       filename        = cms.untracked.string(dir+'analyzerHLTPFNoPUL1L2L3CMG.root') 
)

HltL1L2L3CmgPfJetsAnalyzer = cms.EDAnalyzer('HLTcmgPFJetsAnalyzer',
                                       hltjets         = cms.InputTag('hltAK5PFJetL1FastL2L3Corrected'),
                                       recojets        = cms.InputTag('cmgPFJetSel'),
                                       muons           = cms.InputTag('cmgMuonSel'),      
                                       dRMatched       = cms.untracked.double( 1000. ),
                                       etaBinning      = cms.untracked.uint32( 12 ),
                                       etaBinningResp  = cms.untracked.double( 1. ),
                                       ptBinningResp   = cms.untracked.double( 20. ),
                                       filename        = cms.untracked.string(dir+'analyzerHLTL1L2L3CMG.root') 
)

HltCaloCmgPfJetsAnalyzer = cms.EDAnalyzer('HLTcalocmgPFJetsAnalyzer',
                                      hltjets         = cms.InputTag('hltCaloJetL1FastJetCorrected'),
                                      recojets        = cms.InputTag('cmgPFJetSel'),
                                      muons           = cms.InputTag('cmgMuonSel'),     
                                      dRMatched       = cms.untracked.double( 1000. ),
                                      etaBinning      = cms.untracked.uint32( 12 ),
                                      etaBinningResp  = cms.untracked.double( 1. ),
                                      ptBinningResp   = cms.untracked.double( 20. ),
                                      filename        = cms.untracked.string(dir+'analyzerHLTCaloCMG.root') 
)


####CMGCHS
HltCmgCHSPfJetsAnalyzer = cms.EDAnalyzer('HLTcmgPFJetsAnalyzer',
                                         hltjets         = cms.InputTag('hltAntiKT5PFJets'),
                                         recojets        = cms.InputTag('cmgPFJetSelCHS'),
                                         muons           = cms.InputTag('cmgMuonSel'), 
                                         dRMatched       = cms.untracked.double( 1000. ),
                                         etaBinning      = cms.untracked.uint32( 12 ),
                                         etaBinningResp  = cms.untracked.double( 1. ),
                                         ptBinningResp   = cms.untracked.double( 20. ),
                                         filename        = cms.untracked.string(dir+'analyzerHLTCMGCHS.root') 
)

HltPFNoPUCmgchsPfJetsAnalyzer = cms.EDAnalyzer('HLTcmgPFJetsAnalyzer',
                                       hltjets         = cms.InputTag('hltAntiKT5PFJetsNoPU'),
                                       recojets        = cms.InputTag('cmgPFJetSelCHS'),
                                       muons           = cms.InputTag('cmgMuonSel'),         
                                       dRMatched       = cms.untracked.double( 1000. ),
                                       etaBinning      = cms.untracked.uint32( 12 ),
                                       etaBinningResp  = cms.untracked.double( 1. ),
                                       ptBinningResp   = cms.untracked.double( 20. ),
                                       filename        = cms.untracked.string(dir+'analyzerHLTPFNoPUCMGCHS.root') 
)

HltPFNoPUL1L2L3CmgchsPfJetsAnalyzer = cms.EDAnalyzer('HLTcmgPFJetsAnalyzer',
                                       hltjets         = cms.InputTag('hltAK5PFJetNoPUL1FastL2L3Corrected'),
                                       recojets        = cms.InputTag('cmgPFJetSelCHS'),
                                       muons           = cms.InputTag('cmgMuonSel'),               
                                       dRMatched       = cms.untracked.double( 1000. ),
                                       etaBinning      = cms.untracked.uint32( 12 ),
                                       etaBinningResp  = cms.untracked.double( 1. ),
                                       ptBinningResp   = cms.untracked.double( 20. ),
                                       filename        = cms.untracked.string(dir+'analyzerHLTPFNoPUL1L2L3CMGCHS.root') 
)

HltL1L2L3CmgchsPfJetsAnalyzer = cms.EDAnalyzer('HLTcmgPFJetsAnalyzer',
                                       hltjets         = cms.InputTag('hltAK5PFJetL1FastL2L3Corrected'),
                                       recojets        = cms.InputTag('cmgPFJetSelCHS'),
                                       muons           = cms.InputTag('cmgMuonSel'),         
                                       dRMatched       = cms.untracked.double( 1000. ),
                                       etaBinning      = cms.untracked.uint32( 12 ),
                                       etaBinningResp  = cms.untracked.double( 1. ),
                                       ptBinningResp   = cms.untracked.double( 20. ),
                                       filename        = cms.untracked.string(dir+'analyzerHLTL1L2L3CMGCHS.root') 
)

HltCaloCmgCHSPfJetsAnalyzer = cms.EDAnalyzer('HLTcalocmgPFJetsAnalyzer',
                                         hltjets         = cms.InputTag('hltCaloJetL1FastJetCorrected'),
                                         recojets        = cms.InputTag('cmgPFJetSelCHS'),
                                         muons           = cms.InputTag('cmgMuonSel'),     
                                         dRMatched       = cms.untracked.double( 1000. ),
                                         etaBinning      = cms.untracked.uint32( 12 ),
                                         etaBinningResp  = cms.untracked.double( 1. ),
                                         ptBinningResp   = cms.untracked.double( 20. ),
                                         filename        = cms.untracked.string(dir+'analyzerHLTCaloCMGCHS.root') 
)

