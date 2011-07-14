import FWCore.ParameterSet.Config as cms
import cPickle as pickle


def calculateAveEff(cuts, ratios, nrEv, file) :

    c = 0
    cuts_eff = []
    for cut in cuts :
        averageEff = ratios[c] / nrEv

        cut_eff = {str(cut) : averageEff}
        cuts_eff.append( cut_eff )
        
        c+=1

    pickle.dump(cuts_eff, file)
