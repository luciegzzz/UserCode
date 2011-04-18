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
// $Id: JetAnalyzer.cc,v 1.25 2011/04/14 13:54:00 lucieg Exp $
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

  //histograms definition
    /**vertices distributions**/
    h_nPUVertices_                = new TH1D("h_nPUVertices", "nr of PU vertices", 50, 0, 50);

    h_PFCFromPUOverTOT_           = new TH1D("h_PFCFromPUOverTOT", "charged hadrons from PU over tot charged hadrons", 110, 0., 1.1);
    h_PFCFromPVOverTOT_           = new TH1D("h_PFCFromPVOverTOT", "charged hadrons from PV over tot charged hadrons", 110, 0., 1.1);
    h_sumEtFromPU_                = new TH1D("h_sumEtFromPU", "sum Et charged hadrons from PU over sumEt charged hadrons", 110, 0., 1.1);
    h_sumEtFromPV_                = new TH1D("h_sumEtFromPV", "sum Et charged hadrons from PV over sumEt charged hadrons", 110, 0., 1.1);
    h_sumEtPUOverPVVsFracPU_      = new TH2D("h_sumEtPUOverPVVsFracPU", "sumEt from PU over sumEt from PV vs frac of PU candidates",110, 0., 1.1, 500, 0., 5. );
    h_sumEtPUOverPVVsFracPV_      = new TH2D("h_sumEtPUOverPVVsFracPV", "sumEt from PU over sumEt from PV vs frac of ~PV candidates",110, 0., 1.1, 500, 0., 5. );
    h_neutralJetsOverTot_         = new TH1D("h_neutralJetsOverTOT", "neutral jets fraction", 110, 0., 1.1);
    h_jetFromPVOverGenJet_        = new TH1D("h_jetFromPVOverGenJet", "#jet from PV over # genJet", 110, 0., 1.1);
    h_nConstituents_              = new TH1D("h_nConstituents","nr of charged hadrons in jets", 75, 0., 75.);
    h_PFCFromPUOverTOTVsnConst_   = new TH2D("h_PFCFromPUOverTOTVsnConst", "charged hadrons from PU over tot charged hadrons vs nr of charged constituents", 75, 0., 75., 110, 0., 1.1 );
    h_dR_                          = new TH1D("deltaR","dR",200, 0., 2.);

}

