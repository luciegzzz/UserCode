#include "PFAnalyses/CommonTools/interface/FWLiteTreeAnalyzer.h"
#include "PFAnalyses/LucieAnalysis/interface/LucieAnalyzer.h"
#include "PFAnalyses/LucieAnalysis/interface/LucieHistograms.h"

#include "DataFormats/Math/interface/LorentzVector.h"

#include "FWCore/Utilities/interface/Algorithms.h"
#include "FWCore/Utilities/interface/InputTag.h"

#include "FWCore/ParameterSet/interface/ProcessDesc.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include "FWCore/PythonParameterSet/interface/PythonProcessDesc.h"

#include <iostream>
#include <map>

using namespace std;
using namespace reco;

LucieAnalyzer:: LucieAnalyzer(const std::string & aName):FWLiteAnalyzer(aName){}

LucieAnalyzer::~LucieAnalyzer(){

  std::cout<<"LucieAnalyzer::~LucieAnalyzer()"<<std::endl;

  delete LucieHistos_;
}


void LucieAnalyzer::initialize(const edm::ParameterSet& ps, 
			       TFileDirectory& aDir,
			       std::strbitset *aSelections) {

  verbose_ = ps.getParameter<bool>("verbose"); 
  jetLabel_ = ps.getParameter<edm::InputTag>("jetLabel");
  ht_=0.;
  
  ///The histograms for this analyzer will be saved into "TestHistos"
  ///directory of the ROOT file. One can have many sets of the
  ///histograms, each saved into a separate subdirectory, ie.
  ///TestHistos/Type1 and TestHistos/Type2
  LucieHistos_ = new LucieHistograms(&aDir,"SubDir");
}

void LucieAnalyzer::registerCuts(){
}

void  LucieAnalyzer::addBranch(TTree *tree){
}

void  LucieAnalyzer::addCutHistos(TList *aList){
}

bool LucieAnalyzer::analyze(const edm::EventBase& iEvent){

  if(verbose_) std::cout<<iEvent.id()<<std::endl;

  using namespace reco;

  edm::Handle<pat::JetCollection> pfJets;

  iEvent.getByLabel(jetLabel_, pfJets);

  typedef pat::JetCollection::const_iterator JI;

  for(JI ji = pfJets->begin(); ji!=pfJets->end(); ++ji)  {    
    ht_+= ji->pt();
  }

 LucieHistos_->AnalysisHistograms::fill1DHistogram("HtJets",ht_, 1);

  return true;
}


 
