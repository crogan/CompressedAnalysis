#include "CompressedHiggsinoNtuple2L.hh"

using namespace RestFrames;

CompressedHiggsinoNtuple2L::CompressedHiggsinoNtuple2L(TTree* tree)
  : NtupleBase<HiggsinoBase>(tree)
{
  // RestFrames stuff

  ////////////// Tree set-up /////////////////
  LAB = new LabRecoFrame("LAB","lab");
  CM = new DecayRecoFrame("CM","CM");
  S = new DecayRecoFrame("S","S");
  ISR = new VisibleRecoFrame("ISR","ISR");
  V = new VisibleRecoFrame("V","Vis");
  L = new VisibleRecoFrame("L","Lep");
  I = new InvisibleRecoFrame("I","Inv");

  LAB->SetChildFrame(*CM);
  CM->AddChildFrame(*ISR);
  CM->AddChildFrame(*S);
  S->AddChildFrame(*V);
  S->AddChildFrame(*I);
  S->AddChildFrame(*L);

  LAB->InitializeTree(); 

  ////////////// Tree set-up /////////////////

  ////////////// Jigsaw rules set-up /////////////////
  INV = new InvisibleGroup("INV","Invisible System");
  INV->AddFrame(*I);

  // LEP = new Group("LEP","Leptonic System");
  // LEP->AddFrame(*L);
  
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
  // "1" group (V + I + L)
  SplitVis->AddFrame(*V,1);
  SplitVis->AddFrame(*I,1);
  SplitVis->AddFrame(*L,1);
  
  LAB->InitializeAnalysis(); 
   ////////////// Jigsaw rules set-up /////////////////
}

CompressedHiggsinoNtuple2L::~CompressedHiggsinoNtuple2L() {
  delete LAB;
  delete CM;
  delete S;
  delete ISR;
  delete V;
  delete I;
  delete L;
  delete INV;
  delete InvMass;
  delete VIS;
  delete SplitVis;
}

void CompressedHiggsinoNtuple2L::InitOutputTree(){

  if(m_Tree)
    delete m_Tree;

  string name = string(fChain->GetName());

  name = "CompressedAnalysis";

  m_Tree = (TTree*) new TTree(name.c_str(), name.c_str());
 
  m_Tree->Branch("MET", &m_MET);
  m_Tree->Branch("TrkMET", &m_TrkMET);
  m_Tree->Branch("HLT_xe70", &m_HLT_xe70);
  m_Tree->Branch("is_OS", &m_is_OS);
  
  m_Tree->Branch("pT_1jet", &m_pT_1jet);
  m_Tree->Branch("pT_2jet", &m_pT_2jet);
  m_Tree->Branch("pT_3jet", &m_pT_3jet);
  m_Tree->Branch("pT_4jet", &m_pT_4jet);

  m_Tree->Branch("nEl", &m_nEl);
  m_Tree->Branch("nMu", &m_nMu);
  m_Tree->Branch("MT2W", &m_MT2W);
  m_Tree->Branch("MT2Top", &m_MT2Top);
  m_Tree->Branch("mll", &m_mll);
  m_Tree->Branch("pT_1lep", &m_pT_1lep);
  m_Tree->Branch("id_1lep", &m_id_1lep);
  m_Tree->Branch("pT_2lep", &m_pT_2lep);
  m_Tree->Branch("id_2lep", &m_id_2lep);
  m_Tree->Branch("pT_3lep", &m_pT_3lep);
  m_Tree->Branch("id_3lep", &m_id_3lep);

  m_Tree->Branch("channel", &m_channel);
  
  m_Tree->Branch("weight", &m_weight);
  m_Tree->Branch("HT", &m_HT);
  m_Tree->Branch("dphiMin1", &m_dphiMin1);
  m_Tree->Branch("dphiMin2", &m_dphiMin2);
  m_Tree->Branch("dphiMin3", &m_dphiMin3);
  m_Tree->Branch("dphiMinAll", &m_dphiMinAll);

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
  m_Tree->Branch("mllOS", &m_mllOS);
  m_Tree->Branch("MZ", &m_MZ);
  m_Tree->Branch("dphiCMI", &m_dphiCMI);
  m_Tree->Branch("dphiISRI", &m_dphiISRI);
  m_Tree->Branch("dphiCML1", &m_dphiCML1);
  m_Tree->Branch("dphiCML2", &m_dphiCML2);
  m_Tree->Branch("dphiSL1", &m_dphiSL1);
  m_Tree->Branch("dphiSL2", &m_dphiSL2);
  m_Tree->Branch("cosIL1", &m_cosIL1);
  m_Tree->Branch("cosIL2", &m_cosIL2);
  m_Tree->Branch("cosLLOS", &m_cosLLOS);
  m_Tree->Branch("dphiLLOS", &m_dphiLLOS);
  m_Tree->Branch("pTjV1", &m_pTjV1);
  m_Tree->Branch("pTjV2", &m_pTjV2);
  m_Tree->Branch("pTjV3", &m_pTjV3);
  m_Tree->Branch("pTjV4", &m_pTjV4);
  m_Tree->Branch("pTjV5", &m_pTjV5);
  m_Tree->Branch("pTjV6", &m_pTjV6);
  m_Tree->Branch("NjV", &m_NjV);
  m_Tree->Branch("NjISR", &m_NjISR);

}

