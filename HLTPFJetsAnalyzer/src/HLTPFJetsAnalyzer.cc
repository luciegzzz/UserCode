#include "Lucie/HLTPFJetsAnalyzer/interface/HLTPFJetsAnalyzer.h"

using namespace std;

template<typename T, typename U>
HLTPFJetsAnalyzer<T, U>::HLTPFJetsAnalyzer(const edm::ParameterSet& iConfig):
  hltjets_(iConfig.getParameter< edm::InputTag >("hltjets") ),
  recojets_(iConfig.getParameter< edm::InputTag >("recojets") ),
  dRMatched_(iConfig.getUntrackedParameter<double>("dRMatched") ),
  etaBinning_(iConfig.getUntrackedParameter<uint>("etaBinning") ),
  binWidthEta_(iConfig.getUntrackedParameter<double>("etaBinningResp") ),
  binWidthPt_(iConfig.getUntrackedParameter<double>("ptBinningResp") ),
  fOutputFileName_(iConfig.getUntrackedParameter<string>("filename") )
{
}

template<typename T, typename U>
HLTPFJetsAnalyzer<T, U>::~HLTPFJetsAnalyzer()
{ 
}


// ------------ method called for each event  ------------
template<typename T, typename U>
void
HLTPFJetsAnalyzer<T, U>::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
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
    /*get inputs - jets*/
    /*******************/
    edm::Handle< TCollection > hltjets;
    int nHltJets  = -10;
    edm::Handle< UCollection > recojets;
    int nRecoJets = -10;
  
    //hlt                                       
    try {
      iEvent.getByLabel( hltjets_, hltjets);
      nHltJets = hltjets -> size();
    }
    catch (exception &e)
      {
	cout << "no hlt jet found " << hltjets_ << endl;
      }
    //reco
    try {
      iEvent.getByLabel( recojets_, recojets);
      nRecoJets = recojets -> size();
    }   
    catch (exception &e)
      {
	cout << "no reco jet found " << recojets_ << endl ;
      }

    /*******************/
    /* end inputs      */
    /*******************/
    
    //playtime
    double hltleadpt  = 0.;
    double hltleadeta = 0.;
    double hltleadphi = 0.;

    double recoleadpt  = 0.;
    double recoleadeta = 0.;
    double recoleadphi = 0.;

    // hlt & reco
    if ( nHltJets > 0 && nRecoJets > 0 ){
 
      hltleadpt  = hltjets -> begin() -> pt();
      hltleadeta = hltjets -> begin() -> eta();
      hltleadphi = hltjets -> begin() -> phi();      

      recoleadpt  = recojets -> begin() -> pt();
      recoleadeta = recojets -> begin() -> eta();
      recoleadphi = recojets -> begin() -> phi();

      double dR  = min(dR, deltaR( hltleadeta, hltleadphi, recoleadeta, recoleadphi ));       

      h_deltaPtOverPt_    -> Fill( (recoleadpt - hltleadpt) / recoleadpt );
      h_deltaPt_          -> Fill( (recoleadpt - hltleadpt)  );
      h_deltaEtaOverEta_  -> Fill( (recoleadeta - hltleadeta) / recoleadeta );
      h_deltaEta_         -> Fill( (recoleadeta - hltleadeta)  );

      //eta binned
      unsigned int binToFillRespEta = ( recoleadeta + etamax ) / binWidthEta_ ; 
      // cout << " binToFillRespEta " << binToFillRespEta << " recoleadeta " << recoleadeta << endl;
      unsigned int binToFillRespPt = abs( recoleadpt  ) / binWidthPt_ ;

      if ( binToFillRespPt > 9 ) // could be made generic !!
	binToFillRespPt = 9;

      h_deltaPtOverPtEtaBinned_[ binToFillRespEta ] -> Fill( (recoleadpt - hltleadpt) / recoleadpt );
      h_deltaPtOverPtPtBinned_[ binToFillRespPt ]   -> Fill( (recoleadpt - hltleadpt) / recoleadpt );

 
      /*******************/
      /* turn on curves  */
      /*******************/
      //eta binned
      double binWidth = 6. / etaBinning_ ;
      unsigned int binToFill = abs( recoleadeta ) / binWidth ;
      if (  abs( recoleadeta ) <  (binToFill + 1.)* binWidth ) {
     
	h_turnOnPtEtaBinnedDen_[ binToFill ] -> Fill( recoleadpt );
	if ( hltleadpt > 30. && abs( hltleadeta ) < 2.6 ){
	  h_turnOnPtEtaBinned_[ binToFill ]    -> Fill( recoleadpt );
  
	}  
      }
      // overall
      if ( abs( recoleadeta ) < 2.4) {
	h_turnOnPtDen_                          -> Fill( recoleadpt );
	if ( hltleadpt > 30. && abs( hltleadeta ) < 2.6 ){
	  h_turnOnPt_                           -> Fill( recoleadpt );
	}  
      }

      //debugging
      if ( recoleadpt > 60 &&  abs( recoleadeta ) < 2.4 && !( hltleadpt > 30. && abs( hltleadeta ) < 2.6)){
	cout << "run number " << EvtInfo_Run << " event number " << EvtInfo_Event << endl; 
	cout << recojets_ << " recoleadpt " << recoleadpt << " recoleadeta " << recoleadeta << endl;
	cout << hltjets_ << " hltleadpt " << hltleadpt << " hltleadeta " << hltleadeta << endl;
	cout << "dR " << dR << endl;
      }
    }// end ( nHltJets > 0 && nRecoJets > 0 )

    else {
      cout << "weird numbers of jets : \n hlt " << hltjets_ << " " << nHltJets << " reco " <<  recojets_ << " " << nRecoJets << endl;
    }

  }
  else 
    cout << "failed  filters " << endl;

}//end analyze


