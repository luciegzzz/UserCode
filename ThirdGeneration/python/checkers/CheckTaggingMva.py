#stl
import os, re, pdb
from fnmatch import fnmatch
import copy
from math import ceil, sqrt

#ROOT
from ROOT import TFile, TH1F, TPaveText, TPad

#CMGTools
from CMGTools.RootTools.DataMC.AnalysisDataMCPlot import AnalysisDataMC
from CMGTools.RootTools.fwlite.Weight import Weight
from CMGTools.RootTools.fwlite.Weight import printWeights
from CMGTools.RootTools.Style import *

#me
from Lucie.ThirdGeneration.TopTaggingMVA import TopTaggingMVA

class CheckTopTaggingMva( AnalysisDataMC ):
    keeper = {}
    HINDEX = 0

    def __init__(self, varName, directory, selComps, weights, TopTaggingMvaWeights, bkg,
                 treeName=None):
        if treeName is None:
            treeName = 'FatJetsTreeAnalyzer'
        self.treeName        = treeName
        self.tree            = None
        self.histos          = []
        self.selComps        = selComps
        self.legendBorders   = 0.651, 0.463, 0.895, 0.892
        self.TopTaggingMva   =  TopTaggingMVA (TopTaggingMvaWeights)
        self.outputFile      = TFile("output.root", "RECREATE")
        super(CheckTopTaggingMva, self).__init__(varName, directory, weights)
        
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

            self.tree = file.Get( self.treeName )
           
            self._BuildHistograms( compName, layer )
            self._Write()
            #file.Close()   

        self._ApplyPrefs()
  

    def _BuildHistograms(self, compName, layer):
        h_BDT = TH1F("h_BDT_"+compName, "BDToutput "+compName, 100, -1., 1. )
        h_BDT.SetXTitle("BDT output")
        h_BDT.SetStats(0)

        h_BDT_matched = TH1F("h_BDT_matched_"+compName, "BDToutput, matched fat jets", 100, -1., 1. )
        h_BDT_matched.SetXTitle("BDT output")
        h_BDT_matched.SetStats(0)

        h_BDT_notMatched = TH1F("h_BDT_notMatched_"+compName, "BDToutput, notMatched fat jets", 100, -1., 1. )
        h_BDT_notMatched.SetXTitle("BDT output")
        h_BDT_notMatched.SetStats(0)

        h_mass_tagged = TH1F("h_mass_tagged_"+compName, "mass, tagged fat jets : mva > 0.", 100, 0., 500. )
        h_mass_tagged.SetXTitle("mass")
        h_mass_tagged.SetStats(0)

        h_mass_notTagged = TH1F("h_mass_notTagged_"+compName, "mass, notTagged fat jets  : mva < 0.", 100, 0., 500. )
        h_mass_notTagged.SetXTitle("mass")
        h_mass_notTagged.SetStats(0)

        h_ROC = TH2F("h_ROC_"+compName,"ROC : %fakes vs %'real' tops, varying mva by 0.1, "+compName, 100, 0., 1., 100, 0., 1.)
        h_ROC.SetXTitle("% real tops")
        h_ROC.SetYTitle("% fakes")

        tr = self.tree
        nFakes = [0.]*20
        nTrue  = [0.]*20
        nTotMatched    = 0
        nTotNotMatched = 0
        
        for ev in tr :
            mvaBDT = self.TopTaggingMva.topTaggingMvaCalc.val(
                ev.pt,                        
                ev.eta,                       
                ev.mass,                       
                ev.radius,                       
                ev.sumPtOvernConst,                       
                ev.firstBtag_btag,                     
                ev.firstBtag_pt,
                ev.firstBtag_mass, 
                ev.secondBtag_btag,                     
                ev.secondBtag_pt,
                ev.secondBtag_mass
                )
            
            h_BDT.Fill(mvaBDT)
            
            for i in range(1,20):
                if mvaBDT > -1+0.1*i :
                    if ev.isMatched :
                        nTrue[i]+=1.
                    else :
                        nFakes[i]+=1.
            if ev.isMatched :
                nTotMatched+=1
            else :
                nTotNotMatched+=1
                
            if ev.isMatched :
                h_BDT_matched.Fill(mvaBDT)
            else :
                h_BDT_notMatched.Fill(mvaBDT)        

            if mvaBDT > 0. :
                h_mass_tagged.Fill(ev.mass)
            else :
                h_mass_notTagged.Fill(ev.mass)
            
        for i in range(1,20):
            nTrue[i] /=(nTotMatched+0.00001)
            nFakes[i]/=nTotNotMatched
            h_ROC.Fill(nTrue[i],nFakes[i])
        
        legendLine = compName
        self.AddHistogram(compName, h_BDT                            , layer, legendLine)
        self.AddHistogram(compName, h_ROC                            , layer, "-")
        self.AddHistogram(compName, h_BDT_matched                    , layer, "-")
        self.AddHistogram(compName, h_BDT_notMatched                 , layer, "-")
        self.AddHistogram(compName, h_mass_tagged                    , layer, "-")
        self.AddHistogram(compName, h_mass_notTagged                 , layer, "-")
        ## self.Hist(componentName).realName = compName
