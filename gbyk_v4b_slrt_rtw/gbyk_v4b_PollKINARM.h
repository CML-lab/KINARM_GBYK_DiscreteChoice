/*
 * Code generation for system system '<S4>/Poll KINARM'
 * For more details, see corresponding source file gbyk_v4b_PollKINARM.c
 *
 */

#ifndef RTW_HEADER_gbyk_v4b_PollKINARM_h_
#define RTW_HEADER_gbyk_v4b_PollKINARM_h_
#include <stddef.h>
#include <string.h>
#include <math.h>
#ifndef gbyk_v4b_COMMON_INCLUDES_
# define gbyk_v4b_COMMON_INCLUDES_
#include <xpcimports.h>
#include <xpcdatatypes.h>
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rt_logging.h"
#include "stddef.h"
#include "stdlib.h"
#include "xpcethercatutils.h"
#include "xpctarget.h"
#include "BKINethercat.h"
#include "io_config_xml_1.h"
#include "io_config_xml_0.h"
#endif                                 /* gbyk_v4b_COMMON_INCLUDES_ */

#include "gbyk_v4b_types.h"

/* Shared type includes */
#include "multiword_types.h"

/* Child system includes */
#include "gbyk_v4b_ForceSensorControl.h"
#include "gbyk_v4b_createKINData.h"
#include "gbyk_v4b_read_pmac.h"
#include "rt_nonfinite.h"

/* Block signals for system '<S99>/parse status register' */
typedef struct {
  uint32_T allOK;                      /* '<S99>/parse status register' */
  uint32_T ampStatus;                  /* '<S99>/parse status register' */
  uint32_T servoEnabled;               /* '<S99>/parse status register' */
  uint32_T faultFound;                 /* '<S99>/parse status register' */
  uint32_T currentLimitEnabled;        /* '<S99>/parse status register' */
  uint32_T eStopOut;                   /* '<S99>/parse status register' */
  uint32_T motorOn;                    /* '<S99>/parse status register' */
} B_parsestatusregister_gbyk_v4b_T;

/* Block signals for system '<S102>/fault monitor' */
typedef struct {
  real_T triggerFaultRead;             /* '<S102>/fault monitor' */
} B_faultmonitor_gbyk_v4b_T;

/* Block states (auto storage) for system '<S102>/fault monitor' */
typedef struct {
  real_T preOpCounter;                 /* '<S102>/fault monitor' */
} DW_faultmonitor_gbyk_v4b_T;

/* Block signals for system '<S102>/fault monitor1' */
typedef struct {
  real_T EMCYMsg[5];                   /* '<S102>/fault monitor1' */
  uint32_T TmpSignalConversionAtSFunctionInport2[3];/* '<S102>/fault monitor1' */
} B_faultmonitor1_gbyk_v4b_T;

/* Block states (auto storage) for system '<S102>/fault monitor1' */
typedef struct {
  real_T underVoltageCounter;          /* '<S102>/fault monitor1' */
  uint32_T lastRegister;               /* '<S102>/fault monitor1' */
} DW_faultmonitor1_gbyk_v4b_T;

/* Block signals for system '<S86>/Control GDC Whistle State' */
typedef struct {
  real_T isPermFaulted;                /* '<S86>/Control GDC Whistle State' */
  uint32_T motorStatus;                /* '<S86>/Control GDC Whistle State' */
  uint16_T ControlWord;                /* '<S86>/Control GDC Whistle State' */
} B_ControlGDCWhistleState_gbyk_v4b_T;

/* Block states (auto storage) for system '<S86>/Control GDC Whistle State' */
typedef struct {
  real_T permFaulted;                  /* '<S86>/Control GDC Whistle State' */
  real_T countFaultSteps;              /* '<S86>/Control GDC Whistle State' */
  real_T frameCounter;                 /* '<S86>/Control GDC Whistle State' */
  uint32_T lastEStopState;             /* '<S86>/Control GDC Whistle State' */
  boolean_T permFaulted_not_empty;     /* '<S86>/Control GDC Whistle State' */
} DW_ControlGDCWhistleState_gbyk_v4b_T;

