
#ifndef myTemplateHistograms_h
#define myTemplateHistograms_h

// Base class for histogram managing.
//
// Original Author:  Artur Kalinowski
//         Created:  Wed Jul 22 12:56:54 CEST 2009
// $Id: myTemplateHistograms.h,v 1.1 2010/04/20 10:32:40 cbern Exp $
//
//
#include "PFAnalyses/CommonTools/interface/AnalysisHistograms.h"

class myTemplateHistograms: public AnalysisHistograms {
 public:

  myTemplateHistograms(TFileDirectory *myTemplateDir, const std::string & name="");

  virtual ~myTemplateHistograms();

  void fillHistograms(float et);

 private:

  virtual void defineHistograms();


};

#endif
