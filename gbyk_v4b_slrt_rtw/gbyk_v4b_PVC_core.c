/*
 * Code generation for system system '<S15>/PVC_core'
 *
 * Model                      : gbyk_v4b
 * Model version              : 1.2667
 * Simulink Coder version : 8.8.1 (R2015aSP1) 04-Sep-2015
 * C source code generated on : Tue Sep 15 15:02:19 2020
 *
 * Note that the functions contained in this file are part of a Simulink
 * model, and are not self-contained algorithms.
 */

#include "gbyk_v4b_PVC_core.h"

/* Include model header file for global data */
#include "gbyk_v4b.h"
#include "gbyk_v4b_private.h"

/* Forward declaration for local functions */
static void gbyk_v4b_isPermTarget(const real_T VCODE[70], boolean_T *perm,
  boolean_T *isValidID);
static boolean_T gbyk_v4b_hasColorValue(real_T value);
static boolean_T gbyk_v4b_containsLargerABS1(const real_T VCODE[70], real_T
  count);
static void gbyk_v4b_toString(const real_T VCODE[70], int32_T string[13], real_T
  *intlen, real_T *string_length);
static int32_T gbyk_v4b_packColor(real_T color, real_T alpha);
static int32_T gbyk_v4b_packValues(real_T v1);
static int32_T gbyk_v4b_packValues_i(real_T v1, real_T v2, boolean_T bUse10m);
static uint32_T gbyk_v4b_toBitField(const boolean_T field[13]);
static void gbyk_v4b_pack_code(const real_T VCODE[70], int32_T packed_code[34],
  real_T *b_index, boolean_T *isPerm, real_T *errID);

/* Function for MATLAB Function: '<S298>/Pack VCodeFrame2' */
static void gbyk_v4b_isPermTarget(const real_T VCODE[70], boolean_T *perm,
  boolean_T *isValidID)
{
  /* '<S300>:1:432' */
  /* '<S300>:1:433' */
  /* 15360 as an ID means 'clear all perm targets' */
  /* '<S300>:1:435' */
  *perm = ((VCODE[0] > 100.0) && (VCODE[0] < 130.0));

  /* '<S300>:1:436' */
  *isValidID = (((VCODE[7] > 0.0) && (VCODE[7] < 500.0)) || (VCODE[7] == 15360.0));
}

/* Function for MATLAB Function: '<S298>/Pack VCodeFrame2' */
static boolean_T gbyk_v4b_hasColorValue(real_T value)
{
  /* '<S300>:1:313' */
  return (value != -2.147483648E+9) && (value != 1.6777216E+7);
}

/* Function for MATLAB Function: '<S298>/Pack VCodeFrame2' */
static boolean_T gbyk_v4b_containsLargerABS1(const real_T VCODE[70], real_T
  count)
{
  int32_T k;
  int32_T idx;
  int32_T b_ii;
  boolean_T exitg1;
  real_T measures_data[50];
  int32_T measures_sizes;
  boolean_T x_data[50];

  /* %%%% */
  /*  search for values > 1m. */
  /* this apprears to be ~3 us slower than the old looping implementation */
  if (17.0 > count) {
    k = 0;
    idx = 0;
  } else {
    k = 16;
    idx = (int32_T)count;
  }

  /* '<S300>:1:416' */
  measures_sizes = idx - k;
  idx -= k;
  for (b_ii = 0; b_ii < idx; b_ii++) {
    measures_data[b_ii] = VCODE[k + b_ii];
  }

  for (b_ii = 0; b_ii < measures_sizes; b_ii++) {
    x_data[b_ii] = ((measures_data[b_ii] > 1.0) || (measures_data[b_ii] < -1.0));
  }

  if (1 <= measures_sizes) {
    k = 1;
  } else {
    k = measures_sizes;
  }

  idx = 0;
  b_ii = 1;
  exitg1 = false;
  while ((!exitg1) && (b_ii <= measures_sizes)) {
    if (x_data[b_ii - 1]) {
      idx = 1;
      exitg1 = true;
    } else {
      b_ii++;
    }
  }

  if (k == 1) {
    if (idx == 0) {
      k = 0;
    }
  } else {
    k = !(1 > idx);
  }

  /* '<S300>:1:417' */
  return !(k == 0);
}

/* Function for MATLAB Function: '<S298>/Pack VCodeFrame2' */
static void gbyk_v4b_toString(const real_T VCODE[70], int32_T string[13], real_T
  *intlen, real_T *string_length)
{
  int32_T j;
  int32_T m;
  int32_T c2;
  int32_T c3;
  int32_T c4;
  boolean_T exitg1;
  int32_T i;

  /* '<S300>:1:326' */
  *string_length = 0.0;

  /* '<S300>:1:327' */
  j = 0;

  /* '<S300>:1:328' */
  m = 15;

  /* '<S300>:1:329' */
  for (i = 0; i < 13; i++) {
    string[i] = 0;
  }

  exitg1 = false;
  while ((!exitg1) && (j < 13)) {
    /* '<S300>:1:331' */
    /* '<S300>:1:332' */
    i = (int32_T)rt_roundd_snf(VCODE[m - 1]);

    /* '<S300>:1:333' */
    c2 = (int32_T)rt_roundd_snf(VCODE[m]);
    if (j < 12) {
      /* '<S300>:1:335' */
      /* '<S300>:1:336' */
      c3 = (int32_T)rt_roundd_snf(VCODE[m + 1]);

      /* '<S300>:1:337' */
      c4 = (int32_T)rt_roundd_snf(VCODE[m + 2]);
    } else {
      /* '<S300>:1:339' */
      c3 = 0;

      /* '<S300>:1:340' */
      c4 = 0;
    }

    /* '<S300>:1:343' */
    string[j] = (((i << 24) + (c2 << 16)) + (c3 << 8)) + c4;

    /* '<S300>:1:344' */
    *string_length = ((((real_T)(i != 0) + *string_length) + (real_T)(c2 != 0))
                      + (real_T)(c3 != 0)) + (real_T)(c4 != 0);
    if ((i == 0) || (c2 == 0) || (c3 == 0) || (c4 == 0)) {
      /* '<S300>:1:346' */
      exitg1 = true;
    } else {
      /* '<S300>:1:350' */
      j++;

      /* '<S300>:1:351' */
      m += 4;
    }
  }

  /* '<S300>:1:354' */
  *intlen = ceil(*string_length / 4.0);
}

