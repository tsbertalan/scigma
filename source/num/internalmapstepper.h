#ifndef __SCIGMA_NUM_INTERNALMAPSTEPPER_H__
#define __SCIGMA_NUM_INTERNALMAPSTEPPER_H__

#include <vector>
#include "definitions.h"
#include "stepper.h"

namespace scigma
{
  namespace num
  {

    class InternalMapStepper:public Stepper
    {
    public:
      InternalMapStepper(bool computeJacobian, const Function& tFunc, const VecF& xFuncs, const VecF& rhsFuncs, const VecF& funcFuncs);
      
      double t() const;
      double x(size_t index) const;
      double func(size_t index) const;
      double jac(size_t index) const;
      void reset(const double *x);


      void advance(size_t n=1);

    private:
      InternalMapStepper();
      InternalMapStepper(const InternalMapStepper&);
      InternalMapStepper& operator=(const InternalMapStepper&);

      Function tFunc_;
      VecF xFuncs_;
      VecF rhsFuncs_;
      VecF funcFuncs_;

      VecD work_;
      VecD jacData_;
      VecF jacFuncs_;
      double* jac_;

      double t0_;
      char padding_[8];
    };

  } /* end namespace num */
} /* end namespace scigma */

#endif /* __SCIGMA_NUM_INTERNALMAPSTEPPER_H__ */
