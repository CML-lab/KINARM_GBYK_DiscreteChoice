/*
 * Code generation for system system '<S4>/Network Transfer Subsystem'
 *
 * Model                      : gbyk_v4b
 * Model version              : 1.2667
 * Simulink Coder version : 8.8.1 (R2015aSP1) 04-Sep-2015
 * C source code generated on : Tue Sep 15 15:02:19 2020
 *
 * Note that the functions contained in this file are part of a Simulink
 * model, and are not self-contained algorithms.
 */

#include "gbyk_v4b_NetworkTransferSubsystem.h"

/* Include model header file for global data */
#include "gbyk_v4b.h"
#include "gbyk_v4b_private.h"

/* Named constants for Chart: '<S32>/Send Control Machine' */
#define gbyk_v4b_FULL_PACKET_SIZE      (410.0)
#define gbyk_v4b_IN_AddPacketToQueue   ((uint8_T)1U)
#define gbyk_v4b_IN_Fix                ((uint8_T)1U)
#define gbyk_v4b_IN_Fixed              ((uint8_T)1U)
#define gbyk_v4b_IN_Idle               ((uint8_T)1U)
#define gbyk_v4b_IN_NO_ACTIVE_CHILD_j  ((uint8_T)0U)
#define gbyk_v4b_IN_NoFix              ((uint8_T)2U)
#define gbyk_v4b_IN_ResetUDPPort       ((uint8_T)2U)
#define gbyk_v4b_IN_SendPacket         ((uint8_T)2U)
#define gbyk_v4b_KINEMATIC_LEN         (400.0)
#define gbyk_v4b_event_e_clk           (2)
#define gbyk_v4b_event_e_data_ready_strobe (1)
#define gbyk_v4b_event_e_fast_clk      (3)
#define gbyk_v4b_event_e_reset_UDP     (0)

/* Forward declaration for local functions */
static void gbyk_v4b_TrackQueueSize(void);
static void gbyk_v4b_SendControlMachine(void);
static void gbyk_v4b_chartstep_c8_General(void);

/* Initial conditions for function-call system: '<S32>/UDP Send Subsystem' */
void gbyk_v4b_UDPSendSubsystem_Init(void)
{
  /* InitializeConditions for UnitDelay: '<S54>/Output' */
  gbyk_v4b_DW.Output_DSTATE_h5 = gbyk_v4b_P.Output_InitialCondition;
}

