/*
 * Code generation for system system '<S7>/Task Execution Control Subsystem'
 *
 * Model                      : gbyk_v4b
 * Model version              : 1.2667
 * Simulink Coder version : 8.8.1 (R2015aSP1) 04-Sep-2015
 * C source code generated on : Tue Sep 15 15:02:19 2020
 *
 * Note that the functions contained in this file are part of a Simulink
 * model, and are not self-contained algorithms.
 */

#include "gbyk_v4b_TaskExecutionControlSubsystem.h"

/* Include model header file for global data */
#include "gbyk_v4b.h"
#include "gbyk_v4b_private.h"

/* Named constants for Chart: '<S269>/Task Execution Control Machine' */
#define gbyk_v4b_IN_Finished           ((uint8_T)1U)
#define gbyk_v4b_IN_InTrial            ((uint8_T)2U)
#define gbyk_v4b_IN_NO_ACTIVE_CHILD_l  ((uint8_T)0U)
#define gbyk_v4b_IN_Paused             ((uint8_T)1U)
#define gbyk_v4b_IN_PausedBetweenBlocks ((uint8_T)3U)
#define gbyk_v4b_IN_PausedBetweenTrials ((uint8_T)4U)
#define gbyk_v4b_IN_Ready              ((uint8_T)5U)
#define gbyk_v4b_IN_RepeatTrialLater   ((uint8_T)2U)
#define gbyk_v4b_IN_RepeatTrialNow     ((uint8_T)3U)
#define gbyk_v4b_IN_Running            ((uint8_T)4U)
#define gbyk_v4b_IN_SkipTrial          ((uint8_T)5U)
#define gbyk_v4b_event_e_clk_b         (0)
#define gbyk_v4b_event_e_trial_over    (1)

/* Forward declaration for local functions */
static void gbyk_v4b_Ready(void);
static void gbyk_v4b_chartstep_c42_General(void);

