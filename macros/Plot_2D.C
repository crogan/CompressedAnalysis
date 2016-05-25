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
#include <TH2D.h>
#include <TStyle.h>

#include "RestFrames/RestFrames.hh"

#include "include/CompressedBase.hh"

using namespace std;

vector<string> g_File;
vector<string> g_Tree;
vector<string> g_Title;
string g_PlotTitle;
string g_Xname;
double g_Xmin;
double g_Xmax;
double g_NX;
string g_Yname;
double g_Ymin;
double g_Ymax;
double g_NY;

using namespace RestFrames;

void Plot_2D(){
  HistPlot::SetStyle();

  // g_PlotTitle = "QCD multi-jets";
  // g_File.push_back("NTUPLES/BKG/QCD.root");
  // g_Tree.push_back("CompressedAnalysis");

  // g_PlotTitle = "Top + X";
  // g_File.push_back("NTUPLES/BKG/Top.root");
  // g_Tree.push_back("CompressedAnalysis");

  // g_PlotTitle = "m_{#tilde{t}} = 300, m_{#tilde{#chi}} = 127";
  // g_File.push_back("NTUPLES/SIG/TT_300_127.root");
  // g_Tree.push_back("CompressedAnalysis");

  // g_PlotTitle = "t #bar{t} + jets";
  // g_File.push_back("/Users/crogan/STOP/ttbar_lep.root");
  // g_Tree.push_back("CompressedAnalysis");
  // g_File.push_back("/Users/crogan/STOP/ttbar_had.root");
  // g_Tree.push_back("CompressedAnalysis");

  // g_PlotTitle = "W/Z + jets";
  // g_File.push_back("/Users/crogan/STOP/Wjets.root");
  // g_Tree.push_back("CompressedAnalysis");
  // g_File.push_back("/Users/crogan/STOP/Zjets.root");
  // g_Tree.push_back("CompressedAnalysis");

  // g_PlotTitle = "W/Z + jets";
  // g_File.push_back("NTUPLES/BKG/Zjets.root");
  // g_Tree.push_back("CompressedAnalysis");
  // g_File.push_back("NTUPLES/BKG/Wjets.root");
  // g_Tree.push_back("CompressedAnalysis");

  // g_PlotTitle = "QCD multi-jets";
  // g_File.push_back("/Users/crogan/STOP/QCD.root");
  // g_Tree.push_back("CompressedAnalysis");

  g_PlotTitle = "m_{#tilde{t}} = 300, m_{#tilde{#chi}} = 127 GeV";
  g_File.push_back("/Users/crogan/STOP/TT_300_127.root");
  g_Tree.push_back("CompressedAnalysis");

  // g_PlotTitle = "m_{#tilde{t}} = 350, m_{#tilde{#chi}} = 177 GeV";
  // g_File.push_back("/Users/crogan/STOP/TT_350_177.root");
  // g_Tree.push_back("CompressedAnalysis");

  // g_PlotTitle = "m_{#tilde{t}} = 500, m_{#tilde{#chi}} = 327 GeV";
  // g_File.push_back("/Users/crogan/STOP/TT_500_327.root");
  // g_Tree.push_back("CompressedAnalysis");

  // g_PlotTitle = "m_{#tilde{t}} = 300, m_{#tilde{#chi}} = 127 GeV";
  // g_File.push_back("NTUPLES/SIG/TT_300_127.root");
  // g_Tree.push_back("CompressedAnalysis");

  int Nsample = g_File.size();

  //string g_Label = "No selection";
  string g_Label = "p_{T}^{ ISR} > 400 GeV";

  g_Xname = "R_{ISR}";
  g_Xmin = 0.;
  g_Xmax = 1.; 
  g_NX = 30;
  g_Yname = "PTISR";
  g_Ymin = 0.;
  g_Ymax = 800.;
  g_NY = 30.;

  TH2D* hist = new TH2D("hist","hist",
			g_NX,g_Xmin,g_Xmax,
			g_NY,g_Ymin,g_Ymax);

  for(int s = 0; s < Nsample; s++){
    TChain* chain = new TChain(g_Tree[s].c_str());
    chain->Add(g_File[s].c_str());

    CompressedBase* base = new CompressedBase(chain);

    int Nentry = base->fChain->GetEntries();
    for(int e = 0; e < Nentry; e++){
      base->GetEntry(e);

      // if(!base->HLT_xe70_tc_lcw)
      //  	continue;
      
      // if(base->MET < 200.)
      //  	continue;

      // if(fabs(base->dphi_MET_TrkMET) > acos(-1.)/2.)
      // 	continue;

      // if(base->TrkMET < 30.)
      // 	continue;

      // if(!base->LepVeto)
      // 	 continue;

       if(base->PTISR <= 0.)
       	continue;

      // if(base->NbV < 1)
      // 	continue;

      // if(base->NjV < 4)
      // 	continue;

      // if(base->pTbV1 < 40.)
      // 	continue;

       // if(base->NjV < 3)
       // 	continue;

      // if(base->RISR < 0.35)
      // 	continue;

      // if(base->RISR > 0.5)
      // 	continue;

      // if(base->MS > 200)
      // 	 continue;

      // if(base->MS < 100)
      // 	 continue;

      // if(base->pTjV5 < 45.)
      // 	 continue;

      // if(base->dphiISRI < 3.)
      // 	continue;
  

      // if(base->pTjV5[0] < 40.)
      // 	continue;

      // if(base->dphiMin2 < 0.4)
      // 	continue;

      // if(base->dphiMin3 < 0.2)
      // 	continue;

      // if(base->dphiCMI < 0.3)
      // 	continue;

      // if(acos(-1.) - base->dphiCMI < 0.3)
      // 	continue;
      
      double R_PTCM_PTISR = base->PTCM / (base->PTCM + base->MS);

     
      hist->Fill(base->RISR, base->PTISR, base->weight);
     
      
    }

    delete base;
    delete chain;
  }

  gStyle->SetOptTitle(0);
  gStyle->SetOptStat(0);
  gStyle->SetOptFit(11111111);
    TCanvas* can = (TCanvas*) new TCanvas("can","can",700.,600);

    can->SetLeftMargin(0.15);
    can->SetRightMargin(0.22);
    can->SetBottomMargin(0.15);
    can->SetGridx();
    can->SetGridy();
    can->SetLogz();
    can->Draw();
    can->cd();
    hist->Draw("COLZ");
    hist->GetXaxis()->CenterTitle();
    hist->GetXaxis()->SetTitleFont(132);
    hist->GetXaxis()->SetTitleSize(0.06);
    hist->GetXaxis()->SetTitleOffset(1.06);
    hist->GetXaxis()->SetLabelFont(132);
    hist->GetXaxis()->SetLabelSize(0.05);
    hist->GetXaxis()->SetTitle(g_Xname.c_str());
    hist->GetYaxis()->CenterTitle();
    hist->GetYaxis()->SetTitleFont(132);
    hist->GetYaxis()->SetTitleSize(0.06);
    hist->GetYaxis()->SetTitleOffset(1.12);
    hist->GetYaxis()->SetLabelFont(132);
    hist->GetYaxis()->SetLabelSize(0.05);
    hist->GetYaxis()->SetTitle(g_Yname.c_str());
    hist->GetZaxis()->CenterTitle();
    hist->GetZaxis()->SetTitleFont(132);
    hist->GetZaxis()->SetTitleSize(0.06);
    hist->GetZaxis()->SetTitleOffset(1.3);
    hist->GetZaxis()->SetLabelFont(132);
    hist->GetZaxis()->SetLabelSize(0.05);
    hist->GetZaxis()->SetTitle("N_{evt} / bin / fb^{-1}");
    hist->GetZaxis()->SetRangeUser(0.9*hist->GetMinimum(0.0),1.1*hist->GetMaximum());

    TLatex l;
    l.SetTextFont(132);
    l.SetNDC();
    l.SetTextSize(0.05);
    l.SetTextFont(132);
    // l.DrawLatex(0.17,0.855,g_PlotTitle.c_str());
    l.DrawLatex(0.5,0.943,g_PlotTitle.c_str());
    l.SetTextSize(0.04);
    l.SetTextFont(42);
    l.DrawLatex(0.01,0.943,"#bf{#it{ATLAS}} Internal 13 TeV Simulation");

    l.SetTextSize(0.04);
    l.SetTextFont(132);
    l.DrawLatex(0.64,0.04,g_Label.c_str());


}
