#include "StopOptimization.hh"

StopOptimization::StopOptimization()
  : OptimizationBase<CompressedBase>() {}

StopOptimization::~StopOptimization() {}

double StopOptimization::GetEventWeight(){
  if(m_Base)
    return m_Base->weight;
  else
    return 0.;
}

bool StopOptimization::PassBaseline(){

  if(!m_Base->HLT_xe70_tc_lcw)
    return false;
      
  if(m_Base->MET < 200.)
    return false;

  if(m_Base->NbV < 1)
    return false;

  if(m_Base->pTbV1 < 40.)
    return false;

  if(m_Base->NjV < 5)
    return false;

  if(!m_Base->LepVeto)
     return false;

  if(m_Base->TrkMET < 30.)
    return false;

  if(fabs(m_Base->dphi_MET_TrkMET) > acos(-1.)/2.)
    return false;

  /////////////////////

  return true;
}

void StopOptimization::InitCuts(){
  m_CutMin.clear();
  m_CutMax.clear();
  m_CutN.clear();
  m_CutVal.clear();

  // NjV cut
  m_CutMin.push_back(2.);
  m_CutMax.push_back(7);
  m_CutN.push_back(5);
  m_CutVal.push_back(0.);

  // RISR cut
  m_CutMin.push_back(0.0);
  m_CutMax.push_back(1.);
  m_CutN.push_back(20);
  m_CutVal.push_back(0.);

  // RISR window
  m_CutMin.push_back(0.5);
  m_CutMax.push_back(0.0);
  m_CutN.push_back(50);
  m_CutVal.push_back(0.);

   // PTISR cut
  m_CutMin.push_back(0.);
  m_CutMax.push_back(700.);
  m_CutN.push_back(7);
  m_CutVal.push_back(0.);

  // MS cut
  m_CutMin.push_back(0.);
  m_CutMax.push_back(500.);
  m_CutN.push_back(20);
  m_CutVal.push_back(0.);

  // NbV
  m_CutMin.push_back(1.);
  m_CutMax.push_back(3.);
  m_CutN.push_back(1);
  m_CutVal.push_back(0.);

  // m_pTjV5
  m_CutMin.push_back(20);
  m_CutMax.push_back(80.);
  m_CutN.push_back(6);
  m_CutVal.push_back(0.);

  // dphiISRI
  m_CutMin.push_back(2.);
  m_CutMax.push_back(acos(-1.));
  m_CutN.push_back(40);
  m_CutVal.push_back(0.);

  m_N_Cut = m_CutN.size();
}

int StopOptimization::EvaluateCuts(){
  int icut = 0;

  if(m_Base->NjV < m_CutVal[icut])
    return icut;
  icut++;

  if(m_Base->RISR < m_CutVal[icut])
    return icut;
  icut++;

  if(m_Base->RISR > m_CutVal[icut-1]+m_CutVal[icut])
    return icut;
  icut++;

  if(m_Base->PTISR < m_CutVal[icut])
    return icut;
  icut++;

  if(m_Base->MS < m_CutVal[icut])
    return icut;
  icut++;

  if(m_Base->NbV < m_CutVal[icut])
    return icut;
  icut++;

  if(m_Base->pTjV5 < m_CutVal[icut])
    return icut;
  icut++;

  if(m_Base->dphiISRI < m_CutVal[icut])
    return icut;
  icut++;
      
  return -1;
}