/* Function for MATLAB Function: '<S298>/Pack VCodeFrame2' */
static int32_T gbyk_v4b_packColor(real_T color, real_T alpha)
{
  int32_T packed;

  /* '<S300>:1:407' */
  /* '<S300>:1:408' */
  /* make sure we just have RRGGBB */
  /* '<S300>:1:409' */
  packed = ((int32_T)rt_roundd_snf(alpha / 100.0 * 255.0) << 24) + ((int32_T)
    rt_roundd_snf(color) & 16777215);
  return packed;
}

/* Function for MATLAB Function: '<S298>/Pack VCodeFrame2' */
static int32_T gbyk_v4b_packValues(real_T v1)
{
  int32_T packed;
  int32_T v1Ticks;

  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*  All measurements are encoded into 16 bit signed integers, i.e. -2^15 to 2^15. The encoding assumes that */
  /*  the scale we are trying to measure across is either -1m to 1m or -10m to 10m. For -1m to 1m the accuracy */
  /*  is 0.03mm, for 10m the accuracy is 0.3mm. The conversion is just count * resolution. */
  /* '<S300>:1:366' */
  v1Ticks = (int32_T)rt_roundd_snf(v1 / 3.0517578125E-5);
  if (v1Ticks > 32767) {
    /* '<S300>:1:370' */
    /* '<S300>:1:371' */
    v1Ticks = 32767;
  } else {
    if (v1Ticks < -32767) {
      /* '<S300>:1:372' */
      /* '<S300>:1:373' */
      v1Ticks = -32767;
    }
  }

  /*      if abs(v2Ticks) > 2^15 - 1 */
  /*          v2Ticks = sign(v2Ticks) *  (2^15 - 1); */
  /*      end */
  /* '<S300>:1:386' */
  packed = v1Ticks << 16;
  return packed;
}

real_T rt_remd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T tr;
  boolean_T y_0;
  boolean_T y_1;
  y_0 = ((!rtIsNaN(u0)) && (!rtIsInf(u0)));
  y_1 = ((!rtIsNaN(u1)) && (!rtIsInf(u1)));
  if (!(y_0 && y_1)) {
    y = (rtNaN);
  } else {
    if (u1 < 0.0) {
      y = ceil(u1);
    } else {
      y = floor(u1);
    }

    if ((u1 != 0.0) && (u1 != y)) {
      tr = u0 / u1;
      if (fabs(tr - rt_roundd_snf(tr)) <= DBL_EPSILON * fabs(tr)) {
        y = 0.0;
      } else {
        y = fmod(u0, u1);
      }
    } else {
      y = fmod(u0, u1);
    }
  }

  return y;
}

/* Function for MATLAB Function: '<S298>/Pack VCodeFrame2' */
static int32_T gbyk_v4b_packValues_i(real_T v1, real_T v2, boolean_T bUse10m)
{
  int32_T packed;
  real_T tickSize;
  int32_T v1Ticks;
  int32_T v2Ticks;

  /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
  /*  All measurements are encoded into 16 bit signed integers, i.e. -2^15 to 2^15. The encoding assumes that */
  /*  the scale we are trying to measure across is either -1m to 1m or -10m to 10m. For -1m to 1m the accuracy */
  /*  is 0.03mm, for 10m the accuracy is 0.3mm. The conversion is just count * resolution. */
  /* '<S300>:1:362' */
  tickSize = 3.0517578125E-5;
  if (bUse10m) {
    /* '<S300>:1:363' */
    /* '<S300>:1:364' */
    tickSize = 0.00030517578125;
  }

  /* '<S300>:1:366' */
  v1Ticks = (int32_T)rt_roundd_snf(v1 / tickSize);

  /* '<S300>:1:367' */
  v2Ticks = (int32_T)rt_roundd_snf(v2 / tickSize);
  if (v1Ticks > 32767) {
    /* '<S300>:1:370' */
    /* '<S300>:1:371' */
    v1Ticks = 32767;
  } else {
    if (v1Ticks < -32767) {
      /* '<S300>:1:372' */
      /* '<S300>:1:373' */
      v1Ticks = -32767;
    }
  }

  if (v2Ticks > 32767) {
    /* '<S300>:1:376' */
    /* '<S300>:1:377' */
    v2Ticks = 32767;
  } else {
    if (v2Ticks < -32767) {
      /* '<S300>:1:378' */
      /* '<S300>:1:379' */
      v2Ticks = -32767;
    }
  }

  /*      if abs(v2Ticks) > 2^15 - 1 */
  /*          v2Ticks = sign(v2Ticks) *  (2^15 - 1); */
  /*      end */
  /* '<S300>:1:386' */
  packed = (v1Ticks << 16) + v2Ticks;
  return packed;
}

