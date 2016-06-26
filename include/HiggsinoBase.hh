//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Fri Jun 24 13:16:09 2016 by ROOT version 6.06/00
// from TTree outputTree/outputTree
// found on file: ttbar_MET_gt_100.root
//////////////////////////////////////////////////////////

#ifndef HiggsinoBase_h
#define HiggsinoBase_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include <vector>
#include <vector>

using namespace std;

class HiggsinoBase {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Double_t        MET;
   Double_t        MET_sumET;
   Double_t        MET_phi;
   Double_t        TrackMET;
   Double_t        TrackMET_sumET;
   Double_t        TrackMET_phi;
   Double_t        Mu;
   Double_t        HTincl;
   Double_t        VecHTincl;
   Double_t        HT;
   Double_t        VecHT;
   Double_t        mll;
   Double_t        DPhi_METJet;
   Double_t        DPhi_METJetLeading;
   Double_t        DPhi_METJetSecond;
   Long64_t        channel;
   Long64_t        is_OS;
   Double_t        Z_pt;
   Double_t        Z_phi;
   Double_t        Z_eta;
   Long64_t        EventNumber;
   Long64_t        RunNumber;
   Double_t        eventWeight;
   Double_t        sampleWeight;
   Double_t        pileupWeight;
   Long64_t        HLT_mu50;
   Long64_t        HLT_2mu14;
   Long64_t        HLT_mu24_mu8noL1;
   Long64_t        HLT_mu24;
   Long64_t        HLT_mu20_iloose_L1MU15;
   Long64_t        HLT_2mu10;
   Long64_t        HLT_mu10;
   Long64_t        HLT_mu22_mu8noL1;
   Long64_t        HLT_mu22;
   Long64_t        HLT_mu20_mu8noL1;
   Long64_t        HLT_mu20;
   Long64_t        HLT_mu18_mu8noL1;
   Long64_t        HLT_mu18;
   Long64_t        HLT_e24_lhmedium_iloose_L1EM18VH;
   Long64_t        HLT_e24_lhmedium_iloose_L1EM20VH;
   Long64_t        HLT_e60_lhmedium;
   Long64_t        HLT_2e17_lhloose;
   Long64_t        HLT_2e12_lhloose_L12EM10VH;
   Long64_t        HLT_e17_lhloose_mu14;
   Long64_t        HLT_e7_lhmedium_mu24;
   Long64_t        HLT_e24_lhmedium_L1EM20VH;
   Long64_t        HLT_e26_lhmedium_L1EM22VHI_mu8noL1;
   Long64_t        HLT_e24_lhmedium_L1EM20VHI_mu8noL1;
   Long64_t        HLT_xe70;
   Long64_t        HLT_xe80;
   Long64_t        HLT_xe80_wEFMu;
   Long64_t        HLT_xe100;
   Double_t        sf_trig_HLT_e60_lhmedium;
   Double_t        sfunc_trig_HLT_e60_lhmedium;
   Double_t        sf_trig_HLT_e24_lhmedium_iloose_L1EM18VH;
   Double_t        sfunc_trig_HLT_e24_lhmedium_iloose_L1EM18VH;
   Double_t        sf_trig_HLT_e24_lhmedium_L1EM20VH;
   Double_t        sfunc_trig_HLT_e24_lhmedium_L1EM20VH;
   Double_t        sf_trig_HLT_e24_lhmedium_iloose_L1EM20VH;
   Double_t        sfunc_trig_HLT_e24_lhmedium_iloose_L1EM20VH;
   Double_t        sf_trig_HLT_mu50;
   Double_t        sfunc_trig_HLT_mu50;
   Double_t        sf_trig_HLT_mu20_iloose_L1MU15;
   Double_t        sfunc_trig_HLT_mu20_iloose_L1MU15;
   Double_t        sf_trig_HLT_2e12_lhloose;
   Double_t        sfunc_trig_HLT_2e12_lhloose;
   Double_t        sf_trig_HLT_mu18_mu8noL1;
   Double_t        sfunc_trig_HLT_mu18_mu8noL1;
   Double_t        sf_trig_HLT_e17_lhloose_mu14;
   Double_t        sfunc_trig_HLT_e17_lhloose_mu14;
   Double_t        sf_trig_HLT_e7_lhmedium_mu24;
   Double_t        sfunc_trig_HLT_e7_lhmedium_mu24;
   Double_t        sf_trig_HLT_e26_lhmedium_L1EM22VHI_mu8noL1;
   Double_t        sfunc_trig_HLT_e26_lhmedium_L1EM22VHI_mu8noL1;
   Double_t        sf_trig_HLT_e24_lhmedium_L1EM20VHI_mu8noL1;
   Double_t        sfunc_trig_HLT_e24_lhmedium_L1EM20VHI_mu8noL1;
   Long64_t        eetrig;
   Long64_t        mmtrig;
   Long64_t        emtrig;
   Double_t        eetrigweight;
   Double_t        mmtrigweight;
   Double_t        emtrigweight;
   Double_t        trigweight;
   Double_t        eetrigweight_down;
   Double_t        mmtrigweight_down;
   Double_t        emtrigweight_down;
   Double_t        trigweight_down;
   Long64_t        eetrigor;
   Long64_t        mmtrigor;
   Long64_t        emtrigor;
   vector<double>  *mu_pT;
   vector<double>  *mu_eta;
   vector<double>  *mu_phi;
   vector<double>  *mu_E;
   vector<double>  *mu_m;
   vector<long>    *mu_nPrecLayers;
   vector<double>  *mu_raw_pT;
   vector<double>  *mu_pT_err;
   vector<double>  *mu_x2ndof;
   vector<double>  *mu_pBalanceSignif;
   vector<double>  *mu_eloss;
   vector<double>  *mu_paramEloss;
   vector<double>  *mu_measEloss;
   vector<double>  *mu_elossSigma;
   vector<double>  *mu_id_x2ndof;
   vector<double>  *mu_id_pT;
   vector<double>  *mu_id_qOverPsigma;
   vector<double>  *mu_id_pT_err;
   vector<double>  *mu_me_pT;
   vector<double>  *mu_qOverPsigma;
   vector<double>  *mu_qOverPsignif;
   vector<double>  *mu_me_qOverPsigma;
   vector<double>  *mu_me_x2ndof;
   vector<double>  *mu_me_pT_err;
   vector<double>  *mu_ms_pT;
   vector<double>  *mu_ms_qOverPsigma;
   vector<double>  *mu_ms_pT_err;
   vector<long>    *mu_quality;
   vector<long>    *muon;
   vector<double>  *mu_weight;
   vector<double>  *mu_ptcone20;
   vector<double>  *mu_ptcone30;
   vector<double>  *mu_ptvarcone20;
   vector<double>  *mu_ptvarcone30;
   vector<double>  *mu_topoetcone20;
   vector<double>  *mu_topoetcone30;
   vector<double>  *mu_d0sig;
   vector<double>  *mu_z0sintheta;
   vector<long>    *mu_isPrompt;
   vector<double>  *jet_pT;
   vector<double>  *jet_eta;
   vector<double>  *jet_phi;
   vector<double>  *jet_E;
   vector<double>  *jet_m;
   vector<long>    *jet;
   vector<double>  *jet_weight;
   vector<long>    *jet_btag;
   vector<double>  *jet_bMV2Weight;
   vector<double>  *el_pT;
   vector<double>  *el_eta;
   vector<double>  *el_phi;
   vector<double>  *el_E;
   vector<double>  *el_m;
   vector<long>    *electron;
   vector<double>  *el_weight;
   vector<double>  *el_ptcone20;
   vector<double>  *el_ptcone30;
   vector<double>  *el_ptvarcone20;
   vector<double>  *el_ptvarcone30;
   vector<double>  *el_topoetcone20;
   vector<double>  *el_topoetcone30;
   vector<double>  *el_d0sig;
   vector<double>  *el_z0sintheta;
   vector<long>    *el_isPrompt;
   vector<long>    *el_passAmbi;
   vector<double>  *lep_pT;
   vector<double>  *lep_eta;
   vector<double>  *lep_phi;
   vector<double>  *lep_E;
   vector<double>  *lep_m;
   vector<double>  *lep_truthPt;
   vector<double>  *lep_truthEta;
   vector<double>  *lep_truthPhi;
   vector<double>  *lep_truthE;
   vector<double>  *lep_truthGammaPt;
   vector<long>    *mu_match_HLT_mu50;
   vector<long>    *lep_match_HLT_mu50;
   vector<long>    *el_match_HLT_mu50;
   vector<long>    *mu_match_HLT_2mu14;
   vector<long>    *lep_match_HLT_2mu14;
   vector<long>    *el_match_HLT_2mu14;
   vector<long>    *mu_match_HLT_mu24_mu8noL1;
   vector<long>    *lep_match_HLT_mu24_mu8noL1;
   vector<long>    *el_match_HLT_mu24_mu8noL1;
   vector<long>    *mu_match_HLT_mu24;
   vector<long>    *lep_match_HLT_mu24;
   vector<long>    *el_match_HLT_mu24;
   vector<long>    *mu_match_HLT_mu20_iloose_L1MU15;
   vector<long>    *lep_match_HLT_mu20_iloose_L1MU15;
   vector<long>    *el_match_HLT_mu20_iloose_L1MU15;
   vector<long>    *mu_match_HLT_2mu10;
   vector<long>    *lep_match_HLT_2mu10;
   vector<long>    *el_match_HLT_2mu10;
   vector<long>    *mu_match_HLT_mu10;
   vector<long>    *lep_match_HLT_mu10;
   vector<long>    *el_match_HLT_mu10;
   vector<long>    *mu_match_HLT_mu22_mu8noL1;
   vector<long>    *lep_match_HLT_mu22_mu8noL1;
   vector<long>    *el_match_HLT_mu22_mu8noL1;
   vector<long>    *mu_match_HLT_mu22;
   vector<long>    *lep_match_HLT_mu22;
   vector<long>    *el_match_HLT_mu22;
   vector<long>    *mu_match_HLT_mu20_mu8noL1;
   vector<long>    *lep_match_HLT_mu20_mu8noL1;
   vector<long>    *el_match_HLT_mu20_mu8noL1;
   vector<long>    *mu_match_HLT_mu20;
   vector<long>    *lep_match_HLT_mu20;
   vector<long>    *el_match_HLT_mu20;
   vector<long>    *mu_match_HLT_mu18_mu8noL1;
   vector<long>    *lep_match_HLT_mu18_mu8noL1;
   vector<long>    *el_match_HLT_mu18_mu8noL1;
   vector<long>    *mu_match_HLT_mu18;
   vector<long>    *lep_match_HLT_mu18;
   vector<long>    *el_match_HLT_mu18;
   vector<long>    *mu_match_HLT_e24_lhmedium_iloose_L1EM18VH;
   vector<long>    *lep_match_HLT_e24_lhmedium_iloose_L1EM18VH;
   vector<long>    *el_match_HLT_e24_lhmedium_iloose_L1EM18VH;
   vector<long>    *mu_match_HLT_e24_lhmedium_iloose_L1EM20VH;
   vector<long>    *lep_match_HLT_e24_lhmedium_iloose_L1EM20VH;
   vector<long>    *el_match_HLT_e24_lhmedium_iloose_L1EM20VH;
   vector<long>    *mu_match_HLT_e60_lhmedium;
   vector<long>    *lep_match_HLT_e60_lhmedium;
   vector<long>    *el_match_HLT_e60_lhmedium;
   vector<long>    *mu_match_HLT_2e17_lhloose;
   vector<long>    *lep_match_HLT_2e17_lhloose;
   vector<long>    *el_match_HLT_2e17_lhloose;
   vector<long>    *mu_match_HLT_2e12_lhloose_L12EM10VH;
   vector<long>    *lep_match_HLT_2e12_lhloose_L12EM10VH;
   vector<long>    *el_match_HLT_2e12_lhloose_L12EM10VH;
   vector<long>    *mu_match_HLT_e17_lhloose_mu14;
   vector<long>    *lep_match_HLT_e17_lhloose_mu14;
   vector<long>    *el_match_HLT_e17_lhloose_mu14;
   vector<long>    *mu_match_HLT_e7_lhmedium_mu24;
   vector<long>    *lep_match_HLT_e7_lhmedium_mu24;
   vector<long>    *el_match_HLT_e7_lhmedium_mu24;
   vector<long>    *mu_match_HLT_e24_lhmedium_L1EM20VH;
   vector<long>    *lep_match_HLT_e24_lhmedium_L1EM20VH;
   vector<long>    *el_match_HLT_e24_lhmedium_L1EM20VH;
   vector<long>    *mu_match_HLT_e26_lhmedium_L1EM22VHI_mu8noL1;
   vector<long>    *lep_match_HLT_e26_lhmedium_L1EM22VHI_mu8noL1;
   vector<long>    *el_match_HLT_e26_lhmedium_L1EM22VHI_mu8noL1;
   vector<long>    *mu_match_HLT_e24_lhmedium_L1EM20VHI_mu8noL1;
   vector<long>    *lep_match_HLT_e24_lhmedium_L1EM20VHI_mu8noL1;
   vector<long>    *el_match_HLT_e24_lhmedium_L1EM20VHI_mu8noL1;
   vector<long>    *mu_match_HLT_xe70;
   vector<long>    *lep_match_HLT_xe70;
   vector<long>    *el_match_HLT_xe70;
   vector<long>    *mu_match_HLT_xe80;
   vector<long>    *lep_match_HLT_xe80;
   vector<long>    *el_match_HLT_xe80;
   vector<long>    *mu_match_HLT_xe80_wEFMu;
   vector<long>    *lep_match_HLT_xe80_wEFMu;
   vector<long>    *el_match_HLT_xe80_wEFMu;
   vector<long>    *mu_match_HLT_xe100;
   vector<long>    *lep_match_HLT_xe100;
   vector<long>    *el_match_HLT_xe100;
   vector<long>    *lep_tight;
   vector<double>  *lep_tight_weight;
   vector<long>    *lep_isPrompt;
   vector<double>  *lep_weight;
   vector<long>    *lep_pdgId;
   Long64_t        eetrig_match;
   Long64_t        emtrig_match;
   Long64_t        mmtrig_match;
   Long64_t        mmtrig_match1;
   Double_t        truth_ZpT;
   Double_t        truth_Zll;
   Long64_t        jet_n;
   Long64_t        el_n;
   Long64_t        mu_n;
   Long64_t        lep_n;
   Long64_t        bjet_n;
   Double_t        MT2W;
   Double_t        MT2Top;
   Long64_t        Pass_SUSY2_Triggers;
   Long64_t        PassedSUSYTriggers;
   vector<long>    *truthLepton_status;
   vector<double>  *truthLepton_pT;
   vector<double>  *truthLepton_eta;
   vector<double>  *truthLepton_phi;
   vector<double>  *truthLepton_E;
   vector<long>    *truthLepton_pdgID;
   vector<long>    *truthLepton_parent_pdgID;
   vector<long>    *truthLepton_match_electron;
   vector<double>  *truthLepton_weight_electron;
   vector<long>    *truthLepton_match_muon;
   vector<double>  *truthLepton_weight_muon;
   Long64_t        truthLepton_n;
   Long64_t        truthLepton_nWZel;
   Long64_t        truthLepton_nWZmu;
   Long64_t        truthLepton_nWZtau;
   Long64_t        truthLepton_nWZlep;
   Long64_t        truthPhoton_n;
   Double_t        truthMET_Filter;
   Double_t        truthMET_NonInt;
   Double_t        truthMET_NonIntPhi;
   Double_t        truthMET;
   Double_t        truthMET_Phi;
   Long64_t        jet_n_vetolep;
   Double_t        HT_vetolep;
   Long64_t        nVtx;
   vector<double>  *mu_ms_pt;
   vector<double>  *mu_ms_qoverpsigma;
   Float_t         weight1fb;
   Float_t         lepweight;
   Float_t         nGenEvents;

