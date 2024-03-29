#! /usr/bin/env python

import ROOT, sys, os, pdb, pprint  #pdb for breakpoints, pprint to print anything and everything, maybe even coffee
from DataFormats.FWLite import Events, Handle
from array import array
#my functions
from aux import *
from makeEffPlots import makeEffPlots
from bookHisto import bookHisto
from styles import *
from calculateAveEff import *
from fillHistoCutsPassed import *

ROOT.gStyle.SetPalette(1)
ROOT.gStyle.SetOptStat(100011)
####################
#------inputs------#
####################

####   PARAMETERS TO MODIFY    #######
#path = '/data/lucieg/RelValZEE425/'
#path  = '/data/lucieg/WJetsToLNu_TuneZ2_7TeV_madgraph_tauola/'
path = '/data/lucieg/QCD_Pt-30to80_BCtoE_TuneZ2_7TeV-pythia6/'
postfix            = 'QCDbceTESTPU10'
#postfix            = 'WjetsTESTPU10'
maxEvents          = 500000#000
pdgId              = 11 #for electrons
numberOfPileUpInt  = 10 # select number of pile-up ( extend to range ?)
effFileName        = 'efficiencies' + postfix
effFileRA2IsolName = 'RA2Isol' + postfix
variable           = 'pt' # trying to make the macro generic enough to easily switch from pt to eta
dRMatching         = 0.15
dPtRelMatching     = 0.5

# ---------------- ---------------- ---------------- ---------------- ---------------- ---------------- #
files = []
listFiles = os.listdir(path)
for infile in listFiles :
    files.append(path + infile)
#pdb.set_trace() #for the record & debugging purposes

#get objects
events = Events (files)

handleGenLeptons    = Handle ('std::vector<reco::GenParticle>')
handleCmgElectrons  = Handle ('std::vector<cmg::Electron>')
handleVertices      = Handle ('std::vector<reco::Vertex>')
handlePileUp        = Handle ('std::vector<PileupSummaryInfo>')

cmgElectrons        = ("cmgElectronSel")
genLeptons          = ("genEAndMuStatus1")
vertices            = ("offlinePrimaryVertices")
pileup              = ("addPileupInfo")


##########################################
#------outputs & related quantities------#
##########################################
#output files
effFile        = open(effFileName,'w')
effFileRA2Isol = open(effFileRA2IsolName,'w')

histo   = ROOT.TFile("effPlots"+postfix+".root", "RECREATE")

#********************#
#*****matching*******#
#********************#
h_dR                 = ROOT.TH1F("h_dR", "dR", 1000, 0., 10.)
h_dPtRel             = ROOT.TH1F("h_dPtRel", "(pt(reco)-pt(gen))/pt(gen), for reco ele closest to gen", 200, 0., 2.)
h_dPtRelMatched      = ROOT.TH1F("h_dPtRelMatched", "(pt(reco)-pt(gen))/pt(gen), for reco ele matched(dR < 0.15) to gen", 200, 0., 2.)
h_diffCharge         = ROOT.TH1F("h_diffCharge", "charge(gen) - charge(reco)", 110, 10., 1.)
h_diffChargeMatched  = ROOT.TH1F("h_diffChargeMatched", "charge(gen) - charge(reco), matched (dR<0.15 and #Delta pt < 0.5", 100, 0., 1.)



#********************#
#**efficiency plots**#
#********************#
#binning
binsLowEdges                    = array('d',[0., 5., 10., 15., 20., 25., 30., 35., 40., 45., 50., 60.])

#denominator histo
genLeptonX                      = ROOT.TH1F("genLeptonX", variable, len(binsLowEdges)-1, binsLowEdges )

#reference = no cut
genLeptonXMatched               = ROOT.TH1F("genLeptonXMatched", variable, len(binsLowEdges)-1, binsLowEdges)

#cuts & histos lists
#vbtf ID
cutsVBTFID                   = ["","cuts_vbtf95ID", "cuts_vbtf90ID", "cuts_vbtf80ID", "cuts_vbtf70ID", "cuts_vbtf60ID"]
#histosToCompareVBTFID        = {"" : genLeptonXMatched}
histosToCompareVBTFID        = [genLeptonXMatched]
bookHisto(cutsVBTFID, binsLowEdges, histosToCompareVBTFID)

#vbtf ID + CR
cutsVBTFCR                   = ["","cuts_vbtf95CR", "cuts_vbtf90CR", "cuts_vbtf80CR", "cuts_vbtf70CR", "cuts_vbtf60CR"]
#histosToCompareVBTFIDandCR   = {"" : genLeptonXMatched}
histosToCompareVBTFIDandCR   = [genLeptonXMatched]
bookHisto(cutsVBTFCR, binsLowEdges, histosToCompareVBTFIDandCR)

