//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue May 24 23:51:15 2016 by ROOT version 5.34/34
// from TTree CompressedAnalysis/CompressedAnalysis
// found on file: BKG/ttbar.root
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
   Double_t        MET;
   Double_t        TrkMET;
   Double_t        dphi_MET_TrkMET;
   Bool_t          HLT_xe70_tc_lcw;
   Double_t        pT_1jet;
   Double_t        pT_2jet;
   Double_t        pT_3jet;
   Double_t        pT_4jet;
   Double_t        mj0_12;
   Double_t        mj1_12;
   Bool_t          LepVeto;
   Bool_t          TauVeto;
   Int_t           nEl;
   Int_t           nMu;
   Double_t        MT;
   Double_t        pT_1lep;
   Double_t        pT_2lep;
   Double_t        weight;
   Double_t        HT;
   Double_t        dphiMin1;
   Double_t        dphiMin2;
   Double_t        dphiMin3;
   Double_t        dphiMinAll;
   Double_t        Mbb;
   Double_t        dRMinbl1;
   Double_t        dRMinbl2;
   Double_t        PTISR;
   Double_t        PTCM;
   Double_t        RISR;
   Double_t        cosS;
   Double_t        MS;
   Double_t        MISR;
   Double_t        MV;
   Double_t        MW1;
   Double_t        MW2;
   Double_t        dphiCMI;
   Double_t        dphiISRI;
   Double_t        dphiCML1;
   Double_t        dphiCML2;
   Double_t        cosIL1;
   Double_t        cosIL2;
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
   Int_t           NlV;
   Int_t           NlISR;

   // List of branches
   TBranch        *b_MET;   //!
   TBranch        *b_TrkMET;   //!
   TBranch        *b_dphi_MET_TrkMET;   //!
   TBranch        *b_HLT_xe70_tc_lcw;   //!
   TBranch        *b_pT_1jet;   //!
   TBranch        *b_pT_2jet;   //!
   TBranch        *b_pT_3jet;   //!
   TBranch        *b_pT_4jet;   //!
   TBranch        *b_mj0_12;   //!
   TBranch        *b_mj1_12;   //!
   TBranch        *b_LepVeto;   //!
   TBranch        *b_TauVeto;   //!
   TBranch        *b_nEl;   //!
   TBranch        *b_nMu;   //!
   TBranch        *b_MT;   //!
   TBranch        *b_pT_1lep;   //!
   TBranch        *b_pT_2lep;   //!
   TBranch        *b_weight;   //!
   TBranch        *b_HT;   //!
   TBranch        *b_dphiMin1;   //!
   TBranch        *b_dphiMin2;   //!
   TBranch        *b_dphiMin3;   //!
   TBranch        *b_dphiMinAll;   //!
   TBranch        *b_Mbb;   //!
   TBranch        *b_dRMinbl1;   //!
   TBranch        *b_dRMinbl2;   //!
   TBranch        *b_PTISR;   //!
   TBranch        *b_PTCM;   //!
   TBranch        *b_RISR;   //!
   TBranch        *b_cosS;   //!
   TBranch        *b_MS;   //!
   TBranch        *b_MISR;   //!
   TBranch        *b_MV;   //!
   TBranch        *b_MW1;   //!
   TBranch        *b_MW2;   //!
   TBranch        *b_dphiCMI;   //!
   TBranch        *b_dphiISRI;   //!
   TBranch        *b_dphiCML1;   //!
   TBranch        *b_dphiCML2;   //!
   TBranch        *b_cosIL1;   //!
   TBranch        *b_cosIL2;   //!
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
   TBranch        *b_NlV;   //!
   TBranch        *b_NlISR;   //!

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
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("BKG/ttbar.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("BKG/ttbar.root");
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

   fChain->SetBranchAddress("MET", &MET, &b_MET);
   fChain->SetBranchAddress("TrkMET", &TrkMET, &b_TrkMET);
   fChain->SetBranchAddress("dphi_MET_TrkMET", &dphi_MET_TrkMET, &b_dphi_MET_TrkMET);
   fChain->SetBranchAddress("HLT_xe70_tc_lcw", &HLT_xe70_tc_lcw, &b_HLT_xe70_tc_lcw);
   fChain->SetBranchAddress("pT_1jet", &pT_1jet, &b_pT_1jet);
   fChain->SetBranchAddress("pT_2jet", &pT_2jet, &b_pT_2jet);
   fChain->SetBranchAddress("pT_3jet", &pT_3jet, &b_pT_3jet);
   fChain->SetBranchAddress("pT_4jet", &pT_4jet, &b_pT_4jet);
   fChain->SetBranchAddress("mj0_12", &mj0_12, &b_mj0_12);
   fChain->SetBranchAddress("mj1_12", &mj1_12, &b_mj1_12);
   fChain->SetBranchAddress("LepVeto", &LepVeto, &b_LepVeto);
   fChain->SetBranchAddress("TauVeto", &TauVeto, &b_TauVeto);
   fChain->SetBranchAddress("nEl", &nEl, &b_nEl);
   fChain->SetBranchAddress("nMu", &nMu, &b_nMu);
   fChain->SetBranchAddress("MT", &MT, &b_MT);
   fChain->SetBranchAddress("pT_1lep", &pT_1lep, &b_pT_1lep);
   fChain->SetBranchAddress("pT_2lep", &pT_2lep, &b_pT_2lep);
   fChain->SetBranchAddress("weight", &weight, &b_weight);
   fChain->SetBranchAddress("HT", &HT, &b_HT);
   fChain->SetBranchAddress("dphiMin1", &dphiMin1, &b_dphiMin1);
   fChain->SetBranchAddress("dphiMin2", &dphiMin2, &b_dphiMin2);
   fChain->SetBranchAddress("dphiMin3", &dphiMin3, &b_dphiMin3);
   fChain->SetBranchAddress("dphiMinAll", &dphiMinAll, &b_dphiMinAll);
   fChain->SetBranchAddress("Mbb", &Mbb, &b_Mbb);
   fChain->SetBranchAddress("dRMinbl1", &dRMinbl1, &b_dRMinbl1);
   fChain->SetBranchAddress("dRMinbl2", &dRMinbl2, &b_dRMinbl2);
   fChain->SetBranchAddress("PTISR", &PTISR, &b_PTISR);
   fChain->SetBranchAddress("PTCM", &PTCM, &b_PTCM);
   fChain->SetBranchAddress("RISR", &RISR, &b_RISR);
   fChain->SetBranchAddress("cosS", &cosS, &b_cosS);
   fChain->SetBranchAddress("MS", &MS, &b_MS);
   fChain->SetBranchAddress("MISR", &MISR, &b_MISR);
   fChain->SetBranchAddress("MV", &MV, &b_MV);
   fChain->SetBranchAddress("MW1", &MW1, &b_MW1);
   fChain->SetBranchAddress("MW2", &MW2, &b_MW2);
   fChain->SetBranchAddress("dphiCMI", &dphiCMI, &b_dphiCMI);
   fChain->SetBranchAddress("dphiISRI", &dphiISRI, &b_dphiISRI);
   fChain->SetBranchAddress("dphiCML1", &dphiCML1, &b_dphiCML1);
   fChain->SetBranchAddress("dphiCML2", &dphiCML2, &b_dphiCML2);
   fChain->SetBranchAddress("cosIL1", &cosIL1, &b_cosIL1);
   fChain->SetBranchAddress("cosIL2", &cosIL2, &b_cosIL2);
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
   fChain->SetBranchAddress("NlV", &NlV, &b_NlV);
   fChain->SetBranchAddress("NlISR", &NlISR, &b_NlISR);
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

