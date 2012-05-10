import os, sys
from ROOT import gROOT, TFile,  TLegend, gStyle, TCanvas, TH1F
import ROOT
from CMGTools.RootTools.Style import *
from CMGTools.RootTools.HistogramComparison import *
from CMGTools.RootTools.RootTools import *
from DataFormats.FWLite import Events, Handle

gROOT.Macro( os.path.expanduser( '~/rootlogon.C' ) )
gStyle.SetOptStat("oumen")

file = TFile('checkZ.root')
file.ls()

events = Chain('Events','checkZ.root')

c_z = TCanvas("c_z")

h = TH1F("h", "Z peak", 60, 75., 105.)
events.Draw('cmgMuoncmgMuoncmgDiObjects_Zevents__ANA.obj.mass()>>h')
h.SetXTitle('mass, GeV')
sBlue.formatHisto(h)

c_z.SaveAs('zpeak.png')