/* Block signals for system '<S75>/Find Robot type' */
typedef struct {
  real_T robotType;                    /* '<S75>/Find Robot type' */
} B_FindRobottype_gbyk_v4b_T;

/* Block signals for system '<S88>/AbsEncoder machine' */
typedef struct {
  int32_T setupData[4];                /* '<S88>/AbsEncoder machine' */
  int32_T SDORequest[3];               /* '<S88>/AbsEncoder machine' */
  int32_T encoderOutputs[6];           /* '<S88>/AbsEncoder machine' */
  int32_T complete;                    /* '<S88>/AbsEncoder machine' */
} B_AbsEncodermachine_gbyk_v4b_T;

/* Block states (auto storage) for system '<S88>/AbsEncoder machine' */
typedef struct {
  real_T encoderIdx;                   /* '<S88>/AbsEncoder machine' */
  int32_T sfEvent;                     /* '<S88>/AbsEncoder machine' */
  int32_T setupIdx;                    /* '<S88>/AbsEncoder machine' */
  int32_T donePolling;                 /* '<S88>/AbsEncoder machine' */
  uint8_T is_active_c43_ethercat;      /* '<S88>/AbsEncoder machine' */
  uint8_T is_c43_ethercat;             /* '<S88>/AbsEncoder machine' */
  boolean_T isStable;                  /* '<S88>/AbsEncoder machine' */
} DW_AbsEncodermachine_gbyk_v4b_T;

/* Block signals for system '<S88>/set-up values' */
typedef struct {
  real_T setupValues[24];              /* '<S88>/set-up values' */
  real_T setupValuesCount;             /* '<S88>/set-up values' */
  real_T pollValues[3];                /* '<S88>/set-up values' */
  real_T encoderValues[12];            /* '<S88>/set-up values' */
  real_T encoderValuesCount;           /* '<S88>/set-up values' */
} B_setupvalues_gbyk_v4b_T;

/* Block signals for system '<S75>/SDO read machine' */
typedef struct {
  real_T floatSDOValues[20];           /* '<S75>/SDO read machine' */
  int32_T SDOCommand[3];               /* '<S75>/SDO read machine' */
  int32_T intSDOValues[20];            /* '<S75>/SDO read machine' */
  int32_T complete;                    /* '<S75>/SDO read machine' */
} B_SDOreadmachine_gbyk_v4b_T;

/* Block states (auto storage) for system '<S75>/SDO read machine' */
typedef struct {
  real_T valueCount;                   /* '<S75>/SDO read machine' */
  int32_T sfEvent;                     /* '<S75>/SDO read machine' */
  int32_T valueIdx;                    /* '<S75>/SDO read machine' */
  int32_T lastTrigger;                 /* '<S75>/SDO read machine' */
  uint8_T is_active_c49_ethercat;      /* '<S75>/SDO read machine' */
  uint8_T is_c49_ethercat;             /* '<S75>/SDO read machine' */
  boolean_T isStable;                  /* '<S75>/SDO read machine' */
} DW_SDOreadmachine_gbyk_v4b_T;

/* Block signals for system '<S129>/converter' */
typedef struct {
  real_T doubleOut;                    /* '<S129>/converter' */
  int32_T int32Out;                    /* '<S129>/converter' */
  uint32_T uint32Out;                  /* '<S129>/converter' */
} B_converter_gbyk_v4b_T;

/* Block signals for system '<S91>/SDO read machine' */
typedef struct {
  int32_T enable;                      /* '<S91>/SDO read machine' */
  int32_T complete;                    /* '<S91>/SDO read machine' */
} B_SDOreadmachine_gbyk_v4b_n_T;

