/*
 * gbyk_v4b_capi.c
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

#include "gbyk_v4b.h"
#include "rtw_capi.h"
#include "gbyk_v4b_private.h"

/* Block output signal information */
static const rtwCAPI_Signals rtBlockSignals[] = {
  /* addrMapIndex, sysNum, blockPath,
   * signalName, portNumber, dataTypeIndex, dimIndex, fxpIndex, sTimeIndex
   */
  { 0, 1, "AddTxt2TgtB",
    "VCODE_MOD", 0, 0, 0, 0, 0 },

  { 1, 2, "AddTxt2TgtC",
    "VCODE_MOD", 0, 0, 0, 0, 0 },

  { 2, 186, "MATLAB Function",
    "ListReps", 0, 0, 1, 0, 0 },

  { 3, 195, "Trial_Control/p1",
    "logging_enable", 0, 0, 2, 0, 1 },

  { 4, 195, "Trial_Control/p2",
    "event_code", 1, 1, 1, 0, 1 },

  { 5, 0, "Trial_Control/p3",
    "", 2, 2, 3, 0, 0 },

  { 6, 0, "Trial_Control/p4",
    "", 3, 2, 3, 0, 0 },

  { 7, 0, "Trial_Control/p5",
    "", 4, 2, 3, 0, 0 },

  { 8, 0, "Trial_Control/p6",
    "", 5, 2, 3, 0, 0 },

  { 9, 195, "Trial_Control/p7",
    "targetA_row", 6, 0, 1, 0, 1 },

  { 10, 195, "Trial_Control/p8",
    "targetA_state", 7, 0, 1, 0, 1 },

  { 11, 195, "Trial_Control/p9",
    "targetB_row", 8, 0, 2, 0, 1 },

  { 12, 195, "Trial_Control/p10",
    "targetB_state", 9, 0, 2, 0, 1 },

  { 13, 195, "Trial_Control/p11",
    "offeredRewards", 10, 0, 2, 0, 1 },

  { 14, 195, "Trial_Control/p12",
    "score", 11, 0, 1, 0, 1 },

  { 15, 195, "Trial_Control/p13",
    "doreward", 12, 0, 1, 0, 1 },

  { 16, 195, "Trial_Control/p14",
    "feedback_text", 13, 3, 1, 0, 1 },

  { 17, 195, "Trial_Control/p15",
    "reward", 14, 0, 1, 0, 1 },

  { 18, 195, "Trial_Control/p16",
    "instruct_num", 15, 0, 1, 0, 1 },

  { 19, 195, "Trial_Control/p17",
    "tone", 16, 0, 1, 0, 1 },

  { 20, 195, "Trial_Control/p18",
    "repeat_trial_flag", 17, 0, 1, 0, 1 },

  { 21, 195, "Trial_Control/p19",
    "trialIterations", 18, 0, 4, 0, 1 },

  { 22, 195, "Trial_Control/p20",
    "targetC_row", 19, 0, 2, 0, 1 },

  { 23, 195, "Trial_Control/p21",
    "targetC_state", 20, 0, 2, 0, 1 },

  { 24, 195, "Trial_Control/p22",
    "offeredRewardsC", 21, 0, 2, 0, 1 },

  { 25, 195, "Trial_Control/p23",
    "boxRow", 22, 0, 1, 0, 1 },

  { 26, 195, "Trial_Control/p24",
    "boxState", 23, 0, 1, 0, 1 },

  { 27, 195, "Trial_Control/p25",
    "e_Trial_End", 24, 2, 1, 0, 1 },

  { 28, 0, "Matrix Concatenation",
    "", 0, 0, 5, 0, 0 },

  { 29, 0, "Vector Concatenate",
    "", 0, 0, 6, 0, 0 },

  { 30, 0, "Vector Concatenate1",
    "", 0, 2, 3, 0, 0 },

  { 31, 0, "Vector Concatenate2",
    "", 0, 0, 7, 0, 0 },

  { 32, 0, "Data Type Conversion3",
    "", 0, 0, 6, 0, 0 },

  { 33, 0, "Math Function",
    "", 0, 0, 8, 0, 0 },

  { 34, 0, "Product",
    "", 0, 0, 1, 0, 0 },

  { 35, 0, "Selector2",
    "", 0, 0, 1, 0, 0 },

  { 36, 0, "Selector3",
    "", 0, 0, 9, 0, 0 },

  { 37, 0, "Selector4",
    "", 0, 0, 10, 0, 0 },

  { 38, 0, "Selector5",
    "", 0, 0, 10, 0, 0 },

  { 39, 0, "Sum of Elements",
    "", 0, 0, 1, 0, 0 },

  { 40, 0, "Switch",
    "", 0, 0, 8, 0, 0 },

  { 41, 0, "Switch1",
    "", 0, 0, 8, 0, 0 },

  { 42, 0, "Trigonometric Function",
    "", 0, 0, 1, 0, 0 },

  { 43, 0, "Sqrt",
    "", 0, 0, 1, 0, 0 },

  { 44, 0, "Compare To Constant/Compare",
    "", 0, 2, 1, 0, 0 },

  { 45, 0, "DataLogging/read Digital diag",
    "", 0, 4, 3, 0, 0 },

  { 46, 0, "DataLogging/read status",
    "", 0, 0, 11, 0, 0 },

  { 47, 0, "DataLogging/Memory",
    "", 0, 0, 3, 0, 0 },

  { 48, 0, "DataLogging/Memory1",
    "", 0, 0, 1, 0, 0 },

  { 49, 0, "DataLogging/Rate Transition",
    "", 0, 0, 12, 0, 2 },

  { 50, 0, "DataLogging/Rate Transition1",
    "", 0, 0, 13, 0, 2 },

  { 51, 0, "DataLogging/Rate Transition2",
    "", 0, 0, 2, 0, 2 },

  { 52, 0, "DataLogging/AddTorques",
    "", 0, 0, 3, 0, 0 },

  { 53, 0, "DisplayInstruct/Abs",
    "", 0, 0, 1, 0, 0 },

  { 54, 0, "DisplayInstruct/Sign",
    "", 0, 0, 1, 0, 0 },

  { 55, 0, "DisplayInstruct/Add",
    "", 0, 0, 1, 0, 0 },

  { 56, 164, "DisplayText/MATLAB Function",
    "VCODE_mod", 0, 0, 14, 0, 0 },

  { 57, 0, "DisplayText/Abs",
    "", 0, 3, 1, 0, 0 },

  { 58, 0, "DisplayText/Data Type Conversion",
    "", 0, 0, 1, 0, 0 },

  { 59, 0, "DisplayText/Logical Operator",
    "", 0, 2, 1, 0, 0 },

  { 60, 0, "DisplayText/Switch",
    "", 0, 0, 1, 0, 0 },

  { 61, 0, "GUI Control/Block Definitions",
    "", 0, 0, 15, 0, 0 },

  { 62, 0, "GUI Control/Block Sequence",
    "", 0, 0, 16, 0, 0 },

  { 63, 0, "GUI Control/Library Patch Version",
    "", 0, 0, 1, 0, 0 },

  { 64, 0, "GUI Control/Library Version",
    "", 0, 0, 1, 0, 0 },

  { 65, 0, "GUI Control/Load Table",
    "", 0, 0, 17, 0, 0 },

  { 66, 0, "GUI Control/Next Block",
    "", 0, 0, 1, 0, 0 },

  { 67, 0, "GUI Control/Pause Type",
    "", 0, 0, 1, 0, 0 },

  { 68, 0, "GUI Control/Target Table",
    "", 0, 0, 18, 0, 0 },

  { 69, 0, "GUI Control/Task Version",
    "", 0, 0, 1, 0, 0 },

  { 70, 0, "GUI Control/Task wide param",
    "", 0, 0, 19, 0, 0 },

  { 71, 0, "GUI Control/Use Task Protocol Block Sequence Flag",
    "", 0, 0, 1, 0, 0 },

  { 72, 0, "GUI Control/dlm build time",
    "", 0, 0, 1, 0, 0 },

  { 73, 0, "GUI Control/frame_of_reference_center",
    "", 0, 0, 2, 0, 0 },

  { 74, 0, "GUI Control/xPC Version",
    "", 0, 0, 1, 0, 0 },

  { 75, 0, "GUI Control/Convert1",
    "", 0, 0, 20, 0, 0 },

  { 76, 0, "GUI Control/Convert10",
    "", 0, 0, 8, 0, 0 },

  { 77, 0, "GUI Control/Convert11",
    "", 0, 0, 21, 0, 0 },

  { 78, 0, "GUI Control/Convert12",
    "", 0, 0, 1, 0, 0 },

  { 79, 0, "GUI Control/Convert13",
    "", 0, 0, 7, 0, 0 },

  { 80, 0, "GUI Control/Convert14",
    "", 0, 0, 8, 0, 0 },

  { 81, 0, "GUI Control/Convert15",
    "", 0, 0, 1, 0, 0 },

  { 82, 0, "GUI Control/Convert16",
    "", 0, 0, 1, 0, 0 },

  { 83, 0, "GUI Control/Convert17",
    "", 0, 0, 1, 0, 0 },

  { 84, 0, "GUI Control/Convert18",
    "", 0, 0, 1, 0, 0 },

  { 85, 0, "GUI Control/Convert19",
    "", 0, 4, 1, 0, 0 },

  { 86, 0, "GUI Control/Convert20",
    "", 0, 4, 1, 0, 0 },

  { 87, 0, "GUI Control/Convert21",
    "", 0, 4, 1, 0, 0 },

  { 88, 0, "GUI Control/Convert22",
    "", 0, 4, 1, 0, 0 },

  { 89, 0, "GUI Control/Convert23",
    "", 0, 4, 1, 0, 0 },

  { 90, 0, "GUI Control/Convert24",
    "", 0, 4, 1, 0, 0 },

  { 91, 0, "GUI Control/Convert25",
    "", 0, 2, 1, 0, 0 },

  { 92, 0, "GUI Control/Convert7",
    "", 0, 0, 1, 0, 0 },

  { 93, 0, "GUI Control/Convert8",
    "", 0, 0, 1, 0, 0 },

  { 94, 0, "GUI Control/Convert9",
    "", 0, 0, 8, 0, 0 },

  { 95, 0, "GUI Control/MinMax",
    "", 0, 0, 1, 0, 0 },

  { 96, 0, "GUI Control/TP Selector",
    "", 0, 0, 22, 0, 0 },

  { 97, 173, "Hand_Feedback/FeedFwdArm",
    "VCODES_out", 0, 0, 0, 0, 0 },

  { 98, 0, "Hand_Feedback/Matrix Concatenation",
    "", 0, 0, 0, 0, 0 },

  { 99, 0, "Hand_Feedback/Reshape",
    "", 0, 0, 14, 0, 0 },

  { 100, 0, "Hand_Feedback/Reshape1",
    "", 0, 0, 14, 0, 0 },

  { 101, 176, "KINARM_DistanceFromTarget/Embedded MATLAB InsideTarget",
    "distance", 0, 0, 23, 0, 0 },

  { 102, 177, "KINARM_DistanceFromTarget/Embedded MATLAB WhichHand",
    "hand", 0, 0, 1, 0, 0 },

  { 103, 0, "KINARM_DistanceFromTarget/Multiport Switch",
    "", 0, 0, 8, 0, 0 },

  { 104, 175, "KINARM_DistanceFromTarget/Arm1",
    "", 0, 0, 8, 0, 0 },

  { 105, 174, "KINARM_DistanceFromTarget/Arm2",
    "", 0, 0, 8, 0, 0 },

  { 106, 0, "KINARM_DistanceFromTarget/Dominant_Arm",
    "", 0, 0, 1, 0, 0 },

  { 107, 0, "KINARM_DistanceFromTarget/Hand_Pos",
    "", 0, 0, 24, 0, 0 },

  { 108, 180, "KINARM_HandInBox/Embedded MATLAB InsideTarget",
    "intarget", 0, 0, 25, 0, 0 },

  { 109, 181, "KINARM_HandInBox/Embedded MATLAB WhichHand",
    "hand", 0, 0, 1, 0, 0 },

  { 110, 0, "KINARM_HandInBox/Multiport Switch",
    "", 0, 0, 8, 0, 0 },

  { 111, 179, "KINARM_HandInBox/Arm1",
    "", 0, 0, 8, 0, 0 },

  { 112, 178, "KINARM_HandInBox/Arm2",
    "", 0, 0, 8, 0, 0 },

  { 113, 0, "KINARM_HandInBox/Array Selector",
    "", 0, 0, 26, 0, 0 },

  { 114, 0, "KINARM_HandInBox/Dominant_Arm",
    "", 0, 0, 1, 0, 0 },

  { 115, 0, "KINARM_HandInBox/Hand_Pos",
    "", 0, 0, 24, 0, 0 },

  { 116, 184, "KINARM_HandInTarget/Embedded MATLAB InsideTarget",
    "intarget", 0, 0, 25, 0, 0 },

  { 117, 185, "KINARM_HandInTarget/Embedded MATLAB WhichHand",
    "hand", 0, 0, 1, 0, 0 },

  { 118, 0, "KINARM_HandInTarget/Multiport Switch",
    "", 0, 0, 8, 0, 0 },

  { 119, 183, "KINARM_HandInTarget/Arm1",
    "", 0, 0, 8, 0, 0 },

  { 120, 182, "KINARM_HandInTarget/Arm2",
    "", 0, 0, 8, 0, 0 },

  { 121, 0, "KINARM_HandInTarget/Array Selector",
    "", 0, 0, 26, 0, 0 },

  { 122, 0, "KINARM_HandInTarget/Dominant_Arm",
    "", 0, 0, 1, 0, 0 },

  { 123, 0, "KINARM_HandInTarget/Hand_Pos",
    "", 0, 0, 24, 0, 0 },

  { 124, 188, "Process_Video_CMD/MATLAB Function/p1",
    "last_frame_ack", 0, 0, 1, 0, 0 },

  { 125, 188, "Process_Video_CMD/MATLAB Function/p2",
    "last_perm_ack", 1, 0, 1, 0, 0 },

  { 126, 0, "Process_Video_CMD/Matrix Concatenate",
    "", 0, 0, 27, 0, 3 },

  { 127, 0, "Process_Video_CMD/GUI_VCODE",
    "", 0, 0, 27, 0, 3 },

  { 128, 0, "Process_Video_CMD/Convert",
    "", 0, 0, 1, 0, 0 },

  { 129, 0, "Process_Video_CMD/Convert1",
    "", 0, 0, 1, 0, 0 },

  { 130, 0, "Process_Video_CMD/Gain",
    "", 0, 0, 1, 0, 0 },

  { 131, 0, "Process_Video_CMD/Memory",
    "", 0, 0, 1, 0, 0 },

  { 132, 0, "Process_Video_CMD/invert dim",
    "", 0, 0, 27, 0, 3 },

  { 133, 0, "Process_Video_CMD/Rate Transition2",
    "", 0, 0, 5, 0, 3 },

  { 134, 0, "Process_Video_CMD/Receive/p1",
    "", 0, 5, 3, 0, 0 },

  { 135, 0, "Process_Video_CMD/Receive/p2",
    "", 1, 0, 1, 0, 0 },

  { 136, 0, "Process_Video_CMD/Unpack",
    "", 0, 4, 1, 0, 0 },

  { 137, 191, "Show_Box/Embedded MATLAB Function",
    "VCODE", 0, 0, 14, 0, 0 },

  { 138, 0, "Show_Box/Matrix Concatenation",
    "", 0, 0, 28, 0, 0 },

  { 139, 0, "Show_Box/Matrix Concatenation1",
    "", 0, 0, 28, 0, 0 },

  { 140, 0, "Show_Box/padder",
    "", 0, 0, 28, 0, 0 },

  { 141, 0, "Show_Box/Selector",
    "", 0, 0, 29, 0, 0 },

  { 142, 192, "Show_TargetB_With_Label/Embedded MATLAB Function",
    "VCODE", 0, 0, 0, 0, 0 },

  { 143, 0, "Show_TargetB_With_Label/Matrix Concatenation",
    "", 0, 0, 28, 0, 0 },

  { 144, 0, "Show_TargetB_With_Label/Matrix Concatenation1",
    "", 0, 0, 28, 0, 0 },

  { 145, 0, "Show_TargetB_With_Label/padder",
    "", 0, 0, 28, 0, 0 },

  { 146, 0, "Show_TargetB_With_Label/Selector",
    "", 0, 0, 30, 0, 0 },

  { 147, 193, "Show_TargetC_With_Label/Embedded MATLAB Function",
    "VCODE", 0, 0, 0, 0, 0 },

  { 148, 0, "Show_TargetC_With_Label/Matrix Concatenation",
    "", 0, 0, 28, 0, 0 },

  { 149, 0, "Show_TargetC_With_Label/Matrix Concatenation1",
    "", 0, 0, 28, 0, 0 },

  { 150, 0, "Show_TargetC_With_Label/padder",
    "", 0, 0, 28, 0, 0 },

  { 151, 0, "Show_TargetC_With_Label/Selector",
    "", 0, 0, 30, 0, 0 },

  { 152, 194, "Show_Target_A/Embedded MATLAB Function",
    "VCODE", 0, 0, 14, 0, 0 },

  { 153, 0, "Show_Target_A/Matrix Concatenation",
    "", 0, 0, 28, 0, 0 },

  { 154, 0, "Show_Target_A/Matrix Concatenation1",
    "", 0, 0, 28, 0, 0 },

  { 155, 0, "Show_Target_A/padder",
    "", 0, 0, 28, 0, 0 },

  { 156, 0, "Show_Target_A/Selector",
    "", 0, 0, 29, 0, 0 },

  { 157, 0, "DataLogging/Create Analog Inputs Subsystem/Analog Data",
    "", 0, 0, 6, 0, 0 },

  { 158, 0, "DataLogging/Create Analog Inputs Subsystem/Analog Data Width",
    "", 0, 0, 1, 0, 2 },

  { 159, 0, "DataLogging/Create Analog Inputs Subsystem/Rate Transition",
    "", 0, 0, 1, 0, 2 },

  { 160, 0, "DataLogging/Create Analog Inputs Subsystem/Rate Transition1",
    "", 0, 0, 6, 0, 2 },

  { 161, 0, "DataLogging/Create Analog Inputs Subsystem/Subtract",
    "", 0, 0, 1, 0, 2 },

  { 162, 0, "DataLogging/Create Analog Inputs Subsystem/Width",
    "", 0, 0, 1, 0, 4 },

  { 163, 0, "DataLogging/Create Custom Data Subsystem/Custom Data1",
    "", 0, 0, 31, 0, 0 },

  { 164, 0, "DataLogging/Create Custom Data Subsystem/Rate Transition",
    "", 0, 0, 32, 0, 0 },

  { 165, 0, "DataLogging/Create Custom Data Subsystem/Rate Transition1",
    "", 0, 0, 1, 0, 0 },

  { 166, 0, "DataLogging/Create Custom Data Subsystem/Rate Transition2",
    "", 0, 0, 1, 0, 0 },

  { 167, 0, "DataLogging/Create Custom Data Subsystem/Width",
    "", 0, 0, 1, 0, 4 },

  { 168, 0, "DataLogging/Create Event Codes Subsystem/Event Codes",
    "", 0, 0, 1, 0, 0 },

  { 169, 0, "DataLogging/Create Event Codes Subsystem/Number of Event Codes",
    "", 0, 0, 1, 0, 2 },

  { 170, 0, "DataLogging/Create Event Codes Subsystem/Subtract",
    "", 0, 0, 1, 0, 2 },

  { 171, 0, "DataLogging/Create Event Codes Subsystem/Width",
    "", 0, 0, 1, 0, 4 },

  { 172, 3, "DataLogging/Create KINARM Data Subsystem/bitfield",
    "bitfield", 0, 4, 1, 0, 0 },

  { 173, 0, "DataLogging/Create KINARM Data Subsystem/Arm Kinematics",
    "", 0, 0, 33, 0, 2 },

  { 174, 0, "DataLogging/Create KINARM Data Subsystem/Kinarm Data Width",
    "", 0, 0, 1, 0, 2 },

  { 175, 0, "DataLogging/Create KINARM Data Subsystem/touint",
    "", 0, 4, 34, 0, 0 },

  { 176, 0, "DataLogging/Create KINARM Data Subsystem/touint1",
    "", 0, 0, 1, 0, 2 },

  { 177, 0, "DataLogging/Create KINARM Data Subsystem/Rate Transition",
    "", 0, 0, 35, 0, 2 },

  { 178, 0, "DataLogging/Create KINARM Data Subsystem/Rate Transition1",
    "", 0, 4, 1, 0, 2 },

  { 179, 0, "DataLogging/Create KINARM Data Subsystem/Rate Transition2",
    "", 0, 0, 36, 0, 2 },

  { 180, 0, "DataLogging/Create KINARM Data Subsystem/Rate Transition3",
    "", 0, 0, 37, 0, 2 },

  { 181, 0, "DataLogging/Create KINARM Data Subsystem/Width",
    "", 0, 0, 1, 0, 4 },

  { 182, 0, "DataLogging/Create Task State Subsystem/Button Status",
    "", 0, 0, 1, 0, 0 },

  { 183, 0, "DataLogging/Create Task State Subsystem/Current Block Index",
    "", 0, 0, 1, 0, 0 },

  { 184, 0,
    "DataLogging/Create Task State Subsystem/Current Block Number in Set",
    "", 0, 0, 1, 0, 0 },

  { 185, 0, "DataLogging/Create Task State Subsystem/Current TP Index",
    "", 0, 0, 1, 0, 0 },

  { 186, 0,
    "DataLogging/Create Task State Subsystem/Current Trial Number in Block",
    "", 0, 0, 1, 0, 0 },

  { 187, 0,
    "DataLogging/Create Task State Subsystem/Current Trial Number in Set",
    "", 0, 0, 1, 0, 0 },

  { 188, 0, "DataLogging/Create Task State Subsystem/Last Frame Acknowledged",
    "", 0, 0, 1, 0, 0 },

  { 189, 0, "DataLogging/Create Task State Subsystem/Last Frame Sent",
    "", 0, 0, 1, 0, 0 },

  { 190, 0, "DataLogging/Create Task State Subsystem/Last Frame Sent1",
    "", 0, 0, 1, 0, 0 },

  { 191, 0, "DataLogging/Create Task State Subsystem/Logging Enable",
    "", 0, 0, 2, 0, 0 },

  { 192, 0, "DataLogging/Create Task State Subsystem/Run Status",
    "", 0, 0, 1, 0, 0 },

  { 193, 0, "DataLogging/Create Task State Subsystem/Servo update count",
    "", 0, 0, 1, 0, 0 },

  { 194, 0, "DataLogging/Create Task State Subsystem/Task Control Button",
    "", 0, 0, 1, 0, 0 },

  { 195, 0, "DataLogging/Create Task State Subsystem/Timestamp",
    "", 0, 0, 1, 0, 2 },

  { 196, 0, "DataLogging/Create Task State Subsystem/conv",
    "", 0, 0, 1, 0, 2 },

  { 197, 0, "DataLogging/Create Task State Subsystem/Product",
    "", 0, 0, 2, 0, 0 },

  { 198, 0, "DataLogging/Create Task State Subsystem/Rate Transition",
    "", 0, 0, 1, 0, 2 },

  { 199, 0, "DataLogging/Create Task State Subsystem/Rate Transition1",
    "", 0, 0, 1, 0, 2 },

  { 200, 0, "DataLogging/Create Task State Subsystem/Rate Transition10",
    "", 0, 0, 1, 0, 2 },

  { 201, 0, "DataLogging/Create Task State Subsystem/Rate Transition11",
    "", 0, 0, 1, 0, 2 },

  { 202, 0, "DataLogging/Create Task State Subsystem/Rate Transition12",
    "", 0, 0, 1, 0, 2 },

  { 203, 0, "DataLogging/Create Task State Subsystem/Rate Transition2",
    "", 0, 0, 1, 0, 2 },

  { 204, 0, "DataLogging/Create Task State Subsystem/Rate Transition3",
    "", 0, 0, 1, 0, 2 },

  { 205, 0, "DataLogging/Create Task State Subsystem/Rate Transition4",
    "", 0, 0, 1, 0, 2 },

  { 206, 0, "DataLogging/Create Task State Subsystem/Rate Transition5",
    "", 0, 0, 1, 0, 2 },

  { 207, 0, "DataLogging/Create Task State Subsystem/Rate Transition6",
    "", 0, 0, 1, 0, 2 },

  { 208, 0, "DataLogging/Create Task State Subsystem/Rate Transition7",
    "", 0, 0, 1, 0, 2 },

  { 209, 0, "DataLogging/Create Task State Subsystem/Rate Transition8",
    "", 0, 0, 1, 0, 2 },

  { 210, 0, "DataLogging/Create Task State Subsystem/Rate Transition9",
    "", 0, 0, 2, 0, 2 },

  { 211, 0, "DataLogging/Create Task State Subsystem/Width",
    "", 0, 0, 1, 0, 4 },

  { 212, 5, "DataLogging/Keep alive/Pack",
    "", 0, 5, 38, 0, 5 },

  { 213, 7, "DataLogging/Network Transfer Subsystem/Send Control Machine/p1",
    "resetUDP", 0, 0, 1, 0, 1 },

  { 214, 7, "DataLogging/Network Transfer Subsystem/Send Control Machine/p2",
    "data_out", 1, 6, 39, 0, 1 },

  { 215, 7, "DataLogging/Network Transfer Subsystem/Send Control Machine/p3",
    "queue_size", 2, 0, 1, 0, 1 },

  { 216, 7, "DataLogging/Network Transfer Subsystem/Send Control Machine/p4",
    "total_timeouts", 3, 0, 1, 0, 1 },

  { 217, 9, "DataLogging/Network Transfer Subsystem/force strobe",
    "strobe_out", 0, 0, 1, 0, 6 },

  { 218, 10, "DataLogging/Network Transfer Subsystem/max_packet_id",
    "", 0, 4, 1, 0, 0 },

  { 219, 10, "DataLogging/Network Transfer Subsystem/Data Type Conversion2",
    "", 0, 6, 1, 0, 0 },

  { 220, 10, "DataLogging/Network Transfer Subsystem/Queue Size",
    "queue_size", 0, 0, 1, 0, 0 },

  { 221, 10, "DataLogging/Network Transfer Subsystem/Total Timeouts",
    "timeouts", 0, 0, 1, 0, 0 },

  { 222, 10, "DataLogging/Network Transfer Subsystem/Task Clock",
    "", 0, 0, 1, 0, 0 },

  { 223, 17, "DataLogging/Poll Force Plates/Convert1",
    "", 0, 5, 40, 0, 0 },

  { 224, 17, "DataLogging/Poll Force Plates/Convert19",
    "", 0, 0, 37, 0, 0 },

  { 225, 17, "DataLogging/Poll Force Plates/Rate Transition",
    "", 0, 0, 1, 0, 6 },

  { 226, 17, "DataLogging/Poll Force Plates/Rate Transition1",
    "", 0, 0, 1, 0, 6 },

  { 227, 150, "DataLogging/Poll KINARM/system type",
    "", 0, 0, 1, 0, 0 },

  { 228, 150, "DataLogging/Poll KINARM/Read HasFT",
    "", 0, 0, 2, 0, 0 },

  { 229, 151, "DataLogging/Receive_Gaze/Create timestamp/p1",
    "timestamp_out", 0, 0, 1, 0, 0 },

  { 230, 151, "DataLogging/Receive_Gaze/Create timestamp/p2",
    "start_time_out", 1, 0, 1, 0, 0 },

  { 231, 152, "DataLogging/Receive_Gaze/Embedded MATLAB Function1/p1",
    "gazeXYCalculated", 0, 0, 2, 0, 0 },

  { 232, 152, "DataLogging/Receive_Gaze/Embedded MATLAB Function1/p2",
    "pupil_area_GLOBAL", 1, 0, 1, 0, 0 },

  { 233, 152, "DataLogging/Receive_Gaze/Embedded MATLAB Function1/p3",
    "gaze_unit_vector_GLOBAL", 2, 0, 41, 0, 0 },

  { 234, 152, "DataLogging/Receive_Gaze/Embedded MATLAB Function1/p4",
    "pupil_GLOBAL", 3, 0, 41, 0, 0 },

  { 235, 153, "DataLogging/Receive_Gaze/clean_packet/p1",
    "pack_out", 0, 5, 42, 0, 0 },

  { 236, 153, "DataLogging/Receive_Gaze/clean_packet/p2",
    "len_out", 1, 3, 1, 0, 0 },

  { 237, 154, "DataLogging/Receive_Gaze/convert to seconds2",
    "event_data_out", 0, 0, 41, 0, 2 },

  { 238, 155, "DataLogging/Receive_Gaze/Convert1",
    "", 0, 0, 1, 0, 0 },

  { 239, 155, "DataLogging/Receive_Gaze/Convert19",
    "", 0, 0, 41, 0, 0 },

  { 240, 155, "DataLogging/Receive_Gaze/Convert2",
    "", 0, 0, 41, 0, 2 },

  { 241, 155, "DataLogging/Receive_Gaze/Convert3",
    "", 0, 0, 1, 0, 0 },

  { 242, 155, "DataLogging/Receive_Gaze/Convert4",
    "", 0, 0, 41, 0, 0 },

  { 243, 155, "DataLogging/Receive_Gaze/Data Type Conversion",
    "", 0, 0, 1, 0, 0 },

  { 244, 155, "DataLogging/Receive_Gaze/Data Type Conversion1",
    "", 0, 0, 41, 0, 0 },

  { 245, 155, "DataLogging/Receive_Gaze/Data Type Conversion3",
    "", 0, 0, 32, 0, 0 },

  { 246, 155, "DataLogging/Receive_Gaze/Data Type Conversion4",
    "", 0, 0, 1, 0, 0 },

  { 247, 155, "DataLogging/Receive_Gaze/Data Type Conversion5",
    "", 0, 0, 1, 0, 0 },

  { 248, 155, "DataLogging/Receive_Gaze/convert",
    "", 0, 3, 1, 0, 0 },

  { 249, 155, "DataLogging/Receive_Gaze/Gain",
    "", 0, 0, 41, 0, 0 },

  { 250, 155, "DataLogging/Receive_Gaze/Rate Transition",
    "", 0, 0, 41, 0, 0 },

  { 251, 155, "DataLogging/Receive_Gaze/Reshape",
    "", 0, 6, 43, 0, 0 },

  { 252, 155, "DataLogging/Receive_Gaze/Selector - Left Eye",
    "", 0, 6, 32, 0, 0 },

  { 253, 155, "DataLogging/Receive_Gaze/Receive/p1",
    "", 0, 5, 42, 0, 0 },

  { 254, 155, "DataLogging/Receive_Gaze/Receive/p2",
    "", 1, 0, 1, 0, 0 },

  { 255, 155, "DataLogging/Receive_Gaze/S-Function/p1",
    "", 0, 4, 1, 0, 0 },

  { 256, 155, "DataLogging/Receive_Gaze/S-Function/p2",
    "SAMPE_TYPE", 1, 7, 1, 0, 0 },

  { 257, 155, "DataLogging/Receive_Gaze/S-Function/p3",
    "Content Flags", 2, 1, 1, 0, 0 },

  { 258, 155, "DataLogging/Receive_Gaze/S-Function/p4",
    "pupil X", 3, 6, 2, 0, 0 },

  { 259, 155, "DataLogging/Receive_Gaze/S-Function/p5",
    "pupil Y", 4, 6, 2, 0, 0 },

  { 260, 155, "DataLogging/Receive_Gaze/S-Function/p6",
    "HREF X", 5, 6, 2, 0, 0 },

  { 261, 155, "DataLogging/Receive_Gaze/S-Function/p7",
    "HREF Y", 6, 6, 2, 0, 0 },

  { 262, 155, "DataLogging/Receive_Gaze/S-Function/p8",
    "pupil area", 7, 6, 2, 0, 0 },

  { 263, 155, "DataLogging/Receive_Gaze/S-Function/p9",
    "screen gaze X", 8, 6, 2, 0, 0 },

  { 264, 155, "DataLogging/Receive_Gaze/S-Function/p10",
    "screen gaze Y", 9, 6, 2, 0, 0 },

  { 265, 155, "DataLogging/Receive_Gaze/S-Function/p11",
    "resolution X", 10, 6, 1, 0, 0 },

  { 266, 155, "DataLogging/Receive_Gaze/S-Function/p12",
    "resolution Y", 11, 6, 1, 0, 0 },

  { 267, 155, "DataLogging/Receive_Gaze/S-Function/p13",
    "status flags", 12, 1, 1, 0, 0 },

  { 268, 155, "DataLogging/Receive_Gaze/S-Function/p14",
    "extra input", 13, 1, 1, 0, 0 },

  { 269, 155, "DataLogging/Receive_Gaze/S-Function/p15",
    "buttons", 14, 1, 1, 0, 0 },

  { 270, 155, "DataLogging/Receive_Gaze/S-Function/p16",
    "htype", 15, 7, 1, 0, 0 },

  { 271, 155, "DataLogging/Receive_Gaze/S-Function/p17",
    "hdata", 16, 7, 11, 0, 0 },

  { 272, 155, "DataLogging/Receive_Gaze/S-Function/p18",
    "", 17, 4, 41, 0, 0 },

  { 273, 160, "DataLogging/compare encoders/delta",
    "deltas", 0, 0, 32, 0, 0 },

  { 274, 0, "DataLogging/create_lab_info/arm_count",
    "robot_count", 0, 0, 1, 0, 0 },

  { 275, 0, "DataLogging/create_lab_info/fp1_present",
    "has_force_plate_1", 0, 0, 1, 0, 0 },

  { 276, 0, "DataLogging/create_lab_info/fp2_present",
    "has_force_plate_2", 0, 0, 1, 0, 0 },

  { 277, 0, "DataLogging/create_lab_info/gaze_tracker_present",
    "has_gaze_tracker", 0, 0, 1, 0, 0 },

  { 278, 0, "DataLogging/create_lab_info/robot_lift_present",
    "has_robot_lift", 0, 0, 1, 0, 0 },

  { 279, 163, "DisplayInstruct/Show_Target/Embedded MATLAB Function",
    "VCODE", 0, 0, 14, 0, 0 },

  { 280, 0, "DisplayInstruct/Show_Target/Matrix Concatenation",
    "", 0, 0, 28, 0, 0 },

  { 281, 0, "DisplayInstruct/Show_Target/Matrix Concatenation1",
    "", 0, 0, 28, 0, 0 },

  { 282, 0, "DisplayInstruct/Show_Target/padder",
    "", 0, 0, 28, 0, 0 },

  { 283, 0, "DisplayInstruct/Show_Target/Selector",
    "", 0, 0, 29, 0, 0 },

  { 284, 165, "DisplayText/Show_Target_With_Label1/Embedded MATLAB Function",
    "VCODE", 0, 0, 14, 0, 0 },

  { 285, 0, "DisplayText/Show_Target_With_Label1/Matrix Concatenation",
    "", 0, 0, 28, 0, 0 },

  { 286, 0, "DisplayText/Show_Target_With_Label1/Matrix Concatenation1",
    "", 0, 0, 28, 0, 0 },

  { 287, 0, "DisplayText/Show_Target_With_Label1/padder",
    "", 0, 0, 28, 0, 0 },

  { 288, 0, "DisplayText/Show_Target_With_Label1/Selector",
    "", 0, 0, 29, 0, 0 },

  { 289, 166, "GUI Control/Preview Targets Subsystem/Create Target Vector/p1",
    "target_vector", 0, 0, 44, 0, 0 },

  { 290, 166, "GUI Control/Preview Targets Subsystem/Create Target Vector/p2",
    "target_vector_length", 1, 0, 1, 0, 0 },

  { 291, 167, "GUI Control/Preview Targets Subsystem/Concatenation",
    "", 0, 0, 45, 0, 0 },

  { 292, 167, "GUI Control/Preview Targets Subsystem/Concatenation1",
    "", 0, 0, 45, 0, 0 },

  { 293, 167, "GUI Control/Preview Targets Subsystem/indices_padding",
    "", 0, 0, 45, 0, 0 },

  { 294, 167, "GUI Control/Preview Targets Subsystem/Reshape",
    "", 0, 0, 45, 0, 0 },

  { 295, 167, "GUI Control/Preview Targets Subsystem/Reshape1",
    "", 0, 0, 45, 0, 0 },

  { 296, 168, "GUI Control/Run Command Subsystem/Embedded MATLAB Function/p1",
    "y", 0, 0, 1, 0, 0 },

  { 297, 168, "GUI Control/Run Command Subsystem/Embedded MATLAB Function/p2",
    "z", 1, 0, 1, 0, 0 },

  { 298, 169, "GUI Control/Run Command Subsystem/Hold_to_1Khz",
    "value", 0, 0, 1, 0, 0 },

  { 299, 0, "GUI Control/Run Command Subsystem/Data Type Conversion",
    "", 0, 0, 1, 0, 0 },

  { 300, 0, "GUI Control/Run Command Subsystem/Data Type Conversion1",
    "", 0, 5, 1, 0, 0 },

  { 301, 0, "GUI Control/Run Command Subsystem/Data Type Conversion2",
    "", 0, 0, 1, 0, 0 },

  { 302, 0, "GUI Control/Run Command Subsystem/Run Command Receive/p1",
    "", 0, 5, 1, 0, 0 },

  { 303, 0, "GUI Control/Run Command Subsystem/Run Command Receive/p2",
    "", 1, 0, 1, 0, 0 },

  { 304, 170,
    "GUI Control/Task Execution Control Subsystem/Task Execution Control Machine/p1",
    "task_status", 0, 4, 1, 0, 1 },

  { 305, 170,
    "GUI Control/Task Execution Control Subsystem/Task Execution Control Machine/p2",
    "tp", 1, 4, 1, 0, 1 },

  { 306, 170,
    "GUI Control/Task Execution Control Subsystem/Task Execution Control Machine/p3",
    "block", 2, 4, 1, 0, 1 },

  { 307, 170,
    "GUI Control/Task Execution Control Subsystem/Task Execution Control Machine/p4",
    "trial_in_block", 3, 4, 1, 0, 1 },

  { 308, 170,
    "GUI Control/Task Execution Control Subsystem/Task Execution Control Machine/p5",
    "block_in_set", 4, 4, 1, 0, 1 },

  { 309, 170,
    "GUI Control/Task Execution Control Subsystem/Task Execution Control Machine/p6",
    "trial_in_set", 5, 4, 1, 0, 1 },

  { 310, 170,
    "GUI Control/Task Execution Control Subsystem/Task Execution Control Machine/p7",
    "repeat_last_trial", 6, 0, 1, 0, 1 },

  { 311, 170,
    "GUI Control/Task Execution Control Subsystem/Task Execution Control Machine/p8",
    "extra_trials", 7, 0, 2, 0, 1 },

  { 312, 170,
    "GUI Control/Task Execution Control Subsystem/Task Execution Control Machine/p9",
    "e_exit_trial", 8, 2, 1, 0, 1 },

  { 313, 171,
    "GUI Control/Task Execution Control Subsystem/Data Type Conversion",
    "", 0, 0, 1, 0, 0 },

  { 314, 171,
    "GUI Control/Task Execution Control Subsystem/Data Type Conversion1",
    "", 0, 2, 1, 0, 0 },

  { 315, 171,
    "GUI Control/Task Execution Control Subsystem/Data Type Conversion2",
    "", 0, 0, 1, 0, 0 },

  { 316, 171, "GUI Control/Task Execution Control Subsystem/Task Clock",
    "", 0, 0, 1, 0, 0 },

  { 317, 171, "GUI Control/Task Execution Control Subsystem/Delay",
    "", 0, 2, 1, 0, 0 },

  { 318, 171, "GUI Control/Task Execution Control Subsystem/Delay1",
    "", 0, 0, 1, 0, 0 },

  { 319, 171, "GUI Control/Task Execution Control Subsystem/Product",
    "", 0, 0, 1, 0, 0 },

  { 320, 171, "GUI Control/Task Execution Control Subsystem/Product2",
    "", 0, 0, 1, 0, 0 },

  { 321, 171, "GUI Control/Task Execution Control Subsystem/Product3",
    "", 0, 0, 1, 0, 0 },

  { 322, 171, "GUI Control/Task Execution Control Subsystem/Selector",
    "", 0, 0, 46, 0, 0 },

  { 323, 171, "GUI Control/Task Execution Control Subsystem/Selector1",
    "", 0, 0, 47, 0, 0 },

  { 324, 171, "GUI Control/Task Execution Control Subsystem/Selector2",
    "", 0, 0, 48, 0, 0 },

  { 325, 171, "GUI Control/Task Execution Control Subsystem/Subtract",
    "", 0, 4, 1, 0, 0 },

  { 326, 171, "GUI Control/Task Execution Control Subsystem/Width",
    "", 0, 4, 1, 0, 4 },

  { 327, 171, "GUI Control/Task Execution Control Subsystem/Width1",
    "", 0, 4, 1, 0, 4 },

  { 328, 171, "GUI Control/Task Execution Control Subsystem/Width2",
    "", 0, 4, 1, 0, 4 },

  { 329, 172, "GUI Control/Task_progress/MATLAB Function/p1",
    "total_trials", 0, 0, 1, 0, 0 },

  { 330, 172, "GUI Control/Task_progress/MATLAB Function/p2",
    "trials_in_block", 1, 0, 1, 0, 0 },

  { 331, 172, "GUI Control/Task_progress/MATLAB Function/p3",
    "total_blocks", 2, 0, 1, 0, 0 },

  { 332, 0, "GUI Control/Task_progress/Data Type Conversion",
    "total_trials_in_exam", 0, 4, 1, 0, 0 },

  { 333, 0, "GUI Control/Task_progress/Data Type Conversion1",
    "total_trials_in_block", 0, 4, 1, 0, 0 },

  { 334, 0, "GUI Control/Task_progress/Data Type Conversion2",
    "total_blocks_in_exam", 0, 4, 1, 0, 0 },

  { 335, 0,
    "Parameter Table Defn/TP_table/B1;Target B1 row;float;B1 row in target table;;;none;;",
    "", 0, 0, 1, 0, 0 },

  { 336, 0,
    "Parameter Table Defn/TP_table/B2;Target B2 row;float;B2 row in target table;;;none;;",
    "", 0, 0, 1, 0, 0 },

  { 337, 0,
    "Parameter Table Defn/TP_table/CORR_TGT;Which target is correct;float;Which target is correct (1 or 2) ?;;;none;;",
    "", 0, 0, 1, 0, 0 },

  { 338, 0,
    "Parameter Table Defn/TP_table/DELAY_POST_TRIAL;Trial-End Delay;integer;Time to wait at the end of the trial;;;none;;",
    "", 0, 0, 1, 0, 0 },

  { 339, 0,
    "Parameter Table Defn/TP_table/DISPLAY_TRIAL_COL;Flag Display;integer;Display and pause;;;none;;",
    "", 0, 0, 1, 0, 0 },

  { 340, 0,
    "Parameter Table Defn/TP_table/INCORR_TGT;Which target is incorrect;float;Which target is incorrect (1 or 2) ?;;;none;;",
    "", 0, 0, 1, 0, 0 },

  { 341, 0,
    "Parameter Table Defn/TP_table/MAX_REACH_TIME_COL;Maximum Reach Time;integer;Maximum reach duration allowed;;;none;;",
    "", 0, 0, 1, 0, 0 },

  { 342, 0,
    "Parameter Table Defn/TP_table/RWD_TARGETC1_COL;Target1 Value;float;Reward offered on Target C1;;;none;;",
    "", 0, 0, 1, 0, 0 },

  { 343, 0,
    "Parameter Table Defn/TP_table/RWD_TARGETC2_COL;Target2 Value;float;Reward offered on Target C2;;;none;;",
    "", 0, 0, 1, 0, 0 },

  { 344, 0,
    "Parameter Table Defn/TP_table/START_TARGET_COL;Start target;target;First target to appear during a trial;;;none;;",
    "", 0, 0, 1, 0, 0 },

  { 345, 0,
    "Parameter Table Defn/TP_table/TGT_C_RWD_FRAC;Reward ratio between rowC:rowB;float;How much more will targets B be worth?;;;none;;",
    "", 0, 0, 1, 0, 0 },

  { 346, 0,
    "Parameter Table Defn/buttons/INSTRUCT_PAUSE_BTN;Instruction-Resume;;Button to continue task after displaying instructions;25;22;none;;",
    "", 0, 0, 1, 0, 0 },

  { 347, 0,
    "Parameter Table Defn/events/E_BOX_TRIGGER;Box Was Triggered;;Box triggrered so subject chose row C;;;none;;",
    "", 0, 0, 1, 0, 0 },

  { 348, 0,
    "Parameter Table Defn/events/E_CHOSE_ROW_B;Chose Row B;;Subject chose row B ;;;none;;",
    "", 0, 0, 1, 0, 0 },

  { 349, 0,
    "Parameter Table Defn/events/E_HIT_TARGETB;Hit Target B;;Hit target B;;;none;;",
    "", 0, 0, 1, 0, 0 },

  { 350, 0,
    "Parameter Table Defn/events/E_HIT_TARGETC;Hit Target C;;Hit Target C;;;none;;",
    "", 0, 0, 1, 0, 0 },

  { 351, 0,
    "Parameter Table Defn/events/E_MISS_TARGETB;Miss Targret B;;Miss Targret B;;;none;;",
    "", 0, 0, 1, 0, 0 },

  { 352, 0,
    "Parameter Table Defn/events/E_MISS_TARGETC;Miss Target C;;Miss Target C;;;none;;",
    "", 0, 0, 1, 0, 0 },

  { 353, 0,
    "Parameter Table Defn/events/E_NEW_TRIAL;New Trial Start;;New Trial starts;;;none;;",
    "", 0, 0, 1, 0, 0 },

  { 354, 0,
    "Parameter Table Defn/events/E_NO_EVENT;n|a;;This event_code does not save an event in the data file, it just clears the event;;;none;;",
    "", 0, 0, 1, 0, 0 },

  { 355, 0,
    "Parameter Table Defn/events/E_SHOW_INSTRUCT;Instruction state;;Showing instructions;;;none;;",
    "", 0, 0, 1, 0, 0 },

  { 356, 0,
    "Parameter Table Defn/events/E_SHOW_SCORE;Show Score;;Showing score;;;none;;",
    "", 0, 0, 1, 0, 0 },

  { 357, 0,
    "Parameter Table Defn/events/E_STAY_START;At Start;;Subject reached start target;;;none;;",
    "", 0, 0, 1, 0, 0 },

  { 358, 0,
    "Parameter Table Defn/events/E_TARGETS_ON;Targets On;;Potential Reach targets on;;;none;;",
    "", 0, 0, 1, 0, 0 },

  { 359, 0,
    "Parameter Table Defn/events/E_TOO_SLOW;Too Slow;;Movement is too slow;;;error;;",
    "", 0, 0, 1, 0, 0 },

  { 360, 0,
    "Parameter Table Defn/target_table/BOX_HEIGHT;Height of Box;float;Height of Box;;;none;;",
    "", 0, 0, 1, 0, 0 },

  { 361, 0,
    "Parameter Table Defn/target_table/HIT_COLOR;Reached color;colour;Color when the target is touched;;;none;;",
    "", 0, 0, 1, 0, 0 },

  { 362, 0,
    "Parameter Table Defn/target_table/INIT_COLOR;Initial color;colour;Initial target color;;;none;;",
    "", 0, 0, 1, 0, 0 },

  { 363, 0,
    "Parameter Table Defn/target_table/LABEL;Label Text;label;Initial text for the label;;;none;;",
    "", 0, 0, 1, 0, 0 },

  { 364, 0,
    "Parameter Table Defn/target_table/LABELONLY_X;LabelOnly X;float;X position (cm) of the target relative to local (0,0) when only the label appears;;;none;;",
    "", 0, 0, 1, 0, 0 },

  { 365, 0,
    "Parameter Table Defn/target_table/LABELONLY_Y;LabelOnly  Y;float;Y position (cm) of the target relative to local (0,0) when only the label appears;;;none;;",
    "", 0, 0, 1, 0, 0 },

  { 366, 0,
    "Parameter Table Defn/target_table/LABEL_HEIGHT;Label Height;float;Label Height (cm);;;none;;",
    "", 0, 0, 1, 0, 0 },

  { 367, 0,
    "Parameter Table Defn/target_table/LOGICAL_RADIUS;Logical radius;float;Radius of the target used for 'hand-in-target' logic (cm);;;none;;",
    "", 0, 0, 1, 0, 0 },

  { 368, 0,
    "Parameter Table Defn/target_table/ROTATION;Rotation of a target;float;Rotation of target;;;none;;",
    "", 0, 0, 1, 0, 0 },

  { 369, 0,
    "Parameter Table Defn/target_table/STROKE_WIDTH;Stroke Width;float;Stroke width;;;none;;",
    "", 0, 0, 1, 0, 0 },

  { 370, 0,
    "Parameter Table Defn/target_table/TEXT_COLOR;Text Color;colour;Text Color;;;none;;",
    "", 0, 0, 1, 0, 0 },

  { 371, 0,
    "Parameter Table Defn/target_table/VISUAL_RADIUS;Visual radius;float;Visual radius of the target (cm) or size of the sides of the square targets;;;none;;",
    "", 0, 0, 1, 0, 0 },

  { 372, 0,
    "Parameter Table Defn/target_table/col_x;X;float;X Position (cm) of the target relative to  local (0,0);;;none;;",
    "", 0, 0, 1, 0, 0 },

  { 373, 0,
    "Parameter Table Defn/target_table/col_y;Y;float;Y Position (cm) of the target relative to  local (0,0);;;none;;",
    "", 0, 0, 1, 0, 0 },

  { 374, 0, "Parameter Table Defn/task_definition/INSTRUCTIONS=",
    "", 0, 0, 1, 0, 0 },

  { 375, 0, "Parameter Table Defn/task_definition/LOAD_FOR=EITHER",
    "", 0, 0, 1, 0, 0 },

  { 376, 0,
    "Parameter Table Defn/task_wide/K_DELAY_FIXED;Delay_Min;integer;Minimum hold delay time at start target (fixed);;;none;;",
    "", 0, 0, 1, 0, 0 },

  { 377, 0,
    "Parameter Table Defn/task_wide/K_DELAY_RAND;Delay_Rand;integer;Maximum additional delay time at start target (random);;;none;;",
    "", 0, 0, 1, 0, 0 },

  { 378, 0,
    "Parameter Table Defn/task_wide/K_PRE_REWARD_DELAY;Delay_PreRewardCue;integer;Time to cue the reward information prior to the trial onset;;;none;;",
    "", 0, 0, 1, 0, 0 },

  { 379, 0,
    "Parameter Table Defn/task_wide/K_REWARD_VAL;Reward_Value;integer;One unit of reward;;;none;;",
    "", 0, 0, 1, 0, 0 },

  { 380, 0,
    "Parameter Table Defn/task_wide/K_SCORETEXT_ROW;Feedback_Text_TgtTable_Row;integer;Target number to be used to set the feedback text;;;none;;",
    "", 0, 0, 1, 0, 0 },

  { 381, 0,
    "Parameter Table Defn/task_wide/K_THRESH_VELMAX;Vel_Min_Thresh;float;Minimum velocity that must be exceeded for trial to be considered successful;;;none;;",
    "", 0, 0, 1, 0, 0 },

  { 382, 0,
    "Parameter Table Defn/task_wide/K_TRIGGER_POS;Trigger_Pos;float;Position Threshold for triggering target reveal;;;none;;",
    "", 0, 0, 1, 0, 0 },

  { 383, 0,
    "Parameter Table Defn/task_wide/K_TRIGGER_VEL;Trigger_Vel;float;Velocity Threshold for triggering target reveal;;;none;;",
    "", 0, 0, 1, 0, 0 },

  { 384, 187, "Process_Video_CMD/Add_requested_Delay/MATLAB Function",
    "delay", 0, 0, 1, 0, 0 },

  { 385, 0, "Process_Video_CMD/Add_requested_Delay/Rate Transition1",
    "", 0, 0, 1, 0, 3 },

  { 386, 0, "Process_Video_CMD/Add_requested_Delay/Rate Transition2",
    "", 0, 0, 1, 0, 3 },

  { 387, 0, "Process_Video_CMD/Add_requested_Delay/S-Function Builder/p1",
    "", 0, 5, 49, 0, 3 },

  { 388, 0, "Process_Video_CMD/Add_requested_Delay/S-Function Builder/p2",
    "", 1, 0, 1, 0, 3 },

  { 389, 0, "Process_Video_CMD/Add_requested_Delay/S-Function Builder/p3",
    "", 2, 0, 50, 0, 3 },

  { 390, 189, "Process_Video_CMD/PVC_core/Pack VCodeFrame2/p1",
    "vis_cmd", 0, 3, 51, 0, 3 },

  { 391, 189, "Process_Video_CMD/PVC_core/Pack VCodeFrame2/p2",
    "vis_cmd_len", 1, 0, 1, 0, 3 },

  { 392, 189, "Process_Video_CMD/PVC_core/Pack VCodeFrame2/p3",
    "vis_cmd_cropped", 2, 0, 1, 0, 3 },

  { 393, 189, "Process_Video_CMD/PVC_core/Pack VCodeFrame2/p4",
    "frame_number", 3, 4, 1, 0, 3 },

  { 394, 189, "Process_Video_CMD/PVC_core/Pack VCodeFrame2/p5",
    "vcode_err_id", 4, 0, 1, 0, 3 },

  { 395, 190, "Process_Video_CMD/PVC_core/Convert",
    "", 0, 0, 1, 0, 3 },

  { 396, 190, "Process_Video_CMD/PVC_core/Rate Transition1",
    "", 0, 0, 1, 0, 0 },

  { 397, 4,
    "DataLogging/Create KINARM Data Subsystem/select KINData/MATLAB Function",
    "dd_out", 0, 0, 2, 0, 0 },

  { 398, 0,
    "DataLogging/Create Task State Subsystem/Counter Free-Running/Output",
    "", 0, 4, 1, 0, 2 },

  { 399, 0, "DataLogging/Create Task State Subsystem/If Running/Compare",
    "", 0, 5, 1, 0, 0 },

  { 400, 6,
    "DataLogging/Network Transfer Subsystem/Data Packing Subsystem/Data Type Conversion",
    "", 0, 6, 52, 0, 2 },

  { 401, 6,
    "DataLogging/Network Transfer Subsystem/Data Packing Subsystem/Ideal Frames Per Packet",
    "", 0, 0, 1, 0, 2 },

  { 402, 6,
    "DataLogging/Network Transfer Subsystem/Data Packing Subsystem/Math Function",
    "", 0, 0, 1, 0, 2 },

  { 403, 6, "DataLogging/Network Transfer Subsystem/Data Packing Subsystem/t-1",
    "", 0, 6, 52, 0, 2 },

  { 404, 6, "DataLogging/Network Transfer Subsystem/Data Packing Subsystem/t-2",
    "", 0, 6, 52, 0, 2 },

  { 405, 6,
    "DataLogging/Network Transfer Subsystem/Data Packing Subsystem/MinMax",
    "", 0, 0, 1, 0, 2 },

  { 406, 6,
    "DataLogging/Network Transfer Subsystem/Data Packing Subsystem/Product",
    "", 0, 0, 1, 0, 2 },

  { 407, 6,
    "DataLogging/Network Transfer Subsystem/Data Packing Subsystem/Relational Operator",
    "", 0, 2, 1, 0, 2 },

  { 408, 6,
    "DataLogging/Network Transfer Subsystem/Data Packing Subsystem/Selector",
    "", 0, 6, 53, 0, 2 },

  { 409, 6,
    "DataLogging/Network Transfer Subsystem/Data Packing Subsystem/Subtract",
    "", 0, 0, 1, 0, 2 },

  { 410, 6,
    "DataLogging/Network Transfer Subsystem/Data Packing Subsystem/Width",
    "", 0, 0, 1, 0, 2 },

  { 411, 10,
    "DataLogging/Network Transfer Subsystem/UDP Receiver/Data Type Conversion",
    "", 0, 4, 1, 0, 0 },

  { 412, 10, "DataLogging/Network Transfer Subsystem/UDP Receiver/Memory2",
    "trigger", 0, 0, 1, 0, 0 },

  { 413, 10,
    "DataLogging/Network Transfer Subsystem/UDP Receiver/Rate Transition1",
    "Rqst UDP Reset", 0, 0, 1, 0, 2 },

  { 414, 10,
    "DataLogging/Network Transfer Subsystem/UDP Receiver/Rate Transition2",
    "", 0, 0, 41, 0, 0 },

  { 415, 10,
    "DataLogging/Network Transfer Subsystem/UDP Receiver/UDP Receive/p1",
    "Data", 0, 5, 54, 0, 0 },

  { 416, 10,
    "DataLogging/Network Transfer Subsystem/UDP Receiver/UDP Receive/p2",
    "Pckt_Recd", 1, 0, 1, 0, 0 },

  { 417, 10,
    "DataLogging/Network Transfer Subsystem/UDP Receiver/UDP Receive/p3",
    "Data 2", 2, 5, 54, 0, 0 },

  { 418, 10,
    "DataLogging/Network Transfer Subsystem/UDP Receiver/UDP Receive/p4",
    "Pckt_Recd 2", 3, 0, 1, 0, 0 },

  { 419, 10,
    "DataLogging/Network Transfer Subsystem/UDP Receiver/UDP Receive/p5",
    "# double reads", 4, 0, 1, 0, 0 },

  { 420, 10,
    "DataLogging/Network Transfer Subsystem/UDP Receiver/UDP Receive/p6",
    "", 5, 0, 1, 0, 0 },

  { 421, 10,
    "DataLogging/Network Transfer Subsystem/UDP Receiver/UDP Receive Port Reset/p1",
    "# UDP Resets", 0, 0, 1, 0, 2 },

  { 422, 10,
    "DataLogging/Network Transfer Subsystem/UDP Receiver/UDP Receive Port Reset/p2",
    "", 1, 0, 41, 0, 2 },

  { 423, 10, "DataLogging/Network Transfer Subsystem/UDP Receiver/Unpack",
    "", 0, 6, 1, 0, 0 },

  { 424, 8, "DataLogging/Network Transfer Subsystem/UDP Send Subsystem/Pack",
    "", 0, 5, 55, 0, 1 },

  { 425, 11, "DataLogging/Poll Force Plates/plate1/parse packet 1/p1",
    "forces", 0, 0, 41, 0, 0 },

  { 426, 11, "DataLogging/Poll Force Plates/plate1/parse packet 1/p2",
    "moments", 1, 0, 41, 0, 0 },

  { 427, 11, "DataLogging/Poll Force Plates/plate1/parse packet 1/p3",
    "timer", 2, 0, 1, 0, 0 },

  { 428, 12, "DataLogging/Poll Force Plates/plate1/Receive/p1",
    "", 0, 5, 56, 0, 0 },

  { 429, 12, "DataLogging/Poll Force Plates/plate1/Receive/p2",
    "", 1, 0, 1, 0, 0 },

  { 430, 13, "DataLogging/Poll Force Plates/plate2/parse packet 1/p1",
    "forces", 0, 0, 41, 0, 0 },

  { 431, 13, "DataLogging/Poll Force Plates/plate2/parse packet 1/p2",
    "moments", 1, 0, 41, 0, 0 },

  { 432, 13, "DataLogging/Poll Force Plates/plate2/parse packet 1/p3",
    "timer", 2, 0, 1, 0, 0 },

  { 433, 14, "DataLogging/Poll Force Plates/plate2/Receive1/p1",
    "", 0, 5, 56, 0, 0 },

  { 434, 14, "DataLogging/Poll Force Plates/plate2/Receive1/p2",
    "", 1, 0, 1, 0, 0 },

  { 435, 100, "DataLogging/Poll KINARM/EtherCAT Subsystem/latch_errors/p1",
    "errVals", 0, 0, 57, 0, 0 },

  { 436, 100, "DataLogging/Poll KINARM/EtherCAT Subsystem/latch_errors/p2",
    "DCErrVals", 1, 0, 57, 0, 0 },

  { 437, 101, "DataLogging/Poll KINARM/EtherCAT Subsystem/sdo_addrs/p1",
    "intAddresses", 0, 0, 58, 0, 0 },

  { 438, 101, "DataLogging/Poll KINARM/EtherCAT Subsystem/sdo_addrs/p2",
    "floatAddresses", 1, 0, 58, 0, 0 },

  { 439, 102, "DataLogging/Poll KINARM/EtherCAT Subsystem/setState",
    "motorEnableState", 0, 2, 1, 0, 0 },

  { 440, 150, "DataLogging/Poll KINARM/EtherCAT Subsystem/Data Type Conversion",
    "", 0, 0, 1, 0, 0 },

  { 441, 150, "DataLogging/Poll KINARM/EtherCAT Subsystem/convert",
    "", 0, 0, 11, 0, 0 },

  { 442, 150, "DataLogging/Poll KINARM/EtherCAT Subsystem/BKIN EtherCATinit/p1",
    "", 0, 3, 34, 0, 0 },

  { 443, 150, "DataLogging/Poll KINARM/EtherCAT Subsystem/BKIN EtherCATinit/p2",
    "", 1, 3, 1, 0, 0 },

  { 444, 150, "DataLogging/Poll KINARM/EtherCAT Subsystem/BKIN EtherCATinit/p3",
    "", 2, 3, 1, 0, 0 },

  { 445, 150, "DataLogging/Poll KINARM/EtherCAT Subsystem/BKIN EtherCATinit1/p1",
    "", 0, 3, 34, 0, 0 },

  { 446, 150, "DataLogging/Poll KINARM/EtherCAT Subsystem/BKIN EtherCATinit1/p2",
    "", 1, 3, 1, 0, 0 },

  { 447, 150, "DataLogging/Poll KINARM/EtherCAT Subsystem/BKIN EtherCATinit1/p3",
    "", 2, 3, 1, 0, 0 },

  { 448, 150, "DataLogging/Poll KINARM/EtherCAT Subsystem/Switch",
    "", 0, 3, 11, 0, 0 },

  { 449, 141,
    "DataLogging/Poll KINARM/createKINData/Create KINARM Data Array/p1",
    "kinarm_data", 0, 0, 59, 0, 1 },

  { 450, 141,
    "DataLogging/Poll KINARM/createKINData/Create KINARM Data Array/p2",
    "primary_encoder_data_out", 1, 0, 60, 0, 1 },

  { 451, 142, "DataLogging/Poll KINARM/createKINData/bitpack",
    "statusInts", 0, 4, 32, 0, 1 },

  { 452, 143, "DataLogging/Poll KINARM/createKINData/record errors/p1",
    "newMessage", 0, 0, 61, 0, 1 },

  { 453, 143, "DataLogging/Poll KINARM/createKINData/record errors/p2",
    "sentMessageCount", 1, 0, 1, 0, 1 },

  { 454, 144, "DataLogging/Poll KINARM/createKINData/Data Store Read",
    "", 0, 4, 1, 0, 1 },

  { 455, 144, "DataLogging/Poll KINARM/createKINData/Delay Read",
    "", 0, 0, 3, 0, 1 },

  { 456, 144, "DataLogging/Poll KINARM/createKINData/ErrMsgs",
    "", 0, 0, 62, 0, 1 },

  { 457, 144, "DataLogging/Poll KINARM/createKINData/Primary read",
    "", 0, 0, 57, 0, 1 },

  { 458, 144, "DataLogging/Poll KINARM/createKINData/Read",
    "", 0, 0, 63, 0, 1 },

  { 459, 144, "DataLogging/Poll KINARM/createKINData/Read HW",
    "", 0, 0, 64, 0, 1 },

  { 460, 144, "DataLogging/Poll KINARM/createKINData/Read Kinematics",
    "", 0, 0, 6, 0, 1 },

  { 461, 144, "DataLogging/Poll KINARM/createKINData/Servo Read",
    "", 0, 4, 1, 0, 1 },

  { 462, 144, "DataLogging/Poll KINARM/createKINData/Status read",
    "", 0, 4, 65, 0, 1 },

  { 463, 144, "DataLogging/Poll KINARM/createKINData/Status read1",
    "", 0, 4, 11, 0, 1 },

  { 464, 144, "DataLogging/Poll KINARM/createKINData/torque feedback1",
    "", 0, 0, 11, 0, 1 },

  { 465, 144, "DataLogging/Poll KINARM/createKINData/Data Type Conversion",
    "", 0, 4, 61, 0, 1 },

  { 466, 150, "DataLogging/Poll KINARM/isecat/Compare",
    "", 0, 2, 1, 0, 0 },

  { 467, 150, "DataLogging/Poll KINARM/ispmac/Compare",
    "", 0, 2, 1, 0, 0 },

  { 468, 145, "DataLogging/Poll KINARM/make KINData bus/splitKINData arm1/p1",
    "link_lengths", 0, 0, 8, 0, 0 },

  { 469, 145, "DataLogging/Poll KINARM/make KINData bus/splitKINData arm1/p2",
    "pointer_offset", 1, 0, 1, 0, 0 },

  { 470, 145, "DataLogging/Poll KINARM/make KINData bus/splitKINData arm1/p3",
    "shoulder_loc", 2, 0, 8, 0, 0 },

  { 471, 145, "DataLogging/Poll KINARM/make KINData bus/splitKINData arm1/p4",
    "arm_orientation", 3, 0, 1, 0, 0 },

  { 472, 145, "DataLogging/Poll KINARM/make KINData bus/splitKINData arm1/p5",
    "shoulder_ang", 4, 0, 1, 0, 0 },

  { 473, 145, "DataLogging/Poll KINARM/make KINData bus/splitKINData arm1/p6",
    "elbow_ang", 5, 0, 1, 0, 0 },

  { 474, 145, "DataLogging/Poll KINARM/make KINData bus/splitKINData arm1/p7",
    "shoulder_velocity", 6, 0, 1, 0, 0 },

  { 475, 145, "DataLogging/Poll KINARM/make KINData bus/splitKINData arm1/p8",
    "elbow_velocity", 7, 0, 1, 0, 0 },

  { 476, 145, "DataLogging/Poll KINARM/make KINData bus/splitKINData arm1/p9",
    "shoulder_acceleration", 8, 0, 1, 0, 0 },

  { 477, 145, "DataLogging/Poll KINARM/make KINData bus/splitKINData arm1/p10",
    "elbow_acceleration", 9, 0, 1, 0, 0 },

  { 478, 145, "DataLogging/Poll KINARM/make KINData bus/splitKINData arm1/p11",
    "joint_torque_cmd", 10, 0, 8, 0, 0 },

  { 479, 145, "DataLogging/Poll KINARM/make KINData bus/splitKINData arm1/p12",
    "motor_torque_cmd", 11, 0, 8, 0, 0 },

  { 480, 145, "DataLogging/Poll KINARM/make KINData bus/splitKINData arm1/p13",
    "link_angle", 12, 0, 8, 0, 0 },

  { 481, 145, "DataLogging/Poll KINARM/make KINData bus/splitKINData arm1/p14",
    "link_velocity", 13, 0, 8, 0, 0 },

  { 482, 145, "DataLogging/Poll KINARM/make KINData bus/splitKINData arm1/p15",
    "link_acceleration", 14, 0, 8, 0, 0 },

  { 483, 145, "DataLogging/Poll KINARM/make KINData bus/splitKINData arm1/p16",
    "hand_position", 15, 0, 8, 0, 0 },

  { 484, 145, "DataLogging/Poll KINARM/make KINData bus/splitKINData arm1/p17",
    "hand_velocity", 16, 0, 8, 0, 0 },

  { 485, 145, "DataLogging/Poll KINARM/make KINData bus/splitKINData arm1/p18",
    "hand_acceleration", 17, 0, 8, 0, 0 },

  { 486, 145, "DataLogging/Poll KINARM/make KINData bus/splitKINData arm1/p19",
    "motor_status", 18, 0, 1, 0, 0 },

  { 487, 145, "DataLogging/Poll KINARM/make KINData bus/splitKINData arm1/p20",
    "force_sensor_force_uvw", 19, 0, 7, 0, 0 },

  { 488, 145, "DataLogging/Poll KINARM/make KINData bus/splitKINData arm1/p21",
    "force_sensor_torque_uvw", 20, 0, 7, 0, 0 },

  { 489, 145, "DataLogging/Poll KINARM/make KINData bus/splitKINData arm1/p22",
    "force_sensor_force_xyz", 21, 0, 7, 0, 0 },

  { 490, 145, "DataLogging/Poll KINARM/make KINData bus/splitKINData arm1/p23",
    "force_sensor_torque_xyz", 22, 0, 7, 0, 0 },

  { 491, 145, "DataLogging/Poll KINARM/make KINData bus/splitKINData arm1/p24",
    "force_sensor_timestamp", 23, 0, 1, 0, 0 },

  { 492, 146, "DataLogging/Poll KINARM/make KINData bus/splitKINData arm2/p1",
    "link_lengths", 0, 0, 8, 0, 0 },

  { 493, 146, "DataLogging/Poll KINARM/make KINData bus/splitKINData arm2/p2",
    "pointer_offset", 1, 0, 1, 0, 0 },

  { 494, 146, "DataLogging/Poll KINARM/make KINData bus/splitKINData arm2/p3",
    "shoulder_loc", 2, 0, 8, 0, 0 },

  { 495, 146, "DataLogging/Poll KINARM/make KINData bus/splitKINData arm2/p4",
    "arm_orientation", 3, 0, 1, 0, 0 },

  { 496, 146, "DataLogging/Poll KINARM/make KINData bus/splitKINData arm2/p5",
    "shoulder_ang", 4, 0, 1, 0, 0 },

  { 497, 146, "DataLogging/Poll KINARM/make KINData bus/splitKINData arm2/p6",
    "elbow_ang", 5, 0, 1, 0, 0 },

  { 498, 146, "DataLogging/Poll KINARM/make KINData bus/splitKINData arm2/p7",
    "shoulder_velocity", 6, 0, 1, 0, 0 },

  { 499, 146, "DataLogging/Poll KINARM/make KINData bus/splitKINData arm2/p8",
    "elbow_velocity", 7, 0, 1, 0, 0 },

  { 500, 146, "DataLogging/Poll KINARM/make KINData bus/splitKINData arm2/p9",
    "shoulder_acceleration", 8, 0, 1, 0, 0 },

  { 501, 146, "DataLogging/Poll KINARM/make KINData bus/splitKINData arm2/p10",
    "elbow_acceleration", 9, 0, 1, 0, 0 },

  { 502, 146, "DataLogging/Poll KINARM/make KINData bus/splitKINData arm2/p11",
    "joint_torque_cmd", 10, 0, 8, 0, 0 },

  { 503, 146, "DataLogging/Poll KINARM/make KINData bus/splitKINData arm2/p12",
    "motor_torque_cmd", 11, 0, 8, 0, 0 },

  { 504, 146, "DataLogging/Poll KINARM/make KINData bus/splitKINData arm2/p13",
    "link_angle", 12, 0, 8, 0, 0 },

  { 505, 146, "DataLogging/Poll KINARM/make KINData bus/splitKINData arm2/p14",
    "link_velocity", 13, 0, 8, 0, 0 },

  { 506, 146, "DataLogging/Poll KINARM/make KINData bus/splitKINData arm2/p15",
    "link_acceleration", 14, 0, 8, 0, 0 },

  { 507, 146, "DataLogging/Poll KINARM/make KINData bus/splitKINData arm2/p16",
    "hand_position", 15, 0, 8, 0, 0 },

  { 508, 146, "DataLogging/Poll KINARM/make KINData bus/splitKINData arm2/p17",
    "hand_velocity", 16, 0, 8, 0, 0 },

  { 509, 146, "DataLogging/Poll KINARM/make KINData bus/splitKINData arm2/p18",
    "hand_acceleration", 17, 0, 8, 0, 0 },

  { 510, 146, "DataLogging/Poll KINARM/make KINData bus/splitKINData arm2/p19",
    "motor_status", 18, 0, 1, 0, 0 },

  { 511, 146, "DataLogging/Poll KINARM/make KINData bus/splitKINData arm2/p20",
    "force_sensor_force_uvw", 19, 0, 7, 0, 0 },

  { 512, 146, "DataLogging/Poll KINARM/make KINData bus/splitKINData arm2/p21",
    "force_sensor_torque_uvw", 20, 0, 7, 0, 0 },

  { 513, 146, "DataLogging/Poll KINARM/make KINData bus/splitKINData arm2/p22",
    "force_sensor_force_xyz", 21, 0, 7, 0, 0 },

  { 514, 146, "DataLogging/Poll KINARM/make KINData bus/splitKINData arm2/p23",
    "force_sensor_torque_xyz", 22, 0, 7, 0, 0 },

  { 515, 146, "DataLogging/Poll KINARM/make KINData bus/splitKINData arm2/p24",
    "force_sensor_timestamp", 23, 0, 1, 0, 0 },

  { 516, 147, "DataLogging/Poll KINARM/make KINData bus/splitKINDataGeneral/p1",
    "active_arm", 0, 0, 1, 0, 0 },

  { 517, 147, "DataLogging/Poll KINARM/make KINData bus/splitKINDataGeneral/p2",
    "delayEstimates", 1, 0, 32, 0, 0 },

  { 518, 147, "DataLogging/Poll KINARM/make KINData bus/splitKINDataGeneral/p3",
    "servoCounter", 2, 0, 1, 0, 0 },

  { 519, 147, "DataLogging/Poll KINARM/make KINData bus/splitKINDataGeneral/p4",
    "calibrationButtonBits", 3, 0, 1, 0, 0 },

  { 520, 147, "DataLogging/Poll KINARM/make KINData bus/splitKINDataGeneral/p5",
    "handFF", 4, 0, 1, 0, 0 },

  { 521, 147, "DataLogging/Poll KINARM/make KINData bus/splitKINDataGeneral/p6",
    "handFF_Dex", 5, 0, 1, 0, 0 },

  { 522, 147, "DataLogging/Poll KINARM/make KINData bus/splitKINDataGeneral/p7",
    "handFBArm", 6, 0, 1, 0, 0 },

  { 523, 147, "DataLogging/Poll KINARM/make KINData bus/splitKINDataGeneral/p8",
    "handFBRadius", 7, 0, 1, 0, 0 },

  { 524, 147, "DataLogging/Poll KINARM/make KINData bus/splitKINDataGeneral/p9",
    "handFBControl", 8, 0, 1, 0, 0 },

  { 525, 147, "DataLogging/Poll KINARM/make KINData bus/splitKINDataGeneral/p10",
    "handFBColor", 9, 0, 1, 0, 0 },

  { 526, 147, "DataLogging/Poll KINARM/make KINData bus/splitKINDataGeneral/p11",
    "hasGaze", 10, 0, 1, 0, 0 },

  { 527, 147, "DataLogging/Poll KINARM/make KINData bus/splitKINDataGeneral/p12",
    "gazeFB", 11, 0, 1, 0, 0 },

  { 528, 147, "DataLogging/Poll KINARM/make KINData bus/splitKINDataGeneral/p13",
    "gazeLocation", 12, 0, 8, 0, 0 },

  { 529, 147, "DataLogging/Poll KINARM/make KINData bus/splitKINDataGeneral/p14",
    "gazeTimestamp", 13, 0, 1, 0, 0 },

  { 530, 147, "DataLogging/Poll KINARM/make KINData bus/splitKINDataGeneral/p15",
    "gazePupilArea", 14, 0, 1, 0, 0 },

  { 531, 147, "DataLogging/Poll KINARM/make KINData bus/splitKINDataGeneral/p16",
    "gazeEvent", 15, 0, 7, 0, 0 },

  { 532, 147, "DataLogging/Poll KINARM/make KINData bus/splitKINDataGeneral/p17",
    "gazeVector", 16, 0, 7, 0, 0 },

  { 533, 147, "DataLogging/Poll KINARM/make KINData bus/splitKINDataGeneral/p18",
    "gazePupilLoc", 17, 0, 7, 0, 0 },

  { 534, 150, "DataLogging/Poll KINARM/make KINData bus/Selector",
    "", 0, 0, 22, 0, 0 },

  { 535, 150, "DataLogging/Poll KINARM/make KINData bus/Selector1",
    "", 0, 0, 22, 0, 0 },

  { 536, 150, "DataLogging/Poll KINARM/make KINData bus/Selector2",
    "", 0, 0, 22, 0, 0 },

  { 537, 148, "DataLogging/Poll KINARM/split_primary/split_primary/p1",
    "link_angles", 0, 0, 8, 0, 0 },

  { 538, 148, "DataLogging/Poll KINARM/split_primary/split_primary/p2",
    "link_velocities", 1, 0, 8, 0, 0 },

  { 539, 148, "DataLogging/Poll KINARM/split_primary/split_primary/p3",
    "link_acceleration", 2, 0, 8, 0, 0 },

  { 540, 149, "DataLogging/Poll KINARM/split_primary/split_primary1/p1",
    "link_angles", 0, 0, 8, 0, 0 },

  { 541, 149, "DataLogging/Poll KINARM/split_primary/split_primary1/p2",
    "link_velocities", 1, 0, 8, 0, 0 },

  { 542, 149, "DataLogging/Poll KINARM/split_primary/split_primary1/p3",
    "link_acceleration", 2, 0, 8, 0, 0 },

  { 543, 150, "DataLogging/Poll KINARM/split_primary/Selector1",
    "", 0, 0, 61, 0, 0 },

  { 544, 150, "DataLogging/Poll KINARM/split_primary/Selector2",
    "", 0, 0, 61, 0, 0 },

  { 545, 156, "DataLogging/apply loads/EtherCAT Apply Loads/convert torques",
    "ecatTorques", 0, 7, 32, 0, 0 },

  { 546, 157, "DataLogging/apply loads/EtherCAT Apply Loads/Data Store Read",
    "", 0, 0, 37, 0, 0 },

  { 547, 158, "DataLogging/apply loads/apply pmac loads/Data Type Conversion",
    "", 0, 6, 34, 0, 0 },

  { 548, 158, "DataLogging/apply loads/apply pmac loads/Data Type Conversion1",
    "", 0, 6, 34, 0, 0 },

  { 549, 158, "DataLogging/apply loads/apply pmac loads/Data Type Conversion6",
    "", 0, 6, 3, 0, 0 },

  { 550, 158, "DataLogging/apply loads/apply pmac loads/Product",
    "", 0, 0, 3, 0, 0 },

  { 551, 159, "DataLogging/apply loads/isecat/Compare",
    "", 0, 2, 1, 0, 0 },

  { 552, 159, "DataLogging/apply loads/isecat1/Compare",
    "", 0, 2, 1, 0, 0 },

  { 553, 161, "DataLogging/create_lab_info/Subsystem/MATLAB Function/p1",
    "is_right_arm", 0, 0, 1, 0, 0 },

  { 554, 161, "DataLogging/create_lab_info/Subsystem/MATLAB Function/p2",
    "isExo", 1, 0, 1, 0, 0 },

  { 555, 161, "DataLogging/create_lab_info/Subsystem/MATLAB Function/p3",
    "has_high_res_encoders", 2, 0, 1, 0, 0 },

  { 556, 162, "DataLogging/create_lab_info/Subsystem/MATLAB Function1/p1",
    "is_right_arm", 0, 0, 1, 0, 0 },

  { 557, 162, "DataLogging/create_lab_info/Subsystem/MATLAB Function1/p2",
    "isExo", 1, 0, 1, 0, 0 },

  { 558, 162, "DataLogging/create_lab_info/Subsystem/MATLAB Function1/p3",
    "has_high_res_encoders", 2, 0, 1, 0, 0 },

  { 559, 171,
    "GUI Control/Task Execution Control Subsystem/Compare To Constant/Compare",
    "", 0, 5, 1, 0, 0 },

  { 560, 0,
    "DataLogging/Create Task State Subsystem/Counter Free-Running/Increment Real World/FixPt Sum1",
    "", 0, 4, 1, 0, 2 },

  { 561, 0,
    "DataLogging/Create Task State Subsystem/Counter Free-Running/Wrap To Zero/FixPt Switch",
    "", 0, 4, 1, 0, 2 },

  { 562, 6,
    "DataLogging/Network Transfer Subsystem/Data Packing Subsystem/Counter/Sum",
    "", 0, 0, 1, 0, 2 },

  { 563, 6,
    "DataLogging/Network Transfer Subsystem/Data Packing Subsystem/Counter/Unit Delay",
    "", 0, 0, 1, 0, 2 },

  { 564, 8,
    "DataLogging/Network Transfer Subsystem/UDP Send Subsystem/Counter Free-Running/Output",
    "", 0, 4, 1, 0, 1 },

  { 565, 34, "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/Find Robot type",
    "robotType", 0, 0, 1, 0, 0 },

  { 566, 41,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/SDO read machine/p1",
    "SDOCommand", 0, 3, 41, 0, 0 },

  { 567, 41,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/SDO read machine/p2",
    "intSDOValues", 1, 3, 6, 0, 0 },

  { 568, 41,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/SDO read machine/p3",
    "floatSDOValues", 2, 0, 6, 0, 0 },

  { 569, 41,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/SDO read machine/p4",
    "complete", 3, 3, 1, 0, 0 },

  { 570, 50,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/forceEnableDisable",
    "forceMotorState", 0, 0, 1, 0, 0 },

  { 571, 53, "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/size",
    "count", 0, 0, 1, 0, 0 },

  { 572, 54, "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/size1",
    "count", 0, 0, 1, 0, 0 },

  { 573, 55,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/split out constants/p1",
    "encoderCounts", 0, 0, 8, 0, 0 },

  { 574, 55,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/split out constants/p2",
    "FTSensorOffset", 1, 0, 1, 0, 0 },

  { 575, 55,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/split out constants/p3",
    "calibPinAngles", 2, 0, 8, 0, 0 },

  { 576, 55,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/split out constants/p4",
    "absAngOffsets", 3, 0, 8, 0, 0 },

  { 577, 55,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/split out constants/p5",
    "linkLengths", 4, 0, 8, 0, 0 },

  { 578, 55,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/split out constants/p6",
    "L2CalibPinOffset", 5, 0, 1, 0, 0 },

  { 579, 55,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/split out constants/p7",
    "continuousTorques", 6, 0, 8, 0, 0 },

  { 580, 55,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/split out constants/p8",
    "gearRatios", 7, 0, 8, 0, 0 },

  { 581, 55,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/split out constants/p9",
    "isCalibrated", 8, 0, 1, 0, 0 },

  { 582, 55,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/split out constants/p10",
    "offsetRads", 9, 0, 8, 0, 0 },

  { 583, 55,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/split out constants/p11",
    "offsetRadsPrimary", 10, 0, 8, 0, 0 },

  { 584, 55,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/split out constants/p12",
    "robotRevision", 11, 0, 1, 0, 0 },

  { 585, 55,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/split out constants/p13",
    "constantsReady", 12, 0, 1, 0, 0 },

  { 586, 56,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/split out constants1/p1",
    "hasSecondary", 0, 0, 1, 0, 0 },

  { 587, 56,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/split out constants1/p2",
    "hasFT", 1, 0, 1, 0, 0 },

  { 588, 56,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/split out constants1/p3",
    "robotOrientation", 2, 0, 1, 0, 0 },

  { 589, 56,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/split out constants1/p4",
    "motorOrientation", 3, 0, 8, 0, 0 },

  { 590, 56,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/split out constants1/p5",
    "encOrientation", 4, 0, 8, 0, 0 },

  { 591, 57, "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/Torque Mode",
    "", 0, 8, 1, 0, 0 },

  { 592, 57, "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/readTrigger",
    "", 0, 3, 1, 0, 0 },

  { 593, 57, "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/Memory2",
    "R1_maxContinuousTorque", 0, 0, 8, 0, 0 },

  { 594, 57, "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/Memory3",
    "R1_constantsReady", 0, 0, 1, 0, 0 },

  { 595, 74, "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/Find Robot type",
    "robotType", 0, 0, 1, 0, 0 },

  { 596, 81,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/SDO read machine/p1",
    "SDOCommand", 0, 3, 41, 0, 0 },

  { 597, 81,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/SDO read machine/p2",
    "intSDOValues", 1, 3, 6, 0, 0 },

  { 598, 81,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/SDO read machine/p3",
    "floatSDOValues", 2, 0, 6, 0, 0 },

  { 599, 81,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/SDO read machine/p4",
    "complete", 3, 3, 1, 0, 0 },

  { 600, 90,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/forceEnableDisable",
    "forceMotorState", 0, 0, 1, 0, 0 },

  { 601, 93, "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/size",
    "count", 0, 0, 1, 0, 0 },

  { 602, 94, "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/size1",
    "count", 0, 0, 1, 0, 0 },

  { 603, 95,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/split out constants/p1",
    "encoderCounts", 0, 0, 8, 0, 0 },

  { 604, 95,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/split out constants/p2",
    "FTSensorOffset", 1, 0, 1, 0, 0 },

  { 605, 95,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/split out constants/p3",
    "calibPinAngles", 2, 0, 8, 0, 0 },

  { 606, 95,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/split out constants/p4",
    "absAngOffsets", 3, 0, 8, 0, 0 },

  { 607, 95,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/split out constants/p5",
    "linkLengths", 4, 0, 8, 0, 0 },

  { 608, 95,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/split out constants/p6",
    "L2CalibPinOffset", 5, 0, 1, 0, 0 },

  { 609, 95,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/split out constants/p7",
    "continuousTorques", 6, 0, 8, 0, 0 },

  { 610, 95,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/split out constants/p8",
    "gearRatios", 7, 0, 8, 0, 0 },

  { 611, 95,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/split out constants/p9",
    "isCalibrated", 8, 0, 1, 0, 0 },

  { 612, 95,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/split out constants/p10",
    "offsetRads", 9, 0, 8, 0, 0 },

  { 613, 95,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/split out constants/p11",
    "offsetRadsPrimary", 10, 0, 8, 0, 0 },

  { 614, 95,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/split out constants/p12",
    "robotRevision", 11, 0, 1, 0, 0 },

  { 615, 95,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/split out constants/p13",
    "constantsReady", 12, 0, 1, 0, 0 },

  { 616, 96,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/split out constants1/p1",
    "hasSecondary", 0, 0, 1, 0, 0 },

  { 617, 96,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/split out constants1/p2",
    "hasFT", 1, 0, 1, 0, 0 },

  { 618, 96,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/split out constants1/p3",
    "robotOrientation", 2, 0, 1, 0, 0 },

  { 619, 96,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/split out constants1/p4",
    "motorOrientation", 3, 0, 8, 0, 0 },

  { 620, 96,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/split out constants1/p5",
    "encOrientation", 4, 0, 8, 0, 0 },

  { 621, 97, "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/Torque Mode",
    "", 0, 8, 1, 0, 0 },

  { 622, 97, "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/readTrigger",
    "", 0, 3, 1, 0, 0 },

  { 623, 97, "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/Memory2",
    "R2_maxContinuousTorque", 0, 0, 8, 0, 0 },

  { 624, 97, "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/Memory3",
    "R2_constantsReady", 0, 0, 1, 0, 0 },

  { 625, 150, "DataLogging/Poll KINARM/EtherCAT Subsystem/Compare/Compare",
    "", 0, 5, 1, 0, 0 },

  { 626, 150,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Counter Free-Running/Output",
    "", 0, 4, 1, 0, 0 },

  { 627, 98,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Digital output/update digital outputs/p1",
    "drive1", 0, 4, 1, 0, 0 },

  { 628, 98,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Digital output/update digital outputs/p2",
    "drive2", 1, 4, 1, 0, 0 },

  { 629, 98,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Digital output/update digital outputs/p3",
    "drive3", 2, 4, 1, 0, 0 },

  { 630, 98,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Digital output/update digital outputs/p4",
    "drive4", 3, 4, 1, 0, 0 },

  { 631, 99,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Init to Bus/split init/p1",
    "errVal", 0, 3, 1, 0, 0 },

  { 632, 99,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Init to Bus/split init/p2",
    "masterState", 1, 3, 1, 0, 0 },

  { 633, 99,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Init to Bus/split init/p3",
    "DCErrVal", 2, 3, 1, 0, 0 },

  { 634, 99,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Init to Bus/split init/p4",
    "MasterToNetworkClkDiff", 3, 3, 1, 0, 0 },

  { 635, 99,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Init to Bus/split init/p5",
    "DCInitState", 4, 3, 1, 0, 0 },

  { 636, 99,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Init to Bus/split init/p6",
    "NetworkToSlaveClkDiff", 5, 3, 1, 0, 0 },

  { 637, 103,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/update/convert to bit field",
    "bitField", 0, 4, 1, 0, 1 },

  { 638, 106,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/update/create kinematics/p1",
    "kinematicsOut", 0, 0, 66, 0, 1 },

  { 639, 106,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/update/create kinematics/p2",
    "kinematicsOutPrimary", 1, 0, 57, 0, 1 },

  { 640, 106,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/update/create kinematics/p3",
    "delays", 2, 0, 3, 0, 1 },

  { 641, 107,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/update/create servo counter",
    "servoCounterOut", 0, 4, 1, 0, 1 },

  { 642, 108, "DataLogging/Poll KINARM/EtherCAT Subsystem/update/robottype1",
    "outMem", 0, 0, 62, 0, 1 },

  { 643, 109,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/update/update HW settings",
    "settingsOut", 0, 0, 67, 0, 1 },

  { 644, 110,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/update/update calibrations",
    "calibrationsOut", 0, 0, 68, 0, 1 },

  { 645, 111, "DataLogging/Poll KINARM/EtherCAT Subsystem/update/Data Store",
    "", 0, 0, 63, 0, 1 },

  { 646, 111, "DataLogging/Poll KINARM/EtherCAT Subsystem/update/Data Store1",
    "", 0, 0, 64, 0, 1 },

  { 647, 111,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/update/Data Type Conversion",
    "", 0, 4, 69, 0, 1 },

  { 648, 111,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/update/Data Type Conversion1",
    "", 0, 4, 2, 0, 1 },

  { 649, 111,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/update/Data Type Conversion2",
    "", 0, 4, 1, 0, 1 },

  { 650, 111,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/update/Data Type Conversion3",
    "", 0, 0, 3, 0, 1 },

  { 651, 111,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/update/Data Type Conversion4",
    "", 0, 4, 3, 0, 1 },

  { 652, 114,
    "DataLogging/Poll KINARM/Force Sensor Control/Force Sensor 1 Subsystem/Create timestamp",
    "timestamp_out", 0, 0, 1, 0, 0 },

  { 653, 113,
    "DataLogging/Poll KINARM/Force Sensor Control/Force Sensor 1 Subsystem/Data Type Conversion",
    "", 0, 0, 34, 0, 0 },

  { 654, 124,
    "DataLogging/Poll KINARM/Force Sensor Control/Force Sensor 1 Subsystem/Byte Reversal",
    "", 0, 3, 34, 0, 0 },

  { 655, 124,
    "DataLogging/Poll KINARM/Force Sensor Control/Force Sensor 1 Subsystem/Byte Reversal1",
    "", 0, 4, 41, 0, 0 },

  { 656, 124,
    "DataLogging/Poll KINARM/Force Sensor Control/Force Sensor 1 Subsystem/Receive from Robot 1 Force Sensor/p1",
    "", 0, 5, 70, 0, 0 },

  { 657, 124,
    "DataLogging/Poll KINARM/Force Sensor Control/Force Sensor 1 Subsystem/Receive from Robot 1 Force Sensor/p2",
    "", 1, 0, 1, 0, 0 },

  { 658, 124,
    "DataLogging/Poll KINARM/Force Sensor Control/Force Sensor 1 Subsystem/Unpack/p1",
    "", 0, 4, 41, 0, 0 },

  { 659, 124,
    "DataLogging/Poll KINARM/Force Sensor Control/Force Sensor 1 Subsystem/Unpack/p2",
    "", 1, 3, 34, 0, 0 },

  { 660, 124,
    "DataLogging/Poll KINARM/Force Sensor Control/Force Sensor 1 Subsystem/Switch",
    "", 0, 0, 65, 0, 0 },

  { 661, 120,
    "DataLogging/Poll KINARM/Force Sensor Control/Force Sensor 2 Subsystem/Create timestamp",
    "timestamp_out", 0, 0, 1, 0, 0 },

  { 662, 119,
    "DataLogging/Poll KINARM/Force Sensor Control/Force Sensor 2 Subsystem/Data Type Conversion1",
    "", 0, 0, 34, 0, 0 },

  { 663, 124,
    "DataLogging/Poll KINARM/Force Sensor Control/Force Sensor 2 Subsystem/Byte Reversal",
    "", 0, 3, 34, 0, 0 },

  { 664, 124,
    "DataLogging/Poll KINARM/Force Sensor Control/Force Sensor 2 Subsystem/Byte Reversal1",
    "", 0, 4, 41, 0, 0 },

  { 665, 124,
    "DataLogging/Poll KINARM/Force Sensor Control/Force Sensor 2 Subsystem/Receive from Robot 2 Force Sensor/p1",
    "", 0, 5, 70, 0, 0 },

  { 666, 124,
    "DataLogging/Poll KINARM/Force Sensor Control/Force Sensor 2 Subsystem/Receive from Robot 2 Force Sensor/p2",
    "", 1, 0, 1, 0, 0 },

  { 667, 124,
    "DataLogging/Poll KINARM/Force Sensor Control/Force Sensor 2 Subsystem/Unpack1/p1",
    "", 0, 4, 41, 0, 0 },

  { 668, 124,
    "DataLogging/Poll KINARM/Force Sensor Control/Force Sensor 2 Subsystem/Unpack1/p2",
    "", 1, 3, 34, 0, 0 },

  { 669, 124,
    "DataLogging/Poll KINARM/Force Sensor Control/Force Sensor 2 Subsystem/Switch1",
    "", 0, 0, 65, 0, 0 },

  { 670, 128, "DataLogging/Poll KINARM/PMAC Subsystem/read_pmac/Monitor_status",
    "force_scale", 0, 0, 1, 0, 0 },

  { 671, 129,
    "DataLogging/Poll KINARM/PMAC Subsystem/read_pmac/Robot_data_builder/p1",
    "robot1DataOut", 0, 0, 71, 0, 0 },

  { 672, 129,
    "DataLogging/Poll KINARM/PMAC Subsystem/read_pmac/Robot_data_builder/p2",
    "robot2DataOut", 1, 0, 71, 0, 0 },

  { 673, 129,
    "DataLogging/Poll KINARM/PMAC Subsystem/read_pmac/Robot_data_builder/p3",
    "robot1PrimaryEncDataOut", 2, 0, 34, 0, 0 },

  { 674, 129,
    "DataLogging/Poll KINARM/PMAC Subsystem/read_pmac/Robot_data_builder/p4",
    "robot2PrimaryEncDataOut", 3, 0, 34, 0, 0 },

  { 675, 130,
    "DataLogging/Poll KINARM/PMAC Subsystem/read_pmac/filter_velocities/p1",
    "robot1DataOut", 0, 0, 71, 0, 0 },

  { 676, 130,
    "DataLogging/Poll KINARM/PMAC Subsystem/read_pmac/filter_velocities/p2",
    "robot2DataOut", 1, 0, 71, 0, 0 },

  { 677, 131, "DataLogging/Poll KINARM/PMAC Subsystem/read_pmac/Conversion1",
    "", 0, 0, 34, 0, 0 },

  { 678, 131, "DataLogging/Poll KINARM/PMAC Subsystem/read_pmac/Conversion2",
    "", 0, 0, 34, 0, 0 },

  { 679, 131, "DataLogging/Poll KINARM/PMAC Subsystem/read_pmac/Conversion7",
    "", 0, 0, 3, 0, 0 },

  { 680, 131, "DataLogging/Poll KINARM/PMAC Subsystem/read_pmac/Convert2",
    "", 0, 4, 41, 0, 0 },

  { 681, 131,
    "DataLogging/Poll KINARM/PMAC Subsystem/read_pmac/Data Type Conversion",
    "", 0, 6, 71, 0, 0 },

  { 682, 131,
    "DataLogging/Poll KINARM/PMAC Subsystem/read_pmac/Data Type Conversion1",
    "", 0, 6, 71, 0, 0 },

  { 683, 131,
    "DataLogging/Poll KINARM/PMAC Subsystem/read_pmac/Data Type Conversion2",
    "", 0, 6, 1, 0, 0 },

  { 684, 131,
    "DataLogging/Poll KINARM/PMAC Subsystem/read_pmac/Data Type Conversion3",
    "", 0, 0, 71, 0, 0 },

  { 685, 131,
    "DataLogging/Poll KINARM/PMAC Subsystem/read_pmac/Data Type Conversion4",
    "", 0, 0, 71, 0, 0 },

  { 686, 131, "DataLogging/Poll KINARM/PMAC Subsystem/read_pmac/MinMax",
    "", 0, 4, 1, 0, 0 },

  { 687, 131, "DataLogging/Poll KINARM/PMAC Subsystem/read_pmac/MinMax1",
    "", 0, 4, 1, 0, 0 },

  { 688, 131, "DataLogging/Poll KINARM/PMAC Subsystem/read_pmac/S-Function/p1",
    "", 0, 6, 71, 0, 0 },

  { 689, 131, "DataLogging/Poll KINARM/PMAC Subsystem/read_pmac/S-Function/p2",
    "", 1, 6, 71, 0, 0 },

  { 690, 131, "DataLogging/Poll KINARM/PMAC Subsystem/read_pmac/S-Function/p3",
    "", 2, 4, 2, 0, 0 },

  { 691, 131, "DataLogging/Poll KINARM/PMAC Subsystem/read_pmac/S-Function/p4",
    "", 3, 6, 3, 0, 0 },

  { 692, 131, "DataLogging/Poll KINARM/PMAC Subsystem/read_pmac/S-Function/p5",
    "", 4, 6, 34, 0, 0 },

  { 693, 131, "DataLogging/Poll KINARM/PMAC Subsystem/read_pmac/S-Function/p6",
    "", 5, 6, 34, 0, 0 },

  { 694, 131, "DataLogging/Poll KINARM/PMAC Subsystem/read_pmac/S-Function/p7",
    "", 6, 4, 1, 0, 0 },

  { 695, 131, "DataLogging/Poll KINARM/PMAC Subsystem/read_pmac/S-Function/p8",
    "", 7, 4, 1, 0, 0 },

  { 696, 131, "DataLogging/Poll KINARM/PMAC Subsystem/read_pmac/S-Function/p9",
    "", 8, 4, 41, 0, 0 },

  { 697, 131, "DataLogging/Poll KINARM/PMAC Subsystem/read_pmac/S-Function/p10",
    "", 9, 6, 1, 0, 0 },

  { 698, 132,
    "DataLogging/Poll KINARM/PMAC Subsystem/update settings/update status format",
    "outStatus", 0, 4, 72, 0, 1 },

  { 699, 134,
    "DataLogging/Poll KINARM/bkin_internal_testing/Data receive/MATLAB Function/p1",
    "kinematics", 0, 0, 6, 0, 0 },

  { 700, 134,
    "DataLogging/Poll KINARM/bkin_internal_testing/Data receive/MATLAB Function/p2",
    "primary", 1, 0, 57, 0, 0 },

  { 701, 135,
    "DataLogging/Poll KINARM/bkin_internal_testing/Data receive/Constant",
    "", 0, 4, 1, 0, 0 },

  { 702, 135,
    "DataLogging/Poll KINARM/bkin_internal_testing/Data receive/Constant1",
    "", 0, 4, 65, 0, 0 },

  { 703, 135,
    "DataLogging/Poll KINARM/bkin_internal_testing/Data receive/Data Type Conversion",
    "", 0, 0, 2, 0, 0 },

  { 704, 135,
    "DataLogging/Poll KINARM/bkin_internal_testing/Data receive/Data Type Conversion1",
    "", 0, 0, 2, 0, 0 },

  { 705, 135,
    "DataLogging/Poll KINARM/bkin_internal_testing/Data receive/Data Type Conversion2",
    "", 0, 0, 1, 0, 0 },

  { 706, 135,
    "DataLogging/Poll KINARM/bkin_internal_testing/Data receive/Receive/p1",
    "", 0, 5, 63, 0, 0 },

  { 707, 135,
    "DataLogging/Poll KINARM/bkin_internal_testing/Data receive/Receive/p2",
    "", 1, 0, 1, 0, 0 },

  { 708, 135,
    "DataLogging/Poll KINARM/bkin_internal_testing/Data receive/Unpack/p1",
    "", 0, 6, 2, 0, 0 },

  { 709, 135,
    "DataLogging/Poll KINARM/bkin_internal_testing/Data receive/Unpack/p2",
    "", 1, 6, 2, 0, 0 },

  { 710, 150, "DataLogging/Poll KINARM/bkin_internal_testing/ispmac1/Compare",
    "", 0, 2, 1, 0, 0 },

  { 711, 137, "DataLogging/Poll KINARM/constants/arm1/decode robot/p1",
    "isEP", 0, 0, 1, 0, 0 },

  { 712, 137, "DataLogging/Poll KINARM/constants/arm1/decode robot/p2",
    "isHumanEXO", 1, 0, 1, 0, 0 },

  { 713, 137, "DataLogging/Poll KINARM/constants/arm1/decode robot/p3",
    "isNHPEXO", 2, 0, 1, 0, 0 },

  { 714, 137, "DataLogging/Poll KINARM/constants/arm1/decode robot/p4",
    "isClassicExo", 3, 0, 1, 0, 0 },

  { 715, 137, "DataLogging/Poll KINARM/constants/arm1/decode robot/p5",
    "isUTSEXO", 4, 0, 1, 0, 0 },

  { 716, 137, "DataLogging/Poll KINARM/constants/arm1/decode robot/p6",
    "isPMAC", 5, 0, 1, 0, 0 },

  { 717, 137, "DataLogging/Poll KINARM/constants/arm1/decode robot/p7",
    "isECAT", 6, 0, 1, 0, 0 },

  { 718, 150, "DataLogging/Poll KINARM/constants/arm1/Arm Elbow Angle Offset",
    "elbow angle offset", 0, 0, 1, 0, 0 },

  { 719, 150, "DataLogging/Poll KINARM/constants/arm1/Arm L1",
    "L1", 0, 0, 1, 0, 0 },

  { 720, 150, "DataLogging/Poll KINARM/constants/arm1/Arm L2",
    "L2", 0, 0, 1, 0, 0 },

  { 721, 150, "DataLogging/Poll KINARM/constants/arm1/Arm L3 Error",
    "L3 Error", 0, 0, 1, 0, 0 },

  { 722, 150, "DataLogging/Poll KINARM/constants/arm1/Arm Motor1 Gear Ratio",
    "M1 Gear Ratio", 0, 0, 1, 0, 0 },

  { 723, 150, "DataLogging/Poll KINARM/constants/arm1/Arm Motor1 Orientation",
    "M1 orientation", 0, 0, 1, 0, 0 },

  { 724, 150, "DataLogging/Poll KINARM/constants/arm1/Arm Motor2 Gear Ratio",
    "M2 Gear Ratio", 0, 0, 1, 0, 0 },

  { 725, 150, "DataLogging/Poll KINARM/constants/arm1/Arm Motor2 Orientation",
    "M2 Orientation", 0, 0, 1, 0, 0 },

  { 726, 150, "DataLogging/Poll KINARM/constants/arm1/Arm Orientation",
    "Arm Orientation", 0, 0, 1, 0, 0 },

  { 727, 150, "DataLogging/Poll KINARM/constants/arm1/Arm Pointer Offset",
    "Pointer offset", 0, 0, 1, 0, 0 },

  { 728, 150, "DataLogging/Poll KINARM/constants/arm1/Arm Secondary Encoders",
    "Has Secondary Enc", 0, 0, 1, 0, 0 },

  { 729, 150, "DataLogging/Poll KINARM/constants/arm1/Arm Shoulder Angle Offset",
    "shoulder angle offset", 0, 0, 1, 0, 0 },

  { 730, 150, "DataLogging/Poll KINARM/constants/arm1/Arm Shoulder X",
    "Shoulder X", 0, 0, 1, 0, 0 },

  { 731, 150, "DataLogging/Poll KINARM/constants/arm1/Arm Shoulder Y",
    "Shoulder Y", 0, 0, 1, 0, 0 },

  { 732, 150, "DataLogging/Poll KINARM/constants/arm1/Arm Torque Constant",
    "torque constant", 0, 0, 1, 0, 0 },

  { 733, 150, "DataLogging/Poll KINARM/constants/arm1/Arm robot type",
    "robot type", 0, 0, 1, 0, 0 },

  { 734, 150, "DataLogging/Poll KINARM/constants/arm1/Arm robot version",
    "robot version", 0, 0, 1, 0, 0 },

  { 735, 150, "DataLogging/Poll KINARM/constants/arm1/Status read1",
    "", 0, 0, 2, 0, 0 },

  { 736, 138, "DataLogging/Poll KINARM/constants/arm2/decode robot/p1",
    "isEP", 0, 0, 1, 0, 0 },

  { 737, 138, "DataLogging/Poll KINARM/constants/arm2/decode robot/p2",
    "isHumanEXO", 1, 0, 1, 0, 0 },

  { 738, 138, "DataLogging/Poll KINARM/constants/arm2/decode robot/p3",
    "isNHPEXO", 2, 0, 1, 0, 0 },

  { 739, 138, "DataLogging/Poll KINARM/constants/arm2/decode robot/p4",
    "isClassicExo", 3, 0, 1, 0, 0 },

  { 740, 138, "DataLogging/Poll KINARM/constants/arm2/decode robot/p5",
    "isUTSEXO", 4, 0, 1, 0, 0 },

  { 741, 138, "DataLogging/Poll KINARM/constants/arm2/decode robot/p6",
    "isPMAC", 5, 0, 1, 0, 0 },

  { 742, 138, "DataLogging/Poll KINARM/constants/arm2/decode robot/p7",
    "isECAT", 6, 0, 1, 0, 0 },

  { 743, 150, "DataLogging/Poll KINARM/constants/arm2/Arm Elbow Angle Offset",
    "elbow angle offset", 0, 0, 1, 0, 0 },

  { 744, 150, "DataLogging/Poll KINARM/constants/arm2/Arm L1",
    "L1", 0, 0, 1, 0, 0 },

  { 745, 150, "DataLogging/Poll KINARM/constants/arm2/Arm L2",
    "L2", 0, 0, 1, 0, 0 },

  { 746, 150, "DataLogging/Poll KINARM/constants/arm2/Arm L3 Error",
    "L3 Error", 0, 0, 1, 0, 0 },

  { 747, 150, "DataLogging/Poll KINARM/constants/arm2/Arm Motor1 Gear Ratio",
    "M1 Gear Ratio", 0, 0, 1, 0, 0 },

  { 748, 150, "DataLogging/Poll KINARM/constants/arm2/Arm Motor1 Orientation",
    "M1 orientation", 0, 0, 1, 0, 0 },

  { 749, 150, "DataLogging/Poll KINARM/constants/arm2/Arm Motor2 Gear Ratio",
    "M2 Gear Ratio", 0, 0, 1, 0, 0 },

  { 750, 150, "DataLogging/Poll KINARM/constants/arm2/Arm Motor2 Orientation",
    "M2 Orientation", 0, 0, 1, 0, 0 },

  { 751, 150, "DataLogging/Poll KINARM/constants/arm2/Arm Orientation",
    "Arm Orientation", 0, 0, 1, 0, 0 },

  { 752, 150, "DataLogging/Poll KINARM/constants/arm2/Arm Pointer Offset",
    "Pointer offset", 0, 0, 1, 0, 0 },

  { 753, 150, "DataLogging/Poll KINARM/constants/arm2/Arm Secondary Encoders",
    "Has Secondary Enc", 0, 0, 1, 0, 0 },

  { 754, 150, "DataLogging/Poll KINARM/constants/arm2/Arm Shoulder Angle Offset",
    "shoulder angle offset", 0, 0, 1, 0, 0 },

  { 755, 150, "DataLogging/Poll KINARM/constants/arm2/Arm Shoulder X",
    "Shoulder X", 0, 0, 1, 0, 0 },

  { 756, 150, "DataLogging/Poll KINARM/constants/arm2/Arm Shoulder Y",
    "Shoulder Y", 0, 0, 1, 0, 0 },

  { 757, 150, "DataLogging/Poll KINARM/constants/arm2/Arm Torque Constant",
    "torque constant", 0, 0, 1, 0, 0 },

  { 758, 150, "DataLogging/Poll KINARM/constants/arm2/Arm robot type",
    "robot type", 0, 0, 1, 0, 0 },

  { 759, 150, "DataLogging/Poll KINARM/constants/arm2/Arm robot version",
    "robot version", 0, 0, 1, 0, 0 },

  { 760, 150, "DataLogging/Poll KINARM/constants/arm2/Status read1",
    "", 0, 0, 2, 0, 0 },

  { 761, 144,
    "DataLogging/Poll KINARM/createKINData/Counter Free-Running/Output",
    "", 0, 4, 1, 0, 1 },

  { 762, 8,
    "DataLogging/Network Transfer Subsystem/UDP Send Subsystem/Counter Free-Running/Increment Real World/FixPt Sum1",
    "", 0, 4, 1, 0, 1 },

  { 763, 8,
    "DataLogging/Network Transfer Subsystem/UDP Send Subsystem/Counter Free-Running/Wrap To Zero/FixPt Switch",
    "", 0, 4, 1, 0, 1 },

  { 764, 20,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M1/Control GDC Whistle State/p1",
    "ControlWord", 0, 1, 1, 0, 0 },

  { 765, 20,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M1/Control GDC Whistle State/p2",
    "motorStatus", 1, 4, 1, 0, 0 },

  { 766, 20,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M1/Control GDC Whistle State/p3",
    "isPermFaulted", 2, 0, 1, 0, 0 },

  { 767, 57, "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M1/Memory",
    "", 0, 0, 1, 0, 0 },

  { 768, 28,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M2/Control GDC Whistle State/p1",
    "ControlWord", 0, 1, 1, 0, 0 },

  { 769, 28,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M2/Control GDC Whistle State/p2",
    "motorStatus", 1, 4, 1, 0, 0 },

  { 770, 28,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M2/Control GDC Whistle State/p3",
    "isPermFaulted", 2, 0, 1, 0, 0 },

  { 771, 57, "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M2/Memory",
    "", 0, 0, 1, 0, 0 },

  { 772, 35,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/M1 AbsEnc Calibration/AbsEncoder machine/p1",
    "setupData", 0, 3, 3, 0, 0 },

  { 773, 35,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/M1 AbsEnc Calibration/AbsEncoder machine/p2",
    "SDORequest", 1, 3, 41, 0, 0 },

  { 774, 35,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/M1 AbsEnc Calibration/AbsEncoder machine/p3",
    "encoderOutputs", 2, 3, 34, 0, 0 },

  { 775, 35,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/M1 AbsEnc Calibration/AbsEncoder machine/p4",
    "complete", 3, 3, 1, 0, 0 },

  { 776, 36,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/M1 AbsEnc Calibration/set-up values/p1",
    "setupValues", 0, 0, 73, 0, 0 },

  { 777, 36,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/M1 AbsEnc Calibration/set-up values/p2",
    "setupValuesCount", 1, 0, 1, 0, 0 },

  { 778, 36,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/M1 AbsEnc Calibration/set-up values/p3",
    "pollValues", 2, 0, 7, 0, 0 },

  { 779, 36,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/M1 AbsEnc Calibration/set-up values/p4",
    "encoderValues", 3, 0, 74, 0, 0 },

  { 780, 36,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/M1 AbsEnc Calibration/set-up values/p5",
    "encoderValuesCount", 4, 0, 1, 0, 0 },

  { 781, 37,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/M1 AbsEnc Calibration/Memory",
    "", 0, 3, 1, 0, 0 },

  { 782, 37,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/M1 AbsEnc Calibration/Memory1",
    "", 0, 3, 2, 0, 0 },

  { 783, 37,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/M1 AbsEnc Calibration/BKIN EtherCAT Async SDO Download",
    "", 0, 3, 1, 0, 0 },

  { 784, 37,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/M1 AbsEnc Calibration/BKIN EtherCAT Async SDO Upload/p1",
    "", 0, 3, 1, 0, 0 },

  { 785, 37,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/M1 AbsEnc Calibration/BKIN EtherCAT Async SDO Upload/p2",
    "", 1, 3, 1, 0, 0 },

  { 786, 38,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/M2 AbsEnc Calibration/AbsEncoder machine/p1",
    "setupData", 0, 3, 3, 0, 0 },

  { 787, 38,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/M2 AbsEnc Calibration/AbsEncoder machine/p2",
    "SDORequest", 1, 3, 41, 0, 0 },

  { 788, 38,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/M2 AbsEnc Calibration/AbsEncoder machine/p3",
    "encoderOutputs", 2, 3, 34, 0, 0 },

  { 789, 38,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/M2 AbsEnc Calibration/AbsEncoder machine/p4",
    "complete", 3, 3, 1, 0, 0 },

  { 790, 39,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/M2 AbsEnc Calibration/set-up values/p1",
    "setupValues", 0, 0, 73, 0, 0 },

  { 791, 39,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/M2 AbsEnc Calibration/set-up values/p2",
    "setupValuesCount", 1, 0, 1, 0, 0 },

  { 792, 39,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/M2 AbsEnc Calibration/set-up values/p3",
    "pollValues", 2, 0, 7, 0, 0 },

  { 793, 39,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/M2 AbsEnc Calibration/set-up values/p4",
    "encoderValues", 3, 0, 74, 0, 0 },

  { 794, 39,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/M2 AbsEnc Calibration/set-up values/p5",
    "encoderValuesCount", 4, 0, 1, 0, 0 },

  { 795, 40,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/M2 AbsEnc Calibration/Memory",
    "", 0, 3, 1, 0, 0 },

  { 796, 40,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/M2 AbsEnc Calibration/Memory1",
    "", 0, 3, 2, 0, 0 },

  { 797, 40,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/M2 AbsEnc Calibration/BKIN EtherCAT Async SDO Download",
    "", 0, 3, 1, 0, 0 },

  { 798, 40,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/M2 AbsEnc Calibration/BKIN EtherCAT Async SDO Upload/p1",
    "", 0, 3, 1, 0, 0 },

  { 799, 40,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/M2 AbsEnc Calibration/BKIN EtherCAT Async SDO Upload/p2",
    "", 1, 3, 1, 0, 0 },

  { 800, 44,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/SDO reading/SDO read machine/p1",
    "enable", 0, 3, 1, 0, 0 },

  { 801, 44,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/SDO reading/SDO read machine/p2",
    "complete", 1, 3, 1, 0, 0 },

  { 802, 45,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/SDO reading/values",
    "outVal", 0, 0, 41, 0, 0 },

  { 803, 46,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/SDO reading/readAddr",
    "", 0, 0, 41, 0, 0 },

  { 804, 46,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/SDO reading/Data Type Conversion1",
    "", 0, 3, 1, 0, 0 },

  { 805, 46,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/SDO reading/Data Type Conversion2",
    "", 0, 3, 1, 0, 0 },

  { 806, 46,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/SDO reading/convert",
    "", 0, 0, 1, 0, 0 },

  { 807, 46,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/SDO reading/convert1",
    "", 0, 0, 1, 0, 0 },

  { 808, 46,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/SDO reading/status",
    "", 0, 0, 1, 0, 0 },

  { 809, 46,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/SDO reading/Memory",
    "", 0, 0, 1, 0, 0 },

  { 810, 47,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/SDO writing/SDO write machine/p1",
    "enable", 0, 3, 1, 0, 0 },

  { 811, 47,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/SDO writing/SDO write machine/p2",
    "complete", 1, 3, 1, 0, 0 },

  { 812, 48,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/SDO writing/convert",
    "y", 0, 4, 1, 0, 0 },

  { 813, 49,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/SDO writing/writeData",
    "", 0, 0, 50, 0, 0 },

  { 814, 49,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/SDO writing/Data Type Conversion1",
    "", 0, 3, 1, 0, 0 },

  { 815, 49,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/SDO writing/Data Type Conversion2",
    "", 0, 3, 1, 0, 0 },

  { 816, 49,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/SDO writing/status",
    "", 0, 0, 1, 0, 0 },

  { 817, 49,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/SDO writing/Memory",
    "", 0, 3, 1, 0, 0 },

  { 818, 49,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/SDO writing/BKIN EtherCAT Async SDO Download",
    "", 0, 3, 1, 0, 0 },

  { 819, 57,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/int subsystem/Memory",
    "", 0, 3, 1, 0, 0 },

  { 820, 57,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/int subsystem/Memory1",
    "", 0, 0, 1, 0, 0 },

  { 821, 57,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/int subsystem/Memory2",
    "", 0, 0, 1, 0, 0 },

  { 822, 57,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/int subsystem/Rate Transition",
    "", 0, 3, 1, 0, 0 },

  { 823, 57,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/int subsystem/Rate Transition1",
    "", 0, 0, 1, 0, 0 },

  { 824, 57,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/int subsystem/Rate Transition2",
    "", 0, 0, 1, 0, 0 },

  { 825, 60,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M1/Control GDC Whistle State/p1",
    "ControlWord", 0, 1, 1, 0, 0 },

  { 826, 60,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M1/Control GDC Whistle State/p2",
    "motorStatus", 1, 4, 1, 0, 0 },

  { 827, 60,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M1/Control GDC Whistle State/p3",
    "isPermFaulted", 2, 0, 1, 0, 0 },

  { 828, 97, "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M1/Memory",
    "", 0, 0, 1, 0, 0 },

  { 829, 68,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M2/Control GDC Whistle State/p1",
    "ControlWord", 0, 1, 1, 0, 0 },

  { 830, 68,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M2/Control GDC Whistle State/p2",
    "motorStatus", 1, 4, 1, 0, 0 },

  { 831, 68,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M2/Control GDC Whistle State/p3",
    "isPermFaulted", 2, 0, 1, 0, 0 },

  { 832, 97, "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M2/Memory",
    "", 0, 0, 1, 0, 0 },

  { 833, 75,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/M1 AbsEnc Calibration/AbsEncoder machine/p1",
    "setupData", 0, 3, 3, 0, 0 },

  { 834, 75,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/M1 AbsEnc Calibration/AbsEncoder machine/p2",
    "SDORequest", 1, 3, 41, 0, 0 },

  { 835, 75,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/M1 AbsEnc Calibration/AbsEncoder machine/p3",
    "encoderOutputs", 2, 3, 34, 0, 0 },

  { 836, 75,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/M1 AbsEnc Calibration/AbsEncoder machine/p4",
    "complete", 3, 3, 1, 0, 0 },

  { 837, 76,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/M1 AbsEnc Calibration/set-up values/p1",
    "setupValues", 0, 0, 73, 0, 0 },

  { 838, 76,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/M1 AbsEnc Calibration/set-up values/p2",
    "setupValuesCount", 1, 0, 1, 0, 0 },

  { 839, 76,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/M1 AbsEnc Calibration/set-up values/p3",
    "pollValues", 2, 0, 7, 0, 0 },

  { 840, 76,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/M1 AbsEnc Calibration/set-up values/p4",
    "encoderValues", 3, 0, 74, 0, 0 },

  { 841, 76,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/M1 AbsEnc Calibration/set-up values/p5",
    "encoderValuesCount", 4, 0, 1, 0, 0 },

  { 842, 77,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/M1 AbsEnc Calibration/Memory",
    "", 0, 3, 1, 0, 0 },

  { 843, 77,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/M1 AbsEnc Calibration/Memory1",
    "", 0, 3, 2, 0, 0 },

  { 844, 77,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/M1 AbsEnc Calibration/BKIN EtherCAT Async SDO Download",
    "", 0, 3, 1, 0, 0 },

  { 845, 77,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/M1 AbsEnc Calibration/BKIN EtherCAT Async SDO Upload/p1",
    "", 0, 3, 1, 0, 0 },

  { 846, 77,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/M1 AbsEnc Calibration/BKIN EtherCAT Async SDO Upload/p2",
    "", 1, 3, 1, 0, 0 },

  { 847, 78,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/M2 AbsEnc Calibration/AbsEncoder machine/p1",
    "setupData", 0, 3, 3, 0, 0 },

  { 848, 78,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/M2 AbsEnc Calibration/AbsEncoder machine/p2",
    "SDORequest", 1, 3, 41, 0, 0 },

  { 849, 78,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/M2 AbsEnc Calibration/AbsEncoder machine/p3",
    "encoderOutputs", 2, 3, 34, 0, 0 },

  { 850, 78,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/M2 AbsEnc Calibration/AbsEncoder machine/p4",
    "complete", 3, 3, 1, 0, 0 },

  { 851, 79,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/M2 AbsEnc Calibration/set-up values/p1",
    "setupValues", 0, 0, 73, 0, 0 },

  { 852, 79,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/M2 AbsEnc Calibration/set-up values/p2",
    "setupValuesCount", 1, 0, 1, 0, 0 },

  { 853, 79,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/M2 AbsEnc Calibration/set-up values/p3",
    "pollValues", 2, 0, 7, 0, 0 },

  { 854, 79,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/M2 AbsEnc Calibration/set-up values/p4",
    "encoderValues", 3, 0, 74, 0, 0 },

  { 855, 79,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/M2 AbsEnc Calibration/set-up values/p5",
    "encoderValuesCount", 4, 0, 1, 0, 0 },

  { 856, 80,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/M2 AbsEnc Calibration/Memory",
    "", 0, 3, 1, 0, 0 },

  { 857, 80,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/M2 AbsEnc Calibration/Memory1",
    "", 0, 3, 2, 0, 0 },

  { 858, 80,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/M2 AbsEnc Calibration/BKIN EtherCAT Async SDO Download",
    "", 0, 3, 1, 0, 0 },

  { 859, 80,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/M2 AbsEnc Calibration/BKIN EtherCAT Async SDO Upload/p1",
    "", 0, 3, 1, 0, 0 },

  { 860, 80,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/M2 AbsEnc Calibration/BKIN EtherCAT Async SDO Upload/p2",
    "", 1, 3, 1, 0, 0 },

  { 861, 84,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/SDO reading/SDO read machine/p1",
    "enable", 0, 3, 1, 0, 0 },

  { 862, 84,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/SDO reading/SDO read machine/p2",
    "complete", 1, 3, 1, 0, 0 },

  { 863, 85,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/SDO reading/values",
    "outVal", 0, 0, 41, 0, 0 },

  { 864, 86,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/SDO reading/readAddr",
    "", 0, 0, 41, 0, 0 },

  { 865, 86,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/SDO reading/Data Type Conversion1",
    "", 0, 3, 1, 0, 0 },

  { 866, 86,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/SDO reading/Data Type Conversion2",
    "", 0, 3, 1, 0, 0 },

  { 867, 86,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/SDO reading/convert",
    "", 0, 0, 1, 0, 0 },

  { 868, 86,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/SDO reading/convert1",
    "", 0, 0, 1, 0, 0 },

  { 869, 86,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/SDO reading/status",
    "", 0, 0, 1, 0, 0 },

  { 870, 86,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/SDO reading/Memory",
    "", 0, 0, 1, 0, 0 },

  { 871, 87,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/SDO writing/SDO write machine/p1",
    "enable", 0, 3, 1, 0, 0 },

  { 872, 87,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/SDO writing/SDO write machine/p2",
    "complete", 1, 3, 1, 0, 0 },

  { 873, 88,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/SDO writing/convert",
    "y", 0, 4, 1, 0, 0 },

  { 874, 89,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/SDO writing/writeData",
    "", 0, 0, 50, 0, 0 },

  { 875, 89,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/SDO writing/Data Type Conversion1",
    "", 0, 3, 1, 0, 0 },

  { 876, 89,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/SDO writing/Data Type Conversion2",
    "", 0, 3, 1, 0, 0 },

  { 877, 89,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/SDO writing/status",
    "", 0, 0, 1, 0, 0 },

  { 878, 89,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/SDO writing/Memory",
    "", 0, 3, 1, 0, 0 },

  { 879, 89,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/SDO writing/BKIN EtherCAT Async SDO Download",
    "", 0, 3, 1, 0, 0 },

  { 880, 97,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/int subsystem/Memory",
    "", 0, 3, 1, 0, 0 },

  { 881, 97,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/int subsystem/Memory1",
    "", 0, 0, 1, 0, 0 },

  { 882, 97,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/int subsystem/Memory2",
    "", 0, 0, 1, 0, 0 },

  { 883, 97,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/int subsystem/Rate Transition",
    "", 0, 3, 1, 0, 0 },

  { 884, 97,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/int subsystem/Rate Transition1",
    "", 0, 0, 1, 0, 0 },

  { 885, 97,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/int subsystem/Rate Transition2",
    "", 0, 0, 1, 0, 0 },

  { 886, 150,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Counter Free-Running/Increment Real World/FixPt Sum1",
    "", 0, 4, 1, 0, 0 },

  { 887, 150,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Counter Free-Running/Wrap To Zero/FixPt Switch",
    "", 0, 4, 1, 0, 0 },

  { 888, 104,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/update/create filtered velocities/filter_velocities",
    "filteredVels", 0, 0, 32, 0, 1 },

  { 889, 105,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/update/create filtered velocities/rebuild",
    "outVals", 0, 0, 6, 0, 1 },

  { 890, 124,
    "DataLogging/Poll KINARM/Force Sensor Control/Force Sensor 1 Subsystem/Detect Change/FixPt Relational Operator",
    "", 0, 5, 1, 0, 0 },

  { 891, 124,
    "DataLogging/Poll KINARM/Force Sensor Control/Force Sensor 1 Subsystem/Detect Change/Delay Input1",
    "U(k-1)", 0, 0, 1, 0, 0 },

  { 892, 117,
    "DataLogging/Poll KINARM/Force Sensor Control/Force Sensor 1 Subsystem/If Action Subsystem/Byte Reversal",
    "", 0, 1, 1, 0, 0 },

  { 893, 117,
    "DataLogging/Poll KINARM/Force Sensor Control/Force Sensor 1 Subsystem/If Action Subsystem/Byte Reversal1",
    "", 0, 1, 1, 0, 0 },

  { 894, 117,
    "DataLogging/Poll KINARM/Force Sensor Control/Force Sensor 1 Subsystem/If Action Subsystem/Byte Reversal2",
    "", 0, 4, 1, 0, 0 },

  { 895, 117,
    "DataLogging/Poll KINARM/Force Sensor Control/Force Sensor 1 Subsystem/If Action Subsystem/Pack",
    "", 0, 5, 11, 0, 0 },

  { 896, 117,
    "DataLogging/Poll KINARM/Force Sensor Control/Force Sensor 1 Subsystem/If Action Subsystem/Switch",
    "", 0, 1, 1, 0, 0 },

  { 897, 123,
    "DataLogging/Poll KINARM/Force Sensor Control/Force Sensor 2 Subsystem/Data Transfer Start Subsystem/Byte Reversal",
    "", 0, 4, 1, 0, 0 },

  { 898, 123,
    "DataLogging/Poll KINARM/Force Sensor Control/Force Sensor 2 Subsystem/Data Transfer Start Subsystem/Byte Reversal1",
    "", 0, 1, 1, 0, 0 },

  { 899, 123,
    "DataLogging/Poll KINARM/Force Sensor Control/Force Sensor 2 Subsystem/Data Transfer Start Subsystem/Byte Reversal2",
    "", 0, 1, 1, 0, 0 },

  { 900, 123,
    "DataLogging/Poll KINARM/Force Sensor Control/Force Sensor 2 Subsystem/Data Transfer Start Subsystem/Pack",
    "", 0, 5, 11, 0, 0 },

  { 901, 123,
    "DataLogging/Poll KINARM/Force Sensor Control/Force Sensor 2 Subsystem/Data Transfer Start Subsystem/Switch",
    "", 0, 1, 1, 0, 0 },

  { 902, 124,
    "DataLogging/Poll KINARM/Force Sensor Control/Force Sensor 2 Subsystem/Detect Change/FixPt Relational Operator",
    "", 0, 5, 1, 0, 0 },

  { 903, 124,
    "DataLogging/Poll KINARM/Force Sensor Control/Force Sensor 2 Subsystem/Detect Change/Delay Input1",
    "U(k-1)", 0, 0, 1, 0, 0 },

  { 904, 126,
    "DataLogging/Poll KINARM/PMAC Subsystem/read_pmac/DPRAM Access Subsystem/TypeCast",
    "y", 0, 6, 1, 0, 0 },

  { 905, 131,
    "DataLogging/Poll KINARM/PMAC Subsystem/read_pmac/DPRAM Access Subsystem/Data Type Conversion",
    "", 0, 4, 1, 0, 0 },

  { 906, 131,
    "DataLogging/Poll KINARM/PMAC Subsystem/read_pmac/DPRAM Access Subsystem/DPRAM Read Value",
    "", 0, 0, 1, 0, 0 },

  { 907, 131,
    "DataLogging/Poll KINARM/PMAC Subsystem/read_pmac/DPRAM Access Subsystem/Unit Delay",
    "", 0, 0, 1, 0, 0 },

  { 908, 131,
    "DataLogging/Poll KINARM/PMAC Subsystem/read_pmac/DPRAM Access Subsystem/Unit Delay1",
    "", 0, 0, 1, 0, 0 },

  { 909, 135,
    "DataLogging/Poll KINARM/bkin_internal_testing/Data receive/Counter Free-Running/Output",
    "", 0, 4, 1, 0, 0 },

  { 910, 144,
    "DataLogging/Poll KINARM/createKINData/Counter Free-Running/Increment Real World/FixPt Sum1",
    "", 0, 4, 1, 0, 1 },

  { 911, 144,
    "DataLogging/Poll KINARM/createKINData/Counter Free-Running/Wrap To Zero/FixPt Switch",
    "", 0, 4, 1, 0, 1 },

  { 912, 18,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M1/A1M1 PDOs/parse status register/p1",
    "allOK", 0, 4, 1, 0, 0 },

  { 913, 18,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M1/A1M1 PDOs/parse status register/p2",
    "ampStatus", 1, 4, 1, 0, 0 },

  { 914, 18,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M1/A1M1 PDOs/parse status register/p3",
    "servoEnabled", 2, 4, 1, 0, 0 },

  { 915, 18,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M1/A1M1 PDOs/parse status register/p4",
    "faultFound", 3, 4, 1, 0, 0 },

  { 916, 18,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M1/A1M1 PDOs/parse status register/p5",
    "currentLimitEnabled", 4, 4, 1, 0, 0 },

  { 917, 18,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M1/A1M1 PDOs/parse status register/p6",
    "eStopOut", 5, 4, 1, 0, 0 },

  { 918, 18,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M1/A1M1 PDOs/parse status register/p7",
    "motorOn", 6, 4, 1, 0, 0 },

  { 919, 19,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M1/A1M1 PDOs/A1M1Convert",
    "", 0, 0, 50, 0, 0 },

  { 920, 19,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M1/A1M1 PDOs/Data Type Conversion1",
    "", 0, 3, 1, 0, 0 },

  { 921, 19,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M1/A1M1 PDOs/BKIN PDO Receive ElmoDrive/p1",
    "Status word", 0, 1, 1, 0, 0 },

  { 922, 19,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M1/A1M1 PDOs/BKIN PDO Receive ElmoDrive/p2",
    "status register", 1, 4, 1, 0, 0 },

  { 923, 19,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M1/A1M1 PDOs/BKIN PDO Receive ElmoDrive/p3",
    "primary position", 2, 3, 1, 0, 0 },

  { 924, 19,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M1/A1M1 PDOs/BKIN PDO Receive ElmoDrive/p4",
    "secondary position", 3, 3, 1, 0, 0 },

  { 925, 19,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M1/A1M1 PDOs/BKIN PDO Receive ElmoDrive/p5",
    "primary velocity", 4, 3, 1, 0, 0 },

  { 926, 19,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M1/A1M1 PDOs/BKIN PDO Receive ElmoDrive/p6",
    "torque", 5, 7, 1, 0, 0 },

  { 927, 19,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M1/A1M1 PDOs/BKIN PDO Receive ElmoDrive/p7",
    "digital inputs", 6, 3, 1, 0, 0 },

  { 928, 19,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M1/A1M1 PDOs/BKIN PDO Receive ElmoDrive/p8",
    "actual mode of operation", 7, 8, 1, 0, 0 },

  { 929, 57,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M1/Compare To Constant/Compare",
    "", 0, 2, 1, 0, 0 },

  { 930, 21,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M1/EMCY Message pump/Read EMCY/p1",
    "triggerCountRead", 0, 3, 1, 0, 0 },

  { 931, 21,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M1/EMCY Message pump/Read EMCY/p2",
    "emcyReadTrigger", 1, 3, 2, 0, 0 },

  { 932, 21,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M1/EMCY Message pump/Read EMCY/p3",
    "countOverwriteTrigger", 2, 3, 1, 0, 0 },

  { 933, 21,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M1/EMCY Message pump/Read EMCY/p4",
    "emcyValPump", 3, 0, 41, 0, 0 },

  { 934, 22,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M1/EMCY Message pump/fault monitor",
    "triggerFaultRead", 0, 0, 1, 0, 0 },

  { 935, 23,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M1/EMCY Message pump/fault monitor1",
    "EMCYMsg", 0, 0, 50, 0, 0 },

  { 936, 24,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M1/EMCY Message pump/driveID",
    "", 0, 0, 1, 0, 0 },

  { 937, 24,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M1/EMCY Message pump/Data Type Conversion",
    "", 0, 0, 1, 0, 0 },

  { 938, 25,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M1/PDO to Angles Subsystem/countsToRads/p1",
    "LinkAngle", 0, 0, 1, 0, 0 },

  { 939, 25,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M1/PDO to Angles Subsystem/countsToRads/p2",
    "PrimaryLinkAngle", 1, 0, 1, 0, 0 },

  { 940, 25,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M1/PDO to Angles Subsystem/countsToRads/p3",
    "PrimaryLinkVel", 2, 0, 1, 0, 0 },

  { 941, 25,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M1/PDO to Angles Subsystem/countsToRads/p4",
    "torque", 3, 0, 1, 0, 0 },

  { 942, 25,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M1/PDO to Angles Subsystem/countsToRads/p5",
    "digitalInputs", 4, 0, 8, 0, 0 },

  { 943, 25,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M1/PDO to Angles Subsystem/countsToRads/p6",
    "digitalDiagnostics", 5, 0, 1, 0, 0 },

  { 944, 25,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M1/PDO to Angles Subsystem/countsToRads/p7",
    "calibrationButton", 6, 0, 1, 0, 0 },

  { 945, 57,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M1/PDO to Angles Subsystem/L2 select",
    "", 0, 0, 1, 0, 0 },

  { 946, 57,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M1/PDO to Angles Subsystem/L2 select1",
    "", 0, 0, 1, 0, 0 },

  { 947, 57,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M1/PDO to Angles Subsystem/L2 select2",
    "", 0, 0, 1, 0, 0 },

  { 948, 57,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M1/PDO to Angles Subsystem/L2 select3",
    "", 0, 0, 1, 0, 0 },

  { 949, 57,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M1/PDO to Angles Subsystem/L2 select4",
    "", 0, 0, 1, 0, 0 },

  { 950, 57,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M1/PDO to Angles Subsystem/L2 select5",
    "", 0, 0, 1, 0, 0 },

  { 951, 26,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M2/A1M2 PDOs/parse status register1/p1",
    "allOK", 0, 4, 1, 0, 0 },

  { 952, 26,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M2/A1M2 PDOs/parse status register1/p2",
    "ampStatus", 1, 4, 1, 0, 0 },

  { 953, 26,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M2/A1M2 PDOs/parse status register1/p3",
    "servoEnabled", 2, 4, 1, 0, 0 },

  { 954, 26,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M2/A1M2 PDOs/parse status register1/p4",
    "faultFound", 3, 4, 1, 0, 0 },

  { 955, 26,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M2/A1M2 PDOs/parse status register1/p5",
    "currentLimitEnabled", 4, 4, 1, 0, 0 },

  { 956, 26,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M2/A1M2 PDOs/parse status register1/p6",
    "eStopOut", 5, 4, 1, 0, 0 },

  { 957, 26,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M2/A1M2 PDOs/parse status register1/p7",
    "motorOn", 6, 4, 1, 0, 0 },

  { 958, 27,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M2/A1M2 PDOs/A1M2Convert",
    "", 0, 0, 50, 0, 0 },

  { 959, 27,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M2/A1M2 PDOs/Data Type Conversion",
    "", 0, 3, 1, 0, 0 },

  { 960, 27,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M2/A1M2 PDOs/BKIN PDO Receive ElmoDrive/p1",
    "Status word", 0, 1, 1, 0, 0 },

  { 961, 27,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M2/A1M2 PDOs/BKIN PDO Receive ElmoDrive/p2",
    "status register", 1, 4, 1, 0, 0 },

  { 962, 27,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M2/A1M2 PDOs/BKIN PDO Receive ElmoDrive/p3",
    "primary position", 2, 3, 1, 0, 0 },

  { 963, 27,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M2/A1M2 PDOs/BKIN PDO Receive ElmoDrive/p4",
    "secondary position", 3, 3, 1, 0, 0 },

  { 964, 27,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M2/A1M2 PDOs/BKIN PDO Receive ElmoDrive/p5",
    "primary velocity", 4, 3, 1, 0, 0 },

  { 965, 27,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M2/A1M2 PDOs/BKIN PDO Receive ElmoDrive/p6",
    "torque", 5, 7, 1, 0, 0 },

  { 966, 27,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M2/A1M2 PDOs/BKIN PDO Receive ElmoDrive/p7",
    "digital inputs", 6, 3, 1, 0, 0 },

  { 967, 27,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M2/A1M2 PDOs/BKIN PDO Receive ElmoDrive/p8",
    "actual mode of operation", 7, 8, 1, 0, 0 },

  { 968, 57,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M2/Compare/Compare",
    "", 0, 2, 1, 0, 0 },

  { 969, 29,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M2/EMCY Message pump/Read EMCY/p1",
    "triggerCountRead", 0, 3, 1, 0, 0 },

  { 970, 29,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M2/EMCY Message pump/Read EMCY/p2",
    "emcyReadTrigger", 1, 3, 2, 0, 0 },

  { 971, 29,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M2/EMCY Message pump/Read EMCY/p3",
    "countOverwriteTrigger", 2, 3, 1, 0, 0 },

  { 972, 29,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M2/EMCY Message pump/Read EMCY/p4",
    "emcyValPump", 3, 0, 41, 0, 0 },

  { 973, 30,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M2/EMCY Message pump/fault monitor",
    "triggerFaultRead", 0, 0, 1, 0, 0 },

  { 974, 31,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M2/EMCY Message pump/fault monitor1",
    "EMCYMsg", 0, 0, 50, 0, 0 },

  { 975, 32,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M2/EMCY Message pump/driveID",
    "", 0, 0, 1, 0, 0 },

  { 976, 32,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M2/EMCY Message pump/Data Type Conversion",
    "", 0, 0, 1, 0, 0 },

  { 977, 33,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M2/PDO to Angles Subsystem/countsToRads/p1",
    "LinkAngle", 0, 0, 1, 0, 0 },

  { 978, 33,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M2/PDO to Angles Subsystem/countsToRads/p2",
    "PrimaryLinkAngle", 1, 0, 1, 0, 0 },

  { 979, 33,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M2/PDO to Angles Subsystem/countsToRads/p3",
    "PrimaryLinkVel", 2, 0, 1, 0, 0 },

  { 980, 33,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M2/PDO to Angles Subsystem/countsToRads/p4",
    "torque", 3, 0, 1, 0, 0 },

  { 981, 33,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M2/PDO to Angles Subsystem/countsToRads/p5",
    "digitalInputs", 4, 0, 8, 0, 0 },

  { 982, 33,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M2/PDO to Angles Subsystem/countsToRads/p6",
    "digitalDiagnostics", 5, 0, 1, 0, 0 },

  { 983, 57,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M2/PDO to Angles Subsystem/L2 select",
    "", 0, 0, 1, 0, 0 },

  { 984, 57,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M2/PDO to Angles Subsystem/L2 select1",
    "", 0, 0, 1, 0, 0 },

  { 985, 57,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M2/PDO to Angles Subsystem/L2 select2",
    "", 0, 0, 1, 0, 0 },

  { 986, 57,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M2/PDO to Angles Subsystem/L2 select3",
    "", 0, 0, 1, 0, 0 },

  { 987, 57,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M2/PDO to Angles Subsystem/L2 select4",
    "", 0, 0, 1, 0, 0 },

  { 988, 57,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M2/PDO to Angles Subsystem/L2 select5",
    "", 0, 0, 1, 0, 0 },

  { 989, 42,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/SDO reading/Read Drive 1 SDO/converter/p1",
    "uint32Out", 0, 4, 1, 0, 0 },

  { 990, 42,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/SDO reading/Read Drive 1 SDO/converter/p2",
    "int32Out", 1, 3, 1, 0, 0 },

  { 991, 42,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/SDO reading/Read Drive 1 SDO/converter/p3",
    "doubleOut", 2, 0, 1, 0, 0 },

  { 992, 43,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/SDO reading/Read Drive 1 SDO/Data Type Conversion",
    "", 0, 0, 1, 0, 0 },

  { 993, 43,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/SDO reading/Read Drive 1 SDO/BKIN EtherCAT Async SDO Upload1/p1",
    "", 0, 4, 1, 0, 0 },

  { 994, 43,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/SDO reading/Read Drive 1 SDO/BKIN EtherCAT Async SDO Upload1/p2",
    "", 1, 3, 1, 0, 0 },

  { 995, 51,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/int subsystem/Read Drive 1 SDO/converter/p1",
    "uint32Out", 0, 4, 1, 0, 0 },

  { 996, 51,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/int subsystem/Read Drive 1 SDO/converter/p2",
    "int32Out", 1, 3, 1, 0, 0 },

  { 997, 51,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/int subsystem/Read Drive 1 SDO/converter/p3",
    "doubleOut", 2, 0, 1, 0, 0 },

  { 998, 52,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/int subsystem/Read Drive 1 SDO/Data Type Conversion",
    "", 0, 0, 1, 0, 0 },

  { 999, 52,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/int subsystem/Read Drive 1 SDO/BKIN EtherCAT Async SDO Upload1/p1",
    "", 0, 4, 1, 0, 0 },

  { 1000, 52,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/int subsystem/Read Drive 1 SDO/BKIN EtherCAT Async SDO Upload1/p2",
    "", 1, 3, 1, 0, 0 },

  { 1001, 58,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M1/A2M1 PDOs/parse status register1/p1",
    "allOK", 0, 4, 1, 0, 0 },

  { 1002, 58,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M1/A2M1 PDOs/parse status register1/p2",
    "ampStatus", 1, 4, 1, 0, 0 },

  { 1003, 58,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M1/A2M1 PDOs/parse status register1/p3",
    "servoEnabled", 2, 4, 1, 0, 0 },

  { 1004, 58,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M1/A2M1 PDOs/parse status register1/p4",
    "faultFound", 3, 4, 1, 0, 0 },

  { 1005, 58,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M1/A2M1 PDOs/parse status register1/p5",
    "currentLimitEnabled", 4, 4, 1, 0, 0 },

  { 1006, 58,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M1/A2M1 PDOs/parse status register1/p6",
    "eStopOut", 5, 4, 1, 0, 0 },

  { 1007, 58,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M1/A2M1 PDOs/parse status register1/p7",
    "motorOn", 6, 4, 1, 0, 0 },

  { 1008, 59,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M1/A2M1 PDOs/A2M1Convert",
    "", 0, 0, 50, 0, 0 },

  { 1009, 59,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M1/A2M1 PDOs/Data Type Conversion",
    "", 0, 3, 1, 0, 0 },

  { 1010, 59,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M1/A2M1 PDOs/BKIN PDO Receive ElmoDrive/p1",
    "Status word", 0, 1, 1, 0, 0 },

  { 1011, 59,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M1/A2M1 PDOs/BKIN PDO Receive ElmoDrive/p2",
    "status register", 1, 4, 1, 0, 0 },

  { 1012, 59,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M1/A2M1 PDOs/BKIN PDO Receive ElmoDrive/p3",
    "primary position", 2, 3, 1, 0, 0 },

  { 1013, 59,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M1/A2M1 PDOs/BKIN PDO Receive ElmoDrive/p4",
    "secondary position", 3, 3, 1, 0, 0 },

  { 1014, 59,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M1/A2M1 PDOs/BKIN PDO Receive ElmoDrive/p5",
    "primary velocity", 4, 3, 1, 0, 0 },

  { 1015, 59,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M1/A2M1 PDOs/BKIN PDO Receive ElmoDrive/p6",
    "torque", 5, 7, 1, 0, 0 },

  { 1016, 59,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M1/A2M1 PDOs/BKIN PDO Receive ElmoDrive/p7",
    "digital input", 6, 3, 1, 0, 0 },

  { 1017, 59,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M1/A2M1 PDOs/BKIN PDO Receive ElmoDrive/p8",
    "actual mode of operation", 7, 8, 1, 0, 0 },

  { 1018, 97,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M1/Compare/Compare",
    "", 0, 2, 1, 0, 0 },

  { 1019, 61,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M1/EMCY Message pump/Read EMCY/p1",
    "triggerCountRead", 0, 3, 1, 0, 0 },

  { 1020, 61,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M1/EMCY Message pump/Read EMCY/p2",
    "emcyReadTrigger", 1, 3, 2, 0, 0 },

  { 1021, 61,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M1/EMCY Message pump/Read EMCY/p3",
    "countOverwriteTrigger", 2, 3, 1, 0, 0 },

  { 1022, 61,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M1/EMCY Message pump/Read EMCY/p4",
    "emcyValPump", 3, 0, 41, 0, 0 },

  { 1023, 62,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M1/EMCY Message pump/fault monitor",
    "triggerFaultRead", 0, 0, 1, 0, 0 },

  { 1024, 63,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M1/EMCY Message pump/fault monitor1",
    "EMCYMsg", 0, 0, 50, 0, 0 },

  { 1025, 64,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M1/EMCY Message pump/driveID",
    "", 0, 0, 1, 0, 0 },

  { 1026, 64,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M1/EMCY Message pump/Data Type Conversion",
    "", 0, 0, 1, 0, 0 },

  { 1027, 65,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M1/PDO to Angles Subsystem/countsToRads/p1",
    "LinkAngle", 0, 0, 1, 0, 0 },

  { 1028, 65,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M1/PDO to Angles Subsystem/countsToRads/p2",
    "PrimaryLinkAngle", 1, 0, 1, 0, 0 },

  { 1029, 65,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M1/PDO to Angles Subsystem/countsToRads/p3",
    "PrimaryLinkVel", 2, 0, 1, 0, 0 },

  { 1030, 65,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M1/PDO to Angles Subsystem/countsToRads/p4",
    "torque", 3, 0, 1, 0, 0 },

  { 1031, 65,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M1/PDO to Angles Subsystem/countsToRads/p5",
    "digitalInputs", 4, 0, 8, 0, 0 },

  { 1032, 65,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M1/PDO to Angles Subsystem/countsToRads/p6",
    "digitalDiagnostics", 5, 0, 1, 0, 0 },

  { 1033, 65,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M1/PDO to Angles Subsystem/countsToRads/p7",
    "calibrationButton", 6, 0, 1, 0, 0 },

  { 1034, 97,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M1/PDO to Angles Subsystem/L2 select",
    "offset rads", 0, 0, 1, 0, 0 },

  { 1035, 97,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M1/PDO to Angles Subsystem/L2 select1",
    "enc orient", 0, 0, 1, 0, 0 },

  { 1036, 97,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M1/PDO to Angles Subsystem/L2 select2",
    "", 0, 0, 1, 0, 0 },

  { 1037, 97,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M1/PDO to Angles Subsystem/L2 select3",
    "", 0, 0, 1, 0, 0 },

  { 1038, 97,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M1/PDO to Angles Subsystem/L2 select4",
    "", 0, 0, 1, 0, 0 },

  { 1039, 97,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M1/PDO to Angles Subsystem/L2 select5",
    "", 0, 0, 1, 0, 0 },

  { 1040, 66,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M2/A2M2 PDOs/parse status register1/p1",
    "allOK", 0, 4, 1, 0, 0 },

  { 1041, 66,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M2/A2M2 PDOs/parse status register1/p2",
    "ampStatus", 1, 4, 1, 0, 0 },

  { 1042, 66,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M2/A2M2 PDOs/parse status register1/p3",
    "servoEnabled", 2, 4, 1, 0, 0 },

  { 1043, 66,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M2/A2M2 PDOs/parse status register1/p4",
    "faultFound", 3, 4, 1, 0, 0 },

  { 1044, 66,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M2/A2M2 PDOs/parse status register1/p5",
    "currentLimitEnabled", 4, 4, 1, 0, 0 },

  { 1045, 66,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M2/A2M2 PDOs/parse status register1/p6",
    "eStopOut", 5, 4, 1, 0, 0 },

  { 1046, 66,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M2/A2M2 PDOs/parse status register1/p7",
    "motorOn", 6, 4, 1, 0, 0 },

  { 1047, 67,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M2/A2M2 PDOs/A2M2Convert",
    "", 0, 0, 50, 0, 0 },

  { 1048, 67,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M2/A2M2 PDOs/Data Type Conversion",
    "", 0, 3, 1, 0, 0 },

  { 1049, 67,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M2/A2M2 PDOs/BKIN PDO Receive ElmoDrive/p1",
    "status word", 0, 1, 1, 0, 0 },

  { 1050, 67,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M2/A2M2 PDOs/BKIN PDO Receive ElmoDrive/p2",
    "status register", 1, 4, 1, 0, 0 },

  { 1051, 67,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M2/A2M2 PDOs/BKIN PDO Receive ElmoDrive/p3",
    "position primary", 2, 3, 1, 0, 0 },

  { 1052, 67,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M2/A2M2 PDOs/BKIN PDO Receive ElmoDrive/p4",
    "position secondary", 3, 3, 1, 0, 0 },

  { 1053, 67,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M2/A2M2 PDOs/BKIN PDO Receive ElmoDrive/p5",
    "velocity primary", 4, 3, 1, 0, 0 },

  { 1054, 67,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M2/A2M2 PDOs/BKIN PDO Receive ElmoDrive/p6",
    "torque", 5, 7, 1, 0, 0 },

  { 1055, 67,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M2/A2M2 PDOs/BKIN PDO Receive ElmoDrive/p7",
    "digital input", 6, 3, 1, 0, 0 },

  { 1056, 67,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M2/A2M2 PDOs/BKIN PDO Receive ElmoDrive/p8",
    "actual mode of operation", 7, 8, 1, 0, 0 },

  { 1057, 97,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M2/Compare/Compare",
    "", 0, 2, 1, 0, 0 },

  { 1058, 69,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M2/EMCY Message pump/Read EMCY/p1",
    "triggerCountRead", 0, 3, 1, 0, 0 },

  { 1059, 69,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M2/EMCY Message pump/Read EMCY/p2",
    "emcyReadTrigger", 1, 3, 2, 0, 0 },

  { 1060, 69,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M2/EMCY Message pump/Read EMCY/p3",
    "countOverwriteTrigger", 2, 3, 1, 0, 0 },

  { 1061, 69,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M2/EMCY Message pump/Read EMCY/p4",
    "emcyValPump", 3, 0, 41, 0, 0 },

  { 1062, 70,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M2/EMCY Message pump/fault monitor",
    "triggerFaultRead", 0, 0, 1, 0, 0 },

  { 1063, 71,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M2/EMCY Message pump/fault monitor1",
    "EMCYMsg", 0, 0, 50, 0, 0 },

  { 1064, 72,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M2/EMCY Message pump/driveID",
    "", 0, 0, 1, 0, 0 },

  { 1065, 72,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M2/EMCY Message pump/Data Type Conversion",
    "", 0, 0, 1, 0, 0 },

  { 1066, 73,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M2/PDO to Angles Subsystem/countsToRads/p1",
    "LinkAngle", 0, 0, 1, 0, 0 },

  { 1067, 73,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M2/PDO to Angles Subsystem/countsToRads/p2",
    "PrimaryLinkAngle", 1, 0, 1, 0, 0 },

  { 1068, 73,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M2/PDO to Angles Subsystem/countsToRads/p3",
    "PrimaryLinkVel", 2, 0, 1, 0, 0 },

  { 1069, 73,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M2/PDO to Angles Subsystem/countsToRads/p4",
    "torque", 3, 0, 1, 0, 0 },

  { 1070, 73,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M2/PDO to Angles Subsystem/countsToRads/p5",
    "digitalInputs", 4, 0, 8, 0, 0 },

  { 1071, 73,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M2/PDO to Angles Subsystem/countsToRads/p6",
    "digitalDiagnostics", 5, 0, 1, 0, 0 },

  { 1072, 97,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M2/PDO to Angles Subsystem/L2 select",
    "", 0, 0, 1, 0, 0 },

  { 1073, 97,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M2/PDO to Angles Subsystem/L2 select1",
    "", 0, 0, 1, 0, 0 },

  { 1074, 97,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M2/PDO to Angles Subsystem/L2 select2",
    "", 0, 0, 1, 0, 0 },

  { 1075, 97,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M2/PDO to Angles Subsystem/L2 select3",
    "", 0, 0, 1, 0, 0 },

  { 1076, 97,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M2/PDO to Angles Subsystem/L2 select4",
    "", 0, 0, 1, 0, 0 },

  { 1077, 97,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M2/PDO to Angles Subsystem/L2 select5",
    "", 0, 0, 1, 0, 0 },

  { 1078, 82,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/SDO reading/Read Drive 3 SDO/converter/p1",
    "uint32Out", 0, 4, 1, 0, 0 },

  { 1079, 82,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/SDO reading/Read Drive 3 SDO/converter/p2",
    "int32Out", 1, 3, 1, 0, 0 },

  { 1080, 82,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/SDO reading/Read Drive 3 SDO/converter/p3",
    "doubleOut", 2, 0, 1, 0, 0 },

  { 1081, 83,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/SDO reading/Read Drive 3 SDO/Data Type Conversion",
    "", 0, 0, 1, 0, 0 },

  { 1082, 83,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/SDO reading/Read Drive 3 SDO/BKIN EtherCAT Async SDO Upload1/p1",
    "", 0, 4, 1, 0, 0 },

  { 1083, 83,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/SDO reading/Read Drive 3 SDO/BKIN EtherCAT Async SDO Upload1/p2",
    "", 1, 3, 1, 0, 0 },

  { 1084, 91,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/int subsystem/Read Drive 3 SDO/converter/p1",
    "uint32Out", 0, 4, 1, 0, 0 },

  { 1085, 91,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/int subsystem/Read Drive 3 SDO/converter/p2",
    "int32Out", 1, 3, 1, 0, 0 },

  { 1086, 91,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/int subsystem/Read Drive 3 SDO/converter/p3",
    "doubleOut", 2, 0, 1, 0, 0 },

  { 1087, 92,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/int subsystem/Read Drive 3 SDO/Data Type Conversion",
    "", 0, 0, 1, 0, 0 },

  { 1088, 92,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/int subsystem/Read Drive 3 SDO/BKIN EtherCAT Async SDO Upload1/p1",
    "", 0, 4, 1, 0, 0 },

  { 1089, 92,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/int subsystem/Read Drive 3 SDO/BKIN EtherCAT Async SDO Upload1/p2",
    "", 1, 3, 1, 0, 0 },

  { 1090, 131,
    "DataLogging/Poll KINARM/PMAC Subsystem/read_pmac/DPRAM Access Subsystem/Counter Free-Running/Output",
    "", 0, 1, 1, 0, 0 },

  { 1091, 125,
    "DataLogging/Poll KINARM/PMAC Subsystem/read_pmac/DPRAM Access Subsystem/Read DPRAM/Data Type Conversion",
    "", 0, 4, 1, 0, 0 },

  { 1092, 125,
    "DataLogging/Poll KINARM/PMAC Subsystem/read_pmac/DPRAM Access Subsystem/Read DPRAM/Data Type Conversion1",
    "", 0, 0, 1, 0, 0 },

  { 1093, 125,
    "DataLogging/Poll KINARM/PMAC Subsystem/read_pmac/DPRAM Access Subsystem/Read DPRAM/Data Type Conversion2",
    "", 0, 4, 1, 0, 0 },

  { 1094, 125,
    "DataLogging/Poll KINARM/PMAC Subsystem/read_pmac/DPRAM Access Subsystem/Read DPRAM/Read",
    "", 0, 6, 1, 0, 0 },

  { 1095, 127,
    "DataLogging/Poll KINARM/PMAC Subsystem/read_pmac/DPRAM Access Subsystem/Write DPRAM/Data Type Conversion",
    "", 0, 4, 1, 0, 0 },

  { 1096, 127,
    "DataLogging/Poll KINARM/PMAC Subsystem/read_pmac/DPRAM Access Subsystem/Write DPRAM/Data Type Conversion1",
    "", 0, 6, 1, 0, 0 },

  { 1097, 135,
    "DataLogging/Poll KINARM/bkin_internal_testing/Data receive/Counter Free-Running/Increment Real World/FixPt Sum1",
    "", 0, 4, 1, 0, 0 },

  { 1098, 135,
    "DataLogging/Poll KINARM/bkin_internal_testing/Data receive/Counter Free-Running/Wrap To Zero/FixPt Switch",
    "", 0, 4, 1, 0, 0 },

  { 1099, 24,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M1/EMCY Message pump/Read EMCY Count/Data Type Conversion",
    "", 0, 3, 1, 0, 0 },

  { 1100, 24,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M1/EMCY Message pump/Read EMCY Count/Data Type Conversion1",
    "", 0, 4, 1, 0, 0 },

  { 1101, 24,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M1/EMCY Message pump/Read EMCY Count/Data Type Conversion2",
    "", 0, 0, 2, 0, 0 },

  { 1102, 24,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M1/EMCY Message pump/Read EMCY Count/Memory",
    "", 0, 4, 2, 0, 0 },

  { 1103, 24,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M1/EMCY Message pump/Read EMCY Count/Rate Transition",
    "", 0, 4, 2, 0, 0 },

  { 1104, 24,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M1/EMCY Message pump/Read EMCY Count/BKIN EtherCAT Async SDO Upload/p1",
    "", 0, 4, 1, 0, 0 },

  { 1105, 24,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M1/EMCY Message pump/Read EMCY Count/BKIN EtherCAT Async SDO Upload/p2",
    "", 1, 3, 1, 0, 0 },

  { 1106, 24,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M1/EMCY Message pump/Read EMCY Value/Data Type Conversion",
    "", 0, 0, 2, 0, 0 },

  { 1107, 24,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M1/EMCY Message pump/Read EMCY Value/Memory",
    "", 0, 3, 2, 0, 0 },

  { 1108, 24,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M1/EMCY Message pump/Read EMCY Value/Rate Transition",
    "", 0, 3, 2, 0, 0 },

  { 1109, 24,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M1/EMCY Message pump/Read EMCY Value/BKIN EtherCAT Async SDO Upload/p1",
    "", 0, 3, 1, 0, 0 },

  { 1110, 24,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M1/EMCY Message pump/Read EMCY Value/BKIN EtherCAT Async SDO Upload/p2",
    "", 1, 3, 1, 0, 0 },

  { 1111, 24,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M1/EMCY Message pump/clear errors/Data Type Conversion",
    "", 0, 3, 1, 0, 0 },

  { 1112, 24,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M1/EMCY Message pump/clear errors/Data Type Conversion1",
    "", 0, 0, 1, 0, 0 },

  { 1113, 24,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M1/EMCY Message pump/clear errors/Memory",
    "", 0, 0, 1, 0, 0 },

  { 1114, 24,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M1/EMCY Message pump/clear errors/BKIN EtherCAT Async SDO Download",
    "", 0, 3, 1, 0, 0 },

  { 1115, 32,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M2/EMCY Message pump/Read EMCY Count/Data Type Conversion",
    "", 0, 3, 1, 0, 0 },

  { 1116, 32,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M2/EMCY Message pump/Read EMCY Count/Data Type Conversion1",
    "", 0, 4, 1, 0, 0 },

  { 1117, 32,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M2/EMCY Message pump/Read EMCY Count/Data Type Conversion2",
    "", 0, 0, 2, 0, 0 },

  { 1118, 32,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M2/EMCY Message pump/Read EMCY Count/Memory",
    "", 0, 4, 2, 0, 0 },

  { 1119, 32,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M2/EMCY Message pump/Read EMCY Count/Rate Transition",
    "", 0, 4, 2, 0, 0 },

  { 1120, 32,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M2/EMCY Message pump/Read EMCY Count/BKIN EtherCAT Async SDO Upload/p1",
    "", 0, 4, 1, 0, 0 },

  { 1121, 32,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M2/EMCY Message pump/Read EMCY Count/BKIN EtherCAT Async SDO Upload/p2",
    "", 1, 3, 1, 0, 0 },

  { 1122, 32,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M2/EMCY Message pump/Read EMCY Value/Data Type Conversion",
    "", 0, 0, 2, 0, 0 },

  { 1123, 32,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M2/EMCY Message pump/Read EMCY Value/Memory",
    "", 0, 3, 2, 0, 0 },

  { 1124, 32,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M2/EMCY Message pump/Read EMCY Value/Rate Transition",
    "", 0, 3, 2, 0, 0 },

  { 1125, 32,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M2/EMCY Message pump/Read EMCY Value/BKIN EtherCAT Async SDO Upload/p1",
    "", 0, 3, 1, 0, 0 },

  { 1126, 32,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M2/EMCY Message pump/Read EMCY Value/BKIN EtherCAT Async SDO Upload/p2",
    "", 1, 3, 1, 0, 0 },

  { 1127, 32,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M2/EMCY Message pump/clear errors/Data Type Conversion",
    "", 0, 3, 1, 0, 0 },

  { 1128, 32,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M2/EMCY Message pump/clear errors/Data Type Conversion1",
    "", 0, 0, 1, 0, 0 },

  { 1129, 32,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M2/EMCY Message pump/clear errors/Memory",
    "", 0, 0, 1, 0, 0 },

  { 1130, 32,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M2/EMCY Message pump/clear errors/BKIN EtherCAT Async SDO Download",
    "", 0, 3, 1, 0, 0 },

  { 1131, 64,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M1/EMCY Message pump/Read EMCY Count/Data Type Conversion",
    "", 0, 3, 1, 0, 0 },

  { 1132, 64,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M1/EMCY Message pump/Read EMCY Count/Data Type Conversion1",
    "", 0, 4, 1, 0, 0 },

  { 1133, 64,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M1/EMCY Message pump/Read EMCY Count/Data Type Conversion2",
    "", 0, 0, 2, 0, 0 },

  { 1134, 64,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M1/EMCY Message pump/Read EMCY Count/Memory",
    "", 0, 4, 2, 0, 0 },

  { 1135, 64,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M1/EMCY Message pump/Read EMCY Count/Rate Transition",
    "", 0, 4, 2, 0, 0 },

  { 1136, 64,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M1/EMCY Message pump/Read EMCY Count/BKIN EtherCAT Async SDO Upload/p1",
    "", 0, 4, 1, 0, 0 },

  { 1137, 64,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M1/EMCY Message pump/Read EMCY Count/BKIN EtherCAT Async SDO Upload/p2",
    "", 1, 3, 1, 0, 0 },

  { 1138, 64,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M1/EMCY Message pump/Read EMCY Value/Data Type Conversion",
    "", 0, 0, 2, 0, 0 },

  { 1139, 64,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M1/EMCY Message pump/Read EMCY Value/Memory",
    "", 0, 3, 2, 0, 0 },

  { 1140, 64,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M1/EMCY Message pump/Read EMCY Value/Rate Transition",
    "", 0, 3, 2, 0, 0 },

  { 1141, 64,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M1/EMCY Message pump/Read EMCY Value/BKIN EtherCAT Async SDO Upload/p1",
    "", 0, 3, 1, 0, 0 },

  { 1142, 64,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M1/EMCY Message pump/Read EMCY Value/BKIN EtherCAT Async SDO Upload/p2",
    "", 1, 3, 1, 0, 0 },

  { 1143, 64,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M1/EMCY Message pump/clear errors/Data Type Conversion",
    "", 0, 3, 1, 0, 0 },

  { 1144, 64,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M1/EMCY Message pump/clear errors/Data Type Conversion1",
    "", 0, 0, 1, 0, 0 },

  { 1145, 64,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M1/EMCY Message pump/clear errors/Memory",
    "", 0, 0, 1, 0, 0 },

  { 1146, 64,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M1/EMCY Message pump/clear errors/BKIN EtherCAT Async SDO Download",
    "", 0, 3, 1, 0, 0 },

  { 1147, 72,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M2/EMCY Message pump/Read EMCY Count/Data Type Conversion",
    "", 0, 3, 1, 0, 0 },

  { 1148, 72,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M2/EMCY Message pump/Read EMCY Count/Data Type Conversion1",
    "", 0, 4, 1, 0, 0 },

  { 1149, 72,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M2/EMCY Message pump/Read EMCY Count/Data Type Conversion2",
    "", 0, 0, 2, 0, 0 },

  { 1150, 72,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M2/EMCY Message pump/Read EMCY Count/Memory",
    "", 0, 4, 2, 0, 0 },

  { 1151, 72,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M2/EMCY Message pump/Read EMCY Count/Rate Transition",
    "", 0, 4, 2, 0, 0 },

  { 1152, 72,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M2/EMCY Message pump/Read EMCY Count/BKIN EtherCAT Async SDO Upload/p1",
    "", 0, 4, 1, 0, 0 },

  { 1153, 72,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M2/EMCY Message pump/Read EMCY Count/BKIN EtherCAT Async SDO Upload/p2",
    "", 1, 3, 1, 0, 0 },

  { 1154, 72,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M2/EMCY Message pump/Read EMCY Value/Data Type Conversion",
    "", 0, 0, 2, 0, 0 },

  { 1155, 72,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M2/EMCY Message pump/Read EMCY Value/Memory",
    "", 0, 3, 2, 0, 0 },

  { 1156, 72,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M2/EMCY Message pump/Read EMCY Value/Rate Transition",
    "", 0, 3, 2, 0, 0 },

  { 1157, 72,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M2/EMCY Message pump/Read EMCY Value/BKIN EtherCAT Async SDO Upload/p1",
    "", 0, 3, 1, 0, 0 },

  { 1158, 72,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M2/EMCY Message pump/Read EMCY Value/BKIN EtherCAT Async SDO Upload/p2",
    "", 1, 3, 1, 0, 0 },

  { 1159, 72,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M2/EMCY Message pump/clear errors/Data Type Conversion",
    "", 0, 3, 1, 0, 0 },

  { 1160, 72,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M2/EMCY Message pump/clear errors/Data Type Conversion1",
    "", 0, 0, 1, 0, 0 },

  { 1161, 72,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M2/EMCY Message pump/clear errors/Memory",
    "", 0, 0, 1, 0, 0 },

  { 1162, 72,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M2/EMCY Message pump/clear errors/BKIN EtherCAT Async SDO Download",
    "", 0, 3, 1, 0, 0 },

  { 1163, 131,
    "DataLogging/Poll KINARM/PMAC Subsystem/read_pmac/DPRAM Access Subsystem/Counter Free-Running/Increment Real World/FixPt Sum1",
    "", 0, 1, 1, 0, 0 },

  { 1164, 131,
    "DataLogging/Poll KINARM/PMAC Subsystem/read_pmac/DPRAM Access Subsystem/Counter Free-Running/Wrap To Zero/FixPt Switch",
    "", 0, 1, 1, 0, 0 },

  {
    0, 0, NULL, NULL, 0, 0, 0, 0, 0
  }
};

static const rtwCAPI_BlockParameters rtBlockParameters[] = {
  /* addrMapIndex, blockPath,
   * paramName, dataTypeIndex, dimIndex, fixPtIdx
   */
  { 1165, "Compare To Constant",
    "const", 0, 1, 0 },

  { 1166, "GUI Control",
    "XYcols", 0, 75, 0 },

  { 1167, "GUI Control",
    "Vcols", 0, 1, 0 },

  { 1168, "GUI Control",
    "Lcols", 0, 1, 0 },

  { 1169, "Hand_Feedback",
    "feedback_cntl_src", 0, 1, 0 },

  { 1170, "KINARM_DistanceFromTarget",
    "use_dominant_hand", 0, 1, 0 },

  { 1171, "KINARM_HandInBox",
    "use_dominant_hand", 0, 1, 0 },

  { 1172, "KINARM_HandInBox",
    "target_type", 0, 1, 0 },

  { 1173, "KINARM_HandInBox",
    "num_states", 0, 1, 0 },

  { 1174, "KINARM_HandInBox",
    "attribcol1", 0, 76, 0 },

  { 1175, "KINARM_HandInTarget",
    "use_dominant_hand", 0, 1, 0 },

  { 1176, "KINARM_HandInTarget",
    "target_type", 0, 1, 0 },

  { 1177, "KINARM_HandInTarget",
    "num_states", 0, 1, 0 },

  { 1178, "KINARM_HandInTarget",
    "attribcol1", 0, 1, 0 },

  { 1179, "Process_Video_CMD",
    "video_delay", 0, 1, 0 },

  { 1180, "Show_Box",
    "target_type", 0, 1, 0 },

  { 1181, "Show_Box",
    "num_states", 0, 1, 0 },

  { 1182, "Show_Box",
    "attribcol1", 0, 77, 0 },

  { 1183, "Show_Box",
    "attribcol2", 0, 77, 0 },

  { 1184, "Show_Box",
    "opacity", 0, 1, 0 },

  { 1185, "Show_Box",
    "target_display", 0, 1, 0 },

  { 1186, "Show_TargetB_With_Label",
    "target_type", 0, 1, 0 },

  { 1187, "Show_TargetB_With_Label",
    "num_states", 0, 1, 0 },

  { 1188, "Show_TargetB_With_Label",
    "attribcol1", 0, 78, 0 },

  { 1189, "Show_TargetB_With_Label",
    "attribcol2", 0, 78, 0 },

  { 1190, "Show_TargetB_With_Label",
    "attribcol3", 0, 78, 0 },

  { 1191, "Show_TargetB_With_Label",
    "opacity", 0, 1, 0 },

  { 1192, "Show_TargetB_With_Label",
    "target_display", 0, 1, 0 },

  { 1193, "Show_TargetC_With_Label",
    "target_type", 0, 1, 0 },

  { 1194, "Show_TargetC_With_Label",
    "num_states", 0, 1, 0 },

  { 1195, "Show_TargetC_With_Label",
    "attribcol1", 0, 78, 0 },

  { 1196, "Show_TargetC_With_Label",
    "attribcol2", 0, 78, 0 },

  { 1197, "Show_TargetC_With_Label",
    "attribcol3", 0, 78, 0 },

  { 1198, "Show_TargetC_With_Label",
    "opacity", 0, 1, 0 },

  { 1199, "Show_TargetC_With_Label",
    "target_display", 0, 1, 0 },

  { 1200, "Show_Target_A",
    "target_type", 0, 1, 0 },

  { 1201, "Show_Target_A",
    "num_states", 0, 1, 0 },

  { 1202, "Show_Target_A",
    "attribcol1", 0, 79, 0 },

  { 1203, "Show_Target_A",
    "attribcol2", 0, 79, 0 },

  { 1204, "Show_Target_A",
    "opacity", 0, 1, 0 },

  { 1205, "Show_Target_A",
    "target_display", 0, 1, 0 },

  { 1206, "Switch",
    "Threshold", 0, 1, 0 },

  { 1207, "Switch1",
    "Threshold", 0, 1, 0 },

  { 1208, "DataLogging/ECAT Dig Diagnostic",
    "InitialValue", 4, 79, 0 },

  { 1209, "DataLogging/ECAT Status",
    "InitialValue", 0, 80, 0 },

  { 1210, "DataLogging/ECAT hardware",
    "InitialValue", 0, 81, 0 },

  { 1211, "DataLogging/ZeroDigOut",
    "Value", 0, 79, 0 },

  { 1212, "DataLogging/ZeroEPTorque",
    "Value", 0, 79, 0 },

  { 1213, "DataLogging/ZeroTorque",
    "Value", 0, 79, 0 },

  { 1214, "DataLogging/seconds_remaining",
    "Value", 0, 1, 0 },

  { 1215, "DataLogging/Memory",
    "X0", 0, 1, 0 },

  { 1216, "DataLogging/Memory1",
    "X0", 0, 1, 0 },

  { 1217, "DisplayInstruct/Show_Target",
    "target_type", 0, 1, 0 },

  { 1218, "DisplayInstruct/Show_Target",
    "num_states", 0, 1, 0 },

  { 1219, "DisplayInstruct/Show_Target",
    "attribcol1", 0, 77, 0 },

  { 1220, "DisplayInstruct/Show_Target",
    "opacity", 0, 1, 0 },

  { 1221, "DisplayInstruct/Show_Target",
    "target_display", 0, 1, 0 },

  { 1222, "DisplayInstruct/Constant",
    "Value", 0, 1, 0 },

  { 1223, "DisplayText/Show_Target_With_Label1",
    "target_type", 0, 1, 0 },

  { 1224, "DisplayText/Show_Target_With_Label1",
    "num_states", 0, 1, 0 },

  { 1225, "DisplayText/Show_Target_With_Label1",
    "attribcol1", 0, 82, 0 },

  { 1226, "DisplayText/Show_Target_With_Label1",
    "opacity", 0, 1, 0 },

  { 1227, "DisplayText/Show_Target_With_Label1",
    "target_display", 0, 1, 0 },

  { 1228, "DisplayText/Switch",
    "Threshold", 0, 1, 0 },

  { 1229, "GUI Control/Block Definitions",
    "Value", 0, 15, 0 },

  { 1230, "GUI Control/Block Sequence",
    "Value", 0, 16, 0 },

  { 1231, "GUI Control/Constant",
    "Value", 0, 1, 0 },

  { 1232, "GUI Control/Display Size (m)",
    "Value", 0, 75, 0 },

  { 1233, "GUI Control/Display Size (pels)",
    "Value", 0, 75, 0 },

  { 1234, "GUI Control/Docking Points",
    "Value", 0, 21, 0 },

  { 1235, "GUI Control/EL Camera Angle",
    "Value", 0, 75, 0 },

  { 1236, "GUI Control/EL Camera Focal Length",
    "Value", 0, 1, 0 },

  { 1237, "GUI Control/EL Camera Position",
    "Value", 0, 76, 0 },

  { 1238, "GUI Control/EL Tracking Available",
    "Value", 0, 1, 0 },

  { 1239, "GUI Control/Library Patch Version",
    "Value", 0, 1, 0 },

  { 1240, "GUI Control/Library Version",
    "Value", 0, 1, 0 },

  { 1241, "GUI Control/Load Table",
    "Value", 0, 17, 0 },

  { 1242, "GUI Control/Next Block",
    "Value", 0, 1, 0 },

  { 1243, "GUI Control/Pause Type",
    "Value", 0, 1, 0 },

  { 1244, "GUI Control/Run Task Clock Flag",
    "Value", 0, 1, 0 },

  { 1245, "GUI Control/Seed",
    "Value", 0, 1, 0 },

  { 1246, "GUI Control/Subject Height",
    "Value", 0, 1, 0 },

  { 1247, "GUI Control/Subject Weight",
    "Value", 0, 1, 0 },

  { 1248, "GUI Control/TP Table",
    "Value", 0, 83, 0 },

  { 1249, "GUI Control/Target Labels",
    "Value", 0, 20, 0 },

  { 1250, "GUI Control/Target Table",
    "Value", 0, 18, 0 },

  { 1251, "GUI Control/Task Version",
    "Value", 0, 1, 0 },

  { 1252, "GUI Control/Task wide param",
    "Value", 0, 19, 0 },

  { 1253, "GUI Control/Use Repeat Trial Flag",
    "Value", 0, 1, 0 },

  { 1254, "GUI Control/Use Task Protocol Block Sequence Flag",
    "Value", 0, 1, 0 },

  { 1255, "GUI Control/dlm build time",
    "Value", 0, 1, 0 },

  { 1256, "GUI Control/frame_of_reference_center",
    "Value", 0, 75, 0 },

  { 1257, "GUI Control/xPC Version",
    "Value", 0, 1, 0 },

  { 1258, "Hand_Feedback/Assess_arm_VCODE",
    "Value", 0, 84, 0 },

  { 1259, "Hand_Feedback/Contralateral_arm_VCODE",
    "Value", 0, 84, 0 },

  { 1260, "Hand_Feedback/feedback_status",
    "Value", 0, 1, 0 },

  { 1261, "KINARM_HandInBox/Selected States",
    "Value", 0, 1, 0 },

  { 1262, "KINARM_HandInBox/attribcol2",
    "Value", 0, 76, 0 },

  { 1263, "KINARM_HandInBox/attribcol3",
    "Value", 0, 76, 0 },

  { 1264, "KINARM_HandInBox/attribcol4",
    "Value", 0, 76, 0 },

  { 1265, "KINARM_HandInBox/attribcol5",
    "Value", 0, 76, 0 },

  { 1266, "KINARM_HandInTarget/Selected States",
    "Value", 0, 1, 0 },

  { 1267, "KINARM_HandInTarget/attribcol2",
    "Value", 0, 1, 0 },

  { 1268, "KINARM_HandInTarget/attribcol3",
    "Value", 0, 1, 0 },

  { 1269, "KINARM_HandInTarget/attribcol4",
    "Value", 0, 1, 0 },

  { 1270, "KINARM_HandInTarget/attribcol5",
    "Value", 0, 1, 0 },

  { 1271, "Process_Video_CMD/GUI_VCODE",
    "Value", 0, 85, 0 },

  { 1272, "Process_Video_CMD/Gain",
    "Gain", 0, 1, 0 },

  { 1273, "Process_Video_CMD/Memory",
    "X0", 0, 1, 0 },

  { 1274, "Process_Video_CMD/Receive",
    "P1", 0, 86, 0 },

  { 1275, "Process_Video_CMD/Receive",
    "P2", 0, 1, 0 },

  { 1276, "Process_Video_CMD/Receive",
    "P3", 0, 1, 0 },

  { 1277, "Process_Video_CMD/Receive",
    "P4", 0, 1, 0 },

  { 1278, "Process_Video_CMD/Receive",
    "P5", 0, 1, 0 },

  { 1279, "Process_Video_CMD/Send",
    "P1", 0, 86, 0 },

  { 1280, "Process_Video_CMD/Send",
    "P2", 0, 1, 0 },

  { 1281, "Process_Video_CMD/Send",
    "P3", 0, 1, 0 },

  { 1282, "Process_Video_CMD/Send",
    "P4", 0, 1, 0 },

  { 1283, "Process_Video_CMD/Send",
    "P5", 0, 1, 0 },

  { 1284, "Show_Box/padder",
    "Value", 0, 87, 0 },

  { 1285, "Show_Box/state3_indices",
    "Value", 0, 77, 0 },

  { 1286, "Show_Box/state4_indices",
    "Value", 0, 77, 0 },

  { 1287, "Show_Box/state5_indices",
    "Value", 0, 77, 0 },

  { 1288, "Show_Box/xpos_index",
    "Value", 0, 1, 0 },

  { 1289, "Show_Box/ypos_index",
    "Value", 0, 1, 0 },

  { 1290, "Show_TargetB_With_Label/padder",
    "Value", 0, 88, 0 },

  { 1291, "Show_TargetB_With_Label/state4_indices",
    "Value", 0, 78, 0 },

  { 1292, "Show_TargetB_With_Label/state5_indices",
    "Value", 0, 78, 0 },

  { 1293, "Show_TargetB_With_Label/xpos_index",
    "Value", 0, 1, 0 },

  { 1294, "Show_TargetB_With_Label/ypos_index",
    "Value", 0, 1, 0 },

  { 1295, "Show_TargetC_With_Label/padder",
    "Value", 0, 88, 0 },

  { 1296, "Show_TargetC_With_Label/state4_indices",
    "Value", 0, 78, 0 },

  { 1297, "Show_TargetC_With_Label/state5_indices",
    "Value", 0, 78, 0 },

  { 1298, "Show_TargetC_With_Label/xpos_index",
    "Value", 0, 1, 0 },

  { 1299, "Show_TargetC_With_Label/ypos_index",
    "Value", 0, 1, 0 },

  { 1300, "Show_Target_A/padder",
    "Value", 0, 89, 0 },

  { 1301, "Show_Target_A/state3_indices",
    "Value", 0, 79, 0 },

  { 1302, "Show_Target_A/state4_indices",
    "Value", 0, 79, 0 },

  { 1303, "Show_Target_A/state5_indices",
    "Value", 0, 79, 0 },

  { 1304, "Show_Target_A/xpos_index",
    "Value", 0, 1, 0 },

  { 1305, "Show_Target_A/ypos_index",
    "Value", 0, 1, 0 },

  { 1306, "DataLogging/Create Analog Inputs Subsystem/Not Logging Analog Inputs",
    "Value", 0, 1, 0 },

  { 1307, "DataLogging/Create Custom Data Subsystem/custom_version",
    "Value", 0, 1, 0 },

  { 1308, "DataLogging/Create Custom Data Subsystem/Rate Transition2",
    "X0", 0, 1, 0 },

  { 1309, "DataLogging/Create Event Codes Subsystem/Not Logging Event Codes",
    "Value", 0, 1, 0 },

  { 1310, "DataLogging/Create Task State Subsystem/If Running",
    "const", 4, 1, 0 },

  { 1311, "DataLogging/Create Task State Subsystem/packet_version",
    "Value", 0, 1, 0 },

  { 1312, "DataLogging/Keep alive/const",
    "Value", 0, 90, 0 },

  { 1313, "DataLogging/Keep alive/Send",
    "P1", 0, 86, 0 },

  { 1314, "DataLogging/Keep alive/Send",
    "P2", 0, 1, 0 },

  { 1315, "DataLogging/Keep alive/Send",
    "P3", 0, 1, 0 },

  { 1316, "DataLogging/Keep alive/Send",
    "P4", 0, 1, 0 },

  { 1317, "DataLogging/Keep alive/Send",
    "P5", 0, 1, 0 },

  { 1318, "DataLogging/Network Transfer Subsystem/max_packet_id",
    "Value", 4, 1, 0 },

  { 1319, "DataLogging/Network Transfer Subsystem/runID",
    "Value", 0, 1, 0 },

  { 1320, "DataLogging/Network Transfer Subsystem/Task Clock",
    "Amplitude", 0, 1, 0 },

  { 1321, "DataLogging/Network Transfer Subsystem/Task Clock",
    "Period", 0, 1, 0 },

  { 1322, "DataLogging/Network Transfer Subsystem/Task Clock",
    "PulseWidth", 0, 1, 0 },

  { 1323, "DataLogging/Network Transfer Subsystem/Task Clock",
    "PhaseDelay", 0, 1, 0 },

  { 1324, "DataLogging/Poll Force Plates/ain_offset1",
    "Value", 0, 1, 0 },

  { 1325, "DataLogging/Poll Force Plates/ain_offset2",
    "Value", 0, 1, 0 },

  { 1326, "DataLogging/Poll Force Plates/ain_slope1",
    "Value", 0, 1, 0 },

  { 1327, "DataLogging/Poll Force Plates/ain_slope2",
    "Value", 0, 1, 0 },

  { 1328, "DataLogging/Poll Force Plates/calibration_matrix1",
    "Value", 0, 91, 0 },

  { 1329, "DataLogging/Poll Force Plates/calibration_matrix2",
    "Value", 0, 91, 0 },

  { 1330, "DataLogging/Poll Force Plates/enable_plate1",
    "Value", 0, 1, 0 },

  { 1331, "DataLogging/Poll Force Plates/enable_plate2",
    "Value", 0, 1, 0 },

  { 1332, "DataLogging/Poll Force Plates/gain",
    "Value", 0, 1, 0 },

  { 1333, "DataLogging/Poll Force Plates/orientation1",
    "Value", 0, 1, 0 },

  { 1334, "DataLogging/Poll Force Plates/orientation2",
    "Value", 0, 1, 0 },

  { 1335, "DataLogging/Poll Force Plates/request_packet",
    "Value", 3, 92, 0 },

  { 1336, "DataLogging/Poll Force Plates/zero_voltage",
    "Value", 0, 1, 0 },

  { 1337, "DataLogging/Poll KINARM/ECAT Digital in",
    "InitialValue", 4, 80, 0 },

  { 1338, "DataLogging/Poll KINARM/ECAT Err Msgs",
    "InitialValue", 0, 62, 0 },

  { 1339, "DataLogging/Poll KINARM/ECATTorque feedback",
    "InitialValue", 0, 80, 0 },

  { 1340, "DataLogging/Poll KINARM/HW Settings",
    "InitialValue", 0, 64, 0 },

  { 1341, "DataLogging/Poll KINARM/Kinematics",
    "InitialValue", 0, 6, 0 },

  { 1342, "DataLogging/Poll KINARM/PrimaryEnc",
    "InitialValue", 0, 57, 0 },

  { 1343, "DataLogging/Poll KINARM/Robot Calib",
    "InitialValue", 0, 63, 0 },

  { 1344, "DataLogging/Poll KINARM/RobotRevision",
    "InitialValue", 0, 75, 0 },

  { 1345, "DataLogging/Poll KINARM/ServoUpdate",
    "InitialValue", 4, 1, 0 },

  { 1346, "DataLogging/Poll KINARM/System status",
    "InitialValue", 4, 78, 0 },

  { 1347, "DataLogging/Poll KINARM/calib button",
    "InitialValue", 4, 1, 0 },

  { 1348, "DataLogging/Poll KINARM/delays",
    "InitialValue", 0, 3, 0 },

  { 1349, "DataLogging/Poll KINARM/has FT sensors",
    "InitialValue", 0, 75, 0 },

  { 1350, "DataLogging/Poll KINARM/isecat",
    "const", 0, 1, 0 },

  { 1351, "DataLogging/Poll KINARM/ispmac",
    "const", 0, 1, 0 },

  { 1352, "DataLogging/Poll KINARM/system type",
    "Value", 0, 1, 0 },

  { 1353, "DataLogging/Receive_Gaze/EL Camera Angle",
    "Value", 0, 75, 0 },

  { 1354, "DataLogging/Receive_Gaze/EL Camera Focal Length",
    "Value", 0, 1, 0 },

  { 1355, "DataLogging/Receive_Gaze/EL Camera Position",
    "Value", 0, 76, 0 },

  { 1356, "DataLogging/Receive_Gaze/EL Tracking Available",
    "Value", 0, 1, 0 },

  { 1357, "DataLogging/Receive_Gaze/Gain",
    "Gain", 0, 1, 0 },

  { 1358, "DataLogging/Receive_Gaze/Rate Transition",
    "X0", 0, 1, 0 },

  { 1359, "DataLogging/Receive_Gaze/Receive",
    "P1", 0, 78, 0 },

  { 1360, "DataLogging/Receive_Gaze/Receive",
    "P2", 0, 1, 0 },

  { 1361, "DataLogging/Receive_Gaze/Receive",
    "P3", 0, 1, 0 },

  { 1362, "DataLogging/Receive_Gaze/Receive",
    "P4", 0, 1, 0 },

  { 1363, "DataLogging/Receive_Gaze/Receive",
    "P5", 0, 1, 0 },

  { 1364, "DataLogging/apply loads/isecat",
    "const", 0, 1, 0 },

  { 1365, "DataLogging/apply loads/isecat1",
    "const", 0, 1, 0 },

  { 1366, "DataLogging/create_lab_info/arm_count",
    "Value", 0, 1, 0 },

  { 1367, "DataLogging/create_lab_info/fp1_present",
    "Value", 0, 1, 0 },

  { 1368, "DataLogging/create_lab_info/fp2_present",
    "Value", 0, 1, 0 },

  { 1369, "DataLogging/create_lab_info/gaze_tracker_present",
    "Value", 0, 1, 0 },

  { 1370, "DataLogging/create_lab_info/robot_lift_present",
    "Value", 0, 1, 0 },

  { 1371, "DisplayInstruct/Show_Target/padder",
    "Value", 0, 87, 0 },

  { 1372, "DisplayInstruct/Show_Target/state2_indices",
    "Value", 0, 77, 0 },

  { 1373, "DisplayInstruct/Show_Target/state3_indices",
    "Value", 0, 77, 0 },

  { 1374, "DisplayInstruct/Show_Target/state4_indices",
    "Value", 0, 77, 0 },

  { 1375, "DisplayInstruct/Show_Target/state5_indices",
    "Value", 0, 77, 0 },

  { 1376, "DisplayInstruct/Show_Target/xpos_index",
    "Value", 0, 1, 0 },

  { 1377, "DisplayInstruct/Show_Target/ypos_index",
    "Value", 0, 1, 0 },

  { 1378, "DisplayText/Show_Target_With_Label1/padder",
    "Value", 0, 21, 0 },

  { 1379, "DisplayText/Show_Target_With_Label1/state2_indices",
    "Value", 0, 82, 0 },

  { 1380, "DisplayText/Show_Target_With_Label1/state3_indices",
    "Value", 0, 82, 0 },

  { 1381, "DisplayText/Show_Target_With_Label1/state4_indices",
    "Value", 0, 82, 0 },

  { 1382, "DisplayText/Show_Target_With_Label1/state5_indices",
    "Value", 0, 82, 0 },

  { 1383, "DisplayText/Show_Target_With_Label1/xpos_index",
    "Value", 0, 1, 0 },

  { 1384, "DisplayText/Show_Target_With_Label1/ypos_index",
    "Value", 0, 1, 0 },

  { 1385, "GUI Control/Preview Targets Subsystem/Target_Type",
    "Value", 0, 1, 0 },

  { 1386, "GUI Control/Preview Targets Subsystem/indices_padding",
    "Value", 0, 43, 0 },

  { 1387, "GUI Control/Run Command Subsystem/Hold_to_1Khz",
    "BKIN_STEP_TIME", 0, 1, 0 },

  { 1388, "GUI Control/Run Command Subsystem/Run Command Receive",
    "P1", 0, 78, 0 },

  { 1389, "GUI Control/Run Command Subsystem/Run Command Receive",
    "P2", 0, 1, 0 },

  { 1390, "GUI Control/Run Command Subsystem/Run Command Receive",
    "P3", 0, 1, 0 },

  { 1391, "GUI Control/Run Command Subsystem/Run Command Receive",
    "P4", 0, 1, 0 },

  { 1392, "GUI Control/Run Command Subsystem/Run Command Receive",
    "P5", 0, 1, 0 },

  { 1393, "GUI Control/Task Execution Control Subsystem/Compare To Constant",
    "const", 4, 1, 0 },

  { 1394, "GUI Control/Task Execution Control Subsystem/Constant",
    "Value", 0, 1, 0 },

  { 1395, "GUI Control/Task Execution Control Subsystem/Task Clock",
    "Amplitude", 0, 1, 0 },

  { 1396, "GUI Control/Task Execution Control Subsystem/Task Clock",
    "Period", 0, 1, 0 },

  { 1397, "GUI Control/Task Execution Control Subsystem/Task Clock",
    "PulseWidth", 0, 1, 0 },

  { 1398, "GUI Control/Task Execution Control Subsystem/Task Clock",
    "PhaseDelay", 0, 1, 0 },

  { 1399, "GUI Control/Task Execution Control Subsystem/Delay",
    "X0", 2, 1, 0 },

  { 1400, "GUI Control/Task Execution Control Subsystem/Delay1",
    "X0", 0, 1, 0 },

  { 1401,
    "Parameter Table Defn/TP_table/B1;Target B1 row;float;B1 row in target table;;;none;;",
    "Value", 0, 1, 0 },

  { 1402,
    "Parameter Table Defn/TP_table/B2;Target B2 row;float;B2 row in target table;;;none;;",
    "Value", 0, 1, 0 },

  { 1403,
    "Parameter Table Defn/TP_table/CORR_TGT;Which target is correct;float;Which target is correct (1 or 2) ?;;;none;;",
    "Value", 0, 1, 0 },

  { 1404,
    "Parameter Table Defn/TP_table/DELAY_POST_TRIAL;Trial-End Delay;integer;Time to wait at the end of the trial;;;none;;",
    "Value", 0, 1, 0 },

  { 1405,
    "Parameter Table Defn/TP_table/DISPLAY_TRIAL_COL;Flag Display;integer;Display and pause;;;none;;",
    "Value", 0, 1, 0 },

  { 1406,
    "Parameter Table Defn/TP_table/INCORR_TGT;Which target is incorrect;float;Which target is incorrect (1 or 2) ?;;;none;;",
    "Value", 0, 1, 0 },

  { 1407,
    "Parameter Table Defn/TP_table/MAX_REACH_TIME_COL;Maximum Reach Time;integer;Maximum reach duration allowed;;;none;;",
    "Value", 0, 1, 0 },

  { 1408,
    "Parameter Table Defn/TP_table/RWD_TARGETC1_COL;Target1 Value;float;Reward offered on Target C1;;;none;;",
    "Value", 0, 1, 0 },

  { 1409,
    "Parameter Table Defn/TP_table/RWD_TARGETC2_COL;Target2 Value;float;Reward offered on Target C2;;;none;;",
    "Value", 0, 1, 0 },

  { 1410,
    "Parameter Table Defn/TP_table/START_TARGET_COL;Start target;target;First target to appear during a trial;;;none;;",
    "Value", 0, 1, 0 },

  { 1411,
    "Parameter Table Defn/TP_table/TGT_C_RWD_FRAC;Reward ratio between rowC:rowB;float;How much more will targets B be worth?;;;none;;",
    "Value", 0, 1, 0 },

  { 1412,
    "Parameter Table Defn/buttons/INSTRUCT_PAUSE_BTN;Instruction-Resume;;Button to continue task after displaying instructions;25;22;none;;",
    "Value", 0, 1, 0 },

  { 1413,
    "Parameter Table Defn/events/E_BOX_TRIGGER;Box Was Triggered;;Box triggrered so subject chose row C;;;none;;",
    "Value", 0, 1, 0 },

  { 1414,
    "Parameter Table Defn/events/E_CHOSE_ROW_B;Chose Row B;;Subject chose row B ;;;none;;",
    "Value", 0, 1, 0 },

  { 1415,
    "Parameter Table Defn/events/E_HIT_TARGETB;Hit Target B;;Hit target B;;;none;;",
    "Value", 0, 1, 0 },

  { 1416,
    "Parameter Table Defn/events/E_HIT_TARGETC;Hit Target C;;Hit Target C;;;none;;",
    "Value", 0, 1, 0 },

  { 1417,
    "Parameter Table Defn/events/E_MISS_TARGETB;Miss Targret B;;Miss Targret B;;;none;;",
    "Value", 0, 1, 0 },

  { 1418,
    "Parameter Table Defn/events/E_MISS_TARGETC;Miss Target C;;Miss Target C;;;none;;",
    "Value", 0, 1, 0 },

  { 1419,
    "Parameter Table Defn/events/E_NEW_TRIAL;New Trial Start;;New Trial starts;;;none;;",
    "Value", 0, 1, 0 },

  { 1420,
    "Parameter Table Defn/events/E_NO_EVENT;n|a;;This event_code does not save an event in the data file, it just clears the event;;;none;;",
    "Value", 0, 1, 0 },

  { 1421,
    "Parameter Table Defn/events/E_SHOW_INSTRUCT;Instruction state;;Showing instructions;;;none;;",
    "Value", 0, 1, 0 },

  { 1422,
    "Parameter Table Defn/events/E_SHOW_SCORE;Show Score;;Showing score;;;none;;",
    "Value", 0, 1, 0 },

  { 1423,
    "Parameter Table Defn/events/E_STAY_START;At Start;;Subject reached start target;;;none;;",
    "Value", 0, 1, 0 },

  { 1424,
    "Parameter Table Defn/events/E_TARGETS_ON;Targets On;;Potential Reach targets on;;;none;;",
    "Value", 0, 1, 0 },

  { 1425,
    "Parameter Table Defn/events/E_TOO_SLOW;Too Slow;;Movement is too slow;;;error;;",
    "Value", 0, 1, 0 },

  { 1426,
    "Parameter Table Defn/target_table/BOX_HEIGHT;Height of Box;float;Height of Box;;;none;;",
    "Value", 0, 1, 0 },

  { 1427,
    "Parameter Table Defn/target_table/HIT_COLOR;Reached color;colour;Color when the target is touched;;;none;;",
    "Value", 0, 1, 0 },

  { 1428,
    "Parameter Table Defn/target_table/INIT_COLOR;Initial color;colour;Initial target color;;;none;;",
    "Value", 0, 1, 0 },

  { 1429,
    "Parameter Table Defn/target_table/LABEL;Label Text;label;Initial text for the label;;;none;;",
    "Value", 0, 1, 0 },

  { 1430,
    "Parameter Table Defn/target_table/LABELONLY_X;LabelOnly X;float;X position (cm) of the target relative to local (0,0) when only the label appears;;;none;;",
    "Value", 0, 1, 0 },

  { 1431,
    "Parameter Table Defn/target_table/LABELONLY_Y;LabelOnly  Y;float;Y position (cm) of the target relative to local (0,0) when only the label appears;;;none;;",
    "Value", 0, 1, 0 },

  { 1432,
    "Parameter Table Defn/target_table/LABEL_HEIGHT;Label Height;float;Label Height (cm);;;none;;",
    "Value", 0, 1, 0 },

  { 1433,
    "Parameter Table Defn/target_table/LOGICAL_RADIUS;Logical radius;float;Radius of the target used for 'hand-in-target' logic (cm);;;none;;",
    "Value", 0, 1, 0 },

  { 1434,
    "Parameter Table Defn/target_table/ROTATION;Rotation of a target;float;Rotation of target;;;none;;",
    "Value", 0, 1, 0 },

  { 1435,
    "Parameter Table Defn/target_table/STROKE_WIDTH;Stroke Width;float;Stroke width;;;none;;",
    "Value", 0, 1, 0 },

  { 1436,
    "Parameter Table Defn/target_table/TEXT_COLOR;Text Color;colour;Text Color;;;none;;",
    "Value", 0, 1, 0 },

  { 1437,
    "Parameter Table Defn/target_table/VISUAL_RADIUS;Visual radius;float;Visual radius of the target (cm) or size of the sides of the square targets;;;none;;",
    "Value", 0, 1, 0 },

  { 1438,
    "Parameter Table Defn/target_table/col_x;X;float;X Position (cm) of the target relative to  local (0,0);;;none;;",
    "Value", 0, 1, 0 },

  { 1439,
    "Parameter Table Defn/target_table/col_y;Y;float;Y Position (cm) of the target relative to  local (0,0);;;none;;",
    "Value", 0, 1, 0 },

  { 1440, "Parameter Table Defn/task_definition/INSTRUCTIONS=",
    "Value", 0, 1, 0 },

  { 1441, "Parameter Table Defn/task_definition/LOAD_FOR=EITHER",
    "Value", 0, 1, 0 },

  { 1442,
    "Parameter Table Defn/task_wide/K_DELAY_FIXED;Delay_Min;integer;Minimum hold delay time at start target (fixed);;;none;;",
    "Value", 0, 1, 0 },

  { 1443,
    "Parameter Table Defn/task_wide/K_DELAY_RAND;Delay_Rand;integer;Maximum additional delay time at start target (random);;;none;;",
    "Value", 0, 1, 0 },

  { 1444,
    "Parameter Table Defn/task_wide/K_PRE_REWARD_DELAY;Delay_PreRewardCue;integer;Time to cue the reward information prior to the trial onset;;;none;;",
    "Value", 0, 1, 0 },

  { 1445,
    "Parameter Table Defn/task_wide/K_REWARD_VAL;Reward_Value;integer;One unit of reward;;;none;;",
    "Value", 0, 1, 0 },

  { 1446,
    "Parameter Table Defn/task_wide/K_SCORETEXT_ROW;Feedback_Text_TgtTable_Row;integer;Target number to be used to set the feedback text;;;none;;",
    "Value", 0, 1, 0 },

  { 1447,
    "Parameter Table Defn/task_wide/K_THRESH_VELMAX;Vel_Min_Thresh;float;Minimum velocity that must be exceeded for trial to be considered successful;;;none;;",
    "Value", 0, 1, 0 },

  { 1448,
    "Parameter Table Defn/task_wide/K_TRIGGER_POS;Trigger_Pos;float;Position Threshold for triggering target reveal;;;none;;",
    "Value", 0, 1, 0 },

  { 1449,
    "Parameter Table Defn/task_wide/K_TRIGGER_VEL;Trigger_Vel;float;Velocity Threshold for triggering target reveal;;;none;;",
    "Value", 0, 1, 0 },

  { 1450, "Process_Video_CMD/Add_requested_Delay/500 hz",
    "Value", 0, 1, 0 },

  { 1451, "Process_Video_CMD/PVC_core/Rate Transition1",
    "X0", 0, 1, 0 },

  { 1452,
    "DataLogging/Create Task State Subsystem/Counter Free-Running/Wrap To Zero",
    "Threshold", 4, 1, 0 },

  { 1453, "DataLogging/Create Task State Subsystem/Counter Free-Running/Output",
    "InitialCondition", 4, 1, 0 },

  { 1454,
    "DataLogging/Network Transfer Subsystem/Data Packing Subsystem/Constant",
    "Value", 6, 93, 0 },

  { 1455,
    "DataLogging/Network Transfer Subsystem/Data Packing Subsystem/Constant1",
    "Value", 0, 1, 0 },

  { 1456,
    "DataLogging/Network Transfer Subsystem/Data Packing Subsystem/Max Frames Per Packet",
    "Value", 0, 1, 0 },

  { 1457, "DataLogging/Network Transfer Subsystem/Data Packing Subsystem/t-1",
    "X0", 6, 1, 0 },

  { 1458, "DataLogging/Network Transfer Subsystem/Data Packing Subsystem/t-2",
    "X0", 6, 1, 0 },

  { 1459, "DataLogging/Network Transfer Subsystem/UDP Receiver/Memory2",
    "X0", 0, 1, 0 },

  { 1460, "DataLogging/Network Transfer Subsystem/UDP Receiver/Rate Transition2",
    "X0", 0, 1, 0 },

  { 1461, "DataLogging/Network Transfer Subsystem/UDP Receiver/UDP Receive",
    "P1", 0, 94, 0 },

  { 1462, "DataLogging/Network Transfer Subsystem/UDP Receiver/UDP Receive",
    "P2", 0, 1, 0 },

  { 1463, "DataLogging/Network Transfer Subsystem/UDP Receiver/UDP Receive",
    "P3", 0, 1, 0 },

  { 1464, "DataLogging/Network Transfer Subsystem/UDP Receiver/UDP Receive",
    "P4", 0, 1, 0 },

  { 1465, "DataLogging/Network Transfer Subsystem/UDP Receiver/UDP Receive",
    "P5", 0, 1, 0 },

  { 1466,
    "DataLogging/Network Transfer Subsystem/UDP Receiver/UDP Receive Port Reset",
    "P1", 0, 86, 0 },

  { 1467,
    "DataLogging/Network Transfer Subsystem/UDP Receiver/UDP Receive Port Reset",
    "P2", 0, 1, 0 },

  { 1468,
    "DataLogging/Network Transfer Subsystem/UDP Receiver/UDP Receive Port Reset",
    "P3", 0, 1, 0 },

  { 1469,
    "DataLogging/Network Transfer Subsystem/UDP Receiver/UDP Receive Port Reset",
    "P4", 0, 1, 0 },

  { 1470,
    "DataLogging/Network Transfer Subsystem/UDP Receiver/UDP Receive Port Reset",
    "P5", 0, 1, 0 },

  { 1471,
    "DataLogging/Network Transfer Subsystem/UDP Send Subsystem/total_packets_sent",
    "InitialOutput", 4, 1, 0 },

  { 1472, "DataLogging/Network Transfer Subsystem/UDP Send Subsystem/Send",
    "P1", 0, 86, 0 },

  { 1473, "DataLogging/Network Transfer Subsystem/UDP Send Subsystem/Send",
    "P2", 0, 1, 0 },

  { 1474, "DataLogging/Network Transfer Subsystem/UDP Send Subsystem/Send",
    "P3", 0, 1, 0 },

  { 1475, "DataLogging/Network Transfer Subsystem/UDP Send Subsystem/Send",
    "P4", 0, 1, 0 },

  { 1476, "DataLogging/Network Transfer Subsystem/UDP Send Subsystem/Send",
    "P5", 0, 1, 0 },

  { 1477, "DataLogging/Poll Force Plates/plate1/Receive",
    "P1", 0, 95, 0 },

  { 1478, "DataLogging/Poll Force Plates/plate1/Receive",
    "P2", 0, 1, 0 },

  { 1479, "DataLogging/Poll Force Plates/plate1/Receive",
    "P3", 0, 1, 0 },

  { 1480, "DataLogging/Poll Force Plates/plate1/Receive",
    "P4", 0, 1, 0 },

  { 1481, "DataLogging/Poll Force Plates/plate1/Receive",
    "P5", 0, 1, 0 },

  { 1482, "DataLogging/Poll Force Plates/plate2/Receive1",
    "P1", 0, 95, 0 },

  { 1483, "DataLogging/Poll Force Plates/plate2/Receive1",
    "P2", 0, 1, 0 },

  { 1484, "DataLogging/Poll Force Plates/plate2/Receive1",
    "P3", 0, 1, 0 },

  { 1485, "DataLogging/Poll Force Plates/plate2/Receive1",
    "P4", 0, 1, 0 },

  { 1486, "DataLogging/Poll Force Plates/plate2/Receive1",
    "P5", 0, 1, 0 },

  { 1487, "DataLogging/Poll Force Plates/send poll 1/Send",
    "P1", 0, 95, 0 },

  { 1488, "DataLogging/Poll Force Plates/send poll 1/Send",
    "P2", 0, 1, 0 },

  { 1489, "DataLogging/Poll Force Plates/send poll 1/Send",
    "P3", 0, 1, 0 },

  { 1490, "DataLogging/Poll Force Plates/send poll 1/Send",
    "P4", 0, 1, 0 },

  { 1491, "DataLogging/Poll Force Plates/send poll 1/Send",
    "P5", 0, 1, 0 },

  { 1492, "DataLogging/Poll Force Plates/send poll 2/Send1",
    "P1", 0, 95, 0 },

  { 1493, "DataLogging/Poll Force Plates/send poll 2/Send1",
    "P2", 0, 1, 0 },

  { 1494, "DataLogging/Poll Force Plates/send poll 2/Send1",
    "P3", 0, 1, 0 },

  { 1495, "DataLogging/Poll Force Plates/send poll 2/Send1",
    "P4", 0, 1, 0 },

  { 1496, "DataLogging/Poll Force Plates/send poll 2/Send1",
    "P5", 0, 1, 0 },

  { 1497, "DataLogging/Poll KINARM/EtherCAT Subsystem/Compare",
    "const", 4, 1, 0 },

  { 1498, "DataLogging/Poll KINARM/EtherCAT Subsystem/PCI Bus Slot",
    "Value", 3, 75, 0 },

  { 1499, "DataLogging/Poll KINARM/EtherCAT Subsystem/activation",
    "Value", 3, 75, 0 },

  { 1500, "DataLogging/Poll KINARM/EtherCAT Subsystem/ep part nums",
    "Value", 0, 77, 0 },

  { 1501, "DataLogging/Poll KINARM/EtherCAT Subsystem/exo part nums",
    "Value", 0, 77, 0 },

  { 1502, "DataLogging/Poll KINARM/EtherCAT Subsystem/force primary only",
    "Value", 0, 1, 0 },

  { 1503, "DataLogging/Poll KINARM/EtherCAT Subsystem/max errors to fault",
    "Value", 0, 1, 0 },

  { 1504, "DataLogging/Poll KINARM/EtherCAT Subsystem/nhp part nums",
    "Value", 0, 77, 0 },

  { 1505, "DataLogging/Poll KINARM/EtherCAT Subsystem/Switch",
    "Threshold", 3, 1, 0 },

  { 1506, "DataLogging/Poll KINARM/bkin_internal_testing/ispmac1",
    "const", 0, 1, 0 },

  { 1507, "DataLogging/Poll KINARM/constants/update constants",
    "Value", 0, 1, 0 },

  { 1508, "DataLogging/Poll KINARM/createKINData/Dominant Arm",
    "Value", 0, 1, 0 },

  { 1509, "DataLogging/Poll KINARM/createKINData/step time",
    "Value", 0, 1, 0 },

  { 1510,
    "DataLogging/Create Task State Subsystem/Counter Free-Running/Increment Real World/FixPt Constant",
    "Value", 4, 1, 0 },

  { 1511,
    "DataLogging/Create Task State Subsystem/Counter Free-Running/Wrap To Zero/Constant",
    "Value", 4, 1, 0 },

  { 1512,
    "DataLogging/Network Transfer Subsystem/Data Packing Subsystem/Counter/Constant",
    "Value", 0, 1, 0 },

  { 1513,
    "DataLogging/Network Transfer Subsystem/Data Packing Subsystem/Counter/Unit Delay",
    "InitialCondition", 0, 1, 0 },

  { 1514,
    "DataLogging/Network Transfer Subsystem/UDP Send Subsystem/Counter Free-Running/Wrap To Zero",
    "Threshold", 4, 1, 0 },

  { 1515,
    "DataLogging/Network Transfer Subsystem/UDP Send Subsystem/Counter Free-Running/Output",
    "InitialCondition", 4, 1, 0 },

  { 1516, "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/Torque Mode",
    "Value", 8, 1, 0 },

  { 1517, "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/enableCalibration",
    "Value", 0, 1, 0 },

  { 1518, "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/enableMotors",
    "Value", 0, 1, 0 },

  { 1519, "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/readTrigger",
    "Value", 3, 1, 0 },

  { 1520, "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/Memory2",
    "X0", 0, 1, 0 },

  { 1521, "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/Memory3",
    "X0", 0, 1, 0 },

  { 1522,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/BKIN EtherCAT PDO Transmit ",
    "P1", 0, 96, 0 },

  { 1523,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/BKIN EtherCAT PDO Transmit ",
    "P2", 0, 1, 0 },

  { 1524,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/BKIN EtherCAT PDO Transmit ",
    "P3", 0, 1, 0 },

  { 1525,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/BKIN EtherCAT PDO Transmit ",
    "P4", 0, 1, 0 },

  { 1526,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/BKIN EtherCAT PDO Transmit ",
    "P5", 0, 1, 0 },

  { 1527,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/BKIN EtherCAT PDO Transmit ",
    "P6", 0, 1, 0 },

  { 1528,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/BKIN EtherCAT PDO Transmit ",
    "P7", 0, 1, 0 },

  { 1529,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/BKIN EtherCAT PDO Transmit 1",
    "P1", 0, 96, 0 },

  { 1530,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/BKIN EtherCAT PDO Transmit 1",
    "P2", 0, 1, 0 },

  { 1531,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/BKIN EtherCAT PDO Transmit 1",
    "P3", 0, 1, 0 },

  { 1532,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/BKIN EtherCAT PDO Transmit 1",
    "P4", 0, 1, 0 },

  { 1533,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/BKIN EtherCAT PDO Transmit 1",
    "P5", 0, 1, 0 },

  { 1534,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/BKIN EtherCAT PDO Transmit 1",
    "P6", 0, 1, 0 },

  { 1535,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/BKIN EtherCAT PDO Transmit 1",
    "P7", 0, 1, 0 },

  { 1536, "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/Torque Mode",
    "Value", 8, 1, 0 },

  { 1537, "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/enableCalibration",
    "Value", 0, 1, 0 },

  { 1538, "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/enableMotors",
    "Value", 0, 1, 0 },

  { 1539, "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/readTrigger",
    "Value", 3, 1, 0 },

  { 1540, "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/Memory2",
    "X0", 0, 1, 0 },

  { 1541, "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/Memory3",
    "X0", 0, 1, 0 },

  { 1542,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/BKIN EtherCAT PDO Transmit ",
    "P1", 0, 96, 0 },

  { 1543,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/BKIN EtherCAT PDO Transmit ",
    "P2", 0, 1, 0 },

  { 1544,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/BKIN EtherCAT PDO Transmit ",
    "P3", 0, 1, 0 },

  { 1545,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/BKIN EtherCAT PDO Transmit ",
    "P4", 0, 1, 0 },

  { 1546,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/BKIN EtherCAT PDO Transmit ",
    "P5", 0, 1, 0 },

  { 1547,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/BKIN EtherCAT PDO Transmit ",
    "P6", 0, 1, 0 },

  { 1548,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/BKIN EtherCAT PDO Transmit ",
    "P7", 0, 1, 0 },

  { 1549,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/BKIN EtherCAT PDO Transmit 1",
    "P1", 0, 96, 0 },

  { 1550,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/BKIN EtherCAT PDO Transmit 1",
    "P2", 0, 1, 0 },

  { 1551,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/BKIN EtherCAT PDO Transmit 1",
    "P3", 0, 1, 0 },

  { 1552,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/BKIN EtherCAT PDO Transmit 1",
    "P4", 0, 1, 0 },

  { 1553,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/BKIN EtherCAT PDO Transmit 1",
    "P5", 0, 1, 0 },

  { 1554,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/BKIN EtherCAT PDO Transmit 1",
    "P6", 0, 1, 0 },

  { 1555,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/BKIN EtherCAT PDO Transmit 1",
    "P7", 0, 1, 0 },

  { 1556,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Counter Free-Running/Wrap To Zero",
    "Threshold", 4, 1, 0 },

  { 1557,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Counter Free-Running/Output",
    "InitialCondition", 4, 1, 0 },

  { 1558,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Digital output/BKIN EtherCAT PDO Transmit ",
    "P1", 0, 97, 0 },

  { 1559,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Digital output/BKIN EtherCAT PDO Transmit ",
    "P2", 0, 1, 0 },

  { 1560,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Digital output/BKIN EtherCAT PDO Transmit ",
    "P3", 0, 1, 0 },

  { 1561,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Digital output/BKIN EtherCAT PDO Transmit ",
    "P4", 0, 1, 0 },

  { 1562,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Digital output/BKIN EtherCAT PDO Transmit ",
    "P5", 0, 1, 0 },

  { 1563,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Digital output/BKIN EtherCAT PDO Transmit ",
    "P6", 0, 1, 0 },

  { 1564,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Digital output/BKIN EtherCAT PDO Transmit ",
    "P7", 0, 1, 0 },

  { 1565,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Digital output/BKIN EtherCAT PDO Transmit 1",
    "P1", 0, 97, 0 },

  { 1566,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Digital output/BKIN EtherCAT PDO Transmit 1",
    "P2", 0, 1, 0 },

  { 1567,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Digital output/BKIN EtherCAT PDO Transmit 1",
    "P3", 0, 1, 0 },

  { 1568,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Digital output/BKIN EtherCAT PDO Transmit 1",
    "P4", 0, 1, 0 },

  { 1569,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Digital output/BKIN EtherCAT PDO Transmit 1",
    "P5", 0, 1, 0 },

  { 1570,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Digital output/BKIN EtherCAT PDO Transmit 1",
    "P6", 0, 1, 0 },

  { 1571,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Digital output/BKIN EtherCAT PDO Transmit 1",
    "P7", 0, 1, 0 },

  { 1572,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Digital output/BKIN EtherCAT PDO Transmit 2",
    "P1", 0, 97, 0 },

  { 1573,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Digital output/BKIN EtherCAT PDO Transmit 2",
    "P2", 0, 1, 0 },

  { 1574,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Digital output/BKIN EtherCAT PDO Transmit 2",
    "P3", 0, 1, 0 },

  { 1575,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Digital output/BKIN EtherCAT PDO Transmit 2",
    "P4", 0, 1, 0 },

  { 1576,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Digital output/BKIN EtherCAT PDO Transmit 2",
    "P5", 0, 1, 0 },

  { 1577,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Digital output/BKIN EtherCAT PDO Transmit 2",
    "P6", 0, 1, 0 },

  { 1578,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Digital output/BKIN EtherCAT PDO Transmit 2",
    "P7", 0, 1, 0 },

  { 1579,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Digital output/BKIN EtherCAT PDO Transmit 3",
    "P1", 0, 97, 0 },

  { 1580,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Digital output/BKIN EtherCAT PDO Transmit 3",
    "P2", 0, 1, 0 },

  { 1581,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Digital output/BKIN EtherCAT PDO Transmit 3",
    "P3", 0, 1, 0 },

  { 1582,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Digital output/BKIN EtherCAT PDO Transmit 3",
    "P4", 0, 1, 0 },

  { 1583,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Digital output/BKIN EtherCAT PDO Transmit 3",
    "P5", 0, 1, 0 },

  { 1584,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Digital output/BKIN EtherCAT PDO Transmit 3",
    "P6", 0, 1, 0 },

  { 1585,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Digital output/BKIN EtherCAT PDO Transmit 3",
    "P7", 0, 1, 0 },

  { 1586, "DataLogging/Poll KINARM/EtherCAT Subsystem/update/Constant",
    "Value", 0, 1, 0 },

  { 1587, "DataLogging/Poll KINARM/EtherCAT Subsystem/update/Constant1",
    "Value", 4, 1, 0 },

  { 1588,
    "DataLogging/Poll KINARM/Force Sensor Control/Force Sensor 1 Subsystem/Detect Change",
    "vinit", 0, 1, 0 },

  { 1589,
    "DataLogging/Poll KINARM/Force Sensor Control/Force Sensor 1 Subsystem/Constant",
    "Value", 0, 78, 0 },

  { 1590,
    "DataLogging/Poll KINARM/Force Sensor Control/Force Sensor 1 Subsystem/Receive from Robot 1 Force Sensor",
    "P1", 0, 98, 0 },

  { 1591,
    "DataLogging/Poll KINARM/Force Sensor Control/Force Sensor 1 Subsystem/Receive from Robot 1 Force Sensor",
    "P2", 0, 1, 0 },

  { 1592,
    "DataLogging/Poll KINARM/Force Sensor Control/Force Sensor 1 Subsystem/Receive from Robot 1 Force Sensor",
    "P3", 0, 1, 0 },

  { 1593,
    "DataLogging/Poll KINARM/Force Sensor Control/Force Sensor 1 Subsystem/Receive from Robot 1 Force Sensor",
    "P4", 0, 1, 0 },

  { 1594,
    "DataLogging/Poll KINARM/Force Sensor Control/Force Sensor 1 Subsystem/Receive from Robot 1 Force Sensor",
    "P5", 0, 1, 0 },

  { 1595,
    "DataLogging/Poll KINARM/Force Sensor Control/Force Sensor 1 Subsystem/Switch",
    "Threshold", 0, 1, 0 },

  { 1596,
    "DataLogging/Poll KINARM/Force Sensor Control/Force Sensor 2 Subsystem/Detect Change",
    "vinit", 0, 1, 0 },

  { 1597,
    "DataLogging/Poll KINARM/Force Sensor Control/Force Sensor 2 Subsystem/Constant1",
    "Value", 0, 78, 0 },

  { 1598,
    "DataLogging/Poll KINARM/Force Sensor Control/Force Sensor 2 Subsystem/Receive from Robot 2 Force Sensor",
    "P1", 0, 98, 0 },

  { 1599,
    "DataLogging/Poll KINARM/Force Sensor Control/Force Sensor 2 Subsystem/Receive from Robot 2 Force Sensor",
    "P2", 0, 1, 0 },

  { 1600,
    "DataLogging/Poll KINARM/Force Sensor Control/Force Sensor 2 Subsystem/Receive from Robot 2 Force Sensor",
    "P3", 0, 1, 0 },

  { 1601,
    "DataLogging/Poll KINARM/Force Sensor Control/Force Sensor 2 Subsystem/Receive from Robot 2 Force Sensor",
    "P4", 0, 1, 0 },

  { 1602,
    "DataLogging/Poll KINARM/Force Sensor Control/Force Sensor 2 Subsystem/Receive from Robot 2 Force Sensor",
    "P5", 0, 1, 0 },

  { 1603,
    "DataLogging/Poll KINARM/Force Sensor Control/Force Sensor 2 Subsystem/Switch1",
    "Threshold", 0, 1, 0 },

  { 1604, "DataLogging/Poll KINARM/PMAC Subsystem/read_pmac/robot_count",
    "Value", 0, 1, 0 },

  { 1605, "DataLogging/Poll KINARM/PMAC Subsystem/read_pmac/step duration",
    "Value", 0, 1, 0 },

  { 1606,
    "DataLogging/Poll KINARM/bkin_internal_testing/Data receive/servo counter",
    "InitialOutput", 4, 1, 0 },

  { 1607,
    "DataLogging/Poll KINARM/bkin_internal_testing/Data receive/EP calibration btn",
    "InitialOutput", 4, 1, 0 },

  { 1608,
    "DataLogging/Poll KINARM/bkin_internal_testing/Data receive/Status bits",
    "InitialOutput", 4, 65, 0 },

  { 1609,
    "DataLogging/Poll KINARM/bkin_internal_testing/Data receive/MATLAB Function",
    "BKIN_STEP_TIME", 0, 1, 0 },

  { 1610, "DataLogging/Poll KINARM/bkin_internal_testing/Data receive/Constant",
    "Value", 4, 1, 0 },

  { 1611, "DataLogging/Poll KINARM/bkin_internal_testing/Data receive/Constant1",
    "Value", 4, 65, 0 },

  { 1612, "DataLogging/Poll KINARM/bkin_internal_testing/Data receive/Receive",
    "P1", 0, 86, 0 },

  { 1613, "DataLogging/Poll KINARM/bkin_internal_testing/Data receive/Receive",
    "P2", 0, 1, 0 },

  { 1614, "DataLogging/Poll KINARM/bkin_internal_testing/Data receive/Receive",
    "P3", 0, 1, 0 },

  { 1615, "DataLogging/Poll KINARM/bkin_internal_testing/Data receive/Receive",
    "P4", 0, 1, 0 },

  { 1616, "DataLogging/Poll KINARM/bkin_internal_testing/Data receive/Receive",
    "P5", 0, 1, 0 },

  { 1617, "DataLogging/Poll KINARM/bkin_internal_testing/Data write/Constant",
    "Value", 0, 3, 0 },

  { 1618, "DataLogging/Poll KINARM/constants/arm1/Arm Elbow Angle Offset",
    "Value", 0, 1, 0 },

  { 1619, "DataLogging/Poll KINARM/constants/arm1/Arm Encoder Orientation 1",
    "Value", 0, 1, 0 },

  { 1620, "DataLogging/Poll KINARM/constants/arm1/Arm Encoder Orientation 2",
    "Value", 0, 1, 0 },

  { 1621, "DataLogging/Poll KINARM/constants/arm1/Arm Force Sensor Angle Offset",
    "Value", 0, 1, 0 },

  { 1622, "DataLogging/Poll KINARM/constants/arm1/Arm L1",
    "Value", 0, 1, 0 },

  { 1623, "DataLogging/Poll KINARM/constants/arm1/Arm L2",
    "Value", 0, 1, 0 },

  { 1624, "DataLogging/Poll KINARM/constants/arm1/Arm L2 L5 Angle",
    "Value", 0, 1, 0 },

  { 1625, "DataLogging/Poll KINARM/constants/arm1/Arm L3 Error",
    "Value", 0, 1, 0 },

  { 1626, "DataLogging/Poll KINARM/constants/arm1/Arm L5",
    "Value", 0, 1, 0 },

  { 1627, "DataLogging/Poll KINARM/constants/arm1/Arm Motor1 Gear Ratio",
    "Value", 0, 1, 0 },

  { 1628, "DataLogging/Poll KINARM/constants/arm1/Arm Motor1 Orientation",
    "Value", 0, 1, 0 },

  { 1629, "DataLogging/Poll KINARM/constants/arm1/Arm Motor2 Gear Ratio",
    "Value", 0, 1, 0 },

  { 1630, "DataLogging/Poll KINARM/constants/arm1/Arm Motor2 Orientation",
    "Value", 0, 1, 0 },

  { 1631, "DataLogging/Poll KINARM/constants/arm1/Arm Orientation",
    "Value", 0, 1, 0 },

  { 1632, "DataLogging/Poll KINARM/constants/arm1/Arm Pointer Offset",
    "Value", 0, 1, 0 },

  { 1633, "DataLogging/Poll KINARM/constants/arm1/Arm Secondary Encoders",
    "Value", 0, 1, 0 },

  { 1634, "DataLogging/Poll KINARM/constants/arm1/Arm Shoulder Angle Offset",
    "Value", 0, 1, 0 },

  { 1635, "DataLogging/Poll KINARM/constants/arm1/Arm Shoulder X",
    "Value", 0, 1, 0 },

  { 1636, "DataLogging/Poll KINARM/constants/arm1/Arm Shoulder Y",
    "Value", 0, 1, 0 },

  { 1637, "DataLogging/Poll KINARM/constants/arm1/Arm Torque Constant",
    "Value", 0, 1, 0 },

  { 1638, "DataLogging/Poll KINARM/constants/arm1/Arm primary encoder counts",
    "Value", 0, 1, 0 },

  { 1639, "DataLogging/Poll KINARM/constants/arm1/Arm robot type",
    "Value", 0, 1, 0 },

  { 1640, "DataLogging/Poll KINARM/constants/arm1/Arm robot version",
    "Value", 0, 1, 0 },

  { 1641, "DataLogging/Poll KINARM/constants/arm1/Arm secondary encoder counts",
    "Value", 0, 1, 0 },

  { 1642, "DataLogging/Poll KINARM/constants/arm2/Arm Elbow Angle Offset",
    "Value", 0, 1, 0 },

  { 1643, "DataLogging/Poll KINARM/constants/arm2/Arm Encoder Orientation 1",
    "Value", 0, 1, 0 },

  { 1644, "DataLogging/Poll KINARM/constants/arm2/Arm Encoder Orientation 2",
    "Value", 0, 1, 0 },

  { 1645, "DataLogging/Poll KINARM/constants/arm2/Arm Force Sensor Angle Offset",
    "Value", 0, 1, 0 },

  { 1646, "DataLogging/Poll KINARM/constants/arm2/Arm L1",
    "Value", 0, 1, 0 },

  { 1647, "DataLogging/Poll KINARM/constants/arm2/Arm L2",
    "Value", 0, 1, 0 },

  { 1648, "DataLogging/Poll KINARM/constants/arm2/Arm L2 L5 Angle",
    "Value", 0, 1, 0 },

  { 1649, "DataLogging/Poll KINARM/constants/arm2/Arm L3 Error",
    "Value", 0, 1, 0 },

  { 1650, "DataLogging/Poll KINARM/constants/arm2/Arm L5",
    "Value", 0, 1, 0 },

  { 1651, "DataLogging/Poll KINARM/constants/arm2/Arm Motor1 Gear Ratio",
    "Value", 0, 1, 0 },

  { 1652, "DataLogging/Poll KINARM/constants/arm2/Arm Motor1 Orientation",
    "Value", 0, 1, 0 },

  { 1653, "DataLogging/Poll KINARM/constants/arm2/Arm Motor2 Gear Ratio",
    "Value", 0, 1, 0 },

  { 1654, "DataLogging/Poll KINARM/constants/arm2/Arm Motor2 Orientation",
    "Value", 0, 1, 0 },

  { 1655, "DataLogging/Poll KINARM/constants/arm2/Arm Orientation",
    "Value", 0, 1, 0 },

  { 1656, "DataLogging/Poll KINARM/constants/arm2/Arm Pointer Offset",
    "Value", 0, 1, 0 },

  { 1657, "DataLogging/Poll KINARM/constants/arm2/Arm Secondary Encoders",
    "Value", 0, 1, 0 },

  { 1658, "DataLogging/Poll KINARM/constants/arm2/Arm Shoulder Angle Offset",
    "Value", 0, 1, 0 },

  { 1659, "DataLogging/Poll KINARM/constants/arm2/Arm Shoulder X",
    "Value", 0, 1, 0 },

  { 1660, "DataLogging/Poll KINARM/constants/arm2/Arm Shoulder Y",
    "Value", 0, 1, 0 },

  { 1661, "DataLogging/Poll KINARM/constants/arm2/Arm Torque Constant",
    "Value", 0, 1, 0 },

  { 1662, "DataLogging/Poll KINARM/constants/arm2/Arm primary encoder counts",
    "Value", 0, 1, 0 },

  { 1663, "DataLogging/Poll KINARM/constants/arm2/Arm robot type",
    "Value", 0, 1, 0 },

  { 1664, "DataLogging/Poll KINARM/constants/arm2/Arm robot version",
    "Value", 0, 1, 0 },

  { 1665, "DataLogging/Poll KINARM/constants/arm2/Arm secondary encoder counts",
    "Value", 0, 1, 0 },

  { 1666,
    "DataLogging/Poll KINARM/constants/update constants subsystem/Arm Force Sensors",
    "Value", 0, 75, 0 },

  { 1667,
    "DataLogging/Poll KINARM/createKINData/Counter Free-Running/Wrap To Zero",
    "Threshold", 4, 1, 0 },

  { 1668, "DataLogging/Poll KINARM/createKINData/Counter Free-Running/Output",
    "InitialCondition", 4, 1, 0 },

  { 1669,
    "DataLogging/Poll KINARM/createKINData/hand feedback/Gaze Feedback Status",
    "Value", 0, 1, 0 },

  { 1670,
    "DataLogging/Poll KINARM/createKINData/hand feedback/Hand Feedback Colour",
    "Value", 0, 1, 0 },

  { 1671,
    "DataLogging/Poll KINARM/createKINData/hand feedback/Hand Feedback Feed Forward",
    "Value", 0, 1, 0 },

  { 1672,
    "DataLogging/Poll KINARM/createKINData/hand feedback/Hand Feedback Radius",
    "Value", 0, 1, 0 },

  { 1673,
    "DataLogging/Poll KINARM/createKINData/hand feedback/Hand Feedback Source",
    "Value", 0, 1, 0 },

  { 1674,
    "DataLogging/Poll KINARM/createKINData/hand feedback/Hand Feedback Status",
    "Value", 0, 1, 0 },

  { 1675,
    "DataLogging/apply loads/EtherCAT Apply Loads/A1 Apply torques/BKIN EtherCAT PDO Transmit 1",
    "P1", 0, 99, 0 },

  { 1676,
    "DataLogging/apply loads/EtherCAT Apply Loads/A1 Apply torques/BKIN EtherCAT PDO Transmit 1",
    "P2", 0, 1, 0 },

  { 1677,
    "DataLogging/apply loads/EtherCAT Apply Loads/A1 Apply torques/BKIN EtherCAT PDO Transmit 1",
    "P3", 0, 1, 0 },

  { 1678,
    "DataLogging/apply loads/EtherCAT Apply Loads/A1 Apply torques/BKIN EtherCAT PDO Transmit 1",
    "P4", 0, 1, 0 },

  { 1679,
    "DataLogging/apply loads/EtherCAT Apply Loads/A1 Apply torques/BKIN EtherCAT PDO Transmit 1",
    "P5", 0, 1, 0 },

  { 1680,
    "DataLogging/apply loads/EtherCAT Apply Loads/A1 Apply torques/BKIN EtherCAT PDO Transmit 1",
    "P6", 0, 1, 0 },

  { 1681,
    "DataLogging/apply loads/EtherCAT Apply Loads/A1 Apply torques/BKIN EtherCAT PDO Transmit 1",
    "P7", 0, 1, 0 },

  { 1682,
    "DataLogging/apply loads/EtherCAT Apply Loads/A1 Apply torques/BKIN EtherCAT PDO Transmit 2",
    "P1", 0, 99, 0 },

  { 1683,
    "DataLogging/apply loads/EtherCAT Apply Loads/A1 Apply torques/BKIN EtherCAT PDO Transmit 2",
    "P2", 0, 1, 0 },

  { 1684,
    "DataLogging/apply loads/EtherCAT Apply Loads/A1 Apply torques/BKIN EtherCAT PDO Transmit 2",
    "P3", 0, 1, 0 },

  { 1685,
    "DataLogging/apply loads/EtherCAT Apply Loads/A1 Apply torques/BKIN EtherCAT PDO Transmit 2",
    "P4", 0, 1, 0 },

  { 1686,
    "DataLogging/apply loads/EtherCAT Apply Loads/A1 Apply torques/BKIN EtherCAT PDO Transmit 2",
    "P5", 0, 1, 0 },

  { 1687,
    "DataLogging/apply loads/EtherCAT Apply Loads/A1 Apply torques/BKIN EtherCAT PDO Transmit 2",
    "P6", 0, 1, 0 },

  { 1688,
    "DataLogging/apply loads/EtherCAT Apply Loads/A1 Apply torques/BKIN EtherCAT PDO Transmit 2",
    "P7", 0, 1, 0 },

  { 1689,
    "DataLogging/apply loads/EtherCAT Apply Loads/A2 Apply torques/BKIN EtherCAT PDO Transmit 1",
    "P1", 0, 99, 0 },

  { 1690,
    "DataLogging/apply loads/EtherCAT Apply Loads/A2 Apply torques/BKIN EtherCAT PDO Transmit 1",
    "P2", 0, 1, 0 },

  { 1691,
    "DataLogging/apply loads/EtherCAT Apply Loads/A2 Apply torques/BKIN EtherCAT PDO Transmit 1",
    "P3", 0, 1, 0 },

  { 1692,
    "DataLogging/apply loads/EtherCAT Apply Loads/A2 Apply torques/BKIN EtherCAT PDO Transmit 1",
    "P4", 0, 1, 0 },

  { 1693,
    "DataLogging/apply loads/EtherCAT Apply Loads/A2 Apply torques/BKIN EtherCAT PDO Transmit 1",
    "P5", 0, 1, 0 },

  { 1694,
    "DataLogging/apply loads/EtherCAT Apply Loads/A2 Apply torques/BKIN EtherCAT PDO Transmit 1",
    "P6", 0, 1, 0 },

  { 1695,
    "DataLogging/apply loads/EtherCAT Apply Loads/A2 Apply torques/BKIN EtherCAT PDO Transmit 1",
    "P7", 0, 1, 0 },

  { 1696,
    "DataLogging/apply loads/EtherCAT Apply Loads/A2 Apply torques/BKIN EtherCAT PDO Transmit 2",
    "P1", 0, 99, 0 },

  { 1697,
    "DataLogging/apply loads/EtherCAT Apply Loads/A2 Apply torques/BKIN EtherCAT PDO Transmit 2",
    "P2", 0, 1, 0 },

  { 1698,
    "DataLogging/apply loads/EtherCAT Apply Loads/A2 Apply torques/BKIN EtherCAT PDO Transmit 2",
    "P3", 0, 1, 0 },

  { 1699,
    "DataLogging/apply loads/EtherCAT Apply Loads/A2 Apply torques/BKIN EtherCAT PDO Transmit 2",
    "P4", 0, 1, 0 },

  { 1700,
    "DataLogging/apply loads/EtherCAT Apply Loads/A2 Apply torques/BKIN EtherCAT PDO Transmit 2",
    "P5", 0, 1, 0 },

  { 1701,
    "DataLogging/apply loads/EtherCAT Apply Loads/A2 Apply torques/BKIN EtherCAT PDO Transmit 2",
    "P6", 0, 1, 0 },

  { 1702,
    "DataLogging/apply loads/EtherCAT Apply Loads/A2 Apply torques/BKIN EtherCAT PDO Transmit 2",
    "P7", 0, 1, 0 },

  { 1703,
    "DataLogging/Network Transfer Subsystem/UDP Send Subsystem/Counter Free-Running/Increment Real World/FixPt Constant",
    "Value", 4, 1, 0 },

  { 1704,
    "DataLogging/Network Transfer Subsystem/UDP Send Subsystem/Counter Free-Running/Wrap To Zero/Constant",
    "Value", 4, 1, 0 },

  { 1705,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M1/Compare To Constant",
    "const", 3, 1, 0 },

  { 1706, "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M1/MotorIdx",
    "Value", 0, 1, 0 },

  { 1707, "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M1/Memory",
    "X0", 0, 1, 0 },

  { 1708,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M1/BKIN EtherCAT PDO Transmit ",
    "P1", 0, 100, 0 },

  { 1709,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M1/BKIN EtherCAT PDO Transmit ",
    "P2", 0, 1, 0 },

  { 1710,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M1/BKIN EtherCAT PDO Transmit ",
    "P3", 0, 1, 0 },

  { 1711,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M1/BKIN EtherCAT PDO Transmit ",
    "P4", 0, 1, 0 },

  { 1712,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M1/BKIN EtherCAT PDO Transmit ",
    "P5", 0, 1, 0 },

  { 1713,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M1/BKIN EtherCAT PDO Transmit ",
    "P6", 0, 1, 0 },

  { 1714,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M1/BKIN EtherCAT PDO Transmit ",
    "P7", 0, 1, 0 },

  { 1715, "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M2/Compare",
    "const", 3, 1, 0 },

  { 1716, "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M2/MotorIdx",
    "Value", 0, 1, 0 },

  { 1717, "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M2/Memory",
    "X0", 0, 1, 0 },

  { 1718,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M2/BKIN EtherCAT PDO Transmit ",
    "P1", 0, 100, 0 },

  { 1719,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M2/BKIN EtherCAT PDO Transmit ",
    "P2", 0, 1, 0 },

  { 1720,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M2/BKIN EtherCAT PDO Transmit ",
    "P3", 0, 1, 0 },

  { 1721,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M2/BKIN EtherCAT PDO Transmit ",
    "P4", 0, 1, 0 },

  { 1722,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M2/BKIN EtherCAT PDO Transmit ",
    "P5", 0, 1, 0 },

  { 1723,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M2/BKIN EtherCAT PDO Transmit ",
    "P6", 0, 1, 0 },

  { 1724,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M2/BKIN EtherCAT PDO Transmit ",
    "P7", 0, 1, 0 },

  { 1725,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/M1 AbsEnc Calibration/Memory",
    "X0", 3, 1, 0 },

  { 1726,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/M1 AbsEnc Calibration/Memory1",
    "X0", 3, 1, 0 },

  { 1727,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/M2 AbsEnc Calibration/Memory",
    "X0", 3, 1, 0 },

  { 1728,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/M2 AbsEnc Calibration/Memory1",
    "X0", 3, 1, 0 },

  { 1729,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/SDO reading/readAddr",
    "Value", 0, 76, 0 },

  { 1730, "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/SDO reading/Memory",
    "X0", 0, 1, 0 },

  { 1731,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/SDO writing/writeData",
    "Value", 0, 90, 0 },

  { 1732, "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/SDO writing/Memory",
    "X0", 3, 1, 0 },

  { 1733,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/int subsystem/Memory",
    "X0", 3, 1, 0 },

  { 1734,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/int subsystem/Memory1",
    "X0", 0, 1, 0 },

  { 1735,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/int subsystem/Memory2",
    "X0", 0, 1, 0 },

  { 1736, "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M1/Compare",
    "const", 3, 1, 0 },

  { 1737, "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M1/MotorIdx",
    "Value", 0, 1, 0 },

  { 1738, "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M1/Memory",
    "X0", 0, 1, 0 },

  { 1739,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M1/BKIN EtherCAT PDO Transmit ",
    "P1", 0, 100, 0 },

  { 1740,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M1/BKIN EtherCAT PDO Transmit ",
    "P2", 0, 1, 0 },

  { 1741,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M1/BKIN EtherCAT PDO Transmit ",
    "P3", 0, 1, 0 },

  { 1742,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M1/BKIN EtherCAT PDO Transmit ",
    "P4", 0, 1, 0 },

  { 1743,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M1/BKIN EtherCAT PDO Transmit ",
    "P5", 0, 1, 0 },

  { 1744,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M1/BKIN EtherCAT PDO Transmit ",
    "P6", 0, 1, 0 },

  { 1745,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M1/BKIN EtherCAT PDO Transmit ",
    "P7", 0, 1, 0 },

  { 1746, "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M2/Compare",
    "const", 3, 1, 0 },

  { 1747, "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M2/MotorIdx",
    "Value", 0, 1, 0 },

  { 1748, "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M2/Memory",
    "X0", 0, 1, 0 },

  { 1749,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M2/BKIN EtherCAT PDO Transmit ",
    "P1", 0, 100, 0 },

  { 1750,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M2/BKIN EtherCAT PDO Transmit ",
    "P2", 0, 1, 0 },

  { 1751,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M2/BKIN EtherCAT PDO Transmit ",
    "P3", 0, 1, 0 },

  { 1752,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M2/BKIN EtherCAT PDO Transmit ",
    "P4", 0, 1, 0 },

  { 1753,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M2/BKIN EtherCAT PDO Transmit ",
    "P5", 0, 1, 0 },

  { 1754,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M2/BKIN EtherCAT PDO Transmit ",
    "P6", 0, 1, 0 },

  { 1755,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M2/BKIN EtherCAT PDO Transmit ",
    "P7", 0, 1, 0 },

  { 1756,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/M1 AbsEnc Calibration/Memory",
    "X0", 3, 1, 0 },

  { 1757,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/M1 AbsEnc Calibration/Memory1",
    "X0", 3, 1, 0 },

  { 1758,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/M2 AbsEnc Calibration/Memory",
    "X0", 3, 1, 0 },

  { 1759,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/M2 AbsEnc Calibration/Memory1",
    "X0", 3, 1, 0 },

  { 1760,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/SDO reading/readAddr",
    "Value", 0, 76, 0 },

  { 1761, "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/SDO reading/Memory",
    "X0", 0, 1, 0 },

  { 1762,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/SDO writing/writeData",
    "Value", 0, 90, 0 },

  { 1763, "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/SDO writing/Memory",
    "X0", 3, 1, 0 },

  { 1764,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/int subsystem/Memory",
    "X0", 3, 1, 0 },

  { 1765,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/int subsystem/Memory1",
    "X0", 0, 1, 0 },

  { 1766,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/int subsystem/Memory2",
    "X0", 0, 1, 0 },

  { 1767,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Counter Free-Running/Increment Real World/FixPt Constant",
    "Value", 4, 1, 0 },

  { 1768,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Counter Free-Running/Wrap To Zero/Constant",
    "Value", 4, 1, 0 },

  { 1769,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/update/create filtered velocities/2nd order butterworth, 4Khz, 10hz cutoff",
    "Value", 0, 76, 0 },

  { 1770,
    "DataLogging/Poll KINARM/Force Sensor Control/Force Sensor 1 Subsystem/If Action Subsystem/Constant",
    "Value", 1, 1, 0 },

  { 1771,
    "DataLogging/Poll KINARM/Force Sensor Control/Force Sensor 1 Subsystem/If Action Subsystem/Constant1",
    "Value", 4, 1, 0 },

  { 1772,
    "DataLogging/Poll KINARM/Force Sensor Control/Force Sensor 1 Subsystem/If Action Subsystem/Constant2",
    "Value", 1, 1, 0 },

  { 1773,
    "DataLogging/Poll KINARM/Force Sensor Control/Force Sensor 1 Subsystem/If Action Subsystem/Constant3",
    "Value", 1, 1, 0 },

  { 1774,
    "DataLogging/Poll KINARM/Force Sensor Control/Force Sensor 1 Subsystem/If Action Subsystem/Send",
    "P1", 0, 98, 0 },

  { 1775,
    "DataLogging/Poll KINARM/Force Sensor Control/Force Sensor 1 Subsystem/If Action Subsystem/Send",
    "P2", 0, 1, 0 },

  { 1776,
    "DataLogging/Poll KINARM/Force Sensor Control/Force Sensor 1 Subsystem/If Action Subsystem/Send",
    "P3", 0, 1, 0 },

  { 1777,
    "DataLogging/Poll KINARM/Force Sensor Control/Force Sensor 1 Subsystem/If Action Subsystem/Send",
    "P4", 0, 1, 0 },

  { 1778,
    "DataLogging/Poll KINARM/Force Sensor Control/Force Sensor 1 Subsystem/If Action Subsystem/Send",
    "P5", 0, 1, 0 },

  { 1779,
    "DataLogging/Poll KINARM/Force Sensor Control/Force Sensor 1 Subsystem/If Action Subsystem/Switch",
    "Threshold", 0, 1, 0 },

  { 1780,
    "DataLogging/Poll KINARM/Force Sensor Control/Force Sensor 2 Subsystem/Data Transfer Start Subsystem/Constant",
    "Value", 1, 1, 0 },

  { 1781,
    "DataLogging/Poll KINARM/Force Sensor Control/Force Sensor 2 Subsystem/Data Transfer Start Subsystem/Constant1",
    "Value", 4, 1, 0 },

  { 1782,
    "DataLogging/Poll KINARM/Force Sensor Control/Force Sensor 2 Subsystem/Data Transfer Start Subsystem/Constant2",
    "Value", 1, 1, 0 },

  { 1783,
    "DataLogging/Poll KINARM/Force Sensor Control/Force Sensor 2 Subsystem/Data Transfer Start Subsystem/Constant3",
    "Value", 1, 1, 0 },

  { 1784,
    "DataLogging/Poll KINARM/Force Sensor Control/Force Sensor 2 Subsystem/Data Transfer Start Subsystem/Send",
    "P1", 0, 98, 0 },

  { 1785,
    "DataLogging/Poll KINARM/Force Sensor Control/Force Sensor 2 Subsystem/Data Transfer Start Subsystem/Send",
    "P2", 0, 1, 0 },

  { 1786,
    "DataLogging/Poll KINARM/Force Sensor Control/Force Sensor 2 Subsystem/Data Transfer Start Subsystem/Send",
    "P3", 0, 1, 0 },

  { 1787,
    "DataLogging/Poll KINARM/Force Sensor Control/Force Sensor 2 Subsystem/Data Transfer Start Subsystem/Send",
    "P4", 0, 1, 0 },

  { 1788,
    "DataLogging/Poll KINARM/Force Sensor Control/Force Sensor 2 Subsystem/Data Transfer Start Subsystem/Send",
    "P5", 0, 1, 0 },

  { 1789,
    "DataLogging/Poll KINARM/Force Sensor Control/Force Sensor 2 Subsystem/Data Transfer Start Subsystem/Switch",
    "Threshold", 0, 1, 0 },

  { 1790,
    "DataLogging/Poll KINARM/PMAC Subsystem/read_pmac/DPRAM Access Subsystem/DPRAM Read Offset",
    "Value", 0, 1, 0 },

  { 1791,
    "DataLogging/Poll KINARM/PMAC Subsystem/read_pmac/DPRAM Access Subsystem/DPRAM WatchDog offset",
    "Value", 0, 1, 0 },

  { 1792,
    "DataLogging/Poll KINARM/PMAC Subsystem/read_pmac/DPRAM Access Subsystem/DPRAM Write Offset",
    "Value", 0, 1, 0 },

  { 1793,
    "DataLogging/Poll KINARM/PMAC Subsystem/read_pmac/DPRAM Access Subsystem/DPRAM Write Value",
    "Value", 0, 1, 0 },

  { 1794,
    "DataLogging/Poll KINARM/PMAC Subsystem/read_pmac/DPRAM Access Subsystem/Read Switch",
    "Value", 0, 1, 0 },

  { 1795,
    "DataLogging/Poll KINARM/PMAC Subsystem/read_pmac/DPRAM Access Subsystem/Read as UInt32",
    "Value", 0, 1, 0 },

  { 1796,
    "DataLogging/Poll KINARM/PMAC Subsystem/read_pmac/DPRAM Access Subsystem/Write Switch",
    "Value", 0, 1, 0 },

  { 1797,
    "DataLogging/Poll KINARM/PMAC Subsystem/read_pmac/DPRAM Access Subsystem/DPRAM Read Value",
    "Gain", 0, 1, 0 },

  { 1798,
    "DataLogging/Poll KINARM/PMAC Subsystem/read_pmac/DPRAM Access Subsystem/Unit Delay",
    "InitialCondition", 0, 1, 0 },

  { 1799,
    "DataLogging/Poll KINARM/PMAC Subsystem/read_pmac/DPRAM Access Subsystem/Unit Delay1",
    "InitialCondition", 0, 1, 0 },

  { 1800,
    "DataLogging/Poll KINARM/bkin_internal_testing/Data receive/Counter Free-Running/Wrap To Zero",
    "Threshold", 4, 1, 0 },

  { 1801,
    "DataLogging/Poll KINARM/bkin_internal_testing/Data receive/Counter Free-Running/Output",
    "InitialCondition", 4, 1, 0 },

  { 1802,
    "DataLogging/Poll KINARM/createKINData/Counter Free-Running/Increment Real World/FixPt Constant",
    "Value", 4, 1, 0 },

  { 1803,
    "DataLogging/Poll KINARM/createKINData/Counter Free-Running/Wrap To Zero/Constant",
    "Value", 4, 1, 0 },

  { 1804,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M1/A1M1 PDOs/BKIN PDO Receive ElmoDrive",
    "P1", 0, 101, 0 },

  { 1805,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M1/A1M1 PDOs/BKIN PDO Receive ElmoDrive",
    "P2", 0, 1, 0 },

  { 1806,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M1/A1M1 PDOs/BKIN PDO Receive ElmoDrive",
    "P3", 0, 1, 0 },

  { 1807,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M1/A1M1 PDOs/BKIN PDO Receive ElmoDrive",
    "P4", 0, 1, 0 },

  { 1808,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M1/A1M1 PDOs/BKIN PDO Receive ElmoDrive",
    "P5", 0, 1, 0 },

  { 1809,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M1/A1M1 PDOs/BKIN PDO Receive ElmoDrive",
    "P6", 0, 1, 0 },

  { 1810,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M1/A1M1 PDOs/BKIN PDO Receive ElmoDrive",
    "P7", 0, 1, 0 },

  { 1811,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M1/EMCY Message pump/driveID",
    "Value", 0, 1, 0 },

  { 1812,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M2/A1M2 PDOs/BKIN PDO Receive ElmoDrive",
    "P1", 0, 101, 0 },

  { 1813,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M2/A1M2 PDOs/BKIN PDO Receive ElmoDrive",
    "P2", 0, 1, 0 },

  { 1814,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M2/A1M2 PDOs/BKIN PDO Receive ElmoDrive",
    "P3", 0, 1, 0 },

  { 1815,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M2/A1M2 PDOs/BKIN PDO Receive ElmoDrive",
    "P4", 0, 1, 0 },

  { 1816,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M2/A1M2 PDOs/BKIN PDO Receive ElmoDrive",
    "P5", 0, 1, 0 },

  { 1817,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M2/A1M2 PDOs/BKIN PDO Receive ElmoDrive",
    "P6", 0, 1, 0 },

  { 1818,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M2/A1M2 PDOs/BKIN PDO Receive ElmoDrive",
    "P7", 0, 1, 0 },

  { 1819,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M2/EMCY Message pump/driveID",
    "Value", 0, 1, 0 },

  { 1820,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M1/A2M1 PDOs/BKIN PDO Receive ElmoDrive",
    "P1", 0, 101, 0 },

  { 1821,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M1/A2M1 PDOs/BKIN PDO Receive ElmoDrive",
    "P2", 0, 1, 0 },

  { 1822,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M1/A2M1 PDOs/BKIN PDO Receive ElmoDrive",
    "P3", 0, 1, 0 },

  { 1823,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M1/A2M1 PDOs/BKIN PDO Receive ElmoDrive",
    "P4", 0, 1, 0 },

  { 1824,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M1/A2M1 PDOs/BKIN PDO Receive ElmoDrive",
    "P5", 0, 1, 0 },

  { 1825,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M1/A2M1 PDOs/BKIN PDO Receive ElmoDrive",
    "P6", 0, 1, 0 },

  { 1826,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M1/A2M1 PDOs/BKIN PDO Receive ElmoDrive",
    "P7", 0, 1, 0 },

  { 1827,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M1/EMCY Message pump/driveID",
    "Value", 0, 1, 0 },

  { 1828,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M2/A2M2 PDOs/BKIN PDO Receive ElmoDrive",
    "P1", 0, 101, 0 },

  { 1829,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M2/A2M2 PDOs/BKIN PDO Receive ElmoDrive",
    "P2", 0, 1, 0 },

  { 1830,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M2/A2M2 PDOs/BKIN PDO Receive ElmoDrive",
    "P3", 0, 1, 0 },

  { 1831,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M2/A2M2 PDOs/BKIN PDO Receive ElmoDrive",
    "P4", 0, 1, 0 },

  { 1832,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M2/A2M2 PDOs/BKIN PDO Receive ElmoDrive",
    "P5", 0, 1, 0 },

  { 1833,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M2/A2M2 PDOs/BKIN PDO Receive ElmoDrive",
    "P6", 0, 1, 0 },

  { 1834,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M2/A2M2 PDOs/BKIN PDO Receive ElmoDrive",
    "P7", 0, 1, 0 },

  { 1835,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M2/EMCY Message pump/driveID",
    "Value", 0, 1, 0 },

  { 1836,
    "DataLogging/Poll KINARM/PMAC Subsystem/read_pmac/DPRAM Access Subsystem/Counter Free-Running/Wrap To Zero",
    "Threshold", 1, 1, 0 },

  { 1837,
    "DataLogging/Poll KINARM/PMAC Subsystem/read_pmac/DPRAM Access Subsystem/Counter Free-Running/Output",
    "InitialCondition", 1, 1, 0 },

  { 1838,
    "DataLogging/Poll KINARM/bkin_internal_testing/Data receive/Counter Free-Running/Increment Real World/FixPt Constant",
    "Value", 4, 1, 0 },

  { 1839,
    "DataLogging/Poll KINARM/bkin_internal_testing/Data receive/Counter Free-Running/Wrap To Zero/Constant",
    "Value", 4, 1, 0 },

  { 1840,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M1/EMCY Message pump/Read EMCY Count/Constant",
    "Value", 3, 1, 0 },

  { 1841,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M1/EMCY Message pump/Read EMCY Count/Constant1",
    "Value", 3, 1, 0 },

  { 1842,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M1/EMCY Message pump/Read EMCY Count/Memory",
    "X0", 4, 1, 0 },

  { 1843,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M1/EMCY Message pump/Read EMCY Value/Constant",
    "Value", 3, 1, 0 },

  { 1844,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M1/EMCY Message pump/Read EMCY Value/Memory",
    "X0", 3, 1, 0 },

  { 1845,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M1/EMCY Message pump/clear errors/Constant",
    "Value", 4, 1, 0 },

  { 1846,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M1/EMCY Message pump/clear errors/Constant1",
    "Value", 3, 1, 0 },

  { 1847,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M1/EMCY Message pump/clear errors/Memory",
    "X0", 0, 1, 0 },

  { 1848,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M2/EMCY Message pump/Read EMCY Count/Constant",
    "Value", 3, 1, 0 },

  { 1849,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M2/EMCY Message pump/Read EMCY Count/Constant1",
    "Value", 3, 1, 0 },

  { 1850,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M2/EMCY Message pump/Read EMCY Count/Memory",
    "X0", 4, 1, 0 },

  { 1851,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M2/EMCY Message pump/Read EMCY Value/Constant",
    "Value", 3, 1, 0 },

  { 1852,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M2/EMCY Message pump/Read EMCY Value/Memory",
    "X0", 3, 1, 0 },

  { 1853,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M2/EMCY Message pump/clear errors/Constant",
    "Value", 4, 1, 0 },

  { 1854,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M2/EMCY Message pump/clear errors/Constant1",
    "Value", 3, 1, 0 },

  { 1855,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M2/EMCY Message pump/clear errors/Memory",
    "X0", 0, 1, 0 },

  { 1856,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M1/EMCY Message pump/Read EMCY Count/Constant",
    "Value", 3, 1, 0 },

  { 1857,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M1/EMCY Message pump/Read EMCY Count/Constant1",
    "Value", 3, 1, 0 },

  { 1858,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M1/EMCY Message pump/Read EMCY Count/Memory",
    "X0", 4, 1, 0 },

  { 1859,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M1/EMCY Message pump/Read EMCY Value/Constant",
    "Value", 3, 1, 0 },

  { 1860,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M1/EMCY Message pump/Read EMCY Value/Memory",
    "X0", 3, 1, 0 },

  { 1861,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M1/EMCY Message pump/clear errors/Constant",
    "Value", 4, 1, 0 },

  { 1862,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M1/EMCY Message pump/clear errors/Constant1",
    "Value", 3, 1, 0 },

  { 1863,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M1/EMCY Message pump/clear errors/Memory",
    "X0", 0, 1, 0 },

  { 1864,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M2/EMCY Message pump/Read EMCY Count/Constant",
    "Value", 3, 1, 0 },

  { 1865,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M2/EMCY Message pump/Read EMCY Count/Constant1",
    "Value", 3, 1, 0 },

  { 1866,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M2/EMCY Message pump/Read EMCY Count/Memory",
    "X0", 4, 1, 0 },

  { 1867,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M2/EMCY Message pump/Read EMCY Value/Constant",
    "Value", 3, 1, 0 },

  { 1868,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M2/EMCY Message pump/Read EMCY Value/Memory",
    "X0", 3, 1, 0 },

  { 1869,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M2/EMCY Message pump/clear errors/Constant",
    "Value", 4, 1, 0 },

  { 1870,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M2/EMCY Message pump/clear errors/Constant1",
    "Value", 3, 1, 0 },

  { 1871,
    "DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M2/EMCY Message pump/clear errors/Memory",
    "X0", 0, 1, 0 },

  { 1872,
    "DataLogging/Poll KINARM/PMAC Subsystem/read_pmac/DPRAM Access Subsystem/Counter Free-Running/Increment Real World/FixPt Constant",
    "Value", 1, 1, 0 },

  { 1873,
    "DataLogging/Poll KINARM/PMAC Subsystem/read_pmac/DPRAM Access Subsystem/Counter Free-Running/Wrap To Zero/Constant",
    "Value", 1, 1, 0 },

  {
    0, NULL, NULL, 0, 0, 0
  }
};

/* Tunable variable parameters */
static const rtwCAPI_ModelParameters rtModelParameters[] = {
  /* addrMapIndex, varName, dataTypeIndex, dimIndex, fixPtIndex */
  { 0, NULL, 0, 0, 0 }
};

/* Declare Data Addresses statically */
static void* rtDataAddrMap[] = {
  &gbyk_v4b_B.VCODE_MOD_n[0],          /* 0: Signal */
  &gbyk_v4b_B.VCODE_MOD[0],            /* 1: Signal */
  &gbyk_v4b_B.ListReps,                /* 2: Signal */
  &gbyk_v4b_B.logging_enable[0],       /* 3: Signal */
  &gbyk_v4b_B.event_code,              /* 4: Signal */
  &gbyk_v4b_B.VectorConcatenate1[0],   /* 5: Signal */
  &gbyk_v4b_B.VectorConcatenate1[0],   /* 6: Signal */
  &gbyk_v4b_B.VectorConcatenate1[0],   /* 7: Signal */
  &gbyk_v4b_B.VectorConcatenate1[0],   /* 8: Signal */
  &gbyk_v4b_B.targetA_row,             /* 9: Signal */
  &gbyk_v4b_B.targetA_state,           /* 10: Signal */
  &gbyk_v4b_B.targetB_row[0],          /* 11: Signal */
  &gbyk_v4b_B.targetB_state[0],        /* 12: Signal */
  &gbyk_v4b_B.offeredRewards[0],       /* 13: Signal */
  &gbyk_v4b_B.score,                   /* 14: Signal */
  &gbyk_v4b_B.doreward,                /* 15: Signal */
  &gbyk_v4b_B.feedback_text,           /* 16: Signal */
  &gbyk_v4b_B.reward,                  /* 17: Signal */
  &gbyk_v4b_B.instruct_num,            /* 18: Signal */
  &gbyk_v4b_B.tone,                    /* 19: Signal */
  &gbyk_v4b_B.repeat_trial_flag,       /* 20: Signal */
  &gbyk_v4b_B.trialIterations[0],      /* 21: Signal */
  &gbyk_v4b_B.targetC_row[0],          /* 22: Signal */
  &gbyk_v4b_B.targetC_state[0],        /* 23: Signal */
  &gbyk_v4b_B.offeredRewardsC[0],      /* 24: Signal */
  &gbyk_v4b_B.boxRow,                  /* 25: Signal */
  &gbyk_v4b_B.boxState,                /* 26: Signal */
  &gbyk_v4b_B.e_Trial_End,             /* 27: Signal */
  &gbyk_v4b_B.MatrixConcatenation_b[0],/* 28: Signal */
  &gbyk_v4b_B.VectorConcatenate[0],    /* 29: Signal */
  &gbyk_v4b_B.VectorConcatenate1[0],   /* 30: Signal */
  &gbyk_v4b_B.VectorConcatenate2[0],   /* 31: Signal */
  &gbyk_v4b_B.VectorConcatenate[0],    /* 32: Signal */
  &gbyk_v4b_B.MathFunction[0],         /* 33: Signal */
  &gbyk_v4b_B.Product,                 /* 34: Signal */
  &gbyk_v4b_B.Selector2,               /* 35: Signal */
  &gbyk_v4b_B.Selector3[0],            /* 36: Signal */
  &gbyk_v4b_B.Selector4[0],            /* 37: Signal */
  &gbyk_v4b_B.Selector5[0],            /* 38: Signal */
  &gbyk_v4b_B.SumofElements,           /* 39: Signal */
  &gbyk_v4b_B.Switch[0],               /* 40: Signal */
  &gbyk_v4b_B.Switch1[0],              /* 41: Signal */
  &gbyk_v4b_B.TrigonometricFunction,   /* 42: Signal */
  &gbyk_v4b_B.Sqrt,                    /* 43: Signal */
  &gbyk_v4b_B.Compare_k,               /* 44: Signal */
  &gbyk_v4b_B.readDigitaldiag[0],      /* 45: Signal */
  &gbyk_v4b_B.readstatus[0],           /* 46: Signal */
  &gbyk_v4b_B.Memory[0],               /* 47: Signal */
  &gbyk_v4b_B.Memory1,                 /* 48: Signal */
  &gbyk_v4b_B.RateTransition_d[0],     /* 49: Signal */
  &gbyk_v4b_B.RateTransition1_i[0],    /* 50: Signal */
  &gbyk_v4b_B.RateTransition2_ea[0],   /* 51: Signal */
  &gbyk_v4b_B.AddTorques[0],           /* 52: Signal */
  &gbyk_v4b_B.Abs,                     /* 53: Signal */
  &gbyk_v4b_B.Sign,                    /* 54: Signal */
  &gbyk_v4b_B.Add,                     /* 55: Signal */
  &gbyk_v4b_B.VCODE_mod[0],            /* 56: Signal */
  &gbyk_v4b_B.Abs_f,                   /* 57: Signal */
  &gbyk_v4b_B.DataTypeConversion_b,    /* 58: Signal */
  &gbyk_v4b_B.LogicalOperator,         /* 59: Signal */
  &gbyk_v4b_B.Switch_h,                /* 60: Signal */
  &gbyk_v4b_B.BlockDefinitions[0],     /* 61: Signal */
  &gbyk_v4b_B.BlockSequence[0],        /* 62: Signal */
  &gbyk_v4b_B.LibraryPatchVersion,     /* 63: Signal */
  &gbyk_v4b_B.LibraryVersion,          /* 64: Signal */
  &gbyk_v4b_B.LoadTable[0],            /* 65: Signal */
  &gbyk_v4b_B.NextBlock,               /* 66: Signal */
  &gbyk_v4b_B.PauseType,               /* 67: Signal */
  &gbyk_v4b_B.TargetTable[0],          /* 68: Signal */
  &gbyk_v4b_B.TaskVersion,             /* 69: Signal */
  &gbyk_v4b_B.Taskwideparam[0],        /* 70: Signal */
  &gbyk_v4b_B.UseTaskProtocolBlockSequenceFlag,/* 71: Signal */
  &gbyk_v4b_B.dlmbuildtime,            /* 72: Signal */
  &gbyk_v4b_B.frame_of_reference_center[0],/* 73: Signal */
  &gbyk_v4b_B.xPCVersion,              /* 74: Signal */
  &gbyk_v4b_B.Convert1[0],             /* 75: Signal */
  &gbyk_v4b_B.Convert10[0],            /* 76: Signal */
  &gbyk_v4b_B.Convert11[0],            /* 77: Signal */
  &gbyk_v4b_B.Convert12,               /* 78: Signal */
  &gbyk_v4b_B.Convert13[0],            /* 79: Signal */
  &gbyk_v4b_B.Convert14[0],            /* 80: Signal */
  &gbyk_v4b_B.Convert15,               /* 81: Signal */
  &gbyk_v4b_B.Convert16,               /* 82: Signal */
  &gbyk_v4b_B.Convert17,               /* 83: Signal */
  &gbyk_v4b_B.Convert18,               /* 84: Signal */
  &gbyk_v4b_B.Convert19_b,             /* 85: Signal */
  &gbyk_v4b_B.Convert20,               /* 86: Signal */
  &gbyk_v4b_B.Convert21,               /* 87: Signal */
  &gbyk_v4b_B.Convert22,               /* 88: Signal */
  &gbyk_v4b_B.Convert23,               /* 89: Signal */
  &gbyk_v4b_B.Convert24,               /* 90: Signal */
  &gbyk_v4b_B.Convert25,               /* 91: Signal */
  &gbyk_v4b_B.Convert7,                /* 92: Signal */
  &gbyk_v4b_B.Convert8,                /* 93: Signal */
  &gbyk_v4b_B.Convert9[0],             /* 94: Signal */
  &gbyk_v4b_B.MinMax,                  /* 95: Signal */
  &gbyk_v4b_B.TPSelector[0],           /* 96: Signal */
  &gbyk_v4b_B.VCODES_out[0],           /* 97: Signal */
  &gbyk_v4b_B.MatrixConcatenation[0],  /* 98: Signal */
  &gbyk_v4b_B.Reshape[0],              /* 99: Signal */
  &gbyk_v4b_B.Reshape1[0],             /* 100: Signal */
  &gbyk_v4b_B.distance[0],             /* 101: Signal */
  &gbyk_v4b_B.sf_EmbeddedMATLABWhichHand_d.hand,/* 102: Signal */
  &gbyk_v4b_B.MultiportSwitch_c[0],    /* 103: Signal */
  &gbyk_v4b_B.Arm1_a[0],               /* 104: Signal */
  &gbyk_v4b_B.Arm2_j[0],               /* 105: Signal */
  &gbyk_v4b_B.Dominant_Arm_k,          /* 106: Signal */
  &gbyk_v4b_B.Hand_Pos_i[0],           /* 107: Signal */
  &gbyk_v4b_B.intarget_l[0],           /* 108: Signal */
  &gbyk_v4b_B.sf_EmbeddedMATLABWhichHand_k.hand,/* 109: Signal */
  &gbyk_v4b_B.MultiportSwitch_b[0],    /* 110: Signal */
  &gbyk_v4b_B.Arm1_p[0],               /* 111: Signal */
  &gbyk_v4b_B.Arm2_o[0],               /* 112: Signal */
  &gbyk_v4b_B.ArraySelector_n[0],      /* 113: Signal */
  &gbyk_v4b_B.Dominant_Arm_o,          /* 114: Signal */
  &gbyk_v4b_B.Hand_Pos_n[0],           /* 115: Signal */
  &gbyk_v4b_B.intarget[0],             /* 116: Signal */
  &gbyk_v4b_B.sf_EmbeddedMATLABWhichHand.hand,/* 117: Signal */
  &gbyk_v4b_B.MultiportSwitch[0],      /* 118: Signal */
  &gbyk_v4b_B.Arm1[0],                 /* 119: Signal */
  &gbyk_v4b_B.Arm2[0],                 /* 120: Signal */
  &gbyk_v4b_B.ArraySelector[0],        /* 121: Signal */
  &gbyk_v4b_B.Dominant_Arm,            /* 122: Signal */
  &gbyk_v4b_B.Hand_Pos[0],             /* 123: Signal */
  &gbyk_v4b_B.last_frame_ack,          /* 124: Signal */
  &gbyk_v4b_B.last_perm_ack,           /* 125: Signal */
  &gbyk_v4b_B.MatrixConcatenate[0],    /* 126: Signal */
  &gbyk_v4b_B.MatrixConcatenate[0],    /* 127: Signal */
  &gbyk_v4b_B.Convert,                 /* 128: Signal */
  &gbyk_v4b_B.Convert1_a,              /* 129: Signal */
  &gbyk_v4b_B.Gain,                    /* 130: Signal */
  &gbyk_v4b_B.Memory_k,                /* 131: Signal */
  &gbyk_v4b_B.MatrixConcatenate[0],    /* 132: Signal */
  &gbyk_v4b_B.RateTransition2[0],      /* 133: Signal */
  &gbyk_v4b_B.Receive_o1[0],           /* 134: Signal */
  &gbyk_v4b_B.Receive_o2,              /* 135: Signal */
  &gbyk_v4b_B.Unpack_c,                /* 136: Signal */
  &gbyk_v4b_B.sf_EmbeddedMATLABFunction_c.VCODE[0],/* 137: Signal */
  &gbyk_v4b_B.MatrixConcatenation1_h[0],/* 138: Signal */
  &gbyk_v4b_B.MatrixConcatenation1_h[0],/* 139: Signal */
  &gbyk_v4b_B.MatrixConcatenation1_h[0],/* 140: Signal */
  &gbyk_v4b_B.Selector_d[0],           /* 141: Signal */
  &gbyk_v4b_B.sf_EmbeddedMATLABFunction_k.VCODE[0],/* 142: Signal */
  &gbyk_v4b_B.MatrixConcatenation1_n[0],/* 143: Signal */
  &gbyk_v4b_B.MatrixConcatenation1_n[0],/* 144: Signal */
  &gbyk_v4b_B.MatrixConcatenation1_n[0],/* 145: Signal */
  &gbyk_v4b_B.Selector_l[0],           /* 146: Signal */
  &gbyk_v4b_B.sf_EmbeddedMATLABFunction_id.VCODE[0],/* 147: Signal */
  &gbyk_v4b_B.MatrixConcatenation1_p[0],/* 148: Signal */
  &gbyk_v4b_B.MatrixConcatenation1_p[0],/* 149: Signal */
  &gbyk_v4b_B.MatrixConcatenation1_p[0],/* 150: Signal */
  &gbyk_v4b_B.Selector_i[0],           /* 151: Signal */
  &gbyk_v4b_B.sf_EmbeddedMATLABFunction_i.VCODE[0],/* 152: Signal */
  &gbyk_v4b_B.MatrixConcatenation1[0], /* 153: Signal */
  &gbyk_v4b_B.MatrixConcatenation1[0], /* 154: Signal */
  &gbyk_v4b_B.MatrixConcatenation1[0], /* 155: Signal */
  &gbyk_v4b_B.Selector[0],             /* 156: Signal */
  &gbyk_v4b_B.AnalogData[0],           /* 157: Signal */
  &gbyk_v4b_B.AnalogDataWidth,         /* 158: Signal */
  &gbyk_v4b_B.RateTransition_c,        /* 159: Signal */
  &gbyk_v4b_B.RateTransition1_c[0],    /* 160: Signal */
  &gbyk_v4b_B.Subtract,                /* 161: Signal */
  (void *) &gbyk_v4b_ConstB.Width_a,   /* 162: Signal */
  &gbyk_v4b_B.CustomData1[0],          /* 163: Signal */
  &gbyk_v4b_B.RateTransition_b[0],     /* 164: Signal */
  &gbyk_v4b_B.RateTransition1_b,       /* 165: Signal */
  &gbyk_v4b_B.RateTransition2_eo,      /* 166: Signal */
  (void *) &gbyk_v4b_ConstB.Width_g,   /* 167: Signal */
  &gbyk_v4b_B.EventCodes,              /* 168: Signal */
  &gbyk_v4b_B.NumberofEventCodes,      /* 169: Signal */
  &gbyk_v4b_B.Subtract_g,              /* 170: Signal */
  (void *) &gbyk_v4b_ConstB.Width_c,   /* 171: Signal */
  &gbyk_v4b_B.bitfield,                /* 172: Signal */
  &gbyk_v4b_B.ArmKinematics[0],        /* 173: Signal */
  &gbyk_v4b_B.KinarmDataWidth,         /* 174: Signal */
  &gbyk_v4b_B.touint[0],               /* 175: Signal */
  &gbyk_v4b_B.touint1,                 /* 176: Signal */
  &gbyk_v4b_B.RateTransition_k[0],     /* 177: Signal */
  &gbyk_v4b_B.RateTransition1_n,       /* 178: Signal */
  &gbyk_v4b_B.RateTransition2_er[0],   /* 179: Signal */
  &gbyk_v4b_B.RateTransition3_n[0],    /* 180: Signal */
  (void *) &gbyk_v4b_ConstB.Width_d,   /* 181: Signal */
  &gbyk_v4b_B.ButtonStatus,            /* 182: Signal */
  &gbyk_v4b_B.CurrentBlockIndex,       /* 183: Signal */
  &gbyk_v4b_B.CurrentBlockNumberinSet, /* 184: Signal */
  &gbyk_v4b_B.CurrentTPIndex,          /* 185: Signal */
  &gbyk_v4b_B.CurrentTrialNumberinBlock,/* 186: Signal */
  &gbyk_v4b_B.CurrentTrialNumberinSet, /* 187: Signal */
  &gbyk_v4b_B.LastFrameAcknowledged,   /* 188: Signal */
  &gbyk_v4b_B.LastFrameSent,           /* 189: Signal */
  &gbyk_v4b_B.LastFrameSent1,          /* 190: Signal */
  &gbyk_v4b_B.LoggingEnable[0],        /* 191: Signal */
  &gbyk_v4b_B.RunStatus,               /* 192: Signal */
  &gbyk_v4b_B.Servoupdatecount,        /* 193: Signal */
  &gbyk_v4b_B.TaskControlButton,       /* 194: Signal */
  &gbyk_v4b_B.Timestamp,               /* 195: Signal */
  &gbyk_v4b_B.conv,                    /* 196: Signal */
  &gbyk_v4b_B.Product_g[0],            /* 197: Signal */
  &gbyk_v4b_B.RateTransition,          /* 198: Signal */
  &gbyk_v4b_B.RateTransition1,         /* 199: Signal */
  &gbyk_v4b_B.RateTransition10,        /* 200: Signal */
  &gbyk_v4b_B.RateTransition11,        /* 201: Signal */
  &gbyk_v4b_B.RateTransition12,        /* 202: Signal */
  &gbyk_v4b_B.RateTransition2_e,       /* 203: Signal */
  &gbyk_v4b_B.RateTransition3,         /* 204: Signal */
  &gbyk_v4b_B.RateTransition4,         /* 205: Signal */
  &gbyk_v4b_B.RateTransition5,         /* 206: Signal */
  &gbyk_v4b_B.RateTransition6,         /* 207: Signal */
  &gbyk_v4b_B.RateTransition7,         /* 208: Signal */
  &gbyk_v4b_B.RateTransition8,         /* 209: Signal */
  &gbyk_v4b_B.RateTransition9[0],      /* 210: Signal */
  (void *) &gbyk_v4b_ConstB.Width,     /* 211: Signal */
  &gbyk_v4b_B.Pack_g[0],               /* 212: Signal */
  &gbyk_v4b_B.resetUDP,                /* 213: Signal */
  &gbyk_v4b_B.data_out[0],             /* 214: Signal */
  &gbyk_v4b_B.queue_size_e,            /* 215: Signal */
  &gbyk_v4b_B.total_timeouts,          /* 216: Signal */
  &gbyk_v4b_B.strobe_out,              /* 217: Signal */
  &gbyk_v4b_B.max_packet_id,           /* 218: Signal */
  &gbyk_v4b_B.DataTypeConversion2_k,   /* 219: Signal */
  &gbyk_v4b_B.queue_size,              /* 220: Signal */
  &gbyk_v4b_B.timeouts,                /* 221: Signal */
  &gbyk_v4b_B.TaskClock_a,             /* 222: Signal */
  &gbyk_v4b_B.Convert1_c[0],           /* 223: Signal */
  &gbyk_v4b_B.Convert19_e[0],          /* 224: Signal */
  &gbyk_v4b_B.RateTransition_g,        /* 225: Signal */
  &gbyk_v4b_B.RateTransition1_h3,      /* 226: Signal */
  &gbyk_v4b_B.systemtype,              /* 227: Signal */
  &gbyk_v4b_B.ReadHasFT[0],            /* 228: Signal */
  &gbyk_v4b_B.timestamp_out,           /* 229: Signal */
  &gbyk_v4b_B.start_time_out,          /* 230: Signal */
  &gbyk_v4b_B.gazeXYCalculated[0],     /* 231: Signal */
  &gbyk_v4b_B.pupil_area_GLOBAL,       /* 232: Signal */
  &gbyk_v4b_B.gaze_unit_vector_GLOBAL[0],/* 233: Signal */
  &gbyk_v4b_B.pupil_GLOBAL[0],         /* 234: Signal */
  &gbyk_v4b_B.pack_out[0],             /* 235: Signal */
  &gbyk_v4b_B.len_out,                 /* 236: Signal */
  &gbyk_v4b_B.event_data_out[0],       /* 237: Signal */
  &gbyk_v4b_B.Convert1_p,              /* 238: Signal */
  &gbyk_v4b_B.Convert19[0],            /* 239: Signal */
  &gbyk_v4b_B.Convert2[0],             /* 240: Signal */
  &gbyk_v4b_B.Convert3,                /* 241: Signal */
  &gbyk_v4b_B.Convert4[0],             /* 242: Signal */
  &gbyk_v4b_B.DataTypeConversion_i,    /* 243: Signal */
  &gbyk_v4b_B.DataTypeConversion1[0],  /* 244: Signal */
  &gbyk_v4b_B.DataTypeConversion3[0],  /* 245: Signal */
  &gbyk_v4b_B.DataTypeConversion4,     /* 246: Signal */
  &gbyk_v4b_B.DataTypeConversion5,     /* 247: Signal */
  &gbyk_v4b_B.convert_bp,              /* 248: Signal */
  &gbyk_v4b_B.Gain_b[0],               /* 249: Signal */
  &gbyk_v4b_B.RateTransition_kg[0],    /* 250: Signal */
  &gbyk_v4b_B.Reshape_i[0],            /* 251: Signal */
  &gbyk_v4b_B.SelectorLeftEye[0],      /* 252: Signal */
  &gbyk_v4b_B.Receive_o1_i[0],         /* 253: Signal */
  &gbyk_v4b_B.Receive_o2_j,            /* 254: Signal */
  &gbyk_v4b_B.SFunction_o1_n,          /* 255: Signal */
  &gbyk_v4b_B.SAMPE_TYPE,              /* 256: Signal */
  &gbyk_v4b_B.ContentFlags,            /* 257: Signal */
  &gbyk_v4b_B.pupilX[0],               /* 258: Signal */
  &gbyk_v4b_B.pupilY[0],               /* 259: Signal */
  &gbyk_v4b_B.HREFX[0],                /* 260: Signal */
  &gbyk_v4b_B.HREFY[0],                /* 261: Signal */
  &gbyk_v4b_B.pupilarea[0],            /* 262: Signal */
  &gbyk_v4b_B.screengazeX[0],          /* 263: Signal */
  &gbyk_v4b_B.screengazeY[0],          /* 264: Signal */
  &gbyk_v4b_B.resolutionX,             /* 265: Signal */
  &gbyk_v4b_B.resolutionY,             /* 266: Signal */
  &gbyk_v4b_B.statusflags,             /* 267: Signal */
  &gbyk_v4b_B.extrainput,              /* 268: Signal */
  &gbyk_v4b_B.buttons,                 /* 269: Signal */
  &gbyk_v4b_B.htype,                   /* 270: Signal */
  &gbyk_v4b_B.hdata[0],                /* 271: Signal */
  &gbyk_v4b_B.SFunction_o18[0],        /* 272: Signal */
  &gbyk_v4b_B.deltas[0],               /* 273: Signal */
  &gbyk_v4b_B.robot_count,             /* 274: Signal */
  &gbyk_v4b_B.has_force_plate_1,       /* 275: Signal */
  &gbyk_v4b_B.has_force_plate_2,       /* 276: Signal */
  &gbyk_v4b_B.has_gaze_tracker,        /* 277: Signal */
  &gbyk_v4b_B.has_robot_lift,          /* 278: Signal */
  &gbyk_v4b_B.sf_EmbeddedMATLABFunction_b.VCODE[0],/* 279: Signal */
  &gbyk_v4b_B.MatrixConcatenation1_na[0],/* 280: Signal */
  &gbyk_v4b_B.MatrixConcatenation1_na[0],/* 281: Signal */
  &gbyk_v4b_B.MatrixConcatenation1_na[0],/* 282: Signal */
  &gbyk_v4b_B.Selector_j[0],           /* 283: Signal */
  &gbyk_v4b_B.VCODE[0],                /* 284: Signal */
  &gbyk_v4b_B.MatrixConcatenation1_a[0],/* 285: Signal */
  &gbyk_v4b_B.MatrixConcatenation1_a[0],/* 286: Signal */
  &gbyk_v4b_B.MatrixConcatenation1_a[0],/* 287: Signal */
  &gbyk_v4b_B.Selector_g[0],           /* 288: Signal */
  &gbyk_v4b_B.target_vector[0],        /* 289: Signal */
  &gbyk_v4b_B.target_vector_length,    /* 290: Signal */
  &gbyk_v4b_B.Concatenation1[0],       /* 291: Signal */
  &gbyk_v4b_B.Concatenation1[0],       /* 292: Signal */
  &gbyk_v4b_B.Concatenation1[0],       /* 293: Signal */
  &gbyk_v4b_B.Concatenation1[0],       /* 294: Signal */
  &gbyk_v4b_B.Concatenation1[0],       /* 295: Signal */
  &gbyk_v4b_B.y,                       /* 296: Signal */
  &gbyk_v4b_B.z,                       /* 297: Signal */
  &gbyk_v4b_B.value,                   /* 298: Signal */
  &gbyk_v4b_B.DataTypeConversion,      /* 299: Signal */
  &gbyk_v4b_B.DataTypeConversion1_gw,  /* 300: Signal */
  &gbyk_v4b_B.DataTypeConversion2,     /* 301: Signal */
  &gbyk_v4b_B.RunCommandReceive_o1,    /* 302: Signal */
  &gbyk_v4b_B.RunCommandReceive_o2,    /* 303: Signal */
  &gbyk_v4b_B.task_status,             /* 304: Signal */
  &gbyk_v4b_B.tp,                      /* 305: Signal */
  &gbyk_v4b_B.block,                   /* 306: Signal */
  &gbyk_v4b_B.trial_in_block,          /* 307: Signal */
  &gbyk_v4b_B.block_in_set,            /* 308: Signal */
  &gbyk_v4b_B.trial_in_set,            /* 309: Signal */
  &gbyk_v4b_B.repeat_last_trial,       /* 310: Signal */
  &gbyk_v4b_B.extra_trials[0],         /* 311: Signal */
  &gbyk_v4b_B.e_exit_trial,            /* 312: Signal */
  &gbyk_v4b_B.DataTypeConversion_g,    /* 313: Signal */
  &gbyk_v4b_B.DataTypeConversion1_m,   /* 314: Signal */
  &gbyk_v4b_B.DataTypeConversion2_n,   /* 315: Signal */
  &gbyk_v4b_B.TaskClock,               /* 316: Signal */
  &gbyk_v4b_B.Delay,                   /* 317: Signal */
  &gbyk_v4b_B.Delay1,                  /* 318: Signal */
  &gbyk_v4b_B.Product_i,               /* 319: Signal */
  &gbyk_v4b_B.Product2,                /* 320: Signal */
  &gbyk_v4b_B.Product3,                /* 321: Signal */
  &gbyk_v4b_B.Selector_n[0],           /* 322: Signal */
  &gbyk_v4b_B.Selector1[0],            /* 323: Signal */
  &gbyk_v4b_B.Selector2_l[0],          /* 324: Signal */
  &gbyk_v4b_B.Subtract_p,              /* 325: Signal */
  &gbyk_v4b_B.Width_j,                 /* 326: Signal */
  (void *) &gbyk_v4b_ConstB.Width1,    /* 327: Signal */
  &gbyk_v4b_B.Width2,                  /* 328: Signal */
  &gbyk_v4b_B.total_trials,            /* 329: Signal */
  &gbyk_v4b_B.trials_in_block,         /* 330: Signal */
  &gbyk_v4b_B.total_blocks,            /* 331: Signal */
  &gbyk_v4b_B.total_trials_in_exam,    /* 332: Signal */
  &gbyk_v4b_B.total_trials_in_block,   /* 333: Signal */
  &gbyk_v4b_B.total_blocks_in_exam,    /* 334: Signal */
  &gbyk_v4b_B.B1TargetB1rowfloatB1rowintargettablenone,/* 335: Signal */
  &gbyk_v4b_B.B2TargetB2rowfloatB2rowintargettablenone,/* 336: Signal */
  &gbyk_v4b_B.CORR_TGTWhichtargetiscorrectfloatWhichtargetiscorrect1or2none,/* 337: Signal */
  &gbyk_v4b_B.DELAY_POST_TRIALTrialEndDelayintegerTimetowaitattheendofthetria,/* 338: Signal */
  &gbyk_v4b_B.DISPLAY_TRIAL_COLFlagDisplayintegerDisplayandpausenone,/* 339: Signal */
  &gbyk_v4b_B.INCORR_TGTWhichtargetisincorrectfloatWhichtargetisincorrect1or2,/* 340: Signal */
  &gbyk_v4b_B.MAX_REACH_TIME_COLMaximumReachTimeintegerMaximumreachdurational,/* 341: Signal */
  &gbyk_v4b_B.RWD_TARGETC1_COLTarget1ValuefloatRewardofferedonTargetC1none,/* 342: Signal */
  &gbyk_v4b_B.RWD_TARGETC2_COLTarget2ValuefloatRewardofferedonTargetC2none,/* 343: Signal */
  &gbyk_v4b_B.START_TARGET_COLStarttargettargetFirsttargettoappearduringatria,/* 344: Signal */
  &gbyk_v4b_B.TGT_C_RWD_FRACRewardratiobetweenrowCrowBfloatHowmuchmorewilltar,/* 345: Signal */
  &gbyk_v4b_B.INSTRUCT_PAUSE_BTNInstructionResumeButtontocontinuetaskafterdis,/* 346: Signal */
  &gbyk_v4b_B.E_BOX_TRIGGERBoxWasTriggeredBoxtriggreredsosubjectchoserowCnone,/* 347: Signal */
  &gbyk_v4b_B.E_CHOSE_ROW_BChoseRowBSubjectchoserowBnone,/* 348: Signal */
  &gbyk_v4b_B.E_HIT_TARGETBHitTargetBHittargetBnone,/* 349: Signal */
  &gbyk_v4b_B.E_HIT_TARGETCHitTargetCHitTargetCnone,/* 350: Signal */
  &gbyk_v4b_B.E_MISS_TARGETBMissTargretBMissTargretBnone,/* 351: Signal */
  &gbyk_v4b_B.E_MISS_TARGETCMissTargetCMissTargetCnone,/* 352: Signal */
  &gbyk_v4b_B.E_NEW_TRIALNewTrialStartNewTrialstartsnone,/* 353: Signal */
  &gbyk_v4b_B.E_NO_EVENTnaThisevent_codedoesnotsaveaneventinthedatafileitjust,/* 354: Signal */
  &gbyk_v4b_B.E_SHOW_INSTRUCTInstructionstateShowinginstructionsnone,/* 355: Signal */
  &gbyk_v4b_B.E_SHOW_SCOREShowScoreShowingscorenone,/* 356: Signal */
  &gbyk_v4b_B.E_STAY_STARTAtStartSubjectreachedstarttargetnone,/* 357: Signal */
  &gbyk_v4b_B.E_TARGETS_ONTargetsOnPotentialReachtargetsonnone,/* 358: Signal */
  &gbyk_v4b_B.E_TOO_SLOWTooSlowMovementistooslowerror,/* 359: Signal */
  &gbyk_v4b_B.BOX_HEIGHTHeightofBoxfloatHeightofBoxnone,/* 360: Signal */
  &gbyk_v4b_B.HIT_COLORReachedcolorcolourColorwhenthetargetistouchednone,/* 361: Signal */
  &gbyk_v4b_B.INIT_COLORInitialcolorcolourInitialtargetcolornone,/* 362: Signal */
  &gbyk_v4b_B.LABELLabelTextlabelInitialtextforthelabelnone,/* 363: Signal */
  &gbyk_v4b_B.LABELONLY_XLabelOnlyXfloatXpositioncmofthetargetrelativetolocal,/* 364: Signal */
  &gbyk_v4b_B.LABELONLY_YLabelOnlyYfloatYpositioncmofthetargetrelativetolocal,/* 365: Signal */
  &gbyk_v4b_B.LABEL_HEIGHTLabelHeightfloatLabelHeightcmnone,/* 366: Signal */
  &gbyk_v4b_B.LOGICAL_RADIUSLogicalradiusfloatRadiusofthetargetusedforhandint,/* 367: Signal */
  &gbyk_v4b_B.ROTATIONRotationofatargetfloatRotationoftargetnone,/* 368: Signal */
  &gbyk_v4b_B.STROKE_WIDTHStrokeWidthfloatStrokewidthnone,/* 369: Signal */
  &gbyk_v4b_B.TEXT_COLORTextColorcolourTextColornone,/* 370: Signal */
  &gbyk_v4b_B.VISUAL_RADIUSVisualradiusfloatVisualradiusofthetargetcmorsizeof,/* 371: Signal */
  &gbyk_v4b_B.col_xXfloatXPositioncmofthetargetrelativetolocal00none,/* 372: Signal */
  &gbyk_v4b_B.col_yYfloatYPositioncmofthetargetrelativetolocal00none,/* 373: Signal */
  &gbyk_v4b_B.INSTRUCTIONS,            /* 374: Signal */
  &gbyk_v4b_B.LOAD_FOREITHER,          /* 375: Signal */
  &gbyk_v4b_B.K_DELAY_FIXEDDelay_MinintegerMinimumholddelaytimeatstarttargetf,/* 376: Signal */
  &gbyk_v4b_B.K_DELAY_RANDDelay_RandintegerMaximumadditionaldelaytimeatstartt,/* 377: Signal */
  &gbyk_v4b_B.K_PRE_REWARD_DELAYDelay_PreRewardCueintegerTimetocuetherewardin,/* 378: Signal */
  &gbyk_v4b_B.K_REWARD_VALReward_ValueintegerOneunitofrewardnone,/* 379: Signal */
  &gbyk_v4b_B.K_SCORETEXT_ROWFeedback_Text_TgtTable_RowintegerTargetnumbertob,/* 380: Signal */
  &gbyk_v4b_B.K_THRESH_VELMAXVel_Min_ThreshfloatMinimumvelocitythatmustbeexce,/* 381: Signal */
  &gbyk_v4b_B.K_TRIGGER_POSTrigger_PosfloatPositionThresholdfortriggeringtarg,/* 382: Signal */
  &gbyk_v4b_B.K_TRIGGER_VELTrigger_VelfloatVelocityThresholdfortriggeringtarg,/* 383: Signal */
  &gbyk_v4b_B.delay,                   /* 384: Signal */
  &gbyk_v4b_B.RateTransition1_l,       /* 385: Signal */
  &gbyk_v4b_B.RateTransition2_d,       /* 386: Signal */
  &gbyk_v4b_B.SFunctionBuilder_o1[0],  /* 387: Signal */
  &gbyk_v4b_B.SFunctionBuilder_o2,     /* 388: Signal */
  &gbyk_v4b_B.SFunctionBuilder_o3[0],  /* 389: Signal */
  &gbyk_v4b_B.vis_cmd[0],              /* 390: Signal */
  &gbyk_v4b_B.vis_cmd_len,             /* 391: Signal */
  &gbyk_v4b_B.vis_cmd_cropped,         /* 392: Signal */
  &gbyk_v4b_B.frame_number,            /* 393: Signal */
  &gbyk_v4b_B.vcode_err_id,            /* 394: Signal */
  &gbyk_v4b_B.Convert_n,               /* 395: Signal */
  &gbyk_v4b_B.RateTransition1_h,       /* 396: Signal */
  &gbyk_v4b_B.dd_out[0],               /* 397: Signal */
  &gbyk_v4b_B.Output,                  /* 398: Signal */
  &gbyk_v4b_B.Compare,                 /* 399: Signal */
  &gbyk_v4b_B.DataTypeConversion_p1[0],/* 400: Signal */
  &gbyk_v4b_B.IdealFramesPerPacket,    /* 401: Signal */
  &gbyk_v4b_B.MathFunction_j,          /* 402: Signal */
  &gbyk_v4b_B.t1[0],                   /* 403: Signal */
  &gbyk_v4b_B.t2[0],                   /* 404: Signal */
  &gbyk_v4b_B.MinMax_k,                /* 405: Signal */
  &gbyk_v4b_B.Product_l,               /* 406: Signal */
  &gbyk_v4b_B.RelationalOperator,      /* 407: Signal */
  &gbyk_v4b_B.Selector_e[0],           /* 408: Signal */
  &gbyk_v4b_B.Subtract_o,              /* 409: Signal */
  &gbyk_v4b_B.Width,                   /* 410: Signal */
  &gbyk_v4b_B.DataTypeConversion_cb,   /* 411: Signal */
  &gbyk_v4b_B.trigger,                 /* 412: Signal */
  &gbyk_v4b_B.RqstUDPReset,            /* 413: Signal */
  &gbyk_v4b_B.RateTransition2_js[0],   /* 414: Signal */
  &gbyk_v4b_B.Data[0],                 /* 415: Signal */
  &gbyk_v4b_B.Pckt_Recd,               /* 416: Signal */
  &gbyk_v4b_B.Data2[0],                /* 417: Signal */
  &gbyk_v4b_B.Pckt_Recd2,              /* 418: Signal */
  &gbyk_v4b_B.doublereads,             /* 419: Signal */
  &gbyk_v4b_B.UDPReceive_o6,           /* 420: Signal */
  &gbyk_v4b_B.UDPResets,               /* 421: Signal */
  &gbyk_v4b_B.UDPReceivePortReset_o2[0],/* 422: Signal */
  &gbyk_v4b_B.Unpack,                  /* 423: Signal */
  &gbyk_v4b_B.Pack_i[0],               /* 424: Signal */
  &gbyk_v4b_B.forces_g[0],             /* 425: Signal */
  &gbyk_v4b_B.moments_p[0],            /* 426: Signal */
  &gbyk_v4b_B.timer_c,                 /* 427: Signal */
  &gbyk_v4b_B.Receive_o1_k[0],         /* 428: Signal */
  &gbyk_v4b_B.Receive_o2_m,            /* 429: Signal */
  &gbyk_v4b_B.forces[0],               /* 430: Signal */
  &gbyk_v4b_B.moments[0],              /* 431: Signal */
  &gbyk_v4b_B.timer,                   /* 432: Signal */
  &gbyk_v4b_B.Receive1_o1[0],          /* 433: Signal */
  &gbyk_v4b_B.Receive1_o2,             /* 434: Signal */
  &gbyk_v4b_B.errVals[0],              /* 435: Signal */
  &gbyk_v4b_B.DCErrVals[0],            /* 436: Signal */
  &gbyk_v4b_B.intAddresses[0],         /* 437: Signal */
  &gbyk_v4b_B.floatAddresses[0],       /* 438: Signal */
  &gbyk_v4b_B.motorEnableState,        /* 439: Signal */
  &gbyk_v4b_B.DataTypeConversion_h,    /* 440: Signal */
  &gbyk_v4b_B.convert[0],              /* 441: Signal */
  &gbyk_v4b_B.BKINEtherCATinit_o1[0],  /* 442: Signal */
  &gbyk_v4b_B.BKINEtherCATinit_o2,     /* 443: Signal */
  &gbyk_v4b_B.BKINEtherCATinit_o3,     /* 444: Signal */
  &gbyk_v4b_B.BKINEtherCATinit1_o1[0], /* 445: Signal */
  &gbyk_v4b_B.BKINEtherCATinit1_o2,    /* 446: Signal */
  &gbyk_v4b_B.BKINEtherCATinit1_o3,    /* 447: Signal */
  &gbyk_v4b_B.Switch_m[0],             /* 448: Signal */
  &gbyk_v4b_B.kinarm_data[0],          /* 449: Signal */
  &gbyk_v4b_B.primary_encoder_data_out[0],/* 450: Signal */
  &gbyk_v4b_B.statusInts[0],           /* 451: Signal */
  &gbyk_v4b_B.newMessage[0],           /* 452: Signal */
  &gbyk_v4b_B.sentMessageCount,        /* 453: Signal */
  &gbyk_v4b_B.DataStoreRead_l,         /* 454: Signal */
  &gbyk_v4b_B.DelayRead[0],            /* 455: Signal */
  &gbyk_v4b_B.ErrMsgs[0],              /* 456: Signal */
  &gbyk_v4b_B.Primaryread[0],          /* 457: Signal */
  &gbyk_v4b_B.Read[0],                 /* 458: Signal */
  &gbyk_v4b_B.ReadHW[0],               /* 459: Signal */
  &gbyk_v4b_B.ReadKinematics[0],       /* 460: Signal */
  &gbyk_v4b_B.ServoRead,               /* 461: Signal */
  &gbyk_v4b_B.Statusread[0],           /* 462: Signal */
  &gbyk_v4b_B.Statusread1_e[0],        /* 463: Signal */
  &gbyk_v4b_B.torquefeedback1[0],      /* 464: Signal */
  &gbyk_v4b_B.DataTypeConversion_nq[0],/* 465: Signal */
  &gbyk_v4b_B.Compare_n,               /* 466: Signal */
  &gbyk_v4b_B.Compare_c,               /* 467: Signal */
  &gbyk_v4b_B.link_lengths_o[0],       /* 468: Signal */
  &gbyk_v4b_B.pointer_offset_k,        /* 469: Signal */
  &gbyk_v4b_B.shoulder_loc_o[0],       /* 470: Signal */
  &gbyk_v4b_B.arm_orientation_o,       /* 471: Signal */
  &gbyk_v4b_B.shoulder_ang_h,          /* 472: Signal */
  &gbyk_v4b_B.elbow_ang_k,             /* 473: Signal */
  &gbyk_v4b_B.shoulder_velocity_k,     /* 474: Signal */
  &gbyk_v4b_B.elbow_velocity_j,        /* 475: Signal */
  &gbyk_v4b_B.shoulder_acceleration_c, /* 476: Signal */
  &gbyk_v4b_B.elbow_acceleration_j,    /* 477: Signal */
  &gbyk_v4b_B.joint_torque_cmd_k[0],   /* 478: Signal */
  &gbyk_v4b_B.motor_torque_cmd_b[0],   /* 479: Signal */
  &gbyk_v4b_B.link_angle_b[0],         /* 480: Signal */
  &gbyk_v4b_B.link_velocity_k[0],      /* 481: Signal */
  &gbyk_v4b_B.link_acceleration_c[0],  /* 482: Signal */
  &gbyk_v4b_B.hand_position_g[0],      /* 483: Signal */
  &gbyk_v4b_B.hand_velocity_p[0],      /* 484: Signal */
  &gbyk_v4b_B.hand_acceleration_e[0],  /* 485: Signal */
  &gbyk_v4b_B.motor_status_c,          /* 486: Signal */
  &gbyk_v4b_B.force_sensor_force_uvw_g[0],/* 487: Signal */
  &gbyk_v4b_B.force_sensor_torque_uvw_d[0],/* 488: Signal */
  &gbyk_v4b_B.force_sensor_force_xyz_g[0],/* 489: Signal */
  &gbyk_v4b_B.force_sensor_torque_xyz_g[0],/* 490: Signal */
  &gbyk_v4b_B.force_sensor_timestamp_k,/* 491: Signal */
  &gbyk_v4b_B.link_lengths[0],         /* 492: Signal */
  &gbyk_v4b_B.pointer_offset,          /* 493: Signal */
  &gbyk_v4b_B.shoulder_loc[0],         /* 494: Signal */
  &gbyk_v4b_B.arm_orientation,         /* 495: Signal */
  &gbyk_v4b_B.shoulder_ang,            /* 496: Signal */
  &gbyk_v4b_B.elbow_ang,               /* 497: Signal */
  &gbyk_v4b_B.shoulder_velocity,       /* 498: Signal */
  &gbyk_v4b_B.elbow_velocity,          /* 499: Signal */
  &gbyk_v4b_B.shoulder_acceleration,   /* 500: Signal */
  &gbyk_v4b_B.elbow_acceleration,      /* 501: Signal */
  &gbyk_v4b_B.joint_torque_cmd[0],     /* 502: Signal */
  &gbyk_v4b_B.motor_torque_cmd[0],     /* 503: Signal */
  &gbyk_v4b_B.link_angle[0],           /* 504: Signal */
  &gbyk_v4b_B.link_velocity[0],        /* 505: Signal */
  &gbyk_v4b_B.link_acceleration[0],    /* 506: Signal */
  &gbyk_v4b_B.hand_position[0],        /* 507: Signal */
  &gbyk_v4b_B.hand_velocity[0],        /* 508: Signal */
  &gbyk_v4b_B.hand_acceleration[0],    /* 509: Signal */
  &gbyk_v4b_B.motor_status,            /* 510: Signal */
  &gbyk_v4b_B.force_sensor_force_uvw[0],/* 511: Signal */
  &gbyk_v4b_B.force_sensor_torque_uvw[0],/* 512: Signal */
  &gbyk_v4b_B.force_sensor_force_xyz[0],/* 513: Signal */
  &gbyk_v4b_B.force_sensor_torque_xyz[0],/* 514: Signal */
  &gbyk_v4b_B.force_sensor_timestamp,  /* 515: Signal */
  &gbyk_v4b_B.active_arm,              /* 516: Signal */
  &gbyk_v4b_B.delayEstimates[0],       /* 517: Signal */
  &gbyk_v4b_B.servoCounter,            /* 518: Signal */
  &gbyk_v4b_B.calibrationButtonBits,   /* 519: Signal */
  &gbyk_v4b_B.handFF,                  /* 520: Signal */
  &gbyk_v4b_B.handFF_Dex,              /* 521: Signal */
  &gbyk_v4b_B.handFBArm,               /* 522: Signal */
  &gbyk_v4b_B.handFBRadius,            /* 523: Signal */
  &gbyk_v4b_B.handFBControl,           /* 524: Signal */
  &gbyk_v4b_B.handFBColor,             /* 525: Signal */
  &gbyk_v4b_B.hasGaze,                 /* 526: Signal */
  &gbyk_v4b_B.gazeFB,                  /* 527: Signal */
  &gbyk_v4b_B.gazeLocation[0],         /* 528: Signal */
  &gbyk_v4b_B.gazeTimestamp,           /* 529: Signal */
  &gbyk_v4b_B.gazePupilArea,           /* 530: Signal */
  &gbyk_v4b_B.gazeEvent[0],            /* 531: Signal */
  &gbyk_v4b_B.gazeVector[0],           /* 532: Signal */
  &gbyk_v4b_B.gazePupilLoc[0],         /* 533: Signal */
  &gbyk_v4b_B.Selector_c[0],           /* 534: Signal */
  &gbyk_v4b_B.Selector1_m[0],          /* 535: Signal */
  &gbyk_v4b_B.Selector2_o[0],          /* 536: Signal */
  &gbyk_v4b_B.sf_split_primary.link_angles[0],/* 537: Signal */
  &gbyk_v4b_B.sf_split_primary.link_velocities[0],/* 538: Signal */
  &gbyk_v4b_B.sf_split_primary.link_acceleration[0],/* 539: Signal */
  &gbyk_v4b_B.sf_split_primary1.link_angles[0],/* 540: Signal */
  &gbyk_v4b_B.sf_split_primary1.link_velocities[0],/* 541: Signal */
  &gbyk_v4b_B.sf_split_primary1.link_acceleration[0],/* 542: Signal */
  &gbyk_v4b_B.Selector1_a[0],          /* 543: Signal */
  &gbyk_v4b_B.Selector2_i[0],          /* 544: Signal */
  &gbyk_v4b_B.ecatTorques[0],          /* 545: Signal */
  &gbyk_v4b_B.DataStoreRead[0],        /* 546: Signal */
  &gbyk_v4b_B.DataTypeConversion_a[0], /* 547: Signal */
  &gbyk_v4b_B.DataTypeConversion1_cq[0],/* 548: Signal */
  &gbyk_v4b_B.DataTypeConversion6[0],  /* 549: Signal */
  &gbyk_v4b_B.Product_m[0],            /* 550: Signal */
  &gbyk_v4b_B.Compare_b,               /* 551: Signal */
  &gbyk_v4b_B.Compare_l,               /* 552: Signal */
  &gbyk_v4b_B.sf_MATLABFunction_o.is_right_arm,/* 553: Signal */
  &gbyk_v4b_B.sf_MATLABFunction_o.isExo,/* 554: Signal */
  &gbyk_v4b_B.sf_MATLABFunction_o.has_high_res_encoders,/* 555: Signal */
  &gbyk_v4b_B.sf_MATLABFunction1.is_right_arm,/* 556: Signal */
  &gbyk_v4b_B.sf_MATLABFunction1.isExo,/* 557: Signal */
  &gbyk_v4b_B.sf_MATLABFunction1.has_high_res_encoders,/* 558: Signal */
  &gbyk_v4b_B.Compare_o,               /* 559: Signal */
  &gbyk_v4b_B.FixPtSum1,               /* 560: Signal */
  &gbyk_v4b_B.FixPtSwitch,             /* 561: Signal */
  &gbyk_v4b_B.Sum,                     /* 562: Signal */
  &gbyk_v4b_B.UnitDelay_h,             /* 563: Signal */
  &gbyk_v4b_B.Output_n,                /* 564: Signal */
  &gbyk_v4b_B.sf_FindRobottype.robotType,/* 565: Signal */
  &gbyk_v4b_B.sf_SDOreadmachine.SDOCommand[0],/* 566: Signal */
  &gbyk_v4b_B.sf_SDOreadmachine.intSDOValues[0],/* 567: Signal */
  &gbyk_v4b_B.sf_SDOreadmachine.floatSDOValues[0],/* 568: Signal */
  &gbyk_v4b_B.sf_SDOreadmachine.complete,/* 569: Signal */
  &gbyk_v4b_B.sf_forceEnableDisable.forceMotorState,/* 570: Signal */
  &gbyk_v4b_B.sf_size.count,           /* 571: Signal */
  &gbyk_v4b_B.sf_size1.count,          /* 572: Signal */
  &gbyk_v4b_B.encoderCounts_h[0],      /* 573: Signal */
  &gbyk_v4b_B.FTSensorOffset_j,        /* 574: Signal */
  &gbyk_v4b_B.calibPinAngles_m[0],     /* 575: Signal */
  &gbyk_v4b_B.absAngOffsets_c[0],      /* 576: Signal */
  &gbyk_v4b_B.linkLengths_j[0],        /* 577: Signal */
  &gbyk_v4b_B.L2CalibPinOffset_c,      /* 578: Signal */
  &gbyk_v4b_B.continuousTorques_j[0],  /* 579: Signal */
  &gbyk_v4b_B.gearRatios_p[0],         /* 580: Signal */
  &gbyk_v4b_B.isCalibrated_p,          /* 581: Signal */
  &gbyk_v4b_B.offsetRads_f[0],         /* 582: Signal */
  &gbyk_v4b_B.offsetRadsPrimary_h[0],  /* 583: Signal */
  &gbyk_v4b_B.robotRevision_n,         /* 584: Signal */
  &gbyk_v4b_B.constantsReady_j,        /* 585: Signal */
  &gbyk_v4b_B.sf_splitoutconstants1.hasSecondary,/* 586: Signal */
  &gbyk_v4b_B.sf_splitoutconstants1.hasFT,/* 587: Signal */
  &gbyk_v4b_B.sf_splitoutconstants1.robotOrientation,/* 588: Signal */
  &gbyk_v4b_B.sf_splitoutconstants1.motorOrientation[0],/* 589: Signal */
  &gbyk_v4b_B.sf_splitoutconstants1.encOrientation[0],/* 590: Signal */
  &gbyk_v4b_B.TorqueMode_i,            /* 591: Signal */
  &gbyk_v4b_B.readTrigger_k,           /* 592: Signal */
  &gbyk_v4b_B.R1_maxContinuousTorque[0],/* 593: Signal */
  &gbyk_v4b_B.R1_constantsReady,       /* 594: Signal */
  &gbyk_v4b_B.sf_FindRobottype_d.robotType,/* 595: Signal */
  &gbyk_v4b_B.sf_SDOreadmachine_h.SDOCommand[0],/* 596: Signal */
  &gbyk_v4b_B.sf_SDOreadmachine_h.intSDOValues[0],/* 597: Signal */
  &gbyk_v4b_B.sf_SDOreadmachine_h.floatSDOValues[0],/* 598: Signal */
  &gbyk_v4b_B.sf_SDOreadmachine_h.complete,/* 599: Signal */
  &gbyk_v4b_B.sf_forceEnableDisable_k.forceMotorState,/* 600: Signal */
  &gbyk_v4b_B.sf_size_d.count,         /* 601: Signal */
  &gbyk_v4b_B.sf_size1_e.count,        /* 602: Signal */
  &gbyk_v4b_B.encoderCounts[0],        /* 603: Signal */
  &gbyk_v4b_B.FTSensorOffset,          /* 604: Signal */
  &gbyk_v4b_B.calibPinAngles[0],       /* 605: Signal */
  &gbyk_v4b_B.absAngOffsets[0],        /* 606: Signal */
  &gbyk_v4b_B.linkLengths[0],          /* 607: Signal */
  &gbyk_v4b_B.L2CalibPinOffset,        /* 608: Signal */
  &gbyk_v4b_B.continuousTorques[0],    /* 609: Signal */
  &gbyk_v4b_B.gearRatios[0],           /* 610: Signal */
  &gbyk_v4b_B.isCalibrated,            /* 611: Signal */
  &gbyk_v4b_B.offsetRads[0],           /* 612: Signal */
  &gbyk_v4b_B.offsetRadsPrimary[0],    /* 613: Signal */
  &gbyk_v4b_B.robotRevision_o,         /* 614: Signal */
  &gbyk_v4b_B.constantsReady,          /* 615: Signal */
  &gbyk_v4b_B.sf_splitoutconstants1_o.hasSecondary,/* 616: Signal */
  &gbyk_v4b_B.sf_splitoutconstants1_o.hasFT,/* 617: Signal */
  &gbyk_v4b_B.sf_splitoutconstants1_o.robotOrientation,/* 618: Signal */
  &gbyk_v4b_B.sf_splitoutconstants1_o.motorOrientation[0],/* 619: Signal */
  &gbyk_v4b_B.sf_splitoutconstants1_o.encOrientation[0],/* 620: Signal */
  &gbyk_v4b_B.TorqueMode,              /* 621: Signal */
  &gbyk_v4b_B.readTrigger,             /* 622: Signal */
  &gbyk_v4b_B.R2_maxContinuousTorque[0],/* 623: Signal */
  &gbyk_v4b_B.R2_constantsReady,       /* 624: Signal */
  &gbyk_v4b_B.Compare_i,               /* 625: Signal */
  &gbyk_v4b_B.Output_a,                /* 626: Signal */
  &gbyk_v4b_B.drive1,                  /* 627: Signal */
  &gbyk_v4b_B.drive2,                  /* 628: Signal */
  &gbyk_v4b_B.drive3,                  /* 629: Signal */
  &gbyk_v4b_B.drive4,                  /* 630: Signal */
  &gbyk_v4b_B.errVal,                  /* 631: Signal */
  &gbyk_v4b_B.masterState,             /* 632: Signal */
  &gbyk_v4b_B.DCErrVal,                /* 633: Signal */
  &gbyk_v4b_B.MasterToNetworkClkDiff,  /* 634: Signal */
  &gbyk_v4b_B.DCInitState,             /* 635: Signal */
  &gbyk_v4b_B.NetworkToSlaveClkDiff,   /* 636: Signal */
  &gbyk_v4b_B.bitField,                /* 637: Signal */
  &gbyk_v4b_B.kinematicsOut[0],        /* 638: Signal */
  &gbyk_v4b_B.kinematicsOutPrimary[0], /* 639: Signal */
  &gbyk_v4b_B.delays[0],               /* 640: Signal */
  &gbyk_v4b_B.servoCounterOut,         /* 641: Signal */
  &gbyk_v4b_B.outMem[0],               /* 642: Signal */
  &gbyk_v4b_B.settingsOut[0],          /* 643: Signal */
  &gbyk_v4b_B.calibrationsOut[0],      /* 644: Signal */
  &gbyk_v4b_B.DataStore[0],            /* 645: Signal */
  &gbyk_v4b_B.DataStore1[0],           /* 646: Signal */
  &gbyk_v4b_B.DataTypeConversion_jq[0],/* 647: Signal */
  &gbyk_v4b_B.DataTypeConversion1_ju[0],/* 648: Signal */
  &gbyk_v4b_B.DataTypeConversion2_ir,  /* 649: Signal */
  &gbyk_v4b_B.DataTypeConversion3_l[0],/* 650: Signal */
  &gbyk_v4b_B.DataTypeConversion4_j[0],/* 651: Signal */
  &gbyk_v4b_B.sf_Createtimestamp.timestamp_out,/* 652: Signal */
  &gbyk_v4b_B.DataTypeConversion_e[0], /* 653: Signal */
  &gbyk_v4b_B.ByteReversal[0],         /* 654: Signal */
  &gbyk_v4b_B.ByteReversal1[0],        /* 655: Signal */
  &gbyk_v4b_B.ReceivefromRobot1ForceSensor_o1[0],/* 656: Signal */
  &gbyk_v4b_B.ReceivefromRobot1ForceSensor_o2,/* 657: Signal */
  &gbyk_v4b_B.Unpack_o1_m[0],          /* 658: Signal */
  &gbyk_v4b_B.Unpack_o2_o[0],          /* 659: Signal */
  &gbyk_v4b_B.Switch_p[0],             /* 660: Signal */
  &gbyk_v4b_B.sf_Createtimestamp_b.timestamp_out,/* 661: Signal */
  &gbyk_v4b_B.DataTypeConversion1_g[0],/* 662: Signal */
  &gbyk_v4b_B.ByteReversal_o[0],       /* 663: Signal */
  &gbyk_v4b_B.ByteReversal1_f[0],      /* 664: Signal */
  &gbyk_v4b_B.ReceivefromRobot2ForceSensor_o1[0],/* 665: Signal */
  &gbyk_v4b_B.ReceivefromRobot2ForceSensor_o2,/* 666: Signal */
  &gbyk_v4b_B.Unpack1_o1[0],           /* 667: Signal */
  &gbyk_v4b_B.Unpack1_o2[0],           /* 668: Signal */
  &gbyk_v4b_B.Switch1_b[0],            /* 669: Signal */
  &gbyk_v4b_B.force_scale,             /* 670: Signal */
  &gbyk_v4b_B.robot1DataOut_p[0],      /* 671: Signal */
  &gbyk_v4b_B.robot2DataOut_g[0],      /* 672: Signal */
  &gbyk_v4b_B.robot1PrimaryEncDataOut[0],/* 673: Signal */
  &gbyk_v4b_B.robot2PrimaryEncDataOut[0],/* 674: Signal */
  &gbyk_v4b_B.robot1DataOut[0],        /* 675: Signal */
  &gbyk_v4b_B.robot2DataOut[0],        /* 676: Signal */
  &gbyk_v4b_B.Conversion1[0],          /* 677: Signal */
  &gbyk_v4b_B.Conversion2[0],          /* 678: Signal */
  &gbyk_v4b_B.Conversion7[0],          /* 679: Signal */
  &gbyk_v4b_B.Convert2_n[0],           /* 680: Signal */
  &gbyk_v4b_B.DataTypeConversion_a5[0],/* 681: Signal */
  &gbyk_v4b_B.DataTypeConversion1_i1[0],/* 682: Signal */
  &gbyk_v4b_B.DataTypeConversion2_h,   /* 683: Signal */
  &gbyk_v4b_B.DataTypeConversion3_d[0],/* 684: Signal */
  &gbyk_v4b_B.DataTypeConversion4_g[0],/* 685: Signal */
  &gbyk_v4b_B.MinMax_b,                /* 686: Signal */
  &gbyk_v4b_B.MinMax1,                 /* 687: Signal */
  &gbyk_v4b_B.SFunction_o1[0],         /* 688: Signal */
  &gbyk_v4b_B.SFunction_o2[0],         /* 689: Signal */
  &gbyk_v4b_B.SFunction_o3[0],         /* 690: Signal */
  &gbyk_v4b_B.SFunction_o4[0],         /* 691: Signal */
  &gbyk_v4b_B.SFunction_o5[0],         /* 692: Signal */
  &gbyk_v4b_B.SFunction_o6[0],         /* 693: Signal */
  &gbyk_v4b_B.SFunction_o7,            /* 694: Signal */
  &gbyk_v4b_B.SFunction_o8,            /* 695: Signal */
  &gbyk_v4b_B.SFunction_o9[0],         /* 696: Signal */
  &gbyk_v4b_B.SFunction_o10,           /* 697: Signal */
  &gbyk_v4b_B.outStatus[0],            /* 698: Signal */
  &gbyk_v4b_B.kinematics[0],           /* 699: Signal */
  &gbyk_v4b_B.primary[0],              /* 700: Signal */
  &gbyk_v4b_B.Constant,                /* 701: Signal */
  &gbyk_v4b_B.Constant1[0],            /* 702: Signal */
  &gbyk_v4b_B.DataTypeConversion_k[0], /* 703: Signal */
  &gbyk_v4b_B.DataTypeConversion1_a[0],/* 704: Signal */
  &gbyk_v4b_B.DataTypeConversion2_i,   /* 705: Signal */
  &gbyk_v4b_B.Receive_o1_n[0],         /* 706: Signal */
  &gbyk_v4b_B.Receive_o2_o,            /* 707: Signal */
  &gbyk_v4b_B.Unpack_o1[0],            /* 708: Signal */
  &gbyk_v4b_B.Unpack_o2[0],            /* 709: Signal */
  &gbyk_v4b_B.Compare_a,               /* 710: Signal */
  &gbyk_v4b_B.sf_decoderobot.isEP,     /* 711: Signal */
  &gbyk_v4b_B.sf_decoderobot.isHumanEXO,/* 712: Signal */
  &gbyk_v4b_B.sf_decoderobot.isNHPEXO, /* 713: Signal */
  &gbyk_v4b_B.sf_decoderobot.isClassicExo,/* 714: Signal */
  &gbyk_v4b_B.sf_decoderobot.isUTSEXO, /* 715: Signal */
  &gbyk_v4b_B.sf_decoderobot.isPMAC,   /* 716: Signal */
  &gbyk_v4b_B.sf_decoderobot.isECAT,   /* 717: Signal */
  &gbyk_v4b_B.elbowangleoffset,        /* 718: Signal */
  &gbyk_v4b_B.L1,                      /* 719: Signal */
  &gbyk_v4b_B.L2,                      /* 720: Signal */
  &gbyk_v4b_B.L3Error,                 /* 721: Signal */
  &gbyk_v4b_B.M1GearRatio_b,           /* 722: Signal */
  &gbyk_v4b_B.M1orientation_h,         /* 723: Signal */
  &gbyk_v4b_B.M2GearRatio_p,           /* 724: Signal */
  &gbyk_v4b_B.M2Orientation_l,         /* 725: Signal */
  &gbyk_v4b_B.ArmOrientation_b,        /* 726: Signal */
  &gbyk_v4b_B.Pointeroffset,           /* 727: Signal */
  &gbyk_v4b_B.HasSecondaryEnc_n,       /* 728: Signal */
  &gbyk_v4b_B.shoulderangleoffset,     /* 729: Signal */
  &gbyk_v4b_B.ShoulderX,               /* 730: Signal */
  &gbyk_v4b_B.ShoulderY,               /* 731: Signal */
  &gbyk_v4b_B.torqueconstant_g,        /* 732: Signal */
  &gbyk_v4b_B.robottype_e,             /* 733: Signal */
  &gbyk_v4b_B.robotversion_g,          /* 734: Signal */
  &gbyk_v4b_B.Statusread1[0],          /* 735: Signal */
  &gbyk_v4b_B.sf_decoderobot_p.isEP,   /* 736: Signal */
  &gbyk_v4b_B.sf_decoderobot_p.isHumanEXO,/* 737: Signal */
  &gbyk_v4b_B.sf_decoderobot_p.isNHPEXO,/* 738: Signal */
  &gbyk_v4b_B.sf_decoderobot_p.isClassicExo,/* 739: Signal */
  &gbyk_v4b_B.sf_decoderobot_p.isUTSEXO,/* 740: Signal */
  &gbyk_v4b_B.sf_decoderobot_p.isPMAC, /* 741: Signal */
  &gbyk_v4b_B.sf_decoderobot_p.isECAT, /* 742: Signal */
  &gbyk_v4b_B.elbowangleoffset_a,      /* 743: Signal */
  &gbyk_v4b_B.L1_c,                    /* 744: Signal */
  &gbyk_v4b_B.L2_f,                    /* 745: Signal */
  &gbyk_v4b_B.L3Error_f,               /* 746: Signal */
  &gbyk_v4b_B.M1GearRatio_k,           /* 747: Signal */
  &gbyk_v4b_B.M1orientation_n,         /* 748: Signal */
  &gbyk_v4b_B.M2GearRatio_l,           /* 749: Signal */
  &gbyk_v4b_B.M2Orientation_cw,        /* 750: Signal */
  &gbyk_v4b_B.ArmOrientation_l,        /* 751: Signal */
  &gbyk_v4b_B.Pointeroffset_b,         /* 752: Signal */
  &gbyk_v4b_B.HasSecondaryEnc_f,       /* 753: Signal */
  &gbyk_v4b_B.shoulderangleoffset_b,   /* 754: Signal */
  &gbyk_v4b_B.ShoulderX_a,             /* 755: Signal */
  &gbyk_v4b_B.ShoulderY_b,             /* 756: Signal */
  &gbyk_v4b_B.torqueconstant_i,        /* 757: Signal */
  &gbyk_v4b_B.robottype_cs,            /* 758: Signal */
  &gbyk_v4b_B.robotversion_f,          /* 759: Signal */
  &gbyk_v4b_B.Statusread1_m[0],        /* 760: Signal */
  &gbyk_v4b_B.Output_h,                /* 761: Signal */
  &gbyk_v4b_B.FixPtSum1_eh,            /* 762: Signal */
  &gbyk_v4b_B.FixPtSwitch_dp,          /* 763: Signal */
  &gbyk_v4b_B.ControlWord_o,           /* 764: Signal */
  &gbyk_v4b_B.motorStatus_f,           /* 765: Signal */
  &gbyk_v4b_B.isPermFaulted_i,         /* 766: Signal */
  &gbyk_v4b_B.Memory_j,                /* 767: Signal */
  &gbyk_v4b_B.sf_ControlGDCWhistleState_f.ControlWord,/* 768: Signal */
  &gbyk_v4b_B.sf_ControlGDCWhistleState_f.motorStatus,/* 769: Signal */
  &gbyk_v4b_B.sf_ControlGDCWhistleState_f.isPermFaulted,/* 770: Signal */
  &gbyk_v4b_B.Memory_f,                /* 771: Signal */
  &gbyk_v4b_B.sf_AbsEncodermachine.setupData[0],/* 772: Signal */
  &gbyk_v4b_B.sf_AbsEncodermachine.SDORequest[0],/* 773: Signal */
  &gbyk_v4b_B.sf_AbsEncodermachine.encoderOutputs[0],/* 774: Signal */
  &gbyk_v4b_B.sf_AbsEncodermachine.complete,/* 775: Signal */
  &gbyk_v4b_B.sf_setupvalues.setupValues[0],/* 776: Signal */
  &gbyk_v4b_B.sf_setupvalues.setupValuesCount,/* 777: Signal */
  &gbyk_v4b_B.sf_setupvalues.pollValues[0],/* 778: Signal */
  &gbyk_v4b_B.sf_setupvalues.encoderValues[0],/* 779: Signal */
  &gbyk_v4b_B.sf_setupvalues.encoderValuesCount,/* 780: Signal */
  &gbyk_v4b_B.Memory_c,                /* 781: Signal */
  &gbyk_v4b_B.Memory1_b[0],            /* 782: Signal */
  &gbyk_v4b_B.BKINEtherCATAsyncSDODownload_i,/* 783: Signal */
  &gbyk_v4b_B.BKINEtherCATAsyncSDOUpload_o1_p,/* 784: Signal */
  &gbyk_v4b_B.BKINEtherCATAsyncSDOUpload_o2_a,/* 785: Signal */
  &gbyk_v4b_B.sf_AbsEncodermachine_b.setupData[0],/* 786: Signal */
  &gbyk_v4b_B.sf_AbsEncodermachine_b.SDORequest[0],/* 787: Signal */
  &gbyk_v4b_B.sf_AbsEncodermachine_b.encoderOutputs[0],/* 788: Signal */
  &gbyk_v4b_B.sf_AbsEncodermachine_b.complete,/* 789: Signal */
  &gbyk_v4b_B.sf_setupvalues_p.setupValues[0],/* 790: Signal */
  &gbyk_v4b_B.sf_setupvalues_p.setupValuesCount,/* 791: Signal */
  &gbyk_v4b_B.sf_setupvalues_p.pollValues[0],/* 792: Signal */
  &gbyk_v4b_B.sf_setupvalues_p.encoderValues[0],/* 793: Signal */
  &gbyk_v4b_B.sf_setupvalues_p.encoderValuesCount,/* 794: Signal */
  &gbyk_v4b_B.Memory_n0,               /* 795: Signal */
  &gbyk_v4b_B.Memory1_n[0],            /* 796: Signal */
  &gbyk_v4b_B.BKINEtherCATAsyncSDODownload_ce,/* 797: Signal */
  &gbyk_v4b_B.BKINEtherCATAsyncSDOUpload_o1_dq,/* 798: Signal */
  &gbyk_v4b_B.BKINEtherCATAsyncSDOUpload_o2_m,/* 799: Signal */
  &gbyk_v4b_B.sf_SDOreadmachine_p.enable,/* 800: Signal */
  &gbyk_v4b_B.sf_SDOreadmachine_p.complete,/* 801: Signal */
  &gbyk_v4b_B.sf_values.outVal[0],     /* 802: Signal */
  &gbyk_v4b_B.readAddr_p[0],           /* 803: Signal */
  &gbyk_v4b_B.DataTypeConversion1_dx,  /* 804: Signal */
  &gbyk_v4b_B.DataTypeConversion2_l,   /* 805: Signal */
  &gbyk_v4b_B.convert_b,               /* 806: Signal */
  &gbyk_v4b_B.convert1_f,              /* 807: Signal */
  &gbyk_v4b_B.status_d,                /* 808: Signal */
  &gbyk_v4b_B.Memory_n,                /* 809: Signal */
  &gbyk_v4b_B.sf_SDOwritemachine.enable,/* 810: Signal */
  &gbyk_v4b_B.sf_SDOwritemachine.complete,/* 811: Signal */
  &gbyk_v4b_B.sf_convert.y,            /* 812: Signal */
  &gbyk_v4b_B.writeData_e[0],          /* 813: Signal */
  &gbyk_v4b_B.DataTypeConversion1_d,   /* 814: Signal */
  &gbyk_v4b_B.DataTypeConversion2_b,   /* 815: Signal */
  &gbyk_v4b_B.status_n,                /* 816: Signal */
  &gbyk_v4b_B.Memory_nf,               /* 817: Signal */
  &gbyk_v4b_B.BKINEtherCATAsyncSDODownload_f,/* 818: Signal */
  &gbyk_v4b_B.Memory_d3,               /* 819: Signal */
  &gbyk_v4b_B.Memory1_o,               /* 820: Signal */
  &gbyk_v4b_B.Memory2_n,               /* 821: Signal */
  &gbyk_v4b_B.RateTransition_bs,       /* 822: Signal */
  &gbyk_v4b_B.RateTransition1_ds,      /* 823: Signal */
  &gbyk_v4b_B.RateTransition2_dj,      /* 824: Signal */
  &gbyk_v4b_B.sf_ControlGDCWhistleState_p.ControlWord,/* 825: Signal */
  &gbyk_v4b_B.sf_ControlGDCWhistleState_p.motorStatus,/* 826: Signal */
  &gbyk_v4b_B.sf_ControlGDCWhistleState_p.isPermFaulted,/* 827: Signal */
  &gbyk_v4b_B.Memory_m,                /* 828: Signal */
  &gbyk_v4b_B.ControlWord,             /* 829: Signal */
  &gbyk_v4b_B.motorStatus,             /* 830: Signal */
  &gbyk_v4b_B.isPermFaulted,           /* 831: Signal */
  &gbyk_v4b_B.Memory_i,                /* 832: Signal */
  &gbyk_v4b_B.sf_AbsEncodermachine_i.setupData[0],/* 833: Signal */
  &gbyk_v4b_B.sf_AbsEncodermachine_i.SDORequest[0],/* 834: Signal */
  &gbyk_v4b_B.sf_AbsEncodermachine_i.encoderOutputs[0],/* 835: Signal */
  &gbyk_v4b_B.sf_AbsEncodermachine_i.complete,/* 836: Signal */
  &gbyk_v4b_B.sf_setupvalues_k.setupValues[0],/* 837: Signal */
  &gbyk_v4b_B.sf_setupvalues_k.setupValuesCount,/* 838: Signal */
  &gbyk_v4b_B.sf_setupvalues_k.pollValues[0],/* 839: Signal */
  &gbyk_v4b_B.sf_setupvalues_k.encoderValues[0],/* 840: Signal */
  &gbyk_v4b_B.sf_setupvalues_k.encoderValuesCount,/* 841: Signal */
  &gbyk_v4b_B.Memory_h,                /* 842: Signal */
  &gbyk_v4b_B.Memory1_f[0],            /* 843: Signal */
  &gbyk_v4b_B.BKINEtherCATAsyncSDODownload_g0,/* 844: Signal */
  &gbyk_v4b_B.BKINEtherCATAsyncSDOUpload_o1_k,/* 845: Signal */
  &gbyk_v4b_B.BKINEtherCATAsyncSDOUpload_o2_o,/* 846: Signal */
  &gbyk_v4b_B.sf_AbsEncodermachine_k.setupData[0],/* 847: Signal */
  &gbyk_v4b_B.sf_AbsEncodermachine_k.SDORequest[0],/* 848: Signal */
  &gbyk_v4b_B.sf_AbsEncodermachine_k.encoderOutputs[0],/* 849: Signal */
  &gbyk_v4b_B.sf_AbsEncodermachine_k.complete,/* 850: Signal */
  &gbyk_v4b_B.sf_setupvalues_g.setupValues[0],/* 851: Signal */
  &gbyk_v4b_B.sf_setupvalues_g.setupValuesCount,/* 852: Signal */
  &gbyk_v4b_B.sf_setupvalues_g.pollValues[0],/* 853: Signal */
  &gbyk_v4b_B.sf_setupvalues_g.encoderValues[0],/* 854: Signal */
  &gbyk_v4b_B.sf_setupvalues_g.encoderValuesCount,/* 855: Signal */
  &gbyk_v4b_B.Memory_pb,               /* 856: Signal */
  &gbyk_v4b_B.Memory1_et[0],           /* 857: Signal */
  &gbyk_v4b_B.BKINEtherCATAsyncSDODownload_g,/* 858: Signal */
  &gbyk_v4b_B.BKINEtherCATAsyncSDOUpload_o1,/* 859: Signal */
  &gbyk_v4b_B.BKINEtherCATAsyncSDOUpload_o2,/* 860: Signal */
  &gbyk_v4b_B.sf_SDOreadmachine_g.enable,/* 861: Signal */
  &gbyk_v4b_B.sf_SDOreadmachine_g.complete,/* 862: Signal */
  &gbyk_v4b_B.sf_values_n.outVal[0],   /* 863: Signal */
  &gbyk_v4b_B.readAddr[0],             /* 864: Signal */
  &gbyk_v4b_B.DataTypeConversion1_k2,  /* 865: Signal */
  &gbyk_v4b_B.DataTypeConversion2_m,   /* 866: Signal */
  &gbyk_v4b_B.convert_l,               /* 867: Signal */
  &gbyk_v4b_B.convert1,                /* 868: Signal */
  &gbyk_v4b_B.status_e,                /* 869: Signal */
  &gbyk_v4b_B.Memory_ip,               /* 870: Signal */
  &gbyk_v4b_B.sf_SDOwritemachine_j.enable,/* 871: Signal */
  &gbyk_v4b_B.sf_SDOwritemachine_j.complete,/* 872: Signal */
  &gbyk_v4b_B.sf_convert_i.y,          /* 873: Signal */
  &gbyk_v4b_B.writeData[0],            /* 874: Signal */
  &gbyk_v4b_B.DataTypeConversion1_aq,  /* 875: Signal */
  &gbyk_v4b_B.DataTypeConversion2_p,   /* 876: Signal */
  &gbyk_v4b_B.status,                  /* 877: Signal */
  &gbyk_v4b_B.Memory_lf,               /* 878: Signal */
  &gbyk_v4b_B.BKINEtherCATAsyncSDODownload,/* 879: Signal */
  &gbyk_v4b_B.Memory_p,                /* 880: Signal */
  &gbyk_v4b_B.Memory1_e,               /* 881: Signal */
  &gbyk_v4b_B.Memory2,                 /* 882: Signal */
  &gbyk_v4b_B.RateTransition_bx,       /* 883: Signal */
  &gbyk_v4b_B.RateTransition1_d,       /* 884: Signal */
  &gbyk_v4b_B.RateTransition2_j,       /* 885: Signal */
  &gbyk_v4b_B.FixPtSum1_e,             /* 886: Signal */
  &gbyk_v4b_B.FixPtSwitch_m,           /* 887: Signal */
  &gbyk_v4b_B.filteredVels[0],         /* 888: Signal */
  &gbyk_v4b_B.outVals[0],              /* 889: Signal */
  &gbyk_v4b_B.FixPtRelationalOperator, /* 890: Signal */
  &gbyk_v4b_B.Uk1,                     /* 891: Signal */
  &gbyk_v4b_B.ByteReversal_n,          /* 892: Signal */
  &gbyk_v4b_B.ByteReversal1_m,         /* 893: Signal */
  &gbyk_v4b_B.ByteReversal2,           /* 894: Signal */
  &gbyk_v4b_B.Pack_f[0],               /* 895: Signal */
  &gbyk_v4b_B.Switch_n,                /* 896: Signal */
  &gbyk_v4b_B.ByteReversal_g,          /* 897: Signal */
  &gbyk_v4b_B.ByteReversal1_a,         /* 898: Signal */
  &gbyk_v4b_B.ByteReversal2_g,         /* 899: Signal */
  &gbyk_v4b_B.Pack[0],                 /* 900: Signal */
  &gbyk_v4b_B.Switch_g,                /* 901: Signal */
  &gbyk_v4b_B.FixPtRelationalOperator_i,/* 902: Signal */
  &gbyk_v4b_B.Uk1_p,                   /* 903: Signal */
  &gbyk_v4b_B.y_j,                     /* 904: Signal */
  &gbyk_v4b_B.DataTypeConversion_l,    /* 905: Signal */
  &gbyk_v4b_B.DPRAMReadValue,          /* 906: Signal */
  &gbyk_v4b_B.UnitDelay,               /* 907: Signal */
  &gbyk_v4b_B.UnitDelay1,              /* 908: Signal */
  &gbyk_v4b_B.Output_e,                /* 909: Signal */
  &gbyk_v4b_B.FixPtSum1_o,             /* 910: Signal */
  &gbyk_v4b_B.FixPtSwitch_h,           /* 911: Signal */
  &gbyk_v4b_B.sf_parsestatusregister.allOK,/* 912: Signal */
  &gbyk_v4b_B.sf_parsestatusregister.ampStatus,/* 913: Signal */
  &gbyk_v4b_B.sf_parsestatusregister.servoEnabled,/* 914: Signal */
  &gbyk_v4b_B.sf_parsestatusregister.faultFound,/* 915: Signal */
  &gbyk_v4b_B.sf_parsestatusregister.currentLimitEnabled,/* 916: Signal */
  &gbyk_v4b_B.sf_parsestatusregister.eStopOut,/* 917: Signal */
  &gbyk_v4b_B.sf_parsestatusregister.motorOn,/* 918: Signal */
  &gbyk_v4b_B.A1M1Convert[0],          /* 919: Signal */
  &gbyk_v4b_B.DataTypeConversion1_j1,  /* 920: Signal */
  &gbyk_v4b_B.Statusword_k,            /* 921: Signal */
  &gbyk_v4b_B.statusregister_c4,       /* 922: Signal */
  &gbyk_v4b_B.primaryposition_l,       /* 923: Signal */
  &gbyk_v4b_B.secondaryposition_n,     /* 924: Signal */
  &gbyk_v4b_B.primaryvelocity_d,       /* 925: Signal */
  &gbyk_v4b_B.torque_ky,               /* 926: Signal */
  &gbyk_v4b_B.digitalinputs_j,         /* 927: Signal */
  &gbyk_v4b_B.actualmodeofoperation_g, /* 928: Signal */
  &gbyk_v4b_B.Compare_g,               /* 929: Signal */
  &gbyk_v4b_B.triggerCountRead_n,      /* 930: Signal */
  &gbyk_v4b_B.emcyReadTrigger_e[0],    /* 931: Signal */
  &gbyk_v4b_B.countOverwriteTrigger_n, /* 932: Signal */
  &gbyk_v4b_B.emcyValPump_g[0],        /* 933: Signal */
  &gbyk_v4b_B.sf_faultmonitor.triggerFaultRead,/* 934: Signal */
  &gbyk_v4b_B.sf_faultmonitor1.EMCYMsg[0],/* 935: Signal */
  &gbyk_v4b_B.driveID_n2,              /* 936: Signal */
  &gbyk_v4b_B.DataTypeConversion_c,    /* 937: Signal */
  &gbyk_v4b_B.LinkAngle_c,             /* 938: Signal */
  &gbyk_v4b_B.PrimaryLinkAngle_m,      /* 939: Signal */
  &gbyk_v4b_B.PrimaryLinkVel_m,        /* 940: Signal */
  &gbyk_v4b_B.torque_d,                /* 941: Signal */
  &gbyk_v4b_B.digitalInputs_e[0],      /* 942: Signal */
  &gbyk_v4b_B.digitalDiagnostics_e,    /* 943: Signal */
  &gbyk_v4b_B.calibrationButton_e,     /* 944: Signal */
  &gbyk_v4b_B.L2select_i,              /* 945: Signal */
  &gbyk_v4b_B.L2select1_h,             /* 946: Signal */
  &gbyk_v4b_B.L2select2_o,             /* 947: Signal */
  &gbyk_v4b_B.L2select3_cn,            /* 948: Signal */
  &gbyk_v4b_B.L2select4_o,             /* 949: Signal */
  &gbyk_v4b_B.L2select5_c,             /* 950: Signal */
  &gbyk_v4b_B.sf_parsestatusregister1.allOK,/* 951: Signal */
  &gbyk_v4b_B.sf_parsestatusregister1.ampStatus,/* 952: Signal */
  &gbyk_v4b_B.sf_parsestatusregister1.servoEnabled,/* 953: Signal */
  &gbyk_v4b_B.sf_parsestatusregister1.faultFound,/* 954: Signal */
  &gbyk_v4b_B.sf_parsestatusregister1.currentLimitEnabled,/* 955: Signal */
  &gbyk_v4b_B.sf_parsestatusregister1.eStopOut,/* 956: Signal */
  &gbyk_v4b_B.sf_parsestatusregister1.motorOn,/* 957: Signal */
  &gbyk_v4b_B.A1M2Convert[0],          /* 958: Signal */
  &gbyk_v4b_B.DataTypeConversion_em,   /* 959: Signal */
  &gbyk_v4b_B.Statusword_b,            /* 960: Signal */
  &gbyk_v4b_B.statusregister_c,        /* 961: Signal */
  &gbyk_v4b_B.primaryposition_e,       /* 962: Signal */
  &gbyk_v4b_B.secondaryposition_d,     /* 963: Signal */
  &gbyk_v4b_B.primaryvelocity_p,       /* 964: Signal */
  &gbyk_v4b_B.torque_h,                /* 965: Signal */
  &gbyk_v4b_B.digitalinputs,           /* 966: Signal */
  &gbyk_v4b_B.actualmodeofoperation_a, /* 967: Signal */
  &gbyk_v4b_B.Compare_h,               /* 968: Signal */
  &gbyk_v4b_B.triggerCountRead,        /* 969: Signal */
  &gbyk_v4b_B.emcyReadTrigger[0],      /* 970: Signal */
  &gbyk_v4b_B.countOverwriteTrigger,   /* 971: Signal */
  &gbyk_v4b_B.emcyValPump[0],          /* 972: Signal */
  &gbyk_v4b_B.sf_faultmonitor_k.triggerFaultRead,/* 973: Signal */
  &gbyk_v4b_B.sf_faultmonitor1_l.EMCYMsg[0],/* 974: Signal */
  &gbyk_v4b_B.driveID_a,               /* 975: Signal */
  &gbyk_v4b_B.DataTypeConversion_kb,   /* 976: Signal */
  &gbyk_v4b_B.LinkAngle_g,             /* 977: Signal */
  &gbyk_v4b_B.PrimaryLinkAngle_b,      /* 978: Signal */
  &gbyk_v4b_B.PrimaryLinkVel_d,        /* 979: Signal */
  &gbyk_v4b_B.torque_g,                /* 980: Signal */
  &gbyk_v4b_B.digitalInputs_h[0],      /* 981: Signal */
  &gbyk_v4b_B.digitalDiagnostics_a,    /* 982: Signal */
  &gbyk_v4b_B.L2select_e,              /* 983: Signal */
  &gbyk_v4b_B.L2select1_hf,            /* 984: Signal */
  &gbyk_v4b_B.L2select2_d,             /* 985: Signal */
  &gbyk_v4b_B.L2select3_p,             /* 986: Signal */
  &gbyk_v4b_B.L2select4_g,             /* 987: Signal */
  &gbyk_v4b_B.L2select5_f,             /* 988: Signal */
  &gbyk_v4b_B.sf_converter.uint32Out,  /* 989: Signal */
  &gbyk_v4b_B.sf_converter.int32Out,   /* 990: Signal */
  &gbyk_v4b_B.sf_converter.doubleOut,  /* 991: Signal */
  &gbyk_v4b_B.DataTypeConversion_ba,   /* 992: Signal */
  &gbyk_v4b_B.BKINEtherCATAsyncSDOUpload1_o1_p,/* 993: Signal */
  &gbyk_v4b_B.BKINEtherCATAsyncSDOUpload1_o2_i,/* 994: Signal */
  &gbyk_v4b_B.sf_converter_p.uint32Out,/* 995: Signal */
  &gbyk_v4b_B.sf_converter_p.int32Out, /* 996: Signal */
  &gbyk_v4b_B.sf_converter_p.doubleOut,/* 997: Signal */
  &gbyk_v4b_B.DataTypeConversion_f,    /* 998: Signal */
  &gbyk_v4b_B.BKINEtherCATAsyncSDOUpload1_o1_l,/* 999: Signal */
  &gbyk_v4b_B.BKINEtherCATAsyncSDOUpload1_o2_g,/* 1000: Signal */
  &gbyk_v4b_B.sf_parsestatusregister1_f.allOK,/* 1001: Signal */
  &gbyk_v4b_B.sf_parsestatusregister1_f.ampStatus,/* 1002: Signal */
  &gbyk_v4b_B.sf_parsestatusregister1_f.servoEnabled,/* 1003: Signal */
  &gbyk_v4b_B.sf_parsestatusregister1_f.faultFound,/* 1004: Signal */
  &gbyk_v4b_B.sf_parsestatusregister1_f.currentLimitEnabled,/* 1005: Signal */
  &gbyk_v4b_B.sf_parsestatusregister1_f.eStopOut,/* 1006: Signal */
  &gbyk_v4b_B.sf_parsestatusregister1_f.motorOn,/* 1007: Signal */
  &gbyk_v4b_B.A2M1Convert[0],          /* 1008: Signal */
  &gbyk_v4b_B.DataTypeConversion_et,   /* 1009: Signal */
  &gbyk_v4b_B.Statusword,              /* 1010: Signal */
  &gbyk_v4b_B.statusregister_i,        /* 1011: Signal */
  &gbyk_v4b_B.primaryposition,         /* 1012: Signal */
  &gbyk_v4b_B.secondaryposition,       /* 1013: Signal */
  &gbyk_v4b_B.primaryvelocity,         /* 1014: Signal */
  &gbyk_v4b_B.torque_g5,               /* 1015: Signal */
  &gbyk_v4b_B.digitalinput_d,          /* 1016: Signal */
  &gbyk_v4b_B.actualmodeofoperation_j, /* 1017: Signal */
  &gbyk_v4b_B.Compare_oe,              /* 1018: Signal */
  &gbyk_v4b_B.sf_ReadEMCY_i.triggerCountRead,/* 1019: Signal */
  &gbyk_v4b_B.sf_ReadEMCY_i.emcyReadTrigger[0],/* 1020: Signal */
  &gbyk_v4b_B.sf_ReadEMCY_i.countOverwriteTrigger,/* 1021: Signal */
  &gbyk_v4b_B.sf_ReadEMCY_i.emcyValPump[0],/* 1022: Signal */
  &gbyk_v4b_B.sf_faultmonitor_f.triggerFaultRead,/* 1023: Signal */
  &gbyk_v4b_B.sf_faultmonitor1_c.EMCYMsg[0],/* 1024: Signal */
  &gbyk_v4b_B.driveID_n,               /* 1025: Signal */
  &gbyk_v4b_B.DataTypeConversion_bd,   /* 1026: Signal */
  &gbyk_v4b_B.LinkAngle_l,             /* 1027: Signal */
  &gbyk_v4b_B.PrimaryLinkAngle_f,      /* 1028: Signal */
  &gbyk_v4b_B.PrimaryLinkVel_i,        /* 1029: Signal */
  &gbyk_v4b_B.torque_f,                /* 1030: Signal */
  &gbyk_v4b_B.digitalInputs_m[0],      /* 1031: Signal */
  &gbyk_v4b_B.digitalDiagnostics_c,    /* 1032: Signal */
  &gbyk_v4b_B.calibrationButton,       /* 1033: Signal */
  &gbyk_v4b_B.offsetrads,              /* 1034: Signal */
  &gbyk_v4b_B.encorient,               /* 1035: Signal */
  &gbyk_v4b_B.L2select2,               /* 1036: Signal */
  &gbyk_v4b_B.L2select3,               /* 1037: Signal */
  &gbyk_v4b_B.L2select4,               /* 1038: Signal */
  &gbyk_v4b_B.L2select5,               /* 1039: Signal */
  &gbyk_v4b_B.sf_parsestatusregister1_fq.allOK,/* 1040: Signal */
  &gbyk_v4b_B.sf_parsestatusregister1_fq.ampStatus,/* 1041: Signal */
  &gbyk_v4b_B.sf_parsestatusregister1_fq.servoEnabled,/* 1042: Signal */
  &gbyk_v4b_B.sf_parsestatusregister1_fq.faultFound,/* 1043: Signal */
  &gbyk_v4b_B.sf_parsestatusregister1_fq.currentLimitEnabled,/* 1044: Signal */
  &gbyk_v4b_B.sf_parsestatusregister1_fq.eStopOut,/* 1045: Signal */
  &gbyk_v4b_B.sf_parsestatusregister1_fq.motorOn,/* 1046: Signal */
  &gbyk_v4b_B.A2M2Convert[0],          /* 1047: Signal */
  &gbyk_v4b_B.DataTypeConversion_bv,   /* 1048: Signal */
  &gbyk_v4b_B.statusword,              /* 1049: Signal */
  &gbyk_v4b_B.statusregister,          /* 1050: Signal */
  &gbyk_v4b_B.positionprimary,         /* 1051: Signal */
  &gbyk_v4b_B.positionsecondary,       /* 1052: Signal */
  &gbyk_v4b_B.velocityprimary,         /* 1053: Signal */
  &gbyk_v4b_B.torque_k,                /* 1054: Signal */
  &gbyk_v4b_B.digitalinput,            /* 1055: Signal */
  &gbyk_v4b_B.actualmodeofoperation,   /* 1056: Signal */
  &gbyk_v4b_B.Compare_oo,              /* 1057: Signal */
  &gbyk_v4b_B.sf_ReadEMCY_p.triggerCountRead,/* 1058: Signal */
  &gbyk_v4b_B.sf_ReadEMCY_p.emcyReadTrigger[0],/* 1059: Signal */
  &gbyk_v4b_B.sf_ReadEMCY_p.countOverwriteTrigger,/* 1060: Signal */
  &gbyk_v4b_B.sf_ReadEMCY_p.emcyValPump[0],/* 1061: Signal */
  &gbyk_v4b_B.sf_faultmonitor_i.triggerFaultRead,/* 1062: Signal */
  &gbyk_v4b_B.sf_faultmonitor1_h.EMCYMsg[0],/* 1063: Signal */
  &gbyk_v4b_B.driveID,                 /* 1064: Signal */
  &gbyk_v4b_B.DataTypeConversion_j,    /* 1065: Signal */
  &gbyk_v4b_B.LinkAngle,               /* 1066: Signal */
  &gbyk_v4b_B.PrimaryLinkAngle,        /* 1067: Signal */
  &gbyk_v4b_B.PrimaryLinkVel,          /* 1068: Signal */
  &gbyk_v4b_B.torque,                  /* 1069: Signal */
  &gbyk_v4b_B.digitalInputs[0],        /* 1070: Signal */
  &gbyk_v4b_B.digitalDiagnostics,      /* 1071: Signal */
  &gbyk_v4b_B.L2select,                /* 1072: Signal */
  &gbyk_v4b_B.L2select1,               /* 1073: Signal */
  &gbyk_v4b_B.L2select2_p,             /* 1074: Signal */
  &gbyk_v4b_B.L2select3_c,             /* 1075: Signal */
  &gbyk_v4b_B.L2select4_b,             /* 1076: Signal */
  &gbyk_v4b_B.L2select5_a,             /* 1077: Signal */
  &gbyk_v4b_B.sf_converter_j.uint32Out,/* 1078: Signal */
  &gbyk_v4b_B.sf_converter_j.int32Out, /* 1079: Signal */
  &gbyk_v4b_B.sf_converter_j.doubleOut,/* 1080: Signal */
  &gbyk_v4b_B.DataTypeConversion_d,    /* 1081: Signal */
  &gbyk_v4b_B.BKINEtherCATAsyncSDOUpload1_o1_f,/* 1082: Signal */
  &gbyk_v4b_B.BKINEtherCATAsyncSDOUpload1_o2_a,/* 1083: Signal */
  &gbyk_v4b_B.sf_converter_jl.uint32Out,/* 1084: Signal */
  &gbyk_v4b_B.sf_converter_jl.int32Out,/* 1085: Signal */
  &gbyk_v4b_B.sf_converter_jl.doubleOut,/* 1086: Signal */
  &gbyk_v4b_B.DataTypeConversion_iq,   /* 1087: Signal */
  &gbyk_v4b_B.BKINEtherCATAsyncSDOUpload1_o1,/* 1088: Signal */
  &gbyk_v4b_B.BKINEtherCATAsyncSDOUpload1_o2,/* 1089: Signal */
  &gbyk_v4b_B.Output_b,                /* 1090: Signal */
  &gbyk_v4b_B.DataTypeConversion_pj,   /* 1091: Signal */
  &gbyk_v4b_B.DataTypeConversion1_j,   /* 1092: Signal */
  &gbyk_v4b_B.DataTypeConversion2_pm,  /* 1093: Signal */
  &gbyk_v4b_B.Read_h,                  /* 1094: Signal */
  &gbyk_v4b_B.DataTypeConversion_dd,   /* 1095: Signal */
  &gbyk_v4b_B.DataTypeConversion1_o,   /* 1096: Signal */
  &gbyk_v4b_B.FixPtSum1_n,             /* 1097: Signal */
  &gbyk_v4b_B.FixPtSwitch_d,           /* 1098: Signal */
  &gbyk_v4b_B.DataTypeConversion_je,   /* 1099: Signal */
  &gbyk_v4b_B.DataTypeConversion1_jd,  /* 1100: Signal */
  &gbyk_v4b_B.DataTypeConversion2_j[0],/* 1101: Signal */
  &gbyk_v4b_B.Memory_pr[0],            /* 1102: Signal */
  &gbyk_v4b_B.RateTransition_e[0],     /* 1103: Signal */
  &gbyk_v4b_B.BKINEtherCATAsyncSDOUpload_o1_b,/* 1104: Signal */
  &gbyk_v4b_B.BKINEtherCATAsyncSDOUpload_o2_db,/* 1105: Signal */
  &gbyk_v4b_B.DataTypeConversion_hm[0],/* 1106: Signal */
  &gbyk_v4b_B.Memory_ne[0],            /* 1107: Signal */
  &gbyk_v4b_B.RateTransition_cg[0],    /* 1108: Signal */
  &gbyk_v4b_B.BKINEtherCATAsyncSDOUpload_o1_h,/* 1109: Signal */
  &gbyk_v4b_B.BKINEtherCATAsyncSDOUpload_o2_di,/* 1110: Signal */
  &gbyk_v4b_B.DataTypeConversion_mf,   /* 1111: Signal */
  &gbyk_v4b_B.DataTypeConversion1_av,  /* 1112: Signal */
  &gbyk_v4b_B.Memory_dp,               /* 1113: Signal */
  &gbyk_v4b_B.BKINEtherCATAsyncSDODownload_n,/* 1114: Signal */
  &gbyk_v4b_B.DataTypeConversion_n,    /* 1115: Signal */
  &gbyk_v4b_B.DataTypeConversion1_ke,  /* 1116: Signal */
  &gbyk_v4b_B.DataTypeConversion2_d[0],/* 1117: Signal */
  &gbyk_v4b_B.Memory_d4[0],            /* 1118: Signal */
  &gbyk_v4b_B.RateTransition_m[0],     /* 1119: Signal */
  &gbyk_v4b_B.BKINEtherCATAsyncSDOUpload_o1_ln,/* 1120: Signal */
  &gbyk_v4b_B.BKINEtherCATAsyncSDOUpload_o2_d,/* 1121: Signal */
  &gbyk_v4b_B.DataTypeConversion_m[0], /* 1122: Signal */
  &gbyk_v4b_B.Memory_kw[0],            /* 1123: Signal */
  &gbyk_v4b_B.RateTransition_o[0],     /* 1124: Signal */
  &gbyk_v4b_B.BKINEtherCATAsyncSDOUpload_o1_n,/* 1125: Signal */
  &gbyk_v4b_B.BKINEtherCATAsyncSDOUpload_o2_k,/* 1126: Signal */
  &gbyk_v4b_B.DataTypeConversion_gy,   /* 1127: Signal */
  &gbyk_v4b_B.DataTypeConversion1_i,   /* 1128: Signal */
  &gbyk_v4b_B.Memory_d,                /* 1129: Signal */
  &gbyk_v4b_B.BKINEtherCATAsyncSDODownload_a,/* 1130: Signal */
  &gbyk_v4b_B.DataTypeConversion_b3,   /* 1131: Signal */
  &gbyk_v4b_B.DataTypeConversion1_ij,  /* 1132: Signal */
  &gbyk_v4b_B.DataTypeConversion2_nh[0],/* 1133: Signal */
  &gbyk_v4b_B.Memory_c1[0],            /* 1134: Signal */
  &gbyk_v4b_B.RateTransition_l[0],     /* 1135: Signal */
  &gbyk_v4b_B.BKINEtherCATAsyncSDOUpload_o1_l,/* 1136: Signal */
  &gbyk_v4b_B.BKINEtherCATAsyncSDOUpload_o2_c,/* 1137: Signal */
  &gbyk_v4b_B.DataTypeConversion_p[0], /* 1138: Signal */
  &gbyk_v4b_B.Memory_a[0],             /* 1139: Signal */
  &gbyk_v4b_B.RateTransition_k4[0],    /* 1140: Signal */
  &gbyk_v4b_B.BKINEtherCATAsyncSDOUpload_o1_d,/* 1141: Signal */
  &gbyk_v4b_B.BKINEtherCATAsyncSDOUpload_o2_p,/* 1142: Signal */
  &gbyk_v4b_B.DataTypeConversion_ek,   /* 1143: Signal */
  &gbyk_v4b_B.DataTypeConversion1_k,   /* 1144: Signal */
  &gbyk_v4b_B.Memory_g,                /* 1145: Signal */
  &gbyk_v4b_B.BKINEtherCATAsyncSDODownload_c,/* 1146: Signal */
  &gbyk_v4b_B.DataTypeConversion_dc,   /* 1147: Signal */
  &gbyk_v4b_B.DataTypeConversion1_of,  /* 1148: Signal */
  &gbyk_v4b_B.DataTypeConversion2_g[0],/* 1149: Signal */
  &gbyk_v4b_B.Memory_kg[0],            /* 1150: Signal */
  &gbyk_v4b_B.RateTransition_gy[0],    /* 1151: Signal */
  &gbyk_v4b_B.BKINEtherCATAsyncSDOUpload_o1_m,/* 1152: Signal */
  &gbyk_v4b_B.BKINEtherCATAsyncSDOUpload_o2_i,/* 1153: Signal */
  &gbyk_v4b_B.DataTypeConversion_i1[0],/* 1154: Signal */
  &gbyk_v4b_B.Memory_f3[0],            /* 1155: Signal */
  &gbyk_v4b_B.RateTransition_i[0],     /* 1156: Signal */
  &gbyk_v4b_B.BKINEtherCATAsyncSDOUpload_o1_f,/* 1157: Signal */
  &gbyk_v4b_B.BKINEtherCATAsyncSDOUpload_o2_j,/* 1158: Signal */
  &gbyk_v4b_B.DataTypeConversion_dh,   /* 1159: Signal */
  &gbyk_v4b_B.DataTypeConversion1_c,   /* 1160: Signal */
  &gbyk_v4b_B.Memory_l,                /* 1161: Signal */
  &gbyk_v4b_B.BKINEtherCATAsyncSDODownload_gy,/* 1162: Signal */
  &gbyk_v4b_B.FixPtSum1_ea,            /* 1163: Signal */
  &gbyk_v4b_B.FixPtSwitch_j,           /* 1164: Signal */
  &gbyk_v4b_P.CompareToConstant_const, /* 1165: Block Parameter */
  &gbyk_v4b_P.GUIControl_XYcols[0],    /* 1166: Block Parameter */
  &gbyk_v4b_P.GUIControl_Vcols,        /* 1167: Block Parameter */
  &gbyk_v4b_P.GUIControl_Lcols,        /* 1168: Block Parameter */
  &gbyk_v4b_P.Hand_Feedback_feedback_cntl_src,/* 1169: Block Parameter */
  &gbyk_v4b_P.KINARM_DistanceFromTarget_use_dominant_hand,/* 1170: Block Parameter */
  &gbyk_v4b_P.KINARM_HandInBox_use_dominant_hand,/* 1171: Block Parameter */
  &gbyk_v4b_P.KINARM_HandInBox_target_type,/* 1172: Block Parameter */
  &gbyk_v4b_P.KINARM_HandInBox_num_states,/* 1173: Block Parameter */
  &gbyk_v4b_P.KINARM_HandInBox_attribcol1[0],/* 1174: Block Parameter */
  &gbyk_v4b_P.KINARM_HandInTarget_use_dominant_hand,/* 1175: Block Parameter */
  &gbyk_v4b_P.KINARM_HandInTarget_target_type,/* 1176: Block Parameter */
  &gbyk_v4b_P.KINARM_HandInTarget_num_states,/* 1177: Block Parameter */
  &gbyk_v4b_P.KINARM_HandInTarget_attribcol1,/* 1178: Block Parameter */
  &gbyk_v4b_P.Process_Video_CMD_video_delay,/* 1179: Block Parameter */
  &gbyk_v4b_P.Show_Box_target_type,    /* 1180: Block Parameter */
  &gbyk_v4b_P.Show_Box_num_states,     /* 1181: Block Parameter */
  &gbyk_v4b_P.Show_Box_attribcol1[0],  /* 1182: Block Parameter */
  &gbyk_v4b_P.Show_Box_attribcol2[0],  /* 1183: Block Parameter */
  &gbyk_v4b_P.Show_Box_opacity,        /* 1184: Block Parameter */
  &gbyk_v4b_P.Show_Box_target_display, /* 1185: Block Parameter */
  &gbyk_v4b_P.Show_TargetB_With_Label_target_type,/* 1186: Block Parameter */
  &gbyk_v4b_P.Show_TargetB_With_Label_num_states,/* 1187: Block Parameter */
  &gbyk_v4b_P.Show_TargetB_With_Label_attribcol1[0],/* 1188: Block Parameter */
  &gbyk_v4b_P.Show_TargetB_With_Label_attribcol2[0],/* 1189: Block Parameter */
  &gbyk_v4b_P.Show_TargetB_With_Label_attribcol3[0],/* 1190: Block Parameter */
  &gbyk_v4b_P.Show_TargetB_With_Label_opacity,/* 1191: Block Parameter */
  &gbyk_v4b_P.Show_TargetB_With_Label_target_display,/* 1192: Block Parameter */
  &gbyk_v4b_P.Show_TargetC_With_Label_target_type,/* 1193: Block Parameter */
  &gbyk_v4b_P.Show_TargetC_With_Label_num_states,/* 1194: Block Parameter */
  &gbyk_v4b_P.Show_TargetC_With_Label_attribcol1[0],/* 1195: Block Parameter */
  &gbyk_v4b_P.Show_TargetC_With_Label_attribcol2[0],/* 1196: Block Parameter */
  &gbyk_v4b_P.Show_TargetC_With_Label_attribcol3[0],/* 1197: Block Parameter */
  &gbyk_v4b_P.Show_TargetC_With_Label_opacity,/* 1198: Block Parameter */
  &gbyk_v4b_P.Show_TargetC_With_Label_target_display,/* 1199: Block Parameter */
  &gbyk_v4b_P.Show_Target_A_target_type,/* 1200: Block Parameter */
  &gbyk_v4b_P.Show_Target_A_num_states,/* 1201: Block Parameter */
  &gbyk_v4b_P.Show_Target_A_attribcol1[0],/* 1202: Block Parameter */
  &gbyk_v4b_P.Show_Target_A_attribcol2[0],/* 1203: Block Parameter */
  &gbyk_v4b_P.Show_Target_A_opacity,   /* 1204: Block Parameter */
  &gbyk_v4b_P.Show_Target_A_target_display,/* 1205: Block Parameter */
  &gbyk_v4b_P.Switch_Threshold_f,      /* 1206: Block Parameter */
  &gbyk_v4b_P.Switch1_Threshold_e,     /* 1207: Block Parameter */
  &gbyk_v4b_P.ECATDigDiagnostic_InitialValue[0],/* 1208: Block Parameter */
  &gbyk_v4b_P.ECATStatus_InitialValue[0],/* 1209: Block Parameter */
  &gbyk_v4b_P.ECAThardware_InitialValue[0],/* 1210: Block Parameter */
  &gbyk_v4b_P.ZeroDigOut_Value[0],     /* 1211: Block Parameter */
  &gbyk_v4b_P.ZeroEPTorque_Value[0],   /* 1212: Block Parameter */
  &gbyk_v4b_P.ZeroTorque_Value[0],     /* 1213: Block Parameter */
  &gbyk_v4b_P.seconds_remaining_Value, /* 1214: Block Parameter */
  &gbyk_v4b_P.Memory_X0_gv,            /* 1215: Block Parameter */
  &gbyk_v4b_P.Memory1_X0_b,            /* 1216: Block Parameter */
  &gbyk_v4b_P.Show_Target_target_type, /* 1217: Block Parameter */
  &gbyk_v4b_P.Show_Target_num_states,  /* 1218: Block Parameter */
  &gbyk_v4b_P.Show_Target_attribcol1[0],/* 1219: Block Parameter */
  &gbyk_v4b_P.Show_Target_opacity,     /* 1220: Block Parameter */
  &gbyk_v4b_P.Show_Target_target_display,/* 1221: Block Parameter */
  &gbyk_v4b_P.Constant_Value_a,        /* 1222: Block Parameter */
  &gbyk_v4b_P.Show_Target_With_Label1_target_type,/* 1223: Block Parameter */
  &gbyk_v4b_P.Show_Target_With_Label1_num_states,/* 1224: Block Parameter */
  &gbyk_v4b_P.Show_Target_With_Label1_attribcol1[0],/* 1225: Block Parameter */
  &gbyk_v4b_P.Show_Target_With_Label1_opacity,/* 1226: Block Parameter */
  &gbyk_v4b_P.Show_Target_With_Label1_target_display,/* 1227: Block Parameter */
  &gbyk_v4b_P.Switch_Threshold_d,      /* 1228: Block Parameter */
  &gbyk_v4b_P.BlockDefinitions_Value[0],/* 1229: Block Parameter */
  &gbyk_v4b_P.BlockSequence_Value[0],  /* 1230: Block Parameter */
  &gbyk_v4b_P.Constant_Value_h,        /* 1231: Block Parameter */
  &gbyk_v4b_P.DisplaySizem_Value[0],   /* 1232: Block Parameter */
  &gbyk_v4b_P.DisplaySizepels_Value[0],/* 1233: Block Parameter */
  &gbyk_v4b_P.DockingPoints_Value[0],  /* 1234: Block Parameter */
  &gbyk_v4b_P.ELCameraAngle_Value_h[0],/* 1235: Block Parameter */
  &gbyk_v4b_P.ELCameraFocalLength_Value_b,/* 1236: Block Parameter */
  &gbyk_v4b_P.ELCameraPosition_Value_k[0],/* 1237: Block Parameter */
  &gbyk_v4b_P.ELTrackingAvailable_Value_a,/* 1238: Block Parameter */
  &gbyk_v4b_P.LibraryPatchVersion_Value,/* 1239: Block Parameter */
  &gbyk_v4b_P.LibraryVersion_Value,    /* 1240: Block Parameter */
  &gbyk_v4b_P.LoadTable_Value[0],      /* 1241: Block Parameter */
  &gbyk_v4b_P.NextBlock_Value,         /* 1242: Block Parameter */
  &gbyk_v4b_P.PauseType_Value,         /* 1243: Block Parameter */
  &gbyk_v4b_P.RunTaskClockFlag_Value,  /* 1244: Block Parameter */
  &gbyk_v4b_P.Seed_Value,              /* 1245: Block Parameter */
  &gbyk_v4b_P.SubjectHeight_Value,     /* 1246: Block Parameter */
  &gbyk_v4b_P.SubjectWeight_Value,     /* 1247: Block Parameter */
  &gbyk_v4b_P.TPTable_Value[0],        /* 1248: Block Parameter */
  &gbyk_v4b_P.TargetLabels_Value[0],   /* 1249: Block Parameter */
  &gbyk_v4b_P.TargetTable_Value[0],    /* 1250: Block Parameter */
  &gbyk_v4b_P.TaskVersion_Value,       /* 1251: Block Parameter */
  &gbyk_v4b_P.Taskwideparam_Value[0],  /* 1252: Block Parameter */
  &gbyk_v4b_P.UseRepeatTrialFlag_Value,/* 1253: Block Parameter */
  &gbyk_v4b_P.UseTaskProtocolBlockSequenceFlag_Value,/* 1254: Block Parameter */
  &gbyk_v4b_P.dlmbuildtime_Value,      /* 1255: Block Parameter */
  &gbyk_v4b_P.frame_of_reference_center_Value[0],/* 1256: Block Parameter */
  &gbyk_v4b_P.xPCVersion_Value,        /* 1257: Block Parameter */
  &gbyk_v4b_P.Assess_arm_VCODE_Value[0],/* 1258: Block Parameter */
  &gbyk_v4b_P.Contralateral_arm_VCODE_Value[0],/* 1259: Block Parameter */
  &gbyk_v4b_P.feedback_status_Value,   /* 1260: Block Parameter */
  &gbyk_v4b_P.SelectedStates_Value_j,  /* 1261: Block Parameter */
  &gbyk_v4b_P.attribcol2_Value_k[0],   /* 1262: Block Parameter */
  &gbyk_v4b_P.attribcol3_Value_e[0],   /* 1263: Block Parameter */
  &gbyk_v4b_P.attribcol4_Value_l[0],   /* 1264: Block Parameter */
  &gbyk_v4b_P.attribcol5_Value_j[0],   /* 1265: Block Parameter */
  &gbyk_v4b_P.SelectedStates_Value,    /* 1266: Block Parameter */
  &gbyk_v4b_P.attribcol2_Value,        /* 1267: Block Parameter */
  &gbyk_v4b_P.attribcol3_Value,        /* 1268: Block Parameter */
  &gbyk_v4b_P.attribcol4_Value,        /* 1269: Block Parameter */
  &gbyk_v4b_P.attribcol5_Value,        /* 1270: Block Parameter */
  &gbyk_v4b_P.GUI_VCODE_Value[0],      /* 1271: Block Parameter */
  &gbyk_v4b_P.Gain_Gain_a,             /* 1272: Block Parameter */
  &gbyk_v4b_P.Memory_X0_c,             /* 1273: Block Parameter */
  &gbyk_v4b_P.Receive_P1_n[0],         /* 1274: Block Parameter */
  &gbyk_v4b_P.Receive_P2_n,            /* 1275: Block Parameter */
  &gbyk_v4b_P.Receive_P3_a,            /* 1276: Block Parameter */
  &gbyk_v4b_P.Receive_P4_l,            /* 1277: Block Parameter */
  &gbyk_v4b_P.Receive_P5_g,            /* 1278: Block Parameter */
  &gbyk_v4b_P.Send_P1_n[0],            /* 1279: Block Parameter */
  &gbyk_v4b_P.Send_P2_d,               /* 1280: Block Parameter */
  &gbyk_v4b_P.Send_P3_n,               /* 1281: Block Parameter */
  &gbyk_v4b_P.Send_P4_l,               /* 1282: Block Parameter */
  &gbyk_v4b_P.Send_P5_l,               /* 1283: Block Parameter */
  &gbyk_v4b_P.padder_Value_k[0],       /* 1284: Block Parameter */
  &gbyk_v4b_P.state3_indices_Value_p[0],/* 1285: Block Parameter */
  &gbyk_v4b_P.state4_indices_Value_o[0],/* 1286: Block Parameter */
  &gbyk_v4b_P.state5_indices_Value_d[0],/* 1287: Block Parameter */
  &gbyk_v4b_P.xpos_index_Value_f,      /* 1288: Block Parameter */
  &gbyk_v4b_P.ypos_index_Value_l,      /* 1289: Block Parameter */
  &gbyk_v4b_P.padder_Value_b[0],       /* 1290: Block Parameter */
  &gbyk_v4b_P.state4_indices_Value_d[0],/* 1291: Block Parameter */
  &gbyk_v4b_P.state5_indices_Value_i[0],/* 1292: Block Parameter */
  &gbyk_v4b_P.xpos_index_Value_d,      /* 1293: Block Parameter */
  &gbyk_v4b_P.ypos_index_Value_b,      /* 1294: Block Parameter */
  &gbyk_v4b_P.padder_Value_a[0],       /* 1295: Block Parameter */
  &gbyk_v4b_P.state4_indices_Value_a[0],/* 1296: Block Parameter */
  &gbyk_v4b_P.state5_indices_Value_j[0],/* 1297: Block Parameter */
  &gbyk_v4b_P.xpos_index_Value_g,      /* 1298: Block Parameter */
  &gbyk_v4b_P.ypos_index_Value_f,      /* 1299: Block Parameter */
  &gbyk_v4b_P.padder_Value[0],         /* 1300: Block Parameter */
  &gbyk_v4b_P.state3_indices_Value[0], /* 1301: Block Parameter */
  &gbyk_v4b_P.state4_indices_Value[0], /* 1302: Block Parameter */
  &gbyk_v4b_P.state5_indices_Value[0], /* 1303: Block Parameter */
  &gbyk_v4b_P.xpos_index_Value,        /* 1304: Block Parameter */
  &gbyk_v4b_P.ypos_index_Value,        /* 1305: Block Parameter */
  &gbyk_v4b_P.NotLoggingAnalogInputs_Value,/* 1306: Block Parameter */
  &gbyk_v4b_P.custom_version_Value,    /* 1307: Block Parameter */
  &gbyk_v4b_P.RateTransition2_X0_o,    /* 1308: Block Parameter */
  &gbyk_v4b_P.NotLoggingEventCodes_Value,/* 1309: Block Parameter */
  &gbyk_v4b_P.IfRunning_const,         /* 1310: Block Parameter */
  &gbyk_v4b_P.packet_version_Value,    /* 1311: Block Parameter */
  &gbyk_v4b_P.const_Value[0],          /* 1312: Block Parameter */
  &gbyk_v4b_P.Send_P1[0],              /* 1313: Block Parameter */
  &gbyk_v4b_P.Send_P2,                 /* 1314: Block Parameter */
  &gbyk_v4b_P.Send_P3,                 /* 1315: Block Parameter */
  &gbyk_v4b_P.Send_P4,                 /* 1316: Block Parameter */
  &gbyk_v4b_P.Send_P5,                 /* 1317: Block Parameter */
  &gbyk_v4b_P.max_packet_id_Value,     /* 1318: Block Parameter */
  &gbyk_v4b_P.runID_Value,             /* 1319: Block Parameter */
  &gbyk_v4b_P.TaskClock_Amp,           /* 1320: Block Parameter */
  &gbyk_v4b_P.TaskClock_Period,        /* 1321: Block Parameter */
  &gbyk_v4b_P.TaskClock_Duty,          /* 1322: Block Parameter */
  &gbyk_v4b_P.TaskClock_PhaseDelay,    /* 1323: Block Parameter */
  &gbyk_v4b_P.ain_offset1_Value,       /* 1324: Block Parameter */
  &gbyk_v4b_P.ain_offset2_Value,       /* 1325: Block Parameter */
  &gbyk_v4b_P.ain_slope1_Value,        /* 1326: Block Parameter */
  &gbyk_v4b_P.ain_slope2_Value,        /* 1327: Block Parameter */
  &gbyk_v4b_P.calibration_matrix1_Value[0],/* 1328: Block Parameter */
  &gbyk_v4b_P.calibration_matrix2_Value[0],/* 1329: Block Parameter */
  &gbyk_v4b_P.enable_plate1_Value,     /* 1330: Block Parameter */
  &gbyk_v4b_P.enable_plate2_Value,     /* 1331: Block Parameter */
  &gbyk_v4b_P.gain_Value,              /* 1332: Block Parameter */
  &gbyk_v4b_P.orientation1_Value,      /* 1333: Block Parameter */
  &gbyk_v4b_P.orientation2_Value,      /* 1334: Block Parameter */
  &gbyk_v4b_P.request_packet_Value[0], /* 1335: Block Parameter */
  &gbyk_v4b_P.zero_voltage_Value,      /* 1336: Block Parameter */
  &gbyk_v4b_P.ECATDigitalin_InitialValue[0],/* 1337: Block Parameter */
  &gbyk_v4b_P.ECATErrMsgs_InitialValue[0],/* 1338: Block Parameter */
  &gbyk_v4b_P.ECATTorquefeedback_InitialValue[0],/* 1339: Block Parameter */
  &gbyk_v4b_P.HWSettings_InitialValue[0],/* 1340: Block Parameter */
  &gbyk_v4b_P.Kinematics_InitialValue[0],/* 1341: Block Parameter */
  &gbyk_v4b_P.PrimaryEnc_InitialValue[0],/* 1342: Block Parameter */
  &gbyk_v4b_P.RobotCalib_InitialValue[0],/* 1343: Block Parameter */
  &gbyk_v4b_P.RobotRevision_InitialValue[0],/* 1344: Block Parameter */
  &gbyk_v4b_P.ServoUpdate_InitialValue,/* 1345: Block Parameter */
  &gbyk_v4b_P.Systemstatus_InitialValue[0],/* 1346: Block Parameter */
  &gbyk_v4b_P.calibbutton_InitialValue,/* 1347: Block Parameter */
  &gbyk_v4b_P.delays_InitialValue[0],  /* 1348: Block Parameter */
  &gbyk_v4b_P.hasFTsensors_InitialValue[0],/* 1349: Block Parameter */
  &gbyk_v4b_P.isecat_const,            /* 1350: Block Parameter */
  &gbyk_v4b_P.ispmac_const,            /* 1351: Block Parameter */
  &gbyk_v4b_P.systemtype_Value,        /* 1352: Block Parameter */
  &gbyk_v4b_P.ELCameraAngle_Value[0],  /* 1353: Block Parameter */
  &gbyk_v4b_P.ELCameraFocalLength_Value,/* 1354: Block Parameter */
  &gbyk_v4b_P.ELCameraPosition_Value[0],/* 1355: Block Parameter */
  &gbyk_v4b_P.ELTrackingAvailable_Value,/* 1356: Block Parameter */
  &gbyk_v4b_P.Gain_Gain,               /* 1357: Block Parameter */
  &gbyk_v4b_P.RateTransition_X0,       /* 1358: Block Parameter */
  &gbyk_v4b_P.Receive_P1_i[0],         /* 1359: Block Parameter */
  &gbyk_v4b_P.Receive_P2_i,            /* 1360: Block Parameter */
  &gbyk_v4b_P.Receive_P3_l,            /* 1361: Block Parameter */
  &gbyk_v4b_P.Receive_P4_g,            /* 1362: Block Parameter */
  &gbyk_v4b_P.Receive_P5_a,            /* 1363: Block Parameter */
  &gbyk_v4b_P.isecat_const_a,          /* 1364: Block Parameter */
  &gbyk_v4b_P.isecat1_const,           /* 1365: Block Parameter */
  &gbyk_v4b_P.arm_count_Value,         /* 1366: Block Parameter */
  &gbyk_v4b_P.fp1_present_Value,       /* 1367: Block Parameter */
  &gbyk_v4b_P.fp2_present_Value,       /* 1368: Block Parameter */
  &gbyk_v4b_P.gaze_tracker_present_Value,/* 1369: Block Parameter */
  &gbyk_v4b_P.robot_lift_present_Value,/* 1370: Block Parameter */
  &gbyk_v4b_P.padder_Value_j[0],       /* 1371: Block Parameter */
  &gbyk_v4b_P.state2_indices_Value_j[0],/* 1372: Block Parameter */
  &gbyk_v4b_P.state3_indices_Value_og[0],/* 1373: Block Parameter */
  &gbyk_v4b_P.state4_indices_Value_g[0],/* 1374: Block Parameter */
  &gbyk_v4b_P.state5_indices_Value_im[0],/* 1375: Block Parameter */
  &gbyk_v4b_P.xpos_index_Value_e,      /* 1376: Block Parameter */
  &gbyk_v4b_P.ypos_index_Value_bm,     /* 1377: Block Parameter */
  &gbyk_v4b_P.padder_Value_l[0],       /* 1378: Block Parameter */
  &gbyk_v4b_P.state2_indices_Value[0], /* 1379: Block Parameter */
  &gbyk_v4b_P.state3_indices_Value_o[0],/* 1380: Block Parameter */
  &gbyk_v4b_P.state4_indices_Value_p[0],/* 1381: Block Parameter */
  &gbyk_v4b_P.state5_indices_Value_l[0],/* 1382: Block Parameter */
  &gbyk_v4b_P.xpos_index_Value_l,      /* 1383: Block Parameter */
  &gbyk_v4b_P.ypos_index_Value_d,      /* 1384: Block Parameter */
  &gbyk_v4b_P.Target_Type_Value,       /* 1385: Block Parameter */
  &gbyk_v4b_P.indices_padding_Value[0],/* 1386: Block Parameter */
  &gbyk_v4b_P.Hold_to_1Khz_BKIN_STEP_TIME,/* 1387: Block Parameter */
  &gbyk_v4b_P.RunCommandReceive_P1[0], /* 1388: Block Parameter */
  &gbyk_v4b_P.RunCommandReceive_P2,    /* 1389: Block Parameter */
  &gbyk_v4b_P.RunCommandReceive_P3,    /* 1390: Block Parameter */
  &gbyk_v4b_P.RunCommandReceive_P4,    /* 1391: Block Parameter */
  &gbyk_v4b_P.RunCommandReceive_P5,    /* 1392: Block Parameter */
  &gbyk_v4b_P.CompareToConstant_const_b,/* 1393: Block Parameter */
  &gbyk_v4b_P.Constant_Value_o1,       /* 1394: Block Parameter */
  &gbyk_v4b_P.TaskClock_Amp_m,         /* 1395: Block Parameter */
  &gbyk_v4b_P.TaskClock_Period_n,      /* 1396: Block Parameter */
  &gbyk_v4b_P.TaskClock_Duty_e,        /* 1397: Block Parameter */
  &gbyk_v4b_P.TaskClock_PhaseDelay_b,  /* 1398: Block Parameter */
  &gbyk_v4b_P.Delay_X0,                /* 1399: Block Parameter */
  &gbyk_v4b_P.Delay1_X0,               /* 1400: Block Parameter */
  &gbyk_v4b_P.B1TargetB1rowfloatB1rowintargettablenone_Value,/* 1401: Block Parameter */
  &gbyk_v4b_P.B2TargetB2rowfloatB2rowintargettablenone_Value,/* 1402: Block Parameter */
  &gbyk_v4b_P.CORR_TGTWhichtargetiscorrectfloatWhichtargetiscorrect1or2none_V,/* 1403: Block Parameter */
  &gbyk_v4b_P.DELAY_POST_TRIALTrialEndDelayintegerTimetowaitattheendofthetria,/* 1404: Block Parameter */
  &gbyk_v4b_P.DISPLAY_TRIAL_COLFlagDisplayintegerDisplayandpausenone_Value,/* 1405: Block Parameter */
  &gbyk_v4b_P.INCORR_TGTWhichtargetisincorrectfloatWhichtargetisincorrect1or2,/* 1406: Block Parameter */
  &gbyk_v4b_P.MAX_REACH_TIME_COLMaximumReachTimeintegerMaximumreachdurational,/* 1407: Block Parameter */
  &gbyk_v4b_P.RWD_TARGETC1_COLTarget1ValuefloatRewardofferedonTargetC1none_Va,/* 1408: Block Parameter */
  &gbyk_v4b_P.RWD_TARGETC2_COLTarget2ValuefloatRewardofferedonTargetC2none_Va,/* 1409: Block Parameter */
  &gbyk_v4b_P.START_TARGET_COLStarttargettargetFirsttargettoappearduringatria,/* 1410: Block Parameter */
  &gbyk_v4b_P.TGT_C_RWD_FRACRewardratiobetweenrowCrowBfloatHowmuchmorewilltar,/* 1411: Block Parameter */
  &gbyk_v4b_P.INSTRUCT_PAUSE_BTNInstructionResumeButtontocontinuetaskafterdis,/* 1412: Block Parameter */
  &gbyk_v4b_P.E_BOX_TRIGGERBoxWasTriggeredBoxtriggreredsosubjectchoserowCnone,/* 1413: Block Parameter */
  &gbyk_v4b_P.E_CHOSE_ROW_BChoseRowBSubjectchoserowBnone_Value,/* 1414: Block Parameter */
  &gbyk_v4b_P.E_HIT_TARGETBHitTargetBHittargetBnone_Value,/* 1415: Block Parameter */
  &gbyk_v4b_P.E_HIT_TARGETCHitTargetCHitTargetCnone_Value,/* 1416: Block Parameter */
  &gbyk_v4b_P.E_MISS_TARGETBMissTargretBMissTargretBnone_Value,/* 1417: Block Parameter */
  &gbyk_v4b_P.E_MISS_TARGETCMissTargetCMissTargetCnone_Value,/* 1418: Block Parameter */
  &gbyk_v4b_P.E_NEW_TRIALNewTrialStartNewTrialstartsnone_Value,/* 1419: Block Parameter */
  &gbyk_v4b_P.E_NO_EVENTnaThisevent_codedoesnotsaveaneventinthedatafileitjust,/* 1420: Block Parameter */
  &gbyk_v4b_P.E_SHOW_INSTRUCTInstructionstateShowinginstructionsnone_Value,/* 1421: Block Parameter */
  &gbyk_v4b_P.E_SHOW_SCOREShowScoreShowingscorenone_Value,/* 1422: Block Parameter */
  &gbyk_v4b_P.E_STAY_STARTAtStartSubjectreachedstarttargetnone_Value,/* 1423: Block Parameter */
  &gbyk_v4b_P.E_TARGETS_ONTargetsOnPotentialReachtargetsonnone_Value,/* 1424: Block Parameter */
  &gbyk_v4b_P.E_TOO_SLOWTooSlowMovementistooslowerror_Value,/* 1425: Block Parameter */
  &gbyk_v4b_P.BOX_HEIGHTHeightofBoxfloatHeightofBoxnone_Value,/* 1426: Block Parameter */
  &gbyk_v4b_P.HIT_COLORReachedcolorcolourColorwhenthetargetistouchednone_Valu,/* 1427: Block Parameter */
  &gbyk_v4b_P.INIT_COLORInitialcolorcolourInitialtargetcolornone_Value,/* 1428: Block Parameter */
  &gbyk_v4b_P.LABELLabelTextlabelInitialtextforthelabelnone_Value,/* 1429: Block Parameter */
  &gbyk_v4b_P.LABELONLY_XLabelOnlyXfloatXpositioncmofthetargetrelativetolocal,/* 1430: Block Parameter */
  &gbyk_v4b_P.LABELONLY_YLabelOnlyYfloatYpositioncmofthetargetrelativetolocal,/* 1431: Block Parameter */
  &gbyk_v4b_P.LABEL_HEIGHTLabelHeightfloatLabelHeightcmnone_Value,/* 1432: Block Parameter */
  &gbyk_v4b_P.LOGICAL_RADIUSLogicalradiusfloatRadiusofthetargetusedforhandint,/* 1433: Block Parameter */
  &gbyk_v4b_P.ROTATIONRotationofatargetfloatRotationoftargetnone_Value,/* 1434: Block Parameter */
  &gbyk_v4b_P.STROKE_WIDTHStrokeWidthfloatStrokewidthnone_Value,/* 1435: Block Parameter */
  &gbyk_v4b_P.TEXT_COLORTextColorcolourTextColornone_Value,/* 1436: Block Parameter */
  &gbyk_v4b_P.VISUAL_RADIUSVisualradiusfloatVisualradiusofthetargetcmorsizeof,/* 1437: Block Parameter */
  &gbyk_v4b_P.col_xXfloatXPositioncmofthetargetrelativetolocal00none_Value,/* 1438: Block Parameter */
  &gbyk_v4b_P.col_yYfloatYPositioncmofthetargetrelativetolocal00none_Value,/* 1439: Block Parameter */
  &gbyk_v4b_P.INSTRUCTIONS_Value,      /* 1440: Block Parameter */
  &gbyk_v4b_P.LOAD_FOREITHER_Value,    /* 1441: Block Parameter */
  &gbyk_v4b_P.K_DELAY_FIXEDDelay_MinintegerMinimumholddelaytimeatstarttargetf,/* 1442: Block Parameter */
  &gbyk_v4b_P.K_DELAY_RANDDelay_RandintegerMaximumadditionaldelaytimeatstartt,/* 1443: Block Parameter */
  &gbyk_v4b_P.K_PRE_REWARD_DELAYDelay_PreRewardCueintegerTimetocuetherewardin,/* 1444: Block Parameter */
  &gbyk_v4b_P.K_REWARD_VALReward_ValueintegerOneunitofrewardnone_Value,/* 1445: Block Parameter */
  &gbyk_v4b_P.K_SCORETEXT_ROWFeedback_Text_TgtTable_RowintegerTargetnumbertob,/* 1446: Block Parameter */
  &gbyk_v4b_P.K_THRESH_VELMAXVel_Min_ThreshfloatMinimumvelocitythatmustbeexce,/* 1447: Block Parameter */
  &gbyk_v4b_P.K_TRIGGER_POSTrigger_PosfloatPositionThresholdfortriggeringtarg,/* 1448: Block Parameter */
  &gbyk_v4b_P.K_TRIGGER_VELTrigger_VelfloatVelocityThresholdfortriggeringtarg,/* 1449: Block Parameter */
  &gbyk_v4b_P.u0hz_Value,              /* 1450: Block Parameter */
  &gbyk_v4b_P.RateTransition1_X0,      /* 1451: Block Parameter */
  &gbyk_v4b_P.WrapToZero_Threshold_c,  /* 1452: Block Parameter */
  &gbyk_v4b_P.Output_InitialCondition_a,/* 1453: Block Parameter */
  &gbyk_v4b_P.Constant_Value_g[0],     /* 1454: Block Parameter */
  &gbyk_v4b_P.Constant1_Value,         /* 1455: Block Parameter */
  &gbyk_v4b_P.MaxFramesPerPacket_Value,/* 1456: Block Parameter */
  &gbyk_v4b_P.t1_X0,                   /* 1457: Block Parameter */
  &gbyk_v4b_P.t2_X0,                   /* 1458: Block Parameter */
  &gbyk_v4b_P.Memory2_X0,              /* 1459: Block Parameter */
  &gbyk_v4b_P.RateTransition2_X0,      /* 1460: Block Parameter */
  &gbyk_v4b_P.UDPReceive_P1[0],        /* 1461: Block Parameter */
  &gbyk_v4b_P.UDPReceive_P2,           /* 1462: Block Parameter */
  &gbyk_v4b_P.UDPReceive_P3,           /* 1463: Block Parameter */
  &gbyk_v4b_P.UDPReceive_P4,           /* 1464: Block Parameter */
  &gbyk_v4b_P.UDPReceive_P5,           /* 1465: Block Parameter */
  &gbyk_v4b_P.UDPReceivePortReset_P1[0],/* 1466: Block Parameter */
  &gbyk_v4b_P.UDPReceivePortReset_P2,  /* 1467: Block Parameter */
  &gbyk_v4b_P.UDPReceivePortReset_P3,  /* 1468: Block Parameter */
  &gbyk_v4b_P.UDPReceivePortReset_P4,  /* 1469: Block Parameter */
  &gbyk_v4b_P.UDPReceivePortReset_P5,  /* 1470: Block Parameter */
  &gbyk_v4b_P.total_packets_sent_Y0,   /* 1471: Block Parameter */
  &gbyk_v4b_P.Send_P1_f[0],            /* 1472: Block Parameter */
  &gbyk_v4b_P.Send_P2_g,               /* 1473: Block Parameter */
  &gbyk_v4b_P.Send_P3_j,               /* 1474: Block Parameter */
  &gbyk_v4b_P.Send_P4_k,               /* 1475: Block Parameter */
  &gbyk_v4b_P.Send_P5_k,               /* 1476: Block Parameter */
  &gbyk_v4b_P.Receive_P1[0],           /* 1477: Block Parameter */
  &gbyk_v4b_P.Receive_P2,              /* 1478: Block Parameter */
  &gbyk_v4b_P.Receive_P3,              /* 1479: Block Parameter */
  &gbyk_v4b_P.Receive_P4,              /* 1480: Block Parameter */
  &gbyk_v4b_P.Receive_P5,              /* 1481: Block Parameter */
  &gbyk_v4b_P.Receive1_P1[0],          /* 1482: Block Parameter */
  &gbyk_v4b_P.Receive1_P2,             /* 1483: Block Parameter */
  &gbyk_v4b_P.Receive1_P3,             /* 1484: Block Parameter */
  &gbyk_v4b_P.Receive1_P4,             /* 1485: Block Parameter */
  &gbyk_v4b_P.Receive1_P5,             /* 1486: Block Parameter */
  &gbyk_v4b_P.Send_P1_e[0],            /* 1487: Block Parameter */
  &gbyk_v4b_P.Send_P2_e,               /* 1488: Block Parameter */
  &gbyk_v4b_P.Send_P3_p,               /* 1489: Block Parameter */
  &gbyk_v4b_P.Send_P4_k1,              /* 1490: Block Parameter */
  &gbyk_v4b_P.Send_P5_n,               /* 1491: Block Parameter */
  &gbyk_v4b_P.Send1_P1[0],             /* 1492: Block Parameter */
  &gbyk_v4b_P.Send1_P2,                /* 1493: Block Parameter */
  &gbyk_v4b_P.Send1_P3,                /* 1494: Block Parameter */
  &gbyk_v4b_P.Send1_P4,                /* 1495: Block Parameter */
  &gbyk_v4b_P.Send1_P5,                /* 1496: Block Parameter */
  &gbyk_v4b_P.Compare_const_j,         /* 1497: Block Parameter */
  &gbyk_v4b_P.PCIBusSlot_Value[0],     /* 1498: Block Parameter */
  &gbyk_v4b_P.activation_Value[0],     /* 1499: Block Parameter */
  &gbyk_v4b_P.eppartnums_Value[0],     /* 1500: Block Parameter */
  &gbyk_v4b_P.exopartnums_Value[0],    /* 1501: Block Parameter */
  &gbyk_v4b_P.forceprimaryonly_Value,  /* 1502: Block Parameter */
  &gbyk_v4b_P.maxerrorstofault_Value,  /* 1503: Block Parameter */
  &gbyk_v4b_P.nhppartnums_Value[0],    /* 1504: Block Parameter */
  &gbyk_v4b_P.Switch_Threshold_b,      /* 1505: Block Parameter */
  &gbyk_v4b_P.ispmac1_const,           /* 1506: Block Parameter */
  &gbyk_v4b_P.updateconstants_Value,   /* 1507: Block Parameter */
  &gbyk_v4b_P.DominantArm_Value,       /* 1508: Block Parameter */
  &gbyk_v4b_P.steptime_Value,          /* 1509: Block Parameter */
  &gbyk_v4b_P.FixPtConstant_Value_g,   /* 1510: Block Parameter */
  &gbyk_v4b_P.Constant_Value_cq,       /* 1511: Block Parameter */
  &gbyk_v4b_P.Constant_Value,          /* 1512: Block Parameter */
  &gbyk_v4b_P.UnitDelay_InitialCondition,/* 1513: Block Parameter */
  &gbyk_v4b_P.WrapToZero_Threshold,    /* 1514: Block Parameter */
  &gbyk_v4b_P.Output_InitialCondition, /* 1515: Block Parameter */
  &gbyk_v4b_P.TorqueMode_Value,        /* 1516: Block Parameter */
  &gbyk_v4b_P.enableCalibration_Value, /* 1517: Block Parameter */
  &gbyk_v4b_P.enableMotors_Value,      /* 1518: Block Parameter */
  &gbyk_v4b_P.readTrigger_Value,       /* 1519: Block Parameter */
  &gbyk_v4b_P.Memory2_X0_i,            /* 1520: Block Parameter */
  &gbyk_v4b_P.Memory3_X0,              /* 1521: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit_P1[0],/* 1522: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit_P2,/* 1523: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit_P3,/* 1524: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit_P4,/* 1525: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit_P5,/* 1526: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit_P6,/* 1527: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit_P7,/* 1528: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit1_P1[0],/* 1529: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit1_P2,/* 1530: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit1_P3,/* 1531: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit1_P4,/* 1532: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit1_P5,/* 1533: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit1_P6,/* 1534: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit1_P7,/* 1535: Block Parameter */
  &gbyk_v4b_P.TorqueMode_Value_k,      /* 1536: Block Parameter */
  &gbyk_v4b_P.enableCalibration_Value_h,/* 1537: Block Parameter */
  &gbyk_v4b_P.enableMotors_Value_c,    /* 1538: Block Parameter */
  &gbyk_v4b_P.readTrigger_Value_l,     /* 1539: Block Parameter */
  &gbyk_v4b_P.Memory2_X0_o,            /* 1540: Block Parameter */
  &gbyk_v4b_P.Memory3_X0_i,            /* 1541: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit_P1_o[0],/* 1542: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit_P2_m,/* 1543: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit_P3_n,/* 1544: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit_P4_l,/* 1545: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit_P5_g,/* 1546: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit_P6_d,/* 1547: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit_P7_o,/* 1548: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit1_P1_b[0],/* 1549: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit1_P2_a,/* 1550: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit1_P3_m,/* 1551: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit1_P4_e,/* 1552: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit1_P5_a,/* 1553: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit1_P6_j,/* 1554: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit1_P7_n,/* 1555: Block Parameter */
  &gbyk_v4b_P.WrapToZero_Threshold_e,  /* 1556: Block Parameter */
  &gbyk_v4b_P.Output_InitialCondition_pe,/* 1557: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit_P1_h[0],/* 1558: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit_P2_i,/* 1559: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit_P3_k,/* 1560: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit_P4_dw,/* 1561: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit_P5_n,/* 1562: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit_P6_oc,/* 1563: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit_P7_bj,/* 1564: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit1_P1_j[0],/* 1565: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit1_P2_i,/* 1566: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit1_P3_e,/* 1567: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit1_P4_j,/* 1568: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit1_P5_c,/* 1569: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit1_P6_m,/* 1570: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit1_P7_h,/* 1571: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit2_P1[0],/* 1572: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit2_P2,/* 1573: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit2_P3,/* 1574: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit2_P4,/* 1575: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit2_P5,/* 1576: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit2_P6,/* 1577: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit2_P7,/* 1578: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit3_P1[0],/* 1579: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit3_P2,/* 1580: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit3_P3,/* 1581: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit3_P4,/* 1582: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit3_P5,/* 1583: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit3_P6,/* 1584: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit3_P7,/* 1585: Block Parameter */
  &gbyk_v4b_P.Constant_Value_d,        /* 1586: Block Parameter */
  &gbyk_v4b_P.Constant1_Value_k,       /* 1587: Block Parameter */
  &gbyk_v4b_P.DetectChange_vinit,      /* 1588: Block Parameter */
  &gbyk_v4b_P.Constant_Value_o[0],     /* 1589: Block Parameter */
  &gbyk_v4b_P.ReceivefromRobot1ForceSensor_P1[0],/* 1590: Block Parameter */
  &gbyk_v4b_P.ReceivefromRobot1ForceSensor_P2,/* 1591: Block Parameter */
  &gbyk_v4b_P.ReceivefromRobot1ForceSensor_P3,/* 1592: Block Parameter */
  &gbyk_v4b_P.ReceivefromRobot1ForceSensor_P4,/* 1593: Block Parameter */
  &gbyk_v4b_P.ReceivefromRobot1ForceSensor_P5,/* 1594: Block Parameter */
  &gbyk_v4b_P.Switch_Threshold_m,      /* 1595: Block Parameter */
  &gbyk_v4b_P.DetectChange_vinit_n,    /* 1596: Block Parameter */
  &gbyk_v4b_P.Constant1_Value_a[0],    /* 1597: Block Parameter */
  &gbyk_v4b_P.ReceivefromRobot2ForceSensor_P1[0],/* 1598: Block Parameter */
  &gbyk_v4b_P.ReceivefromRobot2ForceSensor_P2,/* 1599: Block Parameter */
  &gbyk_v4b_P.ReceivefromRobot2ForceSensor_P3,/* 1600: Block Parameter */
  &gbyk_v4b_P.ReceivefromRobot2ForceSensor_P4,/* 1601: Block Parameter */
  &gbyk_v4b_P.ReceivefromRobot2ForceSensor_P5,/* 1602: Block Parameter */
  &gbyk_v4b_P.Switch1_Threshold,       /* 1603: Block Parameter */
  &gbyk_v4b_P.robot_count_Value,       /* 1604: Block Parameter */
  &gbyk_v4b_P.stepduration_Value,      /* 1605: Block Parameter */
  &gbyk_v4b_P.servocounter_Y0,         /* 1606: Block Parameter */
  &gbyk_v4b_P.EPcalibrationbtn_Y0,     /* 1607: Block Parameter */
  &gbyk_v4b_P.Statusbits_Y0[0],        /* 1608: Block Parameter */
  &gbyk_v4b_P.MATLABFunction_BKIN_STEP_TIME,/* 1609: Block Parameter */
  &gbyk_v4b_P.Constant_Value_di,       /* 1610: Block Parameter */
  &gbyk_v4b_P.Constant1_Value_gt[0],   /* 1611: Block Parameter */
  &gbyk_v4b_P.Receive_P1_m[0],         /* 1612: Block Parameter */
  &gbyk_v4b_P.Receive_P2_k,            /* 1613: Block Parameter */
  &gbyk_v4b_P.Receive_P3_e,            /* 1614: Block Parameter */
  &gbyk_v4b_P.Receive_P4_h,            /* 1615: Block Parameter */
  &gbyk_v4b_P.Receive_P5_i,            /* 1616: Block Parameter */
  &gbyk_v4b_P.Constant_Value_l[0],     /* 1617: Block Parameter */
  &gbyk_v4b_P.ArmElbowAngleOffset_Value,/* 1618: Block Parameter */
  &gbyk_v4b_P.ArmEncoderOrientation1_Value,/* 1619: Block Parameter */
  &gbyk_v4b_P.ArmEncoderOrientation2_Value,/* 1620: Block Parameter */
  &gbyk_v4b_P.ArmForceSensorAngleOffset_Value,/* 1621: Block Parameter */
  &gbyk_v4b_P.ArmL1_Value,             /* 1622: Block Parameter */
  &gbyk_v4b_P.ArmL2_Value,             /* 1623: Block Parameter */
  &gbyk_v4b_P.ArmL2L5Angle_Value,      /* 1624: Block Parameter */
  &gbyk_v4b_P.ArmL3Error_Value,        /* 1625: Block Parameter */
  &gbyk_v4b_P.ArmL5_Value,             /* 1626: Block Parameter */
  &gbyk_v4b_P.ArmMotor1GearRatio_Value,/* 1627: Block Parameter */
  &gbyk_v4b_P.ArmMotor1Orientation_Value,/* 1628: Block Parameter */
  &gbyk_v4b_P.ArmMotor2GearRatio_Value,/* 1629: Block Parameter */
  &gbyk_v4b_P.ArmMotor2Orientation_Value,/* 1630: Block Parameter */
  &gbyk_v4b_P.ArmOrientation_Value,    /* 1631: Block Parameter */
  &gbyk_v4b_P.ArmPointerOffset_Value,  /* 1632: Block Parameter */
  &gbyk_v4b_P.ArmSecondaryEncoders_Value,/* 1633: Block Parameter */
  &gbyk_v4b_P.ArmShoulderAngleOffset_Value,/* 1634: Block Parameter */
  &gbyk_v4b_P.ArmShoulderX_Value,      /* 1635: Block Parameter */
  &gbyk_v4b_P.ArmShoulderY_Value,      /* 1636: Block Parameter */
  &gbyk_v4b_P.ArmTorqueConstant_Value, /* 1637: Block Parameter */
  &gbyk_v4b_P.Armprimaryencodercounts_Value,/* 1638: Block Parameter */
  &gbyk_v4b_P.Armrobottype_Value,      /* 1639: Block Parameter */
  &gbyk_v4b_P.Armrobotversion_Value,   /* 1640: Block Parameter */
  &gbyk_v4b_P.Armsecondaryencodercounts_Value,/* 1641: Block Parameter */
  &gbyk_v4b_P.ArmElbowAngleOffset_Value_n,/* 1642: Block Parameter */
  &gbyk_v4b_P.ArmEncoderOrientation1_Value_f,/* 1643: Block Parameter */
  &gbyk_v4b_P.ArmEncoderOrientation2_Value_i,/* 1644: Block Parameter */
  &gbyk_v4b_P.ArmForceSensorAngleOffset_Value_c,/* 1645: Block Parameter */
  &gbyk_v4b_P.ArmL1_Value_c,           /* 1646: Block Parameter */
  &gbyk_v4b_P.ArmL2_Value_i,           /* 1647: Block Parameter */
  &gbyk_v4b_P.ArmL2L5Angle_Value_g,    /* 1648: Block Parameter */
  &gbyk_v4b_P.ArmL3Error_Value_l,      /* 1649: Block Parameter */
  &gbyk_v4b_P.ArmL5_Value_m,           /* 1650: Block Parameter */
  &gbyk_v4b_P.ArmMotor1GearRatio_Value_b,/* 1651: Block Parameter */
  &gbyk_v4b_P.ArmMotor1Orientation_Value_a,/* 1652: Block Parameter */
  &gbyk_v4b_P.ArmMotor2GearRatio_Value_a,/* 1653: Block Parameter */
  &gbyk_v4b_P.ArmMotor2Orientation_Value_a,/* 1654: Block Parameter */
  &gbyk_v4b_P.ArmOrientation_Value_p,  /* 1655: Block Parameter */
  &gbyk_v4b_P.ArmPointerOffset_Value_b,/* 1656: Block Parameter */
  &gbyk_v4b_P.ArmSecondaryEncoders_Value_h,/* 1657: Block Parameter */
  &gbyk_v4b_P.ArmShoulderAngleOffset_Value_l,/* 1658: Block Parameter */
  &gbyk_v4b_P.ArmShoulderX_Value_j,    /* 1659: Block Parameter */
  &gbyk_v4b_P.ArmShoulderY_Value_p,    /* 1660: Block Parameter */
  &gbyk_v4b_P.ArmTorqueConstant_Value_a,/* 1661: Block Parameter */
  &gbyk_v4b_P.Armprimaryencodercounts_Value_j,/* 1662: Block Parameter */
  &gbyk_v4b_P.Armrobottype_Value_m,    /* 1663: Block Parameter */
  &gbyk_v4b_P.Armrobotversion_Value_b, /* 1664: Block Parameter */
  &gbyk_v4b_P.Armsecondaryencodercounts_Value_i,/* 1665: Block Parameter */
  &gbyk_v4b_P.ArmForceSensors_Value[0],/* 1666: Block Parameter */
  &gbyk_v4b_P.WrapToZero_Threshold_o,  /* 1667: Block Parameter */
  &gbyk_v4b_P.Output_InitialCondition_b,/* 1668: Block Parameter */
  &gbyk_v4b_P.GazeFeedbackStatus_Value,/* 1669: Block Parameter */
  &gbyk_v4b_P.HandFeedbackColour_Value,/* 1670: Block Parameter */
  &gbyk_v4b_P.HandFeedbackFeedForward_Value,/* 1671: Block Parameter */
  &gbyk_v4b_P.HandFeedbackRadius_Value,/* 1672: Block Parameter */
  &gbyk_v4b_P.HandFeedbackSource_Value,/* 1673: Block Parameter */
  &gbyk_v4b_P.HandFeedbackStatus_Value,/* 1674: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit1_P1_d[0],/* 1675: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit1_P2_e,/* 1676: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit1_P3_n,/* 1677: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit1_P4_f,/* 1678: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit1_P5_e,/* 1679: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit1_P6_jb,/* 1680: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit1_P7_i,/* 1681: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit2_P1_d[0],/* 1682: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit2_P2_m,/* 1683: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit2_P3_a,/* 1684: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit2_P4_m,/* 1685: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit2_P5_f,/* 1686: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit2_P6_m,/* 1687: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit2_P7_f,/* 1688: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit1_P1_h[0],/* 1689: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit1_P2_k,/* 1690: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit1_P3_p,/* 1691: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit1_P4_k,/* 1692: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit1_P5_g,/* 1693: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit1_P6_jg,/* 1694: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit1_P7_m,/* 1695: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit2_P1_p[0],/* 1696: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit2_P2_j,/* 1697: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit2_P3_f,/* 1698: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit2_P4_j,/* 1699: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit2_P5_m,/* 1700: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit2_P6_h,/* 1701: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit2_P7_a,/* 1702: Block Parameter */
  &gbyk_v4b_P.FixPtConstant_Value,     /* 1703: Block Parameter */
  &gbyk_v4b_P.Constant_Value_f,        /* 1704: Block Parameter */
  &gbyk_v4b_P.CompareToConstant_const_m,/* 1705: Block Parameter */
  &gbyk_v4b_P.MotorIdx_Value,          /* 1706: Block Parameter */
  &gbyk_v4b_P.Memory_X0_f,             /* 1707: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit_P1_d[0],/* 1708: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit_P2_c,/* 1709: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit_P3_g,/* 1710: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit_P4_n,/* 1711: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit_P5_e,/* 1712: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit_P6_n,/* 1713: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit_P7_b,/* 1714: Block Parameter */
  &gbyk_v4b_P.Compare_const,           /* 1715: Block Parameter */
  &gbyk_v4b_P.MotorIdx_Value_n,        /* 1716: Block Parameter */
  &gbyk_v4b_P.Memory_X0_jg,            /* 1717: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit_P1_i[0],/* 1718: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit_P2_n,/* 1719: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit_P3_l,/* 1720: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit_P4_m,/* 1721: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit_P5_d,/* 1722: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit_P6_o,/* 1723: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit_P7_l,/* 1724: Block Parameter */
  &gbyk_v4b_P.Memory_X0_e,             /* 1725: Block Parameter */
  &gbyk_v4b_P.Memory1_X0_h,            /* 1726: Block Parameter */
  &gbyk_v4b_P.Memory_X0_gr,            /* 1727: Block Parameter */
  &gbyk_v4b_P.Memory1_X0_p,            /* 1728: Block Parameter */
  &gbyk_v4b_P.readAddr_Value[0],       /* 1729: Block Parameter */
  &gbyk_v4b_P.Memory_X0_j,             /* 1730: Block Parameter */
  &gbyk_v4b_P.writeData_Value[0],      /* 1731: Block Parameter */
  &gbyk_v4b_P.Memory_X0_h,             /* 1732: Block Parameter */
  &gbyk_v4b_P.Memory_X0_hu,            /* 1733: Block Parameter */
  &gbyk_v4b_P.Memory1_X0,              /* 1734: Block Parameter */
  &gbyk_v4b_P.Memory2_X0_k,            /* 1735: Block Parameter */
  &gbyk_v4b_P.Compare_const_b,         /* 1736: Block Parameter */
  &gbyk_v4b_P.MotorIdx_Value_d,        /* 1737: Block Parameter */
  &gbyk_v4b_P.Memory_X0_g,             /* 1738: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit_P1_k[0],/* 1739: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit_P2_no,/* 1740: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit_P3_gf,/* 1741: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit_P4_d,/* 1742: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit_P5_eg,/* 1743: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit_P6_l,/* 1744: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit_P7_m,/* 1745: Block Parameter */
  &gbyk_v4b_P.Compare_const_h,         /* 1746: Block Parameter */
  &gbyk_v4b_P.MotorIdx_Value_n1,       /* 1747: Block Parameter */
  &gbyk_v4b_P.Memory_X0_fo,            /* 1748: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit_P1_ib[0],/* 1749: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit_P2_g,/* 1750: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit_P3_e,/* 1751: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit_P4_g,/* 1752: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit_P5_f,/* 1753: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit_P6_di,/* 1754: Block Parameter */
  &gbyk_v4b_P.BKINEtherCATPDOTransmit_P7_c,/* 1755: Block Parameter */
  &gbyk_v4b_P.Memory_X0_nj,            /* 1756: Block Parameter */
  &gbyk_v4b_P.Memory1_X0_hb,           /* 1757: Block Parameter */
  &gbyk_v4b_P.Memory_X0_id,            /* 1758: Block Parameter */
  &gbyk_v4b_P.Memory1_X0_a,            /* 1759: Block Parameter */
  &gbyk_v4b_P.readAddr_Value_b[0],     /* 1760: Block Parameter */
  &gbyk_v4b_P.Memory_X0_i,             /* 1761: Block Parameter */
  &gbyk_v4b_P.writeData_Value_f[0],    /* 1762: Block Parameter */
  &gbyk_v4b_P.Memory_X0_cr,            /* 1763: Block Parameter */
  &gbyk_v4b_P.Memory_X0_ge,            /* 1764: Block Parameter */
  &gbyk_v4b_P.Memory1_X0_f,            /* 1765: Block Parameter */
  &gbyk_v4b_P.Memory2_X0_e,            /* 1766: Block Parameter */
  &gbyk_v4b_P.FixPtConstant_Value_m,   /* 1767: Block Parameter */
  &gbyk_v4b_P.Constant_Value_kn,       /* 1768: Block Parameter */
  &gbyk_v4b_P.ndorderbutterworth4Khz10hzcutoff_Value[0],/* 1769: Block Parameter */
  &gbyk_v4b_P.Constant_Value_md,       /* 1770: Block Parameter */
  &gbyk_v4b_P.Constant1_Value_c,       /* 1771: Block Parameter */
  &gbyk_v4b_P.Constant2_Value,         /* 1772: Block Parameter */
  &gbyk_v4b_P.Constant3_Value,         /* 1773: Block Parameter */
  &gbyk_v4b_P.Send_P1_c[0],            /* 1774: Block Parameter */
  &gbyk_v4b_P.Send_P2_o,               /* 1775: Block Parameter */
  &gbyk_v4b_P.Send_P3_d,               /* 1776: Block Parameter */
  &gbyk_v4b_P.Send_P4_o,               /* 1777: Block Parameter */
  &gbyk_v4b_P.Send_P5_m,               /* 1778: Block Parameter */
  &gbyk_v4b_P.Switch_Threshold,        /* 1779: Block Parameter */
  &gbyk_v4b_P.Constant_Value_cn,       /* 1780: Block Parameter */
  &gbyk_v4b_P.Constant1_Value_me,      /* 1781: Block Parameter */
  &gbyk_v4b_P.Constant2_Value_o,       /* 1782: Block Parameter */
  &gbyk_v4b_P.Constant3_Value_k,       /* 1783: Block Parameter */
  &gbyk_v4b_P.Send_P1_i[0],            /* 1784: Block Parameter */
  &gbyk_v4b_P.Send_P2_m,               /* 1785: Block Parameter */
  &gbyk_v4b_P.Send_P3_a,               /* 1786: Block Parameter */
  &gbyk_v4b_P.Send_P4_b,               /* 1787: Block Parameter */
  &gbyk_v4b_P.Send_P5_o,               /* 1788: Block Parameter */
  &gbyk_v4b_P.Switch_Threshold_j,      /* 1789: Block Parameter */
  &gbyk_v4b_P.DPRAMReadOffset_Value,   /* 1790: Block Parameter */
  &gbyk_v4b_P.DPRAMWatchDogoffset_Value,/* 1791: Block Parameter */
  &gbyk_v4b_P.DPRAMWriteOffset_Value,  /* 1792: Block Parameter */
  &gbyk_v4b_P.DPRAMWriteValue_Value,   /* 1793: Block Parameter */
  &gbyk_v4b_P.ReadSwitch_Value,        /* 1794: Block Parameter */
  &gbyk_v4b_P.ReadasUInt32_Value,      /* 1795: Block Parameter */
  &gbyk_v4b_P.WriteSwitch_Value,       /* 1796: Block Parameter */
  &gbyk_v4b_P.DPRAMReadValue_Gain,     /* 1797: Block Parameter */
  &gbyk_v4b_P.UnitDelay_InitialCondition_p,/* 1798: Block Parameter */
  &gbyk_v4b_P.UnitDelay1_InitialCondition,/* 1799: Block Parameter */
  &gbyk_v4b_P.WrapToZero_Threshold_k,  /* 1800: Block Parameter */
  &gbyk_v4b_P.Output_InitialCondition_p,/* 1801: Block Parameter */
  &gbyk_v4b_P.FixPtConstant_Value_n,   /* 1802: Block Parameter */
  &gbyk_v4b_P.Constant_Value_m,        /* 1803: Block Parameter */
  &gbyk_v4b_P.BKINPDOReceiveElmoDrive_P1[0],/* 1804: Block Parameter */
  &gbyk_v4b_P.BKINPDOReceiveElmoDrive_P2,/* 1805: Block Parameter */
  &gbyk_v4b_P.BKINPDOReceiveElmoDrive_P3,/* 1806: Block Parameter */
  &gbyk_v4b_P.BKINPDOReceiveElmoDrive_P4,/* 1807: Block Parameter */
  &gbyk_v4b_P.BKINPDOReceiveElmoDrive_P5,/* 1808: Block Parameter */
  &gbyk_v4b_P.BKINPDOReceiveElmoDrive_P6,/* 1809: Block Parameter */
  &gbyk_v4b_P.BKINPDOReceiveElmoDrive_P7,/* 1810: Block Parameter */
  &gbyk_v4b_P.driveID_Value,           /* 1811: Block Parameter */
  &gbyk_v4b_P.BKINPDOReceiveElmoDrive_P1_o[0],/* 1812: Block Parameter */
  &gbyk_v4b_P.BKINPDOReceiveElmoDrive_P2_f,/* 1813: Block Parameter */
  &gbyk_v4b_P.BKINPDOReceiveElmoDrive_P3_n,/* 1814: Block Parameter */
  &gbyk_v4b_P.BKINPDOReceiveElmoDrive_P4_d,/* 1815: Block Parameter */
  &gbyk_v4b_P.BKINPDOReceiveElmoDrive_P5_b,/* 1816: Block Parameter */
  &gbyk_v4b_P.BKINPDOReceiveElmoDrive_P6_m,/* 1817: Block Parameter */
  &gbyk_v4b_P.BKINPDOReceiveElmoDrive_P7_d,/* 1818: Block Parameter */
  &gbyk_v4b_P.driveID_Value_c,         /* 1819: Block Parameter */
  &gbyk_v4b_P.BKINPDOReceiveElmoDrive_P1_l[0],/* 1820: Block Parameter */
  &gbyk_v4b_P.BKINPDOReceiveElmoDrive_P2_c,/* 1821: Block Parameter */
  &gbyk_v4b_P.BKINPDOReceiveElmoDrive_P3_i,/* 1822: Block Parameter */
  &gbyk_v4b_P.BKINPDOReceiveElmoDrive_P4_m,/* 1823: Block Parameter */
  &gbyk_v4b_P.BKINPDOReceiveElmoDrive_P5_g,/* 1824: Block Parameter */
  &gbyk_v4b_P.BKINPDOReceiveElmoDrive_P6_e,/* 1825: Block Parameter */
  &gbyk_v4b_P.BKINPDOReceiveElmoDrive_P7_n,/* 1826: Block Parameter */
  &gbyk_v4b_P.driveID_Value_i,         /* 1827: Block Parameter */
  &gbyk_v4b_P.BKINPDOReceiveElmoDrive_P1_h[0],/* 1828: Block Parameter */
  &gbyk_v4b_P.BKINPDOReceiveElmoDrive_P2_h,/* 1829: Block Parameter */
  &gbyk_v4b_P.BKINPDOReceiveElmoDrive_P3_k,/* 1830: Block Parameter */
  &gbyk_v4b_P.BKINPDOReceiveElmoDrive_P4_g,/* 1831: Block Parameter */
  &gbyk_v4b_P.BKINPDOReceiveElmoDrive_P5_n,/* 1832: Block Parameter */
  &gbyk_v4b_P.BKINPDOReceiveElmoDrive_P6_n,/* 1833: Block Parameter */
  &gbyk_v4b_P.BKINPDOReceiveElmoDrive_P7_l,/* 1834: Block Parameter */
  &gbyk_v4b_P.driveID_Value_p,         /* 1835: Block Parameter */
  &gbyk_v4b_P.WrapToZero_Threshold_d,  /* 1836: Block Parameter */
  &gbyk_v4b_P.Output_InitialCondition_bg,/* 1837: Block Parameter */
  &gbyk_v4b_P.FixPtConstant_Value_j,   /* 1838: Block Parameter */
  &gbyk_v4b_P.Constant_Value_dz,       /* 1839: Block Parameter */
  &gbyk_v4b_P.Constant_Value_g0,       /* 1840: Block Parameter */
  &gbyk_v4b_P.Constant1_Value_h,       /* 1841: Block Parameter */
  &gbyk_v4b_P.Memory_X0_o2,            /* 1842: Block Parameter */
  &gbyk_v4b_P.Constant_Value_n,        /* 1843: Block Parameter */
  &gbyk_v4b_P.Memory_X0_m,             /* 1844: Block Parameter */
  &gbyk_v4b_P.Constant_Value_p,        /* 1845: Block Parameter */
  &gbyk_v4b_P.Constant1_Value_e,       /* 1846: Block Parameter */
  &gbyk_v4b_P.Memory_X0,               /* 1847: Block Parameter */
  &gbyk_v4b_P.Constant_Value_gd,       /* 1848: Block Parameter */
  &gbyk_v4b_P.Constant1_Value_h4,      /* 1849: Block Parameter */
  &gbyk_v4b_P.Memory_X0_hp,            /* 1850: Block Parameter */
  &gbyk_v4b_P.Constant_Value_i,        /* 1851: Block Parameter */
  &gbyk_v4b_P.Memory_X0_fd,            /* 1852: Block Parameter */
  &gbyk_v4b_P.Constant_Value_nx,       /* 1853: Block Parameter */
  &gbyk_v4b_P.Constant1_Value_m,       /* 1854: Block Parameter */
  &gbyk_v4b_P.Memory_X0_a,             /* 1855: Block Parameter */
  &gbyk_v4b_P.Constant_Value_lk,       /* 1856: Block Parameter */
  &gbyk_v4b_P.Constant1_Value_o,       /* 1857: Block Parameter */
  &gbyk_v4b_P.Memory_X0_co,            /* 1858: Block Parameter */
  &gbyk_v4b_P.Constant_Value_k,        /* 1859: Block Parameter */
  &gbyk_v4b_P.Memory_X0_n5,            /* 1860: Block Parameter */
  &gbyk_v4b_P.Constant_Value_c,        /* 1861: Block Parameter */
  &gbyk_v4b_P.Constant1_Value_g,       /* 1862: Block Parameter */
  &gbyk_v4b_P.Memory_X0_n,             /* 1863: Block Parameter */
  &gbyk_v4b_P.Constant_Value_ik,       /* 1864: Block Parameter */
  &gbyk_v4b_P.Constant1_Value_j,       /* 1865: Block Parameter */
  &gbyk_v4b_P.Memory_X0_er,            /* 1866: Block Parameter */
  &gbyk_v4b_P.Constant_Value_ly,       /* 1867: Block Parameter */
  &gbyk_v4b_P.Memory_X0_ic,            /* 1868: Block Parameter */
  &gbyk_v4b_P.Constant_Value_pq,       /* 1869: Block Parameter */
  &gbyk_v4b_P.Constant1_Value_ol,      /* 1870: Block Parameter */
  &gbyk_v4b_P.Memory_X0_o,             /* 1871: Block Parameter */
  &gbyk_v4b_P.FixPtConstant_Value_c,   /* 1872: Block Parameter */
  &gbyk_v4b_P.Constant_Value_j         /* 1873: Block Parameter */
};

/* Declare Data Run-Time Dimension Buffer Addresses statically */
static int32_T* rtVarDimsAddrMap[] = {
  (NULL)
};

/* Data Type Map - use dataTypeMapIndex to access this structure */
static const rtwCAPI_DataTypeMap rtDataTypeMap[] = {
  /* cName, mwName, numElements, elemMapIndex, dataSize, slDataId, *
   * isComplex, isPointer */
  { "double", "real_T", 0, 0, sizeof(real_T), SS_DOUBLE, 0, 0 },

  { "unsigned short", "uint16_T", 0, 0, sizeof(uint16_T), SS_UINT16, 0, 0 },

  { "unsigned char", "boolean_T", 0, 0, sizeof(boolean_T), SS_BOOLEAN, 0, 0 },

  { "int", "int32_T", 0, 0, sizeof(int32_T), SS_INT32, 0, 0 },

  { "unsigned int", "uint32_T", 0, 0, sizeof(uint32_T), SS_UINT32, 0, 0 },

  { "unsigned char", "uint8_T", 0, 0, sizeof(uint8_T), SS_UINT8, 0, 0 },

  { "float", "real32_T", 0, 0, sizeof(real32_T), SS_SINGLE, 0, 0 },

  { "short", "int16_T", 0, 0, sizeof(int16_T), SS_INT16, 0, 0 },

  { "signed char", "int8_T", 0, 0, sizeof(int8_T), SS_INT8, 0, 0 }
};

/* Structure Element Map - use elemMapIndex to access this structure */
static const rtwCAPI_ElementMap rtElementMap[] = {
  /* elementName, elementOffset, dataTypeIndex, dimIndex, fxpIndex */
  { NULL, 0, 0, 0, 0 },
};

/* Dimension Map - use dimensionMapIndex to access elements of ths structure*/
static const rtwCAPI_DimensionMap rtDimensionMap[] = {
  /* dataOrientation, dimArrayIndex, numDims, vardimsIndex */
  { rtwCAPI_MATRIX_COL_MAJOR, 0, 2, 0 },

  { rtwCAPI_SCALAR, 2, 2, 0 },

  { rtwCAPI_VECTOR, 4, 2, 0 },

  { rtwCAPI_VECTOR, 6, 2, 0 },

  { rtwCAPI_MATRIX_COL_MAJOR, 8, 2, 0 },

  { rtwCAPI_MATRIX_COL_MAJOR, 10, 2, 0 },

  { rtwCAPI_VECTOR, 12, 2, 0 },

  { rtwCAPI_MATRIX_COL_MAJOR, 14, 2, 0 },

  { rtwCAPI_MATRIX_COL_MAJOR, 16, 2, 0 },

  { rtwCAPI_MATRIX_COL_MAJOR, 18, 2, 0 },

  { rtwCAPI_MATRIX_COL_MAJOR, 20, 2, 0 },

  { rtwCAPI_VECTOR, 22, 2, 0 },

  { rtwCAPI_MATRIX_COL_MAJOR, 24, 2, 0 },

  { rtwCAPI_VECTOR, 26, 2, 0 },

  { rtwCAPI_MATRIX_COL_MAJOR, 28, 2, 0 },

  { rtwCAPI_MATRIX_COL_MAJOR, 30, 2, 0 },

  { rtwCAPI_MATRIX_COL_MAJOR, 32, 2, 0 },

  { rtwCAPI_MATRIX_COL_MAJOR, 34, 2, 0 },

  { rtwCAPI_MATRIX_COL_MAJOR, 36, 2, 0 },

  { rtwCAPI_VECTOR, 38, 2, 0 },

  { rtwCAPI_MATRIX_COL_MAJOR, 40, 2, 0 },

  { rtwCAPI_MATRIX_COL_MAJOR, 42, 2, 0 },

  { rtwCAPI_MATRIX_COL_MAJOR, 44, 2, 0 },

  { rtwCAPI_VECTOR, 46, 2, 0 },

  { rtwCAPI_MATRIX_COL_MAJOR, 48, 2, 0 },

  { rtwCAPI_MATRIX_COL_MAJOR, 50, 2, 0 },

  { rtwCAPI_MATRIX_COL_MAJOR, 46, 2, 0 },

  { rtwCAPI_MATRIX_COL_MAJOR, 52, 2, 0 },

  { rtwCAPI_MATRIX_COL_MAJOR, 54, 2, 0 },

  { rtwCAPI_MATRIX_COL_MAJOR, 56, 2, 0 },

  { rtwCAPI_MATRIX_COL_MAJOR, 58, 2, 0 },

  { rtwCAPI_MATRIX_COL_MAJOR, 60, 2, 0 },

  { rtwCAPI_MATRIX_COL_MAJOR, 62, 2, 0 },

  { rtwCAPI_MATRIX_COL_MAJOR, 64, 2, 0 },

  { rtwCAPI_VECTOR, 66, 2, 0 },

  { rtwCAPI_MATRIX_COL_MAJOR, 68, 2, 0 },

  { rtwCAPI_VECTOR, 70, 2, 0 },

  { rtwCAPI_VECTOR, 72, 2, 0 },

  { rtwCAPI_VECTOR, 74, 2, 0 },

  { rtwCAPI_VECTOR, 76, 2, 0 },

  { rtwCAPI_VECTOR, 78, 2, 0 },

  { rtwCAPI_VECTOR, 80, 2, 0 },

  { rtwCAPI_VECTOR, 82, 2, 0 },

  { rtwCAPI_MATRIX_COL_MAJOR, 84, 2, 0 },

  { rtwCAPI_MATRIX_COL_MAJOR, 86, 2, 0 },

  { rtwCAPI_MATRIX_COL_MAJOR, 88, 2, 0 },

  { rtwCAPI_MATRIX_COL_MAJOR, 38, 2, 0 },

  { rtwCAPI_MATRIX_COL_MAJOR, 90, 2, 0 },

  { rtwCAPI_MATRIX_COL_MAJOR, 92, 2, 0 },

  { rtwCAPI_VECTOR, 94, 2, 0 },

  { rtwCAPI_VECTOR, 96, 2, 0 },

  { rtwCAPI_VECTOR, 98, 2, 0 },

  { rtwCAPI_MATRIX_COL_MAJOR, 100, 2, 0 },

  { rtwCAPI_VECTOR, 102, 2, 0 },

  { rtwCAPI_VECTOR, 104, 2, 0 },

  { rtwCAPI_VECTOR, 106, 2, 0 },

  { rtwCAPI_VECTOR, 108, 2, 0 },

  { rtwCAPI_VECTOR, 110, 2, 0 },

  { rtwCAPI_MATRIX_COL_MAJOR, 112, 2, 0 },

  { rtwCAPI_MATRIX_COL_MAJOR, 114, 2, 0 },

  { rtwCAPI_MATRIX_COL_MAJOR, 116, 2, 0 },

  { rtwCAPI_MATRIX_COL_MAJOR, 118, 2, 0 },

  { rtwCAPI_MATRIX_COL_MAJOR, 120, 2, 0 },

  { rtwCAPI_VECTOR, 122, 2, 0 },

  { rtwCAPI_VECTOR, 124, 2, 0 },

  { rtwCAPI_VECTOR, 126, 2, 0 },

  { rtwCAPI_MATRIX_COL_MAJOR, 128, 2, 0 },

  { rtwCAPI_MATRIX_COL_MAJOR, 130, 2, 0 },

  { rtwCAPI_MATRIX_COL_MAJOR, 132, 2, 0 },

  { rtwCAPI_MATRIX_COL_MAJOR, 134, 2, 0 },

  { rtwCAPI_VECTOR, 136, 2, 0 },

  { rtwCAPI_VECTOR, 138, 2, 0 },

  { rtwCAPI_MATRIX_COL_MAJOR, 140, 2, 0 },

  { rtwCAPI_MATRIX_COL_MAJOR, 142, 2, 0 },

  { rtwCAPI_MATRIX_COL_MAJOR, 144, 2, 0 },

  { rtwCAPI_VECTOR, 16, 2, 0 },

  { rtwCAPI_VECTOR, 14, 2, 0 },

  { rtwCAPI_VECTOR, 118, 2, 0 },

  { rtwCAPI_VECTOR, 140, 2, 0 },

  { rtwCAPI_VECTOR, 62, 2, 0 },

  { rtwCAPI_VECTOR, 134, 2, 0 },

  { rtwCAPI_VECTOR, 146, 2, 0 },

  { rtwCAPI_VECTOR, 148, 2, 0 },

  { rtwCAPI_MATRIX_COL_MAJOR, 150, 2, 0 },

  { rtwCAPI_VECTOR, 28, 2, 0 },

  { rtwCAPI_MATRIX_COL_MAJOR, 152, 2, 0 },

  { rtwCAPI_VECTOR, 154, 2, 0 },

  { rtwCAPI_MATRIX_COL_MAJOR, 156, 2, 0 },

  { rtwCAPI_MATRIX_COL_MAJOR, 158, 2, 0 },

  { rtwCAPI_MATRIX_COL_MAJOR, 160, 2, 0 },

  { rtwCAPI_VECTOR, 162, 2, 0 },

  { rtwCAPI_MATRIX_COL_MAJOR, 164, 2, 0 },

  { rtwCAPI_VECTOR, 166, 2, 0 },

  { rtwCAPI_VECTOR, 168, 2, 0 },

  { rtwCAPI_VECTOR, 170, 2, 0 },

  { rtwCAPI_VECTOR, 172, 2, 0 },

  { rtwCAPI_VECTOR, 174, 2, 0 },

  { rtwCAPI_VECTOR, 176, 2, 0 },

  { rtwCAPI_VECTOR, 178, 2, 0 },

  { rtwCAPI_VECTOR, 180, 2, 0 },

  { rtwCAPI_VECTOR, 182, 2, 0 },

  { rtwCAPI_VECTOR, 184, 2, 0 }
};

/* Dimension Array- use dimArrayIndex to access elements of this array */
static const uint_T rtDimensionArray[] = {
  2,                                   /* 0 */
  70,                                  /* 1 */
  1,                                   /* 2 */
  1,                                   /* 3 */
  2,                                   /* 4 */
  1,                                   /* 5 */
  4,                                   /* 6 */
  1,                                   /* 7 */
  60,                                  /* 8 */
  2,                                   /* 9 */
  10,                                  /* 10 */
  70,                                  /* 11 */
  20,                                  /* 12 */
  1,                                   /* 13 */
  1,                                   /* 14 */
  3,                                   /* 15 */
  1,                                   /* 16 */
  2,                                   /* 17 */
  1,                                   /* 18 */
  499,                                 /* 19 */
  60,                                  /* 20 */
  1,                                   /* 21 */
  8,                                   /* 22 */
  1,                                   /* 23 */
  1,                                   /* 24 */
  18,                                  /* 25 */
  17,                                  /* 26 */
  1,                                   /* 27 */
  1,                                   /* 28 */
  70,                                  /* 29 */
  50,                                  /* 30 */
  500,                                 /* 31 */
  1000,                                /* 32 */
  2,                                   /* 33 */
  10,                                  /* 34 */
  20,                                  /* 35 */
  32,                                  /* 36 */
  25,                                  /* 37 */
  50,                                  /* 38 */
  1,                                   /* 39 */
  100,                                 /* 40 */
  50,                                  /* 41 */
  5,                                   /* 42 */
  2,                                   /* 43 */
  1,                                   /* 44 */
  50,                                  /* 45 */
  32,                                  /* 46 */
  1,                                   /* 47 */
  3,                                   /* 48 */
  2,                                   /* 49 */
  32,                                  /* 50 */
  5,                                   /* 51 */
  70,                                  /* 52 */
  19,                                  /* 53 */
  5,                                   /* 54 */
  11,                                  /* 55 */
  1,                                   /* 56 */
  25,                                  /* 57 */
  2,                                   /* 58 */
  25,                                  /* 59 */
  1,                                   /* 60 */
  10,                                  /* 61 */
  1,                                   /* 62 */
  4,                                   /* 63 */
  1,                                   /* 64 */
  68,                                  /* 65 */
  6,                                   /* 66 */
  1,                                   /* 67 */
  1,                                   /* 68 */
  40,                                  /* 69 */
  13,                                  /* 70 */
  1,                                   /* 71 */
  14,                                  /* 72 */
  1,                                   /* 73 */
  40,                                  /* 74 */
  1,                                   /* 75 */
  410,                                 /* 76 */
  1,                                   /* 77 */
  34,                                  /* 78 */
  1,                                   /* 79 */
  3,                                   /* 80 */
  1,                                   /* 81 */
  512,                                 /* 82 */
  1,                                   /* 83 */
  2,                                   /* 84 */
  4,                                   /* 85 */
  1,                                   /* 86 */
  352,                                 /* 87 */
  2,                                   /* 88 */
  5,                                   /* 89 */
  1,                                   /* 90 */
  500,                                 /* 91 */
  1000,                                /* 92 */
  1,                                   /* 93 */
  27240,                               /* 94 */
  1,                                   /* 95 */
  5,                                   /* 96 */
  1,                                   /* 97 */
  6810,                                /* 98 */
  1,                                   /* 99 */
  1,                                   /* 100 */
  127,                                 /* 101 */
  400,                                 /* 102 */
  1,                                   /* 103 */
  21,                                  /* 104 */
  1,                                   /* 105 */
  1640,                                /* 106 */
  1,                                   /* 107 */
  64,                                  /* 108 */
  1,                                   /* 109 */
  12,                                  /* 110 */
  1,                                   /* 111 */
  12,                                  /* 112 */
  2,                                   /* 113 */
  3,                                   /* 114 */
  50,                                  /* 115 */
  2,                                   /* 116 */
  6,                                   /* 117 */
  1,                                   /* 118 */
  6,                                   /* 119 */
  4,                                   /* 120 */
  5,                                   /* 121 */
  16,                                  /* 122 */
  1,                                   /* 123 */
  24,                                  /* 124 */
  1,                                   /* 125 */
  7,                                   /* 126 */
  1,                                   /* 127 */
  1,                                   /* 128 */
  20,                                  /* 129 */
  1,                                   /* 130 */
  24,                                  /* 131 */
  1,                                   /* 132 */
  16,                                  /* 133 */
  1,                                   /* 134 */
  8,                                   /* 135 */
  36,                                  /* 136 */
  1,                                   /* 137 */
  10,                                  /* 138 */
  1,                                   /* 139 */
  1,                                   /* 140 */
  7,                                   /* 141 */
  8,                                   /* 142 */
  3,                                   /* 143 */
  6,                                   /* 144 */
  2,                                   /* 145 */
  1,                                   /* 146 */
  14,                                  /* 147 */
  1,                                   /* 148 */
  9,                                   /* 149 */
  50,                                  /* 150 */
  50,                                  /* 151 */
  70,                                  /* 152 */
  9,                                   /* 153 */
  1,                                   /* 154 */
  11,                                  /* 155 */
  5,                                   /* 156 */
  5,                                   /* 157 */
  5,                                   /* 158 */
  4,                                   /* 159 */
  5,                                   /* 160 */
  7,                                   /* 161 */
  1,                                   /* 162 */
  5,                                   /* 163 */
  6,                                   /* 164 */
  8,                                   /* 165 */
  1,                                   /* 166 */
  34,                                  /* 167 */
  1,                                   /* 168 */
  400,                                 /* 169 */
  1,                                   /* 170 */
  15,                                  /* 171 */
  1,                                   /* 172 */
  13,                                  /* 173 */
  1,                                   /* 174 */
  48,                                  /* 175 */
  1,                                   /* 176 */
  46,                                  /* 177 */
  1,                                   /* 178 */
  12,                                  /* 179 */
  1,                                   /* 180 */
  42,                                  /* 181 */
  1,                                   /* 182 */
  41,                                  /* 183 */
  1,                                   /* 184 */
  39                                   /* 185 */
};

/* C-API stores floating point values in an array. The elements of this  *
 * are unique. This ensures that values which are shared across the model*
 * are stored in the most efficient way. These values are referenced by  *
 *           - rtwCAPI_FixPtMap.fracSlopePtr,                            *
 *           - rtwCAPI_FixPtMap.biasPtr,                                 *
 *           - rtwCAPI_SampleTimeMap.samplePeriodPtr,                    *
 *           - rtwCAPI_SampleTimeMap.sampleOffsetPtr                     */
static const real_T rtcapiStoredFloats[] = {
  0.00025, 0.0, 0.001, 0.002, 0.1, 0.0005
};

/* Fixed Point Map */
static const rtwCAPI_FixPtMap rtFixPtMap[] = {
  /* fracSlopePtr, biasPtr, scaleType, wordLength, exponent, isSigned */
  { NULL, NULL, rtwCAPI_FIX_RESERVED, 0, 0, 0 },
};

/* Sample Time Map - use sTimeIndex to access elements of ths structure */
static const rtwCAPI_SampleTimeMap rtSampleTimeMap[] = {
  /* samplePeriodPtr, sampleOffsetPtr, tid, samplingMode */
  { (const void *) &rtcapiStoredFloats[0], (const void *) &rtcapiStoredFloats[1],
    1, 0 },

  { (NULL), (NULL), -1, 0 },

  { (const void *) &rtcapiStoredFloats[2], (const void *) &rtcapiStoredFloats[1],
    3, 0 },

  { (const void *) &rtcapiStoredFloats[3], (const void *) &rtcapiStoredFloats[1],
    4, 0 },

  { (NULL), (NULL), -2, 0 },

  { (const void *) &rtcapiStoredFloats[4], (const void *) &rtcapiStoredFloats[1],
    5, 0 },

  { (const void *) &rtcapiStoredFloats[5], (const void *) &rtcapiStoredFloats[1],
    2, 0 }
};

static rtwCAPI_ModelMappingStaticInfo mmiStatic = {
  /* Signals:{signals, numSignals},
   * Params: {blockParameters, numBlockParameters,
   *          modelParameters, numModelParameters},
   * States: {states, numStates},
   * Maps:   {dataTypeMap, dimensionMap, fixPtMap,
   *          elementMap, sampleTimeMap, dimensionArray},
   * TargetType: targetType
   */
  { rtBlockSignals, 1165 },

  { rtBlockParameters, 709,
    rtModelParameters, 0 },

  { NULL, 0 },

  { rtDataTypeMap, rtDimensionMap, rtFixPtMap,
    rtElementMap, rtSampleTimeMap, rtDimensionArray },
  "float",

  { 1406322799U,
    1312750509U,
    455964919U,
    4125117104U },
  NULL
};

/* Cache pointers into DataMapInfo substructure of RTModel */
void gbyk_v4b_InitializeDataMapInfo(RT_MODEL_gbyk_v4b_T *gbyk_v4b_M
  )
{
  /* Set C-API version */
  rtwCAPI_SetVersion(gbyk_v4b_M->DataMapInfo.mmi, 1);

  /* Cache static C-API data into the Real-time Model Data structure */
  rtwCAPI_SetStaticMap(gbyk_v4b_M->DataMapInfo.mmi, &mmiStatic);

  /* Cache static C-API logging data into the Real-time Model Data structure */
  rtwCAPI_SetLoggingStaticMap(gbyk_v4b_M->DataMapInfo.mmi, NULL);

  /* Cache C-API Data Addresses into the Real-Time Model Data structure */
  rtwCAPI_SetDataAddressMap(gbyk_v4b_M->DataMapInfo.mmi, rtDataAddrMap);

  /* Cache C-API Data Run-Time Dimension Buffer Addresses into the Real-Time Model Data structure */
  rtwCAPI_SetVarDimsAddressMap(gbyk_v4b_M->DataMapInfo.mmi, rtVarDimsAddrMap);

  /* Cache C-API rtp Address and size  into the Real-Time Model Data structure */
  gbyk_v4b_M->DataMapInfo.mmi.InstanceMap.rtpAddress = rtmGetDefaultParam
    (gbyk_v4b_M);
  gbyk_v4b_M->DataMapInfo.mmi.staticMap->rtpSize = sizeof(P_gbyk_v4b_T);

  /* Cache the instance C-API logging pointer */
  rtwCAPI_SetInstanceLoggingInfo(gbyk_v4b_M->DataMapInfo.mmi, NULL);

  /* Set Reference to submodels */
  rtwCAPI_SetChildMMIArray(gbyk_v4b_M->DataMapInfo.mmi, NULL);
  rtwCAPI_SetChildMMIArrayLen(gbyk_v4b_M->DataMapInfo.mmi, 0);
}

/* EOF: gbyk_v4b_capi.c */
