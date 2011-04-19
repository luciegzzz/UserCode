// -*- C++ -*-
//
// Package:    JetAnalyzer
// Class:      JetAnalyzer
// 
/**\class JetAnalyzer JetAnalyzer.cc Jet/JetAnalyzer/plugins/JetAnalyzer.cc

 Description: [one line class summary]

 Implementation:
     [Notes on implementation]
*/
//
// Original Author:  "Lucie Gauthier"
//        
// $Id: JetAnalyzer.h,v 1.1 2011/04/18 18:03:01 lucieg Exp $
//
//

#ifndef JetWithPU_JetAnalyzer_Analyzer_
#define JetWithPU_JetAnalyzer_Analyzer_


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

#include "DataFormats/ParticleFlowCandidate/interface/PFCandidateFwd.h"
#include "DataFormats/ParticleFlowCandidate/interface/PFCandidate.h"
#include "DataFormats/JetReco/interface/PFJetCollection.h"
#include "DataFormats/JetReco/interface/PFJet.h"
#include "DataFormats/JetReco/interface/GenJetCollection.h"
#include "DataFormats/JetReco/interface/GenJet.h"
#include "DataFormats/VertexReco/interface/Vertex.h"
#include "DataFormats/VertexReco/interface/VertexFwd.h"
#include "SimDataFormats/GeneratorProducts/interface/HepMCProduct.h"
#include "SimDataFormats/PileupSummaryInfo/interface/PileupSummaryInfo.h" 
#include "DataFormats/Math/interface/deltaR.h"

//ROOT includes
#include "TFile.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TF1.h"

//
// class declaration
//

class JetAnalyzer : public edm::EDAnalyzer {
   public:
      explicit JetAnalyzer(const edm::ParameterSet&);
      ~JetAnalyzer();


   private:
      virtual void beginJob() ;
      virtual void analyze(const edm::Event&, const edm::EventSetup&);
      virtual void endJob() ;
  reco::VertexRef chargedHadronVertex( const edm::Handle<reco::VertexCollection>& vertices, const reco::PFCandidate& pfcand ) const;
  bool isMatched(const edm::Handle<reco::GenJetCollection>& genJets, const reco::PFJet& pfjet);

  // ----------member data ---------------------------                                                                                                                                                                                  
  edm::InputTag       inputTagJet_;
  edm::InputTag       inputTagGenJet_;
  edm::InputTag       inputTagVertices_;
 
  //output 
  TFile               *outputFile_;
  std::string         fOutputFileName_;

  //Nr vertices
  TH1D                *h_nPUVertices_;

  //jet 
  TH1D                *h_PFCFromPVOverTOT_;
  TH1D                *h_PFCFromPUOverTOT_;
  TH1D                *h_neutralJetsOverTot_; 
  TH1D                *h_jetFromPVOverGenJet_;
  TH1D                *h_nConstituents_ ;
  TH1D                *h_dR_;
  TH1D                *h_jetsFromPVMatchedOverJetsFromPV_;

  TH2D                *h_PFCFromPUOverTOTVsnConst_;

};

#endif