/* Function for MATLAB Function: '<S298>/Pack VCodeFrame2' */
static uint32_T gbyk_v4b_toBitField(const boolean_T field[13])
{
  uint32_T bits;
  int32_T i;
  int8_T b_field;

  /* '<S300>:1:317' */
  bits = 0U;

  /* '<S300>:1:318' */
  /* '<S300>:1:320' */
  for (i = 0; i < 13; i++) {
    b_field = (int8_T)field[i];

    /* '<S300>:1:320' */
    /* '<S300>:1:321' */
    bits += (uint32_T)b_field << (uint32_T)i;

    /* '<S300>:1:320' */
  }

  return bits;
}

/* Function for MATLAB Function: '<S298>/Pack VCodeFrame2' */
static void gbyk_v4b_pack_code(const real_T VCODE[70], int32_T packed_code[34],
  real_T *b_index, boolean_T *isPerm, real_T *errID)
{
  uint32_T code_type;
  uint32_T displayWhere;
  int32_T shape;
  int32_T lowerCode;
  boolean_T isMultiCode;
  boolean_T isLabel;
  boolean_T hasFillColor;
  boolean_T hasStroke;
  real_T multiCodeRepeats;
  boolean_T use10mPositionResolution = false;
  boolean_T isFillAnImage;
  boolean_T isStrokeAnImage;
  real_T alpha;
  real_T extraLen;
  real_T intCount;
  int32_T b_strAsInts[13];
  boolean_T x[34];
  int32_T idx;
  int32_T v1Ticks;
  static const int8_T all_types[34] = { 1, 2, 3, 4, 5, 6, 7, 11, 12, 13, 14, 15,
    21, 22, 23, 24, 25, 101, 102, 103, 104, 105, 106, 107, 111, 112, 113, 114,
    115, 121, 122, 123, 124, 125 };

  int32_T i;
  boolean_T displayWhere_0[13];
  int32_T strAsInts_data[169];
  uint32_T y;

  /* packed command format is */
  /*  (1) = bit packed: byte 1 = vcode len in ints, byte 2 = shape, bytes 3,4 = bitfield */
  /*          bitfield bits: */
  /*          1 = show on operator */
  /*          2 = show on subject display */
  /*          3 = multi vcode */
  /*          4 = has label */
  /*          5 = is perminent target */
  /*          6 = has fill color */
  /*          7 = has stroke info */
  /*          8 = has rotation */
  /*          9 = has peak offset */
  /*          10 = use 1m resolotion (0.03mm) or 10m resolution (0.3mm) for positions  */
  /*          11 = use 1m resolotion or 10m resolution for sizes */
  /*          12 = is fill a color (or image) - note - we don't need this */
  /*          for stroke because outlines cannot be images! */
  /*  (2) -Optional. Only present if is multi code or has label. bit packet:  */
  /*          first 16 bits = target ID */
  /*          bottom 16 bits = label len in bytes, or multi-target count (1 per location) */
  /*  (4) - Optional - Fill color (incl opacity) */
  /*  (5) - Optional - Stroke color (incl opacity) */
  /*  (6) - Optional - bit packed Stroke width (1m resolution always) */
  /*  (7) - Bit packed, size 1, size 2 */
  /*  (8) - Optional. Bit packed. Size 3, rotation. */
  /*  (9:N) - Optional - Bit packed . X, Y locations for targets */
  /*  (9:N) - Optional - Characters for label */
  /*  (N + 1) - Optional - Label Color (incl opacity) */
  /*  (N + 2) - Optional, bit packed -  */
  /*           first 16 bits = Label height (1m resolution always) */
  /*           second 16 bits = Reserved for page code identifier for */
  /*           string (ex UTF-16, vs ascii) */
  /* '<S300>:1:164' */
  *errID = 0.0;

  /* '<S300>:1:167' */
  /* '<S300>:1:168' */
  code_type = (uint32_T)rt_roundd_snf(VCODE[0]);

  /* '<S300>:1:170' */
  displayWhere = (uint32_T)rt_roundd_snf(VCODE[1]);

  /* '<S300>:1:171' */
  y = code_type % 10U;
  shape = (int32_T)y;

  /* '<S300>:1:172' */
  y = code_type % 100U;
  lowerCode = (int32_T)y;

  /* '<S300>:1:174' */
  /* '<S300>:1:175' */
  *b_index = 0.0;

  /* '<S300>:1:176' */
  *isPerm = false;

  /* only send valid shape types */
  for (i = 0; i < 34; i++) {
    packed_code[i] = 0;
    x[i] = ((uint32_T)all_types[i] == code_type);
  }

  idx = 0;
  i = 1;
  v1Ticks = 1;
  while ((!use10mPositionResolution) && (v1Ticks < 35)) {
    if (x[v1Ticks - 1]) {
      idx = 1;
      use10mPositionResolution = true;
    } else {
      v1Ticks++;
    }
  }

  if (idx == 0) {
    i = 0;
  }

  if (i == 0) {
    /* '<S300>:1:180' */
    *errID = 2.0;
  } else {
    /* force display on all if the VCode is wrong */
    if ((VCODE[1] < 0.0) || (displayWhere > 3U)) {
      /* '<S300>:1:185' */
      /* '<S300>:1:186' */
      displayWhere = 1U;
    }

    /* '<S300>:1:189' */
    /* '<S300>:1:190' */
    /* '<S300>:1:191' */
    isMultiCode = (((lowerCode > 20) && (lowerCode < 30)) || (shape == 6) ||
                   (shape == 7));

    /* '<S300>:1:192' */
    isLabel = ((lowerCode > 10) && (lowerCode < 20) && (!isMultiCode));
    gbyk_v4b_isPermTarget(VCODE, isPerm, &use10mPositionResolution);

    /* '<S300>:1:193' */
    /* '<S300>:1:194' */
    hasFillColor = (gbyk_v4b_hasColorValue(VCODE[4]) && (shape != 6) && (shape
      != 4));

    /* '<S300>:1:195' */
    hasStroke = (gbyk_v4b_hasColorValue(VCODE[5]) && (VCODE[6] > 0.0));

    /* does the ellipse, rectangle, or triangle have a rotation value? */
    /* '<S300>:1:198' */
    /* '<S300>:1:199' */
    /* '<S300>:1:201' */
    multiCodeRepeats = 0.0;
    use10mPositionResolution = false;
    if (isMultiCode) {
      /* '<S300>:1:202' */
      /* '<S300>:1:203' */
      multiCodeRepeats = rt_roundd_snf(VCODE[15]);

      /* no repeats, nothing to draw... */
      if (!(multiCodeRepeats == 0.0)) {
        if ((multiCodeRepeats < 1.0) || (multiCodeRepeats > 25.0)) {
          /* '<S300>:1:209' */
          /* '<S300>:1:210' */
          *errID = 3.0;
        } else {
          use10mPositionResolution = true;
        }
      } else {
        /* '<S300>:1:206' */
      }
    } else {
      use10mPositionResolution = true;
    }

    if (use10mPositionResolution) {
      /* '<S300>:1:215' */
      use10mPositionResolution = ((VCODE[2] > 1.0) || (VCODE[3] > 1.0) ||
        (VCODE[2] < -1.0) || (VCODE[3] < -1.0));
      if (isMultiCode && (!use10mPositionResolution) && (multiCodeRepeats > 0.0))
      {
        /* '<S300>:1:217' */
        /* '<S300>:1:218' */
        use10mPositionResolution = gbyk_v4b_containsLargerABS1(VCODE,
          multiCodeRepeats * 2.0);
      }

      /* '<S300>:1:221' */
      /* '<S300>:1:223' */
      isFillAnImage = (hasFillColor && (VCODE[4] < 0.0));

      /* '<S300>:1:224' */
      isStrokeAnImage = (hasStroke && (VCODE[5] < 0.0));

      /* '<S300>:1:226' */
      /* '<S300>:1:229' */
      /* put the alpha in a valid range */
      /* '<S300>:1:232' */
      alpha = VCODE[8];
      if (VCODE[8] > 100.0) {
        /* '<S300>:1:233' */
        /* '<S300>:1:234' */
        alpha = 100.0;
      } else {
        if (VCODE[8] < 0.0) {
          /* '<S300>:1:235' */
          /* '<S300>:1:236' */
          alpha = 0.0;
        }
      }

      /* '<S300>:1:239' */
      *b_index = 2.0;

      /* '<S300>:1:240' */
      extraLen = 0.0;

      /* '<S300>:1:241' */
      for (i = 0; i < 13; i++) {
        strAsInts_data[i] = 0;
      }

      /* '<S300>:1:242' */
      intCount = 0.0;
      if (isMultiCode || isLabel || (*isPerm)) {
        /* '<S300>:1:244' */
        /* '<S300>:1:193' */
        if (isLabel) {
          /* '<S300>:1:245' */
          gbyk_v4b_toString(VCODE, b_strAsInts, &intCount, &extraLen);

          /* '<S300>:1:246' */
          for (i = 0; i < 13; i++) {
            strAsInts_data[i] = b_strAsInts[i];
          }

          /* '<S300>:1:246' */
          /* '<S300>:1:247' */
        } else {
          if (isMultiCode) {
            /* '<S300>:1:248' */
            if (shape == 7) {
              /* '<S300>:1:249' */
              /* '<S300>:1:250' */
              extraLen = multiCodeRepeats + 1.0;

              /*  center plus vertexes */
            } else {
              /* '<S300>:1:252' */
              extraLen = multiCodeRepeats;

              /*  global positions only */
            }
          }
        }

        /* '<S300>:1:256' */
        /* '<S300>:1:257' */
        packed_code[1] = (int32_T)(uint32_T)rt_roundd_snf((real_T)((uint32_T)
          rt_roundd_snf(VCODE[7]) << 16U) + extraLen);

        /* '<S300>:1:258' */
        *b_index = 3.0;
      }

      if (hasFillColor) {
        /* '<S300>:1:261' */
        /* '<S300>:1:262' */
        extraLen = VCODE[4];
        if (isFillAnImage) {
          /* '<S300>:1:263' */
          /* '<S300>:1:264' */
          extraLen = -VCODE[4];
        }

        /* '<S300>:1:266' */
        packed_code[(int32_T)*b_index - 1] = gbyk_v4b_packColor(extraLen, alpha);

        /* '<S300>:1:267' */
        (*b_index)++;
      }

      if (hasStroke) {
        /* '<S300>:1:270' */
        /* '<S300>:1:271' */
        extraLen = VCODE[5];
        if (isStrokeAnImage) {
          /* '<S300>:1:272' */
          /* '<S300>:1:273' */
          extraLen = -VCODE[5];
        }

        /* '<S300>:1:275' */
        /* '<S300>:1:407' */
        /* '<S300>:1:408' */
        /* make sure we just have RRGGBB */
        /* '<S300>:1:409' */
        packed_code[(int32_T)*b_index - 1] = ((int32_T)rt_roundd_snf(alpha /
          100.0 * 255.0) << 24) + ((int32_T)rt_roundd_snf(extraLen) & 16777215);

        /* '<S300>:1:276' */
        packed_code[(int32_T)*b_index] = gbyk_v4b_packValues(VCODE[6]);

        /* '<S300>:1:277' */
        *b_index += 2.0;
      }

      /*  function [hasRotation, rotation]=vcodeHasRotation(shape) */
      /*      ELLIPSE = 2; RECTANGLE = 3; TRIANGLE = 5; POLYGON = 7; */
      /*      hasRotation = shape == RECTANGLE || shape == ELLIPSE || shape == TRIANGLE || shape == POLYGON; */
      /*      rotation = 0; */
      /*  end */
      /*  function [hasRotation, rotation]=vcodeHasRotation(VCODE, shape) */
      /*      CIRCLE = 1; ELLIPSE = 2; RECTANGLE = 3; LINE = 4;  TRIANGLE = 5; PATH = 6; POLYGON = 7; */
      /*      rotation_idx = [ELLIPSE, 12; RECTANGLE, 12; TRIANGLE, 13; POLYGON, 10]; */
      /*   */
      /*      hasRotation = false; */
      /*      rotation = 0; */
      /*       */
      /*      for j=1:size(rotation_idx, 1) */
      /*          if rotation_idx(j, 1) == shape */
      /*              rotation = VCODE(rotation_idx(j, 2)); */
      /*              hasRotation = rotation ~= 0; */
      /*              break */
      /*          end */
      /*      end */
      /*  end */
      /* '<S300>:1:502' */
      idx = 0;
      i = 0;

      /* '<S300>:1:503' */
      lowerCode = 1;
      if (shape == 1) {
        /* '<S300>:1:505' */
        /* '<S300>:1:506' */
        idx = gbyk_v4b_packValues_i(VCODE[9], 0.0, false);
      } else if ((shape == 3) || (shape == 2)) {
        /* '<S300>:1:507' */
        /* '<S300>:1:508' */
        idx = gbyk_v4b_packValues_i(VCODE[9], VCODE[10], false);

        /* '<S300>:1:509' */
        extraLen = VCODE[11];

        /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
        /*  For angles we also encode to a 16 bit signed integer. The measure is  */
        /*  -2pi to 2pi. The resolution in this case is 0.01 degrees. The conversion  */
        /*  is just count * resolution. */
        if ((VCODE[11] > 6.2831853071795862) || (VCODE[11] < -6.2831853071795862))
        {
          /* '<S300>:1:394' */
          /* '<S300>:1:395' */
          extraLen = rt_remd_snf(VCODE[11], 6.2831853071795862);
        }

        if (extraLen == 0.0) {
          /* '<S300>:1:398' */
          /* '<S300>:1:399' */
          lowerCode = 0;
        } else {
          /* '<S300>:1:402' */
          lowerCode = (int32_T)rt_roundd_snf(5215.0300202921344 * extraLen);
        }

        i = lowerCode;

        /* '<S300>:1:510' */
        lowerCode = 2;
      } else if (shape == 4) {
        /* '<S300>:1:511' */
        /* '<S300>:1:512' */
        idx = gbyk_v4b_packValues_i(VCODE[9], VCODE[10], false);
      } else if (shape == 5) {
        /* '<S300>:1:513' */
        /* '<S300>:1:514' */
        idx = gbyk_v4b_packValues_i(VCODE[9], VCODE[10], false);

        /* '<S300>:1:515' */
        extraLen = VCODE[12];

        /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
        /*  For angles we also encode to a 16 bit signed integer. The measure is  */
        /*  -2pi to 2pi. The resolution in this case is 0.01 degrees. The conversion  */
        /*  is just count * resolution. */
        if ((VCODE[12] > 6.2831853071795862) || (VCODE[12] < -6.2831853071795862))
        {
          /* '<S300>:1:394' */
          /* '<S300>:1:395' */
          extraLen = rt_remd_snf(VCODE[12], 6.2831853071795862);
        }

        if (extraLen == 0.0) {
          /* '<S300>:1:398' */
          /* '<S300>:1:399' */
          lowerCode = 0;
        } else {
          /* '<S300>:1:402' */
          lowerCode = (int32_T)rt_roundd_snf(5215.0300202921344 * extraLen);
        }

        i = gbyk_v4b_packValues_i(VCODE[11], 0.0, false) + lowerCode;

        /* '<S300>:1:516' */
        lowerCode = 2;
      } else if (shape == 6) {
        /* '<S300>:1:517' */
        /* No arguments to pack */
        /* '<S300>:1:519' */
        lowerCode = 0;
      } else {
        if (shape == 7) {
          /* '<S300>:1:520' */
          /* '<S300>:1:521' */
          extraLen = VCODE[9];

          /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
          /*  For angles we also encode to a 16 bit signed integer. The measure is  */
          /*  -2pi to 2pi. The resolution in this case is 0.01 degrees. The conversion  */
          /*  is just count * resolution. */
          if ((VCODE[9] > 6.2831853071795862) || (VCODE[9] < -6.2831853071795862))
          {
            /* '<S300>:1:394' */
            /* '<S300>:1:395' */
            extraLen = rt_remd_snf(VCODE[9], 6.2831853071795862);
          }

          if (extraLen == 0.0) {
            /* '<S300>:1:398' */
            /* '<S300>:1:399' */
            idx = 0;
          } else {
            /* '<S300>:1:402' */
            idx = (int32_T)rt_roundd_snf(5215.0300202921344 * extraLen);
          }
        }
      }

      /* '<S300>:1:281' */
      packed_code[(int32_T)*b_index - 1] = idx;

      /* '<S300>:1:282' */
      packed_code[(int32_T)*b_index] = i;

      /* '<S300>:1:283' */
      *b_index += (real_T)lowerCode;
      if ((!isMultiCode) || (shape == 7)) {
        /* '<S300>:1:285' */
        /* '<S300>:1:286' */
        packed_code[(int32_T)*b_index - 1] = gbyk_v4b_packValues_i(VCODE[2],
          VCODE[3], use10mPositionResolution);

        /* '<S300>:1:287' */
        (*b_index)++;
      }

      if (isMultiCode) {
        /* '<S300>:1:290' */
        /* '<S300>:1:291' */
        extraLen = 17.0;

        /* '<S300>:1:292' */
        for (lowerCode = 0; lowerCode < (int32_T)multiCodeRepeats; lowerCode++)
        {
          /* '<S300>:1:292' */
          /* '<S300>:1:293' */
          packed_code[(int32_T)*b_index - 1] = gbyk_v4b_packValues_i(VCODE
            [(int32_T)extraLen - 1], VCODE[(int32_T)(extraLen + 1.0) - 1],
            use10mPositionResolution);

          /* '<S300>:1:294' */
          (*b_index)++;

          /* '<S300>:1:295' */
          extraLen += 2.0;

          /* '<S300>:1:292' */
        }
      }

      if (isLabel) {
        /* '<S300>:1:299' */
        if (1.0 > intCount) {
          lowerCode = 0;
        } else {
          lowerCode = (int32_T)intCount;
        }

        extraLen = (*b_index + intCount) + 1.0;
        if (*b_index > extraLen) {
          idx = 0;
        } else {
          idx = (int32_T)*b_index - 1;
        }

        /* '<S300>:1:407' */
        /* '<S300>:1:408' */
        /* make sure we just have RRGGBB */
        /* '<S300>:1:409' */
        /* %%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%% */
        /*  All measurements are encoded into 16 bit signed integers, i.e. -2^15 to 2^15. The encoding assumes that */
        /*  the scale we are trying to measure across is either -1m to 1m or -10m to 10m. For -1m to 1m the accuracy */
        /*  is 0.03mm, for 10m the accuracy is 0.3mm. The conversion is just count * resolution. */
        /* '<S300>:1:366' */
        v1Ticks = (int32_T)rt_roundd_snf(VCODE[65] / 3.0517578125E-5);
        if (v1Ticks > 32767) {
          /* '<S300>:1:370' */
          /* '<S300>:1:371' */
          v1Ticks = 32767;
        } else {
          if (v1Ticks < -32767) {
            /* '<S300>:1:372' */
            /* '<S300>:1:373' */
            v1Ticks = -32767;
          }
        }

        /*      if abs(v2Ticks) > 2^15 - 1 */
        /*          v2Ticks = sign(v2Ticks) *  (2^15 - 1); */
        /*      end */
        /* '<S300>:1:386' */
        /* '<S300>:1:300' */
        for (i = 0; i < lowerCode; i++) {
          packed_code[idx + i] = strAsInts_data[i];
        }

        packed_code[idx + lowerCode] = ((int32_T)rt_roundd_snf(alpha / 100.0 *
          255.0) << 24) + ((int32_T)rt_roundd_snf(VCODE[64]) & 16777215);
        packed_code[(idx + lowerCode) + 1] = v1Ticks << 16;

        /* '<S300>:1:301' */
        *b_index = (*b_index + intCount) + 2.0;
      }

      /* '<S300>:1:304' */
      (*b_index)--;

      /* '<S300>:1:305' */
      displayWhere_0[0] = (((int32_T)displayWhere == 1) || ((int32_T)
        displayWhere == 3));
      displayWhere_0[1] = (((int32_T)displayWhere == 1) || ((int32_T)
        displayWhere == 2));
      displayWhere_0[2] = isMultiCode;
      displayWhere_0[3] = isLabel;
      displayWhere_0[4] = *isPerm;
      displayWhere_0[5] = hasFillColor;
      displayWhere_0[6] = hasStroke;
      displayWhere_0[7] = ((shape == 3) || (shape == 2) || (shape == 5) ||
                           (shape == 7));
      displayWhere_0[8] = (shape == 5);
      displayWhere_0[9] = use10mPositionResolution;
      displayWhere_0[10] = false;
      displayWhere_0[11] = isFillAnImage;
      displayWhere_0[12] = isStrokeAnImage;
      packed_code[0] = (int32_T)((((uint32_T)rt_roundd_snf(*b_index) << 24U) +
        ((uint32_T)shape << 16U)) + gbyk_v4b_toBitField(displayWhere_0));

      /* '<S300>:1:309' */
    }
  }
}

