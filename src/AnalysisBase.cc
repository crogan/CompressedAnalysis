#include <iostream>

#include "AnalysisBase.hh"
#include "HFntupleBase.hh"
#include "SussexBase.hh"
#include "HiggsinoBase.hh"
#include "SimpleBase.hh"
#include "Incl1LBase.hh"

using namespace std;

template <class Base>
AnalysisBase<Base>::AnalysisBase(TTree* tree)
  : Base(tree) {}

template <class Base>
AnalysisBase<Base>::~AnalysisBase() {}

template <class Base>
Int_t AnalysisBase<Base>::GetEntry(Long64_t entry){
  if (!Base::fChain) return 0;
  Int_t ret = Base::fChain->GetEntry(entry);

  return ret;
}

template <class Base>
double AnalysisBase<Base>::DeltaPhiMin(const vector<Jet>& JETs, const TVector3& MET, int N){
  double dphimin = acos(-1);
  int Njet = JETs.size();
  for(int i = 0; i < Njet; i++){
    if(N > 0 && i >= N) break;
    if(fabs(JETs[i].P.Vect().DeltaPhi(MET)) < dphimin) dphimin = fabs(JETs[i].P.Vect().DeltaPhi(MET));
  }
  return dphimin;
}

template <class Base>
void AnalysisBase<Base>::GetPartition(vector<Jet>& V_JETs, vector<Jet>& ISR_JETs, 
				      const vector<Jet>& inputJETs, const TVector3& MET, int algo){
  int Ninput = inputJETs.size();
  
  // DO 4 N^3 calculation
  vector<TLorentzVector> inputs;
  for(int i = 0; i < Ninput; i++)
    inputs.push_back(inputJETs[i].P);

  TLorentzVector vMET;
  vMET.SetVectM(MET,0.);

  inputs.push_back(vMET);
  Ninput++;
    
  // boost input vectors to CM frame
  TLorentzVector TOT(0.,0.,0.,0.);
  for(int i = 0; i < Ninput; i++) TOT += inputs[i];
  TVector3 boost = TOT.BoostVector();
  for(int i = 0; i < Ninput; i++) inputs[i].Boost(-boost);
  
  int ip_max[2];
  int jp_max[2];
  for(int i = 0; i < 2; i++) ip_max[i] = -1;
  for(int i = 0; i < 2; i++) jp_max[i] = -1;
  double metric_max = -1.;
  // Loop over all 2-jet seed probes
  int ip[2], jp[2];
  for(ip[0] = 0; ip[0] < Ninput-1; ip[0]++){
    for(ip[1] = ip[0]+1; ip[1] < Ninput; ip[1]++){
      TVector3 nRef = inputs[ip[0]].Vect().Cross(inputs[ip[1]].Vect());
      int Nhem[2];
      TLorentzVector hem[2];
      for(int i = 0; i < 2; i++){
	Nhem[i] = 0;
	hem[i].SetPxPyPzE(0.,0.,0.,0.);
      }
      // Loop over all jets
      for(int i = 0; i < Ninput; i++){
	if((i == ip[0]) || (i ==ip[1])) continue;
	int ihem = int(inputs[i].Vect().Dot(nRef) > 0.);
	Nhem[ihem]++;
	hem[ihem] += inputs[i];
      }
      // assign 2 probes
      for(jp[0] = 0; jp[0] < 2; jp[0]++){
	for(jp[1] = 0; jp[1] < 2; jp[1]++){
	  if(jp[0] == jp[1] && Nhem[!jp[0]] == 0) continue;
	  TLorentzVector hem_probes[2];
	  for(int i = 0; i < 2; i++) hem_probes[i] = hem[i];
	  for(int i = 0; i < 2; i++) hem_probes[jp[i]] += inputs[ip[i]];
	  double metric = hem_probes[0].P() + hem_probes[1].P();
	  if(metric > metric_max){
	    metric_max = metric;
	    for(int i = 0; i < 2; i++) ip_max[i] = ip[i];
	    for(int i = 0; i < 2; i++) jp_max[i] = jp[i];
	  }
	}
      }
    }
  }
  if(metric_max < 0){
    cout << "Negative metric ... " << endl;
    return;
  }
  
  // fill output vectors
  TVector3 HEMs[2];

  for(int i = 0; i < 2; i++) HEMs[jp_max[i]] += inputs[ip_max[i]].Vect();
  TVector3 nRef = inputs[ip_max[0]].Vect().Cross(inputs[ip_max[1]].Vect());
  for(int i = 0; i < Ninput; i++){
    if((i == ip_max[0]) || (i == ip_max[1])) continue;
    int ihem = int(inputs[i].Vect().Dot(nRef) > 0.);
    HEMs[ihem] += inputs[i].Vect();
  }
 
  if(MET.Dot(HEMs[1]) > 0){
    TVector3 temp = HEMs[0];
    HEMs[0] = HEMs[1];
    HEMs[1] = temp;
  }

  // g_N_algo = 5;
  double thresh[5];
  for(int i = 0; i < 5; i++){
    thresh[i] = -1.*double(i)*50.;
  }

  V_JETs.clear();
  ISR_JETs.clear();
  for(int i = 0; i < Ninput-1; i++){
    if(inputs[i].Vect().Dot(HEMs[0].Unit()) >= thresh[algo])
      V_JETs.push_back(inputJETs[i]);
    else
      ISR_JETs.push_back(inputJETs[i]);
  }
}

