

//
// Original Author:  "Lucie Gauthier"
//         Created:  Fri Feb 11 03:43:43 CST 2011
// $Id: JetAnalyzer.h,v 1.14 2011/04/18 13:54:00 lucieg Exp $
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
#include "DataFormats/VertexReco/interface/Vertex.h"
#include "DataFormats/VertexReco/interface/VertexFwd.h"



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


  // ----------member data ---------------------------                                                                                                                                                                                  
  edm::InputTag       inputTagJets_;
  edm::InputTag       inputTagVertices_;
 
};

#endif
