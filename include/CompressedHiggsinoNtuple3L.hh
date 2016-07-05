#ifndef CompressedHiggsinoNtuple3L_h
#define CompressedHiggsinoNtuple3L_h

#include "NtupleBase.hh"
#include "HFntupleBase.hh"
#include "SussexBase.hh"
#include "HiggsinoBase.hh"

#include "RestFrames/RestFrames.hh"

using namespace RestFrames;

class CompressedHiggsinoNtuple3L : public NtupleBase<HiggsinoBase> {

public:
  CompressedHiggsinoNtuple3L(TTree* tree = 0);
  virtual ~CompressedHiggsinoNtuple3L();

private:
  void InitOutputTree();
  void FillOutputTree();

  // Higgsino model format-specific variables

  double m_TrkMET;
  double m_HLT_xe70;
  int m_is_OS;

  double m_pT_1jet;
  double m_pT_2jet;
  double m_pT_3jet;
  double m_pT_4jet;

  // for vetoes, 1 -> pass, 0 -> fail

  // 1 lep control regions
  int m_nEl;
  int m_nMu;
  double m_MT2W;
  double m_MT2Top;
  double m_mll;
  double m_pT_1lep;
  int m_id_1lep;
  double m_pT_2lep;
  int m_id_2lep;
  double m_pT_3lep;
  int m_id_3lep;

  // 1 for ee, 2/3 for emu, 0 for mumu
  int m_channel;
  
  // common variables for output tree
  double m_weight;
  double m_HT;
  double m_MET;
  double m_dphiMin1;
  double m_dphiMin2;
  double m_dphiMin3;
  double m_dphiMinAll;

  ///////////////////////
  // compressed variables
  ///////////////////////
  double m_PTISR;
  double m_PTCM;
  double m_RISR;
  double m_cosS;
  double m_MS;
  double m_MISR;
  double m_dphiCMI;
  double m_dphiISRI;
  double m_pTjISR1;
  double m_pTjISR2;
  int m_NjISR;
  double m_MW1;
  double m_MW2;
  double m_mllOS;
  double m_MZ;
  double m_dphiCML1;
  double m_dphiCML2;
  double m_dphiSL1;
  double m_dphiSL2;
  double m_cosIL1;
  double m_cosIL2;
  double m_cosLLOS;
  double m_dphiLLOS;
  
  // RestFrames frames and friends
  LabRecoFrame*        LAB;
  DecayRecoFrame*      CM;
  DecayRecoFrame*      S;
  VisibleRecoFrame*    ISR;
  VisibleRecoFrame*    L;
  InvisibleRecoFrame*  I;
  InvisibleGroup*      INV;
  SetMassInvJigsaw*    InvMass;
  SetRapidityInvJigsaw*    InvRapidity;

};

#endif
