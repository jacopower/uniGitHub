// lab2

#include <iostream>
#include "TROOT.h"
#include "TStyle.h"
#include "TF1.h"
#include "TCanvas.h"
#include "TMath.h"




void myMacro(Int_t n)       // n=1 sottosmorzato ; n=2 smorzamento critico ; n=3 sovrasmorsato
{
    gROOT->SetStyle("Plain");
    gStyle->SetPalette(57);
    gStyle->SetOptFit(111);

    TF1 *R1func = new TF1("R1func", "[0] * TMath::Exp(-[1] * x) * cos([2] * x + [3]) + [4]", 0., 1.);     // sottosmorzato
        R1func->SetLineColor(kRed);
        R1func->SetLineWidth(1);
        R1func->SetParameters(0.5, 13168., 79865., -1., 0.);
    TF1 *L1func = new TF1("L1func", "[0] * TMath::Exp(-[1] * x) * cos([2] * x + [3]) + [4]", 0., 1.);
        L1func->SetLineColor(kRed);
        L1func->SetLineWidth(1);
        L1func->SetParameters(-2, 13168., 79865., -2., 0.);
    TF1 *C1func = new TF1("C1func", "[0] * TMath::Exp(-[1] * x) * cos([2] * x + [3]) + [4]", 0., 1.);
        C1func->SetLineColor(kRed);
        C1func->SetLineWidth(1);
        C1func->SetParameters(-1.9, 13168., 79865., 0., 2);

    TF1 *R2func = new TF1("R2func", "([0] * x + [1]) * TMath::Exp([2] * x) + [3]", 0., 1.);     // smorzamento critico
        R2func->SetLineColor(kRed);
        R2func->SetLineWidth(1);
        R2func->SetParameters(2., 0.5, -80000., 0.);
    TF1 *L2func = new TF1("L2func", "([0] * x + [1]) * TMath::Exp([2] * x) + [3]", 0., 1.);
        L2func->SetLineColor(kRed);
        L2func->SetLineWidth(1);
        L2func->SetParameters(2., 0.5, -80000., 0.);
    TF1 *C2func = new TF1("C2func", "([0] * x - [1]) * TMath::Exp([2] * x) + [1]", 0., 1.);
        C2func->SetLineColor(kRed);
        C2func->SetLineWidth(1);
        C2func->SetParameters(2., 0.5, -80000.);

    TF1 *R3func = new TF1("R3func", "[0] * TMath::Exp([1] * x) + [2] * TMath::Exp([3] * x) + [4]", 0., 1.);     // sovrasmorzato
        R3func->SetLineColor(kRed);
        R3func->SetLineWidth(1);
        R3func->SetParameters(1.7, -300000., 0.28, -40., 0.);
    TF1 *L3func = new TF1("L3func", "[0] * TMath::Exp([1] * x) + [2] * TMath::Exp([3] * x) + [4]", 0., 1.);
        L3func->SetLineColor(kRed);
        L3func->SetLineWidth(1);
        L3func->SetParameters(2., -300000., 1., -22000., 0);
//    TF1 *C3func = new TF1("C3func", "([0] * (TMath::Exp([1] * x) - 1)) + ([2] * (TMath::Exp([3] * x)) - 1)", 0., 1.);
    TF1 *C3func = new TF1("C3func", "[0] * TMath::Exp([1] * x) + [2] * TMath::Exp([3] * x) + [4]", 0., 1.);
        C3func->SetLineColor(kRed);
        C3func->SetLineWidth(1);
        C3func->SetParameters(1., -300000., 1., -22000., 2.);


    if(n==1) {                                  // fit and draw
        TGraphErrors *R1graph = new TGraphErrors("R1data.txt", "%lg %lg %lg");      // graphing the data
            R1graph->SetTitle("V_R; Tempo (s); Tensione (V)");
            R1graph->GetXaxis()->SetTitleOffset(1.3);
            R1graph->SetMarkerStyle(kFullCircle);
            R1graph->SetMarkerColor(kBlue);  
            R1graph->SetMarkerSize(0.5);
        TCanvas *Rcanvas = new TCanvas("Rcanvas");
            R1graph->Draw("APE");
            R1graph->Fit("R1func");             // fitting
            R1func->Draw("SAME");
        Rcanvas->Print("R1canvas.pdf");         // saves canvas as .pdf
        Rcanvas->Print("R1canvas.png");         // saves canvas as .png

        TGraphErrors *L1graph = new TGraphErrors("L1data.txt", "%lg %lg %lg");
            L1graph->SetTitle("V_L; Tempo (s); Tensione (V)");
            L1graph->GetXaxis()->SetTitleOffset(1.3);
            L1graph->SetMarkerStyle(kFullCircle);
            L1graph->SetMarkerColor(kBlue);  
            L1graph->SetMarkerSize(0.5);
        TCanvas *Lcanvas = new TCanvas("Lcanvas");
            L1graph->Draw("APE");
            L1graph->Fit("L1func");
            L1func->Draw("SAME");
        Lcanvas->Print("L1canvas.pdf");
        Lcanvas->Print("L1canvas.png");

        TGraphErrors *C1graph = new TGraphErrors("C1data.txt", "%lg %lg %lg");
            C1graph->SetTitle("V_C; Tempo (s); Tensione (V)");
            C1graph->GetXaxis()->SetTitleOffset(1.3);
            C1graph->SetMarkerStyle(kFullCircle);
            C1graph->SetMarkerColor(kBlue);  
            C1graph->SetMarkerSize(0.5);
        TCanvas *Ccanvas = new TCanvas("Ccanvas");
            C1graph->Draw("APE");
            C1graph->Fit("C1func");
            C1func->Draw("SAME");
        Ccanvas->Print("C1canvas.pdf");
        Ccanvas->Print("C1canvas.png");

    } 
    else if(n==2) {
        TGraphErrors *R2graph = new TGraphErrors("R2data.txt", "%lg %lg %lg");
            R2graph->SetTitle("V_R; Tempo (s); Tensione (V)");
            R2graph->GetXaxis()->SetTitleOffset(1.3);
            R2graph->SetMarkerStyle(kFullCircle);
            R2graph->SetMarkerColor(kBlue);  
            R2graph->SetMarkerSize(0.5);
        TCanvas *Rcanvas = new TCanvas("Rcanvas");
            R2graph->Draw("APE");
            R2graph->Fit("R2func");
            R2func->Draw("SAME");
        Rcanvas->Print("R2canvas.pdf");
        Rcanvas->Print("R2canvas.png");

        TGraphErrors *L2graph = new TGraphErrors("L2data.txt", "%lg %lg %lg");
            L2graph->SetTitle("V_L; Tempo (s); Tensione (V)");
            L2graph->GetXaxis()->SetTitleOffset(1.3);
            L2graph->SetMarkerStyle(kFullCircle);
            L2graph->SetMarkerColor(kBlue);  
            L2graph->SetMarkerSize(0.5);
        TCanvas *Lcanvas = new TCanvas("Lcanvas");
            L2graph->Draw("APE");
            L2graph->Fit("L2func");
            L2func->Draw("SAME");
        Lcanvas->Print("L2canvas.pdf");
        Lcanvas->Print("L2canvas.png");

        TGraphErrors *C2graph = new TGraphErrors("C2data.txt", "%lg %lg %lg");
            C2graph->SetTitle("V_C; Tempo (s); Tensione (V)");
            C2graph->GetXaxis()->SetTitleOffset(1.3);
            C2graph->SetMarkerStyle(kFullCircle);
            C2graph->SetMarkerColor(kBlue);  
            C2graph->SetMarkerSize(0.5);
        TCanvas *Ccanvas = new TCanvas("Ccanvas");
            C2graph->Draw("APE");
            C2graph->Fit("C2func");
            C2func->Draw("SAME");
        Ccanvas->Print("C2canvas.pdf");
        Ccanvas->Print("C2canvas.png");

    } 
    else if(n==3) {
        TGraphErrors *R3graph = new TGraphErrors("R3data.txt", "%lg %lg %lg");
            R3graph->SetTitle("V_R; Tempo (s); Tensione (V)");
            R3graph->GetXaxis()->SetTitleOffset(1.3);
            R3graph->SetMarkerStyle(kFullCircle);
            R3graph->SetMarkerColor(kBlue);  
            R3graph->SetMarkerSize(0.5);
        TCanvas *Rcanvas = new TCanvas("Rcanvas");
            R3graph->Draw("APE");
            R3graph->Fit("R3func");
            R3func->Draw("SAME");
        Rcanvas->Print("R3canvas.pdf");
        Rcanvas->Print("R3canvas.png");

        TGraphErrors *L3graph = new TGraphErrors("L3data.txt", "%lg %lg %lg");
            L3graph->SetTitle("V_L; Tempo (s); Tensione (V)");
            L3graph->GetXaxis()->SetTitleOffset(1.3);
            L3graph->SetMarkerStyle(kFullCircle);
            L3graph->SetMarkerColor(kBlue);  
            L3graph->SetMarkerSize(0.5);
        TCanvas *Lcanvas = new TCanvas("Lcanvas");
            L3graph->Draw("APE");
            L3graph->Fit("L3func");
            L3func->Draw("SAME");
        Lcanvas->Print("L3canvas.pdf");
        Lcanvas->Print("L3canvas.png");

        TGraphErrors *C3graph = new TGraphErrors("C3data.txt", "%lg %lg %lg");
            C3graph->SetTitle("V_C; Tempo (s); Tensione (V)");
            C3graph->GetXaxis()->SetTitleOffset(1.3);
            C3graph->SetMarkerStyle(kFullCircle);
            C3graph->SetMarkerColor(kBlue);  
            C3graph->SetMarkerSize(0.5);
        TCanvas *Ccanvas = new TCanvas("Ccanvas");
            C3graph->Draw("APE");
            C3graph->Fit("C3func");
            C3func->Draw("SAME");
        Ccanvas->Print("C3canvas.pdf");
        Ccanvas->Print("C3canvas.png");

    }

}
