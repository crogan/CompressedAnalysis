#include "CompressedNtuple.hh"

using namespace RestFrames;

CompressedNtuple::CompressedNtuple(TTree* tree)
  : NtupleBase<HFntupleBase>(tree)
{
  // RestFrames stuff

  ////////////// Tree set-up /////////////////
  LAB = new LabRecoFrame("LAB","lab");
  CM = new DecayRecoFrame("CM","CM");
  S = new DecayRecoFrame("S","S");
  ISR = new VisibleRecoFrame("ISR","ISR");
  V = new VisibleRecoFrame("V","Vis");
  I = new InvisibleRecoFrame("I","Inv");

  LAB->SetChildFrame(*CM);
  CM->AddChildFrame(*ISR);
  CM->AddChildFrame(*S);
  S->AddChildFrame(*V);
  S->AddChildFrame(*I);

  LAB->InitializeTree(); 
  ////////////// Tree set-up /////////////////

  ////////////// Jigsaw rules set-up /////////////////
  INV = new InvisibleGroup("INV","Invisible System");
  INV->AddFrame(*I);

  // VIS = new CombinatoricGroup("VIS","Visible Objects");
  // VIS->AddFrame(*ISR);
  // VIS->SetNElementsForFrame(*ISR,1,false);
  // VIS->AddFrame(*V);
  // VIS->SetNElementsForFrame(*V,0,false);

  // set the invisible system mass to zero
  InvMass = new SetMassInvJigsaw("InvMass", "Invisible system mass Jigsaw");
  INV->AddJigsaw(*InvMass);

  /*
  // define the rule for partitioning objects between "ISR" and "V"
  SplitVis = new MinMassesCombJigsaw("SplitVis","Minimize M_{ISR} and M_{S} Jigsaw");
  VIS->AddJigsaw(*SplitVis);
  // "0" group (ISR)
  SplitVis->AddFrame(*ISR, 0);
  // "1" group (V + I)
  SplitVis->AddFrame(*V,1);
  SplitVis->AddFrame(*I,1);
  */
  LAB->InitializeAnalysis(); 
   ////////////// Jigsaw rules set-up /////////////////
}

CompressedNtuple::~CompressedNtuple() {
  delete LAB;
  delete CM;
  delete S;
  delete ISR;
  delete V;
  delete I;
  delete INV;
  delete InvMass;
  // delete VIS;
  // delete SplitVis;
}

void CompressedNtuple::InitOutputTree(){
  if(m_Tree)
    delete m_Tree;

  string name = string(fChain->GetName());

  name = "CompressedAnalysis";

  m_Tree = (TTree*) new TTree(name.c_str(), name.c_str());
 
  m_Tree->Branch("weight", &m_weight);
  m_Tree->Branch("MET", &m_MET);
  m_Tree->Branch("LepVeto", &m_LepVeto);

  // compressed 
  string posti = "["+to_string(g_N_algo)+"]/I";
  string postf = "["+to_string(g_N_algo)+"]/D";
  m_Tree->Branch("PTISR", m_PTISR, ("PTISR"+postf).c_str());
  m_Tree->Branch("PIoPTISR", m_PIoPTISR, ("PIoPTISR"+postf).c_str());
  m_Tree->Branch("cosS", m_cosS, ("cosS"+postf).c_str());
  m_Tree->Branch("MS", m_MS, ("MS"+postf).c_str());
  m_Tree->Branch("MISR", m_MISR, ("MISR"+postf).c_str());
  m_Tree->Branch("MV", m_MV, ("MV"+postf).c_str());
  m_Tree->Branch("dphiCMV", m_dphiCMV, ("dphiCMV"+postf).c_str());
  m_Tree->Branch("NbV", m_NbV, ("NbV"+posti).c_str());
  m_Tree->Branch("NbISR", m_NbISR, ("NbISR"+posti).c_str());
  m_Tree->Branch("NjV", m_NjV, ("NjV"+posti).c_str());
  m_Tree->Branch("NjISR", m_NjISR, ("NjISR"+posti).c_str());

  // m_Tree->Branch("PTISR", &m_PTISR);
  // m_Tree->Branch("PIoPTISR", &m_PIoPTISR);
  // m_Tree->Branch("cosS", &m_cosS);
  // m_Tree->Branch("MS", &m_MS);
  // m_Tree->Branch("MISR", &m_MISR);
  // m_Tree->Branch("MV", &m_MV);
  // m_Tree->Branch("NbV", &m_NbV);
  // m_Tree->Branch("NbISR", &m_NbISR);
  // m_Tree->Branch("NjV", &m_NjV);
  // m_Tree->Branch("NjISR", &m_NjISR);
  // m_Tree->Branch("dphiCMV", &m_dphiCMV);

}

