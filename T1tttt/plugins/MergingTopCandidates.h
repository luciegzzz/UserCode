#ifndef Lucie_T1tttt_MergingTopCandidates_h
#define Lucie_T1tttt_MergingTopCandidates_h

// -*- C++ -*-
/** \class MergingTopCandidates
 *  Producer meant to add (part of) the MET back to the jet collection, via collinear approximation, projecting the MET along the leading lepton axis
 * Lucie Gauthier - 31-07-2012
 **/

//stl
#include <memory>
#include <iostream>
#include <vector>

//Framework
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDProducer.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/MessageLogger/interface/MessageLogger.h"

//Objects
#include "DataFormats/Common/interface/ValueMap.h"
#include "DataFormats/JetReco/interface/BasicJet.h"

//Math
#include "DataFormats/Math/interface/deltaR.h" 


/////
//class declaration
/////


class MergingTopCandidates : public edm::EDProducer {

 public :

  //helpers
  typedef std::vector< reco::BasicJet >    BasicJetCollection     ;

  //methods
  explicit MergingTopCandidates( const edm::ParameterSet& );

  ~MergingTopCandidates() ;

  virtual void produce(edm::Event&, const edm::EventSetup&);
  
  virtual void beginRun(edm::Run& run,const edm::EventSetup & es);


 private : 

  //Inputs
  edm::InputTag  inputTagJets0_    ;
  edm::InputTag  inputTagJets1_    ;

};

#endif
