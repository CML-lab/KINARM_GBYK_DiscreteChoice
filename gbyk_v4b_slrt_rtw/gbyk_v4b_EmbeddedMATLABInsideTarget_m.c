/*
 * Code generation for system system '<S11>/Embedded MATLAB InsideTarget'
 *
 * Model                      : gbyk_v4b
 * Model version              : 1.2667
 * Simulink Coder version : 8.8.1 (R2015aSP1) 04-Sep-2015
 * C source code generated on : Tue Sep 15 15:02:19 2020
 *
 * Note that the functions contained in this file are part of a Simulink
 * model, and are not self-contained algorithms.
 */

#include "gbyk_v4b_EmbeddedMATLABInsideTarget_m.h"

/* Include model header file for global data */
#include "gbyk_v4b.h"
#include "gbyk_v4b_private.h"

/* Forward declaration for local functions */
static void gbyk_v4b_sin_f(real_T x[32]);
static void gbyk_v4b_cos_c(real_T x[32]);
static void gbyk_v4b_rdivide_ax(real_T x, const real_T y[32], real_T z[32]);
static void gbyk_v4b_power_m(const real_T a[32], real_T y[32]);
static void gbyk_v4b_sqrt_e(real_T x[32]);
static void gbyk_v4b_atan2_f(const real_T y[32], const real_T x[32], real_T r[32]);
static void gbyk_v4b_abs_n(const real_T x[32], real_T y[32]);
static void gbyk_v4b_rdivide_a(const real_T x[32], const real_T y[32], real_T z
  [32]);

/* Function for MATLAB Function: '<S11>/Embedded MATLAB InsideTarget' */
static void gbyk_v4b_sin_f(real_T x[32])
{
  int32_T k;
  for (k = 0; k < 32; k++) {
    x[k] = sin(x[k]);
  }
}

/* Function for MATLAB Function: '<S11>/Embedded MATLAB InsideTarget' */
static void gbyk_v4b_cos_c(real_T x[32])
{
  int32_T k;
  for (k = 0; k < 32; k++) {
    x[k] = cos(x[k]);
  }
}

/* Function for MATLAB Function: '<S11>/Embedded MATLAB InsideTarget' */
static void gbyk_v4b_rdivide_ax(real_T x, const real_T y[32], real_T z[32])
{
  int32_T i;
  for (i = 0; i < 32; i++) {
    z[i] = x / y[i];
  }
}

/* Function for MATLAB Function: '<S11>/Embedded MATLAB InsideTarget' */
static void gbyk_v4b_power_m(const real_T a[32], real_T y[32])
{
  int32_T k;
  for (k = 0; k < 32; k++) {
    y[k] = a[k] * a[k];
  }
}

/* Function for MATLAB Function: '<S11>/Embedded MATLAB InsideTarget' */
static void gbyk_v4b_sqrt_e(real_T x[32])
{
  int32_T k;
  for (k = 0; k < 32; k++) {
    x[k] = sqrt(x[k]);
  }
}

/* Function for MATLAB Function: '<S11>/Embedded MATLAB InsideTarget' */
static void gbyk_v4b_atan2_f(const real_T y[32], const real_T x[32], real_T r[32])
{
  int32_T k;
  for (k = 0; k < 32; k++) {
    r[k] = rt_atan2d_snf(y[k], x[k]);
  }
}

/* Function for MATLAB Function: '<S11>/Embedded MATLAB InsideTarget' */
static void gbyk_v4b_abs_n(const real_T x[32], real_T y[32])
{
  int32_T k;
  for (k = 0; k < 32; k++) {
    y[k] = fabs(x[k]);
  }
}

/* Function for MATLAB Function: '<S11>/Embedded MATLAB InsideTarget' */
static void gbyk_v4b_rdivide_a(const real_T x[32], const real_T y[32], real_T z
  [32])
{
  int32_T i;
  for (i = 0; i < 32; i++) {
    z[i] = x[i] / y[i];
  }
}

