// Create, Fill and draw an Histogram which reproduces the
// counts of a scaler linked to a Geiger counter.
#include <TH1F.h>
#include <TRandom3.h>
#include <TCanvas.h>
#include <iostream>
#include <TApplication.h>
using namespace std;
void macro5()
{
    auto cnt_r_h=new TH1F("count_rate", "Count Rate; N_{Counts}; # occurrence",
                100, // Number of Bins
                -0.5, // Lower X Boundary
                15.5); // Upper X Boundary
    auto mean_count=3.6f;
    TRandom3 rndgen;
    // simulate the measurements
    for (int imeas = 0; imeas < 400; imeas++)
    {
        /* code */
        cnt_r_h->Fill(rndgen.Poisson(mean_count));
    }
    auto c= new TCanvas();
    cnt_r_h->Draw();
    auto c_norm= new TCanvas();
    cnt_r_h->DrawNormalized();
    // Print summary
    cout << "Moments of Distribution:\n"
         << " - Mean     = " << cnt_r_h->GetMean() << " +- "
                             << cnt_r_h->GetMeanError() << "\n"
         << " - Std Dev  = " << cnt_r_h->GetStdDev() << " +- "
                             << cnt_r_h->GetStdDevError() << "\n"
         << " - Skewness = " << cnt_r_h->GetSkewness() << "\n"
         << " - Kurtosis = " << cnt_r_h->GetKurtosis() << "\n";
}
void StandaloneApplication(int argc, char **argv)
{
    macro5();
}
int main(int argc, char **argv)
{
    TApplication app("ROOT Application", &argc, argv);
    StandaloneApplication(app.Argc(), app.Argv());
    app.Run();
    return 0;
}