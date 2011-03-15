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
// $Id: METsAnalyzer.cc,v 1.12 2011/03/14 21:50:23 lucieg Exp $
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

  inputType_
     = iConfig.getUntrackedParameter<string>("inputType");

}


METsAnalyzer::~METsAnalyzer()
{

  //if (h_nRecoVertices_)         delete h_nRecoVertices_;
  //if (h_nPUVertices_)           delete h_nPUVertices_;
  //if (h_nrecoVtcesVsnPUVtces_)  delete h_nrecoVtcesVsnPUVtces_;
  //if (h_MET0PtVsNPU_)           delete h_MET0PtVsNPU_;
  //if (h_MET1PtVsNPU_)           delete h_MET1PtVsNPU_;
  //if (h_MET2PtVsNPU_)           delete h_MET2PtVsNPU_;
  //if (h_MET0PtxVsNPU_)          delete h_MET0PtxVsNPU_;
  //if (h_MET1PtxVsNPU_)          delete h_MET1PtxVsNPU_;
  //if (h_MET2PtxVsNPU_)          delete h_MET2PtxVsNPU_;
  //if (h_MET0PtyVsNPU_)          delete h_MET0PtyVsNPU_;
  //if (h_MET1PtyVsNPU_)          delete h_MET1PtyVsNPU_;
  //if (h_MET2PtyVsNPU_)          delete h_MET2PtyVsNPU_;
  //if (h_EtxVsSumEt0_)           delete h_EtxVsSumEt0_;
  //if (h_EtyVsSumEt0_)           delete h_EtyVsSumEt0_;
  //if (h_EtxVsSumEt1_)           delete h_EtxVsSumEt1_;
  //if (h_EtyVsSumEt1_)           delete h_EtyVsSumEt1_;
  //if (h_EtxVsSumEt2_)           delete h_EtxVsSumEt2_;
  //if (h_EtyVsSumEt2_)           delete h_EtyVsSumEt2_;

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
  h_nPUVertices_              = new TH1I("h_nPUVertices", "nr of PU vertices", 25, 0, 25);
  h_nrecoVtcesVsnPUVtces_     = new TH2D("h_nrecoVtcesVsnPUVtces", "nr of reco vertices vs nr of PU vertices", 50, 0, 50, 50, 0, 50);
  //  h_ngoodRecoVtcesVsnPUVtces_ = new TH2D("h_ngoodRecoVtcesVsnPUVtces", "nr of good reco vertices vs nr of PU vertices", 50, 0, 50, 50, 0, 50);

  /*****TH1 Pt histo *******/                 
  h_MET0PtVsNPU_    = new TH2D("h_MET0PtVsNPU","MET0 Pt(GeV) vs NPU",30 ,0, 30, 100, 0, 100);
  h_MET1PtVsNPU_    = new TH2D("h_MET1PtVsNPU","MET1 Pt(GeV) vs NPU",30 ,0, 30, 100, 0, 100);
  h_MET2PtVsNPU_    = new TH2D("h_MET2PtVsNPU","MET2 Pt(GeV) vs NPU",30 ,0, 30, 100, 0, 100);

  h_MET0PtxVsNPU_   = new TH2D("h_MET0PtxVsNPU","MET0 Ptx(GeV) vs NPU",30 ,0, 30, 100,-50, 50);
  h_MET1PtxVsNPU_   = new TH2D("h_MET1PtxVsNPU","MET1 Ptx(GeV) vs NPU",30 ,0, 30, 100,-50, 50);
  h_MET2PtxVsNPU_   = new TH2D("h_MET2PtxVsNPU","MET2 Ptx(GeV) vs NPU",30 ,0, 30, 100,-50, 50);

  h_MET0PtyVsNPU_   = new TH2D("h_MET0PtyVsNPU","MET0 Pty(GeV) vs NPU",30 ,0, 30, 100,-50, 50);
  h_MET1PtyVsNPU_   = new TH2D("h_MET1PtyVsNPU","MET1 Pty(GeV) vs NPU",30 ,0, 30, 100,-50, 50);
  h_MET2PtyVsNPU_   = new TH2D("h_MET2PtyVsNPU","MET2 Pty(GeV) vs NPU",30 ,0, 30, 100,-50, 50);


  /*****TH2 res...histo******/
  for (int i = 0; i < 6 ; i++){
    TString histoName = TString::Format("h_EtxVsSumEt0_%d", i);
    TH2D *h_EtxVsSumEt0Dummy_ = new TH2D(histoName, "Et,x vs sumEt caloMet vs NPU", 500, 0, 1000, 50, -50, 50);
    h_EtxVsSumEt0_.push_back(h_EtxVsSumEt0Dummy_);
  }

  for (int i = 0; i < 6 ; i++){
    TString histoName = TString::Format("h_EtyVsSumEt0_%d", i);
    TH2D *h_EtyVsSumEt0Dummy_ = new TH2D(histoName, "Et,y vs sumEt caloMet vs NPU", 500, 0, 1000, 50, -50, 50);
    h_EtyVsSumEt0_.push_back(h_EtyVsSumEt0Dummy_);
  }

 for (int i = 0; i < 6 ; i++){
    TString histoName = TString::Format("h_EtxVsSumEt1_%d", i);
    TH2D *h_EtxVsSumEt1Dummy_ = new TH2D(histoName, "Et,x vs sumEt pfMet vs NPU", 500, 0, 1000, 50, -50, 50);
    h_EtxVsSumEt1_.push_back(h_EtxVsSumEt1Dummy_);
  }

  for (int i = 0; i < 6 ; i++){
    TString histoName = TString::Format("h_EtyVsSumEt1_%d", i);
    TH2D *h_EtyVsSumEt1Dummy_ = new TH2D(histoName, "Et,y vs sumEt pfMet vs NPU", 500, 0, 1000, 50, -50, 50);
    h_EtyVsSumEt1_.push_back(h_EtyVsSumEt1Dummy_);
  }

 for (int i = 0; i < 6 ; i++){
    TString histoName = TString::Format("h_EtxVsSumEt2_%d", i);
    TH2D *h_EtxVsSumEt2Dummy_ = new TH2D(histoName, "Et,x vs sumEt pfMetNoPileUp vs NPU", 500, 0, 1000, 50, -50, 50);
    h_EtxVsSumEt2_.push_back(h_EtxVsSumEt2Dummy_);
  }

  for (int i = 0; i < 6 ; i++){
    TString histoName = TString::Format("h_EtyVsSumEt2_%d", i);
    TH2D *h_EtyVsSumEt2Dummy_ = new TH2D(histoName, "Et,y vs sumEt pfMetNoPileUp vs NPU", 500, 0, 1000, 50, -50, 50);
    h_EtyVsSumEt2_.push_back(h_EtyVsSumEt2Dummy_);
  }

}

