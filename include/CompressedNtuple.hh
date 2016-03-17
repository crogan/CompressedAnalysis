#ifndef CompressedNtuple_h
#define CompressedNtuple_h

#include "NtupleBase.hh"
#include "HFntupleBase.hh"

#include "RestFrames/RestFrames.hh"

using namespace RestFrames;

class CompressedNtuple : public NtupleBase<HFntupleBase> {

public:
  CompressedNtuple(TTree* tree = 0);
  virtual ~CompressedNtuple();

private:
  void InitOutputTree();
  void FillOutputTree();

  // common variables for output tree
  double m_weight;

  double m_MET;

  // compressed variables
  double m_PTISR;
  double m_PIoPTISR;
  double m_cosS;
  double m_MS;
  double m_MISR;
  double m_MV;
  int m_NbV;
  int m_NbISR;
  int m_NjV;
  int m_NjISR;
  double m_dphiCMV;
  
  // RestFrames stuff
  LabRecoFrame*       LAB;
  DecayRecoFrame*     CM;
  DecayRecoFrame*     S;
  VisibleRecoFrame*   ISR;
  VisibleRecoFrame*   V;
  InvisibleRecoFrame* I;
  InvisibleGroup*  INV;
  CombinatoricGroup*  VIS;
  SetMassInvJigsaw*   InvMass;
  MinMassesCombJigsaw* SplitVis;

};

#endif
