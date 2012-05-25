#include "Lucie/TurnOnAnalyzer/interface/TurnOnAnalyzer.h"

using namespace std;

TurnOnAnalyzer::TurnOnAnalyzer(const edm::ParameterSet& iConfig):
  triggerResults_(iConfig.getParameter< edm::InputTag >("triggerResults") ),
  jets_(iConfig.getParameter< edm::InputTag >("jets") ),
  met_(iConfig.getParameter< edm::InputTag >("met") ),
  fOutputFileName_(iConfig.getUntrackedParameter<string>("filename") )
{
}

TurnOnAnalyzer::~TurnOnAnalyzer()
{ 
}


// ------------ method called for each event  ------------
void
TurnOnAnalyzer::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
  int EvtInfo_Run   = iEvent.id().run();
  int EvtInfo_Event = iEvent.id().event();

  edm::Handle< bool > ecalDeadCell ;
  iEvent.getByLabel( "ecalDeadCellTPfilter", ecalDeadCell );

  edm::Handle< bool > HBHE ;
  iEvent.getByLabel("HBHENoiseFilterResultProducer2011NonIsoRecommended", "HBHENoiseFilterResult", HBHE  );

  edm::Handle< bool > eeNoiseFilter ;
  iEvent.getByLabel( "eeNoiseFilter", "Result", eeNoiseFilter );

  edm::Handle< bool > goodPV ;
  iEvent.getByLabel( "goodPrimaryVertexFilter",  "Result", goodPV  );

  edm::Handle< bool > greedyMuonsTagging ;
  iEvent.getByLabel( "greedyMuonsTagging",  "Result", greedyMuonsTagging );
 
  edm::Handle< bool > inconsistentMuonsTagging ;
  iEvent.getByLabel( "inconsistentMuonsTagging", "Result", inconsistentMuonsTagging  );
 
  edm::Handle< bool > recovRecHitFilter ;
  iEvent.getByLabel( "recovRecHitFilter", "Result", recovRecHitFilter  );

  edm::Handle< bool > scrapingFilter ;
  iEvent.getByLabel( "scrapingFilter", "Result",  scrapingFilter );

  bool filter = *ecalDeadCell && *HBHE && *eeNoiseFilter && *goodPV && *greedyMuonsTagging && *inconsistentMuonsTagging && *recovRecHitFilter && *scrapingFilter ;
 
  if (filter) {

 
  /*******************/
  /*get inputs       */
  /*******************/
  edm::Handle< TriggerObjectCollection > triggerRes;
  edm::Handle< JetCollection >                 jets;
  edm::Handle< METCollection >                  met;

  try {
    iEvent.getByLabel( triggerResults_, triggerRes );
  }   
  catch (exception &e)
    {
      cout << "no trigger results found " << triggerResults_ << endl ;
    }  

  int nJets = -10;
  try {
    iEvent.getByLabel( jets_, jets);
    nJets = jets -> size();
  }
  catch (exception &e)
    {
      cout << "no jet found " << jets_ << endl;
    }
  
  try {
    iEvent.getByLabel( met_, met);
  }   
  catch (exception &e)
    {
      cout << "no reco jet found " << jets_ << endl ;
    }
                
  /************************/
  /**2Jets + MET turn-on***/
  /************************/
  //MET                
  //check number of central jets
  unsigned int nCentralJetsPlateau = 0;
  unsigned int nCentralJets        = 0;
  double leadJetPt = -10.;
  double secondJetPt  = -10.;
  for ( JetCollection::const_iterator itJet = jets -> begin() ; itJet != jets -> end() ; itJet++ ){

    if (  abs( itJet -> eta() ) < 2.4 ){
      nCentralJets ++;
      if( itJet -> pt() > ptPlateau ){
	nCentralJetsPlateau++;
	if ( nCentralJetsPlateau == 1  )
	  leadJetPt = itJet -> pt();
	else if ( nCentralJetsPlateau == 2  )
	  secondJetPt = itJet -> pt();
      }
    }
  }
  double metpt = met -> begin() -> pt() ;

  if ( nCentralJetsPlateau > 1 ){

    h_denMET_ -> Fill( metpt );

    if ( triggerRes -> begin() -> getSelectionRegExp("^HLT_DiCentralPFJet50_PFMET80.*_v[0-9]+$")) {
      h_numMET_ -> Fill( metpt );
    }

  }

  //Jets
  if ( nCentralJetsPlateau > 0. && nCentralJets > 1 && metpt > metPlateau ){
    h_denDiJet_ -> Fill( secondJetPt );
    if ( triggerRes -> begin() -> getSelectionRegExp("^HLT_DiCentralPFJet50_PFMET80.*_v[0-9]+$")) {
      h_numDiJet_ -> Fill( secondJetPt );
    }
  }

  }

  
  else 
    cout << "failed  filters " << endl;

}//end analyze


// ------------ method called once each job just before starting event loop  ------------
void 
TurnOnAnalyzer::beginJob()
{

  outputFile_              = new TFile( fOutputFileName_.c_str(), "RECREATE" );

  h_numMET_                = new TH1F("h_numMET", "MET distribution, numerator", 100, 0., 500.);
  h_denMET_                = new TH1F("h_denMET", "MET distribution, denominator", 100, 0., 500.);

  h_numDiJet_                = new TH1F("h_numDiJet", "2nd jet pt distribution, numerator", 100, 0., 500.);
  h_denDiJet_                = new TH1F("h_denDiJet", "2nd jet pt distribution, denominator", 100, 0., 500.);  

  ptPlateau =  80.;
  metPlateau = 200.;
}

// ------------ method called once each job just after ending the event loop  ------------
void 
TurnOnAnalyzer::endJob() 
{

  outputFile_->cd();

  h_numMET_    -> Write();
  h_denMET_    -> Write();

  h_ratioMET_  = (TH1F*)h_numMET_ -> Clone("h_ratioMET");
  h_ratioMET_  -> Divide( h_denMET_ );
  h_ratioMET_  -> Write();

  h_numDiJet_    -> Write();
  h_denDiJet_    -> Write();

  h_ratioDiJet_  = (TH1F*)h_numDiJet_ -> Clone("h_ratioDiJet");
  h_ratioDiJet_  -> Divide( h_denDiJet_ );
  h_ratioDiJet_  -> Write();


}


//define this as a plug-in
DEFINE_FWK_MODULE(TurnOnAnalyzer);

