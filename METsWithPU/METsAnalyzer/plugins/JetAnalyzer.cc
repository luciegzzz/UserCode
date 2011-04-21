// -*- C++ -*-
//
// Package:    JetAnalyzer
// Class:      JetAnalyzer
// 
/**\class JetAnalyzer JetAnalyzer.cc Jet/JetAnalyzer/src/JetAnalyzer.cc

Description: [one line class summary]

Implementation:
[Notes on implementation]
*/
//
// Original Author:  "Lucie Gauthier"
//         Created:  Fri Ap 14  2011
// $Id: JetAnalyzer.cc,v 1.11 2011/04/20 19:07:10 lucieg Exp $
//
//

// user include files
#include "METsWithPU/METsAnalyzer/plugins/JetAnalyzer.h"

using namespace std;
using namespace edm;
using namespace reco;

//
// constructors and destructor
//
JetAnalyzer::JetAnalyzer(const edm::ParameterSet& iConfig)

{
  inputTagVertices_ 
    = iConfig.getParameter<InputTag>("vertices");

  inputTagJet_ 
    = iConfig.getParameter<InputTag>("jets");

  inputTagGenJet_ 
    = iConfig.getParameter<InputTag>("genJets");
 
  inputTagPFMET_ 
    = iConfig.getParameter<InputTag>("pfmet");

  inputTagPFCand_ 
    = iConfig.getParameter<InputTag>("pfCandidates");

 
  fOutputFileName_ = iConfig.getUntrackedParameter<string>("HistOutFile");

}


JetAnalyzer::~JetAnalyzer()
{

}


//
// member functions
//
// ------------ pSetup called once each job just before starting event loop  ------------
void 
JetAnalyzer::beginJob()
{
  //Create output file                                                                                                                                                     
  outputFile_ = new TFile( fOutputFileName_.c_str(), "RECREATE" );

  //JetsTree
  JetsTree_ = new TTree("JetsTree", "JetsTree");
  JetsTree_ -> Branch("nPFCFromPV",&nPFCFromPV_,"nPFCFromPV/D");
  JetsTree_ -> Branch("nPFCFromPU",&nPFCFromPU_,"nPFCFromPU/D");
  JetsTree_ -> Branch("nPFCNotAssociated",&nPFCNotAssociated_,"nPFCNotAssociated/D");
  JetsTree_ -> Branch("nNeutralConstituents",&nNeutralConstituents_,"nNeutralConstituents/D");
  JetsTree_ -> Branch("nChargedConstituents",&nChargedConstituents_,"nChargedConstituents/D");
  JetsTree_ -> Branch("nConstituents",&nConstituents_,"nConstituents/D");
  JetsTree_ -> Branch("nMuons",&nMuons_,"nMuons/D");
  JetsTree_ -> Branch("nElectrons",&nElectrons_,"nElectrons/D");
  JetsTree_ -> Branch("ptRecoJet",&ptRecoJet_,"ptRecoJet/D");
  JetsTree_ -> Branch("etaRecoJet",&etaRecoJet_,"etaRecoJet/D");
  JetsTree_ -> Branch("phiRecoJet",&phiRecoJet_,"phiRecoJet/D");
  JetsTree_ -> Branch("chargedMultiplicity",&chargedMultiplicity_,"chargedMultiplicity/I");
  JetsTree_ -> Branch("sumPtFromPV",&sumPtFromPV_,"sumPtFromPV/D");
  JetsTree_ -> Branch("sumPtFromPU",&sumPtFromPU_,"sumPtFromPU/D");
  JetsTree_ -> Branch("sumPtNotAssociated",&sumPtNotAssociated_,"sumPtNotAssociated/D");
  JetsTree_ -> Branch("ptGenJet",&ptGenJet_,"ptGenJet/D");
  JetsTree_ -> Branch("etaGenJet",&etaGenJet_,"etaGenJet/D");
  JetsTree_ -> Branch("phiGenJet",&phiGenJet_,"phiGenJet/D");
  JetsTree_ -> Branch("dR",&dR_,"dR/D");
  JetsTree_ -> Branch("isMatched",&isMatched_,"isMatched/O");
  JetsTree_ -> Branch("nGenJets",&nGenJets_,"nGenJets/D");
  JetsTree_ -> Branch("nPUVerticesForJets", &nPUVerticesForJets_, "nPUVerticesForJets/I");
 
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
  METTree_  -> Branch("mpt", &mpt_, "mpt/D"); 

}

