// -*- C++ -*-
//
// Package:    METsAnalyzer
// Class:      METsAnalyzer
// 
/**\class METsAnalyzer METsAnalyzer.cc METs/METsAnalyzer/src/METsAnalyzer.cc

 Description: [one line class summary]

 Implementation:
     [Notes on implementation]
*/
//
// Original Author:  "Lucie Gauthier"
//         Created:  Fri Feb 11 03:43:43 CST 2011
// $Id: METsAnalyzer.cc,v 1.18 2011/03/23 10:54:54 lucieg Exp $
//
//

// user include files
#include "METsWithPU/METsAnalyzer/plugins/METsAnalyzer.h"
#include "Math/GenVector/PositionVector3D.h"

using namespace std;
using namespace edm;
using namespace reco;

//
// constructors and destructor
//
METsAnalyzer::METsAnalyzer(const edm::ParameterSet& iConfig)

{
  fOutputFileName_ = iConfig.getUntrackedParameter<string>("HistOutFile");
  
  inputTagMET_ 
    = iConfig.getParameter<InputTag>("met0");

  inputTagVertices_
    = iConfig.getParameter<InputTag>("vertices");

  inputTagGoodVertices_
    = iConfig.getParameter<InputTag>("goodVertices");

  inputType_
     = iConfig.getUntrackedParameter<string>("inputType");

}


METsAnalyzer::~METsAnalyzer()
{

}


//
// member functions
//
// ------------ pSetup called once each job just before starting event loop  ------------
void 
METsAnalyzer::beginJob()
{
  //Create output file                                                                                                                                                     
  outputFile_ = new TFile( fOutputFileName_.c_str(), "RECREATE" );

  //histograms definition                                                                                                                                 
  h_nRecoVertices_            = new TH1I("h_nRecoVertices", "nr of reco PV", 25, 0, 25);
  h_nGoodRecoVertices_        = new TH1I("h_nGoodRecoVertices", "nr of good reco PV", 25, 0, 25);
  h_nPUVertices_              = new TH1I("h_nPUVertices", "nr of PU vertices", 25, 0, 25);
  h_nRecoVtcesVsnPUVtces_     = new TH2D("h_nrecoVtcesVsnPUVtces", "nr of reco vertices vs nr of PU vertices", 50, 0, 50, 50, 0, 50);
  h_nGoodRecoVtcesVsnPUVtces_ = new TH2D("h_ngoodRecoVtcesVsnPUVtces", "nr of good reco vertices vs nr of PU vertices", 50, 0, 50, 50, 0, 50);

  /*****TH1 Pt histo *******/                 
  h_METPtVsNPU_              = new TH2D("h_METPtVsNPU","MET Pt(GeV) vs NPU",30 ,0, 30, 100, 0, 100);
  h_METPtxVsNPU_             = new TH2D("h_METPtxVsNPU","MET Ptx(GeV) vs NPU",30 ,0, 30, 100,-50, 50);
  h_METPtxVsNPV_             = new TH2D("h_METPtxVsNPV","MET Ptx(GeV) vs NPV",30 ,0, 30, 100,-50, 50);
  h_METPtxVsNGPV_            = new TH2D("h_METPtxVsNGPV","MET Ptx(GeV) vs NGPV",30 ,0, 30, 100,-50, 50);
  h_METPtyVsNPU_             = new TH2D("h_METPtyVsNPU","MET Pty(GeV) vs NPU",30 ,0, 30, 100,-50, 50);


  /*****TH2 res...histo******/
  for (int i = 0; i < 20 ; i++){
    TString histoNamePUV = TString::Format("h_EtxVsSumEtPUV_%d", i);
    TH2D *h_EtxVsSumEtDummyPUV_ = new TH2D(histoNamePUV, "Et,x vs sumEt, PUV", 500, 0, 2000, 50, -50, 50);
    h_EtxVsSumEtPUV_.push_back(h_EtxVsSumEtDummyPUV_);

    TString histoNamePV = TString::Format("h_EtxVsSumEtPV_%d", i);
    TH2D *h_EtxVsSumEtDummyPV_ = new TH2D(histoNamePV, "Et,x vs sumEt, PV", 500, 0, 2000, 50, -50, 50);
    h_EtxVsSumEtPV_.push_back(h_EtxVsSumEtDummyPV_);
    
    TString histoNameGPV = TString::Format("h_EtxVsSumEt_%d", i);
    TH2D *h_EtxVsSumEtDummyGPV_ = new TH2D(histoNameGPV, "Et,x vs sumEt, GPV", 500, 0, 2000, 50, -50, 50);
    h_EtxVsSumEtGPV_.push_back(h_EtxVsSumEtDummyGPV_);
  }

 //  for (int i = 0; i < 20 ; i++){
//     TString histoName = TString::Format("h_EtyVsSumEt0_%d", i);
//     TH2D *h_EtyVsSumEt0Dummy_ = new TH2D(histoName, "Et,y vs sumEt caloMet vs NPU", 500, 0, 2000, 50, -50, 50);
//     h_EtyVsSumEt_.push_back(h_EtyVsSumEt0Dummy_);
//   }
}

