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

  VIS = new CombinatoricGroup("VIS","Visible Objects");
  VIS->AddFrame(*ISR);
  VIS->SetNElementsForFrame(*ISR,1,false);
  VIS->AddFrame(*V);
  VIS->SetNElementsForFrame(*V,0,false);

  // set the invisible system mass to zero
  InvMass = new SetMassInvJigsaw("InvMass", "Invisible system mass Jigsaw");
  INV->AddJigsaw(*InvMass);

  // define the rule for partitioning objects between "ISR" and "V"
  SplitVis = new MinMassesCombJigsaw("SplitVis","Minimize M_{ISR} and M_{S} Jigsaw");
  VIS->AddJigsaw(*SplitVis);
  // "0" group (ISR)
  SplitVis->AddFrame(*ISR, 0);
  // "1" group (V + I)
  SplitVis->AddFrame(*V,1);
  SplitVis->AddFrame(*I,1);

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
  delete VIS;

  delete InvMass;
  delete SplitVis;
}

void CompressedNtuple::InitOutputTree(){
  if(m_Tree)
    delete m_Tree;

  string name = string(fChain->GetName());

  name = "CompressedAnalysis";

  m_Tree = (TTree*) new TTree(name.c_str(), name.c_str());
 
  m_Tree->Branch("weight", &m_weight);
  m_Tree->Branch("m_MET", &m_MET);

  // compressed 
  m_Tree->Branch("PTISR", &m_PTISR);
  m_Tree->Branch("PIoPTISR", &m_PIoPTISR);
  m_Tree->Branch("cosS", &m_cosS);
  m_Tree->Branch("MS", &m_MS);
  m_Tree->Branch("MISR", &m_MISR);
  m_Tree->Branch("MV", &m_MV);
  m_Tree->Branch("NbV", &m_NbV);
  m_Tree->Branch("NbISR", &m_NbISR);
  m_Tree->Branch("NjV", &m_NjV);
  m_Tree->Branch("NjISR", &m_NjISR);
  m_Tree->Branch("dphiCMV", &m_dphiCMV);

}

void CompressedNtuple::FillOutputTree(){

  TVector3 ETMiss = GetMET(); 
      
  //  double btag_cut = -0.0436; // 70% working point
  //  double btag_cut = -0.4434; // 77% working point
  //  double btag_cut = -0.7887; // 85% working point
  vector<Jet> Jets; 
  GetJets(Jets, 30., -0.7887); 

  // need two jets to play
  if(Jets.size() < 2) 
    return; 

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

  m_MET = ETMiss.Pt();

  m_weight = GetEventWeight();

  if(m_Tree)
    m_Tree->Fill();
}
