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
// $Id: METsAnalyzer.cc,v 1.2 2011/02/11 13:54:10 lucieg Exp $
//
//

// user include files
#include "METsWithPU/METsAnalyzer/plugins/METsAnalyzer.h"

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
}


METsAnalyzer::~METsAnalyzer()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

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
  h_nVertices_ = new TH1I("h_nVertices", "nr of PV", 25, 0, 25);

  /*****TH1 Pt histo *******/                 
  h_MET0Pt_    = new TH1F("h_MET0Pt","MET0 Pt(GeV)",100,0,100);
  h_MET1Pt_    = new TH1F("h_MET1Pt","MET1 Pt(GeV)",100,0,100);
  h_MET2Pt_    = new TH1F("h_MET2Pt","MET2 Pt(GeV)",100,0,100);

  h_MET0Ptx_   = new TH1F("h_MET0Ptx","MET0 Ptx(GeV)",100,-50, 50);
  h_MET1Ptx_   = new TH1F("h_MET1Ptx","MET1 Ptx(GeV)",100,-50, 50);
  h_MET2Ptx_   = new TH1F("h_MET2Ptx","MET2 Ptx(GeV)",100,-50, 50);

  h_MET0Pty_   = new TH1F("h_MET0Pty","MET0 Pty(GeV)",100,-50, 50);
  h_MET1Pty_   = new TH1F("h_MET1Pty","MET1 Pty(GeV)",100,-50, 50);
  h_MET2Pty_   = new TH1F("h_MET2Pty","MET2 Pty(GeV)",100,-50, 50);


  /*****TH2 res...histo******/
  h_EtxVsSumEt0_ = new TH2F("h_EtxVsSumEt0", "Et,x vs sumEt caloMet", 500, 0, 1000, 50, -50, 50);
  h_EtyVsSumEt0_ = new TH2F("h_EtyVsSumEt0", "Et,y vs sumEt caloMet", 500, 0, 1000, 50, -50, 50);
  h_EtxVsSumEt1_ = new TH2F("h_EtxVsSumEt1", "Et,x vs sumEt pfMet", 500, 0, 1000, 50, -50, 50);
  h_EtyVsSumEt1_ = new TH2F("h_EtyVsSumEt1", "Et,y vs sumEt pfMet", 500, 0, 1000, 50, -50, 50); 
  h_EtxVsSumEt2_ = new TH2F("h_EtxVsSumEt2", "Et,x vs sumEt pfMetNoPileUp", 500, 0, 1000, 50, -50, 50); 
  h_EtyVsSumEt2_ = new TH2F("h_EtyVsSumEt2", "Et,y vs sumEt pfMetNoPileUp", 500, 0, 1000, 50, -50, 50);

}

// ------------ method called to for each event  ------------
void
METsAnalyzer::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{

  Handle<CaloMETCollection> met0Coll;
  iEvent.getByLabel(inputTagMET0_, met0Coll);
  CaloMETCollection::const_iterator met0 = met0Coll -> begin();

  Handle<PFMETCollection> met1Coll;
  iEvent.getByLabel(inputTagMET1_, met1Coll);
  PFMETCollection::const_iterator met1 = met1Coll -> begin();

  Handle<PFMETCollection> met2Coll;
  iEvent.getByLabel(inputTagMET2_, met2Coll);
  PFMETCollection::const_iterator met2 = met2Coll -> begin();

  //Handle<GenMETCollection> genMet;
  //iEvent.getByLabel(inputTagGenMET_, genMet);

  Handle<VertexCollection> vertices;  
  iEvent.getByLabel(inputTagVertices_, vertices);
  int nVertices = vertices -> size();
  h_nVertices_   -> Fill(nVertices);
 
  h_MET0Pt_      -> Fill(met0->pt());
  h_MET1Pt_      -> Fill(met1->pt());
  h_MET2Pt_      -> Fill(met2->pt());

  h_MET0Ptx_     -> Fill(met0->px());
  h_MET1Ptx_     -> Fill(met1->px());
  h_MET2Ptx_     -> Fill(met2->px());

  h_MET0Pty_     -> Fill(met0->py());
  h_MET1Pty_     -> Fill(met1->py());
  h_MET2Pty_     -> Fill(met2->py());

  h_EtxVsSumEt0_ -> Fill(met0->sumEt(), met0->px());  
  h_EtyVsSumEt0_ -> Fill(met0->sumEt(), met0->py());
  h_EtxVsSumEt1_ -> Fill(met1->sumEt(), met1->px());  
  h_EtyVsSumEt1_ -> Fill(met1->sumEt(), met1->py());
  h_EtxVsSumEt2_ -> Fill(met2->sumEt(), met2->px());  
  h_EtyVsSumEt2_ -> Fill(met2->sumEt(), met2->py());


}

// ------------ method called once each job just after ending the event loop  ------------
void 
METsAnalyzer::endJob() {
  outputFile_->cd();

//   TF1* f1= new TF1("f1", "gaus", -40, 40);
//   h_MET1Ptx        -> Fit("f1");
 
//   h_SigmaVsNbVtces -> Fill(nVertices, f1 -> GetParameter(2)); //error...
//   h_RMSVsNbVtces   -> Fill(nVertices, h_MET1Ptx -> GetRMS()); //error...



  h_nVertices_     -> Write();

  h_MET0Pt_        -> Write();
  h_MET1Pt_        -> Write();
  h_MET2Pt_        -> Write();

  h_MET0Ptx_       -> Write();
  h_MET1Ptx_       -> Write();
  h_MET2Ptx_       -> Write();

  h_MET0Pty_       -> Write();
  h_MET1Pty_       -> Write();
  h_MET2Pty_       -> Write();

  h_EtxVsSumEt0_   -> Write();
  h_EtxVsSumEt0_   -> Write();
  h_EtxVsSumEt1_   -> Write();
  h_EtxVsSumEt1_   -> Write();
  h_EtxVsSumEt2_   -> Write();
  h_EtxVsSumEt2_   -> Write();


}

//define this as a plug-in
DEFINE_FWK_MODULE(METsAnalyzer);
