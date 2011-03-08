/*
This macro takes the Pt, x vs SumEt distributions (output of metsanalyzer, saved in plotsPUX.root), project along Y (= get rid of/ignore sumEt dependence) calculates sigmaGauss(Et,x) and get the RMS , for different PU (= average # of PU as generated with FastSim), for met 0, 1 and 2 (currently CaloMet, PFMet, PFMet w/o PU)
sigma(Et,x) and RMS vs PU are drawn
*/

#include <TFile.h>
#include <TKey.h>
#include <TH1F.h>
#include <TH2F.h>
#include <TCanvas.h>
#include <TObjArray.h>

void makePUplots()
{
  //get Pt distributions files
  TFile *fPU0       =  TFile::Open("plotsPU0.root");
  TFile *fPU5       =  TFile::Open("plotsPU5.root");
  TFile *fPU10      =  TFile::Open("plotsPU10.root");
  TFile *fPU15      =  TFile::Open("plotsPU15.root");
  TFile *fPU20      =  TFile::Open("plotsPU20.root");
  TFile *fPU25      =  TFile::Open("plotsPU25.root");

  /*****met 0******/
  //get Pt,x vs SumEt histo for met 0 
  TH2F *EtxVsSumEt0PU0  = (TH2F*)fPU0  -> Get("h_EtxVsSumEt0");
  TH2F *EtxVsSumEt0PU5  = (TH2F*)fPU5  -> Get("h_EtxVsSumEt0");
  TH2F *EtxVsSumEt0PU10 = (TH2F*)fPU10 -> Get("h_EtxVsSumEt0");
  TH2F *EtxVsSumEt0PU15 = (TH2F*)fPU15 -> Get("h_EtxVsSumEt0");
  TH2F *EtxVsSumEt0PU20 = (TH2F*)fPU20 -> Get("h_EtxVsSumEt0");
  TH2F *EtxVsSumEt0PU25 = (TH2F*)fPU25 -> Get("h_EtxVsSumEt0");

  //project Pt Vs SumEt (for sigma(Etx) vs PU, any sumEt), gaussian fit
  TH1D *EtxVsSumEt0SlicePU0 = EtxVsSumEt0PU0 -> ProjectionY("PU0");
  EtxVsSumEt0SlicePU0 -> Draw();
  TF1* f0 = new TF1("f0", "gaus", -50, 50);
  EtxVsSumEt0SlicePU0 -> Fit("f0");

  TH1D *EtxVsSumEt0SlicePU5 = EtxVsSumEt0PU5 -> ProjectionY("PU5");
  EtxVsSumEt0SlicePU5 -> Draw();
  TF1* f5 = new TF1("f5", "gaus", -50, 50);
  EtxVsSumEt0SlicePU5 -> Fit("f5");

  TH1D *EtxVsSumEt0SlicePU10 = EtxVsSumEt0PU10 -> ProjectionY("PU10");
  EtxVsSumEt0SlicePU10 -> Draw();
  TF1* f10 = new TF1("f10", "gaus", -50, 50);
  EtxVsSumEt0SlicePU10 -> Fit("f10");

  TH1D *EtxVsSumEt0SlicePU15 = EtxVsSumEt0PU15 -> ProjectionY("PU15");
  EtxVsSumEt0SlicePU15 -> Draw();
  TF1* f15 = new TF1("f15", "gaus", -50, 50);
  EtxVsSumEt0SlicePU15 -> Fit("f15");

  TH1D *EtxVsSumEt0SlicePU20 = EtxVsSumEt0PU20 -> ProjectionY("PU20");
  EtxVsSumEt0SlicePU20 -> Draw();
  TF1* f20 = new TF1("f20", "gaus", -50, 50);
  EtxVsSumEt0SlicePU20 -> Fit("f20");

  TH1D *EtxVsSumEt0SlicePU25 = EtxVsSumEt0PU25 -> ProjectionY("PU25");
  EtxVsSumEt0SlicePU25 -> Draw();
  TF1* f25 = new TF1("f25", "gaus", -50, 50);
  EtxVsSumEt0SlicePU25 -> Fit("f25");


  //put sigma from histo fits into TH2
  TH1D *SigmaEtxVsPU = new TH1D("SigmaEtx0VsPU", "sigma(Et,x) vs PU", 30, 0, 30);//, 20, 0, 20);
  SigmaEtx0VsPU -> Fill(0, f0  -> GetParameter(2));
  SigmaEtx0VsPU -> Fill(5, f5  -> GetParameter(2));
  SigmaEtx0VsPU -> Fill(10,f10 -> GetParameter(2));
  SigmaEtx0VsPU -> Fill(15,f15 -> GetParameter(2));
  SigmaEtx0VsPU -> Fill(20,f20 -> GetParameter(2));
  SigmaEtx0VsPU -> Fill(25,f25 -> GetParameter(2));

  SigmaEtx0VsPU -> SetBinError(1, f0  -> GetParError(2));
  SigmaEtx0VsPU -> SetBinError(6, f5  -> GetParError(2));
  SigmaEtx0VsPU -> SetBinError(11,f10 -> GetParError(2));
  SigmaEtx0VsPU -> SetBinError(16,f15 -> GetParError(2));
  SigmaEtx0VsPU -> SetBinError(21,f20 -> GetParError(2));
  SigmaEtx0VsPU -> SetBinError(26,f25 -> GetParError(2));

 //put the RMS from projected histo into TH2
  TH1D *RMSEtx0VsPU = new TH1D("RMSEtx0VsPU", "RMS(Et,x) vs PU", 30, 0, 30);//, 20, 0, 20);
  RMSEtx0VsPU -> Fill(0, EtxVsSumEt0SlicePU0  -> GetRMS());
  RMSEtx0VsPU -> Fill(5, EtxVsSumEt0SlicePU5  -> GetRMS());
  RMSEtx0VsPU -> Fill(10,EtxVsSumEt0SlicePU10 -> GetRMS());
  RMSEtx0VsPU -> Fill(15,EtxVsSumEt0SlicePU15 -> GetRMS());
  RMSEtx0VsPU -> Fill(20,EtxVsSumEt0SlicePU20 -> GetRMS());
  RMSEtx0VsPU -> Fill(25,EtxVsSumEt0SlicePU25 -> GetRMS());

  RMSEtx0VsPU -> SetBinError(0, 0.);//EtxVsSumEt0SlicePU0  -> GetRMSError(2));
  RMSEtx0VsPU -> SetBinError(5, 0.);//EtxVsSumEt0SlicePU5  -> GetRMSError(2));
  RMSEtx0VsPU -> SetBinError(10,0.);//EtxVsSumEt0SlicePU10 -> GetRMSError(2));
  RMSEtx0VsPU -> SetBinError(15,0.);//EtxVsSumEt0SlicePU15 -> GetRMSError(2));
  RMSEtx0VsPU -> SetBinError(20,0.);//EtxVsSumEt0SlicePU20 -> GetRMSError(2));
  RMSEtx0VsPU -> SetBinError(25,0.);//EtxVsSumEt0SlicePU25 -> GetRMSError(2));



  /************met1******************/

 //get Pt,x vs SumEt histo for met 1 
  TH2F *EtxVsSumEt1PU0  = (TH2F*)fPU0  -> Get("h_EtxVsSumEt1");
  TH2F *EtxVsSumEt1PU5  = (TH2F*)fPU5  -> Get("h_EtxVsSumEt1");
  TH2F *EtxVsSumEt1PU10 = (TH2F*)fPU10 -> Get("h_EtxVsSumEt1");
  TH2F *EtxVsSumEt1PU15 = (TH2F*)fPU15 -> Get("h_EtxVsSumEt1");
  TH2F *EtxVsSumEt1PU20 = (TH2F*)fPU20 -> Get("h_EtxVsSumEt1");
  TH2F *EtxVsSumEt1PU25 = (TH2F*)fPU25 -> Get("h_EtxVsSumEt1");

  //project Pt Vs SumEt (for sigma(Etx) vs PU, any sumEt), gaussian fit
  TH1D *EtxVsSumEt1SlicePU0 = EtxVsSumEt1PU0 -> ProjectionY("PU0");
  EtxVsSumEt1SlicePU0 -> Draw();
  TF1* f0 = new TF1("f0", "gaus", -50, 50);
  EtxVsSumEt1SlicePU0 -> Fit("f0");

  TH1D *EtxVsSumEt1SlicePU5 = EtxVsSumEt1PU5 -> ProjectionY("PU5");
  EtxVsSumEt1SlicePU5 -> Draw();
  TF1* f5 = new TF1("f5", "gaus", -50, 50);
  EtxVsSumEt1SlicePU0 -> Fit("f5");

  TH1D *EtxVsSumEt1SlicePU10 = EtxVsSumEt1PU10 -> ProjectionY("PU10");
  EtxVsSumEt1SlicePU10 -> Draw();
  TF1* f10 = new TF1("f10", "gaus", -50, 50);
  EtxVsSumEt1SlicePU10 -> Fit("f10");

  TH1D *EtxVsSumEt1SlicePU15 = EtxVsSumEt1PU15 -> ProjectionY("PU15");
  EtxVsSumEt1SlicePU15 -> Draw();
  TF1* f15 = new TF1("f15", "gaus", -50, 50);
  EtxVsSumEt1SlicePU15 -> Fit("f15");

  TH1D *EtxVsSumEt1SlicePU20 = EtxVsSumEt1PU20 -> ProjectionY("PU20");
  EtxVsSumEt1SlicePU20 -> Draw();
  TF1* f20 = new TF1("f20", "gaus", -50, 50);
  EtxVsSumEt1SlicePU20 -> Fit("f20");

  TH1D *EtxVsSumEt1SlicePU25 = EtxVsSumEt1PU25 -> ProjectionY("PU25");
  EtxVsSumEt1SlicePU25 -> Draw();
  TF1* f25 = new TF1("f25", "gaus", -50, 50);
  EtxVsSumEt1SlicePU25 -> Fit("f25");


  //put sigma from histo fits into TH2
  TH1D *SigmaEtxVsPU = new TH1D("SigmaEtx1VsPU", "sigma(Et,x) vs PU", 30, 0, 30);//, 20, 0, 20);
  SigmaEtx1VsPU -> Fill(0, f0  -> GetParameter(2));
  SigmaEtx1VsPU -> Fill(5, f5  -> GetParameter(2));
  SigmaEtx1VsPU -> Fill(10,f10 -> GetParameter(2));
  SigmaEtx1VsPU -> Fill(15,f15 -> GetParameter(2));
  SigmaEtx1VsPU -> Fill(20,f20 -> GetParameter(2));
  SigmaEtx1VsPU -> Fill(25,f25 -> GetParameter(2));

  SigmaEtx1VsPU -> SetBinError(1, f0  -> GetParError(2));
  SigmaEtx1VsPU -> SetBinError(6, f5  -> GetParError(2));
  SigmaEtx1VsPU -> SetBinError(11,f10 -> GetParError(2));
  SigmaEtx1VsPU -> SetBinError(16,f15 -> GetParError(2));
  SigmaEtx1VsPU -> SetBinError(21,f20 -> GetParError(2));
  SigmaEtx1VsPU -> SetBinError(26,f25 -> GetParError(2));

  //put the RMS from projected histo into TH2
  TH1D *RMSEtxVsPU = new TH1D("RMSEtx1VsPU", "RMS(Et,x) vs PU", 30, 0, 30);//, 20, 0, 20);
  RMSEtx1VsPU -> Fill(0, EtxVsSumEt1SlicePU0  -> GetRMS());
  RMSEtx1VsPU -> Fill(5, EtxVsSumEt1SlicePU5  -> GetRMS());
  RMSEtx1VsPU -> Fill(10,EtxVsSumEt1SlicePU10 -> GetRMS());
  RMSEtx1VsPU -> Fill(15,EtxVsSumEt1SlicePU15 -> GetRMS());
  RMSEtx1VsPU -> Fill(20,EtxVsSumEt1SlicePU20 -> GetRMS());
  RMSEtx1VsPU -> Fill(25,EtxVsSumEt1SlicePU25 -> GetRMS());

  RMSEtx1VsPU -> SetBinError(0, 0.);//EtxVsSumEt1SlicePU0  -> GetRMSError(2));
  RMSEtx1VsPU -> SetBinError(5, 0.);//EtxVsSumEt1SlicePU5  -> GetRMSError(2));
  RMSEtx1VsPU -> SetBinError(10,0.);//EtxVsSumEt1SlicePU10 -> GetRMSError(2));
  RMSEtx1VsPU -> SetBinError(15,0.);//EtxVsSumEt1SlicePU15 -> GetRMSError(2));
  RMSEtx1VsPU -> SetBinError(20,0.);//EtxVsSumEt1SlicePU20 -> GetRMSError(2));
  RMSEtx1VsPU -> SetBinError(25,0.);//EtxVsSumEt1SlicePU25 -> GetRMSError(2));
 

 /************met2******************/

 //get Pt,x vs SumEt histo for met 2 
  TH2F *EtxVsSumEt2PU0  = (TH2F*)fPU0  -> Get("h_EtxVsSumEt2");
  TH2F *EtxVsSumEt2PU5  = (TH2F*)fPU5  -> Get("h_EtxVsSumEt2");
  TH2F *EtxVsSumEt2PU10 = (TH2F*)fPU10 -> Get("h_EtxVsSumEt2");
  TH2F *EtxVsSumEt2PU15 = (TH2F*)fPU15 -> Get("h_EtxVsSumEt2");
  TH2F *EtxVsSumEt2PU20 = (TH2F*)fPU20 -> Get("h_EtxVsSumEt2");
  TH2F *EtxVsSumEt2PU25 = (TH2F*)fPU25 -> Get("h_EtxVsSumEt2");

  //project Pt Vs SumEt (for sigma(Etx) vs PU, any sumEt), gaussian fit
  TH1D *EtxVsSumEt2SlicePU0 = EtxVsSumEt2PU0 -> ProjectionY("PU0");
  EtxVsSumEt2SlicePU0 -> Draw();
  TF1* f0 = new TF1("f0", "gaus", -50, 50);
  EtxVsSumEt2SlicePU0 -> Fit("f0");

  TH1D *EtxVsSumEt2SlicePU5 = EtxVsSumEt2PU5 -> ProjectionY("PU5");
  EtxVsSumEt2SlicePU5 -> Draw();
  TF1* f5 = new TF1("f5", "gaus", -50, 50);
  EtxVsSumEt2SlicePU0 -> Fit("f5");

  TH1D *EtxVsSumEt2SlicePU10 = EtxVsSumEt2PU10 -> ProjectionY("PU10");
  EtxVsSumEt2SlicePU10 -> Draw();
  TF1* f10 = new TF1("f10", "gaus", -50, 50);
  EtxVsSumEt2SlicePU10 -> Fit("f10");

  TH1D *EtxVsSumEt2SlicePU15 = EtxVsSumEt2PU15 -> ProjectionY("PU15");
  EtxVsSumEt2SlicePU15 -> Draw();
  TF1* f15 = new TF1("f15", "gaus", -50, 50);
  EtxVsSumEt2SlicePU15 -> Fit("f15");

  TH1D *EtxVsSumEt2SlicePU20 = EtxVsSumEt2PU20 -> ProjectionY("PU20");
  EtxVsSumEt2SlicePU20 -> Draw();
  TF1* f20 = new TF1("f20", "gaus", -50, 50);
  EtxVsSumEt0SlicePU20 -> Fit("f20");

  TH1D *EtxVsSumEt2SlicePU25 = EtxVsSumEt2PU25 -> ProjectionY("PU25");
  EtxVsSumEt2SlicePU25 -> Draw();
  TF1* f25 = new TF1("f25", "gaus", -50, 50);
  EtxVsSumEt2SlicePU25 -> Fit("f25");


  //put sigma from histo fits into TH2
  TH1D *SigmaEtxVsPU = new TH1D("SigmaEtx2VsPU", "sigma(Et,x) vs PU", 30, 0, 30);//, 20, 0, 20);
  SigmaEtx2VsPU -> Fill(0, f0  -> GetParameter(2));
  SigmaEtx2VsPU -> Fill(5, f5  -> GetParameter(2));
  SigmaEtx2VsPU -> Fill(10,f10 -> GetParameter(2));
  SigmaEtx2VsPU -> Fill(15,f15 -> GetParameter(2));
  SigmaEtx2VsPU -> Fill(20,f20 -> GetParameter(2));
  SigmaEtx2VsPU -> Fill(25,f25 -> GetParameter(2));

  SigmaEtx2VsPU -> SetBinError(1, f0  -> GetParError(2));
  SigmaEtx2VsPU -> SetBinError(6, f5  -> GetParError(2));
  SigmaEtx2VsPU -> SetBinError(11,f10 -> GetParError(2));
  SigmaEtx2VsPU -> SetBinError(16,f15 -> GetParError(2));
  SigmaEtx2VsPU -> SetBinError(21,f20 -> GetParError(2));
  SigmaEtx2VsPU -> SetBinError(26,f25 -> GetParError(2));

  //put the RMS from projected histo into TH2
  TH1D *RMSEtxVsPU = new TH1D("RMSEtx2VsPU", "RMS(Et,x) vs PU", 30, 0, 30);//, 20, 0, 20);
  RMSEtx2VsPU -> Fill(0, EtxVsSumEt2SlicePU0  -> GetRMS());
  RMSEtx2VsPU -> Fill(5, EtxVsSumEt2SlicePU5  -> GetRMS());
  RMSEtx2VsPU -> Fill(10,EtxVsSumEt2SlicePU10 -> GetRMS());
  RMSEtx2VsPU -> Fill(15,EtxVsSumEt2SlicePU15 -> GetRMS());
  RMSEtx2VsPU -> Fill(20,EtxVsSumEt2SlicePU20 -> GetRMS());
  RMSEtx2VsPU -> Fill(25,EtxVsSumEt2SlicePU25 -> GetRMS());

  RMSEtx2VsPU -> SetBinError(0,0.);// EtxVsSumEt2SlicePU0  -> GetRMSError(2));
  RMSEtx2VsPU -> SetBinError(5,0.);// EtxVsSumEt2SlicePU5  -> GetRMSError(2));
  RMSEtx2VsPU -> SetBinError(10,0.);//EtxVsSumEt2SlicePU10 -> GetRMSError(2));
  RMSEtx2VsPU -> SetBinError(15,0.);//EtxVsSumEt2SlicePU15 -> GetRMSError(2));
  RMSEtx2VsPU -> SetBinError(20,0.);//EtxVsSumEt2SlicePU20 -> GetRMSError(2));
  RMSEtx2VsPU -> SetBinError(25,0.);//EtxVsSumEt2SlicePU25 -> GetRMSError(2));
 




  /****draw all histos(= for all met types) in the same canvas***/
  //Draw sigma and RMS vs PU histos
  TCanvas *SigmaRMSVsPU = new TCanvas("SigmaRMSVsPU");
  SigmaRMSVsPU -> Divide(2,1);
  SigmaRMSVsPU -> cd(1);
  SigmaEtx0VsPU -> SetMarkerStyle(8);
  SigmaEtx0VsPU -> Draw();
  SigmaEtx1VsPU -> SetMarkerStyle(25);
  SigmaEtx1VsPU -> Draw("SAME");
  SigmaEtx2VsPU -> SetMarkerStyle(3);
  SigmaEtx2VsPU -> Draw("SAME");

  SigmaRMSVsPU  -> cd(2);
  RMSEtx0VsPU   -> SetMarkerStyle(8);
  RMSEtx0VsPU   -> Draw();
  RMSEtx1VsPU   -> SetMarkerStyle(25);
  RMSEtx1VsPU   -> Draw("SAME");
  RMSEtx2VsPU   -> SetMarkerStyle(3);
  RMSEtx2VsPU   -> Draw("SAME");
 
}




