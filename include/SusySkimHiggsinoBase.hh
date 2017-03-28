//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Mon Mar 27 16:05:12 2017 by ROOT version 6.04/14
// from TTree MGPy8EG_A14N23LO_SM_N2C1m_110_100_2LMET50_MadSpin_NoSys/MGPy8EG_A14N23LO_SM_N2C1m_110_100_2LMET50_MadSpin_NoSys
// found on file: MGPy8EG_A14N23LO_SM_N2C1m_110_100_2LMET50_MadSpin_SusySkimHiggsino_v1.1_SUSY16_tree.root
//////////////////////////////////////////////////////////

#ifndef SusySkimHiggsinoBase_h
#define SusySkimHiggsinoBase_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include <vector>

using namespace std;

class SusySkimHiggsinoBase {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Double_t        trigWeight_metTrig;
   Bool_t          trigMatch_metTrig;
   Double_t        trigWeight_singleMuonTrig;
   Bool_t          trigMatch_singleMuonTrig;
   Double_t        trigWeight_singleElectronTrig;
   Bool_t          trigMatch_singleElectronTrig;
   Bool_t          HLT_2mu4_j85_xe50_mht_emul;
   Bool_t          HLT_mu4_j125_xe90_mht_emul;
   Float_t         mu;
   Int_t           nVtx;
   Int_t           nLep_base;
   Int_t           nLep_signal;
   Int_t           lep1Flavor;
   Int_t           lep1Charge;
   Float_t         lep1Pt;
   Float_t         lep1Eta;
   Float_t         lep1Phi;
   Float_t         lep1M;
   Float_t         lep1D0;
   Float_t         lep1D0Sig;
   Float_t         lep1Z0;
   Float_t         lep1Z0SinTheta;
   Bool_t          lep1PassOR;
   Int_t           lep1Type;
   Int_t           lep1Origin;
   Int_t           lep1NPix;
   Bool_t          lep1PassBL;
   Bool_t          lep1VeryLoose;
   Bool_t          lep1Loose;
   Bool_t          lep1Medium;
   Bool_t          lep1Tight;
   Bool_t          lep1IsoLoose;
   Bool_t          lep1IsoTight;
   Bool_t          lep1IsoGradient;
   Bool_t          lep1IsoGradientLoose;
   Bool_t          lep1IsoLooseTrackOnly;
   Bool_t          lep1IsoFixedCutLoose;
   Bool_t          lep1IsoFixedCutTight;
   Bool_t          lep1IsoFixedCutTightTrackOnly;
   Float_t         lep1Ptcone20;
   Float_t         lep1Ptcone30;
   Float_t         lep1Ptcone40;
   Bool_t          lep1Signal;
   Bool_t          lep1MatchesTrigger;
   Int_t           lep2Flavor;
   Int_t           lep2Charge;
   Float_t         lep2Pt;
   Float_t         lep2Eta;
   Float_t         lep2Phi;
   Float_t         lep2M;
   Float_t         lep2D0;
   Float_t         lep2D0Sig;
   Float_t         lep2Z0;
   Float_t         lep2Z0SinTheta;
   Bool_t          lep2PassOR;
   Int_t           lep2Type;
   Int_t           lep2Origin;
   Int_t           lep2NPix;
   Bool_t          lep2PassBL;
   Bool_t          lep2VeryLoose;
   Bool_t          lep2Loose;
   Bool_t          lep2Medium;
   Bool_t          lep2Tight;
   Bool_t          lep2IsoLoose;
   Bool_t          lep2IsoTight;
   Bool_t          lep2IsoGradient;
   Bool_t          lep2IsoGradientLoose;
   Bool_t          lep2IsoLooseTrackOnly;
   Bool_t          lep2IsoFixedCutLoose;
   Bool_t          lep2IsoFixedCutTight;
   Bool_t          lep2IsoFixedCutTightTrackOnly;
   Bool_t          lep2Signal;
   Bool_t          lep2MatchesTrigger;
   Int_t           lep3Flavor;
   Int_t           lep3Charge;
   Float_t         lep3Pt;
   Float_t         lep3Eta;
   Float_t         lep3Phi;
   Float_t         lep3M;
   Float_t         lep3D0;
   Float_t         lep3D0Sig;
   Float_t         lep3Z0;
   Float_t         lep3Z0SinTheta;
   Bool_t          lep3PassOR;
   Int_t           lep3Type;
   Int_t           lep3Origin;
   Int_t           lep3NPix;
   Bool_t          lep3PassBL;
   Bool_t          lep3VeryLoose;
   Bool_t          lep3Loose;
   Bool_t          lep3Medium;
   Bool_t          lep3Tight;
   Bool_t          lep3IsoLoose;
   Bool_t          lep3IsoTight;
   Bool_t          lep3IsoGradient;
   Bool_t          lep3IsoGradientLoose;
   Bool_t          lep3IsoLooseTrackOnly;
   Bool_t          lep3IsoFixedCutLoose;
   Bool_t          lep3IsoFixedCutTight;
   Bool_t          lep3IsoFixedCutTightTrackOnly;
   Bool_t          lep3Signal;
   Bool_t          lep3MatchesTrigger;
   Int_t           lep4Flavor;
   Int_t           lep4Charge;
   Float_t         lep4Pt;
   Float_t         lep4Eta;
   Float_t         lep4Phi;
   Float_t         lep4M;
   Float_t         lep4D0;
   Float_t         lep4D0Sig;
   Float_t         lep4Z0;
   Float_t         lep4Z0SinTheta;
   Bool_t          lep4PassOR;
   Int_t           lep4Type;
   Int_t           lep4Origin;
   Int_t           lep4NPix;
   Bool_t          lep4PassBL;
   Bool_t          lep4VeryLoose;
   Bool_t          lep4Loose;
   Bool_t          lep4Medium;
   Bool_t          lep4Tight;
   Bool_t          lep4IsoLoose;
   Bool_t          lep4IsoTight;
   Bool_t          lep4IsoGradient;
   Bool_t          lep4IsoGradientLoose;
   Bool_t          lep4IsoLooseTrackOnly;
   Bool_t          lep4IsoFixedCutLoose;
   Bool_t          lep4IsoFixedCutTight;
   Bool_t          lep4IsoFixedCutTightTrackOnly;
   Bool_t          lep4Signal;
   Bool_t          lep4MatchesTrigger;
   Int_t           nJet30;
   Int_t           nJet25;
   Int_t           nTotalJet;
   Int_t           nBJet30_MV2c10;
   Int_t           nBJet30_MV2c10_FixedCutBEff_60;
   Int_t           nBJet30_MV2c10_FixedCutBEff_70;
   Int_t           nBJet30_MV2c10_FixedCutBEff_85;
   Int_t           DecayModeTTbar;
   vector<float>   *jetPt;
   vector<float>   *jetEta;
   vector<float>   *jetPhi;
   vector<float>   *jetM;
   Float_t         met_Et;
   Float_t         met_Phi;
   Float_t         TST_Et;
   Float_t         TST_Phi;
   Float_t         deltaPhi_MET_TST_Phi;
   Float_t         mt;
   Float_t         meffInc30;
   Float_t         Ht30;
   Float_t         hadronicWMass;
   Float_t         hadronicWPt;
   Float_t         LepAplanarity;
   Float_t         JetAplanarity;
   Float_t         amt2;
   Float_t         amt2b;
   Float_t         amt2bWeight;
   Float_t         mt2tau;
   Float_t         mt2lj;
   Float_t         mbb;
   Float_t         mt_lep1;
   Float_t         mt_lep2;
   Float_t         mt_lep3;
   Float_t         mt_lep4;
   Float_t         METOverHT;
   Float_t         METOverJ1pT;
   Float_t         DPhiJ1Met;
   Float_t         mll;
   Float_t         Rll;
   Float_t         MSqTauTau_1;
   Float_t         MSqTauTau_2;
   Float_t         RjlOverEl;
   Float_t         LepCosThetaLab;
   Float_t         LepCosThetaCoM;
   Float_t         mt2leplsp_0;
   Float_t         mt2leplsp_25;
   Float_t         mt2leplsp_50;
   Float_t         mt2leplsp_75;
   Float_t         mt2leplsp_90;
   Float_t         mt2leplsp_95;
   Float_t         mt2leplsp_100;
   Float_t         mt2leplsp_105;
   Float_t         mt2leplsp_110;
   Float_t         mt2leplsp_115;
   Float_t         mt2leplsp_120;
   Float_t         mt2leplsp_150;
   Double_t        pileupWeight;
   Double_t        leptonWeight;
   Double_t        eventWeight;
   Double_t        genWeight;
   Double_t        bTagWeight;
   Double_t        jvtWeight;
   Double_t        genWeightUp;
   Double_t        genWeightDown;
   Double_t        SherpaVjetsNjetsWeight;
   Bool_t          HLT_mu4;
   Bool_t          HLT_2mu4;
   Bool_t          HLT_2mu10;
   Bool_t          HLT_2mu4_j85_xe50_mht;
   Bool_t          HLT_mu4_j125_xe90_mht;
   Bool_t          HLT_xe70;
   Bool_t          HLT_xe70_mht;
   Bool_t          HLT_xe70_mht_wEFMu;
   Bool_t          HLT_xe70_tc_lcw;
   Bool_t          HLT_xe70_tc_lcw_wEFMu;
   Bool_t          HLT_xe80_tc_lcw_L1XE50;
   Bool_t          HLT_xe90_tc_lcw_L1XE50;
   Bool_t          HLT_xe90_mht_L1XE50;
   Bool_t          HLT_xe90_tc_lcw_wEFMu_L1XE50;
   Bool_t          HLT_xe90_mht_wEFMu_L1XE50;
   Bool_t          HLT_xe100_L1XE50;
   Bool_t          HLT_xe100_wEFMu_L1XE50;
   Bool_t          HLT_xe100_tc_lcw_L1XE50;
   Bool_t          HLT_xe100_mht_L1XE50;
   Bool_t          HLT_xe100_tc_lcw_wEFMu_L1XE50;
   Bool_t          HLT_xe100_mht_wEFMu_L1XE50;
   Bool_t          HLT_xe110_L1XE50;
   Bool_t          HLT_xe110_tc_em_L1XE50;
   Bool_t          HLT_xe110_wEFMu_L1XE50;
   Bool_t          HLT_xe110_tc_em_wEFMu_L1XE50;
   Bool_t          HLT_xe110_mht_L1XE50;
   Bool_t          HLT_xe90_mht_L1XE40;
   Bool_t          HLT_xe50_mht_L1XE20;
   Bool_t          HLT_j85_L1J40;
   Bool_t          HLT_j125_L1J50;
   Bool_t          HLT_e26_lhtight_nod0_ivarloose;
   Bool_t          HLT_e60_lhmedium_nod0;
   Bool_t          HLT_e60_medium;
   Bool_t          HLT_e140_lhloose_nod0;
   Bool_t          HLT_mu26_ivarmedium;
   Double_t        ttbarNNLOWeight;
   Double_t        ttbarNNLOWeightUp;
   Double_t        ttbarNNLOWeightDown;
   Float_t         truthTopPt;
   Float_t         truthAntiTopPt;
   Float_t         truthTtbarPt;
   Float_t         truthTtbarM;
   Float_t         x1;
   Float_t         x2;
   Float_t         pdf1;
   Float_t         pdf2;
   Float_t         scalePDF;
   Int_t           id1;
   Int_t           id2;
   ULong64_t       PRWHash;
   ULong64_t       EventNumber;
   Float_t         xsec;
   Float_t         TrueHt;
   Int_t           DatasetNumber;
   Int_t           RunNumber;
   Int_t           RandomRunNumber;
   Int_t           FS;

