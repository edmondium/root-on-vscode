// Reads the points from a file and produces a simple graph.
#include <TCanvas.h>
#include "TGraphErrors.h"
#include <TLegend.h>
#include <TApplication.h>
//int macro2()
void macro2()
{
    auto c=new TCanvas();
    c->SetGrid();
    TGraphErrors graph_expected("./macro2_input_expected.txt", "%lg %lg %lg");
    graph_expected.SetTitle(
       "Measurement XYZ and Expectation;"
       "length [cm];"
       "Arb.Units");
    graph_expected.SetFillColor(kYellow);
    graph_expected.DrawClone("E3AL"); // E3 draws the band
    TGraphErrors graph("./macro2_input.txt", "%lg %lg %lg");
    graph.SetMarkerStyle(kCircle);
    graph.SetFillColor(0);
    graph.DrawClone("PESame");
    // Draw the Legend
    TLegend leg(.1, .7, .3, .9, "Lab. Lesson 2");
    leg.SetFillColor(0);
    leg.AddEntry(&graph_expected, "Expected Points");
    leg.AddEntry(&graph, "Measured Points");
    leg.DrawClone("Same");
    graph.Print();
}
void StandaloneApplication(int argc, char **argv)
{
    macro2();
}
int main(int argc, char **argv)
{
    TApplication app("ROOT Application", &argc, argv);
    StandaloneApplication(app.Argc(), app.Argv());
    app.Run();
    return 0;
}