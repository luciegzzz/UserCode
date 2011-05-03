README - METsWithPU/METsAnalyzer

//------------------------//
//----------plugins-------//
//------------------------//
-------------------
|    ANALYZERS    |
-------------------
METsAnalyzer
* initial met analyzer. Obsolete
* vertices study (distributions)
* met distributions vs o#pile-up, sumEt....

JetAnalyzer
* open up the jets to look to charged hadrons constituents, where they come from (PV or PU)
* fill a tree with (hopefully) usefule variables
* also recompute met
* could/should be used to recompute MET BEFORE testing cuts

METsTreeAnalyzer
* to be used to study pfMetNoPileUp and pfMetPileUp after cut.

PileUpAnalyzer
....not sure that's really useful. Could be mixed with Jet or METsTree. The idea is to have something to study the different components (charged, neutrals, had...) -moved to ~/trash

-------------------
|     PRODUCERS   |
-------------------
PFPileUpJets
* produce a collection of jets identified as pile-up jets. 
* to do so, open up the jets and look at charged constituents, where they come from...
* stems from JetAnalyzer

//------------------------//
//-------python-----------//
//------------------------//

vertices modules 
* good vertices producers/filters : !isFake && ndof > 4 && abs(z) <= 24 && position.Rho <= 2 (might need to be revised at some point)
* could merge goodVerticesDA_cff.py and goodVertices_cff.py

config files to drive the analyzers
* jetanalyzer
* metsanalyzer (obsolete)
* mettreeanalyzer
  Inputs : - vertices
           - 3 met types (e.g. std met, metNoPileUp, metPileUp)
  

producers
* neutral jet removal :
neutralJetFilter
pfNoNeutralJetCand_cff/cfi


*met producers (could be gathered into a single metProducers_cff/i ?)
pfMET_cfi.py : removes sig calculation. Similar to the "official" prod otherwise
pfMetFancy_cff.py : produces met from non neutral jets pfCand
pfMetNoPileUpDA : produces pfNoPileUp collection with DA vertices, then the pfMetNoPileUp. Obsolete ?
pfMetPileUp_cff : produces pfMet from pfPileUpJetsCand ...

* pile-up jets removal
pfNoNeutralJetsCand_cff/i
pfNeutralJetsCand_cff/i


