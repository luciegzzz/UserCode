import os, sys
from ROOT import gROOT, TFile,  TLegend, gStyle, TCanvas
import ROOT
from CMGTools.RootTools.Style import *

gROOT.Macro( os.path.expanduser( '~/rootlogon.C' ) )
gStyle.SetOptStat(0)

file = TFile('analyzerReco.root')
#file = TFile('analyzerCMG.root')
file.ls()

#lead pt
c_leadpt = TCanvas("c_leadpt")
hltleadpt  = file.Get('h_hltleadpt')
recoleadpt = file.Get('h_recoleadpt')
sBlue.formatHisto( hltleadpt )
sRed.formatHisto( recoleadpt )
hltleadpt.Draw()
recoleadpt.Draw("SAMES")

legpt = TLegend(0.7,0.7,0.9,0.9)
legpt.SetHeader("leading jet pt")
legpt.AddEntry(hltleadpt, "hlt")
legpt.AddEntry(recoleadpt, "reco")
legpt.Draw("SAMES")

#lead eta
c_leadeta = TCanvas("c_leadeta")
hltleadeta  = file.Get('h_hltleadeta')
recoleadeta = file.Get('h_recoleadeta')
sBlue.formatHisto( hltleadeta )
sRed.formatHisto( recoleadeta )
recoleadeta.Draw()
hltleadeta.Draw("SAMES")

legeta = TLegend(0.7,0.7,0.9,0.9)
legeta.SetHeader("leading jet eta")
legeta.AddEntry(hltleadeta, "hlt")
legeta.AddEntry(recoleadeta, "reco")
legeta.Draw("SAME")

#turn on overall
c_turnon = TCanvas("c_turnon")
numPt = ROOT.TH1F(file.Get('h_turnOnPt_'))
denPt = ROOT.TH1F(file.Get('h_turnOnPtDen_'))
numPt.Sumw2()
numPt.Divide(denPt)
numPt.SetMinimum(0.)
numPt.SetMaximum(1.)
numPt.Draw()

leg = TLegend(0.7,0.7,0.9,0.9)
leg.SetHeader("turn on")
leg.AddEntry(numPt, "hlt pf jet > 30 GeV, |eta| < 2.6")
leg.Draw()

#turn-on eta binned
c_turnons = TCanvas("c_turnons")
numPt0 = ROOT.TH1F(file.Get('h_turnOnPtEtalt0'))
denPt0 = ROOT.TH1F(file.Get('h_turnOnPtEtalt0Den'))
numPt0.Sumw2()
numPt0.Divide(denPt0)
numPt0.SetMinimum(0.1)
numPt0.SetMaximum(1.)
sBlue.formatHisto( numPt0 )
numPt0.Draw()

numPt1 = ROOT.TH1F(file.Get('h_turnOnPtEtalt1'))
denPt1 = ROOT.TH1F(file.Get('h_turnOnPtEtalt1Den'))
numPt1.Sumw2()
numPt1.Divide(denPt1)
numPt1.SetMinimum(0.1)
numPt1.SetMaximum(1.)
sRed.formatHisto( numPt1 )
numPt1.Draw("SAMES")


numPt2 = ROOT.TH1F(file.Get('h_turnOnPtEtalt2'))
denPt2 = ROOT.TH1F(file.Get('h_turnOnPtEtalt2Den'))
numPt2.Sumw2()
numPt2.Divide(denPt2)
numPt2.SetMinimum(0.1)
numPt2.SetMaximum(1.)
sCyan = Style(fillColor=7, markerColor = 7)
sCyan.formatHisto( numPt2 )
numPt2.Draw("SAMES")

numPt3 = ROOT.TH1F(file.Get('h_turnOnPtEtalt3'))
denPt3 = ROOT.TH1F(file.Get('h_turnOnPtEtalt3Den'))
numPt3.Sumw2()
numPt3.Divide(denPt3)
numPt3.SetMinimum(0.1)
numPt3.SetMaximum(1.)
sGreen = Style(fillColor=3, markerColor = 3)
sGreen.formatHisto( numPt3 )
numPt3.Draw("SAMES")

numPt4 = ROOT.TH1F(file.Get('h_turnOnPtEtalt4'))
denPt4 = ROOT.TH1F(file.Get('h_turnOnPtEtalt4Den'))
numPt4.Sumw2()
numPt4.Divide(denPt4)
numPt4.SetMinimum(0.1)
numPt4.SetMaximum(1.)
sBlack = Style(fillColor=1)
sBlack.formatHisto( numPt4 )
numPt4.Draw("SAMES")


legturnons = TLegend(0.7,0.7,0.9,0.9)
legturnons.SetHeader("turn on for hlt pf jet > 30 GeV, |eta| < 2.6")
legturnons.AddEntry(numPt0, "recojet |eta| < 0.5")
legturnons.AddEntry(numPt1, "recojet |eta| < 1.")
legturnons.AddEntry(numPt2, "recojet |eta| < 1.5")
legturnons.AddEntry(numPt3, "recojet |eta| < 2.")
legturnons.AddEntry(numPt4, "recojet |eta| < 2.5")
legturnons.Draw("SAMES")
