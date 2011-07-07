import FWCore.ParameterSet.Config as cms

def setStyle(histo, color, style = 1, xTitle = "", yTitle = "", title = ""):

    histo.SetLineWidth(3)
    histo.SetLineColor(color)
    histo.SetLineStyle(style)
    histo.SetXTitle(xTitle)
    histo.SetYTitle(yTitle)
    histo.SetTitle(title)