/* Block states (auto storage) for system '<S91>/SDO read machine' */
typedef struct {
  int32_T sfEvent;                     /* '<S91>/SDO read machine' */
  int32_T lastTriggerValue;            /* '<S91>/SDO read machine' */
  uint8_T is_active_c50_ethercat;      /* '<S91>/SDO read machine' */
  uint8_T is_c50_ethercat;             /* '<S91>/SDO read machine' */
  boolean_T isStable;                  /* '<S91>/SDO read machine' */
} DW_SDOreadmachine_gbyk_v4b_m_T;

/* Block signals for system '<S91>/values' */
typedef struct {
  real_T TmpSignalConversionAtSFunctionInport1[3];/* '<S91>/values' */
  real_T outVal[3];                    /* '<S91>/values' */
} B_values_gbyk_v4b_T;

/* Block signals for system '<S92>/SDO write machine' */
typedef struct {
  int32_T enable;                      /* '<S92>/SDO write machine' */
  int32_T complete;                    /* '<S92>/SDO write machine' */
} B_SDOwritemachine_gbyk_v4b_T;

/* Block states (auto storage) for system '<S92>/SDO write machine' */
typedef struct {
  int32_T sfEvent;                     /* '<S92>/SDO write machine' */
  int32_T lastTriggerValue;            /* '<S92>/SDO write machine' */
  uint8_T is_active_c52_ethercat;      /* '<S92>/SDO write machine' */
  uint8_T is_c52_ethercat;             /* '<S92>/SDO write machine' */
  boolean_T isStable;                  /* '<S92>/SDO write machine' */
} DW_SDOwritemachine_gbyk_v4b_T;

/* Block signals for system '<S92>/convert' */
typedef struct {
  uint32_T y;                          /* '<S92>/convert' */
} B_convert_gbyk_v4b_T;

/* Block signals for system '<S75>/forceEnableDisable' */
typedef struct {
  real_T TmpSignalConversionAtSFunctionInport5[2];/* '<S75>/forceEnableDisable' */
  real_T forceMotorState;              /* '<S75>/forceEnableDisable' */
} B_forceEnableDisable_gbyk_v4b_T;

/* Block states (auto storage) for system '<S75>/forceEnableDisable' */
typedef struct {
  real_T lastRunningState;             /* '<S75>/forceEnableDisable' */
  real_T faultResetCycles;             /* '<S75>/forceEnableDisable' */
} DW_forceEnableDisable_gbyk_v4b_T;

/* Block signals for system '<S75>/size' */
typedef struct {
  real_T count;                        /* '<S75>/size' */
} B_size_gbyk_v4b_T;

/* Block signals for system '<S75>/split out constants1' */
typedef struct {
  real_T hasSecondary;                 /* '<S75>/split out constants1' */
  real_T hasFT;                        /* '<S75>/split out constants1' */
  real_T robotOrientation;             /* '<S75>/split out constants1' */
  real_T motorOrientation[2];          /* '<S75>/split out constants1' */
  real_T encOrientation[2];            /* '<S75>/split out constants1' */
} B_splitoutconstants1_gbyk_v4b_T;

/* Block signals for system '<S154>/Read EMCY' */
typedef struct {
  real_T emcyValPump[3];               /* '<S154>/Read EMCY' */
  int32_T triggerCountRead;            /* '<S154>/Read EMCY' */
  int32_T emcyReadTrigger[2];          /* '<S154>/Read EMCY' */
  int32_T countOverwriteTrigger;       /* '<S154>/Read EMCY' */
} B_ReadEMCY_gbyk_v4b_T;

/* Block states (auto storage) for system '<S154>/Read EMCY' */
typedef struct {
  real_T currReadIdx;                  /* '<S154>/Read EMCY' */
  real_T valuesToRead;                 /* '<S154>/Read EMCY' */
  int32_T sfEvent;                     /* '<S154>/Read EMCY' */
  uint8_T is_active_c104_ethercat;     /* '<S154>/Read EMCY' */
  uint8_T is_c104_ethercat;            /* '<S154>/Read EMCY' */
  boolean_T isStable;                  /* '<S154>/Read EMCY' */
} DW_ReadEMCY_gbyk_v4b_T;

