/*
 * Code generation for system system '<S34>/Force Sensor Control'
 *
 * Model                      : gbyk_v4b
 * Model version              : 1.2667
 * Simulink Coder version : 8.8.1 (R2015aSP1) 04-Sep-2015
 * C source code generated on : Tue Sep 15 15:02:19 2020
 *
 * Note that the functions contained in this file are part of a Simulink
 * model, and are not self-contained algorithms.
 */

#include "gbyk_v4b_ForceSensorControl.h"

/* Include model header file for global data */
#include "gbyk_v4b.h"
#include "gbyk_v4b_private.h"

/*
 * Initial conditions for atomic system:
 *    '<S202>/Create timestamp'
 *    '<S203>/Create timestamp'
 */
void gbyk_v4b_Createtimestamp_Init(DW_Createtimestamp_gbyk_v4b_T *localDW)
{
  localDW->start_time = 0U;
  localDW->last_time = 0U;
}

/*
 * Output and update for atomic system:
 *    '<S202>/Create timestamp'
 *    '<S203>/Create timestamp'
 */
void gbyk_v4b_Createtimestamp(const uint32_T rtu_times_in[3],
  B_Createtimestamp_gbyk_v4b_T *localB, DW_Createtimestamp_gbyk_v4b_T *localDW)
{
  uint32_T q0;
  uint32_T qY;

  /* MATLAB Function 'DataLogging/Poll KINARM/Force Sensor Control/Force Sensor 1 Subsystem/Create timestamp': '<S204>:1' */
  if ((localDW->start_time == 0U) && (rtu_times_in[1] > 0U)) {
    /* '<S204>:1:14' */
    /* '<S204>:1:15' */
    localDW->start_time = rtu_times_in[1];
  }

  if (rtu_times_in[1] < localDW->start_time) {
    /* '<S204>:1:18' */
    /* '<S204>:1:19' */
    localDW->start_time = 0U;
  }

  /* F/T sensor clock runs at 7Khz according to the manual, */
  /* using a 32 bit integer for this gives about 7 days before it will roll */
  /* over. This means we need to account for roll overs in order to make */
  /* analysis sane. */
  /* '<S204>:1:26' */
  q0 = rtu_times_in[1];
  qY = q0 - localDW->start_time;
  if (qY > q0) {
    qY = 0U;
  }

  localB->timestamp_out = (real_T)qY / 7000.0;

  /* '<S204>:1:27' */
  localDW->last_time = rtu_times_in[1];
}

/* Initial conditions for atomic system: '<S34>/Force Sensor Control' */
void gbyk_v4b_ForceSensorControl_Init(void)
{
  /* InitializeConditions for UnitDelay: '<S205>/Delay Input1' */
  gbyk_v4b_DW.DelayInput1_DSTATE = gbyk_v4b_P.DetectChange_vinit;

  /* InitializeConditions for MATLAB Function: '<S202>/Create timestamp' */
  gbyk_v4b_Createtimestamp_Init(&gbyk_v4b_DW.sf_Createtimestamp);

  /* InitializeConditions for UnitDelay: '<S209>/Delay Input1' */
  gbyk_v4b_DW.DelayInput1_DSTATE_n = gbyk_v4b_P.DetectChange_vinit_n;

  /* InitializeConditions for MATLAB Function: '<S203>/Create timestamp' */
  gbyk_v4b_Createtimestamp_Init(&gbyk_v4b_DW.sf_Createtimestamp_b);
}