/* Start for function-call system: '<S32>/UDP Send Subsystem' */
void gbyk_v4b_UDPSendSubsystem_Start(void)
{
  /* Level2 S-Function Block: '<S51>/Send' (xpcudpbytesend) */
  {
    SimStruct *rts = gbyk_v4b_M->childSfunctions[1];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* VirtualOutportStart for Outport: '<S51>/total_packets_sent' */
  gbyk_v4b_B.Output_n = gbyk_v4b_P.total_packets_sent_Y0;
}

/* Output and update for function-call system: '<S32>/UDP Send Subsystem' */
void gbyk_v4b_UDPSendSubsystem(void)
{
  /* UnitDelay: '<S54>/Output' */
  gbyk_v4b_B.Output_n = gbyk_v4b_DW.Output_DSTATE_h5;

  /* Sum: '<S56>/FixPt Sum1' incorporates:
   *  Constant: '<S56>/FixPt Constant'
   */
  gbyk_v4b_B.FixPtSum1_eh = gbyk_v4b_B.Output_n + gbyk_v4b_P.FixPtConstant_Value;

  /* Switch: '<S57>/FixPt Switch' incorporates:
   *  Constant: '<S57>/Constant'
   */
  if (gbyk_v4b_B.FixPtSum1_eh > gbyk_v4b_P.WrapToZero_Threshold) {
    gbyk_v4b_B.FixPtSwitch_dp = gbyk_v4b_P.Constant_Value_f;
  } else {
    gbyk_v4b_B.FixPtSwitch_dp = gbyk_v4b_B.FixPtSum1_eh;
  }

  /* End of Switch: '<S57>/FixPt Switch' */

  /* Pack: <S51>/Pack */
  (void) memcpy(&gbyk_v4b_B.Pack_i[0], &gbyk_v4b_B.data_out[0],
                1640);

  /* Level2 S-Function Block: '<S51>/Send' (xpcudpbytesend) */
  {
    SimStruct *rts = gbyk_v4b_M->childSfunctions[1];
    sfcnOutputs(rts, 1);
  }

  /* Update for UnitDelay: '<S54>/Output' */
  gbyk_v4b_DW.Output_DSTATE_h5 = gbyk_v4b_B.FixPtSwitch_dp;
  gbyk_v4b_DW.UDPSendSubsystem_SubsysRanBC = 4;
}

/* Termination for function-call system: '<S32>/UDP Send Subsystem' */
void gbyk_v4b_UDPSendSubsystem_Term(void)
{
  /* Level2 S-Function Block: '<S51>/Send' (xpcudpbytesend) */
  {
    SimStruct *rts = gbyk_v4b_M->childSfunctions[1];
    sfcnTerminate(rts);
  }
}

/* Function for Chart: '<S32>/Send Control Machine' */
static void gbyk_v4b_TrackQueueSize(void)
{
  /* Graphical Function 'TrackQueueSize': '<S49>:8' */
  /* Transition: '<S49>:21' */
  if (gbyk_v4b_DW.queue_head < gbyk_v4b_DW.queue_tail) {
    /* Transition: '<S49>:22' */
    gbyk_v4b_B.queue_size_e = ((real_T)gbyk_v4b_DW.queue_head +
      gbyk_v4b_DW.packet_queue_sz) - (real_T)gbyk_v4b_DW.queue_tail;
  } else {
    if (gbyk_v4b_DW.queue_head >= gbyk_v4b_DW.queue_tail) {
      /* Transition: '<S49>:23' */
      gbyk_v4b_B.queue_size_e = gbyk_v4b_DW.queue_head - gbyk_v4b_DW.queue_tail;
    }
  }
}

/* Function for Chart: '<S32>/Send Control Machine' */
static void gbyk_v4b_SendControlMachine(void)
{
  /* During 'SendControlMachine': '<S49>:4' */
  switch (gbyk_v4b_DW.is_SendControlMachine) {
   case gbyk_v4b_IN_Fixed:
    /* During 'Fixed': '<S49>:375' */
    if (gbyk_v4b_DW.sfEvent_mm == gbyk_v4b_event_e_reset_UDP) {
      /* Transition: '<S49>:393' */
      /* Exit Internal 'Fixed': '<S49>:375' */
      gbyk_v4b_DW.is_Fixed = gbyk_v4b_IN_NO_ACTIVE_CHILD_j;
      gbyk_v4b_DW.is_SendControlMachine = gbyk_v4b_IN_ResetUDPPort;
      gbyk_v4b_DW.temporalCounter_i3 = 0U;

      /* Entry 'ResetUDPPort': '<S49>:289' */
      gbyk_v4b_B.resetUDP = 1.0;
    } else {
      switch (gbyk_v4b_DW.is_Fixed) {
       case gbyk_v4b_IN_Idle:
        /* During 'Idle': '<S49>:391' */
        if ((gbyk_v4b_DW.sfEvent_mm == gbyk_v4b_event_e_fast_clk) &&
            (gbyk_v4b_DW.queue_head != gbyk_v4b_DW.queue_tail)) {
          /* Transition: '<S49>:386' */
          gbyk_v4b_DW.is_Fixed = gbyk_v4b_IN_SendPacket;
          gbyk_v4b_DW.temporalCounter_i1_o = 0U;

          /* Entry 'SendPacket': '<S49>:392' */
          buildOutputPacket(gbyk_v4b_B.data_out, &gbyk_v4b_DW.packet_queue[410 *
                            (int32_T)gbyk_v4b_DW.queue_tail],
                            gbyk_v4b_FULL_PACKET_SIZE, gbyk_v4b_B.queue_size_e,
                            gbyk_v4b_B.total_timeouts,
                            gbyk_v4b_B.DataTypeConversion2_k);
          gbyk_v4b_DW.outstanding_packet_index = gbyk_v4b_B.data_out[2];

          /* Outputs for Function Call SubSystem: '<S32>/UDP Send Subsystem' */

          /* Event: '<S49>:66' */
          gbyk_v4b_UDPSendSubsystem();

          /* End of Outputs for SubSystem: '<S32>/UDP Send Subsystem' */
        }
        break;

       case gbyk_v4b_IN_SendPacket:
        /* During 'SendPacket': '<S49>:392' */
        if ((gbyk_v4b_DW.sfEvent_mm == gbyk_v4b_event_e_fast_clk) &&
            (gbyk_v4b_DW.temporalCounter_i1_o >= 10)) {
          /* Transition: '<S49>:388' */
          /* Transition: '<S49>:390' */
          if (gbyk_v4b_B.Convert16 == 0.0) {
            /* Transition: '<S49>:406' */
            gbyk_v4b_DW.is_Fixed = gbyk_v4b_IN_SendPacket;
            gbyk_v4b_DW.temporalCounter_i1_o = 0U;

            /* Entry 'SendPacket': '<S49>:392' */
            buildOutputPacket(gbyk_v4b_B.data_out, &gbyk_v4b_DW.packet_queue[410
                              * (int32_T)gbyk_v4b_DW.queue_tail],
                              gbyk_v4b_FULL_PACKET_SIZE, gbyk_v4b_B.queue_size_e,
                              gbyk_v4b_B.total_timeouts,
                              gbyk_v4b_B.DataTypeConversion2_k);
            gbyk_v4b_DW.outstanding_packet_index = gbyk_v4b_B.data_out[2];

            /* Outputs for Function Call SubSystem: '<S32>/UDP Send Subsystem' */

            /* Event: '<S49>:66' */
            gbyk_v4b_UDPSendSubsystem();

            /* End of Outputs for SubSystem: '<S32>/UDP Send Subsystem' */
          } else {
            /* Transition: '<S49>:407' */
            /* Transition: '<S49>:389' */
            gbyk_v4b_B.total_timeouts++;
            gbyk_v4b_DW.is_Fixed = gbyk_v4b_IN_SendPacket;
            gbyk_v4b_DW.temporalCounter_i1_o = 0U;

            /* Entry 'SendPacket': '<S49>:392' */
            buildOutputPacket(gbyk_v4b_B.data_out, &gbyk_v4b_DW.packet_queue[410
                              * (int32_T)gbyk_v4b_DW.queue_tail],
                              gbyk_v4b_FULL_PACKET_SIZE, gbyk_v4b_B.queue_size_e,
                              gbyk_v4b_B.total_timeouts,
                              gbyk_v4b_B.DataTypeConversion2_k);
            gbyk_v4b_DW.outstanding_packet_index = gbyk_v4b_B.data_out[2];

            /* Outputs for Function Call SubSystem: '<S32>/UDP Send Subsystem' */

            /* Event: '<S49>:66' */
            gbyk_v4b_UDPSendSubsystem();

            /* End of Outputs for SubSystem: '<S32>/UDP Send Subsystem' */
          }
        } else {
          /* Transition: '<S49>:387' */
          if ((gbyk_v4b_DW.sfEvent_mm == gbyk_v4b_event_e_fast_clk) &&
              (gbyk_v4b_B.DataTypeConversion_cb ==
               gbyk_v4b_DW.outstanding_packet_index)) {
            /* Transition: '<S49>:385' */
            gbyk_v4b_DW.queue_tail = (uint32_T)fmod(gbyk_v4b_DW.queue_tail + 1U,
              gbyk_v4b_DW.packet_queue_sz);

            /* Transition: '<S49>:383' */
            if (gbyk_v4b_DW.queue_head == gbyk_v4b_DW.queue_tail) {
              /* Transition: '<S49>:382' */
              gbyk_v4b_DW.is_Fixed = gbyk_v4b_IN_Idle;

              /* Entry 'Idle': '<S49>:391' */
              /*  Wait to acquire a new packet to send. */
            } else {
              if (gbyk_v4b_DW.queue_head != gbyk_v4b_DW.queue_tail) {
                /* Transition: '<S49>:384' */
                gbyk_v4b_DW.is_Fixed = gbyk_v4b_IN_SendPacket;
                gbyk_v4b_DW.temporalCounter_i1_o = 0U;

                /* Entry 'SendPacket': '<S49>:392' */
                buildOutputPacket(gbyk_v4b_B.data_out,
                                  &gbyk_v4b_DW.packet_queue[410 * (int32_T)
                                  gbyk_v4b_DW.queue_tail],
                                  gbyk_v4b_FULL_PACKET_SIZE,
                                  gbyk_v4b_B.queue_size_e,
                                  gbyk_v4b_B.total_timeouts,
                                  gbyk_v4b_B.DataTypeConversion2_k);
                gbyk_v4b_DW.outstanding_packet_index = gbyk_v4b_B.data_out[2];

                /* Outputs for Function Call SubSystem: '<S32>/UDP Send Subsystem' */

                /* Event: '<S49>:66' */
                gbyk_v4b_UDPSendSubsystem();

                /* End of Outputs for SubSystem: '<S32>/UDP Send Subsystem' */
              }
            }
          }
        }
        break;

       default:
        /* Unreachable state, for coverage only */
        gbyk_v4b_DW.is_Fixed = gbyk_v4b_IN_NO_ACTIVE_CHILD_j;
        break;
      }
    }
    break;

   case gbyk_v4b_IN_ResetUDPPort:
    /* During 'ResetUDPPort': '<S49>:289' */
    if ((gbyk_v4b_DW.sfEvent_mm == gbyk_v4b_event_e_fast_clk) &&
        (gbyk_v4b_DW.temporalCounter_i3 >= 2)) {
      /* Transition: '<S49>:395' */
      gbyk_v4b_DW.is_SendControlMachine = gbyk_v4b_IN_Fixed;

      /* Entry 'Fixed': '<S49>:375' */
      gbyk_v4b_B.resetUDP = 0.0;

      /* Entry Internal 'Fixed': '<S49>:375' */
      /* Transition: '<S49>:381' */
      if (gbyk_v4b_DW.is_Fixed != gbyk_v4b_IN_Idle) {
        gbyk_v4b_DW.is_Fixed = gbyk_v4b_IN_Idle;

        /* Entry 'Idle': '<S49>:391' */
        /*  Wait to acquire a new packet to send. */
      }
    }
    break;

   default:
    /* Unreachable state, for coverage only */
    gbyk_v4b_DW.is_SendControlMachine = gbyk_v4b_IN_NO_ACTIVE_CHILD_j;
    break;
  }
}

/* Function for Chart: '<S32>/Send Control Machine' */
static void gbyk_v4b_chartstep_c8_General(void)
{
  int32_T b_previousEvent;

  /* During: DataLogging/Network Transfer Subsystem/Send Control Machine */
  if (gbyk_v4b_DW.is_active_c8_General == 0U) {
    /* Entry: DataLogging/Network Transfer Subsystem/Send Control Machine */
    gbyk_v4b_DW.is_active_c8_General = 1U;

    /* Entry Internal: DataLogging/Network Transfer Subsystem/Send Control Machine */
    gbyk_v4b_DW.is_active_UpdatePacketQueue = 1U;

    /* Entry Internal 'UpdatePacketQueue': '<S49>:7' */
    /* Transition: '<S49>:20' */
    gbyk_v4b_DW.is_UpdatePacketQueue = gbyk_v4b_IN_AddPacketToQueue;
    gbyk_v4b_DW.is_active_SendControlMachine = 1U;

    /* Entry Internal 'SendControlMachine': '<S49>:4' */
    /* Transition: '<S49>:236' */
    if (gbyk_v4b_DW.is_SendControlMachine != gbyk_v4b_IN_Fixed) {
      gbyk_v4b_DW.is_SendControlMachine = gbyk_v4b_IN_Fixed;

      /* Entry 'Fixed': '<S49>:375' */
      gbyk_v4b_B.resetUDP = 0.0;
    }

    /* Entry Internal 'Fixed': '<S49>:375' */
    /* Transition: '<S49>:381' */
    if (gbyk_v4b_DW.is_Fixed != gbyk_v4b_IN_Idle) {
      gbyk_v4b_DW.is_Fixed = gbyk_v4b_IN_Idle;

      /* Entry 'Idle': '<S49>:391' */
      /*  Wait to acquire a new packet to send. */
    }

    gbyk_v4b_DW.is_active_FixMonitor = 1U;

    /* Entry Internal 'FixMonitor': '<S49>:183' */
    /* Transition: '<S49>:189' */
    gbyk_v4b_DW.is_FixMonitor = gbyk_v4b_IN_NoFix;
  } else {
    if (!((gbyk_v4b_DW.is_active_UpdatePacketQueue == 0U) ||
          (gbyk_v4b_DW.is_UpdatePacketQueue != gbyk_v4b_IN_AddPacketToQueue))) {
      /* During 'UpdatePacketQueue': '<S49>:7' */
      /* During 'AddPacketToQueue': '<S49>:6' */
      /* Transition: '<S49>:181' */
      if (gbyk_v4b_DW.sfEvent_mm == gbyk_v4b_event_e_data_ready_strobe) {
        /* Transition: '<S49>:180' */
        /*  Prepend the data of the new packet in the queue with the packet's index,
           a.k.a. "tracking number". */
        gbyk_v4b_DW.packet_index++;
        gbyk_v4b_DW.packet_queue[2 + 410 * (int32_T)gbyk_v4b_DW.queue_head] =
          (real32_T)gbyk_v4b_DW.packet_index;

        /* identify the packet version */
        gbyk_v4b_DW.packet_queue[1 + 410 * (int32_T)gbyk_v4b_DW.queue_head] =
          -12.0F;

        /*  Copy the new packet into the packet_queue. //CopyInput(); */
        recordPacket(&gbyk_v4b_DW.packet_queue[gbyk_v4b_DW.j + 410 * (int32_T)
                     gbyk_v4b_DW.queue_head], gbyk_v4b_FULL_PACKET_SIZE,
                     gbyk_v4b_B.TmpRTBAtSendControlMachineInport1,
                     gbyk_v4b_KINEMATIC_LEN);

        /*  Increment the head pointer of the packet_queue for the next packet. */
        gbyk_v4b_DW.queue_head = (uint32_T)fmod(gbyk_v4b_DW.queue_head + 1U,
          gbyk_v4b_DW.packet_queue_sz);
        if (gbyk_v4b_DW.packet_index == gbyk_v4b_B.max_packet_id) {
          /* Transition: '<S49>:37' */
          gbyk_v4b_DW.packet_index = 0U;
        } else {
          /* Transition: '<S49>:36' */
        }

        if (gbyk_v4b_DW.queue_head == gbyk_v4b_DW.queue_tail) {
          /* Transition: '<S49>:32' */
          gbyk_v4b_DW.queue_tail = (uint32_T)fmod(gbyk_v4b_DW.queue_tail + 1U,
            gbyk_v4b_DW.packet_queue_sz);
        } else {
          /* Transition: '<S49>:33' */
        }

        /* Transition: '<S49>:31' */
        gbyk_v4b_TrackQueueSize();
        gbyk_v4b_DW.is_UpdatePacketQueue = gbyk_v4b_IN_AddPacketToQueue;
      } else {
        /* Transition: '<S49>:182' */
        gbyk_v4b_DW.is_UpdatePacketQueue = gbyk_v4b_IN_AddPacketToQueue;
      }
    }

    if (gbyk_v4b_DW.is_active_SendControlMachine != 0U) {
      gbyk_v4b_SendControlMachine();
    }

    if (gbyk_v4b_DW.is_active_FixMonitor != 0U) {
      /* During 'FixMonitor': '<S49>:183' */
      switch (gbyk_v4b_DW.is_FixMonitor) {
       case gbyk_v4b_IN_Fix:
        /* During 'Fix': '<S49>:186' */
        if ((gbyk_v4b_DW.sfEvent_mm == gbyk_v4b_event_e_fast_clk) &&
            (gbyk_v4b_DW.temporalCounter_i2 >= 1000)) {
          /* Transition: '<S49>:298' */
          gbyk_v4b_DW.is_FixMonitor = gbyk_v4b_IN_NoFix;
        }
        break;

       case gbyk_v4b_IN_NoFix:
        /* During 'NoFix': '<S49>:184' */
        if (gbyk_v4b_B.queue_size_e > 2500.0) {
          /* Transition: '<S49>:187' */
          gbyk_v4b_DW.is_FixMonitor = gbyk_v4b_IN_Fix;
          gbyk_v4b_DW.temporalCounter_i2 = 0U;

          /* Entry 'Fix': '<S49>:186' */
          b_previousEvent = gbyk_v4b_DW.sfEvent_mm;
          gbyk_v4b_DW.sfEvent_mm = gbyk_v4b_event_e_reset_UDP;
          if (gbyk_v4b_DW.is_active_SendControlMachine != 0U) {
            gbyk_v4b_SendControlMachine();
          }

          gbyk_v4b_DW.sfEvent_mm = b_previousEvent;
        }
        break;

       default:
        /* Unreachable state, for coverage only */
        gbyk_v4b_DW.is_FixMonitor = gbyk_v4b_IN_NO_ACTIVE_CHILD_j;
        break;
      }
    }
  }
}

real_T rt_modd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T tmp;
  boolean_T y_0;
  boolean_T y_1;
  if (u1 == 0.0) {
    y = u0;
  } else {
    y_0 = ((!rtIsNaN(u0)) && (!rtIsInf(u0)));
    y_1 = ((!rtIsNaN(u1)) && (!rtIsInf(u1)));
    if (!(y_0 && y_1)) {
      y = (rtNaN);
    } else {
      tmp = u0 / u1;
      if (u1 <= floor(u1)) {
        y = u0 - floor(tmp) * u1;
      } else if (fabs(tmp - rt_roundd_snf(tmp)) <= DBL_EPSILON * fabs(tmp)) {
        y = 0.0;
      } else {
        y = (tmp - floor(tmp)) * u1;
      }
    }
  }

  return y;
}

