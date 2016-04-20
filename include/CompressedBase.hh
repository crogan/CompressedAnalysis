//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Apr 20 09:51:11 2016 by ROOT version 5.34/25
// from TTree CompressedAnalysis/CompressedAnalysis
// found on file: CompressedNtuple.root
//////////////////////////////////////////////////////////

#ifndef CompressedBase_h
#define CompressedBase_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

// Fixed size dimensions of array or collections stored in the TTree if any.

class CompressedBase {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   Double_t        weight;
   Double_t        MET;
   Double_t        TrkMET;
   Double_t        dphi_MET_TrkMET;
   Bool_t          HLT_xe70_tc_lcw;
   Double_t        dphiMin1;
   Double_t        dphiMin2;
   Double_t        dphiMin3;
   Double_t        dphiMinAll;
   Bool_t          LepVeto;
   Bool_t          TauVeto;
   Double_t        PTISR;
   Double_t        RISR;
   Double_t        cosS;
   Double_t        MS;
   Double_t        MISR;
   Double_t        MV;
   Double_t        dphiCMI;
   Double_t        dphiISRI;
   Double_t        pTjV1;
   Double_t        pTjV2;
   Double_t        pTjV3;
   Double_t        pTjV4;
   Double_t        pTjV5;
   Double_t        pTjV6;
   Double_t        pTbV1;
   Double_t        pTbV2;
   Int_t           NbV;
   Int_t           NbISR;
   Int_t           NjV;
   Int_t           NjISR;

   // List of branches
   TBranch        *b_weight;   //!
   TBranch        *b_MET;   //!
   TBranch        *b_TrkMET;   //!
   TBranch        *b_dphi_MET_TrkMET;   //!
   TBranch        *b_HLT_xe70_tc_lcw;   //!
   TBranch        *b_dphiMin1;   //!
   TBranch        *b_dphiMin2;   //!
   TBranch        *b_dphiMin3;   //!
   TBranch        *b_dphiMinAll;   //!
   TBranch        *b_LepVeto;   //!
   TBranch        *b_TauVeto;   //!
   TBranch        *b_PTISR;   //!
   TBranch        *b_RISR;   //!
   TBranch        *b_cosS;   //!
   TBranch        *b_MS;   //!
   TBranch        *b_MISR;   //!
   TBranch        *b_MV;   //!
   TBranch        *b_dphiCMI;   //!
   TBranch        *b_dphiISRI;   //!
   TBranch        *b_pTjV1;   //!
   TBranch        *b_pTjV2;   //!
   TBranch        *b_pTjV3;   //!
   TBranch        *b_pTjV4;   //!
   TBranch        *b_pTjV5;   //!
   TBranch        *b_pTjV6;   //!
   TBranch        *b_pTbV1;   //!
   TBranch        *b_pTbV2;   //!
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
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("CompressedNtuple.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("CompressedNtuple.root");
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
   fChain->SetBranchAddress("TrkMET", &TrkMET, &b_TrkMET);
   fChain->SetBranchAddress("dphi_MET_TrkMET", &dphi_MET_TrkMET, &b_dphi_MET_TrkMET);
   fChain->SetBranchAddress("HLT_xe70_tc_lcw", &HLT_xe70_tc_lcw, &b_HLT_xe70_tc_lcw);
   fChain->SetBranchAddress("dphiMin1", &dphiMin1, &b_dphiMin1);
   fChain->SetBranchAddress("dphiMin2", &dphiMin2, &b_dphiMin2);
   fChain->SetBranchAddress("dphiMin3", &dphiMin3, &b_dphiMin3);
   fChain->SetBranchAddress("dphiMinAll", &dphiMinAll, &b_dphiMinAll);
   fChain->SetBranchAddress("LepVeto", &LepVeto, &b_LepVeto);
   fChain->SetBranchAddress("TauVeto", &TauVeto, &b_TauVeto);
   fChain->SetBranchAddress("PTISR", &PTISR, &b_PTISR);
   fChain->SetBranchAddress("RISR", &RISR, &b_RISR);
   fChain->SetBranchAddress("cosS", &cosS, &b_cosS);
   fChain->SetBranchAddress("MS", &MS, &b_MS);
   fChain->SetBranchAddress("MISR", &MISR, &b_MISR);
   fChain->SetBranchAddress("MV", &MV, &b_MV);
   fChain->SetBranchAddress("dphiCMI", &dphiCMI, &b_dphiCMI);
   fChain->SetBranchAddress("dphiISRI", &dphiISRI, &b_dphiISRI);
   fChain->SetBranchAddress("pTjV1", &pTjV1, &b_pTjV1);
   fChain->SetBranchAddress("pTjV2", &pTjV2, &b_pTjV2);
   fChain->SetBranchAddress("pTjV3", &pTjV3, &b_pTjV3);
   fChain->SetBranchAddress("pTjV4", &pTjV4, &b_pTjV4);
   fChain->SetBranchAddress("pTjV5", &pTjV5, &b_pTjV5);
   fChain->SetBranchAddress("pTjV6", &pTjV6, &b_pTjV6);
   fChain->SetBranchAddress("pTbV1", &pTbV1, &b_pTbV1);
   fChain->SetBranchAddress("pTbV2", &pTbV2, &b_pTbV2);
   fChain->SetBranchAddress("NbV", &NbV, &b_NbV);
   fChain->SetBranchAddress("NbISR", &NbISR, &b_NbISR);
   fChain->SetBranchAddress("NjV", &NjV, &b_NjV);
   fChain->SetBranchAddress("NjISR", &NjISR, &b_NjISR);
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