   // List of branches
   TBranch        *b_MET;   //!
   TBranch        *b_MET_sumET;   //!
   TBranch        *b_MET_phi;   //!
   TBranch        *b_TrackMET;   //!
   TBranch        *b_TrackMET_sumET;   //!
   TBranch        *b_TrackMET_phi;   //!
   TBranch        *b_Mu;   //!
   TBranch        *b_HTincl;   //!
   TBranch        *b_VecHTincl;   //!
   TBranch        *b_HT;   //!
   TBranch        *b_VecHT;   //!
   TBranch        *b_mll;   //!
   TBranch        *b_DPhi_METJet;   //!
   TBranch        *b_DPhi_METJetLeading;   //!
   TBranch        *b_DPhi_METJetSecond;   //!
   TBranch        *b_channel;   //!
   TBranch        *b_is_OS;   //!
   TBranch        *b_Z_pt;   //!
   TBranch        *b_Z_phi;   //!
   TBranch        *b_Z_eta;   //!
   TBranch        *b_EventNumber;   //!
   TBranch        *b_RunNumber;   //!
   TBranch        *b_eventWeight;   //!
   TBranch        *b_sampleWeight;   //!
   TBranch        *b_pileupWeight;   //!
   TBranch        *b_HLT_mu50;   //!
   TBranch        *b_HLT_2mu14;   //!
   TBranch        *b_HLT_mu24_mu8noL1;   //!
   TBranch        *b_HLT_mu24;   //!
   TBranch        *b_HLT_mu20_iloose_L1MU15;   //!
   TBranch        *b_HLT_2mu10;   //!
   TBranch        *b_HLT_mu10;   //!
   TBranch        *b_HLT_mu22_mu8noL1;   //!
   TBranch        *b_HLT_mu22;   //!
   TBranch        *b_HLT_mu20_mu8noL1;   //!
   TBranch        *b_HLT_mu20;   //!
   TBranch        *b_HLT_mu18_mu8noL1;   //!
   TBranch        *b_HLT_mu18;   //!
   TBranch        *b_HLT_e24_lhmedium_iloose_L1EM18VH;   //!
   TBranch        *b_HLT_e24_lhmedium_iloose_L1EM20VH;   //!
   TBranch        *b_HLT_e60_lhmedium;   //!
   TBranch        *b_HLT_2e17_lhloose;   //!
   TBranch        *b_HLT_2e12_lhloose_L12EM10VH;   //!
   TBranch        *b_HLT_e17_lhloose_mu14;   //!
   TBranch        *b_HLT_e7_lhmedium_mu24;   //!
   TBranch        *b_HLT_e24_lhmedium_L1EM20VH;   //!
   TBranch        *b_HLT_e26_lhmedium_L1EM22VHI_mu8noL1;   //!
   TBranch        *b_HLT_e24_lhmedium_L1EM20VHI_mu8noL1;   //!
   TBranch        *b_HLT_xe70;   //!
   TBranch        *b_HLT_xe80;   //!
   TBranch        *b_HLT_xe80_wEFMu;   //!
   TBranch        *b_HLT_xe100;   //!
   TBranch        *b_sf_trig_HLT_e60_lhmedium;   //!
   TBranch        *b_sfunc_trig_HLT_e60_lhmedium;   //!
   TBranch        *b_sf_trig_HLT_e24_lhmedium_iloose_L1EM18VH;   //!
   TBranch        *b_sfunc_trig_HLT_e24_lhmedium_iloose_L1EM18VH;   //!
   TBranch        *b_sf_trig_HLT_e24_lhmedium_L1EM20VH;   //!
   TBranch        *b_sfunc_trig_HLT_e24_lhmedium_L1EM20VH;   //!
   TBranch        *b_sf_trig_HLT_e24_lhmedium_iloose_L1EM20VH;   //!
   TBranch        *b_sfunc_trig_HLT_e24_lhmedium_iloose_L1EM20VH;   //!
   TBranch        *b_sf_trig_HLT_mu50;   //!
   TBranch        *b_sfunc_trig_HLT_mu50;   //!
   TBranch        *b_sf_trig_HLT_mu20_iloose_L1MU15;   //!
   TBranch        *b_sfunc_trig_HLT_mu20_iloose_L1MU15;   //!
   TBranch        *b_sf_trig_HLT_2e12_lhloose;   //!
   TBranch        *b_sfunc_trig_HLT_2e12_lhloose;   //!
   TBranch        *b_sf_trig_HLT_mu18_mu8noL1;   //!
   TBranch        *b_sfunc_trig_HLT_mu18_mu8noL1;   //!
   TBranch        *b_sf_trig_HLT_e17_lhloose_mu14;   //!
   TBranch        *b_sfunc_trig_HLT_e17_lhloose_mu14;   //!
   TBranch        *b_sf_trig_HLT_e7_lhmedium_mu24;   //!
   TBranch        *b_sfunc_trig_HLT_e7_lhmedium_mu24;   //!
   TBranch        *b_sf_trig_HLT_e26_lhmedium_L1EM22VHI_mu8noL1;   //!
   TBranch        *b_sfunc_trig_HLT_e26_lhmedium_L1EM22VHI_mu8noL1;   //!
   TBranch        *b_sf_trig_HLT_e24_lhmedium_L1EM20VHI_mu8noL1;   //!
   TBranch        *b_sfunc_trig_HLT_e24_lhmedium_L1EM20VHI_mu8noL1;   //!
   TBranch        *b_eetrig;   //!
   TBranch        *b_mmtrig;   //!
   TBranch        *b_emtrig;   //!
   TBranch        *b_eetrigweight;   //!
   TBranch        *b_mmtrigweight;   //!
   TBranch        *b_emtrigweight;   //!
   TBranch        *b_trigweight;   //!
   TBranch        *b_eetrigweight_down;   //!
   TBranch        *b_mmtrigweight_down;   //!
   TBranch        *b_emtrigweight_down;   //!
   TBranch        *b_trigweight_down;   //!
   TBranch        *b_eetrigor;   //!
   TBranch        *b_mmtrigor;   //!
   TBranch        *b_emtrigor;   //!
   TBranch        *b_mu_pT;   //!
   TBranch        *b_mu_eta;   //!
   TBranch        *b_mu_phi;   //!
   TBranch        *b_mu_E;   //!
   TBranch        *b_mu_m;   //!
   TBranch        *b_mu_nPrecLayers;   //!
   TBranch        *b_mu_raw_pT;   //!
   TBranch        *b_mu_pT_err;   //!
   TBranch        *b_mu_x2ndof;   //!
   TBranch        *b_mu_pBalanceSignif;   //!
   TBranch        *b_mu_eloss;   //!
   TBranch        *b_mu_paramEloss;   //!
   TBranch        *b_mu_measEloss;   //!
   TBranch        *b_mu_elossSigma;   //!
   TBranch        *b_mu_id_x2ndof;   //!
   TBranch        *b_mu_id_pT;   //!
   TBranch        *b_mu_id_qOverPsigma;   //!
   TBranch        *b_mu_id_pT_err;   //!
   TBranch        *b_mu_me_pT;   //!
   TBranch        *b_mu_qOverPsigma;   //!
   TBranch        *b_mu_qOverPsignif;   //!
   TBranch        *b_mu_me_qOverPsigma;   //!
   TBranch        *b_mu_me_x2ndof;   //!
   TBranch        *b_mu_me_pT_err;   //!
   TBranch        *b_mu_ms_pT;   //!
   TBranch        *b_mu_ms_qOverPsigma;   //!
   TBranch        *b_mu_ms_pT_err;   //!
   TBranch        *b_mu_quality;   //!
   TBranch        *b_muon;   //!
   TBranch        *b_mu_weight;   //!
   TBranch        *b_mu_ptcone20;   //!
   TBranch        *b_mu_ptcone30;   //!
   TBranch        *b_mu_ptvarcone20;   //!
   TBranch        *b_mu_ptvarcone30;   //!
   TBranch        *b_mu_topoetcone20;   //!
   TBranch        *b_mu_topoetcone30;   //!
   TBranch        *b_mu_d0sig;   //!
   TBranch        *b_mu_z0sintheta;   //!
   TBranch        *b_mu_isPrompt;   //!
   TBranch        *b_jet_pT;   //!
   TBranch        *b_jet_eta;   //!
   TBranch        *b_jet_phi;   //!
   TBranch        *b_jet_E;   //!
   TBranch        *b_jet_m;   //!
   TBranch        *b_jet;   //!
   TBranch        *b_jet_weight;   //!
   TBranch        *b_jet_btag;   //!
   TBranch        *b_jet_bMV2Weight;   //!
   TBranch        *b_el_pT;   //!
   TBranch        *b_el_eta;   //!
   TBranch        *b_el_phi;   //!
   TBranch        *b_el_E;   //!
   TBranch        *b_el_m;   //!
   TBranch        *b_electron;   //!
   TBranch        *b_el_weight;   //!
   TBranch        *b_el_ptcone20;   //!
   TBranch        *b_el_ptcone30;   //!
   TBranch        *b_el_ptvarcone20;   //!
   TBranch        *b_el_ptvarcone30;   //!
   TBranch        *b_el_topoetcone20;   //!
   TBranch        *b_el_topoetcone30;   //!
   TBranch        *b_el_d0sig;   //!
   TBranch        *b_el_z0sintheta;   //!
   TBranch        *b_el_isPrompt;   //!
   TBranch        *b_el_passAmbi;   //!
   TBranch        *b_lep_pT;   //!
   TBranch        *b_lep_eta;   //!
   TBranch        *b_lep_phi;   //!
   TBranch        *b_lep_E;   //!
   TBranch        *b_lep_m;   //!
   TBranch        *b_lep_truthPt;   //!
   TBranch        *b_lep_truthEta;   //!
   TBranch        *b_lep_truthPhi;   //!
   TBranch        *b_lep_truthE;   //!
   TBranch        *b_lep_truthGammaPt;   //!
   TBranch        *b_mu_match_HLT_mu50;   //!
   TBranch        *b_lep_match_HLT_mu50;   //!
   TBranch        *b_el_match_HLT_mu50;   //!
   TBranch        *b_mu_match_HLT_2mu14;   //!
   TBranch        *b_lep_match_HLT_2mu14;   //!
   TBranch        *b_el_match_HLT_2mu14;   //!
   TBranch        *b_mu_match_HLT_mu24_mu8noL1;   //!
   TBranch        *b_lep_match_HLT_mu24_mu8noL1;   //!
   TBranch        *b_el_match_HLT_mu24_mu8noL1;   //!
   TBranch        *b_mu_match_HLT_mu24;   //!
   TBranch        *b_lep_match_HLT_mu24;   //!
   TBranch        *b_el_match_HLT_mu24;   //!
   TBranch        *b_mu_match_HLT_mu20_iloose_L1MU15;   //!
   TBranch        *b_lep_match_HLT_mu20_iloose_L1MU15;   //!
   TBranch        *b_el_match_HLT_mu20_iloose_L1MU15;   //!
   TBranch        *b_mu_match_HLT_2mu10;   //!
   TBranch        *b_lep_match_HLT_2mu10;   //!
   TBranch        *b_el_match_HLT_2mu10;   //!
   TBranch        *b_mu_match_HLT_mu10;   //!
   TBranch        *b_lep_match_HLT_mu10;   //!
   TBranch        *b_el_match_HLT_mu10;   //!
   TBranch        *b_mu_match_HLT_mu22_mu8noL1;   //!
   TBranch        *b_lep_match_HLT_mu22_mu8noL1;   //!
   TBranch        *b_el_match_HLT_mu22_mu8noL1;   //!
   TBranch        *b_mu_match_HLT_mu22;   //!
   TBranch        *b_lep_match_HLT_mu22;   //!
   TBranch        *b_el_match_HLT_mu22;   //!
   TBranch        *b_mu_match_HLT_mu20_mu8noL1;   //!
   TBranch        *b_lep_match_HLT_mu20_mu8noL1;   //!
   TBranch        *b_el_match_HLT_mu20_mu8noL1;   //!
   TBranch        *b_mu_match_HLT_mu20;   //!
   TBranch        *b_lep_match_HLT_mu20;   //!
   TBranch        *b_el_match_HLT_mu20;   //!
   TBranch        *b_mu_match_HLT_mu18_mu8noL1;   //!
   TBranch        *b_lep_match_HLT_mu18_mu8noL1;   //!
   TBranch        *b_el_match_HLT_mu18_mu8noL1;   //!
   TBranch        *b_mu_match_HLT_mu18;   //!
   TBranch        *b_lep_match_HLT_mu18;   //!
   TBranch        *b_el_match_HLT_mu18;   //!
   TBranch        *b_mu_match_HLT_e24_lhmedium_iloose_L1EM18VH;   //!
   TBranch        *b_lep_match_HLT_e24_lhmedium_iloose_L1EM18VH;   //!
   TBranch        *b_el_match_HLT_e24_lhmedium_iloose_L1EM18VH;   //!
   TBranch        *b_mu_match_HLT_e24_lhmedium_iloose_L1EM20VH;   //!
   TBranch        *b_lep_match_HLT_e24_lhmedium_iloose_L1EM20VH;   //!
   TBranch        *b_el_match_HLT_e24_lhmedium_iloose_L1EM20VH;   //!
   TBranch        *b_mu_match_HLT_e60_lhmedium;   //!
   TBranch        *b_lep_match_HLT_e60_lhmedium;   //!
   TBranch        *b_el_match_HLT_e60_lhmedium;   //!
   TBranch        *b_mu_match_HLT_2e17_lhloose;   //!
   TBranch        *b_lep_match_HLT_2e17_lhloose;   //!
   TBranch        *b_el_match_HLT_2e17_lhloose;   //!
   TBranch        *b_mu_match_HLT_2e12_lhloose_L12EM10VH;   //!
   TBranch        *b_lep_match_HLT_2e12_lhloose_L12EM10VH;   //!
   TBranch        *b_el_match_HLT_2e12_lhloose_L12EM10VH;   //!
   TBranch        *b_mu_match_HLT_e17_lhloose_mu14;   //!
   TBranch        *b_lep_match_HLT_e17_lhloose_mu14;   //!
   TBranch        *b_el_match_HLT_e17_lhloose_mu14;   //!
   TBranch        *b_mu_match_HLT_e7_lhmedium_mu24;   //!
   TBranch        *b_lep_match_HLT_e7_lhmedium_mu24;   //!
   TBranch        *b_el_match_HLT_e7_lhmedium_mu24;   //!
   TBranch        *b_mu_match_HLT_e24_lhmedium_L1EM20VH;   //!
   TBranch        *b_lep_match_HLT_e24_lhmedium_L1EM20VH;   //!
   TBranch        *b_el_match_HLT_e24_lhmedium_L1EM20VH;   //!
   TBranch        *b_mu_match_HLT_e26_lhmedium_L1EM22VHI_mu8noL1;   //!
   TBranch        *b_lep_match_HLT_e26_lhmedium_L1EM22VHI_mu8noL1;   //!
   TBranch        *b_el_match_HLT_e26_lhmedium_L1EM22VHI_mu8noL1;   //!
   TBranch        *b_mu_match_HLT_e24_lhmedium_L1EM20VHI_mu8noL1;   //!
   TBranch        *b_lep_match_HLT_e24_lhmedium_L1EM20VHI_mu8noL1;   //!
   TBranch        *b_el_match_HLT_e24_lhmedium_L1EM20VHI_mu8noL1;   //!
   TBranch        *b_mu_match_HLT_xe70;   //!
   TBranch        *b_lep_match_HLT_xe70;   //!
   TBranch        *b_el_match_HLT_xe70;   //!
   TBranch        *b_mu_match_HLT_xe80;   //!
   TBranch        *b_lep_match_HLT_xe80;   //!
   TBranch        *b_el_match_HLT_xe80;   //!
   TBranch        *b_mu_match_HLT_xe80_wEFMu;   //!
   TBranch        *b_lep_match_HLT_xe80_wEFMu;   //!
   TBranch        *b_el_match_HLT_xe80_wEFMu;   //!
   TBranch        *b_mu_match_HLT_xe100;   //!
   TBranch        *b_lep_match_HLT_xe100;   //!
   TBranch        *b_el_match_HLT_xe100;   //!
   TBranch        *b_lep_tight;   //!
   TBranch        *b_lep_tight_weight;   //!
   TBranch        *b_lep_isPrompt;   //!
   TBranch        *b_lep_weight;   //!
   TBranch        *b_lep_pdgId;   //!
   TBranch        *b_eetrig_match;   //!
   TBranch        *b_emtrig_match;   //!
   TBranch        *b_mmtrig_match;   //!
   TBranch        *b_mmtrig_match1;   //!
   TBranch        *b_truth_ZpT;   //!
   TBranch        *b_truth_Zll;   //!
   TBranch        *b_jet_n;   //!
   TBranch        *b_el_n;   //!
   TBranch        *b_mu_n;   //!
   TBranch        *b_lep_n;   //!
   TBranch        *b_bjet_n;   //!
   TBranch        *b_MT2W;   //!
   TBranch        *b_MT2Top;   //!
   TBranch        *b_Pass_SUSY2_Triggers;   //!
   TBranch        *b_PassedSUSYTriggers;   //!
   TBranch        *b_truthLepton_status;   //!
   TBranch        *b_truthLepton_pT;   //!
   TBranch        *b_truthLepton_eta;   //!
   TBranch        *b_truthLepton_phi;   //!
   TBranch        *b_truthLepton_E;   //!
   TBranch        *b_truthLepton_pdgID;   //!
   TBranch        *b_truthLepton_parent_pdgID;   //!
   TBranch        *b_truthLepton_match_electron;   //!
   TBranch        *b_truthLepton_weight_electron;   //!
   TBranch        *b_truthLepton_match_muon;   //!
   TBranch        *b_truthLepton_weight_muon;   //!
   TBranch        *b_truthLepton_n;   //!
   TBranch        *b_truthLepton_nWZel;   //!
   TBranch        *b_truthLepton_nWZmu;   //!
   TBranch        *b_truthLepton_nWZtau;   //!
   TBranch        *b_truthLepton_nWZlep;   //!
   TBranch        *b_truthPhoton_n;   //!
   TBranch        *b_truthMET_Filter;   //!
   TBranch        *b_truthMET_NonInt;   //!
   TBranch        *b_truthMET_NonIntPhi;   //!
   TBranch        *b_truthMET;   //!
   TBranch        *b_truthMET_Phi;   //!
   TBranch        *b_jet_n_vetolep;   //!
   TBranch        *b_HT_vetolep;   //!
   TBranch        *b_nVtx;   //!
   TBranch        *b_mu_ms_pt;   //!
   TBranch        *b_mu_ms_qoverpsigma;   //!
   TBranch        *b_weight1fb;   //!
   TBranch        *b_lepweight;   //!
   TBranch        *b_nGenEvents;   //!

