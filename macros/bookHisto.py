import FWCore.ParameterSet.Config as cms
import ROOT

def bookHisto(cuts, bins, histos) :
    for cut in cuts :
        if (cut == ""):
            continue 
        else :
            histos.append(ROOT.TH1F(("h"+cut), "pt",len(bins)-1, bins))

