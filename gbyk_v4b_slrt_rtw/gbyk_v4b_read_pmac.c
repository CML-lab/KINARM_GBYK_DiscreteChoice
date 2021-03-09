/*
 * Code generation for system system '<S66>/read_pmac'
 *
 * Model                      : gbyk_v4b
 * Model version              : 1.2667
 * Simulink Coder version : 8.8.1 (R2015aSP1) 04-Sep-2015
 * C source code generated on : Tue Sep 15 15:02:19 2020
 *
 * Note that the functions contained in this file are part of a Simulink
 * model, and are not self-contained algorithms.
 */

#include "gbyk_v4b_read_pmac.h"

/* Include model header file for global data */
#include "gbyk_v4b.h"
#include "gbyk_v4b_private.h"

/* Forward declaration for local functions */
static void gbyk_v4b_circshift(real_T a[5]);
static void gbyk_v4b_calculateVelAcc(const real_T robotStruct_shoPos[5], const
  real_T robotStruct_elbPos[5], const real_T robotStruct_shoVel[5], const real_T
  robotStruct_elbVel[5], real_T robotStruct_shoAcc, real_T robotStruct_elbAcc,
  real_T robotStruct_bHasSecondary, const real_T servoValues[5], const real_T
  robotData[10], real_T robotStructOut_shoPos[5], real_T robotStructOut_elbPos[5],
  real_T robotStructOut_shoVel[5], real_T robotStructOut_elbVel[5], real_T
  *robotStructOut_shoAcc, real_T *robotStructOut_elbAcc, real_T
  *robotStructOut_bHasSecondary);
static void gbyk_v4b_calculateVelAcc_n(const real_T robotStruct_shoPos[5], const
  real_T robotStruct_elbPos[5], const real_T robotStruct_shoVel[5], const real_T
  robotStruct_elbVel[5], real_T robotStruct_shoAcc, real_T robotStruct_elbAcc,
  real_T robotStruct_bHasSecondary, const real_T servoValues[5], const real_T
  robotData[6], real_T robotStructOut_shoPos[5], real_T robotStructOut_elbPos[5],
  real_T robotStructOut_shoVel[5], real_T robotStructOut_elbVel[5], real_T
  *robotStructOut_shoAcc, real_T *robotStructOut_elbAcc, real_T
  *robotStructOut_bHasSecondary);
static void gbyk_v4b_circshift_d(real_T a[3]);
static void gbyk_v4b_updateValues(shSrZ99dE4twa6ELJRaXlMD_gbyk_v4b_T
  *robotStruct, const real_T robotData[10], uint32_T servoCounter, real_T POLES);

/* Function for MATLAB Function: '<S210>/Robot_data_builder' */
static void gbyk_v4b_circshift(real_T a[5])
{
  real_T buffer;
  buffer = a[4];
  a[4] = a[3];
  a[3] = a[2];
  a[2] = a[1];
  a[1] = a[0];
  a[0] = buffer;
}

/* Function for MATLAB Function: '<S210>/Robot_data_builder' */
static void gbyk_v4b_calculateVelAcc(const real_T robotStruct_shoPos[5], const
  real_T robotStruct_elbPos[5], const real_T robotStruct_shoVel[5], const real_T
  robotStruct_elbVel[5], real_T robotStruct_shoAcc, real_T robotStruct_elbAcc,
  real_T robotStruct_bHasSecondary, const real_T servoValues[5], const real_T
  robotData[10], real_T robotStructOut_shoPos[5], real_T robotStructOut_elbPos[5],
  real_T robotStructOut_shoVel[5], real_T robotStructOut_elbVel[5], real_T
  *robotStructOut_shoAcc, real_T *robotStructOut_elbAcc, real_T
  *robotStructOut_bHasSecondary)
{
  real_T stepDuration;
  real_T shoVel;
  real_T elbVel;
  int32_T i;

  /* matches from PMAC code */
  /* '<S214>:1:78' */
  for (i = 0; i < 5; i++) {
    robotStructOut_shoPos[i] = robotStruct_shoPos[i];
    robotStructOut_elbPos[i] = robotStruct_elbPos[i];
  }

  *robotStructOut_bHasSecondary = robotStruct_bHasSecondary;

  /* do not name this anything that will make it the first variable name in */
  /* this method alphabetically. Seriously. With the name "duration" compiling */
  /* a model would work in 2010a, but nothing higher. Most models would compile, */
  /* but the verification task would not! */
  /* '<S214>:1:84' */
  stepDuration = 0.0;
  if (robotStruct_bHasSecondary != 0.0) {
    /* '<S214>:1:87' */
    stepDuration = (servoValues[0] - servoValues[1]) * 0.00088541674613952634;
    if (stepDuration == 0.0) {
      /* '<S214>:1:88' */
      /* '<S214>:1:89' */
      shoVel = robotStruct_shoVel[0];

      /* '<S214>:1:90' */
      elbVel = robotStruct_elbVel[0];
    } else {
      /* '<S214>:1:92' */
      shoVel = (robotStruct_shoPos[0] - robotStruct_shoPos[1]) / stepDuration;

      /* '<S214>:1:93' */
      elbVel = (robotStruct_elbPos[0] - robotStruct_elbPos[1]) / stepDuration;
    }
  } else {
    /* '<S214>:1:96' */
    shoVel = robotData[2];

    /* '<S214>:1:97' */
    elbVel = robotData[3];
  }

  /* '<S214>:1:100' */
  /* '<S214>:1:71' */
  /* '<S214>:1:72' */
  for (i = 0; i < 5; i++) {
    robotStructOut_shoVel[i] = robotStruct_shoVel[i];
  }

  gbyk_v4b_circshift(robotStructOut_shoVel);

  /* '<S214>:1:73' */
  robotStructOut_shoVel[0] = shoVel;

  /* '<S214>:1:101' */
  /* '<S214>:1:71' */
  /* '<S214>:1:72' */
  for (i = 0; i < 5; i++) {
    robotStructOut_elbVel[i] = robotStruct_elbVel[i];
  }

  gbyk_v4b_circshift(robotStructOut_elbVel);

  /* '<S214>:1:73' */
  robotStructOut_elbVel[0] = elbVel;
  if (robotStruct_bHasSecondary != 0.0) {
    if (stepDuration == 0.0) {
      /* '<S214>:1:104' */
      /* '<S214>:1:105' */
      *robotStructOut_shoAcc = robotStruct_shoAcc;

      /* '<S214>:1:106' */
      *robotStructOut_elbAcc = robotStruct_elbAcc;
    } else {
      /* '<S214>:1:108' */
      *robotStructOut_shoAcc = (robotStruct_shoVel[0] - robotStruct_shoVel[1]) /
        stepDuration;

      /* '<S214>:1:109' */
      *robotStructOut_elbAcc = (robotStruct_elbVel[0] - robotStruct_elbVel[1]) /
        stepDuration;
    }
  } else {
    /* '<S214>:1:112' */
    stepDuration = (servoValues[0] - servoValues[4]) * 0.00088541674613952634;

    /* '<S214>:1:113' */
    *robotStructOut_shoAcc = (robotStruct_shoVel[0] - robotStruct_shoVel[4]) /
      stepDuration;

    /* '<S214>:1:114' */
    *robotStructOut_elbAcc = (robotStruct_elbVel[0] - robotStruct_elbVel[4]) /
      stepDuration;
  }

  /* '<S214>:1:117' */
  /* '<S214>:1:118' */
}

