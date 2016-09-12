//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue Aug 16 19:46:28 2016 by ROOT version 6.04/16
// from TTree tree_NoSys/tree_NoSys
// found on file: TestDir_T_06_03/data-tree/mc15_13TeV.371580.MGPy8EG_A14N_GG_onestepCC_1025_705_385.merge.DAOD_SUSY5.e4039_a766_a821_r7676_p2666.root
//////////////////////////////////////////////////////////

#ifndef Incl1LBase_h
#define Incl1LBase_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

class Incl1LBase {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Int_t           nLep_base;
   Int_t           nLep_signal;
   Float_t         mu;
   Int_t           AnalysisType;
   Int_t           AnalysisType_lep2;
   Int_t           AnalysisType_lep3;
   Int_t           AnalysisType_lep4;
   Int_t           lep1Charge;
   Int_t           lep2Charge;
   Int_t           lep3Charge;
   Int_t           lep4Charge;
   Bool_t          singleLepTrig;
   Bool_t          isBadMuon;
   Float_t         muQOverP;
   Float_t         muQOverPErr;
   Int_t           muQuality;
   Int_t           nVtx;
   Int_t           nJet30;
   Int_t           nBJet30_MV2c10;
   Int_t           DecayModeTTbar;
   Float_t         met;
   Float_t         metPhi;
   Float_t         mt;
   Float_t         meffInc30;
   Float_t         Ht30;
   Float_t         lep1Pt;
   Float_t         lep1Eta;
   Float_t         lep1Phi;
   Int_t           lep1Type;
   Int_t           lep1Origin;
   Bool_t          lep1IsoTight;
   Float_t         lep2Pt;
   Float_t         lep2Eta;
   Float_t         lep2Phi;
   Int_t           lep2Type;
   Int_t           lep2Origin;
   Bool_t          lep2IsoTight;
   Float_t         lep3Pt;
   Float_t         lep3Eta;
   Float_t         lep3Phi;
   Int_t           lep3Type;
   Int_t           lep3Origin;
   Bool_t          lep3IsoTight;
   Float_t         lep4Pt;
   Float_t         lep4Eta;
   Float_t         lep4Phi;
   Int_t           lep4Type;
   Int_t           lep4Origin;
   Bool_t          lep4IsoTight;
   Float_t         LepAplanarity;
   Float_t         JetAplanarity;
   Float_t         jet1Pt;
   Float_t         jet2Pt;
   Float_t         jet3Pt;
   Float_t         jet4Pt;
   Float_t         jet5Pt;
   Float_t         jet6Pt;
   Float_t         jet7Pt;
   Float_t         jet8Pt;
   Float_t         jet1Eta;
   Float_t         jet2Eta;
   Float_t         jet3Eta;
   Float_t         jet4Eta;
   Float_t         jet5Eta;
   Float_t         jet6Eta;
   Float_t         jet7Eta;
   Float_t         jet8Eta;
   Float_t         jet1Phi;
   Float_t         jet2Phi;
   Float_t         jet3Phi;
   Float_t         jet4Phi;
   Float_t         jet5Phi;
   Float_t         jet6Phi;
   Float_t         jet7Phi;
   Float_t         jet8Phi;
   Float_t         jet1E;
   Float_t         jet2E;
   Float_t         jet3E;
   Float_t         jet4E;
   Float_t         jet5E;
   Float_t         jet6E;
   Float_t         jet7E;
   Float_t         jet8E;
   Float_t         jet1Mv2c10;
   Float_t         jet2Mv2c10;
   Float_t         jet3Mv2c10;
   Float_t         jet4Mv2c10;
   Float_t         jet5Mv2c10;
   Float_t         jet6Mv2c10;
   Float_t         jet7Mv2c10;
   Float_t         jet8Mv2c10;
   Float_t         amt2;
   Float_t         amt2b;
   Float_t         amt2bWeight;
   Float_t         mt2tau;
   Float_t         mt2lj;
   Float_t         topNess;
   Double_t        pileupWeight;
   Double_t        leptonWeight;
   Double_t        triggerWeight;
   Double_t        eventWeight;
   Double_t        jvtWeight;
   Double_t        bTagWeight;
   Double_t        genWeight;
   Double_t        genWeightUp;
   Double_t        genWeightDown;
   Double_t        SherpaVjetsNjetsWeight;
   Float_t         truthTopPt;
   Float_t         truthAntiTopPt;
   Float_t         truthTtbarPt;
   Float_t         truthTtbarM;
   ULong64_t       PRWHash;
   ULong64_t       EventNumber;
   Float_t         xsec;
   Float_t         TrueHt;
   Int_t           DatasetNumber;
   Int_t           RunNumber;
   Int_t           FS;

