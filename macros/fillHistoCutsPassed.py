
def fillHistoPredefCutsPassed(histos, nrPassed, cuts, collection, index, bin) :

    cut = 1
    while (cut < len( histos ) ):
        if (collection[index].getSelection(cuts[cut])):
          histos[cut].Fill(bin)
          nrPassed[cut] += 1
        cut +=1

def fillHistoPredefAndLTCutsPassed(histos, nrPassed, cuts, cutsLT, collection, index, bin, var) :

    c = 0
    for cut in cuts :
        if (cut == ""):
            continue
        c+=1
        if (collection[index].getSelection(cut)):
               histos[c].Fill(bin)
               cutLT = 0
               while (cutLT < len (cutsLT)):
                   if (var < cutsLT[cutLT]) :
                       (nrPassed[cut])[cutLT] += 1
                   cutLT +=1



def fillHistoLowerThanCutsPassed(histos, nrPassed, cuts, var, bin) :
  
    cut = 0
    while (cut < len( cuts ) ):
        if ( var < cuts[cut] ):
            histos[cut].Fill(bin)
            nrPassed[cut] += 1
        cut += 1
  
