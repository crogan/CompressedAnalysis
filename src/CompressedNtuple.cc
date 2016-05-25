#include "CompressedNtuple.hh"

using namespace RestFrames;

CompressedNtuple::CompressedNtuple(TTree* tree)
  : NtupleBase<SussexBase>(tree)
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
  delete InvMass;
  delete VIS;
  delete SplitVis;
}

void CompressedNtuple::InitOutputTree(){
  if(m_Tree)
    delete m_Tree;

  string name = string(fChain->GetName());

  name = "CompressedAnalysis";

  m_Tree = (TTree*) new TTree(name.c_str(), name.c_str());
 
  m_Tree->Branch("MET", &m_MET);
  m_Tree->Branch("TrkMET", &m_TrkMET);
  m_Tree->Branch("dphi_MET_TrkMET", &m_dphi_MET_TrkMET);
  m_Tree->Branch("HLT_xe70_tc_lcw", &m_HLT_xe70_tc_lcw);

  m_Tree->Branch("pT_1jet", &m_pT_1jet);
  m_Tree->Branch("pT_2jet", &m_pT_2jet);
  m_Tree->Branch("pT_3jet", &m_pT_3jet);
  m_Tree->Branch("pT_4jet", &m_pT_4jet);
  m_Tree->Branch("mj0_12", &m_mj0_12);
  m_Tree->Branch("mj1_12", &m_mj1_12);

  m_Tree->Branch("LepVeto", &m_LepVeto);
  m_Tree->Branch("TauVeto", &m_TauVeto);

  m_Tree->Branch("nEl", &m_nEl);
  m_Tree->Branch("nMu", &m_nMu);
  m_Tree->Branch("MT", &m_MT);
  m_Tree->Branch("pT_1lep", &m_pT_1lep);
  m_Tree->Branch("pT_2lep", &m_pT_2lep);

  m_Tree->Branch("weight", &m_weight);
  m_Tree->Branch("HT", &m_HT);
  m_Tree->Branch("dphiMin1", &m_dphiMin1);
  m_Tree->Branch("dphiMin2", &m_dphiMin2);
  m_Tree->Branch("dphiMin3", &m_dphiMin3);
  m_Tree->Branch("dphiMinAll", &m_dphiMinAll);
  m_Tree->Branch("Mbb", &m_Mbb);
  m_Tree->Branch("dphiMinbl1", &m_dphiMinbl1);
  m_Tree->Branch("dphiMinbl2", &m_dphiMinbl2);
  m_Tree->Branch("dRMinbl1", &m_dRMinbl1);
  m_Tree->Branch("dRMinbl2", &m_dRMinbl2);

  // compressed tree variables
  m_Tree->Branch("PTISR", &m_PTISR);
  m_Tree->Branch("PTCM", &m_PTCM);
  m_Tree->Branch("RISR", &m_RISR);
  m_Tree->Branch("cosS", &m_cosS);
  m_Tree->Branch("MS", &m_MS);
  m_Tree->Branch("MISR", &m_MISR);
  m_Tree->Branch("MV", &m_MV);
  m_Tree->Branch("MW1", &m_MW1);
  m_Tree->Branch("MW2", &m_MW2);
  m_Tree->Branch("dphiCMI", &m_dphiCMI);
  m_Tree->Branch("dphiISRI", &m_dphiISRI);
  m_Tree->Branch("dphiCML1", &m_dphiCML1);
  m_Tree->Branch("dphiCML2", &m_dphiCML2);
  m_Tree->Branch("cosIL1", &m_cosIL1);
  m_Tree->Branch("cosIL2", &m_cosIL2);
  m_Tree->Branch("pTjV1", &m_pTjV1);
  m_Tree->Branch("pTjV2", &m_pTjV2);
  m_Tree->Branch("pTjV3", &m_pTjV3);
  m_Tree->Branch("pTjV4", &m_pTjV4);
  m_Tree->Branch("pTjV5", &m_pTjV5);
  m_Tree->Branch("pTjV6", &m_pTjV6);
  m_Tree->Branch("pTbV1", &m_pTbV1);
  m_Tree->Branch("pTbV2", &m_pTbV2);
  m_Tree->Branch("NbV", &m_NbV);
  m_Tree->Branch("NbISR", &m_NbISR);
  m_Tree->Branch("NjV", &m_NjV);
  m_Tree->Branch("NjISR", &m_NjISR);
  m_Tree->Branch("NlV", &m_NlV);
  m_Tree->Branch("NlISR", &m_NlISR);

}

