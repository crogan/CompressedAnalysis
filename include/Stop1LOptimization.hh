#ifndef Stop1LOptimization_h
#define Stop1LOptimization_h

#include "OptimizationBase.hh"
#include "CompressedBase.hh"

class Stop1LOptimization : public OptimizationBase<CompressedBase> {

public:
  Stop1LOptimization();
  virtual ~Stop1LOptimization();

protected:
  virtual double GetEventWeight();

private:
  virtual void InitCuts();
  virtual bool PassBaseline();
  virtual int EvaluateCuts();

};

#endif
