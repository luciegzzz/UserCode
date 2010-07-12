//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Mon Sep  1 19:12:16 2008 by ROOT version 5.18/00a
// from TTree OHltTree/
// found on file: TEST.root
//////////////////////////////////////////////////////////

#ifndef OHltTree_h
#define OHltTree_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TRandom3.h>
#include <TLorentzVector.h>

#include <vector>
#include <string>
#include <map>

#include "OHltConfig.h"
#include "OHltMenu.h"
#include "OHltRateCounter.h"

#include "L1GtLogicParser.h"

#include "TH1.h"
#include "TH2.h"

class OHltTree {
public :
  TTree          *fChain;   //!pointer to the analyzed TTree or TChain
  Int_t           fCurrent; //!current Tree number in a TChain

  // logic parser for m_l1SeedsLogicalExpression
  std::vector<L1GtLogicParser*> m_l1AlgoLogicParser;
  L1GtLogicParser* m_preFilterLogicParser;
  void SetLogicParser(std::string l1SeedsLogicalExpression);

  // Declaration of leaf types
  Int_t           NrecoJetCal;
  Int_t           NrecoJetGen;
  Int_t           NrecoTowCal;
  Int_t           NrecoJetCorCal;
  Float_t         recoJetCalPt[43000];   //[NrecoJetCal]
  Float_t         recoJetCalPhi[43000];   //[NrecoJetCal]
  Float_t         recoJetCalEta[43000];   //[NrecoJetCal]
  Float_t         recoJetCalEt[43000];   //[NrecoJetCal]
  Float_t         recoJetCalE[43000];   //[NrecoJetCal]
  Float_t         recoJetGenPt[68000];   //[NrecoJetGen]
  Float_t         recoJetGenPhi[68000];   //[NrecoJetGen]
  Float_t         recoJetGenEta[68000];   //[NrecoJetGen]
  Float_t         recoJetGenEt[68000];   //[NrecoJetGen]
  Float_t         recoJetGenE[68000];   //[NrecoJetGen]
  Float_t         recoTowEt[684000];   //[NrecoTowCal]
  Float_t         recoTowEta[684000];   //[NrecoTowCal]
  Float_t         recoTowPhi[684000];   //[NrecoTowCal]
  Float_t         recoTowE[684000];   //[NrecoTowCal]
  Float_t         recoTowEm[684000];   //[NrecoTowCal]
  Float_t         recoTowHad[684000];   //[NrecoTowCal]
  Float_t         recoTowOE[684000];   //[NrecoTowCal]
  Float_t         recoJetCorCalPt[43000];   //[NrecoJetCorCal]
  Float_t         recoJetCorCalPhi[43000];   //[NrecoJetCorCal]
  Float_t         recoJetCorCalEta[43000];   //[NrecoJetCorCal]
  Float_t         recoJetCorCalE[43000];   //[NrecoJetCorCal]
  Float_t         recoMetCal;
  Float_t         recoMetCalPhi;
  Float_t         recoMetCalSum;
  Float_t         recoMetGen;
  Float_t         recoMetGenPhi;
  Float_t         recoMetGenSum;
  Float_t         recoHTCal;
  Float_t         recoHTCalPhi;
  Float_t         recoHTCalSum;
  Int_t           NohTau;
  Float_t         ohTauEta[5000];   //[NohTau]
  Float_t         ohTauPhi[5000];   //[NohTau]
  Float_t         ohTauPt[5000];   //[NohTau]
  Float_t         ohTauEiso[5000];   //[NohTau]
  Float_t         ohTauL25Tpt[5000];   //[NohTau]
  Int_t           ohTauL25Tiso[5000];   //[NohTau]
  Float_t         ohTauL3Tpt[5000];   //[NohTau]
  Int_t           ohTauL3Tiso[5000];   //[NohTau]
  Int_t           NohBJetL2;     //
  Float_t         ohBJetL2Et[5000];  //[NohBJetL2] 
  Float_t         ohBJetL2Energy[5000];  //[NohBJetL2]  
  Float_t         ohBJetL2Pt[5000];  //[NohBJetL2]  
  Float_t         ohBJetL2Eta[5000];  //[NohBJetL2]  
  Float_t         ohBJetL2Phi[5000];  //[NohBJetL2]  
  Int_t           NohPixelTracksL3;
  Float_t         ohPixelTracksL3Pt[10000];   //[NohPixelTracks]
  Float_t         ohPixelTracksL3Eta[10000];   //[NohPixelTracks]
  Float_t         ohPixelTracksL3Phi[10000];   //[NohPixelTracks]
  Float_t         ohPixelTracksL3Vz[10000];   //[NohPixelTracks]
  Int_t           NohBJetLife;
  Float_t         ohBJetLifeL2E[1000];   //[NohBJetLife]
  Float_t         ohBJetLifeL2ET[1000];   //[NohBJetLife]
  Float_t         ohBJetLifeL2Eta[1000];   //[NohBJetLife]
  Float_t         ohBJetLifeL2Phi[1000];   //[NohBJetLife]
  Float_t         ohBJetLifeL25Discriminator[1000];   //[NohBJetLife]
  Float_t         ohBJetLifeL3Discriminator[1000];   //[NohBJetLife]
  Int_t           NohBJetPixelTracks;
  Float_t         ohBJetLifePixelTrackPt[10000];   //[NohBJetPixelTracks]
  Float_t         ohBJetLifePixelTrackEta[10000];   //[NohBJetPixelTracks]
  Float_t         ohBJetLifePixelTrackPhi[10000];   //[NohBJetPixelTracks]
  Float_t         ohBJetLifePixelTrackChi2[10000];   //[NohBJetPixelTracks]
  Int_t           NohBJetRegionalTracks;
  Float_t         ohBJetLifeRegionalTrackPt[10000];   //[NohBJetRegionalTracks]
  Float_t         ohBJetLifeRegionalTrackEta[10000];   //[NohBJetRegionalTracks]
  Float_t         ohBJetLifeRegionalTrackPhi[10000];   //[NohBJetRegionalTracks]
  Float_t         ohBJetLifeRegionalTrackChi2[10000];   //[NohBJetRegionalTracks]
  Float_t         ohBJetLifeRegionalSeedPt[10000];   //[NohBJetRegionalTracks]
  Float_t         ohBJetLifeRegionalSeedEta[10000];   //[NohBJetRegionalTracks]
  Float_t         ohBJetLifeRegionalSeedPhi[10000];   //[NohBJetRegionalTracks]
  Int_t           NohBJetSoftm;
  Float_t         ohBJetSoftmL2E[1000];   //[NohBJetSoftm]
  Float_t         ohBJetSoftmL2ET[1000];   //[NohBJetSoftm]
  Float_t         ohBJetSoftmL2Eta[1000];   //[NohBJetSoftm]
  Float_t         ohBJetSoftmL2Phi[1000];   //[NohBJetSoftm]
  Int_t           ohBJetSoftmL25Discriminator[1000];   //[NohBJetSoftm]
  Float_t         ohBJetSoftmL3Discriminator[1000];   //[NohBJetSoftm]
  Int_t           NohBJetL2Corrected;
  Float_t         ohBJetPerfL2E[1000];   //[NohBJetL2Corrected]
  Float_t         ohBJetPerfL2ET[1000];   //[NohBJetL2Corrected]
  Float_t         ohBJetPerfL2Eta[1000];   //[NohBJetL2Corrected]
  Float_t         ohBJetPerfL2Phi[1000];   //[NohBJetL2Corrected]
  Float_t         ohBJetL2CorrectedEnergy[10];   //[NohBJetL2Corrected] 
  Float_t         ohBJetL2CorrectedEt[10];   //[NohBJetL2Corrected] 
  Float_t         ohBJetL2CorrectedPt[10];   //[NohBJetL2Corrected] 
  Float_t         ohBJetL2CorrectedEta[10];   //[NohBJetL2Corrected] 
  Float_t         ohBJetL2CorrectedPhi[10];   //[NohBJetL2Corrected] 
  Float_t         ohBJetIPL25Tag[10];   //[NohBJetL2] 
  Float_t         ohBJetIPL3Tag[10];   //[NohBJetL2] 
  Float_t         ohBJetIPLooseL25Tag[10];   //[NohBJetL2] 
  Float_t         ohBJetIPLooseL3Tag[10];   //[NohBJetL2] 
  Int_t           ohBJetMuL25Tag[10];   //[NohBJetL2] 
  Float_t         ohBJetMuL3Tag[10];   //[NohBJetL2] 
  Int_t           ohBJetPerfL25Tag[10];   //[NohBJetL2] 
  Int_t           ohBJetPerfL3Tag[10];   //[NohBJetL2] 
  //ccla
  Int_t           recoNVrt;           // reconstructed vertex info
  Float_t         recoVrtX[10];       //
  Float_t         recoVrtY[10];       //
  Float_t         recoVrtZ[10];       //
  Int_t           recoVrtNtrk[10];    //
  Float_t         recoVrtChi2[10];    //
  Float_t         recoVrtNdof[10];    //

  Int_t           NrecoElec;
  Float_t         recoElecPt[4000];   //[NrecoElec]
  Float_t         recoElecPhi[4000];   //[NrecoElec]
  Float_t         recoElecEta[4000];   //[NrecoElec]
  Float_t         recoElecEt[4000];   //[NrecoElec]
  Float_t         recoElecE[4000];   //[NrecoElec]
  Int_t           NrecoPhot;
  Float_t         recoPhotPt[5000];   //[NrecoPhot]
  Float_t         recoPhotPhi[5000];   //[NrecoPhot]
  Float_t         recoPhotEta[5000];   //[NrecoPhot]
  Float_t         recoPhotEt[5000];   //[NrecoPhot]
  Float_t         recoPhotE[5000];   //[NrecoPhot]
  Int_t           NohPhot;
  Float_t         ohPhotEt[8000];   //[NohPhot]
  Float_t         ohPhotEta[8000];   //[NohPhot]
  Float_t         ohPhotPhi[8000];   //[NohPhot]
  Float_t         ohPhotEiso[8000];   //[NohPhot]
  Float_t         ohPhotHiso[8000];   //[NohPhot]
  Float_t         ohPhotTiso[8000];   //[NohPhot]
  Int_t           ohPhotL1iso[8000];   //[NohPhot]
  Int_t           NohEle;
  Float_t         ohEleClusShap[8000];   //[NohEle]
  Float_t         ohEleDeta[8000];   //[NohEle]
  Float_t         ohEleDphi[8000];   //[NohEle]
  Float_t         ohEleEt[8000];   //[NohEle]
  Float_t         ohEleEta[8000];   //[NohEle]
  Float_t         ohElePhi[8000];   //[NohEle]
  Float_t         ohEleE[8000];   //[NohEle]
  Float_t         ohEleP[8000];   //[NohEle]
  Float_t         ohEleHiso[8000];   //[NohEle]
  Float_t         ohEleTiso[8000];   //[NohEle]
  Int_t           ohEleL1iso[8000];   //[NohEle]
  Int_t           ohElePixelSeeds[8000];   //[NohEle]
  Int_t           ohEleNewSC[8000];   //[NohEle]
  Int_t           NohEleLW;
  Float_t         ohEleClusShapLW[8000];   //[NohEle]
  Float_t         ohEleDetaLW[8000];   //[NohEle]
  Float_t         ohEleDphiLW[8000];   //[NohEle]
  Float_t         ohEleEtLW[11000];   //[NohEleLW]
  Float_t         ohEleEtaLW[11000];   //[NohEleLW]
  Float_t         ohElePhiLW[11000];   //[NohEleLW]
  Float_t         ohEleELW[11000];   //[NohEleLW]
  Float_t         ohElePLW[11000];   //[NohEleLW]
  Float_t         ohEleHisoLW[11000];   //[NohEleLW]
  Float_t         ohEleTisoLW[11000];   //[NohEleLW]
  Int_t           ohEleL1isoLW[11000];   //[NohEleLW]
  Int_t           ohElePixelSeedsLW[11000];   //[NohEleLW]
  Int_t           ohEleNewSCLW[11000];   //[NohEleLW]
  Int_t           NrecoMuon;
  Float_t         recoMuonPt[5000];   //[NrecoMuon]
  Float_t         recoMuonPhi[5000];   //[NrecoMuon]
  Float_t         recoMuonEta[5000];   //[NrecoMuon]
  Float_t         recoMuonEt[5000];   //[NrecoMuon]
  Float_t         recoMuonE[5000];   //[NrecoMuon]
  Int_t           NohMuL2;
  Float_t         ohMuL2Pt[2000];   //[NohMuL2]
  Float_t         ohMuL2Phi[2000];   //[NohMuL2]
  Float_t         ohMuL2Eta[2000];   //[NohMuL2]
  Int_t           ohMuL2Chg[2000];   //[NohMuL2]
  Float_t         ohMuL2PtErr[2000];   //[NohMuL2]
  Int_t           ohMuL2Iso[2000];   //[NohMuL2]
  Float_t         ohMuL2Dr[2000];   //[NohMuL2]
  Float_t         ohMuL2Dz[2000];   //[NohMuL2]
  Int_t           NohMuL3;
  Float_t         ohMuL3Pt[1000];   //[NohMuL3]
  Float_t         ohMuL3Phi[1000];   //[NohMuL3]
  Float_t         ohMuL3Eta[1000];   //[NohMuL3]
  Int_t           ohMuL3Chg[1000];   //[NohMuL3]
  Float_t         ohMuL3PtErr[1000];   //[NohMuL3]
  Int_t           ohMuL3Iso[1000];   //[NohMuL3]
  Float_t         ohMuL3Dr[1000];   //[NohMuL3]
  Float_t         ohMuL3Dz[1000];   //[NohMuL3]
  Int_t           ohMuL3L2idx[1000];   //[NohMuL3]
  Int_t           NohOniaPixel;
  Float_t         ohOniaPixelPt[200];   //[NohOniaPixel]
  Float_t         ohOniaPixelPhi[200];   //[NohOniaPixel]
  Float_t         ohOniaPixelEta[200];   //[NohOniaPixel]
  Int_t           ohOniaPixelChg[200];   //[NohOniaPixel]
  Float_t         ohOniaPixelDr[200];   //[NohOniaPixel]
  Float_t         ohOniaPixelDz[200];   //[NohOniaPixel]
  Int_t           ohOniaPixelHits[200];   //[NohOniaPixel]
  Float_t         ohOniaPixelNormChi2[200];   //[NohOniaPixel]
  Int_t           NohOniaTrack;
  Float_t         ohOniaTrackPt[50];   //[NohOniaTrack]
  Float_t         ohOniaTrackPhi[50];   //[NohOniaTrack]
  Float_t         ohOniaTrackEta[50];   //[NohOniaTrack]
  Int_t           ohOniaTrackChg[50];   //[NohOniaTrack]
  Float_t         ohOniaTrackDr[50];   //[NohOniaTrack]
  Float_t         ohOniaTrackDz[50];   //[NohOniaTrack]
  Int_t           ohOniaTrackHits[50];   //[NohOniaTrack]
  Float_t         ohOniaTrackNormChi2[50];   //[NohOniaTrack]
  Float_t         ohHighestEnergyEERecHit; 
  Float_t         ohHighestEnergyEBRecHit; 
  Float_t         ohHighestEnergyHBHERecHit; 
  Float_t         ohHighestEnergyHORecHit; 
  Float_t         ohHighestEnergyHFRecHit; 
  Int_t           Nalcapi0clusters; 
  Float_t         ohAlcapi0ptClusAll[51];   //[Nalcapi0clusters] 
  Float_t         ohAlcapi0etaClusAll[51];   //[Nalcapi0clusters] 
  Float_t         ohAlcapi0phiClusAll[51];   //[Nalcapi0clusters] 
  Float_t         ohAlcapi0s4s9ClusAll[51];   //[Nalcapi0clusters] 
  Int_t           NMCpart;
  Int_t           MCpid[1203000];   //[NMCpart]
  Int_t           MCstatus[1203000];   //[NMCpart]
  Float_t         MCvtxX[1203000];   //[NMCpart]
  Float_t         MCvtxY[1203000];   //[NMCpart]
  Float_t         MCvtxZ[1203000];   //[NMCpart]
  Float_t         MCpt[1203000];   //[NMCpart]
  Float_t         MCeta[1203000];   //[NMCpart]
  Float_t         MCphi[1203000];   //[NMCpart]
  Float_t         MCPtHat;
  Int_t           MCmu3;
  Int_t           MCel3;
  Int_t           MCbb;
  Int_t           MCab;
  Int_t           MCWenu;
  Int_t           MCWmunu;
  Int_t           MCZee;
  Int_t           MCZmumu;
  Float_t         MCptEleMax;
  Float_t         MCptMuMax;
  Int_t           NL1IsolEm;
  Float_t         L1IsolEmEt[4000];   //[NL1IsolEm]
  Float_t         L1IsolEmE[4000];   //[NL1IsolEm]
  Float_t         L1IsolEmEta[4000];   //[NL1IsolEm]
  Float_t         L1IsolEmPhi[4000];   //[NL1IsolEm]
  Int_t           NL1NIsolEm;
  Float_t         L1NIsolEmEt[4000];   //[NL1NIsolEm]
  Float_t         L1NIsolEmE[4000];   //[NL1NIsolEm]
  Float_t         L1NIsolEmEta[4000];   //[NL1NIsolEm]
  Float_t         L1NIsolEmPhi[4000];   //[NL1NIsolEm]
  Int_t           NL1Mu;
  Float_t         L1MuPt[4000];   //[NL1Mu]
  Float_t         L1MuE[4000];   //[NL1Mu]
  Float_t         L1MuEta[4000];   //[NL1Mu]
  Float_t         L1MuPhi[4000];   //[NL1Mu]
  Int_t           L1MuIsol[4000];   //[NL1Mu]
  Int_t           L1MuMip[4000];   //[NL1Mu]
  Int_t           L1MuFor[4000];   //[NL1Mu]
  Int_t           L1MuRPC[4000];   //[NL1Mu]
  Int_t           L1MuQal[4000];   //[NL1Mu]
  Int_t           NL1CenJet;
  Float_t         L1CenJetEt[4000];   //[NL1CenJet]
  Float_t         L1CenJetE[4000];   //[NL1CenJet]
  Float_t         L1CenJetEta[4000];   //[NL1CenJet]
  Float_t         L1CenJetPhi[4000];   //[NL1CenJet]
  Int_t           NL1ForJet;
  Float_t         L1ForJetEt[4000];   //[NL1ForJet]
  Float_t         L1ForJetE[4000];   //[NL1ForJet]
  Float_t         L1ForJetEta[4000];   //[NL1ForJet]
  Float_t         L1ForJetPhi[4000];   //[NL1ForJet]
  Int_t           NL1Tau;
  Float_t         L1TauEt[4000];   //[NL1Tau]
  Float_t         L1TauE[4000];   //[NL1Tau]
  Float_t         L1TauEta[4000];   //[NL1Tau]
  Float_t         L1TauPhi[4000];   //[NL1Tau]
  Float_t         L1Met;
  Float_t         L1MetPhi;
  Float_t         L1MetTot;
  Float_t         L1MetHad;
  Int_t           L1HfRing0EtSumPositiveEta;
  Int_t           L1HfRing1EtSumPositiveEta;
  Int_t           L1HfRing0EtSumNegativeEta;
  Int_t           L1HfRing1EtSumNegativeEta;
  Int_t           L1HfTowerCountPositiveEta;
  Int_t           L1HfTowerCountNegativeEta;
  Int_t           Run;
  Int_t           Event;
  Int_t           LumiBlock;
  Int_t           Bx;
  Int_t           Orbit;

  bool ohEleL1Dupl[8000];
  bool ohEleLWL1Dupl[8000];
  bool ohPhotL1Dupl[8000]; 

  //L1's
  /* For 8E29 Menu */
  Int_t           L1_DoubleEG05_TopBottom;
  Int_t           L1_DoubleMuTopBottom; 
  Int_t           L1_Mu3QE8_Jet6;  
  Int_t           L1_Mu5QE8_Jet6; 
  Int_t           L1_IsoEG10_Jet6_ForJet6; 
  Int_t           L1_SingleJet20; 
  Int_t           L1_SingleJet40; 
  Int_t           L1_SingleJet60; 
  Int_t           L1_DoubleJet30;  
  Int_t           L1_SingleTauJet10; 
  Int_t           L1_SingleTauJet20; 
  Int_t           L1_SingleTauJet50; 
  Int_t           L1_DoubleTauJet14; 
  Int_t           L1_Mu5_Jet6;  
  Int_t           L1_EG5_TripleJet6;  
  Int_t           L1_SingleJet6;  
  Int_t           L1_SingleJet10;
  Int_t           L1_ETM30;  
  Int_t           L1_QuadJet6; 
  Int_t           L1_TripleJet14; 
  Int_t           L1_DoubleEG1; 
  Int_t           L1_DoubleEG2; 
  Int_t           L1_DoubleEG5; 
  Int_t           L1_DoubleHfBitCountsRing1_P1N1; 
  Int_t           L1_DoubleHfBitCountsRing2_P1N1; 
  Int_t           L1_DoubleHfRingEtSumsRing1_P200N200; 
  Int_t           L1_DoubleHfRingEtSumsRing1_P4N4; 
  Int_t           L1_DoubleHfRingEtSumsRing2_P200N200; 
  Int_t           L1_DoubleHfRingEtSumsRing2_P4N4; 
  Int_t           L1_DoubleJet70; 
  Int_t           L1_DoubleMu3; 
  Int_t           L1_DoubleMuOpen; 
  Int_t           L1_DoubleTauJet30; 
  Int_t           L1_EG10_Jet15; 
  Int_t           L1_EG5_TripleJet15; 
  Int_t           L1_ETM20; 
  Int_t           L1_ETM40; 
  Int_t           L1_ETM70; 
  Int_t           L1_ETM80; 
  Int_t           L1_ETT60; 
  Int_t           L1_HTT50; 
  Int_t           L1_HTT100; 
  Int_t           L1_HTT200; 
  Int_t           L1_HTT300; 
  Int_t           L1_IsoEG10_Jet15_ForJet10; 
  Int_t           L1_MinBias_HTT10; 
  Int_t           L1_Mu3QE8_EG5; 
  Int_t           L1_Mu3QE8_Jet15;  
  Int_t           L1_Mu5QE8_Jet15; 
  Int_t           L1_QuadJet15; 
  Int_t           L1_SingleEG1; 
  Int_t           L1_SingleEG10; 
  Int_t           L1_SingleEG12; 
  Int_t           L1_SingleEG15; 
  Int_t           L1_SingleEG2; 
  Int_t           L1_SingleEG20; 
  Int_t           L1_SingleEG5; 
  Int_t           L1_SingleEG8; 
  Int_t           L1_SingleHfBitCountsRing1_1; 
  Int_t           L1_SingleHfBitCountsRing2_1; 
  Int_t           L1_SingleHfRingEtSumsRing1_200; 
  Int_t           L1_SingleHfRingEtSumsRing1_4; 
  Int_t           L1_SingleHfRingEtSumsRing2_200; 
  Int_t           L1_SingleHfRingEtSumsRing2_4; 
  Int_t           L1_SingleIsoEG10; 
  Int_t           L1_SingleIsoEG12; 
  Int_t           L1_SingleIsoEG15; 
  Int_t           L1_SingleIsoEG5; 
  Int_t           L1_SingleIsoEG8; 
  Int_t           L1_SingleJet100; 
  Int_t           L1_SingleJet15; 
  Int_t           L1_SingleJet30; 
  Int_t           L1_SingleJet50; 
  Int_t           L1_SingleJet70; 
  Int_t           L1_SingleMu0; 
  Int_t           L1_SingleMu10; 
  Int_t           L1_SingleMu14; 
  Int_t           L1_SingleMu20; 
  Int_t           L1_SingleMu3; 
  Int_t           L1_SingleMu5; 
  Int_t           L1_SingleMu7; 
  Int_t           L1_SingleMuBeamHalo; 
  Int_t           L1_SingleMuOpen; 
  Int_t           L1_SingleTauJet30; 
  Int_t           L1_SingleTauJet40; 
  Int_t           L1_SingleTauJet60; 
  Int_t           L1_SingleTauJet80; 
  Int_t           L1_TripleJet30; 
  Int_t           L1_ZeroBias;  
  Int_t           L1_ZeroBias_Ext;  
  Int_t           L1_SingleCenJet2;
  Int_t           L1_SingleCenJet4;
  Int_t           L1_SingleForJet2;
  Int_t           L1_SingleForJet4;
  Int_t           L1_SingleTauJet2;
  Int_t           L1_SingleTauJet4;
  Int_t           L1_DoubleForJet10_EtaOpp;

  // ccla - L1 Technical bits (06Dec09)
  Int_t           L1Tech_BPTX_minus_v0;
  Int_t           L1Tech_BPTX_minus_v0_5bx;
  Int_t           L1Tech_BPTX_minus_AND_not_plus_v0;
  Int_t           L1Tech_BPTX_minus_AND_not_plus_v0_5bx;
  Int_t           L1Tech_BPTX_plus_v0;
  Int_t           L1Tech_BPTX_plus_v0_5bx;
  Int_t           L1Tech_BPTX_plus_AND_NOT_minus_v0;
  Int_t           L1Tech_BPTX_plus_AND_NOT_minus_v0_5bx;
  Int_t           L1Tech_BPTX_plus_AND_minus_v0;
  Int_t           L1Tech_BPTX_plus_AND_minus_v0_5bx;
  Int_t           L1Tech_BPTX_plus_AND_minus_instance1_v0;
  Int_t           L1Tech_BPTX_plus_AND_minus_instance1_v0_5bx;
  Int_t           L1Tech_BPTX_plus_OR_minus_v0;
  Int_t           L1Tech_BPTX_plus_OR_minus_v0_5bx;
  Int_t           L1Tech_BPTX_quiet_v0;
  Int_t           L1Tech_BPTX_quiet_v0_5bx;
  Int_t           L1Tech_BSC_HighMultiplicity_v0;
  Int_t           L1Tech_BSC_HighMultiplicity_v0_5bx;
  Int_t           L1Tech_BSC_halo_beam1_inner_v0;
  Int_t           L1Tech_BSC_halo_beam1_inner_v0_5bx;
  Int_t           L1Tech_BSC_halo_beam1_outer_v0;
  Int_t           L1Tech_BSC_halo_beam1_outer_v0_5bx;
  Int_t           L1Tech_BSC_halo_beam2_inner_v0;
  Int_t           L1Tech_BSC_halo_beam2_inner_v0_5bx;
  Int_t           L1Tech_BSC_halo_beam2_outer_v0;
  Int_t           L1Tech_BSC_halo_beam2_outer_v0_5bx;
  Int_t           L1Tech_BSC_minBias_OR_v0;
  Int_t           L1Tech_BSC_minBias_OR_v0_5bx;
  Int_t           L1Tech_BSC_minBias_inner_threshold1_v0;
  Int_t           L1Tech_BSC_minBias_inner_threshold1_v0_5bx;
  Int_t           L1Tech_BSC_minBias_inner_threshold2_v0;
  Int_t           L1Tech_BSC_minBias_inner_threshold2_v0_5bx;
  Int_t           L1Tech_BSC_minBias_threshold1_v0;
  Int_t           L1Tech_BSC_minBias_threshold1_v0_5bx;
  Int_t           L1Tech_BSC_minBias_threshold2_v0;
  Int_t           L1Tech_BSC_minBias_threshold2_v0_5bx;
  Int_t           L1Tech_BSC_splash_beam1_v0;
  Int_t           L1Tech_BSC_splash_beam1_v0_5bx;
  Int_t           L1Tech_BSC_splash_beam2_v0;
  Int_t           L1Tech_BSC_splash_beam2_v0_5bx;
  Int_t           L1Tech_HCAL_HBHE_totalOR_v0;
  Int_t           L1Tech_HCAL_HBHE_totalOR_v0_5bx;
  Int_t           L1Tech_HCAL_HF_totalOR_coincidenceHFM_v0;
  Int_t           L1Tech_HCAL_HF_totalOR_coincidenceHFM_v0_5bx;
  Int_t           L1Tech_HCAL_HF_totalOR_coincidenceHFP_v0;
  Int_t           L1Tech_HCAL_HF_totalOR_coincidenceHFP_v0_5bx;
  Int_t           L1Tech_HCAL_HF_totalOR_minBias_v0;
  Int_t           L1Tech_HCAL_HF_totalOR_minBias_v0_5bx;
  Int_t           L1Tech_HCAL_HO_totalOR_v0;
  Int_t           L1Tech_HCAL_HO_totalOR_v0_5bx;
  Int_t           L1Tech_RPC_TTU_RB0_Cosmics_v0;
  Int_t           L1Tech_RPC_TTU_RB0_Cosmics_v0_5bx;
  Int_t           L1Tech_RPC_TTU_RBminus1_Cosmics_v0;
  Int_t           L1Tech_RPC_TTU_RBminus1_Cosmics_v0_5bx;
  Int_t           L1Tech_RPC_TTU_RBminus2_Cosmics_v0;
  Int_t           L1Tech_RPC_TTU_RBminus2_Cosmics_v0_5bx;
  Int_t           L1Tech_RPC_TTU_RBplus1_Cosmics_v0;
  Int_t           L1Tech_RPC_TTU_RBplus1_Cosmics_v0_5bx;
  Int_t           L1Tech_RPC_TTU_RBplus2_Cosmics_v0;
  Int_t           L1Tech_RPC_TTU_RBplus2_Cosmics_v0_5bx;
  Int_t           L1Tech_RPC_TTU_barrel_Cosmics_v0;
  Int_t           L1Tech_RPC_TTU_barrel_Cosmics_v0_5bx;
  Int_t           L1Tech_RPC_TTU_pointing_Cosmics_v0;
  Int_t           L1Tech_RPC_TTU_pointing_Cosmics_v0_5bx;
  Int_t           L1Tech_RPC_TTU_RBst1_collisions_v0;
  Int_t           L1Tech_RPC_TTU_RBst1_collisions_v0_5bx;

  Int_t           L1Tech_HCAL_HF_MM_or_PP_or_PM_v0;
  Int_t           L1Tech_HCAL_HF_MM_or_PP_or_PM_v0_5bx;
  Int_t           L1Tech_HCAL_HF_coincidence_PM_v1;
  Int_t           L1Tech_HCAL_HF_coincidence_PM_v1_5bx;
  Int_t           L1Tech_HCAL_HF_MMP_or_MPP_v0;
  Int_t           L1Tech_HCAL_HF_MMP_or_MPP_v0_5bx;

  Int_t           L1Tech_ZDC_loose_vertex_v0;
  Int_t           L1Tech_ZDC_loose_vertex_v0_5bx;
  Int_t           L1Tech_ZDC_minus_over_threshold_v0;
  Int_t           L1Tech_ZDC_minus_over_threshold_v0_5bx;
  Int_t           L1Tech_ZDC_plus_over_threshold_v0;
  Int_t           L1Tech_ZDC_plus_over_threshold_v0_5bx;
  Int_t           L1Tech_ZDC_tight_vertex_v0;
  Int_t           L1Tech_ZDC_tight_vertex_v0_5bx;

  // BSC and BPTX algorithm bits
  Int_t           L1_BptxMinus;
  Int_t           L1_BptxMinus_5bx;
  Int_t           L1_BptxPlus;
  Int_t           L1_BptxPlus_5bx;
  Int_t           L1_BptxPlusORMinus;
  Int_t           L1_BptxPlusORMinus_5bx;
  Int_t           L1_BptxPlus_NotBptxMinus;
  Int_t           L1_BptxPlus_NotBptxMinus_5bx;
  Int_t           L1_BptxMinus_NotBptxPlus;
  Int_t           L1_BptxMinus_NotBptxPlus_5bx;
  Int_t           L1_BscHighMultiplicity;
  Int_t           L1_BscHighMultiplicity_5bx;
  Int_t           L1_BscMinBiasInnerThreshold1;
  Int_t           L1_BscMinBiasInnerThreshold1_5bx;
  Int_t           L1_BscMinBiasInnerThreshold2;
  Int_t           L1_BscMinBiasInnerThreshold2_5bx;
  Int_t           L1_BscMinBiasOR;
  Int_t           L1_BscMinBiasOR_5bx;
  Int_t           L1_BscMinBiasOR_BptxPlusORMinus;
  Int_t           L1_BscMinBiasOR_BptxPlusORMinus_5bx;

  // Here we declare any emulated L1 bits 
  Int_t           OpenL1_ZeroBias;
  Int_t           OpenL1_Mu3EG5; 
  Int_t           OpenL1_EG5_HTT100; 
  Int_t           OpenL1_SingleMu30;  
  Int_t           OpenL1_SingleCenJet2; 
  Int_t           OpenL1_SingleCenJet4; 
  Int_t           OpenL1_SingleForJet2; 
  Int_t           OpenL1_SingleForJet4; 
  Int_t           OpenL1_SingleTauJet2; 
  Int_t           OpenL1_SingleTauJet4; 
  Int_t           OpenL1_DoubleForJet10_EtaOpp; 


  // JH - 1E31 MC menu
  Int_t           HLT_L1Jet15; 
  Int_t           HLT_Jet30; 
  Int_t           HLT_Jet50; 
  Int_t           HLT_Jet80; 
  Int_t           HLT_Jet110; 
  Int_t           HLT_Jet140; 
  Int_t           HLT_Jet180; 
  Int_t           HLT_FwdJet40; 
  Int_t           HLT_DiJetAve15U_1E31; 
  Int_t           HLT_DiJetAve30U_1E31; 
  Int_t           HLT_DiJetAve50U; 
  Int_t           HLT_DiJetAve70U; 
  Int_t           HLT_DiJetAve130U; 
  Int_t           HLT_QuadJet30; 
  Int_t           HLT_SumET120; 
  Int_t           HLT_L1MET20; 
  Int_t           HLT_MET35; 
  Int_t           HLT_MET60; 
  Int_t           HLT_HT200; 
  Int_t           HLT_HT300_MHT100; 
  Int_t           HLT_L1MuOpen; 
  Int_t           HLT_L1Mu; 
  Int_t           HLT_L1Mu20HQ; 
  Int_t           HLT_L1Mu30; 
  Int_t           HLT_IsoMu9; 
  Int_t           HLT_Mu5; 
  Int_t           HLT_Mu9; 
  Int_t           HLT_Mu11; 
  Int_t           HLT_Mu15; 
  Int_t           HLT_DoubleMu3; 
  Int_t           HLT_Ele10_SW_L1R; 
  Int_t           HLT_Ele15_SW_L1R; 
  Int_t           HLT_Ele15_SW_EleId_L1R; 
  Int_t           HLT_Ele15_SW_LooseTrackIso_L1R; 
  Int_t           HLT_Ele15_SC15_SW_LooseTrackIso_L1R; 
  Int_t           HLT_Ele15_SC15_SW_EleId_L1R; 
  Int_t           HLT_Ele20_SW_L1R; 
  Int_t           HLT_Ele20_SiStrip_L1R; 
  Int_t           HLT_Ele20_SC15_SW_L1R; 
  Int_t           HLT_Ele25_SW_L1R; 
  Int_t           HLT_Ele25_SW_EleId_LooseTrackIso_L1R; 
  Int_t           HLT_DoubleEle5_SW_Jpsi_L1R; 
  Int_t           HLT_DoubleEle5_SW_Upsilon_L1R; 
  Int_t           HLT_DoubleEle10_SW_L1R; 
  Int_t           HLT_Photon10_LooseEcalIso_TrackIso_L1R; 
  Int_t           HLT_Photon15_L1R; 
  Int_t           HLT_Photon20_LooseEcalIso_TrackIso_L1R; 
  Int_t           HLT_Photon25_L1R; 
  Int_t           HLT_Photon25_LooseEcalIso_TrackIso_L1R; 
  Int_t           HLT_Photon30_L1R_1E31; 
  Int_t           HLT_Photon70_L1R; 
  Int_t           HLT_DoublePhoton15_L1R; 
  Int_t           HLT_DoublePhoton15_VeryLooseEcalIso_L1R; 
  Int_t           HLT_SingleIsoTau30_Trk5; 
  Int_t           HLT_DoubleLooseIsoTau15_Trk5; 
  Int_t           HLT_BTagIP_Jet80; 
  Int_t           HLT_BTagMu_Jet20; 
  Int_t           HLT_BTagIP_Jet120; 
  Int_t           HLT_StoppedHSCP_1E31; 
  Int_t           HLT_L1Mu14_L1SingleJet15; 
  Int_t           HLT_L1Mu14_L1ETM40; 
  Int_t           HLT_L2Mu5_Photon9_L1R; 
  Int_t           HLT_L2Mu9_DiJet30; 
  Int_t           HLT_L2Mu8_HT50; 
  Int_t           HLT_Ele10_SW_L1R_TripleJet30; 
  Int_t           HLT_Ele10_LW_L1R_HT180; 
  Int_t           HLT_ZeroBias; 
  Int_t           HLT_MinBiasHcal; 
  Int_t           HLT_MinBiasEcal; 
  Int_t           HLT_MinBiasPixel; 
  Int_t           HLT_MinBiasPixel_Trk5; 
  Int_t           HLT_ZeroBiasPixel_SingleTrack; 
  Int_t           HLT_CSCBeamHalo; 
  Int_t           HLT_CSCBeamHaloOverlapRing1; 
  Int_t           HLT_CSCBeamHaloOverlapRing2; 
  Int_t           HLT_CSCBeamHaloRing2or3; 
  Int_t           HLT_BackwardBSC; 
  Int_t           HLT_ForwardBSC; 
  Int_t           HLT_TrackerCosmics; 
  Int_t           HLT_IsoTrack_1E31; 
  Int_t           AlCa_EcalPhiSym; 
  Int_t           AlCa_EcalPi0_1E31; 
  Int_t           AlCa_EcalEta_1E31; 

  // 8E29 menu
  Int_t           HLT_L1Jet6U;
  Int_t           HLT_Jet15U;
  Int_t           HLT_Jet30U;
  Int_t           HLT_Jet50U;
  Int_t           HLT_FwdJet20U;
  Int_t           HLT_DiJetAve15U_8E29;
  Int_t           HLT_DiJetAve30U_8E29;
  Int_t           HLT_QuadJet15U;
  Int_t           HLT_MET45;
  Int_t           HLT_MET100;
  Int_t           HLT_HT100U;
  Int_t           HLT_L1Mu20;
  Int_t           HLT_L2Mu9;
  Int_t           HLT_L2Mu11;
  Int_t           HLT_Mu3; 
  Int_t           HLT_IsoMu3;
  Int_t           HLT_L1DoubleMuOpen;
  Int_t           HLT_DoubleMu0;
  Int_t           HLT_L1SingleEG5;
  Int_t           HLT_L1SingleEG8;
  Int_t           HLT_Ele10_LW_L1R;
  Int_t           HLT_Ele10_LW_EleId_L1R;
  Int_t           HLT_Ele15_LW_L1R; 
  Int_t           HLT_Ele15_SC10_LW_L1R;
  Int_t           HLT_Ele15_SiStrip_L1R;
  Int_t           HLT_Ele20_LW_L1R;
  Int_t           HLT_L1DoubleEG5;
  Int_t           HLT_DoubleEle5_SW_L1R;
  Int_t           HLT_DoublePhoton5_eeRes_L1R;
  Int_t           HLT_DoublePhoton5_Jpsi_L1R;
  Int_t           HLT_DoublePhoton5_Upsilon_L1R;
  Int_t           HLT_Photon10_L1R;
  Int_t           HLT_Photon15_TrackIso_L1R;
  Int_t           HLT_Photon15_LooseEcalIso_L1R;
  Int_t           HLT_Photon20_L1R;
  Int_t           HLT_Photon30_L1R_8E29;
  Int_t           HLT_DoublePhoton10_L1R;
  Int_t           HLT_SingleLooseIsoTau20;
  Int_t           HLT_DoubleLooseIsoTau15;
  Int_t           HLT_BTagMu_Jet10U;
  Int_t           HLT_BTagIP_Jet50U;
  Int_t           HLT_StoppedHSCP_8E29;
  Int_t           HLT_L1Mu14_L1SingleEG10;
  Int_t           HLT_L1Mu14_L1SingleJet6U;
  Int_t           HLT_L1Mu14_L1ETM30;
  Int_t           HLT_IsoTrack_8E29;
  Int_t           AlCa_HcalPhiSym;
  Int_t           AlCa_EcalPi0_8E29;
  Int_t           AlCa_EcalEta_8E29;
  Int_t           AlCa_RPCMuonNoHits;
  Int_t           AlCa_RPCMuonNormalisation;  

  // Commissioning and other HLT Paths for the CRAFT09 cosmics menu
  Int_t           HLT_Random;
  Int_t           HLT_L2Mu3_NoVertex;
  Int_t           HLT_OIstateTkMu3;
  Int_t           HLT_TrackPointing;
  Int_t           HLT_EgammaSuperClusterOnly_L1R;
  Int_t           AlCa_EcalPi0_Cosmics; 
  Int_t           AlCa_EcalEta_Cosmics; 
  Int_t           HLT_DataIntegrity; 
  Int_t           HLT_L1_BPTX; 
  Int_t           HLT_L1_BSC; 
  Int_t           HLT_L1_HFtech; 
  Int_t           HLT_HFThreshold; 
  Int_t           HLT_Physics;
  Int_t           HLT_PhysicsNoMuon;
  Int_t           HLT_Calibration; 
  Int_t           HLT_EcalCalibration;
  Int_t           HLT_PixelFEDSize; 
  Int_t           HLT_GlobalRunHPDNoise; 



  
  // HLT paths for the 2009 Circulating Beam menu 
  Int_t           HLT_L2Mu0_NoVertex;
  Int_t           HLT_TkMu3_NoVertex;
  Int_t           HLT_IsoTrackHB_8E29;
  Int_t           HLT_IsoTrackHE_8E29;
  Int_t           HLT_IsoTrackHB_1E31; 
  Int_t           HLT_IsoTrackHE_1E31; 
  Int_t           HLT_MinBiasPixel_DoubleIsoTrack5;
  Int_t           HLT_MinBiasPixel_DoubleTrack;
  Int_t           HLT_MinBiasPixel_SingleTrack;
  Int_t           HLT_TechTrigHCALNoise;
  Int_t           HLT_HcalNZS_8E29;
  Int_t           HLT_HcalPhiSym;
  Int_t           HLT_HcalNZS;

  // Add-ons for Circulation beam v2 (2009Nov18)
  Int_t           HLT_DTErrors;
  Int_t           HLT_HcalCalibration;
  Int_t           HLT_LogMonitor;
  Int_t           HLT_Activity_PixelClusters;
  Int_t           HLT_Activity_Ecal;
  Int_t           HLT_Activity_EcalREM;
  Int_t           HLT_L1SingleEG2_NoBPTX;
  Int_t           HLT_RPCBarrelCosmics;
  Int_t           HLT_L1_BPTX_MinusOnly;
  Int_t           HLT_L1_BPTX_PlusOnly;
  Int_t           HLT_Activity_L1A;
  Int_t           HLT_L1SingleForJet;
  Int_t           HLT_L1SingleEG2;
  Int_t           HLT_MinBias;
  Int_t           HLT_MinBiasBSC;
  Int_t           HLT_MinBiasBSC_OR;
  Int_t           HLT_HighMultiplicityBSC;

  // Splash Feb 2010
  Int_t          HLT_SplashEcalSumET;
  Int_t          HLT_L1SingleEG20;

  // Autogenerated from ConfDB - Int_t
  Int_t           HLT_DiJetAve50U_8E29;
  Int_t           HLT_L1DoubleMuOpen_Tight;
  Int_t           HLT_Photon15_TrackIso_Cleaned_L1R;
  Int_t           HLT_Photon15_LooseEcalIso_Cleaned_L1R;
  Int_t           HLT_SingleLooseIsoTau20_Trk5;
  Int_t           HLT_SingleLooseIsoTau25;
  Int_t           HLT_MultiVertex6;
  Int_t           HLT_MultiVertex8_L1ETT60;
  Int_t           HLT_PixelTracks_Multiplicity85;
  Int_t           HLT_L1Tech_BSC_minBias;
  Int_t           HLT_Activity_CSC;
  Int_t           HLT_Activity_Ecal_SC7;
  Int_t           HLT_Activity_Ecal_SC15;
  Int_t           HLT_L1MuOpen_DT;
  Int_t           HLT_Photon10_Cleaned_L1R;
  Int_t           HLT_Photon15_Cleaned_L1R;
  Int_t           HLT_Photon20_Cleaned_L1R;
  Int_t           HLT_L1Tech_BSC_HighMultiplicity;
  Int_t           HLT_PixelTracks_Multiplicity40;
  Int_t           HLT_L1SingleForJet_BPTX;
  Int_t           HLT_L1Jet6U_BPTX;
  Int_t           HLT_L1Jet10U_BPTX;
  Int_t           HLT_L1MuOpen_BPTX;
  Int_t           HLT_L1_BptxXOR_BscMinBiasOR;
  Int_t           HLT_L1SingleCenJet_BPTX;
  Int_t           HLT_MinBiasBSC_BPTX;
  Int_t           HLT_L1Tech_HCAL_HF;
  Int_t           HLT_L1SingleTauJet_BPTX;
  Int_t           HLT_PixelTracks_Multiplicity70;
  Int_t           HLT_Jet15U_HcalNoiseFiltered;
  Int_t           HLT_L2Mu5;
  Int_t           HLT_L1_BscMinBiasOR_BeamGas;
  Int_t           HLT_L1Tech_BSC_halo;
  Int_t           HLT_L1Tech_BSC_halo_forPhysicsBackground;
  Int_t           HLT_HFThreshold3;
  Int_t           HLT_HFThreshold10;
  Int_t           HLT_Activity_DT;
  Int_t           HLT_Activity_DT_Tuned;
  Int_t           HLT_Activity_HF3;
  Int_t           HLT_Activity_HF10;
  Int_t           HLT_MultiTowerEcal;
  Int_t           HLT_SelectEcalSpikes_L1R;
  Int_t           HLT_SelectEcalSpikesHighEt_L1R;
  Int_t           HLT_L1Jet6U_NoBPTX;
  Int_t           HLT_L1Jet10U;
  Int_t           HLT_L1Jet10U_NoBPTX;
  Int_t           HLT_L1SingleForJet_NoBPTX;
  Int_t           HLT_L1SingleCenJet;
  Int_t           HLT_L1SingleCenJet_NoBPTX;
  Int_t           HLT_L1SingleTauJet;
  Int_t           HLT_L1SingleTauJet_NoBPTX;
  Int_t           HLT_DoubleFwdJet50;
  Int_t           HLT_QuadJet60;
  Int_t           HLT_L1MuOpen_NoBPTX;
  Int_t           HLT_L1MuOpen_AntiBPTX;
  Int_t           HLT_L1SingleEG1;
  Int_t           HLT_L1SingleEG1_NoBPTX;
  Int_t           HLT_L1SingleEG5_NoBPTX;
  Int_t           HLT_L1SingleEG20_NoBPTX;
  Int_t           HLT_Ele20_SW_EleId_LooseTrackIso_L1R;
  Int_t           HLT_Ele25_LW_L1R;
  Int_t           HLT_DoublePhoton4_eeRes_L1R;
  Int_t           HLT_DoublePhoton4_Jpsi_L1R;
  Int_t           HLT_DoublePhoton4_Upsilon_L1R;
  Int_t           HLT_DoublePhoton5_L1R;
  Int_t           HLT_L1Mu14_L1SingleJet20;
  Int_t           HLT_MinBiasBSC_NoBPTX;
  Int_t           HLT_SplashBSC;
  Int_t           HLT_L1_BscMinBiasOR_BptxPlusORMinus;
  Int_t           HLT_L1_BscMinBiasOR_BptxPlusORMinus_NoBPTX;
  Int_t           HLT_L1Tech_RPC_TTU_RBst1_collisions;
  Int_t           HLT_HcalNZS_1E31;
  Int_t           HLT_HIMinBiasCalo;
  Int_t           HLT_HIJet35U;
  Int_t           HLT_HIJet50U;
  Int_t           HLT_HIJet75U;
  Int_t           HLT_HIJet90U;
  Int_t           HLT_HIPhoton10;
  Int_t           HLT_HIPhoton15;
  Int_t           HLT_HIPhoton20;
  Int_t           HLT_HIPhoton30;
  Int_t           HLT_HighMult40;
  Int_t           HLT_L1Tech_HCAL_HF_coincidence_PM;
  Int_t           HLT_PhysicsDeclared;
  Int_t           HLT_Jet250;
  Int_t           HLT_DoubleJet15U_ForwardBackward;
  Int_t           HLT_DoubleJet150;
  Int_t           HLT_DoubleJet125_Aco;
  Int_t           HLT_TripleJet85;
  Int_t           HLT_MET25;
  Int_t           HLT_MET50;
  Int_t           HLT_MET75;
  Int_t           HLT_MET60_HT350;
  Int_t           HLT_HT240;
  Int_t           HLT_Jet180_MET60;
  Int_t           HLT_Jet60_MET70_Aco;
  Int_t           HLT_Jet100_MET60_Aco;
  Int_t           HLT_DoubleJet125_MET60;
  Int_t           HLT_DoubleFwdJet40_MET60;
  Int_t           HLT_DoubleJet60_MET60_Aco;
  Int_t           HLT_DoubleJet50_MET70_Aco;
  Int_t           HLT_DoubleJet40_MET70_Aco;
  Int_t           HLT_TripleJet60_MET60;
  Int_t           HLT_QuadJet35_MET60;
  Int_t           HLT_L2Mu0;
  Int_t           HLT_L2Mu3;
  Int_t           HLT_L2Mu15;
  Int_t           HLT_L2DoubleMu0;
  Int_t           HLT_IsoMu11;
  Int_t           HLT_IsoMu13;
  Int_t           HLT_IsoMu15;
  Int_t           HLT_Mu7;
  Int_t           HLT_Mu13;
  Int_t           HLT_DoubleIsoMu3;
  Int_t           HLT_DoubleMu3_Vtx2mm;
  Int_t           HLT_DoubleMu3_JPsi;
  Int_t           HLT_DoubleMu3_Upsilon;
  Int_t           HLT_DoubleMu7_Z;
  Int_t           HLT_DoubleMu3_SameSign;
  Int_t           HLT_DoubleMu3_Psi2S;
  Int_t           HLT_Mu0_L1MuOpen;
  Int_t           HLT_Mu3_L1MuOpen;
  Int_t           HLT_Mu5_L1MuOpen;
  Int_t           HLT_Mu0_L2Mu0;
  Int_t           HLT_Mu3_L2Mu0;
  Int_t           HLT_Mu5_L2Mu0;
  Int_t           HLT_Mu0_Track0_Jpsi;
  Int_t           HLT_Mu3_Track0_Jpsi;
  Int_t           HLT_Mu5_Track0_Jpsi;
  Int_t           HLT_IsoMu7_BTagIP_Jet35;
  Int_t           HLT_IsoMu7_BTagMu_Jet20;
  Int_t           HLT_IsoMu7_Jet40;
  Int_t           HLT_IsoMu14_IsoTau15_Trk3;
  Int_t           HLT_IsoMu14_IsoTau15_Trk3_NoL1;
  Int_t           HLT_IsoMu14_LooseIsoTau15_NoL25;
  Int_t           HLT_IsoMu14_LooseIsoTau15_Trk3_NoL2;
  Int_t           HLT_NoL2IsoMu8_Jet40;
  Int_t           HLT_Mu14_Jet50;
  Int_t           HLT_Mu5_TripleJet30;
  Int_t           HLT_L2Mu7_Photon9_L1R;
  Int_t           HLT_Ele10_LW_L1R_HT200;
  Int_t           AlCa_RPCMuonNoTriggers;
  Int_t           HLT_HIDoubleMu;
  Int_t           HLT_DoublePhoton5_CEP_L1R;
  Int_t           HLT_ZeroBias1kHz;

  // Add-ons for Circulation beam v2 (2009Nov18)
  TBranch        *b_HLT_DTErrors;   //!
  TBranch        *b_HLT_HcalCalibration;   //!
  TBranch        *b_HLT_LogMonitor;   //!
  TBranch        *b_HLT_Activity_PixelClusters;   //!
  TBranch        *b_HLT_Activity_Ecal;   //!
  TBranch        *b_HLT_Activity_EcalREM;   //!
  TBranch        *b_HLT_L1SingleEG2_NoBPTX;   //!
  TBranch        *b_HLT_RPCBarrelCosmics;   //!
  TBranch        *b_HLT_L1_BPTX_MinusOnly;   //!
  TBranch        *b_HLT_L1_BPTX_PlusOnly;   //!
  TBranch        *b_HLT_Activity_L1A;   //!
  TBranch        *b_HLT_L1SingleForJet;   //!
  TBranch        *b_HLT_L1SingleEG2;   //!
  TBranch        *b_HLT_MinBias;   //!
  TBranch        *b_HLT_MinBiasBSC;   //!
  TBranch        *b_HLT_MinBiasBSC_OR;   //!
  TBranch        *b_HLT_HighMultiplicityBSC;   //!
  TBranch        *b_NohPixelTracksL3;   //!
  TBranch        *b_ohPixelTracksL3Pt;    //!
  TBranch        *b_ohPixelTracksL3Eta;   //!
  TBranch        *b_ohPixelTracksL3Phi;    //!
  TBranch        *b_ohPixelTracksL3Vz;    //!

  
  // List of branches
  TBranch        *b_NrecoJetCal;   //!
  TBranch        *b_NrecoJetGen;   //!
  TBranch        *b_NrecoTowCal;   //!
  TBranch        *b_NrecoJetCorCal; //!
  TBranch        *b_recoJetCalPt;   //!
  TBranch        *b_recoJetCalPhi;   //!
  TBranch        *b_recoJetCalEta;   //!
  TBranch        *b_recoJetCalEt;   //!
  TBranch        *b_recoJetCalE;   //!
  TBranch        *b_recoJetGenPt;   //!
  TBranch        *b_recoJetGenPhi;   //!
  TBranch        *b_recoJetGenEta;   //!
  TBranch        *b_recoJetGenEt;   //!
  TBranch        *b_recoJetGenE;   //!
  TBranch        *b_recoTowEt;   //!
  TBranch        *b_recoTowEta;   //!
  TBranch        *b_recoTowPhi;   //!
  TBranch        *b_recoTowE;   //!
  TBranch        *b_recoTowEm;   //!
  TBranch        *b_recoTowHad;   //!
  TBranch        *b_recoTowOE;   //!
  TBranch        *b_recoMetCal;   //!
  TBranch        *b_recoMetCalPhi;   //!
  TBranch        *b_recoMetCalSum;   //!
  TBranch        *b_recoMetGen;   //!
  TBranch        *b_recoMetGenPhi;   //!
  TBranch        *b_recoMetGenSum;   //!
  TBranch        *b_recoHTCal;   //!
  TBranch        *b_recoHTCalPhi;   //!
  TBranch        *b_recoHTCalSum;   //!
  TBranch        *b_recoJetCorCalPt;   //!
  TBranch        *b_recoJetCorCalPhi;   //!
  TBranch        *b_recoJetCorCalEta;   //!
  TBranch        *b_recoJetCorCalE;   //!
  TBranch        *b_NohTau;   //!
  TBranch        *b_ohTauEta;   //!
  TBranch        *b_ohTauPhi;   //!
  TBranch        *b_ohTauPt;   //!
  TBranch        *b_ohTauEiso;   //!
  TBranch        *b_ohTauL25Tpt;   //!
  TBranch        *b_ohTauL25Tiso;   //!
  TBranch        *b_ohTauL3Tpt;   //!
  TBranch        *b_ohTauL3Tiso;   //!
  TBranch        *b_NohBJetLife;   //!
  TBranch        *b_ohBJetLifeL2E;   //!
  TBranch        *b_ohBJetLifeL2ET;   //!
  TBranch        *b_ohBJetLifeL2Eta;   //!
  TBranch        *b_ohBJetLifeL2Phi;   //!
  TBranch        *b_ohBJetLifeL25Discriminator;   //!
  TBranch        *b_ohBJetLifeL3Discriminator;   //!
  TBranch        *b_NohBJetPixelTracks;   //!
  TBranch        *b_ohBJetLifePixelTrackPt;   //!
  TBranch        *b_ohBJetLifePixelTrackEta;   //!
  TBranch        *b_ohBJetLifePixelTrackPhi;   //!
  TBranch        *b_ohBJetLifePixelTrackChi2;   //!
  TBranch        *b_NohBJetRegionalTracks;   //!
  TBranch        *b_ohBJetLifeRegionalTrackPt;   //!
  TBranch        *b_ohBJetLifeRegionalTrackEta;   //!
  TBranch        *b_ohBJetLifeRegionalTrackPhi;   //!
  TBranch        *b_ohBJetLifeRegionalTrackChi2;   //!
  TBranch        *b_ohBJetLifeRegionalSeedPt;   //!
  TBranch        *b_ohBJetLifeRegionalSeedEta;   //!
  TBranch        *b_ohBJetLifeRegionalSeedPhi;   //!
  TBranch        *b_NohBJetSoftm;   //!
  TBranch        *b_ohBJetSoftmL2E;   //!
  TBranch        *b_ohBJetSoftmL2ET;   //!
  TBranch        *b_ohBJetSoftmL2Eta;   //!
  TBranch        *b_ohBJetSoftmL2Phi;   //!
  TBranch        *b_ohBJetSoftmL25Discriminator;   //!
  TBranch        *b_ohBJetSoftmL3Discriminator;   //!
  TBranch        *b_ohBJetPerfL2E;   //!
  TBranch        *b_ohBJetPerfL2ET;   //!
  TBranch        *b_ohBJetPerfL2Eta;   //!
  TBranch        *b_ohBJetPerfL2Phi;   //!
  TBranch        *b_NohBJetL2;   //! 
  TBranch        *b_ohBJetL2Energy;   //! 
  TBranch        *b_ohBJetL2Et;   //! 
  TBranch        *b_ohBJetL2Pt;   //! 
  TBranch        *b_ohBJetL2Eta;   //! 
  TBranch        *b_ohBJetL2Phi;   //! 
  TBranch        *b_NohBJetL2Corrected;   //! 
  TBranch        *b_ohBJetL2CorrectedEnergy;   //! 
  TBranch        *b_ohBJetL2CorrectedEt;   //! 
  TBranch        *b_ohBJetL2CorrectedPt;   //! 
  TBranch        *b_ohBJetL2CorrectedEta;   //! 
  TBranch        *b_ohBJetL2CorrectedPhi;   //! 
  TBranch        *b_ohBJetIPL25Tag;   //! 
  TBranch        *b_ohBJetIPL3Tag;   //! 
  TBranch        *b_ohBJetIPLooseL25Tag;   //! 
  TBranch        *b_ohBJetIPLooseL3Tag;   //! 
  TBranch        *b_ohBJetMuL25Tag;   //! 
  TBranch        *b_ohBJetMuL3Tag;   //! 
  TBranch        *b_ohBJetPerfL25Tag;   //! 
  TBranch        *b_ohBJetPerfL3Tag;   //! 

  TBranch        *b_recoNVrt;    //!
  TBranch        *b_recoVrtX;    //!
  TBranch        *b_recoVrtY;    //!
  TBranch        *b_recoVrtZ;    //!
  TBranch        *b_recoVrtNtrk;    //!
  TBranch        *b_recoVrtChi2;    //!
  TBranch        *b_recoVrtNdof;    //!


  TBranch        *b_NrecoElec;   //!
  TBranch        *b_recoElecPt;   //!
  TBranch        *b_recoElecPhi;   //!
  TBranch        *b_recoElecEta;   //!
  TBranch        *b_recoElecEt;   //!
  TBranch        *b_recoElecE;   //!
  TBranch        *b_NrecoPhot;   //!
  TBranch        *b_recoPhotPt;   //!
  TBranch        *b_recoPhotPhi;   //!
  TBranch        *b_recoPhotEta;   //!
  TBranch        *b_recoPhotEt;   //!
  TBranch        *b_recoPhotE;   //!
  TBranch        *b_NohPhot;   //!
  TBranch        *b_ohPhotEt;   //!
  TBranch        *b_ohPhotEta;   //!
  TBranch        *b_ohPhotPhi;   //!
  TBranch        *b_ohPhotEiso;   //!
  TBranch        *b_ohPhotHiso;   //!
  TBranch        *b_ohPhotTiso;   //!
  TBranch        *b_ohPhotL1iso;   //!
  TBranch        *b_NohEle;   //!
  TBranch        *b_ohEleClusShap;   //!
  TBranch        *b_ohEleDeta;   //!
  TBranch        *b_ohEleDphi;   //!
  TBranch        *b_ohEleEt;   //!
  TBranch        *b_ohEleEta;   //!
  TBranch        *b_ohElePhi;   //!
  TBranch        *b_ohEleE;   //!
  TBranch        *b_ohEleP;   //!
  TBranch        *b_ohEleHiso;   //!
  TBranch        *b_ohEleTiso;   //!
  TBranch        *b_ohEleL1iso;   //!
  TBranch        *b_ohElePixelSeeds;   //!
  TBranch        *b_ohEleNewSC;   //!
  TBranch        *b_NohEleLW;   //!
  TBranch        *b_ohEleClusShapLW;   //!
  TBranch        *b_ohEleDetaLW;   //!
  TBranch        *b_ohEleDphiLW;   //!
  TBranch        *b_ohEleEtLW;   //!
  TBranch        *b_ohEleEtaLW;   //!
  TBranch        *b_ohElePhiLW;   //!
  TBranch        *b_ohEleELW;   //!
  TBranch        *b_ohElePLW;   //!
  TBranch        *b_ohEleHisoLW;   //!
  TBranch        *b_ohEleTisoLW;   //!
  TBranch        *b_ohEleL1isoLW;   //!
  TBranch        *b_ohElePixelSeedsLW;   //!
  TBranch        *b_ohEleNewSCLW;   //!
  TBranch        *b_NrecoMuon;   //!
  TBranch        *b_recoMuonPt;   //!
  TBranch        *b_recoMuonPhi;   //!
  TBranch        *b_recoMuonEta;   //!
  TBranch        *b_recoMuonEt;   //!
  TBranch        *b_recoMuonE;   //!
  TBranch        *b_NohMuL2;   //!
  TBranch        *b_ohMuL2Pt;   //!
  TBranch        *b_ohMuL2Phi;   //!
  TBranch        *b_ohMuL2Eta;   //!
  TBranch        *b_ohMuL2Chg;   //!
  TBranch        *b_ohMuL2PtErr;   //!
  TBranch        *b_ohMuL2Iso;   //!
  TBranch        *b_ohMuL2Dr;   //!
  TBranch        *b_ohMuL2Dz;   //!
  TBranch        *b_NohMuL3;   //!
  TBranch        *b_ohMuL3Pt;   //!
  TBranch        *b_ohMuL3Phi;   //!
  TBranch        *b_ohMuL3Eta;   //!
  TBranch        *b_ohMuL3Chg;   //!
  TBranch        *b_ohMuL3PtErr;   //!
  TBranch        *b_ohMuL3Iso;   //!
  TBranch        *b_ohMuL3Dr;   //!
  TBranch        *b_ohMuL3Dz;   //!
  TBranch        *b_ohMuL3L2idx;   //!
  TBranch        *b_NohOniaPixel;   //!
  TBranch        *b_ohOniaPixelPt;   //!
  TBranch        *b_ohOniaPixelPhi;   //!
  TBranch        *b_ohOniaPixelEta;   //!
  TBranch        *b_ohOniaPixelChg;   //!
  TBranch        *b_ohOniaPixelDr;   //!
  TBranch        *b_ohOniaPixelDz;   //!
  TBranch        *b_ohOniaPixelHits;   //!
  TBranch        *b_ohOniaPixelNormChi2;   //!
  TBranch        *b_NohOniaTrack;   //!
  TBranch        *b_ohOniaTrackPt;   //!
  TBranch        *b_ohOniaTrackPhi;   //!
  TBranch        *b_ohOniaTrackEta;   //!
  TBranch        *b_ohOniaTrackChg;   //!
  TBranch        *b_ohOniaTrackDr;   //!
  TBranch        *b_ohOniaTrackDz;   //!
  TBranch        *b_ohOniaTrackHits;   //!
  TBranch        *b_ohOniaTrackNormChi2;   //!
  TBranch        *b_ohHighestEnergyEERecHit;   //! 
  TBranch        *b_ohHighestEnergyEBRecHit;   //! 
  TBranch        *b_ohHighestEnergyHBHERecHit;   //! 
  TBranch        *b_ohHighestEnergyHORecHit;   //! 
  TBranch        *b_ohHighestEnergyHFRecHit;   //! 
  TBranch        *b_Nalcapi0clusters;   //! 
  TBranch        *b_ohAlcapi0ptClusAll;   //! 
  TBranch        *b_ohAlcapi0etaClusAll;   //! 
  TBranch        *b_ohAlcapi0phiClusAll;   //! 
  TBranch        *b_ohAlcapi0s4s9ClusAll;   //! 
  TBranch        *b_NMCpart;   //!
  TBranch        *b_MCpid;   //!
  TBranch        *b_MCstatus;   //!
  TBranch        *b_MCvtxX;   //!
  TBranch        *b_MCvtxY;   //!
  TBranch        *b_MCvtxZ;   //!
  TBranch        *b_MCpt;   //!
  TBranch        *b_MCeta;   //!
  TBranch        *b_MCphi;   //!
  TBranch        *b_MCPtHat;   //!
  TBranch        *b_MCmu3;   //!
  TBranch        *b_MCel3;   //!
  TBranch        *b_MCbb;   //!
  TBranch        *b_MCab;   //!
  TBranch        *b_MCWenu;   //!
  TBranch        *b_MCmunu;   //!
  TBranch        *b_MCZee;   //!
  TBranch        *b_MCZmumu;   //!
  TBranch        *b_MCptEleMax;   //!
  TBranch        *b_MCptMuMax;   //!
  TBranch        *b_NL1IsolEm;   //!
  TBranch        *b_L1IsolEmEt;   //!
  TBranch        *b_L1IsolEmE;   //!
  TBranch        *b_L1IsolEmEta;   //!
  TBranch        *b_L1IsolEmPhi;   //!
  TBranch        *b_NL1NIsolEm;   //!
  TBranch        *b_L1NIsolEmEt;   //!
  TBranch        *b_L1NIsolEmE;   //!
  TBranch        *b_L1NIsolEmEta;   //!
  TBranch        *b_L1NIsolEmPhi;   //!
  TBranch        *b_NL1Mu;   //!
  TBranch        *b_L1MuPt;   //!
  TBranch        *b_L1MuE;   //!
  TBranch        *b_L1MuEta;   //!
  TBranch        *b_L1MuPhi;   //!
  TBranch        *b_L1MuIsol;   //!
  TBranch        *b_L1MuMip;   //!
  TBranch        *b_L1MuFor;   //!
  TBranch        *b_L1MuRPC;   //!
  TBranch        *b_L1MuQal;   //!
  TBranch        *b_NL1CenJet;   //!
  TBranch        *b_L1CenJetEt;   //!
  TBranch        *b_L1CenJetE;   //!
  TBranch        *b_L1CenJetEta;   //!
  TBranch        *b_L1CenJetPhi;   //!
  TBranch        *b_NL1ForJet;   //!
  TBranch        *b_L1ForJetEt;   //!
  TBranch        *b_L1ForJetE;   //!
  TBranch        *b_L1ForJetEta;   //!
  TBranch        *b_L1ForJetPhi;   //!
  TBranch        *b_NL1Tau;   //!
  TBranch        *b_L1TauEt;   //!
  TBranch        *b_L1TauE;   //!
  TBranch        *b_L1TauEta;   //!
  TBranch        *b_L1TauPhi;   //!
  TBranch        *b_L1Met;   //!
  TBranch        *b_L1MetPhi;   //!
  TBranch        *b_L1MetTot;   //!
  TBranch        *b_L1MetHad;   //!
  TBranch        *b_L1HfRing0EtSumPositiveEta;   //!
  TBranch        *b_L1HfRing1EtSumPositiveEta;   //!
  TBranch        *b_L1HfRing0EtSumNegativeEta;   //!
  TBranch        *b_L1HfRing1EtSumNegativeEta;   //!
  TBranch        *b_L1HfTowerCountPositiveEta;   //!
  TBranch        *b_L1HfTowerCountNegativeEta;   //!
  TBranch        *b_Run;   //!
  TBranch        *b_Event;   //!
  TBranch        *b_LumiBlock;  //!
  TBranch        *b_Bx;  //!
  TBranch        *b_Orbit;  //!

  TBranch        *b_L1_DoubleMuTopBottom;   //! 
  TBranch        *b_L1_DoubleEG05_TopBottom;   //! 
  TBranch           *b_L1_SingleJet20;   //! 
  TBranch           *b_L1_SingleJet40;   //! 
  TBranch           *b_L1_SingleJet60;   //! 
  TBranch           *b_L1_DoubleJet30;   //!  
  TBranch           *b_L1_SingleTauJet10;   //! 
  TBranch           *b_L1_SingleTauJet20;   //! 
  TBranch           *b_L1_SingleTauJet50;   //! 
  TBranch           *b_L1_DoubleTauJet14;   //! 
  TBranch        *b_L1_IsoEG10_Jet6_ForJet6;   //! 

  //L1's
  TBranch        *b_L1_Mu5_Jet6;   //!
  TBranch        *b_L1_EG5_TripleJet6; //!   
  TBranch        *b_L1_SingleJet6; //!  
  TBranch        *b_L1_SingleJet10; //!
  TBranch        *b_L1_ETM30; //!  
  TBranch        *b_L1_QuadJet6;   //! 
  TBranch        *b_L1_TripleJet14;   //!  
  TBranch        *b_L1_DoubleEG1;   //! 
  TBranch        *b_L1_DoubleEG2;   //! 
  TBranch        *b_L1_DoubleEG5;   //! 
  TBranch        *b_L1_DoubleHfBitCountsRing1_P1N1;   //! 
  TBranch        *b_L1_DoubleHfBitCountsRing2_P1N1;   //! 
  TBranch        *b_L1_DoubleHfRingEtSumsRing1_P200N200;   //! 
  TBranch        *b_L1_DoubleHfRingEtSumsRing1_P4N4;   //! 
  TBranch        *b_L1_DoubleHfRingEtSumsRing2_P200N200;   //! 
  TBranch        *b_L1_DoubleHfRingEtSumsRing2_P4N4;   //! 
  TBranch        *b_L1_DoubleJet70;   //! 
  TBranch        *b_L1_DoubleMu3;   //! 
  TBranch        *b_L1_DoubleMuOpen;   //! 
  TBranch        *b_L1_DoubleTauJet30;   //! 
  TBranch        *b_L1_EG10_Jet15;   //! 
  TBranch        *b_L1_EG5_TripleJet15;   //! 
  TBranch        *b_L1_ETM20;   //! 
  TBranch        *b_L1_ETM40;   //! 
  TBranch        *b_L1_ETM70;   //! 
  TBranch        *b_L1_ETM80;   //! 
  TBranch        *b_L1_ETT60;   //! 
  TBranch        *b_L1_HTT50;   //! 
  TBranch        *b_L1_HTT100;   //! 
  TBranch        *b_L1_HTT200;   //! 
  TBranch        *b_L1_HTT300;   //! 
  TBranch        *b_L1_IsoEG10_Jet15_ForJet10;   //! 
  TBranch        *b_L1_MinBias_HTT10;   //! 
  TBranch        *b_L1_Mu3QE8_EG5;   //!
  TBranch        *b_L1_Mu3QE8_Jet15;   //!  
  TBranch        *b_L1_Mu5QE8_Jet15;   //! 
  TBranch        *b_L1_Mu3QE8_Jet6;   //!  
  TBranch        *b_L1_Mu5QE8_Jet6;   //! 
  TBranch        *b_L1_QuadJet15;   //! 
  TBranch        *b_L1_SingleEG1;   //! 
  TBranch        *b_L1_SingleEG10;   //! 
  TBranch        *b_L1_SingleEG12;   //! 
  TBranch        *b_L1_SingleEG15;   //! 
  TBranch        *b_L1_SingleEG2;   //! 
  TBranch        *b_L1_SingleEG20;   //! 
  TBranch        *b_L1_SingleEG5;   //! 
  TBranch        *b_L1_SingleEG8;   //! 
  TBranch        *b_L1_SingleHfBitCountsRing1_1;   //! 
  TBranch        *b_L1_SingleHfBitCountsRing2_1;   //! 
  TBranch        *b_L1_SingleHfRingEtSumsRing1_200;   //! 
  TBranch        *b_L1_SingleHfRingEtSumsRing1_4;   //! 
  TBranch        *b_L1_SingleHfRingEtSumsRing2_200;   //! 
  TBranch        *b_L1_SingleHfRingEtSumsRing2_4;   //! 
  TBranch        *b_L1_SingleIsoEG10;   //! 
  TBranch        *b_L1_SingleIsoEG12;   //! 
  TBranch        *b_L1_SingleIsoEG15;   //! 
  TBranch        *b_L1_SingleIsoEG5;   //! 
  TBranch        *b_L1_SingleIsoEG8;   //! 
  TBranch        *b_L1_SingleJet100;   //! 
  TBranch        *b_L1_SingleJet15;   //! 
  TBranch        *b_L1_SingleJet30;   //! 
  TBranch        *b_L1_SingleJet50;   //! 
  TBranch        *b_L1_SingleJet70;   //! 
  TBranch        *b_L1_SingleMu0;   //! 
  TBranch        *b_L1_SingleMu10;   //! 
  TBranch        *b_L1_SingleMu14;   //! 
  TBranch        *b_L1_SingleMu20;   //! 
  TBranch        *b_L1_SingleMu3;   //! 
  TBranch        *b_L1_SingleMu5;   //! 
  TBranch        *b_L1_SingleMu7;   //! 
  TBranch        *b_L1_SingleMuBeamHalo;   //! 
  TBranch        *b_L1_SingleMuOpen;   //! 
  TBranch        *b_L1_SingleTauJet30;   //! 
  TBranch        *b_L1_SingleTauJet40;   //! 
  TBranch        *b_L1_SingleTauJet60;   //! 
  TBranch        *b_L1_SingleTauJet80;   //! 
  TBranch        *b_L1_TripleJet30;   //! 
  TBranch        *b_L1_ZeroBias;   //!
  TBranch        *b_L1_ZeroBias_Ext;   //!
  TBranch        *b_L1_SingleCenJet2;   //!    
  TBranch        *b_L1_SingleCenJet4;   //!    
  TBranch        *b_L1_SingleForJet2;   //!    
  TBranch        *b_L1_SingleForJet4;   //!    
  TBranch        *b_L1_SingleTauJet2;   //!    
  TBranch        *b_L1_SingleTauJet4;   //!    
  TBranch        *b_L1_DoubleForJet10_EtaOpp;   //!    

  // ccla - L1 Technical bits  (06Dec09)
  TBranch        *b_L1Tech_BPTX_minus_v0;   //!
  TBranch        *b_L1Tech_BPTX_minus_v0_5bx;   //!
  TBranch        *b_L1Tech_BPTX_minus_AND_not_plus_v0;   //!
  TBranch        *b_L1Tech_BPTX_minus_AND_not_plus_v0_5bx;   //!
  TBranch        *b_L1Tech_BPTX_plus_v0;   //!
  TBranch        *b_L1Tech_BPTX_plus_v0_5bx;   //!
  TBranch        *b_L1Tech_BPTX_plus_AND_NOT_minus_v0;   //!
  TBranch        *b_L1Tech_BPTX_plus_AND_NOT_minus_v0_5bx;   //!
  TBranch        *b_L1Tech_BPTX_plus_AND_minus_v0;   //!
  TBranch        *b_L1Tech_BPTX_plus_AND_minus_v0_5bx;   //!
  TBranch        *b_L1Tech_BPTX_plus_AND_minus_instance1_v0;   //!
  TBranch        *b_L1Tech_BPTX_plus_AND_minus_instance1_v0_5bx;   //!
  TBranch        *b_L1Tech_BPTX_plus_OR_minus_v0;   //!
  TBranch        *b_L1Tech_BPTX_plus_OR_minus_v0_5bx;   //!
  TBranch        *b_L1Tech_BPTX_quiet_v0;   //!
  TBranch        *b_L1Tech_BPTX_quiet_v0_5bx;   //!
  TBranch        *b_L1Tech_BSC_HighMultiplicity_v0;   //!
  TBranch        *b_L1Tech_BSC_HighMultiplicity_v0_5bx;   //!
  TBranch        *b_L1Tech_BSC_halo_beam1_inner_v0;   //!
  TBranch        *b_L1Tech_BSC_halo_beam1_inner_v0_5bx;   //!
  TBranch        *b_L1Tech_BSC_halo_beam1_outer_v0;   //!
  TBranch        *b_L1Tech_BSC_halo_beam1_outer_v0_5bx;   //!
  TBranch        *b_L1Tech_BSC_halo_beam2_inner_v0;   //!
  TBranch        *b_L1Tech_BSC_halo_beam2_inner_v0_5bx;   //!
  TBranch        *b_L1Tech_BSC_halo_beam2_outer_v0;   //!
  TBranch        *b_L1Tech_BSC_halo_beam2_outer_v0_5bx;   //!
  TBranch        *b_L1Tech_BSC_minBias_OR_v0;   //!
  TBranch        *b_L1Tech_BSC_minBias_OR_v0_5bx;   //!
  TBranch        *b_L1Tech_BSC_minBias_inner_threshold1_v0;   //!
  TBranch        *b_L1Tech_BSC_minBias_inner_threshold1_v0_5bx;   //!
  TBranch        *b_L1Tech_BSC_minBias_inner_threshold2_v0;   //!
  TBranch        *b_L1Tech_BSC_minBias_inner_threshold2_v0_5bx;   //!
  TBranch        *b_L1Tech_BSC_minBias_threshold1_v0;   //!
  TBranch        *b_L1Tech_BSC_minBias_threshold1_v0_5bx;   //!
  TBranch        *b_L1Tech_BSC_minBias_threshold2_v0;   //!
  TBranch        *b_L1Tech_BSC_minBias_threshold2_v0_5bx;   //!
  TBranch        *b_L1Tech_BSC_splash_beam1_v0;   //!
  TBranch        *b_L1Tech_BSC_splash_beam1_v0_5bx;   //!
  TBranch        *b_L1Tech_BSC_splash_beam2_v0;   //!
  TBranch        *b_L1Tech_BSC_splash_beam2_v0_5bx;   //!
  TBranch        *b_L1Tech_HCAL_HBHE_totalOR_v0;   //!
  TBranch        *b_L1Tech_HCAL_HBHE_totalOR_v0_5bx;   //!
  TBranch        *b_L1Tech_HCAL_HF_totalOR_coincidenceHFM_v0;   //!
  TBranch        *b_L1Tech_HCAL_HF_totalOR_coincidenceHFM_v0_5bx;   //!
  TBranch        *b_L1Tech_HCAL_HF_totalOR_coincidenceHFP_v0;   //!
  TBranch        *b_L1Tech_HCAL_HF_totalOR_coincidenceHFP_v0_5bx;   //!
  TBranch        *b_L1Tech_HCAL_HF_totalOR_minBias_v0;   //!
  TBranch        *b_L1Tech_HCAL_HF_totalOR_minBias_v0_5bx;   //!
  TBranch        *b_L1Tech_HCAL_HO_totalOR_v0;   //!
  TBranch        *b_L1Tech_HCAL_HO_totalOR_v0_5bx;   //!
  TBranch        *b_L1Tech_RPC_TTU_RB0_Cosmics_v0;   //!
  TBranch        *b_L1Tech_RPC_TTU_RB0_Cosmics_v0_5bx;   //!
  TBranch        *b_L1Tech_RPC_TTU_RBminus1_Cosmics_v0;   //!
  TBranch        *b_L1Tech_RPC_TTU_RBminus1_Cosmics_v0_5bx;   //!
  TBranch        *b_L1Tech_RPC_TTU_RBminus2_Cosmics_v0;   //!
  TBranch        *b_L1Tech_RPC_TTU_RBminus2_Cosmics_v0_5bx;   //!
  TBranch        *b_L1Tech_RPC_TTU_RBplus1_Cosmics_v0;   //!
  TBranch        *b_L1Tech_RPC_TTU_RBplus1_Cosmics_v0_5bx;   //!
  TBranch        *b_L1Tech_RPC_TTU_RBplus2_Cosmics_v0;   //!
  TBranch        *b_L1Tech_RPC_TTU_RBplus2_Cosmics_v0_5bx;   //!
  TBranch        *b_L1Tech_RPC_TTU_barrel_Cosmics_v0;   //!
  TBranch        *b_L1Tech_RPC_TTU_barrel_Cosmics_v0_5bx;   //!
  TBranch        *b_L1Tech_RPC_TTU_pointing_Cosmics_v0;   //!
  TBranch        *b_L1Tech_RPC_TTU_pointing_Cosmics_v0_5bx;   //!
  TBranch        *b_L1Tech_RPC_TTU_RBst1_collisions_v0;   //!
  TBranch        *b_L1Tech_RPC_TTU_RBst1_collisions_v0_5bx; //!

  TBranch        *b_L1Tech_HCAL_HF_MM_or_PP_or_PM_v0; //!
  TBranch        *b_L1Tech_HCAL_HF_MM_or_PP_or_PM_v0_5bx; //!
  TBranch        *b_L1Tech_HCAL_HF_coincidence_PM_v1; //!
  TBranch        *b_L1Tech_HCAL_HF_coincidence_PM_v1_5bx; //!
  TBranch        *b_L1Tech_HCAL_HF_MMP_or_MPP_v0; //!
  TBranch        *b_L1Tech_HCAL_HF_MMP_or_MPP_v0_5bx; //!

  TBranch        *b_L1Tech_ZDC_loose_vertex_v0;   //!
  TBranch        *b_L1Tech_ZDC_loose_vertex_v0_5bx;   //!
  TBranch        *b_L1Tech_ZDC_minus_over_threshold_v0;   //!
  TBranch        *b_L1Tech_ZDC_minus_over_threshold_v0_5bx;   //!
  TBranch        *b_L1Tech_ZDC_plus_over_threshold_v0;   //!
  TBranch        *b_L1Tech_ZDC_plus_over_threshold_v0_5bx;   //!
  TBranch        *b_L1Tech_ZDC_tight_vertex_v0;   //!
  TBranch        *b_L1Tech_ZDC_tight_vertex_v0_5bx;   //!
  TBranch        *b_L1_BptxMinus;   //!
  TBranch        *b_L1_BptxMinus_5bx;   //!
  TBranch        *b_L1_BptxPlus;   //!
  TBranch        *b_L1_BptxPlus_5bx;   //!
  TBranch        *b_L1_BptxPlusORMinus;   //!
  TBranch        *b_L1_BptxPlusORMinus_5bx;   //!
  TBranch        *b_L1_BptxPlus_NotBptxMinus; //!
  TBranch        *b_L1_BptxPlus_NotBptxMinus_5bx; //!
  TBranch        *b_L1_BptxMinus_NotBptxPlus; //!
  TBranch        *b_L1_BptxMinus_NotBptxPlus_5bx; //!
  TBranch        *b_L1_BscHighMultiplicity;   //!
  TBranch        *b_L1_BscHighMultiplicity_5bx;   //!
  TBranch        *b_L1_BscMinBiasInnerThreshold1;   //!
  TBranch        *b_L1_BscMinBiasInnerThreshold1_5bx;   //!
  TBranch        *b_L1_BscMinBiasInnerThreshold2;   //!
  TBranch        *b_L1_BscMinBiasInnerThreshold2_5bx;   //!
  TBranch        *b_L1_BscMinBiasOR;   //!
  TBranch        *b_L1_BscMinBiasOR_5bx;   //!
  TBranch        *b_L1_BscMinBiasOR_BptxPlusORMinus;   //!
  TBranch        *b_L1_BscMinBiasOR_BptxPlusORMinus_5bx;   //!

  // JH - 1E31 MC menu
  TBranch        *b_HLT_L1Jet15;   //!  
  TBranch        *b_HLT_Jet30;   //! 
  TBranch        *b_HLT_Jet50;   //! 
  TBranch        *b_HLT_Jet80;   //! 
  TBranch        *b_HLT_Jet110;   //! 
  TBranch        *b_HLT_Jet140;   //! 
  TBranch        *b_HLT_Jet180;   //! 
  TBranch        *b_HLT_FwdJet40;   //! 
  TBranch        *b_HLT_DiJetAve15U_1E31;   //! 
  TBranch        *b_HLT_DiJetAve30U_1E31;   //! 
  TBranch        *b_HLT_DiJetAve50U;   //! 
  TBranch        *b_HLT_DiJetAve70U;   //! 
  TBranch        *b_HLT_DiJetAve130U;   //! 
  TBranch        *b_HLT_QuadJet30;   //! 
  TBranch        *b_HLT_SumET120;   //! 
  TBranch        *b_HLT_L1MET20;   //! 
  TBranch        *b_HLT_MET35;   //! 
  TBranch        *b_HLT_MET60;   //! 
  TBranch        *b_HLT_HT200;   //! 
  TBranch        *b_HLT_HT300_MHT100;   //! 
  TBranch        *b_HLT_L1MuOpen;   //! 
  TBranch        *b_HLT_L1Mu;   //! 
  TBranch        *b_HLT_L1Mu20HQ;   //! 
  TBranch        *b_HLT_L1Mu30;   //! 
  TBranch        *b_HLT_IsoMu9;   //! 
  TBranch        *b_HLT_Mu5;   //! 
  TBranch        *b_HLT_Mu9;   //! 
  TBranch        *b_HLT_Mu11;   //! 
  TBranch        *b_HLT_Mu15;   //! 
  TBranch        *b_HLT_DoubleMu3;   //! 
  TBranch        *b_HLT_Ele10_SW_L1R;   //! 
  TBranch        *b_HLT_Ele15_SW_L1R;   //! 
  TBranch        *b_HLT_Ele15_SW_EleId_L1R;   //! 
  TBranch        *b_HLT_Ele15_SW_LooseTrackIso_L1R;   //! 
  TBranch        *b_HLT_Ele15_SC15_SW_LooseTrackIso_L1R;   //! 
  TBranch        *b_HLT_Ele15_SC15_SW_EleId_L1R;   //! 
  TBranch        *b_HLT_Ele20_SW_L1R;   //! 
  TBranch        *b_HLT_Ele20_SiStrip_L1R;   //! 
  TBranch        *b_HLT_Ele20_SC15_SW_L1R;   //! 
  TBranch        *b_HLT_Ele25_SW_L1R;   //! 
  TBranch        *b_HLT_Ele25_SW_EleId_LooseTrackIso_L1R;   //! 
  TBranch        *b_HLT_DoubleEle5_SW_Jpsi_L1R;   //! 
  TBranch        *b_HLT_DoubleEle5_SW_Upsilon_L1R;   //! 
  TBranch        *b_HLT_DoubleEle10_SW_L1R;   //! 
  TBranch        *b_HLT_Photon10_LooseEcalIso_TrackIso_L1R;   //! 
  TBranch        *b_HLT_Photon15_L1R;   //! 
  TBranch        *b_HLT_Photon20_LooseEcalIso_TrackIso_L1R;   //! 
  TBranch        *b_HLT_Photon25_L1R;   //! 
  TBranch        *b_HLT_Photon25_LooseEcalIso_TrackIso_L1R;   //! 
  TBranch        *b_HLT_Photon30_L1R_1E31;   //! 
  TBranch        *b_HLT_Photon70_L1R;   //! 
  TBranch        *b_HLT_DoublePhoton15_L1R;   //! 
  TBranch        *b_HLT_DoublePhoton15_VeryLooseEcalIso_L1R;   //! 
  TBranch        *b_HLT_SingleIsoTau30_Trk5;   //! 
  TBranch        *b_HLT_DoubleLooseIsoTau15_Trk5;   //! 
  TBranch        *b_HLT_BTagIP_Jet80;   //! 
  TBranch        *b_HLT_BTagMu_Jet20;   //! 
  TBranch        *b_HLT_BTagIP_Jet120;   //! 
  TBranch        *b_HLT_StoppedHSCP_1E31;   //! 
  TBranch        *b_HLT_L1Mu14_L1SingleJet15;   //! 
  TBranch        *b_HLT_L1Mu14_L1ETM40;   //! 
  TBranch        *b_HLT_L2Mu5_Photon9_L1R;   //! 
  TBranch        *b_HLT_L2Mu9_DiJet30;   //! 
  TBranch        *b_HLT_L2Mu8_HT50;   //! 
  TBranch        *b_HLT_Ele10_SW_L1R_TripleJet30;   //! 
  TBranch        *b_HLT_Ele10_LW_L1R_HT180;   //! 
  TBranch        *b_HLT_ZeroBias;   //! 
  TBranch        *b_HLT_MinBiasHcal;   //! 
  TBranch        *b_HLT_MinBiasEcal;   //! 
  TBranch        *b_HLT_MinBiasPixel;   //! 
  TBranch        *b_HLT_MinBiasPixel_Trk5;   //! 
  TBranch        *b_HLT_ZeroBiasPixel_SingleTrack;   //!
  TBranch        *b_HLT_CSCBeamHalo;   //! 
  TBranch        *b_HLT_CSCBeamHaloOverlapRing1;   //! 
  TBranch        *b_HLT_CSCBeamHaloOverlapRing2;   //! 
  TBranch        *b_HLT_CSCBeamHaloRing2or3;   //! 
  TBranch        *b_HLT_BackwardBSC;   //! 
  TBranch        *b_HLT_ForwardBSC;   //! 
  TBranch        *b_HLT_TrackerCosmics;   //! 
  TBranch        *b_HLT_IsoTrack_1E31;   //! 
  TBranch        *b_AlCa_EcalPhiSym;   //! 
  TBranch        *b_AlCa_EcalPi0_1E31;   //! 
  TBranch        *b_AlCa_EcalEta_1E31;   //! 

  // 8E29 menu
  TBranch        *b_HLT_L1Jet6U;   //!
  TBranch        *b_HLT_Jet15U;   //!
  TBranch        *b_HLT_Jet30U;   //!
  TBranch        *b_HLT_Jet50U;   //!
  TBranch        *b_HLT_FwdJet20U;   //!
  TBranch        *b_HLT_DiJetAve15U_8E29;   //!
  TBranch        *b_HLT_DiJetAve30U_8E29;   //!
  TBranch        *b_HLT_QuadJet15U;   //!
  TBranch        *b_HLT_MET45;   //!
  TBranch        *b_HLT_MET100;   //!
  TBranch        *b_HLT_HT100U;   //!
  TBranch        *b_HLT_L1Mu20;   //!
  TBranch        *b_HLT_L2Mu9;   //!
  TBranch        *b_HLT_L2Mu11;   //!
  TBranch        *b_HLT_Mu3;   //! 
  TBranch        *b_HLT_IsoMu3;   //!
  TBranch        *b_HLT_L1DoubleMuOpen;   //!
  TBranch        *b_HLT_DoubleMu0;   //!
  TBranch        *b_HLT_L1SingleEG5;   //!
  TBranch        *b_HLT_L1SingleEG8;   //!
  TBranch        *b_HLT_Ele10_LW_L1R;   //!
  TBranch        *b_HLT_Ele10_LW_EleId_L1R;   //!
  TBranch        *b_HLT_Ele15_SC10_LW_L1R;   //!
  TBranch        *b_HLT_Ele15_SiStrip_L1R;   //!
  TBranch        *b_HLT_Ele15_LW_L1R;   //! 
  TBranch        *b_HLT_Ele20_LW_L1R;   //!
  TBranch        *b_HLT_L1DoubleEG5;   //!
  TBranch        *b_HLT_DoubleEle5_SW_L1R;   //!
  TBranch        *b_HLT_DoublePhoton5_eeRes_L1R;   //!
  TBranch        *b_HLT_DoublePhoton5_Jpsi_L1R;   //!
  TBranch        *b_HLT_DoublePhoton5_Upsilon_L1R;   //!
  TBranch        *b_HLT_Photon10_L1R;   //!
  TBranch        *b_HLT_Photon15_TrackIso_L1R;   //!
  TBranch        *b_HLT_Photon15_LooseEcalIso_L1R;   //!
  TBranch        *b_HLT_Photon20_L1R;   //!
  TBranch        *b_HLT_Photon30_L1R_8E29;   //!
  TBranch        *b_HLT_DoublePhoton10_L1R;   //!
  TBranch        *b_HLT_SingleLooseIsoTau20;   //!
  TBranch        *b_HLT_DoubleLooseIsoTau15;   //!
  TBranch        *b_HLT_BTagMu_Jet10U;   //!
  TBranch        *b_HLT_BTagIP_Jet50U;   //!
  TBranch        *b_HLT_StoppedHSCP_8E29;   //!
  TBranch        *b_HLT_L1Mu14_L1SingleEG10;   //!
  TBranch        *b_HLT_L1Mu14_L1SingleJet6U;   //!
  TBranch        *b_HLT_L1Mu14_L1ETM30;   //!
  TBranch        *b_HLT_IsoTrack_8E29;   //!
  TBranch        *b_AlCa_HcalPhiSym;   //!
  TBranch        *b_AlCa_EcalPi0_8E29;   //!
  TBranch        *b_AlCa_EcalEta_8E29;   //!
  TBranch        *b_AlCa_RPCMuonNoHits;   //!
  TBranch        *b_AlCa_RPCMuonNormalisation;   //!

  // Commissioning and other HLT Paths for the CRAFT09 cosmics menu 
  TBranch        *b_HLT_Random;   //! 
  TBranch        *b_HLT_L2Mu3_NoVertex;   //! 
  TBranch        *b_HLT_OIstateTkMu3;   //! 
  TBranch        *b_HLT_TrackPointing;   //! 
  TBranch        *b_HLT_EgammaSuperClusterOnly_L1R;   //! 
  TBranch        *b_AlCa_EcalPi0_Cosmics;   //!  
  TBranch        *b_AlCa_EcalEta_Cosmics;   //!  
  TBranch        *b_HLT_DataIntegrity;   //!  
  TBranch        *b_HLT_L1_BPTX;   //!  
  TBranch        *b_HLT_L1_BSC;   //!  
  TBranch        *b_HLT_L1_HFtech;   //!  
  TBranch        *b_HLT_HFThreshold;   //!  
  TBranch        *b_HLT_Physics;   //!  
  TBranch        *b_HLT_PhysicsNoMuon;   //!  
  TBranch        *b_HLT_Calibration;   //!  
  TBranch        *b_HLT_EcalCalibration;   //!  
  TBranch        *b_HLT_PixelFEDSize;   //!  
  TBranch        *b_HLT_GlobalRunHPDNoise;   //!  

  // HLT paths for the 2009 Circulating Beam menu
  TBranch        *b_HLT_L2Mu0_NoVertex;   //!
  TBranch        *b_HLT_TkMu3_NoVertex;   //!
  TBranch        *b_HLT_IsoTrackHB_8E29;   //!
  TBranch        *b_HLT_IsoTrackHE_8E29;   //!
  TBranch        *b_HLT_MinBiasPixel_DoubleIsoTrack5;   //!
  TBranch        *b_HLT_MinBiasPixel_DoubleTrack;   //!
  TBranch        *b_HLT_MinBiasPixel_SingleTrack;   //!
  TBranch        *b_HLT_TechTrigHCALNoise;   //!
  TBranch        *b_HLT_HcalNZS_8E29;   //!
  TBranch        *b_HLT_HcalNZS;   //!
  TBranch        *b_HLT_HcalPhiSym;   //!

  // Splash Feb 2010
  TBranch        *b_HLT_SplashEcalSumET;   //!
  TBranch        *b_HLT_L1SingleEG20;   //!

  // Autogenerated from ConfDB - TBranch
  TBranch        *b_HLT_DiJetAve50U_8E29;   //!
  TBranch        *b_HLT_L1DoubleMuOpen_Tight;   //!
  TBranch        *b_HLT_Photon15_TrackIso_Cleaned_L1R;   //!
  TBranch        *b_HLT_Photon15_LooseEcalIso_Cleaned_L1R;   //!
  TBranch        *b_HLT_SingleLooseIsoTau20_Trk5;   //!
  TBranch        *b_HLT_SingleLooseIsoTau25;   //!
  TBranch        *b_HLT_MultiVertex6;   //!
  TBranch        *b_HLT_MultiVertex8_L1ETT60;   //!
  TBranch        *b_HLT_PixelTracks_Multiplicity85;   //!
  TBranch        *b_HLT_L1Tech_BSC_minBias;   //!
  TBranch        *b_HLT_Activity_CSC;   //!
  TBranch        *b_HLT_Activity_Ecal_SC7;   //!
  TBranch        *b_HLT_Activity_Ecal_SC15;   //!
  TBranch        *b_HLT_L1MuOpen_DT;   //!
  TBranch        *b_HLT_Photon10_Cleaned_L1R;   //!
  TBranch        *b_HLT_Photon15_Cleaned_L1R;   //!
  TBranch        *b_HLT_Photon20_Cleaned_L1R;   //!
  TBranch        *b_HLT_L1Tech_BSC_HighMultiplicity;   //!
  TBranch        *b_HLT_PixelTracks_Multiplicity40;   //!
  TBranch        *b_HLT_L1SingleForJet_BPTX;   //!
  TBranch        *b_HLT_L1Jet6U_BPTX;   //!
  TBranch        *b_HLT_L1Jet10U_BPTX;   //!
  TBranch        *b_HLT_L1MuOpen_BPTX;   //!
  TBranch        *b_HLT_L1_BptxXOR_BscMinBiasOR;   //!
  TBranch        *b_HLT_L1SingleCenJet_BPTX;   //!
  TBranch        *b_HLT_MinBiasBSC_BPTX;   //!
  TBranch        *b_HLT_L1Tech_HCAL_HF;   //!
  TBranch        *b_HLT_L1SingleTauJet_BPTX;   //!
  TBranch        *b_HLT_PixelTracks_Multiplicity70;   //!
  TBranch        *b_HLT_Jet15U_HcalNoiseFiltered;   //!
  TBranch        *b_HLT_L2Mu5;   //!
  TBranch        *b_HLT_L1_BscMinBiasOR_BeamGas;   //!
  TBranch        *b_HLT_L1Tech_BSC_halo;   //!
  TBranch        *b_HLT_L1Tech_BSC_halo_forPhysicsBackground;   //!
  TBranch        *b_HLT_HFThreshold3;   //!
  TBranch        *b_HLT_HFThreshold10;   //!
  TBranch        *b_HLT_Activity_DT;   //!
  TBranch        *b_HLT_Activity_DT_Tuned;   //!
  TBranch        *b_HLT_Activity_HF3;   //!
  TBranch        *b_HLT_Activity_HF10;   //!
  TBranch        *b_HLT_MultiTowerEcal;   //!
  TBranch        *b_HLT_SelectEcalSpikes_L1R;   //!
  TBranch        *b_HLT_SelectEcalSpikesHighEt_L1R;   //!
  TBranch        *b_HLT_L1Jet6U_NoBPTX;   //!
  TBranch        *b_HLT_L1Jet10U;   //!
  TBranch        *b_HLT_L1Jet10U_NoBPTX;   //!
  TBranch        *b_HLT_L1SingleForJet_NoBPTX;   //!
  TBranch        *b_HLT_L1SingleCenJet;   //!
  TBranch        *b_HLT_L1SingleCenJet_NoBPTX;   //!
  TBranch        *b_HLT_L1SingleTauJet;   //!
  TBranch        *b_HLT_L1SingleTauJet_NoBPTX;   //!
  TBranch        *b_HLT_DoubleFwdJet50;   //!
  TBranch        *b_HLT_QuadJet60;   //!
  TBranch        *b_HLT_L1MuOpen_NoBPTX;   //!
  TBranch        *b_HLT_L1MuOpen_AntiBPTX;   //!
  TBranch        *b_HLT_L1SingleEG1;   //!
  TBranch        *b_HLT_L1SingleEG1_NoBPTX;   //!
  TBranch        *b_HLT_L1SingleEG5_NoBPTX;   //!
  TBranch        *b_HLT_L1SingleEG20_NoBPTX;   //!
  TBranch        *b_HLT_Ele20_SW_EleId_LooseTrackIso_L1R;   //!
  TBranch        *b_HLT_Ele25_LW_L1R;   //!
  TBranch        *b_HLT_DoublePhoton4_eeRes_L1R;   //!
  TBranch        *b_HLT_DoublePhoton4_Jpsi_L1R;   //!
  TBranch        *b_HLT_DoublePhoton4_Upsilon_L1R;   //!
  TBranch        *b_HLT_DoublePhoton5_L1R;   //!
  TBranch        *b_HLT_L1Mu14_L1SingleJet20;   //!
  TBranch        *b_HLT_MinBiasBSC_NoBPTX;   //!
  TBranch        *b_HLT_SplashBSC;   //!
  TBranch        *b_HLT_L1_BscMinBiasOR_BptxPlusORMinus;   //!
  TBranch        *b_HLT_L1_BscMinBiasOR_BptxPlusORMinus_NoBPTX;   //!
  TBranch        *b_HLT_L1Tech_RPC_TTU_RBst1_collisions;   //!
  TBranch        *b_HLT_IsoTrackHE_1E31;   //!
  TBranch        *b_HLT_IsoTrackHB_1E31;   //!
  TBranch        *b_HLT_HcalNZS_1E31;   //!
  TBranch        *b_HLT_HIMinBiasCalo;   //!
  TBranch        *b_HLT_HIJet35U;   //!
  TBranch        *b_HLT_HIJet50U;   //!
  TBranch        *b_HLT_HIJet75U;   //!
  TBranch        *b_HLT_HIJet90U;   //!
  TBranch        *b_HLT_HIPhoton10;   //!
  TBranch        *b_HLT_HIPhoton15;   //!
  TBranch        *b_HLT_HIPhoton20;   //!
  TBranch        *b_HLT_HIPhoton30;   //!
  TBranch        *b_HLT_HighMult40;   //!
  TBranch        *b_HLT_L1Tech_HCAL_HF_coincidence_PM;   //!
  TBranch        *b_HLT_PhysicsDeclared;   //!
  TBranch        *b_HLT_Jet250;   //!
  TBranch        *b_HLT_DoubleJet15U_ForwardBackward;   //!
  TBranch        *b_HLT_DoubleJet150;   //!
  TBranch        *b_HLT_DoubleJet125_Aco;   //!
  TBranch        *b_HLT_TripleJet85;   //!
  TBranch        *b_HLT_MET25;   //!
  TBranch        *b_HLT_MET50;   //!
  TBranch        *b_HLT_MET75;   //!
  TBranch        *b_HLT_MET60_HT350;   //!
  TBranch        *b_HLT_HT240;   //!
  TBranch        *b_HLT_Jet180_MET60;   //!
  TBranch        *b_HLT_Jet60_MET70_Aco;   //!
  TBranch        *b_HLT_Jet100_MET60_Aco;   //!
  TBranch        *b_HLT_DoubleJet125_MET60;   //!
  TBranch        *b_HLT_DoubleFwdJet40_MET60;   //!
  TBranch        *b_HLT_DoubleJet60_MET60_Aco;   //!
  TBranch        *b_HLT_DoubleJet50_MET70_Aco;   //!
  TBranch        *b_HLT_DoubleJet40_MET70_Aco;   //!
  TBranch        *b_HLT_TripleJet60_MET60;   //!
  TBranch        *b_HLT_QuadJet35_MET60;   //!
  TBranch        *b_HLT_L2Mu0;   //!
  TBranch        *b_HLT_L2Mu3;   //!
  TBranch        *b_HLT_L2Mu15;   //!
  TBranch        *b_HLT_L2DoubleMu0;   //!
  TBranch        *b_HLT_IsoMu11;   //!
  TBranch        *b_HLT_IsoMu13;   //!
  TBranch        *b_HLT_IsoMu15;   //!
  TBranch        *b_HLT_Mu7;   //!
  TBranch        *b_HLT_Mu13;   //!
  TBranch        *b_HLT_DoubleIsoMu3;   //!
  TBranch        *b_HLT_DoubleMu3_Vtx2mm;   //!
  TBranch        *b_HLT_DoubleMu3_JPsi;   //!
  TBranch        *b_HLT_DoubleMu3_Upsilon;   //!
  TBranch        *b_HLT_DoubleMu7_Z;   //!
  TBranch        *b_HLT_DoubleMu3_SameSign;   //!
  TBranch        *b_HLT_DoubleMu3_Psi2S;   //!
  TBranch        *b_HLT_Mu0_L1MuOpen;   //!
  TBranch        *b_HLT_Mu3_L1MuOpen;   //!
  TBranch        *b_HLT_Mu5_L1MuOpen;   //!
  TBranch        *b_HLT_Mu0_L2Mu0;   //!
  TBranch        *b_HLT_Mu3_L2Mu0;   //!
  TBranch        *b_HLT_Mu5_L2Mu0;   //!
  TBranch        *b_HLT_Mu0_Track0_Jpsi;   //!
  TBranch        *b_HLT_Mu3_Track0_Jpsi;   //!
  TBranch        *b_HLT_Mu5_Track0_Jpsi;   //!
  TBranch        *b_HLT_IsoMu7_BTagIP_Jet35;   //!
  TBranch        *b_HLT_IsoMu7_BTagMu_Jet20;   //!
  TBranch        *b_HLT_IsoMu7_Jet40;   //!
  TBranch        *b_HLT_IsoMu14_IsoTau15_Trk3;   //!
  TBranch        *b_HLT_IsoMu14_IsoTau15_Trk3_NoL1;   //!
  TBranch        *b_HLT_IsoMu14_LooseIsoTau15_NoL25;   //!
  TBranch        *b_HLT_IsoMu14_LooseIsoTau15_Trk3_NoL2;   //!
  TBranch        *b_HLT_NoL2IsoMu8_Jet40;   //!
  TBranch        *b_HLT_Mu14_Jet50;   //!
  TBranch        *b_HLT_Mu5_TripleJet30;   //!
  TBranch        *b_HLT_L2Mu7_Photon9_L1R;   //!
  TBranch        *b_HLT_Ele10_LW_L1R_HT200;   //!
  TBranch        *b_AlCa_RPCMuonNoTriggers;   //!
  TBranch        *b_HLT_HIDoubleMu;   //!
  TBranch        *b_HLT_DoublePhoton5_CEP_L1R;   //!
  TBranch        *b_HLT_ZeroBias1kHz;   //!

  // Cut on mu quality
  Int_t           NL1OpenMu;
  Float_t         L1OpenMuPt[10];   //[NL1OpenMu]
  Float_t         L1OpenMuE[10];   //[NL1OpenMu]
  Float_t         L1OpenMuEta[10];   //[NL1OpenMu]
  Float_t         L1OpenMuPhi[10];   //[NL1OpenMu]
  Int_t           L1OpenMuIsol[10];   //[NL1OpenMu]
  Int_t           L1OpenMuMip[10];   //[NL1OpenMu]
  Int_t           L1OpenMuFor[10];   //[NL1OpenMu]
  Int_t           L1OpenMuRPC[10];   //[NL1OpenMu]
  Int_t           L1OpenMuQal[10];   //[NL1OpenMu]

  Int_t           NL1GoodSingleMu;
  Float_t         L1GoodSingleMuPt[10];   //[NL1GoodSingleMu]
  Float_t         L1GoodSingleMuE[10];   //[NL1GoodSingleMu]
  Float_t         L1GoodSingleMuEta[10];   //[NL1GoodSingleMu]
  Float_t         L1GoodSingleMuPhi[10];   //[NL1GoodSingleMu]
  Int_t           L1GoodSingleMuIsol[10];   //[NL1GoodSingleMu]
  Int_t           L1GoodSingleMuMip[10];   //[NL1GoodSingleMu]
  Int_t           L1GoodSingleMuFor[10];   //[NL1GoodSingleMu]
  Int_t           L1GoodSingleMuRPC[10];   //[NL1GoodSingleMu]
  Int_t           L1GoodSingleMuQal[10];   //[NL1GoodSingleMu]

  Int_t           NL1GoodDoubleMu;
  Float_t         L1GoodDoubleMuPt[10];   //[NL1GoodDoubleMu]
  Float_t         L1GoodDoubleMuE[10];   //[NL1GoodDoubleMu]
  Float_t         L1GoodDoubleMuEta[10];   //[NL1GoodDoubleMu]
  Float_t         L1GoodDoubleMuPhi[10];   //[NL1GoodDoubleMu]
  Int_t           L1GoodDoubleMuIsol[10];   //[NL1GoodDoubleMu]
  Int_t           L1GoodDoubleMuMip[10];   //[NL1GoodDoubleMu]
  Int_t           L1GoodDoubleMuFor[10];   //[NL1GoodDoubleMu]
  Int_t           L1GoodDoubleMuRPC[10];   //[NL1GoodDoubleMu]
  Int_t           L1GoodDoubleMuQal[10];   //[NL1GoodDoubleMu]

/*   TH1F *hEta[10][2][2]; //kNbInstances, kNbStages, kNbCuts */
/*   TH1F *hPt[10][2][2]; */
/*   TH1F *hHits[10][2][2]; */
/*   TH1F *hNormChi2[10][2][2]; */
/*   TH1F *hDxy[10][2][2]; */
/*   TH1F *hDz[10][2][2]; */
/*   TH1F *hP[10][2][2]; */

/*   TH1F *hOniaEta[10][2][4]; */
/*   TH1F *hOniaRap[10][2][4]; */
/*   TH1F *hOniaPt[10][2][4]; */
/*   TH1F *hOniaP[10][2][4]; */
/*   TH1F *hOniaMass[10][2][4]; */
/*   TH2F *hOniaEtaPt[10][2][4]; */
/*   TH2F *hOniaRapP[10][2][4]; */

/*   TH1F *hNCand[10][2]; */
/*   TH1F *hPixCanddr[10]; */
/*   TH1F *hPixCandEta[10]; */
/*   TH1F *hPixCandPt[10]; */
/*   TH1F *hPixCandP[10]; */
  
  OHltTree(TTree *tree=0, OHltMenu *menu=0);
  virtual ~OHltTree();
  virtual Bool_t   Notify();
  virtual void     Init(TTree *tree);

  inline Int_t     GetEntry(Long64_t entry);
  inline Long64_t  LoadTree(Long64_t entry);
  inline void	   SetMapL1BitOfStandardHLTPath(OHltMenu *menu);
  inline void	   SetMapL1SeedsOfStandardHLTPath(OHltMenu *menu);
  inline void      SetMapL1BitOfStandardHLTPathUsingLogicParser(OHltMenu *menu, int nentry);
  inline void ApplyL1Prescales(OHltMenu *menu,OHltConfig *cfg,OHltRateCounter *rc);
  inline void RemoveEGOverlaps();
  inline void SetL1MuonQuality();
  inline void SetOpenL1Bits();
  bool passPreFilterLogicParser(TString, int);

  void Loop(OHltRateCounter *rc,OHltConfig *cfg,OHltMenu *menu,int pID
						,float &Den,TH1F* &h1,TH1F* &h2,TH1F* &h3,TH1F* &h4
						,SampleDiagnostics& primaryDatasetsDiagnostics);

  void PlotOHltEffCurves(OHltConfig *cfg,TString hlteffmode,TString ohltobject,TH1F* &h1,TH1F* &h2,TH1F* &h3,TH1F* &h4);
  void CheckOpenHlt(OHltConfig *cfg,OHltMenu *menu,OHltRateCounter *rc,int it);
  void PrintOhltVariables(int level, int type);
  int OpenHltL1L2TauMatching(float eta, float phi, float tauThr, float jetThre);
  int OpenHltTauPassed(float Et,float Eiso, float L25Tpt, int L25Tiso,float L3Tpt, int L3Tiso,
		       float L1TauEtThr, float L1CenJetThr);
  int OpenHltTauL2SCPassed(float Et,float L25Tpt, int L25Tiso, float L3Tpt, int L3Tiso,
			   float L1TauEtThr, float L1CenJetThr);
  int OpenHlt2Tau1LegL3IsoPassed(float Et,float L25Tpt, int L25Tiso, float L3Tpt,
				 float L1TauEtThr, float L1CenJetThr);
  int OpenHltElecTauL2SCPassed(float elecEt, int elecL1iso, float elecTiso, float elecHiso,
					 float tauEt,float tauL25Tpt, int tauL25Tiso, float tauL3Tpt, int tauL3Tiso);
  int OpenHlt1ElectronPassed(float Et,int L1iso,float Tiso,float Hiso);
  int OpenHlt1LWElectronPassed(float Et,int L1iso,float Tiso,float Hiso); 
  int OpenHlt1EleIdLWElectronPassed(float Et,int L1iso,float Tiso,float Hiso); 
  int OpenHlt1ElectronEleIDPassed(float Et,int L1iso,float Tiso,float Hiso); 
  int OpenHlt1PhotonPassed(float Et,int L1iso,float Tiso,float Eiso,float HisoBR,float HisoEC);
  int OpenHlt1PhotonLooseEcalIsoPassed(float Et,int L1iso,float Tiso,float Eiso,float HisoBR,float HisoEC);
  int OpenHlt1PhotonVeryLooseEcalIsoPassed(float Et,int L1iso,float Tiso,float Eiso,float HisoBR,float HisoEC); 
  int OpenHlt2PhotonMassWinPassed(float Et, int L1iso, float Tiso, float Eiso, float HisoBR, float HisoEC,float massLow, float massHigh);
  int OpenHlt2ElectronMassWinPassed(float Et, int L1iso, float Hiso, float massLow, float massHigh); 
  int OpenHlt2Electron1LegIdPassed(float Et,int L1iso,float Tiso,float Hiso);
  int OpenHlt1MuonPassed(double ptl1,double ptl2,double ptl3,double dr,int iso);
  int OpenHlt2MuonPassed(double ptl1,double ptl2,double ptl3,double dr,int iso);
  int OpenHlt1L2MuonPassed(double ptl1,double ptl2,double dr);  
  int OpenHltMuTrackPassed(double ptTrack, double pTrack, double etaTrack, double DxyTrack, double DzTrack, int NHitsTrack, double normChi2Track, double *massMinTrack, double *massMaxTrack, double DzMuonTrack, bool checkChargeTrack);
  int OpenHltMuPixelPassed(double ptPix, double pPix, double etaPix, double DxyPix, double DzPix, int NHitsPix, double normChi2Pix, double *massMinPix, double *massMaxPix, double DzMuonPix, bool checkChargePix);
  int OpenHltMuTrackPassed_JPsi(double ptTrack, double pTrack, double etaTrack, double DxyTrack, double DzTrack, int NHitsTrack, double normChi2Track, double *massMinTrack, double *massMaxTrack, double DzMuonTrack, bool checkChargeTrack, int histIndex);
  int OpenHltMuPixelPassed_JPsi(double ptPix, double pPix, double etaPix, double DxyPix, double DzPix, int NHitsPix, double normChi2Pix, double *massMinPix, double *massMaxPix, double DzMuonPix, bool checkChargePix, int histIndex);
  int OpenHltMuTrackPassed_Ups(double ptTrack, double pTrack, double etaTrack, double DxyTrack, double DzTrack, int NHitsTrack, double normChi2Track, double *massMinTrack, double *massMaxTrack, double DzMuonTrack, bool checkChargeTrack, int histIndex);
  int OpenHltMuPixelPassed_Ups(double ptPix, double pPix, double etaPix, double DxyPix, double DzPix, int NHitsPix, double normChi2Pix, double *massMinPix, double *massMaxPix, double DzMuonPix, bool checkChargePix, int histIndex);
  int OpenHlt1JetPassed(double pt);
  int OpenHlt1CorJetPassed(double pt);
  int OpenHltFwdJetPassed(double esum);
  int OpenHltFwdCorJetPassed(double esum);
  int OpenHltDiJetAvePassed(double pt);
  int OpenHltCorDiJetAvePassed(double pt);
  int OpenHltQuadJetPassed(double pt);
  int OpenHltQuadCorJetPassed(double pt);
  int OpenHltJRMuonPassed(double ptl1,double ptl2,double ptl3,double dr,int iso,double ptl3hi);
  int OpenHltSumHTPassed(double sumHTthreshold, double jetthreshold) ;
  int OpenHltMHT(double MHTthreshold, double jetthreshold) ;
  int OpenHlt1PixelTrackPassed(float minpt, float minsep, float miniso);

  std::map<TString, std::vector<TString> >&
    GetL1SeedsOfHLTPathMap() { return map_L1SeedsOfStandardHLTPath; }; // mapping to all seeds

  int GetNLumiSections() {
    return nLumiSections;
  }

private:

  int nTrig;
  int nL1Trig;
  int nLumiSections;
  int previousLumiSection;
  int currentLumiSection;
  int nEventsProcessed;
  std::vector<int> triggerBit;
  std::vector<int> previousBitsFired;
  std::vector<int> allOtherBitsFired;
  std::vector<int> BitOfStandardHLTPath;
  std::vector<int> L3MuCandIDForOnia;
  std::vector<int> L3PixelCandIDForOnia;
  std::vector<int> L3MuPixCandIDForOnia;
  std::vector<int> L3PixelCandIDForJPsi;
  std::vector<int> L3MuPixCandIDForJPsi;
  std::vector<int> L3PixelCandIDForUps;
  std::vector<int> L3MuPixCandIDForUps;
  std::map<TString,int> map_BitOfStandardHLTPath;
  std::map<TString,int> map_L1BitOfStandardHLTPath;

  std::map<TString, std::vector<TString> > map_L1SeedsOfStandardHLTPath; // mapping to all seeds
  std::map<TString, std::vector<int> > map_RpnTokenIdOfStandardHLTPath; // mapping to algo token

  TRandom3 random; // for random prescale method
  inline int GetIntRandom() { return (int)(9999999.*random.Rndm()); }

  bool prescaleResponse(OHltMenu *menu, OHltConfig *cfg, OHltRateCounter *rc,int i);
  bool prescaleResponseL1(OHltMenu *menu, OHltConfig *cfg, OHltRateCounter *rc,int i);
  bool isInRunLumiblockList(int,int,std::vector < std::vector <int> >);

  int nMissingTriggerWarnings;

  enum e_objType {muon,electron,tau,photon,jet};

};

#ifdef OHltTree_cxx
OHltTree::OHltTree(TTree *tree, OHltMenu *menu)
{
  random.SetSeed(0);
  
  std::cout<<"Initialising OHltTree."<<std::endl;
  if (tree == 0) {
    std::cerr<<"Error initialising tree!"<<std::endl;
    return;
  }
  if (menu == 0) {
    std::cerr<<"Error: no menu!"<<std::endl;
    return;
  }
  Init(tree);

  nMissingTriggerWarnings = 0;

  currentLumiSection = -999;
  previousLumiSection = -999;
  nLumiSections = 0;

  nTrig = menu->GetTriggerSize();
  nL1Trig = menu->GetL1TriggerSize();

  triggerBit.reserve(nTrig);
  previousBitsFired.reserve(nTrig);
  allOtherBitsFired.reserve(nTrig);
  BitOfStandardHLTPath.reserve(nTrig);
  L3MuCandIDForOnia.reserve(10);
  L3PixelCandIDForOnia.reserve(10);
  L3MuPixCandIDForOnia.reserve(10);
  L3PixelCandIDForJPsi.reserve(10);
  L3MuPixCandIDForJPsi.reserve(10);
  L3PixelCandIDForUps.reserve(10);
  L3MuPixCandIDForUps.reserve(10);
  
  for (int it = 0; it < nTrig; it++){
    triggerBit.push_back(false);
    previousBitsFired.push_back(false);
    allOtherBitsFired.push_back(false);
  }  
  for (int ic = 0; ic < 10; ic++){
    L3MuCandIDForOnia.push_back(-1);
    L3PixelCandIDForOnia.push_back(-1);
    L3MuPixCandIDForOnia.push_back(-1);
    L3PixelCandIDForJPsi.push_back(-1);
    L3MuPixCandIDForJPsi.push_back(-1);
    L3PixelCandIDForUps.push_back(-1);
    L3MuPixCandIDForUps.push_back(-1);
  }

  for(int i=0;i<8000 ;i++) 
    { ohEleL1Dupl[i] = true;} 
 
  for(int i=0;i<8000 ;i++)  
    { ohPhotL1Dupl[i] = true;}  

  for(int i=0;i<8000 ;i++)   
    { ohEleLWL1Dupl[i] = true;}


/*   int binEta = 120; */
/*   double EtabinMin = -4.0, EtabinMax = 4.0; */

/*   int binPt = 100; */
/*   double PtbinMin = 0., PtbinMax = 30.; */

/*   int binP = 100; */
/*   double PbinMin = 0., PbinMax = 50.; */

/*   int binRap = 120; */
/*   double RapbinMin = -3.0; */
/*   double RapbinMax = 3.0; */

/*   int binMass = 240; */
/*   double MassbinMin = 0.; */
/*   double MassbinMax = 12.; */

/*   const char *histIndex[10] = {"Mu0_Track0_Jpsi","Mu1_Track0_Jpsi","Mu1p5_Track0_Jpsi","Mu2_Track0_Jpsi",  */
/*                            "Mu2p5_Track0_Jpsi","Mu3_Track0_Jpsi","Mu5_Track0_Jpsi", */
/*                            "Mu0_Track0_Ups","Mu3_Track0_Ups","Mu5_Track0_Ups"}; */
  
/*   const char *Track[2] = {"Pixel","Track"}; */
/*   const char *histIdxCut[4] = {"","_MassCut","_MassChgCut","_MassChgDzMuPixCut"}; */
/*   //char name[100], title[300]; */

/*   for(Int_t ihistIdx=0;ihistIdx<10;ihistIdx++){ */

/*      hPixCanddr[ihistIdx] = new TH1F(Form("h%s_PixCanddr",histIndex[ihistIdx]), */
/*                                      Form("%s: PixelCand;#DeltaR",histIndex[ihistIdx]),100,0,10); */
/*      hPixCandEta[ihistIdx] = new TH1F(Form("h%s_PixCandEta",histIndex[ihistIdx]), */
/*                                       Form("%s: PixelCand;#eta",histIndex[ihistIdx]),binEta,EtabinMin,EtabinMax); */
/*      hPixCandPt[ihistIdx] = new TH1F(Form("h%s_PixCandPt",histIndex[ihistIdx]), */
/*                                      Form("%s: PixelCand;p_{T} [GeV/c]",histIndex[ihistIdx]),100,0,10); */
/*      hPixCandP[ihistIdx] = new TH1F(Form("h%s_PixCandP",histIndex[ihistIdx]), */
/*                                     Form("%s: PixelCand;p [GeV/c]",histIndex[ihistIdx]),100,0,20); */

/*      for(Int_t iTrk=0;iTrk<2;iTrk++){ */

/*         hEta[ihistIdx][iTrk][0] = new TH1F(Form("h%s_%sEta", histIndex[ihistIdx],Track[iTrk]), */
/*                                            Form("%s: %s;#eta",histIndex[ihistIdx], Track[iTrk]),binEta,EtabinMin,EtabinMax); */
/*         hPt[ihistIdx][iTrk][0] = new TH1F(Form("h%s_%sPt", histIndex[ihistIdx], Track[iTrk]), */
/*                                           Form("%s: %s;p_{T} [GeV/c]",histIndex[ihistIdx], Track[iTrk]), binPt,PtbinMin,PtbinMax); */
/*         hHits[ihistIdx][iTrk][0] = new TH1F(Form("h%s_%sHits", histIndex[ihistIdx], Track[iTrk]),  */
/*                                             Form("%s: # of %s Hits;#Hits",histIndex[ihistIdx], Track[iTrk]),11, -0.5, 10.5); */
/*         hNormChi2[ihistIdx][iTrk][0] = new TH1F(Form("h%s_%sNormChi2", histIndex[ihistIdx], Track[iTrk]), */
/*                                                 Form("%s: %s;#chi^{2} / ndf",histIndex[ihistIdx], Track[iTrk]),200,0.,20.); */
/*         hDxy[ihistIdx][iTrk][0] = new TH1F(Form("h%s_%sDxy", histIndex[ihistIdx], Track[iTrk]), */
/*                                            Form("%s: %s;d_{xy} [cm]",histIndex[ihistIdx], Track[iTrk]),100,-0.5,0.5); */
/*         hDz[ihistIdx][iTrk][0] = new TH1F(Form("h%s_%sDz", histIndex[ihistIdx], Track[iTrk]), */
/*                                           Form("%s: %s;d_{z} [cm]",histIndex[ihistIdx], Track[iTrk]),100,-20.,20.); */
/*         hP[ihistIdx][iTrk][0] = new TH1F(Form("h%s_%sP", histIndex[ihistIdx], Track[iTrk]), */
/*                                          Form("%s: %s;p [GeV/c]",histIndex[ihistIdx], Track[iTrk]),binPt,PtbinMin,PtbinMax); */
/*         hEta[ihistIdx][iTrk][1] = new TH1F(Form("h%s_%sEta_EtaCut", histIndex[ihistIdx], Track[iTrk]), */
/*                                            Form("%s: %s;#eta",histIndex[ihistIdx], Track[iTrk]), binEta,EtabinMin,EtabinMax); */
/*         hPt[ihistIdx][iTrk][1] = new TH1F(Form("h%s_%sPt_PtCut", histIndex[ihistIdx], Track[iTrk]), */
/*                                           Form("%s: %s;p_{T} [GeV/c]",histIndex[ihistIdx], Track[iTrk]), binPt,PtbinMin,PtbinMax); */

/*         hHits[ihistIdx][iTrk][1] = new TH1F(Form("h%s_%sHits_HitCut", histIndex[ihistIdx], Track[iTrk]), */
/*                                             Form("%s: # of %s Hits;#Hits",histIndex[ihistIdx], Track[iTrk]), 11, -0.5, 10.5); */
/*         hNormChi2[ihistIdx][iTrk][1] = new TH1F(Form("h%s_%sNormChi2_Chi2Cut", histIndex[ihistIdx], Track[iTrk]), */
/*                                                 Form("%s: %s;#chi^{2} / ndf",histIndex[ihistIdx], Track[iTrk]),200,0.,20.); */
/*         hDxy[ihistIdx][iTrk][1] = new TH1F(Form("h%s_%sDxy_DxyCut", histIndex[ihistIdx], Track[iTrk]), */
/*                                            Form("%s: %s;d_{xy} [cm]",histIndex[ihistIdx], Track[iTrk]),100,-0.5,0.5); */
/*         hDz[ihistIdx][iTrk][1] = new TH1F(Form("h%s_%sDz_DzCut", histIndex[ihistIdx], Track[iTrk]), */
/*                                           Form("%s: %s;d_{z} [cm]",histIndex[ihistIdx], Track[iTrk]),80,-20.,20.); */
/*         hP[ihistIdx][iTrk][1] = new TH1F(Form("h%s_%sP_PCut", histIndex[ihistIdx], Track[iTrk]), */
/*                                          Form("%s: %s;p [GeV/c]",histIndex[ihistIdx], Track[iTrk]),binPt,PtbinMin,PtbinMax); */
/*         hNCand[ihistIdx][iTrk] = new TH1F(Form("h%s_%sNCand", histIndex[ihistIdx], Track[iTrk]), */
/*                                           Form("%s: # of %s Candidates;#Cands",histIndex[ihistIdx], Track[iTrk]),12,-0.5,11.5); */

/*         for(Int_t iCut=0; iCut<4; iCut++){ */

/*           hOniaEta[ihistIdx][iTrk][iCut] = new TH1F(Form("h%s_%sMuEta%s", histIndex[ihistIdx], Track[iTrk], histIdxCut[iCut]), */
/*                                                     Form("%s: (%s+Mu)%s;#eta", histIndex[ihistIdx], Track[iTrk], histIdxCut[iCut]), */
/*                                                     binEta,EtabinMin,EtabinMax); */
/*           hOniaRap[ihistIdx][iTrk][iCut] = new TH1F(Form("h%s_%sMuRap%s", histIndex[ihistIdx], Track[iTrk], histIdxCut[iCut]), */
/*                                                     Form("%s: (%s+Mu)%s;y", histIndex[ihistIdx], Track[iTrk], histIdxCut[iCut]), */
/*                                                     binRap,RapbinMin,RapbinMax); */
/*           hOniaPt[ihistIdx][iTrk][iCut] = new TH1F(Form("h%s_%sMuPt%s", histIndex[ihistIdx],Track[iTrk],histIdxCut[iCut]), */
/*                                                    Form("%s: (%s+Mu)%s;p_{T} [GeV/c]",histIndex[ihistIdx],Track[iTrk],histIdxCut[iCut]), */
/*                                                    binPt,PtbinMin,PtbinMax); */
/*           hOniaP[ihistIdx][iTrk][iCut] = new TH1F(Form("h%s_%sMuP%s", histIndex[ihistIdx], Track[iTrk], histIdxCut[iCut]), */
/*                                                   Form("%s: (%s+Mu)%s;p [GeV/c]", histIndex[ihistIdx], Track[iTrk], histIdxCut[iCut]), */
/*                                                   binP,PbinMin,PbinMax); */
/*           hOniaMass[ihistIdx][iTrk][iCut] = new TH1F(Form("h%s_%sMuMass%s", histIndex[ihistIdx], Track[iTrk], histIdxCut[iCut]), */
/*                                                      Form("%s: (%s+Mu)%s;M [GeV/c^{2}]", histIndex[ihistIdx], Track[iTrk], histIdxCut[iCut]), */
/*                                                      binMass,MassbinMin,MassbinMax); */
/*           hOniaEtaPt[ihistIdx][iTrk][iCut] = new TH2F(Form("h%s_%sMuEtaPt%s", histIndex[ihistIdx], Track[iTrk], histIdxCut[iCut]), */
/*                                              Form("%s: (%s+Mu)%s;#eta;p_{T} [GeV/c]", histIndex[ihistIdx], Track[iTrk], histIdxCut[iCut]), */
/*                                              binEta,EtabinMin,EtabinMax,binPt,PtbinMin,PtbinMax); */
/*           hOniaRapP[ihistIdx][iTrk][iCut] = new TH2F(Form("h%s_%sMuRapP%s", histIndex[ihistIdx], Track[iTrk], histIdxCut[iCut]), */
/*                                                      Form("%s: (%s+Mu)%s;y;p [GeV/c]", histIndex[ihistIdx],Track[iTrk],histIdxCut[iCut]), */
/*                                                      binRap,RapbinMin,RapbinMax,binP,PbinMin,PbinMax); */
/*         } */
/*      } */
/*   } */


  //SetMapL1SeedsOfStandardHLTPath(menu);

  std::cout<<"Succeeded initialising OHltTree. nEntries: "<<fChain->GetEntries()<<std::endl;
}

OHltTree::~OHltTree()
{
  if (!fChain) return;
  delete fChain->GetCurrentFile();
}

Int_t OHltTree::GetEntry(Long64_t entry)
{
  // Read contents of entry.
  if (!fChain) return 0;
  return fChain->GetEntry(entry);
}

Long64_t OHltTree::LoadTree(Long64_t entry)
{
  // Set the environment to read one entry
  if (!fChain) return -5;
  Long64_t centry = fChain->LoadTree(entry);
  if (centry < 0) return centry;
  if (!fChain->InheritsFrom(TChain::Class()))  return centry;
  TChain *chain = (TChain*)fChain;
  if (chain->GetTreeNumber() != fCurrent) {
    fCurrent = chain->GetTreeNumber();
    Notify();
  }
  return centry;
}

void OHltTree::Init(TTree *tree)
{
  // The Init() function is called when the selector needs to initialize
  // a new tree or chain. Typically here the branch addresses and branch
  // pointers of the tree will be set.
  // It is normally not necessary to make changes to the generated
  // code, but the routine can be extended by the user if needed.
  // Init() will be called many times when running on PROOF
  // (once per file to be processed).

  // Set branch addresses and branch pointers
  if (!tree) return;
  fChain = tree;
  fCurrent = -1;
  fChain->SetMakeClass(1);

  fChain->SetBranchAddress("NrecoJetCal", &NrecoJetCal, &b_NrecoJetCal);
  fChain->SetBranchAddress("NrecoJetGen", &NrecoJetGen, &b_NrecoJetGen);
  fChain->SetBranchAddress("NrecoTowCal", &NrecoTowCal, &b_NrecoTowCal);
  fChain->SetBranchAddress("NrecoJetCorCal", &NrecoJetCorCal, &b_NrecoJetCorCal);
  fChain->SetBranchAddress("recoJetCalPt", recoJetCalPt, &b_recoJetCalPt);
  fChain->SetBranchAddress("recoJetCalPhi", recoJetCalPhi, &b_recoJetCalPhi);
  fChain->SetBranchAddress("recoJetCalEta", recoJetCalEta, &b_recoJetCalEta);
  fChain->SetBranchAddress("recoJetCalEt", recoJetCalEt, &b_recoJetCalEt);
  fChain->SetBranchAddress("recoJetCalE", recoJetCalE, &b_recoJetCalE);
  fChain->SetBranchAddress("recoJetGenPt", &recoJetGenPt, &b_recoJetGenPt);
  fChain->SetBranchAddress("recoJetGenPhi", &recoJetGenPhi, &b_recoJetGenPhi);
  fChain->SetBranchAddress("recoJetGenEta", &recoJetGenEta, &b_recoJetGenEta);
  fChain->SetBranchAddress("recoJetGenEt", &recoJetGenEt, &b_recoJetGenEt);
  fChain->SetBranchAddress("recoJetGenE", &recoJetGenE, &b_recoJetGenE);
  fChain->SetBranchAddress("recoTowEt", &recoTowEt, &b_recoTowEt);
  fChain->SetBranchAddress("recoTowEta", &recoTowEta, &b_recoTowEta);
  fChain->SetBranchAddress("recoTowPhi", &recoTowPhi, &b_recoTowPhi);
  fChain->SetBranchAddress("recoTowE", &recoTowE, &b_recoTowE);
  fChain->SetBranchAddress("recoTowEm", &recoTowEm, &b_recoTowEm);
  fChain->SetBranchAddress("recoTowHad", &recoTowHad, &b_recoTowHad);
  fChain->SetBranchAddress("recoTowOE", &recoTowOE, &b_recoTowOE);
  fChain->SetBranchAddress("recoJetCorCalPt", recoJetCorCalPt, &b_recoJetCorCalPt);
  fChain->SetBranchAddress("recoJetCorCalPhi", recoJetCorCalPhi, &b_recoJetCorCalPhi);
  fChain->SetBranchAddress("recoJetCorCalEta", recoJetCorCalEta, &b_recoJetCorCalEta);
  fChain->SetBranchAddress("recoJetCorCalE", recoJetCorCalE, &b_recoJetCorCalE);
  fChain->SetBranchAddress("recoMetCal", &recoMetCal, &b_recoMetCal);
  fChain->SetBranchAddress("recoMetCalPhi", &recoMetCalPhi, &b_recoMetCalPhi);
  fChain->SetBranchAddress("recoMetCalSum", &recoMetCalSum, &b_recoMetCalSum);
  fChain->SetBranchAddress("recoMetGen", &recoMetGen, &b_recoMetGen);
  fChain->SetBranchAddress("recoMetGenPhi", &recoMetGenPhi, &b_recoMetGenPhi);
  fChain->SetBranchAddress("recoMetGenSum", &recoMetGenSum, &b_recoMetGenSum);
  fChain->SetBranchAddress("recoHTCal", &recoHTCal, &b_recoHTCal);
  fChain->SetBranchAddress("recoHTCalPhi", &recoHTCalPhi, &b_recoHTCalPhi);
  fChain->SetBranchAddress("recoHTCalSum", &recoHTCalSum, &b_recoHTCalSum);
  fChain->SetBranchAddress("NohTau", &NohTau, &b_NohTau);
  fChain->SetBranchAddress("ohTauEta", ohTauEta, &b_ohTauEta);
  fChain->SetBranchAddress("ohTauPhi", ohTauPhi, &b_ohTauPhi);
  fChain->SetBranchAddress("ohTauPt", ohTauPt, &b_ohTauPt);
  fChain->SetBranchAddress("ohTauEiso", ohTauEiso, &b_ohTauEiso);
  fChain->SetBranchAddress("ohTauL25Tpt", ohTauL25Tpt, &b_ohTauL25Tpt);
  fChain->SetBranchAddress("ohTauL25Tiso", ohTauL25Tiso, &b_ohTauL25Tiso);
  fChain->SetBranchAddress("ohTauL3Tpt", ohTauL3Tpt, &b_ohTauL3Tpt);
  fChain->SetBranchAddress("ohTauL3Tiso", ohTauL3Tiso, &b_ohTauL3Tiso);
  //ccla
  fChain->SetBranchAddress("recoNVrt", &recoNVrt, &b_recoNVrt);
  fChain->SetBranchAddress("recoVrtX", &recoVrtX, &b_recoVrtX);
  fChain->SetBranchAddress("recoVrtY", &recoVrtY, &b_recoVrtY);
  fChain->SetBranchAddress("recoVrtZ", &recoVrtZ, &b_recoVrtZ);
  fChain->SetBranchAddress("recoVrtNtrk", &recoVrtNtrk, &b_recoVrtNtrk);
  fChain->SetBranchAddress("recoVrtChi2", &recoVrtChi2, &b_recoVrtChi2);
  fChain->SetBranchAddress("recoVrtNdof", &recoVrtNdof, &b_recoVrtNdof);

  fChain->SetBranchAddress("NohBJetL2", &NohBJetL2, &b_NohBJetL2);
  fChain->SetBranchAddress("NohBJetLife", &NohBJetLife, &b_NohBJetLife);
  fChain->SetBranchAddress("ohBJetLifeL2E", ohBJetLifeL2E, &b_ohBJetLifeL2E);
  fChain->SetBranchAddress("ohBJetLifeL2ET", ohBJetLifeL2ET, &b_ohBJetLifeL2ET);
  fChain->SetBranchAddress("ohBJetLifeL2Eta", ohBJetLifeL2Eta, &b_ohBJetLifeL2Eta);
  fChain->SetBranchAddress("ohBJetLifeL2Phi", ohBJetLifeL2Phi, &b_ohBJetLifeL2Phi);
  fChain->SetBranchAddress("ohBJetLifeL25Discriminator", ohBJetLifeL25Discriminator, &b_ohBJetLifeL25Discriminator);
  fChain->SetBranchAddress("ohBJetLifeL3Discriminator", ohBJetLifeL3Discriminator, &b_ohBJetLifeL3Discriminator);
  fChain->SetBranchAddress("NohBJetPixelTracks", &NohBJetPixelTracks, &b_NohBJetPixelTracks);
  fChain->SetBranchAddress("ohBJetLifePixelTrackPt", ohBJetLifePixelTrackPt, &b_ohBJetLifePixelTrackPt);
  fChain->SetBranchAddress("ohBJetLifePixelTrackEta", ohBJetLifePixelTrackEta, &b_ohBJetLifePixelTrackEta);
  fChain->SetBranchAddress("ohBJetLifePixelTrackPhi", ohBJetLifePixelTrackPhi, &b_ohBJetLifePixelTrackPhi);
  fChain->SetBranchAddress("ohBJetLifePixelTrackChi2", ohBJetLifePixelTrackChi2, &b_ohBJetLifePixelTrackChi2);
  fChain->SetBranchAddress("NohBJetRegionalTracks", &NohBJetRegionalTracks, &b_NohBJetRegionalTracks);
  fChain->SetBranchAddress("ohBJetLifeRegionalTrackPt", ohBJetLifeRegionalTrackPt, &b_ohBJetLifeRegionalTrackPt);
  fChain->SetBranchAddress("ohBJetLifeRegionalTrackEta", ohBJetLifeRegionalTrackEta, &b_ohBJetLifeRegionalTrackEta);
  fChain->SetBranchAddress("ohBJetLifeRegionalTrackPhi", ohBJetLifeRegionalTrackPhi, &b_ohBJetLifeRegionalTrackPhi);
  fChain->SetBranchAddress("ohBJetLifeRegionalTrackChi2", ohBJetLifeRegionalTrackChi2, &b_ohBJetLifeRegionalTrackChi2);
  fChain->SetBranchAddress("ohBJetLifeRegionalSeedPt", ohBJetLifeRegionalSeedPt, &b_ohBJetLifeRegionalSeedPt);
  fChain->SetBranchAddress("ohBJetLifeRegionalSeedEta", ohBJetLifeRegionalSeedEta, &b_ohBJetLifeRegionalSeedEta);
  fChain->SetBranchAddress("ohBJetLifeRegionalSeedPhi", ohBJetLifeRegionalSeedPhi, &b_ohBJetLifeRegionalSeedPhi);
  fChain->SetBranchAddress("NohBJetSoftm", &NohBJetSoftm, &b_NohBJetSoftm);
  fChain->SetBranchAddress("ohBJetSoftmL2E", ohBJetSoftmL2E, &b_ohBJetSoftmL2E);
  fChain->SetBranchAddress("ohBJetSoftmL2ET", ohBJetSoftmL2ET, &b_ohBJetSoftmL2ET);
  fChain->SetBranchAddress("ohBJetSoftmL2Eta", ohBJetSoftmL2Eta, &b_ohBJetSoftmL2Eta);
  fChain->SetBranchAddress("ohBJetSoftmL2Phi", ohBJetSoftmL2Phi, &b_ohBJetSoftmL2Phi);
  fChain->SetBranchAddress("ohBJetSoftmL25Discriminator", ohBJetSoftmL25Discriminator, &b_ohBJetSoftmL25Discriminator);
  fChain->SetBranchAddress("ohBJetSoftmL3Discriminator", ohBJetSoftmL3Discriminator, &b_ohBJetSoftmL3Discriminator);
  fChain->SetBranchAddress("ohBJetPerfL2E", ohBJetPerfL2E, &b_ohBJetPerfL2E);
  fChain->SetBranchAddress("ohBJetPerfL2ET", ohBJetPerfL2ET, &b_ohBJetPerfL2ET);
  fChain->SetBranchAddress("ohBJetPerfL2Eta", ohBJetPerfL2Eta, &b_ohBJetPerfL2Eta);
  fChain->SetBranchAddress("ohBJetPerfL2Phi", ohBJetPerfL2Phi, &b_ohBJetPerfL2Phi);
  fChain->SetBranchAddress("ohBJetL2Energy", ohBJetL2Energy, &b_ohBJetL2Energy); 
  fChain->SetBranchAddress("ohBJetL2Et", ohBJetL2Et, &b_ohBJetL2Et); 
  fChain->SetBranchAddress("ohBJetL2Pt", ohBJetL2Pt, &b_ohBJetL2Pt); 
  fChain->SetBranchAddress("ohBJetL2Eta", ohBJetL2Eta, &b_ohBJetL2Eta); 
  fChain->SetBranchAddress("ohBJetL2Phi", ohBJetL2Phi, &b_ohBJetL2Phi); 
  fChain->SetBranchAddress("NohBJetL2Corrected", &NohBJetL2Corrected, &b_NohBJetL2Corrected); 
  fChain->SetBranchAddress("ohBJetL2CorrectedEnergy", ohBJetL2CorrectedEnergy, &b_ohBJetL2CorrectedEnergy); 
  fChain->SetBranchAddress("ohBJetL2CorrectedEt", ohBJetL2CorrectedEt, &b_ohBJetL2CorrectedEt); 
  fChain->SetBranchAddress("ohBJetL2CorrectedPt", ohBJetL2CorrectedPt, &b_ohBJetL2CorrectedPt); 
  fChain->SetBranchAddress("ohBJetL2CorrectedEta", ohBJetL2CorrectedEta, &b_ohBJetL2CorrectedEta); 
  fChain->SetBranchAddress("ohBJetL2CorrectedPhi", ohBJetL2CorrectedPhi, &b_ohBJetL2CorrectedPhi); 
  fChain->SetBranchAddress("ohBJetIPL25Tag", ohBJetIPL25Tag, &b_ohBJetIPL25Tag); 
  fChain->SetBranchAddress("ohBJetIPL3Tag", ohBJetIPL3Tag, &b_ohBJetIPL3Tag); 
  fChain->SetBranchAddress("ohBJetIPLooseL25Tag", ohBJetIPLooseL25Tag, &b_ohBJetIPLooseL25Tag); 
  fChain->SetBranchAddress("ohBJetIPLooseL3Tag", ohBJetIPLooseL3Tag, &b_ohBJetIPLooseL3Tag); 
  fChain->SetBranchAddress("ohBJetMuL25Tag", ohBJetMuL25Tag, &b_ohBJetMuL25Tag); 
  fChain->SetBranchAddress("ohBJetMuL3Tag", ohBJetMuL3Tag, &b_ohBJetMuL3Tag); 
  fChain->SetBranchAddress("ohBJetPerfL25Tag", ohBJetPerfL25Tag, &b_ohBJetPerfL25Tag); 
  fChain->SetBranchAddress("ohBJetPerfL3Tag", ohBJetPerfL3Tag, &b_ohBJetPerfL3Tag); 
  fChain->SetBranchAddress("NrecoElec", &NrecoElec, &b_NrecoElec);
  fChain->SetBranchAddress("recoElecPt", &recoElecPt, &b_recoElecPt);
  fChain->SetBranchAddress("recoElecPhi", &recoElecPhi, &b_recoElecPhi);
  fChain->SetBranchAddress("recoElecEta", &recoElecEta, &b_recoElecEta);
  fChain->SetBranchAddress("recoElecEt", &recoElecEt, &b_recoElecEt);
  fChain->SetBranchAddress("recoElecE", &recoElecE, &b_recoElecE);
  fChain->SetBranchAddress("NrecoPhot", &NrecoPhot, &b_NrecoPhot);
  fChain->SetBranchAddress("recoPhotPt", &recoPhotPt, &b_recoPhotPt);
  fChain->SetBranchAddress("recoPhotPhi", &recoPhotPhi, &b_recoPhotPhi);
  fChain->SetBranchAddress("recoPhotEta", &recoPhotEta, &b_recoPhotEta);
  fChain->SetBranchAddress("recoPhotEt", &recoPhotEt, &b_recoPhotEt);
  fChain->SetBranchAddress("recoPhotE", &recoPhotE, &b_recoPhotE);
  fChain->SetBranchAddress("NohPhot", &NohPhot, &b_NohPhot);
  fChain->SetBranchAddress("ohPhotEt", ohPhotEt, &b_ohPhotEt);
  fChain->SetBranchAddress("ohPhotEta", ohPhotEta, &b_ohPhotEta);
  fChain->SetBranchAddress("ohPhotPhi", ohPhotPhi, &b_ohPhotPhi);
  fChain->SetBranchAddress("ohPhotEiso", ohPhotEiso, &b_ohPhotEiso);
  fChain->SetBranchAddress("ohPhotHiso", ohPhotHiso, &b_ohPhotHiso);
  fChain->SetBranchAddress("ohPhotTiso", ohPhotTiso, &b_ohPhotTiso);
  fChain->SetBranchAddress("ohPhotL1iso", ohPhotL1iso, &b_ohPhotL1iso);
  fChain->SetBranchAddress("NohEle", &NohEle, &b_NohEle);
  fChain->SetBranchAddress("ohEleClusShap", ohEleClusShap, &b_ohEleClusShap);
  fChain->SetBranchAddress("ohEleDeta", ohEleDeta, &b_ohEleDeta);
  fChain->SetBranchAddress("ohEleDphi", ohEleDphi, &b_ohEleDphi);
  fChain->SetBranchAddress("ohEleEt", ohEleEt, &b_ohEleEt);
  fChain->SetBranchAddress("ohEleEta", ohEleEta, &b_ohEleEta);
  fChain->SetBranchAddress("ohElePhi", ohElePhi, &b_ohElePhi);
  fChain->SetBranchAddress("ohEleE", ohEleE, &b_ohEleE);
  fChain->SetBranchAddress("ohEleP", ohEleP, &b_ohEleP);
  fChain->SetBranchAddress("ohEleHiso", ohEleHiso, &b_ohEleHiso);
  fChain->SetBranchAddress("ohEleTiso", ohEleTiso, &b_ohEleTiso);
  fChain->SetBranchAddress("ohEleL1iso", ohEleL1iso, &b_ohEleL1iso);
  fChain->SetBranchAddress("ohElePixelSeeds", ohElePixelSeeds, &b_ohElePixelSeeds);
  fChain->SetBranchAddress("ohEleNewSC", ohEleNewSC, &b_ohEleNewSC);
  fChain->SetBranchAddress("NohEleLW", &NohEleLW, &b_NohEleLW);
  fChain->SetBranchAddress("ohEleClusShapLW", ohEleClusShapLW, &b_ohEleClusShapLW);
  fChain->SetBranchAddress("ohEleDetaLW", ohEleDetaLW, &b_ohEleDetaLW);
  fChain->SetBranchAddress("ohEleDphiLW", ohEleDphiLW, &b_ohEleDphiLW);
  fChain->SetBranchAddress("ohEleEtLW", ohEleEtLW, &b_ohEleEtLW);
  fChain->SetBranchAddress("ohEleEtaLW", ohEleEtaLW, &b_ohEleEtaLW);
  fChain->SetBranchAddress("ohElePhiLW", ohElePhiLW, &b_ohElePhiLW);
  fChain->SetBranchAddress("ohEleELW", ohEleELW, &b_ohEleELW);
  fChain->SetBranchAddress("ohElePLW", ohElePLW, &b_ohElePLW);
  fChain->SetBranchAddress("ohEleHisoLW", ohEleHisoLW, &b_ohEleHisoLW);
  fChain->SetBranchAddress("ohEleTisoLW", ohEleTisoLW, &b_ohEleTisoLW);
  fChain->SetBranchAddress("ohEleL1isoLW", ohEleL1isoLW, &b_ohEleL1isoLW);
  fChain->SetBranchAddress("ohElePixelSeedsLW", ohElePixelSeedsLW, &b_ohElePixelSeedsLW);
  fChain->SetBranchAddress("ohEleNewSCLW", ohEleNewSCLW, &b_ohEleNewSCLW);
  fChain->SetBranchAddress("NrecoMuon", &NrecoMuon, &b_NrecoMuon);
  fChain->SetBranchAddress("recoMuonPt", &recoMuonPt, &b_recoMuonPt);
  fChain->SetBranchAddress("recoMuonPhi", &recoMuonPhi, &b_recoMuonPhi);
  fChain->SetBranchAddress("recoMuonEta", &recoMuonEta, &b_recoMuonEta);
  fChain->SetBranchAddress("recoMuonEt", &recoMuonEt, &b_recoMuonEt);
  fChain->SetBranchAddress("recoMuonE", &recoMuonE, &b_recoMuonE);
  fChain->SetBranchAddress("NohMuL2", &NohMuL2, &b_NohMuL2);
  fChain->SetBranchAddress("ohMuL2Pt", ohMuL2Pt, &b_ohMuL2Pt);
  fChain->SetBranchAddress("ohMuL2Phi", ohMuL2Phi, &b_ohMuL2Phi);
  fChain->SetBranchAddress("ohMuL2Eta", ohMuL2Eta, &b_ohMuL2Eta);
  fChain->SetBranchAddress("ohMuL2Chg", ohMuL2Chg, &b_ohMuL2Chg);
  fChain->SetBranchAddress("ohMuL2PtErr", ohMuL2PtErr, &b_ohMuL2PtErr);
  fChain->SetBranchAddress("ohMuL2Iso", ohMuL2Iso, &b_ohMuL2Iso);
  fChain->SetBranchAddress("ohMuL2Dr", ohMuL2Dr, &b_ohMuL2Dr);
  fChain->SetBranchAddress("ohMuL2Dz", ohMuL2Dz, &b_ohMuL2Dz);
  fChain->SetBranchAddress("NohMuL3", &NohMuL3, &b_NohMuL3);
  fChain->SetBranchAddress("ohMuL3Pt", ohMuL3Pt, &b_ohMuL3Pt);
  fChain->SetBranchAddress("ohMuL3Phi", ohMuL3Phi, &b_ohMuL3Phi);
  fChain->SetBranchAddress("ohMuL3Eta", ohMuL3Eta, &b_ohMuL3Eta);
  fChain->SetBranchAddress("ohMuL3Chg", ohMuL3Chg, &b_ohMuL3Chg);
  fChain->SetBranchAddress("ohMuL3PtErr", ohMuL3PtErr, &b_ohMuL3PtErr);
  fChain->SetBranchAddress("ohMuL3Iso", ohMuL3Iso, &b_ohMuL3Iso);
  fChain->SetBranchAddress("ohMuL3Dr", ohMuL3Dr, &b_ohMuL3Dr);
  fChain->SetBranchAddress("ohMuL3Dz", ohMuL3Dz, &b_ohMuL3Dz);
  fChain->SetBranchAddress("ohMuL3L2idx", ohMuL3L2idx, &b_ohMuL3L2idx);
  fChain->SetBranchAddress("ohHighestEnergyEERecHit", &ohHighestEnergyEERecHit, &b_ohHighestEnergyEERecHit); 
  fChain->SetBranchAddress("ohHighestEnergyEBRecHit", &ohHighestEnergyEBRecHit, &b_ohHighestEnergyEBRecHit); 
  fChain->SetBranchAddress("ohHighestEnergyHBHERecHit", &ohHighestEnergyHBHERecHit, &b_ohHighestEnergyHBHERecHit); 
  fChain->SetBranchAddress("ohHighestEnergyHORecHit", &ohHighestEnergyHORecHit, &b_ohHighestEnergyHORecHit); 
  fChain->SetBranchAddress("ohHighestEnergyHFRecHit", &ohHighestEnergyHFRecHit, &b_ohHighestEnergyHFRecHit); 
  fChain->SetBranchAddress("Nalcapi0clusters", &Nalcapi0clusters, &b_Nalcapi0clusters); 
  fChain->SetBranchAddress("ohAlcapi0ptClusAll", ohAlcapi0ptClusAll, &b_ohAlcapi0ptClusAll); 
  fChain->SetBranchAddress("ohAlcapi0etaClusAll", ohAlcapi0etaClusAll, &b_ohAlcapi0etaClusAll); 
  fChain->SetBranchAddress("ohAlcapi0phiClusAll", ohAlcapi0phiClusAll, &b_ohAlcapi0phiClusAll); 
  fChain->SetBranchAddress("ohAlcapi0s4s9ClusAll", ohAlcapi0s4s9ClusAll, &b_ohAlcapi0s4s9ClusAll); 
  fChain->SetBranchAddress("NohPixelTracksL3", &NohPixelTracksL3, &b_NohPixelTracksL3);
  fChain->SetBranchAddress("ohPixelTracksL3Pt", ohPixelTracksL3Pt, &b_ohPixelTracksL3Pt);
  fChain->SetBranchAddress("ohPixelTracksL3Eta", ohPixelTracksL3Eta, &b_ohPixelTracksL3Eta);
  fChain->SetBranchAddress("ohPixelTracksL3Phi", ohPixelTracksL3Phi, &b_ohPixelTracksL3Phi); 
  fChain->SetBranchAddress("ohPixelTracksL3Vz", ohPixelTracksL3Vz, &b_ohPixelTracksL3Vz);

  fChain->SetBranchAddress("NohOniaPixel", &NohOniaPixel, &b_NohOniaPixel); 
  fChain->SetBranchAddress("ohOniaPixelPt", ohOniaPixelPt, &b_ohOniaPixelPt); 
  fChain->SetBranchAddress("ohOniaPixelPhi", ohOniaPixelPhi, &b_ohOniaPixelPhi); 
  fChain->SetBranchAddress("ohOniaPixelEta", ohOniaPixelEta, &b_ohOniaPixelEta); 
  fChain->SetBranchAddress("ohOniaPixelChg", ohOniaPixelChg, &b_ohOniaPixelChg); 
  fChain->SetBranchAddress("ohOniaPixelDr", ohOniaPixelDr, &b_ohOniaPixelDr); 
  fChain->SetBranchAddress("ohOniaPixelDz", ohOniaPixelDz, &b_ohOniaPixelDz); 
  fChain->SetBranchAddress("ohOniaPixelHits", ohOniaPixelHits, &b_ohOniaPixelHits); 
  fChain->SetBranchAddress("ohOniaPixelNormChi2", ohOniaPixelNormChi2, &b_ohOniaPixelNormChi2); 
  fChain->SetBranchAddress("NohOniaTrack", &NohOniaTrack, &b_NohOniaTrack); 
  fChain->SetBranchAddress("ohOniaTrackPt", ohOniaTrackPt, &b_ohOniaTrackPt); 
  fChain->SetBranchAddress("ohOniaTrackPhi", ohOniaTrackPhi, &b_ohOniaTrackPhi); 
  fChain->SetBranchAddress("ohOniaTrackEta", ohOniaTrackEta, &b_ohOniaTrackEta); 
  fChain->SetBranchAddress("ohOniaTrackChg", ohOniaTrackChg, &b_ohOniaTrackChg); 
  fChain->SetBranchAddress("ohOniaTrackDr", ohOniaTrackDr, &b_ohOniaTrackDr); 
  fChain->SetBranchAddress("ohOniaTrackDz", ohOniaTrackDz, &b_ohOniaTrackDz); 
  fChain->SetBranchAddress("ohOniaTrackHits", ohOniaTrackHits, &b_ohOniaTrackHits); 
  fChain->SetBranchAddress("ohOniaTrackNormChi2", ohOniaTrackNormChi2, &b_ohOniaTrackNormChi2); 

  fChain->SetBranchAddress("NMCpart", &NMCpart, &b_NMCpart);
  fChain->SetBranchAddress("MCpid", MCpid, &b_MCpid);
  fChain->SetBranchAddress("MCstatus", MCstatus, &b_MCstatus);
  fChain->SetBranchAddress("MCvtxX", MCvtxX, &b_MCvtxX);
  fChain->SetBranchAddress("MCvtxY", MCvtxY, &b_MCvtxY);
  fChain->SetBranchAddress("MCvtxZ", MCvtxZ, &b_MCvtxZ);
  fChain->SetBranchAddress("MCpt", MCpt, &b_MCpt);
  fChain->SetBranchAddress("MCeta", MCeta, &b_MCeta);
  fChain->SetBranchAddress("MCphi", MCphi, &b_MCphi);
  fChain->SetBranchAddress("MCPtHat", &MCPtHat, &b_MCPtHat);
  fChain->SetBranchAddress("MCmu3", &MCmu3, &b_MCmu3);
  fChain->SetBranchAddress("MCel3", &MCel3, &b_MCel3);
  fChain->SetBranchAddress("MCbb", &MCbb, &b_MCbb);
  fChain->SetBranchAddress("MCab", &MCab, &b_MCab);
  fChain->SetBranchAddress("MCWenu", &MCWenu, &b_MCWenu);
  fChain->SetBranchAddress("MCWmunu", &MCWmunu, &b_MCmunu);
  fChain->SetBranchAddress("MCZee", &MCZee, &b_MCZee);
  fChain->SetBranchAddress("MCZmumu", &MCZmumu, &b_MCZmumu);
  fChain->SetBranchAddress("MCptEleMax", &MCptEleMax, &b_MCptEleMax);
  fChain->SetBranchAddress("MCptMuMax", &MCptMuMax, &b_MCptMuMax);
  fChain->SetBranchAddress("NL1IsolEm", &NL1IsolEm, &b_NL1IsolEm);
  fChain->SetBranchAddress("L1IsolEmEt", L1IsolEmEt, &b_L1IsolEmEt);
  fChain->SetBranchAddress("L1IsolEmE", L1IsolEmE, &b_L1IsolEmE);
  fChain->SetBranchAddress("L1IsolEmEta", L1IsolEmEta, &b_L1IsolEmEta);
  fChain->SetBranchAddress("L1IsolEmPhi", L1IsolEmPhi, &b_L1IsolEmPhi);
  fChain->SetBranchAddress("NL1NIsolEm", &NL1NIsolEm, &b_NL1NIsolEm);
  fChain->SetBranchAddress("L1NIsolEmEt", L1NIsolEmEt, &b_L1NIsolEmEt);
  fChain->SetBranchAddress("L1NIsolEmE", L1NIsolEmE, &b_L1NIsolEmE);
  fChain->SetBranchAddress("L1NIsolEmEta", L1NIsolEmEta, &b_L1NIsolEmEta);
  fChain->SetBranchAddress("L1NIsolEmPhi", L1NIsolEmPhi, &b_L1NIsolEmPhi);
  fChain->SetBranchAddress("NL1Mu", &NL1Mu, &b_NL1Mu);
  fChain->SetBranchAddress("L1MuPt", L1MuPt, &b_L1MuPt);
  fChain->SetBranchAddress("L1MuE", L1MuE, &b_L1MuE);
  fChain->SetBranchAddress("L1MuEta", L1MuEta, &b_L1MuEta);
  fChain->SetBranchAddress("L1MuPhi", L1MuPhi, &b_L1MuPhi);
  fChain->SetBranchAddress("L1MuIsol", L1MuIsol, &b_L1MuIsol);
  fChain->SetBranchAddress("L1MuMip", L1MuMip, &b_L1MuMip);
  fChain->SetBranchAddress("L1MuFor", L1MuFor, &b_L1MuFor);
  fChain->SetBranchAddress("L1MuRPC", L1MuRPC, &b_L1MuRPC);
  fChain->SetBranchAddress("L1MuQal", L1MuQal, &b_L1MuQal);
  fChain->SetBranchAddress("NL1CenJet", &NL1CenJet, &b_NL1CenJet);
  fChain->SetBranchAddress("L1CenJetEt", L1CenJetEt, &b_L1CenJetEt);
  fChain->SetBranchAddress("L1CenJetE", L1CenJetE, &b_L1CenJetE);
  fChain->SetBranchAddress("L1CenJetEta", L1CenJetEta, &b_L1CenJetEta);
  fChain->SetBranchAddress("L1CenJetPhi", L1CenJetPhi, &b_L1CenJetPhi);
  fChain->SetBranchAddress("NL1ForJet", &NL1ForJet, &b_NL1ForJet);
  fChain->SetBranchAddress("L1ForJetEt", L1ForJetEt, &b_L1ForJetEt);
  fChain->SetBranchAddress("L1ForJetE", L1ForJetE, &b_L1ForJetE);
  fChain->SetBranchAddress("L1ForJetEta", L1ForJetEta, &b_L1ForJetEta);
  fChain->SetBranchAddress("L1ForJetPhi", L1ForJetPhi, &b_L1ForJetPhi);
  fChain->SetBranchAddress("NL1Tau", &NL1Tau, &b_NL1Tau);
  fChain->SetBranchAddress("L1TauEt", L1TauEt, &b_L1TauEt);
  fChain->SetBranchAddress("L1TauE", L1TauE, &b_L1TauE);
  fChain->SetBranchAddress("L1TauEta", L1TauEta, &b_L1TauEta);
  fChain->SetBranchAddress("L1TauPhi", L1TauPhi, &b_L1TauPhi);
  fChain->SetBranchAddress("L1Met", &L1Met, &b_L1Met);
  fChain->SetBranchAddress("L1MetPhi", &L1MetPhi, &b_L1MetPhi);
  fChain->SetBranchAddress("L1MetTot", &L1MetTot, &b_L1MetTot);
  fChain->SetBranchAddress("L1MetHad", &L1MetHad, &b_L1MetHad);
  fChain->SetBranchAddress("L1HfRing0EtSumPositiveEta", &L1HfRing0EtSumPositiveEta, &b_L1HfRing0EtSumPositiveEta);
  fChain->SetBranchAddress("L1HfRing1EtSumPositiveEta", &L1HfRing1EtSumPositiveEta, &b_L1HfRing1EtSumPositiveEta);
  fChain->SetBranchAddress("L1HfRing0EtSumNegativeEta", &L1HfRing0EtSumNegativeEta, &b_L1HfRing0EtSumNegativeEta);
  fChain->SetBranchAddress("L1HfRing1EtSumNegativeEta", &L1HfRing1EtSumNegativeEta, &b_L1HfRing1EtSumNegativeEta);
  fChain->SetBranchAddress("L1HfTowerCountPositiveEta", &L1HfTowerCountPositiveEta, &b_L1HfTowerCountPositiveEta);
  fChain->SetBranchAddress("L1HfTowerCountNegativeEta", &L1HfTowerCountNegativeEta, &b_L1HfTowerCountNegativeEta);
  fChain->SetBranchAddress("Run", &Run, &b_Run);
  fChain->SetBranchAddress("Event", &Event, &b_Event);
  fChain->SetBranchAddress("LumiBlock", &LumiBlock, &b_LumiBlock); 
  fChain->SetBranchAddress("Bx", &Bx, &b_Bx); 
  fChain->SetBranchAddress("Orbit", &Orbit, &b_Orbit); 
  //20X

  fChain->SetBranchAddress("L1_DoubleMuTopBottom", &L1_DoubleMuTopBottom, &b_L1_DoubleMuTopBottom); 
  fChain->SetBranchAddress("L1_DoubleEG05_TopBottom", &L1_DoubleEG05_TopBottom, &b_L1_DoubleEG05_TopBottom); 
  fChain->SetBranchAddress("L1_IsoEG10_Jet6_ForJet6", &L1_IsoEG10_Jet6_ForJet6, &b_L1_IsoEG10_Jet6_ForJet6); 


  fChain->SetBranchAddress("L1_SingleJet20", &L1_SingleJet20, &b_L1_SingleJet20); 
  fChain->SetBranchAddress("L1_SingleJet40", &L1_SingleJet40, &b_L1_SingleJet40); 
  fChain->SetBranchAddress("L1_SingleJet60", &L1_SingleJet60, &b_L1_SingleJet60); 
  fChain->SetBranchAddress("L1_SingleTauJet10", &L1_SingleTauJet10, &b_L1_SingleTauJet10); 
  fChain->SetBranchAddress("L1_SingleTauJet20", &L1_SingleTauJet20, &b_L1_SingleTauJet20); 
  fChain->SetBranchAddress("L1_SingleTauJet50", &L1_SingleTauJet50, &b_L1_SingleTauJet50); 
  fChain->SetBranchAddress("L1_DoubleJet30", &L1_DoubleJet30, &b_L1_DoubleJet30);   
  
  //L1's
  fChain->SetBranchAddress("L1_TripleJet14", &L1_TripleJet14, &b_L1_TripleJet14);  
  fChain->SetBranchAddress("L1_QuadJet6", &L1_QuadJet6, &b_L1_QuadJet6); 

  fChain->SetBranchAddress("L1_Mu5_Jet6", &L1_Mu5_Jet6, &b_L1_Mu5_Jet6);
  fChain->SetBranchAddress("L1_EG5_TripleJet6", &L1_EG5_TripleJet6, &b_L1_EG5_TripleJet6);
  fChain->SetBranchAddress("L1_SingleJet6", &L1_SingleJet6, &b_L1_SingleJet6);
  fChain->SetBranchAddress("L1_SingleJet10", &L1_SingleJet10, &b_L1_SingleJet10);

  fChain->SetBranchAddress("L1_DoubleEG1", &L1_DoubleEG1, &b_L1_DoubleEG1); 
  fChain->SetBranchAddress("L1_DoubleEG2", &L1_DoubleEG2, &b_L1_DoubleEG2); 
  fChain->SetBranchAddress("L1_DoubleEG5", &L1_DoubleEG5, &b_L1_DoubleEG5); 
  fChain->SetBranchAddress("L1_DoubleHfBitCountsRing1_P1N1", &L1_DoubleHfBitCountsRing1_P1N1, &b_L1_DoubleHfBitCountsRing1_P1N1); 
  fChain->SetBranchAddress("L1_DoubleHfBitCountsRing2_P1N1", &L1_DoubleHfBitCountsRing2_P1N1, &b_L1_DoubleHfBitCountsRing2_P1N1); 
  fChain->SetBranchAddress("L1_DoubleHfRingEtSumsRing1_P200N200", &L1_DoubleHfRingEtSumsRing1_P200N200, &b_L1_DoubleHfRingEtSumsRing1_P200N200); 
  fChain->SetBranchAddress("L1_DoubleHfRingEtSumsRing1_P4N4", &L1_DoubleHfRingEtSumsRing1_P4N4, &b_L1_DoubleHfRingEtSumsRing1_P4N4); 
  fChain->SetBranchAddress("L1_DoubleHfRingEtSumsRing2_P200N200", &L1_DoubleHfRingEtSumsRing2_P200N200, &b_L1_DoubleHfRingEtSumsRing2_P200N200); 
  fChain->SetBranchAddress("L1_DoubleHfRingEtSumsRing2_P4N4", &L1_DoubleHfRingEtSumsRing2_P4N4, &b_L1_DoubleHfRingEtSumsRing2_P4N4); 
  fChain->SetBranchAddress("L1_DoubleJet70", &L1_DoubleJet70, &b_L1_DoubleJet70); 
  fChain->SetBranchAddress("L1_DoubleMu3", &L1_DoubleMu3, &b_L1_DoubleMu3); 
  fChain->SetBranchAddress("L1_DoubleMuOpen", &L1_DoubleMuOpen, &b_L1_DoubleMuOpen); 
  fChain->SetBranchAddress("L1_DoubleTauJet30", &L1_DoubleTauJet30, &b_L1_DoubleTauJet30); 
  fChain->SetBranchAddress("L1_EG10_Jet15", &L1_EG10_Jet15, &b_L1_EG10_Jet15); 
  fChain->SetBranchAddress("L1_EG5_TripleJet15", &L1_EG5_TripleJet15, &b_L1_EG5_TripleJet15); 
  fChain->SetBranchAddress("L1_ETM20", &L1_ETM20, &b_L1_ETM20); 
  fChain->SetBranchAddress("L1_ETM30", &L1_ETM30, &b_L1_ETM30);
  fChain->SetBranchAddress("L1_ETM40", &L1_ETM40, &b_L1_ETM40); 
  fChain->SetBranchAddress("L1_ETM70", &L1_ETM70, &b_L1_ETM70); 
  fChain->SetBranchAddress("L1_ETM80", &L1_ETM80, &b_L1_ETM80); 
  fChain->SetBranchAddress("L1_ETT60", &L1_ETT60, &b_L1_ETT60); 
  fChain->SetBranchAddress("L1_HTT50", &L1_HTT50, &b_L1_HTT50); 
  fChain->SetBranchAddress("L1_HTT100", &L1_HTT100, &b_L1_HTT100); 
  fChain->SetBranchAddress("L1_HTT200", &L1_HTT200, &b_L1_HTT200); 
  fChain->SetBranchAddress("L1_HTT300", &L1_HTT300, &b_L1_HTT300); 
  fChain->SetBranchAddress("L1_IsoEG10_Jet15_ForJet10", &L1_IsoEG10_Jet15_ForJet10, &b_L1_IsoEG10_Jet15_ForJet10); 
  fChain->SetBranchAddress("L1_MinBias_HTT10", &L1_MinBias_HTT10, &b_L1_MinBias_HTT10); 
  fChain->SetBranchAddress("L1_Mu3QE8_EG5", &L1_Mu3QE8_EG5, &b_L1_Mu3QE8_EG5); 
  fChain->SetBranchAddress("L1_Mu3QE8_Jet15", &L1_Mu3QE8_Jet15, &b_L1_Mu3QE8_Jet15);  
  fChain->SetBranchAddress("L1_Mu5QE8_Jet15", &L1_Mu5QE8_Jet15, &b_L1_Mu5QE8_Jet15); 
  fChain->SetBranchAddress("L1_Mu3QE8_Jet6", &L1_Mu3QE8_Jet6, &b_L1_Mu3QE8_Jet6);  
  fChain->SetBranchAddress("L1_Mu5QE8_Jet6", &L1_Mu5QE8_Jet6, &b_L1_Mu5QE8_Jet6); 
  fChain->SetBranchAddress("L1_QuadJet15", &L1_QuadJet15, &b_L1_QuadJet15); 
  fChain->SetBranchAddress("L1_SingleEG1", &L1_SingleEG1, &b_L1_SingleEG1); 
  fChain->SetBranchAddress("L1_SingleEG10", &L1_SingleEG10, &b_L1_SingleEG10); 
  fChain->SetBranchAddress("L1_SingleEG12", &L1_SingleEG12, &b_L1_SingleEG12); 
  fChain->SetBranchAddress("L1_SingleEG15", &L1_SingleEG15, &b_L1_SingleEG15); 
  fChain->SetBranchAddress("L1_SingleEG2", &L1_SingleEG2, &b_L1_SingleEG2); 
  fChain->SetBranchAddress("L1_SingleEG20", &L1_SingleEG20, &b_L1_SingleEG20); 
  fChain->SetBranchAddress("L1_SingleEG5", &L1_SingleEG5, &b_L1_SingleEG5); 
  fChain->SetBranchAddress("L1_SingleEG8", &L1_SingleEG8, &b_L1_SingleEG8); 
  fChain->SetBranchAddress("L1_SingleHfBitCountsRing1_1", &L1_SingleHfBitCountsRing1_1, &b_L1_SingleHfBitCountsRing1_1); 
  fChain->SetBranchAddress("L1_SingleHfBitCountsRing2_1", &L1_SingleHfBitCountsRing2_1, &b_L1_SingleHfBitCountsRing2_1); 
  fChain->SetBranchAddress("L1_SingleHfRingEtSumsRing1_200", &L1_SingleHfRingEtSumsRing1_200, &b_L1_SingleHfRingEtSumsRing1_200); 
  fChain->SetBranchAddress("L1_SingleHfRingEtSumsRing1_4", &L1_SingleHfRingEtSumsRing1_4, &b_L1_SingleHfRingEtSumsRing1_4); 
  fChain->SetBranchAddress("L1_SingleHfRingEtSumsRing2_200", &L1_SingleHfRingEtSumsRing2_200, &b_L1_SingleHfRingEtSumsRing2_200); 
  fChain->SetBranchAddress("L1_SingleHfRingEtSumsRing2_4", &L1_SingleHfRingEtSumsRing2_4, &b_L1_SingleHfRingEtSumsRing2_4); 
  fChain->SetBranchAddress("L1_SingleIsoEG10", &L1_SingleIsoEG10, &b_L1_SingleIsoEG10); 
  fChain->SetBranchAddress("L1_SingleIsoEG12", &L1_SingleIsoEG12, &b_L1_SingleIsoEG12); 
  fChain->SetBranchAddress("L1_SingleIsoEG15", &L1_SingleIsoEG15, &b_L1_SingleIsoEG15); 
  fChain->SetBranchAddress("L1_SingleIsoEG5", &L1_SingleIsoEG5, &b_L1_SingleIsoEG5); 
  fChain->SetBranchAddress("L1_SingleIsoEG8", &L1_SingleIsoEG8, &b_L1_SingleIsoEG8); 
  fChain->SetBranchAddress("L1_SingleJet100", &L1_SingleJet100, &b_L1_SingleJet100); 
  fChain->SetBranchAddress("L1_SingleJet15", &L1_SingleJet15, &b_L1_SingleJet15); 
  fChain->SetBranchAddress("L1_SingleJet30", &L1_SingleJet30, &b_L1_SingleJet30); 
  fChain->SetBranchAddress("L1_SingleJet50", &L1_SingleJet50, &b_L1_SingleJet50); 
  fChain->SetBranchAddress("L1_SingleJet70", &L1_SingleJet70, &b_L1_SingleJet70); 
  fChain->SetBranchAddress("L1_SingleMu0", &L1_SingleMu0, &b_L1_SingleMu0); 
  fChain->SetBranchAddress("L1_SingleMu10", &L1_SingleMu10, &b_L1_SingleMu10); 
  fChain->SetBranchAddress("L1_SingleMu14", &L1_SingleMu14, &b_L1_SingleMu14); 
  fChain->SetBranchAddress("L1_SingleMu20", &L1_SingleMu20, &b_L1_SingleMu20); 
  fChain->SetBranchAddress("L1_SingleMu3", &L1_SingleMu3, &b_L1_SingleMu3); 
  fChain->SetBranchAddress("L1_SingleMu5", &L1_SingleMu5, &b_L1_SingleMu5); 
  fChain->SetBranchAddress("L1_SingleMu7", &L1_SingleMu7, &b_L1_SingleMu7); 
  fChain->SetBranchAddress("L1_SingleMuBeamHalo", &L1_SingleMuBeamHalo, &b_L1_SingleMuBeamHalo); 
  fChain->SetBranchAddress("L1_SingleMuOpen", &L1_SingleMuOpen, &b_L1_SingleMuOpen); 
  fChain->SetBranchAddress("L1_SingleTauJet30", &L1_SingleTauJet30, &b_L1_SingleTauJet30); 
  fChain->SetBranchAddress("L1_SingleTauJet40", &L1_SingleTauJet40, &b_L1_SingleTauJet40); 
  fChain->SetBranchAddress("L1_SingleTauJet60", &L1_SingleTauJet60, &b_L1_SingleTauJet60); 
  fChain->SetBranchAddress("L1_SingleTauJet80", &L1_SingleTauJet80, &b_L1_SingleTauJet80); 
  fChain->SetBranchAddress("L1_TripleJet30", &L1_TripleJet30, &b_L1_TripleJet30); 
  fChain->SetBranchAddress("L1_ZeroBias", &L1_ZeroBias, &b_L1_ZeroBias);
  fChain->SetBranchAddress("L1_ZeroBias_Ext", &L1_ZeroBias_Ext, &b_L1_ZeroBias_Ext);
  fChain->SetBranchAddress("L1_SingleCenJet2", &L1_SingleCenJet2, &b_L1_SingleCenJet2);
  fChain->SetBranchAddress("L1_SingleCenJet4", &L1_SingleCenJet4, &b_L1_SingleCenJet4);
  fChain->SetBranchAddress("L1_SingleForJet2", &L1_SingleForJet2, &b_L1_SingleForJet2);
  fChain->SetBranchAddress("L1_SingleForJet4", &L1_SingleForJet4, &b_L1_SingleForJet4);
  fChain->SetBranchAddress("L1_SingleTauJet2", &L1_SingleTauJet2, &b_L1_SingleTauJet2);
  fChain->SetBranchAddress("L1_SingleTauJet4", &L1_SingleTauJet4, &b_L1_SingleTauJet4);
  fChain->SetBranchAddress("L1_DoubleForJet10_EtaOpp", &L1_DoubleForJet10_EtaOpp, &b_L1_DoubleForJet10_EtaOpp);

  // ccla - L1 Technical bits  (06Dec09)
  fChain->SetBranchAddress("L1Tech_BPTX_minus.v0", &L1Tech_BPTX_minus_v0, &b_L1Tech_BPTX_minus_v0);
  fChain->SetBranchAddress("L1Tech_BPTX_minus.v0_5bx", &L1Tech_BPTX_minus_v0_5bx, &b_L1Tech_BPTX_minus_v0_5bx);
  fChain->SetBranchAddress("L1Tech_BPTX_minus_AND_not_plus.v0", &L1Tech_BPTX_minus_AND_not_plus_v0, &b_L1Tech_BPTX_minus_AND_not_plus_v0);
  fChain->SetBranchAddress("L1Tech_BPTX_minus_AND_not_plus.v0_5bx", &L1Tech_BPTX_minus_AND_not_plus_v0_5bx, &b_L1Tech_BPTX_minus_AND_not_plus_v0_5bx);
  fChain->SetBranchAddress("L1Tech_BPTX_plus.v0", &L1Tech_BPTX_plus_v0, &b_L1Tech_BPTX_plus_v0);
  fChain->SetBranchAddress("L1Tech_BPTX_plus.v0_5bx", &L1Tech_BPTX_plus_v0_5bx, &b_L1Tech_BPTX_plus_v0_5bx);
  fChain->SetBranchAddress("L1Tech_BPTX_plus_AND_NOT_minus.v0", &L1Tech_BPTX_plus_AND_NOT_minus_v0, &b_L1Tech_BPTX_plus_AND_NOT_minus_v0);
  fChain->SetBranchAddress("L1Tech_BPTX_plus_AND_NOT_minus.v0_5bx", &L1Tech_BPTX_plus_AND_NOT_minus_v0_5bx, &b_L1Tech_BPTX_plus_AND_NOT_minus_v0_5bx);
  fChain->SetBranchAddress("L1Tech_BPTX_plus_AND_minus.v0", &L1Tech_BPTX_plus_AND_minus_v0, &b_L1Tech_BPTX_plus_AND_minus_v0);
  fChain->SetBranchAddress("L1Tech_BPTX_plus_AND_minus.v0_5bx", &L1Tech_BPTX_plus_AND_minus_v0_5bx, &b_L1Tech_BPTX_plus_AND_minus_v0_5bx);
  fChain->SetBranchAddress("L1Tech_BPTX_plus_AND_minus_instance1.v0", &L1Tech_BPTX_plus_AND_minus_instance1_v0, &b_L1Tech_BPTX_plus_AND_minus_instance1_v0);
  fChain->SetBranchAddress("L1Tech_BPTX_plus_AND_minus_instance1.v0_5bx", &L1Tech_BPTX_plus_AND_minus_instance1_v0_5bx, &b_L1Tech_BPTX_plus_AND_minus_instance1_v0_5bx);
  fChain->SetBranchAddress("L1Tech_BPTX_plus_OR_minus.v0", &L1Tech_BPTX_plus_OR_minus_v0, &b_L1Tech_BPTX_plus_OR_minus_v0);
  fChain->SetBranchAddress("L1Tech_BPTX_plus_OR_minus.v0_5bx", &L1Tech_BPTX_plus_OR_minus_v0_5bx, &b_L1Tech_BPTX_plus_OR_minus_v0_5bx);
  fChain->SetBranchAddress("L1Tech_BPTX_quiet.v0", &L1Tech_BPTX_quiet_v0, &b_L1Tech_BPTX_quiet_v0);
  fChain->SetBranchAddress("L1Tech_BPTX_quiet.v0_5bx", &L1Tech_BPTX_quiet_v0_5bx, &b_L1Tech_BPTX_quiet_v0_5bx);
  fChain->SetBranchAddress("L1Tech_BSC_HighMultiplicity.v0", &L1Tech_BSC_HighMultiplicity_v0, &b_L1Tech_BSC_HighMultiplicity_v0);
  fChain->SetBranchAddress("L1Tech_BSC_HighMultiplicity.v0_5bx", &L1Tech_BSC_HighMultiplicity_v0_5bx, &b_L1Tech_BSC_HighMultiplicity_v0_5bx);
  fChain->SetBranchAddress("L1Tech_BSC_halo_beam1_inner.v0", &L1Tech_BSC_halo_beam1_inner_v0, &b_L1Tech_BSC_halo_beam1_inner_v0);
  fChain->SetBranchAddress("L1Tech_BSC_halo_beam1_inner.v0_5bx", &L1Tech_BSC_halo_beam1_inner_v0_5bx, &b_L1Tech_BSC_halo_beam1_inner_v0_5bx);
  fChain->SetBranchAddress("L1Tech_BSC_halo_beam1_outer.v0", &L1Tech_BSC_halo_beam1_outer_v0, &b_L1Tech_BSC_halo_beam1_outer_v0);
  fChain->SetBranchAddress("L1Tech_BSC_halo_beam1_outer.v0_5bx", &L1Tech_BSC_halo_beam1_outer_v0_5bx, &b_L1Tech_BSC_halo_beam1_outer_v0_5bx);
  fChain->SetBranchAddress("L1Tech_BSC_halo_beam2_inner.v0", &L1Tech_BSC_halo_beam2_inner_v0, &b_L1Tech_BSC_halo_beam2_inner_v0);
  fChain->SetBranchAddress("L1Tech_BSC_halo_beam2_inner.v0_5bx", &L1Tech_BSC_halo_beam2_inner_v0_5bx, &b_L1Tech_BSC_halo_beam2_inner_v0_5bx);
  fChain->SetBranchAddress("L1Tech_BSC_halo_beam2_outer.v0", &L1Tech_BSC_halo_beam2_outer_v0, &b_L1Tech_BSC_halo_beam2_outer_v0);
  fChain->SetBranchAddress("L1Tech_BSC_halo_beam2_outer.v0_5bx", &L1Tech_BSC_halo_beam2_outer_v0_5bx, &b_L1Tech_BSC_halo_beam2_outer_v0_5bx);
  fChain->SetBranchAddress("L1Tech_BSC_minBias_OR.v0", &L1Tech_BSC_minBias_OR_v0, &b_L1Tech_BSC_minBias_OR_v0);
  fChain->SetBranchAddress("L1Tech_BSC_minBias_OR.v0_5bx", &L1Tech_BSC_minBias_OR_v0_5bx, &b_L1Tech_BSC_minBias_OR_v0_5bx);
  fChain->SetBranchAddress("L1Tech_BSC_minBias_inner_threshold1.v0", &L1Tech_BSC_minBias_inner_threshold1_v0, &b_L1Tech_BSC_minBias_inner_threshold1_v0);
  fChain->SetBranchAddress("L1Tech_BSC_minBias_inner_threshold1.v0_5bx", &L1Tech_BSC_minBias_inner_threshold1_v0_5bx, &b_L1Tech_BSC_minBias_inner_threshold1_v0_5bx);
  fChain->SetBranchAddress("L1Tech_BSC_minBias_inner_threshold2.v0", &L1Tech_BSC_minBias_inner_threshold2_v0, &b_L1Tech_BSC_minBias_inner_threshold2_v0);
  fChain->SetBranchAddress("L1Tech_BSC_minBias_inner_threshold2.v0_5bx", &L1Tech_BSC_minBias_inner_threshold2_v0_5bx, &b_L1Tech_BSC_minBias_inner_threshold2_v0_5bx);
  fChain->SetBranchAddress("L1Tech_BSC_minBias_threshold1.v0", &L1Tech_BSC_minBias_threshold1_v0, &b_L1Tech_BSC_minBias_threshold1_v0);
  fChain->SetBranchAddress("L1Tech_BSC_minBias_threshold1.v0_5bx", &L1Tech_BSC_minBias_threshold1_v0_5bx, &b_L1Tech_BSC_minBias_threshold1_v0_5bx);
  fChain->SetBranchAddress("L1Tech_BSC_minBias_threshold2.v0", &L1Tech_BSC_minBias_threshold2_v0, &b_L1Tech_BSC_minBias_threshold2_v0);
  fChain->SetBranchAddress("L1Tech_BSC_minBias_threshold2.v0_5bx", &L1Tech_BSC_minBias_threshold2_v0_5bx, &b_L1Tech_BSC_minBias_threshold2_v0_5bx);
  fChain->SetBranchAddress("L1Tech_BSC_splash_beam1.v0", &L1Tech_BSC_splash_beam1_v0, &b_L1Tech_BSC_splash_beam1_v0);
  fChain->SetBranchAddress("L1Tech_BSC_splash_beam1.v0_5bx", &L1Tech_BSC_splash_beam1_v0_5bx, &b_L1Tech_BSC_splash_beam1_v0_5bx);
  fChain->SetBranchAddress("L1Tech_BSC_splash_beam2.v0", &L1Tech_BSC_splash_beam2_v0, &b_L1Tech_BSC_splash_beam2_v0);
  fChain->SetBranchAddress("L1Tech_BSC_splash_beam2.v0_5bx", &L1Tech_BSC_splash_beam2_v0_5bx, &b_L1Tech_BSC_splash_beam2_v0_5bx);
  fChain->SetBranchAddress("L1Tech_HCAL_HBHE_totalOR.v0", &L1Tech_HCAL_HBHE_totalOR_v0, &b_L1Tech_HCAL_HBHE_totalOR_v0);
  fChain->SetBranchAddress("L1Tech_HCAL_HBHE_totalOR.v0_5bx", &L1Tech_HCAL_HBHE_totalOR_v0_5bx, &b_L1Tech_HCAL_HBHE_totalOR_v0_5bx);
  fChain->SetBranchAddress("L1Tech_HCAL_HF_totalOR_coincidenceHFM.v0", &L1Tech_HCAL_HF_totalOR_coincidenceHFM_v0, &b_L1Tech_HCAL_HF_totalOR_coincidenceHFM_v0);
  fChain->SetBranchAddress("L1Tech_HCAL_HF_totalOR_coincidenceHFM.v0_5bx", &L1Tech_HCAL_HF_totalOR_coincidenceHFM_v0_5bx, &b_L1Tech_HCAL_HF_totalOR_coincidenceHFM_v0_5bx);
  fChain->SetBranchAddress("L1Tech_HCAL_HF_totalOR_coincidenceHFP.v0", &L1Tech_HCAL_HF_totalOR_coincidenceHFP_v0, &b_L1Tech_HCAL_HF_totalOR_coincidenceHFP_v0);
  fChain->SetBranchAddress("L1Tech_HCAL_HF_totalOR_coincidenceHFP.v0_5bx", &L1Tech_HCAL_HF_totalOR_coincidenceHFP_v0_5bx, &b_L1Tech_HCAL_HF_totalOR_coincidenceHFP_v0_5bx);
  fChain->SetBranchAddress("L1Tech_HCAL_HF_totalOR_minBias.v0", &L1Tech_HCAL_HF_totalOR_minBias_v0, &b_L1Tech_HCAL_HF_totalOR_minBias_v0);
  fChain->SetBranchAddress("L1Tech_HCAL_HF_totalOR_minBias.v0_5bx", &L1Tech_HCAL_HF_totalOR_minBias_v0_5bx, &b_L1Tech_HCAL_HF_totalOR_minBias_v0_5bx);
  fChain->SetBranchAddress("L1Tech_HCAL_HO_totalOR.v0", &L1Tech_HCAL_HO_totalOR_v0, &b_L1Tech_HCAL_HO_totalOR_v0);
  fChain->SetBranchAddress("L1Tech_HCAL_HO_totalOR.v0_5bx", &L1Tech_HCAL_HO_totalOR_v0_5bx, &b_L1Tech_HCAL_HO_totalOR_v0_5bx);
  fChain->SetBranchAddress("L1Tech_RPC_TTU_RB0_Cosmics.v0", &L1Tech_RPC_TTU_RB0_Cosmics_v0, &b_L1Tech_RPC_TTU_RB0_Cosmics_v0);
  fChain->SetBranchAddress("L1Tech_RPC_TTU_RB0_Cosmics.v0_5bx", &L1Tech_RPC_TTU_RB0_Cosmics_v0_5bx, &b_L1Tech_RPC_TTU_RB0_Cosmics_v0_5bx);
  fChain->SetBranchAddress("L1Tech_RPC_TTU_RBminus1_Cosmics.v0", &L1Tech_RPC_TTU_RBminus1_Cosmics_v0, &b_L1Tech_RPC_TTU_RBminus1_Cosmics_v0);
  fChain->SetBranchAddress("L1Tech_RPC_TTU_RBminus1_Cosmics.v0_5bx", &L1Tech_RPC_TTU_RBminus1_Cosmics_v0_5bx, &b_L1Tech_RPC_TTU_RBminus1_Cosmics_v0_5bx);
  fChain->SetBranchAddress("L1Tech_RPC_TTU_RBminus2_Cosmics.v0", &L1Tech_RPC_TTU_RBminus2_Cosmics_v0, &b_L1Tech_RPC_TTU_RBminus2_Cosmics_v0);
  fChain->SetBranchAddress("L1Tech_RPC_TTU_RBminus2_Cosmics.v0_5bx", &L1Tech_RPC_TTU_RBminus2_Cosmics_v0_5bx, &b_L1Tech_RPC_TTU_RBminus2_Cosmics_v0_5bx);
  fChain->SetBranchAddress("L1Tech_RPC_TTU_RBplus1_Cosmics.v0", &L1Tech_RPC_TTU_RBplus1_Cosmics_v0, &b_L1Tech_RPC_TTU_RBplus1_Cosmics_v0);
  fChain->SetBranchAddress("L1Tech_RPC_TTU_RBplus1_Cosmics.v0_5bx", &L1Tech_RPC_TTU_RBplus1_Cosmics_v0_5bx, &b_L1Tech_RPC_TTU_RBplus1_Cosmics_v0_5bx);
  fChain->SetBranchAddress("L1Tech_RPC_TTU_RBplus2_Cosmics.v0", &L1Tech_RPC_TTU_RBplus2_Cosmics_v0, &b_L1Tech_RPC_TTU_RBplus2_Cosmics_v0);
  fChain->SetBranchAddress("L1Tech_RPC_TTU_RBplus2_Cosmics.v0_5bx", &L1Tech_RPC_TTU_RBplus2_Cosmics_v0_5bx, &b_L1Tech_RPC_TTU_RBplus2_Cosmics_v0_5bx);
  fChain->SetBranchAddress("L1Tech_RPC_TTU_barrel_Cosmics.v0", &L1Tech_RPC_TTU_barrel_Cosmics_v0, &b_L1Tech_RPC_TTU_barrel_Cosmics_v0);
  fChain->SetBranchAddress("L1Tech_RPC_TTU_barrel_Cosmics.v0_5bx", &L1Tech_RPC_TTU_barrel_Cosmics_v0_5bx, &b_L1Tech_RPC_TTU_barrel_Cosmics_v0_5bx);
  fChain->SetBranchAddress("L1Tech_RPC_TTU_pointing_Cosmics.v0", &L1Tech_RPC_TTU_pointing_Cosmics_v0, &b_L1Tech_RPC_TTU_pointing_Cosmics_v0);
  fChain->SetBranchAddress("L1Tech_RPC_TTU_pointing_Cosmics.v0_5bx", &L1Tech_RPC_TTU_pointing_Cosmics_v0_5bx, &b_L1Tech_RPC_TTU_pointing_Cosmics_v0_5bx);
  fChain->SetBranchAddress("L1Tech_RPC_TTU_RBst1_collisions.v0", &L1Tech_RPC_TTU_RBst1_collisions_v0, &b_L1Tech_RPC_TTU_RBst1_collisions_v0);
  fChain->SetBranchAddress("L1Tech_RPC_TTU_RBst1_collisions.v0_5bx", &L1Tech_RPC_TTU_RBst1_collisions_v0_5bx, &b_L1Tech_RPC_TTU_RBst1_collisions_v0_5bx);

  fChain->SetBranchAddress("L1Tech_HCAL_HF_MM_or_PP_or_PM.v0", &L1Tech_HCAL_HF_MM_or_PP_or_PM_v0, &b_L1Tech_HCAL_HF_MM_or_PP_or_PM_v0);
  fChain->SetBranchAddress("L1Tech_HCAL_HF_MM_or_PP_or_PM.v0_5bx", &L1Tech_HCAL_HF_MM_or_PP_or_PM_v0_5bx, &b_L1Tech_HCAL_HF_MM_or_PP_or_PM_v0_5bx);
  fChain->SetBranchAddress("L1Tech_HCAL_HF_coincidence_PM.v1", &L1Tech_HCAL_HF_coincidence_PM_v1, &b_L1Tech_HCAL_HF_coincidence_PM_v1);
  fChain->SetBranchAddress("L1Tech_HCAL_HF_coincidence_PM.v1_5bx", &L1Tech_HCAL_HF_coincidence_PM_v1_5bx, &b_L1Tech_HCAL_HF_coincidence_PM_v1_5bx);
  fChain->SetBranchAddress("L1Tech_HCAL_HF_MMP_or_MPP.v0", &L1Tech_HCAL_HF_MMP_or_MPP_v0, &b_L1Tech_HCAL_HF_MMP_or_MPP_v0);
  fChain->SetBranchAddress("L1Tech_HCAL_HF_MMP_or_MPP.v0_5bx", &L1Tech_HCAL_HF_MMP_or_MPP_v0_5bx, &b_L1Tech_HCAL_HF_MMP_or_MPP_v0_5bx);

  fChain->SetBranchAddress("L1Tech_ZDC_loose_vertex.v0", &L1Tech_ZDC_loose_vertex_v0, &b_L1Tech_ZDC_loose_vertex_v0);
  fChain->SetBranchAddress("L1Tech_ZDC_loose_vertex.v0_5bx", &L1Tech_ZDC_loose_vertex_v0_5bx, &b_L1Tech_ZDC_loose_vertex_v0_5bx);
  fChain->SetBranchAddress("L1Tech_ZDC_minus_over_threshold.v0", &L1Tech_ZDC_minus_over_threshold_v0, &b_L1Tech_ZDC_minus_over_threshold_v0);
  fChain->SetBranchAddress("L1Tech_ZDC_minus_over_threshold.v0_5bx", &L1Tech_ZDC_minus_over_threshold_v0_5bx, &b_L1Tech_ZDC_minus_over_threshold_v0_5bx);
  fChain->SetBranchAddress("L1Tech_ZDC_plus_over_threshold.v0", &L1Tech_ZDC_plus_over_threshold_v0, &b_L1Tech_ZDC_plus_over_threshold_v0);
  fChain->SetBranchAddress("L1Tech_ZDC_plus_over_threshold.v0_5bx", &L1Tech_ZDC_plus_over_threshold_v0_5bx, &b_L1Tech_ZDC_plus_over_threshold_v0_5bx);
  fChain->SetBranchAddress("L1Tech_ZDC_tight_vertex.v0", &L1Tech_ZDC_tight_vertex_v0, &b_L1Tech_ZDC_tight_vertex_v0);
  fChain->SetBranchAddress("L1Tech_ZDC_tight_vertex.v0_5bx", &L1Tech_ZDC_tight_vertex_v0_5bx, &b_L1Tech_ZDC_tight_vertex_v0_5bx);

  fChain->SetBranchAddress("L1_BptxMinus", &L1_BptxMinus, &b_L1_BptxMinus);
  fChain->SetBranchAddress("L1_BptxMinus_5bx", &L1_BptxMinus_5bx, &b_L1_BptxMinus_5bx);
  fChain->SetBranchAddress("L1_BptxPlus", &L1_BptxPlus, &b_L1_BptxPlus);
  fChain->SetBranchAddress("L1_BptxPlus_5bx", &L1_BptxPlus_5bx, &b_L1_BptxPlus_5bx);
  fChain->SetBranchAddress("L1_BptxPlusORMinus", &L1_BptxPlusORMinus, &b_L1_BptxPlusORMinus);
  fChain->SetBranchAddress("L1_BptxPlusORMinus_5bx", &L1_BptxPlusORMinus_5bx, &b_L1_BptxPlusORMinus_5bx);
  fChain->SetBranchAddress("L1_BptxPlus_NotBptxMinus", &L1_BptxPlus_NotBptxMinus, &b_L1_BptxPlus_NotBptxMinus);
  fChain->SetBranchAddress("L1_BptxPlus_NotBptxMinus_5bx", &L1_BptxPlus_NotBptxMinus_5bx, &b_L1_BptxPlus_NotBptxMinus_5bx);
  fChain->SetBranchAddress("L1_BptxMinus_NotBptxPlus", &L1_BptxMinus_NotBptxPlus, &b_L1_BptxMinus_NotBptxPlus);
  fChain->SetBranchAddress("L1_BptxMinus_NotBptxPlus_5bx", &L1_BptxMinus_NotBptxPlus_5bx, &b_L1_BptxMinus_NotBptxPlus_5bx);

  fChain->SetBranchAddress("L1_BscHighMultiplicity", &L1_BscHighMultiplicity, &b_L1_BscHighMultiplicity);
  fChain->SetBranchAddress("L1_BscHighMultiplicity_5bx", &L1_BscHighMultiplicity_5bx, &b_L1_BscHighMultiplicity_5bx);
  fChain->SetBranchAddress("L1_BscMinBiasInnerThreshold1", &L1_BscMinBiasInnerThreshold1, &b_L1_BscMinBiasInnerThreshold1);
  fChain->SetBranchAddress("L1_BscMinBiasInnerThreshold1_5bx", &L1_BscMinBiasInnerThreshold1_5bx, &b_L1_BscMinBiasInnerThreshold1_5bx);
  fChain->SetBranchAddress("L1_BscMinBiasInnerThreshold2", &L1_BscMinBiasInnerThreshold2, &b_L1_BscMinBiasInnerThreshold2);
  fChain->SetBranchAddress("L1_BscMinBiasInnerThreshold2_5bx", &L1_BscMinBiasInnerThreshold2_5bx, &b_L1_BscMinBiasInnerThreshold2_5bx);
  fChain->SetBranchAddress("L1_BscMinBiasOR", &L1_BscMinBiasOR, &b_L1_BscMinBiasOR);
  fChain->SetBranchAddress("L1_BscMinBiasOR_5bx", &L1_BscMinBiasOR_5bx, &b_L1_BscMinBiasOR_5bx);
  fChain->SetBranchAddress("L1_BscMinBiasOR_BptxPlusORMinus", &L1_BscMinBiasOR_BptxPlusORMinus, &b_L1_BscMinBiasOR_BptxPlusORMinus);
  fChain->SetBranchAddress("L1_BscMinBiasOR_BptxPlusORMinus_5bx", &L1_BscMinBiasOR_BptxPlusORMinus_5bx, &b_L1_BscMinBiasOR_BptxPlusORMinus_5bx);


  // JH - 1E31 MC menu
  fChain->SetBranchAddress("HLT_L1Jet15", &HLT_L1Jet15, &b_HLT_L1Jet15); 
  fChain->SetBranchAddress("HLT_Jet30", &HLT_Jet30, &b_HLT_Jet30); 
  fChain->SetBranchAddress("HLT_Jet50", &HLT_Jet50, &b_HLT_Jet50); 
  fChain->SetBranchAddress("HLT_Jet80", &HLT_Jet80, &b_HLT_Jet80); 
  fChain->SetBranchAddress("HLT_Jet110", &HLT_Jet110, &b_HLT_Jet110); 
  fChain->SetBranchAddress("HLT_Jet140", &HLT_Jet140, &b_HLT_Jet140); 
  fChain->SetBranchAddress("HLT_Jet180", &HLT_Jet180, &b_HLT_Jet180); 
  fChain->SetBranchAddress("HLT_FwdJet40", &HLT_FwdJet40, &b_HLT_FwdJet40); 
  fChain->SetBranchAddress("HLT_DiJetAve15U_1E31", &HLT_DiJetAve15U_1E31, &b_HLT_DiJetAve15U_1E31); 
  fChain->SetBranchAddress("HLT_DiJetAve30U_1E31", &HLT_DiJetAve30U_1E31, &b_HLT_DiJetAve30U_1E31); 
  fChain->SetBranchAddress("HLT_DiJetAve50U", &HLT_DiJetAve50U, &b_HLT_DiJetAve50U); 
  fChain->SetBranchAddress("HLT_DiJetAve70U", &HLT_DiJetAve70U, &b_HLT_DiJetAve70U); 
  fChain->SetBranchAddress("HLT_DiJetAve130U", &HLT_DiJetAve130U, &b_HLT_DiJetAve130U); 
  fChain->SetBranchAddress("HLT_QuadJet30", &HLT_QuadJet30, &b_HLT_QuadJet30); 
  fChain->SetBranchAddress("HLT_SumET120", &HLT_SumET120, &b_HLT_SumET120); 
  fChain->SetBranchAddress("HLT_L1MET20", &HLT_L1MET20, &b_HLT_L1MET20); 
  fChain->SetBranchAddress("HLT_MET35", &HLT_MET35, &b_HLT_MET35); 
  fChain->SetBranchAddress("HLT_MET60", &HLT_MET60, &b_HLT_MET60); 
  fChain->SetBranchAddress("HLT_HT200", &HLT_HT200, &b_HLT_HT200); 
  fChain->SetBranchAddress("HLT_HT300_MHT100", &HLT_HT300_MHT100, &b_HLT_HT300_MHT100); 
  fChain->SetBranchAddress("HLT_L1MuOpen", &HLT_L1MuOpen, &b_HLT_L1MuOpen); 
  fChain->SetBranchAddress("HLT_L1Mu", &HLT_L1Mu, &b_HLT_L1Mu); 
  fChain->SetBranchAddress("HLT_L1Mu20HQ", &HLT_L1Mu20HQ, &b_HLT_L1Mu20HQ); 
  fChain->SetBranchAddress("HLT_L1Mu30", &HLT_L1Mu30, &b_HLT_L1Mu30); 
  fChain->SetBranchAddress("HLT_IsoMu9", &HLT_IsoMu9, &b_HLT_IsoMu9); 
  fChain->SetBranchAddress("HLT_Mu5", &HLT_Mu5, &b_HLT_Mu5); 
  fChain->SetBranchAddress("HLT_Mu9", &HLT_Mu9, &b_HLT_Mu9); 
  fChain->SetBranchAddress("HLT_Mu11", &HLT_Mu11, &b_HLT_Mu11); 
  fChain->SetBranchAddress("HLT_Mu15", &HLT_Mu15, &b_HLT_Mu15); 
  fChain->SetBranchAddress("HLT_DoubleMu3", &HLT_DoubleMu3, &b_HLT_DoubleMu3); 
  fChain->SetBranchAddress("HLT_Ele10_SW_L1R", &HLT_Ele10_SW_L1R, &b_HLT_Ele10_SW_L1R); 
  fChain->SetBranchAddress("HLT_Ele15_SW_L1R", &HLT_Ele15_SW_L1R, &b_HLT_Ele15_SW_L1R); 
  fChain->SetBranchAddress("HLT_Ele15_SW_EleId_L1R", &HLT_Ele15_SW_EleId_L1R, &b_HLT_Ele15_SW_EleId_L1R); 
  fChain->SetBranchAddress("HLT_Ele15_SW_LooseTrackIso_L1R", &HLT_Ele15_SW_LooseTrackIso_L1R, &b_HLT_Ele15_SW_LooseTrackIso_L1R); 
  fChain->SetBranchAddress("HLT_Ele15_SC15_SW_LooseTrackIso_L1R", &HLT_Ele15_SC15_SW_LooseTrackIso_L1R, &b_HLT_Ele15_SC15_SW_LooseTrackIso_L1R); 
  fChain->SetBranchAddress("HLT_Ele15_SC15_SW_EleId_L1R", &HLT_Ele15_SC15_SW_EleId_L1R, &b_HLT_Ele15_SC15_SW_EleId_L1R); 
  fChain->SetBranchAddress("HLT_Ele20_SW_L1R", &HLT_Ele20_SW_L1R, &b_HLT_Ele20_SW_L1R); 
  fChain->SetBranchAddress("HLT_Ele20_SiStrip_L1R", &HLT_Ele20_SiStrip_L1R, &b_HLT_Ele20_SiStrip_L1R); 
  fChain->SetBranchAddress("HLT_Ele20_SC15_SW_L1R", &HLT_Ele20_SC15_SW_L1R, &b_HLT_Ele20_SC15_SW_L1R); 
  fChain->SetBranchAddress("HLT_Ele25_SW_L1R", &HLT_Ele25_SW_L1R, &b_HLT_Ele25_SW_L1R); 
  fChain->SetBranchAddress("HLT_Ele25_SW_EleId_LooseTrackIso_L1R", &HLT_Ele25_SW_EleId_LooseTrackIso_L1R, &b_HLT_Ele25_SW_EleId_LooseTrackIso_L1R); 
  fChain->SetBranchAddress("HLT_DoubleEle5_SW_Jpsi_L1R", &HLT_DoubleEle5_SW_Jpsi_L1R, &b_HLT_DoubleEle5_SW_Jpsi_L1R); 
  fChain->SetBranchAddress("HLT_DoubleEle5_SW_Upsilon_L1R", &HLT_DoubleEle5_SW_Upsilon_L1R, &b_HLT_DoubleEle5_SW_Upsilon_L1R); 
  fChain->SetBranchAddress("HLT_DoubleEle10_SW_L1R", &HLT_DoubleEle10_SW_L1R, &b_HLT_DoubleEle10_SW_L1R); 
  fChain->SetBranchAddress("HLT_Photon10_LooseEcalIso_TrackIso_L1R", &HLT_Photon10_LooseEcalIso_TrackIso_L1R, &b_HLT_Photon10_LooseEcalIso_TrackIso_L1R); 
  fChain->SetBranchAddress("HLT_Photon15_L1R", &HLT_Photon15_L1R, &b_HLT_Photon15_L1R); 
  fChain->SetBranchAddress("HLT_Photon20_LooseEcalIso_TrackIso_L1R", &HLT_Photon20_LooseEcalIso_TrackIso_L1R, &b_HLT_Photon20_LooseEcalIso_TrackIso_L1R); 
  fChain->SetBranchAddress("HLT_Photon25_L1R", &HLT_Photon25_L1R, &b_HLT_Photon25_L1R); 
  fChain->SetBranchAddress("HLT_Photon25_LooseEcalIso_TrackIso_L1R", &HLT_Photon25_LooseEcalIso_TrackIso_L1R, &b_HLT_Photon25_LooseEcalIso_TrackIso_L1R); 
  fChain->SetBranchAddress("HLT_Photon30_L1R_1E31", &HLT_Photon30_L1R_1E31, &b_HLT_Photon30_L1R_1E31); 
  fChain->SetBranchAddress("HLT_Photon70_L1R", &HLT_Photon70_L1R, &b_HLT_Photon70_L1R); 
  fChain->SetBranchAddress("HLT_DoublePhoton15_L1R", &HLT_DoublePhoton15_L1R, &b_HLT_DoublePhoton15_L1R); 
  fChain->SetBranchAddress("HLT_DoublePhoton15_VeryLooseEcalIso_L1R", &HLT_DoublePhoton15_VeryLooseEcalIso_L1R, &b_HLT_DoublePhoton15_VeryLooseEcalIso_L1R); 
  fChain->SetBranchAddress("HLT_SingleIsoTau30_Trk5", &HLT_SingleIsoTau30_Trk5, &b_HLT_SingleIsoTau30_Trk5); 
  fChain->SetBranchAddress("HLT_DoubleLooseIsoTau15_Trk5", &HLT_DoubleLooseIsoTau15_Trk5, &b_HLT_DoubleLooseIsoTau15_Trk5); 
  fChain->SetBranchAddress("HLT_BTagIP_Jet80", &HLT_BTagIP_Jet80, &b_HLT_BTagIP_Jet80); 
  fChain->SetBranchAddress("HLT_BTagMu_Jet20", &HLT_BTagMu_Jet20, &b_HLT_BTagMu_Jet20); 
  fChain->SetBranchAddress("HLT_BTagIP_Jet120", &HLT_BTagIP_Jet120, &b_HLT_BTagIP_Jet120); 
  fChain->SetBranchAddress("HLT_StoppedHSCP_1E31", &HLT_StoppedHSCP_1E31, &b_HLT_StoppedHSCP_1E31); 
  fChain->SetBranchAddress("HLT_L1Mu14_L1SingleJet15", &HLT_L1Mu14_L1SingleJet15, &b_HLT_L1Mu14_L1SingleJet15); 
  fChain->SetBranchAddress("HLT_L1Mu14_L1ETM40", &HLT_L1Mu14_L1ETM40, &b_HLT_L1Mu14_L1ETM40); 
  fChain->SetBranchAddress("HLT_L2Mu5_Photon9_L1R", &HLT_L2Mu5_Photon9_L1R, &b_HLT_L2Mu5_Photon9_L1R); 
  fChain->SetBranchAddress("HLT_L2Mu9_DiJet30", &HLT_L2Mu9_DiJet30, &b_HLT_L2Mu9_DiJet30); 
  fChain->SetBranchAddress("HLT_L2Mu8_HT50", &HLT_L2Mu8_HT50, &b_HLT_L2Mu8_HT50); 
  fChain->SetBranchAddress("HLT_Ele10_SW_L1R_TripleJet30", &HLT_Ele10_SW_L1R_TripleJet30, &b_HLT_Ele10_SW_L1R_TripleJet30); 
  fChain->SetBranchAddress("HLT_Ele10_LW_L1R_HT180", &HLT_Ele10_LW_L1R_HT180, &b_HLT_Ele10_LW_L1R_HT180); 
  fChain->SetBranchAddress("HLT_ZeroBias", &HLT_ZeroBias, &b_HLT_ZeroBias); 
  fChain->SetBranchAddress("HLT_MinBiasHcal", &HLT_MinBiasHcal, &b_HLT_MinBiasHcal); 
  fChain->SetBranchAddress("HLT_MinBiasEcal", &HLT_MinBiasEcal, &b_HLT_MinBiasEcal); 
  fChain->SetBranchAddress("HLT_MinBiasPixel", &HLT_MinBiasPixel, &b_HLT_MinBiasPixel); 
  fChain->SetBranchAddress("HLT_MinBiasPixel_Trk5", &HLT_MinBiasPixel_Trk5, &b_HLT_MinBiasPixel_Trk5); 
  fChain->SetBranchAddress("HLT_ZeroBiasPixel_SingleTrack", &HLT_ZeroBiasPixel_SingleTrack, &b_HLT_ZeroBiasPixel_SingleTrack); 
  fChain->SetBranchAddress("HLT_CSCBeamHalo", &HLT_CSCBeamHalo, &b_HLT_CSCBeamHalo); 
  fChain->SetBranchAddress("HLT_CSCBeamHaloOverlapRing1", &HLT_CSCBeamHaloOverlapRing1, &b_HLT_CSCBeamHaloOverlapRing1); 
  fChain->SetBranchAddress("HLT_CSCBeamHaloOverlapRing2", &HLT_CSCBeamHaloOverlapRing2, &b_HLT_CSCBeamHaloOverlapRing2); 
  fChain->SetBranchAddress("HLT_CSCBeamHaloRing2or3", &HLT_CSCBeamHaloRing2or3, &b_HLT_CSCBeamHaloRing2or3); 
  fChain->SetBranchAddress("HLT_BackwardBSC", &HLT_BackwardBSC, &b_HLT_BackwardBSC); 
  fChain->SetBranchAddress("HLT_ForwardBSC", &HLT_ForwardBSC, &b_HLT_ForwardBSC); 
  fChain->SetBranchAddress("HLT_TrackerCosmics", &HLT_TrackerCosmics, &b_HLT_TrackerCosmics); 
  fChain->SetBranchAddress("HLT_IsoTrack_1E31", &HLT_IsoTrack_1E31, &b_HLT_IsoTrack_1E31); 
  fChain->SetBranchAddress("AlCa_EcalPhiSym", &AlCa_EcalPhiSym, &b_AlCa_EcalPhiSym); 
  fChain->SetBranchAddress("AlCa_EcalPi0_1E31", &AlCa_EcalPi0_1E31, &b_AlCa_EcalPi0_1E31); 
  fChain->SetBranchAddress("AlCa_EcalEta_1E31", &AlCa_EcalEta_1E31, &b_AlCa_EcalEta_1E31); 

  // 8E29 menu
  fChain->SetBranchAddress("HLT_L1Jet6U", &HLT_L1Jet6U, &b_HLT_L1Jet6U);
  fChain->SetBranchAddress("HLT_Jet15U", &HLT_Jet15U, &b_HLT_Jet15U);
  fChain->SetBranchAddress("HLT_Jet30U", &HLT_Jet30U, &b_HLT_Jet30U);
  fChain->SetBranchAddress("HLT_Jet50U", &HLT_Jet50U, &b_HLT_Jet50U);
  fChain->SetBranchAddress("HLT_FwdJet20U", &HLT_FwdJet20U, &b_HLT_FwdJet20U);
  fChain->SetBranchAddress("HLT_DiJetAve15U_8E29", &HLT_DiJetAve15U_8E29, &b_HLT_DiJetAve15U_8E29);
  fChain->SetBranchAddress("HLT_DiJetAve30U_8E29", &HLT_DiJetAve30U_8E29, &b_HLT_DiJetAve30U_8E29);
  fChain->SetBranchAddress("HLT_QuadJet15U", &HLT_QuadJet15U, &b_HLT_QuadJet15U);
  fChain->SetBranchAddress("HLT_MET45", &HLT_MET45, &b_HLT_MET45);
  fChain->SetBranchAddress("HLT_MET100", &HLT_MET100, &b_HLT_MET100);
  fChain->SetBranchAddress("HLT_HT100U", &HLT_HT100U, &b_HLT_HT100U);
  fChain->SetBranchAddress("HLT_L1Mu20", &HLT_L1Mu20, &b_HLT_L1Mu20);
  fChain->SetBranchAddress("HLT_L2Mu9", &HLT_L2Mu9, &b_HLT_L2Mu9);
  fChain->SetBranchAddress("HLT_L2Mu11", &HLT_L2Mu11, &b_HLT_L2Mu11);
  fChain->SetBranchAddress("HLT_Mu3", &HLT_Mu3, &b_HLT_Mu3); 
  fChain->SetBranchAddress("HLT_IsoMu3", &HLT_IsoMu3, &b_HLT_IsoMu3);
  fChain->SetBranchAddress("HLT_L1DoubleMuOpen", &HLT_L1DoubleMuOpen, &b_HLT_L1DoubleMuOpen);
  fChain->SetBranchAddress("HLT_DoubleMu0", &HLT_DoubleMu0, &b_HLT_DoubleMu0);
  fChain->SetBranchAddress("HLT_L1SingleEG5", &HLT_L1SingleEG5, &b_HLT_L1SingleEG5);
  fChain->SetBranchAddress("HLT_L1SingleEG8", &HLT_L1SingleEG8, &b_HLT_L1SingleEG8);
  fChain->SetBranchAddress("HLT_Ele10_LW_L1R", &HLT_Ele10_LW_L1R, &b_HLT_Ele10_LW_L1R);
  fChain->SetBranchAddress("HLT_Ele15_LW_L1R", &HLT_Ele15_LW_L1R, &b_HLT_Ele15_LW_L1R); 
  fChain->SetBranchAddress("HLT_Ele10_LW_EleId_L1R", &HLT_Ele10_LW_EleId_L1R, &b_HLT_Ele10_LW_EleId_L1R);
  fChain->SetBranchAddress("HLT_Ele15_SC10_LW_L1R", &HLT_Ele15_SC10_LW_L1R, &b_HLT_Ele15_SC10_LW_L1R);
  fChain->SetBranchAddress("HLT_Ele15_SiStrip_L1R", &HLT_Ele15_SiStrip_L1R, &b_HLT_Ele15_SiStrip_L1R);
  fChain->SetBranchAddress("HLT_Ele20_LW_L1R", &HLT_Ele20_LW_L1R, &b_HLT_Ele20_LW_L1R);
  fChain->SetBranchAddress("HLT_L1DoubleEG5", &HLT_L1DoubleEG5, &b_HLT_L1DoubleEG5);
  fChain->SetBranchAddress("HLT_DoubleEle5_SW_L1R", &HLT_DoubleEle5_SW_L1R, &b_HLT_DoubleEle5_SW_L1R);
  fChain->SetBranchAddress("HLT_DoublePhoton5_eeRes_L1R", &HLT_DoublePhoton5_eeRes_L1R, &b_HLT_DoublePhoton5_eeRes_L1R);
  fChain->SetBranchAddress("HLT_DoublePhoton5_Jpsi_L1R", &HLT_DoublePhoton5_Jpsi_L1R, &b_HLT_DoublePhoton5_Jpsi_L1R);
  fChain->SetBranchAddress("HLT_DoublePhoton5_Upsilon_L1R", &HLT_DoublePhoton5_Upsilon_L1R, &b_HLT_DoublePhoton5_Upsilon_L1R);
  fChain->SetBranchAddress("HLT_Photon10_L1R", &HLT_Photon10_L1R, &b_HLT_Photon10_L1R);
  fChain->SetBranchAddress("HLT_Photon15_TrackIso_L1R", &HLT_Photon15_TrackIso_L1R, &b_HLT_Photon15_TrackIso_L1R);
  fChain->SetBranchAddress("HLT_Photon15_LooseEcalIso_L1R", &HLT_Photon15_LooseEcalIso_L1R, &b_HLT_Photon15_LooseEcalIso_L1R);
  fChain->SetBranchAddress("HLT_Photon20_L1R", &HLT_Photon20_L1R, &b_HLT_Photon20_L1R);
  fChain->SetBranchAddress("HLT_Photon30_L1R_8E29", &HLT_Photon30_L1R_8E29, &b_HLT_Photon30_L1R_8E29);
  fChain->SetBranchAddress("HLT_DoublePhoton10_L1R", &HLT_DoublePhoton10_L1R, &b_HLT_DoublePhoton10_L1R);
  fChain->SetBranchAddress("HLT_SingleLooseIsoTau20", &HLT_SingleLooseIsoTau20, &b_HLT_SingleLooseIsoTau20);
  fChain->SetBranchAddress("HLT_DoubleLooseIsoTau15", &HLT_DoubleLooseIsoTau15, &b_HLT_DoubleLooseIsoTau15);
  fChain->SetBranchAddress("HLT_BTagMu_Jet10U", &HLT_BTagMu_Jet10U, &b_HLT_BTagMu_Jet10U);
  fChain->SetBranchAddress("HLT_BTagIP_Jet50U", &HLT_BTagIP_Jet50U, &b_HLT_BTagIP_Jet50U);
  fChain->SetBranchAddress("HLT_StoppedHSCP_8E29", &HLT_StoppedHSCP_8E29, &b_HLT_StoppedHSCP_8E29);
  fChain->SetBranchAddress("HLT_L1Mu14_L1SingleEG10", &HLT_L1Mu14_L1SingleEG10, &b_HLT_L1Mu14_L1SingleEG10);
  fChain->SetBranchAddress("HLT_L1Mu14_L1SingleJet6U", &HLT_L1Mu14_L1SingleJet6U, &b_HLT_L1Mu14_L1SingleJet6U);
  fChain->SetBranchAddress("HLT_L1Mu14_L1ETM30", &HLT_L1Mu14_L1ETM30, &b_HLT_L1Mu14_L1ETM30);
  fChain->SetBranchAddress("HLT_IsoTrack_8E29", &HLT_IsoTrack_8E29, &b_HLT_IsoTrack_8E29);
  fChain->SetBranchAddress("AlCa_HcalPhiSym", &AlCa_HcalPhiSym, &b_AlCa_HcalPhiSym);
  fChain->SetBranchAddress("AlCa_EcalPi0_8E29", &AlCa_EcalPi0_8E29, &b_AlCa_EcalPi0_8E29);
  fChain->SetBranchAddress("AlCa_EcalEta_8E29", &AlCa_EcalEta_8E29, &b_AlCa_EcalEta_8E29);
  fChain->SetBranchAddress("AlCa_RPCMuonNoHits", &AlCa_RPCMuonNoHits, &b_AlCa_RPCMuonNoHits);
  fChain->SetBranchAddress("AlCa_RPCMuonNormalisation", &AlCa_RPCMuonNormalisation, &b_AlCa_RPCMuonNormalisation);

  // Commissioning and other HLT Paths for the CRAFT09 cosmics menu 
  fChain->SetBranchAddress("HLT_Random", &HLT_Random, &b_HLT_Random); 
  fChain->SetBranchAddress("HLT_L2Mu3_NoVertex", &HLT_L2Mu3_NoVertex, &b_HLT_L2Mu3_NoVertex); 
  fChain->SetBranchAddress("HLT_OIstateTkMu3", &HLT_OIstateTkMu3, &b_HLT_OIstateTkMu3); 
  fChain->SetBranchAddress("HLT_TrackPointing", &HLT_TrackPointing, &b_HLT_TrackPointing); 
  fChain->SetBranchAddress("HLT_EgammaSuperClusterOnly_L1R", &HLT_EgammaSuperClusterOnly_L1R, &b_HLT_EgammaSuperClusterOnly_L1R); 
  fChain->SetBranchAddress("AlCa_EcalPi0_Cosmics", &AlCa_EcalPi0_Cosmics, &b_AlCa_EcalPi0_Cosmics);  
  fChain->SetBranchAddress("AlCa_EcalEta_Cosmics", &AlCa_EcalEta_Cosmics, &b_AlCa_EcalEta_Cosmics);  
  fChain->SetBranchAddress("HLT_DataIntegrity", &HLT_DataIntegrity, &b_HLT_DataIntegrity);  
  fChain->SetBranchAddress("HLT_L1_BPTX", &HLT_L1_BPTX, &b_HLT_L1_BPTX);  
  fChain->SetBranchAddress("HLT_L1_BSC", &HLT_L1_BSC, &b_HLT_L1_BSC);  
  fChain->SetBranchAddress("HLT_L1_HFtech", &HLT_L1_HFtech, &b_HLT_L1_HFtech);  
  fChain->SetBranchAddress("HLT_HFThreshold", &HLT_HFThreshold, &b_HLT_HFThreshold);  
  fChain->SetBranchAddress("HLT_Physics", &HLT_Physics, &b_HLT_Physics);  
  fChain->SetBranchAddress("HLT_PhysicsNoMuon", &HLT_PhysicsNoMuon, &b_HLT_PhysicsNoMuon);  
  fChain->SetBranchAddress("HLT_Calibration", &HLT_Calibration, &b_HLT_Calibration);  
  fChain->SetBranchAddress("HLT_EcalCalibration", &HLT_EcalCalibration, &b_HLT_EcalCalibration);  
  fChain->SetBranchAddress("HLT_PixelFEDSize", &HLT_PixelFEDSize, &b_HLT_PixelFEDSize);  
  fChain->SetBranchAddress("HLT_GlobalRunHPDNoise", &HLT_GlobalRunHPDNoise, &b_HLT_GlobalRunHPDNoise);  

  // HLT paths for the 2009 Circulating Beam menu
  fChain->SetBranchAddress("HLT_L2Mu0_NoVertex", &HLT_L2Mu0_NoVertex, &b_HLT_L2Mu0_NoVertex);
  fChain->SetBranchAddress("HLT_TkMu3_NoVertex", &HLT_TkMu3_NoVertex, &b_HLT_TkMu3_NoVertex);
  fChain->SetBranchAddress("HLT_IsoTrackHB_8E29", &HLT_IsoTrackHB_8E29, &b_HLT_IsoTrackHB_8E29);
  fChain->SetBranchAddress("HLT_IsoTrackHE_8E29", &HLT_IsoTrackHE_8E29, &b_HLT_IsoTrackHE_8E29);
  fChain->SetBranchAddress("HLT_MinBiasPixel_DoubleIsoTrack5", &HLT_MinBiasPixel_DoubleIsoTrack5, &b_HLT_MinBiasPixel_DoubleIsoTrack5);
  fChain->SetBranchAddress("HLT_MinBiasPixel_DoubleTrack", &HLT_MinBiasPixel_DoubleTrack, &b_HLT_MinBiasPixel_DoubleTrack);
  fChain->SetBranchAddress("HLT_MinBiasPixel_SingleTrack", &HLT_MinBiasPixel_SingleTrack, &b_HLT_MinBiasPixel_SingleTrack);
  fChain->SetBranchAddress("HLT_TechTrigHCALNoise", &HLT_TechTrigHCALNoise, &b_HLT_TechTrigHCALNoise);
  fChain->SetBranchAddress("HLT_HcalNZS_8E29", &HLT_HcalNZS_8E29, &b_HLT_HcalNZS_8E29);
  fChain->SetBranchAddress("HLT_HcalNZS", &HLT_HcalNZS, &b_HLT_HcalNZS);
  fChain->SetBranchAddress("HLT_HcalPhiSym", &HLT_HcalPhiSym, &b_HLT_HcalPhiSym);
  fChain->SetBranchAddress("HLT_SplashEcalSumET", &HLT_SplashEcalSumET, &b_HLT_SplashEcalSumET);

  // Autogenerated from ConfDB - SetBranchAddressBits
  fChain->SetBranchAddress("HLT_DiJetAve50U_8E29", &HLT_DiJetAve50U_8E29, &b_HLT_DiJetAve50U_8E29);
  fChain->SetBranchAddress("HLT_L1DoubleMuOpen_Tight", &HLT_L1DoubleMuOpen_Tight, &b_HLT_L1DoubleMuOpen_Tight);
  fChain->SetBranchAddress("HLT_Photon15_TrackIso_Cleaned_L1R", &HLT_Photon15_TrackIso_Cleaned_L1R, &b_HLT_Photon15_TrackIso_Cleaned_L1R);
  fChain->SetBranchAddress("HLT_Photon15_LooseEcalIso_Cleaned_L1R", &HLT_Photon15_LooseEcalIso_Cleaned_L1R, &b_HLT_Photon15_LooseEcalIso_Cleaned_L1R);
  fChain->SetBranchAddress("HLT_SingleLooseIsoTau20_Trk5", &HLT_SingleLooseIsoTau20_Trk5, &b_HLT_SingleLooseIsoTau20_Trk5);
  fChain->SetBranchAddress("HLT_SingleLooseIsoTau25", &HLT_SingleLooseIsoTau25, &b_HLT_SingleLooseIsoTau25);
  fChain->SetBranchAddress("HLT_MultiVertex6", &HLT_MultiVertex6, &b_HLT_MultiVertex6);
  fChain->SetBranchAddress("HLT_MultiVertex8_L1ETT60", &HLT_MultiVertex8_L1ETT60, &b_HLT_MultiVertex8_L1ETT60);
  fChain->SetBranchAddress("HLT_PixelTracks_Multiplicity85", &HLT_PixelTracks_Multiplicity85, &b_HLT_PixelTracks_Multiplicity85);
  fChain->SetBranchAddress("HLT_L1Tech_BSC_minBias", &HLT_L1Tech_BSC_minBias, &b_HLT_L1Tech_BSC_minBias);
  fChain->SetBranchAddress("HLT_Activity_CSC", &HLT_Activity_CSC, &b_HLT_Activity_CSC);
  fChain->SetBranchAddress("HLT_Activity_Ecal_SC7", &HLT_Activity_Ecal_SC7, &b_HLT_Activity_Ecal_SC7);
  fChain->SetBranchAddress("HLT_Activity_Ecal_SC15", &HLT_Activity_Ecal_SC15, &b_HLT_Activity_Ecal_SC15);
  fChain->SetBranchAddress("HLT_L1MuOpen_DT", &HLT_L1MuOpen_DT, &b_HLT_L1MuOpen_DT);
  fChain->SetBranchAddress("HLT_Photon10_Cleaned_L1R", &HLT_Photon10_Cleaned_L1R, &b_HLT_Photon10_Cleaned_L1R);
  fChain->SetBranchAddress("HLT_Photon15_Cleaned_L1R", &HLT_Photon15_Cleaned_L1R, &b_HLT_Photon15_Cleaned_L1R);
  fChain->SetBranchAddress("HLT_Photon20_Cleaned_L1R", &HLT_Photon20_Cleaned_L1R, &b_HLT_Photon20_Cleaned_L1R);
  fChain->SetBranchAddress("HLT_L1Tech_BSC_HighMultiplicity", &HLT_L1Tech_BSC_HighMultiplicity, &b_HLT_L1Tech_BSC_HighMultiplicity);
  fChain->SetBranchAddress("HLT_PixelTracks_Multiplicity40", &HLT_PixelTracks_Multiplicity40, &b_HLT_PixelTracks_Multiplicity40);
  fChain->SetBranchAddress("HLT_L1SingleForJet_BPTX", &HLT_L1SingleForJet_BPTX, &b_HLT_L1SingleForJet_BPTX);
  fChain->SetBranchAddress("HLT_L1Jet6U_BPTX", &HLT_L1Jet6U_BPTX, &b_HLT_L1Jet6U_BPTX);
  fChain->SetBranchAddress("HLT_L1Jet10U_BPTX", &HLT_L1Jet10U_BPTX, &b_HLT_L1Jet10U_BPTX);
  fChain->SetBranchAddress("HLT_L1MuOpen_BPTX", &HLT_L1MuOpen_BPTX, &b_HLT_L1MuOpen_BPTX);
  fChain->SetBranchAddress("HLT_L1_BptxXOR_BscMinBiasOR", &HLT_L1_BptxXOR_BscMinBiasOR, &b_HLT_L1_BptxXOR_BscMinBiasOR);
  fChain->SetBranchAddress("HLT_L1SingleCenJet_BPTX", &HLT_L1SingleCenJet_BPTX, &b_HLT_L1SingleCenJet_BPTX);
  fChain->SetBranchAddress("HLT_MinBiasBSC_BPTX", &HLT_MinBiasBSC_BPTX, &b_HLT_MinBiasBSC_BPTX);
  fChain->SetBranchAddress("HLT_L1Tech_HCAL_HF", &HLT_L1Tech_HCAL_HF, &b_HLT_L1Tech_HCAL_HF);
  fChain->SetBranchAddress("HLT_L1SingleTauJet_BPTX", &HLT_L1SingleTauJet_BPTX, &b_HLT_L1SingleTauJet_BPTX);
  fChain->SetBranchAddress("HLT_PixelTracks_Multiplicity70", &HLT_PixelTracks_Multiplicity70, &b_HLT_PixelTracks_Multiplicity70);
  fChain->SetBranchAddress("HLT_Jet15U_HcalNoiseFiltered", &HLT_Jet15U_HcalNoiseFiltered, &b_HLT_Jet15U_HcalNoiseFiltered);
  fChain->SetBranchAddress("HLT_L2Mu5", &HLT_L2Mu5, &b_HLT_L2Mu5);
  fChain->SetBranchAddress("HLT_L1_BscMinBiasOR_BeamGas", &HLT_L1_BscMinBiasOR_BeamGas, &b_HLT_L1_BscMinBiasOR_BeamGas);
  fChain->SetBranchAddress("HLT_L1Tech_BSC_halo", &HLT_L1Tech_BSC_halo, &b_HLT_L1Tech_BSC_halo);
  fChain->SetBranchAddress("HLT_L1Tech_BSC_halo_forPhysicsBackground", &HLT_L1Tech_BSC_halo_forPhysicsBackground, &b_HLT_L1Tech_BSC_halo_forPhysicsBackground);
  fChain->SetBranchAddress("HLT_HFThreshold3", &HLT_HFThreshold3, &b_HLT_HFThreshold3);
  fChain->SetBranchAddress("HLT_HFThreshold10", &HLT_HFThreshold10, &b_HLT_HFThreshold10);
  fChain->SetBranchAddress("HLT_Activity_DT", &HLT_Activity_DT, &b_HLT_Activity_DT);
  fChain->SetBranchAddress("HLT_Activity_DT_Tuned", &HLT_Activity_DT_Tuned, &b_HLT_Activity_DT_Tuned);
  fChain->SetBranchAddress("HLT_Activity_HF3", &HLT_Activity_HF3, &b_HLT_Activity_HF3);
  fChain->SetBranchAddress("HLT_Activity_HF10", &HLT_Activity_HF10, &b_HLT_Activity_HF10);
  fChain->SetBranchAddress("HLT_MultiTowerEcal", &HLT_MultiTowerEcal, &b_HLT_MultiTowerEcal);
  fChain->SetBranchAddress("HLT_SelectEcalSpikes_L1R", &HLT_SelectEcalSpikes_L1R, &b_HLT_SelectEcalSpikes_L1R);
  fChain->SetBranchAddress("HLT_SelectEcalSpikesHighEt_L1R", &HLT_SelectEcalSpikesHighEt_L1R, &b_HLT_SelectEcalSpikesHighEt_L1R);
  fChain->SetBranchAddress("HLT_L1Jet6U_NoBPTX", &HLT_L1Jet6U_NoBPTX, &b_HLT_L1Jet6U_NoBPTX);
  fChain->SetBranchAddress("HLT_L1Jet10U", &HLT_L1Jet10U, &b_HLT_L1Jet10U);
  fChain->SetBranchAddress("HLT_L1Jet10U_NoBPTX", &HLT_L1Jet10U_NoBPTX, &b_HLT_L1Jet10U_NoBPTX);
  fChain->SetBranchAddress("HLT_L1SingleForJet_NoBPTX", &HLT_L1SingleForJet_NoBPTX, &b_HLT_L1SingleForJet_NoBPTX);
  fChain->SetBranchAddress("HLT_L1SingleCenJet", &HLT_L1SingleCenJet, &b_HLT_L1SingleCenJet);
  fChain->SetBranchAddress("HLT_L1SingleCenJet_NoBPTX", &HLT_L1SingleCenJet_NoBPTX, &b_HLT_L1SingleCenJet_NoBPTX);
  fChain->SetBranchAddress("HLT_L1SingleTauJet", &HLT_L1SingleTauJet, &b_HLT_L1SingleTauJet);
  fChain->SetBranchAddress("HLT_L1SingleTauJet_NoBPTX", &HLT_L1SingleTauJet_NoBPTX, &b_HLT_L1SingleTauJet_NoBPTX);
  fChain->SetBranchAddress("HLT_DoubleFwdJet50", &HLT_DoubleFwdJet50, &b_HLT_DoubleFwdJet50);
  fChain->SetBranchAddress("HLT_QuadJet60", &HLT_QuadJet60, &b_HLT_QuadJet60);
  fChain->SetBranchAddress("HLT_L1MuOpen_NoBPTX", &HLT_L1MuOpen_NoBPTX, &b_HLT_L1MuOpen_NoBPTX);
  fChain->SetBranchAddress("HLT_L1MuOpen_AntiBPTX", &HLT_L1MuOpen_AntiBPTX, &b_HLT_L1MuOpen_AntiBPTX);
  fChain->SetBranchAddress("HLT_L1SingleEG1", &HLT_L1SingleEG1, &b_HLT_L1SingleEG1);
  fChain->SetBranchAddress("HLT_L1SingleEG1_NoBPTX", &HLT_L1SingleEG1_NoBPTX, &b_HLT_L1SingleEG1_NoBPTX);
  fChain->SetBranchAddress("HLT_L1SingleEG5_NoBPTX", &HLT_L1SingleEG5_NoBPTX, &b_HLT_L1SingleEG5_NoBPTX);
  fChain->SetBranchAddress("HLT_L1SingleEG20_NoBPTX", &HLT_L1SingleEG20_NoBPTX, &b_HLT_L1SingleEG20_NoBPTX);
  fChain->SetBranchAddress("HLT_Ele20_SW_EleId_LooseTrackIso_L1R", &HLT_Ele20_SW_EleId_LooseTrackIso_L1R, &b_HLT_Ele20_SW_EleId_LooseTrackIso_L1R);
  fChain->SetBranchAddress("HLT_Ele25_LW_L1R", &HLT_Ele25_LW_L1R, &b_HLT_Ele25_LW_L1R);
  fChain->SetBranchAddress("HLT_DoublePhoton4_eeRes_L1R", &HLT_DoublePhoton4_eeRes_L1R, &b_HLT_DoublePhoton4_eeRes_L1R);
  fChain->SetBranchAddress("HLT_DoublePhoton4_Jpsi_L1R", &HLT_DoublePhoton4_Jpsi_L1R, &b_HLT_DoublePhoton4_Jpsi_L1R);
  fChain->SetBranchAddress("HLT_DoublePhoton4_Upsilon_L1R", &HLT_DoublePhoton4_Upsilon_L1R, &b_HLT_DoublePhoton4_Upsilon_L1R);
  fChain->SetBranchAddress("HLT_DoublePhoton5_L1R", &HLT_DoublePhoton5_L1R, &b_HLT_DoublePhoton5_L1R);
  fChain->SetBranchAddress("HLT_L1Mu14_L1SingleJet20", &HLT_L1Mu14_L1SingleJet20, &b_HLT_L1Mu14_L1SingleJet20);
  fChain->SetBranchAddress("HLT_MinBiasBSC_NoBPTX", &HLT_MinBiasBSC_NoBPTX, &b_HLT_MinBiasBSC_NoBPTX);
  fChain->SetBranchAddress("HLT_SplashBSC", &HLT_SplashBSC, &b_HLT_SplashBSC);
  fChain->SetBranchAddress("HLT_L1_BscMinBiasOR_BptxPlusORMinus", &HLT_L1_BscMinBiasOR_BptxPlusORMinus, &b_HLT_L1_BscMinBiasOR_BptxPlusORMinus);
  fChain->SetBranchAddress("HLT_L1_BscMinBiasOR_BptxPlusORMinus_NoBPTX", &HLT_L1_BscMinBiasOR_BptxPlusORMinus_NoBPTX, &b_HLT_L1_BscMinBiasOR_BptxPlusORMinus_NoBPTX);
  fChain->SetBranchAddress("HLT_L1Tech_RPC_TTU_RBst1_collisions", &HLT_L1Tech_RPC_TTU_RBst1_collisions, &b_HLT_L1Tech_RPC_TTU_RBst1_collisions);
  fChain->SetBranchAddress("HLT_IsoTrackHE_1E31", &HLT_IsoTrackHE_1E31, &b_HLT_IsoTrackHE_1E31);
  fChain->SetBranchAddress("HLT_IsoTrackHB_1E31", &HLT_IsoTrackHB_1E31, &b_HLT_IsoTrackHB_1E31);
  fChain->SetBranchAddress("HLT_HcalNZS_1E31", &HLT_HcalNZS_1E31, &b_HLT_HcalNZS_1E31);
  fChain->SetBranchAddress("HLT_HIMinBiasCalo", &HLT_HIMinBiasCalo, &b_HLT_HIMinBiasCalo);
  fChain->SetBranchAddress("HLT_HIJet35U", &HLT_HIJet35U, &b_HLT_HIJet35U);
  fChain->SetBranchAddress("HLT_HIJet50U", &HLT_HIJet50U, &b_HLT_HIJet50U);
  fChain->SetBranchAddress("HLT_HIJet75U", &HLT_HIJet75U, &b_HLT_HIJet75U);
  fChain->SetBranchAddress("HLT_HIJet90U", &HLT_HIJet90U, &b_HLT_HIJet90U);
  fChain->SetBranchAddress("HLT_HIPhoton10", &HLT_HIPhoton10, &b_HLT_HIPhoton10);
  fChain->SetBranchAddress("HLT_HIPhoton15", &HLT_HIPhoton15, &b_HLT_HIPhoton15);
  fChain->SetBranchAddress("HLT_HIPhoton20", &HLT_HIPhoton20, &b_HLT_HIPhoton20);
  fChain->SetBranchAddress("HLT_HIPhoton30", &HLT_HIPhoton30, &b_HLT_HIPhoton30);
  fChain->SetBranchAddress("HLT_HighMult40", &HLT_HighMult40, &b_HLT_HighMult40);
  fChain->SetBranchAddress("HLT_L1Tech_HCAL_HF_coincidence_PM", &HLT_L1Tech_HCAL_HF_coincidence_PM, &b_HLT_L1Tech_HCAL_HF_coincidence_PM);
  fChain->SetBranchAddress("HLT_PhysicsDeclared", &HLT_PhysicsDeclared, &b_HLT_PhysicsDeclared);
  fChain->SetBranchAddress("HLT_Jet250", &HLT_Jet250, &b_HLT_Jet250);
  fChain->SetBranchAddress("HLT_DoubleJet15U_ForwardBackward", &HLT_DoubleJet15U_ForwardBackward, &b_HLT_DoubleJet15U_ForwardBackward);
  fChain->SetBranchAddress("HLT_DoubleJet150", &HLT_DoubleJet150, &b_HLT_DoubleJet150);
  fChain->SetBranchAddress("HLT_DoubleJet125_Aco", &HLT_DoubleJet125_Aco, &b_HLT_DoubleJet125_Aco);
  fChain->SetBranchAddress("HLT_TripleJet85", &HLT_TripleJet85, &b_HLT_TripleJet85);
  fChain->SetBranchAddress("HLT_MET25", &HLT_MET25, &b_HLT_MET25);
  fChain->SetBranchAddress("HLT_MET50", &HLT_MET50, &b_HLT_MET50);
  fChain->SetBranchAddress("HLT_MET75", &HLT_MET75, &b_HLT_MET75);
  fChain->SetBranchAddress("HLT_MET60_HT350", &HLT_MET60_HT350, &b_HLT_MET60_HT350);
  fChain->SetBranchAddress("HLT_HT240", &HLT_HT240, &b_HLT_HT240);
  fChain->SetBranchAddress("HLT_Jet180_MET60", &HLT_Jet180_MET60, &b_HLT_Jet180_MET60);
  fChain->SetBranchAddress("HLT_Jet60_MET70_Aco", &HLT_Jet60_MET70_Aco, &b_HLT_Jet60_MET70_Aco);
  fChain->SetBranchAddress("HLT_Jet100_MET60_Aco", &HLT_Jet100_MET60_Aco, &b_HLT_Jet100_MET60_Aco);
  fChain->SetBranchAddress("HLT_DoubleJet125_MET60", &HLT_DoubleJet125_MET60, &b_HLT_DoubleJet125_MET60);
  fChain->SetBranchAddress("HLT_DoubleFwdJet40_MET60", &HLT_DoubleFwdJet40_MET60, &b_HLT_DoubleFwdJet40_MET60);
  fChain->SetBranchAddress("HLT_DoubleJet60_MET60_Aco", &HLT_DoubleJet60_MET60_Aco, &b_HLT_DoubleJet60_MET60_Aco);
  fChain->SetBranchAddress("HLT_DoubleJet50_MET70_Aco", &HLT_DoubleJet50_MET70_Aco, &b_HLT_DoubleJet50_MET70_Aco);
  fChain->SetBranchAddress("HLT_DoubleJet40_MET70_Aco", &HLT_DoubleJet40_MET70_Aco, &b_HLT_DoubleJet40_MET70_Aco);
  fChain->SetBranchAddress("HLT_TripleJet60_MET60", &HLT_TripleJet60_MET60, &b_HLT_TripleJet60_MET60);
  fChain->SetBranchAddress("HLT_QuadJet35_MET60", &HLT_QuadJet35_MET60, &b_HLT_QuadJet35_MET60);
  fChain->SetBranchAddress("HLT_L2Mu0", &HLT_L2Mu0, &b_HLT_L2Mu0);
  fChain->SetBranchAddress("HLT_L2Mu3", &HLT_L2Mu3, &b_HLT_L2Mu3);
  fChain->SetBranchAddress("HLT_L2Mu15", &HLT_L2Mu15, &b_HLT_L2Mu15);
  fChain->SetBranchAddress("HLT_L2DoubleMu0", &HLT_L2DoubleMu0, &b_HLT_L2DoubleMu0);
  fChain->SetBranchAddress("HLT_IsoMu11", &HLT_IsoMu11, &b_HLT_IsoMu11);
  fChain->SetBranchAddress("HLT_IsoMu13", &HLT_IsoMu13, &b_HLT_IsoMu13);
  fChain->SetBranchAddress("HLT_IsoMu15", &HLT_IsoMu15, &b_HLT_IsoMu15);
  fChain->SetBranchAddress("HLT_Mu7", &HLT_Mu7, &b_HLT_Mu7);
  fChain->SetBranchAddress("HLT_Mu13", &HLT_Mu13, &b_HLT_Mu13);
  fChain->SetBranchAddress("HLT_DoubleIsoMu3", &HLT_DoubleIsoMu3, &b_HLT_DoubleIsoMu3);
  fChain->SetBranchAddress("HLT_DoubleMu3_Vtx2mm", &HLT_DoubleMu3_Vtx2mm, &b_HLT_DoubleMu3_Vtx2mm);
  fChain->SetBranchAddress("HLT_DoubleMu3_JPsi", &HLT_DoubleMu3_JPsi, &b_HLT_DoubleMu3_JPsi);
  fChain->SetBranchAddress("HLT_DoubleMu3_Upsilon", &HLT_DoubleMu3_Upsilon, &b_HLT_DoubleMu3_Upsilon);
  fChain->SetBranchAddress("HLT_DoubleMu7_Z", &HLT_DoubleMu7_Z, &b_HLT_DoubleMu7_Z);
  fChain->SetBranchAddress("HLT_DoubleMu3_SameSign", &HLT_DoubleMu3_SameSign, &b_HLT_DoubleMu3_SameSign);
  fChain->SetBranchAddress("HLT_DoubleMu3_Psi2S", &HLT_DoubleMu3_Psi2S, &b_HLT_DoubleMu3_Psi2S);
  fChain->SetBranchAddress("HLT_Mu0_L1MuOpen", &HLT_Mu0_L1MuOpen, &b_HLT_Mu0_L1MuOpen);
  fChain->SetBranchAddress("HLT_Mu3_L1MuOpen", &HLT_Mu3_L1MuOpen, &b_HLT_Mu3_L1MuOpen);
  fChain->SetBranchAddress("HLT_Mu5_L1MuOpen", &HLT_Mu5_L1MuOpen, &b_HLT_Mu5_L1MuOpen);
  fChain->SetBranchAddress("HLT_Mu0_L2Mu0", &HLT_Mu0_L2Mu0, &b_HLT_Mu0_L2Mu0);
  fChain->SetBranchAddress("HLT_Mu3_L2Mu0", &HLT_Mu3_L2Mu0, &b_HLT_Mu3_L2Mu0);
  fChain->SetBranchAddress("HLT_Mu5_L2Mu0", &HLT_Mu5_L2Mu0, &b_HLT_Mu5_L2Mu0);
  fChain->SetBranchAddress("HLT_Mu0_Track0_Jpsi", &HLT_Mu0_Track0_Jpsi, &b_HLT_Mu0_Track0_Jpsi);
  fChain->SetBranchAddress("HLT_Mu3_Track0_Jpsi", &HLT_Mu3_Track0_Jpsi, &b_HLT_Mu3_Track0_Jpsi);
  fChain->SetBranchAddress("HLT_Mu5_Track0_Jpsi", &HLT_Mu5_Track0_Jpsi, &b_HLT_Mu5_Track0_Jpsi);
  fChain->SetBranchAddress("HLT_IsoMu7_BTagIP_Jet35", &HLT_IsoMu7_BTagIP_Jet35, &b_HLT_IsoMu7_BTagIP_Jet35);
  fChain->SetBranchAddress("HLT_IsoMu7_BTagMu_Jet20", &HLT_IsoMu7_BTagMu_Jet20, &b_HLT_IsoMu7_BTagMu_Jet20);
  fChain->SetBranchAddress("HLT_IsoMu7_Jet40", &HLT_IsoMu7_Jet40, &b_HLT_IsoMu7_Jet40);
  fChain->SetBranchAddress("HLT_IsoMu14_IsoTau15_Trk3", &HLT_IsoMu14_IsoTau15_Trk3, &b_HLT_IsoMu14_IsoTau15_Trk3);
  fChain->SetBranchAddress("HLT_IsoMu14_IsoTau15_Trk3_NoL1", &HLT_IsoMu14_IsoTau15_Trk3_NoL1, &b_HLT_IsoMu14_IsoTau15_Trk3_NoL1);
  fChain->SetBranchAddress("HLT_IsoMu14_LooseIsoTau15_NoL25", &HLT_IsoMu14_LooseIsoTau15_NoL25, &b_HLT_IsoMu14_LooseIsoTau15_NoL25);
  fChain->SetBranchAddress("HLT_IsoMu14_LooseIsoTau15_Trk3_NoL2", &HLT_IsoMu14_LooseIsoTau15_Trk3_NoL2, &b_HLT_IsoMu14_LooseIsoTau15_Trk3_NoL2);
  fChain->SetBranchAddress("HLT_NoL2IsoMu8_Jet40", &HLT_NoL2IsoMu8_Jet40, &b_HLT_NoL2IsoMu8_Jet40);
  fChain->SetBranchAddress("HLT_Mu14_Jet50", &HLT_Mu14_Jet50, &b_HLT_Mu14_Jet50);
  fChain->SetBranchAddress("HLT_Mu5_TripleJet30", &HLT_Mu5_TripleJet30, &b_HLT_Mu5_TripleJet30);
  fChain->SetBranchAddress("HLT_L2Mu7_Photon9_L1R", &HLT_L2Mu7_Photon9_L1R, &b_HLT_L2Mu7_Photon9_L1R);
  fChain->SetBranchAddress("HLT_Ele10_LW_L1R_HT200", &HLT_Ele10_LW_L1R_HT200, &b_HLT_Ele10_LW_L1R_HT200);
  fChain->SetBranchAddress("AlCa_RPCMuonNoTriggers", &AlCa_RPCMuonNoTriggers, &b_AlCa_RPCMuonNoTriggers);
  fChain->SetBranchAddress("HLT_HIDoubleMu", &HLT_HIDoubleMu, &b_HLT_HIDoubleMu);
  fChain->SetBranchAddress("HLT_DoublePhoton5_CEP_L1R", &HLT_DoublePhoton5_CEP_L1R, &b_HLT_DoublePhoton5_CEP_L1R);
  fChain->SetBranchAddress("HLT_ZeroBias1kHz", &HLT_ZeroBias1kHz, &b_HLT_ZeroBias1kHz);

  //
  /* Also associate with the maps to speed up code! */
  fChain->SetBranchAddress("L1Tech_BPTX_plus_OR_minus.v0", &map_BitOfStandardHLTPath["L1Tech_BPTX_plus_OR_minus.v0"], &b_L1Tech_BPTX_plus_OR_minus_v0); 
  fChain->SetBranchAddress("L1Tech_BPTX_plus_AND_minus_instance1.v0", &map_BitOfStandardHLTPath["L1Tech_BPTX_plus_AND_minus_instance1.v0"], &b_L1Tech_BPTX_plus_AND_minus_instance1_v0); 
  fChain->SetBranchAddress("L1Tech_BSC_minBias_OR.v0", &map_BitOfStandardHLTPath["L1Tech_BSC_minBias_OR.v0"], &b_L1Tech_BSC_minBias_OR_v0); 
  fChain->SetBranchAddress("L1Tech_BSC_minBias_threshold1.v0", &map_BitOfStandardHLTPath["L1Tech_BSC_minBias_threshold1.v0"], &b_L1Tech_BSC_minBias_threshold1_v0); 
  fChain->SetBranchAddress("L1Tech_BSC_minBias_threshold2.v0", &map_BitOfStandardHLTPath["L1Tech_BSC_minBias_threshold2.v0"], &b_L1Tech_BSC_minBias_threshold2_v0); 
  fChain->SetBranchAddress("L1Tech_BSC_minBias_inner_threshold1.v0", &map_BitOfStandardHLTPath["L1Tech_BSC_minBias_inner_threshold1.v0"], &b_L1Tech_BSC_minBias_inner_threshold1_v0); 
  fChain->SetBranchAddress("L1Tech_BSC_minBias_inner_threshold2.v0", &map_BitOfStandardHLTPath["L1Tech_BSC_minBias_inner_threshold2.v0"], &b_L1Tech_BSC_minBias_inner_threshold2_v0); 
  fChain->SetBranchAddress("L1Tech_BSC_halo_beam1_inner.v0", &map_BitOfStandardHLTPath["L1Tech_BSC_halo_beam1_inner.v0"], &b_L1Tech_BSC_halo_beam1_inner_v0); 
  fChain->SetBranchAddress("L1Tech_BSC_halo_beam1_outer.v0", &map_BitOfStandardHLTPath["L1Tech_BSC_halo_beam1_outer.v0"], &b_L1Tech_BSC_halo_beam1_outer_v0); 
  fChain->SetBranchAddress("L1Tech_BSC_halo_beam2_inner.v0", &map_BitOfStandardHLTPath["L1Tech_BSC_halo_beam2_inner.v0"], &b_L1Tech_BSC_halo_beam2_inner_v0); 
  fChain->SetBranchAddress("L1Tech_BSC_halo_beam2_outer.v0", &map_BitOfStandardHLTPath["L1Tech_BSC_halo_beam2_outer.v0"], &b_L1Tech_BSC_halo_beam2_outer_v0); 
  fChain->SetBranchAddress("L1Tech_BSC_HighMultiplicity.v0", &map_BitOfStandardHLTPath["L1Tech_BSC_HighMultiplicity.v0"], &b_L1Tech_BSC_HighMultiplicity_v0); 
  fChain->SetBranchAddress("L1Tech_BSC_splash_beam1.v0", &map_BitOfStandardHLTPath["L1Tech_BSC_splash_beam1.v0"], &b_L1Tech_BSC_splash_beam1_v0); 
  fChain->SetBranchAddress("L1Tech_BSC_splash_beam2.v0", &map_BitOfStandardHLTPath["L1Tech_BSC_splash_beam2.v0"], &b_L1Tech_BSC_splash_beam2_v0); 
  fChain->SetBranchAddress("L1Tech_RPC_TTU_barrel_Cosmics.v0", &map_BitOfStandardHLTPath["L1Tech_RPC_TTU_barrel_Cosmics.v0"], &b_L1Tech_RPC_TTU_barrel_Cosmics_v0); 
  fChain->SetBranchAddress("L1Tech_RPC_TTU_pointing_Cosmics.v0", &map_BitOfStandardHLTPath["L1Tech_RPC_TTU_pointing_Cosmics.v0"], &b_L1Tech_RPC_TTU_pointing_Cosmics_v0); 
  fChain->SetBranchAddress("L1Tech_RPC_TTU_RBst1_collisions.v0", &map_BitOfStandardHLTPath["L1Tech_RPC_TTU_RBst1_collisions.v0"], &b_L1Tech_RPC_TTU_RBst1_collisions_v0); 
  fChain->SetBranchAddress("L1Tech_HCAL_HF_MM_or_PP_or_PM.v0", &map_BitOfStandardHLTPath["L1Tech_HCAL_HF_MM_or_PP_or_PM.v0"], &b_L1Tech_HCAL_HF_MM_or_PP_or_PM_v0); 
  fChain->SetBranchAddress("L1Tech_HCAL_HF_coincidence_PM.v1", &map_BitOfStandardHLTPath["L1Tech_HCAL_HF_coincidence_PM.v1"], &b_L1Tech_HCAL_HF_coincidence_PM_v1); 
  fChain->SetBranchAddress("L1Tech_HCAL_HF_MMP_or_MPP.v0", &map_BitOfStandardHLTPath["L1Tech_HCAL_HF_MMP_or_MPP.v0"], &b_L1Tech_HCAL_HF_MMP_or_MPP_v0); 
  fChain->SetBranchAddress("L1Tech_HCAL_HO_totalOR.v0", &map_BitOfStandardHLTPath["L1Tech_HCAL_HO_totalOR.v0"], &b_L1Tech_HCAL_HO_totalOR_v0); 
  fChain->SetBranchAddress("L1Tech_HCAL_HBHE_totalOR.v0", &map_BitOfStandardHLTPath["L1Tech_HCAL_HBHE_totalOR.v0"], &b_L1Tech_HCAL_HBHE_totalOR_v0);
  fChain->SetBranchAddress("L1_BptxPlusORMinus", &map_BitOfStandardHLTPath["L1_BptxPlusORMinus"], &b_L1_BptxPlusORMinus); 
  fChain->SetBranchAddress("L1_BptxPlus_NotBptxMinus", &map_BitOfStandardHLTPath["L1_BptxPlus_NotBptxMinus"], &b_L1_BptxPlus_NotBptxMinus); 
  fChain->SetBranchAddress("L1_BptxMinus_NotBptxPlus", &map_BitOfStandardHLTPath["L1_BptxMinus_NotBptxPlus"], &b_L1_BptxMinus_NotBptxPlus); 
  //fChain->SetBranchAddress("", &map_BitOfStandardHLTPath[""], &b_); 

  fChain->SetBranchAddress("L1_Mu5_Jet6", &map_BitOfStandardHLTPath["L1_Mu5_Jet6"], &b_L1_Mu5_Jet6); 
  fChain->SetBranchAddress("L1_EG5_TripleJet6", &map_BitOfStandardHLTPath["L1_EG5_TripleJet6"], &b_L1_EG5_TripleJet6); 
  fChain->SetBranchAddress("L1_SingleJet6", &map_BitOfStandardHLTPath["L1_SingleJet6"], &b_L1_SingleJet6); 
  fChain->SetBranchAddress("L1_SingleJet10", &map_BitOfStandardHLTPath["L1_SingleJet10"], &b_L1_SingleJet10); 

  fChain->SetBranchAddress("L1_DoubleEG1", &map_BitOfStandardHLTPath["L1_DoubleEG1"], &b_L1_DoubleEG1); 
  fChain->SetBranchAddress("L1_DoubleEG2", &map_BitOfStandardHLTPath["L1_DoubleEG2"], &b_L1_DoubleEG2); 
  fChain->SetBranchAddress("L1_DoubleEG5", &map_BitOfStandardHLTPath["L1_DoubleEG5"], &b_L1_DoubleEG5); 
  fChain->SetBranchAddress("L1_DoubleHfBitCountsRing1_P1N1", &map_BitOfStandardHLTPath["L1_DoubleHfBitCountsRing1_P1N1"], &b_L1_DoubleHfBitCountsRing1_P1N1); 
  fChain->SetBranchAddress("L1_DoubleHfBitCountsRing2_P1N1", &map_BitOfStandardHLTPath["L1_DoubleHfBitCountsRing2_P1N1"], &b_L1_DoubleHfBitCountsRing2_P1N1); 
  fChain->SetBranchAddress("L1_DoubleHfRingEtSumsRing1_P200N200", &map_BitOfStandardHLTPath["L1_DoubleHfRingEtSumsRing1_P200N200"], &b_L1_DoubleHfRingEtSumsRing1_P200N200); 
  fChain->SetBranchAddress("L1_DoubleHfRingEtSumsRing1_P4N4", &map_BitOfStandardHLTPath["L1_DoubleHfRingEtSumsRing1_P4N4"], &b_L1_DoubleHfRingEtSumsRing1_P4N4); 
  fChain->SetBranchAddress("L1_DoubleHfRingEtSumsRing2_P200N200", &map_BitOfStandardHLTPath["L1_DoubleHfRingEtSumsRing2_P200N200"], &b_L1_DoubleHfRingEtSumsRing2_P200N200); 
  fChain->SetBranchAddress("L1_DoubleHfRingEtSumsRing2_P4N4", &map_BitOfStandardHLTPath["L1_DoubleHfRingEtSumsRing2_P4N4"], &b_L1_DoubleHfRingEtSumsRing2_P4N4); 
  fChain->SetBranchAddress("L1_DoubleJet70", &map_BitOfStandardHLTPath["L1_DoubleJet70"], &b_L1_DoubleJet70); 
  fChain->SetBranchAddress("L1_DoubleMu3", &map_BitOfStandardHLTPath["L1_DoubleMu3"], &b_L1_DoubleMu3); 
  fChain->SetBranchAddress("L1_DoubleMuOpen", &map_BitOfStandardHLTPath["L1_DoubleMuOpen"], &b_L1_DoubleMuOpen); 
  fChain->SetBranchAddress("L1_DoubleTauJet30", &map_BitOfStandardHLTPath["L1_DoubleTauJet30"], &b_L1_DoubleTauJet30); 
  fChain->SetBranchAddress("L1_EG10_Jet15", &map_BitOfStandardHLTPath["L1_EG10_Jet15"], &b_L1_EG10_Jet15); 
  fChain->SetBranchAddress("L1_EG5_TripleJet15", &map_BitOfStandardHLTPath["L1_EG5_TripleJet15"], &b_L1_EG5_TripleJet15); 
  fChain->SetBranchAddress("L1_ETM20", &map_BitOfStandardHLTPath["L1_ETM20"], &b_L1_ETM20); 
  fChain->SetBranchAddress("L1_ETM30", &map_BitOfStandardHLTPath["L1_ETM30"], &b_L1_ETM30); 
  fChain->SetBranchAddress("L1_ETM40", &map_BitOfStandardHLTPath["L1_ETM40"], &b_L1_ETM40); 
  fChain->SetBranchAddress("L1_ETM70", &map_BitOfStandardHLTPath["L1_ETM70"], &b_L1_ETM70); 
  fChain->SetBranchAddress("L1_ETM80", &map_BitOfStandardHLTPath["L1_ETM80"], &b_L1_ETM80); 
  fChain->SetBranchAddress("L1_ETT60", &map_BitOfStandardHLTPath["L1_ETT60"], &b_L1_ETT60); 
  fChain->SetBranchAddress("L1_HTT50", &map_BitOfStandardHLTPath["L1_HTT50"], &b_L1_HTT50); 
  fChain->SetBranchAddress("L1_HTT100", &map_BitOfStandardHLTPath["L1_HTT100"], &b_L1_HTT100); 
  fChain->SetBranchAddress("L1_HTT200", &map_BitOfStandardHLTPath["L1_HTT200"], &b_L1_HTT200); 
  fChain->SetBranchAddress("L1_HTT300", &map_BitOfStandardHLTPath["L1_HTT300"], &b_L1_HTT300); 
  fChain->SetBranchAddress("L1_IsoEG10_Jet15_ForJet10", &map_BitOfStandardHLTPath["L1_IsoEG10_Jet15_ForJet10"], &b_L1_IsoEG10_Jet15_ForJet10); 
  fChain->SetBranchAddress("L1_MinBias_HTT10", &map_BitOfStandardHLTPath["L1_MinBias_HTT10"], &b_L1_MinBias_HTT10); 
  fChain->SetBranchAddress("L1_Mu3QE8_EG5", &map_BitOfStandardHLTPath["L1_Mu3QE8_EG5"], &b_L1_Mu3QE8_EG5); 
  fChain->SetBranchAddress("L1_Mu3QE8_Jet15", &map_BitOfStandardHLTPath["L1_Mu3QE8_Jet15"], &b_L1_Mu3QE8_Jet15);  
  fChain->SetBranchAddress("L1_Mu5QE8_Jet15", &map_BitOfStandardHLTPath["L1_Mu5QE8_Jet15"], &b_L1_Mu5QE8_Jet15); 
  fChain->SetBranchAddress("L1_Mu3QE8_Jet6", &map_BitOfStandardHLTPath["L1_Mu3QE8_Jet6"], &b_L1_Mu3QE8_Jet6);  
  fChain->SetBranchAddress("L1_Mu5QE8_Jet6", &map_BitOfStandardHLTPath["L1_Mu5QE8_Jet6"], &b_L1_Mu5QE8_Jet6); 
  fChain->SetBranchAddress("L1_QuadJet15", &map_BitOfStandardHLTPath["L1_QuadJet15"], &b_L1_QuadJet15); 
  fChain->SetBranchAddress("L1_SingleEG1", &map_BitOfStandardHLTPath["L1_SingleEG1"], &b_L1_SingleEG1); 
  fChain->SetBranchAddress("L1_SingleEG10", &map_BitOfStandardHLTPath["L1_SingleEG10"], &b_L1_SingleEG10); 
  fChain->SetBranchAddress("L1_SingleEG12", &map_BitOfStandardHLTPath["L1_SingleEG12"], &b_L1_SingleEG12); 
  fChain->SetBranchAddress("L1_SingleEG15", &map_BitOfStandardHLTPath["L1_SingleEG15"], &b_L1_SingleEG15); 
  fChain->SetBranchAddress("L1_SingleEG2", &map_BitOfStandardHLTPath["L1_SingleEG2"], &b_L1_SingleEG2); 
  fChain->SetBranchAddress("L1_SingleEG20", &map_BitOfStandardHLTPath["L1_SingleEG20"], &b_L1_SingleEG20); 
  fChain->SetBranchAddress("L1_SingleEG5", &map_BitOfStandardHLTPath["L1_SingleEG5"], &b_L1_SingleEG5); 
  fChain->SetBranchAddress("L1_SingleEG8", &map_BitOfStandardHLTPath["L1_SingleEG8"], &b_L1_SingleEG8); 
  fChain->SetBranchAddress("L1_SingleHfBitCountsRing1_1", &map_BitOfStandardHLTPath["L1_SingleHfBitCountsRing1_1"], &b_L1_SingleHfBitCountsRing1_1); 
  fChain->SetBranchAddress("L1_SingleHfBitCountsRing2_1", &map_BitOfStandardHLTPath["L1_SingleHfBitCountsRing2_1"], &b_L1_SingleHfBitCountsRing2_1); 
  fChain->SetBranchAddress("L1_SingleHfRingEtSumsRing1_200", &map_BitOfStandardHLTPath["L1_SingleHfRingEtSumsRing1_200"], &b_L1_SingleHfRingEtSumsRing1_200); 
  fChain->SetBranchAddress("L1_SingleHfRingEtSumsRing1_4", &map_BitOfStandardHLTPath["L1_SingleHfRingEtSumsRing1_4"], &b_L1_SingleHfRingEtSumsRing1_4); 
  fChain->SetBranchAddress("L1_SingleHfRingEtSumsRing2_200", &map_BitOfStandardHLTPath["L1_SingleHfRingEtSumsRing2_200"], &b_L1_SingleHfRingEtSumsRing2_200); 
  fChain->SetBranchAddress("L1_SingleHfRingEtSumsRing2_4", &map_BitOfStandardHLTPath["L1_SingleHfRingEtSumsRing2_4"], &b_L1_SingleHfRingEtSumsRing2_4); 
  fChain->SetBranchAddress("L1_SingleIsoEG10", &map_BitOfStandardHLTPath["L1_SingleIsoEG10"], &b_L1_SingleIsoEG10); 
  fChain->SetBranchAddress("L1_SingleIsoEG12", &map_BitOfStandardHLTPath["L1_SingleIsoEG12"], &b_L1_SingleIsoEG12); 
  fChain->SetBranchAddress("L1_SingleIsoEG15", &map_BitOfStandardHLTPath["L1_SingleIsoEG15"], &b_L1_SingleIsoEG15); 
  fChain->SetBranchAddress("L1_SingleIsoEG5", &map_BitOfStandardHLTPath["L1_SingleIsoEG5"], &b_L1_SingleIsoEG5); 
  fChain->SetBranchAddress("L1_SingleIsoEG8", &map_BitOfStandardHLTPath["L1_SingleIsoEG8"], &b_L1_SingleIsoEG8); 
  fChain->SetBranchAddress("L1_SingleJet100", &map_BitOfStandardHLTPath["L1_SingleJet100"], &b_L1_SingleJet100); 
  fChain->SetBranchAddress("L1_SingleJet15", &map_BitOfStandardHLTPath["L1_SingleJet15"], &b_L1_SingleJet15); 
  fChain->SetBranchAddress("L1_SingleJet30", &map_BitOfStandardHLTPath["L1_SingleJet30"], &b_L1_SingleJet30); 
  fChain->SetBranchAddress("L1_SingleJet50", &map_BitOfStandardHLTPath["L1_SingleJet50"], &b_L1_SingleJet50); 
  fChain->SetBranchAddress("L1_SingleJet70", &map_BitOfStandardHLTPath["L1_SingleJet70"], &b_L1_SingleJet70); 
  fChain->SetBranchAddress("L1_SingleMu0", &map_BitOfStandardHLTPath["L1_SingleMu0"], &b_L1_SingleMu0); 
  fChain->SetBranchAddress("L1_SingleMu10", &map_BitOfStandardHLTPath["L1_SingleMu10"], &b_L1_SingleMu10); 
  fChain->SetBranchAddress("L1_SingleMu14", &map_BitOfStandardHLTPath["L1_SingleMu14"], &b_L1_SingleMu14); 
  fChain->SetBranchAddress("L1_SingleMu20", &map_BitOfStandardHLTPath["L1_SingleMu20"], &b_L1_SingleMu20); 
  fChain->SetBranchAddress("L1_SingleMu3", &map_BitOfStandardHLTPath["L1_SingleMu3"], &b_L1_SingleMu3); 
  fChain->SetBranchAddress("L1_SingleMu5", &map_BitOfStandardHLTPath["L1_SingleMu5"], &b_L1_SingleMu5); 
  fChain->SetBranchAddress("L1_SingleMu7", &map_BitOfStandardHLTPath["L1_SingleMu7"], &b_L1_SingleMu7); 
  fChain->SetBranchAddress("L1_SingleMuBeamHalo", &map_BitOfStandardHLTPath["L1_SingleMuBeamHalo"], &b_L1_SingleMuBeamHalo); 
  fChain->SetBranchAddress("L1_SingleMuOpen", &map_BitOfStandardHLTPath["L1_SingleMuOpen"], &b_L1_SingleMuOpen); 
  fChain->SetBranchAddress("L1_SingleTauJet40", &map_BitOfStandardHLTPath["L1_SingleTauJet40"], &b_L1_SingleTauJet40); 
  fChain->SetBranchAddress("L1_SingleTauJet60", &map_BitOfStandardHLTPath["L1_SingleTauJet60"], &b_L1_SingleTauJet60); 
  fChain->SetBranchAddress("L1_SingleTauJet80", &map_BitOfStandardHLTPath["L1_SingleTauJet80"], &b_L1_SingleTauJet80); 
  fChain->SetBranchAddress("L1_TripleJet30", &map_BitOfStandardHLTPath["L1_TripleJet30"], &b_L1_TripleJet30); 
  fChain->SetBranchAddress("L1_ZeroBias", &map_BitOfStandardHLTPath["L1_ZeroBias"], &b_L1_ZeroBias);
  fChain->SetBranchAddress("L1_ZeroBias_Ext", &map_BitOfStandardHLTPath["L1_ZeroBias_Ext"], &b_L1_ZeroBias_Ext);
  fChain->SetBranchAddress("L1_SingleCenJet2", &map_BitOfStandardHLTPath["L1_SingleCenJet2"], &b_L1_SingleCenJet2); 
  fChain->SetBranchAddress("L1_SingleCenJet4", &map_BitOfStandardHLTPath["L1_SingleCenJet4"], &b_L1_SingleCenJet4); 
  fChain->SetBranchAddress("L1_SingleForJet2", &map_BitOfStandardHLTPath["L1_SingleForJet2"], &b_L1_SingleForJet2); 
  fChain->SetBranchAddress("L1_SingleForJet4", &map_BitOfStandardHLTPath["L1_SingleForJet4"], &b_L1_SingleForJet4); 
  fChain->SetBranchAddress("L1_SingleTauJet2", &map_BitOfStandardHLTPath["L1_SingleTauJet2"], &b_L1_SingleTauJet2); 
  fChain->SetBranchAddress("L1_SingleTauJet4", &map_BitOfStandardHLTPath["L1_SingleTauJet4"], &b_L1_SingleTauJet4); 
  fChain->SetBranchAddress("L1_DoubleForJet10_EtaOpp", &map_BitOfStandardHLTPath["L1_DoubleForJet10_EtaOpp"], &b_L1_DoubleForJet10_EtaOpp); 
  fChain->SetBranchAddress("L1_BscMinBiasOR_BptxPlusORMinus", &map_BitOfStandardHLTPath["L1_BscMinBiasOR_BptxPlusORMinus"], &b_L1_BscMinBiasOR_BptxPlusORMinus); 

  fChain->SetBranchAddress("L1_DoubleMuTopBottom", &map_BitOfStandardHLTPath["L1_DoubleMuTopBottom"], &b_L1_DoubleMuTopBottom); 
  fChain->SetBranchAddress("L1_DoubleEG05_TopBottom", &map_BitOfStandardHLTPath["L1_DoubleEG05_TopBottom"], &b_L1_DoubleEG05_TopBottom);  


  fChain->SetBranchAddress("L1_SingleJet20", &map_BitOfStandardHLTPath["L1_SingleJet20"], &b_L1_SingleJet20); 
  fChain->SetBranchAddress("L1_SingleJet40", &map_BitOfStandardHLTPath["L1_SingleJet40"], &b_L1_SingleJet40); 
  fChain->SetBranchAddress("L1_SingleJet60", &map_BitOfStandardHLTPath["L1_SingleJet60"], &b_L1_SingleJet60); 
  fChain->SetBranchAddress("L1_SingleTauJet10", &map_BitOfStandardHLTPath["L1_SingleTauJet10"], &b_L1_SingleTauJet10); 
  fChain->SetBranchAddress("L1_SingleTauJet20", &map_BitOfStandardHLTPath["L1_SingleTauJet20"], &b_L1_SingleTauJet20); 
  fChain->SetBranchAddress("L1_SingleTauJet30", &map_BitOfStandardHLTPath["L1_SingleTauJet30"], &b_L1_SingleTauJet30); 
  fChain->SetBranchAddress("L1_SingleTauJet50", &map_BitOfStandardHLTPath["L1_SingleTauJet50"], &b_L1_SingleTauJet50); 
  fChain->SetBranchAddress("L1_DoubleJet30", &map_BitOfStandardHLTPath["L1_DoubleJet30"], &b_L1_DoubleJet30);  
  fChain->SetBranchAddress("L1_DoubleTauJet14", &map_BitOfStandardHLTPath["L1_DoubleTauJet14"], &b_L1_DoubleTauJet14); 
  fChain->SetBranchAddress("L1_TripleJet14", &map_BitOfStandardHLTPath["L1_TripleJet14"], &b_L1_TripleJet14);  
  fChain->SetBranchAddress("L1_QuadJet6", &map_BitOfStandardHLTPath["L1_QuadJet6"], &b_L1_QuadJet6); 
  fChain->SetBranchAddress("L1_IsoEG10_Jet6_ForJet6", &map_BitOfStandardHLTPath["L1_IsoEG10_Jet6_ForJet6"], &b_L1_IsoEG10_Jet6_ForJet6); 
  
  // JH - 1E31 MC menu
  fChain->SetBranchAddress("HLT_L1Jet15", &map_BitOfStandardHLTPath["HLT_L1Jet15"], &b_HLT_L1Jet15);
  fChain->SetBranchAddress("HLT_Jet30", &map_BitOfStandardHLTPath["HLT_Jet30"], &b_HLT_Jet30);
  fChain->SetBranchAddress("HLT_Jet50", &map_BitOfStandardHLTPath["HLT_Jet50"], &b_HLT_Jet50);
  fChain->SetBranchAddress("HLT_Jet80", &map_BitOfStandardHLTPath["HLT_Jet80"], &b_HLT_Jet80);
  fChain->SetBranchAddress("HLT_Jet110", &map_BitOfStandardHLTPath["HLT_Jet110"], &b_HLT_Jet110);
  fChain->SetBranchAddress("HLT_Jet140", &map_BitOfStandardHLTPath["HLT_Jet140"], &b_HLT_Jet140);
  fChain->SetBranchAddress("HLT_Jet180", &map_BitOfStandardHLTPath["HLT_Jet180"], &b_HLT_Jet180);
  fChain->SetBranchAddress("HLT_FwdJet40", &map_BitOfStandardHLTPath["HLT_FwdJet40"], &b_HLT_FwdJet40);
  fChain->SetBranchAddress("HLT_DiJetAve15U_1E31", &map_BitOfStandardHLTPath["HLT_DiJetAve15U_1E31"], &b_HLT_DiJetAve15U_1E31);
  fChain->SetBranchAddress("HLT_DiJetAve30U_1E31", &map_BitOfStandardHLTPath["HLT_DiJetAve30U_1E31"], &b_HLT_DiJetAve30U_1E31);
  fChain->SetBranchAddress("HLT_DiJetAve50U", &map_BitOfStandardHLTPath["HLT_DiJetAve50U"], &b_HLT_DiJetAve50U);
  fChain->SetBranchAddress("HLT_DiJetAve70U", &map_BitOfStandardHLTPath["HLT_DiJetAve70U"], &b_HLT_DiJetAve70U);
  fChain->SetBranchAddress("HLT_DiJetAve130U", &map_BitOfStandardHLTPath["HLT_DiJetAve130U"], &b_HLT_DiJetAve130U);
  fChain->SetBranchAddress("HLT_QuadJet30", &map_BitOfStandardHLTPath["HLT_QuadJet30"], &b_HLT_QuadJet30);
  fChain->SetBranchAddress("HLT_SumET120", &map_BitOfStandardHLTPath["HLT_SumET120"], &b_HLT_SumET120);
  fChain->SetBranchAddress("HLT_L1MET20", &map_BitOfStandardHLTPath["HLT_L1MET20"], &b_HLT_L1MET20);
  fChain->SetBranchAddress("HLT_MET35", &map_BitOfStandardHLTPath["HLT_MET35"], &b_HLT_MET35);
  fChain->SetBranchAddress("HLT_MET60", &map_BitOfStandardHLTPath["HLT_MET60"], &b_HLT_MET60);
  fChain->SetBranchAddress("HLT_HT200", &map_BitOfStandardHLTPath["HLT_HT200"], &b_HLT_HT200);
  fChain->SetBranchAddress("HLT_HT300_MHT100", &map_BitOfStandardHLTPath["HLT_HT300_MHT100"], &b_HLT_HT300_MHT100);
  fChain->SetBranchAddress("HLT_L1MuOpen", &map_BitOfStandardHLTPath["HLT_L1MuOpen"], &b_HLT_L1MuOpen);
  fChain->SetBranchAddress("HLT_L1Mu", &map_BitOfStandardHLTPath["HLT_L1Mu"], &b_HLT_L1Mu);
  fChain->SetBranchAddress("HLT_L1Mu20HQ", &map_BitOfStandardHLTPath["HLT_L1Mu20HQ"], &b_HLT_L1Mu20HQ);
  fChain->SetBranchAddress("HLT_L1Mu30", &map_BitOfStandardHLTPath["HLT_L1Mu30"], &b_HLT_L1Mu30);
  fChain->SetBranchAddress("HLT_IsoMu9", &map_BitOfStandardHLTPath["HLT_IsoMu9"], &b_HLT_IsoMu9);
  fChain->SetBranchAddress("HLT_Mu5", &map_BitOfStandardHLTPath["HLT_Mu5"], &b_HLT_Mu5);
  fChain->SetBranchAddress("HLT_Mu9", &map_BitOfStandardHLTPath["HLT_Mu9"], &b_HLT_Mu9);
  fChain->SetBranchAddress("HLT_Mu11", &map_BitOfStandardHLTPath["HLT_Mu11"], &b_HLT_Mu11);
  fChain->SetBranchAddress("HLT_Mu15", &map_BitOfStandardHLTPath["HLT_Mu15"], &b_HLT_Mu15);
  fChain->SetBranchAddress("HLT_DoubleMu3", &map_BitOfStandardHLTPath["HLT_DoubleMu3"], &b_HLT_DoubleMu3);
  fChain->SetBranchAddress("HLT_Ele10_SW_L1R", &map_BitOfStandardHLTPath["HLT_Ele10_SW_L1R"], &b_HLT_Ele10_SW_L1R);
  fChain->SetBranchAddress("HLT_Ele15_SW_L1R", &map_BitOfStandardHLTPath["HLT_Ele15_SW_L1R"], &b_HLT_Ele15_SW_L1R);
  fChain->SetBranchAddress("HLT_Ele15_SW_EleId_L1R", &map_BitOfStandardHLTPath["HLT_Ele15_SW_EleId_L1R"], &b_HLT_Ele15_SW_EleId_L1R);
  fChain->SetBranchAddress("HLT_Ele15_SW_LooseTrackIso_L1R", &map_BitOfStandardHLTPath["HLT_Ele15_SW_LooseTrackIso_L1R"], &b_HLT_Ele15_SW_LooseTrackIso_L1R);
  fChain->SetBranchAddress("HLT_Ele15_SC15_SW_LooseTrackIso_L1R", &map_BitOfStandardHLTPath["HLT_Ele15_SC15_SW_LooseTrackIso_L1R"], &b_HLT_Ele15_SC15_SW_LooseTrackIso_L1R);
  fChain->SetBranchAddress("HLT_Ele15_SC15_SW_EleId_L1R", &map_BitOfStandardHLTPath["HLT_Ele15_SC15_SW_EleId_L1R"], &b_HLT_Ele15_SC15_SW_EleId_L1R);
  fChain->SetBranchAddress("HLT_Ele20_SW_L1R", &map_BitOfStandardHLTPath["HLT_Ele20_SW_L1R"], &b_HLT_Ele20_SW_L1R);
  fChain->SetBranchAddress("HLT_Ele20_SiStrip_L1R", &map_BitOfStandardHLTPath["HLT_Ele20_SiStrip_L1R"], &b_HLT_Ele20_SiStrip_L1R);
  fChain->SetBranchAddress("HLT_Ele20_SC15_SW_L1R", &map_BitOfStandardHLTPath["HLT_Ele20_SC15_SW_L1R"], &b_HLT_Ele20_SC15_SW_L1R);
  fChain->SetBranchAddress("HLT_Ele25_SW_L1R", &map_BitOfStandardHLTPath["HLT_Ele25_SW_L1R"], &b_HLT_Ele25_SW_L1R);
  fChain->SetBranchAddress("HLT_Ele25_SW_EleId_LooseTrackIso_L1R", &map_BitOfStandardHLTPath["HLT_Ele25_SW_EleId_LooseTrackIso_L1R"], &b_HLT_Ele25_SW_EleId_LooseTrackIso_L1R);
  fChain->SetBranchAddress("HLT_DoubleEle5_SW_Jpsi_L1R", &map_BitOfStandardHLTPath["HLT_DoubleEle5_SW_Jpsi_L1R"], &b_HLT_DoubleEle5_SW_Jpsi_L1R);
  fChain->SetBranchAddress("HLT_DoubleEle5_SW_Upsilon_L1R", &map_BitOfStandardHLTPath["HLT_DoubleEle5_SW_Upsilon_L1R"], &b_HLT_DoubleEle5_SW_Upsilon_L1R);
  fChain->SetBranchAddress("HLT_DoubleEle10_SW_L1R", &map_BitOfStandardHLTPath["HLT_DoubleEle10_SW_L1R"], &b_HLT_DoubleEle10_SW_L1R);
  fChain->SetBranchAddress("HLT_Photon10_LooseEcalIso_TrackIso_L1R", &map_BitOfStandardHLTPath["HLT_Photon10_LooseEcalIso_TrackIso_L1R"], &b_HLT_Photon10_LooseEcalIso_TrackIso_L1R);
  fChain->SetBranchAddress("HLT_Photon15_L1R", &map_BitOfStandardHLTPath["HLT_Photon15_L1R"], &b_HLT_Photon15_L1R);
  fChain->SetBranchAddress("HLT_Photon20_LooseEcalIso_TrackIso_L1R", &map_BitOfStandardHLTPath["HLT_Photon20_LooseEcalIso_TrackIso_L1R"], &b_HLT_Photon20_LooseEcalIso_TrackIso_L1R);
  fChain->SetBranchAddress("HLT_Photon25_L1R", &map_BitOfStandardHLTPath["HLT_Photon25_L1R"], &b_HLT_Photon25_L1R);
  fChain->SetBranchAddress("HLT_Photon25_LooseEcalIso_TrackIso_L1R", &map_BitOfStandardHLTPath["HLT_Photon25_LooseEcalIso_TrackIso_L1R"], &b_HLT_Photon25_LooseEcalIso_TrackIso_L1R);
  fChain->SetBranchAddress("HLT_Photon30_L1R_1E31", &map_BitOfStandardHLTPath["HLT_Photon30_L1R_1E31"], &b_HLT_Photon30_L1R_1E31);
  fChain->SetBranchAddress("HLT_Photon70_L1R", &map_BitOfStandardHLTPath["HLT_Photon70_L1R"], &b_HLT_Photon70_L1R);
  fChain->SetBranchAddress("HLT_DoublePhoton15_L1R", &map_BitOfStandardHLTPath["HLT_DoublePhoton15_L1R"], &b_HLT_DoublePhoton15_L1R);
  fChain->SetBranchAddress("HLT_DoublePhoton15_VeryLooseEcalIso_L1R", &map_BitOfStandardHLTPath["HLT_DoublePhoton15_VeryLooseEcalIso_L1R"], &b_HLT_DoublePhoton15_VeryLooseEcalIso_L1R);
  fChain->SetBranchAddress("HLT_SingleIsoTau30_Trk5", &map_BitOfStandardHLTPath["HLT_SingleIsoTau30_Trk5"], &b_HLT_SingleIsoTau30_Trk5);
  fChain->SetBranchAddress("HLT_DoubleLooseIsoTau15_Trk5", &map_BitOfStandardHLTPath["HLT_DoubleLooseIsoTau15_Trk5"], &b_HLT_DoubleLooseIsoTau15_Trk5);
  fChain->SetBranchAddress("HLT_BTagIP_Jet80", &map_BitOfStandardHLTPath["HLT_BTagIP_Jet80"], &b_HLT_BTagIP_Jet80);
  fChain->SetBranchAddress("HLT_BTagMu_Jet20", &map_BitOfStandardHLTPath["HLT_BTagMu_Jet20"], &b_HLT_BTagMu_Jet20);
  fChain->SetBranchAddress("HLT_BTagIP_Jet120", &map_BitOfStandardHLTPath["HLT_BTagIP_Jet120"], &b_HLT_BTagIP_Jet120);
  fChain->SetBranchAddress("HLT_StoppedHSCP_1E31", &map_BitOfStandardHLTPath["HLT_StoppedHSCP_1E31"], &b_HLT_StoppedHSCP_1E31);
  fChain->SetBranchAddress("HLT_L1Mu14_L1SingleJet15", &map_BitOfStandardHLTPath["HLT_L1Mu14_L1SingleJet15"], &b_HLT_L1Mu14_L1SingleJet15);
  fChain->SetBranchAddress("HLT_L1Mu14_L1ETM40", &map_BitOfStandardHLTPath["HLT_L1Mu14_L1ETM40"], &b_HLT_L1Mu14_L1ETM40);
  fChain->SetBranchAddress("HLT_L2Mu5_Photon9_L1R", &map_BitOfStandardHLTPath["HLT_L2Mu5_Photon9_L1R"], &b_HLT_L2Mu5_Photon9_L1R);
  fChain->SetBranchAddress("HLT_L2Mu9_DiJet30", &map_BitOfStandardHLTPath["HLT_L2Mu9_DiJet30"], &b_HLT_L2Mu9_DiJet30);
  fChain->SetBranchAddress("HLT_L2Mu8_HT50", &map_BitOfStandardHLTPath["HLT_L2Mu8_HT50"], &b_HLT_L2Mu8_HT50);
  fChain->SetBranchAddress("HLT_Ele10_SW_L1R_TripleJet30", &map_BitOfStandardHLTPath["HLT_Ele10_SW_L1R_TripleJet30"], &b_HLT_Ele10_SW_L1R_TripleJet30);
  fChain->SetBranchAddress("HLT_Ele10_LW_L1R_HT180", &map_BitOfStandardHLTPath["HLT_Ele10_LW_L1R_HT180"], &b_HLT_Ele10_LW_L1R_HT180);
  fChain->SetBranchAddress("HLT_ZeroBias", &map_BitOfStandardHLTPath["HLT_ZeroBias"], &b_HLT_ZeroBias);
  fChain->SetBranchAddress("HLT_MinBiasHcal", &map_BitOfStandardHLTPath["HLT_MinBiasHcal"], &b_HLT_MinBiasHcal);
  fChain->SetBranchAddress("HLT_MinBiasEcal", &map_BitOfStandardHLTPath["HLT_MinBiasEcal"], &b_HLT_MinBiasEcal);
  fChain->SetBranchAddress("HLT_MinBiasPixel", &map_BitOfStandardHLTPath["HLT_MinBiasPixel"], &b_HLT_MinBiasPixel);
  fChain->SetBranchAddress("HLT_MinBiasPixel_Trk5", &map_BitOfStandardHLTPath["HLT_MinBiasPixel_Trk5"], &b_HLT_MinBiasPixel_Trk5);
  fChain->SetBranchAddress("HLT_ZeroBiasPixel_SingleTrack", &map_BitOfStandardHLTPath["HLT_ZeroBiasPixel_SingleTrack"], &b_HLT_ZeroBiasPixel_SingleTrack);
  fChain->SetBranchAddress("HLT_CSCBeamHalo", &map_BitOfStandardHLTPath["HLT_CSCBeamHalo"], &b_HLT_CSCBeamHalo);
  fChain->SetBranchAddress("HLT_CSCBeamHaloOverlapRing1", &map_BitOfStandardHLTPath["HLT_CSCBeamHaloOverlapRing1"], &b_HLT_CSCBeamHaloOverlapRing1);
  fChain->SetBranchAddress("HLT_CSCBeamHaloOverlapRing2", &map_BitOfStandardHLTPath["HLT_CSCBeamHaloOverlapRing2"], &b_HLT_CSCBeamHaloOverlapRing2);
  fChain->SetBranchAddress("HLT_CSCBeamHaloRing2or3", &map_BitOfStandardHLTPath["HLT_CSCBeamHaloRing2or3"], &b_HLT_CSCBeamHaloRing2or3);
  fChain->SetBranchAddress("HLT_BackwardBSC", &map_BitOfStandardHLTPath["HLT_BackwardBSC"], &b_HLT_BackwardBSC);
  fChain->SetBranchAddress("HLT_ForwardBSC", &map_BitOfStandardHLTPath["HLT_ForwardBSC"], &b_HLT_ForwardBSC);
  fChain->SetBranchAddress("HLT_TrackerCosmics", &map_BitOfStandardHLTPath["HLT_TrackerCosmics"], &b_HLT_TrackerCosmics);
  fChain->SetBranchAddress("HLT_IsoTrack_1E31", &map_BitOfStandardHLTPath["HLT_IsoTrack_1E31"], &b_HLT_IsoTrack_1E31);
  fChain->SetBranchAddress("AlCa_EcalPhiSym", &map_BitOfStandardHLTPath["AlCa_EcalPhiSym"], &b_AlCa_EcalPhiSym);
  fChain->SetBranchAddress("AlCa_EcalPi0_1E31", &map_BitOfStandardHLTPath["AlCa_EcalPi0_1E31"], &b_AlCa_EcalPi0_1E31);
  fChain->SetBranchAddress("AlCa_EcalEta_1E31", &map_BitOfStandardHLTPath["AlCa_EcalEta_1E31"], &b_AlCa_EcalEta_1E31);

  // 8E29 menu
  fChain->SetBranchAddress("HLT_L1Jet6U", &map_BitOfStandardHLTPath["HLT_L1Jet6U"], &b_HLT_L1Jet6U);
  fChain->SetBranchAddress("HLT_Jet15U", &map_BitOfStandardHLTPath["HLT_Jet15U"], &b_HLT_Jet15U);
  fChain->SetBranchAddress("HLT_Jet30U", &map_BitOfStandardHLTPath["HLT_Jet30U"], &b_HLT_Jet30U);
  fChain->SetBranchAddress("HLT_Jet50U", &map_BitOfStandardHLTPath["HLT_Jet50U"], &b_HLT_Jet50U);
  fChain->SetBranchAddress("HLT_FwdJet20U", &map_BitOfStandardHLTPath["HLT_FwdJet20U"], &b_HLT_FwdJet20U);
  fChain->SetBranchAddress("HLT_DiJetAve15U_8E29", &map_BitOfStandardHLTPath["HLT_DiJetAve15U_8E29"], &b_HLT_DiJetAve15U_8E29);
  fChain->SetBranchAddress("HLT_DiJetAve30U_8E29", &map_BitOfStandardHLTPath["HLT_DiJetAve30U_8E29"], &b_HLT_DiJetAve30U_8E29);
  fChain->SetBranchAddress("HLT_QuadJet15U", &map_BitOfStandardHLTPath["HLT_QuadJet15U"], &b_HLT_QuadJet15U);
  fChain->SetBranchAddress("HLT_MET45", &map_BitOfStandardHLTPath["HLT_MET45"], &b_HLT_MET45);
  fChain->SetBranchAddress("HLT_MET100", &map_BitOfStandardHLTPath["HLT_MET100"], &b_HLT_MET100);
  fChain->SetBranchAddress("HLT_HT100U", &map_BitOfStandardHLTPath["HLT_HT100U"], &b_HLT_HT100U);
  fChain->SetBranchAddress("HLT_L1Mu20", &map_BitOfStandardHLTPath["HLT_L1Mu20"], &b_HLT_L1Mu20);
  fChain->SetBranchAddress("HLT_L2Mu9", &map_BitOfStandardHLTPath["HLT_L2Mu9"], &b_HLT_L2Mu9);
  fChain->SetBranchAddress("HLT_L2Mu11", &map_BitOfStandardHLTPath["HLT_L2Mu11"], &b_HLT_L2Mu11);
  fChain->SetBranchAddress("HLT_Mu3", &map_BitOfStandardHLTPath["HLT_Mu3"], &b_HLT_Mu3); 
  fChain->SetBranchAddress("HLT_IsoMu3", &map_BitOfStandardHLTPath["HLT_IsoMu3"], &b_HLT_IsoMu3);
  fChain->SetBranchAddress("HLT_L1DoubleMuOpen", &map_BitOfStandardHLTPath["HLT_L1DoubleMuOpen"], &b_HLT_L1DoubleMuOpen);
  fChain->SetBranchAddress("HLT_DoubleMu0", &map_BitOfStandardHLTPath["HLT_DoubleMu0"], &b_HLT_DoubleMu0);
  fChain->SetBranchAddress("HLT_L1SingleEG5", &map_BitOfStandardHLTPath["HLT_L1SingleEG5"], &b_HLT_L1SingleEG5);
  fChain->SetBranchAddress("HLT_L1SingleEG8", &map_BitOfStandardHLTPath["HLT_L1SingleEG8"], &b_HLT_L1SingleEG8);
  fChain->SetBranchAddress("HLT_Ele10_LW_L1R", &map_BitOfStandardHLTPath["HLT_Ele10_LW_L1R"], &b_HLT_Ele10_LW_L1R);
  fChain->SetBranchAddress("HLT_Ele10_LW_EleId_L1R", &map_BitOfStandardHLTPath["HLT_Ele10_LW_EleId_L1R"], &b_HLT_Ele10_LW_EleId_L1R);
  fChain->SetBranchAddress("HLT_Ele15_LW_L1R", &map_BitOfStandardHLTPath["HLT_Ele15_LW_L1R"], &b_HLT_Ele15_LW_L1R); 
  fChain->SetBranchAddress("HLT_Ele15_SC10_LW_L1R", &map_BitOfStandardHLTPath["HLT_Ele15_SC10_LW_L1R"], &b_HLT_Ele15_SC10_LW_L1R);
  fChain->SetBranchAddress("HLT_Ele15_SiStrip_L1R", &map_BitOfStandardHLTPath["HLT_Ele15_SiStrip_L1R"], &b_HLT_Ele15_SiStrip_L1R);
  fChain->SetBranchAddress("HLT_Ele20_LW_L1R", &map_BitOfStandardHLTPath["HLT_Ele20_LW_L1R"], &b_HLT_Ele20_LW_L1R);
  fChain->SetBranchAddress("HLT_L1DoubleEG5", &map_BitOfStandardHLTPath["HLT_L1DoubleEG5"], &b_HLT_L1DoubleEG5);
  fChain->SetBranchAddress("HLT_DoubleEle5_SW_L1R", &map_BitOfStandardHLTPath["HLT_DoubleEle5_SW_L1R"], &b_HLT_DoubleEle5_SW_L1R); 
  fChain->SetBranchAddress("HLT_DoublePhoton5_eeRes_L1R", &map_BitOfStandardHLTPath["HLT_DoublePhoton5_eeRes_L1R"], &b_HLT_DoublePhoton5_eeRes_L1R);
  fChain->SetBranchAddress("HLT_DoublePhoton5_Jpsi_L1R", &map_BitOfStandardHLTPath["HLT_DoublePhoton5_Jpsi_L1R"], &b_HLT_DoublePhoton5_Jpsi_L1R);
  fChain->SetBranchAddress("HLT_DoublePhoton5_Upsilon_L1R", &map_BitOfStandardHLTPath["HLT_DoublePhoton5_Upsilon_L1R"], &b_HLT_DoublePhoton5_Upsilon_L1R);
  fChain->SetBranchAddress("HLT_Photon10_L1R", &map_BitOfStandardHLTPath["HLT_Photon10_L1R"], &b_HLT_Photon10_L1R);
  fChain->SetBranchAddress("HLT_Photon15_TrackIso_L1R", &map_BitOfStandardHLTPath["HLT_Photon15_TrackIso_L1R"], &b_HLT_Photon15_TrackIso_L1R);
  fChain->SetBranchAddress("HLT_Photon15_LooseEcalIso_L1R", &map_BitOfStandardHLTPath["HLT_Photon15_LooseEcalIso_L1R"], &b_HLT_Photon15_LooseEcalIso_L1R);
  fChain->SetBranchAddress("HLT_Photon20_L1R", &map_BitOfStandardHLTPath["HLT_Photon20_L1R"], &b_HLT_Photon20_L1R);
  fChain->SetBranchAddress("HLT_Photon30_L1R_8E29", &map_BitOfStandardHLTPath["HLT_Photon30_L1R_8E29"], &b_HLT_Photon30_L1R_8E29);
  fChain->SetBranchAddress("HLT_DoublePhoton10_L1R", &map_BitOfStandardHLTPath["HLT_DoublePhoton10_L1R"], &b_HLT_DoublePhoton10_L1R);
  fChain->SetBranchAddress("HLT_SingleLooseIsoTau20", &map_BitOfStandardHLTPath["HLT_SingleLooseIsoTau20"], &b_HLT_SingleLooseIsoTau20);
  fChain->SetBranchAddress("HLT_DoubleLooseIsoTau15", &map_BitOfStandardHLTPath["HLT_DoubleLooseIsoTau15"], &b_HLT_DoubleLooseIsoTau15);
  fChain->SetBranchAddress("HLT_BTagMu_Jet10U", &map_BitOfStandardHLTPath["HLT_BTagMu_Jet10U"], &b_HLT_BTagMu_Jet10U);
  fChain->SetBranchAddress("HLT_BTagIP_Jet50U", &map_BitOfStandardHLTPath["HLT_BTagIP_Jet50U"], &b_HLT_BTagIP_Jet50U);
  fChain->SetBranchAddress("HLT_StoppedHSCP_8E29", &map_BitOfStandardHLTPath["HLT_StoppedHSCP_8E29"], &b_HLT_StoppedHSCP_8E29);
  fChain->SetBranchAddress("HLT_L1Mu14_L1SingleEG10", &map_BitOfStandardHLTPath["HLT_L1Mu14_L1SingleEG10"], &b_HLT_L1Mu14_L1SingleEG10);
  fChain->SetBranchAddress("HLT_L1Mu14_L1SingleJet6U", &map_BitOfStandardHLTPath["HLT_L1Mu14_L1SingleJet6U"], &b_HLT_L1Mu14_L1SingleJet6U);
  fChain->SetBranchAddress("HLT_L1Mu14_L1ETM30", &map_BitOfStandardHLTPath["HLT_L1Mu14_L1ETM30"], &b_HLT_L1Mu14_L1ETM30);
  fChain->SetBranchAddress("HLT_IsoTrack_8E29", &map_BitOfStandardHLTPath["HLT_IsoTrack_8E29"], &b_HLT_IsoTrack_8E29);
  fChain->SetBranchAddress("AlCa_HcalPhiSym", &map_BitOfStandardHLTPath["AlCa_HcalPhiSym"], &b_AlCa_HcalPhiSym);
  fChain->SetBranchAddress("AlCa_EcalPi0_8E29", &map_BitOfStandardHLTPath["AlCa_EcalPi0_8E29"], &b_AlCa_EcalPi0_8E29);
  fChain->SetBranchAddress("AlCa_EcalEta_8E29", &map_BitOfStandardHLTPath["AlCa_EcalEta_8E29"], &b_AlCa_EcalEta_8E29);
  fChain->SetBranchAddress("AlCa_RPCMuonNoHits", &map_BitOfStandardHLTPath["AlCa_RPCMuonNoHits"], &b_AlCa_RPCMuonNoHits);
  fChain->SetBranchAddress("AlCa_RPCMuonNormalisation", &map_BitOfStandardHLTPath["AlCa_RPCMuonNormalisation"], &b_AlCa_RPCMuonNormalisation);

  // Commissioning and other HLT Paths for the CRAFT09 cosmics menu  
  fChain->SetBranchAddress("HLT_Random", &map_BitOfStandardHLTPath["HLT_Random"], &b_HLT_Random);  
  fChain->SetBranchAddress("HLT_L2Mu3_NoVertex", &map_BitOfStandardHLTPath["HLT_L2Mu3_NoVertex"], &b_HLT_L2Mu3_NoVertex);  
  fChain->SetBranchAddress("HLT_OIstateTkMu3", &map_BitOfStandardHLTPath["HLT_OIstateTkMu3"], &b_HLT_OIstateTkMu3);  
  fChain->SetBranchAddress("HLT_TrackPointing", &map_BitOfStandardHLTPath["HLT_TrackPointing"], &b_HLT_TrackPointing);  
  fChain->SetBranchAddress("HLT_EgammaSuperClusterOnly_L1R", &map_BitOfStandardHLTPath["HLT_EgammaSuperClusterOnly_L1R"], &b_HLT_EgammaSuperClusterOnly_L1R);  
  fChain->SetBranchAddress("AlCa_EcalPi0_Cosmics", &map_BitOfStandardHLTPath["AlCa_EcalPi0_Cosmics"], &b_AlCa_EcalPi0_Cosmics);   
  fChain->SetBranchAddress("AlCa_EcalEta_Cosmics", &map_BitOfStandardHLTPath["AlCa_EcalEta_Cosmics"], &b_AlCa_EcalEta_Cosmics);   
  fChain->SetBranchAddress("HLT_DataIntegrity", &map_BitOfStandardHLTPath["HLT_DataIntegrity"], &b_HLT_DataIntegrity);   
  fChain->SetBranchAddress("HLT_L1_BPTX", &map_BitOfStandardHLTPath["HLT_L1_BPTX"], &b_HLT_L1_BPTX);   
  fChain->SetBranchAddress("HLT_L1_BSC", &map_BitOfStandardHLTPath["HLT_L1_BSC"], &b_HLT_L1_BSC);   
  fChain->SetBranchAddress("HLT_L1_HFtech", &map_BitOfStandardHLTPath["HLT_L1_HFtech"], &b_HLT_L1_HFtech);   
  fChain->SetBranchAddress("HLT_HFThreshold", &map_BitOfStandardHLTPath["HLT_HFThreshold"], &b_HLT_HFThreshold);   
  fChain->SetBranchAddress("HLT_Physics", &map_BitOfStandardHLTPath["HLT_Physics"], &b_HLT_Physics);   
  fChain->SetBranchAddress("HLT_PhysicsNoMuon", &map_BitOfStandardHLTPath["HLT_PhysicsNoMuon"], &b_HLT_PhysicsNoMuon);   
  fChain->SetBranchAddress("HLT_Calibration", &map_BitOfStandardHLTPath["HLT_Calibration"], &b_HLT_Calibration);   
  fChain->SetBranchAddress("HLT_EcalCalibration", &map_BitOfStandardHLTPath["HLT_EcalCalibration"], &b_HLT_EcalCalibration);   
  fChain->SetBranchAddress("HLT_PixelFEDSize", &map_BitOfStandardHLTPath["HLT_PixelFEDSize"], &b_HLT_PixelFEDSize);   
  fChain->SetBranchAddress("HLT_GlobalRunHPDNoise", &map_BitOfStandardHLTPath["HLT_GlobalRunHPDNoise"], &b_HLT_GlobalRunHPDNoise);   

  // HLT paths for the 2009 Circulating Beam menu
  fChain->SetBranchAddress("HLT_L2Mu0_NoVertex", &map_BitOfStandardHLTPath["HLT_L2Mu0_NoVertex"], &b_HLT_L2Mu0_NoVertex);
  fChain->SetBranchAddress("HLT_TkMu3_NoVertex", &map_BitOfStandardHLTPath["HLT_TkMu3_NoVertex"], &b_HLT_TkMu3_NoVertex);
  fChain->SetBranchAddress("HLT_IsoTrackHB_8E29", &map_BitOfStandardHLTPath["HLT_IsoTrackHB_8E29"], &b_HLT_IsoTrackHB_8E29);
  fChain->SetBranchAddress("HLT_IsoTrackHE_8E29", &map_BitOfStandardHLTPath["HLT_IsoTrackHE_8E29"], &b_HLT_IsoTrackHE_8E29);
  fChain->SetBranchAddress("HLT_MinBiasPixel_DoubleIsoTrack5", &map_BitOfStandardHLTPath["HLT_MinBiasPixel_DoubleIsoTrack5"], &b_HLT_MinBiasPixel_DoubleIsoTrack5);
  fChain->SetBranchAddress("HLT_MinBiasPixel_DoubleTrack", &map_BitOfStandardHLTPath["HLT_MinBiasPixel_DoubleTrack"], &b_HLT_MinBiasPixel_DoubleTrack);
  fChain->SetBranchAddress("HLT_MinBiasPixel_SingleTrack", &map_BitOfStandardHLTPath["HLT_MinBiasPixel_SingleTrack"], &b_HLT_MinBiasPixel_SingleTrack);
  fChain->SetBranchAddress("HLT_TechTrigHCALNoise", &map_BitOfStandardHLTPath["HLT_TechTrigHCALNoise"], &b_HLT_TechTrigHCALNoise);
  fChain->SetBranchAddress("HLT_HcalNZS_8E29", &map_BitOfStandardHLTPath["HLT_HcalNZS_8E29"], &b_HLT_HcalNZS_8E29);
  fChain->SetBranchAddress("HLT_HcalNZS", &map_BitOfStandardHLTPath["HLT_HcalNZS"], &b_HLT_HcalNZS);
  fChain->SetBranchAddress("HLT_HcalPhiSym", &map_BitOfStandardHLTPath["HLT_HcalPhiSym"], &b_HLT_HcalPhiSym);

  
  // Add-ons for Circulation beam v2 (2009Nov18)
  fChain->SetBranchAddress("HLT_DTErrors", &HLT_DTErrors, &b_HLT_DTErrors);
  fChain->SetBranchAddress("HLT_HcalCalibration", &HLT_HcalCalibration, &b_HLT_HcalCalibration);
  fChain->SetBranchAddress("HLT_LogMonitor", &HLT_LogMonitor, &b_HLT_LogMonitor);
  fChain->SetBranchAddress("HLT_Activity_PixelClusters", &HLT_Activity_PixelClusters, &b_HLT_Activity_PixelClusters);
  fChain->SetBranchAddress("HLT_Activity_Ecal", &HLT_Activity_Ecal, &b_HLT_Activity_Ecal);
  fChain->SetBranchAddress("HLT_Activity_EcalREM", &HLT_Activity_EcalREM, &b_HLT_Activity_EcalREM);
  fChain->SetBranchAddress("HLT_L1SingleEG2_NoBPTX", &HLT_L1SingleEG2_NoBPTX, &b_HLT_L1SingleEG2_NoBPTX);
  fChain->SetBranchAddress("HLT_RPCBarrelCosmics", &HLT_RPCBarrelCosmics, &b_HLT_RPCBarrelCosmics);
  fChain->SetBranchAddress("HLT_L1_BPTX_MinusOnly", &HLT_L1_BPTX_MinusOnly, &b_HLT_L1_BPTX_MinusOnly);
  fChain->SetBranchAddress("HLT_L1_BPTX_PlusOnly", &HLT_L1_BPTX_PlusOnly, &b_HLT_L1_BPTX_PlusOnly);
  fChain->SetBranchAddress("HLT_Activity_L1A", &HLT_Activity_L1A, &b_HLT_Activity_L1A);
  fChain->SetBranchAddress("HLT_L1SingleForJet", &HLT_L1SingleForJet, &b_HLT_L1SingleForJet);
  fChain->SetBranchAddress("HLT_L1SingleEG2", &HLT_L1SingleEG2, &b_HLT_L1SingleEG2);
  fChain->SetBranchAddress("HLT_MinBias", &HLT_MinBias, &b_HLT_MinBias);
  fChain->SetBranchAddress("HLT_MinBiasBSC", &HLT_MinBiasBSC, &b_HLT_MinBiasBSC);
  fChain->SetBranchAddress("HLT_MinBiasBSC_OR", &HLT_MinBiasBSC_OR, &b_HLT_MinBiasBSC_OR);
  fChain->SetBranchAddress("HLT_HighMultiplicityBSC", &HLT_HighMultiplicityBSC, &b_HLT_HighMultiplicityBSC);
  fChain->SetBranchAddress("HLT_DTErrors", &map_BitOfStandardHLTPath["HLT_DTErrors"], &b_HLT_DTErrors);
  fChain->SetBranchAddress("HLT_HcalCalibration", &map_BitOfStandardHLTPath["HLT_HcalCalibration"], &b_HLT_HcalCalibration);
  fChain->SetBranchAddress("HLT_LogMonitor", &map_BitOfStandardHLTPath["HLT_LogMonitor"], &b_HLT_LogMonitor);
  fChain->SetBranchAddress("HLT_Activity_PixelClusters", &map_BitOfStandardHLTPath["HLT_Activity_PixelClusters"], &b_HLT_Activity_PixelClusters);
  fChain->SetBranchAddress("HLT_Activity_Ecal", &map_BitOfStandardHLTPath["HLT_Activity_Ecal"], &b_HLT_Activity_Ecal);
  fChain->SetBranchAddress("HLT_Activity_EcalREM", &map_BitOfStandardHLTPath["HLT_Activity_EcalREM"], &b_HLT_Activity_EcalREM);
  fChain->SetBranchAddress("HLT_L1SingleEG2_NoBPTX", &map_BitOfStandardHLTPath["HLT_L1SingleEG2_NoBPTX"], &b_HLT_L1SingleEG2_NoBPTX);
  fChain->SetBranchAddress("HLT_RPCBarrelCosmics", &map_BitOfStandardHLTPath["HLT_RPCBarrelCosmics"], &b_HLT_RPCBarrelCosmics);
  fChain->SetBranchAddress("HLT_L1_BPTX_MinusOnly", &map_BitOfStandardHLTPath["HLT_L1_BPTX_MinusOnly"], &b_HLT_L1_BPTX_MinusOnly);
  fChain->SetBranchAddress("HLT_L1_BPTX_PlusOnly", &map_BitOfStandardHLTPath["HLT_L1_BPTX_PlusOnly"], &b_HLT_L1_BPTX_PlusOnly);
  fChain->SetBranchAddress("HLT_Activity_L1A", &map_BitOfStandardHLTPath["HLT_Activity_L1A"], &b_HLT_Activity_L1A);
  fChain->SetBranchAddress("HLT_L1SingleForJet", &map_BitOfStandardHLTPath["HLT_L1SingleForJet"], &b_HLT_L1SingleForJet);
  fChain->SetBranchAddress("HLT_L1SingleEG2", &map_BitOfStandardHLTPath["HLT_L1SingleEG2"], &b_HLT_L1SingleEG2);
  fChain->SetBranchAddress("HLT_MinBias", &map_BitOfStandardHLTPath["HLT_MinBias"], &b_HLT_MinBias);
  fChain->SetBranchAddress("HLT_MinBiasBSC", &map_BitOfStandardHLTPath["HLT_MinBiasBSC"], &b_HLT_MinBiasBSC);
  fChain->SetBranchAddress("HLT_MinBiasBSC_OR", &map_BitOfStandardHLTPath["HLT_MinBiasBSC_OR"], &b_HLT_MinBiasBSC_OR);
  fChain->SetBranchAddress("HLT_HighMultiplicityBSC", &map_BitOfStandardHLTPath["HLT_HighMultiplicityBSC"], &b_HLT_HighMultiplicityBSC);

  // Splash Feb 2010
  fChain->SetBranchAddress("HLT_SplashEcalSumET", &map_BitOfStandardHLTPath["HLT_SplashEcalSumET"], &b_HLT_SplashEcalSumET);
  fChain->SetBranchAddress("HLT_L1SingleEG20", &map_BitOfStandardHLTPath["HLT_L1SingleEG20"], &b_HLT_L1SingleEG20);

  // Autogenerated from ConfDB - SetBranchAddressMaps
  fChain->SetBranchAddress("HLT_DiJetAve50U_8E29", &map_BitOfStandardHLTPath["HLT_DiJetAve50U_8E29"], &b_HLT_DiJetAve50U_8E29);
  fChain->SetBranchAddress("HLT_L1DoubleMuOpen_Tight", &map_BitOfStandardHLTPath["HLT_L1DoubleMuOpen_Tight"], &b_HLT_L1DoubleMuOpen_Tight);
  fChain->SetBranchAddress("HLT_Photon15_TrackIso_Cleaned_L1R", &map_BitOfStandardHLTPath["HLT_Photon15_TrackIso_Cleaned_L1R"], &b_HLT_Photon15_TrackIso_Cleaned_L1R);
  fChain->SetBranchAddress("HLT_Photon15_LooseEcalIso_Cleaned_L1R", &map_BitOfStandardHLTPath["HLT_Photon15_LooseEcalIso_Cleaned_L1R"], &b_HLT_Photon15_LooseEcalIso_Cleaned_L1R);
  fChain->SetBranchAddress("HLT_SingleLooseIsoTau20_Trk5", &map_BitOfStandardHLTPath["HLT_SingleLooseIsoTau20_Trk5"], &b_HLT_SingleLooseIsoTau20_Trk5);
  fChain->SetBranchAddress("HLT_SingleLooseIsoTau25", &map_BitOfStandardHLTPath["HLT_SingleLooseIsoTau25"], &b_HLT_SingleLooseIsoTau25);
  fChain->SetBranchAddress("HLT_MultiVertex6", &map_BitOfStandardHLTPath["HLT_MultiVertex6"], &b_HLT_MultiVertex6);
  fChain->SetBranchAddress("HLT_MultiVertex8_L1ETT60", &map_BitOfStandardHLTPath["HLT_MultiVertex8_L1ETT60"], &b_HLT_MultiVertex8_L1ETT60);
  fChain->SetBranchAddress("HLT_PixelTracks_Multiplicity85", &map_BitOfStandardHLTPath["HLT_PixelTracks_Multiplicity85"], &b_HLT_PixelTracks_Multiplicity85);
  fChain->SetBranchAddress("HLT_L1Tech_BSC_minBias", &map_BitOfStandardHLTPath["HLT_L1Tech_BSC_minBias"], &b_HLT_L1Tech_BSC_minBias);
  fChain->SetBranchAddress("HLT_Activity_CSC", &map_BitOfStandardHLTPath["HLT_Activity_CSC"], &b_HLT_Activity_CSC);
  fChain->SetBranchAddress("HLT_Activity_Ecal_SC7", &map_BitOfStandardHLTPath["HLT_Activity_Ecal_SC7"], &b_HLT_Activity_Ecal_SC7);
  fChain->SetBranchAddress("HLT_Activity_Ecal_SC15", &map_BitOfStandardHLTPath["HLT_Activity_Ecal_SC15"], &b_HLT_Activity_Ecal_SC15);
  fChain->SetBranchAddress("HLT_L1MuOpen_DT", &map_BitOfStandardHLTPath["HLT_L1MuOpen_DT"], &b_HLT_L1MuOpen_DT);
  fChain->SetBranchAddress("HLT_Photon10_Cleaned_L1R", &map_BitOfStandardHLTPath["HLT_Photon10_Cleaned_L1R"], &b_HLT_Photon10_Cleaned_L1R);
  fChain->SetBranchAddress("HLT_Photon15_Cleaned_L1R", &map_BitOfStandardHLTPath["HLT_Photon15_Cleaned_L1R"], &b_HLT_Photon15_Cleaned_L1R);
  fChain->SetBranchAddress("HLT_Photon20_Cleaned_L1R", &map_BitOfStandardHLTPath["HLT_Photon20_Cleaned_L1R"], &b_HLT_Photon20_Cleaned_L1R);
  fChain->SetBranchAddress("HLT_L1Tech_BSC_HighMultiplicity", &map_BitOfStandardHLTPath["HLT_L1Tech_BSC_HighMultiplicity"], &b_HLT_L1Tech_BSC_HighMultiplicity);
  fChain->SetBranchAddress("HLT_PixelTracks_Multiplicity40", &map_BitOfStandardHLTPath["HLT_PixelTracks_Multiplicity40"], &b_HLT_PixelTracks_Multiplicity40);
  fChain->SetBranchAddress("HLT_L1SingleForJet_BPTX", &map_BitOfStandardHLTPath["HLT_L1SingleForJet_BPTX"], &b_HLT_L1SingleForJet_BPTX);
  fChain->SetBranchAddress("HLT_L1Jet6U_BPTX", &map_BitOfStandardHLTPath["HLT_L1Jet6U_BPTX"], &b_HLT_L1Jet6U_BPTX);
  fChain->SetBranchAddress("HLT_L1Jet10U_BPTX", &map_BitOfStandardHLTPath["HLT_L1Jet10U_BPTX"], &b_HLT_L1Jet10U_BPTX);
  fChain->SetBranchAddress("HLT_L1MuOpen_BPTX", &map_BitOfStandardHLTPath["HLT_L1MuOpen_BPTX"], &b_HLT_L1MuOpen_BPTX);
  fChain->SetBranchAddress("HLT_L1_BptxXOR_BscMinBiasOR", &map_BitOfStandardHLTPath["HLT_L1_BptxXOR_BscMinBiasOR"], &b_HLT_L1_BptxXOR_BscMinBiasOR);
  fChain->SetBranchAddress("HLT_L1SingleCenJet_BPTX", &map_BitOfStandardHLTPath["HLT_L1SingleCenJet_BPTX"], &b_HLT_L1SingleCenJet_BPTX);
  fChain->SetBranchAddress("HLT_MinBiasBSC_BPTX", &map_BitOfStandardHLTPath["HLT_MinBiasBSC_BPTX"], &b_HLT_MinBiasBSC_BPTX);
  fChain->SetBranchAddress("HLT_L1Tech_HCAL_HF", &map_BitOfStandardHLTPath["HLT_L1Tech_HCAL_HF"], &b_HLT_L1Tech_HCAL_HF);
  fChain->SetBranchAddress("HLT_L1SingleTauJet_BPTX", &map_BitOfStandardHLTPath["HLT_L1SingleTauJet_BPTX"], &b_HLT_L1SingleTauJet_BPTX);
  fChain->SetBranchAddress("HLT_PixelTracks_Multiplicity70", &map_BitOfStandardHLTPath["HLT_PixelTracks_Multiplicity70"], &b_HLT_PixelTracks_Multiplicity70);
  fChain->SetBranchAddress("HLT_Jet15U_HcalNoiseFiltered", &map_BitOfStandardHLTPath["HLT_Jet15U_HcalNoiseFiltered"], &b_HLT_Jet15U_HcalNoiseFiltered);
  fChain->SetBranchAddress("HLT_L2Mu5", &map_BitOfStandardHLTPath["HLT_L2Mu5"], &b_HLT_L2Mu5);
  fChain->SetBranchAddress("HLT_L1_BscMinBiasOR_BeamGas", &map_BitOfStandardHLTPath["HLT_L1_BscMinBiasOR_BeamGas"], &b_HLT_L1_BscMinBiasOR_BeamGas);
  fChain->SetBranchAddress("HLT_L1Tech_BSC_halo", &map_BitOfStandardHLTPath["HLT_L1Tech_BSC_halo"], &b_HLT_L1Tech_BSC_halo);
  fChain->SetBranchAddress("HLT_L1Tech_BSC_halo_forPhysicsBackground", &map_BitOfStandardHLTPath["HLT_L1Tech_BSC_halo_forPhysicsBackground"], &b_HLT_L1Tech_BSC_halo_forPhysicsBackground);
  fChain->SetBranchAddress("HLT_HFThreshold3", &map_BitOfStandardHLTPath["HLT_HFThreshold3"], &b_HLT_HFThreshold3);
  fChain->SetBranchAddress("HLT_HFThreshold10", &map_BitOfStandardHLTPath["HLT_HFThreshold10"], &b_HLT_HFThreshold10);
  fChain->SetBranchAddress("HLT_Activity_DT", &map_BitOfStandardHLTPath["HLT_Activity_DT"], &b_HLT_Activity_DT);
  fChain->SetBranchAddress("HLT_Activity_DT_Tuned", &map_BitOfStandardHLTPath["HLT_Activity_DT_Tuned"], &b_HLT_Activity_DT_Tuned);
  fChain->SetBranchAddress("HLT_Activity_HF3", &map_BitOfStandardHLTPath["HLT_Activity_HF3"], &b_HLT_Activity_HF3);
  fChain->SetBranchAddress("HLT_Activity_HF10", &map_BitOfStandardHLTPath["HLT_Activity_HF10"], &b_HLT_Activity_HF10);
  fChain->SetBranchAddress("HLT_MultiTowerEcal", &map_BitOfStandardHLTPath["HLT_MultiTowerEcal"], &b_HLT_MultiTowerEcal);
  fChain->SetBranchAddress("HLT_SelectEcalSpikes_L1R", &map_BitOfStandardHLTPath["HLT_SelectEcalSpikes_L1R"], &b_HLT_SelectEcalSpikes_L1R);
  fChain->SetBranchAddress("HLT_SelectEcalSpikesHighEt_L1R", &map_BitOfStandardHLTPath["HLT_SelectEcalSpikesHighEt_L1R"], &b_HLT_SelectEcalSpikesHighEt_L1R);
  fChain->SetBranchAddress("HLT_L1Jet6U_NoBPTX", &map_BitOfStandardHLTPath["HLT_L1Jet6U_NoBPTX"], &b_HLT_L1Jet6U_NoBPTX);
  fChain->SetBranchAddress("HLT_L1Jet10U", &map_BitOfStandardHLTPath["HLT_L1Jet10U"], &b_HLT_L1Jet10U);
  fChain->SetBranchAddress("HLT_L1Jet10U_NoBPTX", &map_BitOfStandardHLTPath["HLT_L1Jet10U_NoBPTX"], &b_HLT_L1Jet10U_NoBPTX);
  fChain->SetBranchAddress("HLT_L1SingleForJet_NoBPTX", &map_BitOfStandardHLTPath["HLT_L1SingleForJet_NoBPTX"], &b_HLT_L1SingleForJet_NoBPTX);
  fChain->SetBranchAddress("HLT_L1SingleCenJet", &map_BitOfStandardHLTPath["HLT_L1SingleCenJet"], &b_HLT_L1SingleCenJet);
  fChain->SetBranchAddress("HLT_L1SingleCenJet_NoBPTX", &map_BitOfStandardHLTPath["HLT_L1SingleCenJet_NoBPTX"], &b_HLT_L1SingleCenJet_NoBPTX);
  fChain->SetBranchAddress("HLT_L1SingleTauJet", &map_BitOfStandardHLTPath["HLT_L1SingleTauJet"], &b_HLT_L1SingleTauJet);
  fChain->SetBranchAddress("HLT_L1SingleTauJet_NoBPTX", &map_BitOfStandardHLTPath["HLT_L1SingleTauJet_NoBPTX"], &b_HLT_L1SingleTauJet_NoBPTX);
  fChain->SetBranchAddress("HLT_DoubleFwdJet50", &map_BitOfStandardHLTPath["HLT_DoubleFwdJet50"], &b_HLT_DoubleFwdJet50);
  fChain->SetBranchAddress("HLT_QuadJet60", &map_BitOfStandardHLTPath["HLT_QuadJet60"], &b_HLT_QuadJet60);
  fChain->SetBranchAddress("HLT_L1MuOpen_NoBPTX", &map_BitOfStandardHLTPath["HLT_L1MuOpen_NoBPTX"], &b_HLT_L1MuOpen_NoBPTX);
  fChain->SetBranchAddress("HLT_L1MuOpen_AntiBPTX", &map_BitOfStandardHLTPath["HLT_L1MuOpen_AntiBPTX"], &b_HLT_L1MuOpen_AntiBPTX);
  fChain->SetBranchAddress("HLT_L1SingleEG1", &map_BitOfStandardHLTPath["HLT_L1SingleEG1"], &b_HLT_L1SingleEG1);
  fChain->SetBranchAddress("HLT_L1SingleEG1_NoBPTX", &map_BitOfStandardHLTPath["HLT_L1SingleEG1_NoBPTX"], &b_HLT_L1SingleEG1_NoBPTX);
  fChain->SetBranchAddress("HLT_L1SingleEG5_NoBPTX", &map_BitOfStandardHLTPath["HLT_L1SingleEG5_NoBPTX"], &b_HLT_L1SingleEG5_NoBPTX);
  fChain->SetBranchAddress("HLT_L1SingleEG20_NoBPTX", &map_BitOfStandardHLTPath["HLT_L1SingleEG20_NoBPTX"], &b_HLT_L1SingleEG20_NoBPTX);
  fChain->SetBranchAddress("HLT_Ele20_SW_EleId_LooseTrackIso_L1R", &map_BitOfStandardHLTPath["HLT_Ele20_SW_EleId_LooseTrackIso_L1R"], &b_HLT_Ele20_SW_EleId_LooseTrackIso_L1R);
  fChain->SetBranchAddress("HLT_Ele25_LW_L1R", &map_BitOfStandardHLTPath["HLT_Ele25_LW_L1R"], &b_HLT_Ele25_LW_L1R);
  fChain->SetBranchAddress("HLT_DoublePhoton4_eeRes_L1R", &map_BitOfStandardHLTPath["HLT_DoublePhoton4_eeRes_L1R"], &b_HLT_DoublePhoton4_eeRes_L1R);
  fChain->SetBranchAddress("HLT_DoublePhoton4_Jpsi_L1R", &map_BitOfStandardHLTPath["HLT_DoublePhoton4_Jpsi_L1R"], &b_HLT_DoublePhoton4_Jpsi_L1R);
  fChain->SetBranchAddress("HLT_DoublePhoton4_Upsilon_L1R", &map_BitOfStandardHLTPath["HLT_DoublePhoton4_Upsilon_L1R"], &b_HLT_DoublePhoton4_Upsilon_L1R);
  fChain->SetBranchAddress("HLT_DoublePhoton5_L1R", &map_BitOfStandardHLTPath["HLT_DoublePhoton5_L1R"], &b_HLT_DoublePhoton5_L1R);
  fChain->SetBranchAddress("HLT_L1Mu14_L1SingleJet20", &map_BitOfStandardHLTPath["HLT_L1Mu14_L1SingleJet20"], &b_HLT_L1Mu14_L1SingleJet20);
  fChain->SetBranchAddress("HLT_MinBiasBSC_NoBPTX", &map_BitOfStandardHLTPath["HLT_MinBiasBSC_NoBPTX"], &b_HLT_MinBiasBSC_NoBPTX);
  fChain->SetBranchAddress("HLT_SplashBSC", &map_BitOfStandardHLTPath["HLT_SplashBSC"], &b_HLT_SplashBSC);
  fChain->SetBranchAddress("HLT_L1_BscMinBiasOR_BptxPlusORMinus", &map_BitOfStandardHLTPath["HLT_L1_BscMinBiasOR_BptxPlusORMinus"], &b_HLT_L1_BscMinBiasOR_BptxPlusORMinus);
  fChain->SetBranchAddress("HLT_L1_BscMinBiasOR_BptxPlusORMinus_NoBPTX", &map_BitOfStandardHLTPath["HLT_L1_BscMinBiasOR_BptxPlusORMinus_NoBPTX"], &b_HLT_L1_BscMinBiasOR_BptxPlusORMinus_NoBPTX);
  fChain->SetBranchAddress("HLT_L1Tech_RPC_TTU_RBst1_collisions", &map_BitOfStandardHLTPath["HLT_L1Tech_RPC_TTU_RBst1_collisions"], &b_HLT_L1Tech_RPC_TTU_RBst1_collisions);
  fChain->SetBranchAddress("HLT_IsoTrackHE_1E31", &map_BitOfStandardHLTPath["HLT_IsoTrackHE_1E31"], &b_HLT_IsoTrackHE_1E31);
  fChain->SetBranchAddress("HLT_IsoTrackHB_1E31", &map_BitOfStandardHLTPath["HLT_IsoTrackHB_1E31"], &b_HLT_IsoTrackHB_1E31);
  fChain->SetBranchAddress("HLT_HcalNZS_1E31", &map_BitOfStandardHLTPath["HLT_HcalNZS_1E31"], &b_HLT_HcalNZS_1E31);
  fChain->SetBranchAddress("HLT_HIMinBiasCalo", &map_BitOfStandardHLTPath["HLT_HIMinBiasCalo"], &b_HLT_HIMinBiasCalo);
  fChain->SetBranchAddress("HLT_HIJet35U", &map_BitOfStandardHLTPath["HLT_HIJet35U"], &b_HLT_HIJet35U);
  fChain->SetBranchAddress("HLT_HIJet50U", &map_BitOfStandardHLTPath["HLT_HIJet50U"], &b_HLT_HIJet50U);
  fChain->SetBranchAddress("HLT_HIJet75U", &map_BitOfStandardHLTPath["HLT_HIJet75U"], &b_HLT_HIJet75U);
  fChain->SetBranchAddress("HLT_HIJet90U", &map_BitOfStandardHLTPath["HLT_HIJet90U"], &b_HLT_HIJet90U);
  fChain->SetBranchAddress("HLT_HIPhoton10", &map_BitOfStandardHLTPath["HLT_HIPhoton10"], &b_HLT_HIPhoton10);
  fChain->SetBranchAddress("HLT_HIPhoton15", &map_BitOfStandardHLTPath["HLT_HIPhoton15"], &b_HLT_HIPhoton15);
  fChain->SetBranchAddress("HLT_HIPhoton20", &map_BitOfStandardHLTPath["HLT_HIPhoton20"], &b_HLT_HIPhoton20);
  fChain->SetBranchAddress("HLT_HIPhoton30", &map_BitOfStandardHLTPath["HLT_HIPhoton30"], &b_HLT_HIPhoton30);
  fChain->SetBranchAddress("HLT_HighMult40", &map_BitOfStandardHLTPath["HLT_HighMult40"], &b_HLT_HighMult40);
  fChain->SetBranchAddress("HLT_L1Tech_HCAL_HF_coincidence_PM", &map_BitOfStandardHLTPath["HLT_L1Tech_HCAL_HF_coincidence_PM"], &b_HLT_L1Tech_HCAL_HF_coincidence_PM);
  fChain->SetBranchAddress("HLT_PhysicsDeclared", &map_BitOfStandardHLTPath["HLT_PhysicsDeclared"], &b_HLT_PhysicsDeclared);
  fChain->SetBranchAddress("HLT_Jet250", &map_BitOfStandardHLTPath["HLT_Jet250"], &b_HLT_Jet250);
  fChain->SetBranchAddress("HLT_DoubleJet15U_ForwardBackward", &map_BitOfStandardHLTPath["HLT_DoubleJet15U_ForwardBackward"], &b_HLT_DoubleJet15U_ForwardBackward);
  fChain->SetBranchAddress("HLT_DoubleJet150", &map_BitOfStandardHLTPath["HLT_DoubleJet150"], &b_HLT_DoubleJet150);
  fChain->SetBranchAddress("HLT_DoubleJet125_Aco", &map_BitOfStandardHLTPath["HLT_DoubleJet125_Aco"], &b_HLT_DoubleJet125_Aco);
  fChain->SetBranchAddress("HLT_TripleJet85", &map_BitOfStandardHLTPath["HLT_TripleJet85"], &b_HLT_TripleJet85);
  fChain->SetBranchAddress("HLT_MET25", &map_BitOfStandardHLTPath["HLT_MET25"], &b_HLT_MET25);
  fChain->SetBranchAddress("HLT_MET50", &map_BitOfStandardHLTPath["HLT_MET50"], &b_HLT_MET50);
  fChain->SetBranchAddress("HLT_MET75", &map_BitOfStandardHLTPath["HLT_MET75"], &b_HLT_MET75);
  fChain->SetBranchAddress("HLT_MET60_HT350", &map_BitOfStandardHLTPath["HLT_MET60_HT350"], &b_HLT_MET60_HT350);
  fChain->SetBranchAddress("HLT_HT240", &map_BitOfStandardHLTPath["HLT_HT240"], &b_HLT_HT240);
  fChain->SetBranchAddress("HLT_Jet180_MET60", &map_BitOfStandardHLTPath["HLT_Jet180_MET60"], &b_HLT_Jet180_MET60);
  fChain->SetBranchAddress("HLT_Jet60_MET70_Aco", &map_BitOfStandardHLTPath["HLT_Jet60_MET70_Aco"], &b_HLT_Jet60_MET70_Aco);
  fChain->SetBranchAddress("HLT_Jet100_MET60_Aco", &map_BitOfStandardHLTPath["HLT_Jet100_MET60_Aco"], &b_HLT_Jet100_MET60_Aco);
  fChain->SetBranchAddress("HLT_DoubleJet125_MET60", &map_BitOfStandardHLTPath["HLT_DoubleJet125_MET60"], &b_HLT_DoubleJet125_MET60);
  fChain->SetBranchAddress("HLT_DoubleFwdJet40_MET60", &map_BitOfStandardHLTPath["HLT_DoubleFwdJet40_MET60"], &b_HLT_DoubleFwdJet40_MET60);
  fChain->SetBranchAddress("HLT_DoubleJet60_MET60_Aco", &map_BitOfStandardHLTPath["HLT_DoubleJet60_MET60_Aco"], &b_HLT_DoubleJet60_MET60_Aco);
  fChain->SetBranchAddress("HLT_DoubleJet50_MET70_Aco", &map_BitOfStandardHLTPath["HLT_DoubleJet50_MET70_Aco"], &b_HLT_DoubleJet50_MET70_Aco);
  fChain->SetBranchAddress("HLT_DoubleJet40_MET70_Aco", &map_BitOfStandardHLTPath["HLT_DoubleJet40_MET70_Aco"], &b_HLT_DoubleJet40_MET70_Aco);
  fChain->SetBranchAddress("HLT_TripleJet60_MET60", &map_BitOfStandardHLTPath["HLT_TripleJet60_MET60"], &b_HLT_TripleJet60_MET60);
  fChain->SetBranchAddress("HLT_QuadJet35_MET60", &map_BitOfStandardHLTPath["HLT_QuadJet35_MET60"], &b_HLT_QuadJet35_MET60);
  fChain->SetBranchAddress("HLT_L2Mu0", &map_BitOfStandardHLTPath["HLT_L2Mu0"], &b_HLT_L2Mu0);
  fChain->SetBranchAddress("HLT_L2Mu3", &map_BitOfStandardHLTPath["HLT_L2Mu3"], &b_HLT_L2Mu3);
  fChain->SetBranchAddress("HLT_L2Mu15", &map_BitOfStandardHLTPath["HLT_L2Mu15"], &b_HLT_L2Mu15);
  fChain->SetBranchAddress("HLT_L2DoubleMu0", &map_BitOfStandardHLTPath["HLT_L2DoubleMu0"], &b_HLT_L2DoubleMu0);
  fChain->SetBranchAddress("HLT_IsoMu11", &map_BitOfStandardHLTPath["HLT_IsoMu11"], &b_HLT_IsoMu11);
  fChain->SetBranchAddress("HLT_IsoMu13", &map_BitOfStandardHLTPath["HLT_IsoMu13"], &b_HLT_IsoMu13);
  fChain->SetBranchAddress("HLT_IsoMu15", &map_BitOfStandardHLTPath["HLT_IsoMu15"], &b_HLT_IsoMu15);
  fChain->SetBranchAddress("HLT_Mu7", &map_BitOfStandardHLTPath["HLT_Mu7"], &b_HLT_Mu7);
  fChain->SetBranchAddress("HLT_Mu13", &map_BitOfStandardHLTPath["HLT_Mu13"], &b_HLT_Mu13);
  fChain->SetBranchAddress("HLT_DoubleIsoMu3", &map_BitOfStandardHLTPath["HLT_DoubleIsoMu3"], &b_HLT_DoubleIsoMu3);
  fChain->SetBranchAddress("HLT_DoubleMu3_Vtx2mm", &map_BitOfStandardHLTPath["HLT_DoubleMu3_Vtx2mm"], &b_HLT_DoubleMu3_Vtx2mm);
  fChain->SetBranchAddress("HLT_DoubleMu3_JPsi", &map_BitOfStandardHLTPath["HLT_DoubleMu3_JPsi"], &b_HLT_DoubleMu3_JPsi);
  fChain->SetBranchAddress("HLT_DoubleMu3_Upsilon", &map_BitOfStandardHLTPath["HLT_DoubleMu3_Upsilon"], &b_HLT_DoubleMu3_Upsilon);
  fChain->SetBranchAddress("HLT_DoubleMu7_Z", &map_BitOfStandardHLTPath["HLT_DoubleMu7_Z"], &b_HLT_DoubleMu7_Z);
  fChain->SetBranchAddress("HLT_DoubleMu3_SameSign", &map_BitOfStandardHLTPath["HLT_DoubleMu3_SameSign"], &b_HLT_DoubleMu3_SameSign);
  fChain->SetBranchAddress("HLT_DoubleMu3_Psi2S", &map_BitOfStandardHLTPath["HLT_DoubleMu3_Psi2S"], &b_HLT_DoubleMu3_Psi2S);
  fChain->SetBranchAddress("HLT_Mu0_L1MuOpen", &map_BitOfStandardHLTPath["HLT_Mu0_L1MuOpen"], &b_HLT_Mu0_L1MuOpen);
  fChain->SetBranchAddress("HLT_Mu3_L1MuOpen", &map_BitOfStandardHLTPath["HLT_Mu3_L1MuOpen"], &b_HLT_Mu3_L1MuOpen);
  fChain->SetBranchAddress("HLT_Mu5_L1MuOpen", &map_BitOfStandardHLTPath["HLT_Mu5_L1MuOpen"], &b_HLT_Mu5_L1MuOpen);
  fChain->SetBranchAddress("HLT_Mu0_L2Mu0", &map_BitOfStandardHLTPath["HLT_Mu0_L2Mu0"], &b_HLT_Mu0_L2Mu0);
  fChain->SetBranchAddress("HLT_Mu3_L2Mu0", &map_BitOfStandardHLTPath["HLT_Mu3_L2Mu0"], &b_HLT_Mu3_L2Mu0);
  fChain->SetBranchAddress("HLT_Mu5_L2Mu0", &map_BitOfStandardHLTPath["HLT_Mu5_L2Mu0"], &b_HLT_Mu5_L2Mu0);
  fChain->SetBranchAddress("HLT_Mu0_Track0_Jpsi", &map_BitOfStandardHLTPath["HLT_Mu0_Track0_Jpsi"], &b_HLT_Mu0_Track0_Jpsi);
  fChain->SetBranchAddress("HLT_Mu3_Track0_Jpsi", &map_BitOfStandardHLTPath["HLT_Mu3_Track0_Jpsi"], &b_HLT_Mu3_Track0_Jpsi);
  fChain->SetBranchAddress("HLT_Mu5_Track0_Jpsi", &map_BitOfStandardHLTPath["HLT_Mu5_Track0_Jpsi"], &b_HLT_Mu5_Track0_Jpsi);
  fChain->SetBranchAddress("HLT_IsoMu7_BTagIP_Jet35", &map_BitOfStandardHLTPath["HLT_IsoMu7_BTagIP_Jet35"], &b_HLT_IsoMu7_BTagIP_Jet35);
  fChain->SetBranchAddress("HLT_IsoMu7_BTagMu_Jet20", &map_BitOfStandardHLTPath["HLT_IsoMu7_BTagMu_Jet20"], &b_HLT_IsoMu7_BTagMu_Jet20);
  fChain->SetBranchAddress("HLT_IsoMu7_Jet40", &map_BitOfStandardHLTPath["HLT_IsoMu7_Jet40"], &b_HLT_IsoMu7_Jet40);
  fChain->SetBranchAddress("HLT_IsoMu14_IsoTau15_Trk3", &map_BitOfStandardHLTPath["HLT_IsoMu14_IsoTau15_Trk3"], &b_HLT_IsoMu14_IsoTau15_Trk3);
  fChain->SetBranchAddress("HLT_IsoMu14_IsoTau15_Trk3_NoL1", &map_BitOfStandardHLTPath["HLT_IsoMu14_IsoTau15_Trk3_NoL1"], &b_HLT_IsoMu14_IsoTau15_Trk3_NoL1);
  fChain->SetBranchAddress("HLT_IsoMu14_LooseIsoTau15_NoL25", &map_BitOfStandardHLTPath["HLT_IsoMu14_LooseIsoTau15_NoL25"], &b_HLT_IsoMu14_LooseIsoTau15_NoL25);
  fChain->SetBranchAddress("HLT_IsoMu14_LooseIsoTau15_Trk3_NoL2", &map_BitOfStandardHLTPath["HLT_IsoMu14_LooseIsoTau15_Trk3_NoL2"], &b_HLT_IsoMu14_LooseIsoTau15_Trk3_NoL2);
  fChain->SetBranchAddress("HLT_NoL2IsoMu8_Jet40", &map_BitOfStandardHLTPath["HLT_NoL2IsoMu8_Jet40"], &b_HLT_NoL2IsoMu8_Jet40);
  fChain->SetBranchAddress("HLT_Mu14_Jet50", &map_BitOfStandardHLTPath["HLT_Mu14_Jet50"], &b_HLT_Mu14_Jet50);
  fChain->SetBranchAddress("HLT_Mu5_TripleJet30", &map_BitOfStandardHLTPath["HLT_Mu5_TripleJet30"], &b_HLT_Mu5_TripleJet30);
  fChain->SetBranchAddress("HLT_L2Mu7_Photon9_L1R", &map_BitOfStandardHLTPath["HLT_L2Mu7_Photon9_L1R"], &b_HLT_L2Mu7_Photon9_L1R);
  fChain->SetBranchAddress("HLT_Ele10_LW_L1R_HT200", &map_BitOfStandardHLTPath["HLT_Ele10_LW_L1R_HT200"], &b_HLT_Ele10_LW_L1R_HT200);
  fChain->SetBranchAddress("AlCa_RPCMuonNoTriggers", &map_BitOfStandardHLTPath["AlCa_RPCMuonNoTriggers"], &b_AlCa_RPCMuonNoTriggers);
  fChain->SetBranchAddress("HLT_HIDoubleMu", &map_BitOfStandardHLTPath["HLT_HIDoubleMu"], &b_HLT_HIDoubleMu);
  fChain->SetBranchAddress("HLT_DoublePhoton5_CEP_L1R", &map_BitOfStandardHLTPath["HLT_DoublePhoton5_CEP_L1R"], &b_HLT_DoublePhoton5_CEP_L1R);
  fChain->SetBranchAddress("HLT_ZeroBias1kHz", &map_BitOfStandardHLTPath["HLT_ZeroBias1kHz"], &b_HLT_ZeroBias1kHz);
  
  Notify();
}

void OHltTree::SetMapL1SeedsOfStandardHLTPath(OHltMenu *menu) {
  map_L1SeedsOfStandardHLTPath = menu->GetL1SeedsOfHLTPathMap();
}

void OHltTree::ApplyL1Prescales(OHltMenu *menu, OHltConfig *cfg, OHltRateCounter *rc)
{
  TString st;
  unsigned int tt = menu->GetL1TriggerSize();
  for (unsigned int i=0;i<tt;i++) {
    st = menu->GetL1TriggerName(i);
    if (map_BitOfStandardHLTPath.find(st)->second == 1) {
      if (!prescaleResponseL1(menu,cfg,rc,i)) {
	map_BitOfStandardHLTPath[st] = 0;	
      } 
    }
  }
}

void OHltTree::SetMapL1BitOfStandardHLTPath(OHltMenu *menu) {
  int tt = 0;
  TString st;
  unsigned ts = menu->GetTriggerSize();
  for (unsigned int i=0;i<ts;i++) {
    st = menu->GetTriggerName(i);
    std::map< TString, std::vector<TString> >::const_iterator it = map_L1SeedsOfStandardHLTPath.find(st);
    if (it != map_L1SeedsOfStandardHLTPath.end()) {
      tt = 0;
      unsigned ts2 = it->second.size();
      for (unsigned int j=0;j<ts2;j++) {
 	tt += (map_BitOfStandardHLTPath.find((map_L1SeedsOfStandardHLTPath.find(st)->second)[j]))->second;
      }
    }
    map_L1BitOfStandardHLTPath[st] = tt;
  }
}

void OHltTree::RemoveEGOverlaps()
{
  //remove duplicated SC
  for(int i=0;i<NohEle ;i++){
    if (ohEleL1iso[i] == 1){ohEleL1Dupl[i]=false;}
    else{
      float  dist = 1000;
      for(int j=0;j<NohEle ;j++){
	if(ohEleL1iso[j]==1){
	  float distTemp = fabs(ohEleEta[i]-ohEleEta[j])+fabs(ohEleE[i]-ohEleE[j]);
	  if(distTemp < dist){dist=distTemp;}
	}
      }//loop over j
      if (dist < 0.01){ohEleL1Dupl[i]=true;}
      else {ohEleL1Dupl[i]=false;}
    }
  }

  for(int i=0;i<NohEleLW ;i++){
    if (ohEleL1isoLW[i] == 1){ohEleLWL1Dupl[i]=false;}
    else{
      float  dist = 1000;
      for(int j=0;j<NohEleLW ;j++){
	if(ohEleL1isoLW[j]==1){
	  float distTemp = fabs(ohEleEtaLW[i]-ohEleEtaLW[j])+fabs(ohEleELW[i]-ohEleELW[j]);
	  if(distTemp < dist){dist=distTemp;}
	}
      }//loop over j
      if (dist < 0.01){ohEleLWL1Dupl[i]=true;}
      else {ohEleLWL1Dupl[i]=false;}
    }
  }

  for(int i=0;i<NohPhot ;i++){ 
    if (ohPhotL1iso[i] == 1){ohPhotL1Dupl[i]=false;} 
    else{ 
      float  dist = 1000; 
      for(int j=0;j<NohPhot ;j++){ 
        if(ohPhotL1iso[j]==1){ 
          float distTemp = fabs(ohPhotEta[i]-ohPhotEta[j])+fabs(ohPhotEt[i]-ohPhotEt[j]); 
          if(distTemp < dist){dist=distTemp;} 
        } 
      }//loop over j 
      if (dist < 0.01){ohPhotL1Dupl[i]=true;} 
      else {ohPhotL1Dupl[i]=false;} 
    } 
  } 

}

void OHltTree::SetL1MuonQuality()
{
  // Cut on muon quality
  // init
  NL1OpenMu = 0;
  for (int i=0;i<10;i++) {
    L1OpenMuPt[i] = -999.;
    L1OpenMuE[i] = -999.;
    L1OpenMuEta[i] = -999.;
    L1OpenMuPhi[i] = -999.;
    L1OpenMuIsol[i] = -999;
    L1OpenMuMip[i] = -999;
    L1OpenMuFor[i] = -999;
    L1OpenMuRPC[i] = -999;
    L1OpenMuQal[i] = -999;     
  }
  for (int i=0;i<NL1Mu;i++) {
    if ( L1MuQal[i]==2 || L1MuQal[i]==3 || L1MuQal[i]==4 ||
	 L1MuQal[i]==5 || L1MuQal[i]==6 || L1MuQal[i]==7 ) {
      L1OpenMuPt[NL1OpenMu] = L1MuPt[i];
      L1OpenMuE[NL1OpenMu] = L1MuE[i];
      L1OpenMuEta[NL1OpenMu] = L1MuEta[i];
      L1OpenMuPhi[NL1OpenMu] = L1MuPhi[i];
      L1OpenMuIsol[NL1OpenMu] = L1MuIsol[i];
      L1OpenMuMip[NL1OpenMu] = L1MuMip[i];
      L1OpenMuFor[NL1OpenMu] = L1MuFor[i];
      L1OpenMuRPC[NL1OpenMu] = L1MuRPC[i];
      L1OpenMuQal[NL1OpenMu] = L1MuQal[i];
      NL1OpenMu++;
    }
  }
  // init
  NL1GoodSingleMu = 0;
  for (int i=0;i<10;i++) {
    L1GoodSingleMuPt[i] = -999.;
    L1GoodSingleMuE[i] = -999.;
    L1GoodSingleMuEta[i] = -999.;
    L1GoodSingleMuPhi[i] = -999.;
    L1GoodSingleMuIsol[i] = -999;
    L1GoodSingleMuMip[i] = -999;
    L1GoodSingleMuFor[i] = -999;
    L1GoodSingleMuRPC[i] = -999;
    L1GoodSingleMuQal[i] = -999;     
  }
  // Cut on muon quality      
  for (int i=0;i<NL1Mu;i++) {
    if ( L1MuQal[i]==4 || L1MuQal[i]==5 || L1MuQal[i]==6 || L1MuQal[i]==7 ) {
      L1GoodSingleMuPt[NL1GoodSingleMu] = L1MuPt[i];
      L1GoodSingleMuE[NL1GoodSingleMu] = L1MuE[i];
      L1GoodSingleMuEta[NL1GoodSingleMu] = L1MuEta[i];
      L1GoodSingleMuPhi[NL1GoodSingleMu] = L1MuPhi[i];
      L1GoodSingleMuIsol[NL1GoodSingleMu] = L1MuIsol[i];
      L1GoodSingleMuMip[NL1GoodSingleMu] = L1MuMip[i];
      L1GoodSingleMuFor[NL1GoodSingleMu] = L1MuFor[i];
      L1GoodSingleMuRPC[NL1GoodSingleMu] = L1MuRPC[i];
      L1GoodSingleMuQal[NL1GoodSingleMu] = L1MuQal[i];
      NL1GoodSingleMu++;
    }
  }

  // init
  NL1GoodDoubleMu = 0;
  for (int i=0;i<10;i++) {
    L1GoodDoubleMuPt[i] = -999.;
    L1GoodDoubleMuE[i] = -999.;
    L1GoodDoubleMuEta[i] = -999.;
    L1GoodDoubleMuPhi[i] = -999.;
    L1GoodDoubleMuIsol[i] = -999;
    L1GoodDoubleMuMip[i] = -999;
    L1GoodDoubleMuFor[i] = -999;
    L1GoodDoubleMuRPC[i] = -999;
    L1GoodDoubleMuQal[i] = -999;     
  }
  // Cut on muon quality
  for (int i=0;i<NL1Mu;i++) {
    if ( L1MuQal[i]==3 || L1MuQal[i]==5 || L1MuQal[i]==6 || L1MuQal[i]==7 ) {
      L1GoodDoubleMuPt[NL1GoodDoubleMu] = L1MuPt[i];
      L1GoodDoubleMuE[NL1GoodDoubleMu] = L1MuE[i];
      L1GoodDoubleMuEta[NL1GoodDoubleMu] = L1MuEta[i];
      L1GoodDoubleMuPhi[NL1GoodDoubleMu] = L1MuPhi[i];
      L1GoodDoubleMuIsol[NL1GoodDoubleMu] = L1MuIsol[i];
      L1GoodDoubleMuMip[NL1GoodDoubleMu] = L1MuMip[i];
      L1GoodDoubleMuFor[NL1GoodDoubleMu] = L1MuFor[i];
      L1GoodDoubleMuRPC[NL1GoodDoubleMu] = L1MuRPC[i];
      L1GoodDoubleMuQal[NL1GoodDoubleMu] = L1MuQal[i];
      NL1GoodDoubleMu++;
    }
  }
}

void OHltTree::SetOpenL1Bits()
{
  OpenL1_ZeroBias = 1;
  map_BitOfStandardHLTPath["OpenL1_ZeroBias"] = OpenL1_ZeroBias;

  if(L1GoodSingleMuPt[0] > 3.0 && (L1NIsolEmEt[0] > 5.0 || L1IsolEmEt[0] > 5.0)) 
    OpenL1_Mu3EG5 = 1; 
  else 
    OpenL1_Mu3EG5 = 0; 

  if((map_BitOfStandardHLTPath.find("L1_SingleEG5")->second == 1) && 
     (map_BitOfStandardHLTPath.find("L1_HTT100")->second == 1))  
    OpenL1_EG5_HTT100 = 1; 
  else 
    OpenL1_EG5_HTT100 = 0; 
 
  map_BitOfStandardHLTPath["OpenL1_EG5_HTT100"] = OpenL1_EG5_HTT100;  
 
  if(L1OpenMuPt[0] > 30.0)  
    OpenL1_SingleMu30 = 1; 
  else 
    OpenL1_SingleMu30 = 0;  
   
  map_BitOfStandardHLTPath["OpenL1_SingleMu30"] = OpenL1_SingleMu30;   

  OpenL1_SingleCenJet2 = 0; 
  OpenL1_SingleCenJet4 = 0; 
  OpenL1_SingleForJet2 = 0; 
  OpenL1_SingleForJet4 = 0; 
  OpenL1_SingleTauJet2 = 0; 
  OpenL1_SingleTauJet4 = 0; 

  if(L1CenJetEt[0] > 2.0)
    OpenL1_SingleCenJet2 = 1;
  if(L1CenJetEt[0] > 4.0) 
    OpenL1_SingleCenJet4 = 1; 
  if(L1ForJetEt[0] > 2.0) 
    OpenL1_SingleForJet2 = 1; 
  if(L1ForJetEt[0] > 4.0)  
    OpenL1_SingleForJet4 = 1;  
  if(L1TauEt[0] > 2.0) 
    OpenL1_SingleTauJet2 = 1; 
  if(L1TauEt[0] > 4.0)  
    OpenL1_SingleTauJet4 = 1;  

  map_BitOfStandardHLTPath["OpenL1_SingleCenJet2"] = OpenL1_SingleCenJet2; 
  map_BitOfStandardHLTPath["OpenL1_SingleCenJet4"] = OpenL1_SingleCenJet4; 
  map_BitOfStandardHLTPath["OpenL1_SingleForJet2"] = OpenL1_SingleForJet2; 
  map_BitOfStandardHLTPath["OpenL1_SingleForJet4"] = OpenL1_SingleForJet4; 
  map_BitOfStandardHLTPath["OpenL1_SingleTauJet2"] = OpenL1_SingleTauJet2; 
  map_BitOfStandardHLTPath["OpenL1_SingleTauJet4"] = OpenL1_SingleTauJet4; 


  OpenL1_DoubleForJet10_EtaOpp = 0;
  map_BitOfStandardHLTPath["OpenL1_DoubleForJet10_EtaOpp"] = OpenL1_DoubleForJet10_EtaOpp;
  Int_t hfjetplus=0;
  Int_t hfjetminus=0;
  for (Int_t i = 0; i < NL1ForJet;i++)
    {
      if(L1ForJetEt[i] > 10.0 && L1ForJetEta[i] > 3.0)
	hfjetplus++;
      if(L1ForJetEt[i] > 10.0 && L1ForJetEta[i] < -3.0)
	hfjetminus++;
    }
  if(hfjetplus > 0 && hfjetminus > 0)
    OpenL1_DoubleForJet10_EtaOpp = 1;
}


void OHltTree::SetMapL1BitOfStandardHLTPathUsingLogicParser(OHltMenu *menu, int nentry) {
  typedef std::vector<TString> myvec;
  typedef std::pair< TString, std::vector<TString> > mypair;
  typedef std::pair< TString, std::vector<int> > mypair2;
  myvec vtmp;  
  std::vector<int> vtokentmp;
  
  TString st, l1st, seeds;
  unsigned ts = menu->GetTriggerSize();
  unsigned l1ts = menu->GetL1TriggerSize();
  //  std::cout<<"########################### \n";
  //  std::cout <<  "@@@ Level1GTSeedResult\n";
  
  if (nentry == 0) { // do this only for first event - speed up code!
    for (unsigned int i=0;i<ts;i++) {
      vtmp.clear(); 
      vtokentmp.clear(); 
      st = menu->GetTriggerName(i);
      seeds = menu->GetSeedCondition(st);

      //if (seeds != "") continue; // if no seeds skip to avoid error messages

      SetLogicParser((std::string) seeds);
      
      //      std::cout << "Trigger name: " << st << std::endl;
      //      std::cout << "Seed condition: " << seeds << std::endl;

      std::vector<L1GtLogicParser::OperandToken>& algOpTokenVector =
	(m_l1AlgoLogicParser[i])->operandTokenVector();
      
      //std::cout<<"@@@@@@@@@@@@ "<<st<<std::endl;

      for (unsigned int j=0;j<l1ts;j++) {
	l1st = menu->GetL1TriggerName(j);
	
	for (size_t k = 0; k < algOpTokenVector.size(); ++k) {
	  bool iResult = false;
	  //	  std::cout << "Token name: " << (algOpTokenVector[k]).tokenName << std::endl;
	  if (l1st.CompareTo((algOpTokenVector[k]).tokenName) == 0) {         
	    if (map_BitOfStandardHLTPath.find(l1st)->second==1)
	      iResult = true;
	    else
	      iResult = false;
	    
	    //	    std::cout << "Token result: " << map_BitOfStandardHLTPath.find(l1st)->second << std::endl;
	    //	    std::cout << "Token result: " << iResult << std::endl;
	    (algOpTokenVector[k]).tokenResult = iResult;
	    vtmp.push_back(l1st);
	    vtokentmp.push_back((int)k);
	  }
	}
      }    
      map_L1SeedsOfStandardHLTPath.insert(mypair(st, vtmp)); 
      map_RpnTokenIdOfStandardHLTPath.insert(mypair2(st, vtokentmp));
      
      bool seedsResult = (m_l1AlgoLogicParser[i])->expressionResult();
      
      //      std::cout << "Expression result: " << seedsResult << std::endl;
      
      if (seedsResult)
	map_L1BitOfStandardHLTPath[st] = 1;
      else
	map_L1BitOfStandardHLTPath[st] = 0;
    }
  } else {
    for (unsigned int i=0;i<ts;i++) {
      st = menu->GetTriggerName(i);
      seeds = menu->GetSeedCondition(st);

      if (seeds == "") continue; // 
      
      std::vector<L1GtLogicParser::OperandToken>& algOpTokenVector =
	(m_l1AlgoLogicParser[i])->operandTokenVector();

      //      std::cout << "************** " << st << " " << nentry << std::endl;
      
      std::map< TString, std::vector<TString> >::const_iterator it = map_L1SeedsOfStandardHLTPath.find(st);

      if (it != map_L1SeedsOfStandardHLTPath.end()) {
	unsigned ts2 = it->second.size();
	//	std::cout << "########## " << ts2 << std::endl;
	for (unsigned int j=0;j<ts2;j++) {
	  //	  std::cout << "               " << it->second[j] << std::endl;
	  bool iResult = false;
	  if ((map_BitOfStandardHLTPath.find(it->second[j])->second)==1)
	    iResult = true;
	  else
	    iResult = false;
	  
	  (algOpTokenVector[ (map_RpnTokenIdOfStandardHLTPath.find(st))->second[j] ]).tokenResult = iResult;

	}
      }
      
      bool seedsResult = (m_l1AlgoLogicParser[i])->expressionResult();
      //      std::cout << "Expression result: " << seedsResult << std::endl;
     
      if (seedsResult)
	map_L1BitOfStandardHLTPath[st] = 1;
      else
	map_L1BitOfStandardHLTPath[st] = 0;
    }
  }
  
}

bool OHltTree::passPreFilterLogicParser(TString str, int nentry) {

  if (str == "") return true;
  
  if (nentry == 0) { // do this only for first event - speed up code!
    m_preFilterLogicParser = new L1GtLogicParser((std::string)str);
  }

  //cout<<  map_BitOfStandardHLTPath["HLT_Activity_L1A"]<<std::endl;
  
  //std::cout << "Token string: " << (std::string)str << std::endl;
  
  std::vector<L1GtLogicParser::OperandToken>& prefOpTokenVector =
    m_preFilterLogicParser->operandTokenVector();
  
  //std::cout << "Token size: " << prefOpTokenVector.size() << std::endl;
  for (size_t k = 0; k < prefOpTokenVector.size(); ++k) {
    bool iResult = false;
    //std::cout << "Token name: " << (prefOpTokenVector[k]).tokenName << std::endl;
    if (map_BitOfStandardHLTPath.find((prefOpTokenVector[k]).tokenName)->second==1)
      iResult = true;
    else
      iResult = false;
    //std::cout << "Token result: " << iResult << std::endl;
    
    (prefOpTokenVector[k]).tokenResult = iResult;
  }
  bool expResult = m_preFilterLogicParser->expressionResult();
  //bool expResult = true;
  
  if (expResult)
    return true;
  else
    return false;
  
}

Bool_t OHltTree::Notify()
{
  // The Notify() function is called when a new file is opened. This
  // can be either for a new TTree in a TChain or when when a new TTree
  // is started when using PROOF. It is normally not necessary to make changes
  // to the generated code, but the routine can be extended by the
  // user if needed. The return value is currently not used.

  return kTRUE;
}
#endif // #ifdef OHltTree_cxx

#endif // #ifdef OHltTree_h
