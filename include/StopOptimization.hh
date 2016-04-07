#ifndef StopOptimization_h
#define StopOptimization_h

#include "OptimizationBase.hh"
#include "CompressedBase.hh"

class StopOptimization : public OptimizationBase<CompressedBase> {

public:
  StopOptimization();
  virtual ~StopOptimization();

protected:
  virtual double GetEventWeight();

private:
  virtual void InitCuts();
  virtual bool PassBaseline();
  virtual int EvaluateCuts();

};

#endif
