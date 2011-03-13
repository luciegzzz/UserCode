#include <TFile.h>
#include <TKey.h>
#include <TH1D.h>
#include <TH2D.h>
#include <TCanvas.h>


void checkNvtxPUNVtxRecoMatch(){

  
  gROOT->Reset();
  gStyle->SetOptStat(0);
  gStyle->SetPalette(1);
  gStyle->SetCanvasColor(33);
  gStyle->SetFrameFillColor(18);
  
  
  TFile *f0       = TFile::Open("rfio:/castor/cern.ch/user/l/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_0_10_1_nzL.root");
  TH2I  *nrVtxPU0 = new TH2I("nrVtxPU0", "number of reco primary vertices vs nr of PU vertices", 50, 0 ,50, 50, 0, 50);
  nrVtxPU0 -> SetFillColor(46);
  Events->Draw("recoVertexs_offlinePrimaryVertices__PROD.@obj.size():edmHepMCProduct_famosPileUp_PileUpEvents_PROD.obj.GetEvent()->vertices_size()>>nrVtxPU0");
  nrVtxPU0 -> Draw("colz");


   TFile *f5       = TFile::Open("rfio:/castor/cern.ch/user/l/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_5_1_1_QY1.root");
   TH2I  *nrVtxPU5 = new TH2I("nrVtxPU5", "number of reco primary vertices vs nr of PU vertices", 50, 0 ,50, 50, 0, 50);
   Events->Draw("recoVertexs_offlinePrimaryVertices__PROD.@obj.size():edmHepMCProduct_famosPileUp_PileUpEvents_PROD.obj.GetEvent()->vertices_size()>>nrVtxPU5", "", "colz, SAME");
   //  nrVtxPU5 -> Draw("SAME");
   //   nrVtxPU5 -> Draw("colz");

   TFile *f10       = TFile::Open("rfio:/castor/cern.ch/user/l/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_10_10_1_JBm.root");
   TH2I  *nrVtxPU10 = new TH2I("nrVtxPU10", "number of reco primary vertices vs nr of PU vertices", 50, 0 ,50, 50, 0, 50);
   Events->Draw("recoVertexs_offlinePrimaryVertices__PROD.@obj.size():edmHepMCProduct_famosPileUp_PileUpEvents_PROD.obj.GetEvent()->vertices_size()>>nrVtxPU10", "", "colz, SAME");
   // nrVtxPU10 -> Draw("colz");

   TFile *f15       = TFile::Open("rfio:/castor/cern.ch/user/l/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_15_10_1_73S.root");
   TH2I  *nrVtxPU15 = new TH2I("nrVtxPU15", "number of reco primary vertices vs nr of PU vertices", 50, 0 ,50, 50, 0, 50);
   Events->Draw("recoVertexs_offlinePrimaryVertices__PROD.@obj.size():edmHepMCProduct_famosPileUp_PileUpEvents_PROD.obj.GetEvent()->vertices_size()>>nrVtxPU15", "", "colz, SAME");
   //  nrVtxPU15 -> Draw("colz");

   TFile *f20       = TFile::Open("rfio:/castor/cern.ch/user/l/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_20_1_1_ukd.root");
   TH2I  *nrVtxPU20 = new TH2I("nrVtxPU20", "number of reco primary vertices vs nr of PU vertices", 50, 0 ,50, 50, 0, 50);
   Events->Draw("recoVertexs_offlinePrimaryVertices__PROD.@obj.size():edmHepMCProduct_famosPileUp_PileUpEvents_PROD.obj.GetEvent()->vertices_size()>>nrVtxPU20", "", "colz, SAME");
   //  nrVtxPU20 -> Draw("colz");

   TFile *f25       = TFile::Open("rfio:/castor/cern.ch/user/l/lucieg/FastSimQCD/QCD_15-500/QCD_15-500_PU_25_1_1_dHO.root");
   TH2I  *nrVtxPU25 = new TH2I("nrVtxPU25", "number of reco primary vertices vs nr of PU vertices", 50, 0 ,50, 50, 0, 50);
   Events->Draw("recoVertexs_offlinePrimaryVertices__PROD.@obj.size():edmHepMCProduct_famosPileUp_PileUpEvents_PROD.obj.GetEvent()->vertices_size()>>nrVtxPU25", "", "colz, SAME");
   //nrVtxPU0 -> Draw("colz");

   TH2I  *nrVtxAllPU = new TH2I("nrVtxAllPU", "number of reco primary vertices vs nr of PU vertices", 50, 0 ,50, 50, 0, 50);
   nrVtxAllPU -> Add(nrVtxPU0);
   nrVtxAllPU -> Add(nrVtxPU5);
   nrVtxAllPU -> Add(nrVtxPU10);
   nrVtxAllPU -> Add(nrVtxPU15);
   nrVtxAllPU -> Add(nrVtxPU20);
   nrVtxAllPU -> Add(nrVtxPU25);
   nrVtxAllPU -> Draw("colz");
}