/* Block signals for system '<S230>/decode robot' */
typedef struct {
  real_T isEP;                         /* '<S230>/decode robot' */
  real_T isHumanEXO;                   /* '<S230>/decode robot' */
  real_T isNHPEXO;                     /* '<S230>/decode robot' */
  real_T isClassicExo;                 /* '<S230>/decode robot' */
  real_T isUTSEXO;                     /* '<S230>/decode robot' */
  real_T isPMAC;                       /* '<S230>/decode robot' */
  real_T isECAT;                       /* '<S230>/decode robot' */
} B_decoderobot_gbyk_v4b_T;

/* Block signals for system '<S74>/split_primary' */
typedef struct {
  real_T link_angles[2];               /* '<S74>/split_primary' */
  real_T link_velocities[2];           /* '<S74>/split_primary' */
  real_T link_acceleration[2];         /* '<S74>/split_primary' */
} B_split_primary_gbyk_v4b_T;

extern void gbyk_v4b_parsestatusregister(uint32_T rtu_statusRegister,
  B_parsestatusregister_gbyk_v4b_T *localB);
extern void gbyk_v4b_faultmonitor_Init(DW_faultmonitor_gbyk_v4b_T *localDW);
extern void gbyk_v4b_faultmonitor(uint16_T rtu_StatusWord,
  B_faultmonitor_gbyk_v4b_T *localB, DW_faultmonitor_gbyk_v4b_T *localDW);
extern void gbyk_v4b_faultmonitor1_Init(DW_faultmonitor1_gbyk_v4b_T *localDW);
extern void gbyk_v4b_faultmonitor1(const real_T rtu_SDOEMCY[3], uint32_T
  rtu_registerInfo, uint32_T rtu_registerInfo_b, uint32_T rtu_registerInfo_g,
  real_T rtu_drive, real_T rtu_statusWord, B_faultmonitor1_gbyk_v4b_T *localB,
  DW_faultmonitor1_gbyk_v4b_T *localDW);
extern void gbyk_v4b_ControlGDCWhistleState_Init
  (DW_ControlGDCWhistleState_gbyk_v4b_T *localDW);
extern void gbyk_v4b_ControlGDCWhistleState(uint16_T rtu_StatusWord, uint32_T
  rtu_allOK, uint32_T rtu_motorOn, uint32_T rtu_ampStatus, uint32_T rtu_fault,
  uint32_T rtu_eStops, real_T rtu_EMCY, boolean_T rtu_masterEnabled, real_T
  rtu_requestEnable, real_T rtu_max_errors_to_fault,
  B_ControlGDCWhistleState_gbyk_v4b_T *localB,
  DW_ControlGDCWhistleState_gbyk_v4b_T *localDW);
extern void gbyk_v4b_FindRobottype(const int32_T rtu_intVals[20], const real_T
  rtu_epPNs[6], const real_T rtu_nhpPNs[6], B_FindRobottype_gbyk_v4b_T *localB);
extern void gbyk_v4b_AbsEncodermachine_Init(B_AbsEncodermachine_gbyk_v4b_T
  *localB, DW_AbsEncodermachine_gbyk_v4b_T *localDW);
extern void gbyk_v4b_AbsEncodermachine(const real_T rtu_setupValues[24], real_T
  rtu_setupValuesCount, const real_T rtu_pollValues[3], const real_T
  rtu_encoderValues[12], real_T rtu_encoderValuesCount, int32_T rtu_intStatus,
  const int32_T rtu_pollResponse[2], B_AbsEncodermachine_gbyk_v4b_T *localB,
  DW_AbsEncodermachine_gbyk_v4b_T *localDW);
extern void gbyk_v4b_setupvalues(B_setupvalues_gbyk_v4b_T *localB);
extern void gbyk_v4b_SDOreadmachine_Init(B_SDOreadmachine_gbyk_v4b_T *localB,
  DW_SDOreadmachine_gbyk_v4b_T *localDW);
