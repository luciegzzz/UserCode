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
// $Id: METsAnalyzer.h,v 1.6 2011/03/13 21:20:46 lucieg Exp $
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
#include "DataFormats/METReco/interface/METCollection.h"
#include "DataFormats/METReco/interface/MET.h"
#include "DataFormats/METReco/interface/GenMETCollection.h"
#include "DataFormats/METReco/interface/GenMET.h"
#include "DataFormats/METReco/interface/CaloMETCollection.h"
#include "DataFormats/METReco/interface/CaloMET.h"
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
  edm::InputTag       inputTagMET0_;
  edm::InputTag       inputTagMET1_;
  edm::InputTag       inputTagMET2_;
  edm::InputTag       inputTagNbVtces_;

  edm::InputTag       inputTagVertices_;

  edm::InputTag       inputTagHepMCEvent_;

  std::string              inputType_;

  //output 
  TFile               *outputFile_;
  std:: string        fOutputFileName_;

  //Nr vertices
  TH1I                *h_nRecoVertices_;
  TH1I                *h_nPUVertices_;
  TH2D                *h_nrecoVtcesVsnPUVtces_;
  //Pt distributions
  TH2D                *h_MET0PtVsNPU_;  
  TH2D                *h_MET1PtVsNPU_;
  TH2D                *h_MET2PtVsNPU_;

  //Pt x, y distributions
  TH2D                *h_MET0PtxVsNPU_;  
  TH2D                *h_MET1PtxVsNPU_;
  TH2D                *h_MET2PtxVsNPU_;

  TH2D                *h_MET0PtyVsNPU_;  
  TH2D                *h_MET1PtyVsNPU_;
  TH2D                *h_MET2PtyVsNPU_;

  //Pt x, y = f(sum Et)
 //  TH2D                *h_EtxVsSumEt0_;
//   TH2D                *h_EtyVsSumEt0_;
//   TH2D                *h_EtxVsSumEt1_;
//   TH2D                *h_EtyVsSumEt1_;
//   TH2D                *h_EtxVsSumEt2_;
//   TH2D                *h_EtyVsSumEt2_;

  std::vector< TH2D* >                h_EtxVsSumEt0_;
  std::vector< TH2D* >                h_EtyVsSumEt0_;
  std::vector< TH2D* >                h_EtxVsSumEt1_;
  std::vector< TH2D* >                h_EtyVsSumEt1_;
  std::vector< TH2D* >                h_EtxVsSumEt2_;
  std::vector< TH2D* >                h_EtyVsSumEt2_;



};

#endif
