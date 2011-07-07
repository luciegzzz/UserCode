// -*- C++ -*-
//
// Package:    Analyzer
// Class:      Analyzer
// 
/**\class Analyzer Analyzer.cc /Analyzer/plugins/Analyzer.cc

 Description: [one line class summary]

 Implementation:
     [Notes on implementation]
*/
//
// Original Author:  "Lucie Gauthier"
//        
// $Id: Analyzer.h,v 1.8 2011/04/21 12:15:14 lucieg Exp $
//
//

#ifndef AnalyzerForTests_Analyzer_Analyzer_
#define AnalyzerForTests_Analyzer_Analyzer_


// system include files
#include <memory>
#include <string>
#include <vector>

// user include files
//CMSSW includes
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/Framework/interface/ESHandle.h"

#include "FWCore/Utilities/interface/Exception.h"
#include "FWCore/Framework/interface/EventSetup.h"

#include "DataFormats/Common/interface/Handle.h"

#include <DataFormats/PatCandidates/interface/Electron.h>
#include "DataFormats/Math/interface/deltaR.h"
#include "DataFormats/Common/interface/ValueMap.h"
#include "AnalysisDataFormats/CMGTools/interface/Electron.h"

//ROOT includes
#include "TFile.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TF1.h"
#include "TTree.h"

//
// class declaration
//

class Analyzer : public edm::EDAnalyzer {
   public:
      explicit Analyzer(const edm::ParameterSet&);
      ~Analyzer();


   private:
      virtual void beginJob() ;
      virtual void analyze(const edm::Event&, const edm::EventSetup&);
      virtual void endJob() ;


  // ----------member data ---------------------------                                                                                                                                                                                  
  edm::InputTag       inputTagElectrons_;
  edm::InputTag       inputTagCmgElectrons_;
 
  //output 
  TFile               *outputFile_;
  std::string         fOutputFileName_;


  // tree & its variables
  TTree* eleTree_;
  double deltaR_;
  double ptReco_;
  double ptGen_;
  double etaReco_;
  double etaGen_;
  
 

};

#endif

