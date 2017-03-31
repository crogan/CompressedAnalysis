#ifndef CompressedHiggsinoNtupleMultiTree_h
#define CompressedHiggsinoNtupleMultiTree_h

#include "NtupleBase.hh"
#include "HFntupleBase.hh"
#include "SussexBase.hh"
#include "HiggsinoBase.hh"
#include "SimpleBase.hh"
#include "Incl1LBase.hh"
#include "SusySkimHiggsinoBase.hh"

#include "RestFrames/RestFrames.hh"

using namespace RestFrames;

class CompressedHiggsinoNtupleMultiTree : public NtupleBase<SusySkimHiggsinoBase> {

public:
  CompressedHiggsinoNtupleMultiTree(TTree* tree = 0);
  virtual ~CompressedHiggsinoNtupleMultiTree();

private:
  void InitOutputTree();
  void FillOutputTree();

  // Higgsino model format-specific variables

  double m_MET;
  double m_HLT_xe70;
  double m_TrkMET;
  double m_dphiMin1;
  double m_dphiMin2;
  double m_dphiMin3;
  double m_dphiMinAll;

  double m_pT_1jet;
  double m_pT_2jet;
  double m_pT_3jet;
  double m_pT_4jet;

  int m_nEl;
  int m_nMu;
  int m_nBjet;
  double m_MTW;
  double m_MT2W;
  double m_MT2Top;
  double m_pT_1lep;
  int m_id_1lep;
  double m_pT_2lep;
  int m_id_2lep;
  double m_pT_3lep;
  int m_id_3lep;
  
  // common variables for output tree
  double m_weight;

  double m_pTjS1;
  double m_pTjS2;
  double m_pTjS3;
  double m_pTjS4;
  double m_etajS1;
  double m_etajS2;
  double m_etajS3;
  double m_etajS4;
  int m_NjS;
  int m_NjISR;

  // which tree are we using?
  bool m_Is_1L;
  bool m_Is_2LNJ;
  bool m_Is_1L1L;
  bool m_Is_1L1Lnu;
  bool m_Is_2L1L;
  bool m_Is_2L1Lnu;
  
  // compressed observables
  // common to all trees
  double m_PTISR;
  double m_PTCM;
  double m_RISR;
  double m_cosCM;
  double m_cosS;
  double m_MISR;
  double m_dphiCMI;
  double m_dphiSI;
  double m_dphiISRI;

  double m_HN2S;
  double m_HN2SR;
  double m_H11S;
  double m_HN1Ca;
  double m_HN1Cb;
  double m_H11Ca;
  double m_H11Cb;
  double m_cosC;

  double m_MZ;
  double m_MJ;
  double m_cosZ;
  double m_cosJ;
  
  // RestFrames frames and friends

  // combinatoric (transverse) tree
  // for jet assignment
  LabRecoFrame*        LAB_comb;
  DecayRecoFrame*      CM_comb;
  DecayRecoFrame*      S_comb;
  VisibleRecoFrame*    ISR_comb;
  VisibleRecoFrame*    J_comb;
  VisibleRecoFrame*    L_comb;
  InvisibleRecoFrame*  I_comb;
  InvisibleGroup*      INV_comb;
  SetMassInvJigsaw*    InvMass_comb;
  CombinatoricGroup*   JETS_comb;
  MinMassesCombJigsaw* SplitJETS_comb;

  // 2L+NJ tree (Z->ll + W/Z->qq)
  LabRecoFrame*        LAB_2LNJ;
  DecayRecoFrame*      CM_2LNJ;
  DecayRecoFrame*      S_2LNJ;
  VisibleRecoFrame*    ISR_2LNJ;

  DecayRecoFrame*      Ca_2LNJ;  
  DecayRecoFrame*      Z_2LNJ;
  VisibleRecoFrame*    L1_2LNJ;
  VisibleRecoFrame*    L2_2LNJ;

  DecayRecoFrame*          Cb_2LNJ;
  SelfAssemblingRecoFrame* JSA_2LNJ;
  VisibleRecoFrame*        J_2LNJ;
  
  InvisibleRecoFrame*  Ia_2LNJ;
  InvisibleRecoFrame*  Ib_2LNJ;

  InvisibleGroup*       INV_2LNJ;
  SetMassInvJigsaw*     InvMass_2LNJ;
  SetRapidityInvJigsaw* InvRapidity_2LNJ;
  ContraBoostInvJigsaw* SplitINV_2LNJ;
  CombinatoricGroup*    JETS_2LNJ;

