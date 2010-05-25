#ifndef LucieAnalyzer_H
#define LucieAnalyzer_H

// -*- C++ -*-
//
//
// Original Author:  Artur Kalinowski
//         Created:  Wed Jul 22 14:16:44 CEST 2009
// $Id: LucieAnalyzer.h,v 1.4 2010/04/21 15:28:23 cbern Exp $
//
//

#include "PFAnalyses/CommonTools/interface/FWLiteAnalyzer.h"
#include "PFAnalyses/CommonTools/interface/CandidateSelector.h"
#include "PFAnalyses/CommonTools/interface/PatJetSelector.h"
#include "PFAnalyses/CommonTools/interface/PatLeptonSelector.h"
#include "PFAnalyses/CommonTools/interface/PatElectronSelector.h"

#include "DataFormats/PatCandidates/interface/Jet.h"
#include "DataFormats/PatCandidates/interface/MET.h"
#include "DataFormats/PatCandidates/interface/Muon.h"

#include "DataFormats/Common/interface/Handle.h"
#include "FWCore/Utilities/interface/InputTag.h"

class LucieHistograms;

class LucieAnalyzer:public FWLiteAnalyzer{

 public:

  ///Default contructor
  LucieAnalyzer(const std::string & aName);

  ///Default destructor
  virtual ~LucieAnalyzer();

  ///Method to initialise the object.
  ///It is called by the top level FWLiteTreeAnalyzer
  ///class.
  virtual void initialize(const edm::ParameterSet&, 
			  TFileDirectory&,
			  std::strbitset *aSelections);
  
  ///Method where the analysis is done.
  virtual bool analyze(const edm::EventBase& iEvent);

  ///Method which defined the branches to be added
  ///to the analysis TTree
  virtual void addBranch(TTree *tree);

  ///Here we define histogram to be filled after each cut.
  ///Notice: only 1D here.
  ///Notice: name of the histogram the same as the name of the TBranch registered
  ///        in the relevant Analyzer, EXCEPT "h" at the beggining
  ///Notice: PF suffix in the name is necessary
  virtual void addCutHistos(TList *aList);

  private:

  ///Method for registering the selections for this analyzer
  void registerCuts();

  ///Method reseting the values of class data members
  void clear();

  /// W specific histograms
  LucieHistograms *LucieHistos_;

  ///Name of the analyzed data sample, e.g. "ttbar"
  ///This name will be part of the output ROOT file
  std::string sampleName_;


  bool verbose_;

  //selectors

  ///InputTags for physics objects
  edm::InputTag jetLabel_;
  double ht_;
  /* tree branches */ 
 
};

#endif
