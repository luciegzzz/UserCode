import operator, pickle
from CMGTools.RootTools.fwlite.Analyzer import Analyzer
#from CMGTools.RootTools.analyzers.GenParticleAnalyzer import GenParticleAnalyzer
from Lucie.T1tttt.analyzers.TopTupleReader import TopTupleReader
from CMGTools.RootTools.statistics.Counter import Counter, Counters
from CMGTools.RootTools.fwlite.AutoHandle import AutoHandle
from CMGTools.RootTools.utils.DeltaR import deltaR
from Lucie.T1tttt.physicsobjects.PhysicsObjects import GenJet, Jet, RecoJet
from CMGTools.RootTools.physicsobjects.PileUpSummaryInfo import PileUpSummaryInfo
from ROOT import TH1F, TH2F, TH1I, TFile, TF1, TFitResultPtr, TGraphErrors
from math import sqrt
from array import array


class JetMassAnalyzer( TopTupleReader ):
    '''An analyzer that plots jet mass distribution for a list of jet collections, fit the top peak with a gaussian, plots sigma vs radius'''

    def __init__( self, cfg_ana, cfg_comp, looperName ):
        super(JetMassAnalyzer,self).__init__( cfg_ana, cfg_comp, looperName )
        self.minMass = cfg_ana.minMass
        self.maxMass = cfg_ana.maxMass
      
    def beginLoop(self):
        super(JetMassAnalyzer,self).beginLoop()
        self.histosJetsMass = {}
        for jetAlgo in self.listOfJetCollections :
            self.histosJetsMass[jetAlgo] =  TH1F ( jetAlgo , jetAlgo, 100, 0., 500.) 
       
        self.textFile = open ('/'.join ([self.dirName, 'fitParameters.txt']),
                                 'w')     
    
    def process(self, iEvent, event):
        ###inherits from mom
        super(JetMassAnalyzer,self).process(iEvent, event)

        ###and extend.
        #grab reclusteredJets
        event.jetsAlgos = {}
        for jetColl in self.listOfJetCollections :
            event.jetsAlgos[jetColl] = self.buildTopJets( self.mchandles[jetColl].product(), event )
            #and play
            for jet in event.jetsAlgos[jetColl] :
                self.histosJetsMass[jetColl].Fill( jet.mass() )
   
        return True
        
    def write(self): 
        print self.dirName
        self.file.cd
        for i, jetAlgo in enumerate(self.histosJetsMass) :
            self.histosJetsMass[jetAlgo].Write( self.histosJetsMass[jetAlgo].GetName() )

        ##self.sigmaVsR.Write()
        ##self.meanVsR.Write()
 
    def endLoop(self):
        super(JetMassAnalyzer,self).endLoop()

        ##fitting
        r = array("d", self.jetCollections.values())
        er = array( "d", [0.] * len(r) )
        sigmas  = {}
        esigmas = {}
        means   = {}
        emeans  = {}
       
        for i, jetAlgo in enumerate( self.histosJetsMass )  :
            sigma, mean, errorSigma, errorMean = self.fitTopPeak( self.histosJetsMass[jetAlgo] )
            
            sigmas[jetAlgo]  = sigma
            esigmas[jetAlgo] = errorSigma
            means[jetAlgo]   = mean
            emeans[jetAlgo]  = errorMean
           
            fitParameters = {}
       
        for key in self.jetCollections.keys():
            fitParameters[key]=  self.jetCollections[key],sigmas[key], esigmas[key], means[key], emeans[key]
            # pickle.dump(zip(self.jetCollections.keys(),r,sigmas.values(), esigmas.values(), means.values(), emeans.values()), self.textFile)
        pickle.dump( fitParameters, self.textFile)

        #should move to some fit parameters plotter. TGraph weirdly behave when saving
        ## self.sigmaVsR = TGraphErrors(len(self.jetCollections), r, array("d",sigmas.values()), er,  array("d",esigmas.values()) )
##         self.sigmaVsR.GetXaxis().SetTitle("radius")
##         self.sigmaVsR.GetYaxis().SetTitle("sigma of gaussian fit to top peak")        
##         self.sigmaVsR.Draw("AP")

##         self.meanVsR = TGraphErrors(len(self.jetCollections), r, array("d",means.values()), er,  array("d",emeans.values()) )
##         self.meanVsR.GetXaxis().SetTitle("radius")
##         self.meanVsR.GetYaxis().SetTitle("mean of gaussian fit to top peak")        
##         self.meanVsR.Draw("AP")


    def fitTopPeak(self, histoToFit):
        g =  TF1("g", "gaus", self.minMass, self.maxMass)
       
        r = histoToFit.Fit("g","RS")
        if  r.IsValid() :
            sigma = r.Parameter(2)
            mean  = r.Parameter(1)
            errorSigma = r.ParError(2)
            errorMean  = r.ParError(1)
            return sigma, mean, errorSigma, errorMean
           
        else :
            return 0., 0., 0., 0.
