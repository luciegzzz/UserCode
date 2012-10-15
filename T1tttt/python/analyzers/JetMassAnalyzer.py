import operator, pickle
from CMGTools.RootTools.fwlite.Analyzer import Analyzer
#from CMGTools.RootTools.analyzers.GenParticleAnalyzer import GenParticleAnalyzer
from Lucie.T1tttt.analyzers.TopTupleReader import TopTupleReader
from CMGTools.RootTools.statistics.Counter import Counter, Counters
from CMGTools.RootTools.fwlite.AutoHandle import AutoHandle
from CMGTools.RootTools.utils.DeltaR import *
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
        self.histosJetsMass          = {}
        self.hdRjetGenTops           = {}
        self.hmassDiff               = {}
        self.hmass                   = {}
        self.hptDiff                 = {}
        self.hmassDiffdRcut          = {}
        self.hptDiffdRcut            = {}
        self.hdRjetGenTopsVsmassDiff = {}
        self.hdRjetGenTopsVsptDiff   = {}
        self.hmassDiffVsptDiff       = {}
        self.hmassMatchedToGenTops   = {}
        
        for jetAlgo in self.listOfJetCollections :
            self.histosJetsMass[jetAlgo]          =  TH1F ( "jetMass_"  +jetAlgo        , "jetMass_"+jetAlgo     , 100, 0.   , 500.) 
            self.hdRjetGenTops[jetAlgo]           =  TH1F ( "dRGenTops_"+jetAlgo        , "dRGenTops_"+jetAlgo   , 100, 0.   , 10. )
            self.hmassDiff[jetAlgo]               =  TH1F ( "massDiff_" +jetAlgo        , "massDiff_" +jetAlgo   , 100, -250., 250.)
            self.hmassMatchedToGenTops[jetAlgo]   =  TH1F ( "massMatchedToGenTops_"+jetAlgo , "massMatchedToGenTops_" +jetAlgo   , 100, 0., 500.)
            self.hptDiff[jetAlgo]                 =  TH1F ( "ptDiff_"   +jetAlgo        , "ptDiff_"   +jetAlgo   , 100, -250., 250.)
            self.hptDiffdRcut[jetAlgo]            =  TH1F ( "ptDiffdRcut_"   +jetAlgo        , "ptDiffdRcut_"   +jetAlgo   , 100, -250., 250.)
            self.hmassDiffdRcut[jetAlgo]          =  TH1F ( "massDiffdRcut_" +jetAlgo        , "massDiffdRcut_" +jetAlgo   , 100, -250., 250.)
         
            self.hdRjetGenTopsVsmassDiff[jetAlgo] =  TH2F ( "dRGenTopsVsmassDiff_"+jetAlgo , "dRGenTopsVsmassDiff_"+jetAlgo , 100, -250., 250., 100, 0.   , 10. )
            self.hdRjetGenTopsVsptDiff[jetAlgo]   =  TH2F ( "dRGenTopsVsptDiff_"+jetAlgo   , "dRGenTopsVsptDiff_"+jetAlgo   , 100, -250., 250., 100, 0.   , 10. )
            self.hmassDiffVsptDiff[jetAlgo]       =  TH2F ( "massDiffVsptDiff"+jetAlgo     , "massDiffVsptDiff_"+jetAlgo    , 100, -250., 250., 100, -250., 250.)
          
        self.textFile = open ('/'.join ([self.dirName, 'fitParameters.txt']),
                                 'w')     
    
    def process(self, iEvent, event):
        ###inherits from mom
        super(JetMassAnalyzer,self).process(iEvent, event)

        ###and extend.
        #grab reclusteredJets
        event.jetsAlgos = {}
        for jetAlgo in self.listOfJetCollections :
            event.jetsAlgos[jetAlgo] = self.buildTopJets( self.mchandles[jetAlgo].product(), event )
            #and play
            for jet in event.jetsAlgos[jetAlgo] :
                self.histosJetsMass[jetAlgo].Fill( jet.mass() )
                #is there a gen top consistent with this jet ?
                for gen in event.genParticles :
                    if (abs(gen.pdgId())==6):
                        # are they closeby ?
                        dRjetGenTops = deltaR(gen.eta(), gen.phi(), jet.eta(), jet.phi())
                        # are they close in mass ?
                        massDiff = jet.mass() - gen.mass()
                        # are they close in pt ?
                        ptDiff   = jet.pt() - gen.pt()

                        self.hdRjetGenTops[jetAlgo].Fill(dRjetGenTops)
                        self.hmassDiff[jetAlgo].Fill(massDiff)
                        self.hptDiff[jetAlgo].Fill(ptDiff)

                        self.hdRjetGenTopsVsmassDiff[jetAlgo].Fill(massDiff, dRjetGenTops)
                        self.hdRjetGenTopsVsptDiff[jetAlgo].Fill(ptDiff, dRjetGenTops)
                        self.hmassDiffVsptDiff[jetAlgo].Fill(ptDiff, massDiff)

                        if (dRjetGenTops < 0.3):
                            self.hmassDiffdRcut[jetAlgo].Fill(massDiff)
                            self.hptDiffdRcut[jetAlgo].Fill(ptDiff)
                            self.hmassMatchedToGenTops[jetAlgo].Fill(jet.mass())
                            
               
        return True
        
    def write(self): 
        print self.dirName
        self.file.cd
        for i, jetAlgo in enumerate(self.histosJetsMass) :
            self.histosJetsMass[jetAlgo].Write( self.histosJetsMass[jetAlgo].GetName() )
            self.hdRjetGenTops[jetAlgo].Write( self.hdRjetGenTops[jetAlgo].GetName() )
            self.hmassDiff[jetAlgo].Write( self.hmassDiff[jetAlgo].GetName() )
            self.hptDiff[jetAlgo].Write( self.hptDiff[jetAlgo].GetName() )
            self.hmassDiffdRcut[jetAlgo].Write( self.hmassDiffdRcut[jetAlgo].GetName() )
            self.hptDiffdRcut[jetAlgo].Write( self.hptDiffdRcut[jetAlgo].GetName() )

            self.hdRjetGenTopsVsmassDiff[jetAlgo].Write( self.hdRjetGenTopsVsmassDiff[jetAlgo].GetName() )
            self.hdRjetGenTopsVsptDiff[jetAlgo].Write( self.hdRjetGenTopsVsptDiff[jetAlgo].GetName() )
            self.hmassDiffVsptDiff[jetAlgo].Write( self.hmassDiffVsptDiff[jetAlgo].GetName() )
            self.hmassMatchedToGenTops[jetAlgo].Write( self.hmassMatchedToGenTops[jetAlgo].GetName() )
            
    def endLoop(self):
        super(JetMassAnalyzer,self).endLoop()

        ##fitting
        r  = array("d", self.jetCollections.values())
        er = array( "d", [0.] * len(r) )
        sigmas  = {}
        esigmas = {}
        means   = {}
        emeans  = {}
       
        for i, jetAlgo in enumerate( self.histosJetsMass )  :
          #  sigma, mean, errorSigma, errorMean = self.fitTopPeak( self.histosJetsMass[jetAlgo] )
            sigma, mean, errorSigma, errorMean = self.fitTopPeak( self.hmassMatchedToGenTops[jetAlgo] )
            
            sigmas[jetAlgo]  = sigma
            esigmas[jetAlgo] = errorSigma
            means[jetAlgo]   = mean
            emeans[jetAlgo]  = errorMean
           
            fitParameters = {}
       
        for key in self.jetCollections.keys():
            fitParameters[key]=  self.jetCollections[key],sigmas[key], esigmas[key], means[key], emeans[key]
        pickle.dump( fitParameters, self.textFile)


    def fitTopPeak(self, histoToFit):
        g =  TF1("g", "gaus", self.minMass, self.maxMass)
       
        r = histoToFit.Fit("g","RS0")
        if  r.IsValid() :
            sigma = r.Parameter(2)
            mean  = r.Parameter(1)
            errorSigma = r.ParError(2)
            errorMean  = r.ParError(1)
            return sigma, mean, errorSigma, errorMean
           
        else :
            return 0., 0., 0., 0.