  // 1L+1L tree (Z/W->l + Z/W->l)
  LabRecoFrame*        LAB_1L1L;
  DecayRecoFrame*      CM_1L1L;
  DecayRecoFrame*      S_1L1L;
  VisibleRecoFrame*    ISR_1L1L;

  DecayRecoFrame*      Ca_1L1L;  
  VisibleRecoFrame*    La_1L1L;

  DecayRecoFrame*      Cb_1L1L;  
  VisibleRecoFrame*    Lb_1L1L;
  
  InvisibleRecoFrame*  Ia_1L1L;
  InvisibleRecoFrame*  Ib_1L1L;

  InvisibleGroup*       INV_1L1L;
  SetMassInvJigsaw*     InvMass_1L1L;
  SetRapidityInvJigsaw* InvRapidity_1L1L;
  ContraBoostInvJigsaw* SplitINV_1L1L;

  // 1L+1L tree (Z/W->l + Z/W->l), with neutrino ~ lepton
  LabRecoFrame*        LAB_1L1Lnu;
  DecayRecoFrame*      CM_1L1Lnu;
  DecayRecoFrame*      S_1L1Lnu;
  VisibleRecoFrame*    ISR_1L1Lnu;

  DecayRecoFrame*      Ca_1L1Lnu;  
  DecayRecoFrame*      Wa_1L1Lnu;
  VisibleRecoFrame*    La_1L1Lnu;
  VisibleRecoFrame*    Na_1L1Lnu;

  DecayRecoFrame*      Cb_1L1Lnu;  
  DecayRecoFrame*      Wb_1L1Lnu;
  VisibleRecoFrame*    Lb_1L1Lnu;
  VisibleRecoFrame*    Nb_1L1Lnu;
  
  InvisibleRecoFrame*  Ia_1L1Lnu;
  InvisibleRecoFrame*  Ib_1L1Lnu;

  InvisibleGroup*       INV_1L1Lnu;
  SetMassInvJigsaw*     InvMass_1L1Lnu;
  SetRapidityInvJigsaw* InvRapidity_1L1Lnu;
  ContraBoostInvJigsaw* SplitINV_1L1Lnu;

  // 2L+1L tree (Z->ll + Z/W->l)
  LabRecoFrame*        LAB_2L1L;
  DecayRecoFrame*      CM_2L1L;
  DecayRecoFrame*      S_2L1L;
  VisibleRecoFrame*    ISR_2L1L;

  DecayRecoFrame*      Ca_2L1L;
  DecayRecoFrame*      Z_2L1L;  
  VisibleRecoFrame*    L1_2L1L;
  VisibleRecoFrame*    L2_2L1L;

  DecayRecoFrame*      Cb_2L1L;  
  VisibleRecoFrame*    Lb_2L1L;
  
  InvisibleRecoFrame*  Ia_2L1L;
  InvisibleRecoFrame*  Ib_2L1L;

  InvisibleGroup*       INV_2L1L;
  SetMassInvJigsaw*     InvMass_2L1L;
  SetRapidityInvJigsaw* InvRapidity_2L1L;
  ContraBoostInvJigsaw* SplitINV_2L1L;

  // 2L+1L tree (Z->ll + Z/W->l), with neutrino ~ lepton
  LabRecoFrame*        LAB_2L1Lnu;
  DecayRecoFrame*      CM_2L1Lnu;
  DecayRecoFrame*      S_2L1Lnu;
  VisibleRecoFrame*    ISR_2L1Lnu;

  DecayRecoFrame*      Ca_2L1Lnu;
  DecayRecoFrame*      Z_2L1Lnu;  
  VisibleRecoFrame*    L1_2L1Lnu;
  VisibleRecoFrame*    L2_2L1Lnu;

  DecayRecoFrame*      Cb_2L1Lnu;  
  DecayRecoFrame*      W_2L1Lnu;  
  VisibleRecoFrame*    Lb_2L1Lnu;
  VisibleRecoFrame*    Nb_2L1Lnu;
  
  InvisibleRecoFrame*  Ia_2L1Lnu;
  InvisibleRecoFrame*  Ib_2L1Lnu;

  InvisibleGroup*       INV_2L1Lnu;
  SetMassInvJigsaw*     InvMass_2L1Lnu;
  SetRapidityInvJigsaw* InvRapidity_2L1Lnu;
  ContraBoostInvJigsaw* SplitINV_2L1Lnu;
  

};

#endif
