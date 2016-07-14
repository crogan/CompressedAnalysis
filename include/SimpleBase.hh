//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Jul 13 22:57:35 2016 by ROOT version 6.06/00
// from TTree outputTree/output tree
// found on file: SignalSamples/155_150_smear.root
//////////////////////////////////////////////////////////

#ifndef SimpleBase_h
#define SimpleBase_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include "vector"
#include "vector"

using namespace std;

class SimpleBase {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Double_t        mll;
   Double_t        MET;
   Double_t        MET_phi;
   Double_t        DPhi_METJetLeading;
   Double_t        DPhi_METJetSecond;
   Double_t        HT;
   Double_t        Z_pt;
   Double_t        Z_eta;
   Double_t        Z_phi;
   Int_t           channel;
   Int_t           is_OS;
   vector<int>     *lep_pdgId;
   vector<float>   *lep_E;
   vector<float>   *lep_pT;
   vector<float>   *lep_eta;
   vector<float>   *lep_phi;
   vector<float>   *jet_E;
   vector<float>   *jet_pT;
   vector<float>   *jet_eta;
   vector<float>   *jet_phi;

   // List of branches
   TBranch        *b_mll;   //!
   TBranch        *b_MET;   //!
   TBranch        *b_MET_phi;   //!
   TBranch        *b_DPhi_METJetLeading;   //!
   TBranch        *b_DPhi_METJetSecond;   //!
   TBranch        *b_HT;   //!
   TBranch        *b_Z_pt;   //!
   TBranch        *b_Z_eta;   //!
   TBranch        *b_Z_phi;   //!
   TBranch        *b_channel;   //!
   TBranch        *b_is_OS;   //!
   TBranch        *b_lep_pdgId;   //!
   TBranch        *b_lep_E;   //!
   TBranch        *b_lep_pT;   //!
   TBranch        *b_lep_eta;   //!
   TBranch        *b_lep_phi;   //!
   TBranch        *b_jet_E;   //!
   TBranch        *b_jet_pT;   //!
   TBranch        *b_jet_eta;   //!
   TBranch        *b_jet_phi;   //!

   SimpleBase(TTree *tree=0);
   virtual ~SimpleBase();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

inline SimpleBase::SimpleBase(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("SignalSamples/155_150_smear.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("SignalSamples/155_150_smear.root");
      }
      f->GetObject("outputTree",tree);

   }
   Init(tree);
}

#endif

inline SimpleBase::~SimpleBase()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

inline Int_t SimpleBase::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
inline Long64_t SimpleBase::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

inline void SimpleBase::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   lep_pdgId = 0;
   lep_E = 0;
   lep_pT = 0;
   lep_eta = 0;
   lep_phi = 0;
   jet_E = 0;
   jet_pT = 0;
   jet_eta = 0;
   jet_phi = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("mll", &mll, &b_mll);
   fChain->SetBranchAddress("MET", &MET, &b_MET);
   fChain->SetBranchAddress("MET_phi", &MET_phi, &b_MET_phi);
   fChain->SetBranchAddress("DPhi_METJetLeading", &DPhi_METJetLeading, &b_DPhi_METJetLeading);
   fChain->SetBranchAddress("DPhi_METJetSecond", &DPhi_METJetSecond, &b_DPhi_METJetSecond);
   fChain->SetBranchAddress("HT", &HT, &b_HT);
   fChain->SetBranchAddress("Z_pt", &Z_pt, &b_Z_pt);
   fChain->SetBranchAddress("Z_eta", &Z_eta, &b_Z_eta);
   fChain->SetBranchAddress("Z_phi", &Z_phi, &b_Z_phi);
   fChain->SetBranchAddress("channel", &channel, &b_channel);
   fChain->SetBranchAddress("is_OS", &is_OS, &b_is_OS);
   fChain->SetBranchAddress("lep_pdgId", &lep_pdgId, &b_lep_pdgId);
   fChain->SetBranchAddress("lep_E", &lep_E, &b_lep_E);
   fChain->SetBranchAddress("lep_pT", &lep_pT, &b_lep_pT);
   fChain->SetBranchAddress("lep_eta", &lep_eta, &b_lep_eta);
   fChain->SetBranchAddress("lep_phi", &lep_phi, &b_lep_phi);
   fChain->SetBranchAddress("jet_E", &jet_E, &b_jet_E);
   fChain->SetBranchAddress("jet_pT", &jet_pT, &b_jet_pT);
   fChain->SetBranchAddress("jet_eta", &jet_eta, &b_jet_eta);
   fChain->SetBranchAddress("jet_phi", &jet_phi, &b_jet_phi);
   Notify();
}

inline Bool_t SimpleBase::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

inline void SimpleBase::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
inline Int_t SimpleBase::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}

