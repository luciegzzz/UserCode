import os, sys
from ROOT import gROOT, TFile,  TLegend, gStyle, TCanvas
import ROOT
from CMGTools.RootTools.Style import *

gROOT.Macro( os.path.expanduser( '~/rootlogon.C' ) )
gStyle.SetOptStat(0)

#dir = '/data/lucieg/HltPfJetsAnalyzer/'
#dir = '/data/lucieg/HltPfJetsAnalyzerNoMatchingHLTMay10/'
## dir0 = '/data/lucieg/HltPfJetsAnalyzerMatchingRestoredHLTMay10/'
## dir1 = '/data/lucieg/HltPfJetsAnalyzerNoMatchingMuonDisentangledHLTMay16/'
dir = '/data/lucieg/HltPfJetsAnalyzerNoMatchingMuonDisentangledEvenAtHLTHLTMay16/'
#dir = '../test/'

## ext = 'HLT2Reco'
## fileCaloToReco               = TFile(dir+'analyzerHLTCaloReco.root')
## fileAK5ToReco                = TFile(dir+'analyzerHLTReco.root')
## fileAK5PFNoPUToReco          = TFile(dir+'analyzerHLTPFNoPUReco.root')
## fileAK5PFNoPUL1L2L3ToReco    = TFile(dir+'analyzerHLTPFNoPUL1L2L3Reco.root')
## fileAK5L1L2L3ToReco          = TFile(dir+'analyzerHLTL1L2L3Reco.root')
## file = TFile('test.root')

## ext = 'HLT2CMG'
## fileCaloToReco               = TFile(dir+'analyzerHLTCaloCMG.root')
## fileAK5ToReco                = TFile(dir+'analyzerHLTCMG.root')
## fileAK5PFNoPUToReco          = TFile(dir+'analyzerHLTPFNoPUCMG.root')
## fileAK5PFNoPUL1L2L3ToReco    = TFile(dir+'analyzerHLTPFNoPUL1L2L3CMG.root')
## fileAK5L1L2L3ToReco          = TFile(dir+'analyzerHLTL1L2L3CMG.root')
## file = TFile('test.root')

ext = 'HLT2CMGCHSFullyNoMu'
fileAK5ToReco                = TFile(dir+'analyzerHLTCMGCHS.root')
fileAK5PFNoPUToReco          = TFile(dir+'analyzerHLTPFNoPUCMGCHS.root')
fileAK5PFNoPUL1L2L3ToReco    = TFile(dir+'analyzerHLTPFNoPUL1L2L3CMGCHS.root')
fileAK5L1L2L3ToReco          = TFile(dir+'analyzerHLTL1L2L3CMGCHS.root')
fileCaloToReco               = TFile(dir+'analyzerHLTCaloCMGCHS.root')
file = TFile('test.root')

#turn on overall
c_turnon = TCanvas("c_turnon")
numPt0 = ROOT.TH1F(fileAK5ToReco.Get('h_turnOnPt_'))
denPt0 = ROOT.TH1F(fileAK5ToReco.Get('h_turnOnPtDen_'))
numPt0.Sumw2()
numPt0.Divide(denPt0)
numPt0.SetAxisRange(0., 200.)
numPt0.SetMinimum(0.)
numPt0.SetMaximum(1.)
sRed.formatHisto( numPt0 )
numPt0.Draw()

numPt1 = ROOT.TH1F(fileAK5PFNoPUToReco.Get('h_turnOnPt_'))
denPt1 = ROOT.TH1F(fileAK5PFNoPUToReco.Get('h_turnOnPtDen_'))
numPt1.Sumw2()
numPt1.Divide(denPt1)
numPt1.SetMinimum(0.)
numPt1.SetMaximum(1.)
sBlue.formatHisto( numPt1 )
numPt1.Draw("SAMES")

numPt2 = ROOT.TH1F(fileAK5PFNoPUL1L2L3ToReco.Get('h_turnOnPt_'))
denPt2 = ROOT.TH1F(fileAK5PFNoPUL1L2L3ToReco.Get('h_turnOnPtDen_'))
numPt2.Sumw2()
numPt2.Divide(denPt2)
numPt2.SetMinimum(0.)
numPt2.SetMaximum(1.)
sBlack.markerStyle = 23
sBlack.formatHisto( numPt2 )
numPt2.Draw("SAMES")

