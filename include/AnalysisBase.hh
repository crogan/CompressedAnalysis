#ifndef AnalysisBase_h
#define AnalysisBase_h

#include <iostream>

#include <TTree.h>
#include <TLorentzVector.h>
#include <TVector3.h>
#include <TH1D.h>

using namespace std;

struct Jet {
  TLorentzVector P;
  bool btag;
};

template <class Base>
class AnalysisBase : public Base {

public:
  AnalysisBase(TTree* tree = 0);
  virtual ~AnalysisBase();

  virtual Int_t GetEntry(Long64_t entry);

  virtual TVector3 GetMET();
  //  double btag_cut = -0.0436; // 70% working point
  //  double btag_cut = -0.4434; // 77% working point
  //  double btag_cut = -0.7887; // 85% working point
  virtual void GetJets(vector<Jet>& JETs, double pt_cut = -1, 
		       double eta_cut = -1, double btag_WP_cut = -0.7887);
  double DeltaPhiMin(const vector<Jet>& JETs, const TVector3& MET, int N = -1);

protected:
  virtual double GetEventWeight();

};

#endif









