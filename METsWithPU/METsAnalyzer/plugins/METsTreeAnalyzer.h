// -*- C++ -*-
//
// Package:    METsWithPU
// Class:      METsTreeAnalyzer
// 
/**\class METsTreeAnalyzer METsTreeAnalyzer.cc METsWithPU/METsAnalyzer/plugins/METsTreeAnalyzer.cc

 Description: [one line class summary]

 Implementation:
     [Notes on implementation]
*/
//
// Original Author:  "Lucie Gauthier"
//        
// $Id: METsTreeAnalyzer.h,v 1.1 2011/04/27 16:57:34 lucieg Exp $
//
//

#ifndef METsWithPU_METsAnalyzer_Analyzer_
#define METsWithPU_METsAnalyzer_Analyzer_


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

class METsTreeAnalyzer : public edm::EDAnalyzer {
   public:
      explicit METsTreeAnalyzer(const edm::ParameterSet&);
      ~METsTreeAnalyzer();


   private:
      virtual void beginJob() ;
      virtual void analyze(const edm::Event&, const edm::EventSetup&);
      virtual void endJob() ;

  // ----------member data ---------------------------                                                                                                                                                                                  
  edm::InputTag       inputTagVertices_;
  edm::InputTag       inputTagStdPFMET_;
  edm::InputTag       inputTagPFMET_;
  edm::InputTag       inputTagPFMETRebalanced_;
  edm::InputTag       inputTagPFMETDiscarded_;
  edm::InputTag       inputTagPFJets_;
  edm::InputTag       inputTagPileUpPFJets_;
  edm::InputTag       inputTagPFCandidates_;
  edm::InputTag       inputTagPileUpPFCandidates_;
  edm::InputTag       inputTagNoPileUpPFCandidates_;
 
  //output 
  TFile               *outputFile_;
  std::string         fOutputFileName_;



  //met tree
  TTree* METTree_;
  int    nPUVertices_;
  double stdPFMET_;
  double stdPFMETx_;
  double stdPFMETy_;
  double stdPFMETPhi_;
  double stdSumEt_;
  double met_;
  double metPhi_;
  double metx_;
  double mety_;
  double sumEt_;
  double metDiscarded_;
  double metDiscardedPhi_;
  double metDiscardedx_;
  double metDiscardedy_;
  double sumEtDiscarded_;
  double metRebalanced_;
  double metRebalancedx_;
  double metRebalancedy_;
  double metRebalancedPhi_;
  double sumEtRebalanced_;
  double dPhi_;


  //jets tree 
  TTree* ObjectTree_;
  double jetsPt_;
  double jetsEta_;
  double jetsPhi_;
  double pileUpJetsPt_;
  double pileUpJetsEta_;
  double pileUpJetsPhi_;

  //pfCands tree
  double pfCandsPt_;
  double pfCandsEta_;
  double pfCandsPhi_;
  double pileUpPfCandsPt_;
  double pileUpPfCandsEta_;
  double pileUpPfCandsPhi_;
  double noPileUpPfCandsPt_;
  double noPileUpPfCandsEta_;
  double noPileUpPfCandsPhi_;


};

#endif
