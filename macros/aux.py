import FWCore.ParameterSet.Config as cms
from math import pi, sqrt

def deltaPhi(phi0, phi1):
    res = phi0 - phi1
    while (res > pi):
        res -= 2*pi
    while (res <= - pi ):
        res += 2*pi
    return res

def deltaR(phi0, eta0, phi1, eta1):
    dPhi = deltaPhi(phi0, phi1)
    dEta = eta0 - eta1
    dR   = sqrt(dPhi*dPhi + dEta*dEta)
    return dR

def deltaRmin(obj0, coll):
    dRmin = 9999.
    index = -1 # will remain = -1 if coll is empty
    dPt   = -1
    it = 0
    for obj1 in coll :
        dR = deltaR(obj0.phi(), obj0.eta(), obj1.phi(), obj1.eta())
        if dR < dRmin :
            dRmin = dR
            index = it
            dPt   = abs(obj0.pt() - obj1.pt()) / obj0.pt()
            it += 1
      
    if (dRmin == 9999.) :
        dRmin = -1.

    return dRmin, dPt, index


def matched(dRmin, dPt, dRmatched, dPtMatched):
    
    return (dRmin < dRmatched) and (dPt < dPtMatched)
