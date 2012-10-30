import os, re
from fnmatch import fnmatch
import copy

from ROOT import TFile, TH1F, TPaveText

from CMGTools.RootTools.DataMC.AnalysisDataMCPlot import AnalysisDataMC
from CMGTools.RootTools.fwlite.Weight import Weight
from CMGTools.RootTools.fwlite.Weight import printWeights
from CMGTools.RootTools.Style import *

from math import ceil

class Selection( object ):
    keeper = {}
    HINDEX = 0

    def __init__(self, varName, directory, selComps, weights, bkg,
                 cuts = [], treeName=None):
        if treeName is None:
            treeName = 'Analysis'
        self.treeName                    = treeName
        self.selComps                    = selComps
        self.initialCuts                 = cuts[:]
        self.cuts                        = cuts
        self.varName                     = varName
        self.bkg                         = bkg
        self.Nevents                     = {}
        self.mostDiscriminatingVarHistos = {}
        self.rankedCuts                  = []
        self._ReadHistogramsAndRankVariables(directory)
 
    def _ReadHistogramsAndRankVariables(self, directory):
        '''Read histograms for all components.'''

        while len(self.cuts) > 1:
            self.mostDiscriminatingVarHistos["mostDiscriminatingVarIn"+str(len(self.cuts))] =\
                 TH2F("h_mostDiscriminatingVarIn"+str(len(self.cuts)), "most discriminating variable(s) in "+str(len(self.cuts)) , 80, 0., 800., 80, 0., 800. )
            self.mostDiscriminatingVarHistos["mostDiscriminatingVarIn"+str(len(self.cuts))].SetXTitle("stop mass")
            self.mostDiscriminatingVarHistos["mostDiscriminatingVarIn"+str(len(self.cuts))].SetYTitle("LSP mass")
            self.mostDiscriminatingVarHistos["mostDiscriminatingVarIn"+str(len(self.cuts))].SetStats(0)
            self.mostDiscriminatingVarHistos["mostDiscriminatingVarIn"+str(len(self.cuts))].SetMaximum(len(self.initialCuts))
      
            print '----------------------------------------------------------------------------------------------------------'
            print len(self.cuts)," cuts in the list", self.cuts
            print '----------------------------------------------------------------------------------------------------------'
            for layer, (compName, comp) in enumerate( sorted(self.selComps.iteritems()) ) :
                fileName = '/'.join([ directory,
                                      comp.dir,
                                      self.treeName,
                                      '{treeName}_tree.root'.format(treeName=self.treeName)] )

                file = self.__class__.keeper[ fileName + str(self.__class__.HINDEX) ] = TFile(fileName) 
                self.__class__.HINDEX+=1

                tree = file.Get( self.treeName )

                stopMass, LSPMass        = self._GetMassPoint(tree)
                NeventsSelected, Nevents = self._CalculateEventYields(tree)
                self.Nevents[compName] = {"Nevents":Nevents,
                                          "NeventsSelected" : NeventsSelected,
                                          "weight":(comp.getWeight()).GetWeight(),
                                          "stopMass":stopMass,
                                          "LSPMass":LSPMass}
                file.Close()
                
            self._FindMostDiscriminatingVarOverMassPlane()
            #reinitialize for next iteration
            self.Nevents[compName]["NeventsSelected"]={} 

        #printouts
        print '----------------------------------------------------------------------------------------------------------'
        print '''The initial set of cuts is :'''
        print '----------------------------------------------------------------------------------------------------------'
        i= 0
        for cut in self.initialCuts :
            i+=1
            print i, cut
        self.rankedCuts.append(self.cuts[0])
        print '----------------------------------------------------------------------------------------------------------'
        print "ranked cuts by decreasing order of dsicriminating power"
        print '----------------------------------------------------------------------------------------------------------'
        for cut in self.rankedCuts :
            print cut
        print

    #calculate number of events selected applying the list of cuts given in option,
    #plus the  number of events selected applying the list of cuts given in option - 1,
    #returns the numbers of events selected for each sublist of cuts
    #(dico[sel]=nevents) and the total number of events
    def _CalculateEventYields(self, tree ):

        #all events in tree
        Nevents         = tree.GetEntries()
        #dictionary : number of events selected for each set of cuts (selection)
        NeventsSelected = {}
        for i in range(-1, len(self.cuts)):
            selection = ""
            for j in range(0, len(self.cuts)):
                if not (i==j):
                    selection+= self.cuts[j] + " && "
            selection = selection.rstrip("&& ")
            NeventsSelected[selection] = float(tree.GetEntries(selection))
        
        return NeventsSelected, Nevents

    # return the most discriminating variable :
    #Compute the var for a given component, for all sets of cuts = selection
    #(via computeVar, which returns a dictionary of results, whose keys are selection) ->
    #the most discriminating variable is the one for which var is the smallest
    def _FindMostDiscriminatingVar(self, compName):

        result = self._ComputeVar(self.Nevents[compName], self.Nevents[self.bkg[0]])
        minRes = 100000.
        minSel = ""
        for selection, res in result.iteritems():
            if len(re.split("&&",selection)) == len(self.cuts):
                fullSelection = selection
            else:
                minResTmp = minRes
                minRes = min( minRes, res )
                if not(minRes == minResTmp) :
                   minSel = selection

        return list(set(re.split("&&",fullSelection))- set(re.split("&&",minSel)))[0]

    #Fill mass plane histo with most discriminating variable index
    #remove from the list of cuts the most frequent of most discriminating variables
    def _FindMostDiscriminatingVarOverMassPlane(self):

        for (compName, compNameDico) in self.Nevents.iteritems():
            if not (compName in self.bkg):
                varName = self._FindMostDiscriminatingVar(compName)
                varName = re.sub(" ","",varName)
                i_varName = (self.initialCuts).index(varName)
                self.mostDiscriminatingVarHistos["mostDiscriminatingVarIn"+str(len(self.cuts))].Fill( self.Nevents[compName]["stopMass"], \
                                                                                                      self.Nevents[compName]["LSPMass"], \
                                                                                                      i_varName+1 )
                    
        self.cuts.remove(varName)
        self.rankedCuts.append(varName)       
        

    def _ComputeVar(self, sigDico, bkgDico):
        result = {}
        for selection, neventsSelectedS in (sigDico["NeventsSelected"]).iteritems():
            if self.varName == "SoB":
                result[selection]= ( neventsSelectedS*sigDico["weight"] ) / ( bkgDico["NeventsSelected"][selection] * bkgDico["weight"] )
            elif self.varName == "efficiency":
                result[selection] = neventsSelectedS / sigDico["Nevents"]
            elif self.varName =="approxSignificance":
                result[selection] = ( neventsSelectedS*sigDico["weight"] )  / ( neventsSelectedS*sigDico["weight"] + bkgDico["NeventsSelected"][selection] * bkgDico["weight"])
            elif self.varName == "Nexpected":
                #print "Nevents expected for bkg :", selection, bkgDico["NeventsSelected"][selection]*bkgDico["weight"]
                result[selection] =  neventsSelectedS*sigDico["weight"]
        return result 
       
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

        
    def Draw(self, can, options=""):
        i = 1
        for key, histo in sorted(self.mostDiscriminatingVarHistos.iteritems(), reverse=True):
            can.cd(i)
            histo.Draw(options)
            i+=1
        
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

    example :
    python -i ../python/plotter/Selection.py ANAOct26 analysis_cfg.py -C "jetMultiplicity_30>4","numberOfBTags_csv_tight>0","numberOfTopCandidates_topCandidatesCa0p71p75>0","minDeltaPhiMETJets>0.3","deltaPhiMETHighPtTopCandtopCandidatesCa0p71p75>0.5" -v approxSignificance
    '''
    parser.add_option("-C", "--cuts", 
                      dest="cuts", 
                      help="cuts to apply in TTree::GetEntries. No whitespace please :). I don't understand that.",
                      default="")
     
    parser.add_option("-v", "--varName", 
                      dest="varName", 
                      help="varName : SoB for signal over background,\
                                      efficiency,\
                                      approxSignificance for S/sqrt(S+B),\
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

   
    #cuts    = options.cuts
    cuts = re.split(",", options.cuts)
    varName = options.varName
   ## bkg     = options.bkg
    bkg = ["QCDHT1000Inf"]
    anaDir  = args[0].rstrip('/')
        
    cfgFileName = args[1]
    file = open( cfgFileName, 'r' )

    cfg = imp.load_source( 'cfg', cfgFileName, file)


    selComps, weights = prepareComponents(anaDir, cfg.config)

    plot = Selection( varName, anaDir, selComps,weights,bkg, cuts )

    c1 = TCanvas("c1")
    c1.Divide(2,2)
    plot.Draw(c1,"colz")
    c1.SaveAs( varName+'.png')
