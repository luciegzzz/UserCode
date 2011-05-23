// user include files
#include "METsWithPU/METsAnalyzer/plugins/PFCandSplitByVertex.h"

using namespace std;
using namespace edm;
using namespace reco;

//
// constructors and destructor
//
PFCandSplitByVtx::PFCandSplitByVtx(const edm::ParameterSet& iConfig)

{
  
  inputTagPFCandidates_ 
    = iConfig.getParameter<InputTag>("pfCands");
 
  inputTagVertices_ 
    = iConfig.getParameter<InputTag>("vertices");

  verbose_ 
    = iConfig.getUntrackedParameter<bool>("verbose",false);

  outputFileName_ 
    = iConfig.getUntrackedParameter<string>("outfile");

  vtxIndex_
    = iConfig.getUntrackedParameter<unsigned int>("vtxIndex");

  //  produces<reco::PFCandidateCollection>("pfCandsNotAssociated");
  produces<reco::PFCandidateCollection>("pfCandsVtx0");
  //   produces<reco::PFCandidateCollection>("pfCandsVtx1");
  //   produces<reco::PFCandidateCollection>("pfCandsVtx2");
  //   produces<reco::PFCandidateCollection>("pfCandsVtx3");
  //   produces<reco::PFCandidateCollection>("pfCandsVtx4");
  //   produces<reco::PFCandidateCollection>("pfCandsVtx5");
  //   produces<reco::PFCandidateCollection>("pfCandsVtx6");
  //   produces<reco::PFCandidateCollection>("pfCandsVtx7");
  //   produces<reco::PFCandidateCollection>("pfCandsVtx8");
  //   produces<reco::PFCandidateCollection>("pfCandsVtx9");
  //   produces<reco::PFCandidateCollection>("pfCandsVtx10");
  //   produces<reco::PFCandidateCollection>("pfCandsVtx11");
  //   produces<reco::PFCandidateCollection>("pfCandsVtx12");

}


PFCandSplitByVtx::~PFCandSplitByVtx()
{

}


//
// member functions
//
// ------------ pSetup called once each job just before starting event loop  ------------
void 
PFCandSplitByVtx::beginJob()
{
               
  
}