#cic ID
cutsCiCID                    = ["", "cuts_veryLooseID", "cuts_looseID", "cuts_mediumID", "cuts_tightID", "cuts_superTightID"]
#histosToCompareCiCID         = {"" : genLeptonXMatched}
histosToCompareCiCID         = [genLeptonXMatched]
bookHisto(cutsCiCID, binsLowEdges, histosToCompareCiCID)

#cic ID + CR
cutsCiCCR                    = ["", "cuts_veryLooseCR", "cuts_looseCR", "cuts_mediumCR", "cuts_tightCR", "cuts_superTightCR"]
#histosToCompareCiCIDandCR    = {"" : genLeptonXMatched}
histosToCompareCiCIDandCR    = [genLeptonXMatched]
bookHisto(cutsCiCCR, binsLowEdges, histosToCompareCiCIDandCR)

#isolation
h_Isol                       = ROOT.TH1F("h_Isol", "Isol", 1000, 0., 10.)
cutsIsol                     = [1000., 1., 0.7, 0.5, 0.4, 0.3, 0.2, 0.1]

#pile-up
h_pileUp                       = ROOT.TH1F("h_pileUp", "# pileUp vertices", 25, 0., 25.)
cutsPileUp                     = [0, 3, 6, 9, 12]

#adding RA2 cuts ( and wth RA2 is cutting on ? :)...nothing. Just isolation )
histosRA2                    = []
bookHisto(cutsIsol, binsLowEdges, histosRA2)

h_nrOfLostHitsVsMissingHits     = ROOT.TH2F("h_nrOfLostHitsVsMissingHits","Lost hits", 10, 0, 10, 10, 0, 10)
h_cmgdxyVspatdxy                = ROOT.TH2F("h_cmgdxyVspatdxy","cmg dxy vs pat dxy", 200, 0., 0.1,  200, 0., 0.1)
h_numberOfLostHits              = ROOT.TH2F("numberOfLostHits", "number of lost hits",20, 0., 20., 20, 0., 20.)
h_d0                            = ROOT.TH1F("d0", "d0", 200, 0., 0.1)
h_dz                            = ROOT.TH1F("dz", "dz", 200, 0., 1)

########################################
#-----------loop over events-----------#
########################################
ratioVBTFIDIsolEleSel = {}
errRatioVBTFIDIsolEleSel = {}
for cut in cutsVBTFID :
    ratioVBTFIDIsolEleSel[cut] = array('d', (0.,)*len(cutsIsol))
    errRatioVBTFIDIsolEleSel[cut] = array('d', (0.,)*len(cutsIsol))

ratioCiCIDIsolEleSel = {}
errRatioCiCIDIsolEleSel = {}
for cut in cutsCiCID :
    ratioCiCIDIsolEleSel[cut] = array('d', (0.,)*len(cutsIsol))
    errRatioCiCIDIsolEleSel[cut] = array('d', (0.,)*len(cutsIsol))

ratioVBTFIDEleSel   = array('d', (0.,)*len(cutsVBTFID))  # "cuts_vbtf95", "cuts_vbtf90", "cuts_vbtf80", "cuts_vbtf70", "cuts_vbtf60"
errRatioVBTFIDEleSel   = array('d', (0.,)*len(cutsVBTFID))
ratioVBTFIDCREleSel = array('d', (0.,)*len(cutsVBTFCR)) 
ratioCiCIDEleSel    = array('d', (0.,)*len(cutsCiCID))  #"cuts_veryLoose", "cuts_loose", "cuts_medium", "cuts_tight", "cuts_superTight"
errRatioCiCIDEleSel    = array('d', (0.,)*len(cutsCiCID)) 
ratioCiCIDCREleSel  = array('d', (0.,)*len(cutsCiCCR))

ratioRA2IsolSel     = array('d', (0.,)*len(cutsIsol))  
errRatioRA2IsolSel  = array('d', (0.,)*len(cutsIsol))
h_ratioRA2IsolSel   = ROOT.TH1F("h_ratioRA2IsolSel","test", 110, 0., 1.1)

nrEvWithGenLeptons = 0

