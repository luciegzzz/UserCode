import FWCore.ParameterSet.Config as cms

from METsWithPU.METsAnalyzer.goodVertices_cff import *

goodVerticesDA     = goodVertices.clone()
goodVerticesDA.src = 'offlinePrimaryVerticesDA'


