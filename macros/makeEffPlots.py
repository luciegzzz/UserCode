import FWCore.ParameterSet.Config as cms
import ROOT

from styles import *

def makeEffPlots(histos, denHisto, cuts, xTitle, yTitle, title, leg):

    cut = 0
    color = [1, 1, 4, 4, 3, 3, 28, 28, 7, 7]
    style = [1, 2, 1, 2, 1, 2, 1, 2, 1, 2]
    
    for histo in histos :

         if (cut == 0):
             setStyle(histo, color[cut], style[cut], xTitle, yTitle )
             histo.SetMaximum(1)
             histo.Draw()
             leg.AddEntry(histo, "no cut","l")
                 
         else :
             histo.Sumw2()
           #  denHisto.Sumw2()
             histo.Divide(denHisto)
             setStyle(histo, color[cut], style[cut])
             histo.Draw("SAME")
             leg.AddEntry(histo, cuts[cut],"l")
         cut += 1
         
    leg.Draw("SAME")
       
