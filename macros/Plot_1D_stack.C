#include <iostream>
#include <string>

#include <TFile.h>
#include <TTree.h>
#include <TBranch.h>
#include <TGraph.h>
#include <TMultiGraph.h>
#include <TAxis.h>
#include <TCanvas.h>
#include <TMath.h>
#include <TLegend.h>
#include <TLatex.h>
#include <TColor.h>
#include <TColorWheel.h>
#include <TH1D.h>
#include <TStyle.h>

#include "include/CompressedBase.hh"


using namespace std;

vector<string> g_File;
vector<string> g_Tree;
vector<int> g_Hist;
vector<string> g_Title;
vector<bool> g_Bkg;
double g_Lumi;
string g_PlotTitle;
string g_Xname;
double g_Xmin;
double g_Xmax;
double g_NX;

TColor *icolor[9][2];
int color_list[4][10];
int style_list[4][10];

void setstyle(int istyle);

void Plot_1D_stack(){
  setstyle(0);

  //g_PlotTitle = "Baseline Selection";
  g_PlotTitle = "p_{T S}^{ CM} > 600+R_{ISR} > 0.6+N_{b-tag}^{ V} #geq 1";
  g_Lumi = 10.;

  int ihist = 0;
   
  g_File.push_back("NTUPLES/BKG/Top.root");
  g_Tree.push_back("CompressedAnalysis");
  g_Hist.push_back(ihist);
  g_Title.push_back("Top + X");
  g_Bkg.push_back(true);
  ihist++;

  g_File.push_back("NTUPLES/BKG/QCD.root");
  g_Tree.push_back("CompressedAnalysis");
  g_Hist.push_back(ihist);
  g_Title.push_back("QCD multijets");
  g_Bkg.push_back(true);
  ihist++;

   
  g_File.push_back("NTUPLES/BKG/Wjets.root");
  g_Tree.push_back("CompressedAnalysis");
  g_Hist.push_back(ihist);
  g_File.push_back("NTUPLES/BKG/Zjets.root");
  g_Tree.push_back("CompressedAnalysis");
  g_Hist.push_back(ihist);
  g_Title.push_back("V + jets");
  g_Bkg.push_back(true);
  ihist++;
   

  // g_File.push_back("/Users/crogan/Dropbox/SAMPLES/STOP_ntuple/STOP_Feb16/BKG/DiBoson.root");
  // g_Tree.push_back("Analysis");
  // g_Hist.push_back(ihist);
  // g_Title.push_back("Di-boson");
  // g_Bkg.push_back(true);
  // ihist++;

  g_File.push_back("NTUPLES/SIG/TT_300_127.root");
  g_Tree.push_back("CompressedAnalysis");
  g_Hist.push_back(ihist);
  g_Title.push_back("m_{#tilde{t}} = 300, m_{#tilde{#chi}} = 127");
  g_Bkg.push_back(false);
  ihist++;

  g_File.push_back("NTUPLES/SIG/TT_350_177.root");
  g_Tree.push_back("CompressedAnalysis");
  g_Hist.push_back(ihist);
  g_Title.push_back("m_{#tilde{t}} = 350, m_{#tilde{#chi}} = 177");
  g_Bkg.push_back(false);
  ihist++;

  // g_File.push_back("NTUPLES/SIG/TT_500_327.root");
  // g_Tree.push_back("CompressedAnalysis");
  // g_Hist.push_back(ihist);
  // g_Title.push_back("m_{#tilde{t}} = 500, m_{#tilde{#chi}} = 327");
  // g_Bkg.push_back(false);
  // ihist++;
   
  


  int Nsample = g_File.size();
  int Nhist = ihist;

  //g_Xname = "#Delta #phi_{CM, V}";
  g_Xname = "#vec{p}_{I}^{ CM}. #hat{p}_{T S}^{ CM} / p_{T S}^{ CM}";
  g_Xmin = 0.;
  g_Xmax = acos(-1.);
  g_NX = 30;


  TH1D* hist[Nhist];
  for(int i = 0; i < Nhist; i++)
    hist[i] = new TH1D(("h"+to_string(i)).c_str(),
		       ("h"+to_string(i)).c_str(),
		       g_NX,g_Xmin,g_Xmax);

  for(int s = 0; s < Nsample; s++){
    TChain* chain = new TChain(g_Tree[s].c_str());
    chain->Add(g_File[s].c_str());

    CompressedBase* base = new CompressedBase(chain);

    int Nentry = base->fChain->GetEntries();

    cout << "Sample " << s << " | " << Nsample << endl;
    for(int e = 0; e < Nentry; e++){
      base->GetEntry(e);
      if(e%(max(1,Nentry/10)) == 0)
	cout << "event " << e << " | " << Nentry << endl;

      if(!base->HLT_xe70_tc_lcw)
       	continue;
      
      if(base->MET < 200.)
       	continue;

      if(fabs(base->dphi_MET_TrkMET) > acos(-1.)/2.)
	continue;
      
      if(base->PTISR[0] < 500.)
       	continue;

      if(base->PIoPTISR[0] < 0.3)
      	continue;

      if(base->MS[0] < 250)
      	 continue;

      if(base->NjV[0] < 5)
      	 continue;

      if(!base->LepVeto)
      	 continue;

      // if(!base->TauVeto)
      // 	 continue;

      // if(base->dphiCMV[0] < 0.4)
      // 	 continue;

      // if(acos(-1.)-base->dphiCMV[0] < 0.1)
      // 	 continue;

      if(base->NbV[0] < 1)
      	continue;

      if(base->pTjV5[0] < 40.)
      	continue;

      // if(base->RPT_HT1CM > 0.1)
      // 	 continue;

      hist[g_Hist[s]]->Fill(fabs(base->dphiISRI[0]), base->weight*g_Lumi);

    }

    delete base;
    delete chain;
  }

  TH1D* h_BKG = nullptr;
  bool isBKG = false;
  for(int i = 0; i < Nhist; i++){
    cout << "Sample " << g_Title[i] << " has " << hist[i]->Integral() << " events" << endl;
    if(g_Bkg[i]){
      if(!isBKG){
	h_BKG = (TH1D*) hist[i]->Clone("TOT_BKG");
	isBKG = true;
      } else {
	for(int k = 0; k < i; k++){
	  hist[k]->Add(hist[i]);
	}
	h_BKG->Add(hist[i]);
      }
    }
  }
  if(h_BKG)
    cout << "Total Background is " << h_BKG->Integral() << " events" << endl;

  double max = -1.;
  int imax = -1;
  for(int i = 0; i < Nhist; i++){
    if(hist[i]->GetMaximum() > max){
      max = hist[i]->GetMaximum();
      imax = i;
    }
  }
  float width = hist[0]->GetBinWidth(1);
  char *yaxis = new char[100];
  sprintf(yaxis,"Events / %f", width);

  gStyle->SetOptTitle(0);
  gStyle->SetOptStat(0);
  gStyle->SetOptFit(11111111);
  TCanvas* can = (TCanvas*) new TCanvas("can","can",600.,500);

  can->SetLeftMargin(0.13);
  can->SetRightMargin(0.04);
  can->SetBottomMargin(0.15);
  can->SetTopMargin(0.085);
  can->SetGridx();
  can->SetGridy();
  can->Draw();
  can->cd();
  hist[imax]->Draw();
  hist[imax]->GetXaxis()->CenterTitle();
  hist[imax]->GetXaxis()->SetTitleFont(132);
  hist[imax]->GetXaxis()->SetTitleSize(0.06);
  hist[imax]->GetXaxis()->SetTitleOffset(1.06);
  hist[imax]->GetXaxis()->SetLabelFont(132);
  hist[imax]->GetXaxis()->SetLabelSize(0.05);
  hist[imax]->GetXaxis()->SetTitle(g_Xname.c_str());
  hist[imax]->GetYaxis()->CenterTitle();
  hist[imax]->GetYaxis()->SetTitleFont(132);
  hist[imax]->GetYaxis()->SetTitleSize(0.06);
  hist[imax]->GetYaxis()->SetTitleOffset(1.);
  hist[imax]->GetYaxis()->SetLabelFont(132);
  hist[imax]->GetYaxis()->SetLabelSize(0.05);
  hist[imax]->GetYaxis()->SetTitle("a. u.");
  hist[imax]->GetYaxis()->SetTitle(yaxis);
  //hist[imax]->GetYaxis()->SetTitle("N_{evt} / fb^{-1}");

  int Ntype[3];

  Ntype[0] = 0;
  for(int i = 0; i < Nhist; i++){
    if(g_Bkg[i]){
      hist[i]->SetLineColor(kBlack);
      if(style_list[1][Ntype[0]+1] > 1001) 
	hist[i]->SetLineColor(color_list[1][Ntype[0]+1]);
      hist[i]->SetLineWidth(1.0);
      hist[i]->SetFillColor(color_list[1][Ntype[0]+1]);
      hist[i]->SetFillStyle(style_list[1][Ntype[0]+1]);
      Ntype[0]++;
      hist[i]->Draw("SAME");
    }
  }

  if(Ntype[0] > 0 && h_BKG){
    h_BKG->SetLineWidth(3.0);
    h_BKG->SetLineColor(color_list[3][0]);
    h_BKG->SetMarkerSize(0);
    h_BKG->Draw("SAME");
  }
	
  Ntype[1] = 0;
  for(int i = 0; i < Nhist; i++){
    if(!g_Bkg[i]){
      hist[i]->SetLineWidth(3.0);
      hist[i]->SetMarkerSize(0.);
      hist[i]->SetMarkerColor(kBlack);
      hist[i]->SetLineColor(color_list[2][Ntype[1]]);
      hist[i]->SetLineStyle(style_list[2][Ntype[1]]);
      hist[i]->SetLineColor(kRed+2);
      Ntype[1]++;
      hist[i]->Draw("SAME");
    }
  }


  TLegend* leg = new TLegend(0.688,0.22,0.93,0.42);
  leg->SetTextFont(132);
  leg->SetTextSize(0.045);
  leg->SetFillColor(kWhite);
  leg->SetLineColor(kWhite);
  leg->SetShadowColor(kWhite);
  if(Ntype[0] > 0) leg->AddEntry(h_BKG, "Total Bkg.");
  for(int i = 0; i < Nhist; i++)
    if(g_Bkg[i])
      leg->AddEntry(hist[i],g_Title[i].c_str(),"F");
    else
      leg->AddEntry(hist[i],g_Title[i].c_str());
  leg->SetLineColor(kWhite);
  leg->SetFillColor(kWhite);
  leg->SetShadowColor(kWhite);
  leg->Draw("SAME");

  TLatex l;
  l.SetTextFont(132);
  l.SetNDC();
  l.SetTextSize(0.05);
  l.SetTextFont(132);
  // l.DrawLatex(0.17,0.855,g_PlotTitle.c_str());
  l.DrawLatex(0.65,0.943,g_PlotTitle.c_str());
  l.SetTextSize(0.04);
  l.SetTextFont(42);
  l.DrawLatex(0.15,0.943,"#bf{#it{ATLAS}} Internal 13 TeV Simulation");
  l.SetTextSize(0.05);
  l.SetTextFont(132);
  string s_lumi = "#scale[0.6]{#int} #it{L dt} = "+to_string(int(g_Lumi))+" fb^{-1}";
  l.DrawLatex(0.43,0.79,s_lumi.c_str());	

  // l.SetTextSize(0.045);
  // l.SetTextFont(132);
  // string bla = "#scale[0.6]{#int} #it{L dt} = "+to_string(int(g_lumi))+" fb^{-1},  #Delta_{N#scale[0.8]{bkg}} = ";
  // bla += to_string(int(g_deltaNbkg))+" %";
  // l.DrawLatex(0.61,0.943,bla.c_str());


}



