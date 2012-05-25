// -*- C++ -*-
//
// Package:    TurnOnAnalyzer
// Class:      TurnOnAnalyzer
// 
/**\class TurnOnAnalyzer TurnOnAnalyzer.cc CMGTools/TurnOnAnalyzer/src/TurnOnAnalyzer.cc **/


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
#include "AnalysisDataFormats/CMGTools/interface/BaseMET.h"
#include "AnalysisDataFormats/CMGTools/interface/TriggerObject.h"
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



class TurnOnAnalyzer : public edm::EDAnalyzer {
public:
  explicit TurnOnAnalyzer(const edm::ParameterSet&);
  ~TurnOnAnalyzer();
  
  virtual void beginJob() ;
  virtual void analyze(const edm::Event&, const edm::EventSetup&);
  virtual void endJob() ;

  //helpers
  typedef std::vector< cmg::TriggerObject > TriggerObjectCollection;
  typedef std::vector< cmg::PFJet >         JetCollection;
  typedef std::vector< cmg::BaseMET >       METCollection;
 
  // ----------member data ---------------------------
  
private:
  /*inputs*/
  edm::InputTag triggerResults_  ;
  edm::InputTag jets_            ;
  edm::InputTag met_             ;

  /*helpers*/
  double ptPlateau               ;
  double metPlateau              ;

  /*********/
  /*outputs*/
  /*********/
  TFile* outputFile_             ;
  std::string fOutputFileName_   ;

  TH1F* h_numMET_                ;
  TH1F* h_denMET_                ;
  TH1F* h_ratioMET_              ;

  TH1F* h_numDiJet_              ;
  TH1F* h_denDiJet_              ;
  TH1F* h_ratioDiJet_            ;


};