   // List of branches
   TBranch        *b_nLep_base;   //!
   TBranch        *b_nLep_signal;   //!
   TBranch        *b_mu;   //!
   TBranch        *b_AnalysisType;   //!
   TBranch        *b_AnalysisType_lep2;   //!
   TBranch        *b_AnalysisType_lep3;   //!
   TBranch        *b_AnalysisType_lep4;   //!
   TBranch        *b_lep1Charge;   //!
   TBranch        *b_lep2Charge;   //!
   TBranch        *b_lep3Charge;   //!
   TBranch        *b_lep4Charge;   //!
   TBranch        *b_singleLepTrig;   //!
   TBranch        *b_isBadMuon;   //!
   TBranch        *b_muQOverP;   //!
   TBranch        *b_muQOverPErr;   //!
   TBranch        *b_muQuality;   //!
   TBranch        *b_nVtx;   //!
   TBranch        *b_nJet30;   //!
   TBranch        *b_nBJet30_MV2c10;   //!
   TBranch        *b_DecayModeTTbar;   //!
   TBranch        *b_met;   //!
   TBranch        *b_metPhi;   //!   
   TBranch        *b_mt;   //!
   TBranch        *b_meffInc30;   //!
   TBranch        *b_Ht30;   //!
   TBranch        *b_lep1Pt;   //!
   TBranch        *b_lep1Eta;   //!
   TBranch        *b_lep1Phi;   //!
   TBranch        *b_lep1Type;   //!
   TBranch        *b_lep1Origin;   //!
   TBranch        *b_lep1IsoTight;   //!
   TBranch        *b_lep2Pt;   //!
   TBranch        *b_lep2Eta;   //!
   TBranch        *b_lep2Phi;   //!
   TBranch        *b_lep2Type;   //!
   TBranch        *b_lep2Origin;   //!
   TBranch        *b_lep2IsoTight;   //!
   TBranch        *b_lep3Pt;   //!
   TBranch        *b_lep3Eta;   //!
   TBranch        *b_lep3Phi;   //!
   TBranch        *b_lep3Type;   //!
   TBranch        *b_lep3Origin;   //!
   TBranch        *b_lep3IsoTight;   //!
   TBranch        *b_lep4Pt;   //!
   TBranch        *b_lep4Eta;   //!
   TBranch        *b_lep4Phi;   //!
   TBranch        *b_lep4Type;   //!
   TBranch        *b_lep4Origin;   //!
   TBranch        *b_lep4IsoTight;   //!
   TBranch        *b_LepAplanarity;   //!
   TBranch        *b_JetAplanarity;   //!
   TBranch        *b_jet1Pt;   //!
   TBranch        *b_jet2Pt;   //!
   TBranch        *b_jet3Pt;   //!
   TBranch        *b_jet4Pt;   //!
   TBranch        *b_jet5Pt;   //!
   TBranch        *b_jet6Pt;   //!
   TBranch        *b_jet7Pt;   //!
   TBranch        *b_jet8Pt;   //!
   TBranch        *b_jet1Eta;   //!
   TBranch        *b_jet2Eta;   //!
   TBranch        *b_jet3Eta;   //!
   TBranch        *b_jet4Eta;   //!
   TBranch        *b_jet5Eta;   //!
   TBranch        *b_jet6Eta;   //!
   TBranch        *b_jet7Eta;   //!
   TBranch        *b_jet8Eta;   //!
   TBranch        *b_jet1Phi;   //!
   TBranch        *b_jet2Phi;   //!
   TBranch        *b_jet3Phi;   //!
   TBranch        *b_jet4Phi;   //!
   TBranch        *b_jet5Phi;   //!
   TBranch        *b_jet6Phi;   //!
   TBranch        *b_jet7Phi;   //!
   TBranch        *b_jet8Phi;   //!
   TBranch        *b_jet1E;   //!
   TBranch        *b_jet2E;   //!
   TBranch        *b_jet3E;   //!
   TBranch        *b_jet4E;   //!
   TBranch        *b_jet5E;   //!
   TBranch        *b_jet6E;   //!
   TBranch        *b_jet7E;   //!
   TBranch        *b_jet8E;   //!
   TBranch        *b_jet1Mv2c10;   //!
   TBranch        *b_jet2Mv2c10;   //!
   TBranch        *b_jet3Mv2c10;   //!
   TBranch        *b_jet4Mv2c10;   //!
   TBranch        *b_jet5Mv2c10;   //!
   TBranch        *b_jet6Mv2c10;   //!
   TBranch        *b_jet7Mv2c10;   //!
   TBranch        *b_jet8Mv2c10;   //!
   TBranch        *b_amt2;   //!
   TBranch        *b_amt2b;   //!
   TBranch        *b_amt2bWeight;   //!
   TBranch        *b_mt2tau;   //!
   TBranch        *b_mt2lj;   //!
   TBranch        *b_topNess;   //!
   TBranch        *b_pileupWeight;   //!
   TBranch        *b_leptonWeight;   //!
   TBranch        *b_triggerWeight;   //!
   TBranch        *b_eventWeight;   //!
   TBranch        *b_jvtWeight;   //!
   TBranch        *b_bTagWeight;   //!
   TBranch        *b_genWeight;   //!
   TBranch        *b_genWeightUp;   //!
   TBranch        *b_genWeightDown;   //!
   TBranch        *b_SherpaVjetsNjetsWeight;   //!
   TBranch        *b_truthTopPt;   //!
   TBranch        *b_truthAntiTopPt;   //!
   TBranch        *b_truthTtbarPt;   //!
   TBranch        *b_truthTtbarM;   //!
   TBranch        *b_PRWHash;   //!
   TBranch        *b_EventNumber;   //!
   TBranch        *b_xsec;   //!
   TBranch        *b_TrueHt;   //!
   TBranch        *b_DatasetNumber;   //!
   TBranch        *b_RunNumber;   //!
   TBranch        *b_FS;   //!

