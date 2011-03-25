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
// $Id: METsAnalyzer.h,v 1.11 2011/03/24 17:07:19 lucieg Exp $
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
  edm::InputTag       inputTagRAWMET_;
 
  edm::InputTag       inputTagVertices_;
  edm::InputTag       inputTagGoodVertices_;
  edm::InputTag       inputTagVerticesDA_;
  edm::InputTag       inputTagGoodVerticesDA_;

  std::string         inputType_;//get whether it's MC official or FastSim

  //output 
  TFile               *outputFile_;
  std:: string        fOutputFileName_;

  //Nr vertices
  TH1D                *h_nPUVertices_;
  TH1D                *h_nRecoVertices_;
  TH1D                *h_nGoodRecoVertices_;
  TH1D                *h_nRecoVerticesDA_;
  TH1D                *h_nGoodRecoVerticesDA_;

  TH2D                *h_nRecoVtcesVsnPUVtces_;
  TH2D                *h_nGoodRecoVtcesVsnPUVtces_;
  TH2D                *h_nRecoVtcesDAVsnPUVtces_;
  TH2D                *h_nGoodRecoVtcesDAVsnPUVtces_;

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
