from ROOT import TFile, TTree, TChain
from CMGTools.RootTools.Chain import Chain
from CMGTools.H2TauTau.proto.plotter.embed import embedScaleFactor


def prepareComponents(dir, config):
    '''Selects all components in configuration file. computes the integrated lumi
    from data components, and set it on the MC components.
    '''
    # all components in your configuration object (cfg)
    selComps = dict( [ (comp.name, comp) for comp in config.components ])

    totIntLumi = 0
    newSelComps = {}
    
    # loop on all components
    for comp in selComps.values():
        comp.dir = comp.name
        comp.realName = comp.name
        newSelComps[comp.name] = comp

    # prepare weight dictionary, with all the components
    weights = dict( [ (comp.name,comp.getWeight()) \
                      for comp in newSelComps.values() ] )

    ## for comp in newSelComps.values() :
##         print comp.name,comp.getWeight()
    # attach the corresponding tree to each component
    def attachTree(comps):
        for comp in comps.values():
            fileName = '/'.join([ dir,
                                  comp.dir,
                                  'Analysis',
                                  'Analysis_tree.root'])
            tree = TChain('Analysis_tree.root')
            tree.Add(fileName)
            comp.tree = tree
    
    attachTree(newSelComps)


    return newSelComps, weights
    
