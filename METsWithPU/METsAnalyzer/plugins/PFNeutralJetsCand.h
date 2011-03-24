#ifndef METsWithPU_METsAnalyzer_PFNeutralJetsCand
#define METsWithPU_METsAnalyzer_PFNeutralJetsCand

// system include files
#include <memory>
#include <string>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDProducer.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/Framework/interface/ESHandle.h"
#include "FWCore/MessageLogger/interface/MessageLogger.h"
#include "FWCore/Utilities/interface/Exception.h"
#include "FWCore/Framework/interface/EventSetup.h"

#include "DataFormats/ParticleFlowCandidate/interface/PFCandidate.h"
#include "DataFormats/ParticleFlowCandidate/interface/PFCandidateFwd.h"
#include "DataFormats/JetReco/interface/PFJet.h"



/**\class PFNeutralJetsCand
\brief Identifies pf candidates included in jets whose EMF = 1 and
produces the corresponding collection of JetEMFPFCandidates.

*/




class PFNeutralJetsCand : public edm::EDProducer {
 public:

  explicit PFNeutralJetsCand(const edm::ParameterSet&);

  ~PFNeutralJetsCand();
  
  virtual void produce(edm::Event&, const edm::EventSetup&);

  virtual void beginJob();

 private:
  
  //reco::VertexRef 
  // chargedHadronVertex(const edm::Handle<reco::VertexCollection>& vertices, 
  //		const reco::PFCandidate& pfcand ) const;

  
  ///Jets whose PFCandidates have to be analyzed
  edm::InputTag   inputTagPFJets_;
  
  /// enable PFNeutralJetsCand selection ?
  bool   enable_;



};

#endif
