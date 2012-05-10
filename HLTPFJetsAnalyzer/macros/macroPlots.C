{
  TFile *f = new TFile("analyzer.root");


 

  TH1F* h_deneta = h_turnOnEtaDen ->Clone();
  TCanvas *c_turnOnEta = new TCanvas("c_turnOnEta") ;
  h_turnOnEta -> Sumw2();
  h_turnOnEta -> Divide(h_deneta);
  h_turnOnEta -> Draw();



}