// ------------ method called to for each event  ------------
void
JetAnalyzer::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{

  /*****get Vertices collections and fill vertices (only) histograms******/

  //PU vertices
  int nPUVertices = 0;

  Handle<std::vector< PileupSummaryInfo > >  PupInfo;
    iEvent.getByLabel("addPileupInfo", PupInfo);

    std::vector<PileupSummaryInfo>::const_iterator PVI;

    for(PVI = PupInfo->begin(); PVI != PupInfo->end(); ++PVI) {
      nPUVertices += PVI->getPU_NumInteractions();
    }
    h_nPUVertices_    -> Fill(nPUVertices);
    
  Handle<VertexCollection> vertexColl;
  iEvent.getByLabel(inputTagVertices_, vertexColl);

  
  /*******************************/
  /*****get Jet collections ******/
  /*******************************/
  //get genJets info
  Handle<GenJetCollection> genJetColl;
  iEvent.getByLabel(inputTagGenJet_, genJetColl);
  
  double nGenJet = genJetColl -> size();
  
  //reco Jets
  Handle<PFJetCollection> jetColl;
  iEvent.getByLabel(inputTagJet_, jetColl);

  PFJetCollection::const_iterator jet = jetColl -> begin();
  int jetIndex        = 0;
  double nNeutralJets = 0.;
  double nJetsFromPV  = 0.;

  for(; jet != jetColl -> end(); jet++, jetIndex++){

    //cout <<"chargedMultiplicity "<<jet -> chargedMultiplicity()<<endl;
    if (jet -> chargedMultiplicity() == 0){
      nNeutralJets++;
      continue;
    }

    //genJet matching
    bool matchedJet = isMatched( genJetColl, *jet );

    //bookkeeping
    //cout << "reading "<< jetIndex << "th jetIndex"<<endl;
    double nPFCand            = 0.;
    double nPFCCand           = 0.;
    double nPFCandFromPV      = 0.;
    double nPFCandFromPU      = 0.;
    double nPFNoChargedHadron = 0.;
    double nJetsFromPV        = 0.;
    double sumEtFromPV        = 0.;
    double sumEtFromPU        = 0.;
    double sumEtC             = 0.;

    vector <PFCandidatePtr> constituents = jet -> getPFConstituents ();

    nPFCand = constituents.size ();

    for (unsigned ic = 0; ic < nPFCand; ++ic) {
      //cout<<"reading "<<ic << "th pfCand"<<endl;
     
      VertexRef vertexref;

      switch( constituents[ic]->particleId() ) {
      case PFCandidate::h:
	//cout <<"found a charged hadron\n";
        nPFCCand++;
	sumEtC += constituents[ic]->et();
   	vertexref = chargedHadronVertex( vertexColl, constituents[ic] );
	break;
      default:
	//cout <<"not a charged hadron\n";
	nPFNoChargedHadron++;
	continue;
      } 
    
      // no associated vertex, or primary vertex
      // not pile-up
      if( vertexref.isNull() ||  vertexref.key()==0 )  {
	nPFCandFromPV++;
	sumEtFromPV += constituents[ic]->et();
	//cout<<"increased PV"<<endl;
      }
      else {
	//	cout <<"no PV increase"<<endl;
	nPFCandFromPU++;
	sumEtFromPU += constituents[ic]->et();
      }
     
    }//end loop over consituents

   
    h_PFCFromPUOverTOT_         -> Fill(nPFCandFromPU / nPFCCand);
    h_PFCFromPVOverTOT_         -> Fill(nPFCandFromPV / nPFCCand);
    h_sumEtFromPU_              -> Fill(sumEtFromPU/sumEtC);
    h_sumEtFromPV_              -> Fill(sumEtFromPV/sumEtC);
    h_nConstituents_            -> Fill(nPFCCand);
    h_PFCFromPUOverTOTVsnConst_ -> Fill(nPFCCand, nPFCandFromPU / nPFCCand);
    
    h_sumEtPUOverPVVsFracPU_    -> Fill(nPFCandFromPU / nPFCCand,sumEtFromPU/sumEtFromPV);
    h_sumEtPUOverPVVsFracPV_    -> Fill(nPFCandFromPV / nPFCCand,sumEtFromPU/sumEtFromPV);

    if ((nPFCandFromPV / nPFCCand) > 0.99) nJetsFromPV++;
    cout <<nPFCandFromPV / nPFCCand<<" "<<nJetsFromPV<<endl;
    //     cout << "from PV "<< nPFCandFromPV <<endl;
    //     cout << "from PU "<< nPFCandFromPU <<endl;
    //     cout << "tot N "<< nPFNoChargedHadron <<endl;
    //     cout << "tot C "<< nPFCCand <<endl;
    //     cout << "tot "<< nPFCand <<endl;

  
  }// end loop over jets



  h_jetFromPVOverGenJet_ -> Fill(nJetsFromPV/nGenJet);
  
  h_neutralJetsOverTot_  -> Fill(nNeutralJets/(jetColl -> size()));

 
 
}


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




bool 
JetAnalyzer::isMatched(const edm::Handle<reco::GenJetCollection>& genJets, const reco::PFJet& pfjet){

  bool isMatched = false;
 
  GenJetCollection::const_iterator genJet = genJets -> begin();
  
  double etaPfJet     = pfjet.eta();
  double phiPfJet     = pfjet.phi();

  vector<double> v_dR;

  for(; genJet != genJets -> end(); genJet++){

    double etaGenJet = genJet -> eta();
    double phiGenJet = genJet -> phi();
    double dR = deltaR(etaPfJet, phiPfJet, etaGenJet, phiGenJet);
    v_dR.push_back(dR);
  }

  double dR_min = *(min_element(v_dR.begin(), v_dR.end()));

  h_dR_  -> Fill(dR_min);

  if (dR_min < 0.4) isMatched = true;
  return isMatched;
}




// ------------ method called once each job just after ending the event loop  ------------
void 
JetAnalyzer::endJob() {
  outputFile_->cd();


  h_nPUVertices_              -> Write();
  h_PFCFromPUOverTOT_         -> Write();
  h_PFCFromPVOverTOT_         -> Write();
  h_neutralJetsOverTot_       -> Write();
  h_jetFromPVOverGenJet_      -> Write();
  h_sumEtFromPU_              -> Write();
  h_sumEtFromPV_              -> Write();
  h_sumEtPUOverPVVsFracPU_    -> Write();
  h_sumEtPUOverPVVsFracPV_    -> Write();
  h_nConstituents_            -> Write(); 
  h_PFCFromPUOverTOTVsnConst_ -> Write();
  h_dR_                        -> Write();
}

//Write this as a plug-in
DEFINE_FWK_MODULE(JetAnalyzer);


