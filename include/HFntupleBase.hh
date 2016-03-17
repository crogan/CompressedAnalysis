//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Wed Mar 16 21:41:52 2016 by ROOT version 5.34/34
// from TTree HFntupleNONE/HFntupleNONE
// found on file: HFntuple.root
//////////////////////////////////////////////////////////

#ifndef HFntupleBase_h
#define HFntupleBase_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include <vector>
#include <vector>

using namespace std;

class HFntupleBase {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   Int_t           RunNumber;
   Bool_t          Cleaning;
   Bool_t          JetCleaning;
   Bool_t          MuonCleaning;
   Bool_t          coreFlags;
   Bool_t          SCTflag;
   Bool_t          coreInfo;
   Int_t           numVtx;
   Int_t           numGoodVtx;
   Int_t           nj_good;
   Int_t           nj_good_forward;
   Int_t           nj_good_central;
   Double_t        MT;
   Double_t        mlb1;
   Double_t        mlb2;
   Double_t        mlb_min;
   Int_t           lbn;
   Int_t           bcid;
   Int_t           passGRL;
   Double_t        truthttbarpt;
   Double_t        averageIntPerXing;
   Double_t        pileupweight;
   Double_t        AnalysisWeight;
   Double_t        EventWeight;
   ULong64_t       EventNumber;
   Double_t        w_MV1_1;
   Double_t        w_MV1_2;
   Double_t        w_MV1_3;
   Int_t           charge_1lep;
   Int_t           charge_2lep;
   Double_t        phi_1lep;
   Double_t        phi_2lep;
   Double_t        eta_1lep;
   Double_t        eta_2lep;
   Int_t           num_bjets;
   Double_t        eT_miss;
   Double_t        sumet;
   Double_t        softclus;
   Double_t        mll;
   Double_t        ptll;
   Double_t        mll_baseline;
   Double_t        pT_1lep;
   Double_t        pT_2lep;
   Double_t        pT_1el;
   Double_t        pT_2el;
   Double_t        pT_1mu;
   Double_t        pT_2mu;
   Double_t        id_1lep;
   Double_t        id_2lep;
   Int_t           jet1_truthmatch;
   Int_t           jet2_truthmatch;
   Double_t        pT_1jet;
   Double_t        pT_2jet;
   Double_t        pT_3jet;
   Double_t        pT_4jet;
   Double_t        pT_5jet;
   Double_t        pT_6jet;
   Double_t        eta_1jet;
   Double_t        eta_2jet;
   Double_t        eta_3jet;
   Double_t        eta_4jet;
   Double_t        eta_5jet;
   Double_t        eta_6jet;
   Double_t        phi_1jet;
   Double_t        phi_2jet;
   Double_t        phi_3jet;
   Double_t        phi_4jet;
   Double_t        phi_5jet;
   Double_t        phi_6jet;
   Double_t        pT_1bjet;
   Double_t        pT_2bjet;
   Double_t        dPhi_1jet;
   Double_t        dPhi_2jet;
   Double_t        dPhi_3jet;
   Double_t        dPhi_4jet;
   Double_t        dPhi_1bjet;
   Double_t        dPhi_2bjet;
   Int_t           num_bjets25;
   Int_t           num_bjets30;
   Int_t           num_bjets40;
   Double_t        elecSF;
   Double_t        muonSF;
   Double_t        btagSFCentral;
   Double_t        jvtSF;
   Double_t        elecSF_EFF_Iso_Down;
   Double_t        elecSF_EFF_Iso_Up;
   Double_t        elecSF_EFF_ID_Down;
   Double_t        elecSF_EFF_ID_Up;
   Double_t        elecSF_EFF_Reco_Down;
   Double_t        elecSF_EFF_Reco_Up;
   Double_t        elecSF_EFF_Trigger_Down;
   Double_t        elecSF_EFF_Trigger_Up;
   Double_t        muonSF_EFF_STAT_Down;
   Double_t        muonSF_EFF_STAT_Up;
   Double_t        muonSF_EFF_SYS_Down;
   Double_t        muonSF_EFF_SYS_Up;
   Double_t        muonSF_EFF_TrigStatUnc_Down;
   Double_t        muonSF_EFF_TrigStatUnc_Up;
   Double_t        muonSF_EFF_TrigSystUnc_Down;
   Double_t        muonSF_EFF_TrigSystUnc_Up;
   Double_t        muonSF_ISO_STAT_Down;
   Double_t        muonSF_ISO_STAT_Up;
   Double_t        muonSF_ISO_SYS_Down;
   Double_t        muonSF_ISO_SYS_Up;
   Double_t        bEffUpWeight;
   Double_t        bEffDownWeight;
   Double_t        cEffUpWeight;
   Double_t        cEffDownWeight;
   Double_t        lEffUpWeight;
   Double_t        lEffDownWeight;
   Double_t        extrapolationUpWeight;
   Double_t        extrapolationDownWeight;
   Double_t        jvtSFup;
   Double_t        jvtSFdown;
   Int_t           nJets;
   vector<float>   *jet_px;
   vector<float>   *jet_py;
   vector<float>   *jet_pz;
   vector<float>   *jet_e;
   vector<float>   *jet_MV2c20;
   vector<float>   *jet_chf;
   vector<int>     *jet_truthflav;
   vector<int>     *jet_truthmatched;
   vector<float>   *jet_jvtxf;
   vector<float>   *jet_BCH_CORR_CELL;
   vector<float>   *jet_emfrac;
   Int_t           ngamma_good;
   Int_t           type_1gamma;
   Int_t           origin_1gamma;
   Double_t        pT_1gamma;
   Double_t        pT_2gamma;
   Double_t        eta_1gamma;
   Double_t        eta_2gamma;
   Double_t        phi_1gamma;
   Double_t        phi_2gamma;
   Double_t        dPhi_1gamma;
   Double_t        dPhi_2gamma;
   Int_t           nEl;
   Int_t           nEl_baseline;
   vector<float>   *el_px;
   vector<float>   *el_py;
   vector<float>   *el_pz;
   vector<float>   *el_e;
   Int_t           nMu;
   Int_t           nMu_cosmic;
   Int_t           nMu_baseline;
   vector<float>   *mu_px;
   vector<float>   *mu_py;
   vector<float>   *mu_pz;
   vector<float>   *mu_e;
   Float_t         MET_px;
   Float_t         MET_py;
   Float_t         MET_pt;
   Float_t         MET_px_orig;
   Float_t         MET_py_orig;
   Float_t         MET_pt_orig;
   Float_t         MET_px_truth;
   Float_t         MET_py_truth;
   Float_t         MET_pt_truth;
   Float_t         MET_RefFinal;
   Int_t           HLT_mu20_iloose_L1MU15;
   Int_t           HLT_mu50;
   Int_t           HLT_2mu14;
   Int_t           HLT_e60_lhmedium;
   Int_t           HLT_2e17_lhloose;
   Int_t           HLT_e120_lhloose;
   Int_t           HLT_xe100;
   Int_t           HLT_xe80;
   Int_t           HLT_xe70;
   Int_t           HLT_xe70_tc_lcw;
   Int_t           HLT_g140_loose;
   Int_t           HLT_e24_lhmedium_L1EM20VH;
   Int_t           HLT_e24_lhmedium_L1EM18VH;
   Int_t           HLT_mu18_mu8noL1;
   Int_t           HLT_mu22_mu8noL1;
   Int_t           HLT_mu24_mu8noL1;
   Int_t           HLT_e17_lhloose_mu14;
   Int_t           HLT_xe100_mht_wEFMu;
   Int_t           HLT_xe100_wEFMu;
   Int_t           HLT_xe100_mht;
   Double_t        jvt_1jet;
   Double_t        jvt_2jet;
   Double_t        jvt_3jet;
   Double_t        jvt_4jet;
   Double_t        jvt_5jet;
   Double_t        jvt_6jet;
   Double_t        refele;
   Double_t        refjet;
   Double_t        refmuons;
   Double_t        truthMETfilter;
   ULong64_t       PRWhash;
   Bool_t          isElTrigMatched;
   Bool_t          isMuTrigMatched;
   Int_t           btagzerolep_channel;
   Int_t           passtauveto;
   Double_t        ht;
   Double_t        drbbjet;
   Double_t        drbbjetht;
   Double_t        eT_miss_prime;
   Int_t           zdecay;
   Int_t           ttbardecay;
   Double_t        truthptV;
   Double_t        dPhi_met_trackmet;
   Int_t           btag1e_channel;
   Int_t           btag1mu_channel;
   Int_t           btag2e_channel;
   Int_t           btag2mu_channel;
   Int_t           btagemu_channel;
   Double_t        amt;
   Double_t        mj0_12;
   Double_t        mj1_12;
   Double_t        pt0_12;
   Double_t        pt1_12;
   Double_t        mj0_08;
   Double_t        mj1_08;
   Double_t        pt0_08;
   Double_t        pt1_08;
   Double_t        amt_from03;
   Double_t        mj0_12_from03;
   Double_t        mj1_12_from03;
   Double_t        pt0_12_from03;
   Double_t        pt1_12_from03;
   Double_t        mj0_08_from03;
   Double_t        mj1_08_from03;
   Double_t        pt0_08_from03;
   Double_t        pt1_08_from03;
   Double_t        mbjj0;
   Double_t        mbjj1;
   Double_t        mTb;
   Double_t        mTb_truth;
   Double_t        mT_min;
   Double_t        mT_min_light;
   Double_t        mT_b_min;
   Double_t        metsig;
   Int_t           nJets_fat;
   vector<float>   *fat_jet_px;
   vector<float>   *fat_jet_py;
   vector<float>   *fat_jet_pz;
   vector<float>   *fat_jet_e;
   vector<float>   *fat_jet_MV1;
   vector<float>   *fat_jet_chf;
   vector<int>     *fat_jet_truthflav;
   vector<int>     *fat_jet_truthmatched;
   vector<float>   *fat_jet_jvtxf;
   vector<float>   *fat_jet_BCH_CORR_CELL;
   vector<float>   *fat_jet_emfrac;
   Float_t         eT_miss_LocHadTopo;
   Double_t        eT_miss_TST;
   Double_t        eT_miss_track;
   Double_t        topoetcone20_1gamma;
   Double_t        ptvarcone20_1gamma;
   Double_t        topoetcone40_1gamma;
   Double_t        ptvarcone40_1gamma;
   Int_t           pdgId1_1;
   Int_t           pdgId1_2;
   Int_t           pdgId2_1;
   Int_t           pdgId2_2;
   Double_t        ISR_px;
   Double_t        ISR_py;
   Double_t        ISR_pz;
   Double_t        ISR_e;
   Double_t        ISR1_px;
   Double_t        ISR1_py;
   Double_t        ISR1_pz;
   Double_t        ISR1_e;
   Double_t        ISR2_px;
   Double_t        ISR2_py;
   Double_t        ISR2_pz;
   Double_t        ISR2_e;
   Double_t        stop1_t_px;
   Double_t        stop1_t_py;
   Double_t        stop1_t_pz;
   Double_t        stop1_t_e;
   Double_t        stop1_b_px;
   Double_t        stop1_b_py;
   Double_t        stop1_b_pz;
   Double_t        stop1_b_e;
   Double_t        stop1_w1_px;
   Double_t        stop1_w1_py;
   Double_t        stop1_w1_pz;
   Double_t        stop1_w1_e;
   Double_t        stop1_w2_px;
   Double_t        stop1_w2_py;
   Double_t        stop1_w2_pz;
   Double_t        stop1_w2_e;
   Double_t        stop1_xi_px;
   Double_t        stop1_xi_py;
   Double_t        stop1_xi_pz;
   Double_t        stop1_xi_e;
   Double_t        stop2_t_px;
   Double_t        stop2_t_py;
   Double_t        stop2_t_pz;
   Double_t        stop2_t_e;
   Double_t        stop2_b_px;
   Double_t        stop2_b_py;
   Double_t        stop2_b_pz;
   Double_t        stop2_b_e;
   Double_t        stop2_w1_px;
   Double_t        stop2_w1_py;
   Double_t        stop2_w1_pz;
   Double_t        stop2_w1_e;
   Double_t        stop2_w2_px;
   Double_t        stop2_w2_py;
   Double_t        stop2_w2_pz;
   Double_t        stop2_w2_e;
   Double_t        stop2_xi_px;
   Double_t        stop2_xi_py;
   Double_t        stop2_xi_pz;
   Double_t        stop2_xi_e;
   Double_t        dPhi_min;
   Double_t        pT_1lightjet;
   Double_t        meff;
   Double_t        MET_sig;

