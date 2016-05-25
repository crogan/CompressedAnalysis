#include "Stop1LOptimization.hh"

Stop1LOptimization::Stop1LOptimization()
  : OptimizationBase<CompressedBase>() {}

Stop1LOptimization::~Stop1LOptimization() {}

double Stop1LOptimization::GetEventWeight(){
  if(m_Base)
    return m_Base->weight;
  else
    return 0.;
}

bool Stop1LOptimization::PassBaseline(){
  
  if(!m_Base->HLT_xe70_tc_lcw)
    return false;
      
  if(m_Base->MET < 200.)
    return false;

  if(m_Base->nEl+m_Base->nMu != 1)
     return false;

  if(m_Base->NlV < 1)
    return false;

  // if(m_Base->TrkMET < 30.)
  //   return false;

  // if(fabs(m_Base->dphi_MET_TrkMET) > acos(-1.)/3.)
  //   return false;

  if(m_Base->NbV < 1)
    return false;

  if(m_Base->pTbV1 < 40.)
    return false;

  if(m_Base->PTISR < 400.)
    return false;
  
  if(m_Base->NjV < 3)
    return false;
  
  // if(m_Base->MS < 300)
  //   return false;

  if(m_Base->dphiISRI < 2.95)
    return false;

  /////////////////////

  return true;
}

void Stop1LOptimization::InitCuts(){
  m_CutMin.clear();
  m_CutMax.clear();
  m_CutN.clear();
  m_CutVal.clear();

  // MT cut
  m_CutMin.push_back(120.);
  m_CutMax.push_back(140.);
  m_CutN.push_back(4);
  m_CutVal.push_back(0.);
  
  // NjV cut
  // m_CutMin.push_back(3.);
  // m_CutMax.push_back(5.);
  // m_CutN.push_back(2);
  // m_CutVal.push_back(0.);

  // RISR cut
  m_CutMin.push_back(0.2);
  m_CutMax.push_back(0.7);
  m_CutN.push_back(10);
  m_CutVal.push_back(0.);

  // RISR window
  // m_CutMin.push_back(0.5);
  // m_CutMax.push_back(0.1);
  // m_CutN.push_back(16);
  // m_CutVal.push_back(0.);

   // PTISR cut
  // m_CutMin.push_back(100.);
  // m_CutMax.push_back(600.);
  // m_CutN.push_back(10);
  // m_CutVal.push_back(0.);

  // MS cut
  // m_CutMin.push_back(100.);
  // m_CutMax.push_back(450.);
  // m_CutN.push_back(7);
  // m_CutVal.push_back(0.);

  // NbV
  // m_CutMin.push_back(1.);
  // m_CutMax.push_back(3.);
  // m_CutN.push_back(2);
  // m_CutVal.push_back(0.);

  // m_pTjV3
  m_CutMin.push_back(35);
  m_CutMax.push_back(60.);
  m_CutN.push_back(5);
  m_CutVal.push_back(0.);

  // m_pTjV5
  // m_CutMin.push_back(20);
  // m_CutMax.push_back(65.);
  // m_CutN.push_back(9);
  // m_CutVal.push_back(0.);

  // dphiISRI
  // m_CutMin.push_back(2.8);
  // m_CutMax.push_back(3.15);
  // m_CutN.push_back(7);
  // m_CutVal.push_back(0.);

  // pi-dphiCMI
  m_CutMin.push_back(0.);
  m_CutMax.push_back(1.5);
  m_CutN.push_back(15);
  m_CutVal.push_back(0.);

  // cosIL1
  m_CutMin.push_back(-1.);
  m_CutMax.push_back(1.);
  m_CutN.push_back(20);
  m_CutVal.push_back(0.);

  m_N_Cut = m_CutN.size();
}

int Stop1LOptimization::EvaluateCuts(){
  int icut = 0;

  if(m_Base->MT < m_CutVal[icut])
    return icut;
  icut++;
  
  // if(m_Base->NjV < m_CutVal[icut])
  //   return icut;
  // icut++;

  if(m_Base->RISR < m_CutVal[icut])
    return icut;
  icut++;

  // if(m_Base->RISR > m_CutVal[icut-1]+m_CutVal[icut])
  //   return icut;
  // icut++;

  // if(m_Base->PTISR < m_CutVal[icut])
  //   return icut;
  // icut++;

  // if(m_Base->MS < m_CutVal[icut])
  //   return icut;
  // icut++;

  // if(m_Base->NbV < m_CutVal[icut])
  //   return icut;
  // icut++;

  if(m_Base->pTjV3 < m_CutVal[icut])
    return icut;
  icut++;

  // if(m_Base->pTjV5 < m_CutVal[icut])
  //   return icut;
  // icut++;

  // if(m_Base->dphiISRI < m_CutVal[icut])
  //   return icut;
  // icut++;

  if(acos(-1.)-m_Base->dphiCMI < m_CutVal[icut])
    return icut;
  icut++;

  if(m_Base->cosIL1 < m_CutVal[icut])
    return icut;
  icut++;
      
  return -1;
}
