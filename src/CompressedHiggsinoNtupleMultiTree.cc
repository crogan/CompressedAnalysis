#include "CompressedHiggsinoNtupleMultiTree.hh"

using namespace RestFrames;

CompressedHiggsinoNtupleMultiTree::CompressedHiggsinoNtupleMultiTree(TTree* tree)
  : NtupleBase<SusySkimHiggsinoBase>(tree)
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

  // 1L+1L tree (Z/W->l + Z/W->l), neutrino ~ lepton
  LAB_1L1Lnu = new LabRecoFrame("LAB_1L1Lnu","LAB");
  CM_1L1Lnu  = new DecayRecoFrame("CM_1L1Lnu","CM");
  S_1L1Lnu   = new DecayRecoFrame("S_1L1Lnu","S");
  ISR_1L1Lnu = new VisibleRecoFrame("ISR_1L1Lnu","ISR");
  Ca_1L1Lnu  = new DecayRecoFrame("Ca_1L1Lnu","C_{a}");  
  Wa_1L1Lnu  = new DecayRecoFrame("Wa_1L1Lnu","W_{a}");  
  La_1L1Lnu  = new VisibleRecoFrame("La_1L1Lnu","#it{l}_{a}");
  Na_1L1Lnu  = new VisibleRecoFrame("Na_1L1Lnu","#nu_{a}");
  Cb_1L1Lnu  = new DecayRecoFrame("Ca_1L1Lnu","C_{b}");  
  Wb_1L1Lnu  = new DecayRecoFrame("Wb_1L1Lnu","W_{b}");
  Lb_1L1Lnu  = new VisibleRecoFrame("Lb_1L1Lnu","#it{l}_{b}");
  Nb_1L1Lnu  = new VisibleRecoFrame("Nb_1L1Lnu","#nu_{b}");
  Ia_1L1Lnu  = new InvisibleRecoFrame("Ia_1L1Lnu","I_{a}");
  Ib_1L1Lnu  = new InvisibleRecoFrame("Ia_1L1Lnu","I_{b}");

  LAB_1L1Lnu->SetChildFrame(*CM_1L1Lnu);
  CM_1L1Lnu->AddChildFrame(*ISR_1L1Lnu);
  CM_1L1Lnu->AddChildFrame(*S_1L1Lnu);
  S_1L1Lnu->AddChildFrame(*Ca_1L1Lnu);
  S_1L1Lnu->AddChildFrame(*Cb_1L1Lnu);
  Ca_1L1Lnu->AddChildFrame(*Wa_1L1Lnu);
  Ca_1L1Lnu->AddChildFrame(*Ia_1L1Lnu);
  Cb_1L1Lnu->AddChildFrame(*Wb_1L1Lnu);
  Cb_1L1Lnu->AddChildFrame(*Ib_1L1Lnu);
  Wa_1L1Lnu->AddChildFrame(*La_1L1Lnu);
  Wa_1L1Lnu->AddChildFrame(*Na_1L1Lnu);
  Wb_1L1Lnu->AddChildFrame(*Lb_1L1Lnu);
  Wb_1L1Lnu->AddChildFrame(*Nb_1L1Lnu);

  LAB_1L1Lnu->InitializeTree(); 

  
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

  // 2L+1L tree (Z->ll + Z/W->l), with neutrino ~ lepton
  LAB_2L1Lnu = new LabRecoFrame("LAB_2L1Lnu","LAB");
  CM_2L1Lnu  = new DecayRecoFrame("CM_2L1Lnu","CM");
  S_2L1Lnu   = new DecayRecoFrame("S_2L1Lnu","S");
  ISR_2L1Lnu = new VisibleRecoFrame("ISR_2L1Lnu","ISR");
  Ca_2L1Lnu  = new DecayRecoFrame("Ca_2L1Lnu","C_{a}");
  Z_2L1Lnu   = new DecayRecoFrame("Z_2L1Lnu","Z");  
  L1_2L1Lnu  = new VisibleRecoFrame("L1_2L1Lnu","#it{l}_{1}");
  L2_2L1Lnu  = new VisibleRecoFrame("L2_2L1Lnu","#it{l}_{2}");
  Cb_2L1Lnu  = new DecayRecoFrame("Cb_2L1Lnu","C_{b}");  
  W_2L1Lnu   = new DecayRecoFrame("W_2L1Lnu","W");  
  Lb_2L1Lnu  = new VisibleRecoFrame("Lb_2L1Lnu","#it{l}_{b}");
  Nb_2L1Lnu  = new VisibleRecoFrame("Nb_2L1Lnu","#it{l}_{b}"); // visible since we will define its 4vector explicitly
  Ia_2L1Lnu  = new InvisibleRecoFrame("Ia_2L1Lnu","I_{a}");
  Ib_2L1Lnu  = new InvisibleRecoFrame("Ia_2L1Lnu","I_{b}");

  LAB_2L1Lnu->SetChildFrame(*CM_2L1Lnu);
  CM_2L1Lnu->AddChildFrame(*ISR_2L1Lnu);
  CM_2L1Lnu->AddChildFrame(*S_2L1Lnu);
  S_2L1Lnu->AddChildFrame(*Ca_2L1Lnu);
  S_2L1Lnu->AddChildFrame(*Cb_2L1Lnu);
  Ca_2L1Lnu->AddChildFrame(*Z_2L1Lnu);
  Ca_2L1Lnu->AddChildFrame(*Ia_2L1Lnu);
  Z_2L1Lnu->AddChildFrame(*L1_2L1Lnu);
  Z_2L1Lnu->AddChildFrame(*L2_2L1Lnu);
  Cb_2L1Lnu->AddChildFrame(*W_2L1Lnu);
  Cb_2L1Lnu->AddChildFrame(*Ib_2L1Lnu);
  W_2L1Lnu->AddChildFrame(*Lb_2L1Lnu);
  W_2L1Lnu->AddChildFrame(*Nb_2L1Lnu);
  LAB_2L1Lnu->InitializeTree(); 

  
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

  // 1L+1L tree (Z/W->l + Z/W->l), with neutrino ~ lepton
  INV_1L1Lnu = new InvisibleGroup("INV_1L1Lnu","Invisible System");
  INV_1L1Lnu->AddFrame(*Ia_1L1Lnu);
  INV_1L1Lnu->AddFrame(*Ib_1L1Lnu);
  
  InvMass_1L1Lnu = new SetMassInvJigsaw("InvMass_1L1Lnu", "Invisible system mass Jigsaw");
  INV_1L1Lnu->AddJigsaw(*InvMass_1L1Lnu);
  InvRapidity_1L1Lnu = new SetRapidityInvJigsaw("InvRapidity_1L1Lnu", "Set inv. system rapidity");
  INV_1L1Lnu->AddJigsaw(*InvRapidity_1L1Lnu);
  InvRapidity_1L1Lnu->AddVisibleFrames(S_1L1Lnu->GetListVisibleFrames());
  SplitINV_1L1Lnu = new ContraBoostInvJigsaw("SplitINV_1L1Lnu", "INV -> I_{a}+ I_{b} jigsaw");
  INV_1L1Lnu->AddJigsaw(*SplitINV_1L1Lnu);
  SplitINV_1L1Lnu->AddVisibleFrames(Ca_1L1Lnu->GetListVisibleFrames(), 0);
  SplitINV_1L1Lnu->AddVisibleFrames(Cb_1L1Lnu->GetListVisibleFrames(), 1);
  SplitINV_1L1Lnu->AddInvisibleFrame(*Ia_1L1Lnu, 0);
  SplitINV_1L1Lnu->AddInvisibleFrame(*Ib_1L1Lnu, 1);

  if(!LAB_1L1Lnu->InitializeAnalysis()){
    cout << "Problem initializing \"1L1Lnu\" analysis" << endl;
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

  // 2L+1L tree (Z->ll + Z/W->l), with neutrino ~ lepton
  INV_2L1Lnu = new InvisibleGroup("INV_2L1Lnu","Invisible System");
  INV_2L1Lnu->AddFrame(*Ia_2L1Lnu);
  INV_2L1Lnu->AddFrame(*Ib_2L1Lnu);
  
  InvMass_2L1Lnu = new SetMassInvJigsaw("InvMass_2L1Lnu", "Invisible system mass Jigsaw");
  INV_2L1Lnu->AddJigsaw(*InvMass_2L1Lnu);
  InvRapidity_2L1Lnu = new SetRapidityInvJigsaw("InvRapidity_2L1Lnu", "Set inv. system rapidity");
  INV_2L1Lnu->AddJigsaw(*InvRapidity_2L1Lnu);
  InvRapidity_2L1Lnu->AddVisibleFrames(S_2L1Lnu->GetListVisibleFrames());
  SplitINV_2L1Lnu = new ContraBoostInvJigsaw("SplitINV_2L1Lnu", "INV -> I_{a}+ I_{b} jigsaw");
  INV_2L1Lnu->AddJigsaw(*SplitINV_2L1Lnu);
  SplitINV_2L1Lnu->AddVisibleFrames(Ca_2L1Lnu->GetListVisibleFrames(), 0);
  SplitINV_2L1Lnu->AddVisibleFrames(Cb_2L1Lnu->GetListVisibleFrames(), 1);
  SplitINV_2L1Lnu->AddInvisibleFrame(*Ia_2L1Lnu, 0);
  SplitINV_2L1Lnu->AddInvisibleFrame(*Ib_2L1Lnu, 1);

  if(!LAB_2L1Lnu->InitializeAnalysis()){
    cout << "Problem initializing \"2L1Lnu\" analysis" << endl;
  }

  ////////////// Jigsaw rules set-up /////////////////
}

