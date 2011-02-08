///////////Header file for this analyzer -- usually kept in interface////////////////
#include "../interface/PhotonPlots.h"

using namespace std;
using namespace edm;
using namespace reco;

//struct to sort photons by pt
struct less_mag : public binary_function<Photon, Photon, bool> {
  bool operator()(Photon x, Photon y) { return x.pt() > y.pt() ; }
};


PhotonPlots::PhotonPlots(const edm::ParameterSet& iConfig)

{
  //Output Filename
  fOutputFileName = iConfig.getUntrackedParameter<string>("HistOutFile");
}


PhotonPlots::~PhotonPlots()
{
 
   // do anything here that needs to be done at desctruction time
   // (e.g. close files, deallocate resources etc.)

}

// ------------ method called once each job just before starting event loop  ------------                                                                     

void
PhotonPlots::beginJob()
{
  //Create output file                                                                                                                                     
  hOutputFile = new TFile( fOutputFileName.c_str(), "RECREATE" );

  //histograms definition                                                                                                                                    
  h_photonInvMass                 = new TH1F("h_photonInvMass","DiPhoton Inv Mass(GeV)",150,0,1500);
  h_photonInvMassPtCut            = new TH1F("h_photonInvMassPtCut","DiPhoton Inv Mass(GeV), Pt>20GeV",150,0,1500);
  h_photonInvMassPtIsoCut         = new TH1F("h_photonInvMassPtIsoCut","DiPhoton Inv Mass(GeV), Pt>20GeV, Iso",150,0,1500);
  h_photonInvMassPtIsodRCut       = new TH1F("h_photonInvMassPtIsodRCut","DiPhoton Inv Mass(GeV), Pt>20GeV, Iso, dR>0.4",150,0,1500);
  h_photonInvMassWithPixelCut     = new TH1F("h_photonInvMassWithPixelCut","DiPhoton Inv Mass(GeV),Pt>20GeV, Iso,  Pixel cut",100,0,500);
  h_photonInvMassWithPixelSeed    = new TH1F("h_photonInvMassWithPixelSeed","Di`Ele` Inv Mass(GeV),Pt>20GeV, Iso,  with Pixel seed",100,0,500);
  h_photonInvMassWithPixelSeedAll = new TH1F("h_photonInvMassWithPixelSeedAll","Di`Ele` Inv Mass(GeV),Pt>20GeV, Iso,  with Pixel seed",100,0,500);
  h_photon0Pt                     = new TH1F("h_photon0Pt","Photon Pt(GeV)",100,0,1000);
  h_photon1Pt                     = new TH1F("h_photon1Pt","Photon Pt(GeV)",100,0,1000);
  h_photon2Pt                     = new TH1F("h_photon2Pt","Photon Pt(GeV)",100,0,1000);
  h_sumPt3Photons                 = new TH1F(" h_sumPt3Photons","vector sum 3 Photon Pt(GeV)",300,0,3000);
  h_sumPt2Photons1Fo              = new TH1F("h_sumPt2Photons1Fo","vector sum 2Photon Pt + 1 FO(GeV)",300,0,3000);

}

