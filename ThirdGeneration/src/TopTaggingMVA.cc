#include "Lucie/ThirdGeneration/interface/TopTaggingMVA.h"

TopTaggingMVA::TopTaggingMVA(const char * weightsfile):taggingvars_(11,0.)
{
  init (weightsfile);
}


void TopTaggingMVA::init(const char * weightsfile)
{
  reader_  = new TMVA::Reader( "!Color:!Silent" ) ;

  reader_ -> AddVariable("pt"               , &taggingvars_[0] );
  reader_ -> AddVariable("eta"              , &taggingvars_[1] );
  reader_ -> AddVariable("mass"             , &taggingvars_[2] );
  reader_ -> AddVariable("radius"           , &taggingvars_[3] );
  reader_ -> AddVariable("sumPtOvernConst"  , &taggingvars_[4] );
  reader_ -> AddVariable("firstBtag_btag"   , &taggingvars_[5] );
  reader_ -> AddVariable("firstBtag_pt"     , &taggingvars_[6] );
  reader_ -> AddVariable("firstBtag_mass"   , &taggingvars_[7] );
  reader_ -> AddVariable("secondBtag_btag"  , &taggingvars_[8] );
  reader_ -> AddVariable("secondBtag_pt"    , &taggingvars_[9] );
  reader_ -> AddVariable("secondBtag_mass"  , &taggingvars_[10] );

  std::cout << "Top Tagging MVA: using " << weightsfile << " weight file\n" ;
  //  reader_->BookMVA("BDTG", weightsfile); 
  reader_->BookMVA("BDT", weightsfile); 
}

TopTaggingMVA::~TopTaggingMVA() { delete reader_ ;}


double TopTaggingMVA::val(
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
			  )
{
  taggingvars_[0]  = pt                  ;
  taggingvars_[1]  = eta                 ;
  taggingvars_[2]  = mass                ;
  taggingvars_[3]  = radius              ;
  taggingvars_[4]  = sumPtOvernConst     ;
  taggingvars_[5]  = firstBtag_btag      ;
  taggingvars_[6]  = firstBtag_pt        ;
  taggingvars_[7]  = firstBtag_mass      ;
  taggingvars_[8]  = secondBtag_btag     ;
  taggingvars_[9]  = secondBtag_pt       ;
  taggingvars_[10] = secondBtag_mass     ;

  return reader_ -> EvaluateMVA(taggingvars_,"BDT");
}