/* Function for MATLAB Function: '<S210>/Robot_data_builder' */
static void gbyk_v4b_calculateVelAcc_n(const real_T robotStruct_shoPos[5], const
  real_T robotStruct_elbPos[5], const real_T robotStruct_shoVel[5], const real_T
  robotStruct_elbVel[5], real_T robotStruct_shoAcc, real_T robotStruct_elbAcc,
  real_T robotStruct_bHasSecondary, const real_T servoValues[5], const real_T
  robotData[6], real_T robotStructOut_shoPos[5], real_T robotStructOut_elbPos[5],
  real_T robotStructOut_shoVel[5], real_T robotStructOut_elbVel[5], real_T
  *robotStructOut_shoAcc, real_T *robotStructOut_elbAcc, real_T
  *robotStructOut_bHasSecondary)
{
  real_T stepDuration;
  real_T shoVel;
  real_T elbVel;
  int32_T i;

  /* matches from PMAC code */
  /* '<S214>:1:78' */
  for (i = 0; i < 5; i++) {
    robotStructOut_shoPos[i] = robotStruct_shoPos[i];
    robotStructOut_elbPos[i] = robotStruct_elbPos[i];
  }

  *robotStructOut_bHasSecondary = robotStruct_bHasSecondary;

  /* do not name this anything that will make it the first variable name in */
  /* this method alphabetically. Seriously. With the name "duration" compiling */
  /* a model would work in 2010a, but nothing higher. Most models would compile, */
  /* but the verification task would not! */
  /* '<S214>:1:84' */
  stepDuration = 0.0;
  if (robotStruct_bHasSecondary != 0.0) {
    /* '<S214>:1:87' */
    stepDuration = (servoValues[0] - servoValues[1]) * 0.00088541674613952634;
    if (stepDuration == 0.0) {
      /* '<S214>:1:88' */
      /* '<S214>:1:89' */
      shoVel = robotStruct_shoVel[0];

      /* '<S214>:1:90' */
      elbVel = robotStruct_elbVel[0];
    } else {
      /* '<S214>:1:92' */
      shoVel = (robotStruct_shoPos[0] - robotStruct_shoPos[1]) / stepDuration;

      /* '<S214>:1:93' */
      elbVel = (robotStruct_elbPos[0] - robotStruct_elbPos[1]) / stepDuration;
    }
  } else {
    /* '<S214>:1:96' */
    shoVel = robotData[2];

    /* '<S214>:1:97' */
    elbVel = robotData[3];
  }

  /* '<S214>:1:100' */
  /* '<S214>:1:71' */
  /* '<S214>:1:72' */
  for (i = 0; i < 5; i++) {
    robotStructOut_shoVel[i] = robotStruct_shoVel[i];
  }

  gbyk_v4b_circshift(robotStructOut_shoVel);

  /* '<S214>:1:73' */
  robotStructOut_shoVel[0] = shoVel;

  /* '<S214>:1:101' */
  /* '<S214>:1:71' */
  /* '<S214>:1:72' */
  for (i = 0; i < 5; i++) {
    robotStructOut_elbVel[i] = robotStruct_elbVel[i];
  }

  gbyk_v4b_circshift(robotStructOut_elbVel);

  /* '<S214>:1:73' */
  robotStructOut_elbVel[0] = elbVel;
  if (robotStruct_bHasSecondary != 0.0) {
    if (stepDuration == 0.0) {
      /* '<S214>:1:104' */
      /* '<S214>:1:105' */
      *robotStructOut_shoAcc = robotStruct_shoAcc;

      /* '<S214>:1:106' */
      *robotStructOut_elbAcc = robotStruct_elbAcc;
    } else {
      /* '<S214>:1:108' */
      *robotStructOut_shoAcc = (robotStruct_shoVel[0] - robotStruct_shoVel[1]) /
        stepDuration;

      /* '<S214>:1:109' */
      *robotStructOut_elbAcc = (robotStruct_elbVel[0] - robotStruct_elbVel[1]) /
        stepDuration;
    }
  } else {
    /* '<S214>:1:112' */
    stepDuration = (servoValues[0] - servoValues[4]) * 0.00088541674613952634;

    /* '<S214>:1:113' */
    *robotStructOut_shoAcc = (robotStruct_shoVel[0] - robotStruct_shoVel[4]) /
      stepDuration;

    /* '<S214>:1:114' */
    *robotStructOut_elbAcc = (robotStruct_elbVel[0] - robotStruct_elbVel[4]) /
      stepDuration;
  }

  /* '<S214>:1:117' */
  /* '<S214>:1:118' */
}

/* Function for MATLAB Function: '<S210>/filter_velocities' */
static void gbyk_v4b_circshift_d(real_T a[3])
{
  real_T buffer;
  buffer = a[0];
  a[0] = a[1];
  a[1] = a[2];
  a[2] = buffer;
}

/* Function for MATLAB Function: '<S210>/filter_velocities' */
static void gbyk_v4b_updateValues(shSrZ99dE4twa6ELJRaXlMD_gbyk_v4b_T
  *robotStruct, const real_T robotData[10], uint32_T servoCounter, real_T POLES)
{
  real_T b[3];
  real_T c[3];
  real_T y;

  /* '<S215>:1:42' */
  if (!(robotStruct->servoCounter[(int32_T)(POLES + 1.0) - 1] == servoCounter))
  {
    /* '<S215>:1:47' */
    /* '<S215>:1:37' */
    /* '<S215>:1:38' */
    gbyk_v4b_circshift_d(robotStruct->servoCounter);

    /* '<S215>:1:39' */
    robotStruct->servoCounter[2] = servoCounter;

    /* all filter constants from http://www-users.cs.york.ac.uk/~fisher/cgi-bin/mkfscript */
    /* GAIN = 4.143204922e+03; % 1KHz gain */
    /* 1.129 KHz gain (PMAC speed) */
    /* FILTER_VALUES = [-0.9565436765, 1.9555782403]; % 1KHz */
    /*  1.129 KHz */
    /* '<S215>:1:63' */
    y = robotData[2] / 1342.624471;

    /* '<S215>:1:37' */
    /* '<S215>:1:38' */
    b[0] = robotStruct->shoVel[0];
    b[1] = robotStruct->shoVel[1];
    b[2] = robotStruct->shoVel[2];
    gbyk_v4b_circshift_d(b);

    /* '<S215>:1:39' */
    b[2] = y;

    /* '<S215>:1:64' */
    /* '<S215>:1:37' */
    /* '<S215>:1:38' */
    c[0] = robotStruct->shoVelFilt[0];
    c[1] = robotStruct->shoVelFilt[1];
    c[2] = robotStruct->shoVelFilt[2];
    gbyk_v4b_circshift_d(c);

    /* '<S215>:1:39' */
    c[2] = 0.0;

    /* '<S215>:1:66' */
    c[(int32_T)(POLES + 1.0) - 1] = (((b[1] * 2.0 + b[0]) + y) + c[0] *
      -0.9243128082) + c[1] * 1.9213335686;
    if (rtIsNaN(c[(int32_T)(POLES + 1.0) - 1]) || rtIsInf(c[(int32_T)(POLES +
          1.0) - 1])) {
      /* '<S215>:1:73' */
      c[(int32_T)(POLES + 1.0) - 1] = 0.0;
    }

    /* '<S215>:1:49' */
    robotStruct->shoVel[0] = b[0];
    robotStruct->shoVel[1] = b[1];
    robotStruct->shoVel[2] = b[2];

    /* '<S215>:1:49' */
    robotStruct->shoVelFilt[0] = c[0];
    robotStruct->shoVelFilt[1] = c[1];
    robotStruct->shoVelFilt[2] = c[2];

    /* all filter constants from http://www-users.cs.york.ac.uk/~fisher/cgi-bin/mkfscript */
    /* GAIN = 4.143204922e+03; % 1KHz gain */
    /* 1.129 KHz gain (PMAC speed) */
    /* FILTER_VALUES = [-0.9565436765, 1.9555782403]; % 1KHz */
    /*  1.129 KHz */
    /* '<S215>:1:63' */
    y = robotData[3] / 1342.624471;

    /* '<S215>:1:37' */
    /* '<S215>:1:38' */
    b[0] = robotStruct->elbVel[0];
    b[1] = robotStruct->elbVel[1];
    b[2] = robotStruct->elbVel[2];
    gbyk_v4b_circshift_d(b);

    /* '<S215>:1:39' */
    b[2] = y;

    /* '<S215>:1:64' */
    /* '<S215>:1:37' */
    /* '<S215>:1:38' */
    c[0] = robotStruct->elbVelFilt[0];
    c[1] = robotStruct->elbVelFilt[1];
    c[2] = robotStruct->elbVelFilt[2];
    gbyk_v4b_circshift_d(c);

    /* '<S215>:1:39' */
    c[2] = 0.0;

    /* '<S215>:1:66' */
    c[(int32_T)(POLES + 1.0) - 1] = (((b[1] * 2.0 + b[0]) + y) + c[0] *
      -0.9243128082) + c[1] * 1.9213335686;
    if (rtIsNaN(c[(int32_T)(POLES + 1.0) - 1]) || rtIsInf(c[(int32_T)(POLES +
          1.0) - 1])) {
      /* '<S215>:1:73' */
      c[(int32_T)(POLES + 1.0) - 1] = 0.0;
    }

    /* '<S215>:1:50' */
    robotStruct->elbVel[0] = b[0];
    robotStruct->elbVel[1] = b[1];
    robotStruct->elbVel[2] = b[2];

    /* '<S215>:1:50' */
    robotStruct->elbVelFilt[0] = c[0];
    robotStruct->elbVelFilt[1] = c[1];
    robotStruct->elbVelFilt[2] = c[2];
  } else {
    /* '<S215>:1:43' */
  }
}

