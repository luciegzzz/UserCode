import os, re, pdb
from fnmatch import fnmatch
import copy

from ROOT import TFile, TH1F, TPaveText

from CMGTools.RootTools.DataMC.AnalysisDataMCPlot import AnalysisDataMC
from CMGTools.RootTools.fwlite.Weight import Weight
from CMGTools.RootTools.fwlite.Weight import printWeights
from CMGTools.RootTools.Style import *

from math import ceil, sqrt

#me
from Lucie.ThirdGeneration.AnalysisMVA import AnalysisMVA


class SensitivityWithMVA( object ):
    keeper = {}
    HINDEX = 0

    def __init__(self, varName, directory, selComps, weights, AnalysisMvaWeights, bkg,
                 cuts = [], treeName=None):
        if treeName is None:
            treeName = 'Analysis'
        self.treeName      = treeName
        self.selComps      = selComps
        self.cuts          = cuts
        self.varName       = varName
        self.AnalysisMva   = AnalysisMVA (AnalysisMvaWeights)
        self.bkg=bkg
        self.legendBorders = 0.651, 0.463, 0.895, 0.892
        self.Nevents = {}
        self._ReadHistograms(directory)

    def _BuildHistogram(self):
        self.outputHisto = TH2F("h_"+varName, varName+", "+str(self.cuts), 80, 0., 800., 80, 0., 800. )
        self.outputHisto.SetXTitle("stop mass")
        self.outputHisto.SetYTitle("LSP mass")
        self.outputHisto.SetStats(0)

        printBkgYields = True
        for (compName, compNameDico) in self.Nevents.iteritems():
            if not (compName in self.bkg):
                self.outputHisto.Fill( float(compNameDico["stopMass"]), \
                                       float(compNameDico["LSPMass"]), \
                                       self._ComputeVar(compName, printBkgYields))
                printBkgYields = False
                
        return self.outputHisto

    def _ReadHistograms(self, directory):
        '''Build histograms for all components.'''
        for layer, (compName, comp) in enumerate( sorted(self.selComps.iteritems()) ) :
            filename = os.listdir('/'.join([ directory,
                                             comp.dir,
                                             self.treeName
                                             ] ))
            fileName = '/'.join([ directory,
                                  comp.dir,
                                  self.treeName,
                                  filename[0]])
            print 'reading', fileName
            file = self.__class__.keeper[ fileName + str(self.__class__.HINDEX) ] = TFile(fileName) 
            self.__class__.HINDEX+=1

            tree = file.Get( self.treeName )

            if not (compName in self.bkg):
                stopMass, LSPMass = self._GetMassPoint(filename=filename[0])
            else :
                stopMass, LSPMass = 0,0
           
            Nevents, NeventsSelected = self._CalculateEventYield(tree)
                     
            self.Nevents[compName] = {"Nevents"        : Nevents,
                                      "NeventsSelected": NeventsSelected,
                                      "weight"         : (comp.getWeight()).GetWeight(),
                                      "stopMass"       : stopMass,
                                      "LSPMass"        : LSPMass}
            file.Close()   
        #after reading all components, build histograms
        self._BuildHistogram()

    #calculate number of events selected by the full list of cuts given in option,
    #returns this number of events selected and the total number of events
    def _CalculateEventYield(self, tree ):

        Nevents         = tree.GetEntries()
        NeventsSelected = 0
        
        for ev in tree :
            mvaBDT = self.AnalysisMva.analysisMvaCalc.val(
                ev.jetMultiplicity_30,
                ev.numberOfBTags_csv_tight,
                ev.numberOfTopCandidates_topCandidatesCa0p71p75,
                ev.deltaPhiMETHighPtTopCandtopCandidatesCa0p71p75,
                ev.minDeltaPhiMETJets
                )
            if (mvaBDT > 0.7) :
                NeventsSelected+=1
           
        return float(Nevents), float(NeventsSelected)

    # get T2tt mass point... Could get it from filename  
    def _GetMassPoint(self, tree=None ):
        '''Get mass point for T2tt components from tree leaves'''

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
    
    def _GetMassPoint(self, filename=None ):
        '''Get mass point for T2tt components from filename'''

        massPoint = ""
        stopMass, LSPMass = re.findall("[0-9]+",filename)
       
        return stopMass, LSPMass
        

    def _ComputeVar(self, sigCompName ,printBkgYields):
        NeventsBkg = 0
        #signal over background
        if self.varName == "SoB":
            for bkgName in self.bkg :
                NeventsBkg+=self.Nevents[bkgName]["NeventsSelected"]*self.Nevents[bkgName]["weight"]
            return (self.Nevents[sigCompName]["NeventsSelected"]*self.Nevents[sigCompName]["weight"])/(NeventsBkg+0.00001)
        #efficiency : % of events selected
        elif self.varName == "efficiency":
            if printBkgYields :
                for bkgName in self.bkg :
                    print self.Nevents[bkgName]["NeventsSelected"]/self.Nevents[bkgName]["Nevents"]
            return self.Nevents[sigCompName]["NeventsSelected"]/self.Nevents[sigCompName]["Nevents"]
        #Approx significance S/sqrt(S+B)     
        elif self.varName =="approxSignificance":
            for bkgName in self.bkg :
                NeventsBkg+=self.Nevents[bkgName]["NeventsSelected"]*self.Nevents[bkgName]["weight"]
            NeventsSig = self.Nevents[sigCompName]["NeventsSelected"]*self.Nevents[sigCompName]["weight"]
            return  NeventsSig / sqrt( NeventsSig + NeventsBkg)
        #number of expected events
        elif self.varName == "Nexpected":
            if printBkgYields :
                for bkgName in self.bkg :
                    print bkgName, self.Nevents[bkgName]["NeventsSelected"]*self.Nevents[bkgName]["weight"]
            return self.Nevents[sigCompName]["NeventsSelected"]*self.Nevents[sigCompName]["weight"] 

        
    def Draw(self, options=""):
        self.outputHisto.Draw(options)
        
