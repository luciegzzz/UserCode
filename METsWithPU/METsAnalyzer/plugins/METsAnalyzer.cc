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
// $Id: METsAnalyzer.cc,v 1.1 2011/02/11 09:47:22 lucieg Exp $
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
  fOutputFileName = iConfig.getUntrackedParameter<string>("HistOutFile");
  
  inputTagCaloMET_ 
    = iConfig.getParameter<InputTag>("calomet");

  inputTagPFMET_
    = iConfig.getParameter<InputTag>("pfmet");

  inputTagTcMET_
    = iConfig.getParameter<InputTag>("tcmet");
}


METsAnalyzer::~METsAnalyzer()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}


//
// member functions
//

// ------------ method called to for each event  ------------
void
METsAnalyzer::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{

  Handle<CaloMETCollection> caloMetColl;
  iEvent.getByLabel(inputTagCaloMET_, caloMetColl);
  CaloMETCollection::const_iterator caloMet = caloMetColl -> begin();

  Handle<PFMETCollection> pfMetColl;
  iEvent.getByLabel(inputTagPFMET_, pfMetColl);
  PFMETCollection::const_iterator pfMet = pfMetColl -> begin();
  
  Handle<METCollection> tcMetColl;
  iEvent.getByLabel(inputTagTcMET_, tcMetColl);
  METCollection::const_iterator tcMet = tcMetColl -> begin();
    
  //Handle<GenMETCollection> genMet;
  //iEvent.getByLabel(inputTagGenMET_, genMet);

  h_CaloMETPt -> Fill(caloMet->pt());
  h_pfMETPt   -> Fill(pfMet->pt());
  h_tcMETPt   -> Fill(tcMet->pt());


//   ESHandle<SetupData> pSetup;
   //iSetup.get<SetupRecord>().get(pSetup);



}


// ------------ method called once each job just before starting event loop  ------------
void 
METsAnalyzer::beginJob()
{
  //Create output file                                                                                                                                                     
  hOutputFile = new TFile( fOutputFileName.c_str(), "RECREATE" );

  //histograms definition                                                                                                                                                  
  h_CaloMETPt                 = new TH1F("h_CaloMETPt","CaloMET Pt(GeV)",150,0,1500);
  h_pfMETPt                   = new TH1F("h_pfMETPt","PFMET Pt(GeV)",150,0,1500);
  h_tcMETPt                   = new TH1F("h_tcMETPt","TCMET Pt(GeV)",150,0,1500);
}

// ------------ method called once each job just after ending the event loop  ------------
void 
METsAnalyzer::endJob() {
  hOutputFile->cd();
  h_CaloMETPt -> Write();
  h_pfMETPt   -> Write();
  h_tcMETPt   -> Write();

}

//define this as a plug-in
DEFINE_FWK_MODULE(METsAnalyzer);
