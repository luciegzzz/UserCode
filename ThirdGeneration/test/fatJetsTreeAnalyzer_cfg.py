import copy
import CMGTools.RootTools.fwlite.Config as cfg

from   CMGTools.H2TauTau.proto.samples.getFiles import getFiles

ana = cfg.Analyzer(
    'FatJetsTreeAnalyzer',
    verbose = False,
    listOfFatJetAlgos  = [
    'aktRecluster0p7Hadronic',
    'aktRecluster0p8Hadronic',
    'aktRecluster0p9Hadronic',
    'aktRecluster1p0Hadronic',
    'aktRecluster1p25Hadronic',
    'aktRecluster1p5Hadronic',
    'aktRecluster1p75Hadronic',
    ],
    )



filesT2tt = getFiles('/SMS-T2tt_FineBin_Mstop-225to1200_mLSP-0to1000_8TeV-Pythia6Z/Summer12-START52_V9_FSIM-v1/AODSIM/V5_B/PAT_CMG_V5_6_0_B/TOP/',
         'lucieg', 'topTuple_.*root')[1:2]

T2tt = cfg.MCComponent(
    name = 'T2tt',
    files = filesT2tt,
    xSection = 1., 
    nGenEvents = 4500,
    triggers = [],
    effCorrFactor = 1,
    intLumi = 15.0)

    
#filesQCDHT100To250 = getFiles('/QCD_HT-100To250_TuneZ2star_8TeV-madgraph-pythia/Summer12-PU_S7_START52_V9-v1/AODSIM/V5_B/PAT_CMG_V5_6_0_B/TOP/SKIMDiJetMET','lucieg', 'skim_.*root')
filesQCDHT100To250 = getFiles('/QCD_HT-100To250_TuneZ2star_8TeV-madgraph-pythia/Summer12-PU_S7_START52_V9-v1/AODSIM/V5_B/PAT_CMG_V5_6_0_B/TOP/','lucieg', 'topTuple_.*root')[1:2]

QCDHT100To250 = cfg.MCComponent(
        name = 'QCDHT100To250',
            files = filesQCDHT100To250,
            xSection = 10400000.,
            nGenEvents = 48553986,
            triggers = [],
            effCorrFactor = 1,
            intLumi = 15.0)

#filesQCDHT250To500 = getFiles('/QCD_HT-250To500_TuneZ2star_8TeV-madgraph-pythia/Summer12-PU_S7_START52_V9-v1/AODSIM/V5_B/PAT_CMG_V5_6_0_B/TOP/SKIMDiJetMET','lucieg', 'skim_.*root')
filesQCDHT250To500 = getFiles('/QCD_HT-250To500_TuneZ2star_8TeV-madgraph-pythia/Summer12-PU_S7_START52_V9-v1/AODSIM/V5_B/PAT_CMG_V5_6_0_B/TOP/','lucieg', 'topTuple_.*root')[1:2]

QCDHT250To500 = cfg.MCComponent(
            name = 'QCDHT250To500',
            files = filesQCDHT250To500,
            xSection = 276000.,
            nGenEvents = 26876653,
            triggers = [],
            effCorrFactor = 1,
            intLumi = 15.0)

#filesQCDHT500To1000 = getFiles('/QCD_HT-500To1000_TuneZ2star_8TeV-madgraph-pythia/Summer12-PU_S7_START52_V9-v1/AODSIM/V5_B/PAT_CMG_V5_6_0_B/TOP/SKIMDiJetMET','lucieg', 'skim_.*root')
filesQCDHT500To1000 = getFiles('/QCD_HT-500To1000_TuneZ2star_8TeV-madgraph-pythia/Summer12-PU_S7_START52_V9-v1/AODSIM/V5_B/PAT_CMG_V5_6_0_B/TOP/','lucieg', 'topTuple_.*root')[1:2]

QCDHT500To1000 = cfg.MCComponent(
            name = 'QCDHT500To1000',
            files = filesQCDHT500To1000,
            xSection = 8426.,
            nGenEvents = 32255694,
            triggers = [],
            effCorrFactor = 1,
            intLumi = 15.0)


#filesQCDHT1000Inf = getFiles('/QCD_HT-1000ToInf_TuneZ2star_8TeV-madgraph-pythia6/Summer12-PU_S7_START52_V9-v1/AODSIM/V5_B/PAT_CMG_V5_6_0_B/TOP/SKIMDiJetMET','lucieg', 'skim_.*root')
filesQCDHT1000Inf = getFiles('/QCD_HT-1000ToInf_TuneZ2star_8TeV-madgraph-pythia6/Summer12-PU_S7_START52_V9-v1/AODSIM/V5_B/PAT_CMG_V5_6_0_B/TOP/','lucieg', 'topTuple_.*root')[1:2]

QCDHT1000Inf = cfg.MCComponent(
    name = 'QCDHT1000Inf',
    files = filesQCDHT1000Inf,
    xSection = 204., 
    nGenEvents = 13879218,
    triggers = [],
    effCorrFactor = 1,
    intLumi = 15.0)

#filesTTJets = getFiles('/TTJets_TuneZ2star_8TeV-madgraph-tauola/Summer12-PU_S7_START52_V9-v1/AODSIM/V5_B/PAT_CMG_V5_6_0_B/TOP/SKIMDiJetMET','lucieg', 'skim_.*root')
filesTTJets = getFiles('/TTJets_TuneZ2star_8TeV-madgraph-tauola/Summer12-PU_S7_START52_V9-v1/AODSIM/V5_B/PAT_CMG_V5_6_0_B/TOP/','lucieg', 'topTuple_.*root')[1:2]

TTJets = cfg.MCComponent(
    name = 'TTJets',
    files = filesTTJets,
    xSection = 62.3,#136.3, 
    nGenEvents = 2983701,
    triggers = [],
    effCorrFactor = 1,
    intLumi = 15.0)


selectedComponents =  [T2tt,QCDHT100To250, QCDHT250To500, QCDHT500To1000,QCDHT1000Inf, TTJets]
#selectedComponents=[T2tt,TTJets]

sequence = cfg.Sequence( [
    ana
    ] )

config = cfg.Config( components = selectedComponents,
                     sequence = sequence )


#for i in range(0,1):

T2tt.splitFactor   = 1

QCDHT100To250.splitFactor = 10
QCDHT250To500.splitFactor = 10
QCDHT500To1000.splitFactor = 10
QCDHT1000Inf.splitFactor = 10
TTJets.splitFactor = 10