/* Initial conditions for atomic system: '<S15>/PVC_core' */
void gbyk_v4b_PVC_core_Init(void)
{
  /* InitializeConditions for MATLAB Function: '<S298>/Pack VCodeFrame2' */
  gbyk_v4b_DW.frame_count = 0U;

  /* InitializeConditions for RateTransition: '<S298>/Rate Transition1' */
  gbyk_v4b_DW.RateTransition1_Buffer0 = gbyk_v4b_P.RateTransition1_X0;
}

/* Start for atomic system: '<S15>/PVC_core' */
void gbyk_v4b_PVC_core_Start(void)
{
  /* Start for RateTransition: '<S298>/Rate Transition1' */
  gbyk_v4b_B.RateTransition1_h = gbyk_v4b_P.RateTransition1_X0;
}

/* Outputs for atomic system: '<S15>/PVC_core' */
void gbyk_v4b_PVC_coreTID0(void)
{
  /* RateTransition: '<S298>/Rate Transition1' */
  if (gbyk_v4b_M->Timing.RateInteraction.TID1_4) {
    gbyk_v4b_B.RateTransition1_h = gbyk_v4b_DW.RateTransition1_Buffer0;
  }

  /* End of RateTransition: '<S298>/Rate Transition1' */
}

/* Outputs for atomic system: '<S15>/PVC_core' */
void gbyk_v4b_PVC_coreTID4(void)
{
  int32_T vis_cmd_cropped;
  uint32_T frame_number;
  real_T vcode_err_id;
  real_T b_index;
  int32_T added_code_counter;
  boolean_T containsPerm;
  real_T m;
  int32_T packed[34];
  real_T codelen;
  int32_T i;
  int32_T output_int32;
  boolean_T b_isPerm;
  boolean_T isValidID;
  boolean_T b;
  boolean_T exitg1;

  /* MATLAB Function: '<S298>/Pack VCodeFrame2' */
  /* MATLAB Function 'Process_Video_CMD/PVC_core/Pack VCodeFrame2': '<S300>:1' */
  /*  vcode_err_id */
  /*  1 = invalid perm target ID */
  /*  2 = invalid shape type */
  /*  3 = invalid multi-target location count (polygon, path, multi-target) */
  /*  4 = too many targets */
  /*  Increment a counter on each execution, which corresponds to one increment per packet. This counter is used  */
  /*  as a tracking number / "timestamp". Video command acknowledgements refer to this counter. */
  /* A fullsize UDP packet is 64k. We want a bit less than that to account */
  /* for header info. */
  /*     max_vis_cmd_length = floor((65536 / 4) * 0.9); */
  /* '<S300>:1:24' */
  gbyk_v4b_DW.frame_count++;

  /* '<S300>:1:25' */
  frame_number = gbyk_v4b_DW.frame_count;

  /* '<S300>:1:26' */
  vcode_err_id = 0.0;

  /*  vis_cmd must be a fixed length, so it is initialized to the maximum possible length required. */
  /*   (number of VCODEs * max_single_vis_cmd_length) + 3 int32 for message header, frame count, and "end-of-command" marker */
  /*  */
  /*  Note: max_single_vis_cmd_length refers to the maximum possible length of a single target (i.e. the number of int32 elements  */
  /*  required to define it) within the vis_cmd vector. Currently a triangle with a label is potentially the longest, with */
  /*  the following elements (each an int32): */
  /*    1: target type + target on/off status  */
  /*    2: x position */
  /*    3: y position */
  /*    4: fill colour */
  /*    5: stroke colour */
  /*    6: stroke width */
  /*    7: opacity */
  /*    8: base width */
  /*    9: height */
  /*   10: peak offset */
  /*   11: rotation */
  /*   12-24:  maximum length label (up to 50 characters, 4 1-byte characters per int32, with one byte for a null terminator) */
  /*   25: label colour */
  /*   26: label height */
  /*   27: target id when in background */
  /* '<S300>:1:50' */
  memset(&gbyk_v4b_B.vis_cmd[0], 0, 6810U * sizeof(int32_T));

  /* '<S300>:1:51' */
  vis_cmd_cropped = 0;

  /*  Create a 4-byte message header. */
  /*    byte 1: version */
  /*      37 = Version 3.7 */
  /*    byte 2: bit field. (are there any permanent targets?) */
  /*    bytes 3-4: count of VCodes in the packet */
  /* '<S300>:1:60' */
  /*  The typecast function is not yet available for Embedded Matlab. This function implements a cast from uint32 to int32. */
  /* '<S300>:1:123' */
  /*  The typecast function is not yet available for Embedded Matlab. This function implements a cast from uint32 to int32. */
  if (gbyk_v4b_DW.frame_count > 2147483648U) {
    /* '<S300>:1:119' */
    /* '<S300>:1:120' */
    /*  remove MSB and cast to int32 */
    /* '<S300>:1:121' */
    output_int32 = (int32_T)(uint32_T)rt_roundd_snf((real_T)
      gbyk_v4b_DW.frame_count - 2.147483648E+9) + MIN_int32_T;

    /*  subtract 2^31 (because 2^31 is not int32, subtract 2^30 twice) */
  } else {
    /* '<S300>:1:123' */
    output_int32 = (int32_T)gbyk_v4b_DW.frame_count;
  }

  gbyk_v4b_B.vis_cmd[0] = 620756992;
  gbyk_v4b_B.vis_cmd[1] = output_int32;

  /* '<S300>:1:61' */
  b_index = 3.0;

  /* '<S300>:1:68' */
  added_code_counter = 0;

  /* '<S300>:1:69' */
  containsPerm = false;

  /* '<S300>:1:71' */
  i = 0;
  exitg1 = false;
  while ((!exitg1) && (i < 19)) {
    /* '<S300>:1:71' */
    /* don't transmit invalid perm targets */
    /* '<S300>:1:440' */
    /* '<S300>:1:441' */
    /* 15360 as an ID means 'clear all perm targets' */
    /* '<S300>:1:443' */
    b_isPerm = ((gbyk_v4b_B.MatrixConcatenate[70 * i] > 100.0) &&
                (gbyk_v4b_B.MatrixConcatenate[70 * i] < 130.0));

    /* '<S300>:1:444' */
    isValidID = (((gbyk_v4b_B.MatrixConcatenate[70 * i + 7] > 0.0) &&
                  (gbyk_v4b_B.MatrixConcatenate[70 * i + 7] < 500.0)) ||
                 (gbyk_v4b_B.MatrixConcatenate[70 * i + 7] == 15360.0));

    /* we need to transmit anything that is supposed to be displayed or any */
    /* permanent target. Permanents are always transmitted because turning */
    /* them off is valid! */
    /* '<S300>:1:454' */
    if (b_isPerm && (!isValidID)) {
      /* '<S300>:1:449' */
      /* '<S300>:1:455' */
      b = true;
    } else {
      /* '<S300>:1:455' */
      b = false;
    }

    /* '<S300>:1:455' */
    b = ((!b) && (((gbyk_v4b_B.MatrixConcatenate[70 * i] > 0.0) &&
                   (gbyk_v4b_B.MatrixConcatenate[70 * i + 1] != 0.0)) ||
                  b_isPerm));

    /* '<S300>:1:457' */
    output_int32 = 0;
    if ((!b) && b_isPerm && (!isValidID)) {
      /* '<S300>:1:458' */
      /* '<S300>:1:449' */
      /* '<S300>:1:459' */
      /* '<S300>:1:460' */
      output_int32 = 1;
    }

    /*      %don't transmit invalid perm targets */
    /*      [isPerm, isValidID] = isPermTarget(VCODE); */
    /*      if isPerm && ~isValidID */
    /*          transmit= false; */
    /*          return */
    /*      end */
    /*       */
    /*      %we need to transmit anything that is supposed to be displayed or any */
    /*      %permanent target. Permanents are always transmitted because turning */
    /*      %them off is valid! */
    /*      displayWhere = VCODE(2); */
    /*      transmit = (VCODE(1) > 0 & displayWhere ~= 0) | isPerm; */
    b_isPerm = false;
    if (!b) {
      /* '<S300>:1:74' */
      if (output_int32 != 0) {
        /* '<S300>:1:75' */
        /* '<S300>:1:76' */
        vcode_err_id = 1.0;
      }

      b_isPerm = true;
    } else {
      gbyk_v4b_pack_code(*(real_T (*)[70])&gbyk_v4b_B.MatrixConcatenate[70 * i],
                         packed, &codelen, &b, &m);
      if (codelen == 0.0) {
        /* '<S300>:1:82' */
        if (m != 0.0) {
          /* '<S300>:1:83' */
          /* '<S300>:1:84' */
          vcode_err_id = m;
        }

        b_isPerm = true;
      } else {
        /* '<S300>:1:89' */
        containsPerm = (containsPerm || b);

        /*  This is mildly faster when output to C than: vis_cmd(index: index + codelen - 1) = packed(1:codelen) */
        /* '<S300>:1:91' */
        m = b_index;

        /* '<S300>:1:92' */
        for (output_int32 = 0; output_int32 < (int32_T)codelen; output_int32++)
        {
          /* '<S300>:1:92' */
          /* '<S300>:1:93' */
          gbyk_v4b_B.vis_cmd[(int32_T)m - 1] = packed[output_int32];

          /* '<S300>:1:94' */
          m++;

          /* '<S300>:1:92' */
        }

        /* '<S300>:1:97' */
        b_index += codelen;

        /* '<S300>:1:98' */
        added_code_counter++;

        /*  if the current index < max_vis_cmd_length, then the VCODEs just added will fit in the vis_cmd_out  */
        if ((b_index + 34.0) + 1.0 >= 6810.0) {
          /* '<S300>:1:101' */
          /* '<S300>:1:102' */
          vis_cmd_cropped = 1;

          /* '<S300>:1:103' */
          vcode_err_id = 4.0;
          exitg1 = true;
        } else {
          b_isPerm = true;
        }
      }
    }

    if (b_isPerm) {
      /* '<S300>:1:71' */
      i++;
    }
  }

  /* '<S300>:1:109' */
  /* '<S300>:1:318' */
  /* '<S300>:1:321' */
  /* '<S300>:1:111' */
  gbyk_v4b_B.vis_cmd[0] = ((int32_T)((uint32_T)containsPerm << 16U) +
    gbyk_v4b_B.vis_cmd[0]) + added_code_counter;

  /*  Set the "end-of-command" marker: 0xFFFF0000 instead of a target type indicates end of target commands within the vis_cmd vector. */
  /* '<S300>:1:113' */
  /*  The typecast function is not yet available for Embedded Matlab. This function implements a cast from uint32 to int32. */
  /* '<S300>:1:119' */
  /* '<S300>:1:120' */
  /*  remove MSB and cast to int32 */
  /* '<S300>:1:121' */
  /*  subtract 2^31 (because 2^31 is not int32, subtract 2^30 twice) */
  gbyk_v4b_B.vis_cmd[(int32_T)b_index - 1] = -65536;

  /* '<S300>:1:114' */
  gbyk_v4b_B.vis_cmd_len = (b_index + 1.0) * 4.0;
  gbyk_v4b_B.vis_cmd_cropped = vis_cmd_cropped;
  gbyk_v4b_B.frame_number = frame_number;
  gbyk_v4b_B.vcode_err_id = vcode_err_id;

  /* End of MATLAB Function: '<S298>/Pack VCodeFrame2' */

  /* DataTypeConversion: '<S298>/Convert' */
  gbyk_v4b_B.Convert_n = gbyk_v4b_B.frame_number;
}

/* Update for atomic system: '<S15>/PVC_core' */
void gbyk_v4b_PVC_core_UpdateTID4(void)
{
  /* Update for RateTransition: '<S298>/Rate Transition1' */
  gbyk_v4b_DW.RateTransition1_Buffer0 = gbyk_v4b_B.Convert_n;
}