/* Start for atomic system: '<S34>/Force Sensor Control' */
void gbyk_v4b_ForceSensorControl_Start(void)
{
  /* Start for Enabled SubSystem: '<S202>/If Action Subsystem' */

  /* Level2 S-Function Block: '<S206>/Send' (xpcudpbytesend) */
  {
    SimStruct *rts = gbyk_v4b_M->childSfunctions[20];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* End of Start for SubSystem: '<S202>/If Action Subsystem' */

  /* Level2 S-Function Block: '<S202>/Receive from Robot 1 Force Sensor' (xpcudpbytereceive) */
  {
    SimStruct *rts = gbyk_v4b_M->childSfunctions[22];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for Enabled SubSystem: '<S203>/Data Transfer Start Subsystem' */

  /* Level2 S-Function Block: '<S208>/Send' (xpcudpbytesend) */
  {
    SimStruct *rts = gbyk_v4b_M->childSfunctions[21];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* End of Start for SubSystem: '<S203>/Data Transfer Start Subsystem' */

  /* Level2 S-Function Block: '<S203>/Receive from Robot 2 Force Sensor' (xpcudpbytereceive) */
  {
    SimStruct *rts = gbyk_v4b_M->childSfunctions[23];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }
}

/* Outputs for atomic system: '<S34>/Force Sensor Control' */
void gbyk_v4b_ForceSensorControl(void)
{
  int32_T i;

  /* UnitDelay: '<S205>/Delay Input1' */
  gbyk_v4b_B.Uk1 = gbyk_v4b_DW.DelayInput1_DSTATE;

  /* RelationalOperator: '<S205>/FixPt Relational Operator' */
  gbyk_v4b_B.FixPtRelationalOperator = (uint8_T)(gbyk_v4b_B.ReadHasFT[0] !=
    gbyk_v4b_B.Uk1);

  /* Outputs for Enabled SubSystem: '<S202>/If Action Subsystem' incorporates:
   *  EnablePort: '<S206>/Enable'
   */
  if (gbyk_v4b_B.FixPtRelationalOperator > 0) {
    /* ReverseEndian: <S206>/Byte Reversal1 */

    /* 2 byte-wide input datatypes */
    ((uint16_T *)&gbyk_v4b_B.ByteReversal1_m)[0] =
      SWAP16(((uint16_T *)&gbyk_v4b_P.Constant_Value_md)[0]);

    /* Switch: '<S206>/Switch' incorporates:
     *  Constant: '<S206>/Constant2'
     *  Constant: '<S206>/Constant3'
     */
    if (gbyk_v4b_B.ReadHasFT[0] > gbyk_v4b_P.Switch_Threshold) {
      gbyk_v4b_B.Switch_n = gbyk_v4b_P.Constant3_Value;
    } else {
      gbyk_v4b_B.Switch_n = gbyk_v4b_P.Constant2_Value;
    }

    /* End of Switch: '<S206>/Switch' */

    /* ReverseEndian: <S206>/Byte Reversal */

    /* 2 byte-wide input datatypes */
    ((uint16_T *)&gbyk_v4b_B.ByteReversal_n)[0] =
      SWAP16(((uint16_T *)&gbyk_v4b_B.Switch_n)[0]);

    /* ReverseEndian: <S206>/Byte Reversal2 */

    /* 4 byte-wide input datatypes */
    ((uint32_T *)&gbyk_v4b_B.ByteReversal2)[0] =
      SWAP32(((uint32_T *)&gbyk_v4b_P.Constant1_Value_c)[0]);

    /* Pack: <S206>/Pack */
    (void) memcpy(&gbyk_v4b_B.Pack_f[0], &gbyk_v4b_B.ByteReversal1_m,
                  2);
    (void) memcpy(&gbyk_v4b_B.Pack_f[2], &gbyk_v4b_B.ByteReversal_n,
                  2);
    (void) memcpy(&gbyk_v4b_B.Pack_f[4], &gbyk_v4b_B.ByteReversal2,
                  4);

    /* Level2 S-Function Block: '<S206>/Send' (xpcudpbytesend) */
    {
      SimStruct *rts = gbyk_v4b_M->childSfunctions[20];
      sfcnOutputs(rts, 1);
    }

    srUpdateBC(gbyk_v4b_DW.IfActionSubsystem_SubsysRanBC);
  }

  /* End of Outputs for SubSystem: '<S202>/If Action Subsystem' */

  /* Level2 S-Function Block: '<S202>/Receive from Robot 1 Force Sensor' (xpcudpbytereceive) */
  {
    SimStruct *rts = gbyk_v4b_M->childSfunctions[22];
    sfcnOutputs(rts, 1);
  }

  /* Unpack: <S202>/Unpack */
  (void) memcpy(&gbyk_v4b_B.Unpack_o1_m[0],
                &gbyk_v4b_B.ReceivefromRobot1ForceSensor_o1[0],
                12);
  (void) memcpy(&gbyk_v4b_B.Unpack_o2_o[0],
                &gbyk_v4b_B.ReceivefromRobot1ForceSensor_o1[12],
                24);

  /* ReverseEndian: <S202>/Byte Reversal */

  /* 4 byte-wide input datatypes */
  {
    int_T i1;
    const int32_T *u0 = &gbyk_v4b_B.Unpack_o2_o[0];
    int32_T *y0 = &gbyk_v4b_B.ByteReversal[0];
    for (i1=0; i1 < 6; i1++) {
      ((uint32_T *)&y0[i1])[0] =
        SWAP32(((uint32_T *)&u0[i1])[0]);
    }
  }

  /* ReverseEndian: <S202>/Byte Reversal1 */

  /* 4 byte-wide input datatypes */
  ((uint32_T *)&gbyk_v4b_B.ByteReversal1[0])[0] =
    SWAP32(((uint32_T *)&gbyk_v4b_B.Unpack_o1_m[0])[0]);
  ((uint32_T *)&gbyk_v4b_B.ByteReversal1[1])[0] =
    SWAP32(((uint32_T *)&gbyk_v4b_B.Unpack_o1_m[1])[0]);
  ((uint32_T *)&gbyk_v4b_B.ByteReversal1[2])[0] =
    SWAP32(((uint32_T *)&gbyk_v4b_B.Unpack_o1_m[2])[0]);

  /* MATLAB Function: '<S202>/Create timestamp' */
  gbyk_v4b_Createtimestamp(gbyk_v4b_B.ByteReversal1,
    &gbyk_v4b_B.sf_Createtimestamp, &gbyk_v4b_DW.sf_Createtimestamp);

  /* Switch: '<S202>/Switch' incorporates:
   *  Constant: '<S202>/Constant'
   */
  if (gbyk_v4b_B.ReadHasFT[0] > gbyk_v4b_P.Switch_Threshold_m) {
    /* DataTypeConversion: '<S202>/Data Type Conversion' */
    for (i = 0; i < 6; i++) {
      gbyk_v4b_B.DataTypeConversion_e[i] = gbyk_v4b_B.ByteReversal[i];
      gbyk_v4b_B.Switch_p[i] = gbyk_v4b_B.DataTypeConversion_e[i];
    }

    /* End of DataTypeConversion: '<S202>/Data Type Conversion' */
    gbyk_v4b_B.Switch_p[6] = gbyk_v4b_B.sf_Createtimestamp.timestamp_out;
  } else {
    for (i = 0; i < 7; i++) {
      gbyk_v4b_B.Switch_p[i] = gbyk_v4b_P.Constant_Value_o[i];
    }
  }

  /* End of Switch: '<S202>/Switch' */

  /* UnitDelay: '<S209>/Delay Input1' */
  gbyk_v4b_B.Uk1_p = gbyk_v4b_DW.DelayInput1_DSTATE_n;

  /* RelationalOperator: '<S209>/FixPt Relational Operator' */
  gbyk_v4b_B.FixPtRelationalOperator_i = (uint8_T)(gbyk_v4b_B.ReadHasFT[1] !=
    gbyk_v4b_B.Uk1_p);

  /* Outputs for Enabled SubSystem: '<S203>/Data Transfer Start Subsystem' incorporates:
   *  EnablePort: '<S208>/Enable'
   */
  if (gbyk_v4b_B.FixPtRelationalOperator_i > 0) {
    /* ReverseEndian: <S208>/Byte Reversal1 */

    /* 2 byte-wide input datatypes */
    ((uint16_T *)&gbyk_v4b_B.ByteReversal1_a)[0] =
      SWAP16(((uint16_T *)&gbyk_v4b_P.Constant_Value_cn)[0]);

    /* Switch: '<S208>/Switch' incorporates:
     *  Constant: '<S208>/Constant2'
     *  Constant: '<S208>/Constant3'
     */
    if (gbyk_v4b_B.ReadHasFT[1] > gbyk_v4b_P.Switch_Threshold_j) {
      gbyk_v4b_B.Switch_g = gbyk_v4b_P.Constant3_Value_k;
    } else {
      gbyk_v4b_B.Switch_g = gbyk_v4b_P.Constant2_Value_o;
    }

    /* End of Switch: '<S208>/Switch' */

    /* ReverseEndian: <S208>/Byte Reversal2 */

    /* 2 byte-wide input datatypes */
    ((uint16_T *)&gbyk_v4b_B.ByteReversal2_g)[0] =
      SWAP16(((uint16_T *)&gbyk_v4b_B.Switch_g)[0]);

    /* ReverseEndian: <S208>/Byte Reversal */

    /* 4 byte-wide input datatypes */
    ((uint32_T *)&gbyk_v4b_B.ByteReversal_g)[0] =
      SWAP32(((uint32_T *)&gbyk_v4b_P.Constant1_Value_me)[0]);

    /* Pack: <S208>/Pack */
    (void) memcpy(&gbyk_v4b_B.Pack[0], &gbyk_v4b_B.ByteReversal1_a,
                  2);
    (void) memcpy(&gbyk_v4b_B.Pack[2], &gbyk_v4b_B.ByteReversal2_g,
                  2);
    (void) memcpy(&gbyk_v4b_B.Pack[4], &gbyk_v4b_B.ByteReversal_g,
                  4);

    /* Level2 S-Function Block: '<S208>/Send' (xpcudpbytesend) */
    {
      SimStruct *rts = gbyk_v4b_M->childSfunctions[21];
      sfcnOutputs(rts, 1);
    }

    srUpdateBC(gbyk_v4b_DW.DataTransferStartSubsystem_SubsysRanBC);
  }

  /* End of Outputs for SubSystem: '<S203>/Data Transfer Start Subsystem' */

  /* Level2 S-Function Block: '<S203>/Receive from Robot 2 Force Sensor' (xpcudpbytereceive) */
  {
    SimStruct *rts = gbyk_v4b_M->childSfunctions[23];
    sfcnOutputs(rts, 1);
  }

  /* Unpack: <S203>/Unpack1 */
  (void) memcpy(&gbyk_v4b_B.Unpack1_o1[0],
                &gbyk_v4b_B.ReceivefromRobot2ForceSensor_o1[0],
                12);
  (void) memcpy(&gbyk_v4b_B.Unpack1_o2[0],
                &gbyk_v4b_B.ReceivefromRobot2ForceSensor_o1[12],
                24);

  /* ReverseEndian: <S203>/Byte Reversal */

  /* 4 byte-wide input datatypes */
  {
    int_T i1;
    const int32_T *u0 = &gbyk_v4b_B.Unpack1_o2[0];
    int32_T *y0 = &gbyk_v4b_B.ByteReversal_o[0];
    for (i1=0; i1 < 6; i1++) {
      ((uint32_T *)&y0[i1])[0] =
        SWAP32(((uint32_T *)&u0[i1])[0]);
    }
  }

  /* ReverseEndian: <S203>/Byte Reversal1 */

  /* 4 byte-wide input datatypes */
  ((uint32_T *)&gbyk_v4b_B.ByteReversal1_f[0])[0] =
    SWAP32(((uint32_T *)&gbyk_v4b_B.Unpack1_o1[0])[0]);
  ((uint32_T *)&gbyk_v4b_B.ByteReversal1_f[1])[0] =
    SWAP32(((uint32_T *)&gbyk_v4b_B.Unpack1_o1[1])[0]);
  ((uint32_T *)&gbyk_v4b_B.ByteReversal1_f[2])[0] =
    SWAP32(((uint32_T *)&gbyk_v4b_B.Unpack1_o1[2])[0]);

  /* MATLAB Function: '<S203>/Create timestamp' */
  gbyk_v4b_Createtimestamp(gbyk_v4b_B.ByteReversal1_f,
    &gbyk_v4b_B.sf_Createtimestamp_b, &gbyk_v4b_DW.sf_Createtimestamp_b);

  /* Switch: '<S203>/Switch1' incorporates:
   *  Constant: '<S203>/Constant1'
   */
  if (gbyk_v4b_B.ReadHasFT[1] > gbyk_v4b_P.Switch1_Threshold) {
    /* DataTypeConversion: '<S203>/Data Type Conversion1' */
    for (i = 0; i < 6; i++) {
      gbyk_v4b_B.DataTypeConversion1_g[i] = gbyk_v4b_B.ByteReversal_o[i];
      gbyk_v4b_B.Switch1_b[i] = gbyk_v4b_B.DataTypeConversion1_g[i];
    }

    /* End of DataTypeConversion: '<S203>/Data Type Conversion1' */
    gbyk_v4b_B.Switch1_b[6] = gbyk_v4b_B.sf_Createtimestamp_b.timestamp_out;
  } else {
    for (i = 0; i < 7; i++) {
      gbyk_v4b_B.Switch1_b[i] = gbyk_v4b_P.Constant1_Value_a[i];
    }
  }

  /* End of Switch: '<S203>/Switch1' */
}

/* Update for atomic system: '<S34>/Force Sensor Control' */
void gbyk_v4b_ForceSensorControl_Update(void)
{
  /* Update for UnitDelay: '<S205>/Delay Input1' */
  gbyk_v4b_DW.DelayInput1_DSTATE = gbyk_v4b_B.ReadHasFT[0];

  /* Update for UnitDelay: '<S209>/Delay Input1' */
  gbyk_v4b_DW.DelayInput1_DSTATE_n = gbyk_v4b_B.ReadHasFT[1];
}

/* Termination for atomic system: '<S34>/Force Sensor Control' */
void gbyk_v4b_ForceSensorControl_Term(void)
{
  /* Terminate for Enabled SubSystem: '<S202>/If Action Subsystem' */

  /* Level2 S-Function Block: '<S206>/Send' (xpcudpbytesend) */
  {
    SimStruct *rts = gbyk_v4b_M->childSfunctions[20];
    sfcnTerminate(rts);
  }

  /* End of Terminate for SubSystem: '<S202>/If Action Subsystem' */

  /* Level2 S-Function Block: '<S202>/Receive from Robot 1 Force Sensor' (xpcudpbytereceive) */
  {
    SimStruct *rts = gbyk_v4b_M->childSfunctions[22];
    sfcnTerminate(rts);
  }

  /* Terminate for Enabled SubSystem: '<S203>/Data Transfer Start Subsystem' */

  /* Level2 S-Function Block: '<S208>/Send' (xpcudpbytesend) */
  {
    SimStruct *rts = gbyk_v4b_M->childSfunctions[21];
    sfcnTerminate(rts);
  }

  /* End of Terminate for SubSystem: '<S203>/Data Transfer Start Subsystem' */

  /* Level2 S-Function Block: '<S203>/Receive from Robot 2 Force Sensor' (xpcudpbytereceive) */
  {
    SimStruct *rts = gbyk_v4b_M->childSfunctions[23];
    sfcnTerminate(rts);
  }
}
