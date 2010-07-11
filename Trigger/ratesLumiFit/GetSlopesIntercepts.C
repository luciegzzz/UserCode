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
TH1D* GetTH1Subset(const TH1* h, Int_t nrBins);

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

void GetSlopesIntercepts(TString DS="JMT"){

  //char text[500];
  TString dir = "r137028_root_files/";
  TString fileInNameMinBias  =dir+"hltmenu_7TeV_1.0e29_startup_2010Jun17_r137028_Minbias.root";
  TString fileInNameMu=dir+"hltmenu_7TeV_1.0e29_startup_2010Jun17_r137028_Mu.root";
  TString fileInNameJetMETTau=dir+"hltmenu_7TeV_1.0e29_startup_2010Jun17_r137028_JetMETTau.root";
  TString fileInNameEG=dir+"hltmenu_7TeV_1.0e29_startup_2010Jun17_r137028_EG.root";
  TString fileInNameMuMonitor=dir+"hltmenu_7TeV_1.0e29_startup_2010Jun17_r137028_MuMonitor.root";
  TString fileInNameJetMETTauMonitor=dir+"hltmenu_7TeV_1.0e29_startup_2010Jun17_r137028_JetMETTauMonitor.root";
  TString fileInNameEGMonitor=dir+"hltmenu_7TeV_1.0e29_startup_2010Jun17_r137028_EGMon.root";
  TString fileInNameCommissioning=dir+"hltmenu_7TeV_1.0e29_startup_2010Jun17_r137028_Commissioning.root";
 
  TFile* fMB  = TFile::Open(fileInNameMinBias);
  TFile* f;
  if (DS==TString("Mu" )) f = TFile::Open(fileInNameMu);
  if (DS==TString("JMT")) f = TFile::Open(fileInNameJetMETTau);
  if (DS==TString("EG" )) f = TFile::Open(fileInNameEG);
  if (DS==TString("MuMon" )) f = TFile::Open(fileInNameMuMonitor);
  if (DS==TString("JMTMon")) f = TFile::Open(fileInNameJetMETTauMonitor);
  if (DS==TString("EGMon" )) f = TFile::Open(fileInNameEGMonitor);
  if (DS==TString("Comm" ))  f = TFile::Open(fileInNameCommissioning);
  TH2F* individualPerLS_MB      = (TH2F*)findObj("individualPerLS","TH2F", fMB );
  TH2F* individualPerLS         = (TH2F*)findObj("individualPerLS","TH2F", f   );

  int nPaths     =individualPerLS_MB->GetXaxis()->GetNbins();
  int nLumiSecMB   =individualPerLS_MB->GetYaxis()->GetNbins();
  int nLumiSec   =individualPerLS->GetYaxis()->GetNbins();

  float rates[5000];
  float lumis[5000];

  printf("# of paths: %d\n"       ,nPaths  );
  printf("# of LumiSectionsMB: %d\n",nLumiSecMB);
  printf("# of LumiSections: %d\n",nLumiSec);
  ofstream mbOFile;
  mbOFile.open ("lumiSecMB.txt");
  ofstream pathOFile;
  pathOFile.open ("lumiSec.txt");
	
  vector<TString> v_selectedPaths;
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
  else if (DS==TString("Mu")) {
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
  else if (DS==TString("MuMon")) {
    v_selectedPaths.push_back(TString("HLT_L1Mu"));
    v_selectedPaths.push_back(TString("HLT_L1MuOpen"));
  }
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

  // 	v_selectedPaths.push_back(TString("HLT_Photon10_L1R"));
  // 	v_selectedPaths.push_back(TString("HLT_Photon15_L1R"));
  // 	v_selectedPaths.push_back(TString("HLT_Photon20_L1R"));
  // 	v_selectedPaths.push_back(TString("HLT_Photon30_L1R_8E29"));
  // 	v_selectedPaths.push_back(TString("HLT_DoublePhoton5_L1R"));
  // 	v_selectedPaths.push_back(TString("HLT_L2Mu0"));
  // 	v_selectedPaths.push_back(TString("HLT_Mu3"));
  // 	v_selectedPaths.push_back(TString("HLT_Mu5"));
  // 	v_selectedPaths.push_back(TString("HLT_L1DoubleMuOpen"));
  // 	v_selectedPaths.push_back(TString("HLT_Ele10_LW_L1R"));
  // 	v_selectedPaths.push_back(TString("HLT_Ele10_LW_EleId_L1R"));
  // 	v_selectedPaths.push_back(TString("HLT_Ele15_LW_L1R"));
  // 	v_selectedPaths.push_back(TString("HLT_Ele20_LW_L1R"));
  // 	v_selectedPaths.push_back(TString("HLT_SingleLooseIsoTau20"));
  // 	v_selectedPaths.push_back(TString("HLT_DoubleLooseIsoTau15"));


  double rebinFactor=27;
  double scaleFactor_RateLumi=rebinFactor*7000.;//7000Hz@1E29, PS_L1, PS_HLT
  TH1D* h_referencePath;
  TH1D* h_Luminosity;

  vector<TH1D*>   vh_selectedPaths;
  vector<TGraph*> vtg_selectedPaths;

 for (int iPath=1; iPath<nPaths+1; ++iPath) {
    TString iPathName(individualPerLS_MB->GetXaxis()->GetBinLabel(iPath));
    if (iPathName==TString("HLT_L1_BscMinBiasOR_BptxPlusORMinus")) {
      TH1D* htemp=individualPerLS_MB->ProjectionY(iPathName,iPath,iPath);
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
      //			printf("Path[%d] = %50s\n",iPath,iPathName.Data());
      if (iPathName==v_selectedPaths.at(iSelPath)) {
	TH1D* htemp=individualPerLS->ProjectionY(iPathName,iPath,iPath);
	htemp->SetTitle(iPathName);
	htemp->Rebin(rebinFactor);
	htemp->Scale(1./rebinFactor);
	vh_selectedPaths.push_back(htemp);

// 	if ( nLumiSecMB < nLumiSec ) {
// 	  TH1D* htemp_sub = GetTH1Subset(htemp,nLumiSecMB);
// 	  htemp_sub->SetTitle(iPathName);
// 	  htemp_sub->Rebin(rebinFactor);
// 	  htemp_sub->Scale(1./rebinFactor);
// 	  vh_selectedPaths.push_back(htemp_sub);
// 	}

	if(iPathName==v_selectedPaths.at(1)){
	  for (unsigned int iLS =0;iLS<nLumiSec;iLS++){
	    TString iLSName(individualPerLS->GetYaxis()->GetBinLabel(iLS));
	    pathOFile<<"lumi section "<<iLSName<<endl;
	  }
	}
      }
    }
  }
 
	
  h_Luminosity = (TH1D*) h_referencePath->Clone();
  h_Luminosity->SetNameTitle("h_Luminosity","h_Luminosity");
  h_Luminosity->Scale(1.0/scaleFactor_RateLumi);
  h_Luminosity->Draw();
  //h_referencePath->Draw("e");

  int nBins=h_Luminosity->GetXaxis()->GetNbins();

  for (int iLS=0; iLS<nBins; ++iLS) {
    lumis[iLS] = h_Luminosity->GetBinContent(iLS+1);
    //printf("%f ",lumis[iLS]);
  }
  for (unsigned int iSelPath=0; iSelPath<v_selectedPaths.size(); ++iSelPath) {
    //for (unsigned int iSelPath=0; iSelPath<; ++iSelPath) {
    for (int iLS=0; iLS<nBins; ++iLS) {
      rates[iLS] = vh_selectedPaths.at(iSelPath)->GetBinContent(iLS+1);
      //printf("%f ",rates[iLS]);
    }
    TGraph* tg_temp = new TGraph(nBins,lumis,rates);
    tg_temp->SetTitle(vh_selectedPaths.at(iSelPath)->GetName());
    vtg_selectedPaths.push_back(tg_temp);
  }
  //vtg_selectedPaths.at(0)->Fit("pol1");
  //vtg_selectedPaths.at(1)->Fit("pol1");
  //vtg_selectedPaths.at(0)->Draw("A*");
  //vh_selectedPaths.at(0)->Draw();

  double poli1(double *x, double *par);
  double Pars[200][2];
  TF1 *fit = new TF1("fit",poli1,0.,10.,2);
  fit->SetParNames("Intercept","Slope");
  for (unsigned int iSelPath=0; iSelPath<vtg_selectedPaths.size(); ++iSelPath) {
    fit->SetParameters(0,1);
    vtg_selectedPaths.at(iSelPath)->Fit("fit");
    fit->GetParameters(Pars[iSelPath]);
  }

  for (unsigned int iSelPath=0; iSelPath<v_selectedPaths.size(); ++iSelPath) {
    printf("%50s: Intercept = %3.3lf\tSlope = %3.3lf\tRate[2E29] = %3.3lf\tRate[4E29] = %3.3lf\tRate[8E29] = %3.3lf\n",
	   v_selectedPaths.at(iSelPath).Data(),
	   Pars[iSelPath][0],Pars[iSelPath][1],
	   Pars[iSelPath][0]+Pars[iSelPath][1]*2,
	   Pars[iSelPath][0]+Pars[iSelPath][1]*4,
	   Pars[iSelPath][0]+Pars[iSelPath][1]*8 );
  }

//   TCanvas* c = new TCanvas("c","c",0,0,1000,1000);
//   c->Divide(5,5);
  for (unsigned int iSelPath=0; iSelPath<vtg_selectedPaths.size(); ++iSelPath) {
//     c->cd(iSelPath+1);
     vh_selectedPaths.at(iSelPath)->Draw();
//     // 		vtg_selectedPaths.at(iSelPath)->Draw("A*");
   }
 //  TCanvas* cg = new TCanvas("cg","cg",0,100,1000,1000);
//   cg->Divide(5,5);
   for (unsigned int iSelPath=0; iSelPath<vtg_selectedPaths.size(); ++iSelPath) {
//     cg->cd(iSelPath+1);
//     //vh_selectedPaths.at(iSelPath)->Draw();
         vtg_selectedPaths.at(iSelPath)->Draw("A*");
   }
//   mbOFile.close();
  pathOFile.close();
}

double poli1(double *x, double *par) {
  return par[0] + par[1] * x[0];
}
//creates a sub histo of h for containing only href bins
TH1D* GetTH1Subset(const TH1* h, Int_t nrBins){
  TH1D* subHisto = new TH1D("subHisto","subHisto", nrBins,0,nrBins-1);
  for (int i = 0 ; i < nrBins ; i++){
    subHisto->Fill(i,h->GetBinContent(i+1));
  }
  return subHisto;

}