// ------------ method called once each job just before starting event loop  ------------
template<typename T, typename U>
void 
HLTPFJetsAnalyzer<T, U>::beginJob()
{

  etamax                   = 6.; 
  ptmax                    = 200.; 

  outputFile_              = new TFile( fOutputFileName_.c_str(), "RECREATE" );

  h_dR_                    = new TH1F("h_dR", "dR(lead hlt jet, reco jet)", 100, 0., 1.);

  h_hltpt_                 = new TH1F("h_hltpt", "hlt pt, GeV", 100, 0., 500.);    
  h_hlteta_                = new TH1F("h_hlteta", "hlt eta", 120, -6., 6.);    
  h_recopt_                = new TH1F("h_recopt", "reco pt, GeV", 100, 0., 500.);    
  h_recoeta_               = new TH1F("h_recoeta", "reco eta", 120, -6., 6.);    
  h_hltleadpt_             = new TH1F("h_hltleadpt", "hltlead pt, GeV", 100, 0., 500.);    
  h_hltleadeta_            = new TH1F("h_hltleadeta", "hltlead eta", 120, -6., 6.);    
  h_recoleadpt_            = new TH1F("h_recoleadpt", "recolead pt, GeV", 100, 0., 500.);    
  h_recoleadeta_           = new TH1F("h_recoleadeta", "recolead eta", 120, -6., 6.);    
  h_hltJetMultiplicity_    = new TH1D("h_hltJetMultiplicity", "number of hlt jets", 200, 0, 200); 
  h_recoJetMultiplicity_   = new TH1D("h_recoJetMultiplicity", "number of reco jets", 200, 0, 200); 
  h_deltaPtOverPt_         = new TH1F("h_deltaPtOverPt_", "response in pt", 120, -6, 6.);    
  h_deltaPt_               = new TH1F("h_deltaPt_", "responseRel in pt", 100, -1, 1.);    
  h_deltaEtaOverEta_       = new TH1F("h_deltaEtaOverEta_", "response in eta", 120, -6, 6.);   
  h_deltaEta_              = new TH1F("h_deltaEta_", "responseRel in eta", 100, -1, 1.);   

  h_turnOnPt_              = new TH1F("h_turnOnPt_", "turn on curve, full coverage in eta", 100, 0., 500.);   
  h_turnOnPtDen_           = new TH1F("h_turnOnPtDen_", "turn on curve, full coverage in eta", 100, 0., 500.);   

  for ( unsigned int i = 0 ; i < etaBinning_ ; i++){
    double binWidth = 6. / etaBinning_ ;
    TString h_name    = TString::Format("h_turnOnPtEtalt%d", i);
    TString h_nameDen = TString::Format("h_turnOnPtEtalt%dDen",  i );
  
    TH1F* h_dummy           = new TH1F(h_name, h_name, 50, 0., 500.);
    TH1F* h_dummyDen        = new TH1F(h_nameDen, h_nameDen, 50, 0., 500.);
    h_turnOnPtEtaBinned_. push_back(h_dummy);
    h_turnOnPtEtaBinnedDen_. push_back(h_dummyDen);
  }

  for ( unsigned int i = 0 ; i < 12 ; i++){
    TString h_nameRespEta    = TString::Format("h_deltaPtOverPtEtaBinned%d", i);
    TH1F* h_dummy            = new TH1F(h_nameRespEta, h_nameRespEta, 100, -5., 5.);
    h_deltaPtOverPtEtaBinned_. push_back(h_dummy);
  }

  for ( unsigned int i = 0 ; i < 10 ; i++){
    TString h_nameRespPt    = TString::Format("h_deltaPtOverPtPtBinned%d", i);
    TH1F* h_dummy            = new TH1F(h_nameRespPt, h_nameRespPt, 100, -5., 5.);
    h_deltaPtOverPtPtBinned_. push_back(h_dummy);
  }

  //   h_responseEta_           = new TH2F("h_responseEta_", "response wrt eta", 120, -6., 6., 100, -0.5, 0.5);   
  //   h_responsePt_            = new TH2F("h_responsePt_", "response wrt pt", 10, 0, 200., 120, -1., 0.2);   

  
}

