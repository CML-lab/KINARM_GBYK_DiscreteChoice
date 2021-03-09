/*
 * Code generation for system system '<S10>/Embedded MATLAB InsideTarget'
 *
 * Model                      : gbyk_v4b
 * Model version              : 1.2667
 * Simulink Coder version : 8.8.1 (R2015aSP1) 04-Sep-2015
 * C source code generated on : Tue Sep 15 15:02:19 2020
 *
 * Note that the functions contained in this file are part of a Simulink
 * model, and are not self-contained algorithms.
 */

#include "gbyk_v4b_EmbeddedMATLABInsideTarget.h"

/* Include model header file for global data */
#include "gbyk_v4b.h"
#include "gbyk_v4b_private.h"

/* Forward declaration for local functions */
static void gbyk_v4b_sin(real_T x[32]);
static void gbyk_v4b_cos(real_T x[32]);
static void gbyk_v4b_rdivide_p(real_T x, const real_T y[32], real_T z[32]);
static void gbyk_v4b_power(const real_T a[32], real_T y[32]);
static void gbyk_v4b_sqrt(real_T x[32]);
static void gbyk_v4b_atan2(const real_T y[32], const real_T x[32], real_T r[32]);
static void gbyk_v4b_abs(const real_T x[32], real_T y[32]);
static void gbyk_v4b_rdivide(const real_T x[32], const real_T y[32], real_T z[32]);

/* Function for MATLAB Function: '<S10>/Embedded MATLAB InsideTarget' */
static void gbyk_v4b_sin(real_T x[32])
{
  int32_T k;
  for (k = 0; k < 32; k++) {
    x[k] = sin(x[k]);
  }
}

/* Function for MATLAB Function: '<S10>/Embedded MATLAB InsideTarget' */
static void gbyk_v4b_cos(real_T x[32])
{
  int32_T k;
  for (k = 0; k < 32; k++) {
    x[k] = cos(x[k]);
  }
}

/* Function for MATLAB Function: '<S10>/Embedded MATLAB InsideTarget' */
static void gbyk_v4b_rdivide_p(real_T x, const real_T y[32], real_T z[32])
{
  int32_T i;
  for (i = 0; i < 32; i++) {
    z[i] = x / y[i];
  }
}

/* Function for MATLAB Function: '<S10>/Embedded MATLAB InsideTarget' */
static void gbyk_v4b_power(const real_T a[32], real_T y[32])
{
  int32_T k;
  for (k = 0; k < 32; k++) {
    y[k] = a[k] * a[k];
  }
}

/* Function for MATLAB Function: '<S10>/Embedded MATLAB InsideTarget' */
static void gbyk_v4b_sqrt(real_T x[32])
{
  int32_T k;
  for (k = 0; k < 32; k++) {
    x[k] = sqrt(x[k]);
  }
}

real_T rt_atan2d_snf(real_T u0, real_T u1)
{
  real_T y;
  int32_T tmp;
  int32_T tmp_0;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = (rtNaN);
  } else if (rtIsInf(u0) && rtIsInf(u1)) {
    if (u1 > 0.0) {
      tmp = 1;
    } else {
      tmp = -1;
    }

    if (u0 > 0.0) {
      tmp_0 = 1;
    } else {
      tmp_0 = -1;
    }

    y = atan2(tmp_0, tmp);
  } else if (u1 == 0.0) {
    if (u0 > 0.0) {
      y = RT_PI / 2.0;
    } else if (u0 < 0.0) {
      y = -(RT_PI / 2.0);
    } else {
      y = 0.0;
    }
  } else {
    y = atan2(u0, u1);
  }

  return y;
}

/* Function for MATLAB Function: '<S10>/Embedded MATLAB InsideTarget' */
static void gbyk_v4b_atan2(const real_T y[32], const real_T x[32], real_T r[32])
{
  int32_T k;
  for (k = 0; k < 32; k++) {
    r[k] = rt_atan2d_snf(y[k], x[k]);
  }
}

