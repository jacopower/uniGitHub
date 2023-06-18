// RLC_Fit

void setStyle(){
	gROOT->SetStyle("Plain");
	gStyle->SetOptStat(1111);
	gStyle->SetOptFit(111);
	gStyle->SetPalette(57);
 	gStyle->SetOptTitle(0);
}

void Fit(int n){
	gStyle->SetOptFit(111);
	TGraphErrors *graph = new TGraphErrors("datalab2_R.txt","%lg %lg %lg");
	/*TGraphErrors *graphL = new TGraphErrors("datalab2_L.txt","%lg %lg %lg");
	TGraphErrors *graphC = new TGraphErrors("datalab2_C.txt","%lg %lg %lg");*/
	graph->SetTitle("V_R;Tempo (s); Tensione (V)");
	graph->GetXaxis()->SetTitleOffset(1.3);
    	graph->SetMarkerStyle(kFullCircle);
    	graph->SetMarkerColor(kBlue);  
    	graph->SetMarkerSize(0.5);
	graph->Draw("APE");
	

	TF1 *f1 = new TF1("Sottosmorzato","[0]*exp(-[1]*x)*sin([2]*x+[3])",0.,10.);
	TF1 *f2 = new TF1("Smorzamento critico","([0]*x+[1])*exp(-[2]*x)",0.,10.);
	TF1 *f3 = new TF1("Sovrasmorzato","[0]*exp([1]*x)+[2]*exp([3]*x)",0.,10.);

	f1->SetParameter(0,0.5);
   	f1->SetParameter(1,13168);
   	f1->SetParameter(2,79865.);
   	f1->SetParameter(3,0.);

	f2->SetParameter(0,2.);
   	f2->SetParameter(1,0.5);
   	f2->SetParameter(2,10.);

	f3->SetParameter(0,2.);
   	f3->SetParameter(1,-364768.);
   	f3->SetParameter(2,1.);
   	f3->SetParameter(3,-17961.);


	if(n==1){
		graph->Fit(f1);
		f1->Draw("SAME");
	} else if(n==2){
		graph->Fit(f2);
		f2->Draw("SAME");
	} else{
		graph->Fit(f3);
		f3->Draw("SAME");
	}

}

