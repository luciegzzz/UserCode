#ifndef Lucie_ThirdGeneration_TopTaggingMVA_H
#define Lucie_ThirdGeneration_TopTaggingMVA_H

#include <vector>
#include "TMath.h"  
#include "TMVA/Reader.h" 


class TopTaggingMVA {
 public :

  TopTaggingMVA (const char * weightsfile) ;

  ~TopTaggingMVA () ;

  double val (
	      double pt,
	      double eta,
	      double mass,
	      double radius,
	      double sumPtOvernConst,
	      double firstBtag_btag,
	      double firstBtag_pt,
	      double firstBtag_mass,
	      double secondBtag_btag,
	      double secondBtag_pt,
	      double secondBtag_mass
	      );

 private:

  void init ( const char * weightsfile) ;

  std::vector<Float_t> taggingvars_ ;
  TMVA::Reader *reader_ ;
};

#endif
