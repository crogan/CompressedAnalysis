#include "CompressedHiggsinoNtuple3L.hh"

using namespace RestFrames;

CompressedHiggsinoNtuple3L::CompressedHiggsinoNtuple3L(TTree* tree)
  : NtupleBase<HiggsinoBase>(tree)
{
  // RestFrames stuff

  ////////////// Tree set-up /////////////////
  LAB = new LabRecoFrame("LAB","lab");
  CM = new DecayRecoFrame("CM","CM");
  S = new DecayRecoFrame("S","S");
  ISR = new VisibleRecoFrame("ISR","ISR");
  L = new VisibleRecoFrame("L","Lep");
  I = new InvisibleRecoFrame("I","Inv");

  LAB->SetChildFrame(*CM);
  CM->AddChildFrame(*ISR);
  CM->AddChildFrame(*S);
  S->AddChildFrame(*I);
  S->AddChildFrame(*L);

  LAB->InitializeTree(); 

  ////////////// Tree set-up /////////////////

  ////////////// Jigsaw rules set-up /////////////////
  INV = new InvisibleGroup("INV","Invisible System");
  INV->AddFrame(*I);

  // set the invisible system mass to zero
  InvMass = new SetMassInvJigsaw("InvMass", "Invisible system mass Jigsaw");
  INV->AddJigsaw(*InvMass);

  // set the invisible system rapidity to that of visible
  InvRapidity = new SetRapidityInvJigsaw("InvRapidity", "Invisible system rapidity Jigsaw");
  INV->AddJigsaw(*InvRapidity);
  InvRapidity->AddVisibleFrames(S->GetListVisibleFrames());
  
  LAB->InitializeAnalysis(); 
   ////////////// Jigsaw rules set-up /////////////////
}

CompressedHiggsinoNtuple3L::~CompressedHiggsinoNtuple3L() {
  delete LAB;
  delete CM;
  delete S;
  delete ISR;
  delete I;
  delete L;
  delete InvMass;
  delete InvRapidity;
}

void CompressedHiggsinoNtuple3L::InitOutputTree(){

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
  m_Tree->Branch("pTjISR1", &m_pTjISR1);
  m_Tree->Branch("pTjISR2", &m_pTjISR2);
  m_Tree->Branch("NjISR", &m_NjISR);

}

void CompressedHiggsinoNtuple3L::FillOutputTree(){
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
  m_HLT_xe70 = HLT_xe70;

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
  TLorentzVector jetSys;
  jetSys.SetPtEtaPhiM(0.0,0.0,0.0,0.0);
  for(int i = 0; i < int(Jets.size()); i++){
    TLorentzVector jet = Jets[i].P;
    // full view of jet 4-vectors
    jet.SetPtEtaPhiM(jet.Pt(),jet.Eta(),jet.Phi(),jet.M());
    jetSys = jetSys + jet;
    m_HT += jet.Pt();
  }
  ISR->SetLabFrameFourVector(jetSys);

  TLorentzVector lepSys;
  lepSys.SetPtEtaPhiM(0.0,0.0,0.0,0.0);
  for(int i = 0; i < int(Leptons.size()); i++){
    TLorentzVector lep1;
    // full view of lep 4-vectors
    lep1.SetPtEtaPhiM(Leptons[i].Pt(),Leptons[i].Eta(),Leptons[i].Phi(),Leptons[i].M());
    lepSys = lepSys + lep1;
  }  
  L->SetLabFrameFourVector(lepSys);

  INV->SetLabFrameThreeVector(ETMiss);
  if(!LAB->AnalyzeEvent()) cout << "Something went wrong..." << endl;

  // Compressed variables from tree
  m_NjISR = 0.;
  m_pTjISR1 = 0.;
  m_pTjISR2 = 0.;
  // assuming pT ordered jets
  for(int i = 0; i < int(Jets.size()); i++){
    m_NjISR++;
    if (m_NjISR == 1)
      m_pTjISR1 = Jets[i].P.Pt();
    if (m_NjISR == 2)
      m_pTjISR2 = Jets[i].P.Pt();
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
    m_MISR = ISR->GetMass();
    m_dphiCMI = acos(-1.)-fabs(CM->GetDeltaPhiBoostVisible());
    m_dphiISRI = fabs(vP_ISR.DeltaPhi(vP_I));

  if(m_Tree)
    m_Tree->Fill();
}
