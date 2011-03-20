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
// $Id: METsAnalyzer.cc,v 1.16 2011/03/16 21:36:35 lucieg Exp $
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
  
  inputTagMET0_ 
    = iConfig.getParameter<InputTag>("met0");

  inputTagMET1_
    = iConfig.getParameter<InputTag>("met1");

  inputTagMET2_
    = iConfig.getParameter<InputTag>("met2");

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
  h_MET0PtVsNPU_              = new TH2D("h_MET0PtVsNPU","MET0 Pt(GeV) vs NPU",30 ,0, 30, 100, 0, 100);
  h_MET1PtVsNPU_              = new TH2D("h_MET1PtVsNPU","MET1 Pt(GeV) vs NPU",30 ,0, 30, 100, 0, 100);
  h_MET2PtVsNPU_              = new TH2D("h_MET2PtVsNPU","MET2 Pt(GeV) vs NPU",30 ,0, 30, 100, 0, 100);

  h_MET0PtxVsNPU_             = new TH2D("h_MET0PtxVsNPU","MET0 Ptx(GeV) vs NPU",30 ,0, 30, 100,-50, 50);
  h_MET1PtxVsNPU_             = new TH2D("h_MET1PtxVsNPU","MET1 Ptx(GeV) vs NPU",30 ,0, 30, 100,-50, 50);
  h_MET2PtxVsNPU_             = new TH2D("h_MET2PtxVsNPU","MET2 Ptx(GeV) vs NPU",30 ,0, 30, 100,-50, 50);

  h_MET0PtxVsNPV_             = new TH2D("h_MET0PtxVsNPV","MET0 Ptx(GeV) vs NPV",30 ,0, 30, 100,-50, 50);
  h_MET1PtxVsNPV_             = new TH2D("h_MET1PtxVsNPV","MET1 Ptx(GeV) vs NPV",30 ,0, 30, 100,-50, 50);
  h_MET2PtxVsNPV_             = new TH2D("h_MET2PtxVsNPV","MET2 Ptx(GeV) vs NPV",30 ,0, 30, 100,-50, 50);

  h_MET0PtxVsNGPV_            = new TH2D("h_MET0PtxVsNGPV","MET0 Ptx(GeV) vs NGPV",30 ,0, 30, 100,-50, 50);
  h_MET1PtxVsNGPV_            = new TH2D("h_MET1PtxVsNGPV","MET1 Ptx(GeV) vs NGPV",30 ,0, 30, 100,-50, 50);
  h_MET2PtxVsNGPV_            = new TH2D("h_MET2PtxVsNGPV","MET2 Ptx(GeV) vs NGPV",30 ,0, 30, 100,-50, 50);

  h_MET0PtyVsNPU_            = new TH2D("h_MET0PtyVsNPU","MET0 Pty(GeV) vs NPU",30 ,0, 30, 100,-50, 50);
  h_MET1PtyVsNPU_            = new TH2D("h_MET1PtyVsNPU","MET1 Pty(GeV) vs NPU",30 ,0, 30, 100,-50, 50);
  h_MET2PtyVsNPU_            = new TH2D("h_MET2PtyVsNPU","MET2 Pty(GeV) vs NPU",30 ,0, 30, 100,-50, 50);


  /*****TH2 res...histo******/
  for (int i = 0; i < 20 ; i++){
    TString histoName = TString::Format("h_EtxVsSumEt0_%d", i);
    TH2D *h_EtxVsSumEt0Dummy_ = new TH2D(histoName, "Et,x vs sumEt caloMet vs NPU", 500, 0, 1000, 50, -50, 50);
    h_EtxVsSumEt0_.push_back(h_EtxVsSumEt0Dummy_);
  }

  for (int i = 0; i < 20 ; i++){
    TString histoName = TString::Format("h_EtyVsSumEt0_%d", i);
    TH2D *h_EtyVsSumEt0Dummy_ = new TH2D(histoName, "Et,y vs sumEt caloMet vs NPU", 500, 0, 1000, 50, -50, 50);
    h_EtyVsSumEt0_.push_back(h_EtyVsSumEt0Dummy_);
  }

 for (int i = 0; i < 20 ; i++){
    TString histoName = TString::Format("h_EtxVsSumEt1_%d", i);
    TH2D *h_EtxVsSumEt1Dummy_ = new TH2D(histoName, "Et,x vs sumEt pfMet vs NPU", 500, 0, 1000, 50, -50, 50);
    h_EtxVsSumEt1_.push_back(h_EtxVsSumEt1Dummy_);
  }

  for (int i = 0; i < 20 ; i++){
    TString histoName = TString::Format("h_EtyVsSumEt1_%d", i);
    TH2D *h_EtyVsSumEt1Dummy_ = new TH2D(histoName, "Et,y vs sumEt pfMet vs NPU", 500, 0, 1000, 50, -50, 50);
    h_EtyVsSumEt1_.push_back(h_EtyVsSumEt1Dummy_);
  }

 for (int i = 0; i < 20 ; i++){
    TString histoName = TString::Format("h_EtxVsSumEt2_%d", i);
    TH2D *h_EtxVsSumEt2Dummy_ = new TH2D(histoName, "Et,x vs sumEt pfMetNoPileUp vs NPU", 500, 0, 1000, 50, -50, 50);
    h_EtxVsSumEt2_.push_back(h_EtxVsSumEt2Dummy_);
  }

  for (int i = 0; i < 20 ; i++){
    TString histoName = TString::Format("h_EtyVsSumEt2_%d", i);
    TH2D *h_EtyVsSumEt2Dummy_ = new TH2D(histoName, "Et,y vs sumEt pfMetNoPileUp vs NPU", 500, 0, 1000, 50, -50, 50);
    h_EtyVsSumEt2_.push_back(h_EtyVsSumEt2Dummy_);
  }

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
  Handle<CaloMETCollection> met0Coll;
  iEvent.getByLabel(inputTagMET0_, met0Coll);
  CaloMETCollection::const_iterator met0 = met0Coll -> begin();

  Handle<PFMETCollection> met1Coll;
  iEvent.getByLabel(inputTagMET1_, met1Coll);
  PFMETCollection::const_iterator met1 = met1Coll -> begin();

  Handle<PFMETCollection> met2Coll;
  iEvent.getByLabel(inputTagMET2_, met2Coll);
  PFMETCollection::const_iterator met2 = met2Coll -> begin();

  //Pt
  h_MET0PtVsNPU_      -> Fill(nPUVertices, met0->pt());
  h_MET1PtVsNPU_      -> Fill(nPUVertices, met1->pt());
  h_MET2PtVsNPU_      -> Fill(nPUVertices, met2->pt());

  //Pt, x
  h_MET0PtxVsNPU_     -> Fill(nPUVertices, met0->px());
  h_MET1PtxVsNPU_     -> Fill(nPUVertices, met1->px());
  h_MET2PtxVsNPU_     -> Fill(nPUVertices, met2->px());

  h_MET0PtxVsNPV_     -> Fill(nVertices, met0->px());
  h_MET1PtxVsNPV_     -> Fill(nVertices, met1->px());
  h_MET2PtxVsNPV_     -> Fill(nVertices, met2->px());

  h_MET0PtxVsNGPV_    -> Fill(nGoodVertices, met0->px());
  h_MET1PtxVsNGPV_    -> Fill(nGoodVertices, met1->px());
  h_MET2PtxVsNGPV_    -> Fill(nGoodVertices, met2->px());

  //Pt, y
  h_MET0PtyVsNPU_     -> Fill(nPUVertices, met0->py());
  h_MET1PtyVsNPU_     -> Fill(nPUVertices, met1->py());
  h_MET2PtyVsNPU_     -> Fill(nPUVertices, met2->py());

  //bool fillEtSumEt = 1 - (nPUVertices % 5);

  //if (fillEtSumEt && ((nPUVertices/5) < 6)){

  if (nPUVertices < 20){
    double binContent = h_EtxVsSumEt0_[nPUVertices] -> GetBinContent(met0->sumEt(), met0->px()); 
    h_EtxVsSumEt0_[nPUVertices] -> Fill(met1->sumEt(), met0->px(), binContent + 1.);

    binContent = -10;
    binContent = h_EtyVsSumEt0_[nPUVertices] -> GetBinContent(met0->sumEt(), met0->py());
    h_EtyVsSumEt0_[nPUVertices] -> Fill(met1->sumEt(), met0->py(), binContent + 1.);
 
    binContent = -10;
    binContent = h_EtxVsSumEt1_[nPUVertices] -> GetBinContent(met1->sumEt(), met1->px());
    h_EtxVsSumEt1_[nPUVertices] -> Fill(met1->sumEt(), met1->px(), binContent + 1.);

    binContent = -10;
    binContent = h_EtyVsSumEt1_[nPUVertices] -> GetBinContent(met1->sumEt(), met1->py());
    h_EtyVsSumEt1_[nPUVertices] -> Fill(met1->sumEt(), met1->py(), binContent + 1.);

    binContent = -10;
    binContent = h_EtxVsSumEt2_[nPUVertices] -> GetBinContent(met2->sumEt(), met2->px());
    h_EtxVsSumEt2_[nPUVertices] -> Fill(met1->sumEt(), met2->px(), binContent + 1.);

    binContent = -10;
    binContent = h_EtyVsSumEt2_[nPUVertices] -> GetBinContent(met2->sumEt(), met2->py());
    h_EtyVsSumEt2_[nPUVertices] -> Fill(met1->sumEt(), met2->py(), binContent + 1.);
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

  h_MET0PtVsNPU_              -> Write();
  h_MET1PtVsNPU_              -> Write();
  h_MET2PtVsNPU_              -> Write();

  h_MET0PtxVsNPU_             -> Write();
  h_MET1PtxVsNPU_             -> Write();
  h_MET2PtxVsNPU_             -> Write();

  h_MET0PtxVsNPV_             -> Write();
  h_MET1PtxVsNPV_             -> Write();
  h_MET2PtxVsNPV_             -> Write();

  h_MET0PtxVsNGPV_            -> Write();
  h_MET1PtxVsNGPV_            -> Write();
  h_MET2PtxVsNGPV_            -> Write();

  h_MET0PtyVsNPU_             -> Write();
  h_MET1PtyVsNPU_             -> Write();
  h_MET2PtyVsNPU_             -> Write();

  for (unsigned int i = 0 ; i < h_EtxVsSumEt0_.size() ; i++){
    h_EtxVsSumEt0_[i]   -> Write();
  }

  for (unsigned int i = 0 ; i < h_EtxVsSumEt0_.size() ; i++){
    h_EtyVsSumEt0_[i]   -> Write();
  }

  for (unsigned int i = 0 ; i < h_EtxVsSumEt1_.size() ; i++){
    h_EtxVsSumEt1_[i]   -> Write();
  }

  for (unsigned int i = 0 ; i < h_EtyVsSumEt1_.size() ; i++){
    h_EtyVsSumEt1_[i]   -> Write();
  }

  for (unsigned int i = 0 ; i < h_EtxVsSumEt2_.size() ; i++){
    h_EtxVsSumEt2_[i]   -> Write();
  }
  
  for (unsigned int i = 0 ; i < h_EtyVsSumEt2_.size() ; i++){
    h_EtyVsSumEt2_[i]   -> Write();
 }

}

//define this as a plug-in
DEFINE_FWK_MODULE(METsAnalyzer);