##         self.Hist(componentName).stack = False
   

    def _InitPrefs(self):
        '''Definine preferences for each component'''
        sBlack.fillStyle  = 0
        sBlue.fillStyle   = 0
        sRed.fillStyle    = 0
        sYellow.fillStyle = 0
        sYellow.lineColor = 5
        sViolet.fillStyle = 0
        sViolet.lineColor = kViolet
        sGreen.fillStyle  = 0
        
        self.histPref = {}
        self.histPref['*TTJets*']        = {'style':sViolet, 'layer':2}
        self.histPref['*QCDHT100To250*'] = {'style':sBlue,   'layer':1} 
        self.histPref['*QCDHT250To500*'] = {'style':sRed,    'layer':3}
        self.histPref['*QCDHT500To1000*']= {'style':sYellow, 'layer':4}
        self.histPref['*QCDHT1000Inf*']  = {'style':sGreen,  'layer':5}
        self.histPref['*T2tt*']          = {'style':sBlack,  'layer':0}
      
    def Draw(self, name, opt = ''):
        '''All histograms matching name are drawn.'''
        same = ''
        for hist in self._SortedHistograms():
            if  name +'_'+hist.name == hist.obj.GetName():
                hist.Draw( same + opt)
                if same == '':
                    same = 'same'
        self.DrawLegend()
        if TPad.Pad():
            TPad.Pad().Update()
        self.lastDraw = 'Draw'
        self.lastDrawArgs = [ opt ]
        

    def _Write(self):
        self.outputFile.cd()
        for histo in self.histos:
            histo.obj.Write()
  
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
                      dest="TopTaggingMvaWeights", 
                      help="mva weights file",
                      default="TMVAClassificationTagging_Nov15QCD1000Infasbkg_BDT.weights.xml")
     
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

    TopTaggingMvaWeights ='/'.join( [ os.environ['CMSSW_BASE'],
                                      'src/Lucie/ThirdGeneration/data/Tagging/weights/'+ options.TopTaggingMvaWeights] ) 
    selComps, weights = prepareComponents(anaDir, cfg.config)
    plot = CheckTopTaggingMva( "mva", anaDir, selComps,weights, TopTaggingMvaWeights, bkg )


    c1 = TCanvas("c1")
    plot.Draw("h_BDT")
    c1.SaveAs("BDToutput.png")
    c2 = TCanvas("c2")
    plot.Draw("h_BDT_matched")
    c2.SaveAs("BDT_matched.png")
    c3 = TCanvas("c3")
    plot.Draw("h_BDT_notMatched")
    c3.SaveAs("BDT_notMatched.png")
    c4 = TCanvas("c4")
    plot.Draw("h_mass_tagged")
    c4.SaveAs("mass_tagged.png")
    c5 = TCanvas("c5")
    plot.Draw("h_mass_notTagged")
    c5.SaveAs("mass_notTagged.png")
    c6 = TCanvas("c6")
    plot.Draw("h_ROC")
    c6.SaveAs("ROC.png")
