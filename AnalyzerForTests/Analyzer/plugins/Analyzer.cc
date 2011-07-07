
// -*- C++ -*-
//
// Package:    Analyzer
// Class:      Analyzer
// 
/**\class Analyzer Analyzer.cc /Analyzer/src/Analyzer.cc

Description: [one line class summary]

Implementation:
[Notes on implementation]
*/
//
// Original Author:  "Lucie Gauthier"
//         Created:  Fri Ap 14  2011
// $Id: Analyzer.cc,v 1.13 2011/04/21 20:17:58 lucieg Exp $
//
//

// user include files
#include "AnalyzerForTests/Analyzer/plugins/Analyzer.h"

using namespace std;
using namespace edm;
using namespace pat;

//
// constructors and destructor
//
Analyzer::Analyzer(const edm::ParameterSet& iConfig)

{
 
  inputTagElectrons_ 
    = iConfig.getParameter<InputTag>("patElectrons");

  inputTagCmgElectrons_ 
    = iConfig.getParameter<InputTag>("cmgElectrons");

 
  fOutputFileName_ = iConfig.getUntrackedParameter<string>("HistOutFile");

}


Analyzer::~Analyzer()
{

}


//
// member functions
//
// ------------ pSetup called once each job just before starting event loop  ------------
void 
Analyzer::beginJob()
{
  //Create output file                                                                                                                                                     
  outputFile_ = new TFile( fOutputFileName_.c_str(), "RECREATE" );

}

// ------------ method called to for each event  ------------
void
Analyzer::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
  
  /*****Tree variables initialization******/
 
   //get some pat electrons
  Handle<pat::ElectronCollection> eleColl;
  iEvent.getByLabel(inputTagElectrons_, eleColl);

 
  ElectronCollection::const_iterator ele = eleColl -> begin();
  int eleIndex               = 0;
   
  for(; ele != eleColl -> end(); ele++, eleIndex++){
  //   std::cout << "----------------pat ele--------------"<<endl;
//     std::cout << "Electron ID: 95relIso=" << ele->electronID("simpleEleId95relIso")  
// 	      << " 90relIso=" << ele->electronID("simpleEleId90relIso") 
// 	      << " 85relIso=" << ele->electronID("simpleEleId85relIso") 
// 	      << " 80relIso=" << ele->electronID("simpleEleId80relIso") 
// 	      << " 70relIso=" << ele->electronID("simpleEleId70relIso") 
// 	      << " 60relIso=" << ele->electronID("simpleEleId60relIso") << endl 
// 	      << " eidVeryLoose=" << ele->electronID("eidVeryLoose")
// 	      << " eidLoose="     << ele->electronID("eidLoose")
// 	      << " eidMedium="    << ele->electronID("eidMedium")
// 	      << " eidTight="     << ele->electronID("eidTight")
// 	      << " eidSuperTight="<< ele->electronID("eidSuperTight")
// 	      << std::endl;
    
    //  std::cout << "eidLoose =" << eIDmap[&electrons[i]]<<endl;  
    
  }// end loop 

  //get some cmg ele
  Handle<std::vector< cmg::Electron > > cmgEleColl;
  iEvent.getByLabel(inputTagCmgElectrons_, cmgEleColl);
//   Handle::<View<cmg::Electron> > cmgEles;
//   iEvent.getByLabel(inputTagCmgElectrons_, cmgEles);
   
  std::vector< cmg::Electron >::const_iterator cmgEle = cmgEleColl -> begin();
  
   
  for(; cmgEle != cmgEleColl -> end(); cmgEle++){


// //   //  for(unsigned int cmgEle = 0; cmgEle < cmgEleColl ->size() ; cmgEle++){
//   //  for(view::const_iterator it = cmgEleColl->begin(); it != cmgEleColl->end(); ++it) {
    std::cout << "----------------cmg ele--------------"<<endl;
    std::cout << "Electron ID: 95relIso=" << (*cmgEle -> sourcePtr())-> electronID("simpleEleId95relIso")

//  	      << " 90relIso=" << (*cmgEle -> sourcePtr())->electronID("simpleEleId90relIso") 
//  	      << " 90relIso=" << (*cmgEle -> sourcePtr())->electronID("simpleEleId90relIso") 
// 	      << " 85relIso=" << (*cmgEle -> sourcePtr())->electronID("simpleEleId85relIso") 
// 	      << " 80relIso=" << (*cmgEle -> sourcePtr())->electronID("simpleEleId80relIso") 
// 	      << " 70relIso=" << (*cmgEle -> sourcePtr())->electronID("simpleEleId70relIso") 
// 	      << " 60relIso=" << (*cmgEle -> sourcePtr())->electronID("simpleEleId60relIso") << endl 
// 	      << " eidVeryLoose=" << (*cmgEle -> sourcePtr())->electronID("eidVeryLoose")
// 	      << " eidLoose="     << (*cmgEle -> sourcePtr())->electronID("eidLoose")
// 	      << " eidMedium="    << (*cmgEle -> sourcePtr())->electronID("eidMedium")
// 	      << " eidTight="     << (*cmgEle -> sourcePtr())->electronID("eidTight")
// 	      << " eidSuperTight="<< (*cmgEle -> sourcePtr())->electronID("eidSuperTight")
	      << std::endl;

    std::cout << (*cmgEle -> sourcePtr())-> electronID("simpleEleId95relIso") << " " 
	      << cmgEle -> getSelection("cuts_wp95relIso")<<endl;
    
    
   }// end loop 


}




// ------------ method called once each job just after ending the event loop  ------------
void 
Analyzer::endJob() {

  outputFile_ -> cd();
  outputFile_ -> Write();

}

//Write this as a plug-in
DEFINE_FWK_MODULE(Analyzer);

