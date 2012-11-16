#stl
import os, re, pdb
from fnmatch import fnmatch
import copy
from math import ceil, sqrt

#ROOT
from ROOT import TFile, TH1F, TPaveText

#CMGTools
from CMGTools.RootTools.DataMC.AnalysisDataMCPlot import AnalysisDataMC
from CMGTools.RootTools.fwlite.Weight import Weight
from CMGTools.RootTools.fwlite.Weight import printWeights
from CMGTools.RootTools.Style import *

#me
from Lucie.ThirdGeneration.AnalysisMVA import AnalysisMVA

class CheckAnalysisMva( object ):
    '''draft for analysis mva checker'''
    keeper = {}
    HINDEX = 0

    def __init__(self, directory, selComps, weights, AnalysisMvaWeights, bkg,
                 treeName=None):
        if treeName is None:
            treeName = 'Analysis'
        self.treeName = treeName
        self.tree     = None
        self.outputHisto = None
        self.selComps = selComps
        self.legendBorders = 0.651, 0.463, 0.895, 0.892
        self.AnalysisMva   =  AnalysisMVA (AnalysisMvaWeights)
        self._ReadTrees(directory)

    def _BuildHistogram(self):
        self.outputHisto = TH1F("h_BDT", "BDToutput", 100, -1., 1. )
        self.outputHisto.SetXTitle("BDT output")
        self.outputHisto.SetStats(0)

        tr = self.tree
       
        for ev in tr :
            mvaBDT = self.AnalysisMva.analysisMvaCalc.val(
               ev.jetMultiplicity_30,
               ev.numberOfBTags_csv_tight,
               ev.numberOfTopCandidates_topCandidatesCa0p71p75,
               ev.deltaPhiMETHighPtTopCandtopCandidatesCa0p71p75,
               ev.minDeltaPhiMETJets
               )
            
            self.outputHisto.Fill(mvaBDT)
                
        return self.outputHisto

    def _ReadTrees(self, directory):
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

            self.tree = file.Get( self.treeName )
           
            self._BuildHistogram()
            #file.Close()   
       
              
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
     
    (options,args) = parser.parse_args()
    if len(args) != 2:
        parser.print_help()
        sys.exit(1)

   ## bkg     = options.bkg
    bkg = ["QCDHT100To250", "QCDHT250To500", "QCDHT500To1000","QCDHT1000Inf","TTJets"]
    anaDir  = args[0].rstrip('/')
       
    cfgFileName = args[1]
    file = open( cfgFileName, 'r' )

    cfg = imp.load_source( 'cfg', cfgFileName, file)

    AnalysisMvaWeights = options.AnalysisMvaWeights
    selComps, weights = prepareComponents(anaDir, cfg.config)
    plot = CheckAnalysisMva( anaDir, selComps,weights, AnalysisMvaWeights, bkg )


    c1 = TCanvas("c1")
    plot.Draw()
  

