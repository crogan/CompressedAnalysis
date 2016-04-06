#ifndef OptimizationBase_h
#define OptimizationBase_h

#include <iostream>
#include <string>
#include <vector>

#include <TChain.h>


using namespace std;

template <class Base>
class OptimizationBase {
  
public:
  OptimizationBase();
  virtual ~OptimizationBase();

  void Loop(int Njob = 1, int ijob = 0);
  
  void AddSignal(string filename);
  void AddBackground(string filename);
  
  void WriteOutputFile(const string& filename);

protected:
  Base* m_Base;
  virtual double GetEventWeight(){ 
    return 1.;
  }

  virtual void InitCuts() = 0;
  int m_N_Cut;
  vector<double> m_CutMin;
  vector<double> m_CutMax;
  vector<int> m_CutN;
  vector<double> m_CutVal;

  virtual bool PassBaseline() = 0;
  virtual int EvaluateCuts() = 0;

  int m_NSIG;

private:
  TChain* m_Chain;
  vector<int> m_Signal;
  vector<string> m_SignalName;
  void InitBase();

  TTree* m_Tree;

};

#endif