/* Function for Chart: '<S269>/Task Execution Control Machine' */
static void gbyk_v4b_Ready(void)
{
  int32_T exitg1;
  boolean_T guard1;

  /* During 'Ready': '<S276>:10' */
  if (gbyk_v4b_B.DataTypeConversion1_gw == 1) {
    /* Transition: '<S276>:40' */
    srand(gbyk_v4b_B.Convert18);

    /* Transition: '<S276>:28' */
    do {
      exitg1 = 0;

      /* Transition: '<S276>:55' */
      /*  If specified, use task protocol block sequence. */
      guard1 = false;
      if (gbyk_v4b_B.UseTaskProtocolBlockSequenceFlag == 1.0) {
        /* Transition: '<S276>:50' */
        gbyk_v4b_DW.i_l = 1U;
        gbyk_v4b_DW.temp = (uint32_T)gbyk_v4b_B.BlockSequence[1000];

        /* Transition: '<S276>:27' */
        while ((gbyk_v4b_DW.temp <= gbyk_v4b_B.block_in_set) && (gbyk_v4b_DW.i_l
                < gbyk_v4b_B.Width2)) {
          /* Transition: '<S276>:25' */
          gbyk_v4b_DW.i_l++;
          gbyk_v4b_DW.temp = (uint32_T)(gbyk_v4b_B.BlockSequence[(int32_T)
            gbyk_v4b_DW.i_l + 999] + (real_T)gbyk_v4b_DW.temp);
        }

        /* Transition: '<S276>:12' */
        /*  Finish if using a task protocol block sequence
           and that sequence has finished. */
        if ((gbyk_v4b_DW.i_l == gbyk_v4b_B.Width2) && (gbyk_v4b_DW.temp <=
             gbyk_v4b_B.block_in_set)) {
          /* Transition: '<S276>:42' */
          gbyk_v4b_DW.is_c42_General = gbyk_v4b_IN_Finished;

          /* Entry 'Finished': '<S276>:4' */
          gbyk_v4b_B.task_status = 4U;
          exitg1 = 1;
        } else {
          /* Transition: '<S276>:32' */
          /*  Make next task protocol block index the next block. */
          gbyk_v4b_B.block = (uint32_T)gbyk_v4b_B.BlockSequence[(int32_T)
            (gbyk_v4b_DW.i_l - 1U)];

          /* Transition: '<S276>:13' */
          guard1 = true;
        }
      } else {
        /*  Finish if using a task program-specified block sequence
           and the block index input from the program is invalid. */
        if ((gbyk_v4b_B.UseTaskProtocolBlockSequenceFlag == 0.0) &&
            ((gbyk_v4b_B.NextBlock == 0.0) || (gbyk_v4b_B.NextBlock >
              gbyk_v4b_B.Width_j))) {
          /* Transition: '<S276>:24' */
          gbyk_v4b_DW.is_c42_General = gbyk_v4b_IN_Finished;

          /* Entry 'Finished': '<S276>:4' */
          gbyk_v4b_B.task_status = 4U;
          exitg1 = 1;
        } else {
          /* Transition: '<S276>:39' */
          /*  Make user-input block index the next block. */
          gbyk_v4b_B.block = (uint32_T)gbyk_v4b_B.NextBlock;

          /* Transition: '<S276>:45' */
          guard1 = true;
        }
      }

      if (guard1) {
        /* Transition: '<S276>:49' */
        gbyk_v4b_B.block_in_set++;
        gbyk_v4b_DW.i_l = 1U;
        gbyk_v4b_B.extra_trials[(int32_T)(gbyk_v4b_DW.BLOCK - 1.0)] = 0.0;

        /* Transition: '<S276>:36' */
        /*  Copy the trial list from the block definitions to the trial queue. */
        while ((gbyk_v4b_DW.i_l <= gbyk_v4b_B.Subtract_p) && (gbyk_v4b_B.block >
                0U) && (gbyk_v4b_B.BlockDefinitions[(50 * (int32_T)
                 gbyk_v4b_DW.i_l + (int32_T)gbyk_v4b_B.block) - 1] != 0.0)) {
          /* Transition: '<S276>:16' */
          gbyk_v4b_DW.trial_queue[(int32_T)(gbyk_v4b_DW.i_l - 1U)] =
            gbyk_v4b_B.BlockDefinitions[(50 * (int32_T)gbyk_v4b_DW.i_l +
            (int32_T)gbyk_v4b_B.block) - 1];
          gbyk_v4b_DW.i_l++;
        }

        /* Transition: '<S276>:41' */
        gbyk_v4b_DW.trial_queue_length = gbyk_v4b_DW.i_l - 1U;
        if (gbyk_v4b_DW.trial_queue_length > 0U) {
          /* Transition: '<S276>:66' */
          gbyk_v4b_B.trial_in_block = 0U;

          /* Transition: '<S276>:17' */
          gbyk_v4b_DW.trial_in_mini_block = 0U;

          /*  Randomize the block if the definition specifies to do so. */
          if (gbyk_v4b_B.BlockDefinitions[(int32_T)(gbyk_v4b_B.block - 1U)] ==
              1.0) {
            /* Transition: '<S276>:18' */
            gbyk_v4b_DW.i_l = 1U;

            /* Transition: '<S276>:22' */
            /*  Perform list randomization "a la Knuth". */
            while (gbyk_v4b_DW.i_l <= gbyk_v4b_DW.trial_queue_length) {
              /* Transition: '<S276>:23' */
              gbyk_v4b_DW.swap_index = (uint32_T)(fmod(rand(),
                gbyk_v4b_DW.trial_queue_length) + 1.0);
              gbyk_v4b_DW.temp = (uint32_T)gbyk_v4b_DW.trial_queue[(int32_T)
                (gbyk_v4b_DW.swap_index - 1U)];
              gbyk_v4b_DW.trial_queue[(int32_T)(gbyk_v4b_DW.swap_index - 1U)] =
                gbyk_v4b_DW.trial_queue[(int32_T)(gbyk_v4b_DW.i_l - 1U)];
              gbyk_v4b_DW.trial_queue[(int32_T)(gbyk_v4b_DW.i_l - 1U)] =
                gbyk_v4b_DW.temp;
              gbyk_v4b_DW.i_l++;
            }

            /* Transition: '<S276>:67' */
          } else {
            /* Transition: '<S276>:19' */
            /* Transition: '<S276>:20' */
          }

          /* Transition: '<S276>:21' */
          if (gbyk_v4b_B.DataTypeConversion1_gw != 1) {
            /* Transition: '<S276>:68' */
            /* Transition: '<S276>:69' */
            gbyk_v4b_DW.is_c42_General = gbyk_v4b_IN_PausedBetweenTrials;

            /* Entry 'PausedBetweenTrials': '<S276>:3' */
            gbyk_v4b_B.task_status = 3U;
          } else {
            /* Transition: '<S276>:70' */
            gbyk_v4b_DW.is_c42_General = gbyk_v4b_IN_InTrial;

            /* Entry 'InTrial': '<S276>:8' */
            gbyk_v4b_B.trial_in_set++;
            gbyk_v4b_B.trial_in_block++;
            gbyk_v4b_DW.trial_in_mini_block++;
            gbyk_v4b_B.tp = (uint32_T)gbyk_v4b_DW.trial_queue[(int32_T)
              (gbyk_v4b_DW.trial_in_mini_block - 1U)];

            /* Entry Internal 'InTrial': '<S276>:8' */
            /* Transition: '<S276>:47' */
            gbyk_v4b_DW.is_InTrial = gbyk_v4b_IN_Running;

            /* Entry 'Running': '<S276>:1' */
            gbyk_v4b_B.task_status = 2U;
          }

          exitg1 = 1;
        } else {
          /* Transition: '<S276>:65' */
          /* Transition: '<S276>:26' */
          if (gbyk_v4b_B.DataTypeConversion1_gw != 1) {
            /* Transition: '<S276>:33' */
            gbyk_v4b_DW.is_c42_General = gbyk_v4b_IN_PausedBetweenBlocks;

            /* Entry 'PausedBetweenBlocks': '<S276>:5' */
            gbyk_v4b_B.task_status = 3U;
            exitg1 = 1;
          } else {
            /* Transition: '<S276>:35' */
          }
        }
      }
    } while (exitg1 == 0);
  }
}