// ------------ method called to for each event  ------------
void
JetAnalyzer::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
  
  /*****Tree variables initialization******/
  //JetsTree
  nPFCFromPV_             = -999.;
  nPFCFromPU_             = -999.;
  nPFCNotAssociated_      = -999.;
  nMuons_                 = -999.;
  nElectrons_             = -999.;
  nNeutralConstituents_   = -999.;
  nChargedConstituents_   = -999.;
  nConstituents_          = -999.;
  etaRecoJet_             = -999.;
  phiRecoJet_             = -999.;
  ptRecoJet_              = -999.;
  etaGenJet_              = -999.;
  phiGenJet_              = -999.;
  ptGenJet_               = -999.;
  sumPtFromPV_            = -999.;
  sumPtFromPU_            = -999.;
  sumPtNotAssociated_     = -999.;
  chargedMultiplicity_    = -999; 
  dR_                     = 999.;
  isMatched_              = false;
  nGenJets_               = -999.;
  nPUVerticesForJets_     = -999;

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
  mpt_                    = -999.;

  /*****PU info - not  needed so far....*****/
  int nPUVertices         = 0; 

  Handle<vector< PileupSummaryInfo > >  PupInfo;
  iEvent.getByLabel("addPileupInfo", PupInfo);

  vector<PileupSummaryInfo>::const_iterator PVI;

  for(PVI = PupInfo->begin(); PVI != PupInfo->end(); ++PVI) {
    nPUVertices += PVI->getPU_NumInteractions();
  }
  
  nPUVertices_        = nPUVertices;
  nPUVerticesForJets_ = nPUVertices;
    
  /*******************************************/
  /*get vertices collection(for jet matching)*/
  /*******************************************/
  Handle<VertexCollection> vertexColl;
  iEvent.getByLabel(inputTagVertices_, vertexColl);

  
  /*******************************/
  /*****get Jet collections ******/
  /*******************************/
  // define met < PU variables
  double metxPU             = 0.;
  double metyPU             = 0.;
  double mptxPU             = 0.;
  double mptyPU             = 0.;

  //get genJets 
  Handle<GenJetCollection> genJetColl;
  iEvent.getByLabel(inputTagGenJet_, genJetColl);  
  
  //get recoJets
  Handle<PFJetCollection> jetColl;
  iEvent.getByLabel(inputTagJet_, jetColl);

  PFJetCollection::const_iterator jet = jetColl -> begin();
  int jetIndex               = 0;
 
  for(; jet != jetColl -> end(); jet++, jetIndex++){

    //bookkeeping variables
    double nPFCand            = 0.;
    double nPFCCand           = 0.; 
    double nPFNCand           = 0.; 
    double nPFCandFromPV      = 0.;
    double nPFCandFromPU      = 0.;
    double nPFCandNotAssd     = 0.;
    double nMuons             = 0.;
    double nElectrons         = 0.;
    double nPFNoChargedHadron = 0.;
    double sumPtFromPV        = 0.;
    double sumPtFromPU        = 0.;
    double sumPtNotAssd       = 0.;
   
   
    vector <PFCandidatePtr> constituents = jet -> getPFConstituents ();
    nPFCand = constituents.size ();

    for (unsigned ic = 0; ic < nPFCand; ++ic) {
     
      VertexRef vertexref;

      switch( constituents[ic]->particleId() ) {
      case PFCandidate::h:
	nPFCCand++;
	vertexref = chargedHadronVertex( vertexColl, constituents[ic] );
	break;
      case PFCandidate::mu:
	nMuons++;
	continue;
      case PFCandidate::e:
	nElectrons++;
	continue;
      case PFCandidate::h0: 
	nPFNCand++;
	continue;
      case PFCandidate::gamma:
	nPFNCand++;
	continue;
      default:
	nPFNoChargedHadron++;
	continue;
      } 
    
      if( vertexref.key()==0 )  {//hadron associated to the primary vertex
	nPFCandFromPV++;
	sumPtFromPV += constituents[ic]-> pt();
      }
      else if(vertexref.isNull()){//hadron not associated to any vertex
	nPFCandNotAssd++;
	sumPtNotAssd += constituents[ic]-> pt();
      }
      else {//hadron associated to a secondary vertex
	nPFCandFromPU++;
	sumPtFromPU += constituents[ic]-> pt();
	double et = constituents[ic]-> et();
	double phi = constituents[ic]-> phi();
	metxPU += et * cos(phi);
	metyPU += et * sin(phi);
	mptxPU += constituents[ic]-> px();
	mptyPU += constituents[ic]-> py();
      }
     
    }//end loop over consituents

  
    ptRecoJet_             = jet -> pt();
    etaRecoJet_            = jet -> eta();
    phiRecoJet_            = jet -> phi();
    chargedMultiplicity_   = jet -> chargedMultiplicity();
    isMatched_             = isMatched( genJetColl, *jet );

    nPFCFromPV_            = nPFCandFromPV;
    nPFCFromPU_            = nPFCandFromPU;
    nPFCNotAssociated_     = nPFCandNotAssd;
    nMuons_                = nMuons;
    nElectrons_            = nElectrons;
    nNeutralConstituents_  = nPFNCand;
    nChargedConstituents_  = nPFCCand;
    nConstituents_         = nPFCand;
    sumPtFromPV_           = sumPtFromPV;
    sumPtFromPU_           = sumPtFromPU;
    sumPtNotAssociated_    = sumPtNotAssd;
   
    
    JetsTree_ -> Fill();
    
  }// end loop over jets

  /***********************/
  /*****recompute MET****/
  /**********************/
  //get standard met for consistency check
  Handle<PFMETCollection> pfMETColl;
  iEvent.getByLabel(inputTagPFMET_, pfMETColl);
  PFMETCollection::const_iterator pfmet = pfMETColl -> begin();
  stdPFMET_  = pfmet -> et(); 
  stdPFMETx_ = pfmet -> px(); 
  stdPFMETy_ = pfmet -> py(); 
  stdSumEt_  = pfmet -> sumEt(); 

  //get pfCandidates
  Handle<PFCandidateCollection> pfCandColl;
  iEvent.getByLabel(inputTagPFCand_, pfCandColl);

  if (pfCandColl -> size() > 0){
    PFCandidateCollection::const_iterator pfCand = pfCandColl -> begin();
    double metx = 0.;
    double mety = 0.;
    double mpx = 0.;
    double mpy = 0.;
  
    for(; pfCand != pfCandColl -> end(); pfCand++){
      mpx += pfCand -> px();
      mpy += pfCand -> py();
      double et = pfCand -> et();
      double phi = pfCand -> phi();
      metx += et * cos(phi); // e*sin(theta) gives the same distribution (e, theta = pfCand -> energy(), theta())
      mety += et * sin(phi);
      sumEt_ += et;
    }
    mpt_  = sqrt( mpx * mpx + mpy * mpy ) -  sqrt(mptxPU * mptxPU + mptyPU * mptyPU) ;
    met_  = sqrt( metx * metx + mety * mety ) - sqrt(metxPU * metxPU + metyPU * metyPU) ;
    metx_ = metx - metxPU;
    mety_ = mety - metyPU;
  }

  METTree_ ->Fill();

}

