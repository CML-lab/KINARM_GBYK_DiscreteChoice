/*
 * Code generation for system system '<S4>/Poll Force Plates'
 *
 * Model                      : gbyk_v4b
 * Model version              : 1.2667
 * Simulink Coder version : 8.8.1 (R2015aSP1) 04-Sep-2015
 * C source code generated on : Tue Sep 15 15:02:19 2020
 *
 * Note that the functions contained in this file are part of a Simulink
 * model, and are not self-contained algorithms.
 */

#include "gbyk_v4b_PollForcePlates.h"

/* Include model header file for global data */
#include "gbyk_v4b.h"
#include "gbyk_v4b_private.h"

/* Start for atomic system: '<S4>/Poll Force Plates' */
void gbyk_v4b_PollForcePlates_Start(void)
{
  /* Start for Enabled SubSystem: '<S33>/send poll 1' */

  /* Level2 S-Function Block: '<S60>/Send' (xpcudpbytesend) */
  {
    SimStruct *rts = gbyk_v4b_M->childSfunctions[6];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* End of Start for SubSystem: '<S33>/send poll 1' */

  /* Start for Enabled SubSystem: '<S33>/send poll 2' */

  /* Level2 S-Function Block: '<S61>/Send1' (xpcudpbytesend) */
  {
    SimStruct *rts = gbyk_v4b_M->childSfunctions[7];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* End of Start for SubSystem: '<S33>/send poll 2' */

  /* Start for Enabled SubSystem: '<S33>/plate1' */

  /* Level2 S-Function Block: '<S58>/Receive' (xpcudpbytereceive) */
  {
    SimStruct *rts = gbyk_v4b_M->childSfunctions[4];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* End of Start for SubSystem: '<S33>/plate1' */

  /* Start for Enabled SubSystem: '<S33>/plate2' */

  /* Level2 S-Function Block: '<S59>/Receive1' (xpcudpbytereceive) */
  {
    SimStruct *rts = gbyk_v4b_M->childSfunctions[5];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* End of Start for SubSystem: '<S33>/plate2' */
}

/* Output and update for atomic system: '<S4>/Poll Force Plates' */
void gbyk_v4b_PollForcePlatesTID0(void)
{
  real_T voltages[8];
  real_T values[6];
  int32_T i;
  int32_T i_0;
  real_T voltages_0[8];
  uint32_T timers_idx_0;
  real_T values_0;

  /* DataTypeConversion: '<S33>/Convert1' incorporates:
   *  Constant: '<S33>/request_packet'
   */
  for (i = 0; i < 34; i++) {
    gbyk_v4b_B.Convert1_c[i] = (uint8_T)gbyk_v4b_P.request_packet_Value[i];
  }

  /* End of DataTypeConversion: '<S33>/Convert1' */

  /* RateTransition: '<S33>/TmpRTBAtConvert1Outport1' */
  if (gbyk_v4b_M->Timing.RateInteraction.TID1_2) {
    for (i = 0; i < 34; i++) {
      gbyk_v4b_B.TmpRTBAtConvert1Outport1[i] = gbyk_v4b_B.Convert1_c[i];
    }

    /* RateTransition: '<S33>/Rate Transition' incorporates:
     *  Constant: '<S33>/enable_plate1'
     */
    gbyk_v4b_B.RateTransition_g = gbyk_v4b_P.enable_plate1_Value;

    /* RateTransition: '<S33>/Rate Transition1' incorporates:
     *  Constant: '<S33>/enable_plate2'
     */
    gbyk_v4b_B.RateTransition1_h3 = gbyk_v4b_P.enable_plate2_Value;
  }

  /* End of RateTransition: '<S33>/TmpRTBAtConvert1Outport1' */

  /* Outputs for Enabled SubSystem: '<S33>/plate1' incorporates:
   *  EnablePort: '<S58>/Enable'
   */
  /* Constant: '<S33>/enable_plate1' */
  if (gbyk_v4b_P.enable_plate1_Value > 0.0) {
    /* Level2 S-Function Block: '<S58>/Receive' (xpcudpbytereceive) */
    {
      SimStruct *rts = gbyk_v4b_M->childSfunctions[4];
      sfcnOutputs(rts, 1);
    }

    /* MATLAB Function: '<S58>/parse packet 1' incorporates:
     *  Constant: '<S33>/ain_offset1'
     *  Constant: '<S33>/ain_slope1'
     *  Constant: '<S33>/calibration_matrix1'
     *  Constant: '<S33>/gain'
     *  Constant: '<S33>/orientation1'
     *  Constant: '<S33>/zero_voltage'
     */
    /* MATLAB Function 'DataLogging/Poll Force Plates/plate1/parse packet 1': '<S62>:1' */
    /* This pulls voltages and timer infomation from the packet we got back from */
    /* the lab jack. */
    /* '<S62>:1:5' */
    /* '<S62>:1:6' */
    /* '<S62>:1:8' */
    for (i_0 = 0; i_0 < 8; i_0++) {
      voltages[i_0] = 0.0;

      /* '<S62>:1:8' */
      /* '<S62>:1:9' */
      i = (i_0 << 1) + 12;

      /* '<S62>:1:59' */
      /* '<S62>:1:60' */
      /* '<S62>:1:61' */
      /* '<S62>:1:10' */
      /* '<S62>:1:73' */
      voltages[i_0] = (real_T)(((uint32_T)gbyk_v4b_B.Receive_o1_k[i + 1] << 8) +
        gbyk_v4b_B.Receive_o1_k[i]) * gbyk_v4b_P.ain_slope1_Value +
        gbyk_v4b_P.ain_offset1_Value;

      /* '<S62>:1:8' */
    }

    /* '<S62>:1:13' */
    /* '<S62>:1:14' */
    /* '<S62>:1:65' */
    /* '<S62>:1:66' */
    /* '<S62>:1:67' */
    /* '<S62>:1:68' */
    /* '<S62>:1:69' */
    timers_idx_0 = ((((uint32_T)gbyk_v4b_B.Receive_o1_k[53] << 8) +
                     gbyk_v4b_B.Receive_o1_k[52]) + ((uint32_T)
      gbyk_v4b_B.Receive_o1_k[54] << 16)) + ((uint32_T)gbyk_v4b_B.Receive_o1_k
      [55] << 24);

    /* '<S62>:1:13' */
    /* '<S62>:1:14' */
    /* '<S62>:1:65' */
    /* '<S62>:1:66' */
    /* '<S62>:1:67' */
    /* '<S62>:1:68' */
    /* '<S62>:1:69' */
    /* '<S62>:1:13' */
    /* '<S62>:1:14' */
    /* '<S62>:1:65' */
    /* '<S62>:1:66' */
    /* '<S62>:1:67' */
    /* '<S62>:1:68' */
    /* '<S62>:1:69' */
    /* '<S62>:1:13' */
    /* convert the time stamp to a time in seconds. */
    /* '<S62>:1:18' */
    gbyk_v4b_B.timer_c = (real_T)timers_idx_0 / 750000.0;

    /* all voltages are between -2.5 to 2.5, here we are normalizeing what we read to zero. */
    /* '<S62>:1:21' */
    /* '<S62>:1:22' */
    /*  only the first 8 channels matter. */
    /* using the calibration matrix we convert the to the forces and moments */
    /* '<S62>:1:25' */
    for (i_0 = 0; i_0 < 8; i_0++) {
      values_0 = voltages[i_0];
      values_0 -= gbyk_v4b_P.zero_voltage_Value;
      voltages_0[i_0] = values_0 / gbyk_v4b_P.gain_Value;
    }

    for (i_0 = 0; i_0 < 6; i_0++) {
      values[i_0] = 0.0;
      for (i = 0; i < 8; i++) {
        values_0 = values[i_0];
        values_0 += gbyk_v4b_P.calibration_matrix1_Value[6 * i + i_0] *
          voltages_0[i];
        values[i_0] = values_0;
      }
    }

    /* '<S62>:1:26' */
    gbyk_v4b_B.forces_g[0] = values[0];
    gbyk_v4b_B.forces_g[1] = values[1];
    gbyk_v4b_B.forces_g[2] = values[2];

    /* '<S62>:1:27' */
    gbyk_v4b_B.moments_p[0] = values[3];
    gbyk_v4b_B.moments_p[1] = values[4];
    gbyk_v4b_B.moments_p[2] = values[5];

    /* reverse the Z force to get it into global coordinates. */
    /* '<S62>:1:30' */
    gbyk_v4b_B.forces_g[2] = -values[2];

    /* considering the positions of the cables push all measures into global coordinates */
    if (gbyk_v4b_P.orientation1_Value == 0.0) {
      /* '<S62>:1:33' */
      /* '<S62>:1:34' */
      gbyk_v4b_B.forces_g[1] = -values[1];

      /* '<S62>:1:35' */
      gbyk_v4b_B.moments_p[1] = -values[4];
    } else if (gbyk_v4b_P.orientation1_Value == 90.0) {
      /* '<S62>:1:36' */
      /* '<S62>:1:37' */
      /* '<S62>:1:38' */
      gbyk_v4b_B.forces_g[1] = -values[0];

      /* '<S62>:1:39' */
      gbyk_v4b_B.forces_g[0] = -values[1];

      /* '<S62>:1:41' */
      /* '<S62>:1:42' */
      gbyk_v4b_B.moments_p[1] = -values[3];

      /* '<S62>:1:43' */
      gbyk_v4b_B.moments_p[0] = -values[4];
    } else if (gbyk_v4b_P.orientation1_Value == 180.0) {
      /* '<S62>:1:44' */
      /* '<S62>:1:45' */
      gbyk_v4b_B.forces_g[0] = -values[0];

      /* '<S62>:1:46' */
      gbyk_v4b_B.moments_p[0] = -values[3];
    } else {
      if (gbyk_v4b_P.orientation1_Value == 270.0) {
        /* '<S62>:1:47' */
        /* '<S62>:1:48' */
        /* '<S62>:1:49' */
        gbyk_v4b_B.forces_g[1] = values[0];

        /* '<S62>:1:50' */
        gbyk_v4b_B.forces_g[0] = values[1];

        /* '<S62>:1:52' */
        /* '<S62>:1:53' */
        gbyk_v4b_B.moments_p[1] = values[3];

        /* '<S62>:1:54' */
        gbyk_v4b_B.moments_p[0] = values[4];
      }
    }

    /* End of MATLAB Function: '<S58>/parse packet 1' */
    srUpdateBC(gbyk_v4b_DW.plate1_SubsysRanBC);
  }

  /* End of Outputs for SubSystem: '<S33>/plate1' */

  /* Outputs for Enabled SubSystem: '<S33>/plate2' incorporates:
   *  EnablePort: '<S59>/Enable'
   */
  /* Constant: '<S33>/enable_plate2' */
  if (gbyk_v4b_P.enable_plate2_Value > 0.0) {
    /* Level2 S-Function Block: '<S59>/Receive1' (xpcudpbytereceive) */
    {
      SimStruct *rts = gbyk_v4b_M->childSfunctions[5];
      sfcnOutputs(rts, 1);
    }

    /* MATLAB Function: '<S59>/parse packet 1' incorporates:
     *  Constant: '<S33>/ain_offset2'
     *  Constant: '<S33>/ain_slope2'
     *  Constant: '<S33>/calibration_matrix2'
     *  Constant: '<S33>/gain'
     *  Constant: '<S33>/orientation2'
     *  Constant: '<S33>/zero_voltage'
     */
    /* MATLAB Function 'DataLogging/Poll Force Plates/plate2/parse packet 1': '<S63>:1' */
    /* This pulls voltages and timer infomation from the packet we got back from */
    /* the lab jack. */
    /* '<S63>:1:5' */
    /* '<S63>:1:6' */
    /* '<S63>:1:8' */
    for (i_0 = 0; i_0 < 8; i_0++) {
      voltages[i_0] = 0.0;

      /* '<S63>:1:8' */
      /* '<S63>:1:9' */
      i = (i_0 << 1) + 12;

      /* '<S63>:1:59' */
      /* '<S63>:1:60' */
      /* '<S63>:1:61' */
      /* '<S63>:1:10' */
      /* '<S63>:1:73' */
      voltages[i_0] = (real_T)(((uint32_T)gbyk_v4b_B.Receive1_o1[i + 1] << 8) +
        gbyk_v4b_B.Receive1_o1[i]) * gbyk_v4b_P.ain_slope2_Value +
        gbyk_v4b_P.ain_offset2_Value;

      /* '<S63>:1:8' */
    }

    /* '<S63>:1:13' */
    /* '<S63>:1:14' */
    /* '<S63>:1:65' */
    /* '<S63>:1:66' */
    /* '<S63>:1:67' */
    /* '<S63>:1:68' */
    /* '<S63>:1:69' */
    timers_idx_0 = ((((uint32_T)gbyk_v4b_B.Receive1_o1[53] << 8) +
                     gbyk_v4b_B.Receive1_o1[52]) + ((uint32_T)
      gbyk_v4b_B.Receive1_o1[54] << 16)) + ((uint32_T)gbyk_v4b_B.Receive1_o1[55]
      << 24);

    /* '<S63>:1:13' */
    /* '<S63>:1:14' */
    /* '<S63>:1:65' */
    /* '<S63>:1:66' */
    /* '<S63>:1:67' */
    /* '<S63>:1:68' */
    /* '<S63>:1:69' */
    /* '<S63>:1:13' */
    /* '<S63>:1:14' */
    /* '<S63>:1:65' */
    /* '<S63>:1:66' */
    /* '<S63>:1:67' */
    /* '<S63>:1:68' */
    /* '<S63>:1:69' */
    /* '<S63>:1:13' */
    /* convert the time stamp to a time in seconds. */
    /* '<S63>:1:18' */
    gbyk_v4b_B.timer = (real_T)timers_idx_0 / 750000.0;

    /* all voltages are between -2.5 to 2.5, here we are normalizeing what we read to zero. */
    /* '<S63>:1:21' */
    /* '<S63>:1:22' */
    /*  only the first 8 channels matter. */
    /* using the calibration matrix we convert the to the forces and moments */
    /* '<S63>:1:25' */
    for (i_0 = 0; i_0 < 8; i_0++) {
      values_0 = voltages[i_0];
      values_0 -= gbyk_v4b_P.zero_voltage_Value;
      voltages_0[i_0] = values_0 / gbyk_v4b_P.gain_Value;
    }

    for (i_0 = 0; i_0 < 6; i_0++) {
      values[i_0] = 0.0;
      for (i = 0; i < 8; i++) {
        values_0 = values[i_0];
        values_0 += gbyk_v4b_P.calibration_matrix2_Value[6 * i + i_0] *
          voltages_0[i];
        values[i_0] = values_0;
      }
    }

    /* '<S63>:1:26' */
    gbyk_v4b_B.forces[0] = values[0];
    gbyk_v4b_B.forces[1] = values[1];
    gbyk_v4b_B.forces[2] = values[2];

    /* '<S63>:1:27' */
    gbyk_v4b_B.moments[0] = values[3];
    gbyk_v4b_B.moments[1] = values[4];
    gbyk_v4b_B.moments[2] = values[5];

    /* reverse the Z force to get it into global coordinates. */
    /* '<S63>:1:30' */
    gbyk_v4b_B.forces[2] = -values[2];

    /* considering the positions of the cables push all measures into global coordinates */
    if (gbyk_v4b_P.orientation2_Value == 0.0) {
      /* '<S63>:1:33' */
      /* '<S63>:1:34' */
      gbyk_v4b_B.forces[1] = -values[1];

      /* '<S63>:1:35' */
      gbyk_v4b_B.moments[1] = -values[4];
    } else if (gbyk_v4b_P.orientation2_Value == 90.0) {
      /* '<S63>:1:36' */
      /* '<S63>:1:37' */
      /* '<S63>:1:38' */
      gbyk_v4b_B.forces[1] = -values[0];

      /* '<S63>:1:39' */
      gbyk_v4b_B.forces[0] = -values[1];

      /* '<S63>:1:41' */
      /* '<S63>:1:42' */
      gbyk_v4b_B.moments[1] = -values[3];

      /* '<S63>:1:43' */
      gbyk_v4b_B.moments[0] = -values[4];
    } else if (gbyk_v4b_P.orientation2_Value == 180.0) {
      /* '<S63>:1:44' */
      /* '<S63>:1:45' */
      gbyk_v4b_B.forces[0] = -values[0];

      /* '<S63>:1:46' */
      gbyk_v4b_B.moments[0] = -values[3];
    } else {
      if (gbyk_v4b_P.orientation2_Value == 270.0) {
        /* '<S63>:1:47' */
        /* '<S63>:1:48' */
        /* '<S63>:1:49' */
        gbyk_v4b_B.forces[1] = values[0];

        /* '<S63>:1:50' */
        gbyk_v4b_B.forces[0] = values[1];

        /* '<S63>:1:52' */
        /* '<S63>:1:53' */
        gbyk_v4b_B.moments[1] = values[3];

        /* '<S63>:1:54' */
        gbyk_v4b_B.moments[0] = values[4];
      }
    }

    /* End of MATLAB Function: '<S59>/parse packet 1' */
    srUpdateBC(gbyk_v4b_DW.plate2_SubsysRanBC);
  }

  /* End of Outputs for SubSystem: '<S33>/plate2' */

  /* DataTypeConversion: '<S33>/Convert19' */
  gbyk_v4b_B.Convert19_e[0] = gbyk_v4b_B.forces_g[0];
  gbyk_v4b_B.Convert19_e[1] = gbyk_v4b_B.forces_g[1];
  gbyk_v4b_B.Convert19_e[2] = gbyk_v4b_B.forces_g[2];
  gbyk_v4b_B.Convert19_e[3] = gbyk_v4b_B.moments_p[0];
  gbyk_v4b_B.Convert19_e[4] = gbyk_v4b_B.moments_p[1];
  gbyk_v4b_B.Convert19_e[5] = gbyk_v4b_B.moments_p[2];
  gbyk_v4b_B.Convert19_e[6] = gbyk_v4b_B.timer_c;
  gbyk_v4b_B.Convert19_e[7] = gbyk_v4b_B.forces[0];
  gbyk_v4b_B.Convert19_e[8] = gbyk_v4b_B.forces[1];
  gbyk_v4b_B.Convert19_e[9] = gbyk_v4b_B.forces[2];
  gbyk_v4b_B.Convert19_e[10] = gbyk_v4b_B.moments[0];
  gbyk_v4b_B.Convert19_e[11] = gbyk_v4b_B.moments[1];
  gbyk_v4b_B.Convert19_e[12] = gbyk_v4b_B.moments[2];
  gbyk_v4b_B.Convert19_e[13] = gbyk_v4b_B.timer;
}

/* Output and update for atomic system: '<S4>/Poll Force Plates' */
void gbyk_v4b_PollForcePlatesTID2(void)
{
  /* Outputs for Enabled SubSystem: '<S33>/send poll 1' incorporates:
   *  EnablePort: '<S60>/Enable'
   */
  if (gbyk_v4b_B.RateTransition_g > 0.0) {
    /* Level2 S-Function Block: '<S60>/Send' (xpcudpbytesend) */
    {
      SimStruct *rts = gbyk_v4b_M->childSfunctions[6];
      sfcnOutputs(rts, 2);
    }

    srUpdateBC(gbyk_v4b_DW.sendpoll1_SubsysRanBC);
  }

  /* End of Outputs for SubSystem: '<S33>/send poll 1' */

  /* Outputs for Enabled SubSystem: '<S33>/send poll 2' incorporates:
   *  EnablePort: '<S61>/Enable'
   */
  if (gbyk_v4b_B.RateTransition1_h3 > 0.0) {
    /* Level2 S-Function Block: '<S61>/Send1' (xpcudpbytesend) */
    {
      SimStruct *rts = gbyk_v4b_M->childSfunctions[7];
      sfcnOutputs(rts, 2);
    }

    srUpdateBC(gbyk_v4b_DW.sendpoll2_SubsysRanBC);
  }

  /* End of Outputs for SubSystem: '<S33>/send poll 2' */
}

/* Termination for atomic system: '<S4>/Poll Force Plates' */
void gbyk_v4b_PollForcePlates_Term(void)
{
  /* Terminate for Enabled SubSystem: '<S33>/send poll 1' */

  /* Level2 S-Function Block: '<S60>/Send' (xpcudpbytesend) */
  {
    SimStruct *rts = gbyk_v4b_M->childSfunctions[6];
    sfcnTerminate(rts);
  }

  /* End of Terminate for SubSystem: '<S33>/send poll 1' */

  /* Terminate for Enabled SubSystem: '<S33>/send poll 2' */

  /* Level2 S-Function Block: '<S61>/Send1' (xpcudpbytesend) */
  {
    SimStruct *rts = gbyk_v4b_M->childSfunctions[7];
    sfcnTerminate(rts);
  }

  /* End of Terminate for SubSystem: '<S33>/send poll 2' */

  /* Terminate for Enabled SubSystem: '<S33>/plate1' */

  /* Level2 S-Function Block: '<S58>/Receive' (xpcudpbytereceive) */
  {
    SimStruct *rts = gbyk_v4b_M->childSfunctions[4];
    sfcnTerminate(rts);
  }

  /* End of Terminate for SubSystem: '<S33>/plate1' */

  /* Terminate for Enabled SubSystem: '<S33>/plate2' */

  /* Level2 S-Function Block: '<S59>/Receive1' (xpcudpbytereceive) */
  {
    SimStruct *rts = gbyk_v4b_M->childSfunctions[5];
    sfcnTerminate(rts);
  }

  /* End of Terminate for SubSystem: '<S33>/plate2' */
}
