/*
 * gbyk_v4b.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "gbyk_v4b".
 *
 * Model version              : 1.2667
 * Simulink Coder version : 8.8.1 (R2015aSP1) 04-Sep-2015
 * C source code generated on : Tue Sep 15 15:02:19 2020
 *
 * Target selection: slrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "rt_logging_mmi.h"
#include "gbyk_v4b_capi.h"
#include "gbyk_v4b.h"
#include "gbyk_v4b_private.h"

/* Named constants for Chart: '<Root>/Trial_Control' */
#define gbyk_v4b_IN_EndInstructPause   ((uint8_T)1U)
#define gbyk_v4b_IN_EndOfTrial         ((uint8_T)1U)
#define gbyk_v4b_IN_Ending             ((uint8_T)2U)
#define gbyk_v4b_IN_HitTargetB         ((uint8_T)2U)
#define gbyk_v4b_IN_HitTargetC         ((uint8_T)3U)
#define gbyk_v4b_IN_Initialize         ((uint8_T)3U)
#define gbyk_v4b_IN_InstructWaitState  ((uint8_T)4U)
#define gbyk_v4b_IN_Inter_Trial_State  ((uint8_T)5U)
#define gbyk_v4b_IN_MainTrial          ((uint8_T)6U)
#define gbyk_v4b_IN_MissTargetB        ((uint8_T)4U)
#define gbyk_v4b_IN_MissTargetC        ((uint8_T)5U)
#define gbyk_v4b_IN_NO_ACTIVE_CHILD_o  ((uint8_T)0U)
#define gbyk_v4b_IN_ReturnToStart1     ((uint8_T)7U)
#define gbyk_v4b_IN_RevealCorrectTgtC  ((uint8_T)6U)
#define gbyk_v4b_IN_SetupTgtB          ((uint8_T)7U)
#define gbyk_v4b_IN_ShowAllTargets     ((uint8_T)8U)
#define gbyk_v4b_IN_ShowInstructState  ((uint8_T)8U)
#define gbyk_v4b_IN_ShowReachTargets   ((uint8_T)9U)
#define gbyk_v4b_IN_ShowScoreState     ((uint8_T)9U)
#define gbyk_v4b_IN_ShowStartTarget    ((uint8_T)10U)
#define gbyk_v4b_IN_StayAtFirstTarget  ((uint8_T)11U)
#define gbyk_v4b_IN_TooSlow            ((uint8_T)12U)
#define gbyk_v4b_IN_TooSlowC           ((uint8_T)13U)
#define gbyk_v4b_IN_TriggerTargetB     ((uint8_T)14U)
#define gbyk_v4b_IN_TriggerTargetC     ((uint8_T)15U)
#define gbyk_v4b_RAND_MAX              (32767.0)
#define gbyk_v4b_event_e_ExitTrialNow  (1)
#define gbyk_v4b_event_e_clk_i         (0)
#define gbyk_v4b_event_e_cntl_btn      (2)

/* user code (top of source file) */
#include "stdlib.h"

/* Block signals (auto storage) */
B_gbyk_v4b_T gbyk_v4b_B;

/* Block states (auto storage) */
DW_gbyk_v4b_T gbyk_v4b_DW;

/* Previous zero-crossings (trigger) states */
PrevZCX_gbyk_v4b_T gbyk_v4b_PrevZCX;

/* Real-time model */
RT_MODEL_gbyk_v4b_T gbyk_v4b_M_;
RT_MODEL_gbyk_v4b_T *const gbyk_v4b_M = &gbyk_v4b_M_;

/* Forward declaration for local functions */
static uint32_T gbyk_v4b_colourshift(real_T RRRGGGBBB);

/* Forward declaration for local functions */
static uint32_T gbyk_v4b_colourshift_g(real_T RRRGGGBBB);

/* Forward declaration for local functions */
static void gbyk_v4b_nonzeros(const real_T s[499], real_T v_data[], int32_T
  *v_sizes);
static void gbyk_v4b_merge_sort(int32_T idx_data[], const real_T x_data[], const
  int32_T x_sizes);
static void gbyk_v4b_eml_sort_idx(const real_T x_data[], const int32_T x_sizes,
  int32_T idx_data[], int32_T *idx_sizes);
static void gbyk_v4b_count_nonfinites(const real_T b_data[], int32_T nb, int32_T
  *nMInf, int32_T *nFinite, int32_T *nPInf, int32_T *nNaN);
static real_T gbyk_v4b_sum(const boolean_T x_data[], const int32_T x_sizes);
static real_T gbyk_v4b_mean(const real_T x[3]);
static void gbyk_v4b_enter_atomic_ReturnToStart1(void);
static void gbyk_v4b_enter_atomic_ShowInstructState(void);
static void gbyk_v4b_enter_atomic_ShowStartTarget(void);
static void gbyk_v4b_enter_atomic_Inter_Trial_State(void);
static void gbyk_v4b_enter_atomic_TooSlow(void);
static void gbyk_v4b_MainTrial(void);
static void gbyk_v4b_chartstep_c1_gbyk_v4b(void);
static uint32_T gbyk_v4b_colourshift_h(real_T RRRGGGBBB);
static void rate_monotonic_scheduler(void);
int32_T div_s32_floor(int32_T numerator, int32_T denominator)
{
  int32_T quotient;
  uint32_T absNumerator;
  uint32_T absDenominator;
  uint32_T tempAbsQuotient;
  boolean_T quotientNeedsNegation;
  if (denominator == 0) {
    quotient = numerator >= 0 ? MAX_int32_T : MIN_int32_T;

    /* Divide by zero handler */
  } else {
    absNumerator = (uint32_T)(numerator >= 0 ? numerator : -numerator);
    absDenominator = (uint32_T)(denominator >= 0 ? denominator : -denominator);
    quotientNeedsNegation = ((numerator < 0) != (denominator < 0));
    tempAbsQuotient = absNumerator / absDenominator;
    if (quotientNeedsNegation) {
      absNumerator %= absDenominator;
      if (absNumerator > 0U) {
        tempAbsQuotient++;
      }
    }

    quotient = quotientNeedsNegation ? -(int32_T)tempAbsQuotient : (int32_T)
      tempAbsQuotient;
  }

  return quotient;
}

time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
{
  rtmSampleHitPtr[1] = rtmStepTask(gbyk_v4b_M, 1);
  rtmSampleHitPtr[2] = rtmStepTask(gbyk_v4b_M, 2);
  rtmSampleHitPtr[3] = rtmStepTask(gbyk_v4b_M, 3);
  rtmSampleHitPtr[4] = rtmStepTask(gbyk_v4b_M, 4);
  rtmSampleHitPtr[5] = rtmStepTask(gbyk_v4b_M, 5);
  UNUSED_PARAMETER(rtmNumSampTimes);
  UNUSED_PARAMETER(rtmTimingData);
  UNUSED_PARAMETER(rtmPerTaskSampleHits);
  return(-1);
}

/*
 *   This function updates active task flag for each subrate
 * and rate transition flags for tasks that exchange data.
 * The function assumes rate-monotonic multitasking scheduler.
 * The function must be called at model base rate so that
 * the generated code self-manages all its subrates and rate
 * transition flags.
 */
static void rate_monotonic_scheduler(void)
{
  /* To ensure a deterministic data transfer between two rates,
   * data is transferred at the priority of a fast task and the frequency
   * of the slow task.  The following flags indicate when the data transfer
   * happens.  That is, a rate interaction flag is set true when both rates
   * will run, and false otherwise.
   */

  /* tid 1 shares data with slower tid rates: 2, 3, 4 */
  if (gbyk_v4b_M->Timing.TaskCounters.TID[1] == 0) {
    gbyk_v4b_M->Timing.RateInteraction.TID1_2 =
      (gbyk_v4b_M->Timing.TaskCounters.TID[2] == 0);

    /* update PerTaskSampleHits matrix for non-inline sfcn */
    gbyk_v4b_M->Timing.perTaskSampleHits[8] =
      gbyk_v4b_M->Timing.RateInteraction.TID1_2;
    gbyk_v4b_M->Timing.RateInteraction.TID1_3 =
      (gbyk_v4b_M->Timing.TaskCounters.TID[3] == 0);

    /* update PerTaskSampleHits matrix for non-inline sfcn */
    gbyk_v4b_M->Timing.perTaskSampleHits[9] =
      gbyk_v4b_M->Timing.RateInteraction.TID1_3;
    gbyk_v4b_M->Timing.RateInteraction.TID1_4 =
      (gbyk_v4b_M->Timing.TaskCounters.TID[4] == 0);

    /* update PerTaskSampleHits matrix for non-inline sfcn */
    gbyk_v4b_M->Timing.perTaskSampleHits[10] =
      gbyk_v4b_M->Timing.RateInteraction.TID1_4;
  }

  /* tid 2 shares data with slower tid rate: 3 */
  if (gbyk_v4b_M->Timing.TaskCounters.TID[2] == 0) {
    gbyk_v4b_M->Timing.RateInteraction.TID2_3 =
      (gbyk_v4b_M->Timing.TaskCounters.TID[3] == 0);

    /* update PerTaskSampleHits matrix for non-inline sfcn */
    gbyk_v4b_M->Timing.perTaskSampleHits[15] =
      gbyk_v4b_M->Timing.RateInteraction.TID2_3;
  }

  /* Compute which subrates run during the next base time step.  Subrates
   * are an integer multiple of the base rate counter.  Therefore, the subtask
   * counter is reset when it reaches its limit (zero means run).
   */
  (gbyk_v4b_M->Timing.TaskCounters.TID[2])++;
  if ((gbyk_v4b_M->Timing.TaskCounters.TID[2]) > 1) {/* Sample time: [0.0005s, 0.0s] */
    gbyk_v4b_M->Timing.TaskCounters.TID[2] = 0;
  }

  (gbyk_v4b_M->Timing.TaskCounters.TID[3])++;
  if ((gbyk_v4b_M->Timing.TaskCounters.TID[3]) > 3) {/* Sample time: [0.001s, 0.0s] */
    gbyk_v4b_M->Timing.TaskCounters.TID[3] = 0;
  }

  (gbyk_v4b_M->Timing.TaskCounters.TID[4])++;
  if ((gbyk_v4b_M->Timing.TaskCounters.TID[4]) > 7) {/* Sample time: [0.002s, 0.0s] */
    gbyk_v4b_M->Timing.TaskCounters.TID[4] = 0;
  }

  (gbyk_v4b_M->Timing.TaskCounters.TID[5])++;
  if ((gbyk_v4b_M->Timing.TaskCounters.TID[5]) > 399) {/* Sample time: [0.1s, 0.0s] */
    gbyk_v4b_M->Timing.TaskCounters.TID[5] = 0;
  }
}

/*
 * Output and update for atomic system:
 *    '<S259>/MATLAB Function'
 *    '<S259>/MATLAB Function1'
 */
void gbyk_v4b_MATLABFunction(real_T rtu_orientation, real_T rtu_has_secondary,
  real_T rtu_isEP, B_MATLABFunction_gbyk_v4b_T *localB)
{
  int32_T isExo;

  /* MATLAB Function 'DataLogging/create_lab_info/Subsystem/MATLAB Function': '<S260>:1' */
  /* '<S260>:1:4' */
  isExo = 1;
  if (rtu_isEP != 0.0) {
    /* '<S260>:1:6' */
    isExo = 0;
  }

  /* '<S260>:1:9' */
  localB->has_high_res_encoders = rtu_has_secondary;

  /* '<S260>:1:11' */
  localB->is_right_arm = 0.0;
  if (((isExo != 0) && (rtu_orientation == 1.0)) || ((rtu_isEP != 0.0) &&
       (rtu_orientation == -1.0))) {
    /* '<S260>:1:12' */
    /* '<S260>:1:13' */
    localB->is_right_arm = 1.0;
  }

  localB->isExo = isExo;
}

/* Function for MATLAB Function: '<S262>/Embedded MATLAB Function' */
static uint32_T gbyk_v4b_colourshift(real_T RRRGGGBBB)
{
  uint32_T RRGGBBAA;
  uint32_T blue;
  uint32_T green;
  uint32_T q0;
  uint32_T qY;
  uint64_T tmp;
  int32_T tmp_0;
  real_T tmp_1;

  /*  The colourshift function converts an "RRRGGGBBB" colour value to RRGBB (as an uint32). */
  /* this is "no fill" */
  if (RRRGGGBBB == 1.0E+9) {
    /* '<S263>:1:203' */
    /* '<S263>:1:204' */
    RRGGBBAA = 16777216U;

    /* hex 0x1000000 */
  } else {
    /* '<S263>:1:208' */
    tmp_1 = rt_roundd_snf(RRRGGGBBB - floor(RRRGGGBBB / 1000.0) * 1000.0);
    if (tmp_1 < 4.294967296E+9) {
      if (tmp_1 >= 0.0) {
        blue = (uint32_T)tmp_1;
      } else {
        blue = 0U;
      }
    } else {
      blue = MAX_uint32_T;
    }

    /* '<S263>:1:209' */
    tmp_1 = rt_roundd_snf(RRRGGGBBB - (real_T)blue);
    if (tmp_1 < 4.294967296E+9) {
      if (tmp_1 >= 0.0) {
        green = (uint32_T)tmp_1;
      } else {
        green = 0U;
      }
    } else {
      green = MAX_uint32_T;
    }

    tmp_0 = (int32_T)rt_roundd_snf((real_T)(green - green / 1000000U * 1000000U)
      / 1000.0);
    green = (uint32_T)tmp_0;

    /* '<S263>:1:210' */
    /* '<S263>:1:212' */
    tmp = green * 1000ULL;
    if (tmp > 4294967295ULL) {
      tmp = 4294967295ULL;
    }

    tmp_1 = rt_roundd_snf(RRRGGGBBB - (real_T)(uint32_T)tmp);
    if (tmp_1 < 4.294967296E+9) {
      if (tmp_1 >= 0.0) {
        q0 = (uint32_T)tmp_1;
      } else {
        q0 = 0U;
      }
    } else {
      q0 = MAX_uint32_T;
    }

    qY = q0 - blue;
    if (qY > q0) {
      qY = 0U;
    }

    tmp_0 = (int32_T)rt_roundd_snf((real_T)qY / 1.0E+6);
    tmp = (uint64_T)(((uint32_T)tmp_0 << 16U) + (green << 8U)) + blue;
    if (tmp > 4294967295ULL) {
      tmp = 4294967295ULL;
    }

    RRGGBBAA = (uint32_T)tmp;
  }

  return RRGGBBAA;
}

/*
 * Output and update for atomic system:
 *    '<S262>/Embedded MATLAB Function'
 *    '<S21>/Embedded MATLAB Function'
 *    '<S24>/Embedded MATLAB Function'
 */
void gbyk_v4b_EmbeddedMATLABFunction(const real_T rtu_target[25], real_T
  rtu_state_in, real_T rtu_target_type, real_T rtu_opacity_in, real_T
  rtu_target_display, real_T rtu_x_index, real_T rtu_y_index, real_T
  rtu_num_states, const real_T rtu_stateindices[55],
  B_EmbeddedMATLABFunction_gbyk_v4b_T *localB)
{
  real_T opacity;
  real_T stroke_colour_col;
  real_T stroke_width_col;
  int32_T i;

  /* MATLAB Function 'Show_Target/Embedded MATLAB Function': '<S263>:1' */
  /*  VCODEs are length 70. All units in a VCODE should be SI, e.g. (m) and (rad). Elements in a VCODE are defined as follows: */
  /*  */
  /*  For all target types: */
  /*   1: target type */
  /*        1 - circle */
  /*        2 - ellipse */
  /*        3 - rectangle */
  /*        4 - line */
  /*        5 - triangle */
  /*        11 - circle with label */
  /*        12 - ellipse with label */
  /*        13 - rectangle with label */
  /*        14 - line with label */
  /*        15 - triangle with label */
  /*   2: target on/off status and target display (which display target will appear on) */
  /* 		0 - off */
  /* 		1 - on, appearing on both subject and operator displays */
  /*        2 - on, appearing on subject display only */
  /*        3 - on, appearing on operator display only */
  /*   3: x position (m) */
  /*   4: y position (m) */
  /*   5: fill colour (RRGGBB) or texture index */
  /*   6: stroke colour (RRGGBB) or texture index */
  /*   7: stroke width */
  /*   8: reserved for target background ID */
  /*   9: opacity */
  /*  */
  /*  For circles: */
  /*   10: radius (m) */
  /*  */
  /*  For ellipses: */
  /*   10: major radius (m) */
  /*   11: minor radius (m) */
  /*   12: orientation of major axis (rad) */
  /*  */
  /*  For rectangles: */
  /*   10: length (m) */
  /*   11: height (m) */
  /*   12: orientation (rad) (relative to x, y already shown) */
  /*  */
  /*  For lines: */
  /*   10: endpoint x-axis coordinate relative to start point (m) */
  /*   11: endpoint y-axis coordinate relative to start point (m) */
  /*  */
  /*  For triangles: */
  /*   10: length (m) */
  /*   11: height (m) */
  /*   12: offset of peak from midpoint of length (m) */
  /*   13: orientation (rad) */
  /*  */
  /*  For all labelled target types: */
  /*   14: reserved */
  /*   15-64: label characters (indexes in ISO 8859-1 character set) */
  /*   65: label colour (0xRRGGBB), opacity is set by the vcode's opacity (9). */
  /*   66: label height (m) */
  /*   67: reserved */
  /*   68: reserved */
  /*   69: reserved */
  /*   70: reserved */
  /*  NOTE: we assume that the STATE and/or OPACITY inputs are vectors.  */
  /*  If the length of the input STATE is not the same as the number of targets then make STATE a column vector of the same length as  */
  /*  the TARGET input, using the first STATE (i.e. all targets get the same state)  */
  /* '<S263>:1:70' */
  /*  If the length of the input OPACITY is not the same as the number of targets then make OPACITY a column vector of the same length as */
  /*  the TARGET input, using the first OPACITY (i.e. all targets get the same opacity)  */
  /* '<S263>:1:79' */
  /*  Clamping the opacity to [0, 100]. */
  /* '<S263>:1:86' */
  /* '<S263>:1:87' */
  if (rtu_opacity_in <= 100.0) {
    opacity = rtu_opacity_in;
  } else {
    opacity = 100.0;
  }

  if (!(opacity >= 0.0)) {
    opacity = 0.0;
  }

  /* '<S263>:1:89' */
  for (i = 0; i < 70; i++) {
    localB->VCODE[i] = 0.0;
  }

  /*  Set the target type. */
  /* '<S263>:1:92' */
  localB->VCODE[0] = rtu_target_type;

  /*  Set the target position. */
  /* '<S263>:1:95' */
  localB->VCODE[2] = rtu_target[(int32_T)rtu_x_index - 1] * 0.01;

  /*  x position (convert from (cm) in target table to (m)) */
  /* '<S263>:1:96' */
  localB->VCODE[3] = rtu_target[(int32_T)rtu_y_index - 1] * 0.01;

  /*  y position (convert from (cm) in target table to (m)) */
  /*  Set the target on/off state. If the state input is 0, the target is off. Users of the VCODE should respect this */
  /*  as an indication that the rest of the VCODE will be uninitialized. */
  if ((rtu_state_in <= 0.0) || (rtu_state_in > rtu_num_states)) {
    /* '<S263>:1:101' */
    /* '<S263>:1:102' */
    localB->VCODE[1] = 0.0;

    /*  target is off */
  } else {
    /* '<S263>:1:104' */
    localB->VCODE[1] = rtu_target_display;

    /*  Default is that target is on; target displays as specified by block mask */
  }

  /* '<S263>:1:107' */
  /* '<S263>:1:108' */
  stroke_colour_col = rtu_stateindices[(int32_T)rtu_state_in + 4];

  /* '<S263>:1:109' */
  stroke_width_col = rtu_stateindices[(int32_T)rtu_state_in + 9];

  /*  Set the fill colour. Fill colour currently comes from the GUI in RRRGGGBBB format. */
  if (rtu_stateindices[(int32_T)rtu_state_in - 1] == 0.0) {
    /* '<S263>:1:112' */
    /* '<S263>:1:113' */
    localB->VCODE[4] = -2.147483648E+9;
  } else if (rtu_target[(int32_T)rtu_stateindices[(int32_T)rtu_state_in - 1] - 1]
             < 0.0) {
    /* '<S263>:1:114' */
    /* '<S263>:1:115' */
    localB->VCODE[4] = rtu_target[(int32_T)rtu_stateindices[(int32_T)
      rtu_state_in - 1] - 1];
  } else {
    /* '<S263>:1:117' */
    localB->VCODE[4] = (real_T)gbyk_v4b_colourshift(rtu_target[(int32_T)
      rtu_stateindices[(int32_T)rtu_state_in - 1] - 1]);
  }

  /*  Set the stroke colour. Stroke colour currently comes from the GUI in RRRGGGBBB format. */
  if (stroke_colour_col == 0.0) {
    /* '<S263>:1:121' */
    /* '<S263>:1:122' */
    localB->VCODE[5] = -2.147483648E+9;
  } else if (rtu_target[(int32_T)stroke_colour_col - 1] < 0.0) {
    /* '<S263>:1:123' */
    /* '<S263>:1:124' */
    localB->VCODE[5] = rtu_target[(int32_T)stroke_colour_col - 1];
  } else {
    /* '<S263>:1:126' */
    localB->VCODE[5] = (real_T)gbyk_v4b_colourshift(rtu_target[(int32_T)
      stroke_colour_col - 1]);
  }

  /*  Set the stroke width. if target table index for stroke width is zero, then the stroke width is undefined */
  if (stroke_width_col == 0.0) {
    /* '<S263>:1:130' */
    /* '<S263>:1:131' */
    localB->VCODE[6] = 0.0;

    /*  if stroke width column is 0, then stroke width is 0 */
  } else if (stroke_width_col < 0.0) {
    /* '<S263>:1:132' */
    /* '<S263>:1:133' */
    localB->VCODE[6] = 0.001;

    /*  if stroke width column is -ve, then a 1mm default is chosen */
  } else {
    /* '<S263>:1:135' */
    localB->VCODE[6] = rtu_target[(int32_T)stroke_width_col - 1] * 0.01;

    /*  if stroke width column is +ve, convert width from (cm) in target table to (m) */
  }

  /*  Set the opacity value */
  /* '<S263>:1:139' */
  localB->VCODE[8] = opacity;

  /*  Set attributes specific to each target type. */
  if (rtu_target_type == 1.0) {
    /* '<S263>:1:142' */
    /*  Handle circle target: */
    /* '<S263>:1:145' */
    /* '<S263>:1:146' */
    localB->VCODE[9] = rtu_target[(int32_T)rtu_stateindices[(int32_T)
      rtu_state_in + 14] - 1] * 0.01;

    /*  radius (convert from (cm) in target table to (m)) */
  } else if ((rtu_target_type == 2.0) || (rtu_target_type == 3.0)) {
    /* '<S263>:1:148' */
    /*  Handle ellipse or rectangle target: */
    /* '<S263>:1:151' */
    /* '<S263>:1:152' */
    /* '<S263>:1:153' */
    /* '<S263>:1:155' */
    localB->VCODE[9] = rtu_target[(int32_T)rtu_stateindices[(int32_T)
      rtu_state_in + 14] - 1] * 0.01;

    /*  major radius (convert from (cm) in target table to (m)) */
    /* '<S263>:1:156' */
    localB->VCODE[10] = rtu_target[(int32_T)rtu_stateindices[(int32_T)
      rtu_state_in + 19] - 1] * 0.01;

    /*  minor radius (convert from (cm) in target table to (m)) */
    if (rtu_stateindices[(int32_T)rtu_state_in + 24] == 0.0) {
      /* '<S263>:1:157' */
      /* '<S263>:1:158' */
      localB->VCODE[11] = 0.0;

      /*  if orientation column is 0, set orientation to 0 rad */
    } else {
      /* '<S263>:1:160' */
      localB->VCODE[11] = (rtu_target[(int32_T)rtu_stateindices[(int32_T)
                           rtu_state_in + 24] - 1] - floor(rtu_target[(int32_T)
        rtu_stateindices[(int32_T)rtu_state_in + 24] - 1] / 360.0) * 360.0) *
        3.1415926535897931 / 180.0;

      /*  orientation (convert from (degrees) in target table to (rad)) */
    }
  } else if (rtu_target_type == 4.0) {
    /* '<S263>:1:163' */
    /*  Handle line target: */
    /* '<S263>:1:166' */
    /* '<S263>:1:167' */
    /* '<S263>:1:168' */
    localB->VCODE[9] = rtu_target[(int32_T)rtu_stateindices[(int32_T)
      rtu_state_in + 14] - 1] * 0.01;

    /*  line endpoint in x axis, relative to start (convert from (cm) in target table to (m)) */
    /* '<S263>:1:169' */
    localB->VCODE[10] = rtu_target[(int32_T)rtu_stateindices[(int32_T)
      rtu_state_in + 19] - 1] * 0.01;

    /*  line endpoint in y axis, relative to start (convert from (cm) in target table to (m)) */
  } else {
    if (rtu_target_type == 5.0) {
      /* '<S263>:1:171' */
      /*  Handle triangle target: */
      /* '<S263>:1:174' */
      /* '<S263>:1:175' */
      /* '<S263>:1:176' */
      /* '<S263>:1:177' */
      /* '<S263>:1:179' */
      localB->VCODE[9] = rtu_target[(int32_T)rtu_stateindices[(int32_T)
        rtu_state_in + 14] - 1] * 0.01;

      /*  length (convert from (cm) in target table to (m)) */
      /*  If the height column is set to 0 then the triangle is automatically made equilateral, with the base length used as length */
      /*  for all sides. If the height column is non-zero, separate values for height and peak offset are taken from the target table. */
      if (rtu_stateindices[(int32_T)rtu_state_in + 19] == 0.0) {
        /* '<S263>:1:183' */
        /* '<S263>:1:184' */
        localB->VCODE[10] = 0.8660254037844386 * localB->VCODE[9];

        /*  height for equilateral triangle */
        /* '<S263>:1:185' */
        localB->VCODE[11] = 0.0;

        /*  peak offset for equilateral triangle */
      } else {
        /* '<S263>:1:187' */
        localB->VCODE[10] = rtu_target[(int32_T)rtu_stateindices[(int32_T)
          rtu_state_in + 19] - 1] * 0.01;

        /*  height (convert from (cm) in target table to (m)) */
        /* '<S263>:1:188' */
        localB->VCODE[11] = rtu_target[(int32_T)rtu_stateindices[(int32_T)
          rtu_state_in + 24] - 1] * 0.01;

        /*  peak offset (convert from (cm) in target table to (m)) */
      }

      if (rtu_stateindices[(int32_T)rtu_state_in + 29] == 0.0) {
        /* '<S263>:1:191' */
        /* '<S263>:1:192' */
        localB->VCODE[12] = 0.0;

        /*  if orientation column is 0, set orientation to 0 rad */
      } else {
        /* '<S263>:1:194' */
        localB->VCODE[12] = (rtu_target[(int32_T)rtu_stateindices[(int32_T)
                             rtu_state_in + 29] - 1] - floor(rtu_target[(int32_T)
          rtu_stateindices[(int32_T)rtu_state_in + 29] - 1] / 360.0) * 360.0) *
          3.1415926535897931 / 180.0;

        /*  orientation (convert from (degrees) in target table to (rad)) */
      }
    }
  }
}

/*
 * Output and update for atomic system:
 *    '<S9>/Embedded MATLAB WhichHand'
 *    '<S10>/Embedded MATLAB WhichHand'
 *    '<S11>/Embedded MATLAB WhichHand'
 */
void gbyk_v4b_EmbeddedMATLABWhichHand(real_T rtu_use_dominant_hand, real_T
  rtu_dominant_hand, B_EmbeddedMATLABWhichHand_gbyk_v4b_T *localB)
{
  /* MATLAB Function 'KINARM_DistanceFromTarget/Embedded MATLAB WhichHand': '<S280>:1' */
  if (rtu_use_dominant_hand == 1.0) {
    /* '<S280>:1:3' */
    /* use the dominant hand */
    /* '<S280>:1:4' */
    localB->hand = rtu_dominant_hand;
  } else {
    /* '<S280>:1:6' */
    localB->hand = 3.0 - rtu_dominant_hand;

    /* use the non-dominant hand. i.e. if dominant_hand=2, hand=1 and vice-versa */
  }
}

/* Function for MATLAB Function: '<S22>/Embedded MATLAB Function' */
static uint32_T gbyk_v4b_colourshift_g(real_T RRRGGGBBB)
{
  uint32_T RRGGBBAA;
  uint32_T blue;
  uint32_T green;
  uint32_T q0;
  uint32_T qY;
  uint64_T tmp;
  int32_T tmp_0;
  real_T tmp_1;

  /*  The colourshift function converts an "RRRGGGBBB" colour value to RRGBB (as an uint32). */
  /* this is "no fill" */
  if (RRRGGGBBB == 1.0E+9) {
    /* '<S302>:1:232' */
    /* '<S302>:1:233' */
    RRGGBBAA = 16777216U;

    /* hex 0x1000000 */
  } else {
    /* '<S302>:1:237' */
    tmp_1 = rt_roundd_snf(RRRGGGBBB - floor(RRRGGGBBB / 1000.0) * 1000.0);
    if (tmp_1 < 4.294967296E+9) {
      if (tmp_1 >= 0.0) {
        blue = (uint32_T)tmp_1;
      } else {
        blue = 0U;
      }
    } else {
      blue = MAX_uint32_T;
    }

    /* '<S302>:1:238' */
    tmp_1 = rt_roundd_snf(RRRGGGBBB - (real_T)blue);
    if (tmp_1 < 4.294967296E+9) {
      if (tmp_1 >= 0.0) {
        green = (uint32_T)tmp_1;
      } else {
        green = 0U;
      }
    } else {
      green = MAX_uint32_T;
    }

    tmp_0 = (int32_T)rt_roundd_snf((real_T)(green - green / 1000000U * 1000000U)
      / 1000.0);
    green = (uint32_T)tmp_0;

    /* '<S302>:1:239' */
    /* '<S302>:1:241' */
    tmp = green * 1000ULL;
    if (tmp > 4294967295ULL) {
      tmp = 4294967295ULL;
    }

    tmp_1 = rt_roundd_snf(RRRGGGBBB - (real_T)(uint32_T)tmp);
    if (tmp_1 < 4.294967296E+9) {
      if (tmp_1 >= 0.0) {
        q0 = (uint32_T)tmp_1;
      } else {
        q0 = 0U;
      }
    } else {
      q0 = MAX_uint32_T;
    }

    qY = q0 - blue;
    if (qY > q0) {
      qY = 0U;
    }

    tmp_0 = (int32_T)rt_roundd_snf((real_T)qY / 1.0E+6);
    tmp = (uint64_T)(((uint32_T)tmp_0 << 16U) + (green << 8U)) + blue;
    if (tmp > 4294967295ULL) {
      tmp = 4294967295ULL;
    }

    RRGGBBAA = (uint32_T)tmp;
  }

  return RRGGBBAA;
}

/*
 * Output and update for atomic system:
 *    '<S22>/Embedded MATLAB Function'
 *    '<S23>/Embedded MATLAB Function'
 */
void gbyk_v4b_EmbeddedMATLABFunction_k(const real_T rtu_target[50], const real_T
  rtu_state_in[2], real_T rtu_target_type, real_T rtu_opacity_in, real_T
  rtu_target_display, real_T rtu_x_index, real_T rtu_y_index, real_T
  rtu_num_states, const real_T rtu_stateindices[55], const real_T
  rtu_target_labels[5000], B_EmbeddedMATLABFunction_gbyk_v4b_p_T *localB)
{
  real_T state[2];
  real_T opacity[2];
  int32_T label_index;
  int32_T jj;
  int32_T i;
  real_T x_idx_0;
  real_T x_idx_1;

  /* MATLAB Function 'Show_Target_With_Label/Embedded MATLAB Function': '<S302>:1' */
  /*  VCODEs are length 70. All units in a VCODE should be SI, e.g. (m) and (rad). Elements in a VCODE are defined as follows: */
  /*  */
  /*  For all target types: */
  /*   1: target type */
  /*        1 - circle */
  /*        2 - ellipse */
  /*        3 - rectangle */
  /*        4 - line */
  /*        5 - triangle */
  /*        11 - circle with label */
  /*        12 - ellipse with label */
  /*        13 - rectangle with label */
  /*        14 - line with label */
  /*        15 - triangle with label */
  /*   2: target on/off status and target display (which display target will appear on) */
  /* 		0 - off */
  /* 		1 - on, appearing on both subject and operator displays */
  /*        2 - on, appearing on subject display only */
  /*        3 - on, appearing on operator display only */
  /*   3: x position (m) */
  /*   4: y position (m) */
  /*   5: fill colour (RRGGBB) or texture index */
  /*   6: stroke colour (RRGGBB) or texture index */
  /*   7: stroke width */
  /*   8: reserved for target background ID */
  /*   9: opacity */
  /*  */
  /*  For circles: */
  /*   10: radius (m) */
  /*  */
  /*  For ellipses: */
  /*   10: major radius (m) */
  /*   11: minor radius (m) */
  /*   12: orientation of major axis (rad) */
  /*  */
  /*  For rectangles: */
  /*   10: length (m) */
  /*   11: height (m) */
  /*   12: orientation (rad) (relative to x, y already shown) */
  /*  */
  /*  For lines: */
  /*   10: endpoint x-axis coordinate relative to start point (m) */
  /*   11: endpoint y-axis coordinate relative to start point (m) */
  /*  */
  /*  For triangles: */
  /*   10: length (m) */
  /*   11: height (m) */
  /*   12: offset of peak from midpoint of length (m) */
  /*   13: orientation (rad) */
  /*  */
  /*  For all labelled target types: */
  /*   14: reserved */
  /*   15-64: label characters (indexes in ISO 8859-1 character set) */
  /*   65: label colour (0xRRGGBB), opacity is set by the vcode's opacity (9). */
  /*   66: label height (m) */
  /*   67: reserved */
  /*   68: reserved */
  /*   69: reserved */
  /*   70: reserved */
  /*  NOTE: we assume that the STATE and/or OPACITY inputs are vectors.  */
  /*  If the length of the input STATE is not the same as the number of targets then make STATE a column vector of the same length as  */
  /*  the TARGET input, using the first STATE (i.e. all targets get the same state)  */
  /* '<S302>:1:70' */
  state[0] = rtu_state_in[0];
  state[1] = rtu_state_in[1];

  /*  If the length of the input OPACITY is not the same as the number of targets then make OPACITY a column vector of the same length as */
  /*  the TARGET input, using the first OPACITY (i.e. all targets get the same opacity)  */
  /* '<S302>:1:81' */
  /*  Clamping the opacity to [0, 100]. */
  /* '<S302>:1:86' */
  x_idx_0 = rtu_opacity_in;
  x_idx_1 = rtu_opacity_in;
  if (!(x_idx_0 <= 100.0)) {
    x_idx_0 = 100.0;
  }

  opacity[0] = x_idx_0;
  if (!(x_idx_1 <= 100.0)) {
    x_idx_1 = 100.0;
  }

  opacity[1] = x_idx_1;

  /* '<S302>:1:87' */
  x_idx_0 = opacity[0];
  x_idx_1 = opacity[1];
  if (!(x_idx_0 >= 0.0)) {
    x_idx_0 = 0.0;
  }

  opacity[0] = x_idx_0;
  if (!(x_idx_1 >= 0.0)) {
    x_idx_1 = 0.0;
  }

  opacity[1] = x_idx_1;

  /* '<S302>:1:89' */
  for (i = 0; i < 140; i++) {
    localB->VCODE[i] = 0.0;
  }

  /*  Set the target type. Targets with labels have type codes 10 greater than their unlabelled counterparts. */
  /* '<S302>:1:92' */
  localB->VCODE[0] = rtu_target_type + 10.0;
  localB->VCODE[1] = rtu_target_type + 10.0;

  /*  Set the target position. */
  /* '<S302>:1:95' */
  i = (int32_T)rtu_x_index;
  localB->VCODE[4] = rtu_target[(i - 1) << 1] * 0.01;
  localB->VCODE[5] = rtu_target[((i - 1) << 1) + 1] * 0.01;

  /*  x position (convert from (cm) in target table to (m)) */
  /* '<S302>:1:96' */
  i = (int32_T)rtu_y_index;
  localB->VCODE[6] = rtu_target[(i - 1) << 1] * 0.01;
  localB->VCODE[7] = rtu_target[((i - 1) << 1) + 1] * 0.01;

  /*  y position (convert from (cm) in target table to (m)) */
  /* '<S302>:1:98' */
  for (i = 0; i < 2; i++) {
    /* '<S302>:1:98' */
    /*  Set the target on/off state. If the state input is 0, the target is off. Users of the VCODE should respect this */
    /*  as an indication that the rest of the VCODE will be uninitialized. */
    if ((state[i] <= 0.0) || (state[i] > rtu_num_states)) {
      /* '<S302>:1:101' */
      /* '<S302>:1:102' */
      localB->VCODE[2 + i] = 0.0;

      /*  target is off */
    } else {
      /* '<S302>:1:104' */
      localB->VCODE[2 + i] = rtu_target_display;

      /*  Default is that target is on; target displays as specified by block mask */
    }

    /* '<S302>:1:107' */
    /* '<S302>:1:108' */
    /* '<S302>:1:109' */
    /*  Set the fill colour. Fill colour currently comes from the GUI in RRRGGGBBB format. */
    if (rtu_stateindices[(int32_T)state[i] - 1] == 0.0) {
      /* '<S302>:1:112' */
      /* '<S302>:1:113' */
      localB->VCODE[8 + i] = -2.147483648E+9;
    } else if (rtu_target[(((int32_T)rtu_stateindices[(int32_T)state[i] - 1] - 1)
                << 1) + i] < 0.0) {
      /* '<S302>:1:114' */
      /* '<S302>:1:115' */
      localB->VCODE[8 + i] = rtu_target[(((int32_T)rtu_stateindices[(int32_T)
        state[i] - 1] - 1) << 1) + i];
    } else {
      /* '<S302>:1:117' */
      localB->VCODE[8 + i] = (real_T)gbyk_v4b_colourshift_g(rtu_target
        [(((int32_T)rtu_stateindices[(int32_T)state[i] - 1] - 1) << 1) + i]);
    }

    /*  Set the stroke colour. Stroke colour currently comes from the GUI in RRRGGGBBB format. */
    if (rtu_stateindices[(int32_T)state[i] + 4] == 0.0) {
      /* '<S302>:1:121' */
      /* '<S302>:1:122' */
      localB->VCODE[10 + i] = -2.147483648E+9;
    } else if (rtu_target[(((int32_T)rtu_stateindices[(int32_T)state[i] + 4] - 1)
                << 1) + i] < 0.0) {
      /* '<S302>:1:123' */
      /* '<S302>:1:124' */
      localB->VCODE[10 + i] = rtu_target[(((int32_T)rtu_stateindices[(int32_T)
        state[i] + 4] - 1) << 1) + i];
    } else {
      /* '<S302>:1:126' */
      localB->VCODE[10 + i] = (real_T)gbyk_v4b_colourshift_g(rtu_target
        [(((int32_T)rtu_stateindices[(int32_T)state[i] + 4] - 1) << 1) + i]);
    }

    /*  Set the stroke width. if target table index for stroke width is zero, then the stroke width is undefined */
    if (rtu_stateindices[(int32_T)state[i] + 9] == 0.0) {
      /* '<S302>:1:130' */
      /* '<S302>:1:131' */
      localB->VCODE[12 + i] = 0.0;

      /*  if stroke width column is 0, then stroke width is 0 */
    } else if (rtu_stateindices[(int32_T)state[i] + 9] < 0.0) {
      /* '<S302>:1:132' */
      /* '<S302>:1:133' */
      localB->VCODE[12 + i] = 0.001;

      /*  if stroke width column is -ve, then a 1mm default is chosen */
    } else {
      /* '<S302>:1:135' */
      localB->VCODE[12 + i] = rtu_target[(((int32_T)rtu_stateindices[(int32_T)
        state[i] + 9] - 1) << 1) + i] * 0.01;

      /*  if stroke width column is +ve, convert width from (cm) in target table to (m) */
    }

    /*  Set the opacity value */
    /* '<S302>:1:139' */
    localB->VCODE[16 + i] = opacity[i];

    /*  Set attributes specific to each target type. In the process, note the first state vector column used for label information. */
    /* '<S302>:1:142' */
    label_index = 1;

    /*  Set attributes specific to each target type. */
    if (rtu_target_type == 1.0) {
      /* '<S302>:1:145' */
      /*  Handle circle target: */
      /* '<S302>:1:148' */
      /* '<S302>:1:149' */
      localB->VCODE[18 + i] = rtu_target[(((int32_T)rtu_stateindices[(int32_T)
        state[i] + 14] - 1) << 1) + i] * 0.01;

      /*  radius (convert from (cm) in target table to (m)) */
      /* '<S302>:1:150' */
      label_index = 5;
    } else if ((rtu_target_type == 2.0) || (rtu_target_type == 3.0)) {
      /* '<S302>:1:152' */
      /*  Handle ellipse or rectangle target: */
      /* '<S302>:1:155' */
      /* '<S302>:1:156' */
      /* '<S302>:1:157' */
      /* '<S302>:1:159' */
      localB->VCODE[18 + i] = rtu_target[(((int32_T)rtu_stateindices[(int32_T)
        state[i] + 14] - 1) << 1) + i] * 0.01;

      /*  major radius (convert from (cm) in target table to (m)) */
      /* '<S302>:1:160' */
      localB->VCODE[20 + i] = rtu_target[(((int32_T)rtu_stateindices[(int32_T)
        state[i] + 19] - 1) << 1) + i] * 0.01;

      /*  minor radius (convert from (cm) in target table to (m)) */
      if (rtu_stateindices[(int32_T)state[i] + 24] == 0.0) {
        /* '<S302>:1:161' */
        /* '<S302>:1:162' */
        localB->VCODE[22 + i] = 0.0;

        /*  if orientation column is 0, set orientation to 0 rad */
      } else {
        /* '<S302>:1:164' */
        localB->VCODE[22 + i] = (rtu_target[(((int32_T)rtu_stateindices[(int32_T)
          state[i] + 24] - 1) << 1) + i] - floor(rtu_target[(((int32_T)
          rtu_stateindices[(int32_T)state[i] + 24] - 1) << 1) + i] / 360.0) *
          360.0) * 3.1415926535897931 / 180.0;

        /*  orientation (convert from (degrees) in target table to (rad)) */
      }

      /* '<S302>:1:166' */
      label_index = 7;
    } else if (rtu_target_type == 4.0) {
      /* '<S302>:1:168' */
      /*  Handle line target: */
      /* '<S302>:1:171' */
      /* '<S302>:1:172' */
      /* '<S302>:1:173' */
      localB->VCODE[18 + i] = rtu_target[(((int32_T)rtu_stateindices[(int32_T)
        state[i] + 14] - 1) << 1) + i] * 0.01;

      /*  line endpoint in x axis, relative to start (convert from (cm) in target table to (m)) */
      /* '<S302>:1:174' */
      localB->VCODE[20 + i] = rtu_target[(((int32_T)rtu_stateindices[(int32_T)
        state[i] + 19] - 1) << 1) + i] * 0.01;

      /*  line endpoint in y axis, relative to start (convert from (cm) in target table to (m)) */
      /* '<S302>:1:175' */
      label_index = 6;
    } else {
      if (rtu_target_type == 5.0) {
        /* '<S302>:1:177' */
        /*  Handle triangle target: */
        /* '<S302>:1:180' */
        /* '<S302>:1:181' */
        /* '<S302>:1:182' */
        /* '<S302>:1:183' */
        /* '<S302>:1:185' */
        localB->VCODE[18 + i] = rtu_target[(((int32_T)rtu_stateindices[(int32_T)
          state[i] + 14] - 1) << 1) + i] * 0.01;

        /*  length (convert from (cm) in target table to (m)) */
        /*  If the height column is set to 0 then the triangle is automatically made equilateral, with the base length used as length */
        /*  for all sides. If the height column is non-zero, separate values for height and peak offset are taken from the target table. */
        if (rtu_stateindices[(int32_T)state[i] + 19] == 0.0) {
          /* '<S302>:1:189' */
          /* '<S302>:1:190' */
          localB->VCODE[20 + i] = localB->VCODE[18 + i] * 0.8660254037844386;

          /*  height for equilateral triangle */
          /* '<S302>:1:191' */
          localB->VCODE[22 + i] = 0.0;

          /*  peak offset for equilateral triangle */
        } else {
          /* '<S302>:1:193' */
          localB->VCODE[20 + i] = rtu_target[(((int32_T)rtu_stateindices
            [(int32_T)state[i] + 19] - 1) << 1) + i] * 0.01;

          /*  height (convert from (cm) in target table to (m)) */
          /* '<S302>:1:194' */
          localB->VCODE[22 + i] = rtu_target[(((int32_T)rtu_stateindices
            [(int32_T)state[i] + 24] - 1) << 1) + i] * 0.01;

          /*  peak offset (convert from (cm) in target table to (m)) */
        }

        if (rtu_stateindices[(int32_T)state[i] + 29] == 0.0) {
          /* '<S302>:1:197' */
          /* '<S302>:1:198' */
          localB->VCODE[24 + i] = 0.0;

          /*  if orientation column is 0, set orientation to 0 rad */
        } else {
          /* '<S302>:1:200' */
          localB->VCODE[24 + i] = (rtu_target[(((int32_T)rtu_stateindices
            [(int32_T)state[i] + 29] - 1) << 1) + i] - floor(rtu_target
            [(((int32_T)rtu_stateindices[(int32_T)state[i] + 29] - 1) << 1) + i]
            / 360.0) * 360.0) * 3.1415926535897931 / 180.0;

          /*  orientation (convert from (degrees) in target table to (rad)) */
        }

        /* '<S302>:1:202' */
        label_index = 8;
      }
    }

    /*  Copy the label characters to the VCODE. */
    /* '<S302>:1:207' */
    for (jj = 0; jj < 50; jj++) {
      /* '<S302>:1:207' */
      /* '<S302>:1:208' */
      localB->VCODE[i + ((14 + jj) << 1)] = rtu_target_labels[((int32_T)
        rtu_target[(((int32_T)rtu_stateindices[((label_index - 1) * 5 + (int32_T)
        state[i]) - 1] - 1) << 1) + i] + 100 * jj) - 1];

      /* '<S302>:1:207' */
    }

    /*  Set the label colour. Like other colours, label colour comes from the GUI in RRRGGGBBB format and is converted to a 32-bit */
    /*  0xRRGGBB value here. If the target column table index for the colour is 0, the label is transparent. */
    if (rtu_stateindices[(5 * label_index + (int32_T)state[i]) - 1] == 0.0) {
      /* '<S302>:1:213' */
      /* '<S302>:1:214' */
      localB->VCODE[128 + i] = -2.147483648E+9;
    } else if (rtu_target[(((int32_T)rtu_stateindices[(5 * label_index +
                  (int32_T)state[i]) - 1] - 1) << 1) + i] < 0.0) {
      /* '<S302>:1:215' */
      /* '<S302>:1:216' */
      localB->VCODE[128 + i] = rtu_target[(((int32_T)rtu_stateindices[(5 *
        label_index + (int32_T)state[i]) - 1] - 1) << 1) + i];
    } else {
      /* '<S302>:1:218' */
      localB->VCODE[128 + i] = (real_T)gbyk_v4b_colourshift_g(rtu_target
        [(((int32_T)rtu_stateindices[(5 * label_index + (int32_T)state[i]) - 1]
           - 1) << 1) + i]);
    }

    /*  Set the label height. Label height is converted from (cm) in the target table to (m). */
    /* '<S302>:1:222' */
    localB->VCODE[130 + i] = rtu_target[(((int32_T)rtu_stateindices
      [((label_index + 1) * 5 + (int32_T)state[i]) - 1] - 1) << 1) + i] * 0.01;

    /* '<S302>:1:98' */
  }
}

/* Function for MATLAB Function: '<Root>/MATLAB Function' */
static void gbyk_v4b_nonzeros(const real_T s[499], real_T v_data[], int32_T
  *v_sizes)
{
  int32_T i;
  int32_T b_k;
  i = 0;
  for (b_k = 0; b_k < 499; b_k++) {
    if (s[b_k] != 0.0) {
      i++;
    }
  }

  *v_sizes = i;
  i = -1;
  for (b_k = 0; b_k < 499; b_k++) {
    if (s[b_k] != 0.0) {
      i++;
      v_data[i] = s[b_k];
    }
  }
}

/* Function for MATLAB Function: '<Root>/MATLAB Function' */
static void gbyk_v4b_merge_sort(int32_T idx_data[], const real_T x_data[], const
  int32_T x_sizes)
{
  int32_T n;
  int32_T k;
  int32_T i;
  int32_T i2;
  int32_T j;
  int32_T pEnd;
  int32_T p;
  int32_T q;
  int32_T qEnd;
  int32_T kEnd;
  boolean_T b_p;
  int32_T iwork_data[499];
  n = x_sizes + 1;
  for (pEnd = 1; pEnd <= n - 2; pEnd += 2) {
    b_p = ((x_data[pEnd - 1] <= x_data[pEnd]) || rtIsNaN(x_data[pEnd]));
    if (b_p) {
      idx_data[pEnd - 1] = pEnd;
      idx_data[pEnd] = pEnd + 1;
    } else {
      idx_data[pEnd - 1] = pEnd + 1;
      idx_data[pEnd] = pEnd;
    }
  }

  if ((x_sizes & 1) != 0) {
    idx_data[x_sizes - 1] = x_sizes;
  }

  i = 2;
  while (i < n - 1) {
    i2 = i << 1;
    j = 1;
    pEnd = 1 + i;
    while (pEnd < n) {
      p = j;
      q = pEnd - 1;
      qEnd = j + i2;
      if (qEnd > n) {
        qEnd = n;
      }

      k = 0;
      kEnd = qEnd - j;
      while (k + 1 <= kEnd) {
        b_p = ((x_data[idx_data[p - 1] - 1] <= x_data[idx_data[q] - 1]) ||
               rtIsNaN(x_data[idx_data[q] - 1]));
        if (b_p) {
          iwork_data[k] = idx_data[p - 1];
          p++;
          if (p == pEnd) {
            while (q + 1 < qEnd) {
              k++;
              iwork_data[k] = idx_data[q];
              q++;
            }
          }
        } else {
          iwork_data[k] = idx_data[q];
          q++;
          if (q + 1 == qEnd) {
            while (p < pEnd) {
              k++;
              iwork_data[k] = idx_data[p - 1];
              p++;
            }
          }
        }

        k++;
      }

      for (pEnd = 0; pEnd + 1 <= kEnd; pEnd++) {
        idx_data[(j + pEnd) - 1] = iwork_data[pEnd];
      }

      j = qEnd;
      pEnd = qEnd + i;
    }

    i = i2;
  }
}

/* Function for MATLAB Function: '<Root>/MATLAB Function' */
static void gbyk_v4b_eml_sort_idx(const real_T x_data[], const int32_T x_sizes,
  int32_T idx_data[], int32_T *idx_sizes)
{
  int32_T i;
  int32_T loop_ub;
  int16_T b_x_idx_0;
  b_x_idx_0 = (int16_T)x_sizes;
  *idx_sizes = b_x_idx_0;
  loop_ub = b_x_idx_0;
  for (i = 0; i < loop_ub; i++) {
    idx_data[i] = 0;
  }

  if (x_sizes != 0) {
    gbyk_v4b_merge_sort(idx_data, x_data, x_sizes);
  }
}

/* Function for MATLAB Function: '<Root>/MATLAB Function' */
static void gbyk_v4b_count_nonfinites(const real_T b_data[], int32_T nb, int32_T
  *nMInf, int32_T *nFinite, int32_T *nPInf, int32_T *nNaN)
{
  int32_T k;
  k = 0;
  while ((k + 1 <= nb) && rtIsInf(b_data[k]) && (b_data[k] < 0.0)) {
    k++;
  }

  *nMInf = k;
  k = nb;
  while ((k >= 1) && rtIsNaN(b_data[k - 1])) {
    k--;
  }

  *nNaN = nb - k;
  while ((k >= 1) && rtIsInf(b_data[k - 1]) && (b_data[k - 1] > 0.0)) {
    k--;
  }

  *nPInf = (nb - k) - *nNaN;
  *nFinite = k - *nMInf;
}

/* Function for MATLAB Function: '<Root>/MATLAB Function' */
static real_T gbyk_v4b_sum(const boolean_T x_data[], const int32_T x_sizes)
{
  real_T y;
  int32_T k;
  if (x_sizes == 0) {
    y = 0.0;
  } else {
    y = x_data[0];
    for (k = 2; k <= x_sizes; k++) {
      y += (real_T)x_data[k - 1];
    }
  }

  return y;
}

/* Function for MATLAB Function: '<Root>/MATLAB Function' */
static real_T gbyk_v4b_mean(const real_T x[3])
{
  real_T b_y;
  b_y = x[0];
  b_y += x[1];
  b_y += x[2];
  return b_y / 3.0;
}

/* Function for Chart: '<Root>/Trial_Control' */
static void gbyk_v4b_enter_atomic_ReturnToStart1(void)
{
  /* Entry 'ReturnToStart1': '<S25>:83' */
  gbyk_v4b_B.targetA_state = 1.0;
  gbyk_v4b_B.targetB_state[0] = 0.0;
  gbyk_v4b_B.targetB_state[1] = 0.0;
  gbyk_v4b_B.targetC_state[0] = 0.0;
  gbyk_v4b_B.targetC_state[1] = 0.0;
  gbyk_v4b_B.boxState = 0.0;
  gbyk_v4b_B.feedback_text = 0;
  gbyk_v4b_B.doreward = 0.0;
  gbyk_v4b_B.repeat_trial_flag = 0.0;
  gbyk_v4b_B.logging_enable[0] = 1.0;
  gbyk_v4b_B.logging_enable[1] = 1.0;
  gbyk_v4b_DW.setup_trial_flag = false;
}

/* Function for Chart: '<Root>/Trial_Control' */
static void gbyk_v4b_enter_atomic_ShowInstructState(void)
{
  /* Entry 'ShowInstructState': '<S25>:73' */
  gbyk_v4b_B.event_code = (uint16_T)E_SHOW_INSTRUCT;
  gbyk_v4b_B.targetA_state = 0.0;
  gbyk_v4b_B.targetB_state[0] = 0.0;
  gbyk_v4b_B.targetB_state[1] = 0.0;
  gbyk_v4b_B.targetC_state[0] = 0.0;
  gbyk_v4b_B.targetC_state[1] = 0.0;
  gbyk_v4b_B.boxState = 0.0;
  gbyk_v4b_B.doreward = 0.0;
  gbyk_v4b_B.instruct_num = gbyk_v4b_B.TPSelector[8];
  gbyk_v4b_DW.tickCount = gbyk_v4b_B.TPSelector[6];
  gbyk_v4b_B.logging_enable[0] = 0.0;
  gbyk_v4b_B.logging_enable[1] = 0.0;
}

/* Function for Chart: '<Root>/Trial_Control' */
static void gbyk_v4b_enter_atomic_ShowStartTarget(void)
{
  /* Entry 'ShowStartTarget': '<S25>:6' */
  /*  Turn on first target, enable data logging, and wait for a specified time or until the hand is in the target. */
  gbyk_v4b_B.targetA_row = gbyk_v4b_B.TPSelector[0];
  gbyk_v4b_B.targetA_state = 1.0;
  gbyk_v4b_B.logging_enable[0] = 1.0;
  gbyk_v4b_B.logging_enable[1] = 1.0;
  gbyk_v4b_B.VectorConcatenate1[1] = false;
  gbyk_v4b_B.VectorConcatenate1[0] = false;
  gbyk_v4b_B.VectorConcatenate1[2] = false;
  gbyk_v4b_B.VectorConcatenate1[3] = false;
  gbyk_v4b_B.targetB_state[0] = 0.0;
  gbyk_v4b_B.targetB_state[1] = 0.0;
  gbyk_v4b_B.targetC_state[0] = 0.0;
  gbyk_v4b_B.targetC_state[1] = 0.0;
  gbyk_v4b_B.boxState = 0.0;
  gbyk_v4b_B.tone = 0.0;
  gbyk_v4b_B.reward = 0.0;
}

/* Function for Chart: '<Root>/Trial_Control' */
static void gbyk_v4b_enter_atomic_Inter_Trial_State(void)
{
  /* Entry 'Inter_Trial_State': '<S25>:5' */
  /*  Turn off both targets, turn off data logging, reset the
     event code, and send the e_Trial_End Stateflow event. */
  gbyk_v4b_B.event_code = 0U;
  gbyk_v4b_B.targetA_state = 1.0;
  gbyk_v4b_B.targetB_state[0] = 0.0;
  gbyk_v4b_B.targetB_state[1] = 0.0;
  gbyk_v4b_B.targetC_state[0] = 0.0;
  gbyk_v4b_B.targetC_state[1] = 0.0;
  gbyk_v4b_B.boxState = 0.0;
  gbyk_v4b_B.offeredRewards[0] = 0.0;
  gbyk_v4b_B.offeredRewards[1] = 0.0;
  gbyk_v4b_B.feedback_text = 0;
  gbyk_v4b_B.doreward = 0.0;
  gbyk_v4b_DW.setup_trial_flag = false;

  /* Event: '<S25>:44' */
  gbyk_v4b_DW.e_Trial_EndEventCounter++;
}

/* Function for Chart: '<Root>/Trial_Control' */
static void gbyk_v4b_enter_atomic_TooSlow(void)
{
  /* Entry 'TooSlow': '<S25>:63' */
  /*  Log a bad trial */
  gbyk_v4b_B.event_code = (uint16_T)E_TOO_SLOW;
  gbyk_v4b_B.targetB_state[0] = 0.0;
  gbyk_v4b_B.targetB_state[1] = 0.0;
  gbyk_v4b_B.targetC_state[0] = 0.0;
  gbyk_v4b_B.targetC_state[1] = 0.0;
  gbyk_v4b_B.boxState = 0.0;
  gbyk_v4b_B.repeat_trial_flag = 1.0;
  gbyk_v4b_B.reward = 0.0;
  gbyk_v4b_B.doreward = 0.0;
  gbyk_v4b_B.feedback_text = -1;
  gbyk_v4b_B.tone = 2.0;
  gbyk_v4b_DW.tickCount = 500.0;
}

/* Function for Chart: '<Root>/Trial_Control' */
static void gbyk_v4b_MainTrial(void)
{
  /* During 'MainTrial': '<S25>:8' */
  if (gbyk_v4b_DW.sfEvent == gbyk_v4b_event_e_ExitTrialNow) {
    /* Transition: '<S25>:17' */
    /* Exit Internal 'MainTrial': '<S25>:8' */
    gbyk_v4b_DW.is_MainTrial = gbyk_v4b_IN_NO_ACTIVE_CHILD_o;
    gbyk_v4b_DW.tickCount = 1.0;
    gbyk_v4b_DW.is_c1_gbyk_v4b = gbyk_v4b_IN_Inter_Trial_State;
    gbyk_v4b_DW.temporalCounter_i1 = 0U;
    gbyk_v4b_enter_atomic_Inter_Trial_State();
  } else {
    switch (gbyk_v4b_DW.is_MainTrial) {
     case gbyk_v4b_IN_EndOfTrial:
      /* During 'EndOfTrial': '<S25>:3' */
      if ((gbyk_v4b_DW.sfEvent == gbyk_v4b_event_e_clk_i) &&
          (gbyk_v4b_DW.temporalCounter_i1 >= (uint32_T)gbyk_v4b_DW.tickCount)) {
        /* Transition: '<S25>:12' */
        gbyk_v4b_DW.is_MainTrial = gbyk_v4b_IN_NO_ACTIVE_CHILD_o;
        gbyk_v4b_DW.is_c1_gbyk_v4b = gbyk_v4b_IN_Inter_Trial_State;
        gbyk_v4b_DW.temporalCounter_i1 = 0U;
        gbyk_v4b_enter_atomic_Inter_Trial_State();
      }
      break;

     case gbyk_v4b_IN_HitTargetB:
      /* During 'HitTargetB': '<S25>:2' */
      if ((gbyk_v4b_DW.sfEvent == gbyk_v4b_event_e_clk_i) &&
          (gbyk_v4b_DW.temporalCounter_i1 >= (uint32_T)gbyk_v4b_DW.tickCount)) {
        /* Transition: '<S25>:15' */
        gbyk_v4b_DW.is_MainTrial = gbyk_v4b_IN_EndOfTrial;
        gbyk_v4b_DW.temporalCounter_i1 = 0U;

        /* Entry 'EndOfTrial': '<S25>:3' */
        /*  Set the post-trial delay. */
        gbyk_v4b_DW.tickCount = gbyk_v4b_B.TPSelector[7];
        gbyk_v4b_DW.boxtrig = 0.0;
      }
      break;

     case gbyk_v4b_IN_HitTargetC:
      /* During 'HitTargetC': '<S25>:171' */
      /* Transition: '<S25>:178' */
      gbyk_v4b_DW.is_MainTrial = gbyk_v4b_IN_EndOfTrial;
      gbyk_v4b_DW.temporalCounter_i1 = 0U;

      /* Entry 'EndOfTrial': '<S25>:3' */
      /*  Set the post-trial delay. */
      gbyk_v4b_DW.tickCount = gbyk_v4b_B.TPSelector[7];
      gbyk_v4b_DW.boxtrig = 0.0;
      break;

     case gbyk_v4b_IN_MissTargetB:
      /* During 'MissTargetB': '<S25>:57' */
      if ((gbyk_v4b_DW.sfEvent == gbyk_v4b_event_e_clk_i) &&
          (gbyk_v4b_DW.temporalCounter_i1 >= (uint32_T)gbyk_v4b_DW.tickCount)) {
        /* Transition: '<S25>:59' */
        gbyk_v4b_DW.is_MainTrial = gbyk_v4b_IN_EndOfTrial;
        gbyk_v4b_DW.temporalCounter_i1 = 0U;

        /* Entry 'EndOfTrial': '<S25>:3' */
        /*  Set the post-trial delay. */
        gbyk_v4b_DW.tickCount = gbyk_v4b_B.TPSelector[7];
        gbyk_v4b_DW.boxtrig = 0.0;
      }
      break;

     case gbyk_v4b_IN_MissTargetC:
      /* During 'MissTargetC': '<S25>:172' */
      /* Transition: '<S25>:177' */
      gbyk_v4b_DW.is_MainTrial = gbyk_v4b_IN_EndOfTrial;
      gbyk_v4b_DW.temporalCounter_i1 = 0U;

      /* Entry 'EndOfTrial': '<S25>:3' */
      /*  Set the post-trial delay. */
      gbyk_v4b_DW.tickCount = gbyk_v4b_B.TPSelector[7];
      gbyk_v4b_DW.boxtrig = 0.0;
      break;

     case gbyk_v4b_IN_RevealCorrectTgtC:
      /* During 'RevealCorrectTgtC': '<S25>:169' */
      if (((gbyk_v4b_DW.temporalCounter_i1 >= 1U) &&
           (gbyk_v4b_B.VectorConcatenate1[2] || gbyk_v4b_B.VectorConcatenate1[0])
           && (!gbyk_v4b_B.VectorConcatenate1[3])) ||
          (gbyk_v4b_DW.temporalCounter_i1 >= (uint32_T)gbyk_v4b_DW.tickCount)) {
        /* Transition: '<S25>:174' */
        /* check if missed the target but moved fast enough */
        gbyk_v4b_DW.is_MainTrial = gbyk_v4b_IN_TooSlowC;

        /* Entry 'TooSlowC': '<S25>:173' */
        /*  Log a bad trial */
        gbyk_v4b_B.event_code = (uint16_T)E_TOO_SLOW;
        gbyk_v4b_B.targetC_state[0] = 0.0;
        gbyk_v4b_B.targetC_state[1] = 0.0;
        gbyk_v4b_B.boxState = 0.0;
        gbyk_v4b_B.repeat_trial_flag = 1.0;
        gbyk_v4b_B.reward = 0.0;
        gbyk_v4b_B.doreward = 0.0;
        gbyk_v4b_B.feedback_text = -1;
        gbyk_v4b_B.tone = 2.0;
        gbyk_v4b_DW.tickCount = 500.0;
      } else if ((gbyk_v4b_DW.temporalCounter_i1 >= 1U) &&
                 gbyk_v4b_B.VectorConcatenate1[0] &&
                 gbyk_v4b_B.VectorConcatenate1[3]) {
        /* Transition: '<S25>:175' */
        /* check if hit the target and moved fast enough */
        gbyk_v4b_DW.is_MainTrial = gbyk_v4b_IN_HitTargetC;

        /* Entry 'HitTargetC': '<S25>:171' */
        /*  Log a successful hit */
        gbyk_v4b_B.event_code = (uint16_T)E_HIT_TARGETC;
        gbyk_v4b_B.targetC_state[(int32_T)(gbyk_v4b_DW.corrTgt - 1.0)] = 3.0;
        gbyk_v4b_B.targetC_state[(int32_T)(gbyk_v4b_DW.incorrTgt - 1.0)] = 0.0;
        gbyk_v4b_B.doreward = 1.0;
        gbyk_v4b_B.reward = gbyk_v4b_B.offeredRewardsC[0];
        gbyk_v4b_B.score += gbyk_v4b_B.reward;
        gbyk_v4b_B.tone = 3.0;
        gbyk_v4b_B.boxState = 0.0;
        gbyk_v4b_DW.tickCount = 500.0;
      } else if ((gbyk_v4b_DW.temporalCounter_i1 >= 1U) &&
                 ((gbyk_v4b_DW.tgt2trig != 0.0) ||
                  (gbyk_v4b_B.VectorConcatenate1[2] &&
                   (!gbyk_v4b_B.VectorConcatenate1[0]))) &&
                 gbyk_v4b_B.VectorConcatenate1[3]) {
        /* Transition: '<S25>:176' */
        /* check if missed the target but moved fast enough */
        gbyk_v4b_DW.is_MainTrial = gbyk_v4b_IN_MissTargetC;

        /* Entry 'MissTargetC': '<S25>:172' */
        /*  Log a target miss */
        gbyk_v4b_B.event_code = (uint16_T)E_MISS_TARGETC;
        gbyk_v4b_B.targetC_state[0] = 0.0;
        gbyk_v4b_B.targetC_state[1] = 0.0;
        gbyk_v4b_B.boxState = 0.0;
        gbyk_v4b_B.tone = 2.0;
        gbyk_v4b_B.reward = 0.0;
        gbyk_v4b_B.doreward = 0.0;
        gbyk_v4b_DW.tickCount = 500.0;
      } else {
        /*  if tgt xy is 4 20
           TODO fix this below  */
        gbyk_v4b_DW.disttrigy = (gbyk_v4b_B.Switch1[1] > gbyk_v4b_B.TargetTable
          [(int32_T)(gbyk_v4b_B.targetC_row[(int32_T)(gbyk_v4b_DW.corrTgt - 1.0)]
                     - 1.0) + 32]);
        gbyk_v4b_DW.tgt2trig = (gbyk_v4b_B.ArraySelector[(int32_T)
          (gbyk_v4b_B.targetC_row[(int32_T)(gbyk_v4b_DW.incorrTgt - 1.0)] - 1.0)]
          == 1.0);
        gbyk_v4b_B.VectorConcatenate1[2] = (fabs(gbyk_v4b_B.distance[(int32_T)
          (gbyk_v4b_B.targetA_row - 1.0)]) > gbyk_v4b_DW.tgtdist * 0.01);
        gbyk_v4b_B.VectorConcatenate1[2] = (gbyk_v4b_B.VectorConcatenate1[2] &&
          gbyk_v4b_DW.disttrigy);
        gbyk_v4b_B.VectorConcatenate1[0] = (gbyk_v4b_B.ArraySelector[(int32_T)
          (gbyk_v4b_B.targetC_row[(int32_T)(gbyk_v4b_DW.corrTgt - 1.0)] - 1.0)] ==
          1.0);
        gbyk_v4b_B.VectorConcatenate1[3] = (gbyk_v4b_B.VectorConcatenate1[3] ||
          (gbyk_v4b_B.Sqrt > gbyk_v4b_B.Taskwideparam[6]));
      }
      break;

     case gbyk_v4b_IN_SetupTgtB:
      /* During 'SetupTgtB': '<S25>:137' */
      /* Transition: '<S25>:141' */
      gbyk_v4b_DW.is_MainTrial = gbyk_v4b_IN_StayAtFirstTarget;
      gbyk_v4b_DW.temporalCounter_i1 = 0U;

      /* Entry 'StayAtFirstTarget': '<S25>:4' */
      /*  Log an event that target was reached and wait for a specified time.
         The wait time may have both a fixed and a random component. The hand must stay in the target for the full wait time. */
      gbyk_v4b_B.event_code = (uint16_T)E_STAY_START;
      gbyk_v4b_B.targetA_state = 1.0;
      gbyk_v4b_DW.tickCount = gbyk_v4b_B.Taskwideparam[7];

      /* TODO ask aaron if we want to show the second row values too or show nothing or just what to show before the trial starts */
      break;

     case gbyk_v4b_IN_ShowAllTargets:
      /* During 'ShowAllTargets': '<S25>:147' */
      if ((gbyk_v4b_DW.sfEvent == gbyk_v4b_event_e_clk_i) &&
          (gbyk_v4b_DW.temporalCounter_i1 >= (uint32_T)gbyk_v4b_DW.tickCount)) {
        /* Transition: '<S25>:148' */
        gbyk_v4b_DW.is_MainTrial = gbyk_v4b_IN_ShowReachTargets;
        gbyk_v4b_DW.temporalCounter_i1 = 0U;

        /* Entry 'ShowReachTargets': '<S25>:1' */
        /*  Turn on all reach targets and log an event indicating this has occurred. Then wait until the hand is the target or until a specified time has elapsed. */
        gbyk_v4b_B.event_code = (uint16_T)E_TARGETS_ON;
        gbyk_v4b_DW.tickCount = gbyk_v4b_B.TPSelector[6];
        gbyk_v4b_B.tone = 1.0;
      }
      break;

     case gbyk_v4b_IN_ShowReachTargets:
      /* During 'ShowReachTargets': '<S25>:1' */
      if ((gbyk_v4b_DW.sfEvent == gbyk_v4b_event_e_clk_i) &&
          (gbyk_v4b_DW.temporalCounter_i1 >= (uint32_T)gbyk_v4b_DW.tickCount)) {
        /* Transition: '<S25>:14' */
        /* if the trial times out it is an error */
        gbyk_v4b_B.feedback_text = -2;
        gbyk_v4b_DW.is_MainTrial = gbyk_v4b_IN_TooSlow;
        gbyk_v4b_DW.temporalCounter_i1 = 0U;
        gbyk_v4b_enter_atomic_TooSlow();
      } else if ((gbyk_v4b_DW.temporalCounter_i1 >= 1U) &&
                 gbyk_v4b_B.VectorConcatenate1[0] && (!(gbyk_v4b_DW.boxtrig !=
                   0.0))) {
        /* Transition: '<S25>:47' */
        /* when the hand velocity pr position exceeds the threshold
           shut off the second target */
        gbyk_v4b_DW.is_MainTrial = gbyk_v4b_IN_TriggerTargetB;
        gbyk_v4b_DW.temporalCounter_i1 = 0U;

        /* Entry 'TriggerTargetB': '<S25>:46' */
        /*  if they have chosen to go for the box */
        gbyk_v4b_B.event_code = (uint16_T)E_CHOSE_ROW_B;
        gbyk_v4b_B.tone = 0.0;
        gbyk_v4b_DW.tgtdist = 17.0;

        /*  HARD CODED ( (TargetTable[targetB_row[corrTgt]][col_x] - TargetTable[targetA_row][col_x])^2.0 + (TargetTable[targetB_row[corrTgt]][col_y] - TargetTable[targetA_row][col_y])^2.0 )^0.5; */
        gbyk_v4b_B.VectorConcatenate1[0] = false;
      } else if ((gbyk_v4b_DW.temporalCounter_i1 >= 1U) &&
                 gbyk_v4b_B.VectorConcatenate1[1] && (gbyk_v4b_DW.boxtrig != 0.0))
      {
        /* Transition: '<S25>:167' */
        gbyk_v4b_DW.is_MainTrial = gbyk_v4b_IN_TriggerTargetC;
        gbyk_v4b_DW.temporalCounter_i1 = 0U;

        /* Entry 'TriggerTargetC': '<S25>:166' */
        gbyk_v4b_B.event_code = (uint16_T)E_BOX_TRIGGER;
        gbyk_v4b_B.targetB_state[0] = 0.0;
        gbyk_v4b_B.targetB_state[1] = 0.0;
        gbyk_v4b_B.tone = 0.0;
      } else {
        /* handvel2d = sqrt((HandVel[1])^2 + (HandVel[2])^2); */
        gbyk_v4b_B.VectorConcatenate1[1] = (gbyk_v4b_B.Sqrt >
          gbyk_v4b_B.Taskwideparam[4]);

        /* postrig = abs( HandPos[1] - (TargetTable[targetA_row][col_x])) > (TargetTable[boxRow][LOGICAL_RADIUS]/2);
           aboveasks whether the hand is past the side edges of the box which triggers rowB */
        gbyk_v4b_B.VectorConcatenate1[0] = ((fabs(gbyk_v4b_B.distance[(int32_T)
          (gbyk_v4b_B.targetB_row[(int32_T)(gbyk_v4b_DW.corrTgt - 1.0)] - 1.0)])
          < gbyk_v4b_B.Taskwideparam[5] * 0.01) || (fabs(gbyk_v4b_B.distance
          [(int32_T)(gbyk_v4b_B.targetB_row[(int32_T)(gbyk_v4b_DW.incorrTgt -
          1.0)] - 1.0)]) < gbyk_v4b_B.Taskwideparam[5] * 0.01));
        gbyk_v4b_DW.boxtrig = (gbyk_v4b_B.ArraySelector_n[(int32_T)
          (gbyk_v4b_B.boxRow - 1.0)] == 1.0);
      }
      break;

     case gbyk_v4b_IN_ShowStartTarget:
      /* During 'ShowStartTarget': '<S25>:6' */
      /* Transition: '<S25>:140' */
      if ((gbyk_v4b_B.ArraySelector[(int32_T)(gbyk_v4b_B.targetA_row - 1.0)] ==
           1.0) && (!gbyk_v4b_DW.setup_trial_flag)) {
        /* Transition: '<S25>:11' */
        gbyk_v4b_DW.is_MainTrial = gbyk_v4b_IN_SetupTgtB;

        /* Entry 'SetupTgtB': '<S25>:137' */
        /* if turning the targets on the for the first time (each trial), set them up. We can only do this once per trial or it will throw the counters off. */
        gbyk_v4b_B.targetB_row[0] = gbyk_v4b_B.TPSelector[9];
        gbyk_v4b_B.targetB_row[1] = gbyk_v4b_B.TPSelector[10];
        gbyk_v4b_DW.corrTgt = gbyk_v4b_B.TPSelector[1];
        gbyk_v4b_DW.incorrTgt = gbyk_v4b_B.TPSelector[2];
        gbyk_v4b_B.offeredRewards[0] = gbyk_v4b_B.TPSelector[3] *
          gbyk_v4b_B.TPSelector[5];
        gbyk_v4b_B.offeredRewards[1] = gbyk_v4b_B.TPSelector[4] *
          gbyk_v4b_B.TPSelector[5];
        gbyk_v4b_B.offeredRewardsC[0] = gbyk_v4b_B.TPSelector[3];
        gbyk_v4b_B.offeredRewardsC[1] = gbyk_v4b_B.TPSelector[4];
        gbyk_v4b_DW.setup_trial_flag = true;
      } else {
        if ((gbyk_v4b_B.ArraySelector[(int32_T)(gbyk_v4b_B.targetA_row - 1.0)] ==
             1.0) && gbyk_v4b_DW.setup_trial_flag) {
          /* Transition: '<S25>:138' */
          gbyk_v4b_DW.is_MainTrial = gbyk_v4b_IN_StayAtFirstTarget;
          gbyk_v4b_DW.temporalCounter_i1 = 0U;

          /* Entry 'StayAtFirstTarget': '<S25>:4' */
          /*  Log an event that target was reached and wait for a specified time.
             The wait time may have both a fixed and a random component. The hand must stay in the target for the full wait time. */
          gbyk_v4b_B.event_code = (uint16_T)E_STAY_START;
          gbyk_v4b_B.targetA_state = 1.0;
          gbyk_v4b_DW.tickCount = gbyk_v4b_B.Taskwideparam[7];

          /* TODO ask aaron if we want to show the second row values too or show nothing or just what to show before the trial starts */
        }
      }
      break;

     case gbyk_v4b_IN_StayAtFirstTarget:
      /* During 'StayAtFirstTarget': '<S25>:4' */
      if ((gbyk_v4b_DW.sfEvent == gbyk_v4b_event_e_clk_i) &&
          (gbyk_v4b_DW.temporalCounter_i1 >= (uint32_T)gbyk_v4b_DW.tickCount)) {
        /* Transition: '<S25>:9' */
        gbyk_v4b_DW.is_MainTrial = gbyk_v4b_IN_ShowAllTargets;
        gbyk_v4b_DW.temporalCounter_i1 = 0U;

        /* Entry 'ShowAllTargets': '<S25>:147' */
        /*  Log an event that target was reached and wait for a specified time.
           The wait time may have both a fixed and a random component. The hand must stay in the target for the full wait time. */
        gbyk_v4b_B.event_code = (uint16_T)E_STAY_START;

        /* targetA_state = 1; */
        gbyk_v4b_DW.tickCount = gbyk_v4b_B.Taskwideparam[3] * (real_T)rand() /
          gbyk_v4b_RAND_MAX + gbyk_v4b_B.Taskwideparam[2];

        /* Show targets before the go tone - allows for comparison */
        gbyk_v4b_B.targetB_state[0] = 1.0;
        gbyk_v4b_B.targetB_state[1] = 1.0;
        gbyk_v4b_B.targetC_state[0] = 1.0;
        gbyk_v4b_B.targetC_state[1] = 1.0;
        gbyk_v4b_B.boxState = 1.0;
      } else {
        if (gbyk_v4b_B.ArraySelector[(int32_T)(gbyk_v4b_B.targetA_row - 1.0)] ==
            0.0) {
          /* Transition: '<S25>:18' */
          gbyk_v4b_DW.is_MainTrial = gbyk_v4b_IN_ShowStartTarget;
          gbyk_v4b_enter_atomic_ShowStartTarget();
        }
      }
      break;

     case gbyk_v4b_IN_TooSlow:
      /* During 'TooSlow': '<S25>:63' */
      if ((gbyk_v4b_DW.sfEvent == gbyk_v4b_event_e_clk_i) &&
          (gbyk_v4b_DW.temporalCounter_i1 >= (uint32_T)gbyk_v4b_DW.tickCount)) {
        /* Transition: '<S25>:66' */
        gbyk_v4b_DW.is_MainTrial = gbyk_v4b_IN_EndOfTrial;
        gbyk_v4b_DW.temporalCounter_i1 = 0U;

        /* Entry 'EndOfTrial': '<S25>:3' */
        /*  Set the post-trial delay. */
        gbyk_v4b_DW.tickCount = gbyk_v4b_B.TPSelector[7];
        gbyk_v4b_DW.boxtrig = 0.0;
      }
      break;

     case gbyk_v4b_IN_TooSlowC:
      /* During 'TooSlowC': '<S25>:173' */
      /* Transition: '<S25>:179' */
      gbyk_v4b_DW.is_MainTrial = gbyk_v4b_IN_EndOfTrial;
      gbyk_v4b_DW.temporalCounter_i1 = 0U;

      /* Entry 'EndOfTrial': '<S25>:3' */
      /*  Set the post-trial delay. */
      gbyk_v4b_DW.tickCount = gbyk_v4b_B.TPSelector[7];
      gbyk_v4b_DW.boxtrig = 0.0;
      break;

     case gbyk_v4b_IN_TriggerTargetB:
      /* During 'TriggerTargetB': '<S25>:46' */
      if (((gbyk_v4b_DW.temporalCounter_i1 >= 1U) &&
           (gbyk_v4b_B.VectorConcatenate1[2] || gbyk_v4b_B.VectorConcatenate1[0])
           && (!gbyk_v4b_B.VectorConcatenate1[3])) ||
          (gbyk_v4b_DW.temporalCounter_i1 >= (uint32_T)gbyk_v4b_DW.tickCount)) {
        /* Transition: '<S25>:64' */
        /* check if missed the target but moved fast enough */
        gbyk_v4b_B.feedback_text = -1;
        gbyk_v4b_DW.is_MainTrial = gbyk_v4b_IN_TooSlow;
        gbyk_v4b_DW.temporalCounter_i1 = 0U;
        gbyk_v4b_enter_atomic_TooSlow();
      } else if ((gbyk_v4b_DW.temporalCounter_i1 >= 1U) &&
                 ((gbyk_v4b_DW.tgt2trig != 0.0) ||
                  (gbyk_v4b_B.VectorConcatenate1[2] &&
                   (!gbyk_v4b_B.VectorConcatenate1[0]))) &&
                 gbyk_v4b_B.VectorConcatenate1[3]) {
        /* Transition: '<S25>:58' */
        /* check if missed the target but moved fast enough */
        gbyk_v4b_DW.is_MainTrial = gbyk_v4b_IN_MissTargetB;
        gbyk_v4b_DW.temporalCounter_i1 = 0U;

        /* Entry 'MissTargetB': '<S25>:57' */
        /*  Log a target miss */
        gbyk_v4b_B.event_code = (uint16_T)E_MISS_TARGETB;
        gbyk_v4b_B.targetB_state[0] = 0.0;
        gbyk_v4b_B.targetB_state[1] = 0.0;
        gbyk_v4b_B.targetC_state[0] = 0.0;
        gbyk_v4b_B.targetC_state[1] = 0.0;
        gbyk_v4b_B.boxState = 0.0;
        gbyk_v4b_B.reward = 0.0;
        gbyk_v4b_B.doreward = 0.0;
        gbyk_v4b_B.tone = 2.0;
        gbyk_v4b_DW.tickCount = 500.0;
      } else if ((gbyk_v4b_DW.temporalCounter_i1 >= 1U) &&
                 gbyk_v4b_B.VectorConcatenate1[0] &&
                 gbyk_v4b_B.VectorConcatenate1[3]) {
        /* Transition: '<S25>:55' */
        /* check if hit the target and moved fast enough */
        gbyk_v4b_DW.is_MainTrial = gbyk_v4b_IN_HitTargetB;
        gbyk_v4b_DW.temporalCounter_i1 = 0U;

        /* Entry 'HitTargetB': '<S25>:2' */
        /*  Log a successful hit */
        gbyk_v4b_B.event_code = (uint16_T)E_HIT_TARGETB;
        gbyk_v4b_B.targetB_state[(int32_T)(gbyk_v4b_DW.corrTgt - 1.0)] = 3.0;
        gbyk_v4b_B.targetB_state[(int32_T)(gbyk_v4b_DW.incorrTgt - 1.0)] = 0.0;
        gbyk_v4b_B.targetC_state[0] = 0.0;
        gbyk_v4b_B.targetC_state[1] = 0.0;
        gbyk_v4b_B.boxState = 0.0;
        gbyk_v4b_B.doreward = 1.0;
        gbyk_v4b_B.reward = gbyk_v4b_B.offeredRewards[0];
        gbyk_v4b_B.score += gbyk_v4b_B.reward;
        gbyk_v4b_B.tone = 3.0;
        gbyk_v4b_DW.tickCount = 500.0;
      } else {
        gbyk_v4b_B.VectorConcatenate1[0] = (gbyk_v4b_B.ArraySelector[(int32_T)
          (gbyk_v4b_B.targetB_row[(int32_T)(gbyk_v4b_DW.corrTgt - 1.0)] - 1.0)] ==
          1.0);
        gbyk_v4b_DW.tgt2trig = (gbyk_v4b_B.ArraySelector[(int32_T)
          (gbyk_v4b_B.targetB_row[(int32_T)(gbyk_v4b_DW.incorrTgt - 1.0)] - 1.0)]
          == 1.0);
        gbyk_v4b_DW.disttrigy = (gbyk_v4b_B.Switch1[1] > gbyk_v4b_B.TargetTable
          [(int32_T)(gbyk_v4b_B.targetB_row[(int32_T)(gbyk_v4b_DW.corrTgt - 1.0)]
                     - 1.0) + 32]);
        gbyk_v4b_B.VectorConcatenate1[2] = (fabs(gbyk_v4b_B.distance[(int32_T)
          (gbyk_v4b_B.targetA_row - 1.0)]) > gbyk_v4b_DW.tgtdist * 0.01);
        gbyk_v4b_B.VectorConcatenate1[2] = (gbyk_v4b_B.VectorConcatenate1[2] &&
          gbyk_v4b_DW.disttrigy);
        gbyk_v4b_B.VectorConcatenate1[3] = (gbyk_v4b_B.VectorConcatenate1[3] ||
          (gbyk_v4b_B.Sqrt > gbyk_v4b_B.Taskwideparam[6]));

        /* (sqrt(HandVel[1]^2 + HandVel[2]^2) */
      }
      break;

     default:
      /* During 'TriggerTargetC': '<S25>:166' */
      if ((gbyk_v4b_DW.sfEvent == gbyk_v4b_event_e_clk_i) &&
          (gbyk_v4b_DW.temporalCounter_i1 >= 1U)) {
        /* Transition: '<S25>:170' */
        gbyk_v4b_DW.is_MainTrial = gbyk_v4b_IN_RevealCorrectTgtC;
        gbyk_v4b_DW.temporalCounter_i1 = 0U;

        /* Entry 'RevealCorrectTgtC': '<S25>:169' */
        /* event_code = E_CHOSE_TGT_C */
        gbyk_v4b_B.targetC_state[(int32_T)(gbyk_v4b_DW.corrTgt - 1.0)] = 1.0;
        gbyk_v4b_B.targetC_state[(int32_T)(gbyk_v4b_DW.incorrTgt - 1.0)] = 0.0;
        gbyk_v4b_DW.tgtdist = 27.0;
      }
      break;
    }
  }
}

/* Function for Chart: '<Root>/Trial_Control' */
static void gbyk_v4b_chartstep_c1_gbyk_v4b(void)
{
  /* During: Trial_Control */
  if (gbyk_v4b_DW.is_active_c1_gbyk_v4b == 0U) {
    /* Entry: Trial_Control */
    gbyk_v4b_DW.is_active_c1_gbyk_v4b = 1U;

    /* Entry Internal: Trial_Control */
    /* Transition: '<S25>:154' */
    gbyk_v4b_DW.is_c1_gbyk_v4b = gbyk_v4b_IN_Initialize;

    /* Entry 'Initialize': '<S25>:7' */
    /*  Both the targets and data logging are initially off. */
    gbyk_v4b_B.targetA_state = 0.0;
    gbyk_v4b_B.targetB_state[0] = 0.0;
    gbyk_v4b_B.targetB_state[1] = 0.0;
    gbyk_v4b_B.targetC_state[0] = 0.0;
    gbyk_v4b_B.targetC_state[1] = 0.0;
    gbyk_v4b_B.targetC_row[0] = 10.0;
    gbyk_v4b_B.targetC_row[1] = 11.0;
    gbyk_v4b_B.boxState = 0.0;
    gbyk_v4b_B.boxRow = 8.0;
    gbyk_v4b_B.logging_enable[0] = 0.0;
    gbyk_v4b_B.logging_enable[1] = 0.0;
    gbyk_v4b_B.score = 0.0;
    gbyk_v4b_B.reward = 0.0;
    gbyk_v4b_B.doreward = 0.0;
    gbyk_v4b_B.feedback_text = 0;
    gbyk_v4b_B.repeat_trial_flag = 0.0;
    gbyk_v4b_DW.setup_trial_flag = false;
  } else {
    switch (gbyk_v4b_DW.is_c1_gbyk_v4b) {
     case gbyk_v4b_IN_EndInstructPause:
      /* During 'EndInstructPause': '<S25>:88' */
      if ((gbyk_v4b_DW.sfEvent == gbyk_v4b_event_e_clk_i) &&
          (gbyk_v4b_DW.temporalCounter_i1 >= (uint32_T)gbyk_v4b_DW.tickCount)) {
        /* Transition: '<S25>:77' */
        gbyk_v4b_DW.is_c1_gbyk_v4b = gbyk_v4b_IN_ReturnToStart1;
        gbyk_v4b_DW.temporalCounter_i1 = 0U;
        gbyk_v4b_enter_atomic_ReturnToStart1();
      }
      break;

     case gbyk_v4b_IN_Ending:
      /* During 'Ending': '<S25>:84' */
      if ((gbyk_v4b_DW.sfEvent == gbyk_v4b_event_e_clk_i) &&
          (gbyk_v4b_DW.temporalCounter_i1 >= 1U)) {
        /* Transition: '<S25>:92' */
        if (gbyk_v4b_B.TPSelector[8] == 0.0) {
          /* Transition: '<S25>:80' */
          /* continue if a regular trial comes after! */
          gbyk_v4b_DW.is_c1_gbyk_v4b = gbyk_v4b_IN_EndInstructPause;
          gbyk_v4b_DW.temporalCounter_i1 = 0U;

          /* Entry 'EndInstructPause': '<S25>:88' */
          gbyk_v4b_B.instruct_num = 0.0;
          gbyk_v4b_DW.tickCount = gbyk_v4b_B.TPSelector[7];
          gbyk_v4b_B.logging_enable[0] = 1.0;
          gbyk_v4b_B.logging_enable[1] = 1.0;
          gbyk_v4b_B.score = 0.0;
        } else {
          /* so we can show the score and then show instructions */
          if (gbyk_v4b_B.TPSelector[8] > 0.0) {
            /* Transition: '<S25>:90' */
            gbyk_v4b_DW.is_c1_gbyk_v4b = gbyk_v4b_IN_ShowInstructState;
            gbyk_v4b_DW.temporalCounter_i1 = 0U;
            gbyk_v4b_enter_atomic_ShowInstructState();
          }
        }
      }
      break;

     case gbyk_v4b_IN_Initialize:
      /* During 'Initialize': '<S25>:7' */
      if (gbyk_v4b_B.TPSelector[8] == 0.0) {
        /* Transition: '<S25>:19' */
        gbyk_v4b_DW.is_c1_gbyk_v4b = gbyk_v4b_IN_MainTrial;
        gbyk_v4b_DW.is_MainTrial = gbyk_v4b_IN_ShowStartTarget;
        gbyk_v4b_enter_atomic_ShowStartTarget();
      } else {
        if (gbyk_v4b_B.TPSelector[8] > 0.0) {
          /* Transition: '<S25>:95' */
          /* in case we start with an instruction trial */
          gbyk_v4b_DW.is_c1_gbyk_v4b = gbyk_v4b_IN_ShowInstructState;
          gbyk_v4b_DW.temporalCounter_i1 = 0U;
          gbyk_v4b_enter_atomic_ShowInstructState();
        }
      }
      break;

     case gbyk_v4b_IN_InstructWaitState:
      /* During 'InstructWaitState': '<S25>:79' */
      if (gbyk_v4b_DW.sfEvent == gbyk_v4b_event_e_cntl_btn) {
        /* Transition: '<S25>:78' */
        gbyk_v4b_B.event_code = 22U;
        gbyk_v4b_DW.is_c1_gbyk_v4b = gbyk_v4b_IN_Ending;
        gbyk_v4b_DW.temporalCounter_i1 = 0U;

        /* Entry 'Ending': '<S25>:84' */
        /* end the special "show score" state
           score = 0; */
        /* Event: '<S25>:44' */
        gbyk_v4b_DW.e_Trial_EndEventCounter++;
      }
      break;

     case gbyk_v4b_IN_Inter_Trial_State:
      /* During 'Inter_Trial_State': '<S25>:5' */
      if ((gbyk_v4b_DW.sfEvent == gbyk_v4b_event_e_clk_i) &&
          (gbyk_v4b_DW.temporalCounter_i1 >= 1U)) {
        /* Transition: '<S25>:82' */
        if (gbyk_v4b_B.TPSelector[8] == -1.0) {
          /* Transition: '<S25>:75' */
          gbyk_v4b_DW.is_c1_gbyk_v4b = gbyk_v4b_IN_ShowScoreState;
          gbyk_v4b_DW.temporalCounter_i1 = 0U;

          /* Entry 'ShowScoreState': '<S25>:81' */
          gbyk_v4b_B.event_code = (uint16_T)E_SHOW_SCORE;
          gbyk_v4b_B.targetA_state = 0.0;
          gbyk_v4b_B.targetB_state[0] = 0.0;
          gbyk_v4b_B.targetB_state[1] = 0.0;
          gbyk_v4b_B.targetC_state[0] = 0.0;
          gbyk_v4b_B.targetC_state[1] = 0.0;
          gbyk_v4b_B.boxState = 0.0;
          gbyk_v4b_B.doreward = 2.0;
          gbyk_v4b_DW.tickCount = gbyk_v4b_B.TPSelector[6];
          gbyk_v4b_B.logging_enable[0] = 0.0;
          gbyk_v4b_B.logging_enable[1] = 0.0;
        } else if (gbyk_v4b_B.TPSelector[8] > 0.0) {
          /* Transition: '<S25>:85' */
          gbyk_v4b_DW.is_c1_gbyk_v4b = gbyk_v4b_IN_ShowInstructState;
          gbyk_v4b_DW.temporalCounter_i1 = 0U;
          gbyk_v4b_enter_atomic_ShowInstructState();
        } else {
          if (gbyk_v4b_B.TPSelector[8] == 0.0) {
            /* Transition: '<S25>:87' */
            gbyk_v4b_DW.is_c1_gbyk_v4b = gbyk_v4b_IN_ReturnToStart1;
            gbyk_v4b_DW.temporalCounter_i1 = 0U;
            gbyk_v4b_enter_atomic_ReturnToStart1();
          }
        }
      }
      break;

     case gbyk_v4b_IN_MainTrial:
      gbyk_v4b_MainTrial();
      break;

     case gbyk_v4b_IN_ReturnToStart1:
      /* During 'ReturnToStart1': '<S25>:83' */
      if ((gbyk_v4b_DW.sfEvent == gbyk_v4b_event_e_clk_i) &&
          (gbyk_v4b_DW.temporalCounter_i1 >= 1U)) {
        /* Transition: '<S25>:16' */
        gbyk_v4b_DW.is_c1_gbyk_v4b = gbyk_v4b_IN_MainTrial;
        gbyk_v4b_DW.is_MainTrial = gbyk_v4b_IN_ShowStartTarget;
        gbyk_v4b_enter_atomic_ShowStartTarget();
      }
      break;

     case gbyk_v4b_IN_ShowInstructState:
      /* During 'ShowInstructState': '<S25>:73' */
      if ((gbyk_v4b_DW.sfEvent == gbyk_v4b_event_e_clk_i) &&
          (gbyk_v4b_DW.temporalCounter_i1 >= (uint32_T)gbyk_v4b_DW.tickCount)) {
        /* Transition: '<S25>:74' */
        gbyk_v4b_DW.is_c1_gbyk_v4b = gbyk_v4b_IN_InstructWaitState;

        /* Entry 'InstructWaitState': '<S25>:79' */
        /* "pause" here until the button has been clicked */
      }
      break;

     default:
      /* During 'ShowScoreState': '<S25>:81' */
      if ((gbyk_v4b_DW.sfEvent == gbyk_v4b_event_e_clk_i) &&
          (gbyk_v4b_DW.temporalCounter_i1 >= (uint32_T)gbyk_v4b_DW.tickCount)) {
        /* Transition: '<S25>:76' */
        gbyk_v4b_DW.is_c1_gbyk_v4b = gbyk_v4b_IN_Ending;
        gbyk_v4b_DW.temporalCounter_i1 = 0U;

        /* Entry 'Ending': '<S25>:84' */
        /* end the special "show score" state
           score = 0; */
        /* Event: '<S25>:44' */
        gbyk_v4b_DW.e_Trial_EndEventCounter++;
      }
      break;
    }
  }
}

/* Function for MATLAB Function: '<S265>/Embedded MATLAB Function' */
static uint32_T gbyk_v4b_colourshift_h(real_T RRRGGGBBB)
{
  uint32_T RRGGBBAA;
  uint32_T blue;
  uint32_T green;
  uint32_T q0;
  uint32_T qY;
  uint64_T tmp;
  int32_T tmp_0;
  real_T tmp_1;

  /*  The colourshift function converts an "RRRGGGBBB" colour value to RRGBB (as an uint32). */
  /* this is "no fill" */
  if (RRRGGGBBB == 1.0E+9) {
    /* '<S266>:1:232' */
    /* '<S266>:1:233' */
    RRGGBBAA = 16777216U;

    /* hex 0x1000000 */
  } else {
    /* '<S266>:1:237' */
    tmp_1 = rt_roundd_snf(RRRGGGBBB - floor(RRRGGGBBB / 1000.0) * 1000.0);
    if (tmp_1 < 4.294967296E+9) {
      if (tmp_1 >= 0.0) {
        blue = (uint32_T)tmp_1;
      } else {
        blue = 0U;
      }
    } else {
      blue = MAX_uint32_T;
    }

    /* '<S266>:1:238' */
    tmp_1 = rt_roundd_snf(RRRGGGBBB - (real_T)blue);
    if (tmp_1 < 4.294967296E+9) {
      if (tmp_1 >= 0.0) {
        green = (uint32_T)tmp_1;
      } else {
        green = 0U;
      }
    } else {
      green = MAX_uint32_T;
    }

    tmp_0 = (int32_T)rt_roundd_snf((real_T)(green - green / 1000000U * 1000000U)
      / 1000.0);
    green = (uint32_T)tmp_0;

    /* '<S266>:1:239' */
    /* '<S266>:1:241' */
    tmp = green * 1000ULL;
    if (tmp > 4294967295ULL) {
      tmp = 4294967295ULL;
    }

    tmp_1 = rt_roundd_snf(RRRGGGBBB - (real_T)(uint32_T)tmp);
    if (tmp_1 < 4.294967296E+9) {
      if (tmp_1 >= 0.0) {
        q0 = (uint32_T)tmp_1;
      } else {
        q0 = 0U;
      }
    } else {
      q0 = MAX_uint32_T;
    }

    qY = q0 - blue;
    if (qY > q0) {
      qY = 0U;
    }

    tmp_0 = (int32_T)rt_roundd_snf((real_T)qY / 1.0E+6);
    tmp = (uint64_T)(((uint32_T)tmp_0 << 16U) + (green << 8U)) + blue;
    if (tmp > 4294967295ULL) {
      tmp = 4294967295ULL;
    }

    RRGGBBAA = (uint32_T)tmp;
  }

  return RRGGBBAA;
}

/* Model output function for TID0 */
static void gbyk_v4b_output0(void)     /* Sample time: [0.0s, 0.0s] */
{
  real_T hold_steps;
  boolean_T x[499];
  real_T reps2;
  real_T reps3;
  int32_T khi;
  int32_T exponent;
  real_T stroke_colour_col;
  real_T stroke_width_col;
  int32_T n1;
  int32_T n1d;
  int32_T n2d;
  static const char_T text1[12] = { 'Y', 'o', 'u', ' ', 'e', 'a', 'r', 'n', 'e',
    'd', ' ', '$' };

  static const char_T c[9] = { 'T', 'o', 'o', ' ', 'F', 'a', 's', 't', '!' };

  static const char_T d[10] = { 'T', 'o', 'o', ' ', 'E', 'a', 'r', 'l', 'y', '!'
  };

  static const char_T e[9] = { 'T', 'o', 'o', ' ', 'S', 'l', 'o', 'w', '!' };

  static const char_T f[9] = { 'T', 'o', 'o', ' ', 'L', 'a', 't', 'e', '!' };

  static const char_T b_text1[11] = { 'Y', 'o', 'u', ' ', 'e', 'a', 'r', 'n',
    'e', 'd', ' ' };

  static const char_T text2[7] = { ' ', 'c', 'e', 'n', 't', 's', '!' };

  real32_T ss[2];
  real_T hold_steps_0[3];
  int32_T i;
  real_T tmp[7];
  boolean_T tmp_0;
  real_T tmp_1[20];
  real_T tmp_2[35];
  real_T tmp_3[45];
  char_T b_text1_0[20];
  char_T b_text1_1[19];
  real_T tmp_4[30];
  int32_T c_data[8];
  real_T trials_data[499];
  real_T BlockDef_data[499];
  int32_T BlockDef_sizes;
  int32_T idx_data[499];
  int32_T idx_sizes;
  char_T textout_data[20];
  char_T textdollars_data[2];
  uint8_T textnum_data[20];
  boolean_T zcEvent_idx_0;
  boolean_T zcEvent_idx_1;
  boolean_T zcEvent_idx_2;
  int16_T b_idx_0;
  char_T textcents_idx_0;
  char_T textcents_idx_1;
  int8_T varargin_1_idx_0;
  uint32_T tmp_5;
  int64_T tmp_6;

  {                                    /* Sample time: [0.0s, 0.0s] */
    rate_monotonic_scheduler();
  }

  /* Reset subsysRan breadcrumbs */
  srClearBC(gbyk_v4b_DW.UDPSendSubsystem_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(gbyk_v4b_DW.SendControlMachine_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(gbyk_v4b_DW.plate1_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(gbyk_v4b_DW.plate2_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(gbyk_v4b_DW.M1AbsEncCalibration_SubsysRanBC_h);

  /* Reset subsysRan breadcrumbs */
  srClearBC(gbyk_v4b_DW.M2AbsEncCalibration_SubsysRanBC_h);

  /* Reset subsysRan breadcrumbs */
  srClearBC(gbyk_v4b_DW.Arm1_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(gbyk_v4b_DW.M1AbsEncCalibration_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(gbyk_v4b_DW.M2AbsEncCalibration_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(gbyk_v4b_DW.Arm2_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(gbyk_v4b_DW.IfActionSubsystem_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(gbyk_v4b_DW.DataTransferStartSubsystem_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(gbyk_v4b_DW.ReadDPRAM_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(gbyk_v4b_DW.WriteDPRAM_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(gbyk_v4b_DW.read_pmac_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(gbyk_v4b_DW.Datareceive_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(gbyk_v4b_DW.updateconstantssubsystem_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(gbyk_v4b_DW.Datawrite_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(gbyk_v4b_DW.update_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(gbyk_v4b_DW.updatesettings_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(gbyk_v4b_DW.createKINData_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(gbyk_v4b_DW.EtherCATApplyLoads_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(gbyk_v4b_DW.applypmacloads_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(gbyk_v4b_DW.TaskExecutionControlMachine_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(gbyk_v4b_DW.Trial_Control_SubsysRanBC);

  /* Level2 S-Function Block: '<S7>/ICH7' (ich10) */
  {
    SimStruct *rts = gbyk_v4b_M->childSfunctions[40];
    sfcnOutputs(rts, 0);
  }

  /* Constant: '<S7>/Block Definitions' */
  memcpy(&gbyk_v4b_B.BlockDefinitions[0], &gbyk_v4b_P.BlockDefinitions_Value[0],
         25000U * sizeof(real_T));

  /* Constant: '<S7>/Block Sequence' */
  memcpy(&gbyk_v4b_B.BlockSequence[0], &gbyk_v4b_P.BlockSequence_Value[0], 2000U
         * sizeof(real_T));

  /* Level2 S-Function Block: '<S268>/Run Command Receive' (xpcudpbytereceive) */
  {
    SimStruct *rts = gbyk_v4b_M->childSfunctions[41];
    sfcnOutputs(rts, 0);
  }

  /* DataTypeConversion: '<S268>/Data Type Conversion' */
  gbyk_v4b_B.DataTypeConversion = gbyk_v4b_B.RunCommandReceive_o1;

  /* MATLAB Function: '<S268>/Embedded MATLAB Function' */
  /* MATLAB Function 'GUI Control/Run Command Subsystem/Embedded MATLAB Function': '<S273>:1' */
  /*  This block determines the run_command input of the task execution control */
  /*  subsystem (y), as well as the value of the task control button Goto (z). */
  /*  To the run_command input, only output a 1 or a 0 ('run' or 'pause') */
  /*  according to the last received status for the Go/Pause button. */
  if ((gbyk_v4b_B.DataTypeConversion < 2.0) && (gbyk_v4b_DW.u !=
       gbyk_v4b_B.DataTypeConversion)) {
    /* '<S273>:1:18' */
    /* '<S273>:1:19' */
    gbyk_v4b_DW.u = gbyk_v4b_B.DataTypeConversion;
  }

  /* '<S273>:1:22' */
  gbyk_v4b_B.y = gbyk_v4b_DW.u;

  /*  To the Goto block, only output a non-zero value on the first receipt of  */
  /*  a block index > 1 (i.e. not the Go/Pause button). */
  if ((gbyk_v4b_B.DataTypeConversion > 1.0) && (gbyk_v4b_B.DataTypeConversion !=
       gbyk_v4b_DW.v)) {
    /* '<S273>:1:26' */
    /* '<S273>:1:27' */
    gbyk_v4b_DW.v = gbyk_v4b_B.DataTypeConversion;
    if (gbyk_v4b_DW.v == 255.0) {
      /* '<S273>:1:28' */
      /* '<S273>:1:29' */
      gbyk_v4b_B.z = 0.0;
    } else {
      /* '<S273>:1:31' */
      gbyk_v4b_B.z = gbyk_v4b_DW.v;
    }
  } else {
    /* '<S273>:1:34' */
    gbyk_v4b_B.z = 0.0;
  }

  /* End of MATLAB Function: '<S268>/Embedded MATLAB Function' */

  /* DataTypeConversion: '<S268>/Data Type Conversion1' */
  stroke_width_col = floor(gbyk_v4b_B.y);
  if (rtIsNaN(stroke_width_col) || rtIsInf(stroke_width_col)) {
    stroke_width_col = 0.0;
  } else {
    stroke_width_col = fmod(stroke_width_col, 256.0);
  }

  gbyk_v4b_B.DataTypeConversion1_gw = (uint8_T)(stroke_width_col < 0.0 ?
    (int32_T)(uint8_T)-(int8_T)(uint8_T)-stroke_width_col : (int32_T)(uint8_T)
    stroke_width_col);

  /* End of DataTypeConversion: '<S268>/Data Type Conversion1' */

  /* Constant: '<S7>/Pause Type' */
  gbyk_v4b_B.PauseType = gbyk_v4b_P.PauseType_Value;

  /* DataTypeConversion: '<S7>/Convert18' incorporates:
   *  Constant: '<S7>/Seed'
   */
  gbyk_v4b_B.Convert18 = gbyk_v4b_P.Seed_Value;

  /* Constant: '<S7>/Use Task Protocol Block Sequence Flag' */
  gbyk_v4b_B.UseTaskProtocolBlockSequenceFlag =
    gbyk_v4b_P.UseTaskProtocolBlockSequenceFlag_Value;

  /* Constant: '<S7>/Next Block' */
  gbyk_v4b_B.NextBlock = gbyk_v4b_P.NextBlock_Value;

  /* Outputs for Atomic SubSystem: '<S7>/Task Execution Control Subsystem' */
  gbyk_v4b_TaskExecutionControlSubsystem();

  /* End of Outputs for SubSystem: '<S7>/Task Execution Control Subsystem' */

  /* DataTypeConversion: '<S7>/Convert16' */
  gbyk_v4b_B.Convert16 = gbyk_v4b_B.DataTypeConversion2_n;

  /* DataTypeConversion: '<S7>/Convert17' */
  gbyk_v4b_B.Convert17 = gbyk_v4b_B.Product_i;

  /* DataTypeConversion: '<S7>/Convert19' */
  gbyk_v4b_B.Convert19_b = gbyk_v4b_B.trial_in_set;

  /* DataTypeConversion: '<S7>/Convert20' */
  gbyk_v4b_B.Convert20 = gbyk_v4b_B.task_status;

  /* DataTypeConversion: '<S7>/Convert21' */
  gbyk_v4b_B.Convert21 = gbyk_v4b_B.block_in_set;

  /* DataTypeConversion: '<S7>/Convert22' */
  gbyk_v4b_B.Convert22 = gbyk_v4b_B.trial_in_block;

  /* DataTypeConversion: '<S7>/Convert23' */
  gbyk_v4b_B.Convert23 = gbyk_v4b_B.block;

  /* DataTypeConversion: '<S7>/Convert24' */
  gbyk_v4b_B.Convert24 = gbyk_v4b_B.tp;

  /* DataTypeConversion: '<S7>/Convert25' */
  gbyk_v4b_B.Convert25 = (gbyk_v4b_B.repeat_last_trial != 0.0);

  /* MinMax: '<S7>/MinMax' incorporates:
   *  Constant: '<S7>/Constant'
   */
  reps3 = gbyk_v4b_B.Convert24;
  hold_steps = gbyk_v4b_P.Constant_Value_h;
  if ((reps3 >= hold_steps) || rtIsNaN(hold_steps)) {
    hold_steps = reps3;
  }

  gbyk_v4b_B.MinMax = hold_steps;

  /* End of MinMax: '<S7>/MinMax' */

  /* DataTypeConversion: '<S268>/Data Type Conversion2' */
  gbyk_v4b_B.DataTypeConversion2 = gbyk_v4b_B.z;

  /* MATLAB Function: '<S268>/Hold_to_1Khz' */
  /* MATLAB Function 'GUI Control/Run Command Subsystem/Hold_to_1Khz': '<S274>:1' */
  /*  This block determines the run_command input of the task execution control */
  /*  subsystem (y), as well as the value of the task control button Goto (z). */
  /* How many time steps does the value need to be held in order to make a 1 */
  /* kHz signal? This will normally be 2 or 4. */
  /* '<S274>:1:9' */
  hold_steps = 0.001 / gbyk_v4b_P.Hold_to_1Khz_BKIN_STEP_TIME;
  if (gbyk_v4b_B.DataTypeConversion2 != 0.0) {
    /* '<S274>:1:18' */
    if (1.0 > hold_steps) {
      khi = 0;
    } else {
      khi = (int32_T)hold_steps;
    }

    for (i = 0; i < khi; i++) {
      c_data[i] = i;
    }

    /* '<S274>:1:19' */
    for (i = 0; i < khi; i++) {
      gbyk_v4b_DW.held_value[c_data[i]] = gbyk_v4b_B.DataTypeConversion2;
    }
  }

  /* '<S274>:1:22' */
  gbyk_v4b_B.value = gbyk_v4b_DW.held_value[0];

  /* '<S274>:1:23' */
  for (i = 0; i < 7; i++) {
    tmp[i] = gbyk_v4b_DW.held_value[1 + i];
  }

  for (i = 0; i < 7; i++) {
    gbyk_v4b_DW.held_value[i] = tmp[i];
  }

  /* '<S274>:1:24' */
  gbyk_v4b_DW.held_value[7] = 0.0;

  /* End of MATLAB Function: '<S268>/Hold_to_1Khz' */

  /* Selector: '<S7>/TP Selector' incorporates:
   *  Constant: '<S7>/TP Table'
   */
  i = (int32_T)gbyk_v4b_B.MinMax;
  for (idx_sizes = 0; idx_sizes < 50; idx_sizes++) {
    gbyk_v4b_B.TPSelector[idx_sizes] = gbyk_v4b_P.TPTable_Value[(50 * idx_sizes
      + i) - 1];
  }

  /* End of Selector: '<S7>/TP Selector' */

  /* DataTypeConversion: '<S7>/Convert1' incorporates:
   *  Constant: '<S7>/Target Labels'
   */
  memcpy(&gbyk_v4b_B.Convert1[0], &gbyk_v4b_P.TargetLabels_Value[0], 5000U *
         sizeof(real_T));

  /* DataTypeConversion: '<S7>/Convert10' incorporates:
   *  Constant: '<S7>/Display Size (pels)'
   */
  gbyk_v4b_B.Convert10[0] = gbyk_v4b_P.DisplaySizepels_Value[0];
  gbyk_v4b_B.Convert10[1] = gbyk_v4b_P.DisplaySizepels_Value[1];

  /* DataTypeConversion: '<S7>/Convert11' incorporates:
   *  Constant: '<S7>/Docking Points'
   */
  memcpy(&gbyk_v4b_B.Convert11[0], &gbyk_v4b_P.DockingPoints_Value[0], 10U *
         sizeof(real_T));

  /* DataTypeConversion: '<S7>/Convert12' incorporates:
   *  Constant: '<S7>/EL Camera Focal Length'
   */
  gbyk_v4b_B.Convert12 = gbyk_v4b_P.ELCameraFocalLength_Value_b;

  /* DataTypeConversion: '<S7>/Convert13' incorporates:
   *  Constant: '<S7>/EL Camera Position'
   */
  gbyk_v4b_B.Convert13[0] = gbyk_v4b_P.ELCameraPosition_Value_k[0];
  gbyk_v4b_B.Convert13[1] = gbyk_v4b_P.ELCameraPosition_Value_k[1];
  gbyk_v4b_B.Convert13[2] = gbyk_v4b_P.ELCameraPosition_Value_k[2];

  /* DataTypeConversion: '<S7>/Convert14' incorporates:
   *  Constant: '<S7>/EL Camera Angle'
   */
  gbyk_v4b_B.Convert14[0] = gbyk_v4b_P.ELCameraAngle_Value_h[0];
  gbyk_v4b_B.Convert14[1] = gbyk_v4b_P.ELCameraAngle_Value_h[1];

  /* DataTypeConversion: '<S7>/Convert15' incorporates:
   *  Constant: '<S7>/EL Tracking Available'
   */
  gbyk_v4b_B.Convert15 = gbyk_v4b_P.ELTrackingAvailable_Value_a;

  /* DataTypeConversion: '<S7>/Convert7' incorporates:
   *  Constant: '<S7>/Subject Height'
   */
  gbyk_v4b_B.Convert7 = gbyk_v4b_P.SubjectHeight_Value;

  /* DataTypeConversion: '<S7>/Convert8' incorporates:
   *  Constant: '<S7>/Subject Weight'
   */
  gbyk_v4b_B.Convert8 = gbyk_v4b_P.SubjectWeight_Value;

  /* DataTypeConversion: '<S7>/Convert9' incorporates:
   *  Constant: '<S7>/Display Size (m)'
   */
  gbyk_v4b_B.Convert9[0] = gbyk_v4b_P.DisplaySizem_Value[0];
  gbyk_v4b_B.Convert9[1] = gbyk_v4b_P.DisplaySizem_Value[1];

  /* Constant: '<S7>/Target Table' */
  memcpy(&gbyk_v4b_B.TargetTable[0], &gbyk_v4b_P.TargetTable_Value[0], 800U *
         sizeof(real_T));

  /* Outputs for Atomic SubSystem: '<S7>/Preview Targets Subsystem' */
  gbyk_v4b_PreviewTargetsSubsystem();

  /* End of Outputs for SubSystem: '<S7>/Preview Targets Subsystem' */

  /* Constant: '<S7>/Load Table' */
  memcpy(&gbyk_v4b_B.LoadTable[0], &gbyk_v4b_P.LoadTable_Value[0], 200U * sizeof
         (real_T));

  /* Constant: '<S7>/Task wide param' */
  memcpy(&gbyk_v4b_B.Taskwideparam[0], &gbyk_v4b_P.Taskwideparam_Value[0], 50U *
         sizeof(real_T));

  /* Constant: '<S7>/frame_of_reference_center' */
  gbyk_v4b_B.frame_of_reference_center[0] =
    gbyk_v4b_P.frame_of_reference_center_Value[0];
  gbyk_v4b_B.frame_of_reference_center[1] =
    gbyk_v4b_P.frame_of_reference_center_Value[1];

  /* Constant: '<S7>/Library Patch Version' */
  gbyk_v4b_B.LibraryPatchVersion = gbyk_v4b_P.LibraryPatchVersion_Value;

  /* Constant: '<S7>/Library Version' */
  gbyk_v4b_B.LibraryVersion = gbyk_v4b_P.LibraryVersion_Value;

  /* Constant: '<S7>/Task Version' */
  gbyk_v4b_B.TaskVersion = gbyk_v4b_P.TaskVersion_Value;

  /* Constant: '<S7>/xPC Version' */
  gbyk_v4b_B.xPCVersion = gbyk_v4b_P.xPCVersion_Value;

  /* Constant: '<S7>/dlm build time' */
  gbyk_v4b_B.dlmbuildtime = gbyk_v4b_P.dlmbuildtime_Value;

  /* MATLAB Function: '<S270>/MATLAB Function' */
  /* MATLAB Function 'GUI Control/Task_progress/MATLAB Function': '<S277>:1' */
  /*  persistent total_trials_added last_trial_in_block  */
  /*  persistent trials_added_in_block last_block_in_exam */
  /*   */
  /*  if isempty(total_trials_added) */
  /*      total_trials_added = 0; */
  /*      last_trial_in_block = uint32(0); */
  /*      trials_added_in_block = 0; */
  /*      last_block_in_exam = uint32(0); */
  /*  end */
  /*   */
  /*  if last_trial_in_block ~= trial_in_block && repeat_last_trial */
  /*      total_trials_added = total_trials_added + 1; */
  /*      trials_added_in_block = trials_added_in_block + 1; */
  /*  end */
  /*   */
  /*  if last_block_in_exam ~= block_in_set */
  /*      trials_added_in_block = 0; */
  /*  end */
  /*   */
  /*  last_trial_in_block = trial_in_block; */
  /*  last_block_in_exam = block_in_set; */
  /* '<S277>:1:26' */
  reps2 = gbyk_v4b_B.extra_trials[0];

  /* '<S277>:1:27' */
  reps3 = 0.0;

  /* '<S277>:1:29' */
  for (khi = 0; khi < 1000; khi++) {
    /* '<S277>:1:29' */
    if (!(gbyk_v4b_B.BlockSequence[1000 + khi] == 0.0)) {
      /* '<S277>:1:34' */
      for (i = 0; i < 499; i++) {
        x[i] = (gbyk_v4b_B.BlockDefinitions[(1 + i) * 50 + khi] != 0.0);
      }

      hold_steps = x[0];
      for (n1d = 0; n1d < 498; n1d++) {
        hold_steps += (real_T)x[n1d + 1];
      }

      /* '<S277>:1:35' */
      reps2 += gbyk_v4b_B.BlockSequence[1000 + khi] * hold_steps;

      /* '<S277>:1:36' */
      reps3 += gbyk_v4b_B.BlockSequence[1000 + khi];
    } else {
      /* '<S277>:1:30' */
    }

    /* '<S277>:1:29' */
  }

  /* '<S277>:1:39' */
  i = (int32_T)gbyk_v4b_B.Convert23;
  for (idx_sizes = 0; idx_sizes < 499; idx_sizes++) {
    x[idx_sizes] = (gbyk_v4b_B.BlockDefinitions[((1 + idx_sizes) * 50 + i) - 1]
                    != 0.0);
  }

  hold_steps = x[0];
  for (i = 0; i < 498; i++) {
    hold_steps += (real_T)x[i + 1];
  }

  gbyk_v4b_B.total_trials = reps2;
  gbyk_v4b_B.trials_in_block = hold_steps + gbyk_v4b_B.extra_trials[0];
  gbyk_v4b_B.total_blocks = reps3;

  /* End of MATLAB Function: '<S270>/MATLAB Function' */

  /* DataTypeConversion: '<S270>/Data Type Conversion' */
  stroke_width_col = floor(gbyk_v4b_B.total_trials);
  if (rtIsNaN(stroke_width_col) || rtIsInf(stroke_width_col)) {
    stroke_width_col = 0.0;
  } else {
    stroke_width_col = fmod(stroke_width_col, 4.294967296E+9);
  }

  gbyk_v4b_B.total_trials_in_exam = stroke_width_col < 0.0 ? (uint32_T)-(int32_T)
    (uint32_T)-stroke_width_col : (uint32_T)stroke_width_col;

  /* End of DataTypeConversion: '<S270>/Data Type Conversion' */

  /* DataTypeConversion: '<S270>/Data Type Conversion1' */
  stroke_width_col = floor(gbyk_v4b_B.trials_in_block);
  if (rtIsNaN(stroke_width_col) || rtIsInf(stroke_width_col)) {
    stroke_width_col = 0.0;
  } else {
    stroke_width_col = fmod(stroke_width_col, 4.294967296E+9);
  }

  gbyk_v4b_B.total_trials_in_block = stroke_width_col < 0.0 ? (uint32_T)
    -(int32_T)(uint32_T)-stroke_width_col : (uint32_T)stroke_width_col;

  /* End of DataTypeConversion: '<S270>/Data Type Conversion1' */

  /* DataTypeConversion: '<S270>/Data Type Conversion2' */
  stroke_width_col = floor(gbyk_v4b_B.total_blocks);
  if (rtIsNaN(stroke_width_col) || rtIsInf(stroke_width_col)) {
    stroke_width_col = 0.0;
  } else {
    stroke_width_col = fmod(stroke_width_col, 4.294967296E+9);
  }

  gbyk_v4b_B.total_blocks_in_exam = stroke_width_col < 0.0 ? (uint32_T)-(int32_T)
    (uint32_T)-stroke_width_col : (uint32_T)stroke_width_col;

  /* End of DataTypeConversion: '<S270>/Data Type Conversion2' */

  /* DataTypeConversion: '<S30>/Run Status' */
  gbyk_v4b_B.RunStatus = gbyk_v4b_B.Convert20;

  /* RateTransition: '<S30>/Rate Transition10' */
  if (gbyk_v4b_M->Timing.RateInteraction.TID1_3) {
    gbyk_v4b_B.RateTransition10 = gbyk_v4b_B.RunStatus;
  }

  /* End of RateTransition: '<S30>/Rate Transition10' */

  /* RelationalOperator: '<S45>/Compare' incorporates:
   *  Constant: '<S45>/Constant'
   */
  gbyk_v4b_B.Compare = (uint8_T)(gbyk_v4b_B.Convert20 ==
    gbyk_v4b_P.IfRunning_const);

  /* Selector: '<Root>/Selector2' */
  gbyk_v4b_B.Selector2 = gbyk_v4b_B.BlockSequence[(int32_T)gbyk_v4b_B.Convert23
    + 999];

  /* Selector: '<Root>/Selector3' */
  i = (int32_T)gbyk_v4b_B.Convert23;
  for (idx_sizes = 0; idx_sizes < 499; idx_sizes++) {
    gbyk_v4b_B.Selector3[idx_sizes] = gbyk_v4b_B.BlockDefinitions[((1 +
      idx_sizes) * 50 + i) - 1];
  }

  /* End of Selector: '<Root>/Selector3' */

  /* MATLAB Function: '<Root>/MATLAB Function' */
  /* MATLAB Function 'MATLAB Function': '<S12>:1' */
  /* '<S12>:1:4' */
  gbyk_v4b_nonzeros(gbyk_v4b_B.Selector3, BlockDef_data, &BlockDef_sizes);

  /* BlockDef = BlockDef(2:end); */
  /* '<S12>:1:7' */
  gbyk_v4b_eml_sort_idx(BlockDef_data, BlockDef_sizes, idx_data, &idx_sizes);
  b_idx_0 = (int16_T)BlockDef_sizes;
  idx_sizes = b_idx_0;
  for (n1d = 0; n1d + 1 <= BlockDef_sizes; n1d++) {
    trials_data[n1d] = BlockDef_data[idx_data[n1d] - 1];
  }

  gbyk_v4b_count_nonfinites(trials_data, BlockDef_sizes, &i, &khi, &n2d, &n1);
  idx_sizes = -1;
  if (i > 0) {
    idx_sizes = 0;
  }

  khi += i;
  while (i + 1 <= khi) {
    reps2 = trials_data[i];
    do {
      n1d = 0;
      i++;
      if (i + 1 > khi) {
        n1d = 1;
      } else {
        hold_steps = fabs(reps2 / 2.0);
        if ((!rtIsInf(hold_steps)) && (!rtIsNaN(hold_steps))) {
          if (hold_steps <= 2.2250738585072014E-308) {
            hold_steps = 4.94065645841247E-324;
          } else {
            frexp(hold_steps, &exponent);
            hold_steps = ldexp(1.0, exponent - 53);
          }
        } else {
          hold_steps = (rtNaN);
        }

        zcEvent_idx_0 = ((fabs(reps2 - trials_data[i]) < hold_steps) || (rtIsInf
          (trials_data[i]) && rtIsInf(reps2) && ((trials_data[i] > 0.0) ==
          (reps2 > 0.0))));
        if (!zcEvent_idx_0) {
          n1d = 1;
        }
      }
    } while (n1d == 0);

    idx_sizes++;
    trials_data[idx_sizes] = reps2;
  }

  if (n2d > 0) {
    idx_sizes++;
    trials_data[idx_sizes] = trials_data[khi];
  }

  i = khi + n2d;
  for (khi = 1; khi <= n1; khi++) {
    idx_sizes++;
    trials_data[idx_sizes] = trials_data[(i + khi) - 1];
  }

  /* '<S12>:1:8' */
  reps3 = trials_data[0];
  for (i = 0; i < BlockDef_sizes; i++) {
    x[i] = (BlockDef_data[i] == reps3);
  }

  hold_steps = gbyk_v4b_sum(x, BlockDef_sizes);

  /* '<S12>:1:9' */
  reps3 = trials_data[1];
  for (i = 0; i < BlockDef_sizes; i++) {
    x[i] = (BlockDef_data[i] == reps3);
  }

  reps2 = gbyk_v4b_sum(x, BlockDef_sizes);

  /* '<S12>:1:10' */
  reps3 = trials_data[2];
  for (i = 0; i < BlockDef_sizes; i++) {
    x[i] = (BlockDef_data[i] == reps3);
  }

  reps3 = gbyk_v4b_sum(x, BlockDef_sizes);

  /* '<S12>:1:11' */
  hold_steps_0[0] = hold_steps;
  hold_steps_0[1] = reps2;
  hold_steps_0[2] = reps3;
  gbyk_v4b_B.ListReps = rt_roundd_snf(gbyk_v4b_mean(hold_steps_0));

  /* End of MATLAB Function: '<Root>/MATLAB Function' */

  /* Product: '<Root>/Product' */
  gbyk_v4b_B.Product = gbyk_v4b_B.Selector2 * gbyk_v4b_B.ListReps;

  /* Outputs for Atomic SubSystem: '<S4>/Receive_Gaze' */
  gbyk_v4b_Receive_GazeTID0();

  /* End of Outputs for SubSystem: '<S4>/Receive_Gaze' */

  /* Memory: '<S4>/Memory' */
  gbyk_v4b_B.Memory[0] = gbyk_v4b_DW.Memory_PreviousInput[0];
  gbyk_v4b_B.Memory[1] = gbyk_v4b_DW.Memory_PreviousInput[1];
  gbyk_v4b_B.Memory[2] = gbyk_v4b_DW.Memory_PreviousInput[2];
  gbyk_v4b_B.Memory[3] = gbyk_v4b_DW.Memory_PreviousInput[3];

  /* Memory: '<S15>/Memory' */
  gbyk_v4b_B.Memory_k = gbyk_v4b_DW.Memory_PreviousInput_c;

  /* Gain: '<S15>/Gain' */
  gbyk_v4b_B.Gain = gbyk_v4b_P.Gain_Gain_a * gbyk_v4b_B.Memory_k;

  /* Outputs for Atomic SubSystem: '<S4>/Poll KINARM' */
  gbyk_v4b_PollKINARM();

  /* End of Outputs for SubSystem: '<S4>/Poll KINARM' */

  /* Selector: '<S11>/Dominant_Arm' */
  gbyk_v4b_B.Dominant_Arm = gbyk_v4b_B.kinarm_data[2];

  /* MATLAB Function: '<S11>/Embedded MATLAB WhichHand' incorporates:
   *  Constant: '<S11>/Use_Dominant_Hand?'
   */
  gbyk_v4b_EmbeddedMATLABWhichHand
    (gbyk_v4b_P.KINARM_HandInTarget_use_dominant_hand, gbyk_v4b_B.Dominant_Arm,
     &gbyk_v4b_B.sf_EmbeddedMATLABWhichHand);

  /* Selector: '<S11>/Hand_Pos' */
  for (i = 0; i < 2; i++) {
    gbyk_v4b_B.Hand_Pos[3 * i] = gbyk_v4b_B.kinarm_data[(22 + i) * 3];
    gbyk_v4b_B.Hand_Pos[1 + 3 * i] = gbyk_v4b_B.kinarm_data[(22 + i) * 3 + 1];
    gbyk_v4b_B.Hand_Pos[2 + 3 * i] = gbyk_v4b_B.kinarm_data[(22 + i) * 3 + 2];
  }

  /* End of Selector: '<S11>/Hand_Pos' */

  /* MultiPortSwitch: '<S11>/Multiport Switch' */
  if ((int32_T)gbyk_v4b_B.sf_EmbeddedMATLABWhichHand.hand == 1) {
    /* Selector: '<S11>/Arm1' */
    gbyk_v4b_B.Arm1[0] = gbyk_v4b_B.Hand_Pos[0];
    gbyk_v4b_B.Arm1[1] = gbyk_v4b_B.Hand_Pos[3];
    gbyk_v4b_B.MultiportSwitch[0] = gbyk_v4b_B.Arm1[0];
    gbyk_v4b_B.MultiportSwitch[1] = gbyk_v4b_B.Arm1[1];
  } else {
    /* Selector: '<S11>/Arm2' */
    gbyk_v4b_B.Arm2[0] = gbyk_v4b_B.Hand_Pos[1];
    gbyk_v4b_B.Arm2[1] = gbyk_v4b_B.Hand_Pos[4];
    gbyk_v4b_B.MultiportSwitch[0] = gbyk_v4b_B.Arm2[0];
    gbyk_v4b_B.MultiportSwitch[1] = gbyk_v4b_B.Arm2[1];
  }

  /* End of MultiPortSwitch: '<S11>/Multiport Switch' */

  /* MATLAB Function: '<S11>/Embedded MATLAB InsideTarget' */
  gbyk_v4b_EmbeddedMATLABInsideTarget_m();

  /* Selector: '<S11>/Array Selector' incorporates:
   *  Constant: '<S11>/Selected States'
   */
  i = (int32_T)gbyk_v4b_P.SelectedStates_Value;
  memcpy(&gbyk_v4b_B.ArraySelector[0], &gbyk_v4b_B.intarget[(i - 1) << 5],
         sizeof(real_T) << 5U);

  /* Selector: '<S9>/Dominant_Arm' */
  gbyk_v4b_B.Dominant_Arm_k = gbyk_v4b_B.kinarm_data[2];

  /* MATLAB Function: '<S9>/Embedded MATLAB WhichHand' incorporates:
   *  Constant: '<S9>/Use_Dominant_Hand?'
   */
  gbyk_v4b_EmbeddedMATLABWhichHand
    (gbyk_v4b_P.KINARM_DistanceFromTarget_use_dominant_hand,
     gbyk_v4b_B.Dominant_Arm_k, &gbyk_v4b_B.sf_EmbeddedMATLABWhichHand_d);

  /* Selector: '<S9>/Hand_Pos' */
  for (i = 0; i < 2; i++) {
    gbyk_v4b_B.Hand_Pos_i[3 * i] = gbyk_v4b_B.kinarm_data[(22 + i) * 3];
    gbyk_v4b_B.Hand_Pos_i[1 + 3 * i] = gbyk_v4b_B.kinarm_data[(22 + i) * 3 + 1];
    gbyk_v4b_B.Hand_Pos_i[2 + 3 * i] = gbyk_v4b_B.kinarm_data[(22 + i) * 3 + 2];
  }

  /* End of Selector: '<S9>/Hand_Pos' */

  /* MultiPortSwitch: '<S9>/Multiport Switch' */
  if ((int32_T)gbyk_v4b_B.sf_EmbeddedMATLABWhichHand_d.hand == 1) {
    /* Selector: '<S9>/Arm1' */
    gbyk_v4b_B.Arm1_a[0] = gbyk_v4b_B.Hand_Pos_i[0];
    gbyk_v4b_B.Arm1_a[1] = gbyk_v4b_B.Hand_Pos_i[3];
    gbyk_v4b_B.MultiportSwitch_c[0] = gbyk_v4b_B.Arm1_a[0];
    gbyk_v4b_B.MultiportSwitch_c[1] = gbyk_v4b_B.Arm1_a[1];
  } else {
    /* Selector: '<S9>/Arm2' */
    gbyk_v4b_B.Arm2_j[0] = gbyk_v4b_B.Hand_Pos_i[1];
    gbyk_v4b_B.Arm2_j[1] = gbyk_v4b_B.Hand_Pos_i[4];
    gbyk_v4b_B.MultiportSwitch_c[0] = gbyk_v4b_B.Arm2_j[0];
    gbyk_v4b_B.MultiportSwitch_c[1] = gbyk_v4b_B.Arm2_j[1];
  }

  /* End of MultiPortSwitch: '<S9>/Multiport Switch' */

  /* MATLAB Function: '<S9>/Embedded MATLAB InsideTarget' */
  /* MATLAB Function 'KINARM_DistanceFromTarget/Embedded MATLAB InsideTarget': '<S279>:1' */
  /*  all dimensions in m, rad */
  /*  arguments: */
  /*  handpos: x,y positions of center of target */
  /* '<S279>:1:8' */
  /* '<S279>:1:9' */
  /* '<S279>:1:11' */
  /* Target Table sizes in cm in v1.4 */
  /* '<S279>:1:12' */
  /* Target Table sizes in cm in v1.4 */
  /* '<S279>:1:14' */
  stroke_width_col = gbyk_v4b_B.MultiportSwitch_c[0];
  stroke_colour_col = gbyk_v4b_B.MultiportSwitch_c[1];
  for (i = 0; i < 32; i++) {
    reps3 = gbyk_v4b_B.TargetTable[i] * 0.01 - stroke_width_col;
    gbyk_v4b_B.distance[i] = reps3 * reps3;
    reps3 = gbyk_v4b_B.TargetTable[32 + i] * 0.01 - stroke_colour_col;
    reps3 *= reps3;
    gbyk_v4b_B.distance[i] += reps3;
    gbyk_v4b_B.distance[i] = sqrt(gbyk_v4b_B.distance[i]);
  }

  /* End of MATLAB Function: '<S9>/Embedded MATLAB InsideTarget' */

  /* Switch: '<Root>/Switch1' */
  if (gbyk_v4b_B.active_arm > gbyk_v4b_P.Switch1_Threshold_e) {
    gbyk_v4b_B.Switch1[0] = gbyk_v4b_B.hand_position[0];
    gbyk_v4b_B.Switch1[1] = gbyk_v4b_B.hand_position[1];
  } else {
    gbyk_v4b_B.Switch1[0] = gbyk_v4b_B.hand_position_g[0];
    gbyk_v4b_B.Switch1[1] = gbyk_v4b_B.hand_position_g[1];
  }

  /* End of Switch: '<Root>/Switch1' */

  /* Switch: '<Root>/Switch' */
  if (gbyk_v4b_B.active_arm > gbyk_v4b_P.Switch_Threshold_f) {
    gbyk_v4b_B.Switch[0] = gbyk_v4b_B.hand_velocity[0];
    gbyk_v4b_B.Switch[1] = gbyk_v4b_B.hand_velocity[1];
  } else {
    gbyk_v4b_B.Switch[0] = gbyk_v4b_B.hand_velocity_p[0];
    gbyk_v4b_B.Switch[1] = gbyk_v4b_B.hand_velocity_p[1];
  }

  /* End of Switch: '<Root>/Switch' */

  /* Math: '<Root>/Math Function' */
  gbyk_v4b_B.MathFunction[0] = gbyk_v4b_B.Switch[0] * gbyk_v4b_B.Switch[0];
  gbyk_v4b_B.MathFunction[1] = gbyk_v4b_B.Switch[1] * gbyk_v4b_B.Switch[1];

  /* Sum: '<Root>/Sum of Elements' */
  hold_steps = gbyk_v4b_B.MathFunction[0];
  hold_steps += gbyk_v4b_B.MathFunction[1];
  gbyk_v4b_B.SumofElements = hold_steps;

  /* Sqrt: '<Root>/Sqrt' */
  gbyk_v4b_B.Sqrt = sqrt(gbyk_v4b_B.SumofElements);

  /* Selector: '<S10>/Dominant_Arm' */
  gbyk_v4b_B.Dominant_Arm_o = gbyk_v4b_B.kinarm_data[2];

  /* MATLAB Function: '<S10>/Embedded MATLAB WhichHand' incorporates:
   *  Constant: '<S10>/Use_Dominant_Hand?'
   */
  gbyk_v4b_EmbeddedMATLABWhichHand(gbyk_v4b_P.KINARM_HandInBox_use_dominant_hand,
    gbyk_v4b_B.Dominant_Arm_o, &gbyk_v4b_B.sf_EmbeddedMATLABWhichHand_k);

  /* Selector: '<S10>/Hand_Pos' */
  for (i = 0; i < 2; i++) {
    gbyk_v4b_B.Hand_Pos_n[3 * i] = gbyk_v4b_B.kinarm_data[(22 + i) * 3];
    gbyk_v4b_B.Hand_Pos_n[1 + 3 * i] = gbyk_v4b_B.kinarm_data[(22 + i) * 3 + 1];
    gbyk_v4b_B.Hand_Pos_n[2 + 3 * i] = gbyk_v4b_B.kinarm_data[(22 + i) * 3 + 2];
  }

  /* End of Selector: '<S10>/Hand_Pos' */

  /* MultiPortSwitch: '<S10>/Multiport Switch' */
  if ((int32_T)gbyk_v4b_B.sf_EmbeddedMATLABWhichHand_k.hand == 1) {
    /* Selector: '<S10>/Arm1' */
    gbyk_v4b_B.Arm1_p[0] = gbyk_v4b_B.Hand_Pos_n[0];
    gbyk_v4b_B.Arm1_p[1] = gbyk_v4b_B.Hand_Pos_n[3];
    gbyk_v4b_B.MultiportSwitch_b[0] = gbyk_v4b_B.Arm1_p[0];
    gbyk_v4b_B.MultiportSwitch_b[1] = gbyk_v4b_B.Arm1_p[1];
  } else {
    /* Selector: '<S10>/Arm2' */
    gbyk_v4b_B.Arm2_o[0] = gbyk_v4b_B.Hand_Pos_n[1];
    gbyk_v4b_B.Arm2_o[1] = gbyk_v4b_B.Hand_Pos_n[4];
    gbyk_v4b_B.MultiportSwitch_b[0] = gbyk_v4b_B.Arm2_o[0];
    gbyk_v4b_B.MultiportSwitch_b[1] = gbyk_v4b_B.Arm2_o[1];
  }

  /* End of MultiPortSwitch: '<S10>/Multiport Switch' */

  /* MATLAB Function: '<S10>/Embedded MATLAB InsideTarget' */
  gbyk_v4b_EmbeddedMATLABInsideTarget();

  /* Selector: '<S10>/Array Selector' incorporates:
   *  Constant: '<S10>/Selected States'
   */
  i = (int32_T)gbyk_v4b_P.SelectedStates_Value_j;
  memcpy(&gbyk_v4b_B.ArraySelector_n[0], &gbyk_v4b_B.intarget_l[(i - 1) << 5],
         sizeof(real_T) << 5U);

  /* RelationalOperator: '<S3>/Compare' incorporates:
   *  Constant: '<S3>/Constant'
   */
  gbyk_v4b_B.Compare_k = (gbyk_v4b_B.value == gbyk_v4b_P.CompareToConstant_const);

  /* Chart: '<Root>/Trial_Control' incorporates:
   *  TriggerPort: '<S25>/ input events '
   */
  zcEvent_idx_0 = (((gbyk_v4b_PrevZCX.Trial_Control_Trig_ZCE[0] == POS_ZCSIG) !=
                    gbyk_v4b_B.DataTypeConversion1_m) &&
                   (gbyk_v4b_PrevZCX.Trial_Control_Trig_ZCE[0] !=
                    UNINITIALIZED_ZCSIG));
  zcEvent_idx_1 = (((gbyk_v4b_PrevZCX.Trial_Control_Trig_ZCE[1] == POS_ZCSIG) !=
                    gbyk_v4b_B.e_exit_trial) &&
                   (gbyk_v4b_PrevZCX.Trial_Control_Trig_ZCE[1] !=
                    UNINITIALIZED_ZCSIG));
  zcEvent_idx_2 = (((gbyk_v4b_PrevZCX.Trial_Control_Trig_ZCE[2] == POS_ZCSIG) !=
                    gbyk_v4b_B.Compare_k) &&
                   (gbyk_v4b_PrevZCX.Trial_Control_Trig_ZCE[2] !=
                    UNINITIALIZED_ZCSIG));
  tmp_0 = zcEvent_idx_0;
  tmp_0 = (tmp_0 || zcEvent_idx_1);
  tmp_0 = (tmp_0 || zcEvent_idx_2);
  if (tmp_0) {
    gbyk_v4b_B.inputevents[0] = (int8_T)(zcEvent_idx_0 ?
      gbyk_v4b_B.DataTypeConversion1_m ? RISING_ZCEVENT : FALLING_ZCEVENT :
      NO_ZCEVENT);
    gbyk_v4b_B.inputevents[1] = (int8_T)(zcEvent_idx_1 ? gbyk_v4b_B.e_exit_trial
      ? RISING_ZCEVENT : FALLING_ZCEVENT : NO_ZCEVENT);
    gbyk_v4b_B.inputevents[2] = (int8_T)(zcEvent_idx_2 ? gbyk_v4b_B.Compare_k ?
      RISING_ZCEVENT : FALLING_ZCEVENT : NO_ZCEVENT);

    /* Gateway: Trial_Control */
    khi = 0;
    if (gbyk_v4b_B.inputevents[0U] == 1) {
      khi = 1;
      if (gbyk_v4b_DW.temporalCounter_i1 < MAX_uint32_T) {
        gbyk_v4b_DW.temporalCounter_i1++;
      }

      /* Event: '<S25>:42' */
      gbyk_v4b_DW.sfEvent = gbyk_v4b_event_e_clk_i;
      gbyk_v4b_chartstep_c1_gbyk_v4b();
    }

    if (gbyk_v4b_B.inputevents[1U] != 0) {
      khi = 1;

      /* Event: '<S25>:43' */
      gbyk_v4b_DW.sfEvent = gbyk_v4b_event_e_ExitTrialNow;
      gbyk_v4b_chartstep_c1_gbyk_v4b();
    }

    if (gbyk_v4b_B.inputevents[2U] != 0) {
      khi = 1;

      /* Event: '<S25>:93' */
      gbyk_v4b_DW.sfEvent = gbyk_v4b_event_e_cntl_btn;
      gbyk_v4b_chartstep_c1_gbyk_v4b();
    }

    if ((khi != 0) && (gbyk_v4b_DW.e_Trial_EndEventCounter > 0U)) {
      gbyk_v4b_B.e_Trial_End = !gbyk_v4b_B.e_Trial_End;
      gbyk_v4b_DW.e_Trial_EndEventCounter--;
    }

    gbyk_v4b_DW.Trial_Control_SubsysRanBC = 4;
  }

  gbyk_v4b_PrevZCX.Trial_Control_Trig_ZCE[0] = gbyk_v4b_B.DataTypeConversion1_m;
  gbyk_v4b_PrevZCX.Trial_Control_Trig_ZCE[1] = gbyk_v4b_B.e_exit_trial;
  gbyk_v4b_PrevZCX.Trial_Control_Trig_ZCE[2] = gbyk_v4b_B.Compare_k;

  /* Product: '<S30>/Product' */
  gbyk_v4b_B.Product_g[0] = (real_T)gbyk_v4b_B.Compare *
    gbyk_v4b_B.logging_enable[0];
  gbyk_v4b_B.Product_g[1] = (real_T)gbyk_v4b_B.Compare *
    gbyk_v4b_B.logging_enable[1];

  /* DataTypeConversion: '<S30>/Logging Enable' */
  gbyk_v4b_B.LoggingEnable[0] = gbyk_v4b_B.Product_g[0];
  gbyk_v4b_B.LoggingEnable[1] = gbyk_v4b_B.Product_g[1];

  /* RateTransition: '<S30>/Rate Transition9' */
  if (gbyk_v4b_M->Timing.RateInteraction.TID1_3) {
    gbyk_v4b_B.RateTransition9[0] = gbyk_v4b_B.LoggingEnable[0];
    gbyk_v4b_B.RateTransition9[1] = gbyk_v4b_B.LoggingEnable[1];
  }

  /* End of RateTransition: '<S30>/Rate Transition9' */

  /* DataTypeConversion: '<S30>/Current TP Index' */
  gbyk_v4b_B.CurrentTPIndex = gbyk_v4b_B.Convert24;

  /* RateTransition: '<S30>/Rate Transition8' */
  if (gbyk_v4b_M->Timing.RateInteraction.TID1_3) {
    gbyk_v4b_B.RateTransition8 = gbyk_v4b_B.CurrentTPIndex;
  }

  /* End of RateTransition: '<S30>/Rate Transition8' */

  /* DataTypeConversion: '<S30>/Current Block Index' */
  gbyk_v4b_B.CurrentBlockIndex = gbyk_v4b_B.Convert23;

  /* RateTransition: '<S30>/Rate Transition7' */
  if (gbyk_v4b_M->Timing.RateInteraction.TID1_3) {
    gbyk_v4b_B.RateTransition7 = gbyk_v4b_B.CurrentBlockIndex;
  }

  /* End of RateTransition: '<S30>/Rate Transition7' */

  /* DataTypeConversion: '<S30>/Current Trial Number in Block' */
  gbyk_v4b_B.CurrentTrialNumberinBlock = gbyk_v4b_B.Convert22;

  /* RateTransition: '<S30>/Rate Transition6' */
  if (gbyk_v4b_M->Timing.RateInteraction.TID1_3) {
    gbyk_v4b_B.RateTransition6 = gbyk_v4b_B.CurrentTrialNumberinBlock;
  }

  /* End of RateTransition: '<S30>/Rate Transition6' */

  /* DataTypeConversion: '<S30>/Current Block Number in Set' */
  gbyk_v4b_B.CurrentBlockNumberinSet = gbyk_v4b_B.Convert21;

  /* RateTransition: '<S30>/Rate Transition5' */
  if (gbyk_v4b_M->Timing.RateInteraction.TID1_3) {
    gbyk_v4b_B.RateTransition5 = gbyk_v4b_B.CurrentBlockNumberinSet;
  }

  /* End of RateTransition: '<S30>/Rate Transition5' */

  /* DataTypeConversion: '<S30>/Current Trial Number in Set' */
  gbyk_v4b_B.CurrentTrialNumberinSet = gbyk_v4b_B.Convert19_b;

  /* RateTransition: '<S30>/Rate Transition4' */
  if (gbyk_v4b_M->Timing.RateInteraction.TID1_3) {
    gbyk_v4b_B.RateTransition4 = gbyk_v4b_B.CurrentTrialNumberinSet;
  }

  /* End of RateTransition: '<S30>/Rate Transition4' */

  /* DataTypeConversion: '<S30>/Last Frame Sent1' */
  gbyk_v4b_B.LastFrameSent1 = gbyk_v4b_B.Convert25;

  /* RateTransition: '<S30>/Rate Transition12' */
  if (gbyk_v4b_M->Timing.RateInteraction.TID1_3) {
    gbyk_v4b_B.RateTransition12 = gbyk_v4b_B.LastFrameSent1;
  }

  /* End of RateTransition: '<S30>/Rate Transition12' */

  /* Selector: '<S24>/Selector' */
  i = (int32_T)gbyk_v4b_B.targetA_row;
  for (idx_sizes = 0; idx_sizes < 25; idx_sizes++) {
    gbyk_v4b_B.Selector[idx_sizes] = gbyk_v4b_B.TargetTable[((idx_sizes << 5) +
      i) - 1];
  }

  /* End of Selector: '<S24>/Selector' */

  /* Concatenate: '<S24>/Matrix Concatenation' incorporates:
   *  Constant: '<S24>/state1_indices'
   *  Constant: '<S24>/state2_indices'
   *  Constant: '<S24>/state3_indices'
   *  Constant: '<S24>/state4_indices'
   *  Constant: '<S24>/state5_indices'
   */
  tmp_1[0] = gbyk_v4b_P.Show_Target_A_attribcol1[0];
  tmp_1[5] = gbyk_v4b_P.Show_Target_A_attribcol1[1];
  tmp_1[10] = gbyk_v4b_P.Show_Target_A_attribcol1[2];
  tmp_1[15] = gbyk_v4b_P.Show_Target_A_attribcol1[3];
  tmp_1[1] = gbyk_v4b_P.Show_Target_A_attribcol2[0];
  tmp_1[6] = gbyk_v4b_P.Show_Target_A_attribcol2[1];
  tmp_1[11] = gbyk_v4b_P.Show_Target_A_attribcol2[2];
  tmp_1[16] = gbyk_v4b_P.Show_Target_A_attribcol2[3];
  tmp_1[2] = gbyk_v4b_P.state3_indices_Value[0];
  tmp_1[7] = gbyk_v4b_P.state3_indices_Value[1];
  tmp_1[12] = gbyk_v4b_P.state3_indices_Value[2];
  tmp_1[17] = gbyk_v4b_P.state3_indices_Value[3];
  tmp_1[3] = gbyk_v4b_P.state4_indices_Value[0];
  tmp_1[8] = gbyk_v4b_P.state4_indices_Value[1];
  tmp_1[13] = gbyk_v4b_P.state4_indices_Value[2];
  tmp_1[18] = gbyk_v4b_P.state4_indices_Value[3];
  tmp_1[4] = gbyk_v4b_P.state5_indices_Value[0];
  tmp_1[9] = gbyk_v4b_P.state5_indices_Value[1];
  tmp_1[14] = gbyk_v4b_P.state5_indices_Value[2];
  tmp_1[19] = gbyk_v4b_P.state5_indices_Value[3];
  memcpy(&gbyk_v4b_B.MatrixConcatenation1[0], &tmp_1[0], 20U * sizeof(real_T));

  /* Constant: '<S24>/padder' */
  memcpy(&gbyk_v4b_B.MatrixConcatenation1[20], &gbyk_v4b_P.padder_Value[0], 35U *
         sizeof(real_T));

  /* MATLAB Function: '<S24>/Embedded MATLAB Function' incorporates:
   *  Constant: '<S24>/Opacity'
   *  Constant: '<S24>/Target_Display'
   *  Constant: '<S24>/Target_Type'
   *  Constant: '<S24>/num_states'
   *  Constant: '<S24>/xpos_index'
   *  Constant: '<S24>/ypos_index'
   */
  gbyk_v4b_EmbeddedMATLABFunction(gbyk_v4b_B.Selector, gbyk_v4b_B.targetA_state,
    gbyk_v4b_P.Show_Target_A_target_type, gbyk_v4b_P.Show_Target_A_opacity,
    gbyk_v4b_P.Show_Target_A_target_display, gbyk_v4b_P.xpos_index_Value,
    gbyk_v4b_P.ypos_index_Value, gbyk_v4b_P.Show_Target_A_num_states,
    gbyk_v4b_B.MatrixConcatenation1, &gbyk_v4b_B.sf_EmbeddedMATLABFunction_i);

  /* Selector: '<S22>/Selector' */
  for (i = 0; i < 25; i++) {
    gbyk_v4b_B.Selector_l[i << 1] = gbyk_v4b_B.TargetTable[((i << 5) + (int32_T)
      gbyk_v4b_B.targetB_row[0]) - 1];
    gbyk_v4b_B.Selector_l[1 + (i << 1)] = gbyk_v4b_B.TargetTable[((i << 5) +
      (int32_T)gbyk_v4b_B.targetB_row[1]) - 1];
  }

  /* End of Selector: '<S22>/Selector' */

  /* Concatenate: '<S22>/Matrix Concatenation' incorporates:
   *  Constant: '<S22>/state1_indices'
   *  Constant: '<S22>/state2_indices'
   *  Constant: '<S22>/state3_indices'
   *  Constant: '<S22>/state4_indices'
   *  Constant: '<S22>/state5_indices'
   */
  for (i = 0; i < 7; i++) {
    tmp_2[5 * i] = gbyk_v4b_P.Show_TargetB_With_Label_attribcol1[i];
  }

  for (i = 0; i < 7; i++) {
    tmp_2[1 + 5 * i] = gbyk_v4b_P.Show_TargetB_With_Label_attribcol2[i];
  }

  for (i = 0; i < 7; i++) {
    tmp_2[2 + 5 * i] = gbyk_v4b_P.Show_TargetB_With_Label_attribcol3[i];
  }

  for (i = 0; i < 7; i++) {
    tmp_2[3 + 5 * i] = gbyk_v4b_P.state4_indices_Value_d[i];
  }

  for (i = 0; i < 7; i++) {
    tmp_2[4 + 5 * i] = gbyk_v4b_P.state5_indices_Value_i[i];
  }

  memcpy(&gbyk_v4b_B.MatrixConcatenation1_n[0], &tmp_2[0], 35U * sizeof(real_T));

  /* End of Concatenate: '<S22>/Matrix Concatenation' */

  /* Constant: '<S22>/padder' */
  memcpy(&gbyk_v4b_B.MatrixConcatenation1_n[35], &gbyk_v4b_P.padder_Value_b[0],
         20U * sizeof(real_T));

  /* MATLAB Function: '<S22>/Embedded MATLAB Function' incorporates:
   *  Constant: '<S22>/Opacity'
   *  Constant: '<S22>/Target_Display'
   *  Constant: '<S22>/Target_Type'
   *  Constant: '<S22>/num_states'
   *  Constant: '<S22>/xpos_index'
   *  Constant: '<S22>/ypos_index'
   */
  gbyk_v4b_EmbeddedMATLABFunction_k(gbyk_v4b_B.Selector_l,
    gbyk_v4b_B.targetB_state, gbyk_v4b_P.Show_TargetB_With_Label_target_type,
    gbyk_v4b_P.Show_TargetB_With_Label_opacity,
    gbyk_v4b_P.Show_TargetB_With_Label_target_display,
    gbyk_v4b_P.xpos_index_Value_d, gbyk_v4b_P.ypos_index_Value_b,
    gbyk_v4b_P.Show_TargetB_With_Label_num_states,
    gbyk_v4b_B.MatrixConcatenation1_n, gbyk_v4b_B.Convert1,
    &gbyk_v4b_B.sf_EmbeddedMATLABFunction_k);

  /* MATLAB Function: '<Root>/AddTxt2TgtB' */
  /* MATLAB Function 'AddTxt2TgtB': '<S1>:1' */
  /* '<S1>:1:4' */
  memcpy(&gbyk_v4b_B.VCODE_MOD_n[0],
         &gbyk_v4b_B.sf_EmbeddedMATLABFunction_k.VCODE[0], 140U * sizeof(real_T));

  /* rewards = rwd_multipliers*rwd_val; */
  /* '<S1>:1:8' */
  zcEvent_idx_0 = false;
  i = 0;
  zcEvent_idx_1 = false;
  while ((!zcEvent_idx_1) && (i < 2)) {
    zcEvent_idx_2 = ((gbyk_v4b_B.offeredRewards[i] == 0.0) || rtIsNaN
                     (gbyk_v4b_B.offeredRewards[i]));
    if (!zcEvent_idx_2) {
      zcEvent_idx_0 = true;
      zcEvent_idx_1 = true;
    } else {
      i++;
    }
  }

  if ((int32_T)zcEvent_idx_0 > 0) {
    /* '<S1>:1:10' */
    /* '<S1>:1:11' */
    n2d = 15;

    /* '<S1>:1:12' */
    if (gbyk_v4b_B.offeredRewards[0] < 10.0) {
      /* '<S1>:1:14' */
      /* '<S1>:1:15' */
      stroke_width_col = rt_roundd_snf(gbyk_v4b_B.offeredRewards[0] + 48.0);
      if (stroke_width_col < 2.147483648E+9) {
        if (stroke_width_col >= -2.147483648E+9) {
          i = (int32_T)stroke_width_col;
        } else {
          i = MIN_int32_T;
        }
      } else {
        i = MAX_int32_T;
      }

      gbyk_v4b_B.VCODE_MOD_n[28] = i;
    } else if (gbyk_v4b_B.offeredRewards[0] < 100.0) {
      /* '<S1>:1:17' */
      /* score < $1 */
      /* '<S1>:1:18' */
      stroke_width_col = rt_roundd_snf(floor(gbyk_v4b_B.offeredRewards[0] / 10.0));
      if (stroke_width_col < 2.147483648E+9) {
        if (stroke_width_col >= -2.147483648E+9) {
          n1 = (int32_T)stroke_width_col;
        } else {
          n1 = MIN_int32_T;
        }
      } else {
        n1 = MAX_int32_T;
      }

      /* we need to cast score to a double otherwise the arithmetic is wrong! */
      /* '<S1>:1:19' */
      /* '<S1>:1:21' */
      tmp_6 = n1 + 48LL;
      if (tmp_6 > 2147483647LL) {
        tmp_6 = 2147483647LL;
      } else {
        if (tmp_6 < -2147483648LL) {
          tmp_6 = -2147483648LL;
        }
      }

      gbyk_v4b_B.VCODE_MOD_n[28] = (int32_T)tmp_6;

      /* '<S1>:1:22' */
      n2d = 16;

      /* '<S1>:1:23' */
      tmp_6 = n1 * 10LL;
      if (tmp_6 > 2147483647LL) {
        tmp_6 = 2147483647LL;
      } else {
        if (tmp_6 < -2147483648LL) {
          tmp_6 = -2147483648LL;
        }
      }

      stroke_width_col = rt_roundd_snf(gbyk_v4b_B.offeredRewards[0] - (real_T)
        (int32_T)tmp_6);
      if (stroke_width_col < 2.147483648E+9) {
        if (stroke_width_col >= -2.147483648E+9) {
          i = (int32_T)stroke_width_col;
        } else {
          i = MIN_int32_T;
        }
      } else {
        i = MAX_int32_T;
      }

      tmp_6 = i + 48LL;
      if (tmp_6 > 2147483647LL) {
        tmp_6 = 2147483647LL;
      } else {
        if (tmp_6 < -2147483648LL) {
          tmp_6 = -2147483648LL;
        }
      }

      gbyk_v4b_B.VCODE_MOD_n[30] = (int32_T)tmp_6;
    } else {
      /* label < 1000 */
      /* '<S1>:1:25' */
      stroke_width_col = rt_roundd_snf(floor(gbyk_v4b_B.offeredRewards[0] /
        100.0));
      if (stroke_width_col < 2.147483648E+9) {
        if (stroke_width_col >= -2.147483648E+9) {
          n1 = (int32_T)stroke_width_col;
        } else {
          n1 = MIN_int32_T;
        }
      } else {
        n1 = MAX_int32_T;
      }

      /* we need to cast score to a double otherwise the arithmetic is wrong! */
      /* '<S1>:1:26' */
      /* '<S1>:1:27' */
      tmp_6 = n1 * 100LL;
      if (tmp_6 > 2147483647LL) {
        tmp_6 = 2147483647LL;
      } else {
        if (tmp_6 < -2147483648LL) {
          tmp_6 = -2147483648LL;
        }
      }

      stroke_width_col = rt_roundd_snf(gbyk_v4b_B.offeredRewards[0] - (real_T)
        (int32_T)tmp_6);
      if (stroke_width_col < 2.147483648E+9) {
        if (stroke_width_col >= -2.147483648E+9) {
          i = (int32_T)stroke_width_col;
        } else {
          i = MIN_int32_T;
        }
      } else {
        i = MAX_int32_T;
      }

      khi = (int32_T)floor((real_T)i / 100.0);

      /* we need to cast score to a double otherwise the arithmetic is wrong! */
      /* '<S1>:1:28' */
      /* '<S1>:1:30' */
      tmp_6 = n1 + 48LL;
      if (tmp_6 > 2147483647LL) {
        tmp_6 = 2147483647LL;
      } else {
        if (tmp_6 < -2147483648LL) {
          tmp_6 = -2147483648LL;
        }
      }

      gbyk_v4b_B.VCODE_MOD_n[28] = (int32_T)tmp_6;

      /* '<S1>:1:32' */
      gbyk_v4b_B.VCODE_MOD_n[30] = (real_T)khi + 48.0;

      /* '<S1>:1:33' */
      n2d = 17;

      /* '<S1>:1:34' */
      tmp_6 = n1 * 100LL;
      if (tmp_6 > 2147483647LL) {
        tmp_6 = 2147483647LL;
      } else {
        if (tmp_6 < -2147483648LL) {
          tmp_6 = -2147483648LL;
        }
      }

      stroke_width_col = rt_roundd_snf(gbyk_v4b_B.offeredRewards[0] - (real_T)
        (int32_T)tmp_6);
      if (stroke_width_col < 2.147483648E+9) {
        if (stroke_width_col >= -2.147483648E+9) {
          i = (int32_T)stroke_width_col;
        } else {
          i = MIN_int32_T;
        }
      } else {
        i = MAX_int32_T;
      }

      tmp_6 = (int64_T)i - khi * 10;
      if (tmp_6 > 2147483647LL) {
        tmp_6 = 2147483647LL;
      } else {
        if (tmp_6 < -2147483648LL) {
          tmp_6 = -2147483648LL;
        }
      }

      tmp_6 = (int32_T)tmp_6 + 48LL;
      if (tmp_6 > 2147483647LL) {
        tmp_6 = 2147483647LL;
      } else {
        if (tmp_6 < -2147483648LL) {
          tmp_6 = -2147483648LL;
        }
      }

      gbyk_v4b_B.VCODE_MOD_n[32] = (int32_T)tmp_6;
    }

    /* '<S1>:1:36' */
    gbyk_v4b_B.VCODE_MOD_n[n2d << 1] = 0.0;

    /* terminate string */
  } else {
    /* '<S1>:1:38' */
    gbyk_v4b_B.VCODE_MOD_n[28] = 0.0;

    /* terminate string */
  }

  /* '<S1>:1:8' */
  zcEvent_idx_0 = false;
  i = 0;
  zcEvent_idx_1 = false;
  while ((!zcEvent_idx_1) && (i < 2)) {
    zcEvent_idx_2 = ((gbyk_v4b_B.offeredRewards[i] == 0.0) || rtIsNaN
                     (gbyk_v4b_B.offeredRewards[i]));
    if (!zcEvent_idx_2) {
      zcEvent_idx_0 = true;
      zcEvent_idx_1 = true;
    } else {
      i++;
    }
  }

  if ((int32_T)zcEvent_idx_0 > 0) {
    /* '<S1>:1:10' */
    /* '<S1>:1:11' */
    n2d = 15;

    /* '<S1>:1:12' */
    if (gbyk_v4b_B.offeredRewards[1] < 10.0) {
      /* '<S1>:1:14' */
      /* '<S1>:1:15' */
      stroke_width_col = rt_roundd_snf(gbyk_v4b_B.offeredRewards[1] + 48.0);
      if (stroke_width_col < 2.147483648E+9) {
        if (stroke_width_col >= -2.147483648E+9) {
          i = (int32_T)stroke_width_col;
        } else {
          i = MIN_int32_T;
        }
      } else {
        i = MAX_int32_T;
      }

      gbyk_v4b_B.VCODE_MOD_n[29] = i;
    } else if (gbyk_v4b_B.offeredRewards[1] < 100.0) {
      /* '<S1>:1:17' */
      /* score < $1 */
      /* '<S1>:1:18' */
      stroke_width_col = rt_roundd_snf(floor(gbyk_v4b_B.offeredRewards[1] / 10.0));
      if (stroke_width_col < 2.147483648E+9) {
        if (stroke_width_col >= -2.147483648E+9) {
          n1 = (int32_T)stroke_width_col;
        } else {
          n1 = MIN_int32_T;
        }
      } else {
        n1 = MAX_int32_T;
      }

      /* we need to cast score to a double otherwise the arithmetic is wrong! */
      /* '<S1>:1:19' */
      /* '<S1>:1:21' */
      tmp_6 = n1 + 48LL;
      if (tmp_6 > 2147483647LL) {
        tmp_6 = 2147483647LL;
      } else {
        if (tmp_6 < -2147483648LL) {
          tmp_6 = -2147483648LL;
        }
      }

      gbyk_v4b_B.VCODE_MOD_n[29] = (int32_T)tmp_6;

      /* '<S1>:1:22' */
      n2d = 16;

      /* '<S1>:1:23' */
      tmp_6 = n1 * 10LL;
      if (tmp_6 > 2147483647LL) {
        tmp_6 = 2147483647LL;
      } else {
        if (tmp_6 < -2147483648LL) {
          tmp_6 = -2147483648LL;
        }
      }

      stroke_width_col = rt_roundd_snf(gbyk_v4b_B.offeredRewards[1] - (real_T)
        (int32_T)tmp_6);
      if (stroke_width_col < 2.147483648E+9) {
        if (stroke_width_col >= -2.147483648E+9) {
          i = (int32_T)stroke_width_col;
        } else {
          i = MIN_int32_T;
        }
      } else {
        i = MAX_int32_T;
      }

      tmp_6 = i + 48LL;
      if (tmp_6 > 2147483647LL) {
        tmp_6 = 2147483647LL;
      } else {
        if (tmp_6 < -2147483648LL) {
          tmp_6 = -2147483648LL;
        }
      }

      gbyk_v4b_B.VCODE_MOD_n[31] = (int32_T)tmp_6;
    } else {
      /* label < 1000 */
      /* '<S1>:1:25' */
      stroke_width_col = rt_roundd_snf(floor(gbyk_v4b_B.offeredRewards[1] /
        100.0));
      if (stroke_width_col < 2.147483648E+9) {
        if (stroke_width_col >= -2.147483648E+9) {
          n1 = (int32_T)stroke_width_col;
        } else {
          n1 = MIN_int32_T;
        }
      } else {
        n1 = MAX_int32_T;
      }

      /* we need to cast score to a double otherwise the arithmetic is wrong! */
      /* '<S1>:1:26' */
      /* '<S1>:1:27' */
      tmp_6 = n1 * 100LL;
      if (tmp_6 > 2147483647LL) {
        tmp_6 = 2147483647LL;
      } else {
        if (tmp_6 < -2147483648LL) {
          tmp_6 = -2147483648LL;
        }
      }

      stroke_width_col = rt_roundd_snf(gbyk_v4b_B.offeredRewards[1] - (real_T)
        (int32_T)tmp_6);
      if (stroke_width_col < 2.147483648E+9) {
        if (stroke_width_col >= -2.147483648E+9) {
          i = (int32_T)stroke_width_col;
        } else {
          i = MIN_int32_T;
        }
      } else {
        i = MAX_int32_T;
      }

      khi = (int32_T)floor((real_T)i / 100.0);

      /* we need to cast score to a double otherwise the arithmetic is wrong! */
      /* '<S1>:1:28' */
      /* '<S1>:1:30' */
      tmp_6 = n1 + 48LL;
      if (tmp_6 > 2147483647LL) {
        tmp_6 = 2147483647LL;
      } else {
        if (tmp_6 < -2147483648LL) {
          tmp_6 = -2147483648LL;
        }
      }

      gbyk_v4b_B.VCODE_MOD_n[29] = (int32_T)tmp_6;

      /* '<S1>:1:32' */
      gbyk_v4b_B.VCODE_MOD_n[31] = (real_T)khi + 48.0;

      /* '<S1>:1:33' */
      n2d = 17;

      /* '<S1>:1:34' */
      tmp_6 = n1 * 100LL;
      if (tmp_6 > 2147483647LL) {
        tmp_6 = 2147483647LL;
      } else {
        if (tmp_6 < -2147483648LL) {
          tmp_6 = -2147483648LL;
        }
      }

      stroke_width_col = rt_roundd_snf(gbyk_v4b_B.offeredRewards[1] - (real_T)
        (int32_T)tmp_6);
      if (stroke_width_col < 2.147483648E+9) {
        if (stroke_width_col >= -2.147483648E+9) {
          i = (int32_T)stroke_width_col;
        } else {
          i = MIN_int32_T;
        }
      } else {
        i = MAX_int32_T;
      }

      tmp_6 = (int64_T)i - khi * 10;
      if (tmp_6 > 2147483647LL) {
        tmp_6 = 2147483647LL;
      } else {
        if (tmp_6 < -2147483648LL) {
          tmp_6 = -2147483648LL;
        }
      }

      tmp_6 = (int32_T)tmp_6 + 48LL;
      if (tmp_6 > 2147483647LL) {
        tmp_6 = 2147483647LL;
      } else {
        if (tmp_6 < -2147483648LL) {
          tmp_6 = -2147483648LL;
        }
      }

      gbyk_v4b_B.VCODE_MOD_n[33] = (int32_T)tmp_6;
    }

    /* '<S1>:1:36' */
    gbyk_v4b_B.VCODE_MOD_n[1 + (n2d << 1)] = 0.0;

    /* terminate string */
  } else {
    /* '<S1>:1:38' */
    gbyk_v4b_B.VCODE_MOD_n[29] = 0.0;

    /* terminate string */
  }

  /* '<S1>:1:8' */
  for (idx_sizes = 0; idx_sizes < 70; idx_sizes++) {
    /* Reshape: '<S8>/Reshape' incorporates:
     *  Constant: '<S8>/Assess_arm_VCODE'
     */
    gbyk_v4b_B.Reshape[idx_sizes] = gbyk_v4b_P.Assess_arm_VCODE_Value[idx_sizes];

    /* Reshape: '<S8>/Reshape1' incorporates:
     *  Constant: '<S8>/Contralateral_arm_VCODE'
     */
    gbyk_v4b_B.Reshape1[idx_sizes] =
      gbyk_v4b_P.Contralateral_arm_VCODE_Value[idx_sizes];
  }

  /* End of MATLAB Function: '<Root>/AddTxt2TgtB' */

  /* Concatenate: '<S8>/Matrix Concatenation' */
  for (i = 0; i < 70; i++) {
    gbyk_v4b_B.MatrixConcatenation[i << 1] = gbyk_v4b_B.Reshape[i];
  }

  for (i = 0; i < 70; i++) {
    gbyk_v4b_B.MatrixConcatenation[1 + (i << 1)] = gbyk_v4b_B.Reshape1[i];
  }

  /* End of Concatenate: '<S8>/Matrix Concatenation' */

  /* MATLAB Function: '<S8>/FeedFwdArm' */
  gbyk_v4b_FeedFwdArm();

  /* Selector: '<S265>/Selector' */
  i = (int32_T)gbyk_v4b_B.Taskwideparam[1];
  for (idx_sizes = 0; idx_sizes < 25; idx_sizes++) {
    gbyk_v4b_B.Selector_g[idx_sizes] = gbyk_v4b_B.TargetTable[((idx_sizes << 5)
      + i) - 1];
  }

  /* End of Selector: '<S265>/Selector' */

  /* Abs: '<S6>/Abs' */
  idx_sizes = gbyk_v4b_B.feedback_text;
  if (idx_sizes < 0) {
    gbyk_v4b_B.Abs_f = -idx_sizes;
  } else {
    gbyk_v4b_B.Abs_f = idx_sizes;
  }

  /* End of Abs: '<S6>/Abs' */

  /* Logic: '<S6>/Logical Operator' */
  gbyk_v4b_B.LogicalOperator = ((gbyk_v4b_B.doreward != 0.0) ||
    (gbyk_v4b_B.Abs_f != 0));

  /* DataTypeConversion: '<S6>/Data Type Conversion' */
  gbyk_v4b_B.DataTypeConversion_b = gbyk_v4b_B.LogicalOperator;

  /* Concatenate: '<S265>/Matrix Concatenation' incorporates:
   *  Constant: '<S265>/state1_indices'
   *  Constant: '<S265>/state2_indices'
   *  Constant: '<S265>/state3_indices'
   *  Constant: '<S265>/state4_indices'
   *  Constant: '<S265>/state5_indices'
   */
  for (i = 0; i < 9; i++) {
    tmp_3[5 * i] = gbyk_v4b_P.Show_Target_With_Label1_attribcol1[i];
  }

  for (i = 0; i < 9; i++) {
    tmp_3[1 + 5 * i] = gbyk_v4b_P.state2_indices_Value[i];
  }

  for (i = 0; i < 9; i++) {
    tmp_3[2 + 5 * i] = gbyk_v4b_P.state3_indices_Value_o[i];
  }

  for (i = 0; i < 9; i++) {
    tmp_3[3 + 5 * i] = gbyk_v4b_P.state4_indices_Value_p[i];
  }

  for (i = 0; i < 9; i++) {
    tmp_3[4 + 5 * i] = gbyk_v4b_P.state5_indices_Value_l[i];
  }

  memcpy(&gbyk_v4b_B.MatrixConcatenation1_a[0], &tmp_3[0], 45U * sizeof(real_T));

  /* End of Concatenate: '<S265>/Matrix Concatenation' */

  /* Constant: '<S265>/padder' */
  memcpy(&gbyk_v4b_B.MatrixConcatenation1_a[45], &gbyk_v4b_P.padder_Value_l[0],
         10U * sizeof(real_T));

  /* MATLAB Function: '<S265>/Embedded MATLAB Function' incorporates:
   *  Constant: '<S265>/Opacity'
   *  Constant: '<S265>/Target_Display'
   *  Constant: '<S265>/Target_Type'
   *  Constant: '<S265>/num_states'
   *  Constant: '<S265>/xpos_index'
   *  Constant: '<S265>/ypos_index'
   */
  hold_steps = gbyk_v4b_P.Show_Target_With_Label1_target_type;

  /* MATLAB Function 'Show_Target_With_Label/Embedded MATLAB Function': '<S266>:1' */
  /*  VCODEs are length 70. All units in a VCODE should be SI, e.g. (m) and (rad). Elements in a VCODE are defined as follows: */
  /*  */
  /*  For all target types: */
  /*   1: target type */
  /*        1 - circle */
  /*        2 - ellipse */
  /*        3 - rectangle */
  /*        4 - line */
  /*        5 - triangle */
  /*        11 - circle with label */
  /*        12 - ellipse with label */
  /*        13 - rectangle with label */
  /*        14 - line with label */
  /*        15 - triangle with label */
  /*   2: target on/off status and target display (which display target will appear on) */
  /* 		0 - off */
  /* 		1 - on, appearing on both subject and operator displays */
  /*        2 - on, appearing on subject display only */
  /*        3 - on, appearing on operator display only */
  /*   3: x position (m) */
  /*   4: y position (m) */
  /*   5: fill colour (RRGGBB) or texture index */
  /*   6: stroke colour (RRGGBB) or texture index */
  /*   7: stroke width */
  /*   8: reserved for target background ID */
  /*   9: opacity */
  /*  */
  /*  For circles: */
  /*   10: radius (m) */
  /*  */
  /*  For ellipses: */
  /*   10: major radius (m) */
  /*   11: minor radius (m) */
  /*   12: orientation of major axis (rad) */
  /*  */
  /*  For rectangles: */
  /*   10: length (m) */
  /*   11: height (m) */
  /*   12: orientation (rad) (relative to x, y already shown) */
  /*  */
  /*  For lines: */
  /*   10: endpoint x-axis coordinate relative to start point (m) */
  /*   11: endpoint y-axis coordinate relative to start point (m) */
  /*  */
  /*  For triangles: */
  /*   10: length (m) */
  /*   11: height (m) */
  /*   12: offset of peak from midpoint of length (m) */
  /*   13: orientation (rad) */
  /*  */
  /*  For all labelled target types: */
  /*   14: reserved */
  /*   15-64: label characters (indexes in ISO 8859-1 character set) */
  /*   65: label colour (0xRRGGBB), opacity is set by the vcode's opacity (9). */
  /*   66: label height (m) */
  /*   67: reserved */
  /*   68: reserved */
  /*   69: reserved */
  /*   70: reserved */
  /*  NOTE: we assume that the STATE and/or OPACITY inputs are vectors.  */
  /*  If the length of the input STATE is not the same as the number of targets then make STATE a column vector of the same length as  */
  /*  the TARGET input, using the first STATE (i.e. all targets get the same state)  */
  /* '<S266>:1:70' */
  reps2 = gbyk_v4b_B.DataTypeConversion_b;

  /*  If the length of the input OPACITY is not the same as the number of targets then make OPACITY a column vector of the same length as */
  /*  the TARGET input, using the first OPACITY (i.e. all targets get the same opacity)  */
  /* '<S266>:1:79' */
  /*  Clamping the opacity to [0, 100]. */
  /* '<S266>:1:86' */
  /* '<S266>:1:87' */
  reps3 = gbyk_v4b_P.Show_Target_With_Label1_opacity;
  if (!(reps3 <= 100.0)) {
    reps3 = 100.0;
  }

  if (!(reps3 >= 0.0)) {
    reps3 = 0.0;
  }

  /* '<S266>:1:89' */
  for (idx_sizes = 0; idx_sizes < 70; idx_sizes++) {
    gbyk_v4b_B.VCODE[idx_sizes] = 0.0;
  }

  /*  Set the target type. Targets with labels have type codes 10 greater than their unlabelled counterparts. */
  /* '<S266>:1:92' */
  gbyk_v4b_B.VCODE[0] = gbyk_v4b_P.Show_Target_With_Label1_target_type + 10.0;

  /*  Set the target position. */
  /* '<S266>:1:95' */
  gbyk_v4b_B.VCODE[2] = gbyk_v4b_B.Selector_g[(int32_T)
    gbyk_v4b_P.xpos_index_Value_l - 1] * 0.01;

  /*  x position (convert from (cm) in target table to (m)) */
  /* '<S266>:1:96' */
  gbyk_v4b_B.VCODE[3] = gbyk_v4b_B.Selector_g[(int32_T)
    gbyk_v4b_P.ypos_index_Value_d - 1] * 0.01;

  /*  y position (convert from (cm) in target table to (m)) */
  /*  Set the target on/off state. If the state input is 0, the target is off. Users of the VCODE should respect this */
  /*  as an indication that the rest of the VCODE will be uninitialized. */
  if ((gbyk_v4b_B.DataTypeConversion_b <= 0.0) ||
      (gbyk_v4b_B.DataTypeConversion_b >
       gbyk_v4b_P.Show_Target_With_Label1_num_states)) {
    /* '<S266>:1:101' */
    /* '<S266>:1:102' */
    gbyk_v4b_B.VCODE[1] = 0.0;

    /*  target is off */
  } else {
    /* '<S266>:1:104' */
    gbyk_v4b_B.VCODE[1] = gbyk_v4b_P.Show_Target_With_Label1_target_display;

    /*  Default is that target is on; target displays as specified by block mask */
  }

  /* '<S266>:1:107' */
  /* '<S266>:1:108' */
  stroke_colour_col = gbyk_v4b_B.MatrixConcatenation1_a[(int32_T)
    gbyk_v4b_B.DataTypeConversion_b + 4];

  /* '<S266>:1:109' */
  stroke_width_col = gbyk_v4b_B.MatrixConcatenation1_a[(int32_T)
    gbyk_v4b_B.DataTypeConversion_b + 9];

  /*  Set the fill colour. Fill colour currently comes from the GUI in RRRGGGBBB format. */
  if (gbyk_v4b_B.MatrixConcatenation1_a[(int32_T)gbyk_v4b_B.DataTypeConversion_b
      - 1] == 0.0) {
    /* '<S266>:1:112' */
    /* '<S266>:1:113' */
    gbyk_v4b_B.VCODE[4] = -2.147483648E+9;
  } else if (gbyk_v4b_B.Selector_g[(int32_T)gbyk_v4b_B.MatrixConcatenation1_a
             [(int32_T)gbyk_v4b_B.DataTypeConversion_b - 1] - 1] < 0.0) {
    /* '<S266>:1:114' */
    /* '<S266>:1:115' */
    gbyk_v4b_B.VCODE[4] = gbyk_v4b_B.Selector_g[(int32_T)
      gbyk_v4b_B.MatrixConcatenation1_a[(int32_T)gbyk_v4b_B.DataTypeConversion_b
      - 1] - 1];
  } else {
    /* '<S266>:1:117' */
    gbyk_v4b_B.VCODE[4] = gbyk_v4b_colourshift_h(gbyk_v4b_B.Selector_g[(int32_T)
      gbyk_v4b_B.MatrixConcatenation1_a[(int32_T)gbyk_v4b_B.DataTypeConversion_b
      - 1] - 1]);
  }

  /*  Set the stroke colour. Stroke colour currently comes from the GUI in RRRGGGBBB format. */
  if (stroke_colour_col == 0.0) {
    /* '<S266>:1:121' */
    /* '<S266>:1:122' */
    gbyk_v4b_B.VCODE[5] = -2.147483648E+9;
  } else if (gbyk_v4b_B.Selector_g[(int32_T)stroke_colour_col - 1] < 0.0) {
    /* '<S266>:1:123' */
    /* '<S266>:1:124' */
    gbyk_v4b_B.VCODE[5] = gbyk_v4b_B.Selector_g[(int32_T)stroke_colour_col - 1];
  } else {
    /* '<S266>:1:126' */
    gbyk_v4b_B.VCODE[5] = gbyk_v4b_colourshift_h(gbyk_v4b_B.Selector_g[(int32_T)
      stroke_colour_col - 1]);
  }

  /*  Set the stroke width. if target table index for stroke width is zero, then the stroke width is undefined */
  if (stroke_width_col == 0.0) {
    /* '<S266>:1:130' */
    /* '<S266>:1:131' */
    gbyk_v4b_B.VCODE[6] = 0.0;

    /*  if stroke width column is 0, then stroke width is 0 */
  } else if (stroke_width_col < 0.0) {
    /* '<S266>:1:132' */
    /* '<S266>:1:133' */
    gbyk_v4b_B.VCODE[6] = 0.001;

    /*  if stroke width column is -ve, then a 1mm default is chosen */
  } else {
    /* '<S266>:1:135' */
    gbyk_v4b_B.VCODE[6] = gbyk_v4b_B.Selector_g[(int32_T)stroke_width_col - 1] *
      0.01;

    /*  if stroke width column is +ve, convert width from (cm) in target table to (m) */
  }

  /*  Set the opacity value */
  /* '<S266>:1:139' */
  gbyk_v4b_B.VCODE[8] = reps3;

  /*  Set attributes specific to each target type. In the process, note the first state vector column used for label information. */
  /* '<S266>:1:142' */
  khi = 1;

  /*  Set attributes specific to each target type. */
  if (hold_steps == 1.0) {
    /* '<S266>:1:145' */
    /*  Handle circle target: */
    /* '<S266>:1:148' */
    /* '<S266>:1:149' */
    gbyk_v4b_B.VCODE[9] = gbyk_v4b_B.Selector_g[(int32_T)
      gbyk_v4b_B.MatrixConcatenation1_a[(int32_T)reps2 + 14] - 1] * 0.01;

    /*  radius (convert from (cm) in target table to (m)) */
    /* '<S266>:1:150' */
    khi = 5;
  } else if ((hold_steps == 2.0) || (hold_steps == 3.0)) {
    /* '<S266>:1:152' */
    /*  Handle ellipse or rectangle target: */
    /* '<S266>:1:155' */
    /* '<S266>:1:156' */
    /* '<S266>:1:157' */
    /* '<S266>:1:159' */
    gbyk_v4b_B.VCODE[9] = gbyk_v4b_B.Selector_g[(int32_T)
      gbyk_v4b_B.MatrixConcatenation1_a[(int32_T)reps2 + 14] - 1] * 0.01;

    /*  major radius (convert from (cm) in target table to (m)) */
    /* '<S266>:1:160' */
    gbyk_v4b_B.VCODE[10] = gbyk_v4b_B.Selector_g[(int32_T)
      gbyk_v4b_B.MatrixConcatenation1_a[(int32_T)reps2 + 19] - 1] * 0.01;

    /*  minor radius (convert from (cm) in target table to (m)) */
    if (gbyk_v4b_B.MatrixConcatenation1_a[(int32_T)reps2 + 24] == 0.0) {
      /* '<S266>:1:161' */
      /* '<S266>:1:162' */
      gbyk_v4b_B.VCODE[11] = 0.0;

      /*  if orientation column is 0, set orientation to 0 rad */
    } else {
      /* '<S266>:1:164' */
      gbyk_v4b_B.VCODE[11] = (gbyk_v4b_B.Selector_g[(int32_T)
        gbyk_v4b_B.MatrixConcatenation1_a[(int32_T)reps2 + 24] - 1] - floor
        (gbyk_v4b_B.Selector_g[(int32_T)gbyk_v4b_B.MatrixConcatenation1_a
         [(int32_T)reps2 + 24] - 1] / 360.0) * 360.0) * 3.1415926535897931 /
        180.0;

      /*  orientation (convert from (degrees) in target table to (rad)) */
    }

    /* '<S266>:1:166' */
    khi = 7;
  } else if (hold_steps == 4.0) {
    /* '<S266>:1:168' */
    /*  Handle line target: */
    /* '<S266>:1:171' */
    /* '<S266>:1:172' */
    /* '<S266>:1:173' */
    gbyk_v4b_B.VCODE[9] = gbyk_v4b_B.Selector_g[(int32_T)
      gbyk_v4b_B.MatrixConcatenation1_a[(int32_T)reps2 + 14] - 1] * 0.01;

    /*  line endpoint in x axis, relative to start (convert from (cm) in target table to (m)) */
    /* '<S266>:1:174' */
    gbyk_v4b_B.VCODE[10] = gbyk_v4b_B.Selector_g[(int32_T)
      gbyk_v4b_B.MatrixConcatenation1_a[(int32_T)reps2 + 19] - 1] * 0.01;

    /*  line endpoint in y axis, relative to start (convert from (cm) in target table to (m)) */
    /* '<S266>:1:175' */
    khi = 6;
  } else {
    if (hold_steps == 5.0) {
      /* '<S266>:1:177' */
      /*  Handle triangle target: */
      /* '<S266>:1:180' */
      /* '<S266>:1:181' */
      /* '<S266>:1:182' */
      /* '<S266>:1:183' */
      /* '<S266>:1:185' */
      gbyk_v4b_B.VCODE[9] = gbyk_v4b_B.Selector_g[(int32_T)
        gbyk_v4b_B.MatrixConcatenation1_a[(int32_T)reps2 + 14] - 1] * 0.01;

      /*  length (convert from (cm) in target table to (m)) */
      /*  If the height column is set to 0 then the triangle is automatically made equilateral, with the base length used as length */
      /*  for all sides. If the height column is non-zero, separate values for height and peak offset are taken from the target table. */
      if (gbyk_v4b_B.MatrixConcatenation1_a[(int32_T)reps2 + 19] == 0.0) {
        /* '<S266>:1:189' */
        /* '<S266>:1:190' */
        gbyk_v4b_B.VCODE[10] = 0.8660254037844386 * gbyk_v4b_B.VCODE[9];

        /*  height for equilateral triangle */
        /* '<S266>:1:191' */
        gbyk_v4b_B.VCODE[11] = 0.0;

        /*  peak offset for equilateral triangle */
      } else {
        /* '<S266>:1:193' */
        gbyk_v4b_B.VCODE[10] = gbyk_v4b_B.Selector_g[(int32_T)
          gbyk_v4b_B.MatrixConcatenation1_a[(int32_T)reps2 + 19] - 1] * 0.01;

        /*  height (convert from (cm) in target table to (m)) */
        /* '<S266>:1:194' */
        gbyk_v4b_B.VCODE[11] = gbyk_v4b_B.Selector_g[(int32_T)
          gbyk_v4b_B.MatrixConcatenation1_a[(int32_T)reps2 + 24] - 1] * 0.01;

        /*  peak offset (convert from (cm) in target table to (m)) */
      }

      if (gbyk_v4b_B.MatrixConcatenation1_a[(int32_T)reps2 + 29] == 0.0) {
        /* '<S266>:1:197' */
        /* '<S266>:1:198' */
        gbyk_v4b_B.VCODE[12] = 0.0;

        /*  if orientation column is 0, set orientation to 0 rad */
      } else {
        /* '<S266>:1:200' */
        gbyk_v4b_B.VCODE[12] = (gbyk_v4b_B.Selector_g[(int32_T)
          gbyk_v4b_B.MatrixConcatenation1_a[(int32_T)reps2 + 29] - 1] - floor
          (gbyk_v4b_B.Selector_g[(int32_T)gbyk_v4b_B.MatrixConcatenation1_a
           [(int32_T)reps2 + 29] - 1] / 360.0) * 360.0) * 3.1415926535897931 /
          180.0;

        /*  orientation (convert from (degrees) in target table to (rad)) */
      }

      /* '<S266>:1:202' */
      khi = 8;
    }
  }

  /*  Copy the label characters to the VCODE. */
  /* '<S266>:1:207' */
  for (n2d = 0; n2d < 50; n2d++) {
    /* '<S266>:1:207' */
    /* '<S266>:1:208' */
    gbyk_v4b_B.VCODE[14 + n2d] = gbyk_v4b_B.Convert1[((int32_T)
      gbyk_v4b_B.Selector_g[(int32_T)gbyk_v4b_B.MatrixConcatenation1_a[((khi - 1)
      * 5 + (int32_T)reps2) - 1] - 1] + 100 * n2d) - 1];

    /* '<S266>:1:207' */
  }

  /*  Set the label colour. Like other colours, label colour comes from the GUI in RRRGGGBBB format and is converted to a 32-bit */
  /*  0xRRGGBB value here. If the target column table index for the colour is 0, the label is transparent. */
  if (gbyk_v4b_B.MatrixConcatenation1_a[(5 * khi + (int32_T)reps2) - 1] == 0.0)
  {
    /* '<S266>:1:213' */
    /* '<S266>:1:214' */
    gbyk_v4b_B.VCODE[64] = -2.147483648E+9;
  } else if (gbyk_v4b_B.Selector_g[(int32_T)gbyk_v4b_B.MatrixConcatenation1_a[(5
              * khi + (int32_T)reps2) - 1] - 1] < 0.0) {
    /* '<S266>:1:215' */
    /* '<S266>:1:216' */
    gbyk_v4b_B.VCODE[64] = gbyk_v4b_B.Selector_g[(int32_T)
      gbyk_v4b_B.MatrixConcatenation1_a[(5 * khi + (int32_T)reps2) - 1] - 1];
  } else {
    /* '<S266>:1:218' */
    gbyk_v4b_B.VCODE[64] = gbyk_v4b_colourshift_h(gbyk_v4b_B.Selector_g[(int32_T)
      gbyk_v4b_B.MatrixConcatenation1_a[(5 * khi + (int32_T)reps2) - 1] - 1]);
  }

  /*  Set the label height. Label height is converted from (cm) in the target table to (m). */
  /* '<S266>:1:222' */
  gbyk_v4b_B.VCODE[65] = gbyk_v4b_B.Selector_g[(int32_T)
    gbyk_v4b_B.MatrixConcatenation1_a[((khi + 1) * 5 + (int32_T)reps2) - 1] - 1]
    * 0.01;

  /* End of MATLAB Function: '<S265>/Embedded MATLAB Function' */

  /* Switch: '<S6>/Switch' */
  if (gbyk_v4b_B.doreward > gbyk_v4b_P.Switch_Threshold_d) {
    gbyk_v4b_B.Switch_h = gbyk_v4b_B.score;
  } else {
    gbyk_v4b_B.Switch_h = gbyk_v4b_B.reward;
  }

  /* End of Switch: '<S6>/Switch' */

  /* MATLAB Function: '<S6>/MATLAB Function' */
  /* MATLAB Function 'DisplayText/MATLAB Function': '<S264>:1' */
  /* '<S264>:1:20' */
  /* '<S264>:1:21' */
  /* '<S264>:1:29' */
  /* '<S264>:1:57' */
  /* '<S264>:1:62' */
  /* '<S264>:1:67' */
  /* '<S264>:1:71' */
  /* '<S264>:1:75' */
  /* '<S264>:1:4' */
  memcpy(&gbyk_v4b_B.VCODE_mod[0], &gbyk_v4b_B.VCODE[0], 70U * sizeof(real_T));

  /* '<S264>:1:6' */
  hold_steps = rt_roundd_snf(gbyk_v4b_B.Switch_h);

  /* for display purposes, round fractional rewards */
  if (gbyk_v4b_B.feedback_text == 0) {
    /* '<S264>:1:8' */
    /* if this is zero, show the score */
    /* score is in cents. potentially need to convert to dollars */
    if (hold_steps < 10.0) {
      /* '<S264>:1:13' */
      /* '<S264>:1:14' */
      /* '<S264>:1:15' */
      /* '<S264>:1:17' */
      stroke_width_col = rt_roundd_snf(hold_steps);
      if (stroke_width_col >= -2.147483648E+9) {
        khi = (int32_T)stroke_width_col;
      } else {
        khi = MIN_int32_T;
      }

      /* terminate the string! */
      /* '<S264>:1:93' */
      khi -= div_s32_floor(khi, 10) * 10;

      /* make sure we only have 1 digit or we will get a weird character! */
      /* '<S264>:1:95' */
      /* // add the character */
      /* '<S264>:1:17' */
      for (i = 0; i < 11; i++) {
        b_text1_1[i] = b_text1[i];
      }

      tmp_6 = khi + 48LL;
      if (tmp_6 > 2147483647LL) {
        tmp_6 = 2147483647LL;
      } else {
        if (tmp_6 < -2147483648LL) {
          tmp_6 = -2147483648LL;
        }
      }

      b_text1_1[11] = (int8_T)tmp_6;
      for (i = 0; i < 7; i++) {
        b_text1_1[i + 12] = text2[i];
      }

      idx_sizes = 19;
      for (i = 0; i < 19; i++) {
        textout_data[i] = b_text1_1[i];
      }
    } else if (hold_steps < 100.0) {
      /* '<S264>:1:19' */
      /* score < $1 */
      /* '<S264>:1:20' */
      /* '<S264>:1:21' */
      /* '<S264>:1:23' */
      n1 = (int32_T)floor(hold_steps / 10.0);

      /* we need to cast score to a double otherwise the arithmetic is wrong! */
      /* '<S264>:1:24' */
      khi = (int32_T)rt_roundd_snf(hold_steps - (real_T)n1 * 10.0);

      /* '<S264>:1:26' */
      /* terminate the string! */
      /* '<S264>:1:93' */
      /* make sure we only have 1 digit or we will get a weird character! */
      /* '<S264>:1:95' */
      /* // add the character */
      /* terminate the string! */
      /* '<S264>:1:93' */
      /* make sure we only have 1 digit or we will get a weird character! */
      /* '<S264>:1:95' */
      /* // add the character */
      /* '<S264>:1:26' */
      for (i = 0; i < 11; i++) {
        b_text1_0[i] = b_text1[i];
      }

      b_text1_0[11] = (char_T)((n1 - div_s32_floor(n1, 10) * 10) + 48);
      b_text1_0[12] = (int8_T)((khi - div_s32_floor(khi, 10) * 10) + 48);
      for (i = 0; i < 7; i++) {
        b_text1_0[i + 13] = text2[i];
      }

      idx_sizes = 20;
      for (i = 0; i < 20; i++) {
        textout_data[i] = b_text1_0[i];
      }
    } else {
      /* score > $1, convert to dollars to keep the score readable */
      /* '<S264>:1:29' */
      /* '<S264>:1:33' */
      stroke_width_col = rt_roundd_snf(floor(hold_steps / 100.0));
      if (stroke_width_col < 2.147483648E+9) {
        khi = (int32_T)stroke_width_col;
      } else {
        khi = MAX_int32_T;
      }

      if (khi >= 10) {
        /* '<S264>:1:34' */
        /* double digit dollar value */
        /* '<S264>:1:35' */
        n1d = (int32_T)floor((real_T)khi / 10.0);

        /* '<S264>:1:36' */
        n2d = khi - n1d * 10;

        /* '<S264>:1:37' */
        /* terminate the string! */
        /* '<S264>:1:93' */
        /* make sure we only have 1 digit or we will get a weird character! */
        /* '<S264>:1:95' */
        /* // add the character */
        /* terminate the string! */
        /* '<S264>:1:93' */
        /* make sure we only have 1 digit or we will get a weird character! */
        /* '<S264>:1:95' */
        /* // add the character */
        /* '<S264>:1:37' */
        textcents_idx_0 = (int8_T)((n1d - div_s32_floor(n1d, 10) * 10) + 48);
        tmp_6 = (n2d - div_s32_floor(n2d, 10) * 10) + 48LL;
        if (tmp_6 > 2147483647LL) {
          tmp_6 = 2147483647LL;
        } else {
          if (tmp_6 < -2147483648LL) {
            tmp_6 = -2147483648LL;
          }
        }

        textcents_idx_1 = (int8_T)tmp_6;
        n1d = 2;
        textdollars_data[0] = textcents_idx_0;
        textdollars_data[1] = textcents_idx_1;
      } else {
        /* single digit */
        /* '<S264>:1:39' */
        /* terminate the string! */
        /* '<S264>:1:93' */
        /* make sure we only have 1 digit or we will get a weird character! */
        /* '<S264>:1:95' */
        tmp_6 = (khi - div_s32_floor(khi, 10) * 10) + 48LL;
        if (tmp_6 > 2147483647LL) {
          tmp_6 = 2147483647LL;
        } else {
          if (tmp_6 < -2147483648LL) {
            tmp_6 = -2147483648LL;
          }
        }

        textcents_idx_0 = (int8_T)tmp_6;

        /* // add the character */
        n1d = 1;
        textdollars_data[0] = textcents_idx_0;
      }

      /* '<S264>:1:42' */
      tmp_6 = khi * 100LL;
      if (tmp_6 > 2147483647LL) {
        tmp_6 = 2147483647LL;
      } else {
        if (tmp_6 < -2147483648LL) {
          tmp_6 = -2147483648LL;
        }
      }

      stroke_width_col = rt_roundd_snf(hold_steps - (real_T)(int32_T)tmp_6);
      if (stroke_width_col < 2.147483648E+9) {
        khi = (int32_T)stroke_width_col;
      } else {
        khi = MAX_int32_T;
      }

      if (khi < 10) {
        /* '<S264>:1:43' */
        /* '<S264>:1:44' */
        /* terminate the string! */
        /* '<S264>:1:93' */
        /* make sure we only have 1 digit or we will get a weird character! */
        /* '<S264>:1:95' */
        /* // add the character */
        textcents_idx_0 = '0';
        tmp_6 = (khi - div_s32_floor(khi, 10) * 10) + 48LL;
        if (tmp_6 > 2147483647LL) {
          tmp_6 = 2147483647LL;
        } else {
          if (tmp_6 < -2147483648LL) {
            tmp_6 = -2147483648LL;
          }
        }

        textcents_idx_1 = (int8_T)tmp_6;
      } else {
        /* '<S264>:1:46' */
        n1 = (int32_T)floor((real_T)khi / 10.0);

        /* '<S264>:1:47' */
        khi -= n1 * 10;

        /* '<S264>:1:48' */
        /* terminate the string! */
        /* '<S264>:1:93' */
        /* make sure we only have 1 digit or we will get a weird character! */
        /* '<S264>:1:95' */
        /* // add the character */
        /* terminate the string! */
        /* '<S264>:1:93' */
        /* make sure we only have 1 digit or we will get a weird character! */
        /* '<S264>:1:95' */
        /* // add the character */
        textcents_idx_0 = (int8_T)((n1 - div_s32_floor(n1, 10) * 10) + 48);
        tmp_6 = (khi - div_s32_floor(khi, 10) * 10) + 48LL;
        if (tmp_6 > 2147483647LL) {
          tmp_6 = 2147483647LL;
        } else {
          if (tmp_6 < -2147483648LL) {
            tmp_6 = -2147483648LL;
          }
        }

        textcents_idx_1 = (int8_T)tmp_6;
      }

      /* '<S264>:1:51' */
      idx_sizes = 16 + n1d;
      for (i = 0; i < 12; i++) {
        textout_data[i] = text1[i];
      }

      for (i = 0; i < n1d; i++) {
        textout_data[i + 12] = textdollars_data[i];
      }

      textout_data[12 + n1d] = '.';
      textout_data[n1d + 13] = textcents_idx_0;
      textout_data[n1d + 14] = textcents_idx_1;
      textout_data[15 + n1d] = '!';
    }
  } else if (gbyk_v4b_B.feedback_text == 1) {
    /* '<S264>:1:55' */
    /* print "too fast" */
    /* '<S264>:1:57' */
    idx_sizes = 9;
    for (i = 0; i < 9; i++) {
      textout_data[i] = c[i];
    }
  } else if (gbyk_v4b_B.feedback_text == 2) {
    /* '<S264>:1:60' */
    /* print "too fast" */
    /* '<S264>:1:62' */
    idx_sizes = 10;
    for (i = 0; i < 10; i++) {
      textout_data[i] = d[i];
    }
  } else if (gbyk_v4b_B.feedback_text == -1) {
    /* '<S264>:1:64' */
    /* print "too slow" */
    /* '<S264>:1:67' */
    idx_sizes = 9;
    for (i = 0; i < 9; i++) {
      textout_data[i] = e[i];
    }
  } else if (gbyk_v4b_B.feedback_text == -2) {
    /* '<S264>:1:69' */
    /* print "too fast" */
    /* '<S264>:1:71' */
    idx_sizes = 9;
    for (i = 0; i < 9; i++) {
      textout_data[i] = f[i];
    }
  } else {
    /* '<S264>:1:75' */
    idx_sizes = 0;
  }

  /* the first character is VCODE(15) */
  /* need to translate text into ascii: */
  /* '<S264>:1:82' */
  for (i = 0; i < idx_sizes; i++) {
    textnum_data[i] = (uint8_T)textout_data[i];
  }

  /* this quickly casts each char into a number */
  /* make sure we won't overflow the VCODE: no more than 50 chars! we will */
  /* clip off anything that overflows. */
  varargin_1_idx_0 = (int8_T)idx_sizes;
  if (1 > varargin_1_idx_0) {
    i = 0;
  } else {
    i = varargin_1_idx_0;
  }

  khi = i - 1;

  /* '<S264>:1:86' */
  for (i = 0; i <= khi; i++) {
    gbyk_v4b_B.VCODE_mod[14 + i] = textnum_data[i];
  }

  /* write out as many the characters as possible into the VCODE */
  /* '<S264>:1:87' */
  gbyk_v4b_B.VCODE_mod[idx_sizes + 15] = 0.0;

  /* End of MATLAB Function: '<S6>/MATLAB Function' */

  /* Sum: '<S5>/Add' incorporates:
   *  Constant: '<S5>/Constant'
   */
  gbyk_v4b_B.Add = gbyk_v4b_P.Constant_Value_a + gbyk_v4b_B.instruct_num;

  /* Selector: '<S262>/Selector' */
  i = (int32_T)gbyk_v4b_B.Add;
  for (idx_sizes = 0; idx_sizes < 25; idx_sizes++) {
    gbyk_v4b_B.Selector_j[idx_sizes] = gbyk_v4b_B.TargetTable[((idx_sizes << 5)
      + i) - 1];
  }

  /* End of Selector: '<S262>/Selector' */

  /* Abs: '<S5>/Abs' */
  gbyk_v4b_B.Abs = fabs(gbyk_v4b_B.instruct_num);

  /* Signum: '<S5>/Sign' */
  reps3 = gbyk_v4b_B.Abs;
  if (reps3 < 0.0) {
    gbyk_v4b_B.Sign = -1.0;
  } else if (reps3 > 0.0) {
    gbyk_v4b_B.Sign = 1.0;
  } else if (reps3 == 0.0) {
    gbyk_v4b_B.Sign = 0.0;
  } else {
    gbyk_v4b_B.Sign = reps3;
  }

  /* End of Signum: '<S5>/Sign' */

  /* Concatenate: '<S262>/Matrix Concatenation' incorporates:
   *  Constant: '<S262>/state1_indices'
   *  Constant: '<S262>/state2_indices'
   *  Constant: '<S262>/state3_indices'
   *  Constant: '<S262>/state4_indices'
   *  Constant: '<S262>/state5_indices'
   */
  for (i = 0; i < 6; i++) {
    tmp_4[5 * i] = gbyk_v4b_P.Show_Target_attribcol1[i];
  }

  for (i = 0; i < 6; i++) {
    tmp_4[1 + 5 * i] = gbyk_v4b_P.state2_indices_Value_j[i];
  }

  for (i = 0; i < 6; i++) {
    tmp_4[2 + 5 * i] = gbyk_v4b_P.state3_indices_Value_og[i];
  }

  for (i = 0; i < 6; i++) {
    tmp_4[3 + 5 * i] = gbyk_v4b_P.state4_indices_Value_g[i];
  }

  for (i = 0; i < 6; i++) {
    tmp_4[4 + 5 * i] = gbyk_v4b_P.state5_indices_Value_im[i];
  }

  memcpy(&gbyk_v4b_B.MatrixConcatenation1_na[0], &tmp_4[0], 30U * sizeof(real_T));

  /* End of Concatenate: '<S262>/Matrix Concatenation' */

  /* Constant: '<S262>/padder' */
  memcpy(&gbyk_v4b_B.MatrixConcatenation1_na[30], &gbyk_v4b_P.padder_Value_j[0],
         25U * sizeof(real_T));

  /* MATLAB Function: '<S262>/Embedded MATLAB Function' incorporates:
   *  Constant: '<S262>/Opacity'
   *  Constant: '<S262>/Target_Display'
   *  Constant: '<S262>/Target_Type'
   *  Constant: '<S262>/num_states'
   *  Constant: '<S262>/xpos_index'
   *  Constant: '<S262>/ypos_index'
   */
  gbyk_v4b_EmbeddedMATLABFunction(gbyk_v4b_B.Selector_j, gbyk_v4b_B.Sign,
    gbyk_v4b_P.Show_Target_target_type, gbyk_v4b_P.Show_Target_opacity,
    gbyk_v4b_P.Show_Target_target_display, gbyk_v4b_P.xpos_index_Value_e,
    gbyk_v4b_P.ypos_index_Value_bm, gbyk_v4b_P.Show_Target_num_states,
    gbyk_v4b_B.MatrixConcatenation1_na, &gbyk_v4b_B.sf_EmbeddedMATLABFunction_b);

  /* Selector: '<S23>/Selector' */
  for (i = 0; i < 25; i++) {
    gbyk_v4b_B.Selector_i[i << 1] = gbyk_v4b_B.TargetTable[((i << 5) + (int32_T)
      gbyk_v4b_B.targetC_row[0]) - 1];
    gbyk_v4b_B.Selector_i[1 + (i << 1)] = gbyk_v4b_B.TargetTable[((i << 5) +
      (int32_T)gbyk_v4b_B.targetC_row[1]) - 1];
  }

  /* End of Selector: '<S23>/Selector' */

  /* Concatenate: '<S23>/Matrix Concatenation' incorporates:
   *  Constant: '<S23>/state1_indices'
   *  Constant: '<S23>/state2_indices'
   *  Constant: '<S23>/state3_indices'
   *  Constant: '<S23>/state4_indices'
   *  Constant: '<S23>/state5_indices'
   */
  for (i = 0; i < 7; i++) {
    tmp_2[5 * i] = gbyk_v4b_P.Show_TargetC_With_Label_attribcol1[i];
  }

  for (i = 0; i < 7; i++) {
    tmp_2[1 + 5 * i] = gbyk_v4b_P.Show_TargetC_With_Label_attribcol2[i];
  }

  for (i = 0; i < 7; i++) {
    tmp_2[2 + 5 * i] = gbyk_v4b_P.Show_TargetC_With_Label_attribcol3[i];
  }

  for (i = 0; i < 7; i++) {
    tmp_2[3 + 5 * i] = gbyk_v4b_P.state4_indices_Value_a[i];
  }

  for (i = 0; i < 7; i++) {
    tmp_2[4 + 5 * i] = gbyk_v4b_P.state5_indices_Value_j[i];
  }

  memcpy(&gbyk_v4b_B.MatrixConcatenation1_p[0], &tmp_2[0], 35U * sizeof(real_T));

  /* End of Concatenate: '<S23>/Matrix Concatenation' */

  /* Constant: '<S23>/padder' */
  memcpy(&gbyk_v4b_B.MatrixConcatenation1_p[35], &gbyk_v4b_P.padder_Value_a[0],
         20U * sizeof(real_T));

  /* MATLAB Function: '<S23>/Embedded MATLAB Function' incorporates:
   *  Constant: '<S23>/Opacity'
   *  Constant: '<S23>/Target_Display'
   *  Constant: '<S23>/Target_Type'
   *  Constant: '<S23>/num_states'
   *  Constant: '<S23>/xpos_index'
   *  Constant: '<S23>/ypos_index'
   */
  gbyk_v4b_EmbeddedMATLABFunction_k(gbyk_v4b_B.Selector_i,
    gbyk_v4b_B.targetC_state, gbyk_v4b_P.Show_TargetC_With_Label_target_type,
    gbyk_v4b_P.Show_TargetC_With_Label_opacity,
    gbyk_v4b_P.Show_TargetC_With_Label_target_display,
    gbyk_v4b_P.xpos_index_Value_g, gbyk_v4b_P.ypos_index_Value_f,
    gbyk_v4b_P.Show_TargetC_With_Label_num_states,
    gbyk_v4b_B.MatrixConcatenation1_p, gbyk_v4b_B.Convert1,
    &gbyk_v4b_B.sf_EmbeddedMATLABFunction_id);

  /* MATLAB Function: '<Root>/AddTxt2TgtC' */
  /* MATLAB Function 'AddTxt2TgtC': '<S2>:1' */
  /* '<S2>:1:4' */
  memcpy(&gbyk_v4b_B.VCODE_MOD[0],
         &gbyk_v4b_B.sf_EmbeddedMATLABFunction_id.VCODE[0], 140U * sizeof(real_T));

  /* rewards = rwd_multipliers*rwd_val; */
  /* '<S2>:1:8' */
  zcEvent_idx_0 = false;
  i = 0;
  zcEvent_idx_1 = false;
  while ((!zcEvent_idx_1) && (i < 2)) {
    zcEvent_idx_2 = ((gbyk_v4b_B.offeredRewardsC[i] == 0.0) || rtIsNaN
                     (gbyk_v4b_B.offeredRewardsC[i]));
    if (!zcEvent_idx_2) {
      zcEvent_idx_0 = true;
      zcEvent_idx_1 = true;
    } else {
      i++;
    }
  }

  if ((int32_T)zcEvent_idx_0 > 0) {
    /* '<S2>:1:10' */
    /* '<S2>:1:11' */
    n2d = 15;

    /* '<S2>:1:12' */
    if (gbyk_v4b_B.offeredRewardsC[0] < 10.0) {
      /* '<S2>:1:14' */
      /* '<S2>:1:15' */
      stroke_width_col = rt_roundd_snf(gbyk_v4b_B.offeredRewardsC[0] + 48.0);
      if (stroke_width_col < 2.147483648E+9) {
        if (stroke_width_col >= -2.147483648E+9) {
          i = (int32_T)stroke_width_col;
        } else {
          i = MIN_int32_T;
        }
      } else {
        i = MAX_int32_T;
      }

      gbyk_v4b_B.VCODE_MOD[28] = i;
    } else if (gbyk_v4b_B.offeredRewardsC[0] < 100.0) {
      /* '<S2>:1:17' */
      /* score < $1 */
      /* '<S2>:1:18' */
      stroke_width_col = rt_roundd_snf(floor(gbyk_v4b_B.offeredRewardsC[0] /
        10.0));
      if (stroke_width_col < 2.147483648E+9) {
        if (stroke_width_col >= -2.147483648E+9) {
          n1 = (int32_T)stroke_width_col;
        } else {
          n1 = MIN_int32_T;
        }
      } else {
        n1 = MAX_int32_T;
      }

      /* we need to cast score to a double otherwise the arithmetic is wrong! */
      /* '<S2>:1:19' */
      /* '<S2>:1:21' */
      tmp_6 = n1 + 48LL;
      if (tmp_6 > 2147483647LL) {
        tmp_6 = 2147483647LL;
      } else {
        if (tmp_6 < -2147483648LL) {
          tmp_6 = -2147483648LL;
        }
      }

      gbyk_v4b_B.VCODE_MOD[28] = (int32_T)tmp_6;

      /* '<S2>:1:22' */
      n2d = 16;

      /* '<S2>:1:23' */
      tmp_6 = n1 * 10LL;
      if (tmp_6 > 2147483647LL) {
        tmp_6 = 2147483647LL;
      } else {
        if (tmp_6 < -2147483648LL) {
          tmp_6 = -2147483648LL;
        }
      }

      stroke_width_col = rt_roundd_snf(gbyk_v4b_B.offeredRewardsC[0] - (real_T)
        (int32_T)tmp_6);
      if (stroke_width_col < 2.147483648E+9) {
        if (stroke_width_col >= -2.147483648E+9) {
          i = (int32_T)stroke_width_col;
        } else {
          i = MIN_int32_T;
        }
      } else {
        i = MAX_int32_T;
      }

      tmp_6 = i + 48LL;
      if (tmp_6 > 2147483647LL) {
        tmp_6 = 2147483647LL;
      } else {
        if (tmp_6 < -2147483648LL) {
          tmp_6 = -2147483648LL;
        }
      }

      gbyk_v4b_B.VCODE_MOD[30] = (int32_T)tmp_6;
    } else {
      /* label < 100 */
      /* '<S2>:1:25' */
      stroke_width_col = rt_roundd_snf(floor(gbyk_v4b_B.offeredRewardsC[0] /
        100.0));
      if (stroke_width_col < 2.147483648E+9) {
        if (stroke_width_col >= -2.147483648E+9) {
          n1 = (int32_T)stroke_width_col;
        } else {
          n1 = MIN_int32_T;
        }
      } else {
        n1 = MAX_int32_T;
      }

      /* we need to cast score to a double otherwise the arithmetic is wrong! */
      /* '<S2>:1:26' */
      /* '<S2>:1:27' */
      tmp_6 = n1 * 100LL;
      if (tmp_6 > 2147483647LL) {
        tmp_6 = 2147483647LL;
      } else {
        if (tmp_6 < -2147483648LL) {
          tmp_6 = -2147483648LL;
        }
      }

      stroke_width_col = rt_roundd_snf(gbyk_v4b_B.offeredRewardsC[0] - (real_T)
        (int32_T)tmp_6);
      if (stroke_width_col < 2.147483648E+9) {
        if (stroke_width_col >= -2.147483648E+9) {
          i = (int32_T)stroke_width_col;
        } else {
          i = MIN_int32_T;
        }
      } else {
        i = MAX_int32_T;
      }

      khi = (int32_T)floor((real_T)i / 100.0);

      /* we need to cast score to a double otherwise the arithmetic is wrong! */
      /* '<S2>:1:28' */
      /* '<S2>:1:30' */
      tmp_6 = n1 + 48LL;
      if (tmp_6 > 2147483647LL) {
        tmp_6 = 2147483647LL;
      } else {
        if (tmp_6 < -2147483648LL) {
          tmp_6 = -2147483648LL;
        }
      }

      gbyk_v4b_B.VCODE_MOD[28] = (int32_T)tmp_6;

      /* '<S2>:1:32' */
      gbyk_v4b_B.VCODE_MOD[30] = (real_T)khi + 48.0;

      /* '<S2>:1:33' */
      n2d = 17;

      /* '<S2>:1:34' */
      tmp_6 = n1 * 100LL;
      if (tmp_6 > 2147483647LL) {
        tmp_6 = 2147483647LL;
      } else {
        if (tmp_6 < -2147483648LL) {
          tmp_6 = -2147483648LL;
        }
      }

      stroke_width_col = rt_roundd_snf(gbyk_v4b_B.offeredRewardsC[0] - (real_T)
        (int32_T)tmp_6);
      if (stroke_width_col < 2.147483648E+9) {
        if (stroke_width_col >= -2.147483648E+9) {
          i = (int32_T)stroke_width_col;
        } else {
          i = MIN_int32_T;
        }
      } else {
        i = MAX_int32_T;
      }

      tmp_6 = (int64_T)i - khi * 10;
      if (tmp_6 > 2147483647LL) {
        tmp_6 = 2147483647LL;
      } else {
        if (tmp_6 < -2147483648LL) {
          tmp_6 = -2147483648LL;
        }
      }

      tmp_6 = (int32_T)tmp_6 + 48LL;
      if (tmp_6 > 2147483647LL) {
        tmp_6 = 2147483647LL;
      } else {
        if (tmp_6 < -2147483648LL) {
          tmp_6 = -2147483648LL;
        }
      }

      gbyk_v4b_B.VCODE_MOD[32] = (int32_T)tmp_6;
    }

    /* '<S2>:1:36' */
    gbyk_v4b_B.VCODE_MOD[n2d << 1] = 0.0;

    /* terminate string */
  } else {
    /* '<S2>:1:38' */
    gbyk_v4b_B.VCODE_MOD[28] = 0.0;

    /* terminate string */
  }

  /* '<S2>:1:8' */
  zcEvent_idx_0 = false;
  i = 0;
  zcEvent_idx_1 = false;
  while ((!zcEvent_idx_1) && (i < 2)) {
    zcEvent_idx_2 = ((gbyk_v4b_B.offeredRewardsC[i] == 0.0) || rtIsNaN
                     (gbyk_v4b_B.offeredRewardsC[i]));
    if (!zcEvent_idx_2) {
      zcEvent_idx_0 = true;
      zcEvent_idx_1 = true;
    } else {
      i++;
    }
  }

  if ((int32_T)zcEvent_idx_0 > 0) {
    /* '<S2>:1:10' */
    /* '<S2>:1:11' */
    n2d = 15;

    /* '<S2>:1:12' */
    if (gbyk_v4b_B.offeredRewardsC[1] < 10.0) {
      /* '<S2>:1:14' */
      /* '<S2>:1:15' */
      stroke_width_col = rt_roundd_snf(gbyk_v4b_B.offeredRewardsC[1] + 48.0);
      if (stroke_width_col < 2.147483648E+9) {
        if (stroke_width_col >= -2.147483648E+9) {
          i = (int32_T)stroke_width_col;
        } else {
          i = MIN_int32_T;
        }
      } else {
        i = MAX_int32_T;
      }

      gbyk_v4b_B.VCODE_MOD[29] = i;
    } else if (gbyk_v4b_B.offeredRewardsC[1] < 100.0) {
      /* '<S2>:1:17' */
      /* score < $1 */
      /* '<S2>:1:18' */
      stroke_width_col = rt_roundd_snf(floor(gbyk_v4b_B.offeredRewardsC[1] /
        10.0));
      if (stroke_width_col < 2.147483648E+9) {
        if (stroke_width_col >= -2.147483648E+9) {
          n1 = (int32_T)stroke_width_col;
        } else {
          n1 = MIN_int32_T;
        }
      } else {
        n1 = MAX_int32_T;
      }

      /* we need to cast score to a double otherwise the arithmetic is wrong! */
      /* '<S2>:1:19' */
      /* '<S2>:1:21' */
      tmp_6 = n1 + 48LL;
      if (tmp_6 > 2147483647LL) {
        tmp_6 = 2147483647LL;
      } else {
        if (tmp_6 < -2147483648LL) {
          tmp_6 = -2147483648LL;
        }
      }

      gbyk_v4b_B.VCODE_MOD[29] = (int32_T)tmp_6;

      /* '<S2>:1:22' */
      n2d = 16;

      /* '<S2>:1:23' */
      tmp_6 = n1 * 10LL;
      if (tmp_6 > 2147483647LL) {
        tmp_6 = 2147483647LL;
      } else {
        if (tmp_6 < -2147483648LL) {
          tmp_6 = -2147483648LL;
        }
      }

      stroke_width_col = rt_roundd_snf(gbyk_v4b_B.offeredRewardsC[1] - (real_T)
        (int32_T)tmp_6);
      if (stroke_width_col < 2.147483648E+9) {
        if (stroke_width_col >= -2.147483648E+9) {
          i = (int32_T)stroke_width_col;
        } else {
          i = MIN_int32_T;
        }
      } else {
        i = MAX_int32_T;
      }

      tmp_6 = i + 48LL;
      if (tmp_6 > 2147483647LL) {
        tmp_6 = 2147483647LL;
      } else {
        if (tmp_6 < -2147483648LL) {
          tmp_6 = -2147483648LL;
        }
      }

      gbyk_v4b_B.VCODE_MOD[31] = (int32_T)tmp_6;
    } else {
      /* label < 100 */
      /* '<S2>:1:25' */
      stroke_width_col = rt_roundd_snf(floor(gbyk_v4b_B.offeredRewardsC[1] /
        100.0));
      if (stroke_width_col < 2.147483648E+9) {
        if (stroke_width_col >= -2.147483648E+9) {
          n1 = (int32_T)stroke_width_col;
        } else {
          n1 = MIN_int32_T;
        }
      } else {
        n1 = MAX_int32_T;
      }

      /* we need to cast score to a double otherwise the arithmetic is wrong! */
      /* '<S2>:1:26' */
      /* '<S2>:1:27' */
      tmp_6 = n1 * 100LL;
      if (tmp_6 > 2147483647LL) {
        tmp_6 = 2147483647LL;
      } else {
        if (tmp_6 < -2147483648LL) {
          tmp_6 = -2147483648LL;
        }
      }

      stroke_width_col = rt_roundd_snf(gbyk_v4b_B.offeredRewardsC[1] - (real_T)
        (int32_T)tmp_6);
      if (stroke_width_col < 2.147483648E+9) {
        if (stroke_width_col >= -2.147483648E+9) {
          i = (int32_T)stroke_width_col;
        } else {
          i = MIN_int32_T;
        }
      } else {
        i = MAX_int32_T;
      }

      khi = (int32_T)floor((real_T)i / 100.0);

      /* we need to cast score to a double otherwise the arithmetic is wrong! */
      /* '<S2>:1:28' */
      /* '<S2>:1:30' */
      tmp_6 = n1 + 48LL;
      if (tmp_6 > 2147483647LL) {
        tmp_6 = 2147483647LL;
      } else {
        if (tmp_6 < -2147483648LL) {
          tmp_6 = -2147483648LL;
        }
      }

      gbyk_v4b_B.VCODE_MOD[29] = (int32_T)tmp_6;

      /* '<S2>:1:32' */
      gbyk_v4b_B.VCODE_MOD[31] = (real_T)khi + 48.0;

      /* '<S2>:1:33' */
      n2d = 17;

      /* '<S2>:1:34' */
      tmp_6 = n1 * 100LL;
      if (tmp_6 > 2147483647LL) {
        tmp_6 = 2147483647LL;
      } else {
        if (tmp_6 < -2147483648LL) {
          tmp_6 = -2147483648LL;
        }
      }

      stroke_width_col = rt_roundd_snf(gbyk_v4b_B.offeredRewardsC[1] - (real_T)
        (int32_T)tmp_6);
      if (stroke_width_col < 2.147483648E+9) {
        if (stroke_width_col >= -2.147483648E+9) {
          i = (int32_T)stroke_width_col;
        } else {
          i = MIN_int32_T;
        }
      } else {
        i = MAX_int32_T;
      }

      tmp_6 = (int64_T)i - khi * 10;
      if (tmp_6 > 2147483647LL) {
        tmp_6 = 2147483647LL;
      } else {
        if (tmp_6 < -2147483648LL) {
          tmp_6 = -2147483648LL;
        }
      }

      tmp_6 = (int32_T)tmp_6 + 48LL;
      if (tmp_6 > 2147483647LL) {
        tmp_6 = 2147483647LL;
      } else {
        if (tmp_6 < -2147483648LL) {
          tmp_6 = -2147483648LL;
        }
      }

      gbyk_v4b_B.VCODE_MOD[33] = (int32_T)tmp_6;
    }

    /* '<S2>:1:36' */
    gbyk_v4b_B.VCODE_MOD[1 + (n2d << 1)] = 0.0;

    /* terminate string */
  } else {
    /* '<S2>:1:38' */
    gbyk_v4b_B.VCODE_MOD[29] = 0.0;

    /* terminate string */
  }

  /* End of MATLAB Function: '<Root>/AddTxt2TgtC' */

  /* Selector: '<S21>/Selector' */
  /* '<S2>:1:8' */
  i = (int32_T)gbyk_v4b_B.boxRow;
  for (idx_sizes = 0; idx_sizes < 25; idx_sizes++) {
    gbyk_v4b_B.Selector_d[idx_sizes] = gbyk_v4b_B.TargetTable[((idx_sizes << 5)
      + i) - 1];
  }

  /* End of Selector: '<S21>/Selector' */

  /* Concatenate: '<S21>/Matrix Concatenation' incorporates:
   *  Constant: '<S21>/state1_indices'
   *  Constant: '<S21>/state2_indices'
   *  Constant: '<S21>/state3_indices'
   *  Constant: '<S21>/state4_indices'
   *  Constant: '<S21>/state5_indices'
   */
  for (i = 0; i < 6; i++) {
    tmp_4[5 * i] = gbyk_v4b_P.Show_Box_attribcol1[i];
  }

  for (i = 0; i < 6; i++) {
    tmp_4[1 + 5 * i] = gbyk_v4b_P.Show_Box_attribcol2[i];
  }

  for (i = 0; i < 6; i++) {
    tmp_4[2 + 5 * i] = gbyk_v4b_P.state3_indices_Value_p[i];
  }

  for (i = 0; i < 6; i++) {
    tmp_4[3 + 5 * i] = gbyk_v4b_P.state4_indices_Value_o[i];
  }

  for (i = 0; i < 6; i++) {
    tmp_4[4 + 5 * i] = gbyk_v4b_P.state5_indices_Value_d[i];
  }

  memcpy(&gbyk_v4b_B.MatrixConcatenation1_h[0], &tmp_4[0], 30U * sizeof(real_T));

  /* End of Concatenate: '<S21>/Matrix Concatenation' */

  /* Constant: '<S21>/padder' */
  memcpy(&gbyk_v4b_B.MatrixConcatenation1_h[30], &gbyk_v4b_P.padder_Value_k[0],
         25U * sizeof(real_T));

  /* MATLAB Function: '<S21>/Embedded MATLAB Function' incorporates:
   *  Constant: '<S21>/Opacity'
   *  Constant: '<S21>/Target_Display'
   *  Constant: '<S21>/Target_Type'
   *  Constant: '<S21>/num_states'
   *  Constant: '<S21>/xpos_index'
   *  Constant: '<S21>/ypos_index'
   */
  gbyk_v4b_EmbeddedMATLABFunction(gbyk_v4b_B.Selector_d, gbyk_v4b_B.boxState,
    gbyk_v4b_P.Show_Box_target_type, gbyk_v4b_P.Show_Box_opacity,
    gbyk_v4b_P.Show_Box_target_display, gbyk_v4b_P.xpos_index_Value_f,
    gbyk_v4b_P.ypos_index_Value_l, gbyk_v4b_P.Show_Box_num_states,
    gbyk_v4b_B.MatrixConcatenation1_h, &gbyk_v4b_B.sf_EmbeddedMATLABFunction_c);

  /* Concatenate: '<Root>/Matrix Concatenation' */
  for (i = 0; i < 70; i++) {
    gbyk_v4b_B.MatrixConcatenation_b[10 * i] =
      gbyk_v4b_B.sf_EmbeddedMATLABFunction_i.VCODE[i];
  }

  for (i = 0; i < 70; i++) {
    gbyk_v4b_B.MatrixConcatenation_b[1 + 10 * i] = gbyk_v4b_B.VCODE_MOD_n[i << 1];
    gbyk_v4b_B.MatrixConcatenation_b[2 + 10 * i] = gbyk_v4b_B.VCODE_MOD_n[(i <<
      1) + 1];
  }

  for (i = 0; i < 70; i++) {
    gbyk_v4b_B.MatrixConcatenation_b[3 + 10 * i] = gbyk_v4b_B.VCODES_out[i << 1];
    gbyk_v4b_B.MatrixConcatenation_b[4 + 10 * i] = gbyk_v4b_B.VCODES_out[(i << 1)
      + 1];
  }

  for (i = 0; i < 70; i++) {
    gbyk_v4b_B.MatrixConcatenation_b[5 + 10 * i] = gbyk_v4b_B.VCODE_mod[i];
  }

  for (i = 0; i < 70; i++) {
    gbyk_v4b_B.MatrixConcatenation_b[6 + 10 * i] =
      gbyk_v4b_B.sf_EmbeddedMATLABFunction_b.VCODE[i];
  }

  for (i = 0; i < 70; i++) {
    gbyk_v4b_B.MatrixConcatenation_b[7 + 10 * i] = gbyk_v4b_B.VCODE_MOD[i << 1];
    gbyk_v4b_B.MatrixConcatenation_b[8 + 10 * i] = gbyk_v4b_B.VCODE_MOD[(i << 1)
      + 1];
  }

  for (i = 0; i < 70; i++) {
    gbyk_v4b_B.MatrixConcatenation_b[9 + 10 * i] =
      gbyk_v4b_B.sf_EmbeddedMATLABFunction_c.VCODE[i];
  }

  /* End of Concatenate: '<Root>/Matrix Concatenation' */

  /* RateTransition: '<S15>/Rate Transition2' */
  if (gbyk_v4b_M->Timing.RateInteraction.TID1_4) {
    memcpy(&gbyk_v4b_B.RateTransition2[0], &gbyk_v4b_B.MatrixConcatenation_b[0],
           700U * sizeof(real_T));
  }

  /* End of RateTransition: '<S15>/Rate Transition2' */

  /* Outputs for Atomic SubSystem: '<S15>/PVC_core' */
  gbyk_v4b_PVC_coreTID0();

  /* End of Outputs for SubSystem: '<S15>/PVC_core' */

  /* DataTypeConversion: '<S15>/Convert' */
  gbyk_v4b_B.Convert = gbyk_v4b_B.RateTransition1_h;

  /* DataTypeConversion: '<S30>/Last Frame Sent' */
  gbyk_v4b_B.LastFrameSent = gbyk_v4b_B.Convert;

  /* RateTransition: '<S30>/Rate Transition3' */
  if (gbyk_v4b_M->Timing.RateInteraction.TID1_3) {
    gbyk_v4b_B.RateTransition3 = gbyk_v4b_B.LastFrameSent;
  }

  /* End of RateTransition: '<S30>/Rate Transition3' */

  /* Level2 S-Function Block: '<S15>/Receive' (xpcudpbytereceive) */
  {
    SimStruct *rts = gbyk_v4b_M->childSfunctions[42];
    sfcnOutputs(rts, 0);
  }

  /* Unpack: <S15>/Unpack */
  (void) memcpy(&gbyk_v4b_B.Unpack_c, &gbyk_v4b_B.Receive_o1[0],
                4);

  /* DataTypeConversion: '<S15>/Convert1' */
  gbyk_v4b_B.Convert1_a = gbyk_v4b_B.Unpack_c;

  /* MATLAB Function: '<S15>/MATLAB Function' */
  /* MATLAB Function 'Process_Video_CMD/MATLAB Function': '<S297>:1' */
  /* '<S297>:1:11' */
  gbyk_v4b_B.last_frame_ack = gbyk_v4b_DW.last_valid_frame_ack;

  /* '<S297>:1:12' */
  gbyk_v4b_B.last_perm_ack = gbyk_v4b_DW.last_perm_frame_ack;
  if (gbyk_v4b_B.Receive_o2 == 8.0) {
    /* '<S297>:1:14' */
    /* '<S297>:1:15' */
    gbyk_v4b_B.last_perm_ack = gbyk_v4b_B.Convert1_a;

    /* '<S297>:1:16' */
    gbyk_v4b_DW.last_perm_frame_ack = gbyk_v4b_B.Convert1_a;
  } else {
    if (gbyk_v4b_B.Receive_o2 == 4.0) {
      /* '<S297>:1:17' */
      /* DEX-2765 - when we get more than 4 bytes (1 int) then it's a special ACK */
      /* for permanent targets. This allows us to signal that the target */
      /* has been accepted sooner. */
      /* '<S297>:1:21' */
      gbyk_v4b_B.last_frame_ack = gbyk_v4b_B.Convert1_a;

      /* '<S297>:1:22' */
      gbyk_v4b_DW.last_valid_frame_ack = gbyk_v4b_B.Convert1_a;

      /* '<S297>:1:23' */
      gbyk_v4b_DW.last_perm_frame_ack = gbyk_v4b_B.Convert1_a;

      /* '<S297>:1:24' */
      gbyk_v4b_B.last_perm_ack = gbyk_v4b_B.Convert1_a;
    }
  }

  /* End of MATLAB Function: '<S15>/MATLAB Function' */

  /* DataTypeConversion: '<S30>/Last Frame Acknowledged' */
  gbyk_v4b_B.LastFrameAcknowledged = gbyk_v4b_B.last_frame_ack;

  /* RateTransition: '<S30>/Rate Transition2' */
  if (gbyk_v4b_M->Timing.RateInteraction.TID1_3) {
    gbyk_v4b_B.RateTransition2_e = gbyk_v4b_B.LastFrameAcknowledged;
  }

  /* End of RateTransition: '<S30>/Rate Transition2' */

  /* DataTypeConversion: '<S30>/Button Status' */
  gbyk_v4b_B.ButtonStatus = gbyk_v4b_B.calibrationButtonBits;

  /* RateTransition: '<S30>/Rate Transition1' */
  if (gbyk_v4b_M->Timing.RateInteraction.TID1_3) {
    gbyk_v4b_B.RateTransition1 = gbyk_v4b_B.ButtonStatus;
  }

  /* End of RateTransition: '<S30>/Rate Transition1' */

  /* DataTypeConversion: '<S30>/Servo update count' */
  gbyk_v4b_B.Servoupdatecount = gbyk_v4b_B.servoCounter;

  /* RateTransition: '<S30>/Rate Transition' */
  if (gbyk_v4b_M->Timing.RateInteraction.TID1_3) {
    gbyk_v4b_B.RateTransition = gbyk_v4b_B.Servoupdatecount;
  }

  /* End of RateTransition: '<S30>/Rate Transition' */

  /* DataTypeConversion: '<S30>/Task Control Button' */
  gbyk_v4b_B.TaskControlButton = gbyk_v4b_B.value;

  /* RateTransition: '<S30>/Rate Transition11' */
  if (gbyk_v4b_M->Timing.RateInteraction.TID1_3) {
    gbyk_v4b_B.RateTransition11 = gbyk_v4b_B.TaskControlButton;

    /* RateTransition: '<S28>/TmpRTBAtNumber of Event CodesOutport1' */
    gbyk_v4b_B.TmpRTBAtNumberofEventCodesOutport1 =
      gbyk_v4b_DW.TmpRTBAtNumberofEventCodesOutport1_Buffer0;
  }

  /* End of RateTransition: '<S30>/Rate Transition11' */

  /* DataTypeConversion: '<S28>/Event Codes' */
  gbyk_v4b_B.EventCodes = gbyk_v4b_B.event_code;

  /* RateTransition: '<S4>/Rate Transition2' */
  if (gbyk_v4b_M->Timing.RateInteraction.TID1_3) {
    gbyk_v4b_B.RateTransition2_ea[0] =
      gbyk_v4b_B.TmpRTBAtNumberofEventCodesOutport1;
    gbyk_v4b_B.RateTransition2_ea[1] = gbyk_v4b_B.EventCodes;
  }

  /* End of RateTransition: '<S4>/Rate Transition2' */

  /* SignalConversion: '<S43>/TmpSignal ConversionAt SFunction Inport1' incorporates:
   *  MATLAB Function: '<S42>/MATLAB Function'
   */
  gbyk_v4b_B.TmpSignalConversionAtSFunctionInport1_m[0] =
    gbyk_v4b_B.ByteReversal1[2];
  gbyk_v4b_B.TmpSignalConversionAtSFunctionInport1_m[1] =
    gbyk_v4b_B.ByteReversal1_f[2];

  /* MATLAB Function: '<S42>/MATLAB Function' */
  /* MATLAB Function 'DataLogging/Create KINARM Data Subsystem/select KINData/MATLAB Function': '<S43>:1' */
  /* when you have an int32 or uint32 and you need to send it to Dex this is */
  /* the right way to do it.  */
  /* '<S43>:1:7' */
  memcpy(&ss[0], &gbyk_v4b_B.TmpSignalConversionAtSFunctionInport1_m[0], (size_t)
         2 * sizeof(real32_T));

  /* '<S43>:1:8' */
  gbyk_v4b_B.dd_out[0] = ss[0];
  gbyk_v4b_B.dd_out[1] = ss[1];

  /* RateTransition: '<S29>/Rate Transition' */
  if (gbyk_v4b_M->Timing.RateInteraction.TID1_3) {
    gbyk_v4b_B.RateTransition_k[0] = gbyk_v4b_B.link_angle_b[0];
    gbyk_v4b_B.RateTransition_k[1] = gbyk_v4b_B.link_angle_b[1];
    gbyk_v4b_B.RateTransition_k[2] = gbyk_v4b_B.link_velocity_k[0];
    gbyk_v4b_B.RateTransition_k[3] = gbyk_v4b_B.link_velocity_k[1];
    gbyk_v4b_B.RateTransition_k[4] = gbyk_v4b_B.link_acceleration_c[0];
    gbyk_v4b_B.RateTransition_k[5] = gbyk_v4b_B.link_acceleration_c[1];
    gbyk_v4b_B.RateTransition_k[6] = gbyk_v4b_B.hand_position_g[0];
    gbyk_v4b_B.RateTransition_k[7] = gbyk_v4b_B.hand_position_g[1];
    gbyk_v4b_B.RateTransition_k[8] = gbyk_v4b_B.motor_torque_cmd_b[0];
    gbyk_v4b_B.RateTransition_k[9] = gbyk_v4b_B.motor_torque_cmd_b[1];
    gbyk_v4b_B.RateTransition_k[10] = gbyk_v4b_B.force_sensor_force_xyz_g[0];
    gbyk_v4b_B.RateTransition_k[11] = gbyk_v4b_B.force_sensor_force_xyz_g[1];
    gbyk_v4b_B.RateTransition_k[12] = gbyk_v4b_B.force_sensor_force_xyz_g[2];
    gbyk_v4b_B.RateTransition_k[13] = gbyk_v4b_B.force_sensor_torque_xyz_g[0];
    gbyk_v4b_B.RateTransition_k[14] = gbyk_v4b_B.force_sensor_torque_xyz_g[1];
    gbyk_v4b_B.RateTransition_k[15] = gbyk_v4b_B.force_sensor_torque_xyz_g[2];
    gbyk_v4b_B.RateTransition_k[16] = gbyk_v4b_B.force_sensor_timestamp_k;
    gbyk_v4b_B.RateTransition_k[17] = gbyk_v4b_B.dd_out[0];
    gbyk_v4b_B.RateTransition_k[18] = gbyk_v4b_B.torquefeedback1[0];
    gbyk_v4b_B.RateTransition_k[19] = gbyk_v4b_B.torquefeedback1[1];
    gbyk_v4b_B.RateTransition_k[20] = gbyk_v4b_B.link_angle[0];
    gbyk_v4b_B.RateTransition_k[21] = gbyk_v4b_B.link_angle[1];
    gbyk_v4b_B.RateTransition_k[22] = gbyk_v4b_B.link_velocity[0];
    gbyk_v4b_B.RateTransition_k[23] = gbyk_v4b_B.link_velocity[1];
    gbyk_v4b_B.RateTransition_k[24] = gbyk_v4b_B.link_acceleration[0];
    gbyk_v4b_B.RateTransition_k[25] = gbyk_v4b_B.link_acceleration[1];
    gbyk_v4b_B.RateTransition_k[26] = gbyk_v4b_B.hand_position[0];
    gbyk_v4b_B.RateTransition_k[27] = gbyk_v4b_B.hand_position[1];
    gbyk_v4b_B.RateTransition_k[28] = gbyk_v4b_B.motor_torque_cmd[0];
    gbyk_v4b_B.RateTransition_k[29] = gbyk_v4b_B.motor_torque_cmd[1];
    gbyk_v4b_B.RateTransition_k[30] = gbyk_v4b_B.force_sensor_force_xyz[0];
    gbyk_v4b_B.RateTransition_k[31] = gbyk_v4b_B.force_sensor_force_xyz[1];
    gbyk_v4b_B.RateTransition_k[32] = gbyk_v4b_B.force_sensor_force_xyz[2];
    gbyk_v4b_B.RateTransition_k[33] = gbyk_v4b_B.force_sensor_torque_xyz[0];
    gbyk_v4b_B.RateTransition_k[34] = gbyk_v4b_B.force_sensor_torque_xyz[1];
    gbyk_v4b_B.RateTransition_k[35] = gbyk_v4b_B.force_sensor_torque_xyz[2];
    gbyk_v4b_B.RateTransition_k[36] = gbyk_v4b_B.force_sensor_timestamp;
    gbyk_v4b_B.RateTransition_k[37] = gbyk_v4b_B.dd_out[1];
    gbyk_v4b_B.RateTransition_k[38] = gbyk_v4b_B.torquefeedback1[2];
    gbyk_v4b_B.RateTransition_k[39] = gbyk_v4b_B.torquefeedback1[3];

    /* RateTransition: '<S29>/Rate Transition2' */
    gbyk_v4b_B.RateTransition2_er[0] = gbyk_v4b_B.Convert19[0];
    gbyk_v4b_B.RateTransition2_er[1] = gbyk_v4b_B.Convert19[1];
    gbyk_v4b_B.RateTransition2_er[2] = gbyk_v4b_B.Convert19[2];
    gbyk_v4b_B.RateTransition2_er[3] = gbyk_v4b_B.Convert1_p;
    gbyk_v4b_B.RateTransition2_er[4] = gbyk_v4b_B.Convert4[0];
    gbyk_v4b_B.RateTransition2_er[5] = gbyk_v4b_B.Convert4[1];
    gbyk_v4b_B.RateTransition2_er[6] = gbyk_v4b_B.Convert4[2];
    gbyk_v4b_B.RateTransition2_er[7] = gbyk_v4b_B.pupil_GLOBAL[0];
    gbyk_v4b_B.RateTransition2_er[8] = gbyk_v4b_B.pupil_GLOBAL[1];
    gbyk_v4b_B.RateTransition2_er[9] = gbyk_v4b_B.pupil_GLOBAL[2];
    gbyk_v4b_B.RateTransition2_er[10] = gbyk_v4b_B.RateTransition_kg[0];
    gbyk_v4b_B.RateTransition2_er[11] = gbyk_v4b_B.RateTransition_kg[1];
    gbyk_v4b_B.RateTransition2_er[12] = gbyk_v4b_B.RateTransition_kg[2];
  }

  /* End of RateTransition: '<S29>/Rate Transition' */

  /* Outputs for Atomic SubSystem: '<S4>/Poll Force Plates' */
  gbyk_v4b_PollForcePlatesTID0();

  /* End of Outputs for SubSystem: '<S4>/Poll Force Plates' */

  /* RateTransition: '<S29>/Rate Transition3' */
  if (gbyk_v4b_M->Timing.RateInteraction.TID1_3) {
    memcpy(&gbyk_v4b_B.RateTransition3_n[0], &gbyk_v4b_B.Convert19_e[0], 14U *
           sizeof(real_T));
  }

  /* End of RateTransition: '<S29>/Rate Transition3' */

  /* DataTypeConversion: '<S29>/touint' */
  stroke_width_col = gbyk_v4b_B.motor_status_c;
  if (stroke_width_col < 4.294967296E+9) {
    if (stroke_width_col >= 0.0) {
      tmp_5 = (uint32_T)stroke_width_col;
    } else {
      tmp_5 = 0U;
    }
  } else {
    tmp_5 = MAX_uint32_T;
  }

  gbyk_v4b_B.touint[0] = tmp_5;
  stroke_width_col = gbyk_v4b_B.motor_status;
  if (stroke_width_col < 4.294967296E+9) {
    if (stroke_width_col >= 0.0) {
      tmp_5 = (uint32_T)stroke_width_col;
    } else {
      tmp_5 = 0U;
    }
  } else {
    tmp_5 = MAX_uint32_T;
  }

  gbyk_v4b_B.touint[1] = tmp_5;
  stroke_width_col = gbyk_v4b_B.torquefeedback1[4];
  if (stroke_width_col < 4.294967296E+9) {
    if (stroke_width_col >= 0.0) {
      tmp_5 = (uint32_T)stroke_width_col;
    } else {
      tmp_5 = 0U;
    }
  } else {
    tmp_5 = MAX_uint32_T;
  }

  gbyk_v4b_B.touint[2] = tmp_5;
  stroke_width_col = gbyk_v4b_B.torquefeedback1[5];
  if (stroke_width_col < 4.294967296E+9) {
    if (stroke_width_col >= 0.0) {
      tmp_5 = (uint32_T)stroke_width_col;
    } else {
      tmp_5 = 0U;
    }
  } else {
    tmp_5 = MAX_uint32_T;
  }

  gbyk_v4b_B.touint[3] = tmp_5;
  stroke_width_col = gbyk_v4b_B.torquefeedback1[6];
  if (stroke_width_col < 4.294967296E+9) {
    if (stroke_width_col >= 0.0) {
      tmp_5 = (uint32_T)stroke_width_col;
    } else {
      tmp_5 = 0U;
    }
  } else {
    tmp_5 = MAX_uint32_T;
  }

  gbyk_v4b_B.touint[4] = tmp_5;
  stroke_width_col = gbyk_v4b_B.torquefeedback1[7];
  if (stroke_width_col < 4.294967296E+9) {
    if (stroke_width_col >= 0.0) {
      tmp_5 = (uint32_T)stroke_width_col;
    } else {
      tmp_5 = 0U;
    }
  } else {
    tmp_5 = MAX_uint32_T;
  }

  gbyk_v4b_B.touint[5] = tmp_5;

  /* End of DataTypeConversion: '<S29>/touint' */

  /* MATLAB Function: '<S29>/bitfield' */
  /* MATLAB Function 'DataLogging/Create KINARM Data Subsystem/bitfield': '<S40>:1' */
  /* the bits are 0=motor enabled, 1=disabled. This logic is  */
  /* attempting to reverse that.  */
  /* '<S40>:1:5' */
  /* '<S40>:1:6' */
  /* '<S40>:1:8' */
  /* '<S40>:1:11' */
  gbyk_v4b_B.bitfield = (((((((gbyk_v4b_B.touint[3] & 1U) << 1U) +
    (gbyk_v4b_B.touint[2] & 1U)) + ((gbyk_v4b_B.touint[4] & 1U) << 2U)) +
    ((gbyk_v4b_B.touint[5] & 1U) << 3U)) << 4U) + (((gbyk_v4b_B.touint[1] ^ 3U)
    & 3U) << 2U)) + ((gbyk_v4b_B.touint[0] ^ 3U) & 3U);

  /* RateTransition: '<S29>/Rate Transition1' */
  if (gbyk_v4b_M->Timing.RateInteraction.TID1_3) {
    gbyk_v4b_B.RateTransition1_n = gbyk_v4b_B.bitfield;
  }

  /* End of RateTransition: '<S29>/Rate Transition1' */

  /* SignalConversion: '<Root>/ConcatBufferAtVector ConcatenateIn1' */
  gbyk_v4b_B.VectorConcatenate[0] = gbyk_v4b_B.targetB_row[0];
  gbyk_v4b_B.VectorConcatenate[1] = gbyk_v4b_B.targetB_row[1];

  /* SignalConversion: '<Root>/ConcatBufferAtVector ConcatenateIn2' */
  gbyk_v4b_B.VectorConcatenate[2] = gbyk_v4b_B.targetB_state[0];
  gbyk_v4b_B.VectorConcatenate[3] = gbyk_v4b_B.targetB_state[1];

  /* SignalConversion: '<Root>/ConcatBufferAtVector ConcatenateIn3' */
  gbyk_v4b_B.VectorConcatenate[4] = gbyk_v4b_B.offeredRewards[0];
  gbyk_v4b_B.VectorConcatenate[5] = gbyk_v4b_B.offeredRewards[1];

  /* SignalConversion: '<Root>/ConcatBufferAtVector ConcatenateIn4' */
  gbyk_v4b_B.VectorConcatenate[6] = gbyk_v4b_B.score;

  /* DataTypeConversion: '<Root>/Data Type Conversion3' */
  gbyk_v4b_B.VectorConcatenate[7] = gbyk_v4b_B.VectorConcatenate1[0];
  gbyk_v4b_B.VectorConcatenate[8] = gbyk_v4b_B.VectorConcatenate1[1];
  gbyk_v4b_B.VectorConcatenate[9] = gbyk_v4b_B.VectorConcatenate1[2];
  gbyk_v4b_B.VectorConcatenate[10] = gbyk_v4b_B.VectorConcatenate1[3];

  /* SignalConversion: '<Root>/ConcatBufferAtVector ConcatenateIn6' */
  gbyk_v4b_B.VectorConcatenate[11] = 0.0;

  /* Trigonometry: '<Root>/Trigonometric Function' */
  gbyk_v4b_B.TrigonometricFunction = rt_atan2d_snf(gbyk_v4b_B.Switch[1],
    gbyk_v4b_B.Switch[0]);

  /* SignalConversion: '<Root>/ConcatBufferAtVector ConcatenateIn7' */
  gbyk_v4b_B.VectorConcatenate[12] = gbyk_v4b_B.TrigonometricFunction;

  /* SignalConversion: '<Root>/ConcatBufferAtVector ConcatenateIn8' */
  gbyk_v4b_B.VectorConcatenate[13] = gbyk_v4b_B.targetC_row[0];
  gbyk_v4b_B.VectorConcatenate[14] = gbyk_v4b_B.targetC_row[1];

  /* SignalConversion: '<Root>/ConcatBufferAtVector ConcatenateIn9' */
  gbyk_v4b_B.VectorConcatenate[15] = gbyk_v4b_B.targetC_state[0];
  gbyk_v4b_B.VectorConcatenate[16] = gbyk_v4b_B.targetC_state[1];

  /* SignalConversion: '<Root>/ConcatBufferAtVector ConcatenateIn10' */
  gbyk_v4b_B.VectorConcatenate[17] = gbyk_v4b_B.boxState;

  /* SignalConversion: '<Root>/ConcatBufferAtVector ConcatenateIn11' */
  gbyk_v4b_B.VectorConcatenate[18] = gbyk_v4b_B.offeredRewardsC[0];
  gbyk_v4b_B.VectorConcatenate[19] = gbyk_v4b_B.offeredRewardsC[1];

  /* DataTypeConversion: '<S26>/Analog Data' */
  memcpy(&gbyk_v4b_B.AnalogData[0], &gbyk_v4b_B.VectorConcatenate[0], 20U *
         sizeof(real_T));

  /* RateTransition: '<S26>/Rate Transition1' */
  if (gbyk_v4b_M->Timing.RateInteraction.TID1_3) {
    memcpy(&gbyk_v4b_B.RateTransition1_c[0], &gbyk_v4b_B.AnalogData[0], 20U *
           sizeof(real_T));
  }

  /* End of RateTransition: '<S26>/Rate Transition1' */

  /* DataTypeConversion: '<S27>/Custom Data1' */
  gbyk_v4b_B.CustomData1[0] = gbyk_v4b_B.statusInts[0];
  gbyk_v4b_B.CustomData1[1] = gbyk_v4b_B.statusInts[1];
  gbyk_v4b_B.CustomData1[2] = gbyk_v4b_B.statusInts[2];
  gbyk_v4b_B.CustomData1[3] = gbyk_v4b_B.statusInts[3];
  for (idx_sizes = 0; idx_sizes < 6; idx_sizes++) {
    gbyk_v4b_B.CustomData1[idx_sizes + 4] =
      gbyk_v4b_B.DataTypeConversion_nq[idx_sizes];
  }

  /* End of DataTypeConversion: '<S27>/Custom Data1' */

  /* SignalConversion: '<S258>/TmpSignal ConversionAt SFunction Inport1' incorporates:
   *  MATLAB Function: '<S38>/delta'
   */
  gbyk_v4b_B.TmpSignalConversionAtSFunctionInport1[0] = gbyk_v4b_B.link_angle_b
    [0];
  gbyk_v4b_B.TmpSignalConversionAtSFunctionInport1[1] = gbyk_v4b_B.link_angle_b
    [1];
  gbyk_v4b_B.TmpSignalConversionAtSFunctionInport1[2] = gbyk_v4b_B.link_angle[0];
  gbyk_v4b_B.TmpSignalConversionAtSFunctionInport1[3] = gbyk_v4b_B.link_angle[1];

  /* SignalConversion: '<S258>/TmpSignal ConversionAt SFunction Inport2' incorporates:
   *  MATLAB Function: '<S38>/delta'
   */
  gbyk_v4b_B.TmpSignalConversionAtSFunctionInport2[0] =
    gbyk_v4b_B.sf_split_primary.link_angles[0];
  gbyk_v4b_B.TmpSignalConversionAtSFunctionInport2[1] =
    gbyk_v4b_B.sf_split_primary.link_angles[1];
  gbyk_v4b_B.TmpSignalConversionAtSFunctionInport2[2] =
    gbyk_v4b_B.sf_split_primary1.link_angles[0];
  gbyk_v4b_B.TmpSignalConversionAtSFunctionInport2[3] =
    gbyk_v4b_B.sf_split_primary1.link_angles[1];

  /* MATLAB Function: '<S38>/delta' */
  /* MATLAB Function 'DataLogging/compare encoders/delta': '<S258>:1' */
  /* '<S258>:1:4' */
  gbyk_v4b_B.deltas[0] = gbyk_v4b_B.TmpSignalConversionAtSFunctionInport1[0] -
    gbyk_v4b_B.TmpSignalConversionAtSFunctionInport2[0];
  gbyk_v4b_B.deltas[1] = gbyk_v4b_B.TmpSignalConversionAtSFunctionInport1[1] -
    gbyk_v4b_B.TmpSignalConversionAtSFunctionInport2[1];
  gbyk_v4b_B.deltas[2] = gbyk_v4b_B.TmpSignalConversionAtSFunctionInport1[2] -
    gbyk_v4b_B.TmpSignalConversionAtSFunctionInport2[2];
  gbyk_v4b_B.deltas[3] = gbyk_v4b_B.TmpSignalConversionAtSFunctionInport1[3] -
    gbyk_v4b_B.TmpSignalConversionAtSFunctionInport2[3];

  /* RateTransition: '<S27>/Rate Transition' */
  gbyk_v4b_B.RateTransition_b[0] = gbyk_v4b_B.deltas[0];
  gbyk_v4b_B.RateTransition_b[1] = gbyk_v4b_B.deltas[1];
  gbyk_v4b_B.RateTransition_b[2] = gbyk_v4b_B.deltas[2];
  gbyk_v4b_B.RateTransition_b[3] = gbyk_v4b_B.deltas[3];

  /* RateTransition: '<S27>/Rate Transition1' incorporates:
   *  Constant: '<S4>/seconds_remaining'
   */
  gbyk_v4b_B.RateTransition1_b = gbyk_v4b_P.seconds_remaining_Value;

  /* RateTransition: '<S27>/Rate Transition2' */
  if (gbyk_v4b_M->Timing.RateInteraction.TID1_4) {
    gbyk_v4b_B.RateTransition2_eo = gbyk_v4b_DW.RateTransition2_Buffer0;
  }

  /* End of RateTransition: '<S27>/Rate Transition2' */

  /* RateTransition: '<S4>/Rate Transition' incorporates:
   *  Constant: '<S27>/custom_version'
   */
  if (gbyk_v4b_M->Timing.RateInteraction.TID1_3) {
    gbyk_v4b_B.RateTransition_d[0] = gbyk_v4b_ConstB.Width_g;
    gbyk_v4b_B.RateTransition_d[1] = gbyk_v4b_P.custom_version_Value;
    memcpy(&gbyk_v4b_B.RateTransition_d[2], &gbyk_v4b_B.CustomData1[0], 10U *
           sizeof(real_T));
    gbyk_v4b_B.RateTransition_d[12] = gbyk_v4b_B.RateTransition_b[0];
    gbyk_v4b_B.RateTransition_d[13] = gbyk_v4b_B.RateTransition_b[1];
    gbyk_v4b_B.RateTransition_d[14] = gbyk_v4b_B.RateTransition_b[2];
    gbyk_v4b_B.RateTransition_d[15] = gbyk_v4b_B.RateTransition_b[3];
    gbyk_v4b_B.RateTransition_d[16] = gbyk_v4b_B.RateTransition1_b;
    gbyk_v4b_B.RateTransition_d[17] = gbyk_v4b_B.RateTransition2_eo;
  }

  /* End of RateTransition: '<S4>/Rate Transition' */

  /* Outputs for Atomic SubSystem: '<S4>/Network Transfer Subsystem' */
  gbyk_v4b_NetworkTransferSubsystemTID0();

  /* End of Outputs for SubSystem: '<S4>/Network Transfer Subsystem' */

  /* Sum: '<S4>/AddTorques' incorporates:
   *  Constant: '<S4>/ZeroEPTorque'
   *  Constant: '<S4>/ZeroTorque'
   */
  gbyk_v4b_B.AddTorques[0] = gbyk_v4b_P.ZeroTorque_Value[0] +
    gbyk_v4b_P.ZeroEPTorque_Value[0];
  gbyk_v4b_B.AddTorques[1] = gbyk_v4b_P.ZeroTorque_Value[1] +
    gbyk_v4b_P.ZeroEPTorque_Value[1];
  gbyk_v4b_B.AddTorques[2] = gbyk_v4b_P.ZeroTorque_Value[2] +
    gbyk_v4b_P.ZeroEPTorque_Value[2];
  gbyk_v4b_B.AddTorques[3] = gbyk_v4b_P.ZeroTorque_Value[3] +
    gbyk_v4b_P.ZeroEPTorque_Value[3];

  /* Memory: '<S4>/Memory1' */
  gbyk_v4b_B.Memory1 = gbyk_v4b_DW.Memory1_PreviousInput;

  /* Memory: '<S4>/Memory2' */
  gbyk_v4b_B.ArmOrientation = gbyk_v4b_DW.Memory2_1_PreviousInput;

  /* Memory: '<S4>/Memory2' */
  gbyk_v4b_B.M1orientation = gbyk_v4b_DW.Memory2_2_PreviousInput;

  /* Memory: '<S4>/Memory2' */
  gbyk_v4b_B.M2Orientation = gbyk_v4b_DW.Memory2_3_PreviousInput;

  /* Memory: '<S4>/Memory2' */
  gbyk_v4b_B.M1GearRatio = gbyk_v4b_DW.Memory2_4_PreviousInput;

  /* Memory: '<S4>/Memory2' */
  gbyk_v4b_B.M2GearRatio = gbyk_v4b_DW.Memory2_5_PreviousInput;

  /* Memory: '<S4>/Memory2' */
  gbyk_v4b_B.torqueconstant = gbyk_v4b_DW.Memory2_9_PreviousInput;

  /* Memory: '<S4>/Memory2' */
  gbyk_v4b_B.ArmOrientation_c = gbyk_v4b_DW.Memory2_18_PreviousInput;

  /* Memory: '<S4>/Memory2' */
  gbyk_v4b_B.M1orientation_f = gbyk_v4b_DW.Memory2_19_PreviousInput;

  /* Memory: '<S4>/Memory2' */
  gbyk_v4b_B.M2Orientation_c = gbyk_v4b_DW.Memory2_20_PreviousInput;

  /* Memory: '<S4>/Memory2' */
  gbyk_v4b_B.M1GearRatio_h = gbyk_v4b_DW.Memory2_21_PreviousInput;

  /* Memory: '<S4>/Memory2' */
  gbyk_v4b_B.M2GearRatio_d = gbyk_v4b_DW.Memory2_22_PreviousInput;

  /* Memory: '<S4>/Memory2' */
  gbyk_v4b_B.torqueconstant_m = gbyk_v4b_DW.Memory2_26_PreviousInput;

  /* Outputs for Atomic SubSystem: '<S4>/apply loads' */
  gbyk_v4b_applyloads();

  /* End of Outputs for SubSystem: '<S4>/apply loads' */

  /* Memory: '<S4>/Memory2' */
  gbyk_v4b_B.isEP = gbyk_v4b_DW.Memory2_10_PreviousInput;

  /* Memory: '<S4>/Memory2' */
  gbyk_v4b_B.isHumanExo = gbyk_v4b_DW.Memory2_11_PreviousInput;

  /* Memory: '<S4>/Memory2' */
  gbyk_v4b_B.isNHPExo = gbyk_v4b_DW.Memory2_12_PreviousInput;

  /* Memory: '<S4>/Memory2' */
  gbyk_v4b_B.isClassicExo = gbyk_v4b_DW.Memory2_13_PreviousInput;

  /* Memory: '<S4>/Memory2' */
  gbyk_v4b_B.isUTSExo = gbyk_v4b_DW.Memory2_14_PreviousInput;

  /* Memory: '<S4>/Memory2' */
  gbyk_v4b_B.isPMAC = gbyk_v4b_DW.Memory2_15_PreviousInput;

  /* Memory: '<S4>/Memory2' */
  gbyk_v4b_B.isECAT = gbyk_v4b_DW.Memory2_16_PreviousInput;

  /* Memory: '<S4>/Memory2' */
  gbyk_v4b_B.robotRevision = gbyk_v4b_DW.Memory2_17_PreviousInput;

  /* Memory: '<S4>/Memory2' */
  gbyk_v4b_B.HasSecondaryEnc = gbyk_v4b_DW.Memory2_23_PreviousInput;

  /* Memory: '<S4>/Memory2' */
  gbyk_v4b_B.robottype = gbyk_v4b_DW.Memory2_24_PreviousInput;

  /* Memory: '<S4>/Memory2' */
  gbyk_v4b_B.robotversion = gbyk_v4b_DW.Memory2_25_PreviousInput;

  /* Memory: '<S4>/Memory2' */
  gbyk_v4b_B.isEP_k = gbyk_v4b_DW.Memory2_27_PreviousInput;

  /* Memory: '<S4>/Memory2' */
  gbyk_v4b_B.isHumanExo_p = gbyk_v4b_DW.Memory2_28_PreviousInput;

  /* Memory: '<S4>/Memory2' */
  gbyk_v4b_B.isNHPExo_n = gbyk_v4b_DW.Memory2_29_PreviousInput;

  /* Memory: '<S4>/Memory2' */
  gbyk_v4b_B.isClassicExo_g = gbyk_v4b_DW.Memory2_30_PreviousInput;

  /* Memory: '<S4>/Memory2' */
  gbyk_v4b_B.isUTSExo_o = gbyk_v4b_DW.Memory2_31_PreviousInput;

  /* Memory: '<S4>/Memory2' */
  gbyk_v4b_B.isPMAC_n = gbyk_v4b_DW.Memory2_32_PreviousInput;

  /* Memory: '<S4>/Memory2' */
  gbyk_v4b_B.isECAT_b = gbyk_v4b_DW.Memory2_33_PreviousInput;

  /* Memory: '<S4>/Memory2' */
  gbyk_v4b_B.robotRevision_k = gbyk_v4b_DW.Memory2_34_PreviousInput;

  /* Memory: '<S4>/Memory2' */
  gbyk_v4b_B.HasSecondaryEnc_d = gbyk_v4b_DW.Memory2_6_PreviousInput;

  /* Memory: '<S4>/Memory2' */
  gbyk_v4b_B.robottype_c = gbyk_v4b_DW.Memory2_7_PreviousInput;

  /* Memory: '<S4>/Memory2' */
  gbyk_v4b_B.robotversion_i = gbyk_v4b_DW.Memory2_8_PreviousInput;

  /* DataStoreRead: '<S4>/read status' */
  memcpy(&gbyk_v4b_B.readstatus[0], &gbyk_v4b_DW.ECATStatus[0], sizeof(real_T) <<
         3U);

  /* DataStoreRead: '<S4>/read Digital diag' */
  gbyk_v4b_B.readDigitaldiag[0] = gbyk_v4b_DW.ECATDigDiagnostic[0];
  gbyk_v4b_B.readDigitaldiag[1] = gbyk_v4b_DW.ECATDigDiagnostic[1];
  gbyk_v4b_B.readDigitaldiag[2] = gbyk_v4b_DW.ECATDigDiagnostic[2];
  gbyk_v4b_B.readDigitaldiag[3] = gbyk_v4b_DW.ECATDigDiagnostic[3];

  /* MATLAB Function: '<S259>/MATLAB Function' */
  gbyk_v4b_MATLABFunction(gbyk_v4b_B.ArmOrientation_b,
    gbyk_v4b_B.HasSecondaryEnc_n, gbyk_v4b_B.sf_decoderobot.isEP,
    &gbyk_v4b_B.sf_MATLABFunction_o);

  /* MATLAB Function: '<S259>/MATLAB Function1' */
  gbyk_v4b_MATLABFunction(gbyk_v4b_B.ArmOrientation_l,
    gbyk_v4b_B.HasSecondaryEnc_f, gbyk_v4b_B.sf_decoderobot_p.isEP,
    &gbyk_v4b_B.sf_MATLABFunction1);

  /* Constant: '<S39>/arm_count' */
  gbyk_v4b_B.robot_count = gbyk_v4b_P.arm_count_Value;

  /* Constant: '<S39>/fp1_present' */
  gbyk_v4b_B.has_force_plate_1 = gbyk_v4b_P.fp1_present_Value;

  /* Constant: '<S39>/fp2_present' */
  gbyk_v4b_B.has_force_plate_2 = gbyk_v4b_P.fp2_present_Value;

  /* Constant: '<S39>/gaze_tracker_present' */
  gbyk_v4b_B.has_gaze_tracker = gbyk_v4b_P.gaze_tracker_present_Value;

  /* Constant: '<S39>/robot_lift_present' */
  gbyk_v4b_B.has_robot_lift = gbyk_v4b_P.robot_lift_present_Value;

  /* MATLAB Function: '<S296>/MATLAB Function' incorporates:
   *  Constant: '<S15>/Constant'
   */
  hold_steps = gbyk_v4b_P.Process_Video_CMD_video_delay;

  /* MATLAB Function 'Process_Video_CMD/Add_requested_Delay/MATLAB Function': '<S299>:1' */
  /* '<S299>:1:4' */
  reps2 = gbyk_v4b_B.handFF_Dex * 1000.0;
  if (gbyk_v4b_P.Process_Video_CMD_video_delay < reps2) {
    /* '<S299>:1:6' */
    /* '<S299>:1:7' */
    hold_steps = reps2;
  }

  /* '<S299>:1:10' */
  gbyk_v4b_B.delay = hold_steps - reps2;
  if (gbyk_v4b_B.delay < 0.0) {
    /* '<S299>:1:12' */
    /* '<S299>:1:13' */
    gbyk_v4b_B.delay = 0.0;
  } else {
    if (gbyk_v4b_B.delay > 50.0) {
      /* '<S299>:1:14' */
      /* '<S299>:1:15' */
      gbyk_v4b_B.delay = 50.0;
    }
  }

  /* End of MATLAB Function: '<S296>/MATLAB Function' */

  /* RateTransition: '<S296>/Rate Transition1' */
  if (gbyk_v4b_M->Timing.RateInteraction.TID1_4) {
    gbyk_v4b_B.RateTransition1_l = gbyk_v4b_B.delay;
  }

  /* End of RateTransition: '<S296>/Rate Transition1' */
  /* ok to acquire for <S16>/S-Function */
  gbyk_v4b_DW.SFunction_IWORK.AcquireOK = 1;

  /* ok to acquire for <S17>/S-Function */
  gbyk_v4b_DW.SFunction_IWORK_n.AcquireOK = 1;

  /* ok to acquire for <S18>/S-Function */
  gbyk_v4b_DW.SFunction_IWORK_i.AcquireOK = 1;

  /* ok to acquire for <S19>/S-Function */
  gbyk_v4b_DW.SFunction_IWORK_j.AcquireOK = 1;

  /* ok to acquire for <S20>/S-Function */
  gbyk_v4b_DW.SFunction_IWORK_c.AcquireOK = 1;

  /* SignalConversion: '<Root>/ConcatBufferAtVector Concatenate2In1' */
  gbyk_v4b_B.VectorConcatenate2[0] = gbyk_v4b_B.Switch[0];
  gbyk_v4b_B.VectorConcatenate2[1] = gbyk_v4b_B.Switch[1];

  /* SignalConversion: '<Root>/ConcatBufferAtVector Concatenate2In2' */
  gbyk_v4b_B.VectorConcatenate2[2] = gbyk_v4b_B.Sqrt;
  for (i = 0; i < 60; i++) {
    /* Selector: '<Root>/Selector4' */
    gbyk_v4b_B.Selector4[i] = gbyk_v4b_B.trialIterations[i];

    /* Selector: '<Root>/Selector5' */
    gbyk_v4b_B.Selector5[i] = gbyk_v4b_B.trialIterations[60 + i];
  }

  /* Constant: '<S285>/B1;Target B1 row;float;B1 row in target table;;;none;;' */
  gbyk_v4b_B.B1TargetB1rowfloatB1rowintargettablenone =
    gbyk_v4b_P.B1TargetB1rowfloatB1rowintargettablenone_Value;

  /* Constant: '<S285>/B2;Target B2 row;float;B2 row in target table;;;none;;' */
  gbyk_v4b_B.B2TargetB2rowfloatB2rowintargettablenone =
    gbyk_v4b_P.B2TargetB2rowfloatB2rowintargettablenone_Value;

  /* Constant: '<S285>/CORR_TGT;Which target is correct;float;Which target is correct (1 or 2) ?;;;none;;' */
  gbyk_v4b_B.CORR_TGTWhichtargetiscorrectfloatWhichtargetiscorrect1or2none =
    gbyk_v4b_P.CORR_TGTWhichtargetiscorrectfloatWhichtargetiscorrect1or2none_V;

  /* Constant: '<S285>/DELAY_POST_TRIAL;Trial-End Delay;integer;Time to wait at the end of the trial;;;none;;' */
  gbyk_v4b_B.DELAY_POST_TRIALTrialEndDelayintegerTimetowaitattheendofthetria =
    gbyk_v4b_P.DELAY_POST_TRIALTrialEndDelayintegerTimetowaitattheendofthetria;

  /* Constant: '<S285>/DISPLAY_TRIAL_COL;Flag Display;integer;Display and pause;;;none;;' */
  gbyk_v4b_B.DISPLAY_TRIAL_COLFlagDisplayintegerDisplayandpausenone =
    gbyk_v4b_P.DISPLAY_TRIAL_COLFlagDisplayintegerDisplayandpausenone_Value;

  /* Constant: '<S285>/INCORR_TGT;Which target is incorrect;float;Which target is incorrect (1 or 2) ?;;;none;;' */
  gbyk_v4b_B.INCORR_TGTWhichtargetisincorrectfloatWhichtargetisincorrect1or2 =
    gbyk_v4b_P.INCORR_TGTWhichtargetisincorrectfloatWhichtargetisincorrect1or2;

  /* Constant: '<S285>/MAX_REACH_TIME_COL;Maximum Reach Time;integer;Maximum reach duration allowed;;;none;;' */
  gbyk_v4b_B.MAX_REACH_TIME_COLMaximumReachTimeintegerMaximumreachdurational =
    gbyk_v4b_P.MAX_REACH_TIME_COLMaximumReachTimeintegerMaximumreachdurational;

  /* Constant: '<S285>/RWD_TARGETC1_COL;Target1 Value;float;Reward offered on Target C1;;;none;;' */
  gbyk_v4b_B.RWD_TARGETC1_COLTarget1ValuefloatRewardofferedonTargetC1none =
    gbyk_v4b_P.RWD_TARGETC1_COLTarget1ValuefloatRewardofferedonTargetC1none_Va;

  /* Constant: '<S285>/RWD_TARGETC2_COL;Target2 Value;float;Reward offered on Target C2;;;none;;' */
  gbyk_v4b_B.RWD_TARGETC2_COLTarget2ValuefloatRewardofferedonTargetC2none =
    gbyk_v4b_P.RWD_TARGETC2_COLTarget2ValuefloatRewardofferedonTargetC2none_Va;

  /* Constant: '<S285>/START_TARGET_COL;Start target;target;First target to appear during a trial;;;none;;' */
  gbyk_v4b_B.START_TARGET_COLStarttargettargetFirsttargettoappearduringatria =
    gbyk_v4b_P.START_TARGET_COLStarttargettargetFirsttargettoappearduringatria;

  /* Constant: '<S285>/TGT_C_RWD_FRAC;Reward ratio between rowC:rowB;float;How much more will targets B be worth?;;;none;;' */
  gbyk_v4b_B.TGT_C_RWD_FRACRewardratiobetweenrowCrowBfloatHowmuchmorewilltar =
    gbyk_v4b_P.TGT_C_RWD_FRACRewardratiobetweenrowCrowBfloatHowmuchmorewilltar;

  /* Constant: '<S286>/INSTRUCT_PAUSE_BTN;Instruction-Resume;;Button to continue task after displaying instructions;25;22;none;;' */
  gbyk_v4b_B.INSTRUCT_PAUSE_BTNInstructionResumeButtontocontinuetaskafterdis =
    gbyk_v4b_P.INSTRUCT_PAUSE_BTNInstructionResumeButtontocontinuetaskafterdis;

  /* Constant: '<S287>/E_BOX_TRIGGER;Box Was Triggered;;Box triggrered so subject chose row C;;;none;;' */
  gbyk_v4b_B.E_BOX_TRIGGERBoxWasTriggeredBoxtriggreredsosubjectchoserowCnone =
    gbyk_v4b_P.E_BOX_TRIGGERBoxWasTriggeredBoxtriggreredsosubjectchoserowCnone;

  /* Constant: '<S287>/E_CHOSE_ROW_B;Chose Row B;;Subject chose row B ;;;none;;' */
  gbyk_v4b_B.E_CHOSE_ROW_BChoseRowBSubjectchoserowBnone =
    gbyk_v4b_P.E_CHOSE_ROW_BChoseRowBSubjectchoserowBnone_Value;

  /* Constant: '<S287>/E_HIT_TARGETB;Hit Target B;;Hit target B;;;none;;' */
  gbyk_v4b_B.E_HIT_TARGETBHitTargetBHittargetBnone =
    gbyk_v4b_P.E_HIT_TARGETBHitTargetBHittargetBnone_Value;

  /* Constant: '<S287>/E_HIT_TARGETC;Hit Target C;;Hit Target C;;;none;;' */
  gbyk_v4b_B.E_HIT_TARGETCHitTargetCHitTargetCnone =
    gbyk_v4b_P.E_HIT_TARGETCHitTargetCHitTargetCnone_Value;

  /* Constant: '<S287>/E_MISS_TARGETB;Miss Targret B;;Miss Targret B;;;none;;' */
  gbyk_v4b_B.E_MISS_TARGETBMissTargretBMissTargretBnone =
    gbyk_v4b_P.E_MISS_TARGETBMissTargretBMissTargretBnone_Value;

  /* Constant: '<S287>/E_MISS_TARGETC;Miss Target C;;Miss Target C;;;none;;' */
  gbyk_v4b_B.E_MISS_TARGETCMissTargetCMissTargetCnone =
    gbyk_v4b_P.E_MISS_TARGETCMissTargetCMissTargetCnone_Value;

  /* Constant: '<S287>/E_NEW_TRIAL;New Trial Start;;New Trial starts;;;none;;' */
  gbyk_v4b_B.E_NEW_TRIALNewTrialStartNewTrialstartsnone =
    gbyk_v4b_P.E_NEW_TRIALNewTrialStartNewTrialstartsnone_Value;

  /* Constant: '<S287>/E_NO_EVENT;n|a;;This event_code does not save an event in the data file, it just clears the event;;;none;;' */
  gbyk_v4b_B.E_NO_EVENTnaThisevent_codedoesnotsaveaneventinthedatafileitjust =
    gbyk_v4b_P.E_NO_EVENTnaThisevent_codedoesnotsaveaneventinthedatafileitjust;

  /* Constant: '<S287>/E_SHOW_INSTRUCT;Instruction state;;Showing instructions;;;none;;' */
  gbyk_v4b_B.E_SHOW_INSTRUCTInstructionstateShowinginstructionsnone =
    gbyk_v4b_P.E_SHOW_INSTRUCTInstructionstateShowinginstructionsnone_Value;

  /* Constant: '<S287>/E_SHOW_SCORE;Show Score;;Showing score;;;none;;' */
  gbyk_v4b_B.E_SHOW_SCOREShowScoreShowingscorenone =
    gbyk_v4b_P.E_SHOW_SCOREShowScoreShowingscorenone_Value;

  /* Constant: '<S287>/E_STAY_START;At Start;;Subject reached start target;;;none;;' */
  gbyk_v4b_B.E_STAY_STARTAtStartSubjectreachedstarttargetnone =
    gbyk_v4b_P.E_STAY_STARTAtStartSubjectreachedstarttargetnone_Value;

  /* Constant: '<S287>/E_TARGETS_ON;Targets On;;Potential Reach targets on;;;none;;' */
  gbyk_v4b_B.E_TARGETS_ONTargetsOnPotentialReachtargetsonnone =
    gbyk_v4b_P.E_TARGETS_ONTargetsOnPotentialReachtargetsonnone_Value;

  /* Constant: '<S287>/E_TOO_SLOW;Too Slow;;Movement is too slow;;;error;;' */
  gbyk_v4b_B.E_TOO_SLOWTooSlowMovementistooslowerror =
    gbyk_v4b_P.E_TOO_SLOWTooSlowMovementistooslowerror_Value;

  /* Constant: '<S288>/BOX_HEIGHT;Height of Box;float;Height of Box;;;none;;' */
  gbyk_v4b_B.BOX_HEIGHTHeightofBoxfloatHeightofBoxnone =
    gbyk_v4b_P.BOX_HEIGHTHeightofBoxfloatHeightofBoxnone_Value;

  /* Constant: '<S288>/HIT_COLOR;Reached color;colour;Color when the target is touched;;;none;;' */
  gbyk_v4b_B.HIT_COLORReachedcolorcolourColorwhenthetargetistouchednone =
    gbyk_v4b_P.HIT_COLORReachedcolorcolourColorwhenthetargetistouchednone_Valu;

  /* Constant: '<S288>/INIT_COLOR;Initial color;colour;Initial target color;;;none;;' */
  gbyk_v4b_B.INIT_COLORInitialcolorcolourInitialtargetcolornone =
    gbyk_v4b_P.INIT_COLORInitialcolorcolourInitialtargetcolornone_Value;

  /* Constant: '<S288>/LABEL;Label Text;label;Initial text for the label;;;none;;' */
  gbyk_v4b_B.LABELLabelTextlabelInitialtextforthelabelnone =
    gbyk_v4b_P.LABELLabelTextlabelInitialtextforthelabelnone_Value;

  /* Constant: '<S288>/LABELONLY_X;LabelOnly X;float;X position (cm) of the target relative to local (0,0) when only the label appears;;;none;;' */
  gbyk_v4b_B.LABELONLY_XLabelOnlyXfloatXpositioncmofthetargetrelativetolocal =
    gbyk_v4b_P.LABELONLY_XLabelOnlyXfloatXpositioncmofthetargetrelativetolocal;

  /* Constant: '<S288>/LABELONLY_Y;LabelOnly  Y;float;Y position (cm) of the target relative to local (0,0) when only the label appears;;;none;;' */
  gbyk_v4b_B.LABELONLY_YLabelOnlyYfloatYpositioncmofthetargetrelativetolocal =
    gbyk_v4b_P.LABELONLY_YLabelOnlyYfloatYpositioncmofthetargetrelativetolocal;

  /* Constant: '<S288>/LABEL_HEIGHT;Label Height;float;Label Height (cm);;;none;;' */
  gbyk_v4b_B.LABEL_HEIGHTLabelHeightfloatLabelHeightcmnone =
    gbyk_v4b_P.LABEL_HEIGHTLabelHeightfloatLabelHeightcmnone_Value;

  /* Constant: '<S288>/LOGICAL_RADIUS;Logical radius;float;Radius of the target used for 'hand-in-target' logic (cm);;;none;;' */
  gbyk_v4b_B.LOGICAL_RADIUSLogicalradiusfloatRadiusofthetargetusedforhandint =
    gbyk_v4b_P.LOGICAL_RADIUSLogicalradiusfloatRadiusofthetargetusedforhandint;

  /* Constant: '<S288>/ROTATION;Rotation of a target;float;Rotation of target;;;none;;' */
  gbyk_v4b_B.ROTATIONRotationofatargetfloatRotationoftargetnone =
    gbyk_v4b_P.ROTATIONRotationofatargetfloatRotationoftargetnone_Value;

  /* Constant: '<S288>/STROKE_WIDTH;Stroke Width;float;Stroke width;;;none;;' */
  gbyk_v4b_B.STROKE_WIDTHStrokeWidthfloatStrokewidthnone =
    gbyk_v4b_P.STROKE_WIDTHStrokeWidthfloatStrokewidthnone_Value;

  /* Constant: '<S288>/TEXT_COLOR;Text Color;colour;Text Color;;;none;;' */
  gbyk_v4b_B.TEXT_COLORTextColorcolourTextColornone =
    gbyk_v4b_P.TEXT_COLORTextColorcolourTextColornone_Value;

  /* Constant: '<S288>/col_x;X;float;X Position (cm) of the target relative to  local (0,0);;;none;;' */
  gbyk_v4b_B.col_xXfloatXPositioncmofthetargetrelativetolocal00none =
    gbyk_v4b_P.col_xXfloatXPositioncmofthetargetrelativetolocal00none_Value;

  /* Constant: '<S288>/col_y;Y;float;Y Position (cm) of the target relative to  local (0,0);;;none;;' */
  gbyk_v4b_B.col_yYfloatYPositioncmofthetargetrelativetolocal00none =
    gbyk_v4b_P.col_yYfloatYPositioncmofthetargetrelativetolocal00none_Value;

  /* Constant: '<S288>/VISUAL_RADIUS;Visual radius;float;Visual radius of the target (cm) or size of the sides of the square targets;;;none;;' */
  gbyk_v4b_B.VISUAL_RADIUSVisualradiusfloatVisualradiusofthetargetcmorsizeof =
    gbyk_v4b_P.VISUAL_RADIUSVisualradiusfloatVisualradiusofthetargetcmorsizeof;

  /* Constant: '<S289>/INSTRUCTIONS=' */
  gbyk_v4b_B.INSTRUCTIONS = gbyk_v4b_P.INSTRUCTIONS_Value;

  /* Constant: '<S289>/LOAD_FOR=EITHER' */
  gbyk_v4b_B.LOAD_FOREITHER = gbyk_v4b_P.LOAD_FOREITHER_Value;

  /* Constant: '<S290>/K_DELAY_FIXED;Delay_Min;integer;Minimum hold delay time at start target (fixed);;;none;;' */
  gbyk_v4b_B.K_DELAY_FIXEDDelay_MinintegerMinimumholddelaytimeatstarttargetf =
    gbyk_v4b_P.K_DELAY_FIXEDDelay_MinintegerMinimumholddelaytimeatstarttargetf;

  /* Constant: '<S290>/K_DELAY_RAND;Delay_Rand;integer;Maximum additional delay time at start target (random);;;none;;' */
  gbyk_v4b_B.K_DELAY_RANDDelay_RandintegerMaximumadditionaldelaytimeatstartt =
    gbyk_v4b_P.K_DELAY_RANDDelay_RandintegerMaximumadditionaldelaytimeatstartt;

  /* Constant: '<S290>/K_PRE_REWARD_DELAY;Delay_PreRewardCue;integer;Time to cue the reward information prior to the trial onset;;;none;;' */
  gbyk_v4b_B.K_PRE_REWARD_DELAYDelay_PreRewardCueintegerTimetocuetherewardin =
    gbyk_v4b_P.K_PRE_REWARD_DELAYDelay_PreRewardCueintegerTimetocuetherewardin;

  /* Constant: '<S290>/K_REWARD_VAL;Reward_Value;integer;One unit of reward;;;none;;' */
  gbyk_v4b_B.K_REWARD_VALReward_ValueintegerOneunitofrewardnone =
    gbyk_v4b_P.K_REWARD_VALReward_ValueintegerOneunitofrewardnone_Value;

  /* Constant: '<S290>/K_SCORETEXT_ROW;Feedback_Text_TgtTable_Row;integer;Target number to be used to set the feedback text;;;none;;' */
  gbyk_v4b_B.K_SCORETEXT_ROWFeedback_Text_TgtTable_RowintegerTargetnumbertob =
    gbyk_v4b_P.K_SCORETEXT_ROWFeedback_Text_TgtTable_RowintegerTargetnumbertob;

  /* Constant: '<S290>/K_THRESH_VELMAX;Vel_Min_Thresh;float;Minimum velocity that must be exceeded for trial to be considered successful;;;none;;' */
  gbyk_v4b_B.K_THRESH_VELMAXVel_Min_ThreshfloatMinimumvelocitythatmustbeexce =
    gbyk_v4b_P.K_THRESH_VELMAXVel_Min_ThreshfloatMinimumvelocitythatmustbeexce;

  /* Constant: '<S290>/K_TRIGGER_POS;Trigger_Pos;float;Position Threshold for triggering target reveal;;;none;;' */
  gbyk_v4b_B.K_TRIGGER_POSTrigger_PosfloatPositionThresholdfortriggeringtarg =
    gbyk_v4b_P.K_TRIGGER_POSTrigger_PosfloatPositionThresholdfortriggeringtarg;

  /* Constant: '<S290>/K_TRIGGER_VEL;Trigger_Vel;float;Velocity Threshold for triggering target reveal;;;none;;' */
  gbyk_v4b_B.K_TRIGGER_VELTrigger_VelfloatVelocityThresholdfortriggeringtarg =
    gbyk_v4b_P.K_TRIGGER_VELTrigger_VelfloatVelocityThresholdfortriggeringtarg;
}

/* Model update function for TID0 */
static void gbyk_v4b_update0(void)     /* Sample time: [0.0s, 0.0s] */
{
  /* Update for Atomic SubSystem: '<S7>/Task Execution Control Subsystem' */
  gbyk_v4b_TaskExecutionControlSubsystem_Update();

  /* End of Update for SubSystem: '<S7>/Task Execution Control Subsystem' */

  /* Update for Memory: '<S4>/Memory' */
  gbyk_v4b_DW.Memory_PreviousInput[0] = gbyk_v4b_B.AddTorques[0];
  gbyk_v4b_DW.Memory_PreviousInput[1] = gbyk_v4b_B.AddTorques[1];
  gbyk_v4b_DW.Memory_PreviousInput[2] = gbyk_v4b_B.AddTorques[2];
  gbyk_v4b_DW.Memory_PreviousInput[3] = gbyk_v4b_B.AddTorques[3];

  /* Update for Memory: '<S15>/Memory' incorporates:
   *  Constant: '<S15>/Constant'
   */
  gbyk_v4b_DW.Memory_PreviousInput_c = gbyk_v4b_P.Process_Video_CMD_video_delay;

  /* Update for Atomic SubSystem: '<S4>/Poll KINARM' */
  gbyk_v4b_PollKINARM_Update();

  /* End of Update for SubSystem: '<S4>/Poll KINARM' */

  /* Update for Atomic SubSystem: '<S4>/Network Transfer Subsystem' */
  gbyk_v4b_NetworkTransferSubsystem_UpdateTID0();

  /* End of Update for SubSystem: '<S4>/Network Transfer Subsystem' */

  /* Update for Memory: '<S4>/Memory1' */
  gbyk_v4b_DW.Memory1_PreviousInput = gbyk_v4b_B.force_scale;

  /* Update for Memory: '<S4>/Memory2' */
  gbyk_v4b_DW.Memory2_1_PreviousInput = gbyk_v4b_B.ArmOrientation_b;

  /* Update for Memory: '<S4>/Memory2' */
  gbyk_v4b_DW.Memory2_2_PreviousInput = gbyk_v4b_B.M1orientation_h;

  /* Update for Memory: '<S4>/Memory2' */
  gbyk_v4b_DW.Memory2_3_PreviousInput = gbyk_v4b_B.M2Orientation_l;

  /* Update for Memory: '<S4>/Memory2' */
  gbyk_v4b_DW.Memory2_4_PreviousInput = gbyk_v4b_B.M1GearRatio_b;

  /* Update for Memory: '<S4>/Memory2' */
  gbyk_v4b_DW.Memory2_5_PreviousInput = gbyk_v4b_B.M2GearRatio_p;

  /* Update for Memory: '<S4>/Memory2' */
  gbyk_v4b_DW.Memory2_9_PreviousInput = gbyk_v4b_B.torqueconstant_g;

  /* Update for Memory: '<S4>/Memory2' */
  gbyk_v4b_DW.Memory2_18_PreviousInput = gbyk_v4b_B.ArmOrientation_l;

  /* Update for Memory: '<S4>/Memory2' */
  gbyk_v4b_DW.Memory2_19_PreviousInput = gbyk_v4b_B.M1orientation_n;

  /* Update for Memory: '<S4>/Memory2' */
  gbyk_v4b_DW.Memory2_20_PreviousInput = gbyk_v4b_B.M2Orientation_cw;

  /* Update for Memory: '<S4>/Memory2' */
  gbyk_v4b_DW.Memory2_21_PreviousInput = gbyk_v4b_B.M1GearRatio_k;

  /* Update for Memory: '<S4>/Memory2' */
  gbyk_v4b_DW.Memory2_22_PreviousInput = gbyk_v4b_B.M2GearRatio_l;

  /* Update for Memory: '<S4>/Memory2' */
  gbyk_v4b_DW.Memory2_26_PreviousInput = gbyk_v4b_B.torqueconstant_i;

  /* Update for Memory: '<S4>/Memory2' */
  gbyk_v4b_DW.Memory2_10_PreviousInput = gbyk_v4b_B.sf_decoderobot.isEP;

  /* Update for Memory: '<S4>/Memory2' */
  gbyk_v4b_DW.Memory2_11_PreviousInput = gbyk_v4b_B.sf_decoderobot.isHumanEXO;

  /* Update for Memory: '<S4>/Memory2' */
  gbyk_v4b_DW.Memory2_12_PreviousInput = gbyk_v4b_B.sf_decoderobot.isNHPEXO;

  /* Update for Memory: '<S4>/Memory2' */
  gbyk_v4b_DW.Memory2_13_PreviousInput = gbyk_v4b_B.sf_decoderobot.isClassicExo;

  /* Update for Memory: '<S4>/Memory2' */
  gbyk_v4b_DW.Memory2_14_PreviousInput = gbyk_v4b_B.sf_decoderobot.isUTSEXO;

  /* Update for Memory: '<S4>/Memory2' */
  gbyk_v4b_DW.Memory2_15_PreviousInput = gbyk_v4b_B.sf_decoderobot.isPMAC;

  /* Update for Memory: '<S4>/Memory2' */
  gbyk_v4b_DW.Memory2_16_PreviousInput = gbyk_v4b_B.sf_decoderobot.isECAT;

  /* Update for Memory: '<S4>/Memory2' */
  gbyk_v4b_DW.Memory2_17_PreviousInput = gbyk_v4b_B.Statusread1[0];

  /* Update for Memory: '<S4>/Memory2' */
  gbyk_v4b_DW.Memory2_23_PreviousInput = gbyk_v4b_B.HasSecondaryEnc_f;

  /* Update for Memory: '<S4>/Memory2' */
  gbyk_v4b_DW.Memory2_24_PreviousInput = gbyk_v4b_B.robottype_cs;

  /* Update for Memory: '<S4>/Memory2' */
  gbyk_v4b_DW.Memory2_25_PreviousInput = gbyk_v4b_B.robotversion_f;

  /* Update for Memory: '<S4>/Memory2' */
  gbyk_v4b_DW.Memory2_27_PreviousInput = gbyk_v4b_B.sf_decoderobot_p.isEP;

  /* Update for Memory: '<S4>/Memory2' */
  gbyk_v4b_DW.Memory2_28_PreviousInput = gbyk_v4b_B.sf_decoderobot_p.isHumanEXO;

  /* Update for Memory: '<S4>/Memory2' */
  gbyk_v4b_DW.Memory2_29_PreviousInput = gbyk_v4b_B.sf_decoderobot_p.isNHPEXO;

  /* Update for Memory: '<S4>/Memory2' */
  gbyk_v4b_DW.Memory2_30_PreviousInput =
    gbyk_v4b_B.sf_decoderobot_p.isClassicExo;

  /* Update for Memory: '<S4>/Memory2' */
  gbyk_v4b_DW.Memory2_31_PreviousInput = gbyk_v4b_B.sf_decoderobot_p.isUTSEXO;

  /* Update for Memory: '<S4>/Memory2' */
  gbyk_v4b_DW.Memory2_32_PreviousInput = gbyk_v4b_B.sf_decoderobot_p.isPMAC;

  /* Update for Memory: '<S4>/Memory2' */
  gbyk_v4b_DW.Memory2_33_PreviousInput = gbyk_v4b_B.sf_decoderobot_p.isECAT;

  /* Update for Memory: '<S4>/Memory2' */
  gbyk_v4b_DW.Memory2_34_PreviousInput = gbyk_v4b_B.Statusread1_m[1];

  /* Update for Memory: '<S4>/Memory2' */
  gbyk_v4b_DW.Memory2_6_PreviousInput = gbyk_v4b_B.HasSecondaryEnc_n;

  /* Update for Memory: '<S4>/Memory2' */
  gbyk_v4b_DW.Memory2_7_PreviousInput = gbyk_v4b_B.robottype_e;

  /* Update for Memory: '<S4>/Memory2' */
  gbyk_v4b_DW.Memory2_8_PreviousInput = gbyk_v4b_B.robotversion_g;

  /* Update absolute time */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++gbyk_v4b_M->Timing.clockTick0)) {
    ++gbyk_v4b_M->Timing.clockTickH0;
  }

  gbyk_v4b_M->Timing.t[0] = gbyk_v4b_M->Timing.clockTick0 *
    gbyk_v4b_M->Timing.stepSize0 + gbyk_v4b_M->Timing.clockTickH0 *
    gbyk_v4b_M->Timing.stepSize0 * 4294967296.0;

  /* Update absolute time */
  /* The "clockTick1" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick1"
   * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick1 and the high bits
   * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++gbyk_v4b_M->Timing.clockTick1)) {
    ++gbyk_v4b_M->Timing.clockTickH1;
  }

  gbyk_v4b_M->Timing.t[1] = gbyk_v4b_M->Timing.clockTick1 *
    gbyk_v4b_M->Timing.stepSize1 + gbyk_v4b_M->Timing.clockTickH1 *
    gbyk_v4b_M->Timing.stepSize1 * 4294967296.0;
}

/* Model output function for TID2 */
static void gbyk_v4b_output2(void)     /* Sample time: [0.0005s, 0.0s] */
{
  /* Reset subsysRan breadcrumbs */
  srClearBC(gbyk_v4b_DW.sendpoll1_SubsysRanBC);

  /* Reset subsysRan breadcrumbs */
  srClearBC(gbyk_v4b_DW.sendpoll2_SubsysRanBC);

  /* Outputs for Atomic SubSystem: '<S4>/Poll Force Plates' */
  gbyk_v4b_PollForcePlatesTID2();

  /* End of Outputs for SubSystem: '<S4>/Poll Force Plates' */

  /* Outputs for Atomic SubSystem: '<S4>/Network Transfer Subsystem' */
  gbyk_v4b_NetworkTransferSubsystemTID2();

  /* End of Outputs for SubSystem: '<S4>/Network Transfer Subsystem' */
}

/* Model update function for TID2 */
static void gbyk_v4b_update2(void)     /* Sample time: [0.0005s, 0.0s] */
{
  /* Update for Atomic SubSystem: '<S4>/Network Transfer Subsystem' */
  gbyk_v4b_NetworkTransferSubsystem_UpdateTID2();

  /* End of Update for SubSystem: '<S4>/Network Transfer Subsystem' */

  /* Update absolute time */
  /* The "clockTick2" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick2"
   * and "Timing.stepSize2". Size of "clockTick2" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick2 and the high bits
   * Timing.clockTickH2. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++gbyk_v4b_M->Timing.clockTick2)) {
    ++gbyk_v4b_M->Timing.clockTickH2;
  }

  gbyk_v4b_M->Timing.t[2] = gbyk_v4b_M->Timing.clockTick2 *
    gbyk_v4b_M->Timing.stepSize2 + gbyk_v4b_M->Timing.clockTickH2 *
    gbyk_v4b_M->Timing.stepSize2 * 4294967296.0;
}

/* Model output function for TID3 */
static void gbyk_v4b_output3(void)     /* Sample time: [0.001s, 0.0s] */
{
  /* UnitDelay: '<S44>/Output' */
  gbyk_v4b_B.Output = gbyk_v4b_DW.Output_DSTATE;

  /* DataTypeConversion: '<S30>/Timestamp' */
  gbyk_v4b_B.Timestamp = gbyk_v4b_B.Output;

  /* DataTypeConversion: '<S30>/conv' */
  gbyk_v4b_B.conv = gbyk_v4b_ConstB.Width;

  /* Outputs for Atomic SubSystem: '<S4>/Receive_Gaze' */
  gbyk_v4b_Receive_GazeTID3();

  /* End of Outputs for SubSystem: '<S4>/Receive_Gaze' */

  /* RateTransition: '<S4>/Rate Transition1' incorporates:
   *  Constant: '<S30>/packet_version'
   */
  gbyk_v4b_B.RateTransition1_i[0] = gbyk_v4b_B.Timestamp;
  gbyk_v4b_B.RateTransition1_i[1] = gbyk_v4b_P.packet_version_Value;
  gbyk_v4b_B.RateTransition1_i[2] = gbyk_v4b_B.conv;
  gbyk_v4b_B.RateTransition1_i[3] = gbyk_v4b_B.RateTransition10;
  gbyk_v4b_B.RateTransition1_i[4] = gbyk_v4b_B.RateTransition9[0];
  gbyk_v4b_B.RateTransition1_i[5] = gbyk_v4b_B.RateTransition9[1];
  gbyk_v4b_B.RateTransition1_i[6] = gbyk_v4b_B.RateTransition8;
  gbyk_v4b_B.RateTransition1_i[7] = gbyk_v4b_B.RateTransition7;
  gbyk_v4b_B.RateTransition1_i[8] = gbyk_v4b_B.RateTransition6;
  gbyk_v4b_B.RateTransition1_i[9] = gbyk_v4b_B.RateTransition5;
  gbyk_v4b_B.RateTransition1_i[10] = gbyk_v4b_B.RateTransition4;
  gbyk_v4b_B.RateTransition1_i[11] = gbyk_v4b_B.RateTransition12;
  gbyk_v4b_B.RateTransition1_i[12] = gbyk_v4b_B.RateTransition3;
  gbyk_v4b_B.RateTransition1_i[13] = gbyk_v4b_B.RateTransition2_e;
  gbyk_v4b_B.RateTransition1_i[14] = gbyk_v4b_B.RateTransition1;
  gbyk_v4b_B.RateTransition1_i[15] = gbyk_v4b_B.RateTransition;
  gbyk_v4b_B.RateTransition1_i[16] = gbyk_v4b_B.RateTransition11;

  /* DataTypeConversion: '<S29>/Kinarm Data Width' */
  gbyk_v4b_B.KinarmDataWidth = gbyk_v4b_ConstB.Width_d;

  /* DataTypeConversion: '<S29>/touint1' */
  gbyk_v4b_B.touint1 = gbyk_v4b_B.RateTransition1_n;

  /* DataTypeConversion: '<S29>/Arm Kinematics' */
  memcpy(&gbyk_v4b_B.ArmKinematics[0], &gbyk_v4b_B.RateTransition_k[0], 40U *
         sizeof(real_T));
  memcpy(&gbyk_v4b_B.ArmKinematics[40], &gbyk_v4b_B.RateTransition2_er[0], 13U *
         sizeof(real_T));
  memcpy(&gbyk_v4b_B.ArmKinematics[53], &gbyk_v4b_B.RateTransition3_n[0], 14U *
         sizeof(real_T));
  gbyk_v4b_B.ArmKinematics[67] = gbyk_v4b_B.touint1;

  /* Sum: '<S26>/Subtract' incorporates:
   *  Constant: '<S26>/Not Logging Analog Inputs'
   */
  gbyk_v4b_B.Subtract = gbyk_v4b_ConstB.Width_a -
    gbyk_v4b_P.NotLoggingAnalogInputs_Value;

  /* DataTypeConversion: '<S26>/Analog Data Width' */
  gbyk_v4b_B.AnalogDataWidth = gbyk_v4b_B.Subtract;

  /* RateTransition: '<S26>/Rate Transition' */
  gbyk_v4b_B.RateTransition_c = gbyk_v4b_B.AnalogDataWidth;

  /* Outputs for Atomic SubSystem: '<S4>/Network Transfer Subsystem' */
  gbyk_v4b_NetworkTransferSubsystemTID3();

  /* End of Outputs for SubSystem: '<S4>/Network Transfer Subsystem' */

  /* Sum: '<S28>/Subtract' incorporates:
   *  Constant: '<S28>/Not Logging Event Codes'
   */
  gbyk_v4b_B.Subtract_g = gbyk_v4b_ConstB.Width_c -
    gbyk_v4b_P.NotLoggingEventCodes_Value;

  /* DataTypeConversion: '<S28>/Number of Event Codes' */
  gbyk_v4b_B.NumberofEventCodes = gbyk_v4b_B.Subtract_g;

  /* Sum: '<S46>/FixPt Sum1' incorporates:
   *  Constant: '<S46>/FixPt Constant'
   */
  gbyk_v4b_B.FixPtSum1 = gbyk_v4b_B.Output + gbyk_v4b_P.FixPtConstant_Value_g;

  /* Switch: '<S47>/FixPt Switch' incorporates:
   *  Constant: '<S47>/Constant'
   */
  if (gbyk_v4b_B.FixPtSum1 > gbyk_v4b_P.WrapToZero_Threshold_c) {
    gbyk_v4b_B.FixPtSwitch = gbyk_v4b_P.Constant_Value_cq;
  } else {
    gbyk_v4b_B.FixPtSwitch = gbyk_v4b_B.FixPtSum1;
  }

  /* End of Switch: '<S47>/FixPt Switch' */
}

/* Model update function for TID3 */
static void gbyk_v4b_update3(void)     /* Sample time: [0.001s, 0.0s] */
{
  /* Update for UnitDelay: '<S44>/Output' */
  gbyk_v4b_DW.Output_DSTATE = gbyk_v4b_B.FixPtSwitch;

  /* Update for Atomic SubSystem: '<S4>/Receive_Gaze' */
  gbyk_v4b_Receive_Gaze_UpdateTID3();

  /* End of Update for SubSystem: '<S4>/Receive_Gaze' */

  /* Update for RateTransition: '<S28>/TmpRTBAtNumber of Event CodesOutport1' */
  gbyk_v4b_DW.TmpRTBAtNumberofEventCodesOutport1_Buffer0 =
    gbyk_v4b_B.NumberofEventCodes;

  /* Update for Atomic SubSystem: '<S4>/Network Transfer Subsystem' */
  gbyk_v4b_NetworkTransferSubsystem_UpdateTID3();

  /* End of Update for SubSystem: '<S4>/Network Transfer Subsystem' */

  /* Update absolute time */
  /* The "clockTick3" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick3"
   * and "Timing.stepSize3". Size of "clockTick3" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick3 and the high bits
   * Timing.clockTickH3. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++gbyk_v4b_M->Timing.clockTick3)) {
    ++gbyk_v4b_M->Timing.clockTickH3;
  }

  gbyk_v4b_M->Timing.t[3] = gbyk_v4b_M->Timing.clockTick3 *
    gbyk_v4b_M->Timing.stepSize3 + gbyk_v4b_M->Timing.clockTickH3 *
    gbyk_v4b_M->Timing.stepSize3 * 4294967296.0;
}

/* Model output function for TID4 */
static void gbyk_v4b_output4(void)     /* Sample time: [0.002s, 0.0s] */
{
  int32_T yElIdx;
  int32_T uElOffset1;
  int32_T ntIdx1;
  int32_T uElOffset0;
  int32_T ntIdx0;

  /* PermuteDimensions: '<S15>/invert dim' */
  yElIdx = 0;
  uElOffset1 = 0;
  for (ntIdx1 = 0; ntIdx1 < 10; ntIdx1++) {
    uElOffset0 = uElOffset1;
    for (ntIdx0 = 0; ntIdx0 < 70; ntIdx0++) {
      gbyk_v4b_B.MatrixConcatenate[yElIdx] =
        gbyk_v4b_B.RateTransition2[uElOffset0];
      yElIdx++;
      uElOffset0 += 10;
    }

    uElOffset1++;
  }

  /* End of PermuteDimensions: '<S15>/invert dim' */

  /* Constant: '<S15>/GUI_VCODE' */
  memcpy(&gbyk_v4b_B.MatrixConcatenate[700], &gbyk_v4b_P.GUI_VCODE_Value[0],
         630U * sizeof(real_T));

  /* Outputs for Atomic SubSystem: '<S15>/PVC_core' */
  gbyk_v4b_PVC_coreTID4();

  /* End of Outputs for SubSystem: '<S15>/PVC_core' */

  /* RateTransition: '<S296>/Rate Transition2' incorporates:
   *  Constant: '<S296>/500 hz'
   */
  gbyk_v4b_B.RateTransition2_d = gbyk_v4b_P.u0hz_Value;

  /* S-Function (delay_vcodes): '<S296>/S-Function Builder' */
  delay_vcodes_Outputs_wrapper(&gbyk_v4b_B.vis_cmd[0], &gbyk_v4b_B.vis_cmd_len,
    &gbyk_v4b_B.RateTransition1_l, &gbyk_v4b_B.RateTransition2_d,
    &gbyk_v4b_B.SFunctionBuilder_o1[0], &gbyk_v4b_B.SFunctionBuilder_o2,
    &gbyk_v4b_B.SFunctionBuilder_o3[0] );

  /* Level2 S-Function Block: '<S15>/Send' (xpcudpbytesend) */
  {
    SimStruct *rts = gbyk_v4b_M->childSfunctions[43];
    sfcnOutputs(rts, 4);
  }
}

/* Model update function for TID4 */
static void gbyk_v4b_update4(void)     /* Sample time: [0.002s, 0.0s] */
{
  /* Update for Atomic SubSystem: '<S15>/PVC_core' */
  gbyk_v4b_PVC_core_UpdateTID4();

  /* End of Update for SubSystem: '<S15>/PVC_core' */

  /* Update for RateTransition: '<S27>/Rate Transition2' */
  gbyk_v4b_DW.RateTransition2_Buffer0 = gbyk_v4b_B.vcode_err_id;

  /* Update absolute time */
  /* The "clockTick4" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick4"
   * and "Timing.stepSize4". Size of "clockTick4" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick4 and the high bits
   * Timing.clockTickH4. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++gbyk_v4b_M->Timing.clockTick4)) {
    ++gbyk_v4b_M->Timing.clockTickH4;
  }

  gbyk_v4b_M->Timing.t[4] = gbyk_v4b_M->Timing.clockTick4 *
    gbyk_v4b_M->Timing.stepSize4 + gbyk_v4b_M->Timing.clockTickH4 *
    gbyk_v4b_M->Timing.stepSize4 * 4294967296.0;
}

/* Model output function for TID5 */
static void gbyk_v4b_output5(void)     /* Sample time: [0.1s, 0.0s] */
{
  /* Outputs for Atomic SubSystem: '<S4>/Keep alive' */
  gbyk_v4b_Keepalive();

  /* End of Outputs for SubSystem: '<S4>/Keep alive' */
}

/* Model update function for TID5 */
static void gbyk_v4b_update5(void)     /* Sample time: [0.1s, 0.0s] */
{
  /* Update absolute time */
  /* The "clockTick5" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick5"
   * and "Timing.stepSize5". Size of "clockTick5" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick5 and the high bits
   * Timing.clockTickH5. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++gbyk_v4b_M->Timing.clockTick5)) {
    ++gbyk_v4b_M->Timing.clockTickH5;
  }

  gbyk_v4b_M->Timing.t[5] = gbyk_v4b_M->Timing.clockTick5 *
    gbyk_v4b_M->Timing.stepSize5 + gbyk_v4b_M->Timing.clockTickH5 *
    gbyk_v4b_M->Timing.stepSize5 * 4294967296.0;
}

/* Model output wrapper function for compatibility with a static main program */
static void gbyk_v4b_output(int_T tid)
{
  switch (tid) {
   case 0 :
    gbyk_v4b_output0();
    break;

   case 2 :
    gbyk_v4b_output2();
    break;

   case 3 :
    gbyk_v4b_output3();
    break;

   case 4 :
    gbyk_v4b_output4();
    break;

   case 5 :
    gbyk_v4b_output5();
    break;

   default :
    break;
  }
}

/* Model update wrapper function for compatibility with a static main program */
static void gbyk_v4b_update(int_T tid)
{
  switch (tid) {
   case 0 :
    gbyk_v4b_update0();
    break;

   case 2 :
    gbyk_v4b_update2();
    break;

   case 3 :
    gbyk_v4b_update3();
    break;

   case 4 :
    gbyk_v4b_update4();
    break;

   case 5 :
    gbyk_v4b_update5();
    break;

   default :
    break;
  }
}

/* Model initialize function */
static void gbyk_v4b_initialize(void)
{
  {
    /* user code (Start function Header) */
    {
      int_T i;
      int_T idx;
      int_T idxSignalStart;
      int_T pdoSignalStringLength;
      char_T pdoListString[MAX_PDO_LIST_STRING_LENGTH];
      char_T pdoSignalString[MAX_PDO_SIGNAL_NAME_LENGTH];
      int_T slaveAddrStringLength;
      char_T slaveAddrListString[MAX_SLAVEADDR_LIST_STRING_LENGTH];
      char_T slaveAddrString[10];
      char_T delimiter = '!';
      g_pdoRxNumberSignals[1] = min(77, MAX_NUMBER_PDO_SIGNALS);
      g_pdoTxNumberSignals[1] = min(19, MAX_NUMBER_PDO_SIGNALS);
      strncpy(pdoListString,
              "!Drive 1 (Elmo Drive).Inputs.Position actual value!592!Drive 1 (Elmo Drive).Inputs.Digital Inputs!624!Drive 1 (Elmo Drive).Inputs.Status word!656!Drive 1 (Elmo Drive).Inputs_1.Mode of operation display!672!Drive 1 (Elmo Drive).Inputs_2.Velocity actual value!688!Drive 1 (Elmo Drive).Inputs_3.Torque actual value!720!Drive 1 (Elmo Drive).Inputs_4.Auxiliary position actual value!736!Drive 1 (Elmo Drive).Inputs_5.Elmo Status Reg!768!Drive 2 (Elmo Drive).Inputs.Position actual value!800!Drive 2 (Elmo Drive).Inputs.Digital Inputs!832!Drive 2 (Elmo Drive).Inputs.Status word!864!Drive 2 (Elmo Drive).Inputs_1.Mode of operation display!880!Drive 2 (Elmo Drive).Inputs_2.Velocity actual value!896!Drive 2 (Elmo Drive).Inputs_3.Torque actual value!928!Drive 2 (Elmo Drive).Inputs_4.Auxiliary position actual value!944!Drive 2 (Elmo Drive).Inputs_5.Elmo Status Reg!976!Drive 3 (Elmo Drive).Inputs.Position actual value!1008!Drive 3 (Elmo Drive).Inputs.Digital Inputs!1040!Drive 3 (Elmo Drive).Inputs.Status word!1072!Drive 3 (Elmo Drive).Inputs_1.Mode of operation display!1088!Drive 3 (Elmo Drive).Inputs_2.Velocity actual value!1104!Drive 3 (Elmo Drive).Inputs_3.Torque actual value!1136!Drive 3 (Elmo Drive).Inputs_4.Auxiliary position actual value!1152!Drive 3 (Elmo Drive).Inputs_5.Elmo Status Reg!1184!Drive 4 (Elmo Drive).Inputs.Position actual value!1216!Drive 4 (Elmo Drive).Inputs.Digital Inputs!1248!Drive 4 (Elmo Drive).Inputs.Status word!1280!Drive 4 (Elmo Drive).Inputs_1.Mode of operation display!1296!Drive 4 (Elmo Drive).Inputs_2.Velocity actual value!1312!Drive 4 (Elmo Drive).Inputs_3.Torque actual value!1344!Drive 4 (Elmo Drive).Inputs_4.Auxiliary position actual value!1360!Drive 4 (Elmo Drive).Inputs_5.Elmo Status Reg!1392!Inputs.Frm0State!12160!Inputs.Frm0WcState!12176!Drive 3 (Elmo Drive).WcState.WcState!12179!Drive 2 (Elmo Drive).WcState.WcState!12179!Drive 1 (Elmo Drive).WcState.WcState!12179!Drive 4 (Elmo Drive).WcState.WcState!12179!Inputs.Frm0InputToggle!12192!Drive 3 (Elmo Drive).WcState.InputToggle!12195!Drive 2 (Elmo Drive).WcState.InputToggle!12195!Drive 1 (Elmo Drive).WcState.InputToggle!12195!Drive 4 (Elmo Drive).WcState.InputToggle!12195!SyncUnits.Drive.<unreferenced>.WcState.WcState!12208!SyncUnits.Drive.Task 2.WcState.WcState!12209!Inputs.SlaveCount!12240!Inputs.DevState!12272!InfoData.ChangeCount!12288!InfoData.DevId!12304!InfoData.AmsNetId!12320!InfoData.CfgSlaveCount!12368!Drive 1 (Elmo Drive).InfoData.State!12384!Drive 1 (Elmo Drive).InfoData.AdsAddr!12400!Drive 1 (Elmo Drive).InfoData.Chn0!12464!Drive 1 (Elmo Drive).InfoData.DcOutputShift!12472!Drive 1 (Elmo Drive).InfoData.DcInputShift!12504!Drive 2 (Elmo Drive).InfoData.State!12536!Drive 2 (Elmo Drive).InfoData.AdsAddr!12552!Drive 2 (Elmo Drive).InfoData.Chn0!12616!Drive 2 (Elmo Drive).InfoData.DcOutputShift!12624!Drive 2 (Elmo Drive).InfoData.DcInputShift!12656!Drive 3 (Elmo Drive).InfoData.State!12688!Drive 3 (Elmo Drive).InfoData.AdsAddr!12704!Drive 3 (Elmo Drive).InfoData.Chn0!12768!Drive 3 (Elmo Drive).InfoData.DcOutputShift!12776!Drive 3 (Elmo Drive).InfoData.DcInputShift!12808!Drive 4 (Elmo Drive).InfoData.State!12840!Drive 4 (Elmo Drive).InfoData.AdsAddr!12856!Drive 4 (Elmo Drive).InfoData.Chn0!12920!Drive 4 (Elmo Drive).InfoData.DcOutputShift!12928!Drive 4 (Elmo Drive).InfoData.DcInputShift!12960!SyncUnits.Drive.<unreferenced>.InfoData.ObjectId!12992!SyncUnits.Drive.<unreferenced>.InfoData.State!13024!SyncUnits.Drive.<unreferenced>.InfoData.SlaveCount!13040!SyncUnits.Drive.Task 2.InfoData.ObjectId!13056!SyncUnits.Drive.Task 2.InfoData.State!13088!SyncUnits.Drive.Task 2.InfoData.SlaveCount!13104!",
              MAX_PDO_LIST_STRING_LENGTH);
      idx = 0;
      for (i = 0 ; i < g_pdoRxNumberSignals[1]; i++ ) {
        idxSignalStart = ++idx;
        while (pdoListString[idx] != delimiter && idx <
               MAX_PDO_LIST_STRING_LENGTH)
          idx++;
        pdoSignalStringLength = min( (idx - idxSignalStart ),
          MAX_PDO_SIGNAL_NAME_LENGTH - 1);
        strncpy(pdoSignalString, pdoListString + idxSignalStart,
                pdoSignalStringLength );
        pdoSignalString[pdoSignalStringLength] = '\0';
        strcpy(g_pdoRxSignalList[1][i], pdoSignalString);
        idxSignalStart = ++idx;
        while (pdoListString[idx] != delimiter && idx <
               MAX_PDO_LIST_STRING_LENGTH)
          idx++;
        pdoSignalStringLength = min( (idx - idxSignalStart ),
          MAX_PDO_SIGNAL_NAME_LENGTH - 1);
        strncpy(pdoSignalString, pdoListString + idxSignalStart,
                pdoSignalStringLength );
        pdoSignalString[pdoSignalStringLength] = '\0';
        g_pdoRxSignalOffset[1][i] = atoi(pdoSignalString);
      }

      strncpy(pdoListString,
              "!Drive 1 (Elmo Drive).Outputs.Target Torque!592!Drive 1 (Elmo Drive).Outputs.Control word!608!Drive 1 (Elmo Drive).Outputs_1.Mode of operation!624!Drive 1 (Elmo Drive).Outputs_2.Digital Outputs!640!Drive 2 (Elmo Drive).Outputs.Target Torque!800!Drive 2 (Elmo Drive).Outputs.Control word!816!Drive 2 (Elmo Drive).Outputs_1.Mode of operation!832!Drive 2 (Elmo Drive).Outputs_2.Digital Outputs!848!Drive 3 (Elmo Drive).Outputs.Target Torque!1008!Drive 3 (Elmo Drive).Outputs.Control word!1024!Drive 3 (Elmo Drive).Outputs_1.Mode of operation!1040!Drive 3 (Elmo Drive).Outputs_2.Digital Outputs!1056!Drive 4 (Elmo Drive).Outputs.Target Torque!1216!Drive 4 (Elmo Drive).Outputs.Control word!1232!Drive 4 (Elmo Drive).Outputs_1.Mode of operation!1248!Drive 4 (Elmo Drive).Outputs_2.Digital Outputs!1264!Outputs.Frm0Ctrl!12160!Outputs.Frm0WcCtrl!12176!Outputs.DevCtrl!12272!",
              MAX_PDO_LIST_STRING_LENGTH);
      idx = 0;
      for (i = 0 ; i < g_pdoTxNumberSignals[1]; i++ ) {
        idxSignalStart = ++idx;
        while (pdoListString[idx] != delimiter && idx <
               MAX_PDO_LIST_STRING_LENGTH)
          idx++;
        pdoSignalStringLength = min( (idx - idxSignalStart ),
          MAX_PDO_SIGNAL_NAME_LENGTH - 1);
        strncpy(pdoSignalString, pdoListString + idxSignalStart,
                pdoSignalStringLength );
        pdoSignalString[pdoSignalStringLength] = '\0';
        strcpy(g_pdoTxSignalList[1][i], pdoSignalString);
        idxSignalStart = ++idx;
        while (pdoListString[idx] != delimiter && idx <
               MAX_PDO_LIST_STRING_LENGTH)
          idx++;
        pdoSignalStringLength = min( (idx - idxSignalStart ),
          MAX_PDO_SIGNAL_NAME_LENGTH - 1);
        strncpy(pdoSignalString, pdoListString + idxSignalStart,
                pdoSignalStringLength );
        pdoSignalString[pdoSignalStringLength] = '\0';
        g_pdoTxSignalOffset[1][i] = atoi(pdoSignalString);
      }

      strncpy(slaveAddrListString, "!1001!1002!1003!1004!",
              MAX_SLAVEADDR_LIST_STRING_LENGTH);
      idx = 0;
      for (i = 0 ; i < 4; i++ ) {
        idxSignalStart = ++idx;
        while (slaveAddrListString[idx] != delimiter && idx <
               MAX_SLAVEADDR_LIST_STRING_LENGTH)
          idx++;
        slaveAddrStringLength = idx - idxSignalStart;
        strncpy(slaveAddrString, slaveAddrListString + idxSignalStart,
                slaveAddrStringLength );
        slaveAddrString[slaveAddrStringLength] = '\0';
        g_ecatSlaveAddressList[1][i] = (int_T)atoi(slaveAddrString);
      }
    }

    {
      int_T i;
      int_T idx;
      int_T idxSignalStart;
      int_T pdoSignalStringLength;
      char_T pdoListString[MAX_PDO_LIST_STRING_LENGTH];
      char_T pdoSignalString[MAX_PDO_SIGNAL_NAME_LENGTH];
      int_T slaveAddrStringLength;
      char_T slaveAddrListString[MAX_SLAVEADDR_LIST_STRING_LENGTH];
      char_T slaveAddrString[10];
      char_T delimiter = '!';
      g_pdoRxNumberSignals[0] = min(47, MAX_NUMBER_PDO_SIGNALS);
      g_pdoTxNumberSignals[0] = min(11, MAX_NUMBER_PDO_SIGNALS);
      strncpy(pdoListString,
              "!Drive 1 (Elmo Drive).Inputs.Position actual value!592!Drive 1 (Elmo Drive).Inputs.Digital Inputs!624!Drive 1 (Elmo Drive).Inputs.Status word!656!Drive 1 (Elmo Drive).Inputs_1.Mode of operation display!672!Drive 1 (Elmo Drive).Inputs_2.Velocity actual value!688!Drive 1 (Elmo Drive).Inputs_3.Torque actual value!720!Drive 1 (Elmo Drive).Inputs_4.Auxiliary position actual value!736!Drive 1 (Elmo Drive).Inputs_5.Elmo Status Reg!768!Drive 2 (Elmo Drive).Inputs.Position actual value!800!Drive 2 (Elmo Drive).Inputs.Digital Inputs!832!Drive 2 (Elmo Drive).Inputs.Status word!864!Drive 2 (Elmo Drive).Inputs_1.Mode of operation display!880!Drive 2 (Elmo Drive).Inputs_2.Velocity actual value!896!Drive 2 (Elmo Drive).Inputs_3.Torque actual value!928!Drive 2 (Elmo Drive).Inputs_4.Auxiliary position actual value!944!Drive 2 (Elmo Drive).Inputs_5.Elmo Status Reg!976!Inputs.Frm0State!12160!Inputs.Frm0WcState!12176!Drive 1 (Elmo Drive).WcState.WcState!12179!Drive 2 (Elmo Drive).WcState.WcState!12179!Inputs.Frm0InputToggle!12192!Drive 1 (Elmo Drive).WcState.InputToggle!12195!Drive 2 (Elmo Drive).WcState.InputToggle!12195!SyncUnits.Drive.<unreferenced>.WcState.WcState!12208!SyncUnits.Drive.Task 2.WcState.WcState!12209!Inputs.SlaveCount!12240!Inputs.DevState!12272!InfoData.ChangeCount!12288!InfoData.DevId!12304!InfoData.AmsNetId!12320!InfoData.CfgSlaveCount!12368!Drive 1 (Elmo Drive).InfoData.State!12384!Drive 1 (Elmo Drive).InfoData.AdsAddr!12400!Drive 1 (Elmo Drive).InfoData.Chn0!12464!Drive 1 (Elmo Drive).InfoData.DcOutputShift!12472!Drive 1 (Elmo Drive).InfoData.DcInputShift!12504!Drive 2 (Elmo Drive).InfoData.State!12536!Drive 2 (Elmo Drive).InfoData.AdsAddr!12552!Drive 2 (Elmo Drive).InfoData.Chn0!12616!Drive 2 (Elmo Drive).InfoData.DcOutputShift!12624!Drive 2 (Elmo Drive).InfoData.DcInputShift!12656!SyncUnits.Drive.<unreferenced>.InfoData.ObjectId!12688!SyncUnits.Drive.<unreferenced>.InfoData.State!12720!SyncUnits.Drive.<unreferenced>.InfoData.SlaveCount!12736!SyncUnits.Drive.Task 2.InfoData.ObjectId!12752!SyncUnits.Drive.Task 2.InfoData.State!12784!SyncUnits.Drive.Task 2.InfoData.SlaveCount!12800!",
              MAX_PDO_LIST_STRING_LENGTH);
      idx = 0;
      for (i = 0 ; i < g_pdoRxNumberSignals[0]; i++ ) {
        idxSignalStart = ++idx;
        while (pdoListString[idx] != delimiter && idx <
               MAX_PDO_LIST_STRING_LENGTH)
          idx++;
        pdoSignalStringLength = min( (idx - idxSignalStart ),
          MAX_PDO_SIGNAL_NAME_LENGTH - 1);
        strncpy(pdoSignalString, pdoListString + idxSignalStart,
                pdoSignalStringLength );
        pdoSignalString[pdoSignalStringLength] = '\0';
        strcpy(g_pdoRxSignalList[0][i], pdoSignalString);
        idxSignalStart = ++idx;
        while (pdoListString[idx] != delimiter && idx <
               MAX_PDO_LIST_STRING_LENGTH)
          idx++;
        pdoSignalStringLength = min( (idx - idxSignalStart ),
          MAX_PDO_SIGNAL_NAME_LENGTH - 1);
        strncpy(pdoSignalString, pdoListString + idxSignalStart,
                pdoSignalStringLength );
        pdoSignalString[pdoSignalStringLength] = '\0';
        g_pdoRxSignalOffset[0][i] = atoi(pdoSignalString);
      }

      strncpy(pdoListString,
              "!Drive 1 (Elmo Drive).Outputs.Target Torque!592!Drive 1 (Elmo Drive).Outputs.Control word!608!Drive 1 (Elmo Drive).Outputs_1.Mode of operation!624!Drive 1 (Elmo Drive).Outputs_2.Digital Outputs!640!Drive 2 (Elmo Drive).Outputs.Target Torque!800!Drive 2 (Elmo Drive).Outputs.Control word!816!Drive 2 (Elmo Drive).Outputs_1.Mode of operation!832!Drive 2 (Elmo Drive).Outputs_2.Digital Outputs!848!Outputs.Frm0Ctrl!12160!Outputs.Frm0WcCtrl!12176!Outputs.DevCtrl!12272!",
              MAX_PDO_LIST_STRING_LENGTH);
      idx = 0;
      for (i = 0 ; i < g_pdoTxNumberSignals[0]; i++ ) {
        idxSignalStart = ++idx;
        while (pdoListString[idx] != delimiter && idx <
               MAX_PDO_LIST_STRING_LENGTH)
          idx++;
        pdoSignalStringLength = min( (idx - idxSignalStart ),
          MAX_PDO_SIGNAL_NAME_LENGTH - 1);
        strncpy(pdoSignalString, pdoListString + idxSignalStart,
                pdoSignalStringLength );
        pdoSignalString[pdoSignalStringLength] = '\0';
        strcpy(g_pdoTxSignalList[0][i], pdoSignalString);
        idxSignalStart = ++idx;
        while (pdoListString[idx] != delimiter && idx <
               MAX_PDO_LIST_STRING_LENGTH)
          idx++;
        pdoSignalStringLength = min( (idx - idxSignalStart ),
          MAX_PDO_SIGNAL_NAME_LENGTH - 1);
        strncpy(pdoSignalString, pdoListString + idxSignalStart,
                pdoSignalStringLength );
        pdoSignalString[pdoSignalStringLength] = '\0';
        g_pdoTxSignalOffset[0][i] = atoi(pdoSignalString);
      }

      strncpy(slaveAddrListString, "!1001!1002!",
              MAX_SLAVEADDR_LIST_STRING_LENGTH);
      idx = 0;
      for (i = 0 ; i < 2; i++ ) {
        idxSignalStart = ++idx;
        while (slaveAddrListString[idx] != delimiter && idx <
               MAX_SLAVEADDR_LIST_STRING_LENGTH)
          idx++;
        slaveAddrStringLength = idx - idxSignalStart;
        strncpy(slaveAddrString, slaveAddrListString + idxSignalStart,
                slaveAddrStringLength );
        slaveAddrString[slaveAddrStringLength] = '\0';
        g_ecatSlaveAddressList[0][i] = (int_T)atoi(slaveAddrString);
      }
    }

    /* Level2 S-Function Block: '<S7>/ICH7' (ich10) */
    {
      SimStruct *rts = gbyk_v4b_M->childSfunctions[40];
      sfcnStart(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Start for Constant: '<S7>/Block Definitions' */
    memcpy(&gbyk_v4b_B.BlockDefinitions[0], &gbyk_v4b_P.BlockDefinitions_Value[0],
           25000U * sizeof(real_T));

    /* Start for Constant: '<S7>/Block Sequence' */
    memcpy(&gbyk_v4b_B.BlockSequence[0], &gbyk_v4b_P.BlockSequence_Value[0],
           2000U * sizeof(real_T));

    /* Level2 S-Function Block: '<S268>/Run Command Receive' (xpcudpbytereceive) */
    {
      SimStruct *rts = gbyk_v4b_M->childSfunctions[41];
      sfcnStart(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Start for Constant: '<S7>/Pause Type' */
    gbyk_v4b_B.PauseType = gbyk_v4b_P.PauseType_Value;

    /* Start for Constant: '<S7>/Use Task Protocol Block Sequence Flag' */
    gbyk_v4b_B.UseTaskProtocolBlockSequenceFlag =
      gbyk_v4b_P.UseTaskProtocolBlockSequenceFlag_Value;

    /* Start for Constant: '<S7>/Next Block' */
    gbyk_v4b_B.NextBlock = gbyk_v4b_P.NextBlock_Value;

    /* Start for Atomic SubSystem: '<S7>/Task Execution Control Subsystem' */
    gbyk_v4b_TaskExecutionControlSubsystem_Start();

    /* End of Start for SubSystem: '<S7>/Task Execution Control Subsystem' */

    /* Start for Constant: '<S7>/Target Table' */
    memcpy(&gbyk_v4b_B.TargetTable[0], &gbyk_v4b_P.TargetTable_Value[0], 800U *
           sizeof(real_T));

    /* Start for Constant: '<S7>/Task wide param' */
    memcpy(&gbyk_v4b_B.Taskwideparam[0], &gbyk_v4b_P.Taskwideparam_Value[0], 50U
           * sizeof(real_T));

    /* Start for Atomic SubSystem: '<S4>/Receive_Gaze' */
    gbyk_v4b_Receive_Gaze_Start();

    /* End of Start for SubSystem: '<S4>/Receive_Gaze' */

    /* Start for Atomic SubSystem: '<S4>/Poll KINARM' */
    gbyk_v4b_PollKINARM_Start();

    /* End of Start for SubSystem: '<S4>/Poll KINARM' */

    /* Start for Atomic SubSystem: '<S15>/PVC_core' */
    gbyk_v4b_PVC_core_Start();

    /* End of Start for SubSystem: '<S15>/PVC_core' */

    /* Level2 S-Function Block: '<S15>/Receive' (xpcudpbytereceive) */
    {
      SimStruct *rts = gbyk_v4b_M->childSfunctions[42];
      sfcnStart(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* Start for RateTransition: '<S28>/TmpRTBAtNumber of Event CodesOutport1' */
    gbyk_v4b_B.TmpRTBAtNumberofEventCodesOutport1 =
      gbyk_v4b_P.TmpRTBAtNumberofEventCodesOutport1_X0;

    /* Start for Atomic SubSystem: '<S4>/Poll Force Plates' */
    gbyk_v4b_PollForcePlates_Start();

    /* End of Start for SubSystem: '<S4>/Poll Force Plates' */

    /* Start for RateTransition: '<S27>/Rate Transition2' */
    gbyk_v4b_B.RateTransition2_eo = gbyk_v4b_P.RateTransition2_X0_o;

    /* Start for Atomic SubSystem: '<S4>/Network Transfer Subsystem' */
    gbyk_v4b_NetworkTransferSubsystem_Start();

    /* End of Start for SubSystem: '<S4>/Network Transfer Subsystem' */

    /* Start for Atomic SubSystem: '<S4>/apply loads' */
    gbyk_v4b_applyloads_Start();

    /* End of Start for SubSystem: '<S4>/apply loads' */

    /* Start for Atomic SubSystem: '<S4>/Keep alive' */
    gbyk_v4b_Keepalive_Start();

    /* End of Start for SubSystem: '<S4>/Keep alive' */

    /* Start for DataStoreMemory: '<S4>/ECAT Dig Diagnostic' */
    gbyk_v4b_DW.ECATDigDiagnostic[0] =
      gbyk_v4b_P.ECATDigDiagnostic_InitialValue[0];
    gbyk_v4b_DW.ECATDigDiagnostic[1] =
      gbyk_v4b_P.ECATDigDiagnostic_InitialValue[1];
    gbyk_v4b_DW.ECATDigDiagnostic[2] =
      gbyk_v4b_P.ECATDigDiagnostic_InitialValue[2];
    gbyk_v4b_DW.ECATDigDiagnostic[3] =
      gbyk_v4b_P.ECATDigDiagnostic_InitialValue[3];

    /* Start for DataStoreMemory: '<S4>/ECAT Status' */
    memcpy(&gbyk_v4b_DW.ECATStatus[0], &gbyk_v4b_P.ECATStatus_InitialValue[0],
           sizeof(real_T) << 3U);

    /* Start for DataStoreMemory: '<S4>/ECAT hardware' */
    memcpy(&gbyk_v4b_DW.ECATHardware[0], &gbyk_v4b_P.ECAThardware_InitialValue[0],
           14U * sizeof(real_T));

    /* Level2 S-Function Block: '<S15>/Send' (xpcudpbytesend) */
    {
      SimStruct *rts = gbyk_v4b_M->childSfunctions[43];
      sfcnStart(rts);
      if (ssGetErrorStatus(rts) != (NULL))
        return;
    }

    /* S-Function Block: <S16>/S-Function (scblock) */
    {
      int i;
      if ((i = rl32eScopeExists(1)) == 0) {
        if ((i = rl32eDefScope(1,2)) != 0) {
          printf("Error creating scope 1\n");
        } else {
          rl32eAddSignal(1, rl32eGetSignalNo("Vector Concatenate2/s1"));
          rl32eAddSignal(1, rl32eGetSignalNo("Vector Concatenate2/s2"));
          rl32eAddSignal(1, rl32eGetSignalNo("Vector Concatenate2/s3"));
          rl32eSetTargetScopeSigFt(1,rl32eGetSignalNo("Vector Concatenate2/s1"),
            "%15.6f");
          rl32eSetTargetScopeSigFt(1,rl32eGetSignalNo("Vector Concatenate2/s2"),
            "%15.6f");
          rl32eSetTargetScopeSigFt(1,rl32eGetSignalNo("Vector Concatenate2/s3"),
            "%15.6f");
          rl32eSetScope(1, 4, 250);
          rl32eSetScope(1, 5, 0);
          rl32eSetScope(1, 6, 1);
          rl32eSetScope(1, 0, 0);
          rl32eSetScope(1, 3, rl32eGetSignalNo("Vector Concatenate2/s1"));
          rl32eSetScope(1, 1, 0.0);
          rl32eSetScope(1, 2, 0);
          rl32eSetScope(1, 9, 0);
          rl32eSetTargetScope(1, 1, 0.0);
          rl32eSetTargetScope(1, 11, 0.0);
          rl32eSetTargetScope(1, 10, 0.0);
          xpceScopeAcqOK(1, &gbyk_v4b_DW.SFunction_IWORK.AcquireOK);
        }
      }

      if (i) {
        rl32eRestartAcquisition(1);
      }
    }

    /* S-Function Block: <S17>/S-Function (scblock) */
    {
      int i;
      if ((i = rl32eScopeExists(5)) == 0) {
        if ((i = rl32eDefScope(5,2)) != 0) {
          printf("Error creating scope 5\n");
        } else {
          rl32eAddSignal(5, rl32eGetSignalNo("Selector4/s1"));
          rl32eAddSignal(5, rl32eGetSignalNo("Selector4/s2"));
          rl32eAddSignal(5, rl32eGetSignalNo("Selector4/s3"));
          rl32eAddSignal(5, rl32eGetSignalNo("Selector4/s4"));
          rl32eAddSignal(5, rl32eGetSignalNo("Selector4/s5"));
          rl32eAddSignal(5, rl32eGetSignalNo("Selector4/s6"));
          rl32eAddSignal(5, rl32eGetSignalNo("Selector4/s7"));
          rl32eAddSignal(5, rl32eGetSignalNo("Selector4/s8"));
          rl32eAddSignal(5, rl32eGetSignalNo("Selector4/s9"));
          rl32eAddSignal(5, rl32eGetSignalNo("Selector4/s10"));
          rl32eAddSignal(5, rl32eGetSignalNo("Selector4/s11"));
          rl32eAddSignal(5, rl32eGetSignalNo("Selector4/s12"));
          rl32eAddSignal(5, rl32eGetSignalNo("Selector4/s13"));
          rl32eAddSignal(5, rl32eGetSignalNo("Selector4/s14"));
          rl32eAddSignal(5, rl32eGetSignalNo("Selector4/s15"));
          rl32eAddSignal(5, rl32eGetSignalNo("Selector4/s16"));
          rl32eAddSignal(5, rl32eGetSignalNo("Selector4/s17"));
          rl32eAddSignal(5, rl32eGetSignalNo("Selector4/s18"));
          rl32eAddSignal(5, rl32eGetSignalNo("Selector4/s19"));
          rl32eAddSignal(5, rl32eGetSignalNo("Selector4/s20"));
          rl32eAddSignal(5, rl32eGetSignalNo("Selector4/s21"));
          rl32eAddSignal(5, rl32eGetSignalNo("Selector4/s22"));
          rl32eAddSignal(5, rl32eGetSignalNo("Selector4/s23"));
          rl32eAddSignal(5, rl32eGetSignalNo("Selector4/s24"));
          rl32eAddSignal(5, rl32eGetSignalNo("Selector4/s25"));
          rl32eAddSignal(5, rl32eGetSignalNo("Selector4/s26"));
          rl32eAddSignal(5, rl32eGetSignalNo("Selector4/s27"));
          rl32eAddSignal(5, rl32eGetSignalNo("Selector4/s28"));
          rl32eAddSignal(5, rl32eGetSignalNo("Selector4/s29"));
          rl32eAddSignal(5, rl32eGetSignalNo("Selector4/s30"));
          rl32eAddSignal(5, rl32eGetSignalNo("Selector4/s31"));
          rl32eAddSignal(5, rl32eGetSignalNo("Selector4/s32"));
          rl32eAddSignal(5, rl32eGetSignalNo("Selector4/s33"));
          rl32eAddSignal(5, rl32eGetSignalNo("Selector4/s34"));
          rl32eAddSignal(5, rl32eGetSignalNo("Selector4/s35"));
          rl32eAddSignal(5, rl32eGetSignalNo("Selector4/s36"));
          rl32eAddSignal(5, rl32eGetSignalNo("Selector4/s37"));
          rl32eAddSignal(5, rl32eGetSignalNo("Selector4/s38"));
          rl32eAddSignal(5, rl32eGetSignalNo("Selector4/s39"));
          rl32eAddSignal(5, rl32eGetSignalNo("Selector4/s40"));
          rl32eAddSignal(5, rl32eGetSignalNo("Selector4/s41"));
          rl32eAddSignal(5, rl32eGetSignalNo("Selector4/s42"));
          rl32eAddSignal(5, rl32eGetSignalNo("Selector4/s43"));
          rl32eAddSignal(5, rl32eGetSignalNo("Selector4/s44"));
          rl32eAddSignal(5, rl32eGetSignalNo("Selector4/s45"));
          rl32eAddSignal(5, rl32eGetSignalNo("Selector4/s46"));
          rl32eAddSignal(5, rl32eGetSignalNo("Selector4/s47"));
          rl32eAddSignal(5, rl32eGetSignalNo("Selector4/s48"));
          rl32eAddSignal(5, rl32eGetSignalNo("Selector4/s49"));
          rl32eAddSignal(5, rl32eGetSignalNo("Selector4/s50"));
          rl32eAddSignal(5, rl32eGetSignalNo("Selector4/s51"));
          rl32eAddSignal(5, rl32eGetSignalNo("Selector4/s52"));
          rl32eAddSignal(5, rl32eGetSignalNo("Selector4/s53"));
          rl32eAddSignal(5, rl32eGetSignalNo("Selector4/s54"));
          rl32eAddSignal(5, rl32eGetSignalNo("Selector4/s55"));
          rl32eAddSignal(5, rl32eGetSignalNo("Selector4/s56"));
          rl32eAddSignal(5, rl32eGetSignalNo("Selector4/s57"));
          rl32eAddSignal(5, rl32eGetSignalNo("Selector4/s58"));
          rl32eAddSignal(5, rl32eGetSignalNo("Selector4/s59"));
          rl32eAddSignal(5, rl32eGetSignalNo("Selector4/s60"));
          rl32eSetTargetScopeSigFt(5,rl32eGetSignalNo("Selector4/s1"),"%15.6f");
          rl32eSetTargetScopeSigFt(5,rl32eGetSignalNo("Selector4/s2"),"%15.6f");
          rl32eSetTargetScopeSigFt(5,rl32eGetSignalNo("Selector4/s3"),"%15.6f");
          rl32eSetTargetScopeSigFt(5,rl32eGetSignalNo("Selector4/s4"),"%15.6f");
          rl32eSetTargetScopeSigFt(5,rl32eGetSignalNo("Selector4/s5"),"%15.6f");
          rl32eSetTargetScopeSigFt(5,rl32eGetSignalNo("Selector4/s6"),"%15.6f");
          rl32eSetTargetScopeSigFt(5,rl32eGetSignalNo("Selector4/s7"),"%15.6f");
          rl32eSetTargetScopeSigFt(5,rl32eGetSignalNo("Selector4/s8"),"%15.6f");
          rl32eSetTargetScopeSigFt(5,rl32eGetSignalNo("Selector4/s9"),"%15.6f");
          rl32eSetTargetScopeSigFt(5,rl32eGetSignalNo("Selector4/s10"),"%15.6f");
          rl32eSetScope(5, 4, 250);
          rl32eSetScope(5, 5, 0);
          rl32eSetScope(5, 6, 1);
          rl32eSetScope(5, 0, 0);
          rl32eSetScope(5, 3, rl32eGetSignalNo("Selector4/s1"));
          rl32eSetScope(5, 1, 0.0);
          rl32eSetScope(5, 2, 0);
          rl32eSetScope(5, 9, 0);
          rl32eSetTargetScope(5, 1, 0.0);
          rl32eSetTargetScope(5, 11, 0.0);
          rl32eSetTargetScope(5, 10, 0.0);
          xpceScopeAcqOK(5, &gbyk_v4b_DW.SFunction_IWORK_n.AcquireOK);
        }
      }

      if (i) {
        rl32eRestartAcquisition(5);
      }
    }

    /* S-Function Block: <S18>/S-Function (scblock) */
    {
      int i;
      if ((i = rl32eScopeExists(7)) == 0) {
        if ((i = rl32eDefScope(7,2)) != 0) {
          printf("Error creating scope 7\n");
        } else {
          rl32eAddSignal(7, rl32eGetSignalNo("Trigonometric Function"));
          rl32eSetTargetScopeSigFt(7,rl32eGetSignalNo("Trigonometric Function"),
            "%15.6f");
          rl32eSetScope(7, 4, 250);
          rl32eSetScope(7, 5, 0);
          rl32eSetScope(7, 6, 1);
          rl32eSetScope(7, 0, 0);
          rl32eSetScope(7, 3, rl32eGetSignalNo("Trigonometric Function"));
          rl32eSetScope(7, 1, 0.0);
          rl32eSetScope(7, 2, 0);
          rl32eSetScope(7, 9, 0);
          rl32eSetTargetScope(7, 1, 0.0);
          rl32eSetTargetScope(7, 11, 0.0);
          rl32eSetTargetScope(7, 10, 0.0);
          xpceScopeAcqOK(7, &gbyk_v4b_DW.SFunction_IWORK_i.AcquireOK);
        }
      }

      if (i) {
        rl32eRestartAcquisition(7);
      }
    }

    /* S-Function Block: <S19>/S-Function (scblock) */
    {
      int i;
      if ((i = rl32eScopeExists(8)) == 0) {
        if ((i = rl32eDefScope(8,2)) != 0) {
          printf("Error creating scope 8\n");
        } else {
          rl32eAddSignal(8, rl32eGetSignalNo("Vector Concatenate1/s1"));
          rl32eAddSignal(8, rl32eGetSignalNo("Vector Concatenate1/s2"));
          rl32eAddSignal(8, rl32eGetSignalNo("Vector Concatenate1/s3"));
          rl32eAddSignal(8, rl32eGetSignalNo("Vector Concatenate1/s4"));
          rl32eSetTargetScopeSigFt(8,rl32eGetSignalNo("Vector Concatenate1/s1"),
            "%15.6f");
          rl32eSetTargetScopeSigFt(8,rl32eGetSignalNo("Vector Concatenate1/s2"),
            "%15.6f");
          rl32eSetTargetScopeSigFt(8,rl32eGetSignalNo("Vector Concatenate1/s3"),
            "%15.6f");
          rl32eSetTargetScopeSigFt(8,rl32eGetSignalNo("Vector Concatenate1/s4"),
            "%15.6f");
          rl32eSetScope(8, 4, 250);
          rl32eSetScope(8, 5, 0);
          rl32eSetScope(8, 6, 1);
          rl32eSetScope(8, 0, 0);
          rl32eSetScope(8, 3, rl32eGetSignalNo("Vector Concatenate1/s1"));
          rl32eSetScope(8, 1, 0.0);
          rl32eSetScope(8, 2, 0);
          rl32eSetScope(8, 9, 0);
          rl32eSetTargetScope(8, 1, 0.0);
          rl32eSetTargetScope(8, 11, 0.0);
          rl32eSetTargetScope(8, 10, 0.0);
          xpceScopeAcqOK(8, &gbyk_v4b_DW.SFunction_IWORK_j.AcquireOK);
        }
      }

      if (i) {
        rl32eRestartAcquisition(8);
      }
    }

    /* S-Function Block: <S20>/S-Function (scblock) */
    {
      int i;
      if ((i = rl32eScopeExists(6)) == 0) {
        if ((i = rl32eDefScope(6,2)) != 0) {
          printf("Error creating scope 6\n");
        } else {
          rl32eAddSignal(6, rl32eGetSignalNo("Selector5/s1"));
          rl32eAddSignal(6, rl32eGetSignalNo("Selector5/s2"));
          rl32eAddSignal(6, rl32eGetSignalNo("Selector5/s3"));
          rl32eAddSignal(6, rl32eGetSignalNo("Selector5/s4"));
          rl32eAddSignal(6, rl32eGetSignalNo("Selector5/s5"));
          rl32eAddSignal(6, rl32eGetSignalNo("Selector5/s6"));
          rl32eAddSignal(6, rl32eGetSignalNo("Selector5/s7"));
          rl32eAddSignal(6, rl32eGetSignalNo("Selector5/s8"));
          rl32eAddSignal(6, rl32eGetSignalNo("Selector5/s9"));
          rl32eAddSignal(6, rl32eGetSignalNo("Selector5/s10"));
          rl32eAddSignal(6, rl32eGetSignalNo("Selector5/s11"));
          rl32eAddSignal(6, rl32eGetSignalNo("Selector5/s12"));
          rl32eAddSignal(6, rl32eGetSignalNo("Selector5/s13"));
          rl32eAddSignal(6, rl32eGetSignalNo("Selector5/s14"));
          rl32eAddSignal(6, rl32eGetSignalNo("Selector5/s15"));
          rl32eAddSignal(6, rl32eGetSignalNo("Selector5/s16"));
          rl32eAddSignal(6, rl32eGetSignalNo("Selector5/s17"));
          rl32eAddSignal(6, rl32eGetSignalNo("Selector5/s18"));
          rl32eAddSignal(6, rl32eGetSignalNo("Selector5/s19"));
          rl32eAddSignal(6, rl32eGetSignalNo("Selector5/s20"));
          rl32eAddSignal(6, rl32eGetSignalNo("Selector5/s21"));
          rl32eAddSignal(6, rl32eGetSignalNo("Selector5/s22"));
          rl32eAddSignal(6, rl32eGetSignalNo("Selector5/s23"));
          rl32eAddSignal(6, rl32eGetSignalNo("Selector5/s24"));
          rl32eAddSignal(6, rl32eGetSignalNo("Selector5/s25"));
          rl32eAddSignal(6, rl32eGetSignalNo("Selector5/s26"));
          rl32eAddSignal(6, rl32eGetSignalNo("Selector5/s27"));
          rl32eAddSignal(6, rl32eGetSignalNo("Selector5/s28"));
          rl32eAddSignal(6, rl32eGetSignalNo("Selector5/s29"));
          rl32eAddSignal(6, rl32eGetSignalNo("Selector5/s30"));
          rl32eAddSignal(6, rl32eGetSignalNo("Selector5/s31"));
          rl32eAddSignal(6, rl32eGetSignalNo("Selector5/s32"));
          rl32eAddSignal(6, rl32eGetSignalNo("Selector5/s33"));
          rl32eAddSignal(6, rl32eGetSignalNo("Selector5/s34"));
          rl32eAddSignal(6, rl32eGetSignalNo("Selector5/s35"));
          rl32eAddSignal(6, rl32eGetSignalNo("Selector5/s36"));
          rl32eAddSignal(6, rl32eGetSignalNo("Selector5/s37"));
          rl32eAddSignal(6, rl32eGetSignalNo("Selector5/s38"));
          rl32eAddSignal(6, rl32eGetSignalNo("Selector5/s39"));
          rl32eAddSignal(6, rl32eGetSignalNo("Selector5/s40"));
          rl32eAddSignal(6, rl32eGetSignalNo("Selector5/s41"));
          rl32eAddSignal(6, rl32eGetSignalNo("Selector5/s42"));
          rl32eAddSignal(6, rl32eGetSignalNo("Selector5/s43"));
          rl32eAddSignal(6, rl32eGetSignalNo("Selector5/s44"));
          rl32eAddSignal(6, rl32eGetSignalNo("Selector5/s45"));
          rl32eAddSignal(6, rl32eGetSignalNo("Selector5/s46"));
          rl32eAddSignal(6, rl32eGetSignalNo("Selector5/s47"));
          rl32eAddSignal(6, rl32eGetSignalNo("Selector5/s48"));
          rl32eAddSignal(6, rl32eGetSignalNo("Selector5/s49"));
          rl32eAddSignal(6, rl32eGetSignalNo("Selector5/s50"));
          rl32eAddSignal(6, rl32eGetSignalNo("Selector5/s51"));
          rl32eAddSignal(6, rl32eGetSignalNo("Selector5/s52"));
          rl32eAddSignal(6, rl32eGetSignalNo("Selector5/s53"));
          rl32eAddSignal(6, rl32eGetSignalNo("Selector5/s54"));
          rl32eAddSignal(6, rl32eGetSignalNo("Selector5/s55"));
          rl32eAddSignal(6, rl32eGetSignalNo("Selector5/s56"));
          rl32eAddSignal(6, rl32eGetSignalNo("Selector5/s57"));
          rl32eAddSignal(6, rl32eGetSignalNo("Selector5/s58"));
          rl32eAddSignal(6, rl32eGetSignalNo("Selector5/s59"));
          rl32eAddSignal(6, rl32eGetSignalNo("Selector5/s60"));
          rl32eSetTargetScopeSigFt(6,rl32eGetSignalNo("Selector5/s1"),"%15.6f");
          rl32eSetTargetScopeSigFt(6,rl32eGetSignalNo("Selector5/s2"),"%15.6f");
          rl32eSetTargetScopeSigFt(6,rl32eGetSignalNo("Selector5/s3"),"%15.6f");
          rl32eSetTargetScopeSigFt(6,rl32eGetSignalNo("Selector5/s4"),"%15.6f");
          rl32eSetTargetScopeSigFt(6,rl32eGetSignalNo("Selector5/s5"),"%15.6f");
          rl32eSetTargetScopeSigFt(6,rl32eGetSignalNo("Selector5/s6"),"%15.6f");
          rl32eSetTargetScopeSigFt(6,rl32eGetSignalNo("Selector5/s7"),"%15.6f");
          rl32eSetTargetScopeSigFt(6,rl32eGetSignalNo("Selector5/s8"),"%15.6f");
          rl32eSetTargetScopeSigFt(6,rl32eGetSignalNo("Selector5/s9"),"%15.6f");
          rl32eSetTargetScopeSigFt(6,rl32eGetSignalNo("Selector5/s10"),"%15.6f");
          rl32eSetScope(6, 4, 250);
          rl32eSetScope(6, 5, 0);
          rl32eSetScope(6, 6, 1);
          rl32eSetScope(6, 0, 0);
          rl32eSetScope(6, 3, rl32eGetSignalNo("Selector5/s1"));
          rl32eSetScope(6, 1, 0.0);
          rl32eSetScope(6, 2, 0);
          rl32eSetScope(6, 9, 0);
          rl32eSetTargetScope(6, 1, 0.0);
          rl32eSetTargetScope(6, 11, 0.0);
          rl32eSetTargetScope(6, 10, 0.0);
          xpceScopeAcqOK(6, &gbyk_v4b_DW.SFunction_IWORK_c.AcquireOK);
        }
      }

      if (i) {
        rl32eRestartAcquisition(6);
      }
    }

    /* user code (Start function Trailer) */
    {
      int_T deviceIndex;
      int_T i;
      int_T slaveIsInSlaveAddressList;
      deviceIndex = g_deviceIndex;
      if (!xpcIsModelInit()) {
        if (deviceIndex != NO_ETHERCAT) {
          slaveIsInSlaveAddressList = 0;// default value
          for (i = 0; i < MAX_NUMBER_ECAT_SLAVES; i++) {
            if (1001 == g_ecatSlaveAddressList[deviceIndex][i])
              slaveIsInSlaveAddressList = 1;
          }

          if (slaveIsInSlaveAddressList == 0) {
            deviceIndex = NO_ETHERCAT;
          } else {
            registerAsyncSDOUpload(342973257,1*(uint32_T)4,(uint32_T)deviceIndex);
            printf("SDO Upload. Register device %d, slave addr: %d\n",
                   deviceIndex, 1001 );
          }
        }

        gbyk_v4b_DW.BKINEtherCATAsyncSDOUpload_IWORK_hj[0] = deviceIndex;
        gbyk_v4b_DW.BKINEtherCATAsyncSDOUpload_IWORK_hj[7] = 0;
      }
    }

    {
      int_T deviceIndex;
      int_T i;
      int_T slaveIsInSlaveAddressList;
      deviceIndex = g_deviceIndex;
      if (!xpcIsModelInit()) {
        if (deviceIndex != NO_ETHERCAT) {
          slaveIsInSlaveAddressList = 0;// default value
          for (i = 0; i < MAX_NUMBER_ECAT_SLAVES; i++) {
            if (1001 == g_ecatSlaveAddressList[deviceIndex][i])
              slaveIsInSlaveAddressList = 1;
          }

          if (slaveIsInSlaveAddressList == 0) {
            deviceIndex = NO_ETHERCAT;
          } else {
            registerAsyncSDOUpload(342973265,1*(uint32_T)4,(uint32_T)deviceIndex);
            printf("SDO Upload. Register device %d, slave addr: %d\n",
                   deviceIndex, 1001 );
          }
        }

        gbyk_v4b_DW.BKINEtherCATAsyncSDOUpload_IWORK_b[0] = deviceIndex;
        gbyk_v4b_DW.BKINEtherCATAsyncSDOUpload_IWORK_b[7] = 0;
      }
    }

    {
      int_T deviceIndex;
      int_T i;
      int_T slaveIsInSlaveAddressList;
      deviceIndex = g_deviceIndex;
      if (!xpcIsModelInit()) {
        if (deviceIndex != NO_ETHERCAT) {
          slaveIsInSlaveAddressList = 0;// default value
          for (i = 0; i < MAX_NUMBER_ECAT_SLAVES; i++) {
            if (1001 == g_ecatSlaveAddressList[deviceIndex][i])
              slaveIsInSlaveAddressList = 1;
          }

          if (slaveIsInSlaveAddressList == 0) {
            deviceIndex = NO_ETHERCAT;
          } else {
            registerAsyncSDODownload(342973277,1*(uint32_T)4,(uint32_T)
              deviceIndex);
            printf("SDO Download. Register device %d, slave addr: %d\n",
                   deviceIndex, 1001);
          }
        }

        gbyk_v4b_DW.BKINEtherCATAsyncSDODownload_IWORK_g1[0] = deviceIndex;
        gbyk_v4b_DW.BKINEtherCATAsyncSDODownload_IWORK_g1[7] = 0;
      }
    }

    {
      int_T deviceIndex;
      int_T i;
      int_T slaveIsInSlaveAddressList;
      deviceIndex = g_deviceIndex;
      if (!xpcIsModelInit()) {
        if (deviceIndex != NO_ETHERCAT) {
          slaveIsInSlaveAddressList = 0;// default value
          for (i = 0; i < MAX_NUMBER_ECAT_SLAVES; i++) {
            if (1002 == g_ecatSlaveAddressList[deviceIndex][i])
              slaveIsInSlaveAddressList = 1;
          }

          if (slaveIsInSlaveAddressList == 0) {
            deviceIndex = NO_ETHERCAT;
          } else {
            registerAsyncSDOUpload(342973341,1*(uint32_T)4,(uint32_T)deviceIndex);
            printf("SDO Upload. Register device %d, slave addr: %d\n",
                   deviceIndex, 1002 );
          }
        }

        gbyk_v4b_DW.BKINEtherCATAsyncSDOUpload_IWORK_j[0] = deviceIndex;
        gbyk_v4b_DW.BKINEtherCATAsyncSDOUpload_IWORK_j[7] = 0;
      }
    }

    {
      int_T deviceIndex;
      int_T i;
      int_T slaveIsInSlaveAddressList;
      deviceIndex = g_deviceIndex;
      if (!xpcIsModelInit()) {
        if (deviceIndex != NO_ETHERCAT) {
          slaveIsInSlaveAddressList = 0;// default value
          for (i = 0; i < MAX_NUMBER_ECAT_SLAVES; i++) {
            if (1002 == g_ecatSlaveAddressList[deviceIndex][i])
              slaveIsInSlaveAddressList = 1;
          }

          if (slaveIsInSlaveAddressList == 0) {
            deviceIndex = NO_ETHERCAT;
          } else {
            registerAsyncSDOUpload(342973352,1*(uint32_T)4,(uint32_T)deviceIndex);
            printf("SDO Upload. Register device %d, slave addr: %d\n",
                   deviceIndex, 1002 );
          }
        }

        gbyk_v4b_DW.BKINEtherCATAsyncSDOUpload_IWORK_a[0] = deviceIndex;
        gbyk_v4b_DW.BKINEtherCATAsyncSDOUpload_IWORK_a[7] = 0;
      }
    }

    {
      int_T deviceIndex;
      int_T i;
      int_T slaveIsInSlaveAddressList;
      deviceIndex = g_deviceIndex;
      if (!xpcIsModelInit()) {
        if (deviceIndex != NO_ETHERCAT) {
          slaveIsInSlaveAddressList = 0;// default value
          for (i = 0; i < MAX_NUMBER_ECAT_SLAVES; i++) {
            if (1002 == g_ecatSlaveAddressList[deviceIndex][i])
              slaveIsInSlaveAddressList = 1;
          }

          if (slaveIsInSlaveAddressList == 0) {
            deviceIndex = NO_ETHERCAT;
          } else {
            registerAsyncSDODownload(342973361,1*(uint32_T)4,(uint32_T)
              deviceIndex);
            printf("SDO Download. Register device %d, slave addr: %d\n",
                   deviceIndex, 1002);
          }
        }

        gbyk_v4b_DW.BKINEtherCATAsyncSDODownload_IWORK_g[0] = deviceIndex;
        gbyk_v4b_DW.BKINEtherCATAsyncSDODownload_IWORK_g[7] = 0;
      }
    }

    {
      int_T deviceIndex;
      int_T i;
      int_T slaveIsInSlaveAddressList;
      deviceIndex = g_deviceIndex;
      if (!xpcIsModelInit()) {
        if (deviceIndex != NO_ETHERCAT) {
          slaveIsInSlaveAddressList = 0;// default value
          for (i = 0; i < MAX_NUMBER_ECAT_SLAVES; i++) {
            if (1001 == g_ecatSlaveAddressList[deviceIndex][i])
              slaveIsInSlaveAddressList = 1;
          }

          if (slaveIsInSlaveAddressList == 0) {
            deviceIndex = NO_ETHERCAT;
          } else {
            registerAsyncSDOUpload(35101310,1*(uint32_T)4,(uint32_T)deviceIndex);
            printf("SDO Upload. Register device %d, slave addr: %d\n",
                   deviceIndex, 1001 );
          }
        }

        gbyk_v4b_DW.BKINEtherCATAsyncSDOUpload1_IWORK_a[0] = deviceIndex;
        gbyk_v4b_DW.BKINEtherCATAsyncSDOUpload1_IWORK_a[7] = 0;
      }
    }

    {
      int_T deviceIndex;
      int_T i;
      int_T slaveIsInSlaveAddressList;
      deviceIndex = g_deviceIndex;
      if (!xpcIsModelInit()) {
        if (deviceIndex != NO_ETHERCAT) {
          slaveIsInSlaveAddressList = 0;// default value
          for (i = 0; i < MAX_NUMBER_ECAT_SLAVES; i++) {
            if (1001 == g_ecatSlaveAddressList[deviceIndex][i])
              slaveIsInSlaveAddressList = 1;
          }

          if (slaveIsInSlaveAddressList == 0) {
            deviceIndex = NO_ETHERCAT;
          } else {
            registerAsyncSDODownload(34297580,1*(uint32_T)4,(uint32_T)
              deviceIndex);
            printf("SDO Download. Register device %d, slave addr: %d\n",
                   deviceIndex, 1001);
          }
        }

        gbyk_v4b_DW.BKINEtherCATAsyncSDODownload_IWORK_e[0] = deviceIndex;
        gbyk_v4b_DW.BKINEtherCATAsyncSDODownload_IWORK_e[7] = 0;
      }
    }

    {
      int_T deviceIndex;
      int_T i;
      int_T slaveIsInSlaveAddressList;
      deviceIndex = g_deviceIndex;
      if (!xpcIsModelInit()) {
        if (deviceIndex != NO_ETHERCAT) {
          slaveIsInSlaveAddressList = 0;// default value
          for (i = 0; i < MAX_NUMBER_ECAT_SLAVES; i++) {
            if (1001 == g_ecatSlaveAddressList[deviceIndex][i])
              slaveIsInSlaveAddressList = 1;
          }

          if (slaveIsInSlaveAddressList == 0) {
            deviceIndex = NO_ETHERCAT;
          } else {
            registerAsyncSDOUpload(35081310,1*(uint32_T)4,(uint32_T)deviceIndex);
            printf("SDO Upload. Register device %d, slave addr: %d\n",
                   deviceIndex, 1001 );
          }
        }

        gbyk_v4b_DW.BKINEtherCATAsyncSDOUpload1_IWORK_p[0] = deviceIndex;
        gbyk_v4b_DW.BKINEtherCATAsyncSDOUpload1_IWORK_p[7] = 0;
      }
    }

    {
      int_T deviceIndex;
      int_T i;
      int_T slaveIsInSlaveAddressList;
      deviceIndex = g_deviceIndex;
      if (!xpcIsModelInit()) {
        if (deviceIndex != NO_ETHERCAT) {
          slaveIsInSlaveAddressList = 0;// default value
          for (i = 0; i < MAX_NUMBER_ECAT_SLAVES; i++) {
            if (1003 == g_ecatSlaveAddressList[deviceIndex][i])
              slaveIsInSlaveAddressList = 1;
          }

          if (slaveIsInSlaveAddressList == 0) {
            deviceIndex = NO_ETHERCAT;
          } else {
            registerAsyncSDOUpload(342973381,1*(uint32_T)4,(uint32_T)deviceIndex);
            printf("SDO Upload. Register device %d, slave addr: %d\n",
                   deviceIndex, 1003 );
          }
        }

        gbyk_v4b_DW.BKINEtherCATAsyncSDOUpload_IWORK_n[0] = deviceIndex;
        gbyk_v4b_DW.BKINEtherCATAsyncSDOUpload_IWORK_n[7] = 0;
      }
    }

    {
      int_T deviceIndex;
      int_T i;
      int_T slaveIsInSlaveAddressList;
      deviceIndex = g_deviceIndex;
      if (!xpcIsModelInit()) {
        if (deviceIndex != NO_ETHERCAT) {
          slaveIsInSlaveAddressList = 0;// default value
          for (i = 0; i < MAX_NUMBER_ECAT_SLAVES; i++) {
            if (1003 == g_ecatSlaveAddressList[deviceIndex][i])
              slaveIsInSlaveAddressList = 1;
          }

          if (slaveIsInSlaveAddressList == 0) {
            deviceIndex = NO_ETHERCAT;
          } else {
            registerAsyncSDOUpload(342973393,1*(uint32_T)4,(uint32_T)deviceIndex);
            printf("SDO Upload. Register device %d, slave addr: %d\n",
                   deviceIndex, 1003 );
          }
        }

        gbyk_v4b_DW.BKINEtherCATAsyncSDOUpload_IWORK_i[0] = deviceIndex;
        gbyk_v4b_DW.BKINEtherCATAsyncSDOUpload_IWORK_i[7] = 0;
      }
    }

    {
      int_T deviceIndex;
      int_T i;
      int_T slaveIsInSlaveAddressList;
      deviceIndex = g_deviceIndex;
      if (!xpcIsModelInit()) {
        if (deviceIndex != NO_ETHERCAT) {
          slaveIsInSlaveAddressList = 0;// default value
          for (i = 0; i < MAX_NUMBER_ECAT_SLAVES; i++) {
            if (1003 == g_ecatSlaveAddressList[deviceIndex][i])
              slaveIsInSlaveAddressList = 1;
          }

          if (slaveIsInSlaveAddressList == 0) {
            deviceIndex = NO_ETHERCAT;
          } else {
            registerAsyncSDODownload(342973403,1*(uint32_T)4,(uint32_T)
              deviceIndex);
            printf("SDO Download. Register device %d, slave addr: %d\n",
                   deviceIndex, 1003);
          }
        }

        gbyk_v4b_DW.BKINEtherCATAsyncSDODownload_IWORK_o[0] = deviceIndex;
        gbyk_v4b_DW.BKINEtherCATAsyncSDODownload_IWORK_o[7] = 0;
      }
    }

    {
      int_T deviceIndex;
      int_T i;
      int_T slaveIsInSlaveAddressList;
      deviceIndex = g_deviceIndex;
      if (!xpcIsModelInit()) {
        if (deviceIndex != NO_ETHERCAT) {
          slaveIsInSlaveAddressList = 0;// default value
          for (i = 0; i < MAX_NUMBER_ECAT_SLAVES; i++) {
            if (1004 == g_ecatSlaveAddressList[deviceIndex][i])
              slaveIsInSlaveAddressList = 1;
          }

          if (slaveIsInSlaveAddressList == 0) {
            deviceIndex = NO_ETHERCAT;
          } else {
            registerAsyncSDOUpload(342973419,1*(uint32_T)4,(uint32_T)deviceIndex);
            printf("SDO Upload. Register device %d, slave addr: %d\n",
                   deviceIndex, 1004 );
          }
        }

        gbyk_v4b_DW.BKINEtherCATAsyncSDOUpload_IWORK_d[0] = deviceIndex;
        gbyk_v4b_DW.BKINEtherCATAsyncSDOUpload_IWORK_d[7] = 0;
      }
    }

    {
      int_T deviceIndex;
      int_T i;
      int_T slaveIsInSlaveAddressList;
      deviceIndex = g_deviceIndex;
      if (!xpcIsModelInit()) {
        if (deviceIndex != NO_ETHERCAT) {
          slaveIsInSlaveAddressList = 0;// default value
          for (i = 0; i < MAX_NUMBER_ECAT_SLAVES; i++) {
            if (1004 == g_ecatSlaveAddressList[deviceIndex][i])
              slaveIsInSlaveAddressList = 1;
          }

          if (slaveIsInSlaveAddressList == 0) {
            deviceIndex = NO_ETHERCAT;
          } else {
            registerAsyncSDOUpload(342973431,1*(uint32_T)4,(uint32_T)deviceIndex);
            printf("SDO Upload. Register device %d, slave addr: %d\n",
                   deviceIndex, 1004 );
          }
        }

        gbyk_v4b_DW.BKINEtherCATAsyncSDOUpload_IWORK_p[0] = deviceIndex;
        gbyk_v4b_DW.BKINEtherCATAsyncSDOUpload_IWORK_p[7] = 0;
      }
    }

    {
      int_T deviceIndex;
      int_T i;
      int_T slaveIsInSlaveAddressList;
      deviceIndex = g_deviceIndex;
      if (!xpcIsModelInit()) {
        if (deviceIndex != NO_ETHERCAT) {
          slaveIsInSlaveAddressList = 0;// default value
          for (i = 0; i < MAX_NUMBER_ECAT_SLAVES; i++) {
            if (1004 == g_ecatSlaveAddressList[deviceIndex][i])
              slaveIsInSlaveAddressList = 1;
          }

          if (slaveIsInSlaveAddressList == 0) {
            deviceIndex = NO_ETHERCAT;
          } else {
            registerAsyncSDODownload(342973441,1*(uint32_T)4,(uint32_T)
              deviceIndex);
            printf("SDO Download. Register device %d, slave addr: %d\n",
                   deviceIndex, 1004);
          }
        }

        gbyk_v4b_DW.BKINEtherCATAsyncSDODownload_IWORK_a[0] = deviceIndex;
        gbyk_v4b_DW.BKINEtherCATAsyncSDODownload_IWORK_a[7] = 0;
      }
    }

    {
      int_T deviceIndex;
      int_T i;
      int_T slaveIsInSlaveAddressList;
      deviceIndex = g_deviceIndex;
      if (!xpcIsModelInit()) {
        if (deviceIndex != NO_ETHERCAT) {
          slaveIsInSlaveAddressList = 0;// default value
          for (i = 0; i < MAX_NUMBER_ECAT_SLAVES; i++) {
            if (1003 == g_ecatSlaveAddressList[deviceIndex][i])
              slaveIsInSlaveAddressList = 1;
          }

          if (slaveIsInSlaveAddressList == 0) {
            deviceIndex = NO_ETHERCAT;
          } else {
            registerAsyncSDOUpload(35471299,1*(uint32_T)4,(uint32_T)deviceIndex);
            printf("SDO Upload. Register device %d, slave addr: %d\n",
                   deviceIndex, 1003 );
          }
        }

        gbyk_v4b_DW.BKINEtherCATAsyncSDOUpload1_IWORK_h[0] = deviceIndex;
        gbyk_v4b_DW.BKINEtherCATAsyncSDOUpload1_IWORK_h[7] = 0;
      }
    }

    {
      int_T deviceIndex;
      int_T i;
      int_T slaveIsInSlaveAddressList;
      deviceIndex = g_deviceIndex;
      if (!xpcIsModelInit()) {
        if (deviceIndex != NO_ETHERCAT) {
          slaveIsInSlaveAddressList = 0;// default value
          for (i = 0; i < MAX_NUMBER_ECAT_SLAVES; i++) {
            if (1003 == g_ecatSlaveAddressList[deviceIndex][i])
              slaveIsInSlaveAddressList = 1;
          }

          if (slaveIsInSlaveAddressList == 0) {
            deviceIndex = NO_ETHERCAT;
          } else {
            registerAsyncSDODownload(342973537,1*(uint32_T)4,(uint32_T)
              deviceIndex);
            printf("SDO Download. Register device %d, slave addr: %d\n",
                   deviceIndex, 1003);
          }
        }

        gbyk_v4b_DW.BKINEtherCATAsyncSDODownload_IWORK[0] = deviceIndex;
        gbyk_v4b_DW.BKINEtherCATAsyncSDODownload_IWORK[7] = 0;
      }
    }

    {
      int_T deviceIndex;
      int_T i;
      int_T slaveIsInSlaveAddressList;
      deviceIndex = g_deviceIndex;
      if (!xpcIsModelInit()) {
        if (deviceIndex != NO_ETHERCAT) {
          slaveIsInSlaveAddressList = 0;// default value
          for (i = 0; i < MAX_NUMBER_ECAT_SLAVES; i++) {
            if (1003 == g_ecatSlaveAddressList[deviceIndex][i])
              slaveIsInSlaveAddressList = 1;
          }

          if (slaveIsInSlaveAddressList == 0) {
            deviceIndex = NO_ETHERCAT;
          } else {
            registerAsyncSDOUpload(35091299,1*(uint32_T)4,(uint32_T)deviceIndex);
            printf("SDO Upload. Register device %d, slave addr: %d\n",
                   deviceIndex, 1003 );
          }
        }

        gbyk_v4b_DW.BKINEtherCATAsyncSDOUpload1_IWORK[0] = deviceIndex;
        gbyk_v4b_DW.BKINEtherCATAsyncSDOUpload1_IWORK[7] = 0;
      }
    }

    {
      if (1 == g_firstInitBlockToRunPlusOne - 1 ) {
        switch (gbyk_v4b_P.activation_Value[0]) {
         case MC_TYPE_SIMULATION:
          {
            printf("Simulation mode requested and enabled.\n");
            break;
          }

         case MC_TYPE_PMAC:
          {
            if (gbyk_v4b_B.BKINEtherCATinit1_o3 == MC_TYPE_PMAC)
              printf("PMAC mode requested and enabled");
            else
              printf("PMAC mode requested, but not enabled.");
            break;
          }

         case MC_TYPE_ETHERCAT:
          {
            if (g_deviceIndex == NO_ETHERCAT && gbyk_v4b_P.activation_Value[1] <
                MAX_NUMBER_ECAT_NETWORK_DEVICES)
              printf("The EtherCAT Network device ( = %d) requested is not specified in the code.\n",
                     gbyk_v4b_P.activation_Value[1]);
            break;
          }

         default:
          printf("Unknown Motion Control type ( = %d) requested.\n",
                 gbyk_v4b_P.activation_Value[0]);
        }
      }
    }

    {
      if (0 == g_firstInitBlockToRunPlusOne - 1 ) {
        switch (gbyk_v4b_P.activation_Value[0]) {
         case MC_TYPE_SIMULATION:
          {
            printf("Simulation mode requested and enabled.\n");
            break;
          }

         case MC_TYPE_PMAC:
          {
            if (gbyk_v4b_B.BKINEtherCATinit_o3 == MC_TYPE_PMAC)
              printf("PMAC mode requested and enabled");
            else
              printf("PMAC mode requested, but not enabled.");
            break;
          }

         case MC_TYPE_ETHERCAT:
          {
            if (g_deviceIndex == NO_ETHERCAT && gbyk_v4b_P.activation_Value[1] <
                MAX_NUMBER_ECAT_NETWORK_DEVICES)
              printf("The EtherCAT Network device ( = %d) requested is not specified in the code.\n",
                     gbyk_v4b_P.activation_Value[1]);
            break;
          }

         default:
          printf("Unknown Motion Control type ( = %d) requested.\n",
                 gbyk_v4b_P.activation_Value[0]);
        }
      }
    }

    {
      int_T deviceIndex;
      int_T i;
      int_T slaveIsInSlaveAddressList;
      deviceIndex = g_deviceIndex;
      if (!xpcIsModelInit()) {
        if (deviceIndex != NO_ETHERCAT) {
          slaveIsInSlaveAddressList = 0;// default value
          for (i = 0; i < MAX_NUMBER_ECAT_SLAVES; i++) {
            if (1001 == g_ecatSlaveAddressList[deviceIndex][i])
              slaveIsInSlaveAddressList = 1;
          }

          if (slaveIsInSlaveAddressList == 0) {
            deviceIndex = NO_ETHERCAT;
          } else {
            registerAsyncSDODownload(342971113,1*(uint32_T)4,(uint32_T)
              deviceIndex);
            printf("SDO Download. Register device %d, slave addr: %d\n",
                   deviceIndex, 1001);
          }
        }

        gbyk_v4b_DW.BKINEtherCATAsyncSDODownload_IWORK_j[0] = deviceIndex;
        gbyk_v4b_DW.BKINEtherCATAsyncSDODownload_IWORK_j[7] = 0;
      }
    }

    {
      int_T deviceIndex;
      int_T i;
      int_T slaveIsInSlaveAddressList;
      deviceIndex = g_deviceIndex;
      if (!xpcIsModelInit()) {
        if (deviceIndex != NO_ETHERCAT) {
          slaveIsInSlaveAddressList = 0;// default value
          for (i = 0; i < MAX_NUMBER_ECAT_SLAVES; i++) {
            if (1001 == g_ecatSlaveAddressList[deviceIndex][i])
              slaveIsInSlaveAddressList = 1;
          }

          if (slaveIsInSlaveAddressList == 0) {
            deviceIndex = NO_ETHERCAT;
          } else {
            registerAsyncSDOUpload(342971114,1*(uint32_T)4,(uint32_T)deviceIndex);
            printf("SDO Upload. Register device %d, slave addr: %d\n",
                   deviceIndex, 1001 );
          }
        }

        gbyk_v4b_DW.BKINEtherCATAsyncSDOUpload_IWORK_h[0] = deviceIndex;
        gbyk_v4b_DW.BKINEtherCATAsyncSDOUpload_IWORK_h[7] = 0;
      }
    }

    {
      int_T deviceIndex;
      int_T i;
      int_T slaveIsInSlaveAddressList;
      deviceIndex = g_deviceIndex;
      if (!xpcIsModelInit()) {
        if (deviceIndex != NO_ETHERCAT) {
          slaveIsInSlaveAddressList = 0;// default value
          for (i = 0; i < MAX_NUMBER_ECAT_SLAVES; i++) {
            if (1002 == g_ecatSlaveAddressList[deviceIndex][i])
              slaveIsInSlaveAddressList = 1;
          }

          if (slaveIsInSlaveAddressList == 0) {
            deviceIndex = NO_ETHERCAT;
          } else {
            registerAsyncSDODownload(342974267,1*(uint32_T)4,(uint32_T)
              deviceIndex);
            printf("SDO Download. Register device %d, slave addr: %d\n",
                   deviceIndex, 1002);
          }
        }

        gbyk_v4b_DW.BKINEtherCATAsyncSDODownload_IWORK_a0[0] = deviceIndex;
        gbyk_v4b_DW.BKINEtherCATAsyncSDODownload_IWORK_a0[7] = 0;
      }
    }

    {
      int_T deviceIndex;
      int_T i;
      int_T slaveIsInSlaveAddressList;
      deviceIndex = g_deviceIndex;
      if (!xpcIsModelInit()) {
        if (deviceIndex != NO_ETHERCAT) {
          slaveIsInSlaveAddressList = 0;// default value
          for (i = 0; i < MAX_NUMBER_ECAT_SLAVES; i++) {
            if (1002 == g_ecatSlaveAddressList[deviceIndex][i])
              slaveIsInSlaveAddressList = 1;
          }

          if (slaveIsInSlaveAddressList == 0) {
            deviceIndex = NO_ETHERCAT;
          } else {
            registerAsyncSDOUpload(342974268,1*(uint32_T)4,(uint32_T)deviceIndex);
            printf("SDO Upload. Register device %d, slave addr: %d\n",
                   deviceIndex, 1002 );
          }
        }

        gbyk_v4b_DW.BKINEtherCATAsyncSDOUpload_IWORK_f[0] = deviceIndex;
        gbyk_v4b_DW.BKINEtherCATAsyncSDOUpload_IWORK_f[7] = 0;
      }
    }

    {
      int_T deviceIndex;
      int_T i;
      int_T slaveIsInSlaveAddressList;
      deviceIndex = g_deviceIndex;
      if (!xpcIsModelInit()) {
        if (deviceIndex != NO_ETHERCAT) {
          slaveIsInSlaveAddressList = 0;// default value
          for (i = 0; i < MAX_NUMBER_ECAT_SLAVES; i++) {
            if (1003 == g_ecatSlaveAddressList[deviceIndex][i])
              slaveIsInSlaveAddressList = 1;
          }

          if (slaveIsInSlaveAddressList == 0) {
            deviceIndex = NO_ETHERCAT;
          } else {
            registerAsyncSDODownload(342974277,1*(uint32_T)4,(uint32_T)
              deviceIndex);
            printf("SDO Download. Register device %d, slave addr: %d\n",
                   deviceIndex, 1003);
          }
        }

        gbyk_v4b_DW.BKINEtherCATAsyncSDODownload_IWORK_m[0] = deviceIndex;
        gbyk_v4b_DW.BKINEtherCATAsyncSDODownload_IWORK_m[7] = 0;
      }
    }

    {
      int_T deviceIndex;
      int_T i;
      int_T slaveIsInSlaveAddressList;
      deviceIndex = g_deviceIndex;
      if (!xpcIsModelInit()) {
        if (deviceIndex != NO_ETHERCAT) {
          slaveIsInSlaveAddressList = 0;// default value
          for (i = 0; i < MAX_NUMBER_ECAT_SLAVES; i++) {
            if (1003 == g_ecatSlaveAddressList[deviceIndex][i])
              slaveIsInSlaveAddressList = 1;
          }

          if (slaveIsInSlaveAddressList == 0) {
            deviceIndex = NO_ETHERCAT;
          } else {
            registerAsyncSDOUpload(342974278,1*(uint32_T)4,(uint32_T)deviceIndex);
            printf("SDO Upload. Register device %d, slave addr: %d\n",
                   deviceIndex, 1003 );
          }
        }

        gbyk_v4b_DW.BKINEtherCATAsyncSDOUpload_IWORK_o[0] = deviceIndex;
        gbyk_v4b_DW.BKINEtherCATAsyncSDOUpload_IWORK_o[7] = 0;
      }
    }

    {
      int_T deviceIndex;
      int_T i;
      int_T slaveIsInSlaveAddressList;
      deviceIndex = g_deviceIndex;
      if (!xpcIsModelInit()) {
        if (deviceIndex != NO_ETHERCAT) {
          slaveIsInSlaveAddressList = 0;// default value
          for (i = 0; i < MAX_NUMBER_ECAT_SLAVES; i++) {
            if (1004 == g_ecatSlaveAddressList[deviceIndex][i])
              slaveIsInSlaveAddressList = 1;
          }

          if (slaveIsInSlaveAddressList == 0) {
            deviceIndex = NO_ETHERCAT;
          } else {
            registerAsyncSDODownload(342974287,1*(uint32_T)4,(uint32_T)
              deviceIndex);
            printf("SDO Download. Register device %d, slave addr: %d\n",
                   deviceIndex, 1004);
          }
        }

        gbyk_v4b_DW.BKINEtherCATAsyncSDODownload_IWORK_k[0] = deviceIndex;
        gbyk_v4b_DW.BKINEtherCATAsyncSDODownload_IWORK_k[7] = 0;
      }
    }

    {
      int_T deviceIndex;
      int_T i;
      int_T slaveIsInSlaveAddressList;
      deviceIndex = g_deviceIndex;
      if (!xpcIsModelInit()) {
        if (deviceIndex != NO_ETHERCAT) {
          slaveIsInSlaveAddressList = 0;// default value
          for (i = 0; i < MAX_NUMBER_ECAT_SLAVES; i++) {
            if (1004 == g_ecatSlaveAddressList[deviceIndex][i])
              slaveIsInSlaveAddressList = 1;
          }

          if (slaveIsInSlaveAddressList == 0) {
            deviceIndex = NO_ETHERCAT;
          } else {
            registerAsyncSDOUpload(342974288,1*(uint32_T)4,(uint32_T)deviceIndex);
            printf("SDO Upload. Register device %d, slave addr: %d\n",
                   deviceIndex, 1004 );
          }
        }

        gbyk_v4b_DW.BKINEtherCATAsyncSDOUpload_IWORK[0] = deviceIndex;
        gbyk_v4b_DW.BKINEtherCATAsyncSDOUpload_IWORK[7] = 0;
      }
    }
  }

  gbyk_v4b_PrevZCX.SendControlMachine_Trig_ZCE[0] = UNINITIALIZED_ZCSIG;
  gbyk_v4b_PrevZCX.SendControlMachine_Trig_ZCE[1] = UNINITIALIZED_ZCSIG;
  gbyk_v4b_PrevZCX.SendControlMachine_Trig_ZCE[2] = UNINITIALIZED_ZCSIG;
  gbyk_v4b_PrevZCX.TaskExecutionControlMachine_Trig_ZCE[0] = UNINITIALIZED_ZCSIG;
  gbyk_v4b_PrevZCX.TaskExecutionControlMachine_Trig_ZCE[1] = UNINITIALIZED_ZCSIG;
  gbyk_v4b_PrevZCX.Trial_Control_Trig_ZCE[0] = UNINITIALIZED_ZCSIG;
  gbyk_v4b_PrevZCX.Trial_Control_Trig_ZCE[1] = UNINITIALIZED_ZCSIG;
  gbyk_v4b_PrevZCX.Trial_Control_Trig_ZCE[2] = UNINITIALIZED_ZCSIG;

  {
    int32_T i;

    /* Machine initializer */
    gbyk_v4b_DW.data = 0.0;

    /* InitializeConditions for MATLAB Function: '<S268>/Embedded MATLAB Function' */
    gbyk_v4b_DW.u = 0.0;
    gbyk_v4b_DW.v = 0.0;

    /* InitializeConditions for Atomic SubSystem: '<S7>/Task Execution Control Subsystem' */
    gbyk_v4b_TaskExecutionControlSubsystem_Init();

    /* End of InitializeConditions for SubSystem: '<S7>/Task Execution Control Subsystem' */

    /* InitializeConditions for MATLAB Function: '<S268>/Hold_to_1Khz' */
    /* this does not need to be a vector 8 elements long. Simulink just */
    /* doesn't like variable sized arrays here. So I make it twice as long as */
    /* required in case we decide to run faster some day. */
    for (i = 0; i < 8; i++) {
      gbyk_v4b_DW.held_value[i] = 0.0;
    }

    /* End of InitializeConditions for MATLAB Function: '<S268>/Hold_to_1Khz' */

    /* InitializeConditions for UnitDelay: '<S44>/Output' */
    gbyk_v4b_DW.Output_DSTATE = gbyk_v4b_P.Output_InitialCondition_a;

    /* InitializeConditions for Atomic SubSystem: '<S4>/Receive_Gaze' */
    gbyk_v4b_Receive_Gaze_Init();

    /* End of InitializeConditions for SubSystem: '<S4>/Receive_Gaze' */

    /* InitializeConditions for Memory: '<S4>/Memory' */
    gbyk_v4b_DW.Memory_PreviousInput[0] = gbyk_v4b_P.Memory_X0_gv;
    gbyk_v4b_DW.Memory_PreviousInput[1] = gbyk_v4b_P.Memory_X0_gv;
    gbyk_v4b_DW.Memory_PreviousInput[2] = gbyk_v4b_P.Memory_X0_gv;
    gbyk_v4b_DW.Memory_PreviousInput[3] = gbyk_v4b_P.Memory_X0_gv;

    /* InitializeConditions for Memory: '<S15>/Memory' */
    gbyk_v4b_DW.Memory_PreviousInput_c = gbyk_v4b_P.Memory_X0_c;

    /* InitializeConditions for Atomic SubSystem: '<S4>/Poll KINARM' */
    gbyk_v4b_PollKINARM_Init();

    /* End of InitializeConditions for SubSystem: '<S4>/Poll KINARM' */

    /* InitializeConditions for Chart: '<Root>/Trial_Control' */
    gbyk_v4b_DW.is_MainTrial = gbyk_v4b_IN_NO_ACTIVE_CHILD_o;
    gbyk_v4b_DW.temporalCounter_i1 = 0U;
    gbyk_v4b_DW.is_active_c1_gbyk_v4b = 0U;
    gbyk_v4b_DW.is_c1_gbyk_v4b = gbyk_v4b_IN_NO_ACTIVE_CHILD_o;
    gbyk_v4b_DW.tickCount = 0.0;
    gbyk_v4b_DW.tgtdist = 0.0;
    gbyk_v4b_DW.rwdTgts[0] = 0.0;
    gbyk_v4b_DW.rwdTgts[1] = 0.0;
    gbyk_v4b_DW.pTgts[0] = 0.0;
    gbyk_v4b_DW.pTgts[1] = 0.0;
    gbyk_v4b_DW.setup_trial_flag = false;
    gbyk_v4b_DW.disttrigy = false;
    gbyk_v4b_DW.tgt2trig = 0.0;
    gbyk_v4b_DW.corrTgt = 0.0;
    gbyk_v4b_DW.incorrTgt = 0.0;
    gbyk_v4b_DW.boxtrig = 0.0;
    gbyk_v4b_B.logging_enable[0] = 0.0;
    gbyk_v4b_B.logging_enable[1] = 0.0;
    gbyk_v4b_B.event_code = 0U;
    gbyk_v4b_B.VectorConcatenate1[0] = false;
    gbyk_v4b_B.VectorConcatenate1[1] = false;
    gbyk_v4b_B.VectorConcatenate1[2] = false;
    gbyk_v4b_B.VectorConcatenate1[3] = false;
    gbyk_v4b_B.targetA_row = 0.0;
    gbyk_v4b_B.targetA_state = 0.0;
    gbyk_v4b_B.targetB_row[0] = 0.0;
    gbyk_v4b_B.targetB_row[1] = 0.0;
    gbyk_v4b_B.targetB_state[0] = 0.0;
    gbyk_v4b_B.targetB_state[1] = 0.0;
    gbyk_v4b_B.offeredRewards[0] = 0.0;
    gbyk_v4b_B.offeredRewards[1] = 0.0;
    gbyk_v4b_B.score = 0.0;
    gbyk_v4b_B.doreward = 0.0;
    gbyk_v4b_B.feedback_text = 0;
    gbyk_v4b_B.reward = 0.0;
    gbyk_v4b_B.instruct_num = 0.0;
    gbyk_v4b_B.tone = 0.0;
    gbyk_v4b_B.repeat_trial_flag = 0.0;
    for (i = 0; i < 120; i++) {
      gbyk_v4b_B.trialIterations[i] = 0.0;
    }

    gbyk_v4b_B.targetC_row[0] = 0.0;
    gbyk_v4b_B.targetC_row[1] = 0.0;
    gbyk_v4b_B.targetC_state[0] = 0.0;
    gbyk_v4b_B.targetC_state[1] = 0.0;
    gbyk_v4b_B.offeredRewardsC[0] = 0.0;
    gbyk_v4b_B.offeredRewardsC[1] = 0.0;
    gbyk_v4b_B.boxRow = 0.0;
    gbyk_v4b_B.boxState = 0.0;
    gbyk_v4b_DW.e_Trial_EndEventCounter = 0U;
    gbyk_v4b_B.e_Trial_End = false;

    /* End of InitializeConditions for Chart: '<Root>/Trial_Control' */

    /* InitializeConditions for Atomic SubSystem: '<S15>/PVC_core' */
    gbyk_v4b_PVC_core_Init();

    /* End of InitializeConditions for SubSystem: '<S15>/PVC_core' */

    /* InitializeConditions for MATLAB Function: '<S15>/MATLAB Function' */
    gbyk_v4b_DW.last_valid_frame_ack = 0.0;
    gbyk_v4b_DW.last_perm_frame_ack = 0.0;

    /* InitializeConditions for RateTransition: '<S28>/TmpRTBAtNumber of Event CodesOutport1' */
    gbyk_v4b_DW.TmpRTBAtNumberofEventCodesOutport1_Buffer0 =
      gbyk_v4b_P.TmpRTBAtNumberofEventCodesOutport1_X0;

    /* InitializeConditions for RateTransition: '<S27>/Rate Transition2' */
    gbyk_v4b_DW.RateTransition2_Buffer0 = gbyk_v4b_P.RateTransition2_X0_o;

    /* InitializeConditions for Atomic SubSystem: '<S4>/Network Transfer Subsystem' */
    gbyk_v4b_NetworkTransferSubsystem_Init();

    /* End of InitializeConditions for SubSystem: '<S4>/Network Transfer Subsystem' */

    /* InitializeConditions for Memory: '<S4>/Memory1' */
    gbyk_v4b_DW.Memory1_PreviousInput = gbyk_v4b_P.Memory1_X0_b;

    /* InitializeConditions for Memory: '<S4>/Memory2' */
    gbyk_v4b_DW.Memory2_1_PreviousInput = gbyk_v4b_P.Memory2_1_X0;

    /* InitializeConditions for Memory: '<S4>/Memory2' */
    gbyk_v4b_DW.Memory2_2_PreviousInput = gbyk_v4b_P.Memory2_2_X0;

    /* InitializeConditions for Memory: '<S4>/Memory2' */
    gbyk_v4b_DW.Memory2_3_PreviousInput = gbyk_v4b_P.Memory2_3_X0;

    /* InitializeConditions for Memory: '<S4>/Memory2' */
    gbyk_v4b_DW.Memory2_4_PreviousInput = gbyk_v4b_P.Memory2_4_X0;

    /* InitializeConditions for Memory: '<S4>/Memory2' */
    gbyk_v4b_DW.Memory2_5_PreviousInput = gbyk_v4b_P.Memory2_5_X0;

    /* InitializeConditions for Memory: '<S4>/Memory2' */
    gbyk_v4b_DW.Memory2_9_PreviousInput = gbyk_v4b_P.Memory2_9_X0;

    /* InitializeConditions for Memory: '<S4>/Memory2' */
    gbyk_v4b_DW.Memory2_18_PreviousInput = gbyk_v4b_P.Memory2_18_X0;

    /* InitializeConditions for Memory: '<S4>/Memory2' */
    gbyk_v4b_DW.Memory2_19_PreviousInput = gbyk_v4b_P.Memory2_19_X0;

    /* InitializeConditions for Memory: '<S4>/Memory2' */
    gbyk_v4b_DW.Memory2_20_PreviousInput = gbyk_v4b_P.Memory2_20_X0;

    /* InitializeConditions for Memory: '<S4>/Memory2' */
    gbyk_v4b_DW.Memory2_21_PreviousInput = gbyk_v4b_P.Memory2_21_X0;

    /* InitializeConditions for Memory: '<S4>/Memory2' */
    gbyk_v4b_DW.Memory2_22_PreviousInput = gbyk_v4b_P.Memory2_22_X0;

    /* InitializeConditions for Memory: '<S4>/Memory2' */
    gbyk_v4b_DW.Memory2_26_PreviousInput = gbyk_v4b_P.Memory2_26_X0;

    /* InitializeConditions for Memory: '<S4>/Memory2' */
    gbyk_v4b_DW.Memory2_10_PreviousInput = gbyk_v4b_P.Memory2_10_X0;

    /* InitializeConditions for Memory: '<S4>/Memory2' */
    gbyk_v4b_DW.Memory2_11_PreviousInput = gbyk_v4b_P.Memory2_11_X0;

    /* InitializeConditions for Memory: '<S4>/Memory2' */
    gbyk_v4b_DW.Memory2_12_PreviousInput = gbyk_v4b_P.Memory2_12_X0;

    /* InitializeConditions for Memory: '<S4>/Memory2' */
    gbyk_v4b_DW.Memory2_13_PreviousInput = gbyk_v4b_P.Memory2_13_X0;

    /* InitializeConditions for Memory: '<S4>/Memory2' */
    gbyk_v4b_DW.Memory2_14_PreviousInput = gbyk_v4b_P.Memory2_14_X0;

    /* InitializeConditions for Memory: '<S4>/Memory2' */
    gbyk_v4b_DW.Memory2_15_PreviousInput = gbyk_v4b_P.Memory2_15_X0;

    /* InitializeConditions for Memory: '<S4>/Memory2' */
    gbyk_v4b_DW.Memory2_16_PreviousInput = gbyk_v4b_P.Memory2_16_X0;

    /* InitializeConditions for Memory: '<S4>/Memory2' */
    gbyk_v4b_DW.Memory2_17_PreviousInput = gbyk_v4b_P.Memory2_17_X0;

    /* InitializeConditions for Memory: '<S4>/Memory2' */
    gbyk_v4b_DW.Memory2_23_PreviousInput = gbyk_v4b_P.Memory2_23_X0;

    /* InitializeConditions for Memory: '<S4>/Memory2' */
    gbyk_v4b_DW.Memory2_24_PreviousInput = gbyk_v4b_P.Memory2_24_X0;

    /* InitializeConditions for Memory: '<S4>/Memory2' */
    gbyk_v4b_DW.Memory2_25_PreviousInput = gbyk_v4b_P.Memory2_25_X0;

    /* InitializeConditions for Memory: '<S4>/Memory2' */
    gbyk_v4b_DW.Memory2_27_PreviousInput = gbyk_v4b_P.Memory2_27_X0;

    /* InitializeConditions for Memory: '<S4>/Memory2' */
    gbyk_v4b_DW.Memory2_28_PreviousInput = gbyk_v4b_P.Memory2_28_X0;

    /* InitializeConditions for Memory: '<S4>/Memory2' */
    gbyk_v4b_DW.Memory2_29_PreviousInput = gbyk_v4b_P.Memory2_29_X0;

    /* InitializeConditions for Memory: '<S4>/Memory2' */
    gbyk_v4b_DW.Memory2_30_PreviousInput = gbyk_v4b_P.Memory2_30_X0;

    /* InitializeConditions for Memory: '<S4>/Memory2' */
    gbyk_v4b_DW.Memory2_31_PreviousInput = gbyk_v4b_P.Memory2_31_X0;

    /* InitializeConditions for Memory: '<S4>/Memory2' */
    gbyk_v4b_DW.Memory2_32_PreviousInput = gbyk_v4b_P.Memory2_32_X0;

    /* InitializeConditions for Memory: '<S4>/Memory2' */
    gbyk_v4b_DW.Memory2_33_PreviousInput = gbyk_v4b_P.Memory2_33_X0;

    /* InitializeConditions for Memory: '<S4>/Memory2' */
    gbyk_v4b_DW.Memory2_34_PreviousInput = gbyk_v4b_P.Memory2_34_X0;

    /* InitializeConditions for Memory: '<S4>/Memory2' */
    gbyk_v4b_DW.Memory2_6_PreviousInput = gbyk_v4b_P.Memory2_6_X0;

    /* InitializeConditions for Memory: '<S4>/Memory2' */
    gbyk_v4b_DW.Memory2_7_PreviousInput = gbyk_v4b_P.Memory2_7_X0;

    /* InitializeConditions for Memory: '<S4>/Memory2' */
    gbyk_v4b_DW.Memory2_8_PreviousInput = gbyk_v4b_P.Memory2_8_X0;
  }
}

/* Model terminate function */
static void gbyk_v4b_terminate(void)
{
  /* Level2 S-Function Block: '<S7>/ICH7' (ich10) */
  {
    SimStruct *rts = gbyk_v4b_M->childSfunctions[40];
    sfcnTerminate(rts);
  }

  /* Level2 S-Function Block: '<S268>/Run Command Receive' (xpcudpbytereceive) */
  {
    SimStruct *rts = gbyk_v4b_M->childSfunctions[41];
    sfcnTerminate(rts);
  }

  /* Terminate for Atomic SubSystem: '<S4>/Receive_Gaze' */
  gbyk_v4b_Receive_Gaze_Term();

  /* End of Terminate for SubSystem: '<S4>/Receive_Gaze' */

  /* Terminate for Atomic SubSystem: '<S4>/Poll KINARM' */
  gbyk_v4b_PollKINARM_Term();

  /* End of Terminate for SubSystem: '<S4>/Poll KINARM' */

  /* Level2 S-Function Block: '<S15>/Receive' (xpcudpbytereceive) */
  {
    SimStruct *rts = gbyk_v4b_M->childSfunctions[42];
    sfcnTerminate(rts);
  }

  /* Terminate for Atomic SubSystem: '<S4>/Poll Force Plates' */
  gbyk_v4b_PollForcePlates_Term();

  /* End of Terminate for SubSystem: '<S4>/Poll Force Plates' */

  /* Terminate for Atomic SubSystem: '<S4>/Network Transfer Subsystem' */
  gbyk_v4b_NetworkTransferSubsystem_Term();

  /* End of Terminate for SubSystem: '<S4>/Network Transfer Subsystem' */

  /* Terminate for Atomic SubSystem: '<S4>/apply loads' */
  gbyk_v4b_applyloads_Term();

  /* End of Terminate for SubSystem: '<S4>/apply loads' */

  /* Terminate for Atomic SubSystem: '<S4>/Keep alive' */
  gbyk_v4b_Keepalive_Term();

  /* End of Terminate for SubSystem: '<S4>/Keep alive' */

  /* Level2 S-Function Block: '<S15>/Send' (xpcudpbytesend) */
  {
    SimStruct *rts = gbyk_v4b_M->childSfunctions[43];
    sfcnTerminate(rts);
  }

  /* user code (Terminate function Trailer) */

  /*------------ S-Function Block: <S64>/BKIN EtherCATinit1 Process Shutdown Network ------------*/
  {
    int_T status;
    if (!xpcIsModelInit()) {
      status = xpcEtherCATstop(1, 1000 /* 1 second timeout */
        );
    }
  }

  /*------------ S-Function Block: <S64>/BKIN EtherCATinit Process Shutdown Network ------------*/
  {
    int_T status;
    if (!xpcIsModelInit()) {
      status = xpcEtherCATstop(0, 1000 /* 1 second timeout */
        );
    }
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  if (tid == 1)
    tid = 0;
  gbyk_v4b_output(tid);
}

void MdlUpdate(int_T tid)
{
  if (tid == 1)
    tid = 0;
  gbyk_v4b_update(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  gbyk_v4b_initialize();
}

void MdlTerminate(void)
{
  gbyk_v4b_terminate();
}

/* Registration function */
RT_MODEL_gbyk_v4b_T *gbyk_v4b(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)gbyk_v4b_M, 0,
                sizeof(RT_MODEL_gbyk_v4b_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&gbyk_v4b_M->solverInfo,
                          &gbyk_v4b_M->Timing.simTimeStep);
    rtsiSetTPtr(&gbyk_v4b_M->solverInfo, &rtmGetTPtr(gbyk_v4b_M));
    rtsiSetStepSizePtr(&gbyk_v4b_M->solverInfo, &gbyk_v4b_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&gbyk_v4b_M->solverInfo, (&rtmGetErrorStatus
      (gbyk_v4b_M)));
    rtsiSetRTModelPtr(&gbyk_v4b_M->solverInfo, gbyk_v4b_M);
  }

  rtsiSetSimTimeStep(&gbyk_v4b_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&gbyk_v4b_M->solverInfo,"FixedStepDiscrete");
  gbyk_v4b_M->solverInfoPtr = (&gbyk_v4b_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = gbyk_v4b_M->Timing.sampleTimeTaskIDArray;
    int_T i;
    for (i = 0; i < 6; i++) {
      mdlTsMap[i] = i;
    }

    gbyk_v4b_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    gbyk_v4b_M->Timing.sampleTimes = (&gbyk_v4b_M->Timing.sampleTimesArray[0]);
    gbyk_v4b_M->Timing.offsetTimes = (&gbyk_v4b_M->Timing.offsetTimesArray[0]);

    /* task periods */
    gbyk_v4b_M->Timing.sampleTimes[0] = (0.0);
    gbyk_v4b_M->Timing.sampleTimes[1] = (0.00025);
    gbyk_v4b_M->Timing.sampleTimes[2] = (0.0005);
    gbyk_v4b_M->Timing.sampleTimes[3] = (0.001);
    gbyk_v4b_M->Timing.sampleTimes[4] = (0.002);
    gbyk_v4b_M->Timing.sampleTimes[5] = (0.1);

    /* task offsets */
    gbyk_v4b_M->Timing.offsetTimes[0] = (0.0);
    gbyk_v4b_M->Timing.offsetTimes[1] = (0.0);
    gbyk_v4b_M->Timing.offsetTimes[2] = (0.0);
    gbyk_v4b_M->Timing.offsetTimes[3] = (0.0);
    gbyk_v4b_M->Timing.offsetTimes[4] = (0.0);
    gbyk_v4b_M->Timing.offsetTimes[5] = (0.0);
  }

  rtmSetTPtr(gbyk_v4b_M, &gbyk_v4b_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = gbyk_v4b_M->Timing.sampleHitArray;
    int_T *mdlPerTaskSampleHits = gbyk_v4b_M->Timing.perTaskSampleHitsArray;
    gbyk_v4b_M->Timing.perTaskSampleHits = (&mdlPerTaskSampleHits[0]);
    mdlSampleHits[0] = 1;
    gbyk_v4b_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(gbyk_v4b_M, -1);
  gbyk_v4b_M->Timing.stepSize0 = 0.00025;
  gbyk_v4b_M->Timing.stepSize1 = 0.00025;
  gbyk_v4b_M->Timing.stepSize2 = 0.0005;
  gbyk_v4b_M->Timing.stepSize3 = 0.001;
  gbyk_v4b_M->Timing.stepSize4 = 0.002;
  gbyk_v4b_M->Timing.stepSize5 = 0.1;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    gbyk_v4b_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(gbyk_v4b_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(gbyk_v4b_M->rtwLogInfo, (NULL));
    rtliSetLogT(gbyk_v4b_M->rtwLogInfo, "");
    rtliSetLogX(gbyk_v4b_M->rtwLogInfo, "");
    rtliSetLogXFinal(gbyk_v4b_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(gbyk_v4b_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(gbyk_v4b_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(gbyk_v4b_M->rtwLogInfo, 0);
    rtliSetLogDecimation(gbyk_v4b_M->rtwLogInfo, 1);
    rtliSetLogY(gbyk_v4b_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(gbyk_v4b_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(gbyk_v4b_M->rtwLogInfo, (NULL));
  }

  gbyk_v4b_M->solverInfoPtr = (&gbyk_v4b_M->solverInfo);
  gbyk_v4b_M->Timing.stepSize = (0.00025);
  rtsiSetFixedStepSize(&gbyk_v4b_M->solverInfo, 0.00025);
  rtsiSetSolverMode(&gbyk_v4b_M->solverInfo, SOLVER_MODE_MULTITASKING);

  /* block I/O */
  gbyk_v4b_M->ModelData.blockIO = ((void *) &gbyk_v4b_B);
  (void) memset(((void *) &gbyk_v4b_B), 0,
                sizeof(B_gbyk_v4b_T));

  {
    int32_T i;
    for (i = 0; i < 25000; i++) {
      gbyk_v4b_B.BlockDefinitions[i] = 0.0;
    }

    for (i = 0; i < 2000; i++) {
      gbyk_v4b_B.BlockSequence[i] = 0.0;
    }

    for (i = 0; i < 50; i++) {
      gbyk_v4b_B.TPSelector[i] = 0.0;
    }

    for (i = 0; i < 5000; i++) {
      gbyk_v4b_B.Convert1[i] = 0.0;
    }

    for (i = 0; i < 10; i++) {
      gbyk_v4b_B.Convert11[i] = 0.0;
    }

    for (i = 0; i < 800; i++) {
      gbyk_v4b_B.TargetTable[i] = 0.0;
    }

    for (i = 0; i < 200; i++) {
      gbyk_v4b_B.LoadTable[i] = 0.0;
    }

    for (i = 0; i < 50; i++) {
      gbyk_v4b_B.Taskwideparam[i] = 0.0;
    }

    for (i = 0; i < 499; i++) {
      gbyk_v4b_B.Selector3[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      gbyk_v4b_B.Hand_Pos[i] = 0.0;
    }

    for (i = 0; i < 32; i++) {
      gbyk_v4b_B.ArraySelector[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      gbyk_v4b_B.Hand_Pos_i[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      gbyk_v4b_B.Hand_Pos_n[i] = 0.0;
    }

    for (i = 0; i < 32; i++) {
      gbyk_v4b_B.ArraySelector_n[i] = 0.0;
    }

    for (i = 0; i < 25; i++) {
      gbyk_v4b_B.Selector[i] = 0.0;
    }

    for (i = 0; i < 55; i++) {
      gbyk_v4b_B.MatrixConcatenation1[i] = 0.0;
    }

    for (i = 0; i < 50; i++) {
      gbyk_v4b_B.Selector_l[i] = 0.0;
    }

    for (i = 0; i < 55; i++) {
      gbyk_v4b_B.MatrixConcatenation1_n[i] = 0.0;
    }

    for (i = 0; i < 70; i++) {
      gbyk_v4b_B.Reshape[i] = 0.0;
    }

    for (i = 0; i < 70; i++) {
      gbyk_v4b_B.Reshape1[i] = 0.0;
    }

    for (i = 0; i < 140; i++) {
      gbyk_v4b_B.MatrixConcatenation[i] = 0.0;
    }

    for (i = 0; i < 25; i++) {
      gbyk_v4b_B.Selector_g[i] = 0.0;
    }

    for (i = 0; i < 55; i++) {
      gbyk_v4b_B.MatrixConcatenation1_a[i] = 0.0;
    }

    for (i = 0; i < 25; i++) {
      gbyk_v4b_B.Selector_j[i] = 0.0;
    }

    for (i = 0; i < 55; i++) {
      gbyk_v4b_B.MatrixConcatenation1_na[i] = 0.0;
    }

    for (i = 0; i < 50; i++) {
      gbyk_v4b_B.Selector_i[i] = 0.0;
    }

    for (i = 0; i < 55; i++) {
      gbyk_v4b_B.MatrixConcatenation1_p[i] = 0.0;
    }

    for (i = 0; i < 25; i++) {
      gbyk_v4b_B.Selector_d[i] = 0.0;
    }

    for (i = 0; i < 55; i++) {
      gbyk_v4b_B.MatrixConcatenation1_h[i] = 0.0;
    }

    for (i = 0; i < 700; i++) {
      gbyk_v4b_B.MatrixConcatenation_b[i] = 0.0;
    }

    for (i = 0; i < 700; i++) {
      gbyk_v4b_B.RateTransition2[i] = 0.0;
    }

    for (i = 0; i < 1330; i++) {
      gbyk_v4b_B.MatrixConcatenate[i] = 0.0;
    }

    for (i = 0; i < 17; i++) {
      gbyk_v4b_B.RateTransition1_i[i] = 0.0;
    }

    for (i = 0; i < 40; i++) {
      gbyk_v4b_B.RateTransition_k[i] = 0.0;
    }

    for (i = 0; i < 13; i++) {
      gbyk_v4b_B.RateTransition2_er[i] = 0.0;
    }

    for (i = 0; i < 14; i++) {
      gbyk_v4b_B.RateTransition3_n[i] = 0.0;
    }

    for (i = 0; i < 68; i++) {
      gbyk_v4b_B.ArmKinematics[i] = 0.0;
    }

    for (i = 0; i < 20; i++) {
      gbyk_v4b_B.VectorConcatenate[i] = 0.0;
    }

    for (i = 0; i < 20; i++) {
      gbyk_v4b_B.AnalogData[i] = 0.0;
    }

    for (i = 0; i < 20; i++) {
      gbyk_v4b_B.RateTransition1_c[i] = 0.0;
    }

    for (i = 0; i < 10; i++) {
      gbyk_v4b_B.CustomData1[i] = 0.0;
    }

    for (i = 0; i < 18; i++) {
      gbyk_v4b_B.RateTransition_d[i] = 0.0;
    }

    for (i = 0; i < 8; i++) {
      gbyk_v4b_B.readstatus[i] = 0.0;
    }

    for (i = 0; i < 5; i++) {
      gbyk_v4b_B.SFunctionBuilder_o3[i] = 0.0;
    }

    for (i = 0; i < 60; i++) {
      gbyk_v4b_B.Selector4[i] = 0.0;
    }

    for (i = 0; i < 60; i++) {
      gbyk_v4b_B.Selector5[i] = 0.0;
    }

    for (i = 0; i < 120; i++) {
      gbyk_v4b_B.trialIterations[i] = 0.0;
    }

    for (i = 0; i < 5; i++) {
      gbyk_v4b_B.TmpSignalConversionAtSFunctionInport3[i] = 0.0;
    }

    for (i = 0; i < 160; i++) {
      gbyk_v4b_B.intarget[i] = 0.0;
    }

    for (i = 0; i < 15; i++) {
      gbyk_v4b_B.TmpSignalConversionAtSFunctionInport3_d[i] = 0.0;
    }

    for (i = 0; i < 160; i++) {
      gbyk_v4b_B.intarget_l[i] = 0.0;
    }

    for (i = 0; i < 32; i++) {
      gbyk_v4b_B.distance[i] = 0.0;
    }

    for (i = 0; i < 140; i++) {
      gbyk_v4b_B.VCODES_out[i] = 0.0;
    }

    for (i = 0; i < 50; i++) {
      gbyk_v4b_B.Selector_n[i] = 0.0;
    }

    for (i = 0; i < 500; i++) {
      gbyk_v4b_B.Selector1[i] = 0.0;
    }

    for (i = 0; i < 1000; i++) {
      gbyk_v4b_B.Selector2_l[i] = 0.0;
    }

    for (i = 0; i < 10; i++) {
      gbyk_v4b_B.Concatenation1[i] = 0.0;
    }

    for (i = 0; i < 352; i++) {
      gbyk_v4b_B.target_vector[i] = 0.0;
    }

    for (i = 0; i < 70; i++) {
      gbyk_v4b_B.VCODE[i] = 0.0;
    }

    for (i = 0; i < 70; i++) {
      gbyk_v4b_B.VCODE_mod[i] = 0.0;
    }

    for (i = 0; i < 14; i++) {
      gbyk_v4b_B.DataStoreRead[i] = 0.0;
    }

    for (i = 0; i < 8; i++) {
      gbyk_v4b_B.convert[i] = 0.0;
    }

    for (i = 0; i < 50; i++) {
      gbyk_v4b_B.Selector_c[i] = 0.0;
    }

    for (i = 0; i < 50; i++) {
      gbyk_v4b_B.Selector1_m[i] = 0.0;
    }

    for (i = 0; i < 50; i++) {
      gbyk_v4b_B.Selector2_o[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      gbyk_v4b_B.Selector1_a[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      gbyk_v4b_B.Selector2_i[i] = 0.0;
    }

    for (i = 0; i < 16; i++) {
      gbyk_v4b_B.Read[i] = 0.0;
    }

    for (i = 0; i < 24; i++) {
      gbyk_v4b_B.ReadHW[i] = 0.0;
    }

    for (i = 0; i < 20; i++) {
      gbyk_v4b_B.ReadKinematics[i] = 0.0;
    }

    for (i = 0; i < 12; i++) {
      gbyk_v4b_B.Primaryread[i] = 0.0;
    }

    for (i = 0; i < 8; i++) {
      gbyk_v4b_B.torquefeedback1[i] = 0.0;
    }

    for (i = 0; i < 20; i++) {
      gbyk_v4b_B.ErrMsgs[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      gbyk_v4b_B.newMessage[i] = 0.0;
    }

    for (i = 0; i < 14; i++) {
      gbyk_v4b_B.TmpSignalConversionAtSFunctionInport3_e[i] = 0.0;
    }

    for (i = 0; i < 7; i++) {
      gbyk_v4b_B.TmpSignalConversionAtSFunctionInport10[i] = 0.0;
    }

    for (i = 0; i < 14; i++) {
      gbyk_v4b_B.TmpSignalConversionAtSFunctionInport12[i] = 0.0;
    }

    for (i = 0; i < 150; i++) {
      gbyk_v4b_B.kinarm_data[i] = 0.0;
    }

    for (i = 0; i < 12; i++) {
      gbyk_v4b_B.primary_encoder_data_out[i] = 0.0;
    }

    for (i = 0; i < 16; i++) {
      gbyk_v4b_B.DataStore[i] = 0.0;
    }

    for (i = 0; i < 24; i++) {
      gbyk_v4b_B.DataStore1[i] = 0.0;
    }

    for (i = 0; i < 16; i++) {
      gbyk_v4b_B.calibrationsOut[i] = 0.0;
    }

    for (i = 0; i < 24; i++) {
      gbyk_v4b_B.settingsOut[i] = 0.0;
    }

    for (i = 0; i < 20; i++) {
      gbyk_v4b_B.outMem[i] = 0.0;
    }

    for (i = 0; i < 20; i++) {
      gbyk_v4b_B.kinematicsOut[i] = 0.0;
    }

    for (i = 0; i < 12; i++) {
      gbyk_v4b_B.kinematicsOutPrimary[i] = 0.0;
    }

    for (i = 0; i < 20; i++) {
      gbyk_v4b_B.outVals[i] = 0.0;
    }

    for (i = 0; i < 20; i++) {
      gbyk_v4b_B.kinematics[i] = 0.0;
    }

    for (i = 0; i < 12; i++) {
      gbyk_v4b_B.primary[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      gbyk_v4b_B.Conversion1[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      gbyk_v4b_B.Conversion2[i] = 0.0;
    }

    for (i = 0; i < 10; i++) {
      gbyk_v4b_B.DataTypeConversion3_d[i] = 0.0;
    }

    for (i = 0; i < 10; i++) {
      gbyk_v4b_B.DataTypeConversion4_g[i] = 0.0;
    }

    for (i = 0; i < 10; i++) {
      gbyk_v4b_B.robot1DataOut[i] = 0.0;
    }

    for (i = 0; i < 10; i++) {
      gbyk_v4b_B.robot2DataOut[i] = 0.0;
    }

    for (i = 0; i < 10; i++) {
      gbyk_v4b_B.robot1DataOut_p[i] = 0.0;
    }

    for (i = 0; i < 10; i++) {
      gbyk_v4b_B.robot2DataOut_g[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      gbyk_v4b_B.robot1PrimaryEncDataOut[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      gbyk_v4b_B.robot2PrimaryEncDataOut[i] = 0.0;
    }

    for (i = 0; i < 7; i++) {
      gbyk_v4b_B.Switch_p[i] = 0.0;
    }

    for (i = 0; i < 7; i++) {
      gbyk_v4b_B.Switch1_b[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      gbyk_v4b_B.DataTypeConversion1_g[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      gbyk_v4b_B.DataTypeConversion_e[i] = 0.0;
    }

    for (i = 0; i < 24; i++) {
      gbyk_v4b_B.intAddresses[i] = 0.0;
    }

    for (i = 0; i < 24; i++) {
      gbyk_v4b_B.floatAddresses[i] = 0.0;
    }

    for (i = 0; i < 12; i++) {
      gbyk_v4b_B.errVals[i] = 0.0;
    }

    for (i = 0; i < 12; i++) {
      gbyk_v4b_B.DCErrVals[i] = 0.0;
    }

    for (i = 0; i < 5; i++) {
      gbyk_v4b_B.R2M2_EMCY_codes[i] = 0.0;
    }

    for (i = 0; i < 5; i++) {
      gbyk_v4b_B.R2M1_EMCY_codes[i] = 0.0;
    }

    for (i = 0; i < 5; i++) {
      gbyk_v4b_B.writeData[i] = 0.0;
    }

    for (i = 0; i < 5; i++) {
      gbyk_v4b_B.A2M2Convert[i] = 0.0;
    }

    for (i = 0; i < 5; i++) {
      gbyk_v4b_B.A2M1Convert[i] = 0.0;
    }

    for (i = 0; i < 5; i++) {
      gbyk_v4b_B.R1M2_EMCY_codes[i] = 0.0;
    }

    for (i = 0; i < 5; i++) {
      gbyk_v4b_B.R1M1_EMCY_codes[i] = 0.0;
    }

    for (i = 0; i < 5; i++) {
      gbyk_v4b_B.writeData_e[i] = 0.0;
    }

    for (i = 0; i < 5; i++) {
      gbyk_v4b_B.A1M2Convert[i] = 0.0;
    }

    for (i = 0; i < 5; i++) {
      gbyk_v4b_B.A1M1Convert[i] = 0.0;
    }

    for (i = 0; i < 14; i++) {
      gbyk_v4b_B.Convert19_e[i] = 0.0;
    }

    for (i = 0; i < 140; i++) {
      gbyk_v4b_B.VCODE_MOD[i] = 0.0;
    }

    for (i = 0; i < 140; i++) {
      gbyk_v4b_B.VCODE_MOD_n[i] = 0.0;
    }

    for (i = 0; i < 6; i++) {
      gbyk_v4b_B.DataTypeConversion_a[i] = 0.0F;
    }

    for (i = 0; i < 6; i++) {
      gbyk_v4b_B.DataTypeConversion1_cq[i] = 0.0F;
    }

    for (i = 0; i < 8; i++) {
      gbyk_v4b_B.Reshape_i[i] = 0.0F;
    }

    for (i = 0; i < 10; i++) {
      gbyk_v4b_B.DataTypeConversion_a5[i] = 0.0F;
    }

    for (i = 0; i < 10; i++) {
      gbyk_v4b_B.DataTypeConversion1_i1[i] = 0.0F;
    }

    for (i = 0; i < 10; i++) {
      gbyk_v4b_B.SFunction_o1[i] = 0.0F;
    }

    for (i = 0; i < 10; i++) {
      gbyk_v4b_B.SFunction_o2[i] = 0.0F;
    }

    for (i = 0; i < 6; i++) {
      gbyk_v4b_B.SFunction_o5[i] = 0.0F;
    }

    for (i = 0; i < 6; i++) {
      gbyk_v4b_B.SFunction_o6[i] = 0.0F;
    }

    for (i = 0; i < 400; i++) {
      gbyk_v4b_B.TmpRTBAtSendControlMachineInport1[i] = 0.0F;
    }

    for (i = 0; i < 410; i++) {
      gbyk_v4b_B.data_out[i] = 0.0F;
    }

    for (i = 0; i < 127; i++) {
      gbyk_v4b_B.DataTypeConversion_p1[i] = 0.0F;
    }

    for (i = 0; i < 127; i++) {
      gbyk_v4b_B.t2[i] = 0.0F;
    }

    for (i = 0; i < 127; i++) {
      gbyk_v4b_B.t1[i] = 0.0F;
    }

    for (i = 0; i < 781; i++) {
      gbyk_v4b_B.TmpSignalConversionAtSelectorInport1[i] = 0.0F;
    }

    for (i = 0; i < 400; i++) {
      gbyk_v4b_B.Selector_e[i] = 0.0F;
    }

    for (i = 0; i < 70; i++) {
      gbyk_v4b_B.sf_EmbeddedMATLABFunction_i.VCODE[i] = 0.0;
    }

    for (i = 0; i < 140; i++) {
      gbyk_v4b_B.sf_EmbeddedMATLABFunction_id.VCODE[i] = 0.0;
    }

    for (i = 0; i < 140; i++) {
      gbyk_v4b_B.sf_EmbeddedMATLABFunction_k.VCODE[i] = 0.0;
    }

    for (i = 0; i < 70; i++) {
      gbyk_v4b_B.sf_EmbeddedMATLABFunction_c.VCODE[i] = 0.0;
    }

    for (i = 0; i < 70; i++) {
      gbyk_v4b_B.sf_EmbeddedMATLABFunction_b.VCODE[i] = 0.0;
    }

    for (i = 0; i < 20; i++) {
      gbyk_v4b_B.sf_SDOreadmachine_h.floatSDOValues[i] = 0.0;
    }

    for (i = 0; i < 24; i++) {
      gbyk_v4b_B.sf_setupvalues_g.setupValues[i] = 0.0;
    }

    for (i = 0; i < 12; i++) {
      gbyk_v4b_B.sf_setupvalues_g.encoderValues[i] = 0.0;
    }

    for (i = 0; i < 24; i++) {
      gbyk_v4b_B.sf_setupvalues_k.setupValues[i] = 0.0;
    }

    for (i = 0; i < 12; i++) {
      gbyk_v4b_B.sf_setupvalues_k.encoderValues[i] = 0.0;
    }

    for (i = 0; i < 5; i++) {
      gbyk_v4b_B.sf_faultmonitor1_h.EMCYMsg[i] = 0.0;
    }

    for (i = 0; i < 5; i++) {
      gbyk_v4b_B.sf_faultmonitor1_c.EMCYMsg[i] = 0.0;
    }

    for (i = 0; i < 20; i++) {
      gbyk_v4b_B.sf_SDOreadmachine.floatSDOValues[i] = 0.0;
    }

    for (i = 0; i < 24; i++) {
      gbyk_v4b_B.sf_setupvalues_p.setupValues[i] = 0.0;
    }

    for (i = 0; i < 12; i++) {
      gbyk_v4b_B.sf_setupvalues_p.encoderValues[i] = 0.0;
    }

    for (i = 0; i < 24; i++) {
      gbyk_v4b_B.sf_setupvalues.setupValues[i] = 0.0;
    }

    for (i = 0; i < 12; i++) {
      gbyk_v4b_B.sf_setupvalues.encoderValues[i] = 0.0;
    }

    for (i = 0; i < 5; i++) {
      gbyk_v4b_B.sf_faultmonitor1_l.EMCYMsg[i] = 0.0;
    }

    for (i = 0; i < 5; i++) {
      gbyk_v4b_B.sf_faultmonitor1.EMCYMsg[i] = 0.0;
    }

    gbyk_v4b_B.RunCommandReceive_o2 = 0.0;
    gbyk_v4b_B.DataTypeConversion = 0.0;
    gbyk_v4b_B.PauseType = 0.0;
    gbyk_v4b_B.Convert18 = 0.0;
    gbyk_v4b_B.UseTaskProtocolBlockSequenceFlag = 0.0;
    gbyk_v4b_B.NextBlock = 0.0;
    gbyk_v4b_B.Convert16 = 0.0;
    gbyk_v4b_B.Convert17 = 0.0;
    gbyk_v4b_B.MinMax = 0.0;
    gbyk_v4b_B.DataTypeConversion2 = 0.0;
    gbyk_v4b_B.Convert10[0] = 0.0;
    gbyk_v4b_B.Convert10[1] = 0.0;
    gbyk_v4b_B.Convert12 = 0.0;
    gbyk_v4b_B.Convert13[0] = 0.0;
    gbyk_v4b_B.Convert13[1] = 0.0;
    gbyk_v4b_B.Convert13[2] = 0.0;
    gbyk_v4b_B.Convert14[0] = 0.0;
    gbyk_v4b_B.Convert14[1] = 0.0;
    gbyk_v4b_B.Convert15 = 0.0;
    gbyk_v4b_B.Convert7 = 0.0;
    gbyk_v4b_B.Convert8 = 0.0;
    gbyk_v4b_B.Convert9[0] = 0.0;
    gbyk_v4b_B.Convert9[1] = 0.0;
    gbyk_v4b_B.frame_of_reference_center[0] = 0.0;
    gbyk_v4b_B.frame_of_reference_center[1] = 0.0;
    gbyk_v4b_B.LibraryPatchVersion = 0.0;
    gbyk_v4b_B.LibraryVersion = 0.0;
    gbyk_v4b_B.TaskVersion = 0.0;
    gbyk_v4b_B.xPCVersion = 0.0;
    gbyk_v4b_B.dlmbuildtime = 0.0;
    gbyk_v4b_B.Timestamp = 0.0;
    gbyk_v4b_B.conv = 0.0;
    gbyk_v4b_B.RunStatus = 0.0;
    gbyk_v4b_B.RateTransition10 = 0.0;
    gbyk_v4b_B.Selector2 = 0.0;
    gbyk_v4b_B.Product = 0.0;
    gbyk_v4b_B.Memory[0] = 0.0;
    gbyk_v4b_B.Memory[1] = 0.0;
    gbyk_v4b_B.Memory[2] = 0.0;
    gbyk_v4b_B.Memory[3] = 0.0;
    gbyk_v4b_B.Memory_k = 0.0;
    gbyk_v4b_B.Gain = 0.0;
    gbyk_v4b_B.Dominant_Arm = 0.0;
    gbyk_v4b_B.MultiportSwitch[0] = 0.0;
    gbyk_v4b_B.MultiportSwitch[1] = 0.0;
    gbyk_v4b_B.Dominant_Arm_k = 0.0;
    gbyk_v4b_B.MultiportSwitch_c[0] = 0.0;
    gbyk_v4b_B.MultiportSwitch_c[1] = 0.0;
    gbyk_v4b_B.Switch1[0] = 0.0;
    gbyk_v4b_B.Switch1[1] = 0.0;
    gbyk_v4b_B.Switch[0] = 0.0;
    gbyk_v4b_B.Switch[1] = 0.0;
    gbyk_v4b_B.MathFunction[0] = 0.0;
    gbyk_v4b_B.MathFunction[1] = 0.0;
    gbyk_v4b_B.SumofElements = 0.0;
    gbyk_v4b_B.Sqrt = 0.0;
    gbyk_v4b_B.Dominant_Arm_o = 0.0;
    gbyk_v4b_B.MultiportSwitch_b[0] = 0.0;
    gbyk_v4b_B.MultiportSwitch_b[1] = 0.0;
    gbyk_v4b_B.Product_g[0] = 0.0;
    gbyk_v4b_B.Product_g[1] = 0.0;
    gbyk_v4b_B.LoggingEnable[0] = 0.0;
    gbyk_v4b_B.LoggingEnable[1] = 0.0;
    gbyk_v4b_B.RateTransition9[0] = 0.0;
    gbyk_v4b_B.RateTransition9[1] = 0.0;
    gbyk_v4b_B.CurrentTPIndex = 0.0;
    gbyk_v4b_B.RateTransition8 = 0.0;
    gbyk_v4b_B.CurrentBlockIndex = 0.0;
    gbyk_v4b_B.RateTransition7 = 0.0;
    gbyk_v4b_B.CurrentTrialNumberinBlock = 0.0;
    gbyk_v4b_B.RateTransition6 = 0.0;
    gbyk_v4b_B.CurrentBlockNumberinSet = 0.0;
    gbyk_v4b_B.RateTransition5 = 0.0;
    gbyk_v4b_B.CurrentTrialNumberinSet = 0.0;
    gbyk_v4b_B.RateTransition4 = 0.0;
    gbyk_v4b_B.LastFrameSent1 = 0.0;
    gbyk_v4b_B.RateTransition12 = 0.0;
    gbyk_v4b_B.DataTypeConversion_b = 0.0;
    gbyk_v4b_B.Switch_h = 0.0;
    gbyk_v4b_B.Add = 0.0;
    gbyk_v4b_B.Abs = 0.0;
    gbyk_v4b_B.Sign = 0.0;
    gbyk_v4b_B.Convert = 0.0;
    gbyk_v4b_B.LastFrameSent = 0.0;
    gbyk_v4b_B.RateTransition3 = 0.0;
    gbyk_v4b_B.Receive_o2 = 0.0;
    gbyk_v4b_B.Convert1_a = 0.0;
    gbyk_v4b_B.LastFrameAcknowledged = 0.0;
    gbyk_v4b_B.RateTransition2_e = 0.0;
    gbyk_v4b_B.ButtonStatus = 0.0;
    gbyk_v4b_B.RateTransition1 = 0.0;
    gbyk_v4b_B.Servoupdatecount = 0.0;
    gbyk_v4b_B.RateTransition = 0.0;
    gbyk_v4b_B.TaskControlButton = 0.0;
    gbyk_v4b_B.RateTransition11 = 0.0;
    gbyk_v4b_B.TmpRTBAtNumberofEventCodesOutport1 = 0.0;
    gbyk_v4b_B.EventCodes = 0.0;
    gbyk_v4b_B.RateTransition2_ea[0] = 0.0;
    gbyk_v4b_B.RateTransition2_ea[1] = 0.0;
    gbyk_v4b_B.KinarmDataWidth = 0.0;
    gbyk_v4b_B.touint1 = 0.0;
    gbyk_v4b_B.Subtract = 0.0;
    gbyk_v4b_B.AnalogDataWidth = 0.0;
    gbyk_v4b_B.RateTransition_c = 0.0;
    gbyk_v4b_B.TrigonometricFunction = 0.0;
    gbyk_v4b_B.RateTransition_b[0] = 0.0;
    gbyk_v4b_B.RateTransition_b[1] = 0.0;
    gbyk_v4b_B.RateTransition_b[2] = 0.0;
    gbyk_v4b_B.RateTransition_b[3] = 0.0;
    gbyk_v4b_B.RateTransition1_b = 0.0;
    gbyk_v4b_B.RateTransition2_eo = 0.0;
    gbyk_v4b_B.Subtract_g = 0.0;
    gbyk_v4b_B.NumberofEventCodes = 0.0;
    gbyk_v4b_B.AddTorques[0] = 0.0;
    gbyk_v4b_B.AddTorques[1] = 0.0;
    gbyk_v4b_B.AddTorques[2] = 0.0;
    gbyk_v4b_B.AddTorques[3] = 0.0;
    gbyk_v4b_B.Memory1 = 0.0;
    gbyk_v4b_B.ArmOrientation = 0.0;
    gbyk_v4b_B.M1orientation = 0.0;
    gbyk_v4b_B.M2Orientation = 0.0;
    gbyk_v4b_B.M1GearRatio = 0.0;
    gbyk_v4b_B.M2GearRatio = 0.0;
    gbyk_v4b_B.torqueconstant = 0.0;
    gbyk_v4b_B.ArmOrientation_c = 0.0;
    gbyk_v4b_B.M1orientation_f = 0.0;
    gbyk_v4b_B.M2Orientation_c = 0.0;
    gbyk_v4b_B.M1GearRatio_h = 0.0;
    gbyk_v4b_B.M2GearRatio_d = 0.0;
    gbyk_v4b_B.torqueconstant_m = 0.0;
    gbyk_v4b_B.isEP = 0.0;
    gbyk_v4b_B.isHumanExo = 0.0;
    gbyk_v4b_B.isNHPExo = 0.0;
    gbyk_v4b_B.isClassicExo = 0.0;
    gbyk_v4b_B.isUTSExo = 0.0;
    gbyk_v4b_B.isPMAC = 0.0;
    gbyk_v4b_B.isECAT = 0.0;
    gbyk_v4b_B.robotRevision = 0.0;
    gbyk_v4b_B.HasSecondaryEnc = 0.0;
    gbyk_v4b_B.robottype = 0.0;
    gbyk_v4b_B.robotversion = 0.0;
    gbyk_v4b_B.isEP_k = 0.0;
    gbyk_v4b_B.isHumanExo_p = 0.0;
    gbyk_v4b_B.isNHPExo_n = 0.0;
    gbyk_v4b_B.isClassicExo_g = 0.0;
    gbyk_v4b_B.isUTSExo_o = 0.0;
    gbyk_v4b_B.isPMAC_n = 0.0;
    gbyk_v4b_B.isECAT_b = 0.0;
    gbyk_v4b_B.robotRevision_k = 0.0;
    gbyk_v4b_B.HasSecondaryEnc_d = 0.0;
    gbyk_v4b_B.robottype_c = 0.0;
    gbyk_v4b_B.robotversion_i = 0.0;
    gbyk_v4b_B.robot_count = 0.0;
    gbyk_v4b_B.has_force_plate_1 = 0.0;
    gbyk_v4b_B.has_force_plate_2 = 0.0;
    gbyk_v4b_B.has_gaze_tracker = 0.0;
    gbyk_v4b_B.has_robot_lift = 0.0;
    gbyk_v4b_B.RateTransition1_l = 0.0;
    gbyk_v4b_B.RateTransition2_d = 0.0;
    gbyk_v4b_B.SFunctionBuilder_o2 = 0.0;
    gbyk_v4b_B.VectorConcatenate2[0] = 0.0;
    gbyk_v4b_B.VectorConcatenate2[1] = 0.0;
    gbyk_v4b_B.VectorConcatenate2[2] = 0.0;
    gbyk_v4b_B.B1TargetB1rowfloatB1rowintargettablenone = 0.0;
    gbyk_v4b_B.B2TargetB2rowfloatB2rowintargettablenone = 0.0;
    gbyk_v4b_B.CORR_TGTWhichtargetiscorrectfloatWhichtargetiscorrect1or2none =
      0.0;
    gbyk_v4b_B.DELAY_POST_TRIALTrialEndDelayintegerTimetowaitattheendofthetria =
      0.0;
    gbyk_v4b_B.DISPLAY_TRIAL_COLFlagDisplayintegerDisplayandpausenone = 0.0;
    gbyk_v4b_B.INCORR_TGTWhichtargetisincorrectfloatWhichtargetisincorrect1or2 =
      0.0;
    gbyk_v4b_B.MAX_REACH_TIME_COLMaximumReachTimeintegerMaximumreachdurational =
      0.0;
    gbyk_v4b_B.RWD_TARGETC1_COLTarget1ValuefloatRewardofferedonTargetC1none =
      0.0;
    gbyk_v4b_B.RWD_TARGETC2_COLTarget2ValuefloatRewardofferedonTargetC2none =
      0.0;
    gbyk_v4b_B.START_TARGET_COLStarttargettargetFirsttargettoappearduringatria =
      0.0;
    gbyk_v4b_B.TGT_C_RWD_FRACRewardratiobetweenrowCrowBfloatHowmuchmorewilltar =
      0.0;
    gbyk_v4b_B.INSTRUCT_PAUSE_BTNInstructionResumeButtontocontinuetaskafterdis =
      0.0;
    gbyk_v4b_B.E_BOX_TRIGGERBoxWasTriggeredBoxtriggreredsosubjectchoserowCnone =
      0.0;
    gbyk_v4b_B.E_CHOSE_ROW_BChoseRowBSubjectchoserowBnone = 0.0;
    gbyk_v4b_B.E_HIT_TARGETBHitTargetBHittargetBnone = 0.0;
    gbyk_v4b_B.E_HIT_TARGETCHitTargetCHitTargetCnone = 0.0;
    gbyk_v4b_B.E_MISS_TARGETBMissTargretBMissTargretBnone = 0.0;
    gbyk_v4b_B.E_MISS_TARGETCMissTargetCMissTargetCnone = 0.0;
    gbyk_v4b_B.E_NEW_TRIALNewTrialStartNewTrialstartsnone = 0.0;
    gbyk_v4b_B.E_NO_EVENTnaThisevent_codedoesnotsaveaneventinthedatafileitjust =
      0.0;
    gbyk_v4b_B.E_SHOW_INSTRUCTInstructionstateShowinginstructionsnone = 0.0;
    gbyk_v4b_B.E_SHOW_SCOREShowScoreShowingscorenone = 0.0;
    gbyk_v4b_B.E_STAY_STARTAtStartSubjectreachedstarttargetnone = 0.0;
    gbyk_v4b_B.E_TARGETS_ONTargetsOnPotentialReachtargetsonnone = 0.0;
    gbyk_v4b_B.E_TOO_SLOWTooSlowMovementistooslowerror = 0.0;
    gbyk_v4b_B.BOX_HEIGHTHeightofBoxfloatHeightofBoxnone = 0.0;
    gbyk_v4b_B.HIT_COLORReachedcolorcolourColorwhenthetargetistouchednone = 0.0;
    gbyk_v4b_B.INIT_COLORInitialcolorcolourInitialtargetcolornone = 0.0;
    gbyk_v4b_B.LABELLabelTextlabelInitialtextforthelabelnone = 0.0;
    gbyk_v4b_B.LABELONLY_XLabelOnlyXfloatXpositioncmofthetargetrelativetolocal =
      0.0;
    gbyk_v4b_B.LABELONLY_YLabelOnlyYfloatYpositioncmofthetargetrelativetolocal =
      0.0;
    gbyk_v4b_B.LABEL_HEIGHTLabelHeightfloatLabelHeightcmnone = 0.0;
    gbyk_v4b_B.LOGICAL_RADIUSLogicalradiusfloatRadiusofthetargetusedforhandint =
      0.0;
    gbyk_v4b_B.ROTATIONRotationofatargetfloatRotationoftargetnone = 0.0;
    gbyk_v4b_B.STROKE_WIDTHStrokeWidthfloatStrokewidthnone = 0.0;
    gbyk_v4b_B.TEXT_COLORTextColorcolourTextColornone = 0.0;
    gbyk_v4b_B.col_xXfloatXPositioncmofthetargetrelativetolocal00none = 0.0;
    gbyk_v4b_B.col_yYfloatYPositioncmofthetargetrelativetolocal00none = 0.0;
    gbyk_v4b_B.VISUAL_RADIUSVisualradiusfloatVisualradiusofthetargetcmorsizeof =
      0.0;
    gbyk_v4b_B.INSTRUCTIONS = 0.0;
    gbyk_v4b_B.LOAD_FOREITHER = 0.0;
    gbyk_v4b_B.K_DELAY_FIXEDDelay_MinintegerMinimumholddelaytimeatstarttargetf =
      0.0;
    gbyk_v4b_B.K_DELAY_RANDDelay_RandintegerMaximumadditionaldelaytimeatstartt =
      0.0;
    gbyk_v4b_B.K_PRE_REWARD_DELAYDelay_PreRewardCueintegerTimetocuetherewardin =
      0.0;
    gbyk_v4b_B.K_REWARD_VALReward_ValueintegerOneunitofrewardnone = 0.0;
    gbyk_v4b_B.K_SCORETEXT_ROWFeedback_Text_TgtTable_RowintegerTargetnumbertob =
      0.0;
    gbyk_v4b_B.K_THRESH_VELMAXVel_Min_ThreshfloatMinimumvelocitythatmustbeexce =
      0.0;
    gbyk_v4b_B.K_TRIGGER_POSTrigger_PosfloatPositionThresholdfortriggeringtarg =
      0.0;
    gbyk_v4b_B.K_TRIGGER_VELTrigger_VelfloatVelocityThresholdfortriggeringtarg =
      0.0;
    gbyk_v4b_B.logging_enable[0] = 0.0;
    gbyk_v4b_B.logging_enable[1] = 0.0;
    gbyk_v4b_B.targetA_row = 0.0;
    gbyk_v4b_B.targetA_state = 0.0;
    gbyk_v4b_B.targetB_row[0] = 0.0;
    gbyk_v4b_B.targetB_row[1] = 0.0;
    gbyk_v4b_B.targetB_state[0] = 0.0;
    gbyk_v4b_B.targetB_state[1] = 0.0;
    gbyk_v4b_B.offeredRewards[0] = 0.0;
    gbyk_v4b_B.offeredRewards[1] = 0.0;
    gbyk_v4b_B.score = 0.0;
    gbyk_v4b_B.doreward = 0.0;
    gbyk_v4b_B.reward = 0.0;
    gbyk_v4b_B.instruct_num = 0.0;
    gbyk_v4b_B.tone = 0.0;
    gbyk_v4b_B.repeat_trial_flag = 0.0;
    gbyk_v4b_B.targetC_row[0] = 0.0;
    gbyk_v4b_B.targetC_row[1] = 0.0;
    gbyk_v4b_B.targetC_state[0] = 0.0;
    gbyk_v4b_B.targetC_state[1] = 0.0;
    gbyk_v4b_B.offeredRewardsC[0] = 0.0;
    gbyk_v4b_B.offeredRewardsC[1] = 0.0;
    gbyk_v4b_B.boxRow = 0.0;
    gbyk_v4b_B.boxState = 0.0;
    gbyk_v4b_B.Convert_n = 0.0;
    gbyk_v4b_B.RateTransition1_h = 0.0;
    gbyk_v4b_B.vis_cmd_len = 0.0;
    gbyk_v4b_B.vis_cmd_cropped = 0.0;
    gbyk_v4b_B.vcode_err_id = 0.0;
    gbyk_v4b_B.last_frame_ack = 0.0;
    gbyk_v4b_B.last_perm_ack = 0.0;
    gbyk_v4b_B.delay = 0.0;
    gbyk_v4b_B.ListReps = 0.0;
    gbyk_v4b_B.Arm1[0] = 0.0;
    gbyk_v4b_B.Arm1[1] = 0.0;
    gbyk_v4b_B.Arm2[0] = 0.0;
    gbyk_v4b_B.Arm2[1] = 0.0;
    gbyk_v4b_B.Arm1_p[0] = 0.0;
    gbyk_v4b_B.Arm1_p[1] = 0.0;
    gbyk_v4b_B.Arm2_o[0] = 0.0;
    gbyk_v4b_B.Arm2_o[1] = 0.0;
    gbyk_v4b_B.Arm1_a[0] = 0.0;
    gbyk_v4b_B.Arm1_a[1] = 0.0;
    gbyk_v4b_B.Arm2_j[0] = 0.0;
    gbyk_v4b_B.Arm2_j[1] = 0.0;
    gbyk_v4b_B.total_trials = 0.0;
    gbyk_v4b_B.trials_in_block = 0.0;
    gbyk_v4b_B.total_blocks = 0.0;
    gbyk_v4b_B.Delay1 = 0.0;
    gbyk_v4b_B.Product3 = 0.0;
    gbyk_v4b_B.TaskClock = 0.0;
    gbyk_v4b_B.Product_i = 0.0;
    gbyk_v4b_B.DataTypeConversion_g = 0.0;
    gbyk_v4b_B.Product2 = 0.0;
    gbyk_v4b_B.DataTypeConversion2_n = 0.0;
    gbyk_v4b_B.repeat_last_trial = 0.0;
    gbyk_v4b_B.extra_trials[0] = 0.0;
    gbyk_v4b_B.extra_trials[1] = 0.0;
    gbyk_v4b_B.value = 0.0;
    gbyk_v4b_B.y = 0.0;
    gbyk_v4b_B.z = 0.0;
    gbyk_v4b_B.target_vector_length = 0.0;
    gbyk_v4b_B.TmpSignalConversionAtSFunctionInport1[0] = 0.0;
    gbyk_v4b_B.TmpSignalConversionAtSFunctionInport1[1] = 0.0;
    gbyk_v4b_B.TmpSignalConversionAtSFunctionInport1[2] = 0.0;
    gbyk_v4b_B.TmpSignalConversionAtSFunctionInport1[3] = 0.0;
    gbyk_v4b_B.TmpSignalConversionAtSFunctionInport2[0] = 0.0;
    gbyk_v4b_B.TmpSignalConversionAtSFunctionInport2[1] = 0.0;
    gbyk_v4b_B.TmpSignalConversionAtSFunctionInport2[2] = 0.0;
    gbyk_v4b_B.TmpSignalConversionAtSFunctionInport2[3] = 0.0;
    gbyk_v4b_B.deltas[0] = 0.0;
    gbyk_v4b_B.deltas[1] = 0.0;
    gbyk_v4b_B.deltas[2] = 0.0;
    gbyk_v4b_B.deltas[3] = 0.0;
    gbyk_v4b_B.Product_m[0] = 0.0;
    gbyk_v4b_B.Product_m[1] = 0.0;
    gbyk_v4b_B.Product_m[2] = 0.0;
    gbyk_v4b_B.Product_m[3] = 0.0;
    gbyk_v4b_B.DataTypeConversion3[0] = 0.0;
    gbyk_v4b_B.DataTypeConversion3[1] = 0.0;
    gbyk_v4b_B.DataTypeConversion3[2] = 0.0;
    gbyk_v4b_B.DataTypeConversion3[3] = 0.0;
    gbyk_v4b_B.DataTypeConversion4 = 0.0;
    gbyk_v4b_B.DataTypeConversion5 = 0.0;
    gbyk_v4b_B.Convert1_p = 0.0;
    gbyk_v4b_B.DataTypeConversion_i = 0.0;
    gbyk_v4b_B.Convert19[0] = 0.0;
    gbyk_v4b_B.Convert19[1] = 0.0;
    gbyk_v4b_B.Convert19[2] = 0.0;
    gbyk_v4b_B.DataTypeConversion1[0] = 0.0;
    gbyk_v4b_B.DataTypeConversion1[1] = 0.0;
    gbyk_v4b_B.DataTypeConversion1[2] = 0.0;
    gbyk_v4b_B.TmpRTBAtconverttoseconds2Inport1[0] = 0.0;
    gbyk_v4b_B.TmpRTBAtconverttoseconds2Inport1[1] = 0.0;
    gbyk_v4b_B.TmpRTBAtconverttoseconds2Inport1[2] = 0.0;
    gbyk_v4b_B.TmpRTBAtconverttoseconds2Inport2 = 0.0;
    gbyk_v4b_B.Convert2[0] = 0.0;
    gbyk_v4b_B.Convert2[1] = 0.0;
    gbyk_v4b_B.Convert2[2] = 0.0;
    gbyk_v4b_B.Convert3 = 0.0;
    gbyk_v4b_B.Gain_b[0] = 0.0;
    gbyk_v4b_B.Gain_b[1] = 0.0;
    gbyk_v4b_B.Gain_b[2] = 0.0;
    gbyk_v4b_B.Convert4[0] = 0.0;
    gbyk_v4b_B.Convert4[1] = 0.0;
    gbyk_v4b_B.Convert4[2] = 0.0;
    gbyk_v4b_B.RateTransition_kg[0] = 0.0;
    gbyk_v4b_B.RateTransition_kg[1] = 0.0;
    gbyk_v4b_B.RateTransition_kg[2] = 0.0;
    gbyk_v4b_B.Receive_o2_j = 0.0;
    gbyk_v4b_B.event_data_out[0] = 0.0;
    gbyk_v4b_B.event_data_out[1] = 0.0;
    gbyk_v4b_B.event_data_out[2] = 0.0;
    gbyk_v4b_B.gazeXYCalculated[0] = 0.0;
    gbyk_v4b_B.gazeXYCalculated[1] = 0.0;
    gbyk_v4b_B.pupil_area_GLOBAL = 0.0;
    gbyk_v4b_B.gaze_unit_vector_GLOBAL[0] = 0.0;
    gbyk_v4b_B.gaze_unit_vector_GLOBAL[1] = 0.0;
    gbyk_v4b_B.gaze_unit_vector_GLOBAL[2] = 0.0;
    gbyk_v4b_B.pupil_GLOBAL[0] = 0.0;
    gbyk_v4b_B.pupil_GLOBAL[1] = 0.0;
    gbyk_v4b_B.pupil_GLOBAL[2] = 0.0;
    gbyk_v4b_B.timestamp_out = 0.0;
    gbyk_v4b_B.start_time_out = 0.0;
    gbyk_v4b_B.DataTypeConversion_h = 0.0;
    gbyk_v4b_B.systemtype = 0.0;
    gbyk_v4b_B.ReadHasFT[0] = 0.0;
    gbyk_v4b_B.ReadHasFT[1] = 0.0;
    gbyk_v4b_B.ArmOrientation_b = 0.0;
    gbyk_v4b_B.M1orientation_h = 0.0;
    gbyk_v4b_B.M2Orientation_l = 0.0;
    gbyk_v4b_B.M1GearRatio_b = 0.0;
    gbyk_v4b_B.M2GearRatio_p = 0.0;
    gbyk_v4b_B.HasSecondaryEnc_n = 0.0;
    gbyk_v4b_B.ArmOrientation_l = 0.0;
    gbyk_v4b_B.M1orientation_n = 0.0;
    gbyk_v4b_B.M2Orientation_cw = 0.0;
    gbyk_v4b_B.M1GearRatio_k = 0.0;
    gbyk_v4b_B.M2GearRatio_l = 0.0;
    gbyk_v4b_B.HasSecondaryEnc_f = 0.0;
    gbyk_v4b_B.shoulderangleoffset = 0.0;
    gbyk_v4b_B.elbowangleoffset = 0.0;
    gbyk_v4b_B.ShoulderX = 0.0;
    gbyk_v4b_B.ShoulderY = 0.0;
    gbyk_v4b_B.L1 = 0.0;
    gbyk_v4b_B.L2 = 0.0;
    gbyk_v4b_B.Pointeroffset = 0.0;
    gbyk_v4b_B.L3Error = 0.0;
    gbyk_v4b_B.robottype_e = 0.0;
    gbyk_v4b_B.torqueconstant_g = 0.0;
    gbyk_v4b_B.robotversion_g = 0.0;
    gbyk_v4b_B.shoulderangleoffset_b = 0.0;
    gbyk_v4b_B.elbowangleoffset_a = 0.0;
    gbyk_v4b_B.ShoulderX_a = 0.0;
    gbyk_v4b_B.ShoulderY_b = 0.0;
    gbyk_v4b_B.L1_c = 0.0;
    gbyk_v4b_B.L2_f = 0.0;
    gbyk_v4b_B.Pointeroffset_b = 0.0;
    gbyk_v4b_B.L3Error_f = 0.0;
    gbyk_v4b_B.robottype_cs = 0.0;
    gbyk_v4b_B.torqueconstant_i = 0.0;
    gbyk_v4b_B.robotversion_f = 0.0;
    gbyk_v4b_B.Statusread1[0] = 0.0;
    gbyk_v4b_B.Statusread1[1] = 0.0;
    gbyk_v4b_B.Statusread1_m[0] = 0.0;
    gbyk_v4b_B.Statusread1_m[1] = 0.0;
    gbyk_v4b_B.active_arm = 0.0;
    gbyk_v4b_B.delayEstimates[0] = 0.0;
    gbyk_v4b_B.delayEstimates[1] = 0.0;
    gbyk_v4b_B.delayEstimates[2] = 0.0;
    gbyk_v4b_B.delayEstimates[3] = 0.0;
    gbyk_v4b_B.servoCounter = 0.0;
    gbyk_v4b_B.calibrationButtonBits = 0.0;
    gbyk_v4b_B.handFF = 0.0;
    gbyk_v4b_B.handFF_Dex = 0.0;
    gbyk_v4b_B.handFBArm = 0.0;
    gbyk_v4b_B.handFBRadius = 0.0;
    gbyk_v4b_B.handFBControl = 0.0;
    gbyk_v4b_B.handFBColor = 0.0;
    gbyk_v4b_B.hasGaze = 0.0;
    gbyk_v4b_B.gazeFB = 0.0;
    gbyk_v4b_B.gazeLocation[0] = 0.0;
    gbyk_v4b_B.gazeLocation[1] = 0.0;
    gbyk_v4b_B.gazeTimestamp = 0.0;
    gbyk_v4b_B.gazePupilArea = 0.0;
    gbyk_v4b_B.gazeEvent[0] = 0.0;
    gbyk_v4b_B.gazeEvent[1] = 0.0;
    gbyk_v4b_B.gazeEvent[2] = 0.0;
    gbyk_v4b_B.gazeVector[0] = 0.0;
    gbyk_v4b_B.gazeVector[1] = 0.0;
    gbyk_v4b_B.gazeVector[2] = 0.0;
    gbyk_v4b_B.gazePupilLoc[0] = 0.0;
    gbyk_v4b_B.gazePupilLoc[1] = 0.0;
    gbyk_v4b_B.gazePupilLoc[2] = 0.0;
    gbyk_v4b_B.link_lengths[0] = 0.0;
    gbyk_v4b_B.link_lengths[1] = 0.0;
    gbyk_v4b_B.pointer_offset = 0.0;
    gbyk_v4b_B.shoulder_loc[0] = 0.0;
    gbyk_v4b_B.shoulder_loc[1] = 0.0;
    gbyk_v4b_B.arm_orientation = 0.0;
    gbyk_v4b_B.shoulder_ang = 0.0;
    gbyk_v4b_B.elbow_ang = 0.0;
    gbyk_v4b_B.shoulder_velocity = 0.0;
    gbyk_v4b_B.elbow_velocity = 0.0;
    gbyk_v4b_B.shoulder_acceleration = 0.0;
    gbyk_v4b_B.elbow_acceleration = 0.0;
    gbyk_v4b_B.joint_torque_cmd[0] = 0.0;
    gbyk_v4b_B.joint_torque_cmd[1] = 0.0;
    gbyk_v4b_B.motor_torque_cmd[0] = 0.0;
    gbyk_v4b_B.motor_torque_cmd[1] = 0.0;
    gbyk_v4b_B.link_angle[0] = 0.0;
    gbyk_v4b_B.link_angle[1] = 0.0;
    gbyk_v4b_B.link_velocity[0] = 0.0;
    gbyk_v4b_B.link_velocity[1] = 0.0;
    gbyk_v4b_B.link_acceleration[0] = 0.0;
    gbyk_v4b_B.link_acceleration[1] = 0.0;
    gbyk_v4b_B.hand_position[0] = 0.0;
    gbyk_v4b_B.hand_position[1] = 0.0;
    gbyk_v4b_B.hand_velocity[0] = 0.0;
    gbyk_v4b_B.hand_velocity[1] = 0.0;
    gbyk_v4b_B.hand_acceleration[0] = 0.0;
    gbyk_v4b_B.hand_acceleration[1] = 0.0;
    gbyk_v4b_B.motor_status = 0.0;
    gbyk_v4b_B.force_sensor_force_uvw[0] = 0.0;
    gbyk_v4b_B.force_sensor_force_uvw[1] = 0.0;
    gbyk_v4b_B.force_sensor_force_uvw[2] = 0.0;
    gbyk_v4b_B.force_sensor_torque_uvw[0] = 0.0;
    gbyk_v4b_B.force_sensor_torque_uvw[1] = 0.0;
    gbyk_v4b_B.force_sensor_torque_uvw[2] = 0.0;
    gbyk_v4b_B.force_sensor_force_xyz[0] = 0.0;
    gbyk_v4b_B.force_sensor_force_xyz[1] = 0.0;
    gbyk_v4b_B.force_sensor_force_xyz[2] = 0.0;
    gbyk_v4b_B.force_sensor_torque_xyz[0] = 0.0;
    gbyk_v4b_B.force_sensor_torque_xyz[1] = 0.0;
    gbyk_v4b_B.force_sensor_torque_xyz[2] = 0.0;
    gbyk_v4b_B.force_sensor_timestamp = 0.0;
    gbyk_v4b_B.link_lengths_o[0] = 0.0;
    gbyk_v4b_B.link_lengths_o[1] = 0.0;
    gbyk_v4b_B.pointer_offset_k = 0.0;
    gbyk_v4b_B.shoulder_loc_o[0] = 0.0;
    gbyk_v4b_B.shoulder_loc_o[1] = 0.0;
    gbyk_v4b_B.arm_orientation_o = 0.0;
    gbyk_v4b_B.shoulder_ang_h = 0.0;
    gbyk_v4b_B.elbow_ang_k = 0.0;
    gbyk_v4b_B.shoulder_velocity_k = 0.0;
    gbyk_v4b_B.elbow_velocity_j = 0.0;
    gbyk_v4b_B.shoulder_acceleration_c = 0.0;
    gbyk_v4b_B.elbow_acceleration_j = 0.0;
    gbyk_v4b_B.joint_torque_cmd_k[0] = 0.0;
    gbyk_v4b_B.joint_torque_cmd_k[1] = 0.0;
    gbyk_v4b_B.motor_torque_cmd_b[0] = 0.0;
    gbyk_v4b_B.motor_torque_cmd_b[1] = 0.0;
    gbyk_v4b_B.link_angle_b[0] = 0.0;
    gbyk_v4b_B.link_angle_b[1] = 0.0;
    gbyk_v4b_B.link_velocity_k[0] = 0.0;
    gbyk_v4b_B.link_velocity_k[1] = 0.0;
    gbyk_v4b_B.link_acceleration_c[0] = 0.0;
    gbyk_v4b_B.link_acceleration_c[1] = 0.0;
    gbyk_v4b_B.hand_position_g[0] = 0.0;
    gbyk_v4b_B.hand_position_g[1] = 0.0;
    gbyk_v4b_B.hand_velocity_p[0] = 0.0;
    gbyk_v4b_B.hand_velocity_p[1] = 0.0;
    gbyk_v4b_B.hand_acceleration_e[0] = 0.0;
    gbyk_v4b_B.hand_acceleration_e[1] = 0.0;
    gbyk_v4b_B.motor_status_c = 0.0;
    gbyk_v4b_B.force_sensor_force_uvw_g[0] = 0.0;
    gbyk_v4b_B.force_sensor_force_uvw_g[1] = 0.0;
    gbyk_v4b_B.force_sensor_force_uvw_g[2] = 0.0;
    gbyk_v4b_B.force_sensor_torque_uvw_d[0] = 0.0;
    gbyk_v4b_B.force_sensor_torque_uvw_d[1] = 0.0;
    gbyk_v4b_B.force_sensor_torque_uvw_d[2] = 0.0;
    gbyk_v4b_B.force_sensor_force_xyz_g[0] = 0.0;
    gbyk_v4b_B.force_sensor_force_xyz_g[1] = 0.0;
    gbyk_v4b_B.force_sensor_force_xyz_g[2] = 0.0;
    gbyk_v4b_B.force_sensor_torque_xyz_g[0] = 0.0;
    gbyk_v4b_B.force_sensor_torque_xyz_g[1] = 0.0;
    gbyk_v4b_B.force_sensor_torque_xyz_g[2] = 0.0;
    gbyk_v4b_B.force_sensor_timestamp_k = 0.0;
    gbyk_v4b_B.DelayRead[0] = 0.0;
    gbyk_v4b_B.DelayRead[1] = 0.0;
    gbyk_v4b_B.DelayRead[2] = 0.0;
    gbyk_v4b_B.DelayRead[3] = 0.0;
    gbyk_v4b_B.sentMessageCount = 0.0;
    gbyk_v4b_B.DataTypeConversion3_l[0] = 0.0;
    gbyk_v4b_B.DataTypeConversion3_l[1] = 0.0;
    gbyk_v4b_B.DataTypeConversion3_l[2] = 0.0;
    gbyk_v4b_B.DataTypeConversion3_l[3] = 0.0;
    gbyk_v4b_B.TmpSignalConversionAtSFunctionInport2_l[0] = 0.0;
    gbyk_v4b_B.TmpSignalConversionAtSFunctionInport2_l[1] = 0.0;
    gbyk_v4b_B.TmpSignalConversionAtSFunctionInport2_l[2] = 0.0;
    gbyk_v4b_B.TmpSignalConversionAtSFunctionInport2_l[3] = 0.0;
    gbyk_v4b_B.TmpSignalConversionAtSFunctionInport4[0] = 0.0;
    gbyk_v4b_B.TmpSignalConversionAtSFunctionInport4[1] = 0.0;
    gbyk_v4b_B.TmpSignalConversionAtSFunctionInport2_b[0] = 0.0;
    gbyk_v4b_B.TmpSignalConversionAtSFunctionInport2_b[1] = 0.0;
    gbyk_v4b_B.TmpSignalConversionAtSFunctionInport3_h[0] = 0.0;
    gbyk_v4b_B.TmpSignalConversionAtSFunctionInport3_h[1] = 0.0;
    gbyk_v4b_B.TmpSignalConversionAtSFunctionInport4_i[0] = 0.0;
    gbyk_v4b_B.TmpSignalConversionAtSFunctionInport4_i[1] = 0.0;
    gbyk_v4b_B.TmpSignalConversionAtSFunctionInport1_p[0] = 0.0;
    gbyk_v4b_B.TmpSignalConversionAtSFunctionInport1_p[1] = 0.0;
    gbyk_v4b_B.TmpSignalConversionAtSFunctionInport1_p[2] = 0.0;
    gbyk_v4b_B.TmpSignalConversionAtSFunctionInport1_p[3] = 0.0;
    gbyk_v4b_B.TmpSignalConversionAtSFunctionInport2_bj[0] = 0.0;
    gbyk_v4b_B.TmpSignalConversionAtSFunctionInport2_bj[1] = 0.0;
    gbyk_v4b_B.TmpSignalConversionAtSFunctionInport2_bj[2] = 0.0;
    gbyk_v4b_B.TmpSignalConversionAtSFunctionInport2_bj[3] = 0.0;
    gbyk_v4b_B.TmpSignalConversionAtSFunctionInport3_g[0] = 0.0;
    gbyk_v4b_B.TmpSignalConversionAtSFunctionInport3_g[1] = 0.0;
    gbyk_v4b_B.TmpSignalConversionAtSFunctionInport3_g[2] = 0.0;
    gbyk_v4b_B.TmpSignalConversionAtSFunctionInport3_g[3] = 0.0;
    gbyk_v4b_B.TmpSignalConversionAtSFunctionInport4_b[0] = 0.0;
    gbyk_v4b_B.TmpSignalConversionAtSFunctionInport4_b[1] = 0.0;
    gbyk_v4b_B.TmpSignalConversionAtSFunctionInport6[0] = 0.0;
    gbyk_v4b_B.TmpSignalConversionAtSFunctionInport6[1] = 0.0;
    gbyk_v4b_B.TmpSignalConversionAtSFunctionInport8[0] = 0.0;
    gbyk_v4b_B.TmpSignalConversionAtSFunctionInport8[1] = 0.0;
    gbyk_v4b_B.delays[0] = 0.0;
    gbyk_v4b_B.delays[1] = 0.0;
    gbyk_v4b_B.delays[2] = 0.0;
    gbyk_v4b_B.delays[3] = 0.0;
    gbyk_v4b_B.TmpSignalConversionAtSFunctionInport1_l[0] = 0.0;
    gbyk_v4b_B.TmpSignalConversionAtSFunctionInport1_l[1] = 0.0;
    gbyk_v4b_B.TmpSignalConversionAtSFunctionInport1_l[2] = 0.0;
    gbyk_v4b_B.TmpSignalConversionAtSFunctionInport1_l[3] = 0.0;
    gbyk_v4b_B.filteredVels[0] = 0.0;
    gbyk_v4b_B.filteredVels[1] = 0.0;
    gbyk_v4b_B.filteredVels[2] = 0.0;
    gbyk_v4b_B.filteredVels[3] = 0.0;
    gbyk_v4b_B.Receive_o2_o = 0.0;
    gbyk_v4b_B.DataTypeConversion_k[0] = 0.0;
    gbyk_v4b_B.DataTypeConversion_k[1] = 0.0;
    gbyk_v4b_B.DataTypeConversion1_a[0] = 0.0;
    gbyk_v4b_B.DataTypeConversion1_a[1] = 0.0;
    gbyk_v4b_B.DataTypeConversion2_i = 0.0;
    gbyk_v4b_B.UnitDelay = 0.0;
    gbyk_v4b_B.DPRAMReadValue = 0.0;
    gbyk_v4b_B.UnitDelay1 = 0.0;
    gbyk_v4b_B.Conversion7[0] = 0.0;
    gbyk_v4b_B.Conversion7[1] = 0.0;
    gbyk_v4b_B.Conversion7[2] = 0.0;
    gbyk_v4b_B.Conversion7[3] = 0.0;
    gbyk_v4b_B.force_scale = 0.0;
    gbyk_v4b_B.DataTypeConversion1_j = 0.0;
    gbyk_v4b_B.Uk1 = 0.0;
    gbyk_v4b_B.ReceivefromRobot1ForceSensor_o2 = 0.0;
    gbyk_v4b_B.Uk1_p = 0.0;
    gbyk_v4b_B.ReceivefromRobot2ForceSensor_o2 = 0.0;
    gbyk_v4b_B.Memory_m = 0.0;
    gbyk_v4b_B.Memory_i = 0.0;
    gbyk_v4b_B.Memory1_e = 0.0;
    gbyk_v4b_B.Memory2 = 0.0;
    gbyk_v4b_B.offsetrads = 0.0;
    gbyk_v4b_B.encorient = 0.0;
    gbyk_v4b_B.L2select2 = 0.0;
    gbyk_v4b_B.L2select3 = 0.0;
    gbyk_v4b_B.L2select4 = 0.0;
    gbyk_v4b_B.R2_maxContinuousTorque[0] = 0.0;
    gbyk_v4b_B.R2_maxContinuousTorque[1] = 0.0;
    gbyk_v4b_B.L2select5 = 0.0;
    gbyk_v4b_B.R2_constantsReady = 0.0;
    gbyk_v4b_B.L2select = 0.0;
    gbyk_v4b_B.L2select1 = 0.0;
    gbyk_v4b_B.L2select2_p = 0.0;
    gbyk_v4b_B.L2select3_c = 0.0;
    gbyk_v4b_B.L2select4_b = 0.0;
    gbyk_v4b_B.L2select5_a = 0.0;
    gbyk_v4b_B.R2M1_LinkAngle = 0.0;
    gbyk_v4b_B.R2M2_LinkAngle = 0.0;
    gbyk_v4b_B.R2M2_PrimaryLinkAngle = 0.0;
    gbyk_v4b_B.R2M2_PrimaryLinkVelocity = 0.0;
    gbyk_v4b_B.R2M2_RecordedTorque = 0.0;
    gbyk_v4b_B.R2M2_digitalInputs[0] = 0.0;
    gbyk_v4b_B.R2M2_digitalInputs[1] = 0.0;
    gbyk_v4b_B.R2M2_digitalDiagnostics = 0.0;
    gbyk_v4b_B.R2M1_PrimaryLinkAngle = 0.0;
    gbyk_v4b_B.R2M1_PrimaryLinkVelocity = 0.0;
    gbyk_v4b_B.R2M1_RecordedTorque = 0.0;
    gbyk_v4b_B.R2M1_digitalInputs[0] = 0.0;
    gbyk_v4b_B.R2M1_digitalInputs[1] = 0.0;
    gbyk_v4b_B.R2M1_digitalDiagnostics = 0.0;
    gbyk_v4b_B.R2_calibrationButton = 0.0;
    gbyk_v4b_B.R2_RobotType = 0.0;
    gbyk_v4b_B.R2_absAngleOffset[0] = 0.0;
    gbyk_v4b_B.R2_absAngleOffset[1] = 0.0;
    gbyk_v4b_B.R2_LinkLength[0] = 0.0;
    gbyk_v4b_B.R2_LinkLength[1] = 0.0;
    gbyk_v4b_B.R2_L2CalibPinOffset = 0.0;
    gbyk_v4b_B.R2_maxContinuousTorque_e[0] = 0.0;
    gbyk_v4b_B.R2_maxContinuousTorque_e[1] = 0.0;
    gbyk_v4b_B.R2_gearRatios[0] = 0.0;
    gbyk_v4b_B.R2_gearRatios[1] = 0.0;
    gbyk_v4b_B.R2_isCalibrated = 0.0;
    gbyk_v4b_B.R2_OffsetRads[0] = 0.0;
    gbyk_v4b_B.R2_OffsetRads[1] = 0.0;
    gbyk_v4b_B.R2_OffsetRadsPrimary[0] = 0.0;
    gbyk_v4b_B.R2_OffsetRadsPrimary[1] = 0.0;
    gbyk_v4b_B.R2_RobotRevision = 0.0;
    gbyk_v4b_B.R2_constantsReady_j = 0.0;
    gbyk_v4b_B.R2_hasSecondary = 0.0;
    gbyk_v4b_B.R2_hasFT = 0.0;
    gbyk_v4b_B.R2_robotOrientation = 0.0;
    gbyk_v4b_B.R2_motorOrientation[0] = 0.0;
    gbyk_v4b_B.R2_motorOrientation[1] = 0.0;
    gbyk_v4b_B.R2_encOrientation[0] = 0.0;
    gbyk_v4b_B.R2_encOrientation[1] = 0.0;
    gbyk_v4b_B.R2_encodercounts[0] = 0.0;
    gbyk_v4b_B.R2_encodercounts[1] = 0.0;
    gbyk_v4b_B.R2_FTSensorAngleOffset = 0.0;
    gbyk_v4b_B.R2_calibPinAngle[0] = 0.0;
    gbyk_v4b_B.R2_calibPinAngle[1] = 0.0;
    gbyk_v4b_B.RateTransition1_d = 0.0;
    gbyk_v4b_B.RateTransition2_j = 0.0;
    gbyk_v4b_B.encoderCounts[0] = 0.0;
    gbyk_v4b_B.encoderCounts[1] = 0.0;
    gbyk_v4b_B.FTSensorOffset = 0.0;
    gbyk_v4b_B.calibPinAngles[0] = 0.0;
    gbyk_v4b_B.calibPinAngles[1] = 0.0;
    gbyk_v4b_B.absAngOffsets[0] = 0.0;
    gbyk_v4b_B.absAngOffsets[1] = 0.0;
    gbyk_v4b_B.linkLengths[0] = 0.0;
    gbyk_v4b_B.linkLengths[1] = 0.0;
    gbyk_v4b_B.L2CalibPinOffset = 0.0;
    gbyk_v4b_B.continuousTorques[0] = 0.0;
    gbyk_v4b_B.continuousTorques[1] = 0.0;
    gbyk_v4b_B.gearRatios[0] = 0.0;
    gbyk_v4b_B.gearRatios[1] = 0.0;
    gbyk_v4b_B.isCalibrated = 0.0;
    gbyk_v4b_B.offsetRads[0] = 0.0;
    gbyk_v4b_B.offsetRads[1] = 0.0;
    gbyk_v4b_B.offsetRadsPrimary[0] = 0.0;
    gbyk_v4b_B.offsetRadsPrimary[1] = 0.0;
    gbyk_v4b_B.robotRevision_o = 0.0;
    gbyk_v4b_B.constantsReady = 0.0;
    gbyk_v4b_B.DataTypeConversion_iq = 0.0;
    gbyk_v4b_B.status = 0.0;
    gbyk_v4b_B.readAddr[0] = 0.0;
    gbyk_v4b_B.readAddr[1] = 0.0;
    gbyk_v4b_B.readAddr[2] = 0.0;
    gbyk_v4b_B.Memory_ip = 0.0;
    gbyk_v4b_B.convert_l = 0.0;
    gbyk_v4b_B.convert1 = 0.0;
    gbyk_v4b_B.status_e = 0.0;
    gbyk_v4b_B.DataTypeConversion_d = 0.0;
    gbyk_v4b_B.LinkAngle = 0.0;
    gbyk_v4b_B.PrimaryLinkAngle = 0.0;
    gbyk_v4b_B.PrimaryLinkVel = 0.0;
    gbyk_v4b_B.torque = 0.0;
    gbyk_v4b_B.digitalInputs[0] = 0.0;
    gbyk_v4b_B.digitalInputs[1] = 0.0;
    gbyk_v4b_B.digitalDiagnostics = 0.0;
    gbyk_v4b_B.DataTypeConversion_j = 0.0;
    gbyk_v4b_B.driveID = 0.0;
    gbyk_v4b_B.DataTypeConversion2_g[0] = 0.0;
    gbyk_v4b_B.DataTypeConversion2_g[1] = 0.0;
    gbyk_v4b_B.DataTypeConversion_i1[0] = 0.0;
    gbyk_v4b_B.DataTypeConversion_i1[1] = 0.0;
    gbyk_v4b_B.Memory_l = 0.0;
    gbyk_v4b_B.DataTypeConversion1_c = 0.0;
    gbyk_v4b_B.isPermFaulted = 0.0;
    gbyk_v4b_B.LinkAngle_l = 0.0;
    gbyk_v4b_B.PrimaryLinkAngle_f = 0.0;
    gbyk_v4b_B.PrimaryLinkVel_i = 0.0;
    gbyk_v4b_B.torque_f = 0.0;
    gbyk_v4b_B.digitalInputs_m[0] = 0.0;
    gbyk_v4b_B.digitalInputs_m[1] = 0.0;
    gbyk_v4b_B.digitalDiagnostics_c = 0.0;
    gbyk_v4b_B.calibrationButton = 0.0;
    gbyk_v4b_B.DataTypeConversion_bd = 0.0;
    gbyk_v4b_B.driveID_n = 0.0;
    gbyk_v4b_B.DataTypeConversion2_nh[0] = 0.0;
    gbyk_v4b_B.DataTypeConversion2_nh[1] = 0.0;
    gbyk_v4b_B.DataTypeConversion_p[0] = 0.0;
    gbyk_v4b_B.DataTypeConversion_p[1] = 0.0;
    gbyk_v4b_B.Memory_g = 0.0;
    gbyk_v4b_B.DataTypeConversion1_k = 0.0;
    gbyk_v4b_B.Memory_j = 0.0;
    gbyk_v4b_B.Memory_f = 0.0;
    gbyk_v4b_B.Memory1_o = 0.0;
    gbyk_v4b_B.Memory2_n = 0.0;
    gbyk_v4b_B.L2select_i = 0.0;
    gbyk_v4b_B.L2select1_h = 0.0;
    gbyk_v4b_B.L2select2_o = 0.0;
    gbyk_v4b_B.L2select3_cn = 0.0;
    gbyk_v4b_B.L2select4_o = 0.0;
    gbyk_v4b_B.R1_maxContinuousTorque[0] = 0.0;
    gbyk_v4b_B.R1_maxContinuousTorque[1] = 0.0;
    gbyk_v4b_B.L2select5_c = 0.0;
    gbyk_v4b_B.R1_constantsReady = 0.0;
    gbyk_v4b_B.L2select_e = 0.0;
    gbyk_v4b_B.L2select1_hf = 0.0;
    gbyk_v4b_B.L2select2_d = 0.0;
    gbyk_v4b_B.L2select3_p = 0.0;
    gbyk_v4b_B.L2select4_g = 0.0;
    gbyk_v4b_B.L2select5_f = 0.0;
    gbyk_v4b_B.R1M1_LinkAngle = 0.0;
    gbyk_v4b_B.R1M2_LinkAngle = 0.0;
    gbyk_v4b_B.R1M2_PrimaryLinkAngle = 0.0;
    gbyk_v4b_B.R1M2_PrimaryLinkVelocity = 0.0;
    gbyk_v4b_B.R1M2_RecordedTorque = 0.0;
    gbyk_v4b_B.R1M2_digitalInputs[0] = 0.0;
    gbyk_v4b_B.R1M2_digitalInputs[1] = 0.0;
    gbyk_v4b_B.R1M2_digitalDiagnostics = 0.0;
    gbyk_v4b_B.R1M1_PrimaryLinkAngle = 0.0;
    gbyk_v4b_B.R1M1_PrimaryLinkVelocity = 0.0;
    gbyk_v4b_B.R1M1_RecordedTorque = 0.0;
    gbyk_v4b_B.R1M1_digitalInputs[0] = 0.0;
    gbyk_v4b_B.R1M1_digitalInputs[1] = 0.0;
    gbyk_v4b_B.R1M1_digitalDiagnostics = 0.0;
    gbyk_v4b_B.R1_calibrationButton = 0.0;
    gbyk_v4b_B.R1_RobotType = 0.0;
    gbyk_v4b_B.R1_absAngleOffset[0] = 0.0;
    gbyk_v4b_B.R1_absAngleOffset[1] = 0.0;
    gbyk_v4b_B.R1_LinkLength[0] = 0.0;
    gbyk_v4b_B.R1_LinkLength[1] = 0.0;
    gbyk_v4b_B.R1_L2CalibPinOffset = 0.0;
    gbyk_v4b_B.R1_maxContinuousTorque_d[0] = 0.0;
    gbyk_v4b_B.R1_maxContinuousTorque_d[1] = 0.0;
    gbyk_v4b_B.R1_gearRatios[0] = 0.0;
    gbyk_v4b_B.R1_gearRatios[1] = 0.0;
    gbyk_v4b_B.R1_isCalibrated = 0.0;
    gbyk_v4b_B.R1_OffsetRads[0] = 0.0;
    gbyk_v4b_B.R1_OffsetRads[1] = 0.0;
    gbyk_v4b_B.R1_OffsetRadsPrimary[0] = 0.0;
    gbyk_v4b_B.R1_OffsetRadsPrimary[1] = 0.0;
    gbyk_v4b_B.R1_RobotRevision = 0.0;
    gbyk_v4b_B.R1_constantsReady_p = 0.0;
    gbyk_v4b_B.R1_hasSecondary = 0.0;
    gbyk_v4b_B.R1_hasFT = 0.0;
    gbyk_v4b_B.R1_robotOrientation = 0.0;
    gbyk_v4b_B.R1_motorOrientation[0] = 0.0;
    gbyk_v4b_B.R1_motorOrientation[1] = 0.0;
    gbyk_v4b_B.R1_encOrientation[0] = 0.0;
    gbyk_v4b_B.R1_encOrientation[1] = 0.0;
    gbyk_v4b_B.R1_encodercounts[0] = 0.0;
    gbyk_v4b_B.R1_encodercounts[1] = 0.0;
    gbyk_v4b_B.R1_FTSensorAngleOffset = 0.0;
    gbyk_v4b_B.R1_calibPinAngle[0] = 0.0;
    gbyk_v4b_B.R1_calibPinAngle[1] = 0.0;
    gbyk_v4b_B.RateTransition1_ds = 0.0;
    gbyk_v4b_B.RateTransition2_dj = 0.0;
    gbyk_v4b_B.encoderCounts_h[0] = 0.0;
    gbyk_v4b_B.encoderCounts_h[1] = 0.0;
    gbyk_v4b_B.FTSensorOffset_j = 0.0;
    gbyk_v4b_B.calibPinAngles_m[0] = 0.0;
    gbyk_v4b_B.calibPinAngles_m[1] = 0.0;
    gbyk_v4b_B.absAngOffsets_c[0] = 0.0;
    gbyk_v4b_B.absAngOffsets_c[1] = 0.0;
    gbyk_v4b_B.linkLengths_j[0] = 0.0;
    gbyk_v4b_B.linkLengths_j[1] = 0.0;
    gbyk_v4b_B.L2CalibPinOffset_c = 0.0;
    gbyk_v4b_B.continuousTorques_j[0] = 0.0;
    gbyk_v4b_B.continuousTorques_j[1] = 0.0;
    gbyk_v4b_B.gearRatios_p[0] = 0.0;
    gbyk_v4b_B.gearRatios_p[1] = 0.0;
    gbyk_v4b_B.isCalibrated_p = 0.0;
    gbyk_v4b_B.offsetRads_f[0] = 0.0;
    gbyk_v4b_B.offsetRads_f[1] = 0.0;
    gbyk_v4b_B.offsetRadsPrimary_h[0] = 0.0;
    gbyk_v4b_B.offsetRadsPrimary_h[1] = 0.0;
    gbyk_v4b_B.robotRevision_n = 0.0;
    gbyk_v4b_B.constantsReady_j = 0.0;
    gbyk_v4b_B.DataTypeConversion_f = 0.0;
    gbyk_v4b_B.status_n = 0.0;
    gbyk_v4b_B.readAddr_p[0] = 0.0;
    gbyk_v4b_B.readAddr_p[1] = 0.0;
    gbyk_v4b_B.readAddr_p[2] = 0.0;
    gbyk_v4b_B.Memory_n = 0.0;
    gbyk_v4b_B.convert_b = 0.0;
    gbyk_v4b_B.convert1_f = 0.0;
    gbyk_v4b_B.status_d = 0.0;
    gbyk_v4b_B.DataTypeConversion_ba = 0.0;
    gbyk_v4b_B.LinkAngle_g = 0.0;
    gbyk_v4b_B.PrimaryLinkAngle_b = 0.0;
    gbyk_v4b_B.PrimaryLinkVel_d = 0.0;
    gbyk_v4b_B.torque_g = 0.0;
    gbyk_v4b_B.digitalInputs_h[0] = 0.0;
    gbyk_v4b_B.digitalInputs_h[1] = 0.0;
    gbyk_v4b_B.digitalDiagnostics_a = 0.0;
    gbyk_v4b_B.DataTypeConversion_kb = 0.0;
    gbyk_v4b_B.driveID_a = 0.0;
    gbyk_v4b_B.DataTypeConversion2_d[0] = 0.0;
    gbyk_v4b_B.DataTypeConversion2_d[1] = 0.0;
    gbyk_v4b_B.DataTypeConversion_m[0] = 0.0;
    gbyk_v4b_B.DataTypeConversion_m[1] = 0.0;
    gbyk_v4b_B.Memory_d = 0.0;
    gbyk_v4b_B.DataTypeConversion1_i = 0.0;
    gbyk_v4b_B.emcyValPump[0] = 0.0;
    gbyk_v4b_B.emcyValPump[1] = 0.0;
    gbyk_v4b_B.emcyValPump[2] = 0.0;
    gbyk_v4b_B.LinkAngle_c = 0.0;
    gbyk_v4b_B.PrimaryLinkAngle_m = 0.0;
    gbyk_v4b_B.PrimaryLinkVel_m = 0.0;
    gbyk_v4b_B.torque_d = 0.0;
    gbyk_v4b_B.digitalInputs_e[0] = 0.0;
    gbyk_v4b_B.digitalInputs_e[1] = 0.0;
    gbyk_v4b_B.digitalDiagnostics_e = 0.0;
    gbyk_v4b_B.calibrationButton_e = 0.0;
    gbyk_v4b_B.DataTypeConversion_c = 0.0;
    gbyk_v4b_B.driveID_n2 = 0.0;
    gbyk_v4b_B.DataTypeConversion2_j[0] = 0.0;
    gbyk_v4b_B.DataTypeConversion2_j[1] = 0.0;
    gbyk_v4b_B.DataTypeConversion_hm[0] = 0.0;
    gbyk_v4b_B.DataTypeConversion_hm[1] = 0.0;
    gbyk_v4b_B.Memory_dp = 0.0;
    gbyk_v4b_B.DataTypeConversion1_av = 0.0;
    gbyk_v4b_B.emcyValPump_g[0] = 0.0;
    gbyk_v4b_B.emcyValPump_g[1] = 0.0;
    gbyk_v4b_B.emcyValPump_g[2] = 0.0;
    gbyk_v4b_B.isPermFaulted_i = 0.0;
    gbyk_v4b_B.RateTransition_g = 0.0;
    gbyk_v4b_B.RateTransition1_h3 = 0.0;
    gbyk_v4b_B.Receive1_o2 = 0.0;
    gbyk_v4b_B.forces[0] = 0.0;
    gbyk_v4b_B.forces[1] = 0.0;
    gbyk_v4b_B.forces[2] = 0.0;
    gbyk_v4b_B.moments[0] = 0.0;
    gbyk_v4b_B.moments[1] = 0.0;
    gbyk_v4b_B.moments[2] = 0.0;
    gbyk_v4b_B.timer = 0.0;
    gbyk_v4b_B.Receive_o2_m = 0.0;
    gbyk_v4b_B.forces_g[0] = 0.0;
    gbyk_v4b_B.forces_g[1] = 0.0;
    gbyk_v4b_B.forces_g[2] = 0.0;
    gbyk_v4b_B.moments_p[0] = 0.0;
    gbyk_v4b_B.moments_p[1] = 0.0;
    gbyk_v4b_B.moments_p[2] = 0.0;
    gbyk_v4b_B.timer_c = 0.0;
    gbyk_v4b_B.trigger = 0.0;
    gbyk_v4b_B.RateTransition2_js[0] = 0.0;
    gbyk_v4b_B.RateTransition2_js[1] = 0.0;
    gbyk_v4b_B.RateTransition2_js[2] = 0.0;
    gbyk_v4b_B.Pckt_Recd = 0.0;
    gbyk_v4b_B.Pckt_Recd2 = 0.0;
    gbyk_v4b_B.doublereads = 0.0;
    gbyk_v4b_B.UDPReceive_o6 = 0.0;
    gbyk_v4b_B.TmpRTBAtforcestrobeOutport1 = 0.0;
    gbyk_v4b_B.TaskClock_a = 0.0;
    gbyk_v4b_B.queue_size = 0.0;
    gbyk_v4b_B.timeouts = 0.0;
    gbyk_v4b_B.RqstUDPReset = 0.0;
    gbyk_v4b_B.UDPResets = 0.0;
    gbyk_v4b_B.UDPReceivePortReset_o2[0] = 0.0;
    gbyk_v4b_B.UDPReceivePortReset_o2[1] = 0.0;
    gbyk_v4b_B.UDPReceivePortReset_o2[2] = 0.0;
    gbyk_v4b_B.strobe_out = 0.0;
    gbyk_v4b_B.resetUDP = 0.0;
    gbyk_v4b_B.queue_size_e = 0.0;
    gbyk_v4b_B.total_timeouts = 0.0;
    gbyk_v4b_B.UnitDelay_h = 0.0;
    gbyk_v4b_B.Sum = 0.0;
    gbyk_v4b_B.Width = 0.0;
    gbyk_v4b_B.IdealFramesPerPacket = 0.0;
    gbyk_v4b_B.MinMax_k = 0.0;
    gbyk_v4b_B.MathFunction_j = 0.0;
    gbyk_v4b_B.Subtract_o = 0.0;
    gbyk_v4b_B.Product_l = 0.0;
    gbyk_v4b_B.dd_out[0] = 0.0;
    gbyk_v4b_B.dd_out[1] = 0.0;
    gbyk_v4b_B.DataTypeConversion6[0] = 0.0F;
    gbyk_v4b_B.DataTypeConversion6[1] = 0.0F;
    gbyk_v4b_B.DataTypeConversion6[2] = 0.0F;
    gbyk_v4b_B.DataTypeConversion6[3] = 0.0F;
    gbyk_v4b_B.pupilX[0] = 0.0F;
    gbyk_v4b_B.pupilX[1] = 0.0F;
    gbyk_v4b_B.pupilY[0] = 0.0F;
    gbyk_v4b_B.pupilY[1] = 0.0F;
    gbyk_v4b_B.HREFX[0] = 0.0F;
    gbyk_v4b_B.HREFX[1] = 0.0F;
    gbyk_v4b_B.HREFY[0] = 0.0F;
    gbyk_v4b_B.HREFY[1] = 0.0F;
    gbyk_v4b_B.pupilarea[0] = 0.0F;
    gbyk_v4b_B.pupilarea[1] = 0.0F;
    gbyk_v4b_B.screengazeX[0] = 0.0F;
    gbyk_v4b_B.screengazeX[1] = 0.0F;
    gbyk_v4b_B.screengazeY[0] = 0.0F;
    gbyk_v4b_B.screengazeY[1] = 0.0F;
    gbyk_v4b_B.resolutionX = 0.0F;
    gbyk_v4b_B.resolutionY = 0.0F;
    gbyk_v4b_B.SelectorLeftEye[0] = 0.0F;
    gbyk_v4b_B.SelectorLeftEye[1] = 0.0F;
    gbyk_v4b_B.SelectorLeftEye[2] = 0.0F;
    gbyk_v4b_B.SelectorLeftEye[3] = 0.0F;
    gbyk_v4b_B.Unpack_o1[0] = 0.0F;
    gbyk_v4b_B.Unpack_o1[1] = 0.0F;
    gbyk_v4b_B.Unpack_o2[0] = 0.0F;
    gbyk_v4b_B.Unpack_o2[1] = 0.0F;
    gbyk_v4b_B.DataTypeConversion2_h = 0.0F;
    gbyk_v4b_B.SFunction_o4[0] = 0.0F;
    gbyk_v4b_B.SFunction_o4[1] = 0.0F;
    gbyk_v4b_B.SFunction_o4[2] = 0.0F;
    gbyk_v4b_B.SFunction_o4[3] = 0.0F;
    gbyk_v4b_B.SFunction_o10 = 0.0F;
    gbyk_v4b_B.y_j = 0.0F;
    gbyk_v4b_B.DataTypeConversion1_o = 0.0F;
    gbyk_v4b_B.Read_h = 0.0F;
    gbyk_v4b_B.DataTypeConversion2_k = 0.0F;
    gbyk_v4b_B.Unpack = 0.0F;
    gbyk_v4b_B.sf_EmbeddedMATLABWhichHand.hand = 0.0;
    gbyk_v4b_B.sf_EmbeddedMATLABWhichHand_k.hand = 0.0;
    gbyk_v4b_B.sf_EmbeddedMATLABWhichHand_d.hand = 0.0;
    gbyk_v4b_B.sf_MATLABFunction1.is_right_arm = 0.0;
    gbyk_v4b_B.sf_MATLABFunction1.isExo = 0.0;
    gbyk_v4b_B.sf_MATLABFunction1.has_high_res_encoders = 0.0;
    gbyk_v4b_B.sf_MATLABFunction_o.is_right_arm = 0.0;
    gbyk_v4b_B.sf_MATLABFunction_o.isExo = 0.0;
    gbyk_v4b_B.sf_MATLABFunction_o.has_high_res_encoders = 0.0;
    gbyk_v4b_B.sf_split_primary1.link_angles[0] = 0.0;
    gbyk_v4b_B.sf_split_primary1.link_angles[1] = 0.0;
    gbyk_v4b_B.sf_split_primary1.link_velocities[0] = 0.0;
    gbyk_v4b_B.sf_split_primary1.link_velocities[1] = 0.0;
    gbyk_v4b_B.sf_split_primary1.link_acceleration[0] = 0.0;
    gbyk_v4b_B.sf_split_primary1.link_acceleration[1] = 0.0;
    gbyk_v4b_B.sf_split_primary.link_angles[0] = 0.0;
    gbyk_v4b_B.sf_split_primary.link_angles[1] = 0.0;
    gbyk_v4b_B.sf_split_primary.link_velocities[0] = 0.0;
    gbyk_v4b_B.sf_split_primary.link_velocities[1] = 0.0;
    gbyk_v4b_B.sf_split_primary.link_acceleration[0] = 0.0;
    gbyk_v4b_B.sf_split_primary.link_acceleration[1] = 0.0;
    gbyk_v4b_B.sf_decoderobot_p.isEP = 0.0;
    gbyk_v4b_B.sf_decoderobot_p.isHumanEXO = 0.0;
    gbyk_v4b_B.sf_decoderobot_p.isNHPEXO = 0.0;
    gbyk_v4b_B.sf_decoderobot_p.isClassicExo = 0.0;
    gbyk_v4b_B.sf_decoderobot_p.isUTSEXO = 0.0;
    gbyk_v4b_B.sf_decoderobot_p.isPMAC = 0.0;
    gbyk_v4b_B.sf_decoderobot_p.isECAT = 0.0;
    gbyk_v4b_B.sf_decoderobot.isEP = 0.0;
    gbyk_v4b_B.sf_decoderobot.isHumanEXO = 0.0;
    gbyk_v4b_B.sf_decoderobot.isNHPEXO = 0.0;
    gbyk_v4b_B.sf_decoderobot.isClassicExo = 0.0;
    gbyk_v4b_B.sf_decoderobot.isUTSEXO = 0.0;
    gbyk_v4b_B.sf_decoderobot.isPMAC = 0.0;
    gbyk_v4b_B.sf_decoderobot.isECAT = 0.0;
    gbyk_v4b_B.sf_Createtimestamp_b.timestamp_out = 0.0;
    gbyk_v4b_B.sf_Createtimestamp.timestamp_out = 0.0;
    gbyk_v4b_B.sf_splitoutconstants1_o.hasSecondary = 0.0;
    gbyk_v4b_B.sf_splitoutconstants1_o.hasFT = 0.0;
    gbyk_v4b_B.sf_splitoutconstants1_o.robotOrientation = 0.0;
    gbyk_v4b_B.sf_splitoutconstants1_o.motorOrientation[0] = 0.0;
    gbyk_v4b_B.sf_splitoutconstants1_o.motorOrientation[1] = 0.0;
    gbyk_v4b_B.sf_splitoutconstants1_o.encOrientation[0] = 0.0;
    gbyk_v4b_B.sf_splitoutconstants1_o.encOrientation[1] = 0.0;
    gbyk_v4b_B.sf_size1_e.count = 0.0;
    gbyk_v4b_B.sf_size_d.count = 0.0;
    gbyk_v4b_B.sf_converter_jl.doubleOut = 0.0;
    gbyk_v4b_B.sf_forceEnableDisable_k.TmpSignalConversionAtSFunctionInport5[0] =
      0.0;
    gbyk_v4b_B.sf_forceEnableDisable_k.TmpSignalConversionAtSFunctionInport5[1] =
      0.0;
    gbyk_v4b_B.sf_forceEnableDisable_k.forceMotorState = 0.0;
    gbyk_v4b_B.sf_values_n.TmpSignalConversionAtSFunctionInport1[0] = 0.0;
    gbyk_v4b_B.sf_values_n.TmpSignalConversionAtSFunctionInport1[1] = 0.0;
    gbyk_v4b_B.sf_values_n.TmpSignalConversionAtSFunctionInport1[2] = 0.0;
    gbyk_v4b_B.sf_values_n.outVal[0] = 0.0;
    gbyk_v4b_B.sf_values_n.outVal[1] = 0.0;
    gbyk_v4b_B.sf_values_n.outVal[2] = 0.0;
    gbyk_v4b_B.sf_converter_j.doubleOut = 0.0;
    gbyk_v4b_B.sf_setupvalues_g.setupValuesCount = 0.0;
    gbyk_v4b_B.sf_setupvalues_g.pollValues[0] = 0.0;
    gbyk_v4b_B.sf_setupvalues_g.pollValues[1] = 0.0;
    gbyk_v4b_B.sf_setupvalues_g.pollValues[2] = 0.0;
    gbyk_v4b_B.sf_setupvalues_g.encoderValuesCount = 0.0;
    gbyk_v4b_B.sf_setupvalues_k.setupValuesCount = 0.0;
    gbyk_v4b_B.sf_setupvalues_k.pollValues[0] = 0.0;
    gbyk_v4b_B.sf_setupvalues_k.pollValues[1] = 0.0;
    gbyk_v4b_B.sf_setupvalues_k.pollValues[2] = 0.0;
    gbyk_v4b_B.sf_setupvalues_k.encoderValuesCount = 0.0;
    gbyk_v4b_B.sf_FindRobottype_d.robotType = 0.0;
    gbyk_v4b_B.sf_faultmonitor_i.triggerFaultRead = 0.0;
    gbyk_v4b_B.sf_ReadEMCY_p.emcyValPump[0] = 0.0;
    gbyk_v4b_B.sf_ReadEMCY_p.emcyValPump[1] = 0.0;
    gbyk_v4b_B.sf_ReadEMCY_p.emcyValPump[2] = 0.0;
    gbyk_v4b_B.sf_faultmonitor_f.triggerFaultRead = 0.0;
    gbyk_v4b_B.sf_ReadEMCY_i.emcyValPump[0] = 0.0;
    gbyk_v4b_B.sf_ReadEMCY_i.emcyValPump[1] = 0.0;
    gbyk_v4b_B.sf_ReadEMCY_i.emcyValPump[2] = 0.0;
    gbyk_v4b_B.sf_ControlGDCWhistleState_p.isPermFaulted = 0.0;
    gbyk_v4b_B.sf_splitoutconstants1.hasSecondary = 0.0;
    gbyk_v4b_B.sf_splitoutconstants1.hasFT = 0.0;
    gbyk_v4b_B.sf_splitoutconstants1.robotOrientation = 0.0;
    gbyk_v4b_B.sf_splitoutconstants1.motorOrientation[0] = 0.0;
    gbyk_v4b_B.sf_splitoutconstants1.motorOrientation[1] = 0.0;
    gbyk_v4b_B.sf_splitoutconstants1.encOrientation[0] = 0.0;
    gbyk_v4b_B.sf_splitoutconstants1.encOrientation[1] = 0.0;
    gbyk_v4b_B.sf_size1.count = 0.0;
    gbyk_v4b_B.sf_size.count = 0.0;
    gbyk_v4b_B.sf_converter_p.doubleOut = 0.0;
    gbyk_v4b_B.sf_forceEnableDisable.TmpSignalConversionAtSFunctionInport5[0] =
      0.0;
    gbyk_v4b_B.sf_forceEnableDisable.TmpSignalConversionAtSFunctionInport5[1] =
      0.0;
    gbyk_v4b_B.sf_forceEnableDisable.forceMotorState = 0.0;
    gbyk_v4b_B.sf_values.TmpSignalConversionAtSFunctionInport1[0] = 0.0;
    gbyk_v4b_B.sf_values.TmpSignalConversionAtSFunctionInport1[1] = 0.0;
    gbyk_v4b_B.sf_values.TmpSignalConversionAtSFunctionInport1[2] = 0.0;
    gbyk_v4b_B.sf_values.outVal[0] = 0.0;
    gbyk_v4b_B.sf_values.outVal[1] = 0.0;
    gbyk_v4b_B.sf_values.outVal[2] = 0.0;
    gbyk_v4b_B.sf_converter.doubleOut = 0.0;
    gbyk_v4b_B.sf_setupvalues_p.setupValuesCount = 0.0;
    gbyk_v4b_B.sf_setupvalues_p.pollValues[0] = 0.0;
    gbyk_v4b_B.sf_setupvalues_p.pollValues[1] = 0.0;
    gbyk_v4b_B.sf_setupvalues_p.pollValues[2] = 0.0;
    gbyk_v4b_B.sf_setupvalues_p.encoderValuesCount = 0.0;
    gbyk_v4b_B.sf_setupvalues.setupValuesCount = 0.0;
    gbyk_v4b_B.sf_setupvalues.pollValues[0] = 0.0;
    gbyk_v4b_B.sf_setupvalues.pollValues[1] = 0.0;
    gbyk_v4b_B.sf_setupvalues.pollValues[2] = 0.0;
    gbyk_v4b_B.sf_setupvalues.encoderValuesCount = 0.0;
    gbyk_v4b_B.sf_FindRobottype.robotType = 0.0;
    gbyk_v4b_B.sf_faultmonitor_k.triggerFaultRead = 0.0;
    gbyk_v4b_B.sf_ControlGDCWhistleState_f.isPermFaulted = 0.0;
    gbyk_v4b_B.sf_faultmonitor.triggerFaultRead = 0.0;
    gbyk_v4b_B.Width_j = 50U;
    gbyk_v4b_B.Width2 = 1000U;
  }

  /* parameters */
  gbyk_v4b_M->ModelData.defaultParam = ((real_T *)&gbyk_v4b_P);

  /* states (dwork) */
  gbyk_v4b_M->ModelData.dwork = ((void *) &gbyk_v4b_DW);
  (void) memset((void *)&gbyk_v4b_DW, 0,
                sizeof(DW_gbyk_v4b_T));
  gbyk_v4b_DW.UnitDelay_DSTATE = 0.0;
  gbyk_v4b_DW.UnitDelay1_DSTATE = 0.0;
  gbyk_v4b_DW.DelayInput1_DSTATE = 0.0;
  gbyk_v4b_DW.DelayInput1_DSTATE_n = 0.0;
  gbyk_v4b_DW.UnitDelay_DSTATE_a = 0.0;
  gbyk_v4b_DW.Memory_PreviousInput[0] = 0.0;
  gbyk_v4b_DW.Memory_PreviousInput[1] = 0.0;
  gbyk_v4b_DW.Memory_PreviousInput[2] = 0.0;
  gbyk_v4b_DW.Memory_PreviousInput[3] = 0.0;
  gbyk_v4b_DW.Memory_PreviousInput_c = 0.0;
  gbyk_v4b_DW.TmpRTBAtNumberofEventCodesOutport1_Buffer0 = 0.0;
  gbyk_v4b_DW.RateTransition2_Buffer0 = 0.0;
  gbyk_v4b_DW.Memory1_PreviousInput = 0.0;
  gbyk_v4b_DW.Memory2_1_PreviousInput = 0.0;
  gbyk_v4b_DW.Memory2_2_PreviousInput = 0.0;
  gbyk_v4b_DW.Memory2_3_PreviousInput = 0.0;
  gbyk_v4b_DW.Memory2_4_PreviousInput = 0.0;
  gbyk_v4b_DW.Memory2_5_PreviousInput = 0.0;
  gbyk_v4b_DW.Memory2_9_PreviousInput = 0.0;
  gbyk_v4b_DW.Memory2_18_PreviousInput = 0.0;
  gbyk_v4b_DW.Memory2_19_PreviousInput = 0.0;
  gbyk_v4b_DW.Memory2_20_PreviousInput = 0.0;
  gbyk_v4b_DW.Memory2_21_PreviousInput = 0.0;
  gbyk_v4b_DW.Memory2_22_PreviousInput = 0.0;
  gbyk_v4b_DW.Memory2_26_PreviousInput = 0.0;
  gbyk_v4b_DW.Memory2_10_PreviousInput = 0.0;
  gbyk_v4b_DW.Memory2_11_PreviousInput = 0.0;
  gbyk_v4b_DW.Memory2_12_PreviousInput = 0.0;
  gbyk_v4b_DW.Memory2_13_PreviousInput = 0.0;
  gbyk_v4b_DW.Memory2_14_PreviousInput = 0.0;
  gbyk_v4b_DW.Memory2_15_PreviousInput = 0.0;
  gbyk_v4b_DW.Memory2_16_PreviousInput = 0.0;
  gbyk_v4b_DW.Memory2_17_PreviousInput = 0.0;
  gbyk_v4b_DW.Memory2_23_PreviousInput = 0.0;
  gbyk_v4b_DW.Memory2_24_PreviousInput = 0.0;
  gbyk_v4b_DW.Memory2_25_PreviousInput = 0.0;
  gbyk_v4b_DW.Memory2_27_PreviousInput = 0.0;
  gbyk_v4b_DW.Memory2_28_PreviousInput = 0.0;
  gbyk_v4b_DW.Memory2_29_PreviousInput = 0.0;
  gbyk_v4b_DW.Memory2_30_PreviousInput = 0.0;
  gbyk_v4b_DW.Memory2_31_PreviousInput = 0.0;
  gbyk_v4b_DW.Memory2_32_PreviousInput = 0.0;
  gbyk_v4b_DW.Memory2_33_PreviousInput = 0.0;
  gbyk_v4b_DW.Memory2_34_PreviousInput = 0.0;
  gbyk_v4b_DW.Memory2_6_PreviousInput = 0.0;
  gbyk_v4b_DW.Memory2_7_PreviousInput = 0.0;
  gbyk_v4b_DW.Memory2_8_PreviousInput = 0.0;

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      gbyk_v4b_DW.ECATStatus[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 14; i++) {
      gbyk_v4b_DW.ECATHardware[i] = 0.0;
    }
  }

  gbyk_v4b_DW.tickCount = 0.0;
  gbyk_v4b_DW.tgtdist = 0.0;
  gbyk_v4b_DW.rwdTgts[0] = 0.0;
  gbyk_v4b_DW.rwdTgts[1] = 0.0;
  gbyk_v4b_DW.pTgts[0] = 0.0;
  gbyk_v4b_DW.pTgts[1] = 0.0;
  gbyk_v4b_DW.tgt2trig = 0.0;
  gbyk_v4b_DW.corrTgt = 0.0;
  gbyk_v4b_DW.incorrTgt = 0.0;
  gbyk_v4b_DW.boxtrig = 0.0;
  gbyk_v4b_DW.RateTransition1_Buffer0 = 0.0;
  gbyk_v4b_DW.last_valid_frame_ack = 0.0;
  gbyk_v4b_DW.last_perm_frame_ack = 0.0;
  gbyk_v4b_DW.Delay1_PreviousInput = 0.0;
  gbyk_v4b_DW.Subtract_DWORK1 = 0.0;

  {
    int32_T i;
    for (i = 0; i < 499; i++) {
      gbyk_v4b_DW.trial_queue[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 499; i++) {
      gbyk_v4b_DW.repeat_list[i] = 0.0;
    }
  }

  gbyk_v4b_DW.EXAM = 0.0;
  gbyk_v4b_DW.BLOCK = 0.0;

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      gbyk_v4b_DW.held_value[i] = 0.0;
    }
  }

  gbyk_v4b_DW.u = 0.0;
  gbyk_v4b_DW.v = 0.0;
  gbyk_v4b_DW.RateTransition_Buffer0[0] = 0.0;
  gbyk_v4b_DW.RateTransition_Buffer0[1] = 0.0;
  gbyk_v4b_DW.RateTransition_Buffer0[2] = 0.0;
  gbyk_v4b_DW.start_time = 0.0;
  gbyk_v4b_DW.last_time = 0.0;
  gbyk_v4b_DW.BKINEtherCATinit1_DWORK2 = 0.0;
  gbyk_v4b_DW.BKINEtherCATinit1_DWORK4 = 0.0;
  gbyk_v4b_DW.BKINEtherCATinit_DWORK2 = 0.0;
  gbyk_v4b_DW.BKINEtherCATinit_DWORK4 = 0.0;

  {
    int32_T i;
    for (i = 0; i < 20; i++) {
      gbyk_v4b_DW.ECATErrMsgs[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 8; i++) {
      gbyk_v4b_DW.ECATExtraData[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 24; i++) {
      gbyk_v4b_DW.HardwareSettings[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 20; i++) {
      gbyk_v4b_DW.Kinematics[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 12; i++) {
      gbyk_v4b_DW.PrimaryEncoderData[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 16; i++) {
      gbyk_v4b_DW.RobotCalibrations[i] = 0.0;
    }
  }

  gbyk_v4b_DW.RobotRevision[0] = 0.0;
  gbyk_v4b_DW.RobotRevision[1] = 0.0;
  gbyk_v4b_DW.DelayEstimates[0] = 0.0;
  gbyk_v4b_DW.DelayEstimates[1] = 0.0;
  gbyk_v4b_DW.DelayEstimates[2] = 0.0;
  gbyk_v4b_DW.DelayEstimates[3] = 0.0;
  gbyk_v4b_DW.ArmForceSensors[0] = 0.0;
  gbyk_v4b_DW.ArmForceSensors[1] = 0.0;

  {
    int32_T i;
    for (i = 0; i < 20; i++) {
      gbyk_v4b_DW.lastECATMessages[i] = 0.0;
    }
  }

  gbyk_v4b_DW.outCount = 0.0;

  {
    int32_T i;
    for (i = 0; i < 300; i++) {
      gbyk_v4b_DW.memoryBuffer[i] = 0.0;
    }
  }

  gbyk_v4b_DW.waitingMsgCount = 0.0;
  gbyk_v4b_DW.sentCount = 0.0;

  {
    int32_T i;
    for (i = 0; i < 400; i++) {
      gbyk_v4b_DW.secondaryPosData_data[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 400; i++) {
      gbyk_v4b_DW.secondaryVelData_data[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 400; i++) {
      gbyk_v4b_DW.primaryVelData_data[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 400; i++) {
      gbyk_v4b_DW.primaryVelDataFiltered_data[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 12; i++) {
      gbyk_v4b_DW.rawVelocities[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 12; i++) {
      gbyk_v4b_DW.filtVelocities[i] = 0.0;
    }
  }

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

  {
    int32_T i;
    for (i = 0; i < 5; i++) {
      gbyk_v4b_DW.servoValuesR1[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 5; i++) {
      gbyk_v4b_DW.servoValuesR2[i] = 0.0;
    }
  }

  gbyk_v4b_DW.no_update_count = 0.0;

  {
    int32_T i;
    for (i = 0; i < 12; i++) {
      gbyk_v4b_DW.latchedErrors[i] = 0.0;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 12; i++) {
      gbyk_v4b_DW.latchedDCErrors[i] = 0.0;
    }
  }

  gbyk_v4b_DW.Memory_PreviousInput_l = 0.0;
  gbyk_v4b_DW.Memory_PreviousInput_h = 0.0;
  gbyk_v4b_DW.Memory1_PreviousInput_c = 0.0;
  gbyk_v4b_DW.Memory2_PreviousInput = 0.0;
  gbyk_v4b_DW.Memory2_PreviousInput_n[0] = 0.0;
  gbyk_v4b_DW.Memory2_PreviousInput_n[1] = 0.0;
  gbyk_v4b_DW.Memory3_PreviousInput = 0.0;
  gbyk_v4b_DW.Memory_PreviousInput_f = 0.0;
  gbyk_v4b_DW.Memory_PreviousInput_m = 0.0;
  gbyk_v4b_DW.permFaulted = 0.0;
  gbyk_v4b_DW.countFaultSteps = 0.0;
  gbyk_v4b_DW.frameCounter = 0.0;
  gbyk_v4b_DW.Memory_PreviousInput_p = 0.0;
  gbyk_v4b_DW.Memory_PreviousInput_g = 0.0;
  gbyk_v4b_DW.Memory_PreviousInput_pv = 0.0;
  gbyk_v4b_DW.Memory1_PreviousInput_i = 0.0;
  gbyk_v4b_DW.Memory2_PreviousInput_p = 0.0;
  gbyk_v4b_DW.Memory2_PreviousInput_i[0] = 0.0;
  gbyk_v4b_DW.Memory2_PreviousInput_i[1] = 0.0;
  gbyk_v4b_DW.Memory3_PreviousInput_l = 0.0;
  gbyk_v4b_DW.Memory_PreviousInput_d = 0.0;
  gbyk_v4b_DW.Memory_PreviousInput_h3 = 0.0;
  gbyk_v4b_DW.currReadIdx = 0.0;
  gbyk_v4b_DW.valuesToRead = 0.0;
  gbyk_v4b_DW.Memory_PreviousInput_lw = 0.0;
  gbyk_v4b_DW.currReadIdx_j = 0.0;
  gbyk_v4b_DW.valuesToRead_b = 0.0;
  gbyk_v4b_DW.permFaulted_l = 0.0;
  gbyk_v4b_DW.countFaultSteps_d = 0.0;
  gbyk_v4b_DW.frameCounter_e = 0.0;
  gbyk_v4b_DW.Memory2_PreviousInput_a = 0.0;
  gbyk_v4b_DW.RateTransition2_Buffer0_p[0] = 0.0;
  gbyk_v4b_DW.RateTransition2_Buffer0_p[1] = 0.0;
  gbyk_v4b_DW.RateTransition2_Buffer0_p[2] = 0.0;
  gbyk_v4b_DW.TmpRTBAtforcestrobeOutport1_Buffer0 = 0.0;
  gbyk_v4b_DW.counter = 0.0;
  gbyk_v4b_DW.packet_queue_sz = 0.0;
  gbyk_v4b_DW.outstanding_packet_index = 0.0;

  {
    int32_T i;
    for (i = 0; i < 400; i++) {
      gbyk_v4b_DW.TmpRTBAtSendControlMachineInport1_Buffer0[i] = 0.0F;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 20500000; i++) {
      gbyk_v4b_DW.packet_queue[i] = 0.0F;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 127; i++) {
      gbyk_v4b_DW.t2_PreviousInput[i] = 0.0F;
    }
  }

  {
    int32_T i;
    for (i = 0; i < 127; i++) {
      gbyk_v4b_DW.t1_PreviousInput[i] = 0.0F;
    }
  }

  gbyk_v4b_DW.sf_forceEnableDisable_k.lastRunningState = 0.0;
  gbyk_v4b_DW.sf_forceEnableDisable_k.faultResetCycles = 0.0;
  gbyk_v4b_DW.sf_SDOreadmachine_h.valueCount = 0.0;
  gbyk_v4b_DW.sf_AbsEncodermachine_k.encoderIdx = 0.0;
  gbyk_v4b_DW.sf_AbsEncodermachine_i.encoderIdx = 0.0;
  gbyk_v4b_DW.sf_faultmonitor1_h.underVoltageCounter = 0.0;
  gbyk_v4b_DW.sf_faultmonitor_i.preOpCounter = 0.0;
  gbyk_v4b_DW.sf_ReadEMCY_p.currReadIdx = 0.0;
  gbyk_v4b_DW.sf_ReadEMCY_p.valuesToRead = 0.0;
  gbyk_v4b_DW.sf_faultmonitor1_c.underVoltageCounter = 0.0;
  gbyk_v4b_DW.sf_faultmonitor_f.preOpCounter = 0.0;
  gbyk_v4b_DW.sf_ReadEMCY_i.currReadIdx = 0.0;
  gbyk_v4b_DW.sf_ReadEMCY_i.valuesToRead = 0.0;
  gbyk_v4b_DW.sf_ControlGDCWhistleState_p.permFaulted = 0.0;
  gbyk_v4b_DW.sf_ControlGDCWhistleState_p.countFaultSteps = 0.0;
  gbyk_v4b_DW.sf_ControlGDCWhistleState_p.frameCounter = 0.0;
  gbyk_v4b_DW.sf_forceEnableDisable.lastRunningState = 0.0;
  gbyk_v4b_DW.sf_forceEnableDisable.faultResetCycles = 0.0;
  gbyk_v4b_DW.sf_SDOreadmachine.valueCount = 0.0;
  gbyk_v4b_DW.sf_AbsEncodermachine_b.encoderIdx = 0.0;
  gbyk_v4b_DW.sf_AbsEncodermachine.encoderIdx = 0.0;
  gbyk_v4b_DW.sf_faultmonitor1_l.underVoltageCounter = 0.0;
  gbyk_v4b_DW.sf_faultmonitor_k.preOpCounter = 0.0;
  gbyk_v4b_DW.sf_ControlGDCWhistleState_f.permFaulted = 0.0;
  gbyk_v4b_DW.sf_ControlGDCWhistleState_f.countFaultSteps = 0.0;
  gbyk_v4b_DW.sf_ControlGDCWhistleState_f.frameCounter = 0.0;
  gbyk_v4b_DW.sf_faultmonitor1.underVoltageCounter = 0.0;
  gbyk_v4b_DW.sf_faultmonitor.preOpCounter = 0.0;

  /* Initialize DataMapInfo substructure containing ModelMap for C API */
  gbyk_v4b_InitializeDataMapInfo(gbyk_v4b_M);

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &gbyk_v4b_M->NonInlinedSFcns.sfcnInfo;
    gbyk_v4b_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(gbyk_v4b_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo, &gbyk_v4b_M->Sizes.numSampTimes);
    gbyk_v4b_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr(gbyk_v4b_M)[0]);
    gbyk_v4b_M->NonInlinedSFcns.taskTimePtrs[1] = &(rtmGetTPtr(gbyk_v4b_M)[1]);
    gbyk_v4b_M->NonInlinedSFcns.taskTimePtrs[2] = &(rtmGetTPtr(gbyk_v4b_M)[2]);
    gbyk_v4b_M->NonInlinedSFcns.taskTimePtrs[3] = &(rtmGetTPtr(gbyk_v4b_M)[3]);
    gbyk_v4b_M->NonInlinedSFcns.taskTimePtrs[4] = &(rtmGetTPtr(gbyk_v4b_M)[4]);
    gbyk_v4b_M->NonInlinedSFcns.taskTimePtrs[5] = &(rtmGetTPtr(gbyk_v4b_M)[5]);
    rtssSetTPtrPtr(sfcnInfo,gbyk_v4b_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(gbyk_v4b_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(gbyk_v4b_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput(gbyk_v4b_M));
    rtssSetStepSizePtr(sfcnInfo, &gbyk_v4b_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(gbyk_v4b_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &gbyk_v4b_M->ModelData.derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo,
      &gbyk_v4b_M->ModelData.zCCacheNeedsReset);
    rtssSetBlkStateChangePtr(sfcnInfo, &gbyk_v4b_M->ModelData.blkStateChange);
    rtssSetSampleHitsPtr(sfcnInfo, &gbyk_v4b_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo, &gbyk_v4b_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &gbyk_v4b_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &gbyk_v4b_M->solverInfoPtr);
  }

  gbyk_v4b_M->Sizes.numSFcns = (44);

  /* register each child */
  {
    (void) memset((void *)&gbyk_v4b_M->NonInlinedSFcns.childSFunctions[0], 0,
                  44*sizeof(SimStruct));
    gbyk_v4b_M->childSfunctions =
      (&gbyk_v4b_M->NonInlinedSFcns.childSFunctionPtrs[0]);

    {
      int_T i;
      for (i = 0; i < 44; i++) {
        gbyk_v4b_M->childSfunctions[i] =
          (&gbyk_v4b_M->NonInlinedSFcns.childSFunctions[i]);
      }
    }

    /* Level2 S-Function Block: gbyk_v4b/<S31>/Send (xpcudpbytesend) */
    {
      SimStruct *rts = gbyk_v4b_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = gbyk_v4b_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = gbyk_v4b_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = gbyk_v4b_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &gbyk_v4b_M->NonInlinedSFcns.blkInfo2[0]);
      }

      ssSetRTWSfcnInfo(rts, gbyk_v4b_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &gbyk_v4b_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &gbyk_v4b_M->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &gbyk_v4b_M->NonInlinedSFcns.statesInfo2[0]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn0.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, gbyk_v4b_B.Pack_g);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 40);
        }
      }

      /* path info */
      ssSetModelName(rts, "Send");
      ssSetPath(rts, "gbyk_v4b/DataLogging/Keep alive/Send");
      ssSetRTModel(rts,gbyk_v4b_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 5);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)gbyk_v4b_P.Send_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)gbyk_v4b_P.Send_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)gbyk_v4b_P.Send_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)gbyk_v4b_P.Send_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)gbyk_v4b_P.Send_P5_Size);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &gbyk_v4b_DW.Send_IWORK_p[0]);
      ssSetPWork(rts, (void **) &gbyk_v4b_DW.Send_PWORK_p);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn0.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn0.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &gbyk_v4b_DW.Send_IWORK_p[0]);

        /* PWORK */
        ssSetDWorkWidth(rts, 1, 1);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &gbyk_v4b_DW.Send_PWORK_p);
      }

      /* registration */
      xpcudpbytesend(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.1);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 5;

      /* set compiled values of dynamic vector attributes */
      ssSetInputPortWidth(rts, 0, 40);
      ssSetInputPortDataType(rts, 0, SS_UINT8);
      ssSetInputPortComplexSignal(rts, 0, 0);
      ssSetInputPortFrameData(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: gbyk_v4b/<S51>/Send (xpcudpbytesend) */
    {
      SimStruct *rts = gbyk_v4b_M->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod = gbyk_v4b_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset = gbyk_v4b_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap = gbyk_v4b_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &gbyk_v4b_M->NonInlinedSFcns.blkInfo2[1]);
      }

      ssSetRTWSfcnInfo(rts, gbyk_v4b_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &gbyk_v4b_M->NonInlinedSFcns.methods2[1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &gbyk_v4b_M->NonInlinedSFcns.methods3[1]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &gbyk_v4b_M->NonInlinedSFcns.statesInfo2[1]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn1.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, gbyk_v4b_B.Pack_i);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1640);
        }
      }

      /* path info */
      ssSetModelName(rts, "Send");
      ssSetPath(rts,
                "gbyk_v4b/DataLogging/Network Transfer Subsystem/UDP Send Subsystem/Send");
      ssSetRTModel(rts,gbyk_v4b_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 5);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)gbyk_v4b_P.Send_P1_Size_b);
        ssSetSFcnParam(rts, 1, (mxArray*)gbyk_v4b_P.Send_P2_Size_i);
        ssSetSFcnParam(rts, 2, (mxArray*)gbyk_v4b_P.Send_P3_Size_g);
        ssSetSFcnParam(rts, 3, (mxArray*)gbyk_v4b_P.Send_P4_Size_l);
        ssSetSFcnParam(rts, 4, (mxArray*)gbyk_v4b_P.Send_P5_Size_e);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &gbyk_v4b_DW.Send_IWORK_e[0]);
      ssSetPWork(rts, (void **) &gbyk_v4b_DW.Send_PWORK_hr);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn1.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn1.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &gbyk_v4b_DW.Send_IWORK_e[0]);

        /* PWORK */
        ssSetDWorkWidth(rts, 1, 1);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &gbyk_v4b_DW.Send_PWORK_hr);
      }

      /* registration */
      xpcudpbytesend(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.00025);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetInputPortWidth(rts, 0, 1640);
      ssSetInputPortDataType(rts, 0, SS_UINT8);
      ssSetInputPortComplexSignal(rts, 0, 0);
      ssSetInputPortFrameData(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: gbyk_v4b/<S50>/UDP Receive (BKINUDPReceiveRead) */
    {
      SimStruct *rts = gbyk_v4b_M->childSfunctions[2];

      /* timing info */
      time_T *sfcnPeriod = gbyk_v4b_M->NonInlinedSFcns.Sfcn2.sfcnPeriod;
      time_T *sfcnOffset = gbyk_v4b_M->NonInlinedSFcns.Sfcn2.sfcnOffset;
      int_T *sfcnTsMap = gbyk_v4b_M->NonInlinedSFcns.Sfcn2.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &gbyk_v4b_M->NonInlinedSFcns.blkInfo2[2]);
      }

      ssSetRTWSfcnInfo(rts, gbyk_v4b_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &gbyk_v4b_M->NonInlinedSFcns.methods2[2]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &gbyk_v4b_M->NonInlinedSFcns.methods3[2]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &gbyk_v4b_M->NonInlinedSFcns.statesInfo2[2]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn2.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, &gbyk_v4b_B.trigger);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          ssSetInputPortRequiredContiguous(rts, 1, 1);
          ssSetInputPortSignal(rts, 1, gbyk_v4b_B.RateTransition2_js);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 3);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn2.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 6);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 21);
          ssSetOutputPortSignal(rts, 0, ((uint8_T *) gbyk_v4b_B.Data));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((real_T *) &gbyk_v4b_B.Pckt_Recd));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidth(rts, 2, 21);
          ssSetOutputPortSignal(rts, 2, ((uint8_T *) gbyk_v4b_B.Data2));
        }

        /* port 3 */
        {
          _ssSetOutputPortNumDimensions(rts, 3, 1);
          ssSetOutputPortWidth(rts, 3, 1);
          ssSetOutputPortSignal(rts, 3, ((real_T *) &gbyk_v4b_B.Pckt_Recd2));
        }

        /* port 4 */
        {
          _ssSetOutputPortNumDimensions(rts, 4, 1);
          ssSetOutputPortWidth(rts, 4, 1);
          ssSetOutputPortSignal(rts, 4, ((real_T *) &gbyk_v4b_B.doublereads));
        }

        /* port 5 */
        {
          _ssSetOutputPortNumDimensions(rts, 5, 1);
          ssSetOutputPortWidth(rts, 5, 1);
          ssSetOutputPortSignal(rts, 5, ((real_T *) &gbyk_v4b_B.UDPReceive_o6));
        }
      }

      /* path info */
      ssSetModelName(rts, "UDP Receive");
      ssSetPath(rts,
                "gbyk_v4b/DataLogging/Network Transfer Subsystem/UDP Receiver/UDP Receive");
      ssSetRTModel(rts,gbyk_v4b_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn2.params;
        ssSetSFcnParamsCount(rts, 5);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)gbyk_v4b_P.UDPReceive_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)gbyk_v4b_P.UDPReceive_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)gbyk_v4b_P.UDPReceive_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)gbyk_v4b_P.UDPReceive_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)gbyk_v4b_P.UDPReceive_P5_Size);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &gbyk_v4b_DW.UDPReceive_IWORK[0]);
      ssSetPWork(rts, (void **) &gbyk_v4b_DW.UDPReceive_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn2.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn2.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 3);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &gbyk_v4b_DW.UDPReceive_IWORK[0]);

        /* PWORK */
        ssSetDWorkWidth(rts, 1, 1);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &gbyk_v4b_DW.UDPReceive_PWORK);
      }

      /* registration */
      BKINUDPReceiveRead(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.00025);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetInputPortConnected(rts, 1, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 1, 0);
      _ssSetOutputPortConnected(rts, 2, 0);
      _ssSetOutputPortConnected(rts, 3, 0);
      _ssSetOutputPortConnected(rts, 4, 0);
      _ssSetOutputPortConnected(rts, 5, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);
      _ssSetOutputPortBeingMerged(rts, 1, 0);
      _ssSetOutputPortBeingMerged(rts, 2, 0);
      _ssSetOutputPortBeingMerged(rts, 3, 0);
      _ssSetOutputPortBeingMerged(rts, 4, 0);
      _ssSetOutputPortBeingMerged(rts, 5, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
    }

    /* Level2 S-Function Block: gbyk_v4b/<S50>/UDP Receive Port Reset (BKINUDPReceiveInit) */
    {
      SimStruct *rts = gbyk_v4b_M->childSfunctions[3];

      /* timing info */
      time_T *sfcnPeriod = gbyk_v4b_M->NonInlinedSFcns.Sfcn3.sfcnPeriod;
      time_T *sfcnOffset = gbyk_v4b_M->NonInlinedSFcns.Sfcn3.sfcnOffset;
      int_T *sfcnTsMap = gbyk_v4b_M->NonInlinedSFcns.Sfcn3.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &gbyk_v4b_M->NonInlinedSFcns.blkInfo2[3]);
      }

      ssSetRTWSfcnInfo(rts, gbyk_v4b_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &gbyk_v4b_M->NonInlinedSFcns.methods2[3]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &gbyk_v4b_M->NonInlinedSFcns.methods3[3]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &gbyk_v4b_M->NonInlinedSFcns.statesInfo2[3]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn3.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, &gbyk_v4b_B.RqstUDPReset);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn3.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 2);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *) &gbyk_v4b_B.UDPResets));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 3);
          ssSetOutputPortSignal(rts, 1, ((real_T *)
            gbyk_v4b_B.UDPReceivePortReset_o2));
        }
      }

      /* path info */
      ssSetModelName(rts, "UDP Receive Port Reset");
      ssSetPath(rts,
                "gbyk_v4b/DataLogging/Network Transfer Subsystem/UDP Receiver/UDP Receive Port Reset");
      ssSetRTModel(rts,gbyk_v4b_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn3.params;
        ssSetSFcnParamsCount(rts, 5);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)gbyk_v4b_P.UDPReceivePortReset_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)gbyk_v4b_P.UDPReceivePortReset_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)gbyk_v4b_P.UDPReceivePortReset_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)gbyk_v4b_P.UDPReceivePortReset_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)gbyk_v4b_P.UDPReceivePortReset_P5_Size);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &gbyk_v4b_DW.UDPReceivePortReset_IWORK[0]);
      ssSetPWork(rts, (void **) &gbyk_v4b_DW.UDPReceivePortReset_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn3.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn3.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 4);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &gbyk_v4b_DW.UDPReceivePortReset_IWORK[0]);

        /* PWORK */
        ssSetDWorkWidth(rts, 1, 1);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &gbyk_v4b_DW.UDPReceivePortReset_PWORK);
      }

      /* registration */
      BKINUDPReceiveInit(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.001);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 3;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 0);
      _ssSetOutputPortConnected(rts, 1, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);
      _ssSetOutputPortBeingMerged(rts, 1, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: gbyk_v4b/<S58>/Receive (xpcudpbytereceive) */
    {
      SimStruct *rts = gbyk_v4b_M->childSfunctions[4];

      /* timing info */
      time_T *sfcnPeriod = gbyk_v4b_M->NonInlinedSFcns.Sfcn4.sfcnPeriod;
      time_T *sfcnOffset = gbyk_v4b_M->NonInlinedSFcns.Sfcn4.sfcnOffset;
      int_T *sfcnTsMap = gbyk_v4b_M->NonInlinedSFcns.Sfcn4.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &gbyk_v4b_M->NonInlinedSFcns.blkInfo2[4]);
      }

      ssSetRTWSfcnInfo(rts, gbyk_v4b_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &gbyk_v4b_M->NonInlinedSFcns.methods2[4]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &gbyk_v4b_M->NonInlinedSFcns.methods3[4]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &gbyk_v4b_M->NonInlinedSFcns.statesInfo2[4]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn4.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 2);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 64);
          ssSetOutputPortSignal(rts, 0, ((uint8_T *) gbyk_v4b_B.Receive_o1_k));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((real_T *) &gbyk_v4b_B.Receive_o2_m));
        }
      }

      /* path info */
      ssSetModelName(rts, "Receive");
      ssSetPath(rts, "gbyk_v4b/DataLogging/Poll Force Plates/plate1/Receive");
      ssSetRTModel(rts,gbyk_v4b_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn4.params;
        ssSetSFcnParamsCount(rts, 5);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)gbyk_v4b_P.Receive_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)gbyk_v4b_P.Receive_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)gbyk_v4b_P.Receive_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)gbyk_v4b_P.Receive_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)gbyk_v4b_P.Receive_P5_Size);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &gbyk_v4b_DW.Receive_IWORK_d[0]);
      ssSetPWork(rts, (void **) &gbyk_v4b_DW.Receive_PWORK_l);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn4.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn4.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &gbyk_v4b_DW.Receive_IWORK_d[0]);

        /* PWORK */
        ssSetDWorkWidth(rts, 1, 1);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &gbyk_v4b_DW.Receive_PWORK_l);
      }

      /* registration */
      xpcudpbytereceive(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.00025);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 1, 0);
      _ssSetOutputPortBeingMerged(rts, 0, 0);
      _ssSetOutputPortBeingMerged(rts, 1, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: gbyk_v4b/<S59>/Receive1 (xpcudpbytereceive) */
    {
      SimStruct *rts = gbyk_v4b_M->childSfunctions[5];

      /* timing info */
      time_T *sfcnPeriod = gbyk_v4b_M->NonInlinedSFcns.Sfcn5.sfcnPeriod;
      time_T *sfcnOffset = gbyk_v4b_M->NonInlinedSFcns.Sfcn5.sfcnOffset;
      int_T *sfcnTsMap = gbyk_v4b_M->NonInlinedSFcns.Sfcn5.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &gbyk_v4b_M->NonInlinedSFcns.blkInfo2[5]);
      }

      ssSetRTWSfcnInfo(rts, gbyk_v4b_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &gbyk_v4b_M->NonInlinedSFcns.methods2[5]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &gbyk_v4b_M->NonInlinedSFcns.methods3[5]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &gbyk_v4b_M->NonInlinedSFcns.statesInfo2[5]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn5.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 2);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 64);
          ssSetOutputPortSignal(rts, 0, ((uint8_T *) gbyk_v4b_B.Receive1_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((real_T *) &gbyk_v4b_B.Receive1_o2));
        }
      }

      /* path info */
      ssSetModelName(rts, "Receive1");
      ssSetPath(rts, "gbyk_v4b/DataLogging/Poll Force Plates/plate2/Receive1");
      ssSetRTModel(rts,gbyk_v4b_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn5.params;
        ssSetSFcnParamsCount(rts, 5);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)gbyk_v4b_P.Receive1_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)gbyk_v4b_P.Receive1_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)gbyk_v4b_P.Receive1_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)gbyk_v4b_P.Receive1_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)gbyk_v4b_P.Receive1_P5_Size);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &gbyk_v4b_DW.Receive1_IWORK[0]);
      ssSetPWork(rts, (void **) &gbyk_v4b_DW.Receive1_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn5.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn5.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &gbyk_v4b_DW.Receive1_IWORK[0]);

        /* PWORK */
        ssSetDWorkWidth(rts, 1, 1);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &gbyk_v4b_DW.Receive1_PWORK);
      }

      /* registration */
      xpcudpbytereceive(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.00025);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 1, 0);
      _ssSetOutputPortBeingMerged(rts, 0, 0);
      _ssSetOutputPortBeingMerged(rts, 1, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: gbyk_v4b/<S60>/Send (xpcudpbytesend) */
    {
      SimStruct *rts = gbyk_v4b_M->childSfunctions[6];

      /* timing info */
      time_T *sfcnPeriod = gbyk_v4b_M->NonInlinedSFcns.Sfcn6.sfcnPeriod;
      time_T *sfcnOffset = gbyk_v4b_M->NonInlinedSFcns.Sfcn6.sfcnOffset;
      int_T *sfcnTsMap = gbyk_v4b_M->NonInlinedSFcns.Sfcn6.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &gbyk_v4b_M->NonInlinedSFcns.blkInfo2[6]);
      }

      ssSetRTWSfcnInfo(rts, gbyk_v4b_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &gbyk_v4b_M->NonInlinedSFcns.methods2[6]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &gbyk_v4b_M->NonInlinedSFcns.methods3[6]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &gbyk_v4b_M->NonInlinedSFcns.statesInfo2[6]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn6.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, gbyk_v4b_B.TmpRTBAtConvert1Outport1);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 34);
        }
      }

      /* path info */
      ssSetModelName(rts, "Send");
      ssSetPath(rts, "gbyk_v4b/DataLogging/Poll Force Plates/send poll 1/Send");
      ssSetRTModel(rts,gbyk_v4b_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn6.params;
        ssSetSFcnParamsCount(rts, 5);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)gbyk_v4b_P.Send_P1_Size_i);
        ssSetSFcnParam(rts, 1, (mxArray*)gbyk_v4b_P.Send_P2_Size_l);
        ssSetSFcnParam(rts, 2, (mxArray*)gbyk_v4b_P.Send_P3_Size_a);
        ssSetSFcnParam(rts, 3, (mxArray*)gbyk_v4b_P.Send_P4_Size_h);
        ssSetSFcnParam(rts, 4, (mxArray*)gbyk_v4b_P.Send_P5_Size_es);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &gbyk_v4b_DW.Send_IWORK_dv[0]);
      ssSetPWork(rts, (void **) &gbyk_v4b_DW.Send_PWORK_l);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn6.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn6.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &gbyk_v4b_DW.Send_IWORK_dv[0]);

        /* PWORK */
        ssSetDWorkWidth(rts, 1, 1);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &gbyk_v4b_DW.Send_PWORK_l);
      }

      /* registration */
      xpcudpbytesend(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.0005);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 2;

      /* set compiled values of dynamic vector attributes */
      ssSetInputPortWidth(rts, 0, 34);
      ssSetInputPortDataType(rts, 0, SS_UINT8);
      ssSetInputPortComplexSignal(rts, 0, 0);
      ssSetInputPortFrameData(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: gbyk_v4b/<S61>/Send1 (xpcudpbytesend) */
    {
      SimStruct *rts = gbyk_v4b_M->childSfunctions[7];

      /* timing info */
      time_T *sfcnPeriod = gbyk_v4b_M->NonInlinedSFcns.Sfcn7.sfcnPeriod;
      time_T *sfcnOffset = gbyk_v4b_M->NonInlinedSFcns.Sfcn7.sfcnOffset;
      int_T *sfcnTsMap = gbyk_v4b_M->NonInlinedSFcns.Sfcn7.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &gbyk_v4b_M->NonInlinedSFcns.blkInfo2[7]);
      }

      ssSetRTWSfcnInfo(rts, gbyk_v4b_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &gbyk_v4b_M->NonInlinedSFcns.methods2[7]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &gbyk_v4b_M->NonInlinedSFcns.methods3[7]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &gbyk_v4b_M->NonInlinedSFcns.statesInfo2[7]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn7.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, gbyk_v4b_B.TmpRTBAtConvert1Outport1);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 34);
        }
      }

      /* path info */
      ssSetModelName(rts, "Send1");
      ssSetPath(rts, "gbyk_v4b/DataLogging/Poll Force Plates/send poll 2/Send1");
      ssSetRTModel(rts,gbyk_v4b_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn7.params;
        ssSetSFcnParamsCount(rts, 5);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)gbyk_v4b_P.Send1_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)gbyk_v4b_P.Send1_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)gbyk_v4b_P.Send1_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)gbyk_v4b_P.Send1_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)gbyk_v4b_P.Send1_P5_Size);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &gbyk_v4b_DW.Send1_IWORK[0]);
      ssSetPWork(rts, (void **) &gbyk_v4b_DW.Send1_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn7.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn7.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &gbyk_v4b_DW.Send1_IWORK[0]);

        /* PWORK */
        ssSetDWorkWidth(rts, 1, 1);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &gbyk_v4b_DW.Send1_PWORK);
      }

      /* registration */
      xpcudpbytesend(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.0005);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 2;

      /* set compiled values of dynamic vector attributes */
      ssSetInputPortWidth(rts, 0, 34);
      ssSetInputPortDataType(rts, 0, SS_UINT8);
      ssSetInputPortComplexSignal(rts, 0, 0);
      ssSetInputPortFrameData(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: gbyk_v4b/<S99>/BKIN PDO Receive ElmoDrive (BKINethercatpdorxElmoDrive) */
    {
      SimStruct *rts = gbyk_v4b_M->childSfunctions[8];

      /* timing info */
      time_T *sfcnPeriod = gbyk_v4b_M->NonInlinedSFcns.Sfcn8.sfcnPeriod;
      time_T *sfcnOffset = gbyk_v4b_M->NonInlinedSFcns.Sfcn8.sfcnOffset;
      int_T *sfcnTsMap = gbyk_v4b_M->NonInlinedSFcns.Sfcn8.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &gbyk_v4b_M->NonInlinedSFcns.blkInfo2[8]);
      }

      ssSetRTWSfcnInfo(rts, gbyk_v4b_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &gbyk_v4b_M->NonInlinedSFcns.methods2[8]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &gbyk_v4b_M->NonInlinedSFcns.methods3[8]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &gbyk_v4b_M->NonInlinedSFcns.statesInfo2[8]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn8.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 8);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((uint16_T *) &gbyk_v4b_B.Statusword_k));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((uint32_T *)
            &gbyk_v4b_B.statusregister_c4));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidth(rts, 2, 1);
          ssSetOutputPortSignal(rts, 2, ((int32_T *)
            &gbyk_v4b_B.primaryposition_l));
        }

        /* port 3 */
        {
          _ssSetOutputPortNumDimensions(rts, 3, 1);
          ssSetOutputPortWidth(rts, 3, 1);
          ssSetOutputPortSignal(rts, 3, ((int32_T *)
            &gbyk_v4b_B.secondaryposition_n));
        }

        /* port 4 */
        {
          _ssSetOutputPortNumDimensions(rts, 4, 1);
          ssSetOutputPortWidth(rts, 4, 1);
          ssSetOutputPortSignal(rts, 4, ((int32_T *)
            &gbyk_v4b_B.primaryvelocity_d));
        }

        /* port 5 */
        {
          _ssSetOutputPortNumDimensions(rts, 5, 1);
          ssSetOutputPortWidth(rts, 5, 1);
          ssSetOutputPortSignal(rts, 5, ((int16_T *) &gbyk_v4b_B.torque_ky));
        }

        /* port 6 */
        {
          _ssSetOutputPortNumDimensions(rts, 6, 1);
          ssSetOutputPortWidth(rts, 6, 1);
          ssSetOutputPortSignal(rts, 6, ((int32_T *) &gbyk_v4b_B.digitalinputs_j));
        }

        /* port 7 */
        {
          _ssSetOutputPortNumDimensions(rts, 7, 1);
          ssSetOutputPortWidth(rts, 7, 1);
          ssSetOutputPortSignal(rts, 7, ((int8_T *)
            &gbyk_v4b_B.actualmodeofoperation_g));
        }
      }

      /* path info */
      ssSetModelName(rts, "BKIN PDO Receive ElmoDrive");
      ssSetPath(rts,
                "gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M1/A1M1 PDOs/BKIN PDO Receive ElmoDrive");
      ssSetRTModel(rts,gbyk_v4b_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn8.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       gbyk_v4b_P.BKINPDOReceiveElmoDrive_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       gbyk_v4b_P.BKINPDOReceiveElmoDrive_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       gbyk_v4b_P.BKINPDOReceiveElmoDrive_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       gbyk_v4b_P.BKINPDOReceiveElmoDrive_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       gbyk_v4b_P.BKINPDOReceiveElmoDrive_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       gbyk_v4b_P.BKINPDOReceiveElmoDrive_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)
                       gbyk_v4b_P.BKINPDOReceiveElmoDrive_P7_Size);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &gbyk_v4b_DW.BKINPDOReceiveElmoDrive_IWORK_f[0]);
      ssSetPWork(rts, (void **) &gbyk_v4b_DW.BKINPDOReceiveElmoDrive_PWORK_i);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn8.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn8.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 7);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &gbyk_v4b_DW.BKINPDOReceiveElmoDrive_IWORK_f[0]);

        /* PWORK */
        ssSetDWorkWidth(rts, 1, 1);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &gbyk_v4b_DW.BKINPDOReceiveElmoDrive_PWORK_i);
      }

      /* registration */
      BKINethercatpdorxElmoDrive(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.00025);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 1, 1);
      _ssSetOutputPortConnected(rts, 2, 1);
      _ssSetOutputPortConnected(rts, 3, 1);
      _ssSetOutputPortConnected(rts, 4, 1);
      _ssSetOutputPortConnected(rts, 5, 1);
      _ssSetOutputPortConnected(rts, 6, 1);
      _ssSetOutputPortConnected(rts, 7, 0);
      _ssSetOutputPortBeingMerged(rts, 0, 0);
      _ssSetOutputPortBeingMerged(rts, 1, 0);
      _ssSetOutputPortBeingMerged(rts, 2, 0);
      _ssSetOutputPortBeingMerged(rts, 3, 0);
      _ssSetOutputPortBeingMerged(rts, 4, 0);
      _ssSetOutputPortBeingMerged(rts, 5, 0);
      _ssSetOutputPortBeingMerged(rts, 6, 0);
      _ssSetOutputPortBeingMerged(rts, 7, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: gbyk_v4b/<S112>/BKIN PDO Receive ElmoDrive (BKINethercatpdorxElmoDrive) */
    {
      SimStruct *rts = gbyk_v4b_M->childSfunctions[9];

      /* timing info */
      time_T *sfcnPeriod = gbyk_v4b_M->NonInlinedSFcns.Sfcn9.sfcnPeriod;
      time_T *sfcnOffset = gbyk_v4b_M->NonInlinedSFcns.Sfcn9.sfcnOffset;
      int_T *sfcnTsMap = gbyk_v4b_M->NonInlinedSFcns.Sfcn9.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &gbyk_v4b_M->NonInlinedSFcns.blkInfo2[9]);
      }

      ssSetRTWSfcnInfo(rts, gbyk_v4b_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &gbyk_v4b_M->NonInlinedSFcns.methods2[9]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &gbyk_v4b_M->NonInlinedSFcns.methods3[9]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &gbyk_v4b_M->NonInlinedSFcns.statesInfo2[9]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn9.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 8);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((uint16_T *) &gbyk_v4b_B.Statusword_b));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((uint32_T *)
            &gbyk_v4b_B.statusregister_c));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidth(rts, 2, 1);
          ssSetOutputPortSignal(rts, 2, ((int32_T *)
            &gbyk_v4b_B.primaryposition_e));
        }

        /* port 3 */
        {
          _ssSetOutputPortNumDimensions(rts, 3, 1);
          ssSetOutputPortWidth(rts, 3, 1);
          ssSetOutputPortSignal(rts, 3, ((int32_T *)
            &gbyk_v4b_B.secondaryposition_d));
        }

        /* port 4 */
        {
          _ssSetOutputPortNumDimensions(rts, 4, 1);
          ssSetOutputPortWidth(rts, 4, 1);
          ssSetOutputPortSignal(rts, 4, ((int32_T *)
            &gbyk_v4b_B.primaryvelocity_p));
        }

        /* port 5 */
        {
          _ssSetOutputPortNumDimensions(rts, 5, 1);
          ssSetOutputPortWidth(rts, 5, 1);
          ssSetOutputPortSignal(rts, 5, ((int16_T *) &gbyk_v4b_B.torque_h));
        }

        /* port 6 */
        {
          _ssSetOutputPortNumDimensions(rts, 6, 1);
          ssSetOutputPortWidth(rts, 6, 1);
          ssSetOutputPortSignal(rts, 6, ((int32_T *) &gbyk_v4b_B.digitalinputs));
        }

        /* port 7 */
        {
          _ssSetOutputPortNumDimensions(rts, 7, 1);
          ssSetOutputPortWidth(rts, 7, 1);
          ssSetOutputPortSignal(rts, 7, ((int8_T *)
            &gbyk_v4b_B.actualmodeofoperation_a));
        }
      }

      /* path info */
      ssSetModelName(rts, "BKIN PDO Receive ElmoDrive");
      ssSetPath(rts,
                "gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M2/A1M2 PDOs/BKIN PDO Receive ElmoDrive");
      ssSetRTModel(rts,gbyk_v4b_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn9.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       gbyk_v4b_P.BKINPDOReceiveElmoDrive_P1_Size_i);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       gbyk_v4b_P.BKINPDOReceiveElmoDrive_P2_Size_d);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       gbyk_v4b_P.BKINPDOReceiveElmoDrive_P3_Size_g);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       gbyk_v4b_P.BKINPDOReceiveElmoDrive_P4_Size_p);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       gbyk_v4b_P.BKINPDOReceiveElmoDrive_P5_Size_n);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       gbyk_v4b_P.BKINPDOReceiveElmoDrive_P6_Size_o);
        ssSetSFcnParam(rts, 6, (mxArray*)
                       gbyk_v4b_P.BKINPDOReceiveElmoDrive_P7_Size_o);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &gbyk_v4b_DW.BKINPDOReceiveElmoDrive_IWORK_ct[0]);
      ssSetPWork(rts, (void **) &gbyk_v4b_DW.BKINPDOReceiveElmoDrive_PWORK_b);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn9.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn9.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 7);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &gbyk_v4b_DW.BKINPDOReceiveElmoDrive_IWORK_ct[0]);

        /* PWORK */
        ssSetDWorkWidth(rts, 1, 1);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &gbyk_v4b_DW.BKINPDOReceiveElmoDrive_PWORK_b);
      }

      /* registration */
      BKINethercatpdorxElmoDrive(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.00025);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 1, 1);
      _ssSetOutputPortConnected(rts, 2, 1);
      _ssSetOutputPortConnected(rts, 3, 1);
      _ssSetOutputPortConnected(rts, 4, 1);
      _ssSetOutputPortConnected(rts, 5, 1);
      _ssSetOutputPortConnected(rts, 6, 1);
      _ssSetOutputPortConnected(rts, 7, 0);
      _ssSetOutputPortBeingMerged(rts, 0, 0);
      _ssSetOutputPortBeingMerged(rts, 1, 0);
      _ssSetOutputPortBeingMerged(rts, 2, 0);
      _ssSetOutputPortBeingMerged(rts, 3, 0);
      _ssSetOutputPortBeingMerged(rts, 4, 0);
      _ssSetOutputPortBeingMerged(rts, 5, 0);
      _ssSetOutputPortBeingMerged(rts, 6, 0);
      _ssSetOutputPortBeingMerged(rts, 7, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: gbyk_v4b/<S75>/BKIN EtherCAT PDO Transmit  (BKINethercatpdotx) */
    {
      SimStruct *rts = gbyk_v4b_M->childSfunctions[10];

      /* timing info */
      time_T *sfcnPeriod = gbyk_v4b_M->NonInlinedSFcns.Sfcn10.sfcnPeriod;
      time_T *sfcnOffset = gbyk_v4b_M->NonInlinedSFcns.Sfcn10.sfcnOffset;
      int_T *sfcnTsMap = gbyk_v4b_M->NonInlinedSFcns.Sfcn10.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &gbyk_v4b_M->NonInlinedSFcns.blkInfo2[10]);
      }

      ssSetRTWSfcnInfo(rts, gbyk_v4b_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &gbyk_v4b_M->NonInlinedSFcns.methods2[10]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &gbyk_v4b_M->NonInlinedSFcns.methods3[10]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &gbyk_v4b_M->NonInlinedSFcns.statesInfo2[10]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn10.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, &gbyk_v4b_B.TorqueMode_i);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "BKIN EtherCAT PDO Transmit ");
      ssSetPath(rts,
                "gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/BKIN EtherCAT PDO Transmit ");
      ssSetRTModel(rts,gbyk_v4b_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn10.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit_P7_Size);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &gbyk_v4b_DW.BKINEtherCATPDOTransmit_IWORK_f[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn10.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn10.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 23);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &gbyk_v4b_DW.BKINEtherCATPDOTransmit_IWORK_f[0]);
      }

      /* registration */
      BKINethercatpdotx(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.00025);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: gbyk_v4b/<S75>/BKIN EtherCAT PDO Transmit 1 (BKINethercatpdotx) */
    {
      SimStruct *rts = gbyk_v4b_M->childSfunctions[11];

      /* timing info */
      time_T *sfcnPeriod = gbyk_v4b_M->NonInlinedSFcns.Sfcn11.sfcnPeriod;
      time_T *sfcnOffset = gbyk_v4b_M->NonInlinedSFcns.Sfcn11.sfcnOffset;
      int_T *sfcnTsMap = gbyk_v4b_M->NonInlinedSFcns.Sfcn11.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &gbyk_v4b_M->NonInlinedSFcns.blkInfo2[11]);
      }

      ssSetRTWSfcnInfo(rts, gbyk_v4b_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &gbyk_v4b_M->NonInlinedSFcns.methods2[11]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &gbyk_v4b_M->NonInlinedSFcns.methods3[11]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &gbyk_v4b_M->NonInlinedSFcns.statesInfo2[11]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn11.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, &gbyk_v4b_B.TorqueMode_i);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "BKIN EtherCAT PDO Transmit 1");
      ssSetPath(rts,
                "gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/BKIN EtherCAT PDO Transmit 1");
      ssSetRTModel(rts,gbyk_v4b_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn11.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit1_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit1_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit1_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit1_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit1_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit1_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit1_P7_Size);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &gbyk_v4b_DW.BKINEtherCATPDOTransmit1_IWORK_j[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn11.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn11.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 23);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &gbyk_v4b_DW.BKINEtherCATPDOTransmit1_IWORK_j[0]);
      }

      /* registration */
      BKINethercatpdotx(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.00025);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: gbyk_v4b/<S85>/BKIN EtherCAT PDO Transmit  (BKINethercatpdotx) */
    {
      SimStruct *rts = gbyk_v4b_M->childSfunctions[12];

      /* timing info */
      time_T *sfcnPeriod = gbyk_v4b_M->NonInlinedSFcns.Sfcn12.sfcnPeriod;
      time_T *sfcnOffset = gbyk_v4b_M->NonInlinedSFcns.Sfcn12.sfcnOffset;
      int_T *sfcnTsMap = gbyk_v4b_M->NonInlinedSFcns.Sfcn12.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &gbyk_v4b_M->NonInlinedSFcns.blkInfo2[12]);
      }

      ssSetRTWSfcnInfo(rts, gbyk_v4b_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &gbyk_v4b_M->NonInlinedSFcns.methods2[12]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &gbyk_v4b_M->NonInlinedSFcns.methods3[12]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &gbyk_v4b_M->NonInlinedSFcns.statesInfo2[12]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn12.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, &gbyk_v4b_B.ControlWord_o);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "BKIN EtherCAT PDO Transmit ");
      ssSetPath(rts,
                "gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M1/BKIN EtherCAT PDO Transmit ");
      ssSetRTModel(rts,gbyk_v4b_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn12.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit_P1_Size_f);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit_P2_Size_e);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit_P3_Size_i);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit_P4_Size_l);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit_P5_Size_i);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit_P6_Size_i);
        ssSetSFcnParam(rts, 6, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit_P7_Size_g);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &gbyk_v4b_DW.BKINEtherCATPDOTransmit_IWORK_a[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn12.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn12.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 23);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &gbyk_v4b_DW.BKINEtherCATPDOTransmit_IWORK_a[0]);
      }

      /* registration */
      BKINethercatpdotx(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.00025);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: gbyk_v4b/<S86>/BKIN EtherCAT PDO Transmit  (BKINethercatpdotx) */
    {
      SimStruct *rts = gbyk_v4b_M->childSfunctions[13];

      /* timing info */
      time_T *sfcnPeriod = gbyk_v4b_M->NonInlinedSFcns.Sfcn13.sfcnPeriod;
      time_T *sfcnOffset = gbyk_v4b_M->NonInlinedSFcns.Sfcn13.sfcnOffset;
      int_T *sfcnTsMap = gbyk_v4b_M->NonInlinedSFcns.Sfcn13.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &gbyk_v4b_M->NonInlinedSFcns.blkInfo2[13]);
      }

      ssSetRTWSfcnInfo(rts, gbyk_v4b_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &gbyk_v4b_M->NonInlinedSFcns.methods2[13]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &gbyk_v4b_M->NonInlinedSFcns.methods3[13]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &gbyk_v4b_M->NonInlinedSFcns.statesInfo2[13]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn13.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0,
                               &gbyk_v4b_B.sf_ControlGDCWhistleState_f.ControlWord);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "BKIN EtherCAT PDO Transmit ");
      ssSetPath(rts,
                "gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M2/BKIN EtherCAT PDO Transmit ");
      ssSetRTModel(rts,gbyk_v4b_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn13.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit_P1_Size_o);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit_P2_Size_g);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit_P3_Size_n);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit_P4_Size_k);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit_P5_Size_n);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit_P6_Size_j);
        ssSetSFcnParam(rts, 6, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit_P7_Size_i);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &gbyk_v4b_DW.BKINEtherCATPDOTransmit_IWORK_p5[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn13.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn13.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 23);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &gbyk_v4b_DW.BKINEtherCATPDOTransmit_IWORK_p5[0]);
      }

      /* registration */
      BKINethercatpdotx(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.00025);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: gbyk_v4b/<S151>/BKIN PDO Receive ElmoDrive (BKINethercatpdorxElmoDrive) */
    {
      SimStruct *rts = gbyk_v4b_M->childSfunctions[14];

      /* timing info */
      time_T *sfcnPeriod = gbyk_v4b_M->NonInlinedSFcns.Sfcn14.sfcnPeriod;
      time_T *sfcnOffset = gbyk_v4b_M->NonInlinedSFcns.Sfcn14.sfcnOffset;
      int_T *sfcnTsMap = gbyk_v4b_M->NonInlinedSFcns.Sfcn14.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &gbyk_v4b_M->NonInlinedSFcns.blkInfo2[14]);
      }

      ssSetRTWSfcnInfo(rts, gbyk_v4b_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &gbyk_v4b_M->NonInlinedSFcns.methods2[14]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &gbyk_v4b_M->NonInlinedSFcns.methods3[14]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &gbyk_v4b_M->NonInlinedSFcns.statesInfo2[14]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn14.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 8);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((uint16_T *) &gbyk_v4b_B.Statusword));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((uint32_T *)
            &gbyk_v4b_B.statusregister_i));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidth(rts, 2, 1);
          ssSetOutputPortSignal(rts, 2, ((int32_T *) &gbyk_v4b_B.primaryposition));
        }

        /* port 3 */
        {
          _ssSetOutputPortNumDimensions(rts, 3, 1);
          ssSetOutputPortWidth(rts, 3, 1);
          ssSetOutputPortSignal(rts, 3, ((int32_T *)
            &gbyk_v4b_B.secondaryposition));
        }

        /* port 4 */
        {
          _ssSetOutputPortNumDimensions(rts, 4, 1);
          ssSetOutputPortWidth(rts, 4, 1);
          ssSetOutputPortSignal(rts, 4, ((int32_T *) &gbyk_v4b_B.primaryvelocity));
        }

        /* port 5 */
        {
          _ssSetOutputPortNumDimensions(rts, 5, 1);
          ssSetOutputPortWidth(rts, 5, 1);
          ssSetOutputPortSignal(rts, 5, ((int16_T *) &gbyk_v4b_B.torque_g5));
        }

        /* port 6 */
        {
          _ssSetOutputPortNumDimensions(rts, 6, 1);
          ssSetOutputPortWidth(rts, 6, 1);
          ssSetOutputPortSignal(rts, 6, ((int32_T *) &gbyk_v4b_B.digitalinput_d));
        }

        /* port 7 */
        {
          _ssSetOutputPortNumDimensions(rts, 7, 1);
          ssSetOutputPortWidth(rts, 7, 1);
          ssSetOutputPortSignal(rts, 7, ((int8_T *)
            &gbyk_v4b_B.actualmodeofoperation_j));
        }
      }

      /* path info */
      ssSetModelName(rts, "BKIN PDO Receive ElmoDrive");
      ssSetPath(rts,
                "gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M1/A2M1 PDOs/BKIN PDO Receive ElmoDrive");
      ssSetRTModel(rts,gbyk_v4b_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn14.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       gbyk_v4b_P.BKINPDOReceiveElmoDrive_P1_Size_g);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       gbyk_v4b_P.BKINPDOReceiveElmoDrive_P2_Size_p);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       gbyk_v4b_P.BKINPDOReceiveElmoDrive_P3_Size_c);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       gbyk_v4b_P.BKINPDOReceiveElmoDrive_P4_Size_n);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       gbyk_v4b_P.BKINPDOReceiveElmoDrive_P5_Size_d);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       gbyk_v4b_P.BKINPDOReceiveElmoDrive_P6_Size_g);
        ssSetSFcnParam(rts, 6, (mxArray*)
                       gbyk_v4b_P.BKINPDOReceiveElmoDrive_P7_Size_n);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &gbyk_v4b_DW.BKINPDOReceiveElmoDrive_IWORK_c[0]);
      ssSetPWork(rts, (void **) &gbyk_v4b_DW.BKINPDOReceiveElmoDrive_PWORK_d);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn14.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn14.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 7);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &gbyk_v4b_DW.BKINPDOReceiveElmoDrive_IWORK_c[0]);

        /* PWORK */
        ssSetDWorkWidth(rts, 1, 1);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &gbyk_v4b_DW.BKINPDOReceiveElmoDrive_PWORK_d);
      }

      /* registration */
      BKINethercatpdorxElmoDrive(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.00025);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 1, 1);
      _ssSetOutputPortConnected(rts, 2, 1);
      _ssSetOutputPortConnected(rts, 3, 1);
      _ssSetOutputPortConnected(rts, 4, 1);
      _ssSetOutputPortConnected(rts, 5, 1);
      _ssSetOutputPortConnected(rts, 6, 1);
      _ssSetOutputPortConnected(rts, 7, 0);
      _ssSetOutputPortBeingMerged(rts, 0, 0);
      _ssSetOutputPortBeingMerged(rts, 1, 0);
      _ssSetOutputPortBeingMerged(rts, 2, 0);
      _ssSetOutputPortBeingMerged(rts, 3, 0);
      _ssSetOutputPortBeingMerged(rts, 4, 0);
      _ssSetOutputPortBeingMerged(rts, 5, 0);
      _ssSetOutputPortBeingMerged(rts, 6, 0);
      _ssSetOutputPortBeingMerged(rts, 7, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: gbyk_v4b/<S164>/BKIN PDO Receive ElmoDrive (BKINethercatpdorxElmoDrive) */
    {
      SimStruct *rts = gbyk_v4b_M->childSfunctions[15];

      /* timing info */
      time_T *sfcnPeriod = gbyk_v4b_M->NonInlinedSFcns.Sfcn15.sfcnPeriod;
      time_T *sfcnOffset = gbyk_v4b_M->NonInlinedSFcns.Sfcn15.sfcnOffset;
      int_T *sfcnTsMap = gbyk_v4b_M->NonInlinedSFcns.Sfcn15.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &gbyk_v4b_M->NonInlinedSFcns.blkInfo2[15]);
      }

      ssSetRTWSfcnInfo(rts, gbyk_v4b_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &gbyk_v4b_M->NonInlinedSFcns.methods2[15]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &gbyk_v4b_M->NonInlinedSFcns.methods3[15]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &gbyk_v4b_M->NonInlinedSFcns.statesInfo2[15]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn15.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 8);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((uint16_T *) &gbyk_v4b_B.statusword));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((uint32_T *) &gbyk_v4b_B.statusregister));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidth(rts, 2, 1);
          ssSetOutputPortSignal(rts, 2, ((int32_T *) &gbyk_v4b_B.positionprimary));
        }

        /* port 3 */
        {
          _ssSetOutputPortNumDimensions(rts, 3, 1);
          ssSetOutputPortWidth(rts, 3, 1);
          ssSetOutputPortSignal(rts, 3, ((int32_T *)
            &gbyk_v4b_B.positionsecondary));
        }

        /* port 4 */
        {
          _ssSetOutputPortNumDimensions(rts, 4, 1);
          ssSetOutputPortWidth(rts, 4, 1);
          ssSetOutputPortSignal(rts, 4, ((int32_T *) &gbyk_v4b_B.velocityprimary));
        }

        /* port 5 */
        {
          _ssSetOutputPortNumDimensions(rts, 5, 1);
          ssSetOutputPortWidth(rts, 5, 1);
          ssSetOutputPortSignal(rts, 5, ((int16_T *) &gbyk_v4b_B.torque_k));
        }

        /* port 6 */
        {
          _ssSetOutputPortNumDimensions(rts, 6, 1);
          ssSetOutputPortWidth(rts, 6, 1);
          ssSetOutputPortSignal(rts, 6, ((int32_T *) &gbyk_v4b_B.digitalinput));
        }

        /* port 7 */
        {
          _ssSetOutputPortNumDimensions(rts, 7, 1);
          ssSetOutputPortWidth(rts, 7, 1);
          ssSetOutputPortSignal(rts, 7, ((int8_T *)
            &gbyk_v4b_B.actualmodeofoperation));
        }
      }

      /* path info */
      ssSetModelName(rts, "BKIN PDO Receive ElmoDrive");
      ssSetPath(rts,
                "gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M2/A2M2 PDOs/BKIN PDO Receive ElmoDrive");
      ssSetRTModel(rts,gbyk_v4b_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn15.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       gbyk_v4b_P.BKINPDOReceiveElmoDrive_P1_Size_e);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       gbyk_v4b_P.BKINPDOReceiveElmoDrive_P2_Size_m);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       gbyk_v4b_P.BKINPDOReceiveElmoDrive_P3_Size_k);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       gbyk_v4b_P.BKINPDOReceiveElmoDrive_P4_Size_j);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       gbyk_v4b_P.BKINPDOReceiveElmoDrive_P5_Size_o);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       gbyk_v4b_P.BKINPDOReceiveElmoDrive_P6_Size_n);
        ssSetSFcnParam(rts, 6, (mxArray*)
                       gbyk_v4b_P.BKINPDOReceiveElmoDrive_P7_Size_c);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &gbyk_v4b_DW.BKINPDOReceiveElmoDrive_IWORK[0]);
      ssSetPWork(rts, (void **) &gbyk_v4b_DW.BKINPDOReceiveElmoDrive_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn15.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn15.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 7);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &gbyk_v4b_DW.BKINPDOReceiveElmoDrive_IWORK[0]);

        /* PWORK */
        ssSetDWorkWidth(rts, 1, 1);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &gbyk_v4b_DW.BKINPDOReceiveElmoDrive_PWORK);
      }

      /* registration */
      BKINethercatpdorxElmoDrive(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.00025);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 1, 1);
      _ssSetOutputPortConnected(rts, 2, 1);
      _ssSetOutputPortConnected(rts, 3, 1);
      _ssSetOutputPortConnected(rts, 4, 1);
      _ssSetOutputPortConnected(rts, 5, 1);
      _ssSetOutputPortConnected(rts, 6, 1);
      _ssSetOutputPortConnected(rts, 7, 0);
      _ssSetOutputPortBeingMerged(rts, 0, 0);
      _ssSetOutputPortBeingMerged(rts, 1, 0);
      _ssSetOutputPortBeingMerged(rts, 2, 0);
      _ssSetOutputPortBeingMerged(rts, 3, 0);
      _ssSetOutputPortBeingMerged(rts, 4, 0);
      _ssSetOutputPortBeingMerged(rts, 5, 0);
      _ssSetOutputPortBeingMerged(rts, 6, 0);
      _ssSetOutputPortBeingMerged(rts, 7, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: gbyk_v4b/<S76>/BKIN EtherCAT PDO Transmit  (BKINethercatpdotx) */
    {
      SimStruct *rts = gbyk_v4b_M->childSfunctions[16];

      /* timing info */
      time_T *sfcnPeriod = gbyk_v4b_M->NonInlinedSFcns.Sfcn16.sfcnPeriod;
      time_T *sfcnOffset = gbyk_v4b_M->NonInlinedSFcns.Sfcn16.sfcnOffset;
      int_T *sfcnTsMap = gbyk_v4b_M->NonInlinedSFcns.Sfcn16.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &gbyk_v4b_M->NonInlinedSFcns.blkInfo2[16]);
      }

      ssSetRTWSfcnInfo(rts, gbyk_v4b_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &gbyk_v4b_M->NonInlinedSFcns.methods2[16]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &gbyk_v4b_M->NonInlinedSFcns.methods3[16]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &gbyk_v4b_M->NonInlinedSFcns.statesInfo2[16]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn16.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, &gbyk_v4b_B.TorqueMode);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "BKIN EtherCAT PDO Transmit ");
      ssSetPath(rts,
                "gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/BKIN EtherCAT PDO Transmit ");
      ssSetRTModel(rts,gbyk_v4b_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn16.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit_P1_Size_f1);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit_P2_Size_o);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit_P3_Size_o);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit_P4_Size_a);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit_P5_Size_e);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit_P6_Size_l);
        ssSetSFcnParam(rts, 6, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit_P7_Size_d);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &gbyk_v4b_DW.BKINEtherCATPDOTransmit_IWORK_p[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn16.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn16.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 23);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &gbyk_v4b_DW.BKINEtherCATPDOTransmit_IWORK_p[0]);
      }

      /* registration */
      BKINethercatpdotx(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.00025);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: gbyk_v4b/<S76>/BKIN EtherCAT PDO Transmit 1 (BKINethercatpdotx) */
    {
      SimStruct *rts = gbyk_v4b_M->childSfunctions[17];

      /* timing info */
      time_T *sfcnPeriod = gbyk_v4b_M->NonInlinedSFcns.Sfcn17.sfcnPeriod;
      time_T *sfcnOffset = gbyk_v4b_M->NonInlinedSFcns.Sfcn17.sfcnOffset;
      int_T *sfcnTsMap = gbyk_v4b_M->NonInlinedSFcns.Sfcn17.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &gbyk_v4b_M->NonInlinedSFcns.blkInfo2[17]);
      }

      ssSetRTWSfcnInfo(rts, gbyk_v4b_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &gbyk_v4b_M->NonInlinedSFcns.methods2[17]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &gbyk_v4b_M->NonInlinedSFcns.methods3[17]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &gbyk_v4b_M->NonInlinedSFcns.statesInfo2[17]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn17.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, &gbyk_v4b_B.TorqueMode);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "BKIN EtherCAT PDO Transmit 1");
      ssSetPath(rts,
                "gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/BKIN EtherCAT PDO Transmit 1");
      ssSetRTModel(rts,gbyk_v4b_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn17.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit1_P1_Size_l);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit1_P2_Size_m);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit1_P3_Size_a);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit1_P4_Size_l);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit1_P5_Size_i);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit1_P6_Size_h);
        ssSetSFcnParam(rts, 6, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit1_P7_Size_i);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &gbyk_v4b_DW.BKINEtherCATPDOTransmit1_IWORK_p[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn17.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn17.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 23);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &gbyk_v4b_DW.BKINEtherCATPDOTransmit1_IWORK_p[0]);
      }

      /* registration */
      BKINethercatpdotx(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.00025);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: gbyk_v4b/<S137>/BKIN EtherCAT PDO Transmit  (BKINethercatpdotx) */
    {
      SimStruct *rts = gbyk_v4b_M->childSfunctions[18];

      /* timing info */
      time_T *sfcnPeriod = gbyk_v4b_M->NonInlinedSFcns.Sfcn18.sfcnPeriod;
      time_T *sfcnOffset = gbyk_v4b_M->NonInlinedSFcns.Sfcn18.sfcnOffset;
      int_T *sfcnTsMap = gbyk_v4b_M->NonInlinedSFcns.Sfcn18.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &gbyk_v4b_M->NonInlinedSFcns.blkInfo2[18]);
      }

      ssSetRTWSfcnInfo(rts, gbyk_v4b_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &gbyk_v4b_M->NonInlinedSFcns.methods2[18]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &gbyk_v4b_M->NonInlinedSFcns.methods3[18]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &gbyk_v4b_M->NonInlinedSFcns.statesInfo2[18]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn18.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0,
                               &gbyk_v4b_B.sf_ControlGDCWhistleState_p.ControlWord);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "BKIN EtherCAT PDO Transmit ");
      ssSetPath(rts,
                "gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M1/BKIN EtherCAT PDO Transmit ");
      ssSetRTModel(rts,gbyk_v4b_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn18.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit_P1_Size_od);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit_P2_Size_m);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit_P3_Size_g);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit_P4_Size_f);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit_P5_Size_f);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit_P6_Size_g);
        ssSetSFcnParam(rts, 6, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit_P7_Size_h);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &gbyk_v4b_DW.BKINEtherCATPDOTransmit_IWORK_m[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn18.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn18.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 23);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &gbyk_v4b_DW.BKINEtherCATPDOTransmit_IWORK_m[0]);
      }

      /* registration */
      BKINethercatpdotx(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.00025);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: gbyk_v4b/<S138>/BKIN EtherCAT PDO Transmit  (BKINethercatpdotx) */
    {
      SimStruct *rts = gbyk_v4b_M->childSfunctions[19];

      /* timing info */
      time_T *sfcnPeriod = gbyk_v4b_M->NonInlinedSFcns.Sfcn19.sfcnPeriod;
      time_T *sfcnOffset = gbyk_v4b_M->NonInlinedSFcns.Sfcn19.sfcnOffset;
      int_T *sfcnTsMap = gbyk_v4b_M->NonInlinedSFcns.Sfcn19.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &gbyk_v4b_M->NonInlinedSFcns.blkInfo2[19]);
      }

      ssSetRTWSfcnInfo(rts, gbyk_v4b_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &gbyk_v4b_M->NonInlinedSFcns.methods2[19]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &gbyk_v4b_M->NonInlinedSFcns.methods3[19]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &gbyk_v4b_M->NonInlinedSFcns.statesInfo2[19]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn19.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, &gbyk_v4b_B.ControlWord);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "BKIN EtherCAT PDO Transmit ");
      ssSetPath(rts,
                "gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M2/BKIN EtherCAT PDO Transmit ");
      ssSetRTModel(rts,gbyk_v4b_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn19.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit_P1_Size_e);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit_P2_Size_mb);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit_P3_Size_h);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit_P4_Size_m);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit_P5_Size_iz);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit_P6_Size_c);
        ssSetSFcnParam(rts, 6, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit_P7_Size_j);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &gbyk_v4b_DW.BKINEtherCATPDOTransmit_IWORK_h[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn19.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn19.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 23);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &gbyk_v4b_DW.BKINEtherCATPDOTransmit_IWORK_h[0]);
      }

      /* registration */
      BKINethercatpdotx(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.00025);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: gbyk_v4b/<S206>/Send (xpcudpbytesend) */
    {
      SimStruct *rts = gbyk_v4b_M->childSfunctions[20];

      /* timing info */
      time_T *sfcnPeriod = gbyk_v4b_M->NonInlinedSFcns.Sfcn20.sfcnPeriod;
      time_T *sfcnOffset = gbyk_v4b_M->NonInlinedSFcns.Sfcn20.sfcnOffset;
      int_T *sfcnTsMap = gbyk_v4b_M->NonInlinedSFcns.Sfcn20.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &gbyk_v4b_M->NonInlinedSFcns.blkInfo2[20]);
      }

      ssSetRTWSfcnInfo(rts, gbyk_v4b_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &gbyk_v4b_M->NonInlinedSFcns.methods2[20]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &gbyk_v4b_M->NonInlinedSFcns.methods3[20]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &gbyk_v4b_M->NonInlinedSFcns.statesInfo2[20]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn20.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, gbyk_v4b_B.Pack_f);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 8);
        }
      }

      /* path info */
      ssSetModelName(rts, "Send");
      ssSetPath(rts,
                "gbyk_v4b/DataLogging/Poll KINARM/Force Sensor Control/Force Sensor 1 Subsystem/If Action Subsystem/Send");
      ssSetRTModel(rts,gbyk_v4b_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn20.params;
        ssSetSFcnParamsCount(rts, 5);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)gbyk_v4b_P.Send_P1_Size_b4);
        ssSetSFcnParam(rts, 1, (mxArray*)gbyk_v4b_P.Send_P2_Size_b);
        ssSetSFcnParam(rts, 2, (mxArray*)gbyk_v4b_P.Send_P3_Size_d);
        ssSetSFcnParam(rts, 3, (mxArray*)gbyk_v4b_P.Send_P4_Size_lq);
        ssSetSFcnParam(rts, 4, (mxArray*)gbyk_v4b_P.Send_P5_Size_j);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &gbyk_v4b_DW.Send_IWORK_d[0]);
      ssSetPWork(rts, (void **) &gbyk_v4b_DW.Send_PWORK_f);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn20.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn20.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &gbyk_v4b_DW.Send_IWORK_d[0]);

        /* PWORK */
        ssSetDWorkWidth(rts, 1, 1);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &gbyk_v4b_DW.Send_PWORK_f);
      }

      /* registration */
      xpcudpbytesend(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.00025);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetInputPortWidth(rts, 0, 8);
      ssSetInputPortDataType(rts, 0, SS_UINT8);
      ssSetInputPortComplexSignal(rts, 0, 0);
      ssSetInputPortFrameData(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: gbyk_v4b/<S208>/Send (xpcudpbytesend) */
    {
      SimStruct *rts = gbyk_v4b_M->childSfunctions[21];

      /* timing info */
      time_T *sfcnPeriod = gbyk_v4b_M->NonInlinedSFcns.Sfcn21.sfcnPeriod;
      time_T *sfcnOffset = gbyk_v4b_M->NonInlinedSFcns.Sfcn21.sfcnOffset;
      int_T *sfcnTsMap = gbyk_v4b_M->NonInlinedSFcns.Sfcn21.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &gbyk_v4b_M->NonInlinedSFcns.blkInfo2[21]);
      }

      ssSetRTWSfcnInfo(rts, gbyk_v4b_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &gbyk_v4b_M->NonInlinedSFcns.methods2[21]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &gbyk_v4b_M->NonInlinedSFcns.methods3[21]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &gbyk_v4b_M->NonInlinedSFcns.statesInfo2[21]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn21.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, gbyk_v4b_B.Pack);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 8);
        }
      }

      /* path info */
      ssSetModelName(rts, "Send");
      ssSetPath(rts,
                "gbyk_v4b/DataLogging/Poll KINARM/Force Sensor Control/Force Sensor 2 Subsystem/Data Transfer Start Subsystem/Send");
      ssSetRTModel(rts,gbyk_v4b_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn21.params;
        ssSetSFcnParamsCount(rts, 5);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)gbyk_v4b_P.Send_P1_Size_c);
        ssSetSFcnParam(rts, 1, (mxArray*)gbyk_v4b_P.Send_P2_Size_m);
        ssSetSFcnParam(rts, 2, (mxArray*)gbyk_v4b_P.Send_P3_Size_p);
        ssSetSFcnParam(rts, 3, (mxArray*)gbyk_v4b_P.Send_P4_Size_hn);
        ssSetSFcnParam(rts, 4, (mxArray*)gbyk_v4b_P.Send_P5_Size_f);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &gbyk_v4b_DW.Send_IWORK_l[0]);
      ssSetPWork(rts, (void **) &gbyk_v4b_DW.Send_PWORK_h);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn21.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn21.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &gbyk_v4b_DW.Send_IWORK_l[0]);

        /* PWORK */
        ssSetDWorkWidth(rts, 1, 1);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &gbyk_v4b_DW.Send_PWORK_h);
      }

      /* registration */
      xpcudpbytesend(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.00025);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetInputPortWidth(rts, 0, 8);
      ssSetInputPortDataType(rts, 0, SS_UINT8);
      ssSetInputPortComplexSignal(rts, 0, 0);
      ssSetInputPortFrameData(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: gbyk_v4b/<S202>/Receive from Robot 1 Force Sensor (xpcudpbytereceive) */
    {
      SimStruct *rts = gbyk_v4b_M->childSfunctions[22];

      /* timing info */
      time_T *sfcnPeriod = gbyk_v4b_M->NonInlinedSFcns.Sfcn22.sfcnPeriod;
      time_T *sfcnOffset = gbyk_v4b_M->NonInlinedSFcns.Sfcn22.sfcnOffset;
      int_T *sfcnTsMap = gbyk_v4b_M->NonInlinedSFcns.Sfcn22.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &gbyk_v4b_M->NonInlinedSFcns.blkInfo2[22]);
      }

      ssSetRTWSfcnInfo(rts, gbyk_v4b_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &gbyk_v4b_M->NonInlinedSFcns.methods2[22]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &gbyk_v4b_M->NonInlinedSFcns.methods3[22]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &gbyk_v4b_M->NonInlinedSFcns.statesInfo2[22]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn22.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 2);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 36);
          ssSetOutputPortSignal(rts, 0, ((uint8_T *)
            gbyk_v4b_B.ReceivefromRobot1ForceSensor_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((real_T *)
            &gbyk_v4b_B.ReceivefromRobot1ForceSensor_o2));
        }
      }

      /* path info */
      ssSetModelName(rts, "Receive from Robot 1 Force Sensor");
      ssSetPath(rts,
                "gbyk_v4b/DataLogging/Poll KINARM/Force Sensor Control/Force Sensor 1 Subsystem/Receive from Robot 1 Force Sensor");
      ssSetRTModel(rts,gbyk_v4b_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn22.params;
        ssSetSFcnParamsCount(rts, 5);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       gbyk_v4b_P.ReceivefromRobot1ForceSensor_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       gbyk_v4b_P.ReceivefromRobot1ForceSensor_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       gbyk_v4b_P.ReceivefromRobot1ForceSensor_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       gbyk_v4b_P.ReceivefromRobot1ForceSensor_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       gbyk_v4b_P.ReceivefromRobot1ForceSensor_P5_Size);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &gbyk_v4b_DW.ReceivefromRobot1ForceSensor_IWORK
                 [0]);
      ssSetPWork(rts, (void **) &gbyk_v4b_DW.ReceivefromRobot1ForceSensor_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn22.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn22.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &gbyk_v4b_DW.ReceivefromRobot1ForceSensor_IWORK[0]);

        /* PWORK */
        ssSetDWorkWidth(rts, 1, 1);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &gbyk_v4b_DW.ReceivefromRobot1ForceSensor_PWORK);
      }

      /* registration */
      xpcudpbytereceive(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.00025);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 1, 0);
      _ssSetOutputPortBeingMerged(rts, 0, 0);
      _ssSetOutputPortBeingMerged(rts, 1, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: gbyk_v4b/<S203>/Receive from Robot 2 Force Sensor (xpcudpbytereceive) */
    {
      SimStruct *rts = gbyk_v4b_M->childSfunctions[23];

      /* timing info */
      time_T *sfcnPeriod = gbyk_v4b_M->NonInlinedSFcns.Sfcn23.sfcnPeriod;
      time_T *sfcnOffset = gbyk_v4b_M->NonInlinedSFcns.Sfcn23.sfcnOffset;
      int_T *sfcnTsMap = gbyk_v4b_M->NonInlinedSFcns.Sfcn23.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &gbyk_v4b_M->NonInlinedSFcns.blkInfo2[23]);
      }

      ssSetRTWSfcnInfo(rts, gbyk_v4b_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &gbyk_v4b_M->NonInlinedSFcns.methods2[23]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &gbyk_v4b_M->NonInlinedSFcns.methods3[23]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &gbyk_v4b_M->NonInlinedSFcns.statesInfo2[23]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn23.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 2);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 36);
          ssSetOutputPortSignal(rts, 0, ((uint8_T *)
            gbyk_v4b_B.ReceivefromRobot2ForceSensor_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((real_T *)
            &gbyk_v4b_B.ReceivefromRobot2ForceSensor_o2));
        }
      }

      /* path info */
      ssSetModelName(rts, "Receive from Robot 2 Force Sensor");
      ssSetPath(rts,
                "gbyk_v4b/DataLogging/Poll KINARM/Force Sensor Control/Force Sensor 2 Subsystem/Receive from Robot 2 Force Sensor");
      ssSetRTModel(rts,gbyk_v4b_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn23.params;
        ssSetSFcnParamsCount(rts, 5);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       gbyk_v4b_P.ReceivefromRobot2ForceSensor_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       gbyk_v4b_P.ReceivefromRobot2ForceSensor_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       gbyk_v4b_P.ReceivefromRobot2ForceSensor_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       gbyk_v4b_P.ReceivefromRobot2ForceSensor_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       gbyk_v4b_P.ReceivefromRobot2ForceSensor_P5_Size);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &gbyk_v4b_DW.ReceivefromRobot2ForceSensor_IWORK
                 [0]);
      ssSetPWork(rts, (void **) &gbyk_v4b_DW.ReceivefromRobot2ForceSensor_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn23.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn23.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &gbyk_v4b_DW.ReceivefromRobot2ForceSensor_IWORK[0]);

        /* PWORK */
        ssSetDWorkWidth(rts, 1, 1);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &gbyk_v4b_DW.ReceivefromRobot2ForceSensor_PWORK);
      }

      /* registration */
      xpcudpbytereceive(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.00025);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 1, 0);
      _ssSetOutputPortBeingMerged(rts, 0, 0);
      _ssSetOutputPortBeingMerged(rts, 1, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: gbyk_v4b/<S217>/Read (mcc_readmem) */
    {
      SimStruct *rts = gbyk_v4b_M->childSfunctions[24];

      /* timing info */
      time_T *sfcnPeriod = gbyk_v4b_M->NonInlinedSFcns.Sfcn24.sfcnPeriod;
      time_T *sfcnOffset = gbyk_v4b_M->NonInlinedSFcns.Sfcn24.sfcnOffset;
      int_T *sfcnTsMap = gbyk_v4b_M->NonInlinedSFcns.Sfcn24.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &gbyk_v4b_M->NonInlinedSFcns.blkInfo2[24]);
      }

      ssSetRTWSfcnInfo(rts, gbyk_v4b_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &gbyk_v4b_M->NonInlinedSFcns.methods2[24]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &gbyk_v4b_M->NonInlinedSFcns.methods3[24]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &gbyk_v4b_M->NonInlinedSFcns.statesInfo2[24]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn24.inputPortInfo[0]);

        /* port 0 */
        {
          uint32_T const **sfcnUPtrs = (uint32_T const **)
            &gbyk_v4b_M->NonInlinedSFcns.Sfcn24.UPtrs0;
          sfcnUPtrs[0] = &gbyk_v4b_B.DataTypeConversion_pj;
          sfcnUPtrs[1] = &gbyk_v4b_B.DataTypeConversion2_pm;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 2);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn24.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real32_T *) &gbyk_v4b_B.Read_h));
        }
      }

      /* path info */
      ssSetModelName(rts, "Read");
      ssSetPath(rts,
                "gbyk_v4b/DataLogging/Poll KINARM/PMAC Subsystem/read_pmac/DPRAM Access Subsystem/Read DPRAM/Read");
      ssSetRTModel(rts,gbyk_v4b_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* work vectors */
      ssSetPWork(rts, (void **) &gbyk_v4b_DW.Read_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn24.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn24.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &gbyk_v4b_DW.Read_PWORK);
      }

      /* registration */
      mcc_readmem(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.00025);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: gbyk_v4b/<S219>/Write (mcc_writemem) */
    {
      SimStruct *rts = gbyk_v4b_M->childSfunctions[25];

      /* timing info */
      time_T *sfcnPeriod = gbyk_v4b_M->NonInlinedSFcns.Sfcn25.sfcnPeriod;
      time_T *sfcnOffset = gbyk_v4b_M->NonInlinedSFcns.Sfcn25.sfcnOffset;
      int_T *sfcnTsMap = gbyk_v4b_M->NonInlinedSFcns.Sfcn25.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &gbyk_v4b_M->NonInlinedSFcns.blkInfo2[25]);
      }

      ssSetRTWSfcnInfo(rts, gbyk_v4b_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &gbyk_v4b_M->NonInlinedSFcns.methods2[25]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &gbyk_v4b_M->NonInlinedSFcns.methods3[25]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &gbyk_v4b_M->NonInlinedSFcns.statesInfo2[25]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn25.inputPortInfo[0]);

        /* port 0 */
        {
          uint32_T const **sfcnUPtrs = (uint32_T const **)
            &gbyk_v4b_M->NonInlinedSFcns.Sfcn25.UPtrs0;
          sfcnUPtrs[0] = &gbyk_v4b_B.DataTypeConversion_dd;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          real32_T const **sfcnUPtrs = (real32_T const **)
            &gbyk_v4b_M->NonInlinedSFcns.Sfcn25.UPtrs1;
          sfcnUPtrs[0] = &gbyk_v4b_B.DataTypeConversion1_o;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "Write");
      ssSetPath(rts,
                "gbyk_v4b/DataLogging/Poll KINARM/PMAC Subsystem/read_pmac/DPRAM Access Subsystem/Write DPRAM/Write");
      ssSetRTModel(rts,gbyk_v4b_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* work vectors */
      ssSetPWork(rts, (void **) &gbyk_v4b_DW.Write_PWORK_i);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn25.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn25.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &gbyk_v4b_DW.Write_PWORK_i);
      }

      /* registration */
      mcc_writemem(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.00025);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetInputPortConnected(rts, 1, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
    }

    /* Level2 S-Function Block: gbyk_v4b/<S210>/S-Function (mcc_pollall) */
    {
      SimStruct *rts = gbyk_v4b_M->childSfunctions[26];

      /* timing info */
      time_T *sfcnPeriod = gbyk_v4b_M->NonInlinedSFcns.Sfcn26.sfcnPeriod;
      time_T *sfcnOffset = gbyk_v4b_M->NonInlinedSFcns.Sfcn26.sfcnOffset;
      int_T *sfcnTsMap = gbyk_v4b_M->NonInlinedSFcns.Sfcn26.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &gbyk_v4b_M->NonInlinedSFcns.blkInfo2[26]);
      }

      ssSetRTWSfcnInfo(rts, gbyk_v4b_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &gbyk_v4b_M->NonInlinedSFcns.methods2[26]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &gbyk_v4b_M->NonInlinedSFcns.methods3[26]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &gbyk_v4b_M->NonInlinedSFcns.statesInfo2[26]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 3);
        ssSetPortInfoForInputs(rts,
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn26.inputPortInfo[0]);

        /* port 0 */
        {
          real32_T const **sfcnUPtrs = (real32_T const **)
            &gbyk_v4b_M->NonInlinedSFcns.Sfcn26.UPtrs0;

          {
            int_T i1;
            const real32_T *u0 = gbyk_v4b_B.DataTypeConversion_a5;
            for (i1=0; i1 < 10; i1++) {
              sfcnUPtrs[i1] = &u0[i1];
            }
          }

          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 10);
        }

        /* port 1 */
        {
          real32_T const **sfcnUPtrs = (real32_T const **)
            &gbyk_v4b_M->NonInlinedSFcns.Sfcn26.UPtrs1;

          {
            int_T i1;
            const real32_T *u1 = gbyk_v4b_B.DataTypeConversion1_i1;
            for (i1=0; i1 < 10; i1++) {
              sfcnUPtrs[i1] = &u1[i1];
            }
          }

          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 10);
        }

        /* port 2 */
        {
          real32_T const **sfcnUPtrs = (real32_T const **)
            &gbyk_v4b_M->NonInlinedSFcns.Sfcn26.UPtrs2;
          sfcnUPtrs[0] = &gbyk_v4b_B.DataTypeConversion2_h;
          ssSetInputPortSignalPtrs(rts, 2, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 2, 1);
          ssSetInputPortWidth(rts, 2, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn26.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 10);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 10);
          ssSetOutputPortSignal(rts, 0, ((real32_T *) gbyk_v4b_B.SFunction_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 10);
          ssSetOutputPortSignal(rts, 1, ((real32_T *) gbyk_v4b_B.SFunction_o2));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidth(rts, 2, 2);
          ssSetOutputPortSignal(rts, 2, ((uint32_T *) gbyk_v4b_B.SFunction_o3));
        }

        /* port 3 */
        {
          _ssSetOutputPortNumDimensions(rts, 3, 1);
          ssSetOutputPortWidth(rts, 3, 4);
          ssSetOutputPortSignal(rts, 3, ((real32_T *) gbyk_v4b_B.SFunction_o4));
        }

        /* port 4 */
        {
          _ssSetOutputPortNumDimensions(rts, 4, 1);
          ssSetOutputPortWidth(rts, 4, 6);
          ssSetOutputPortSignal(rts, 4, ((real32_T *) gbyk_v4b_B.SFunction_o5));
        }

        /* port 5 */
        {
          _ssSetOutputPortNumDimensions(rts, 5, 1);
          ssSetOutputPortWidth(rts, 5, 6);
          ssSetOutputPortSignal(rts, 5, ((real32_T *) gbyk_v4b_B.SFunction_o6));
        }

        /* port 6 */
        {
          _ssSetOutputPortNumDimensions(rts, 6, 1);
          ssSetOutputPortWidth(rts, 6, 1);
          ssSetOutputPortSignal(rts, 6, ((uint32_T *) &gbyk_v4b_B.SFunction_o7));
        }

        /* port 7 */
        {
          _ssSetOutputPortNumDimensions(rts, 7, 1);
          ssSetOutputPortWidth(rts, 7, 1);
          ssSetOutputPortSignal(rts, 7, ((uint32_T *) &gbyk_v4b_B.SFunction_o8));
        }

        /* port 8 */
        {
          _ssSetOutputPortNumDimensions(rts, 8, 1);
          ssSetOutputPortWidth(rts, 8, 3);
          ssSetOutputPortSignal(rts, 8, ((uint32_T *) gbyk_v4b_B.SFunction_o9));
        }

        /* port 9 */
        {
          _ssSetOutputPortNumDimensions(rts, 9, 1);
          ssSetOutputPortWidth(rts, 9, 1);
          ssSetOutputPortSignal(rts, 9, ((real32_T *) &gbyk_v4b_B.SFunction_o10));
        }
      }

      /* path info */
      ssSetModelName(rts, "S-Function");
      ssSetPath(rts,
                "gbyk_v4b/DataLogging/Poll KINARM/PMAC Subsystem/read_pmac/S-Function");
      ssSetRTModel(rts,gbyk_v4b_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* work vectors */
      ssSetPWork(rts, (void **) &gbyk_v4b_DW.SFunction_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn26.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn26.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &gbyk_v4b_DW.SFunction_PWORK);
      }

      /* registration */
      mcc_pollall(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.00025);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetInputPortConnected(rts, 1, 1);
      _ssSetInputPortConnected(rts, 2, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 1, 1);
      _ssSetOutputPortConnected(rts, 2, 1);
      _ssSetOutputPortConnected(rts, 3, 1);
      _ssSetOutputPortConnected(rts, 4, 1);
      _ssSetOutputPortConnected(rts, 5, 1);
      _ssSetOutputPortConnected(rts, 6, 1);
      _ssSetOutputPortConnected(rts, 7, 0);
      _ssSetOutputPortConnected(rts, 8, 1);
      _ssSetOutputPortConnected(rts, 9, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);
      _ssSetOutputPortBeingMerged(rts, 1, 0);
      _ssSetOutputPortBeingMerged(rts, 2, 0);
      _ssSetOutputPortBeingMerged(rts, 3, 0);
      _ssSetOutputPortBeingMerged(rts, 4, 0);
      _ssSetOutputPortBeingMerged(rts, 5, 0);
      _ssSetOutputPortBeingMerged(rts, 6, 0);
      _ssSetOutputPortBeingMerged(rts, 7, 0);
      _ssSetOutputPortBeingMerged(rts, 8, 0);
      _ssSetOutputPortBeingMerged(rts, 9, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
      ssSetInputPortBufferDstPort(rts, 2, -1);
    }

    /* Level2 S-Function Block: gbyk_v4b/<S212>/Write (mcc_writemem) */
    {
      SimStruct *rts = gbyk_v4b_M->childSfunctions[27];

      /* timing info */
      time_T *sfcnPeriod = gbyk_v4b_M->NonInlinedSFcns.Sfcn27.sfcnPeriod;
      time_T *sfcnOffset = gbyk_v4b_M->NonInlinedSFcns.Sfcn27.sfcnOffset;
      int_T *sfcnTsMap = gbyk_v4b_M->NonInlinedSFcns.Sfcn27.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &gbyk_v4b_M->NonInlinedSFcns.blkInfo2[27]);
      }

      ssSetRTWSfcnInfo(rts, gbyk_v4b_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &gbyk_v4b_M->NonInlinedSFcns.methods2[27]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &gbyk_v4b_M->NonInlinedSFcns.methods3[27]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &gbyk_v4b_M->NonInlinedSFcns.statesInfo2[27]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn27.inputPortInfo[0]);

        /* port 0 */
        {
          uint32_T const **sfcnUPtrs = (uint32_T const **)
            &gbyk_v4b_M->NonInlinedSFcns.Sfcn27.UPtrs0;
          sfcnUPtrs[0] = &gbyk_v4b_B.DataTypeConversion_l;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          real32_T const **sfcnUPtrs = (real32_T const **)
            &gbyk_v4b_M->NonInlinedSFcns.Sfcn27.UPtrs1;
          sfcnUPtrs[0] = &gbyk_v4b_B.y_j;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "Write");
      ssSetPath(rts,
                "gbyk_v4b/DataLogging/Poll KINARM/PMAC Subsystem/read_pmac/DPRAM Access Subsystem/Write");
      ssSetRTModel(rts,gbyk_v4b_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* work vectors */
      ssSetPWork(rts, (void **) &gbyk_v4b_DW.Write_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn27.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn27.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &gbyk_v4b_DW.Write_PWORK);
      }

      /* registration */
      mcc_writemem(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.00025);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetInputPortConnected(rts, 1, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
    }

    /* Level2 S-Function Block: gbyk_v4b/<S223>/Receive (xpcudpbytereceive) */
    {
      SimStruct *rts = gbyk_v4b_M->childSfunctions[28];

      /* timing info */
      time_T *sfcnPeriod = gbyk_v4b_M->NonInlinedSFcns.Sfcn28.sfcnPeriod;
      time_T *sfcnOffset = gbyk_v4b_M->NonInlinedSFcns.Sfcn28.sfcnOffset;
      int_T *sfcnTsMap = gbyk_v4b_M->NonInlinedSFcns.Sfcn28.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &gbyk_v4b_M->NonInlinedSFcns.blkInfo2[28]);
      }

      ssSetRTWSfcnInfo(rts, gbyk_v4b_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &gbyk_v4b_M->NonInlinedSFcns.methods2[28]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &gbyk_v4b_M->NonInlinedSFcns.methods3[28]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &gbyk_v4b_M->NonInlinedSFcns.statesInfo2[28]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn28.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 2);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 16);
          ssSetOutputPortSignal(rts, 0, ((uint8_T *) gbyk_v4b_B.Receive_o1_n));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((real_T *) &gbyk_v4b_B.Receive_o2_o));
        }
      }

      /* path info */
      ssSetModelName(rts, "Receive");
      ssSetPath(rts,
                "gbyk_v4b/DataLogging/Poll KINARM/bkin_internal_testing/Data receive/Receive");
      ssSetRTModel(rts,gbyk_v4b_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn28.params;
        ssSetSFcnParamsCount(rts, 5);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)gbyk_v4b_P.Receive_P1_Size_b);
        ssSetSFcnParam(rts, 1, (mxArray*)gbyk_v4b_P.Receive_P2_Size_j);
        ssSetSFcnParam(rts, 2, (mxArray*)gbyk_v4b_P.Receive_P3_Size_k);
        ssSetSFcnParam(rts, 3, (mxArray*)gbyk_v4b_P.Receive_P4_Size_o);
        ssSetSFcnParam(rts, 4, (mxArray*)gbyk_v4b_P.Receive_P5_Size_g);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &gbyk_v4b_DW.Receive_IWORK_f[0]);
      ssSetPWork(rts, (void **) &gbyk_v4b_DW.Receive_PWORK_n);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn28.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn28.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &gbyk_v4b_DW.Receive_IWORK_f[0]);

        /* PWORK */
        ssSetDWorkWidth(rts, 1, 1);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &gbyk_v4b_DW.Receive_PWORK_n);
      }

      /* registration */
      xpcudpbytereceive(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.00025);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 1, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);
      _ssSetOutputPortBeingMerged(rts, 1, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: gbyk_v4b/<S79>/BKIN EtherCAT PDO Transmit  (BKINethercatpdotx) */
    {
      SimStruct *rts = gbyk_v4b_M->childSfunctions[29];

      /* timing info */
      time_T *sfcnPeriod = gbyk_v4b_M->NonInlinedSFcns.Sfcn29.sfcnPeriod;
      time_T *sfcnOffset = gbyk_v4b_M->NonInlinedSFcns.Sfcn29.sfcnOffset;
      int_T *sfcnTsMap = gbyk_v4b_M->NonInlinedSFcns.Sfcn29.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &gbyk_v4b_M->NonInlinedSFcns.blkInfo2[29]);
      }

      ssSetRTWSfcnInfo(rts, gbyk_v4b_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &gbyk_v4b_M->NonInlinedSFcns.methods2[29]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &gbyk_v4b_M->NonInlinedSFcns.methods3[29]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &gbyk_v4b_M->NonInlinedSFcns.statesInfo2[29]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn29.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, &gbyk_v4b_B.drive1);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "BKIN EtherCAT PDO Transmit ");
      ssSetPath(rts,
                "gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Digital output/BKIN EtherCAT PDO Transmit ");
      ssSetRTModel(rts,gbyk_v4b_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn29.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit_P1_Size_n);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit_P2_Size_b);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit_P3_Size_b);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit_P4_Size_fk);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit_P5_Size_g);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit_P6_Size_k);
        ssSetSFcnParam(rts, 6, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit_P7_Size_gy);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &gbyk_v4b_DW.BKINEtherCATPDOTransmit_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn29.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn29.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 23);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &gbyk_v4b_DW.BKINEtherCATPDOTransmit_IWORK[0]);
      }

      /* registration */
      BKINethercatpdotx(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.00025);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: gbyk_v4b/<S79>/BKIN EtherCAT PDO Transmit 1 (BKINethercatpdotx) */
    {
      SimStruct *rts = gbyk_v4b_M->childSfunctions[30];

      /* timing info */
      time_T *sfcnPeriod = gbyk_v4b_M->NonInlinedSFcns.Sfcn30.sfcnPeriod;
      time_T *sfcnOffset = gbyk_v4b_M->NonInlinedSFcns.Sfcn30.sfcnOffset;
      int_T *sfcnTsMap = gbyk_v4b_M->NonInlinedSFcns.Sfcn30.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &gbyk_v4b_M->NonInlinedSFcns.blkInfo2[30]);
      }

      ssSetRTWSfcnInfo(rts, gbyk_v4b_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &gbyk_v4b_M->NonInlinedSFcns.methods2[30]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &gbyk_v4b_M->NonInlinedSFcns.methods3[30]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &gbyk_v4b_M->NonInlinedSFcns.statesInfo2[30]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn30.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, &gbyk_v4b_B.drive2);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "BKIN EtherCAT PDO Transmit 1");
      ssSetPath(rts,
                "gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Digital output/BKIN EtherCAT PDO Transmit 1");
      ssSetRTModel(rts,gbyk_v4b_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn30.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit1_P1_Size_b);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit1_P2_Size_p);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit1_P3_Size_g);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit1_P4_Size_c);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit1_P5_Size_m);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit1_P6_Size_p);
        ssSetSFcnParam(rts, 6, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit1_P7_Size_f);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &gbyk_v4b_DW.BKINEtherCATPDOTransmit1_IWORK_m[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn30.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn30.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 23);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &gbyk_v4b_DW.BKINEtherCATPDOTransmit1_IWORK_m[0]);
      }

      /* registration */
      BKINethercatpdotx(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.00025);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: gbyk_v4b/<S79>/BKIN EtherCAT PDO Transmit 2 (BKINethercatpdotx) */
    {
      SimStruct *rts = gbyk_v4b_M->childSfunctions[31];

      /* timing info */
      time_T *sfcnPeriod = gbyk_v4b_M->NonInlinedSFcns.Sfcn31.sfcnPeriod;
      time_T *sfcnOffset = gbyk_v4b_M->NonInlinedSFcns.Sfcn31.sfcnOffset;
      int_T *sfcnTsMap = gbyk_v4b_M->NonInlinedSFcns.Sfcn31.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &gbyk_v4b_M->NonInlinedSFcns.blkInfo2[31]);
      }

      ssSetRTWSfcnInfo(rts, gbyk_v4b_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &gbyk_v4b_M->NonInlinedSFcns.methods2[31]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &gbyk_v4b_M->NonInlinedSFcns.methods3[31]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &gbyk_v4b_M->NonInlinedSFcns.statesInfo2[31]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn31.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, &gbyk_v4b_B.drive3);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "BKIN EtherCAT PDO Transmit 2");
      ssSetPath(rts,
                "gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Digital output/BKIN EtherCAT PDO Transmit 2");
      ssSetRTModel(rts,gbyk_v4b_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn31.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit2_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit2_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit2_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit2_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit2_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit2_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit2_P7_Size);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &gbyk_v4b_DW.BKINEtherCATPDOTransmit2_IWORK_d[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn31.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn31.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 23);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &gbyk_v4b_DW.BKINEtherCATPDOTransmit2_IWORK_d[0]);
      }

      /* registration */
      BKINethercatpdotx(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.00025);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: gbyk_v4b/<S79>/BKIN EtherCAT PDO Transmit 3 (BKINethercatpdotx) */
    {
      SimStruct *rts = gbyk_v4b_M->childSfunctions[32];

      /* timing info */
      time_T *sfcnPeriod = gbyk_v4b_M->NonInlinedSFcns.Sfcn32.sfcnPeriod;
      time_T *sfcnOffset = gbyk_v4b_M->NonInlinedSFcns.Sfcn32.sfcnOffset;
      int_T *sfcnTsMap = gbyk_v4b_M->NonInlinedSFcns.Sfcn32.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &gbyk_v4b_M->NonInlinedSFcns.blkInfo2[32]);
      }

      ssSetRTWSfcnInfo(rts, gbyk_v4b_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &gbyk_v4b_M->NonInlinedSFcns.methods2[32]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &gbyk_v4b_M->NonInlinedSFcns.methods3[32]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &gbyk_v4b_M->NonInlinedSFcns.statesInfo2[32]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn32.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, &gbyk_v4b_B.drive4);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "BKIN EtherCAT PDO Transmit 3");
      ssSetPath(rts,
                "gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Digital output/BKIN EtherCAT PDO Transmit 3");
      ssSetRTModel(rts,gbyk_v4b_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn32.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit3_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit3_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit3_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit3_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit3_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit3_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit3_P7_Size);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &gbyk_v4b_DW.BKINEtherCATPDOTransmit3_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn32.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn32.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 23);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &gbyk_v4b_DW.BKINEtherCATPDOTransmit3_IWORK[0]);
      }

      /* registration */
      BKINethercatpdotx(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.00025);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: gbyk_v4b/<S35>/S-Function (eyelink_unpack) */
    {
      SimStruct *rts = gbyk_v4b_M->childSfunctions[33];

      /* timing info */
      time_T *sfcnPeriod = gbyk_v4b_M->NonInlinedSFcns.Sfcn33.sfcnPeriod;
      time_T *sfcnOffset = gbyk_v4b_M->NonInlinedSFcns.Sfcn33.sfcnOffset;
      int_T *sfcnTsMap = gbyk_v4b_M->NonInlinedSFcns.Sfcn33.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &gbyk_v4b_M->NonInlinedSFcns.blkInfo2[33]);
      }

      ssSetRTWSfcnInfo(rts, gbyk_v4b_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &gbyk_v4b_M->NonInlinedSFcns.methods2[33]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &gbyk_v4b_M->NonInlinedSFcns.methods3[33]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &gbyk_v4b_M->NonInlinedSFcns.statesInfo2[33]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn33.inputPortInfo[0]);

        /* port 0 */
        {
          uint8_T const **sfcnUPtrs = (uint8_T const **)
            &gbyk_v4b_M->NonInlinedSFcns.Sfcn33.UPtrs0;

          {
            int_T i1;
            const uint8_T *u0 = gbyk_v4b_B.pack_out;
            for (i1=0; i1 < 512; i1++) {
              sfcnUPtrs[i1] = &u0[i1];
            }
          }

          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 512);
        }

        /* port 1 */
        {
          int32_T const **sfcnUPtrs = (int32_T const **)
            &gbyk_v4b_M->NonInlinedSFcns.Sfcn33.UPtrs1;
          sfcnUPtrs[0] = &gbyk_v4b_B.len_out;
          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn33.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 18);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((uint32_T *) &gbyk_v4b_B.SFunction_o1_n));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((int16_T *) &gbyk_v4b_B.SAMPE_TYPE));
        }

        /* port 2 */
        {
          _ssSetOutputPortNumDimensions(rts, 2, 1);
          ssSetOutputPortWidth(rts, 2, 1);
          ssSetOutputPortSignal(rts, 2, ((uint16_T *) &gbyk_v4b_B.ContentFlags));
        }

        /* port 3 */
        {
          _ssSetOutputPortNumDimensions(rts, 3, 1);
          ssSetOutputPortWidth(rts, 3, 2);
          ssSetOutputPortSignal(rts, 3, ((real32_T *) gbyk_v4b_B.pupilX));
        }

        /* port 4 */
        {
          _ssSetOutputPortNumDimensions(rts, 4, 1);
          ssSetOutputPortWidth(rts, 4, 2);
          ssSetOutputPortSignal(rts, 4, ((real32_T *) gbyk_v4b_B.pupilY));
        }

        /* port 5 */
        {
          _ssSetOutputPortNumDimensions(rts, 5, 1);
          ssSetOutputPortWidth(rts, 5, 2);
          ssSetOutputPortSignal(rts, 5, ((real32_T *) gbyk_v4b_B.HREFX));
        }

        /* port 6 */
        {
          _ssSetOutputPortNumDimensions(rts, 6, 1);
          ssSetOutputPortWidth(rts, 6, 2);
          ssSetOutputPortSignal(rts, 6, ((real32_T *) gbyk_v4b_B.HREFY));
        }

        /* port 7 */
        {
          _ssSetOutputPortNumDimensions(rts, 7, 1);
          ssSetOutputPortWidth(rts, 7, 2);
          ssSetOutputPortSignal(rts, 7, ((real32_T *) gbyk_v4b_B.pupilarea));
        }

        /* port 8 */
        {
          _ssSetOutputPortNumDimensions(rts, 8, 1);
          ssSetOutputPortWidth(rts, 8, 2);
          ssSetOutputPortSignal(rts, 8, ((real32_T *) gbyk_v4b_B.screengazeX));
        }

        /* port 9 */
        {
          _ssSetOutputPortNumDimensions(rts, 9, 1);
          ssSetOutputPortWidth(rts, 9, 2);
          ssSetOutputPortSignal(rts, 9, ((real32_T *) gbyk_v4b_B.screengazeY));
        }

        /* port 10 */
        {
          _ssSetOutputPortNumDimensions(rts, 10, 1);
          ssSetOutputPortWidth(rts, 10, 1);
          ssSetOutputPortSignal(rts, 10, ((real32_T *) &gbyk_v4b_B.resolutionX));
        }

        /* port 11 */
        {
          _ssSetOutputPortNumDimensions(rts, 11, 1);
          ssSetOutputPortWidth(rts, 11, 1);
          ssSetOutputPortSignal(rts, 11, ((real32_T *) &gbyk_v4b_B.resolutionY));
        }

        /* port 12 */
        {
          _ssSetOutputPortNumDimensions(rts, 12, 1);
          ssSetOutputPortWidth(rts, 12, 1);
          ssSetOutputPortSignal(rts, 12, ((uint16_T *) &gbyk_v4b_B.statusflags));
        }

        /* port 13 */
        {
          _ssSetOutputPortNumDimensions(rts, 13, 1);
          ssSetOutputPortWidth(rts, 13, 1);
          ssSetOutputPortSignal(rts, 13, ((uint16_T *) &gbyk_v4b_B.extrainput));
        }

        /* port 14 */
        {
          _ssSetOutputPortNumDimensions(rts, 14, 1);
          ssSetOutputPortWidth(rts, 14, 1);
          ssSetOutputPortSignal(rts, 14, ((uint16_T *) &gbyk_v4b_B.buttons));
        }

        /* port 15 */
        {
          _ssSetOutputPortNumDimensions(rts, 15, 1);
          ssSetOutputPortWidth(rts, 15, 1);
          ssSetOutputPortSignal(rts, 15, ((int16_T *) &gbyk_v4b_B.htype));
        }

        /* port 16 */
        {
          _ssSetOutputPortNumDimensions(rts, 16, 1);
          ssSetOutputPortWidth(rts, 16, 8);
          ssSetOutputPortSignal(rts, 16, ((int16_T *) gbyk_v4b_B.hdata));
        }

        /* port 17 */
        {
          _ssSetOutputPortNumDimensions(rts, 17, 1);
          ssSetOutputPortWidth(rts, 17, 3);
          ssSetOutputPortSignal(rts, 17, ((uint32_T *) gbyk_v4b_B.SFunction_o18));
        }
      }

      /* path info */
      ssSetModelName(rts, "S-Function");
      ssSetPath(rts, "gbyk_v4b/DataLogging/Receive_Gaze/S-Function");
      ssSetRTModel(rts,gbyk_v4b_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* registration */
      eyelink_unpack(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.00025);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetInputPortConnected(rts, 1, 1);
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 1, 0);
      _ssSetOutputPortConnected(rts, 2, 0);
      _ssSetOutputPortConnected(rts, 3, 1);
      _ssSetOutputPortConnected(rts, 4, 1);
      _ssSetOutputPortConnected(rts, 5, 1);
      _ssSetOutputPortConnected(rts, 6, 1);
      _ssSetOutputPortConnected(rts, 7, 1);
      _ssSetOutputPortConnected(rts, 8, 0);
      _ssSetOutputPortConnected(rts, 9, 0);
      _ssSetOutputPortConnected(rts, 10, 0);
      _ssSetOutputPortConnected(rts, 11, 0);
      _ssSetOutputPortConnected(rts, 12, 1);
      _ssSetOutputPortConnected(rts, 13, 0);
      _ssSetOutputPortConnected(rts, 14, 0);
      _ssSetOutputPortConnected(rts, 15, 0);
      _ssSetOutputPortConnected(rts, 16, 1);
      _ssSetOutputPortConnected(rts, 17, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);
      _ssSetOutputPortBeingMerged(rts, 1, 0);
      _ssSetOutputPortBeingMerged(rts, 2, 0);
      _ssSetOutputPortBeingMerged(rts, 3, 0);
      _ssSetOutputPortBeingMerged(rts, 4, 0);
      _ssSetOutputPortBeingMerged(rts, 5, 0);
      _ssSetOutputPortBeingMerged(rts, 6, 0);
      _ssSetOutputPortBeingMerged(rts, 7, 0);
      _ssSetOutputPortBeingMerged(rts, 8, 0);
      _ssSetOutputPortBeingMerged(rts, 9, 0);
      _ssSetOutputPortBeingMerged(rts, 10, 0);
      _ssSetOutputPortBeingMerged(rts, 11, 0);
      _ssSetOutputPortBeingMerged(rts, 12, 0);
      _ssSetOutputPortBeingMerged(rts, 13, 0);
      _ssSetOutputPortBeingMerged(rts, 14, 0);
      _ssSetOutputPortBeingMerged(rts, 15, 0);
      _ssSetOutputPortBeingMerged(rts, 16, 0);
      _ssSetOutputPortBeingMerged(rts, 17, 0);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
    }

    /* Level2 S-Function Block: gbyk_v4b/<S35>/Receive (xpcudpbytereceive) */
    {
      SimStruct *rts = gbyk_v4b_M->childSfunctions[34];

      /* timing info */
      time_T *sfcnPeriod = gbyk_v4b_M->NonInlinedSFcns.Sfcn34.sfcnPeriod;
      time_T *sfcnOffset = gbyk_v4b_M->NonInlinedSFcns.Sfcn34.sfcnOffset;
      int_T *sfcnTsMap = gbyk_v4b_M->NonInlinedSFcns.Sfcn34.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &gbyk_v4b_M->NonInlinedSFcns.blkInfo2[34]);
      }

      ssSetRTWSfcnInfo(rts, gbyk_v4b_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &gbyk_v4b_M->NonInlinedSFcns.methods2[34]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &gbyk_v4b_M->NonInlinedSFcns.methods3[34]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &gbyk_v4b_M->NonInlinedSFcns.statesInfo2[34]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn34.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 2);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 512);
          ssSetOutputPortSignal(rts, 0, ((uint8_T *) gbyk_v4b_B.Receive_o1_i));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((real_T *) &gbyk_v4b_B.Receive_o2_j));
        }
      }

      /* path info */
      ssSetModelName(rts, "Receive");
      ssSetPath(rts, "gbyk_v4b/DataLogging/Receive_Gaze/Receive");
      ssSetRTModel(rts,gbyk_v4b_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn34.params;
        ssSetSFcnParamsCount(rts, 5);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)gbyk_v4b_P.Receive_P1_Size_o);
        ssSetSFcnParam(rts, 1, (mxArray*)gbyk_v4b_P.Receive_P2_Size_e);
        ssSetSFcnParam(rts, 2, (mxArray*)gbyk_v4b_P.Receive_P3_Size_ky);
        ssSetSFcnParam(rts, 3, (mxArray*)gbyk_v4b_P.Receive_P4_Size_f);
        ssSetSFcnParam(rts, 4, (mxArray*)gbyk_v4b_P.Receive_P5_Size_k);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &gbyk_v4b_DW.Receive_IWORK_n[0]);
      ssSetPWork(rts, (void **) &gbyk_v4b_DW.Receive_PWORK_o);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn34.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn34.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &gbyk_v4b_DW.Receive_IWORK_n[0]);

        /* PWORK */
        ssSetDWorkWidth(rts, 1, 1);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &gbyk_v4b_DW.Receive_PWORK_o);
      }

      /* registration */
      xpcudpbytereceive(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.00025);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 1, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);
      _ssSetOutputPortBeingMerged(rts, 1, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: gbyk_v4b/<S255>/BKIN EtherCAT PDO Transmit 1 (BKINethercatpdotx) */
    {
      SimStruct *rts = gbyk_v4b_M->childSfunctions[35];

      /* timing info */
      time_T *sfcnPeriod = gbyk_v4b_M->NonInlinedSFcns.Sfcn35.sfcnPeriod;
      time_T *sfcnOffset = gbyk_v4b_M->NonInlinedSFcns.Sfcn35.sfcnOffset;
      int_T *sfcnTsMap = gbyk_v4b_M->NonInlinedSFcns.Sfcn35.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &gbyk_v4b_M->NonInlinedSFcns.blkInfo2[35]);
      }

      ssSetRTWSfcnInfo(rts, gbyk_v4b_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &gbyk_v4b_M->NonInlinedSFcns.methods2[35]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &gbyk_v4b_M->NonInlinedSFcns.methods3[35]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &gbyk_v4b_M->NonInlinedSFcns.statesInfo2[35]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn35.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, &gbyk_v4b_B.ecatTorques[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "BKIN EtherCAT PDO Transmit 1");
      ssSetPath(rts,
                "gbyk_v4b/DataLogging/apply loads/EtherCAT Apply Loads/A1 Apply torques/BKIN EtherCAT PDO Transmit 1");
      ssSetRTModel(rts,gbyk_v4b_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn35.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit1_P1_Size_m);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit1_P2_Size_g);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit1_P3_Size_e);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit1_P4_Size_i);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit1_P5_Size_l);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit1_P6_Size_d);
        ssSetSFcnParam(rts, 6, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit1_P7_Size_a);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &gbyk_v4b_DW.BKINEtherCATPDOTransmit1_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn35.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn35.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 23);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &gbyk_v4b_DW.BKINEtherCATPDOTransmit1_IWORK[0]);
      }

      /* registration */
      BKINethercatpdotx(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.00025);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: gbyk_v4b/<S255>/BKIN EtherCAT PDO Transmit 2 (BKINethercatpdotx) */
    {
      SimStruct *rts = gbyk_v4b_M->childSfunctions[36];

      /* timing info */
      time_T *sfcnPeriod = gbyk_v4b_M->NonInlinedSFcns.Sfcn36.sfcnPeriod;
      time_T *sfcnOffset = gbyk_v4b_M->NonInlinedSFcns.Sfcn36.sfcnOffset;
      int_T *sfcnTsMap = gbyk_v4b_M->NonInlinedSFcns.Sfcn36.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &gbyk_v4b_M->NonInlinedSFcns.blkInfo2[36]);
      }

      ssSetRTWSfcnInfo(rts, gbyk_v4b_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &gbyk_v4b_M->NonInlinedSFcns.methods2[36]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &gbyk_v4b_M->NonInlinedSFcns.methods3[36]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &gbyk_v4b_M->NonInlinedSFcns.statesInfo2[36]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn36.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, &gbyk_v4b_B.ecatTorques[1]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "BKIN EtherCAT PDO Transmit 2");
      ssSetPath(rts,
                "gbyk_v4b/DataLogging/apply loads/EtherCAT Apply Loads/A1 Apply torques/BKIN EtherCAT PDO Transmit 2");
      ssSetRTModel(rts,gbyk_v4b_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn36.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit2_P1_Size_m);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit2_P2_Size_m);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit2_P3_Size_e);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit2_P4_Size_e);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit2_P5_Size_o);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit2_P6_Size_g);
        ssSetSFcnParam(rts, 6, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit2_P7_Size_j);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &gbyk_v4b_DW.BKINEtherCATPDOTransmit2_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn36.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn36.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 23);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &gbyk_v4b_DW.BKINEtherCATPDOTransmit2_IWORK[0]);
      }

      /* registration */
      BKINethercatpdotx(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.00025);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: gbyk_v4b/<S256>/BKIN EtherCAT PDO Transmit 1 (BKINethercatpdotx) */
    {
      SimStruct *rts = gbyk_v4b_M->childSfunctions[37];

      /* timing info */
      time_T *sfcnPeriod = gbyk_v4b_M->NonInlinedSFcns.Sfcn37.sfcnPeriod;
      time_T *sfcnOffset = gbyk_v4b_M->NonInlinedSFcns.Sfcn37.sfcnOffset;
      int_T *sfcnTsMap = gbyk_v4b_M->NonInlinedSFcns.Sfcn37.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &gbyk_v4b_M->NonInlinedSFcns.blkInfo2[37]);
      }

      ssSetRTWSfcnInfo(rts, gbyk_v4b_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &gbyk_v4b_M->NonInlinedSFcns.methods2[37]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &gbyk_v4b_M->NonInlinedSFcns.methods3[37]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &gbyk_v4b_M->NonInlinedSFcns.statesInfo2[37]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn37.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, &gbyk_v4b_B.ecatTorques[2]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "BKIN EtherCAT PDO Transmit 1");
      ssSetPath(rts,
                "gbyk_v4b/DataLogging/apply loads/EtherCAT Apply Loads/A2 Apply torques/BKIN EtherCAT PDO Transmit 1");
      ssSetRTModel(rts,gbyk_v4b_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn37.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit1_P1_Size_d);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit1_P2_Size_o);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit1_P3_Size_f);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit1_P4_Size_d);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit1_P5_Size_io);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit1_P6_Size_ht);
        ssSetSFcnParam(rts, 6, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit1_P7_Size_d);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &gbyk_v4b_DW.BKINEtherCATPDOTransmit1_IWORK_c[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn37.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn37.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 23);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &gbyk_v4b_DW.BKINEtherCATPDOTransmit1_IWORK_c[0]);
      }

      /* registration */
      BKINethercatpdotx(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.00025);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: gbyk_v4b/<S256>/BKIN EtherCAT PDO Transmit 2 (BKINethercatpdotx) */
    {
      SimStruct *rts = gbyk_v4b_M->childSfunctions[38];

      /* timing info */
      time_T *sfcnPeriod = gbyk_v4b_M->NonInlinedSFcns.Sfcn38.sfcnPeriod;
      time_T *sfcnOffset = gbyk_v4b_M->NonInlinedSFcns.Sfcn38.sfcnOffset;
      int_T *sfcnTsMap = gbyk_v4b_M->NonInlinedSFcns.Sfcn38.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &gbyk_v4b_M->NonInlinedSFcns.blkInfo2[38]);
      }

      ssSetRTWSfcnInfo(rts, gbyk_v4b_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &gbyk_v4b_M->NonInlinedSFcns.methods2[38]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &gbyk_v4b_M->NonInlinedSFcns.methods3[38]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &gbyk_v4b_M->NonInlinedSFcns.statesInfo2[38]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn38.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, &gbyk_v4b_B.ecatTorques[3]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "BKIN EtherCAT PDO Transmit 2");
      ssSetPath(rts,
                "gbyk_v4b/DataLogging/apply loads/EtherCAT Apply Loads/A2 Apply torques/BKIN EtherCAT PDO Transmit 2");
      ssSetRTModel(rts,gbyk_v4b_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn38.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit2_P1_Size_f);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit2_P2_Size_j);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit2_P3_Size_p);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit2_P4_Size_p);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit2_P5_Size_h);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit2_P6_Size_a);
        ssSetSFcnParam(rts, 6, (mxArray*)
                       gbyk_v4b_P.BKINEtherCATPDOTransmit2_P7_Size_o);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &gbyk_v4b_DW.BKINEtherCATPDOTransmit2_IWORK_g[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn38.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn38.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 23);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &gbyk_v4b_DW.BKINEtherCATPDOTransmit2_IWORK_g[0]);
      }

      /* registration */
      BKINethercatpdotx(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.00025);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: gbyk_v4b/<S252>/S-Function1 (mcc_apply_loads) */
    {
      SimStruct *rts = gbyk_v4b_M->childSfunctions[39];

      /* timing info */
      time_T *sfcnPeriod = gbyk_v4b_M->NonInlinedSFcns.Sfcn39.sfcnPeriod;
      time_T *sfcnOffset = gbyk_v4b_M->NonInlinedSFcns.Sfcn39.sfcnOffset;
      int_T *sfcnTsMap = gbyk_v4b_M->NonInlinedSFcns.Sfcn39.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &gbyk_v4b_M->NonInlinedSFcns.blkInfo2[39]);
      }

      ssSetRTWSfcnInfo(rts, gbyk_v4b_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &gbyk_v4b_M->NonInlinedSFcns.methods2[39]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &gbyk_v4b_M->NonInlinedSFcns.methods3[39]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &gbyk_v4b_M->NonInlinedSFcns.statesInfo2[39]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 3);
        ssSetPortInfoForInputs(rts,
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn39.inputPortInfo[0]);

        /* port 0 */
        {
          real32_T const **sfcnUPtrs = (real32_T const **)
            &gbyk_v4b_M->NonInlinedSFcns.Sfcn39.UPtrs0;
          sfcnUPtrs[0] = gbyk_v4b_B.DataTypeConversion6;
          sfcnUPtrs[1] = &gbyk_v4b_B.DataTypeConversion6[1];
          sfcnUPtrs[2] = &gbyk_v4b_B.DataTypeConversion6[2];
          sfcnUPtrs[3] = &gbyk_v4b_B.DataTypeConversion6[3];
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 4);
        }

        /* port 1 */
        {
          real32_T const **sfcnUPtrs = (real32_T const **)
            &gbyk_v4b_M->NonInlinedSFcns.Sfcn39.UPtrs1;

          {
            int_T i1;
            const real32_T *u1 = gbyk_v4b_B.DataTypeConversion_a;
            for (i1=0; i1 < 6; i1++) {
              sfcnUPtrs[i1] = &u1[i1];
            }
          }

          ssSetInputPortSignalPtrs(rts, 1, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 6);
        }

        /* port 2 */
        {
          real32_T const **sfcnUPtrs = (real32_T const **)
            &gbyk_v4b_M->NonInlinedSFcns.Sfcn39.UPtrs2;

          {
            int_T i1;
            const real32_T *u2 = gbyk_v4b_B.DataTypeConversion1_cq;
            for (i1=0; i1 < 6; i1++) {
              sfcnUPtrs[i1] = &u2[i1];
            }
          }

          ssSetInputPortSignalPtrs(rts, 2, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 2, 1);
          ssSetInputPortWidth(rts, 2, 6);
        }
      }

      /* path info */
      ssSetModelName(rts, "S-Function1");
      ssSetPath(rts,
                "gbyk_v4b/DataLogging/apply loads/apply pmac loads/S-Function1");
      ssSetRTModel(rts,gbyk_v4b_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* work vectors */
      ssSetPWork(rts, (void **) &gbyk_v4b_DW.SFunction1_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn39.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn39.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &gbyk_v4b_DW.SFunction1_PWORK);
      }

      /* registration */
      mcc_apply_loads(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.00025);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetInputPortConnected(rts, 1, 1);
      _ssSetInputPortConnected(rts, 2, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
      ssSetInputPortBufferDstPort(rts, 2, -1);
    }

    /* Level2 S-Function Block: gbyk_v4b/<S7>/ICH7 (ich10) */
    {
      SimStruct *rts = gbyk_v4b_M->childSfunctions[40];

      /* timing info */
      time_T *sfcnPeriod = gbyk_v4b_M->NonInlinedSFcns.Sfcn40.sfcnPeriod;
      time_T *sfcnOffset = gbyk_v4b_M->NonInlinedSFcns.Sfcn40.sfcnOffset;
      int_T *sfcnTsMap = gbyk_v4b_M->NonInlinedSFcns.Sfcn40.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &gbyk_v4b_M->NonInlinedSFcns.blkInfo2[40]);
      }

      ssSetRTWSfcnInfo(rts, gbyk_v4b_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &gbyk_v4b_M->NonInlinedSFcns.methods2[40]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &gbyk_v4b_M->NonInlinedSFcns.methods3[40]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &gbyk_v4b_M->NonInlinedSFcns.statesInfo2[40]);
      }

      /* path info */
      ssSetModelName(rts, "ICH7");
      ssSetPath(rts, "gbyk_v4b/GUI Control/ICH7");
      ssSetRTModel(rts,gbyk_v4b_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* work vectors */
      ssSetIWork(rts, (int_T *) &gbyk_v4b_DW.ICH7_IWORK[0]);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn40.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn40.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 5);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &gbyk_v4b_DW.ICH7_IWORK[0]);
      }

      /* registration */
      ich10(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.0);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 0;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: gbyk_v4b/<S268>/Run Command Receive (xpcudpbytereceive) */
    {
      SimStruct *rts = gbyk_v4b_M->childSfunctions[41];

      /* timing info */
      time_T *sfcnPeriod = gbyk_v4b_M->NonInlinedSFcns.Sfcn41.sfcnPeriod;
      time_T *sfcnOffset = gbyk_v4b_M->NonInlinedSFcns.Sfcn41.sfcnOffset;
      int_T *sfcnTsMap = gbyk_v4b_M->NonInlinedSFcns.Sfcn41.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &gbyk_v4b_M->NonInlinedSFcns.blkInfo2[41]);
      }

      ssSetRTWSfcnInfo(rts, gbyk_v4b_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &gbyk_v4b_M->NonInlinedSFcns.methods2[41]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &gbyk_v4b_M->NonInlinedSFcns.methods3[41]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &gbyk_v4b_M->NonInlinedSFcns.statesInfo2[41]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn41.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 2);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((uint8_T *)
            &gbyk_v4b_B.RunCommandReceive_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((real_T *)
            &gbyk_v4b_B.RunCommandReceive_o2));
        }
      }

      /* path info */
      ssSetModelName(rts, "Run Command Receive");
      ssSetPath(rts,
                "gbyk_v4b/GUI Control/Run Command Subsystem/Run Command Receive");
      ssSetRTModel(rts,gbyk_v4b_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn41.params;
        ssSetSFcnParamsCount(rts, 5);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)gbyk_v4b_P.RunCommandReceive_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)gbyk_v4b_P.RunCommandReceive_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)gbyk_v4b_P.RunCommandReceive_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)gbyk_v4b_P.RunCommandReceive_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)gbyk_v4b_P.RunCommandReceive_P5_Size);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &gbyk_v4b_DW.RunCommandReceive_IWORK[0]);
      ssSetPWork(rts, (void **) &gbyk_v4b_DW.RunCommandReceive_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn41.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn41.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &gbyk_v4b_DW.RunCommandReceive_IWORK[0]);

        /* PWORK */
        ssSetDWorkWidth(rts, 1, 1);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &gbyk_v4b_DW.RunCommandReceive_PWORK);
      }

      /* registration */
      xpcudpbytereceive(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.00025);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 1, 0);
      _ssSetOutputPortBeingMerged(rts, 0, 0);
      _ssSetOutputPortBeingMerged(rts, 1, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: gbyk_v4b/<S15>/Receive (xpcudpbytereceive) */
    {
      SimStruct *rts = gbyk_v4b_M->childSfunctions[42];

      /* timing info */
      time_T *sfcnPeriod = gbyk_v4b_M->NonInlinedSFcns.Sfcn42.sfcnPeriod;
      time_T *sfcnOffset = gbyk_v4b_M->NonInlinedSFcns.Sfcn42.sfcnOffset;
      int_T *sfcnTsMap = gbyk_v4b_M->NonInlinedSFcns.Sfcn42.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &gbyk_v4b_M->NonInlinedSFcns.blkInfo2[42]);
      }

      ssSetRTWSfcnInfo(rts, gbyk_v4b_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &gbyk_v4b_M->NonInlinedSFcns.methods2[42]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &gbyk_v4b_M->NonInlinedSFcns.methods3[42]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &gbyk_v4b_M->NonInlinedSFcns.statesInfo2[42]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn42.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 2);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 4);
          ssSetOutputPortSignal(rts, 0, ((uint8_T *) gbyk_v4b_B.Receive_o1));
        }

        /* port 1 */
        {
          _ssSetOutputPortNumDimensions(rts, 1, 1);
          ssSetOutputPortWidth(rts, 1, 1);
          ssSetOutputPortSignal(rts, 1, ((real_T *) &gbyk_v4b_B.Receive_o2));
        }
      }

      /* path info */
      ssSetModelName(rts, "Receive");
      ssSetPath(rts, "gbyk_v4b/Process_Video_CMD/Receive");
      ssSetRTModel(rts,gbyk_v4b_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn42.params;
        ssSetSFcnParamsCount(rts, 5);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)gbyk_v4b_P.Receive_P1_Size_g);
        ssSetSFcnParam(rts, 1, (mxArray*)gbyk_v4b_P.Receive_P2_Size_m);
        ssSetSFcnParam(rts, 2, (mxArray*)gbyk_v4b_P.Receive_P3_Size_f);
        ssSetSFcnParam(rts, 3, (mxArray*)gbyk_v4b_P.Receive_P4_Size_d);
        ssSetSFcnParam(rts, 4, (mxArray*)gbyk_v4b_P.Receive_P5_Size_h);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &gbyk_v4b_DW.Receive_IWORK[0]);
      ssSetPWork(rts, (void **) &gbyk_v4b_DW.Receive_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn42.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn42.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &gbyk_v4b_DW.Receive_IWORK[0]);

        /* PWORK */
        ssSetDWorkWidth(rts, 1, 1);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &gbyk_v4b_DW.Receive_PWORK);
      }

      /* registration */
      xpcudpbytereceive(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.00025);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortConnected(rts, 1, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);
      _ssSetOutputPortBeingMerged(rts, 1, 0);

      /* Update the BufferDstPort flags for each input port */
    }

    /* Level2 S-Function Block: gbyk_v4b/<S15>/Send (xpcudpbytesend) */
    {
      SimStruct *rts = gbyk_v4b_M->childSfunctions[43];

      /* timing info */
      time_T *sfcnPeriod = gbyk_v4b_M->NonInlinedSFcns.Sfcn43.sfcnPeriod;
      time_T *sfcnOffset = gbyk_v4b_M->NonInlinedSFcns.Sfcn43.sfcnOffset;
      int_T *sfcnTsMap = gbyk_v4b_M->NonInlinedSFcns.Sfcn43.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      /* Set up the mdlInfo pointer */
      {
        ssSetBlkInfo2Ptr(rts, &gbyk_v4b_M->NonInlinedSFcns.blkInfo2[43]);
      }

      ssSetRTWSfcnInfo(rts, gbyk_v4b_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &gbyk_v4b_M->NonInlinedSFcns.methods2[43]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &gbyk_v4b_M->NonInlinedSFcns.methods3[43]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &gbyk_v4b_M->NonInlinedSFcns.statesInfo2[43]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn43.inputPortInfo[0]);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, gbyk_v4b_B.SFunctionBuilder_o1);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 27240);
        }

        /* port 1 */
        {
          ssSetInputPortRequiredContiguous(rts, 1, 1);
          ssSetInputPortSignal(rts, 1, &gbyk_v4b_B.SFunctionBuilder_o2);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "Send");
      ssSetPath(rts, "gbyk_v4b/Process_Video_CMD/Send");
      ssSetRTModel(rts,gbyk_v4b_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn43.params;
        ssSetSFcnParamsCount(rts, 5);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)gbyk_v4b_P.Send_P1_Size_k);
        ssSetSFcnParam(rts, 1, (mxArray*)gbyk_v4b_P.Send_P2_Size_mp);
        ssSetSFcnParam(rts, 2, (mxArray*)gbyk_v4b_P.Send_P3_Size_dr);
        ssSetSFcnParam(rts, 3, (mxArray*)gbyk_v4b_P.Send_P4_Size_o);
        ssSetSFcnParam(rts, 4, (mxArray*)gbyk_v4b_P.Send_P5_Size_n);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &gbyk_v4b_DW.Send_IWORK[0]);
      ssSetPWork(rts, (void **) &gbyk_v4b_DW.Send_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn43.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &gbyk_v4b_M->NonInlinedSFcns.Sfcn43.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 2);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &gbyk_v4b_DW.Send_IWORK[0]);

        /* PWORK */
        ssSetDWorkWidth(rts, 1, 1);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &gbyk_v4b_DW.Send_PWORK);
      }

      /* registration */
      xpcudpbytesend(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.002);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 4;

      /* set compiled values of dynamic vector attributes */
      ssSetInputPortWidth(rts, 0, 27240);
      ssSetInputPortDataType(rts, 0, SS_UINT8);
      ssSetInputPortComplexSignal(rts, 0, 0);
      ssSetInputPortFrameData(rts, 0, 0);
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetInputPortConnected(rts, 1, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
    }
  }

  /* Initialize Sizes */
  gbyk_v4b_M->Sizes.numContStates = (0);/* Number of continuous states */
  gbyk_v4b_M->Sizes.numY = (0);        /* Number of model outputs */
  gbyk_v4b_M->Sizes.numU = (0);        /* Number of model inputs */
  gbyk_v4b_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  gbyk_v4b_M->Sizes.numSampTimes = (6);/* Number of sample times */
  gbyk_v4b_M->Sizes.numBlocks = (1432);/* Number of blocks */
  gbyk_v4b_M->Sizes.numBlockIO = (1283);/* Number of block outputs */
  gbyk_v4b_M->Sizes.numBlockPrms = (39592);/* Sum of parameter "widths" */
  return gbyk_v4b_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