extern void gbyk_v4b_SDOreadmachine(int32_T rtu_triggerReading, const real_T
  rtu_intReadAddrs[24], real_T rtu_intCount, int32_T rtu_intSDOResponse, const
  real_T rtu_floatReadAddrs[24], real_T rtu_floatCount, real_T
  rtu_floatSDOResponse, real_T rtu_status, B_SDOreadmachine_gbyk_v4b_T *localB,
  DW_SDOreadmachine_gbyk_v4b_T *localDW);
extern void gbyk_v4b_converter(uint32_T rtu_inVal, B_converter_gbyk_v4b_T
  *localB);
extern void gbyk_v4b_SDOreadmachine_p_Init(B_SDOreadmachine_gbyk_v4b_n_T *localB,
  DW_SDOreadmachine_gbyk_v4b_m_T *localDW);
extern void gbyk_v4b_SDOreadmachine_p(real_T rtu_triggerWriting, real_T
  rtu_readState, B_SDOreadmachine_gbyk_v4b_n_T *localB,
  DW_SDOreadmachine_gbyk_v4b_m_T *localDW);
extern void gbyk_v4b_values(real_T rtu_inVal, real_T rtu_inVal_g, real_T
  rtu_inVal_o, B_values_gbyk_v4b_T *localB);
extern void gbyk_v4b_SDOwritemachine_Init(B_SDOwritemachine_gbyk_v4b_T *localB,
  DW_SDOwritemachine_gbyk_v4b_T *localDW);
extern void gbyk_v4b_SDOwritemachine(real_T rtu_triggerReading, int32_T
  rtu_writeState, B_SDOwritemachine_gbyk_v4b_T *localB,
  DW_SDOwritemachine_gbyk_v4b_T *localDW);
extern void gbyk_v4b_convert(real_T rtu_u, real_T rtu_type, B_convert_gbyk_v4b_T
  *localB);
extern void gbyk_v4b_forceEnableDisable_Init(DW_forceEnableDisable_gbyk_v4b_T
  *localDW);
extern void gbyk_v4b_forceEnableDisable(real_T rtu_dexState, real_T
  rtu_task_state, const real_T rtu_forces[4], boolean_T rtu_allowEnableMotors,
  real_T rtu_motorFaults, real_T rtu_motorFaults_e, real_T
  rtu_fault_cycles_allowed, B_forceEnableDisable_gbyk_v4b_T *localB,
  DW_forceEnableDisable_gbyk_v4b_T *localDW);
extern void gbyk_v4b_size(B_size_gbyk_v4b_T *localB);
extern void gbyk_v4b_splitoutconstants1(const int32_T rtu_intVals[20], real_T
  rtu_forcePrimary, real_T rtu_robotType, B_splitoutconstants1_gbyk_v4b_T
  *localB);
extern void gbyk_v4b_ReadEMCY_Init(B_ReadEMCY_gbyk_v4b_T *localB,
  DW_ReadEMCY_gbyk_v4b_T *localDW);
extern void gbyk_v4b_ReadEMCY(real_T rtu_triggerReading, real_T rtu_driveID,
  const real_T rtu_countValues[2], const real_T rtu_emcyValues[2], real_T
  rtu_overwriteStatus, B_ReadEMCY_gbyk_v4b_T *localB, DW_ReadEMCY_gbyk_v4b_T
  *localDW);
extern void gbyk_v4b_decoderobot(real_T rtu_system_type, real_T rtu_robot_type,
  real_T rtu_robot_version, B_decoderobot_gbyk_v4b_T *localB);
extern void gbyk_v4b_split_primary(const real_T rtu_primary_data[6],
  B_split_primary_gbyk_v4b_T *localB);
