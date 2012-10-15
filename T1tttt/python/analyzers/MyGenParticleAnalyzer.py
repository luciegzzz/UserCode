import operator 
from CMGTools.RootTools.analyzers.GenParticleAnalyzer import GenParticleAnalyzer
from CMGTools.RootTools.statistics.Counter import Counter, Counters
from CMGTools.RootTools.fwlite.AutoHandle import AutoHandle
from CMGTools.RootTools.physicsobjects.PhysicsObjects import GenParticle, PhysicsObject, printOut
from CMGTools.RootTools.physicsobjects.genutils import *
from ROOT import TH1I, TFile

class MyGenParticleAnalyzer( GenParticleAnalyzer ):
    '''Base analyzer for GenParticle analysis.
    Puts the collection of GenParticles in the event, as event.genParticles.
    Prints the list if verbose is True in the configuration.'''
    
    def beginLoop(self):
        super(MyGenParticleAnalyzer,self).beginLoop()
        self.h_WdaugthersPdgId = TH1I("h_WdaugthersPdgId","h_WdaugthersPdgId",300,0,300)
        self.histos = [
            self.h_WdaugthersPdgId
            ]
        self.file = TFile ('/'.join ([self.dirName, 'output.root']),
                                 'recreate')     
     
    def buildGenParticles(self, cmgGenParticles, event):
        '''Creates python GenParticles from the di-leptons read from the disk.
        to be overloaded if needed.'''
        return map( GenParticle, cmgGenParticles )
    
        
    def process(self, iEvent, event):
        self.readCollections( iEvent )
        if not self.cfg_comp.isMC:
            return True
        
        event.genParticles = self.buildGenParticles( self.mchandles['genpart'].product(), event )

        for gen in event.genParticles :
            if ( abs(gen.pdgId())==1000006 ):
                print gen.mass()
            if ( abs(gen.pdgId())==1000022 ):
                print gen.mass()
            
            if ( (gen.numberOfMothers() > 0) and abs(gen.mother().pdgId()) == 24 and abs(gen.mother().mother().pdgId()) == 6):
                #print "I'm a W daughter, my pdgId is ", gen.pdgId(), " mom pdgId ", gen.mother().pdgId() 
                self.h_WdaugthersPdgId.Fill(abs(gen.pdgId()))
            if (gen.numberOfMothers() > 0) and abs(gen.mother().pdgId()) == 24 and abs(gen.pdgId()) > 4 :
                print gen.pdgId(), abs(gen.mother().mother().pdgId())
            
        if self.cfg_ana.verbose:
            print self.name
            print printOut(event.genParticles)
            
        
        return True

    def write(self):
        super(MyGenParticleAnalyzer, self).write()
        for histo in self.histos:
            histo.Write()

    def declareHandles(self):
        '''Reads genParticlesPruned.'''
        super(MyGenParticleAnalyzer, self).declareHandles()
        self.mchandles['genpart'] =  AutoHandle(
            'genParticlesPruned',
            'std::vector<reco::GenParticle>'
            )
    
