#include "CompressedHiggsinoNtupleMultiTree.hh"

using namespace RestFrames;

CompressedHiggsinoNtupleMultiTree::CompressedHiggsinoNtupleMultiTree(TTree* tree)
  : NtupleBase<HiggsinoBase>(tree)
{
  // RestFrames stuff

  // combinatoric (transverse) tree
  // for jet assignment
  LAB_comb = new LabRecoFrame("LAB_comb","LAB");
  CM_comb  = new DecayRecoFrame("CM_comb","CM");
  S_comb   = new DecayRecoFrame("S_comb","S");
  ISR_comb = new VisibleRecoFrame("ISR_comb","ISR");
  J_comb   = new VisibleRecoFrame("J_comb","Jets");
  L_comb   = new VisibleRecoFrame("L_comb","#it{l}'s");
  I_comb   = new InvisibleRecoFrame("I_comb","Inv");

  LAB_comb->SetChildFrame(*CM_comb);
  CM_comb->AddChildFrame(*ISR_comb);
  CM_comb->AddChildFrame(*S_comb);
  S_comb->AddChildFrame(*L_comb);
  S_comb->AddChildFrame(*J_comb);
  S_comb->AddChildFrame(*I_comb);

  LAB_comb->InitializeTree(); 

  // 2L+NJ tree (Z->ll + W/Z->qq)
  LAB_2LNJ = new LabRecoFrame("LAB_2LNJ","LAB");
  CM_2LNJ  = new DecayRecoFrame("CM_2LNJ","CM");
  S_2LNJ   = new DecayRecoFrame("S_2LNJ","S");
  ISR_2LNJ = new VisibleRecoFrame("ISR_2LNJ","ISR");
  Ca_2LNJ  = new DecayRecoFrame("Ca_2LNJ","C_{a}");  
  Z_2LNJ   = new DecayRecoFrame("Z_2LNJ","Z");
  L1_2LNJ  = new VisibleRecoFrame("L1_2LNJ","#it{l}_{1}");
  L2_2LNJ  = new VisibleRecoFrame("L2_2LNJ","#it{l}_{2}");
  Cb_2LNJ  = new DecayRecoFrame("Cb_2LNJ","C_{b}");
  JSA_2LNJ = new SelfAssemblingRecoFrame("JSA_2L2J", "J");
  J_2LNJ   = new VisibleRecoFrame("J_2L2J","Jets");
  Ia_2LNJ  = new InvisibleRecoFrame("Ia_2LNJ","I_{a}");
  Ib_2LNJ  = new InvisibleRecoFrame("Ib_2LNJ","I_{b}");

  LAB_2LNJ->SetChildFrame(*CM_2LNJ);
  CM_2LNJ->AddChildFrame(*ISR_2LNJ);
  CM_2LNJ->AddChildFrame(*S_2LNJ);
  S_2LNJ->AddChildFrame(*Ca_2LNJ);
  S_2LNJ->AddChildFrame(*Cb_2LNJ);
  Ca_2LNJ->AddChildFrame(*Z_2LNJ);
  Ca_2LNJ->AddChildFrame(*Ia_2LNJ);
  Cb_2LNJ->AddChildFrame(*JSA_2LNJ);
  Cb_2LNJ->AddChildFrame(*Ib_2LNJ);
  Z_2LNJ->AddChildFrame(*L1_2LNJ);
  Z_2LNJ->AddChildFrame(*L2_2LNJ);
  JSA_2LNJ->AddChildFrame(*J_2LNJ);

  LAB_2LNJ->InitializeTree(); 

  // 1L+1L tree (Z/W->l + Z/W->l)
  LAB_1L1L = new LabRecoFrame("LAB_1L1L","LAB");
  CM_1L1L  = new DecayRecoFrame("CM_1L1L","CM");
  S_1L1L   = new DecayRecoFrame("S_1L1L","S");
  ISR_1L1L = new VisibleRecoFrame("ISR_1L1L","ISR");
  Ca_1L1L  = new DecayRecoFrame("Ca_1L1L","C_{a}");  
  La_1L1L  = new VisibleRecoFrame("La_1L1L","#it{l}_{a}");
  Cb_1L1L  = new DecayRecoFrame("Ca_1L1L","C_{b}");  
  Lb_1L1L  = new VisibleRecoFrame("Lb_1L1L","#it{l}_{b}");
  Ia_1L1L  = new InvisibleRecoFrame("Ia_1L1L","I_{a}");
  Ib_1L1L  = new InvisibleRecoFrame("Ia_1L1L","I_{b}");

  LAB_1L1L->SetChildFrame(*CM_1L1L);
  CM_1L1L->AddChildFrame(*ISR_1L1L);
  CM_1L1L->AddChildFrame(*S_1L1L);
  S_1L1L->AddChildFrame(*Ca_1L1L);
  S_1L1L->AddChildFrame(*Cb_1L1L);
  Ca_1L1L->AddChildFrame(*La_1L1L);
  Ca_1L1L->AddChildFrame(*Ia_1L1L);
  Cb_1L1L->AddChildFrame(*Lb_1L1L);
  Cb_1L1L->AddChildFrame(*Ib_1L1L);

  LAB_1L1L->InitializeTree(); 

  // 2L+1L tree (Z->ll + Z/W->l)
  LAB_2L1L = new LabRecoFrame("LAB_2L1L","LAB");
  CM_2L1L  = new DecayRecoFrame("CM_2L1L","CM");
  S_2L1L   = new DecayRecoFrame("S_2L1L","S");
  ISR_2L1L = new VisibleRecoFrame("ISR_2L1L","ISR");
  Ca_2L1L  = new DecayRecoFrame("Ca_2L1L","C_{a}");
  Z_2L1L   = new DecayRecoFrame("Z_2L1L","Z");  
  L1_2L1L  = new VisibleRecoFrame("L1_2L1L","#it{l}_{1}");
  L2_2L1L  = new VisibleRecoFrame("L2_2L1L","#it{l}_{2}");
  Cb_2L1L  = new DecayRecoFrame("Cb_2L1L","C_{b}");  
  Lb_2L1L  = new VisibleRecoFrame("Lb_2L1L","#it{l}_{b}");
  Ia_2L1L  = new InvisibleRecoFrame("Ia_2L1L","I_{a}");
  Ib_2L1L  = new InvisibleRecoFrame("Ia_2L1L","I_{b}");

  LAB_2L1L->SetChildFrame(*CM_2L1L);
  CM_2L1L->AddChildFrame(*ISR_2L1L);
  CM_2L1L->AddChildFrame(*S_2L1L);
  S_2L1L->AddChildFrame(*Ca_2L1L);
  S_2L1L->AddChildFrame(*Cb_2L1L);
  Ca_2L1L->AddChildFrame(*Z_2L1L);
  Ca_2L1L->AddChildFrame(*Ia_2L1L);
  Z_2L1L->AddChildFrame(*L1_2L1L);
  Z_2L1L->AddChildFrame(*L2_2L1L);
  Cb_2L1L->AddChildFrame(*Lb_2L1L);
  Cb_2L1L->AddChildFrame(*Ib_2L1L);

  LAB_2L1L->InitializeTree(); 

  ////////////// Jigsaw rules set-up /////////////////

  // combinatoric (transverse) tree
  // for jet assignment
  INV_comb = new InvisibleGroup("INV_comb","Invisible System");
  INV_comb->AddFrame(*I_comb);
  
  InvMass_comb = new SetMassInvJigsaw("InvMass_comb", "Invisible system mass Jigsaw");
  INV_comb->AddJigsaw(*InvMass_comb);
  
  JETS_comb = new CombinatoricGroup("JETS_comb","Jets System");
  JETS_comb->AddFrame(*ISR_comb);
  JETS_comb->SetNElementsForFrame(*ISR_comb, 1);
  JETS_comb->AddFrame(*J_comb);
  JETS_comb->SetNElementsForFrame(*J_comb, 0);
  
  SplitJETS_comb = new MinMassesCombJigsaw("SplitJETS_comb", "Minimize M_{ISR} and M_{S} Jigsaw");
  JETS_comb->AddJigsaw(*SplitJETS_comb);
  SplitJETS_comb->AddCombFrame(*ISR_comb, 0);
  SplitJETS_comb->AddCombFrame(*J_comb, 1);
  SplitJETS_comb->AddObjectFrame(*ISR_comb,0);
  SplitJETS_comb->AddObjectFrame(*S_comb,1);

  if(!LAB_comb->InitializeAnalysis()){
    cout << "Problem initializing \"comb\" analysis" << endl;
  }

  // 2L+NJ tree (Z->ll + W/Z->qq)
  INV_2LNJ = new InvisibleGroup("INV_2LNJ","Invisible System");
  INV_2LNJ->AddFrame(*Ia_2LNJ);
  INV_2LNJ->AddFrame(*Ib_2LNJ);
  
  InvMass_2LNJ = new SetMassInvJigsaw("InvMass_2LNJ", "Invisible system mass Jigsaw");
  INV_2LNJ->AddJigsaw(*InvMass_2LNJ);
  InvRapidity_2LNJ = new SetRapidityInvJigsaw("InvRapidity_2LNJ", "Set inv. system rapidity");
  INV_2LNJ->AddJigsaw(*InvRapidity_2LNJ);
  InvRapidity_2LNJ->AddVisibleFrames(S_2LNJ->GetListVisibleFrames());
  SplitINV_2LNJ = new ContraBoostInvJigsaw("SplitINV_2LNJ", "INV -> I_{a}+ I_{b} jigsaw");
  INV_2LNJ->AddJigsaw(*SplitINV_2LNJ);
  SplitINV_2LNJ->AddVisibleFrames(Ca_2LNJ->GetListVisibleFrames(), 0);
  SplitINV_2LNJ->AddVisibleFrames(Cb_2LNJ->GetListVisibleFrames(), 1);
  SplitINV_2LNJ->AddInvisibleFrame(*Ia_2LNJ, 0);
  SplitINV_2LNJ->AddInvisibleFrame(*Ib_2LNJ, 1);
  
  JETS_2LNJ = new CombinatoricGroup("JETS_comb","Jets System");
  JETS_2LNJ->AddFrame(*J_2LNJ);
  JETS_2LNJ->SetNElementsForFrame(*J_2LNJ, 0);

  if(!LAB_2LNJ->InitializeAnalysis()){
    cout << "Problem initializing \"2LNJ\" analysis" << endl;
  }

  // 1L+1L tree (Z/W->l + Z/W->l)
  INV_1L1L = new InvisibleGroup("INV_1L1L","Invisible System");
  INV_1L1L->AddFrame(*Ia_1L1L);
  INV_1L1L->AddFrame(*Ib_1L1L);
  
  InvMass_1L1L = new SetMassInvJigsaw("InvMass_1L1L", "Invisible system mass Jigsaw");
  INV_1L1L->AddJigsaw(*InvMass_1L1L);
  InvRapidity_1L1L = new SetRapidityInvJigsaw("InvRapidity_1L1L", "Set inv. system rapidity");
  INV_1L1L->AddJigsaw(*InvRapidity_1L1L);
  InvRapidity_1L1L->AddVisibleFrames(S_1L1L->GetListVisibleFrames());
  SplitINV_1L1L = new ContraBoostInvJigsaw("SplitINV_1L1L", "INV -> I_{a}+ I_{b} jigsaw");
  INV_1L1L->AddJigsaw(*SplitINV_1L1L);
  SplitINV_1L1L->AddVisibleFrames(Ca_1L1L->GetListVisibleFrames(), 0);
  SplitINV_1L1L->AddVisibleFrames(Cb_1L1L->GetListVisibleFrames(), 1);
  SplitINV_1L1L->AddInvisibleFrame(*Ia_1L1L, 0);
  SplitINV_1L1L->AddInvisibleFrame(*Ib_1L1L, 1);

  if(!LAB_1L1L->InitializeAnalysis()){
    cout << "Problem initializing \"1L1L\" analysis" << endl;
  }
  
  // 2L+1L tree (Z->ll + Z/W->l)
  INV_2L1L = new InvisibleGroup("INV_2L1L","Invisible System");
  INV_2L1L->AddFrame(*Ia_2L1L);
  INV_2L1L->AddFrame(*Ib_2L1L);
  
  InvMass_2L1L = new SetMassInvJigsaw("InvMass_2L1L", "Invisible system mass Jigsaw");
  INV_2L1L->AddJigsaw(*InvMass_2L1L);
  InvRapidity_2L1L = new SetRapidityInvJigsaw("InvRapidity_2L1L", "Set inv. system rapidity");
  INV_2L1L->AddJigsaw(*InvRapidity_2L1L);
  InvRapidity_2L1L->AddVisibleFrames(S_2L1L->GetListVisibleFrames());
  SplitINV_2L1L = new ContraBoostInvJigsaw("SplitINV_2L1L", "INV -> I_{a}+ I_{b} jigsaw");
  INV_2L1L->AddJigsaw(*SplitINV_2L1L);
  SplitINV_2L1L->AddVisibleFrames(Ca_2L1L->GetListVisibleFrames(), 0);
  SplitINV_2L1L->AddVisibleFrames(Cb_2L1L->GetListVisibleFrames(), 1);
  SplitINV_2L1L->AddInvisibleFrame(*Ia_2L1L, 0);
  SplitINV_2L1L->AddInvisibleFrame(*Ib_2L1L, 1);

  if(!LAB_2L1L->InitializeAnalysis()){
    cout << "Problem initializing \"2L1L\" analysis" << endl;
  }

  ////////////// Jigsaw rules set-up /////////////////
}

