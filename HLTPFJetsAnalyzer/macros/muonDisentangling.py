import os, sys
from ROOT import gROOT, TFile,  TLegend, gStyle, TCanvas
import ROOT
from CMGTools.RootTools.Style import *

gROOT.Macro( os.path.expanduser( '~/rootlogon.C' ) )
gStyle.SetOptStat("oumen")

#dir = '/data/lucieg/HltPfJetsAnalyzer/'
#dir = '/data/lucieg/HltPfJetsAnalyzerNoMatchingHLTMay10/'
#dir = '/data/lucieg/HltPfJetsAnalyzerMatchingRestoredHLTMay10/'
dir = '/data/lucieg/HltPfJetsAnalyzerNoMatchingMuonDisentangledHLTMay16/'

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

ext = 'HLT2CMGCHS'
## fileAK5ToReco                = TFile(dir+'analyzerHLTCMGCHS.root')
## fileAK5PFNoPUToReco          = TFile(dir+'analyzerHLTPFNoPUCMGCHS.root')
fileAK5PFNoPUL1L2L3ToReco    = TFile(dir+'analyzerHLTPFNoPUL1L2L3CMGCHS.root')
## fileAK5L1L2L3ToReco          = TFile(dir+'analyzerHLTL1L2L3CMGCHS.root')
## fileCaloToReco               = TFile(dir+'analyzerHLTCaloCMGCHS.root')
dir1 = '/data/lucieg/HltPfJetsAnalyzerNoMatchingHLTMay10/'
file    = TFile(dir1+'analyzerHLTPFNoPUL1L2L3CMGCHS.root')
file.ls()
filedummy = TFile('test.root')


c_dR = TCanvas("c_dR")
dR = ROOT.TH1F(fileAK5PFNoPUL1L2L3ToReco.Get("h_dRjm"))
sBlue.formatHisto( dR )
dR.Draw()
c_dR.SaveAs("dRmCHSL1L2L3.png")

c_pt = TCanvas("c_pt")
ptMu = ROOT.TH1F(file.Get("h_turnOnPt_"))
sRed.formatHisto( ptMu )
ptMu.SetTitle("jet pt, passing hlt pfnopu jet with pt > 30GeV, |eta| < 2.6")
ptMu.Draw()
ptMuDis = ROOT.TH1F(fileAK5PFNoPUL1L2L3ToReco.Get("h_turnOnPt_"))
sBlue.formatHisto( ptMuDis )
ptMuDis.Draw("SAMES")

leg = TLegend(0.4,0.1,0.9,0.5)
leg.AddEntry(ptMu, "all recojets")
leg.AddEntry(ptMuDis, "recojets not muons")
leg.Draw("SAMES")

c_pt.SaveAs("ptNum.png")