numPt3 = ROOT.TH1F(fileAK5L1L2L3ToReco.Get('h_turnOnPt_'))
denPt3 = ROOT.TH1F(fileAK5L1L2L3ToReco.Get('h_turnOnPtDen_'))
numPt3.Sumw2()
numPt3.Divide(denPt3)
numPt3.SetMinimum(0.)
numPt3.SetMaximum(1.)
sGreen.markerStyle = 24
sGreen.formatHisto( numPt3 )
numPt3.Draw("SAMES")

numPt4 = ROOT.TH1F(fileCaloToReco.Get('h_turnOnPt_'))
denPt4 = ROOT.TH1F(fileCaloToReco.Get('h_turnOnPtDen_'))
numPt4.Sumw2()
numPt4.Divide(denPt4)
numPt4.SetMinimum(0.)
numPt4.SetMaximum(1.)
sYellow.markerStyle = 31
sYellow.formatHisto( numPt4 )
#numPt4.Draw()
numPt4.Draw("SAMES")



## leg = TLegend(0.4,0.1,0.9,0.5)
## leg.SetHeader("turn on")
## leg.AddEntry(numPt0, "ak5 pf jet > 30 GeV, |eta| < 2.6, to ak5 pfjets")
## leg.AddEntry(numPt1, "ak5 pfnopu pf jet > 30 GeV, |eta| < 2.6, to ak5 pfjets")
## leg.AddEntry(numPt2, "ak5 pfnopu L1L2L3 pf jet > 30 GeV, |eta| < 2.6, to ak5 pfjets")
## leg.AddEntry(numPt3, "ak5  L1L2L3 pf jet > 30 GeV, |eta| < 2.6, to ak5 pfjets")
## leg.AddEntry(numPt4, "ak5 calo jet > 30 GeV, |eta| < 2.6, to ak5 pfjets")
## leg.Draw("SAMES")

## leg = TLegend(0.4,0.1,0.9,0.5)
## leg.SetHeader("turn on")
## leg.AddEntry(numPt0, "ak5 pf jet > 30 GeV, |eta| < 2.6, to ak5 pfjets L1L2L3")
## leg.AddEntry(numPt1, "ak5 pfnopu pf jet > 30 GeV, |eta| < 2.6, to ak5 pfjets L1L2L3")
## leg.AddEntry(numPt2, "ak5 pfnopu L1L2L3 pf jet > 30 GeV, |eta| < 2.6, to ak5 pfjets L1L2L3")
## leg.AddEntry(numPt3, "ak5  L1L2L3 pf jet > 30 GeV, |eta| < 2.6, to ak5 pfjets L1L2L3")
## leg.AddEntry(numPt4, "ak5 calo jet > 30 GeV, |eta| < 2.6, to ak5 pfjets L1L2L3")
## leg.Draw("SAMES")

leg = TLegend(0.4,0.1,0.9,0.5)
leg.SetHeader("turn on")
leg.AddEntry(numPt0, "ak5 pf jet > 30 GeV, |eta| < 2.6, to ak5 pfjets chsL1L2L3")
leg.AddEntry(numPt1, "ak5 pfnopu pf jet > 30 GeV, |eta| < 2.6, to ak5 pfjets chsL1L2L3")
leg.AddEntry(numPt2, "ak5 pfnopu L1L2L3 pf jet > 30 GeV, |eta| < 2.6, to ak5 pfjets chsL1L2L3")
leg.AddEntry(numPt3, "ak5  L1L2L3 pf jet > 30 GeV, |eta| < 2.6, to ak5 pfjets chsL1L2L3")
leg.AddEntry(numPt4, "ak5 calo jet > 30 GeV, |eta| < 2.6, to ak5 pfjets chsL1L2L3")
leg.Draw("SAMES")

c_turnon.SaveAs('MultHLT2Reco'+ext+'.png')