extern void gbyk_v4b_EMCYMessagepump_Init(void);
extern void gbyk_v4b_EMCYMessagepump_Start(void);
extern void gbyk_v4b_EMCYMessagepump_Update(void);
extern void gbyk_v4b_EMCYMessagepump(void);
extern void gbyk_v4b_EMCYMessagepump_p_Init(void);
extern void gbyk_v4b_EMCYMessagepump_h_Start(void);
extern void gbyk_v4b_EMCYMessagepump_e_Update(void);
extern void gbyk_v4b_EMCYMessagepump_o(void);
extern void gbyk_v4b_ReadDrive1SDO(void);
extern void gbyk_v4b_SDOreading_Init(void);
extern void gbyk_v4b_SDOreading_Start(void);
extern void gbyk_v4b_SDOreading_Update(void);
extern void gbyk_v4b_SDOreading(void);
extern void gbyk_v4b_SDOwriting_Init(void);
extern void gbyk_v4b_SDOwriting_Start(void);
extern void gbyk_v4b_SDOwriting_Update(void);
extern void gbyk_v4b_SDOwriting(void);
extern void gbyk_v4b_ReadDrive1SDO_p(void);
extern void gbyk_v4b_A2M1PDOs_Start(void);
extern void gbyk_v4b_A2M1PDOs(void);
extern void gbyk_v4b_EMCYMessagepump_f_Init(void);
extern void gbyk_v4b_EMCYMessagepump_b_Start(void);
extern void gbyk_v4b_EMCYMessagepump_n_Update(void);
extern void gbyk_v4b_EMCYMessagepump_o1(void);
extern void gbyk_v4b_A2M2PDOs_Start(void);
extern void gbyk_v4b_A2M2PDOs(void);
extern void gbyk_v4b_EMCYMessagepump_b_Init(void);
extern void gbyk_v4b_EMCYMessagepump_j_Start(void);
extern void gbyk_v4b_EMCYMessagepump_o_Update(void);
extern void gbyk_v4b_EMCYMessagepump_i(void);
extern void gbyk_v4b_ReadDrive3SDO(void);
extern void gbyk_v4b_SDOreading_k_Init(void);
extern void gbyk_v4b_SDOreading_m_Start(void);
extern void gbyk_v4b_SDOreading_a_Update(void);
extern void gbyk_v4b_SDOreading_n(void);
extern void gbyk_v4b_SDOwriting_m_Init(void);
extern void gbyk_v4b_SDOwriting_e_Start(void);
extern void gbyk_v4b_SDOwriting_f_Update(void);
extern void gbyk_v4b_SDOwriting_f(void);
extern void gbyk_v4b_ReadDrive3SDO_g(void);
extern void gbyk_v4b_PollKINARM_Init(void);
extern void gbyk_v4b_PollKINARM_Start(void);
extern void gbyk_v4b_PollKINARM_Disable(void);
extern void gbyk_v4b_PollKINARM_Update(void);
extern void gbyk_v4b_PollKINARM(void);
extern void gbyk_v4b_EMCYMessagepump_Term(void);
extern void gbyk_v4b_EMCYMessagepump_j_Term(void);
extern void gbyk_v4b_ReadDrive1SDO_Term(void);
extern void gbyk_v4b_SDOreading_Term(void);
extern void gbyk_v4b_SDOwriting_Term(void);
extern void gbyk_v4b_ReadDrive1SDO_i_Term(void);
extern void gbyk_v4b_A2M1PDOs_Term(void);
extern void gbyk_v4b_EMCYMessagepump_l_Term(void);
extern void gbyk_v4b_A2M2PDOs_Term(void);
extern void gbyk_v4b_EMCYMessagepump_i_Term(void);
extern void gbyk_v4b_ReadDrive3SDO_Term(void);
extern void gbyk_v4b_SDOreading_h_Term(void);
extern void gbyk_v4b_SDOwriting_k_Term(void);
extern void gbyk_v4b_ReadDrive3SDO_a_Term(void);
extern void gbyk_v4b_PollKINARM_Term(void);

#endif                                 /* RTW_HEADER_gbyk_v4b_PollKINARM_h_ */
