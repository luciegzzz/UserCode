//
// Original Author:  "Lucie Gauthier"
//         Created:  Tue 2011/05/16
// 


#ifndef METsWithPU_METsAnalyzer_PFCandSplitByVtx_
#define METsWithPU_METsAnalyzer_PFCandSplitByVtx_


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
#include "DataFormats/Math/interface/deltaR.h"



//
// class declaration
//

class PFCandSplitByVtx : public edm::EDProducer {
   public:
      explicit PFCandSplitByVtx(const edm::ParameterSet&);
      ~PFCandSplitByVtx();


   private:
      virtual void beginJob() ;
      virtual void produce(edm::Event&, const edm::EventSetup&);
     
  reco::VertexRef chargedVertex( const edm::Handle<reco::VertexCollection>& vertices, const reco::PFCandidate& pfcand ) const;

  // ----------member data ---------------------------                                                                                                                                                                                  
  edm::InputTag       inputTagPFCandidates_;
  edm::InputTag       inputTagVertices_;
 
  bool verbose_;
  std::string outputFileName_;
  unsigned int vtxIndex_;

};

#endif