if __name__ == '__main__':


    import copy
    import imp
    import re 
    from optparse import OptionParser
    from CMGTools.RootTools.RootInit import *
    from CMGTools.H2TauTau.proto.plotter.rootutils import buildCanvas, draw
    from Lucie.ThirdGeneration.plotter.prepareComponents import prepareComponents

    parser = OptionParser()
    parser.usage = '''
    %prog <anaDir> <cfgFile>

    cfgFile: analysis configuration file, see CMGTools.H2TauTau.macros.MultiLoop
    anaDir: analysis directory containing all components, see CMGTools.H2TauTau.macros.MultiLoop.
    '''

    parser.add_option("-w", "--mvaWeights", 
                      dest="AnalysisMvaWeights", 
                      help="mva weights file",
                      default='/afs/cern.ch/work/l/lucieg/private/Nov9/CMGTools/CMSSW_5_3_3_patch3/src/Lucie/ThirdGeneration/tmva/analysis/weights/TMVAClassificationAnalysis_Nov12_BDT.weights.xml')
   
    parser.add_option("-v", "--varName", 
                      dest="varName", 
                      help="varName : SoB for signal over background,\
                                      efficiency,\
                                      approxSignificance for S/sqrt(S+B),\
                                      Nexpected for number of events expected(signal -> histo, bkg -> printout)",
                      default='SoB')
    
    parser.add_option("-e", "--ext", 
                      dest="ext", 
                      help="extension for filename : varName+ext+.png",
                      default='')

    (options,args) = parser.parse_args()
    if len(args) != 2:
        parser.print_help()
        sys.exit(1)

   
    varName = options.varName
    ext     = options.ext
   ## bkg     = options.bkg
    bkg = ["QCDHT100To250", "QCDHT250To500", "QCDHT500To1000","QCDHT1000Inf","TTJets"]
    anaDir  = args[0].rstrip('/')
       
    cfgFileName = args[1]
    file = open( cfgFileName, 'r' )

    cfg = imp.load_source( 'cfg', cfgFileName, file)

    AnalysisMvaWeights = options.AnalysisMvaWeights
    selComps, weights = prepareComponents(anaDir, cfg.config)
    plot = SensitivityWithMVA( varName, anaDir, selComps,weights, AnalysisMvaWeights,bkg )

    c1 = TCanvas("c1")
    plot.Draw("colz")
    c1.SaveAs( varName+ext+'.png')
