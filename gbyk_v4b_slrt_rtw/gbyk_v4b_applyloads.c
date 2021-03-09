/*
 * Code generation for system system '<S4>/apply loads'
 *
 * Model                      : gbyk_v4b
 * Model version              : 1.2667
 * Simulink Coder version : 8.8.1 (R2015aSP1) 04-Sep-2015
 * C source code generated on : Tue Sep 15 15:02:19 2020
 *
 * Note that the functions contained in this file are part of a Simulink
 * model, and are not self-contained algorithms.
 */

#include "gbyk_v4b_applyloads.h"

/* Include model header file for global data */
#include "gbyk_v4b.h"
#include "gbyk_v4b_private.h"

/* Start for atomic system: '<S4>/apply loads' */
void gbyk_v4b_applyloads_Start(void)
{
  /* Start for Enabled SubSystem: '<S37>/EtherCAT Apply Loads' */

  /* Level2 S-Function Block: '<S255>/BKIN EtherCAT PDO Transmit 1' (BKINethercatpdotx) */
  {
    SimStruct *rts = gbyk_v4b_M->childSfunctions[35];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S255>/BKIN EtherCAT PDO Transmit 2' (BKINethercatpdotx) */
  {
    SimStruct *rts = gbyk_v4b_M->childSfunctions[36];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S256>/BKIN EtherCAT PDO Transmit 1' (BKINethercatpdotx) */
  {
    SimStruct *rts = gbyk_v4b_M->childSfunctions[37];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S256>/BKIN EtherCAT PDO Transmit 2' (BKINethercatpdotx) */
  {
    SimStruct *rts = gbyk_v4b_M->childSfunctions[38];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* End of Start for SubSystem: '<S37>/EtherCAT Apply Loads' */

  /* Start for Enabled SubSystem: '<S37>/apply pmac loads' */
  gbyk_v4b_applypmacloads_Start();

  /* End of Start for SubSystem: '<S37>/apply pmac loads' */
}

/* Output and update for atomic system: '<S4>/apply loads' */
void gbyk_v4b_applyloads(void)
{
  real_T motorTorques_idx_0;
  real_T motorTorques_idx_1;
  real_T motorTorques_idx_2;
  real_T motorTorques_idx_3;
  int16_T tmp;

  /* RelationalOperator: '<S253>/Compare' incorporates:
   *  Constant: '<S253>/Constant'
   */
  gbyk_v4b_B.Compare_b = (gbyk_v4b_B.systemtype == gbyk_v4b_P.isecat_const_a);

  /* Outputs for Enabled SubSystem: '<S37>/EtherCAT Apply Loads' incorporates:
   *  EnablePort: '<S251>/Enable1'
   */
  if (gbyk_v4b_B.Compare_b) {
    /* DataStoreRead: '<S251>/Data Store Read' */
    memcpy(&gbyk_v4b_B.DataStoreRead[0], &gbyk_v4b_DW.ECATHardware[0], 14U *
           sizeof(real_T));

    /* MATLAB Function: '<S251>/convert torques' */
    /* MATLAB Function 'ECAT Apply Loads/convert torques': '<S257>:1' */
    /* convert the shoulder and elbow torques to M1 and M2 torques */
    /* '<S257>:1:5' */
    motorTorques_idx_0 = (gbyk_v4b_B.AddTorques[0] - gbyk_v4b_B.AddTorques[1]) *
      gbyk_v4b_B.DataStoreRead[8];
    motorTorques_idx_1 = gbyk_v4b_B.AddTorques[1] * gbyk_v4b_B.DataStoreRead[8];
    motorTorques_idx_2 = (gbyk_v4b_B.AddTorques[2] - gbyk_v4b_B.AddTorques[3]) *
      gbyk_v4b_B.DataStoreRead[9];
    motorTorques_idx_3 = gbyk_v4b_B.AddTorques[3] * gbyk_v4b_B.DataStoreRead[9];

    /* this is converting the requested torque to units of 1/1000th of */
    /* maximum continuous torque. This statement will auto clip to the min */
    /* and max for an int16. */
    /* '<S257>:1:13' */
    gbyk_v4b_B.ecatTorques[0] = 0;
    gbyk_v4b_B.ecatTorques[1] = 0;
    gbyk_v4b_B.ecatTorques[2] = 0;
    gbyk_v4b_B.ecatTorques[3] = 0;

    /* '<S257>:1:15' */
    /* We are trying to avoid a divide by zero. If either of these are zero */
    /* then that means we don't have that arm! */
    if (!((gbyk_v4b_B.DataStoreRead[0] <= 0.0) || (gbyk_v4b_B.DataStoreRead[4] <=
          0.0))) {
      /* '<S257>:1:21' */
      motorTorques_idx_0 = rt_roundd_snf(motorTorques_idx_0 *
        gbyk_v4b_B.DataStoreRead[10] / gbyk_v4b_B.DataStoreRead[4] * 1000.0 /
        gbyk_v4b_B.DataStoreRead[0]);
      if (motorTorques_idx_0 < 32768.0) {
        if (motorTorques_idx_0 >= -32768.0) {
          tmp = (int16_T)motorTorques_idx_0;
        } else {
          tmp = MIN_int16_T;
        }
      } else {
        tmp = MAX_int16_T;
      }

      gbyk_v4b_B.ecatTorques[0] = tmp;
    } else {
      /* '<S257>:1:18' */
    }

    /* '<S257>:1:15' */
    /* We are trying to avoid a divide by zero. If either of these are zero */
    /* then that means we don't have that arm! */
    if (!((gbyk_v4b_B.DataStoreRead[1] <= 0.0) || (gbyk_v4b_B.DataStoreRead[5] <=
          0.0))) {
      /* '<S257>:1:21' */
      motorTorques_idx_0 = rt_roundd_snf(motorTorques_idx_1 *
        gbyk_v4b_B.DataStoreRead[11] / gbyk_v4b_B.DataStoreRead[5] * 1000.0 /
        gbyk_v4b_B.DataStoreRead[1]);
      if (motorTorques_idx_0 < 32768.0) {
        if (motorTorques_idx_0 >= -32768.0) {
          tmp = (int16_T)motorTorques_idx_0;
        } else {
          tmp = MIN_int16_T;
        }
      } else {
        tmp = MAX_int16_T;
      }

      gbyk_v4b_B.ecatTorques[1] = tmp;
    } else {
      /* '<S257>:1:18' */
    }

    /* '<S257>:1:15' */
    /* We are trying to avoid a divide by zero. If either of these are zero */
    /* then that means we don't have that arm! */
    if (!((gbyk_v4b_B.DataStoreRead[2] <= 0.0) || (gbyk_v4b_B.DataStoreRead[6] <=
          0.0))) {
      /* '<S257>:1:21' */
      motorTorques_idx_0 = rt_roundd_snf(motorTorques_idx_2 *
        gbyk_v4b_B.DataStoreRead[12] / gbyk_v4b_B.DataStoreRead[6] * 1000.0 /
        gbyk_v4b_B.DataStoreRead[2]);
      if (motorTorques_idx_0 < 32768.0) {
        if (motorTorques_idx_0 >= -32768.0) {
          tmp = (int16_T)motorTorques_idx_0;
        } else {
          tmp = MIN_int16_T;
        }
      } else {
        tmp = MAX_int16_T;
      }

      gbyk_v4b_B.ecatTorques[2] = tmp;
    } else {
      /* '<S257>:1:18' */
    }

    /* '<S257>:1:15' */
    /* We are trying to avoid a divide by zero. If either of these are zero */
    /* then that means we don't have that arm! */
    if (!((gbyk_v4b_B.DataStoreRead[3] <= 0.0) || (gbyk_v4b_B.DataStoreRead[7] <=
          0.0))) {
      /* '<S257>:1:21' */
      motorTorques_idx_0 = rt_roundd_snf(motorTorques_idx_3 *
        gbyk_v4b_B.DataStoreRead[13] / gbyk_v4b_B.DataStoreRead[7] * 1000.0 /
        gbyk_v4b_B.DataStoreRead[3]);
      if (motorTorques_idx_0 < 32768.0) {
        if (motorTorques_idx_0 >= -32768.0) {
          tmp = (int16_T)motorTorques_idx_0;
        } else {
          tmp = MIN_int16_T;
        }
      } else {
        tmp = MAX_int16_T;
      }

      gbyk_v4b_B.ecatTorques[3] = tmp;
    } else {
      /* '<S257>:1:18' */
    }

    /* End of MATLAB Function: '<S251>/convert torques' */
    /* '<S257>:1:15' */

    /* Level2 S-Function Block: '<S255>/BKIN EtherCAT PDO Transmit 1' (BKINethercatpdotx) */
    {
      SimStruct *rts = gbyk_v4b_M->childSfunctions[35];
      sfcnOutputs(rts, 1);
    }

    /* Level2 S-Function Block: '<S255>/BKIN EtherCAT PDO Transmit 2' (BKINethercatpdotx) */
    {
      SimStruct *rts = gbyk_v4b_M->childSfunctions[36];
      sfcnOutputs(rts, 1);
    }

    /* Level2 S-Function Block: '<S256>/BKIN EtherCAT PDO Transmit 1' (BKINethercatpdotx) */
    {
      SimStruct *rts = gbyk_v4b_M->childSfunctions[37];
      sfcnOutputs(rts, 1);
    }

    /* Level2 S-Function Block: '<S256>/BKIN EtherCAT PDO Transmit 2' (BKINethercatpdotx) */
    {
      SimStruct *rts = gbyk_v4b_M->childSfunctions[38];
      sfcnOutputs(rts, 1);
    }

    srUpdateBC(gbyk_v4b_DW.EtherCATApplyLoads_SubsysRanBC);
  }

  /* End of Outputs for SubSystem: '<S37>/EtherCAT Apply Loads' */

  /* RelationalOperator: '<S254>/Compare' incorporates:
   *  Constant: '<S254>/Constant'
   */
  gbyk_v4b_B.Compare_l = (gbyk_v4b_B.systemtype == gbyk_v4b_P.isecat1_const);

  /* Outputs for Enabled SubSystem: '<S37>/apply pmac loads' */
  gbyk_v4b_applypmacloads();

  /* End of Outputs for SubSystem: '<S37>/apply pmac loads' */
}

/* Termination for atomic system: '<S4>/apply loads' */
void gbyk_v4b_applyloads_Term(void)
{
  /* Terminate for Enabled SubSystem: '<S37>/EtherCAT Apply Loads' */

  /* Level2 S-Function Block: '<S255>/BKIN EtherCAT PDO Transmit 1' (BKINethercatpdotx) */
  {
    SimStruct *rts = gbyk_v4b_M->childSfunctions[35];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S255>/BKIN EtherCAT PDO Transmit 2' (BKINethercatpdotx) */
  {
    SimStruct *rts = gbyk_v4b_M->childSfunctions[36];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S256>/BKIN EtherCAT PDO Transmit 1' (BKINethercatpdotx) */
  {
    SimStruct *rts = gbyk_v4b_M->childSfunctions[37];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S256>/BKIN EtherCAT PDO Transmit 2' (BKINethercatpdotx) */
  {
    SimStruct *rts = gbyk_v4b_M->childSfunctions[38];
    sfcnTerminate(rts);
  }

  /* End of Terminate for SubSystem: '<S37>/EtherCAT Apply Loads' */

  /* Terminate for Enabled SubSystem: '<S37>/apply pmac loads' */
  gbyk_v4b_applypmacloads_Term();

  /* End of Terminate for SubSystem: '<S37>/apply pmac loads' */
}
