/*
 * Code generation for system system '<S4>/Keep alive'
 *
 * Model                      : gbyk_v4b
 * Model version              : 1.2667
 * Simulink Coder version : 8.8.1 (R2015aSP1) 04-Sep-2015
 * C source code generated on : Tue Sep 15 15:02:19 2020
 *
 * Note that the functions contained in this file are part of a Simulink
 * model, and are not self-contained algorithms.
 */

#include "gbyk_v4b_Keepalive.h"

/* Include model header file for global data */
#include "gbyk_v4b.h"
#include "gbyk_v4b_private.h"

/* Start for atomic system: '<S4>/Keep alive' */
void gbyk_v4b_Keepalive_Start(void)
{
  /* Level2 S-Function Block: '<S31>/Send' (xpcudpbytesend) */
  {
    SimStruct *rts = gbyk_v4b_M->childSfunctions[0];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }
}

/* Output and update for atomic system: '<S4>/Keep alive' */
void gbyk_v4b_Keepalive(void)
{
  /* Pack: <S31>/Pack */
  (void) memcpy(&gbyk_v4b_B.Pack_g[0], &gbyk_v4b_P.const_Value[0],
                40);

  /* Level2 S-Function Block: '<S31>/Send' (xpcudpbytesend) */
  {
    SimStruct *rts = gbyk_v4b_M->childSfunctions[0];
    sfcnOutputs(rts, 5);
  }
}

/* Termination for atomic system: '<S4>/Keep alive' */
void gbyk_v4b_Keepalive_Term(void)
{
  /* Level2 S-Function Block: '<S31>/Send' (xpcudpbytesend) */
  {
    SimStruct *rts = gbyk_v4b_M->childSfunctions[0];
    sfcnTerminate(rts);
  }
}