   // List of branches
   TBranch        *b_trigWeight_metTrig;   //!
   TBranch        *b_trigMatch_metTrig;   //!
   TBranch        *b_trigWeight_singleMuonTrig;   //!
   TBranch        *b_trigMatch_singleMuonTrig;   //!
   TBranch        *b_trigWeight_singleElectronTrig;   //!
   TBranch        *b_trigMatch_singleElectronTrig;   //!
   TBranch        *b_HLT_2mu4_j85_xe50_mht_emul;   //!
   TBranch        *b_HLT_mu4_j125_xe90_mht_emul;   //!
   TBranch        *b_mu;   //!
   TBranch        *b_nVtx;   //!
   TBranch        *b_nLep_base;   //!
   TBranch        *b_nLep_signal;   //!
   TBranch        *b_lep1Flavor;   //!
   TBranch        *b_lep1Charge;   //!
   TBranch        *b_lep1Pt;   //!
   TBranch        *b_lep1Eta;   //!
   TBranch        *b_lep1Phi;   //!
   TBranch        *b_lep1M;   //!
   TBranch        *b_lep1D0;   //!
   TBranch        *b_lep1D0Sig;   //!
   TBranch        *b_lep1Z0;   //!
   TBranch        *b_lep1Z0SinTheta;   //!
   TBranch        *b_lep1PassOR;   //!
   TBranch        *b_lep1Type;   //!
   TBranch        *b_lep1Origin;   //!
   TBranch        *b_lep1NPix;   //!
   TBranch        *b_lep1PassBL;   //!
   TBranch        *b_lep1VeryLoose;   //!
   TBranch        *b_lep1Loose;   //!
   TBranch        *b_lep1Medium;   //!
   TBranch        *b_lep1Tight;   //!
   TBranch        *b_lep1IsoLoose;   //!
   TBranch        *b_lep1IsoTight;   //!
   TBranch        *b_lep1IsoGradient;   //!
   TBranch        *b_lep1IsoGradientLoose;   //!
   TBranch        *b_lep1IsoLooseTrackOnly;   //!
   TBranch        *b_lep1IsoFixedCutLoose;   //!
   TBranch        *b_lep1IsoFixedCutTight;   //!
   TBranch        *b_lep1IsoFixedCutTightTrackOnly;   //!
   TBranch        *b_lep1Ptcone20;   //!
   TBranch        *b_lep1Ptcone30;   //!
   TBranch        *b_lep1Ptcone40;   //!
   TBranch        *b_lep1Signal;   //!
   TBranch        *b_lep1MatchesTrigger;   //!
   TBranch        *b_lep2Flavor;   //!
   TBranch        *b_lep2Charge;   //!
   TBranch        *b_lep2Pt;   //!
   TBranch        *b_lep2Eta;   //!
   TBranch        *b_lep2Phi;   //!
   TBranch        *b_lep2M;   //!
   TBranch        *b_lep2D0;   //!
   TBranch        *b_lep2D0Sig;   //!
   TBranch        *b_lep2Z0;   //!
   TBranch        *b_lep2Z0SinTheta;   //!
   TBranch        *b_lep2PassOR;   //!
   TBranch        *b_lep2Type;   //!
   TBranch        *b_lep2Origin;   //!
   TBranch        *b_lep2NPix;   //!
   TBranch        *b_lep2PassBL;   //!
   TBranch        *b_lep2VeryLoose;   //!
   TBranch        *b_lep2Loose;   //!
   TBranch        *b_lep2Medium;   //!
   TBranch        *b_lep2Tight;   //!
   TBranch        *b_lep2IsoLoose;   //!
   TBranch        *b_lep2IsoTight;   //!
   TBranch        *b_lep2IsoGradient;   //!
   TBranch        *b_lep2IsoGradientLoose;   //!
   TBranch        *b_lep2IsoLooseTrackOnly;   //!
   TBranch        *b_lep2IsoFixedCutLoose;   //!
   TBranch        *b_lep2IsoFixedCutTight;   //!
   TBranch        *b_lep2IsoFixedCutTightTrackOnly;   //!
   TBranch        *b_lep2Signal;   //!
   TBranch        *b_lep2MatchesTrigger;   //!
   TBranch        *b_lep3Flavor;   //!
   TBranch        *b_lep3Charge;   //!
   TBranch        *b_lep3Pt;   //!
   TBranch        *b_lep3Eta;   //!
   TBranch        *b_lep3Phi;   //!
   TBranch        *b_lep3M;   //!
   TBranch        *b_lep3D0;   //!
   TBranch        *b_lep3D0Sig;   //!
   TBranch        *b_lep3Z0;   //!
   TBranch        *b_lep3Z0SinTheta;   //!
   TBranch        *b_lep3PassOR;   //!
   TBranch        *b_lep3Type;   //!
   TBranch        *b_lep3Origin;   //!
   TBranch        *b_lep3NPix;   //!
   TBranch        *b_lep3PassBL;   //!
   TBranch        *b_lep3VeryLoose;   //!
   TBranch        *b_lep3Loose;   //!
   TBranch        *b_lep3Medium;   //!
   TBranch        *b_lep3Tight;   //!
   TBranch        *b_lep3IsoLoose;   //!
   TBranch        *b_lep3IsoTight;   //!
   TBranch        *b_lep3IsoGradient;   //!
   TBranch        *b_lep3IsoGradientLoose;   //!
   TBranch        *b_lep3IsoLooseTrackOnly;   //!
   TBranch        *b_lep3IsoFixedCutLoose;   //!
   TBranch        *b_lep3IsoFixedCutTight;   //!
   TBranch        *b_lep3IsoFixedCutTightTrackOnly;   //!
   TBranch        *b_lep3Signal;   //!
   TBranch        *b_lep3MatchesTrigger;   //!
   TBranch        *b_lep4Flavor;   //!
   TBranch        *b_lep4Charge;   //!
   TBranch        *b_lep4Pt;   //!
   TBranch        *b_lep4Eta;   //!
   TBranch        *b_lep4Phi;   //!
   TBranch        *b_lep4M;   //!
   TBranch        *b_lep4D0;   //!
   TBranch        *b_lep4D0Sig;   //!
   TBranch        *b_lep4Z0;   //!
   TBranch        *b_lep4Z0SinTheta;   //!
   TBranch        *b_lep4PassOR;   //!
   TBranch        *b_lep4Type;   //!
   TBranch        *b_lep4Origin;   //!
   TBranch        *b_lep4NPix;   //!
   TBranch        *b_lep4PassBL;   //!
   TBranch        *b_lep4VeryLoose;   //!
   TBranch        *b_lep4Loose;   //!
   TBranch        *b_lep4Medium;   //!
   TBranch        *b_lep4Tight;   //!
   TBranch        *b_lep4IsoLoose;   //!
   TBranch        *b_lep4IsoTight;   //!
   TBranch        *b_lep4IsoGradient;   //!
   TBranch        *b_lep4IsoGradientLoose;   //!
   TBranch        *b_lep4IsoLooseTrackOnly;   //!
   TBranch        *b_lep4IsoFixedCutLoose;   //!
   TBranch        *b_lep4IsoFixedCutTight;   //!
   TBranch        *b_lep4IsoFixedCutTightTrackOnly;   //!
   TBranch        *b_lep4Signal;   //!
   TBranch        *b_lep4MatchesTrigger;   //!
   TBranch        *b_nJet30;   //!
   TBranch        *b_nJet25;   //!
   TBranch        *b_nTotalJet;   //!
   TBranch        *b_nBJet30_MV2c10;   //!
   TBranch        *b_nBJet30_MV2c10_FixedCutBEff_60;   //!
   TBranch        *b_nBJet30_MV2c10_FixedCutBEff_70;   //!
   TBranch        *b_nBJet30_MV2c10_FixedCutBEff_85;   //!
   TBranch        *b_DecayModeTTbar;   //!
   TBranch        *b_jetPt;   //!
   TBranch        *b_jetEta;   //!
   TBranch        *b_jetPhi;   //!
   TBranch        *b_jetM;   //!
   TBranch        *b_met_Et;   //!
   TBranch        *b_met_Phi;   //!
   TBranch        *b_TST_Et;   //!
   TBranch        *b_TST_Phi;   //!
   TBranch        *b_deltaPhi_MET_TST_Phi;   //!
   TBranch        *b_mt;   //!
   TBranch        *b_meffInc30;   //!
   TBranch        *b_Ht30;   //!
   TBranch        *b_hadronicWMass;   //!
   TBranch        *b_hadronicWPt;   //!
   TBranch        *b_LepAplanarity;   //!
   TBranch        *b_JetAplanarity;   //!
   TBranch        *b_amt2;   //!
   TBranch        *b_amt2b;   //!
   TBranch        *b_amt2bWeight;   //!
   TBranch        *b_mt2tau;   //!
   TBranch        *b_mt2lj;   //!
   TBranch        *b_mbb;   //!
   TBranch        *b_mt_lep1;   //!
   TBranch        *b_mt_lep2;   //!
   TBranch        *b_mt_lep3;   //!
   TBranch        *b_mt_lep4;   //!
   TBranch        *b_METOverHT;   //!
   TBranch        *b_METOverJ1pT;   //!
   TBranch        *b_DPhiJ1Met;   //!
   TBranch        *b_mll;   //!
   TBranch        *b_Rll;   //!
   TBranch        *b_MSqTauTau_1;   //!
   TBranch        *b_MSqTauTau_2;   //!
   TBranch        *b_RjlOverEl;   //!
   TBranch        *b_LepCosThetaLab;   //!
   TBranch        *b_LepCosThetaCoM;   //!
   TBranch        *b_mt2leplsp_0;   //!
   TBranch        *b_mt2leplsp_25;   //!
   TBranch        *b_mt2leplsp_50;   //!
   TBranch        *b_mt2leplsp_75;   //!
   TBranch        *b_mt2leplsp_90;   //!
   TBranch        *b_mt2leplsp_95;   //!
   TBranch        *b_mt2leplsp_100;   //!
   TBranch        *b_mt2leplsp_105;   //!
   TBranch        *b_mt2leplsp_110;   //!
   TBranch        *b_mt2leplsp_115;   //!
   TBranch        *b_mt2leplsp_120;   //!
   TBranch        *b_mt2leplsp_150;   //!
   TBranch        *b_pileupWeight;   //!
   TBranch        *b_leptonWeight;   //!
   TBranch        *b_eventWeight;   //!
   TBranch        *b_genWeight;   //!
   TBranch        *b_bTagWeight;   //!
   TBranch        *b_jvtWeight;   //!
   TBranch        *b_genWeightUp;   //!
   TBranch        *b_genWeightDown;   //!
   TBranch        *b_SherpaVjetsNjetsWeight;   //!
   TBranch        *b_HLT_mu4;   //!
   TBranch        *b_HLT_2mu4;   //!
   TBranch        *b_HLT_2mu10;   //!
   TBranch        *b_HLT_2mu4_j85_xe50_mht;   //!
   TBranch        *b_HLT_mu4_j125_xe90_mht;   //!
   TBranch        *b_HLT_xe70;   //!
   TBranch        *b_HLT_xe70_mht;   //!
   TBranch        *b_HLT_xe70_mht_wEFMu;   //!
   TBranch        *b_HLT_xe70_tc_lcw;   //!
   TBranch        *b_HLT_xe70_tc_lcw_wEFMu;   //!
   TBranch        *b_HLT_xe80_tc_lcw_L1XE50;   //!
   TBranch        *b_HLT_xe90_tc_lcw_L1XE50;   //!
   TBranch        *b_HLT_xe90_mht_L1XE50;   //!
   TBranch        *b_HLT_xe90_tc_lcw_wEFMu_L1XE50;   //!
   TBranch        *b_HLT_xe90_mht_wEFMu_L1XE50;   //!
   TBranch        *b_HLT_xe100_L1XE50;   //!
   TBranch        *b_HLT_xe100_wEFMu_L1XE50;   //!
   TBranch        *b_HLT_xe100_tc_lcw_L1XE50;   //!
   TBranch        *b_HLT_xe100_mht_L1XE50;   //!
   TBranch        *b_HLT_xe100_tc_lcw_wEFMu_L1XE50;   //!
   TBranch        *b_HLT_xe100_mht_wEFMu_L1XE50;   //!
   TBranch        *b_HLT_xe110_L1XE50;   //!
   TBranch        *b_HLT_xe110_tc_em_L1XE50;   //!
   TBranch        *b_HLT_xe110_wEFMu_L1XE50;   //!
   TBranch        *b_HLT_xe110_tc_em_wEFMu_L1XE50;   //!
   TBranch        *b_HLT_xe110_mht_L1XE50;   //!
   TBranch        *b_HLT_xe90_mht_L1XE40;   //!
   TBranch        *b_HLT_xe50_mht_L1XE20;   //!
   TBranch        *b_HLT_j85_L1J40;   //!
   TBranch        *b_HLT_j125_L1J50;   //!
   TBranch        *b_HLT_e26_lhtight_nod0_ivarloose;   //!
   TBranch        *b_HLT_e60_lhmedium_nod0;   //!
   TBranch        *b_HLT_e60_medium;   //!
   TBranch        *b_HLT_e140_lhloose_nod0;   //!
   TBranch        *b_HLT_mu26_ivarmedium;   //!
   TBranch        *b_ttbarNNLOWeight;   //!
   TBranch        *b_ttbarNNLOWeightUp;   //!
   TBranch        *b_ttbarNNLOWeightDown;   //!
   TBranch        *b_truthTopPt;   //!
   TBranch        *b_truthAntiTopPt;   //!
   TBranch        *b_truthTtbarPt;   //!
   TBranch        *b_truthTtbarM;   //!
   TBranch        *b_x1;   //!
   TBranch        *b_x2;   //!
   TBranch        *b_pdf1;   //!
   TBranch        *b_pdf2;   //!
   TBranch        *b_scalePDF;   //!
   TBranch        *b_id1;   //!
   TBranch        *b_id2;   //!
   TBranch        *b_PRWHash;   //!
   TBranch        *b_EventNumber;   //!
   TBranch        *b_xsec;   //!
   TBranch        *b_TrueHt;   //!
   TBranch        *b_DatasetNumber;   //!
   TBranch        *b_RunNumber;   //!
   TBranch        *b_RandomRunNumber;   //!
   TBranch        *b_FS;   //!

