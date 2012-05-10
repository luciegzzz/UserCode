import os, sys
from ROOT import gROOT, TFile,  TLegend, gStyle, TCanvas
import ROOT
from CMGTools.RootTools.Style import *

gROOT.Macro( os.path.expanduser( '~/rootlogon.C' ) )
gStyle.SetOptStat("n")

dir = '/data/lucieg/HltPfJetsAnalyzer/'

## ext = 'HLTReco'
## file = TFile(dir+'analyzerHLTReco.root')
## ext = 'HLTPFNoPUReco'
## file = TFile(dir+'analyzerHLTPFNoPUReco.root')
## ext = 'HLTL1L2L3Reco'
## file = TFile(dir+'analyzerHLTL1L2L3Reco.root')
## ext = 'HLTPFNoPUL1L2L3Reco'
## file = TFile(dir+'analyzerHLTPFNoPUL1L2L3Reco.root')

## ext = 'HLTCMGCHS'
## file = TFile(dir+'analyzerHLTCMGCHS.root') ##
ext = 'HLTPFNoPUCMGCHS'
file = TFile(dir+'analyzerHLTPFNoPUCMGCHS.root')
## ext = 'HLTL1L2L3CMGCHS'
## file = TFile(dir+'analyzerHLTL1L2L3CMGCHS.root')
## ext = 'HLTPFNoPUL1L2L3CMGCHS'
## file = TFile(dir+'analyzerHLTPFNoPUL1L2L3CMGCHS.root')## 

## ext = 'HLTCMG'
## file = TFile(dir+'analyzerHLTCMG.root') ##
## ext = 'HLTPFNoPUCMG'
## file = TFile(dir+'analyzerHLTPFNoPUCMG.root')
## ext = 'HLTL1L2L3CMG'
## file = TFile(dir+'analyzerHLTL1L2L3CMG.root')
## ext = 'HLTPFNoPUL1L2L3CMG'
## file = TFile(dir+'analyzerHLTPFNoPUL1L2L3CMG.root')## 



file.ls()

## #lead pt
## c_leadpt = TCanvas("c_leadpt")
## hltleadpt  = file.Get('h_hltleadpt')
## recoleadpt = file.Get('h_recoleadpt')
## sBlue.formatHisto( hltleadpt )
## sRed.formatHisto( recoleadpt )
## hltleadpt.Draw()
## recoleadpt.Draw("SAMES")

## legpt = TLegend(0.7,0.7,0.9,0.9)
## legpt.SetHeader("leading jet pt")
## legpt.AddEntry(hltleadpt, "hlt")
## legpt.AddEntry(recoleadpt, "reco")
## legpt.Draw("SAMES")

## #lead eta
## c_leadeta = TCanvas("c_leadeta")
## hltleadeta  = file.Get('h_hltleadeta')
## recoleadeta = file.Get('h_recoleadeta')
## sBlue.formatHisto( hltleadeta )
## sRed.formatHisto( recoleadeta )
## recoleadeta.Draw()
## hltleadeta.Draw("SAMES")

## legeta = TLegend(0.7,0.7,0.9,0.9)
## legeta.SetHeader("leading jet eta")
## legeta.AddEntry(hltleadeta, "hlt")
## legeta.AddEntry(recoleadeta, "reco")
## legeta.Draw("SAME")

