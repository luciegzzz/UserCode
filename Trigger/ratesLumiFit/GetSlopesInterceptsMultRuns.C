#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <map>

#ifndef __CINT__
#include <TPRegexp.h>
#include <TRegexp.h>
#include <TCanvas.h>
#include <TFile.h>
#include <TList.h>
#include <TH1.h>
#include <TObject.h>
#include <TDirectory.h>
#include <TPad.h>
#include <TVirtualPad.h>
#include <TSeqCollection.h>
#include <TROOT.h>
#include <TSystem.h>
#include <TEnv.h>
#include <TMath.h>
#include <TObjArray.h>
#include <TStyle.h>
#include <TKey.h>
#include <TH1D.h>
#include <TH2D.h>
#include <TProfile.h>
#include <TGraph.h>
#include <TGraphErrors.h>
#include <TF1.h>
#include <TMatrixDSym.h>
#endif

#include <TLegendEntry.h>
#include <TFitResult.h>
#include <TFitResultPtr.h>
#include <TString.h>

using namespace std;

void GetSlopesInterceptsMultRuns( vector<int> runNr,  vector<int> prescaleL1_124, vector<double> nB, const char* DS="Mu"){

  //--------------------READING/MAKING USE OF THE ARGUMENTS----------------------------------//
  int                   nrRuns = runNr.size();

  //get files corresponding to run numbers and dataset requested
  vector<TFile*>        runFiles;
  for (int i = 0 ; i < nrRuns ; i++){
    TString filename = TString::Format("r%d/%s.root",runNr[i],DS);
    cout<<"filename "<<filename<<endl;
    runFiles.push_back( TFile::Open(filename));
  }
  
  //////////////////////////////////////////////////////////////// 

  double Eff=0.95;
  double fBC=11245.;
    
  float                 rates[5000];
  float                 lumis[5000];
  float                 errors_rates[5000];
  float                 errors_lumis[5000];
 
  vector<TGraphErrors*> vtg_selectedPaths;//vector of graphs containing graph for selected paths. RatesPerLumi Canvas
  vector<TString>       v_selectedPaths;
 

  //here should read histo from a given file and fill corresonding rates and lumi
  TIter nextkey1(runFiles[0]->GetListOfKeys());//first run is driving the iteration

  TKey* dummy;                                 //dummy key to iterate on. 
  vector<TKey*>         key;                   //keys to objects in each run

  vector<int>           nLSref;                //get numberOfLumiSection from lumi histogram
  nLSref.push_back(0);

  while (dummy = (TKey*)nextkey1()){           //loop over paths from file 1 by default
    key.push_back(dummy);
    TString histoName(key[0]->GetName());
    v_selectedPaths.push_back(histoName); 
  
    for (int i = 1 ; i< nrRuns ; i++){
      key.push_back(runFiles[i]->GetKey(histoName));//Get keys to histograms for each run for a given path
    }

    vector<TH1D*>       htemp;                 //vector to store histo from each run for a given path
    for(int i = 0; i < nrRuns ; i++){
      htemp.push_back(dynamic_cast<TH1D*>(key[i]->ReadObj()));//Get histograms for a given path
    }   

    if (histoName.BeginsWith("h_Luminosity")){ //h_Luminosity is a special case
      for(int i = 0; i < nrRuns ; i++){
	nLSref.push_back(htemp[i]->GetNbinsX());
      }
    }
  
    //------------Getting luminosities & rates-----------//
     
    for (int iLS = 0; iLS < *max_element(nLSref.begin(),nLSref.end()) ; iLS++){
      //for(int j = 0 ; j <  nLSref.size()-1 ; j++){//might be a pb if hlumi not read "early enough"
	for(int j = 0 ; j <  nrRuns ; j++){
	
	if (histoName.BeginsWith("h_Luminosity")){
	  double rate = (htemp[j]->GetBinContent(iLS+1))*prescaleL1_124[j];
	  //lumis[iLS+nLSref[j]] = rate/7000.;
	  lumis[iLS+nLSref[j]] = -nB[j]/Eff*TMath::Log(1-rate/(nB[j]*fBC))*fBC/71.3*1/100;
	  double error_rate = htemp[j]->GetBinError(iLS+1);
	  errors_lumis[iLS+nLSref[j]]= nB[j]*fBC/(Eff*71.3*100)*error_rate/rate;
	}

	rates[iLS+nLSref[j]] = htemp[j]->GetBinContent(iLS+1);
	errors_rates[iLS+nLSref[j]]= htemp[j]->GetBinError(iLS+1);
      }
	cout <<"lumis "<<iLS <<" "<<lumis[iLS]<<" "<<lumis[iLS+16]<<endl;
    }
  
    //------------TGraphErroring-------------------------//
    int nbPts = std::accumulate( nLSref.begin(),nLSref.end(),0 );
    TGraphErrors* tg_temp = new TGraphErrors(nbPts,lumis,rates,errors_lumis,errors_rates);
    tg_temp->SetTitle(histoName);
    if (histoName.BeginsWith("h_Lumi")){
    }
    else
      vtg_selectedPaths.push_back(tg_temp);

    key.clear();
  }//end while loop on keys

  //---------------Plotting TGraphErors-------------------------------//

  TCanvas* RatesPerLumi = new TCanvas("RatesPerLumiBis","RatesPerLumiBis",0,100,1000,1000);
  RatesPerLumi->Divide(5,5);
  for (unsigned int iPath=0; iPath< vtg_selectedPaths.size(); ++iPath) {
    RatesPerLumi->cd(iPath+1);
    vtg_selectedPaths.at(iPath)->Draw("A*");
  }
  //---------------Fitting TGraphErrors-------------------------------//
  double poli1(double *x, double *par);
  TF1 *fit = new TF1("fit",poli1,0.,10.,2);
  fit->SetParNames("Intercept","Slope");
  ofstream fitsParameters;
  fitsParameters.open ("fitsParameters.dat");
  fitsParameters<<" paths intercepts  slopes errorsOnIntercepts^2  errorsOnSlopes^2 covarianceSlopesIntercepts"<<endl;
  
  for (unsigned int iPath=0; iPath<vtg_selectedPaths.size() ; ++iPath) {
    fit->SetParameters(0,1);
    // TFitResultPtr r = (vtg_selectedPaths.at(iPath))->Fit("fit","S");
    (vtg_selectedPaths.at(iPath))->Fit("fit");
    //  TMatrixDSym cov = r->GetCovarianceMatrix();  //  to access the covariance matrix
 
   //  fitsParameters<< v_selectedPaths.at(iPath).Data()<<" "
//   		  << r->Value(0)<<" "
// 		  << r->Value(1)<<" "
// 		  << cov(0,0)<<" "
//   		  << cov(1,1)<<" "
// 		  << cov(0,1)<<endl;
    // r->Print("V");
  }

  TString sDS = TString(DS);
  TString filename_eps ="RatesPerLumi136100_err"+sDS+".eps";
  RatesPerLumi->SaveAs(filename_eps);
  TString filename_png ="RatesPerLumi136100_err"+sDS+".png";
  RatesPerLumi->SaveAs(filename_png);
	
  fitsParameters.close();

}


double poli1(double *x, double *par) {
  return par[0] + par[1] * x[0];
}



