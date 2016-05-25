#ifndef Stop0LOptimization_h
#define Stop0LOptimization_h

#include "OptimizationBase.hh"
#include "CompressedBase.hh"

class Stop0LOptimization : public OptimizationBase<CompressedBase> {

public:
  Stop0LOptimization();
  virtual ~Stop0LOptimization();

protected:
  virtual double GetEventWeight();

private:
  virtual void InitCuts();
  virtual bool PassBaseline();
  virtual int EvaluateCuts();

};

#endif
