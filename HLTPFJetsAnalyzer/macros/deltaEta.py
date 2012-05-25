import os, sys
from ROOT import gROOT, TFile,  TLegend, gStyle, TCanvas
import ROOT
from CMGTools.RootTools.Style import *

gROOT.Macro( os.path.expanduser( '~/rootlogon.C' ) )
gStyle.SetOptStat("oumen")


dir = '/data/lucieg/HltPfJetsAnalyzerNoMatching/'

ext = 'Reco'
file0 = TFile(dir+'analyzerHLTReco.root')
file1 = TFile(dir+'analyzerHLTCaloReco.root')
file2 = TFile(dir+'analyzerHLTL1L2L3Reco.root')
file3 = TFile(dir+'analyzerHLTPFNoPUL1L2L3Reco.root')
file4 = TFile(dir+'analyzerHLTPFNoPUReco.root')

## ext = 'CMG'
## file0 = TFile(dir+'analyzerHLTCMG.root')
## file1 = TFile(dir+'analyzerHLTCaloCMG.root')
## file2 = TFile(dir+'analyzerHLTL1L2L3CMG.root')
## file3 = TFile(dir+'analyzerHLTPFNoPUCMG.root')
## file4 = TFile(dir+'analyzerHLTPFNoPUL1L2L3CMG.root')

## ext = 'CMGCHS'
## file0 = TFile(dir+'analyzerHLTCMGCHS.root')
## file1 = TFile(dir+'analyzerHLTCaloCMGCHS.root')
## file2 = TFile(dir+'analyzerHLTL1L2L3CMGCHS.root')
## file3 = TFile(dir+'analyzerHLTPFNoPUCMGCHS.root')
## file4 = TFile(dir+'analyzerHLTPFNoPUL1L2L3CMGCHS.root')

c_deltaEtaRel = TCanvas('c_deltaEtaRel')
deltaEtaRel0 = ROOT.TH1F(file0.Get('h_deltaEta_'))
sBlue.formatHisto(deltaEtaRel0 )
deltaEtaRel0.SetMaximum(10000.)
deltaEtaRel0.SetTitle('eta hlt - eta reco')
deltaEtaRel0.Draw()

deltaEtaRel3 = ROOT.TH1F(file3.Get('h_deltaEta_'))
sGreen.formatHisto(deltaEtaRel3 )
deltaEtaRel3.Draw("SAMES")


deltaEtaRel1 = ROOT.TH1F(file1.Get('h_deltaEta_'))
sRed.formatHisto(deltaEtaRel1 )
deltaEtaRel1.Draw("SAMES")

deltaEtaRel2 = ROOT.TH1F(file2.Get('h_deltaEta_'))
sBlack.formatHisto(deltaEtaRel2 )
deltaEtaRel2.Draw("SAMES")

deltaEtaRel4 = ROOT.TH1F(file4.Get('h_deltaEta_'))
sYellow.formatHisto(deltaEtaRel4 )
deltaEtaRel4.Draw("SAMES")

leg = TLegend(0.6,0.6,0.9,0.9)
leg.SetHeader("turn on")
leg.AddEntry(deltaEtaRel0, 'hlt ak5 pfjets')
leg.AddEntry(deltaEtaRel1, 'hlt ak5 calojets')
leg.AddEntry(deltaEtaRel2, 'hlt ak5 L1L2L3 pfjets')
leg.AddEntry(deltaEtaRel3, 'hlt ak5 pfnopu pfjets')
leg.AddEntry(deltaEtaRel4, 'hlt ak5 pfnopu L1L2L3 pfjets')

leg.Draw("SAMES")

c_deltaEtaRel.SaveAs('deltaEtaRel'+ext+'.png')