template <class Base>
double AnalysisBase<Base>::GetEventWeight(){
  return 0;
}

template <class Base>
TVector3 AnalysisBase<Base>::GetMET(){
  return TVector3(0.,0.,0.);
}

template <class Base>
void AnalysisBase<Base>::GetJets(vector<Jet>& JETs, double pt_cut, 
				 double eta_cut, double btag_WP_cut) {}

template <class Base>
void AnalysisBase<Base>::GetLeptons(vector<TLorentzVector>& LEPs, vector<int>& IDs,
				    double pt_cut, double eta_cut) {}
template <class Base>
void AnalysisBase<Base>::GetMuons(vector<TLorentzVector>& MUs, 
				  double pt_cut, double eta_cut) {}

template <class Base>
void AnalysisBase<Base>::GetElectrons(vector<TLorentzVector>& ELs, 
				      double pt_cut, double eta_cut) {}

/////////////////////////////////////////////////////////////////////
// specialized template method instances for different ntuple formats
/////////////////////////////////////////////////////////////////////

///////////////// SussexBase ///////////////////////////////////
template <>
double AnalysisBase<SussexBase>::GetEventWeight(){
  if(pileupweight <= 0.)
    pileupweight = 1.;
  return XSecWeight*AnalysisWeight*btagSFCentral*1000.;
  //return XSecWeight*AnalysisWeight*btagSFCentral*1000.*0.301190/0.33198; // for 400_227 temporarily
}

template <>
TVector3 AnalysisBase<SussexBase>::GetMET(){
  TVector3 met;
  // units GeV -> GeV
  met.SetXYZ(MET_px, MET_py, 0.0);
  return met;
}

template <>
void AnalysisBase<SussexBase>::GetJets(vector<Jet>& JETs, double pt_cut, 
					 double eta_cut, double btag_WP_cut){
  JETs.clear();

  int Njet = jet_px->size();
  for(int i = 0; i < Njet; i++){
    Jet JET;
    // units MeV -> GeV
    JET.P.SetPxPyPzE(jet_px->at(i)/1000., jet_py->at(i)/1000.,
		     jet_pz->at(i)/1000., jet_e->at(i)/1000.);
    if((JET.P.Pt() >= pt_cut) && (fabs(JET.P.Eta()) < eta_cut || eta_cut < 0)){
      if(jet_MV2c20->at(i) > btag_WP_cut)
      //if(jet_MV2c10->at(i) > btag_WP_cut)
	JET.btag = true;
      else
	JET.btag = false;
      JETs.push_back(JET);
    }
  }
}

