/*
 * gbyk_v4b_private.h
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

#ifndef RTW_HEADER_gbyk_v4b_private_h_
#define RTW_HEADER_gbyk_v4b_private_h_
#include <stdio.h>
#include <stdlib.h>
#include <crc32.h>
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"
#define col_x                          (1.0)
#define col_y                          (2.0)
#define INIT_COLOR                     (5.0)
#define DELAY_POST_TRIAL               (8.0)
#define HIT_COLOR                      (6.0)
#define E_NO_EVENT                     (0.0)
#define START_TARGET_COL               (1.0)
#define MAX_REACH_TIME_COL             (7.0)
#define K_DELAY_FIXED                  (3.0)
#define K_DELAY_RAND                   (4.0)
#define K_TRIGGER_VEL                  (5.0)
#define K_TRIGGER_POS                  (6.0)
#define K_THRESH_VELMAX                (7.0)
#define E_NEW_TRIAL                    (1.0)
#define E_STAY_START                   (2.0)
#define K_REWARD_VAL                   (1.0)
#define VISUAL_RADIUS                  (3.0)
#define LOGICAL_RADIUS                 (4.0)
#define STROKE_WIDTH                   (7.0)
#define TEXT_COLOR                     (8.0)
#define LABEL_HEIGHT                   (10.0)
#define E_TOO_SLOW                     (20.0)
#define K_SCORETEXT_ROW                (2.0)
#define LABEL                          (9.0)
#define E_TARGETS_ON                   (3.0)
#define DISPLAY_TRIAL_COL              (9.0)
#define E_SHOW_INSTRUCT                (13.0)
#define E_SHOW_SCORE                   (14.0)
#define INSTRUCT_PAUSE_BTN             (2.0)
#define LABELONLY_X                    (11.0)
#define LABELONLY_Y                    (12.0)
#define K_PRE_REWARD_DELAY             (8.0)
#define CORR_TGT                       (2.0)
#define INCORR_TGT                     (3.0)
#define TGT_C_RWD_FRAC                 (6.0)
#define BOX_HEIGHT                     (13.0)
#define B1                             (10.0)
#define B2                             (11.0)
#define RWD_TARGETC1_COL               (4.0)
#define RWD_TARGETC2_COL               (5.0)
#define E_BOX_TRIGGER                  (22.0)
#define E_CHOSE_ROW_B                  (21.0)
#define E_HIT_TARGETB                  (23.0)
#define E_MISS_TARGETB                 (24.0)
#define E_HIT_TARGETC                  (25.0)
#define E_MISS_TARGETC                 (26.0)
#define ROTATION                       (14.0)
#define col_x                          (1.0)
#define col_y                          (2.0)

/* Used to reverse endianness */
#define SWAP16(x)                      (((x) >> 8) | (((x) & 0xff) << 8))
#define SWAP32(x)                      (SWAP16((x) >> 16) | (SWAP16((x) & 0xffff) << 16))

extern void delay_vcodes_Outputs_wrapper(const int32_T *VCode,
  const real_T *VCode_len,
  const real_T *delay_ms,
  const real_T *step_time_ms,
  uint8_T *VCode_out,
  real_T *VCode_len_out,
  real_T *debug_out);
extern const serialfifoptr serialfifoground;
extern const bcmsglist1553 bcmsg1553ground;
extern const bcstatus1553 bcstatground;
extern const bmmsglist1553 bmmsg1553ground;
extern real_T rt_roundd_snf(real_T u);
extern real_T rt_modd_snf(real_T u0, real_T u1);
extern real_T rt_powd_snf(real_T u0, real_T u1);
extern real_T rt_atan2d_snf(real_T u0, real_T u1);
extern real_T rt_remd_snf(real_T u0, real_T u1);
extern const char *getRefMdlPath(const char *refMdl);
extern int getRefMdlSignalNumber(const char *mdlBlock, const char *signalName);
extern int32_T div_s32_floor(int32_T numerator, int32_T denominator);
extern void xpcudpbytesend(SimStruct *rts);
extern void BKINUDPReceiveRead(SimStruct *rts);
extern void BKINUDPReceiveInit(SimStruct *rts);
extern void xpcudpbytereceive(SimStruct *rts);
extern void BKINethercatpdorxElmoDrive(SimStruct *rts);
extern void BKINethercatpdotx(SimStruct *rts);
extern void mcc_readmem(SimStruct *rts);
extern void mcc_writemem(SimStruct *rts);
extern void mcc_pollall(SimStruct *rts);
extern void eyelink_unpack(SimStruct *rts);
extern void mcc_apply_loads(SimStruct *rts);
extern void ich10(SimStruct *rts);
extern void gbyk_v4b_MATLABFunction(real_T rtu_orientation, real_T
  rtu_has_secondary, real_T rtu_isEP, B_MATLABFunction_gbyk_v4b_T *localB);
extern void gbyk_v4b_EmbeddedMATLABFunction(const real_T rtu_target[25], real_T
  rtu_state_in, real_T rtu_target_type, real_T rtu_opacity_in, real_T
  rtu_target_display, real_T rtu_x_index, real_T rtu_y_index, real_T
  rtu_num_states, const real_T rtu_stateindices[55],
  B_EmbeddedMATLABFunction_gbyk_v4b_T *localB);
extern void gbyk_v4b_EmbeddedMATLABWhichHand(real_T rtu_use_dominant_hand,
  real_T rtu_dominant_hand, B_EmbeddedMATLABWhichHand_gbyk_v4b_T *localB);
extern void gbyk_v4b_EmbeddedMATLABFunction_k(const real_T rtu_target[50], const
  real_T rtu_state_in[2], real_T rtu_target_type, real_T rtu_opacity_in, real_T
  rtu_target_display, real_T rtu_x_index, real_T rtu_y_index, real_T
  rtu_num_states, const real_T rtu_stateindices[55], const real_T
  rtu_target_labels[5000], B_EmbeddedMATLABFunction_gbyk_v4b_p_T *localB);

#endif                                 /* RTW_HEADER_gbyk_v4b_private_h_ */