/* Output and update for atomic system: '<S11>/Embedded MATLAB InsideTarget' */
void gbyk_v4b_EmbeddedMATLABInsideTarget_m(void)
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

  /* SignalConversion: '<S283>/TmpSignal ConversionAt SFunction Inport3' incorporates:
   *  Constant: '<S11>/attribcol1'
   *  Constant: '<S11>/attribcol2'
   *  Constant: '<S11>/attribcol3'
   *  Constant: '<S11>/attribcol4'
   *  Constant: '<S11>/attribcol5'
   */
  gbyk_v4b_B.TmpSignalConversionAtSFunctionInport3[0] =
    gbyk_v4b_P.KINARM_HandInTarget_attribcol1;
  gbyk_v4b_B.TmpSignalConversionAtSFunctionInport3[1] =
    gbyk_v4b_P.attribcol2_Value;
  gbyk_v4b_B.TmpSignalConversionAtSFunctionInport3[2] =
    gbyk_v4b_P.attribcol3_Value;
  gbyk_v4b_B.TmpSignalConversionAtSFunctionInport3[3] =
    gbyk_v4b_P.attribcol4_Value;
  gbyk_v4b_B.TmpSignalConversionAtSFunctionInport3[4] =
    gbyk_v4b_P.attribcol5_Value;

  /* MATLAB Function 'KINARM_HandInTarget/Embedded MATLAB InsideTarget': '<S283>:1' */
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
  /* '<S283>:1:26' */
  /* '<S283>:1:27' */
  /* '<S283>:1:29' */
  for (i_0 = 0; i_0 < 160; i_0++) {
    gbyk_v4b_B.intarget[i_0] = 0.0;
  }

  /* '<S283>:1:31' */
  /* Target Table sizes in cm in v1.4 */
  /* '<S283>:1:32' */
  /* Target Table sizes in cm in v1.4 */
  /* '<S283>:1:34' */
  dot11_0 = gbyk_v4b_B.MultiportSwitch[0];

  /* '<S283>:1:35' */
  sint_1 = gbyk_v4b_B.MultiportSwitch[1];
  for (i_0 = 0; i_0 < 32; i_0++) {
    deltax[i_0] = dot11_0 - gbyk_v4b_B.TargetTable[i_0] * 0.01;
    deltay[i_0] = sint_1 - gbyk_v4b_B.TargetTable[32 + i_0] * 0.01;
  }

  /* Constant: '<S11>/Target_Type' */
  if (gbyk_v4b_P.KINARM_HandInTarget_target_type == 1.0) {
    /* Constant: '<S11>/num_states' */
    /* '<S283>:1:37' */
    /* circle */
    /* '<S283>:1:38' */
    f = (int32_T)gbyk_v4b_P.KINARM_HandInTarget_num_states;

    /* '<S283>:1:38' */
    for (e_target = 0; e_target < f; e_target++) {
      /* '<S283>:1:38' */
      /* '<S283>:1:39' */
      /* Target Table sizes in cm in v1.4 */
      /*  simple euclidean distance */
      /* '<S283>:1:41' */
      gbyk_v4b_power_m(deltax, p);
      gbyk_v4b_power_m(deltay, i);

      /* distance2 is the square of the distance */
      /* '<S283>:1:42' */
      i_0 = (int32_T)gbyk_v4b_B.TmpSignalConversionAtSFunctionInport3[e_target];
      for (i_1 = 0; i_1 < 32; i_1++) {
        p_0 = p[i_1];
        p_0 += i[i_1];
        w[i_1] = gbyk_v4b_B.TargetTable[((i_0 - 1) << 5) + i_1] * 0.01;
        p[i_1] = p_0;
      }

      gbyk_v4b_power_m(w, i);
      for (i_0 = 0; i_0 < 32; i_0++) {
        gbyk_v4b_B.intarget[i_0 + (e_target << 5)] = (p[i_0] <= i[i_0]);
      }

      /* '<S283>:1:38' */
    }
  } else if (gbyk_v4b_P.KINARM_HandInTarget_target_type == 2.0) {
    /* Constant: '<S11>/num_states' */
    /* '<S283>:1:44' */
    /* ellipse */
    /* '<S283>:1:45' */
    f = (int32_T)gbyk_v4b_P.KINARM_HandInTarget_num_states;

    /* '<S283>:1:45' */
    for (e_target = 0; e_target < f; e_target++) {
      /* '<S283>:1:45' */
      /* '<S283>:1:46' */
      /* Target Table sizes in cm in v1.4 */
      /* '<S283>:1:47' */
      /* Target Table sizes in cm in v1.4	 */
      /* '<S283>:1:48' */
      i_0 = (int32_T)gbyk_v4b_B.TmpSignalConversionAtSFunctionInport3[(int32_T)
        ((1.0 + (real_T)e_target) * 3.0) - 1];

      /* Target Table angles in degrees in v1.4 */
      /* '<S283>:1:49' */
      for (i_1 = 0; i_1 < 32; i_1++) {
        dot11_0 = gbyk_v4b_B.TargetTable[((i_0 - 1) << 5) + i_1] *
          0.017453292519943295;
        sint[i_1] = dot11_0;
        t[i_1] = dot11_0;
      }

      gbyk_v4b_sin_f(sint);

      /* '<S283>:1:50' */
      gbyk_v4b_cos_c(t);

      /* '<S283>:1:51' */
      /* location of x point in ellipse's coordinate frame */
      /* '<S283>:1:52' */
      /* location of y point in ellipse's coordinate frame */
      /* '<S283>:1:53' */
      /* slope of line between the (x,y) to (x0,y0) in ellipse's coordinate frame */
      /* '<S283>:1:54' */
      for (i_0 = 0; i_0 < 32; i_0++) {
        dot02[i_0] = -deltax[i_0] * sint[i_0] + deltay[i_0] * t[i_0];
        sint_0[i_0] = deltax[i_0] * t[i_0] + deltay[i_0] * sint[i_0];
      }

      gbyk_v4b_rdivide_a(dot02, sint_0, w);
      i_0 = (int32_T)gbyk_v4b_B.TmpSignalConversionAtSFunctionInport3[(int32_T)
        ((1.0 + (real_T)e_target) * 3.0 - 2.0) - 1];
      for (i_1 = 0; i_1 < 32; i_1++) {
        sint_0[i_1] = gbyk_v4b_B.TargetTable[((i_0 - 1) << 5) + i_1] * 0.01 *
          w[i_1];
      }

      gbyk_v4b_power_m(sint_0, i);
      gbyk_v4b_rdivide_ax(1.0, i, p);
      i_0 = (int32_T)gbyk_v4b_B.TmpSignalConversionAtSFunctionInport3[(int32_T)
        ((1.0 + (real_T)e_target) * 3.0 - 1.0) - 1];
      for (i_1 = 0; i_1 < 32; i_1++) {
        w[i_1] = gbyk_v4b_B.TargetTable[((i_0 - 1) << 5) + i_1] * 0.01;
      }

      gbyk_v4b_power_m(w, i);
      gbyk_v4b_rdivide_ax(1.0, i, w);
      for (i_0 = 0; i_0 < 32; i_0++) {
        sint_0[i_0] = p[i_0] + w[i_0];
      }

      gbyk_v4b_rdivide_ax(1.0, sint_0, p);

      /* y2sq is y2^2, where y2 is the intersection of the ellipse and the (x,y) to (x0,y0) line */
      /* '<S283>:1:55' */
      gbyk_v4b_power_m(dot02, i);
      for (i_0 = 0; i_0 < 32; i_0++) {
        gbyk_v4b_B.intarget[i_0 + (e_target << 5)] = (i[i_0] <= p[i_0]);
      }

      /* '<S283>:1:45' */
    }
  } else if (gbyk_v4b_P.KINARM_HandInTarget_target_type == 3.0) {
    /* Constant: '<S11>/num_states' */
    /* '<S283>:1:57' */
    /* rectangle */
    /* '<S283>:1:58' */
    f = (int32_T)gbyk_v4b_P.KINARM_HandInTarget_num_states;

    /* '<S283>:1:58' */
    for (e_target = 0; e_target < f; e_target++) {
      /* '<S283>:1:58' */
      /* '<S283>:1:59' */
      /* width (sizes in cm in v1.4) */
      /* '<S283>:1:60' */
      /* height (sizes in cm in v1.4) */
      if (gbyk_v4b_B.TmpSignalConversionAtSFunctionInport3[(int32_T)((1.0 +
            (real_T)e_target) * 3.0) - 1] > 0.0) {
        /* '<S283>:1:62' */
        /* '<S283>:1:63' */
        i_0 = (int32_T)gbyk_v4b_B.TmpSignalConversionAtSFunctionInport3[(int32_T)
          ((1.0 + (real_T)e_target) * 3.0) - 1];
        for (i_1 = 0; i_1 < 32; i_1++) {
          t[i_1] = gbyk_v4b_B.TargetTable[((i_0 - 1) << 5) + i_1] *
            0.017453292519943295;
        }

        /* angle (angles in degrees in v1.4) */
      } else {
        /* '<S283>:1:65' */
        for (i_0 = 0; i_0 < 32; i_0++) {
          t[i_0] = 0.0;
        }
      }

      /* '<S283>:1:68' */
      memcpy(&sint[0], &t[0], sizeof(real_T) << 5U);
      gbyk_v4b_sin_f(sint);

      /* '<S283>:1:69' */
      gbyk_v4b_cos_c(t);

      /* '<S283>:1:71' */
      /* location of x point in rectangle's coordinate frame */
      /* '<S283>:1:72' */
      /* location of y point in rectangle's coordinate frame */
      for (i_0 = 0; i_0 < 32; i_0++) {
        sint_0[i_0] = deltax[i_0] * t[i_0] + deltay[i_0] * sint[i_0];
      }

      gbyk_v4b_abs_n(sint_0, i);
      i_0 = (int32_T)gbyk_v4b_B.TmpSignalConversionAtSFunctionInport3[(int32_T)
        ((1.0 + (real_T)e_target) * 3.0 - 2.0) - 1];
      for (i_1 = 0; i_1 < 32; i_1++) {
        g[i_1] = (i[i_1] <= gbyk_v4b_B.TargetTable[((i_0 - 1) << 5) + i_1] *
                  0.01 / 2.0);
        sint_0[i_1] = -deltax[i_1] * sint[i_1] + deltay[i_1] * t[i_1];
      }

      gbyk_v4b_abs_n(sint_0, i);

      /* '<S283>:1:74' */
      i_0 = (int32_T)gbyk_v4b_B.TmpSignalConversionAtSFunctionInport3[(int32_T)
        ((1.0 + (real_T)e_target) * 3.0 - 1.0) - 1];
      for (i_1 = 0; i_1 < 32; i_1++) {
        gbyk_v4b_B.intarget[i_1 + (e_target << 5)] = (g[i_1] && (i[i_1] <=
          gbyk_v4b_B.TargetTable[((i_0 - 1) << 5) + i_1] * 0.01 / 2.0));
      }

      /* '<S283>:1:58' */
    }
  } else if (gbyk_v4b_P.KINARM_HandInTarget_target_type == 4.0) {
    /* Constant: '<S11>/num_states' */
    /* '<S283>:1:76' */
    /* line */
    /* '<S283>:1:77' */
    f = (int32_T)gbyk_v4b_P.KINARM_HandInTarget_num_states;

    /* '<S283>:1:77' */
    for (e_target = 0; e_target < f; e_target++) {
      /* '<S283>:1:77' */
      /*  treat the line like a rectangle of height h and width w */
      /*  determine height (stroke width) in the same fashion as in Show_Target */
      if (gbyk_v4b_B.TmpSignalConversionAtSFunctionInport3[(int32_T)((1.0 +
            (real_T)e_target) * 3.0 - 2.0) - 1] == 0.0) {
        /* '<S283>:1:80' */
        /* 0 column index means stroke width of 0 */
        /* '<S283>:1:81' */
        for (i_0 = 0; i_0 < 32; i_0++) {
          h[i_0] = 0.0;
        }
      } else if (gbyk_v4b_B.TmpSignalConversionAtSFunctionInport3[(int32_T)((1.0
        + (real_T)e_target) * 3.0 - 2.0) - 1] < 0.0) {
        /* '<S283>:1:82' */
        /* -ve column index means stroke width of 1mm */
        /* '<S283>:1:83' */
        for (i_0 = 0; i_0 < 32; i_0++) {
          h[i_0] = 0.001;
        }
      } else {
        /* '<S283>:1:85' */
        i_0 = (int32_T)gbyk_v4b_B.TmpSignalConversionAtSFunctionInport3[(int32_T)
          ((1.0 + (real_T)e_target) * 3.0 - 2.0) - 1];
        for (i_1 = 0; i_1 < 32; i_1++) {
          h[i_1] = gbyk_v4b_B.TargetTable[((i_0 - 1) << 5) + i_1] * 0.01;
        }

        /* target table contains width in cm */
      }

      /* '<S283>:1:88' */
      i_0 = (int32_T)gbyk_v4b_B.TmpSignalConversionAtSFunctionInport3[(int32_T)
        ((1.0 + (real_T)e_target) * 3.0 - 1.0) - 1];

      /* endpoint in x relative to start point (cm) */
      /* '<S283>:1:89' */
      i_1 = (int32_T)gbyk_v4b_B.TmpSignalConversionAtSFunctionInport3[(int32_T)
        ((1.0 + (real_T)e_target) * 3.0) - 1];
      for (i_2 = 0; i_2 < 32; i_2++) {
        p[i_2] = gbyk_v4b_B.TargetTable[((i_0 - 1) << 5) + i_2] * 0.01;
        sint[i_2] = gbyk_v4b_B.TargetTable[((i_1 - 1) << 5) + i_2] * 0.01;
      }

      /* endpoint in y relative to start point (cm) */
      /* '<S283>:1:91' */
      gbyk_v4b_power_m(p, w);
      gbyk_v4b_power_m(sint, i);
      for (i_0 = 0; i_0 < 32; i_0++) {
        dot11_0 = w[i_0];
        dot11_0 += i[i_0];
        w[i_0] = dot11_0;
      }

      gbyk_v4b_sqrt_e(w);

      /* width (cm) */
      /*  determine the vector from the line's midpoint to the hand position */
      /* '<S283>:1:94' */
      /* '<S283>:1:95' */
      /* '<S283>:1:97' */
      gbyk_v4b_atan2_f(sint, p, t);

      /* calculate angle of the line (rads) */
      /* '<S283>:1:98' */
      for (i_0 = 0; i_0 < 32; i_0++) {
        sint_1 = sint[i_0];
        dot02[i_0] = deltax[i_0] - p[i_0] / 2.0;
        dot11[i_0] = deltay[i_0] - sint_1 / 2.0;
        sint_1 = t[i_0];
        sint[i_0] = sint_1;
      }

      gbyk_v4b_sin_f(sint);

      /* '<S283>:1:99' */
      gbyk_v4b_cos_c(t);

      /* '<S283>:1:101' */
      /* location of x point in rectangle's coordinate frame */
      /* '<S283>:1:102' */
      /* location of y point in rectangle's coordinate frame */
      for (i_0 = 0; i_0 < 32; i_0++) {
        sint_0[i_0] = dot02[i_0] * t[i_0] + dot11[i_0] * sint[i_0];
      }

      gbyk_v4b_abs_n(sint_0, i);
      for (i_0 = 0; i_0 < 32; i_0++) {
        g[i_0] = (i[i_0] <= w[i_0] / 2.0);
        sint_0[i_0] = -dot02[i_0] * sint[i_0] + dot11[i_0] * t[i_0];
      }

      gbyk_v4b_abs_n(sint_0, i);

      /* '<S283>:1:104' */
      for (i_0 = 0; i_0 < 32; i_0++) {
        gbyk_v4b_B.intarget[i_0 + (e_target << 5)] = (g[i_0] && (i[i_0] <= h[i_0]
          / 2.0));
      }

      /* '<S283>:1:77' */
    }
  } else {
    if (gbyk_v4b_P.KINARM_HandInTarget_target_type == 5.0) {
      /* Constant: '<S11>/num_states' */
      /* '<S283>:1:106' */
      /*  triangle */
      /* '<S283>:1:107' */
      f = (int32_T)gbyk_v4b_P.KINARM_HandInTarget_num_states;

      /* '<S283>:1:107' */
      for (e_target = 0; e_target < f; e_target++) {
        /* '<S283>:1:107' */
        /* '<S283>:1:108' */
        i_0 = (int32_T)gbyk_v4b_B.TmpSignalConversionAtSFunctionInport3[(int32_T)
          ((1.0 + (real_T)e_target) * 4.0 - 3.0) - 1];
        for (i_1 = 0; i_1 < 32; i_1++) {
          w[i_1] = gbyk_v4b_B.TargetTable[((i_0 - 1) << 5) + i_1] * 0.01;
        }

        /* length (sizes in cm in v1.4) */
        /*  If a height column of 0 is specified, make the triangle equilateral. Otherwise, use the */
        /*  values for height and peak offset from the target table. */
        if (gbyk_v4b_B.TmpSignalConversionAtSFunctionInport3[(int32_T)((1.0 +
              (real_T)e_target) * 4.0 - 2.0) - 1] > 0.0) {
          /* '<S283>:1:112' */
          /* '<S283>:1:113' */
          i_0 = (int32_T)gbyk_v4b_B.TmpSignalConversionAtSFunctionInport3
            [(int32_T)((1.0 + (real_T)e_target) * 4.0 - 2.0) - 1];

          /* height (sizes in cm in v1.4) */
          /* '<S283>:1:114' */
          i_1 = (int32_T)gbyk_v4b_B.TmpSignalConversionAtSFunctionInport3
            [(int32_T)((1.0 + (real_T)e_target) * 4.0 - 1.0) - 1];
          for (i_2 = 0; i_2 < 32; i_2++) {
            h[i_2] = gbyk_v4b_B.TargetTable[((i_0 - 1) << 5) + i_2] * 0.01;
            p[i_2] = gbyk_v4b_B.TargetTable[((i_1 - 1) << 5) + i_2] * 0.01;
          }

          /* peak offset (sizes in cm in v1.4) */
        } else {
          /* '<S283>:1:116' */
          /* '<S283>:1:117' */
          for (i_0 = 0; i_0 < 32; i_0++) {
            h[i_0] = w[i_0] * 0.8660254037844386;
            p[i_0] = 0.0;
          }
        }

        if (gbyk_v4b_B.TmpSignalConversionAtSFunctionInport3[(int32_T)((1.0 +
              (real_T)e_target) * 4.0) - 1] > 0.0) {
          /* '<S283>:1:120' */
          /* '<S283>:1:121' */
          i_0 = (int32_T)gbyk_v4b_B.TmpSignalConversionAtSFunctionInport3
            [(int32_T)((1.0 + (real_T)e_target) * 4.0) - 1];
          for (i_1 = 0; i_1 < 32; i_1++) {
            t[i_1] = gbyk_v4b_B.TargetTable[((i_0 - 1) << 5) + i_1] *
              0.017453292519943295;
          }

          /* angle (angles in degrees in v1.4) */
        } else {
          /* '<S283>:1:123' */
          for (i_0 = 0; i_0 < 32; i_0++) {
            t[i_0] = 0.0;
          }
        }

        /* '<S283>:1:126' */
        memcpy(&sint[0], &t[0], sizeof(real_T) << 5U);
        gbyk_v4b_sin_f(sint);

        /* '<S283>:1:127' */
        gbyk_v4b_cos_c(t);

        /* '<S283>:1:129' */
        /* location of x point in triangle's coordinate frame */
        /* '<S283>:1:130' */
        /* location of y point in triangle's coordinate frame */
        /*  Perform a point-in-triangle test using Barycentric coordinates. */
        /* '<S283>:1:133' */
        for (i_0 = 0; i_0 < 32; i_0++) {
          A[i_0] = -w[i_0] / 2.0 - p[i_0] / 3.0;
        }

        /* '<S283>:1:134' */
        /* '<S283>:1:135' */
        /* '<S283>:1:137' */
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

        /* '<S283>:1:138' */
        for (i_0 = 0; i_0 < 32; i_0++) {
          w_0[i_0] = 2.0 * p[i_0] / 3.0;
        }

        for (i_0 = 0; i_0 < 32; i_0++) {
          w_0[i_0 + 32] = 2.0 * h[i_0] / 3.0;
        }

        for (i_0 = 0; i_0 < 64; i_0++) {
          v1[i_0] = w_0[i_0] - A[i_0];
        }

        /* '<S283>:1:139' */
        for (i_0 = 0; i_0 < 32; i_0++) {
          w_0[i_0] = deltax[i_0] * t[i_0] + deltay[i_0] * sint[i_0];
        }

        for (i_0 = 0; i_0 < 32; i_0++) {
          w_0[i_0 + 32] = -deltax[i_0] * sint[i_0] + deltay[i_0] * t[i_0];
        }

        for (i_0 = 0; i_0 < 64; i_0++) {
          v2[i_0] = w_0[i_0] - A[i_0];
        }

        /* '<S283>:1:141' */
        /* '<S283>:1:142' */
        /* '<S283>:1:143' */
        /* '<S283>:1:144' */
        /* '<S283>:1:145' */
        /* '<S283>:1:147' */
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

        gbyk_v4b_rdivide_ax(1.0, sint_0, h);

        /* '<S283>:1:148' */
        /* '<S283>:1:149' */
        for (i_0 = 0; i_0 < 32; i_0++) {
          dot11_0 = dot11[i_0];
          sint_1 = sint[i_0];
          dot11_0 = (dot11_0 * dot02[i_0] - p[i_0] * w[i_0]) * h[i_0];
          sint_1 = (sint_1 * w[i_0] - p[i_0] * dot02[i_0]) * h[i_0];
          sint[i_0] = sint_1;
          dot11[i_0] = dot11_0;
        }

        /* '<S283>:1:151' */
        for (i_0 = 0; i_0 < 32; i_0++) {
          gbyk_v4b_B.intarget[i_0 + (e_target << 5)] = ((dot11[i_0] > 0.0) &&
            (sint[i_0] > 0.0) && (dot11[i_0] + sint[i_0] < 1.0));
        }

        /* '<S283>:1:107' */
      }
    }
  }

  /* End of Constant: '<S11>/Target_Type' */
}
