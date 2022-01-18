// Divide and add 1D Histograms
#include <TH1F.h>
#include <TRandom3.h>
#include <TCanvas.h>
#include <TStyle.h>
#include <TApplication.h>
void format_h(TH1F *h, int linecolor)
{
    h->SetLineWidth(3);
    h->SetLineColor(linecolor);
}
void macro6()
{
    auto sig_h=new TH1F("sig_h","Signal Histo", 50, 0, 10);
    auto gaus_h1=new TH1F("gaus_h1","Gauss Histo 1", 30, 0, 10);
    auto gaus_h2=new TH1F("gaus_h2","Gauss Histo 2", 30, 0, 10);
    auto bkg_h=new TH1F("exp_h","Exponential Histo", 50, 0, 10);
    // simulate the measurements
    TRandom3 rndgen;
    for (int imeas = 0; imeas < 4000; imeas++)
    {
        /* code */
        bkg_h->Fill(rndgen.Exp(4));
        if (imeas%4==0)
        {
            /* code */
            gaus_h1->Fill(rndgen.Gaus(5, 2));
        }
        if (imeas%4==0)
        {
            /* code */
            gaus_h2->Fill(rndgen.Gaus(5, 2));
        }
        if (imeas%10==0)
        {
            /* code */
            sig_h->Fill(rndgen.Gaus(5, .5));
        }
    }
    // Format Histograms
    int i=0;
    for (auto hist : {sig_h, bkg_h, gaus_h1, gaus_h2})
    {
        /* code */
        format_h(hist, 1+i++);
    }
    // Sum
    auto sum_h= new TH1F(*bkg_h);
    sum_h->Add(sig_h, 1.);
    sum_h->SetTitle("Exponential + Gaussian; X variable; Y variable");
    format_h(sum_h,kBlue);
    auto c_sum= new TCanvas();
    sum_h->Draw("hist");
    bkg_h->Draw("SameHist");
    sig_h->Draw("SameHist");
    // Divide
    auto dividend=new TH1F(*gaus_h1);
    dividend->Divide(gaus_h2);
    // Graphical Maquillage
    dividend->SetTitle("; X axis; Gaus Histo 1 / Gaus Histo 2");
    format_h(dividend, kOrange);
    gaus_h1->SetTitle("; ; Gaus Histo 1 and Gaus Histo 2");
    gStyle->SetOptStat(0);
    TCanvas* c_divide= new TCanvas();
    c_divide->Divide(1, 2, 0, 0);
    c_divide->cd(1);
    c_divide->GetPad(1)->SetRightMargin(.01);
    gaus_h1->DrawNormalized("Hist");
    gaus_h2->DrawNormalized("HistSame");
    c_divide->cd(2);
    dividend->GetYaxis()->SetRangeUser(0,2.49);
    c_divide->GetPad(2)->SetGridy();
    c_divide->GetPad(2)->SetRightMargin(.01);
    dividend->Draw();
}
void StandaloneApplication(int argc, char **argv)
{
    macro6();
}
int main(int argc, char **argv)
{
    TApplication app("ROOT Application", &argc, argv);
    StandaloneApplication(app.Argc(), app.Argv());
    app.Run();
    return 0;
}