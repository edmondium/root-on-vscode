#include <TAttLine.h>
#include <TMath.h>
#include <TStyle.h>
#include <TF1.h>
#include <TH1F.h>
#include <TFitResult.h>
#include <TLatex.h>
#include <TApplication.h>
#include <TMatrixDSym.h>
void format_line(TAttLine* line, int col, int sty)
{
    line->SetLineWidth(5);
    line->SetLineColor(col);
    line->SetLineStyle(sty);
}
double the_gausppar(double* vars, double* pars)
{
    return pars[0]*TMath::Gaus(vars[0], pars[1], pars[2])+
        pars[3]+pars[4]*vars[0]+pars[5]*vars[0]*vars[0];
}
void macro8()
{
    gStyle->SetOptTitle(0);
    gStyle->SetOptStat(0);
    gStyle->SetOptFit(1111);
    gStyle->SetStatBorderSize(0);
    gStyle->SetStatX(.89);
    gStyle->SetStatY(.89);
    TF1 parabola("parabola", "[0]+[1]*x+[2]*x**2", 0, 20);
    format_line(&parabola, kBlue, 2);
    TF1 gaussian("gaussian", "[0]*TMath::Gaus(x,[1],[2])", 0, 20);
    format_line(&gaussian, kRed, 2);
    TF1 gausppar("gausppar", the_gausppar, -0, 20, 6);
    double a=15;
    double b=-1.2;
    double c=.03;
    double norm=4;
    double mean=7;
    double sigma=1;
    gausppar.SetParameters(norm, mean, sigma, a, b, c);
    gausppar.SetParNames("Norm", "Mean", "Sigma", "a", "b", "c");
    format_line(&gausppar, kBlue, 1);
    TH1F histo("histo", "Signal plus background; X vals; Y Vals", 50, 0, 20);
    histo.SetMarkerStyle(8);
    // Fake the data
    for (int i = 1; i <= 5000; ++i)
    {
        /* code */
        histo.Fill(gausppar.GetRandom());
    }
    // Reset the parameters before the fit and set
    // by eye a peak at 6 with an area of more or less 50
    gausppar.SetParameter(0, 50);
    gausppar.SetParameter(1, 6);
    int npar=gausppar.GetNpar();
    for (int ipar = 2; ipar < npar; ++ipar)
    {
        /* code */
        gausppar.SetParameter(ipar, 1);
    }
    // perform fit ...
    auto fitResPtr = histo.Fit(&gausppar, "S");
    // ... and retrieve fit results
    fitResPtr->Print(); // print fit results
    // get covariance Matrix and print it
    TMatrixDSym covMatrix(fitResPtr->GetCovarianceMatrix());
    covMatrix.Print();
    // Set the values of the gaussian and parabola
    for (int ipar = 0; ipar < 3; ipar++)
    {
        /* code */
        gaussian.SetParameter(ipar, gausppar.GetParameter(ipar));
        parabola.SetParameter(ipar, gausppar.GetParameter(ipar+3));
    }
    histo.GetYaxis()->SetRangeUser(0, 250);
    histo.DrawClone("PE");
    parabola.DrawClone("Same");
    gaussian.DrawClone("Same");
    TLatex latex(2, 220, "#splitline{Signal Peak over}{background}");
    latex.DrawClone("Same");
}
void StandaloneApplication(int argc, char **argv)
{
    macro8();
}
int main(int argc, char **argv)
{
    TApplication app("ROOT Application", &argc, argv);
    StandaloneApplication(app.Argc(), app.Argv());
    app.Run();
    return 0;
}