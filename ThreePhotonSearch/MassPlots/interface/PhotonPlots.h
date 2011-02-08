// system include files
#include <memory>
#include <string>
#include <vector>
#include <iostream>
#include <cmath>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/Utilities/interface/Exception.h"
#include "FWCore/Framework/interface/ESHandle.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "Geometry/CaloGeometry/interface/CaloCellGeometry.h"
#include "Geometry/CaloGeometry/interface/CaloGeometry.h"
#include "Geometry/Records/interface/CaloGeometryRecord.h"
#include "DataFormats/GeometryVector/interface/GlobalPoint.h"
#include "DataFormats/DetId/interface/DetId.h"
#include "DataFormats/HcalRecHit/interface/HcalRecHitCollections.h"
#include "DataFormats/EgammaReco/interface/SuperCluster.h"
#include "DataFormats/EgammaReco/interface/SuperClusterFwd.h"
#include "DataFormats/Candidate/interface/Particle.h"
#include "DataFormats/Common/interface/Ref.h"
#include "DataFormats/CaloTowers/interface/CaloTowerCollection.h"
#include "DataFormats/HcalRecHit/interface/HBHERecHit.h"
#include "DataFormats/HcalDigi/interface/HBHEDataFrame.h"
#include "DataFormats/EcalRecHit/interface/EcalRecHit.h"
#include "DataFormats/EcalRecHit/interface/EcalRecHitCollections.h"
#include "DataFormats/CaloRecHit/interface/CaloRecHit.h"
#include "DataFormats/CaloRecHit/interface/CaloCluster.h"
#include "DataFormats/CaloRecHit/interface/CaloClusterFwd.h"
#include "DataFormats/EgammaCandidates/interface/Photon.h"
#include "DataFormats/EgammaCandidates/interface/PhotonFwd.h"
#include "DataFormats/EcalDetId/interface/EBDetId.h"
#include "DataFormats/Math/interface/deltaR.h"

#include "TMath.h"
#include "TFile.h"
#include "TH1F.h"
#include "TH2F.h"

using namespace std;

//class declaration
class PhotonPlots : public edm::EDAnalyzer {
 public:
  explicit PhotonPlots(const edm::ParameterSet&);
  ~PhotonPlots();


 private:
  virtual void beginJob() ;
  virtual void analyze(const edm::Event&, const edm::EventSetup&);
  virtual void endJob() ;

  // ----------member data ---------------------------                                                                                                                                                                                  

  TFile   *hOutputFile;
  string   fOutputFileName;

  TH1F    *h_photonInvMass;
  TH1F    *h_photonInvMassWithPixelCut;
  TH1F    *h_photonInvMassWithPixelSeed;
  TH1F    *h_photonInvMassWithPixelSeedAll;
  TH1F    *h_photonInvMassPtCut ;
  TH1F    *h_photonInvMassPtIsoCut;
  TH1F    *h_photonInvMassPtIsodRCut ;
  TH1F    *h_photon0Pt;
  TH1F    *h_photon1Pt;
  TH1F    *h_photon2Pt;
  TH1F    *h_sumPt3Photons;
  TH1F    *h_sumPt2Photons1Fo;
 

};
