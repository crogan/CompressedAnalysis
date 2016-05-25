#include <TFile.h>
#include <TTree.h>
#include <TList.h>
#include <iostream>
#include <string>

#include "OptimizationBase.hh"
#include "CompressedBase.hh"

using namespace std;

template <class Base>
OptimizationBase<Base>::OptimizationBase(){
  m_Chain = (TChain*) new TChain("Analysis");
  m_Base = nullptr;
  m_Tree = nullptr;
  m_NSIG = 0;
}

template <class Base>
OptimizationBase<Base>::~OptimizationBase(){
  delete m_Chain;
  if(m_Base)
    delete m_Base;
}

template <class Base>
void OptimizationBase<Base>::Loop(int Njob, int ijob){
  if(ijob >= Njob) return;

  InitCuts();
  InitBase();

  int Ncomb = 1;
  for(int i = 0; i < m_N_Cut; i++)
    Ncomb *= m_CutN[i];
  Ncomb /= Njob;
  int Nstart = Ncomb*ijob;
  int Nend   = Ncomb*(ijob+1);

  vector<vector<double> > Nsig_comb;
  vector<double> Nbkg_comb;
  for(int i = 0; i < m_NSIG; i++)
    Nsig_comb.push_back(vector<double>());
  for(int i = 0; i < Ncomb; i++){
    for(int s = 0; s < m_NSIG; s++)
      Nsig_comb[s].push_back(0.);
    Nbkg_comb.push_back(0.);
  }

  Long64_t Nevent = m_Base->fChain->GetEntries();
  // event loop
  for(Long64_t ievent = 0; ievent < Nevent; ievent++){
    if(ievent%(Nevent/100) == 0)
      cout << "event " << ievent << " | " << Nevent << endl;
    m_Base->fChain->GetEntry(ievent);
    if(!PassBaseline()) continue;

    int ifile = m_Base->fChain->GetTreeNumber();

    // combinatoric cut loop
    int icut = -1;
    vector<int> sev_max;
    for(int i = 0; i < m_N_Cut; i++)
      sev_max.push_back(m_CutN[i]);
   
    for(int c = Nstart; c < Nend; c++){
      icut++;
      int key = c;
      bool fail = false;
      for(int i = 0; i < m_N_Cut; i++){
	int sev = key%m_CutN[i];
	// if(sev >= sev_max[i]){
	//   fail = true;
	//   break;
	// }
	key /= m_CutN[i];
	m_CutVal[i] = m_CutMin[i] + (m_CutMax[i]-m_CutMin[i])/double(m_CutN[i])*double(sev);
      }
      if(fail)
	continue;
      int failcut = EvaluateCuts();
      if(failcut > -1){
	key = c;
	for(int i = 0; i < failcut; i++)
	  key /= m_CutN[i];
	sev_max[failcut] = key%m_CutN[failcut];
	continue;
      }
      

      if(m_Signal[ifile] >= 0){
	Nsig_comb[m_Signal[ifile]][icut] += GetEventWeight();
      }
      else
	Nbkg_comb[icut] += GetEventWeight();
    } // end combinatoric cut loop
  } // end event loop

  // Create output tree;
  if(m_Tree)
    delete m_Tree;

  m_Tree = (TTree*) new TTree("optimization","optimization");
  for(int i = 0; i < m_N_Cut; i++){
    string svar = "var"+to_string(i);
    m_Tree->Branch(svar.c_str(),&(m_CutVal[i]));
  }
  double Nbkg;
  m_Tree->Branch("Nbkg",&Nbkg);
  vector<double> Nsig;
  for(int i = 0; i < m_NSIG; i++)
     Nsig.push_back(0.);
  for(int i = 0; i < m_NSIG; i++)
    m_Tree->Branch(("Nsig_"+m_SignalName[i]).c_str(),&(Nsig[i]));

  int icut = -1;
  for(int c = Nstart; c < Nend; c++){
    icut++;
    int key = c;
    for(int i = 0; i < m_N_Cut; i++){
      int sev = key%m_CutN[i];
      key /= m_CutN[i];
      m_CutVal[i] = m_CutMin[i] + (m_CutMax[i]-m_CutMin[i])/double(m_CutN[i])*double(sev);
    }
    Nbkg = Nbkg_comb[icut];
    for(int i = 0; i < m_NSIG; i++)
      Nsig[i] = Nsig_comb[i][icut];
    m_Tree->Fill();
  }
}
  
template <class Base>
void OptimizationBase<Base>::AddSignal(string filename){
  
  std::cout << "Adding signal trees from file " << filename << " :" << endl;
  cout << "   adding tree Analysis" << endl;
  TChain* chain = new TChain("CompressedAnalysis");
  chain->Add(filename.c_str());
  m_Chain->Add(chain);
  m_Signal.push_back(m_NSIG);
  string name = filename;
  while(name.find("/") != string::npos)
    name.erase(name.begin(),name.begin()+name.find("/")+1);
  if(name.find(".root") != string::npos)
    name.erase(name.find(".root"),5);
  m_SignalName.push_back(name);
  m_NSIG++;
  
}

template <class Base>
void OptimizationBase<Base>::AddBackground(string filename){
  std::cout << "Adding background trees from file " << filename << " :" << endl;
  TFile* F = new TFile(filename.c_str(),"READ");
  TObjLink* link = F->GetListOfKeys()->FirstLink();
  vector<string> treenames;
  while(link){
    string name = link->GetObject()->GetName();
    if(name.find("CompressedAnalysis") != string::npos){ 
      int Nt = treenames.size();
      bool isnew = true;
      for(int i = 0; i < Nt; i++){
	if(name.find(treenames[i]) != string::npos){
	  isnew = false;
	  break;
	}
      }
      if(isnew){
	treenames.push_back(name);
      }
    }
    link = link->Next();
  }
  F->Close();
  delete F;

  int Ntree = treenames.size();
  for(int j = 0; j < Ntree; j++){
    cout << "   adding tree " << treenames[j] << endl;
    TChain* chain = new TChain(treenames[j].c_str());
    chain->Add(filename.c_str());
    m_Chain->Add(chain);
    m_Signal.push_back(-1);
  }
  
}
  
template <class Base>
void OptimizationBase<Base>::WriteOutputFile(const string& filename){
  if(!m_Tree) return;
  TFile* file = new TFile(filename.c_str(),"RECREATE");
  file->cd();
  m_Tree->Write();
  file->Close();
  delete file;
}

template <class Base>
void OptimizationBase<Base>::InitBase(){
  if(m_Base)
    delete m_Base;
  m_Base = new Base(m_Chain);
}

template class OptimizationBase<CompressedBase>;
