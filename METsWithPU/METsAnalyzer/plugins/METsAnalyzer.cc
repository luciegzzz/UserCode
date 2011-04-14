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
// $Id: METsAnalyzer.cc,v 1.24 2011/04/04 12:58:23 lucieg Exp $
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
  
  inputTagMET_ 
    = iConfig.getParameter<InputTag>("met");
 
  inputTagRAWMET_ 
    = iConfig.getParameter<InputTag>("rawmet");

  inputTagVertices_
    = iConfig.getParameter<InputTag>("vertices");

  inputTagGoodVertices_
    = iConfig.getParameter<InputTag>("goodVertices");

  inputTagVerticesDA_
    = iConfig.getParameter<InputTag>("verticesDA");

  inputTagGoodVerticesDA_
    = iConfig.getParameter<InputTag>("goodVerticesDA");

  inputType_
     = iConfig.getUntrackedParameter<string>("inputType");

  fillVerticesHistos_    
     = iConfig.getUntrackedParameter<bool>("fillVerticesHistos");

  fOutputFileName_ = iConfig.getUntrackedParameter<string>("HistOutFile");

  //  metLabel_ = iConfig.getUntrackedParameter<string>("metLabel");
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
  if (fillVerticesHistos_){
    /**vertices distributions**/
    h_nPUVertices_                = new TH1D("h_nPUVertices", "nr of PU vertices", 50, 0, 50);
    h_nRecoVertices_              = new TH1D("h_nRecoVertices", "nr of reco PV", 50, 0, 50);
    h_nGoodRecoVertices_          = new TH1D("h_nGoodRecoVertices", "nr of good reco PV", 50, 0, 50);
    h_nRecoVerticesDA_            = new TH1D("h_nRecoVerticesDA", "nr of reco PV with DA", 50, 0, 50);
    h_nGoodRecoVerticesDA_        = new TH1D("h_nGoodRecoVerticesDA", "nr of good reco PV with DA", 50, 0, 50);
    
    h_nRecoVtcesVsnPUVtces_       = new TH2D("h_nrecoVtcesVsnPUVtces", "nr of reco vertices vs nr of PU vertices", 50, 0, 50, 50, 0, 50);  
    h_nGoodRecoVtcesVsnPUVtces_   = new TH2D("h_ngoodRecoVtcesVsnPUVtces", "nr of good reco vertices vs nr of PU vertices", 50, 0, 50, 50, 0, 50);
    
    h_nRecoVtcesDAVsnPUVtces_     = new TH2D("h_nrecoVtcesDAVsnPUVtces", "nr of reco vertices with DA vs nr of PU vertices", 50, 0, 50, 50, 0, 50);
    h_nGoodRecoVtcesDAVsnPUVtces_ = new TH2D("h_ngoodRecoVtcesDAVsnPUVtces", "nr of good reco vertices with DA vs nr of PU vertices", 50, 0, 50, 50, 0, 50);
  }
  /*****SumEt***************/
  h_sumEtEffNPU_                  = new TH2D("h_sumEtEffNPU", "sumEt (GeV) vs NPU", 30 ,0 ,30 , 500, 0, 2000);
  h_sumEtEffNPVDA_                = new TH2D("h_sumEtEffNPVDA", "sumEt (GeV) vs NPVDA", 30 ,0 ,30 , 500, 0, 2000);
  h_sumEtEffNGPVDA_               = new TH2D("h_sumEtEffNGPVDA", "sumEt (GeV) vs NGPVDA", 30 ,0 ,30 , 500, 0, 2000);

  /*****MET : TH1 Pt histo *******/                 
  h_METPtVsNPU_                 = new TH2D("h_METPtVsNPU","MET Pt(GeV) vs NPU",30 ,0, 30, 100, 0, 100);
  h_METPtxVsNPU_                = new TH2D("h_METPtxVsNPU","MET Ptx(GeV) vs NPU",30 ,0, 30, 100,-50, 50);
  h_METPtxVsNPV_                = new TH2D("h_METPtxVsNPV","MET Ptx(GeV) vs NPV (DA)",30 ,0, 30, 100,-50, 50);
  h_METPtxVsNGPV_               = new TH2D("h_METPtxVsNGPV","MET Ptx(GeV) vs NGPV (DA)",30 ,0, 30, 100,-50, 50);
  h_METPtyVsNPU_                = new TH2D("h_METPtyVsNPU","MET Pty(GeV) vs NPU",30 ,0, 30, 100,-50, 50);


  /*****MET : TH2 res...histo******/
  for (int i = 0; i < 25 ; i++){
    TString histoNamePUV = TString::Format("h_EtxVsSumEtPUV_%d", i);
    TH2D *h_EtxVsSumEtDummyPUV_ = new TH2D(histoNamePUV, "Et,x vs sumEt, PUV", 500, 0, 2000, 100, -50, 50);
    h_EtxVsSumEtPUV_.push_back(h_EtxVsSumEtDummyPUV_);

    TString histoNamePV = TString::Format("h_EtxVsSumEtPV_%d", i);
    TH2D *h_EtxVsSumEtDummyPV_ = new TH2D(histoNamePV, "Et,x vs sumEt, PV (DA)", 500, 0, 2000, 100, -50, 50);
    h_EtxVsSumEtPV_.push_back(h_EtxVsSumEtDummyPV_);
    
    TString histoNameGPV = TString::Format("h_EtxVsSumEt_%d", i);
    TH2D *h_EtxVsSumEtDummyGPV_ = new TH2D(histoNameGPV, "Et,x vs sumEt, GPV (DA)", 500, 0, 2000, 100, -50, 50);
    h_EtxVsSumEtGPV_.push_back(h_EtxVsSumEtDummyGPV_);

    TString histoNameSumEtNPU = TString::Format("h_sumEtRatioVsRawSumEt_%d", i);
    TH2D *h_sumEtRatioVsRawSumEtDummyNPU_ = new TH2D(histoNameSumEtNPU, "sumEt eff/raw vs sumEt raw", 500, 0, 2000, 100, 0, 2 );
    h_sumEtRatioVsRawSumEtNPU_.push_back(h_sumEtRatioVsRawSumEtDummyNPU_);

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

  //PU vertices
  int nPUVertices = 0;

  if (inputType_ == "FastSim"){
    Handle<edm::HepMCProduct> pileUpSource;
    iEvent.getByLabel("famosPileUp", "PileUpEvents", pileUpSource);
    nPUVertices       = (pileUpSource -> GetEvent()) -> vertices_size();
    h_nPUVertices_    -> Fill(nPUVertices);
  }

  else if (inputType_ == "MCOfficial"){
    Handle<std::vector< PileupSummaryInfo > >  PupInfo;
    iEvent.getByLabel("addPileupInfo", PupInfo);

    std::vector<PileupSummaryInfo>::const_iterator PVI;

    for(PVI = PupInfo->begin(); PVI != PupInfo->end(); ++PVI) {
      nPUVertices += PVI->getPU_NumInteractions();
    }
    h_nPUVertices_    -> Fill(nPUVertices);
  }

  //  Handle<double> rho;
  //iEvent.getByLabel("kt6PFJets", "rho", rho);

  //reco PV 
  Handle<VertexCollection> vertices;  
  iEvent.getByLabel(inputTagVertices_, vertices);
  int nVertices      = vertices -> size();
 
  // good reco PV (!isFake && ndof >4 && abs(z)<25 and position.Rho()<2)
  Handle<VertexCollection> goodVertices;  
  iEvent.getByLabel(inputTagGoodVertices_, goodVertices);
  int nGoodVertices   = goodVertices -> size();

  //reco PV with DA 
  Handle<VertexCollection> verticesDA;  
  iEvent.getByLabel(inputTagVerticesDA_, verticesDA);
  int nVerticesDA     = verticesDA -> size();

  // good reco PV  with DA (!isFake && ndof >4 && abs(z)<25 and position.Rho()<2)
  Handle<VertexCollection> goodVerticesDA;  
  iEvent.getByLabel(inputTagGoodVerticesDA_, goodVerticesDA);
  int nGoodVerticesDA   = goodVerticesDA -> size();

  if (fillVerticesHistos_){

  /***1D Vertices histos***/
  h_nRecoVertices_      -> Fill(nVertices);
  h_nGoodRecoVertices_  -> Fill(nGoodVertices);
  h_nRecoVerticesDA_    -> Fill(nVerticesDA);
  h_nGoodRecoVerticesDA_-> Fill(nGoodVerticesDA);

  /***2D histos****/
  h_nRecoVtcesVsnPUVtces_       -> Fill(nPUVertices,nVertices);
  h_nGoodRecoVtcesVsnPUVtces_   -> Fill(nPUVertices,nGoodVertices);
  h_nRecoVtcesDAVsnPUVtces_     -> Fill(nPUVertices,nVerticesDA);
  h_nGoodRecoVtcesDAVsnPUVtces_ -> Fill(nPUVertices,nGoodVerticesDA);

} 

  /*******************************/
  /*****get MET collections ******/
  /*******************************/
  Handle<PFMETCollection> metColl;
  //Handle<METCollection> metColl; //for corrected met
  iEvent.getByLabel(inputTagMET_, metColl);
  PFMETCollection::const_iterator met = metColl -> begin();
  //METCollection::const_iterator met = metColl -> begin();

  Handle<PFMETCollection> rawPFMetColl;
  iEvent.getByLabel(inputTagRAWMET_, rawPFMetColl);
  PFMETCollection::const_iterator rawmet = rawPFMetColl -> begin();

  /****sumEt histos*****/
  double sumEtEff = met    -> sumEt();
  double rawSumEt = rawmet -> sumEt();
  //  double genSumEt = 

  h_sumEtEffNPU_    -> Fill(nPUVertices, sumEtEff);
  h_sumEtEffNPVDA_  -> Fill(nVerticesDA, sumEtEff);
  h_sumEtEffNGPVDA_ -> Fill(nGoodVerticesDA, sumEtEff);

  /*****MET histos******/

  //Pt
  h_METPtVsNPU_      -> Fill(nPUVertices, met->pt());

  //Pt, x
  h_METPtxVsNPU_     -> Fill(nPUVertices, met->px());
  h_METPtxVsNPV_     -> Fill(nVerticesDA, met->px());
  h_METPtxVsNGPV_    -> Fill(nGoodVerticesDA, met->px());
  //Pt, y
  h_METPtyVsNPU_     -> Fill(nPUVertices, met->py());

  if (nPUVertices < 25 && nVerticesDA <25){
    h_EtxVsSumEtPUV_[nPUVertices]     -> Fill(rawSumEt, met->px());
    h_EtxVsSumEtPV_[nVerticesDA]      -> Fill(rawSumEt, met->px());
    h_EtxVsSumEtGPV_[nGoodVerticesDA] -> Fill(rawSumEt, met->px());

    h_sumEtRatioVsRawSumEtNPU_[nPUVertices] -> Fill(rawSumEt, sumEtEff/rawSumEt);
    //    h_sumEtRatioVsRawSumEt[nPUVertices] -> Fill(rawSumEt, sumEtEff/genSumEt);
  }

  else cout<<"higher nr of vtces than expected"<<endl;

}