void CompressedHiggsinoNtuple2L::FillOutputTree(){
  // preselection

  // if (is_OS != 1)
  //   return;

  if (lep_pT->at(0) <= 10.0 || lep_pT->at(1) <= 4.0 )
    return;

  if (bjet_n != 0)
    return;

  // commented out b/c it kills the current samples
  // if (MET < 200)
  //   return;

  // if (!HLT_xe70)
  //   return;

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
  GetJets(Jets, 30., 2.8, -1);

  if (Jets.size() < 1) //REQUIRE THIS IF WE ARE FORCING LEPTONS
    return;

  vector<TLorentzVector> Leptons;
  vector<int> LepIDs;
  GetLeptons(Leptons,LepIDs); 

  vector<TLorentzVector> Muons; 
  GetMuons(Muons); 
  
  vector<TLorentzVector> Elecs; 
  GetElectrons(Elecs);

  // need two objects to play
  if(Jets.size() + Muons.size() + Elecs.size() < 2) 
    return; 

  m_TrkMET = TrackMET;
  m_is_OS = is_OS;
  //  m_dphi_MET_TrkMET = dPhi_met_trackmet;
  //  m_HLT_xe70_tc_lcw = (HLT_xe70_tc_lcw > 0);

  if (Jets.size() > 0)
    m_pT_1jet = jet_pT->at(0);
  else
    m_pT_1jet = 0.;
  if (Jets.size() > 1)
    m_pT_2jet = jet_pT->at(1);
  else
    m_pT_2jet = 0.;
  if (Jets.size() > 2)
    m_pT_3jet = jet_pT->at(2);
  else
    m_pT_3jet = 0.;
  if (Jets.size() > 3)
    m_pT_4jet = jet_pT->at(3);
  else
    m_pT_4jet = 0.;
  // m_mj0_12 = mj0_12;
  // m_mj1_12 = mj1_12;

  m_channel = channel;
  // m_LepVeto = (nEl_baseline+nMu_baseline < 1);
  // m_TauVeto = (passtauveto > 0);
  m_weight = GetEventWeight();

  m_nEl = el_n;
  m_nMu = mu_n;
  m_MT2W  = MT2W;
  m_MT2Top  = MT2Top;
  m_mll = mll;
  
  if (lep_n > 0) {
    m_pT_1lep = lep_pT->at(0);
    m_id_1lep = lep_pdgId->at(0);
  }
  else {
    m_pT_1lep = 0.;
    m_id_1lep = 0;
  }
  if (lep_n > 1) {
    m_pT_2lep = lep_pT->at(1);
    m_id_2lep = lep_pdgId->at(1);
  }
  else {
    m_pT_2lep = 0.;
    m_id_2lep = 0;
  }
  if (lep_n > 2) {
    m_pT_3lep = lep_pT->at(2);
    m_id_3lep = lep_pdgId->at(2);
  }
  else {
    m_pT_3lep = 0.;
    m_id_3lep = 0;
  }

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

  //  vector<RFKey> lepID;
  TLorentzVector lepSys;
  lepSys.SetPtEtaPhiM(0.0,0.0,0.0,0.0);
  for(int i = 0; i < int(Leptons.size()); i++){
    TLorentzVector lep1;
    // transverse view of mu 4-vectors
    lep1.SetPtEtaPhiM(Leptons[i].Pt(),0.0,Leptons[i].Phi(),Leptons[i].M());
    lepSys = lepSys + lep1;
  }  
  L->SetLabFrameFourVector(lepSys);
  //  L2->SetLabFrameFourVector(Leptons[1]);
  //L->SetMass(lepSys.M());

  INV->SetLabFrameThreeVector(ETMiss);
  if(!LAB->AnalyzeEvent()) cout << "Something went wrong..." << endl;

  // Compressed variables from tree
  m_NjV = 0;
  m_NjISR = 0;
  m_pTjV1 = 0.;
  m_pTjV2 = 0.;
  m_pTjV3 = 0.;
  m_pTjV4 = 0.;
  m_pTjV5 = 0.;
  m_pTjV6 = 0.;
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
      
    } else {
      m_NjISR++;
    }
  }


  //quick and dirty way of looping through the muons to correspond to lepton pdgIDs
  vector<int> MuonIDs;
  vector<int> ElecIDs;

  for (int i = 0; i < lep_n; i++) {
    if (fabs(lep_pdgId->at(i)) == 13)
      MuonIDs.push_back(lep_pdgId->at(i));
    else
      ElecIDs.push_back(lep_pdgId->at(i));
  }
  
  m_MW1 = 0;
  m_MW2 = 0;
  m_mllOS = 0;
  m_MZ = 0;
  m_dphiCML1 = 0;
  m_dphiCML2 = 0;
  m_dphiSL1 = 0;
  m_dphiSL2 = 0;
  m_cosIL1 = 0;
  m_cosIL2 = 0;
  m_cosLLOS = 0;
  m_dphiLLOS = 0;

  bool foundOS = false;

  // assuming pT ordered leptons
  for(int i = 0; i < int(Leptons.size()); i++){
    for(int j = 0; j < int(Leptons.size()); j++){
      if (!foundOS) {
	if (LepIDs[i] == -LepIDs[j]) {
	  foundOS = true;
	  TLorentzVector lep1;
	  TLorentzVector lep2;
	  lep1.SetPtEtaPhiM(Leptons[i].Pt(), Leptons[i].Eta(),
			    Leptons[i].Phi(), Leptons[i].M());
	  lep2.SetPtEtaPhiM(Leptons[j].Pt(), Leptons[i].Eta(),
			    Leptons[j].Phi(), Leptons[j].M());
	  m_mllOS = (lep1 + lep2).M();
	  lep1.Clear();
	  lep2.Clear();
	  lep1.SetPtEtaPhiM(Leptons[i].Pt(), 0.0,
			    Leptons[i].Phi(), max(0.,Leptons[i].M()));
	  lep2.SetPtEtaPhiM(Leptons[j].Pt(), 0.0,
			    Leptons[j].Phi(), max(0.,Leptons[j].M()));
	  TLorentzVector vL1_CM   = CM->GetFourVector(lep1);
	  TLorentzVector vL2_CM   = CM->GetFourVector(lep2);
	  TLorentzVector vL1_S    = S->GetFourVector(lep1);
	  TLorentzVector vL2_S    = S->GetFourVector(lep2);
	  TLorentzVector vL1_L    = L->GetFourVector(lep1);
	  TLorentzVector vL2_L    = L->GetFourVector(lep2);
	  TLorentzVector vCM_lab = CM->GetFourVector();
	  TLorentzVector vS_CM   = S->GetFourVector(*CM);
	  TLorentzVector vI_S    = I->GetFourVector(*S);
	  TLorentzVector vL_S    = L->GetFourVector(*S);
	  m_MZ = (vL1_S + vL2_S).M();
	  if (fabs(vL1_S.Phi()) < TMath::Pi())
	    m_dphiLLOS = fabs(vL1_L.DeltaPhi(vL2_L));
	  m_cosLLOS = -vL_S.Vect().Unit().Dot(vL1_L.Vect().Unit());

	  //L1
	  m_dphiCML1 = acos( vL1_CM.Vect().Unit().Dot(vCM_lab.Vect().Unit()) );
	  m_dphiSL1 = acos( vL1_S.Vect().Unit().Dot(vS_CM.Vect().Unit()) );
	  m_MW1 = (vL1_S + vI_S).M();
	  TVector3 boostLI = (vL1_S + vI_S).BoostVector();
	  vL1_S.Boost(-boostLI); 
	  m_cosIL1 = -boostLI.Unit().Dot(vL1_S.Vect().Unit());

	  //L2
	  boostLI.Clear();
	  m_dphiCML2 = acos( vL2_CM.Vect().Unit().Dot(vCM_lab.Vect().Unit()) );
	  m_dphiSL2 = acos( vL2_S.Vect().Unit().Dot(vS_CM.Vect().Unit()) );
	  m_MW2 = (vL2_S + vI_S).M();
	  boostLI = (vL2_S + vI_S).BoostVector();
	  vL2_S.Boost(-boostLI); 
	  m_cosIL2 = -boostLI.Unit().Dot(vL2_S.Vect().Unit());
	}
      }
    }
  }
  
  // need at least one jet or lepton associated with sparticle-side of event
//  if(m_NjV+m_NlV < 1){
    m_PTISR = 0.;
    m_PTCM = 0.;
    m_RISR = 0.;
    m_cosS = 0.;
    m_MS = 0.;
    m_MV = 0.;
    m_MISR = 0.;
    m_dphiCMI = 0.;
    m_dphiISRI = 0.;
//  } else {

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
    // if(m_NbV+m_NbISR != NbV+NbISR){
    //   cout << m_NbV << " " << NbV << endl;
    // }
    // m_pTbV1 = pTbV1;
    // m_pTbV2 = pTsbV2;
//  }

  if(m_Tree)
    m_Tree->Fill();
}
