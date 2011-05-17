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
// $Id: METsTreeAnalyzer.cc,v 1.3 2011/05/11 19:54:42 lucieg Exp $
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
    = iConfig.getParameter<InputTag>("stdPfMet");

  inputTagPFMET_ 
    = iConfig.getParameter<InputTag>("pfMet");

  inputTagPFMETDiscarded_ 
    = iConfig.getParameter<InputTag>("pfMetDiscarded");

  inputTagPFJets_ 
    = iConfig.getParameter<InputTag>("pfJets");

  inputTagPileUpPFJets_ 
    = iConfig.getParameter<InputTag>("pileUpPfJets");

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

  //Jets Tree
//   JetsTree_  = new TTree("JetsTree", "JetsTree");
//   JetsTree_  -> Branch("jetsPt", &jetsPt_, "jetPt/D");
//   JetsTree_  -> Branch("jetsEta", &jetsEta_, "jetEta/D");
//   JetsTree_  -> Branch("jetsPtPhi", &jetsPhi_, "jetsPhi/D");

//   //Pile-Up Jets Tree
//   PileUpJetsTree_  = new TTree("PileUpJetsTree", "PileUpJetsTree");
//   PileUpJetsTree_  -> Branch("pileUpJetsPt", &pileUpJetsPt_, "jetPt/D");
//   PileUpJetsTree_  -> Branch("pileUpJetsEta", &pileUpJetsEta_, "jetEta/D");
//   PileUpJetsTree_  -> Branch("pileUpJetsPtPhi", &pileUpJetsPhi_, "pileUpJetsPhi/D");
 
//   //pfCands Tree
//   PfCandsTree_  = new TTree("PfCandsTree", "PfCandsTree");
//   PfCandsTree_  -> Branch("pfCandsPt", &pfCandsPt_, "pfCandsPt/D");
//   PfCandsTree_  -> Branch("pfCandsEta", &pfCandsEta_, "pfCandsEta/D");
//   PfCandsTree_  -> Branch("pfCandsPtPhi", &pfCandsPhi_, "pfCandsPhi/D");
//   PfCandsTree_  -> Branch("pileUpPfCandsPt", &pileUpPfCandsPt_, "pileUpPfCandsPt/D");
//   PfCandsTree_  -> Branch("pileUpPfCandsEta", &pileUpPfCandsEta_, "pileUpPfCandsEta/D");
//   PfCandsTree_  -> Branch("pileUpPfCandsPtPhi", &pileUpPfCandsPhi_, "pileUpPfCandsPhi/D");
//   PfCandsTree_  -> Branch("noPileUpPfCandsPt", &noPileUpPfCandsPt_, "noPileUpPfCandsPt/D");
//   PfCandsTree_  -> Branch("noPileUpPfCandsEta", &noPileUpPfCandsEta_, "noPileUpPfCandsEta/D");
//   PfCandsTree_  -> Branch("noPileUpPfCandsPtPhi", &noPileUpPfCandsPhi_, "noPileUpPfCandsPhi/D");

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

//   //"other" Trees
//   jetsPt_              = -999.;
//   jetsEta_             = -999.;
//   jetsPhi_             = -999.;
//   pileUpJetsPt_        = -999.;
//   pileUpJetsEta_       = -999.;
//   pileUpJetsPhi_       = -999.;
//   pfCandsPt_           = -999.;
//   pfCandsEta_          = -999.;
//   pfCandsPhi_          = -999.;
//   pileUpPfCandsPt_     = -999.;
//   pileUpPfCandsEta_    = -999.;
//   pileUpPfCandsPhi_    = -999.;
//   noPileUpPfCandsPt_   = -999.;
//   noPileUpPfCandsEta_  = -999.;
//   noPileUpPfCandsPhi_  = -999.;
 
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

  //pf candidates
//   Handle<PFCandidateCollection> pfCandidateColl;
//   iEvent.getByLabel(inputTagPFCandidates_, pfCandidateColl);
 
//   Handle<PFCandidateCollection> pileUpPfCandidateColl;
//   iEvent.getByLabel(inputTagPileUpPFCandidates_, pileUpPfCandidateColl);
  
//   Handle<PFCandidateCollection> noPileUpPfCandidateColl;
//   iEvent.getByLabel(inputTagNoPileUpPFCandidates_, noPileUpPfCandidateColl);
 
//   for(unsigned int pfc = 0 ; pfc < pfCandidateColl -> size(); pfc++){

//     pfCandsPt_  = (*pfCandidateColl)[pfc].pt();
//     pfCandsEta_ = (*pfCandidateColl)[pfc].eta();
//     pfCandsPhi_ = (*pfCandidateColl)[pfc].phi();

//     if(pfc < pileUpPfCandidateColl -> size()){
//       pileUpPfCandsPt_  = (*pileUpPfCandidateColl)[pfc].pt();
//       pileUpPfCandsEta_ = (*pileUpPfCandidateColl)[pfc].eta();
//       pileUpPfCandsPhi_ = (*pileUpPfCandidateColl)[pfc].phi();
//     }

//     if(pfc < noPileUpPfCandidateColl -> size()){
//       noPileUpPfCandsPt_  = (*noPileUpPfCandidateColl)[pfc].pt();
//       noPileUpPfCandsEta_ = (*noPileUpPfCandidateColl)[pfc].eta();
//       noPileUpPfCandsPhi_ = (*noPileUpPfCandidateColl)[pfc].phi();
//     }

//     PfCandsTree_ -> Fill();
//   }

//   //jets
//   Handle<PFJetCollection> pfJetsColl;
//   iEvent.getByLabel(inputTagPFJets_, pfJetsColl);
//   PFJetCollection::const_iterator jet = pfJetsColl -> begin();
//   int jetIndex               = 0;

//   for(; jet != pfJetsColl -> end(); jet++, jetIndex++){
//     jetsPt_    = jet -> pt();
//     jetsEta_   = jet -> eta();
//     jetsPhi_   = jet -> phi();
//     JetsTree_ -> Fill();
//   }

//    Handle<PFJetCollection> pileUpPfJetsColl;
//    iEvent.getByLabel(inputTagPileUpPFJets_, pileUpPfJetsColl);
//    PFJetCollection::const_iterator puJet = pileUpPfJetsColl -> begin();
//    int puJetIndex               = 0;

//    for(; puJet != pileUpPfJetsColl -> end(); puJet++, puJetIndex++){
//      pileUpJetsPt_  = puJet -> pt();
//      pileUpJetsEta_ = puJet -> eta(); 
//      pileUpJetsPhi_ = puJet -> phi();
//      PileUpJetsTree_ -> Fill();
//    }


}



// ------------ method called once each job just after ending the event loop  ------------
void 
METsTreeAnalyzer::endJob() {

  outputFile_ -> cd();
  outputFile_ -> Write();

}

//Write this as a plug-in
DEFINE_FWK_MODULE(METsTreeAnalyzer);


