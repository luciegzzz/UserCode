// -*- C++ -*-
//
// Package:    METsTreeAnalyzer
// Class:      METsTreeAnalyzer
// 
/**\class METsTreeAnalyzer METsTreeAnalyzer.cc METsTree/METsTreeAnalyzer/src/METsTreeAnalyzer.cc

Description: [one line class summary]

Implementation:
[Notes on implementation]
*/
//
// Original Author:  "Lucie Gauthier"
//         Created:  Fri Ap 14  2011
// $Id: METsTreeAnalyzer.cc,v 1.13 2011/04/21 20:17:58 lucieg Exp $
//
//

// user include files
#include "METsWithPU/METsAnalyzer/plugins/METsTreeAnalyzer.h"

using namespace std;
using namespace edm;
using namespace reco;

//
// constructors and destructor
//
METsTreeAnalyzer::METsTreeAnalyzer(const edm::ParameterSet& iConfig)

{
  inputTagVertices_ 
    = iConfig.getParameter<InputTag>("vertices");

  inputTagStdPFMET_ 
    = iConfig.getParameter<InputTag>("pfmet");

  inputTagPFMETRecomputed_ 
    = iConfig.getParameter<InputTag>("pfmetRecomputed");

  inputTagPFMETDiscarded_ 
    = iConfig.getParameter<InputTag>("pfmetDiscarded");

  fOutputFileName_ = iConfig.getUntrackedParameter<string>("HistOutFile");

}


METsTreeAnalyzer::~METsTreeAnalyzer()
{

}


//
// member functions
//
// ------------ pSetup called once each job just before starting event loop  ------------
void 
METsTreeAnalyzer::beginJob()
{
  //Create output file                                                                                                                                                     
  outputFile_ = new TFile( fOutputFileName_.c_str(), "RECREATE" );

  //METTree
  METTree_  = new TTree("METTree", "METTree");
  METTree_  -> Branch("nPUVertices", &nPUVertices_, "nPUVertices/I");
  METTree_  -> Branch("stdPFMET", &stdPFMET_, "stdPFMET/D");
  METTree_  -> Branch("stdPFMETx", &stdPFMETx_, "stdPFMETx/D");
  METTree_  -> Branch("stdPFMETy", &stdPFMETy_, "stdPFMETy/D");
  METTree_  -> Branch("stdSumEt", &stdSumEt_, "stdSumEt/D");
  METTree_  -> Branch("met", &met_, "met/D");
  METTree_  -> Branch("metx", &metx_, "metx/D");
  METTree_  -> Branch("mety", &mety_, "mety/D");
  METTree_  -> Branch("sumEt", &sumEt_, "sumEt/D");
  METTree_  -> Branch("metDiscarded", &metDiscarded_, "metDiscarded/D");
  METTree_  -> Branch("metxDiscarded", &metxDiscarded_, "metxDiscarded/D");
  METTree_  -> Branch("metyDiscarded", &metyDiscarded_, "metyDiscarded/D");
  METTree_  -> Branch("sumEtDiscarded", &sumEtDiscarded_, "sumEtDiscarded/D");
  METTree_  -> Branch("dPhi", &dPhi_, "dPhi/D");

}

// ------------ method called to for each event  ------------
void
METsTreeAnalyzer::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
  
  /*****Tree variables initialization******/
  //METTree
  nPUVertices_            = -999;
  stdPFMET_               = -999.;
  stdPFMETx_              = -999.;
  stdPFMETy_              = -999.;
  stdSumEt_               = -999.;
  met_                    = -999.;
  metx_                   = -999.;
  mety_                   = -999.;
  sumEt_                  = -999.;
  metDiscarded_           = -999.;
  metxDiscarded_          = -999.;
  metyDiscarded_          = -999.;
  sumEtDiscarded_         = -999.;
  dPhi_                   = -999.;
 
  /*****PU info - not  needed so far....*****/
  int nPUVertices         = 0; 

  Handle<vector< PileupSummaryInfo > >  PupInfo;
  iEvent.getByLabel("addPileupInfo", PupInfo);

  vector<PileupSummaryInfo>::const_iterator PVI;

  for(PVI = PupInfo->begin(); PVI != PupInfo->end(); ++PVI) {
    nPUVertices += PVI->getPU_NumInteractions();
  }
  
  nPUVertices_        = nPUVertices;
 
  //get standard met
  Handle<PFMETCollection> pfMETColl;
  iEvent.getByLabel(inputTagStdPFMET_, pfMETColl);
  PFMETCollection::const_iterator pfmet = pfMETColl -> begin();
  stdPFMET_  = pfmet -> pt(); 
  stdPFMETx_ = pfmet -> px(); 
  stdPFMETy_ = pfmet -> py(); 
  stdSumEt_  = pfmet -> sumEt(); 

  Handle<PFMETCollection> pfMETRecomputedColl;
  iEvent.getByLabel(inputTagPFMETRecomputed_, pfMETRecomputedColl);
  PFMETCollection::const_iterator pfmetRecomputed = pfMETRecomputedColl -> begin();
 
  met_       = pfmetRecomputed -> pt(); 
  metx_      = pfmetRecomputed -> px(); 
  mety_      = pfmetRecomputed -> py(); ;
  sumEt_     = pfmetRecomputed -> sumEt(); 

  Handle<PFMETCollection> pfMETDiscardedColl;
  iEvent.getByLabel(inputTagPFMETDiscarded_, pfMETDiscardedColl);
  PFMETCollection::const_iterator pfmetDiscarded = pfMETDiscardedColl -> begin();
 
  metDiscarded_       = pfmetDiscarded -> pt(); 
  metxDiscarded_      = pfmetDiscarded -> px(); 
  metyDiscarded_      = pfmetDiscarded -> py(); ;
  sumEtDiscarded_     = pfmetDiscarded -> sumEt(); 

  dPhi_       = deltaPhi(pfmetRecomputed -> phi(), pfmetDiscarded -> phi()) ; 
   
  METTree_ -> Fill();

}



// ------------ method called once each job just after ending the event loop  ------------
void 
METsTreeAnalyzer::endJob() {

  outputFile_ -> cd();
  outputFile_ -> Write();

}

//Write this as a plug-in
DEFINE_FWK_MODULE(METsTreeAnalyzer);


