/*
 * Code generation for system system '<S37>/apply pmac loads'
 *
 * Model                      : gbyk_v4b
 * Model version              : 1.2667
 * Simulink Coder version : 8.8.1 (R2015aSP1) 04-Sep-2015
 * C source code generated on : Tue Sep 15 15:02:19 2020
 *
 * Note that the functions contained in this file are part of a Simulink
 * model, and are not self-contained algorithms.
 */

#include "gbyk_v4b_applypmacloads.h"

/* Include model header file for global data */
#include "gbyk_v4b.h"
#include "gbyk_v4b_private.h"

/* Start for enable system: '<S37>/apply pmac loads' */
void gbyk_v4b_applypmacloads_Start(void)
{
  /* Level2 S-Function Block: '<S252>/S-Function1' (mcc_apply_loads) */
  {
    SimStruct *rts = gbyk_v4b_M->childSfunctions[39];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }
}

/* Output and update for enable system: '<S37>/apply pmac loads' */
void gbyk_v4b_applypmacloads(void)
{
  /* Outputs for Enabled SubSystem: '<S37>/apply pmac loads' incorporates:
   *  EnablePort: '<S252>/Enable'
   */
  if (gbyk_v4b_B.Compare_l) {
    /* Product: '<S252>/Product' */
    gbyk_v4b_B.Product_m[0] = gbyk_v4b_B.AddTorques[0] * gbyk_v4b_B.Memory1;
    gbyk_v4b_B.Product_m[1] = gbyk_v4b_B.AddTorques[1] * gbyk_v4b_B.Memory1;
    gbyk_v4b_B.Product_m[2] = gbyk_v4b_B.AddTorques[2] * gbyk_v4b_B.Memory1;
    gbyk_v4b_B.Product_m[3] = gbyk_v4b_B.AddTorques[3] * gbyk_v4b_B.Memory1;

    /* DataTypeConversion: '<S252>/Data Type Conversion6' */
    gbyk_v4b_B.DataTypeConversion6[0] = (real32_T)gbyk_v4b_B.Product_m[0];
    gbyk_v4b_B.DataTypeConversion6[1] = (real32_T)gbyk_v4b_B.Product_m[1];
    gbyk_v4b_B.DataTypeConversion6[2] = (real32_T)gbyk_v4b_B.Product_m[2];
    gbyk_v4b_B.DataTypeConversion6[3] = (real32_T)gbyk_v4b_B.Product_m[3];

    /* DataTypeConversion: '<S252>/Data Type Conversion' */
    gbyk_v4b_B.DataTypeConversion_a[0] = (real32_T)gbyk_v4b_B.ArmOrientation;
    gbyk_v4b_B.DataTypeConversion_a[1] = (real32_T)gbyk_v4b_B.M1orientation;
    gbyk_v4b_B.DataTypeConversion_a[2] = (real32_T)gbyk_v4b_B.M2Orientation;
    gbyk_v4b_B.DataTypeConversion_a[3] = (real32_T)gbyk_v4b_B.M1GearRatio;
    gbyk_v4b_B.DataTypeConversion_a[4] = (real32_T)gbyk_v4b_B.M2GearRatio;
    gbyk_v4b_B.DataTypeConversion_a[5] = (real32_T)gbyk_v4b_B.torqueconstant;

    /* DataTypeConversion: '<S252>/Data Type Conversion1' */
    gbyk_v4b_B.DataTypeConversion1_cq[0] = (real32_T)gbyk_v4b_B.ArmOrientation_c;
    gbyk_v4b_B.DataTypeConversion1_cq[1] = (real32_T)gbyk_v4b_B.M1orientation_f;
    gbyk_v4b_B.DataTypeConversion1_cq[2] = (real32_T)gbyk_v4b_B.M2Orientation_c;
    gbyk_v4b_B.DataTypeConversion1_cq[3] = (real32_T)gbyk_v4b_B.M1GearRatio_h;
    gbyk_v4b_B.DataTypeConversion1_cq[4] = (real32_T)gbyk_v4b_B.M2GearRatio_d;
    gbyk_v4b_B.DataTypeConversion1_cq[5] = (real32_T)gbyk_v4b_B.torqueconstant_m;

    /* Level2 S-Function Block: '<S252>/S-Function1' (mcc_apply_loads) */
    {
      SimStruct *rts = gbyk_v4b_M->childSfunctions[39];
      sfcnOutputs(rts, 1);
    }

    srUpdateBC(gbyk_v4b_DW.applypmacloads_SubsysRanBC);
  }

  /* End of Outputs for SubSystem: '<S37>/apply pmac loads' */
}

/* Termination for enable system: '<S37>/apply pmac loads' */
void gbyk_v4b_applypmacloads_Term(void)
{
  /* Level2 S-Function Block: '<S252>/S-Function1' (mcc_apply_loads) */
  {
    SimStruct *rts = gbyk_v4b_M->childSfunctions[39];
    sfcnTerminate(rts);
  }
}
