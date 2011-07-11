

def fillHistoCutsPassed(histos, nrPassed, cuts, collection, index, bin) :

    cut = 1
    while (cut < len( histos ) ):
        if (collection[index].getSelection(cuts[cut])):
            histos[cut].Fill(bin)
            nrPassed[cut] += 1
        cut +=1

