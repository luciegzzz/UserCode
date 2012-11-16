#ifndef Lucie_ThirdGeneration_AnalysisMVA_H
#define Lucie_ThirdGeneration_AnalysisMVA_H

#include <vector>
#include "TMath.h"  
#include "TMVA/Reader.h" 


class AnalysisMVA {
 public :

  AnalysisMVA (const char * weightsfile) ;

  ~AnalysisMVA () ;

  double val (
	      int jetMultiplicity30                            ,
	      int numberOfBTags_csv_tight                      ,
	      int numberOfTopCandidates_topCandidatesCa0p71p75 ,
	      double deltaPhiMETHighPtTopCandtopCandidatesCa0p71p75 ,
	      double minDeltaPhiMETJets
	      );

 private:

  void init ( const char * weightsfile) ;

  std::vector<Float_t> anavars_ ;
  TMVA::Reader *reader_ ;
};

#endif