template <>
void AnalysisBase<SussexBase>::GetMuons(vector<TLorentzVector>& MUs, 
					double pt_cut, double eta_cut) {
  MUs.clear();

  int Nmu = mu_px->size();
  for(int i = 0; i < Nmu; i++){
    TLorentzVector MU;
    // units MeV -> GeV
    MU.SetPxPyPzE(mu_px->at(i)/1000., mu_py->at(i)/1000.,
		  mu_pz->at(i)/1000., mu_e->at(i)/1000.);
    if((MU.Pt() >= pt_cut) && (fabs(MU.Eta()) < eta_cut || eta_cut < 0)){
      MUs.push_back(MU);
    }
  }
}

template <>
void AnalysisBase<SussexBase>::GetElectrons(vector<TLorentzVector>& ELs, 
					    double pt_cut, double eta_cut) {
  ELs.clear();

  int Nel = el_px->size();
  for(int i = 0; i < Nel; i++){
    TLorentzVector EL;
    // units MeV -> GeV
    EL.SetPxPyPzE(el_px->at(i)/1000., el_py->at(i)/1000.,
		  el_pz->at(i)/1000., el_e->at(i)/1000.);
    if((EL.Pt() >= pt_cut) && (fabs(EL.Eta()) < eta_cut || eta_cut < 0)){
      ELs.push_back(EL);
    }
  }
}

double xsec_3l =  517.259; //fb
double bf_3l =  0.03266518922;
double eff_3l =  6.564165*pow(10,-1);
int nEvents_3l = 6600;
double xsec_2l2j = 517.259; //fb
double bf_2l2j = 0.068070618;
double eff_2l2j = 4.912453*pow(10,-1);
int nEvents_2l2j = 7734;

///////////////// HiggsinoBase ///////////////////////////////////
template <>
double AnalysisBase<HiggsinoBase>::GetEventWeight(){
  if(pileupWeight <= 0.)
      pileupWeight = 1.;
  return weight1fb; //backgrounds
  //  return eventWeight*xsec_3l*bf_3l*eff_3l/nEvents_3l; // signals 3l
  //return eventWeight*xsec_2l2j*bf_2l2j*eff_2l2j/nEvents_2l2j; // signals 2l2j
}

template <>
TVector3 AnalysisBase<HiggsinoBase>::GetMET(){
  TVector3 met;
  met.SetXYZ(MET*cos(MET_phi), MET*sin(MET_phi), 0.0);
  return met;
}

template <>
void AnalysisBase<HiggsinoBase>::GetJets(vector<Jet>& JETs, double pt_cut, 
					 double eta_cut, double btag_WP_cut){
  JETs.clear();

  int Njet = jet_pT->size();
  for(int i = 0; i < Njet; i++){
    Jet JET;
    // units MeV -> GeV
    JET.P.SetPtEtaPhiE(jet_pT->at(i), jet_eta->at(i),
		       jet_phi->at(i), jet_E->at(i));
    if((JET.P.Pt() >= pt_cut) && (fabs(JET.P.Eta()) < eta_cut || eta_cut < 0)){
      //if(jet_MV2c20->at(i) > btag_WP_cut)
      //commented out for simple samples
      if(jet_btag->at(i) == 1)
	JET.btag = true;
      else
	JET.btag = false;
      JETs.push_back(JET);
    }
  }
}

template <>
void AnalysisBase<HiggsinoBase>::GetLeptons(vector<TLorentzVector>& LEPs, vector<int>& IDs,
					    double pt_cut, double eta_cut) {
  LEPs.clear();
  IDs.clear();
  
  int Nlep = lep_pT->size();
  for(int i = 0; i < Nlep; i++){
    TLorentzVector LEP;
    LEP.SetPtEtaPhiE(lep_pT->at(i), lep_eta->at(i),
		    lep_phi->at(i), lep_E->at(i));
    if((LEP.Pt() >= pt_cut) && (fabs(LEP.Eta()) < eta_cut || eta_cut < 0)){
      LEPs.push_back(LEP);
      IDs.push_back(lep_pdgId->at(i));
    }
  }
}