   Incl1LBase(TTree *tree=0);
   virtual ~Incl1LBase();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
  //virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef Incl1LBase_cxx
Incl1LBase::Incl1LBase(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("TestDir_T_06_03/data-tree/mc15_13TeV.371580.MGPy8EG_A14N_GG_onestepCC_1025_705_385.merge.DAOD_SUSY5.e4039_a766_a821_r7676_p2666.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("TestDir_T_06_03/data-tree/mc15_13TeV.371580.MGPy8EG_A14N_GG_onestepCC_1025_705_385.merge.DAOD_SUSY5.e4039_a766_a821_r7676_p2666.root");
      }
      f->GetObject("tree_NoSys",tree);

   }
   Init(tree);
}

Incl1LBase::~Incl1LBase()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t Incl1LBase::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t Incl1LBase::LoadTree(Long64_t entry)
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

void Incl1LBase::Init(TTree *tree)
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

   fChain->SetBranchAddress("nLep_base", &nLep_base, &b_nLep_base);
   fChain->SetBranchAddress("nLep_signal", &nLep_signal, &b_nLep_signal);
   fChain->SetBranchAddress("mu", &mu, &b_mu);
   fChain->SetBranchAddress("AnalysisType", &AnalysisType, &b_AnalysisType);
   fChain->SetBranchAddress("AnalysisType_lep2", &AnalysisType_lep2, &b_AnalysisType_lep2);
   fChain->SetBranchAddress("AnalysisType_lep3", &AnalysisType_lep3, &b_AnalysisType_lep3);
   fChain->SetBranchAddress("AnalysisType_lep4", &AnalysisType_lep4, &b_AnalysisType_lep4);
   fChain->SetBranchAddress("lep1Charge", &lep1Charge, &b_lep1Charge);
   fChain->SetBranchAddress("lep2Charge", &lep2Charge, &b_lep2Charge);
   fChain->SetBranchAddress("lep3Charge", &lep3Charge, &b_lep3Charge);
   fChain->SetBranchAddress("lep4Charge", &lep4Charge, &b_lep4Charge);
   fChain->SetBranchAddress("singleLepTrig", &singleLepTrig, &b_singleLepTrig);
   fChain->SetBranchAddress("isBadMuon", &isBadMuon, &b_isBadMuon);
   fChain->SetBranchAddress("muQOverP", &muQOverP, &b_muQOverP);
   fChain->SetBranchAddress("muQOverPErr", &muQOverPErr, &b_muQOverPErr);
   fChain->SetBranchAddress("muQuality", &muQuality, &b_muQuality);
   fChain->SetBranchAddress("nVtx", &nVtx, &b_nVtx);
   fChain->SetBranchAddress("nJet30", &nJet30, &b_nJet30);
   fChain->SetBranchAddress("nBJet30_MV2c10", &nBJet30_MV2c10, &b_nBJet30_MV2c10);
   fChain->SetBranchAddress("DecayModeTTbar", &DecayModeTTbar, &b_DecayModeTTbar);
   fChain->SetBranchAddress("met", &met, &b_met);
   fChain->SetBranchAddress("metPhi", &metPhi, &b_metPhi);
   fChain->SetBranchAddress("mt", &mt, &b_mt);
   fChain->SetBranchAddress("meffInc30", &meffInc30, &b_meffInc30);
   fChain->SetBranchAddress("Ht30", &Ht30, &b_Ht30);
   fChain->SetBranchAddress("lep1Pt", &lep1Pt, &b_lep1Pt);
   fChain->SetBranchAddress("lep1Eta", &lep1Eta, &b_lep1Eta);
   fChain->SetBranchAddress("lep1Phi", &lep1Phi, &b_lep1Phi);
   fChain->SetBranchAddress("lep1Type", &lep1Type, &b_lep1Type);
   fChain->SetBranchAddress("lep1Origin", &lep1Origin, &b_lep1Origin);
   fChain->SetBranchAddress("lep1IsoTight", &lep1IsoTight, &b_lep1IsoTight);
   fChain->SetBranchAddress("lep2Pt", &lep2Pt, &b_lep2Pt);
   fChain->SetBranchAddress("lep2Eta", &lep2Eta, &b_lep2Eta);
   fChain->SetBranchAddress("lep2Phi", &lep2Phi, &b_lep2Phi);
   fChain->SetBranchAddress("lep2Type", &lep2Type, &b_lep2Type);
   fChain->SetBranchAddress("lep2Origin", &lep2Origin, &b_lep2Origin);
   fChain->SetBranchAddress("lep2IsoTight", &lep2IsoTight, &b_lep2IsoTight);
   fChain->SetBranchAddress("lep3Pt", &lep3Pt, &b_lep3Pt);
   fChain->SetBranchAddress("lep3Eta", &lep3Eta, &b_lep3Eta);
   fChain->SetBranchAddress("lep3Phi", &lep3Phi, &b_lep3Phi);
   fChain->SetBranchAddress("lep3Type", &lep3Type, &b_lep3Type);
   fChain->SetBranchAddress("lep3Origin", &lep3Origin, &b_lep3Origin);
   fChain->SetBranchAddress("lep3IsoTight", &lep3IsoTight, &b_lep3IsoTight);
   fChain->SetBranchAddress("lep4Pt", &lep4Pt, &b_lep4Pt);
   fChain->SetBranchAddress("lep4Eta", &lep4Eta, &b_lep4Eta);
   fChain->SetBranchAddress("lep4Phi", &lep4Phi, &b_lep4Phi);
   fChain->SetBranchAddress("lep4Type", &lep4Type, &b_lep4Type);
   fChain->SetBranchAddress("lep4Origin", &lep4Origin, &b_lep4Origin);
   fChain->SetBranchAddress("lep4IsoTight", &lep4IsoTight, &b_lep4IsoTight);
   fChain->SetBranchAddress("LepAplanarity", &LepAplanarity, &b_LepAplanarity);
   fChain->SetBranchAddress("JetAplanarity", &JetAplanarity, &b_JetAplanarity);
   fChain->SetBranchAddress("jet1Pt", &jet1Pt, &b_jet1Pt);
   fChain->SetBranchAddress("jet2Pt", &jet2Pt, &b_jet2Pt);
   fChain->SetBranchAddress("jet3Pt", &jet3Pt, &b_jet3Pt);
   fChain->SetBranchAddress("jet4Pt", &jet4Pt, &b_jet4Pt);
   fChain->SetBranchAddress("jet5Pt", &jet5Pt, &b_jet5Pt);
   fChain->SetBranchAddress("jet6Pt", &jet6Pt, &b_jet6Pt);
   fChain->SetBranchAddress("jet7Pt", &jet7Pt, &b_jet7Pt);
   fChain->SetBranchAddress("jet8Pt", &jet8Pt, &b_jet8Pt);
   fChain->SetBranchAddress("jet1Eta", &jet1Eta, &b_jet1Eta);
   fChain->SetBranchAddress("jet2Eta", &jet2Eta, &b_jet2Eta);
   fChain->SetBranchAddress("jet3Eta", &jet3Eta, &b_jet3Eta);
   fChain->SetBranchAddress("jet4Eta", &jet4Eta, &b_jet4Eta);
   fChain->SetBranchAddress("jet5Eta", &jet5Eta, &b_jet5Eta);
   fChain->SetBranchAddress("jet6Eta", &jet6Eta, &b_jet6Eta);
   fChain->SetBranchAddress("jet7Eta", &jet7Eta, &b_jet7Eta);
   fChain->SetBranchAddress("jet8Eta", &jet8Eta, &b_jet8Eta);
   fChain->SetBranchAddress("jet1Phi", &jet1Phi, &b_jet1Phi);
   fChain->SetBranchAddress("jet2Phi", &jet2Phi, &b_jet2Phi);
   fChain->SetBranchAddress("jet3Phi", &jet3Phi, &b_jet3Phi);
   fChain->SetBranchAddress("jet4Phi", &jet4Phi, &b_jet4Phi);
   fChain->SetBranchAddress("jet5Phi", &jet5Phi, &b_jet5Phi);
   fChain->SetBranchAddress("jet6Phi", &jet6Phi, &b_jet6Phi);
   fChain->SetBranchAddress("jet7Phi", &jet7Phi, &b_jet7Phi);
   fChain->SetBranchAddress("jet8Phi", &jet8Phi, &b_jet8Phi);
   fChain->SetBranchAddress("jet1E", &jet1E, &b_jet1E);
   fChain->SetBranchAddress("jet2E", &jet2E, &b_jet2E);
   fChain->SetBranchAddress("jet3E", &jet3E, &b_jet3E);
   fChain->SetBranchAddress("jet4E", &jet4E, &b_jet4E);
   fChain->SetBranchAddress("jet5E", &jet5E, &b_jet5E);
   fChain->SetBranchAddress("jet6E", &jet6E, &b_jet6E);
   fChain->SetBranchAddress("jet7E", &jet7E, &b_jet7E);
   fChain->SetBranchAddress("jet8E", &jet8E, &b_jet8E);
   fChain->SetBranchAddress("jet1Mv2c10", &jet1Mv2c10, &b_jet1Mv2c10);
   fChain->SetBranchAddress("jet2Mv2c10", &jet2Mv2c10, &b_jet2Mv2c10);
   fChain->SetBranchAddress("jet3Mv2c10", &jet3Mv2c10, &b_jet3Mv2c10);
   fChain->SetBranchAddress("jet4Mv2c10", &jet4Mv2c10, &b_jet4Mv2c10);
   fChain->SetBranchAddress("jet5Mv2c10", &jet5Mv2c10, &b_jet5Mv2c10);
   fChain->SetBranchAddress("jet6Mv2c10", &jet6Mv2c10, &b_jet6Mv2c10);
   fChain->SetBranchAddress("jet7Mv2c10", &jet7Mv2c10, &b_jet7Mv2c10);
   fChain->SetBranchAddress("jet8Mv2c10", &jet8Mv2c10, &b_jet8Mv2c10);
   fChain->SetBranchAddress("amt2", &amt2, &b_amt2);
   fChain->SetBranchAddress("amt2b", &amt2b, &b_amt2b);
   fChain->SetBranchAddress("amt2bWeight", &amt2bWeight, &b_amt2bWeight);
   fChain->SetBranchAddress("mt2tau", &mt2tau, &b_mt2tau);
   fChain->SetBranchAddress("mt2lj", &mt2lj, &b_mt2lj);
   fChain->SetBranchAddress("topNess", &topNess, &b_topNess);
   fChain->SetBranchAddress("pileupWeight", &pileupWeight, &b_pileupWeight);
   fChain->SetBranchAddress("leptonWeight", &leptonWeight, &b_leptonWeight);
   fChain->SetBranchAddress("triggerWeight", &triggerWeight, &b_triggerWeight);
   fChain->SetBranchAddress("eventWeight", &eventWeight, &b_eventWeight);
   fChain->SetBranchAddress("jvtWeight", &jvtWeight, &b_jvtWeight);
   fChain->SetBranchAddress("bTagWeight", &bTagWeight, &b_bTagWeight);
   fChain->SetBranchAddress("genWeight", &genWeight, &b_genWeight);
   fChain->SetBranchAddress("genWeightUp", &genWeightUp, &b_genWeightUp);
   fChain->SetBranchAddress("genWeightDown", &genWeightDown, &b_genWeightDown);
   fChain->SetBranchAddress("SherpaVjetsNjetsWeight", &SherpaVjetsNjetsWeight, &b_SherpaVjetsNjetsWeight);
   fChain->SetBranchAddress("truthTopPt", &truthTopPt, &b_truthTopPt);
   fChain->SetBranchAddress("truthAntiTopPt", &truthAntiTopPt, &b_truthAntiTopPt);
   fChain->SetBranchAddress("truthTtbarPt", &truthTtbarPt, &b_truthTtbarPt);
   fChain->SetBranchAddress("truthTtbarM", &truthTtbarM, &b_truthTtbarM);
   fChain->SetBranchAddress("PRWHash", &PRWHash, &b_PRWHash);
   fChain->SetBranchAddress("EventNumber", &EventNumber, &b_EventNumber);
   fChain->SetBranchAddress("xsec", &xsec, &b_xsec);
   fChain->SetBranchAddress("TrueHt", &TrueHt, &b_TrueHt);
   fChain->SetBranchAddress("DatasetNumber", &DatasetNumber, &b_DatasetNumber);
   fChain->SetBranchAddress("RunNumber", &RunNumber, &b_RunNumber);
   fChain->SetBranchAddress("FS", &FS, &b_FS);
   Notify();
}

Bool_t Incl1LBase::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void Incl1LBase::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t Incl1LBase::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef Incl1LBase_cxx