void CompressedNtuple::FillOutputTree(){

  // Event cleaning, GRL, cosmic mu baseline requirements
  if(!passGRL)     
    return;

  if(!Cleaning) 
    return;

  if(!JetCleaning) 
    return;

  if(!MuonCleaning) 
    return;
  
  if(nMu_cosmic > 0) 
    return;

  if(numVtx <= 0) 
    return;

  // trigger
  // if(!HLT_xe70_tc_lcw) 
  //   return;

  TVector3 ETMiss = GetMET(); 
      
  //  double btag_cut = -0.0436; // 70% working point
  //  double btag_cut = -0.4434; // 77% working point
  //  double btag_cut = -0.7887; // 85% working point
  vector<Jet> Jets; 
  GetJets(Jets, 30., 2.8, -0.4434); 

  // need two jets to play
  if(Jets.size() < 2) 
    return; 

  // lead 2 jets pT > 60
  if(Jets[0].P.Pt() < 60. || Jets[1].P.Pt() < 60.)
    return;

  // make jets 'transverse'
  for(int i = 0; i < int(Jets.size()); i++){
    Jets[i].P.SetPtEtaPhiM(Jets[i].P.Pt(), 0.0,
			   Jets[i].P.Phi(), Jets[i].P.M());
  }

  for(int a = 0; a < g_N_algo; a++){
    vector<Jet> V_JETs;
    vector<Jet> ISR_JETs;
    GetPartition(V_JETs, ISR_JETs, Jets, ETMiss, a);

    m_NjV[a] = 0;
    m_NbV[a] = 0;
    TLorentzVector pV_lab(0.,0.,0.,0.);
    for(int i = 0; i < int(V_JETs.size()); i++){
      m_NjV[a]++;
      pV_lab += V_JETs[i].P;
      if(V_JETs[i].btag)
	m_NbV[a]++;
    }
    m_NbISR[a] = 0;
    m_NjISR[a] = 0;
    TLorentzVector pISR_lab(0.,0.,0.,0.);
    for(int i = 0; i < int(ISR_JETs.size()); i++){
      m_NjISR[a]++;
      pISR_lab += ISR_JETs[i].P;
      if(ISR_JETs[i].btag)
	m_NbISR[a]++;
    }

    if(m_NjV[a] < 1 || m_NjISR[a] < 1){
      m_PTISR[a] = 0.;
      m_PIoPTISR[a] = 0.;
      m_cosS[a] = 0.;
      m_MS[a] = 0.;
      m_MV[a] = 0.;
      m_MISR[a] = 0.;
      m_dphiCMV[a] = 0.;
      continue;
    }

    // analyze event in RestFrames tree
    LAB->ClearEvent();
    
    V->SetLabFrameFourVector(pV_lab);
    ISR->SetLabFrameFourVector(pISR_lab);
    INV->SetLabFrameThreeVector(ETMiss);
    
    if(!LAB->AnalyzeEvent()) cout << "Something went wrong..." << endl;
 
    // Compressed variables from tree

    TVector3 vP_ISR = ISR->GetFourVector(*CM).Vect();
    TVector3 vP_I   = I->GetFourVector(*CM).Vect();

    m_PTISR[a] = vP_ISR.Mag();
    m_PIoPTISR[a] = fabs(vP_I.Dot(vP_ISR.Unit())) / m_PTISR[a];
    m_cosS[a] = S->GetCosDecayAngle();
    m_MS[a] = S->GetMass();
    m_MV[a] = V->GetMass();
    m_MISR[a] = ISR->GetMass();
    m_dphiCMV[a] = CM->GetDeltaPhiBoostVisible();
  }

  /*
  // analyze event in RestFrames tree
  LAB->ClearEvent();
  vector<RFKey> jetID; 
  for(int i = 0; i < int(Jets.size()); i++){
    TLorentzVector jet = Jets[i].P;
    // transverse view of jet 4-vectors
    jet.SetPtEtaPhiM(jet.Pt(),0.0,jet.Phi(),jet.M());
    jetID.push_back(VIS->AddLabFrameFourVector(jet));
  }
  INV->SetLabFrameThreeVector(ETMiss);
  if(!LAB->AnalyzeEvent()) cout << "Something went wrong..." << endl;
 
  // Compressed variables from tree
  m_NjV = VIS->GetNElementsInFrame(*V);
  m_NjISR = VIS->GetNElementsInFrame(*ISR);
  m_NbV = 0;
  m_NbISR = 0;

  // need at least one jet associated with MET-side of event
  if(m_NjV < 1)
    return;

  // count b-jets in each half of the event
  int Nj = jetID.size();
  for(int i = 0; i < Nj; i++){
    if(Jets[i].btag){
      if(VIS->GetFrame(jetID[i]) == *ISR){ // ISR group
	m_NbISR++;
      } else {                             // sparticle group
	m_NbV++;
      }
    }
  }

  TVector3 vP_ISR = ISR->GetFourVector(*CM).Vect();
  TVector3 vP_I   = I->GetFourVector(*CM).Vect();

  m_PTISR = vP_ISR.Mag();
  m_PIoPTISR = fabs(vP_I.Dot(vP_ISR.Unit())) / m_PTISR;
  m_cosS = S->GetCosDecayAngle();
  m_MS = S->GetMass();
  m_MV = V->GetMass();
  m_MISR = ISR->GetMass();
  m_dphiCMV = CM->GetDeltaPhiBoostVisible();
  */

  m_MET = ETMiss.Pt();
  m_LepVeto = (nEl_baseline+nMu_baseline < 1);
  m_weight = GetEventWeight();

  if(m_Tree)
    m_Tree->Fill();
}