/* Initial conditions for enable system: '<S66>/read_pmac' */
void gbyk_v4b_read_pmac_Init(void)
{
  int32_T i;
  static const sbr0BdzAW6GQX2fQakj4o6C_gbyk_v4b_T tmp = { { 0.0, 0.0, 0.0, 0.0,
      0.0 }, { 0.0, 0.0, 0.0, 0.0, 0.0 }, { 0.0, 0.0, 0.0, 0.0, 0.0 }, { 0.0,
      0.0, 0.0, 0.0, 0.0 }, 0.0, 0.0, 0.0 };

  static const shSrZ99dE4twa6ELJRaXlMD_gbyk_v4b_T tmp_0 = { { 0.0, 0.0, 0.0 }, {
      0.0, 0.0, 0.0 }, { 0.0, 0.0, 0.0 }, { 0.0, 0.0, 0.0 }, { 0.0, 0.0, 0.0 } };

  /* InitializeConditions for UnitDelay: '<S216>/Output' */
  gbyk_v4b_DW.Output_DSTATE_k = gbyk_v4b_P.Output_InitialCondition_bg;

  /* InitializeConditions for UnitDelay: '<S212>/Unit Delay' */
  gbyk_v4b_DW.UnitDelay_DSTATE = gbyk_v4b_P.UnitDelay_InitialCondition_p;

  /* InitializeConditions for UnitDelay: '<S212>/Unit Delay1' */
  gbyk_v4b_DW.UnitDelay1_DSTATE = gbyk_v4b_P.UnitDelay1_InitialCondition;

  /* InitializeConditions for MATLAB Function: '<S210>/Monitor_status' */
  gbyk_v4b_DW.no_update_count = 0.0;
  gbyk_v4b_DW.last_servo_counter = 0U;

  /* InitializeConditions for MATLAB Function: '<S210>/Robot_data_builder' */
  gbyk_v4b_DW.robot1Struct = tmp;
  gbyk_v4b_DW.robot2Struct = gbyk_v4b_DW.robot1Struct;
  gbyk_v4b_DW.robot1StructPrimary = gbyk_v4b_DW.robot1Struct;
  gbyk_v4b_DW.robot2StructPrimary = gbyk_v4b_DW.robot1Struct;
  for (i = 0; i < 5; i++) {
    gbyk_v4b_DW.servoValuesR1[i] = 0.0;
    gbyk_v4b_DW.servoValuesR2[i] = 0.0;
  }

  /* End of InitializeConditions for MATLAB Function: '<S210>/Robot_data_builder' */

  /* InitializeConditions for MATLAB Function: '<S210>/filter_velocities' */
  gbyk_v4b_DW.robot1Struct_a = tmp_0;
  gbyk_v4b_DW.robot2Struct_o = gbyk_v4b_DW.robot1Struct_a;
}

