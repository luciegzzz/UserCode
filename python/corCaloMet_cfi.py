from JetMETCorrections.Configuration.JetCorrectionServicesAllAlgos_cff import *
from JetMETCorrections.Type1MET.MetType1Corrections_cff import *

metMuonJESCorAK5 = metJESCorAK5CaloJet.clone()
metMuonJESCorAK5.inputUncorMetLabel = "corMetGlobalMuons"
metCorSequence = cms.Sequence(metMuonJESCorAK5)