i = 0 # event counter
for event in events:
    i = i + 1
    if ((i % 1000) == 0):
        print i
    if (i > maxEvents) :
        break

    #for overall efficiencies (2D plots)
    nrGenLeptons     = 0.

    nrVBTFIDIsolEleSel = {}
    for cut in cutsVBTFID :
        nrVBTFIDIsolEleSel[cut] = array('d', (0.,)*len(cutsIsol))

    nrCiCIDIsolEleSel = {}
    for cut in cutsCiCID :
        nrCiCIDIsolEleSel[cut] = array('d', (0.,)*len(cutsIsol))


    
    nrVBTFIDEleSel   = array('d', (0.,)*len(cutsVBTFID))  # "cuts_vbtf95", "cuts_vbtf90", "cuts_vbtf80", "cuts_vbtf70", "cuts_vbtf60"
    nrVBTFIDCREleSel = array('d', (0.,)*len(cutsVBTFCR)) 
    nrCiCIDEleSel    = array('d', (0.,)*len(cutsCiCID))  #"cuts_veryLoose", "cuts_loose", "cuts_medium", "cuts_tight", "cuts_superTight"
    nrCiCIDCREleSel  = array('d', (0.,)*len(cutsCiCCR))  
    nrRA2IsolSel     = array('d', (0.,)*len(cutsIsol))

    indices = []
  
    #get objects
    event.getByLabel (genLeptons, handleGenLeptons)
    event.getByLabel (cmgElectrons, handleCmgElectrons)
    event.getByLabel (vertices, handleVertices)
    event.getByLabel (pileup, handlePileUp)
    
    cmgEles = handleCmgElectrons.product()
    genLeps = handleGenLeptons.product()
    vtces   = handleVertices.product()
    puvtces = handlePileUp.product()
    
    #pile-up info
    nrOfVtces = vtces.size()
    nrOfPUvertices = puvtces[1].getPU_NumInteractions() #assuming 0 = BC -1, 1 = BC, 2 = BC +1
    h_pileUp.Fill(nrOfPUvertices)

    if (nrOfPUvertices != numberOfPileUpInt) :
        continue
          
    for genLepton in genLeps :
        if (abs(genLepton.pdgId()) != pdgId or abs(genLepton.eta()) > 2.5 or (abs(genLepton.eta()) > 1.44 and abs(genLepton.eta()) < 1.57) or genLepton.pt() < 5.):
            continue
        
        else :
            nrGenLeptons += 1
            genLeptonX.Fill(genLepton.pt()) 

            if (cmgEles.size() == 0) : # no need to go further if no reco ele ;) 
                continue

            (dRmin, dPt, diffCharge, index) = deltaRmin(genLepton, cmgEles)

            if (index == -1) : 
                print 'something fishy. Index = -1, but there should be some reco eles ???'

            #ID & co variables
            h_dR.Fill(dRmin)
            h_dPtRel.Fill(dPt)
            h_diffCharge.Fill(diffCharge)
            if (dRmin < dRMatching ) :
                h_dPtRelMatched.Fill(dPt)
                if (dPt < dPtRelMatching) :
                    h_diffChargeMatched.Fill(diffCharge)

            for cmgEle in cmgEles :
                h_Isol.Fill(cmgEle.relIso())
            

           ############# RA2 cuts ##############
            # "ID" = actually, CR
            numberOfLostHits    = cmgEles[index].sourcePtr().gsfTrack().trackerExpectedHitsInner().numberOfLostHits()
            h_numberOfLostHits.Fill(numberOfLostHits)
            numberOfMissingHits = cmgEles[index].numberOfHits()
            h_nrOfLostHitsVsMissingHits.Fill(numberOfMissingHits,numberOfLostHits)
            # RA2IDCut = ( numberOfLostHits < 2 )
            RA2IDCut = ( numberOfMissingHits < 2 ) #used by conversion veto everywhere else in cmssw...
            
            # vtx cuts
            if (nrOfVtces > 0) :
                vtxpos = vtces[0].position()
                d0 = cmgEles[index].sourcePtr().gsfTrack().dxy(vtxpos)
                h_d0.Fill(d0) # this is a CR cut
                h_cmgdxyVspatdxy.Fill(d0, cmgEles[index].dxy())
                dz = cmgEles[index].vz() - vtxpos.z()
                h_dz.Fill(dz)
            RA2VtxAssociationCuts = (nrOfVtces > 0) and (d0 < 0.02 ) and (dz <= 1.)
            
            ############ what passed what #########
            if (matched(dRmin, dPt, diffCharge, dRMatching, dPtRelMatching, index, indices)):#ele seems to be reco'ed :)
                nrVBTFIDEleSel[0]   += 1
                nrVBTFIDCREleSel[0] += 1
                nrCiCIDEleSel[0]    += 1  
                nrCiCIDCREleSel[0]  += 1
                genLeptonXMatched.Fill(genLepton.pt()) 
                if (RA2IDCut and RA2VtxAssociationCuts) :
                    fillHistoLowerThanCutsPassed(histosRA2, nrRA2IsolSel, cutsIsol, cmgEles[index].relIso(), genLepton.pt())
                fillHistoPredefAndLTCutsPassed(histosToCompareVBTFID, nrVBTFIDIsolEleSel, cutsVBTFID, cutsIsol, cmgEles, index, genLepton.pt(), cmgEles[index].relIso() )
                fillHistoPredefAndLTCutsPassed(histosToCompareCiCID, nrCiCIDIsolEleSel, cutsCiCID, cutsIsol, cmgEles, index, genLepton.pt(), cmgEles[index].relIso())
         
                fillHistoPredefCutsPassed(histosToCompareVBTFIDandCR, nrVBTFIDCREleSel, cutsVBTFCR, cmgEles, index, genLepton.pt())
                fillHistoPredefCutsPassed(histosToCompareCiCIDandCR, nrCiCIDCREleSel, cutsCiCCR, cmgEles, index, genLepton.pt())
            else :
                indices.remove(index)
            
    if (nrGenLeptons > 0) :
        nrEvWithGenLeptons += 1
        cut = 0
       # while (cut  < len(nrVBTFIDEleSel)) :
        for cut in cutsVBTFID :
            cutIsol = 0
            while (cutIsol < len(cutsIsol)):
                (ratioVBTFIDIsolEleSel[cut])[cutIsol]    += (nrVBTFIDIsolEleSel[cut])[cutIsol] / nrGenLeptons
                (errRatioVBTFIDIsolEleSel[cut])[cutIsol] += ((nrVBTFIDIsolEleSel[cut])[cutIsol] / nrGenLeptons) * ((nrVBTFIDIsolEleSel[cut])[cutIsol] / nrGenLeptons)
                cutIsol +=1
        for cut in cutsCiCID :
            cutIsol = 0
            while (cutIsol < len(cutsIsol)):
                (ratioCiCIDIsolEleSel[cut])[cutIsol]    += (nrCiCIDIsolEleSel[cut])[cutIsol] / nrGenLeptons
                (errRatioCiCIDIsolEleSel[cut])[cutIsol] += ((nrCiCIDIsolEleSel[cut])[cutIsol] / nrGenLeptons) * ((nrCiCIDIsolEleSel[cut])[cutIsol] / nrGenLeptons)
                cutIsol +=1
        cut = 0 # don't forget to initialize the variable you're looping over ;)
        while (cut < len( nrRA2IsolSel )) :
            ratioRA2IsolSel[cut]        += (nrRA2IsolSel[cut] / nrGenLeptons)
            errRatioRA2IsolSel[cut]     += ((nrRA2IsolSel[cut] / nrGenLeptons) * (nrRA2IsolSel[cut] / nrGenLeptons))
            if (cut == 0) :
             #   print (nrRA2IsolSel[cut] / nrGenLeptons)
                h_ratioRA2IsolSel.Fill(nrRA2IsolSel[cut] / nrGenLeptons)
            cut += 1