/* Function for Chart: '<S269>/Task Execution Control Machine' */
static void gbyk_v4b_chartstep_c42_General(void)
{
  boolean_T guard1 = false;
  boolean_T guard2;
  int32_T i;

  /* During: GUI Control/Task Execution Control Subsystem/Task Execution Control Machine */
  if (gbyk_v4b_DW.is_active_c42_General == 0U) {
    /* Entry: GUI Control/Task Execution Control Subsystem/Task Execution Control Machine */
    gbyk_v4b_DW.is_active_c42_General = 1U;

    /* Entry Internal: GUI Control/Task Execution Control Subsystem/Task Execution Control Machine */
    /* Transition: '<S276>:57' */
    gbyk_v4b_DW.is_c42_General = gbyk_v4b_IN_Ready;

    /* Entry 'Ready': '<S276>:10' */
    gbyk_v4b_B.task_status = 1U;
    gbyk_v4b_B.tp = 0U;
    gbyk_v4b_B.block = 0U;
    gbyk_v4b_B.trial_in_block = 0U;
    gbyk_v4b_B.block_in_set = 0U;
    gbyk_v4b_B.trial_in_set = 0U;
    gbyk_v4b_DW.trial_in_mini_block = 0U;
    gbyk_v4b_B.extra_trials[(int32_T)(gbyk_v4b_DW.EXAM - 1.0)] = 0.0;
    gbyk_v4b_B.extra_trials[(int32_T)(gbyk_v4b_DW.BLOCK - 1.0)] = 0.0;
  } else {
    switch (gbyk_v4b_DW.is_c42_General) {
     case gbyk_v4b_IN_Finished:
      /* During 'Finished': '<S276>:4' */
      break;

     case gbyk_v4b_IN_InTrial:
      /* During 'InTrial': '<S276>:8' */
      if (gbyk_v4b_DW.sfEvent_m == gbyk_v4b_event_e_trial_over) {
        /* Transition: '<S276>:37' */
        /*  Add the current trial to the repeat list if the
           task is paused and the selected pause type
           is to repeat the trial later, i.e. at the end of
           the block. This occurs independent of the
           repeat trial flag. */
        if (((gbyk_v4b_B.DataTypeConversion1_gw != 1) && (gbyk_v4b_B.PauseType ==
              3.0)) || ((gbyk_v4b_B.Product3 > 0.0) &&
                        ((gbyk_v4b_B.DataTypeConversion1_gw == 1) ||
                         (gbyk_v4b_B.PauseType == 0.0)))) {
          /* Transition: '<S276>:38' */
          /* Transition: '<S276>:59' */
          /* Transition: '<S276>:43' */
          /* Transition: '<S276>:58' */
          /* Transition: '<S276>:46' */
          /*  Add the current trial to the repeat list. */
          gbyk_v4b_DW.repeat_list_length++;
          gbyk_v4b_DW.repeat_list[(int32_T)(gbyk_v4b_DW.repeat_list_length - 1U)]
            = gbyk_v4b_B.tp;
          gbyk_v4b_B.repeat_last_trial = 1.0;
        } else {
          /* Transition: '<S276>:44' */
          /*  Also add the current trial to the repeat list
             if the repeat trial flag is set and the task is
             running (either normally or until pausing at
             the next trial). */
          /* Transition: '<S276>:60' */
          gbyk_v4b_B.repeat_last_trial = 0.0;
        }

        if (gbyk_v4b_DW.trial_in_mini_block >= gbyk_v4b_DW.trial_queue_length) {
          /* Transition: '<S276>:15' */
          /*  If there are any trials to repeat, assign them to the
             trial queue instead of advancing to the next block. */
          if (gbyk_v4b_DW.repeat_list_length > 0U) {
            /* Transition: '<S276>:11' */
            gbyk_v4b_DW.trial_queue_length = gbyk_v4b_DW.repeat_list_length;
            for (i = 0; i < 499; i++) {
              gbyk_v4b_DW.trial_queue[i] = gbyk_v4b_DW.repeat_list[i];
              gbyk_v4b_DW.repeat_list[i] = 0.0;
            }

            gbyk_v4b_DW.repeat_list_length = 0U;
            guard1 = true;
          } else {
            /* Transition: '<S276>:64' */
            do {
              i = 0;

              /* Transition: '<S276>:26' */
              if (gbyk_v4b_B.DataTypeConversion1_gw == 1) {
                /* Transition: '<S276>:35' */
                /* Transition: '<S276>:55' */
                /*  If specified, use task protocol block sequence. */
                guard2 = false;
                if (gbyk_v4b_B.UseTaskProtocolBlockSequenceFlag == 1.0) {
                  /* Transition: '<S276>:50' */
                  gbyk_v4b_DW.i_l = 1U;
                  gbyk_v4b_DW.temp = (uint32_T)gbyk_v4b_B.BlockSequence[1000];

                  /* Transition: '<S276>:27' */
                  while ((gbyk_v4b_DW.temp <= gbyk_v4b_B.block_in_set) &&
                         (gbyk_v4b_DW.i_l < gbyk_v4b_B.Width2)) {
                    /* Transition: '<S276>:25' */
                    gbyk_v4b_DW.i_l++;
                    gbyk_v4b_DW.temp = (uint32_T)(gbyk_v4b_B.BlockSequence
                      [(int32_T)gbyk_v4b_DW.i_l + 999] + (real_T)
                      gbyk_v4b_DW.temp);
                  }

                  /* Transition: '<S276>:12' */
                  /*  Finish if using a task protocol block sequence
                     and that sequence has finished. */
                  if ((gbyk_v4b_DW.i_l == gbyk_v4b_B.Width2) &&
                      (gbyk_v4b_DW.temp <= gbyk_v4b_B.block_in_set)) {
                    /* Transition: '<S276>:42' */
                    /* Exit Internal 'InTrial': '<S276>:8' */
                    gbyk_v4b_DW.is_InTrial = gbyk_v4b_IN_NO_ACTIVE_CHILD_l;
                    gbyk_v4b_DW.is_c42_General = gbyk_v4b_IN_Finished;

                    /* Entry 'Finished': '<S276>:4' */
                    gbyk_v4b_B.task_status = 4U;
                    i = 1;
                  } else {
                    /* Transition: '<S276>:32' */
                    /*  Make next task protocol block index the next block. */
                    gbyk_v4b_B.block = (uint32_T)gbyk_v4b_B.BlockSequence
                      [(int32_T)(gbyk_v4b_DW.i_l - 1U)];

                    /* Transition: '<S276>:13' */
                    guard2 = true;
                  }
                } else {
                  /*  Finish if using a task program-specified block sequence
                     and the block index input from the program is invalid. */
                  if ((gbyk_v4b_B.UseTaskProtocolBlockSequenceFlag == 0.0) &&
                      ((gbyk_v4b_B.NextBlock == 0.0) || (gbyk_v4b_B.NextBlock >
                        gbyk_v4b_B.Width_j))) {
                    /* Transition: '<S276>:24' */
                    /* Exit Internal 'InTrial': '<S276>:8' */
                    gbyk_v4b_DW.is_InTrial = gbyk_v4b_IN_NO_ACTIVE_CHILD_l;
                    gbyk_v4b_DW.is_c42_General = gbyk_v4b_IN_Finished;

                    /* Entry 'Finished': '<S276>:4' */
                    gbyk_v4b_B.task_status = 4U;
                    i = 1;
                  } else {
                    /* Transition: '<S276>:39' */
                    /*  Make user-input block index the next block. */
                    gbyk_v4b_B.block = (uint32_T)gbyk_v4b_B.NextBlock;

                    /* Transition: '<S276>:45' */
                    guard2 = true;
                  }
                }

                if (guard2) {
                  /* Transition: '<S276>:49' */
                  gbyk_v4b_B.block_in_set++;
                  gbyk_v4b_DW.i_l = 1U;
                  gbyk_v4b_B.extra_trials[(int32_T)(gbyk_v4b_DW.BLOCK - 1.0)] =
                    0.0;

                  /* Transition: '<S276>:36' */
                  /*  Copy the trial list from the block definitions to the trial queue. */
                  while ((gbyk_v4b_DW.i_l <= gbyk_v4b_B.Subtract_p) &&
                         (gbyk_v4b_B.block > 0U) &&
                         (gbyk_v4b_B.BlockDefinitions[(50 * (int32_T)
                           gbyk_v4b_DW.i_l + (int32_T)gbyk_v4b_B.block) - 1] !=
                          0.0)) {
                    /* Transition: '<S276>:16' */
                    gbyk_v4b_DW.trial_queue[(int32_T)(gbyk_v4b_DW.i_l - 1U)] =
                      gbyk_v4b_B.BlockDefinitions[(50 * (int32_T)gbyk_v4b_DW.i_l
                      + (int32_T)gbyk_v4b_B.block) - 1];
                    gbyk_v4b_DW.i_l++;
                  }

                  /* Transition: '<S276>:41' */
                  gbyk_v4b_DW.trial_queue_length = gbyk_v4b_DW.i_l - 1U;
                  if (gbyk_v4b_DW.trial_queue_length > 0U) {
                    /* Transition: '<S276>:66' */
                    gbyk_v4b_B.trial_in_block = 0U;
                    guard1 = true;
                    i = 1;
                  } else {
                    /* Transition: '<S276>:65' */
                  }
                }
              } else {
                /* Transition: '<S276>:33' */
                /* Exit Internal 'InTrial': '<S276>:8' */
                gbyk_v4b_DW.is_InTrial = gbyk_v4b_IN_NO_ACTIVE_CHILD_l;
                gbyk_v4b_DW.is_c42_General = gbyk_v4b_IN_PausedBetweenBlocks;

                /* Entry 'PausedBetweenBlocks': '<S276>:5' */
                gbyk_v4b_B.task_status = 3U;
                i = 1;
              }
            } while (i == 0);
          }
        } else {
          /* Transition: '<S276>:14' */
          if (gbyk_v4b_B.DataTypeConversion1_gw == 1) {
            /* Transition: '<S276>:29' */
            /* Exit Internal 'InTrial': '<S276>:8' */
            gbyk_v4b_DW.is_c42_General = gbyk_v4b_IN_InTrial;

            /* Entry 'InTrial': '<S276>:8' */
            gbyk_v4b_B.trial_in_set++;
            gbyk_v4b_B.trial_in_block++;
            gbyk_v4b_DW.trial_in_mini_block++;
            gbyk_v4b_B.tp = (uint32_T)gbyk_v4b_DW.trial_queue[(int32_T)
              (gbyk_v4b_DW.trial_in_mini_block - 1U)];

            /* Entry Internal 'InTrial': '<S276>:8' */
            /* Transition: '<S276>:47' */
            gbyk_v4b_DW.is_InTrial = gbyk_v4b_IN_Running;

            /* Entry 'Running': '<S276>:1' */
            gbyk_v4b_B.task_status = 2U;
          } else {
            /* Transition: '<S276>:30' */
            /* Exit Internal 'InTrial': '<S276>:8' */
            gbyk_v4b_DW.is_InTrial = gbyk_v4b_IN_NO_ACTIVE_CHILD_l;
            gbyk_v4b_DW.is_c42_General = gbyk_v4b_IN_PausedBetweenTrials;

            /* Entry 'PausedBetweenTrials': '<S276>:3' */
            gbyk_v4b_B.task_status = 3U;
          }
        }
      } else {
        switch (gbyk_v4b_DW.is_InTrial) {
         case gbyk_v4b_IN_Paused:
          /* During 'Paused': '<S276>:6' */
          if (gbyk_v4b_B.DataTypeConversion1_gw == 1) {
            /* Transition: '<S276>:54' */
            gbyk_v4b_DW.is_InTrial = gbyk_v4b_IN_Running;

            /* Entry 'Running': '<S276>:1' */
            gbyk_v4b_B.task_status = 2U;
          }
          break;

         case gbyk_v4b_IN_RepeatTrialLater:
          /* During 'RepeatTrialLater': '<S276>:7' */
          break;

         case gbyk_v4b_IN_RepeatTrialNow:
          /* During 'RepeatTrialNow': '<S276>:9' */
          break;

         case gbyk_v4b_IN_Running:
          /* During 'Running': '<S276>:1' */
          if ((gbyk_v4b_B.DataTypeConversion1_gw != 1) && (gbyk_v4b_B.PauseType >
               0.0)) {
            /* Transition: '<S276>:53' */
            if (gbyk_v4b_B.PauseType == 1.0) {
              /* Transition: '<S276>:52' */
              gbyk_v4b_DW.is_InTrial = gbyk_v4b_IN_SkipTrial;

              /* Entry 'SkipTrial': '<S276>:2' */
              /* Event: '<S276>:132' */
              gbyk_v4b_DW.e_exit_trialEventCounter++;
            } else {
              /* Transition: '<S276>:61' */
              if (gbyk_v4b_B.PauseType == 2.0) {
                /* Transition: '<S276>:51' */
                gbyk_v4b_DW.is_InTrial = gbyk_v4b_IN_RepeatTrialNow;

                /* Entry 'RepeatTrialNow': '<S276>:9' */
                gbyk_v4b_DW.trial_in_mini_block--;
                gbyk_v4b_B.extra_trials[(int32_T)(gbyk_v4b_DW.EXAM - 1.0)]++;
                gbyk_v4b_B.extra_trials[(int32_T)(gbyk_v4b_DW.BLOCK - 1.0)]++;

                /* Event: '<S276>:132' */
                gbyk_v4b_DW.e_exit_trialEventCounter++;
              } else {
                /* Transition: '<S276>:62' */
                if (gbyk_v4b_B.PauseType == 3.0) {
                  /* Transition: '<S276>:48' */
                  gbyk_v4b_DW.is_InTrial = gbyk_v4b_IN_RepeatTrialLater;

                  /* Entry 'RepeatTrialLater': '<S276>:7' */
                  gbyk_v4b_B.extra_trials[(int32_T)(gbyk_v4b_DW.EXAM - 1.0)]++;
                  gbyk_v4b_B.extra_trials[(int32_T)(gbyk_v4b_DW.BLOCK - 1.0)]++;

                  /* Event: '<S276>:132' */
                  gbyk_v4b_DW.e_exit_trialEventCounter++;
                } else {
                  /* Transition: '<S276>:63' */
                  /* Transition: '<S276>:56' */
                  gbyk_v4b_DW.is_InTrial = gbyk_v4b_IN_Paused;

                  /* Entry 'Paused': '<S276>:6' */
                  gbyk_v4b_B.task_status = 3U;
                }
              }
            }
          }
          break;

         default:
          /* During 'SkipTrial': '<S276>:2' */
          break;
        }
      }
      break;

     case gbyk_v4b_IN_PausedBetweenBlocks:
      /* During 'PausedBetweenBlocks': '<S276>:5' */
      if (gbyk_v4b_B.DataTypeConversion1_gw == 1) {
        /* Transition: '<S276>:34' */
        /* Transition: '<S276>:28' */
        do {
          i = 0;

          /* Transition: '<S276>:55' */
          /*  If specified, use task protocol block sequence. */
          guard2 = false;
          if (gbyk_v4b_B.UseTaskProtocolBlockSequenceFlag == 1.0) {
            /* Transition: '<S276>:50' */
            gbyk_v4b_DW.i_l = 1U;
            gbyk_v4b_DW.temp = (uint32_T)gbyk_v4b_B.BlockSequence[1000];

            /* Transition: '<S276>:27' */
            while ((gbyk_v4b_DW.temp <= gbyk_v4b_B.block_in_set) &&
                   (gbyk_v4b_DW.i_l < gbyk_v4b_B.Width2)) {
              /* Transition: '<S276>:25' */
              gbyk_v4b_DW.i_l++;
              gbyk_v4b_DW.temp = (uint32_T)(gbyk_v4b_B.BlockSequence[(int32_T)
                gbyk_v4b_DW.i_l + 999] + (real_T)gbyk_v4b_DW.temp);
            }

            /* Transition: '<S276>:12' */
            /*  Finish if using a task protocol block sequence
               and that sequence has finished. */
            if ((gbyk_v4b_DW.i_l == gbyk_v4b_B.Width2) && (gbyk_v4b_DW.temp <=
                 gbyk_v4b_B.block_in_set)) {
              /* Transition: '<S276>:42' */
              gbyk_v4b_DW.is_c42_General = gbyk_v4b_IN_Finished;

              /* Entry 'Finished': '<S276>:4' */
              gbyk_v4b_B.task_status = 4U;
              i = 1;
            } else {
              /* Transition: '<S276>:32' */
              /*  Make next task protocol block index the next block. */
              gbyk_v4b_B.block = (uint32_T)gbyk_v4b_B.BlockSequence[(int32_T)
                (gbyk_v4b_DW.i_l - 1U)];

              /* Transition: '<S276>:13' */
              guard2 = true;
            }
          } else {
            /*  Finish if using a task program-specified block sequence
               and the block index input from the program is invalid. */
            if ((gbyk_v4b_B.UseTaskProtocolBlockSequenceFlag == 0.0) &&
                ((gbyk_v4b_B.NextBlock == 0.0) || (gbyk_v4b_B.NextBlock >
                  gbyk_v4b_B.Width_j))) {
              /* Transition: '<S276>:24' */
              gbyk_v4b_DW.is_c42_General = gbyk_v4b_IN_Finished;

              /* Entry 'Finished': '<S276>:4' */
              gbyk_v4b_B.task_status = 4U;
              i = 1;
            } else {
              /* Transition: '<S276>:39' */
              /*  Make user-input block index the next block. */
              gbyk_v4b_B.block = (uint32_T)gbyk_v4b_B.NextBlock;

              /* Transition: '<S276>:45' */
              guard2 = true;
            }
          }

          if (guard2) {
            /* Transition: '<S276>:49' */
            gbyk_v4b_B.block_in_set++;
            gbyk_v4b_DW.i_l = 1U;
            gbyk_v4b_B.extra_trials[(int32_T)(gbyk_v4b_DW.BLOCK - 1.0)] = 0.0;

            /* Transition: '<S276>:36' */
            /*  Copy the trial list from the block definitions to the trial queue. */
            while ((gbyk_v4b_DW.i_l <= gbyk_v4b_B.Subtract_p) &&
                   (gbyk_v4b_B.block > 0U) && (gbyk_v4b_B.BlockDefinitions[(50 *
                     (int32_T)gbyk_v4b_DW.i_l + (int32_T)gbyk_v4b_B.block) - 1]
                    != 0.0)) {
              /* Transition: '<S276>:16' */
              gbyk_v4b_DW.trial_queue[(int32_T)(gbyk_v4b_DW.i_l - 1U)] =
                gbyk_v4b_B.BlockDefinitions[(50 * (int32_T)gbyk_v4b_DW.i_l +
                (int32_T)gbyk_v4b_B.block) - 1];
              gbyk_v4b_DW.i_l++;
            }

            /* Transition: '<S276>:41' */
            gbyk_v4b_DW.trial_queue_length = gbyk_v4b_DW.i_l - 1U;
            if (gbyk_v4b_DW.trial_queue_length > 0U) {
              /* Transition: '<S276>:66' */
              gbyk_v4b_B.trial_in_block = 0U;

              /* Transition: '<S276>:17' */
              gbyk_v4b_DW.trial_in_mini_block = 0U;

              /*  Randomize the block if the definition specifies to do so. */
              if (gbyk_v4b_B.BlockDefinitions[(int32_T)(gbyk_v4b_B.block - 1U)] ==
                  1.0) {
                /* Transition: '<S276>:18' */
                gbyk_v4b_DW.i_l = 1U;

                /* Transition: '<S276>:22' */
                /*  Perform list randomization "a la Knuth". */
                while (gbyk_v4b_DW.i_l <= gbyk_v4b_DW.trial_queue_length) {
                  /* Transition: '<S276>:23' */
                  gbyk_v4b_DW.swap_index = (uint32_T)(fmod(rand(),
                    gbyk_v4b_DW.trial_queue_length) + 1.0);
                  gbyk_v4b_DW.temp = (uint32_T)gbyk_v4b_DW.trial_queue[(int32_T)
                    (gbyk_v4b_DW.swap_index - 1U)];
                  gbyk_v4b_DW.trial_queue[(int32_T)(gbyk_v4b_DW.swap_index - 1U)]
                    = gbyk_v4b_DW.trial_queue[(int32_T)(gbyk_v4b_DW.i_l - 1U)];
                  gbyk_v4b_DW.trial_queue[(int32_T)(gbyk_v4b_DW.i_l - 1U)] =
                    gbyk_v4b_DW.temp;
                  gbyk_v4b_DW.i_l++;
                }

                /* Transition: '<S276>:67' */
              } else {
                /* Transition: '<S276>:19' */
                /* Transition: '<S276>:20' */
              }

              /* Transition: '<S276>:21' */
              if (gbyk_v4b_B.DataTypeConversion1_gw != 1) {
                /* Transition: '<S276>:68' */
                /* Transition: '<S276>:69' */
                gbyk_v4b_DW.is_c42_General = gbyk_v4b_IN_PausedBetweenTrials;

                /* Entry 'PausedBetweenTrials': '<S276>:3' */
                gbyk_v4b_B.task_status = 3U;
              } else {
                /* Transition: '<S276>:70' */
                gbyk_v4b_DW.is_c42_General = gbyk_v4b_IN_InTrial;

                /* Entry 'InTrial': '<S276>:8' */
                gbyk_v4b_B.trial_in_set++;
                gbyk_v4b_B.trial_in_block++;
                gbyk_v4b_DW.trial_in_mini_block++;
                gbyk_v4b_B.tp = (uint32_T)gbyk_v4b_DW.trial_queue[(int32_T)
                  (gbyk_v4b_DW.trial_in_mini_block - 1U)];

                /* Entry Internal 'InTrial': '<S276>:8' */
                /* Transition: '<S276>:47' */
                gbyk_v4b_DW.is_InTrial = gbyk_v4b_IN_Running;

                /* Entry 'Running': '<S276>:1' */
                gbyk_v4b_B.task_status = 2U;
              }

              i = 1;
            } else {
              /* Transition: '<S276>:65' */
              /* Transition: '<S276>:26' */
              if (gbyk_v4b_B.DataTypeConversion1_gw != 1) {
                /* Transition: '<S276>:33' */
                gbyk_v4b_DW.is_c42_General = gbyk_v4b_IN_PausedBetweenBlocks;

                /* Entry 'PausedBetweenBlocks': '<S276>:5' */
                gbyk_v4b_B.task_status = 3U;
                i = 1;
              } else {
                /* Transition: '<S276>:35' */
              }
            }
          }
        } while (i == 0);
      }
      break;

     case gbyk_v4b_IN_PausedBetweenTrials:
      /* During 'PausedBetweenTrials': '<S276>:3' */
      if (gbyk_v4b_B.DataTypeConversion1_gw == 1) {
        /* Transition: '<S276>:31' */
        gbyk_v4b_DW.is_c42_General = gbyk_v4b_IN_InTrial;

        /* Entry 'InTrial': '<S276>:8' */
        gbyk_v4b_B.trial_in_set++;
        gbyk_v4b_B.trial_in_block++;
        gbyk_v4b_DW.trial_in_mini_block++;
        gbyk_v4b_B.tp = (uint32_T)gbyk_v4b_DW.trial_queue[(int32_T)
          (gbyk_v4b_DW.trial_in_mini_block - 1U)];

        /* Entry Internal 'InTrial': '<S276>:8' */
        /* Transition: '<S276>:47' */
        gbyk_v4b_DW.is_InTrial = gbyk_v4b_IN_Running;

        /* Entry 'Running': '<S276>:1' */
        gbyk_v4b_B.task_status = 2U;
      }
      break;

     default:
      gbyk_v4b_Ready();
      break;
    }

    if (guard1) {
      /* Transition: '<S276>:17' */
      gbyk_v4b_DW.trial_in_mini_block = 0U;

      /*  Randomize the block if the definition specifies to do so. */
      if (gbyk_v4b_B.BlockDefinitions[(int32_T)(gbyk_v4b_B.block - 1U)] == 1.0)
      {
        /* Transition: '<S276>:18' */
        gbyk_v4b_DW.i_l = 1U;

        /* Transition: '<S276>:22' */
        /*  Perform list randomization "a la Knuth". */
        while (gbyk_v4b_DW.i_l <= gbyk_v4b_DW.trial_queue_length) {
          /* Transition: '<S276>:23' */
          gbyk_v4b_DW.swap_index = (uint32_T)(fmod(rand(),
            gbyk_v4b_DW.trial_queue_length) + 1.0);
          gbyk_v4b_DW.temp = (uint32_T)gbyk_v4b_DW.trial_queue[(int32_T)
            (gbyk_v4b_DW.swap_index - 1U)];
          gbyk_v4b_DW.trial_queue[(int32_T)(gbyk_v4b_DW.swap_index - 1U)] =
            gbyk_v4b_DW.trial_queue[(int32_T)(gbyk_v4b_DW.i_l - 1U)];
          gbyk_v4b_DW.trial_queue[(int32_T)(gbyk_v4b_DW.i_l - 1U)] =
            gbyk_v4b_DW.temp;
          gbyk_v4b_DW.i_l++;
        }

        /* Transition: '<S276>:67' */
      } else {
        /* Transition: '<S276>:19' */
        /* Transition: '<S276>:20' */
      }

      /* Transition: '<S276>:21' */
      if (gbyk_v4b_B.DataTypeConversion1_gw != 1) {
        /* Transition: '<S276>:68' */
        /* Transition: '<S276>:69' */
        /* Exit Internal 'InTrial': '<S276>:8' */
        gbyk_v4b_DW.is_InTrial = gbyk_v4b_IN_NO_ACTIVE_CHILD_l;
        gbyk_v4b_DW.is_c42_General = gbyk_v4b_IN_PausedBetweenTrials;

        /* Entry 'PausedBetweenTrials': '<S276>:3' */
        gbyk_v4b_B.task_status = 3U;
      } else {
        /* Transition: '<S276>:70' */
        /* Exit Internal 'InTrial': '<S276>:8' */
        gbyk_v4b_DW.is_c42_General = gbyk_v4b_IN_InTrial;

        /* Entry 'InTrial': '<S276>:8' */
        gbyk_v4b_B.trial_in_set++;
        gbyk_v4b_B.trial_in_block++;
        gbyk_v4b_DW.trial_in_mini_block++;
        gbyk_v4b_B.tp = (uint32_T)gbyk_v4b_DW.trial_queue[(int32_T)
          (gbyk_v4b_DW.trial_in_mini_block - 1U)];

        /* Entry Internal 'InTrial': '<S276>:8' */
        /* Transition: '<S276>:47' */
        gbyk_v4b_DW.is_InTrial = gbyk_v4b_IN_Running;

        /* Entry 'Running': '<S276>:1' */
        gbyk_v4b_B.task_status = 2U;
      }
    }
  }
}

