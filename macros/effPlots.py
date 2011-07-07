#! /usr/bin/env python

import ROOT, sys
from DataFormats.FWLite import Events, Handle
from aux import *
from array import array
from makeEffPlots import makeEffPlots
from bookHisto import bookHisto

#input file(s)
#files = ["/data/lucieg/SingleEle/tree_CMG_1k.root"]
files = ["/data/lucieg/RelValZEE423/tree_CMG_0.root","/data/lucieg/RelValZEE423/tree_CMG_1.root","/data/lucieg/RelValZEE423/tree_CMG_2.root"]
#files = ["/data/lucieg/RelValWE423/tree_CMG_0.root","/data/lucieg/RelValWE423/tree_CMG_1.root","/data/lucieg/RelValWE423/tree_CMG_2.root"]

#get objects
events = Events (files)

handleGenLeptons  = Handle ('std::vector<reco::GenParticle>')
handleCmgElectrons  = Handle ('std::vector<cmg::Electron>')

cmgElectrons = ("cmgElectronSel")
genLeptons = ("genParticles")
pdgId      = 11 #for electrons

#output file
histo = ROOT.TFile("effPlots.root", "RECREATE")

#matching
dR                 = ROOT.TH1F("dR", "dR", 100, 0., 10.)
dPtRel             = ROOT.TH1F("dPtRel", "dPtRel", 100, 0., 1.)

####################
##efficiency plots##
####################
#binning
binsLowEdges                 = array('d',[0., 5., 10., 15., 20., 25., 30., 35., 40., 45., 50., 60.])

#denominator histo
genLeptonPt                     = ROOT.TH1F("genLeptonPt", "pt", len(binsLowEdges)-1, binsLowEdges )

#reference = no cut
genLeptonPtMatched              = ROOT.TH1F("genLeptonPtMatched", "pt", len(binsLowEdges)-1, binsLowEdges)

#cuts & histos lists
#vbtf ID
cutsVBTFID                   = ["","cuts_vbtf95ID", "cuts_vbtf90ID", "cuts_vbtf80ID", "cuts_vbtf70ID", "cuts_vbtf60ID"]
histosToCompareVBTFID        = [genLeptonPtMatched]
bookHisto(cutsVBTFID, binsLowEdges, histosToCompareVBTFID)

#vbtf ID + CR
cutsVBTFCR                   = ["","cuts_vbtf95CR", "cuts_vbtf90CR", "cuts_vbtf80CR", "cuts_vbtf70CR", "cuts_vbtf60CR"]
histosToCompareVBTFIDandCR   = [genLeptonPtMatched]
bookHisto(cutsVBTFCR, binsLowEdges, histosToCompareVBTFIDandCR)

#cic ID
cutsCiCID                    = ["", "cuts_veryLooseID", "cuts_looseID", "cuts_mediumID", "cuts_tightID", "cuts_superTightID"]
histosToCompareCiCID         = [genLeptonPtMatched]
bookHisto(cutsCiCID, binsLowEdges, histosToCompareCiCID)

#cic ID + CR
cutsCiCCR                    = ["", "cuts_veryLooseCR", "cuts_looseCR", "cuts_mediumCR", "cuts_tightCR", "cuts_superTightCR"]
histosToCompareCiCIDandCR    = [genLeptonPtMatched]
bookHisto(cutsCiCCR, binsLowEdges, histosToCompareCiCIDandCR)

#versus RA2 cut
## cutsVBTFID += "cut_RA2"
## cutsVBTFCR += "cut_RA2"
## cutsCiCID  += "cut_RA2"
## cutsCiCCR  += "cut_RA2"
RA2LeptonPtMatched              = ROOT.TH1F("RA2LeptonPtMatched", "pt", len(binsLowEdges)-1, binsLowEdges)