// ------------ method called to for each event  ------------
void
PhotonPlots::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
  
  //get run/event info for event display
  int EvtInfo_Run   = iEvent.id().run();
  int EvtInfo_Event = iEvent.id().event();

  //get photon collection
  Handle<PhotonCollection>photonColl;
  iEvent.getByLabel("photons","",photonColl);
  PhotonCollection pho = *(photonColl.product());

  if (pho.size()>=3) {//check that at least 3 photons -> to run on MC. Shouldn't do anything (except loss of time) for skims

  //sort the photon collection in ascending pt
  sort(pho.begin(), pho.end(), less_mag());
 
  PhotonCollection::const_iterator phoItmax = ++(++(++(pho.begin())));//to read only the 1st 3 photons. Inelegant.

  //Loop over photon collection : photon 0
  for (PhotonCollection::const_iterator phoIt0 = pho.begin(); phoIt0 != phoItmax ; phoIt0++){
    //variables for the vector sumPt
    double sumPx = 0.;
    double sumPy = 0.;
    double sumPt = 0.;

    //Loop over photon collection : photon 1 
    for (PhotonCollection::const_iterator phoIt1 = phoIt0; phoIt1 != phoItmax  ; phoIt1++){
      if (phoIt0 == phoIt1) continue;//discard photon0 == photon1
      
      //inv mass
      double px01 = phoIt0->px() + phoIt1->px();
      double py01 = phoIt0->py() + phoIt1->py();
      double pz01 = phoIt0->pz() + phoIt1->pz();
      double E01  = phoIt0->energy() + phoIt1->energy(); 

      sumPx+=px01;
      sumPy+=py01;
 
      double mass2 = E01*E01 - (px01*px01 +  py01*py01 +  pz01*pz01 );
      double mass = sqrt(mass2);

      h_photonInvMass->Fill(mass);//just in case, invariant mass before any cut
     
      //pt cut on photons 0 and 1- matters for MC/unskimmed input
      double pt0 = phoIt0->pt();
      double pt1 = phoIt1->pt();
      if (pt0 < 20.) continue;
      if (pt1 < 20.) continue;
 
      //Iso & cut photons 0 and 1- matters for MC/unskimmed input
      Float_t PhotonTrkIso0    = phoIt0->trkSumPtHollowConeDR04();//needed in any case
      Float_t PhotonEcalIso0   = phoIt0->ecalRecHitSumEtConeDR04();
      Float_t PhotonHcalIso0   = phoIt0->hcalTowerSumEtConeDR04();
      Float_t PhotonHadOverEM0 = phoIt0->hadronicOverEm();
      Float_t PhotonEtaWidth0  = phoIt0->sigmaIetaIeta();
     
      Float_t PhotonTrkIso1    = phoIt1->trkSumPtHollowConeDR04();//needed in any case
      Float_t PhotonEcalIso1   = phoIt1->ecalRecHitSumEtConeDR04();
      Float_t PhotonHcalIso1   = phoIt1->hcalTowerSumEtConeDR04();
      Float_t PhotonHadOverEM1 = phoIt1->hadronicOverEm();
      Float_t PhotonEtaWidth1  = phoIt1->sigmaIetaIeta();
  
      bool EcalIso0            = PhotonEcalIso0 < (4.2 + 0.006*pt0) ;
      bool HcalIso0            = PhotonHcalIso0 < (2.2 + 0.0025*pt0) ;
      bool HadOverEMIso0       = PhotonHadOverEM0 < 0.05 ;
      bool TrkIso0             = PhotonTrkIso0 < (3.5 + 0.001*pt0);
      bool EtaWidth0           = PhotonEtaWidth0 < 0.013;

      bool EcalIso1            = PhotonEcalIso1 < (4.2 + 0.006*pt1) ;
      bool HcalIso1            = PhotonHcalIso1 < (2.2 + 0.0025*pt1) ;
      bool HadOverEMIso1       = PhotonHadOverEM1 < 0.05 ;
      bool TrkIso1             = PhotonTrkIso1 < (3.5 + 0.001*pt1);
      bool EtaWidth1           = PhotonEtaWidth1 < 0.013;

      bool TrkIso2             = false;
      bool PhoLike2            = false;//for hasPixelSeed cut

      //check for 3rd photon Iso + get whether it's photon like or gamma like
      for (PhotonCollection::const_iterator phoIt2 = pho.begin() ; phoIt2 != phoItmax; phoIt2++){
	if ((phoIt2 == phoIt0)||(phoIt2 == phoIt1)) continue;//make sure we don't have twice the same photon
	
	double pt2 = phoIt2->pt();
	if (pt2<20) continue; //pt cut on the 3rd photon
	
	double px2 = phoIt2->px();
	double py2 = phoIt2->py();
	sumPx+=px2;
	sumPy+=py2;

	h_photonInvMassPtCut ->Fill(mass);//all diPhotons mass with only pt cut. Should have #photons * 3 entries

	if (phoIt0 == pho.begin() && phoIt1 == (pho.begin()+1)) {//fill pt histo only once - should have #photons entries
	  sumPt+=sqrt(sumPx*sumPx+sumPy*sumPy);
	  h_photon0Pt->Fill(pt0);
	  h_photon1Pt->Fill(pt1);
	  h_photon2Pt->Fill(pt2);
	}

	Float_t PhotonTrkIso2    = phoIt2->trkSumPtHollowConeDR04();
	TrkIso2 = PhotonTrkIso2 < (3.5 + 0.001*pt2);
        PhoLike2 = !(phoIt2->hasPixelSeed());
	if (TrkIso2){
	  continue;
	}
      }//end loop over 3rd photon

      //Iso cut
      bool Iso = TrkIso0 && TrkIso1 && TrkIso2; //for skims 
      //bool Iso = EcalIso0 && HcalIso0 && HadOverEMIso0 && TrkIso0  && EcalIso1 && HcalIso1 && HadOverEMIso1 && TrkIso1 && EcalIso2 && HcalIso2 && HadOverEMIso2 && TrkIso2;//for MC : should add full iso cut

      //sumPt loose-loose-bad
      if(TrkIso0 && TrkIso1 && !TrkIso2){
	if (phoIt0 == pho.begin() && phoIt1 == (pho.begin()+1)){
	  h_sumPt2Photons1Fo->Fill(sumPt);
	}
      }

      if (!Iso) continue;
      h_photonInvMassPtIsoCut ->Fill(mass);  

      // deltaR & cut
      // double dR = deltaR(phoIt0->eta(),phoIt0->phi(),phoIt1->eta(),phoIt1->phi());
      // if (dR < 0.4) continue;	
      // h_photonInvMassPtIsodRCut -> Fill(mass);
 
      //pixel seed cut : get whether photon 0/1 are ele-like or gamma-like     
      bool PhoLike0 = !(phoIt0->hasPixelSeed());    
      bool PhoLike1 = !(phoIt1->hasPixelSeed());
     
      if (PhoLike0 && PhoLike1 && PhoLike2) {
	h_photonInvMassWithPixelCut->Fill(mass);
	if (phoIt0 == pho.begin() && phoIt1 == (pho.begin()+1)) h_sumPt3Photons->Fill(sumPt);//should have #photons entries
	cout<< "PhoLike, mass :  "<<mass<< " run nr "<< EvtInfo_Run <<" event nr "<<EvtInfo_Event <<endl;//should add an if statement to get high mass candidates only
      }

      if (!PhoLike0 && !PhoLike1) {//2ele for invariant mass <->Z
	h_photonInvMassWithPixelSeed->Fill(mass);
	cout<< "EleLike, mass :  "<<mass<< " run nr "<< EvtInfo_Run <<" event nr "<<EvtInfo_Event <<endl;
      }

    }

  }

  }

}//end of analyzer

// ------------ method called once each job just after ending the event loop  ------------
void 
PhotonPlots::endJob() {
  //write histograms to output file
  hOutputFile->cd();
  h_photonInvMass->Write();
  h_photonInvMassWithPixelCut->Write();
  h_photonInvMassWithPixelSeed->Write();
  h_photonInvMassWithPixelSeedAll->Write();
  h_photonInvMassPtCut ->Write();
  h_photonInvMassPtIsoCut->Write();
  h_photonInvMassPtIsodRCut ->Write();
  h_photon0Pt->Write();
  h_photon1Pt->Write();
  h_photon2Pt->Write();
  h_sumPt3Photons->Write();
  h_sumPt2Photons1Fo->Write();


  hOutputFile->Close();

}


//define this as a plug-in
DEFINE_FWK_MODULE(PhotonPlots);
