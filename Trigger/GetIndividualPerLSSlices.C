#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

#ifndef __CINT__
#include <TPRegexp.h>
#include <TRegexp.h>
#include <TCanvas.h>
#include <TFile.h>
#include <TList.h>
#include <TH1.h>
#include <TObject.h>
#include <TDirectory.h>
#include <TPad.h>
#include <TVirtualPad.h>
#include <TSeqCollection.h>
#include <TROOT.h>
#include <TSystem.h>
#include <TEnv.h>
#include <TMath.h>
#include <TObjArray.h>
#include <TStyle.h>
#include <TKey.h>
#include <TH1D.h>
#include <TH2D.h>
#include <TProfile.h>
#include <TGraph.h>
#include <TF1.h>
#endif

#include <TLegendEntry.h>

using namespace std;

// Finds the first object with a matching name.
TObject* findObj(const Char_t namePattern[], const Char_t classPattern[] = "", TDirectory* dir = 0, const Bool_t matchTitle = kFALSE, const Int_t startIndex = 0)
{
  if (dir == 0)         dir = gDirectory;
  TPRegexp    matchName (namePattern);
  TPRegexp    matchClass(classPattern);
  TIter       next      (dir->GetListOfKeys());
  TKey*       key       = 0;
  Int_t       index     = 0;
  TString     name;
  while (key = (TKey*) next()) {
    name      = matchTitle ? key->GetTitle() : key->GetName();
    if (matchName.Match(name) && matchClass.Match(key->GetClassName()) && (++index > startIndex))
      return key->ReadObj();
  }
  return 0;
}