// ------------ method called to for each event  ------------
void
PFCandSplitByVtx::produce(edm::Event& iEvent, const edm::EventSetup& iSetup)
{

  if( verbose_)
    cout << "Event -------------------- " << iEvent.id().event() << endl;

  const unsigned int nbVtxMax = 1;
  if( verbose_)
    cout << "PFCandSplitByVertex set up to handle " << nbVtxMax << " vertices " << endl;

  /******output collection***********/
  //   auto_ptr< reco::PFCandidateCollection > 
  //     pfCandsNotAssociated( new reco::PFCandidateCollection ); 

  auto_ptr< reco::PFCandidateCollection > 
    pfCandsVtx0( new reco::PFCandidateCollection ); 

  //   auto_ptr< reco::PFCandidateCollection > 
  //     pfCandsVtx1( new reco::PFCandidateCollection ); 

  //   auto_ptr< reco::PFCandidateCollection > 
  //     pfCandsVtx2( new reco::PFCandidateCollection ); 

  //   auto_ptr< reco::PFCandidateCollection > 
  //     pfCandsVtx3( new reco::PFCandidateCollection ); 

  //   auto_ptr< reco::PFCandidateCollection > 
  //     pfCandsVtx4( new reco::PFCandidateCollection ); 

  //   auto_ptr< reco::PFCandidateCollection > 
  //     pfCandsVtx5( new reco::PFCandidateCollection ); 

  //   auto_ptr< reco::PFCandidateCollection > 
  //     pfCandsVtx6( new reco::PFCandidateCollection ); 

  //   auto_ptr< reco::PFCandidateCollection > 
  //     pfCandsVtx7( new reco::PFCandidateCollection ); 

  //   auto_ptr< reco::PFCandidateCollection > 
  //     pfCandsVtx8( new reco::PFCandidateCollection ); 

  //   auto_ptr< reco::PFCandidateCollection > 
  //     pfCandsVtx9( new reco::PFCandidateCollection ); 

  //   auto_ptr< reco::PFCandidateCollection > 
  //     pfCandsVtx10( new reco::PFCandidateCollection ); 

  //   auto_ptr< reco::PFCandidateCollection > 
  //     pfCandsVtx11( new reco::PFCandidateCollection ); 
 
  //   auto_ptr< reco::PFCandidateCollection > 
  //     pfCandsVtx12( new reco::PFCandidateCollection ); 

  /*****get Vertices collection******/

  Handle<VertexCollection> vertices;
  iEvent.getByLabel(inputTagVertices_, vertices);  

  if( verbose_)
    cout <<"number of vertices "<< vertices -> size() << endl;

  if(vertices -> size() < nbVtxMax) {
 
    //  for (unsigned int vtx = 0; vtx < vertices -> size(); vtx++){
    //     reco::PFCandidateCollection  dummy;
    //     pfCansVtx -> push_back(dummy);
    //   }
  
    /*****get PFCandidates collection ******/
    //get pfCandidates
    Handle<PFCandidateCollection> pfCands;
    iEvent.getByLabel(inputTagPFCandidates_, pfCands);  

    if( verbose_)
      cout <<"number of pfCandidates "<< pfCands -> size() << endl;

    for( unsigned int i = 0; i < pfCands -> size(); i++ ) {
    
      PFCandidatePtr candptr(pfCands, i);
    
      VertexRef vertexref;
    
      if ( candptr -> particleId() ==  ( PFCandidate::h || PFCandidate::mu || PFCandidate::e )){
	if( verbose_)
	  cout <<"pfCandidates nr "<< i << " is charged with type " << candptr -> particleId() << " pt "<< candptr -> pt() << " eta " << candptr -> eta() <<endl;
	vertexref = chargedVertex( vertices, *candptr );
      }
    
      else if( verbose_)
	cout <<"pfCandidates nr "<< i << " is neutral with type " << candptr -> particleId() << " pt "<< candptr -> pt() << " eta " << candptr -> eta() <<endl;


      // no associated vertex, or neutral
      if(vertexref.isNull() && (vtxIndex_ == 999)){
	if( verbose_)
	  cout <<"pfCandidates nr "<< i << " : no vertex associated" <<endl;
	pfCandsVtx0 -> push_back(PFCandidate(candptr));
      }
    
      //charged pfCands, associated to a vertex
      else {
	if( verbose_)
	  cout <<"pfCandidates nr "<< i << " is associated to vertex " << vertexref.key()   <<endl;
	if (vertexref.key() == vtxIndex_)       pfCandsVtx0 -> push_back(PFCandidate(candptr));
	//    else if (vertexref.key() == 1)  pfCandsVtx1 -> push_back(PFCandidate(candptr));
	//       else if (vertexref.key() == 2)  pfCandsVtx2 -> push_back(PFCandidate(candptr));
	//       else if (vertexref.key() == 3)  pfCandsVtx3 -> push_back(PFCandidate(candptr));
	//       else if (vertexref.key() == 4)  pfCandsVtx4 -> push_back(PFCandidate(candptr));
	//       else if (vertexref.key() == 5)  pfCandsVtx5 -> push_back(PFCandidate(candptr));
	//       else if (vertexref.key() == 6)  pfCandsVtx6 -> push_back(PFCandidate(candptr));
	//       else if (vertexref.key() == 7)  pfCandsVtx7 -> push_back(PFCandidate(candptr));
	//       else if (vertexref.key() == 8)  pfCandsVtx8 -> push_back(PFCandidate(candptr));
	//       else if (vertexref.key() == 9)  pfCandsVtx9 -> push_back(PFCandidate(candptr));
	//       else if (vertexref.key() == 10) pfCandsVtx10 -> push_back(PFCandidate(candptr));
	//       else if (vertexref.key() == 11) pfCandsVtx11 -> push_back(PFCandidate(candptr));
	//       else if (vertexref.key() == 12) pfCandsVtx12 -> push_back(PFCandidate(candptr));
      }

    }

    //  if (verbose_){
    //     for (unsigned int coll = 0 ; coll < pfCandsVtx -> size() ; coll++){
    //       cout << "size of the pfCandidate collection associated to vertex "<< coll <<" " << (*pfCandsVtx)[coll].size()<<endl;
    //     }
    //   }

  
    //  iEvent.put( pfCandsNotAssociated, "pfCandsNotAssociated" );
    iEvent.put( pfCandsVtx0, "pfCandsVtx0" );
    //   iEvent.put( pfCandsVtx1, "pfCandsVtx1" );
    //   iEvent.put( pfCandsVtx2, "pfCandsVtx2" );
    //   iEvent.put( pfCandsVtx3, "pfCandsVtx3" );
    //   iEvent.put( pfCandsVtx4, "pfCandsVtx4" );
    //   iEvent.put( pfCandsVtx5, "pfCandsVtx5" );
    //   iEvent.put( pfCandsVtx6, "pfCandsVtx6" );
    //   iEvent.put( pfCandsVtx7, "pfCandsVtx7" );
    //   iEvent.put( pfCandsVtx8, "pfCandsVtx8" );
    //   iEvent.put( pfCandsVtx9, "pfCandsVtx9" );
    //   iEvent.put( pfCandsVtx10, "pfCandsVtx10" );
    //   iEvent.put( pfCandsVtx11, "pfCandsVtx11" );
    //   iEvent.put( pfCandsVtx12, "pfCandsVtx12" );
  }
}



VertexRef 
PFCandSplitByVtx::chargedVertex( const Handle<VertexCollection>& vertices, const PFCandidate& pfcand ) const {

  
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
DEFINE_FWK_MODULE(PFCandSplitByVtx);


