// -*- C++ -*-
//
// Package:    RateAnalyzer
// Class:      RateAnalyzer
// 
/**\class RateAnalyzer RateAnalyzer.cc CMGTools/RateAnalyzer/src/RateAnalyzer.cc **/


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
#include <DataFormats/METReco/interface/CaloMET.h>
#include <DataFormats/METReco/interface/MET.h>
#include "DataFormats/Common/interface/TriggerResults.h"
//#include "DataFormats/Common/interface/TriggerNames.h"
#include "DataFormats/MuonReco/interface/Muon.h"
 #include "FWCore/Common/interface/TriggerNames.h"

#include "TH1F.h"
#include "TH2F.h"
#include "TH1D.h"
#include "TGraphErrors.h"
#include "TFile.h"
#include <string>
#include <vector>
#include <map>
//
// class declaration
//



class RateAnalyzer : public edm::EDAnalyzer {
public:
  explicit RateAnalyzer(const edm::ParameterSet&);
  ~RateAnalyzer();
  
  virtual void beginJob() ;
  virtual void analyze(const edm::Event&, const edm::EventSetup&);
  virtual void endJob() ;

  //helpers
  typedef edm::TriggerResults                TriggerResult;
  typedef std::map<std::string, int>         nameToRate;

  // ----------member data ---------------------------
  
private:
  /*inputs*/
  edm::InputTag triggerResults_    ;
  /*helpers*/
  nameToRate listOfNameToRate_     ;
  double normFactor_               ;

  /*********/
  /*outputs*/
  /*********/
  TFile* outputFile_               ;
  std::string fOutputFileName_     ;


};