   HiggsinoBase(TTree *tree=0);
   virtual ~HiggsinoBase();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

inline HiggsinoBase::HiggsinoBase(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("ttbar_MET_gt_100.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("ttbar_MET_gt_100.root");
      }
      f->GetObject("outputTree",tree);

   }
   Init(tree);
}

inline HiggsinoBase::~HiggsinoBase()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

inline Int_t HiggsinoBase::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
inline Long64_t HiggsinoBase::LoadTree(Long64_t entry)
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

inline void HiggsinoBase::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   mu_pT = 0;
   mu_eta = 0;
   mu_phi = 0;
   mu_E = 0;
   mu_m = 0;
   mu_nPrecLayers = 0;
   mu_raw_pT = 0;
   mu_pT_err = 0;
   mu_x2ndof = 0;
   mu_pBalanceSignif = 0;
   mu_eloss = 0;
   mu_paramEloss = 0;
   mu_measEloss = 0;
   mu_elossSigma = 0;
   mu_id_x2ndof = 0;
   mu_id_pT = 0;
   mu_id_qOverPsigma = 0;
   mu_id_pT_err = 0;
   mu_me_pT = 0;
   mu_qOverPsigma = 0;
   mu_qOverPsignif = 0;
   mu_me_qOverPsigma = 0;
   mu_me_x2ndof = 0;
   mu_me_pT_err = 0;
   mu_ms_pT = 0;
   mu_ms_qOverPsigma = 0;
   mu_ms_pT_err = 0;
   mu_quality = 0;
   muon = 0;
   mu_weight = 0;
   mu_ptcone20 = 0;
   mu_ptcone30 = 0;
   mu_ptvarcone20 = 0;
   mu_ptvarcone30 = 0;
   mu_topoetcone20 = 0;
   mu_topoetcone30 = 0;
   mu_d0sig = 0;
   mu_z0sintheta = 0;
   mu_isPrompt = 0;
   jet_pT = 0;
   jet_eta = 0;
   jet_phi = 0;
   jet_E = 0;
   jet_m = 0;
   jet = 0;
   jet_weight = 0;
   jet_btag = 0;
   jet_bMV2Weight = 0;
   el_pT = 0;
   el_eta = 0;
   el_phi = 0;
   el_E = 0;
   el_m = 0;
   electron = 0;
   el_weight = 0;
   el_ptcone20 = 0;
   el_ptcone30 = 0;
   el_ptvarcone20 = 0;
   el_ptvarcone30 = 0;
   el_topoetcone20 = 0;
   el_topoetcone30 = 0;
   el_d0sig = 0;
   el_z0sintheta = 0;
   el_isPrompt = 0;
   el_passAmbi = 0;
   lep_pT = 0;
   lep_eta = 0;
   lep_phi = 0;
   lep_E = 0;
   lep_m = 0;
   lep_truthPt = 0;
   lep_truthEta = 0;
   lep_truthPhi = 0;
   lep_truthE = 0;
   lep_truthGammaPt = 0;
   mu_match_HLT_mu50 = 0;
   lep_match_HLT_mu50 = 0;
   el_match_HLT_mu50 = 0;
   mu_match_HLT_2mu14 = 0;
   lep_match_HLT_2mu14 = 0;
   el_match_HLT_2mu14 = 0;
   mu_match_HLT_mu24_mu8noL1 = 0;
   lep_match_HLT_mu24_mu8noL1 = 0;
   el_match_HLT_mu24_mu8noL1 = 0;
   mu_match_HLT_mu24 = 0;
   lep_match_HLT_mu24 = 0;
   el_match_HLT_mu24 = 0;
   mu_match_HLT_mu20_iloose_L1MU15 = 0;
   lep_match_HLT_mu20_iloose_L1MU15 = 0;
   el_match_HLT_mu20_iloose_L1MU15 = 0;
   mu_match_HLT_2mu10 = 0;
   lep_match_HLT_2mu10 = 0;
   el_match_HLT_2mu10 = 0;
   mu_match_HLT_mu10 = 0;
   lep_match_HLT_mu10 = 0;
   el_match_HLT_mu10 = 0;
   mu_match_HLT_mu22_mu8noL1 = 0;
   lep_match_HLT_mu22_mu8noL1 = 0;
   el_match_HLT_mu22_mu8noL1 = 0;
   mu_match_HLT_mu22 = 0;
   lep_match_HLT_mu22 = 0;
   el_match_HLT_mu22 = 0;
   mu_match_HLT_mu20_mu8noL1 = 0;
   lep_match_HLT_mu20_mu8noL1 = 0;
   el_match_HLT_mu20_mu8noL1 = 0;
   mu_match_HLT_mu20 = 0;
   lep_match_HLT_mu20 = 0;
   el_match_HLT_mu20 = 0;
   mu_match_HLT_mu18_mu8noL1 = 0;
   lep_match_HLT_mu18_mu8noL1 = 0;
   el_match_HLT_mu18_mu8noL1 = 0;
   mu_match_HLT_mu18 = 0;
   lep_match_HLT_mu18 = 0;
   el_match_HLT_mu18 = 0;
   mu_match_HLT_e24_lhmedium_iloose_L1EM18VH = 0;
   lep_match_HLT_e24_lhmedium_iloose_L1EM18VH = 0;
   el_match_HLT_e24_lhmedium_iloose_L1EM18VH = 0;
   mu_match_HLT_e24_lhmedium_iloose_L1EM20VH = 0;
   lep_match_HLT_e24_lhmedium_iloose_L1EM20VH = 0;
   el_match_HLT_e24_lhmedium_iloose_L1EM20VH = 0;
   mu_match_HLT_e60_lhmedium = 0;
   lep_match_HLT_e60_lhmedium = 0;
   el_match_HLT_e60_lhmedium = 0;
   mu_match_HLT_2e17_lhloose = 0;
   lep_match_HLT_2e17_lhloose = 0;
   el_match_HLT_2e17_lhloose = 0;
   mu_match_HLT_2e12_lhloose_L12EM10VH = 0;
   lep_match_HLT_2e12_lhloose_L12EM10VH = 0;
   el_match_HLT_2e12_lhloose_L12EM10VH = 0;
   mu_match_HLT_e17_lhloose_mu14 = 0;
   lep_match_HLT_e17_lhloose_mu14 = 0;
   el_match_HLT_e17_lhloose_mu14 = 0;
   mu_match_HLT_e7_lhmedium_mu24 = 0;
   lep_match_HLT_e7_lhmedium_mu24 = 0;
   el_match_HLT_e7_lhmedium_mu24 = 0;
   mu_match_HLT_e24_lhmedium_L1EM20VH = 0;
   lep_match_HLT_e24_lhmedium_L1EM20VH = 0;
   el_match_HLT_e24_lhmedium_L1EM20VH = 0;
   mu_match_HLT_e26_lhmedium_L1EM22VHI_mu8noL1 = 0;
   lep_match_HLT_e26_lhmedium_L1EM22VHI_mu8noL1 = 0;
   el_match_HLT_e26_lhmedium_L1EM22VHI_mu8noL1 = 0;
   mu_match_HLT_e24_lhmedium_L1EM20VHI_mu8noL1 = 0;
   lep_match_HLT_e24_lhmedium_L1EM20VHI_mu8noL1 = 0;
   el_match_HLT_e24_lhmedium_L1EM20VHI_mu8noL1 = 0;
   mu_match_HLT_xe70 = 0;
   lep_match_HLT_xe70 = 0;
   el_match_HLT_xe70 = 0;
   mu_match_HLT_xe80 = 0;
   lep_match_HLT_xe80 = 0;
   el_match_HLT_xe80 = 0;
   mu_match_HLT_xe80_wEFMu = 0;
   lep_match_HLT_xe80_wEFMu = 0;
   el_match_HLT_xe80_wEFMu = 0;
   mu_match_HLT_xe100 = 0;
   lep_match_HLT_xe100 = 0;
   el_match_HLT_xe100 = 0;
   lep_tight = 0;
   lep_tight_weight = 0;
   lep_isPrompt = 0;
   lep_weight = 0;
   lep_pdgId = 0;
   truthLepton_status = 0;
   truthLepton_pT = 0;
   truthLepton_eta = 0;
   truthLepton_phi = 0;
   truthLepton_E = 0;
   truthLepton_pdgID = 0;
   truthLepton_parent_pdgID = 0;
   truthLepton_match_electron = 0;
   truthLepton_weight_electron = 0;
   truthLepton_match_muon = 0;
   truthLepton_weight_muon = 0;
   mu_ms_pt = 0;
   mu_ms_qoverpsigma = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("MET", &MET, &b_MET);
   fChain->SetBranchAddress("MET_sumET", &MET_sumET, &b_MET_sumET);
   fChain->SetBranchAddress("MET_phi", &MET_phi, &b_MET_phi);
   fChain->SetBranchAddress("TrackMET", &TrackMET, &b_TrackMET);
   fChain->SetBranchAddress("TrackMET_sumET", &TrackMET_sumET, &b_TrackMET_sumET);
   fChain->SetBranchAddress("TrackMET_phi", &TrackMET_phi, &b_TrackMET_phi);
   fChain->SetBranchAddress("Mu", &Mu, &b_Mu);
   fChain->SetBranchAddress("HTincl", &HTincl, &b_HTincl);
   fChain->SetBranchAddress("VecHTincl", &VecHTincl, &b_VecHTincl);
   fChain->SetBranchAddress("HT", &HT, &b_HT);
   fChain->SetBranchAddress("VecHT", &VecHT, &b_VecHT);
   fChain->SetBranchAddress("mll", &mll, &b_mll);
   fChain->SetBranchAddress("DPhi_METJet", &DPhi_METJet, &b_DPhi_METJet);
   fChain->SetBranchAddress("DPhi_METJetLeading", &DPhi_METJetLeading, &b_DPhi_METJetLeading);
   fChain->SetBranchAddress("DPhi_METJetSecond", &DPhi_METJetSecond, &b_DPhi_METJetSecond);
   fChain->SetBranchAddress("channel", &channel, &b_channel);
   fChain->SetBranchAddress("is_OS", &is_OS, &b_is_OS);
   fChain->SetBranchAddress("Z_pt", &Z_pt, &b_Z_pt);
   fChain->SetBranchAddress("Z_phi", &Z_phi, &b_Z_phi);
   fChain->SetBranchAddress("Z_eta", &Z_eta, &b_Z_eta);
   fChain->SetBranchAddress("EventNumber", &EventNumber, &b_EventNumber);
   fChain->SetBranchAddress("RunNumber", &RunNumber, &b_RunNumber);
   fChain->SetBranchAddress("eventWeight", &eventWeight, &b_eventWeight);
   fChain->SetBranchAddress("sampleWeight", &sampleWeight, &b_sampleWeight);
   fChain->SetBranchAddress("pileupWeight", &pileupWeight, &b_pileupWeight);
   fChain->SetBranchAddress("HLT_mu50", &HLT_mu50, &b_HLT_mu50);
   fChain->SetBranchAddress("HLT_2mu14", &HLT_2mu14, &b_HLT_2mu14);
   fChain->SetBranchAddress("HLT_mu24_mu8noL1", &HLT_mu24_mu8noL1, &b_HLT_mu24_mu8noL1);
   fChain->SetBranchAddress("HLT_mu24", &HLT_mu24, &b_HLT_mu24);
   fChain->SetBranchAddress("HLT_mu20_iloose_L1MU15", &HLT_mu20_iloose_L1MU15, &b_HLT_mu20_iloose_L1MU15);
   fChain->SetBranchAddress("HLT_2mu10", &HLT_2mu10, &b_HLT_2mu10);
   fChain->SetBranchAddress("HLT_mu10", &HLT_mu10, &b_HLT_mu10);
   fChain->SetBranchAddress("HLT_mu22_mu8noL1", &HLT_mu22_mu8noL1, &b_HLT_mu22_mu8noL1);
   fChain->SetBranchAddress("HLT_mu22", &HLT_mu22, &b_HLT_mu22);
   fChain->SetBranchAddress("HLT_mu20_mu8noL1", &HLT_mu20_mu8noL1, &b_HLT_mu20_mu8noL1);
   fChain->SetBranchAddress("HLT_mu20", &HLT_mu20, &b_HLT_mu20);
   fChain->SetBranchAddress("HLT_mu18_mu8noL1", &HLT_mu18_mu8noL1, &b_HLT_mu18_mu8noL1);
   fChain->SetBranchAddress("HLT_mu18", &HLT_mu18, &b_HLT_mu18);
   fChain->SetBranchAddress("HLT_e24_lhmedium_iloose_L1EM18VH", &HLT_e24_lhmedium_iloose_L1EM18VH, &b_HLT_e24_lhmedium_iloose_L1EM18VH);
   fChain->SetBranchAddress("HLT_e24_lhmedium_iloose_L1EM20VH", &HLT_e24_lhmedium_iloose_L1EM20VH, &b_HLT_e24_lhmedium_iloose_L1EM20VH);
   fChain->SetBranchAddress("HLT_e60_lhmedium", &HLT_e60_lhmedium, &b_HLT_e60_lhmedium);
   fChain->SetBranchAddress("HLT_2e17_lhloose", &HLT_2e17_lhloose, &b_HLT_2e17_lhloose);
   fChain->SetBranchAddress("HLT_2e12_lhloose_L12EM10VH", &HLT_2e12_lhloose_L12EM10VH, &b_HLT_2e12_lhloose_L12EM10VH);
   fChain->SetBranchAddress("HLT_e17_lhloose_mu14", &HLT_e17_lhloose_mu14, &b_HLT_e17_lhloose_mu14);
   fChain->SetBranchAddress("HLT_e7_lhmedium_mu24", &HLT_e7_lhmedium_mu24, &b_HLT_e7_lhmedium_mu24);
   fChain->SetBranchAddress("HLT_e24_lhmedium_L1EM20VH", &HLT_e24_lhmedium_L1EM20VH, &b_HLT_e24_lhmedium_L1EM20VH);
   fChain->SetBranchAddress("HLT_e26_lhmedium_L1EM22VHI_mu8noL1", &HLT_e26_lhmedium_L1EM22VHI_mu8noL1, &b_HLT_e26_lhmedium_L1EM22VHI_mu8noL1);
   fChain->SetBranchAddress("HLT_e24_lhmedium_L1EM20VHI_mu8noL1", &HLT_e24_lhmedium_L1EM20VHI_mu8noL1, &b_HLT_e24_lhmedium_L1EM20VHI_mu8noL1);
   fChain->SetBranchAddress("HLT_xe70", &HLT_xe70, &b_HLT_xe70);
   fChain->SetBranchAddress("HLT_xe80", &HLT_xe80, &b_HLT_xe80);
   fChain->SetBranchAddress("HLT_xe80_wEFMu", &HLT_xe80_wEFMu, &b_HLT_xe80_wEFMu);
   fChain->SetBranchAddress("HLT_xe100", &HLT_xe100, &b_HLT_xe100);
   fChain->SetBranchAddress("sf_trig_HLT_e60_lhmedium", &sf_trig_HLT_e60_lhmedium, &b_sf_trig_HLT_e60_lhmedium);
   fChain->SetBranchAddress("sfunc_trig_HLT_e60_lhmedium", &sfunc_trig_HLT_e60_lhmedium, &b_sfunc_trig_HLT_e60_lhmedium);
   fChain->SetBranchAddress("sf_trig_HLT_e24_lhmedium_iloose_L1EM18VH", &sf_trig_HLT_e24_lhmedium_iloose_L1EM18VH, &b_sf_trig_HLT_e24_lhmedium_iloose_L1EM18VH);
   fChain->SetBranchAddress("sfunc_trig_HLT_e24_lhmedium_iloose_L1EM18VH", &sfunc_trig_HLT_e24_lhmedium_iloose_L1EM18VH, &b_sfunc_trig_HLT_e24_lhmedium_iloose_L1EM18VH);
   fChain->SetBranchAddress("sf_trig_HLT_e24_lhmedium_L1EM20VH", &sf_trig_HLT_e24_lhmedium_L1EM20VH, &b_sf_trig_HLT_e24_lhmedium_L1EM20VH);
   fChain->SetBranchAddress("sfunc_trig_HLT_e24_lhmedium_L1EM20VH", &sfunc_trig_HLT_e24_lhmedium_L1EM20VH, &b_sfunc_trig_HLT_e24_lhmedium_L1EM20VH);
   fChain->SetBranchAddress("sf_trig_HLT_e24_lhmedium_iloose_L1EM20VH", &sf_trig_HLT_e24_lhmedium_iloose_L1EM20VH, &b_sf_trig_HLT_e24_lhmedium_iloose_L1EM20VH);
   fChain->SetBranchAddress("sfunc_trig_HLT_e24_lhmedium_iloose_L1EM20VH", &sfunc_trig_HLT_e24_lhmedium_iloose_L1EM20VH, &b_sfunc_trig_HLT_e24_lhmedium_iloose_L1EM20VH);
   fChain->SetBranchAddress("sf_trig_HLT_mu50", &sf_trig_HLT_mu50, &b_sf_trig_HLT_mu50);
   fChain->SetBranchAddress("sfunc_trig_HLT_mu50", &sfunc_trig_HLT_mu50, &b_sfunc_trig_HLT_mu50);
   fChain->SetBranchAddress("sf_trig_HLT_mu20_iloose_L1MU15", &sf_trig_HLT_mu20_iloose_L1MU15, &b_sf_trig_HLT_mu20_iloose_L1MU15);
   fChain->SetBranchAddress("sfunc_trig_HLT_mu20_iloose_L1MU15", &sfunc_trig_HLT_mu20_iloose_L1MU15, &b_sfunc_trig_HLT_mu20_iloose_L1MU15);
   fChain->SetBranchAddress("sf_trig_HLT_2e12_lhloose", &sf_trig_HLT_2e12_lhloose, &b_sf_trig_HLT_2e12_lhloose);
   fChain->SetBranchAddress("sfunc_trig_HLT_2e12_lhloose", &sfunc_trig_HLT_2e12_lhloose, &b_sfunc_trig_HLT_2e12_lhloose);
   fChain->SetBranchAddress("sf_trig_HLT_mu18_mu8noL1", &sf_trig_HLT_mu18_mu8noL1, &b_sf_trig_HLT_mu18_mu8noL1);
   fChain->SetBranchAddress("sfunc_trig_HLT_mu18_mu8noL1", &sfunc_trig_HLT_mu18_mu8noL1, &b_sfunc_trig_HLT_mu18_mu8noL1);
   fChain->SetBranchAddress("sf_trig_HLT_e17_lhloose_mu14", &sf_trig_HLT_e17_lhloose_mu14, &b_sf_trig_HLT_e17_lhloose_mu14);
   fChain->SetBranchAddress("sfunc_trig_HLT_e17_lhloose_mu14", &sfunc_trig_HLT_e17_lhloose_mu14, &b_sfunc_trig_HLT_e17_lhloose_mu14);
   fChain->SetBranchAddress("sf_trig_HLT_e7_lhmedium_mu24", &sf_trig_HLT_e7_lhmedium_mu24, &b_sf_trig_HLT_e7_lhmedium_mu24);
   fChain->SetBranchAddress("sfunc_trig_HLT_e7_lhmedium_mu24", &sfunc_trig_HLT_e7_lhmedium_mu24, &b_sfunc_trig_HLT_e7_lhmedium_mu24);
   fChain->SetBranchAddress("sf_trig_HLT_e26_lhmedium_L1EM22VHI_mu8noL1", &sf_trig_HLT_e26_lhmedium_L1EM22VHI_mu8noL1, &b_sf_trig_HLT_e26_lhmedium_L1EM22VHI_mu8noL1);
   fChain->SetBranchAddress("sfunc_trig_HLT_e26_lhmedium_L1EM22VHI_mu8noL1", &sfunc_trig_HLT_e26_lhmedium_L1EM22VHI_mu8noL1, &b_sfunc_trig_HLT_e26_lhmedium_L1EM22VHI_mu8noL1);
   fChain->SetBranchAddress("sf_trig_HLT_e24_lhmedium_L1EM20VHI_mu8noL1", &sf_trig_HLT_e24_lhmedium_L1EM20VHI_mu8noL1, &b_sf_trig_HLT_e24_lhmedium_L1EM20VHI_mu8noL1);
   fChain->SetBranchAddress("sfunc_trig_HLT_e24_lhmedium_L1EM20VHI_mu8noL1", &sfunc_trig_HLT_e24_lhmedium_L1EM20VHI_mu8noL1, &b_sfunc_trig_HLT_e24_lhmedium_L1EM20VHI_mu8noL1);
   fChain->SetBranchAddress("eetrig", &eetrig, &b_eetrig);
   fChain->SetBranchAddress("mmtrig", &mmtrig, &b_mmtrig);
   fChain->SetBranchAddress("emtrig", &emtrig, &b_emtrig);
   fChain->SetBranchAddress("eetrigweight", &eetrigweight, &b_eetrigweight);
   fChain->SetBranchAddress("mmtrigweight", &mmtrigweight, &b_mmtrigweight);
   fChain->SetBranchAddress("emtrigweight", &emtrigweight, &b_emtrigweight);
   fChain->SetBranchAddress("trigweight", &trigweight, &b_trigweight);
   fChain->SetBranchAddress("eetrigweight_down", &eetrigweight_down, &b_eetrigweight_down);
   fChain->SetBranchAddress("mmtrigweight_down", &mmtrigweight_down, &b_mmtrigweight_down);
   fChain->SetBranchAddress("emtrigweight_down", &emtrigweight_down, &b_emtrigweight_down);
   fChain->SetBranchAddress("trigweight_down", &trigweight_down, &b_trigweight_down);
   fChain->SetBranchAddress("eetrigor", &eetrigor, &b_eetrigor);
   fChain->SetBranchAddress("mmtrigor", &mmtrigor, &b_mmtrigor);
   fChain->SetBranchAddress("emtrigor", &emtrigor, &b_emtrigor);
   fChain->SetBranchAddress("mu_pT", &mu_pT, &b_mu_pT);
   fChain->SetBranchAddress("mu_eta", &mu_eta, &b_mu_eta);
   fChain->SetBranchAddress("mu_phi", &mu_phi, &b_mu_phi);
   fChain->SetBranchAddress("mu_E", &mu_E, &b_mu_E);
   fChain->SetBranchAddress("mu_m", &mu_m, &b_mu_m);
   fChain->SetBranchAddress("mu_nPrecLayers", &mu_nPrecLayers, &b_mu_nPrecLayers);
   fChain->SetBranchAddress("mu_raw_pT", &mu_raw_pT, &b_mu_raw_pT);
   fChain->SetBranchAddress("mu_pT_err", &mu_pT_err, &b_mu_pT_err);
   fChain->SetBranchAddress("mu_x2ndof", &mu_x2ndof, &b_mu_x2ndof);
   fChain->SetBranchAddress("mu_pBalanceSignif", &mu_pBalanceSignif, &b_mu_pBalanceSignif);
   fChain->SetBranchAddress("mu_eloss", &mu_eloss, &b_mu_eloss);
   fChain->SetBranchAddress("mu_paramEloss", &mu_paramEloss, &b_mu_paramEloss);
   fChain->SetBranchAddress("mu_measEloss", &mu_measEloss, &b_mu_measEloss);
   fChain->SetBranchAddress("mu_elossSigma", &mu_elossSigma, &b_mu_elossSigma);
   fChain->SetBranchAddress("mu_id_x2ndof", &mu_id_x2ndof, &b_mu_id_x2ndof);
   fChain->SetBranchAddress("mu_id_pT", &mu_id_pT, &b_mu_id_pT);
   fChain->SetBranchAddress("mu_id_qOverPsigma", &mu_id_qOverPsigma, &b_mu_id_qOverPsigma);
   fChain->SetBranchAddress("mu_id_pT_err", &mu_id_pT_err, &b_mu_id_pT_err);
   fChain->SetBranchAddress("mu_me_pT", &mu_me_pT, &b_mu_me_pT);
   fChain->SetBranchAddress("mu_qOverPsigma", &mu_qOverPsigma, &b_mu_qOverPsigma);
   fChain->SetBranchAddress("mu_qOverPsignif", &mu_qOverPsignif, &b_mu_qOverPsignif);
   fChain->SetBranchAddress("mu_me_qOverPsigma", &mu_me_qOverPsigma, &b_mu_me_qOverPsigma);
   fChain->SetBranchAddress("mu_me_x2ndof", &mu_me_x2ndof, &b_mu_me_x2ndof);
   fChain->SetBranchAddress("mu_me_pT_err", &mu_me_pT_err, &b_mu_me_pT_err);
   fChain->SetBranchAddress("mu_ms_pT", &mu_ms_pT, &b_mu_ms_pT);
   fChain->SetBranchAddress("mu_ms_qOverPsigma", &mu_ms_qOverPsigma, &b_mu_ms_qOverPsigma);
   fChain->SetBranchAddress("mu_ms_pT_err", &mu_ms_pT_err, &b_mu_ms_pT_err);
   fChain->SetBranchAddress("mu_quality", &mu_quality, &b_mu_quality);
   fChain->SetBranchAddress("muon", &muon, &b_muon);
   fChain->SetBranchAddress("mu_weight", &mu_weight, &b_mu_weight);
   fChain->SetBranchAddress("mu_ptcone20", &mu_ptcone20, &b_mu_ptcone20);
   fChain->SetBranchAddress("mu_ptcone30", &mu_ptcone30, &b_mu_ptcone30);
   fChain->SetBranchAddress("mu_ptvarcone20", &mu_ptvarcone20, &b_mu_ptvarcone20);
   fChain->SetBranchAddress("mu_ptvarcone30", &mu_ptvarcone30, &b_mu_ptvarcone30);
   fChain->SetBranchAddress("mu_topoetcone20", &mu_topoetcone20, &b_mu_topoetcone20);
   fChain->SetBranchAddress("mu_topoetcone30", &mu_topoetcone30, &b_mu_topoetcone30);
   fChain->SetBranchAddress("mu_d0sig", &mu_d0sig, &b_mu_d0sig);
   fChain->SetBranchAddress("mu_z0sintheta", &mu_z0sintheta, &b_mu_z0sintheta);
   fChain->SetBranchAddress("mu_isPrompt", &mu_isPrompt, &b_mu_isPrompt);
   fChain->SetBranchAddress("jet_pT", &jet_pT, &b_jet_pT);
   fChain->SetBranchAddress("jet_eta", &jet_eta, &b_jet_eta);
   fChain->SetBranchAddress("jet_phi", &jet_phi, &b_jet_phi);
   fChain->SetBranchAddress("jet_E", &jet_E, &b_jet_E);
   fChain->SetBranchAddress("jet_m", &jet_m, &b_jet_m);
   fChain->SetBranchAddress("jet", &jet, &b_jet);
   fChain->SetBranchAddress("jet_weight", &jet_weight, &b_jet_weight);
   fChain->SetBranchAddress("jet_btag", &jet_btag, &b_jet_btag);
   fChain->SetBranchAddress("jet_bMV2Weight", &jet_bMV2Weight, &b_jet_bMV2Weight);
   fChain->SetBranchAddress("el_pT", &el_pT, &b_el_pT);
   fChain->SetBranchAddress("el_eta", &el_eta, &b_el_eta);
   fChain->SetBranchAddress("el_phi", &el_phi, &b_el_phi);
   fChain->SetBranchAddress("el_E", &el_E, &b_el_E);
   fChain->SetBranchAddress("el_m", &el_m, &b_el_m);
   fChain->SetBranchAddress("electron", &electron, &b_electron);
   fChain->SetBranchAddress("el_weight", &el_weight, &b_el_weight);
   fChain->SetBranchAddress("el_ptcone20", &el_ptcone20, &b_el_ptcone20);
   fChain->SetBranchAddress("el_ptcone30", &el_ptcone30, &b_el_ptcone30);
   fChain->SetBranchAddress("el_ptvarcone20", &el_ptvarcone20, &b_el_ptvarcone20);
   fChain->SetBranchAddress("el_ptvarcone30", &el_ptvarcone30, &b_el_ptvarcone30);
   fChain->SetBranchAddress("el_topoetcone20", &el_topoetcone20, &b_el_topoetcone20);
   fChain->SetBranchAddress("el_topoetcone30", &el_topoetcone30, &b_el_topoetcone30);
   fChain->SetBranchAddress("el_d0sig", &el_d0sig, &b_el_d0sig);
   fChain->SetBranchAddress("el_z0sintheta", &el_z0sintheta, &b_el_z0sintheta);
   fChain->SetBranchAddress("el_isPrompt", &el_isPrompt, &b_el_isPrompt);
   fChain->SetBranchAddress("el_passAmbi", &el_passAmbi, &b_el_passAmbi);
   fChain->SetBranchAddress("lep_pT", &lep_pT, &b_lep_pT);
   fChain->SetBranchAddress("lep_eta", &lep_eta, &b_lep_eta);
   fChain->SetBranchAddress("lep_phi", &lep_phi, &b_lep_phi);
   fChain->SetBranchAddress("lep_E", &lep_E, &b_lep_E);
   fChain->SetBranchAddress("lep_m", &lep_m, &b_lep_m);
   fChain->SetBranchAddress("lep_truthPt", &lep_truthPt, &b_lep_truthPt);
   fChain->SetBranchAddress("lep_truthEta", &lep_truthEta, &b_lep_truthEta);
   fChain->SetBranchAddress("lep_truthPhi", &lep_truthPhi, &b_lep_truthPhi);
   fChain->SetBranchAddress("lep_truthE", &lep_truthE, &b_lep_truthE);
   fChain->SetBranchAddress("lep_truthGammaPt", &lep_truthGammaPt, &b_lep_truthGammaPt);
   fChain->SetBranchAddress("mu_match_HLT_mu50", &mu_match_HLT_mu50, &b_mu_match_HLT_mu50);
   fChain->SetBranchAddress("lep_match_HLT_mu50", &lep_match_HLT_mu50, &b_lep_match_HLT_mu50);
   fChain->SetBranchAddress("el_match_HLT_mu50", &el_match_HLT_mu50, &b_el_match_HLT_mu50);
   fChain->SetBranchAddress("mu_match_HLT_2mu14", &mu_match_HLT_2mu14, &b_mu_match_HLT_2mu14);
   fChain->SetBranchAddress("lep_match_HLT_2mu14", &lep_match_HLT_2mu14, &b_lep_match_HLT_2mu14);
   fChain->SetBranchAddress("el_match_HLT_2mu14", &el_match_HLT_2mu14, &b_el_match_HLT_2mu14);
   fChain->SetBranchAddress("mu_match_HLT_mu24_mu8noL1", &mu_match_HLT_mu24_mu8noL1, &b_mu_match_HLT_mu24_mu8noL1);
   fChain->SetBranchAddress("lep_match_HLT_mu24_mu8noL1", &lep_match_HLT_mu24_mu8noL1, &b_lep_match_HLT_mu24_mu8noL1);
   fChain->SetBranchAddress("el_match_HLT_mu24_mu8noL1", &el_match_HLT_mu24_mu8noL1, &b_el_match_HLT_mu24_mu8noL1);
   fChain->SetBranchAddress("mu_match_HLT_mu24", &mu_match_HLT_mu24, &b_mu_match_HLT_mu24);
   fChain->SetBranchAddress("lep_match_HLT_mu24", &lep_match_HLT_mu24, &b_lep_match_HLT_mu24);
   fChain->SetBranchAddress("el_match_HLT_mu24", &el_match_HLT_mu24, &b_el_match_HLT_mu24);
   fChain->SetBranchAddress("mu_match_HLT_mu20_iloose_L1MU15", &mu_match_HLT_mu20_iloose_L1MU15, &b_mu_match_HLT_mu20_iloose_L1MU15);
   fChain->SetBranchAddress("lep_match_HLT_mu20_iloose_L1MU15", &lep_match_HLT_mu20_iloose_L1MU15, &b_lep_match_HLT_mu20_iloose_L1MU15);
   fChain->SetBranchAddress("el_match_HLT_mu20_iloose_L1MU15", &el_match_HLT_mu20_iloose_L1MU15, &b_el_match_HLT_mu20_iloose_L1MU15);
   fChain->SetBranchAddress("mu_match_HLT_2mu10", &mu_match_HLT_2mu10, &b_mu_match_HLT_2mu10);
   fChain->SetBranchAddress("lep_match_HLT_2mu10", &lep_match_HLT_2mu10, &b_lep_match_HLT_2mu10);
   fChain->SetBranchAddress("el_match_HLT_2mu10", &el_match_HLT_2mu10, &b_el_match_HLT_2mu10);
   fChain->SetBranchAddress("mu_match_HLT_mu10", &mu_match_HLT_mu10, &b_mu_match_HLT_mu10);
   fChain->SetBranchAddress("lep_match_HLT_mu10", &lep_match_HLT_mu10, &b_lep_match_HLT_mu10);
   fChain->SetBranchAddress("el_match_HLT_mu10", &el_match_HLT_mu10, &b_el_match_HLT_mu10);
   fChain->SetBranchAddress("mu_match_HLT_mu22_mu8noL1", &mu_match_HLT_mu22_mu8noL1, &b_mu_match_HLT_mu22_mu8noL1);
   fChain->SetBranchAddress("lep_match_HLT_mu22_mu8noL1", &lep_match_HLT_mu22_mu8noL1, &b_lep_match_HLT_mu22_mu8noL1);
   fChain->SetBranchAddress("el_match_HLT_mu22_mu8noL1", &el_match_HLT_mu22_mu8noL1, &b_el_match_HLT_mu22_mu8noL1);
   fChain->SetBranchAddress("mu_match_HLT_mu22", &mu_match_HLT_mu22, &b_mu_match_HLT_mu22);
   fChain->SetBranchAddress("lep_match_HLT_mu22", &lep_match_HLT_mu22, &b_lep_match_HLT_mu22);
   fChain->SetBranchAddress("el_match_HLT_mu22", &el_match_HLT_mu22, &b_el_match_HLT_mu22);
   fChain->SetBranchAddress("mu_match_HLT_mu20_mu8noL1", &mu_match_HLT_mu20_mu8noL1, &b_mu_match_HLT_mu20_mu8noL1);
   fChain->SetBranchAddress("lep_match_HLT_mu20_mu8noL1", &lep_match_HLT_mu20_mu8noL1, &b_lep_match_HLT_mu20_mu8noL1);
   fChain->SetBranchAddress("el_match_HLT_mu20_mu8noL1", &el_match_HLT_mu20_mu8noL1, &b_el_match_HLT_mu20_mu8noL1);
   fChain->SetBranchAddress("mu_match_HLT_mu20", &mu_match_HLT_mu20, &b_mu_match_HLT_mu20);
   fChain->SetBranchAddress("lep_match_HLT_mu20", &lep_match_HLT_mu20, &b_lep_match_HLT_mu20);
   fChain->SetBranchAddress("el_match_HLT_mu20", &el_match_HLT_mu20, &b_el_match_HLT_mu20);
   fChain->SetBranchAddress("mu_match_HLT_mu18_mu8noL1", &mu_match_HLT_mu18_mu8noL1, &b_mu_match_HLT_mu18_mu8noL1);
   fChain->SetBranchAddress("lep_match_HLT_mu18_mu8noL1", &lep_match_HLT_mu18_mu8noL1, &b_lep_match_HLT_mu18_mu8noL1);
   fChain->SetBranchAddress("el_match_HLT_mu18_mu8noL1", &el_match_HLT_mu18_mu8noL1, &b_el_match_HLT_mu18_mu8noL1);
   fChain->SetBranchAddress("mu_match_HLT_mu18", &mu_match_HLT_mu18, &b_mu_match_HLT_mu18);
   fChain->SetBranchAddress("lep_match_HLT_mu18", &lep_match_HLT_mu18, &b_lep_match_HLT_mu18);
   fChain->SetBranchAddress("el_match_HLT_mu18", &el_match_HLT_mu18, &b_el_match_HLT_mu18);
   fChain->SetBranchAddress("mu_match_HLT_e24_lhmedium_iloose_L1EM18VH", &mu_match_HLT_e24_lhmedium_iloose_L1EM18VH, &b_mu_match_HLT_e24_lhmedium_iloose_L1EM18VH);
   fChain->SetBranchAddress("lep_match_HLT_e24_lhmedium_iloose_L1EM18VH", &lep_match_HLT_e24_lhmedium_iloose_L1EM18VH, &b_lep_match_HLT_e24_lhmedium_iloose_L1EM18VH);
   fChain->SetBranchAddress("el_match_HLT_e24_lhmedium_iloose_L1EM18VH", &el_match_HLT_e24_lhmedium_iloose_L1EM18VH, &b_el_match_HLT_e24_lhmedium_iloose_L1EM18VH);
   fChain->SetBranchAddress("mu_match_HLT_e24_lhmedium_iloose_L1EM20VH", &mu_match_HLT_e24_lhmedium_iloose_L1EM20VH, &b_mu_match_HLT_e24_lhmedium_iloose_L1EM20VH);
   fChain->SetBranchAddress("lep_match_HLT_e24_lhmedium_iloose_L1EM20VH", &lep_match_HLT_e24_lhmedium_iloose_L1EM20VH, &b_lep_match_HLT_e24_lhmedium_iloose_L1EM20VH);
   fChain->SetBranchAddress("el_match_HLT_e24_lhmedium_iloose_L1EM20VH", &el_match_HLT_e24_lhmedium_iloose_L1EM20VH, &b_el_match_HLT_e24_lhmedium_iloose_L1EM20VH);
   fChain->SetBranchAddress("mu_match_HLT_e60_lhmedium", &mu_match_HLT_e60_lhmedium, &b_mu_match_HLT_e60_lhmedium);
   fChain->SetBranchAddress("lep_match_HLT_e60_lhmedium", &lep_match_HLT_e60_lhmedium, &b_lep_match_HLT_e60_lhmedium);
   fChain->SetBranchAddress("el_match_HLT_e60_lhmedium", &el_match_HLT_e60_lhmedium, &b_el_match_HLT_e60_lhmedium);
   fChain->SetBranchAddress("mu_match_HLT_2e17_lhloose", &mu_match_HLT_2e17_lhloose, &b_mu_match_HLT_2e17_lhloose);
   fChain->SetBranchAddress("lep_match_HLT_2e17_lhloose", &lep_match_HLT_2e17_lhloose, &b_lep_match_HLT_2e17_lhloose);
   fChain->SetBranchAddress("el_match_HLT_2e17_lhloose", &el_match_HLT_2e17_lhloose, &b_el_match_HLT_2e17_lhloose);
   fChain->SetBranchAddress("mu_match_HLT_2e12_lhloose_L12EM10VH", &mu_match_HLT_2e12_lhloose_L12EM10VH, &b_mu_match_HLT_2e12_lhloose_L12EM10VH);
   fChain->SetBranchAddress("lep_match_HLT_2e12_lhloose_L12EM10VH", &lep_match_HLT_2e12_lhloose_L12EM10VH, &b_lep_match_HLT_2e12_lhloose_L12EM10VH);
   fChain->SetBranchAddress("el_match_HLT_2e12_lhloose_L12EM10VH", &el_match_HLT_2e12_lhloose_L12EM10VH, &b_el_match_HLT_2e12_lhloose_L12EM10VH);
   fChain->SetBranchAddress("mu_match_HLT_e17_lhloose_mu14", &mu_match_HLT_e17_lhloose_mu14, &b_mu_match_HLT_e17_lhloose_mu14);
   fChain->SetBranchAddress("lep_match_HLT_e17_lhloose_mu14", &lep_match_HLT_e17_lhloose_mu14, &b_lep_match_HLT_e17_lhloose_mu14);
   fChain->SetBranchAddress("el_match_HLT_e17_lhloose_mu14", &el_match_HLT_e17_lhloose_mu14, &b_el_match_HLT_e17_lhloose_mu14);
   fChain->SetBranchAddress("mu_match_HLT_e7_lhmedium_mu24", &mu_match_HLT_e7_lhmedium_mu24, &b_mu_match_HLT_e7_lhmedium_mu24);
   fChain->SetBranchAddress("lep_match_HLT_e7_lhmedium_mu24", &lep_match_HLT_e7_lhmedium_mu24, &b_lep_match_HLT_e7_lhmedium_mu24);
   fChain->SetBranchAddress("el_match_HLT_e7_lhmedium_mu24", &el_match_HLT_e7_lhmedium_mu24, &b_el_match_HLT_e7_lhmedium_mu24);
   fChain->SetBranchAddress("mu_match_HLT_e24_lhmedium_L1EM20VH", &mu_match_HLT_e24_lhmedium_L1EM20VH, &b_mu_match_HLT_e24_lhmedium_L1EM20VH);
   fChain->SetBranchAddress("lep_match_HLT_e24_lhmedium_L1EM20VH", &lep_match_HLT_e24_lhmedium_L1EM20VH, &b_lep_match_HLT_e24_lhmedium_L1EM20VH);
   fChain->SetBranchAddress("el_match_HLT_e24_lhmedium_L1EM20VH", &el_match_HLT_e24_lhmedium_L1EM20VH, &b_el_match_HLT_e24_lhmedium_L1EM20VH);
   fChain->SetBranchAddress("mu_match_HLT_e26_lhmedium_L1EM22VHI_mu8noL1", &mu_match_HLT_e26_lhmedium_L1EM22VHI_mu8noL1, &b_mu_match_HLT_e26_lhmedium_L1EM22VHI_mu8noL1);
   fChain->SetBranchAddress("lep_match_HLT_e26_lhmedium_L1EM22VHI_mu8noL1", &lep_match_HLT_e26_lhmedium_L1EM22VHI_mu8noL1, &b_lep_match_HLT_e26_lhmedium_L1EM22VHI_mu8noL1);
   fChain->SetBranchAddress("el_match_HLT_e26_lhmedium_L1EM22VHI_mu8noL1", &el_match_HLT_e26_lhmedium_L1EM22VHI_mu8noL1, &b_el_match_HLT_e26_lhmedium_L1EM22VHI_mu8noL1);
   fChain->SetBranchAddress("mu_match_HLT_e24_lhmedium_L1EM20VHI_mu8noL1", &mu_match_HLT_e24_lhmedium_L1EM20VHI_mu8noL1, &b_mu_match_HLT_e24_lhmedium_L1EM20VHI_mu8noL1);
   fChain->SetBranchAddress("lep_match_HLT_e24_lhmedium_L1EM20VHI_mu8noL1", &lep_match_HLT_e24_lhmedium_L1EM20VHI_mu8noL1, &b_lep_match_HLT_e24_lhmedium_L1EM20VHI_mu8noL1);
   fChain->SetBranchAddress("el_match_HLT_e24_lhmedium_L1EM20VHI_mu8noL1", &el_match_HLT_e24_lhmedium_L1EM20VHI_mu8noL1, &b_el_match_HLT_e24_lhmedium_L1EM20VHI_mu8noL1);
   fChain->SetBranchAddress("mu_match_HLT_xe70", &mu_match_HLT_xe70, &b_mu_match_HLT_xe70);
   fChain->SetBranchAddress("lep_match_HLT_xe70", &lep_match_HLT_xe70, &b_lep_match_HLT_xe70);
   fChain->SetBranchAddress("el_match_HLT_xe70", &el_match_HLT_xe70, &b_el_match_HLT_xe70);
   fChain->SetBranchAddress("mu_match_HLT_xe80", &mu_match_HLT_xe80, &b_mu_match_HLT_xe80);
   fChain->SetBranchAddress("lep_match_HLT_xe80", &lep_match_HLT_xe80, &b_lep_match_HLT_xe80);
   fChain->SetBranchAddress("el_match_HLT_xe80", &el_match_HLT_xe80, &b_el_match_HLT_xe80);
   fChain->SetBranchAddress("mu_match_HLT_xe80_wEFMu", &mu_match_HLT_xe80_wEFMu, &b_mu_match_HLT_xe80_wEFMu);
   fChain->SetBranchAddress("lep_match_HLT_xe80_wEFMu", &lep_match_HLT_xe80_wEFMu, &b_lep_match_HLT_xe80_wEFMu);
   fChain->SetBranchAddress("el_match_HLT_xe80_wEFMu", &el_match_HLT_xe80_wEFMu, &b_el_match_HLT_xe80_wEFMu);
   fChain->SetBranchAddress("mu_match_HLT_xe100", &mu_match_HLT_xe100, &b_mu_match_HLT_xe100);
   fChain->SetBranchAddress("lep_match_HLT_xe100", &lep_match_HLT_xe100, &b_lep_match_HLT_xe100);
   fChain->SetBranchAddress("el_match_HLT_xe100", &el_match_HLT_xe100, &b_el_match_HLT_xe100);
   fChain->SetBranchAddress("lep_tight", &lep_tight, &b_lep_tight);
   fChain->SetBranchAddress("lep_tight_weight", &lep_tight_weight, &b_lep_tight_weight);
   fChain->SetBranchAddress("lep_isPrompt", &lep_isPrompt, &b_lep_isPrompt);
   fChain->SetBranchAddress("lep_weight", &lep_weight, &b_lep_weight);
   fChain->SetBranchAddress("lep_pdgId", &lep_pdgId, &b_lep_pdgId);
   fChain->SetBranchAddress("eetrig_match", &eetrig_match, &b_eetrig_match);
   fChain->SetBranchAddress("emtrig_match", &emtrig_match, &b_emtrig_match);
   fChain->SetBranchAddress("mmtrig_match", &mmtrig_match, &b_mmtrig_match);
   fChain->SetBranchAddress("mmtrig_match1", &mmtrig_match1, &b_mmtrig_match1);
   fChain->SetBranchAddress("truth_ZpT", &truth_ZpT, &b_truth_ZpT);
   fChain->SetBranchAddress("truth_Zll", &truth_Zll, &b_truth_Zll);
   fChain->SetBranchAddress("jet_n", &jet_n, &b_jet_n);
   fChain->SetBranchAddress("el_n", &el_n, &b_el_n);
   fChain->SetBranchAddress("mu_n", &mu_n, &b_mu_n);
   fChain->SetBranchAddress("lep_n", &lep_n, &b_lep_n);
   fChain->SetBranchAddress("bjet_n", &bjet_n, &b_bjet_n);
   fChain->SetBranchAddress("MT2W", &MT2W, &b_MT2W);
   fChain->SetBranchAddress("MT2Top", &MT2Top, &b_MT2Top);
   fChain->SetBranchAddress("Pass_SUSY2_Triggers", &Pass_SUSY2_Triggers, &b_Pass_SUSY2_Triggers);
   fChain->SetBranchAddress("PassedSUSYTriggers", &PassedSUSYTriggers, &b_PassedSUSYTriggers);
   fChain->SetBranchAddress("truthLepton_status", &truthLepton_status, &b_truthLepton_status);
   fChain->SetBranchAddress("truthLepton_pT", &truthLepton_pT, &b_truthLepton_pT);
   fChain->SetBranchAddress("truthLepton_eta", &truthLepton_eta, &b_truthLepton_eta);
   fChain->SetBranchAddress("truthLepton_phi", &truthLepton_phi, &b_truthLepton_phi);
   fChain->SetBranchAddress("truthLepton_E", &truthLepton_E, &b_truthLepton_E);
   fChain->SetBranchAddress("truthLepton_pdgID", &truthLepton_pdgID, &b_truthLepton_pdgID);
   fChain->SetBranchAddress("truthLepton_parent_pdgID", &truthLepton_parent_pdgID, &b_truthLepton_parent_pdgID);
   fChain->SetBranchAddress("truthLepton_match_electron", &truthLepton_match_electron, &b_truthLepton_match_electron);
   fChain->SetBranchAddress("truthLepton_weight_electron", &truthLepton_weight_electron, &b_truthLepton_weight_electron);
   fChain->SetBranchAddress("truthLepton_match_muon", &truthLepton_match_muon, &b_truthLepton_match_muon);
   fChain->SetBranchAddress("truthLepton_weight_muon", &truthLepton_weight_muon, &b_truthLepton_weight_muon);
   fChain->SetBranchAddress("truthLepton_n", &truthLepton_n, &b_truthLepton_n);
   fChain->SetBranchAddress("truthLepton_nWZel", &truthLepton_nWZel, &b_truthLepton_nWZel);
   fChain->SetBranchAddress("truthLepton_nWZmu", &truthLepton_nWZmu, &b_truthLepton_nWZmu);
   fChain->SetBranchAddress("truthLepton_nWZtau", &truthLepton_nWZtau, &b_truthLepton_nWZtau);
   fChain->SetBranchAddress("truthLepton_nWZlep", &truthLepton_nWZlep, &b_truthLepton_nWZlep);
   fChain->SetBranchAddress("truthPhoton_n", &truthPhoton_n, &b_truthPhoton_n);
   fChain->SetBranchAddress("truthMET_Filter", &truthMET_Filter, &b_truthMET_Filter);
   fChain->SetBranchAddress("truthMET_NonInt", &truthMET_NonInt, &b_truthMET_NonInt);
   fChain->SetBranchAddress("truthMET_NonIntPhi", &truthMET_NonIntPhi, &b_truthMET_NonIntPhi);
   fChain->SetBranchAddress("truthMET", &truthMET, &b_truthMET);
   fChain->SetBranchAddress("truthMET_Phi", &truthMET_Phi, &b_truthMET_Phi);
   fChain->SetBranchAddress("jet_n_vetolep", &jet_n_vetolep, &b_jet_n_vetolep);
   fChain->SetBranchAddress("HT_vetolep", &HT_vetolep, &b_HT_vetolep);
   fChain->SetBranchAddress("nVtx", &nVtx, &b_nVtx);
   fChain->SetBranchAddress("mu_ms_pt", &mu_ms_pt, &b_mu_ms_pt);
   fChain->SetBranchAddress("mu_ms_qoverpsigma", &mu_ms_qoverpsigma, &b_mu_ms_qoverpsigma);
   fChain->SetBranchAddress("weight1fb", &weight1fb, &b_weight1fb);
   fChain->SetBranchAddress("lepweight", &lepweight, &b_lepweight);
   fChain->SetBranchAddress("nGenEvents", &nGenEvents, &b_nGenEvents);
   Notify();
}

inline Bool_t HiggsinoBase::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

inline void HiggsinoBase::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
inline Int_t HiggsinoBase::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
