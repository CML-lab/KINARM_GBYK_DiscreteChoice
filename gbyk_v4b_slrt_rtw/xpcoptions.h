#ifndef __gbyk_v4b_XPCOPTIONS_H___
#define __gbyk_v4b_XPCOPTIONS_H___
#include "simstruc_types.h"
#ifndef MT
#define MT                             0                         /* MT may be undefined by simstruc_types.h */
#endif

#include "gbyk_v4b.h"
#define XPCMDSSUPPORT                  0
#define MDSTASKSNUM                    0
#define FULLMULTITHREAD                0
#define SIZEOF_PARAMS                  (-1 * (int)sizeof(P_gbyk_v4b_T))
#define SIMMODE                        0
#define LOGTET                         1
#define LOGBUFSIZE                     100000
#define PROFILINGFLAG                  0
#define EVENTNUMBER                    5000
#define IRQ_NO                         0
#define IO_IRQ                         0
#define WWW_ACCESS_LEVEL               0
#define CPUCLOCK                       0
#define MAXOVERLOAD                    0
#define MAXOVERLOADLEN                 0
#define XPCMODELSTACKSIZEKB            512
#define XPCSTARTUPFLAG                 1
#define PTLOADPARAMFLAG                0
#define DOUBLEBUFFERING                0

/* Change all stepsize using the newBaseRateStepSize */
void gbyk_v4b_ChangeStepSize(real_T newBaseRateStepSize, RT_MODEL_gbyk_v4b_T *
  const gbyk_v4b_M)
{
  real_T ratio = newBaseRateStepSize / 0.00025;

  /* update non-zore stepsize of periodic
   * sample time. Stepsize of asynchronous
   * sample time is not changed in this function */
  gbyk_v4b_M->Timing.stepSize0 = gbyk_v4b_M->Timing.stepSize0 * ratio;
  gbyk_v4b_M->Timing.stepSize1 = gbyk_v4b_M->Timing.stepSize1 * ratio;
  gbyk_v4b_M->Timing.stepSize2 = gbyk_v4b_M->Timing.stepSize2 * ratio;
  gbyk_v4b_M->Timing.stepSize3 = gbyk_v4b_M->Timing.stepSize3 * ratio;
  gbyk_v4b_M->Timing.stepSize4 = gbyk_v4b_M->Timing.stepSize4 * ratio;
  gbyk_v4b_M->Timing.stepSize5 = gbyk_v4b_M->Timing.stepSize5 * ratio;
  gbyk_v4b_M->Timing.stepSize = gbyk_v4b_M->Timing.stepSize * ratio;
}

void XPCCALLCONV changeStepSize(real_T stepSize)
{
  /* Change all stepsize using the newBaseRateStepSize */
  gbyk_v4b_ChangeStepSize(stepSize, gbyk_v4b_M);
}

#endif                                 /* __gbyk_v4b_XPCOPTIONS_H___ */
