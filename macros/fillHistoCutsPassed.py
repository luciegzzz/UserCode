
def fillHistoPredefCutsPassed(histos, nrPassed, cuts, collection, index, bin) :

    cut = 1
    while (cut < len( histos ) ):
        if (collection[index].getSelection(cuts[cut])):
          histos[cut].Fill(bin)
          nrPassed[cut] += 1
        cut +=1

def fillHistoLowerThanCutsPassed(histos, nrPassed, cuts, var, bin) :
  
    cut = 0
    while (cut < len( cuts ) ):
        if ( var < cuts[cut] ):
            histos[cut].Fill(bin)
            nrPassed[cut] += 1
        cut += 1
  