void GetIndividualPerLSSlices(TString DS="Mu"){

  //char text[500];
//   TString dir                       = "r137027_root_files/";
//   TString fileInNameMinBias         = dir+"hltmenu_7TeV_1.0e29_startup_2010Jun17_r137027_Minbias.root";
//   TString fileInNameMu              = dir+"hltmenu_7TeV_1.0e29_startup_2010Jun17_r137027_Mu.root";
//   TString fileInNameJetMETTau       = dir+"hltmenu_7TeV_1.0e29_startup_2010Jun17_r137027_JetMETTau.root";
//   TString fileInNameEG              = dir+"hltmenu_7TeV_1.0e29_startup_2010Jun17_r137027_EG.root";
//   TString fileInNameMuMonitor       = dir+"hltmenu_7TeV_1.0e29_startup_2010Jun17_r137027_MuMonitor.root";
//   TString fileInNameJetMETTauMonitor= dir+"hltmenu_7TeV_1.0e29_startup_2010Jun17_r137027_JetMETTauMonitor.root";
//   TString fileInNameEGMonitor       = dir+"hltmenu_7TeV_1.0e29_startup_2010Jun17_r137027_EGMon.root";
//   TString fileInNameCommissioning   = dir+"hltmenu_7TeV_1.0e29_startup_2010Jun17_r137027_Comm.root";
  TString dir                       = "r136100_root_files/";
  TString fileInNameMinBias         = dir+"hltmenu_7TeV_1.0e29_startup_HLT_LowInt_2E29-V2_r136100.root";
  TString fileInNameMu              = dir+"hltmenu_7TeV_1.0e29_startup_HLT_LowInt_2E29-V2_r136100_Mu.root";
  TString fileInNameJetMETTau       = dir+"hltmenu_7TeV_1.0e29_startup_HLT_LowInt_2E29-V2_r136100_JetMETTau.root";
  TString fileInNameEG              = dir+"hltmenu_7TeV_1.0e29_startup_HLT_LowInt_2E29-V2_r136100_EG.root";
  TString fileInNameMuMonitor       = dir+"hltmenu_7TeV_1.0e29_startup_HLT_LowInt_2E29-V2_r136100_MuMonitor.root";
  TString fileInNameJetMETTauMonitor= dir+"hltmenu_7TeV_1.0e29_startup_HLT_LowInt_2E29-V2_r136100_JetMETTauMonitor.root";
  TString fileInNameEGMonitor       = dir+"hltmenu_7TeV_1.0e29_startup_HLT_LowInt_2E29-V2_r136100_EGMonitor.root";
  TString fileInNameCommissioning   = dir+"hltmenu_7TeV_1.0e29_startup_HLT_LowInt_2E29-V2_r136100_Commissioning.root";

  TFile* fMB = TFile::Open(fileInNameMinBias);
  TFile* f;
  if (DS==TString("Mu" ))    f = TFile::Open(fileInNameMu);
  if (DS==TString("JMT"))    f = TFile::Open(fileInNameJetMETTau);
  if (DS==TString("EG" ))    f = TFile::Open(fileInNameEG);
  if (DS==TString("MuMon" )) f = TFile::Open(fileInNameMuMonitor);
  if (DS==TString("JMTMon")) f = TFile::Open(fileInNameJetMETTauMonitor);
  if (DS==TString("EGMon" )) f = TFile::Open(fileInNameEGMonitor);
  if (DS==TString("Comm" ))  f = TFile::Open(fileInNameCommissioning);

  TH2F* individualPerLS_MB      = (TH2F*)findObj("individualPerLS","TH2F", fMB );
  TH2F* individualPerLS         = (TH2F*)findObj("individualPerLS","TH2F", f   );

  int nPaths       = individualPerLS_MB->GetXaxis()->GetNbins();
  int nLumiSecMB   = individualPerLS_MB->GetYaxis()->GetNbins();
  int nLumiSec     = individualPerLS->GetYaxis()->GetNbins();

  cout<<"# of paths: "  <<     nPaths <<endl;
  cout<<"# of LumiSectionsMB: "<<nLumiSecMB<<endl;
  cout<<"# of LumiSections: "<<nLumiSec<<endl;
  ofstream mbOFile;
  mbOFile.open ("lumiSecMB.txt");
  ofstream pathOFile;
  pathOFile.open ("lumiSec.txt");

	
  vector<TString> v_selectedPaths;

  if (DS==TString("Mu")) {
    //Mu
    v_selectedPaths.push_back(TString("HLT_DoubleMu0"));
    v_selectedPaths.push_back(TString("HLT_DoubleMu3"));
    v_selectedPaths.push_back(TString("HLT_IsoMu3"));
    v_selectedPaths.push_back(TString("HLT_L1DoubleMuOpen"));
    v_selectedPaths.push_back(TString("HLT_L1Mu14_L1ETM30"));
    //v_selectedPaths.push_back(TString("HLT_L1Mu14_L1SingleEG10"));
    v_selectedPaths.push_back(TString("HLT_L1Mu14_L1SingleJet6U"));
    v_selectedPaths.push_back(TString("HLT_L1Mu20"));
    v_selectedPaths.push_back(TString("HLT_L2DoubleMu0"));
    v_selectedPaths.push_back(TString("HLT_L2Mu0"));
    v_selectedPaths.push_back(TString("HLT_L2Mu11"));
    v_selectedPaths.push_back(TString("HLT_L2Mu3"));
    v_selectedPaths.push_back(TString("HLT_L2Mu5"));
    v_selectedPaths.push_back(TString("HLT_L2Mu9"));
    v_selectedPaths.push_back(TString("HLT_Mu0_L1MuOpen"));
    v_selectedPaths.push_back(TString("HLT_Mu0_L2Mu0"));
    v_selectedPaths.push_back(TString("HLT_Mu0_Track0_Jpsi"));
    v_selectedPaths.push_back(TString("HLT_Mu3"));
    v_selectedPaths.push_back(TString("HLT_Mu3_L1MuOpen"));
    v_selectedPaths.push_back(TString("HLT_Mu3_L2Mu0"));
    v_selectedPaths.push_back(TString("HLT_Mu3_Track0_Jpsi"));
    v_selectedPaths.push_back(TString("HLT_Mu5"));
    v_selectedPaths.push_back(TString("HLT_Mu5_L1MuOpen"));
    v_selectedPaths.push_back(TString("HLT_Mu5_L2Mu0"));
    v_selectedPaths.push_back(TString("HLT_Mu5_Track0_Jpsi"));
    v_selectedPaths.push_back(TString("HLT_Mu9"));
  }
  else
    // JetMETTau
    if (DS==TString("JMT")) {
      v_selectedPaths.push_back(TString("HLT_Jet15U"));
      v_selectedPaths.push_back(TString("HLT_Jet15U_HcalNoiseFiltered"));
      v_selectedPaths.push_back(TString("HLT_Jet30U"));
      v_selectedPaths.push_back(TString("HLT_Jet50U"));
      v_selectedPaths.push_back(TString("HLT_DiJetAve15U_8E29"));
      v_selectedPaths.push_back(TString("HLT_DiJetAve30U_8E29"));
      v_selectedPaths.push_back(TString("HLT_DoubleJet15U_ForwardBackward"));
      v_selectedPaths.push_back(TString("HLT_FwdJet20U"));
      v_selectedPaths.push_back(TString("HLT_HT100U"));
      v_selectedPaths.push_back(TString("HLT_MET100"));
      v_selectedPaths.push_back(TString("HLT_MET45"));
      v_selectedPaths.push_back(TString("HLT_QuadJet15U"));
      v_selectedPaths.push_back(TString("HLT_SingleLooseIsoTau20"));
      v_selectedPaths.push_back(TString("HLT_DoubleLooseIsoTau15"));
      v_selectedPaths.push_back(TString("HLT_BTagIP_Jet50U"));
      v_selectedPaths.push_back(TString("HLT_BTagMu_Jet10U"));
    }
    else if (DS==TString("EG")) {
      // EG
      v_selectedPaths.push_back(TString("HLT_Ele10_LW_EleId_L1R"));
      v_selectedPaths.push_back(TString("HLT_Ele10_LW_L1R"));
      v_selectedPaths.push_back(TString("HLT_Ele15_LW_L1R"));
      v_selectedPaths.push_back(TString("HLT_Ele15_SC10_LW_L1R"));
      v_selectedPaths.push_back(TString("HLT_Ele15_SiStrip_L1R"));
      v_selectedPaths.push_back(TString("HLT_Ele20_LW_L1R"));
      v_selectedPaths.push_back(TString("HLT_DoubleEle5_SW_L1R"));
      v_selectedPaths.push_back(TString("HLT_Photon10_L1R"));
      v_selectedPaths.push_back(TString("HLT_Photon15_L1R"));
      v_selectedPaths.push_back(TString("HLT_Photon15_LooseEcalIso_L1R"));
      v_selectedPaths.push_back(TString("HLT_Photon15_TrackIso_L1R"));
      v_selectedPaths.push_back(TString("HLT_Photon20_L1R"));
      v_selectedPaths.push_back(TString("HLT_Photon30_L1R_8E29"));
      v_selectedPaths.push_back(TString("HLT_DoublePhoton10_L1R"));
      v_selectedPaths.push_back(TString("HLT_DoublePhoton4_Jpsi_L1R"));
      v_selectedPaths.push_back(TString("HLT_DoublePhoton4_Upsilon_L1R"));
      v_selectedPaths.push_back(TString("HLT_DoublePhoton4_eeRes_L1R"));
      v_selectedPaths.push_back(TString("HLT_DoublePhoton5_Jpsi_L1R"));
      v_selectedPaths.push_back(TString("HLT_DoublePhoton5_L1R"));
      v_selectedPaths.push_back(TString("HLT_DoublePhoton5_Upsilon_L1R"));
    }
    else if (DS==TString("MuMon")) {
      v_selectedPaths.push_back(TString("HLT_L1Mu"));
      v_selectedPaths.push_back(TString("HLT_L1MuOpen"));
    }
  //JETMETTauMonitor
    else if (DS==TString("JMTMon")) {
      v_selectedPaths.push_back(TString("HLT_L1Jet6U"));
      v_selectedPaths.push_back(TString("HLT_L1Jet6U_NoBPTX"));
      v_selectedPaths.push_back(TString("HLT_L1Jet10U"));
      v_selectedPaths.push_back(TString("HLT_L1Jet10U_NoBPTX"));
      v_selectedPaths.push_back(TString("HLT_L1MET20"));
      v_selectedPaths.push_back(TString("HLT_L1SingleCenJet"));
      v_selectedPaths.push_back(TString("HLT_L1SingleCenJet_NoBPTX"));
      v_selectedPaths.push_back(TString("HLT_L1SingleForJet"));
      v_selectedPaths.push_back(TString("HLT_L1SingleForJet_NoBPTX"));
      v_selectedPaths.push_back(TString("HLT_L1SingleTauJet"));
      v_selectedPaths.push_back(TString("HLT_L1SingleTauJet_NoBPTX"));
    }
    else if (DS==TString("EGMon")) {
      v_selectedPaths.push_back(TString("HLT_L1SingleEG2"));
      v_selectedPaths.push_back(TString("HLT_L1SingleEG5"));
      v_selectedPaths.push_back(TString("HLT_L1SingleEG8"));
      v_selectedPaths.push_back(TString("HLT_L1DoubleEG5"));
    }
    else if (DS==TString("Comm")) {
      v_selectedPaths.push_back(TString("HLT_Activity_DT"));
      v_selectedPaths.push_back(TString("HLT_Activity_DT_Tuned"));
      v_selectedPaths.push_back(TString("HLT_Activity_Ecal"));
      v_selectedPaths.push_back(TString("HLT_Activity_EcalREM"));
      v_selectedPaths.push_back(TString("HLT_Activity_L1A"));
      v_selectedPaths.push_back(TString("HLT_Activity_PixelClusters"));
      v_selectedPaths.push_back(TString("HLT_L1_BptxXOR_BscMinBiasOR"));
      v_selectedPaths.push_back(TString("HLT_SelectEcalSpikesHighEt_L1R"));
      v_selectedPaths.push_back(TString("HLT_SelectEcalSpikes_L1R"));
    }
    else {return;}


  double rebinFactor=66.;
  double scaleFactor_RateLumi=rebinFactor;//*7000.;//7000Hz@1E29, PS_L1, PS_HLT
  TH1D* h_referencePath;
  TH1D* h_Luminosity;

  vector<TH1D*>   vh_selectedPaths;

  for (int iPath=1; iPath<nPaths+1; ++iPath) {
    TString iPathName(individualPerLS_MB->GetXaxis()->GetBinLabel(iPath));
    if (iPathName==TString("HLT_L1_BscMinBiasOR_BptxPlusORMinus")) {
      TH1D* htemp=individualPerLS_MB->ProjectionY(iPathName,iPath,iPath,"e");
      if ( nLumiSec < nLumiSecMB ) {
	htemp->SetBins(nLumiSec,0,nLumiSec-1);
      }
      htemp->SetTitle(iPathName);
      htemp->Rebin(rebinFactor);
      h_referencePath=htemp;
      for(unsigned int iLS=0 ; iLS<nLumiSecMB ; iLS++){
	TString iLSName(individualPerLS->GetYaxis()->GetBinLabel(iLS));
	mbOFile<<"lumi section "<<iLSName<<endl;
      }
    }
  }

  for (unsigned int iSelPath=0; iSelPath<v_selectedPaths.size(); ++iSelPath) {
    for (int iPath=1; iPath<nPaths+1; ++iPath) {
      TString iPathName(individualPerLS->GetXaxis()->GetBinLabel(iPath));
       if (iPathName==v_selectedPaths.at(iSelPath)) {
	 TH1D* htemp=individualPerLS->ProjectionY(iPathName,iPath,iPath,"e");
 	if ( nLumiSecMB < nLumiSec ) {
	  htemp->SetBins(nLumiSecMB,0,nLumiSecMB-1);
	}
	  htemp->SetTitle(iPathName);
 	  htemp->Rebin(rebinFactor);
	  htemp->Scale(1./rebinFactor);
	  vh_selectedPaths.push_back(htemp);

	if(iPathName==v_selectedPaths.at(1)){
	  for (unsigned int iLS =0;iLS<nLumiSec;iLS++){
	    TString iLSName(individualPerLS->GetYaxis()->GetBinLabel(iLS));
	    pathOFile<<"lumi section "<<iLSName<<endl;
	  }
	}
      }
    }
  }

  TString outputFileName = dir+DS+".root";
  TFile output(outputFileName, "RECREATE");

  TCanvas* h_Lumi = new TCanvas("h_Lumi","h_Lumi",0,0,1000,1000);
  h_Luminosity = (TH1D*) h_referencePath->Clone();
  h_Luminosity->SetNameTitle("h_Luminosity","h_Luminosity");
  h_Luminosity->Scale(1.0/scaleFactor_RateLumi);
  h_Luminosity->Draw();
  h_Luminosity->Write();
  for (int i =0 ;i<h_Luminosity->GetNbinsX();i++){
    cout<<"error "<<h_Luminosity->GetBinError(i+1)<<endl;
  }

   TCanvas* RatesPerLS = new TCanvas("RatesPerLS","RatesPerLS",0,0,1000,1000);
   RatesPerLS->Divide(5,5);
   for (unsigned int iSelPath=0; iSelPath<vh_selectedPaths.size(); ++iSelPath) {
     RatesPerLS->cd(iSelPath+1);
     vh_selectedPaths.at(iSelPath)->Draw();
     vh_selectedPaths.at(iSelPath)->Write();
  }

  output.Close();
  mbOFile.close();
  pathOFile.close();

}

