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

#include "include/HFntupleBase.hh"

#include "RestFrames/RestFrames.hh"

using namespace std;

vector<string> g_File;
vector<string> g_Tree;
vector<string> g_Title;
vector<double> g_Scale;
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

void Plot_2D_HFntupleBase(){
  HistPlot::SetStyle();

  int SKIP = 1; // how many events to skip, ex. 10 runs over 1/10 of events

  g_PlotTitle = "Test File";
  g_File.push_back("samples/HFntuple.root");
  g_Tree.push_back("HFntupleNONE");
  g_Scale.push_back(1.);

  int Nsample = g_File.size();

  string g_Label = "Baseline Selection";

  g_Xname = "#vec{p}_{T I}^{ CM}. #hat{p}_{T ISR}^{ CM} / p_{T ISR}^{ CM}";
  g_Xmin = 0.0;
  g_Xmax = 1.; 
  g_NX = 20;
  g_Yname = "p_{T}^{ ISR} [GeV]";
  g_Ymin = 0.;
  g_Ymax = 1500.;
  g_NY = 20;

  TH2D* hist = new TH2D("hist","hist",
			g_NX,g_Xmin,g_Xmax,
			g_NY,g_Ymin,g_Ymax);

  /////////////////////////////////////////////////

  // Define the frames in our reconstruction tree
  LabRecoFrame       LAB("LAB","lab");
  DecayRecoFrame     CM("CM","CM");
  DecayRecoFrame     S("S","S");
  VisibleRecoFrame   ISR("ISR","ISR");
  VisibleRecoFrame   V("V","V");
  InvisibleRecoFrame I("I","I");

  // connect the tree according to our interpretation
  LAB.SetChildFrame(CM);
  CM.AddChildFrame(ISR);
  CM.AddChildFrame(S);
  S.AddChildFrame(V);
  S.AddChildFrame(I);

  // Initialize the tree skeleton (check for problems)
  if(!LAB.InitializeTree())
    cout << "PROBLEM with reco tree structure" << endl;

  InvisibleGroup INV("INV","Invisible System");
  INV.AddFrame(I);

  CombinatoricGroup VIS("VIS","Visible Objects");
  VIS.AddFrame(ISR);
  VIS.SetNElementsForFrame(ISR,1,false);
  VIS.AddFrame(V);
  VIS.SetNElementsForFrame(V,0,false);

  // set the invisible system mass to zero
  SetMassInvJigsaw InvMass("InvMass", "Invisible system mass Jigsaw");
  INV.AddJigsaw(InvMass);

  // define the rule for partitioning objects between "ISR" and "V"
  MinMassesCombJigsaw SplitVis("SplitVis","Minimize M_{ISR} and M_{S} Jigsaw");
  VIS.AddJigsaw(SplitVis);
  // "0" group (ISR)
  SplitVis.AddFrame(ISR, 0);
  // "1" group (V + I)
  SplitVis.AddFrame(V,1);
  SplitVis.AddFrame(I,1);

  if(!LAB.InitializeAnalysis())
    cout << "PROBLEM with analysis set-up of tree" << endl;

  /////////////////////////////////////////////////////////

  // Draw the RestFrames tree if you like!
  TreePlot* tree_plot = new TreePlot("TreePlot","TreePlot");
  tree_plot->SetFrameTree(LAB);
  tree_plot->Draw();

  return;

  /////////////////////////////////////////////////////////

  for(int s = 0; s < Nsample; s++){
    TChain* chain = new TChain(g_Tree[s].c_str());
    chain->Add(g_File[s].c_str());

    HFntupleBase* base = new HFntupleBase(chain);

    int Nentry = base->fChain->GetEntries();
    for(int e = 0; e < Nentry; e++){
      if(e%SKIP != 0) continue;
      if(e%(max(1,Nentry/10)) == 0)
	cout << "Event " << e << " | " << Nentry << endl;
      base->GetEntry(e);

      // Get the jets in a vector
      vector<TLorentzVector> JETs;
      vector<bool> JETs_btag;

      int Njet = base->jet_px->size();
      for(int i = 0; i < Njet; i++){
	TLorentzVector JET;
	JET.SetPxPyPzE(base->jet_px->at(i)/1000., base->jet_py->at(i)/1000.,
		       base->jet_pz->at(i)/1000., base->jet_e->at(i)/1000.);

	if((JET.Pt() >= 30.) && (fabs(JET.Eta()) < 2.8)){
	  JETs.push_back(JET);
	  JETs_btag.push_back( (base->jet_MV2c20->at(i) > 0.7) );
	}
      }

      // two to play
      if(JETs.size() < 2) continue;

      TVector3 MET;
      MET.SetXYZ(base->MET_px,base->MET_py, 0.);

      LAB.ClearEvent();
      vector<RFKey> jetID; 
      for(int i = 0; i < int(JETs.size()); i++){
	TLorentzVector jet = JETs[i];
	jet.SetPtEtaPhiM(jet.Pt(),0.0,jet.Phi(),jet.M());
	jetID.push_back(VIS.AddLabFrameFourVector(jet));
      }
      INV.SetLabFrameThreeVector(MET);
      if(!LAB.AnalyzeEvent()) 
	cout << "PROBLEM with event analysis" << endl;

      // Compressed variables from tree
      int NjV = VIS.GetNElementsInFrame(V);
      int NjISR = VIS.GetNElementsInFrame(ISR);
      int NbV = 0;
      int NbISR = 0;

      // need at least one jet associated with MET-side of event
      if(NjV < 1)
	continue;

      // count b-jets in each half of the event
      int Nj = jetID.size();
      for(int i = 0; i < Nj; i++){
	if(JETs_btag[i]){
	  if(VIS.GetFrame(jetID[i]) == ISR){ // ISR group
	    NbISR++;
	  } else {                             // sparticle group
	    NbV++;
	  }
	}
      }

      TVector3 vP_ISR = ISR.GetFourVector(CM).Vect();
      TVector3 vP_I   = I.GetFourVector(CM).Vect();

      double PTISR = vP_ISR.Mag();
      double PIoPTISR = fabs(vP_I.Dot(vP_ISR.Unit())) / PTISR;
      double cosS = S.GetCosDecayAngle();
      double MS = S.GetMass();
      double MV = V.GetMass();
      double MISR = ISR.GetMass();
      double dphiCMV = CM.GetDeltaPhiBoostVisible();

      double weight = 1.;
      hist->Fill(PIoPTISR, PTISR, weight);
    }

    delete base;
    delete chain;
  }

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
  l.DrawLatex(0.5,0.943,g_PlotTitle.c_str());
  l.SetTextSize(0.04);
  l.SetTextFont(42);
  l.DrawLatex(0.01,0.943,"#bf{#it{ATLAS}} Internal 13 TeV Simulation");

  l.SetTextSize(0.04);
  l.SetTextFont(132);
  l.DrawLatex(0.7,0.04,g_Label.c_str());


}
