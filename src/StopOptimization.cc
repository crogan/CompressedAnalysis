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

  if(!m_Base->LepVeto)
     return false;

  if(m_Base->TrkMET < 30.)
    return false;

  if(fabs(m_Base->dphi_MET_TrkMET) > acos(-1.)/3.)
    return false;

  if(m_Base->NbV < 1)
    return false;

  if(m_Base->pTbV1 < 40.)
    return false;

  if(m_Base->NjV < 5)
    return false;

  // if(m_Base->MS < 300)
  //   return false;

  // if(m_Base->dphiISRI < 3.05)
  //   return false;

  /////////////////////

  return true;
}

void StopOptimization::InitCuts(){
  m_CutMin.clear();
  m_CutMax.clear();
  m_CutN.clear();
  m_CutVal.clear();

  // NjV cut
  // m_CutMin.push_back(5.);
  // m_CutMax.push_back(7);
  // m_CutN.push_back(2);
  // m_CutVal.push_back(0.);

  // RISR cut
  m_CutMin.push_back(0.15);
  m_CutMax.push_back(0.7);
  m_CutN.push_back(11);
  m_CutVal.push_back(0.);

  // RISR window
  m_CutMin.push_back(0.3);
  m_CutMax.push_back(0.05);
  m_CutN.push_back(10);
  m_CutVal.push_back(0.);

   // PTISR cut
  m_CutMin.push_back(400.);
  m_CutMax.push_back(750.);
  m_CutN.push_back(7);
  m_CutVal.push_back(0.);

  // MS cut
  m_CutMin.push_back(250.);
  m_CutMax.push_back(550.);
  m_CutN.push_back(6);
  m_CutVal.push_back(0.);

  // NbV
  m_CutMin.push_back(1.);
  m_CutMax.push_back(3.);
  m_CutN.push_back(2);
  m_CutVal.push_back(0.);

  // m_pTjV4
  m_CutMin.push_back(20);
  m_CutMax.push_back(80.);
  m_CutN.push_back(12);
  m_CutVal.push_back(0.);

  // m_pTjV5
  // m_CutMin.push_back(20);
  // m_CutMax.push_back(65.);
  // m_CutN.push_back(9);
  // m_CutVal.push_back(0.);

  // dphiISRI
  m_CutMin.push_back(2.6);
  m_CutMax.push_back(3.15);
  m_CutN.push_back(11);
  m_CutVal.push_back(0.);

  m_N_Cut = m_CutN.size();
}

int StopOptimization::EvaluateCuts(){
  int icut = 0;

  // if(m_Base->NjV < m_CutVal[icut])
  //   return icut;
  // icut++;

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

  if(m_Base->pTjV4 < m_CutVal[icut])
    return icut;
  icut++;

  // if(m_Base->pTjV5 < m_CutVal[icut])
  //   return icut;
  // icut++;

  if(m_Base->dphiISRI < m_CutVal[icut])
    return icut;
  icut++;
      
  return -1;
}