#response
c_responses = TCanvas("c_responses")
c_responses.Divide(5, 2)
c_responses.cd(1)
deltaPtOverPtEtaBinned0 = ROOT.TH1F(file.Get( 'h_deltaPtOverPtEtaBinned0' ))
deltaPtOverPtEtaBinned0.SetTitle('(ptMatched - hltleadpt) / ptMatched, 0 GeV < ptMatched < 20GeV')
deltaPtOverPtEtaBinned0.Draw()
c_responses.cd(2)
deltaPtOverPtEtaBinned1 = ROOT.TH1F(file.Get( 'h_deltaPtOverPtEtaBinned1' ))
deltaPtOverPtEtaBinned1.SetTitle('(ptMatched - hltleadpt) / ptMatched, 20 GeV < ptMatched < 40GeV')
deltaPtOverPtEtaBinned1.Draw()
c_responses.cd(3)
deltaPtOverPtEtaBinned2 = ROOT.TH1F(file.Get( 'h_deltaPtOverPtEtaBinned2' ))
deltaPtOverPtEtaBinned2.SetTitle('(ptMatched - hltleadpt) / ptMatched, 40 GeV < ptMatched < 60GeV')
deltaPtOverPtEtaBinned2.Draw()
c_responses.cd(4)
deltaPtOverPtEtaBinned3 = ROOT.TH1F(file.Get( 'h_deltaPtOverPtEtaBinned3' ))
deltaPtOverPtEtaBinned3.SetTitle('(ptMatched - hltleadpt) / ptMatched, 60 GeV < ptMatched < 80GeV')
deltaPtOverPtEtaBinned3.Draw()
c_responses.cd(5)
deltaPtOverPtEtaBinned4 = ROOT.TH1F(file.Get( 'h_deltaPtOverPtEtaBinned4' ))
deltaPtOverPtEtaBinned4.SetTitle('(ptMatched - hltleadpt) / ptMatched, 80 GeV < ptMatched < 100GeV')
deltaPtOverPtEtaBinned4.Draw()
c_responses.cd(6)
deltaPtOverPtEtaBinned5 = ROOT.TH1F(file.Get( 'h_deltaPtOverPtEtaBinned5' ))
deltaPtOverPtEtaBinned5.SetTitle('(ptMatched - hltleadpt) / ptMatched, 100 GeV < ptMatched < 120GeV')
deltaPtOverPtEtaBinned5.Draw()
c_responses.cd(7)
deltaPtOverPtEtaBinned6 = ROOT.TH1F(file.Get( 'h_deltaPtOverPtEtaBinned6' ))
deltaPtOverPtEtaBinned6.SetTitle('(ptMatched - hltleadpt) / ptMatched, 120 GeV < ptMatched < 140GeV')
deltaPtOverPtEtaBinned6.Draw()
c_responses.cd(8)
deltaPtOverPtEtaBinned7 = ROOT.TH1F(file.Get( 'h_deltaPtOverPtEtaBinned7' ))
deltaPtOverPtEtaBinned7.SetTitle('(ptMatched - hltleadpt) / ptMatched, 140 GeV < ptMatched < 160GeV')
deltaPtOverPtEtaBinned7.Draw()
c_responses.cd(9)
deltaPtOverPtEtaBinned8 = ROOT.TH1F(file.Get( 'h_deltaPtOverPtEtaBinned8' ))
deltaPtOverPtEtaBinned8.SetTitle('(ptMatched - hltleadpt) / ptMatched, 160 GeV < ptMatched < 180GeV')
deltaPtOverPtEtaBinned8.Draw()
c_responses.cd(10)
deltaPtOverPtEtaBinned9 = ROOT.TH1F(file.Get( 'h_deltaPtOverPtEtaBinned9' ))
deltaPtOverPtEtaBinned9.SetTitle('(ptMatched - hltleadpt) / ptMatched, 180 GeV < ptMatched ')
deltaPtOverPtEtaBinned9.Draw()
c_responses.SaveAs('responsesEta'+ext+'.png')