template <>
void AnalysisBase<HiggsinoBase>::GetMuons(vector<TLorentzVector>& MUs, 
					double pt_cut, double eta_cut) {
  MUs.clear();

  int Nmu = mu_pT->size();
  for(int i = 0; i < Nmu; i++){
    TLorentzVector MU;
    MU.SetPtEtaPhiE(mu_pT->at(i), mu_eta->at(i),
		    mu_phi->at(i), mu_E->at(i));
    if((MU.Pt() >= pt_cut) && (fabs(MU.Eta()) < eta_cut || eta_cut < 0)){
      MUs.push_back(MU);
    }
  }
}


template <>
void AnalysisBase<HiggsinoBase>::GetElectrons(vector<TLorentzVector>& ELs, 
					    double pt_cut, double eta_cut) {
  ELs.clear();

  int Nel = el_pT->size();
  for(int i = 0; i < Nel; i++){
    TLorentzVector EL;
    EL.SetPtEtaPhiE(el_pT->at(i), el_phi->at(i),
		  el_eta->at(i), el_E->at(i));
    if((EL.Pt() >= pt_cut) && (fabs(EL.Eta()) < eta_cut || eta_cut < 0)){
      ELs.push_back(EL);
    }
  }
}

// Event weight numbers for Ruo's generated samples

double xsec155 = 2105; //fb
double eff155 = 0.07244277;
int nEvents155 = 50000;
double xsec160 = 1964; //fb
double eff160 = 0.1154156;
int nEvents160 = 50000;
double xsec170 = 1728; //fb
double eff170 = 0.1182419;
int nEvents170 = 50000;
double xsec190_150 = 1360; //fb
double eff190_150 = 0.1271336;
int nEvents190_150 = 50000;
double xsec190_170 = 1130; //fb
double eff190_170 = 0.13;
int nEvents190_170 = 20000;
double xsec210_190 = 767.4; //fb
double eff210_190 = 0.142;
int nEvents210_190 = 20000;

///////////////// SimpleBase ///////////////////////////////////
template <>
double AnalysisBase<SimpleBase>::GetEventWeight(){
  return 1*xsec190_150*eff190_150/nEvents190_150;
}

template <>
TVector3 AnalysisBase<SimpleBase>::GetMET(){
  TVector3 met;
  met.SetXYZ(MET*cos(MET_phi), MET*sin(MET_phi), 0.0);
  return met;
}

template <>
void AnalysisBase<SimpleBase>::GetJets(vector<Jet>& JETs, double pt_cut, 
					 double eta_cut, double btag_WP_cut){
  JETs.clear();

  int Njet = jet_pT->size();
  for(int i = 0; i < Njet; i++){
    Jet JET;
    // units MeV -> GeV
    JET.P.SetPtEtaPhiE(jet_pT->at(i), jet_eta->at(i),
		       jet_phi->at(i), jet_E->at(i));
    if((JET.P.Pt() >= pt_cut) && (fabs(JET.P.Eta()) < eta_cut || eta_cut < 0)){
      JET.btag = false; //assume no b-tagged jets for simple samples
      JETs.push_back(JET);
    }
  }
}

template <>
void AnalysisBase<SimpleBase>::GetLeptons(vector<TLorentzVector>& LEPs, vector<int>& IDs,
					    double pt_cut, double eta_cut) {
  LEPs.clear();
  IDs.clear();
  
  int Nlep = lep_pT->size();
  for(int i = 0; i < Nlep; i++){
    TLorentzVector LEP;
    LEP.SetPtEtaPhiE(lep_pT->at(i), lep_eta->at(i),
		    lep_phi->at(i), lep_E->at(i));
    if((LEP.Pt() >= pt_cut) && (fabs(LEP.Eta()) < eta_cut || eta_cut < 0)){
      LEPs.push_back(LEP);
      IDs.push_back(lep_pdgId->at(i));
    }
  }
}

