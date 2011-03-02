#include <TFile.h>
#include <TKey.h>
#include <TH1F.h>


void checkPUNVtxMatch(){

  TFile *f0 = new TFile("../data/QCD_PU0.root");
  TH1D  *nrVtxPU0 = new TH1D("nrVtxPU0", "number of primary vertices", 50, 0 ,50);
  nrVtxPU0 -> SetFillColor(kBlue);
 
  TFile *f1 = new TFile("../data/QCD_PU5.root");
  TH1D  *nrVtxPU1 = new TH1D("nrVtxPU1", "number of primary vertices", 50, 0 ,50);
  nrVtxPU1 -> SetFillColor(kGreen);

  Events->Draw("recoVertexs_offlinePrimaryVertices__PROD.@obj.size()>>nrVtxPU1");
  Events->Draw("recoVertexs_offlinePrimaryVertices__PROD.@obj.size()>>nrVtxPU0", "SAME");

}