/* Initial conditions for atomic system: '<S4>/Network Transfer Subsystem' */
void gbyk_v4b_NetworkTransferSubsystem_Init(void)
{
  int32_T i;

  /* InitializeConditions for Atomic SubSystem: '<S32>/Data Packing Subsystem' */
  /* InitializeConditions for UnitDelay: '<S53>/Unit Delay' */
  gbyk_v4b_DW.UnitDelay_DSTATE_a = gbyk_v4b_P.UnitDelay_InitialCondition;
  for (i = 0; i < 127; i++) {
    /* InitializeConditions for Memory: '<S48>/t-2' */
    gbyk_v4b_DW.t2_PreviousInput[i] = gbyk_v4b_P.t2_X0;

    /* InitializeConditions for Memory: '<S48>/t-1' */
    gbyk_v4b_DW.t1_PreviousInput[i] = gbyk_v4b_P.t1_X0;
  }

  /* End of InitializeConditions for SubSystem: '<S32>/Data Packing Subsystem' */

  /* InitializeConditions for RateTransition: '<S32>/TmpRTBAtSend Control MachineInport1' */
  for (i = 0; i < 400; i++) {
    gbyk_v4b_DW.TmpRTBAtSendControlMachineInport1_Buffer0[i] =
      gbyk_v4b_P.TmpRTBAtSendControlMachineInport1_X0;
  }

  /* End of InitializeConditions for RateTransition: '<S32>/TmpRTBAtSend Control MachineInport1' */

  /* InitializeConditions for Memory: '<S50>/Memory2' */
  gbyk_v4b_DW.Memory2_PreviousInput_a = gbyk_v4b_P.Memory2_X0;

  /* InitializeConditions for RateTransition: '<S50>/Rate Transition2' */
  gbyk_v4b_DW.RateTransition2_Buffer0_p[0] = gbyk_v4b_P.RateTransition2_X0;
  gbyk_v4b_DW.RateTransition2_Buffer0_p[1] = gbyk_v4b_P.RateTransition2_X0;
  gbyk_v4b_DW.RateTransition2_Buffer0_p[2] = gbyk_v4b_P.RateTransition2_X0;

  /* InitializeConditions for RateTransition: '<S32>/TmpRTBAtforce strobeOutport1' */
  gbyk_v4b_DW.TmpRTBAtforcestrobeOutport1_Buffer0 =
    gbyk_v4b_P.TmpRTBAtforcestrobeOutport1_X0;
  gbyk_v4b_DW.is_active_FixMonitor = 0U;
  gbyk_v4b_DW.is_FixMonitor = gbyk_v4b_IN_NO_ACTIVE_CHILD_j;
  gbyk_v4b_DW.temporalCounter_i2 = 0U;
  gbyk_v4b_DW.is_active_SendControlMachine = 0U;
  gbyk_v4b_DW.is_SendControlMachine = gbyk_v4b_IN_NO_ACTIVE_CHILD_j;
  gbyk_v4b_DW.is_Fixed = gbyk_v4b_IN_NO_ACTIVE_CHILD_j;
  gbyk_v4b_DW.temporalCounter_i1_o = 0U;
  gbyk_v4b_DW.temporalCounter_i3 = 0U;
  gbyk_v4b_DW.is_active_UpdatePacketQueue = 0U;
  gbyk_v4b_DW.is_UpdatePacketQueue = gbyk_v4b_IN_NO_ACTIVE_CHILD_j;
  gbyk_v4b_DW.is_active_c8_General = 0U;
  gbyk_v4b_DW.queue_tail = 0U;
  gbyk_v4b_DW.packet_index = 0U;
  for (i = 0; i < 20500000; i++) {
    gbyk_v4b_DW.packet_queue[i] = 0.0F;
  }

  gbyk_v4b_DW.packet_queue_sz = 50000.0;
  gbyk_v4b_DW.i = 0;
  gbyk_v4b_DW.j = 0;
  gbyk_v4b_DW.outstanding_packet_index = 0.0;
  gbyk_v4b_DW.queue_head = 0U;
  gbyk_v4b_B.resetUDP = 0.0;
  for (i = 0; i < 410; i++) {
    gbyk_v4b_B.data_out[i] = 0.0F;
  }

  gbyk_v4b_B.queue_size_e = 0.0;
  gbyk_v4b_B.total_timeouts = 0.0;

  /* InitializeConditions for Chart: '<S32>/Send Control Machine' incorporates:
   *  InitializeConditions for SubSystem: '<S32>/UDP Send Subsystem'
   */
  gbyk_v4b_UDPSendSubsystem_Init();

  /* InitializeConditions for RateTransition: '<S32>/TmpRTBAtforce strobeInport1' */
  gbyk_v4b_DW.TmpRTBAtforcestrobeInport1_Buffer0 =
    gbyk_v4b_P.TmpRTBAtforcestrobeInport1_X0;

  /* InitializeConditions for MATLAB Function: '<S32>/force strobe' */
  gbyk_v4b_DW.counter = 0.0;
}