///////////////// ********** /////////////////////////////////// 
///////////////// Incl1LBase /////////////////////////////////// 
///////////////// ********** /////////////////////////////////// 
template <>
double AnalysisBase<Incl1LBase>::GetEventWeight(){
  return pileupWeight*eventWeight*genWeight*jvtWeight*leptonWeight*SherpaVjetsNjetsWeight;

  // 300-200 //  *(-0.3163*0.5825/20000);
  // 170-150 //  *(-1.724*0.29055/50000);
  // 120-100 //  *(-6.54*0.231/20000);   
}

template <>
TVector3 AnalysisBase<Incl1LBase>::GetMET(){
  TVector3 MET;
  MET.SetXYZ(met*cos(metPhi), met*sin(metPhi), 0.0);
  return MET;
}

template <>
void AnalysisBase<Incl1LBase>::GetJets(vector<Jet>& JETs, double pt_cut, 
				       double eta_cut, double btag_WP_cut){
  JETs.clear();

  // A bit ugly, but it allow us to keep flat ntuples... (c'est la vie :-))
  vector<float> jpt  = {jet1Pt,jet2Pt,jet3Pt,jet4Pt,jet5Pt,jet6Pt,jet7Pt,jet8Pt};
  vector<float> jeta = {jet1Eta,jet2Eta,jet3Eta,jet4Eta,jet5Eta,jet6Eta,jet7Eta,jet8Eta};
  vector<float> jphi = {jet1Phi,jet2Phi,jet3Phi,jet4Phi,jet5Phi,jet6Phi,jet7Phi,jet8Phi};
  vector<float> jE   = {jet1E,jet2E,jet3E,jet4E,jet5E,jet6E,jet7E,jet8E};
  vector<float> jmv2 = {jet1Mv2c10,jet2Mv2c10,jet3Mv2c10,jet4Mv2c10,jet5Mv2c10,jet6Mv2c10,jet7Mv2c10,jet8Mv2c10};
  
  int Njets = jpt.size();
  for(int i = 0; i < Njets; i++) {
    if(jpt[i]>0) {
      Jet JET;
      JET.P.SetPtEtaPhiE(jpt[i],jeta[i],jphi[i],jE[i]);
      if( jmv2[i] > btag_WP_cut && fabs(jeta[i])<2.5 )
	JET.btag = true;
      else
	JET.btag = false;
      JETs.push_back(JET);
    }
  }
}

template <>
void AnalysisBase<Incl1LBase>::GetMuons(vector<TLorentzVector>& MUs, 
					double pt_cut, double eta_cut) {
  MUs.clear();
  
  if(AnalysisType==2) {
    if( lep1Pt >= pt_cut && (fabs(lep1Eta) < eta_cut || eta_cut < 0) ){
      TLorentzVector MU;
      MU.SetPtEtaPhiM(lep1Pt,lep1Eta,lep1Phi,0.105658); 
      MUs.push_back(MU);
    }
  }
  if(AnalysisType_lep2==2) {
    if( lep2Pt >= pt_cut && (fabs(lep2Eta) < eta_cut || eta_cut < 0) ){
      TLorentzVector MU;
      MU.SetPtEtaPhiM(lep2Pt,lep2Eta,lep2Phi,0.105658);
      MUs.push_back(MU);
    }
  }
  if(AnalysisType_lep3==2) {
    if( lep3Pt >= pt_cut && (fabs(lep3Eta) < eta_cut || eta_cut < 0) ){
      TLorentzVector MU;
      MU.SetPtEtaPhiM(lep3Pt,lep3Eta,lep3Phi,0.105658);
      MUs.push_back(MU);
    }
  }
  if(AnalysisType_lep4==2) {
    if( lep4Pt >= pt_cut && (fabs(lep4Eta) < eta_cut || eta_cut < 0) ){
      TLorentzVector MU;
      MU.SetPtEtaPhiM(lep4Pt,lep4Eta,lep4Phi,0.105658);
      MUs.push_back(MU);
    }
  }
}