   // List of branches
   TBranch        *b_RunNumber;   //!
   TBranch        *b_Cleaning;   //!
   TBranch        *b_JetCleaning;   //!
   TBranch        *b_MuonCleaning;   //!
   TBranch        *b_coreFlags;   //!
   TBranch        *b_SCTflag;   //!
   TBranch        *b_coreInfo;   //!
   TBranch        *b_numVtx;   //!
   TBranch        *b_numGoodVtx;   //!
   TBranch        *b_nj_good;   //!
   TBranch        *b_nj_good_forward;   //!
   TBranch        *b_nj_good_central;   //!
   TBranch        *b_MT;   //!
   TBranch        *b_mlb1;   //!
   TBranch        *b_mlb2;   //!
   TBranch        *b_mlb_min;   //!
   TBranch        *b_lbn;   //!
   TBranch        *b_bcid;   //!
   TBranch        *b_passGRL;   //!
   TBranch        *b_truthttbarpt;   //!
   TBranch        *b_averageIntPerXing;   //!
   TBranch        *b_pileupweight;   //!
   TBranch        *b_AnalysisWeight;   //!
   TBranch        *b_EventWeight;   //!
   TBranch        *b_EventNumber;   //!
   TBranch        *b_w_MV1_1;   //!
   TBranch        *b_w_MV1_2;   //!
   TBranch        *b_w_MV1_3;   //!
   TBranch        *b_charge_1lep;   //!
   TBranch        *b_charge_2lep;   //!
   TBranch        *b_phi_1lep;   //!
   TBranch        *b_phi_2lep;   //!
   TBranch        *b_eta_1lep;   //!
   TBranch        *b_eta_2lep;   //!
   TBranch        *b_num_bjets;   //!
   TBranch        *b_eT_miss;   //!
   TBranch        *b_sumet;   //!
   TBranch        *b_softclus;   //!
   TBranch        *b_mll;   //!
   TBranch        *b_ptll;   //!
   TBranch        *b_mll_baseline;   //!
   TBranch        *b_pT_1lep;   //!
   TBranch        *b_pT_2lep;   //!
   TBranch        *b_pT_1el;   //!
   TBranch        *b_pT_2el;   //!
   TBranch        *b_pT_1mu;   //!
   TBranch        *b_pT_2mu;   //!
   TBranch        *b_id_1lep;   //!
   TBranch        *b_id_2lep;   //!
   TBranch        *b_jet1_truthmatch;   //!
   TBranch        *b_jet2_truthmatch;   //!
   TBranch        *b_pT_1jet;   //!
   TBranch        *b_pT_2jet;   //!
   TBranch        *b_pT_3jet;   //!
   TBranch        *b_pT_4jet;   //!
   TBranch        *b_pT_5jet;   //!
   TBranch        *b_pT_6jet;   //!
   TBranch        *b_eta_1jet;   //!
   TBranch        *b_eta_2jet;   //!
   TBranch        *b_eta_3jet;   //!
   TBranch        *b_eta_4jet;   //!
   TBranch        *b_eta_5jet;   //!
   TBranch        *b_eta_6jet;   //!
   TBranch        *b_phi_1jet;   //!
   TBranch        *b_phi_2jet;   //!
   TBranch        *b_phi_3jet;   //!
   TBranch        *b_phi_4jet;   //!
   TBranch        *b_phi_5jet;   //!
   TBranch        *b_phi_6jet;   //!
   TBranch        *b_pT_1bjet;   //!
   TBranch        *b_pT_2bjet;   //!
   TBranch        *b_dPhi_1jet;   //!
   TBranch        *b_dPhi_2jet;   //!
   TBranch        *b_dPhi_3jet;   //!
   TBranch        *b_dPhi_4jet;   //!
   TBranch        *b_dPhi_1bjet;   //!
   TBranch        *b_dPhi_2bjet;   //!
   TBranch        *b_num_bjets25;   //!
   TBranch        *b_num_bjets30;   //!
   TBranch        *b_num_bjets40;   //!
   TBranch        *b_elecSF;   //!
   TBranch        *b_muonSF;   //!
   TBranch        *b_bEffSFCent;   //!
   TBranch        *b_jvtSF;   //!
   TBranch        *b_elecSF_EFF_Iso_Down;   //!
   TBranch        *b_elecSF_EFF_Iso_Up;   //!
   TBranch        *b_elecSF_EFF_ID_Down;   //!
   TBranch        *b_elecSF_EFF_ID_Up;   //!
   TBranch        *b_elecSF_EFF_Reco_Down;   //!
   TBranch        *b_elecSF_EFF_Reco_Up;   //!
   TBranch        *b_elecSF_EFF_Trigger_Down;   //!
   TBranch        *b_elecSF_EFF_Trigger_Up;   //!
   TBranch        *b_muonSF_EFF_STAT_Down;   //!
   TBranch        *b_muonSF_EFF_STAT_Up;   //!
   TBranch        *b_muonSF_EFF_SYS_Down;   //!
   TBranch        *b_muonSF_EFF_SYS_Up;   //!
   TBranch        *b_muonSF_EFF_TrigStatUnc_Down;   //!
   TBranch        *b_muonSF_EFF_TrigStatUnc_Up;   //!
   TBranch        *b_muonSF_EFF_TrigSystUnc_Down;   //!
   TBranch        *b_muonSF_EFF_TrigSystUnc_Up;   //!
   TBranch        *b_muonSF_ISO_STAT_Down;   //!
   TBranch        *b_muonSF_ISO_STAT_Up;   //!
   TBranch        *b_muonSF_ISO_SYS_Down;   //!
   TBranch        *b_muonSF_ISO_SYS_Up;   //!
   TBranch        *b_bEffUp;   //!
   TBranch        *b_bEffDown;   //!
   TBranch        *b_cEffUp;   //!
   TBranch        *b_cEffDown;   //!
   TBranch        *b_lEffUp;   //!
   TBranch        *b_lEffDown;   //!
   TBranch        *b_extrapUp;   //!
   TBranch        *b_extrapDown;   //!
   TBranch        *b_jvtSFup;   //!
   TBranch        *b_jvtSFdown;   //!
   TBranch        *b_nJets;   //!
   TBranch        *b_jet_px;   //!
   TBranch        *b_jet_py;   //!
   TBranch        *b_jet_pz;   //!
   TBranch        *b_jet_e;   //!
   TBranch        *b_jet_MV2c20;   //!
   TBranch        *b_jet_chf;   //!
   TBranch        *b_jet_truthflav;   //!
   TBranch        *b_jet_truthmatched;   //!
   TBranch        *b_jet_jvtxf;   //!
   TBranch        *b_jet_BCH_CORR_CELL;   //!
   TBranch        *b_jet_emfrac;   //!
   TBranch        *b_ngamma_good;   //!
   TBranch        *b_type_1gamma;   //!
   TBranch        *b_origin_1gamma;   //!
   TBranch        *b_pT_1gamma;   //!
   TBranch        *b_pT_2gamma;   //!
   TBranch        *b_eta_1gamma;   //!
   TBranch        *b_eta_2gamma;   //!
   TBranch        *b_phi_1gamma;   //!
   TBranch        *b_phi_2gamma;   //!
   TBranch        *b_dPhi_1gamma;   //!
   TBranch        *b_dPhi_2gamma;   //!
   TBranch        *b_nEl;   //!
   TBranch        *b_nEl_baseline;   //!
   TBranch        *b_el_px;   //!
   TBranch        *b_el_py;   //!
   TBranch        *b_el_pz;   //!
   TBranch        *b_el_e;   //!
   TBranch        *b_nMu;   //!
   TBranch        *b_nMu_cosmic;   //!
   TBranch        *b_nMu_baseline;   //!
   TBranch        *b_mu_px;   //!
   TBranch        *b_mu_py;   //!
   TBranch        *b_mu_pz;   //!
   TBranch        *b_mu_e;   //!
   TBranch        *b_MET_px;   //!
   TBranch        *b_MET_py;   //!
   TBranch        *b_MET_pt;   //!
   TBranch        *b_MET_px_orig;   //!
   TBranch        *b_MET_py_orig;   //!
   TBranch        *b_MET_pt_orig;   //!
   TBranch        *b_MET_px_truth;   //!
   TBranch        *b_MET_py_truth;   //!
   TBranch        *b_MET_pt_truth;   //!
   TBranch        *b_MET_RefFinal;   //!
   TBranch        *b_HLT_mu20_iloose_L1MU15;   //!
   TBranch        *b_HLT_mu50;   //!
   TBranch        *b_HLT_2mu14;   //!
   TBranch        *b_HLT_e60_lhmedium;   //!
   TBranch        *b_HLT_2e17_lhloose;   //!
   TBranch        *b_HLT_e120_lhloose;   //!
   TBranch        *b_HLT_xe100;   //!
   TBranch        *b_HLT_xe80;   //!
   TBranch        *b_HLT_xe70;   //!
   TBranch        *b_HLT_xe70_tc_lcw;   //!
   TBranch        *b_HLT_g140_loose;   //!
   TBranch        *b_HLT_e24_lhmedium_L1EM20VH;   //!
   TBranch        *b_HLT_e24_lhmedium_L1EM18VH;   //!
   TBranch        *b_HLT_mu18_mu8noL1;   //!
   TBranch        *b_HLT_mu22_mu8noL1;   //!
   TBranch        *b_HLT_mu24_mu8noL1;   //!
   TBranch        *b_HLT_e17_lhloose_mu14;   //!
   TBranch        *b_HLT_xe100_mht_wEFMu;   //!
   TBranch        *b_HLT_xe100_wEFMu;   //!
   TBranch        *b_HLT_xe100_mht;   //!
   TBranch        *b_jvt_1jet;   //!
   TBranch        *b_jvt_2jet;   //!
   TBranch        *b_jvt_3jet;   //!
   TBranch        *b_jvt_4jet;   //!
   TBranch        *b_jvt_5jet;   //!
   TBranch        *b_jvt_6jet;   //!
   TBranch        *b_refele;   //!
   TBranch        *b_refjet;   //!
   TBranch        *b_refmuons;   //!
   TBranch        *b_truthMETfilter;   //!
   TBranch        *b_PRWhash;   //!
   TBranch        *b_isElTrigMatched;   //!
   TBranch        *b_isMuTrigMatched;   //!
   TBranch        *b_btagzerolep_channel;   //!
   TBranch        *b_passtauveto;   //!
   TBranch        *b_ht;   //!
   TBranch        *b_drbbjet;   //!
   TBranch        *b_drbbjetht;   //!
   TBranch        *b_eT_miss_prime;   //!
   TBranch        *b_zdecay;   //!
   TBranch        *b_ttbardecay;   //!
   TBranch        *b_truthptV;   //!
   TBranch        *b_dPhi_met_trackmet;   //!
   TBranch        *b_btag1e_channel;   //!
   TBranch        *b_btag1mu_channel;   //!
   TBranch        *b_btag2e_channel;   //!
   TBranch        *b_btag2mu_channel;   //!
   TBranch        *b_btagemu_channel;   //!
   TBranch        *b_amt;   //!
   TBranch        *b_mj0_12;   //!
   TBranch        *b_mj1_12;   //!
   TBranch        *b_pt0_12;   //!
   TBranch        *b_pt1_12;   //!
   TBranch        *b_mj0_08;   //!
   TBranch        *b_mj1_08;   //!
   TBranch        *b_pt0_08;   //!
   TBranch        *b_pt1_08;   //!
   TBranch        *b_amt_from03;   //!
   TBranch        *b_mj0_12_from03;   //!
   TBranch        *b_mj1_12_from03;   //!
   TBranch        *b_pt0_12_from03;   //!
   TBranch        *b_pt1_12_from03;   //!
   TBranch        *b_mj0_08_from03;   //!
   TBranch        *b_mj1_08_from03;   //!
   TBranch        *b_pt0_08_from03;   //!
   TBranch        *b_pt1_08_from03;   //!
   TBranch        *b_mbjj0;   //!
   TBranch        *b_mbjj1;   //!
   TBranch        *b_mTb;   //!
   TBranch        *b_mTb_truth;   //!
   TBranch        *b_mT_min;   //!
   TBranch        *b_mT_min_light;   //!
   TBranch        *b_mT_b_min;   //!
   TBranch        *b_metsig;   //!
   TBranch        *b_nJets_fat;   //!
   TBranch        *b_fat_jet_px;   //!
   TBranch        *b_fat_jet_py;   //!
   TBranch        *b_fat_jet_pz;   //!
   TBranch        *b_fat_jet_e;   //!
   TBranch        *b_fat_jet_MV1;   //!
   TBranch        *b_fat_jet_chf;   //!
   TBranch        *b_fat_jet_truthflav;   //!
   TBranch        *b_fat_jet_truthmatched;   //!
   TBranch        *b_fat_jet_jvtxf;   //!
   TBranch        *b_fat_jet_BCH_CORR_CELL;   //!
   TBranch        *b_fat_jet_emfrac;   //!
   TBranch        *b_eT_miss_LocHadTopo;   //!
   TBranch        *b_eT_miss_TST;   //!
   TBranch        *b_eT_miss_track;   //!
   TBranch        *b_topoetcone20_1gamma;   //!
   TBranch        *b_ptvarcone20_1gamma;   //!
   TBranch        *b_topoetcone40_1gamma;   //!
   TBranch        *b_ptvarcone40_1gamma;   //!
   TBranch        *b_pdgId1_1;   //!
   TBranch        *b_pdgId1_2;   //!
   TBranch        *b_pdgId2_1;   //!
   TBranch        *b_pdgId2_2;   //!
   TBranch        *b_ISR_px;   //!
   TBranch        *b_ISR_py;   //!
   TBranch        *b_ISR_pz;   //!
   TBranch        *b_ISR_e;   //!
   TBranch        *b_ISR1_px;   //!
   TBranch        *b_ISR1_py;   //!
   TBranch        *b_ISR1_pz;   //!
   TBranch        *b_ISR1_e;   //!
   TBranch        *b_ISR2_px;   //!
   TBranch        *b_ISR2_py;   //!
   TBranch        *b_ISR2_pz;   //!
   TBranch        *b_ISR2_e;   //!
   TBranch        *b_stop1_t_px;   //!
   TBranch        *b_stop1_t_py;   //!
   TBranch        *b_stop1_t_pz;   //!
   TBranch        *b_stop1_t_e;   //!
   TBranch        *b_stop1_b_px;   //!
   TBranch        *b_stop1_b_py;   //!
   TBranch        *b_stop1_b_pz;   //!
   TBranch        *b_stop1_b_e;   //!
   TBranch        *b_stop1_w1_px;   //!
   TBranch        *b_stop1_w1_py;   //!
   TBranch        *b_stop1_w1_pz;   //!
   TBranch        *b_stop1_w1_e;   //!
   TBranch        *b_stop1_w2_px;   //!
   TBranch        *b_stop1_w2_py;   //!
   TBranch        *b_stop1_w2_pz;   //!
   TBranch        *b_stop1_w2_e;   //!
   TBranch        *b_stop1_xi_px;   //!
   TBranch        *b_stop1_xi_py;   //!
   TBranch        *b_stop1_xi_pz;   //!
   TBranch        *b_stop1_xi_e;   //!
   TBranch        *b_stop2_t_px;   //!
   TBranch        *b_stop2_t_py;   //!
   TBranch        *b_stop2_t_pz;   //!
   TBranch        *b_stop2_t_e;   //!
   TBranch        *b_stop2_b_px;   //!
   TBranch        *b_stop2_b_py;   //!
   TBranch        *b_stop2_b_pz;   //!
   TBranch        *b_stop2_b_e;   //!
   TBranch        *b_stop2_w1_px;   //!
   TBranch        *b_stop2_w1_py;   //!
   TBranch        *b_stop2_w1_pz;   //!
   TBranch        *b_stop2_w1_e;   //!
   TBranch        *b_stop2_w2_px;   //!
   TBranch        *b_stop2_w2_py;   //!
   TBranch        *b_stop2_w2_pz;   //!
   TBranch        *b_stop2_w2_e;   //!
   TBranch        *b_stop2_xi_px;   //!
   TBranch        *b_stop2_xi_py;   //!
   TBranch        *b_stop2_xi_pz;   //!
   TBranch        *b_stop2_xi_e;   //!
   TBranch        *b_dPhi_min;   //!
   TBranch        *b_pT_1lightjet;   //!
   TBranch        *b_meff;   //!
   TBranch        *b_MET_sig;   //!