calculateAveEffMultiCuts(ratioVBTFIDIsolEleSel, errRatioVBTFIDIsolEleSel, nrEvWithGenLeptons, effFile)       
calculateAveEffMultiCuts(ratioCiCIDIsolEleSel, errRatioCiCIDIsolEleSel, nrEvWithGenLeptons, effFile)       
##calculateAveEff(cutsVBTFID, ratioVBTFIDEleSel, errRatioVBTFIDEleSel, nrEvWithGenLeptons, effFile)
## #calculateAveEff(cutsVBTFCR, ratioVBTFIDCREleSel, nrEvWithGenLeptons, effFile)
## calculateAveEff(cutsCiCID, ratioCiCIDEleSel,errRatioCiCIDEleSel, nrEvWithGenLeptons, effFile)
## #calculateAveEff(cutsCiCCR, ratioCiCIDCREleSel, nrEvWithGenLeptons, effFile)
calculateAveEff(cutsIsol, ratioRA2IsolSel, errRatioRA2IsolSel , nrEvWithGenLeptons, effFileRA2Isol)


#######################################           
#---------plots-----------------------#
#######################################

#-------efficiencies------------------#
genLeptonX.Sumw2()

genLeptonXMatched.Sumw2()
genLeptonXMatched.Divide(genLeptonX)

cEfficiencies = ROOT.TCanvas("efficiencies")
cEfficiencies.Divide(2,2)

histosRA2[0].Divide(genLeptonX)
histosRA2[0].SetLineColor(28)
histosRA2[0].SetLineWidth(3)

