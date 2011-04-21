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
// $Id: JetAnalyzer.h,v 1.7 2011/04/20 19:07:10 lucieg Exp $
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
#include "DataFormats/METReco/interface/PFMET.h"
#include "DataFormats/METReco/interface/PFMETCollection.h"
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
#include "TTree.h"

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
  edm::InputTag       inputTagVertices_;
  edm::InputTag       inputTagJet_;
  edm::InputTag       inputTagGenJet_;
  edm::InputTag       inputTagPFMET_;
  edm::InputTag       inputTagPFCand_;
 
  //output 
  TFile               *outputFile_;
  std::string         fOutputFileName_;


  // tree variables
  // event
   //double neutralJets_;

  // jet tree
  TTree* JetsTree_;
  double nPFCFromPV_;
  double nPFCFromPU_;
  double nPFCNotAssociated_;
  double nNeutralConstituents_;
  double nChargedConstituents_;
  double nConstituents_;
  double nMuons_; 
  double nElectrons_;
  double sumPtFromPV_;
  double sumPtFromPU_;
  double sumPtNotAssociated_;
  double ptRecoJet_;
  double etaRecoJet_;
  double phiRecoJet_;
  int    chargedMultiplicity_;
  double ptGenJet_;
  double etaGenJet_;
  double phiGenJet_;
  double dR_;
  bool   isMatched_;
  double nGenJets_;
  int     nPUVerticesForJets_;
 
  //met tree
  TTree* METTree_;
  int    nPUVertices_;
  double stdPFMET_;
  double stdPFMETx_;
  double stdPFMETy_;
  double stdSumEt_;
  double met_;
  double metx_;
  double mety_;
  double sumEt_;
  double mpt_;
 

};

#endif
