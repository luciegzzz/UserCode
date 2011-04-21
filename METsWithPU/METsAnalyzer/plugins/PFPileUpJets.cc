
//
// Original Author:  "Lucie Gauthier"
//         
// $Id: PFPileUpJets.cc,v 1.1 2011/04/21 13:43:35 lucieg Exp $
//
//

// user include files
#include "METsWithPU/METsAnalyzer/plugins/PFPileUpJets.h"

using namespace std;
using namespace edm;
using namespace reco;

//
// constructors and destructor
//
PFPileUpJets::PFPileUpJets(const edm::ParameterSet& iConfig)

{
  
  inputTagJets_ 
    = iConfig.getParameter<InputTag>("jets");
 
  inputTagVertices_ 
    = iConfig.getParameter<InputTag>("vertices");

  produces<reco::PFJetCollection>();

}


PFPileUpJets::~PFPileUpJets()
{

}


//
// member functions
//
// ------------ pSetup called once each job just before starting event loop  ------------
void 
PFPileUpJets::beginJob()
{
               
  
}

// ------------ method called to for each event  ------------
void
PFPileUpJets::produce(edm::Event& iEvent, const edm::EventSetup& iSetup)
{

  /******output collection***********/
  auto_ptr< reco::PFJetCollection > 
    pOutput( new reco::PFJetCollection ); 

  /*****get Vertices collection******/

  Handle<VertexCollection> vertexColl;
  iEvent.getByLabel(inputTagVertices_, vertexColl);  
  
  /*****get Jet collection ******/

  Handle< View<PFJet> > jetColl;
  iEvent.getByLabel(inputTagJets_, jetColl);

  for(unsigned int jetIndex = 0 ; jetIndex < jetColl ->size();  jetIndex++){
      
    if ((*jetColl)[jetIndex].chargedMultiplicity() == 0) continue;

    double nPFCCand      = 0.;
    double nPFCandFromPV = 0.;
    double nPFCandFromPU = 0.;
   
    vector <PFCandidatePtr> constituents = (*jetColl)[jetIndex].getPFConstituents ();

    for (unsigned ic = 0; ic < constituents.size(); ++ic) {
    
      VertexRef vertexref;

      switch( constituents[ic]->particleId() ) {
      case PFCandidate::h:
	nPFCCand++;
	vertexref = chargedHadronVertex( vertexColl, constituents[ic] );
	break;
      default:
	continue;
      } 
    
      // no associated vertex, or primary vertex
      // not pile-up
      if( vertexref.isNull() ||  vertexref.key()==0 )  {
	nPFCandFromPV++;
      }
      else {
	nPFCandFromPU++;
      }
    }//end loop over consituents
    
    if (nPFCandFromPV ==0){//cut to decide whether PU jet or not
      //if ((nPFCandFromPV ==0) && (nPFCandFromPU > 0)){//cut to decide whether PU jet or not
      //if (nPFCandFromPV > nPFCandFromPU){//cut to decide whether PU jet or not
      //if (nPFCandFromPU/nChargedConstituents > 0.8){//cut to decide whether PU jet or not
      PFJet pileUpJet = (*jetColl)[jetIndex];
      pOutput -> push_back(pileUpJet);
    }
  
  }// end loop over jets

  iEvent.put(pOutput);
  
}



VertexRef 
PFPileUpJets::chargedHadronVertex( const Handle<VertexCollection>& vertices, const PFCandidate& pfcand ) const {

  
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


//Write this as a plug-in
DEFINE_FWK_MODULE(PFPileUpJets);


