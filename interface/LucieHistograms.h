
#ifndef LucieHistograms_h
#define LucieHistograms_h

// Base class for histogram managing.
//
// Original Author:  Artur Kalinowski
//         Created:  Wed Jul 22 12:56:54 CEST 2009
// $Id: LucieHistograms.h,v 1.1 2010/04/20 10:32:40 cbern Exp $
//
//
#include "PFAnalyses/CommonTools/interface/AnalysisHistograms.h"

class LucieHistograms: public AnalysisHistograms {
 public:

  LucieHistograms(TFileDirectory *myDir, const std::string & name="");

  virtual ~LucieHistograms();

  void fillHistograms(float et);

 private:

  virtual void defineHistograms();


};

#endif