// ------------ method called to for each event  ------------
void
METsAnalyzer::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{

  /*****get Vertices collections and fill vtces (only) histograms******/

  //reco PV (all of them). Need to add something about good vertices
  Handle<VertexCollection> vertices;  
  iEvent.getByLabel(inputTagVertices_, vertices);
  int nVertices = vertices -> size();
  h_nRecoVertices_   -> Fill(nVertices);
 
  int nPUVertices = -10;

  if (inputType_ == "FastSim"){
    //PU vertices
    Handle<edm::HepMCProduct> pileUpSource;
    iEvent.getByLabel("famosPileUp", "PileUpEvents", pileUpSource);
    nPUVertices = (pileUpSource -> GetEvent()) -> vertices_size();
    h_nPUVertices_   -> Fill(nPUVertices);
  }

  else if (inputType_ == "MCOfficial"){
    Handle<PileupSummaryInfo> pileUpSource;
    iEvent.getByLabel("addPileupInfo", pileUpSource);
    nPUVertices = pileUpSource -> getPU_NumInteractions();
    h_nPUVertices_   -> Fill(nPUVertices);
     }

  if (nPUVertices == -10) {
    cout << "failed to get NPU vertices !!!\n";
  }

  //nreco PV vs n PU vertices histo
  TH2D *h_nrecoVtcesVsnPUVtcesTemp = new TH2D("h_nrecoVtcesVsnPUVtcesTemp", "nhtemp", 50, 0, 50, 50, 0, 50);
  h_nrecoVtcesVsnPUVtcesTemp -> Fill(nPUVertices,nVertices);
  h_nrecoVtcesVsnPUVtces_ -> Add(h_nrecoVtcesVsnPUVtcesTemp);

  //n good reco PV vs n PU vertices hiso
  //int nGoodVertices = 0;
  // for(reco::VertexCollection::const_iterator v= vertices ->begin();  v!= vertices -> end(); ++v){
  //  if ( !(v->isFake()) && (v->ndof() > 4) && (fabs(v->z()) <= 24) && (v->position().Rho() <= 2))
  //    nGoodVertices++;
  // }
  
  //TH2D *h_ngoodRecoVtcesVsnPUVtcesTemp = new TH2D("h_nGoodRecoVtcesVsnPUVtcesTemp", "nhtemp", 50, 0, 50, 50, 0, 50);
  //h_ngoodRecoVtcesVsnPUVtcesTemp -> Fill(nPUVertices,nGoodVertices);
  //  h_ngoodRecoVtcesVsnPUVtces_ -> Add(h_ngoodRecoVtcesVsnPUVtcesTemp);

 /*****get MET collections *******/
  Handle<CaloMETCollection> met0Coll;
  iEvent.getByLabel(inputTagMET0_, met0Coll);
  CaloMETCollection::const_iterator met0 = met0Coll -> begin();

  Handle<PFMETCollection> met1Coll;
  iEvent.getByLabel(inputTagMET1_, met1Coll);
  PFMETCollection::const_iterator met1 = met1Coll -> begin();

  Handle<PFMETCollection> met2Coll;
  iEvent.getByLabel(inputTagMET2_, met2Coll);
  PFMETCollection::const_iterator met2 = met2Coll -> begin();

  //maybe used later
  //Handle<GenMETCollection> genMet;
  //iEvent.getByLabel(inputTagGenMET_, genMet);

  h_MET0PtVsNPU_      -> Fill(nPUVertices, met0->pt());
  h_MET1PtVsNPU_      -> Fill(nPUVertices, met1->pt());
  h_MET2PtVsNPU_      -> Fill(nPUVertices, met2->pt());

  h_MET0PtxVsNPU_     -> Fill(nPUVertices, met0->px());
  h_MET1PtxVsNPU_     -> Fill(nPUVertices, met1->px());
  h_MET2PtxVsNPU_     -> Fill(nPUVertices, met2->px());

  h_MET0PtyVsNPU_     -> Fill(nPUVertices, met0->py());
  h_MET1PtyVsNPU_     -> Fill(nPUVertices, met1->py());
  h_MET2PtyVsNPU_     -> Fill(nPUVertices, met2->py());

  ///

  bool fillEtSumEt = 1 - (nPUVertices % 5);
  //cout<<"fillEtSumEt "<<fillEtSumEt<<endl;

  if (fillEtSumEt && ((nPUVertices/5) < 6)){

    TH2D *h_EtxVsSumEt0Temp = new TH2D("h_EtxVsSumEt0Temp", "Et,y vs sumEt caloMet vs NPU", 500, 0, 1000, 50, -50, 50);
    h_EtxVsSumEt0Temp -> Fill(met0->sumEt(), met0->px()); 
    //Double_t binContent = h_EtxVsSumEt0_[nPUVertices/5] -> GetBinContent(met0->sumEt(), met0->px()); ///Add(h_EtxVsSumEt0Temp);
    // h_EtxVsSumEt0_[nPUVertices/5] -> Fill(met0->sumEt(), met0->px(), binContent + 1.);

    //binContent = -10;
    //binContent = h_EtyVsSumEt0_[nPUVertices/5] -> GetBinContent(met0->sumEt(), met0->py());
    // h_EtyVsSumEt0_[nPUVertices/5] -> Fill(met0->sumEt(), met0->py(), binContent + 1.);
 
    //binContent = -10;
    //binContent = h_EtxVsSumEt1_[nPUVertices/5] -> GetBinContent(met1->sumEt(), met1->px());
    //h_EtxVsSumEt1_[nPUVertices/5] -> Fill(met1->sumEt(), met1->px(), binContent + 1.);

    //binContent = -10;
    //binContent = h_EtyVsSumEt1_[nPUVertices/5] -> GetBinContent(met1->sumEt(), met1->py());
    // h_EtyVsSumEt1_[nPUVertices/5] -> Fill(met1->sumEt(), met1->py(), binContent + 1.);

    //binContent = -10;
    // binContent = h_EtxVsSumEt2_[nPUVertices/5] -> GetBinContent(met2->sumEt(), met2->px());
    //h_EtxVsSumEt2_[nPUVertices/5] -> Fill(met2->sumEt(), met2->px(), binContent + 1.);

    //binContent = -10;
    //binContent = h_EtyVsSumEt2_[nPUVertices/5] -> GetBinContent(met2->sumEt(), met2->py());
    //h_EtyVsSumEt2_[nPUVertices/5] -> Fill(met2->sumEt(), met2->py(), binContent + 1.);




    delete h_EtxVsSumEt0Temp; 
    //cout<<"histo to fill "<<nPUVertices/5<<endl;
      TH2D *h_EtyVsSumEt0Temp = new TH2D("h_EtyVsSumEt0Temp", "Et,y vs sumEt caloMet vs NPU", 500, 0, 1000, 50, -50, 50);
    h_EtyVsSumEt0Temp -> Fill(met0->sumEt(), met0->py());  
  h_EtyVsSumEt0_[nPUVertices/5] -> Add(h_EtyVsSumEt0Temp);
  delete h_EtyVsSumEt0Temp;

  TH2D *h_EtxVsSumEt1Temp = new TH2D("h_EtxVsSumEt1Temp", "Et,y vs sumEt caloMet vs NPU", 500, 0, 1000, 50, -50, 50);
  h_EtxVsSumEt1Temp -> Fill(met1->sumEt(), met1->px());  
  h_EtxVsSumEt1_[nPUVertices/5] -> Add(h_EtxVsSumEt1Temp);
  delete h_EtxVsSumEt1Temp;

  TH2D *h_EtyVsSumEt1Temp = new TH2D("h_EtyVsSumEt1Temp", "Et,y vs sumEt caloMet vs NPU", 500, 0, 1000, 50, -50, 50);
  h_EtyVsSumEt1Temp -> Fill(met1->sumEt(), met1->py());  
  h_EtyVsSumEt1_[nPUVertices/5] -> Add(h_EtyVsSumEt1Temp);
  delete h_EtyVsSumEt1Temp;

    TH2D *h_EtxVsSumEt2Temp = new TH2D("h_EtxVsSumEt2Temp", "Et,y vs sumEt caloMet vs NPU", 500, 0, 1000, 50, -50, 50);
  h_EtxVsSumEt2Temp -> Fill(met2->sumEt(), met2->px());  
   h_EtxVsSumEt2_[nPUVertices/5] -> Add(h_EtxVsSumEt2Temp);
  delete h_EtxVsSumEt2Temp;
 
  TH2D *h_EtyVsSumEt2Temp = new TH2D("h_EtyVsSumEt2Temp", "Et,y vs sumEt caloMet vs NPU", 500, 0, 1000, 50, -50, 50);
  h_EtyVsSumEt2Temp -> Fill(met2->sumEt(), met2->py());  
  h_EtyVsSumEt2_[nPUVertices/5] -> Add(h_EtyVsSumEt2Temp);
  delete h_EtyVsSumEt2Temp;
  }

}

// ------------ method called once each job just after ending the event loop  ------------
void 
METsAnalyzer::endJob() {
  outputFile_->cd();

  h_nRecoVertices_            -> Write();
  h_nPUVertices_              -> Write();
  h_nrecoVtcesVsnPUVtces_     -> Write();
  //  h_ngoodRecoVtcesVsnPUVtces_ -> Write();

  h_MET0PtVsNPU_        -> Write();
  h_MET1PtVsNPU_        -> Write();
  h_MET2PtVsNPU_        -> Write();

  h_MET0PtxVsNPU_       -> Write();
  h_MET1PtxVsNPU_       -> Write();
  h_MET2PtxVsNPU_       -> Write();

  h_MET0PtyVsNPU_       -> Write();
  h_MET1PtyVsNPU_       -> Write();
  h_MET2PtyVsNPU_       -> Write();

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
