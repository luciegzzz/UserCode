/*
This macro takes the Pt, x vs SumEt distributions (output of metsanalyzer, saved in plotsPUX.root), calculates sigmaGauss(Et,x) for sumEt slices, for different PU (= average # of PU as generated with FastSim), for met 0, 1 and 2 (currently CaloMet, PFMet, PFMet w/o PU)
Ptx vs SumEt distributions are drawn, and sigma(Et,x) vs sumEt is drawn - one canvas per met type, all PU on the same canvas
*/
{

  //get TH2Analyzer (maybe more :) ) /CMSSW/Validation/RecoParticleFlow/interface & src
  gSystem->Load("libValidationRecoParticleFlow.so");

  //get Pt distributions files
  TFile *fPU0       =  TFile::Open("plotsPU0.root");
  TFile *fPU5       =  TFile::Open("plotsPU5.root");
  TFile *fPU10      =  TFile::Open("plotsPU10.root");
  TFile *fPU15      =  TFile::Open("plotsPU15.root");
  TFile *fPU20      =  TFile::Open("plotsPU20.root");
  TFile *fPU25      =  TFile::Open("plotsPU25.root");

  /*****met 0******/
  TCanvas *CaloEtxVsSumEt = new TCanvas("CaloEtxVsSumEt");
  CaloEtxVsSumEt -> Divide(3,2);

  //get Pt,x vs SumEt histo for met 0, drawn into

  TH2F *EtxVsSumEt0PU0  = (TH2F*)fPU0  -> Get("h_EtxVsSumEt0");
  CaloEtxVsSumEt -> cd(1);
  EtxVsSumEt0PU0->Draw();
  TH2F *EtxVsSumEt0PU5  = (TH2F*)fPU5  -> Get("h_EtxVsSumEt0");
  CaloEtxVsSumEt -> cd(2);
  EtxVsSumEt0PU5->Draw();
  TH2F *EtxVsSumEt0PU10 = (TH2F*)fPU10 -> Get("h_EtxVsSumEt0");
  CaloEtxVsSumEt -> cd(3);
  EtxVsSumEt0PU10->Draw();
  TH2F *EtxVsSumEt0PU15 = (TH2F*)fPU15 -> Get("h_EtxVsSumEt0");
  CaloEtxVsSumEt -> cd(4);
  EtxVsSumEt0PU15->Draw();
  TH2F *EtxVsSumEt0PU20 = (TH2F*)fPU20 -> Get("h_EtxVsSumEt0");
  CaloEtxVsSumEt -> cd(5);
  EtxVsSumEt0PU20->Draw();
  TH2F *EtxVsSumEt0PU25 = (TH2F*)fPU25 -> Get("h_EtxVsSumEt0");
  CaloEtxVsSumEt -> cd(6);
  EtxVsSumEt0PU25->Draw();

  //calculate sigmaGauss(Et,x) for sumEt bins
  TCanvas *CaloSigmaEtxVsSumEt = new TCanvas("CaloSigmaEtxVsSumEt");
 
  TH2Analyzer EtxVsSumEt0PU0_ana(EtxVsSumEt0PU0, 50, 200, 20, true);
  TH2Analyzer EtxVsSumEt0PU5_ana(EtxVsSumEt0PU5, 50, 200, 20, true);
  TH2Analyzer EtxVsSumEt0PU10_ana(EtxVsSumEt0PU10, 50, 200, 20, true);
  TH2Analyzer EtxVsSumEt0PU15_ana(EtxVsSumEt0PU15, 50, 200, 20, true);
  TH2Analyzer EtxVsSumEt0PU20_ana(EtxVsSumEt0PU20, 50, 200, 20, true);
  TH2Analyzer EtxVsSumEt0PU25_ana(EtxVsSumEt0PU25, 50, 200, 20, true);

  CaloSigmaEtxVsSumEt -> cd();
  EtxVsSumEt0PU0_ana.SigmaGauss()-> SetMarkerStyle(8);
  EtxVsSumEt0PU0_ana.SigmaGauss()-> Draw();
  EtxVsSumEt0PU5_ana.SigmaGauss()-> SetMarkerStyle(24);
  EtxVsSumEt0PU5_ana.SigmaGauss()-> Draw("SAME");
  EtxVsSumEt0PU10_ana.SigmaGauss()-> SetMarkerStyle(30);
  EtxVsSumEt0PU10_ana.SigmaGauss()->Draw("SAME");
  EtxVsSumEt0PU15_ana.SigmaGauss()->Draw("SAME");
  EtxVsSumEt0PU20_ana.SigmaGauss()->Draw("SAME");
  EtxVsSumEt0PU25_ana.SigmaGauss()->Draw("SAME");



  /************met1******************/

  TCanvas *PFEtxVsSumEt = new TCanvas("PFEtxVsSumEt");
  PFEtxVsSumEt -> Divide(3,2);

  //get Pt,x vs SumEt histo for met 0 

  TH2F *EtxVsSumEt1PU0  = (TH2F*)fPU0  -> Get("h_EtxVsSumEt1");
  PFEtxVsSumEt -> cd(1);
  EtxVsSumEt1PU0->Draw();
  TH2F *EtxVsSumEt1PU5  = (TH2F*)fPU5  -> Get("h_EtxVsSumEt1");
  PFEtxVsSumEt -> cd(2);
  EtxVsSumEt1PU5->Draw();
  TH2F *EtxVsSumEt1PU10 = (TH2F*)fPU10 -> Get("h_EtxVsSumEt1");
  PFEtxVsSumEt -> cd(3);
  EtxVsSumEt1PU10->Draw();
  TH2F *EtxVsSumEt1PU15 = (TH2F*)fPU15 -> Get("h_EtxVsSumEt1");
  PFEtxVsSumEt -> cd(4);
  EtxVsSumEt1PU15->Draw();
  TH2F *EtxVsSumEt1PU20 = (TH2F*)fPU20 -> Get("h_EtxVsSumEt1");
  PFEtxVsSumEt -> cd(5);
  EtxVsSumEt1PU20->Draw();
  TH2F *EtxVsSumEt1PU25 = (TH2F*)fPU25 -> Get("h_EtxVsSumEt1");
  PFEtxVsSumEt -> cd(6);
  EtxVsSumEt1PU25->Draw();

  TCanvas *PFSigmaEtxVsSumEt = new TCanvas("PFSigmaEtxVsSumEt");
 
  TH2Analyzer EtxVsSumEt1PU0_ana(EtxVsSumEt1PU0, 50, 200, 20, true);
  TH2Analyzer EtxVsSumEt1PU5_ana(EtxVsSumEt1PU5, 50, 200, 20, true);
  TH2Analyzer EtxVsSumEt1PU10_ana(EtxVsSumEt1PU10, 50, 200, 20, true);
  TH2Analyzer EtxVsSumEt1PU15_ana(EtxVsSumEt1PU15, 50, 200, 20, true);
  TH2Analyzer EtxVsSumEt1PU20_ana(EtxVsSumEt1PU20, 50, 200, 20, true);
  TH2Analyzer EtxVsSumEt1PU25_ana(EtxVsSumEt1PU25, 50, 200, 20, true);

  PFSigmaEtxVsSumEt -> cd();
  EtxVsSumEt1PU0_ana.SigmaGauss()-> SetMarkerStyle(8);
  EtxVsSumEt1PU0_ana.SigmaGauss()-> Draw();
  EtxVsSumEt1PU5_ana.SigmaGauss()-> SetMarkerStyle(24);
  EtxVsSumEt1PU5_ana.SigmaGauss()-> Draw("SAME");
  EtxVsSumEt1PU10_ana.SigmaGauss()-> SetMarkerStyle(30);
  EtxVsSumEt1PU10_ana.SigmaGauss()->Draw("SAME");
  EtxVsSumEt1PU15_ana.SigmaGauss()->Draw("SAME");
  EtxVsSumEt1PU20_ana.SigmaGauss()->Draw("SAME");
  EtxVsSumEt1PU25_ana.SigmaGauss()->Draw("SAME");


  /************met2******************/
  TCanvas *PFNPUEtxVsSumEt = new TCanvas("PFNPUEtxVsSumEt");
  PFNPUEtxVsSumEt -> Divide(3,2);

  //get Pt,x vs SumEt histo for met 0 

  TH2F *EtxVsSumEt2PU0  = (TH2F*)fPU0  -> Get("h_EtxVsSumEt2");
  PFNPUEtxVsSumEt -> cd(1);
  EtxVsSumEt2PU0->Draw();
  TH2F *EtxVsSumEt2PU5  = (TH2F*)fPU5  -> Get("h_EtxVsSumEt2");
  PFNPUEtxVsSumEt -> cd(2);
  EtxVsSumEt2PU5->Draw();
  TH2F *EtxVsSumEt2PU10 = (TH2F*)fPU10 -> Get("h_EtxVsSumEt2");
  PFNPUEtxVsSumEt -> cd(3);
  EtxVsSumEt2PU10->Draw();
  TH2F *EtxVsSumEt2PU15 = (TH2F*)fPU15 -> Get("h_EtxVsSumEt2");
  PFNPUEtxVsSumEt -> cd(4);
  EtxVsSumEt2PU15->Draw();
  TH2F *EtxVsSumEt2PU20 = (TH2F*)fPU20 -> Get("h_EtxVsSumEt2");
  PFNPUEtxVsSumEt -> cd(5);
  EtxVsSumEt2PU20->Draw();
  TH2F *EtxVsSumEt2PU25 = (TH2F*)fPU25 -> Get("h_EtxVsSumEt2");
  PFNPUEtxVsSumEt -> cd(6);
  EtxVsSumEt2PU25->Draw();

  TCanvas *PFNPUSigmaEtxVsSumEt = new TCanvas("PFNPUSigmaEtxVsSumEt");
 
  TH2Analyzer EtxVsSumEt2PU0_ana(EtxVsSumEt2PU0, 50, 200, 20, true);
  TH2Analyzer EtxVsSumEt2PU5_ana(EtxVsSumEt2PU5, 50, 200, 20, true);
  TH2Analyzer EtxVsSumEt2PU10_ana(EtxVsSumEt2PU10, 50, 200, 20, true);
  TH2Analyzer EtxVsSumEt2PU15_ana(EtxVsSumEt2PU15, 50, 200, 20, true);
  TH2Analyzer EtxVsSumEt2PU20_ana(EtxVsSumEt2PU20, 50, 200, 20, true);
  TH2Analyzer EtxVsSumEt2PU25_ana(EtxVsSumEt2PU25, 50, 200, 20, true);

  PFNPUSigmaEtxVsSumEt -> cd();
  EtxVsSumEt2PU0_ana.SigmaGauss()-> SetMarkerStyle(8);
  EtxVsSumEt2PU0_ana.SigmaGauss()-> Draw();
  EtxVsSumEt2PU5_ana.SigmaGauss()-> SetMarkerStyle(24);
  EtxVsSumEt2PU5_ana.SigmaGauss()-> Draw("SAME");
  EtxVsSumEt2PU10_ana.SigmaGauss()-> SetMarkerStyle(30);
  EtxVsSumEt2PU10_ana.SigmaGauss()->Draw("SAME");
  EtxVsSumEt2PU15_ana.SigmaGauss()->Draw("SAME");
  EtxVsSumEt2PU20_ana.SigmaGauss()->Draw("SAME");
  EtxVsSumEt2PU25_ana.SigmaGauss()->Draw("SAME");

}




