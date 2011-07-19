#! /usr/bin/env python

import ROOT, sys, os, pdb
from DataFormats.FWLite import Events, Handle
from aux import *
from array import array
from makeEffPlots import makeEffPlots
from bookHisto import bookHisto
from styles import setStyle
from calculateAveEff import calculateAveEff
from fillHistoCutsPassed import *
#from RA2cuts import RA2CutsEles
from options import *

ROOT.gStyle.SetPalette(1)

####################
#------inputs------#
####################

#path = '/data/lucieg/RelValZEE425/'
path  = '/data/lucieg/WJetsToLNu_TuneZ2_7TeV_madgraph_tauola/'
#path = '/data/lucieg/QCD_Pt-30to80_BCtoE_TuneZ2_7TeV-pythia6/'
#postfix            = 'QCDbce'
postfix            = 'Wjets'
maxEvents          = 500000
pdgId              = 11 #for electrons
numberOfPileUpInt  = 0 # select number of pile-up ( extend to range ?)
effFileName        = 'efficiencies' + postfix
effFileRA2IsolName = 'RA2Isol' + postfix
variable           = 'pt' # trying to make the macro generic enough to easily switch from pt to eta
dRMatching         = 0.15
dPtRelMatching     = 0.5
histoFileName      = 'histo'+postfix+'.root'

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
handleCmgMuons      = Handle ('std::vector<cmg::Muon>')
handleVertices      = Handle ('std::vector<reco::Vertex>')
handlePileUp        = Handle ('std::vector<PileupSummaryInfo>')

cmgElectrons        = ("cmgElectronSel")
cmgMuons            = ("cmgMuonSel")
genLeptons          = ("genEAndMuStatus1")
vertices            = ("offlinePrimaryVertices")
pileup              = ("addPileupInfo")


##########################################
#------outputs & related quantities------#
##########################################
#output files
effFile = open(effFileName,'w')

histo   = ROOT.TFile(histoFileName, "RECREATE")

#********************#
#*****matching*******#
#********************#
h_dR                 = ROOT.TH1F("h_dR", "dR", 1000, 0., 10.)
h_dPtRel             = ROOT.TH1F("h_dPtRel", "(pt(reco)-pt(gen))/pt(gen), for reco ele closest to gen", 100, 0., 1.)
h_dPtRelMatched      = ROOT.TH1F("h_dPtRelMatched", "(pt(reco)-pt(gen))/pt(gen), for reco ele matched(dR < 0.15) to gen", 100, 0., 1.)
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
cuts                   = cutsVBTFID

histosToCompare        = [genLeptonXMatched]
bookHisto(cuts,binsLowEdges, histosToCompare )

########################################
#-----------loop over events-----------#
########################################

ratioEleSel   = array('d', (0.,)*len(cuts)) 
errRatioEleSel   = array('d', (0.,)*len(cuts)) 
nrEvWithGenLeptons = 0

i = 0 # event counter
for event in events:
    i = i + 1
    if (i > maxEvents) :
        break

    #for overall efficiencies (2D plots)
    nrGenLeptons     = 0.
    nrEleSel         = array('d', (0.,)*len(cuts))  # for a given event, eff = nrEleSel / nrGenLeptons
  
    #get objects
    event.getByLabel (genLeptons, handleGenLeptons)
    event.getByLabel (cmgElectrons, handleCmgElectrons)
    event.getByLabel (cmgMuons, handleCmgMuons)
    event.getByLabel (vertices, handleVertices)
    event.getByLabel (pileup, handlePileUp)
    
    cmgEles  = handleCmgElectrons.product()
    cmgMus   = handleCmgMuons.product()
    genLeps  = handleGenLeptons.product()
    vtces    = handleVertices.product()
    puvtces  = handlePileUp.product()
    
    #pile-up info
    nrOfVtces      = vtces.size()
    nrOfPUvertices = puvtces[1].getPU_NumInteractions() # 0 = BC -1, 1 = BC, 2 = BC +1

   ##  if (nrOfPUvertices != numberOfPileUpInt) :
##         continue
          
    for genLepton in genLeps :

        if ((abs(genLepton.pdgId()) != pdgId or abs(genLepton.eta()) > 2.5 or (abs(genLepton.eta()) > 1.44 and abs(genLepton.eta()) < 1.57) or genLepton.pt() < 5.)):
            continue
        
        elif ((pdgId == 13) and (abs(genLepton.pdgId()) != pdgId or abs(genLepton.eta()) > 2.5  or genLepton.pt() < 5.)):
            continue
        
        else :
            nrGenLeptons += 1
            genVar = genLepton.pt()
            genLeptonX.Fill(genVar) #need to find an elegant way to switch easily from pt, to eta to anything

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

       
            ############ what passed what #########
            if (matched(dRmin, dPt, diffCharge, dRMatching, dPtRelMatching)):#ele seems to be reco'ed :)
                nrEleSel[0]   += 1
                genLeptonXMatched.Fill(genLepton.pt()) 
         
                fillHistoPredefCutsPassed(histosToCompare[nrOfPUvertices], nrEleSel[nrOfPUvertices], cuts, cmgEles, index, genLepton.pt())
                           
               
    if (nrGenLeptons[nrOfPUvertices] > 0) :
        nrEvWithGenLeptons[nrOfPUvertices] += 1
        cut = 0
        while (cut  < len(cuts)) :
            ratioEleSel[nrOfPUvertices][cut]   += nrEleSel[nrOfPUvertices][cut] / nrGenLeptons[nrOfPUvertices]
            errRatioEleSel[nrOfPUvertices][cut]     += ((nrEleSel[nrOfPUvertices][cut] / nrGenLeptons[nrOfPUvertices]) * (nrEleSel[nrOfPUvertices][cut] / nrGenLeptons[nrOfPUvertices]))
            cut += 1

calculateAveEffPU(cuts, ratioEleSel, errRatioEleSel, nrEvWithGenLeptons, effFile)

#######################################           
#---------plots-----------------------#
#######################################

#-------efficiencies------------------#
genLeptonX.Sumw2()

genLeptonXMatched.Sumw2()
genLeptonXMatched.Divide(genLeptonX)

cEfficiencies = ROOT.TCanvas("efficiencies")

cEfficiencies.cd()
leg1   = ROOT.TLegend(0.6,0.1,0.9,0.5)
makeEffPlots(histosToCompare, genLeptonX, cuts, "pt(GeV)", "efficiency (#matched/total)", "reconstruction efficiency vs pt, vbtfID", leg1 )

cEfficiencies.SaveAs("effPlots.png")

#-------matching------------------#
cMatching  = ROOT.TCanvas("matching")
cMatching.Divide(2,2)

cMatching.cd(1)
setStyle(h_dR)
h_dR.Draw()

cMatching.cd(2)
setStyle(h_dPtRel)
h_dPtRel.Draw()
setStyle(h_dPtRelMatched,2)
h_dPtRelMatched.Draw("SAME")

cMatching.cd(3)
setStyle(h_diffCharge)
h_diffCharge.Draw()
setStyle(h_diffChargeMatched)
h_diffChargeMatched.Draw("SAME")

cMatching.SaveAs("matching.png")

#Save histos
histo.cd()
histo.Write()
#histo.Close()
