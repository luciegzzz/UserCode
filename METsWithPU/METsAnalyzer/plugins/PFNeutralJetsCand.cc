#include "METsWithPU/METsAnalyzer/plugins/PFNeutralJetsCand.h"

using namespace std;
using namespace edm;
using namespace reco;


PFNeutralJetsCand::PFNeutralJetsCand(const edm::ParameterSet& iConfig) {
  


  inputTagPFJets_ 
    = iConfig.getParameter<InputTag>("PFJets");

  enable_ = iConfig.getParameter<bool>("Enable");

  produces<reco::PFCandidateCollection>();//PFNeutralJetsCandCollection ? 
  
}



PFNeutralJetsCand::~PFNeutralJetsCand() { }



void PFNeutralJetsCand::beginJob() { }


void PFNeutralJetsCand::produce(Event& iEvent, 
				const EventSetup& iSetup) {
  
  //   LogDebug("PFNeutralJetsCand")<<"START event: "<<iEvent.id().event()
  //  <<" in run "<<iEvent.id().run()<<endl;
   
  auto_ptr< PFCandidateCollection >  pOutput( new PFCandidateCollection() ); 
  
  if(enable_) {
    //get jets
    Handle<PFJetCollection> pfJets; 
    iEvent.getByLabel(inputTagPFJets_, pfJets);
    
    for (PFJetCollection::const_iterator jet = pfJets->begin(); jet!=pfJets->end(); ++jet){
      if (jet -> chargedMultiplicity() > 0) continue; 
      else  {
	
 	//get the vector of constituents/pf candidates from jets  
 	std::vector < PFCandidatePtr > constituents = jet -> getPFConstituents ();
	
 	for (unsigned int i = 0 ; i < constituents.size(); i++){
	  //cout<< "i "<<endl;
	  //cout<<constituents[i]->pt()<<endl;
	    pOutput -> push_back(PFCandidate(constituents[i])); 
	}

          }//end else
     }//end loop over jets

   }//end if enable
  iEvent.put( pOutput);
}


DEFINE_FWK_MODULE(PFNeutralJetsCand);