// ------------ method called once each job just after ending the event loop  ------------
void 
METsAnalyzer::endJob() {
  outputFile_->cd();

  if (fillVerticesHistos_){

    h_nPUVertices_                -> Write();
    h_nRecoVertices_              -> Write();
    h_nGoodRecoVertices_          -> Write();
    h_nRecoVerticesDA_            -> Write();
    h_nGoodRecoVerticesDA_        -> Write();

    h_nRecoVtcesVsnPUVtces_       -> Write();
    h_nGoodRecoVtcesVsnPUVtces_   -> Write();
    h_nRecoVtcesDAVsnPUVtces_     -> Write();
    h_nGoodRecoVtcesDAVsnPUVtces_ -> Write();

  }

  h_sumEtEffNPU_             -> Write();
  h_sumEtEffNPVDA_           -> Write();
  h_sumEtEffNGPVDA_          -> Write();

  h_METPtVsNPU_              -> Write();
  h_METPtxVsNPU_             -> Write();
  h_METPtxVsNPV_             -> Write();
  h_METPtxVsNGPV_            -> Write();
  h_METPtyVsNPU_             -> Write();

  for (unsigned int i = 0 ; i < h_EtxVsSumEtPUV_.size() ; i++){
    h_EtxVsSumEtPUV_[i]        -> Write();
    h_EtxVsSumEtPV_[i]         -> Write();
    h_EtxVsSumEtGPV_[i]        -> Write();
    h_sumEtRatioVsRawSumEtNPU_[i] -> Write();
  }

//   for (unsigned int i = 0 ; i < h_EtxVsSumEt_.size() ; i++){
//     h_EtyVsSumEtPUV_[i]   -> Write();
//     h_EtyVsSumEtPV_[i]    -> Write();
//     h_EtyVsSumEtGPV_[i]   -> Write();
//   }


}

//define this as a plug-in
DEFINE_FWK_MODULE(METsAnalyzer);
