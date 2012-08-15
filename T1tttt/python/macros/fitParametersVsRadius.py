##PYTHON / OS part
import os, sys, pickle, re
from datetime import date
from array import array
from optparse import OptionParser


parser = OptionParser()
parser.usage = '''
python -i fitParametersVsRadius.py [root_file]
'''

(options,args) = parser.parse_args()

file = None
ext  = ''
if len(args)>2:
    parser.print_help()
    print
    print 'Maximum 2 argument (a text file, an output dir ext)'
    sys.exit(1)
else :
    file = open( args[0], 'r' )
    ext  = args[1]

outputDirName  = '/'.join( [ os.environ['CMSSW_BASE'],
                'src/Lucie/T1tttt/plots/plots'+str(date.today())+ext ] )

if ( os.path.isdir( outputDirName ) == 0 ):
    os.mkdir( 
        outputDirName
        )

##ROOT
from ROOT import gROOT, TFile,  TLegend, gStyle, TCanvas, TGraphErrors, TMultiGraph
import ROOT
from CMGTools.RootTools.Style import *

gROOT.Macro( os.path.expanduser( '~/rootlogon.C' ) )
gStyle.SetOptStat("oumen")

print '''reading ''', file, ''', saving plots to ''', outputDirName

radiiakt   = array("d")
meanakt    = array("d")
emeanakt   = array("d")
sigmaakt   = array("d")
esigmaakt  = array("d")

radiikt   = array("d")
meankt    = array("d")
emeankt   = array("d")
sigmakt   = array("d")
esigmakt  = array("d")

radiica   = array("d")
meanca    = array("d")
emeanca   = array("d")
sigmaca   = array("d")
esigmaca  = array("d")


fitParameters = pickle.load( file )
for i,key in enumerate(fitParameters):
    if re.match('aktRecluster.',key):
        radiiakt.append(fitParameters[key][0])
        sigmaakt.append(fitParameters[key][1])
        esigmaakt.append(fitParameters[key][2])
        meanakt.append(fitParameters[key][3])
        emeanakt.append(fitParameters[key][4])
    elif re.match('ktRecluster.',key):
        radiikt.append(fitParameters[key][0])
        sigmakt.append(fitParameters[key][1])
        esigmakt.append(fitParameters[key][2])
        meankt.append(fitParameters[key][3])
        emeankt.append(fitParameters[key][4])
    elif re.match('caRecluster.',key):
        radiica.append(fitParameters[key][0])
        sigmaca.append(fitParameters[key][1])
        esigmaca.append(fitParameters[key][2])
        meanca.append(fitParameters[key][3])
        emeanca.append(fitParameters[key][4])
 
eradii = array("d",[0.]*len(radiiakt))

c_sigmaVsR = TCanvas("c_sigmaVsR")
sigmaVsRakt = TGraphErrors(len(radiiakt), radiiakt, sigmaakt, eradii, esigmaakt)
sigmaVsRakt.GetXaxis().SetTitle("radius")
sigmaVsRakt.GetYaxis().SetTitle("sigma of gaussian fit to top peak")
sigmaVsRakt.SetMaximum(20.)
sigmaVsRakt.SetMinimum(10.)
sigmaVsRakt.SetMarkerStyle(22)
sigmaVsRakt.SetMarkerColor(kBlue)

sigmaVsRkt = TGraphErrors(len(radiikt), radiikt, sigmakt, eradii, esigmakt)
sigmaVsRkt.SetMarkerStyle(21)
sigmaVsRkt.SetMarkerColor(kRed)

sigmaVsRca = TGraphErrors(len(radiica), radiica, sigmaca, eradii, esigmaca)
sigmaVsRca.SetMarkerStyle(31)
sigmaVsRca.SetMarkerColor(1)

allSigmaVsR = TMultiGraph("allSigmaVsR", "Sigma versus jet clustering radius")
allSigmaVsR.Add( sigmaVsRakt, "ap")
allSigmaVsR.Add( sigmaVsRkt, "p")
allSigmaVsR.Add( sigmaVsRca, "p")
allSigmaVsR.Draw()

leg = TLegend(0.6,0.1, 0.9, 0.3)
leg.SetShadowColor(0)
leg.AddEntry(sigmaVsRakt, "anti-kt","lpf")
leg.AddEntry(sigmaVsRkt, "kt","lpf")
leg.AddEntry(sigmaVsRca, "cambridge-aachen","lpf")

leg.Draw("SAMES")

c_sigmaVsR.SaveAs(outputDirName+"/sigmaVsRadius.png")


c_meanVsRakt = TCanvas("c_meanVsRakt")
meanVsRakt = TGraphErrors( len(radiiakt), radiiakt, meanakt, eradii, emeanakt )
meanVsRakt.GetXaxis().SetTitle("radius")
meanVsRakt.GetYaxis().SetTitle("mean of gaussian fit to top peak")
meanVsRakt.SetMaximum(185.)
meanVsRakt.SetMinimum(165.)
meanVsRakt.SetMarkerStyle(22)
meanVsRakt.SetMarkerColor(kBlue)

meanVsRkt = TGraphErrors( len(radiikt), radiikt, meankt, eradii, emeankt )
meanVsRkt.SetMarkerStyle(21)
meanVsRkt.SetMarkerColor(kRed)

meanVsRca = TGraphErrors( len(radiica), radiica, meanca, eradii, emeanca )
meanVsRca.SetMarkerStyle(31)
meanVsRca.SetMarkerColor(1)

allMeanVsR = TMultiGraph("allMeanVsR", "Mean versus jet clustering radius")
allMeanVsR.Add( meanVsRakt, "ap")
allMeanVsR.Add( meanVsRkt, "p")
allMeanVsR.Add( meanVsRca, "p")
allMeanVsR.Draw()

legMean = TLegend(0.6,0.1, 0.9, 0.3)
legMean.SetShadowColor(0)
legMean.AddEntry(meanVsRakt, "anti-kt","lpf")
legMean.AddEntry(meanVsRkt, "kt","lpf")
legMean.AddEntry(meanVsRca, "cambridge-aachen","lpf")

legMean.Draw("SAMES")

c_meanVsRakt.SaveAs(outputDirName+"/meanVsRadius.png")