/****take a pfCandidate and a collection of vertices, loop through the vertices, try to associate to the pfCand. Copy-paste from PFPileUp.cc*****/
VertexRef 
JetAnalyzer::chargedHadronVertex( const Handle<VertexCollection>& vertices, const PFCandidate& pfcand ) const {

  
  reco::TrackBaseRef trackBaseRef( pfcand.trackRef() );
  
  size_t  iVertex = 0;
  unsigned index=0;
  unsigned nFoundVertex = 0;
  typedef reco::VertexCollection::const_iterator IV;
  float bestweight=0;
  for(IV iv=vertices->begin(); iv!=vertices->end(); ++iv, ++index) {

    const reco::Vertex& vtx = *iv;
    
    typedef reco::Vertex::trackRef_iterator IT;
    
    // loop on tracks in vertices
    for(IT iTrack=vtx.tracks_begin(); 
	iTrack!=vtx.tracks_end(); ++iTrack) {
	 
      const reco::TrackBaseRef& baseRef = *iTrack;

      // one of the tracks in the vertex is the same as 
      // the track considered in the function
      float w = vtx.trackWeight(baseRef);
      if(baseRef == trackBaseRef ) {
	//select the vertex for which the track has the highest weight
	if (w > bestweight){
	  bestweight=w;
	  iVertex=index;
	  nFoundVertex++;
	}	 	
      }
    }
  }

  if (nFoundVertex>0){
    if (nFoundVertex!=1)
      edm::LogWarning("TrackOnTwoVertex")<<"a track is shared by at least two verteces. Used to be an assert";
    return VertexRef( vertices, iVertex);
  }
  // no vertex found with this track. 
  // keep this track

  return VertexRef();
}



/****take a pf Jet, a GenJet collection, loop through the genJets, calculate deltaR and find the min. If this min < 0.4, the pf jet is matched***/
bool 
JetAnalyzer::isMatched(const edm::Handle<reco::GenJetCollection>& genJets, const reco::PFJet& pfjet){

  bool isMatched = false;

  nGenJets_ =  genJets ->size();

  if (genJets ->size()>0) {

    GenJetCollection::const_iterator genJet = genJets -> begin();
  
    double etaPfJet     = pfjet.eta();
    double phiPfJet     = pfjet.phi();

    double dRmin        = 999.;
    double etaGenJetMin = 999.;
    double phiGenJetMin = 999.;
    double ptGenJetMin  = 9999.;
   
    for(; genJet != genJets -> end(); genJet++){
    
      double etaGenJet = genJet -> eta();
      double phiGenJet = genJet -> phi();
      double ptGenJet  = genJet -> pt();

      double dR = deltaR(etaPfJet, phiPfJet, etaGenJet, phiGenJet);
     
      if (dR < dRmin) {
	dRmin = dR;
	etaGenJetMin = etaGenJet ;
	phiGenJetMin = phiGenJet ;
	ptGenJetMin  = ptGenJet ;
      }
    }

    dR_        = dRmin;

    if (dRmin < 0.4) {
      isMatched = true;
      //fill JetTree variables
      etaGenJet_ = etaGenJetMin;
      phiGenJet_ = phiGenJetMin;
      ptGenJet_  = ptGenJetMin;
    }
  }
 
  return isMatched;
}




// ------------ method called once each job just after ending the event loop  ------------
void 
JetAnalyzer::endJob() {

  outputFile_ -> cd();
  outputFile_ -> Write();

}

//Write this as a plug-in
DEFINE_FWK_MODULE(JetAnalyzer);


