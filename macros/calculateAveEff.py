import FWCore.ParameterSet.Config as cms
import cPickle as pickle
import math, pprint
from array import array

def calculateAveEff(cuts, ratios, errRatios, nrEv, file) :

    c = 0
    cuts_eff = []
    for cut in cuts :
        averageEff = ratios[c] / nrEv
        error      = math.sqrt((errRatios[c]/nrEv - averageEff * averageEff)/nrEv)
        cut_eff = {str(cut) : [averageEff,  error]}
        cuts_eff.append( cut_eff )
        
        c+=1

    pickle.dump(cuts_eff, file)

def calculateAveEffMultiCuts(ratios, errRatios, nrEv, file) :

   
    cuts_eff = []
    for cut, ratiosByCuts  in ratios.iteritems()  :
       ##  pprint.pprint(cut)
##         pprint.pprint(ratiosByCuts)
##         pprint.pprint(errRatios[cut][0])
        c = 0
        averageEff =  array('d', (0.,)*len(ratiosByCuts))
        error      =  array('d', (0.,)*len(ratiosByCuts))
        nbCuts =  len(ratiosByCuts)
        while (c < nbCuts) :
            averageEff[c] = ratiosByCuts[c] / nrEv
            error[c]      = math.sqrt(((errRatios[cut])[c]/nrEv - averageEff[c] * averageEff[c])/nrEv)
            c+=1
        cut_eff = {str(cut) : [averageEff,  error]}
        cuts_eff.append( cut_eff )
            

   # pprint.pprint(cuts_eff)
    pickle.dump(cuts_eff, file)


def calculateAveEffPU(cuts, ratios, errRatios, nrEv, file) :

    pu_cuts_eff = []
    pu = 0
    while pu < len(ratios) :
        c = 0
        for cut in cuts :
            averageEff = ratios[pu][c] / nrEv
            error      = math.sqrt(errRatios[pu][c]/nrEv - averageEff * averageEff)
            cut_eff = {str(cut) : [averageEff,  error]}
            pu_cut_eff = {str(pu) : cut_eff}
            pu_cuts_eff.append( pu_cut_eff )
        
            c+=1
        pu += 1
        
    pickle.dump(pu_cuts_eff, file)