   HFntupleBase(TTree *tree=0);
   virtual ~HFntupleBase();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

inline HFntupleBase::HFntupleBase(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("HFntuple.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("HFntuple.root");
      }
      f->GetObject("HFntupleNONE",tree);

   }
   Init(tree);
}

inline HFntupleBase::~HFntupleBase()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

inline Int_t HFntupleBase::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
inline Long64_t HFntupleBase::LoadTree(Long64_t entry)
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

inline void HFntupleBase::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   jet_px = 0;
   jet_py = 0;
   jet_pz = 0;
   jet_e = 0;
   jet_MV2c20 = 0;
   jet_chf = 0;
   jet_truthflav = 0;
   jet_truthmatched = 0;
   jet_jvtxf = 0;
   jet_BCH_CORR_CELL = 0;
   jet_emfrac = 0;
   el_px = 0;
   el_py = 0;
   el_pz = 0;
   el_e = 0;
   mu_px = 0;
   mu_py = 0;
   mu_pz = 0;
   mu_e = 0;
   fat_jet_px = 0;
   fat_jet_py = 0;
   fat_jet_pz = 0;
   fat_jet_e = 0;
   fat_jet_MV1 = 0;
   fat_jet_chf = 0;
   fat_jet_truthflav = 0;
   fat_jet_truthmatched = 0;
   fat_jet_jvtxf = 0;
   fat_jet_BCH_CORR_CELL = 0;
   fat_jet_emfrac = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("RunNumber", &RunNumber, &b_RunNumber);
   fChain->SetBranchAddress("Cleaning", &Cleaning, &b_Cleaning);
   fChain->SetBranchAddress("JetCleaning", &JetCleaning, &b_JetCleaning);
   fChain->SetBranchAddress("MuonCleaning", &MuonCleaning, &b_MuonCleaning);
   fChain->SetBranchAddress("coreFlags", &coreFlags, &b_coreFlags);
   fChain->SetBranchAddress("SCTflag", &SCTflag, &b_SCTflag);
   fChain->SetBranchAddress("coreInfo", &coreInfo, &b_coreInfo);
   fChain->SetBranchAddress("numVtx", &numVtx, &b_numVtx);
   fChain->SetBranchAddress("numGoodVtx", &numGoodVtx, &b_numGoodVtx);
   fChain->SetBranchAddress("nj_good", &nj_good, &b_nj_good);
   fChain->SetBranchAddress("nj_good_forward", &nj_good_forward, &b_nj_good_forward);
   fChain->SetBranchAddress("nj_good_central", &nj_good_central, &b_nj_good_central);
   fChain->SetBranchAddress("MT", &MT, &b_MT);
   fChain->SetBranchAddress("mlb1", &mlb1, &b_mlb1);
   fChain->SetBranchAddress("mlb2", &mlb2, &b_mlb2);
   fChain->SetBranchAddress("mlb_min", &mlb_min, &b_mlb_min);
   fChain->SetBranchAddress("lbn", &lbn, &b_lbn);
   fChain->SetBranchAddress("bcid", &bcid, &b_bcid);
   fChain->SetBranchAddress("passGRL", &passGRL, &b_passGRL);
   fChain->SetBranchAddress("truthttbarpt", &truthttbarpt, &b_truthttbarpt);
   fChain->SetBranchAddress("averageIntPerXing", &averageIntPerXing, &b_averageIntPerXing);
   fChain->SetBranchAddress("pileupweight", &pileupweight, &b_pileupweight);
   fChain->SetBranchAddress("AnalysisWeight", &AnalysisWeight, &b_AnalysisWeight);
   fChain->SetBranchAddress("EventWeight", &EventWeight, &b_EventWeight);
   fChain->SetBranchAddress("EventNumber", &EventNumber, &b_EventNumber);
   fChain->SetBranchAddress("w_MV1_1", &w_MV1_1, &b_w_MV1_1);
   fChain->SetBranchAddress("w_MV1_2", &w_MV1_2, &b_w_MV1_2);
   fChain->SetBranchAddress("w_MV1_3", &w_MV1_3, &b_w_MV1_3);
   fChain->SetBranchAddress("charge_1lep", &charge_1lep, &b_charge_1lep);
   fChain->SetBranchAddress("charge_2lep", &charge_2lep, &b_charge_2lep);
   fChain->SetBranchAddress("phi_1lep", &phi_1lep, &b_phi_1lep);
   fChain->SetBranchAddress("phi_2lep", &phi_2lep, &b_phi_2lep);
   fChain->SetBranchAddress("eta_1lep", &eta_1lep, &b_eta_1lep);
   fChain->SetBranchAddress("eta_2lep", &eta_2lep, &b_eta_2lep);
   fChain->SetBranchAddress("num_bjets", &num_bjets, &b_num_bjets);
   fChain->SetBranchAddress("eT_miss", &eT_miss, &b_eT_miss);
   fChain->SetBranchAddress("sumet", &sumet, &b_sumet);
   fChain->SetBranchAddress("softclus", &softclus, &b_softclus);
   fChain->SetBranchAddress("mll", &mll, &b_mll);
   fChain->SetBranchAddress("ptll", &ptll, &b_ptll);
   fChain->SetBranchAddress("mll_baseline", &mll_baseline, &b_mll_baseline);
   fChain->SetBranchAddress("pT_1lep", &pT_1lep, &b_pT_1lep);
   fChain->SetBranchAddress("pT_2lep", &pT_2lep, &b_pT_2lep);
   fChain->SetBranchAddress("pT_1el", &pT_1el, &b_pT_1el);
   fChain->SetBranchAddress("pT_2el", &pT_2el, &b_pT_2el);
   fChain->SetBranchAddress("pT_1mu", &pT_1mu, &b_pT_1mu);
   fChain->SetBranchAddress("pT_2mu", &pT_2mu, &b_pT_2mu);
   fChain->SetBranchAddress("id_1lep", &id_1lep, &b_id_1lep);
   fChain->SetBranchAddress("id_2lep", &id_2lep, &b_id_2lep);
   fChain->SetBranchAddress("jet1_truthmatch", &jet1_truthmatch, &b_jet1_truthmatch);
   fChain->SetBranchAddress("jet2_truthmatch", &jet2_truthmatch, &b_jet2_truthmatch);
   fChain->SetBranchAddress("pT_1jet", &pT_1jet, &b_pT_1jet);
   fChain->SetBranchAddress("pT_2jet", &pT_2jet, &b_pT_2jet);
   fChain->SetBranchAddress("pT_3jet", &pT_3jet, &b_pT_3jet);
   fChain->SetBranchAddress("pT_4jet", &pT_4jet, &b_pT_4jet);
   fChain->SetBranchAddress("pT_5jet", &pT_5jet, &b_pT_5jet);
   fChain->SetBranchAddress("pT_6jet", &pT_6jet, &b_pT_6jet);
   fChain->SetBranchAddress("eta_1jet", &eta_1jet, &b_eta_1jet);
   fChain->SetBranchAddress("eta_2jet", &eta_2jet, &b_eta_2jet);
   fChain->SetBranchAddress("eta_3jet", &eta_3jet, &b_eta_3jet);
   fChain->SetBranchAddress("eta_4jet", &eta_4jet, &b_eta_4jet);
   fChain->SetBranchAddress("eta_5jet", &eta_5jet, &b_eta_5jet);
   fChain->SetBranchAddress("eta_6jet", &eta_6jet, &b_eta_6jet);
   fChain->SetBranchAddress("phi_1jet", &phi_1jet, &b_phi_1jet);
   fChain->SetBranchAddress("phi_2jet", &phi_2jet, &b_phi_2jet);
   fChain->SetBranchAddress("phi_3jet", &phi_3jet, &b_phi_3jet);
   fChain->SetBranchAddress("phi_4jet", &phi_4jet, &b_phi_4jet);
   fChain->SetBranchAddress("phi_5jet", &phi_5jet, &b_phi_5jet);
   fChain->SetBranchAddress("phi_6jet", &phi_6jet, &b_phi_6jet);
   fChain->SetBranchAddress("pT_1bjet", &pT_1bjet, &b_pT_1bjet);
   fChain->SetBranchAddress("pT_2bjet", &pT_2bjet, &b_pT_2bjet);
   fChain->SetBranchAddress("dPhi_1jet", &dPhi_1jet, &b_dPhi_1jet);
   fChain->SetBranchAddress("dPhi_2jet", &dPhi_2jet, &b_dPhi_2jet);
   fChain->SetBranchAddress("dPhi_3jet", &dPhi_3jet, &b_dPhi_3jet);
   fChain->SetBranchAddress("dPhi_4jet", &dPhi_4jet, &b_dPhi_4jet);
   fChain->SetBranchAddress("dPhi_1bjet", &dPhi_1bjet, &b_dPhi_1bjet);
   fChain->SetBranchAddress("dPhi_2bjet", &dPhi_2bjet, &b_dPhi_2bjet);
   fChain->SetBranchAddress("num_bjets25", &num_bjets25, &b_num_bjets25);
   fChain->SetBranchAddress("num_bjets30", &num_bjets30, &b_num_bjets30);
   fChain->SetBranchAddress("num_bjets40", &num_bjets40, &b_num_bjets40);
   fChain->SetBranchAddress("elecSF", &elecSF, &b_elecSF);
   fChain->SetBranchAddress("muonSF", &muonSF, &b_muonSF);
   fChain->SetBranchAddress("btagSFCentral", &btagSFCentral, &b_bEffSFCent);
   fChain->SetBranchAddress("jvtSF", &jvtSF, &b_jvtSF);
   fChain->SetBranchAddress("elecSF_EFF_Iso_Down", &elecSF_EFF_Iso_Down, &b_elecSF_EFF_Iso_Down);
   fChain->SetBranchAddress("elecSF_EFF_Iso_Up", &elecSF_EFF_Iso_Up, &b_elecSF_EFF_Iso_Up);
   fChain->SetBranchAddress("elecSF_EFF_ID_Down", &elecSF_EFF_ID_Down, &b_elecSF_EFF_ID_Down);
   fChain->SetBranchAddress("elecSF_EFF_ID_Up", &elecSF_EFF_ID_Up, &b_elecSF_EFF_ID_Up);
   fChain->SetBranchAddress("elecSF_EFF_Reco_Down", &elecSF_EFF_Reco_Down, &b_elecSF_EFF_Reco_Down);
   fChain->SetBranchAddress("elecSF_EFF_Reco_Up", &elecSF_EFF_Reco_Up, &b_elecSF_EFF_Reco_Up);
   fChain->SetBranchAddress("elecSF_EFF_Trigger_Down", &elecSF_EFF_Trigger_Down, &b_elecSF_EFF_Trigger_Down);
   fChain->SetBranchAddress("elecSF_EFF_Trigger_Up", &elecSF_EFF_Trigger_Up, &b_elecSF_EFF_Trigger_Up);
   fChain->SetBranchAddress("muonSF_EFF_STAT_Down", &muonSF_EFF_STAT_Down, &b_muonSF_EFF_STAT_Down);
   fChain->SetBranchAddress("muonSF_EFF_STAT_Up", &muonSF_EFF_STAT_Up, &b_muonSF_EFF_STAT_Up);
   fChain->SetBranchAddress("muonSF_EFF_SYS_Down", &muonSF_EFF_SYS_Down, &b_muonSF_EFF_SYS_Down);
   fChain->SetBranchAddress("muonSF_EFF_SYS_Up", &muonSF_EFF_SYS_Up, &b_muonSF_EFF_SYS_Up);
   fChain->SetBranchAddress("muonSF_EFF_TrigStatUnc_Down", &muonSF_EFF_TrigStatUnc_Down, &b_muonSF_EFF_TrigStatUnc_Down);
   fChain->SetBranchAddress("muonSF_EFF_TrigStatUnc_Up", &muonSF_EFF_TrigStatUnc_Up, &b_muonSF_EFF_TrigStatUnc_Up);
   fChain->SetBranchAddress("muonSF_EFF_TrigSystUnc_Down", &muonSF_EFF_TrigSystUnc_Down, &b_muonSF_EFF_TrigSystUnc_Down);
   fChain->SetBranchAddress("muonSF_EFF_TrigSystUnc_Up", &muonSF_EFF_TrigSystUnc_Up, &b_muonSF_EFF_TrigSystUnc_Up);
   fChain->SetBranchAddress("muonSF_ISO_STAT_Down", &muonSF_ISO_STAT_Down, &b_muonSF_ISO_STAT_Down);
   fChain->SetBranchAddress("muonSF_ISO_STAT_Up", &muonSF_ISO_STAT_Up, &b_muonSF_ISO_STAT_Up);
   fChain->SetBranchAddress("muonSF_ISO_SYS_Down", &muonSF_ISO_SYS_Down, &b_muonSF_ISO_SYS_Down);
   fChain->SetBranchAddress("muonSF_ISO_SYS_Up", &muonSF_ISO_SYS_Up, &b_muonSF_ISO_SYS_Up);
   fChain->SetBranchAddress("bEffUpWeight", &bEffUpWeight, &b_bEffUp);
   fChain->SetBranchAddress("bEffDownWeight", &bEffDownWeight, &b_bEffDown);
   fChain->SetBranchAddress("cEffUpWeight", &cEffUpWeight, &b_cEffUp);
   fChain->SetBranchAddress("cEffDownWeight", &cEffDownWeight, &b_cEffDown);
   fChain->SetBranchAddress("lEffUpWeight", &lEffUpWeight, &b_lEffUp);
   fChain->SetBranchAddress("lEffDownWeight", &lEffDownWeight, &b_lEffDown);
   fChain->SetBranchAddress("extrapolationUpWeight", &extrapolationUpWeight, &b_extrapUp);
   fChain->SetBranchAddress("extrapolationDownWeight", &extrapolationDownWeight, &b_extrapDown);
   fChain->SetBranchAddress("jvtSFup", &jvtSFup, &b_jvtSFup);
   fChain->SetBranchAddress("jvtSFdown", &jvtSFdown, &b_jvtSFdown);
   fChain->SetBranchAddress("nJets", &nJets, &b_nJets);
   fChain->SetBranchAddress("jet_px", &jet_px, &b_jet_px);
   fChain->SetBranchAddress("jet_py", &jet_py, &b_jet_py);
   fChain->SetBranchAddress("jet_pz", &jet_pz, &b_jet_pz);
   fChain->SetBranchAddress("jet_e", &jet_e, &b_jet_e);
   fChain->SetBranchAddress("jet_MV2c20", &jet_MV2c20, &b_jet_MV2c20);
   fChain->SetBranchAddress("jet_chf", &jet_chf, &b_jet_chf);
   fChain->SetBranchAddress("jet_truthflav", &jet_truthflav, &b_jet_truthflav);
   fChain->SetBranchAddress("jet_truthmatched", &jet_truthmatched, &b_jet_truthmatched);
   fChain->SetBranchAddress("jet_jvtxf", &jet_jvtxf, &b_jet_jvtxf);
   fChain->SetBranchAddress("jet_BCH_CORR_CELL", &jet_BCH_CORR_CELL, &b_jet_BCH_CORR_CELL);
   fChain->SetBranchAddress("jet_emfrac", &jet_emfrac, &b_jet_emfrac);
   fChain->SetBranchAddress("ngamma_good", &ngamma_good, &b_ngamma_good);
   fChain->SetBranchAddress("type_1gamma", &type_1gamma, &b_type_1gamma);
   fChain->SetBranchAddress("origin_1gamma", &origin_1gamma, &b_origin_1gamma);
   fChain->SetBranchAddress("pT_1gamma", &pT_1gamma, &b_pT_1gamma);
   fChain->SetBranchAddress("pT_2gamma", &pT_2gamma, &b_pT_2gamma);
   fChain->SetBranchAddress("eta_1gamma", &eta_1gamma, &b_eta_1gamma);
   fChain->SetBranchAddress("eta_2gamma", &eta_2gamma, &b_eta_2gamma);
   fChain->SetBranchAddress("phi_1gamma", &phi_1gamma, &b_phi_1gamma);
   fChain->SetBranchAddress("phi_2gamma", &phi_2gamma, &b_phi_2gamma);
   fChain->SetBranchAddress("dPhi_1gamma", &dPhi_1gamma, &b_dPhi_1gamma);
   fChain->SetBranchAddress("dPhi_2gamma", &dPhi_2gamma, &b_dPhi_2gamma);
   fChain->SetBranchAddress("nEl", &nEl, &b_nEl);
   fChain->SetBranchAddress("nEl_baseline", &nEl_baseline, &b_nEl_baseline);
   fChain->SetBranchAddress("el_px", &el_px, &b_el_px);
   fChain->SetBranchAddress("el_py", &el_py, &b_el_py);
   fChain->SetBranchAddress("el_pz", &el_pz, &b_el_pz);
   fChain->SetBranchAddress("el_e", &el_e, &b_el_e);
   fChain->SetBranchAddress("nMu", &nMu, &b_nMu);
   fChain->SetBranchAddress("nMu_cosmic", &nMu_cosmic, &b_nMu_cosmic);
   fChain->SetBranchAddress("nMu_baseline", &nMu_baseline, &b_nMu_baseline);
   fChain->SetBranchAddress("mu_px", &mu_px, &b_mu_px);
   fChain->SetBranchAddress("mu_py", &mu_py, &b_mu_py);
   fChain->SetBranchAddress("mu_pz", &mu_pz, &b_mu_pz);
   fChain->SetBranchAddress("mu_e", &mu_e, &b_mu_e);
   fChain->SetBranchAddress("MET_px", &MET_px, &b_MET_px);
   fChain->SetBranchAddress("MET_py", &MET_py, &b_MET_py);
   fChain->SetBranchAddress("MET_pt", &MET_pt, &b_MET_pt);
   fChain->SetBranchAddress("MET_px_orig", &MET_px_orig, &b_MET_px_orig);
   fChain->SetBranchAddress("MET_py_orig", &MET_py_orig, &b_MET_py_orig);
   fChain->SetBranchAddress("MET_pt_orig", &MET_pt_orig, &b_MET_pt_orig);
   fChain->SetBranchAddress("MET_px_truth", &MET_px_truth, &b_MET_px_truth);
   fChain->SetBranchAddress("MET_py_truth", &MET_py_truth, &b_MET_py_truth);
   fChain->SetBranchAddress("MET_pt_truth", &MET_pt_truth, &b_MET_pt_truth);
   fChain->SetBranchAddress("MET_RefFinal", &MET_RefFinal, &b_MET_RefFinal);
   fChain->SetBranchAddress("HLT_mu20_iloose_L1MU15", &HLT_mu20_iloose_L1MU15, &b_HLT_mu20_iloose_L1MU15);
   fChain->SetBranchAddress("HLT_mu50", &HLT_mu50, &b_HLT_mu50);
   fChain->SetBranchAddress("HLT_2mu14", &HLT_2mu14, &b_HLT_2mu14);
   fChain->SetBranchAddress("HLT_e60_lhmedium", &HLT_e60_lhmedium, &b_HLT_e60_lhmedium);
   fChain->SetBranchAddress("HLT_2e17_lhloose", &HLT_2e17_lhloose, &b_HLT_2e17_lhloose);
   fChain->SetBranchAddress("HLT_e120_lhloose", &HLT_e120_lhloose, &b_HLT_e120_lhloose);
   fChain->SetBranchAddress("HLT_xe100", &HLT_xe100, &b_HLT_xe100);
   fChain->SetBranchAddress("HLT_xe80", &HLT_xe80, &b_HLT_xe80);
   fChain->SetBranchAddress("HLT_xe70", &HLT_xe70, &b_HLT_xe70);
   fChain->SetBranchAddress("HLT_xe70_tc_lcw", &HLT_xe70_tc_lcw, &b_HLT_xe70_tc_lcw);
   fChain->SetBranchAddress("HLT_g140_loose", &HLT_g140_loose, &b_HLT_g140_loose);
   fChain->SetBranchAddress("HLT_e24_lhmedium_L1EM20VH", &HLT_e24_lhmedium_L1EM20VH, &b_HLT_e24_lhmedium_L1EM20VH);
   fChain->SetBranchAddress("HLT_e24_lhmedium_L1EM18VH", &HLT_e24_lhmedium_L1EM18VH, &b_HLT_e24_lhmedium_L1EM18VH);
   fChain->SetBranchAddress("HLT_mu18_mu8noL1", &HLT_mu18_mu8noL1, &b_HLT_mu18_mu8noL1);
   fChain->SetBranchAddress("HLT_mu22_mu8noL1", &HLT_mu22_mu8noL1, &b_HLT_mu22_mu8noL1);
   fChain->SetBranchAddress("HLT_mu24_mu8noL1", &HLT_mu24_mu8noL1, &b_HLT_mu24_mu8noL1);
   fChain->SetBranchAddress("HLT_e17_lhloose_mu14", &HLT_e17_lhloose_mu14, &b_HLT_e17_lhloose_mu14);
   fChain->SetBranchAddress("HLT_xe100_mht_wEFMu", &HLT_xe100_mht_wEFMu, &b_HLT_xe100_mht_wEFMu);
   fChain->SetBranchAddress("HLT_xe100_wEFMu", &HLT_xe100_wEFMu, &b_HLT_xe100_wEFMu);
   fChain->SetBranchAddress("HLT_xe100_mht", &HLT_xe100_mht, &b_HLT_xe100_mht);
   fChain->SetBranchAddress("jvt_1jet", &jvt_1jet, &b_jvt_1jet);
   fChain->SetBranchAddress("jvt_2jet", &jvt_2jet, &b_jvt_2jet);
   fChain->SetBranchAddress("jvt_3jet", &jvt_3jet, &b_jvt_3jet);
   fChain->SetBranchAddress("jvt_4jet", &jvt_4jet, &b_jvt_4jet);
   fChain->SetBranchAddress("jvt_5jet", &jvt_5jet, &b_jvt_5jet);
   fChain->SetBranchAddress("jvt_6jet", &jvt_6jet, &b_jvt_6jet);
   fChain->SetBranchAddress("refele", &refele, &b_refele);
   fChain->SetBranchAddress("refjet", &refjet, &b_refjet);
   fChain->SetBranchAddress("refmuons", &refmuons, &b_refmuons);
   fChain->SetBranchAddress("truthMETfilter", &truthMETfilter, &b_truthMETfilter);
   fChain->SetBranchAddress("PRWhash", &PRWhash, &b_PRWhash);
   fChain->SetBranchAddress("isElTrigMatched", &isElTrigMatched, &b_isElTrigMatched);
   fChain->SetBranchAddress("isMuTrigMatched", &isMuTrigMatched, &b_isMuTrigMatched);
   fChain->SetBranchAddress("btagzerolep_channel", &btagzerolep_channel, &b_btagzerolep_channel);
   fChain->SetBranchAddress("passtauveto", &passtauveto, &b_passtauveto);
   fChain->SetBranchAddress("ht", &ht, &b_ht);
   fChain->SetBranchAddress("drbbjet", &drbbjet, &b_drbbjet);
   fChain->SetBranchAddress("drbbjetht", &drbbjetht, &b_drbbjetht);
   fChain->SetBranchAddress("eT_miss_prime", &eT_miss_prime, &b_eT_miss_prime);
   fChain->SetBranchAddress("zdecay", &zdecay, &b_zdecay);
   fChain->SetBranchAddress("ttbardecay", &ttbardecay, &b_ttbardecay);
   fChain->SetBranchAddress("truthptV", &truthptV, &b_truthptV);
   fChain->SetBranchAddress("dPhi_met_trackmet", &dPhi_met_trackmet, &b_dPhi_met_trackmet);
   fChain->SetBranchAddress("btag1e_channel", &btag1e_channel, &b_btag1e_channel);
   fChain->SetBranchAddress("btag1mu_channel", &btag1mu_channel, &b_btag1mu_channel);
   fChain->SetBranchAddress("btag2e_channel", &btag2e_channel, &b_btag2e_channel);
   fChain->SetBranchAddress("btag2mu_channel", &btag2mu_channel, &b_btag2mu_channel);
   fChain->SetBranchAddress("btagemu_channel", &btagemu_channel, &b_btagemu_channel);
   fChain->SetBranchAddress("amt", &amt, &b_amt);
   fChain->SetBranchAddress("mj0_12", &mj0_12, &b_mj0_12);
   fChain->SetBranchAddress("mj1_12", &mj1_12, &b_mj1_12);
   fChain->SetBranchAddress("pt0_12", &pt0_12, &b_pt0_12);
   fChain->SetBranchAddress("pt1_12", &pt1_12, &b_pt1_12);
   fChain->SetBranchAddress("mj0_08", &mj0_08, &b_mj0_08);
   fChain->SetBranchAddress("mj1_08", &mj1_08, &b_mj1_08);
   fChain->SetBranchAddress("pt0_08", &pt0_08, &b_pt0_08);
   fChain->SetBranchAddress("pt1_08", &pt1_08, &b_pt1_08);
   fChain->SetBranchAddress("amt_from03", &amt_from03, &b_amt_from03);
   fChain->SetBranchAddress("mj0_12_from03", &mj0_12_from03, &b_mj0_12_from03);
   fChain->SetBranchAddress("mj1_12_from03", &mj1_12_from03, &b_mj1_12_from03);
   fChain->SetBranchAddress("pt0_12_from03", &pt0_12_from03, &b_pt0_12_from03);
   fChain->SetBranchAddress("pt1_12_from03", &pt1_12_from03, &b_pt1_12_from03);
   fChain->SetBranchAddress("mj0_08_from03", &mj0_08_from03, &b_mj0_08_from03);
   fChain->SetBranchAddress("mj1_08_from03", &mj1_08_from03, &b_mj1_08_from03);
   fChain->SetBranchAddress("pt0_08_from03", &pt0_08_from03, &b_pt0_08_from03);
   fChain->SetBranchAddress("pt1_08_from03", &pt1_08_from03, &b_pt1_08_from03);
   fChain->SetBranchAddress("mbjj0", &mbjj0, &b_mbjj0);
   fChain->SetBranchAddress("mbjj1", &mbjj1, &b_mbjj1);
   fChain->SetBranchAddress("mTb", &mTb, &b_mTb);
   fChain->SetBranchAddress("mTb_truth", &mTb_truth, &b_mTb_truth);
   fChain->SetBranchAddress("mT_min", &mT_min, &b_mT_min);
   fChain->SetBranchAddress("mT_min_light", &mT_min_light, &b_mT_min_light);
   fChain->SetBranchAddress("mT_b_min", &mT_b_min, &b_mT_b_min);
   fChain->SetBranchAddress("metsig", &metsig, &b_metsig);
   fChain->SetBranchAddress("nJets_fat", &nJets_fat, &b_nJets_fat);
   fChain->SetBranchAddress("fat_jet_px", &fat_jet_px, &b_fat_jet_px);
   fChain->SetBranchAddress("fat_jet_py", &fat_jet_py, &b_fat_jet_py);
   fChain->SetBranchAddress("fat_jet_pz", &fat_jet_pz, &b_fat_jet_pz);
   fChain->SetBranchAddress("fat_jet_e", &fat_jet_e, &b_fat_jet_e);
   fChain->SetBranchAddress("fat_jet_MV1", &fat_jet_MV1, &b_fat_jet_MV1);
   fChain->SetBranchAddress("fat_jet_chf", &fat_jet_chf, &b_fat_jet_chf);
   fChain->SetBranchAddress("fat_jet_truthflav", &fat_jet_truthflav, &b_fat_jet_truthflav);
   fChain->SetBranchAddress("fat_jet_truthmatched", &fat_jet_truthmatched, &b_fat_jet_truthmatched);
   fChain->SetBranchAddress("fat_jet_jvtxf", &fat_jet_jvtxf, &b_fat_jet_jvtxf);
   fChain->SetBranchAddress("fat_jet_BCH_CORR_CELL", &fat_jet_BCH_CORR_CELL, &b_fat_jet_BCH_CORR_CELL);
   fChain->SetBranchAddress("fat_jet_emfrac", &fat_jet_emfrac, &b_fat_jet_emfrac);
   fChain->SetBranchAddress("eT_miss_LocHadTopo", &eT_miss_LocHadTopo, &b_eT_miss_LocHadTopo);
   fChain->SetBranchAddress("eT_miss_TST", &eT_miss_TST, &b_eT_miss_TST);
   fChain->SetBranchAddress("eT_miss_track", &eT_miss_track, &b_eT_miss_track);
   fChain->SetBranchAddress("topoetcone20_1gamma", &topoetcone20_1gamma, &b_topoetcone20_1gamma);
   fChain->SetBranchAddress("ptvarcone20_1gamma", &ptvarcone20_1gamma, &b_ptvarcone20_1gamma);
   fChain->SetBranchAddress("topoetcone40_1gamma", &topoetcone40_1gamma, &b_topoetcone40_1gamma);
   fChain->SetBranchAddress("ptvarcone40_1gamma", &ptvarcone40_1gamma, &b_ptvarcone40_1gamma);
   fChain->SetBranchAddress("pdgId1_1", &pdgId1_1, &b_pdgId1_1);
   fChain->SetBranchAddress("pdgId1_2", &pdgId1_2, &b_pdgId1_2);
   fChain->SetBranchAddress("pdgId2_1", &pdgId2_1, &b_pdgId2_1);
   fChain->SetBranchAddress("pdgId2_2", &pdgId2_2, &b_pdgId2_2);
   fChain->SetBranchAddress("ISR_px", &ISR_px, &b_ISR_px);
   fChain->SetBranchAddress("ISR_py", &ISR_py, &b_ISR_py);
   fChain->SetBranchAddress("ISR_pz", &ISR_pz, &b_ISR_pz);
   fChain->SetBranchAddress("ISR_e", &ISR_e, &b_ISR_e);
   fChain->SetBranchAddress("ISR1_px", &ISR1_px, &b_ISR1_px);
   fChain->SetBranchAddress("ISR1_py", &ISR1_py, &b_ISR1_py);
   fChain->SetBranchAddress("ISR1_pz", &ISR1_pz, &b_ISR1_pz);
   fChain->SetBranchAddress("ISR1_e", &ISR1_e, &b_ISR1_e);
   fChain->SetBranchAddress("ISR2_px", &ISR2_px, &b_ISR2_px);
   fChain->SetBranchAddress("ISR2_py", &ISR2_py, &b_ISR2_py);
   fChain->SetBranchAddress("ISR2_pz", &ISR2_pz, &b_ISR2_pz);
   fChain->SetBranchAddress("ISR2_e", &ISR2_e, &b_ISR2_e);
   fChain->SetBranchAddress("stop1_t_px", &stop1_t_px, &b_stop1_t_px);
   fChain->SetBranchAddress("stop1_t_py", &stop1_t_py, &b_stop1_t_py);
   fChain->SetBranchAddress("stop1_t_pz", &stop1_t_pz, &b_stop1_t_pz);
   fChain->SetBranchAddress("stop1_t_e", &stop1_t_e, &b_stop1_t_e);
   fChain->SetBranchAddress("stop1_b_px", &stop1_b_px, &b_stop1_b_px);
   fChain->SetBranchAddress("stop1_b_py", &stop1_b_py, &b_stop1_b_py);
   fChain->SetBranchAddress("stop1_b_pz", &stop1_b_pz, &b_stop1_b_pz);
   fChain->SetBranchAddress("stop1_b_e", &stop1_b_e, &b_stop1_b_e);
   fChain->SetBranchAddress("stop1_w1_px", &stop1_w1_px, &b_stop1_w1_px);
   fChain->SetBranchAddress("stop1_w1_py", &stop1_w1_py, &b_stop1_w1_py);
   fChain->SetBranchAddress("stop1_w1_pz", &stop1_w1_pz, &b_stop1_w1_pz);
   fChain->SetBranchAddress("stop1_w1_e", &stop1_w1_e, &b_stop1_w1_e);
   fChain->SetBranchAddress("stop1_w2_px", &stop1_w2_px, &b_stop1_w2_px);
   fChain->SetBranchAddress("stop1_w2_py", &stop1_w2_py, &b_stop1_w2_py);
   fChain->SetBranchAddress("stop1_w2_pz", &stop1_w2_pz, &b_stop1_w2_pz);
   fChain->SetBranchAddress("stop1_w2_e", &stop1_w2_e, &b_stop1_w2_e);
   fChain->SetBranchAddress("stop1_xi_px", &stop1_xi_px, &b_stop1_xi_px);
   fChain->SetBranchAddress("stop1_xi_py", &stop1_xi_py, &b_stop1_xi_py);
   fChain->SetBranchAddress("stop1_xi_pz", &stop1_xi_pz, &b_stop1_xi_pz);
   fChain->SetBranchAddress("stop1_xi_e", &stop1_xi_e, &b_stop1_xi_e);
   fChain->SetBranchAddress("stop2_t_px", &stop2_t_px, &b_stop2_t_px);
   fChain->SetBranchAddress("stop2_t_py", &stop2_t_py, &b_stop2_t_py);
   fChain->SetBranchAddress("stop2_t_pz", &stop2_t_pz, &b_stop2_t_pz);
   fChain->SetBranchAddress("stop2_t_e", &stop2_t_e, &b_stop2_t_e);
   fChain->SetBranchAddress("stop2_b_px", &stop2_b_px, &b_stop2_b_px);
   fChain->SetBranchAddress("stop2_b_py", &stop2_b_py, &b_stop2_b_py);
   fChain->SetBranchAddress("stop2_b_pz", &stop2_b_pz, &b_stop2_b_pz);
   fChain->SetBranchAddress("stop2_b_e", &stop2_b_e, &b_stop2_b_e);
   fChain->SetBranchAddress("stop2_w1_px", &stop2_w1_px, &b_stop2_w1_px);
   fChain->SetBranchAddress("stop2_w1_py", &stop2_w1_py, &b_stop2_w1_py);
   fChain->SetBranchAddress("stop2_w1_pz", &stop2_w1_pz, &b_stop2_w1_pz);
   fChain->SetBranchAddress("stop2_w1_e", &stop2_w1_e, &b_stop2_w1_e);
   fChain->SetBranchAddress("stop2_w2_px", &stop2_w2_px, &b_stop2_w2_px);
   fChain->SetBranchAddress("stop2_w2_py", &stop2_w2_py, &b_stop2_w2_py);
   fChain->SetBranchAddress("stop2_w2_pz", &stop2_w2_pz, &b_stop2_w2_pz);
   fChain->SetBranchAddress("stop2_w2_e", &stop2_w2_e, &b_stop2_w2_e);
   fChain->SetBranchAddress("stop2_xi_px", &stop2_xi_px, &b_stop2_xi_px);
   fChain->SetBranchAddress("stop2_xi_py", &stop2_xi_py, &b_stop2_xi_py);
   fChain->SetBranchAddress("stop2_xi_pz", &stop2_xi_pz, &b_stop2_xi_pz);
   fChain->SetBranchAddress("stop2_xi_e", &stop2_xi_e, &b_stop2_xi_e);
   fChain->SetBranchAddress("dPhi_min", &dPhi_min, &b_dPhi_min);
   fChain->SetBranchAddress("pT_1lightjet", &pT_1lightjet, &b_pT_1lightjet);
   fChain->SetBranchAddress("meff", &meff, &b_meff);
   fChain->SetBranchAddress("MET_sig", &MET_sig, &b_MET_sig);
   Notify();
}

inline Bool_t HFntupleBase::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

inline void HFntupleBase::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}

inline Int_t HFntupleBase::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
