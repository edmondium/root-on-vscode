import ROOT
from array import array
arrBins = array('d' ,(1 ,4 ,9 ,16) ) # array of bin edges
histo = ROOT.TH1F("hist", "hist", len(arrBins)-1, arrBins)
# fill it with equally spaced numbers
for i in range (1 ,16) :
    histo.Fill(i)
histo.Draw ()