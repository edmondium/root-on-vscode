#include <TH1F.h>
#include <TFile.h>
#include <TCanvas.h>
void read_from_file()
{
    // Let's open the TFile
    TFile in_file("my_rootfile.root");
    // Get the Histogram out
    TH1F* h;
    in_file.GetObject("my_histogram",h);
    // Draw it
    auto myCanvas = new TCanvas();
    h->DrawClone();
}