void CompressedNtuple::FillOutputTree(){

  // MET filter
  if (!(truthMETfilter < 200 || RunNumber == 407012 || 
	RunNumber == 407019 || RunNumber == 407021) ) 
    return;

  // Event cleaning, GRL, cosmic mu baseline requirements
  if(!passGRL)     
    return;

  if(!Cleaning) 
    return;

  if(!JetCleaning) 
    return;

  if(!MuonCleaning) 
    return;
  
  // cosmic mu rejection
  if(nMu_cosmic > 0) 
    return;

  // vertex requirement
  if(numVtx <= 0) 
    return;

  // trigger
  if(!HLT_xe70_tc_lcw) 
    return;

  TVector3 ETMiss = GetMET(); 
      
  //  MV2c20
  //  double btag_cut = -0.0436; // 70% working point
  //  double btag_cut = -0.4434; // 77% working point
  //  double btag_cut = -0.7887; // 85% working point
  //  MV2c10
  //  double btag_cut = 0.8244; // 70% working point
  //  double btag_cut = 0.6459; // 77% working point
  //  double btag_cut = 0.1758; // 85% working point
  vector<Jet> Jets; 
  GetJets(Jets, 20., 2.8, -0.4434); 
  //GetJets(Jets, 20., 2.8, 0.6459); 

  vector<TLorentzVector> Muons; 
  GetMuons(Muons); 

  vector<TLorentzVector> Elecs; 
  GetElectrons(Elecs); 

  // need two jets to play
  if(Jets.size() < 2) 
    return; 

  m_TrkMET = eT_miss_track;
  m_dphi_MET_TrkMET = dPhi_met_trackmet;
  m_HLT_xe70_tc_lcw = (HLT_xe70_tc_lcw > 0);

  m_pT_1jet = pT_1jet;
  m_pT_2jet = pT_2jet;
  m_pT_3jet = pT_3jet;
  m_pT_4jet = pT_4jet;

  m_mj0_12 = mj0_12;
  m_mj1_12 = mj1_12;

  m_LepVeto = (nEl_baseline+nMu_baseline < 1);
  m_TauVeto = (passtauveto > 0);
  m_weight = GetEventWeight();

  m_nEl = nEl;
  m_nMu = nMu;
  m_MT  = MT;
  m_pT_1lep = pT_1lep;
  m_pT_2lep = pT_2lep;

  // other observables
  m_MET = ETMiss.Pt();
  m_dphiMin1   = DeltaPhiMin(Jets, ETMiss, 1);
  m_dphiMin2   = DeltaPhiMin(Jets, ETMiss, 2);
  m_dphiMin3   = DeltaPhiMin(Jets, ETMiss, 3);
  m_dphiMinAll = DeltaPhiMin(Jets, ETMiss);

  // analyze event in RestFrames tree
  LAB->ClearEvent();

  m_HT = 0.;
  vector<RFKey> jetID; 
  for(int i = 0; i < int(Jets.size()); i++){
    TLorentzVector jet = Jets[i].P;
    // transverse view of jet 4-vectors
    jet.SetPtEtaPhiM(jet.Pt(),0.0,jet.Phi(),jet.M());
    jetID.push_back(VIS->AddLabFrameFourVector(jet));
    m_HT += jet.Pt();
  }
  vector<RFKey> muID; 
  for(int i = 0; i < int(Muons.size()); i++){
    TLorentzVector mu = Muons[i];
    // transverse view of mu 4-vectors
    mu.SetPtEtaPhiM(mu.Pt(),0.0,mu.Phi(),mu.M());
    muID.push_back(VIS->AddLabFrameFourVector(mu));
  }
  vector<RFKey> elID; 
  for(int i = 0; i < int(Elecs.size()); i++){
    TLorentzVector el = Elecs[i];
    // transverse view of mu 4-vectors
    el.SetPtEtaPhiM(el.Pt(),0.0,el.Phi(),el.M());
    elID.push_back(VIS->AddLabFrameFourVector(el));
  }
  INV->SetLabFrameThreeVector(ETMiss);
  if(!LAB->AnalyzeEvent()) cout << "Something went wrong..." << endl;

  // Compressed variables from tree
  m_NjV = 0;
  m_NbV = 0;
  m_NjISR = 0;
  m_NbISR = 0;
  m_pTjV1 = 0.;
  m_pTjV2 = 0.;
  m_pTjV3 = 0.;
  m_pTjV4 = 0.;
  m_pTjV5 = 0.;
  m_pTjV6 = 0.;
  m_pTbV1 = 0.;
  m_pTbV2 = 0.;
  vector<TLorentzVector> Btags;
  // assuming pT ordered jets
  for(int i = 0; i < int(Jets.size()); i++){
    if(VIS->GetFrame(jetID[i]) == *V){ // sparticle group
      m_NjV++;
      if(m_NjV == 1)
	m_pTjV1 = Jets[i].P.Pt();
      if(m_NjV == 2)
	m_pTjV2 = Jets[i].P.Pt();
      if(m_NjV == 3)
	m_pTjV3 = Jets[i].P.Pt();
      if(m_NjV == 4)
	m_pTjV4 = Jets[i].P.Pt();
      if(m_NjV == 5)
	m_pTjV5 = Jets[i].P.Pt();
      if(m_NjV == 6)
	m_pTjV6 = Jets[i].P.Pt();
      if(Jets[i].btag){
	m_NbV++;
	Btags.push_back(Jets[i].P);
	if(m_NbV == 1)
	  m_pTbV1 = Jets[i].P.Pt();
	if(m_NbV == 2)
	  m_pTbV2 = Jets[i].P.Pt();
      }
    } else {
      m_NjISR++;
      if(Jets[i].btag){
	m_NbISR++;
	Btags.push_back(Jets[i].P);
      }
    }
  }

  if(int(Btags.size() >= 2))
    m_Mbb = (Btags[0]+Btags[1]).M();
  else
    m_Mbb = 0.;

  m_NlV = 0;
  m_NlISR = 0;
  m_MW1 = 0;
  m_MW2 = 0;
  m_dphiCML1 = 0;
  m_dphiCML2 = 0;
  m_cosIL1 = 0;
  m_cosIL2 = 0;
  m_dRMinbl1 = -1.;
  m_dRMinbl2 = -1.;
  m_dphiMinbl1 = -1.;
  m_dphiMinbl2 = -1.;
  // assuming pT ordered muons
  for(int i = 0; i < int(Muons.size()); i++){
    if(VIS->GetFrame(muID[i]) == *V) // sparticle group
      m_NlV++;
    else
      m_NlISR++;

    TLorentzVector lep;
    lep.SetPtEtaPhiM(Muons[i].Pt(), 0.0,
		     Muons[i].Phi(), max(0.,Muons[i].M()));
    TLorentzVector vL_CM = CM->GetFourVector(lep);
    TLorentzVector vCM_lab = CM->GetFourVector();
    TLorentzVector vI_CM = I->GetFourVector(*CM);
    if(m_NlV+m_NlISR == 1){
      m_dphiCML1 = acos( vL_CM.Vect().Unit().Dot(vCM_lab.Vect().Unit()) );
      m_MW1 = (vL_CM + vI_CM).M();
      TVector3 boostLI = (vL_CM + vI_CM).BoostVector();
      vL_CM.Boost(-boostLI); 
      m_cosIL1 = -boostLI.Unit().Dot(vL_CM.Vect().Unit());
      for(int j = 0; j < int(Btags.size()); j++)
	if(m_dRMinbl1 > Muons[i].DeltaR(Btags[j]) || m_dRMinbl1 < 0.)
	  m_dRMinbl1 = Muons[i].DeltaR(Btags[j]);
      for(int j = 0; j < int(Btags.size()); j++)
	if(m_dphiMinbl1 > fabs(Muons[i].DeltaR(Btags[j])) || m_dphiMinbl1 < 0.)
	  m_dphiMinbl1 = fabs(Muons[i].DeltaR(Btags[j]));
    }
    if(m_NlV+m_NlISR == 2){
      m_dphiCML2 = acos( vL_CM.Vect().Unit().Dot(vCM_lab.Vect().Unit()) );
      m_MW2 = (vL_CM + vI_CM).M();
      TVector3 boostLI = (vL_CM + vI_CM).BoostVector();
      vL_CM.Boost(-boostLI); 
      m_cosIL2 = -boostLI.Unit().Dot(vL_CM.Vect().Unit());
      for(int j = 0; j < int(Btags.size()); j++)
	if(m_dRMinbl2 > Muons[i].DeltaR(Btags[j]) || m_dRMinbl2 < 0.)
	  m_dRMinbl2 = Muons[i].DeltaR(Btags[j]);
      for(int j = 0; j < int(Btags.size()); j++)
	if(m_dphiMinbl2 > fabs(Muons[i].DeltaR(Btags[j])) || m_dphiMinbl2 < 0.)
	  m_dphiMinbl2 = fabs(Muons[i].DeltaR(Btags[j]));
    }
  }
  // assuming pT ordered electrons
  for(int i = 0; i < int(Elecs.size()); i++){
    if(VIS->GetFrame(elID[i]) == *V) // sparticle group
      m_NlV++;
    else
      m_NlISR++;

    TLorentzVector lep;
    lep.SetPtEtaPhiM(Elecs[i].Pt(), 0.0,
		     Elecs[i].Phi(), max(0.,Elecs[i].M()));
    TLorentzVector vL_CM = CM->GetFourVector(lep);
    TLorentzVector vCM_lab = CM->GetFourVector();
    TLorentzVector vI_CM = I->GetFourVector(*CM);
    if(m_NlV+m_NlISR == 1){
      m_dphiCML1 = acos( vL_CM.Vect().Unit().Dot(vCM_lab.Vect().Unit()) );
      m_MW1 = (vL_CM + vI_CM).M();
      TVector3 boostLI = (vL_CM + vI_CM).BoostVector();
      vL_CM.Boost(-boostLI); 
      m_cosIL1 = -boostLI.Unit().Dot(vL_CM.Vect().Unit());
      for(int j = 0; j < int(Btags.size()); j++)
	if(m_dRMinbl1 > Elecs[i].DeltaR(Btags[j]) || m_dRMinbl1 < 0.)
	  m_dRMinbl1 = Elecs[i].DeltaR(Btags[j]);
      for(int j = 0; j < int(Btags.size()); j++)
	if(m_dphiMinbl1 > fabs(Elecs[i].DeltaR(Btags[j])) || m_dphiMinbl1 < 0.)
	  m_dphiMinbl1 = fabs(Elecs[i].DeltaR(Btags[j]));
    }
    if(m_NlV+m_NlISR == 2){
      m_dphiCML2 = acos( vL_CM.Vect().Unit().Dot(vCM_lab.Vect().Unit()) );
      m_MW2 = (vL_CM + vI_CM).M();
      TVector3 boostLI = (vL_CM + vI_CM).BoostVector();
      vL_CM.Boost(-boostLI); 
      m_cosIL2 = -boostLI.Unit().Dot(vL_CM.Vect().Unit());
      for(int j = 0; j < int(Btags.size()); j++)
	if(m_dRMinbl2 > Elecs[i].DeltaR(Btags[j]) || m_dRMinbl2 < 0.)
	  m_dRMinbl2 = Elecs[i].DeltaR(Btags[j]);
      for(int j = 0; j < int(Btags.size()); j++)
	if(m_dphiMinbl2 > fabs(Elecs[i].DeltaR(Btags[j])) || m_dphiMinbl2 < 0.)
	  m_dphiMinbl2 = fabs(Elecs[i].DeltaR(Btags[j]));
    }
  }
  

  // need at least one jet or lepton associated with sparticle-side of event
  if(m_NjV+m_NlV < 1){
    m_PTISR = 0.;
    m_PTCM = 0.;
    m_RISR = 0.;
    m_cosS = 0.;
    m_MS = 0.;
    m_MV = 0.;
    m_MISR = 0.;
    m_dphiCMI = 0.;
    m_dphiISRI = 0.;
  } else {

    TVector3 vP_ISR = ISR->GetFourVector(*CM).Vect();
    TVector3 vP_I   = I->GetFourVector(*CM).Vect();
    TVector3 vP_CM   = CM->GetFourVector(*LAB).Vect();
  
    m_PTISR = vP_ISR.Mag();
    m_PTCM  = vP_CM.Pt();
    m_RISR = fabs(vP_I.Dot(vP_ISR.Unit())) / m_PTISR;
    m_cosS = S->GetCosDecayAngle();
    m_MS = S->GetMass();
    m_MV = V->GetMass();
    m_MISR = ISR->GetMass();
    m_dphiCMI = acos(-1.)-fabs(CM->GetDeltaPhiBoostVisible());
    m_dphiISRI = fabs(vP_ISR.DeltaPhi(vP_I));

    // SussexBase w/ b-tagging
    if(m_NbV+m_NbISR != NbV+NbISR){
      cout << m_NbV << " " << NbV << endl;
    }
    // m_pTbV1 = pTbV1;
    // m_pTbV2 = pTsbV2;
  }

  if(m_Tree)
    m_Tree->Fill();
}