CompressedHiggsinoNtupleMultiTree::~CompressedHiggsinoNtupleMultiTree() {
  // combinatoric (transverse) tree
  // for jet assignment
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

  // 1L+1L tree (Z/W->l + Z/W->l), with neutrino ~ lepton
  delete LAB_1L1Lnu;
  delete CM_1L1Lnu;
  delete S_1L1Lnu;
  delete ISR_1L1Lnu;
  delete Ca_1L1Lnu;  
  delete Wa_1L1Lnu;  
  delete La_1L1Lnu;
  delete Na_1L1Lnu;  
  delete Cb_1L1Lnu;  
  delete Wb_1L1Lnu;  
  delete Lb_1L1Lnu;
  delete Nb_1L1Lnu;  
  delete Ia_1L1Lnu;
  delete Ib_1L1Lnu;
  delete INV_1L1Lnu;
  delete InvMass_1L1Lnu;
  delete InvRapidity_1L1Lnu;
  delete SplitINV_1L1Lnu;

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

  // 2L+1L tree (Z->ll + Z/W->l), with neutrino ~ lepton
  delete LAB_2L1Lnu;
  delete CM_2L1Lnu;
  delete S_2L1Lnu;
  delete ISR_2L1Lnu;
  delete Ca_2L1Lnu;
  delete Z_2L1Lnu;  
  delete L1_2L1Lnu;
  delete L2_2L1Lnu;
  delete Cb_2L1Lnu;  
  delete W_2L1Lnu;  
  delete Lb_2L1Lnu;
  delete Nb_2L1Lnu;
  delete Ia_2L1Lnu;
  delete Ib_2L1Lnu;
  delete INV_2L1Lnu;
  delete InvMass_2L1Lnu;
  delete InvRapidity_2L1Lnu;
  delete SplitINV_2L1Lnu;
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
  m_Tree->Branch("nBjet", &m_nBjet);
  m_Tree->Branch("MTW", &m_MTW);
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
  m_Tree->Branch("etajS1", &m_etajS1);
  m_Tree->Branch("etajS2", &m_etajS2);
  m_Tree->Branch("etajS3", &m_etajS3);
  m_Tree->Branch("etajS4", &m_etajS4);
  m_Tree->Branch("NjS", &m_NjS);
  m_Tree->Branch("NjISR", &m_NjISR);

  // which tree are we using for event?
  m_Tree->Branch("Is_1L", &m_Is_1L);
  m_Tree->Branch("Is_2LNJ", &m_Is_2LNJ);
  m_Tree->Branch("Is_1L1L", &m_Is_1L1L);
  m_Tree->Branch("Is_1L1Lnu", &m_Is_1L1Lnu);
  m_Tree->Branch("Is_2L1L", &m_Is_2L1L);
  m_Tree->Branch("Is_2L1Lnu", &m_Is_2L1Lnu);
  
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
  m_Tree->Branch("HN2SR", &m_HN2SR);
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

  //TOGGLE ON AND OFF//
  bool withnu = false; //flag for whether you want the neutrino as a separate frame

  // preselection

  // cout << "BJET VETO" << endl;
  // if (bjet_n != 0) //this is b-jet veto for background samples given by Ben
  //   return;

  TVector3 ETMiss = GetMET(); 
      
  vector<Jet> Jets; 
  //GetJets(Jets, 30., 2.8, -1); //old cuts
  //GetJets(Jets, 20., 2.8, 0.6459); //mc15c
  GetJets(Jets, 30., 2.8, 0.6459); //mc15c

  // Need one jet to play
  if (Jets.size() < 1) 
    return;

  //  b-jet veto for Incl1L samples
  int nBJets = 0;
  for( int i=0; i< int(Jets.size()); i++ ) {
    if ( Jets[i].btag == true ) nBJets++;
  }
  if( nBJets !=0 ) {
    return;
  }
  cout << "Warning! Btag information not used." << endl;
  vector<TLorentzVector> Leptons;
  vector<int> LepIDs;
  GetLeptons(Leptons, LepIDs, 4.);

  // if (Leptons[0].Pt() <= 6.0 || Leptons[1].Pt() <= 4.0 ) 
  //   return;
  //  cout << "NumLeps: " << Leptons.size() << endl;
  if ((Leptons[0].Pt() <= 4.0 || Leptons[1].Pt() <= 4.0 ) && Leptons.size() > 1) { 
    return;
  }
  else if (Leptons.size() == 1 && Leptons[0].Pt() <= 4.0 ) {
    return;
  }
  // if (Leptons[0].Pt() <= 10.0 || Leptons[1].Pt() <= 4.0 ) 
  //   return;

  // need two objects to play - should
  // be satisfied by previous requirements
  if(Jets.size() + Leptons.size() < 2) 
    return; 

  m_weight = GetEventWeight();
  
  // MET-related observables
  //  m_TrkMET = TrackMET;
  m_MET = ETMiss.Pt();
  //  m_dphiMin1   = DeltaPhiMin(Jets, ETMiss, 1);
  //  m_dphiMin2   = DeltaPhiMin(Jets, ETMiss, 2);
  //  m_dphiMin3   = DeltaPhiMin(Jets, ETMiss, 3);
  //  m_dphiMinAll = DeltaPhiMin(Jets, ETMiss);
  //  m_HLT_xe70 = HLT_xe70;

  if (Jets.size() > 0)
    m_pT_1jet = Jets[0].P.Pt(); // for old samples HIGGSINO, this was jet_pT->at(0)
  else
    m_pT_1jet = 0.;
  if (Jets.size() > 1)
    m_pT_2jet = Jets[1].P.Pt();
  else
    m_pT_2jet = 0.;
  if (Jets.size() > 2)
    m_pT_3jet = Jets[2].P.Pt();
  else
    m_pT_3jet = 0.;
  if (Jets.size() > 3)
    m_pT_4jet = Jets[3].P.Pt();
  else
    m_pT_4jet = 0.;

  // m_nEl = el_n;
  // m_nMu = mu_n;

  m_nBjet = nBJet30_MV2c10;
  
  m_MT2W  = mt2leplsp_0;
  // m_MT2Top  = MT2Top;

  
  if (Leptons.size() > 0) {
    m_pT_1lep = Leptons[0].Pt();
    m_id_1lep = LepIDs[0];
  }
  else {
    m_pT_1lep = 0.;
    m_id_1lep = 0;
  }
  if (Leptons.size() > 1) {
    m_pT_2lep = Leptons[1].Pt();
    m_id_2lep = LepIDs[1];
  }
  else {
    m_pT_2lep = 0.;
    m_id_2lep = 0;
  }
  if (Leptons.size() > 2) {
    m_pT_3lep = Leptons[2].Pt();
    m_id_3lep = LepIDs[2];
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
  m_etajS1 = 0.;
  m_etajS2 = 0.;
  m_etajS3 = 0.;
  m_etajS4 = 0.;
  // assuming pT ordered jets
  for(int i = 0; i < int(Jets.size()); i++){
    if(JETS_comb->GetFrame(jetID[i]) == *J_comb){ // sparticle group
      m_NjS++;
      if(m_NjS == 1){
	m_pTjS1 = Jets[i].P.Pt();
	m_etajS1 = Jets[i].P.Eta();
      }
      if(m_NjS == 2){
	m_pTjS2 = Jets[i].P.Pt();
	m_etajS2 = Jets[i].P.Eta();
      }
      if(m_NjS == 3){
	m_pTjS3 = Jets[i].P.Pt();
	m_etajS3 = Jets[i].P.Eta();
      }
      if(m_NjS == 4){
	m_pTjS4 = Jets[i].P.Pt();
	m_etajS4 = Jets[i].P.Eta();
      }
    } else {
      m_NjISR++;
    }
  }

  // figure out which tree to use
  m_Is_1L = false;
  m_Is_2LNJ = false;
  m_Is_1L1L = false;
  m_Is_1L1Lnu = false;
  m_Is_2L1L = false;
  m_Is_2L1Lnu = false;
  int NL = Leptons.size();
  // only analyze these events for now
  if(NL > 3)
    return;
  // if(NL < 2 || NL > 3)
  //   return;

  if(NL == 1)
    m_Is_1L = true;
  if(NL == 2){
    // SS and/or OF leptons
    if(LepIDs[0]+LepIDs[1] != 0){
      if (withnu == false)
	m_Is_1L1L = true;
      else
	m_Is_1L1Lnu = true;
    } else{
      // 2LNJ
      if(m_NjS > 0){
	m_Is_2LNJ = true;
      }
    }
  }
  if(NL == 3){
    // at least 1 OS/SF pair
    if(LepIDs[0]+LepIDs[1] == 0 ||
       LepIDs[0]+LepIDs[2] == 0 ||
       LepIDs[1]+LepIDs[2] == 0){
      if (withnu == false)
	m_Is_2L1L = true;
      else
	m_Is_2L1Lnu = true;
    }
  }
  
  // 2LNJ analysis
  if(m_Is_2LNJ){
    LAB_2LNJ->ClearEvent();

    // put jets in their place
    int NJ = jetID.size();
    TLorentzVector vISR(0.,0.,0.,0.);
    for(int i = 0; i < NJ; i++){
      if(JETS_comb->GetFrame(jetID[i]) == *J_comb){
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

  // 1L1L analysis with neutrino ~ lepton
  if(m_Is_1L1Lnu){
    LAB_1L1Lnu->ClearEvent();

    // put jets in their place
    int NJ = jetID.size();
    TLorentzVector vISR(0.,0.,0.,0.);
    for(int i = 0; i < NJ; i++){
      vISR += Jets[i].P;
    }

    ISR_1L1Lnu->SetLabFrameFourVector(vISR);

    TLorentzVector Nu_a;
    TLorentzVector Nu_b;

    
    // put leptons in their place
    La_1L1Lnu->SetLabFrameFourVector(Leptons[0]);
    Lb_1L1Lnu->SetLabFrameFourVector(Leptons[1]);
    Nu_a.SetPxPyPzE(Leptons[0].Px(),Leptons[0].Py(),Leptons[0].Pz(),Leptons[0].P()); 
    Nu_b.SetPxPyPzE(Leptons[1].Px(),Leptons[1].Py(),Leptons[1].Pz(),Leptons[1].P()); 
    Na_1L1Lnu->SetLabFrameFourVector(Nu_a);
    Nb_1L1Lnu->SetLabFrameFourVector(Nu_b);

    INV_1L1Lnu->SetLabFrameThreeVector(ETMiss-Nu_a.Vect()-Nu_b.Vect());
    
    if(!LAB_1L1Lnu->AnalyzeEvent())
      cout << "Something went wrong with \"1L1Lnu\" tree event analysis" << endl;
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
	  if(mSFOS < 0. ||
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

    // 2L1L with neutrino ~ lepton analysis
  if(m_Is_2L1Lnu){
    LAB_2L1Lnu->ClearEvent();

    // put jets in their place
    int NJ = jetID.size();
    TLorentzVector vISR(0.,0.,0.,0.);
    for(int i = 0; i < NJ; i++){
      vISR += Jets[i].P;
    }

    ISR_2L1Lnu->SetLabFrameFourVector(vISR);
    
    // put leptons in their place
    // find min mass SF/OS pair
    pair<int,int> iSFOS;
    double        mSFOS = -1.;
    for(int i = 0; i < 2; i++){
      for(int j = i+1; j < 3; j++){
	if(LepIDs[i]+LepIDs[j] == 0){
	  if(mSFOS < 0. ||
	     (Leptons[i]+Leptons[j]).M() < mSFOS){
	    mSFOS = (Leptons[i]+Leptons[j]).M();
	    iSFOS.first  = i;
	    iSFOS.second = j;
	  }
	}
      }
    }

    TLorentzVector Nu;
    
    for(int i = 0; i < 3; i++){
      if(i == iSFOS.first)
	L1_2L1Lnu->SetLabFrameFourVector(Leptons[i]);
      if(i == iSFOS.second)
	L2_2L1Lnu->SetLabFrameFourVector(Leptons[i]);
      if(i != iSFOS.first && i != iSFOS.second) { 
	Lb_2L1Lnu->SetLabFrameFourVector(Leptons[i]);
	Nu.SetPxPyPzE(Leptons[i].Px(),Leptons[i].Py(),Leptons[i].Pz(),Leptons[i].P()); 
	Nb_2L1Lnu->SetLabFrameFourVector(Nu);
      }
    }

    INV_2L1Lnu->SetLabFrameThreeVector(ETMiss-Nu.Vect()); // subtract out the "neutrino"
    
    if(!LAB_2L1Lnu->AnalyzeEvent())
      cout << "Something went wrong with \"2L1Lnu\" tree event analysis" << endl;
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
  m_HN2SR = 0.;
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
  if(!m_Is_2LNJ && !m_Is_1L1L && !m_Is_1L1Lnu && !m_Is_2L1L && !m_Is_2L1Lnu && !m_Is_1L)
    return;

  TLorentzVector vP_CM;
  TLorentzVector vP_ISR;
  TLorentzVector vP_I;
  
  if(m_Is_2LNJ){

    vP_CM  = CM_2LNJ->GetFourVector();
    vP_ISR = ISR_2LNJ->GetFourVector();
    vP_I   = (*Ia_2LNJ+*Ib_2LNJ).GetFourVector();
   
    m_cosCM = CM_2LNJ->GetCosDecayAngle();
    m_cosS  = S_2LNJ->GetCosDecayAngle();
    m_MISR = ISR_2LNJ->GetMass();
    m_dphiCMI = acos(-1.)-fabs(CM_2LNJ->GetDeltaPhiBoostVisible());
    m_dphiSI  = acos(-1.)-fabs(S_2LNJ->GetDeltaPhiBoostVisible());

    m_MTW = min( sqrt(2.*(Leptons[0].Pt()*ETMiss.Pt() - Leptons[0].Vect().Dot(ETMiss))),
		 sqrt(2.*(Leptons[1].Pt()*ETMiss.Pt() - Leptons[1].Vect().Dot(ETMiss))) );

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
    
    vP_CM  = CM_1L1L->GetFourVector();
    vP_ISR = ISR_1L1L->GetFourVector();
    vP_I   = (*Ia_1L1L+*Ib_1L1L).GetFourVector();
   
    m_cosCM = CM_1L1L->GetCosDecayAngle();
    m_cosS  = S_1L1L->GetCosDecayAngle();
    m_MISR = ISR_1L1L->GetMass();
    m_dphiCMI = acos(-1.)-fabs(CM_1L1L->GetDeltaPhiBoostVisible());
    m_dphiSI  = acos(-1.)-fabs(S_1L1L->GetDeltaPhiBoostVisible());

    m_MTW = min( sqrt(2.*(Leptons[0].Pt()*ETMiss.Pt() - Leptons[0].Vect().Dot(ETMiss))),
		 sqrt(2.*(Leptons[1].Pt()*ETMiss.Pt() - Leptons[1].Vect().Dot(ETMiss))) );

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

  if(m_Is_1L1Lnu){
    
    vP_CM  = CM_1L1Lnu->GetFourVector();
    vP_ISR = ISR_1L1Lnu->GetFourVector();
    vP_I   = (*Ia_1L1Lnu+*Ib_1L1Lnu).GetFourVector();
   
    m_cosCM = CM_1L1Lnu->GetCosDecayAngle();
    m_cosS  = S_1L1Lnu->GetCosDecayAngle();
    m_MISR = ISR_1L1Lnu->GetMass();
    m_dphiCMI = acos(-1.)-fabs(CM_1L1Lnu->GetDeltaPhiBoostVisible());
    m_dphiSI  = acos(-1.)-fabs(S_1L1Lnu->GetDeltaPhiBoostVisible());

    m_HN2S = La_1L1Lnu->GetFourVector(*S_1L1Lnu).E() +
      Lb_1L1Lnu->GetFourVector(*S_1L1Lnu).E() +
      Na_1L1Lnu->GetFourVector(*S_1L1Lnu).P() +
      Nb_1L1Lnu->GetFourVector(*S_1L1Lnu).P() +
      Ia_1L1Lnu->GetFourVector(*S_1L1Lnu).P() +
      Ib_1L1Lnu->GetFourVector(*S_1L1Lnu).P();
    m_H11S = 2.*(*Ia_1L1Lnu+*Ib_1L1Lnu).GetFourVector(*S_1L1Lnu).P();
    m_HN1Ca = La_1L1Lnu->GetFourVector(*Ca_1L1Lnu).E()+
      Na_1L1Lnu->GetFourVector(*Ca_1L1Lnu).P()+
      Ia_1L1Lnu->GetFourVector(*Ca_1L1Lnu).P();
    m_HN1Cb = Lb_1L1Lnu->GetFourVector(*Cb_1L1Lnu).E()+
      Nb_1L1Lnu->GetFourVector(*Cb_1L1Lnu).P()+
      Ib_1L1Lnu->GetFourVector(*Cb_1L1Lnu).P();
    m_H11Ca = 2.*Ia_1L1Lnu->GetFourVector(*Ca_1L1Lnu).P();
    m_H11Cb = 2.*Ib_1L1Lnu->GetFourVector(*Cb_1L1Lnu).P();
    m_cosC  = Ca_1L1Lnu->GetCosDecayAngle();
  }

  
  if(m_Is_2L1L){
    
    vP_CM  = CM_2L1L->GetFourVector();
    vP_ISR = ISR_2L1L->GetFourVector();
    vP_I   = (*Ia_2L1L+*Ib_2L1L).GetFourVector();
   
    m_cosCM = CM_2L1L->GetCosDecayAngle();
    m_cosS  = S_2L1L->GetCosDecayAngle();
    m_MISR = ISR_2L1L->GetMass();
    m_dphiCMI = acos(-1.)-fabs(CM_2L1L->GetDeltaPhiBoostVisible());
    m_dphiSI  = acos(-1.)-fabs(S_2L1L->GetDeltaPhiBoostVisible());

    TVector3 vP_L = Lb_2L1L->GetFourVector(*Cb_2L1L).Vect();
    m_MTW = sqrt(2.*(vP_L.Pt()*ETMiss.Pt() - vP_L.Dot(ETMiss)));
    
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

  if(m_Is_2L1Lnu){
    
    vP_CM  = CM_2L1Lnu->GetFourVector();
    vP_ISR = ISR_2L1Lnu->GetFourVector();
    vP_I   = (*Ia_2L1Lnu+*Ib_2L1Lnu).GetFourVector();
   
    m_cosCM = CM_2L1Lnu->GetCosDecayAngle();
    m_cosS  = S_2L1Lnu->GetCosDecayAngle();
    m_MISR = ISR_2L1Lnu->GetMass();
    m_dphiCMI = acos(-1.)-fabs(CM_2L1Lnu->GetDeltaPhiBoostVisible());
    m_dphiSI  = acos(-1.)-fabs(S_2L1Lnu->GetDeltaPhiBoostVisible());
    
    m_HN2S = Z_2L1Lnu->GetFourVector(*S_2L1Lnu).E() +
      Lb_2L1Lnu->GetFourVector(*S_2L1Lnu).E() +
      Nb_2L1Lnu->GetFourVector(*S_2L1Lnu).E() +
      Ia_2L1Lnu->GetFourVector(*S_2L1Lnu).P() +
      Ib_2L1Lnu->GetFourVector(*S_2L1Lnu).P();
    m_H11S = 2.*(*Ia_2L1Lnu+*Ib_2L1Lnu).GetFourVector(*S_2L1Lnu).P();
    m_HN1Ca = Z_2L1Lnu->GetFourVector(*Ca_2L1Lnu).E()+
      Ia_2L1Lnu->GetFourVector(*Ca_2L1Lnu).P();
    m_HN1Cb = W_2L1Lnu->GetFourVector(*Cb_2L1Lnu).E()+
      Ib_2L1Lnu->GetFourVector(*Cb_2L1Lnu).P();
    m_H11Ca = 2.*Ia_2L1Lnu->GetFourVector(*Ca_2L1Lnu).P();
    m_H11Cb = 2.*Ib_2L1Lnu->GetFourVector(*Cb_2L1Lnu).P();
    m_cosC  = Ca_2L1Lnu->GetCosDecayAngle();
    
    m_MZ = Z_2L1Lnu->GetMass();
    m_cosZ = Z_2L1Lnu->GetCosDecayAngle();
  }

  m_PTCM = vP_CM.Pt();

  TVector3 boostZ = vP_CM.BoostVector();
  boostZ.SetX(0.);
  boostZ.SetY(0.);

  vP_CM.Boost(-boostZ);
  vP_ISR.Boost(-boostZ);
  vP_I.Boost(-boostZ);

  TVector3 boostT = vP_CM.BoostVector();
  vP_ISR.Boost(-boostT);
  vP_I.Boost(-boostT);

  TVector3 vPt_ISR = vP_ISR.Vect();
  TVector3 vPt_I   = vP_I.Vect();
  vPt_ISR -= vPt_ISR.Dot(boostZ.Unit())*boostZ.Unit();
  vPt_I   -= vPt_I.Dot(boostZ.Unit())*boostZ.Unit();
  
  m_PTISR =  vPt_ISR.Mag();
  m_RISR  = -vPt_I.Dot(vPt_ISR.Unit()) / m_PTISR;
  m_HN2SR = m_HN2S/m_RISR;
  m_dphiISRI = fabs(vPt_ISR.Angle(vPt_I));

  if(m_Tree)
    m_Tree->Fill();
}
