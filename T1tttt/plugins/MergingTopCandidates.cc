#include "Lucie/T1tttt/plugins/MergingTopCandidates.h"

using namespace std;


MergingTopCandidates::MergingTopCandidates( const edm::ParameterSet & iConfig ):
  inputTagJets0_(iConfig.getParameter< edm::InputTag >("jets0") ),   
  inputTagJets1_(iConfig.getParameter< edm::InputTag >("jets1") )   
{
   produces < BasicJetCollection >   ("topCandidates") ;  
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

  std::auto_ptr< BasicJetCollection >    jOutput(new BasicJetCollection());

  //grab jets 0
  edm::Handle< BasicJetCollection > jets0 ;
  //int nJets0 = -10;
  try {
    iEvent.getByLabel( inputTagJets0_, jets0);
    //nJets0 = jets0 -> size();
    //    cout << "jet collection contains " << nJets0 << " jets " << inputTagJets0_ << endl  ;
  }
  catch (exception &e)
    {
      cout << "no jets found " << inputTagJets0_ << endl;
    }
  //grab jets 1
  edm::Handle< BasicJetCollection > jets1 ;
  //int nJets1 = -10;
  try {
    iEvent.getByLabel( inputTagJets1_, jets1);
    //nJets1 = jets1 -> size();
    // cout << "jet collection contains " << nJets1 << " jets " << inputTagJets1_ << endl  ;
  }
  catch (exception &e)
    {
      cout << "no jets found " << inputTagJets1_ << endl;
    }

  //copy jets0 collection
  for ( BasicJetCollection::const_iterator it_jet0 = jets0 -> begin() ; it_jet0 != jets0 -> end() ; it_jet0++ ){
      jOutput -> push_back( *it_jet0 );
    }
  //look for new candidates
  for ( BasicJetCollection::const_iterator it_jet1 = jets1 -> begin() ; it_jet1 != jets1 -> end() ; it_jet1++ ){
    double dR = 1000.;
    for ( BasicJetCollection::const_iterator it_jet0 = jets0 -> begin() ; it_jet0 != jets0 -> end() ; it_jet0++ ){
      dR = min(dR, deltaR( it_jet1 -> eta(), it_jet1 -> phi(), it_jet0 -> eta(), it_jet0 -> phi()));
   }
    if (dR > 0.4)
      jOutput -> push_back( *it_jet1 );
  }

    iEvent.put( jOutput , "topCandidates" );
  
}


//define this as a plug-in

DEFINE_FWK_MODULE(MergingTopCandidates);

