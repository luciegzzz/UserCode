

//
// Original Author:  "Lucie Gauthier"
//         Created:  Fri Feb 11 03:43:43 CST 2011
// $Id: PFPileUpJets.h,v 1.1 2011/04/21 13:43:35 lucieg Exp $
//
//

#ifndef METsWithPU_METsAnalyzer_PFPileUpJets_
#define METsWithPU_METsAnalyzer_PFPileUpJets_


// system include files
#include <memory>
#include <string>
#include <vector>

// user include files
//CMSSW includes
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDProducer.h"
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
#include "DataFormats/Math/interface/deltaR.h"



//
// class declaration
//

class PFPileUpJets : public edm::EDProducer {
   public:
      explicit PFPileUpJets(const edm::ParameterSet&);
      ~PFPileUpJets();


   private:
      virtual void beginJob() ;
      virtual void produce(edm::Event&, const edm::EventSetup&);
     
  reco::VertexRef chargedHadronVertex( const edm::Handle<reco::VertexCollection>& vertices, const reco::PFCandidate& pfcand ) const;
  bool isMatched(const edm::Handle<reco::GenJetCollection>& genJets, const reco::PFJet& pfjet);

  // ----------member data ---------------------------                                                                                                                                                                                  
  edm::InputTag       inputTagJets_;
  edm::InputTag       inputTagVertices_;
  edm::InputTag       inputTagGenJet_;
 
};

#endif