// ------------ method called to for each event  ------------
void
METsAnalyzer::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{

  /*****get Vertices collections and fill vertices (only) histograms******/

  //reco PV 
  Handle<VertexCollection> vertices;  
  iEvent.getByLabel(inputTagVertices_, vertices);
  int nVertices      = vertices -> size();
  h_nRecoVertices_   -> Fill(nVertices);
 
  // good reco PV (!isFake && ndof >4 && abs(z)<25 and position.Rho()<2)
  Handle<VertexCollection> goodVertices;  
  iEvent.getByLabel(inputTagVertices_, goodVertices);
  int nGoodVertices   = goodVertices -> size();
  h_nGoodRecoVertices_-> Fill(nGoodVertices);
 
  //PU vertices
  int nPUVertices = -10;

  if (inputType_ == "FastSim"){
    Handle<edm::HepMCProduct> pileUpSource;
    iEvent.getByLabel("famosPileUp", "PileUpEvents", pileUpSource);
    nPUVertices       = (pileUpSource -> GetEvent()) -> vertices_size();
    h_nPUVertices_    -> Fill(nPUVertices);
  }

  else if (inputType_ == "MCOfficial"){
    //num PU vertices
    Handle<PileupSummaryInfo> pileUpSource;
    iEvent.getByLabel("addPileupInfo", pileUpSource);
    nPUVertices       = pileUpSource -> getPU_NumInteractions();
    h_nPUVertices_    -> Fill(nPUVertices);

    //
     }

  if (nPUVertices == -10) {
    cout << "failed to get NPU vertices !!!\n";
  }

  //nreco PV vs n PU vertices histo
  TH2D *h_nRecoVtcesVsnPUVtcesTemp = new TH2D("h_nRecoVtcesVsnPUVtcesTemp", "nhtemp", 50, 0, 50, 50, 0, 50);
  h_nRecoVtcesVsnPUVtcesTemp -> Fill(nPUVertices,nVertices);
  h_nRecoVtcesVsnPUVtces_ -> Add(h_nRecoVtcesVsnPUVtcesTemp);
  
  //n good reco PV vs n PU vertices histo
  TH2D *h_nGoodRecoVtcesVsnPUVtcesTemp = new TH2D("h_nGoodRecoVtcesVsnPUVtcesTemp", "nhtemp", 50, 0, 50, 50, 0, 50);
  h_nGoodRecoVtcesVsnPUVtcesTemp -> Fill(nPUVertices,nGoodVertices);
  h_nGoodRecoVtcesVsnPUVtces_ -> Add(h_nGoodRecoVtcesVsnPUVtcesTemp);

 /*****get MET collections *- might be more flexible with patmets ?******/
  Handle<PFMETCollection> metColl;
  iEvent.getByLabel(inputTagMET_, metColl);
  PFMETCollection::const_iterator met = metColl -> begin();

  //Pt
  h_METPtVsNPU_      -> Fill(nPUVertices, met->pt());

  //Pt, x
  h_METPtxVsNPU_     -> Fill(nPUVertices, met->px());

  h_METPtxVsNPV_     -> Fill(nVertices, met->px());

  h_METPtxVsNGPV_    -> Fill(nGoodVertices, met->px());

  //Pt, y
  h_METPtyVsNPU_     -> Fill(nPUVertices, met->py());

  //bool fillEtSumEt = 1 - (nPUVertices % 5);

  //if (fillEtSumEt && ((nPUVertices/5) < 6)){

  if (nPUVertices < 20){
    h_EtxVsSumEtPUV_[nPUVertices] -> Fill(met->sumEt(), met->px());
    h_EtxVsSumEtPV_[nPUVertices] -> Fill(met->sumEt(), met->px());
    h_EtxVsSumEtGPV_[nPUVertices] -> Fill(met->sumEt(), met->px());
  }



}

// ------------ method called once each job just after ending the event loop  ------------
void 
METsAnalyzer::endJob() {
  outputFile_->cd();

  h_nRecoVertices_            -> Write();
  h_nGoodRecoVertices_        -> Write();
  h_nPUVertices_              -> Write();
  h_nRecoVtcesVsnPUVtces_     -> Write();
  h_nGoodRecoVtcesVsnPUVtces_ -> Write();

  h_METPtVsNPU_              -> Write();
  h_METPtxVsNPU_             -> Write();
  h_METPtxVsNPV_             -> Write();
  h_METPtxVsNGPV_            -> Write();
  h_METPtyVsNPU_             -> Write();

  for (unsigned int i = 0 ; i < h_EtxVsSumEtPUV_.size() ; i++){
    h_EtxVsSumEtPUV_[i]   -> Write();
    h_EtxVsSumEtPV_[i]    -> Write();
    h_EtxVsSumEtGPV_[i]   -> Write();
  }

//   for (unsigned int i = 0 ; i < h_EtxVsSumEt_.size() ; i++){
//     h_EtyVsSumEtPUV_[i]   -> Write();
//     h_EtyVsSumEtPV_[i]    -> Write();
//     h_EtyVsSumEtGPV_[i]   -> Write();
//   }


}

//define this as a plug-in
DEFINE_FWK_MODULE(METsAnalyzer);
