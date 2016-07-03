//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Mon Jun 27 22:39:18 2016 by ROOT version 6.06/00
// from TTree CompressedAnalysis/CompressedAnalysis
// found on file: ../HIGGSINONTUPLES/C1N2_WZ_250p0_200p0_3L_2L7.root
//////////////////////////////////////////////////////////

#ifndef CompressedHiggsinoBase_h
#define CompressedHiggsinoBase_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

class CompressedHiggsinoBase {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Double_t        MET;
   Double_t        TrkMET;
   Double_t        HLT_xe70;
   Int_t           is_OS;
   Double_t        pT_1jet;
   Double_t        pT_2jet;
   Double_t        pT_3jet;
   Double_t        pT_4jet;
   Int_t           nEl;
   Int_t           nMu;
   Double_t        MT2W;
   Double_t        MT2Top;
   Double_t        mll;
   Double_t        pT_1lep;
   Int_t           id_1lep;
   Double_t        pT_2lep;
   Int_t           id_2lep;
   Double_t        pT_3lep;
   Int_t           id_3lep;
   Int_t           channel;
   Double_t        weight;
   Double_t        HT;
   Double_t        dphiMin1;
   Double_t        dphiMin2;
   Double_t        dphiMin3;
   Double_t        dphiMinAll;
   Double_t        Mbb;
   Double_t        dphiMinbl1;
   Double_t        dphiMinbl2;
   Double_t        dphiMinbl3;
   Double_t        dRMinbl1;
   Double_t        dRMinbl2;
   Double_t        dRMinbl3;
   Double_t        PTISR;
   Double_t        PTCM;
   Double_t        RISR;
   Double_t        cosS;
   Double_t        MS;
   Double_t        MISR;
   Double_t        MV;
   Double_t        MW1;
   Double_t        MW2;
   Double_t        MW3;
   Double_t        mllOS;
   Double_t        MZ;
   Double_t        dphiCMI;
   Double_t        dphiISRI;
   Double_t        dphiCML1;
   Double_t        dphiCML2;
   Double_t        dphiSL1;
   Double_t        dphiSL2;
   Double_t        cosIL1;
   Double_t        cosIL2;
   Double_t        cosIL3;
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
   Int_t           id_1lV;
   Int_t           id_2lV;
   Int_t           id_3lV;
   Int_t           id_1lISR;
   Int_t           id_2lISR;
   Int_t           id_3lISR;
  
   // List of branches
   TBranch        *b_MET;   //!
   TBranch        *b_TrkMET;   //!
   TBranch        *b_HLT_xe70;   //!
   TBranch        *b_is_OS;   //!
   TBranch        *b_pT_1jet;   //!
   TBranch        *b_pT_2jet;   //!
   TBranch        *b_pT_3jet;   //!
   TBranch        *b_pT_4jet;   //!
   TBranch        *b_nEl;   //!
   TBranch        *b_nMu;   //!
   TBranch        *b_MT2W;   //!
   TBranch        *b_MT2Top;   //!
   TBranch        *b_mll;   //!
   TBranch        *b_pT_1lep;   //!
   TBranch        *b_id_1lep;   //!
   TBranch        *b_pT_2lep;   //!
   TBranch        *b_id_2lep;   //!
   TBranch        *b_pT_3lep;   //!
   TBranch        *b_id_3lep;   //!
   TBranch        *b_channel;   //!
   TBranch        *b_weight;   //!
   TBranch        *b_HT;   //!
   TBranch        *b_dphiMin1;   //!
   TBranch        *b_dphiMin2;   //!
   TBranch        *b_dphiMin3;   //!
   TBranch        *b_dphiMinAll;   //!
   TBranch        *b_Mbb;   //!
   TBranch        *b_dphiMinbl1;   //!
   TBranch        *b_dphiMinbl2;   //!
   TBranch        *b_dphiMinbl3;   //!
   TBranch        *b_dRMinbl1;   //!
   TBranch        *b_dRMinbl2;   //!
   TBranch        *b_dRMinbl3;   //!
   TBranch        *b_PTISR;   //!
   TBranch        *b_PTCM;   //!
   TBranch        *b_RISR;   //!
   TBranch        *b_cosS;   //!
   TBranch        *b_MS;   //!
   TBranch        *b_MISR;   //!
   TBranch        *b_MV;   //!
   TBranch        *b_MW1;   //!
   TBranch        *b_MW2;   //!
   TBranch        *b_MW3;   //!
   TBranch        *b_mllOS;   //!
   TBranch        *b_MZ;   //!
   TBranch        *b_dphiCMI;   //!
   TBranch        *b_dphiISRI;   //!
   TBranch        *b_dphiCML1;   //!
   TBranch        *b_dphiCML2;   //!
   TBranch        *b_dphiSL1;   //!
   TBranch        *b_dphiSL2;   //!
   TBranch        *b_cosIL1;   //!
   TBranch        *b_cosIL2;   //!
   TBranch        *b_cosIL3;   //!
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
   TBranch        *b_id_1lV;   //!
   TBranch        *b_id_2lV;   //!
   TBranch        *b_id_3lV;   //!
   TBranch        *b_id_1lISR;   //!
   TBranch        *b_id_2lISR;   //!
   TBranch        *b_id_3lISR;   //!    

