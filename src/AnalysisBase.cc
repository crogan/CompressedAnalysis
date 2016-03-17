#include <iostream>

#include "AnalysisBase.hh"
#include "HFntupleBase.hh"

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

/////////////////////////////////////////////////////////////////////
// specialized template method instances for different ntuple formats
/////////////////////////////////////////////////////////////////////

///////////////// HFntupleBase ///////////////////////////////////
template <>
double AnalysisBase<HFntupleBase>::GetEventWeight(){
  // to be updated with x-section normalization
  return  pileupweight*AnalysisWeight*EventWeight;
}

template <>
TVector3 AnalysisBase<HFntupleBase>::GetMET(){
  TVector3 met;
  // units GeV -> GeV
  met.SetXYZ(MET_px, MET_py, 0.0);
  return met;
}

template <>
void AnalysisBase<HFntupleBase>::GetJets(vector<Jet>& JETs, double pt_cut, 
					 double eta_cut, double btag_WP_cut){
  int Njet = jet_px->size();
  for(int i = 0; i < Njet; i++){
    Jet JET;
    // units MeV -> GeV
    JET.P.SetPxPyPzE(jet_px->at(i)/1000., jet_py->at(i)/1000.,
		     jet_pz->at(i)/1000., jet_e->at(i)/1000.);
    if((JET.P.Pt() >= pt_cut) && (fabs(JET.P.Eta()) < eta_cut || eta_cut < 0)){
      if(jet_MV2c20->at(i) > btag_WP_cut)
	JET.btag = true;
      else
	JET.btag = false;
      JETs.push_back(JET);
    }
  }
}

template class AnalysisBase<HFntupleBase>;