histosRA2[6].Divide(genLeptonX)
histosRA2[6].SetLineColor(7)
histosRA2[6].SetLineWidth(3)

cEfficiencies.cd(1)
leg1   = ROOT.TLegend(0.6,0.1,0.9,0.5)
makeEffPlots(histosToCompareVBTFID, genLeptonX, cutsVBTFID, "pt(GeV)", "efficiency (#matched/total)", "reconstruction efficiency vs pt, vbtfID", leg1 )
leg1.AddEntry(histosRA2[0])
leg1.AddEntry(histosRA2[6])
histosRA2[0].Draw("SAME")
histosRA2[6].Draw("SAME")

cEfficiencies.cd(2)
leg2   = ROOT.TLegend(0.6,0.1,0.9,0.5)
makeEffPlots(histosToCompareVBTFIDandCR, genLeptonX, cutsVBTFCR, "pt(GeV)", "efficiency (#matched/total)", "reconstruction efficiency vs pt, vbtfIDandCR", leg2 )
leg2.AddEntry(histosRA2[0])
leg2.AddEntry(histosRA2[6])
histosRA2[0].Draw("SAME")
histosRA2[6].Draw("SAME")

cEfficiencies.cd(3)
leg3   = ROOT.TLegend(0.6,0.1,0.9,0.5)
makeEffPlots(histosToCompareCiCID, genLeptonX, cutsCiCID, "pt(GeV)", "efficiency (matched/total)", "reconstruction efficiency vs pt, CiCID", leg3 )
leg3.AddEntry(histosRA2[0])
leg3.AddEntry(histosRA2[6])
histosRA2[0].Draw("SAME")
histosRA2[6].Draw("SAME")

cEfficiencies.cd(4)
leg4   = ROOT.TLegend(0.6,0.1,0.9,0.5)
makeEffPlots(histosToCompareCiCIDandCR, genLeptonX, cutsCiCCR, "pt(GeV)", "efficiency (#matched/total)", "reconstruction efficiency vs pt, CiC ID and CR", leg4 )
leg4.AddEntry(histosRA2[0])
leg4.AddEntry(histosRA2[6])
histosRA2[0].Draw("SAME")
histosRA2[6].Draw("SAME")

cEfficiencies.SaveAs('effPlots' + postfix + '.png')

#-------matching------------------#
cMatching  = ROOT.TCanvas("matching")
cMatching.Divide(3,1)

cMatching.cd(1)
cMatching.SetLogy()
setStyle(h_dR)
h_dR.GetXaxis().SetLimits(0, 1.2)
h_dR.Draw()

cMatching.cd(2)
cMatching.SetLogy()
#h_dPtRel.GetXaxis().SetLimits(0, 1.)
setStyle(h_dPtRel)
h_dPtRel.Draw()
setStyle(h_dPtRelMatched,2)
h_dPtRelMatched.Draw("SAME")

cMatching.cd(3)
cMatching.SetLogy()
setStyle(h_diffCharge)
h_diffCharge.Draw()
setStyle(h_diffChargeMatched)
h_diffChargeMatched.Draw("SAME")

## cMatching.cd(4)
## setStyle(h_Isol)
## h_Isol.Draw()
#h_ratioRA2IsolSel.Draw()


cMatching.SaveAs('matching' + postfix + '.png')

#-------RA2------------------#
cRA2 = ROOT.TCanvas("RA2")
cRA2.Divide(4,1)
## cRA2.cd(1)
## h_numberOfLostHits.Draw()

cRA2.cd(1)
setStyle(h_d0, 1, 1, "dxy(PV)","#events", "d0 = dxy(PV) distribution")
h_d0.Draw()

cRA2.cd(2)
setStyle(h_dz, 1, 1, "dz(PV)","#events", "dz = dz(PV) = ele.vz() - vtx.z() distribution")
h_dz.Draw()

## cRA2.cd(4)
## h_pileUp.Draw()

cRA2.cd(3)
setStyle2D(h_nrOfLostHitsVsMissingHits, 20, "number of missing hits", "number of lost hits")
h_nrOfLostHitsVsMissingHits.Draw("colz")

cRA2.cd(4)
setStyle(h_Isol, 1, 1, "particle-based relIso", "#events", "relIso distribution")
h_Isol.Draw()


## cRA2.cd(6)
## h_cmgdxyVspatdxy.SetMarkerSize(22)
## h_cmgdxyVspatdxy.Draw()

cRA2.SaveAs('RA2'  + postfix + '.png')


#Save histos
histo.cd()
histo.Write()
#histo.Close()
