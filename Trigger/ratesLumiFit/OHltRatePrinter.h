//////////////////////////////////////////////////////////
//
// Class to print rates
//
//////////////////////////////////////////////////////////

#ifndef OHltRatePrinter_h
#define OHltRatePrinter_h

#include <vector>
#include "OHltMenu.h"
#include "OHltConfig.h"
#include "OHltTree.h"

class OHltRatePrinter {
 public:
  
	static const float fTwo=2.;
  OHltRatePrinter(){};
  virtual ~OHltRatePrinter(){};

  void SetupAll(std::vector<float> Rate,std::vector<float> RateErr,std::vector<float> spureRate,
		std::vector<float> spureRateErr,std::vector<float> pureRate,
		std::vector<float> pureRateErr,std::vector< std::vector<float> >coMa,
		std::vector< std::vector<float> > RatePerLS,std::vector<int> tRunID,std::vector<int> tLumiSection,
		std::vector<float> tTotalRatePerLS);
  void ReorderRunLS();

  void printRatesASCII(OHltConfig *cfg,OHltMenu *menu);
  void printCorrelationASCII();
  
  void printRatesTex(OHltConfig *cfg, OHltMenu *menu);
  void printHltRatesTex(OHltConfig *cfg, OHltMenu *menu);
  void printL1RatesTex(OHltConfig *cfg, OHltMenu *menu);
  void printRatesTwiki(OHltConfig *cfg, OHltMenu *menu); 
  void printHltRatesTwiki(OHltConfig *cfg, OHltMenu *menu); 
  void printL1RatesTwiki(OHltConfig *cfg, OHltMenu *menu); 
  void printHltRatesBocci(OHltConfig *cfg, OHltMenu *menu);
  void writeHistos(OHltConfig *cfg, OHltMenu *menu);
  TString GetFileName(OHltConfig *cfg, OHltMenu *menu);
  void printPrescalesCfg(OHltConfig *cfg, OHltMenu *menu);
  void printHLTDatasets(OHltConfig *cfg, OHltMenu *menu
  		, HLTDatasets &hltDatasets
  		, TString   &fullPathTableName
  		, const Int_t     significantDigits);
  int ivecMax(std::vector<int> ivec);
  int ivecMin(std::vector<int> ivec);

  std::vector<float> Rate;
  std::vector<float> RateErr;
  std::vector<float> spureRate;
  std::vector<float> spureRateErr;
  std::vector<float> pureRate;
  std::vector<float> pureRateErr;
  std::vector< std::vector<float> >coMa;

  std::vector< std::vector<float> > RatePerLS;
  std::vector<float> totalRatePerLS;
  std::vector<int> runID;
  std::vector<int> lumiSection;

};

#endif
