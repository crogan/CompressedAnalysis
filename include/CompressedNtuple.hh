#ifndef CompressedNtuple_h
#define CompressedNtuple_h

#include "NtupleBase.hh"
#include "HFntupleBase.hh"

#include "RestFrames/RestFrames.hh"

using namespace RestFrames;

class CompressedNtuple : public NtupleBase<HFntupleBase> {

  static const int g_N_algo = 5;

public:
  CompressedNtuple(TTree* tree = 0);
  virtual ~CompressedNtuple();

private:
  void InitOutputTree();
  void FillOutputTree();

  // common variables for output tree
  double m_weight;

  double m_MET;
  double m_TrkMET;
  double m_dphi_MET_TrkMET;

  double m_dphiMin1;
  double m_dphiMin2;
  double m_dphiMin3;
  double m_dphiMinAll;

  // for vetoes, 1 -> pass, 0 -> fail
  bool m_LepVeto;
  bool m_TauVeto;

  // compressed variables
  double m_PTISR[g_N_algo];
  double m_PIoPTISR[g_N_algo];
  double m_cosS[g_N_algo];
  double m_MS[g_N_algo];
  double m_MISR[g_N_algo];
  double m_MV[g_N_algo];
  double m_dphiCMV[g_N_algo];
  double m_pTjV5[g_N_algo];
  double m_pTjV6[g_N_algo];
  double m_pTbV1[g_N_algo];
  double m_pTbV2[g_N_algo];
  int m_NbV[g_N_algo];
  int m_NbISR[g_N_algo];
  int m_NjV[g_N_algo];
  int m_NjISR[g_N_algo];
  
  // RestFrames stuff
  LabRecoFrame*       LAB;
  DecayRecoFrame*     CM;
  DecayRecoFrame*     S;
  VisibleRecoFrame*   ISR;
  VisibleRecoFrame*   V;
  InvisibleRecoFrame* I;
  InvisibleGroup*  INV;
  SetMassInvJigsaw*   InvMass;
  // CombinatoricGroup*  VIS;
  // MinMassesCombJigsaw* SplitVis;

};

#endif