  CompressedHiggsinoBase(TTree *tree=0);
   virtual ~CompressedHiggsinoBase();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};


inline CompressedHiggsinoBase::CompressedHiggsinoBase(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("../HIGGSINONTUPLES/C1N2_WZ_250p0_200p0_3L_2L7.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("../HIGGSINONTUPLES/C1N2_WZ_250p0_200p0_3L_2L7.root");
      }
      f->GetObject("CompressedAnalysis",tree);

   }
   Init(tree);
}

inline CompressedHiggsinoBase::~CompressedHiggsinoBase()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

inline Int_t CompressedHiggsinoBase::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
inline Long64_t CompressedHiggsinoBase::LoadTree(Long64_t entry)
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

inline void CompressedHiggsinoBase::Init(TTree *tree)
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
   fChain->SetBranchAddress("HLT_xe70", &HLT_xe70, &b_HLT_xe70);
   fChain->SetBranchAddress("is_OS", &is_OS, &b_is_OS);
   fChain->SetBranchAddress("pT_1jet", &pT_1jet, &b_pT_1jet);
   fChain->SetBranchAddress("pT_2jet", &pT_2jet, &b_pT_2jet);
   fChain->SetBranchAddress("pT_3jet", &pT_3jet, &b_pT_3jet);
   fChain->SetBranchAddress("pT_4jet", &pT_4jet, &b_pT_4jet);
   fChain->SetBranchAddress("nEl", &nEl, &b_nEl);
   fChain->SetBranchAddress("nMu", &nMu, &b_nMu);
   fChain->SetBranchAddress("MT2W", &MT2W, &b_MT2W);
   fChain->SetBranchAddress("MT2Top", &MT2Top, &b_MT2Top);
   fChain->SetBranchAddress("mll", &mll, &b_mll);
   fChain->SetBranchAddress("pT_1lep", &pT_1lep, &b_pT_1lep);
   fChain->SetBranchAddress("id_1lep", &id_1lep, &b_id_1lep);
   fChain->SetBranchAddress("pT_2lep", &pT_2lep, &b_pT_2lep);
   fChain->SetBranchAddress("id_2lep", &id_2lep, &b_id_2lep);
   fChain->SetBranchAddress("pT_3lep", &pT_3lep, &b_pT_3lep);
   fChain->SetBranchAddress("id_3lep", &id_3lep, &b_id_3lep);
   fChain->SetBranchAddress("channel", &channel, &b_channel);
   fChain->SetBranchAddress("weight", &weight, &b_weight);
   fChain->SetBranchAddress("HT", &HT, &b_HT);
   fChain->SetBranchAddress("dphiMin1", &dphiMin1, &b_dphiMin1);
   fChain->SetBranchAddress("dphiMin2", &dphiMin2, &b_dphiMin2);
   fChain->SetBranchAddress("dphiMin3", &dphiMin3, &b_dphiMin3);
   fChain->SetBranchAddress("dphiMinAll", &dphiMinAll, &b_dphiMinAll);
   fChain->SetBranchAddress("Mbb", &Mbb, &b_Mbb);
   fChain->SetBranchAddress("dphiMinbl1", &dphiMinbl1, &b_dphiMinbl1);
   fChain->SetBranchAddress("dphiMinbl2", &dphiMinbl2, &b_dphiMinbl2);
   fChain->SetBranchAddress("dphiMinbl3", &dphiMinbl3, &b_dphiMinbl3);
   fChain->SetBranchAddress("dRMinbl1", &dRMinbl1, &b_dRMinbl1);
   fChain->SetBranchAddress("dRMinbl2", &dRMinbl2, &b_dRMinbl2);
   fChain->SetBranchAddress("dRMinbl3", &dRMinbl3, &b_dRMinbl3);
   fChain->SetBranchAddress("PTISR", &PTISR, &b_PTISR);
   fChain->SetBranchAddress("PTCM", &PTCM, &b_PTCM);
   fChain->SetBranchAddress("RISR", &RISR, &b_RISR);
   fChain->SetBranchAddress("cosS", &cosS, &b_cosS);
   fChain->SetBranchAddress("MS", &MS, &b_MS);
   fChain->SetBranchAddress("MISR", &MISR, &b_MISR);
   fChain->SetBranchAddress("MV", &MV, &b_MV);
   fChain->SetBranchAddress("MW1", &MW1, &b_MW1);
   fChain->SetBranchAddress("MW2", &MW2, &b_MW2);
   fChain->SetBranchAddress("MW3", &MW3, &b_MW3);
   fChain->SetBranchAddress("mllOS", &mllOS, &b_mllOS);
   fChain->SetBranchAddress("MZ", &MZ, &b_MZ);
   fChain->SetBranchAddress("dphiCMI", &dphiCMI, &b_dphiCMI);
   fChain->SetBranchAddress("dphiISRI", &dphiISRI, &b_dphiISRI);
   fChain->SetBranchAddress("dphiCML1", &dphiCML1, &b_dphiCML1);
   fChain->SetBranchAddress("dphiCML2", &dphiCML2, &b_dphiCML2);
   fChain->SetBranchAddress("dphiSL1", &dphiSL1, &b_dphiSL1);
   fChain->SetBranchAddress("dphiSL2", &dphiSL2, &b_dphiSL2);
   fChain->SetBranchAddress("cosIL1", &cosIL1, &b_cosIL1);
   fChain->SetBranchAddress("cosIL2", &cosIL2, &b_cosIL2);
   fChain->SetBranchAddress("cosIL3", &cosIL3, &b_cosIL3);
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
   fChain->SetBranchAddress("id_1lV", &id_1lV, &b_id_1lV);
   fChain->SetBranchAddress("id_2lV", &id_2lV, &b_id_2lV);
   fChain->SetBranchAddress("id_3lV", &id_3lV, &b_id_3lV);
   fChain->SetBranchAddress("id_1lISR", &id_1lISR, &b_id_1lISR);
   fChain->SetBranchAddress("id_2lISR", &id_2lISR, &b_id_2lISR);
   fChain->SetBranchAddress("id_3lISR", &id_3lISR, &b_id_3lISR);
   Notify();
}

inline Bool_t CompressedHiggsinoBase::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

inline void CompressedHiggsinoBase::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
inline Int_t CompressedHiggsinoBase::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef CompressedHiggsinoBase_cxx
