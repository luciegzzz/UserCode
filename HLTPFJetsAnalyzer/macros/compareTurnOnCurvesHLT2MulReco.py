import os, sys
from ROOT import gROOT, TFile,  TLegend, gStyle, TCanvas
import ROOT
from CMGTools.RootTools.Style import *

gROOT.Macro( os.path.expanduser( '~/rootlogon.C' ) )
gStyle.SetOptStat(0)

dir = '/data/lucieg/HltPfJetsAnalyzer/'

ext = 'HLT2Reco'
fileHLTToAK5          = TFile(dir+'analyzerHLTReco.root')
fileHLTToAK5L1L2L3    = TFile(dir+'analyzerHLTCMG.root')
fileHLTToAK5chsL1L2L3 = TFile(dir+'analyzerCMGCHS.root')

## ext = 'HLTPFNoPU2Reco'
## fileHLTToAK5          = TFile(dir+'analyzerHLTPFNoPUReco.root')
## fileHLTToAK5L1L2L3    = TFile(dir+'analyzerHLTPFNoPUCMG.root')
## fileHLTToAK5chsL1L2L3 = TFile(dir+'analyzerHLTPFNoPUCMGCHS.root')

## ext = 'HLTPFNoPUL1L2L32Reco'
## fileHLTToAK5          = TFile(dir+'analyzerHLTPFNoPUL1L2L3Reco.root')
## fileHLTToAK5L1L2L3    = TFile(dir+'analyzerHLTPFNoPUL1L2L3CMG.root')
## fileHLTToAK5chsL1L2L3 = TFile(dir+'analyzerHLTPFNoPUL1L2L3CMGCHS.root')

## ext = 'HLTL1L2L32Reco'
## fileHLTToAK5          = TFile(dir+'analyzerHLTL1L2L3Reco.root')
## fileHLTToAK5L1L2L3    = TFile(dir+'analyzerHLTL1L2L3CMG.root')
## fileHLTToAK5chsL1L2L3 = TFile(dir+'analyzerHLTL1L2L3CMGCHS.root')


#turn on overall
c_turnon = TCanvas("c_turnon")
numPt0 = ROOT.TH1F(fileHLTToAK5.Get('h_turnOnPt_'))
denPt0 = ROOT.TH1F(fileHLTToAK5.Get('h_turnOnPtDen_'))
numPt0.Sumw2()
numPt0.Divide(denPt)
numPt0.SetMinimum(0.)
numPt0.SetMaximum(1.)
sRed.formatHisto( numPt0 )
numPt0.Draw()

numPt1 = ROOT.TH1F(fileHLTToAK5.Get('h_turnOnPt_'))
denPt1 = ROOT.TH1F(fileHLTToAK5.Get('h_turnOnPtDen_'))
numPt1.Sumw2()
numPt1.Divide(denPt)
numPt1.SetMinimum(0.)
numPt1.SetMaximum(1.)
sRed.formatHisto( numPt1 )
numPt1.Draw("SAMES")

numPt2 = ROOT.TH1F(fileHLTToAK5.Get('h_turnOnPt_'))
denPt2 = ROOT.TH1F(fileHLTToAK5.Get('h_turnOnPtDen_'))
numPt2.Sumw2()
numPt2.Divide(denPt)
numPt2.SetMinimum(0.)
numPt2.SetMaximum(1.)
sBlack = Style(fillColor=1)
sBlack.formatHisto( numPt2 )
numPt2.Draw("SAMES")

leg = TLegend(0.7,0.7,0.9,0.9)
leg.SetHeader("turn on")
leg.AddEntry(numPt0, "ak5 pf jet > 30 GeV, |eta| < 2.6, to ak5 pfjets")
leg.AddEntry(numPt1, "ak5 pf jet > 30 GeV, |eta| < 2.6, to ak5 pfjets, L1L2L3")
leg.AddEntry(numPt2, "ak5 pf jet > 30 GeV, |eta| < 2.6, to ak5 pfjets, chs L1L2L3")
leg.Draw("SAMES")

## leg = TLegend(0.7,0.7,0.9,0.9)
## leg.SetHeader("turn on")
## leg.AddEntry(numPt0, "ak5 pfnopu jet > 30 GeV, |eta| < 2.6, to ak5 pfjets")
## leg.AddEntry(numPt1, "ak5 pfnopu jet > 30 GeV, |eta| < 2.6, to ak5 pfjets, L1L2L3")
## leg.AddEntry(numPt2, "ak5 pfnopu jet > 30 GeV, |eta| < 2.6, to ak5 pfjets, chs L1L2L3")
## leg.Draw("SAMES")

## leg = TLegend(0.7,0.7,0.9,0.9)
## leg.SetHeader("turn on")
## leg.AddEntry(numPt0, "ak5 pfnopu, L1L2L3 jet > 30 GeV, |eta| < 2.6, to ak5 pfjets")
## leg.AddEntry(numPt1, "ak5 pfnopu, L1L2L3 jet > 30 GeV, |eta| < 2.6, to ak5 pfjets, L1L2L3")
## leg.AddEntry(numPt2, "ak5 pfnopu, L1L2L3 jet > 30 GeV, |eta| < 2.6, to ak5 pfjets, chs L1L2L3")
## leg.Draw("SAMES")

## leg = TLegend(0.7,0.7,0.9,0.9)
## leg.SetHeader("turn on")
## leg.AddEntry(numPt0, "ak5 pf, L1L2L3 jet > 30 GeV, |eta| < 2.6, to ak5 pfjets")
## leg.AddEntry(numPt1, "ak5 pf, L1L2L3 jet > 30 GeV, |eta| < 2.6, to ak5 pfjets, L1L2L3")
## leg.AddEntry(numPt2, "ak5 pf, L1L2L3 jet > 30 GeV, |eta| < 2.6, to ak5 pfjets, chs L1L2L3")
## leg.Draw("SAMES")


c_turnon.SaveAs('HLT2MultReco'+ext+'.png')











