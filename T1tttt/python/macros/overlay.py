#plots all the histograms from a root file and save them as .png under $CMSSW_BASE/src/Lucie/T1tttt/plots/plots-today

##PYTHON / OS part
import os, sys, re
from datetime import date

from optparse import OptionParser

parser = OptionParser()
parser.usage = '''
python -i overlay.py [root_file] [histoName]
'''

(options,args) = parser.parse_args()

file = None
ext  = ''
if len(args)>2:
    parser.print_help()
    print
    print 'Maximum 2 argument (a root file, an output dir ext)'
    sys.exit(1)
elif len(args)==2:
    file = args[0]
    histoName = args[1]
outputDirName  = '/'.join( [ os.environ['CMSSW_BASE'],
                'src/Lucie/T1tttt/plots/plots'+str(date.today())+ext ] )

if ( os.path.isdir( outputDirName ) == 0 ):
    os.mkdir( 
        outputDirName
        )

##ROOT
from ROOT import gROOT, TFile,  TLegend, gStyle, TCanvas, kMagenta, kOrange, kCyan


from CMGTools.RootTools.Style import *

gROOT.Macro( os.path.expanduser( '~/rootlogon.C' ) )
gStyle.SetOptStat("oumen")

print '''reading ''', file, ''', saving plots to ''', outputDirName

tFile = TFile( file )
tFile.ls()
gStyle.SetOptStat(0)
c0 = TCanvas( histoName )
first = True
leg = TLegend(0.53,0.36,0.94,0.89)

styleSet.pop()
styleSet.pop()
styleSet.pop()
styleSet.pop()
sYellow.lineColor = sYellow.markerColor
styleSet.append(sYellow)
sViolet.lineColor = sViolet.markerColor
styleSet.append(sViolet)
sOrange = Style(fillStyle = 0, lineColor = kOrange, markerColor = kOrange)
styleSet.append(sOrange)
sCyan = Style(fillStyle = 0, lineColor = kCyan, markerColor = kCyan)
styleSet.append(sCyan)
sMagenta = Style(fillStyle = 0, lineColor = kMagenta, markerColor = kMagenta)
styleSet.append(sMagenta)

for style in styleSet :
    style.fillColor = 0
import CMGTools.RootTools.Style as Style


for key in tFile.GetListOfKeys():
    name = key.GetName()
    
    if re.match(histoName, name):
        if first :
            Style.nextStyle().formatHisto( tFile.Get( name ) )
            leg.AddEntry( tFile.Get( name ) )
            tFile.Get( name ).SetTitle(histoName)
            tFile.Get( name ).Draw()
            first = False
        else :
            Style.nextStyle().formatHisto( tFile.Get( name ) )
            tFile.Get( name ).Draw("SAMES")
            leg.AddEntry( tFile.Get( name ) )
    leg.Draw("SAMES")
c0.SaveAs( outputDirName + '/' + histoName + '.png' )