c_responsesPt = TCanvas("c_responsesPt")
c_responsesPt.Divide(5, 2)
c_responsesPt.cd(1)
deltaPtOverPtPtBinned0 = ROOT.TH1F(file.Get( 'h_deltaPtOverPtPtBinned0' ))
deltaPtOverPtPtBinned0.SetTitle('(ptMatched - hltleadpt) / ptMatched, 0 GeV < ptMatched < 20GeV')
deltaPtOverPtPtBinned0.Draw()
c_responsesPt.cd(2)
deltaPtOverPtPtBinned1 = ROOT.TH1F(file.Get( 'h_deltaPtOverPtPtBinned1' ))
deltaPtOverPtPtBinned1.SetTitle('(ptMatched - hltleadpt) / ptMatched, 20 GeV < ptMatched < 40GeV')
deltaPtOverPtPtBinned1.Draw()
c_responsesPt.cd(3)
deltaPtOverPtPtBinned2 = ROOT.TH1F(file.Get( 'h_deltaPtOverPtPtBinned2' ))
deltaPtOverPtPtBinned2.SetTitle('(ptMatched - hltleadpt) / ptMatched, 40 GeV < ptMatched < 60GeV')
deltaPtOverPtPtBinned2.Draw()
c_responsesPt.cd(4)
deltaPtOverPtPtBinned3 = ROOT.TH1F(file.Get( 'h_deltaPtOverPtPtBinned3' ))
deltaPtOverPtPtBinned3.SetTitle('(ptMatched - hltleadpt) / ptMatched, 60 GeV < ptMatched < 80GeV')
deltaPtOverPtPtBinned3.Draw()
c_responsesPt.cd(5)
deltaPtOverPtPtBinned4 = ROOT.TH1F(file.Get( 'h_deltaPtOverPtPtBinned4' ))
deltaPtOverPtPtBinned4.SetTitle('(ptMatched - hltleadpt) / ptMatched, 80 GeV < ptMatched < 100GeV')
deltaPtOverPtPtBinned4.Draw()
c_responsesPt.cd(6)
deltaPtOverPtPtBinned5 = ROOT.TH1F(file.Get( 'h_deltaPtOverPtPtBinned5' ))
deltaPtOverPtPtBinned5.SetTitle('(ptMatched - hltleadpt) / ptMatched, 100 GeV < ptMatched < 120GeV')
deltaPtOverPtPtBinned5.Draw()
c_responsesPt.cd(7)
deltaPtOverPtPtBinned6 = ROOT.TH1F(file.Get( 'h_deltaPtOverPtPtBinned6' ))
deltaPtOverPtPtBinned6.SetTitle('(ptMatched - hltleadpt) / ptMatched, 120 GeV < ptMatched < 140GeV')
deltaPtOverPtPtBinned6.Draw()
c_responsesPt.cd(8)
deltaPtOverPtPtBinned7 = ROOT.TH1F(file.Get( 'h_deltaPtOverPtPtBinned7' ))
deltaPtOverPtPtBinned7.SetTitle('(ptMatched - hltleadpt) / ptMatched, 140 GeV < ptMatched < 160GeV')
deltaPtOverPtPtBinned7.Draw()
c_responsesPt.cd(9)
deltaPtOverPtPtBinned8 = ROOT.TH1F(file.Get( 'h_deltaPtOverPtPtBinned8' ))
deltaPtOverPtPtBinned8.SetTitle('(ptMatched - hltleadpt) / ptMatched, 160 GeV < ptMatched < 180GeV')
deltaPtOverPtPtBinned8.Draw()
c_responsesPt.cd(10)
deltaPtOverPtPtBinned9 = ROOT.TH1F(file.Get( 'h_deltaPtOverPtPtBinned9' ))
deltaPtOverPtPtBinned9.SetTitle('(ptMatched - hltleadpt) / ptMatched, 180 GeV < ptMatched ')
deltaPtOverPtPtBinned9.Draw()
c_responsesPt.SaveAs('responsesPt'+ext+'.png')

c_response = TCanvas("c_response")
c_response.Divide(2,1)
c_response.cd(1)
respEta = ROOT.TH2F(file.Get('h_responseEta_'))
sBlue.formatHisto( respEta )
respEta.Draw()

c_response.cd(2)
respPt  = ROOT.TH2F(file.Get('h_responsePt_'))
sBlue.formatHisto( respPt )
respPt.Draw()
c_response.SaveAs('response'+ext+'.png')
