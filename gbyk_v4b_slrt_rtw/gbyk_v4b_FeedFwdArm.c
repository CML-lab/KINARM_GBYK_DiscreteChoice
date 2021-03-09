/*
 * Code generation for system system '<S8>/FeedFwdArm'
 *
 * Model                      : gbyk_v4b
 * Model version              : 1.2667
 * Simulink Coder version : 8.8.1 (R2015aSP1) 04-Sep-2015
 * C source code generated on : Tue Sep 15 15:02:19 2020
 *
 * Note that the functions contained in this file are part of a Simulink
 * model, and are not self-contained algorithms.
 */

#include "gbyk_v4b_FeedFwdArm.h"

/* Include model header file for global data */
#include "gbyk_v4b.h"
#include "gbyk_v4b_private.h"

/* Output and update for atomic system: '<S8>/FeedFwdArm' */
void gbyk_v4b_FeedFwdArm(void)
{
  real_T feedfwd;
  real_T feedback_status;
  int32_T i;

  /* MATLAB Function 'Hand_Feedback/FeedFwdArm': '<S278>:1' */
  /*  */
  /*  This function creates the VCODEs for the hand position feedback for both */
  /*  hands.  Various options in the Mask of the Simulink block in which this */
  /*  embedded Matlab file sits, allow the user to specify how often */
  /*  the hand feedback is updated as well as the source of the style and status */
  /*  of the hand feedback.   */
  /*  */
  /*  block_settings is the value chosen by the user in the Mask for parent Simulink */
  /*  block.  Note: that even if the block is wired up to accept Task Program  */
  /*  control of hand feedback style and status, this embedded Matlab file allows */
  /*  the GUI to over-ride those settings.  However, if the GUI requests that */
  /*  the parent block use Task Program control for the style and/or status when */
  /*  it has not been programmed in, then this embedded Matlab file handles this */
  /*  appropriately and ignore the request for Task Program control.   */
  /*  */
  /*  block_settings=1 -- parent block does not have any Task Program control over style or status */
  /*  block_settings=2 -- parent block has Task Program control over status only */
  /*  block_settings=3 -- parent block has Task Program control over both style and status */
  /*  */
  /*  fdbk_stts_mdl (only potentially used if block_settings=2)  */
  /*  fdbk_stts_mdl=0 -- neither hand on */
  /*  fdbk_stts_mdl=1 -- dominant hand on */
  /*  fdbk_stts_mdl=2 -- non-dominant hand on */
  /*  fdbk_stts_mdl=3 -- both hands on */
  /*  */
  /*  VCODES (only potentially used if block_settings=3)  */
  /*  VCODES for dominant and non-dominant, input to parent block  */
  /* '<S278>:1:32' */
  feedfwd = gbyk_v4b_B.kinarm_data[5];

  /* Constant: '<S8>/block_settings' */
  /* amount of feedforward extrapolation for hand position(s) */
  /* '<S278>:1:33' */
  /* status of hand feedback requested from GUI */
  /* '<S278>:1:34' */
  /* source of hand feedback style requested from GUI */
  /* '<S278>:1:35' */
  /* colour of hand feedback required by GUI */
  /* '<S278>:1:36' */
  /* radius of hand feedback required by GUI */
  /* ----------------Feedback Style ---------------- */
  /*  IF GUI asks for feedback style from Task Program (fdbk_src_GUI==0) */
  /*  AND if Task Program has been chosen to supply feedback style (block_settings==3) */
  /*  AND if Task Program actually supplies appropriate feedback styles (size(VCODES_in,2)==70) */
  if ((gbyk_v4b_B.kinarm_data[11] == 0.0) &&
      (gbyk_v4b_P.Hand_Feedback_feedback_cntl_src == 3.0)) {
    /* '<S278>:1:43' */
    /* '<S278>:1:44' */
    memcpy(&gbyk_v4b_B.VCODES_out[0], &gbyk_v4b_B.MatrixConcatenation[0], 140U *
           sizeof(real_T));
  } else {
    /* '<S278>:1:46' */
    for (i = 0; i < 140; i++) {
      gbyk_v4b_B.VCODES_out[i] = 0.0;
    }

    /* set default */
    /* '<S278>:1:47' */
    gbyk_v4b_B.VCODES_out[0] = 1.0;
    gbyk_v4b_B.VCODES_out[1] = 1.0;

    /* target_type of circle */
    /* '<S278>:1:48' */
    gbyk_v4b_B.VCODES_out[8] = gbyk_v4b_B.kinarm_data[14];
    gbyk_v4b_B.VCODES_out[9] = gbyk_v4b_B.kinarm_data[14];

    /* fill colour as specified by GUI */
    /* '<S278>:1:49' */
    gbyk_v4b_B.VCODES_out[10] = gbyk_v4b_B.kinarm_data[14];
    gbyk_v4b_B.VCODES_out[11] = gbyk_v4b_B.kinarm_data[14];

    /* stroke colour same as fill colour */
    /* '<S278>:1:50' */
    gbyk_v4b_B.VCODES_out[12] = 0.0;
    gbyk_v4b_B.VCODES_out[13] = 0.0;

    /* no stroke width */
    /* '<S278>:1:51' */
    gbyk_v4b_B.VCODES_out[16] = 100.0;
    gbyk_v4b_B.VCODES_out[17] = 100.0;

    /* 100% opacity */
    /* '<S278>:1:52' */
    gbyk_v4b_B.VCODES_out[18] = gbyk_v4b_B.kinarm_data[17];
    gbyk_v4b_B.VCODES_out[19] = gbyk_v4b_B.kinarm_data[17];

    /* radius (m) as specified by GUI */
  }

  /* ----------------Feedback Status ---------------- */
  /* feedback status from GUI sets the default to be used */
  if (gbyk_v4b_B.kinarm_data[8] == 4.0) {
    /* Constant: '<S8>/block_settings' */
    /* '<S278>:1:60' */
    /* if GUI has requested Task Program control of feedback status */
    if (gbyk_v4b_P.Hand_Feedback_feedback_cntl_src == 2.0) {
      /* Constant: '<S8>/feedback_status' */
      /* '<S278>:1:61' */
      /* if there is Task Program control ONLY of status (but not style) */
      /* '<S278>:1:62' */
      feedback_status = gbyk_v4b_P.feedback_status_Value;

      /* then use feedback status input from parent block */
    } else if (gbyk_v4b_P.Hand_Feedback_feedback_cntl_src == 3.0) {
      /* '<S278>:1:63' */
      /* if there is Task Program control of both status and style */
      /* '<S278>:1:64' */
      feedback_status = 4.0;

      /* then let the input VCODEs handle the status */
    } else {
      /* otherwise assume that the Task Program did not provide style OR status */
      /* '<S278>:1:66' */
      feedback_status = 3.0;

      /* then set both hands are always on as a default */
    }
  } else {
    /* if GUI is controlling feedback status */
    /* '<S278>:1:69' */
    feedback_status = gbyk_v4b_B.kinarm_data[8];
  }

  /* set the status of the hand-feedback in the VCODES */
  switch ((int32_T)feedback_status) {
   case 0:
    /* show neither hand feedback */
    /* '<S278>:1:75' */
    gbyk_v4b_B.VCODES_out[2] = 0.0;

    /* '<S278>:1:76' */
    gbyk_v4b_B.VCODES_out[3] = 0.0;
    break;

   case 1:
    /* show ONLY dominant hand feedback */
    /* '<S278>:1:78' */
    gbyk_v4b_B.VCODES_out[2] = 1.0;

    /* '<S278>:1:79' */
    gbyk_v4b_B.VCODES_out[3] = 0.0;
    break;

   case 2:
    /* show ONLY non-dominant hand feedback */
    /* '<S278>:1:81' */
    gbyk_v4b_B.VCODES_out[2] = 0.0;

    /* '<S278>:1:82' */
    gbyk_v4b_B.VCODES_out[3] = 1.0;
    break;

   case 4:
    /* VCODES already control hand feedback */
    /* do nothing */
    break;

   default:
    /* show both hand feedbacks */
    /* '<S278>:1:86' */
    gbyk_v4b_B.VCODES_out[2] = 1.0;

    /* '<S278>:1:87' */
    gbyk_v4b_B.VCODES_out[3] = 1.0;
    break;
  }

  /* ----------------Feedback Position ---------------- */
  /* set the position of the hand feedback. */
  /* '<S278>:1:92' */
  /* '<S278>:1:93' */
  /* '<S278>:1:94' */
  feedback_status = gbyk_v4b_B.kinarm_data[2];

  /* choose dominant arm first */
  /* '<S278>:1:98' */
  /* (m) */
  /* '<S278>:1:99' */
  /* (m) */
  /* '<S278>:1:100' */
  /* (m/s) */
  /* '<S278>:1:101' */
  /* (m/s) */
  /*  feed-forward hand position (m) */
  /* '<S278>:1:104' */
  /* '<S278>:1:105' */
  /* '<S278>:1:106' */
  gbyk_v4b_B.VCODES_out[4] = gbyk_v4b_B.kinarm_data[(int32_T)feedback_status +
    71] * feedfwd + gbyk_v4b_B.kinarm_data[(int32_T)feedback_status + 65];

  /* target position in m  */
  /* '<S278>:1:107' */
  gbyk_v4b_B.VCODES_out[6] = gbyk_v4b_B.kinarm_data[(int32_T)feedback_status +
    74] * feedfwd + gbyk_v4b_B.kinarm_data[(int32_T)feedback_status + 68];

  /* target position in m  */
  /* '<S278>:1:92' */
  /* '<S278>:1:96' */
  feedback_status = 3.0 - gbyk_v4b_B.kinarm_data[2];

  /* choose non-dominant arm 2nd */
  /* '<S278>:1:98' */
  /* (m) */
  /* '<S278>:1:99' */
  /* (m) */
  /* '<S278>:1:100' */
  /* (m/s) */
  /* '<S278>:1:101' */
  /* (m/s) */
  /*  feed-forward hand position (m) */
  /* '<S278>:1:104' */
  /* '<S278>:1:105' */
  /* '<S278>:1:106' */
  gbyk_v4b_B.VCODES_out[5] = gbyk_v4b_B.kinarm_data[(int32_T)feedback_status +
    71] * feedfwd + gbyk_v4b_B.kinarm_data[(int32_T)feedback_status + 65];

  /* target position in m  */
  /* '<S278>:1:107' */
  gbyk_v4b_B.VCODES_out[7] = gbyk_v4b_B.kinarm_data[(int32_T)feedback_status +
    74] * feedfwd + gbyk_v4b_B.kinarm_data[(int32_T)feedback_status + 68];

  /* target position in m  */
  /* '<S278>:1:92' */
  /* '<S278>:1:110' */
}
