#include "Lucie/RateAnalyzer/interface/RateAnalyzer.h"

using namespace std;

RateAnalyzer::RateAnalyzer(const edm::ParameterSet& iConfig):
  triggerResults_(iConfig.getParameter< edm::InputTag >("triggerResults") ),
  normFactor_(iConfig.getUntrackedParameter< double >("normalizationFactor") ),
  fOutputFileName_(iConfig.getUntrackedParameter<string>("filename") )
{
}

RateAnalyzer::~RateAnalyzer()
{ 
}


// ------------ method called for each event  ------------
void
RateAnalyzer::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
  //int EvtInfo_Run   = iEvent.id().run();
  //int EvtInfo_Event = iEvent.id().event();

 
  /*******************/
  /*  get inputs     */
  /*******************/
  edm::Handle< edm::TriggerResults >     triggerRes;

  //trigger results
  try {
    iEvent.getByLabel( triggerResults_, triggerRes );
  }   
  catch (exception &e)
    {
      cout << "no trigger results found " << triggerResults_ << endl ;
    }  

 
 
  /*****************/
  /*** get rates ***/
  /*****************/

   const edm::TriggerNames & names = iEvent.triggerNames(*triggerRes);
    
    for ( unsigned int i = 0 ; i < names.size() ; i++){
      listOfNameToRate_[names.triggerName(i)] += triggerRes -> accept( i );
    }
     
 
}//end analyze


// ------------ method called once each job just before starting event loop  ------------
void 
RateAnalyzer::beginJob()
{
  outputFile_              = new TFile( fOutputFileName_.c_str(), "RECREATE" ); 
}

// ------------ method called once each job just after ending the event loop  ------------
void 
RateAnalyzer::endJob() 
{

  outputFile_->cd();

  for (  map<string, int>::iterator it = listOfNameToRate_.begin() ; it != listOfNameToRate_.end() ; ++it){
    cout << it ->first << " " << (it -> second) * normFactor_ /1000 << " kHz " << endl;
    }

}


//define this as a plug-in
DEFINE_FWK_MODULE(RateAnalyzer);

