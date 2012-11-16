#ifndef Lucie_ThirdGeneration_TopJetFactory_h
#define Lucie_ThirdGeneration_TopJetFactory_h

// -*- C++ -*-
/** \class TopJetFactory
 *  Producer meant to add (part of) the MET back to the jet collection, via collinear approximation, projecting the MET along the leading lepton axis
 * Lucie Gauthier - 31-07-2012
 **/

//stl
#include <memory>
#include <iostream>
#include <vector>
#include <string>

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
#include "DataFormats/JetReco/interface/TopJet.h"
#include "DataFormats/Candidate/interface/CandidateFwd.h"

//Math
#include "DataFormats/Math/interface/deltaR.h" 

//CMGTools
#include "AnalysisDataFormats/CMGTools/interface/PFJet.h"

//Me
#include "Lucie/ThirdGeneration/interface/TopTaggingMVA.h"

//ROOT
#include "TFile.h"
#include "TPRegexp.h"
#include "TString.h"

/////
//class declaration
/////


class TopJetFactory : public edm::EDProducer {

 public :

  //helpers
  typedef std::vector< reco::BasicJet >  BasicJetCollection   ;
  typedef std::vector< reco::TopJet >    TopJetCollection     ;
  typedef std::vector< cmg::PFJet >      PFJetCollection      ;
  typedef math::XYZPoint Point;
  //methods
  explicit TopJetFactory( const edm::ParameterSet& );

  ~TopJetFactory() ;

  virtual void produce(edm::Event&, const edm::EventSetup&);
  
  virtual void beginRun(edm::Run& run,const edm::EventSetup & es);

  double ComputeMVA( const BasicJetCollection::const_iterator );

 private : 

  //Inputs
  edm::InputTag  inputTagJets_     ;
  std::string    weightsfile_      ;

  TopTaggingMVA  mva_              ;
};

#endif