template <>
void AnalysisBase<Incl1LBase>::GetElectrons(vector<TLorentzVector>& ELs, 
					    double pt_cut, double eta_cut) {
  ELs.clear();

  if(AnalysisType==1) {
    if( lep1Pt >= pt_cut && (fabs(lep1Eta) < eta_cut || eta_cut < 0) ){
      TLorentzVector EL;
      EL.SetPtEtaPhiM(lep1Pt,lep1Eta,lep1Phi,0.00051);
      ELs.push_back(EL);
    }
  }
  if(AnalysisType_lep2==1) {
    if( lep2Pt >= pt_cut && (fabs(lep2Eta) < eta_cut || eta_cut < 0) ){
      TLorentzVector EL;
      EL.SetPtEtaPhiM(lep2Pt,lep2Eta,lep2Phi,0.00051);
      ELs.push_back(EL);
    }
  }
  if(AnalysisType_lep3==1) {
    if( lep3Pt >= pt_cut && (fabs(lep3Eta) < eta_cut || eta_cut < 0) ){
      TLorentzVector EL;
      EL.SetPtEtaPhiM(lep3Pt,lep3Eta,lep3Phi,0.00051);
      ELs.push_back(EL);
    }
  }
  if(AnalysisType_lep4==1) {
    if( lep4Pt >= pt_cut && (fabs(lep4Eta) < eta_cut || eta_cut < 0) ){
      TLorentzVector EL;
      EL.SetPtEtaPhiM(lep4Pt,lep4Eta,lep4Phi,0.00051);
      ELs.push_back(EL);
    }
  }
}

template <>
void AnalysisBase<Incl1LBase>::GetLeptons(vector<TLorentzVector>& LEPs, vector<int>& IDs,
                                            double pt_cut, double eta_cut) {
  LEPs.clear();
  IDs.clear();
  
  if( lep1Pt >= pt_cut && (fabs(lep1Eta) < eta_cut || eta_cut < 0) ){
    TLorentzVector LEP;
    LEP.SetPtEtaPhiM(lep1Pt,lep1Eta,lep1Phi, ( AnalysisType==1 ? 0.00051 : 0.105658 ) );
    LEPs.push_back(LEP);
    IDs.push_back(lep1Charge*AnalysisType);
  }
  if( lep2Pt >= pt_cut && (fabs(lep2Eta) < eta_cut || eta_cut < 0) ){
    TLorentzVector LEP;
    LEP.SetPtEtaPhiM(lep2Pt,lep2Eta,lep2Phi, ( AnalysisType_lep2==1 ? 0.00051 : 0.105658 ) );
    LEPs.push_back(LEP);
    IDs.push_back(lep2Charge*AnalysisType_lep2);
  }
  if( lep3Pt >= pt_cut && (fabs(lep3Eta) < eta_cut || eta_cut < 0) ){
    TLorentzVector LEP;
    LEP.SetPtEtaPhiM(lep3Pt,lep3Eta,lep3Phi, ( AnalysisType_lep3==1 ? 0.00051 : 0.105658 ) );
    LEPs.push_back(LEP);
    IDs.push_back(lep3Charge*AnalysisType_lep3);
  }
  if( lep4Pt >= pt_cut && (fabs(lep4Eta) < eta_cut || eta_cut < 0) ){
    TLorentzVector LEP;
    LEP.SetPtEtaPhiM(lep4Pt,lep4Eta,lep4Phi, ( AnalysisType_lep4==1 ? 0.00051 : 0.105658 ) );
    LEPs.push_back(LEP);
    IDs.push_back(lep4Charge*AnalysisType_lep4);
  }
}



template class AnalysisBase<HFntupleBase>;
template class AnalysisBase<SussexBase>;
template class AnalysisBase<HiggsinoBase>;
template class AnalysisBase<SimpleBase>;
template class AnalysisBase<Incl1LBase>;