   SusySkimHiggsinoBase(TTree *tree=0);
   virtual ~SusySkimHiggsinoBase();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

inline SusySkimHiggsinoBase::SusySkimHiggsinoBase(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("MGPy8EG_A14N23LO_SM_N2C1m_110_100_2LMET50_MadSpin_SusySkimHiggsinoBase_v1.1_SUSY16_tree.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("MGPy8EG_A14N23LO_SM_N2C1m_110_100_2LMET50_MadSpin_SusySkimHiggsinoBase_v1.1_SUSY16_tree.root");
      }
      f->GetObject("MGPy8EG_A14N23LO_SM_N2C1m_110_100_2LMET50_MadSpin_NoSys",tree);

   }
   Init(tree);
}

inline SusySkimHiggsinoBase::~SusySkimHiggsinoBase()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

inline Int_t SusySkimHiggsinoBase::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
inline Long64_t SusySkimHiggsinoBase::LoadTree(Long64_t entry)
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

inline void SusySkimHiggsinoBase::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   jetPt = 0;
   jetEta = 0;
   jetPhi = 0;
   jetM = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("trigWeight_metTrig", &trigWeight_metTrig, &b_trigWeight_metTrig);
   fChain->SetBranchAddress("trigMatch_metTrig", &trigMatch_metTrig, &b_trigMatch_metTrig);
   fChain->SetBranchAddress("trigWeight_singleMuonTrig", &trigWeight_singleMuonTrig, &b_trigWeight_singleMuonTrig);
   fChain->SetBranchAddress("trigMatch_singleMuonTrig", &trigMatch_singleMuonTrig, &b_trigMatch_singleMuonTrig);
   fChain->SetBranchAddress("trigWeight_singleElectronTrig", &trigWeight_singleElectronTrig, &b_trigWeight_singleElectronTrig);
   fChain->SetBranchAddress("trigMatch_singleElectronTrig", &trigMatch_singleElectronTrig, &b_trigMatch_singleElectronTrig);
   fChain->SetBranchAddress("HLT_2mu4_j85_xe50_mht_emul", &HLT_2mu4_j85_xe50_mht_emul, &b_HLT_2mu4_j85_xe50_mht_emul);
   fChain->SetBranchAddress("HLT_mu4_j125_xe90_mht_emul", &HLT_mu4_j125_xe90_mht_emul, &b_HLT_mu4_j125_xe90_mht_emul);
   fChain->SetBranchAddress("mu", &mu, &b_mu);
   fChain->SetBranchAddress("nVtx", &nVtx, &b_nVtx);
   fChain->SetBranchAddress("nLep_base", &nLep_base, &b_nLep_base);
   fChain->SetBranchAddress("nLep_signal", &nLep_signal, &b_nLep_signal);
   fChain->SetBranchAddress("lep1Flavor", &lep1Flavor, &b_lep1Flavor);
   fChain->SetBranchAddress("lep1Charge", &lep1Charge, &b_lep1Charge);
   fChain->SetBranchAddress("lep1Pt", &lep1Pt, &b_lep1Pt);
   fChain->SetBranchAddress("lep1Eta", &lep1Eta, &b_lep1Eta);
   fChain->SetBranchAddress("lep1Phi", &lep1Phi, &b_lep1Phi);
   fChain->SetBranchAddress("lep1M", &lep1M, &b_lep1M);
   fChain->SetBranchAddress("lep1D0", &lep1D0, &b_lep1D0);
   fChain->SetBranchAddress("lep1D0Sig", &lep1D0Sig, &b_lep1D0Sig);
   fChain->SetBranchAddress("lep1Z0", &lep1Z0, &b_lep1Z0);
   fChain->SetBranchAddress("lep1Z0SinTheta", &lep1Z0SinTheta, &b_lep1Z0SinTheta);
   fChain->SetBranchAddress("lep1PassOR", &lep1PassOR, &b_lep1PassOR);
   fChain->SetBranchAddress("lep1Type", &lep1Type, &b_lep1Type);
   fChain->SetBranchAddress("lep1Origin", &lep1Origin, &b_lep1Origin);
   fChain->SetBranchAddress("lep1NPix", &lep1NPix, &b_lep1NPix);
   fChain->SetBranchAddress("lep1PassBL", &lep1PassBL, &b_lep1PassBL);
   fChain->SetBranchAddress("lep1VeryLoose", &lep1VeryLoose, &b_lep1VeryLoose);
   fChain->SetBranchAddress("lep1Loose", &lep1Loose, &b_lep1Loose);
   fChain->SetBranchAddress("lep1Medium", &lep1Medium, &b_lep1Medium);
   fChain->SetBranchAddress("lep1Tight", &lep1Tight, &b_lep1Tight);
   fChain->SetBranchAddress("lep1IsoLoose", &lep1IsoLoose, &b_lep1IsoLoose);
   fChain->SetBranchAddress("lep1IsoTight", &lep1IsoTight, &b_lep1IsoTight);
   fChain->SetBranchAddress("lep1IsoGradient", &lep1IsoGradient, &b_lep1IsoGradient);
   fChain->SetBranchAddress("lep1IsoGradientLoose", &lep1IsoGradientLoose, &b_lep1IsoGradientLoose);
   fChain->SetBranchAddress("lep1IsoLooseTrackOnly", &lep1IsoLooseTrackOnly, &b_lep1IsoLooseTrackOnly);
   fChain->SetBranchAddress("lep1IsoFixedCutLoose", &lep1IsoFixedCutLoose, &b_lep1IsoFixedCutLoose);
   fChain->SetBranchAddress("lep1IsoFixedCutTight", &lep1IsoFixedCutTight, &b_lep1IsoFixedCutTight);
   fChain->SetBranchAddress("lep1IsoFixedCutTightTrackOnly", &lep1IsoFixedCutTightTrackOnly, &b_lep1IsoFixedCutTightTrackOnly);
   fChain->SetBranchAddress("lep1Ptcone20", &lep1Ptcone20, &b_lep1Ptcone20);
   fChain->SetBranchAddress("lep1Ptcone30", &lep1Ptcone30, &b_lep1Ptcone30);
   fChain->SetBranchAddress("lep1Ptcone40", &lep1Ptcone40, &b_lep1Ptcone40);
   fChain->SetBranchAddress("lep1Signal", &lep1Signal, &b_lep1Signal);
   fChain->SetBranchAddress("lep1MatchesTrigger", &lep1MatchesTrigger, &b_lep1MatchesTrigger);
   fChain->SetBranchAddress("lep2Flavor", &lep2Flavor, &b_lep2Flavor);
   fChain->SetBranchAddress("lep2Charge", &lep2Charge, &b_lep2Charge);
   fChain->SetBranchAddress("lep2Pt", &lep2Pt, &b_lep2Pt);
   fChain->SetBranchAddress("lep2Eta", &lep2Eta, &b_lep2Eta);
   fChain->SetBranchAddress("lep2Phi", &lep2Phi, &b_lep2Phi);
   fChain->SetBranchAddress("lep2M", &lep2M, &b_lep2M);
   fChain->SetBranchAddress("lep2D0", &lep2D0, &b_lep2D0);
   fChain->SetBranchAddress("lep2D0Sig", &lep2D0Sig, &b_lep2D0Sig);
   fChain->SetBranchAddress("lep2Z0", &lep2Z0, &b_lep2Z0);
   fChain->SetBranchAddress("lep2Z0SinTheta", &lep2Z0SinTheta, &b_lep2Z0SinTheta);
   fChain->SetBranchAddress("lep2PassOR", &lep2PassOR, &b_lep2PassOR);
   fChain->SetBranchAddress("lep2Type", &lep2Type, &b_lep2Type);
   fChain->SetBranchAddress("lep2Origin", &lep2Origin, &b_lep2Origin);
   fChain->SetBranchAddress("lep2NPix", &lep2NPix, &b_lep2NPix);
   fChain->SetBranchAddress("lep2PassBL", &lep2PassBL, &b_lep2PassBL);
   fChain->SetBranchAddress("lep2VeryLoose", &lep2VeryLoose, &b_lep2VeryLoose);
   fChain->SetBranchAddress("lep2Loose", &lep2Loose, &b_lep2Loose);
   fChain->SetBranchAddress("lep2Medium", &lep2Medium, &b_lep2Medium);
   fChain->SetBranchAddress("lep2Tight", &lep2Tight, &b_lep2Tight);
   fChain->SetBranchAddress("lep2IsoLoose", &lep2IsoLoose, &b_lep2IsoLoose);
   fChain->SetBranchAddress("lep2IsoTight", &lep2IsoTight, &b_lep2IsoTight);
   fChain->SetBranchAddress("lep2IsoGradient", &lep2IsoGradient, &b_lep2IsoGradient);
   fChain->SetBranchAddress("lep2IsoGradientLoose", &lep2IsoGradientLoose, &b_lep2IsoGradientLoose);
   fChain->SetBranchAddress("lep2IsoLooseTrackOnly", &lep2IsoLooseTrackOnly, &b_lep2IsoLooseTrackOnly);
   fChain->SetBranchAddress("lep2IsoFixedCutLoose", &lep2IsoFixedCutLoose, &b_lep2IsoFixedCutLoose);
   fChain->SetBranchAddress("lep2IsoFixedCutTight", &lep2IsoFixedCutTight, &b_lep2IsoFixedCutTight);
   fChain->SetBranchAddress("lep2IsoFixedCutTightTrackOnly", &lep2IsoFixedCutTightTrackOnly, &b_lep2IsoFixedCutTightTrackOnly);
   fChain->SetBranchAddress("lep2Signal", &lep2Signal, &b_lep2Signal);
   fChain->SetBranchAddress("lep2MatchesTrigger", &lep2MatchesTrigger, &b_lep2MatchesTrigger);
   fChain->SetBranchAddress("lep3Flavor", &lep3Flavor, &b_lep3Flavor);
   fChain->SetBranchAddress("lep3Charge", &lep3Charge, &b_lep3Charge);
   fChain->SetBranchAddress("lep3Pt", &lep3Pt, &b_lep3Pt);
   fChain->SetBranchAddress("lep3Eta", &lep3Eta, &b_lep3Eta);
   fChain->SetBranchAddress("lep3Phi", &lep3Phi, &b_lep3Phi);
   fChain->SetBranchAddress("lep3M", &lep3M, &b_lep3M);
   fChain->SetBranchAddress("lep3D0", &lep3D0, &b_lep3D0);
   fChain->SetBranchAddress("lep3D0Sig", &lep3D0Sig, &b_lep3D0Sig);
   fChain->SetBranchAddress("lep3Z0", &lep3Z0, &b_lep3Z0);
   fChain->SetBranchAddress("lep3Z0SinTheta", &lep3Z0SinTheta, &b_lep3Z0SinTheta);
   fChain->SetBranchAddress("lep3PassOR", &lep3PassOR, &b_lep3PassOR);
   fChain->SetBranchAddress("lep3Type", &lep3Type, &b_lep3Type);
   fChain->SetBranchAddress("lep3Origin", &lep3Origin, &b_lep3Origin);
   fChain->SetBranchAddress("lep3NPix", &lep3NPix, &b_lep3NPix);
   fChain->SetBranchAddress("lep3PassBL", &lep3PassBL, &b_lep3PassBL);
   fChain->SetBranchAddress("lep3VeryLoose", &lep3VeryLoose, &b_lep3VeryLoose);
   fChain->SetBranchAddress("lep3Loose", &lep3Loose, &b_lep3Loose);
   fChain->SetBranchAddress("lep3Medium", &lep3Medium, &b_lep3Medium);
   fChain->SetBranchAddress("lep3Tight", &lep3Tight, &b_lep3Tight);
   fChain->SetBranchAddress("lep3IsoLoose", &lep3IsoLoose, &b_lep3IsoLoose);
   fChain->SetBranchAddress("lep3IsoTight", &lep3IsoTight, &b_lep3IsoTight);
   fChain->SetBranchAddress("lep3IsoGradient", &lep3IsoGradient, &b_lep3IsoGradient);
   fChain->SetBranchAddress("lep3IsoGradientLoose", &lep3IsoGradientLoose, &b_lep3IsoGradientLoose);
   fChain->SetBranchAddress("lep3IsoLooseTrackOnly", &lep3IsoLooseTrackOnly, &b_lep3IsoLooseTrackOnly);
   fChain->SetBranchAddress("lep3IsoFixedCutLoose", &lep3IsoFixedCutLoose, &b_lep3IsoFixedCutLoose);
   fChain->SetBranchAddress("lep3IsoFixedCutTight", &lep3IsoFixedCutTight, &b_lep3IsoFixedCutTight);
   fChain->SetBranchAddress("lep3IsoFixedCutTightTrackOnly", &lep3IsoFixedCutTightTrackOnly, &b_lep3IsoFixedCutTightTrackOnly);
   fChain->SetBranchAddress("lep3Signal", &lep3Signal, &b_lep3Signal);
   fChain->SetBranchAddress("lep3MatchesTrigger", &lep3MatchesTrigger, &b_lep3MatchesTrigger);
   fChain->SetBranchAddress("lep4Flavor", &lep4Flavor, &b_lep4Flavor);
   fChain->SetBranchAddress("lep4Charge", &lep4Charge, &b_lep4Charge);
   fChain->SetBranchAddress("lep4Pt", &lep4Pt, &b_lep4Pt);
   fChain->SetBranchAddress("lep4Eta", &lep4Eta, &b_lep4Eta);
   fChain->SetBranchAddress("lep4Phi", &lep4Phi, &b_lep4Phi);
   fChain->SetBranchAddress("lep4M", &lep4M, &b_lep4M);
   fChain->SetBranchAddress("lep4D0", &lep4D0, &b_lep4D0);
   fChain->SetBranchAddress("lep4D0Sig", &lep4D0Sig, &b_lep4D0Sig);
   fChain->SetBranchAddress("lep4Z0", &lep4Z0, &b_lep4Z0);
   fChain->SetBranchAddress("lep4Z0SinTheta", &lep4Z0SinTheta, &b_lep4Z0SinTheta);
   fChain->SetBranchAddress("lep4PassOR", &lep4PassOR, &b_lep4PassOR);
   fChain->SetBranchAddress("lep4Type", &lep4Type, &b_lep4Type);
   fChain->SetBranchAddress("lep4Origin", &lep4Origin, &b_lep4Origin);
   fChain->SetBranchAddress("lep4NPix", &lep4NPix, &b_lep4NPix);
   fChain->SetBranchAddress("lep4PassBL", &lep4PassBL, &b_lep4PassBL);
   fChain->SetBranchAddress("lep4VeryLoose", &lep4VeryLoose, &b_lep4VeryLoose);
   fChain->SetBranchAddress("lep4Loose", &lep4Loose, &b_lep4Loose);
   fChain->SetBranchAddress("lep4Medium", &lep4Medium, &b_lep4Medium);
   fChain->SetBranchAddress("lep4Tight", &lep4Tight, &b_lep4Tight);
   fChain->SetBranchAddress("lep4IsoLoose", &lep4IsoLoose, &b_lep4IsoLoose);
   fChain->SetBranchAddress("lep4IsoTight", &lep4IsoTight, &b_lep4IsoTight);
   fChain->SetBranchAddress("lep4IsoGradient", &lep4IsoGradient, &b_lep4IsoGradient);
   fChain->SetBranchAddress("lep4IsoGradientLoose", &lep4IsoGradientLoose, &b_lep4IsoGradientLoose);
   fChain->SetBranchAddress("lep4IsoLooseTrackOnly", &lep4IsoLooseTrackOnly, &b_lep4IsoLooseTrackOnly);
   fChain->SetBranchAddress("lep4IsoFixedCutLoose", &lep4IsoFixedCutLoose, &b_lep4IsoFixedCutLoose);
   fChain->SetBranchAddress("lep4IsoFixedCutTight", &lep4IsoFixedCutTight, &b_lep4IsoFixedCutTight);
   fChain->SetBranchAddress("lep4IsoFixedCutTightTrackOnly", &lep4IsoFixedCutTightTrackOnly, &b_lep4IsoFixedCutTightTrackOnly);
   fChain->SetBranchAddress("lep4Signal", &lep4Signal, &b_lep4Signal);
   fChain->SetBranchAddress("lep4MatchesTrigger", &lep4MatchesTrigger, &b_lep4MatchesTrigger);
   fChain->SetBranchAddress("nJet30", &nJet30, &b_nJet30);
   fChain->SetBranchAddress("nJet25", &nJet25, &b_nJet25);
   fChain->SetBranchAddress("nTotalJet", &nTotalJet, &b_nTotalJet);
   fChain->SetBranchAddress("nBJet30_MV2c10", &nBJet30_MV2c10, &b_nBJet30_MV2c10);
   fChain->SetBranchAddress("nBJet30_MV2c10_FixedCutBEff_60", &nBJet30_MV2c10_FixedCutBEff_60, &b_nBJet30_MV2c10_FixedCutBEff_60);
   fChain->SetBranchAddress("nBJet30_MV2c10_FixedCutBEff_70", &nBJet30_MV2c10_FixedCutBEff_70, &b_nBJet30_MV2c10_FixedCutBEff_70);
   fChain->SetBranchAddress("nBJet30_MV2c10_FixedCutBEff_85", &nBJet30_MV2c10_FixedCutBEff_85, &b_nBJet30_MV2c10_FixedCutBEff_85);
   fChain->SetBranchAddress("DecayModeTTbar", &DecayModeTTbar, &b_DecayModeTTbar);
   fChain->SetBranchAddress("jetPt", &jetPt, &b_jetPt);
   fChain->SetBranchAddress("jetEta", &jetEta, &b_jetEta);
   fChain->SetBranchAddress("jetPhi", &jetPhi, &b_jetPhi);
   fChain->SetBranchAddress("jetM", &jetM, &b_jetM);
   fChain->SetBranchAddress("met_Et", &met_Et, &b_met_Et);
   fChain->SetBranchAddress("met_Phi", &met_Phi, &b_met_Phi);
   fChain->SetBranchAddress("TST_Et", &TST_Et, &b_TST_Et);
   fChain->SetBranchAddress("TST_Phi", &TST_Phi, &b_TST_Phi);
   fChain->SetBranchAddress("deltaPhi_MET_TST_Phi", &deltaPhi_MET_TST_Phi, &b_deltaPhi_MET_TST_Phi);
   fChain->SetBranchAddress("mt", &mt, &b_mt);
   fChain->SetBranchAddress("meffInc30", &meffInc30, &b_meffInc30);
   fChain->SetBranchAddress("Ht30", &Ht30, &b_Ht30);
   fChain->SetBranchAddress("hadronicWMass", &hadronicWMass, &b_hadronicWMass);
   fChain->SetBranchAddress("hadronicWPt", &hadronicWPt, &b_hadronicWPt);
   fChain->SetBranchAddress("LepAplanarity", &LepAplanarity, &b_LepAplanarity);
   fChain->SetBranchAddress("JetAplanarity", &JetAplanarity, &b_JetAplanarity);
   fChain->SetBranchAddress("amt2", &amt2, &b_amt2);
   fChain->SetBranchAddress("amt2b", &amt2b, &b_amt2b);
   fChain->SetBranchAddress("amt2bWeight", &amt2bWeight, &b_amt2bWeight);
   fChain->SetBranchAddress("mt2tau", &mt2tau, &b_mt2tau);
   fChain->SetBranchAddress("mt2lj", &mt2lj, &b_mt2lj);
   fChain->SetBranchAddress("mbb", &mbb, &b_mbb);
   fChain->SetBranchAddress("mt_lep1", &mt_lep1, &b_mt_lep1);
   fChain->SetBranchAddress("mt_lep2", &mt_lep2, &b_mt_lep2);
   fChain->SetBranchAddress("mt_lep3", &mt_lep3, &b_mt_lep3);
   fChain->SetBranchAddress("mt_lep4", &mt_lep4, &b_mt_lep4);
   fChain->SetBranchAddress("METOverHT", &METOverHT, &b_METOverHT);
   fChain->SetBranchAddress("METOverJ1pT", &METOverJ1pT, &b_METOverJ1pT);
   fChain->SetBranchAddress("DPhiJ1Met", &DPhiJ1Met, &b_DPhiJ1Met);
   fChain->SetBranchAddress("mll", &mll, &b_mll);
   fChain->SetBranchAddress("Rll", &Rll, &b_Rll);
   fChain->SetBranchAddress("MSqTauTau_1", &MSqTauTau_1, &b_MSqTauTau_1);
   fChain->SetBranchAddress("MSqTauTau_2", &MSqTauTau_2, &b_MSqTauTau_2);
   fChain->SetBranchAddress("RjlOverEl", &RjlOverEl, &b_RjlOverEl);
   fChain->SetBranchAddress("LepCosThetaLab", &LepCosThetaLab, &b_LepCosThetaLab);
   fChain->SetBranchAddress("LepCosThetaCoM", &LepCosThetaCoM, &b_LepCosThetaCoM);
   fChain->SetBranchAddress("mt2leplsp_0", &mt2leplsp_0, &b_mt2leplsp_0);
   fChain->SetBranchAddress("mt2leplsp_25", &mt2leplsp_25, &b_mt2leplsp_25);
   fChain->SetBranchAddress("mt2leplsp_50", &mt2leplsp_50, &b_mt2leplsp_50);
   fChain->SetBranchAddress("mt2leplsp_75", &mt2leplsp_75, &b_mt2leplsp_75);
   fChain->SetBranchAddress("mt2leplsp_90", &mt2leplsp_90, &b_mt2leplsp_90);
   fChain->SetBranchAddress("mt2leplsp_95", &mt2leplsp_95, &b_mt2leplsp_95);
   fChain->SetBranchAddress("mt2leplsp_100", &mt2leplsp_100, &b_mt2leplsp_100);
   fChain->SetBranchAddress("mt2leplsp_105", &mt2leplsp_105, &b_mt2leplsp_105);
   fChain->SetBranchAddress("mt2leplsp_110", &mt2leplsp_110, &b_mt2leplsp_110);
   fChain->SetBranchAddress("mt2leplsp_115", &mt2leplsp_115, &b_mt2leplsp_115);
   fChain->SetBranchAddress("mt2leplsp_120", &mt2leplsp_120, &b_mt2leplsp_120);
   fChain->SetBranchAddress("mt2leplsp_150", &mt2leplsp_150, &b_mt2leplsp_150);
   fChain->SetBranchAddress("pileupWeight", &pileupWeight, &b_pileupWeight);
   fChain->SetBranchAddress("leptonWeight", &leptonWeight, &b_leptonWeight);
   fChain->SetBranchAddress("eventWeight", &eventWeight, &b_eventWeight);
   fChain->SetBranchAddress("genWeight", &genWeight, &b_genWeight);
   fChain->SetBranchAddress("bTagWeight", &bTagWeight, &b_bTagWeight);
   fChain->SetBranchAddress("jvtWeight", &jvtWeight, &b_jvtWeight);
   fChain->SetBranchAddress("genWeightUp", &genWeightUp, &b_genWeightUp);
   fChain->SetBranchAddress("genWeightDown", &genWeightDown, &b_genWeightDown);
   fChain->SetBranchAddress("SherpaVjetsNjetsWeight", &SherpaVjetsNjetsWeight, &b_SherpaVjetsNjetsWeight);
   fChain->SetBranchAddress("HLT_mu4", &HLT_mu4, &b_HLT_mu4);
   fChain->SetBranchAddress("HLT_2mu4", &HLT_2mu4, &b_HLT_2mu4);
   fChain->SetBranchAddress("HLT_2mu10", &HLT_2mu10, &b_HLT_2mu10);
   fChain->SetBranchAddress("HLT_2mu4_j85_xe50_mht", &HLT_2mu4_j85_xe50_mht, &b_HLT_2mu4_j85_xe50_mht);
   fChain->SetBranchAddress("HLT_mu4_j125_xe90_mht", &HLT_mu4_j125_xe90_mht, &b_HLT_mu4_j125_xe90_mht);
   fChain->SetBranchAddress("HLT_xe70", &HLT_xe70, &b_HLT_xe70);
   fChain->SetBranchAddress("HLT_xe70_mht", &HLT_xe70_mht, &b_HLT_xe70_mht);
   fChain->SetBranchAddress("HLT_xe70_mht_wEFMu", &HLT_xe70_mht_wEFMu, &b_HLT_xe70_mht_wEFMu);
   fChain->SetBranchAddress("HLT_xe70_tc_lcw", &HLT_xe70_tc_lcw, &b_HLT_xe70_tc_lcw);
   fChain->SetBranchAddress("HLT_xe70_tc_lcw_wEFMu", &HLT_xe70_tc_lcw_wEFMu, &b_HLT_xe70_tc_lcw_wEFMu);
   fChain->SetBranchAddress("HLT_xe80_tc_lcw_L1XE50", &HLT_xe80_tc_lcw_L1XE50, &b_HLT_xe80_tc_lcw_L1XE50);
   fChain->SetBranchAddress("HLT_xe90_tc_lcw_L1XE50", &HLT_xe90_tc_lcw_L1XE50, &b_HLT_xe90_tc_lcw_L1XE50);
   fChain->SetBranchAddress("HLT_xe90_mht_L1XE50", &HLT_xe90_mht_L1XE50, &b_HLT_xe90_mht_L1XE50);
   fChain->SetBranchAddress("HLT_xe90_tc_lcw_wEFMu_L1XE50", &HLT_xe90_tc_lcw_wEFMu_L1XE50, &b_HLT_xe90_tc_lcw_wEFMu_L1XE50);
   fChain->SetBranchAddress("HLT_xe90_mht_wEFMu_L1XE50", &HLT_xe90_mht_wEFMu_L1XE50, &b_HLT_xe90_mht_wEFMu_L1XE50);
   fChain->SetBranchAddress("HLT_xe100_L1XE50", &HLT_xe100_L1XE50, &b_HLT_xe100_L1XE50);
   fChain->SetBranchAddress("HLT_xe100_wEFMu_L1XE50", &HLT_xe100_wEFMu_L1XE50, &b_HLT_xe100_wEFMu_L1XE50);
   fChain->SetBranchAddress("HLT_xe100_tc_lcw_L1XE50", &HLT_xe100_tc_lcw_L1XE50, &b_HLT_xe100_tc_lcw_L1XE50);
   fChain->SetBranchAddress("HLT_xe100_mht_L1XE50", &HLT_xe100_mht_L1XE50, &b_HLT_xe100_mht_L1XE50);
   fChain->SetBranchAddress("HLT_xe100_tc_lcw_wEFMu_L1XE50", &HLT_xe100_tc_lcw_wEFMu_L1XE50, &b_HLT_xe100_tc_lcw_wEFMu_L1XE50);
   fChain->SetBranchAddress("HLT_xe100_mht_wEFMu_L1XE50", &HLT_xe100_mht_wEFMu_L1XE50, &b_HLT_xe100_mht_wEFMu_L1XE50);
   fChain->SetBranchAddress("HLT_xe110_L1XE50", &HLT_xe110_L1XE50, &b_HLT_xe110_L1XE50);
   fChain->SetBranchAddress("HLT_xe110_tc_em_L1XE50", &HLT_xe110_tc_em_L1XE50, &b_HLT_xe110_tc_em_L1XE50);
   fChain->SetBranchAddress("HLT_xe110_wEFMu_L1XE50", &HLT_xe110_wEFMu_L1XE50, &b_HLT_xe110_wEFMu_L1XE50);
   fChain->SetBranchAddress("HLT_xe110_tc_em_wEFMu_L1XE50", &HLT_xe110_tc_em_wEFMu_L1XE50, &b_HLT_xe110_tc_em_wEFMu_L1XE50);
   fChain->SetBranchAddress("HLT_xe110_mht_L1XE50", &HLT_xe110_mht_L1XE50, &b_HLT_xe110_mht_L1XE50);
   fChain->SetBranchAddress("HLT_xe90_mht_L1XE40", &HLT_xe90_mht_L1XE40, &b_HLT_xe90_mht_L1XE40);
   fChain->SetBranchAddress("HLT_xe50_mht_L1XE20", &HLT_xe50_mht_L1XE20, &b_HLT_xe50_mht_L1XE20);
   fChain->SetBranchAddress("HLT_j85_L1J40", &HLT_j85_L1J40, &b_HLT_j85_L1J40);
   fChain->SetBranchAddress("HLT_j125_L1J50", &HLT_j125_L1J50, &b_HLT_j125_L1J50);
   fChain->SetBranchAddress("HLT_e26_lhtight_nod0_ivarloose", &HLT_e26_lhtight_nod0_ivarloose, &b_HLT_e26_lhtight_nod0_ivarloose);
   fChain->SetBranchAddress("HLT_e60_lhmedium_nod0", &HLT_e60_lhmedium_nod0, &b_HLT_e60_lhmedium_nod0);
   fChain->SetBranchAddress("HLT_e60_medium", &HLT_e60_medium, &b_HLT_e60_medium);
   fChain->SetBranchAddress("HLT_e140_lhloose_nod0", &HLT_e140_lhloose_nod0, &b_HLT_e140_lhloose_nod0);
   fChain->SetBranchAddress("HLT_mu26_ivarmedium", &HLT_mu26_ivarmedium, &b_HLT_mu26_ivarmedium);
   fChain->SetBranchAddress("ttbarNNLOWeight", &ttbarNNLOWeight, &b_ttbarNNLOWeight);
   fChain->SetBranchAddress("ttbarNNLOWeightUp", &ttbarNNLOWeightUp, &b_ttbarNNLOWeightUp);
   fChain->SetBranchAddress("ttbarNNLOWeightDown", &ttbarNNLOWeightDown, &b_ttbarNNLOWeightDown);
   fChain->SetBranchAddress("truthTopPt", &truthTopPt, &b_truthTopPt);
   fChain->SetBranchAddress("truthAntiTopPt", &truthAntiTopPt, &b_truthAntiTopPt);
   fChain->SetBranchAddress("truthTtbarPt", &truthTtbarPt, &b_truthTtbarPt);
   fChain->SetBranchAddress("truthTtbarM", &truthTtbarM, &b_truthTtbarM);
   fChain->SetBranchAddress("x1", &x1, &b_x1);
   fChain->SetBranchAddress("x2", &x2, &b_x2);
   fChain->SetBranchAddress("pdf1", &pdf1, &b_pdf1);
   fChain->SetBranchAddress("pdf2", &pdf2, &b_pdf2);
   fChain->SetBranchAddress("scalePDF", &scalePDF, &b_scalePDF);
   fChain->SetBranchAddress("id1", &id1, &b_id1);
   fChain->SetBranchAddress("id2", &id2, &b_id2);
   fChain->SetBranchAddress("PRWHash", &PRWHash, &b_PRWHash);
   fChain->SetBranchAddress("EventNumber", &EventNumber, &b_EventNumber);
   fChain->SetBranchAddress("xsec", &xsec, &b_xsec);
   fChain->SetBranchAddress("TrueHt", &TrueHt, &b_TrueHt);
   fChain->SetBranchAddress("DatasetNumber", &DatasetNumber, &b_DatasetNumber);
   fChain->SetBranchAddress("RunNumber", &RunNumber, &b_RunNumber);
   fChain->SetBranchAddress("RandomRunNumber", &RandomRunNumber, &b_RandomRunNumber);
   fChain->SetBranchAddress("FS", &FS, &b_FS);
   Notify();
}

inline Bool_t SusySkimHiggsinoBase::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

inline void SusySkimHiggsinoBase::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
inline Int_t SusySkimHiggsinoBase::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}

