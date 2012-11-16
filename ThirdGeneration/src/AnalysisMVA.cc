#include "Lucie/ThirdGeneration/interface/AnalysisMVA.h"

AnalysisMVA::AnalysisMVA(const char * weightsfile):anavars_(5,0.)
{
  init (weightsfile);
}


void AnalysisMVA::init(const char * weightsfile)
{
  reader_  = new TMVA::Reader( "!Color:!Silent" ) ;

  reader_ -> AddVariable("jetMultiplicity_30"                             , &anavars_[0] );
  reader_ -> AddVariable("numberOfBTags_csv_tight"                        , &anavars_[1] );
  reader_ -> AddVariable("numberOfTopCandidates_topCandidatesCa0p71p75"   , &anavars_[2] );
  reader_ -> AddVariable("deltaPhiMETHighPtTopCandtopCandidatesCa0p71p75" , &anavars_[3] );
  reader_ -> AddVariable("minDeltaPhiMETJets"                             , &anavars_[4] );
 
  std::cout << "Analysis MVA: using " << weightsfile << " weight file\n" ;
    reader_->BookMVA("BDT", weightsfile); 
}

AnalysisMVA::~AnalysisMVA() { delete reader_ ;}


double AnalysisMVA::val(
			int jetMultiplicity_30                            ,
			int numberOfBTags_csv_tight                      ,
			int numberOfTopCandidates_topCandidatesCa0p71p75 ,
			double deltaPhiMETHighPtTopCandtopCandidatesCa0p71p75 ,
			double minDeltaPhiMETJets
			)
{
  anavars_[0]  = jetMultiplicity_30                              ;
  anavars_[1]  = numberOfBTags_csv_tight                         ;
  anavars_[2]  = numberOfTopCandidates_topCandidatesCa0p71p75    ;
  anavars_[3]  = deltaPhiMETHighPtTopCandtopCandidatesCa0p71p75  ;
  anavars_[4]  = minDeltaPhiMETJets                              ;
 
  return reader_ -> EvaluateMVA(anavars_,"BDT");
}
