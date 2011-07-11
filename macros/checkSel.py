#! /usr/bin/env python

import ROOT, sys
from DataFormats.FWLite import Events, Handle
from aux import *
from array import array
from makeEffPlots import makeEffPlots
from bookHisto import bookHisto

ROOT.gStyle.SetPalette(1)

files = ["/data/lucieg/RelValZEE423/tree_CMG_0.root","/data/lucieg/RelValZEE423/tree_CMG_1.root","/data/lucieg/RelValZEE423/tree_CMG_2.root"]

#get objects
events = Events (files)

handleCmgElectrons  = Handle ('std::vector<cmg::Electron>')

cmgElectrons = ("cmgElectronSel")

#checkCuts = ROOT.TH2I("checkCuts","check cuts", 15, 1, 16, 15, 1, 16)
checkCutsCiCCR = ROOT.TH2I("checkCutsCiCCR","check cuts cic CR", 5, 0, 5, 2, 0, 2)
checkCutsCiCID = ROOT.TH2I("checkCutsCiCID","check cuts cic ID", 5, 0, 5, 2, 0, 2)

checkCutsvbtfCR = ROOT.TH2I("checkCutsvbtfCR","check cuts cic CR", 5, 0, 5, 2, 0, 2)
checkCutsvbtfID = ROOT.TH2I("checkCutsvbtfID","check cuts cic ID", 5, 0, 5, 2, 0, 2)

cutsCiC = ["eidVeryLoose", "eidLoose", "eidMedium", "eidTight", "eidSuperTight"]
cutsCiCCR  = ["cuts_veryLooseCR", "cuts_looseCR", "cuts_mediumCR", "cuts_tightCR", "cuts_superTightCR"]
cutsCiCID  = ["cuts_veryLooseID", "cuts_looseID", "cuts_mediumID", "cuts_tightID", "cuts_superTightID"]

cutsvbtf   = ["simpleEleId95relIso", "simpleEleId90relIso", "simpleEleId80relIso", "simpleEleId70relIso", "simpleEleId60relIso"]
cutsvbtfID = ["cuts_vbtf95ID", "cuts_vbtf90ID", "cuts_vbtf80ID", "cuts_vbtf70ID", "cuts_vbtf60ID"]
cutsvbtfCR = ["cuts_vbtf95CR", "cuts_vbtf90CR", "cuts_vbtf80CR", "cuts_vbtf70CR", "cuts_vbtf60CR"]


####################
##loop over events##
####################
i = 0
nEntries = 0
for event in events:
    i = i + 1
    if (i > 1000) :
        break

    event.getByLabel (cmgElectrons, handleCmgElectrons)
    
    cmgEles = handleCmgElectrons.product()

    for cmgEle in cmgEles :
        nEntries += 1
        i = 0
        for cutc in cutsCiC :
            if (((cmgEle.sourcePtr().electronID(cutc) >= 4) and (cmgEle.sourcePtr().electronID(cutc) < 8)) or
                (cmgEle.sourcePtr().electronID(cutc) >= 12)): # if the CR cut is passed
                checkCutsCiCCR.Fill(i, cmgEle.getSelection(cutsCiCCR[i]))
            if ((cmgEle.sourcePtr().electronID(cutc) % 2) == 1): # if the ID cut is passed
                checkCutsCiCID.Fill(i, cmgEle.getSelection(cutsCiCID[i]))
            i += 1
        i = 0
        for cutv in cutsvbtf :
            if ( cmgEle.sourcePtr().electronID(cutv) > 3): # if the CR cut is passed
                checkCutsvbtfCR.Fill(i, cmgEle.getSelection(cutsvbtfCR[i]))
            if ((cmgEle.sourcePtr().electronID(cutv) % 2) == 1): # if the ID cut is passed
                checkCutsvbtfID.Fill(i, cmgEle.getSelection(cutsvbtfID[i]))
            i += 1

print nEntries


c = ROOT.TCanvas("c")
c.Divide(2,2)
c.cd(1)
checkCutsCiCCR.Draw("colz")
c.cd(2)
checkCutsCiCID.Draw("colz")
c.cd(3)
checkCutsvbtfCR.Draw("colz")
c.cd(4)
checkCutsvbtfID.Draw("colz")
