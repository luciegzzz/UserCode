// -*- C++ -*-
//
// Package:    HLTPFJetsAnalyzer
// Class:      HLTPFJetsAnalyzer
// 
/**\class HLTPFJetsAnalyzer HLTPFJetsAnalyzer.cc CMGTools/HLTPFJetsAnalyzer/src/HLTPFJetsAnalyzer.cc **/


// system include files
#include <memory>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include "DataFormats/Math/interface/deltaR.h"
#include <DataFormats/JetReco/interface/PFJet.h>
#include <DataFormats/JetReco/interface/CaloJet.h>
#include "AnalysisDataFormats/CMGTools/interface/PFJet.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TH1D.h"
#include "TGraphErrors.h"
#include "TFile.h"
#include <string>
#include <vector>
//
// class declaration
//

template <typename T, typename U>

class HLTPFJetsAnalyzer : public edm::EDAnalyzer {
public:
  explicit HLTPFJetsAnalyzer(const edm::ParameterSet&);
  ~HLTPFJetsAnalyzer();
  
  virtual void beginJob() ;
  virtual void analyze(const edm::Event&, const edm::EventSetup&);
  virtual void endJob() ;

  //helpers
  typedef std::vector< reco::PFJet > HLTJetCollection;
  typedef std::vector< T > TCollection;
  typedef std::vector< U > UCollection;
 
  // ----------member data ---------------------------
  
private:
  /*inputs*/
  edm::InputTag hltjets_         ;
  edm::InputTag recojets_        ;
  double dRMatched_              ;
  unsigned etaBinning_           ;
  double binWidthEta_            ;
  double binWidthPt_             ;

  /*helpers*/
  double etamax                  ;
  double ptmax                   ;

  /*********/
  /*outputs*/
  /*********/
  TFile* outputFile_             ;
  std::string fOutputFileName_   ;

  /*online - offline comparison*/
  // for jet matching
  TH1F* h_dR_                    ; 
  //distributions
  TH1F* h_hltpt_                 ; 
  TH1F* h_hlteta_                ; 
  TH1F* h_hltleadpt_             ; 
  TH1F* h_hltleadeta_            ; 
  TH1F* h_recopt_                ; 
  TH1F* h_recoeta_               ; 
  TH1F* h_recoleadpt_            ; 
  TH1F* h_recoleadeta_           ; 
  TH1D* h_hltJetMultiplicity_    ;
  TH1D* h_recoJetMultiplicity_   ;

  //response plots
  TH1F* h_deltaPtOverPt_         ;
  TH1F* h_deltaPt_               ;
  TH1F* h_deltaEtaOverEta_       ;
  TH1F* h_deltaEta_              ;

  std::vector< TH1F* > h_deltaPtOverPtEtaBinned_ ;
  std::vector< TH1F* > h_deltaPtOverPtPtBinned_  ;
    
  TGraphErrors *h_responseEta_           ;
  TGraphErrors *h_responsePt_            ;

  /* turn-on curves*/
  //overall
  TH1F* h_turnOnPt_               ;
  TH1F* h_turnOnPtDen_            ;


  //pt dependant constant binning or detector-wise ?
  std::vector< TH1F* >  h_turnOnPtEtaBinned_ ;
  std::vector< TH1F* >  h_turnOnPtEtaBinnedDen_ ;



};


