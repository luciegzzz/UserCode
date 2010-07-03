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
#endif

#include <TLegendEntry.h>

using namespace std;

void GetSlopesInterceptsMultRuns( vector<int> runNr,  vector<int> lumisScale, const char* DS="Mu"){

  //--------------------READING/MAKING USE OF THE ARGUMENTS----------------------------------//
  int                   nrRuns = runNr.size();

  //get files corresponding to run numbers and dataset requested
  vector<TFile*>        runFiles;
  for (int i = 0 ; i < nrRuns ; i++){
    TString filename = TString::Format("r%d_root_files/%s.root",runNr[i],DS);
    cout<<"filename "<<filename<<endl;
    runFiles.push_back( TFile::Open(filename));
  }
  
  ////to correct bit 124 prescale HAS TO BE GIVEN AS AN ARGUMENT TOO !!!
//   vector<int>           lumisScale;
//   lumisScale.push_back(2);
//   lumisScale.push_back(1);
  //////////////////////////////////////////////////////////////// 

  double Eff=0.95;
  double fBC=11245.;
  double nB=8.;
    
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

  vector<int>           nLSref;
  nLSref.push_back(0);

  while (dummy = (TKey*)nextkey1()){           //loop over paths from file 1 by default
    key.push_back(dummy);
    TString histoName(key[0]->GetName());
    v_selectedPaths.push_back(histoName); 
  
    for (int i = 1 ; i< nrRuns ; i++){
      key.push_back(runFiles[i]->GetKey(histoName));
    }

    vector<TH1D*>       htemp;                 //vector to store histo from each path
    for(int i = 0; i < nrRuns ; i++){
      htemp.push_back(dynamic_cast<TH1D*>(key[i]->ReadObj()));
    }   

    if (histoName.BeginsWith("h_Luminosity")){ //h_Luminosity is a special case
      for(int i = 0; i < nrRuns ; i++){
	nLSref.push_back(htemp[i]->GetNbinsX());
      }
    }
  
    //------------Getting luminosities & rates-----------//
     
    for (int iLS = 0; iLS < *max_element(nLSref.begin(),nLSref.end()) ; iLS++){
      for(int j = 0 ; j <  nLSref.size()-1 ; j++){
	
	if (histoName.BeginsWith("h_Luminosity")){
	  double rate = (htemp[j]->GetBinContent(iLS+1))*lumisScale[j];
	  lumis[iLS+nLSref[j]] = rate/7000.;
	  lumis[iLS+nLSref[j]] = -nB/Eff*TMath::Log(1-rate/(nB*fBC))*fBC/71.3*1/100;//*1E27;
	  // double error_rate = htemp[j]->GetBinError(iLS+1);
	  errors_lumis[iLS+nLSref[j]]= 0.;//(htemp[j]->GetBinError(iLS+1))*lumisScale[j];//error_rate;//error_rate * 1/Eff*1/(1-Rate/fBC)*1/71.3*1E27;
	}

	rates[iLS+nLSref[j]] = htemp[j]->GetBinContent(iLS+1);
	errors_rates[iLS+nLSref[j]]= 0.;//htemp[j]->GetBinError(iLS+1);
      }
           cout <<"lumis "<<iLS <<" "<<lumis[iLS]<<" "<<errors_lumis[iLS]<<endl;
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
 //   TCanvas* GLumi =  new TCanvas("GLumi","GLumi",0,100,700,700);
//    vtg_selectedPaths.at(0)->Draw("A*");

  TCanvas* RatesPerLumi = new TCanvas("RatesPerLumiBis","RatesPerLumiBis",0,100,1000,1000);
  RatesPerLumi->Divide(5,5);
  for (unsigned int iPath=0; iPath< vtg_selectedPaths.size(); ++iPath) {
    RatesPerLumi->cd(iPath+1);
    vtg_selectedPaths.at(iPath)->Draw("A*");
  }
  //---------------Fitting TGraphErrors-------------------------------//
  double poli1(double *x, double *par);
  double Pars[200][2];       //[paths] [params]
  double errPars[200][2];
  //  double cov[200];           //[paths]
  TF1 *fit = new TF1("fit",poli1,0.,10.,2);
  fit->SetParNames("Intercept","Slope");
  for (unsigned int iPath=0; iPath<vtg_selectedPaths.size() ; ++iPath) {
    fit->SetParameters(0,1);
    vtg_selectedPaths.at(iPath)->Fit("fit");
    fit->GetParameters(Pars[iPath]);
    errPars[iPath][0] =  fit->GetParError(0);
    errPars[iPath][1] =  fit->GetParError(1);
    //   cov[iPath]        =  fit->GetCovariance();
  }

  RatesPerLumi->SaveAs("RatesPerLumi136100_err.eps");
  RatesPerLumi->SaveAs("RatesPerLumi136100_err.png");
 
  //--------------Cosmetizing print out of fitting parameters-----//
  ofstream fitsParameters;
  fitsParameters.open ("fitsParameters.dat");
  fitsParameters<<" paths intercepts errorsOnIntercepts slopes errorsOnSlopes covariance"<<endl;
  for (unsigned int iPath=1; iPath < v_selectedPaths.size(); ++iPath) {

    fitsParameters<< v_selectedPaths.at(iPath).Data()<<" "
  		  << Pars[iPath][0]<<" "
  		  << errPars[iPath][0]<<" "
  		  << Pars[iPath][1]<<" "
  		  << errPars[iPath][1]<<" "
      //  << cov[iPath]
  		  << endl;
  }
  
  fitsParameters.close();

}


double poli1(double *x, double *par) {
  return par[0] + par[1] * x[0];
}