CompressedHiggsinoNtupleMultiTree::~CompressedHiggsinoNtupleMultiTree() {
  // combinatoric (transverse) tree
  // for jet assignment
  /*
  delete LAB_comb;
  delete CM_comb;
  delete S_comb;
  delete ISR_comb;
  delete J_comb;
  delete L_comb;
  delete I_comb;
  delete INV_comb;
  delete InvMass_comb;
  delete JETS_comb;
  delete SplitJETS_comb;

  // 2L+NJ tree (Z->ll + W/Z->qq)
  delete LAB_2LNJ;
  delete CM_2LNJ;
  delete S_2LNJ;
  delete ISR_2LNJ;
  delete Ca_2LNJ;  
  delete Z_2LNJ;
  delete L1_2LNJ;
  delete L2_2LNJ;
  delete Cb_2LNJ;
  delete JSA_2LNJ;
  delete J_2LNJ;
  delete Ia_2LNJ;
  delete Ib_2LNJ;
  delete INV_2LNJ;
  delete InvMass_2LNJ;
  delete InvRapidity_2LNJ;
  delete SplitINV_2LNJ;
  delete JETS_2LNJ;

  // 1L+1L tree (Z/W->l + Z/W->l)
  delete LAB_1L1L;
  delete CM_1L1L;
  delete S_1L1L;
  delete ISR_1L1L;
  delete Ca_1L1L;  
  delete La_1L1L;
  delete Cb_1L1L;  
  delete Lb_1L1L;
  delete Ia_1L1L;
  delete Ib_1L1L;
  delete INV_1L1L;
  delete InvMass_1L1L;
  delete InvRapidity_1L1L;
  delete SplitINV_1L1L;

  // 2L+1L tree (Z->ll + Z/W->l)
  delete LAB_2L1L;
  delete CM_2L1L;
  delete S_2L1L;
  delete ISR_2L1L;
  delete Ca_2L1L;
  delete Z_2L1L;  
  delete L1_2L1L;
  delete L2_2L1L;
  delete Cb_2L1L;  
  delete Lb_2L1L;
  delete Ia_2L1L;
  delete Ib_2L1L;
  delete INV_2L1L;
  delete InvMass_2L1L;
  delete InvRapidity_2L1L;
  delete SplitINV_2L1L;
  */
}