/* Initial conditions for atomic system: '<S7>/Task Execution Control Subsystem' */
void gbyk_v4b_TaskExecutionControlSubsystem_Init(void)
{
  int32_T i;

  /* InitializeConditions for Memory: '<S269>/Delay1' */
  gbyk_v4b_DW.Delay1_PreviousInput = gbyk_v4b_P.Delay1_X0;

  /* InitializeConditions for Memory: '<S269>/Delay' */
  gbyk_v4b_DW.Delay_PreviousInput = gbyk_v4b_P.Delay_X0;

  /* InitializeConditions for Chart: '<S269>/Task Execution Control Machine' */
  gbyk_v4b_DW.is_InTrial = gbyk_v4b_IN_NO_ACTIVE_CHILD_l;
  gbyk_v4b_DW.is_active_c42_General = 0U;
  gbyk_v4b_DW.is_c42_General = gbyk_v4b_IN_NO_ACTIVE_CHILD_l;
  for (i = 0; i < 499; i++) {
    gbyk_v4b_DW.trial_queue[i] = 0.0;
    gbyk_v4b_DW.repeat_list[i] = 0.0;
  }

  gbyk_v4b_DW.repeat_list_length = 0U;
  gbyk_v4b_DW.i_l = 1U;
  gbyk_v4b_DW.swap_index = 0U;
  gbyk_v4b_DW.temp = 0U;
  gbyk_v4b_DW.trial_queue_length = 499U;
  gbyk_v4b_DW.trial_in_mini_block = 0U;
  gbyk_v4b_DW.EXAM = 1.0;
  gbyk_v4b_DW.BLOCK = 2.0;
  gbyk_v4b_B.task_status = 0U;
  gbyk_v4b_B.tp = 0U;
  gbyk_v4b_B.block = 0U;
  gbyk_v4b_B.trial_in_block = 0U;
  gbyk_v4b_B.block_in_set = 0U;
  gbyk_v4b_B.trial_in_set = 0U;
  gbyk_v4b_B.repeat_last_trial = 0.0;
  gbyk_v4b_B.extra_trials[0] = 0.0;
  gbyk_v4b_B.extra_trials[1] = 0.0;
  gbyk_v4b_DW.e_exit_trialEventCounter = 0U;
  gbyk_v4b_B.e_exit_trial = false;

  /* End of InitializeConditions for Chart: '<S269>/Task Execution Control Machine' */
}