/* Start for atomic system: '<S4>/Network Transfer Subsystem' */
void gbyk_v4b_NetworkTransferSubsystem_Start(void)
{
  int32_T i;

  /* Start for Atomic SubSystem: '<S32>/Data Packing Subsystem' */
  /* Start for Width: '<S48>/Width' */
  gbyk_v4b_B.Width = 127.0;

  /* End of Start for SubSystem: '<S32>/Data Packing Subsystem' */

  /* Start for RateTransition: '<S32>/TmpRTBAtSend Control MachineInport1' */
  for (i = 0; i < 400; i++) {
    gbyk_v4b_B.TmpRTBAtSendControlMachineInport1[i] =
      gbyk_v4b_P.TmpRTBAtSendControlMachineInport1_X0;
  }

  /* End of Start for RateTransition: '<S32>/TmpRTBAtSend Control MachineInport1' */

  /* Start for RateTransition: '<S50>/Rate Transition2' */
  gbyk_v4b_B.RateTransition2_js[0] = gbyk_v4b_P.RateTransition2_X0;
  gbyk_v4b_B.RateTransition2_js[1] = gbyk_v4b_P.RateTransition2_X0;
  gbyk_v4b_B.RateTransition2_js[2] = gbyk_v4b_P.RateTransition2_X0;

  /* Level2 S-Function Block: '<S50>/UDP Receive' (BKINUDPReceiveRead) */
  {
    SimStruct *rts = gbyk_v4b_M->childSfunctions[2];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for Constant: '<S32>/max_packet_id' */
  gbyk_v4b_B.max_packet_id = gbyk_v4b_P.max_packet_id_Value;

  /* Start for RateTransition: '<S32>/TmpRTBAtforce strobeOutport1' */
  gbyk_v4b_B.TmpRTBAtforcestrobeOutport1 =
    gbyk_v4b_P.TmpRTBAtforcestrobeOutport1_X0;

  /* Start for DiscretePulseGenerator: '<S32>/Task Clock' */
  gbyk_v4b_DW.clockTickCounter_e = 0;

  /* Start for Chart: '<S32>/Send Control Machine' incorporates:
   *  Start for SubSystem: '<S32>/UDP Send Subsystem'
   */
  gbyk_v4b_UDPSendSubsystem_Start();

  /* Start for RateTransition: '<S32>/TmpRTBAtforce strobeInport1' */
  gbyk_v4b_B.TmpRTBAtforcestrobeInport1 =
    gbyk_v4b_P.TmpRTBAtforcestrobeInport1_X0;

  /* Level2 S-Function Block: '<S50>/UDP Receive Port Reset' (BKINUDPReceiveInit) */
  {
    SimStruct *rts = gbyk_v4b_M->childSfunctions[3];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }
}

/* Outputs for atomic system: '<S4>/Network Transfer Subsystem' */
void gbyk_v4b_NetworkTransferSubsystemTID0(void)
{
  boolean_T tmp;
  ZCEventType zcEvent_idx_0;
  ZCEventType zcEvent_idx_1;
  ZCEventType zcEvent_idx_2;
  real32_T tmp_0;

  /* DataTypeConversion: '<S32>/Data Type Conversion2' incorporates:
   *  Constant: '<S32>/runID'
   */
  gbyk_v4b_B.DataTypeConversion2_k = (real32_T)gbyk_v4b_P.runID_Value;

  /* RateTransition: '<S32>/TmpRTBAtSend Control MachineInport1' */
  if (gbyk_v4b_M->Timing.RateInteraction.TID1_3) {
    memcpy(&gbyk_v4b_B.TmpRTBAtSendControlMachineInport1[0],
           &gbyk_v4b_DW.TmpRTBAtSendControlMachineInport1_Buffer0[0], 400U *
           sizeof(real32_T));
  }

  /* End of RateTransition: '<S32>/TmpRTBAtSend Control MachineInport1' */

  /* Memory: '<S50>/Memory2' */
  gbyk_v4b_B.trigger = gbyk_v4b_DW.Memory2_PreviousInput_a;

  /* RateTransition: '<S50>/Rate Transition2' */
  if (gbyk_v4b_M->Timing.RateInteraction.TID1_3) {
    gbyk_v4b_B.RateTransition2_js[0] = gbyk_v4b_DW.RateTransition2_Buffer0_p[0];
    gbyk_v4b_B.RateTransition2_js[1] = gbyk_v4b_DW.RateTransition2_Buffer0_p[1];
    gbyk_v4b_B.RateTransition2_js[2] = gbyk_v4b_DW.RateTransition2_Buffer0_p[2];
  }

  /* End of RateTransition: '<S50>/Rate Transition2' */

  /* Level2 S-Function Block: '<S50>/UDP Receive' (BKINUDPReceiveRead) */
  {
    SimStruct *rts = gbyk_v4b_M->childSfunctions[2];
    sfcnOutputs(rts, 1);
  }

  /* Unpack: <S50>/Unpack */
  (void) memcpy(&gbyk_v4b_B.Unpack, &gbyk_v4b_B.Data[1],
                4);

  /* DataTypeConversion: '<S50>/Data Type Conversion' */
  tmp_0 = (real32_T)floor(gbyk_v4b_B.Unpack);
  if (rtIsNaNF(tmp_0) || rtIsInfF(tmp_0)) {
    tmp_0 = 0.0F;
  } else {
    tmp_0 = (real32_T)fmod(tmp_0, 4.2949673E+9F);
  }

  gbyk_v4b_B.DataTypeConversion_cb = tmp_0 < 0.0F ? (uint32_T)-(int32_T)
    (uint32_T)-tmp_0 : (uint32_T)tmp_0;

  /* End of DataTypeConversion: '<S50>/Data Type Conversion' */

  /* Constant: '<S32>/max_packet_id' */
  gbyk_v4b_B.max_packet_id = gbyk_v4b_P.max_packet_id_Value;

  /* RateTransition: '<S32>/TmpRTBAtforce strobeOutport1' */
  if (gbyk_v4b_M->Timing.RateInteraction.TID1_2) {
    gbyk_v4b_B.TmpRTBAtforcestrobeOutport1 =
      gbyk_v4b_DW.TmpRTBAtforcestrobeOutport1_Buffer0;
  }

  /* End of RateTransition: '<S32>/TmpRTBAtforce strobeOutport1' */

  /* DiscretePulseGenerator: '<S32>/Task Clock' */
  gbyk_v4b_B.TaskClock_a = (gbyk_v4b_DW.clockTickCounter_e <
    gbyk_v4b_P.TaskClock_Duty) && (gbyk_v4b_DW.clockTickCounter_e >= 0) ?
    gbyk_v4b_P.TaskClock_Amp : 0.0;
  if (gbyk_v4b_DW.clockTickCounter_e >= gbyk_v4b_P.TaskClock_Period - 1.0) {
    gbyk_v4b_DW.clockTickCounter_e = 0;
  } else {
    gbyk_v4b_DW.clockTickCounter_e++;
  }

  /* End of DiscretePulseGenerator: '<S32>/Task Clock' */

  /* Chart: '<S32>/Send Control Machine' incorporates:
   *  TriggerPort: '<S49>/ input events '
   */
  zcEvent_idx_0 = rt_ZCFcn(ANY_ZERO_CROSSING,
    &gbyk_v4b_PrevZCX.SendControlMachine_Trig_ZCE[0],
    (gbyk_v4b_B.TmpRTBAtforcestrobeOutport1));
  zcEvent_idx_1 = rt_ZCFcn(ANY_ZERO_CROSSING,
    &gbyk_v4b_PrevZCX.SendControlMachine_Trig_ZCE[1],
    (gbyk_v4b_B.Convert17));
  zcEvent_idx_2 = rt_ZCFcn(ANY_ZERO_CROSSING,
    &gbyk_v4b_PrevZCX.SendControlMachine_Trig_ZCE[2],
    (gbyk_v4b_B.TaskClock_a));
  tmp = (zcEvent_idx_0 != NO_ZCEVENT);
  tmp = (tmp || (zcEvent_idx_1 != NO_ZCEVENT));
  tmp = (tmp || (zcEvent_idx_2 != NO_ZCEVENT));
  if (tmp) {
    gbyk_v4b_B.inputevents_o[0] = (int8_T)zcEvent_idx_0;
    gbyk_v4b_B.inputevents_o[1] = (int8_T)zcEvent_idx_1;
    gbyk_v4b_B.inputevents_o[2] = (int8_T)zcEvent_idx_2;

    /* Gateway: DataLogging/Network Transfer Subsystem/Send Control Machine */
    if (gbyk_v4b_B.inputevents_o[0U] == 1) {
      /* Event: '<S49>:67' */
      gbyk_v4b_DW.sfEvent_mm = gbyk_v4b_event_e_data_ready_strobe;
      gbyk_v4b_chartstep_c8_General();
    }

    if (gbyk_v4b_B.inputevents_o[1U] == 1) {
      if (gbyk_v4b_DW.temporalCounter_i1_o < 15U) {
        gbyk_v4b_DW.temporalCounter_i1_o++;
      }

      if (gbyk_v4b_DW.temporalCounter_i2 < 1023U) {
        gbyk_v4b_DW.temporalCounter_i2++;
      }

      /* Event: '<S49>:208' */
      gbyk_v4b_DW.sfEvent_mm = gbyk_v4b_event_e_clk;
      gbyk_v4b_chartstep_c8_General();
    }

    if (gbyk_v4b_B.inputevents_o[2U] != 0) {
      if (gbyk_v4b_DW.temporalCounter_i3 < 3U) {
        gbyk_v4b_DW.temporalCounter_i3++;
      }

      /* Event: '<S49>:258' */
      gbyk_v4b_DW.sfEvent_mm = gbyk_v4b_event_e_fast_clk;
      gbyk_v4b_chartstep_c8_General();
    }

    gbyk_v4b_DW.SendControlMachine_SubsysRanBC = 4;
  }

  /* DataTypeConversion: '<S32>/Queue Size' */
  gbyk_v4b_B.queue_size = gbyk_v4b_B.queue_size_e;

  /* DataTypeConversion: '<S32>/Total Timeouts' */
  gbyk_v4b_B.timeouts = gbyk_v4b_B.total_timeouts;

  /* RateTransition: '<S50>/Rate Transition1' */
  if (gbyk_v4b_M->Timing.RateInteraction.TID1_3) {
    gbyk_v4b_B.RqstUDPReset = gbyk_v4b_B.UDPReceive_o6;
  }

  /* End of RateTransition: '<S50>/Rate Transition1' */
}

/* Outputs for atomic system: '<S4>/Network Transfer Subsystem' */
void gbyk_v4b_NetworkTransferSubsystemTID2(void)
{
  /* RateTransition: '<S32>/TmpRTBAtforce strobeInport1' */
  if (gbyk_v4b_M->Timing.RateInteraction.TID2_3) {
    gbyk_v4b_B.TmpRTBAtforcestrobeInport1 =
      gbyk_v4b_DW.TmpRTBAtforcestrobeInport1_Buffer0;
  }

  /* End of RateTransition: '<S32>/TmpRTBAtforce strobeInport1' */

  /* MATLAB Function: '<S32>/force strobe' */
  /* MATLAB Function 'DataLogging/Network Transfer Subsystem/force strobe': '<S52>:1' */
  /*  DEX-3234 - it turns out that if we try to send 1 kinematic packet of data */
  /*  per UDP packet then the "strobe" from the packet creating sub-system just */
  /*  stays high - i.e. always send data. The trouble is that signal is used by */
  /*  the Sending state flow diagram and in order to be used as a proper */
  /*  stateflow input event the strobe has to change. This code runs at double */
  /*  the speed of the packet creating sub system. That allows us to force the */
  /*  strobe to zero on alternate steps so that we can properly signal on a true */
  /*  strobe going to 1. */
  /* '<S52>:1:17' */
  gbyk_v4b_DW.counter++;
  if (gbyk_v4b_DW.counter - floor(gbyk_v4b_DW.counter / 2.0) * 2.0 == 0.0) {
    /* '<S52>:1:19' */
    /* '<S52>:1:20' */
    gbyk_v4b_B.strobe_out = 0.0;

    /* '<S52>:1:21' */
    gbyk_v4b_DW.counter = 0.0;
  } else {
    /* '<S52>:1:23' */
    gbyk_v4b_B.strobe_out = gbyk_v4b_B.TmpRTBAtforcestrobeInport1;
  }

  /* End of MATLAB Function: '<S32>/force strobe' */
}

/* Outputs for atomic system: '<S4>/Network Transfer Subsystem' */
void gbyk_v4b_NetworkTransferSubsystemTID3(void)
{
  int32_T i;
  real_T u0;
  real_T u1;

  /* Outputs for Atomic SubSystem: '<S32>/Data Packing Subsystem' */
  /* UnitDelay: '<S53>/Unit Delay' */
  gbyk_v4b_B.UnitDelay_h = gbyk_v4b_DW.UnitDelay_DSTATE_a;

  /* Sum: '<S53>/Sum' incorporates:
   *  Constant: '<S53>/Constant'
   */
  gbyk_v4b_B.Sum = gbyk_v4b_B.UnitDelay_h + gbyk_v4b_P.Constant_Value;

  /* DataTypeConversion: '<S48>/Data Type Conversion' */
  for (i = 0; i < 17; i++) {
    gbyk_v4b_B.DataTypeConversion_p1[i] = (real32_T)
      gbyk_v4b_B.RateTransition1_i[i];
  }

  gbyk_v4b_B.DataTypeConversion_p1[17] = (real32_T)
    gbyk_v4b_B.RateTransition2_ea[0];
  gbyk_v4b_B.DataTypeConversion_p1[18] = (real32_T)
    gbyk_v4b_B.RateTransition2_ea[1];
  gbyk_v4b_B.DataTypeConversion_p1[19] = (real32_T)gbyk_v4b_B.KinarmDataWidth;
  for (i = 0; i < 68; i++) {
    gbyk_v4b_B.DataTypeConversion_p1[i + 20] = (real32_T)
      gbyk_v4b_B.ArmKinematics[i];
  }

  gbyk_v4b_B.DataTypeConversion_p1[88] = (real32_T)gbyk_v4b_B.RateTransition_c;
  for (i = 0; i < 20; i++) {
    gbyk_v4b_B.DataTypeConversion_p1[i + 89] = (real32_T)
      gbyk_v4b_B.RateTransition1_c[i];
  }

  for (i = 0; i < 18; i++) {
    gbyk_v4b_B.DataTypeConversion_p1[i + 109] = (real32_T)
      gbyk_v4b_B.RateTransition_d[i];
  }

  /* End of DataTypeConversion: '<S48>/Data Type Conversion' */

  /* Fcn: '<S48>/Ideal Frames Per Packet' */
  gbyk_v4b_B.IdealFramesPerPacket = floor(400.0 / gbyk_v4b_B.Width);

  /* MinMax: '<S48>/MinMax' incorporates:
   *  Constant: '<S48>/Max Frames Per Packet'
   */
  u0 = gbyk_v4b_P.MaxFramesPerPacket_Value;
  u1 = gbyk_v4b_B.IdealFramesPerPacket;
  if ((u0 <= u1) || rtIsNaN(u1)) {
    u1 = u0;
  }

  gbyk_v4b_B.MinMax_k = u1;

  /* End of MinMax: '<S48>/MinMax' */

  /* Math: '<S48>/Math Function' */
  gbyk_v4b_B.MathFunction_j = rt_modd_snf(gbyk_v4b_B.Sum, gbyk_v4b_B.MinMax_k);

  /* Sum: '<S48>/Subtract' incorporates:
   *  Constant: '<S48>/Max Frames Per Packet'
   */
  gbyk_v4b_B.Subtract_o = gbyk_v4b_P.MaxFramesPerPacket_Value -
    gbyk_v4b_B.MinMax_k;

  /* Product: '<S48>/Product' */
  gbyk_v4b_B.Product_l = gbyk_v4b_B.Width * gbyk_v4b_B.Subtract_o;

  /* RelationalOperator: '<S48>/Relational Operator' incorporates:
   *  Constant: '<S48>/Constant1'
   */
  gbyk_v4b_B.RelationalOperator = (gbyk_v4b_P.Constant1_Value ==
    gbyk_v4b_B.MathFunction_j);
  for (i = 0; i < 127; i++) {
    /* Memory: '<S48>/t-2' */
    gbyk_v4b_B.t2[i] = gbyk_v4b_DW.t2_PreviousInput[i];

    /* Memory: '<S48>/t-1' */
    gbyk_v4b_B.t1[i] = gbyk_v4b_DW.t1_PreviousInput[i];

    /* SignalConversion: '<S48>/TmpSignal ConversionAtSelectorInport1' */
    gbyk_v4b_B.TmpSignalConversionAtSelectorInport1[i] = gbyk_v4b_B.t2[i];
  }

  /* SignalConversion: '<S48>/TmpSignal ConversionAtSelectorInport1' incorporates:
   *  Constant: '<S48>/Constant'
   */
  memcpy(&gbyk_v4b_B.TmpSignalConversionAtSelectorInport1[127], &gbyk_v4b_B.t1[0],
         127U * sizeof(real32_T));
  memcpy(&gbyk_v4b_B.TmpSignalConversionAtSelectorInport1[254],
         &gbyk_v4b_B.DataTypeConversion_p1[0], 127U * sizeof(real32_T));
  memcpy(&gbyk_v4b_B.TmpSignalConversionAtSelectorInport1[381],
         &gbyk_v4b_P.Constant_Value_g[0], 400U * sizeof(real32_T));

  /* Selector: '<S48>/Selector' */
  memcpy(&gbyk_v4b_B.Selector_e[0],
         &gbyk_v4b_B.TmpSignalConversionAtSelectorInport1[(int32_T)
         gbyk_v4b_B.Product_l], 400U * sizeof(real32_T));

  /* End of Outputs for SubSystem: '<S32>/Data Packing Subsystem' */

  /* Level2 S-Function Block: '<S50>/UDP Receive Port Reset' (BKINUDPReceiveInit) */
  {
    SimStruct *rts = gbyk_v4b_M->childSfunctions[3];
    sfcnOutputs(rts, 3);
  }
}

/* Update for atomic system: '<S4>/Network Transfer Subsystem' */
void gbyk_v4b_NetworkTransferSubsystem_UpdateTID0(void)
{
  /* Update for Memory: '<S50>/Memory2' */
  gbyk_v4b_DW.Memory2_PreviousInput_a = gbyk_v4b_B.resetUDP;
}

/* Update for atomic system: '<S4>/Network Transfer Subsystem' */
void gbyk_v4b_NetworkTransferSubsystem_UpdateTID2(void)
{
  /* Update for RateTransition: '<S32>/TmpRTBAtforce strobeOutport1' */
  gbyk_v4b_DW.TmpRTBAtforcestrobeOutport1_Buffer0 = gbyk_v4b_B.strobe_out;
}

/* Update for atomic system: '<S4>/Network Transfer Subsystem' */
void gbyk_v4b_NetworkTransferSubsystem_UpdateTID3(void)
{
  int32_T i;

  /* Update for Atomic SubSystem: '<S32>/Data Packing Subsystem' */
  /* Update for UnitDelay: '<S53>/Unit Delay' */
  gbyk_v4b_DW.UnitDelay_DSTATE_a = gbyk_v4b_B.Sum;
  for (i = 0; i < 127; i++) {
    /* Update for Memory: '<S48>/t-2' */
    gbyk_v4b_DW.t2_PreviousInput[i] = gbyk_v4b_B.t1[i];

    /* Update for Memory: '<S48>/t-1' */
    gbyk_v4b_DW.t1_PreviousInput[i] = gbyk_v4b_B.DataTypeConversion_p1[i];
  }

  /* End of Update for SubSystem: '<S32>/Data Packing Subsystem' */

  /* Update for RateTransition: '<S32>/TmpRTBAtSend Control MachineInport1' */
  memcpy(&gbyk_v4b_DW.TmpRTBAtSendControlMachineInport1_Buffer0[0],
         &gbyk_v4b_B.Selector_e[0], 400U * sizeof(real32_T));

  /* Update for RateTransition: '<S50>/Rate Transition2' */
  gbyk_v4b_DW.RateTransition2_Buffer0_p[0] = gbyk_v4b_B.UDPReceivePortReset_o2[0];
  gbyk_v4b_DW.RateTransition2_Buffer0_p[1] = gbyk_v4b_B.UDPReceivePortReset_o2[1];
  gbyk_v4b_DW.RateTransition2_Buffer0_p[2] = gbyk_v4b_B.UDPReceivePortReset_o2[2];

  /* Update for RateTransition: '<S32>/TmpRTBAtforce strobeInport1' */
  gbyk_v4b_DW.TmpRTBAtforcestrobeInport1_Buffer0 = gbyk_v4b_B.RelationalOperator;
}

/* Termination for atomic system: '<S4>/Network Transfer Subsystem' */
void gbyk_v4b_NetworkTransferSubsystem_Term(void)
{
  /* Level2 S-Function Block: '<S50>/UDP Receive' (BKINUDPReceiveRead) */
  {
    SimStruct *rts = gbyk_v4b_M->childSfunctions[2];
    sfcnTerminate(rts);
  }

  /* Terminate for Chart: '<S32>/Send Control Machine' incorporates:
   *  Terminate for SubSystem: '<S32>/UDP Send Subsystem'
   */
  gbyk_v4b_UDPSendSubsystem_Term();    /* Level2 S-Function Block: '<S50>/UDP Receive Port Reset' (BKINUDPReceiveInit) */

  {
    SimStruct *rts = gbyk_v4b_M->childSfunctions[3];
    sfcnTerminate(rts);
  }
}
