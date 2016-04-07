//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Apr  6 21:26:32 2016 by ROOT version 5.34/34
// from TTree CompressedAnalysis/CompressedAnalysis
// found on file: NTUPLES/TT_500_327.root
//////////////////////////////////////////////////////////

#ifndef CompressedBase_h
#define CompressedBase_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

using namespace std;

class CompressedBase {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   Double_t        weight;
   Double_t        MET;
   Bool_t          LepVeto;
   Double_t        PTISR[5];
   Double_t        PIoPTISR[5];
   Double_t        cosS[5];
   Double_t        MS[5];
   Double_t        MISR[5];
   Double_t        MV[5];
   Double_t        dphiCMV[5];
   Int_t           NbV[5];
   Int_t           NbISR[5];
   Int_t           NjV[5];
   Int_t           NjISR[5];

   // List of branches
   TBranch        *b_weight;   //!
   TBranch        *b_MET;   //!
   TBranch        *b_LepVeto;   //!
   TBranch        *b_PTISR;   //!
   TBranch        *b_PIoPTISR;   //!
   TBranch        *b_cosS;   //!
   TBranch        *b_MS;   //!
   TBranch        *b_MISR;   //!
   TBranch        *b_MV;   //!
   TBranch        *b_dphiCMV;   //!
   TBranch        *b_NbV;   //!
   TBranch        *b_NbISR;   //!
   TBranch        *b_NjV;   //!
   TBranch        *b_NjISR;   //!

   CompressedBase(TTree *tree=0);
   virtual ~CompressedBase();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif


inline CompressedBase::CompressedBase(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("NTUPLES/TT_500_327.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("NTUPLES/TT_500_327.root");
      }
      f->GetObject("CompressedAnalysis",tree);

   }
   Init(tree);
}

inline CompressedBase::~CompressedBase()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

inline Int_t CompressedBase::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
inline Long64_t CompressedBase::LoadTree(Long64_t entry)
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

inline void CompressedBase::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("weight", &weight, &b_weight);
   fChain->SetBranchAddress("MET", &MET, &b_MET);
   fChain->SetBranchAddress("LepVeto", &LepVeto, &b_LepVeto);
   fChain->SetBranchAddress("PTISR", PTISR, &b_PTISR);
   fChain->SetBranchAddress("PIoPTISR", PIoPTISR, &b_PIoPTISR);
   fChain->SetBranchAddress("cosS", cosS, &b_cosS);
   fChain->SetBranchAddress("MS", MS, &b_MS);
   fChain->SetBranchAddress("MISR", MISR, &b_MISR);
   fChain->SetBranchAddress("MV", MV, &b_MV);
   fChain->SetBranchAddress("dphiCMV", dphiCMV, &b_dphiCMV);
   fChain->SetBranchAddress("NbV", NbV, &b_NbV);
   fChain->SetBranchAddress("NbISR", NbISR, &b_NbISR);
   fChain->SetBranchAddress("NjV", NjV, &b_NjV);
   fChain->SetBranchAddress("NjISR", NjISR, &b_NjISR);
   Notify();
}

inline Bool_t CompressedBase::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

inline void CompressedBase::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
inline Int_t CompressedBase::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}

