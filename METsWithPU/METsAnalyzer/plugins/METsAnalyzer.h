// -*- C++ -*-
//
// Package:    METsAnalyzer
// Class:      METsAnalyzer
// 
/**\class METsAnalyzer METsAnalyzer.cc METs/METsAnalyzer/plugins/METsAnalyzer.cc

 Description: [one line class summary]

 Implementation:
     [Notes on implementation]
*/
//
// Original Author:  "Lucie Gauthier"
//         Created:  Fri Feb 11 03:43:43 CST 2011
// $Id: METsAnalyzer.h,v 1.10 2011/03/16 13:07:13 lucieg Exp $
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
#include "DataFormats/Common/interface/Handle.h"

#include "DataFormats/METReco/interface/PFMETCollection.h"
#include "DataFormats/METReco/interface/PFMET.h"
#include "DataFormats/VertexReco/interface/Vertex.h"
#include "DataFormats/VertexReco/interface/VertexFwd.h" //to get access to VertexCollection
#include "SimDataFormats/GeneratorProducts/interface/HepMCProduct.h"
#include "SimDataFormats/PileupSummaryInfo/interface/PileupSummaryInfo.h" 

//ROOT includes
#include "TFile.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TF1.h"

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
  edm::InputTag       inputTagMET_;
  edm::InputTag       inputTagNbVtces_;

  edm::InputTag       inputTagVertices_;
  edm::InputTag       inputTagGoodVertices_;

  std::string         inputType_;//get whether it's MC official or FastSim

  //output 
  TFile               *outputFile_;
  std:: string        fOutputFileName_;

  //Nr vertices
  TH1I                *h_nRecoVertices_;
  TH1I                *h_nGoodRecoVertices_;
  TH1I                *h_nPUVertices_;
  TH2D                *h_nRecoVtcesVsnPUVtces_;
  TH2D                *h_nGoodRecoVtcesVsnPUVtces_;
  //Pt distributions
  TH2D                *h_METPtVsNPU_;  

  //Pt x, y distributions
  TH2D                *h_METPtxVsNPU_;  
  TH2D                *h_METPtxVsNPV_;  
  TH2D                *h_METPtxVsNGPV_;  
  TH2D                *h_METPtyVsNPU_;  

  std::vector< TH2D* > h_EtxVsSumEtPUV_;
  std::vector< TH2D* > h_EtxVsSumEtPV_;
  std::vector< TH2D* > h_EtxVsSumEtGPV_;

  //  std::vector< TH2D* > h_EtyVsSumEtPUV_;



};

#endif