void CompressedHiggsinoNtupleMultiTree::InitOutputTree(){

  if(m_Tree)
    delete m_Tree;

  string name = string(fChain->GetName());

  name = "CompressedAnalysis";

  m_Tree = (TTree*) new TTree(name.c_str(), name.c_str());

   m_Tree->Branch("weight", &m_weight);
  
  m_Tree->Branch("MET", &m_MET);
  m_Tree->Branch("TrkMET", &m_TrkMET);
  m_Tree->Branch("HLT_xe70", &m_HLT_xe70);
  m_Tree->Branch("dphiMin1", &m_dphiMin1);
  m_Tree->Branch("dphiMin2", &m_dphiMin2);
  m_Tree->Branch("dphiMin3", &m_dphiMin3);
  m_Tree->Branch("dphiMinAll", &m_dphiMinAll);
  
  m_Tree->Branch("pT_1jet", &m_pT_1jet);
  m_Tree->Branch("pT_2jet", &m_pT_2jet);
  m_Tree->Branch("pT_3jet", &m_pT_3jet);
  m_Tree->Branch("pT_4jet", &m_pT_4jet);

  // pre-computed lepton variables
  m_Tree->Branch("nEl", &m_nEl);
  m_Tree->Branch("nMu", &m_nMu);
  m_Tree->Branch("MT2W", &m_MT2W);
  m_Tree->Branch("MT2Top", &m_MT2Top);
  m_Tree->Branch("pT_1lep", &m_pT_1lep);
  m_Tree->Branch("id_1lep", &m_id_1lep);
  m_Tree->Branch("pT_2lep", &m_pT_2lep);
  m_Tree->Branch("id_2lep", &m_id_2lep);
  m_Tree->Branch("pT_3lep", &m_pT_3lep);
  m_Tree->Branch("id_3lep", &m_id_3lep);

  // jets from comb tree
  m_Tree->Branch("pTjS1", &m_pTjS1);
  m_Tree->Branch("pTjS2", &m_pTjS2);
  m_Tree->Branch("pTjS3", &m_pTjS3);
  m_Tree->Branch("pTjS4", &m_pTjS4);
  m_Tree->Branch("NjS", &m_NjS);
  m_Tree->Branch("NjISR", &m_NjISR);

  // which tree are we using for event?
  m_Tree->Branch("Is_2LNJ", &m_Is_2LNJ);
  m_Tree->Branch("Is_1L1L", &m_Is_1L1L);
  m_Tree->Branch("Is_2L1L", &m_Is_2L1L);
  
  // compressed tree variables
  // commone to all analysis trees
  m_Tree->Branch("PTCM", &m_PTCM);
  m_Tree->Branch("PTISR", &m_PTISR);
  m_Tree->Branch("RISR", &m_RISR);
  m_Tree->Branch("cosCM", &m_cosCM);
  m_Tree->Branch("cosS", &m_cosS);
  m_Tree->Branch("MISR", &m_MISR);
  m_Tree->Branch("dphiCMI", &m_dphiCMI);
  m_Tree->Branch("dphiSI", &m_dphiSI);
  m_Tree->Branch("dphiISRI", &m_dphiISRI);

  m_Tree->Branch("HN2S", &m_HN2S);
  m_Tree->Branch("H11S", &m_H11S);
  m_Tree->Branch("HN1Ca", &m_HN1Ca);
  m_Tree->Branch("HN1Cb", &m_HN1Cb);
  m_Tree->Branch("H11Ca", &m_H11Ca);
  m_Tree->Branch("H11Cb", &m_H11Cb);
  m_Tree->Branch("cosC", &m_cosC);

  m_Tree->Branch("MZ", &m_MZ);
  m_Tree->Branch("MJ", &m_MJ);
  m_Tree->Branch("cosZ", &m_cosZ);
  m_Tree->Branch("cosJ", &m_cosJ);

}

