#include "Lucie/ThirdGeneration/plugins/MergingTopCandidates.h"

using namespace std;


MergingTopCandidates::MergingTopCandidates( const edm::ParameterSet & iConfig ):
  inputTagJets0_(iConfig.getParameter< edm::InputTag >("jets0") ),   
  inputTagJets1_(iConfig.getParameter< edm::InputTag >("jets1") ),
  weightsfile_( iConfig.getUntrackedParameter< std::string >("weightsfile") ),
  mva_(weightsfile_.c_str())
{
   
  produces < TopJetCollection >   ("topCandidates") ;  
}


MergingTopCandidates::~MergingTopCandidates()
{
  ;
}


void
MergingTopCandidates::beginRun( edm::Run& run,const edm::EventSetup & es )
{
  ;
}


void
MergingTopCandidates::produce( edm::Event& iEvent, const edm::EventSetup& iSetup )
{

  std::auto_ptr< TopJetCollection >    jOutput(new TopJetCollection());

  //grab jets 0
  edm::Handle< TopJetCollection > jets0 ;
  int nJets0 = -10;
  try {
    iEvent.getByLabel( inputTagJets0_, jets0);
    nJets0 = jets0 -> size();
    //    cout << "jet collection contains " << nJets0 << " jets " << inputTagJets0_ << endl  ;
  }
  catch (exception &e)
    {
      cout << "no jets found " << inputTagJets0_ << endl;
    }
  //grab jets 1
  edm::Handle< TopJetCollection > jets1 ;
  int nJets1 = -10;
  try {
    iEvent.getByLabel( inputTagJets1_, jets1);
    nJets1 = jets1 -> size();
    // cout << "jet collection contains " << nJets1 << " jets " << inputTagJets1_ << endl  ;
  }
  catch (exception &e)
    {
      cout << "no jets found " << inputTagJets1_ << endl;
    }

 
  //loop over new collection from which top cands could be grabbed
  for ( TopJetCollection::const_iterator it_jet1 = jets1 -> begin() ; it_jet1 != jets1 -> end() ; it_jet1++ ){
    //does it match any top candidate in the existing collection ?
    double dR = 1000.;
    TopJetCollection::const_iterator it_Closestjet0;
    for ( TopJetCollection::const_iterator it_jet0 = jets0 -> begin() ; it_jet0 != jets0 -> end() ; it_jet0++ ){
      double dRtmp = dR ;
      dR = min(dR, deltaR( it_jet1 -> eta(), it_jet1 -> phi(), it_jet0 -> eta(), it_jet0 -> phi()));
      if (dRtmp != dR){
	it_Closestjet0 = it_jet0;
      }
    }
    
    //Merge similar candidates
    if ( dR < 0.3){//there is already a similar candidate in the top candidate collection : keep candidate with higher topTag
      if ( it_Closestjet0 -> topTag() < it_jet1 -> topTag() ){
	jOutput -> push_back( *it_jet1 );
      }
      else {
	jOutput -> push_back( *it_Closestjet0 );
      }
    }
    else { // new candidate !
      jOutput -> push_back( *it_jet1 );
    }
  }

  //we still need to add back jets from jets0 that are further away than 0.3 of any jet1
  for ( TopJetCollection::const_iterator it_jet0 = jets0 -> begin() ; it_jet0 != jets0 -> end() ; it_jet0++ ){
    double dR = 1000.;
    for ( TopJetCollection::const_iterator it_jet1 = jets1 -> begin() ; it_jet1 != jets1 -> end() ; it_jet1++ ){
      dR = min(dR, deltaR( it_jet1 -> eta(), it_jet1 -> phi(), it_jet0 -> eta(), it_jet0 -> phi()));
    }
    if (dR > 0.3){
      jOutput -> push_back( *it_jet0 );
    }
  }
 
  iEvent.put( jOutput , "topCandidates" );
  
}


//define this as a plug-in

DEFINE_FWK_MODULE(MergingTopCandidates);