####################
##loop over events##
####################
i = 0
for event in events:
    i = i + 1
    if (i > 1000) :
        break

    event.getByLabel (cmgElectrons, handleCmgElectrons)
    event.getByLabel (genLeptons, handleGenLeptons)
    
    cmgEles = handleCmgElectrons.product()
    genLeptons = handleGenLeptons.product()

    for genLepton in genLeptons :
        if (genLepton.status() != 1 or abs(genLepton.pdgId()) != 11 or abs(genLepton.eta()) > 2.5 or (abs(genLepton.eta()) > 1.44 and abs(genLepton.eta()) < 1.57) or genLepton.pt() < 5.):
            continue
        
        else :
            genLeptonPt.Fill(genLepton.pt()) 

            (dRmin, dPt, index) = deltaRmin(genLepton, cmgEles)
            dR.Fill(dRmin)
            dPtRel.Fill(dPt)
            
            if (index == -1) :
                continue

            RA2IDCut = (cmgElectrons[index].sourcePtr().gsfTrack().trackerExpectedHitsInner().numberOfLostHits() < 2)

       ##      RA2VtxCut = (vertices.size() >0) && (cmgLeptons[index].sourcePtr().gsfTrack().dxy(vtxpos) < maxEleD0)  && (cmgLeptons[index].vz() - vtxpos.z() >=1)) 

##             if (RA2IDCut && RA2VtxCut) :
##                  RA2LeptonPtMatched.Fill(genLepton.pt())
            
            if (matched(dRmin, dPt, 0.11, 1.)):
                genLeptonPtMatched.Fill(genLepton.pt())
                cut = 1
                while (cut < len( histosToCompareVBTFID ) ):
                    if (cmgLeptons[index].getSelection(cutsVBTFID[cut])):
                        histosToCompareVBTFID[cut].Fill(genLepton.pt())
                    cut +=1
                cut = 1
                while (cut < len( histosToCompareVBTFIDandCR ) ):
                    if (cmgLeptons[index].getSelection(cutsVBTFID[cut]) and cmgLeptons[index].getSelection(cutsVBTFCR[cut])):
                        histosToCompareVBTFIDandCR[cut].Fill(genLepton.pt())
                    cut +=1
                cut = 1       
                while (cut < len( histosToCompareCiCID ) ):
                    if (cmgLeptons[index].getSelection(cutsCiCID[cut])):
                        histosToCompareCiCID[cut].Fill(genLepton.pt())
                    cut +=1
                cut = 1
                while (cut < len( histosToCompareCiCIDandCR ) ):
                    if (cmgLeptons[index].getSelection(cutsCiCID[cut]) and cmgLeptons[index].getSelection(cutsCiCCR[cut])):
                        histosToCompareCiCIDandCR[cut].Fill(genLepton.pt())
                    cut +=1
           
#plots
genLeptonPt.Sumw2()

genLeptonPtMatched.Sumw2()
genLeptonPtMatched.Divide(genLeptonPt)

cEfficiencies = ROOT.TCanvas("efficiencies")
cEfficiencies.Divide(2,2)

cEfficiencies.cd(1)
leg1   = ROOT.TLegend(0.6,0.1,0.9,0.5)
makeEffPlots(histosToCompareVBTFID, genLeptonPt, cutsVBTFID, "pt(GeV)", "efficiency (#matched/total)", "reconstruction efficiency vs pt, vbtfID", leg1 )

cEfficiencies.cd(2)
leg2   = ROOT.TLegend(0.6,0.1,0.9,0.5)
makeEffPlots(histosToCompareVBTFIDandCR, genLeptonPt, cutsVBTFCR, "pt(GeV)", "efficiency (#matched/total)", "reconstruction efficiency vs pt, vbtfIDandCR", leg2 )

cEfficiencies.cd(3)
leg3   = ROOT.TLegend(0.6,0.1,0.9,0.5)
makeEffPlots(histosToCompareCiCID, genLeptonPt, cutsCiCID, "pt(GeV)", "efficiency (#matched/total)", "reconstruction efficiency vs pt, CiCID", leg3 )

cEfficiencies.cd(4)
leg4   = ROOT.TLegend(0.6,0.1,0.9,0.5)
makeEffPlots(histosToCompareCiCIDandCR, genLeptonPt, cutsCiCCR, "pt(GeV)", "efficiency (#matched/total)", "reconstruction efficiency vs pt, CiC ID and CR", leg4 )


#matching
cMatching  = ROOT.TCanvas("matching")
cMatching.Divide(2,1)

cMatching.cd(1)
dR.Draw()

cMatching.cd(2)
dPtRel.Draw()

histo.cd()
histo.Write()
#histo.Close()
