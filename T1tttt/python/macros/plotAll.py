#plots all the histograms from a root file and save them as .png under $CMSSW_BASE/src/Lucie/T1tttt/plots/plots-today

##PYTHON / OS part
import os, sys
from datetime import date

from optparse import OptionParser

parser = OptionParser()
parser.usage = '''
python -i plotAll.py [root_file]
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
    ext  = args[1]

outputDirName  = '/'.join( [ os.environ['CMSSW_BASE'],
                'src/Lucie/T1tttt/plots/plots'+str(date.today())+ext ] )

if ( os.path.isdir( outputDirName ) == 0 ):
    os.mkdir( 
        outputDirName
        )

##ROOT
from ROOT import gROOT, TFile,  TLegend, gStyle, TCanvas, TGraphAsymmErrors, TMultiGraph

from CMGTools.RootTools.Style import *

gROOT.Macro( os.path.expanduser( '~/rootlogon.C' ) )
gStyle.SetOptStat("oumen")

print '''reading ''', file, ''', saving plots to ''', outputDirName

tFile = TFile( file )
tFile.ls()

for key in tFile.GetListOfKeys():
    name = key.GetName()
    c0 = TCanvas( name )
    c0.cd()
    if ( key.GetClassName() == 'TH2F' ) :
       tFile.Get( name ).Draw("colz")
    elif ( key.GetClassName() == 'TH2I' ) :
       tFile.Get( name ).Draw("colz,TEXT")
    elif ( key.GetClassName() == 'TTree' ) :
        for leaf in tFile.Get( name ).GetListOfLeaves():
            nameForFile = leaf.GetName()
            tFile.Get( name ).Draw( leaf.GetName() )
            c0.SaveAs( outputDirName + '/' + nameForFile + '.png' )
    else :
        tFile.Get( name ).Draw()
    c0.SaveAs( outputDirName + '/' + name + '.png' )
