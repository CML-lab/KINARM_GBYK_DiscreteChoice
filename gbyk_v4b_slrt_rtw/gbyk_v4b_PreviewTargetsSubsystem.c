/*
 * Code generation for system system '<S7>/Preview Targets Subsystem'
 *
 * Model                      : gbyk_v4b
 * Model version              : 1.2667
 * Simulink Coder version : 8.8.1 (R2015aSP1) 04-Sep-2015
 * C source code generated on : Tue Sep 15 15:02:19 2020
 *
 * Note that the functions contained in this file are part of a Simulink
 * model, and are not self-contained algorithms.
 */

#include "gbyk_v4b_PreviewTargetsSubsystem.h"

/* Include model header file for global data */
#include "gbyk_v4b.h"
#include "gbyk_v4b_private.h"

/* Output and update for atomic system: '<S7>/Preview Targets Subsystem' */
void gbyk_v4b_PreviewTargetsSubsystem(void)
{
  int32_T num_attributes;
  int32_T target_entry_size;
  int32_T start_index;
  int32_T attrib_start;
  int32_T i;

  /* Reshape: '<S267>/Reshape1' incorporates:
   *  Constant: '<S267>/V_cols'
   */
  gbyk_v4b_B.Concatenation1[0] = gbyk_v4b_P.GUIControl_Vcols;

  /* Reshape: '<S267>/Reshape' incorporates:
   *  Constant: '<S267>/L_cols'
   */
  gbyk_v4b_B.Concatenation1[1] = gbyk_v4b_P.GUIControl_Lcols;

  /* Constant: '<S267>/indices_padding' */
  memcpy(&gbyk_v4b_B.Concatenation1[2], &gbyk_v4b_P.indices_padding_Value[0],
         sizeof(real_T) << 3U);

  /* MATLAB Function: '<S267>/Create Target Vector' incorporates:
   *  Constant: '<S267>/Target_Type'
   *  Constant: '<S267>/XY_cols'
   */
  /* MATLAB Function 'GUI Control/Preview Targets Subsystem/Create Target Vector': '<S272>:1' */
  /*  Assemble the target vector for reading by the GUI. The vector consists of n entries back-to-back, */
  /*  where n is the number of rows in the target table, and each entry consists of */
  /*  */
  /*    target type, x position, y position, visual attribute values, logical attribute values */
  /*  */
  /*  for a target, where all values are taken out of the target table and processed so that they are ready */
  /*  to be used by the GUI. This is kind of a compressed version of the process of creating a target using */
  /*  Show_Target block -> VCODE -> Process_Video_CMD block. */
  /*  */
  /*  The visual and logical attributes are the target type-specific information corresponding to the visual */
  /*  and logical versions of that target. Distances and rotations are converted from cm and degrees, as they */
  /*  are specified in the GUI, to um and and urads. For more information on how these are defined for each  */
  /*  target type, refer to the mask help for this block or for the Show_Target block. */
  /*  Note the number of attribute columns based on the target type. */
  /* '<S272>:1:18' */
  num_attributes = 1;
  if (!(gbyk_v4b_P.Target_Type_Value == 1.0)) {
    if ((gbyk_v4b_P.Target_Type_Value == 2.0) || (gbyk_v4b_P.Target_Type_Value ==
         3.0) || (gbyk_v4b_P.Target_Type_Value == 4.0)) {
      /* '<S272>:1:22' */
      /* '<S272>:1:23' */
      num_attributes = 3;
    } else {
      if (gbyk_v4b_P.Target_Type_Value == 5.0) {
        /* '<S272>:1:24' */
        /* '<S272>:1:25' */
        num_attributes = 4;
      }
    }
  } else {
    /* '<S272>:1:20' */
    /* '<S272>:1:21' */
  }

  /* '<S272>:1:28' */
  target_entry_size = (num_attributes << 1) + 3;

  /*  size of type, x,y position, and all attributes */
  /*  Set the vector length to the maximum that might be required, as it has to be constant at build time. */
  /* '<S272>:1:32' */
  gbyk_v4b_B.target_vector_length = 352.0;

  /* '<S272>:1:33' */
  for (i = 0; i < 352; i++) {
    gbyk_v4b_B.target_vector[i] = 0.0;
  }

  /*  For each target, set... */
  /* '<S272>:1:38' */
  for (i = 0; i < 32; i++) {
    /* '<S272>:1:38' */
    /* '<S272>:1:39' */
    start_index = i * target_entry_size;

    /* '<S272>:1:41' */
    gbyk_v4b_B.target_vector[start_index] = gbyk_v4b_P.Target_Type_Value;

    /*  target type */
    /* '<S272>:1:43' */
    gbyk_v4b_B.target_vector[start_index + 1] = gbyk_v4b_B.TargetTable
      [(((int32_T)gbyk_v4b_P.GUIControl_XYcols[0] - 1) << 5) + i] * 0.01;

    /*  x position (m) */
    /* '<S272>:1:44' */
    gbyk_v4b_B.target_vector[start_index + 2] = gbyk_v4b_B.TargetTable
      [(((int32_T)gbyk_v4b_P.GUIControl_XYcols[1] - 1) << 5) + i] * 0.01;

    /*  y position (m) */
    /*  For each vector of visual and logical column indices... */
    /* '<S272>:1:47' */
    /* '<S272>:1:48' */
    attrib_start = start_index + 5;

    /*  Copy circle attributes: radius (m). */
    if (gbyk_v4b_P.Target_Type_Value == 1.0) {
      /* '<S272>:1:51' */
      /* '<S272>:1:52' */
      gbyk_v4b_B.target_vector[attrib_start - 2] = gbyk_v4b_B.TargetTable
        [(((int32_T)gbyk_v4b_B.Concatenation1[0] - 1) << 5) + i] * 0.01;

      /*  Copy ellipse attributes: major radius (m), minor radius (m), rotation (degrees). */
    } else if (gbyk_v4b_P.Target_Type_Value == 2.0) {
      /* '<S272>:1:55' */
      if ((gbyk_v4b_B.Concatenation1[0] == 0.0) || (gbyk_v4b_B.Concatenation1[2]
           == 0.0)) {
        /* '<S272>:1:56' */
        /* '<S272>:1:57' */
        gbyk_v4b_B.target_vector[attrib_start - 2] = 0.0;

        /* '<S272>:1:58' */
        gbyk_v4b_B.target_vector[attrib_start - 1] = 0.0;
      } else {
        /* '<S272>:1:60' */
        gbyk_v4b_B.target_vector[attrib_start - 2] = gbyk_v4b_B.TargetTable
          [(((int32_T)gbyk_v4b_B.Concatenation1[0] - 1) << 5) + i] * 0.01;

        /* '<S272>:1:61' */
        gbyk_v4b_B.target_vector[attrib_start - 1] = gbyk_v4b_B.TargetTable
          [(((int32_T)gbyk_v4b_B.Concatenation1[2] - 1) << 5) + i] * 0.01;
      }

      if (gbyk_v4b_B.Concatenation1[4] == 0.0) {
        /* '<S272>:1:64' */
        /* '<S272>:1:65' */
        gbyk_v4b_B.target_vector[attrib_start] = 0.0;
      } else {
        /* '<S272>:1:67' */
        gbyk_v4b_B.target_vector[attrib_start] = (gbyk_v4b_B.TargetTable
          [(((int32_T)gbyk_v4b_B.Concatenation1[4] - 1) << 5) + i] - floor
          (gbyk_v4b_B.TargetTable[(((int32_T)gbyk_v4b_B.Concatenation1[4] - 1) <<
          5) + i] / 360.0) * 360.0) * 3.1415926535897931 / 180.0;
      }

      /*  Copy rectangle attributes: length (m), height (m), rotation (degrees). */
      /*  This amounts to the same procedure as for an ellipse. */
    } else if (gbyk_v4b_P.Target_Type_Value == 3.0) {
      /* '<S272>:1:72' */
      if ((gbyk_v4b_B.Concatenation1[0] == 0.0) || (gbyk_v4b_B.Concatenation1[2]
           == 0.0)) {
        /* '<S272>:1:73' */
        /* '<S272>:1:74' */
        gbyk_v4b_B.target_vector[attrib_start - 2] = 0.0;

        /* '<S272>:1:75' */
        gbyk_v4b_B.target_vector[attrib_start - 1] = 0.0;
      } else {
        /* '<S272>:1:77' */
        gbyk_v4b_B.target_vector[attrib_start - 2] = gbyk_v4b_B.TargetTable
          [(((int32_T)gbyk_v4b_B.Concatenation1[0] - 1) << 5) + i] * 0.01;

        /* '<S272>:1:78' */
        gbyk_v4b_B.target_vector[attrib_start - 1] = gbyk_v4b_B.TargetTable
          [(((int32_T)gbyk_v4b_B.Concatenation1[2] - 1) << 5) + i] * 0.01;
      }

      if (gbyk_v4b_B.Concatenation1[4] == 0.0) {
        /* '<S272>:1:81' */
        /* '<S272>:1:82' */
        gbyk_v4b_B.target_vector[attrib_start] = 0.0;
      } else {
        /* '<S272>:1:84' */
        gbyk_v4b_B.target_vector[attrib_start] = (gbyk_v4b_B.TargetTable
          [(((int32_T)gbyk_v4b_B.Concatenation1[4] - 1) << 5) + i] - floor
          (gbyk_v4b_B.TargetTable[(((int32_T)gbyk_v4b_B.Concatenation1[4] - 1) <<
          5) + i] / 360.0) * 360.0) * 3.1415926535897931 / 180.0;
      }

      /*  Copy line attributes: relative endpoint x coordinate (m), relative endpoint y coordinate (m), width */
    } else if (gbyk_v4b_P.Target_Type_Value == 4.0) {
      /* '<S272>:1:88' */
      if (((gbyk_v4b_B.Concatenation1[0] == 0.0) && (gbyk_v4b_B.Concatenation1[2]
            == 0.0)) || (gbyk_v4b_B.Concatenation1[4] == 0.0)) {
        /* '<S272>:1:89' */
        /* '<S272>:1:90' */
        gbyk_v4b_B.target_vector[attrib_start - 2] = 0.0;

        /* '<S272>:1:91' */
        gbyk_v4b_B.target_vector[attrib_start - 1] = 0.0;

        /* '<S272>:1:92' */
        gbyk_v4b_B.target_vector[attrib_start] = 0.0;
      } else {
        /* '<S272>:1:94' */
        gbyk_v4b_B.target_vector[attrib_start - 2] = gbyk_v4b_B.TargetTable
          [(((int32_T)gbyk_v4b_B.Concatenation1[0] - 1) << 5) + i] * 0.01;

        /* '<S272>:1:95' */
        gbyk_v4b_B.target_vector[attrib_start - 1] = gbyk_v4b_B.TargetTable
          [(((int32_T)gbyk_v4b_B.Concatenation1[2] - 1) << 5) + i] * 0.01;
        if (gbyk_v4b_B.Concatenation1[4] < 0.0) {
          /* '<S272>:1:97' */
          /* '<S272>:1:98' */
          gbyk_v4b_B.target_vector[attrib_start] = 0.001;
        } else {
          /* '<S272>:1:100' */
          gbyk_v4b_B.target_vector[attrib_start] = gbyk_v4b_B.TargetTable
            [(((int32_T)gbyk_v4b_B.Concatenation1[4] - 1) << 5) + i] * 0.01;
        }
      }

      /*  Copy triangle attributes: length (m), height (m), peak offset (m), rotation (degrees). */
    } else {
      if (gbyk_v4b_P.Target_Type_Value == 5.0) {
        /* '<S272>:1:105' */
        if (gbyk_v4b_B.Concatenation1[0] == 0.0) {
          /* '<S272>:1:106' */
          /* '<S272>:1:107' */
          gbyk_v4b_B.target_vector[attrib_start - 2] = 0.0;
        } else {
          /* '<S272>:1:109' */
          gbyk_v4b_B.target_vector[attrib_start - 2] = gbyk_v4b_B.TargetTable
            [(((int32_T)gbyk_v4b_B.Concatenation1[0] - 1) << 5) + i] * 0.01;
        }

        if (gbyk_v4b_B.Concatenation1[2] == 0.0) {
          /* '<S272>:1:112' */
          /*  create an equilateral triangle if no height column is specified */
          /* '<S272>:1:113' */
          gbyk_v4b_B.target_vector[attrib_start - 1] = gbyk_v4b_B.TargetTable
            [(((int32_T)gbyk_v4b_B.Concatenation1[0] - 1) << 5) + i] *
            0.8660254037844386 * 0.01;

          /* '<S272>:1:114' */
          gbyk_v4b_B.target_vector[attrib_start] = 0.0;
        } else {
          /* '<S272>:1:116' */
          gbyk_v4b_B.target_vector[attrib_start - 1] = gbyk_v4b_B.TargetTable
            [(((int32_T)gbyk_v4b_B.Concatenation1[2] - 1) << 5) + i] * 0.01;

          /* '<S272>:1:117' */
          gbyk_v4b_B.target_vector[attrib_start] = gbyk_v4b_B.TargetTable
            [(((int32_T)gbyk_v4b_B.Concatenation1[4] - 1) << 5) + i] * 0.01;
        }

        if (gbyk_v4b_B.Concatenation1[6] == 0.0) {
          /* '<S272>:1:120' */
          /* '<S272>:1:121' */
          gbyk_v4b_B.target_vector[attrib_start + 1] = 0.0;
        } else {
          /* '<S272>:1:123' */
          gbyk_v4b_B.target_vector[attrib_start + 1] = (gbyk_v4b_B.TargetTable
            [(((int32_T)gbyk_v4b_B.Concatenation1[6] - 1) << 5) + i] - floor
            (gbyk_v4b_B.TargetTable[(((int32_T)gbyk_v4b_B.Concatenation1[6] - 1)
            << 5) + i] / 360.0) * 360.0) * 3.1415926535897931 / 180.0;
        }
      }
    }

    /* '<S272>:1:47' */
    /* '<S272>:1:48' */
    attrib_start = (start_index + num_attributes) + 5;

    /*  Copy circle attributes: radius (m). */
    if (gbyk_v4b_P.Target_Type_Value == 1.0) {
      /* '<S272>:1:51' */
      /* '<S272>:1:52' */
      gbyk_v4b_B.target_vector[attrib_start - 2] = gbyk_v4b_B.TargetTable
        [(((int32_T)gbyk_v4b_B.Concatenation1[1] - 1) << 5) + i] * 0.01;

      /*  Copy ellipse attributes: major radius (m), minor radius (m), rotation (degrees). */
    } else if (gbyk_v4b_P.Target_Type_Value == 2.0) {
      /* '<S272>:1:55' */
      if ((gbyk_v4b_B.Concatenation1[1] == 0.0) || (gbyk_v4b_B.Concatenation1[3]
           == 0.0)) {
        /* '<S272>:1:56' */
        /* '<S272>:1:57' */
        gbyk_v4b_B.target_vector[attrib_start - 2] = 0.0;

        /* '<S272>:1:58' */
        gbyk_v4b_B.target_vector[attrib_start - 1] = 0.0;
      } else {
        /* '<S272>:1:60' */
        gbyk_v4b_B.target_vector[attrib_start - 2] = gbyk_v4b_B.TargetTable
          [(((int32_T)gbyk_v4b_B.Concatenation1[1] - 1) << 5) + i] * 0.01;

        /* '<S272>:1:61' */
        gbyk_v4b_B.target_vector[attrib_start - 1] = gbyk_v4b_B.TargetTable
          [(((int32_T)gbyk_v4b_B.Concatenation1[3] - 1) << 5) + i] * 0.01;
      }

      if (gbyk_v4b_B.Concatenation1[5] == 0.0) {
        /* '<S272>:1:64' */
        /* '<S272>:1:65' */
        gbyk_v4b_B.target_vector[attrib_start] = 0.0;
      } else {
        /* '<S272>:1:67' */
        gbyk_v4b_B.target_vector[attrib_start] = (gbyk_v4b_B.TargetTable
          [(((int32_T)gbyk_v4b_B.Concatenation1[5] - 1) << 5) + i] - floor
          (gbyk_v4b_B.TargetTable[(((int32_T)gbyk_v4b_B.Concatenation1[5] - 1) <<
          5) + i] / 360.0) * 360.0) * 3.1415926535897931 / 180.0;
      }

      /*  Copy rectangle attributes: length (m), height (m), rotation (degrees). */
      /*  This amounts to the same procedure as for an ellipse. */
    } else if (gbyk_v4b_P.Target_Type_Value == 3.0) {
      /* '<S272>:1:72' */
      if ((gbyk_v4b_B.Concatenation1[1] == 0.0) || (gbyk_v4b_B.Concatenation1[3]
           == 0.0)) {
        /* '<S272>:1:73' */
        /* '<S272>:1:74' */
        gbyk_v4b_B.target_vector[attrib_start - 2] = 0.0;

        /* '<S272>:1:75' */
        gbyk_v4b_B.target_vector[attrib_start - 1] = 0.0;
      } else {
        /* '<S272>:1:77' */
        gbyk_v4b_B.target_vector[attrib_start - 2] = gbyk_v4b_B.TargetTable
          [(((int32_T)gbyk_v4b_B.Concatenation1[1] - 1) << 5) + i] * 0.01;

        /* '<S272>:1:78' */
        gbyk_v4b_B.target_vector[attrib_start - 1] = gbyk_v4b_B.TargetTable
          [(((int32_T)gbyk_v4b_B.Concatenation1[3] - 1) << 5) + i] * 0.01;
      }

      if (gbyk_v4b_B.Concatenation1[5] == 0.0) {
        /* '<S272>:1:81' */
        /* '<S272>:1:82' */
        gbyk_v4b_B.target_vector[attrib_start] = 0.0;
      } else {
        /* '<S272>:1:84' */
        gbyk_v4b_B.target_vector[attrib_start] = (gbyk_v4b_B.TargetTable
          [(((int32_T)gbyk_v4b_B.Concatenation1[5] - 1) << 5) + i] - floor
          (gbyk_v4b_B.TargetTable[(((int32_T)gbyk_v4b_B.Concatenation1[5] - 1) <<
          5) + i] / 360.0) * 360.0) * 3.1415926535897931 / 180.0;
      }

      /*  Copy line attributes: relative endpoint x coordinate (m), relative endpoint y coordinate (m), width */
    } else if (gbyk_v4b_P.Target_Type_Value == 4.0) {
      /* '<S272>:1:88' */
      if (((gbyk_v4b_B.Concatenation1[1] == 0.0) && (gbyk_v4b_B.Concatenation1[3]
            == 0.0)) || (gbyk_v4b_B.Concatenation1[5] == 0.0)) {
        /* '<S272>:1:89' */
        /* '<S272>:1:90' */
        gbyk_v4b_B.target_vector[attrib_start - 2] = 0.0;

        /* '<S272>:1:91' */
        gbyk_v4b_B.target_vector[attrib_start - 1] = 0.0;

        /* '<S272>:1:92' */
        gbyk_v4b_B.target_vector[attrib_start] = 0.0;
      } else {
        /* '<S272>:1:94' */
        gbyk_v4b_B.target_vector[attrib_start - 2] = gbyk_v4b_B.TargetTable
          [(((int32_T)gbyk_v4b_B.Concatenation1[1] - 1) << 5) + i] * 0.01;

        /* '<S272>:1:95' */
        gbyk_v4b_B.target_vector[attrib_start - 1] = gbyk_v4b_B.TargetTable
          [(((int32_T)gbyk_v4b_B.Concatenation1[3] - 1) << 5) + i] * 0.01;
        if (gbyk_v4b_B.Concatenation1[5] < 0.0) {
          /* '<S272>:1:97' */
          /* '<S272>:1:98' */
          gbyk_v4b_B.target_vector[attrib_start] = 0.001;
        } else {
          /* '<S272>:1:100' */
          gbyk_v4b_B.target_vector[attrib_start] = gbyk_v4b_B.TargetTable
            [(((int32_T)gbyk_v4b_B.Concatenation1[5] - 1) << 5) + i] * 0.01;
        }
      }

      /*  Copy triangle attributes: length (m), height (m), peak offset (m), rotation (degrees). */
    } else {
      if (gbyk_v4b_P.Target_Type_Value == 5.0) {
        /* '<S272>:1:105' */
        if (gbyk_v4b_B.Concatenation1[1] == 0.0) {
          /* '<S272>:1:106' */
          /* '<S272>:1:107' */
          gbyk_v4b_B.target_vector[attrib_start - 2] = 0.0;
        } else {
          /* '<S272>:1:109' */
          gbyk_v4b_B.target_vector[attrib_start - 2] = gbyk_v4b_B.TargetTable
            [(((int32_T)gbyk_v4b_B.Concatenation1[1] - 1) << 5) + i] * 0.01;
        }

        if (gbyk_v4b_B.Concatenation1[3] == 0.0) {
          /* '<S272>:1:112' */
          /*  create an equilateral triangle if no height column is specified */
          /* '<S272>:1:113' */
          gbyk_v4b_B.target_vector[attrib_start - 1] = gbyk_v4b_B.TargetTable
            [(((int32_T)gbyk_v4b_B.Concatenation1[1] - 1) << 5) + i] *
            0.8660254037844386 * 0.01;

          /* '<S272>:1:114' */
          gbyk_v4b_B.target_vector[attrib_start] = 0.0;
        } else {
          /* '<S272>:1:116' */
          gbyk_v4b_B.target_vector[attrib_start - 1] = gbyk_v4b_B.TargetTable
            [(((int32_T)gbyk_v4b_B.Concatenation1[3] - 1) << 5) + i] * 0.01;

          /* '<S272>:1:117' */
          gbyk_v4b_B.target_vector[attrib_start] = gbyk_v4b_B.TargetTable
            [(((int32_T)gbyk_v4b_B.Concatenation1[5] - 1) << 5) + i] * 0.01;
        }

        if (gbyk_v4b_B.Concatenation1[7] == 0.0) {
          /* '<S272>:1:120' */
          /* '<S272>:1:121' */
          gbyk_v4b_B.target_vector[attrib_start + 1] = 0.0;
        } else {
          /* '<S272>:1:123' */
          gbyk_v4b_B.target_vector[attrib_start + 1] = (gbyk_v4b_B.TargetTable
            [(((int32_T)gbyk_v4b_B.Concatenation1[7] - 1) << 5) + i] - floor
            (gbyk_v4b_B.TargetTable[(((int32_T)gbyk_v4b_B.Concatenation1[7] - 1)
            << 5) + i] / 360.0) * 360.0) * 3.1415926535897931 / 180.0;
        }
      }
    }

    /* '<S272>:1:47' */
    /* '<S272>:1:38' */
  }

  /* End of MATLAB Function: '<S267>/Create Target Vector' */
}