// ------------ method called once each job just after ending the event loop  ------------
template<typename T, typename U>
void 
HLTPFJetsAnalyzer<T, U>::endJob() 
{

  outputFile_->cd();
  //distributions
  h_dR_                  -> Write();
  h_hltpt_               -> Write();
  h_hlteta_              -> Write();
  h_recopt_              -> Write();
  h_recoeta_             -> Write();
  h_hltleadpt_           -> Write();
  h_hltleadeta_          -> Write();
  h_recoleadpt_          -> Write();
  h_recoleadeta_         -> Write();
  h_hltJetMultiplicity_  -> Write();
  h_recoJetMultiplicity_ -> Write();

  h_deltaPtOverPt_       -> Write();
  h_deltaPt_             -> Write();
  h_deltaEtaOverEta_     -> Write();
  h_deltaEta_            -> Write();

  //turn-on curves
  h_turnOnPt_             -> Write();
  h_turnOnPtDen_          -> Write();

  for (unsigned int i = 0 ; i < etaBinning_ ; i++){
    h_turnOnPtEtaBinned_[i]    -> Write();
    h_turnOnPtEtaBinnedDen_[i] -> Write();
  }

  for ( unsigned int i = 0 ; i < 12 ; i++){
    h_deltaPtOverPtEtaBinned_[i] -> Write();
  }

  for ( unsigned int i = 0 ; i < 10 ; i++){
    h_deltaPtOverPtPtBinned_[i] -> Write();
  }


  Double_t xEta[12]   = {-5.5, -4.5, -3.5, -2.5, -1.5, 0.5, 1.5, 2.5, 3.5, 4.5, 5.5};
  Double_t yEta[12]   = {0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.};
  Double_t exEta[12]  = {0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.};
  Double_t eyEta[12]  = {0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.,0.};

  for ( unsigned int i = 0 ; i < 12 ; i++){
    yEta[i]  = h_deltaPtOverPtEtaBinned_[i] -> GetMean();
    eyEta[i] = h_deltaPtOverPtEtaBinned_[i] -> GetRMS();
  }

  Double_t xPt[10]   = {10., 30., 50., 70., 90., 110., 130., 150., 170., 190.};
  Double_t yPt[10]   = {0.,0.,0.,0.,0.,0.,0.,0.,0.,0.};
  Double_t exPt[10]  = {0.,0.,0.,0.,0.,0.,0.,0.,0.,0.};
  Double_t eyPt[10]  = {0.,0.,0.,0.,0.,0.,0.,0.,0.,0.};

  for ( unsigned int i = 0 ; i < 10 ; i++){
    yPt[i]  = h_deltaPtOverPtPtBinned_[i] -> GetMean();
    eyPt[i] = h_deltaPtOverPtPtBinned_[i] -> GetRMS();
  }

  h_responseEta_ = new TGraphErrors(12, xEta, yEta, exEta, eyEta);
  h_responseEta_ -> SetName("gr_responseEta");
  h_responsePt_  = new TGraphErrors(10, xPt, yPt, exPt, eyPt);
  h_responsePt_ -> SetName("gr_responsePt");

  h_responseEta_ -> Write();
  h_responsePt_  -> Write();

}


//define this as a plug-in
//DEFINE_FWK_MODULE(HLTPFJetsAnalyzer);
typedef HLTPFJetsAnalyzer< reco::PFJet, reco::PFJet > HLTrecoPFJetsAnalyzer;
typedef HLTPFJetsAnalyzer< reco::CaloJet, reco::PFJet > HLTcalorecoPFJetsAnalyzer;
typedef HLTPFJetsAnalyzer< reco::PFJet, cmg::PFJet > HLTcmgPFJetsAnalyzer;
typedef HLTPFJetsAnalyzer< reco::CaloJet, cmg::PFJet > HLTcalocmgPFJetsAnalyzer;

DEFINE_FWK_MODULE(HLTrecoPFJetsAnalyzer);
DEFINE_FWK_MODULE(HLTcmgPFJetsAnalyzer);
DEFINE_FWK_MODULE(HLTcalorecoPFJetsAnalyzer);
DEFINE_FWK_MODULE(HLTcalocmgPFJetsAnalyzer);

