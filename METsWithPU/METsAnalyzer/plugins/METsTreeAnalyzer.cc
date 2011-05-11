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
// $Id: METsTreeAnalyzer.cc,v 1.1 2011/04/27 16:57:34 lucieg Exp $
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
    = iConfig.getParameter<InputTag>("pfMet");

  inputTagPFMET_ 
    = iConfig.getParameter<InputTag>("pfMetNoPileUp");

  inputTagPFMETRebalanced_ 
    = iConfig.getParameter<InputTag>("pfMetRebalanced");

  inputTagPFMETDiscarded_ 
    = iConfig.getParameter<InputTag>("pfMetDiscarded");

  inputTagPFJets_ 
    = iConfig.getParameter<InputTag>("pfJets");

  inputTagPileUpPFJets_ 
    = iConfig.getParameter<InputTag>("pfPileUpJets");

  inputTagPFCandidates_ 
    = iConfig.getParameter<InputTag>("pfCands");

  inputTagPileUpPFCandidates_ 
    = iConfig.getParameter<InputTag>("pfPileUpCands");

  inputTagNoPileUpPFCandidates_ 
    = iConfig.getParameter<InputTag>("pfNoPileUpCands");

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
  METTree_  -> Branch("metPhi", &metPhi_, "metPhi/D");
  METTree_  -> Branch("sumEt", &sumEt_, "sumEt/D");
  METTree_  -> Branch("metDiscarded", &metDiscarded_, "metDiscarded/D");
  METTree_  -> Branch("metDiscardedx", &metDiscardedx_, "metDiscardedx/D");
  METTree_  -> Branch("metDiscardedy", &metDiscardedy_, "metDiscardedy/D");
  METTree_  -> Branch("metDiscardedPhi", &metDiscardedPhi_, "metDiscardedPhi/D");
  METTree_  -> Branch("sumEtDiscarded", &sumEtDiscarded_, "sumEtDiscarded/D");
  METTree_  -> Branch("metRebalanced", &metRebalanced_, "metRebalanced/D");
  METTree_  -> Branch("metRebalancedx", &metRebalancedx_, "metRebalancedx/D");
  METTree_  -> Branch("metRebalancedy", &metRebalancedy_, "metRebalancedy/D");
  METTree_  -> Branch("metRebalancedPhi", &metRebalancedPhi_, "metRebalancedPhi/D");
  METTree_  -> Branch("sumEtRebalanced", &sumEtRebalanced_, "sumEtRebalanced/D");
  METTree_  -> Branch("dPhi", &dPhi_, "dPhi/D");

  //ObjectTree
  ObjectTree_  = new TTree("ObjectTree", "ObjectTree");
  ObjectTree_  -> Branch("jetsPt", &jetsPt_, "jetPt/D");
  ObjectTree_  -> Branch("jetsEta", &jetsEta_, "jetEta/D");
  ObjectTree_  -> Branch("jetsPtPhi", &jetsPhi_, "jetsPhi/D");
  ObjectTree_  -> Branch("pileUpJetsPt", &pileUpJetsPt_, "jetPt/D");
  ObjectTree_  -> Branch("pileUpJetsEta", &pileUpJetsEta_, "jetEta/D");
  ObjectTree_  -> Branch("pileUpJetsPtPhi", &pileUpJetsPhi_, "pileUpJetsPhi/D");
  ObjectTree_  -> Branch("pfCandsPt", &pfCandsPt_, "jetPt/D");
  ObjectTree_  -> Branch("pfCandsEta", &pfCandsEta_, "jetEta/D");
  ObjectTree_  -> Branch("pfCandsPtPhi", &pfCandsPhi_, "pfCandsPhi/D");
  ObjectTree_  -> Branch("pileUpPfCandsPt", &pileUpPfCandsPt_, "jetPt/D");
  ObjectTree_  -> Branch("pileUpPfCandsEta", &pileUpPfCandsEta_, "jetEta/D");
  ObjectTree_  -> Branch("pileUpPfCandsPtPhi", &pileUpPfCandsPhi_, "pileUpPfCandsPhi/D");
  ObjectTree_  -> Branch("noPileUpPfCandsPt", &noPileUpPfCandsPt_, "jetPt/D");
  ObjectTree_  -> Branch("noPileUpPfCandsEta", &noPileUpPfCandsEta_, "jetEta/D");
  ObjectTree_  -> Branch("noPileUpPfCandsPtPhi", &noPileUpPfCandsPhi_, "noPileUpPfCandsPhi/D");

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
  stdPFMETPhi_            = -999.;
  stdSumEt_               = -999.;
  met_                    = -999.;
  metx_                   = -999.;
  mety_                   = -999.;
  metPhi_                 = -999.;
  sumEt_                  = -999.;
  metDiscarded_           = -999.;
  metDiscardedx_          = -999.;
  metDiscardedy_          = -999.;
  metDiscardedPhi_        = -999.;
  sumEtDiscarded_         = -999.;
  metRebalanced_          = -999.;
  metRebalancedx_         = -999.;
  metRebalancedy_         = -999.;
  metRebalancedPhi_       = -999.;
  sumEtRebalanced_        = -999.;
  dPhi_                   = -999.;

  //ObjectTree
  jetsPt_              = -999.;
  jetsEta_             = -999.;
  jetsPhi_             = -999.;
  pileUpJetsPt_        = -999.;
  pileUpJetsEta_       = -999.;
  pileUpJetsPhi_       = -999.;
  pfCandsPt_           = -999.;
  pfCandsEta_          = -999.;
  pfCandsPhi_          = -999.;
  pileUpPfCandsPt_     = -999.;
  pileUpPfCandsEta_    = -999.;
  pileUpPfCandsPhi_    = -999.;
  noPileUpPfCandsPt_   = -999.;
  noPileUpPfCandsEta_  = -999.;
  noPileUpPfCandsPhi_  = -999.;
 
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
  Handle<PFMETCollection> stdPfMETColl;
  iEvent.getByLabel(inputTagStdPFMET_, stdPfMETColl);
  PFMETCollection::const_iterator stdPfmet = stdPfMETColl -> begin();
  stdPFMET_    = stdPfmet -> pt(); 
  stdPFMETx_   = stdPfmet -> px(); 
  stdPFMETy_   = stdPfmet -> py(); 
  stdPFMETPhi_ = stdPfmet -> phi(); 
  stdSumEt_    = stdPfmet -> sumEt(); 

  //get "new" pfMet (e.g. pfMetNoPileUp)
  Handle<PFMETCollection> pfMETColl;
  iEvent.getByLabel(inputTagPFMET_, pfMETColl);
  PFMETCollection::const_iterator pfmet = pfMETColl -> begin();
 
  met_       = pfmet -> pt(); 
  metx_      = pfmet -> px(); 
  mety_      = pfmet -> py(); 
  metPhi_    = pfmet -> phi(); 
  sumEt_     = pfmet -> sumEt(); 

  //get what has been removed
  Handle<PFMETCollection> pfMETDiscardedColl;
  iEvent.getByLabel(inputTagPFMETDiscarded_, pfMETDiscardedColl);
  PFMETCollection::const_iterator pfmetDiscarded = pfMETDiscardedColl -> begin();
 
  metDiscarded_       = pfmetDiscarded -> pt(); 
  metDiscardedx_      = pfmetDiscarded -> px(); 
  metDiscardedy_      = pfmetDiscarded -> py(); 
  metDiscardedPhi_    = pfmetDiscarded -> phi(); 
  sumEtDiscarded_     = pfmetDiscarded -> sumEt(); 

  dPhi_       = deltaPhi(pfmet -> phi(), pfmetDiscarded -> phi()) ; 

  //substract the complementary of what has been removed
  metRebalancedx_      = metx_ - metDiscardedx_ ; 
  metRebalancedy_      = mety_ - metDiscardedy_ ; 
  metRebalanced_       = sqrt( metRebalancedx_ * metRebalancedx_ +  metRebalancedy_ * metRebalancedy_ );
  
  sumEtRebalanced_     = sumEt_ + sumEtDiscarded_ ; 

  METTree_ -> Fill();


  //jets
 //  Handle<PFJetsCollection> pfJetsColl;
//   iEvent.getByLabel(inputTagPFJets_, pfJetsColl);

//   Handle<PFJetsCollection> pileUpPfJetsColl;
//   iEvent.getByLabel(inputTagPileUpPFJets_, pileUpPfJetsColl);
  
//   for(unsigned int jetIndex = 0 ; jetIndex < jetColl ->size();  jetIndex++){
   
//     jetPt_  = (*pfJetsColl)[jetIndex]pt();
//     jetEta_ = (*pfJetsColl)[jetIndex]eta();
//     jetPhi_ = (*pfJetsColl)[jetIndex]phi();
//     if (jetIndex < pileUpPfJetsColl.size() ){
//       pileUpJetsPt_  = (*pfPileUpJetsColl)[jetIndex]pt();
//       pileUpJetsEta_ = (*pfPileUpJetsColl)[jetIndex]eta();
//       pileUpJetsPhi_ = (*pfPileUpJetsColl)[jetIndex]phi();
//     }

//   }

}



// ------------ method called once each job just after ending the event loop  ------------
void 
METsTreeAnalyzer::endJob() {

  outputFile_ -> cd();
  outputFile_ -> Write();

}

//Write this as a plug-in
DEFINE_FWK_MODULE(METsTreeAnalyzer);


