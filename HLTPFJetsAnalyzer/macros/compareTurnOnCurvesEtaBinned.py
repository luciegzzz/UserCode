import os, sys
from ROOT import gROOT, TFile,  TLegend, gStyle, TCanvas
import ROOT
from CMGTools.RootTools.Style import *

gROOT.Macro( os.path.expanduser( '~/rootlogon.C' ) )
gStyle.SetOptStat(0)

dir = '/data/lucieg/HltPfJetsAnalyzerNoMatchingHLTMay10/'

##fileHLTToReco          = TFile(dir+'analyzerHLTReco.root')
#fileHLTToReco          = TFile(dir+'analyzerHLTCMG.root')
## fileHLTToReco          = TFile(dir+'analyzerHLTCMGCHS.root')

## fileHLTToReco          = TFile(dir+'analyzerL1L2L3Reco.root')
## fileHLTToReco          = TFile(dir+'analyzerL1L2L3CMG.root')
##fileHLTToReco          = TFile(dir+'analyzerHLTPFNoPUL1L2L3CMGCHS.root')

## ext = 'ak5PFJetsToCMGCHS'
## fileHLTToReco          = TFile(dir+'analyzerHLTCMGCHS.root')
## ext = 'ak5PFJetsPFNoPUToCMGCHS'
## fileHLTToReco          = TFile(dir+'analyzerHLTPFNoPUCMGCHS.root')
ext = 'ak5PFJetsL1L2L3ToCMGCHS'
fileHLTToReco          = TFile(dir+'analyzerHLTL1L2L3CMGCHS.root')


## fileHLTToReco          = TFile(dir+'analyzerCHSL1L2L3CMGCHS.root')


#turn-on eta binned
c_turnons = TCanvas("c_turnons")
numPt0 = ROOT.TH1F(fileHLTToReco.Get('h_turnOnPtEtalt0'))
denPt0 = ROOT.TH1F(fileHLTToReco.Get('h_turnOnPtEtalt0Den'))
numPt0.Sumw2()
numPt0.Divide(denPt0)
numPt0.SetAxisRange(0., 200.)
numPt0.SetMinimum(0.1)
numPt0.SetMaximum(1.)
sBlue.formatHisto( numPt0 )
numPt0.Draw()

numPt1 = ROOT.TH1F(fileHLTToReco.Get('h_turnOnPtEtalt1'))
denPt1 = ROOT.TH1F(fileHLTToReco.Get('h_turnOnPtEtalt1Den'))
numPt1.Sumw2()
numPt1.Divide(denPt1)
numPt1.SetMinimum(0.1)
numPt1.SetMaximum(1.)
sRed.formatHisto( numPt1 )
numPt1.Draw("SAMES")


numPt2 = ROOT.TH1F(fileHLTToReco.Get('h_turnOnPtEtalt2'))
denPt2 = ROOT.TH1F(fileHLTToReco.Get('h_turnOnPtEtalt2Den'))
numPt2.Sumw2()
numPt2.Divide(denPt2)
numPt2.SetMinimum(0.1)
numPt2.SetMaximum(1.)
sCyan = Style(fillColor=7, markerColor = 7)
sCyan.formatHisto( numPt2 )
numPt2.Draw("SAMES")

numPt3 = ROOT.TH1F(fileHLTToReco.Get('h_turnOnPtEtalt3'))
denPt3 = ROOT.TH1F(fileHLTToReco.Get('h_turnOnPtEtalt3Den'))
numPt3.Sumw2()
numPt3.Divide(denPt3)
numPt3.SetMinimum(0.1)
numPt3.SetMaximum(1.)
sGreen = Style(fillColor=3, markerColor = 3)
sGreen.formatHisto( numPt3 )
numPt3.Draw("SAMES")

numPt4 = ROOT.TH1F(fileHLTToReco.Get('h_turnOnPtEtalt4'))
denPt4 = ROOT.TH1F(fileHLTToReco.Get('h_turnOnPtEtalt4Den'))
numPt4.Sumw2()
numPt4.Divide(denPt4)
numPt4.SetMinimum(0.1)
numPt4.SetMaximum(1.)
sBlack = Style(fillColor=1)
sBlack.formatHisto( numPt4 )
numPt4.Draw("SAMES")


legturnons = TLegend(0.4,0.1,0.9,0.5)
#legturnons.SetHeader("turn on for hlt ak5 pf jet> 30 GeV, |eta| < 2.6, ak5pfjets offline")
#legturnons.SetHeader("turn on for hlt ak5 pf jet > 30 GeV, |eta| < 2.6, L1L2L3 offline ")
legturnons.SetHeader("turn on for hlt ak5 pf jet > 30 GeV, |eta| < 2.6, chsL1L2L3 offline")
#legturnons.SetHeader("turn on for hlt ak5 pfnopu jet> 30 GeV, |eta| < 2.6, ak5pfjets offline")
#legturnons.SetHeader("turn on for hlt ak5 pfnopu jet > 30 GeV, |eta| < 2.6, L1L2L3 offline ")
#legturnons.SetHeader("turn on for hlt ak5 pfnopu jet > 30 GeV, |eta| < 2.6, chsL1L2L3 offline")
#legturnons.SetHeader("turn on for hlt ak5 pfnopu L1L2L3 jet> 30 GeV, |eta| < 2.6, ak5pfjets offline")
#legturnons.SetHeader("turn on for hlt ak5 pfnopu L1L2L3 jet > 30 GeV, |eta| < 2.6, L1L2L3 offline ")
#legturnons.SetHeader("turn on for hlt ak5 pfnopu L1L2L3 jet > 30 GeV, |eta| < 2.6, chsL1L2L3 offline")
legturnons.AddEntry(numPt0, "recojet |eta| < 0.5")
legturnons.AddEntry(numPt1, "recojet |eta| < 1.")
legturnons.AddEntry(numPt2, "recojet |eta| < 1.5")
legturnons.AddEntry(numPt3, "recojet |eta| < 2.")
legturnons.AddEntry(numPt4, "recojet |eta| < 2.5")
legturnons.Draw("SAMES")

c_turnons.SaveAs('turnOnEtaBinned'+ext+'.png')