/* Start for atomic system: '<S7>/Task Execution Control Subsystem' */
void gbyk_v4b_TaskExecutionControlSubsystem_Start(void)
{
  /* Start for DiscretePulseGenerator: '<S269>/Task Clock' */
  gbyk_v4b_DW.clockTickCounter = 0;
}

/* Outputs for atomic system: '<S7>/Task Execution Control Subsystem' */
void gbyk_v4b_TaskExecutionControlSubsystem(void)
{
  int32_T inputEventFiredFlag;
  boolean_T tmp;
  ZCEventType zcEvent_idx_0;
  ZCEventType zcEvent_idx_1;
  real_T tmp_0;

  /* Memory: '<S269>/Delay1' */
  gbyk_v4b_B.Delay1 = gbyk_v4b_DW.Delay1_PreviousInput;

  /* Product: '<S269>/Product3' incorporates:
   *  Constant: '<S7>/Use Repeat Trial Flag'
   */
  gbyk_v4b_B.Product3 = gbyk_v4b_B.Delay1 * gbyk_v4b_P.UseRepeatTrialFlag_Value;

  /* Sum: '<S269>/Subtract' incorporates:
   *  Constant: '<S269>/Constant'
   */
  tmp_0 = floor((real_T)gbyk_v4b_ConstB.Width1 - gbyk_v4b_P.Constant_Value_o1);
  if (rtIsNaN(tmp_0) || rtIsInf(tmp_0)) {
    tmp_0 = 0.0;
  } else {
    tmp_0 = fmod(tmp_0, 4.294967296E+9);
  }

  gbyk_v4b_B.Subtract_p = tmp_0 < 0.0 ? (uint32_T)-(int32_T)(uint32_T)-tmp_0 :
    (uint32_T)tmp_0;

  /* End of Sum: '<S269>/Subtract' */

  /* DiscretePulseGenerator: '<S269>/Task Clock' */
  gbyk_v4b_B.TaskClock = (gbyk_v4b_DW.clockTickCounter <
    gbyk_v4b_P.TaskClock_Duty_e) && (gbyk_v4b_DW.clockTickCounter >= 0) ?
    gbyk_v4b_P.TaskClock_Amp_m : 0.0;
  if (gbyk_v4b_DW.clockTickCounter >= gbyk_v4b_P.TaskClock_Period_n - 1.0) {
    gbyk_v4b_DW.clockTickCounter = 0;
  } else {
    gbyk_v4b_DW.clockTickCounter++;
  }

  /* End of DiscretePulseGenerator: '<S269>/Task Clock' */

  /* Product: '<S269>/Product' incorporates:
   *  Constant: '<S7>/Run Task Clock Flag'
   */
  gbyk_v4b_B.Product_i = gbyk_v4b_P.RunTaskClockFlag_Value *
    gbyk_v4b_B.TaskClock;

  /* Memory: '<S269>/Delay' */
  gbyk_v4b_B.Delay = gbyk_v4b_DW.Delay_PreviousInput;

  /* DataTypeConversion: '<S269>/Data Type Conversion' */
  gbyk_v4b_B.DataTypeConversion_g = gbyk_v4b_B.Delay;

  /* Chart: '<S269>/Task Execution Control Machine' incorporates:
   *  TriggerPort: '<S276>/ input events '
   */
  zcEvent_idx_0 = rt_ZCFcn(ANY_ZERO_CROSSING,
    &gbyk_v4b_PrevZCX.TaskExecutionControlMachine_Trig_ZCE[0],
    (gbyk_v4b_B.Product_i));
  zcEvent_idx_1 = rt_ZCFcn(ANY_ZERO_CROSSING,
    &gbyk_v4b_PrevZCX.TaskExecutionControlMachine_Trig_ZCE[1],
    (gbyk_v4b_B.DataTypeConversion_g));
  tmp = (zcEvent_idx_0 != NO_ZCEVENT);
  tmp = (tmp || (zcEvent_idx_1 != NO_ZCEVENT));
  if (tmp) {
    gbyk_v4b_B.inputevents_h[0] = (int8_T)zcEvent_idx_0;
    gbyk_v4b_B.inputevents_h[1] = (int8_T)zcEvent_idx_1;

    /* Gateway: GUI Control/Task Execution Control Subsystem/Task Execution Control Machine */
    inputEventFiredFlag = 0;
    if (gbyk_v4b_B.inputevents_h[0U] != 0) {
      inputEventFiredFlag = 1;

      /* Event: '<S276>:130' */
      gbyk_v4b_DW.sfEvent_m = gbyk_v4b_event_e_clk_b;
      gbyk_v4b_chartstep_c42_General();
    }

    if (gbyk_v4b_B.inputevents_h[1U] != 0) {
      inputEventFiredFlag = 1;

      /* Event: '<S276>:131' */
      gbyk_v4b_DW.sfEvent_m = gbyk_v4b_event_e_trial_over;
      gbyk_v4b_chartstep_c42_General();
    }

    if ((inputEventFiredFlag != 0) && (gbyk_v4b_DW.e_exit_trialEventCounter > 0U))
    {
      gbyk_v4b_B.e_exit_trial = !gbyk_v4b_B.e_exit_trial;
      gbyk_v4b_DW.e_exit_trialEventCounter--;
    }

    gbyk_v4b_DW.TaskExecutionControlMachine_SubsysRanBC = 4;
  }

  /* RelationalOperator: '<S275>/Compare' incorporates:
   *  Constant: '<S275>/Constant'
   */
  gbyk_v4b_B.Compare_o = (uint8_T)(gbyk_v4b_B.task_status ==
    gbyk_v4b_P.CompareToConstant_const_b);

  /* Product: '<S269>/Product2' */
  gbyk_v4b_B.Product2 = gbyk_v4b_B.Product_i * (real_T)gbyk_v4b_B.Compare_o;

  /* DataTypeConversion: '<S269>/Data Type Conversion1' */
  gbyk_v4b_B.DataTypeConversion1_m = (gbyk_v4b_B.Product2 != 0.0);

  /* DataTypeConversion: '<S269>/Data Type Conversion2' */
  gbyk_v4b_B.DataTypeConversion2_n = gbyk_v4b_B.Compare_o;

  /* Selector: '<S269>/Selector' */
  memcpy(&gbyk_v4b_B.Selector_n[0], &gbyk_v4b_B.BlockDefinitions[0], 50U *
         sizeof(real_T));

  /* Selector: '<S269>/Selector1' */
  for (inputEventFiredFlag = 0; inputEventFiredFlag < 500; inputEventFiredFlag++)
  {
    gbyk_v4b_B.Selector1[inputEventFiredFlag] = gbyk_v4b_B.BlockDefinitions[50 *
      inputEventFiredFlag];
  }

  /* End of Selector: '<S269>/Selector1' */

  /* Selector: '<S269>/Selector2' */
  memcpy(&gbyk_v4b_B.Selector2_l[0], &gbyk_v4b_B.BlockSequence[0], 1000U *
         sizeof(real_T));
}

/* Update for atomic system: '<S7>/Task Execution Control Subsystem' */
void gbyk_v4b_TaskExecutionControlSubsystem_Update(void)
{
  /* Update for Memory: '<S269>/Delay1' */
  gbyk_v4b_DW.Delay1_PreviousInput = gbyk_v4b_B.repeat_trial_flag;

  /* Update for Memory: '<S269>/Delay' */
  gbyk_v4b_DW.Delay_PreviousInput = gbyk_v4b_B.e_Trial_End;
}
