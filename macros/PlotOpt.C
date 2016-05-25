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
#include <TObjArray.h>

double EvaluateMetric(double Nsig, double Nbkg);

double g_deltaNbkg;
double g_lumi;
double g_minBKG;

void PlotOpt(){
  // fixed background uncertainty (%)
  g_deltaNbkg = 20.;
  // integrated luminosity (fb^-1)
  g_lumi = 10.;
  // minimum number of expected background events
  g_minBKG = 0.01;

  TFile* input = new TFile("test.root","READ");

  int ParentMass = 250;
  int LSPMass    = 77;

  double Sscale = 1.;
  double Bscale = 1.;

  string SignalModel = "TT";
  string plot_title = "#tilde{t} #tilde{t} #rightarrow (t #tilde{#chi})(t #tilde{#chi}); m_{#tilde{t}} = ";
  plot_title += to_string(ParentMass)+", m_{#tilde{#chi}} = "+to_string(LSPMass)+" GeV";
  
  TTree* tree  = (TTree*) input->Get("optimization");
  double Nsig, Nbkg;
  vector<double> VAR;
  TBranch *b_Nsig,*b_Nbkg;
  vector<TBranch*> b_VAR;
  //int Ncut = tree->GetNbranches()-2;
  int Ncut = 0;
  TObjArray* branches = tree->GetListOfBranches();
  int Nbranch = branches->GetEntries();
  for(int i = 0; i < Nbranch; i++)
    if(string(branches->At(i)->GetName()).find("var") != string::npos)
      Ncut++;
  tree->SetBranchStatus("*",0);
  string sname = "Nsig_"+SignalModel+"_"+to_string(ParentMass)+"_"+to_string(LSPMass);
  tree->SetBranchStatus(sname.c_str(),"1");
  tree->SetBranchAddress(sname.c_str(),&Nsig,&b_Nsig);
  tree->SetBranchStatus("Nbkg","1");
  tree->SetBranchAddress("Nbkg",&Nbkg,&b_Nbkg);
  for(int i = 0; i < Ncut; i++){
    VAR.push_back(0.);
    b_VAR.push_back(new TBranch());
  }
  for(int i = 0; i < Ncut; i++){
    tree->SetBranchStatus(("var"+to_string(i)).c_str(),"1");
    tree->SetBranchAddress(("var"+to_string(i)).c_str(),&(VAR[i]),&b_VAR[i]);
  }

  int Ncomb = tree->GetEntries();

  vector<vector<double> > VAR_cut;
  for(int i = 0; i < Ncut; i++)
    VAR_cut.push_back(vector<double>());

  // find max metric combination
  int c_max = -1;
  double metric_max = -1.;
  for(int c = 0; c < Ncomb; c++){
    tree->GetEntry(c);
    double metric = 0;
    if(Nsig > 0. && Nbkg > 0. && g_lumi*Nbkg*Bscale > g_minBKG)
       metric = EvaluateMetric(g_lumi*Nsig*Sscale,g_lumi*Nbkg*Bscale);
    if(metric > metric_max && g_lumi*Nbkg*Bscale > g_minBKG){
      metric_max = metric;
      c_max = c;
    }
    for(int i = 0; i < Ncut; i++){
      int N = VAR_cut[i].size();
      bool found = false;
      for(int j = 0; j < N; j++){
	if(VAR_cut[i][j] == VAR[i]){
	  found = true;
	  break;
	}
      }
      if(!found)
	VAR_cut[i].push_back(VAR[i]);
    }
  }
  
  vector<double> VAR_max;
  tree->GetEntry(c_max);
  cout << "Point: " << ParentMass << " " << LSPMass << endl;;
  cout << "Max significance of " << EvaluateMetric(g_lumi*Nsig*Sscale,g_lumi*Nbkg*Bscale);
  cout << " sigma with:" << endl;
  cout << "   Nsig = " << g_lumi*Nsig*Sscale << endl;
  cout << "   Nbkg = " << g_lumi*Nbkg*Bscale << endl;
  for(int i = 0; i < Ncut; i++){
    VAR_max.push_back(VAR[i]);
    cout << "var " << i << " " << VAR[i] << endl;
  }

  vector<vector<double> > VAR_max_fix;
  vector<vector<double> > VAR_max_float;
  for(int i = 0; i < Ncut; i++){
    VAR_max_fix.push_back(vector<double>());
    VAR_max_float.push_back(vector<double>());
    int N = VAR_cut[i].size();
    for(int j = 0; j < N; j++){
      VAR_max_fix[i].push_back(-1.);
      VAR_max_float[i].push_back(-1.);
    }
  }

  for(int c = 0; c < Ncomb; c++){
    tree->GetEntry(c);
    double metric = 0;
    if(Nsig > 0. && Nbkg > 0. && g_lumi*Nbkg*Bscale > g_minBKG)
       metric = EvaluateMetric(g_lumi*Nsig*Sscale,g_lumi*Nbkg*Bscale);
   
    for(int i = 0; i < Ncut; i++){
      int N = VAR_cut[i].size();
      int jcut = -1;
      for(int j = 0; j < N; j++)
	if(VAR[i] == VAR_cut[i][j])
	  jcut = j;
      if(metric > VAR_max_float[i][jcut])
	VAR_max_float[i][jcut] = metric;
      bool fix = true;
      for(int j = 0; j < Ncut; j++){
	if(i == j) continue;
	if(fabs(VAR[j]-VAR_max[j]) > 1e-10){
	  fix = false;
	  break;
	}
      }
      if(!fix)
	continue;
      if(metric > VAR_max_fix[i][jcut]){
	VAR_max_fix[i][jcut] = metric;
      }
    }
  }
  
  TGraph* gr_fix[Ncut];
  TGraph* gr_float[Ncut];
  TMultiGraph* mg[Ncut];
  TCanvas* can[Ncut];
  TLegend* leg;

  for(int icut = 0; icut < Ncut; icut++){
    int Nval = VAR_cut[icut].size();
    double x[Nval];
    double y[2][Nval];
    for(int i = 0; i < Nval; i++){
      x[i] = VAR_cut[icut][i];
      y[0][i] = VAR_max_fix[icut][i];
      y[1][i] = VAR_max_float[icut][i];
    }
    gr_fix[icut] = (TGraph*) new TGraph(Nval,x,y[0]);
    gr_float[icut] = (TGraph*) new TGraph(Nval,x,y[1]);
    gr_fix[icut]->SetLineWidth(4);
    gr_fix[icut]->SetLineColor(kBlue+2);
    gr_fix[icut]->SetFillColor(kWhite);
    gr_fix[icut]->SetMarkerSize(0);
    gr_float[icut]->SetLineWidth(4);
    gr_float[icut]->SetLineStyle(7);
    gr_float[icut]->SetLineColor(kGreen+3);
    gr_float[icut]->SetFillColor(kWhite);
    gr_float[icut]->SetMarkerSize(0);
    mg[icut] = (TMultiGraph*) new TMultiGraph();
    mg[icut]->Add(gr_fix[icut]);
    mg[icut]->Add(gr_float[icut]);

    string scan = "can_"+to_string(icut);
    can[icut] = (TCanvas*) new TCanvas(scan.c_str(),scan.c_str(),600.,500);
    can[icut]->SetLeftMargin(0.15);
    can[icut]->SetRightMargin(0.04);
    can[icut]->SetBottomMargin(0.15);
    can[icut]->SetGridx();
    can[icut]->SetGridy();
    can[icut]->Draw();
    can[icut]->cd();
    mg[icut]->Draw("AL");
    mg[icut]->GetXaxis()->CenterTitle();
    mg[icut]->GetXaxis()->SetTitleFont(132);
    mg[icut]->GetXaxis()->SetTitleSize(0.06);
    mg[icut]->GetXaxis()->SetTitleOffset(1.13);
    mg[icut]->GetXaxis()->SetLabelFont(132);
    mg[icut]->GetXaxis()->SetLabelSize(0.05);
    mg[icut]->GetXaxis()->SetTitle(("Var "+to_string(icut)).c_str());
    mg[icut]->GetYaxis()->CenterTitle();
    mg[icut]->GetYaxis()->SetTitleFont(132);
    mg[icut]->GetYaxis()->SetTitleSize(0.06);
    mg[icut]->GetYaxis()->SetTitleOffset(1.2);
    mg[icut]->GetYaxis()->SetLabelFont(132);
    mg[icut]->GetYaxis()->SetLabelSize(0.05);
    mg[icut]->GetYaxis()->SetTitle("Significance ( Z_{Bi} )");
    
    if(icut == 0){
      leg = (TLegend*) new TLegend(0.688,0.22,0.93,0.42);
      leg->SetTextFont(132);
      leg->SetTextSize(0.06);
      leg->AddEntry(gr_fix[icut],"#vec{c} |_{global max}");
      leg->AddEntry(gr_float[icut],"#vec{c} |_{local max}");
      leg->SetFillColor(kWhite);
      leg->SetLineColor(kWhite);
      leg->SetShadowColor(kWhite);
    } 
    leg->Draw("SAME");

    TLatex l;
    l.SetTextFont(132);	
    l.SetNDC();	
    l.SetTextSize(0.04);
    l.SetTextFont(132);
    l.DrawLatex(0.17,0.855,plot_title.c_str());
    l.SetTextSize(0.04);
    l.SetTextFont(42);
    l.DrawLatex(0.15,0.943,"#bf{#it{ATLAS}} Internal");
    l.SetTextSize(0.045);
    l.SetTextFont(132);
    string bla = "#scale[0.6]{#int} #it{L dt} = "+to_string(int(g_lumi))+" fb^{-1},  #Delta_{N#scale[0.8]{bkg}} = ";
    bla += to_string(int(g_deltaNbkg))+" %";
    l.DrawLatex(0.55,0.943,bla.c_str());
  }
  
}

double EvaluateMetric(double Nsig, double Nbkg){
  double Nobs = Nsig+Nbkg;
  double tau = 1./Nbkg/(g_deltaNbkg*g_deltaNbkg/10000.);
  double aux = Nbkg*tau;
  double Pvalue = TMath::BetaIncomplete(1./(1.+tau),Nobs,aux+1.);
  return sqrt(2.)*TMath::ErfcInverse(Pvalue*2);
}
