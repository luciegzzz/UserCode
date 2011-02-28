// -*- C++ -*-
//
// Package:    METsAnalyzer
// Class:      METsAnalyzer
// 
/**\class METsAnalyzer METsAnalyzer.cc METs/METsAnalyzer/src/METsAnalyzer.cc

 Description: [one line class summary]

 Implementation:
     [Notes on implementation]
*/
//
// Original Author:  "Lucie Gauthier"
//         Created:  Fri Feb 11 03:43:43 CST 2011
// $Id: METsAnalyzer.h,v 1.1 2011/02/28 16:14:40 lucieg Exp $
//
//

#ifndef METsWithPU_METsAnalyzer_Analyzer_
#define METsWithPU_METsAnalyzer_Analyzer_


// system include files
#include <memory>
#include <string>

// user include files
//CMSSW includes
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include "DataFormats/METReco/interface/PFMETCollection.h"
#include "DataFormats/METReco/interface/PFMET.h"
#include "DataFormats/METReco/interface/METCollection.h"
#include "DataFormats/METReco/interface/MET.h"
#include "DataFormats/METReco/interface/GenMETCollection.h"
#include "DataFormats/METReco/interface/GenMET.h"
#include "DataFormats/METReco/interface/CaloMETCollection.h"
#include "DataFormats/METReco/interface/CaloMET.h"

//ROOT includes
#include "TFile.h"
#include "TH1F.h"

//
// class declaration
//

class METsAnalyzer : public edm::EDAnalyzer {
   public:
      explicit METsAnalyzer(const edm::ParameterSet&);
      ~METsAnalyzer();


   private:
      virtual void beginJob() ;
      virtual void analyze(const edm::Event&, const edm::EventSetup&);
      virtual void endJob() ;
  // ----------member data ---------------------------                                                                                                                                                                                  
  //  edm::InputTag       inputTagPFCandidates_;
  edm::InputTag       inputTagCaloMET_;
  edm::InputTag       inputTagPFMET_;
  edm::InputTag       inputTagTcMET_;
  edm::InputTag       inputTagGenMET_;

  TFile   *hOutputFile;
  std:: string   fOutputFileName;

  TH1F    *h_CaloMETPt;  
  TH1F    *h_pfMETPt;
  TH1F    *h_tcMETPt;
};

#endif
