#include <iostream>

#include "PFAnalyses/LucieAnalysis/interface/LucieHistograms.h"

/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
LucieHistograms::LucieHistograms(TFileDirectory *myDir, const std::string & name){

  AnalysisHistograms::init(myDir,name);

}

/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
LucieHistograms::~LucieHistograms(){ 

  std::cout<<"LucieHistograms::~LucieHistograms()"<<std::endl;

}
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
void LucieHistograms::defineHistograms(){

  using namespace std;

 if(!histosInitialized_){

   ///Here we define 1D histogram. The histograms are assigned to the TDirectory 
   /// pointed by the file argument 
   add1DHistogram("HtJets","; HtJets;Events",100,0,10000,file_);

   histosInitialized_ = true;
 }
}
