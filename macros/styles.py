import FWCore.ParameterSet.Config as cms

def setStyle(histo, color = 1, style = 1, xTitle = "", yTitle = "", title = ""):

    histo.SetLineWidth(2)
    histo.SetLineColor(color)
    histo.SetLineStyle(style)
    histo.SetXTitle(xTitle)
    histo.SetYTitle(yTitle)
    histo.SetTitle(title)

def setStyle2D(histo, markerStyle = 20, xTitle = "", yTitle = "", title = ""):

    histo.SetMarkerSize(1)
    histo.SetMarkerStyle(markerStyle)
    histo.SetXTitle(xTitle)
    histo.SetYTitle(yTitle)
    histo.SetTitle(title)

def canvasStyle(canvas):

    canvas.SetLogy()
    canvas.SetGridx()
    canvas.SetGridy()

