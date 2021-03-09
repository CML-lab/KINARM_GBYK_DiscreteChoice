/*
 * Code generation for system system '<S4>/Poll KINARM'
 *
 * Model                      : gbyk_v4b
 * Model version              : 1.2667
 * Simulink Coder version : 8.8.1 (R2015aSP1) 04-Sep-2015
 * C source code generated on : Tue Sep 15 15:02:19 2020
 *
 * Note that the functions contained in this file are part of a Simulink
 * model, and are not self-contained algorithms.
 */

#include "gbyk_v4b_PollKINARM.h"

/* Include model header file for global data */
#include "gbyk_v4b.h"
#include "gbyk_v4b_private.h"

/* Named constants for Chart: '<S88>/AbsEncoder machine' */
#define gbyk_v4b_CALL_EVENT_h          (-1)
#define gbyk_v4b_IN_Complete           ((uint8_T)1U)
#define gbyk_v4b_IN_Done               ((uint8_T)2U)
#define gbyk_v4b_IN_NO_ACTIVE_CHILD    ((uint8_T)0U)
#define gbyk_v4b_IN_PollingComplete    ((uint8_T)3U)
#define gbyk_v4b_IN_ReadNext           ((uint8_T)4U)
#define gbyk_v4b_IN_ReadNextEncoder    ((uint8_T)5U)
#define gbyk_v4b_IN_Received           ((uint8_T)6U)
#define gbyk_v4b_IN_disable            ((uint8_T)7U)
#define gbyk_v4b_IN_disable1           ((uint8_T)8U)
#define gbyk_v4b_IN_disableRead        ((uint8_T)9U)
#define gbyk_v4b_IN_encoderReadSetup   ((uint8_T)10U)
#define gbyk_v4b_IN_pollReceived       ((uint8_T)11U)
#define gbyk_v4b_IN_receivedEncoder    ((uint8_T)12U)
#define gbyk_v4b_IN_setup              ((uint8_T)13U)
#define gbyk_v4b_IN_startPolling       ((uint8_T)14U)

/* Named constants for Chart: '<S75>/SDO read machine' */
#define gbyk_v4b_CALL_EVENT_lt         (-1)
#define gbyk_v4b_IN_Done_e             ((uint8_T)1U)
#define gbyk_v4b_IN_NO_ACTIVE_CHILD_c  ((uint8_T)0U)
#define gbyk_v4b_IN_ReadNextFloat      ((uint8_T)2U)
#define gbyk_v4b_IN_ReadNextInt        ((uint8_T)3U)
#define gbyk_v4b_IN_ReceivedFloat      ((uint8_T)4U)
#define gbyk_v4b_IN_ReceivedInt        ((uint8_T)5U)
#define gbyk_v4b_IN_disableFloat       ((uint8_T)6U)
#define gbyk_v4b_IN_disableInt         ((uint8_T)7U)
#define gbyk_v4b_IN_setup_g            ((uint8_T)8U)
#define gbyk_v4b_IN_startFloats        ((uint8_T)9U)

/* Named constants for Chart: '<S91>/SDO read machine' */
#define gbyk_v4b_CALL_EVENT_lg         (-1)
#define gbyk_v4b_IN_NO_ACTIVE_CHILD_b  ((uint8_T)0U)
#define gbyk_v4b_IN_ReadNext_n         ((uint8_T)1U)
#define gbyk_v4b_IN_disable_a          ((uint8_T)2U)
#define gbyk_v4b_IN_setup_a            ((uint8_T)3U)

/* Named constants for Chart: '<S92>/SDO write machine' */
#define gbyk_v4b_CALL_EVENT_if         (-1)
#define gbyk_v4b_IN_NO_ACTIVE_CHILD_f  ((uint8_T)0U)
#define gbyk_v4b_IN_ReadNext_o         ((uint8_T)1U)
#define gbyk_v4b_IN_disable_g          ((uint8_T)2U)
#define gbyk_v4b_IN_setup_i            ((uint8_T)3U)

/* Named constants for Chart: '<S154>/Read EMCY' */
#define gbyk_v4b_CALL_EVENT_jm         (-1)
#define gbyk_v4b_IN_DoneClearing       ((uint8_T)1U)
#define gbyk_v4b_IN_NO_ACTIVE_CHILD_fq ((uint8_T)0U)
#define gbyk_v4b_IN_ReadNextEMCY       ((uint8_T)2U)
#define gbyk_v4b_IN_ReceivedFloat_d    ((uint8_T)3U)
#define gbyk_v4b_IN_StartOverwrite     ((uint8_T)4U)
#define gbyk_v4b_IN_StartReadingCount  ((uint8_T)5U)
#define gbyk_v4b_IN_disableCount       ((uint8_T)6U)
#define gbyk_v4b_IN_disableEMCY        ((uint8_T)7U)
#define gbyk_v4b_IN_setup_c            ((uint8_T)8U)
#define gbyk_v4b_IN_startEMCYs         ((uint8_T)9U)

/* Named constants for Chart: '<S102>/Read EMCY' */
#define gbyk_v4b_CALL_EVENT_mm         (-1)
#define gbyk_v4b_IN_DoneClearing_g     ((uint8_T)1U)
#define gbyk_v4b_IN_NO_ACTIVE_CHILD_jq ((uint8_T)0U)
#define gbyk_v4b_IN_ReadNextEMCY_e     ((uint8_T)2U)
#define gbyk_v4b_IN_ReceivedFloat_m    ((uint8_T)3U)
#define gbyk_v4b_IN_StartOverwrite_c   ((uint8_T)4U)
#define gbyk_v4b_IN_StartReadingCount_f ((uint8_T)5U)
#define gbyk_v4b_IN_disableCount_b     ((uint8_T)6U)
#define gbyk_v4b_IN_disableEMCY_g      ((uint8_T)7U)
#define gbyk_v4b_IN_setup_k            ((uint8_T)8U)
#define gbyk_v4b_IN_startEMCYs_h       ((uint8_T)9U)

/* Named constants for Chart: '<S115>/Read EMCY' */
#define gbyk_v4b_CALL_EVENT_il         (-1)
#define gbyk_v4b_IN_DoneClearing_m     ((uint8_T)1U)
#define gbyk_v4b_IN_NO_ACTIVE_CHILD_p  ((uint8_T)0U)
#define gbyk_v4b_IN_ReadNextEMCY_l     ((uint8_T)2U)
#define gbyk_v4b_IN_ReceivedFloat_a    ((uint8_T)3U)
#define gbyk_v4b_IN_StartOverwrite_b   ((uint8_T)4U)
#define gbyk_v4b_IN_StartReadingCount_k ((uint8_T)5U)
#define gbyk_v4b_IN_disableCount_c     ((uint8_T)6U)
#define gbyk_v4b_IN_disableEMCY_m      ((uint8_T)7U)
#define gbyk_v4b_IN_setup_m            ((uint8_T)8U)
#define gbyk_v4b_IN_startEMCYs_hm      ((uint8_T)9U)

/* Named constants for Chart: '<S34>/control read write' */
#define gbyk_v4b_IN_NO_ACTIVE_CHILD_e  ((uint8_T)0U)
#define gbyk_v4b_IN_RunECat            ((uint8_T)1U)
#define gbyk_v4b_IN_RunPMAC            ((uint8_T)2U)
#define gbyk_v4b_IN_RunSim             ((uint8_T)3U)

/* Forward declaration for local functions */
static void gbyk_v4b_clearValues(B_SDOreadmachine_gbyk_v4b_T *localB);

/* Forward declaration for local functions */
static void gbyk_v4b_circshift_j(real_T a[12]);
static void gbyk_v4b_convertL1L2ToShoElb(const real_T L1L2[4], const real_T
  orientation[2], real_T shoElb[4]);
static void gbyk_v4b_convertL1L2ToShoElbVel(const real_T L1L2[4], const real_T
  orientation[2], real_T shoElb[4]);
static void gbyk_v4b_reduce(const int32_T a_sizes[2], int32_T absp[2], boolean_T
  shiftright[2]);
static void gbyk_v4b_circshift_c(real_T a_data[], int32_T a_sizes[2]);
static void gbyk_v4b_updateQueue(const real_T arr_data[], const int32_T
  arr_sizes[2], const real_T newVals[4], real_T encData_data[], int32_T
  encData_sizes[2]);
static void gbyk_v4b_calcDT(const real_T positions_data[], const int32_T
  positions_sizes[2], real_T stepTime, real_T velocity[4]);
static void gbyk_v4b_buildEncoderData(real_T queueSize, const real_T shoElb[4],
  real_T encData_data[], int32_T encData_sizes[2]);
static void gbyk_v4b_buildEncoderData_j(real_T queueSize, real_T encData_data[],
  int32_T encData_sizes[2]);
static void gbyk_v4b_buildKin(const real_T angles[2], const real_T
  velocities_data[], const int32_T velocities_sizes[2], real_T stepTime, const
  uint32_T motorStatuses[2], real_T kinOut[10]);
static void gbyk_v4b_buildKinPrimary(const real_T angles[2], const real_T
  velocities_data[], const int32_T velocities_sizes[2], real_T stepTime, const
  uint32_T motorStatuses[2], real_T filteredVelocities_data[], int32_T
  filteredVelocities_sizes[2], real_T kinOut[10]);
static void gbyk_v4b_insertVal(real_T arr[3], real_T v);

/*
 * Output and update for atomic system:
 *    '<S99>/parse status register'
 *    '<S112>/parse status register1'
 *    '<S151>/parse status register1'
 *    '<S164>/parse status register1'
 */
void gbyk_v4b_parsestatusregister(uint32_T rtu_statusRegister,
  B_parsestatusregister_gbyk_v4b_T *localB)
{
  int32_T ampStatus;

  /* MATLAB Function 'EtherCAT Subsystem/Arm 1/A1M1/A1M1 PDOs/parse status register': '<S104>:1' */
  /* The contents of the status register are detailed in MAN_G_CR.pdf */
  /* '<S104>:1:6' */
  ampStatus = (int32_T)(rtu_statusRegister & 15U);

  /*  15 = 0xF */
  if (ampStatus == 0) {
    /* '<S104>:1:7' */
    /* '<S104>:1:8' */
    localB->allOK = 1U;
  } else {
    /* '<S104>:1:10' */
    localB->allOK = 0U;
  }

  /* '<S104>:1:12' */
  localB->servoEnabled = rtu_statusRegister >> 4U & 1U;

  /* '<S104>:1:13' */
  localB->faultFound = rtu_statusRegister >> 6U & 1U;

  /* '<S104>:1:14' */
  localB->currentLimitEnabled = rtu_statusRegister >> 13U & 1U;

  /* '<S104>:1:15' */
  localB->motorOn = rtu_statusRegister >> 22U & 1U;
  if (rtu_statusRegister == 0U) {
    /* '<S104>:1:17' */
    /* '<S104>:1:18' */
    localB->eStopOut = 0U;

    /* if the PDO's are not working yet then assume the estops are not pressed */
  } else {
    /* '<S104>:1:20' */
    /* bits 14 and 15 */
    /* '<S104>:1:21' */
    localB->eStopOut = (rtu_statusRegister >> 14U & 3U) ^ 3U;
  }

  localB->ampStatus = (uint32_T)ampStatus;
}

/*
 * Initial conditions for atomic system:
 *    '<S102>/fault monitor'
 *    '<S115>/fault monitor'
 *    '<S154>/fault monitor'
 *    '<S167>/fault monitor'
 */
void gbyk_v4b_faultmonitor_Init(DW_faultmonitor_gbyk_v4b_T *localDW)
{
  localDW->preOpCounter = 0.0;
}

/*
 * Output and update for atomic system:
 *    '<S102>/fault monitor'
 *    '<S115>/fault monitor'
 *    '<S154>/fault monitor'
 *    '<S167>/fault monitor'
 */
void gbyk_v4b_faultmonitor(uint16_T rtu_StatusWord, B_faultmonitor_gbyk_v4b_T
  *localB, DW_faultmonitor_gbyk_v4b_T *localDW)
{
  /* MATLAB Function 'EtherCAT Subsystem/Arm 1/A1M1/EMCY Message pump/fault monitor': '<S109>:1' */
  /* when we are not yet in the OP state this will always return 0 since */
  /* PDO's don't work yet. We can still read SDO's though, so for safety */
  /* we will trigger an attempt to read every 5ms just in case there is */
  /* an EMCY message fired off at this point. */
  if (rtu_StatusWord == 0) {
    /* '<S109>:1:13' */
    /* '<S109>:1:14' */
    localDW->preOpCounter++;
    if (localDW->preOpCounter >= 20.0) {
      /* '<S109>:1:16' */
      /* '<S109>:1:17' */
      localB->triggerFaultRead = 1.0;

      /* '<S109>:1:18' */
      localDW->preOpCounter = 0.0;
    } else {
      /* '<S109>:1:20' */
      localB->triggerFaultRead = 0.0;
    }
  } else {
    /* a fault is binary x0xx1000 */
    /* '<S109>:1:26' */
    /* '<S109>:1:27' */
    if (((rtu_StatusWord & 15) == 8) && (((int32_T)((uint32_T)rtu_StatusWord >>
           6) & 1) == 0)) {
      /* '<S109>:1:29' */
      /* '<S109>:1:30' */
      localB->triggerFaultRead = 1.0;
    } else {
      /* '<S109>:1:32' */
      localB->triggerFaultRead = 0.0;
    }
  }
}

/*
 * Initial conditions for atomic system:
 *    '<S102>/fault monitor1'
 *    '<S115>/fault monitor1'
 *    '<S154>/fault monitor1'
 *    '<S167>/fault monitor1'
 */
void gbyk_v4b_faultmonitor1_Init(DW_faultmonitor1_gbyk_v4b_T *localDW)
{
  localDW->lastRegister = 0U;
  localDW->underVoltageCounter = 0.0;
}

/*
 * Output and update for atomic system:
 *    '<S102>/fault monitor1'
 *    '<S115>/fault monitor1'
 *    '<S154>/fault monitor1'
 *    '<S167>/fault monitor1'
 */
void gbyk_v4b_faultmonitor1(const real_T rtu_SDOEMCY[3], uint32_T
  rtu_registerInfo, uint32_T rtu_registerInfo_b, uint32_T rtu_registerInfo_g,
  real_T rtu_drive, real_T rtu_statusWord, B_faultmonitor1_gbyk_v4b_T *localB,
  DW_faultmonitor1_gbyk_v4b_T *localDW)
{
  int32_T EMCY;
  uint32_T registerEMCY;
  int32_T recordLast;
  uint32_T c;

  /* SignalConversion: '<S110>/TmpSignal ConversionAt SFunction Inport2' */
  localB->TmpSignalConversionAtSFunctionInport2[0] = rtu_registerInfo;
  localB->TmpSignalConversionAtSFunctionInport2[1] = rtu_registerInfo_b;
  localB->TmpSignalConversionAtSFunctionInport2[2] = rtu_registerInfo_g;

  /* MATLAB Function 'EtherCAT Subsystem/Arm 1/A1M1/EMCY Message pump/fault monitor1': '<S110>:1' */
  /* grab the first 22 bits of the SR - any higher and the conversions from */
  /* uint32 to double to single loses information */
  /* '<S110>:1:12' */
  c = localB->TmpSignalConversionAtSFunctionInport2[2] & 4194303U;
  if (rtu_SDOEMCY[0] != 0.0) {
    /* '<S110>:1:14' */
    /* '<S110>:1:15' */
    localB->EMCYMsg[0] = rtu_SDOEMCY[0];
    localB->EMCYMsg[1] = rtu_SDOEMCY[1];
    localB->EMCYMsg[2] = rtu_SDOEMCY[2];
    localB->EMCYMsg[3] = rtu_statusWord;
    localB->EMCYMsg[4] = c;
  } else {
    /* '<S110>:1:19' */
    EMCY = 0;

    /* '<S110>:1:20' */
    registerEMCY = localB->TmpSignalConversionAtSFunctionInport2[0];

    /* '<S110>:1:21' */
    if (localB->TmpSignalConversionAtSFunctionInport2[1] != 0U) {
      /* '<S110>:1:24' */
      registerEMCY = 32U;
    }

    /* The status register's first 4 bits are the amp status. The meaning of the */
    /* bits can be found in MAN-G-CR v1.501.pdf under the StatusRegister section */
    if (localDW->lastRegister != registerEMCY) {
      /* '<S110>:1:29' */
      /* '<S110>:1:30' */
      recordLast = 1;
      if (registerEMCY == 3U) {
        /* '<S110>:1:32' */
        /* '<S110>:1:33' */
        localDW->underVoltageCounter++;
        if (localDW->underVoltageCounter >= 2.0) {
          /* '<S110>:1:34' */
          /* '<S110>:1:35' */
          EMCY = 12576;

          /* 0x3120 - Undervoltage */
        } else {
          /* '<S110>:1:37' */
          recordLast = 0;
        }
      } else if (registerEMCY == 5U) {
        /* '<S110>:1:39' */
        /* '<S110>:1:40' */
        EMCY = 13072;

        /* 0x3310 - Overvoltage */
      } else if (registerEMCY == 11U) {
        /* '<S110>:1:41' */
        /* '<S110>:1:42' */
        EMCY = 9024;

        /* 0x2340 - short protection */
      } else if (registerEMCY == 13U) {
        /* '<S110>:1:43' */
        /* '<S110>:1:44' */
        EMCY = 17168;

        /* 0x4310 - over temp */
      } else if (registerEMCY == 15U) {
        /* '<S110>:1:45' */
        /* '<S110>:1:46' */
        EMCY = 21570;

        /* 0x5442 - AdditionalAbort */
      } else {
        if (registerEMCY == 32U) {
          /* '<S110>:1:47' */
          /* '<S110>:1:48' */
          EMCY = 10;

          /* Current limit is activated */
        }
      }

      if (recordLast == 1) {
        /* '<S110>:1:51' */
        /* '<S110>:1:52' */
        localDW->lastRegister = registerEMCY;
      }
    }

    if (EMCY == 0) {
      /* '<S110>:1:56' */
      /* '<S110>:1:57' */
      for (EMCY = 0; EMCY < 5; EMCY++) {
        localB->EMCYMsg[EMCY] = 0.0;
      }
    } else {
      /* error message type 3 means that the error is from the status */
      /* register's amp status bits */
      /* '<S110>:1:61' */
      localB->EMCYMsg[0] = 3.0;
      localB->EMCYMsg[1] = rtu_drive;
      localB->EMCYMsg[2] = EMCY;
      localB->EMCYMsg[3] = rtu_statusWord;
      localB->EMCYMsg[4] = c;
    }
  }
}

/* Initial conditions for atomic system: '<S85>/EMCY Message pump' */
void gbyk_v4b_EMCYMessagepump_Init(void)
{
  /* InitializeConditions for MATLAB Function: '<S102>/fault monitor' */
  gbyk_v4b_faultmonitor_Init(&gbyk_v4b_DW.sf_faultmonitor);

  /* InitializeConditions for Memory: '<S106>/Memory' */
  gbyk_v4b_DW.Memory_PreviousInput_nh[0] = gbyk_v4b_P.Memory_X0_o2;
  gbyk_v4b_DW.Memory_PreviousInput_nh[1] = gbyk_v4b_P.Memory_X0_o2;

  /* InitializeConditions for Memory: '<S107>/Memory' */
  gbyk_v4b_DW.Memory_PreviousInput_he[0] = gbyk_v4b_P.Memory_X0_m;
  gbyk_v4b_DW.Memory_PreviousInput_he[1] = gbyk_v4b_P.Memory_X0_m;

  /* InitializeConditions for Memory: '<S108>/Memory' */
  gbyk_v4b_DW.Memory_PreviousInput_lw = gbyk_v4b_P.Memory_X0;

  /* InitializeConditions for Chart: '<S102>/Read EMCY' */
  gbyk_v4b_DW.sfEvent_p = gbyk_v4b_CALL_EVENT_mm;
  gbyk_v4b_DW.is_active_c99_ethercat = 0U;
  gbyk_v4b_DW.is_c99_ethercat = gbyk_v4b_IN_NO_ACTIVE_CHILD_jq;
  gbyk_v4b_DW.currReadIdx_j = 0.0;
  gbyk_v4b_DW.valuesToRead_b = 0.0;
  gbyk_v4b_B.triggerCountRead_n = 0;
  gbyk_v4b_B.emcyReadTrigger_e[0] = 0;
  gbyk_v4b_B.emcyReadTrigger_e[1] = 0;
  gbyk_v4b_B.countOverwriteTrigger_n = 0;
  gbyk_v4b_B.emcyValPump_g[0] = 0.0;
  gbyk_v4b_B.emcyValPump_g[1] = 0.0;
  gbyk_v4b_B.emcyValPump_g[2] = 0.0;

  /* InitializeConditions for MATLAB Function: '<S102>/fault monitor1' */
  gbyk_v4b_faultmonitor1_Init(&gbyk_v4b_DW.sf_faultmonitor1);
}

/* Start for atomic system: '<S85>/EMCY Message pump' */
void gbyk_v4b_EMCYMessagepump_Start(void)
{
  /* Start for Constant: '<S102>/driveID' */
  gbyk_v4b_B.driveID_n2 = gbyk_v4b_P.driveID_Value;
}

/* Outputs for atomic system: '<S85>/EMCY Message pump' */
void gbyk_v4b_EMCYMessagepump(void)
{
  /* DataTypeConversion: '<S102>/Data Type Conversion' */
  gbyk_v4b_B.DataTypeConversion_c = gbyk_v4b_B.Statusword_k;

  /* MATLAB Function: '<S102>/fault monitor' */
  gbyk_v4b_faultmonitor(gbyk_v4b_B.Statusword_k, &gbyk_v4b_B.sf_faultmonitor,
                        &gbyk_v4b_DW.sf_faultmonitor);

  /* Constant: '<S102>/driveID' */
  gbyk_v4b_B.driveID_n2 = gbyk_v4b_P.driveID_Value;

  /* Memory: '<S106>/Memory' */
  gbyk_v4b_B.Memory_pr[0] = gbyk_v4b_DW.Memory_PreviousInput_nh[0];
  gbyk_v4b_B.Memory_pr[1] = gbyk_v4b_DW.Memory_PreviousInput_nh[1];

  /* DataTypeConversion: '<S106>/Data Type Conversion2' */
  gbyk_v4b_B.DataTypeConversion2_j[0] = gbyk_v4b_B.Memory_pr[0];
  gbyk_v4b_B.DataTypeConversion2_j[1] = gbyk_v4b_B.Memory_pr[1];

  /* Memory: '<S107>/Memory' */
  gbyk_v4b_B.Memory_ne[0] = gbyk_v4b_DW.Memory_PreviousInput_he[0];
  gbyk_v4b_B.Memory_ne[1] = gbyk_v4b_DW.Memory_PreviousInput_he[1];

  /* DataTypeConversion: '<S107>/Data Type Conversion' */
  gbyk_v4b_B.DataTypeConversion_hm[0] = gbyk_v4b_B.Memory_ne[0];
  gbyk_v4b_B.DataTypeConversion_hm[1] = gbyk_v4b_B.Memory_ne[1];

  /* Memory: '<S108>/Memory' */
  gbyk_v4b_B.Memory_dp = gbyk_v4b_DW.Memory_PreviousInput_lw;

  /* Chart: '<S102>/Read EMCY' */
  /* Gateway: EtherCAT Subsystem/Arm 1/A1M1/EMCY Message pump/Read EMCY */
  gbyk_v4b_DW.sfEvent_p = gbyk_v4b_CALL_EVENT_mm;

  /* During: EtherCAT Subsystem/Arm 1/A1M1/EMCY Message pump/Read EMCY */
  if (gbyk_v4b_DW.is_active_c99_ethercat == 0U) {
    /* Entry: EtherCAT Subsystem/Arm 1/A1M1/EMCY Message pump/Read EMCY */
    gbyk_v4b_DW.is_active_c99_ethercat = 1U;

    /* Entry Internal: EtherCAT Subsystem/Arm 1/A1M1/EMCY Message pump/Read EMCY */
    /* Transition: '<S105>:140' */
    gbyk_v4b_DW.is_c99_ethercat = gbyk_v4b_IN_setup_k;
  } else {
    switch (gbyk_v4b_DW.is_c99_ethercat) {
     case gbyk_v4b_IN_DoneClearing_g:
      /* During 'DoneClearing': '<S105>:197' */
      /* Transition: '<S105>:200' */
      gbyk_v4b_DW.is_c99_ethercat = gbyk_v4b_IN_setup_k;
      break;

     case gbyk_v4b_IN_ReadNextEMCY_e:
      /* During 'ReadNextEMCY': '<S105>:184' */
      if (gbyk_v4b_B.DataTypeConversion_hm[1] == 1.0) {
        /* Transition: '<S105>:187' */
        gbyk_v4b_DW.is_c99_ethercat = gbyk_v4b_IN_disableEMCY_g;

        /* Entry 'disableEMCY': '<S105>:186' */
        gbyk_v4b_B.emcyReadTrigger_e[0] = 0;
      }
      break;

     case gbyk_v4b_IN_ReceivedFloat_m:
      /* During 'ReceivedFloat': '<S105>:188' */
      if (gbyk_v4b_DW.currReadIdx_j <= gbyk_v4b_DW.valuesToRead_b) {
        /* Transition: '<S105>:192' */
        gbyk_v4b_DW.is_c99_ethercat = gbyk_v4b_IN_ReadNextEMCY_e;

        /* Entry 'ReadNextEMCY': '<S105>:184' */
        gbyk_v4b_B.emcyReadTrigger_e[0] = 1;
        gbyk_v4b_B.emcyReadTrigger_e[1] = (int32_T)gbyk_v4b_DW.currReadIdx_j;
      } else {
        /* Transition: '<S105>:191' */
        gbyk_v4b_DW.is_c99_ethercat = gbyk_v4b_IN_StartOverwrite_c;

        /* Entry 'StartOverwrite': '<S105>:193' */
        gbyk_v4b_B.countOverwriteTrigger_n = 1;
        gbyk_v4b_B.emcyValPump_g[0] = 0.0;
        gbyk_v4b_B.emcyValPump_g[1] = 0.0;
        gbyk_v4b_B.emcyValPump_g[2] = 0.0;
      }
      break;

     case gbyk_v4b_IN_StartOverwrite_c:
      /* During 'StartOverwrite': '<S105>:193' */
      if (gbyk_v4b_B.Memory_dp == 1.0) {
        /* Transition: '<S105>:223' */
        gbyk_v4b_DW.is_c99_ethercat = gbyk_v4b_IN_DoneClearing_g;

        /* Entry 'DoneClearing': '<S105>:197' */
        gbyk_v4b_B.countOverwriteTrigger_n = 0;
      }
      break;

     case gbyk_v4b_IN_StartReadingCount_f:
      /* During 'StartReadingCount': '<S105>:141' */
      if (gbyk_v4b_B.DataTypeConversion2_j[1] == 1.0) {
        /* Transition: '<S105>:157' */
        gbyk_v4b_DW.is_c99_ethercat = gbyk_v4b_IN_disableCount_b;

        /* Entry 'disableCount': '<S105>:156' */
        gbyk_v4b_B.triggerCountRead_n = 0;
      }
      break;

     case gbyk_v4b_IN_disableCount_b:
      /* During 'disableCount': '<S105>:156' */
      if (gbyk_v4b_B.DataTypeConversion2_j[1] >= 2.0) {
        /* Transition: '<S105>:143' */
        if (gbyk_v4b_B.DataTypeConversion2_j[0] == 0.0) {
          /* Transition: '<S105>:219' */
          gbyk_v4b_DW.is_c99_ethercat = gbyk_v4b_IN_setup_k;
        } else {
          /* Transition: '<S105>:220' */
          gbyk_v4b_DW.is_c99_ethercat = gbyk_v4b_IN_startEMCYs_h;

          /* Entry 'startEMCYs': '<S105>:183' */
          gbyk_v4b_DW.currReadIdx_j = 1.0;
          gbyk_v4b_DW.valuesToRead_b = gbyk_v4b_B.DataTypeConversion2_j[1];
        }
      }
      break;

     case gbyk_v4b_IN_disableEMCY_g:
      /* During 'disableEMCY': '<S105>:186' */
      if (gbyk_v4b_B.DataTypeConversion_hm[1] >= 2.0) {
        /* Transition: '<S105>:189' */
        gbyk_v4b_DW.is_c99_ethercat = gbyk_v4b_IN_ReceivedFloat_m;

        /* Entry 'ReceivedFloat': '<S105>:188' */
        gbyk_v4b_B.emcyValPump_g[0] = 1.0;

        /* ID for EMCY messge */
        gbyk_v4b_B.emcyValPump_g[1] = gbyk_v4b_B.driveID_n2;
        gbyk_v4b_B.emcyValPump_g[2] = gbyk_v4b_B.DataTypeConversion_hm[0];
        gbyk_v4b_DW.currReadIdx_j++;
      }
      break;

     case gbyk_v4b_IN_setup_k:
      /* During 'setup': '<S105>:139' */
      if (gbyk_v4b_B.sf_faultmonitor.triggerFaultRead == 1.0) {
        /* Transition: '<S105>:145' */
        gbyk_v4b_DW.is_c99_ethercat = gbyk_v4b_IN_StartReadingCount_f;

        /* Entry 'StartReadingCount': '<S105>:141' */
        gbyk_v4b_B.triggerCountRead_n = 1;
      }
      break;

     default:
      /* During 'startEMCYs': '<S105>:183' */
      /* Transition: '<S105>:185' */
      gbyk_v4b_DW.is_c99_ethercat = gbyk_v4b_IN_ReadNextEMCY_e;

      /* Entry 'ReadNextEMCY': '<S105>:184' */
      gbyk_v4b_B.emcyReadTrigger_e[0] = 1;
      gbyk_v4b_B.emcyReadTrigger_e[1] = (int32_T)gbyk_v4b_DW.currReadIdx_j;
      break;
    }
  }

  /* End of Chart: '<S102>/Read EMCY' */

  /* DataTypeConversion: '<S106>/Data Type Conversion' */
  gbyk_v4b_B.DataTypeConversion_je = gbyk_v4b_B.triggerCountRead_n;

  /* S-Function (BKINethercatasyncsdoupload): '<S106>/BKIN EtherCAT Async SDO Upload' */
  {
    int8_T *sigOutputPtr;
    int32_T *sigStatusPtr;
    int32_T *enInputPtr;
    int_T deviceIndex;
    static int counter= 0;
    int_T actLen;
    int_T res;
    int_T state;
    int32_T *indexInputPtr;
    int32_T *subIndexInputPtr;
    deviceIndex = gbyk_v4b_DW.BKINEtherCATAsyncSDOUpload_IWORK_hj[0];
    if (deviceIndex != NO_ETHERCAT) {
      state = xpcEtherCATgetState( deviceIndex );
      if (state >= 2 ) {
        sigOutputPtr = &gbyk_v4b_B.BKINEtherCATAsyncSDOUpload_o1_b;
        sigStatusPtr = &gbyk_v4b_B.BKINEtherCATAsyncSDOUpload_o2_db;
        enInputPtr = &gbyk_v4b_B.DataTypeConversion_je;
        indexInputPtr = &gbyk_v4b_P.Constant_Value_g0;
        subIndexInputPtr = &gbyk_v4b_P.Constant1_Value_h;
        if (gbyk_v4b_DW.BKINEtherCATAsyncSDOUpload_IWORK_hj[7] != 0) {
          res = ecatAsyncSDOUpload(deviceIndex,
            1001,
            (unsigned short)*indexInputPtr,
            (unsigned char)*subIndexInputPtr,
            (void *)sigOutputPtr,
            1*4,
            &actLen,
            500,
            342973257,
            sigStatusPtr,
            *enInputPtr);
        }

        gbyk_v4b_DW.BKINEtherCATAsyncSDOUpload_IWORK_hj[7] = 1;
        ;
      }
    }
  }

  /* DataTypeConversion: '<S106>/Data Type Conversion1' */
  gbyk_v4b_B.DataTypeConversion1_jd = (uint32_T)
    gbyk_v4b_B.BKINEtherCATAsyncSDOUpload_o2_db;

  /* RateTransition: '<S106>/Rate Transition' */
  gbyk_v4b_B.RateTransition_e[0] = gbyk_v4b_B.BKINEtherCATAsyncSDOUpload_o1_b;
  gbyk_v4b_B.RateTransition_e[1] = gbyk_v4b_B.DataTypeConversion1_jd;

  /* S-Function (BKINethercatasyncsdoupload): '<S107>/BKIN EtherCAT Async SDO Upload' */
  {
    int8_T *sigOutputPtr;
    int32_T *sigStatusPtr;
    int32_T *enInputPtr;
    int_T deviceIndex;
    static int counter= 0;
    int_T actLen;
    int_T res;
    int_T state;
    int32_T *indexInputPtr;
    int32_T *subIndexInputPtr;
    deviceIndex = gbyk_v4b_DW.BKINEtherCATAsyncSDOUpload_IWORK_b[0];
    if (deviceIndex != NO_ETHERCAT) {
      state = xpcEtherCATgetState( deviceIndex );
      if (state >= 2 ) {
        sigOutputPtr = &gbyk_v4b_B.BKINEtherCATAsyncSDOUpload_o1_h;
        sigStatusPtr = &gbyk_v4b_B.BKINEtherCATAsyncSDOUpload_o2_di;
        enInputPtr = &gbyk_v4b_B.emcyReadTrigger_e[0];
        indexInputPtr = &gbyk_v4b_P.Constant_Value_n;
        subIndexInputPtr = &gbyk_v4b_B.emcyReadTrigger_e[1];
        if (gbyk_v4b_DW.BKINEtherCATAsyncSDOUpload_IWORK_b[7] != 0) {
          res = ecatAsyncSDOUpload(deviceIndex,
            1001,
            (unsigned short)*indexInputPtr,
            (unsigned char)*subIndexInputPtr,
            (void *)sigOutputPtr,
            1*4,
            &actLen,
            500,
            342973265,
            sigStatusPtr,
            *enInputPtr);
        }

        gbyk_v4b_DW.BKINEtherCATAsyncSDOUpload_IWORK_b[7] = 1;
        ;
      }
    }
  }

  /* RateTransition: '<S107>/Rate Transition' */
  gbyk_v4b_B.RateTransition_cg[0] = gbyk_v4b_B.BKINEtherCATAsyncSDOUpload_o1_h;
  gbyk_v4b_B.RateTransition_cg[1] = gbyk_v4b_B.BKINEtherCATAsyncSDOUpload_o2_di;

  /* DataTypeConversion: '<S108>/Data Type Conversion' incorporates:
   *  Constant: '<S108>/Constant'
   */
  gbyk_v4b_B.DataTypeConversion_mf = (int32_T)gbyk_v4b_P.Constant_Value_p;

  /* S-Function (BKINethercatasyncsdodownload): '<S108>/BKIN EtherCAT Async SDO Download' */
  {
    int8_T *sigInputPtr;
    int32_T *sigStatusPtr;
    int32_T *enInputPtr;
    int_T deviceIndex;
    int_T res;
    int_T state;
    int32_T *indexInputPtr;
    int32_T *subIndexInputPtr;
    deviceIndex = gbyk_v4b_DW.BKINEtherCATAsyncSDODownload_IWORK_g1[0];
    if (deviceIndex != NO_ETHERCAT) {
      state = xpcEtherCATgetState( deviceIndex );
      if (state >= 2 ) {
        sigStatusPtr = &gbyk_v4b_B.BKINEtherCATAsyncSDODownload_n;
        sigInputPtr = &gbyk_v4b_P.Constant_Value_p;
        enInputPtr = &gbyk_v4b_B.countOverwriteTrigger_n;
        indexInputPtr = &gbyk_v4b_P.Constant1_Value_e;
        subIndexInputPtr = &gbyk_v4b_B.DataTypeConversion_mf;
        if (gbyk_v4b_DW.BKINEtherCATAsyncSDODownload_IWORK_g1[7] != 0) {
          res = ecatAsyncSDODownload(deviceIndex,
            1001,
            (unsigned short)*indexInputPtr,
            (unsigned char)*subIndexInputPtr,
            (void *)sigInputPtr,
            1*4,
            500,
            342973277,
            sigStatusPtr,
            *enInputPtr);
        } else {
          *sigStatusPtr = 0;
        }

        gbyk_v4b_DW.BKINEtherCATAsyncSDODownload_IWORK_g1[7] = 1;
        ;
      }
    }
  }

  /* DataTypeConversion: '<S108>/Data Type Conversion1' */
  gbyk_v4b_B.DataTypeConversion1_av = gbyk_v4b_B.BKINEtherCATAsyncSDODownload_n;

  /* MATLAB Function: '<S102>/fault monitor1' */
  gbyk_v4b_faultmonitor1(gbyk_v4b_B.emcyValPump_g,
    gbyk_v4b_B.sf_parsestatusregister.ampStatus,
    gbyk_v4b_B.sf_parsestatusregister.currentLimitEnabled,
    gbyk_v4b_B.statusregister_c4, gbyk_v4b_B.driveID_n2,
    gbyk_v4b_B.DataTypeConversion_c, &gbyk_v4b_B.sf_faultmonitor1,
    &gbyk_v4b_DW.sf_faultmonitor1);
}

/* Update for atomic system: '<S85>/EMCY Message pump' */
void gbyk_v4b_EMCYMessagepump_Update(void)
{
  /* Update for Memory: '<S106>/Memory' */
  gbyk_v4b_DW.Memory_PreviousInput_nh[0] = gbyk_v4b_B.RateTransition_e[0];
  gbyk_v4b_DW.Memory_PreviousInput_nh[1] = gbyk_v4b_B.RateTransition_e[1];

  /* Update for Memory: '<S107>/Memory' */
  gbyk_v4b_DW.Memory_PreviousInput_he[0] = gbyk_v4b_B.RateTransition_cg[0];
  gbyk_v4b_DW.Memory_PreviousInput_he[1] = gbyk_v4b_B.RateTransition_cg[1];

  /* Update for Memory: '<S108>/Memory' */
  gbyk_v4b_DW.Memory_PreviousInput_lw = gbyk_v4b_B.DataTypeConversion1_av;
}

/* Termination for atomic system: '<S85>/EMCY Message pump' */
void gbyk_v4b_EMCYMessagepump_Term(void)
{
  /* Terminate for S-Function (BKINethercatasyncsdoupload): '<S106>/BKIN EtherCAT Async SDO Upload' */
  {
    int_T deviceIndex;
    if (!xpcIsModelInit()) {
      deviceIndex = gbyk_v4b_DW.BKINEtherCATAsyncSDOUpload_IWORK_hj[0];
      if (deviceIndex != NO_ETHERCAT) {
        unregisterAsyncSDOUpload(342973257, deviceIndex);
        printf("SDO Upload. Unregister device %d, slave addr: %d\n", deviceIndex,
               1001);
      }
    }
  }

  /* Terminate for S-Function (BKINethercatasyncsdoupload): '<S107>/BKIN EtherCAT Async SDO Upload' */
  {
    int_T deviceIndex;
    if (!xpcIsModelInit()) {
      deviceIndex = gbyk_v4b_DW.BKINEtherCATAsyncSDOUpload_IWORK_b[0];
      if (deviceIndex != NO_ETHERCAT) {
        unregisterAsyncSDOUpload(342973265, deviceIndex);
        printf("SDO Upload. Unregister device %d, slave addr: %d\n", deviceIndex,
               1001);
      }
    }
  }

  /* Terminate for S-Function (BKINethercatasyncsdodownload): '<S108>/BKIN EtherCAT Async SDO Download' */
  {
    int_T deviceIndex;
    if (!xpcIsModelInit()) {
      deviceIndex = gbyk_v4b_DW.BKINEtherCATAsyncSDODownload_IWORK_g1[0];
      if (deviceIndex != NO_ETHERCAT) {
        unregisterAsyncSDODownload(342973277, deviceIndex);
        printf("SDO Download. Unregister device %d, slave addr: %d\n",
               deviceIndex, 1001);
      }
    }
  }
}

/*
 * Initial conditions for atomic system:
 *    '<S86>/Control GDC Whistle State'
 *    '<S137>/Control GDC Whistle State'
 */
void gbyk_v4b_ControlGDCWhistleState_Init(DW_ControlGDCWhistleState_gbyk_v4b_T
  *localDW)
{
  localDW->permFaulted_not_empty = false;
  localDW->permFaulted = 0.0;
  localDW->countFaultSteps = 0.0;
  localDW->frameCounter = 0.0;
}

/*
 * Output and update for atomic system:
 *    '<S86>/Control GDC Whistle State'
 *    '<S137>/Control GDC Whistle State'
 */
void gbyk_v4b_ControlGDCWhistleState(uint16_T rtu_StatusWord, uint32_T rtu_allOK,
  uint32_T rtu_motorOn, uint32_T rtu_ampStatus, uint32_T rtu_fault, uint32_T
  rtu_eStops, real_T rtu_EMCY, boolean_T rtu_masterEnabled, real_T
  rtu_requestEnable, real_T rtu_max_errors_to_fault,
  B_ControlGDCWhistleState_gbyk_v4b_T *localB,
  DW_ControlGDCWhistleState_gbyk_v4b_T *localDW)
{
  uint16_T StatusWord;
  uint16_T ControlWord;
  int32_T idx;
  int32_T b_ii;
  static const uint16_T ignorable_emcys[4] = { 0U, 10U, 65312U, 33072U };

  boolean_T exitg1;
  int32_T ii_sizes_idx_1;

  /* MATLAB Function 'EtherCAT Subsystem/Arm 1/A1M2/Control GDC Whistle State': '<S114>:1' */
  /*  This function outputs the appropriate ControlWord to control the state of the Elmo Drive. */
  /*  Need to decide why I would want Disabled state vs Ready to switch on state. */
  /*  TODO - deal with faults "better" */
  if (!localDW->permFaulted_not_empty) {
    /* '<S114>:1:8' */
    localDW->permFaulted_not_empty = true;

    /* '<S114>:1:12' */
    localDW->lastEStopState = rtu_eStops;
  }

  /*  Define the value of the StatusWord for different states of the Elmo drive.  */
  /*  Taken from the EtherCAT CoE Usage.xls from Elmo.  */
  /*  bit 9 = 1, because the Elmo drive is always in Remote mode, but I don't look at it. */
  /*  bit 4 = 1, because the voltage should be enabled */
  /*  bits 0-3, 6 define the state */
  /*  unclear on bits 10 and higher */
  /*  hex2dec('50'); */
  /*  hex2dec('31'); */
  /*  hex2dec('33');		% NOTE: We don't really need this state with the Elmo drive in Torque Mode */
  /*  hex2dec('37');		% Although we operate in this state, we don't actual need to query it */
  /*  hex2dec('18');		 */
  /*  Define the value of the ControlWord for different transitions */
  /*  Equal to transitions 7, 9 or 10 */
  /*  Technically this is just the "shutdown" transition. Equal to transitions 2, 6 or 8 */
  /*  Transition 3. As per SwitchedOn, we don't really need this one. */
  /*  Combines transitions 3 and 4 together = 0xF */
  /*  Transitions 15 together = 0x80 */
  /*  Mask the StatusWord input to bits 0-7 */
  /* '<S114>:1:36' */
  StatusWord = (uint16_T)(rtu_StatusWord & 127);

  /*  127 = 0x7F */
  /* '<S114>:1:38' */
  localB->motorStatus = 2U;

  /* motor is not working (red) */
  if ((!(rtu_fault != 0U)) && (rtu_allOK != 0U)) {
    /* '<S114>:1:39' */
    if (rtu_motorOn != 0U) {
      /* '<S114>:1:41' */
      localB->motorStatus = 0U;

      /* motor is working (green) */
    } else {
      /* '<S114>:1:43' */
      localB->motorStatus = 1U;

      /* motor is ready to work (yellow) */
    }
  }

  /* 0xff20 */
  /* 0xff10 */
  /* 0x8130 */
  /* 10 is a current limit */
  /* '<S114>:1:52' */
  idx = 0;
  ii_sizes_idx_1 = 1;
  b_ii = 1;
  exitg1 = false;
  while ((!exitg1) && (b_ii < 5)) {
    if (ignorable_emcys[b_ii - 1] == rtu_EMCY) {
      idx = 1;
      exitg1 = true;
    } else {
      b_ii++;
    }
  }

  if (idx == 0) {
    ii_sizes_idx_1 = 0;
  }

  /* '<S114>:1:53' */
  if ((rtu_EMCY != 0.0) && (!!(ii_sizes_idx_1 == 0))) {
    /* '<S114>:1:55' */
    if (rtu_EMCY == 65296.0) {
      /* '<S114>:1:56' */
      if (rtu_eStops == 0U) {
        /* '<S114>:1:57' */
        /* if the estops are not pressed but we couldn't start then we are truly faulted */
        /* '<S114>:1:58' */
        localDW->permFaulted = 1.0;
      }
    } else {
      /* '<S114>:1:61' */
      localDW->permFaulted = 1.0;
    }
  }

  /* is the amp is reporting it is working we can reset our count of faults */
  if (StatusWord == 55) {
    /* '<S114>:1:66' */
    /* '<S114>:1:67' */
    localDW->countFaultSteps = 0.0;
  }

  /* '<S114>:1:70' */
  ControlWord = 0U;
  if (StatusWord == 24) {
    /* '<S114>:1:72' */
    /* Only when the amp is ready to go can we try to enable it. Otherwise */
    /* we will flood the slrt stdout and slrt will CPU overload. */
    if ((rtu_ampStatus == 0U) && (localDW->permFaulted == 0.0) && (rtu_eStops ==
         0U) && rtu_masterEnabled) {
      /* '<S114>:1:75' */
      /*  change to the Disabled state if faulted */
      /* '<S114>:1:77' */
      ControlWord = 128U;

      /* if eStops == 0 %the emergency stops are not engaged, i.e. we can run with forces */
      /* '<S114>:1:79' */
      localDW->countFaultSteps++;

      /* when the emergency stop is released we get a few rounds where */
      /* there are faults. If we get lots of rounds where there are */
      /* faults then the motor is truly in a bad state and we should */
      /* not continue to ask it to start up. If we continue to ask then */
      /* we can get CPU overloads from all the MBX errors */
      if (localDW->countFaultSteps > rtu_max_errors_to_fault) {
        /* '<S114>:1:85' */
        /* '<S114>:1:86' */
        localDW->permFaulted = 1.0;
      }

      /*  end */
    } else {
      /* '<S114>:1:90' */
    }
  } else if ((StatusWord == 80) && (rtu_requestEnable != 0.0)) {
    /* '<S114>:1:92' */
    /*  change to the Ready to Switch On state if in the Switch On Disabled state AND enable has been requested */
    /* '<S114>:1:94' */
    ControlWord = 6U;
  } else {
    if (rtu_requestEnable != 0.0) {
      /* '<S114>:1:95' */
      /*  change to the Enabled state if in the Ready to Switch on state AND enable had been requested */
      /* '<S114>:1:97' */
      ControlWord = 15U;
    }
  }

  /* If the estop was hit while a task was running that generates a fault. When */
  /* the task is reset then later you disable the estop we need to try to clear */
  /* the error. */
  if ((ControlWord == 0) && (rtu_fault != 0U) && (!(rtu_eStops != 0U)) &&
      (localDW->lastEStopState != 0U)) {
    /* '<S114>:1:103' */
    /* '<S114>:1:104' */
    localDW->frameCounter = 0.0;
  }

  /* this code is trying to clear any faults found at start-up */
  /* 4khz * 3s - it takes ~1.8s to reach the op state and we need to do this after that */
  if ((localDW->frameCounter < 12000.0) && (rtu_allOK != 0U) && (rtu_ampStatus ==
       0U) && (!(localDW->permFaulted != 0.0)) && (!(rtu_eStops != 0U)) &&
      rtu_masterEnabled && (rtu_fault != 0U)) {
    /* '<S114>:1:109' */
    if (StatusWord == 80) {
      /* '<S114>:1:110' */
      /* '<S114>:1:111' */
      ControlWord = 6U;
    } else {
      if (StatusWord == 49) {
        /* '<S114>:1:112' */
        /* the only way to clear an error is to enable the drive. This should */
        /* enable the drive very briefly. The forces should still be off */
        /* though since they are controlled by the run state of the drive. */
        /* '<S114>:1:116' */
        ControlWord = 15U;
      }
    }
  }

  /* '<S114>:1:120' */
  localDW->lastEStopState = rtu_eStops;

  /* '<S114>:1:121' */
  localDW->frameCounter++;

  /* '<S114>:1:122' */
  localB->isPermFaulted = localDW->permFaulted;
  localB->ControlWord = ControlWord;
}

/* Initial conditions for atomic system: '<S86>/EMCY Message pump' */
void gbyk_v4b_EMCYMessagepump_p_Init(void)
{
  /* InitializeConditions for MATLAB Function: '<S115>/fault monitor' */
  gbyk_v4b_faultmonitor_Init(&gbyk_v4b_DW.sf_faultmonitor_k);

  /* InitializeConditions for Memory: '<S119>/Memory' */
  gbyk_v4b_DW.Memory_PreviousInput_n[0] = gbyk_v4b_P.Memory_X0_hp;
  gbyk_v4b_DW.Memory_PreviousInput_n[1] = gbyk_v4b_P.Memory_X0_hp;

  /* InitializeConditions for Memory: '<S120>/Memory' */
  gbyk_v4b_DW.Memory_PreviousInput_id[0] = gbyk_v4b_P.Memory_X0_fd;
  gbyk_v4b_DW.Memory_PreviousInput_id[1] = gbyk_v4b_P.Memory_X0_fd;

  /* InitializeConditions for Memory: '<S121>/Memory' */
  gbyk_v4b_DW.Memory_PreviousInput_h3 = gbyk_v4b_P.Memory_X0_a;

  /* InitializeConditions for Chart: '<S115>/Read EMCY' */
  gbyk_v4b_DW.sfEvent_e = gbyk_v4b_CALL_EVENT_il;
  gbyk_v4b_DW.is_active_c101_ethercat = 0U;
  gbyk_v4b_DW.is_c101_ethercat = gbyk_v4b_IN_NO_ACTIVE_CHILD_p;
  gbyk_v4b_DW.currReadIdx = 0.0;
  gbyk_v4b_DW.valuesToRead = 0.0;
  gbyk_v4b_B.triggerCountRead = 0;
  gbyk_v4b_B.emcyReadTrigger[0] = 0;
  gbyk_v4b_B.emcyReadTrigger[1] = 0;
  gbyk_v4b_B.countOverwriteTrigger = 0;
  gbyk_v4b_B.emcyValPump[0] = 0.0;
  gbyk_v4b_B.emcyValPump[1] = 0.0;
  gbyk_v4b_B.emcyValPump[2] = 0.0;

  /* InitializeConditions for MATLAB Function: '<S115>/fault monitor1' */
  gbyk_v4b_faultmonitor1_Init(&gbyk_v4b_DW.sf_faultmonitor1_l);
}

/* Start for atomic system: '<S86>/EMCY Message pump' */
void gbyk_v4b_EMCYMessagepump_h_Start(void)
{
  /* Start for Constant: '<S115>/driveID' */
  gbyk_v4b_B.driveID_a = gbyk_v4b_P.driveID_Value_c;
}

/* Outputs for atomic system: '<S86>/EMCY Message pump' */
void gbyk_v4b_EMCYMessagepump_o(void)
{
  /* DataTypeConversion: '<S115>/Data Type Conversion' */
  gbyk_v4b_B.DataTypeConversion_kb = gbyk_v4b_B.Statusword_b;

  /* MATLAB Function: '<S115>/fault monitor' */
  gbyk_v4b_faultmonitor(gbyk_v4b_B.Statusword_b, &gbyk_v4b_B.sf_faultmonitor_k,
                        &gbyk_v4b_DW.sf_faultmonitor_k);

  /* Constant: '<S115>/driveID' */
  gbyk_v4b_B.driveID_a = gbyk_v4b_P.driveID_Value_c;

  /* Memory: '<S119>/Memory' */
  gbyk_v4b_B.Memory_d4[0] = gbyk_v4b_DW.Memory_PreviousInput_n[0];
  gbyk_v4b_B.Memory_d4[1] = gbyk_v4b_DW.Memory_PreviousInput_n[1];

  /* DataTypeConversion: '<S119>/Data Type Conversion2' */
  gbyk_v4b_B.DataTypeConversion2_d[0] = gbyk_v4b_B.Memory_d4[0];
  gbyk_v4b_B.DataTypeConversion2_d[1] = gbyk_v4b_B.Memory_d4[1];

  /* Memory: '<S120>/Memory' */
  gbyk_v4b_B.Memory_kw[0] = gbyk_v4b_DW.Memory_PreviousInput_id[0];
  gbyk_v4b_B.Memory_kw[1] = gbyk_v4b_DW.Memory_PreviousInput_id[1];

  /* DataTypeConversion: '<S120>/Data Type Conversion' */
  gbyk_v4b_B.DataTypeConversion_m[0] = gbyk_v4b_B.Memory_kw[0];
  gbyk_v4b_B.DataTypeConversion_m[1] = gbyk_v4b_B.Memory_kw[1];

  /* Memory: '<S121>/Memory' */
  gbyk_v4b_B.Memory_d = gbyk_v4b_DW.Memory_PreviousInput_h3;

  /* Chart: '<S115>/Read EMCY' */
  /* Gateway: EtherCAT Subsystem/Arm 1/A1M2/EMCY Message pump/Read EMCY */
  gbyk_v4b_DW.sfEvent_e = gbyk_v4b_CALL_EVENT_il;

  /* During: EtherCAT Subsystem/Arm 1/A1M2/EMCY Message pump/Read EMCY */
  if (gbyk_v4b_DW.is_active_c101_ethercat == 0U) {
    /* Entry: EtherCAT Subsystem/Arm 1/A1M2/EMCY Message pump/Read EMCY */
    gbyk_v4b_DW.is_active_c101_ethercat = 1U;

    /* Entry Internal: EtherCAT Subsystem/Arm 1/A1M2/EMCY Message pump/Read EMCY */
    /* Transition: '<S118>:140' */
    gbyk_v4b_DW.is_c101_ethercat = gbyk_v4b_IN_setup_m;
  } else {
    switch (gbyk_v4b_DW.is_c101_ethercat) {
     case gbyk_v4b_IN_DoneClearing_m:
      /* During 'DoneClearing': '<S118>:197' */
      /* Transition: '<S118>:200' */
      gbyk_v4b_DW.is_c101_ethercat = gbyk_v4b_IN_setup_m;
      break;

     case gbyk_v4b_IN_ReadNextEMCY_l:
      /* During 'ReadNextEMCY': '<S118>:184' */
      if (gbyk_v4b_B.DataTypeConversion_m[1] == 1.0) {
        /* Transition: '<S118>:187' */
        gbyk_v4b_DW.is_c101_ethercat = gbyk_v4b_IN_disableEMCY_m;

        /* Entry 'disableEMCY': '<S118>:186' */
        gbyk_v4b_B.emcyReadTrigger[0] = 0;
      }
      break;

     case gbyk_v4b_IN_ReceivedFloat_a:
      /* During 'ReceivedFloat': '<S118>:188' */
      if (gbyk_v4b_DW.currReadIdx <= gbyk_v4b_DW.valuesToRead) {
        /* Transition: '<S118>:192' */
        gbyk_v4b_DW.is_c101_ethercat = gbyk_v4b_IN_ReadNextEMCY_l;

        /* Entry 'ReadNextEMCY': '<S118>:184' */
        gbyk_v4b_B.emcyReadTrigger[0] = 1;
        gbyk_v4b_B.emcyReadTrigger[1] = (int32_T)gbyk_v4b_DW.currReadIdx;
      } else {
        /* Transition: '<S118>:191' */
        gbyk_v4b_DW.is_c101_ethercat = gbyk_v4b_IN_StartOverwrite_b;

        /* Entry 'StartOverwrite': '<S118>:193' */
        gbyk_v4b_B.countOverwriteTrigger = 1;
        gbyk_v4b_B.emcyValPump[0] = 0.0;
        gbyk_v4b_B.emcyValPump[1] = 0.0;
        gbyk_v4b_B.emcyValPump[2] = 0.0;
      }
      break;

     case gbyk_v4b_IN_StartOverwrite_b:
      /* During 'StartOverwrite': '<S118>:193' */
      if (gbyk_v4b_B.Memory_d == 1.0) {
        /* Transition: '<S118>:223' */
        gbyk_v4b_DW.is_c101_ethercat = gbyk_v4b_IN_DoneClearing_m;

        /* Entry 'DoneClearing': '<S118>:197' */
        gbyk_v4b_B.countOverwriteTrigger = 0;
      }
      break;

     case gbyk_v4b_IN_StartReadingCount_k:
      /* During 'StartReadingCount': '<S118>:141' */
      if (gbyk_v4b_B.DataTypeConversion2_d[1] == 1.0) {
        /* Transition: '<S118>:157' */
        gbyk_v4b_DW.is_c101_ethercat = gbyk_v4b_IN_disableCount_c;

        /* Entry 'disableCount': '<S118>:156' */
        gbyk_v4b_B.triggerCountRead = 0;
      }
      break;

     case gbyk_v4b_IN_disableCount_c:
      /* During 'disableCount': '<S118>:156' */
      if (gbyk_v4b_B.DataTypeConversion2_d[1] >= 2.0) {
        /* Transition: '<S118>:143' */
        if (gbyk_v4b_B.DataTypeConversion2_d[0] == 0.0) {
          /* Transition: '<S118>:219' */
          gbyk_v4b_DW.is_c101_ethercat = gbyk_v4b_IN_setup_m;
        } else {
          /* Transition: '<S118>:220' */
          gbyk_v4b_DW.is_c101_ethercat = gbyk_v4b_IN_startEMCYs_hm;

          /* Entry 'startEMCYs': '<S118>:183' */
          gbyk_v4b_DW.currReadIdx = 1.0;
          gbyk_v4b_DW.valuesToRead = gbyk_v4b_B.DataTypeConversion2_d[1];
        }
      }
      break;

     case gbyk_v4b_IN_disableEMCY_m:
      /* During 'disableEMCY': '<S118>:186' */
      if (gbyk_v4b_B.DataTypeConversion_m[1] >= 2.0) {
        /* Transition: '<S118>:189' */
        gbyk_v4b_DW.is_c101_ethercat = gbyk_v4b_IN_ReceivedFloat_a;

        /* Entry 'ReceivedFloat': '<S118>:188' */
        gbyk_v4b_B.emcyValPump[0] = 1.0;

        /* ID for EMCY messge */
        gbyk_v4b_B.emcyValPump[1] = gbyk_v4b_B.driveID_a;
        gbyk_v4b_B.emcyValPump[2] = gbyk_v4b_B.DataTypeConversion_m[0];
        gbyk_v4b_DW.currReadIdx++;
      }
      break;

     case gbyk_v4b_IN_setup_m:
      /* During 'setup': '<S118>:139' */
      if (gbyk_v4b_B.sf_faultmonitor_k.triggerFaultRead == 1.0) {
        /* Transition: '<S118>:145' */
        gbyk_v4b_DW.is_c101_ethercat = gbyk_v4b_IN_StartReadingCount_k;

        /* Entry 'StartReadingCount': '<S118>:141' */
        gbyk_v4b_B.triggerCountRead = 1;
      }
      break;

     default:
      /* During 'startEMCYs': '<S118>:183' */
      /* Transition: '<S118>:185' */
      gbyk_v4b_DW.is_c101_ethercat = gbyk_v4b_IN_ReadNextEMCY_l;

      /* Entry 'ReadNextEMCY': '<S118>:184' */
      gbyk_v4b_B.emcyReadTrigger[0] = 1;
      gbyk_v4b_B.emcyReadTrigger[1] = (int32_T)gbyk_v4b_DW.currReadIdx;
      break;
    }
  }

  /* End of Chart: '<S115>/Read EMCY' */

  /* DataTypeConversion: '<S119>/Data Type Conversion' */
  gbyk_v4b_B.DataTypeConversion_n = gbyk_v4b_B.triggerCountRead;

  /* S-Function (BKINethercatasyncsdoupload): '<S119>/BKIN EtherCAT Async SDO Upload' */
  {
    int8_T *sigOutputPtr;
    int32_T *sigStatusPtr;
    int32_T *enInputPtr;
    int_T deviceIndex;
    static int counter= 0;
    int_T actLen;
    int_T res;
    int_T state;
    int32_T *indexInputPtr;
    int32_T *subIndexInputPtr;
    deviceIndex = gbyk_v4b_DW.BKINEtherCATAsyncSDOUpload_IWORK_j[0];
    if (deviceIndex != NO_ETHERCAT) {
      state = xpcEtherCATgetState( deviceIndex );
      if (state >= 2 ) {
        sigOutputPtr = &gbyk_v4b_B.BKINEtherCATAsyncSDOUpload_o1_ln;
        sigStatusPtr = &gbyk_v4b_B.BKINEtherCATAsyncSDOUpload_o2_d;
        enInputPtr = &gbyk_v4b_B.DataTypeConversion_n;
        indexInputPtr = &gbyk_v4b_P.Constant_Value_gd;
        subIndexInputPtr = &gbyk_v4b_P.Constant1_Value_h4;
        if (gbyk_v4b_DW.BKINEtherCATAsyncSDOUpload_IWORK_j[7] != 0) {
          res = ecatAsyncSDOUpload(deviceIndex,
            1002,
            (unsigned short)*indexInputPtr,
            (unsigned char)*subIndexInputPtr,
            (void *)sigOutputPtr,
            1*4,
            &actLen,
            500,
            342973341,
            sigStatusPtr,
            *enInputPtr);
        }

        gbyk_v4b_DW.BKINEtherCATAsyncSDOUpload_IWORK_j[7] = 1;
        ;
      }
    }
  }

  /* DataTypeConversion: '<S119>/Data Type Conversion1' */
  gbyk_v4b_B.DataTypeConversion1_ke = (uint32_T)
    gbyk_v4b_B.BKINEtherCATAsyncSDOUpload_o2_d;

  /* RateTransition: '<S119>/Rate Transition' */
  gbyk_v4b_B.RateTransition_m[0] = gbyk_v4b_B.BKINEtherCATAsyncSDOUpload_o1_ln;
  gbyk_v4b_B.RateTransition_m[1] = gbyk_v4b_B.DataTypeConversion1_ke;

  /* S-Function (BKINethercatasyncsdoupload): '<S120>/BKIN EtherCAT Async SDO Upload' */
  {
    int8_T *sigOutputPtr;
    int32_T *sigStatusPtr;
    int32_T *enInputPtr;
    int_T deviceIndex;
    static int counter= 0;
    int_T actLen;
    int_T res;
    int_T state;
    int32_T *indexInputPtr;
    int32_T *subIndexInputPtr;
    deviceIndex = gbyk_v4b_DW.BKINEtherCATAsyncSDOUpload_IWORK_a[0];
    if (deviceIndex != NO_ETHERCAT) {
      state = xpcEtherCATgetState( deviceIndex );
      if (state >= 2 ) {
        sigOutputPtr = &gbyk_v4b_B.BKINEtherCATAsyncSDOUpload_o1_n;
        sigStatusPtr = &gbyk_v4b_B.BKINEtherCATAsyncSDOUpload_o2_k;
        enInputPtr = &gbyk_v4b_B.emcyReadTrigger[0];
        indexInputPtr = &gbyk_v4b_P.Constant_Value_i;
        subIndexInputPtr = &gbyk_v4b_B.emcyReadTrigger[1];
        if (gbyk_v4b_DW.BKINEtherCATAsyncSDOUpload_IWORK_a[7] != 0) {
          res = ecatAsyncSDOUpload(deviceIndex,
            1002,
            (unsigned short)*indexInputPtr,
            (unsigned char)*subIndexInputPtr,
            (void *)sigOutputPtr,
            1*4,
            &actLen,
            500,
            342973352,
            sigStatusPtr,
            *enInputPtr);
        }

        gbyk_v4b_DW.BKINEtherCATAsyncSDOUpload_IWORK_a[7] = 1;
        ;
      }
    }
  }

  /* RateTransition: '<S120>/Rate Transition' */
  gbyk_v4b_B.RateTransition_o[0] = gbyk_v4b_B.BKINEtherCATAsyncSDOUpload_o1_n;
  gbyk_v4b_B.RateTransition_o[1] = gbyk_v4b_B.BKINEtherCATAsyncSDOUpload_o2_k;

  /* DataTypeConversion: '<S121>/Data Type Conversion' incorporates:
   *  Constant: '<S121>/Constant'
   */
  gbyk_v4b_B.DataTypeConversion_gy = (int32_T)gbyk_v4b_P.Constant_Value_nx;

  /* S-Function (BKINethercatasyncsdodownload): '<S121>/BKIN EtherCAT Async SDO Download' */
  {
    int8_T *sigInputPtr;
    int32_T *sigStatusPtr;
    int32_T *enInputPtr;
    int_T deviceIndex;
    int_T res;
    int_T state;
    int32_T *indexInputPtr;
    int32_T *subIndexInputPtr;
    deviceIndex = gbyk_v4b_DW.BKINEtherCATAsyncSDODownload_IWORK_g[0];
    if (deviceIndex != NO_ETHERCAT) {
      state = xpcEtherCATgetState( deviceIndex );
      if (state >= 2 ) {
        sigStatusPtr = &gbyk_v4b_B.BKINEtherCATAsyncSDODownload_a;
        sigInputPtr = &gbyk_v4b_P.Constant_Value_nx;
        enInputPtr = &gbyk_v4b_B.countOverwriteTrigger;
        indexInputPtr = &gbyk_v4b_P.Constant1_Value_m;
        subIndexInputPtr = &gbyk_v4b_B.DataTypeConversion_gy;
        if (gbyk_v4b_DW.BKINEtherCATAsyncSDODownload_IWORK_g[7] != 0) {
          res = ecatAsyncSDODownload(deviceIndex,
            1002,
            (unsigned short)*indexInputPtr,
            (unsigned char)*subIndexInputPtr,
            (void *)sigInputPtr,
            1*4,
            500,
            342973361,
            sigStatusPtr,
            *enInputPtr);
        } else {
          *sigStatusPtr = 0;
        }

        gbyk_v4b_DW.BKINEtherCATAsyncSDODownload_IWORK_g[7] = 1;
        ;
      }
    }
  }

  /* DataTypeConversion: '<S121>/Data Type Conversion1' */
  gbyk_v4b_B.DataTypeConversion1_i = gbyk_v4b_B.BKINEtherCATAsyncSDODownload_a;

  /* MATLAB Function: '<S115>/fault monitor1' */
  gbyk_v4b_faultmonitor1(gbyk_v4b_B.emcyValPump,
    gbyk_v4b_B.sf_parsestatusregister1.ampStatus,
    gbyk_v4b_B.sf_parsestatusregister1.currentLimitEnabled,
    gbyk_v4b_B.statusregister_c, gbyk_v4b_B.driveID_a,
    gbyk_v4b_B.DataTypeConversion_kb, &gbyk_v4b_B.sf_faultmonitor1_l,
    &gbyk_v4b_DW.sf_faultmonitor1_l);
}

/* Update for atomic system: '<S86>/EMCY Message pump' */
void gbyk_v4b_EMCYMessagepump_e_Update(void)
{
  /* Update for Memory: '<S119>/Memory' */
  gbyk_v4b_DW.Memory_PreviousInput_n[0] = gbyk_v4b_B.RateTransition_m[0];
  gbyk_v4b_DW.Memory_PreviousInput_n[1] = gbyk_v4b_B.RateTransition_m[1];

  /* Update for Memory: '<S120>/Memory' */
  gbyk_v4b_DW.Memory_PreviousInput_id[0] = gbyk_v4b_B.RateTransition_o[0];
  gbyk_v4b_DW.Memory_PreviousInput_id[1] = gbyk_v4b_B.RateTransition_o[1];

  /* Update for Memory: '<S121>/Memory' */
  gbyk_v4b_DW.Memory_PreviousInput_h3 = gbyk_v4b_B.DataTypeConversion1_i;
}

/* Termination for atomic system: '<S86>/EMCY Message pump' */
void gbyk_v4b_EMCYMessagepump_j_Term(void)
{
  /* Terminate for S-Function (BKINethercatasyncsdoupload): '<S119>/BKIN EtherCAT Async SDO Upload' */
  {
    int_T deviceIndex;
    if (!xpcIsModelInit()) {
      deviceIndex = gbyk_v4b_DW.BKINEtherCATAsyncSDOUpload_IWORK_j[0];
      if (deviceIndex != NO_ETHERCAT) {
        unregisterAsyncSDOUpload(342973341, deviceIndex);
        printf("SDO Upload. Unregister device %d, slave addr: %d\n", deviceIndex,
               1002);
      }
    }
  }

  /* Terminate for S-Function (BKINethercatasyncsdoupload): '<S120>/BKIN EtherCAT Async SDO Upload' */
  {
    int_T deviceIndex;
    if (!xpcIsModelInit()) {
      deviceIndex = gbyk_v4b_DW.BKINEtherCATAsyncSDOUpload_IWORK_a[0];
      if (deviceIndex != NO_ETHERCAT) {
        unregisterAsyncSDOUpload(342973352, deviceIndex);
        printf("SDO Upload. Unregister device %d, slave addr: %d\n", deviceIndex,
               1002);
      }
    }
  }

  /* Terminate for S-Function (BKINethercatasyncsdodownload): '<S121>/BKIN EtherCAT Async SDO Download' */
  {
    int_T deviceIndex;
    if (!xpcIsModelInit()) {
      deviceIndex = gbyk_v4b_DW.BKINEtherCATAsyncSDODownload_IWORK_g[0];
      if (deviceIndex != NO_ETHERCAT) {
        unregisterAsyncSDODownload(342973361, deviceIndex);
        printf("SDO Download. Unregister device %d, slave addr: %d\n",
               deviceIndex, 1002);
      }
    }
  }
}

/*
 * Output and update for atomic system:
 *    '<S75>/Find Robot type'
 *    '<S76>/Find Robot type'
 */
void gbyk_v4b_FindRobottype(const int32_T rtu_intVals[20], const real_T
  rtu_epPNs[6], const real_T rtu_nhpPNs[6], B_FindRobottype_gbyk_v4b_T *localB)
{
  boolean_T x[6];
  int32_T b_ii;
  boolean_T exitg2;
  int32_T i;
  int32_T ii_sizes;

  /* MATLAB Function 'EtherCAT Subsystem/Arm 1/Find Robot type': '<S87>:1' */
  /* '<S87>:1:7' */
  localB->robotType = 0.0;

  /* 0=exo, 1=ep, 2=NHP     */
  /* '<S87>:1:8' */
  for (i = 0; i < 6; i++) {
    x[i] = (rtu_epPNs[i] == rtu_intVals[1]);
  }

  i = 0;
  ii_sizes = 1;
  b_ii = 1;
  exitg2 = false;
  while ((!exitg2) && (b_ii < 7)) {
    if (x[b_ii - 1]) {
      i = 1;
      exitg2 = true;
    } else {
      b_ii++;
    }
  }

  if (i == 0) {
    ii_sizes = 0;
  }

  if (!(ii_sizes == 0)) {
    /* '<S87>:1:9' */
    /* '<S87>:1:10' */
    localB->robotType = 1.0;
  } else {
    for (i = 0; i < 6; i++) {
      x[i] = (rtu_nhpPNs[i] == rtu_intVals[1]);
    }

    i = 0;
    ii_sizes = 1;
    b_ii = 1;
    exitg2 = false;
    while ((!exitg2) && (b_ii < 7)) {
      if (x[b_ii - 1]) {
        i = 1;
        exitg2 = true;
      } else {
        b_ii++;
      }
    }

    if (i == 0) {
      ii_sizes = 0;
    }

    if (!(ii_sizes == 0)) {
      /* '<S87>:1:11' */
      /* '<S87>:1:12' */
      localB->robotType = 2.0;
    }
  }
}

/*
 * Initial conditions for atomic system:
 *    '<S88>/AbsEncoder machine'
 *    '<S89>/AbsEncoder machine'
 *    '<S140>/AbsEncoder machine'
 *    '<S141>/AbsEncoder machine'
 */
void gbyk_v4b_AbsEncodermachine_Init(B_AbsEncodermachine_gbyk_v4b_T *localB,
  DW_AbsEncodermachine_gbyk_v4b_T *localDW)
{
  localDW->sfEvent = gbyk_v4b_CALL_EVENT_h;
  localDW->is_active_c43_ethercat = 0U;
  localDW->is_c43_ethercat = gbyk_v4b_IN_NO_ACTIVE_CHILD;
  localDW->setupIdx = 0;
  localDW->donePolling = 0;
  localDW->encoderIdx = 0.0;
  localB->setupData[0] = 0;
  localB->setupData[1] = 0;
  localB->setupData[2] = 0;
  localB->setupData[3] = 0;
  localB->SDORequest[0] = 0;
  localB->SDORequest[1] = 0;
  localB->SDORequest[2] = 0;
  localB->encoderOutputs[0] = 0;
  localB->encoderOutputs[1] = 0;
  localB->encoderOutputs[2] = 0;
  localB->encoderOutputs[3] = 0;
  localB->encoderOutputs[4] = 0;
  localB->encoderOutputs[5] = 0;
  localB->complete = 0;
}

/*
 * Output and update for atomic system:
 *    '<S88>/AbsEncoder machine'
 *    '<S89>/AbsEncoder machine'
 *    '<S140>/AbsEncoder machine'
 *    '<S141>/AbsEncoder machine'
 */
void gbyk_v4b_AbsEncodermachine(const real_T rtu_setupValues[24], real_T
  rtu_setupValuesCount, const real_T rtu_pollValues[3], const real_T
  rtu_encoderValues[12], real_T rtu_encoderValuesCount, int32_T rtu_intStatus,
  const int32_T rtu_pollResponse[2], B_AbsEncodermachine_gbyk_v4b_T *localB,
  DW_AbsEncodermachine_gbyk_v4b_T *localDW)
{
  /* Gateway: EtherCAT Subsystem/Arm 1/M1 AbsEnc Calibration/AbsEncoder machine */
  localDW->sfEvent = gbyk_v4b_CALL_EVENT_h;

  /* During: EtherCAT Subsystem/Arm 1/M1 AbsEnc Calibration/AbsEncoder machine */
  if (localDW->is_active_c43_ethercat == 0U) {
    /* Entry: EtherCAT Subsystem/Arm 1/M1 AbsEnc Calibration/AbsEncoder machine */
    localDW->is_active_c43_ethercat = 1U;

    /* Entry Internal: EtherCAT Subsystem/Arm 1/M1 AbsEnc Calibration/AbsEncoder machine */
    /* Transition: '<S125>:140' */
    localDW->is_c43_ethercat = gbyk_v4b_IN_setup;

    /* Entry 'setup': '<S125>:139' */
    localDW->setupIdx = 0;
    localDW->donePolling = 0;
  } else {
    switch (localDW->is_c43_ethercat) {
     case gbyk_v4b_IN_Complete:
      /* During 'Complete': '<S125>:200' */
      break;

     case gbyk_v4b_IN_Done:
      /* During 'Done': '<S125>:146' */
      /* Transition: '<S125>:173' */
      localDW->is_c43_ethercat = gbyk_v4b_IN_startPolling;

      /* Entry 'startPolling': '<S125>:172' */
      localB->SDORequest[0] = 1;
      localB->SDORequest[1] = (int32_T)rtu_pollValues[0];
      localB->SDORequest[2] = (int32_T)rtu_pollValues[1];
      break;

     case gbyk_v4b_IN_PollingComplete:
      /* During 'PollingComplete': '<S125>:181' */
      /* Transition: '<S125>:192' */
      localDW->is_c43_ethercat = gbyk_v4b_IN_encoderReadSetup;

      /* Entry 'encoderReadSetup': '<S125>:191' */
      localDW->encoderIdx = 0.0;
      break;

     case gbyk_v4b_IN_ReadNext:
      /* During 'ReadNext': '<S125>:141' */
      if (rtu_intStatus == 1) {
        /* Transition: '<S125>:157' */
        localDW->is_c43_ethercat = gbyk_v4b_IN_disable;

        /* Entry 'disable': '<S125>:156' */
        localB->setupData[1] = 0;
      }
      break;

     case gbyk_v4b_IN_ReadNextEncoder:
      /* During 'ReadNextEncoder': '<S125>:193' */
      if (rtu_pollResponse[1] == 1) {
        /* Transition: '<S125>:196' */
        localDW->is_c43_ethercat = gbyk_v4b_IN_disableRead;

        /* Entry 'disableRead': '<S125>:195' */
        localB->SDORequest[0] = 0;
      }
      break;

     case gbyk_v4b_IN_Received:
      /* During 'Received': '<S125>:142' */
      if (localDW->setupIdx + 1 > rtu_setupValuesCount) {
        /* Transition: '<S125>:147' */
        localDW->is_c43_ethercat = gbyk_v4b_IN_Done;

        /* Entry 'Done': '<S125>:146' */
        localDW->setupIdx = -1;
      } else {
        if (rtu_intStatus == 0) {
          /* Transition: '<S125>:144' */
          localDW->is_c43_ethercat = gbyk_v4b_IN_ReadNext;

          /* Entry 'ReadNext': '<S125>:141' */
          localDW->setupIdx++;
          localB->setupData[0] = (int32_T)rtu_setupValues[localDW->setupIdx + 15];
          localB->setupData[1] = 1;
          localB->setupData[2] = (int32_T)rtu_setupValues[localDW->setupIdx - 1];
          localB->setupData[3] = (int32_T)rtu_setupValues[localDW->setupIdx + 7];
        }
      }
      break;

     case gbyk_v4b_IN_disable:
      /* During 'disable': '<S125>:156' */
      if (rtu_intStatus >= 2) {
        /* Transition: '<S125>:143' */
        localDW->is_c43_ethercat = gbyk_v4b_IN_Received;
      }
      break;

     case gbyk_v4b_IN_disable1:
      /* During 'disable1': '<S125>:174' */
      if (rtu_pollResponse[1] >= 2) {
        /* Transition: '<S125>:179' */
        localDW->is_c43_ethercat = gbyk_v4b_IN_pollReceived;
      }
      break;

     case gbyk_v4b_IN_disableRead:
      /* During 'disableRead': '<S125>:195' */
      if (rtu_pollResponse[1] >= 2) {
        /* Transition: '<S125>:198' */
        localDW->is_c43_ethercat = gbyk_v4b_IN_receivedEncoder;

        /* Entry 'receivedEncoder': '<S125>:197' */
        localB->encoderOutputs[(int32_T)(localDW->encoderIdx - 1.0)] =
          rtu_pollResponse[0];
      }
      break;

     case gbyk_v4b_IN_encoderReadSetup:
      /* During 'encoderReadSetup': '<S125>:191' */
      /* Transition: '<S125>:194' */
      localDW->is_c43_ethercat = gbyk_v4b_IN_ReadNextEncoder;

      /* Entry 'ReadNextEncoder': '<S125>:193' */
      localDW->encoderIdx++;
      localB->SDORequest[0] = 1;
      localB->SDORequest[1] = (int32_T)rtu_encoderValues[(int32_T)
        (localDW->encoderIdx - 1.0)];
      localB->SDORequest[2] = (int32_T)rtu_encoderValues[(int32_T)
        (localDW->encoderIdx - 1.0) + 6];
      break;

     case gbyk_v4b_IN_pollReceived:
      /* During 'pollReceived': '<S125>:178' */
      if (rtu_pollResponse[0] != rtu_pollValues[2]) {
        /* Transition: '<S125>:180' */
        localDW->is_c43_ethercat = gbyk_v4b_IN_startPolling;

        /* Entry 'startPolling': '<S125>:172' */
        localB->SDORequest[0] = 1;
        localB->SDORequest[1] = (int32_T)rtu_pollValues[0];
        localB->SDORequest[2] = (int32_T)rtu_pollValues[1];
      } else {
        /* Transition: '<S125>:189' */
        localDW->is_c43_ethercat = gbyk_v4b_IN_PollingComplete;

        /* Entry 'PollingComplete': '<S125>:181' */
        localDW->donePolling = 1;
      }
      break;

     case gbyk_v4b_IN_receivedEncoder:
      /* During 'receivedEncoder': '<S125>:197' */
      if (localDW->encoderIdx + 1.0 > rtu_encoderValuesCount) {
        /* Transition: '<S125>:201' */
        localDW->is_c43_ethercat = gbyk_v4b_IN_Complete;

        /* Entry 'Complete': '<S125>:200' */
        localB->complete = 1;
      } else {
        /* Transition: '<S125>:199' */
        localDW->is_c43_ethercat = gbyk_v4b_IN_ReadNextEncoder;

        /* Entry 'ReadNextEncoder': '<S125>:193' */
        localDW->encoderIdx++;
        localB->SDORequest[0] = 1;
        localB->SDORequest[1] = (int32_T)rtu_encoderValues[(int32_T)
          (localDW->encoderIdx - 1.0)];
        localB->SDORequest[2] = (int32_T)rtu_encoderValues[(int32_T)
          (localDW->encoderIdx - 1.0) + 6];
      }
      break;

     case gbyk_v4b_IN_setup:
      /* During 'setup': '<S125>:139' */
      /* Transition: '<S125>:145' */
      localDW->is_c43_ethercat = gbyk_v4b_IN_ReadNext;

      /* Entry 'ReadNext': '<S125>:141' */
      localDW->setupIdx++;
      localB->setupData[0] = (int32_T)rtu_setupValues[localDW->setupIdx + 15];
      localB->setupData[1] = 1;
      localB->setupData[2] = (int32_T)rtu_setupValues[localDW->setupIdx - 1];
      localB->setupData[3] = (int32_T)rtu_setupValues[localDW->setupIdx + 7];
      break;

     default:
      /* During 'startPolling': '<S125>:172' */
      if (rtu_pollResponse[1] == 1) {
        /* Transition: '<S125>:175' */
        localDW->is_c43_ethercat = gbyk_v4b_IN_disable1;

        /* Entry 'disable1': '<S125>:174' */
        localB->SDORequest[0] = 0;
      }
      break;
    }
  }
}

/*
 * Output and update for atomic system:
 *    '<S88>/set-up values'
 *    '<S89>/set-up values'
 *    '<S140>/set-up values'
 *    '<S141>/set-up values'
 */
void gbyk_v4b_setupvalues(B_setupvalues_gbyk_v4b_T *localB)
{
  static const int16_T tmp[24] = { 12475, 12475, 12475, 12475, 12475, 12475,
    12475, 12475, 3, 4, 5, 10, 11, 12, 13, 1, 3, 2, 2, 2, 4, 19, 24, 6 };

  static const int16_T tmp_0[12] = { 12032, 12032, 12032, 12032, 12032, 12032,
    19, 20, 21, 22, 23, 24 };

  int32_T i;
  for (i = 0; i < 24; i++) {
    localB->setupValues[i] = tmp[i];
  }

  localB->pollValues[0] = 12475.0;
  localB->pollValues[1] = 1.0;
  localB->pollValues[2] = 0.0;
  for (i = 0; i < 12; i++) {
    localB->encoderValues[i] = tmp_0[i];
  }

  /* MATLAB Function 'EtherCAT Subsystem/Arm 1/M1 AbsEnc Calibration/set-up values': '<S126>:1' */
  /* this is an array of [address, sub index, value to write]. These all */
  /* came from HAR-568. */
  /*  %record the low to high transition */
  /*  %(do nothing when the capture is complete) */
  /*  % (do not change encoder position value to a present value upon completion; we need to use an algorithm to decide this afterwards) */
  /*  % (Socket used for this stuff; i.e. the secondary encoder is socket #2 */
  /*  % (Store in UI array where this is stored. Of the 5 options, only UI can be read using ECAT) */
  /*  %(start of capture array indices) */
  /*  % (end of capture array indices) */
  /*  %  (# events to record) */
  /* '<S126>:1:5' */
  /* '<S126>:1:16' */
  localB->setupValuesCount = 8.0;

  /* '<S126>:1:18' */
  /* When this addr is 0 then the values have all been read */
  /*  % GI - 0x2f00 */
  /* '<S126>:1:20' */
  /* '<S126>:1:29' */
  localB->encoderValuesCount = 6.0;
}

/* Function for Chart: '<S75>/SDO read machine' */
static void gbyk_v4b_clearValues(B_SDOreadmachine_gbyk_v4b_T *localB)
{
  int32_T n;

  /* MATLAB Function 'clearValues': '<S90>:167' */
  /* '<S90>:167:2' */
  /* '<S90>:167:6' */
  for (n = 0; n < 20; n++) {
    /* '<S90>:167:2' */
    /* '<S90>:167:3' */
    localB->intSDOValues[n] = 0;

    /* '<S90>:167:2' */
    /* '<S90>:167:6' */
    /* '<S90>:167:7' */
    localB->floatSDOValues[n] = 0.0;

    /* '<S90>:167:6' */
  }
}

/*
 * Initial conditions for atomic system:
 *    '<S75>/SDO read machine'
 *    '<S76>/SDO read machine'
 */
void gbyk_v4b_SDOreadmachine_Init(B_SDOreadmachine_gbyk_v4b_T *localB,
  DW_SDOreadmachine_gbyk_v4b_T *localDW)
{
  localDW->sfEvent = gbyk_v4b_CALL_EVENT_lt;
  localDW->is_active_c49_ethercat = 0U;
  localDW->is_c49_ethercat = gbyk_v4b_IN_NO_ACTIVE_CHILD_c;
  localDW->valueIdx = 0;
  localDW->lastTrigger = -1;
  localDW->valueCount = 0.0;
  localB->SDOCommand[0] = 0;
  localB->SDOCommand[1] = 0;
  localB->SDOCommand[2] = 0;
  localB->intSDOValues[0] = 0;
  localB->intSDOValues[1] = 0;
  localB->intSDOValues[2] = 0;
  localB->intSDOValues[3] = 0;
  localB->intSDOValues[4] = 0;
  localB->intSDOValues[5] = 0;
  localB->intSDOValues[6] = 0;
  localB->intSDOValues[7] = 0;
  localB->intSDOValues[8] = 0;
  localB->intSDOValues[9] = 0;
  localB->intSDOValues[10] = 0;
  localB->intSDOValues[11] = 0;
  localB->intSDOValues[12] = 0;
  localB->intSDOValues[13] = 0;
  localB->intSDOValues[14] = 0;
  localB->intSDOValues[15] = 0;
  localB->intSDOValues[16] = 0;
  localB->intSDOValues[17] = 0;
  localB->intSDOValues[18] = 0;
  localB->intSDOValues[19] = 0;
  localB->floatSDOValues[0] = 0.0;
  localB->floatSDOValues[1] = 0.0;
  localB->floatSDOValues[2] = 0.0;
  localB->floatSDOValues[3] = 0.0;
  localB->floatSDOValues[4] = 0.0;
  localB->floatSDOValues[5] = 0.0;
  localB->floatSDOValues[6] = 0.0;
  localB->floatSDOValues[7] = 0.0;
  localB->floatSDOValues[8] = 0.0;
  localB->floatSDOValues[9] = 0.0;
  localB->floatSDOValues[10] = 0.0;
  localB->floatSDOValues[11] = 0.0;
  localB->floatSDOValues[12] = 0.0;
  localB->floatSDOValues[13] = 0.0;
  localB->floatSDOValues[14] = 0.0;
  localB->floatSDOValues[15] = 0.0;
  localB->floatSDOValues[16] = 0.0;
  localB->floatSDOValues[17] = 0.0;
  localB->floatSDOValues[18] = 0.0;
  localB->floatSDOValues[19] = 0.0;
  localB->complete = 0;
}

/*
 * Output and update for atomic system:
 *    '<S75>/SDO read machine'
 *    '<S76>/SDO read machine'
 */
void gbyk_v4b_SDOreadmachine(int32_T rtu_triggerReading, const real_T
  rtu_intReadAddrs[24], real_T rtu_intCount, int32_T rtu_intSDOResponse, const
  real_T rtu_floatReadAddrs[24], real_T rtu_floatCount, real_T
  rtu_floatSDOResponse, real_T rtu_status, B_SDOreadmachine_gbyk_v4b_T *localB,
  DW_SDOreadmachine_gbyk_v4b_T *localDW)
{
  /* Gateway: EtherCAT Subsystem/Arm 1/SDO read machine */
  localDW->sfEvent = gbyk_v4b_CALL_EVENT_lt;

  /* During: EtherCAT Subsystem/Arm 1/SDO read machine */
  if (localDW->is_active_c49_ethercat == 0U) {
    /* Entry: EtherCAT Subsystem/Arm 1/SDO read machine */
    localDW->is_active_c49_ethercat = 1U;

    /* Entry Internal: EtherCAT Subsystem/Arm 1/SDO read machine */
    /* Transition: '<S90>:140' */
    localDW->is_c49_ethercat = gbyk_v4b_IN_setup_g;

    /* Entry 'setup': '<S90>:139' */
    localDW->valueIdx = 0;
    localB->complete = 0;
    gbyk_v4b_clearValues(localB);
    localDW->valueCount = rtu_intCount;
  } else {
    switch (localDW->is_c49_ethercat) {
     case gbyk_v4b_IN_Done_e:
      /* During 'Done': '<S90>:146' */
      if (rtu_triggerReading != localDW->lastTrigger) {
        /* Transition: '<S90>:164' */
        localDW->is_c49_ethercat = gbyk_v4b_IN_setup_g;

        /* Entry 'setup': '<S90>:139' */
        localDW->valueIdx = 0;
        localB->complete = 0;
        gbyk_v4b_clearValues(localB);
        localDW->valueCount = rtu_intCount;
      }
      break;

     case gbyk_v4b_IN_ReadNextFloat:
      /* During 'ReadNextFloat': '<S90>:184' */
      if (rtu_status == 1.0) {
        /* Transition: '<S90>:187' */
        localDW->is_c49_ethercat = gbyk_v4b_IN_disableFloat;

        /* Entry 'disableFloat': '<S90>:186' */
        localB->SDOCommand[0] = 0;
      }
      break;

     case gbyk_v4b_IN_ReadNextInt:
      /* During 'ReadNextInt': '<S90>:141' */
      if (rtu_status == 1.0) {
        /* Transition: '<S90>:157' */
        localDW->is_c49_ethercat = gbyk_v4b_IN_disableInt;

        /* Entry 'disableInt': '<S90>:156' */
        localB->SDOCommand[0] = 0;
      }
      break;

     case gbyk_v4b_IN_ReceivedFloat:
      /* During 'ReceivedFloat': '<S90>:188' */
      if (localDW->valueIdx + 1 > localDW->valueCount) {
        /* Transition: '<S90>:191' */
        localDW->is_c49_ethercat = gbyk_v4b_IN_Done_e;

        /* Entry 'Done': '<S90>:146' */
        localB->complete = 1;
        localDW->lastTrigger = rtu_triggerReading;
      } else {
        if (rtu_status == 0.0) {
          /* Transition: '<S90>:192' */
          localDW->is_c49_ethercat = gbyk_v4b_IN_ReadNextFloat;

          /* Entry 'ReadNextFloat': '<S90>:184' */
          localDW->valueIdx++;
          localB->SDOCommand[0] = 1;
          localB->SDOCommand[1] = (int32_T)rtu_floatReadAddrs[localDW->valueIdx
            - 1];
          localB->SDOCommand[2] = (int32_T)rtu_floatReadAddrs[localDW->valueIdx
            + 11];
        }
      }
      break;

     case gbyk_v4b_IN_ReceivedInt:
      /* During 'ReceivedInt': '<S90>:142' */
      if (localDW->valueIdx + 1 > localDW->valueCount) {
        /* Transition: '<S90>:147' */
        localDW->is_c49_ethercat = gbyk_v4b_IN_startFloats;

        /* Entry 'startFloats': '<S90>:183' */
        localDW->valueCount = rtu_floatCount;
        localDW->valueIdx = 0;
      } else {
        if (rtu_status == 0.0) {
          /* Transition: '<S90>:144' */
          localDW->is_c49_ethercat = gbyk_v4b_IN_ReadNextInt;

          /* Entry 'ReadNextInt': '<S90>:141' */
          localDW->valueIdx++;
          localB->SDOCommand[0] = 1;
          localB->SDOCommand[1] = (int32_T)rtu_intReadAddrs[localDW->valueIdx -
            1];
          localB->SDOCommand[2] = (int32_T)rtu_intReadAddrs[localDW->valueIdx +
            11];
        }
      }
      break;

     case gbyk_v4b_IN_disableFloat:
      /* During 'disableFloat': '<S90>:186' */
      if (rtu_status >= 2.0) {
        /* Transition: '<S90>:189' */
        localDW->is_c49_ethercat = gbyk_v4b_IN_ReceivedFloat;

        /* Entry 'ReceivedFloat': '<S90>:188' */
        localB->floatSDOValues[localDW->valueIdx - 1] = rtu_floatSDOResponse;
      }
      break;

     case gbyk_v4b_IN_disableInt:
      /* During 'disableInt': '<S90>:156' */
      if (rtu_status >= 2.0) {
        /* Transition: '<S90>:143' */
        localDW->is_c49_ethercat = gbyk_v4b_IN_ReceivedInt;

        /* Entry 'ReceivedInt': '<S90>:142' */
        localB->intSDOValues[localDW->valueIdx - 1] = rtu_intSDOResponse;
      }
      break;

     case gbyk_v4b_IN_setup_g:
      /* During 'setup': '<S90>:139' */
      /* Transition: '<S90>:145' */
      localDW->is_c49_ethercat = gbyk_v4b_IN_ReadNextInt;

      /* Entry 'ReadNextInt': '<S90>:141' */
      localDW->valueIdx++;
      localB->SDOCommand[0] = 1;
      localB->SDOCommand[1] = (int32_T)rtu_intReadAddrs[localDW->valueIdx - 1];
      localB->SDOCommand[2] = (int32_T)rtu_intReadAddrs[localDW->valueIdx + 11];
      break;

     default:
      /* During 'startFloats': '<S90>:183' */
      /* Transition: '<S90>:185' */
      localDW->is_c49_ethercat = gbyk_v4b_IN_ReadNextFloat;

      /* Entry 'ReadNextFloat': '<S90>:184' */
      localDW->valueIdx++;
      localB->SDOCommand[0] = 1;
      localB->SDOCommand[1] = (int32_T)rtu_floatReadAddrs[localDW->valueIdx - 1];
      localB->SDOCommand[2] = (int32_T)rtu_floatReadAddrs[localDW->valueIdx + 11];
      break;
    }
  }
}

/*
 * Output and update for atomic system:
 *    '<S129>/converter'
 *    '<S135>/converter'
 *    '<S181>/converter'
 *    '<S187>/converter'
 */
void gbyk_v4b_converter(uint32_T rtu_inVal, B_converter_gbyk_v4b_T *localB)
{
  uint32_T uint32Out;
  int32_T int32Out;
  real32_T y;

  /* MATLAB Function 'Read Drive 1 SDO/converter': '<S132>:1' */
  /* '<S132>:1:4' */
  memcpy(&uint32Out, &rtu_inVal, (size_t)1 * sizeof(uint32_T));

  /* '<S132>:1:5' */
  memcpy(&int32Out, &rtu_inVal, (size_t)1 * sizeof(int32_T));

  /* '<S132>:1:6' */
  memcpy(&y, &rtu_inVal, (size_t)1 * sizeof(real32_T));
  localB->uint32Out = uint32Out;
  localB->int32Out = int32Out;
  localB->doubleOut = y;
}

/* Output and update for atomic system: '<S91>/Read Drive 1 SDO' */
void gbyk_v4b_ReadDrive1SDO(void)
{
  /* S-Function (BKINethercatasyncsdoupload): '<S129>/BKIN EtherCAT Async SDO Upload1' */
  {
    int8_T *sigOutputPtr;
    int32_T *sigStatusPtr;
    int32_T *enInputPtr;
    int_T deviceIndex;
    static int counter= 0;
    int_T actLen;
    int_T res;
    int_T state;
    int32_T *indexInputPtr;
    int32_T *subIndexInputPtr;
    deviceIndex = gbyk_v4b_DW.BKINEtherCATAsyncSDOUpload1_IWORK_a[0];
    if (deviceIndex != NO_ETHERCAT) {
      state = xpcEtherCATgetState( deviceIndex );
      if (state >= 2 ) {
        sigOutputPtr = &gbyk_v4b_B.BKINEtherCATAsyncSDOUpload1_o1_p;
        sigStatusPtr = &gbyk_v4b_B.BKINEtherCATAsyncSDOUpload1_o2_i;
        enInputPtr = &gbyk_v4b_B.sf_SDOreadmachine_p.enable;
        indexInputPtr = &gbyk_v4b_B.DataTypeConversion2_l;
        subIndexInputPtr = &gbyk_v4b_B.DataTypeConversion1_dx;
        if (gbyk_v4b_DW.BKINEtherCATAsyncSDOUpload1_IWORK_a[7] != 0) {
          res = ecatAsyncSDOUpload(deviceIndex,
            1001,
            (unsigned short)*indexInputPtr,
            (unsigned char)*subIndexInputPtr,
            (void *)sigOutputPtr,
            1*4,
            &actLen,
            500,
            35101310,
            sigStatusPtr,
            *enInputPtr);
        }

        gbyk_v4b_DW.BKINEtherCATAsyncSDOUpload1_IWORK_a[7] = 1;
        ;
      }
    }
  }

  /* DataTypeConversion: '<S129>/Data Type Conversion' */
  gbyk_v4b_B.DataTypeConversion_ba = gbyk_v4b_B.BKINEtherCATAsyncSDOUpload1_o2_i;

  /* MATLAB Function: '<S129>/converter' */
  gbyk_v4b_converter(gbyk_v4b_B.BKINEtherCATAsyncSDOUpload1_o1_p,
                     &gbyk_v4b_B.sf_converter);
}

/* Termination for atomic system: '<S91>/Read Drive 1 SDO' */
void gbyk_v4b_ReadDrive1SDO_Term(void)
{
  /* Terminate for S-Function (BKINethercatasyncsdoupload): '<S129>/BKIN EtherCAT Async SDO Upload1' */
  {
    int_T deviceIndex;
    if (!xpcIsModelInit()) {
      deviceIndex = gbyk_v4b_DW.BKINEtherCATAsyncSDOUpload1_IWORK_a[0];
      if (deviceIndex != NO_ETHERCAT) {
        unregisterAsyncSDOUpload(35101310, deviceIndex);
        printf("SDO Upload. Unregister device %d, slave addr: %d\n", deviceIndex,
               1001);
      }
    }
  }
}

/*
 * Initial conditions for atomic system:
 *    '<S91>/SDO read machine'
 *    '<S143>/SDO read machine'
 */
void gbyk_v4b_SDOreadmachine_p_Init(B_SDOreadmachine_gbyk_v4b_n_T *localB,
  DW_SDOreadmachine_gbyk_v4b_m_T *localDW)
{
  localDW->sfEvent = gbyk_v4b_CALL_EVENT_lg;
  localDW->is_active_c50_ethercat = 0U;
  localDW->is_c50_ethercat = gbyk_v4b_IN_NO_ACTIVE_CHILD_b;
  localDW->lastTriggerValue = 0;
  localB->enable = 0;
  localB->complete = 0;
}

/*
 * Output and update for atomic system:
 *    '<S91>/SDO read machine'
 *    '<S143>/SDO read machine'
 */
void gbyk_v4b_SDOreadmachine_p(real_T rtu_triggerWriting, real_T rtu_readState,
  B_SDOreadmachine_gbyk_v4b_n_T *localB, DW_SDOreadmachine_gbyk_v4b_m_T *localDW)
{
  boolean_T guard1 = false;

  /* Gateway: EtherCAT Subsystem/Arm 1/SDO reading/SDO read machine */
  localDW->sfEvent = gbyk_v4b_CALL_EVENT_lg;

  /* During: EtherCAT Subsystem/Arm 1/SDO reading/SDO read machine */
  if (localDW->is_active_c50_ethercat == 0U) {
    /* Entry: EtherCAT Subsystem/Arm 1/SDO reading/SDO read machine */
    localDW->is_active_c50_ethercat = 1U;

    /* Entry Internal: EtherCAT Subsystem/Arm 1/SDO reading/SDO read machine */
    /* Transition: '<S130>:140' */
    localDW->is_c50_ethercat = gbyk_v4b_IN_setup_a;

    /* Entry 'setup': '<S130>:139' */
    localB->enable = 0;
  } else {
    switch (localDW->is_c50_ethercat) {
     case gbyk_v4b_IN_ReadNext_n:
      /* During 'ReadNext': '<S130>:141' */
      if (rtu_readState == 1.0) {
        /* Transition: '<S130>:157' */
        localDW->is_c50_ethercat = gbyk_v4b_IN_disable_a;

        /* Entry 'disable': '<S130>:156' */
        localB->enable = 0;
      }
      break;

     case gbyk_v4b_IN_disable_a:
      /* During 'disable': '<S130>:156' */
      if (rtu_readState == 2.0) {
        /* Transition: '<S130>:143' */
        localB->complete = 1;
        guard1 = true;
      } else {
        if (rtu_readState == 3.0) {
          /* Transition: '<S130>:169' */
          localB->complete = -1;
          guard1 = true;
        }
      }
      break;

     default:
      /* During 'setup': '<S130>:139' */
      if (rtu_triggerWriting != localDW->lastTriggerValue) {
        /* Transition: '<S130>:145' */
        localDW->is_c50_ethercat = gbyk_v4b_IN_ReadNext_n;

        /* Entry 'ReadNext': '<S130>:141' */
        localB->enable = 1;
        localB->complete = 0;
      }
      break;
    }

    if (guard1) {
      /* Transition: '<S130>:167' */
      localDW->lastTriggerValue = (int32_T)rtu_triggerWriting;
      localDW->is_c50_ethercat = gbyk_v4b_IN_setup_a;

      /* Entry 'setup': '<S130>:139' */
      localB->enable = 0;
    }
  }
}

/*
 * Output and update for atomic system:
 *    '<S91>/values'
 *    '<S143>/values'
 */
void gbyk_v4b_values(real_T rtu_inVal, real_T rtu_inVal_g, real_T rtu_inVal_o,
                     B_values_gbyk_v4b_T *localB)
{
  /* SignalConversion: '<S131>/TmpSignal ConversionAt SFunction Inport1' */
  localB->TmpSignalConversionAtSFunctionInport1[0] = rtu_inVal;
  localB->TmpSignalConversionAtSFunctionInport1[1] = rtu_inVal_g;
  localB->TmpSignalConversionAtSFunctionInport1[2] = rtu_inVal_o;

  /* MATLAB Function 'EtherCAT Subsystem/Arm 1/SDO reading/values': '<S131>:1' */
  /* this is only useful so that I can read the signals! */
  /* '<S131>:1:4' */
  localB->outVal[0] = localB->TmpSignalConversionAtSFunctionInport1[0];
  localB->outVal[1] = localB->TmpSignalConversionAtSFunctionInport1[1];
  localB->outVal[2] = localB->TmpSignalConversionAtSFunctionInport1[2];
}

/* Initial conditions for atomic system: '<S75>/SDO reading' */
void gbyk_v4b_SDOreading_Init(void)
{
  /* InitializeConditions for Memory: '<S91>/Memory' */
  gbyk_v4b_DW.Memory_PreviousInput_d = gbyk_v4b_P.Memory_X0_j;

  /* InitializeConditions for Chart: '<S91>/SDO read machine' */
  gbyk_v4b_SDOreadmachine_p_Init(&gbyk_v4b_B.sf_SDOreadmachine_p,
    &gbyk_v4b_DW.sf_SDOreadmachine_p);
}

/* Start for atomic system: '<S75>/SDO reading' */
void gbyk_v4b_SDOreading_Start(void)
{
  /* Start for Constant: '<S91>/readAddr' */
  gbyk_v4b_B.readAddr_p[0] = gbyk_v4b_P.readAddr_Value[0];
  gbyk_v4b_B.readAddr_p[1] = gbyk_v4b_P.readAddr_Value[1];
  gbyk_v4b_B.readAddr_p[2] = gbyk_v4b_P.readAddr_Value[2];
}

/* Outputs for atomic system: '<S75>/SDO reading' */
void gbyk_v4b_SDOreading(void)
{
  real_T tmp;

  /* Constant: '<S91>/readAddr' */
  gbyk_v4b_B.readAddr_p[0] = gbyk_v4b_P.readAddr_Value[0];
  gbyk_v4b_B.readAddr_p[1] = gbyk_v4b_P.readAddr_Value[1];
  gbyk_v4b_B.readAddr_p[2] = gbyk_v4b_P.readAddr_Value[2];

  /* DataTypeConversion: '<S91>/Data Type Conversion1' */
  tmp = floor(gbyk_v4b_B.readAddr_p[2]);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 4.294967296E+9);
  }

  gbyk_v4b_B.DataTypeConversion1_dx = tmp < 0.0 ? -(int32_T)(uint32_T)-tmp :
    (int32_T)(uint32_T)tmp;

  /* End of DataTypeConversion: '<S91>/Data Type Conversion1' */

  /* DataTypeConversion: '<S91>/Data Type Conversion2' */
  tmp = floor(gbyk_v4b_B.readAddr_p[1]);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 4.294967296E+9);
  }

  gbyk_v4b_B.DataTypeConversion2_l = tmp < 0.0 ? -(int32_T)(uint32_T)-tmp :
    (int32_T)(uint32_T)tmp;

  /* End of DataTypeConversion: '<S91>/Data Type Conversion2' */

  /* Memory: '<S91>/Memory' */
  gbyk_v4b_B.Memory_n = gbyk_v4b_DW.Memory_PreviousInput_d;

  /* Chart: '<S91>/SDO read machine' */
  gbyk_v4b_SDOreadmachine_p(gbyk_v4b_B.readAddr_p[0], gbyk_v4b_B.Memory_n,
    &gbyk_v4b_B.sf_SDOreadmachine_p, &gbyk_v4b_DW.sf_SDOreadmachine_p);

  /* Outputs for Atomic SubSystem: '<S91>/Read Drive 1 SDO' */
  gbyk_v4b_ReadDrive1SDO();

  /* End of Outputs for SubSystem: '<S91>/Read Drive 1 SDO' */

  /* DataTypeConversion: '<S91>/convert' */
  gbyk_v4b_B.convert_b = gbyk_v4b_B.sf_converter.uint32Out;

  /* DataTypeConversion: '<S91>/convert1' */
  gbyk_v4b_B.convert1_f = gbyk_v4b_B.sf_converter.int32Out;

  /* DataTypeConversion: '<S91>/status' */
  gbyk_v4b_B.status_d = gbyk_v4b_B.sf_SDOreadmachine_p.complete;

  /* MATLAB Function: '<S91>/values' */
  gbyk_v4b_values(gbyk_v4b_B.convert_b, gbyk_v4b_B.convert1_f,
                  gbyk_v4b_B.sf_converter.doubleOut, &gbyk_v4b_B.sf_values);
}

/* Update for atomic system: '<S75>/SDO reading' */
void gbyk_v4b_SDOreading_Update(void)
{
  /* Update for Memory: '<S91>/Memory' */
  gbyk_v4b_DW.Memory_PreviousInput_d = gbyk_v4b_B.DataTypeConversion_ba;
}

/* Termination for atomic system: '<S75>/SDO reading' */
void gbyk_v4b_SDOreading_Term(void)
{
  /* Terminate for Atomic SubSystem: '<S91>/Read Drive 1 SDO' */
  gbyk_v4b_ReadDrive1SDO_Term();

  /* End of Terminate for SubSystem: '<S91>/Read Drive 1 SDO' */
}

/*
 * Initial conditions for atomic system:
 *    '<S92>/SDO write machine'
 *    '<S144>/SDO write machine'
 */
void gbyk_v4b_SDOwritemachine_Init(B_SDOwritemachine_gbyk_v4b_T *localB,
  DW_SDOwritemachine_gbyk_v4b_T *localDW)
{
  localDW->sfEvent = gbyk_v4b_CALL_EVENT_if;
  localDW->is_active_c52_ethercat = 0U;
  localDW->is_c52_ethercat = gbyk_v4b_IN_NO_ACTIVE_CHILD_f;
  localDW->lastTriggerValue = 0;
  localB->enable = 0;
  localB->complete = 0;
}

/*
 * Output and update for atomic system:
 *    '<S92>/SDO write machine'
 *    '<S144>/SDO write machine'
 */
void gbyk_v4b_SDOwritemachine(real_T rtu_triggerReading, int32_T rtu_writeState,
  B_SDOwritemachine_gbyk_v4b_T *localB, DW_SDOwritemachine_gbyk_v4b_T *localDW)
{
  boolean_T guard1 = false;

  /* Gateway: EtherCAT Subsystem/Arm 1/SDO writing/SDO write machine */
  localDW->sfEvent = gbyk_v4b_CALL_EVENT_if;

  /* During: EtherCAT Subsystem/Arm 1/SDO writing/SDO write machine */
  if (localDW->is_active_c52_ethercat == 0U) {
    /* Entry: EtherCAT Subsystem/Arm 1/SDO writing/SDO write machine */
    localDW->is_active_c52_ethercat = 1U;

    /* Entry Internal: EtherCAT Subsystem/Arm 1/SDO writing/SDO write machine */
    /* Transition: '<S133>:140' */
    localDW->is_c52_ethercat = gbyk_v4b_IN_setup_i;

    /* Entry 'setup': '<S133>:139' */
    localB->enable = 0;
  } else {
    switch (localDW->is_c52_ethercat) {
     case gbyk_v4b_IN_ReadNext_o:
      /* During 'ReadNext': '<S133>:141' */
      if (rtu_writeState == 1) {
        /* Transition: '<S133>:157' */
        localDW->is_c52_ethercat = gbyk_v4b_IN_disable_g;

        /* Entry 'disable': '<S133>:156' */
        localB->enable = 0;
      }
      break;

     case gbyk_v4b_IN_disable_g:
      /* During 'disable': '<S133>:156' */
      if (rtu_writeState == 2) {
        /* Transition: '<S133>:143' */
        localB->complete = 1;
        guard1 = true;
      } else {
        if (rtu_writeState == 3) {
          /* Transition: '<S133>:168' */
          localB->complete = -1;
          guard1 = true;
        }
      }
      break;

     default:
      /* During 'setup': '<S133>:139' */
      if (rtu_triggerReading != localDW->lastTriggerValue) {
        /* Transition: '<S133>:145' */
        localDW->is_c52_ethercat = gbyk_v4b_IN_ReadNext_o;

        /* Entry 'ReadNext': '<S133>:141' */
        localB->enable = 1;
        localB->complete = 0;
      }
      break;
    }

    if (guard1) {
      /* Transition: '<S133>:170' */
      localDW->lastTriggerValue = (int32_T)rtu_triggerReading;
      localDW->is_c52_ethercat = gbyk_v4b_IN_setup_i;

      /* Entry 'setup': '<S133>:139' */
      localB->enable = 0;
    }
  }
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/*
 * Output and update for atomic system:
 *    '<S92>/convert'
 *    '<S144>/convert'
 */
void gbyk_v4b_convert(real_T rtu_u, real_T rtu_type, B_convert_gbyk_v4b_T
                      *localB)
{
  uint32_T y;
  real32_T x;
  int32_T b_x;
  real_T tmp;

  /* MATLAB Function 'EtherCAT Subsystem/Arm 1/SDO writing/convert': '<S134>:1' */
  if (rtu_type == 1.0) {
    /* '<S134>:1:4' */
    /* '<S134>:1:5' */
    tmp = rt_roundd_snf(rtu_u);
    if (tmp < 4.294967296E+9) {
      if (tmp >= 0.0) {
        y = (uint32_T)tmp;
      } else {
        y = 0U;
      }
    } else {
      y = MAX_uint32_T;
    }
  } else if (rtu_type == 2.0) {
    /* '<S134>:1:6' */
    /* '<S134>:1:7' */
    tmp = rt_roundd_snf(rtu_u);
    if (tmp < 2.147483648E+9) {
      if (tmp >= -2.147483648E+9) {
        b_x = (int32_T)tmp;
      } else {
        b_x = MIN_int32_T;
      }
    } else {
      b_x = MAX_int32_T;
    }

    memcpy(&y, &b_x, (size_t)1 * sizeof(uint32_T));
  } else {
    /* '<S134>:1:9' */
    x = (real32_T)rtu_u;
    memcpy(&y, &x, (size_t)1 * sizeof(uint32_T));
  }

  localB->y = y;
}

/* Initial conditions for atomic system: '<S75>/SDO writing' */
void gbyk_v4b_SDOwriting_Init(void)
{
  /* InitializeConditions for Memory: '<S92>/Memory' */
  gbyk_v4b_DW.Memory_PreviousInput_a = gbyk_v4b_P.Memory_X0_h;

  /* InitializeConditions for Chart: '<S92>/SDO write machine' */
  gbyk_v4b_SDOwritemachine_Init(&gbyk_v4b_B.sf_SDOwritemachine,
    &gbyk_v4b_DW.sf_SDOwritemachine);
}

/* Start for atomic system: '<S75>/SDO writing' */
void gbyk_v4b_SDOwriting_Start(void)
{
  int32_T i;

  /* Start for Constant: '<S92>/writeData' */
  for (i = 0; i < 5; i++) {
    gbyk_v4b_B.writeData_e[i] = gbyk_v4b_P.writeData_Value[i];
  }

  /* End of Start for Constant: '<S92>/writeData' */
}

/* Outputs for atomic system: '<S75>/SDO writing' */
void gbyk_v4b_SDOwriting(void)
{
  int32_T i;
  real_T tmp;

  /* Constant: '<S92>/writeData' */
  for (i = 0; i < 5; i++) {
    gbyk_v4b_B.writeData_e[i] = gbyk_v4b_P.writeData_Value[i];
  }

  /* End of Constant: '<S92>/writeData' */

  /* MATLAB Function: '<S92>/convert' */
  gbyk_v4b_convert(gbyk_v4b_B.writeData_e[1], gbyk_v4b_B.writeData_e[2],
                   &gbyk_v4b_B.sf_convert);

  /* Memory: '<S92>/Memory' */
  gbyk_v4b_B.Memory_nf = gbyk_v4b_DW.Memory_PreviousInput_a;

  /* Chart: '<S92>/SDO write machine' */
  gbyk_v4b_SDOwritemachine(gbyk_v4b_B.writeData_e[0], gbyk_v4b_B.Memory_nf,
    &gbyk_v4b_B.sf_SDOwritemachine, &gbyk_v4b_DW.sf_SDOwritemachine);

  /* DataTypeConversion: '<S92>/Data Type Conversion2' */
  tmp = floor(gbyk_v4b_B.writeData_e[3]);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 4.294967296E+9);
  }

  gbyk_v4b_B.DataTypeConversion2_b = tmp < 0.0 ? -(int32_T)(uint32_T)-tmp :
    (int32_T)(uint32_T)tmp;

  /* End of DataTypeConversion: '<S92>/Data Type Conversion2' */

  /* DataTypeConversion: '<S92>/Data Type Conversion1' */
  tmp = floor(gbyk_v4b_B.writeData_e[4]);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 4.294967296E+9);
  }

  gbyk_v4b_B.DataTypeConversion1_d = tmp < 0.0 ? -(int32_T)(uint32_T)-tmp :
    (int32_T)(uint32_T)tmp;

  /* End of DataTypeConversion: '<S92>/Data Type Conversion1' */

  /* S-Function (BKINethercatasyncsdodownload): '<S92>/BKIN EtherCAT Async SDO Download' */
  {
    int8_T *sigInputPtr;
    int32_T *sigStatusPtr;
    int32_T *enInputPtr;
    int_T deviceIndex;
    int_T res;
    int_T state;
    int32_T *indexInputPtr;
    int32_T *subIndexInputPtr;
    deviceIndex = gbyk_v4b_DW.BKINEtherCATAsyncSDODownload_IWORK_e[0];
    if (deviceIndex != NO_ETHERCAT) {
      state = xpcEtherCATgetState( deviceIndex );
      if (state >= 2 ) {
        sigStatusPtr = &gbyk_v4b_B.BKINEtherCATAsyncSDODownload_f;
        sigInputPtr = &gbyk_v4b_B.sf_convert.y;
        enInputPtr = &gbyk_v4b_B.sf_SDOwritemachine.enable;
        indexInputPtr = &gbyk_v4b_B.DataTypeConversion2_b;
        subIndexInputPtr = &gbyk_v4b_B.DataTypeConversion1_d;
        if (gbyk_v4b_DW.BKINEtherCATAsyncSDODownload_IWORK_e[7] != 0) {
          res = ecatAsyncSDODownload(deviceIndex,
            1001,
            (unsigned short)*indexInputPtr,
            (unsigned char)*subIndexInputPtr,
            (void *)sigInputPtr,
            1*4,
            500,
            34297580,
            sigStatusPtr,
            *enInputPtr);
        } else {
          *sigStatusPtr = 0;
        }

        gbyk_v4b_DW.BKINEtherCATAsyncSDODownload_IWORK_e[7] = 1;
        ;
      }
    }
  }

  /* DataTypeConversion: '<S92>/status' */
  gbyk_v4b_B.status_n = gbyk_v4b_B.sf_SDOwritemachine.complete;
}

/* Update for atomic system: '<S75>/SDO writing' */
void gbyk_v4b_SDOwriting_Update(void)
{
  /* Update for Memory: '<S92>/Memory' */
  gbyk_v4b_DW.Memory_PreviousInput_a = gbyk_v4b_B.BKINEtherCATAsyncSDODownload_f;
}

/* Termination for atomic system: '<S75>/SDO writing' */
void gbyk_v4b_SDOwriting_Term(void)
{
  /* Terminate for S-Function (BKINethercatasyncsdodownload): '<S92>/BKIN EtherCAT Async SDO Download' */
  {
    int_T deviceIndex;
    if (!xpcIsModelInit()) {
      deviceIndex = gbyk_v4b_DW.BKINEtherCATAsyncSDODownload_IWORK_e[0];
      if (deviceIndex != NO_ETHERCAT) {
        unregisterAsyncSDODownload(34297580, deviceIndex);
        printf("SDO Download. Unregister device %d, slave addr: %d\n",
               deviceIndex, 1001);
      }
    }
  }
}

/*
 * Initial conditions for atomic system:
 *    '<S75>/forceEnableDisable'
 *    '<S76>/forceEnableDisable'
 */
void gbyk_v4b_forceEnableDisable_Init(DW_forceEnableDisable_gbyk_v4b_T *localDW)
{
  localDW->lastRunningState = 0.0;
  localDW->faultResetCycles = 0.0;
}

/*
 * Output and update for atomic system:
 *    '<S75>/forceEnableDisable'
 *    '<S76>/forceEnableDisable'
 */
void gbyk_v4b_forceEnableDisable(real_T rtu_dexState, real_T rtu_task_state,
  const real_T rtu_forces[4], boolean_T rtu_allowEnableMotors, real_T
  rtu_motorFaults, real_T rtu_motorFaults_e, real_T rtu_fault_cycles_allowed,
  B_forceEnableDisable_gbyk_v4b_T *localB, DW_forceEnableDisable_gbyk_v4b_T
  *localDW)
{
  real_T y;
  boolean_T guard1 = false;

  /* SignalConversion: '<S93>/TmpSignal ConversionAt SFunction Inport5' */
  localB->TmpSignalConversionAtSFunctionInport5[0] = rtu_motorFaults;
  localB->TmpSignalConversionAtSFunctionInport5[1] = rtu_motorFaults_e;

  /* MATLAB Function 'EtherCAT Subsystem/Arm 1/forceEnableDisable': '<S93>:1' */
  /* '<S93>:1:10' */
  localB->forceMotorState = 0.0;

  /* if either motor is faulted then fault both */
  if (localB->TmpSignalConversionAtSFunctionInport5[0] +
      localB->TmpSignalConversionAtSFunctionInport5[1] != 0.0) {
    /* '<S93>:1:13' */
    /* '<S93>:1:14' */
    localDW->faultResetCycles++;

    /* if there was a fault on a motor we need to reset the motor to clear */
    /* the fault. This allows us to wait 40 cycles, or 10ms for all faults to */
    /* clear before we assume the fault is bad enough to kill both motors */
    if (!(localDW->faultResetCycles > rtu_fault_cycles_allowed)) {
      guard1 = true;
    } else {
      /* '<S93>:1:18' */
    }
  } else {
    guard1 = true;
  }

  if (guard1 && (!((rtu_dexState == 0.0) || (!rtu_allowEnableMotors)))) {
    /* if dex says the motor should be off, force it off! */
    /* this should only happen during certain calibrations when there are no forces */
    /* this needs to check for running or complete because otherwise this will */
    /* kill the motors as we are stopping the task and then DEX will report */
    /* motors faulting during the task */
    if (!((rtu_task_state == 2.0) || (rtu_task_state == 4.0))) {
      /* '<S93>:1:32' */
      guard1 = false;
    } else {
      /* '<S93>:1:32' */
    }

    /* running or complete */
    if (guard1) {
      /* '<S93>:1:32' */
      /* '<S93>:1:35' */
      localB->forceMotorState = 1.0;

      /* '<S93>:1:36' */
      localDW->lastRunningState = 1.0;
    } else {
      if (localDW->lastRunningState == 1.0) {
        /* '<S93>:1:40' */
        y = rtu_forces[0];
        y += rtu_forces[1];
        y += rtu_forces[2];
        y += rtu_forces[3];
        if (y != 0.0) {
          /* '<S93>:1:41' */
          /* '<S93>:1:42' */
          localB->forceMotorState = 1.0;
        } else {
          /* '<S93>:1:44' */
          localDW->lastRunningState = 0.0;
        }
      }
    }
  } else {
    /* '<S93>:1:25' */
  }
}

/* Output and update for atomic system: '<S94>/Read Drive 1 SDO' */
void gbyk_v4b_ReadDrive1SDO_p(void)
{
  /* S-Function (BKINethercatasyncsdoupload): '<S135>/BKIN EtherCAT Async SDO Upload1' */
  {
    int8_T *sigOutputPtr;
    int32_T *sigStatusPtr;
    int32_T *enInputPtr;
    int_T deviceIndex;
    static int counter= 0;
    int_T actLen;
    int_T res;
    int_T state;
    int32_T *indexInputPtr;
    int32_T *subIndexInputPtr;
    deviceIndex = gbyk_v4b_DW.BKINEtherCATAsyncSDOUpload1_IWORK_p[0];
    if (deviceIndex != NO_ETHERCAT) {
      state = xpcEtherCATgetState( deviceIndex );
      if (state >= 2 ) {
        sigOutputPtr = &gbyk_v4b_B.BKINEtherCATAsyncSDOUpload1_o1_l;
        sigStatusPtr = &gbyk_v4b_B.BKINEtherCATAsyncSDOUpload1_o2_g;
        enInputPtr = &gbyk_v4b_B.sf_SDOreadmachine.SDOCommand[0];
        indexInputPtr = &gbyk_v4b_B.sf_SDOreadmachine.SDOCommand[1];
        subIndexInputPtr = &gbyk_v4b_B.sf_SDOreadmachine.SDOCommand[2];
        if (gbyk_v4b_DW.BKINEtherCATAsyncSDOUpload1_IWORK_p[7] != 0) {
          res = ecatAsyncSDOUpload(deviceIndex,
            1001,
            (unsigned short)*indexInputPtr,
            (unsigned char)*subIndexInputPtr,
            (void *)sigOutputPtr,
            1*4,
            &actLen,
            500,
            35081310,
            sigStatusPtr,
            *enInputPtr);
        }

        gbyk_v4b_DW.BKINEtherCATAsyncSDOUpload1_IWORK_p[7] = 1;
        ;
      }
    }
  }

  /* DataTypeConversion: '<S135>/Data Type Conversion' */
  gbyk_v4b_B.DataTypeConversion_f = gbyk_v4b_B.BKINEtherCATAsyncSDOUpload1_o2_g;

  /* MATLAB Function: '<S135>/converter' */
  gbyk_v4b_converter(gbyk_v4b_B.BKINEtherCATAsyncSDOUpload1_o1_l,
                     &gbyk_v4b_B.sf_converter_p);
}

/* Termination for atomic system: '<S94>/Read Drive 1 SDO' */
void gbyk_v4b_ReadDrive1SDO_i_Term(void)
{
  /* Terminate for S-Function (BKINethercatasyncsdoupload): '<S135>/BKIN EtherCAT Async SDO Upload1' */
  {
    int_T deviceIndex;
    if (!xpcIsModelInit()) {
      deviceIndex = gbyk_v4b_DW.BKINEtherCATAsyncSDOUpload1_IWORK_p[0];
      if (deviceIndex != NO_ETHERCAT) {
        unregisterAsyncSDOUpload(35081310, deviceIndex);
        printf("SDO Upload. Unregister device %d, slave addr: %d\n", deviceIndex,
               1001);
      }
    }
  }
}

/*
 * Output and update for atomic system:
 *    '<S75>/size'
 *    '<S75>/size1'
 *    '<S76>/size'
 *    '<S76>/size1'
 */
void gbyk_v4b_size(B_size_gbyk_v4b_T *localB)
{
  /* MATLAB Function 'EtherCAT Subsystem/Arm 1/size': '<S95>:1' */
  /* '<S95>:1:3' */
  localB->count = 12.0;
}

/*
 * Output and update for atomic system:
 *    '<S75>/split out constants1'
 *    '<S76>/split out constants1'
 */
void gbyk_v4b_splitoutconstants1(const int32_T rtu_intVals[20], real_T
  rtu_forcePrimary, real_T rtu_robotType, B_splitoutconstants1_gbyk_v4b_T
  *localB)
{
  int32_T c;
  int32_T orientation;
  int32_T b_orientation;

  /* MATLAB Function 'EtherCAT Subsystem/Arm 1/split out constants1': '<S98>:1' */
  /* '<S98>:1:4' */
  /* '<S98>:1:6' */
  /* '<S98>:1:7' */
  /* '<S98>:1:9' */
  /* '<S98>:1:10' */
  localB->hasSecondary = rtu_intVals[3] & 1;
  if (rtu_forcePrimary != 0.0) {
    /* '<S98>:1:12' */
    localB->hasSecondary = 0.0;
  }

  /* '<S98>:1:14' */
  localB->hasFT = rtu_intVals[3] >> 1 & 1;

  /* '<S98>:1:15' */
  c = rtu_intVals[3] >> 2 & 1;

  /*  robot orientation (0 - right Exo or left EP; 1 - left Exo or right EP) */
  /* '<S98>:1:16' */
  if ((rtu_intVals[3] >> 3 & 1) == 1) {
    /* '<S98>:1:38' */
    /* '<S98>:1:39' */
    orientation = -1;
  } else {
    /* '<S98>:1:41' */
    orientation = 1;
  }

  if ((rtu_intVals[3] >> 4 & 1) == 1) {
    /* '<S98>:1:38' */
    /* '<S98>:1:39' */
    b_orientation = -1;
  } else {
    /* '<S98>:1:41' */
    b_orientation = 1;
  }

  localB->motorOrientation[0] = orientation;
  localB->motorOrientation[1] = b_orientation;

  /* '<S98>:1:19' */
  if ((rtu_intVals[3] >> 5 & 1) == 1) {
    /* '<S98>:1:38' */
    /* '<S98>:1:39' */
    orientation = -1;
  } else {
    /* '<S98>:1:41' */
    orientation = 1;
  }

  if ((rtu_intVals[3] >> 6 & 1) == 1) {
    /* '<S98>:1:38' */
    /* '<S98>:1:39' */
    b_orientation = -1;
  } else {
    /* '<S98>:1:41' */
    b_orientation = 1;
  }

  localB->encOrientation[0] = orientation;
  localB->encOrientation[1] = b_orientation;
  if (rtu_robotType == 1.0) {
    /* '<S98>:1:22' */
    if (c == 0) {
      /* '<S98>:1:23' */
      /* '<S98>:1:24' */
      orientation = -1;
    } else {
      /* '<S98>:1:26' */
      orientation = 1;
    }
  } else if (c == 0) {
    /* '<S98>:1:29' */
    /* '<S98>:1:30' */
    orientation = 1;
  } else {
    /* '<S98>:1:32' */
    orientation = -1;
  }

  localB->robotOrientation = orientation;
}

/* Start for atomic system: '<S137>/A2M1 PDOs' */
void gbyk_v4b_A2M1PDOs_Start(void)
{
  /* Level2 S-Function Block: '<S151>/BKIN PDO Receive ElmoDrive' (BKINethercatpdorxElmoDrive) */
  {
    SimStruct *rts = gbyk_v4b_M->childSfunctions[14];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }
}

/* Output and update for atomic system: '<S137>/A2M1 PDOs' */
void gbyk_v4b_A2M1PDOs(void)
{
  /* Level2 S-Function Block: '<S151>/BKIN PDO Receive ElmoDrive' (BKINethercatpdorxElmoDrive) */
  {
    SimStruct *rts = gbyk_v4b_M->childSfunctions[14];
    sfcnOutputs(rts, 1);
  }

  /* DataTypeConversion: '<S151>/Data Type Conversion' */
  gbyk_v4b_B.DataTypeConversion_et = gbyk_v4b_B.torque_g5;

  /* DataTypeConversion: '<S151>/A2M1Convert' */
  gbyk_v4b_B.A2M1Convert[0] = gbyk_v4b_B.primaryposition;
  gbyk_v4b_B.A2M1Convert[1] = gbyk_v4b_B.secondaryposition;
  gbyk_v4b_B.A2M1Convert[2] = gbyk_v4b_B.primaryvelocity;
  gbyk_v4b_B.A2M1Convert[3] = gbyk_v4b_B.DataTypeConversion_et;
  gbyk_v4b_B.A2M1Convert[4] = gbyk_v4b_B.digitalinput_d;

  /* MATLAB Function: '<S151>/parse status register1' */
  gbyk_v4b_parsestatusregister(gbyk_v4b_B.statusregister_i,
    &gbyk_v4b_B.sf_parsestatusregister1_f);
}

/* Termination for atomic system: '<S137>/A2M1 PDOs' */
void gbyk_v4b_A2M1PDOs_Term(void)
{
  /* Level2 S-Function Block: '<S151>/BKIN PDO Receive ElmoDrive' (BKINethercatpdorxElmoDrive) */
  {
    SimStruct *rts = gbyk_v4b_M->childSfunctions[14];
    sfcnTerminate(rts);
  }
}

/*
 * Initial conditions for atomic system:
 *    '<S154>/Read EMCY'
 *    '<S167>/Read EMCY'
 */
void gbyk_v4b_ReadEMCY_Init(B_ReadEMCY_gbyk_v4b_T *localB,
  DW_ReadEMCY_gbyk_v4b_T *localDW)
{
  localDW->sfEvent = gbyk_v4b_CALL_EVENT_jm;
  localDW->is_active_c104_ethercat = 0U;
  localDW->is_c104_ethercat = gbyk_v4b_IN_NO_ACTIVE_CHILD_fq;
  localDW->currReadIdx = 0.0;
  localDW->valuesToRead = 0.0;
  localB->triggerCountRead = 0;
  localB->emcyReadTrigger[0] = 0;
  localB->emcyReadTrigger[1] = 0;
  localB->countOverwriteTrigger = 0;
  localB->emcyValPump[0] = 0.0;
  localB->emcyValPump[1] = 0.0;
  localB->emcyValPump[2] = 0.0;
}

/*
 * Output and update for atomic system:
 *    '<S154>/Read EMCY'
 *    '<S167>/Read EMCY'
 */
void gbyk_v4b_ReadEMCY(real_T rtu_triggerReading, real_T rtu_driveID, const
  real_T rtu_countValues[2], const real_T rtu_emcyValues[2], real_T
  rtu_overwriteStatus, B_ReadEMCY_gbyk_v4b_T *localB, DW_ReadEMCY_gbyk_v4b_T
  *localDW)
{
  /* Gateway: EtherCAT Subsystem/Arm 2/A2M1/EMCY Message pump/Read EMCY */
  localDW->sfEvent = gbyk_v4b_CALL_EVENT_jm;

  /* During: EtherCAT Subsystem/Arm 2/A2M1/EMCY Message pump/Read EMCY */
  if (localDW->is_active_c104_ethercat == 0U) {
    /* Entry: EtherCAT Subsystem/Arm 2/A2M1/EMCY Message pump/Read EMCY */
    localDW->is_active_c104_ethercat = 1U;

    /* Entry Internal: EtherCAT Subsystem/Arm 2/A2M1/EMCY Message pump/Read EMCY */
    /* Transition: '<S157>:140' */
    localDW->is_c104_ethercat = gbyk_v4b_IN_setup_c;
  } else {
    switch (localDW->is_c104_ethercat) {
     case gbyk_v4b_IN_DoneClearing:
      /* During 'DoneClearing': '<S157>:197' */
      /* Transition: '<S157>:200' */
      localDW->is_c104_ethercat = gbyk_v4b_IN_setup_c;
      break;

     case gbyk_v4b_IN_ReadNextEMCY:
      /* During 'ReadNextEMCY': '<S157>:184' */
      if (rtu_emcyValues[1] == 1.0) {
        /* Transition: '<S157>:187' */
        localDW->is_c104_ethercat = gbyk_v4b_IN_disableEMCY;

        /* Entry 'disableEMCY': '<S157>:186' */
        localB->emcyReadTrigger[0] = 0;
      }
      break;

     case gbyk_v4b_IN_ReceivedFloat_d:
      /* During 'ReceivedFloat': '<S157>:188' */
      if (localDW->currReadIdx <= localDW->valuesToRead) {
        /* Transition: '<S157>:192' */
        localDW->is_c104_ethercat = gbyk_v4b_IN_ReadNextEMCY;

        /* Entry 'ReadNextEMCY': '<S157>:184' */
        localB->emcyReadTrigger[0] = 1;
        localB->emcyReadTrigger[1] = (int32_T)localDW->currReadIdx;
      } else {
        /* Transition: '<S157>:191' */
        localDW->is_c104_ethercat = gbyk_v4b_IN_StartOverwrite;

        /* Entry 'StartOverwrite': '<S157>:193' */
        localB->countOverwriteTrigger = 1;
        localB->emcyValPump[0] = 0.0;
        localB->emcyValPump[1] = 0.0;
        localB->emcyValPump[2] = 0.0;
      }
      break;

     case gbyk_v4b_IN_StartOverwrite:
      /* During 'StartOverwrite': '<S157>:193' */
      if (rtu_overwriteStatus == 1.0) {
        /* Transition: '<S157>:223' */
        localDW->is_c104_ethercat = gbyk_v4b_IN_DoneClearing;

        /* Entry 'DoneClearing': '<S157>:197' */
        localB->countOverwriteTrigger = 0;
      }
      break;

     case gbyk_v4b_IN_StartReadingCount:
      /* During 'StartReadingCount': '<S157>:141' */
      if (rtu_countValues[1] == 1.0) {
        /* Transition: '<S157>:157' */
        localDW->is_c104_ethercat = gbyk_v4b_IN_disableCount;

        /* Entry 'disableCount': '<S157>:156' */
        localB->triggerCountRead = 0;
      }
      break;

     case gbyk_v4b_IN_disableCount:
      /* During 'disableCount': '<S157>:156' */
      if (rtu_countValues[1] >= 2.0) {
        /* Transition: '<S157>:143' */
        if (rtu_countValues[0] == 0.0) {
          /* Transition: '<S157>:219' */
          localDW->is_c104_ethercat = gbyk_v4b_IN_setup_c;
        } else {
          /* Transition: '<S157>:220' */
          localDW->is_c104_ethercat = gbyk_v4b_IN_startEMCYs;

          /* Entry 'startEMCYs': '<S157>:183' */
          localDW->currReadIdx = 1.0;
          localDW->valuesToRead = rtu_countValues[1];
        }
      }
      break;

     case gbyk_v4b_IN_disableEMCY:
      /* During 'disableEMCY': '<S157>:186' */
      if (rtu_emcyValues[1] >= 2.0) {
        /* Transition: '<S157>:189' */
        localDW->is_c104_ethercat = gbyk_v4b_IN_ReceivedFloat_d;

        /* Entry 'ReceivedFloat': '<S157>:188' */
        localB->emcyValPump[0] = 1.0;

        /* ID for EMCY messge */
        localB->emcyValPump[1] = rtu_driveID;
        localB->emcyValPump[2] = rtu_emcyValues[0];
        localDW->currReadIdx++;
      }
      break;

     case gbyk_v4b_IN_setup_c:
      /* During 'setup': '<S157>:139' */
      if (rtu_triggerReading == 1.0) {
        /* Transition: '<S157>:145' */
        localDW->is_c104_ethercat = gbyk_v4b_IN_StartReadingCount;

        /* Entry 'StartReadingCount': '<S157>:141' */
        localB->triggerCountRead = 1;
      }
      break;

     default:
      /* During 'startEMCYs': '<S157>:183' */
      /* Transition: '<S157>:185' */
      localDW->is_c104_ethercat = gbyk_v4b_IN_ReadNextEMCY;

      /* Entry 'ReadNextEMCY': '<S157>:184' */
      localB->emcyReadTrigger[0] = 1;
      localB->emcyReadTrigger[1] = (int32_T)localDW->currReadIdx;
      break;
    }
  }
}

/* Initial conditions for atomic system: '<S137>/EMCY Message pump' */
void gbyk_v4b_EMCYMessagepump_f_Init(void)
{
  /* InitializeConditions for MATLAB Function: '<S154>/fault monitor' */
  gbyk_v4b_faultmonitor_Init(&gbyk_v4b_DW.sf_faultmonitor_f);

  /* InitializeConditions for Memory: '<S158>/Memory' */
  gbyk_v4b_DW.Memory_PreviousInput_cn[0] = gbyk_v4b_P.Memory_X0_co;
  gbyk_v4b_DW.Memory_PreviousInput_cn[1] = gbyk_v4b_P.Memory_X0_co;

  /* InitializeConditions for Memory: '<S159>/Memory' */
  gbyk_v4b_DW.Memory_PreviousInput_dg[0] = gbyk_v4b_P.Memory_X0_n5;
  gbyk_v4b_DW.Memory_PreviousInput_dg[1] = gbyk_v4b_P.Memory_X0_n5;

  /* InitializeConditions for Memory: '<S160>/Memory' */
  gbyk_v4b_DW.Memory_PreviousInput_p = gbyk_v4b_P.Memory_X0_n;

  /* InitializeConditions for Chart: '<S154>/Read EMCY' */
  gbyk_v4b_ReadEMCY_Init(&gbyk_v4b_B.sf_ReadEMCY_i, &gbyk_v4b_DW.sf_ReadEMCY_i);

  /* InitializeConditions for MATLAB Function: '<S154>/fault monitor1' */
  gbyk_v4b_faultmonitor1_Init(&gbyk_v4b_DW.sf_faultmonitor1_c);
}

/* Start for atomic system: '<S137>/EMCY Message pump' */
void gbyk_v4b_EMCYMessagepump_b_Start(void)
{
  /* Start for Constant: '<S154>/driveID' */
  gbyk_v4b_B.driveID_n = gbyk_v4b_P.driveID_Value_i;
}

/* Outputs for atomic system: '<S137>/EMCY Message pump' */
void gbyk_v4b_EMCYMessagepump_o1(void)
{
  /* DataTypeConversion: '<S154>/Data Type Conversion' */
  gbyk_v4b_B.DataTypeConversion_bd = gbyk_v4b_B.Statusword;

  /* MATLAB Function: '<S154>/fault monitor' */
  gbyk_v4b_faultmonitor(gbyk_v4b_B.Statusword, &gbyk_v4b_B.sf_faultmonitor_f,
                        &gbyk_v4b_DW.sf_faultmonitor_f);

  /* Constant: '<S154>/driveID' */
  gbyk_v4b_B.driveID_n = gbyk_v4b_P.driveID_Value_i;

  /* Memory: '<S158>/Memory' */
  gbyk_v4b_B.Memory_c1[0] = gbyk_v4b_DW.Memory_PreviousInput_cn[0];
  gbyk_v4b_B.Memory_c1[1] = gbyk_v4b_DW.Memory_PreviousInput_cn[1];

  /* DataTypeConversion: '<S158>/Data Type Conversion2' */
  gbyk_v4b_B.DataTypeConversion2_nh[0] = gbyk_v4b_B.Memory_c1[0];
  gbyk_v4b_B.DataTypeConversion2_nh[1] = gbyk_v4b_B.Memory_c1[1];

  /* Memory: '<S159>/Memory' */
  gbyk_v4b_B.Memory_a[0] = gbyk_v4b_DW.Memory_PreviousInput_dg[0];
  gbyk_v4b_B.Memory_a[1] = gbyk_v4b_DW.Memory_PreviousInput_dg[1];

  /* DataTypeConversion: '<S159>/Data Type Conversion' */
  gbyk_v4b_B.DataTypeConversion_p[0] = gbyk_v4b_B.Memory_a[0];
  gbyk_v4b_B.DataTypeConversion_p[1] = gbyk_v4b_B.Memory_a[1];

  /* Memory: '<S160>/Memory' */
  gbyk_v4b_B.Memory_g = gbyk_v4b_DW.Memory_PreviousInput_p;

  /* Chart: '<S154>/Read EMCY' */
  gbyk_v4b_ReadEMCY(gbyk_v4b_B.sf_faultmonitor_f.triggerFaultRead,
                    gbyk_v4b_B.driveID_n, gbyk_v4b_B.DataTypeConversion2_nh,
                    gbyk_v4b_B.DataTypeConversion_p, gbyk_v4b_B.Memory_g,
                    &gbyk_v4b_B.sf_ReadEMCY_i, &gbyk_v4b_DW.sf_ReadEMCY_i);

  /* DataTypeConversion: '<S158>/Data Type Conversion' */
  gbyk_v4b_B.DataTypeConversion_b3 = gbyk_v4b_B.sf_ReadEMCY_i.triggerCountRead;

  /* S-Function (BKINethercatasyncsdoupload): '<S158>/BKIN EtherCAT Async SDO Upload' */
  {
    int8_T *sigOutputPtr;
    int32_T *sigStatusPtr;
    int32_T *enInputPtr;
    int_T deviceIndex;
    static int counter= 0;
    int_T actLen;
    int_T res;
    int_T state;
    int32_T *indexInputPtr;
    int32_T *subIndexInputPtr;
    deviceIndex = gbyk_v4b_DW.BKINEtherCATAsyncSDOUpload_IWORK_n[0];
    if (deviceIndex != NO_ETHERCAT) {
      state = xpcEtherCATgetState( deviceIndex );
      if (state >= 2 ) {
        sigOutputPtr = &gbyk_v4b_B.BKINEtherCATAsyncSDOUpload_o1_l;
        sigStatusPtr = &gbyk_v4b_B.BKINEtherCATAsyncSDOUpload_o2_c;
        enInputPtr = &gbyk_v4b_B.DataTypeConversion_b3;
        indexInputPtr = &gbyk_v4b_P.Constant_Value_lk;
        subIndexInputPtr = &gbyk_v4b_P.Constant1_Value_o;
        if (gbyk_v4b_DW.BKINEtherCATAsyncSDOUpload_IWORK_n[7] != 0) {
          res = ecatAsyncSDOUpload(deviceIndex,
            1003,
            (unsigned short)*indexInputPtr,
            (unsigned char)*subIndexInputPtr,
            (void *)sigOutputPtr,
            1*4,
            &actLen,
            500,
            342973381,
            sigStatusPtr,
            *enInputPtr);
        }

        gbyk_v4b_DW.BKINEtherCATAsyncSDOUpload_IWORK_n[7] = 1;
        ;
      }
    }
  }

  /* DataTypeConversion: '<S158>/Data Type Conversion1' */
  gbyk_v4b_B.DataTypeConversion1_ij = (uint32_T)
    gbyk_v4b_B.BKINEtherCATAsyncSDOUpload_o2_c;

  /* RateTransition: '<S158>/Rate Transition' */
  gbyk_v4b_B.RateTransition_l[0] = gbyk_v4b_B.BKINEtherCATAsyncSDOUpload_o1_l;
  gbyk_v4b_B.RateTransition_l[1] = gbyk_v4b_B.DataTypeConversion1_ij;

  /* S-Function (BKINethercatasyncsdoupload): '<S159>/BKIN EtherCAT Async SDO Upload' */
  {
    int8_T *sigOutputPtr;
    int32_T *sigStatusPtr;
    int32_T *enInputPtr;
    int_T deviceIndex;
    static int counter= 0;
    int_T actLen;
    int_T res;
    int_T state;
    int32_T *indexInputPtr;
    int32_T *subIndexInputPtr;
    deviceIndex = gbyk_v4b_DW.BKINEtherCATAsyncSDOUpload_IWORK_i[0];
    if (deviceIndex != NO_ETHERCAT) {
      state = xpcEtherCATgetState( deviceIndex );
      if (state >= 2 ) {
        sigOutputPtr = &gbyk_v4b_B.BKINEtherCATAsyncSDOUpload_o1_d;
        sigStatusPtr = &gbyk_v4b_B.BKINEtherCATAsyncSDOUpload_o2_p;
        enInputPtr = &gbyk_v4b_B.sf_ReadEMCY_i.emcyReadTrigger[0];
        indexInputPtr = &gbyk_v4b_P.Constant_Value_k;
        subIndexInputPtr = &gbyk_v4b_B.sf_ReadEMCY_i.emcyReadTrigger[1];
        if (gbyk_v4b_DW.BKINEtherCATAsyncSDOUpload_IWORK_i[7] != 0) {
          res = ecatAsyncSDOUpload(deviceIndex,
            1003,
            (unsigned short)*indexInputPtr,
            (unsigned char)*subIndexInputPtr,
            (void *)sigOutputPtr,
            1*4,
            &actLen,
            500,
            342973393,
            sigStatusPtr,
            *enInputPtr);
        }

        gbyk_v4b_DW.BKINEtherCATAsyncSDOUpload_IWORK_i[7] = 1;
        ;
      }
    }
  }

  /* RateTransition: '<S159>/Rate Transition' */
  gbyk_v4b_B.RateTransition_k4[0] = gbyk_v4b_B.BKINEtherCATAsyncSDOUpload_o1_d;
  gbyk_v4b_B.RateTransition_k4[1] = gbyk_v4b_B.BKINEtherCATAsyncSDOUpload_o2_p;

  /* DataTypeConversion: '<S160>/Data Type Conversion' incorporates:
   *  Constant: '<S160>/Constant'
   */
  gbyk_v4b_B.DataTypeConversion_ek = (int32_T)gbyk_v4b_P.Constant_Value_c;

  /* S-Function (BKINethercatasyncsdodownload): '<S160>/BKIN EtherCAT Async SDO Download' */
  {
    int8_T *sigInputPtr;
    int32_T *sigStatusPtr;
    int32_T *enInputPtr;
    int_T deviceIndex;
    int_T res;
    int_T state;
    int32_T *indexInputPtr;
    int32_T *subIndexInputPtr;
    deviceIndex = gbyk_v4b_DW.BKINEtherCATAsyncSDODownload_IWORK_o[0];
    if (deviceIndex != NO_ETHERCAT) {
      state = xpcEtherCATgetState( deviceIndex );
      if (state >= 2 ) {
        sigStatusPtr = &gbyk_v4b_B.BKINEtherCATAsyncSDODownload_c;
        sigInputPtr = &gbyk_v4b_P.Constant_Value_c;
        enInputPtr = &gbyk_v4b_B.sf_ReadEMCY_i.countOverwriteTrigger;
        indexInputPtr = &gbyk_v4b_P.Constant1_Value_g;
        subIndexInputPtr = &gbyk_v4b_B.DataTypeConversion_ek;
        if (gbyk_v4b_DW.BKINEtherCATAsyncSDODownload_IWORK_o[7] != 0) {
          res = ecatAsyncSDODownload(deviceIndex,
            1003,
            (unsigned short)*indexInputPtr,
            (unsigned char)*subIndexInputPtr,
            (void *)sigInputPtr,
            1*4,
            500,
            342973403,
            sigStatusPtr,
            *enInputPtr);
        } else {
          *sigStatusPtr = 0;
        }

        gbyk_v4b_DW.BKINEtherCATAsyncSDODownload_IWORK_o[7] = 1;
        ;
      }
    }
  }

  /* DataTypeConversion: '<S160>/Data Type Conversion1' */
  gbyk_v4b_B.DataTypeConversion1_k = gbyk_v4b_B.BKINEtherCATAsyncSDODownload_c;

  /* MATLAB Function: '<S154>/fault monitor1' */
  gbyk_v4b_faultmonitor1(gbyk_v4b_B.sf_ReadEMCY_i.emcyValPump,
    gbyk_v4b_B.sf_parsestatusregister1_f.ampStatus,
    gbyk_v4b_B.sf_parsestatusregister1_f.currentLimitEnabled,
    gbyk_v4b_B.statusregister_i, gbyk_v4b_B.driveID_n,
    gbyk_v4b_B.DataTypeConversion_bd, &gbyk_v4b_B.sf_faultmonitor1_c,
    &gbyk_v4b_DW.sf_faultmonitor1_c);
}

/* Update for atomic system: '<S137>/EMCY Message pump' */
void gbyk_v4b_EMCYMessagepump_n_Update(void)
{
  /* Update for Memory: '<S158>/Memory' */
  gbyk_v4b_DW.Memory_PreviousInput_cn[0] = gbyk_v4b_B.RateTransition_l[0];
  gbyk_v4b_DW.Memory_PreviousInput_cn[1] = gbyk_v4b_B.RateTransition_l[1];

  /* Update for Memory: '<S159>/Memory' */
  gbyk_v4b_DW.Memory_PreviousInput_dg[0] = gbyk_v4b_B.RateTransition_k4[0];
  gbyk_v4b_DW.Memory_PreviousInput_dg[1] = gbyk_v4b_B.RateTransition_k4[1];

  /* Update for Memory: '<S160>/Memory' */
  gbyk_v4b_DW.Memory_PreviousInput_p = gbyk_v4b_B.DataTypeConversion1_k;
}

/* Termination for atomic system: '<S137>/EMCY Message pump' */
void gbyk_v4b_EMCYMessagepump_l_Term(void)
{
  /* Terminate for S-Function (BKINethercatasyncsdoupload): '<S158>/BKIN EtherCAT Async SDO Upload' */
  {
    int_T deviceIndex;
    if (!xpcIsModelInit()) {
      deviceIndex = gbyk_v4b_DW.BKINEtherCATAsyncSDOUpload_IWORK_n[0];
      if (deviceIndex != NO_ETHERCAT) {
        unregisterAsyncSDOUpload(342973381, deviceIndex);
        printf("SDO Upload. Unregister device %d, slave addr: %d\n", deviceIndex,
               1003);
      }
    }
  }

  /* Terminate for S-Function (BKINethercatasyncsdoupload): '<S159>/BKIN EtherCAT Async SDO Upload' */
  {
    int_T deviceIndex;
    if (!xpcIsModelInit()) {
      deviceIndex = gbyk_v4b_DW.BKINEtherCATAsyncSDOUpload_IWORK_i[0];
      if (deviceIndex != NO_ETHERCAT) {
        unregisterAsyncSDOUpload(342973393, deviceIndex);
        printf("SDO Upload. Unregister device %d, slave addr: %d\n", deviceIndex,
               1003);
      }
    }
  }

  /* Terminate for S-Function (BKINethercatasyncsdodownload): '<S160>/BKIN EtherCAT Async SDO Download' */
  {
    int_T deviceIndex;
    if (!xpcIsModelInit()) {
      deviceIndex = gbyk_v4b_DW.BKINEtherCATAsyncSDODownload_IWORK_o[0];
      if (deviceIndex != NO_ETHERCAT) {
        unregisterAsyncSDODownload(342973403, deviceIndex);
        printf("SDO Download. Unregister device %d, slave addr: %d\n",
               deviceIndex, 1003);
      }
    }
  }
}

/* Start for atomic system: '<S138>/A2M2 PDOs' */
void gbyk_v4b_A2M2PDOs_Start(void)
{
  /* Level2 S-Function Block: '<S164>/BKIN PDO Receive ElmoDrive' (BKINethercatpdorxElmoDrive) */
  {
    SimStruct *rts = gbyk_v4b_M->childSfunctions[15];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }
}

/* Output and update for atomic system: '<S138>/A2M2 PDOs' */
void gbyk_v4b_A2M2PDOs(void)
{
  /* Level2 S-Function Block: '<S164>/BKIN PDO Receive ElmoDrive' (BKINethercatpdorxElmoDrive) */
  {
    SimStruct *rts = gbyk_v4b_M->childSfunctions[15];
    sfcnOutputs(rts, 1);
  }

  /* DataTypeConversion: '<S164>/Data Type Conversion' */
  gbyk_v4b_B.DataTypeConversion_bv = gbyk_v4b_B.torque_k;

  /* DataTypeConversion: '<S164>/A2M2Convert' */
  gbyk_v4b_B.A2M2Convert[0] = gbyk_v4b_B.positionprimary;
  gbyk_v4b_B.A2M2Convert[1] = gbyk_v4b_B.positionsecondary;
  gbyk_v4b_B.A2M2Convert[2] = gbyk_v4b_B.velocityprimary;
  gbyk_v4b_B.A2M2Convert[3] = gbyk_v4b_B.DataTypeConversion_bv;
  gbyk_v4b_B.A2M2Convert[4] = gbyk_v4b_B.digitalinput;

  /* MATLAB Function: '<S164>/parse status register1' */
  gbyk_v4b_parsestatusregister(gbyk_v4b_B.statusregister,
    &gbyk_v4b_B.sf_parsestatusregister1_fq);
}

/* Termination for atomic system: '<S138>/A2M2 PDOs' */
void gbyk_v4b_A2M2PDOs_Term(void)
{
  /* Level2 S-Function Block: '<S164>/BKIN PDO Receive ElmoDrive' (BKINethercatpdorxElmoDrive) */
  {
    SimStruct *rts = gbyk_v4b_M->childSfunctions[15];
    sfcnTerminate(rts);
  }
}

/* Initial conditions for atomic system: '<S138>/EMCY Message pump' */
void gbyk_v4b_EMCYMessagepump_b_Init(void)
{
  /* InitializeConditions for MATLAB Function: '<S167>/fault monitor' */
  gbyk_v4b_faultmonitor_Init(&gbyk_v4b_DW.sf_faultmonitor_i);

  /* InitializeConditions for Memory: '<S171>/Memory' */
  gbyk_v4b_DW.Memory_PreviousInput_ml[0] = gbyk_v4b_P.Memory_X0_er;
  gbyk_v4b_DW.Memory_PreviousInput_ml[1] = gbyk_v4b_P.Memory_X0_er;

  /* InitializeConditions for Memory: '<S172>/Memory' */
  gbyk_v4b_DW.Memory_PreviousInput_de[0] = gbyk_v4b_P.Memory_X0_ic;
  gbyk_v4b_DW.Memory_PreviousInput_de[1] = gbyk_v4b_P.Memory_X0_ic;

  /* InitializeConditions for Memory: '<S173>/Memory' */
  gbyk_v4b_DW.Memory_PreviousInput_m = gbyk_v4b_P.Memory_X0_o;

  /* InitializeConditions for Chart: '<S167>/Read EMCY' */
  gbyk_v4b_ReadEMCY_Init(&gbyk_v4b_B.sf_ReadEMCY_p, &gbyk_v4b_DW.sf_ReadEMCY_p);

  /* InitializeConditions for MATLAB Function: '<S167>/fault monitor1' */
  gbyk_v4b_faultmonitor1_Init(&gbyk_v4b_DW.sf_faultmonitor1_h);
}

/* Start for atomic system: '<S138>/EMCY Message pump' */
void gbyk_v4b_EMCYMessagepump_j_Start(void)
{
  /* Start for Constant: '<S167>/driveID' */
  gbyk_v4b_B.driveID = gbyk_v4b_P.driveID_Value_p;
}

/* Outputs for atomic system: '<S138>/EMCY Message pump' */
void gbyk_v4b_EMCYMessagepump_i(void)
{
  /* DataTypeConversion: '<S167>/Data Type Conversion' */
  gbyk_v4b_B.DataTypeConversion_j = gbyk_v4b_B.statusword;

  /* MATLAB Function: '<S167>/fault monitor' */
  gbyk_v4b_faultmonitor(gbyk_v4b_B.statusword, &gbyk_v4b_B.sf_faultmonitor_i,
                        &gbyk_v4b_DW.sf_faultmonitor_i);

  /* Constant: '<S167>/driveID' */
  gbyk_v4b_B.driveID = gbyk_v4b_P.driveID_Value_p;

  /* Memory: '<S171>/Memory' */
  gbyk_v4b_B.Memory_kg[0] = gbyk_v4b_DW.Memory_PreviousInput_ml[0];
  gbyk_v4b_B.Memory_kg[1] = gbyk_v4b_DW.Memory_PreviousInput_ml[1];

  /* DataTypeConversion: '<S171>/Data Type Conversion2' */
  gbyk_v4b_B.DataTypeConversion2_g[0] = gbyk_v4b_B.Memory_kg[0];
  gbyk_v4b_B.DataTypeConversion2_g[1] = gbyk_v4b_B.Memory_kg[1];

  /* Memory: '<S172>/Memory' */
  gbyk_v4b_B.Memory_f3[0] = gbyk_v4b_DW.Memory_PreviousInput_de[0];
  gbyk_v4b_B.Memory_f3[1] = gbyk_v4b_DW.Memory_PreviousInput_de[1];

  /* DataTypeConversion: '<S172>/Data Type Conversion' */
  gbyk_v4b_B.DataTypeConversion_i1[0] = gbyk_v4b_B.Memory_f3[0];
  gbyk_v4b_B.DataTypeConversion_i1[1] = gbyk_v4b_B.Memory_f3[1];

  /* Memory: '<S173>/Memory' */
  gbyk_v4b_B.Memory_l = gbyk_v4b_DW.Memory_PreviousInput_m;

  /* Chart: '<S167>/Read EMCY' */
  gbyk_v4b_ReadEMCY(gbyk_v4b_B.sf_faultmonitor_i.triggerFaultRead,
                    gbyk_v4b_B.driveID, gbyk_v4b_B.DataTypeConversion2_g,
                    gbyk_v4b_B.DataTypeConversion_i1, gbyk_v4b_B.Memory_l,
                    &gbyk_v4b_B.sf_ReadEMCY_p, &gbyk_v4b_DW.sf_ReadEMCY_p);

  /* DataTypeConversion: '<S171>/Data Type Conversion' */
  gbyk_v4b_B.DataTypeConversion_dc = gbyk_v4b_B.sf_ReadEMCY_p.triggerCountRead;

  /* S-Function (BKINethercatasyncsdoupload): '<S171>/BKIN EtherCAT Async SDO Upload' */
  {
    int8_T *sigOutputPtr;
    int32_T *sigStatusPtr;
    int32_T *enInputPtr;
    int_T deviceIndex;
    static int counter= 0;
    int_T actLen;
    int_T res;
    int_T state;
    int32_T *indexInputPtr;
    int32_T *subIndexInputPtr;
    deviceIndex = gbyk_v4b_DW.BKINEtherCATAsyncSDOUpload_IWORK_d[0];
    if (deviceIndex != NO_ETHERCAT) {
      state = xpcEtherCATgetState( deviceIndex );
      if (state >= 2 ) {
        sigOutputPtr = &gbyk_v4b_B.BKINEtherCATAsyncSDOUpload_o1_m;
        sigStatusPtr = &gbyk_v4b_B.BKINEtherCATAsyncSDOUpload_o2_i;
        enInputPtr = &gbyk_v4b_B.DataTypeConversion_dc;
        indexInputPtr = &gbyk_v4b_P.Constant_Value_ik;
        subIndexInputPtr = &gbyk_v4b_P.Constant1_Value_j;
        if (gbyk_v4b_DW.BKINEtherCATAsyncSDOUpload_IWORK_d[7] != 0) {
          res = ecatAsyncSDOUpload(deviceIndex,
            1004,
            (unsigned short)*indexInputPtr,
            (unsigned char)*subIndexInputPtr,
            (void *)sigOutputPtr,
            1*4,
            &actLen,
            500,
            342973419,
            sigStatusPtr,
            *enInputPtr);
        }

        gbyk_v4b_DW.BKINEtherCATAsyncSDOUpload_IWORK_d[7] = 1;
        ;
      }
    }
  }

  /* DataTypeConversion: '<S171>/Data Type Conversion1' */
  gbyk_v4b_B.DataTypeConversion1_of = (uint32_T)
    gbyk_v4b_B.BKINEtherCATAsyncSDOUpload_o2_i;

  /* RateTransition: '<S171>/Rate Transition' */
  gbyk_v4b_B.RateTransition_gy[0] = gbyk_v4b_B.BKINEtherCATAsyncSDOUpload_o1_m;
  gbyk_v4b_B.RateTransition_gy[1] = gbyk_v4b_B.DataTypeConversion1_of;

  /* S-Function (BKINethercatasyncsdoupload): '<S172>/BKIN EtherCAT Async SDO Upload' */
  {
    int8_T *sigOutputPtr;
    int32_T *sigStatusPtr;
    int32_T *enInputPtr;
    int_T deviceIndex;
    static int counter= 0;
    int_T actLen;
    int_T res;
    int_T state;
    int32_T *indexInputPtr;
    int32_T *subIndexInputPtr;
    deviceIndex = gbyk_v4b_DW.BKINEtherCATAsyncSDOUpload_IWORK_p[0];
    if (deviceIndex != NO_ETHERCAT) {
      state = xpcEtherCATgetState( deviceIndex );
      if (state >= 2 ) {
        sigOutputPtr = &gbyk_v4b_B.BKINEtherCATAsyncSDOUpload_o1_f;
        sigStatusPtr = &gbyk_v4b_B.BKINEtherCATAsyncSDOUpload_o2_j;
        enInputPtr = &gbyk_v4b_B.sf_ReadEMCY_p.emcyReadTrigger[0];
        indexInputPtr = &gbyk_v4b_P.Constant_Value_ly;
        subIndexInputPtr = &gbyk_v4b_B.sf_ReadEMCY_p.emcyReadTrigger[1];
        if (gbyk_v4b_DW.BKINEtherCATAsyncSDOUpload_IWORK_p[7] != 0) {
          res = ecatAsyncSDOUpload(deviceIndex,
            1004,
            (unsigned short)*indexInputPtr,
            (unsigned char)*subIndexInputPtr,
            (void *)sigOutputPtr,
            1*4,
            &actLen,
            500,
            342973431,
            sigStatusPtr,
            *enInputPtr);
        }

        gbyk_v4b_DW.BKINEtherCATAsyncSDOUpload_IWORK_p[7] = 1;
        ;
      }
    }
  }

  /* RateTransition: '<S172>/Rate Transition' */
  gbyk_v4b_B.RateTransition_i[0] = gbyk_v4b_B.BKINEtherCATAsyncSDOUpload_o1_f;
  gbyk_v4b_B.RateTransition_i[1] = gbyk_v4b_B.BKINEtherCATAsyncSDOUpload_o2_j;

  /* DataTypeConversion: '<S173>/Data Type Conversion' incorporates:
   *  Constant: '<S173>/Constant'
   */
  gbyk_v4b_B.DataTypeConversion_dh = (int32_T)gbyk_v4b_P.Constant_Value_pq;

  /* S-Function (BKINethercatasyncsdodownload): '<S173>/BKIN EtherCAT Async SDO Download' */
  {
    int8_T *sigInputPtr;
    int32_T *sigStatusPtr;
    int32_T *enInputPtr;
    int_T deviceIndex;
    int_T res;
    int_T state;
    int32_T *indexInputPtr;
    int32_T *subIndexInputPtr;
    deviceIndex = gbyk_v4b_DW.BKINEtherCATAsyncSDODownload_IWORK_a[0];
    if (deviceIndex != NO_ETHERCAT) {
      state = xpcEtherCATgetState( deviceIndex );
      if (state >= 2 ) {
        sigStatusPtr = &gbyk_v4b_B.BKINEtherCATAsyncSDODownload_gy;
        sigInputPtr = &gbyk_v4b_P.Constant_Value_pq;
        enInputPtr = &gbyk_v4b_B.sf_ReadEMCY_p.countOverwriteTrigger;
        indexInputPtr = &gbyk_v4b_P.Constant1_Value_ol;
        subIndexInputPtr = &gbyk_v4b_B.DataTypeConversion_dh;
        if (gbyk_v4b_DW.BKINEtherCATAsyncSDODownload_IWORK_a[7] != 0) {
          res = ecatAsyncSDODownload(deviceIndex,
            1004,
            (unsigned short)*indexInputPtr,
            (unsigned char)*subIndexInputPtr,
            (void *)sigInputPtr,
            1*4,
            500,
            342973441,
            sigStatusPtr,
            *enInputPtr);
        } else {
          *sigStatusPtr = 0;
        }

        gbyk_v4b_DW.BKINEtherCATAsyncSDODownload_IWORK_a[7] = 1;
        ;
      }
    }
  }

  /* DataTypeConversion: '<S173>/Data Type Conversion1' */
  gbyk_v4b_B.DataTypeConversion1_c = gbyk_v4b_B.BKINEtherCATAsyncSDODownload_gy;

  /* MATLAB Function: '<S167>/fault monitor1' */
  gbyk_v4b_faultmonitor1(gbyk_v4b_B.sf_ReadEMCY_p.emcyValPump,
    gbyk_v4b_B.sf_parsestatusregister1_fq.ampStatus,
    gbyk_v4b_B.sf_parsestatusregister1_fq.currentLimitEnabled,
    gbyk_v4b_B.statusregister, gbyk_v4b_B.driveID,
    gbyk_v4b_B.DataTypeConversion_j, &gbyk_v4b_B.sf_faultmonitor1_h,
    &gbyk_v4b_DW.sf_faultmonitor1_h);
}

/* Update for atomic system: '<S138>/EMCY Message pump' */
void gbyk_v4b_EMCYMessagepump_o_Update(void)
{
  /* Update for Memory: '<S171>/Memory' */
  gbyk_v4b_DW.Memory_PreviousInput_ml[0] = gbyk_v4b_B.RateTransition_gy[0];
  gbyk_v4b_DW.Memory_PreviousInput_ml[1] = gbyk_v4b_B.RateTransition_gy[1];

  /* Update for Memory: '<S172>/Memory' */
  gbyk_v4b_DW.Memory_PreviousInput_de[0] = gbyk_v4b_B.RateTransition_i[0];
  gbyk_v4b_DW.Memory_PreviousInput_de[1] = gbyk_v4b_B.RateTransition_i[1];

  /* Update for Memory: '<S173>/Memory' */
  gbyk_v4b_DW.Memory_PreviousInput_m = gbyk_v4b_B.DataTypeConversion1_c;
}

/* Termination for atomic system: '<S138>/EMCY Message pump' */
void gbyk_v4b_EMCYMessagepump_i_Term(void)
{
  /* Terminate for S-Function (BKINethercatasyncsdoupload): '<S171>/BKIN EtherCAT Async SDO Upload' */
  {
    int_T deviceIndex;
    if (!xpcIsModelInit()) {
      deviceIndex = gbyk_v4b_DW.BKINEtherCATAsyncSDOUpload_IWORK_d[0];
      if (deviceIndex != NO_ETHERCAT) {
        unregisterAsyncSDOUpload(342973419, deviceIndex);
        printf("SDO Upload. Unregister device %d, slave addr: %d\n", deviceIndex,
               1004);
      }
    }
  }

  /* Terminate for S-Function (BKINethercatasyncsdoupload): '<S172>/BKIN EtherCAT Async SDO Upload' */
  {
    int_T deviceIndex;
    if (!xpcIsModelInit()) {
      deviceIndex = gbyk_v4b_DW.BKINEtherCATAsyncSDOUpload_IWORK_p[0];
      if (deviceIndex != NO_ETHERCAT) {
        unregisterAsyncSDOUpload(342973431, deviceIndex);
        printf("SDO Upload. Unregister device %d, slave addr: %d\n", deviceIndex,
               1004);
      }
    }
  }

  /* Terminate for S-Function (BKINethercatasyncsdodownload): '<S173>/BKIN EtherCAT Async SDO Download' */
  {
    int_T deviceIndex;
    if (!xpcIsModelInit()) {
      deviceIndex = gbyk_v4b_DW.BKINEtherCATAsyncSDODownload_IWORK_a[0];
      if (deviceIndex != NO_ETHERCAT) {
        unregisterAsyncSDODownload(342973441, deviceIndex);
        printf("SDO Download. Unregister device %d, slave addr: %d\n",
               deviceIndex, 1004);
      }
    }
  }
}

/* Output and update for atomic system: '<S143>/Read Drive 3 SDO' */
void gbyk_v4b_ReadDrive3SDO(void)
{
  /* S-Function (BKINethercatasyncsdoupload): '<S181>/BKIN EtherCAT Async SDO Upload1' */
  {
    int8_T *sigOutputPtr;
    int32_T *sigStatusPtr;
    int32_T *enInputPtr;
    int_T deviceIndex;
    static int counter= 0;
    int_T actLen;
    int_T res;
    int_T state;
    int32_T *indexInputPtr;
    int32_T *subIndexInputPtr;
    deviceIndex = gbyk_v4b_DW.BKINEtherCATAsyncSDOUpload1_IWORK_h[0];
    if (deviceIndex != NO_ETHERCAT) {
      state = xpcEtherCATgetState( deviceIndex );
      if (state >= 2 ) {
        sigOutputPtr = &gbyk_v4b_B.BKINEtherCATAsyncSDOUpload1_o1_f;
        sigStatusPtr = &gbyk_v4b_B.BKINEtherCATAsyncSDOUpload1_o2_a;
        enInputPtr = &gbyk_v4b_B.sf_SDOreadmachine_g.enable;
        indexInputPtr = &gbyk_v4b_B.DataTypeConversion2_m;
        subIndexInputPtr = &gbyk_v4b_B.DataTypeConversion1_k2;
        if (gbyk_v4b_DW.BKINEtherCATAsyncSDOUpload1_IWORK_h[7] != 0) {
          res = ecatAsyncSDOUpload(deviceIndex,
            1003,
            (unsigned short)*indexInputPtr,
            (unsigned char)*subIndexInputPtr,
            (void *)sigOutputPtr,
            1*4,
            &actLen,
            500,
            35471299,
            sigStatusPtr,
            *enInputPtr);
        }

        gbyk_v4b_DW.BKINEtherCATAsyncSDOUpload1_IWORK_h[7] = 1;
        ;
      }
    }
  }

  /* DataTypeConversion: '<S181>/Data Type Conversion' */
  gbyk_v4b_B.DataTypeConversion_d = gbyk_v4b_B.BKINEtherCATAsyncSDOUpload1_o2_a;

  /* MATLAB Function: '<S181>/converter' */
  gbyk_v4b_converter(gbyk_v4b_B.BKINEtherCATAsyncSDOUpload1_o1_f,
                     &gbyk_v4b_B.sf_converter_j);
}

/* Termination for atomic system: '<S143>/Read Drive 3 SDO' */
void gbyk_v4b_ReadDrive3SDO_Term(void)
{
  /* Terminate for S-Function (BKINethercatasyncsdoupload): '<S181>/BKIN EtherCAT Async SDO Upload1' */
  {
    int_T deviceIndex;
    if (!xpcIsModelInit()) {
      deviceIndex = gbyk_v4b_DW.BKINEtherCATAsyncSDOUpload1_IWORK_h[0];
      if (deviceIndex != NO_ETHERCAT) {
        unregisterAsyncSDOUpload(35471299, deviceIndex);
        printf("SDO Upload. Unregister device %d, slave addr: %d\n", deviceIndex,
               1003);
      }
    }
  }
}

/* Initial conditions for atomic system: '<S76>/SDO reading' */
void gbyk_v4b_SDOreading_k_Init(void)
{
  /* InitializeConditions for Memory: '<S143>/Memory' */
  gbyk_v4b_DW.Memory_PreviousInput_f = gbyk_v4b_P.Memory_X0_i;

  /* InitializeConditions for Chart: '<S143>/SDO read machine' */
  gbyk_v4b_SDOreadmachine_p_Init(&gbyk_v4b_B.sf_SDOreadmachine_g,
    &gbyk_v4b_DW.sf_SDOreadmachine_g);
}

/* Start for atomic system: '<S76>/SDO reading' */
void gbyk_v4b_SDOreading_m_Start(void)
{
  /* Start for Constant: '<S143>/readAddr' */
  gbyk_v4b_B.readAddr[0] = gbyk_v4b_P.readAddr_Value_b[0];
  gbyk_v4b_B.readAddr[1] = gbyk_v4b_P.readAddr_Value_b[1];
  gbyk_v4b_B.readAddr[2] = gbyk_v4b_P.readAddr_Value_b[2];
}

/* Outputs for atomic system: '<S76>/SDO reading' */
void gbyk_v4b_SDOreading_n(void)
{
  real_T tmp;

  /* Constant: '<S143>/readAddr' */
  gbyk_v4b_B.readAddr[0] = gbyk_v4b_P.readAddr_Value_b[0];
  gbyk_v4b_B.readAddr[1] = gbyk_v4b_P.readAddr_Value_b[1];
  gbyk_v4b_B.readAddr[2] = gbyk_v4b_P.readAddr_Value_b[2];

  /* DataTypeConversion: '<S143>/Data Type Conversion1' */
  tmp = floor(gbyk_v4b_B.readAddr[2]);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 4.294967296E+9);
  }

  gbyk_v4b_B.DataTypeConversion1_k2 = tmp < 0.0 ? -(int32_T)(uint32_T)-tmp :
    (int32_T)(uint32_T)tmp;

  /* End of DataTypeConversion: '<S143>/Data Type Conversion1' */

  /* DataTypeConversion: '<S143>/Data Type Conversion2' */
  tmp = floor(gbyk_v4b_B.readAddr[1]);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 4.294967296E+9);
  }

  gbyk_v4b_B.DataTypeConversion2_m = tmp < 0.0 ? -(int32_T)(uint32_T)-tmp :
    (int32_T)(uint32_T)tmp;

  /* End of DataTypeConversion: '<S143>/Data Type Conversion2' */

  /* Memory: '<S143>/Memory' */
  gbyk_v4b_B.Memory_ip = gbyk_v4b_DW.Memory_PreviousInput_f;

  /* Chart: '<S143>/SDO read machine' */
  gbyk_v4b_SDOreadmachine_p(gbyk_v4b_B.readAddr[0], gbyk_v4b_B.Memory_ip,
    &gbyk_v4b_B.sf_SDOreadmachine_g, &gbyk_v4b_DW.sf_SDOreadmachine_g);

  /* Outputs for Atomic SubSystem: '<S143>/Read Drive 3 SDO' */
  gbyk_v4b_ReadDrive3SDO();

  /* End of Outputs for SubSystem: '<S143>/Read Drive 3 SDO' */

  /* DataTypeConversion: '<S143>/convert' */
  gbyk_v4b_B.convert_l = gbyk_v4b_B.sf_converter_j.uint32Out;

  /* DataTypeConversion: '<S143>/convert1' */
  gbyk_v4b_B.convert1 = gbyk_v4b_B.sf_converter_j.int32Out;

  /* DataTypeConversion: '<S143>/status' */
  gbyk_v4b_B.status_e = gbyk_v4b_B.sf_SDOreadmachine_g.complete;

  /* MATLAB Function: '<S143>/values' */
  gbyk_v4b_values(gbyk_v4b_B.convert_l, gbyk_v4b_B.convert1,
                  gbyk_v4b_B.sf_converter_j.doubleOut, &gbyk_v4b_B.sf_values_n);
}

/* Update for atomic system: '<S76>/SDO reading' */
void gbyk_v4b_SDOreading_a_Update(void)
{
  /* Update for Memory: '<S143>/Memory' */
  gbyk_v4b_DW.Memory_PreviousInput_f = gbyk_v4b_B.DataTypeConversion_d;
}

/* Termination for atomic system: '<S76>/SDO reading' */
void gbyk_v4b_SDOreading_h_Term(void)
{
  /* Terminate for Atomic SubSystem: '<S143>/Read Drive 3 SDO' */
  gbyk_v4b_ReadDrive3SDO_Term();

  /* End of Terminate for SubSystem: '<S143>/Read Drive 3 SDO' */
}

/* Initial conditions for atomic system: '<S76>/SDO writing' */
void gbyk_v4b_SDOwriting_m_Init(void)
{
  /* InitializeConditions for Memory: '<S144>/Memory' */
  gbyk_v4b_DW.Memory_PreviousInput_do = gbyk_v4b_P.Memory_X0_cr;

  /* InitializeConditions for Chart: '<S144>/SDO write machine' */
  gbyk_v4b_SDOwritemachine_Init(&gbyk_v4b_B.sf_SDOwritemachine_j,
    &gbyk_v4b_DW.sf_SDOwritemachine_j);
}

/* Start for atomic system: '<S76>/SDO writing' */
void gbyk_v4b_SDOwriting_e_Start(void)
{
  int32_T i;

  /* Start for Constant: '<S144>/writeData' */
  for (i = 0; i < 5; i++) {
    gbyk_v4b_B.writeData[i] = gbyk_v4b_P.writeData_Value_f[i];
  }

  /* End of Start for Constant: '<S144>/writeData' */
}

/* Outputs for atomic system: '<S76>/SDO writing' */
void gbyk_v4b_SDOwriting_f(void)
{
  int32_T i;
  real_T tmp;

  /* Constant: '<S144>/writeData' */
  for (i = 0; i < 5; i++) {
    gbyk_v4b_B.writeData[i] = gbyk_v4b_P.writeData_Value_f[i];
  }

  /* End of Constant: '<S144>/writeData' */

  /* MATLAB Function: '<S144>/convert' */
  gbyk_v4b_convert(gbyk_v4b_B.writeData[1], gbyk_v4b_B.writeData[2],
                   &gbyk_v4b_B.sf_convert_i);

  /* Memory: '<S144>/Memory' */
  gbyk_v4b_B.Memory_lf = gbyk_v4b_DW.Memory_PreviousInput_do;

  /* Chart: '<S144>/SDO write machine' */
  gbyk_v4b_SDOwritemachine(gbyk_v4b_B.writeData[0], gbyk_v4b_B.Memory_lf,
    &gbyk_v4b_B.sf_SDOwritemachine_j, &gbyk_v4b_DW.sf_SDOwritemachine_j);

  /* DataTypeConversion: '<S144>/Data Type Conversion2' */
  tmp = floor(gbyk_v4b_B.writeData[3]);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 4.294967296E+9);
  }

  gbyk_v4b_B.DataTypeConversion2_p = tmp < 0.0 ? -(int32_T)(uint32_T)-tmp :
    (int32_T)(uint32_T)tmp;

  /* End of DataTypeConversion: '<S144>/Data Type Conversion2' */

  /* DataTypeConversion: '<S144>/Data Type Conversion1' */
  tmp = floor(gbyk_v4b_B.writeData[4]);
  if (rtIsNaN(tmp) || rtIsInf(tmp)) {
    tmp = 0.0;
  } else {
    tmp = fmod(tmp, 4.294967296E+9);
  }

  gbyk_v4b_B.DataTypeConversion1_aq = tmp < 0.0 ? -(int32_T)(uint32_T)-tmp :
    (int32_T)(uint32_T)tmp;

  /* End of DataTypeConversion: '<S144>/Data Type Conversion1' */

  /* S-Function (BKINethercatasyncsdodownload): '<S144>/BKIN EtherCAT Async SDO Download' */
  {
    int8_T *sigInputPtr;
    int32_T *sigStatusPtr;
    int32_T *enInputPtr;
    int_T deviceIndex;
    int_T res;
    int_T state;
    int32_T *indexInputPtr;
    int32_T *subIndexInputPtr;
    deviceIndex = gbyk_v4b_DW.BKINEtherCATAsyncSDODownload_IWORK[0];
    if (deviceIndex != NO_ETHERCAT) {
      state = xpcEtherCATgetState( deviceIndex );
      if (state >= 2 ) {
        sigStatusPtr = &gbyk_v4b_B.BKINEtherCATAsyncSDODownload;
        sigInputPtr = &gbyk_v4b_B.sf_convert_i.y;
        enInputPtr = &gbyk_v4b_B.sf_SDOwritemachine_j.enable;
        indexInputPtr = &gbyk_v4b_B.DataTypeConversion2_p;
        subIndexInputPtr = &gbyk_v4b_B.DataTypeConversion1_aq;
        if (gbyk_v4b_DW.BKINEtherCATAsyncSDODownload_IWORK[7] != 0) {
          res = ecatAsyncSDODownload(deviceIndex,
            1003,
            (unsigned short)*indexInputPtr,
            (unsigned char)*subIndexInputPtr,
            (void *)sigInputPtr,
            1*4,
            500,
            342973537,
            sigStatusPtr,
            *enInputPtr);
        } else {
          *sigStatusPtr = 0;
        }

        gbyk_v4b_DW.BKINEtherCATAsyncSDODownload_IWORK[7] = 1;
        ;
      }
    }
  }

  /* DataTypeConversion: '<S144>/status' */
  gbyk_v4b_B.status = gbyk_v4b_B.sf_SDOwritemachine_j.complete;
}

/* Update for atomic system: '<S76>/SDO writing' */
void gbyk_v4b_SDOwriting_f_Update(void)
{
  /* Update for Memory: '<S144>/Memory' */
  gbyk_v4b_DW.Memory_PreviousInput_do = gbyk_v4b_B.BKINEtherCATAsyncSDODownload;
}

/* Termination for atomic system: '<S76>/SDO writing' */
void gbyk_v4b_SDOwriting_k_Term(void)
{
  /* Terminate for S-Function (BKINethercatasyncsdodownload): '<S144>/BKIN EtherCAT Async SDO Download' */
  {
    int_T deviceIndex;
    if (!xpcIsModelInit()) {
      deviceIndex = gbyk_v4b_DW.BKINEtherCATAsyncSDODownload_IWORK[0];
      if (deviceIndex != NO_ETHERCAT) {
        unregisterAsyncSDODownload(342973537, deviceIndex);
        printf("SDO Download. Unregister device %d, slave addr: %d\n",
               deviceIndex, 1003);
      }
    }
  }
}

/* Output and update for atomic system: '<S146>/Read Drive 3 SDO' */
void gbyk_v4b_ReadDrive3SDO_g(void)
{
  /* S-Function (BKINethercatasyncsdoupload): '<S187>/BKIN EtherCAT Async SDO Upload1' */
  {
    int8_T *sigOutputPtr;
    int32_T *sigStatusPtr;
    int32_T *enInputPtr;
    int_T deviceIndex;
    static int counter= 0;
    int_T actLen;
    int_T res;
    int_T state;
    int32_T *indexInputPtr;
    int32_T *subIndexInputPtr;
    deviceIndex = gbyk_v4b_DW.BKINEtherCATAsyncSDOUpload1_IWORK[0];
    if (deviceIndex != NO_ETHERCAT) {
      state = xpcEtherCATgetState( deviceIndex );
      if (state >= 2 ) {
        sigOutputPtr = &gbyk_v4b_B.BKINEtherCATAsyncSDOUpload1_o1;
        sigStatusPtr = &gbyk_v4b_B.BKINEtherCATAsyncSDOUpload1_o2;
        enInputPtr = &gbyk_v4b_B.sf_SDOreadmachine_h.SDOCommand[0];
        indexInputPtr = &gbyk_v4b_B.sf_SDOreadmachine_h.SDOCommand[1];
        subIndexInputPtr = &gbyk_v4b_B.sf_SDOreadmachine_h.SDOCommand[2];
        if (gbyk_v4b_DW.BKINEtherCATAsyncSDOUpload1_IWORK[7] != 0) {
          res = ecatAsyncSDOUpload(deviceIndex,
            1003,
            (unsigned short)*indexInputPtr,
            (unsigned char)*subIndexInputPtr,
            (void *)sigOutputPtr,
            1*4,
            &actLen,
            500,
            35091299,
            sigStatusPtr,
            *enInputPtr);
        }

        gbyk_v4b_DW.BKINEtherCATAsyncSDOUpload1_IWORK[7] = 1;
        ;
      }
    }
  }

  /* DataTypeConversion: '<S187>/Data Type Conversion' */
  gbyk_v4b_B.DataTypeConversion_iq = gbyk_v4b_B.BKINEtherCATAsyncSDOUpload1_o2;

  /* MATLAB Function: '<S187>/converter' */
  gbyk_v4b_converter(gbyk_v4b_B.BKINEtherCATAsyncSDOUpload1_o1,
                     &gbyk_v4b_B.sf_converter_jl);
}

/* Termination for atomic system: '<S146>/Read Drive 3 SDO' */
void gbyk_v4b_ReadDrive3SDO_a_Term(void)
{
  /* Terminate for S-Function (BKINethercatasyncsdoupload): '<S187>/BKIN EtherCAT Async SDO Upload1' */
  {
    int_T deviceIndex;
    if (!xpcIsModelInit()) {
      deviceIndex = gbyk_v4b_DW.BKINEtherCATAsyncSDOUpload1_IWORK[0];
      if (deviceIndex != NO_ETHERCAT) {
        unregisterAsyncSDOUpload(35091299, deviceIndex);
        printf("SDO Upload. Unregister device %d, slave addr: %d\n", deviceIndex,
               1003);
      }
    }
  }
}

/*
 * Output and update for atomic system:
 *    '<S230>/decode robot'
 *    '<S231>/decode robot'
 */
void gbyk_v4b_decoderobot(real_T rtu_system_type, real_T rtu_robot_type, real_T
  rtu_robot_version, B_decoderobot_gbyk_v4b_T *localB)
{
  /* MATLAB Function 'DataLogging/Poll KINARM/constants/arm1/decode robot': '<S233>:1' */
  /* '<S233>:1:3' */
  localB->isEP = 0.0;

  /* '<S233>:1:4' */
  localB->isHumanEXO = 0.0;

  /* '<S233>:1:5' */
  localB->isNHPEXO = 0.0;

  /* '<S233>:1:6' */
  localB->isClassicExo = 0.0;

  /* '<S233>:1:7' */
  localB->isUTSEXO = 0.0;

  /* '<S233>:1:8' */
  localB->isPMAC = 0.0;

  /* '<S233>:1:9' */
  localB->isECAT = 0.0;
  if (rtu_robot_type == 0.0) {
    /* '<S233>:1:11' */
    /* '<S233>:1:12' */
    localB->isHumanEXO = 1.0;
    if (rtu_robot_version == 1.0) {
      /* '<S233>:1:13' */
      /* '<S233>:1:14' */
      localB->isClassicExo = 1.0;
    } else {
      if (rtu_robot_version == 2.0) {
        /* '<S233>:1:15' */
        /* '<S233>:1:16' */
        localB->isUTSEXO = 1.0;
      }
    }
  } else if (rtu_robot_type == 1.0) {
    /* '<S233>:1:18' */
    /* '<S233>:1:19' */
    localB->isEP = 1.0;
  } else {
    if (rtu_robot_type == 2.0) {
      /* '<S233>:1:20' */
      /* '<S233>:1:21' */
      localB->isNHPEXO = 1.0;
      if (rtu_robot_version == 1.0) {
        /* '<S233>:1:22' */
        /* '<S233>:1:23' */
        localB->isClassicExo = 1.0;
      } else {
        if (rtu_robot_version == 2.0) {
          /* '<S233>:1:24' */
          /* '<S233>:1:25' */
          localB->isUTSEXO = 1.0;
        }
      }
    }
  }

  if (rtu_system_type == 1.0) {
    /* '<S233>:1:29' */
    /* '<S233>:1:30' */
    localB->isPMAC = 1.0;
  } else {
    if (rtu_system_type == 2.0) {
      /* '<S233>:1:31' */
      /* '<S233>:1:32' */
      localB->isECAT = 1.0;
    }
  }
}

/*
 * Output and update for atomic system:
 *    '<S74>/split_primary'
 *    '<S74>/split_primary1'
 */
void gbyk_v4b_split_primary(const real_T rtu_primary_data[6],
  B_split_primary_gbyk_v4b_T *localB)
{
  /* MATLAB Function 'DataLogging/Poll KINARM/split_primary/split_primary': '<S245>:1' */
  /* '<S245>:1:2' */
  localB->link_angles[0] = rtu_primary_data[0];
  localB->link_angles[1] = rtu_primary_data[1];

  /* '<S245>:1:3' */
  localB->link_velocities[0] = rtu_primary_data[2];
  localB->link_velocities[1] = rtu_primary_data[3];

  /* '<S245>:1:4' */
  localB->link_acceleration[0] = rtu_primary_data[4];
  localB->link_acceleration[1] = rtu_primary_data[5];
}

/* Function for MATLAB Function: '<S64>/latch_errors' */
static void gbyk_v4b_circshift_j(real_T a[12])
{
  int32_T k;
  real_T buffer_idx_0;
  real_T buffer_idx_1;
  buffer_idx_0 = a[10];
  buffer_idx_1 = a[11];
  for (k = 9; k >= 0; k += -1) {
    a[k + 2] = a[k];
  }

  a[0] = buffer_idx_0;
  a[1] = buffer_idx_1;
}

/* Function for MATLAB Function: '<S84>/create kinematics' */
static void gbyk_v4b_convertL1L2ToShoElb(const real_T L1L2[4], const real_T
  orientation[2], real_T shoElb[4])
{
  real_T L2;
  real_T L1;

  /* '<S195>:1:63' */
  shoElb[0] = L1L2[0];
  shoElb[2] = L1L2[2];

  /* '<S195>:1:64' */
  /* '<S195>:1:65' */
  /* '<S195>:1:66' */
  L2 = L1L2[1];

  /* '<S195>:1:67' */
  L1 = L1L2[0];
  if (orientation[0] == -1.0) {
    /* '<S195>:1:69' */
    /* '<S195>:1:70' */
    L2 = -L1L2[1] + 3.1415926535897931;

    /* '<S195>:1:71' */
    L1 = -L1L2[0] + 3.1415926535897931;

    /* '<S195>:1:72' */
    shoElb[0] = -L1L2[0] + 3.1415926535897931;
  }

  /* '<S195>:1:75' */
  shoElb[1] = L2 - L1;

  /* convert L2 to elbow */
  /* '<S195>:1:76' */
  /* '<S195>:1:65' */
  /* '<S195>:1:66' */
  L2 = L1L2[3];

  /* '<S195>:1:67' */
  L1 = L1L2[2];
  if (orientation[1] == -1.0) {
    /* '<S195>:1:69' */
    /* '<S195>:1:70' */
    L2 = -L1L2[3] + 3.1415926535897931;

    /* '<S195>:1:71' */
    L1 = -L1L2[2] + 3.1415926535897931;

    /* '<S195>:1:72' */
    shoElb[2] = -L1L2[2] + 3.1415926535897931;
  }

  /* '<S195>:1:75' */
  shoElb[3] = L2 - L1;

  /* convert L2 to elbow */
  /* '<S195>:1:76' */
  /* '<S195>:1:65' */
}

/* Function for MATLAB Function: '<S84>/create kinematics' */
static void gbyk_v4b_convertL1L2ToShoElbVel(const real_T L1L2[4], const real_T
  orientation[2], real_T shoElb[4])
{
  real_T L2;
  real_T L1;

  /* '<S195>:1:81' */
  shoElb[0] = L1L2[0];
  shoElb[2] = L1L2[2];

  /* '<S195>:1:82' */
  /* '<S195>:1:83' */
  /* '<S195>:1:84' */
  L2 = L1L2[1];

  /* '<S195>:1:85' */
  L1 = L1L2[0];
  if (orientation[0] == -1.0) {
    /* '<S195>:1:87' */
    /* '<S195>:1:88' */
    L2 = -L1L2[1];

    /* '<S195>:1:89' */
    L1 = -L1L2[0];

    /* '<S195>:1:90' */
    shoElb[0] = -L1L2[0];
  }

  /* '<S195>:1:93' */
  shoElb[1] = L2 - L1;

  /* convert L2 to elbow */
  /* '<S195>:1:94' */
  /* '<S195>:1:83' */
  /* '<S195>:1:84' */
  L2 = L1L2[3];

  /* '<S195>:1:85' */
  L1 = L1L2[2];
  if (orientation[1] == -1.0) {
    /* '<S195>:1:87' */
    /* '<S195>:1:88' */
    L2 = -L1L2[3];

    /* '<S195>:1:89' */
    L1 = -L1L2[2];

    /* '<S195>:1:90' */
    shoElb[2] = -L1L2[2];
  }

  /* '<S195>:1:93' */
  shoElb[3] = L2 - L1;

  /* convert L2 to elbow */
  /* '<S195>:1:94' */
  /* '<S195>:1:83' */
}

/* Function for MATLAB Function: '<S84>/create kinematics' */
static void gbyk_v4b_reduce(const int32_T a_sizes[2], int32_T absp[2], boolean_T
  shiftright[2])
{
  int32_T b;
  boolean_T c;
  b = 0;
  c = true;
  if (0 > a_sizes[0]) {
    b = 1;
  }

  if (b > (a_sizes[0] >> 1)) {
    b = a_sizes[0] - 1;
    c = false;
  }

  absp[0] = b;
  shiftright[0] = c;
  b = 1;
  c = true;
  if (1 > (a_sizes[1] >> 1)) {
    b = a_sizes[1] - 1;
    c = false;
  }

  absp[1] = b;
  shiftright[1] = c;
}

/* Function for MATLAB Function: '<S84>/create kinematics' */
static void gbyk_v4b_circshift_c(real_T a_data[], int32_T a_sizes[2])
{
  int32_T ns;
  int32_T pagesize;
  int32_T absp[2];
  boolean_T shiftright[2];
  int32_T c;
  int32_T mtmp;
  int32_T pageroot;
  int32_T i1;
  int32_T i;
  int32_T j;
  int32_T e_k;
  real_T buffer_data[50];
  int8_T npages_idx_0;
  if (a_sizes[1] != 0) {
    gbyk_v4b_reduce(a_sizes, absp, shiftright);
    npages_idx_0 = (int8_T)a_sizes[1];
    c = a_sizes[0];
    ns = absp[0];
    pagesize = a_sizes[0];
    if ((a_sizes[0] > 1) && (absp[0] > 0)) {
      for (i = 1; i <= npages_idx_0; i++) {
        pageroot = (i - 1) * pagesize;
        for (j = 0; j + 1 < 2; j++) {
          i1 = pageroot + j;
          if (shiftright[0]) {
            for (mtmp = 0; mtmp + 1 <= ns; mtmp++) {
              buffer_data[mtmp] = a_data[((i1 + mtmp) + c) - ns];
            }

            for (mtmp = c; mtmp >= ns + 1; mtmp--) {
              a_data[(i1 + mtmp) - 1] = a_data[((i1 + mtmp) - ns) - 1];
            }

            for (mtmp = 0; mtmp + 1 <= ns; mtmp++) {
              a_data[i1 + mtmp] = buffer_data[mtmp];
            }
          } else {
            for (mtmp = 0; mtmp + 1 <= ns; mtmp++) {
              buffer_data[mtmp] = a_data[i1 + mtmp];
            }

            mtmp = c - ns;
            for (e_k = 0; e_k + 1 <= mtmp; e_k++) {
              a_data[i1 + e_k] = a_data[(i1 + e_k) + ns];
            }

            for (mtmp = 0; mtmp + 1 <= ns; mtmp++) {
              a_data[((i1 + mtmp) + c) - ns] = buffer_data[mtmp];
            }
          }
        }
      }
    }

    c = a_sizes[1];
    ns = absp[1];
    if ((a_sizes[1] > 1) && (absp[1] > 0)) {
      i = 1;
      while (i <= 1) {
        for (j = 0; j + 1 <= pagesize; j++) {
          i1 = j;
          if (shiftright[1]) {
            for (mtmp = 0; mtmp + 1 <= ns; mtmp++) {
              buffer_data[mtmp] = a_data[((mtmp + c) - ns) * pagesize + i1];
            }

            for (mtmp = c; mtmp >= ns + 1; mtmp--) {
              a_data[i1 + (mtmp - 1) * pagesize] = a_data[((mtmp - ns) - 1) *
                pagesize + i1];
            }

            for (mtmp = 0; mtmp + 1 <= ns; mtmp++) {
              a_data[i1 + mtmp * pagesize] = buffer_data[mtmp];
            }
          } else {
            for (mtmp = 0; mtmp + 1 <= ns; mtmp++) {
              buffer_data[mtmp] = a_data[mtmp * pagesize + i1];
            }

            mtmp = c - ns;
            for (e_k = 0; e_k + 1 <= mtmp; e_k++) {
              a_data[i1 + e_k * pagesize] = a_data[(e_k + ns) * pagesize + i1];
            }

            for (mtmp = 0; mtmp + 1 <= ns; mtmp++) {
              a_data[i1 + ((mtmp + c) - ns) * pagesize] = buffer_data[mtmp];
            }
          }
        }

        i = 2;
      }
    }
  }
}

/* Function for MATLAB Function: '<S84>/create kinematics' */
static void gbyk_v4b_updateQueue(const real_T arr_data[], const int32_T
  arr_sizes[2], const real_T newVals[4], real_T encData_data[], int32_T
  encData_sizes[2])
{
  int32_T i;
  int32_T loop_ub;

  /* '<S195>:1:58' */
  encData_sizes[0] = 4;
  encData_sizes[1] = arr_sizes[1];
  loop_ub = arr_sizes[0] * arr_sizes[1];
  for (i = 0; i < loop_ub; i++) {
    encData_data[i] = arr_data[i];
  }

  gbyk_v4b_circshift_c(encData_data, encData_sizes);

  /* '<S195>:1:59' */
  encData_data[0] = newVals[0];
  encData_data[1] = newVals[1];
  encData_data[2] = newVals[2];
  encData_data[3] = newVals[3];
}

/* Function for MATLAB Function: '<S84>/create kinematics' */
static void gbyk_v4b_calcDT(const real_T positions_data[], const int32_T
  positions_sizes[2], real_T stepTime, real_T velocity[4])
{
  real_T dt;
  int32_T positions;

  /* % Calculate the derrivative of the given signals. This will work with and  */
  /*  X, Y matrix of values. You will get out the X derrivaties, each */
  /*  calculated over Y times steps. */
  /* '<S195>:1:127' */
  dt = ((real_T)positions_sizes[1] - 1.0) * stepTime;

  /* '<S195>:1:128' */
  positions = positions_sizes[1];
  velocity[0] = (positions_data[0] - positions_data[(positions - 1) *
                 positions_sizes[0]]) / dt;
  velocity[1] = (positions_data[1] - positions_data[(positions - 1) *
                 positions_sizes[0] + 1]) / dt;
  velocity[2] = (positions_data[2] - positions_data[(positions - 1) *
                 positions_sizes[0] + 2]) / dt;
  velocity[3] = (positions_data[3] - positions_data[(positions - 1) *
                 positions_sizes[0] + 3]) / dt;
}

/* Function for MATLAB Function: '<S84>/create kinematics' */
static void gbyk_v4b_buildEncoderData(real_T queueSize, const real_T shoElb[4],
  real_T encData_data[], int32_T encData_sizes[2])
{
  real_T shoElb_0;
  real_T shoElb_1;
  real_T shoElb_2;
  real_T shoElb_3;
  int32_T i;
  int32_T tmp;
  int32_T tmp_0;
  int32_T tmp_1;
  int32_T tmp_2;

  /* '<S195>:1:52' */
  /* '<S195>:1:53' */
  tmp = (int32_T)queueSize;
  shoElb_0 = shoElb[0];
  tmp_0 = (int32_T)queueSize;
  shoElb_1 = shoElb[1];
  tmp_1 = (int32_T)queueSize;
  shoElb_2 = shoElb[2];
  tmp_2 = (int32_T)queueSize;
  shoElb_3 = shoElb[3];
  encData_sizes[0] = 4;
  encData_sizes[1] = tmp;
  for (i = 0; i < tmp; i++) {
    encData_data[i << 2] = shoElb_0;
  }

  for (i = 0; i < tmp_0; i++) {
    encData_data[1 + (i << 2)] = shoElb_1;
  }

  for (i = 0; i < tmp_1; i++) {
    encData_data[2 + (i << 2)] = shoElb_2;
  }

  for (i = 0; i < tmp_2; i++) {
    encData_data[3 + (i << 2)] = shoElb_3;
  }
}

/* Function for MATLAB Function: '<S84>/create kinematics' */
static void gbyk_v4b_buildEncoderData_j(real_T queueSize, real_T encData_data[],
  int32_T encData_sizes[2])
{
  int32_T i;
  int32_T tmp;
  int32_T tmp_0;
  int32_T tmp_1;
  int32_T tmp_2;

  /* '<S195>:1:52' */
  /* '<S195>:1:53' */
  tmp = (int32_T)queueSize;
  tmp_0 = (int32_T)queueSize;
  tmp_1 = (int32_T)queueSize;
  tmp_2 = (int32_T)queueSize;
  encData_sizes[0] = 4;
  encData_sizes[1] = tmp;
  for (i = 0; i < tmp; i++) {
    encData_data[i << 2] = 0.0;
  }

  for (i = 0; i < tmp_0; i++) {
    encData_data[1 + (i << 2)] = 0.0;
  }

  for (i = 0; i < tmp_1; i++) {
    encData_data[2 + (i << 2)] = 0.0;
  }

  for (i = 0; i < tmp_2; i++) {
    encData_data[3 + (i << 2)] = 0.0;
  }
}

/* Function for MATLAB Function: '<S84>/create kinematics' */
static void gbyk_v4b_buildKin(const real_T angles[2], const real_T
  velocities_data[], const int32_T velocities_sizes[2], real_T stepTime, const
  uint32_T motorStatuses[2], real_T kinOut[10])
{
  real_T dt;
  int32_T velocities;
  real_T kinOut_idx_1;

  /* % Build the KINData we need for secondary encoders */
  /* '<S195>:1:100' */
  /* '<S195>:1:102' */
  /* % We know that the shoulder and elbow should always be from -pi/2 to 3/2 pi, this method ensures  */
  /*  we always report in that range. */
  /*  NOTE: With appropriately chosen calibration values this is not required.  */
  /*  I have disabled this code because it can pose a danger if for some crazy */
  /*  reason we cross a threshold that makes us jump 2pi from the last measure */
  /*  this can accidentally create HUGE forces depending on the block being */
  /*  used. */
  /*      minVal = -pi/2; */
  /*      maxVal = 3/2 * pi; */
  /*       */
  /*      for n=1:2 */
  /*          while shoElb(n) < minVal */
  /*              shoElb(n) = shoElb(n) + (2 * pi); */
  /*          end */
  /*           */
  /*          while shoElb(n) > maxVal */
  /*              shoElb(n) = shoElb(n) - (2 * pi); */
  /*          end */
  /*      end */
  /* '<S195>:1:151' */
  kinOut[0] = angles[0];
  kinOut[1] = angles[1];

  /* sho, elb angle     */
  /* '<S195>:1:103' */
  kinOut[2] = velocities_data[0];
  kinOut[3] = velocities_data[1];

  /* sho, elb velocity */
  /* '<S195>:1:104' */
  /* % Calculate the derrivative of the given signals. This will work with and  */
  /*  X, Y matrix of values. You will get out the X derrivaties, each */
  /*  calculated over Y times steps. */
  /* '<S195>:1:127' */
  dt = ((real_T)velocities_sizes[1] - 1.0) * stepTime;

  /* '<S195>:1:128' */
  velocities = velocities_sizes[1];
  kinOut[4] = (velocities_data[0] - velocities_data[(velocities - 1) *
               velocities_sizes[0]]) / dt;
  kinOut[5] = (velocities_data[1] - velocities_data[(velocities - 1) *
               velocities_sizes[0] + 1]) / dt;

  /* accelerations, see DEX-2531 */
  /* '<S195>:1:105' */
  dt = kinOut[2];
  kinOut_idx_1 = kinOut[3];
  kinOut[6] = dt;
  kinOut[7] = kinOut_idx_1;

  /* filtered vel */
  /* '<S195>:1:106' */
  kinOut[8] = motorStatuses[0];
  kinOut[9] = motorStatuses[1];

  /* M1, M2 status */
}

/* Function for MATLAB Function: '<S84>/create kinematics' */
static void gbyk_v4b_buildKinPrimary(const real_T angles[2], const real_T
  velocities_data[], const int32_T velocities_sizes[2], real_T stepTime, const
  uint32_T motorStatuses[2], real_T filteredVelocities_data[], int32_T
  filteredVelocities_sizes[2], real_T kinOut[10])
{
  int32_T b;
  int32_T ix;
  int32_T iy;
  real_T s;
  int32_T ns;
  int32_T pagesize;
  boolean_T f;
  int32_T pageroot;
  int32_T i1;
  int32_T i;
  int32_T b_j;
  real_T buffer_data[50];
  int8_T npages_idx_0;
  real_T y_idx_0;
  int8_T absp_idx_0;
  boolean_T shiftright_idx_0;
  int8_T absp_idx_1;

  /* % Build the KINData we need from the primary encoder data. */
  /* '<S195>:1:111' */
  /* '<S195>:1:113' */
  /* % We know that the shoulder and elbow should always be from -pi/2 to 3/2 pi, this method ensures  */
  /*  we always report in that range. */
  /*  NOTE: With appropriately chosen calibration values this is not required.  */
  /*  I have disabled this code because it can pose a danger if for some crazy */
  /*  reason we cross a threshold that makes us jump 2pi from the last measure */
  /*  this can accidentally create HUGE forces depending on the block being */
  /*  used. */
  /*      minVal = -pi/2; */
  /*      maxVal = 3/2 * pi; */
  /*       */
  /*      for n=1:2 */
  /*          while shoElb(n) < minVal */
  /*              shoElb(n) = shoElb(n) + (2 * pi); */
  /*          end */
  /*           */
  /*          while shoElb(n) > maxVal */
  /*              shoElb(n) = shoElb(n) - (2 * pi); */
  /*          end */
  /*      end */
  /* '<S195>:1:151' */
  kinOut[0] = angles[0];
  kinOut[1] = angles[1];

  /* sho, elb angle */
  if (1 > velocities_sizes[1] - 1) {
    b = 0;
  } else {
    b = velocities_sizes[1] - 1;
  }

  /* '<S195>:1:114' */
  if (b == 0) {
    y_idx_0 = 0.0;
    s = 0.0;
  } else {
    ix = 0;
    s = velocities_data[0];
    for (ns = 2; ns <= b; ns++) {
      ix += 2;
      s += velocities_data[ix / 2 * velocities_sizes[0] + ix % 2];
    }

    y_idx_0 = s;
    ix = 1;
    s = velocities_data[1];
    for (ns = 2; ns <= b; ns++) {
      ix += 2;
      s += velocities_data[ix / 2 * velocities_sizes[0] + ix % 2];
    }
  }

  kinOut[2] = y_idx_0 / (real_T)b;
  kinOut[3] = s / (real_T)b;

  /* velocities, see DEX-2531 */
  /* '<S195>:1:116' */
  /* '<S195>:1:58' */
  if (filteredVelocities_sizes[1] != 0) {
    iy = 0;
    f = true;
    if (0 > filteredVelocities_sizes[0]) {
      iy = 1;
    }

    if (iy > (filteredVelocities_sizes[0] >> 1)) {
      iy = filteredVelocities_sizes[0] - 1;
      f = false;
    }

    absp_idx_0 = (int8_T)iy;
    shiftright_idx_0 = f;
    iy = 1;
    f = true;
    if (1 > (filteredVelocities_sizes[1] >> 1)) {
      iy = filteredVelocities_sizes[1] - 1;
      f = false;
    }

    absp_idx_1 = (int8_T)iy;
    npages_idx_0 = (int8_T)filteredVelocities_sizes[1];
    ix = filteredVelocities_sizes[0];
    ns = absp_idx_0;
    pagesize = filteredVelocities_sizes[0];
    if ((filteredVelocities_sizes[0] > 1) && (absp_idx_0 > 0)) {
      for (i = 1; i <= npages_idx_0; i++) {
        pageroot = (i - 1) * pagesize;
        for (b_j = 0; b_j + 1 < 2; b_j++) {
          i1 = pageroot + b_j;
          if (shiftright_idx_0) {
            for (b = 0; b + 1 <= ns; b++) {
              buffer_data[b] = filteredVelocities_data[((i1 + b) + ix) - ns];
            }

            for (b = ix; b >= ns + 1; b--) {
              filteredVelocities_data[(i1 + b) - 1] = filteredVelocities_data
                [((i1 + b) - ns) - 1];
            }

            for (b = 0; b + 1 <= ns; b++) {
              filteredVelocities_data[i1 + b] = buffer_data[b];
            }
          } else {
            for (b = 0; b + 1 <= ns; b++) {
              buffer_data[b] = filteredVelocities_data[i1 + b];
            }

            b = ix - ns;
            for (iy = 0; iy + 1 <= b; iy++) {
              filteredVelocities_data[i1 + iy] = filteredVelocities_data[(i1 +
                iy) + ns];
            }

            for (b = 0; b + 1 <= ns; b++) {
              filteredVelocities_data[((i1 + b) + ix) - ns] = buffer_data[b];
            }
          }
        }
      }
    }

    ix = filteredVelocities_sizes[1];
    ns = absp_idx_1;
    if ((filteredVelocities_sizes[1] > 1) && (absp_idx_1 > 0)) {
      i = 1;
      while (i <= 1) {
        for (b_j = 0; b_j + 1 <= pagesize; b_j++) {
          i1 = b_j;
          if (f) {
            for (b = 0; b + 1 <= ns; b++) {
              buffer_data[b] = filteredVelocities_data[((b + ix) - ns) *
                pagesize + i1];
            }

            for (b = ix; b >= ns + 1; b--) {
              filteredVelocities_data[i1 + (b - 1) * pagesize] =
                filteredVelocities_data[((b - ns) - 1) * pagesize + i1];
            }

            for (b = 0; b + 1 <= ns; b++) {
              filteredVelocities_data[i1 + b * pagesize] = buffer_data[b];
            }
          } else {
            for (b = 0; b + 1 <= ns; b++) {
              buffer_data[b] = filteredVelocities_data[b * pagesize + i1];
            }

            b = ix - ns;
            for (iy = 0; iy + 1 <= b; iy++) {
              filteredVelocities_data[i1 + iy * pagesize] =
                filteredVelocities_data[(iy + ns) * pagesize + i1];
            }

            for (b = 0; b + 1 <= ns; b++) {
              filteredVelocities_data[i1 + ((b + ix) - ns) * pagesize] =
                buffer_data[b];
            }
          }
        }

        i = 2;
      }
    }
  }

  /* '<S195>:1:59' */
  filteredVelocities_data[0] = kinOut[2];
  filteredVelocities_data[1] = kinOut[3];

  /* '<S195>:1:118' */
  /* % Calculate the derrivative of the given signals. This will work with and  */
  /*  X, Y matrix of values. You will get out the X derrivaties, each */
  /*  calculated over Y times steps. */
  /* '<S195>:1:127' */
  s = ((real_T)filteredVelocities_sizes[1] - 1.0) * stepTime;

  /* '<S195>:1:128' */
  b = filteredVelocities_sizes[1];
  kinOut[4] = (filteredVelocities_data[0] - filteredVelocities_data[(b - 1) *
               filteredVelocities_sizes[0]]) / s;
  kinOut[5] = (filteredVelocities_data[1] - filteredVelocities_data[(b - 1) *
               filteredVelocities_sizes[0] + 1]) / s;

  /* accelerations, see DEX-2531 */
  /* '<S195>:1:119' */
  s = kinOut[2];
  y_idx_0 = kinOut[3];
  kinOut[6] = s;
  kinOut[7] = y_idx_0;

  /* filtered vel */
  /* '<S195>:1:120' */
  kinOut[8] = motorStatuses[0];
  kinOut[9] = motorStatuses[1];

  /* M1, M2 status */
}

/* Function for MATLAB Function: '<S194>/filter_velocities' */
static void gbyk_v4b_insertVal(real_T arr[3], real_T v)
{
  real_T a_idx_2;
  real_T a_idx_0;
  real_T a_idx_1;

  /* '<S200>:1:39' */
  /* '<S200>:1:40' */
  a_idx_1 = arr[1];
  a_idx_2 = arr[2];
  a_idx_0 = a_idx_1;
  a_idx_1 = a_idx_2;
  a_idx_2 = arr[0];
  arr[0] = a_idx_0;
  arr[1] = a_idx_1;
  arr[2] = a_idx_2;

  /* '<S200>:1:41' */
  arr[2] = v;
}

/* Initial conditions for atomic system: '<S4>/Poll KINARM' */
void gbyk_v4b_PollKINARM_Init(void)
{
  int32_T i;

  /* InitializeConditions for MATLAB Function: '<S79>/update digital outputs' */
  gbyk_v4b_DW.prevRunStatus = 0U;

  /* InitializeConditions for Atomic SubSystem: '<S34>/Force Sensor Control' */
  gbyk_v4b_ForceSensorControl_Init();

  /* End of InitializeConditions for SubSystem: '<S34>/Force Sensor Control' */

  /* InitializeConditions for UnitDelay: '<S78>/Output' */
  gbyk_v4b_DW.Output_DSTATE_c = gbyk_v4b_P.Output_InitialCondition_pe;

  /* InitializeConditions for MATLAB Function: '<S64>/latch_errors' */
  gbyk_v4b_DW.enteredOpStep = 0U;
  gbyk_v4b_DW.sfEvent_n = -1;
  gbyk_v4b_DW.is_active_c38_General = 0U;
  gbyk_v4b_DW.is_c38_General = gbyk_v4b_IN_NO_ACTIVE_CHILD_e;

  /* InitializeConditions for Chart: '<S34>/control read write' incorporates:
   *  InitializeConditions for SubSystem: '<S64>/update'
   */
  /* InitializeConditions for MATLAB Function: '<S84>/create kinematics' */
  gbyk_v4b_DW.secondaryPosData_not_empty = false;
  for (i = 0; i < 12; i++) {
    /* InitializeConditions for MATLAB Function: '<S64>/latch_errors' */
    gbyk_v4b_DW.latchedErrors[i] = 0.0;
    gbyk_v4b_DW.latchedDCErrors[i] = 0.0;

    /* InitializeConditions for MATLAB Function: '<S194>/filter_velocities' */
    gbyk_v4b_DW.rawVelocities[i] = 0.0;
    gbyk_v4b_DW.filtVelocities[i] = 0.0;
  }

  /* InitializeConditions for MATLAB Function: '<S84>/create servo counter' */
  gbyk_v4b_DW.servoCounter_not_empty = false;

  /* InitializeConditions for Chart: '<S34>/control read write' incorporates:
   *  InitializeConditions for SubSystem: '<S34>/createKINData'
   */
  gbyk_v4b_createKINData_Init();
}

/* Disable for atomic system: '<S4>/Poll KINARM' */
void gbyk_v4b_PollKINARM_Disable(void)
{
  /* Disable for Enabled SubSystem: '<S64>/Arm 1' */
  if (gbyk_v4b_DW.Arm1_MODE) {
    /* Disable for Enabled SubSystem: '<S75>/M1 AbsEnc Calibration' */
    if (gbyk_v4b_DW.M1AbsEncCalibration_MODE_i) {
      gbyk_v4b_DW.M1AbsEncCalibration_MODE_i = false;
    }

    /* End of Disable for SubSystem: '<S75>/M1 AbsEnc Calibration' */

    /* Disable for Enabled SubSystem: '<S75>/M2 AbsEnc Calibration' */
    if (gbyk_v4b_DW.M2AbsEncCalibration_MODE_a) {
      gbyk_v4b_DW.M2AbsEncCalibration_MODE_a = false;
    }

    /* End of Disable for SubSystem: '<S75>/M2 AbsEnc Calibration' */
    gbyk_v4b_DW.Arm1_MODE = false;
  }

  /* End of Disable for SubSystem: '<S64>/Arm 1' */

  /* Disable for Enabled SubSystem: '<S64>/Arm 2' */
  if (gbyk_v4b_DW.Arm2_MODE) {
    /* Disable for Enabled SubSystem: '<S76>/M1 AbsEnc Calibration' */
    if (gbyk_v4b_DW.M1AbsEncCalibration_MODE) {
      gbyk_v4b_DW.M1AbsEncCalibration_MODE = false;
    }

    /* End of Disable for SubSystem: '<S76>/M1 AbsEnc Calibration' */

    /* Disable for Enabled SubSystem: '<S76>/M2 AbsEnc Calibration' */
    if (gbyk_v4b_DW.M2AbsEncCalibration_MODE) {
      gbyk_v4b_DW.M2AbsEncCalibration_MODE = false;
    }

    /* End of Disable for SubSystem: '<S76>/M2 AbsEnc Calibration' */
    gbyk_v4b_DW.Arm2_MODE = false;
  }

  /* End of Disable for SubSystem: '<S64>/Arm 2' */
}

/* Start for atomic system: '<S4>/Poll KINARM' */
void gbyk_v4b_PollKINARM_Start(void)
{
  int32_T i;

  /* Start for S-Function (BKINethercatinit): '<S64>/BKIN EtherCATinit1' */
  {
    int_T status = 1;
    char_T *errMsg;
    xpcPCIDevice pciInfo;
    char_T l_errMsg[128];
    int_T i;
    int_T j;
    uint8_T *DeviceType;

    /* From LinkOsLayer.h   Intel PRO-100 specific definitions */
    struct EtherCATDevices {
      uint16_T VendorID;
      uint16_T DeviceID;
      uint8_T *DeviceType;
    } EtherCATDeviceTable[] = {
      /* I8254x types */
      { 0x8086, 0xABB1, "I8254x" },    //

      { 0x8086, 0xABB2, "I8254x" },    //

      { 0x8086, 0x100E, "I8254x" },    //  PCI_DEVICE_I82540EM_DESKTOP

      { 0x8086, 0x1010, "I8254x" },    //  PCI_DEVICE_I82546EB_COPPER_DUAL

      { 0x8086, 0x1013, "I8254x" },    //  PCI_DEVICE_I82541EI_COPPER

      { 0x8086, 0x1019, "I8254x" },    //  PCI_DEVICE_I82547GI_COPPER

      { 0x8086, 0x1026, "I8254x" },    //  PCI_DEVICE_I82545GM_COPPER

      { 0x8086, 0x104A, "I8254x" },    //  PCI_DEVICE_I82566DM

      { 0x8086, 0x104D, "I8254x" },    //  PCI_DEVICE_I82566MC

      { 0x8086, 0x105E, "I8254x" },    //  PCI_DEVICE_N1E5132_SERVER

      { 0x8086, 0x1075, "I8254x" },    //  PCI_DEVICE_I82547EI

      { 0x8086, 0x1076, "I8254x" },    //  PCI_DEVICE_I82541GI_COPPER

      { 0x8086, 0x1078, "I8254x" },    //  PCI_DEVICE_I82541ER

      { 0x8086, 0x1079, "I8254x" },    //  PCI_DEVICE_I82546GB_COPPER_DUAL

      { 0x8086, 0x107C, "I8254x" },    //  PCI_DEVICE_I82541PI_DESKTOP

      { 0x8086, 0x107D, "I8254x" },    //  PCI_DEVICE_I82572EI

      { 0x8086, 0x108B, "I8254x" },    //  PCI_DEVICE_I82573E

      { 0x8086, 0x108C, "I8254x" },    //  PCI_DEVICE_I82573

      { 0x8086, 0x109A, "I8254x" },    //  PCI_DEVICE_I82573L

      { 0x8086, 0x10A4, "I8254x" },    //  PCI_DEVICE_I82571GB_QUAD

      { 0x8086, 0x10A7, "I8254x" },    //  PCI_DEVICE_I82575_ZOAR

      { 0x8086, 0x10B9, "I8254x" },    //  PCI_DEVICE_I82572GI

      { 0x8086, 0x10BC, "I8254x" },    //  PCI_DEVICE_I82571GB_QUAD_2

      { 0x8086, 0x10BD, "I8254x" },    //  PCI_DEVICE_I82566L

      { 0x8086, 0x10C9, "I8254x" },    //  PCI_DEVICE_I82576

      { 0x8086, 0x10CE, "I8254x" },    //  PCI_DEVICE_I82567V

      { 0x8086, 0x10D3, "I8254x" },    //  PCI_DEVICE_I82574L

      { 0x8086, 0x10DE, "I8254x" },    //  PCI_DEVICE_I82567LM3

      { 0x8086, 0x10EA, "I8254x" },    //  PCI_DEVICE_I82577LM

      { 0x8086, 0x10EB, "I8254x" },    //  PCI_DEVICE_I82577LC

      { 0x8086, 0x10EF, "I8254x" },    //  PCI_DEVICE_I82578DM

      { 0x8086, 0x10F0, "I8254x" },    //  PCI_DEVICE_I82578DC

      { 0x8086, 0x10F5, "I8254x" },    //  PCI_DEVICE_I82567LM

      { 0x8086, 0x1501, "I8254x" },    //  PCI_DEVICE_I82567V3

      { 0x8086, 0x1502, "I8254x" },    //  PCI_DEVICE_I82579LM

      { 0x8086, 0x1503, "I8254x" },    //  PCI_DEVICE_I82579V

      { 0x8086, 0x150C, "I8254x" },    //  PCI_DEVICE_I82583V

      { 0x8086, 0x150E, "I8254x" },    //  PCI_DEVICE_I82580_QUAD

      { 0x8086, 0x1521, "I8254x" },    //  PCI_DEVICE_I350

      { 0x8086, 0x1526, "I8254x" },    //  PCI_DEVICE_I82576_ET2

      { 0x8086, 0x1527, "I8254x" },    //  PCI_DEVICE_I82580_QUAD_FIBRE

      { 0x8086, 0x1533, "I8254x" },    //  PCI_DEVICE_I210_COPPER

      { 0x8086, 0x1539, "I8254x" },    //  PCI_DEVICE_I211AT

      { 0x8086, 0x157B, "I8254x" },    //  PCI_DEVICE_I210_COPPER_FLASHLESS

      { 0x8086, 0x153A, "I8254x" },    //  PCI_DEVICE_I217LM

      { 0x8086, 0x153B, "I8254x" },    //  PCI_DEVICE_I217V

      { 0x8086, 0x155A, "I8254x" },    //  PCI_DEVICE_I218LM

      { 0x8086, 0x1559, "I8254x" },    //  PCI_DEVICE_I218V

      /* I8255x types */
      { 0x8086, 0x103a, "I8255x" },    //  PCI device ID, Intel 82801DB(M) (ICH4) LAN Controller

      { 0x8086, 0x1229, "I8255x" },    //  82557 device ID

      { 0x8086, 0x1209, "I8255x" },    //  82557 ER device ID

      { 0x8086, 0x1050, "I8255x" },    //  PRO/100 VE device ID

      { 0x8086, 0x1039, "I8255x" },    //  82562 VE/VM device ID

      { 0x8086, 0x2449, "I8255x" },    //  82559 ER device ID

      { 0x8086, 0x27DC, "I8255x" },    //  PRO/100 VE device ID

      { 0x8086, 0x1059, "I8255x" },    //  Mobile version of 1229

      { 0x8086, 0x1092, "I8255x" }     //  PRO/100 VE3 device ID
    };

    if (!xpcIsModelInit()) {
      if (g_firstInitBlockToRunPlusOne == 0) {
        g_firstInitBlockToRunPlusOne = 1 + 1;
      }

      if (g_firstInitBlockToRunPlusOne == 1 + 1) {
        g_deviceIndex = NO_ETHERCAT;
      }

      gbyk_v4b_B.BKINEtherCATinit1_o2 = MC_TYPE_SIMULATION;
      gbyk_v4b_B.BKINEtherCATinit1_o3 = MC_TYPE_SIMULATION;

      /*  Initialize the first DWork vector so that by default EtherCAT for this EtherCAT network device is DISABLED */
      gbyk_v4b_DW.BKINEtherCATinit1_DWORK1 = 0;
      if (xpcGetPCIDeviceInfo( PMAC_VENDOR_ID, (uint16_T)PMAC_DEVICE_ID,
                              XPC_NO_SUB, XPC_NO_SUB, XPC_NO_BUS_SLOT,
                              XPC_NO_BUS_SLOT, &pciInfo ) ) {
        if (1 == g_firstInitBlockToRunPlusOne - 1 )
          printf("PMAC not found.\n");
      } else {
        if (1 == g_firstInitBlockToRunPlusOne - 1 )
          printf("PMAC found.\n");
        gbyk_v4b_B.BKINEtherCATinit1_o2 = gbyk_v4b_B.BKINEtherCATinit1_o2 + 1;// Bit 0 indicates if the PMAC is available
        if (gbyk_v4b_P.activation_Value[0] == MC_TYPE_PMAC) {
          gbyk_v4b_B.BKINEtherCATinit1_o3 = MC_TYPE_PMAC;
          printf("PMAC configuration enabled\n");
        }
      }

      status = xpcGetPciConfigAtSlot( gbyk_v4b_P.PCIBusSlot_Value[0],
        gbyk_v4b_P.PCIBusSlot_Value[1], &pciInfo);
      if (status ) {
        sprintf(l_errMsg, "You must specify a bus/slot, not auto search.\n");
        rtmSetErrorStatus(gbyk_v4b_M, l_errMsg);
        return;
      }

      status = -1;                     // Preset to a failed search.
      DeviceType = "";
      for (j = 0 ; j < sizeof(EtherCATDeviceTable)/sizeof(struct EtherCATDevices)
           ; j++ ) {
        // Search through the device table for the matching vendor/device ID.
        if (( pciInfo.DeviceId == EtherCATDeviceTable[j].DeviceID )
            && ( pciInfo.VendorId == EtherCATDeviceTable[j].VendorID ) ) {
          status = 0;
          DeviceType = EtherCATDeviceTable[j].DeviceType;
          break;
        }
      }

      if (status ) {
        if (1 == g_firstInitBlockToRunPlusOne - 1 ) {
          printf("No valid EtherCAT NIC found at bus %d slot %d\n",
                 gbyk_v4b_P.PCIBusSlot_Value[0], gbyk_v4b_P.PCIBusSlot_Value[1]);
        }
      } else {
        char *logfile = "c:\\dbglog.txt";
        gbyk_v4b_B.BKINEtherCATinit1_o2 = gbyk_v4b_B.BKINEtherCATinit1_o2 + 2;// // Bit 1 indicates that the valid EtherCAT NIC found
        if (1 == g_firstInitBlockToRunPlusOne - 1) {
          printf("Valid EtherCAT NIC found at bus %d slot %d\n",
                 gbyk_v4b_P.PCIBusSlot_Value[0], gbyk_v4b_P.PCIBusSlot_Value[1]);
          if ((gbyk_v4b_P.activation_Value[1] >= MAX_NUMBER_ECAT_NETWORK_DEVICES
               ) && (gbyk_v4b_P.activation_Value[0] == MC_TYPE_ETHERCAT) ) {
            printf("Requested EtherCAT Network device %d is greater then max allowable value of %d\n",
                   gbyk_v4b_P.activation_Value[1],
                   MAX_NUMBER_ECAT_NETWORK_DEVICES - 1 );
          }
        }

        if (( gbyk_v4b_P.activation_Value[1] == 1 ) &&
            (gbyk_v4b_P.activation_Value[0] == MC_TYPE_ETHERCAT) ) {
          status = xpcEtherCATinitialize(1, DeviceType,
            gbyk_v4b_P.PCIBusSlot_Value[0], gbyk_v4b_P.PCIBusSlot_Value[1], 0, 1,
            xmlCharArr_1, sizeof(xmlCharArr_1),1048576, 1, logfile, 0.00025);
          if (status != XPC_ECAT_OK) {
            errMsg = xpcPrintEtherCATError(1, 0);
            rtmSetErrorStatus(gbyk_v4b_M, errMsg);
            return;
          }

          //printf("init status = %08x\n", status );
          gbyk_v4b_DW.BKINEtherCATinit1_DWORK1 = 1;// Indicate to the rest of this block that EtherCAT is enabled for THIS block
          gbyk_v4b_B.BKINEtherCATinit1_o3 = MC_TYPE_ETHERCAT;// Output that indicates that Motion Control Type of EtherCAT was requested and found (for this device)
          g_deviceIndex = 1;           // Store the device index into this global variable for the other EtherCAT blocks to access
          printf("EtherCAT Network device %d configured.\n", 1);
        }
      }
    }
  }

  /* Start for S-Function (BKINethercatinit): '<S64>/BKIN EtherCATinit' */
  {
    int_T status = 1;
    char_T *errMsg;
    xpcPCIDevice pciInfo;
    char_T l_errMsg[128];
    int_T i;
    int_T j;
    uint8_T *DeviceType;

    /* From LinkOsLayer.h   Intel PRO-100 specific definitions */
    struct EtherCATDevices {
      uint16_T VendorID;
      uint16_T DeviceID;
      uint8_T *DeviceType;
    } EtherCATDeviceTable[] = {
      /* I8254x types */
      { 0x8086, 0xABB1, "I8254x" },    //

      { 0x8086, 0xABB2, "I8254x" },    //

      { 0x8086, 0x100E, "I8254x" },    //  PCI_DEVICE_I82540EM_DESKTOP

      { 0x8086, 0x1010, "I8254x" },    //  PCI_DEVICE_I82546EB_COPPER_DUAL

      { 0x8086, 0x1013, "I8254x" },    //  PCI_DEVICE_I82541EI_COPPER

      { 0x8086, 0x1019, "I8254x" },    //  PCI_DEVICE_I82547GI_COPPER

      { 0x8086, 0x1026, "I8254x" },    //  PCI_DEVICE_I82545GM_COPPER

      { 0x8086, 0x104A, "I8254x" },    //  PCI_DEVICE_I82566DM

      { 0x8086, 0x104D, "I8254x" },    //  PCI_DEVICE_I82566MC

      { 0x8086, 0x105E, "I8254x" },    //  PCI_DEVICE_N1E5132_SERVER

      { 0x8086, 0x1075, "I8254x" },    //  PCI_DEVICE_I82547EI

      { 0x8086, 0x1076, "I8254x" },    //  PCI_DEVICE_I82541GI_COPPER

      { 0x8086, 0x1078, "I8254x" },    //  PCI_DEVICE_I82541ER

      { 0x8086, 0x1079, "I8254x" },    //  PCI_DEVICE_I82546GB_COPPER_DUAL

      { 0x8086, 0x107C, "I8254x" },    //  PCI_DEVICE_I82541PI_DESKTOP

      { 0x8086, 0x107D, "I8254x" },    //  PCI_DEVICE_I82572EI

      { 0x8086, 0x108B, "I8254x" },    //  PCI_DEVICE_I82573E

      { 0x8086, 0x108C, "I8254x" },    //  PCI_DEVICE_I82573

      { 0x8086, 0x109A, "I8254x" },    //  PCI_DEVICE_I82573L

      { 0x8086, 0x10A4, "I8254x" },    //  PCI_DEVICE_I82571GB_QUAD

      { 0x8086, 0x10A7, "I8254x" },    //  PCI_DEVICE_I82575_ZOAR

      { 0x8086, 0x10B9, "I8254x" },    //  PCI_DEVICE_I82572GI

      { 0x8086, 0x10BC, "I8254x" },    //  PCI_DEVICE_I82571GB_QUAD_2

      { 0x8086, 0x10BD, "I8254x" },    //  PCI_DEVICE_I82566L

      { 0x8086, 0x10C9, "I8254x" },    //  PCI_DEVICE_I82576

      { 0x8086, 0x10CE, "I8254x" },    //  PCI_DEVICE_I82567V

      { 0x8086, 0x10D3, "I8254x" },    //  PCI_DEVICE_I82574L

      { 0x8086, 0x10DE, "I8254x" },    //  PCI_DEVICE_I82567LM3

      { 0x8086, 0x10EA, "I8254x" },    //  PCI_DEVICE_I82577LM

      { 0x8086, 0x10EB, "I8254x" },    //  PCI_DEVICE_I82577LC

      { 0x8086, 0x10EF, "I8254x" },    //  PCI_DEVICE_I82578DM

      { 0x8086, 0x10F0, "I8254x" },    //  PCI_DEVICE_I82578DC

      { 0x8086, 0x10F5, "I8254x" },    //  PCI_DEVICE_I82567LM

      { 0x8086, 0x1501, "I8254x" },    //  PCI_DEVICE_I82567V3

      { 0x8086, 0x1502, "I8254x" },    //  PCI_DEVICE_I82579LM

      { 0x8086, 0x1503, "I8254x" },    //  PCI_DEVICE_I82579V

      { 0x8086, 0x150C, "I8254x" },    //  PCI_DEVICE_I82583V

      { 0x8086, 0x150E, "I8254x" },    //  PCI_DEVICE_I82580_QUAD

      { 0x8086, 0x1521, "I8254x" },    //  PCI_DEVICE_I350

      { 0x8086, 0x1526, "I8254x" },    //  PCI_DEVICE_I82576_ET2

      { 0x8086, 0x1527, "I8254x" },    //  PCI_DEVICE_I82580_QUAD_FIBRE

      { 0x8086, 0x1533, "I8254x" },    //  PCI_DEVICE_I210_COPPER

      { 0x8086, 0x1539, "I8254x" },    //  PCI_DEVICE_I211AT

      { 0x8086, 0x157B, "I8254x" },    //  PCI_DEVICE_I210_COPPER_FLASHLESS

      { 0x8086, 0x153A, "I8254x" },    //  PCI_DEVICE_I217LM

      { 0x8086, 0x153B, "I8254x" },    //  PCI_DEVICE_I217V

      { 0x8086, 0x155A, "I8254x" },    //  PCI_DEVICE_I218LM

      { 0x8086, 0x1559, "I8254x" },    //  PCI_DEVICE_I218V

      /* I8255x types */
      { 0x8086, 0x103a, "I8255x" },    //  PCI device ID, Intel 82801DB(M) (ICH4) LAN Controller

      { 0x8086, 0x1229, "I8255x" },    //  82557 device ID

      { 0x8086, 0x1209, "I8255x" },    //  82557 ER device ID

      { 0x8086, 0x1050, "I8255x" },    //  PRO/100 VE device ID

      { 0x8086, 0x1039, "I8255x" },    //  82562 VE/VM device ID

      { 0x8086, 0x2449, "I8255x" },    //  82559 ER device ID

      { 0x8086, 0x27DC, "I8255x" },    //  PRO/100 VE device ID

      { 0x8086, 0x1059, "I8255x" },    //  Mobile version of 1229

      { 0x8086, 0x1092, "I8255x" }     //  PRO/100 VE3 device ID
    };

    if (!xpcIsModelInit()) {
      if (g_firstInitBlockToRunPlusOne == 0) {
        g_firstInitBlockToRunPlusOne = 0 + 1;
      }

      if (g_firstInitBlockToRunPlusOne == 0 + 1) {
        g_deviceIndex = NO_ETHERCAT;
      }

      gbyk_v4b_B.BKINEtherCATinit_o2 = MC_TYPE_SIMULATION;
      gbyk_v4b_B.BKINEtherCATinit_o3 = MC_TYPE_SIMULATION;

      /*  Initialize the first DWork vector so that by default EtherCAT for this EtherCAT network device is DISABLED */
      gbyk_v4b_DW.BKINEtherCATinit_DWORK1 = 0;
      if (xpcGetPCIDeviceInfo( PMAC_VENDOR_ID, (uint16_T)PMAC_DEVICE_ID,
                              XPC_NO_SUB, XPC_NO_SUB, XPC_NO_BUS_SLOT,
                              XPC_NO_BUS_SLOT, &pciInfo ) ) {
        if (0 == g_firstInitBlockToRunPlusOne - 1 )
          printf("PMAC not found.\n");
      } else {
        if (0 == g_firstInitBlockToRunPlusOne - 1 )
          printf("PMAC found.\n");
        gbyk_v4b_B.BKINEtherCATinit_o2 = gbyk_v4b_B.BKINEtherCATinit_o2 + 1;// Bit 0 indicates if the PMAC is available
        if (gbyk_v4b_P.activation_Value[0] == MC_TYPE_PMAC) {
          gbyk_v4b_B.BKINEtherCATinit_o3 = MC_TYPE_PMAC;
          printf("PMAC configuration enabled\n");
        }
      }

      status = xpcGetPciConfigAtSlot( gbyk_v4b_P.PCIBusSlot_Value[0],
        gbyk_v4b_P.PCIBusSlot_Value[1], &pciInfo);
      if (status ) {
        sprintf(l_errMsg, "You must specify a bus/slot, not auto search.\n");
        rtmSetErrorStatus(gbyk_v4b_M, l_errMsg);
        return;
      }

      status = -1;                     // Preset to a failed search.
      DeviceType = "";
      for (j = 0 ; j < sizeof(EtherCATDeviceTable)/sizeof(struct EtherCATDevices)
           ; j++ ) {
        // Search through the device table for the matching vendor/device ID.
        if (( pciInfo.DeviceId == EtherCATDeviceTable[j].DeviceID )
            && ( pciInfo.VendorId == EtherCATDeviceTable[j].VendorID ) ) {
          status = 0;
          DeviceType = EtherCATDeviceTable[j].DeviceType;
          break;
        }
      }

      if (status ) {
        if (0 == g_firstInitBlockToRunPlusOne - 1 ) {
          printf("No valid EtherCAT NIC found at bus %d slot %d\n",
                 gbyk_v4b_P.PCIBusSlot_Value[0], gbyk_v4b_P.PCIBusSlot_Value[1]);
        }
      } else {
        char *logfile = "c:\\dbglog.txt";
        gbyk_v4b_B.BKINEtherCATinit_o2 = gbyk_v4b_B.BKINEtherCATinit_o2 + 2;// // Bit 1 indicates that the valid EtherCAT NIC found
        if (0 == g_firstInitBlockToRunPlusOne - 1) {
          printf("Valid EtherCAT NIC found at bus %d slot %d\n",
                 gbyk_v4b_P.PCIBusSlot_Value[0], gbyk_v4b_P.PCIBusSlot_Value[1]);
          if ((gbyk_v4b_P.activation_Value[1] >= MAX_NUMBER_ECAT_NETWORK_DEVICES
               ) && (gbyk_v4b_P.activation_Value[0] == MC_TYPE_ETHERCAT) ) {
            printf("Requested EtherCAT Network device %d is greater then max allowable value of %d\n",
                   gbyk_v4b_P.activation_Value[1],
                   MAX_NUMBER_ECAT_NETWORK_DEVICES - 1 );
          }
        }

        if (( gbyk_v4b_P.activation_Value[1] == 0 ) &&
            (gbyk_v4b_P.activation_Value[0] == MC_TYPE_ETHERCAT) ) {
          status = xpcEtherCATinitialize(0, DeviceType,
            gbyk_v4b_P.PCIBusSlot_Value[0], gbyk_v4b_P.PCIBusSlot_Value[1], 0, 1,
            xmlCharArr_0, sizeof(xmlCharArr_0),1048576, 1, logfile, 0.00025);
          if (status != XPC_ECAT_OK) {
            errMsg = xpcPrintEtherCATError(0, 0);
            rtmSetErrorStatus(gbyk_v4b_M, errMsg);
            return;
          }

          //printf("init status = %08x\n", status );
          gbyk_v4b_DW.BKINEtherCATinit_DWORK1 = 1;// Indicate to the rest of this block that EtherCAT is enabled for THIS block
          gbyk_v4b_B.BKINEtherCATinit_o3 = MC_TYPE_ETHERCAT;// Output that indicates that Motion Control Type of EtherCAT was requested and found (for this device)
          g_deviceIndex = 0;           // Store the device index into this global variable for the other EtherCAT blocks to access
          printf("EtherCAT Network device %d configured.\n", 0);
        }
      }
    }
  }

  /* Start for Constant: '<S34>/system type' */
  gbyk_v4b_B.systemtype = gbyk_v4b_P.systemtype_Value;

  /* Start for Enabled SubSystem: '<S64>/Arm 1' */
  gbyk_v4b_DW.Arm1_MODE = false;

  /* Start for Constant: '<S75>/Torque Mode' */
  gbyk_v4b_B.TorqueMode_i = gbyk_v4b_P.TorqueMode_Value;

  /* Level2 S-Function Block: '<S75>/BKIN EtherCAT PDO Transmit ' (BKINethercatpdotx) */
  {
    SimStruct *rts = gbyk_v4b_M->childSfunctions[10];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S75>/BKIN EtherCAT PDO Transmit 1' (BKINethercatpdotx) */
  {
    SimStruct *rts = gbyk_v4b_M->childSfunctions[11];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for Atomic SubSystem: '<S85>/A1M1 PDOs' */

  /* Level2 S-Function Block: '<S99>/BKIN PDO Receive ElmoDrive' (BKINethercatpdorxElmoDrive) */
  {
    SimStruct *rts = gbyk_v4b_M->childSfunctions[8];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* End of Start for SubSystem: '<S85>/A1M1 PDOs' */

  /* Start for Atomic SubSystem: '<S85>/EMCY Message pump' */
  gbyk_v4b_EMCYMessagepump_Start();

  /* End of Start for SubSystem: '<S85>/EMCY Message pump' */

  /* Level2 S-Function Block: '<S85>/BKIN EtherCAT PDO Transmit ' (BKINethercatpdotx) */
  {
    SimStruct *rts = gbyk_v4b_M->childSfunctions[12];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for Constant: '<S75>/readTrigger' */
  gbyk_v4b_B.readTrigger_k = gbyk_v4b_P.readTrigger_Value;

  /* Start for Atomic SubSystem: '<S86>/A1M2 PDOs' */

  /* Level2 S-Function Block: '<S112>/BKIN PDO Receive ElmoDrive' (BKINethercatpdorxElmoDrive) */
  {
    SimStruct *rts = gbyk_v4b_M->childSfunctions[9];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* End of Start for SubSystem: '<S86>/A1M2 PDOs' */

  /* Start for Atomic SubSystem: '<S86>/EMCY Message pump' */
  gbyk_v4b_EMCYMessagepump_h_Start();

  /* End of Start for SubSystem: '<S86>/EMCY Message pump' */

  /* Level2 S-Function Block: '<S86>/BKIN EtherCAT PDO Transmit ' (BKINethercatpdotx) */
  {
    SimStruct *rts = gbyk_v4b_M->childSfunctions[13];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for Enabled SubSystem: '<S75>/M1 AbsEnc Calibration' */
  gbyk_v4b_DW.M1AbsEncCalibration_MODE_i = false;

  /* InitializeConditions for Enabled SubSystem: '<S75>/M1 AbsEnc Calibration' */
  /* InitializeConditions for Memory: '<S88>/Memory' */
  gbyk_v4b_DW.Memory_PreviousInput_hw = gbyk_v4b_P.Memory_X0_e;

  /* InitializeConditions for Memory: '<S88>/Memory1' */
  gbyk_v4b_DW.Memory1_PreviousInput_g[0] = gbyk_v4b_P.Memory1_X0_h;
  gbyk_v4b_DW.Memory1_PreviousInput_g[1] = gbyk_v4b_P.Memory1_X0_h;

  /* InitializeConditions for Chart: '<S88>/AbsEncoder machine' */
  gbyk_v4b_AbsEncodermachine_Init(&gbyk_v4b_B.sf_AbsEncodermachine,
    &gbyk_v4b_DW.sf_AbsEncodermachine);

  /* End of InitializeConditions for SubSystem: '<S75>/M1 AbsEnc Calibration' */

  /* Start for Enabled SubSystem: '<S75>/M2 AbsEnc Calibration' */
  gbyk_v4b_DW.M2AbsEncCalibration_MODE_a = false;

  /* InitializeConditions for Enabled SubSystem: '<S75>/M2 AbsEnc Calibration' */
  /* InitializeConditions for Memory: '<S89>/Memory' */
  gbyk_v4b_DW.Memory_PreviousInput_i = gbyk_v4b_P.Memory_X0_gr;

  /* InitializeConditions for Memory: '<S89>/Memory1' */
  gbyk_v4b_DW.Memory1_PreviousInput_a[0] = gbyk_v4b_P.Memory1_X0_p;
  gbyk_v4b_DW.Memory1_PreviousInput_a[1] = gbyk_v4b_P.Memory1_X0_p;

  /* InitializeConditions for Chart: '<S89>/AbsEncoder machine' */
  gbyk_v4b_AbsEncodermachine_Init(&gbyk_v4b_B.sf_AbsEncodermachine_b,
    &gbyk_v4b_DW.sf_AbsEncodermachine_b);

  /* End of InitializeConditions for SubSystem: '<S75>/M2 AbsEnc Calibration' */

  /* Start for Atomic SubSystem: '<S75>/SDO reading' */
  gbyk_v4b_SDOreading_Start();

  /* End of Start for SubSystem: '<S75>/SDO reading' */

  /* Start for Atomic SubSystem: '<S75>/SDO writing' */
  gbyk_v4b_SDOwriting_Start();

  /* End of Start for SubSystem: '<S75>/SDO writing' */

  /* End of Start for SubSystem: '<S64>/Arm 1' */

  /* InitializeConditions for Enabled SubSystem: '<S64>/Arm 1' */

  /* InitializeConditions for Atomic SubSystem: '<S85>/EMCY Message pump' */
  gbyk_v4b_EMCYMessagepump_Init();

  /* End of InitializeConditions for SubSystem: '<S85>/EMCY Message pump' */

  /* InitializeConditions for Memory: '<S85>/Memory' */
  gbyk_v4b_DW.Memory_PreviousInput_g = gbyk_v4b_P.Memory_X0_f;

  /* InitializeConditions for Memory: '<S86>/Memory' */
  gbyk_v4b_DW.Memory_PreviousInput_pv = gbyk_v4b_P.Memory_X0_jg;

  /* InitializeConditions for MATLAB Function: '<S75>/forceEnableDisable' */
  gbyk_v4b_forceEnableDisable_Init(&gbyk_v4b_DW.sf_forceEnableDisable);

  /* InitializeConditions for MATLAB Function: '<S85>/Control GDC Whistle State' */
  gbyk_v4b_DW.permFaulted_not_empty_n = false;
  gbyk_v4b_DW.permFaulted_l = 0.0;
  gbyk_v4b_DW.countFaultSteps_d = 0.0;
  gbyk_v4b_DW.frameCounter_e = 0.0;

  /* InitializeConditions for Memory: '<S94>/Memory' */
  gbyk_v4b_DW.Memory_PreviousInput_pn = gbyk_v4b_P.Memory_X0_hu;

  /* InitializeConditions for Memory: '<S94>/Memory1' */
  gbyk_v4b_DW.Memory1_PreviousInput_i = gbyk_v4b_P.Memory1_X0;

  /* InitializeConditions for Memory: '<S94>/Memory2' */
  gbyk_v4b_DW.Memory2_PreviousInput_p = gbyk_v4b_P.Memory2_X0_k;

  /* InitializeConditions for Chart: '<S75>/SDO read machine' */
  gbyk_v4b_SDOreadmachine_Init(&gbyk_v4b_B.sf_SDOreadmachine,
    &gbyk_v4b_DW.sf_SDOreadmachine);

  /* InitializeConditions for Memory: '<S75>/Memory2' */
  gbyk_v4b_DW.Memory2_PreviousInput_i[0] = gbyk_v4b_P.Memory2_X0_i;
  gbyk_v4b_DW.Memory2_PreviousInput_i[1] = gbyk_v4b_P.Memory2_X0_i;

  /* InitializeConditions for Memory: '<S75>/Memory3' */
  gbyk_v4b_DW.Memory3_PreviousInput_l = gbyk_v4b_P.Memory3_X0;

  /* InitializeConditions for Atomic SubSystem: '<S86>/EMCY Message pump' */
  gbyk_v4b_EMCYMessagepump_p_Init();

  /* End of InitializeConditions for SubSystem: '<S86>/EMCY Message pump' */

  /* InitializeConditions for MATLAB Function: '<S86>/Control GDC Whistle State' */
  gbyk_v4b_ControlGDCWhistleState_Init(&gbyk_v4b_DW.sf_ControlGDCWhistleState_f);

  /* InitializeConditions for Atomic SubSystem: '<S75>/SDO reading' */
  gbyk_v4b_SDOreading_Init();

  /* End of InitializeConditions for SubSystem: '<S75>/SDO reading' */

  /* InitializeConditions for Atomic SubSystem: '<S75>/SDO writing' */
  gbyk_v4b_SDOwriting_Init();

  /* End of InitializeConditions for SubSystem: '<S75>/SDO writing' */

  /* End of InitializeConditions for SubSystem: '<S64>/Arm 1' */

  /* Start for Enabled SubSystem: '<S64>/Arm 2' */
  gbyk_v4b_DW.Arm2_MODE = false;

  /* Start for Constant: '<S76>/Torque Mode' */
  gbyk_v4b_B.TorqueMode = gbyk_v4b_P.TorqueMode_Value_k;

  /* Level2 S-Function Block: '<S76>/BKIN EtherCAT PDO Transmit ' (BKINethercatpdotx) */
  {
    SimStruct *rts = gbyk_v4b_M->childSfunctions[16];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S76>/BKIN EtherCAT PDO Transmit 1' (BKINethercatpdotx) */
  {
    SimStruct *rts = gbyk_v4b_M->childSfunctions[17];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for Atomic SubSystem: '<S137>/A2M1 PDOs' */
  gbyk_v4b_A2M1PDOs_Start();

  /* End of Start for SubSystem: '<S137>/A2M1 PDOs' */

  /* Start for Atomic SubSystem: '<S137>/EMCY Message pump' */
  gbyk_v4b_EMCYMessagepump_b_Start();

  /* End of Start for SubSystem: '<S137>/EMCY Message pump' */

  /* Level2 S-Function Block: '<S137>/BKIN EtherCAT PDO Transmit ' (BKINethercatpdotx) */
  {
    SimStruct *rts = gbyk_v4b_M->childSfunctions[18];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for Constant: '<S76>/readTrigger' */
  gbyk_v4b_B.readTrigger = gbyk_v4b_P.readTrigger_Value_l;

  /* Start for Atomic SubSystem: '<S138>/A2M2 PDOs' */
  gbyk_v4b_A2M2PDOs_Start();

  /* End of Start for SubSystem: '<S138>/A2M2 PDOs' */

  /* Start for Atomic SubSystem: '<S138>/EMCY Message pump' */
  gbyk_v4b_EMCYMessagepump_j_Start();

  /* End of Start for SubSystem: '<S138>/EMCY Message pump' */

  /* Level2 S-Function Block: '<S138>/BKIN EtherCAT PDO Transmit ' (BKINethercatpdotx) */
  {
    SimStruct *rts = gbyk_v4b_M->childSfunctions[19];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for Enabled SubSystem: '<S76>/M1 AbsEnc Calibration' */
  gbyk_v4b_DW.M1AbsEncCalibration_MODE = false;

  /* InitializeConditions for Enabled SubSystem: '<S76>/M1 AbsEnc Calibration' */
  /* InitializeConditions for Memory: '<S140>/Memory' */
  gbyk_v4b_DW.Memory_PreviousInput_cs = gbyk_v4b_P.Memory_X0_nj;

  /* InitializeConditions for Memory: '<S140>/Memory1' */
  gbyk_v4b_DW.Memory1_PreviousInput_io[0] = gbyk_v4b_P.Memory1_X0_hb;
  gbyk_v4b_DW.Memory1_PreviousInput_io[1] = gbyk_v4b_P.Memory1_X0_hb;

  /* InitializeConditions for Chart: '<S140>/AbsEncoder machine' */
  gbyk_v4b_AbsEncodermachine_Init(&gbyk_v4b_B.sf_AbsEncodermachine_i,
    &gbyk_v4b_DW.sf_AbsEncodermachine_i);

  /* End of InitializeConditions for SubSystem: '<S76>/M1 AbsEnc Calibration' */

  /* Start for Enabled SubSystem: '<S76>/M2 AbsEnc Calibration' */
  gbyk_v4b_DW.M2AbsEncCalibration_MODE = false;

  /* InitializeConditions for Enabled SubSystem: '<S76>/M2 AbsEnc Calibration' */
  /* InitializeConditions for Memory: '<S141>/Memory' */
  gbyk_v4b_DW.Memory_PreviousInput_o = gbyk_v4b_P.Memory_X0_id;

  /* InitializeConditions for Memory: '<S141>/Memory1' */
  gbyk_v4b_DW.Memory1_PreviousInput_l[0] = gbyk_v4b_P.Memory1_X0_a;
  gbyk_v4b_DW.Memory1_PreviousInput_l[1] = gbyk_v4b_P.Memory1_X0_a;

  /* InitializeConditions for Chart: '<S141>/AbsEncoder machine' */
  gbyk_v4b_AbsEncodermachine_Init(&gbyk_v4b_B.sf_AbsEncodermachine_k,
    &gbyk_v4b_DW.sf_AbsEncodermachine_k);

  /* End of InitializeConditions for SubSystem: '<S76>/M2 AbsEnc Calibration' */

  /* Start for Atomic SubSystem: '<S76>/SDO reading' */
  gbyk_v4b_SDOreading_m_Start();

  /* End of Start for SubSystem: '<S76>/SDO reading' */

  /* Start for Atomic SubSystem: '<S76>/SDO writing' */
  gbyk_v4b_SDOwriting_e_Start();

  /* End of Start for SubSystem: '<S76>/SDO writing' */

  /* End of Start for SubSystem: '<S64>/Arm 2' */

  /* InitializeConditions for Enabled SubSystem: '<S64>/Arm 2' */

  /* InitializeConditions for Atomic SubSystem: '<S137>/EMCY Message pump' */
  gbyk_v4b_EMCYMessagepump_f_Init();

  /* End of InitializeConditions for SubSystem: '<S137>/EMCY Message pump' */

  /* InitializeConditions for Memory: '<S137>/Memory' */
  gbyk_v4b_DW.Memory_PreviousInput_l = gbyk_v4b_P.Memory_X0_g;

  /* InitializeConditions for Memory: '<S138>/Memory' */
  gbyk_v4b_DW.Memory_PreviousInput_h = gbyk_v4b_P.Memory_X0_fo;

  /* InitializeConditions for MATLAB Function: '<S76>/forceEnableDisable' */
  gbyk_v4b_forceEnableDisable_Init(&gbyk_v4b_DW.sf_forceEnableDisable_k);

  /* InitializeConditions for MATLAB Function: '<S137>/Control GDC Whistle State' */
  gbyk_v4b_ControlGDCWhistleState_Init(&gbyk_v4b_DW.sf_ControlGDCWhistleState_p);

  /* InitializeConditions for Memory: '<S146>/Memory' */
  gbyk_v4b_DW.Memory_PreviousInput_b = gbyk_v4b_P.Memory_X0_ge;

  /* InitializeConditions for Memory: '<S146>/Memory1' */
  gbyk_v4b_DW.Memory1_PreviousInput_c = gbyk_v4b_P.Memory1_X0_f;

  /* InitializeConditions for Memory: '<S146>/Memory2' */
  gbyk_v4b_DW.Memory2_PreviousInput = gbyk_v4b_P.Memory2_X0_e;

  /* InitializeConditions for Chart: '<S76>/SDO read machine' */
  gbyk_v4b_SDOreadmachine_Init(&gbyk_v4b_B.sf_SDOreadmachine_h,
    &gbyk_v4b_DW.sf_SDOreadmachine_h);

  /* InitializeConditions for Memory: '<S76>/Memory2' */
  gbyk_v4b_DW.Memory2_PreviousInput_n[0] = gbyk_v4b_P.Memory2_X0_o;
  gbyk_v4b_DW.Memory2_PreviousInput_n[1] = gbyk_v4b_P.Memory2_X0_o;

  /* InitializeConditions for Memory: '<S76>/Memory3' */
  gbyk_v4b_DW.Memory3_PreviousInput = gbyk_v4b_P.Memory3_X0_i;

  /* InitializeConditions for Atomic SubSystem: '<S138>/EMCY Message pump' */
  gbyk_v4b_EMCYMessagepump_b_Init();

  /* End of InitializeConditions for SubSystem: '<S138>/EMCY Message pump' */

  /* InitializeConditions for MATLAB Function: '<S138>/Control GDC Whistle State' */
  gbyk_v4b_DW.permFaulted_not_empty = false;
  gbyk_v4b_DW.permFaulted = 0.0;
  gbyk_v4b_DW.countFaultSteps = 0.0;
  gbyk_v4b_DW.frameCounter = 0.0;

  /* InitializeConditions for Atomic SubSystem: '<S76>/SDO reading' */
  gbyk_v4b_SDOreading_k_Init();

  /* End of InitializeConditions for SubSystem: '<S76>/SDO reading' */

  /* InitializeConditions for Atomic SubSystem: '<S76>/SDO writing' */
  gbyk_v4b_SDOwriting_m_Init();

  /* End of InitializeConditions for SubSystem: '<S76>/SDO writing' */

  /* End of InitializeConditions for SubSystem: '<S64>/Arm 2' */
  /* Level2 S-Function Block: '<S79>/BKIN EtherCAT PDO Transmit ' (BKINethercatpdotx) */
  {
    SimStruct *rts = gbyk_v4b_M->childSfunctions[29];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S79>/BKIN EtherCAT PDO Transmit 1' (BKINethercatpdotx) */
  {
    SimStruct *rts = gbyk_v4b_M->childSfunctions[30];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S79>/BKIN EtherCAT PDO Transmit 2' (BKINethercatpdotx) */
  {
    SimStruct *rts = gbyk_v4b_M->childSfunctions[31];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Level2 S-Function Block: '<S79>/BKIN EtherCAT PDO Transmit 3' (BKINethercatpdotx) */
  {
    SimStruct *rts = gbyk_v4b_M->childSfunctions[32];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for Atomic SubSystem: '<S34>/Force Sensor Control' */
  gbyk_v4b_ForceSensorControl_Start();

  /* End of Start for SubSystem: '<S34>/Force Sensor Control' */

  /* Start for Enabled SubSystem: '<S67>/Data receive' */

  /* Level2 S-Function Block: '<S223>/Receive' (xpcudpbytereceive) */
  {
    SimStruct *rts = gbyk_v4b_M->childSfunctions[28];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* End of Start for SubSystem: '<S67>/Data receive' */

  /* InitializeConditions for Enabled SubSystem: '<S67>/Data receive' */
  /* InitializeConditions for UnitDelay: '<S226>/Output' */
  gbyk_v4b_DW.Output_DSTATE_h = gbyk_v4b_P.Output_InitialCondition_p;

  /* InitializeConditions for MATLAB Function: '<S223>/MATLAB Function' */
  gbyk_v4b_DW.r1Sho[0] = 0.0;
  gbyk_v4b_DW.r1Sho[1] = 0.0;
  gbyk_v4b_DW.r1Sho[2] = 0.0;
  gbyk_v4b_DW.r1Sho[3] = 0.0;
  gbyk_v4b_DW.r1Elb[0] = 0.0;
  gbyk_v4b_DW.r1Elb[1] = 0.0;
  gbyk_v4b_DW.r1Elb[2] = 0.0;
  gbyk_v4b_DW.r1Elb[3] = 0.0;
  gbyk_v4b_DW.r2Sho[0] = 0.0;
  gbyk_v4b_DW.r2Sho[1] = 0.0;
  gbyk_v4b_DW.r2Sho[2] = 0.0;
  gbyk_v4b_DW.r2Sho[3] = 0.0;
  gbyk_v4b_DW.r2Elb[0] = 0.0;
  gbyk_v4b_DW.r2Elb[1] = 0.0;
  gbyk_v4b_DW.r2Elb[2] = 0.0;
  gbyk_v4b_DW.r2Elb[3] = 0.0;
  gbyk_v4b_DW.last_tick[0] = 0.0;
  gbyk_v4b_DW.last_tick[1] = 0.0;
  gbyk_v4b_DW.last_tick[2] = 0.0;
  gbyk_v4b_DW.last_tick[3] = 0.0;

  /* End of InitializeConditions for SubSystem: '<S67>/Data receive' */

  /* Start for Enabled SubSystem: '<S67>/Data receive' */
  /* VirtualOutportStart for Outport: '<S223>/servo counter' */
  gbyk_v4b_B.Output_e = gbyk_v4b_P.servocounter_Y0;

  /* VirtualOutportStart for Outport: '<S223>/EP calibration btn' */
  gbyk_v4b_B.Constant = gbyk_v4b_P.EPcalibrationbtn_Y0;

  /* VirtualOutportStart for Outport: '<S223>/Status bits' */
  for (i = 0; i < 7; i++) {
    gbyk_v4b_B.Constant1[i] = gbyk_v4b_P.Statusbits_Y0[i];
  }

  /* End of VirtualOutportStart for Outport: '<S223>/Status bits' */
  /* End of Start for SubSystem: '<S67>/Data receive' */

  /* Start for Constant: '<S230>/Arm Orientation' */
  gbyk_v4b_B.ArmOrientation_b = gbyk_v4b_P.ArmOrientation_Value;

  /* Start for Constant: '<S230>/Arm Secondary Encoders' */
  gbyk_v4b_B.HasSecondaryEnc_n = gbyk_v4b_P.ArmSecondaryEncoders_Value;

  /* Start for Constant: '<S231>/Arm Orientation' */
  gbyk_v4b_B.ArmOrientation_l = gbyk_v4b_P.ArmOrientation_Value_p;

  /* Start for Constant: '<S231>/Arm Secondary Encoders' */
  gbyk_v4b_B.HasSecondaryEnc_f = gbyk_v4b_P.ArmSecondaryEncoders_Value_h;

  /* Start for Enabled SubSystem: '<S66>/read_pmac' */
  gbyk_v4b_read_pmac_Start();

  /* End of Start for SubSystem: '<S66>/read_pmac' */

  /* Start for Constant: '<S230>/Arm robot type' */
  gbyk_v4b_B.robottype_e = gbyk_v4b_P.Armrobottype_Value;

  /* Start for Constant: '<S230>/Arm robot version' */
  gbyk_v4b_B.robotversion_g = gbyk_v4b_P.Armrobotversion_Value;

  /* Start for Constant: '<S231>/Arm robot type' */
  gbyk_v4b_B.robottype_cs = gbyk_v4b_P.Armrobottype_Value_m;

  /* Start for Constant: '<S231>/Arm robot version' */
  gbyk_v4b_B.robotversion_f = gbyk_v4b_P.Armrobotversion_Value_b;

  /* Start for DataStoreMemory: '<S34>/ECAT Digital in' */
  for (i = 0; i < 8; i++) {
    gbyk_v4b_DW.ECATDigitalInput[i] = gbyk_v4b_P.ECATDigitalin_InitialValue[i];
  }

  /* End of Start for DataStoreMemory: '<S34>/ECAT Digital in' */

  /* Start for DataStoreMemory: '<S34>/ECAT Err Msgs' */
  memcpy(&gbyk_v4b_DW.ECATErrMsgs[0], &gbyk_v4b_P.ECATErrMsgs_InitialValue[0],
         20U * sizeof(real_T));

  /* Start for DataStoreMemory: '<S34>/ECATTorque feedback' */
  memcpy(&gbyk_v4b_DW.ECATExtraData[0],
         &gbyk_v4b_P.ECATTorquefeedback_InitialValue[0], sizeof(real_T) << 3U);

  /* Start for DataStoreMemory: '<S34>/HW Settings' */
  memcpy(&gbyk_v4b_DW.HardwareSettings[0], &gbyk_v4b_P.HWSettings_InitialValue[0],
         24U * sizeof(real_T));

  /* Start for DataStoreMemory: '<S34>/Kinematics' */
  memcpy(&gbyk_v4b_DW.Kinematics[0], &gbyk_v4b_P.Kinematics_InitialValue[0], 20U
         * sizeof(real_T));

  /* Start for DataStoreMemory: '<S34>/PrimaryEnc' */
  memcpy(&gbyk_v4b_DW.PrimaryEncoderData[0],
         &gbyk_v4b_P.PrimaryEnc_InitialValue[0], 12U * sizeof(real_T));

  /* Start for DataStoreMemory: '<S34>/Robot Calib' */
  memcpy(&gbyk_v4b_DW.RobotCalibrations[0], &gbyk_v4b_P.RobotCalib_InitialValue
         [0], sizeof(real_T) << 4U);

  /* Start for DataStoreMemory: '<S34>/RobotRevision' */
  gbyk_v4b_DW.RobotRevision[0] = gbyk_v4b_P.RobotRevision_InitialValue[0];
  gbyk_v4b_DW.RobotRevision[1] = gbyk_v4b_P.RobotRevision_InitialValue[1];

  /* Start for DataStoreMemory: '<S34>/ServoUpdate' */
  gbyk_v4b_DW.ServoUpdate = gbyk_v4b_P.ServoUpdate_InitialValue;

  /* Start for DataStoreMemory: '<S34>/System status' */
  for (i = 0; i < 7; i++) {
    gbyk_v4b_DW.SystemStatus[i] = gbyk_v4b_P.Systemstatus_InitialValue[i];
  }

  /* End of Start for DataStoreMemory: '<S34>/System status' */

  /* Start for DataStoreMemory: '<S34>/calib button' */
  gbyk_v4b_DW.CalibrationButton = gbyk_v4b_P.calibbutton_InitialValue;

  /* Start for DataStoreMemory: '<S34>/delays' */
  gbyk_v4b_DW.DelayEstimates[0] = gbyk_v4b_P.delays_InitialValue[0];
  gbyk_v4b_DW.DelayEstimates[1] = gbyk_v4b_P.delays_InitialValue[1];
  gbyk_v4b_DW.DelayEstimates[2] = gbyk_v4b_P.delays_InitialValue[2];
  gbyk_v4b_DW.DelayEstimates[3] = gbyk_v4b_P.delays_InitialValue[3];

  /* Start for DataStoreMemory: '<S34>/has FT sensors' */
  gbyk_v4b_DW.ArmForceSensors[0] = gbyk_v4b_P.hasFTsensors_InitialValue[0];
  gbyk_v4b_DW.ArmForceSensors[1] = gbyk_v4b_P.hasFTsensors_InitialValue[1];
}

/* Outputs for atomic system: '<S4>/Poll KINARM' */
void gbyk_v4b_PollKINARM(void)
{
  uint32_T drive1;
  uint32_T drive2;
  uint32_T drive3;
  uint32_T drive4;
  int32_T status[8];
  uint16_T StatusWord;
  uint16_T ControlWord;
  int32_T b_ii;
  static const uint16_T ignorable_emcys[4] = { 0U, 10U, 65312U, 33072U };

  boolean_T exitg1;
  real_T ticksPerRad;
  static const uint16_T ignorable_emcys_0[4] = { 0U, 10U, 65312U, 33072U };

  real_T r1Calibs[8];
  real_T r2Calibs[8];
  real_T r1SettingsOut[12];
  real_T r2SettingsOut[12];
  real_T anglesPrimary[4];
  real_T queueSizePrimary;
  real_T queueSizeSecondary;
  real_T secondaryShoElb[4];
  real_T primaryShoElbVel[4];
  real_T r1SecondaryKinematicsOut[10];
  real_T r2SecondaryKinematicsOut[10];
  real_T r1PrimaryKinematicsOut[10];
  real_T r2PrimaryKinematicsOut[10];
  real_T b[3];
  int32_T i;
  static const int16_T tmp[24] = { 12032, 12032, 12032, 12032, 12032, 12032,
    12032, 12961, 12961, 12961, 12961, 12961, 1, 2, 3, 4, 5, 6, 7, 1, 2, 3, 4, 5
  };

  static const int16_T tmp_0[24] = { 12033, 12033, 12033, 12033, 12033, 12033,
    12033, 12033, 12033, 12033, 12033, 12033, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11,
    12 };

  real_T anglesPrimary_0[4];
  real_T b_data[200];
  int32_T b_sizes[2];
  real_T tmp_data[400];
  int32_T tmp_sizes[2];
  int32_T tmp_sizes_0[2];
  int32_T tmp_sizes_1[2];
  int32_T tmp_sizes_2[2];
  real_T tmp_data_0[200];
  int32_T tmp_sizes_3[2];
  int32_T ii_sizes_idx_1;
  uint64_T tmp_1;

  {
    /* user code (Output function Header) */
    {
      int32_T data[6]= { 0 };

      int32_T ecatStatus;
      int32_T minPauseBeforeReadMicroSec = ECAT_MIN_PAUSE_BEFORE_READ_US;
      int32_T DCInitState;
      if (gbyk_v4b_DW.BKINEtherCATinit1_DWORK1) {
        /*------------ S-Function Block: <S64>/BKIN EtherCATinit1 Write Process Data ,Run Admin Tasks and then Write Acyclic Data------------*/
        xpcEtherCATWriteProcessData(1,NULL);
        xpcEtherCATExecAdminJobs(1);
        xpcEtherCATWriteAcyclicData(1);
        mwErrorGet((int_T)1,
                   &data[0], &data[1], &data[2], &data[3],&data[4],&data[5]);
        memcpy(&gbyk_v4b_B.BKINEtherCATinit1_o1[0], data,6*sizeof(int32_T));
        mwErrorClear( (int_T)1 );

        // Clear all momentary triggered values
        gbyk_v4b_DW.BKINEtherCATinit1_DWORK4 = xpcGetElapsedTime(NULL);
        ecatStatus = data[1];
        DCInitState = data[4];
        if (ecatStatus == ECAT_PREOP_STATE && DCInitState == 0) {
          gbyk_v4b_DW.BKINEtherCATinit1_DWORK3 = true;
        } else {
          gbyk_v4b_DW.BKINEtherCATinit1_DWORK3 = false;
        }

        if (gbyk_v4b_P.activation_Value[0] == ECAT_OP_PAUSE_TEST && ecatStatus ==
            ECAT_OP_STATE) {
          minPauseBeforeReadMicroSec = gbyk_v4b_P.activation_Value[1];
        }

        if (!gbyk_v4b_DW.BKINEtherCATinit1_DWORK3) {
          xpcBusyWait(minPauseBeforeReadMicroSec * 1e-6);
          xpcEtherCATReadProcessData(1,NULL);
        }
      }
    }

    {
      int32_T data[6]= { 0 };

      int32_T ecatStatus;
      int32_T minPauseBeforeReadMicroSec = ECAT_MIN_PAUSE_BEFORE_READ_US;
      int32_T DCInitState;
      if (gbyk_v4b_DW.BKINEtherCATinit_DWORK1) {
        /*------------ S-Function Block: <S64>/BKIN EtherCATinit Write Process Data ,Run Admin Tasks and then Write Acyclic Data------------*/
        xpcEtherCATWriteProcessData(0,NULL);
        xpcEtherCATExecAdminJobs(0);
        xpcEtherCATWriteAcyclicData(0);
        mwErrorGet((int_T)0,
                   &data[0], &data[1], &data[2], &data[3],&data[4],&data[5]);
        memcpy(&gbyk_v4b_B.BKINEtherCATinit_o1[0], data,6*sizeof(int32_T));
        mwErrorClear( (int_T)0 );

        // Clear all momentary triggered values
        gbyk_v4b_DW.BKINEtherCATinit_DWORK4 = xpcGetElapsedTime(NULL);
        ecatStatus = data[1];
        DCInitState = data[4];
        if (ecatStatus == ECAT_PREOP_STATE && DCInitState == 0) {
          gbyk_v4b_DW.BKINEtherCATinit_DWORK3 = true;
        } else {
          gbyk_v4b_DW.BKINEtherCATinit_DWORK3 = false;
        }

        if (gbyk_v4b_P.activation_Value[0] == ECAT_OP_PAUSE_TEST && ecatStatus ==
            ECAT_OP_STATE) {
          minPauseBeforeReadMicroSec = gbyk_v4b_P.activation_Value[1];
        }

        if (!gbyk_v4b_DW.BKINEtherCATinit_DWORK3) {
          xpcBusyWait(minPauseBeforeReadMicroSec * 1e-6);
          xpcEtherCATReadProcessData(0,NULL);
        }
      }
    }

    /* MATLAB Function: '<S64>/sdo_addrs' */
    for (i = 0; i < 24; i++) {
      gbyk_v4b_B.intAddresses[i] = tmp[i];
      gbyk_v4b_B.floatAddresses[i] = tmp_0[i];
    }

    /* End of MATLAB Function: '<S64>/sdo_addrs' */

    /* DataTypeConversion: '<S64>/Data Type Conversion' */
    /* MATLAB Function 'EtherCAT Subsystem/sdo_addrs': '<S82>:1' */
    /*  %(0x2F00)  User Int - KINARM Lab Serial Number */
    /*  %(0x2F00)  User Int - KINARM Robot PN */
    /*  %(0x2F00)  User Int - KINARM Robot Rev */
    /*  %(0x2F00)  User Int - KINARM Robot Options */
    /*  %(0x2F00)  User Int -  Primary encoder resolution (quad-counts per motor revolution) */
    /*  %(0x2F00)  User Int -  secondary encoder resolution (quad-counts per robot axis revolution) */
    /*  %(0x2F00)  User Int - secondary encoder fundamental counts/revolution (I think this is needed for MMA) */
    /*  %(0x32A1)  User Int - Has the robot been calibrated (0 = no; 1 = yes) */
    /*  %(0x32A1)  User Int - L1 calibration angle offset (milli radians) */
    /*  %(0x32A1)  User Int - L2 calibration angle offset (milli radians) */
    /*  %(0x32A1)  User Int - L1 calibration angle offset (milli radians) for primary encoders */
    /*  %(0x32A1)  User Int - L2 calibration angle offset (milli radians) for primary encoders */
    /* '<S82>:1:3' */
    /*  %(0x2F01)  User float - Force Sensor Angle Offset (radians) */
    /*  %(0x2F01)  User float -  L1 Calibration pin angle (radians) (i.e. angle when calibration pin or block is in place; global coordinates) */
    /*  %(0x2F01)  User float -  L2 Calibration pin angle (radians) */
    /*  %(0x2F01)  User float -  L1 Absolute angle offset (radians) (i.e. angle of absolute encoder zero (i.e. index marking) relative to zero in global coordinates) */
    /*  %(0x2F01)  User float - L2 Absolute angle offset (radians) */
    /*  %(0x2F01)  User float - L1 Link length (m) - (For Exo, L1 is not stored) */
    /*  %(0x2F01)  User float - L2 Link length (m) - (For Exo, L2 is distance to calibration pin (IF THE UTS HAS ONE) */
    /*  %(0x2F01)  User float -  L2 Calibration pin offset (m) - Exo only (IF THE UTS HAS ONE) */
    /*  %(0x2F01)  User float - Motor1 actual_continuous_torque (Nm) */
    /*  %(0x2F01)  User float - Motor2 actual_continuous_torque (Nm) */
    /*  %(0x2F01)  User float - M1 Gear ratio */
    /*  %(0x2F01)  User float -  M2 Gear ratio */
    /* '<S82>:1:19' */
    gbyk_v4b_B.DataTypeConversion_h = gbyk_v4b_B.Convert20;

    /* Switch: '<S64>/Switch' incorporates:
     *  Constant: '<S64>/activation'
     */
    for (i = 0; i < 6; i++) {
      if (gbyk_v4b_P.activation_Value[1] >= gbyk_v4b_P.Switch_Threshold_b) {
        gbyk_v4b_B.Switch_m[i] = gbyk_v4b_B.BKINEtherCATinit1_o1[i];
      } else {
        gbyk_v4b_B.Switch_m[i] = gbyk_v4b_B.BKINEtherCATinit_o1[i];
      }
    }

    if (gbyk_v4b_P.activation_Value[1] >= gbyk_v4b_P.Switch_Threshold_b) {
      gbyk_v4b_B.Switch_m[6] = gbyk_v4b_B.BKINEtherCATinit1_o2;
      gbyk_v4b_B.Switch_m[7] = gbyk_v4b_B.BKINEtherCATinit1_o3;
    } else {
      gbyk_v4b_B.Switch_m[6] = gbyk_v4b_B.BKINEtherCATinit_o2;
      gbyk_v4b_B.Switch_m[7] = gbyk_v4b_B.BKINEtherCATinit_o3;
    }

    /* End of Switch: '<S64>/Switch' */

    /* MATLAB Function: '<S80>/split init' */
    /* MATLAB Function 'EtherCAT Subsystem/Init to Bus/split init': '<S192>:1' */
    /* '<S192>:1:4' */
    gbyk_v4b_B.errVal = gbyk_v4b_B.Switch_m[0];

    /* '<S192>:1:5' */
    gbyk_v4b_B.masterState = gbyk_v4b_B.Switch_m[1];

    /* '<S192>:1:6' */
    gbyk_v4b_B.DCErrVal = gbyk_v4b_B.Switch_m[2];

    /* '<S192>:1:7' */
    gbyk_v4b_B.MasterToNetworkClkDiff = gbyk_v4b_B.Switch_m[3];

    /* '<S192>:1:8' */
    gbyk_v4b_B.DCInitState = gbyk_v4b_B.Switch_m[4];

    /* '<S192>:1:9' */
    gbyk_v4b_B.NetworkToSlaveClkDiff = gbyk_v4b_B.Switch_m[5];

    /* MATLAB Function: '<S64>/setState' */
    /* MATLAB Function 'EtherCAT Subsystem/setState': '<S83>:1' */
    /* '<S83>:1:3' */
    /*  Cyclic command: working counter error.  */
    /*  This error occurs if the EtherCAT network is broken AFTER the first slave */
    /* '<S83>:1:5' */
    /*  Not all slave devices are in operational state when receiving cyclic frames.  */
    /*  This error occurs if the EtherCAT network is broken BEFORE the first slave */
    /* '<S83>:1:8' */
    gbyk_v4b_B.motorEnableState = true;

    /*  default */
    if ((gbyk_v4b_B.masterState == 8) && ((gbyk_v4b_B.errVal == 65537) ||
         (gbyk_v4b_B.errVal == 65551))) {
      /* '<S83>:1:10' */
      /* '<S83>:1:11' */
      /* '<S83>:1:12' */
      gbyk_v4b_B.motorEnableState = false;
    }

    /* End of MATLAB Function: '<S64>/setState' */

    /* Constant: '<S34>/system type' */
    gbyk_v4b_B.systemtype = gbyk_v4b_P.systemtype_Value;

    /* RelationalOperator: '<S71>/Compare' incorporates:
     *  Constant: '<S71>/Constant'
     */
    gbyk_v4b_B.Compare_n = (gbyk_v4b_B.systemtype == gbyk_v4b_P.isecat_const);

    /* Outputs for Enabled SubSystem: '<S64>/Arm 1' incorporates:
     *  EnablePort: '<S75>/Enable'
     */
    if (gbyk_v4b_B.Compare_n) {
      if (!gbyk_v4b_DW.Arm1_MODE) {
        gbyk_v4b_DW.Arm1_MODE = true;
      }

      /* Constant: '<S75>/Torque Mode' */
      gbyk_v4b_B.TorqueMode_i = gbyk_v4b_P.TorqueMode_Value;

      /* Level2 S-Function Block: '<S75>/BKIN EtherCAT PDO Transmit ' (BKINethercatpdotx) */
      {
        SimStruct *rts = gbyk_v4b_M->childSfunctions[10];
        sfcnOutputs(rts, 1);
      }

      /* Level2 S-Function Block: '<S75>/BKIN EtherCAT PDO Transmit 1' (BKINethercatpdotx) */
      {
        SimStruct *rts = gbyk_v4b_M->childSfunctions[11];
        sfcnOutputs(rts, 1);
      }

      /* Outputs for Atomic SubSystem: '<S85>/A1M1 PDOs' */

      /* Level2 S-Function Block: '<S99>/BKIN PDO Receive ElmoDrive' (BKINethercatpdorxElmoDrive) */
      {
        SimStruct *rts = gbyk_v4b_M->childSfunctions[8];
        sfcnOutputs(rts, 1);
      }

      /* DataTypeConversion: '<S99>/Data Type Conversion1' */
      gbyk_v4b_B.DataTypeConversion1_j1 = gbyk_v4b_B.torque_ky;

      /* DataTypeConversion: '<S99>/A1M1Convert' */
      gbyk_v4b_B.A1M1Convert[0] = gbyk_v4b_B.primaryposition_l;
      gbyk_v4b_B.A1M1Convert[1] = gbyk_v4b_B.secondaryposition_n;
      gbyk_v4b_B.A1M1Convert[2] = gbyk_v4b_B.primaryvelocity_d;
      gbyk_v4b_B.A1M1Convert[3] = gbyk_v4b_B.DataTypeConversion1_j1;
      gbyk_v4b_B.A1M1Convert[4] = gbyk_v4b_B.digitalinputs_j;

      /* MATLAB Function: '<S99>/parse status register' */
      gbyk_v4b_parsestatusregister(gbyk_v4b_B.statusregister_c4,
        &gbyk_v4b_B.sf_parsestatusregister);

      /* End of Outputs for SubSystem: '<S85>/A1M1 PDOs' */

      /* Outputs for Atomic SubSystem: '<S85>/EMCY Message pump' */
      gbyk_v4b_EMCYMessagepump();

      /* End of Outputs for SubSystem: '<S85>/EMCY Message pump' */

      /* RelationalOperator: '<S100>/Compare' incorporates:
       *  Constant: '<S100>/Constant'
       */
      gbyk_v4b_B.Compare_g = (gbyk_v4b_B.masterState ==
        gbyk_v4b_P.CompareToConstant_const_m);

      /* Memory: '<S85>/Memory' */
      gbyk_v4b_B.Memory_j = gbyk_v4b_DW.Memory_PreviousInput_g;

      /* Memory: '<S86>/Memory' */
      gbyk_v4b_B.Memory_f = gbyk_v4b_DW.Memory_PreviousInput_pv;

      /* MATLAB Function: '<S75>/forceEnableDisable' incorporates:
       *  Constant: '<S64>/max errors to fault'
       *  Constant: '<S75>/enableMotors'
       */
      gbyk_v4b_forceEnableDisable(gbyk_v4b_P.enableMotors_Value,
        gbyk_v4b_B.DataTypeConversion_h, gbyk_v4b_B.Memory,
        gbyk_v4b_B.motorEnableState, gbyk_v4b_B.Memory_j, gbyk_v4b_B.Memory_f,
        gbyk_v4b_P.maxerrorstofault_Value, &gbyk_v4b_B.sf_forceEnableDisable,
        &gbyk_v4b_DW.sf_forceEnableDisable);

      /* MATLAB Function: '<S85>/Control GDC Whistle State' incorporates:
       *  Constant: '<S64>/max errors to fault'
       */
      /* MATLAB Function 'EtherCAT Subsystem/Arm 1/A1M1/Control GDC Whistle State': '<S101>:1' */
      /*  This function outputs the appropriate ControlWord to control the state of the Elmo Drive. */
      /*  Need to decide why I would want Disabled state vs Ready to switch on state. */
      /*  TODO - deal with faults "better" */
      if (!gbyk_v4b_DW.permFaulted_not_empty_n) {
        /* '<S101>:1:8' */
        gbyk_v4b_DW.permFaulted_not_empty_n = true;

        /* '<S101>:1:12' */
        gbyk_v4b_DW.lastEStopState_n =
          gbyk_v4b_B.sf_parsestatusregister.eStopOut;
      }

      /*  Define the value of the StatusWord for different states of the Elmo drive.  */
      /*  Taken from the EtherCAT CoE Usage.xls from Elmo.  */
      /*  bit 9 = 1, because the Elmo drive is always in Remote mode, but I don't look at it. */
      /*  bit 4 = 1, because the voltage should be enabled */
      /*  bits 0-3, 6 define the state */
      /*  unclear on bits 10 and higher */
      /*  hex2dec('50'); */
      /*  hex2dec('31'); */
      /*  hex2dec('33');		% NOTE: We don't really need this state with the Elmo drive in Torque Mode */
      /*  hex2dec('37');		% Although we operate in this state, we don't actual need to query it */
      /*  hex2dec('18');		 */
      /*  Define the value of the ControlWord for different transitions */
      /*  Equal to transitions 7, 9 or 10 */
      /*  Technically this is just the "shutdown" transition. Equal to transitions 2, 6 or 8 */
      /*  Transition 3. As per SwitchedOn, we don't really need this one. */
      /*  Combines transitions 3 and 4 together = 0xF */
      /*  Transitions 15 together = 0x80 */
      /*  Mask the StatusWord input to bits 0-7 */
      /* '<S101>:1:36' */
      StatusWord = (uint16_T)(gbyk_v4b_B.Statusword_k & 127);

      /*  127 = 0x7F */
      /* '<S101>:1:38' */
      gbyk_v4b_B.motorStatus_f = 2U;

      /* motor is not working (red) */
      if ((!(gbyk_v4b_B.sf_parsestatusregister.faultFound != 0U)) &&
          (gbyk_v4b_B.sf_parsestatusregister.allOK != 0U)) {
        /* '<S101>:1:39' */
        if (gbyk_v4b_B.sf_parsestatusregister.motorOn != 0U) {
          /* '<S101>:1:41' */
          gbyk_v4b_B.motorStatus_f = 0U;

          /* motor is working (green) */
        } else {
          /* '<S101>:1:43' */
          gbyk_v4b_B.motorStatus_f = 1U;

          /* motor is ready to work (yellow) */
        }
      }

      /* 0xff20 */
      /* 0xff10 */
      /* 0x8130 */
      /* 10 is a current limit */
      /* '<S101>:1:52' */
      i = 0;
      ii_sizes_idx_1 = 1;
      b_ii = 1;
      exitg1 = false;
      while ((!exitg1) && (b_ii < 5)) {
        ticksPerRad = gbyk_v4b_B.sf_faultmonitor1.EMCYMsg[2];
        if (ignorable_emcys[b_ii - 1] == ticksPerRad) {
          i = 1;
          exitg1 = true;
        } else {
          b_ii++;
        }
      }

      if (i == 0) {
        ii_sizes_idx_1 = 0;
      }

      /* '<S101>:1:53' */
      if ((gbyk_v4b_B.sf_faultmonitor1.EMCYMsg[2] != 0.0) && (!!(ii_sizes_idx_1 ==
            0))) {
        /* '<S101>:1:55' */
        if (gbyk_v4b_B.sf_faultmonitor1.EMCYMsg[2] == 65296.0) {
          /* '<S101>:1:56' */
          if (gbyk_v4b_B.sf_parsestatusregister.eStopOut == 0U) {
            /* '<S101>:1:57' */
            /* if the estops are not pressed but we couldn't start then we are truly faulted */
            /* '<S101>:1:58' */
            gbyk_v4b_DW.permFaulted_l = 1.0;
          }
        } else {
          /* '<S101>:1:61' */
          gbyk_v4b_DW.permFaulted_l = 1.0;
        }
      }

      /* is the amp is reporting it is working we can reset our count of faults */
      if (StatusWord == 55) {
        /* '<S101>:1:66' */
        /* '<S101>:1:67' */
        gbyk_v4b_DW.countFaultSteps_d = 0.0;
      }

      /* '<S101>:1:70' */
      ControlWord = 0U;
      if (StatusWord == 24) {
        /* '<S101>:1:72' */
        /* Only when the amp is ready to go can we try to enable it. Otherwise */
        /* we will flood the slrt stdout and slrt will CPU overload. */
        if ((gbyk_v4b_B.sf_parsestatusregister.ampStatus == 0U) &&
            (gbyk_v4b_DW.permFaulted_l == 0.0) &&
            (gbyk_v4b_B.sf_parsestatusregister.eStopOut == 0U) &&
            gbyk_v4b_B.Compare_g) {
          /* '<S101>:1:75' */
          /*  change to the Disabled state if faulted */
          /* '<S101>:1:77' */
          ControlWord = 128U;

          /* if eStops == 0 %the emergency stops are not engaged, i.e. we can run with forces */
          /* '<S101>:1:79' */
          gbyk_v4b_DW.countFaultSteps_d++;

          /* when the emergency stop is released we get a few rounds where */
          /* there are faults. If we get lots of rounds where there are */
          /* faults then the motor is truly in a bad state and we should */
          /* not continue to ask it to start up. If we continue to ask then */
          /* we can get CPU overloads from all the MBX errors */
          if (gbyk_v4b_DW.countFaultSteps_d > gbyk_v4b_P.maxerrorstofault_Value)
          {
            /* '<S101>:1:85' */
            /* '<S101>:1:86' */
            gbyk_v4b_DW.permFaulted_l = 1.0;
          }

          /*  end */
        } else {
          /* '<S101>:1:90' */
        }
      } else if ((StatusWord == 80) &&
                 (gbyk_v4b_B.sf_forceEnableDisable.forceMotorState != 0.0)) {
        /* '<S101>:1:92' */
        /*  change to the Ready to Switch On state if in the Switch On Disabled state AND enable has been requested */
        /* '<S101>:1:94' */
        ControlWord = 6U;
      } else {
        if (gbyk_v4b_B.sf_forceEnableDisable.forceMotorState != 0.0) {
          /* '<S101>:1:95' */
          /*  change to the Enabled state if in the Ready to Switch on state AND enable had been requested */
          /* '<S101>:1:97' */
          ControlWord = 15U;
        }
      }

      /* If the estop was hit while a task was running that generates a fault. When */
      /* the task is reset then later you disable the estop we need to try to clear */
      /* the error. */
      if ((ControlWord == 0) && (gbyk_v4b_B.sf_parsestatusregister.faultFound !=
           0U) && (!(gbyk_v4b_B.sf_parsestatusregister.eStopOut != 0U)) &&
          (gbyk_v4b_DW.lastEStopState_n != 0U)) {
        /* '<S101>:1:103' */
        /* '<S101>:1:104' */
        gbyk_v4b_DW.frameCounter_e = 0.0;
      }

      /* this code is trying to clear any faults found at start-up */
      /* 4khz * 3s - it takes ~1.8s to reach the op state and we need to do this after that */
      if ((gbyk_v4b_DW.frameCounter_e < 12000.0) &&
          (gbyk_v4b_B.sf_parsestatusregister.allOK != 0U) &&
          (gbyk_v4b_B.sf_parsestatusregister.ampStatus == 0U) &&
          (!(gbyk_v4b_DW.permFaulted_l != 0.0)) &&
          (!(gbyk_v4b_B.sf_parsestatusregister.eStopOut != 0U)) &&
          gbyk_v4b_B.Compare_g && (gbyk_v4b_B.sf_parsestatusregister.faultFound
           != 0U)) {
        /* '<S101>:1:109' */
        if (StatusWord == 80) {
          /* '<S101>:1:110' */
          /* '<S101>:1:111' */
          ControlWord = 6U;
        } else {
          if (StatusWord == 49) {
            /* '<S101>:1:112' */
            /* the only way to clear an error is to enable the drive. This should */
            /* enable the drive very briefly. The forces should still be off */
            /* though since they are controlled by the run state of the drive. */
            /* '<S101>:1:116' */
            ControlWord = 15U;
          }
        }
      }

      /* '<S101>:1:120' */
      gbyk_v4b_DW.lastEStopState_n = gbyk_v4b_B.sf_parsestatusregister.eStopOut;

      /* '<S101>:1:121' */
      gbyk_v4b_DW.frameCounter_e++;

      /* '<S101>:1:122' */
      gbyk_v4b_B.isPermFaulted_i = gbyk_v4b_DW.permFaulted_l;
      gbyk_v4b_B.ControlWord_o = ControlWord;

      /* End of MATLAB Function: '<S85>/Control GDC Whistle State' */

      /* Level2 S-Function Block: '<S85>/BKIN EtherCAT PDO Transmit ' (BKINethercatpdotx) */
      {
        SimStruct *rts = gbyk_v4b_M->childSfunctions[12];
        sfcnOutputs(rts, 1);
      }

      /* Constant: '<S75>/readTrigger' */
      gbyk_v4b_B.readTrigger_k = gbyk_v4b_P.readTrigger_Value;

      /* MATLAB Function: '<S75>/size' */
      gbyk_v4b_size(&gbyk_v4b_B.sf_size);

      /* Memory: '<S94>/Memory' */
      gbyk_v4b_B.Memory_d3 = gbyk_v4b_DW.Memory_PreviousInput_pn;

      /* MATLAB Function: '<S75>/size1' */
      gbyk_v4b_size(&gbyk_v4b_B.sf_size1);

      /* Memory: '<S94>/Memory1' */
      gbyk_v4b_B.Memory1_o = gbyk_v4b_DW.Memory1_PreviousInput_i;

      /* Memory: '<S94>/Memory2' */
      gbyk_v4b_B.Memory2_n = gbyk_v4b_DW.Memory2_PreviousInput_p;

      /* Chart: '<S75>/SDO read machine' */
      gbyk_v4b_SDOreadmachine(gbyk_v4b_B.readTrigger_k, gbyk_v4b_B.intAddresses,
        gbyk_v4b_B.sf_size.count, gbyk_v4b_B.Memory_d3,
        gbyk_v4b_B.floatAddresses, gbyk_v4b_B.sf_size1.count,
        gbyk_v4b_B.Memory1_o, gbyk_v4b_B.Memory2_n,
        &gbyk_v4b_B.sf_SDOreadmachine, &gbyk_v4b_DW.sf_SDOreadmachine);

      /* MATLAB Function: '<S75>/split out constants' */
      /* MATLAB Function 'EtherCAT Subsystem/Arm 1/split out constants': '<S97>:1' */
      /* '<S97>:1:3' */
      gbyk_v4b_B.encoderCounts_h[0] = 0.0;
      gbyk_v4b_B.encoderCounts_h[1] = 0.0;

      /* '<S97>:1:4' */
      gbyk_v4b_B.calibPinAngles_m[0] = 0.0;
      gbyk_v4b_B.calibPinAngles_m[1] = 0.0;

      /* '<S97>:1:5' */
      gbyk_v4b_B.absAngOffsets_c[0] = 0.0;
      gbyk_v4b_B.absAngOffsets_c[1] = 0.0;

      /* '<S97>:1:6' */
      gbyk_v4b_B.linkLengths_j[0] = 0.0;
      gbyk_v4b_B.linkLengths_j[1] = 0.0;

      /* '<S97>:1:7' */
      gbyk_v4b_B.L2CalibPinOffset_c = 0.0;

      /* '<S97>:1:8' */
      gbyk_v4b_B.continuousTorques_j[0] = 0.0;
      gbyk_v4b_B.continuousTorques_j[1] = 0.0;

      /* '<S97>:1:9' */
      gbyk_v4b_B.gearRatios_p[0] = 0.0;
      gbyk_v4b_B.gearRatios_p[1] = 0.0;

      /* '<S97>:1:10' */
      gbyk_v4b_B.offsetRads_f[0] = 0.0;
      gbyk_v4b_B.offsetRads_f[1] = 0.0;

      /* '<S97>:1:11' */
      gbyk_v4b_B.offsetRadsPrimary_h[0] = 0.0;
      gbyk_v4b_B.offsetRadsPrimary_h[1] = 0.0;

      /* '<S97>:1:12' */
      gbyk_v4b_B.isCalibrated_p = 0.0;

      /* '<S97>:1:13' */
      gbyk_v4b_B.FTSensorOffset_j = 0.0;

      /* '<S97>:1:14' */
      gbyk_v4b_B.robotRevision_n = 0.0;

      /* '<S97>:1:16' */
      gbyk_v4b_B.constantsReady_j = gbyk_v4b_B.sf_SDOreadmachine.complete;
      if (gbyk_v4b_B.sf_SDOreadmachine.complete != 0) {
        /* '<S97>:1:22' */
        gbyk_v4b_B.encoderCounts_h[0] =
          gbyk_v4b_B.sf_SDOreadmachine.intSDOValues[4];
        gbyk_v4b_B.encoderCounts_h[1] =
          gbyk_v4b_B.sf_SDOreadmachine.intSDOValues[5];

        /* '<S97>:1:24' */
        gbyk_v4b_B.isCalibrated_p = gbyk_v4b_B.sf_SDOreadmachine.intSDOValues[7];

        /* '<S97>:1:25' */
        gbyk_v4b_B.offsetRads_f[0] = (real_T)
          gbyk_v4b_B.sf_SDOreadmachine.intSDOValues[8] / 1000.0;
        gbyk_v4b_B.offsetRads_f[1] = (real_T)
          gbyk_v4b_B.sf_SDOreadmachine.intSDOValues[9] / 1000.0;

        /* '<S97>:1:26' */
        gbyk_v4b_B.offsetRadsPrimary_h[0] = (real_T)
          gbyk_v4b_B.sf_SDOreadmachine.intSDOValues[10] / 1000.0;
        gbyk_v4b_B.offsetRadsPrimary_h[1] = (real_T)
          gbyk_v4b_B.sf_SDOreadmachine.intSDOValues[11] / 1000.0;

        /* '<S97>:1:28' */
        gbyk_v4b_B.FTSensorOffset_j =
          gbyk_v4b_B.sf_SDOreadmachine.floatSDOValues[0];

        /* '<S97>:1:29' */
        gbyk_v4b_B.calibPinAngles_m[0] =
          gbyk_v4b_B.sf_SDOreadmachine.floatSDOValues[1];
        gbyk_v4b_B.calibPinAngles_m[1] =
          gbyk_v4b_B.sf_SDOreadmachine.floatSDOValues[2];

        /* '<S97>:1:30' */
        gbyk_v4b_B.absAngOffsets_c[0] =
          gbyk_v4b_B.sf_SDOreadmachine.floatSDOValues[3];
        gbyk_v4b_B.absAngOffsets_c[1] =
          gbyk_v4b_B.sf_SDOreadmachine.floatSDOValues[4];

        /* '<S97>:1:31' */
        gbyk_v4b_B.linkLengths_j[0] =
          gbyk_v4b_B.sf_SDOreadmachine.floatSDOValues[5];
        gbyk_v4b_B.linkLengths_j[1] =
          gbyk_v4b_B.sf_SDOreadmachine.floatSDOValues[6];

        /* '<S97>:1:32' */
        gbyk_v4b_B.L2CalibPinOffset_c =
          gbyk_v4b_B.sf_SDOreadmachine.floatSDOValues[7];

        /* '<S97>:1:33' */
        gbyk_v4b_B.continuousTorques_j[0] =
          gbyk_v4b_B.sf_SDOreadmachine.floatSDOValues[8];
        gbyk_v4b_B.continuousTorques_j[1] =
          gbyk_v4b_B.sf_SDOreadmachine.floatSDOValues[9];

        /* '<S97>:1:34' */
        gbyk_v4b_B.gearRatios_p[0] =
          gbyk_v4b_B.sf_SDOreadmachine.floatSDOValues[10];
        gbyk_v4b_B.gearRatios_p[1] =
          gbyk_v4b_B.sf_SDOreadmachine.floatSDOValues[11];

        /* '<S97>:1:35' */
        gbyk_v4b_B.robotRevision_n = gbyk_v4b_B.sf_SDOreadmachine.intSDOValues[2];
      } else {
        /* '<S97>:1:18' */
      }

      /* End of MATLAB Function: '<S75>/split out constants' */

      /* Selector: '<S103>/L2 select' incorporates:
       *  Constant: '<S85>/MotorIdx'
       */
      gbyk_v4b_B.L2select_i = gbyk_v4b_B.offsetRads_f[(int32_T)
        gbyk_v4b_P.MotorIdx_Value - 1];

      /* MATLAB Function: '<S75>/Find Robot type' incorporates:
       *  Constant: '<S64>/ep part nums'
       *  Constant: '<S64>/nhp part nums'
       */
      gbyk_v4b_FindRobottype(gbyk_v4b_B.sf_SDOreadmachine.intSDOValues,
        gbyk_v4b_P.eppartnums_Value, gbyk_v4b_P.nhppartnums_Value,
        &gbyk_v4b_B.sf_FindRobottype);

      /* MATLAB Function: '<S75>/split out constants1' incorporates:
       *  Constant: '<S64>/force primary only'
       */
      gbyk_v4b_splitoutconstants1(gbyk_v4b_B.sf_SDOreadmachine.intSDOValues,
        gbyk_v4b_P.forceprimaryonly_Value, gbyk_v4b_B.sf_FindRobottype.robotType,
        &gbyk_v4b_B.sf_splitoutconstants1);

      /* Selector: '<S103>/L2 select1' incorporates:
       *  Constant: '<S85>/MotorIdx'
       */
      gbyk_v4b_B.L2select1_h = gbyk_v4b_B.sf_splitoutconstants1.encOrientation
        [(int32_T)gbyk_v4b_P.MotorIdx_Value - 1];

      /* Selector: '<S103>/L2 select2' incorporates:
       *  Constant: '<S85>/MotorIdx'
       */
      gbyk_v4b_B.L2select2_o =
        gbyk_v4b_B.sf_splitoutconstants1.motorOrientation[(int32_T)
        gbyk_v4b_P.MotorIdx_Value - 1];

      /* Selector: '<S103>/L2 select3' incorporates:
       *  Constant: '<S85>/MotorIdx'
       */
      gbyk_v4b_B.L2select3_cn = gbyk_v4b_B.offsetRadsPrimary_h[(int32_T)
        gbyk_v4b_P.MotorIdx_Value - 1];

      /* Selector: '<S103>/L2 select4' incorporates:
       *  Constant: '<S85>/MotorIdx'
       */
      gbyk_v4b_B.L2select4_o = gbyk_v4b_B.gearRatios_p[(int32_T)
        gbyk_v4b_P.MotorIdx_Value - 1];

      /* Memory: '<S75>/Memory2' */
      gbyk_v4b_B.R1_maxContinuousTorque[0] =
        gbyk_v4b_DW.Memory2_PreviousInput_i[0];
      gbyk_v4b_B.R1_maxContinuousTorque[1] =
        gbyk_v4b_DW.Memory2_PreviousInput_i[1];

      /* Selector: '<S103>/L2 select5' incorporates:
       *  Constant: '<S85>/MotorIdx'
       */
      gbyk_v4b_B.L2select5_c = gbyk_v4b_B.R1_maxContinuousTorque[(int32_T)
        gbyk_v4b_P.MotorIdx_Value - 1];

      /* Memory: '<S75>/Memory3' */
      gbyk_v4b_B.R1_constantsReady = gbyk_v4b_DW.Memory3_PreviousInput_l;

      /* MATLAB Function: '<S103>/countsToRads' */
      /* MATLAB Function 'EtherCAT Subsystem/Arm 1/A1M1/PDO to Angles Subsystem/countsToRads': '<S111>:1' */
      /* '<S111>:1:3' */
      /* '<S111>:1:4' */
      gbyk_v4b_B.digitalDiagnostics_e = gbyk_v4b_B.A1M1Convert[4];

      /* The CR (command reference) manual says that */
      /* Digital inputs 5 and 6 are at bits 20 and 21 */
      /* '<S111>:1:7' */
      ticksPerRad = rt_roundd_snf((real_T)((uint64_T)rt_roundd_snf
        (gbyk_v4b_B.A1M1Convert[4]) >> 20ULL));
      if (ticksPerRad < 1.8446744073709552E+19) {
        if (ticksPerRad >= 0.0) {
          tmp_1 = (uint64_T)ticksPerRad;
        } else {
          tmp_1 = 0ULL;
        }
      } else {
        tmp_1 = MAX_uint64_T;
      }

      gbyk_v4b_B.digitalInputs_e[0] = (real_T)(tmp_1 & 1ULL);
      ticksPerRad = rt_roundd_snf((real_T)((uint64_T)rt_roundd_snf
        (gbyk_v4b_B.A1M1Convert[4]) >> 21ULL));
      if (ticksPerRad < 1.8446744073709552E+19) {
        if (ticksPerRad >= 0.0) {
          tmp_1 = (uint64_T)ticksPerRad;
        } else {
          tmp_1 = 0ULL;
        }
      } else {
        tmp_1 = MAX_uint64_T;
      }

      gbyk_v4b_B.digitalInputs_e[1] = (real_T)(tmp_1 & 1ULL);

      /* '<S111>:1:8' */
      ticksPerRad = rt_roundd_snf((real_T)((uint64_T)rt_roundd_snf
        (gbyk_v4b_B.A1M1Convert[4]) >> 16ULL));
      if (ticksPerRad < 1.8446744073709552E+19) {
        if (ticksPerRad >= 0.0) {
          tmp_1 = (uint64_T)ticksPerRad;
        } else {
          tmp_1 = 0ULL;
        }
      } else {
        tmp_1 = MAX_uint64_T;
      }

      gbyk_v4b_B.calibrationButton_e = (real_T)(tmp_1 & 1ULL);
      if (gbyk_v4b_B.R1_constantsReady != 1.0) {
        /* '<S111>:1:10' */
        /* '<S111>:1:11' */
        gbyk_v4b_B.LinkAngle_c = 0.0;

        /* '<S111>:1:12' */
        gbyk_v4b_B.PrimaryLinkVel_m = 0.0;

        /* '<S111>:1:13' */
        gbyk_v4b_B.PrimaryLinkAngle_m = 0.0;

        /* '<S111>:1:14' */
        ticksPerRad = 0.0;
      } else {
        if (gbyk_v4b_B.sf_splitoutconstants1.hasSecondary != 0.0) {
          /* '<S111>:1:38' */
          /* '<S111>:1:39' */
          /* '<S111>:1:40' */
          /* '<S111>:1:19' */
          gbyk_v4b_B.LinkAngle_c = gbyk_v4b_B.A1M1Convert[1] /
            (gbyk_v4b_B.encoderCounts_h[1] / 6.2831853071795862) *
            -gbyk_v4b_B.L2select1_h + gbyk_v4b_B.L2select_i;
        } else {
          /* '<S111>:1:38' */
          /* '<S111>:1:39' */
          /* '<S111>:1:40' */
          /* '<S111>:1:21' */
          gbyk_v4b_B.LinkAngle_c = gbyk_v4b_B.A1M1Convert[0] /
            (gbyk_v4b_B.encoderCounts_h[0] * gbyk_v4b_B.L2select4_o /
             6.2831853071795862) * gbyk_v4b_B.L2select2_o +
            gbyk_v4b_B.L2select3_cn;
        }

        /* '<S111>:1:38' */
        ticksPerRad = gbyk_v4b_B.encoderCounts_h[0] * gbyk_v4b_B.L2select4_o /
          6.2831853071795862;

        /* '<S111>:1:39' */
        /* '<S111>:1:40' */
        /* '<S111>:1:24' */
        gbyk_v4b_B.PrimaryLinkAngle_m = gbyk_v4b_B.A1M1Convert[0] / ticksPerRad *
          gbyk_v4b_B.L2select2_o + gbyk_v4b_B.L2select3_cn;

        /* '<S111>:1:24' */
        gbyk_v4b_B.PrimaryLinkVel_m = gbyk_v4b_B.A1M1Convert[2] / ticksPerRad *
          gbyk_v4b_B.L2select2_o;

        /* '<S111>:1:25' */
        ticksPerRad = gbyk_v4b_B.A1M1Convert[3] / 1000.0 *
          gbyk_v4b_B.L2select5_c * gbyk_v4b_B.L2select4_o *
          gbyk_v4b_B.L2select2_o;

        /* I had to follow this around for a while to figure out why this is */
        /* required. There I think are 2 reasons: 1) the robot orientation I */
        /* calculate for ECAT is "backwards" (i.e. it is arm orientation) 2) if */
        /* you look at the apply loads blocks there is a reversal there as well. */
        /* '<S111>:1:31' */
        if (gbyk_v4b_B.sf_FindRobottype.robotType == 1.0) {
          /* '<S111>:1:32' */
          /* '<S111>:1:33' */
          ticksPerRad = -ticksPerRad;
        }
      }

      gbyk_v4b_B.torque_d = ticksPerRad;

      /* End of MATLAB Function: '<S103>/countsToRads' */

      /* Outputs for Atomic SubSystem: '<S86>/A1M2 PDOs' */

      /* Level2 S-Function Block: '<S112>/BKIN PDO Receive ElmoDrive' (BKINethercatpdorxElmoDrive) */
      {
        SimStruct *rts = gbyk_v4b_M->childSfunctions[9];
        sfcnOutputs(rts, 1);
      }

      /* DataTypeConversion: '<S112>/Data Type Conversion' */
      gbyk_v4b_B.DataTypeConversion_em = gbyk_v4b_B.torque_h;

      /* DataTypeConversion: '<S112>/A1M2Convert' */
      gbyk_v4b_B.A1M2Convert[0] = gbyk_v4b_B.primaryposition_e;
      gbyk_v4b_B.A1M2Convert[1] = gbyk_v4b_B.secondaryposition_d;
      gbyk_v4b_B.A1M2Convert[2] = gbyk_v4b_B.primaryvelocity_p;
      gbyk_v4b_B.A1M2Convert[3] = gbyk_v4b_B.DataTypeConversion_em;
      gbyk_v4b_B.A1M2Convert[4] = gbyk_v4b_B.digitalinputs;

      /* MATLAB Function: '<S112>/parse status register1' */
      gbyk_v4b_parsestatusregister(gbyk_v4b_B.statusregister_c,
        &gbyk_v4b_B.sf_parsestatusregister1);

      /* End of Outputs for SubSystem: '<S86>/A1M2 PDOs' */

      /* Outputs for Atomic SubSystem: '<S86>/EMCY Message pump' */
      gbyk_v4b_EMCYMessagepump_o();

      /* End of Outputs for SubSystem: '<S86>/EMCY Message pump' */

      /* RelationalOperator: '<S113>/Compare' incorporates:
       *  Constant: '<S113>/Constant'
       */
      gbyk_v4b_B.Compare_h = (gbyk_v4b_B.masterState == gbyk_v4b_P.Compare_const);

      /* MATLAB Function: '<S86>/Control GDC Whistle State' incorporates:
       *  Constant: '<S64>/max errors to fault'
       */
      gbyk_v4b_ControlGDCWhistleState(gbyk_v4b_B.Statusword_b,
        gbyk_v4b_B.sf_parsestatusregister1.allOK,
        gbyk_v4b_B.sf_parsestatusregister1.motorOn,
        gbyk_v4b_B.sf_parsestatusregister1.ampStatus,
        gbyk_v4b_B.sf_parsestatusregister1.faultFound,
        gbyk_v4b_B.sf_parsestatusregister1.eStopOut,
        gbyk_v4b_B.sf_faultmonitor1_l.EMCYMsg[2], gbyk_v4b_B.Compare_h,
        gbyk_v4b_B.sf_forceEnableDisable.forceMotorState,
        gbyk_v4b_P.maxerrorstofault_Value,
        &gbyk_v4b_B.sf_ControlGDCWhistleState_f,
        &gbyk_v4b_DW.sf_ControlGDCWhistleState_f);

      /* Level2 S-Function Block: '<S86>/BKIN EtherCAT PDO Transmit ' (BKINethercatpdotx) */
      {
        SimStruct *rts = gbyk_v4b_M->childSfunctions[13];
        sfcnOutputs(rts, 1);
      }

      /* Selector: '<S116>/L2 select' incorporates:
       *  Constant: '<S86>/MotorIdx'
       */
      gbyk_v4b_B.L2select_e = gbyk_v4b_B.offsetRads_f[(int32_T)
        gbyk_v4b_P.MotorIdx_Value_n - 1];

      /* Selector: '<S116>/L2 select1' incorporates:
       *  Constant: '<S86>/MotorIdx'
       */
      gbyk_v4b_B.L2select1_hf = gbyk_v4b_B.sf_splitoutconstants1.encOrientation
        [(int32_T)gbyk_v4b_P.MotorIdx_Value_n - 1];

      /* Selector: '<S116>/L2 select2' incorporates:
       *  Constant: '<S86>/MotorIdx'
       */
      gbyk_v4b_B.L2select2_d =
        gbyk_v4b_B.sf_splitoutconstants1.motorOrientation[(int32_T)
        gbyk_v4b_P.MotorIdx_Value_n - 1];

      /* Selector: '<S116>/L2 select3' incorporates:
       *  Constant: '<S86>/MotorIdx'
       */
      gbyk_v4b_B.L2select3_p = gbyk_v4b_B.offsetRadsPrimary_h[(int32_T)
        gbyk_v4b_P.MotorIdx_Value_n - 1];

      /* Selector: '<S116>/L2 select4' incorporates:
       *  Constant: '<S86>/MotorIdx'
       */
      gbyk_v4b_B.L2select4_g = gbyk_v4b_B.gearRatios_p[(int32_T)
        gbyk_v4b_P.MotorIdx_Value_n - 1];

      /* Selector: '<S116>/L2 select5' incorporates:
       *  Constant: '<S86>/MotorIdx'
       */
      gbyk_v4b_B.L2select5_f = gbyk_v4b_B.R1_maxContinuousTorque[(int32_T)
        gbyk_v4b_P.MotorIdx_Value_n - 1];

      /* MATLAB Function: '<S116>/countsToRads' */
      /* MATLAB Function 'EtherCAT Subsystem/Arm 1/A1M2/PDO to Angles Subsystem/countsToRads': '<S124>:1' */
      /* '<S124>:1:4' */
      /* '<S124>:1:5' */
      gbyk_v4b_B.digitalDiagnostics_a = gbyk_v4b_B.A1M2Convert[4];

      /* The CR (command reference) manual says that */
      /* Digital inputs 5 and 6 are at bits 20 and 21 */
      /* '<S124>:1:8' */
      ticksPerRad = rt_roundd_snf((real_T)((uint64_T)rt_roundd_snf
        (gbyk_v4b_B.A1M2Convert[4]) >> 20ULL));
      if (ticksPerRad < 1.8446744073709552E+19) {
        if (ticksPerRad >= 0.0) {
          tmp_1 = (uint64_T)ticksPerRad;
        } else {
          tmp_1 = 0ULL;
        }
      } else {
        tmp_1 = MAX_uint64_T;
      }

      gbyk_v4b_B.digitalInputs_h[0] = (real_T)(tmp_1 & 1ULL);
      ticksPerRad = rt_roundd_snf((real_T)((uint64_T)rt_roundd_snf
        (gbyk_v4b_B.A1M2Convert[4]) >> 21ULL));
      if (ticksPerRad < 1.8446744073709552E+19) {
        if (ticksPerRad >= 0.0) {
          tmp_1 = (uint64_T)ticksPerRad;
        } else {
          tmp_1 = 0ULL;
        }
      } else {
        tmp_1 = MAX_uint64_T;
      }

      gbyk_v4b_B.digitalInputs_h[1] = (real_T)(tmp_1 & 1ULL);
      if (gbyk_v4b_B.R1_constantsReady != 1.0) {
        /* '<S124>:1:10' */
        /* '<S124>:1:11' */
        gbyk_v4b_B.LinkAngle_g = 0.0;

        /* '<S124>:1:12' */
        gbyk_v4b_B.PrimaryLinkVel_d = 0.0;

        /* '<S124>:1:13' */
        gbyk_v4b_B.PrimaryLinkAngle_b = 0.0;

        /* '<S124>:1:14' */
        ticksPerRad = 0.0;
      } else {
        if (gbyk_v4b_B.sf_splitoutconstants1.hasSecondary != 0.0) {
          /* '<S124>:1:38' */
          /* '<S124>:1:39' */
          /* '<S124>:1:40' */
          /* '<S124>:1:19' */
          gbyk_v4b_B.LinkAngle_g = gbyk_v4b_B.A1M2Convert[1] /
            (gbyk_v4b_B.encoderCounts_h[1] / 6.2831853071795862) *
            -gbyk_v4b_B.L2select1_hf + gbyk_v4b_B.L2select_e;
        } else {
          /* '<S124>:1:38' */
          /* '<S124>:1:39' */
          /* '<S124>:1:40' */
          /* '<S124>:1:21' */
          gbyk_v4b_B.LinkAngle_g = gbyk_v4b_B.A1M2Convert[0] /
            (gbyk_v4b_B.encoderCounts_h[0] * gbyk_v4b_B.L2select4_g /
             6.2831853071795862) * gbyk_v4b_B.L2select2_d +
            gbyk_v4b_B.L2select3_p;
        }

        /* '<S124>:1:38' */
        ticksPerRad = gbyk_v4b_B.encoderCounts_h[0] * gbyk_v4b_B.L2select4_g /
          6.2831853071795862;

        /* '<S124>:1:39' */
        /* '<S124>:1:40' */
        /* '<S124>:1:24' */
        gbyk_v4b_B.PrimaryLinkAngle_b = gbyk_v4b_B.A1M2Convert[0] / ticksPerRad *
          gbyk_v4b_B.L2select2_d + gbyk_v4b_B.L2select3_p;

        /* '<S124>:1:24' */
        gbyk_v4b_B.PrimaryLinkVel_d = gbyk_v4b_B.A1M2Convert[2] / ticksPerRad *
          gbyk_v4b_B.L2select2_d;

        /* '<S124>:1:25' */
        ticksPerRad = gbyk_v4b_B.A1M2Convert[3] / 1000.0 *
          gbyk_v4b_B.L2select5_f * gbyk_v4b_B.L2select4_g *
          gbyk_v4b_B.L2select2_d;

        /* I had to follow this around for a while to figure out why this is */
        /* required. There I think are 2 reasons: 1) the robot orientation I */
        /* calculate for ECAT is "backwards" (i.e. it is arm orientation) 2) if */
        /* you look at the apply loads blocks there is a reversal there as well. */
        /* '<S124>:1:31' */
        if (gbyk_v4b_B.sf_FindRobottype.robotType == 1.0) {
          /* '<S124>:1:32' */
          /* '<S124>:1:33' */
          ticksPerRad = -ticksPerRad;
        }
      }

      gbyk_v4b_B.torque_g = ticksPerRad;

      /* End of MATLAB Function: '<S116>/countsToRads' */

      /* SignalConversion: '<S75>/Signal Conversion' */
      gbyk_v4b_B.R1M1_LinkAngle = gbyk_v4b_B.LinkAngle_c;

      /* SignalConversion: '<S75>/Signal Conversion' */
      gbyk_v4b_B.R1M2_LinkAngle = gbyk_v4b_B.LinkAngle_g;

      /* SignalConversion: '<S75>/Signal Conversion' */
      gbyk_v4b_B.R1M2_PrimaryLinkAngle = gbyk_v4b_B.PrimaryLinkAngle_b;

      /* SignalConversion: '<S75>/Signal Conversion' */
      gbyk_v4b_B.R1M2_PrimaryLinkVelocity = gbyk_v4b_B.PrimaryLinkVel_d;

      /* SignalConversion: '<S75>/Signal Conversion' */
      gbyk_v4b_B.R1M2_RecordedTorque = gbyk_v4b_B.torque_g;

      /* SignalConversion: '<S75>/Signal Conversion' */
      gbyk_v4b_B.R1M2_digitalInputs[0] = gbyk_v4b_B.digitalInputs_h[0];
      gbyk_v4b_B.R1M2_digitalInputs[1] = gbyk_v4b_B.digitalInputs_h[1];

      /* SignalConversion: '<S75>/Signal Conversion' */
      gbyk_v4b_B.R1M2_digitalDiagnostics = gbyk_v4b_B.digitalDiagnostics_a;

      /* SignalConversion: '<S75>/Signal Conversion' */
      gbyk_v4b_B.R1M2_CurrentLimitEnabled =
        gbyk_v4b_B.sf_parsestatusregister1.currentLimitEnabled;

      /* SignalConversion: '<S75>/Signal Conversion' */
      gbyk_v4b_B.R1M1_PrimaryLinkAngle = gbyk_v4b_B.PrimaryLinkAngle_m;

      /* SignalConversion: '<S75>/Signal Conversion' */
      gbyk_v4b_B.R1M1_PrimaryLinkVelocity = gbyk_v4b_B.PrimaryLinkVel_m;

      /* SignalConversion: '<S75>/Signal Conversion' */
      gbyk_v4b_B.R1M1_RecordedTorque = gbyk_v4b_B.torque_d;

      /* SignalConversion: '<S75>/Signal Conversion' */
      gbyk_v4b_B.R1M1_digitalInputs[0] = gbyk_v4b_B.digitalInputs_e[0];
      gbyk_v4b_B.R1M1_digitalInputs[1] = gbyk_v4b_B.digitalInputs_e[1];

      /* SignalConversion: '<S75>/Signal Conversion' */
      gbyk_v4b_B.R1M1_digitalDiagnostics = gbyk_v4b_B.digitalDiagnostics_e;

      /* SignalConversion: '<S75>/Signal Conversion' */
      gbyk_v4b_B.R1_calibrationButton = gbyk_v4b_B.calibrationButton_e;
      for (i = 0; i < 5; i++) {
        /* SignalConversion: '<S75>/Signal Conversion' */
        gbyk_v4b_B.R1M2_EMCY_codes[i] = gbyk_v4b_B.sf_faultmonitor1_l.EMCYMsg[i];

        /* SignalConversion: '<S75>/Signal Conversion' */
        gbyk_v4b_B.R1M1_EMCY_codes[i] = gbyk_v4b_B.sf_faultmonitor1.EMCYMsg[i];
      }

      /* SignalConversion: '<S75>/Signal Conversion' */
      gbyk_v4b_B.R1M1_CurrentLimitEnabled =
        gbyk_v4b_B.sf_parsestatusregister.currentLimitEnabled;

      /* SignalConversion: '<S75>/Signal Conversion1' */
      gbyk_v4b_B.R1_RobotType = gbyk_v4b_B.sf_FindRobottype.robotType;

      /* SignalConversion: '<S75>/Signal Conversion1' */
      gbyk_v4b_B.R1_absAngleOffset[0] = gbyk_v4b_B.absAngOffsets_c[0];
      gbyk_v4b_B.R1_absAngleOffset[1] = gbyk_v4b_B.absAngOffsets_c[1];

      /* SignalConversion: '<S75>/Signal Conversion1' */
      gbyk_v4b_B.R1_LinkLength[0] = gbyk_v4b_B.linkLengths_j[0];
      gbyk_v4b_B.R1_LinkLength[1] = gbyk_v4b_B.linkLengths_j[1];

      /* SignalConversion: '<S75>/Signal Conversion1' */
      gbyk_v4b_B.R1_L2CalibPinOffset = gbyk_v4b_B.L2CalibPinOffset_c;

      /* SignalConversion: '<S75>/Signal Conversion1' */
      gbyk_v4b_B.R1_maxContinuousTorque_d[0] =
        gbyk_v4b_B.R1_maxContinuousTorque[0];
      gbyk_v4b_B.R1_maxContinuousTorque_d[1] =
        gbyk_v4b_B.R1_maxContinuousTorque[1];

      /* SignalConversion: '<S75>/Signal Conversion1' */
      gbyk_v4b_B.R1_gearRatios[0] = gbyk_v4b_B.gearRatios_p[0];
      gbyk_v4b_B.R1_gearRatios[1] = gbyk_v4b_B.gearRatios_p[1];

      /* SignalConversion: '<S75>/Signal Conversion1' */
      gbyk_v4b_B.R1_isCalibrated = gbyk_v4b_B.isCalibrated_p;

      /* SignalConversion: '<S75>/Signal Conversion1' */
      gbyk_v4b_B.R1_OffsetRads[0] = gbyk_v4b_B.offsetRads_f[0];
      gbyk_v4b_B.R1_OffsetRads[1] = gbyk_v4b_B.offsetRads_f[1];

      /* SignalConversion: '<S75>/Signal Conversion1' */
      gbyk_v4b_B.R1_OffsetRadsPrimary[0] = gbyk_v4b_B.offsetRadsPrimary_h[0];
      gbyk_v4b_B.R1_OffsetRadsPrimary[1] = gbyk_v4b_B.offsetRadsPrimary_h[1];

      /* SignalConversion: '<S75>/Signal Conversion1' */
      gbyk_v4b_B.R1_RobotRevision = gbyk_v4b_B.robotRevision_n;

      /* SignalConversion: '<S75>/Signal Conversion1' */
      gbyk_v4b_B.R1_constantsReady_p = gbyk_v4b_B.R1_constantsReady;

      /* SignalConversion: '<S75>/Signal Conversion1' */
      gbyk_v4b_B.R1_hasSecondary = gbyk_v4b_B.sf_splitoutconstants1.hasSecondary;

      /* SignalConversion: '<S75>/Signal Conversion1' */
      gbyk_v4b_B.R1_hasFT = gbyk_v4b_B.sf_splitoutconstants1.hasFT;

      /* SignalConversion: '<S75>/Signal Conversion1' */
      gbyk_v4b_B.R1_robotOrientation =
        gbyk_v4b_B.sf_splitoutconstants1.robotOrientation;

      /* SignalConversion: '<S75>/Signal Conversion1' */
      gbyk_v4b_B.R1_motorOrientation[0] =
        gbyk_v4b_B.sf_splitoutconstants1.motorOrientation[0];
      gbyk_v4b_B.R1_motorOrientation[1] =
        gbyk_v4b_B.sf_splitoutconstants1.motorOrientation[1];

      /* SignalConversion: '<S75>/Signal Conversion1' */
      gbyk_v4b_B.R1_encOrientation[0] =
        gbyk_v4b_B.sf_splitoutconstants1.encOrientation[0];
      gbyk_v4b_B.R1_encOrientation[1] =
        gbyk_v4b_B.sf_splitoutconstants1.encOrientation[1];

      /* SignalConversion: '<S75>/Signal Conversion1' */
      gbyk_v4b_B.R1_encodercounts[0] = gbyk_v4b_B.encoderCounts_h[0];
      gbyk_v4b_B.R1_encodercounts[1] = gbyk_v4b_B.encoderCounts_h[1];

      /* SignalConversion: '<S75>/Signal Conversion1' */
      gbyk_v4b_B.R1_FTSensorAngleOffset = gbyk_v4b_B.FTSensorOffset_j;

      /* SignalConversion: '<S75>/Signal Conversion1' */
      gbyk_v4b_B.R1_calibPinAngle[0] = gbyk_v4b_B.calibPinAngles_m[0];
      gbyk_v4b_B.R1_calibPinAngle[1] = gbyk_v4b_B.calibPinAngles_m[1];

      /* Outputs for Atomic SubSystem: '<S94>/Read Drive 1 SDO' */
      gbyk_v4b_ReadDrive1SDO_p();

      /* End of Outputs for SubSystem: '<S94>/Read Drive 1 SDO' */

      /* RateTransition: '<S94>/Rate Transition' */
      gbyk_v4b_B.RateTransition_bs = gbyk_v4b_B.sf_converter_p.int32Out;

      /* RateTransition: '<S94>/Rate Transition1' */
      gbyk_v4b_B.RateTransition1_ds = gbyk_v4b_B.sf_converter_p.doubleOut;

      /* RateTransition: '<S94>/Rate Transition2' */
      gbyk_v4b_B.RateTransition2_dj = gbyk_v4b_B.DataTypeConversion_f;

      /* Outputs for Enabled SubSystem: '<S75>/M1 AbsEnc Calibration' incorporates:
       *  EnablePort: '<S88>/Enable'
       */
      /* Constant: '<S75>/enableCalibration' */
      if (gbyk_v4b_P.enableCalibration_Value > 0.0) {
        if (!gbyk_v4b_DW.M1AbsEncCalibration_MODE_i) {
          /* InitializeConditions for Memory: '<S88>/Memory' */
          gbyk_v4b_DW.Memory_PreviousInput_hw = gbyk_v4b_P.Memory_X0_e;

          /* InitializeConditions for Memory: '<S88>/Memory1' */
          gbyk_v4b_DW.Memory1_PreviousInput_g[0] = gbyk_v4b_P.Memory1_X0_h;
          gbyk_v4b_DW.Memory1_PreviousInput_g[1] = gbyk_v4b_P.Memory1_X0_h;

          /* InitializeConditions for Chart: '<S88>/AbsEncoder machine' */
          gbyk_v4b_AbsEncodermachine_Init(&gbyk_v4b_B.sf_AbsEncodermachine,
            &gbyk_v4b_DW.sf_AbsEncodermachine);
          gbyk_v4b_DW.M1AbsEncCalibration_MODE_i = true;
        }

        /* MATLAB Function: '<S88>/set-up values' */
        gbyk_v4b_setupvalues(&gbyk_v4b_B.sf_setupvalues);

        /* Memory: '<S88>/Memory' */
        gbyk_v4b_B.Memory_c = gbyk_v4b_DW.Memory_PreviousInput_hw;

        /* Memory: '<S88>/Memory1' */
        gbyk_v4b_B.Memory1_b[0] = gbyk_v4b_DW.Memory1_PreviousInput_g[0];
        gbyk_v4b_B.Memory1_b[1] = gbyk_v4b_DW.Memory1_PreviousInput_g[1];

        /* Chart: '<S88>/AbsEncoder machine' */
        gbyk_v4b_AbsEncodermachine(gbyk_v4b_B.sf_setupvalues.setupValues,
          gbyk_v4b_B.sf_setupvalues.setupValuesCount,
          gbyk_v4b_B.sf_setupvalues.pollValues,
          gbyk_v4b_B.sf_setupvalues.encoderValues,
          gbyk_v4b_B.sf_setupvalues.encoderValuesCount, gbyk_v4b_B.Memory_c,
          gbyk_v4b_B.Memory1_b, &gbyk_v4b_B.sf_AbsEncodermachine,
          &gbyk_v4b_DW.sf_AbsEncodermachine);

        /* S-Function (BKINethercatasyncsdodownload): '<S88>/BKIN EtherCAT Async SDO Download' */
        {
          int8_T *sigInputPtr;
          int32_T *sigStatusPtr;
          int32_T *enInputPtr;
          int_T deviceIndex;
          int_T res;
          int_T state;
          int32_T *indexInputPtr;
          int32_T *subIndexInputPtr;
          deviceIndex = gbyk_v4b_DW.BKINEtherCATAsyncSDODownload_IWORK_j[0];
          if (deviceIndex != NO_ETHERCAT) {
            state = xpcEtherCATgetState( deviceIndex );
            if (state >= 2 ) {
              sigStatusPtr = &gbyk_v4b_B.BKINEtherCATAsyncSDODownload_i;
              sigInputPtr = &gbyk_v4b_B.sf_AbsEncodermachine.setupData[0];
              enInputPtr = &gbyk_v4b_B.sf_AbsEncodermachine.setupData[1];
              indexInputPtr = &gbyk_v4b_B.sf_AbsEncodermachine.setupData[2];
              subIndexInputPtr = &gbyk_v4b_B.sf_AbsEncodermachine.setupData[3];
              if (gbyk_v4b_DW.BKINEtherCATAsyncSDODownload_IWORK_j[7] != 0) {
                res = ecatAsyncSDODownload(deviceIndex,
                  1001,
                  (unsigned short)*indexInputPtr,
                  (unsigned char)*subIndexInputPtr,
                  (void *)sigInputPtr,
                  1*4,
                  500,
                  342971113,
                  sigStatusPtr,
                  *enInputPtr);
              } else {
                *sigStatusPtr = 0;
              }

              gbyk_v4b_DW.BKINEtherCATAsyncSDODownload_IWORK_j[7] = 1;
              ;
            }
          }
        }

        /* S-Function (BKINethercatasyncsdoupload): '<S88>/BKIN EtherCAT Async SDO Upload' */
        {
          int8_T *sigOutputPtr;
          int32_T *sigStatusPtr;
          int32_T *enInputPtr;
          int_T deviceIndex;
          static int counter= 0;
          int_T actLen;
          int_T res;
          int_T state;
          int32_T *indexInputPtr;
          int32_T *subIndexInputPtr;
          deviceIndex = gbyk_v4b_DW.BKINEtherCATAsyncSDOUpload_IWORK_h[0];
          if (deviceIndex != NO_ETHERCAT) {
            state = xpcEtherCATgetState( deviceIndex );
            if (state >= 2 ) {
              sigOutputPtr = &gbyk_v4b_B.BKINEtherCATAsyncSDOUpload_o1_p;
              sigStatusPtr = &gbyk_v4b_B.BKINEtherCATAsyncSDOUpload_o2_a;
              enInputPtr = &gbyk_v4b_B.sf_AbsEncodermachine.SDORequest[0];
              indexInputPtr = &gbyk_v4b_B.sf_AbsEncodermachine.SDORequest[1];
              subIndexInputPtr = &gbyk_v4b_B.sf_AbsEncodermachine.SDORequest[2];
              if (gbyk_v4b_DW.BKINEtherCATAsyncSDOUpload_IWORK_h[7] != 0) {
                res = ecatAsyncSDOUpload(deviceIndex,
                  1001,
                  (unsigned short)*indexInputPtr,
                  (unsigned char)*subIndexInputPtr,
                  (void *)sigOutputPtr,
                  1*4,
                  &actLen,
                  500,
                  342971114,
                  sigStatusPtr,
                  *enInputPtr);
              }

              gbyk_v4b_DW.BKINEtherCATAsyncSDOUpload_IWORK_h[7] = 1;
              ;
            }
          }
        }

        srUpdateBC(gbyk_v4b_DW.M1AbsEncCalibration_SubsysRanBC_h);
      } else {
        if (gbyk_v4b_DW.M1AbsEncCalibration_MODE_i) {
          gbyk_v4b_DW.M1AbsEncCalibration_MODE_i = false;
        }
      }

      /* End of Outputs for SubSystem: '<S75>/M1 AbsEnc Calibration' */

      /* Outputs for Enabled SubSystem: '<S75>/M2 AbsEnc Calibration' incorporates:
       *  EnablePort: '<S89>/Enable'
       */
      if (gbyk_v4b_P.enableCalibration_Value > 0.0) {
        if (!gbyk_v4b_DW.M2AbsEncCalibration_MODE_a) {
          /* InitializeConditions for Memory: '<S89>/Memory' */
          gbyk_v4b_DW.Memory_PreviousInput_i = gbyk_v4b_P.Memory_X0_gr;

          /* InitializeConditions for Memory: '<S89>/Memory1' */
          gbyk_v4b_DW.Memory1_PreviousInput_a[0] = gbyk_v4b_P.Memory1_X0_p;
          gbyk_v4b_DW.Memory1_PreviousInput_a[1] = gbyk_v4b_P.Memory1_X0_p;

          /* InitializeConditions for Chart: '<S89>/AbsEncoder machine' */
          gbyk_v4b_AbsEncodermachine_Init(&gbyk_v4b_B.sf_AbsEncodermachine_b,
            &gbyk_v4b_DW.sf_AbsEncodermachine_b);
          gbyk_v4b_DW.M2AbsEncCalibration_MODE_a = true;
        }

        /* MATLAB Function: '<S89>/set-up values' */
        gbyk_v4b_setupvalues(&gbyk_v4b_B.sf_setupvalues_p);

        /* Memory: '<S89>/Memory' */
        gbyk_v4b_B.Memory_n0 = gbyk_v4b_DW.Memory_PreviousInput_i;

        /* Memory: '<S89>/Memory1' */
        gbyk_v4b_B.Memory1_n[0] = gbyk_v4b_DW.Memory1_PreviousInput_a[0];
        gbyk_v4b_B.Memory1_n[1] = gbyk_v4b_DW.Memory1_PreviousInput_a[1];

        /* Chart: '<S89>/AbsEncoder machine' */
        gbyk_v4b_AbsEncodermachine(gbyk_v4b_B.sf_setupvalues_p.setupValues,
          gbyk_v4b_B.sf_setupvalues_p.setupValuesCount,
          gbyk_v4b_B.sf_setupvalues_p.pollValues,
          gbyk_v4b_B.sf_setupvalues_p.encoderValues,
          gbyk_v4b_B.sf_setupvalues_p.encoderValuesCount, gbyk_v4b_B.Memory_n0,
          gbyk_v4b_B.Memory1_n, &gbyk_v4b_B.sf_AbsEncodermachine_b,
          &gbyk_v4b_DW.sf_AbsEncodermachine_b);

        /* S-Function (BKINethercatasyncsdodownload): '<S89>/BKIN EtherCAT Async SDO Download' */
        {
          int8_T *sigInputPtr;
          int32_T *sigStatusPtr;
          int32_T *enInputPtr;
          int_T deviceIndex;
          int_T res;
          int_T state;
          int32_T *indexInputPtr;
          int32_T *subIndexInputPtr;
          deviceIndex = gbyk_v4b_DW.BKINEtherCATAsyncSDODownload_IWORK_a0[0];
          if (deviceIndex != NO_ETHERCAT) {
            state = xpcEtherCATgetState( deviceIndex );
            if (state >= 2 ) {
              sigStatusPtr = &gbyk_v4b_B.BKINEtherCATAsyncSDODownload_ce;
              sigInputPtr = &gbyk_v4b_B.sf_AbsEncodermachine_b.setupData[0];
              enInputPtr = &gbyk_v4b_B.sf_AbsEncodermachine_b.setupData[1];
              indexInputPtr = &gbyk_v4b_B.sf_AbsEncodermachine_b.setupData[2];
              subIndexInputPtr = &gbyk_v4b_B.sf_AbsEncodermachine_b.setupData[3];
              if (gbyk_v4b_DW.BKINEtherCATAsyncSDODownload_IWORK_a0[7] != 0) {
                res = ecatAsyncSDODownload(deviceIndex,
                  1002,
                  (unsigned short)*indexInputPtr,
                  (unsigned char)*subIndexInputPtr,
                  (void *)sigInputPtr,
                  1*4,
                  500,
                  342974267,
                  sigStatusPtr,
                  *enInputPtr);
              } else {
                *sigStatusPtr = 0;
              }

              gbyk_v4b_DW.BKINEtherCATAsyncSDODownload_IWORK_a0[7] = 1;
              ;
            }
          }
        }

        /* S-Function (BKINethercatasyncsdoupload): '<S89>/BKIN EtherCAT Async SDO Upload' */
        {
          int8_T *sigOutputPtr;
          int32_T *sigStatusPtr;
          int32_T *enInputPtr;
          int_T deviceIndex;
          static int counter= 0;
          int_T actLen;
          int_T res;
          int_T state;
          int32_T *indexInputPtr;
          int32_T *subIndexInputPtr;
          deviceIndex = gbyk_v4b_DW.BKINEtherCATAsyncSDOUpload_IWORK_f[0];
          if (deviceIndex != NO_ETHERCAT) {
            state = xpcEtherCATgetState( deviceIndex );
            if (state >= 2 ) {
              sigOutputPtr = &gbyk_v4b_B.BKINEtherCATAsyncSDOUpload_o1_dq;
              sigStatusPtr = &gbyk_v4b_B.BKINEtherCATAsyncSDOUpload_o2_m;
              enInputPtr = &gbyk_v4b_B.sf_AbsEncodermachine_b.SDORequest[0];
              indexInputPtr = &gbyk_v4b_B.sf_AbsEncodermachine_b.SDORequest[1];
              subIndexInputPtr = &gbyk_v4b_B.sf_AbsEncodermachine_b.SDORequest[2];
              if (gbyk_v4b_DW.BKINEtherCATAsyncSDOUpload_IWORK_f[7] != 0) {
                res = ecatAsyncSDOUpload(deviceIndex,
                  1002,
                  (unsigned short)*indexInputPtr,
                  (unsigned char)*subIndexInputPtr,
                  (void *)sigOutputPtr,
                  1*4,
                  &actLen,
                  500,
                  342974268,
                  sigStatusPtr,
                  *enInputPtr);
              }

              gbyk_v4b_DW.BKINEtherCATAsyncSDOUpload_IWORK_f[7] = 1;
              ;
            }
          }
        }

        srUpdateBC(gbyk_v4b_DW.M2AbsEncCalibration_SubsysRanBC_h);
      } else {
        if (gbyk_v4b_DW.M2AbsEncCalibration_MODE_a) {
          gbyk_v4b_DW.M2AbsEncCalibration_MODE_a = false;
        }
      }

      /* End of Constant: '<S75>/enableCalibration' */
      /* End of Outputs for SubSystem: '<S75>/M2 AbsEnc Calibration' */

      /* Outputs for Atomic SubSystem: '<S75>/SDO reading' */
      gbyk_v4b_SDOreading();

      /* End of Outputs for SubSystem: '<S75>/SDO reading' */

      /* Outputs for Atomic SubSystem: '<S75>/SDO writing' */
      gbyk_v4b_SDOwriting();

      /* End of Outputs for SubSystem: '<S75>/SDO writing' */
      srUpdateBC(gbyk_v4b_DW.Arm1_SubsysRanBC);
    } else {
      if (gbyk_v4b_DW.Arm1_MODE) {
        /* Disable for Enabled SubSystem: '<S75>/M1 AbsEnc Calibration' */
        if (gbyk_v4b_DW.M1AbsEncCalibration_MODE_i) {
          gbyk_v4b_DW.M1AbsEncCalibration_MODE_i = false;
        }

        /* End of Disable for SubSystem: '<S75>/M1 AbsEnc Calibration' */

        /* Disable for Enabled SubSystem: '<S75>/M2 AbsEnc Calibration' */
        if (gbyk_v4b_DW.M2AbsEncCalibration_MODE_a) {
          gbyk_v4b_DW.M2AbsEncCalibration_MODE_a = false;
        }

        /* End of Disable for SubSystem: '<S75>/M2 AbsEnc Calibration' */
        gbyk_v4b_DW.Arm1_MODE = false;
      }
    }

    /* End of Outputs for SubSystem: '<S64>/Arm 1' */

    /* Outputs for Enabled SubSystem: '<S64>/Arm 2' incorporates:
     *  EnablePort: '<S76>/Enable'
     */
    if (gbyk_v4b_B.Compare_n) {
      if (!gbyk_v4b_DW.Arm2_MODE) {
        gbyk_v4b_DW.Arm2_MODE = true;
      }

      /* Constant: '<S76>/Torque Mode' */
      gbyk_v4b_B.TorqueMode = gbyk_v4b_P.TorqueMode_Value_k;

      /* Level2 S-Function Block: '<S76>/BKIN EtherCAT PDO Transmit ' (BKINethercatpdotx) */
      {
        SimStruct *rts = gbyk_v4b_M->childSfunctions[16];
        sfcnOutputs(rts, 1);
      }

      /* Level2 S-Function Block: '<S76>/BKIN EtherCAT PDO Transmit 1' (BKINethercatpdotx) */
      {
        SimStruct *rts = gbyk_v4b_M->childSfunctions[17];
        sfcnOutputs(rts, 1);
      }

      /* Outputs for Atomic SubSystem: '<S137>/A2M1 PDOs' */
      gbyk_v4b_A2M1PDOs();

      /* End of Outputs for SubSystem: '<S137>/A2M1 PDOs' */

      /* Outputs for Atomic SubSystem: '<S137>/EMCY Message pump' */
      gbyk_v4b_EMCYMessagepump_o1();

      /* End of Outputs for SubSystem: '<S137>/EMCY Message pump' */

      /* RelationalOperator: '<S152>/Compare' incorporates:
       *  Constant: '<S152>/Constant'
       */
      gbyk_v4b_B.Compare_oe = (gbyk_v4b_B.masterState ==
        gbyk_v4b_P.Compare_const_b);

      /* Memory: '<S137>/Memory' */
      gbyk_v4b_B.Memory_m = gbyk_v4b_DW.Memory_PreviousInput_l;

      /* Memory: '<S138>/Memory' */
      gbyk_v4b_B.Memory_i = gbyk_v4b_DW.Memory_PreviousInput_h;

      /* MATLAB Function: '<S76>/forceEnableDisable' incorporates:
       *  Constant: '<S64>/max errors to fault'
       *  Constant: '<S76>/enableMotors'
       */
      gbyk_v4b_forceEnableDisable(gbyk_v4b_P.enableMotors_Value_c,
        gbyk_v4b_B.DataTypeConversion_h, gbyk_v4b_B.Memory,
        gbyk_v4b_B.motorEnableState, gbyk_v4b_B.Memory_m, gbyk_v4b_B.Memory_i,
        gbyk_v4b_P.maxerrorstofault_Value, &gbyk_v4b_B.sf_forceEnableDisable_k,
        &gbyk_v4b_DW.sf_forceEnableDisable_k);

      /* MATLAB Function: '<S137>/Control GDC Whistle State' incorporates:
       *  Constant: '<S64>/max errors to fault'
       */
      gbyk_v4b_ControlGDCWhistleState(gbyk_v4b_B.Statusword,
        gbyk_v4b_B.sf_parsestatusregister1_f.allOK,
        gbyk_v4b_B.sf_parsestatusregister1_f.motorOn,
        gbyk_v4b_B.sf_parsestatusregister1_f.ampStatus,
        gbyk_v4b_B.sf_parsestatusregister1_f.faultFound,
        gbyk_v4b_B.sf_parsestatusregister1_f.eStopOut,
        gbyk_v4b_B.sf_faultmonitor1_c.EMCYMsg[2], gbyk_v4b_B.Compare_oe,
        gbyk_v4b_B.sf_forceEnableDisable_k.forceMotorState,
        gbyk_v4b_P.maxerrorstofault_Value,
        &gbyk_v4b_B.sf_ControlGDCWhistleState_p,
        &gbyk_v4b_DW.sf_ControlGDCWhistleState_p);

      /* Level2 S-Function Block: '<S137>/BKIN EtherCAT PDO Transmit ' (BKINethercatpdotx) */
      {
        SimStruct *rts = gbyk_v4b_M->childSfunctions[18];
        sfcnOutputs(rts, 1);
      }

      /* Constant: '<S76>/readTrigger' */
      gbyk_v4b_B.readTrigger = gbyk_v4b_P.readTrigger_Value_l;

      /* MATLAB Function: '<S76>/size' */
      gbyk_v4b_size(&gbyk_v4b_B.sf_size_d);

      /* Memory: '<S146>/Memory' */
      gbyk_v4b_B.Memory_p = gbyk_v4b_DW.Memory_PreviousInput_b;

      /* MATLAB Function: '<S76>/size1' */
      gbyk_v4b_size(&gbyk_v4b_B.sf_size1_e);

      /* Memory: '<S146>/Memory1' */
      gbyk_v4b_B.Memory1_e = gbyk_v4b_DW.Memory1_PreviousInput_c;

      /* Memory: '<S146>/Memory2' */
      gbyk_v4b_B.Memory2 = gbyk_v4b_DW.Memory2_PreviousInput;

      /* Chart: '<S76>/SDO read machine' */
      gbyk_v4b_SDOreadmachine(gbyk_v4b_B.readTrigger, gbyk_v4b_B.intAddresses,
        gbyk_v4b_B.sf_size_d.count, gbyk_v4b_B.Memory_p,
        gbyk_v4b_B.floatAddresses, gbyk_v4b_B.sf_size1_e.count,
        gbyk_v4b_B.Memory1_e, gbyk_v4b_B.Memory2,
        &gbyk_v4b_B.sf_SDOreadmachine_h, &gbyk_v4b_DW.sf_SDOreadmachine_h);

      /* MATLAB Function: '<S76>/split out constants' */
      /* MATLAB Function 'EtherCAT Subsystem/Arm 2/split out constants': '<S149>:1' */
      /* '<S149>:1:3' */
      gbyk_v4b_B.encoderCounts[0] = 0.0;
      gbyk_v4b_B.encoderCounts[1] = 0.0;

      /* '<S149>:1:4' */
      gbyk_v4b_B.calibPinAngles[0] = 0.0;
      gbyk_v4b_B.calibPinAngles[1] = 0.0;

      /* '<S149>:1:5' */
      gbyk_v4b_B.absAngOffsets[0] = 0.0;
      gbyk_v4b_B.absAngOffsets[1] = 0.0;

      /* '<S149>:1:6' */
      gbyk_v4b_B.linkLengths[0] = 0.0;
      gbyk_v4b_B.linkLengths[1] = 0.0;

      /* '<S149>:1:7' */
      gbyk_v4b_B.L2CalibPinOffset = 0.0;

      /* '<S149>:1:8' */
      gbyk_v4b_B.continuousTorques[0] = 0.0;
      gbyk_v4b_B.continuousTorques[1] = 0.0;

      /* '<S149>:1:9' */
      gbyk_v4b_B.gearRatios[0] = 0.0;
      gbyk_v4b_B.gearRatios[1] = 0.0;

      /* '<S149>:1:10' */
      gbyk_v4b_B.offsetRads[0] = 0.0;
      gbyk_v4b_B.offsetRads[1] = 0.0;

      /* '<S149>:1:11' */
      gbyk_v4b_B.offsetRadsPrimary[0] = 0.0;
      gbyk_v4b_B.offsetRadsPrimary[1] = 0.0;

      /* '<S149>:1:12' */
      gbyk_v4b_B.isCalibrated = 0.0;

      /* '<S149>:1:13' */
      gbyk_v4b_B.FTSensorOffset = 0.0;

      /* '<S149>:1:14' */
      gbyk_v4b_B.robotRevision_o = 0.0;

      /* '<S149>:1:16' */
      gbyk_v4b_B.constantsReady = gbyk_v4b_B.sf_SDOreadmachine_h.complete;
      if (gbyk_v4b_B.sf_SDOreadmachine_h.complete != 0) {
        /* '<S149>:1:22' */
        gbyk_v4b_B.encoderCounts[0] =
          gbyk_v4b_B.sf_SDOreadmachine_h.intSDOValues[4];
        gbyk_v4b_B.encoderCounts[1] =
          gbyk_v4b_B.sf_SDOreadmachine_h.intSDOValues[5];

        /* '<S149>:1:24' */
        gbyk_v4b_B.isCalibrated = gbyk_v4b_B.sf_SDOreadmachine_h.intSDOValues[7];

        /* '<S149>:1:25' */
        gbyk_v4b_B.offsetRads[0] = (real_T)
          gbyk_v4b_B.sf_SDOreadmachine_h.intSDOValues[8] / 1000.0;
        gbyk_v4b_B.offsetRads[1] = (real_T)
          gbyk_v4b_B.sf_SDOreadmachine_h.intSDOValues[9] / 1000.0;

        /* '<S149>:1:26' */
        gbyk_v4b_B.offsetRadsPrimary[0] = (real_T)
          gbyk_v4b_B.sf_SDOreadmachine_h.intSDOValues[10] / 1000.0;
        gbyk_v4b_B.offsetRadsPrimary[1] = (real_T)
          gbyk_v4b_B.sf_SDOreadmachine_h.intSDOValues[11] / 1000.0;

        /* '<S149>:1:28' */
        gbyk_v4b_B.FTSensorOffset =
          gbyk_v4b_B.sf_SDOreadmachine_h.floatSDOValues[0];

        /* '<S149>:1:29' */
        gbyk_v4b_B.calibPinAngles[0] =
          gbyk_v4b_B.sf_SDOreadmachine_h.floatSDOValues[1];
        gbyk_v4b_B.calibPinAngles[1] =
          gbyk_v4b_B.sf_SDOreadmachine_h.floatSDOValues[2];

        /* '<S149>:1:30' */
        gbyk_v4b_B.absAngOffsets[0] =
          gbyk_v4b_B.sf_SDOreadmachine_h.floatSDOValues[3];
        gbyk_v4b_B.absAngOffsets[1] =
          gbyk_v4b_B.sf_SDOreadmachine_h.floatSDOValues[4];

        /* '<S149>:1:31' */
        gbyk_v4b_B.linkLengths[0] =
          gbyk_v4b_B.sf_SDOreadmachine_h.floatSDOValues[5];
        gbyk_v4b_B.linkLengths[1] =
          gbyk_v4b_B.sf_SDOreadmachine_h.floatSDOValues[6];

        /* '<S149>:1:32' */
        gbyk_v4b_B.L2CalibPinOffset =
          gbyk_v4b_B.sf_SDOreadmachine_h.floatSDOValues[7];

        /* '<S149>:1:33' */
        gbyk_v4b_B.continuousTorques[0] =
          gbyk_v4b_B.sf_SDOreadmachine_h.floatSDOValues[8];
        gbyk_v4b_B.continuousTorques[1] =
          gbyk_v4b_B.sf_SDOreadmachine_h.floatSDOValues[9];

        /* '<S149>:1:34' */
        gbyk_v4b_B.gearRatios[0] =
          gbyk_v4b_B.sf_SDOreadmachine_h.floatSDOValues[10];
        gbyk_v4b_B.gearRatios[1] =
          gbyk_v4b_B.sf_SDOreadmachine_h.floatSDOValues[11];

        /* '<S149>:1:35' */
        gbyk_v4b_B.robotRevision_o =
          gbyk_v4b_B.sf_SDOreadmachine_h.intSDOValues[2];
      } else {
        /* '<S149>:1:18' */
      }

      /* End of MATLAB Function: '<S76>/split out constants' */

      /* Selector: '<S155>/L2 select' incorporates:
       *  Constant: '<S137>/MotorIdx'
       */
      gbyk_v4b_B.offsetrads = gbyk_v4b_B.offsetRads[(int32_T)
        gbyk_v4b_P.MotorIdx_Value_d - 1];

      /* MATLAB Function: '<S76>/Find Robot type' incorporates:
       *  Constant: '<S64>/ep part nums'
       *  Constant: '<S64>/nhp part nums'
       */
      gbyk_v4b_FindRobottype(gbyk_v4b_B.sf_SDOreadmachine_h.intSDOValues,
        gbyk_v4b_P.eppartnums_Value, gbyk_v4b_P.nhppartnums_Value,
        &gbyk_v4b_B.sf_FindRobottype_d);

      /* MATLAB Function: '<S76>/split out constants1' incorporates:
       *  Constant: '<S64>/force primary only'
       */
      gbyk_v4b_splitoutconstants1(gbyk_v4b_B.sf_SDOreadmachine_h.intSDOValues,
        gbyk_v4b_P.forceprimaryonly_Value,
        gbyk_v4b_B.sf_FindRobottype_d.robotType,
        &gbyk_v4b_B.sf_splitoutconstants1_o);

      /* Selector: '<S155>/L2 select1' incorporates:
       *  Constant: '<S137>/MotorIdx'
       */
      gbyk_v4b_B.encorient = gbyk_v4b_B.sf_splitoutconstants1_o.encOrientation
        [(int32_T)gbyk_v4b_P.MotorIdx_Value_d - 1];

      /* Selector: '<S155>/L2 select2' incorporates:
       *  Constant: '<S137>/MotorIdx'
       */
      gbyk_v4b_B.L2select2 =
        gbyk_v4b_B.sf_splitoutconstants1_o.motorOrientation[(int32_T)
        gbyk_v4b_P.MotorIdx_Value_d - 1];

      /* Selector: '<S155>/L2 select3' incorporates:
       *  Constant: '<S137>/MotorIdx'
       */
      gbyk_v4b_B.L2select3 = gbyk_v4b_B.offsetRadsPrimary[(int32_T)
        gbyk_v4b_P.MotorIdx_Value_d - 1];

      /* Selector: '<S155>/L2 select4' incorporates:
       *  Constant: '<S137>/MotorIdx'
       */
      gbyk_v4b_B.L2select4 = gbyk_v4b_B.gearRatios[(int32_T)
        gbyk_v4b_P.MotorIdx_Value_d - 1];

      /* Memory: '<S76>/Memory2' */
      gbyk_v4b_B.R2_maxContinuousTorque[0] =
        gbyk_v4b_DW.Memory2_PreviousInput_n[0];
      gbyk_v4b_B.R2_maxContinuousTorque[1] =
        gbyk_v4b_DW.Memory2_PreviousInput_n[1];

      /* Selector: '<S155>/L2 select5' incorporates:
       *  Constant: '<S137>/MotorIdx'
       */
      gbyk_v4b_B.L2select5 = gbyk_v4b_B.R2_maxContinuousTorque[(int32_T)
        gbyk_v4b_P.MotorIdx_Value_d - 1];

      /* Memory: '<S76>/Memory3' */
      gbyk_v4b_B.R2_constantsReady = gbyk_v4b_DW.Memory3_PreviousInput;

      /* MATLAB Function: '<S155>/countsToRads' */
      /* MATLAB Function 'EtherCAT Subsystem/Arm 2/A2M1/PDO to Angles Subsystem/countsToRads': '<S163>:1' */
      /* '<S163>:1:3' */
      /* '<S163>:1:4' */
      gbyk_v4b_B.digitalDiagnostics_c = gbyk_v4b_B.A2M1Convert[4];

      /* The CR (command reference) manual says that */
      /* Digital inputs 5 and 6 are at bits 20 and 21 */
      /* '<S163>:1:8' */
      ticksPerRad = rt_roundd_snf((real_T)((uint64_T)rt_roundd_snf
        (gbyk_v4b_B.A2M1Convert[4]) >> 20ULL));
      if (ticksPerRad < 1.8446744073709552E+19) {
        if (ticksPerRad >= 0.0) {
          tmp_1 = (uint64_T)ticksPerRad;
        } else {
          tmp_1 = 0ULL;
        }
      } else {
        tmp_1 = MAX_uint64_T;
      }

      gbyk_v4b_B.digitalInputs_m[0] = (real_T)(tmp_1 & 1ULL);
      ticksPerRad = rt_roundd_snf((real_T)((uint64_T)rt_roundd_snf
        (gbyk_v4b_B.A2M1Convert[4]) >> 21ULL));
      if (ticksPerRad < 1.8446744073709552E+19) {
        if (ticksPerRad >= 0.0) {
          tmp_1 = (uint64_T)ticksPerRad;
        } else {
          tmp_1 = 0ULL;
        }
      } else {
        tmp_1 = MAX_uint64_T;
      }

      gbyk_v4b_B.digitalInputs_m[1] = (real_T)(tmp_1 & 1ULL);

      /* '<S163>:1:9' */
      ticksPerRad = rt_roundd_snf((real_T)((uint64_T)rt_roundd_snf
        (gbyk_v4b_B.A2M1Convert[4]) >> 16ULL));
      if (ticksPerRad < 1.8446744073709552E+19) {
        if (ticksPerRad >= 0.0) {
          tmp_1 = (uint64_T)ticksPerRad;
        } else {
          tmp_1 = 0ULL;
        }
      } else {
        tmp_1 = MAX_uint64_T;
      }

      gbyk_v4b_B.calibrationButton = (real_T)(tmp_1 & 1ULL);
      if (gbyk_v4b_B.R2_constantsReady != 1.0) {
        /* '<S163>:1:11' */
        /* '<S163>:1:12' */
        gbyk_v4b_B.LinkAngle_l = 0.0;

        /* '<S163>:1:13' */
        gbyk_v4b_B.PrimaryLinkVel_i = 0.0;

        /* '<S163>:1:14' */
        gbyk_v4b_B.PrimaryLinkAngle_f = 0.0;

        /* '<S163>:1:15' */
        ticksPerRad = 0.0;
      } else {
        if (gbyk_v4b_B.sf_splitoutconstants1_o.hasSecondary != 0.0) {
          /* '<S163>:1:39' */
          /* '<S163>:1:40' */
          /* '<S163>:1:41' */
          /* '<S163>:1:20' */
          gbyk_v4b_B.LinkAngle_l = gbyk_v4b_B.A2M1Convert[1] /
            (gbyk_v4b_B.encoderCounts[1] / 6.2831853071795862) *
            -gbyk_v4b_B.encorient + gbyk_v4b_B.offsetrads;
        } else {
          /* '<S163>:1:39' */
          /* '<S163>:1:40' */
          /* '<S163>:1:41' */
          /* '<S163>:1:22' */
          gbyk_v4b_B.LinkAngle_l = gbyk_v4b_B.A2M1Convert[0] /
            (gbyk_v4b_B.encoderCounts[0] * gbyk_v4b_B.L2select4 /
             6.2831853071795862) * gbyk_v4b_B.L2select2 + gbyk_v4b_B.L2select3;
        }

        /* '<S163>:1:39' */
        ticksPerRad = gbyk_v4b_B.encoderCounts[0] * gbyk_v4b_B.L2select4 /
          6.2831853071795862;

        /* '<S163>:1:40' */
        /* '<S163>:1:41' */
        /* '<S163>:1:25' */
        gbyk_v4b_B.PrimaryLinkAngle_f = gbyk_v4b_B.A2M1Convert[0] / ticksPerRad *
          gbyk_v4b_B.L2select2 + gbyk_v4b_B.L2select3;

        /* '<S163>:1:25' */
        gbyk_v4b_B.PrimaryLinkVel_i = gbyk_v4b_B.A2M1Convert[2] / ticksPerRad *
          gbyk_v4b_B.L2select2;

        /* '<S163>:1:26' */
        ticksPerRad = gbyk_v4b_B.A2M1Convert[3] / 1000.0 * gbyk_v4b_B.L2select5 *
          gbyk_v4b_B.L2select4 * gbyk_v4b_B.L2select2;

        /* I had to follow this around for a while to figure out why this is */
        /* required. There I think are 2 reasons: 1) the robot orientation I */
        /* calculate for ECAT is "backwards" (i.e. it is arm orientation) 2) if */
        /* you look at the apply loads blocks there is a reversal there as well. */
        /* '<S163>:1:32' */
        if (gbyk_v4b_B.sf_FindRobottype_d.robotType == 1.0) {
          /* '<S163>:1:33' */
          /* '<S163>:1:34' */
          ticksPerRad = -ticksPerRad;
        }
      }

      gbyk_v4b_B.torque_f = ticksPerRad;

      /* End of MATLAB Function: '<S155>/countsToRads' */

      /* Outputs for Atomic SubSystem: '<S138>/A2M2 PDOs' */
      gbyk_v4b_A2M2PDOs();

      /* End of Outputs for SubSystem: '<S138>/A2M2 PDOs' */

      /* Outputs for Atomic SubSystem: '<S138>/EMCY Message pump' */
      gbyk_v4b_EMCYMessagepump_i();

      /* End of Outputs for SubSystem: '<S138>/EMCY Message pump' */

      /* RelationalOperator: '<S165>/Compare' incorporates:
       *  Constant: '<S165>/Constant'
       */
      gbyk_v4b_B.Compare_oo = (gbyk_v4b_B.masterState ==
        gbyk_v4b_P.Compare_const_h);

      /* MATLAB Function: '<S138>/Control GDC Whistle State' incorporates:
       *  Constant: '<S64>/max errors to fault'
       */
      /* MATLAB Function 'EtherCAT Subsystem/Arm 2/A2M2/Control GDC Whistle State': '<S166>:1' */
      /*  This function outputs the appropriate ControlWord to control the state of the Elmo Drive. */
      /*  Need to decide why I would want Disabled state vs Ready to switch on state. */
      /*  TODO - deal with faults "better" */
      if (!gbyk_v4b_DW.permFaulted_not_empty) {
        /* '<S166>:1:8' */
        gbyk_v4b_DW.permFaulted_not_empty = true;

        /* '<S166>:1:12' */
        gbyk_v4b_DW.lastEStopState =
          gbyk_v4b_B.sf_parsestatusregister1_fq.eStopOut;
      }

      /*  Define the value of the StatusWord for different states of the Elmo drive.  */
      /*  Taken from the EtherCAT CoE Usage.xls from Elmo.  */
      /*  bit 9 = 1, because the Elmo drive is always in Remote mode, but I don't look at it. */
      /*  bit 4 = 1, because the voltage should be enabled */
      /*  bits 0-3, 6 define the state */
      /*  unclear on bits 10 and higher */
      /*  hex2dec('50'); */
      /*  hex2dec('31'); */
      /*  hex2dec('33');		% NOTE: We don't really need this state with the Elmo drive in Torque Mode */
      /*  hex2dec('37');		% Although we operate in this state, we don't actual need to query it */
      /*  hex2dec('18');		 */
      /*  Define the value of the ControlWord for different transitions */
      /*  Equal to transitions 7, 9 or 10 */
      /*  Technically this is just the "shutdown" transition. Equal to transitions 2, 6 or 8 */
      /*  Transition 3. As per SwitchedOn, we don't really need this one. */
      /*  Combines transitions 3 and 4 together = 0xF */
      /*  Transitions 15 together = 0x80 */
      /*  Mask the StatusWord input to bits 0-7 */
      /* '<S166>:1:36' */
      StatusWord = (uint16_T)(gbyk_v4b_B.statusword & 127);

      /*  127 = 0x7F */
      /* '<S166>:1:38' */
      gbyk_v4b_B.motorStatus = 2U;

      /* motor is not working (red) */
      if ((!(gbyk_v4b_B.sf_parsestatusregister1_fq.faultFound != 0U)) &&
          (gbyk_v4b_B.sf_parsestatusregister1_fq.allOK != 0U)) {
        /* '<S166>:1:39' */
        if (gbyk_v4b_B.sf_parsestatusregister1_fq.motorOn != 0U) {
          /* '<S166>:1:41' */
          gbyk_v4b_B.motorStatus = 0U;

          /* motor is working (green) */
        } else {
          /* '<S166>:1:43' */
          gbyk_v4b_B.motorStatus = 1U;

          /* motor is ready to work (yellow) */
        }
      }

      /* 0xff20 */
      /* 0xff10 */
      /* 0x8130 */
      /* 10 is a current limit */
      /* '<S166>:1:52' */
      i = 0;
      ii_sizes_idx_1 = 1;
      b_ii = 1;
      exitg1 = false;
      while ((!exitg1) && (b_ii < 5)) {
        ticksPerRad = gbyk_v4b_B.sf_faultmonitor1_h.EMCYMsg[2];
        if (ignorable_emcys_0[b_ii - 1] == ticksPerRad) {
          i = 1;
          exitg1 = true;
        } else {
          b_ii++;
        }
      }

      if (i == 0) {
        ii_sizes_idx_1 = 0;
      }

      /* '<S166>:1:53' */
      if ((gbyk_v4b_B.sf_faultmonitor1_h.EMCYMsg[2] != 0.0) &&
          (!!(ii_sizes_idx_1 == 0))) {
        /* '<S166>:1:55' */
        if (gbyk_v4b_B.sf_faultmonitor1_h.EMCYMsg[2] == 65296.0) {
          /* '<S166>:1:56' */
          if (gbyk_v4b_B.sf_parsestatusregister1_fq.eStopOut == 0U) {
            /* '<S166>:1:57' */
            /* if the estops are not pressed but we couldn't start then we are truly faulted */
            /* '<S166>:1:58' */
            gbyk_v4b_DW.permFaulted = 1.0;
          }
        } else {
          /* '<S166>:1:61' */
          gbyk_v4b_DW.permFaulted = 1.0;
        }
      }

      /* is the amp is reporting it is working we can reset our count of faults */
      if (StatusWord == 55) {
        /* '<S166>:1:66' */
        /* '<S166>:1:67' */
        gbyk_v4b_DW.countFaultSteps = 0.0;
      }

      /* '<S166>:1:70' */
      ControlWord = 0U;
      if (StatusWord == 24) {
        /* '<S166>:1:72' */
        /* Only when the amp is ready to go can we try to enable it. Otherwise */
        /* we will flood the slrt stdout and slrt will CPU overload. */
        if ((gbyk_v4b_B.sf_parsestatusregister1_fq.ampStatus == 0U) &&
            (gbyk_v4b_DW.permFaulted == 0.0) &&
            (gbyk_v4b_B.sf_parsestatusregister1_fq.eStopOut == 0U) &&
            gbyk_v4b_B.Compare_oo) {
          /* '<S166>:1:75' */
          /*  change to the Disabled state if faulted */
          /* '<S166>:1:77' */
          ControlWord = 128U;

          /* if eStops == 0 %the emergency stops are not engaged, i.e. we can run with forces */
          /* '<S166>:1:79' */
          gbyk_v4b_DW.countFaultSteps++;

          /* when the emergency stop is released we get a few rounds where */
          /* there are faults. If we get lots of rounds where there are */
          /* faults then the motor is truly in a bad state and we should */
          /* not continue to ask it to start up. If we continue to ask then */
          /* we can get CPU overloads from all the MBX errors */
          if (gbyk_v4b_DW.countFaultSteps > gbyk_v4b_P.maxerrorstofault_Value) {
            /* '<S166>:1:85' */
            /* '<S166>:1:86' */
            gbyk_v4b_DW.permFaulted = 1.0;
          }

          /*  end */
        } else {
          /* '<S166>:1:90' */
        }
      } else if ((StatusWord == 80) &&
                 (gbyk_v4b_B.sf_forceEnableDisable_k.forceMotorState != 0.0)) {
        /* '<S166>:1:92' */
        /*  change to the Ready to Switch On state if in the Switch On Disabled state AND enable has been requested */
        /* '<S166>:1:94' */
        ControlWord = 6U;
      } else {
        if (gbyk_v4b_B.sf_forceEnableDisable_k.forceMotorState != 0.0) {
          /* '<S166>:1:95' */
          /*  change to the Enabled state if in the Ready to Switch on state AND enable had been requested */
          /* '<S166>:1:97' */
          ControlWord = 15U;
        }
      }

      /* If the estop was hit while a task was running that generates a fault. When */
      /* the task is reset then later you disable the estop we need to try to clear */
      /* the error. */
      if ((ControlWord == 0) &&
          (gbyk_v4b_B.sf_parsestatusregister1_fq.faultFound != 0U) &&
          (!(gbyk_v4b_B.sf_parsestatusregister1_fq.eStopOut != 0U)) &&
          (gbyk_v4b_DW.lastEStopState != 0U)) {
        /* '<S166>:1:103' */
        /* '<S166>:1:104' */
        gbyk_v4b_DW.frameCounter = 0.0;
      }

      /* this code is trying to clear any faults found at start-up */
      /* 4khz * 3s - it takes ~1.8s to reach the op state and we need to do this after that */
      if ((gbyk_v4b_DW.frameCounter < 12000.0) &&
          (gbyk_v4b_B.sf_parsestatusregister1_fq.allOK != 0U) &&
          (gbyk_v4b_B.sf_parsestatusregister1_fq.ampStatus == 0U) &&
          (!(gbyk_v4b_DW.permFaulted != 0.0)) &&
          (!(gbyk_v4b_B.sf_parsestatusregister1_fq.eStopOut != 0U)) &&
          gbyk_v4b_B.Compare_oo &&
          (gbyk_v4b_B.sf_parsestatusregister1_fq.faultFound != 0U)) {
        /* '<S166>:1:109' */
        if (StatusWord == 80) {
          /* '<S166>:1:110' */
          /* '<S166>:1:111' */
          ControlWord = 6U;
        } else {
          if (StatusWord == 49) {
            /* '<S166>:1:112' */
            /* the only way to clear an error is to enable the drive. This should */
            /* enable the drive very briefly. The forces should still be off */
            /* though since they are controlled by the run state of the drive. */
            /* '<S166>:1:116' */
            ControlWord = 15U;
          }
        }
      }

      /* '<S166>:1:120' */
      gbyk_v4b_DW.lastEStopState =
        gbyk_v4b_B.sf_parsestatusregister1_fq.eStopOut;

      /* '<S166>:1:121' */
      gbyk_v4b_DW.frameCounter++;

      /* '<S166>:1:122' */
      gbyk_v4b_B.isPermFaulted = gbyk_v4b_DW.permFaulted;
      gbyk_v4b_B.ControlWord = ControlWord;

      /* End of MATLAB Function: '<S138>/Control GDC Whistle State' */

      /* Level2 S-Function Block: '<S138>/BKIN EtherCAT PDO Transmit ' (BKINethercatpdotx) */
      {
        SimStruct *rts = gbyk_v4b_M->childSfunctions[19];
        sfcnOutputs(rts, 1);
      }

      /* Selector: '<S168>/L2 select' incorporates:
       *  Constant: '<S138>/MotorIdx'
       */
      gbyk_v4b_B.L2select = gbyk_v4b_B.offsetRads[(int32_T)
        gbyk_v4b_P.MotorIdx_Value_n1 - 1];

      /* Selector: '<S168>/L2 select1' incorporates:
       *  Constant: '<S138>/MotorIdx'
       */
      gbyk_v4b_B.L2select1 = gbyk_v4b_B.sf_splitoutconstants1_o.encOrientation
        [(int32_T)gbyk_v4b_P.MotorIdx_Value_n1 - 1];

      /* Selector: '<S168>/L2 select2' incorporates:
       *  Constant: '<S138>/MotorIdx'
       */
      gbyk_v4b_B.L2select2_p =
        gbyk_v4b_B.sf_splitoutconstants1_o.motorOrientation[(int32_T)
        gbyk_v4b_P.MotorIdx_Value_n1 - 1];

      /* Selector: '<S168>/L2 select3' incorporates:
       *  Constant: '<S138>/MotorIdx'
       */
      gbyk_v4b_B.L2select3_c = gbyk_v4b_B.offsetRadsPrimary[(int32_T)
        gbyk_v4b_P.MotorIdx_Value_n1 - 1];

      /* Selector: '<S168>/L2 select4' incorporates:
       *  Constant: '<S138>/MotorIdx'
       */
      gbyk_v4b_B.L2select4_b = gbyk_v4b_B.gearRatios[(int32_T)
        gbyk_v4b_P.MotorIdx_Value_n1 - 1];

      /* Selector: '<S168>/L2 select5' incorporates:
       *  Constant: '<S138>/MotorIdx'
       */
      gbyk_v4b_B.L2select5_a = gbyk_v4b_B.R2_maxContinuousTorque[(int32_T)
        gbyk_v4b_P.MotorIdx_Value_n1 - 1];

      /* MATLAB Function: '<S168>/countsToRads' */
      /* MATLAB Function 'EtherCAT Subsystem/Arm 2/A2M2/PDO to Angles Subsystem/countsToRads': '<S176>:1' */
      /* '<S176>:1:3' */
      /* '<S176>:1:4' */
      gbyk_v4b_B.digitalDiagnostics = gbyk_v4b_B.A2M2Convert[4];

      /* The CR (command reference) manual says that */
      /* Digital inputs 5 and 6 are at bits 20 and 21 */
      /* '<S176>:1:8' */
      ticksPerRad = rt_roundd_snf((real_T)((uint64_T)rt_roundd_snf
        (gbyk_v4b_B.A2M2Convert[4]) >> 20ULL));
      if (ticksPerRad < 1.8446744073709552E+19) {
        if (ticksPerRad >= 0.0) {
          tmp_1 = (uint64_T)ticksPerRad;
        } else {
          tmp_1 = 0ULL;
        }
      } else {
        tmp_1 = MAX_uint64_T;
      }

      gbyk_v4b_B.digitalInputs[0] = (real_T)(tmp_1 & 1ULL);
      ticksPerRad = rt_roundd_snf((real_T)((uint64_T)rt_roundd_snf
        (gbyk_v4b_B.A2M2Convert[4]) >> 21ULL));
      if (ticksPerRad < 1.8446744073709552E+19) {
        if (ticksPerRad >= 0.0) {
          tmp_1 = (uint64_T)ticksPerRad;
        } else {
          tmp_1 = 0ULL;
        }
      } else {
        tmp_1 = MAX_uint64_T;
      }

      gbyk_v4b_B.digitalInputs[1] = (real_T)(tmp_1 & 1ULL);
      if (gbyk_v4b_B.R2_constantsReady != 1.0) {
        /* '<S176>:1:10' */
        /* '<S176>:1:11' */
        gbyk_v4b_B.LinkAngle = 0.0;

        /* '<S176>:1:12' */
        gbyk_v4b_B.PrimaryLinkVel = 0.0;

        /* '<S176>:1:13' */
        gbyk_v4b_B.PrimaryLinkAngle = 0.0;

        /* '<S176>:1:14' */
        ticksPerRad = 0.0;
      } else {
        if (gbyk_v4b_B.sf_splitoutconstants1_o.hasSecondary != 0.0) {
          /* '<S176>:1:38' */
          /* '<S176>:1:39' */
          /* '<S176>:1:40' */
          /* '<S176>:1:19' */
          gbyk_v4b_B.LinkAngle = gbyk_v4b_B.A2M2Convert[1] /
            (gbyk_v4b_B.encoderCounts[1] / 6.2831853071795862) *
            -gbyk_v4b_B.L2select1 + gbyk_v4b_B.L2select;
        } else {
          /* '<S176>:1:38' */
          /* '<S176>:1:39' */
          /* '<S176>:1:40' */
          /* '<S176>:1:21' */
          gbyk_v4b_B.LinkAngle = gbyk_v4b_B.A2M2Convert[0] /
            (gbyk_v4b_B.encoderCounts[0] * gbyk_v4b_B.L2select4_b /
             6.2831853071795862) * gbyk_v4b_B.L2select2_p +
            gbyk_v4b_B.L2select3_c;
        }

        /* '<S176>:1:38' */
        ticksPerRad = gbyk_v4b_B.encoderCounts[0] * gbyk_v4b_B.L2select4_b /
          6.2831853071795862;

        /* '<S176>:1:39' */
        /* '<S176>:1:40' */
        /* '<S176>:1:24' */
        gbyk_v4b_B.PrimaryLinkAngle = gbyk_v4b_B.A2M2Convert[0] / ticksPerRad *
          gbyk_v4b_B.L2select2_p + gbyk_v4b_B.L2select3_c;

        /* '<S176>:1:24' */
        gbyk_v4b_B.PrimaryLinkVel = gbyk_v4b_B.A2M2Convert[2] / ticksPerRad *
          gbyk_v4b_B.L2select2_p;

        /* '<S176>:1:25' */
        ticksPerRad = gbyk_v4b_B.A2M2Convert[3] / 1000.0 *
          gbyk_v4b_B.L2select5_a * gbyk_v4b_B.L2select4_b *
          gbyk_v4b_B.L2select2_p;

        /* I had to follow this around for a while to figure out why this is */
        /* required. There I think are 2 reasons: 1) the robot orientation I */
        /* calculate for ECAT is "backwards" (i.e. it is arm orientation) 2) if */
        /* you look at the apply loads blocks there is a reversal there as well. */
        /* '<S176>:1:31' */
        if (gbyk_v4b_B.sf_FindRobottype_d.robotType == 1.0) {
          /* '<S176>:1:32' */
          /* '<S176>:1:33' */
          ticksPerRad = -ticksPerRad;
        }
      }

      gbyk_v4b_B.torque = ticksPerRad;

      /* End of MATLAB Function: '<S168>/countsToRads' */

      /* SignalConversion: '<S76>/Signal Conversion' */
      gbyk_v4b_B.R2M1_LinkAngle = gbyk_v4b_B.LinkAngle_l;

      /* SignalConversion: '<S76>/Signal Conversion' */
      gbyk_v4b_B.R2M2_LinkAngle = gbyk_v4b_B.LinkAngle;

      /* SignalConversion: '<S76>/Signal Conversion' */
      gbyk_v4b_B.R2M2_PrimaryLinkAngle = gbyk_v4b_B.PrimaryLinkAngle;

      /* SignalConversion: '<S76>/Signal Conversion' */
      gbyk_v4b_B.R2M2_PrimaryLinkVelocity = gbyk_v4b_B.PrimaryLinkVel;

      /* SignalConversion: '<S76>/Signal Conversion' */
      gbyk_v4b_B.R2M2_RecordedTorque = gbyk_v4b_B.torque;

      /* SignalConversion: '<S76>/Signal Conversion' */
      gbyk_v4b_B.R2M2_digitalInputs[0] = gbyk_v4b_B.digitalInputs[0];
      gbyk_v4b_B.R2M2_digitalInputs[1] = gbyk_v4b_B.digitalInputs[1];

      /* SignalConversion: '<S76>/Signal Conversion' */
      gbyk_v4b_B.R2M2_digitalDiagnostics = gbyk_v4b_B.digitalDiagnostics;

      /* SignalConversion: '<S76>/Signal Conversion' */
      gbyk_v4b_B.R2M2_CurrentLimitEnabled =
        gbyk_v4b_B.sf_parsestatusregister1_fq.currentLimitEnabled;

      /* SignalConversion: '<S76>/Signal Conversion' */
      gbyk_v4b_B.R2M1_PrimaryLinkAngle = gbyk_v4b_B.PrimaryLinkAngle_f;

      /* SignalConversion: '<S76>/Signal Conversion' */
      gbyk_v4b_B.R2M1_PrimaryLinkVelocity = gbyk_v4b_B.PrimaryLinkVel_i;

      /* SignalConversion: '<S76>/Signal Conversion' */
      gbyk_v4b_B.R2M1_RecordedTorque = gbyk_v4b_B.torque_f;

      /* SignalConversion: '<S76>/Signal Conversion' */
      gbyk_v4b_B.R2M1_digitalInputs[0] = gbyk_v4b_B.digitalInputs_m[0];
      gbyk_v4b_B.R2M1_digitalInputs[1] = gbyk_v4b_B.digitalInputs_m[1];

      /* SignalConversion: '<S76>/Signal Conversion' */
      gbyk_v4b_B.R2M1_digitalDiagnostics = gbyk_v4b_B.digitalDiagnostics_c;

      /* SignalConversion: '<S76>/Signal Conversion' */
      gbyk_v4b_B.R2_calibrationButton = gbyk_v4b_B.calibrationButton;
      for (i = 0; i < 5; i++) {
        /* SignalConversion: '<S76>/Signal Conversion' */
        gbyk_v4b_B.R2M2_EMCY_codes[i] = gbyk_v4b_B.sf_faultmonitor1_h.EMCYMsg[i];

        /* SignalConversion: '<S76>/Signal Conversion' */
        gbyk_v4b_B.R2M1_EMCY_codes[i] = gbyk_v4b_B.sf_faultmonitor1_c.EMCYMsg[i];
      }

      /* SignalConversion: '<S76>/Signal Conversion' */
      gbyk_v4b_B.R2M1_CurrentLimitEnabled =
        gbyk_v4b_B.sf_parsestatusregister1_f.currentLimitEnabled;

      /* SignalConversion: '<S76>/Signal Conversion1' */
      gbyk_v4b_B.R2_RobotType = gbyk_v4b_B.sf_FindRobottype_d.robotType;

      /* SignalConversion: '<S76>/Signal Conversion1' */
      gbyk_v4b_B.R2_absAngleOffset[0] = gbyk_v4b_B.absAngOffsets[0];
      gbyk_v4b_B.R2_absAngleOffset[1] = gbyk_v4b_B.absAngOffsets[1];

      /* SignalConversion: '<S76>/Signal Conversion1' */
      gbyk_v4b_B.R2_LinkLength[0] = gbyk_v4b_B.linkLengths[0];
      gbyk_v4b_B.R2_LinkLength[1] = gbyk_v4b_B.linkLengths[1];

      /* SignalConversion: '<S76>/Signal Conversion1' */
      gbyk_v4b_B.R2_L2CalibPinOffset = gbyk_v4b_B.L2CalibPinOffset;

      /* SignalConversion: '<S76>/Signal Conversion1' */
      gbyk_v4b_B.R2_maxContinuousTorque_e[0] =
        gbyk_v4b_B.R2_maxContinuousTorque[0];
      gbyk_v4b_B.R2_maxContinuousTorque_e[1] =
        gbyk_v4b_B.R2_maxContinuousTorque[1];

      /* SignalConversion: '<S76>/Signal Conversion1' */
      gbyk_v4b_B.R2_gearRatios[0] = gbyk_v4b_B.gearRatios[0];
      gbyk_v4b_B.R2_gearRatios[1] = gbyk_v4b_B.gearRatios[1];

      /* SignalConversion: '<S76>/Signal Conversion1' */
      gbyk_v4b_B.R2_isCalibrated = gbyk_v4b_B.isCalibrated;

      /* SignalConversion: '<S76>/Signal Conversion1' */
      gbyk_v4b_B.R2_OffsetRads[0] = gbyk_v4b_B.offsetRads[0];
      gbyk_v4b_B.R2_OffsetRads[1] = gbyk_v4b_B.offsetRads[1];

      /* SignalConversion: '<S76>/Signal Conversion1' */
      gbyk_v4b_B.R2_OffsetRadsPrimary[0] = gbyk_v4b_B.offsetRadsPrimary[0];
      gbyk_v4b_B.R2_OffsetRadsPrimary[1] = gbyk_v4b_B.offsetRadsPrimary[1];

      /* SignalConversion: '<S76>/Signal Conversion1' */
      gbyk_v4b_B.R2_RobotRevision = gbyk_v4b_B.robotRevision_o;

      /* SignalConversion: '<S76>/Signal Conversion1' */
      gbyk_v4b_B.R2_constantsReady_j = gbyk_v4b_B.R2_constantsReady;

      /* SignalConversion: '<S76>/Signal Conversion1' */
      gbyk_v4b_B.R2_hasSecondary =
        gbyk_v4b_B.sf_splitoutconstants1_o.hasSecondary;

      /* SignalConversion: '<S76>/Signal Conversion1' */
      gbyk_v4b_B.R2_hasFT = gbyk_v4b_B.sf_splitoutconstants1_o.hasFT;

      /* SignalConversion: '<S76>/Signal Conversion1' */
      gbyk_v4b_B.R2_robotOrientation =
        gbyk_v4b_B.sf_splitoutconstants1_o.robotOrientation;

      /* SignalConversion: '<S76>/Signal Conversion1' */
      gbyk_v4b_B.R2_motorOrientation[0] =
        gbyk_v4b_B.sf_splitoutconstants1_o.motorOrientation[0];
      gbyk_v4b_B.R2_motorOrientation[1] =
        gbyk_v4b_B.sf_splitoutconstants1_o.motorOrientation[1];

      /* SignalConversion: '<S76>/Signal Conversion1' */
      gbyk_v4b_B.R2_encOrientation[0] =
        gbyk_v4b_B.sf_splitoutconstants1_o.encOrientation[0];
      gbyk_v4b_B.R2_encOrientation[1] =
        gbyk_v4b_B.sf_splitoutconstants1_o.encOrientation[1];

      /* SignalConversion: '<S76>/Signal Conversion1' */
      gbyk_v4b_B.R2_encodercounts[0] = gbyk_v4b_B.encoderCounts[0];
      gbyk_v4b_B.R2_encodercounts[1] = gbyk_v4b_B.encoderCounts[1];

      /* SignalConversion: '<S76>/Signal Conversion1' */
      gbyk_v4b_B.R2_FTSensorAngleOffset = gbyk_v4b_B.FTSensorOffset;

      /* SignalConversion: '<S76>/Signal Conversion1' */
      gbyk_v4b_B.R2_calibPinAngle[0] = gbyk_v4b_B.calibPinAngles[0];
      gbyk_v4b_B.R2_calibPinAngle[1] = gbyk_v4b_B.calibPinAngles[1];

      /* Outputs for Atomic SubSystem: '<S146>/Read Drive 3 SDO' */
      gbyk_v4b_ReadDrive3SDO_g();

      /* End of Outputs for SubSystem: '<S146>/Read Drive 3 SDO' */

      /* RateTransition: '<S146>/Rate Transition' */
      gbyk_v4b_B.RateTransition_bx = gbyk_v4b_B.sf_converter_jl.int32Out;

      /* RateTransition: '<S146>/Rate Transition1' */
      gbyk_v4b_B.RateTransition1_d = gbyk_v4b_B.sf_converter_jl.doubleOut;

      /* RateTransition: '<S146>/Rate Transition2' */
      gbyk_v4b_B.RateTransition2_j = gbyk_v4b_B.DataTypeConversion_iq;

      /* Outputs for Enabled SubSystem: '<S76>/M1 AbsEnc Calibration' incorporates:
       *  EnablePort: '<S140>/Enable'
       */
      /* Constant: '<S76>/enableCalibration' */
      if (gbyk_v4b_P.enableCalibration_Value_h > 0.0) {
        if (!gbyk_v4b_DW.M1AbsEncCalibration_MODE) {
          /* InitializeConditions for Memory: '<S140>/Memory' */
          gbyk_v4b_DW.Memory_PreviousInput_cs = gbyk_v4b_P.Memory_X0_nj;

          /* InitializeConditions for Memory: '<S140>/Memory1' */
          gbyk_v4b_DW.Memory1_PreviousInput_io[0] = gbyk_v4b_P.Memory1_X0_hb;
          gbyk_v4b_DW.Memory1_PreviousInput_io[1] = gbyk_v4b_P.Memory1_X0_hb;

          /* InitializeConditions for Chart: '<S140>/AbsEncoder machine' */
          gbyk_v4b_AbsEncodermachine_Init(&gbyk_v4b_B.sf_AbsEncodermachine_i,
            &gbyk_v4b_DW.sf_AbsEncodermachine_i);
          gbyk_v4b_DW.M1AbsEncCalibration_MODE = true;
        }

        /* MATLAB Function: '<S140>/set-up values' */
        gbyk_v4b_setupvalues(&gbyk_v4b_B.sf_setupvalues_k);

        /* Memory: '<S140>/Memory' */
        gbyk_v4b_B.Memory_h = gbyk_v4b_DW.Memory_PreviousInput_cs;

        /* Memory: '<S140>/Memory1' */
        gbyk_v4b_B.Memory1_f[0] = gbyk_v4b_DW.Memory1_PreviousInput_io[0];
        gbyk_v4b_B.Memory1_f[1] = gbyk_v4b_DW.Memory1_PreviousInput_io[1];

        /* Chart: '<S140>/AbsEncoder machine' */
        gbyk_v4b_AbsEncodermachine(gbyk_v4b_B.sf_setupvalues_k.setupValues,
          gbyk_v4b_B.sf_setupvalues_k.setupValuesCount,
          gbyk_v4b_B.sf_setupvalues_k.pollValues,
          gbyk_v4b_B.sf_setupvalues_k.encoderValues,
          gbyk_v4b_B.sf_setupvalues_k.encoderValuesCount, gbyk_v4b_B.Memory_h,
          gbyk_v4b_B.Memory1_f, &gbyk_v4b_B.sf_AbsEncodermachine_i,
          &gbyk_v4b_DW.sf_AbsEncodermachine_i);

        /* S-Function (BKINethercatasyncsdodownload): '<S140>/BKIN EtherCAT Async SDO Download' */
        {
          int8_T *sigInputPtr;
          int32_T *sigStatusPtr;
          int32_T *enInputPtr;
          int_T deviceIndex;
          int_T res;
          int_T state;
          int32_T *indexInputPtr;
          int32_T *subIndexInputPtr;
          deviceIndex = gbyk_v4b_DW.BKINEtherCATAsyncSDODownload_IWORK_m[0];
          if (deviceIndex != NO_ETHERCAT) {
            state = xpcEtherCATgetState( deviceIndex );
            if (state >= 2 ) {
              sigStatusPtr = &gbyk_v4b_B.BKINEtherCATAsyncSDODownload_g0;
              sigInputPtr = &gbyk_v4b_B.sf_AbsEncodermachine_i.setupData[0];
              enInputPtr = &gbyk_v4b_B.sf_AbsEncodermachine_i.setupData[1];
              indexInputPtr = &gbyk_v4b_B.sf_AbsEncodermachine_i.setupData[2];
              subIndexInputPtr = &gbyk_v4b_B.sf_AbsEncodermachine_i.setupData[3];
              if (gbyk_v4b_DW.BKINEtherCATAsyncSDODownload_IWORK_m[7] != 0) {
                res = ecatAsyncSDODownload(deviceIndex,
                  1003,
                  (unsigned short)*indexInputPtr,
                  (unsigned char)*subIndexInputPtr,
                  (void *)sigInputPtr,
                  1*4,
                  500,
                  342974277,
                  sigStatusPtr,
                  *enInputPtr);
              } else {
                *sigStatusPtr = 0;
              }

              gbyk_v4b_DW.BKINEtherCATAsyncSDODownload_IWORK_m[7] = 1;
              ;
            }
          }
        }

        /* S-Function (BKINethercatasyncsdoupload): '<S140>/BKIN EtherCAT Async SDO Upload' */
        {
          int8_T *sigOutputPtr;
          int32_T *sigStatusPtr;
          int32_T *enInputPtr;
          int_T deviceIndex;
          static int counter= 0;
          int_T actLen;
          int_T res;
          int_T state;
          int32_T *indexInputPtr;
          int32_T *subIndexInputPtr;
          deviceIndex = gbyk_v4b_DW.BKINEtherCATAsyncSDOUpload_IWORK_o[0];
          if (deviceIndex != NO_ETHERCAT) {
            state = xpcEtherCATgetState( deviceIndex );
            if (state >= 2 ) {
              sigOutputPtr = &gbyk_v4b_B.BKINEtherCATAsyncSDOUpload_o1_k;
              sigStatusPtr = &gbyk_v4b_B.BKINEtherCATAsyncSDOUpload_o2_o;
              enInputPtr = &gbyk_v4b_B.sf_AbsEncodermachine_i.SDORequest[0];
              indexInputPtr = &gbyk_v4b_B.sf_AbsEncodermachine_i.SDORequest[1];
              subIndexInputPtr = &gbyk_v4b_B.sf_AbsEncodermachine_i.SDORequest[2];
              if (gbyk_v4b_DW.BKINEtherCATAsyncSDOUpload_IWORK_o[7] != 0) {
                res = ecatAsyncSDOUpload(deviceIndex,
                  1003,
                  (unsigned short)*indexInputPtr,
                  (unsigned char)*subIndexInputPtr,
                  (void *)sigOutputPtr,
                  1*4,
                  &actLen,
                  500,
                  342974278,
                  sigStatusPtr,
                  *enInputPtr);
              }

              gbyk_v4b_DW.BKINEtherCATAsyncSDOUpload_IWORK_o[7] = 1;
              ;
            }
          }
        }

        srUpdateBC(gbyk_v4b_DW.M1AbsEncCalibration_SubsysRanBC);
      } else {
        if (gbyk_v4b_DW.M1AbsEncCalibration_MODE) {
          gbyk_v4b_DW.M1AbsEncCalibration_MODE = false;
        }
      }

      /* End of Outputs for SubSystem: '<S76>/M1 AbsEnc Calibration' */

      /* Outputs for Enabled SubSystem: '<S76>/M2 AbsEnc Calibration' incorporates:
       *  EnablePort: '<S141>/Enable'
       */
      if (gbyk_v4b_P.enableCalibration_Value_h > 0.0) {
        if (!gbyk_v4b_DW.M2AbsEncCalibration_MODE) {
          /* InitializeConditions for Memory: '<S141>/Memory' */
          gbyk_v4b_DW.Memory_PreviousInput_o = gbyk_v4b_P.Memory_X0_id;

          /* InitializeConditions for Memory: '<S141>/Memory1' */
          gbyk_v4b_DW.Memory1_PreviousInput_l[0] = gbyk_v4b_P.Memory1_X0_a;
          gbyk_v4b_DW.Memory1_PreviousInput_l[1] = gbyk_v4b_P.Memory1_X0_a;

          /* InitializeConditions for Chart: '<S141>/AbsEncoder machine' */
          gbyk_v4b_AbsEncodermachine_Init(&gbyk_v4b_B.sf_AbsEncodermachine_k,
            &gbyk_v4b_DW.sf_AbsEncodermachine_k);
          gbyk_v4b_DW.M2AbsEncCalibration_MODE = true;
        }

        /* MATLAB Function: '<S141>/set-up values' */
        gbyk_v4b_setupvalues(&gbyk_v4b_B.sf_setupvalues_g);

        /* Memory: '<S141>/Memory' */
        gbyk_v4b_B.Memory_pb = gbyk_v4b_DW.Memory_PreviousInput_o;

        /* Memory: '<S141>/Memory1' */
        gbyk_v4b_B.Memory1_et[0] = gbyk_v4b_DW.Memory1_PreviousInput_l[0];
        gbyk_v4b_B.Memory1_et[1] = gbyk_v4b_DW.Memory1_PreviousInput_l[1];

        /* Chart: '<S141>/AbsEncoder machine' */
        gbyk_v4b_AbsEncodermachine(gbyk_v4b_B.sf_setupvalues_g.setupValues,
          gbyk_v4b_B.sf_setupvalues_g.setupValuesCount,
          gbyk_v4b_B.sf_setupvalues_g.pollValues,
          gbyk_v4b_B.sf_setupvalues_g.encoderValues,
          gbyk_v4b_B.sf_setupvalues_g.encoderValuesCount, gbyk_v4b_B.Memory_pb,
          gbyk_v4b_B.Memory1_et, &gbyk_v4b_B.sf_AbsEncodermachine_k,
          &gbyk_v4b_DW.sf_AbsEncodermachine_k);

        /* S-Function (BKINethercatasyncsdodownload): '<S141>/BKIN EtherCAT Async SDO Download' */
        {
          int8_T *sigInputPtr;
          int32_T *sigStatusPtr;
          int32_T *enInputPtr;
          int_T deviceIndex;
          int_T res;
          int_T state;
          int32_T *indexInputPtr;
          int32_T *subIndexInputPtr;
          deviceIndex = gbyk_v4b_DW.BKINEtherCATAsyncSDODownload_IWORK_k[0];
          if (deviceIndex != NO_ETHERCAT) {
            state = xpcEtherCATgetState( deviceIndex );
            if (state >= 2 ) {
              sigStatusPtr = &gbyk_v4b_B.BKINEtherCATAsyncSDODownload_g;
              sigInputPtr = &gbyk_v4b_B.sf_AbsEncodermachine_k.setupData[0];
              enInputPtr = &gbyk_v4b_B.sf_AbsEncodermachine_k.setupData[1];
              indexInputPtr = &gbyk_v4b_B.sf_AbsEncodermachine_k.setupData[2];
              subIndexInputPtr = &gbyk_v4b_B.sf_AbsEncodermachine_k.setupData[3];
              if (gbyk_v4b_DW.BKINEtherCATAsyncSDODownload_IWORK_k[7] != 0) {
                res = ecatAsyncSDODownload(deviceIndex,
                  1004,
                  (unsigned short)*indexInputPtr,
                  (unsigned char)*subIndexInputPtr,
                  (void *)sigInputPtr,
                  1*4,
                  500,
                  342974287,
                  sigStatusPtr,
                  *enInputPtr);
              } else {
                *sigStatusPtr = 0;
              }

              gbyk_v4b_DW.BKINEtherCATAsyncSDODownload_IWORK_k[7] = 1;
              ;
            }
          }
        }

        /* S-Function (BKINethercatasyncsdoupload): '<S141>/BKIN EtherCAT Async SDO Upload' */
        {
          int8_T *sigOutputPtr;
          int32_T *sigStatusPtr;
          int32_T *enInputPtr;
          int_T deviceIndex;
          static int counter= 0;
          int_T actLen;
          int_T res;
          int_T state;
          int32_T *indexInputPtr;
          int32_T *subIndexInputPtr;
          deviceIndex = gbyk_v4b_DW.BKINEtherCATAsyncSDOUpload_IWORK[0];
          if (deviceIndex != NO_ETHERCAT) {
            state = xpcEtherCATgetState( deviceIndex );
            if (state >= 2 ) {
              sigOutputPtr = &gbyk_v4b_B.BKINEtherCATAsyncSDOUpload_o1;
              sigStatusPtr = &gbyk_v4b_B.BKINEtherCATAsyncSDOUpload_o2;
              enInputPtr = &gbyk_v4b_B.sf_AbsEncodermachine_k.SDORequest[0];
              indexInputPtr = &gbyk_v4b_B.sf_AbsEncodermachine_k.SDORequest[1];
              subIndexInputPtr = &gbyk_v4b_B.sf_AbsEncodermachine_k.SDORequest[2];
              if (gbyk_v4b_DW.BKINEtherCATAsyncSDOUpload_IWORK[7] != 0) {
                res = ecatAsyncSDOUpload(deviceIndex,
                  1004,
                  (unsigned short)*indexInputPtr,
                  (unsigned char)*subIndexInputPtr,
                  (void *)sigOutputPtr,
                  1*4,
                  &actLen,
                  500,
                  342974288,
                  sigStatusPtr,
                  *enInputPtr);
              }

              gbyk_v4b_DW.BKINEtherCATAsyncSDOUpload_IWORK[7] = 1;
              ;
            }
          }
        }

        srUpdateBC(gbyk_v4b_DW.M2AbsEncCalibration_SubsysRanBC);
      } else {
        if (gbyk_v4b_DW.M2AbsEncCalibration_MODE) {
          gbyk_v4b_DW.M2AbsEncCalibration_MODE = false;
        }
      }

      /* End of Constant: '<S76>/enableCalibration' */
      /* End of Outputs for SubSystem: '<S76>/M2 AbsEnc Calibration' */

      /* Outputs for Atomic SubSystem: '<S76>/SDO reading' */
      gbyk_v4b_SDOreading_n();

      /* End of Outputs for SubSystem: '<S76>/SDO reading' */

      /* Outputs for Atomic SubSystem: '<S76>/SDO writing' */
      gbyk_v4b_SDOwriting_f();

      /* End of Outputs for SubSystem: '<S76>/SDO writing' */
      srUpdateBC(gbyk_v4b_DW.Arm2_SubsysRanBC);
    } else {
      if (gbyk_v4b_DW.Arm2_MODE) {
        /* Disable for Enabled SubSystem: '<S76>/M1 AbsEnc Calibration' */
        if (gbyk_v4b_DW.M1AbsEncCalibration_MODE) {
          gbyk_v4b_DW.M1AbsEncCalibration_MODE = false;
        }

        /* End of Disable for SubSystem: '<S76>/M1 AbsEnc Calibration' */

        /* Disable for Enabled SubSystem: '<S76>/M2 AbsEnc Calibration' */
        if (gbyk_v4b_DW.M2AbsEncCalibration_MODE) {
          gbyk_v4b_DW.M2AbsEncCalibration_MODE = false;
        }

        /* End of Disable for SubSystem: '<S76>/M2 AbsEnc Calibration' */
        gbyk_v4b_DW.Arm2_MODE = false;
      }
    }

    /* End of Outputs for SubSystem: '<S64>/Arm 2' */

    /* DataStoreWrite: '<S64>/Data Store Write' */
    gbyk_v4b_DW.ECATHardware[0] = gbyk_v4b_B.R1_maxContinuousTorque_d[0];
    gbyk_v4b_DW.ECATHardware[1] = gbyk_v4b_B.R1_maxContinuousTorque_d[1];
    gbyk_v4b_DW.ECATHardware[2] = gbyk_v4b_B.R2_maxContinuousTorque_e[0];
    gbyk_v4b_DW.ECATHardware[3] = gbyk_v4b_B.R2_maxContinuousTorque_e[1];
    gbyk_v4b_DW.ECATHardware[4] = gbyk_v4b_B.R1_gearRatios[0];
    gbyk_v4b_DW.ECATHardware[5] = gbyk_v4b_B.R1_gearRatios[1];
    gbyk_v4b_DW.ECATHardware[6] = gbyk_v4b_B.R2_gearRatios[0];
    gbyk_v4b_DW.ECATHardware[7] = gbyk_v4b_B.R2_gearRatios[1];
    gbyk_v4b_DW.ECATHardware[8] = gbyk_v4b_B.R1_robotOrientation;
    gbyk_v4b_DW.ECATHardware[9] = gbyk_v4b_B.R2_robotOrientation;
    gbyk_v4b_DW.ECATHardware[10] = gbyk_v4b_B.R1_motorOrientation[0];
    gbyk_v4b_DW.ECATHardware[11] = gbyk_v4b_B.R1_motorOrientation[1];
    gbyk_v4b_DW.ECATHardware[12] = gbyk_v4b_B.R2_motorOrientation[0];
    gbyk_v4b_DW.ECATHardware[13] = gbyk_v4b_B.R2_motorOrientation[1];
    for (i = 0; i < 8; i++) {
      /* DataTypeConversion: '<S64>/convert' */
      gbyk_v4b_B.convert[i] = gbyk_v4b_B.Switch_m[i];

      /* DataStoreWrite: '<S64>/ECat status write' */
      gbyk_v4b_DW.ECATStatus[i] = gbyk_v4b_B.convert[i];
    }

    /* RelationalOperator: '<S77>/Compare' incorporates:
     *  Constant: '<S77>/Constant'
     */
    gbyk_v4b_B.Compare_i = (uint8_T)(gbyk_v4b_B.Convert20 ==
      gbyk_v4b_P.Compare_const_j);

    /* MATLAB Function: '<S79>/update digital outputs' incorporates:
     *  Constant: '<S4>/ZeroDigOut'
     */
    /* MATLAB Function 'EtherCAT Subsystem/Digital output/update digital outputs': '<S191>:1' */
    /* '<S191>:1:9' */
    i = 0;

    /* do nothing to the laser */
    if ((gbyk_v4b_B.Compare_i == 1) && (gbyk_v4b_B.Compare_i !=
         gbyk_v4b_DW.prevRunStatus)) {
      /* '<S191>:1:10' */
      /* if this is the first cycle where we are running, turn the laser */
      /* off */
      /* '<S191>:1:13' */
      i = 1;
    }

    /* '<S191>:1:15' */
    gbyk_v4b_DW.prevRunStatus = gbyk_v4b_B.Compare_i;

    /* '<S191>:1:17' */
    /* '<S191>:1:25' */
    drive1 = 0U;

    /*      if ampStatus ~= 0 */
    /*          outVal = outVal + 1; */
    /*      end */
    /*   */
    /*      if mototStatus ~= 0 */
    /*          outVal = outVal + 2; */
    /*      end */
    if (i != 0) {
      /* '<S191>:1:35' */
      /* '<S191>:1:36' */
      drive1 = 262144U;
    }

    if (gbyk_v4b_P.ZeroDigOut_Value[0] != 0.0) {
      /* '<S191>:1:39' */
      /* '<S191>:1:40' */
      drive1 += 524288U;
    }

    /* '<S191>:1:18' */
    /* '<S191>:1:25' */
    drive2 = 0U;

    /*      if ampStatus ~= 0 */
    /*          outVal = outVal + 1; */
    /*      end */
    /*   */
    /*      if mototStatus ~= 0 */
    /*          outVal = outVal + 2; */
    /*      end */
    if (gbyk_v4b_P.ZeroDigOut_Value[1] != 0.0) {
      /* '<S191>:1:39' */
      /* '<S191>:1:40' */
      drive2 = 524288U;
    }

    /* '<S191>:1:19' */
    /* '<S191>:1:25' */
    drive3 = 0U;

    /*      if ampStatus ~= 0 */
    /*          outVal = outVal + 1; */
    /*      end */
    /*   */
    /*      if mototStatus ~= 0 */
    /*          outVal = outVal + 2; */
    /*      end */
    if (gbyk_v4b_P.ZeroDigOut_Value[2] != 0.0) {
      /* '<S191>:1:39' */
      /* '<S191>:1:40' */
      drive3 = 524288U;
    }

    /* '<S191>:1:20' */
    /* '<S191>:1:25' */
    drive4 = 0U;

    /*      if ampStatus ~= 0 */
    /*          outVal = outVal + 1; */
    /*      end */
    /*   */
    /*      if mototStatus ~= 0 */
    /*          outVal = outVal + 2; */
    /*      end */
    if (gbyk_v4b_P.ZeroDigOut_Value[3] != 0.0) {
      /* '<S191>:1:39' */
      /* '<S191>:1:40' */
      drive4 = 524288U;
    }

    gbyk_v4b_B.drive1 = drive1;
    gbyk_v4b_B.drive2 = drive2;
    gbyk_v4b_B.drive3 = drive3;
    gbyk_v4b_B.drive4 = drive4;

    /* End of MATLAB Function: '<S79>/update digital outputs' */

    /* Level2 S-Function Block: '<S79>/BKIN EtherCAT PDO Transmit ' (BKINethercatpdotx) */
    {
      SimStruct *rts = gbyk_v4b_M->childSfunctions[29];
      sfcnOutputs(rts, 1);
    }

    /* Level2 S-Function Block: '<S79>/BKIN EtherCAT PDO Transmit 1' (BKINethercatpdotx) */
    {
      SimStruct *rts = gbyk_v4b_M->childSfunctions[30];
      sfcnOutputs(rts, 1);
    }

    /* Level2 S-Function Block: '<S79>/BKIN EtherCAT PDO Transmit 2' (BKINethercatpdotx) */
    {
      SimStruct *rts = gbyk_v4b_M->childSfunctions[31];
      sfcnOutputs(rts, 1);
    }

    /* Level2 S-Function Block: '<S79>/BKIN EtherCAT PDO Transmit 3' (BKINethercatpdotx) */
    {
      SimStruct *rts = gbyk_v4b_M->childSfunctions[32];
      sfcnOutputs(rts, 1);
    }

    /* DataStoreRead: '<S34>/Read HasFT' */
    gbyk_v4b_B.ReadHasFT[0] = gbyk_v4b_DW.ArmForceSensors[0];
    gbyk_v4b_B.ReadHasFT[1] = gbyk_v4b_DW.ArmForceSensors[1];

    /* Outputs for Atomic SubSystem: '<S34>/Force Sensor Control' */
    gbyk_v4b_ForceSensorControl();

    /* End of Outputs for SubSystem: '<S34>/Force Sensor Control' */

    /* RelationalOperator: '<S225>/Compare' incorporates:
     *  Constant: '<S225>/Constant'
     */
    gbyk_v4b_B.Compare_a = (gbyk_v4b_B.systemtype == gbyk_v4b_P.ispmac1_const);

    /* Outputs for Enabled SubSystem: '<S67>/Data receive' incorporates:
     *  EnablePort: '<S223>/Enable'
     */
    if (gbyk_v4b_B.Compare_a) {
      /* UnitDelay: '<S226>/Output' */
      gbyk_v4b_B.Output_e = gbyk_v4b_DW.Output_DSTATE_h;

      /* Sum: '<S228>/FixPt Sum1' incorporates:
       *  Constant: '<S228>/FixPt Constant'
       */
      gbyk_v4b_B.FixPtSum1_n = gbyk_v4b_B.Output_e +
        gbyk_v4b_P.FixPtConstant_Value_j;

      /* Switch: '<S229>/FixPt Switch' incorporates:
       *  Constant: '<S229>/Constant'
       */
      if (gbyk_v4b_B.FixPtSum1_n > gbyk_v4b_P.WrapToZero_Threshold_k) {
        gbyk_v4b_B.FixPtSwitch_d = gbyk_v4b_P.Constant_Value_dz;
      } else {
        gbyk_v4b_B.FixPtSwitch_d = gbyk_v4b_B.FixPtSum1_n;
      }

      /* End of Switch: '<S229>/FixPt Switch' */

      /* Level2 S-Function Block: '<S223>/Receive' (xpcudpbytereceive) */
      {
        SimStruct *rts = gbyk_v4b_M->childSfunctions[28];
        sfcnOutputs(rts, 1);
      }

      /* Unpack: <S223>/Unpack */
      (void) memcpy(&gbyk_v4b_B.Unpack_o1[0], &gbyk_v4b_B.Receive_o1_n[0],
                    8);
      (void) memcpy(&gbyk_v4b_B.Unpack_o2[0], &gbyk_v4b_B.Receive_o1_n[8],
                    8);

      /* DataTypeConversion: '<S223>/Data Type Conversion' */
      gbyk_v4b_B.DataTypeConversion_k[0] = gbyk_v4b_B.Unpack_o1[0];
      gbyk_v4b_B.DataTypeConversion_k[1] = gbyk_v4b_B.Unpack_o1[1];

      /* DataTypeConversion: '<S223>/Data Type Conversion1' */
      gbyk_v4b_B.DataTypeConversion1_a[0] = gbyk_v4b_B.Unpack_o2[0];
      gbyk_v4b_B.DataTypeConversion1_a[1] = gbyk_v4b_B.Unpack_o2[1];

      /* DataTypeConversion: '<S223>/Data Type Conversion2' */
      gbyk_v4b_B.DataTypeConversion2_i = gbyk_v4b_B.Output_e;

      /* MATLAB Function: '<S223>/MATLAB Function' */
      /* MATLAB Function 'DataLogging/Poll KINARM/bkin_internal_testing/Data receive/MATLAB Function': '<S227>:1' */
      if (gbyk_v4b_B.Receive_o2_o == 1.0) {
        /* '<S227>:1:14' */
        /* '<S227>:1:15' */
        ticksPerRad = gbyk_v4b_DW.r1Sho[0];
        queueSizePrimary = gbyk_v4b_DW.r1Sho[1];
        queueSizeSecondary = gbyk_v4b_DW.r1Sho[2];
        gbyk_v4b_DW.r1Sho[1] = ticksPerRad;
        gbyk_v4b_DW.r1Sho[2] = queueSizePrimary;
        gbyk_v4b_DW.r1Sho[3] = queueSizeSecondary;

        /* '<S227>:1:16' */
        ticksPerRad = gbyk_v4b_DW.r1Elb[0];
        queueSizePrimary = gbyk_v4b_DW.r1Elb[1];
        queueSizeSecondary = gbyk_v4b_DW.r1Elb[2];
        gbyk_v4b_DW.r1Elb[1] = ticksPerRad;
        gbyk_v4b_DW.r1Elb[2] = queueSizePrimary;
        gbyk_v4b_DW.r1Elb[3] = queueSizeSecondary;

        /* '<S227>:1:17' */
        ticksPerRad = gbyk_v4b_DW.r2Sho[0];
        queueSizePrimary = gbyk_v4b_DW.r2Sho[1];
        queueSizeSecondary = gbyk_v4b_DW.r2Sho[2];
        gbyk_v4b_DW.r2Sho[1] = ticksPerRad;
        gbyk_v4b_DW.r2Sho[2] = queueSizePrimary;
        gbyk_v4b_DW.r2Sho[3] = queueSizeSecondary;

        /* '<S227>:1:18' */
        ticksPerRad = gbyk_v4b_DW.r2Elb[0];
        queueSizePrimary = gbyk_v4b_DW.r2Elb[1];
        queueSizeSecondary = gbyk_v4b_DW.r2Elb[2];
        gbyk_v4b_DW.r2Elb[1] = ticksPerRad;
        gbyk_v4b_DW.r2Elb[2] = queueSizePrimary;
        gbyk_v4b_DW.r2Elb[3] = queueSizeSecondary;

        /* '<S227>:1:20' */
        gbyk_v4b_DW.r1Sho[0] = gbyk_v4b_B.DataTypeConversion_k[0];

        /* '<S227>:1:21' */
        gbyk_v4b_DW.r1Elb[0] = gbyk_v4b_B.DataTypeConversion_k[1];

        /* '<S227>:1:22' */
        gbyk_v4b_DW.r2Sho[0] = gbyk_v4b_B.DataTypeConversion1_a[0];

        /* '<S227>:1:23' */
        gbyk_v4b_DW.r2Elb[0] = gbyk_v4b_B.DataTypeConversion1_a[1];

        /* '<S227>:1:25' */
        ticksPerRad = gbyk_v4b_DW.last_tick[0];
        queueSizePrimary = gbyk_v4b_DW.last_tick[1];
        queueSizeSecondary = gbyk_v4b_DW.last_tick[2];
        gbyk_v4b_DW.last_tick[1] = ticksPerRad;
        gbyk_v4b_DW.last_tick[2] = queueSizePrimary;
        gbyk_v4b_DW.last_tick[3] = queueSizeSecondary;

        /* '<S227>:1:26' */
        gbyk_v4b_DW.last_tick[0] = gbyk_v4b_B.DataTypeConversion2_i *
          gbyk_v4b_P.MATLABFunction_BKIN_STEP_TIME;
      }

      /* '<S227>:1:29' */
      for (i = 0; i < 20; i++) {
        gbyk_v4b_B.kinematics[i] = 0.0;
      }

      /* '<S227>:1:30' */
      for (i = 0; i < 12; i++) {
        gbyk_v4b_B.primary[i] = 0.0;
      }

      /* '<S227>:1:32' */
      gbyk_v4b_B.kinematics[0] = gbyk_v4b_DW.r1Sho[0];
      gbyk_v4b_B.kinematics[1] = gbyk_v4b_DW.r1Elb[0];

      /* [kinematics(3), kinematics(5)] = velAndAcc(r1Sho, last_tick); */
      /* [kinematics(4), kinematics(6)] = velAndAcc(r1Elb, last_tick); */
      /* kinematics(7:8) = kinematics(5:6); */
      /* '<S227>:1:37' */
      gbyk_v4b_B.kinematics[10] = gbyk_v4b_DW.r2Sho[0];
      gbyk_v4b_B.kinematics[11] = gbyk_v4b_DW.r2Elb[0];

      /* [kinematics(13), kinematics(15)] = velAndAcc(r2Sho, last_tick); */
      /* [kinematics(14), kinematics(16)] = velAndAcc(r2Elb, last_tick); */
      /* kinematics(17:18) = kinematics(15:16); */
      /* '<S227>:1:42' */
      for (i = 0; i < 6; i++) {
        gbyk_v4b_B.primary[i] = gbyk_v4b_B.kinematics[i];
      }

      /* '<S227>:1:43' */
      for (i = 0; i < 6; i++) {
        gbyk_v4b_B.primary[i + 6] = gbyk_v4b_B.kinematics[i + 10];
      }

      /* End of MATLAB Function: '<S223>/MATLAB Function' */

      /* Constant: '<S223>/Constant' */
      gbyk_v4b_B.Constant = gbyk_v4b_P.Constant_Value_di;

      /* Constant: '<S223>/Constant1' */
      for (i = 0; i < 7; i++) {
        gbyk_v4b_B.Constant1[i] = gbyk_v4b_P.Constant1_Value_gt[i];
      }

      /* End of Constant: '<S223>/Constant1' */
      srUpdateBC(gbyk_v4b_DW.Datareceive_SubsysRanBC);
    }

    /* End of Outputs for SubSystem: '<S67>/Data receive' */

    /* Constant: '<S230>/Arm Orientation' */
    gbyk_v4b_B.ArmOrientation_b = gbyk_v4b_P.ArmOrientation_Value;

    /* Constant: '<S230>/Arm Motor1 Orientation' */
    gbyk_v4b_B.M1orientation_h = gbyk_v4b_P.ArmMotor1Orientation_Value;

    /* Constant: '<S230>/Arm Motor2 Orientation' */
    gbyk_v4b_B.M2Orientation_l = gbyk_v4b_P.ArmMotor2Orientation_Value;

    /* Constant: '<S230>/Arm Motor1 Gear Ratio' */
    gbyk_v4b_B.M1GearRatio_b = gbyk_v4b_P.ArmMotor1GearRatio_Value;

    /* Constant: '<S230>/Arm Motor2 Gear Ratio' */
    gbyk_v4b_B.M2GearRatio_p = gbyk_v4b_P.ArmMotor2GearRatio_Value;

    /* Constant: '<S230>/Arm Secondary Encoders' */
    gbyk_v4b_B.HasSecondaryEnc_n = gbyk_v4b_P.ArmSecondaryEncoders_Value;

    /* Constant: '<S231>/Arm Orientation' */
    gbyk_v4b_B.ArmOrientation_l = gbyk_v4b_P.ArmOrientation_Value_p;

    /* Constant: '<S231>/Arm Motor1 Orientation' */
    gbyk_v4b_B.M1orientation_n = gbyk_v4b_P.ArmMotor1Orientation_Value_a;

    /* Constant: '<S231>/Arm Motor2 Orientation' */
    gbyk_v4b_B.M2Orientation_cw = gbyk_v4b_P.ArmMotor2Orientation_Value_a;

    /* Constant: '<S231>/Arm Motor1 Gear Ratio' */
    gbyk_v4b_B.M1GearRatio_k = gbyk_v4b_P.ArmMotor1GearRatio_Value_b;

    /* Constant: '<S231>/Arm Motor2 Gear Ratio' */
    gbyk_v4b_B.M2GearRatio_l = gbyk_v4b_P.ArmMotor2GearRatio_Value_a;

    /* Constant: '<S231>/Arm Secondary Encoders' */
    gbyk_v4b_B.HasSecondaryEnc_f = gbyk_v4b_P.ArmSecondaryEncoders_Value_h;

    /* RelationalOperator: '<S72>/Compare' incorporates:
     *  Constant: '<S72>/Constant'
     */
    gbyk_v4b_B.Compare_c = (gbyk_v4b_B.systemtype == gbyk_v4b_P.ispmac_const);

    /* Outputs for Enabled SubSystem: '<S66>/read_pmac' */
    gbyk_v4b_read_pmac();

    /* End of Outputs for SubSystem: '<S66>/read_pmac' */

    /* UnitDelay: '<S78>/Output' */
    gbyk_v4b_B.Output_a = gbyk_v4b_DW.Output_DSTATE_c;

    /* MATLAB Function: '<S64>/latch_errors' */
    for (i = 0; i < 8; i++) {
      status[i] = gbyk_v4b_B.Switch_m[i];
    }

    drive1 = gbyk_v4b_B.Output_a;

    /* MATLAB Function 'EtherCAT Subsystem/latch_errors': '<S81>:1' */
    if ((gbyk_v4b_B.Switch_m[1] == 8) && (gbyk_v4b_DW.enteredOpStep == 0U)) {
      /* '<S81>:1:12' */
      /* '<S81>:1:13' */
      gbyk_v4b_DW.enteredOpStep = gbyk_v4b_B.Output_a;
    }

    /* ignore these 2 error types before we hit the OP state and for at least */
    /* a few rounds after. */
    drive2 = gbyk_v4b_B.Output_a;
    drive3 = drive2 - gbyk_v4b_DW.enteredOpStep;
    if (drive3 > drive2) {
      drive3 = 0U;
    }

    if (((gbyk_v4b_B.Switch_m[0] == 65551) || (gbyk_v4b_B.Switch_m[0] == 65569))
        && ((gbyk_v4b_DW.enteredOpStep == 0U) || (drive3 < 10U))) {
      /* '<S81>:1:18' */
      /* '<S81>:1:19' */
      /* '<S81>:1:20' */
      status[0] = 22;
    }

    if ((gbyk_v4b_DW.latchedErrors[0] != status[0]) && (status[0] != 0)) {
      /* '<S81>:1:24' */
      /* '<S81>:1:25' */
      gbyk_v4b_circshift_j(gbyk_v4b_DW.latchedErrors);

      /* '<S81>:1:26' */
      gbyk_v4b_DW.latchedErrors[0] = status[0];

      /* '<S81>:1:27' */
      gbyk_v4b_DW.latchedErrors[1] = drive1;
    }

    if ((gbyk_v4b_DW.latchedDCErrors[0] != status[2]) && (status[2] != 0)) {
      /* '<S81>:1:30' */
      /* '<S81>:1:31' */
      gbyk_v4b_circshift_j(gbyk_v4b_DW.latchedDCErrors);

      /* '<S81>:1:32' */
      gbyk_v4b_DW.latchedDCErrors[0] = status[2];

      /* '<S81>:1:33' */
      gbyk_v4b_DW.latchedDCErrors[1] = drive1;
    }

    /* '<S81>:1:36' */
    /* '<S81>:1:37' */
    for (i = 0; i < 12; i++) {
      gbyk_v4b_B.errVals[i] = gbyk_v4b_DW.latchedErrors[i];
      gbyk_v4b_B.DCErrVals[i] = gbyk_v4b_DW.latchedDCErrors[i];
    }

    /* End of MATLAB Function: '<S64>/latch_errors' */

    /* Chart: '<S34>/control read write' */
    /* Gateway: DataLogging/Poll KINARM/control read write */
    gbyk_v4b_DW.sfEvent_n = -1;

    /* During: DataLogging/Poll KINARM/control read write */
    if (gbyk_v4b_DW.is_active_c38_General == 0U) {
      /* Entry: DataLogging/Poll KINARM/control read write */
      gbyk_v4b_DW.is_active_c38_General = 1U;

      /* Entry Internal: DataLogging/Poll KINARM/control read write */
      /* Transition: '<S69>:215' */
      if (gbyk_v4b_B.systemtype == 2.0) {
        /* Transition: '<S69>:220' */
        gbyk_v4b_DW.is_c38_General = gbyk_v4b_IN_RunECat;
      } else if (gbyk_v4b_B.systemtype == 1.0) {
        /* Transition: '<S69>:222' */
        gbyk_v4b_DW.is_c38_General = gbyk_v4b_IN_RunPMAC;
      } else {
        /* Transition: '<S69>:218' */
        gbyk_v4b_DW.is_c38_General = gbyk_v4b_IN_RunSim;
      }
    } else {
      switch (gbyk_v4b_DW.is_c38_General) {
       case gbyk_v4b_IN_RunECat:
        /* Outputs for Function Call SubSystem: '<S64>/update' */
        /* DataTypeConversion: '<S84>/Data Type Conversion1' */
        /* During 'RunECat': '<S69>:219' */
        /* Event: '<S69>:207' */
        ticksPerRad = floor(gbyk_v4b_B.R1_calibrationButton);
        if (rtIsNaN(ticksPerRad) || rtIsInf(ticksPerRad)) {
          ticksPerRad = 0.0;
        } else {
          ticksPerRad = fmod(ticksPerRad, 4.294967296E+9);
        }

        gbyk_v4b_B.DataTypeConversion1_ju[0] = ticksPerRad < 0.0 ? (uint32_T)
          -(int32_T)(uint32_T)-ticksPerRad : (uint32_T)ticksPerRad;
        ticksPerRad = floor(gbyk_v4b_B.R2_calibrationButton);
        if (rtIsNaN(ticksPerRad) || rtIsInf(ticksPerRad)) {
          ticksPerRad = 0.0;
        } else {
          ticksPerRad = fmod(ticksPerRad, 4.294967296E+9);
        }

        gbyk_v4b_B.DataTypeConversion1_ju[1] = ticksPerRad < 0.0 ? (uint32_T)
          -(int32_T)(uint32_T)-ticksPerRad : (uint32_T)ticksPerRad;

        /* End of DataTypeConversion: '<S84>/Data Type Conversion1' */

        /* MATLAB Function: '<S84>/convert to bit field' */
        /* MATLAB Function 'EtherCAT Subsystem/update/convert to bit field': '<S193>:1' */
        /* '<S193>:1:3' */
        tmp_1 = (uint64_T)(gbyk_v4b_B.DataTypeConversion1_ju[1] << 1U) +
          gbyk_v4b_B.DataTypeConversion1_ju[0];
        if (tmp_1 > 4294967295ULL) {
          tmp_1 = 4294967295ULL;
        }

        gbyk_v4b_B.bitField = (uint32_T)tmp_1;

        /* End of MATLAB Function: '<S84>/convert to bit field' */

        /* DataStoreWrite: '<S84>/Calib write' */
        gbyk_v4b_DW.CalibrationButton = gbyk_v4b_B.bitField;

        /* DataTypeConversion: '<S84>/Data Type Conversion' */
        ticksPerRad = floor(gbyk_v4b_B.R1M1_digitalInputs[0]);
        if (rtIsNaN(ticksPerRad) || rtIsInf(ticksPerRad)) {
          ticksPerRad = 0.0;
        } else {
          ticksPerRad = fmod(ticksPerRad, 4.294967296E+9);
        }

        gbyk_v4b_B.DataTypeConversion_jq[0] = ticksPerRad < 0.0 ? (uint32_T)
          -(int32_T)(uint32_T)-ticksPerRad : (uint32_T)ticksPerRad;
        ticksPerRad = floor(gbyk_v4b_B.R1M1_digitalInputs[1]);
        if (rtIsNaN(ticksPerRad) || rtIsInf(ticksPerRad)) {
          ticksPerRad = 0.0;
        } else {
          ticksPerRad = fmod(ticksPerRad, 4.294967296E+9);
        }

        gbyk_v4b_B.DataTypeConversion_jq[1] = ticksPerRad < 0.0 ? (uint32_T)
          -(int32_T)(uint32_T)-ticksPerRad : (uint32_T)ticksPerRad;
        ticksPerRad = floor(gbyk_v4b_B.R1M2_digitalInputs[0]);
        if (rtIsNaN(ticksPerRad) || rtIsInf(ticksPerRad)) {
          ticksPerRad = 0.0;
        } else {
          ticksPerRad = fmod(ticksPerRad, 4.294967296E+9);
        }

        gbyk_v4b_B.DataTypeConversion_jq[2] = ticksPerRad < 0.0 ? (uint32_T)
          -(int32_T)(uint32_T)-ticksPerRad : (uint32_T)ticksPerRad;
        ticksPerRad = floor(gbyk_v4b_B.R1M2_digitalInputs[1]);
        if (rtIsNaN(ticksPerRad) || rtIsInf(ticksPerRad)) {
          ticksPerRad = 0.0;
        } else {
          ticksPerRad = fmod(ticksPerRad, 4.294967296E+9);
        }

        gbyk_v4b_B.DataTypeConversion_jq[3] = ticksPerRad < 0.0 ? (uint32_T)
          -(int32_T)(uint32_T)-ticksPerRad : (uint32_T)ticksPerRad;
        ticksPerRad = floor(gbyk_v4b_B.R2M1_digitalInputs[0]);
        if (rtIsNaN(ticksPerRad) || rtIsInf(ticksPerRad)) {
          ticksPerRad = 0.0;
        } else {
          ticksPerRad = fmod(ticksPerRad, 4.294967296E+9);
        }

        gbyk_v4b_B.DataTypeConversion_jq[4] = ticksPerRad < 0.0 ? (uint32_T)
          -(int32_T)(uint32_T)-ticksPerRad : (uint32_T)ticksPerRad;
        ticksPerRad = floor(gbyk_v4b_B.R2M1_digitalInputs[1]);
        if (rtIsNaN(ticksPerRad) || rtIsInf(ticksPerRad)) {
          ticksPerRad = 0.0;
        } else {
          ticksPerRad = fmod(ticksPerRad, 4.294967296E+9);
        }

        gbyk_v4b_B.DataTypeConversion_jq[5] = ticksPerRad < 0.0 ? (uint32_T)
          -(int32_T)(uint32_T)-ticksPerRad : (uint32_T)ticksPerRad;
        ticksPerRad = floor(gbyk_v4b_B.R2M2_digitalInputs[0]);
        if (rtIsNaN(ticksPerRad) || rtIsInf(ticksPerRad)) {
          ticksPerRad = 0.0;
        } else {
          ticksPerRad = fmod(ticksPerRad, 4.294967296E+9);
        }

        gbyk_v4b_B.DataTypeConversion_jq[6] = ticksPerRad < 0.0 ? (uint32_T)
          -(int32_T)(uint32_T)-ticksPerRad : (uint32_T)ticksPerRad;
        ticksPerRad = floor(gbyk_v4b_B.R2M2_digitalInputs[1]);
        if (rtIsNaN(ticksPerRad) || rtIsInf(ticksPerRad)) {
          ticksPerRad = 0.0;
        } else {
          ticksPerRad = fmod(ticksPerRad, 4.294967296E+9);
        }

        gbyk_v4b_B.DataTypeConversion_jq[7] = ticksPerRad < 0.0 ? (uint32_T)
          -(int32_T)(uint32_T)-ticksPerRad : (uint32_T)ticksPerRad;

        /* End of DataTypeConversion: '<S84>/Data Type Conversion' */

        /* DataStoreWrite: '<S84>/Data Store Write' */
        for (i = 0; i < 8; i++) {
          gbyk_v4b_DW.ECATDigitalInput[i] = gbyk_v4b_B.DataTypeConversion_jq[i];
        }

        /* End of DataStoreWrite: '<S84>/Data Store Write' */

        /* DataStoreWrite: '<S84>/Data Store Write6' */
        gbyk_v4b_DW.RobotRevision[0] = gbyk_v4b_B.R1_RobotRevision;
        gbyk_v4b_DW.RobotRevision[1] = gbyk_v4b_B.R2_RobotRevision;

        /* DataTypeConversion: '<S84>/Data Type Conversion4' */
        ticksPerRad = floor(gbyk_v4b_B.R1M1_digitalDiagnostics);
        if (rtIsNaN(ticksPerRad) || rtIsInf(ticksPerRad)) {
          ticksPerRad = 0.0;
        } else {
          ticksPerRad = fmod(ticksPerRad, 4.294967296E+9);
        }

        gbyk_v4b_B.DataTypeConversion4_j[0] = ticksPerRad < 0.0 ? (uint32_T)
          -(int32_T)(uint32_T)-ticksPerRad : (uint32_T)ticksPerRad;
        ticksPerRad = floor(gbyk_v4b_B.R1M2_digitalDiagnostics);
        if (rtIsNaN(ticksPerRad) || rtIsInf(ticksPerRad)) {
          ticksPerRad = 0.0;
        } else {
          ticksPerRad = fmod(ticksPerRad, 4.294967296E+9);
        }

        gbyk_v4b_B.DataTypeConversion4_j[1] = ticksPerRad < 0.0 ? (uint32_T)
          -(int32_T)(uint32_T)-ticksPerRad : (uint32_T)ticksPerRad;
        ticksPerRad = floor(gbyk_v4b_B.R2M1_digitalDiagnostics);
        if (rtIsNaN(ticksPerRad) || rtIsInf(ticksPerRad)) {
          ticksPerRad = 0.0;
        } else {
          ticksPerRad = fmod(ticksPerRad, 4.294967296E+9);
        }

        gbyk_v4b_B.DataTypeConversion4_j[2] = ticksPerRad < 0.0 ? (uint32_T)
          -(int32_T)(uint32_T)-ticksPerRad : (uint32_T)ticksPerRad;
        ticksPerRad = floor(gbyk_v4b_B.R2M2_digitalDiagnostics);
        if (rtIsNaN(ticksPerRad) || rtIsInf(ticksPerRad)) {
          ticksPerRad = 0.0;
        } else {
          ticksPerRad = fmod(ticksPerRad, 4.294967296E+9);
        }

        gbyk_v4b_B.DataTypeConversion4_j[3] = ticksPerRad < 0.0 ? (uint32_T)
          -(int32_T)(uint32_T)-ticksPerRad : (uint32_T)ticksPerRad;

        /* End of DataTypeConversion: '<S84>/Data Type Conversion4' */

        /* DataStoreWrite: '<S84>/ECat status write' */
        gbyk_v4b_DW.ECATDigDiagnostic[0] = gbyk_v4b_B.DataTypeConversion4_j[0];
        gbyk_v4b_DW.ECATDigDiagnostic[1] = gbyk_v4b_B.DataTypeConversion4_j[1];
        gbyk_v4b_DW.ECATDigDiagnostic[2] = gbyk_v4b_B.DataTypeConversion4_j[2];
        gbyk_v4b_DW.ECATDigDiagnostic[3] = gbyk_v4b_B.DataTypeConversion4_j[3];

        /* DataStoreWrite: '<S84>/Force sensor write' */
        gbyk_v4b_DW.ArmForceSensors[0] = gbyk_v4b_B.R1_hasFT;
        gbyk_v4b_DW.ArmForceSensors[1] = gbyk_v4b_B.R2_hasFT;

        /* DataTypeConversion: '<S84>/Data Type Conversion2' */
        gbyk_v4b_B.DataTypeConversion2_ir = (uint32_T)gbyk_v4b_B.masterState;

        /* DataStoreWrite: '<S84>/Status write' incorporates:
         *  Constant: '<S84>/Constant1'
         */
        gbyk_v4b_DW.SystemStatus[0] = gbyk_v4b_B.motorStatus_f;
        gbyk_v4b_DW.SystemStatus[1] =
          gbyk_v4b_B.sf_ControlGDCWhistleState_f.motorStatus;
        gbyk_v4b_DW.SystemStatus[2] =
          gbyk_v4b_B.sf_ControlGDCWhistleState_p.motorStatus;
        gbyk_v4b_DW.SystemStatus[3] = gbyk_v4b_B.motorStatus;
        gbyk_v4b_DW.SystemStatus[4] = gbyk_v4b_P.Constant1_Value_k;
        gbyk_v4b_DW.SystemStatus[5] = gbyk_v4b_B.DataTypeConversion2_ir;
        gbyk_v4b_DW.SystemStatus[6] = gbyk_v4b_B.sf_parsestatusregister.eStopOut;

        /* DataStoreRead: '<S84>/Data Store' */
        memcpy(&gbyk_v4b_B.DataStore[0], &gbyk_v4b_DW.RobotCalibrations[0],
               sizeof(real_T) << 4U);

        /* SignalConversion: '<S199>/TmpSignal ConversionAt SFunction Inport2' incorporates:
         *  MATLAB Function: '<S84>/update calibrations'
         */
        gbyk_v4b_B.TmpSignalConversionAtSFunctionInport2_l[0] =
          gbyk_v4b_B.R1_LinkLength[0];
        gbyk_v4b_B.TmpSignalConversionAtSFunctionInport2_l[1] =
          gbyk_v4b_B.R1_LinkLength[1];
        gbyk_v4b_B.TmpSignalConversionAtSFunctionInport2_l[2] =
          gbyk_v4b_B.R2_LinkLength[0];
        gbyk_v4b_B.TmpSignalConversionAtSFunctionInport2_l[3] =
          gbyk_v4b_B.R2_LinkLength[1];

        /* SignalConversion: '<S199>/TmpSignal ConversionAt SFunction Inport4' incorporates:
         *  MATLAB Function: '<S84>/update calibrations'
         */
        gbyk_v4b_B.TmpSignalConversionAtSFunctionInport4[0] =
          gbyk_v4b_B.R1_RobotType;
        gbyk_v4b_B.TmpSignalConversionAtSFunctionInport4[1] =
          gbyk_v4b_B.R2_RobotType;

        /* MATLAB Function: '<S84>/update calibrations' */
        /* MATLAB Function 'EtherCAT Subsystem/update/update calibrations': '<S199>:1' */
        /* '<S199>:1:3' */
        /* '<S199>:1:4' */
        for (i = 0; i < 8; i++) {
          r1Calibs[i] = gbyk_v4b_B.DataStore[i];
          r2Calibs[i] = gbyk_v4b_B.DataStore[i + 8];
        }

        /* only EP's can read teh link lengths from the drive */
        if (gbyk_v4b_B.TmpSignalConversionAtSFunctionInport4[0] == 1.0) {
          /* '<S199>:1:7' */
          /* '<S199>:1:8' */
          r1Calibs[4] = gbyk_v4b_B.TmpSignalConversionAtSFunctionInport2_l[0];

          /* '<S199>:1:9' */
          r1Calibs[5] = gbyk_v4b_B.TmpSignalConversionAtSFunctionInport2_l[1];
        }

        /* only EP's can read teh link lengths from the drive */
        if (gbyk_v4b_B.TmpSignalConversionAtSFunctionInport4[1] == 1.0) {
          /* '<S199>:1:13' */
          /* '<S199>:1:14' */
          r2Calibs[4] = gbyk_v4b_B.TmpSignalConversionAtSFunctionInport2_l[0];

          /* '<S199>:1:15' */
          r2Calibs[5] = gbyk_v4b_B.TmpSignalConversionAtSFunctionInport2_l[1];
        }

        /* '<S199>:1:17' */
        memcpy(&gbyk_v4b_B.calibrationsOut[0], &r1Calibs[0], sizeof(real_T) <<
               3U);
        memcpy(&gbyk_v4b_B.calibrationsOut[8], &r2Calibs[0], sizeof(real_T) <<
               3U);

        /* DataStoreWrite: '<S84>/calib write' */
        memcpy(&gbyk_v4b_DW.RobotCalibrations[0], &gbyk_v4b_B.calibrationsOut[0],
               sizeof(real_T) << 4U);

        /* DataStoreRead: '<S84>/Data Store1' */
        memcpy(&gbyk_v4b_B.DataStore1[0], &gbyk_v4b_DW.HardwareSettings[0], 24U *
               sizeof(real_T));

        /* SignalConversion: '<S198>/TmpSignal ConversionAt SFunction Inport2' incorporates:
         *  MATLAB Function: '<S84>/update HW settings'
         */
        gbyk_v4b_B.TmpSignalConversionAtSFunctionInport2_b[0] =
          gbyk_v4b_B.R1_RobotType;
        gbyk_v4b_B.TmpSignalConversionAtSFunctionInport2_b[1] =
          gbyk_v4b_B.R2_RobotType;

        /* SignalConversion: '<S198>/TmpSignal ConversionAt SFunction Inport3' incorporates:
         *  MATLAB Function: '<S84>/update HW settings'
         */
        gbyk_v4b_B.TmpSignalConversionAtSFunctionInport3_h[0] =
          gbyk_v4b_B.R1_FTSensorAngleOffset;
        gbyk_v4b_B.TmpSignalConversionAtSFunctionInport3_h[1] =
          gbyk_v4b_B.R2_FTSensorAngleOffset;

        /* SignalConversion: '<S198>/TmpSignal ConversionAt SFunction Inport4' incorporates:
         *  MATLAB Function: '<S84>/update HW settings'
         */
        gbyk_v4b_B.TmpSignalConversionAtSFunctionInport4_i[0] =
          gbyk_v4b_B.R1_robotOrientation;
        gbyk_v4b_B.TmpSignalConversionAtSFunctionInport4_i[1] =
          gbyk_v4b_B.R2_robotOrientation;

        /* MATLAB Function: '<S84>/update HW settings' */
        /* MATLAB Function 'EtherCAT Subsystem/update/update HW settings': '<S198>:1' */
        /* '<S198>:1:3' */
        /* '<S198>:1:4' */
        for (i = 0; i < 12; i++) {
          r1SettingsOut[i] = gbyk_v4b_B.DataStore1[i];
          r2SettingsOut[i] = gbyk_v4b_B.DataStore1[i + 12];
        }

        /* '<S198>:1:5' */
        r1SettingsOut[0] = gbyk_v4b_B.TmpSignalConversionAtSFunctionInport2_b[0];

        /* '<S198>:1:6' */
        r2SettingsOut[0] = gbyk_v4b_B.TmpSignalConversionAtSFunctionInport2_b[1];

        /* '<S198>:1:7' */
        r1SettingsOut[4] = gbyk_v4b_B.TmpSignalConversionAtSFunctionInport3_h[0];

        /* '<S198>:1:8' */
        r2SettingsOut[4] = gbyk_v4b_B.TmpSignalConversionAtSFunctionInport3_h[1];

        /* '<S198>:1:9' */
        r1SettingsOut[6] = gbyk_v4b_B.TmpSignalConversionAtSFunctionInport4_i[0];

        /* '<S198>:1:10' */
        r2SettingsOut[6] = gbyk_v4b_B.TmpSignalConversionAtSFunctionInport4_i[1];

        /* '<S198>:1:12' */
        memcpy(&gbyk_v4b_B.settingsOut[0], &r1SettingsOut[0], 12U * sizeof
               (real_T));
        memcpy(&gbyk_v4b_B.settingsOut[12], &r2SettingsOut[0], 12U * sizeof
               (real_T));

        /* DataStoreWrite: '<S84>/hardware write' */
        memcpy(&gbyk_v4b_DW.HardwareSettings[0], &gbyk_v4b_B.settingsOut[0], 24U
               * sizeof(real_T));

        /* SignalConversion: '<S195>/TmpSignal ConversionAt SFunction Inport1' incorporates:
         *  MATLAB Function: '<S84>/create kinematics'
         */
        gbyk_v4b_B.TmpSignalConversionAtSFunctionInport1_p[0] =
          gbyk_v4b_B.R1M1_LinkAngle;
        gbyk_v4b_B.TmpSignalConversionAtSFunctionInport1_p[1] =
          gbyk_v4b_B.R1M2_LinkAngle;
        gbyk_v4b_B.TmpSignalConversionAtSFunctionInport1_p[2] =
          gbyk_v4b_B.R2M1_LinkAngle;
        gbyk_v4b_B.TmpSignalConversionAtSFunctionInport1_p[3] =
          gbyk_v4b_B.R2M2_LinkAngle;

        /* SignalConversion: '<S195>/TmpSignal ConversionAt SFunction Inport2' incorporates:
         *  MATLAB Function: '<S84>/create kinematics'
         */
        gbyk_v4b_B.TmpSignalConversionAtSFunctionInport2_bj[0] =
          gbyk_v4b_B.R1M1_PrimaryLinkAngle;
        gbyk_v4b_B.TmpSignalConversionAtSFunctionInport2_bj[1] =
          gbyk_v4b_B.R1M2_PrimaryLinkAngle;
        gbyk_v4b_B.TmpSignalConversionAtSFunctionInport2_bj[2] =
          gbyk_v4b_B.R2M1_PrimaryLinkAngle;
        gbyk_v4b_B.TmpSignalConversionAtSFunctionInport2_bj[3] =
          gbyk_v4b_B.R2M2_PrimaryLinkAngle;

        /* SignalConversion: '<S195>/TmpSignal ConversionAt SFunction Inport3' incorporates:
         *  MATLAB Function: '<S84>/create kinematics'
         */
        gbyk_v4b_B.TmpSignalConversionAtSFunctionInport3_g[0] =
          gbyk_v4b_B.R1M1_PrimaryLinkVelocity;
        gbyk_v4b_B.TmpSignalConversionAtSFunctionInport3_g[1] =
          gbyk_v4b_B.R1M2_PrimaryLinkVelocity;
        gbyk_v4b_B.TmpSignalConversionAtSFunctionInport3_g[2] =
          gbyk_v4b_B.R2M1_PrimaryLinkVelocity;
        gbyk_v4b_B.TmpSignalConversionAtSFunctionInport3_g[3] =
          gbyk_v4b_B.R2M2_PrimaryLinkVelocity;

        /* SignalConversion: '<S195>/TmpSignal ConversionAt SFunction Inport4' incorporates:
         *  MATLAB Function: '<S84>/create kinematics'
         */
        gbyk_v4b_B.TmpSignalConversionAtSFunctionInport4_b[0] =
          gbyk_v4b_B.R1_hasSecondary;
        gbyk_v4b_B.TmpSignalConversionAtSFunctionInport4_b[1] =
          gbyk_v4b_B.R2_hasSecondary;

        /* SignalConversion: '<S195>/TmpSignal ConversionAt SFunction Inport5' incorporates:
         *  MATLAB Function: '<S84>/create kinematics'
         */
        gbyk_v4b_B.TmpSignalConversionAtSFunctionInport5[0] =
          gbyk_v4b_B.motorStatus_f;
        gbyk_v4b_B.TmpSignalConversionAtSFunctionInport5[1] =
          gbyk_v4b_B.sf_ControlGDCWhistleState_f.motorStatus;
        gbyk_v4b_B.TmpSignalConversionAtSFunctionInport5[2] =
          gbyk_v4b_B.sf_ControlGDCWhistleState_p.motorStatus;
        gbyk_v4b_B.TmpSignalConversionAtSFunctionInport5[3] =
          gbyk_v4b_B.motorStatus;

        /* SignalConversion: '<S195>/TmpSignal ConversionAt SFunction Inport6' incorporates:
         *  MATLAB Function: '<S84>/create kinematics'
         */
        gbyk_v4b_B.TmpSignalConversionAtSFunctionInport6[0] =
          gbyk_v4b_B.R1_robotOrientation;
        gbyk_v4b_B.TmpSignalConversionAtSFunctionInport6[1] =
          gbyk_v4b_B.R2_robotOrientation;

        /* SignalConversion: '<S195>/TmpSignal ConversionAt SFunction Inport8' incorporates:
         *  MATLAB Function: '<S84>/create kinematics'
         */
        gbyk_v4b_B.TmpSignalConversionAtSFunctionInport8[0] =
          gbyk_v4b_B.R1_constantsReady_p;
        gbyk_v4b_B.TmpSignalConversionAtSFunctionInport8[1] =
          gbyk_v4b_B.R2_constantsReady_j;

        /* MATLAB Function: '<S84>/create kinematics' incorporates:
         *  Constant: '<S84>/Constant'
         */
        gbyk_v4b_B.delays[0] = 0.001;
        gbyk_v4b_B.delays[1] = 0.002;
        gbyk_v4b_B.delays[2] = 0.0005;
        gbyk_v4b_B.delays[3] = 0.001;
        anglesPrimary[0] = gbyk_v4b_B.TmpSignalConversionAtSFunctionInport2_bj[0];
        anglesPrimary[1] = gbyk_v4b_B.TmpSignalConversionAtSFunctionInport2_bj[1];
        anglesPrimary[2] = gbyk_v4b_B.TmpSignalConversionAtSFunctionInport2_bj[2];
        anglesPrimary[3] = gbyk_v4b_B.TmpSignalConversionAtSFunctionInport2_bj[3];
        ticksPerRad = gbyk_v4b_P.Constant_Value_d;

        /* MATLAB Function 'EtherCAT Subsystem/update/create kinematics': '<S195>:1' */
        /*  %primary enc 1ms velocity delay */
        /*  %primary enc 2ms acceleration delay */
        /*  %secondary encoder 0.5ms velocity delay */
        /* '<S195>:1:5' */
        /* secondary encoder 1ms acceleration delay */
        if (gbyk_v4b_B.TmpSignalConversionAtSFunctionInport8[0] +
            gbyk_v4b_B.TmpSignalConversionAtSFunctionInport8[1] == 0.0) {
          /* '<S195>:1:10' */
          /* '<S195>:1:11' */
          for (i = 0; i < 20; i++) {
            gbyk_v4b_B.kinematicsOut[i] = 0.0;
          }

          /* '<S195>:1:12' */
          for (i = 0; i < 12; i++) {
            gbyk_v4b_B.kinematicsOutPrimary[i] = 0.0;
          }
        } else {
          /* These min calls are required to avoid compile errors. */
          /* '<S195>:1:17' */
          queueSizePrimary = 0.002 / gbyk_v4b_P.Constant_Value_d + 1.0;
          if (!(queueSizePrimary <= 100.0)) {
            queueSizePrimary = 100.0;
          }

          /* '<S195>:1:18' */
          queueSizeSecondary = 0.001 / gbyk_v4b_P.Constant_Value_d + 1.0;
          if (!(queueSizeSecondary <= 100.0)) {
            queueSizeSecondary = 100.0;
          }

          /* '<S195>:1:19' */
          gbyk_v4b_convertL1L2ToShoElb
            (gbyk_v4b_B.TmpSignalConversionAtSFunctionInport1_p,
             gbyk_v4b_B.TmpSignalConversionAtSFunctionInport6, secondaryShoElb);

          /* '<S195>:1:20' */
          gbyk_v4b_convertL1L2ToShoElbVel
            (gbyk_v4b_B.TmpSignalConversionAtSFunctionInport3_g,
             gbyk_v4b_B.TmpSignalConversionAtSFunctionInport6, primaryShoElbVel);
          if (!gbyk_v4b_DW.secondaryPosData_not_empty) {
            /* '<S195>:1:22' */
            /* '<S195>:1:23' */
            gbyk_v4b_buildEncoderData(queueSizeSecondary, secondaryShoElb,
              tmp_data, tmp_sizes);
            gbyk_v4b_DW.secondaryPosData_sizes[0] = tmp_sizes[0];
            gbyk_v4b_DW.secondaryPosData_sizes[1] = tmp_sizes[1];
            ii_sizes_idx_1 = tmp_sizes[0] * tmp_sizes[1];
            for (i = 0; i < ii_sizes_idx_1; i++) {
              gbyk_v4b_DW.secondaryPosData_data[i] = tmp_data[i];
            }

            gbyk_v4b_DW.secondaryPosData_not_empty =
              !(gbyk_v4b_DW.secondaryPosData_sizes[1] == 0);

            /* '<S195>:1:24' */
            gbyk_v4b_buildEncoderData_j(queueSizeSecondary, tmp_data, tmp_sizes);
            gbyk_v4b_DW.secondaryVelData_sizes[0] = tmp_sizes[0];
            gbyk_v4b_DW.secondaryVelData_sizes[1] = tmp_sizes[1];
            ii_sizes_idx_1 = tmp_sizes[0] * tmp_sizes[1];
            for (i = 0; i < ii_sizes_idx_1; i++) {
              gbyk_v4b_DW.secondaryVelData_data[i] = tmp_data[i];
            }

            /* '<S195>:1:25' */
            gbyk_v4b_buildEncoderData(queueSizePrimary, primaryShoElbVel,
              tmp_data, tmp_sizes);
            gbyk_v4b_DW.primaryVelData_sizes[0] = tmp_sizes[0];
            gbyk_v4b_DW.primaryVelData_sizes[1] = tmp_sizes[1];
            ii_sizes_idx_1 = tmp_sizes[0] * tmp_sizes[1];
            for (i = 0; i < ii_sizes_idx_1; i++) {
              gbyk_v4b_DW.primaryVelData_data[i] = tmp_data[i];
            }

            /* '<S195>:1:26' */
            gbyk_v4b_buildEncoderData(queueSizePrimary, primaryShoElbVel,
              tmp_data, tmp_sizes);
            gbyk_v4b_DW.primaryVelDataFiltered_sizes[0] = tmp_sizes[0];
            gbyk_v4b_DW.primaryVelDataFiltered_sizes[1] = tmp_sizes[1];
            ii_sizes_idx_1 = tmp_sizes[0] * tmp_sizes[1];
            for (i = 0; i < ii_sizes_idx_1; i++) {
              gbyk_v4b_DW.primaryVelDataFiltered_data[i] = tmp_data[i];
            }
          } else {
            /* '<S195>:1:28' */
            gbyk_v4b_updateQueue(gbyk_v4b_DW.secondaryPosData_data,
                                 gbyk_v4b_DW.secondaryPosData_sizes,
                                 secondaryShoElb, tmp_data, tmp_sizes);
            gbyk_v4b_DW.secondaryPosData_sizes[0] = tmp_sizes[0];
            gbyk_v4b_DW.secondaryPosData_sizes[1] = tmp_sizes[1];
            ii_sizes_idx_1 = tmp_sizes[0] * tmp_sizes[1];
            for (i = 0; i < ii_sizes_idx_1; i++) {
              gbyk_v4b_DW.secondaryPosData_data[i] = tmp_data[i];
            }

            gbyk_v4b_DW.secondaryPosData_not_empty =
              !(gbyk_v4b_DW.secondaryPosData_sizes[1] == 0);

            /* '<S195>:1:29' */
            gbyk_v4b_calcDT(gbyk_v4b_DW.secondaryPosData_data,
                            gbyk_v4b_DW.secondaryPosData_sizes, ticksPerRad,
                            secondaryShoElb);
            gbyk_v4b_updateQueue(gbyk_v4b_DW.secondaryVelData_data,
                                 gbyk_v4b_DW.secondaryVelData_sizes,
                                 secondaryShoElb, tmp_data, tmp_sizes);
            gbyk_v4b_DW.secondaryVelData_sizes[0] = tmp_sizes[0];
            gbyk_v4b_DW.secondaryVelData_sizes[1] = tmp_sizes[1];
            ii_sizes_idx_1 = tmp_sizes[0] * tmp_sizes[1];
            for (i = 0; i < ii_sizes_idx_1; i++) {
              gbyk_v4b_DW.secondaryVelData_data[i] = tmp_data[i];
            }

            /* '<S195>:1:30' */
            gbyk_v4b_updateQueue(gbyk_v4b_DW.primaryVelData_data,
                                 gbyk_v4b_DW.primaryVelData_sizes,
                                 primaryShoElbVel, tmp_data, tmp_sizes);
            gbyk_v4b_DW.primaryVelData_sizes[0] = tmp_sizes[0];
            gbyk_v4b_DW.primaryVelData_sizes[1] = tmp_sizes[1];
            ii_sizes_idx_1 = tmp_sizes[0] * tmp_sizes[1];
            for (i = 0; i < ii_sizes_idx_1; i++) {
              gbyk_v4b_DW.primaryVelData_data[i] = tmp_data[i];
            }
          }

          /* '<S195>:1:33' */
          ii_sizes_idx_1 = gbyk_v4b_DW.secondaryVelData_sizes[1];
          tmp_sizes_3[0] = 2;
          tmp_sizes_3[1] = ii_sizes_idx_1;
          for (i = 0; i < ii_sizes_idx_1; i++) {
            tmp_data_0[i << 1] =
              gbyk_v4b_DW.secondaryVelData_data[gbyk_v4b_DW.secondaryVelData_sizes
              [0] * i];
            tmp_data_0[1 + (i << 1)] =
              gbyk_v4b_DW.secondaryVelData_data[gbyk_v4b_DW.secondaryVelData_sizes
              [0] * i + 1];
          }

          gbyk_v4b_buildKin(*(real_T (*)[2])&gbyk_v4b_DW.secondaryPosData_data[0],
                            tmp_data_0, tmp_sizes_3, ticksPerRad, *(uint32_T (*)
            [2])&gbyk_v4b_B.TmpSignalConversionAtSFunctionInport5[0],
                            r1SecondaryKinematicsOut);

          /* '<S195>:1:34' */
          ii_sizes_idx_1 = gbyk_v4b_DW.secondaryVelData_sizes[1];
          tmp_sizes_2[0] = 2;
          tmp_sizes_2[1] = ii_sizes_idx_1;
          for (i = 0; i < ii_sizes_idx_1; i++) {
            tmp_data_0[i << 1] =
              gbyk_v4b_DW.secondaryVelData_data[gbyk_v4b_DW.secondaryVelData_sizes
              [0] * i + 2];
            tmp_data_0[1 + (i << 1)] =
              gbyk_v4b_DW.secondaryVelData_data[gbyk_v4b_DW.secondaryVelData_sizes
              [0] * i + 3];
          }

          gbyk_v4b_buildKin(*(real_T (*)[2])&gbyk_v4b_DW.secondaryPosData_data[2],
                            tmp_data_0, tmp_sizes_2, ticksPerRad, *(uint32_T (*)
            [2])&gbyk_v4b_B.TmpSignalConversionAtSFunctionInport5[2],
                            r2SecondaryKinematicsOut);

          /* '<S195>:1:36' */
          anglesPrimary_0[0] = anglesPrimary[0];
          anglesPrimary_0[1] = anglesPrimary[1];
          anglesPrimary_0[2] = anglesPrimary[2];
          anglesPrimary_0[3] = anglesPrimary[3];
          gbyk_v4b_convertL1L2ToShoElb(anglesPrimary_0,
            gbyk_v4b_B.TmpSignalConversionAtSFunctionInport6, anglesPrimary);
          ii_sizes_idx_1 = gbyk_v4b_DW.primaryVelDataFiltered_sizes[1];
          b_sizes[0] = 2;
          b_sizes[1] = ii_sizes_idx_1;
          for (i = 0; i < ii_sizes_idx_1; i++) {
            b_data[i << 1] =
              gbyk_v4b_DW.primaryVelDataFiltered_data[gbyk_v4b_DW.primaryVelDataFiltered_sizes
              [0] * i];
            b_data[1 + (i << 1)] =
              gbyk_v4b_DW.primaryVelDataFiltered_data[gbyk_v4b_DW.primaryVelDataFiltered_sizes
              [0] * i + 1];
          }

          ii_sizes_idx_1 = gbyk_v4b_DW.primaryVelData_sizes[1];
          tmp_sizes_1[0] = 2;
          tmp_sizes_1[1] = ii_sizes_idx_1;
          for (i = 0; i < ii_sizes_idx_1; i++) {
            tmp_data_0[i << 1] =
              gbyk_v4b_DW.primaryVelData_data[gbyk_v4b_DW.primaryVelData_sizes[0]
              * i];
            tmp_data_0[1 + (i << 1)] =
              gbyk_v4b_DW.primaryVelData_data[gbyk_v4b_DW.primaryVelData_sizes[0]
              * i + 1];
          }

          gbyk_v4b_buildKinPrimary(*(real_T (*)[2])&anglesPrimary[0], tmp_data_0,
            tmp_sizes_1, ticksPerRad, *(uint32_T (*)[2])&
            gbyk_v4b_B.TmpSignalConversionAtSFunctionInport5[0], b_data, b_sizes,
            r1PrimaryKinematicsOut);

          /* '<S195>:1:37' */
          ii_sizes_idx_1 = b_sizes[1];
          for (i = 0; i < ii_sizes_idx_1; i++) {
            b_ii = gbyk_v4b_DW.primaryVelDataFiltered_sizes[0];
            gbyk_v4b_DW.primaryVelDataFiltered_data[b_ii * i] = b_data[b_sizes[0]
              * i];
            b_ii = gbyk_v4b_DW.primaryVelDataFiltered_sizes[0];
            gbyk_v4b_DW.primaryVelDataFiltered_data[1 + b_ii * i] =
              b_data[b_sizes[0] * i + 1];
          }

          ii_sizes_idx_1 = gbyk_v4b_DW.primaryVelDataFiltered_sizes[1];
          b_sizes[0] = 2;
          b_sizes[1] = ii_sizes_idx_1;
          for (i = 0; i < ii_sizes_idx_1; i++) {
            b_data[i << 1] =
              gbyk_v4b_DW.primaryVelDataFiltered_data[gbyk_v4b_DW.primaryVelDataFiltered_sizes
              [0] * i + 2];
            b_data[1 + (i << 1)] =
              gbyk_v4b_DW.primaryVelDataFiltered_data[gbyk_v4b_DW.primaryVelDataFiltered_sizes
              [0] * i + 3];
          }

          ii_sizes_idx_1 = gbyk_v4b_DW.primaryVelData_sizes[1];
          tmp_sizes_0[0] = 2;
          tmp_sizes_0[1] = ii_sizes_idx_1;
          for (i = 0; i < ii_sizes_idx_1; i++) {
            tmp_data_0[i << 1] =
              gbyk_v4b_DW.primaryVelData_data[gbyk_v4b_DW.primaryVelData_sizes[0]
              * i + 2];
            tmp_data_0[1 + (i << 1)] =
              gbyk_v4b_DW.primaryVelData_data[gbyk_v4b_DW.primaryVelData_sizes[0]
              * i + 3];
          }

          gbyk_v4b_buildKinPrimary(*(real_T (*)[2])&anglesPrimary[2], tmp_data_0,
            tmp_sizes_0, ticksPerRad, *(uint32_T (*)[2])&
            gbyk_v4b_B.TmpSignalConversionAtSFunctionInport5[2], b_data, b_sizes,
            r2PrimaryKinematicsOut);

          /* '<S195>:1:38' */
          ii_sizes_idx_1 = b_sizes[1];
          for (i = 0; i < ii_sizes_idx_1; i++) {
            b_ii = gbyk_v4b_DW.primaryVelDataFiltered_sizes[0];
            gbyk_v4b_DW.primaryVelDataFiltered_data[b_ii * i + 2] =
              b_data[b_sizes[0] * i];
            b_ii = gbyk_v4b_DW.primaryVelDataFiltered_sizes[0];
            gbyk_v4b_DW.primaryVelDataFiltered_data[b_ii * i + 3] =
              b_data[b_sizes[0] * i + 1];
          }

          if (gbyk_v4b_B.TmpSignalConversionAtSFunctionInport4_b[0] != 1.0) {
            /* '<S195>:1:40' */
            /* '<S195>:1:41' */
            memcpy(&r1SecondaryKinematicsOut[0], &r1PrimaryKinematicsOut[0], 10U
                   * sizeof(real_T));
          }

          if (gbyk_v4b_B.TmpSignalConversionAtSFunctionInport4_b[1] != 1.0) {
            /* '<S195>:1:43' */
            /* '<S195>:1:44' */
            memcpy(&r2SecondaryKinematicsOut[0], &r2PrimaryKinematicsOut[0], 10U
                   * sizeof(real_T));
          }

          /* '<S195>:1:47' */
          memcpy(&gbyk_v4b_B.kinematicsOut[0], &r1SecondaryKinematicsOut[0], 10U
                 * sizeof(real_T));
          memcpy(&gbyk_v4b_B.kinematicsOut[10], &r2SecondaryKinematicsOut[0],
                 10U * sizeof(real_T));

          /* '<S195>:1:48' */
          for (i = 0; i < 6; i++) {
            gbyk_v4b_B.kinematicsOutPrimary[i] = r1PrimaryKinematicsOut[i];
          }

          for (i = 0; i < 6; i++) {
            gbyk_v4b_B.kinematicsOutPrimary[i + 6] = r2PrimaryKinematicsOut[i];
          }
        }

        /* SignalConversion: '<S200>/TmpSignal ConversionAt SFunction Inport1' incorporates:
         *  MATLAB Function: '<S194>/filter_velocities'
         */
        gbyk_v4b_B.TmpSignalConversionAtSFunctionInport1_l[0] =
          gbyk_v4b_B.kinematicsOut[2];
        gbyk_v4b_B.TmpSignalConversionAtSFunctionInport1_l[1] =
          gbyk_v4b_B.kinematicsOut[3];
        gbyk_v4b_B.TmpSignalConversionAtSFunctionInport1_l[2] =
          gbyk_v4b_B.kinematicsOut[12];
        gbyk_v4b_B.TmpSignalConversionAtSFunctionInport1_l[3] =
          gbyk_v4b_B.kinematicsOut[13];

        /* MATLAB Function: '<S194>/filter_velocities' incorporates:
         *  Constant: '<S194>/2nd order butterworth, 4Khz, 10hz cutoff'
         */
        /* MATLAB Function 'EtherCAT Subsystem/update/create filtered velocities/filter_velocities': '<S200>:1' */
        /* given any number of input values this will filter those values based */
        /* on a 2nd order Butterworth filter. You will need to get the constants */
        /* from http://www-users.cs.york.ac.uk/~fisher/mkfilter/trad.html */
        /* '<S200>:1:14' */
        gbyk_v4b_B.filteredVels[0] = 0.0;
        gbyk_v4b_B.filteredVels[1] = 0.0;
        gbyk_v4b_B.filteredVels[2] = 0.0;
        gbyk_v4b_B.filteredVels[3] = 0.0;

        /* this code is roughly derrived from the example code given when you */
        /* generate filter constants at: http://www-users.cs.york.ac.uk/~fisher/mkfilter/trad.html */
        /* '<S200>:1:18' */
        for (i = 0; i < 4; i++) {
          /* '<S200>:1:18' */
          /* '<S200>:1:19' */
          /* '<S200>:1:20' */
          b[0] = gbyk_v4b_DW.rawVelocities[i];
          b[1] = gbyk_v4b_DW.rawVelocities[i + 4];
          b[2] = gbyk_v4b_DW.rawVelocities[i + 8];
          gbyk_v4b_insertVal(b,
                             gbyk_v4b_B.TmpSignalConversionAtSFunctionInport1_l[i]
                             /
                             gbyk_v4b_P.ndorderbutterworth4Khz10hzcutoff_Value[0]);
          gbyk_v4b_DW.rawVelocities[i] = b[0];
          gbyk_v4b_DW.rawVelocities[i + 4] = b[1];
          gbyk_v4b_DW.rawVelocities[i + 8] = b[2];

          /* '<S200>:1:21' */
          b[0] = gbyk_v4b_DW.filtVelocities[i];
          b[1] = gbyk_v4b_DW.filtVelocities[i + 4];
          b[2] = gbyk_v4b_DW.filtVelocities[i + 8];
          gbyk_v4b_insertVal(b, 0.0);
          gbyk_v4b_DW.filtVelocities[i] = b[0];
          gbyk_v4b_DW.filtVelocities[i + 4] = b[1];
          gbyk_v4b_DW.filtVelocities[i + 8] = b[2];

          /* '<S200>:1:22' */
          /* all filter constants from http://www-users.cs.york.ac.uk/~fisher/mkfilter/trad.html */
          /* '<S200>:1:29' */
          ticksPerRad = (((gbyk_v4b_DW.rawVelocities[4 + i] * 2.0 +
                           gbyk_v4b_DW.rawVelocities[i]) +
                          gbyk_v4b_DW.rawVelocities[8 + i]) +
                         gbyk_v4b_DW.filtVelocities[i] *
                         gbyk_v4b_P.ndorderbutterworth4Khz10hzcutoff_Value[1]) +
            gbyk_v4b_DW.filtVelocities[4 + i] *
            gbyk_v4b_P.ndorderbutterworth4Khz10hzcutoff_Value[2];
          if (rtIsNaN(ticksPerRad) || rtIsInf(ticksPerRad)) {
            /* '<S200>:1:35' */
            ticksPerRad = 0.0;
          }

          gbyk_v4b_DW.filtVelocities[8 + i] = ticksPerRad;

          /* '<S200>:1:23' */
          gbyk_v4b_B.filteredVels[i] = gbyk_v4b_DW.filtVelocities[8 + i];

          /* '<S200>:1:18' */
        }

        /* MATLAB Function: '<S194>/rebuild' */
        /* MATLAB Function 'EtherCAT Subsystem/update/create filtered velocities/rebuild': '<S201>:1' */
        /* '<S201>:1:2' */
        memcpy(&gbyk_v4b_B.outVals[0], &gbyk_v4b_B.kinematicsOut[0], 20U *
               sizeof(real_T));

        /* '<S201>:1:3' */
        gbyk_v4b_B.outVals[6] = gbyk_v4b_B.filteredVels[0];
        gbyk_v4b_B.outVals[7] = gbyk_v4b_B.filteredVels[1];

        /* '<S201>:1:4' */
        gbyk_v4b_B.outVals[16] = gbyk_v4b_B.filteredVels[2];
        gbyk_v4b_B.outVals[17] = gbyk_v4b_B.filteredVels[3];

        /* DataStoreWrite: '<S84>/kin write' */
        memcpy(&gbyk_v4b_DW.Kinematics[0], &gbyk_v4b_B.outVals[0], 20U * sizeof
               (real_T));

        /* DataStoreWrite: '<S84>/primary write' */
        memcpy(&gbyk_v4b_DW.PrimaryEncoderData[0],
               &gbyk_v4b_B.kinematicsOutPrimary[0], 12U * sizeof(real_T));

        /* DataStoreWrite: '<S84>/write delays' */
        gbyk_v4b_DW.DelayEstimates[0] = gbyk_v4b_B.delays[0];
        gbyk_v4b_DW.DelayEstimates[1] = gbyk_v4b_B.delays[1];
        gbyk_v4b_DW.DelayEstimates[2] = gbyk_v4b_B.delays[2];
        gbyk_v4b_DW.DelayEstimates[3] = gbyk_v4b_B.delays[3];

        /* MATLAB Function: '<S84>/robottype1' */
        /* MATLAB Function 'EtherCAT Subsystem/update/robottype1': '<S197>:1' */
        /* '<S197>:1:3' */
        for (i = 0; i < 5; i++) {
          gbyk_v4b_B.outMem[i << 2] = gbyk_v4b_B.R1M1_EMCY_codes[i];
        }

        for (i = 0; i < 5; i++) {
          gbyk_v4b_B.outMem[1 + (i << 2)] = gbyk_v4b_B.R1M2_EMCY_codes[i];
        }

        for (i = 0; i < 5; i++) {
          gbyk_v4b_B.outMem[2 + (i << 2)] = gbyk_v4b_B.R2M1_EMCY_codes[i];
        }

        for (i = 0; i < 5; i++) {
          gbyk_v4b_B.outMem[3 + (i << 2)] = gbyk_v4b_B.R2M2_EMCY_codes[i];
        }

        /* End of MATLAB Function: '<S84>/robottype1' */

        /* DataStoreWrite: '<S84>/write errs' */
        memcpy(&gbyk_v4b_DW.ECATErrMsgs[0], &gbyk_v4b_B.outMem[0], 20U * sizeof
               (real_T));

        /* DataTypeConversion: '<S84>/Data Type Conversion3' */
        gbyk_v4b_B.DataTypeConversion3_l[0] =
          gbyk_v4b_B.R1M1_CurrentLimitEnabled;
        gbyk_v4b_B.DataTypeConversion3_l[1] =
          gbyk_v4b_B.R1M2_CurrentLimitEnabled;
        gbyk_v4b_B.DataTypeConversion3_l[2] =
          gbyk_v4b_B.R2M1_CurrentLimitEnabled;
        gbyk_v4b_B.DataTypeConversion3_l[3] =
          gbyk_v4b_B.R2M2_CurrentLimitEnabled;

        /* DataStoreWrite: '<S84>/write torque' */
        gbyk_v4b_DW.ECATExtraData[0] = gbyk_v4b_B.R1M1_RecordedTorque;
        gbyk_v4b_DW.ECATExtraData[1] = gbyk_v4b_B.R1M2_RecordedTorque;
        gbyk_v4b_DW.ECATExtraData[2] = gbyk_v4b_B.R2M1_RecordedTorque;
        gbyk_v4b_DW.ECATExtraData[3] = gbyk_v4b_B.R2M2_RecordedTorque;
        gbyk_v4b_DW.ECATExtraData[4] = gbyk_v4b_B.DataTypeConversion3_l[0];
        gbyk_v4b_DW.ECATExtraData[5] = gbyk_v4b_B.DataTypeConversion3_l[1];
        gbyk_v4b_DW.ECATExtraData[6] = gbyk_v4b_B.DataTypeConversion3_l[2];
        gbyk_v4b_DW.ECATExtraData[7] = gbyk_v4b_B.DataTypeConversion3_l[3];

        /* MATLAB Function: '<S84>/create servo counter' */
        /* MATLAB Function 'EtherCAT Subsystem/update/create servo counter': '<S196>:1' */
        /*  % Not all slave devices are in operational state when receiving cyclic frames */
        /*  %Ethernet link (cable) not connected */
        /*  % Cyclic command: working counter error. his error occurs if the EtherCAT network is broken AFTER the first slave */
        if (!gbyk_v4b_DW.servoCounter_not_empty) {
          /* '<S196>:1:10' */
          /* '<S196>:1:11' */
          gbyk_v4b_DW.servoCounter = 0U;
          gbyk_v4b_DW.servoCounter_not_empty = true;
        } else {
          i = 0;
          if (65551.0 == gbyk_v4b_B.errVals[0]) {
            /* '<S196>:1:12' */
            i = 1;
          }

          if (65552.0 == gbyk_v4b_B.errVals[0]) {
            /* '<S196>:1:12' */
            i++;
          }

          if (65537.0 == gbyk_v4b_B.errVals[0]) {
            /* '<S196>:1:12' */
            i++;
          }

          if (!(i == 0)) {
            /* '<S196>:1:12' */
            /* if we find a fatal error just set the servo amp counter to */
            /* that error value so it's easier to report to the operator */
            /* '<S196>:1:15' */
            ticksPerRad = rt_roundd_snf(gbyk_v4b_B.errVals[0]);
            if (ticksPerRad < 4.294967296E+9) {
              if (ticksPerRad >= 0.0) {
                drive2 = (uint32_T)ticksPerRad;
              } else {
                drive2 = 0U;
              }
            } else {
              drive2 = MAX_uint32_T;
            }

            gbyk_v4b_DW.servoCounter = drive2;
          } else {
            /* '<S196>:1:17' */
            tmp_1 = gbyk_v4b_DW.servoCounter + 1ULL;
            if (tmp_1 > 4294967295ULL) {
              tmp_1 = 4294967295ULL;
            }

            gbyk_v4b_DW.servoCounter = (uint32_T)tmp_1;
          }
        }

        /* '<S196>:1:20' */
        gbyk_v4b_B.servoCounterOut = gbyk_v4b_DW.servoCounter;

        /* End of MATLAB Function: '<S84>/create servo counter' */

        /* DataStoreWrite: '<S84>/Servo Write' */
        gbyk_v4b_DW.ServoUpdate = gbyk_v4b_B.servoCounterOut;
        gbyk_v4b_DW.update_SubsysRanBC = 4;

        /* End of Outputs for SubSystem: '<S64>/update' */

        /* Outputs for Function Call SubSystem: '<S34>/createKINData' */

        /* Event: '<S69>:209' */
        gbyk_v4b_createKINData();

        /* End of Outputs for SubSystem: '<S34>/createKINData' */
        break;

       case gbyk_v4b_IN_RunPMAC:
        /* Outputs for Function Call SubSystem: '<S66>/update settings' */
        /* DataStoreWrite: '<S211>/Data Store Write1' */
        /* During 'RunPMAC': '<S69>:221' */
        /* Event: '<S69>:208' */
        memcpy(&gbyk_v4b_DW.Kinematics[0], &gbyk_v4b_B.robot1DataOut[0], 10U *
               sizeof(real_T));
        memcpy(&gbyk_v4b_DW.Kinematics[10], &gbyk_v4b_B.robot2DataOut[0], 10U *
               sizeof(real_T));

        /* DataStoreWrite: '<S211>/Data Store Write2' */
        gbyk_v4b_DW.ServoUpdate = gbyk_v4b_B.MinMax1;

        /* DataStoreWrite: '<S211>/Data Store Write3' */
        gbyk_v4b_DW.DelayEstimates[0] = gbyk_v4b_B.Conversion7[0];
        gbyk_v4b_DW.DelayEstimates[1] = gbyk_v4b_B.Conversion7[1];
        gbyk_v4b_DW.DelayEstimates[2] = gbyk_v4b_B.Conversion7[2];
        gbyk_v4b_DW.DelayEstimates[3] = gbyk_v4b_B.Conversion7[3];

        /* DataStoreWrite: '<S211>/Data Store Write4' */
        for (i = 0; i < 6; i++) {
          gbyk_v4b_DW.PrimaryEncoderData[i] =
            gbyk_v4b_B.robot1PrimaryEncDataOut[i];
        }

        for (i = 0; i < 6; i++) {
          gbyk_v4b_DW.PrimaryEncoderData[i + 6] =
            gbyk_v4b_B.robot2PrimaryEncDataOut[i];
        }

        /* End of DataStoreWrite: '<S211>/Data Store Write4' */

        /* DataStoreWrite: '<S211>/Data Store Write5' */
        gbyk_v4b_DW.CalibrationButton = gbyk_v4b_B.SFunction_o7;

        /* MATLAB Function: '<S211>/update status format' */
        /* MATLAB Function 'DataLogging/Poll KINARM/PMAC Subsystem/update settings/update status format': '<S222>:1' */
        /* '<S222>:1:4' */
        for (i = 0; i < 7; i++) {
          gbyk_v4b_B.outStatus[i] = 0U;
        }

        /* '<S222>:1:5' */
        gbyk_v4b_B.outStatus[4] = gbyk_v4b_B.Convert2_n[1];
        gbyk_v4b_B.outStatus[5] = gbyk_v4b_B.Convert2_n[2];

        /* '<S222>:1:7' */
        /* '<S222>:1:9' */
        /* Each motor has 2 possible states: 0 working, 1 faulted. The READY state is only used by EtherCAT */
        /* '<S222>:1:12' */
        /* '<S222>:1:13' */
        drive1 = gbyk_v4b_B.Convert2_n[0];
        if ((int32_T)(drive1 & 1U) == 1) {
          /* '<S222>:1:14' */
          /* '<S222>:1:15' */
          gbyk_v4b_B.outStatus[0] = 2U;
        } else {
          /* '<S222>:1:17' */
          gbyk_v4b_B.outStatus[0] = 0U;
        }

        /* '<S222>:1:12' */
        /* '<S222>:1:13' */
        drive1 = gbyk_v4b_B.Convert2_n[0] >> 1U;
        if ((int32_T)(drive1 & 1U) == 1) {
          /* '<S222>:1:14' */
          /* '<S222>:1:15' */
          gbyk_v4b_B.outStatus[1] = 2U;
        } else {
          /* '<S222>:1:17' */
          gbyk_v4b_B.outStatus[1] = 0U;
        }

        /* '<S222>:1:12' */
        /* '<S222>:1:13' */
        drive1 = gbyk_v4b_B.Convert2_n[0] >> 2U;
        if ((int32_T)(drive1 & 1U) == 1) {
          /* '<S222>:1:14' */
          /* '<S222>:1:15' */
          gbyk_v4b_B.outStatus[2] = 2U;
        } else {
          /* '<S222>:1:17' */
          gbyk_v4b_B.outStatus[2] = 0U;
        }

        /* '<S222>:1:12' */
        /* '<S222>:1:13' */
        drive1 = gbyk_v4b_B.Convert2_n[0] >> 3U;
        if ((int32_T)(drive1 & 1U) == 1) {
          /* '<S222>:1:14' */
          /* '<S222>:1:15' */
          gbyk_v4b_B.outStatus[3] = 2U;
        } else {
          /* '<S222>:1:17' */
          gbyk_v4b_B.outStatus[3] = 0U;
        }

        /* End of MATLAB Function: '<S211>/update status format' */

        /* DataStoreWrite: '<S211>/Data Store Write7' */
        /* '<S222>:1:12' */
        for (i = 0; i < 7; i++) {
          gbyk_v4b_DW.SystemStatus[i] = gbyk_v4b_B.outStatus[i];
        }

        /* End of DataStoreWrite: '<S211>/Data Store Write7' */
        gbyk_v4b_DW.updatesettings_SubsysRanBC = 4;

        /* End of Outputs for SubSystem: '<S66>/update settings' */

        /* Outputs for Function Call SubSystem: '<S34>/createKINData' */

        /* Event: '<S69>:209' */
        gbyk_v4b_createKINData();

        /* End of Outputs for SubSystem: '<S34>/createKINData' */
        break;

       default:
        /* Outputs for Function Call SubSystem: '<S67>/Data write' */
        /* DataStoreWrite: '<S224>/Data Store Write1' */
        /* During 'RunSim': '<S69>:217' */
        /* Event: '<S69>:206' */
        memcpy(&gbyk_v4b_DW.Kinematics[0], &gbyk_v4b_B.kinematics[0], 20U *
               sizeof(real_T));

        /* DataStoreWrite: '<S224>/Data Store Write4' */
        memcpy(&gbyk_v4b_DW.PrimaryEncoderData[0], &gbyk_v4b_B.primary[0], 12U *
               sizeof(real_T));

        /* DataStoreWrite: '<S224>/Data Store Write2' */
        gbyk_v4b_DW.ServoUpdate = gbyk_v4b_B.Output_e;

        /* DataStoreWrite: '<S224>/Data Store Write5' */
        gbyk_v4b_DW.CalibrationButton = gbyk_v4b_B.Constant;

        /* DataStoreWrite: '<S224>/Data Store Write7' */
        for (i = 0; i < 7; i++) {
          gbyk_v4b_DW.SystemStatus[i] = gbyk_v4b_B.Constant1[i];
        }

        /* End of DataStoreWrite: '<S224>/Data Store Write7' */

        /* DataStoreWrite: '<S224>/Data Store Write3' incorporates:
         *  Constant: '<S224>/Constant'
         */
        gbyk_v4b_DW.DelayEstimates[0] = gbyk_v4b_P.Constant_Value_l[0];
        gbyk_v4b_DW.DelayEstimates[1] = gbyk_v4b_P.Constant_Value_l[1];
        gbyk_v4b_DW.DelayEstimates[2] = gbyk_v4b_P.Constant_Value_l[2];
        gbyk_v4b_DW.DelayEstimates[3] = gbyk_v4b_P.Constant_Value_l[3];
        gbyk_v4b_DW.Datawrite_SubsysRanBC = 4;

        /* End of Outputs for SubSystem: '<S67>/Data write' */

        /* Outputs for Function Call SubSystem: '<S34>/createKINData' */

        /* Event: '<S69>:209' */
        gbyk_v4b_createKINData();

        /* End of Outputs for SubSystem: '<S34>/createKINData' */
        break;
      }
    }

    /* End of Chart: '<S34>/control read write' */

    /* Sum: '<S189>/FixPt Sum1' incorporates:
     *  Constant: '<S189>/FixPt Constant'
     */
    gbyk_v4b_B.FixPtSum1_e = gbyk_v4b_B.Output_a +
      gbyk_v4b_P.FixPtConstant_Value_m;

    /* Switch: '<S190>/FixPt Switch' incorporates:
     *  Constant: '<S190>/Constant'
     */
    if (gbyk_v4b_B.FixPtSum1_e > gbyk_v4b_P.WrapToZero_Threshold_e) {
      gbyk_v4b_B.FixPtSwitch_m = gbyk_v4b_P.Constant_Value_kn;
    } else {
      gbyk_v4b_B.FixPtSwitch_m = gbyk_v4b_B.FixPtSum1_e;
    }

    /* End of Switch: '<S190>/FixPt Switch' */

    /* Constant: '<S230>/Arm Shoulder Angle Offset' */
    gbyk_v4b_B.shoulderangleoffset = gbyk_v4b_P.ArmShoulderAngleOffset_Value;

    /* Constant: '<S230>/Arm Elbow Angle Offset' */
    gbyk_v4b_B.elbowangleoffset = gbyk_v4b_P.ArmElbowAngleOffset_Value;

    /* Constant: '<S230>/Arm Shoulder X' */
    gbyk_v4b_B.ShoulderX = gbyk_v4b_P.ArmShoulderX_Value;

    /* Constant: '<S230>/Arm Shoulder Y' */
    gbyk_v4b_B.ShoulderY = gbyk_v4b_P.ArmShoulderY_Value;

    /* Constant: '<S230>/Arm L1' */
    gbyk_v4b_B.L1 = gbyk_v4b_P.ArmL1_Value;

    /* Constant: '<S230>/Arm L2' */
    gbyk_v4b_B.L2 = gbyk_v4b_P.ArmL2_Value;

    /* Constant: '<S230>/Arm Pointer Offset' */
    gbyk_v4b_B.Pointeroffset = gbyk_v4b_P.ArmPointerOffset_Value;

    /* Constant: '<S230>/Arm L3 Error' */
    gbyk_v4b_B.L3Error = gbyk_v4b_P.ArmL3Error_Value;

    /* Constant: '<S230>/Arm robot type' */
    gbyk_v4b_B.robottype_e = gbyk_v4b_P.Armrobottype_Value;

    /* Constant: '<S230>/Arm Torque Constant' */
    gbyk_v4b_B.torqueconstant_g = gbyk_v4b_P.ArmTorqueConstant_Value;

    /* Constant: '<S230>/Arm robot version' */
    gbyk_v4b_B.robotversion_g = gbyk_v4b_P.Armrobotversion_Value;

    /* Constant: '<S231>/Arm Shoulder Angle Offset' */
    gbyk_v4b_B.shoulderangleoffset_b = gbyk_v4b_P.ArmShoulderAngleOffset_Value_l;

    /* Constant: '<S231>/Arm Elbow Angle Offset' */
    gbyk_v4b_B.elbowangleoffset_a = gbyk_v4b_P.ArmElbowAngleOffset_Value_n;

    /* Constant: '<S231>/Arm Shoulder X' */
    gbyk_v4b_B.ShoulderX_a = gbyk_v4b_P.ArmShoulderX_Value_j;

    /* Constant: '<S231>/Arm Shoulder Y' */
    gbyk_v4b_B.ShoulderY_b = gbyk_v4b_P.ArmShoulderY_Value_p;

    /* Constant: '<S231>/Arm L1' */
    gbyk_v4b_B.L1_c = gbyk_v4b_P.ArmL1_Value_c;

    /* Constant: '<S231>/Arm L2' */
    gbyk_v4b_B.L2_f = gbyk_v4b_P.ArmL2_Value_i;

    /* Constant: '<S231>/Arm Pointer Offset' */
    gbyk_v4b_B.Pointeroffset_b = gbyk_v4b_P.ArmPointerOffset_Value_b;

    /* Constant: '<S231>/Arm L3 Error' */
    gbyk_v4b_B.L3Error_f = gbyk_v4b_P.ArmL3Error_Value_l;

    /* Constant: '<S231>/Arm robot type' */
    gbyk_v4b_B.robottype_cs = gbyk_v4b_P.Armrobottype_Value_m;

    /* Constant: '<S231>/Arm Torque Constant' */
    gbyk_v4b_B.torqueconstant_i = gbyk_v4b_P.ArmTorqueConstant_Value_a;

    /* Constant: '<S231>/Arm robot version' */
    gbyk_v4b_B.robotversion_f = gbyk_v4b_P.Armrobotversion_Value_b;

    /* Outputs for Enabled SubSystem: '<S68>/update constants subsystem' incorporates:
     *  EnablePort: '<S232>/Enable'
     */
    /* Constant: '<S68>/update constants' */
    if (gbyk_v4b_P.updateconstants_Value > 0.0) {
      /* DataStoreWrite: '<S232>/Data Store Write' */
      gbyk_v4b_DW.RobotCalibrations[0] = gbyk_v4b_B.shoulderangleoffset;
      gbyk_v4b_DW.RobotCalibrations[1] = gbyk_v4b_B.elbowangleoffset;
      gbyk_v4b_DW.RobotCalibrations[2] = gbyk_v4b_B.ShoulderX;
      gbyk_v4b_DW.RobotCalibrations[3] = gbyk_v4b_B.ShoulderY;
      gbyk_v4b_DW.RobotCalibrations[4] = gbyk_v4b_B.L1;
      gbyk_v4b_DW.RobotCalibrations[5] = gbyk_v4b_B.L2;
      gbyk_v4b_DW.RobotCalibrations[6] = gbyk_v4b_B.Pointeroffset;
      gbyk_v4b_DW.RobotCalibrations[7] = gbyk_v4b_B.L3Error;
      gbyk_v4b_DW.RobotCalibrations[8] = gbyk_v4b_B.shoulderangleoffset_b;
      gbyk_v4b_DW.RobotCalibrations[9] = gbyk_v4b_B.elbowangleoffset_a;
      gbyk_v4b_DW.RobotCalibrations[10] = gbyk_v4b_B.ShoulderX_a;
      gbyk_v4b_DW.RobotCalibrations[11] = gbyk_v4b_B.ShoulderY_b;
      gbyk_v4b_DW.RobotCalibrations[12] = gbyk_v4b_B.L1_c;
      gbyk_v4b_DW.RobotCalibrations[13] = gbyk_v4b_B.L2_f;
      gbyk_v4b_DW.RobotCalibrations[14] = gbyk_v4b_B.Pointeroffset_b;
      gbyk_v4b_DW.RobotCalibrations[15] = gbyk_v4b_B.L3Error_f;

      /* DataStoreWrite: '<S232>/Data Store Write1' incorporates:
       *  Constant: '<S230>/Arm Force Sensor Angle Offset'
       *  Constant: '<S230>/Arm L2 L5 Angle'
       *  Constant: '<S230>/Arm L5'
       *  Constant: '<S231>/Arm Force Sensor Angle Offset'
       *  Constant: '<S231>/Arm L2 L5 Angle'
       *  Constant: '<S231>/Arm L5'
       */
      gbyk_v4b_DW.HardwareSettings[0] = gbyk_v4b_B.robottype_e;
      gbyk_v4b_DW.HardwareSettings[1] = gbyk_v4b_B.torqueconstant_g;
      gbyk_v4b_DW.HardwareSettings[2] = gbyk_v4b_P.ArmL5_Value;
      gbyk_v4b_DW.HardwareSettings[3] = gbyk_v4b_P.ArmL2L5Angle_Value;
      gbyk_v4b_DW.HardwareSettings[4] =
        gbyk_v4b_P.ArmForceSensorAngleOffset_Value;
      gbyk_v4b_DW.HardwareSettings[5] = gbyk_v4b_B.ArmOrientation_b;
      gbyk_v4b_DW.HardwareSettings[6] = gbyk_v4b_B.M1orientation_h;
      gbyk_v4b_DW.HardwareSettings[7] = gbyk_v4b_B.M2Orientation_l;
      gbyk_v4b_DW.HardwareSettings[8] = gbyk_v4b_B.M1GearRatio_b;
      gbyk_v4b_DW.HardwareSettings[9] = gbyk_v4b_B.M2GearRatio_p;
      gbyk_v4b_DW.HardwareSettings[10] = gbyk_v4b_B.HasSecondaryEnc_n;
      gbyk_v4b_DW.HardwareSettings[11] = gbyk_v4b_B.robotversion_g;
      gbyk_v4b_DW.HardwareSettings[12] = gbyk_v4b_B.robottype_cs;
      gbyk_v4b_DW.HardwareSettings[13] = gbyk_v4b_B.torqueconstant_i;
      gbyk_v4b_DW.HardwareSettings[14] = gbyk_v4b_P.ArmL5_Value_m;
      gbyk_v4b_DW.HardwareSettings[15] = gbyk_v4b_P.ArmL2L5Angle_Value_g;
      gbyk_v4b_DW.HardwareSettings[16] =
        gbyk_v4b_P.ArmForceSensorAngleOffset_Value_c;
      gbyk_v4b_DW.HardwareSettings[17] = gbyk_v4b_B.ArmOrientation_l;
      gbyk_v4b_DW.HardwareSettings[18] = gbyk_v4b_B.M1orientation_n;
      gbyk_v4b_DW.HardwareSettings[19] = gbyk_v4b_B.M2Orientation_cw;
      gbyk_v4b_DW.HardwareSettings[20] = gbyk_v4b_B.M1GearRatio_k;
      gbyk_v4b_DW.HardwareSettings[21] = gbyk_v4b_B.M2GearRatio_l;
      gbyk_v4b_DW.HardwareSettings[22] = gbyk_v4b_B.HasSecondaryEnc_f;
      gbyk_v4b_DW.HardwareSettings[23] = gbyk_v4b_B.robotversion_f;

      /* DataStoreWrite: '<S232>/Data Store Write8' incorporates:
       *  Constant: '<S232>/Arm Force Sensors'
       */
      gbyk_v4b_DW.ArmForceSensors[0] = gbyk_v4b_P.ArmForceSensors_Value[0];
      gbyk_v4b_DW.ArmForceSensors[1] = gbyk_v4b_P.ArmForceSensors_Value[1];
      srUpdateBC(gbyk_v4b_DW.updateconstantssubsystem_SubsysRanBC);
    }

    /* End of Constant: '<S68>/update constants' */
    /* End of Outputs for SubSystem: '<S68>/update constants subsystem' */

    /* DataStoreRead: '<S230>/Status read1' */
    gbyk_v4b_B.Statusread1[0] = gbyk_v4b_DW.RobotRevision[0];
    gbyk_v4b_B.Statusread1[1] = gbyk_v4b_DW.RobotRevision[1];

    /* MATLAB Function: '<S230>/decode robot' */
    gbyk_v4b_decoderobot(gbyk_v4b_B.systemtype, gbyk_v4b_B.robottype_e,
                         gbyk_v4b_B.robotversion_g, &gbyk_v4b_B.sf_decoderobot);

    /* DataStoreRead: '<S231>/Status read1' */
    gbyk_v4b_B.Statusread1_m[0] = gbyk_v4b_DW.RobotRevision[0];
    gbyk_v4b_B.Statusread1_m[1] = gbyk_v4b_DW.RobotRevision[1];

    /* MATLAB Function: '<S231>/decode robot' */
    gbyk_v4b_decoderobot(gbyk_v4b_B.systemtype, gbyk_v4b_B.robottype_cs,
                         gbyk_v4b_B.robotversion_f, &gbyk_v4b_B.sf_decoderobot_p);
    for (i = 0; i < 50; i++) {
      /* Selector: '<S73>/Selector' */
      gbyk_v4b_B.Selector_c[i] = gbyk_v4b_B.kinarm_data[3 * i];

      /* Selector: '<S73>/Selector1' */
      gbyk_v4b_B.Selector1_m[i] = gbyk_v4b_B.kinarm_data[3 * i + 1];

      /* Selector: '<S73>/Selector2' */
      gbyk_v4b_B.Selector2_o[i] = gbyk_v4b_B.kinarm_data[3 * i + 2];
    }

    /* MATLAB Function: '<S73>/splitKINData arm1' */
    /* MATLAB Function 'DataLogging/Poll KINARM/make KINData bus/splitKINData arm1': '<S242>:1' */
    /* '<S242>:1:9' */
    gbyk_v4b_B.link_lengths_o[0] = gbyk_v4b_B.Selector_c[0];
    gbyk_v4b_B.link_lengths_o[1] = gbyk_v4b_B.Selector_c[1];

    /*  L1, L2 length in m */
    /* '<S242>:1:10' */
    gbyk_v4b_B.pointer_offset_k = gbyk_v4b_B.Selector_c[2];

    /*  perpendicular distance from L2 to subject pointer (m) */
    /* '<S242>:1:11' */
    gbyk_v4b_B.shoulder_loc_o[0] = gbyk_v4b_B.Selector_c[3];
    gbyk_v4b_B.shoulder_loc_o[1] = gbyk_v4b_B.Selector_c[4];

    /*  shoulder x,y position (m) (global coordinates) */
    /* '<S242>:1:12' */
    gbyk_v4b_B.arm_orientation_o = gbyk_v4b_B.Selector_c[5];

    /*  subject's expected arm orientation (1: right, 2: left) */
    /* '<S242>:1:13' */
    gbyk_v4b_B.shoulder_ang_h = gbyk_v4b_B.Selector_c[6];

    /*  shoulder joint angle, with correction for offsets (see above) (rad) */
    /* '<S242>:1:14' */
    gbyk_v4b_B.elbow_ang_k = gbyk_v4b_B.Selector_c[7];

    /*  elbow joint angle, with correction for offsets (see above) (rad) */
    /* '<S242>:1:15' */
    gbyk_v4b_B.shoulder_velocity_k = gbyk_v4b_B.Selector_c[8];

    /*  shoulder joint angular velocity (rad/s) */
    /* '<S242>:1:16' */
    gbyk_v4b_B.elbow_velocity_j = gbyk_v4b_B.Selector_c[9];

    /*  elbow joint angular velocity (rad/s) */
    /* '<S242>:1:17' */
    gbyk_v4b_B.shoulder_acceleration_c = gbyk_v4b_B.Selector_c[10];

    /*  shoulder joint angular acceleration (rad/s^2) */
    /* '<S242>:1:18' */
    gbyk_v4b_B.elbow_acceleration_j = gbyk_v4b_B.Selector_c[11];

    /*  elbow joint angular acceleration (rad/s^2) */
    /* '<S242>:1:19' */
    gbyk_v4b_B.joint_torque_cmd_k[0] = gbyk_v4b_B.Selector_c[12];
    gbyk_v4b_B.joint_torque_cmd_k[1] = gbyk_v4b_B.Selector_c[13];

    /*  commanded shoulder (1), and elbow (2) torque (Nm) */
    /* '<S242>:1:20' */
    gbyk_v4b_B.motor_torque_cmd_b[0] = gbyk_v4b_B.Selector_c[14];
    gbyk_v4b_B.motor_torque_cmd_b[1] = gbyk_v4b_B.Selector_c[15];

    /*  commanded motor 1 (1) and 2 (2) torque (shoulder torque less elbow torque) (Nm) */
    /* '<S242>:1:22' */
    gbyk_v4b_B.link_angle_b[0] = gbyk_v4b_B.Selector_c[16];
    gbyk_v4b_B.link_angle_b[1] = gbyk_v4b_B.Selector_c[17];

    /*  upper arm angle with corrections, orientation-independent (see above) (rad) */
    /* '<S242>:1:23' */
    gbyk_v4b_B.link_velocity_k[0] = gbyk_v4b_B.Selector_c[18];
    gbyk_v4b_B.link_velocity_k[1] = gbyk_v4b_B.Selector_c[19];

    /*  upper arm angular velocity, orientation-independent (see above) (rad/s) */
    /* '<S242>:1:24' */
    gbyk_v4b_B.link_acceleration_c[0] = gbyk_v4b_B.Selector_c[20];
    gbyk_v4b_B.link_acceleration_c[1] = gbyk_v4b_B.Selector_c[21];

    /*  upper arm angular acceleration, orientation-independent (see above) (rad/s^2) */
    /* '<S242>:1:27' */
    gbyk_v4b_B.hand_position_g[0] = gbyk_v4b_B.Selector_c[22];
    gbyk_v4b_B.hand_position_g[1] = gbyk_v4b_B.Selector_c[23];

    /*  fingertip position in x,y (m) */
    /* '<S242>:1:28' */
    gbyk_v4b_B.hand_velocity_p[0] = gbyk_v4b_B.Selector_c[24];
    gbyk_v4b_B.hand_velocity_p[1] = gbyk_v4b_B.Selector_c[25];

    /*  fingertip velocity in x,y (m/s) */
    /* '<S242>:1:29' */
    gbyk_v4b_B.hand_acceleration_e[0] = gbyk_v4b_B.Selector_c[26];
    gbyk_v4b_B.hand_acceleration_e[1] = gbyk_v4b_B.Selector_c[27];

    /*  fingertip acceleration in x,y (m/s^2) */
    /*  shoulder_velocity_filt = robot_row(1,35); */
    /*  elbow_velocity_filt = robot_row(1,36); */
    /* '<S242>:1:34' */
    gbyk_v4b_B.motor_status_c = gbyk_v4b_B.Selector_c[36];

    /*  motor status (bitfield; each 0: motor enabled, 1: motor disabled/faulted) */
    /* '<S242>:1:36' */
    gbyk_v4b_B.force_sensor_force_uvw_g[0] = gbyk_v4b_B.Selector_c[37];
    gbyk_v4b_B.force_sensor_force_uvw_g[1] = gbyk_v4b_B.Selector_c[38];
    gbyk_v4b_B.force_sensor_force_uvw_g[2] = gbyk_v4b_B.Selector_c[39];

    /*  force measured by force sensor along u,v,w in its local coordinate system (N) */
    /* '<S242>:1:37' */
    gbyk_v4b_B.force_sensor_torque_uvw_d[0] = gbyk_v4b_B.Selector_c[40];
    gbyk_v4b_B.force_sensor_torque_uvw_d[1] = gbyk_v4b_B.Selector_c[41];
    gbyk_v4b_B.force_sensor_torque_uvw_d[2] = gbyk_v4b_B.Selector_c[42];

    /*  torque measured by force sensor along u,v,w in its local coordinate system (Nm) */
    /* '<S242>:1:39' */
    gbyk_v4b_B.force_sensor_force_xyz_g[0] = gbyk_v4b_B.Selector_c[43];
    gbyk_v4b_B.force_sensor_force_xyz_g[1] = gbyk_v4b_B.Selector_c[44];
    gbyk_v4b_B.force_sensor_force_xyz_g[2] = gbyk_v4b_B.Selector_c[45];

    /*  force measured by force sensor along x,y,z in the global coordinate system (N) */
    /* '<S242>:1:40' */
    gbyk_v4b_B.force_sensor_torque_xyz_g[0] = gbyk_v4b_B.Selector_c[46];
    gbyk_v4b_B.force_sensor_torque_xyz_g[1] = gbyk_v4b_B.Selector_c[47];
    gbyk_v4b_B.force_sensor_torque_xyz_g[2] = gbyk_v4b_B.Selector_c[48];

    /*  torque measured by force sensor along x in its local coordinate system (Nm) */
    /* '<S242>:1:41' */
    gbyk_v4b_B.force_sensor_timestamp_k = gbyk_v4b_B.Selector_c[49];

    /* MATLAB Function: '<S73>/splitKINData arm2' */
    /*  The timestamp from the force sensor(s) */
    /* MATLAB Function 'DataLogging/Poll KINARM/make KINData bus/splitKINData arm2': '<S243>:1' */
    /* '<S243>:1:9' */
    gbyk_v4b_B.link_lengths[0] = gbyk_v4b_B.Selector1_m[0];
    gbyk_v4b_B.link_lengths[1] = gbyk_v4b_B.Selector1_m[1];

    /*  L1, L2 length in m */
    /* '<S243>:1:10' */
    gbyk_v4b_B.pointer_offset = gbyk_v4b_B.Selector1_m[2];

    /*  perpendicular distance from L2 to subject pointer (m) */
    /* '<S243>:1:11' */
    gbyk_v4b_B.shoulder_loc[0] = gbyk_v4b_B.Selector1_m[3];
    gbyk_v4b_B.shoulder_loc[1] = gbyk_v4b_B.Selector1_m[4];

    /*  shoulder x,y position (m) (global coordinates) */
    /* '<S243>:1:12' */
    gbyk_v4b_B.arm_orientation = gbyk_v4b_B.Selector1_m[5];

    /*  subject's expected arm orientation (1: right, 2: left) */
    /* '<S243>:1:13' */
    gbyk_v4b_B.shoulder_ang = gbyk_v4b_B.Selector1_m[6];

    /*  shoulder joint angle, with correction for offsets (see above) (rad) */
    /* '<S243>:1:14' */
    gbyk_v4b_B.elbow_ang = gbyk_v4b_B.Selector1_m[7];

    /*  elbow joint angle, with correction for offsets (see above) (rad) */
    /* '<S243>:1:15' */
    gbyk_v4b_B.shoulder_velocity = gbyk_v4b_B.Selector1_m[8];

    /*  shoulder joint angular velocity (rad/s) */
    /* '<S243>:1:16' */
    gbyk_v4b_B.elbow_velocity = gbyk_v4b_B.Selector1_m[9];

    /*  elbow joint angular velocity (rad/s) */
    /* '<S243>:1:17' */
    gbyk_v4b_B.shoulder_acceleration = gbyk_v4b_B.Selector1_m[10];

    /*  shoulder joint angular acceleration (rad/s^2) */
    /* '<S243>:1:18' */
    gbyk_v4b_B.elbow_acceleration = gbyk_v4b_B.Selector1_m[11];

    /*  elbow joint angular acceleration (rad/s^2) */
    /* '<S243>:1:19' */
    gbyk_v4b_B.joint_torque_cmd[0] = gbyk_v4b_B.Selector1_m[12];
    gbyk_v4b_B.joint_torque_cmd[1] = gbyk_v4b_B.Selector1_m[13];

    /*  commanded shoulder (1), and elbow (2) torque (Nm) */
    /* '<S243>:1:20' */
    gbyk_v4b_B.motor_torque_cmd[0] = gbyk_v4b_B.Selector1_m[14];
    gbyk_v4b_B.motor_torque_cmd[1] = gbyk_v4b_B.Selector1_m[15];

    /*  commanded motor 1 (1) and 2 (2) torque (shoulder torque less elbow torque) (Nm) */
    /* '<S243>:1:22' */
    gbyk_v4b_B.link_angle[0] = gbyk_v4b_B.Selector1_m[16];
    gbyk_v4b_B.link_angle[1] = gbyk_v4b_B.Selector1_m[17];

    /*  upper arm angle with corrections, orientation-independent (see above) (rad) */
    /* '<S243>:1:23' */
    gbyk_v4b_B.link_velocity[0] = gbyk_v4b_B.Selector1_m[18];
    gbyk_v4b_B.link_velocity[1] = gbyk_v4b_B.Selector1_m[19];

    /*  upper arm angular velocity, orientation-independent (see above) (rad/s) */
    /* '<S243>:1:24' */
    gbyk_v4b_B.link_acceleration[0] = gbyk_v4b_B.Selector1_m[20];
    gbyk_v4b_B.link_acceleration[1] = gbyk_v4b_B.Selector1_m[21];

    /*  upper arm angular acceleration, orientation-independent (see above) (rad/s^2) */
    /* '<S243>:1:27' */
    gbyk_v4b_B.hand_position[0] = gbyk_v4b_B.Selector1_m[22];
    gbyk_v4b_B.hand_position[1] = gbyk_v4b_B.Selector1_m[23];

    /*  fingertip position in x,y (m) */
    /* '<S243>:1:28' */
    gbyk_v4b_B.hand_velocity[0] = gbyk_v4b_B.Selector1_m[24];
    gbyk_v4b_B.hand_velocity[1] = gbyk_v4b_B.Selector1_m[25];

    /*  fingertip velocity in x,y (m/s) */
    /* '<S243>:1:29' */
    gbyk_v4b_B.hand_acceleration[0] = gbyk_v4b_B.Selector1_m[26];
    gbyk_v4b_B.hand_acceleration[1] = gbyk_v4b_B.Selector1_m[27];

    /*  fingertip acceleration in x,y (m/s^2) */
    /*  shoulder_velocity_filt = robot_row(1,35); */
    /*  elbow_velocity_filt = robot_row(1,36); */
    /* '<S243>:1:34' */
    gbyk_v4b_B.motor_status = gbyk_v4b_B.Selector1_m[36];

    /*  motor status (bitfield; each 0: motor enabled, 1: motor disabled/faulted) */
    /* '<S243>:1:36' */
    gbyk_v4b_B.force_sensor_force_uvw[0] = gbyk_v4b_B.Selector1_m[37];
    gbyk_v4b_B.force_sensor_force_uvw[1] = gbyk_v4b_B.Selector1_m[38];
    gbyk_v4b_B.force_sensor_force_uvw[2] = gbyk_v4b_B.Selector1_m[39];

    /*  force measured by force sensor along u,v,w in its local coordinate system (N) */
    /* '<S243>:1:37' */
    gbyk_v4b_B.force_sensor_torque_uvw[0] = gbyk_v4b_B.Selector1_m[40];
    gbyk_v4b_B.force_sensor_torque_uvw[1] = gbyk_v4b_B.Selector1_m[41];
    gbyk_v4b_B.force_sensor_torque_uvw[2] = gbyk_v4b_B.Selector1_m[42];

    /*  torque measured by force sensor along u,v,w in its local coordinate system (Nm) */
    /* '<S243>:1:39' */
    gbyk_v4b_B.force_sensor_force_xyz[0] = gbyk_v4b_B.Selector1_m[43];
    gbyk_v4b_B.force_sensor_force_xyz[1] = gbyk_v4b_B.Selector1_m[44];
    gbyk_v4b_B.force_sensor_force_xyz[2] = gbyk_v4b_B.Selector1_m[45];

    /*  force measured by force sensor along x,y,z in the global coordinate system (N) */
    /* '<S243>:1:40' */
    gbyk_v4b_B.force_sensor_torque_xyz[0] = gbyk_v4b_B.Selector1_m[46];
    gbyk_v4b_B.force_sensor_torque_xyz[1] = gbyk_v4b_B.Selector1_m[47];
    gbyk_v4b_B.force_sensor_torque_xyz[2] = gbyk_v4b_B.Selector1_m[48];

    /*  torque measured by force sensor along x in its local coordinate system (Nm) */
    /* '<S243>:1:41' */
    gbyk_v4b_B.force_sensor_timestamp = gbyk_v4b_B.Selector1_m[49];

    /* MATLAB Function: '<S73>/splitKINDataGeneral' */
    /*  The timestamp from the force sensor(s) */
    /* MATLAB Function 'DataLogging/Poll KINARM/make KINData bus/splitKINDataGeneral': '<S244>:1' */
    /* '<S244>:1:5' */
    gbyk_v4b_B.active_arm = gbyk_v4b_B.Selector2_o[0];

    /*  dominant KINARM for the experiment (1: arm 1, 2: arm 2) */
    /* '<S244>:1:6' */
    gbyk_v4b_B.handFF = gbyk_v4b_B.Selector2_o[1];

    /*  duration of feed forward for position of hand feedback (s) */
    /* '<S244>:1:7' */
    gbyk_v4b_B.handFF_Dex = gbyk_v4b_B.Selector2_o[6];

    /*  the true feed forward time set in Dexterit-E */
    /* '<S244>:1:8' */
    gbyk_v4b_B.handFBArm = gbyk_v4b_B.Selector2_o[2];

    /*  hand feedback arm (0: none, 1: dominant, 2: non-dominant, 3: both, 4: controlled by task program) */
    /* '<S244>:1:9' */
    gbyk_v4b_B.handFBControl = gbyk_v4b_B.Selector2_o[3];

    /*  hand feedback settings source (0: GUI, 1: from task program) */
    /* '<S244>:1:10' */
    gbyk_v4b_B.handFBColor = gbyk_v4b_B.Selector2_o[4];

    /*  feedback colour (RRRGGGBBB string converted to integer) */
    /* '<S244>:1:11' */
    gbyk_v4b_B.handFBRadius = gbyk_v4b_B.Selector2_o[5];

    /*  feedback radius (m) */
    /* '<S244>:1:13' */
    gbyk_v4b_B.delayEstimates[0] = gbyk_v4b_B.Selector2_o[7];
    gbyk_v4b_B.delayEstimates[1] = gbyk_v4b_B.Selector2_o[8];
    gbyk_v4b_B.delayEstimates[2] = gbyk_v4b_B.Selector2_o[9];
    gbyk_v4b_B.delayEstimates[3] = gbyk_v4b_B.Selector2_o[10];

    /*  primary encoders velocity(1), acceleration(2), seconadary enc velocity(3) and acceleration(4) delay estimate (s) */
    /* '<S244>:1:14' */
    gbyk_v4b_B.servoCounter = gbyk_v4b_B.Selector2_o[11];

    /*  servo update count */
    /* '<S244>:1:15' */
    gbyk_v4b_B.calibrationButtonBits = gbyk_v4b_B.Selector2_o[12];

    /*  EP calibration button status bitfield */
    /* '<S244>:1:18' */
    gbyk_v4b_B.hasGaze = gbyk_v4b_B.Selector2_o[13];

    /*  is Gaze tracking hardware available */
    /* '<S244>:1:19' */
    gbyk_v4b_B.gazeFB = gbyk_v4b_B.Selector2_o[14];

    /*  Gaze feedback (0: on, 1: controlled by task program) */
    /* '<S244>:1:21' */
    gbyk_v4b_B.gazeLocation[0] = gbyk_v4b_B.Selector2_o[15];
    gbyk_v4b_B.gazeLocation[1] = gbyk_v4b_B.Selector2_o[16];

    /*  Gaze X,Y location in global coordinates */
    /* '<S244>:1:22' */
    gbyk_v4b_B.gazeTimestamp = gbyk_v4b_B.Selector2_o[17];

    /*  Gaze Timestamp in seconds */
    /* '<S244>:1:23' */
    gbyk_v4b_B.gazePupilArea = gbyk_v4b_B.Selector2_o[18];

    /*  Gaze pupil area */
    /* '<S244>:1:24' */
    gbyk_v4b_B.gazeEvent[0] = gbyk_v4b_B.Selector2_o[19];
    gbyk_v4b_B.gazeEvent[1] = gbyk_v4b_B.Selector2_o[20];
    gbyk_v4b_B.gazeEvent[2] = gbyk_v4b_B.Selector2_o[21];

    /*  Gaze Event ID(1), start time(2), end time (3)  */
    /* '<S244>:1:25' */
    gbyk_v4b_B.gazeVector[0] = gbyk_v4b_B.Selector2_o[22];
    gbyk_v4b_B.gazeVector[1] = gbyk_v4b_B.Selector2_o[23];
    gbyk_v4b_B.gazeVector[2] = gbyk_v4b_B.Selector2_o[24];

    /*  Gaze vector in global coordinates */
    /* '<S244>:1:26' */
    gbyk_v4b_B.gazePupilLoc[0] = gbyk_v4b_B.Selector2_o[25];
    gbyk_v4b_B.gazePupilLoc[1] = gbyk_v4b_B.Selector2_o[26];
    gbyk_v4b_B.gazePupilLoc[2] = gbyk_v4b_B.Selector2_o[27];

    /*  Gaze pupil location in global coordinates */
    for (i = 0; i < 6; i++) {
      /* Selector: '<S74>/Selector1' */
      gbyk_v4b_B.Selector1_a[i] = gbyk_v4b_B.primary_encoder_data_out[(i << 1) +
        1];

      /* Selector: '<S74>/Selector2' */
      gbyk_v4b_B.Selector2_i[i] = gbyk_v4b_B.primary_encoder_data_out[i << 1];
    }

    /* MATLAB Function: '<S74>/split_primary' */
    gbyk_v4b_split_primary(gbyk_v4b_B.Selector2_i, &gbyk_v4b_B.sf_split_primary);

    /* MATLAB Function: '<S74>/split_primary1' */
    gbyk_v4b_split_primary(gbyk_v4b_B.Selector1_a, &gbyk_v4b_B.sf_split_primary1);/* user code (Output function Trailer) */

    {
      /*------------ S-Function Block: <S64>/BKIN EtherCATinit1 Process Received Frames ------------*/
      real_T pauseDuration;
      real_T elapsedTime;
      real_T minDCSyncPauseDuration;
      int32_T minDCSyncPauseDurationMicroSec =
        ECAT_MIN_PAUSE_BEFORE_READ_PREOP_US;
      if (gbyk_v4b_P.activation_Value[0] == ECAT_PREOP_PAUSE_TEST) {
        minDCSyncPauseDurationMicroSec = gbyk_v4b_P.activation_Value[1];
      }

      if (gbyk_v4b_DW.BKINEtherCATinit1_DWORK3) {
        minDCSyncPauseDuration = minDCSyncPauseDurationMicroSec * 1e-6;
        elapsedTime = xpcGetElapsedTime(NULL) -
          gbyk_v4b_DW.BKINEtherCATinit1_DWORK4;
        if (elapsedTime < minDCSyncPauseDuration) {
          pauseDuration = minDCSyncPauseDuration - elapsedTime;
          xpcBusyWait(pauseDuration);
        }

        xpcEtherCATReadProcessData(1,NULL);
      }
    }

    {
      /*------------ S-Function Block: <S64>/BKIN EtherCATinit Process Received Frames ------------*/
      real_T pauseDuration;
      real_T elapsedTime;
      real_T minDCSyncPauseDuration;
      int32_T minDCSyncPauseDurationMicroSec =
        ECAT_MIN_PAUSE_BEFORE_READ_PREOP_US;
      if (gbyk_v4b_P.activation_Value[0] == ECAT_PREOP_PAUSE_TEST) {
        minDCSyncPauseDurationMicroSec = gbyk_v4b_P.activation_Value[1];
      }

      if (gbyk_v4b_DW.BKINEtherCATinit_DWORK3) {
        minDCSyncPauseDuration = minDCSyncPauseDurationMicroSec * 1e-6;
        elapsedTime = xpcGetElapsedTime(NULL) -
          gbyk_v4b_DW.BKINEtherCATinit_DWORK4;
        if (elapsedTime < minDCSyncPauseDuration) {
          pauseDuration = minDCSyncPauseDuration - elapsedTime;
          xpcBusyWait(pauseDuration);
        }

        xpcEtherCATReadProcessData(0,NULL);
      }
    }
  }
}

/* Update for atomic system: '<S4>/Poll KINARM' */
void gbyk_v4b_PollKINARM_Update(void)
{
  /* Update for Enabled SubSystem: '<S64>/Arm 1' incorporates:
   *  Update for EnablePort: '<S75>/Enable'
   */
  if (gbyk_v4b_DW.Arm1_MODE) {
    /* Update for Atomic SubSystem: '<S85>/EMCY Message pump' */
    gbyk_v4b_EMCYMessagepump_Update();

    /* End of Update for SubSystem: '<S85>/EMCY Message pump' */

    /* Update for Memory: '<S85>/Memory' */
    gbyk_v4b_DW.Memory_PreviousInput_g = gbyk_v4b_B.isPermFaulted_i;

    /* Update for Memory: '<S86>/Memory' */
    gbyk_v4b_DW.Memory_PreviousInput_pv =
      gbyk_v4b_B.sf_ControlGDCWhistleState_f.isPermFaulted;

    /* Update for Memory: '<S94>/Memory' */
    gbyk_v4b_DW.Memory_PreviousInput_pn = gbyk_v4b_B.RateTransition_bs;

    /* Update for Memory: '<S94>/Memory1' */
    gbyk_v4b_DW.Memory1_PreviousInput_i = gbyk_v4b_B.RateTransition1_ds;

    /* Update for Memory: '<S94>/Memory2' */
    gbyk_v4b_DW.Memory2_PreviousInput_p = gbyk_v4b_B.RateTransition2_dj;

    /* Update for Memory: '<S75>/Memory2' */
    gbyk_v4b_DW.Memory2_PreviousInput_i[0] = gbyk_v4b_B.continuousTorques_j[0];
    gbyk_v4b_DW.Memory2_PreviousInput_i[1] = gbyk_v4b_B.continuousTorques_j[1];

    /* Update for Memory: '<S75>/Memory3' */
    gbyk_v4b_DW.Memory3_PreviousInput_l = gbyk_v4b_B.constantsReady_j;

    /* Update for Atomic SubSystem: '<S86>/EMCY Message pump' */
    gbyk_v4b_EMCYMessagepump_e_Update();

    /* End of Update for SubSystem: '<S86>/EMCY Message pump' */

    /* Update for Enabled SubSystem: '<S75>/M1 AbsEnc Calibration' incorporates:
     *  Update for EnablePort: '<S88>/Enable'
     */
    if (gbyk_v4b_DW.M1AbsEncCalibration_MODE_i) {
      /* Update for Memory: '<S88>/Memory' */
      gbyk_v4b_DW.Memory_PreviousInput_hw =
        gbyk_v4b_B.BKINEtherCATAsyncSDODownload_i;

      /* Update for Memory: '<S88>/Memory1' */
      gbyk_v4b_DW.Memory1_PreviousInput_g[0] =
        gbyk_v4b_B.BKINEtherCATAsyncSDOUpload_o1_p;
      gbyk_v4b_DW.Memory1_PreviousInput_g[1] =
        gbyk_v4b_B.BKINEtherCATAsyncSDOUpload_o2_a;
    }

    /* End of Update for SubSystem: '<S75>/M1 AbsEnc Calibration' */

    /* Update for Enabled SubSystem: '<S75>/M2 AbsEnc Calibration' incorporates:
     *  Update for EnablePort: '<S89>/Enable'
     */
    if (gbyk_v4b_DW.M2AbsEncCalibration_MODE_a) {
      /* Update for Memory: '<S89>/Memory' */
      gbyk_v4b_DW.Memory_PreviousInput_i =
        gbyk_v4b_B.BKINEtherCATAsyncSDODownload_ce;

      /* Update for Memory: '<S89>/Memory1' */
      gbyk_v4b_DW.Memory1_PreviousInput_a[0] =
        gbyk_v4b_B.BKINEtherCATAsyncSDOUpload_o1_dq;
      gbyk_v4b_DW.Memory1_PreviousInput_a[1] =
        gbyk_v4b_B.BKINEtherCATAsyncSDOUpload_o2_m;
    }

    /* End of Update for SubSystem: '<S75>/M2 AbsEnc Calibration' */

    /* Update for Atomic SubSystem: '<S75>/SDO reading' */
    gbyk_v4b_SDOreading_Update();

    /* End of Update for SubSystem: '<S75>/SDO reading' */

    /* Update for Atomic SubSystem: '<S75>/SDO writing' */
    gbyk_v4b_SDOwriting_Update();

    /* End of Update for SubSystem: '<S75>/SDO writing' */
  }

  /* End of Update for SubSystem: '<S64>/Arm 1' */

  /* Update for Enabled SubSystem: '<S64>/Arm 2' incorporates:
   *  Update for EnablePort: '<S76>/Enable'
   */
  if (gbyk_v4b_DW.Arm2_MODE) {
    /* Update for Atomic SubSystem: '<S137>/EMCY Message pump' */
    gbyk_v4b_EMCYMessagepump_n_Update();

    /* End of Update for SubSystem: '<S137>/EMCY Message pump' */

    /* Update for Memory: '<S137>/Memory' */
    gbyk_v4b_DW.Memory_PreviousInput_l =
      gbyk_v4b_B.sf_ControlGDCWhistleState_p.isPermFaulted;

    /* Update for Memory: '<S138>/Memory' */
    gbyk_v4b_DW.Memory_PreviousInput_h = gbyk_v4b_B.isPermFaulted;

    /* Update for Memory: '<S146>/Memory' */
    gbyk_v4b_DW.Memory_PreviousInput_b = gbyk_v4b_B.RateTransition_bx;

    /* Update for Memory: '<S146>/Memory1' */
    gbyk_v4b_DW.Memory1_PreviousInput_c = gbyk_v4b_B.RateTransition1_d;

    /* Update for Memory: '<S146>/Memory2' */
    gbyk_v4b_DW.Memory2_PreviousInput = gbyk_v4b_B.RateTransition2_j;

    /* Update for Memory: '<S76>/Memory2' */
    gbyk_v4b_DW.Memory2_PreviousInput_n[0] = gbyk_v4b_B.continuousTorques[0];
    gbyk_v4b_DW.Memory2_PreviousInput_n[1] = gbyk_v4b_B.continuousTorques[1];

    /* Update for Memory: '<S76>/Memory3' */
    gbyk_v4b_DW.Memory3_PreviousInput = gbyk_v4b_B.constantsReady;

    /* Update for Atomic SubSystem: '<S138>/EMCY Message pump' */
    gbyk_v4b_EMCYMessagepump_o_Update();

    /* End of Update for SubSystem: '<S138>/EMCY Message pump' */

    /* Update for Enabled SubSystem: '<S76>/M1 AbsEnc Calibration' incorporates:
     *  Update for EnablePort: '<S140>/Enable'
     */
    if (gbyk_v4b_DW.M1AbsEncCalibration_MODE) {
      /* Update for Memory: '<S140>/Memory' */
      gbyk_v4b_DW.Memory_PreviousInput_cs =
        gbyk_v4b_B.BKINEtherCATAsyncSDODownload_g0;

      /* Update for Memory: '<S140>/Memory1' */
      gbyk_v4b_DW.Memory1_PreviousInput_io[0] =
        gbyk_v4b_B.BKINEtherCATAsyncSDOUpload_o1_k;
      gbyk_v4b_DW.Memory1_PreviousInput_io[1] =
        gbyk_v4b_B.BKINEtherCATAsyncSDOUpload_o2_o;
    }

    /* End of Update for SubSystem: '<S76>/M1 AbsEnc Calibration' */

    /* Update for Enabled SubSystem: '<S76>/M2 AbsEnc Calibration' incorporates:
     *  Update for EnablePort: '<S141>/Enable'
     */
    if (gbyk_v4b_DW.M2AbsEncCalibration_MODE) {
      /* Update for Memory: '<S141>/Memory' */
      gbyk_v4b_DW.Memory_PreviousInput_o =
        gbyk_v4b_B.BKINEtherCATAsyncSDODownload_g;

      /* Update for Memory: '<S141>/Memory1' */
      gbyk_v4b_DW.Memory1_PreviousInput_l[0] =
        gbyk_v4b_B.BKINEtherCATAsyncSDOUpload_o1;
      gbyk_v4b_DW.Memory1_PreviousInput_l[1] =
        gbyk_v4b_B.BKINEtherCATAsyncSDOUpload_o2;
    }

    /* End of Update for SubSystem: '<S76>/M2 AbsEnc Calibration' */

    /* Update for Atomic SubSystem: '<S76>/SDO reading' */
    gbyk_v4b_SDOreading_a_Update();

    /* End of Update for SubSystem: '<S76>/SDO reading' */

    /* Update for Atomic SubSystem: '<S76>/SDO writing' */
    gbyk_v4b_SDOwriting_f_Update();

    /* End of Update for SubSystem: '<S76>/SDO writing' */
  }

  /* End of Update for SubSystem: '<S64>/Arm 2' */

  /* Update for Atomic SubSystem: '<S34>/Force Sensor Control' */
  gbyk_v4b_ForceSensorControl_Update();

  /* End of Update for SubSystem: '<S34>/Force Sensor Control' */

  /* Update for Enabled SubSystem: '<S67>/Data receive' incorporates:
   *  Update for EnablePort: '<S223>/Enable'
   */
  if (gbyk_v4b_B.Compare_a) {
    /* Update for UnitDelay: '<S226>/Output' */
    gbyk_v4b_DW.Output_DSTATE_h = gbyk_v4b_B.FixPtSwitch_d;
  }

  /* End of Update for SubSystem: '<S67>/Data receive' */

  /* Update for Enabled SubSystem: '<S66>/read_pmac' */
  gbyk_v4b_read_pmac_Update();

  /* End of Update for SubSystem: '<S66>/read_pmac' */

  /* Update for UnitDelay: '<S78>/Output' */
  gbyk_v4b_DW.Output_DSTATE_c = gbyk_v4b_B.FixPtSwitch_m;
}

/* Termination for atomic system: '<S4>/Poll KINARM' */
void gbyk_v4b_PollKINARM_Term(void)
{
  /* Terminate for Enabled SubSystem: '<S64>/Arm 1' */

  /* Level2 S-Function Block: '<S75>/BKIN EtherCAT PDO Transmit ' (BKINethercatpdotx) */
  {
    SimStruct *rts = gbyk_v4b_M->childSfunctions[10];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S75>/BKIN EtherCAT PDO Transmit 1' (BKINethercatpdotx) */
  {
    SimStruct *rts = gbyk_v4b_M->childSfunctions[11];
    sfcnTerminate(rts);
  }

  /* Terminate for Atomic SubSystem: '<S85>/A1M1 PDOs' */

  /* Level2 S-Function Block: '<S99>/BKIN PDO Receive ElmoDrive' (BKINethercatpdorxElmoDrive) */
  {
    SimStruct *rts = gbyk_v4b_M->childSfunctions[8];
    sfcnTerminate(rts);
  }

  /* End of Terminate for SubSystem: '<S85>/A1M1 PDOs' */

  /* Terminate for Atomic SubSystem: '<S85>/EMCY Message pump' */
  gbyk_v4b_EMCYMessagepump_Term();

  /* End of Terminate for SubSystem: '<S85>/EMCY Message pump' */

  /* Level2 S-Function Block: '<S85>/BKIN EtherCAT PDO Transmit ' (BKINethercatpdotx) */
  {
    SimStruct *rts = gbyk_v4b_M->childSfunctions[12];
    sfcnTerminate(rts);
  }

  /* Terminate for Atomic SubSystem: '<S86>/A1M2 PDOs' */

  /* Level2 S-Function Block: '<S112>/BKIN PDO Receive ElmoDrive' (BKINethercatpdorxElmoDrive) */
  {
    SimStruct *rts = gbyk_v4b_M->childSfunctions[9];
    sfcnTerminate(rts);
  }

  /* End of Terminate for SubSystem: '<S86>/A1M2 PDOs' */

  /* Terminate for Atomic SubSystem: '<S86>/EMCY Message pump' */
  gbyk_v4b_EMCYMessagepump_j_Term();

  /* End of Terminate for SubSystem: '<S86>/EMCY Message pump' */

  /* Level2 S-Function Block: '<S86>/BKIN EtherCAT PDO Transmit ' (BKINethercatpdotx) */
  {
    SimStruct *rts = gbyk_v4b_M->childSfunctions[13];
    sfcnTerminate(rts);
  }

  /* Terminate for Atomic SubSystem: '<S94>/Read Drive 1 SDO' */
  gbyk_v4b_ReadDrive1SDO_i_Term();

  /* End of Terminate for SubSystem: '<S94>/Read Drive 1 SDO' */

  /* Terminate for Enabled SubSystem: '<S75>/M1 AbsEnc Calibration' */

  /* Terminate for S-Function (BKINethercatasyncsdodownload): '<S88>/BKIN EtherCAT Async SDO Download' */
  {
    int_T deviceIndex;
    if (!xpcIsModelInit()) {
      deviceIndex = gbyk_v4b_DW.BKINEtherCATAsyncSDODownload_IWORK_j[0];
      if (deviceIndex != NO_ETHERCAT) {
        unregisterAsyncSDODownload(342971113, deviceIndex);
        printf("SDO Download. Unregister device %d, slave addr: %d\n",
               deviceIndex, 1001);
      }
    }
  }

  /* Terminate for S-Function (BKINethercatasyncsdoupload): '<S88>/BKIN EtherCAT Async SDO Upload' */
  {
    int_T deviceIndex;
    if (!xpcIsModelInit()) {
      deviceIndex = gbyk_v4b_DW.BKINEtherCATAsyncSDOUpload_IWORK_h[0];
      if (deviceIndex != NO_ETHERCAT) {
        unregisterAsyncSDOUpload(342971114, deviceIndex);
        printf("SDO Upload. Unregister device %d, slave addr: %d\n", deviceIndex,
               1001);
      }
    }
  }

  /* End of Terminate for SubSystem: '<S75>/M1 AbsEnc Calibration' */

  /* Terminate for Enabled SubSystem: '<S75>/M2 AbsEnc Calibration' */

  /* Terminate for S-Function (BKINethercatasyncsdodownload): '<S89>/BKIN EtherCAT Async SDO Download' */
  {
    int_T deviceIndex;
    if (!xpcIsModelInit()) {
      deviceIndex = gbyk_v4b_DW.BKINEtherCATAsyncSDODownload_IWORK_a0[0];
      if (deviceIndex != NO_ETHERCAT) {
        unregisterAsyncSDODownload(342974267, deviceIndex);
        printf("SDO Download. Unregister device %d, slave addr: %d\n",
               deviceIndex, 1002);
      }
    }
  }

  /* Terminate for S-Function (BKINethercatasyncsdoupload): '<S89>/BKIN EtherCAT Async SDO Upload' */
  {
    int_T deviceIndex;
    if (!xpcIsModelInit()) {
      deviceIndex = gbyk_v4b_DW.BKINEtherCATAsyncSDOUpload_IWORK_f[0];
      if (deviceIndex != NO_ETHERCAT) {
        unregisterAsyncSDOUpload(342974268, deviceIndex);
        printf("SDO Upload. Unregister device %d, slave addr: %d\n", deviceIndex,
               1002);
      }
    }
  }

  /* End of Terminate for SubSystem: '<S75>/M2 AbsEnc Calibration' */

  /* Terminate for Atomic SubSystem: '<S75>/SDO reading' */
  gbyk_v4b_SDOreading_Term();

  /* End of Terminate for SubSystem: '<S75>/SDO reading' */

  /* Terminate for Atomic SubSystem: '<S75>/SDO writing' */
  gbyk_v4b_SDOwriting_Term();

  /* End of Terminate for SubSystem: '<S75>/SDO writing' */

  /* End of Terminate for SubSystem: '<S64>/Arm 1' */

  /* Terminate for Enabled SubSystem: '<S64>/Arm 2' */

  /* Level2 S-Function Block: '<S76>/BKIN EtherCAT PDO Transmit ' (BKINethercatpdotx) */
  {
    SimStruct *rts = gbyk_v4b_M->childSfunctions[16];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S76>/BKIN EtherCAT PDO Transmit 1' (BKINethercatpdotx) */
  {
    SimStruct *rts = gbyk_v4b_M->childSfunctions[17];
    sfcnTerminate(rts);
  }

  /* Terminate for Atomic SubSystem: '<S137>/A2M1 PDOs' */
  gbyk_v4b_A2M1PDOs_Term();

  /* End of Terminate for SubSystem: '<S137>/A2M1 PDOs' */

  /* Terminate for Atomic SubSystem: '<S137>/EMCY Message pump' */
  gbyk_v4b_EMCYMessagepump_l_Term();

  /* End of Terminate for SubSystem: '<S137>/EMCY Message pump' */

  /* Level2 S-Function Block: '<S137>/BKIN EtherCAT PDO Transmit ' (BKINethercatpdotx) */
  {
    SimStruct *rts = gbyk_v4b_M->childSfunctions[18];
    sfcnTerminate(rts);
  }

  /* Terminate for Atomic SubSystem: '<S138>/A2M2 PDOs' */
  gbyk_v4b_A2M2PDOs_Term();

  /* End of Terminate for SubSystem: '<S138>/A2M2 PDOs' */

  /* Terminate for Atomic SubSystem: '<S138>/EMCY Message pump' */
  gbyk_v4b_EMCYMessagepump_i_Term();

  /* End of Terminate for SubSystem: '<S138>/EMCY Message pump' */

  /* Level2 S-Function Block: '<S138>/BKIN EtherCAT PDO Transmit ' (BKINethercatpdotx) */
  {
    SimStruct *rts = gbyk_v4b_M->childSfunctions[19];
    sfcnTerminate(rts);
  }

  /* Terminate for Atomic SubSystem: '<S146>/Read Drive 3 SDO' */
  gbyk_v4b_ReadDrive3SDO_a_Term();

  /* End of Terminate for SubSystem: '<S146>/Read Drive 3 SDO' */

  /* Terminate for Enabled SubSystem: '<S76>/M1 AbsEnc Calibration' */

  /* Terminate for S-Function (BKINethercatasyncsdodownload): '<S140>/BKIN EtherCAT Async SDO Download' */
  {
    int_T deviceIndex;
    if (!xpcIsModelInit()) {
      deviceIndex = gbyk_v4b_DW.BKINEtherCATAsyncSDODownload_IWORK_m[0];
      if (deviceIndex != NO_ETHERCAT) {
        unregisterAsyncSDODownload(342974277, deviceIndex);
        printf("SDO Download. Unregister device %d, slave addr: %d\n",
               deviceIndex, 1003);
      }
    }
  }

  /* Terminate for S-Function (BKINethercatasyncsdoupload): '<S140>/BKIN EtherCAT Async SDO Upload' */
  {
    int_T deviceIndex;
    if (!xpcIsModelInit()) {
      deviceIndex = gbyk_v4b_DW.BKINEtherCATAsyncSDOUpload_IWORK_o[0];
      if (deviceIndex != NO_ETHERCAT) {
        unregisterAsyncSDOUpload(342974278, deviceIndex);
        printf("SDO Upload. Unregister device %d, slave addr: %d\n", deviceIndex,
               1003);
      }
    }
  }

  /* End of Terminate for SubSystem: '<S76>/M1 AbsEnc Calibration' */

  /* Terminate for Enabled SubSystem: '<S76>/M2 AbsEnc Calibration' */

  /* Terminate for S-Function (BKINethercatasyncsdodownload): '<S141>/BKIN EtherCAT Async SDO Download' */
  {
    int_T deviceIndex;
    if (!xpcIsModelInit()) {
      deviceIndex = gbyk_v4b_DW.BKINEtherCATAsyncSDODownload_IWORK_k[0];
      if (deviceIndex != NO_ETHERCAT) {
        unregisterAsyncSDODownload(342974287, deviceIndex);
        printf("SDO Download. Unregister device %d, slave addr: %d\n",
               deviceIndex, 1004);
      }
    }
  }

  /* Terminate for S-Function (BKINethercatasyncsdoupload): '<S141>/BKIN EtherCAT Async SDO Upload' */
  {
    int_T deviceIndex;
    if (!xpcIsModelInit()) {
      deviceIndex = gbyk_v4b_DW.BKINEtherCATAsyncSDOUpload_IWORK[0];
      if (deviceIndex != NO_ETHERCAT) {
        unregisterAsyncSDOUpload(342974288, deviceIndex);
        printf("SDO Upload. Unregister device %d, slave addr: %d\n", deviceIndex,
               1004);
      }
    }
  }

  /* End of Terminate for SubSystem: '<S76>/M2 AbsEnc Calibration' */

  /* Terminate for Atomic SubSystem: '<S76>/SDO reading' */
  gbyk_v4b_SDOreading_h_Term();

  /* End of Terminate for SubSystem: '<S76>/SDO reading' */

  /* Terminate for Atomic SubSystem: '<S76>/SDO writing' */
  gbyk_v4b_SDOwriting_k_Term();

  /* End of Terminate for SubSystem: '<S76>/SDO writing' */

  /* End of Terminate for SubSystem: '<S64>/Arm 2' */

  /* Level2 S-Function Block: '<S79>/BKIN EtherCAT PDO Transmit ' (BKINethercatpdotx) */
  {
    SimStruct *rts = gbyk_v4b_M->childSfunctions[29];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S79>/BKIN EtherCAT PDO Transmit 1' (BKINethercatpdotx) */
  {
    SimStruct *rts = gbyk_v4b_M->childSfunctions[30];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S79>/BKIN EtherCAT PDO Transmit 2' (BKINethercatpdotx) */
  {
    SimStruct *rts = gbyk_v4b_M->childSfunctions[31];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S79>/BKIN EtherCAT PDO Transmit 3' (BKINethercatpdotx) */
  {
    SimStruct *rts = gbyk_v4b_M->childSfunctions[32];
    sfcnTerminate(rts);
  }

  /* Terminate for Atomic SubSystem: '<S34>/Force Sensor Control' */
  gbyk_v4b_ForceSensorControl_Term();

  /* End of Terminate for SubSystem: '<S34>/Force Sensor Control' */

  /* Terminate for Enabled SubSystem: '<S67>/Data receive' */

  /* Level2 S-Function Block: '<S223>/Receive' (xpcudpbytereceive) */
  {
    SimStruct *rts = gbyk_v4b_M->childSfunctions[28];
    sfcnTerminate(rts);
  }

  /* End of Terminate for SubSystem: '<S67>/Data receive' */

  /* Terminate for Enabled SubSystem: '<S66>/read_pmac' */
  gbyk_v4b_read_pmac_Term();

  /* End of Terminate for SubSystem: '<S66>/read_pmac' */
}
