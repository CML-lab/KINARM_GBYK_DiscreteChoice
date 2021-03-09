/*
 * gbyk_v4b_types.h
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

#ifndef RTW_HEADER_gbyk_v4b_types_h_
#define RTW_HEADER_gbyk_v4b_types_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "zero_crossing_types.h"

/* Custom Type definition for MATLAB Function: '<S129>/converter' */
#include <stddef.h>

/* Custom Type definition for MATLAB Function: '<S210>/Robot_data_builder' */
#ifndef struct_sbr0BdzAW6GQX2fQakj4o6C
#define struct_sbr0BdzAW6GQX2fQakj4o6C

struct sbr0BdzAW6GQX2fQakj4o6C
{
  real_T shoPos[5];
  real_T elbPos[5];
  real_T shoVel[5];
  real_T elbVel[5];
  real_T shoAcc;
  real_T elbAcc;
  real_T bHasSecondary;
};

#endif                                 /*struct_sbr0BdzAW6GQX2fQakj4o6C*/

#ifndef typedef_sbr0BdzAW6GQX2fQakj4o6C_gbyk_v4b_T
#define typedef_sbr0BdzAW6GQX2fQakj4o6C_gbyk_v4b_T

typedef struct sbr0BdzAW6GQX2fQakj4o6C sbr0BdzAW6GQX2fQakj4o6C_gbyk_v4b_T;

#endif                                 /*typedef_sbr0BdzAW6GQX2fQakj4o6C_gbyk_v4b_T*/

/* Custom Type definition for MATLAB Function: '<S210>/filter_velocities' */
#ifndef struct_shSrZ99dE4twa6ELJRaXlMD
#define struct_shSrZ99dE4twa6ELJRaXlMD

struct shSrZ99dE4twa6ELJRaXlMD
{
  real_T shoVel[3];
  real_T elbVel[3];
  real_T shoVelFilt[3];
  real_T elbVelFilt[3];
  real_T servoCounter[3];
};

#endif                                 /*struct_shSrZ99dE4twa6ELJRaXlMD*/

#ifndef typedef_shSrZ99dE4twa6ELJRaXlMD_gbyk_v4b_T
#define typedef_shSrZ99dE4twa6ELJRaXlMD_gbyk_v4b_T

typedef struct shSrZ99dE4twa6ELJRaXlMD shSrZ99dE4twa6ELJRaXlMD_gbyk_v4b_T;

#endif                                 /*typedef_shSrZ99dE4twa6ELJRaXlMD_gbyk_v4b_T*/

/* Parameters (auto storage) */
typedef struct P_gbyk_v4b_T_ P_gbyk_v4b_T;

/* Forward declaration for rtModel */
typedef struct tag_RTM_gbyk_v4b_T RT_MODEL_gbyk_v4b_T;

#endif                                 /* RTW_HEADER_gbyk_v4b_types_h_ */