/* Function for MATLAB Function: '<S10>/Embedded MATLAB InsideTarget' */
static void gbyk_v4b_abs(const real_T x[32], real_T y[32])
{
  int32_T k;
  for (k = 0; k < 32; k++) {
    y[k] = fabs(x[k]);
  }
}

/* Function for MATLAB Function: '<S10>/Embedded MATLAB InsideTarget' */
static void gbyk_v4b_rdivide(const real_T x[32], const real_T y[32], real_T z[32])
{
  int32_T i;
  for (i = 0; i < 32; i++) {
    z[i] = x[i] / y[i];
  }
}

/* Output and update for atomic system: '<S10>/Embedded MATLAB InsideTarget' */
void gbyk_v4b_EmbeddedMATLABInsideTarget(void)
{
  real_T deltax[32];
  real_T deltay[32];
  real_T t[32];
  real_T sint[32];
  real_T w[32];
  real_T h[32];
  real_T p[32];
  real_T A[64];
  real_T v0[64];
  real_T v1[64];
  real_T v2[64];
  real_T dot02[32];
  real_T dot11[32];
  int32_T e_target;
  int32_T f;
  boolean_T g[32];
  real_T i[32];
  int32_T i_0;
  real_T sint_0[32];
  int32_T i_1;
  int32_T i_2;
  real_T w_0[64];
  real_T p_0;
  real_T sint_1;
  real_T dot11_0;

  /* SignalConversion: '<S281>/TmpSignal ConversionAt SFunction Inport3' incorporates:
   *  Constant: '<S10>/attribcol1'
   *  Constant: '<S10>/attribcol2'
   *  Constant: '<S10>/attribcol3'
   *  Constant: '<S10>/attribcol4'
   *  Constant: '<S10>/attribcol5'
   */
  gbyk_v4b_B.TmpSignalConversionAtSFunctionInport3_d[0] =
    gbyk_v4b_P.KINARM_HandInBox_attribcol1[0];
  gbyk_v4b_B.TmpSignalConversionAtSFunctionInport3_d[1] =
    gbyk_v4b_P.KINARM_HandInBox_attribcol1[1];
  gbyk_v4b_B.TmpSignalConversionAtSFunctionInport3_d[2] =
    gbyk_v4b_P.KINARM_HandInBox_attribcol1[2];
  gbyk_v4b_B.TmpSignalConversionAtSFunctionInport3_d[3] =
    gbyk_v4b_P.attribcol2_Value_k[0];
  gbyk_v4b_B.TmpSignalConversionAtSFunctionInport3_d[4] =
    gbyk_v4b_P.attribcol2_Value_k[1];
  gbyk_v4b_B.TmpSignalConversionAtSFunctionInport3_d[5] =
    gbyk_v4b_P.attribcol2_Value_k[2];
  gbyk_v4b_B.TmpSignalConversionAtSFunctionInport3_d[6] =
    gbyk_v4b_P.attribcol3_Value_e[0];
  gbyk_v4b_B.TmpSignalConversionAtSFunctionInport3_d[7] =
    gbyk_v4b_P.attribcol3_Value_e[1];
  gbyk_v4b_B.TmpSignalConversionAtSFunctionInport3_d[8] =
    gbyk_v4b_P.attribcol3_Value_e[2];
  gbyk_v4b_B.TmpSignalConversionAtSFunctionInport3_d[9] =
    gbyk_v4b_P.attribcol4_Value_l[0];
  gbyk_v4b_B.TmpSignalConversionAtSFunctionInport3_d[10] =
    gbyk_v4b_P.attribcol4_Value_l[1];
  gbyk_v4b_B.TmpSignalConversionAtSFunctionInport3_d[11] =
    gbyk_v4b_P.attribcol4_Value_l[2];
  gbyk_v4b_B.TmpSignalConversionAtSFunctionInport3_d[12] =
    gbyk_v4b_P.attribcol5_Value_j[0];
  gbyk_v4b_B.TmpSignalConversionAtSFunctionInport3_d[13] =
    gbyk_v4b_P.attribcol5_Value_j[1];
  gbyk_v4b_B.TmpSignalConversionAtSFunctionInport3_d[14] =
    gbyk_v4b_P.attribcol5_Value_j[2];

  /* MATLAB Function 'KINARM_HandInTarget/Embedded MATLAB InsideTarget': '<S281>:1' */
  /*  all dimensions in m, rad */
  /*  arguments: */
  /*  handpos: x,y positions of center of target */
  /*  attribcol: columns in target table specifying target attributes.   */
  /*  Specific to Target_Type */
  /* 	circle: */
  /* 	[X0,Y0,r...,rn] where: */
  /* 	X0,Y0 : centre of circle */
  /* 	r : logical radius of circle (i.e. radius used to determine 'in' or 'out' of target) */
  /* 	rn: logical radius of other targets (e.g. 2nd, 3rd) also specified in target row. */
  /*    Up to 4 targets can be specified in a row */
  /*  ellipse: */
  /* 	[X0,Y0,a,b,t...,an, bn, tn] where: */
  /* 	X0,Y0 : centre of ellipse */
  /* 	a,b : major, minor radii of ellipse */
  /* 	t : rotation of ellipse in degrees */
  /* 	an,bn : major, minor radii of ellipse of other targets (e.g. 2nd, 3rd) also specified in target row */
  /* 	tn : rotation of ellipse in degrees of other targets (e.g. 2nd, 3rd) also specified in target row */
  /*    Up to 4 targets can be specified in a row */
  /* '<S281>:1:26' */
  /* '<S281>:1:27' */
  /* '<S281>:1:29' */
  for (i_0 = 0; i_0 < 160; i_0++) {
    gbyk_v4b_B.intarget_l[i_0] = 0.0;
  }

  /* '<S281>:1:31' */
  /* Target Table sizes in cm in v1.4 */
  /* '<S281>:1:32' */
  /* Target Table sizes in cm in v1.4 */
  /* '<S281>:1:34' */
  dot11_0 = gbyk_v4b_B.MultiportSwitch_b[0];

  /* '<S281>:1:35' */
  sint_1 = gbyk_v4b_B.MultiportSwitch_b[1];
  for (i_0 = 0; i_0 < 32; i_0++) {
    deltax[i_0] = dot11_0 - gbyk_v4b_B.TargetTable[i_0] * 0.01;
    deltay[i_0] = sint_1 - gbyk_v4b_B.TargetTable[32 + i_0] * 0.01;
  }

  /* Constant: '<S10>/Target_Type' */
  if (gbyk_v4b_P.KINARM_HandInBox_target_type == 1.0) {
    /* Constant: '<S10>/num_states' */
    /* '<S281>:1:37' */
    /* circle */
    /* '<S281>:1:38' */
    f = (int32_T)gbyk_v4b_P.KINARM_HandInBox_num_states;

    /* '<S281>:1:38' */
    for (e_target = 0; e_target < f; e_target++) {
      /* '<S281>:1:38' */
      /* '<S281>:1:39' */
      /* Target Table sizes in cm in v1.4 */
      /*  simple euclidean distance */
      /* '<S281>:1:41' */
      gbyk_v4b_power(deltax, p);
      gbyk_v4b_power(deltay, i);

      /* distance2 is the square of the distance */
      /* '<S281>:1:42' */
      i_0 = (int32_T)gbyk_v4b_B.TmpSignalConversionAtSFunctionInport3_d[e_target];
      for (i_1 = 0; i_1 < 32; i_1++) {
        p_0 = p[i_1];
        p_0 += i[i_1];
        w[i_1] = gbyk_v4b_B.TargetTable[((i_0 - 1) << 5) + i_1] * 0.01;
        p[i_1] = p_0;
      }

      gbyk_v4b_power(w, i);
      for (i_0 = 0; i_0 < 32; i_0++) {
        gbyk_v4b_B.intarget_l[i_0 + (e_target << 5)] = (p[i_0] <= i[i_0]);
      }

      /* '<S281>:1:38' */
    }
  } else if (gbyk_v4b_P.KINARM_HandInBox_target_type == 2.0) {
    /* Constant: '<S10>/num_states' */
    /* '<S281>:1:44' */
    /* ellipse */
    /* '<S281>:1:45' */
    f = (int32_T)gbyk_v4b_P.KINARM_HandInBox_num_states;

    /* '<S281>:1:45' */
    for (e_target = 0; e_target < f; e_target++) {
      /* '<S281>:1:45' */
      /* '<S281>:1:46' */
      /* Target Table sizes in cm in v1.4 */
      /* '<S281>:1:47' */
      /* Target Table sizes in cm in v1.4	 */
      /* '<S281>:1:48' */
      i_0 = (int32_T)gbyk_v4b_B.TmpSignalConversionAtSFunctionInport3_d[(int32_T)
        ((1.0 + (real_T)e_target) * 3.0) - 1];

      /* Target Table angles in degrees in v1.4 */
      /* '<S281>:1:49' */
      for (i_1 = 0; i_1 < 32; i_1++) {
        dot11_0 = gbyk_v4b_B.TargetTable[((i_0 - 1) << 5) + i_1] *
          0.017453292519943295;
        sint[i_1] = dot11_0;
        t[i_1] = dot11_0;
      }

      gbyk_v4b_sin(sint);

      /* '<S281>:1:50' */
      gbyk_v4b_cos(t);

      /* '<S281>:1:51' */
      /* location of x point in ellipse's coordinate frame */
      /* '<S281>:1:52' */
      /* location of y point in ellipse's coordinate frame */
      /* '<S281>:1:53' */
      /* slope of line between the (x,y) to (x0,y0) in ellipse's coordinate frame */
      /* '<S281>:1:54' */
      for (i_0 = 0; i_0 < 32; i_0++) {
        dot02[i_0] = -deltax[i_0] * sint[i_0] + deltay[i_0] * t[i_0];
        sint_0[i_0] = deltax[i_0] * t[i_0] + deltay[i_0] * sint[i_0];
      }

      gbyk_v4b_rdivide(dot02, sint_0, w);
      i_0 = (int32_T)gbyk_v4b_B.TmpSignalConversionAtSFunctionInport3_d[(int32_T)
        ((1.0 + (real_T)e_target) * 3.0 - 2.0) - 1];
      for (i_1 = 0; i_1 < 32; i_1++) {
        sint_0[i_1] = gbyk_v4b_B.TargetTable[((i_0 - 1) << 5) + i_1] * 0.01 *
          w[i_1];
      }

      gbyk_v4b_power(sint_0, i);
      gbyk_v4b_rdivide_p(1.0, i, p);
      i_0 = (int32_T)gbyk_v4b_B.TmpSignalConversionAtSFunctionInport3_d[(int32_T)
        ((1.0 + (real_T)e_target) * 3.0 - 1.0) - 1];
      for (i_1 = 0; i_1 < 32; i_1++) {
        w[i_1] = gbyk_v4b_B.TargetTable[((i_0 - 1) << 5) + i_1] * 0.01;
      }

      gbyk_v4b_power(w, i);
      gbyk_v4b_rdivide_p(1.0, i, w);
      for (i_0 = 0; i_0 < 32; i_0++) {
        sint_0[i_0] = p[i_0] + w[i_0];
      }

      gbyk_v4b_rdivide_p(1.0, sint_0, p);

      /* y2sq is y2^2, where y2 is the intersection of the ellipse and the (x,y) to (x0,y0) line */
      /* '<S281>:1:55' */
      gbyk_v4b_power(dot02, i);
      for (i_0 = 0; i_0 < 32; i_0++) {
        gbyk_v4b_B.intarget_l[i_0 + (e_target << 5)] = (i[i_0] <= p[i_0]);
      }

      /* '<S281>:1:45' */
    }
  } else if (gbyk_v4b_P.KINARM_HandInBox_target_type == 3.0) {
    /* Constant: '<S10>/num_states' */
    /* '<S281>:1:57' */
    /* rectangle */
    /* '<S281>:1:58' */
    f = (int32_T)gbyk_v4b_P.KINARM_HandInBox_num_states;

    /* '<S281>:1:58' */
    for (e_target = 0; e_target < f; e_target++) {
      /* '<S281>:1:58' */
      /* '<S281>:1:59' */
      /* width (sizes in cm in v1.4) */
      /* '<S281>:1:60' */
      /* height (sizes in cm in v1.4) */
      if (gbyk_v4b_B.TmpSignalConversionAtSFunctionInport3_d[(int32_T)((1.0 +
            (real_T)e_target) * 3.0) - 1] > 0.0) {
        /* '<S281>:1:62' */
        /* '<S281>:1:63' */
        i_0 = (int32_T)gbyk_v4b_B.TmpSignalConversionAtSFunctionInport3_d
          [(int32_T)((1.0 + (real_T)e_target) * 3.0) - 1];
        for (i_1 = 0; i_1 < 32; i_1++) {
          t[i_1] = gbyk_v4b_B.TargetTable[((i_0 - 1) << 5) + i_1] *
            0.017453292519943295;
        }

        /* angle (angles in degrees in v1.4) */
      } else {
        /* '<S281>:1:65' */
        for (i_0 = 0; i_0 < 32; i_0++) {
          t[i_0] = 0.0;
        }
      }

      /* '<S281>:1:68' */
      memcpy(&sint[0], &t[0], sizeof(real_T) << 5U);
      gbyk_v4b_sin(sint);

      /* '<S281>:1:69' */
      gbyk_v4b_cos(t);

      /* '<S281>:1:71' */
      /* location of x point in rectangle's coordinate frame */
      /* '<S281>:1:72' */
      /* location of y point in rectangle's coordinate frame */
      for (i_0 = 0; i_0 < 32; i_0++) {
        sint_0[i_0] = deltax[i_0] * t[i_0] + deltay[i_0] * sint[i_0];
      }

      gbyk_v4b_abs(sint_0, i);
      i_0 = (int32_T)gbyk_v4b_B.TmpSignalConversionAtSFunctionInport3_d[(int32_T)
        ((1.0 + (real_T)e_target) * 3.0 - 2.0) - 1];
      for (i_1 = 0; i_1 < 32; i_1++) {
        g[i_1] = (i[i_1] <= gbyk_v4b_B.TargetTable[((i_0 - 1) << 5) + i_1] *
                  0.01 / 2.0);
        sint_0[i_1] = -deltax[i_1] * sint[i_1] + deltay[i_1] * t[i_1];
      }

      gbyk_v4b_abs(sint_0, i);

      /* '<S281>:1:74' */
      i_0 = (int32_T)gbyk_v4b_B.TmpSignalConversionAtSFunctionInport3_d[(int32_T)
        ((1.0 + (real_T)e_target) * 3.0 - 1.0) - 1];
      for (i_1 = 0; i_1 < 32; i_1++) {
        gbyk_v4b_B.intarget_l[i_1 + (e_target << 5)] = (g[i_1] && (i[i_1] <=
          gbyk_v4b_B.TargetTable[((i_0 - 1) << 5) + i_1] * 0.01 / 2.0));
      }

      /* '<S281>:1:58' */
    }
  } else if (gbyk_v4b_P.KINARM_HandInBox_target_type == 4.0) {
    /* Constant: '<S10>/num_states' */
    /* '<S281>:1:76' */
    /* line */
    /* '<S281>:1:77' */
    f = (int32_T)gbyk_v4b_P.KINARM_HandInBox_num_states;

    /* '<S281>:1:77' */
    for (e_target = 0; e_target < f; e_target++) {
      /* '<S281>:1:77' */
      /*  treat the line like a rectangle of height h and width w */
      /*  determine height (stroke width) in the same fashion as in Show_Target */
      if (gbyk_v4b_B.TmpSignalConversionAtSFunctionInport3_d[(int32_T)((1.0 +
            (real_T)e_target) * 3.0 - 2.0) - 1] == 0.0) {
        /* '<S281>:1:80' */
        /* 0 column index means stroke width of 0 */
        /* '<S281>:1:81' */
        for (i_0 = 0; i_0 < 32; i_0++) {
          h[i_0] = 0.0;
        }
      } else if (gbyk_v4b_B.TmpSignalConversionAtSFunctionInport3_d[(int32_T)
                 ((1.0 + (real_T)e_target) * 3.0 - 2.0) - 1] < 0.0) {
        /* '<S281>:1:82' */
        /* -ve column index means stroke width of 1mm */
        /* '<S281>:1:83' */
        for (i_0 = 0; i_0 < 32; i_0++) {
          h[i_0] = 0.001;
        }
      } else {
        /* '<S281>:1:85' */
        i_0 = (int32_T)gbyk_v4b_B.TmpSignalConversionAtSFunctionInport3_d
          [(int32_T)((1.0 + (real_T)e_target) * 3.0 - 2.0) - 1];
        for (i_1 = 0; i_1 < 32; i_1++) {
          h[i_1] = gbyk_v4b_B.TargetTable[((i_0 - 1) << 5) + i_1] * 0.01;
        }

        /* target table contains width in cm */
      }

      /* '<S281>:1:88' */
      i_0 = (int32_T)gbyk_v4b_B.TmpSignalConversionAtSFunctionInport3_d[(int32_T)
        ((1.0 + (real_T)e_target) * 3.0 - 1.0) - 1];

      /* endpoint in x relative to start point (cm) */
      /* '<S281>:1:89' */
      i_1 = (int32_T)gbyk_v4b_B.TmpSignalConversionAtSFunctionInport3_d[(int32_T)
        ((1.0 + (real_T)e_target) * 3.0) - 1];
      for (i_2 = 0; i_2 < 32; i_2++) {
        p[i_2] = gbyk_v4b_B.TargetTable[((i_0 - 1) << 5) + i_2] * 0.01;
        sint[i_2] = gbyk_v4b_B.TargetTable[((i_1 - 1) << 5) + i_2] * 0.01;
      }

      /* endpoint in y relative to start point (cm) */
      /* '<S281>:1:91' */
      gbyk_v4b_power(p, w);
      gbyk_v4b_power(sint, i);
      for (i_0 = 0; i_0 < 32; i_0++) {
        dot11_0 = w[i_0];
        dot11_0 += i[i_0];
        w[i_0] = dot11_0;
      }

      gbyk_v4b_sqrt(w);

      /* width (cm) */
      /*  determine the vector from the line's midpoint to the hand position */
      /* '<S281>:1:94' */
      /* '<S281>:1:95' */
      /* '<S281>:1:97' */
      gbyk_v4b_atan2(sint, p, t);

      /* calculate angle of the line (rads) */
      /* '<S281>:1:98' */
      for (i_0 = 0; i_0 < 32; i_0++) {
        sint_1 = sint[i_0];
        dot02[i_0] = deltax[i_0] - p[i_0] / 2.0;
        dot11[i_0] = deltay[i_0] - sint_1 / 2.0;
        sint_1 = t[i_0];
        sint[i_0] = sint_1;
      }

      gbyk_v4b_sin(sint);

      /* '<S281>:1:99' */
      gbyk_v4b_cos(t);

      /* '<S281>:1:101' */
      /* location of x point in rectangle's coordinate frame */
      /* '<S281>:1:102' */
      /* location of y point in rectangle's coordinate frame */
      for (i_0 = 0; i_0 < 32; i_0++) {
        sint_0[i_0] = dot02[i_0] * t[i_0] + dot11[i_0] * sint[i_0];
      }

      gbyk_v4b_abs(sint_0, i);
      for (i_0 = 0; i_0 < 32; i_0++) {
        g[i_0] = (i[i_0] <= w[i_0] / 2.0);
        sint_0[i_0] = -dot02[i_0] * sint[i_0] + dot11[i_0] * t[i_0];
      }

      gbyk_v4b_abs(sint_0, i);

      /* '<S281>:1:104' */
      for (i_0 = 0; i_0 < 32; i_0++) {
        gbyk_v4b_B.intarget_l[i_0 + (e_target << 5)] = (g[i_0] && (i[i_0] <=
          h[i_0] / 2.0));
      }

      /* '<S281>:1:77' */
    }
  } else {
    if (gbyk_v4b_P.KINARM_HandInBox_target_type == 5.0) {
      /* Constant: '<S10>/num_states' */
      /* '<S281>:1:106' */
      /*  triangle */
      /* '<S281>:1:107' */
      f = (int32_T)gbyk_v4b_P.KINARM_HandInBox_num_states;

      /* '<S281>:1:107' */
      for (e_target = 0; e_target < f; e_target++) {
        /* '<S281>:1:107' */
        /* '<S281>:1:108' */
        i_0 = (int32_T)gbyk_v4b_B.TmpSignalConversionAtSFunctionInport3_d
          [(int32_T)((1.0 + (real_T)e_target) * 4.0 - 3.0) - 1];
        for (i_1 = 0; i_1 < 32; i_1++) {
          w[i_1] = gbyk_v4b_B.TargetTable[((i_0 - 1) << 5) + i_1] * 0.01;
        }

        /* length (sizes in cm in v1.4) */
        /*  If a height column of 0 is specified, make the triangle equilateral. Otherwise, use the */
        /*  values for height and peak offset from the target table. */
        if (gbyk_v4b_B.TmpSignalConversionAtSFunctionInport3_d[(int32_T)((1.0 +
              (real_T)e_target) * 4.0 - 2.0) - 1] > 0.0) {
          /* '<S281>:1:112' */
          /* '<S281>:1:113' */
          i_0 = (int32_T)gbyk_v4b_B.TmpSignalConversionAtSFunctionInport3_d
            [(int32_T)((1.0 + (real_T)e_target) * 4.0 - 2.0) - 1];

          /* height (sizes in cm in v1.4) */
          /* '<S281>:1:114' */
          i_1 = (int32_T)gbyk_v4b_B.TmpSignalConversionAtSFunctionInport3_d
            [(int32_T)((1.0 + (real_T)e_target) * 4.0 - 1.0) - 1];
          for (i_2 = 0; i_2 < 32; i_2++) {
            h[i_2] = gbyk_v4b_B.TargetTable[((i_0 - 1) << 5) + i_2] * 0.01;
            p[i_2] = gbyk_v4b_B.TargetTable[((i_1 - 1) << 5) + i_2] * 0.01;
          }

          /* peak offset (sizes in cm in v1.4) */
        } else {
          /* '<S281>:1:116' */
          /* '<S281>:1:117' */
          for (i_0 = 0; i_0 < 32; i_0++) {
            h[i_0] = w[i_0] * 0.8660254037844386;
            p[i_0] = 0.0;
          }
        }

        if (gbyk_v4b_B.TmpSignalConversionAtSFunctionInport3_d[(int32_T)((1.0 +
              (real_T)e_target) * 4.0) - 1] > 0.0) {
          /* '<S281>:1:120' */
          /* '<S281>:1:121' */
          i_0 = (int32_T)gbyk_v4b_B.TmpSignalConversionAtSFunctionInport3_d
            [(int32_T)((1.0 + (real_T)e_target) * 4.0) - 1];
          for (i_1 = 0; i_1 < 32; i_1++) {
            t[i_1] = gbyk_v4b_B.TargetTable[((i_0 - 1) << 5) + i_1] *
              0.017453292519943295;
          }

          /* angle (angles in degrees in v1.4) */
        } else {
          /* '<S281>:1:123' */
          for (i_0 = 0; i_0 < 32; i_0++) {
            t[i_0] = 0.0;
          }
        }

        /* '<S281>:1:126' */
        memcpy(&sint[0], &t[0], sizeof(real_T) << 5U);
        gbyk_v4b_sin(sint);

        /* '<S281>:1:127' */
        gbyk_v4b_cos(t);

        /* '<S281>:1:129' */
        /* location of x point in triangle's coordinate frame */
        /* '<S281>:1:130' */
        /* location of y point in triangle's coordinate frame */
        /*  Perform a point-in-triangle test using Barycentric coordinates. */
        /* '<S281>:1:133' */
        for (i_0 = 0; i_0 < 32; i_0++) {
          A[i_0] = -w[i_0] / 2.0 - p[i_0] / 3.0;
        }

        /* '<S281>:1:134' */
        /* '<S281>:1:135' */
        /* '<S281>:1:137' */
        for (i_0 = 0; i_0 < 32; i_0++) {
          A[i_0 + 32] = -h[i_0] / 3.0;
          w_0[i_0] = w[i_0] / 2.0 - p[i_0] / 3.0;
        }

        for (i_0 = 0; i_0 < 32; i_0++) {
          w_0[i_0 + 32] = -h[i_0] / 3.0;
        }

        for (i_0 = 0; i_0 < 64; i_0++) {
          v0[i_0] = w_0[i_0] - A[i_0];
        }

        /* '<S281>:1:138' */
        for (i_0 = 0; i_0 < 32; i_0++) {
          w_0[i_0] = 2.0 * p[i_0] / 3.0;
        }

        for (i_0 = 0; i_0 < 32; i_0++) {
          w_0[i_0 + 32] = 2.0 * h[i_0] / 3.0;
        }

        for (i_0 = 0; i_0 < 64; i_0++) {
          v1[i_0] = w_0[i_0] - A[i_0];
        }

        /* '<S281>:1:139' */
        for (i_0 = 0; i_0 < 32; i_0++) {
          w_0[i_0] = deltax[i_0] * t[i_0] + deltay[i_0] * sint[i_0];
        }

        for (i_0 = 0; i_0 < 32; i_0++) {
          w_0[i_0 + 32] = -deltax[i_0] * sint[i_0] + deltay[i_0] * t[i_0];
        }

        for (i_0 = 0; i_0 < 64; i_0++) {
          v2[i_0] = w_0[i_0] - A[i_0];
        }

        /* '<S281>:1:141' */
        /* '<S281>:1:142' */
        /* '<S281>:1:143' */
        /* '<S281>:1:144' */
        /* '<S281>:1:145' */
        /* '<S281>:1:147' */
        for (i_0 = 0; i_0 < 32; i_0++) {
          sint_1 = v0[32 + i_0] * v0[32 + i_0] + v0[i_0] * v0[i_0];
          p_0 = v0[32 + i_0] * v1[32 + i_0] + v0[i_0] * v1[i_0];
          dot02[i_0] = v0[32 + i_0] * v2[32 + i_0] + v0[i_0] * v2[i_0];
          dot11_0 = v1[32 + i_0] * v1[32 + i_0] + v1[i_0] * v1[i_0];
          w[i_0] = v1[32 + i_0] * v2[32 + i_0] + v1[i_0] * v2[i_0];
          sint_0[i_0] = sint_1 * dot11_0 - p_0 * p_0;
          sint[i_0] = sint_1;
          p[i_0] = p_0;
          dot11[i_0] = dot11_0;
        }

        gbyk_v4b_rdivide_p(1.0, sint_0, h);

        /* '<S281>:1:148' */
        /* '<S281>:1:149' */
        for (i_0 = 0; i_0 < 32; i_0++) {
          dot11_0 = dot11[i_0];
          sint_1 = sint[i_0];
          dot11_0 = (dot11_0 * dot02[i_0] - p[i_0] * w[i_0]) * h[i_0];
          sint_1 = (sint_1 * w[i_0] - p[i_0] * dot02[i_0]) * h[i_0];
          sint[i_0] = sint_1;
          dot11[i_0] = dot11_0;
        }

        /* '<S281>:1:151' */
        for (i_0 = 0; i_0 < 32; i_0++) {
          gbyk_v4b_B.intarget_l[i_0 + (e_target << 5)] = ((dot11[i_0] > 0.0) &&
            (sint[i_0] > 0.0) && (dot11[i_0] + sint[i_0] < 1.0));
        }

        /* '<S281>:1:107' */
      }
    }
  }

  /* End of Constant: '<S10>/Target_Type' */
}
