#ifndef CompressedHiggsinoNtuple_h
#define CompressedHiggsinoNtuple_h

#include "NtupleBase.hh"
#include "HFntupleBase.hh"
#include "SussexBase.hh"
#include "HiggsinoBase.hh"

#include "RestFrames/RestFrames.hh"

using namespace RestFrames;

class CompressedHiggsinoNtuple : public NtupleBase<HiggsinoBase> {

public:
  CompressedHiggsinoNtuple(TTree* tree = 0);
  virtual ~CompressedHiggsinoNtuple();

private:
  void InitOutputTree();
  void FillOutputTree();

  // Higgsino model format-specific variables

  double m_TrkMET;
  double m_HLT_xe70;

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
  double m_pT_1lep;
  double m_pT_2lep;

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
  double m_Mbb;
  double m_dphiMinbl1;
  double m_dphiMinbl2;
  double m_dphiMinbl3;
  double m_dRMinbl1;
  double m_dRMinbl2;
  double m_dRMinbl3;

  ///////////////////////
  // compressed variables
  ///////////////////////
  double m_PTISR;
  double m_PTCM;
  double m_RISR;
  double m_cosS;
  double m_MS;
  double m_MISR;
  double m_MV;
  double m_dphiCMI;
  double m_dphiISRI;
  double m_pTjV1;
  double m_pTjV2;
  double m_pTjV3;
  double m_pTjV4;
  double m_pTjV5;
  double m_pTjV6;
  double m_pTbV1;
  double m_pTbV2;
  int m_NbV;
  int m_NbISR;
  int m_NjV;
  int m_NjISR;
  int m_NlV;
  int m_NlISR;
  double m_MW1;
  double m_MW2;
  double m_MW3;
  double m_dphiCML1;
  double m_dphiCML2;
  double m_dphiCML3;
  double m_dphiSL1;
  double m_dphiSL2;
  double m_dphiSL3;
  double m_cosIL1;
  double m_cosIL2;
  double m_cosIL3;
  
  
  // RestFrames frames and friends
  LabRecoFrame*        LAB;
  DecayRecoFrame*      CM;
  DecayRecoFrame*      S;
  VisibleRecoFrame*    ISR;
  VisibleRecoFrame*    V;
  InvisibleRecoFrame*  I;
  InvisibleGroup*      INV;
  SetMassInvJigsaw*    InvMass;
  CombinatoricGroup*   VIS;
  MinMassesCombJigsaw* SplitVis;

};

#endif
