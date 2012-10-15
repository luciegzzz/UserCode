import os
from fnmatch import fnmatch
import copy

from ROOT import TFile, TH1F, TPaveText

from CMGTools.RootTools.DataMC.AnalysisDataMCPlot import AnalysisDataMC
from CMGTools.RootTools.fwlite.Weight import Weight
from CMGTools.RootTools.fwlite.Weight import printWeights
from CMGTools.RootTools.Style import *

class MyAnalysisDataMC( AnalysisDataMC ):

    keeper = {}
    HINDEX = 0

    def __init__(self, varName, directory, selComps, weights,
                 bins = None, xmin = None, xmax=None, cut = '',
                 weight='1',  treeName=None):
        '''Data/MC plotter adapted to the H->tau tau analysis.
        The plotter takes a collection of trees in input. The trees are found according
        to the dictionary of selected components selComps.
        The global weighting information for each component is read from the weights dictionary.
        The weight parameter is the name of an event weight variable that can be found in the tree.
        The default is "weight" (full event weight computed at python analysis stage),
        but you can build up the weight string you want before calling this constructor.
        To do an unweighted plot, choose weight="1" (the string, not the number).        
        '''
        if treeName is None:
            treeName = 'Analysis'
        self.treeName = treeName
        self.selComps = selComps
        self.varName = varName
        self.cut = cut
        self.eventWeight = weight
        self.bins = bins
        self.xmin = xmin
        self.xmax = xmax
                
        super(MyAnalysisDataMC, self).__init__(varName, directory, weights)

        self.legendBorders = 0.651, 0.463, 0.895, 0.892



    def _BuildHistogram(self, tree, comp, compName, varName, cut, layer ):
        '''Build one histogram, for a given component'''

        print 'filling', compName
        if not hasattr( comp, 'tree'):
            comp.tree = tree
                    
        histName = '_'.join( [compName, self.varName] )

        hist = None
        hist = TH1F( histName, '', self.bins, self.xmin, self.xmax )
        hist.Sumw2()
        weight = self.eventWeight
        if tree == None:
            raise ValueError('tree does not exist for component '+compName)
        var = varName
        tree.Project( histName, var, '{cut}'.format(cut=cut) )
        hist.SetStats(0)
        componentName = compName
        legendLine = compName
        self.AddHistogram( componentName, hist, layer, legendLine)
        self.Hist(componentName).realName = comp.realName
        self.Hist(componentName).stack = False


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
            
            self._BuildHistogram(tree, comp, compName, self.varName,
                                     self.cut, layer )     

        self._ApplyWeights()
        self._ApplyPrefs()


    def _InitPrefs(self):
        '''Definine preferences for each component'''
        self.histPref = {}
        self.histPref['T2tt*'] = {'style':sBlackSquares, 'layer':4}
        self.histPref['TTJets*'] = {'style':sBlue, 'layer':2} 
        self.histPref['QCD*'] = {'style':sRed, 'layer':1}
        self.histPref['WJets*'] = {'style':sYellow, 'layer':3}  
       

def filterComps(comps, filterString=None): 
    filteredComps = copy.copy(comps)
    if filterString:
        filters = filterString.split(';')
        filteredComps = {}
        for comp in comps.values():
            for filter in filters:
                pattern = re.compile( filter )
                if pattern.search( comp.name ):
                    filteredComps[comp.name] = comp 
    return filteredComps


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
    hist: histogram you want to plot
    '''
    parser.add_option("-H", "--hist", 
                      dest="hist", 
                      help="histogram list",
                      default='mt')
    parser.add_option("-C", "--cut", 
                      dest="cut", 
                      help="cut to apply in TTree::Draw",
                      default='')
    parser.add_option("-n", "--nbins", 
                      dest="nbins", 
                      help="Number of bins",
                      default=None)
    parser.add_option("-m", "--min", 
                      dest="xmin", 
                      help="xmin",
                      default=None)
    parser.add_option("-M", "--max", 
                      dest="xmax", 
                      help="xmax",
                      default=None)
    parser.add_option("-f", "--filter", 
                      dest="filter", 
                      help="Regexp filter to select components",
                      default=None)
  
    
    (options,args) = parser.parse_args()
    if len(args) != 2:
        parser.print_help()
        sys.exit(1)

    NBINS = int(options.nbins)
    XMIN = float(options.xmin)
    XMAX = float(options.xmax)

    cutstring = options.cut
    
    weight='weight'
    anaDir = args[0].rstrip('/')
        
    cfgFileName = args[1]
    file = open( cfgFileName, 'r' )
    cfg = imp.load_source( 'cfg', cfgFileName, file)


    selComps, weights = prepareComponents(anaDir, cfg.config)
    filteredComps = filterComps(selComps, options.filter)

    print options.hist
    #can, pad, padr = buildCanvas()
    plot = MyAnalysisDataMC( options.hist, anaDir, filteredComps, weights, NBINS, XMIN, XMAX, options.cut,
                       weight=weight )
    #plot.DrawStack('HIST')
    plot.Draw()
    gPad.SaveAs(options.hist + '.png')
