import os, re
from fnmatch import fnmatch
import copy

from ROOT import TFile, TH1F, TPaveText

from CMGTools.RootTools.DataMC.AnalysisDataMCPlot import AnalysisDataMC
from CMGTools.RootTools.fwlite.Weight import Weight
from CMGTools.RootTools.fwlite.Weight import printWeights
from CMGTools.RootTools.Style import *

from math import ceil

class SelectionHisto( object ):
    keeper = {}
    HINDEX = 0

    def __init__(self, varName, directory, selComps, weights, bkg,
                 cuts = [], treeName=None):
        if treeName is None:
            treeName = 'Analysis'
        self.treeName = treeName
        self.selComps = selComps
        self.cuts = cuts
        self.varName = varName
        self.bkg=bkg
        self.legendBorders = 0.651, 0.463, 0.895, 0.892
        self.Nevents = {}
        self._ReadHistograms(directory)

    def _BuildHistogram(self):
        self.outputHisto = TH2F("h_"+varName, varName+", "+self.cuts, 80, 0., 800., 80, 0., 800. )
        self.outputHisto.SetXTitle("stop mass")
        self.outputHisto.SetYTitle("LSP mass")
        self.outputHisto.SetStats(0)
        
        for (compName, compNameDico) in self.Nevents.iteritems():
            if not (compName in self.bkg):
                self.outputHisto.Fill( compNameDico["stopMass"], \
                                       compNameDico["LSPMass"], \
                                       self._ComputeVar(compNameDico, self.Nevents[self.bkg[0]]))
        return self.outputHisto

    def _ReadHistograms(self, directory):
        '''Build histograms for all components.'''
        for layer, (compName, comp) in enumerate( sorted(self.selComps.iteritems()) ) :
            fileName = '/'.join([ directory,
                                  comp.dir,
                                  self.treeName,
                                  '{treeName}_tree.root'.format(treeName=self.treeName)] )

            file = self.__class__.keeper[ fileName + str(self.__class__.HINDEX) ] = TFile(fileName) 
            self.__class__.HINDEX+=1

            tree = file.Get( self.treeName )

            stopMass, LSPMass = self._GetMassPoint(tree)
            Nevents, NeventsSelected = self._CalculateEventYield(tree)
            self.Nevents[compName] = {"Nevents":Nevents,
                                      "NeventsSelected": NeventsSelected,
                                      "weight":(comp.getWeight()).GetWeight(),
                                      "stopMass":stopMass,
                                      "LSPMass":LSPMass}
            file.Close()   

        self._BuildHistogram()

    #calculate number of events selected by the full list of cuts given in option,
    #returns this number of events selected and the total number of events
    def _CalculateEventYield(self, tree ):
        
        Nevents         = tree.GetEntries()
        selection = ""
        for cut in re.split(",", self.cuts):
            selection+= cut + " && "
        selection = selection.rstrip("&& ")
        NeventsSelected = tree.GetEntries(selection)
        
        return float(Nevents), float(NeventsSelected)

        
    def _GetMassPoint(self, tree ):
        '''Get mass point for T2tt components'''

        massPoint = ""
     
        histStop = None
        histStop = TH1F( "histStop", '', 200, 0., 1000.)
        stopMass = 0
        tree.Project( "histStop", "stopMass" )
        stopMass = ceil(histStop.GetMean())
        
        histLSP = None
        histLSP = TH1F( "histLSP", '', 200, 0., 1000.)
        LSPMass = 0
        tree.Project( "histLSP", "LSPMass" )
        LSPMass = ceil(histLSP.GetMean())
        
        return stopMass, LSPMass

    def _ComputeVar(self, sigDico, bkgDico):
        if self.varName == "SoB":
            return (sigDico["NeventsSelected"]*sigDico["weight"])/(bkgDico["NeventsSelected"]*bkgDico["weight"])
        elif self.varName == "efficiency":
            return sigDico["NeventsSelected"]/sigDico["Nevents"]
        elif self.varName =="approxSignificance":
            return  (sigDico["NeventsSelected"]*sigDico["weight"]) / (sigDico["NeventsSelected"]*sigDico["weight"] + bkgDico["NeventsSelected"]*bkgDico["weight"])
        elif self.varName == "Nexpected":
            print "Nevents expected for bkg :", bkgDico["NeventsSelected"]*bkgDico["weight"]
            return sigDico["NeventsSelected"]*sigDico["weight"] 

        
    def Draw(self, options=""):
        self.outputHisto.Draw(options)
        
if __name__ == '__main__':


    import copy
    import imp
    import re 
    from optparse import OptionParser
    from CMGTools.RootTools.RootInit import *
    from CMGTools.H2TauTau.proto.plotter.rootutils import buildCanvas, draw
    from Lucie.T1tttt.plotter.prepareComponents import prepareComponents

    parser = OptionParser()
    parser.usage = '''
    %prog <anaDir> <cfgFile>

    cfgFile: analysis configuration file, see CMGTools.H2TauTau.macros.MultiLoop
    anaDir: analysis directory containing all components, see CMGTools.H2TauTau.macros.MultiLoop.
    '''
    parser.add_option("-C", "--cuts", 
                      dest="cuts", 
                      help="cuts to apply in TTree::GetEntries",
                      default="")
     
    parser.add_option("-v", "--varName", 
                      dest="varName", 
                      help="varName : SoB for signal over background,\
                                      efficiency,\
                                      approxSnificance for S/sqrt(S+B),\
                                      Nexpected for number of events expected(signal -> histo, bkg -> printout)",
                      default='SoB')
     
  ##   parser.add_option("-b", "--bkg", 
##                       dest="bkg", 
##                       help="bkg : background component ....",
##                       default='QCDHT1000Inf')
     
    (options,args) = parser.parse_args()
    if len(args) != 2:
        parser.print_help()
        sys.exit(1)

   
    cuts    = options.cuts
    varName = options.varName
   ## bkg     = options.bkg
    bkg = ["QCDHT1000Inf"]
    anaDir  = args[0].rstrip('/')
        
    cfgFileName = args[1]
    file = open( cfgFileName, 'r' )

    cfg = imp.load_source( 'cfg', cfgFileName, file)


    selComps, weights = prepareComponents(anaDir, cfg.config)
    plot = SelectionHisto( varName, anaDir, selComps,weights,bkg, cuts )

    c1 = TCanvas("c1")
    plot.Draw("colz")
    c1.SaveAs( varName+'.png')