/* Start for enable system: '<S66>/read_pmac' */
void gbyk_v4b_read_pmac_Start(void)
{
  /* Level2 S-Function Block: '<S210>/S-Function' (mcc_pollall) */
  {
    SimStruct *rts = gbyk_v4b_M->childSfunctions[26];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S212>/Write' (mcc_writemem) */
  {
    SimStruct *rts = gbyk_v4b_M->childSfunctions[27];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for IfAction SubSystem: '<S212>/Read DPRAM' */

  /* Level2 S-Function Block: '<S217>/Read' (mcc_readmem) */
  {
    SimStruct *rts = gbyk_v4b_M->childSfunctions[24];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* End of Start for SubSystem: '<S212>/Read DPRAM' */

  /* Start for IfAction SubSystem: '<S212>/Write DPRAM' */

  /* Level2 S-Function Block: '<S219>/Write' (mcc_writemem) */
  {
    SimStruct *rts = gbyk_v4b_M->childSfunctions[25];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* End of Start for SubSystem: '<S212>/Write DPRAM' */

  /* InitializeConditions for Enabled SubSystem: '<S66>/read_pmac' */
  gbyk_v4b_read_pmac_Init();

  /* End of InitializeConditions for SubSystem: '<S66>/read_pmac' */
}

/* Outputs for enable system: '<S66>/read_pmac' */
void gbyk_v4b_read_pmac(void)
{
  real32_T y;
  uint32_T temp;
  real_T bR2HasSecondardy;
  real_T bHasSecondardy;
  real_T v;
  int32_T i;
  real_T tmp[5];
  real_T tmp_0[5];
  real_T tmp_1[5];
  real_T tmp_2[5];
  uint32_T u1;

  /* Outputs for Enabled SubSystem: '<S66>/read_pmac' incorporates:
   *  EnablePort: '<S210>/Enable'
   */
  if (gbyk_v4b_B.Compare_c) {
    /* DataTypeConversion: '<S210>/Data Type Conversion' incorporates:
     *  Constant: '<S230>/Arm Encoder Orientation 1'
     *  Constant: '<S230>/Arm Encoder Orientation 2'
     *  Constant: '<S230>/Arm primary encoder counts'
     *  Constant: '<S230>/Arm secondary encoder counts'
     */
    gbyk_v4b_B.DataTypeConversion_a5[0] = (real32_T)gbyk_v4b_B.ArmOrientation_b;
    gbyk_v4b_B.DataTypeConversion_a5[1] = (real32_T)gbyk_v4b_B.M1orientation_h;
    gbyk_v4b_B.DataTypeConversion_a5[2] = (real32_T)gbyk_v4b_B.M2Orientation_l;
    gbyk_v4b_B.DataTypeConversion_a5[3] = (real32_T)gbyk_v4b_B.M1GearRatio_b;
    gbyk_v4b_B.DataTypeConversion_a5[4] = (real32_T)gbyk_v4b_B.M2GearRatio_p;
    gbyk_v4b_B.DataTypeConversion_a5[5] = (real32_T)gbyk_v4b_B.HasSecondaryEnc_n;
    gbyk_v4b_B.DataTypeConversion_a5[6] = (real32_T)
      gbyk_v4b_P.ArmEncoderOrientation1_Value;
    gbyk_v4b_B.DataTypeConversion_a5[7] = (real32_T)
      gbyk_v4b_P.ArmEncoderOrientation2_Value;
    gbyk_v4b_B.DataTypeConversion_a5[8] = (real32_T)
      gbyk_v4b_P.Armprimaryencodercounts_Value;
    gbyk_v4b_B.DataTypeConversion_a5[9] = (real32_T)
      gbyk_v4b_P.Armsecondaryencodercounts_Value;

    /* DataTypeConversion: '<S210>/Data Type Conversion1' incorporates:
     *  Constant: '<S231>/Arm Encoder Orientation 1'
     *  Constant: '<S231>/Arm Encoder Orientation 2'
     *  Constant: '<S231>/Arm primary encoder counts'
     *  Constant: '<S231>/Arm secondary encoder counts'
     */
    gbyk_v4b_B.DataTypeConversion1_i1[0] = (real32_T)gbyk_v4b_B.ArmOrientation_l;
    gbyk_v4b_B.DataTypeConversion1_i1[1] = (real32_T)gbyk_v4b_B.M1orientation_n;
    gbyk_v4b_B.DataTypeConversion1_i1[2] = (real32_T)gbyk_v4b_B.M2Orientation_cw;
    gbyk_v4b_B.DataTypeConversion1_i1[3] = (real32_T)gbyk_v4b_B.M1GearRatio_k;
    gbyk_v4b_B.DataTypeConversion1_i1[4] = (real32_T)gbyk_v4b_B.M2GearRatio_l;
    gbyk_v4b_B.DataTypeConversion1_i1[5] = (real32_T)
      gbyk_v4b_B.HasSecondaryEnc_f;
    gbyk_v4b_B.DataTypeConversion1_i1[6] = (real32_T)
      gbyk_v4b_P.ArmEncoderOrientation1_Value_f;
    gbyk_v4b_B.DataTypeConversion1_i1[7] = (real32_T)
      gbyk_v4b_P.ArmEncoderOrientation2_Value_i;
    gbyk_v4b_B.DataTypeConversion1_i1[8] = (real32_T)
      gbyk_v4b_P.Armprimaryencodercounts_Value_j;
    gbyk_v4b_B.DataTypeConversion1_i1[9] = (real32_T)
      gbyk_v4b_P.Armsecondaryencodercounts_Value_i;

    /* DataTypeConversion: '<S210>/Data Type Conversion2' incorporates:
     *  Constant: '<S210>/step duration'
     */
    gbyk_v4b_B.DataTypeConversion2_h = (real32_T)gbyk_v4b_P.stepduration_Value;

    /* Level2 S-Function Block: '<S210>/S-Function' (mcc_pollall) */
    {
      SimStruct *rts = gbyk_v4b_M->childSfunctions[26];
      sfcnOutputs(rts, 1);
    }

    /* DataTypeConversion: '<S212>/Data Type Conversion' incorporates:
     *  Constant: '<S212>/DPRAM WatchDog offset'
     */
    bR2HasSecondardy = gbyk_v4b_P.DPRAMWatchDogoffset_Value;
    if (bR2HasSecondardy < 4.294967296E+9) {
      if (bR2HasSecondardy >= 0.0) {
        temp = (uint32_T)bR2HasSecondardy;
      } else {
        temp = 0U;
      }
    } else {
      temp = MAX_uint32_T;
    }

    gbyk_v4b_B.DataTypeConversion_l = temp;

    /* End of DataTypeConversion: '<S212>/Data Type Conversion' */

    /* UnitDelay: '<S216>/Output' */
    gbyk_v4b_B.Output_b = gbyk_v4b_DW.Output_DSTATE_k;

    /* MATLAB Function: '<S212>/TypeCast' */
    /* MATLAB Function 'DataLogging/Poll KINARM/PMAC Subsystem/read_pmac/DPRAM Access Subsystem/TypeCast': '<S218>:1' */
    /*  EML determines output class and size based on first usage */
    /*  for some reason the typecast is not setting it correctly, so we  */
    /*  explicitly define it first. */
    /*  in order for the typecast to work, both temp and y must be 32 bit */
    /* '<S218>:1:9' */
    temp = gbyk_v4b_B.Output_b;

    /* '<S218>:1:10' */
    memcpy(&y, &temp, (size_t)1 * sizeof(real32_T));
    gbyk_v4b_B.y_j = y;

    /* Level2 S-Function Block: '<S212>/Write' (mcc_writemem) */
    {
      SimStruct *rts = gbyk_v4b_M->childSfunctions[27];
      sfcnOutputs(rts, 1);
    }

    /* Sum: '<S220>/FixPt Sum1' incorporates:
     *  Constant: '<S220>/FixPt Constant'
     */
    gbyk_v4b_B.FixPtSum1_ea = (uint16_T)((uint32_T)gbyk_v4b_B.Output_b +
      gbyk_v4b_P.FixPtConstant_Value_c);

    /* Switch: '<S221>/FixPt Switch' incorporates:
     *  Constant: '<S221>/Constant'
     */
    if (gbyk_v4b_B.FixPtSum1_ea > gbyk_v4b_P.WrapToZero_Threshold_d) {
      gbyk_v4b_B.FixPtSwitch_j = gbyk_v4b_P.Constant_Value_j;
    } else {
      gbyk_v4b_B.FixPtSwitch_j = gbyk_v4b_B.FixPtSum1_ea;
    }

    /* End of Switch: '<S221>/FixPt Switch' */

    /* UnitDelay: '<S212>/Unit Delay' */
    gbyk_v4b_B.UnitDelay = gbyk_v4b_DW.UnitDelay_DSTATE;

    /* If: '<S212>/If' incorporates:
     *  Constant: '<S212>/Read Switch'
     */
    if (gbyk_v4b_P.ReadSwitch_Value > gbyk_v4b_B.UnitDelay) {
      /* Outputs for IfAction SubSystem: '<S212>/Read DPRAM' incorporates:
       *  ActionPort: '<S217>/Action Port'
       */
      /* DataTypeConversion: '<S217>/Data Type Conversion' incorporates:
       *  Constant: '<S212>/DPRAM Read Offset'
       */
      bR2HasSecondardy = gbyk_v4b_P.DPRAMReadOffset_Value;
      if (bR2HasSecondardy < 4.294967296E+9) {
        if (bR2HasSecondardy >= 0.0) {
          temp = (uint32_T)bR2HasSecondardy;
        } else {
          temp = 0U;
        }
      } else {
        temp = MAX_uint32_T;
      }

      gbyk_v4b_B.DataTypeConversion_pj = temp;

      /* End of DataTypeConversion: '<S217>/Data Type Conversion' */

      /* DataTypeConversion: '<S217>/Data Type Conversion2' incorporates:
       *  Constant: '<S212>/Read as UInt32'
       */
      bR2HasSecondardy = gbyk_v4b_P.ReadasUInt32_Value;
      if (bR2HasSecondardy < 4.294967296E+9) {
        if (bR2HasSecondardy >= 0.0) {
          temp = (uint32_T)bR2HasSecondardy;
        } else {
          temp = 0U;
        }
      } else {
        temp = MAX_uint32_T;
      }

      gbyk_v4b_B.DataTypeConversion2_pm = temp;

      /* End of DataTypeConversion: '<S217>/Data Type Conversion2' */

      /* Level2 S-Function Block: '<S217>/Read' (mcc_readmem) */
      {
        SimStruct *rts = gbyk_v4b_M->childSfunctions[24];
        sfcnOutputs(rts, 1);
      }

      /* DataTypeConversion: '<S217>/Data Type Conversion1' */
      gbyk_v4b_B.DataTypeConversion1_j = gbyk_v4b_B.Read_h;

      /* End of Outputs for SubSystem: '<S212>/Read DPRAM' */

      /* Update for IfAction SubSystem: '<S212>/Read DPRAM' incorporates:
       *  Update for ActionPort: '<S217>/Action Port'
       */
      /* Update for If: '<S212>/If' */
      srUpdateBC(gbyk_v4b_DW.ReadDPRAM_SubsysRanBC);

      /* End of Update for SubSystem: '<S212>/Read DPRAM' */
    }

    /* End of If: '<S212>/If' */

    /* Gain: '<S212>/DPRAM Read Value' */
    gbyk_v4b_B.DPRAMReadValue = gbyk_v4b_P.DPRAMReadValue_Gain *
      gbyk_v4b_B.DataTypeConversion1_j;

    /* UnitDelay: '<S212>/Unit Delay1' */
    gbyk_v4b_B.UnitDelay1 = gbyk_v4b_DW.UnitDelay1_DSTATE;

    /* If: '<S212>/If1' incorporates:
     *  Constant: '<S212>/Write Switch'
     */
    if (gbyk_v4b_P.WriteSwitch_Value > gbyk_v4b_B.UnitDelay1) {
      /* Outputs for IfAction SubSystem: '<S212>/Write DPRAM' incorporates:
       *  ActionPort: '<S219>/Action Port'
       */
      /* DataTypeConversion: '<S219>/Data Type Conversion' incorporates:
       *  Constant: '<S212>/DPRAM Write Offset'
       */
      bR2HasSecondardy = gbyk_v4b_P.DPRAMWriteOffset_Value;
      if (bR2HasSecondardy < 4.294967296E+9) {
        if (bR2HasSecondardy >= 0.0) {
          temp = (uint32_T)bR2HasSecondardy;
        } else {
          temp = 0U;
        }
      } else {
        temp = MAX_uint32_T;
      }

      gbyk_v4b_B.DataTypeConversion_dd = temp;

      /* End of DataTypeConversion: '<S219>/Data Type Conversion' */

      /* DataTypeConversion: '<S219>/Data Type Conversion1' incorporates:
       *  Constant: '<S212>/DPRAM Write Value'
       */
      gbyk_v4b_B.DataTypeConversion1_o = (real32_T)
        gbyk_v4b_P.DPRAMWriteValue_Value;

      /* Level2 S-Function Block: '<S219>/Write' (mcc_writemem) */
      {
        SimStruct *rts = gbyk_v4b_M->childSfunctions[25];
        sfcnOutputs(rts, 1);
      }

      /* End of Outputs for SubSystem: '<S212>/Write DPRAM' */

      /* Update for IfAction SubSystem: '<S212>/Write DPRAM' incorporates:
       *  Update for ActionPort: '<S219>/Action Port'
       */
      /* Update for If: '<S212>/If1' */
      srUpdateBC(gbyk_v4b_DW.WriteDPRAM_SubsysRanBC);

      /* End of Update for SubSystem: '<S212>/Write DPRAM' */
    }

    for (i = 0; i < 6; i++) {
      /* DataTypeConversion: '<S210>/Conversion1' */
      gbyk_v4b_B.Conversion1[i] = gbyk_v4b_B.SFunction_o6[i];

      /* DataTypeConversion: '<S210>/Conversion2' */
      gbyk_v4b_B.Conversion2[i] = gbyk_v4b_B.SFunction_o5[i];
    }

    /* End of If: '<S212>/If1' */

    /* DataTypeConversion: '<S210>/Conversion7' */
    gbyk_v4b_B.Conversion7[0] = gbyk_v4b_B.SFunction_o4[0];
    gbyk_v4b_B.Conversion7[1] = gbyk_v4b_B.SFunction_o4[1];
    gbyk_v4b_B.Conversion7[2] = gbyk_v4b_B.SFunction_o4[2];
    gbyk_v4b_B.Conversion7[3] = gbyk_v4b_B.SFunction_o4[3];

    /* DataTypeConversion: '<S210>/Convert2' */
    gbyk_v4b_B.Convert2_n[0] = gbyk_v4b_B.SFunction_o9[0];
    gbyk_v4b_B.Convert2_n[1] = gbyk_v4b_B.SFunction_o9[1];
    gbyk_v4b_B.Convert2_n[2] = gbyk_v4b_B.SFunction_o9[2];
    for (i = 0; i < 10; i++) {
      /* DataTypeConversion: '<S210>/Data Type Conversion3' */
      gbyk_v4b_B.DataTypeConversion3_d[i] = gbyk_v4b_B.SFunction_o1[i];

      /* DataTypeConversion: '<S210>/Data Type Conversion4' */
      gbyk_v4b_B.DataTypeConversion4_g[i] = gbyk_v4b_B.SFunction_o2[i];
    }

    /* MinMax: '<S210>/MinMax' */
    temp = gbyk_v4b_B.SFunction_o3[0];
    u1 = gbyk_v4b_B.SFunction_o3[1];
    if (!(temp >= u1)) {
      temp = u1;
    }

    gbyk_v4b_B.MinMax_b = temp;

    /* End of MinMax: '<S210>/MinMax' */

    /* MinMax: '<S210>/MinMax1' */
    temp = gbyk_v4b_B.SFunction_o3[0];
    u1 = gbyk_v4b_B.SFunction_o3[1];
    if (!(temp >= u1)) {
      temp = u1;
    }

    gbyk_v4b_B.MinMax1 = temp;

    /* End of MinMax: '<S210>/MinMax1' */

    /* MATLAB Function: '<S210>/Monitor_status' incorporates:
     *  Constant: '<S210>/robot_count'
     */
    /* MATLAB Function 'DataLogging/Poll KINARM/PMAC Subsystem/read_pmac/Monitor_status': '<S213>:1' */
    /* '<S213>:1:14' */
    /* '<S213>:1:15' */
    /* '<S213>:1:16' */
    gbyk_v4b_B.force_scale = 1.0;

    /* plcc versions >1000 are custom */
    if ((gbyk_v4b_B.SFunction_o10 >= 6.0F) && (gbyk_v4b_B.SFunction_o10 <
         1000.0F)) {
      /* '<S213>:1:19' */
      /* if the task is running and the servo amp counter is not */
      if ((gbyk_v4b_B.SFunction_o9[2] == 4U) && (gbyk_v4b_DW.last_servo_counter ==
           gbyk_v4b_B.MinMax_b)) {
        /* '<S213>:1:21' */
        /* '<S213>:1:22' */
        gbyk_v4b_DW.no_update_count++;

        /* after 5 cycles with the counter not running we should kill forces. */
        if (gbyk_v4b_DW.no_update_count >= 5.0) {
          /* '<S213>:1:24' */
          /* '<S213>:1:25' */
          gbyk_v4b_B.force_scale = 0.0;
        }
      } else {
        /* '<S213>:1:28' */
        gbyk_v4b_DW.no_update_count = 0.0;
      }

      /* '<S213>:1:30' */
      gbyk_v4b_DW.last_servo_counter = gbyk_v4b_B.MinMax_b;
    }

    /* plcc versions >1000 are custom */
    if ((gbyk_v4b_B.SFunction_o10 >= 7.0F) && (gbyk_v4b_B.SFunction_o10 <
         1000.0F)) {
      /* '<S213>:1:34' */
      /* if it is unilateral and the robot state is faulted then kill the forces */
      if ((gbyk_v4b_P.robot_count_Value == 1.0) && ((int32_T)
           (gbyk_v4b_B.SFunction_o9[1] & 1U) == 1)) {
        /* '<S213>:1:36' */
        /* '<S213>:1:37' */
        gbyk_v4b_B.force_scale = 0.0;

        /* if the system is bilateral and either robot is faulted, kill forces. */
      } else {
        if ((gbyk_v4b_P.robot_count_Value == 2.0) && ((int32_T)
             (gbyk_v4b_B.SFunction_o9[1] & 3U) != 0)) {
          /* '<S213>:1:39' */
          /* '<S213>:1:40' */
          gbyk_v4b_B.force_scale = 0.0;
        }
      }
    }

    if (gbyk_v4b_B.SFunction_o10 == 0.0F) {
      /* '<S213>:1:44' */
      /* '<S213>:1:45' */
      gbyk_v4b_B.force_scale = 0.0;
    }

    /* End of MATLAB Function: '<S210>/Monitor_status' */

    /* MATLAB Function: '<S210>/Robot_data_builder' */
    bR2HasSecondardy = gbyk_v4b_B.HasSecondaryEnc_f;

    /* MATLAB Function 'DataLogging/Poll KINARM/PMAC Subsystem/read_pmac/Robot_data_builder': '<S214>:1' */
    if (gbyk_v4b_B.SFunction_o10 < 7.0F) {
      /* '<S214>:1:14' */
      /* '<S214>:1:15' */
      /* '<S214>:1:16' */
      for (i = 0; i < 10; i++) {
        gbyk_v4b_B.robot1DataOut_p[i] = gbyk_v4b_B.DataTypeConversion3_d[i];
        gbyk_v4b_B.robot2DataOut_g[i] = gbyk_v4b_B.DataTypeConversion4_g[i];
      }

      /* '<S214>:1:17' */
      /* '<S214>:1:18' */
      for (i = 0; i < 6; i++) {
        gbyk_v4b_B.robot1PrimaryEncDataOut[i] = gbyk_v4b_B.Conversion2[i];
        gbyk_v4b_B.robot2PrimaryEncDataOut[i] = gbyk_v4b_B.Conversion1[i];
      }
    } else {
      if (gbyk_v4b_B.SFunction_o3[0] != gbyk_v4b_DW.servoValuesR1[0]) {
        /* '<S214>:1:22' */
        /* '<S214>:1:23' */
        bHasSecondardy = gbyk_v4b_B.HasSecondaryEnc_n;

        /* '<S214>:1:65' */
        /* '<S214>:1:66' */
        v = gbyk_v4b_B.DataTypeConversion3_d[0];

        /* '<S214>:1:71' */
        /* '<S214>:1:72' */
        gbyk_v4b_circshift(gbyk_v4b_DW.robot1Struct.shoPos);

        /* '<S214>:1:73' */
        gbyk_v4b_DW.robot1Struct.shoPos[0] = v;

        /* '<S214>:1:67' */
        /* '<S214>:1:71' */
        /* '<S214>:1:72' */
        gbyk_v4b_circshift(gbyk_v4b_DW.robot1Struct.elbPos);

        /* '<S214>:1:73' */
        gbyk_v4b_DW.robot1Struct.elbPos[0] = gbyk_v4b_B.DataTypeConversion3_d[1];

        /* '<S214>:1:68' */
        gbyk_v4b_DW.robot1Struct.bHasSecondary = bHasSecondardy;

        /* '<S214>:1:24' */
        /* '<S214>:1:65' */
        /* '<S214>:1:66' */
        /* '<S214>:1:71' */
        /* '<S214>:1:72' */
        gbyk_v4b_circshift(gbyk_v4b_DW.robot1StructPrimary.shoPos);

        /* '<S214>:1:73' */
        gbyk_v4b_DW.robot1StructPrimary.shoPos[0] = gbyk_v4b_B.Conversion2[0];

        /* '<S214>:1:67' */
        /* '<S214>:1:71' */
        /* '<S214>:1:72' */
        gbyk_v4b_circshift(gbyk_v4b_DW.robot1StructPrimary.elbPos);

        /* '<S214>:1:73' */
        gbyk_v4b_DW.robot1StructPrimary.elbPos[0] = gbyk_v4b_B.Conversion2[1];

        /* '<S214>:1:68' */
        gbyk_v4b_DW.robot1StructPrimary.bHasSecondary = 0.0;

        /* '<S214>:1:25' */
        /* '<S214>:1:71' */
        /* '<S214>:1:72' */
        gbyk_v4b_circshift(gbyk_v4b_DW.servoValuesR1);

        /* '<S214>:1:73' */
        gbyk_v4b_DW.servoValuesR1[0] = gbyk_v4b_B.SFunction_o3[0];

        /* '<S214>:1:26' */
        for (i = 0; i < 5; i++) {
          tmp[i] = gbyk_v4b_DW.robot1Struct.shoPos[i];
          tmp_0[i] = gbyk_v4b_DW.robot1Struct.elbPos[i];
          tmp_1[i] = gbyk_v4b_DW.robot1Struct.shoVel[i];
          tmp_2[i] = gbyk_v4b_DW.robot1Struct.elbVel[i];
        }

        gbyk_v4b_calculateVelAcc(tmp, tmp_0, tmp_1, tmp_2,
          gbyk_v4b_DW.robot1Struct.shoAcc, gbyk_v4b_DW.robot1Struct.elbAcc,
          gbyk_v4b_DW.robot1Struct.bHasSecondary, gbyk_v4b_DW.servoValuesR1,
          gbyk_v4b_B.DataTypeConversion3_d, gbyk_v4b_DW.robot1Struct.shoPos,
          gbyk_v4b_DW.robot1Struct.elbPos, gbyk_v4b_DW.robot1Struct.shoVel,
          gbyk_v4b_DW.robot1Struct.elbVel, &gbyk_v4b_DW.robot1Struct.shoAcc,
          &gbyk_v4b_DW.robot1Struct.elbAcc,
          &gbyk_v4b_DW.robot1Struct.bHasSecondary);

        /* '<S214>:1:27' */
        for (i = 0; i < 5; i++) {
          tmp[i] = gbyk_v4b_DW.robot1StructPrimary.shoPos[i];
          tmp_0[i] = gbyk_v4b_DW.robot1StructPrimary.elbPos[i];
          tmp_1[i] = gbyk_v4b_DW.robot1StructPrimary.shoVel[i];
          tmp_2[i] = gbyk_v4b_DW.robot1StructPrimary.elbVel[i];
        }

        gbyk_v4b_calculateVelAcc_n(tmp, tmp_0, tmp_1, tmp_2,
          gbyk_v4b_DW.robot1StructPrimary.shoAcc,
          gbyk_v4b_DW.robot1StructPrimary.elbAcc,
          gbyk_v4b_DW.robot1StructPrimary.bHasSecondary,
          gbyk_v4b_DW.servoValuesR1, gbyk_v4b_B.Conversion2,
          gbyk_v4b_DW.robot1StructPrimary.shoPos,
          gbyk_v4b_DW.robot1StructPrimary.elbPos,
          gbyk_v4b_DW.robot1StructPrimary.shoVel,
          gbyk_v4b_DW.robot1StructPrimary.elbVel,
          &gbyk_v4b_DW.robot1StructPrimary.shoAcc,
          &gbyk_v4b_DW.robot1StructPrimary.elbAcc,
          &gbyk_v4b_DW.robot1StructPrimary.bHasSecondary);
      }

      if (gbyk_v4b_B.SFunction_o3[1] != gbyk_v4b_DW.servoValuesR2[0]) {
        /* '<S214>:1:30' */
        /* '<S214>:1:31' */
        /* '<S214>:1:65' */
        /* '<S214>:1:66' */
        /* '<S214>:1:71' */
        /* '<S214>:1:72' */
        gbyk_v4b_circshift(gbyk_v4b_DW.robot2Struct.shoPos);

        /* '<S214>:1:73' */
        gbyk_v4b_DW.robot2Struct.shoPos[0] = gbyk_v4b_B.DataTypeConversion4_g[0];

        /* '<S214>:1:67' */
        /* '<S214>:1:71' */
        /* '<S214>:1:72' */
        gbyk_v4b_circshift(gbyk_v4b_DW.robot2Struct.elbPos);

        /* '<S214>:1:73' */
        gbyk_v4b_DW.robot2Struct.elbPos[0] = gbyk_v4b_B.DataTypeConversion4_g[1];

        /* '<S214>:1:68' */
        gbyk_v4b_DW.robot2Struct.bHasSecondary = bR2HasSecondardy;

        /* '<S214>:1:32' */
        /* '<S214>:1:65' */
        /* '<S214>:1:66' */
        /* '<S214>:1:71' */
        /* '<S214>:1:72' */
        gbyk_v4b_circshift(gbyk_v4b_DW.robot2StructPrimary.shoPos);

        /* '<S214>:1:73' */
        gbyk_v4b_DW.robot2StructPrimary.shoPos[0] = gbyk_v4b_B.Conversion1[0];

        /* '<S214>:1:67' */
        /* '<S214>:1:71' */
        /* '<S214>:1:72' */
        gbyk_v4b_circshift(gbyk_v4b_DW.robot2StructPrimary.elbPos);

        /* '<S214>:1:73' */
        gbyk_v4b_DW.robot2StructPrimary.elbPos[0] = gbyk_v4b_B.Conversion1[1];

        /* '<S214>:1:68' */
        gbyk_v4b_DW.robot2StructPrimary.bHasSecondary = 0.0;

        /* '<S214>:1:33' */
        /* '<S214>:1:71' */
        /* '<S214>:1:72' */
        gbyk_v4b_circshift(gbyk_v4b_DW.servoValuesR2);

        /* '<S214>:1:73' */
        gbyk_v4b_DW.servoValuesR2[0] = gbyk_v4b_B.SFunction_o3[1];

        /* '<S214>:1:34' */
        for (i = 0; i < 5; i++) {
          tmp[i] = gbyk_v4b_DW.robot2Struct.shoPos[i];
          tmp_0[i] = gbyk_v4b_DW.robot2Struct.elbPos[i];
          tmp_1[i] = gbyk_v4b_DW.robot2Struct.shoVel[i];
          tmp_2[i] = gbyk_v4b_DW.robot2Struct.elbVel[i];
        }

        gbyk_v4b_calculateVelAcc(tmp, tmp_0, tmp_1, tmp_2,
          gbyk_v4b_DW.robot2Struct.shoAcc, gbyk_v4b_DW.robot2Struct.elbAcc,
          gbyk_v4b_DW.robot2Struct.bHasSecondary, gbyk_v4b_DW.servoValuesR2,
          gbyk_v4b_B.DataTypeConversion4_g, gbyk_v4b_DW.robot2Struct.shoPos,
          gbyk_v4b_DW.robot2Struct.elbPos, gbyk_v4b_DW.robot2Struct.shoVel,
          gbyk_v4b_DW.robot2Struct.elbVel, &gbyk_v4b_DW.robot2Struct.shoAcc,
          &gbyk_v4b_DW.robot2Struct.elbAcc,
          &gbyk_v4b_DW.robot2Struct.bHasSecondary);

        /* '<S214>:1:35' */
        for (i = 0; i < 5; i++) {
          tmp[i] = gbyk_v4b_DW.robot2StructPrimary.shoPos[i];
          tmp_0[i] = gbyk_v4b_DW.robot2StructPrimary.elbPos[i];
          tmp_1[i] = gbyk_v4b_DW.robot2StructPrimary.shoVel[i];
          tmp_2[i] = gbyk_v4b_DW.robot2StructPrimary.elbVel[i];
        }

        gbyk_v4b_calculateVelAcc_n(tmp, tmp_0, tmp_1, tmp_2,
          gbyk_v4b_DW.robot2StructPrimary.shoAcc,
          gbyk_v4b_DW.robot2StructPrimary.elbAcc,
          gbyk_v4b_DW.robot2StructPrimary.bHasSecondary,
          gbyk_v4b_DW.servoValuesR2, gbyk_v4b_B.Conversion1,
          gbyk_v4b_DW.robot2StructPrimary.shoPos,
          gbyk_v4b_DW.robot2StructPrimary.elbPos,
          gbyk_v4b_DW.robot2StructPrimary.shoVel,
          gbyk_v4b_DW.robot2StructPrimary.elbVel,
          &gbyk_v4b_DW.robot2StructPrimary.shoAcc,
          &gbyk_v4b_DW.robot2StructPrimary.elbAcc,
          &gbyk_v4b_DW.robot2StructPrimary.bHasSecondary);
      }

      /* '<S214>:1:38' */
      /* '<S214>:1:52' */
      /* '<S214>:1:53' */
      for (i = 0; i < 10; i++) {
        gbyk_v4b_B.robot1DataOut_p[i] = gbyk_v4b_B.DataTypeConversion3_d[i];
        gbyk_v4b_B.robot2DataOut_g[i] = gbyk_v4b_B.DataTypeConversion4_g[i];
      }

      gbyk_v4b_B.robot1DataOut_p[2] = gbyk_v4b_DW.robot1Struct.shoVel[0];

      /* '<S214>:1:54' */
      gbyk_v4b_B.robot1DataOut_p[3] = gbyk_v4b_DW.robot1Struct.elbVel[0];

      /* '<S214>:1:55' */
      gbyk_v4b_B.robot1DataOut_p[4] = gbyk_v4b_DW.robot1Struct.shoAcc;

      /* '<S214>:1:56' */
      gbyk_v4b_B.robot1DataOut_p[5] = gbyk_v4b_DW.robot1Struct.elbAcc;

      /* '<S214>:1:39' */
      /* '<S214>:1:52' */
      /* '<S214>:1:53' */
      gbyk_v4b_B.robot2DataOut_g[2] = gbyk_v4b_DW.robot2Struct.shoVel[0];

      /* '<S214>:1:54' */
      gbyk_v4b_B.robot2DataOut_g[3] = gbyk_v4b_DW.robot2Struct.elbVel[0];

      /* '<S214>:1:55' */
      gbyk_v4b_B.robot2DataOut_g[4] = gbyk_v4b_DW.robot2Struct.shoAcc;

      /* '<S214>:1:56' */
      gbyk_v4b_B.robot2DataOut_g[5] = gbyk_v4b_DW.robot2Struct.elbAcc;

      /* '<S214>:1:41' */
      /* '<S214>:1:52' */
      /* '<S214>:1:53' */
      for (i = 0; i < 6; i++) {
        gbyk_v4b_B.robot1PrimaryEncDataOut[i] = gbyk_v4b_B.Conversion2[i];
        gbyk_v4b_B.robot2PrimaryEncDataOut[i] = gbyk_v4b_B.Conversion1[i];
      }

      gbyk_v4b_B.robot1PrimaryEncDataOut[2] =
        gbyk_v4b_DW.robot1StructPrimary.shoVel[0];

      /* '<S214>:1:54' */
      gbyk_v4b_B.robot1PrimaryEncDataOut[3] =
        gbyk_v4b_DW.robot1StructPrimary.elbVel[0];

      /* '<S214>:1:55' */
      gbyk_v4b_B.robot1PrimaryEncDataOut[4] =
        gbyk_v4b_DW.robot1StructPrimary.shoAcc;

      /* '<S214>:1:56' */
      gbyk_v4b_B.robot1PrimaryEncDataOut[5] =
        gbyk_v4b_DW.robot1StructPrimary.elbAcc;

      /* '<S214>:1:42' */
      /* '<S214>:1:52' */
      /* '<S214>:1:53' */
      gbyk_v4b_B.robot2PrimaryEncDataOut[2] =
        gbyk_v4b_DW.robot2StructPrimary.shoVel[0];

      /* '<S214>:1:54' */
      gbyk_v4b_B.robot2PrimaryEncDataOut[3] =
        gbyk_v4b_DW.robot2StructPrimary.elbVel[0];

      /* '<S214>:1:55' */
      gbyk_v4b_B.robot2PrimaryEncDataOut[4] =
        gbyk_v4b_DW.robot2StructPrimary.shoAcc;

      /* '<S214>:1:56' */
      gbyk_v4b_B.robot2PrimaryEncDataOut[5] =
        gbyk_v4b_DW.robot2StructPrimary.elbAcc;

      /* We used to provide a filtered velocity, but we can't with EtherCAT and */
      /* it was not being used anywhere anyway.  */
      /* '<S214>:1:46' */
      bR2HasSecondardy = gbyk_v4b_B.robot1DataOut_p[2];
      bHasSecondardy = gbyk_v4b_B.robot1DataOut_p[3];
      gbyk_v4b_B.robot1DataOut_p[6] = bR2HasSecondardy;
      gbyk_v4b_B.robot1DataOut_p[7] = bHasSecondardy;

      /* '<S214>:1:47' */
      bR2HasSecondardy = gbyk_v4b_B.robot2DataOut_g[2];
      bHasSecondardy = gbyk_v4b_B.robot2DataOut_g[3];
      gbyk_v4b_B.robot2DataOut_g[6] = bR2HasSecondardy;
      gbyk_v4b_B.robot2DataOut_g[7] = bHasSecondardy;
    }

    /* End of MATLAB Function: '<S210>/Robot_data_builder' */

    /* MATLAB Function: '<S210>/filter_velocities' */
    /* MATLAB Function 'DataLogging/Poll KINARM/PMAC Subsystem/read_pmac/filter_velocities': '<S215>:1' */
    if (gbyk_v4b_B.SFunction_o10 < 7.0F) {
      /* '<S215>:1:11' */
      /* '<S215>:1:12' */
      /* '<S215>:1:13' */
      for (i = 0; i < 10; i++) {
        gbyk_v4b_B.robot1DataOut[i] = gbyk_v4b_B.robot1DataOut_p[i];
        gbyk_v4b_B.robot2DataOut[i] = gbyk_v4b_B.robot2DataOut_g[i];
      }
    } else {
      /* '<S215>:1:17' */
      /* '<S215>:1:18' */
      for (i = 0; i < 10; i++) {
        gbyk_v4b_B.robot1DataOut[i] = gbyk_v4b_B.robot1DataOut_p[i];
        gbyk_v4b_B.robot2DataOut[i] = gbyk_v4b_B.robot2DataOut_g[i];
      }

      /* '<S215>:1:20' */
      gbyk_v4b_updateValues(&gbyk_v4b_DW.robot1Struct_a,
                            gbyk_v4b_B.robot1DataOut_p, gbyk_v4b_B.SFunction_o3
                            [0], 2.0);

      /* '<S215>:1:21' */
      gbyk_v4b_updateValues(&gbyk_v4b_DW.robot2Struct_o,
                            gbyk_v4b_B.robot2DataOut_g, gbyk_v4b_B.SFunction_o3
                            [1], 2.0);

      /* We used to provide a filtered velocity, but we can't with EtherCAT and */
      /* it was not being used anywhere anyway.  */
      /* '<S215>:1:25' */
      gbyk_v4b_B.robot1DataOut[6] = gbyk_v4b_DW.robot1Struct_a.shoVelFilt[2];
      gbyk_v4b_B.robot1DataOut[7] = gbyk_v4b_DW.robot1Struct_a.elbVelFilt[2];

      /* '<S215>:1:26' */
      gbyk_v4b_B.robot2DataOut[6] = gbyk_v4b_DW.robot2Struct_o.shoVelFilt[2];
      gbyk_v4b_B.robot2DataOut[7] = gbyk_v4b_DW.robot2Struct_o.elbVelFilt[2];
    }

    /* End of MATLAB Function: '<S210>/filter_velocities' */
    srUpdateBC(gbyk_v4b_DW.read_pmac_SubsysRanBC);
  }

  /* End of Outputs for SubSystem: '<S66>/read_pmac' */
}

/* Update for enable system: '<S66>/read_pmac' */
void gbyk_v4b_read_pmac_Update(void)
{
  /* Update for Enabled SubSystem: '<S66>/read_pmac' incorporates:
   *  Update for EnablePort: '<S210>/Enable'
   */
  if (gbyk_v4b_B.Compare_c) {
    /* Update for UnitDelay: '<S216>/Output' */
    gbyk_v4b_DW.Output_DSTATE_k = gbyk_v4b_B.FixPtSwitch_j;

    /* Update for UnitDelay: '<S212>/Unit Delay' incorporates:
     *  Constant: '<S212>/Read Switch'
     */
    gbyk_v4b_DW.UnitDelay_DSTATE = gbyk_v4b_P.ReadSwitch_Value;

    /* Update for UnitDelay: '<S212>/Unit Delay1' incorporates:
     *  Constant: '<S212>/Write Switch'
     */
    gbyk_v4b_DW.UnitDelay1_DSTATE = gbyk_v4b_P.WriteSwitch_Value;
  }

  /* End of Update for SubSystem: '<S66>/read_pmac' */
}

/* Termination for enable system: '<S66>/read_pmac' */
void gbyk_v4b_read_pmac_Term(void)
{
  /* Level2 S-Function Block: '<S210>/S-Function' (mcc_pollall) */
  {
    SimStruct *rts = gbyk_v4b_M->childSfunctions[26];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S212>/Write' (mcc_writemem) */
  {
    SimStruct *rts = gbyk_v4b_M->childSfunctions[27];
    sfcnTerminate(rts);
  }

  /* Terminate for IfAction SubSystem: '<S212>/Read DPRAM' */

  /* Level2 S-Function Block: '<S217>/Read' (mcc_readmem) */
  {
    SimStruct *rts = gbyk_v4b_M->childSfunctions[24];
    sfcnTerminate(rts);
  }

  /* End of Terminate for SubSystem: '<S212>/Read DPRAM' */

  /* Terminate for IfAction SubSystem: '<S212>/Write DPRAM' */

  /* Level2 S-Function Block: '<S219>/Write' (mcc_writemem) */
  {
    SimStruct *rts = gbyk_v4b_M->childSfunctions[25];
    sfcnTerminate(rts);
  }

  /* End of Terminate for SubSystem: '<S212>/Write DPRAM' */
}
