{
  TFile f("PFAnalysis_Test.root");

  TCanvas c2;
  TH1F* InvMassJets = (TH1F*)f.Get("LucieAnalyzer/SubDir/InMassJets");
  InvMassJets.Draw();

  TCanvas cIso("cStats", "Stats", 800, 800);
  cStats.Divide(1,2);
  f.cd("Statistics");
  cStats.cd(1);
  hStats.Draw();
  cStats.cd(2);
  hStats.Draw();
 
}
