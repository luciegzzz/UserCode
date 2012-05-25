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

  //hlt
  if (nHltJets > 0) {
      
    hltleadpt  = hltjets -> begin() -> pt();
    hltleadeta = hltjets -> begin() -> eta();
    hltleadphi = hltjets -> begin() -> phi();
      
    h_hltleadpt_  -> Fill( hltleadpt );
    h_hltleadeta_ -> Fill( hltleadeta );  
  
    for ( typename TCollection::const_iterator itHltJet = hltjets -> begin() ; itHltJet != hltjets -> end() ; itHltJet++ ){
      h_hltpt_  -> Fill( itHltJet -> pt() );
      h_hlteta_ -> Fill( itHltJet -> eta() );
    }
    h_hltJetMultiplicity_ -> Fill( nHltJets );
  }

  //reco
  if (nRecoJets > 0) {
 
    recoleadpt  = recojets -> begin() -> pt();
    recoleadeta = recojets -> begin() -> eta();
    recoleadphi = recojets -> begin() -> phi();
    
    h_recoleadpt_  -> Fill( recoleadpt );
    h_recoleadeta_ -> Fill( recoleadeta );  

    for ( typename UCollection::const_iterator itRecoJet = recojets -> begin() ; itRecoJet != recojets -> end() ; itRecoJet++ ){
      h_recopt_  -> Fill( itRecoJet -> pt() );
      h_recoeta_ -> Fill( itRecoJet -> eta() );
    }
    h_recoJetMultiplicity_ -> Fill( nRecoJets );
  }

  // hlt & reco
  if ( nHltJets > 0 && nRecoJets > 0 ){
 
    //matching
    double dR = 1000.;
    double ptMatched = 10000.;
    double etaMatched = 100.;
    for ( typename UCollection::const_iterator itRecoJet = recojets -> begin() ; itRecoJet != recojets -> end() ; itRecoJet++ ){
      double tmpDr = dR;
      dR = min(dR, deltaR( hltleadeta, hltleadphi,itRecoJet -> eta(), itRecoJet -> phi() ));
      if ( dR < tmpDr ){
	ptMatched  = itRecoJet -> pt();
	etaMatched = itRecoJet -> eta();
      }
    }

    h_dR_ -> Fill(dR);
    if ( dR < dRMatched_ ){
      h_deltaPtOverPt_    -> Fill( (ptMatched - hltleadpt) / ptMatched );
      h_deltaPt_          -> Fill( (ptMatched - hltleadpt)  );
      h_deltaEtaOverEta_  -> Fill( (etaMatched - hltleadeta) / etaMatched );
      h_deltaEta_         -> Fill( (etaMatched - hltleadeta)  );

      //eta binned
      unsigned int binToFillRespEta = ( etaMatched + etamax ) / binWidthEta_ ; 
      unsigned int binToFillRespPt = abs( ptMatched  ) / binWidthPt_ ;

      if ( binToFillRespPt > 9 ) // could be made generic !!
	binToFillRespPt = 9;

      h_deltaPtOverPtEtaBinned_[ binToFillRespEta ] -> Fill( (ptMatched - hltleadpt) / ptMatched );
      h_deltaPtOverPtPtBinned_[ binToFillRespPt ]   -> Fill( (ptMatched - hltleadpt) / ptMatched );
    


    }
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
    if ( recoleadpt > 80 &&  abs( recoleadeta ) < 2.4 && !( hltleadpt > 30. && abs( hltleadeta ) < 2.6)){
      cout << "run number " << EvtInfo_Run << " event number " << EvtInfo_Event << endl; 
      cout << recojets_ << " recoleadpt " << recoleadpt << " recoleadeta " << recoleadeta << endl;
      cout << hltjets_ << " hltleadpt " << hltleadpt << " hltleadeta " << hltleadeta << endl;
      cout << "dR " << dR << endl;
    }
  }// end ( nHltJets > 0 && nRecoJets > 0 )

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

  h_responseEta_           = new TH2F("h_responseEta_", "response wrt eta", 120, -6., 6., 100, -0.5, 0.5);   
  h_responsePt_            = new TH2F("h_responsePt_", "response wrt pt", 10, 0, 200., 120, -1., 0.2);   

  
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

  for ( unsigned int i = 0 ; i < 10 ; i++){
    h_deltaPtOverPtEtaBinned_[i] -> Write();
  }

  for ( unsigned int i = 0 ; i < 10 ; i++){
    h_deltaPtOverPtPtBinned_[i] -> Write();
  }


  for ( unsigned int i = 0 ; i < 12 ; i++){
    double meanEtaResp = h_deltaPtOverPtEtaBinned_[i] -> GetMean();
    h_responseEta_ -> Fill( -6. + i, meanEtaResp) ;
    double meanPtResp = h_deltaPtOverPtEtaBinned_[i] -> GetMean();
    h_responsePt_ -> Fill( 20*i, meanPtResp) ;
  }

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

