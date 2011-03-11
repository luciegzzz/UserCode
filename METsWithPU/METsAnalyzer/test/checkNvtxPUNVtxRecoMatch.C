#include <TFile.h>
#include <TKey.h>
#include <TH1D.h>
#include <TH2D.h>
#include <TCanvas.h>


void checkPUNVtxMatch(){

  gStyle->SetOptStat(1111111);

  //  TFile *f0 = new TFile("../data/QCD_PU0.root");

  TH2D *maxEntriesVsNVTxPU  = new TH2D("maxEntriesVsNvtxPU", "number of primary vertices with max entries vs pile-up nr of PU vertices", 30, 0, 30, 20, 0, 20);
  TH2D *meanVsNVtxPU        = new TH2D("meanVsNvtxPU", "mean number of primary vertices vs nr of pile-up vertices", 30, 0, 30, 20, 0, 20);

  //  TCanvas *c = new TCanvas("c");//line to comment/uncomment depending on root complaining that meanVsPU doesn't exist

  TFile *f0       = TFile::Open("rfio:/castor/cern.ch/user/l/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_0_10_1_nzL.root");
  TH2D  *nrVtxPU0 = new TH2D("nrVtxPU0", "number of reco primary vertices vs nr of PU vertices", 30, 0 ,30, 30, 0, 30);
  Events->Draw("recoVertexs_offlinePrimaryVertices__PROD.@obj.size():edmHepMCProduct_famosPileUp_PileUpEvents_PROD.obj.GetEvent()->vertices_size()>>nrVtxPU0");


  TFile *f5       = TFile::Open("rfio:/castor/cern.ch/user/l/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_5_1_1_QY1.root");
  //TH2D  *nrVtxPU5 = new TH2D("nrVtxPU5", "number of reco primary vertices vs nr of PU vertices", 30, 0 ,30, 30, 0, 30);
  Events->Draw("recoVertexs_offlinePrimaryVertices__PROD.@obj.size():edmHepMCProduct_famosPileUp_PileUpEvents_PROD.obj.GetEvent()->vertices_size()", "", "SAME");



//   TFile *f5       =  TFile::Open("rfio:/castor/cern.ch/user/l/lucieg/FastSimQCD/QCD_80-120_PU_5_1_1_Khx.root");
//   TH1D  *nrVtxPU5 = new TH1D("nrVtxPU5", "number of primary vertices", 30, 0 ,30);
//   nrVtxPU5        -> SetFillColor(kBlue);
//   Events->Draw("recoVertexs_offlinePrimaryVertices__PROD.@obj.size()>>nrVtxPU5", "", "SAME");
//   meanVsPU        -> Fill(5, nrVtxPU5 -> GetMean());
//   maxEntriesVsPU  -> Fill(5, nrVtxPU5 -> GetMaximumBin());


// //   TFile *f10       =  TFile::Open("rfio:/castor/cern.ch/user/l/lucieg/FastSimQCD/QCD_80-120_PU_10_5_1_1eC.root");
// //   TH1D  *nrVtxPU10 = new TH1D("nrVtxPU10", "number of primary vertices", 30, 0 ,30);
// //   nrVtxPU10       -> SetFillColor(kBlue);
// //   Events->Draw("recoVertexs_offlinePrimaryVertices__PROD.@obj.size()>>nrVtxPU10", "", "SAME");
// //   meanVsPU        -> Fill(10, nrVtxPU10 -> GetMean());
// //   maxEntriesVsPU  -> Fill(10, nrVtxPU10 -> GetMaximumBin());


//   TFile *f15       =  TFile::Open("rfio:/castor/cern.ch/user/l/lucieg/FastSimQCD/QCD_80-120_PU_15_1_1_fc8.root");
//   TH1D  *nrVtxPU15 = new TH1D("nrVtxPU15", "number of primary vertices", 30, 0 ,30);
//   nrVtxPU15       -> SetFillColor(kBlue);
//   Events->Draw("recoVertexs_offlinePrimaryVertices__PROD.@obj.size()>>nrVtxPU15", "", "SAME");
//   meanVsPU        -> Fill(15, nrVtxPU15 -> GetMean());
//   maxEntriesVsPU  -> Fill(15, nrVtxPU15 -> GetMaximumBin());


//   TFile *f20       =  TFile::Open("rfio:/castor/cern.ch/user/l/lucieg/FastSimQCD/QCD_80-120_PU_20_1_1_LoH.root");
//   TH1D  *nrVtxPU20 = new TH1D("nrVtxPU20", "number of primary vertices", 30, 0 ,30);
//   nrVtxPU20       -> SetFillColor(kBlue);
//   Events->Draw("recoVertexs_offlinePrimaryVertices__PROD.@obj.size()>>nrVtxPU20", "", "SAME");
//   meanVsPU        -> Fill(20, nrVtxPU20 -> GetMean());
//   maxEntriesVsPU  -> Fill(20, nrVtxPU20 -> GetMaximumBin());


//   TFile *f25       =  TFile::Open("rfio:/castor/cern.ch/user/l/lucieg/FastSimQCD/QCD_80-120_PU_25_1_1_Cal.root");
//   TH1D  *nrVtxPU25 = new TH1D("nrVtxPU25", "number of primary vertices", 30, 0 ,30);
//   nrVtxPU25       -> SetFillColor(kBlue);
//   nrVtxPU25       -> SetMaximum(200.);
//   Events -> Draw("recoVertexs_offlinePrimaryVertices__PROD.@obj.size()>>nrVtxPU25", "", "SAME");
//   meanVsPU        -> Fill(25, nrVtxPU25 -> GetMean());
//   maxEntriesVsPU  -> Fill(25, nrVtxPU25 -> GetMaximumBin());



//   TCanvas *nrPV = new TCanvas("nrPV");
//   nrPV -> Divide(2, 3);

//   nrPV -> cd(1);
//   nrVtxPU0 -> Draw();

//   nrPV -> cd(2);
//   nrVtxPU5 -> SetMaximum(200);
//   nrVtxPU5 -> Draw();

//  //  nrPV -> cd(3);
// //   nrVtxPU10 -> SetMaximum(200);
// //   nrVtxPU10 -> Draw();

//   nrPV -> cd(4);
//   nrVtxPU15 -> SetMaximum(200);
//   nrVtxPU15 -> Draw();

//   nrPV -> cd(5);
//   nrVtxPU20 -> SetMaximum(200);
//   nrVtxPU20 -> Draw();

//   nrPV -> cd(6);
//   nrVtxPU25 -> SetMaximum(200);
//   nrVtxPU25 -> Draw();

//   TCanvas *entriesVsPU = new TCanvas("entriesVsPU");
//   entriesVsPU         -> cd();
//   entriesVsPU         -> Divide(2,1);
//   entriesVsPU         -> cd(1);
//   maxEntriesVsPU      -> SetMarkerStyle(8);
//   maxEntriesVsPU      -> Draw();
//   entriesVsPU         -> cd(2);
//   meanVsPU            -> SetMarkerStyle(8);
//   meanVsPU            -> Draw();

}