void CompressedHiggsinoNtupleMultiTree::FillOutputTree(){
  // preselection

  if (lep_pT->at(0) <= 10.0 || lep_pT->at(1) <= 4.0 )
    return;

  // really need this?
  if (bjet_n != 0)
    return;

  // commented out b/c it kills the current samples
  // can apply offline
  // if (MET < 200)
  //   return;

  // if (!HLT_xe70)
  //   return;

  TVector3 ETMiss = GetMET(); 
      
  vector<Jet> Jets; 
  GetJets(Jets, 30., 2.8, -1);

  // Need one jet to play
  if (Jets.size() < 1) 
    return;

  vector<TLorentzVector> Leptons;
  vector<int> LepIDs;
  GetLeptons(Leptons, LepIDs, 4.); 

  vector<TLorentzVector> Muons; 
  GetMuons(Muons); 
  
  vector<TLorentzVector> Elecs; 
  GetElectrons(Elecs);

  // need two objects to play - should
  // be satisfied by previous requirements
  if(Jets.size() + Muons.size() + Elecs.size() < 2) 
    return; 

  m_weight = GetEventWeight();
  
  // MET-related observables
  m_TrkMET = TrackMET;
  m_MET = ETMiss.Pt();
  m_dphiMin1   = DeltaPhiMin(Jets, ETMiss, 1);
  m_dphiMin2   = DeltaPhiMin(Jets, ETMiss, 2);
  m_dphiMin3   = DeltaPhiMin(Jets, ETMiss, 3);
  m_dphiMinAll = DeltaPhiMin(Jets, ETMiss);
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

  m_nEl = el_n;
  m_nMu = mu_n;
  m_MT2W  = MT2W;
  m_MT2Top  = MT2Top;
  
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

  // first - analyze jet combinatoric tree
  // (regardless of later tree)
  LAB_comb->ClearEvent();
  
  vector<RFKey> jetID; 
  for(int i = 0; i < int(Jets.size()); i++){
    TLorentzVector jet = Jets[i].P;
    // transverse view of jet 4-vectors
    jet.SetPtEtaPhiM(jet.Pt(),0.0,jet.Phi(),jet.M());
    jetID.push_back(JETS_comb->AddLabFrameFourVector(jet));
  }

  TLorentzVector lepSys(0.,0.,0.,0.);
  for(int i = 0; i < int(Leptons.size()); i++){
    TLorentzVector lep1;
    // transverse view of mu 4-vectors
    lep1.SetPtEtaPhiM(Leptons[i].Pt(),0.0,Leptons[i].Phi(),Leptons[i].M());
    lepSys = lepSys + lep1;
  }  
  L_comb->SetLabFrameFourVector(lepSys);

  INV_comb->SetLabFrameThreeVector(ETMiss);
  if(!LAB_comb->AnalyzeEvent())
    cout << "Something went wrong with \"comb\" tree event analysis" << endl;

  // Jet counting from comb tree
  m_NjS   = 0;
  m_NjISR = 0;
  m_pTjS1 = 0.;
  m_pTjS2 = 0.;
  m_pTjS3 = 0.;
  m_pTjS4 = 0.;
  // assuming pT ordered jets
  for(int i = 0; i < int(Jets.size()); i++){
    if(JETS_comb->GetFrame(jetID[i]) == *J_comb){ // sparticle group
      m_NjS++;
      if(m_NjS == 1)
	m_pTjS1 = Jets[i].P.Pt();
      if(m_NjS == 2)
	m_pTjS2 = Jets[i].P.Pt();
      if(m_NjS == 3)
	m_pTjS3 = Jets[i].P.Pt();
      if(m_NjS == 4)
	m_pTjS4 = Jets[i].P.Pt();
    } else {
      m_NjISR++;
    }
  }

  // figure out which tree to use
  m_Is_2LNJ = false;
  m_Is_1L1L = false;
  m_Is_2L1L = false;
  int NL = Leptons.size();
  // only analyze these events for now
  if(NL < 2 || NL > 3)
    return;

  if(NL == 2){
    // SS and/or OF leptons
    if(LepIDs[0]+LepIDs[1] != 0){
      m_Is_1L1L = true;
    } else{
      // 2LNJ
      if(m_NjS > 0){
	//	m_Is_2LNJ = true;
	m_Is_2LNJ = false; // need to fix first
      }
    }
  }
  if(NL == 3){
    // at least 1 OS/SF pair
    if(LepIDs[0]+LepIDs[1] == 0 ||
       LepIDs[0]+LepIDs[2] == 0 ||
       LepIDs[1]+LepIDs[2] == 0){
      m_Is_2L1L = true;
    }
  }
  
  // 2LNJ analysis
  if(m_Is_2LNJ){
    LAB_2LNJ->ClearEvent();

    // put jets in their place
    int NJ = jetID.size();
    TLorentzVector vISR(0.,0.,0.,0.);
    for(int i = 0; i < NJ; i++){
      if(JETS_comb->GetFrame(jetID[i]) == *S_comb){
	JETS_2LNJ->AddLabFrameFourVector(Jets[i].P);
      } else {
	vISR += Jets[i].P;
      }
    }

    ISR_2LNJ->SetLabFrameFourVector(vISR);
    
    // put leptons in their place
    L1_2LNJ->SetLabFrameFourVector(Leptons[0]);
    L2_2LNJ->SetLabFrameFourVector(Leptons[1]);

    INV_2LNJ->SetLabFrameThreeVector(ETMiss);
    
    if(!LAB_2LNJ->AnalyzeEvent())
      cout << "Something went wrong with \"2LNJ\" tree event analysis" << endl;
  }

  // 1L1L analysis
  if(m_Is_1L1L){
    LAB_1L1L->ClearEvent();

    // put jets in their place
    int NJ = jetID.size();
    TLorentzVector vISR(0.,0.,0.,0.);
    for(int i = 0; i < NJ; i++){
      vISR += Jets[i].P;
    }

    ISR_1L1L->SetLabFrameFourVector(vISR);
    
    // put leptons in their place
    La_1L1L->SetLabFrameFourVector(Leptons[0]);
    Lb_1L1L->SetLabFrameFourVector(Leptons[1]);

    INV_1L1L->SetLabFrameThreeVector(ETMiss);
    
    if(!LAB_1L1L->AnalyzeEvent())
      cout << "Something went wrong with \"1L1L\" tree event analysis" << endl;
  }

  // 2L1L analysis
  if(m_Is_2L1L){
    LAB_2L1L->ClearEvent();

    // put jets in their place
    int NJ = jetID.size();
    TLorentzVector vISR(0.,0.,0.,0.);
    for(int i = 0; i < NJ; i++){
      vISR += Jets[i].P;
    }

    ISR_2L1L->SetLabFrameFourVector(vISR);
    
    // put leptons in their place
    // find min mass SF/OS pair
    pair<int,int> iSFOS;
    double        mSFOS = -1.;
    for(int i = 0; i < 2; i++){
      for(int j = i+1; j < 3; j++){
	if(LepIDs[i]+LepIDs[j] == 0){
	  if(mSFOS < -1. ||
	     (Leptons[i]+Leptons[j]).M() < mSFOS){
	    mSFOS = (Leptons[i]+Leptons[j]).M();
	    iSFOS.first  = i;
	    iSFOS.second = j;
	  }
	}
      }
    }
    
    for(int i = 0; i < 3; i++){
      if(i == iSFOS.first)
	L1_2L1L->SetLabFrameFourVector(Leptons[i]);
      if(i == iSFOS.second)
	L2_2L1L->SetLabFrameFourVector(Leptons[i]);
      if(i != iSFOS.first && i != iSFOS.second)
	Lb_2L1L->SetLabFrameFourVector(Leptons[i]);
    }

    INV_2L1L->SetLabFrameThreeVector(ETMiss);
    
    if(!LAB_2L1L->AnalyzeEvent())
      cout << "Something went wrong with \"2L1L\" tree event analysis" << endl;
  }

  // calculate analysis observables
  
  // common to analysis trees
  m_PTCM = 0.;
  
  m_PTISR = 0.;
  m_RISR = 0.;
  m_cosCM = 0.;
  m_cosS = 0.;
  m_MISR = 0.;
  m_dphiCMI = 0.;
  m_dphiSI  = 0.;
  m_dphiISRI = 0.;

  m_HN2S = 0.;
  m_H11S = 0.;
  m_HN1Ca = 0.;
  m_HN1Cb = 0.;
  m_H11Ca = 0.;
  m_H11Cb = 0.;
  m_cosC = 0.;

  m_MZ = 0.;
  m_MJ = 0.;
  m_cosZ = 0.;
  m_cosJ = 0.;

  // no tree satisfied? Bounce
  if(!m_Is_2LNJ && !m_Is_1L1L && !m_Is_2L1L)
    return;

  TVector3 vP_ISR;
  TVector3 vP_I;
  
  if(m_Is_2LNJ){
    m_PTCM = CM_2LNJ->GetFourVector().Pt();

    vP_ISR  = ISR_2LNJ->GetFourVector(*CM_2LNJ).Vect();
    vP_I    = (*Ia_2LNJ+*Ib_2LNJ).GetFourVector(*CM_2LNJ).Vect();
   
    m_cosCM = CM_2LNJ->GetCosDecayAngle();
    m_cosS  = S_2LNJ->GetCosDecayAngle();
    m_MISR = ISR_2LNJ->GetCosDecayAngle();
    m_dphiCMI = acos(-1.)-fabs(CM_2LNJ->GetDeltaPhiBoostVisible());
    m_dphiSI  = acos(-1.)-fabs(S_2LNJ->GetDeltaPhiBoostVisible());

    m_HN2S = Z_2LNJ->GetFourVector(*S_2LNJ).E() +
      J_2LNJ->GetFourVector(*S_2LNJ).E() +
      Ia_2LNJ->GetFourVector(*S_2LNJ).P() +
      Ib_2LNJ->GetFourVector(*S_2LNJ).P();
    m_H11S = 2.*(*Ia_2LNJ+*Ib_2LNJ).GetFourVector(*S_2LNJ).P();
    m_HN1Ca = Z_2LNJ->GetFourVector(*Ca_2LNJ).E()+
      Ia_2LNJ->GetFourVector(*Ca_2LNJ).P();
    m_HN1Cb = J_2LNJ->GetFourVector(*Cb_2LNJ).E()+
      Ib_2LNJ->GetFourVector(*Cb_2LNJ).P();
    m_H11Ca = 2.*Ia_2LNJ->GetFourVector(*Ca_2LNJ).P();
    m_H11Cb = 2.*Ib_2LNJ->GetFourVector(*Cb_2LNJ).P();
    m_cosC  = Ca_2LNJ->GetCosDecayAngle();
    
    m_MZ = Z_2LNJ->GetMass();
    m_MJ = J_2LNJ->GetMass();
    m_cosZ = Z_2LNJ->GetCosDecayAngle();
    if(m_NjS > 1)
      m_cosJ = JSA_2LNJ->GetCosDecayAngle();
  }

  if(m_Is_1L1L){
    m_PTCM = CM_1L1L->GetFourVector().Pt();

    vP_ISR  = ISR_1L1L->GetFourVector(*CM_1L1L).Vect();
    vP_I    = (*Ia_1L1L+*Ib_1L1L).GetFourVector(*CM_1L1L).Vect();
   
    m_cosCM = CM_1L1L->GetCosDecayAngle();
    m_cosS  = S_1L1L->GetCosDecayAngle();
    m_MISR = ISR_1L1L->GetCosDecayAngle();
    m_dphiCMI = acos(-1.)-fabs(CM_1L1L->GetDeltaPhiBoostVisible());
    m_dphiSI  = acos(-1.)-fabs(S_1L1L->GetDeltaPhiBoostVisible());

    m_HN2S = La_1L1L->GetFourVector(*S_1L1L).E() +
      Lb_1L1L->GetFourVector(*S_1L1L).E() +
      Ia_1L1L->GetFourVector(*S_1L1L).P() +
      Ib_1L1L->GetFourVector(*S_1L1L).P();
    m_H11S = 2.*(*Ia_1L1L+*Ib_1L1L).GetFourVector(*S_1L1L).P();
    m_HN1Ca = La_1L1L->GetFourVector(*Ca_1L1L).E()+
      Ia_1L1L->GetFourVector(*Ca_1L1L).P();
    m_HN1Cb = Lb_1L1L->GetFourVector(*Cb_1L1L).E()+
      Ib_1L1L->GetFourVector(*Cb_1L1L).P();
    m_H11Ca = 2.*Ia_1L1L->GetFourVector(*Ca_1L1L).P();
    m_H11Cb = 2.*Ib_1L1L->GetFourVector(*Cb_1L1L).P();
    m_cosC  = Ca_1L1L->GetCosDecayAngle();
  }

  if(m_Is_2L1L){
    m_PTCM = CM_2L1L->GetFourVector().Pt();

    vP_ISR  = ISR_2L1L->GetFourVector(*CM_2L1L).Vect();
    vP_I    = (*Ia_2L1L+*Ib_2L1L).GetFourVector(*CM_2L1L).Vect();
   
    m_cosCM = CM_2L1L->GetCosDecayAngle();
    m_cosS  = S_2L1L->GetCosDecayAngle();
    m_MISR = ISR_2L1L->GetCosDecayAngle();
    m_dphiCMI = acos(-1.)-fabs(CM_2L1L->GetDeltaPhiBoostVisible());
    m_dphiSI  = acos(-1.)-fabs(S_2L1L->GetDeltaPhiBoostVisible());
    
     m_HN2S = Z_2L1L->GetFourVector(*S_2L1L).E() +
      Lb_2L1L->GetFourVector(*S_2L1L).E() +
      Ia_2L1L->GetFourVector(*S_2L1L).P() +
      Ib_2L1L->GetFourVector(*S_2L1L).P();
    m_H11S = 2.*(*Ia_2L1L+*Ib_2L1L).GetFourVector(*S_2L1L).P();
    m_HN1Ca = Z_2L1L->GetFourVector(*Ca_2L1L).E()+
      Ia_2L1L->GetFourVector(*Ca_2L1L).P();
    m_HN1Cb = Lb_2L1L->GetFourVector(*Cb_2L1L).E()+
      Ib_2L1L->GetFourVector(*Cb_2L1L).P();
    m_H11Ca = 2.*Ia_2L1L->GetFourVector(*Ca_2L1L).P();
    m_H11Cb = 2.*Ib_2L1L->GetFourVector(*Cb_2L1L).P();
    m_cosC  = Ca_2L1L->GetCosDecayAngle();
    
    m_MZ = Z_2L1L->GetMass();
    m_cosZ = Z_2L1L->GetCosDecayAngle();
  }

  vP_ISR.SetZ(0.);
  vP_I.SetZ(0.);
  
  m_PTISR =  vP_ISR.Mag();
  m_RISR  = -vP_I.Dot(vP_ISR.Unit()) / m_PTISR;
  m_dphiISRI = fabs(vP_ISR.DeltaPhi(vP_I));

  if(m_Tree)
    m_Tree->Fill();
}
