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

#include "RestFrames/RestFrames.hh"

#include "include/CompressedBase.hh"

using namespace RestFrames;
using namespace std;

vector<string> g_File;
vector<string> g_Tree;
vector<int> g_Hist;
vector<string> g_Title;
vector<bool> g_Bkg;
vector<int> g_Color;
double g_Lumi;
string g_PlotTitle;
string g_Xname;
double g_Xmin;
double g_Xmax;
double g_NX;

void Plot_1D_stack(){
  RFPlot::SetStyle();

  int ihist = 0;
   
  g_File.push_back("NTUPLES/BKG/Wjets.root");
  g_Tree.push_back("CompressedAnalysis");
  g_Hist.push_back(ihist);
  g_Title.push_back("W + jets");
  g_Bkg.push_back(true);
  g_Color.push_back(kAzure+1);
  ihist++;

  g_File.push_back("NTUPLES/BKG/ttbar.root");
  g_Tree.push_back("CompressedAnalysis");
  g_Hist.push_back(ihist);
  g_Title.push_back("t #bar{t}");
  g_Bkg.push_back(true);
  g_Color.push_back(kGreen-9);
  ihist++;

  g_File.push_back("NTUPLES/BKG/QCD.root");
  g_Tree.push_back("CompressedAnalysis");
  g_Hist.push_back(ihist);
  g_Title.push_back("QCD");
  g_Bkg.push_back(true);
  g_Color.push_back(10);
  ihist++;

  g_File.push_back("NTUPLES/BKG/SingleTop.root");
  g_Tree.push_back("CompressedAnalysis");
  g_Hist.push_back(ihist);
  g_Title.push_back("single top");
  g_Bkg.push_back(true);
  g_Color.push_back(kGreen+3);
  ihist++;

  g_File.push_back("NTUPLES/BKG/Zjets.root");
  g_Tree.push_back("CompressedAnalysis");
  g_Hist.push_back(ihist);
  g_Title.push_back("Z + jets");
  g_Bkg.push_back(true);
  g_Color.push_back(603);
  ihist++;

  g_File.push_back("NTUPLES/BKG/Diboson.root");
  g_Tree.push_back("CompressedAnalysis");
  g_Hist.push_back(ihist);
  g_Title.push_back("di-boson");
  g_Bkg.push_back(true);
  g_Color.push_back(kYellow);
  ihist++;

  g_File.push_back("NTUPLES/BKG/ttbarV.root");
  g_Tree.push_back("CompressedAnalysis");
  g_Hist.push_back(ihist);
  g_File.push_back("NTUPLES/BKG/SM4top.root");
  g_Tree.push_back("CompressedAnalysis");
  g_Hist.push_back(ihist);
  g_File.push_back("NTUPLES/BKG/ttbarWW.root");
  g_Tree.push_back("CompressedAnalysis");
  g_Hist.push_back(ihist);
  g_Title.push_back("Others");
  g_Bkg.push_back(true);
  g_Color.push_back(kRed+3);
  ihist++;

  g_File.push_back("NTUPLES/SIG/TT_250_77.root");
   g_Tree.push_back("CompressedAnalysis");
   g_Hist.push_back(ihist);
   g_Title.push_back("m_{#tilde{t}} = 250, m_{#tilde{#chi}} = 77");
   g_Bkg.push_back(false);
   g_Color.push_back(kMagenta+1);
   ihist++;

   g_File.push_back("NTUPLES/SIG/TT_300_127.root");
   g_Tree.push_back("CompressedAnalysis");
   g_Hist.push_back(ihist);
   g_Title.push_back("m_{#tilde{t}} = 300, m_{#tilde{#chi}} = 127");
   g_Bkg.push_back(false);
   g_Color.push_back(kRed+2);
   ihist++;

   g_File.push_back("NTUPLES/SIG/TT_350_177.root");
   g_Tree.push_back("CompressedAnalysis");
   g_Hist.push_back(ihist);
   g_Title.push_back("m_{#tilde{t}} = 350, m_{#tilde{#chi}} = 177");
   g_Bkg.push_back(false);
   g_Color.push_back(kBlack);
   ihist++;

   g_File.push_back("NTUPLES/SIG/TT_350_150.root");
   g_Tree.push_back("CompressedAnalysis");
   g_Hist.push_back(ihist);
   g_Title.push_back("m_{#tilde{t}} = 350, m_{#tilde{#chi}} = 150");
   g_Bkg.push_back(false);
   g_Color.push_back(kGreen-1);
   ihist++;

   g_File.push_back("NTUPLES/SIG/TT_400_227.root");
   g_Tree.push_back("CompressedAnalysis");
   g_Hist.push_back(ihist);
   g_Title.push_back("m_{#tilde{t}} = 400, m_{#tilde{#chi}} = 227");
   g_Bkg.push_back(false);
   g_Color.push_back(kCyan+2);
   ihist++;
   
   g_File.push_back("NTUPLES/SIG/TT_500_327.root");
   g_Tree.push_back("CompressedAnalysis");
   g_Hist.push_back(ihist);
   g_Title.push_back("m_{#tilde{t}} = 500, m_{#tilde{#chi}} = 327");
   g_Bkg.push_back(false);
   g_Color.push_back(kOrange+1);
   ihist++;
   


  int Nsample = g_File.size();
  int Nhist = ihist;

  g_PlotTitle = "CR0L (a)";
  g_Lumi = 10.;

  g_Xname = "R_{ISR}";
  g_Xmin = 0.;
  g_Xmax = acos(-1.);
  g_NX = 20;


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

      if(base->HLT_xe70_tc_lcw < 1)
       	continue;

      if(base->MET < 200.)
       	continue;

      // if(fabs(base->dphi_MET_TrkMET) > acos(-1.)/3.)
      // 	continue;

      // if(base->dphiMin2 < 0.4)
      // 	continue;

      // if(base->TrkMET < 30.)
      // 	continue;

      // if(base->nMu_baseline > 0 ||
      // 	 base->nEl_baseline > 0)
      // 	 continue;

      if((base->nEl+base->nMu) != 1)
      	continue;

      if(base->NlV < 1)
      	continue;
      
      if(base->pT_2jet < 80.)
	continue;
      
      // if(base->pT_3jet < 20.)
      // 	continue;
 
      // if(base->RISR < 0.35)
      //  	continue;

      if(base->PTISR < 400.)
       	continue;

      // if(base->NbISR > 1)
      // 	continue;

      if(base->NbV < 1)
      	continue;

      if(base->NjV < 3)
      	continue;

      if(base->pTbV1 < 40.)
      	continue;

      if(base->pTjV3 < 45.)
      	continue;

      // if(base->MS > 300)
      //  	 continue;

      // if(base->MS < 100)
      // 	 continue;

      // if(base->MV/base->MS > 0.6)
      // 	 continue;

      if(base->MT < 125.)
      	 continue;

      // if(base->pT_1lep < 20.)
      // 	continue;

      // if(base->mj0_12 > 60)
      // 	continue;

      // if(base->dRMinbl1 < 3.3)
      // 	continue;

      if(base->dphiISRI < 2.95)
      	continue;

      // if(base->dphiCML1 > 1.5)
      // 	continue;

      // if(base->dphiCMI > 2.5)
      // 	continue;

      double weight = base->weight;
     

      hist[g_Hist[s]]->Fill(base->dphiCMI, weight*g_Lumi);

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
  //sprintf(yaxis,"Events / %f", width);
  sprintf(yaxis,"Events / bin", width);

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
      // if(style_list[1][Ntype[0]+1] > 1001) 
      // 	hist[i]->SetLineColor(color_list[1][Ntype[0]+1]);
      hist[i]->SetLineWidth(1.0);
      hist[i]->SetFillColor(g_Color[i]);
      hist[i]->SetFillStyle(1001);
      Ntype[0]++;
      hist[i]->Draw("SAME");
    }
  }

  if(Ntype[0] > 0 && h_BKG){
    h_BKG->SetLineWidth(3.0);
    h_BKG->SetLineColor(kRed);
    h_BKG->SetMarkerSize(0);
    h_BKG->Draw("SAME");
  }
	
  Ntype[1] = 0;
  for(int i = 0; i < Nhist; i++){
    if(!g_Bkg[i]){
      hist[i]->SetLineWidth(3.0);
      hist[i]->SetMarkerSize(0.);
      hist[i]->SetMarkerColor(kBlack);
      hist[i]->SetLineStyle(7);
      hist[i]->SetLineColor(g_Color[i]);
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
  if(Ntype[0] > 0) leg->AddEntry(h_BKG, "SM total");
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
  l.DrawLatex(0.65,0.943,g_PlotTitle.c_str());
  l.SetTextSize(0.04);
  l.SetTextFont(42);
  l.DrawLatex(0.15,0.943,"#bf{#it{ATLAS}} Internal 13 TeV Simulation");
  l.SetTextSize(0.05);
  l.SetTextFont(132);
  string s_lumi = "#scale[0.6]{#int} #it{L dt} = "+to_string(int(g_Lumi))+" fb^{-1}";
  l.DrawLatex(0.43,0.79,s_lumi.c_str());	

}



