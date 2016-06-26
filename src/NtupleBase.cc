#include <TFile.h>

#include "NtupleBase.hh"
#include "HFntupleBase.hh"
#include "SussexBase.hh"
#include "HiggsinoBase.hh"

template <class Base>
NtupleBase<Base>::NtupleBase(TTree* tree)
  : AnalysisBase<Base>(tree)
{
  m_Tree = nullptr;
}

template <class Base>
NtupleBase<Base>::~NtupleBase(){
  if(m_Tree)
    delete m_Tree;
}

template <class Base>
void NtupleBase<Base>::WriteNtuple(const string& filename){
  TFile* outfile = new TFile(filename.c_str(),"UPDATE");
  outfile->cd();
  InitOutputTree();
  Long64_t N = Base::fChain->GetEntries();
  for(Long64_t i = 0; i < N; i++){
    int mymod = N/10;
    if(mymod < 1)
      mymod = 1;
    if(i%mymod == 0)
      cout << " event = " << i << " : " << N << endl;
    
    AnalysisBase<Base>::GetEntry(i);
    outfile->cd();
    FillOutputTree();
  }
  m_Tree->Write("",TObject::kOverwrite);
  delete m_Tree;
  m_Tree = nullptr;
  outfile->Close();
  delete outfile;
}

template class NtupleBase<HFntupleBase>;
template class NtupleBase<SussexBase>;
template class NtupleBase<HiggsinoBase>;


