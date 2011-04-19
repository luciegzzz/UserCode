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
// $Id: JetAnalyzer.cc,v 1.5 2011/04/19 18:21:09 lucieg Exp $
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
  
  inputTagJet_ 
    = iConfig.getParameter<InputTag>("jets");

  inputTagGenJet_ 
    = iConfig.getParameter<InputTag>("genJets");
 
  inputTagVertices_ 
    = iConfig.getParameter<InputTag>("vertices");
 
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

  METTree_ = new TTree("METTree", "METTree");
  METTree_ -> Branch("nPFCFromPV",&nPFCFromPV_,"nPFCFromPV/D");
  METTree_ -> Branch("nPFCFromPU",&nPFCFromPU_,"nPFCFromPU/D");
  METTree_ -> Branch("nPFCNotAssociated",&nPFCNotAssociated_,"nPFCNotAssociated/D");
  METTree_ -> Branch("nChargedConstituents",&nChargedConstituents_,"nChargedConstituents/D");
  METTree_ -> Branch("nConstituents",&nConstituents_,"nConstituents/D");
  METTree_ -> Branch("nMuons",&nMuons_,"nMuons/D");
  METTree_ -> Branch("nElectrons",&nElectrons_,"nElectrons/D");
  METTree_ -> Branch("ptRecoJet",&ptRecoJet_,"ptRecoJet/D");
  METTree_ -> Branch("etaRecoJet",&etaRecoJet_,"etaRecoJet/D");
  METTree_ -> Branch("phiRecoJet",&phiRecoJet_,"phiRecoJet/D");
  METTree_ -> Branch("chargedMultiplicity",&chargedMultiplicity_,"chargedMultiplicity/I");
  METTree_ -> Branch("sumPtFromPV",&sumPtFromPV_,"sumPtFromPV/D");
  METTree_ -> Branch("sumPtFromPU",&sumPtFromPU_,"sumPtFromPU/D");
  METTree_ -> Branch("sumPtNotAssociated",&sumPtNotAssociated_,"sumPtNotAssociated/D");
  METTree_ -> Branch("ptGenJet",&ptGenJet_,"ptGenJet/D");
  METTree_ -> Branch("etaGenJet",&etaGenJet_,"etaGenJet/D");
  METTree_ -> Branch("phiGenJet",&phiGenJet_,"phiGenJet/D");
  METTree_ -> Branch("dR",&dR_,"dR/D");

  METTree_ -> Branch("isMatched",&isMatched_,"isMatched/O");
 
}

// ------------ method called to for each event  ------------
void
JetAnalyzer::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
  /*****get Vertices collections and fill vertices (only) histograms******/

  int nPUVertices         = 0; //PU vertices -not  needed so far....
  nPFCFromPV_             = -999.;
  nPFCFromPU_             = -999.;
  nPFCNotAssociated_      = -999.;
  nMuons_                 = -999.;
  nElectrons_             = -999.;
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
  isMatched_              = false;

  Handle<std::vector< PileupSummaryInfo > >  PupInfo;
  iEvent.getByLabel("addPileupInfo", PupInfo);

  std::vector<PileupSummaryInfo>::const_iterator PVI;

  for(PVI = PupInfo->begin(); PVI != PupInfo->end(); ++PVI) {
    nPUVertices += PVI->getPU_NumInteractions();
  }
  
    
  /*******************************************/
  /*get vertices collection(for jet matching)*/
  /*******************************************/
  Handle<VertexCollection> vertexColl;
  iEvent.getByLabel(inputTagVertices_, vertexColl);

  
  /*******************************/
  /*****get Jet collections ******/
  /*******************************/
  //get genJets 
  Handle<GenJetCollection> genJetColl;
  iEvent.getByLabel(inputTagGenJet_, genJetColl);  
  
  //get recoJets
  Handle<PFJetCollection> jetColl;
  iEvent.getByLabel(inputTagJet_, jetColl);

  PFJetCollection::const_iterator jet = jetColl -> begin();
  int jetIndex               = 0;
 
  for(; jet != jetColl -> end(); jet++, jetIndex++){

  
    //  //cout <<"chargedMultiplicity "<<jet -> chargedMultiplicity()<<endl;
    //     if (jet -> chargedMultiplicity() == 0){
    //       nNeutralJets++;
    //       continue;
    //     }

    //genJet matching
    bool matchedJet = isMatched( genJetColl, *jet );

    //bookkeeping variables
    double nPFCand            = 0.;
    double nPFCCand           = 0.; 
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
      default:
	nPFNoChargedHadron++;
	continue;
      } 
    
      if( vertexref.key()==0 )  {//PV associated
	nPFCandFromPV++;
	sumPtFromPV += constituents[ic]-> pt();
      }
      else if(vertexref.isNull()){//no vertex associated
	nPFCandNotAssd++;
	sumPtNotAssd += constituents[ic]-> pt();
      }
      else {//PU associated
	nPFCandFromPU++;
	sumPtFromPU += constituents[ic]-> pt();
      }
     
    }//end loop over consituents

  
    ptRecoJet_             = jet -> pt();
    etaRecoJet_            = jet -> eta();
    phiRecoJet_            = jet -> phi();
    chargedMultiplicity_   = jet -> chargedMultiplicity();

    nPFCFromPV_            = nPFCandFromPV;
    nPFCFromPU_            = nPFCandFromPU;
    nPFCNotAssociated_     = nPFCandNotAssd;
    nMuons_                = nMuons;
    nElectrons_            = nElectrons;
    nChargedConstituents_  = nPFCCand;
    nConstituents_         = nPFCand;
    sumPtFromPV_           = sumPtFromPV;
    sumPtFromPU_           = sumPtFromPU;
    sumPtNotAssociated_    = sumPtNotAssd;
    
    isMatched_             = matchedJet;
    
    METTree_ -> Fill();
    
  }// end loop over jets

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
 
  if (genJets ->size()>0) {

    GenJetCollection::const_iterator genJet = genJets -> begin();
  
    double etaPfJet     = pfjet.eta();
    double phiPfJet     = pfjet.phi();

    double dRmin     = 999.;
    double etaGenJet = 999.;
    double phiGenJet = 999.;
    double ptGenJet  = 9999.;
 
    for(; genJet != genJets -> end(); genJet++){

      double dR = deltaR(etaPfJet, phiPfJet, etaGenJet, phiGenJet);

      if (dR < dRmin) {
	dRmin = dR;
	etaGenJet = genJet -> eta();
	phiGenJet = genJet -> phi();
	ptGenJet  = genJet -> pt();
      }

    }

    if (dRmin < 0.4) {

      isMatched = true;
    
      dR_        = dRmin;
      etaGenJet_ = etaGenJet;
      phiGenJet_ = phiGenJet;
      ptGenJet_  = ptGenJet;

    }
  }

 
  return isMatched;
}




// ------------ method called once each job just after ending the event loop  ------------
void 
JetAnalyzer::endJob() {
  outputFile_->cd();
  outputFile_->Write();

}

//Write this as a plug-in
DEFINE_FWK_MODULE(JetAnalyzer);