void setstyle(int istyle) {
	
  // For the canvas:
  gStyle->SetCanvasBorderMode(0);
  gStyle->SetCanvasColor(kWhite);
  gStyle->SetCanvasDefH(300); //Height of canvas
  gStyle->SetCanvasDefW(600); //Width of canvas
  gStyle->SetCanvasDefX(0);   //POsition on screen
  gStyle->SetCanvasDefY(0);
	
  // For the Pad:
  gStyle->SetPadBorderMode(0);
  // gStyle->SetPadBorderSize(Width_t size = 1);
  gStyle->SetPadColor(kWhite);
  gStyle->SetPadGridX(false);
  gStyle->SetPadGridY(false);
  gStyle->SetGridColor(0);
  gStyle->SetGridStyle(3);
  gStyle->SetGridWidth(1);
	
  // For the frame:
  gStyle->SetFrameBorderMode(0);
  gStyle->SetFrameBorderSize(1);
  gStyle->SetFrameFillColor(0);
  gStyle->SetFrameFillStyle(0);
  gStyle->SetFrameLineColor(1);
  gStyle->SetFrameLineStyle(1);
  gStyle->SetFrameLineWidth(1);
	
  // set the paper & margin sizes
  gStyle->SetPaperSize(20,26);
  gStyle->SetPadTopMargin(0.065);
  gStyle->SetPadRightMargin(0.065);
  gStyle->SetPadBottomMargin(0.15);
  gStyle->SetPadLeftMargin(0.17);
	
  // use large Times-Roman fonts
  gStyle->SetTitleFont(132,"xyz");  // set the all 3 axes title font
  gStyle->SetTitleFont(132," ");    // set the pad title font
  gStyle->SetTitleSize(0.06,"xyz"); // set the 3 axes title size
  gStyle->SetTitleSize(0.06," ");   // set the pad title size
  gStyle->SetLabelFont(132,"xyz");
  gStyle->SetLabelSize(0.05,"xyz");
  gStyle->SetLabelColor(1,"xyz");
  gStyle->SetTextFont(132);
  gStyle->SetTextSize(0.08);
  gStyle->SetStatFont(132);
	
  // use bold lines and markers
  gStyle->SetMarkerStyle(8);
  gStyle->SetHistLineWidth(1.85);
  gStyle->SetLineStyleString(2,"[12 12]"); // postscript dashes
	
  //..Get rid of X error bars
  gStyle->SetErrorX(0.001);
	
  // do not display any of the standard histogram decorations
  gStyle->SetOptTitle(0);
  gStyle->SetOptStat(0);
  gStyle->SetOptFit(11111111);
	
  // put tick marks on top and RHS of plots
  gStyle->SetPadTickX(1);
  gStyle->SetPadTickY(1);
	
  // set a decent palette
  gStyle->SetPalette(1);
	
  gStyle->cd();
	
  TColorWheel *w = new TColorWheel();
	
  icolor[0][1] = new TColor(1390, 0.90, 0.60, 0.60, ""); //red
  icolor[0][0] = new TColor(1391, 0.70, 0.25, 0.25, "");
  icolor[1][1] = new TColor(1392, 0.87, 0.87, 0.91, ""); //blue
  icolor[1][0] = new TColor(1393, 0.59, 0.58, 0.91, "");
  icolor[2][1] = new TColor(1394, 0.65, 0.55, 0.85, ""); //violet (gamma)
  icolor[2][0] = new TColor(1395, 0.49, 0.26, 0.64, "");
  icolor[3][1] = new TColor(1396, 0.95, 0.95, 0.60, ""); // yellow (alpha)
  icolor[3][0] = new TColor(1397, 0.95, 0.95, 0.00, "");
  icolor[4][1] = new TColor(1398, 0.75, 0.92, 0.68, ""); //green (2beta+gamma)
  icolor[4][0] = new TColor(1399, 0.36, 0.57, 0.30, "");
  icolor[5][1] = new TColor(1400, 0.97, 0.50, 0.09, ""); // orange
  icolor[5][0] = new TColor(1401, 0.76, 0.34, 0.09, "");
  icolor[6][1] = new TColor(1402, 0.97, 0.52, 0.75, ""); // pink
  icolor[6][0] = new TColor(1403, 0.76, 0.32, 0.51, "");
  icolor[7][1] = new TColor(1404, 0.49, 0.60, 0.82, ""); // dark blue (kpnn)
  icolor[7][0] = new TColor(1405, 0.43, 0.48, 0.52, "");
  icolor[8][1] = new TColor(1406, 0.70, 0.70, 0.70, "");  // black
  icolor[8][0] = new TColor(1407, 0.40, 0.40, 0.40, "");
	
	
  if(istyle == 0){
		
    //SM MC
    color_list[3][0] = kCyan+3;
		
    //DATA
    color_list[0][0] = 1;
    color_list[0][1] = 2;
    color_list[0][2] = 4;
    style_list[0][0] = 20;
    style_list[0][1] = 23;
		
    //BKG MC
    color_list[1][0] = 0;
    color_list[1][3] = kGreen-9; //Light green
    color_list[1][5] = kOrange-2; //dark blue
    color_list[1][4] = kGreen+3; //yellow
    color_list[1][1] = kBlue-10; //light blue
    color_list[1][2] = kBlue+4; //dark green
    style_list[1][0] = 1001;
    style_list[1][1] = 1001;
    style_list[1][2] = 3002;
    style_list[1][3] = 1001;
    style_list[1][4] = 1001;
    style_list[1][5] = 1001;
		
    //SIG MC
    color_list[2][0] = 1;
    color_list[2][1] = 1;
    color_list[2][2] = 1;
    style_list[2][0] = 2;
    style_list[2][1] = 5;
  }
  if(istyle == 1){
		
    //SM MC
    color_list[3][0] = kSpring+4;
		
    //DATA
    color_list[0][0] = 1;
    color_list[0][1] = 2;
    color_list[0][2] = 4;
    style_list[0][0] = 20;
    style_list[0][1] = 23;
		
    //BKG MC
    color_list[1][0] = 0;
    color_list[1][1] = kGreen-9; //Light green
    color_list[1][2] = kGreen+3; //dark blue
    color_list[1][3] = kYellow-7; //yellow
    color_list[1][4] = kBlue-10; //light blue
    color_list[1][5] = kBlue+4; //dark blue
    style_list[1][0] = 1001;
    style_list[1][1] = 1001;
    style_list[1][2] = 3002;
    style_list[1][3] = 1001;
    style_list[1][4] = 1001;
    style_list[1][5] = 1001;
		
    //SIG MC
    color_list[2][0] = 1;
    color_list[2][1] = 1;
    color_list[2][2] = 1;
    style_list[2][0] = 2;
    style_list[2][1] = 5;
  }
  if(istyle == 2){
		
    //SM MC
    color_list[3][0] = kMagenta+2;
		
    //DATA
    color_list[0][0] = 1;
    color_list[0][1] = 2;
    color_list[0][2] = 4;
    style_list[0][0] = 20;
    style_list[0][1] = 23;
		
    //BKG MC
    color_list[1][0] = 0;
    color_list[1][3] = kRed-9; //Light green
    color_list[1][5] = kRed+3; //dark blue
    color_list[1][4] = kYellow-7; //yellow
    color_list[1][1] = kMagenta-10; //light blue
    color_list[1][2] = kMagenta+4; //dark green
    style_list[1][0] = 1001;
    style_list[1][1] = 1001;
    style_list[1][2] = 3002;
    style_list[1][3] = 1001;
    style_list[1][4] = 1001;
    style_list[1][5] = 1001;
		
    //SIG MC
    color_list[2][0] = 1;
    color_list[2][1] = 1;
    color_list[2][2] = 1;
    style_list[2][0] = 2;
    style_list[2][1] = 5;
  }
	
}
