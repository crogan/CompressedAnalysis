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

  if(m_Base->NbV[0] < 1)
    return false;

  return true;
}

void StopOptimization::InitCuts(){
  m_CutMin.clear();
  m_CutMax.clear();
  m_CutN.clear();
  m_CutVal.clear();

  // NV
  m_CutMin.push_back(5.);
  m_CutMax.push_back(8);
  m_CutN.push_back(3);
  m_CutVal.push_back(0.);

  // // lep veto
  m_CutMin.push_back(-0.5);
  m_CutMax.push_back(1.5);
  m_CutN.push_back(2);
  m_CutVal.push_back(0.);

   // PTISR
  m_CutMin.push_back(500.);
  m_CutMax.push_back(900.);
  m_CutN.push_back(4);
  m_CutVal.push_back(0.);

  // MS
  // m_CutMin.push_back(0.);
  // m_CutMax.push_back(400.);
  // m_CutN.push_back(8);
  // m_CutVal.push_back(0.);

  // // dphiCMV
  m_CutMin.push_back(0.0);
  m_CutMax.push_back(1.);
  m_CutN.push_back(4);
  m_CutVal.push_back(0.);

  // dphiCMV
  m_CutMin.push_back(0.0);
  m_CutMax.push_back(0.5);
  m_CutN.push_back(4);
  m_CutVal.push_back(0.);

   // PIoHT1CM
  m_CutMin.push_back(0.3);
  m_CutMax.push_back(0.7);
  m_CutN.push_back(8);
  m_CutVal.push_back(0.);

  // // NbV
  m_CutMin.push_back(1.);
  m_CutMax.push_back(3.);
  m_CutN.push_back(2);
  m_CutVal.push_back(0.);

  
  // m_CutMin.push_back(0);
  // m_CutMax.push_back(3.);
  // m_CutN.push_back(3);
  // m_CutVal.push_back(0.);

  // // Rsib
  // m_CutMin.push_back(0.5);
  // m_CutMax.push_back(0.0);
  // m_CutN.push_back(10);
  // m_CutVal.push_back(0.);

  // // RPT_HT1CM
  // m_CutMin.push_back(0.3);
  // m_CutMax.push_back(0.);
  // m_CutN.push_back(30);
  // m_CutVal.push_back(0.);

  // Rsib
  // m_CutMin.push_back(0.5);
  // m_CutMax.push_back(0.);
  // m_CutN.push_back(200);
  // m_CutVal.push_back(0.);

  m_N_Cut = m_CutN.size();
}

int StopOptimization::EvaluateCuts(){
  int icut = 0;

  // double MeffN = m_Base->pT_jet1+m_Base->pT_jet2+m_Base->pT_jet3+m_Base->pT_jet4+m_Base->MET;
  // double HTN = m_Base->pT_jet1+m_Base->pT_jet2;
  // //double METsig = m_Base->MET/sqrt(HTN);
  // double METsig = m_Base->MET/sqrt(m_Base->Meff-m_Base->MET);

  if(m_Base->NjV[0] < m_CutVal[icut])
    return icut;
  icut++;

  if(m_CutVal[icut] > 0.)
    if(!m_Base->LepVeto)
      return icut;
  icut++;

  if(m_Base->PTISR[0] < m_CutVal[icut])
    return icut;
  icut++;

  // if(m_Base->MS < m_CutVal[icut])
  //   return icut;
  // icut++;

   if(m_Base->dphiCMV[0] < m_CutVal[icut])
    return icut;
  icut++;

  if(fabs(m_Base->dphiCMV[0]-acos(-1.)) < m_CutVal[icut])
    return icut;
  icut++;

  if(m_Base->PIoPTISR[0] < m_CutVal[icut])
    return icut;
  icut++;

  if(m_Base->NbV[0] < m_CutVal[icut])
    return icut;
  icut++;
  
  // if(m_Base->Rsib > m_CutVal[icut])
  //   return icut;
  // icut++;

  // if(m_Base->RPT_HT1CM > m_CutVal[icut])
  //   return icut;
  // icut++;
  
  // if(m_Base->deltaQCD < m_CutVal[icut])
  //   return false;

  // if(m_Base->Rsib > m_CutVal[icut])
  //   return false;
      
  return -1;
}
