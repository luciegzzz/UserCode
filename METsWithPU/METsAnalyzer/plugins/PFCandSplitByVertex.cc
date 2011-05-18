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

  produces<std::vector<reco::PFCandidateCollection> >();

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

  /******output collection***********/
  std::auto_ptr<std::vector<reco::PFCandidateCollection > >
    pOutput( new std::vector<reco::PFCandidateCollection > ); 

  /*****get Vertices collection******/

  Handle<VertexCollection> vertices;
  iEvent.getByLabel(inputTagVertices_, vertices);  

  if( verbose_)
  cout <<"number of vertices "<< vertices -> size() << endl;

  for (unsigned int vtx = 0; vtx < vertices -> size(); vtx++){
    reco::PFCandidateCollection  dummy;
    pOutput -> push_back(dummy);
  }
  
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
	cout <<"pfCandidates nr "<< i << "is charged" <<endl;
      vertexref = chargedVertex( vertices, *candptr );
    }
    
    // no associated vertex, or neutral
    if(vertexref.isNull()){
      if( verbose_)
	cout <<"pfCandidates nr "<< i << " : no vertex associated" <<endl;
      (*pOutput)[0].push_back(PFCandidate(candptr));
    }
    
    //charged pfCands, associated to a vertex
    else {
      if( verbose_)
	cout <<"pfCandidates nr "<< i << " is associated to vertex " << vertexref.key()   <<endl;
      (*pOutput)[vertexref.key()].push_back(PFCandidate(candptr));
    }

  }

  if (verbose_){
    for (unsigned int coll = 0 ; coll < pOutput -> size() ; coll++){
      cout << "size of the pfCandidate collection associated to vertex "<< coll <<" " << (*pOutput)[coll].size()<<endl;
    }
  }

  
  iEvent.put(pOutput);
  
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


