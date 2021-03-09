/*
 * gbyk_v4b.h
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

#ifndef RTW_HEADER_gbyk_v4b_h_
#define RTW_HEADER_gbyk_v4b_h_
#include <stddef.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include "rtw_modelmap.h"
#ifndef gbyk_v4b_COMMON_INCLUDES_
# define gbyk_v4b_COMMON_INCLUDES_
#include <xpcimports.h>
#include <xpcdatatypes.h>
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rt_logging.h"
#include "stddef.h"
#include "stdlib.h"
#include "xpcethercatutils.h"
#include "xpctarget.h"
#include "BKINethercat.h"
#include "io_config_xml_1.h"
#include "io_config_xml_0.h"
#endif                                 /* gbyk_v4b_COMMON_INCLUDES_ */

#include "gbyk_v4b_types.h"

/* Shared type includes */
#include "multiword_types.h"

/* Child system includes */
#include "gbyk_v4b_EmbeddedMATLABInsideTarget.h"
#include "gbyk_v4b_EmbeddedMATLABInsideTarget_m.h"
#include "gbyk_v4b_FeedFwdArm.h"
#include "gbyk_v4b_Keepalive.h"
#include "gbyk_v4b_NetworkTransferSubsystem.h"
#include "gbyk_v4b_PVC_core.h"
#include "gbyk_v4b_PollForcePlates.h"
#include "gbyk_v4b_PollKINARM.h"
#include "gbyk_v4b_PreviewTargetsSubsystem.h"
#include "gbyk_v4b_Receive_Gaze.h"
#include "gbyk_v4b_TaskExecutionControlSubsystem.h"
#include "gbyk_v4b_applyloads.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rt_defines.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlkStateChangeFlag
# define rtmGetBlkStateChangeFlag(rtm) ((rtm)->ModelData.blkStateChange)
#endif

#ifndef rtmSetBlkStateChangeFlag
# define rtmSetBlkStateChangeFlag(rtm, val) ((rtm)->ModelData.blkStateChange = (val))
#endif

#ifndef rtmGetBlockIO
# define rtmGetBlockIO(rtm)            ((rtm)->ModelData.blockIO)
#endif

#ifndef rtmSetBlockIO
# define rtmSetBlockIO(rtm, val)       ((rtm)->ModelData.blockIO = (val))
#endif

#ifndef rtmGetChecksums
# define rtmGetChecksums(rtm)          ((rtm)->Sizes.checksums)
#endif

#ifndef rtmSetChecksums
# define rtmSetChecksums(rtm, val)     ((rtm)->Sizes.checksums = (val))
#endif

#ifndef rtmGetConstBlockIO
# define rtmGetConstBlockIO(rtm)       ((rtm)->ModelData.constBlockIO)
#endif

#ifndef rtmSetConstBlockIO
# define rtmSetConstBlockIO(rtm, val)  ((rtm)->ModelData.constBlockIO = (val))
#endif

#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->ModelData.contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->ModelData.contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->ModelData.contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->ModelData.contStates = (val))
#endif

#ifndef rtmGetDataMapInfo
# define rtmGetDataMapInfo(rtm)        ((rtm)->DataMapInfo)
#endif

#ifndef rtmSetDataMapInfo
# define rtmSetDataMapInfo(rtm, val)   ((rtm)->DataMapInfo = (val))
#endif

#ifndef rtmGetDefaultParam
# define rtmGetDefaultParam(rtm)       ((rtm)->ModelData.defaultParam)
#endif

#ifndef rtmSetDefaultParam
# define rtmSetDefaultParam(rtm, val)  ((rtm)->ModelData.defaultParam = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->ModelData.derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->ModelData.derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetDirectFeedThrough
# define rtmGetDirectFeedThrough(rtm)  ((rtm)->Sizes.sysDirFeedThru)
#endif

#ifndef rtmSetDirectFeedThrough
# define rtmSetDirectFeedThrough(rtm, val) ((rtm)->Sizes.sysDirFeedThru = (val))
#endif

#ifndef rtmGetErrorStatusFlag
# define rtmGetErrorStatusFlag(rtm)    ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatusFlag
# define rtmSetErrorStatusFlag(rtm, val) ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetFinalTime
# define rtmSetFinalTime(rtm, val)     ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetFirstInitCondFlag
# define rtmGetFirstInitCondFlag(rtm)  ()
#endif

#ifndef rtmSetFirstInitCondFlag
# define rtmSetFirstInitCondFlag(rtm, val) ()
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ()
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ()
#endif

#ifndef rtmGetMdlRefGlobalTID
# define rtmGetMdlRefGlobalTID(rtm)    ()
#endif

#ifndef rtmSetMdlRefGlobalTID
# define rtmSetMdlRefGlobalTID(rtm, val) ()
#endif

#ifndef rtmGetMdlRefTriggerTID
# define rtmGetMdlRefTriggerTID(rtm)   ()
#endif

#ifndef rtmSetMdlRefTriggerTID
# define rtmSetMdlRefTriggerTID(rtm, val) ()
#endif

#ifndef rtmGetModelMappingInfo
# define rtmGetModelMappingInfo(rtm)   ((rtm)->SpecialInfo.mappingInfo)
#endif

#ifndef rtmSetModelMappingInfo
# define rtmSetModelMappingInfo(rtm, val) ((rtm)->SpecialInfo.mappingInfo = (val))
#endif

#ifndef rtmGetModelName
# define rtmGetModelName(rtm)          ((rtm)->modelName)
#endif

#ifndef rtmSetModelName
# define rtmSetModelName(rtm, val)     ((rtm)->modelName = (val))
#endif

#ifndef rtmGetNonInlinedSFcns
# define rtmGetNonInlinedSFcns(rtm)    ((rtm)->NonInlinedSFcns)
#endif

#ifndef rtmSetNonInlinedSFcns
# define rtmSetNonInlinedSFcns(rtm, val) ((rtm)->NonInlinedSFcns = (val))
#endif

#ifndef rtmGetNumBlockIO
# define rtmGetNumBlockIO(rtm)         ((rtm)->Sizes.numBlockIO)
#endif

#ifndef rtmSetNumBlockIO
# define rtmSetNumBlockIO(rtm, val)    ((rtm)->Sizes.numBlockIO = (val))
#endif

#ifndef rtmGetNumBlockParams
# define rtmGetNumBlockParams(rtm)     ((rtm)->Sizes.numBlockPrms)
#endif

#ifndef rtmSetNumBlockParams
# define rtmSetNumBlockParams(rtm, val) ((rtm)->Sizes.numBlockPrms = (val))
#endif

#ifndef rtmGetNumBlocks
# define rtmGetNumBlocks(rtm)          ((rtm)->Sizes.numBlocks)
#endif

#ifndef rtmSetNumBlocks
# define rtmSetNumBlocks(rtm, val)     ((rtm)->Sizes.numBlocks = (val))
#endif

#ifndef rtmGetNumContStates
# define rtmGetNumContStates(rtm)      ((rtm)->Sizes.numContStates)
#endif

#ifndef rtmSetNumContStates
# define rtmSetNumContStates(rtm, val) ((rtm)->Sizes.numContStates = (val))
#endif

#ifndef rtmGetNumDWork
# define rtmGetNumDWork(rtm)           ((rtm)->Sizes.numDwork)
#endif

#ifndef rtmSetNumDWork
# define rtmSetNumDWork(rtm, val)      ((rtm)->Sizes.numDwork = (val))
#endif

#ifndef rtmGetNumInputPorts
# define rtmGetNumInputPorts(rtm)      ((rtm)->Sizes.numIports)
#endif

#ifndef rtmSetNumInputPorts
# define rtmSetNumInputPorts(rtm, val) ((rtm)->Sizes.numIports = (val))
#endif

#ifndef rtmGetNumNonSampledZCs
# define rtmGetNumNonSampledZCs(rtm)   ((rtm)->Sizes.numNonSampZCs)
#endif

#ifndef rtmSetNumNonSampledZCs
# define rtmSetNumNonSampledZCs(rtm, val) ((rtm)->Sizes.numNonSampZCs = (val))
#endif

#ifndef rtmGetNumOutputPorts
# define rtmGetNumOutputPorts(rtm)     ((rtm)->Sizes.numOports)
#endif

#ifndef rtmSetNumOutputPorts
# define rtmSetNumOutputPorts(rtm, val) ((rtm)->Sizes.numOports = (val))
#endif

#ifndef rtmGetNumPeriodicContStates
# define rtmGetNumPeriodicContStates(rtm) ((rtm)->Sizes.numPeriodicContStates)
#endif

#ifndef rtmSetNumPeriodicContStates
# define rtmSetNumPeriodicContStates(rtm, val) ((rtm)->Sizes.numPeriodicContStates = (val))
#endif

#ifndef rtmGetNumSFcnParams
# define rtmGetNumSFcnParams(rtm)      ((rtm)->Sizes.numSFcnPrms)
#endif

#ifndef rtmSetNumSFcnParams
# define rtmSetNumSFcnParams(rtm, val) ((rtm)->Sizes.numSFcnPrms = (val))
#endif

#ifndef rtmGetNumSFunctions
# define rtmGetNumSFunctions(rtm)      ((rtm)->Sizes.numSFcns)
#endif

#ifndef rtmSetNumSFunctions
# define rtmSetNumSFunctions(rtm, val) ((rtm)->Sizes.numSFcns = (val))
#endif

#ifndef rtmGetNumSampleTimes
# define rtmGetNumSampleTimes(rtm)     ((rtm)->Sizes.numSampTimes)
#endif

#ifndef rtmSetNumSampleTimes
# define rtmSetNumSampleTimes(rtm, val) ((rtm)->Sizes.numSampTimes = (val))
#endif

#ifndef rtmGetNumU
# define rtmGetNumU(rtm)               ((rtm)->Sizes.numU)
#endif

#ifndef rtmSetNumU
# define rtmSetNumU(rtm, val)          ((rtm)->Sizes.numU = (val))
#endif

#ifndef rtmGetNumY
# define rtmGetNumY(rtm)               ((rtm)->Sizes.numY)
#endif

#ifndef rtmSetNumY
# define rtmSetNumY(rtm, val)          ((rtm)->Sizes.numY = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ()
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ()
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ()
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ()
#endif

#ifndef rtmGetOffsetTimeArray
# define rtmGetOffsetTimeArray(rtm)    ((rtm)->Timing.offsetTimesArray)
#endif

#ifndef rtmSetOffsetTimeArray
# define rtmSetOffsetTimeArray(rtm, val) ((rtm)->Timing.offsetTimesArray = (val))
#endif

#ifndef rtmGetOffsetTimePtr
# define rtmGetOffsetTimePtr(rtm)      ((rtm)->Timing.offsetTimes)
#endif

#ifndef rtmSetOffsetTimePtr
# define rtmSetOffsetTimePtr(rtm, val) ((rtm)->Timing.offsetTimes = (val))
#endif

#ifndef rtmGetOptions
# define rtmGetOptions(rtm)            ((rtm)->Sizes.options)
#endif

#ifndef rtmSetOptions
# define rtmSetOptions(rtm, val)       ((rtm)->Sizes.options = (val))
#endif

#ifndef rtmGetParamIsMalloced
# define rtmGetParamIsMalloced(rtm)    ()
#endif

#ifndef rtmSetParamIsMalloced
# define rtmSetParamIsMalloced(rtm, val) ()
#endif

#ifndef rtmGetPath
# define rtmGetPath(rtm)               ((rtm)->path)
#endif

#ifndef rtmSetPath
# define rtmSetPath(rtm, val)          ((rtm)->path = (val))
#endif

#ifndef rtmGetPerTaskSampleHits
# define rtmGetPerTaskSampleHits(rtm)  ((rtm)->Timing.RateInteraction)
#endif

#ifndef rtmSetPerTaskSampleHits
# define rtmSetPerTaskSampleHits(rtm, val) ((rtm)->Timing.RateInteraction = (val))
#endif

#ifndef rtmGetPerTaskSampleHitsArray
# define rtmGetPerTaskSampleHitsArray(rtm) ((rtm)->Timing.perTaskSampleHitsArray)
#endif

#ifndef rtmSetPerTaskSampleHitsArray
# define rtmSetPerTaskSampleHitsArray(rtm, val) ((rtm)->Timing.perTaskSampleHitsArray = (val))
#endif

#ifndef rtmGetPerTaskSampleHitsPtr
# define rtmGetPerTaskSampleHitsPtr(rtm) ((rtm)->Timing.perTaskSampleHits)
#endif

#ifndef rtmSetPerTaskSampleHitsPtr
# define rtmSetPerTaskSampleHitsPtr(rtm, val) ((rtm)->Timing.perTaskSampleHits = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
# define rtmGetPeriodicContStateIndices(rtm) ((rtm)->ModelData.periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
# define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->ModelData.periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
# define rtmGetPeriodicContStateRanges(rtm) ((rtm)->ModelData.periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
# define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->ModelData.periodicContStateRanges = (val))
#endif

#ifndef rtmGetPrevZCSigState
# define rtmGetPrevZCSigState(rtm)     ((rtm)->ModelData.prevZCSigState)
#endif

#ifndef rtmSetPrevZCSigState
# define rtmSetPrevZCSigState(rtm, val) ((rtm)->ModelData.prevZCSigState = (val))
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmSetRTWExtModeInfo
# define rtmSetRTWExtModeInfo(rtm, val) ((rtm)->extModeInfo = (val))
#endif

#ifndef rtmGetRTWGeneratedSFcn
# define rtmGetRTWGeneratedSFcn(rtm)   ((rtm)->Sizes.rtwGenSfcn)
#endif

#ifndef rtmSetRTWGeneratedSFcn
# define rtmSetRTWGeneratedSFcn(rtm, val) ((rtm)->Sizes.rtwGenSfcn = (val))
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmSetRTWLogInfo
# define rtmSetRTWLogInfo(rtm, val)    ((rtm)->rtwLogInfo = (val))
#endif

#ifndef rtmGetRTWRTModelMethodsInfo
# define rtmGetRTWRTModelMethodsInfo(rtm) ()
#endif

#ifndef rtmSetRTWRTModelMethodsInfo
# define rtmSetRTWRTModelMethodsInfo(rtm, val) ()
#endif

#ifndef rtmGetRTWSfcnInfo
# define rtmGetRTWSfcnInfo(rtm)        ((rtm)->sfcnInfo)
#endif

#ifndef rtmSetRTWSfcnInfo
# define rtmSetRTWSfcnInfo(rtm, val)   ((rtm)->sfcnInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfo
# define rtmGetRTWSolverInfo(rtm)      ((rtm)->solverInfo)
#endif

#ifndef rtmSetRTWSolverInfo
# define rtmSetRTWSolverInfo(rtm, val) ((rtm)->solverInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfoPtr
# define rtmGetRTWSolverInfoPtr(rtm)   ((rtm)->solverInfoPtr)
#endif

#ifndef rtmSetRTWSolverInfoPtr
# define rtmSetRTWSolverInfoPtr(rtm, val) ((rtm)->solverInfoPtr = (val))
#endif

#ifndef rtmGetReservedForXPC
# define rtmGetReservedForXPC(rtm)     ((rtm)->SpecialInfo.xpcData)
#endif

#ifndef rtmSetReservedForXPC
# define rtmSetReservedForXPC(rtm, val) ((rtm)->SpecialInfo.xpcData = (val))
#endif

#ifndef rtmGetRootDWork
# define rtmGetRootDWork(rtm)          ((rtm)->ModelData.dwork)
#endif

#ifndef rtmSetRootDWork
# define rtmSetRootDWork(rtm, val)     ((rtm)->ModelData.dwork = (val))
#endif

#ifndef rtmGetSFunctions
# define rtmGetSFunctions(rtm)         ((rtm)->childSfunctions)
#endif

#ifndef rtmSetSFunctions
# define rtmSetSFunctions(rtm, val)    ((rtm)->childSfunctions = (val))
#endif

#ifndef rtmGetSampleHitArray
# define rtmGetSampleHitArray(rtm)     ((rtm)->Timing.sampleHitArray)
#endif

#ifndef rtmSetSampleHitArray
# define rtmSetSampleHitArray(rtm, val) ((rtm)->Timing.sampleHitArray = (val))
#endif

#ifndef rtmGetSampleHitPtr
# define rtmGetSampleHitPtr(rtm)       ((rtm)->Timing.sampleHits)
#endif

#ifndef rtmSetSampleHitPtr
# define rtmSetSampleHitPtr(rtm, val)  ((rtm)->Timing.sampleHits = (val))
#endif

#ifndef rtmGetSampleTimeArray
# define rtmGetSampleTimeArray(rtm)    ((rtm)->Timing.sampleTimesArray)
#endif

#ifndef rtmSetSampleTimeArray
# define rtmSetSampleTimeArray(rtm, val) ((rtm)->Timing.sampleTimesArray = (val))
#endif

#ifndef rtmGetSampleTimePtr
# define rtmGetSampleTimePtr(rtm)      ((rtm)->Timing.sampleTimes)
#endif

#ifndef rtmSetSampleTimePtr
# define rtmSetSampleTimePtr(rtm, val) ((rtm)->Timing.sampleTimes = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDArray
# define rtmGetSampleTimeTaskIDArray(rtm) ((rtm)->Timing.sampleTimeTaskIDArray)
#endif

#ifndef rtmSetSampleTimeTaskIDArray
# define rtmSetSampleTimeTaskIDArray(rtm, val) ((rtm)->Timing.sampleTimeTaskIDArray = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDPtr
# define rtmGetSampleTimeTaskIDPtr(rtm) ((rtm)->Timing.sampleTimeTaskIDPtr)
#endif

#ifndef rtmSetSampleTimeTaskIDPtr
# define rtmSetSampleTimeTaskIDPtr(rtm, val) ((rtm)->Timing.sampleTimeTaskIDPtr = (val))
#endif

#ifndef rtmGetSimMode
# define rtmGetSimMode(rtm)            ((rtm)->simMode)
#endif

#ifndef rtmSetSimMode
# define rtmSetSimMode(rtm, val)       ((rtm)->simMode = (val))
#endif

#ifndef rtmGetSimTimeStep
# define rtmGetSimTimeStep(rtm)        ((rtm)->Timing.simTimeStep)
#endif

#ifndef rtmSetSimTimeStep
# define rtmSetSimTimeStep(rtm, val)   ((rtm)->Timing.simTimeStep = (val))
#endif

#ifndef rtmGetStartTime
# define rtmGetStartTime(rtm)          ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetStartTime
# define rtmSetStartTime(rtm, val)     ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetStepSize
# define rtmGetStepSize(rtm)           ((rtm)->Timing.stepSize)
#endif

#ifndef rtmSetStepSize
# define rtmSetStepSize(rtm, val)      ((rtm)->Timing.stepSize = (val))
#endif

#ifndef rtmGetStopRequestedFlag
# define rtmGetStopRequestedFlag(rtm)  ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequestedFlag
# define rtmSetStopRequestedFlag(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetTaskCounters
# define rtmGetTaskCounters(rtm)       ((rtm)->Timing.TaskCounters)
#endif

#ifndef rtmSetTaskCounters
# define rtmSetTaskCounters(rtm, val)  ((rtm)->Timing.TaskCounters = (val))
#endif

#ifndef rtmGetTaskTimeArray
# define rtmGetTaskTimeArray(rtm)      ((rtm)->Timing.tArray)
#endif

#ifndef rtmSetTaskTimeArray
# define rtmSetTaskTimeArray(rtm, val) ((rtm)->Timing.tArray = (val))
#endif

#ifndef rtmGetTimePtr
# define rtmGetTimePtr(rtm)            ((rtm)->Timing.t)
#endif

#ifndef rtmSetTimePtr
# define rtmSetTimePtr(rtm, val)       ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTimingData
# define rtmGetTimingData(rtm)         ((rtm)->Timing.timingData)
#endif

#ifndef rtmSetTimingData
# define rtmSetTimingData(rtm, val)    ((rtm)->Timing.timingData = (val))
#endif

#ifndef rtmGetU
# define rtmGetU(rtm)                  ((rtm)->ModelData.inputs)
#endif

#ifndef rtmSetU
# define rtmSetU(rtm, val)             ((rtm)->ModelData.inputs = (val))
#endif

#ifndef rtmGetVarNextHitTimesListPtr
# define rtmGetVarNextHitTimesListPtr(rtm) ((rtm)->Timing.varNextHitTimesList)
#endif

#ifndef rtmSetVarNextHitTimesListPtr
# define rtmSetVarNextHitTimesListPtr(rtm, val) ((rtm)->Timing.varNextHitTimesList = (val))
#endif

#ifndef rtmGetY
# define rtmGetY(rtm)                  ((rtm)->ModelData.outputs)
#endif

#ifndef rtmSetY
# define rtmSetY(rtm, val)             ((rtm)->ModelData.outputs = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->ModelData.zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->ModelData.zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetZCSignalValues
# define rtmGetZCSignalValues(rtm)     ((rtm)->ModelData.zcSignalValues)
#endif

#ifndef rtmSetZCSignalValues
# define rtmSetZCSignalValues(rtm, val) ((rtm)->ModelData.zcSignalValues = (val))
#endif

#ifndef rtmGet_TimeOfLastOutput
# define rtmGet_TimeOfLastOutput(rtm)  ((rtm)->Timing.timeOfLastOutput)
#endif

#ifndef rtmSet_TimeOfLastOutput
# define rtmSet_TimeOfLastOutput(rtm, val) ((rtm)->Timing.timeOfLastOutput = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->ModelData.derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->ModelData.derivs = (val))
#endif

#ifndef rtmGetChecksumVal
# define rtmGetChecksumVal(rtm, idx)   ((rtm)->Sizes.checksums[idx])
#endif

#ifndef rtmSetChecksumVal
# define rtmSetChecksumVal(rtm, idx, val) ((rtm)->Sizes.checksums[idx] = (val))
#endif

#ifndef rtmGetDWork
# define rtmGetDWork(rtm, idx)         ((rtm)->ModelData.dwork[idx])
#endif

#ifndef rtmSetDWork
# define rtmSetDWork(rtm, idx, val)    ((rtm)->ModelData.dwork[idx] = (val))
#endif

#ifndef rtmGetOffsetTime
# define rtmGetOffsetTime(rtm, idx)    ((rtm)->Timing.offsetTimes[idx])
#endif

#ifndef rtmSetOffsetTime
# define rtmSetOffsetTime(rtm, idx, val) ((rtm)->Timing.offsetTimes[idx] = (val))
#endif

#ifndef rtmGetSFunction
# define rtmGetSFunction(rtm, idx)     ((rtm)->childSfunctions[idx])
#endif

#ifndef rtmSetSFunction
# define rtmSetSFunction(rtm, idx, val) ((rtm)->childSfunctions[idx] = (val))
#endif

#ifndef rtmGetSampleTime
# define rtmGetSampleTime(rtm, idx)    ((rtm)->Timing.sampleTimes[idx])
#endif

#ifndef rtmSetSampleTime
# define rtmSetSampleTime(rtm, idx, val) ((rtm)->Timing.sampleTimes[idx] = (val))
#endif

#ifndef rtmGetSampleTimeTaskID
# define rtmGetSampleTimeTaskID(rtm, idx) ((rtm)->Timing.sampleTimeTaskIDPtr[idx])
#endif

#ifndef rtmSetSampleTimeTaskID
# define rtmSetSampleTimeTaskID(rtm, idx, val) ((rtm)->Timing.sampleTimeTaskIDPtr[idx] = (val))
#endif

#ifndef rtmGetVarNextHitTimeList
# define rtmGetVarNextHitTimeList(rtm, idx) ((rtm)->Timing.varNextHitTimesList[idx])
#endif

#ifndef rtmSetVarNextHitTimeList
# define rtmSetVarNextHitTimeList(rtm, idx, val) ((rtm)->Timing.varNextHitTimesList[idx] = (val))
#endif

#ifndef rtmIsContinuousTask
# define rtmIsContinuousTask(rtm, tid) ((tid) <= 1)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmIsMajorTimeStep
# define rtmIsMajorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
# define rtmIsMinorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmIsSampleHit
# define rtmIsSampleHit(rtm, sti, tid) (((rtm)->Timing.sampleTimeTaskIDPtr[sti] == (tid)))
#endif

#ifndef rtmStepTask
# define rtmStepTask(rtm, idx)         ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmSetT
# define rtmSetT(rtm, val)                                       /* Do Nothing */
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTStart
# define rtmGetTStart(rtm)             ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetTStart
# define rtmSetTStart(rtm, val)        ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmTaskCounter
# define rtmTaskCounter(rtm, idx)      ((rtm)->Timing.TaskCounters.TID[(idx)])
#endif

#ifndef rtmGetTaskTime
# define rtmGetTaskTime(rtm, sti)      (rtmGetTPtr((rtm))[(rtm)->Timing.sampleTimeTaskIDPtr[sti]])
#endif

#ifndef rtmSetTaskTime
# define rtmSetTaskTime(rtm, sti, val) (rtmGetTPtr((rtm))[sti] = (val))
#endif

#ifndef rtmGetTimeOfLastOutput
# define rtmGetTimeOfLastOutput(rtm)   ((rtm)->Timing.timeOfLastOutput)
#endif

#ifdef rtmGetRTWSolverInfo
#undef rtmGetRTWSolverInfo
#endif

#define rtmGetRTWSolverInfo(rtm)       &((rtm)->solverInfo)
#define rtModel_gbyk_v4b               RT_MODEL_gbyk_v4b_T

/* Definition for use in the target main file */
#define gbyk_v4b_rtModel               RT_MODEL_gbyk_v4b_T

/* user code (top of export header file) */
#include "xpcdatatypes.h"

/* Block signals for system '<S259>/MATLAB Function' */
typedef struct {
  real_T is_right_arm;                 /* '<S259>/MATLAB Function' */
  real_T isExo;                        /* '<S259>/MATLAB Function' */
  real_T has_high_res_encoders;        /* '<S259>/MATLAB Function' */
} B_MATLABFunction_gbyk_v4b_T;

/* Block signals for system '<S262>/Embedded MATLAB Function' */
typedef struct {
  real_T VCODE[70];                    /* '<S262>/Embedded MATLAB Function' */
} B_EmbeddedMATLABFunction_gbyk_v4b_T;

/* Block signals for system '<S9>/Embedded MATLAB WhichHand' */
typedef struct {
  real_T hand;                         /* '<S9>/Embedded MATLAB WhichHand' */
} B_EmbeddedMATLABWhichHand_gbyk_v4b_T;

/* Block signals for system '<S22>/Embedded MATLAB Function' */
typedef struct {
  real_T VCODE[140];                   /* '<S22>/Embedded MATLAB Function' */
} B_EmbeddedMATLABFunction_gbyk_v4b_p_T;

/* Block signals (auto storage) */
typedef struct {
  real_T BlockDefinitions[25000];      /* '<S7>/Block Definitions' */
  real_T BlockSequence[2000];          /* '<S7>/Block Sequence' */
  real_T RunCommandReceive_o2;         /* '<S268>/Run Command Receive' */
  real_T DataTypeConversion;           /* '<S268>/Data Type Conversion' */
  real_T PauseType;                    /* '<S7>/Pause Type' */
  real_T Convert18;                    /* '<S7>/Convert18' */
  real_T UseTaskProtocolBlockSequenceFlag;/* '<S7>/Use Task Protocol Block Sequence Flag' */
  real_T NextBlock;                    /* '<S7>/Next Block' */
  real_T Convert16;                    /* '<S7>/Convert16' */
  real_T Convert17;                    /* '<S7>/Convert17' */
  real_T MinMax;                       /* '<S7>/MinMax' */
  real_T DataTypeConversion2;          /* '<S268>/Data Type Conversion2' */
  real_T TPSelector[50];               /* '<S7>/TP Selector' */
  real_T Convert1[5000];               /* '<S7>/Convert1' */
  real_T Convert10[2];                 /* '<S7>/Convert10' */
  real_T Convert11[10];                /* '<S7>/Convert11' */
  real_T Convert12;                    /* '<S7>/Convert12' */
  real_T Convert13[3];                 /* '<S7>/Convert13' */
  real_T Convert14[2];                 /* '<S7>/Convert14' */
  real_T Convert15;                    /* '<S7>/Convert15' */
  real_T Convert7;                     /* '<S7>/Convert7' */
  real_T Convert8;                     /* '<S7>/Convert8' */
  real_T Convert9[2];                  /* '<S7>/Convert9' */
  real_T TargetTable[800];             /* '<S7>/Target Table' */
  real_T LoadTable[200];               /* '<S7>/Load Table' */
  real_T Taskwideparam[50];            /* '<S7>/Task wide param' */
  real_T frame_of_reference_center[2]; /* '<S7>/frame_of_reference_center' */
  real_T LibraryPatchVersion;          /* '<S7>/Library Patch Version' */
  real_T LibraryVersion;               /* '<S7>/Library Version' */
  real_T TaskVersion;                  /* '<S7>/Task Version' */
  real_T xPCVersion;                   /* '<S7>/xPC Version' */
  real_T dlmbuildtime;                 /* '<S7>/dlm build time' */
  real_T Timestamp;                    /* '<S30>/Timestamp' */
  real_T conv;                         /* '<S30>/conv' */
  real_T RunStatus;                    /* '<S30>/Run Status' */
  real_T RateTransition10;             /* '<S30>/Rate Transition10' */
  real_T Selector2;                    /* '<Root>/Selector2' */
  real_T Selector3[499];               /* '<Root>/Selector3' */
  real_T Product;                      /* '<Root>/Product' */
  real_T Memory[4];                    /* '<S4>/Memory' */
  real_T Memory_k;                     /* '<S15>/Memory' */
  real_T Gain;                         /* '<S15>/Gain' */
  real_T Dominant_Arm;                 /* '<S11>/Dominant_Arm' */
  real_T Hand_Pos[6];                  /* '<S11>/Hand_Pos' */
  real_T MultiportSwitch[2];           /* '<S11>/Multiport Switch' */
  real_T ArraySelector[32];            /* '<S11>/Array Selector' */
  real_T Dominant_Arm_k;               /* '<S9>/Dominant_Arm' */
  real_T Hand_Pos_i[6];                /* '<S9>/Hand_Pos' */
  real_T MultiportSwitch_c[2];         /* '<S9>/Multiport Switch' */
  real_T Switch1[2];                   /* '<Root>/Switch1' */
  real_T Switch[2];                    /* '<Root>/Switch' */
  real_T MathFunction[2];              /* '<Root>/Math Function' */
  real_T SumofElements;                /* '<Root>/Sum of Elements' */
  real_T Sqrt;                         /* '<Root>/Sqrt' */
  real_T Dominant_Arm_o;               /* '<S10>/Dominant_Arm' */
  real_T Hand_Pos_n[6];                /* '<S10>/Hand_Pos' */
  real_T MultiportSwitch_b[2];         /* '<S10>/Multiport Switch' */
  real_T ArraySelector_n[32];          /* '<S10>/Array Selector' */
  real_T Product_g[2];                 /* '<S30>/Product' */
  real_T LoggingEnable[2];             /* '<S30>/Logging Enable' */
  real_T RateTransition9[2];           /* '<S30>/Rate Transition9' */
  real_T CurrentTPIndex;               /* '<S30>/Current TP Index' */
  real_T RateTransition8;              /* '<S30>/Rate Transition8' */
  real_T CurrentBlockIndex;            /* '<S30>/Current Block Index' */
  real_T RateTransition7;              /* '<S30>/Rate Transition7' */
  real_T CurrentTrialNumberinBlock;    /* '<S30>/Current Trial Number in Block' */
  real_T RateTransition6;              /* '<S30>/Rate Transition6' */
  real_T CurrentBlockNumberinSet;      /* '<S30>/Current Block Number in Set' */
  real_T RateTransition5;              /* '<S30>/Rate Transition5' */
  real_T CurrentTrialNumberinSet;      /* '<S30>/Current Trial Number in Set' */
  real_T RateTransition4;              /* '<S30>/Rate Transition4' */
  real_T LastFrameSent1;               /* '<S30>/Last Frame Sent1' */
  real_T RateTransition12;             /* '<S30>/Rate Transition12' */
  real_T Selector[25];                 /* '<S24>/Selector' */
  real_T MatrixConcatenation1[55];     /* '<S24>/Matrix Concatenation1' */
  real_T Selector_l[50];               /* '<S22>/Selector' */
  real_T MatrixConcatenation1_n[55];   /* '<S22>/Matrix Concatenation1' */
  real_T Reshape[70];                  /* '<S8>/Reshape' */
  real_T Reshape1[70];                 /* '<S8>/Reshape1' */
  real_T MatrixConcatenation[140];     /* '<S8>/Matrix Concatenation' */
  real_T Selector_g[25];               /* '<S265>/Selector' */
  real_T DataTypeConversion_b;         /* '<S6>/Data Type Conversion' */
  real_T MatrixConcatenation1_a[55];   /* '<S265>/Matrix Concatenation1' */
  real_T Switch_h;                     /* '<S6>/Switch' */
  real_T Add;                          /* '<S5>/Add' */
  real_T Selector_j[25];               /* '<S262>/Selector' */
  real_T Abs;                          /* '<S5>/Abs' */
  real_T Sign;                         /* '<S5>/Sign' */
  real_T MatrixConcatenation1_na[55];  /* '<S262>/Matrix Concatenation1' */
  real_T Selector_i[50];               /* '<S23>/Selector' */
  real_T MatrixConcatenation1_p[55];   /* '<S23>/Matrix Concatenation1' */
  real_T Selector_d[25];               /* '<S21>/Selector' */
  real_T MatrixConcatenation1_h[55];   /* '<S21>/Matrix Concatenation1' */
  real_T MatrixConcatenation_b[700];   /* '<Root>/Matrix Concatenation' */
  real_T RateTransition2[700];         /* '<S15>/Rate Transition2' */
  real_T MatrixConcatenate[1330];      /* '<S15>/Matrix Concatenate' */
  real_T Convert;                      /* '<S15>/Convert' */
  real_T LastFrameSent;                /* '<S30>/Last Frame Sent' */
  real_T RateTransition3;              /* '<S30>/Rate Transition3' */
  real_T Receive_o2;                   /* '<S15>/Receive' */
  real_T Convert1_a;                   /* '<S15>/Convert1' */
  real_T LastFrameAcknowledged;        /* '<S30>/Last Frame Acknowledged' */
  real_T RateTransition2_e;            /* '<S30>/Rate Transition2' */
  real_T ButtonStatus;                 /* '<S30>/Button Status' */
  real_T RateTransition1;              /* '<S30>/Rate Transition1' */
  real_T Servoupdatecount;             /* '<S30>/Servo update count' */
  real_T RateTransition;               /* '<S30>/Rate Transition' */
  real_T TaskControlButton;            /* '<S30>/Task Control Button' */
  real_T RateTransition11;             /* '<S30>/Rate Transition11' */
  real_T RateTransition1_i[17];        /* '<S4>/Rate Transition1' */
  real_T TmpRTBAtNumberofEventCodesOutport1;/* '<S28>/Number of Event Codes' */
  real_T EventCodes;                   /* '<S28>/Event Codes' */
  real_T RateTransition2_ea[2];        /* '<S4>/Rate Transition2' */
  real_T KinarmDataWidth;              /* '<S29>/Kinarm Data Width' */
  real_T RateTransition_k[40];         /* '<S29>/Rate Transition' */
  real_T RateTransition2_er[13];       /* '<S29>/Rate Transition2' */
  real_T RateTransition3_n[14];        /* '<S29>/Rate Transition3' */
  real_T touint1;                      /* '<S29>/touint1' */
  real_T ArmKinematics[68];            /* '<S29>/Arm Kinematics' */
  real_T Subtract;                     /* '<S26>/Subtract' */
  real_T AnalogDataWidth;              /* '<S26>/Analog Data Width' */
  real_T RateTransition_c;             /* '<S26>/Rate Transition' */
  real_T TrigonometricFunction;        /* '<Root>/Trigonometric Function' */
  real_T VectorConcatenate[20];        /* '<Root>/Vector Concatenate' */
  real_T AnalogData[20];               /* '<S26>/Analog Data' */
  real_T RateTransition1_c[20];        /* '<S26>/Rate Transition1' */
  real_T CustomData1[10];              /* '<S27>/Custom Data1' */
  real_T RateTransition_b[4];          /* '<S27>/Rate Transition' */
  real_T RateTransition1_b;            /* '<S27>/Rate Transition1' */
  real_T RateTransition2_eo;           /* '<S27>/Rate Transition2' */
  real_T RateTransition_d[18];         /* '<S4>/Rate Transition' */
  real_T Subtract_g;                   /* '<S28>/Subtract' */
  real_T NumberofEventCodes;           /* '<S28>/Number of Event Codes' */
  real_T AddTorques[4];                /* '<S4>/AddTorques' */
  real_T Memory1;                      /* '<S4>/Memory1' */
  real_T ArmOrientation;               /* '<S4>/Memory2' */
  real_T M1orientation;                /* '<S4>/Memory2' */
  real_T M2Orientation;                /* '<S4>/Memory2' */
  real_T M1GearRatio;                  /* '<S4>/Memory2' */
  real_T M2GearRatio;                  /* '<S4>/Memory2' */
  real_T torqueconstant;               /* '<S4>/Memory2' */
  real_T ArmOrientation_c;             /* '<S4>/Memory2' */
  real_T M1orientation_f;              /* '<S4>/Memory2' */
  real_T M2Orientation_c;              /* '<S4>/Memory2' */
  real_T M1GearRatio_h;                /* '<S4>/Memory2' */
  real_T M2GearRatio_d;                /* '<S4>/Memory2' */
  real_T torqueconstant_m;             /* '<S4>/Memory2' */
  real_T isEP;                         /* '<S4>/Memory2' */
  real_T isHumanExo;                   /* '<S4>/Memory2' */
  real_T isNHPExo;                     /* '<S4>/Memory2' */
  real_T isClassicExo;                 /* '<S4>/Memory2' */
  real_T isUTSExo;                     /* '<S4>/Memory2' */
  real_T isPMAC;                       /* '<S4>/Memory2' */
  real_T isECAT;                       /* '<S4>/Memory2' */
  real_T robotRevision;                /* '<S4>/Memory2' */
  real_T HasSecondaryEnc;              /* '<S4>/Memory2' */
  real_T robottype;                    /* '<S4>/Memory2' */
  real_T robotversion;                 /* '<S4>/Memory2' */
  real_T isEP_k;                       /* '<S4>/Memory2' */
  real_T isHumanExo_p;                 /* '<S4>/Memory2' */
  real_T isNHPExo_n;                   /* '<S4>/Memory2' */
  real_T isClassicExo_g;               /* '<S4>/Memory2' */
  real_T isUTSExo_o;                   /* '<S4>/Memory2' */
  real_T isPMAC_n;                     /* '<S4>/Memory2' */
  real_T isECAT_b;                     /* '<S4>/Memory2' */
  real_T robotRevision_k;              /* '<S4>/Memory2' */
  real_T HasSecondaryEnc_d;            /* '<S4>/Memory2' */
  real_T robottype_c;                  /* '<S4>/Memory2' */
  real_T robotversion_i;               /* '<S4>/Memory2' */
  real_T readstatus[8];                /* '<S4>/read status' */
  real_T robot_count;                  /* '<S39>/arm_count' */
  real_T has_force_plate_1;            /* '<S39>/fp1_present' */
  real_T has_force_plate_2;            /* '<S39>/fp2_present' */
  real_T has_gaze_tracker;             /* '<S39>/gaze_tracker_present' */
  real_T has_robot_lift;               /* '<S39>/robot_lift_present' */
  real_T RateTransition1_l;            /* '<S296>/Rate Transition1' */
  real_T RateTransition2_d;            /* '<S296>/Rate Transition2' */
  real_T SFunctionBuilder_o2;          /* '<S296>/S-Function Builder' */
  real_T SFunctionBuilder_o3[5];       /* '<S296>/S-Function Builder' */
  real_T Selector4[60];                /* '<Root>/Selector4' */
  real_T Selector5[60];                /* '<Root>/Selector5' */
  real_T VectorConcatenate2[3];        /* '<Root>/Vector Concatenate2' */
  real_T B1TargetB1rowfloatB1rowintargettablenone;/* '<S285>/B1;Target B1 row;float;B1 row in target table;;;none;;' */
  real_T B2TargetB2rowfloatB2rowintargettablenone;/* '<S285>/B2;Target B2 row;float;B2 row in target table;;;none;;' */
  real_T CORR_TGTWhichtargetiscorrectfloatWhichtargetiscorrect1or2none;/* '<S285>/CORR_TGT;Which target is correct;float;Which target is correct (1 or 2) ?;;;none;;' */
  real_T DELAY_POST_TRIALTrialEndDelayintegerTimetowaitattheendofthetria;/* '<S285>/DELAY_POST_TRIAL;Trial-End Delay;integer;Time to wait at the end of the trial;;;none;;' */
  real_T DISPLAY_TRIAL_COLFlagDisplayintegerDisplayandpausenone;/* '<S285>/DISPLAY_TRIAL_COL;Flag Display;integer;Display and pause;;;none;;' */
  real_T INCORR_TGTWhichtargetisincorrectfloatWhichtargetisincorrect1or2;/* '<S285>/INCORR_TGT;Which target is incorrect;float;Which target is incorrect (1 or 2) ?;;;none;;' */
  real_T MAX_REACH_TIME_COLMaximumReachTimeintegerMaximumreachdurational;/* '<S285>/MAX_REACH_TIME_COL;Maximum Reach Time;integer;Maximum reach duration allowed;;;none;;' */
  real_T RWD_TARGETC1_COLTarget1ValuefloatRewardofferedonTargetC1none;/* '<S285>/RWD_TARGETC1_COL;Target1 Value;float;Reward offered on Target C1;;;none;;' */
  real_T RWD_TARGETC2_COLTarget2ValuefloatRewardofferedonTargetC2none;/* '<S285>/RWD_TARGETC2_COL;Target2 Value;float;Reward offered on Target C2;;;none;;' */
  real_T START_TARGET_COLStarttargettargetFirsttargettoappearduringatria;/* '<S285>/START_TARGET_COL;Start target;target;First target to appear during a trial;;;none;;' */
  real_T TGT_C_RWD_FRACRewardratiobetweenrowCrowBfloatHowmuchmorewilltar;/* '<S285>/TGT_C_RWD_FRAC;Reward ratio between rowC:rowB;float;How much more will targets B be worth?;;;none;;' */
  real_T INSTRUCT_PAUSE_BTNInstructionResumeButtontocontinuetaskafterdis;/* '<S286>/INSTRUCT_PAUSE_BTN;Instruction-Resume;;Button to continue task after displaying instructions;25;22;none;;' */
  real_T E_BOX_TRIGGERBoxWasTriggeredBoxtriggreredsosubjectchoserowCnone;/* '<S287>/E_BOX_TRIGGER;Box Was Triggered;;Box triggrered so subject chose row C;;;none;;' */
  real_T E_CHOSE_ROW_BChoseRowBSubjectchoserowBnone;/* '<S287>/E_CHOSE_ROW_B;Chose Row B;;Subject chose row B ;;;none;;' */
  real_T E_HIT_TARGETBHitTargetBHittargetBnone;/* '<S287>/E_HIT_TARGETB;Hit Target B;;Hit target B;;;none;;' */
  real_T E_HIT_TARGETCHitTargetCHitTargetCnone;/* '<S287>/E_HIT_TARGETC;Hit Target C;;Hit Target C;;;none;;' */
  real_T E_MISS_TARGETBMissTargretBMissTargretBnone;/* '<S287>/E_MISS_TARGETB;Miss Targret B;;Miss Targret B;;;none;;' */
  real_T E_MISS_TARGETCMissTargetCMissTargetCnone;/* '<S287>/E_MISS_TARGETC;Miss Target C;;Miss Target C;;;none;;' */
  real_T E_NEW_TRIALNewTrialStartNewTrialstartsnone;/* '<S287>/E_NEW_TRIAL;New Trial Start;;New Trial starts;;;none;;' */
  real_T E_NO_EVENTnaThisevent_codedoesnotsaveaneventinthedatafileitjust;/* '<S287>/E_NO_EVENT;n|a;;This event_code does not save an event in the data file, it just clears the event;;;none;;' */
  real_T E_SHOW_INSTRUCTInstructionstateShowinginstructionsnone;/* '<S287>/E_SHOW_INSTRUCT;Instruction state;;Showing instructions;;;none;;' */
  real_T E_SHOW_SCOREShowScoreShowingscorenone;/* '<S287>/E_SHOW_SCORE;Show Score;;Showing score;;;none;;' */
  real_T E_STAY_STARTAtStartSubjectreachedstarttargetnone;/* '<S287>/E_STAY_START;At Start;;Subject reached start target;;;none;;' */
  real_T E_TARGETS_ONTargetsOnPotentialReachtargetsonnone;/* '<S287>/E_TARGETS_ON;Targets On;;Potential Reach targets on;;;none;;' */
  real_T E_TOO_SLOWTooSlowMovementistooslowerror;/* '<S287>/E_TOO_SLOW;Too Slow;;Movement is too slow;;;error;;' */
  real_T BOX_HEIGHTHeightofBoxfloatHeightofBoxnone;/* '<S288>/BOX_HEIGHT;Height of Box;float;Height of Box;;;none;;' */
  real_T HIT_COLORReachedcolorcolourColorwhenthetargetistouchednone;/* '<S288>/HIT_COLOR;Reached color;colour;Color when the target is touched;;;none;;' */
  real_T INIT_COLORInitialcolorcolourInitialtargetcolornone;/* '<S288>/INIT_COLOR;Initial color;colour;Initial target color;;;none;;' */
  real_T LABELLabelTextlabelInitialtextforthelabelnone;/* '<S288>/LABEL;Label Text;label;Initial text for the label;;;none;;' */
  real_T LABELONLY_XLabelOnlyXfloatXpositioncmofthetargetrelativetolocal;/* '<S288>/LABELONLY_X;LabelOnly X;float;X position (cm) of the target relative to local (0,0) when only the label appears;;;none;;' */
  real_T LABELONLY_YLabelOnlyYfloatYpositioncmofthetargetrelativetolocal;/* '<S288>/LABELONLY_Y;LabelOnly  Y;float;Y position (cm) of the target relative to local (0,0) when only the label appears;;;none;;' */
  real_T LABEL_HEIGHTLabelHeightfloatLabelHeightcmnone;/* '<S288>/LABEL_HEIGHT;Label Height;float;Label Height (cm);;;none;;' */
  real_T LOGICAL_RADIUSLogicalradiusfloatRadiusofthetargetusedforhandint;/* '<S288>/LOGICAL_RADIUS;Logical radius;float;Radius of the target used for 'hand-in-target' logic (cm);;;none;;' */
  real_T ROTATIONRotationofatargetfloatRotationoftargetnone;/* '<S288>/ROTATION;Rotation of a target;float;Rotation of target;;;none;;' */
  real_T STROKE_WIDTHStrokeWidthfloatStrokewidthnone;/* '<S288>/STROKE_WIDTH;Stroke Width;float;Stroke width;;;none;;' */
  real_T TEXT_COLORTextColorcolourTextColornone;/* '<S288>/TEXT_COLOR;Text Color;colour;Text Color;;;none;;' */
  real_T col_xXfloatXPositioncmofthetargetrelativetolocal00none;/* '<S288>/col_x;X;float;X Position (cm) of the target relative to  local (0,0);;;none;;' */
  real_T col_yYfloatYPositioncmofthetargetrelativetolocal00none;/* '<S288>/col_y;Y;float;Y Position (cm) of the target relative to  local (0,0);;;none;;' */
  real_T VISUAL_RADIUSVisualradiusfloatVisualradiusofthetargetcmorsizeof;/* '<S288>/VISUAL_RADIUS;Visual radius;float;Visual radius of the target (cm) or size of the sides of the square targets;;;none;;' */
  real_T INSTRUCTIONS;                 /* '<S289>/INSTRUCTIONS=' */
  real_T LOAD_FOREITHER;               /* '<S289>/LOAD_FOR=EITHER' */
  real_T K_DELAY_FIXEDDelay_MinintegerMinimumholddelaytimeatstarttargetf;/* '<S290>/K_DELAY_FIXED;Delay_Min;integer;Minimum hold delay time at start target (fixed);;;none;;' */
  real_T K_DELAY_RANDDelay_RandintegerMaximumadditionaldelaytimeatstartt;/* '<S290>/K_DELAY_RAND;Delay_Rand;integer;Maximum additional delay time at start target (random);;;none;;' */
  real_T K_PRE_REWARD_DELAYDelay_PreRewardCueintegerTimetocuetherewardin;/* '<S290>/K_PRE_REWARD_DELAY;Delay_PreRewardCue;integer;Time to cue the reward information prior to the trial onset;;;none;;' */
  real_T K_REWARD_VALReward_ValueintegerOneunitofrewardnone;/* '<S290>/K_REWARD_VAL;Reward_Value;integer;One unit of reward;;;none;;' */
  real_T K_SCORETEXT_ROWFeedback_Text_TgtTable_RowintegerTargetnumbertob;/* '<S290>/K_SCORETEXT_ROW;Feedback_Text_TgtTable_Row;integer;Target number to be used to set the feedback text;;;none;;' */
  real_T K_THRESH_VELMAXVel_Min_ThreshfloatMinimumvelocitythatmustbeexce;/* '<S290>/K_THRESH_VELMAX;Vel_Min_Thresh;float;Minimum velocity that must be exceeded for trial to be considered successful;;;none;;' */
  real_T K_TRIGGER_POSTrigger_PosfloatPositionThresholdfortriggeringtarg;/* '<S290>/K_TRIGGER_POS;Trigger_Pos;float;Position Threshold for triggering target reveal;;;none;;' */
  real_T K_TRIGGER_VELTrigger_VelfloatVelocityThresholdfortriggeringtarg;/* '<S290>/K_TRIGGER_VEL;Trigger_Vel;float;Velocity Threshold for triggering target reveal;;;none;;' */
  real_T logging_enable[2];            /* '<Root>/Trial_Control' */
  real_T targetA_row;                  /* '<Root>/Trial_Control' */
  real_T targetA_state;                /* '<Root>/Trial_Control' */
  real_T targetB_row[2];               /* '<Root>/Trial_Control' */
  real_T targetB_state[2];             /* '<Root>/Trial_Control' */
  real_T offeredRewards[2];            /* '<Root>/Trial_Control' */
  real_T score;                        /* '<Root>/Trial_Control' */
  real_T doreward;                     /* '<Root>/Trial_Control' */
  real_T reward;                       /* '<Root>/Trial_Control' */
  real_T instruct_num;                 /* '<Root>/Trial_Control' */
  real_T tone;                         /* '<Root>/Trial_Control' */
  real_T repeat_trial_flag;            /* '<Root>/Trial_Control' */
  real_T trialIterations[120];         /* '<Root>/Trial_Control' */
  real_T targetC_row[2];               /* '<Root>/Trial_Control' */
  real_T targetC_state[2];             /* '<Root>/Trial_Control' */
  real_T offeredRewardsC[2];           /* '<Root>/Trial_Control' */
  real_T boxRow;                       /* '<Root>/Trial_Control' */
  real_T boxState;                     /* '<Root>/Trial_Control' */
  real_T Convert_n;                    /* '<S298>/Convert' */
  real_T RateTransition1_h;            /* '<S298>/Rate Transition1' */
  real_T vis_cmd_len;                  /* '<S298>/Pack VCodeFrame2' */
  real_T vis_cmd_cropped;              /* '<S298>/Pack VCodeFrame2' */
  real_T vcode_err_id;                 /* '<S298>/Pack VCodeFrame2' */
  real_T last_frame_ack;               /* '<S15>/MATLAB Function' */
  real_T last_perm_ack;                /* '<S15>/MATLAB Function' */
  real_T delay;                        /* '<S296>/MATLAB Function' */
  real_T ListReps;                     /* '<Root>/MATLAB Function' */
  real_T TmpSignalConversionAtSFunctionInport3[5];/* '<S11>/Embedded MATLAB InsideTarget' */
  real_T intarget[160];                /* '<S11>/Embedded MATLAB InsideTarget' */
  real_T Arm1[2];                      /* '<S11>/Arm1' */
  real_T Arm2[2];                      /* '<S11>/Arm2' */
  real_T TmpSignalConversionAtSFunctionInport3_d[15];/* '<S10>/Embedded MATLAB InsideTarget' */
  real_T intarget_l[160];              /* '<S10>/Embedded MATLAB InsideTarget' */
  real_T Arm1_p[2];                    /* '<S10>/Arm1' */
  real_T Arm2_o[2];                    /* '<S10>/Arm2' */
  real_T distance[32];                 /* '<S9>/Embedded MATLAB InsideTarget' */
  real_T Arm1_a[2];                    /* '<S9>/Arm1' */
  real_T Arm2_j[2];                    /* '<S9>/Arm2' */
  real_T VCODES_out[140];              /* '<S8>/FeedFwdArm' */
  real_T total_trials;                 /* '<S270>/MATLAB Function' */
  real_T trials_in_block;              /* '<S270>/MATLAB Function' */
  real_T total_blocks;                 /* '<S270>/MATLAB Function' */
  real_T Delay1;                       /* '<S269>/Delay1' */
  real_T Product3;                     /* '<S269>/Product3' */
  real_T TaskClock;                    /* '<S269>/Task Clock' */
  real_T Product_i;                    /* '<S269>/Product' */
  real_T DataTypeConversion_g;         /* '<S269>/Data Type Conversion' */
  real_T Product2;                     /* '<S269>/Product2' */
  real_T DataTypeConversion2_n;        /* '<S269>/Data Type Conversion2' */
  real_T Selector_n[50];               /* '<S269>/Selector' */
  real_T Selector1[500];               /* '<S269>/Selector1' */
  real_T Selector2_l[1000];            /* '<S269>/Selector2' */
  real_T repeat_last_trial;            /* '<S269>/Task Execution Control Machine' */
  real_T extra_trials[2];              /* '<S269>/Task Execution Control Machine' */
  real_T value;                        /* '<S268>/Hold_to_1Khz' */
  real_T y;                            /* '<S268>/Embedded MATLAB Function' */
  real_T z;                            /* '<S268>/Embedded MATLAB Function' */
  real_T Concatenation1[10];           /* '<S267>/Concatenation1' */
  real_T target_vector[352];           /* '<S267>/Create Target Vector' */
  real_T target_vector_length;         /* '<S267>/Create Target Vector' */
  real_T VCODE[70];                    /* '<S265>/Embedded MATLAB Function' */
  real_T VCODE_mod[70];                /* '<S6>/MATLAB Function' */
  real_T TmpSignalConversionAtSFunctionInport1[4];/* '<S38>/delta' */
  real_T TmpSignalConversionAtSFunctionInport2[4];/* '<S38>/delta' */
  real_T deltas[4];                    /* '<S38>/delta' */
  real_T Product_m[4];                 /* '<S252>/Product' */
  real_T DataStoreRead[14];            /* '<S251>/Data Store Read' */
  real_T DataTypeConversion3[4];       /* '<S35>/Data Type Conversion3' */
  real_T DataTypeConversion4;          /* '<S35>/Data Type Conversion4' */
  real_T DataTypeConversion5;          /* '<S35>/Data Type Conversion5' */
  real_T Convert1_p;                   /* '<S35>/Convert1' */
  real_T DataTypeConversion_i;         /* '<S35>/Data Type Conversion' */
  real_T Convert19[3];                 /* '<S35>/Convert19' */
  real_T DataTypeConversion1[3];       /* '<S35>/Data Type Conversion1' */
  real_T TmpRTBAtconverttoseconds2Inport1[3];/* '<S35>/Data Type Conversion1' */
  real_T TmpRTBAtconverttoseconds2Inport2;/* '<S35>/Create timestamp' */
  real_T Convert2[3];                  /* '<S35>/Convert2' */
  real_T Convert3;                     /* '<S35>/Convert3' */
  real_T Gain_b[3];                    /* '<S35>/Gain' */
  real_T Convert4[3];                  /* '<S35>/Convert4' */
  real_T RateTransition_kg[3];         /* '<S35>/Rate Transition' */
  real_T Receive_o2_j;                 /* '<S35>/Receive' */
  real_T event_data_out[3];            /* '<S35>/convert to seconds2' */
  real_T gazeXYCalculated[2];          /* '<S35>/Embedded MATLAB Function1' */
  real_T pupil_area_GLOBAL;            /* '<S35>/Embedded MATLAB Function1' */
  real_T gaze_unit_vector_GLOBAL[3];   /* '<S35>/Embedded MATLAB Function1' */
  real_T pupil_GLOBAL[3];              /* '<S35>/Embedded MATLAB Function1' */
  real_T timestamp_out;                /* '<S35>/Create timestamp' */
  real_T start_time_out;               /* '<S35>/Create timestamp' */
  real_T DataTypeConversion_h;         /* '<S64>/Data Type Conversion' */
  real_T systemtype;                   /* '<S34>/system type' */
  real_T convert[8];                   /* '<S64>/convert' */
  real_T ReadHasFT[2];                 /* '<S34>/Read HasFT' */
  real_T ArmOrientation_b;             /* '<S230>/Arm Orientation' */
  real_T M1orientation_h;              /* '<S230>/Arm Motor1 Orientation' */
  real_T M2Orientation_l;              /* '<S230>/Arm Motor2 Orientation' */
  real_T M1GearRatio_b;                /* '<S230>/Arm Motor1 Gear Ratio' */
  real_T M2GearRatio_p;                /* '<S230>/Arm Motor2 Gear Ratio' */
  real_T HasSecondaryEnc_n;            /* '<S230>/Arm Secondary Encoders' */
  real_T ArmOrientation_l;             /* '<S231>/Arm Orientation' */
  real_T M1orientation_n;              /* '<S231>/Arm Motor1 Orientation' */
  real_T M2Orientation_cw;             /* '<S231>/Arm Motor2 Orientation' */
  real_T M1GearRatio_k;                /* '<S231>/Arm Motor1 Gear Ratio' */
  real_T M2GearRatio_l;                /* '<S231>/Arm Motor2 Gear Ratio' */
  real_T HasSecondaryEnc_f;            /* '<S231>/Arm Secondary Encoders' */
  real_T shoulderangleoffset;          /* '<S230>/Arm Shoulder Angle Offset' */
  real_T elbowangleoffset;             /* '<S230>/Arm Elbow Angle Offset' */
  real_T ShoulderX;                    /* '<S230>/Arm Shoulder X' */
  real_T ShoulderY;                    /* '<S230>/Arm Shoulder Y' */
  real_T L1;                           /* '<S230>/Arm L1' */
  real_T L2;                           /* '<S230>/Arm L2' */
  real_T Pointeroffset;                /* '<S230>/Arm Pointer Offset' */
  real_T L3Error;                      /* '<S230>/Arm L3 Error' */
  real_T robottype_e;                  /* '<S230>/Arm robot type' */
  real_T torqueconstant_g;             /* '<S230>/Arm Torque Constant' */
  real_T robotversion_g;               /* '<S230>/Arm robot version' */
  real_T shoulderangleoffset_b;        /* '<S231>/Arm Shoulder Angle Offset' */
  real_T elbowangleoffset_a;           /* '<S231>/Arm Elbow Angle Offset' */
  real_T ShoulderX_a;                  /* '<S231>/Arm Shoulder X' */
  real_T ShoulderY_b;                  /* '<S231>/Arm Shoulder Y' */
  real_T L1_c;                         /* '<S231>/Arm L1' */
  real_T L2_f;                         /* '<S231>/Arm L2' */
  real_T Pointeroffset_b;              /* '<S231>/Arm Pointer Offset' */
  real_T L3Error_f;                    /* '<S231>/Arm L3 Error' */
  real_T robottype_cs;                 /* '<S231>/Arm robot type' */
  real_T torqueconstant_i;             /* '<S231>/Arm Torque Constant' */
  real_T robotversion_f;               /* '<S231>/Arm robot version' */
  real_T Statusread1[2];               /* '<S230>/Status read1' */
  real_T Statusread1_m[2];             /* '<S231>/Status read1' */
  real_T Selector_c[50];               /* '<S73>/Selector' */
  real_T Selector1_m[50];              /* '<S73>/Selector1' */
  real_T Selector2_o[50];              /* '<S73>/Selector2' */
  real_T Selector1_a[6];               /* '<S74>/Selector1' */
  real_T Selector2_i[6];               /* '<S74>/Selector2' */
  real_T active_arm;                   /* '<S73>/splitKINDataGeneral' */
  real_T delayEstimates[4];            /* '<S73>/splitKINDataGeneral' */
  real_T servoCounter;                 /* '<S73>/splitKINDataGeneral' */
  real_T calibrationButtonBits;        /* '<S73>/splitKINDataGeneral' */
  real_T handFF;                       /* '<S73>/splitKINDataGeneral' */
  real_T handFF_Dex;                   /* '<S73>/splitKINDataGeneral' */
  real_T handFBArm;                    /* '<S73>/splitKINDataGeneral' */
  real_T handFBRadius;                 /* '<S73>/splitKINDataGeneral' */
  real_T handFBControl;                /* '<S73>/splitKINDataGeneral' */
  real_T handFBColor;                  /* '<S73>/splitKINDataGeneral' */
  real_T hasGaze;                      /* '<S73>/splitKINDataGeneral' */
  real_T gazeFB;                       /* '<S73>/splitKINDataGeneral' */
  real_T gazeLocation[2];              /* '<S73>/splitKINDataGeneral' */
  real_T gazeTimestamp;                /* '<S73>/splitKINDataGeneral' */
  real_T gazePupilArea;                /* '<S73>/splitKINDataGeneral' */
  real_T gazeEvent[3];                 /* '<S73>/splitKINDataGeneral' */
  real_T gazeVector[3];                /* '<S73>/splitKINDataGeneral' */
  real_T gazePupilLoc[3];              /* '<S73>/splitKINDataGeneral' */
  real_T link_lengths[2];              /* '<S73>/splitKINData arm2' */
  real_T pointer_offset;               /* '<S73>/splitKINData arm2' */
  real_T shoulder_loc[2];              /* '<S73>/splitKINData arm2' */
  real_T arm_orientation;              /* '<S73>/splitKINData arm2' */
  real_T shoulder_ang;                 /* '<S73>/splitKINData arm2' */
  real_T elbow_ang;                    /* '<S73>/splitKINData arm2' */
  real_T shoulder_velocity;            /* '<S73>/splitKINData arm2' */
  real_T elbow_velocity;               /* '<S73>/splitKINData arm2' */
  real_T shoulder_acceleration;        /* '<S73>/splitKINData arm2' */
  real_T elbow_acceleration;           /* '<S73>/splitKINData arm2' */
  real_T joint_torque_cmd[2];          /* '<S73>/splitKINData arm2' */
  real_T motor_torque_cmd[2];          /* '<S73>/splitKINData arm2' */
  real_T link_angle[2];                /* '<S73>/splitKINData arm2' */
  real_T link_velocity[2];             /* '<S73>/splitKINData arm2' */
  real_T link_acceleration[2];         /* '<S73>/splitKINData arm2' */
  real_T hand_position[2];             /* '<S73>/splitKINData arm2' */
  real_T hand_velocity[2];             /* '<S73>/splitKINData arm2' */
  real_T hand_acceleration[2];         /* '<S73>/splitKINData arm2' */
  real_T motor_status;                 /* '<S73>/splitKINData arm2' */
  real_T force_sensor_force_uvw[3];    /* '<S73>/splitKINData arm2' */
  real_T force_sensor_torque_uvw[3];   /* '<S73>/splitKINData arm2' */
  real_T force_sensor_force_xyz[3];    /* '<S73>/splitKINData arm2' */
  real_T force_sensor_torque_xyz[3];   /* '<S73>/splitKINData arm2' */
  real_T force_sensor_timestamp;       /* '<S73>/splitKINData arm2' */
  real_T link_lengths_o[2];            /* '<S73>/splitKINData arm1' */
  real_T pointer_offset_k;             /* '<S73>/splitKINData arm1' */
  real_T shoulder_loc_o[2];            /* '<S73>/splitKINData arm1' */
  real_T arm_orientation_o;            /* '<S73>/splitKINData arm1' */
  real_T shoulder_ang_h;               /* '<S73>/splitKINData arm1' */
  real_T elbow_ang_k;                  /* '<S73>/splitKINData arm1' */
  real_T shoulder_velocity_k;          /* '<S73>/splitKINData arm1' */
  real_T elbow_velocity_j;             /* '<S73>/splitKINData arm1' */
  real_T shoulder_acceleration_c;      /* '<S73>/splitKINData arm1' */
  real_T elbow_acceleration_j;         /* '<S73>/splitKINData arm1' */
  real_T joint_torque_cmd_k[2];        /* '<S73>/splitKINData arm1' */
  real_T motor_torque_cmd_b[2];        /* '<S73>/splitKINData arm1' */
  real_T link_angle_b[2];              /* '<S73>/splitKINData arm1' */
  real_T link_velocity_k[2];           /* '<S73>/splitKINData arm1' */
  real_T link_acceleration_c[2];       /* '<S73>/splitKINData arm1' */
  real_T hand_position_g[2];           /* '<S73>/splitKINData arm1' */
  real_T hand_velocity_p[2];           /* '<S73>/splitKINData arm1' */
  real_T hand_acceleration_e[2];       /* '<S73>/splitKINData arm1' */
  real_T motor_status_c;               /* '<S73>/splitKINData arm1' */
  real_T force_sensor_force_uvw_g[3];  /* '<S73>/splitKINData arm1' */
  real_T force_sensor_torque_uvw_d[3]; /* '<S73>/splitKINData arm1' */
  real_T force_sensor_force_xyz_g[3];  /* '<S73>/splitKINData arm1' */
  real_T force_sensor_torque_xyz_g[3]; /* '<S73>/splitKINData arm1' */
  real_T force_sensor_timestamp_k;     /* '<S73>/splitKINData arm1' */
  real_T Read[16];                     /* '<S70>/Read' */
  real_T ReadHW[24];                   /* '<S70>/Read HW' */
  real_T ReadKinematics[20];           /* '<S70>/Read Kinematics' */
  real_T DelayRead[4];                 /* '<S70>/Delay Read' */
  real_T Primaryread[12];              /* '<S70>/Primary read' */
  real_T torquefeedback1[8];           /* '<S70>/torque feedback1' */
  real_T ErrMsgs[20];                  /* '<S70>/ErrMsgs' */
  real_T newMessage[6];                /* '<S70>/record errors' */
  real_T sentMessageCount;             /* '<S70>/record errors' */
  real_T TmpSignalConversionAtSFunctionInport3_e[14];/* '<S70>/Create KINARM Data Array' */
  real_T TmpSignalConversionAtSFunctionInport10[7];/* '<S70>/Create KINARM Data Array' */
  real_T TmpSignalConversionAtSFunctionInport12[14];/* '<S70>/Create KINARM Data Array' */
  real_T kinarm_data[150];             /* '<S70>/Create KINARM Data Array' */
  real_T primary_encoder_data_out[12]; /* '<S70>/Create KINARM Data Array' */
  real_T DataStore[16];                /* '<S84>/Data Store' */
  real_T DataStore1[24];               /* '<S84>/Data Store1' */
  real_T DataTypeConversion3_l[4];     /* '<S84>/Data Type Conversion3' */
  real_T TmpSignalConversionAtSFunctionInport2_l[4];/* '<S84>/update calibrations' */
  real_T TmpSignalConversionAtSFunctionInport4[2];/* '<S84>/update calibrations' */
  real_T calibrationsOut[16];          /* '<S84>/update calibrations' */
  real_T TmpSignalConversionAtSFunctionInport2_b[2];/* '<S84>/update HW settings' */
  real_T TmpSignalConversionAtSFunctionInport3_h[2];/* '<S84>/update HW settings' */
  real_T TmpSignalConversionAtSFunctionInport4_i[2];/* '<S84>/update HW settings' */
  real_T settingsOut[24];              /* '<S84>/update HW settings' */
  real_T outMem[20];                   /* '<S84>/robottype1' */
  real_T TmpSignalConversionAtSFunctionInport1_p[4];/* '<S84>/create kinematics' */
  real_T TmpSignalConversionAtSFunctionInport2_bj[4];/* '<S84>/create kinematics' */
  real_T TmpSignalConversionAtSFunctionInport3_g[4];/* '<S84>/create kinematics' */
  real_T TmpSignalConversionAtSFunctionInport4_b[2];/* '<S84>/create kinematics' */
  real_T TmpSignalConversionAtSFunctionInport6[2];/* '<S84>/create kinematics' */
  real_T TmpSignalConversionAtSFunctionInport8[2];/* '<S84>/create kinematics' */
  real_T kinematicsOut[20];            /* '<S84>/create kinematics' */
  real_T kinematicsOutPrimary[12];     /* '<S84>/create kinematics' */
  real_T delays[4];                    /* '<S84>/create kinematics' */
  real_T outVals[20];                  /* '<S194>/rebuild' */
  real_T TmpSignalConversionAtSFunctionInport1_l[4];/* '<S194>/filter_velocities' */
  real_T filteredVels[4];              /* '<S194>/filter_velocities' */
  real_T Receive_o2_o;                 /* '<S223>/Receive' */
  real_T DataTypeConversion_k[2];      /* '<S223>/Data Type Conversion' */
  real_T DataTypeConversion1_a[2];     /* '<S223>/Data Type Conversion1' */
  real_T DataTypeConversion2_i;        /* '<S223>/Data Type Conversion2' */
  real_T kinematics[20];               /* '<S223>/MATLAB Function' */
  real_T primary[12];                  /* '<S223>/MATLAB Function' */
  real_T UnitDelay;                    /* '<S212>/Unit Delay' */
  real_T DPRAMReadValue;               /* '<S212>/DPRAM Read Value' */
  real_T UnitDelay1;                   /* '<S212>/Unit Delay1' */
  real_T Conversion1[6];               /* '<S210>/Conversion1' */
  real_T Conversion2[6];               /* '<S210>/Conversion2' */
  real_T Conversion7[4];               /* '<S210>/Conversion7' */
  real_T DataTypeConversion3_d[10];    /* '<S210>/Data Type Conversion3' */
  real_T DataTypeConversion4_g[10];    /* '<S210>/Data Type Conversion4' */
  real_T robot1DataOut[10];            /* '<S210>/filter_velocities' */
  real_T robot2DataOut[10];            /* '<S210>/filter_velocities' */
  real_T robot1DataOut_p[10];          /* '<S210>/Robot_data_builder' */
  real_T robot2DataOut_g[10];          /* '<S210>/Robot_data_builder' */
  real_T robot1PrimaryEncDataOut[6];   /* '<S210>/Robot_data_builder' */
  real_T robot2PrimaryEncDataOut[6];   /* '<S210>/Robot_data_builder' */
  real_T force_scale;                  /* '<S210>/Monitor_status' */
  real_T DataTypeConversion1_j;        /* '<S217>/Data Type Conversion1' */
  real_T Uk1;                          /* '<S205>/Delay Input1' */
  real_T ReceivefromRobot1ForceSensor_o2;/* '<S202>/Receive from Robot 1 Force Sensor' */
  real_T Switch_p[7];                  /* '<S202>/Switch' */
  real_T Uk1_p;                        /* '<S209>/Delay Input1' */
  real_T ReceivefromRobot2ForceSensor_o2;/* '<S203>/Receive from Robot 2 Force Sensor' */
  real_T Switch1_b[7];                 /* '<S203>/Switch1' */
  real_T DataTypeConversion1_g[6];     /* '<S203>/Data Type Conversion1' */
  real_T DataTypeConversion_e[6];      /* '<S202>/Data Type Conversion' */
  real_T intAddresses[24];             /* '<S64>/sdo_addrs' */
  real_T floatAddresses[24];           /* '<S64>/sdo_addrs' */
  real_T errVals[12];                  /* '<S64>/latch_errors' */
  real_T DCErrVals[12];                /* '<S64>/latch_errors' */
  real_T Memory_m;                     /* '<S137>/Memory' */
  real_T Memory_i;                     /* '<S138>/Memory' */
  real_T Memory1_e;                    /* '<S146>/Memory1' */
  real_T Memory2;                      /* '<S146>/Memory2' */
  real_T offsetrads;                   /* '<S155>/L2 select' */
  real_T encorient;                    /* '<S155>/L2 select1' */
  real_T L2select2;                    /* '<S155>/L2 select2' */
  real_T L2select3;                    /* '<S155>/L2 select3' */
  real_T L2select4;                    /* '<S155>/L2 select4' */
  real_T R2_maxContinuousTorque[2];    /* '<S76>/Memory2' */
  real_T L2select5;                    /* '<S155>/L2 select5' */
  real_T R2_constantsReady;            /* '<S76>/Memory3' */
  real_T L2select;                     /* '<S168>/L2 select' */
  real_T L2select1;                    /* '<S168>/L2 select1' */
  real_T L2select2_p;                  /* '<S168>/L2 select2' */
  real_T L2select3_c;                  /* '<S168>/L2 select3' */
  real_T L2select4_b;                  /* '<S168>/L2 select4' */
  real_T L2select5_a;                  /* '<S168>/L2 select5' */
  real_T R2M1_LinkAngle;               /* '<S76>/Signal Conversion' */
  real_T R2M2_LinkAngle;               /* '<S76>/Signal Conversion' */
  real_T R2M2_PrimaryLinkAngle;        /* '<S76>/Signal Conversion' */
  real_T R2M2_PrimaryLinkVelocity;     /* '<S76>/Signal Conversion' */
  real_T R2M2_RecordedTorque;          /* '<S76>/Signal Conversion' */
  real_T R2M2_digitalInputs[2];        /* '<S76>/Signal Conversion' */
  real_T R2M2_digitalDiagnostics;      /* '<S76>/Signal Conversion' */
  real_T R2M2_EMCY_codes[5];           /* '<S76>/Signal Conversion' */
  real_T R2M1_PrimaryLinkAngle;        /* '<S76>/Signal Conversion' */
  real_T R2M1_PrimaryLinkVelocity;     /* '<S76>/Signal Conversion' */
  real_T R2M1_RecordedTorque;          /* '<S76>/Signal Conversion' */
  real_T R2M1_digitalInputs[2];        /* '<S76>/Signal Conversion' */
  real_T R2M1_digitalDiagnostics;      /* '<S76>/Signal Conversion' */
  real_T R2_calibrationButton;         /* '<S76>/Signal Conversion' */
  real_T R2M1_EMCY_codes[5];           /* '<S76>/Signal Conversion' */
  real_T R2_RobotType;                 /* '<S76>/Signal Conversion1' */
  real_T R2_absAngleOffset[2];         /* '<S76>/Signal Conversion1' */
  real_T R2_LinkLength[2];             /* '<S76>/Signal Conversion1' */
  real_T R2_L2CalibPinOffset;          /* '<S76>/Signal Conversion1' */
  real_T R2_maxContinuousTorque_e[2];  /* '<S76>/Signal Conversion1' */
  real_T R2_gearRatios[2];             /* '<S76>/Signal Conversion1' */
  real_T R2_isCalibrated;              /* '<S76>/Signal Conversion1' */
  real_T R2_OffsetRads[2];             /* '<S76>/Signal Conversion1' */
  real_T R2_OffsetRadsPrimary[2];      /* '<S76>/Signal Conversion1' */
  real_T R2_RobotRevision;             /* '<S76>/Signal Conversion1' */
  real_T R2_constantsReady_j;          /* '<S76>/Signal Conversion1' */
  real_T R2_hasSecondary;              /* '<S76>/Signal Conversion1' */
  real_T R2_hasFT;                     /* '<S76>/Signal Conversion1' */
  real_T R2_robotOrientation;          /* '<S76>/Signal Conversion1' */
  real_T R2_motorOrientation[2];       /* '<S76>/Signal Conversion1' */
  real_T R2_encOrientation[2];         /* '<S76>/Signal Conversion1' */
  real_T R2_encodercounts[2];          /* '<S76>/Signal Conversion1' */
  real_T R2_FTSensorAngleOffset;       /* '<S76>/Signal Conversion1' */
  real_T R2_calibPinAngle[2];          /* '<S76>/Signal Conversion1' */
  real_T RateTransition1_d;            /* '<S146>/Rate Transition1' */
  real_T RateTransition2_j;            /* '<S146>/Rate Transition2' */
  real_T encoderCounts[2];             /* '<S76>/split out constants' */
  real_T FTSensorOffset;               /* '<S76>/split out constants' */
  real_T calibPinAngles[2];            /* '<S76>/split out constants' */
  real_T absAngOffsets[2];             /* '<S76>/split out constants' */
  real_T linkLengths[2];               /* '<S76>/split out constants' */
  real_T L2CalibPinOffset;             /* '<S76>/split out constants' */
  real_T continuousTorques[2];         /* '<S76>/split out constants' */
  real_T gearRatios[2];                /* '<S76>/split out constants' */
  real_T isCalibrated;                 /* '<S76>/split out constants' */
  real_T offsetRads[2];                /* '<S76>/split out constants' */
  real_T offsetRadsPrimary[2];         /* '<S76>/split out constants' */
  real_T robotRevision_o;              /* '<S76>/split out constants' */
  real_T constantsReady;               /* '<S76>/split out constants' */
  real_T DataTypeConversion_iq;        /* '<S187>/Data Type Conversion' */
  real_T writeData[5];                 /* '<S144>/writeData' */
  real_T status;                       /* '<S144>/status' */
  real_T readAddr[3];                  /* '<S143>/readAddr' */
  real_T Memory_ip;                    /* '<S143>/Memory' */
  real_T convert_l;                    /* '<S143>/convert' */
  real_T convert1;                     /* '<S143>/convert1' */
  real_T status_e;                     /* '<S143>/status' */
  real_T DataTypeConversion_d;         /* '<S181>/Data Type Conversion' */
  real_T LinkAngle;                    /* '<S168>/countsToRads' */
  real_T PrimaryLinkAngle;             /* '<S168>/countsToRads' */
  real_T PrimaryLinkVel;               /* '<S168>/countsToRads' */
  real_T torque;                       /* '<S168>/countsToRads' */
  real_T digitalInputs[2];             /* '<S168>/countsToRads' */
  real_T digitalDiagnostics;           /* '<S168>/countsToRads' */
  real_T DataTypeConversion_j;         /* '<S167>/Data Type Conversion' */
  real_T driveID;                      /* '<S167>/driveID' */
  real_T DataTypeConversion2_g[2];     /* '<S171>/Data Type Conversion2' */
  real_T DataTypeConversion_i1[2];     /* '<S172>/Data Type Conversion' */
  real_T Memory_l;                     /* '<S173>/Memory' */
  real_T DataTypeConversion1_c;        /* '<S173>/Data Type Conversion1' */
  real_T isPermFaulted;                /* '<S138>/Control GDC Whistle State' */
  real_T A2M2Convert[5];               /* '<S164>/A2M2Convert' */
  real_T LinkAngle_l;                  /* '<S155>/countsToRads' */
  real_T PrimaryLinkAngle_f;           /* '<S155>/countsToRads' */
  real_T PrimaryLinkVel_i;             /* '<S155>/countsToRads' */
  real_T torque_f;                     /* '<S155>/countsToRads' */
  real_T digitalInputs_m[2];           /* '<S155>/countsToRads' */
  real_T digitalDiagnostics_c;         /* '<S155>/countsToRads' */
  real_T calibrationButton;            /* '<S155>/countsToRads' */
  real_T DataTypeConversion_bd;        /* '<S154>/Data Type Conversion' */
  real_T driveID_n;                    /* '<S154>/driveID' */
  real_T DataTypeConversion2_nh[2];    /* '<S158>/Data Type Conversion2' */
  real_T DataTypeConversion_p[2];      /* '<S159>/Data Type Conversion' */
  real_T Memory_g;                     /* '<S160>/Memory' */
  real_T DataTypeConversion1_k;        /* '<S160>/Data Type Conversion1' */
  real_T A2M1Convert[5];               /* '<S151>/A2M1Convert' */
  real_T Memory_j;                     /* '<S85>/Memory' */
  real_T Memory_f;                     /* '<S86>/Memory' */
  real_T Memory1_o;                    /* '<S94>/Memory1' */
  real_T Memory2_n;                    /* '<S94>/Memory2' */
  real_T L2select_i;                   /* '<S103>/L2 select' */
  real_T L2select1_h;                  /* '<S103>/L2 select1' */
  real_T L2select2_o;                  /* '<S103>/L2 select2' */
  real_T L2select3_cn;                 /* '<S103>/L2 select3' */
  real_T L2select4_o;                  /* '<S103>/L2 select4' */
  real_T R1_maxContinuousTorque[2];    /* '<S75>/Memory2' */
  real_T L2select5_c;                  /* '<S103>/L2 select5' */
  real_T R1_constantsReady;            /* '<S75>/Memory3' */
  real_T L2select_e;                   /* '<S116>/L2 select' */
  real_T L2select1_hf;                 /* '<S116>/L2 select1' */
  real_T L2select2_d;                  /* '<S116>/L2 select2' */
  real_T L2select3_p;                  /* '<S116>/L2 select3' */
  real_T L2select4_g;                  /* '<S116>/L2 select4' */
  real_T L2select5_f;                  /* '<S116>/L2 select5' */
  real_T R1M1_LinkAngle;               /* '<S75>/Signal Conversion' */
  real_T R1M2_LinkAngle;               /* '<S75>/Signal Conversion' */
  real_T R1M2_PrimaryLinkAngle;        /* '<S75>/Signal Conversion' */
  real_T R1M2_PrimaryLinkVelocity;     /* '<S75>/Signal Conversion' */
  real_T R1M2_RecordedTorque;          /* '<S75>/Signal Conversion' */
  real_T R1M2_digitalInputs[2];        /* '<S75>/Signal Conversion' */
  real_T R1M2_digitalDiagnostics;      /* '<S75>/Signal Conversion' */
  real_T R1M2_EMCY_codes[5];           /* '<S75>/Signal Conversion' */
  real_T R1M1_PrimaryLinkAngle;        /* '<S75>/Signal Conversion' */
  real_T R1M1_PrimaryLinkVelocity;     /* '<S75>/Signal Conversion' */
  real_T R1M1_RecordedTorque;          /* '<S75>/Signal Conversion' */
  real_T R1M1_digitalInputs[2];        /* '<S75>/Signal Conversion' */
  real_T R1M1_digitalDiagnostics;      /* '<S75>/Signal Conversion' */
  real_T R1_calibrationButton;         /* '<S75>/Signal Conversion' */
  real_T R1M1_EMCY_codes[5];           /* '<S75>/Signal Conversion' */
  real_T R1_RobotType;                 /* '<S75>/Signal Conversion1' */
  real_T R1_absAngleOffset[2];         /* '<S75>/Signal Conversion1' */
  real_T R1_LinkLength[2];             /* '<S75>/Signal Conversion1' */
  real_T R1_L2CalibPinOffset;          /* '<S75>/Signal Conversion1' */
  real_T R1_maxContinuousTorque_d[2];  /* '<S75>/Signal Conversion1' */
  real_T R1_gearRatios[2];             /* '<S75>/Signal Conversion1' */
  real_T R1_isCalibrated;              /* '<S75>/Signal Conversion1' */
  real_T R1_OffsetRads[2];             /* '<S75>/Signal Conversion1' */
  real_T R1_OffsetRadsPrimary[2];      /* '<S75>/Signal Conversion1' */
  real_T R1_RobotRevision;             /* '<S75>/Signal Conversion1' */
  real_T R1_constantsReady_p;          /* '<S75>/Signal Conversion1' */
  real_T R1_hasSecondary;              /* '<S75>/Signal Conversion1' */
  real_T R1_hasFT;                     /* '<S75>/Signal Conversion1' */
  real_T R1_robotOrientation;          /* '<S75>/Signal Conversion1' */
  real_T R1_motorOrientation[2];       /* '<S75>/Signal Conversion1' */
  real_T R1_encOrientation[2];         /* '<S75>/Signal Conversion1' */
  real_T R1_encodercounts[2];          /* '<S75>/Signal Conversion1' */
  real_T R1_FTSensorAngleOffset;       /* '<S75>/Signal Conversion1' */
  real_T R1_calibPinAngle[2];          /* '<S75>/Signal Conversion1' */
  real_T RateTransition1_ds;           /* '<S94>/Rate Transition1' */
  real_T RateTransition2_dj;           /* '<S94>/Rate Transition2' */
  real_T encoderCounts_h[2];           /* '<S75>/split out constants' */
  real_T FTSensorOffset_j;             /* '<S75>/split out constants' */
  real_T calibPinAngles_m[2];          /* '<S75>/split out constants' */
  real_T absAngOffsets_c[2];           /* '<S75>/split out constants' */
  real_T linkLengths_j[2];             /* '<S75>/split out constants' */
  real_T L2CalibPinOffset_c;           /* '<S75>/split out constants' */
  real_T continuousTorques_j[2];       /* '<S75>/split out constants' */
  real_T gearRatios_p[2];              /* '<S75>/split out constants' */
  real_T isCalibrated_p;               /* '<S75>/split out constants' */
  real_T offsetRads_f[2];              /* '<S75>/split out constants' */
  real_T offsetRadsPrimary_h[2];       /* '<S75>/split out constants' */
  real_T robotRevision_n;              /* '<S75>/split out constants' */
  real_T constantsReady_j;             /* '<S75>/split out constants' */
  real_T DataTypeConversion_f;         /* '<S135>/Data Type Conversion' */
  real_T writeData_e[5];               /* '<S92>/writeData' */
  real_T status_n;                     /* '<S92>/status' */
  real_T readAddr_p[3];                /* '<S91>/readAddr' */
  real_T Memory_n;                     /* '<S91>/Memory' */
  real_T convert_b;                    /* '<S91>/convert' */
  real_T convert1_f;                   /* '<S91>/convert1' */
  real_T status_d;                     /* '<S91>/status' */
  real_T DataTypeConversion_ba;        /* '<S129>/Data Type Conversion' */
  real_T LinkAngle_g;                  /* '<S116>/countsToRads' */
  real_T PrimaryLinkAngle_b;           /* '<S116>/countsToRads' */
  real_T PrimaryLinkVel_d;             /* '<S116>/countsToRads' */
  real_T torque_g;                     /* '<S116>/countsToRads' */
  real_T digitalInputs_h[2];           /* '<S116>/countsToRads' */
  real_T digitalDiagnostics_a;         /* '<S116>/countsToRads' */
  real_T DataTypeConversion_kb;        /* '<S115>/Data Type Conversion' */
  real_T driveID_a;                    /* '<S115>/driveID' */
  real_T DataTypeConversion2_d[2];     /* '<S119>/Data Type Conversion2' */
  real_T DataTypeConversion_m[2];      /* '<S120>/Data Type Conversion' */
  real_T Memory_d;                     /* '<S121>/Memory' */
  real_T DataTypeConversion1_i;        /* '<S121>/Data Type Conversion1' */
  real_T emcyValPump[3];               /* '<S115>/Read EMCY' */
  real_T A1M2Convert[5];               /* '<S112>/A1M2Convert' */
  real_T LinkAngle_c;                  /* '<S103>/countsToRads' */
  real_T PrimaryLinkAngle_m;           /* '<S103>/countsToRads' */
  real_T PrimaryLinkVel_m;             /* '<S103>/countsToRads' */
  real_T torque_d;                     /* '<S103>/countsToRads' */
  real_T digitalInputs_e[2];           /* '<S103>/countsToRads' */
  real_T digitalDiagnostics_e;         /* '<S103>/countsToRads' */
  real_T calibrationButton_e;          /* '<S103>/countsToRads' */
  real_T DataTypeConversion_c;         /* '<S102>/Data Type Conversion' */
  real_T driveID_n2;                   /* '<S102>/driveID' */
  real_T DataTypeConversion2_j[2];     /* '<S106>/Data Type Conversion2' */
  real_T DataTypeConversion_hm[2];     /* '<S107>/Data Type Conversion' */
  real_T Memory_dp;                    /* '<S108>/Memory' */
  real_T DataTypeConversion1_av;       /* '<S108>/Data Type Conversion1' */
  real_T emcyValPump_g[3];             /* '<S102>/Read EMCY' */
  real_T isPermFaulted_i;              /* '<S85>/Control GDC Whistle State' */
  real_T A1M1Convert[5];               /* '<S99>/A1M1Convert' */
  real_T RateTransition_g;             /* '<S33>/Rate Transition' */
  real_T RateTransition1_h3;           /* '<S33>/Rate Transition1' */
  real_T Convert19_e[14];              /* '<S33>/Convert19' */
  real_T Receive1_o2;                  /* '<S59>/Receive1' */
  real_T forces[3];                    /* '<S59>/parse packet 1' */
  real_T moments[3];                   /* '<S59>/parse packet 1' */
  real_T timer;                        /* '<S59>/parse packet 1' */
  real_T Receive_o2_m;                 /* '<S58>/Receive' */
  real_T forces_g[3];                  /* '<S58>/parse packet 1' */
  real_T moments_p[3];                 /* '<S58>/parse packet 1' */
  real_T timer_c;                      /* '<S58>/parse packet 1' */
  real_T trigger;                      /* '<S50>/Memory2' */
  real_T RateTransition2_js[3];        /* '<S50>/Rate Transition2' */
  real_T Pckt_Recd;                    /* '<S50>/UDP Receive' */
  real_T Pckt_Recd2;                   /* '<S50>/UDP Receive' */
  real_T doublereads;                  /* '<S50>/UDP Receive' */
  real_T UDPReceive_o6;                /* '<S50>/UDP Receive' */
  real_T TmpRTBAtforcestrobeOutport1;  /* '<S32>/force strobe' */
  real_T TaskClock_a;                  /* '<S32>/Task Clock' */
  real_T queue_size;                   /* '<S32>/Queue Size' */
  real_T timeouts;                     /* '<S32>/Total Timeouts' */
  real_T RqstUDPReset;                 /* '<S50>/Rate Transition1' */
  real_T UDPResets;                    /* '<S50>/UDP Receive Port Reset' */
  real_T UDPReceivePortReset_o2[3];    /* '<S50>/UDP Receive Port Reset' */
  real_T strobe_out;                   /* '<S32>/force strobe' */
  real_T resetUDP;                     /* '<S32>/Send Control Machine' */
  real_T queue_size_e;                 /* '<S32>/Send Control Machine' */
  real_T total_timeouts;               /* '<S32>/Send Control Machine' */
  real_T UnitDelay_h;                  /* '<S53>/Unit Delay' */
  real_T Sum;                          /* '<S53>/Sum' */
  real_T Width;                        /* '<S48>/Width' */
  real_T IdealFramesPerPacket;         /* '<S48>/Ideal Frames Per Packet' */
  real_T MinMax_k;                     /* '<S48>/MinMax' */
  real_T MathFunction_j;               /* '<S48>/Math Function' */
  real_T Subtract_o;                   /* '<S48>/Subtract' */
  real_T Product_l;                    /* '<S48>/Product' */
  real_T dd_out[2];                    /* '<S42>/MATLAB Function' */
  real_T VCODE_MOD[140];               /* '<Root>/AddTxt2TgtC' */
  real_T VCODE_MOD_n[140];             /* '<Root>/AddTxt2TgtB' */
  real32_T DataTypeConversion6[4];     /* '<S252>/Data Type Conversion6' */
  real32_T DataTypeConversion_a[6];    /* '<S252>/Data Type Conversion' */
  real32_T DataTypeConversion1_cq[6];  /* '<S252>/Data Type Conversion1' */
  real32_T pupilX[2];                  /* '<S35>/S-Function' */
  real32_T pupilY[2];                  /* '<S35>/S-Function' */
  real32_T HREFX[2];                   /* '<S35>/S-Function' */
  real32_T HREFY[2];                   /* '<S35>/S-Function' */
  real32_T pupilarea[2];               /* '<S35>/S-Function' */
  real32_T screengazeX[2];             /* '<S35>/S-Function' */
  real32_T screengazeY[2];             /* '<S35>/S-Function' */
  real32_T resolutionX;                /* '<S35>/S-Function' */
  real32_T resolutionY;                /* '<S35>/S-Function' */
  real32_T Reshape_i[8];               /* '<S35>/Reshape' */
  real32_T SelectorLeftEye[4];         /* '<S35>/Selector - Left Eye' */
  real32_T Unpack_o1[2];               /* '<S223>/Unpack' */
  real32_T Unpack_o2[2];               /* '<S223>/Unpack' */
  real32_T DataTypeConversion_a5[10];  /* '<S210>/Data Type Conversion' */
  real32_T DataTypeConversion1_i1[10]; /* '<S210>/Data Type Conversion1' */
  real32_T DataTypeConversion2_h;      /* '<S210>/Data Type Conversion2' */
  real32_T SFunction_o1[10];           /* '<S210>/S-Function' */
  real32_T SFunction_o2[10];           /* '<S210>/S-Function' */
  real32_T SFunction_o4[4];            /* '<S210>/S-Function' */
  real32_T SFunction_o5[6];            /* '<S210>/S-Function' */
  real32_T SFunction_o6[6];            /* '<S210>/S-Function' */
  real32_T SFunction_o10;              /* '<S210>/S-Function' */
  real32_T y_j;                        /* '<S212>/TypeCast' */
  real32_T DataTypeConversion1_o;      /* '<S219>/Data Type Conversion1' */
  real32_T Read_h;                     /* '<S217>/Read' */
  real32_T DataTypeConversion2_k;      /* '<S32>/Data Type Conversion2' */
  real32_T TmpRTBAtSendControlMachineInport1[400];/* '<S32>/Data Packing Subsystem' */
  real32_T Unpack;                     /* '<S50>/Unpack' */
  real32_T data_out[410];              /* '<S32>/Send Control Machine' */
  real32_T DataTypeConversion_p1[127]; /* '<S48>/Data Type Conversion' */
  real32_T t2[127];                    /* '<S48>/t-2' */
  real32_T t1[127];                    /* '<S48>/t-1' */
  real32_T TmpSignalConversionAtSelectorInport1[781];
  real32_T Selector_e[400];            /* '<S48>/Selector' */
  int32_T Abs_f;                       /* '<S6>/Abs' */
  int32_T feedback_text;               /* '<Root>/Trial_Control' */
  int32_T vis_cmd[6810];               /* '<S298>/Pack VCodeFrame2' */
  int32_T convert_bp;                  /* '<S35>/convert' */
  int32_T len_out;                     /* '<S35>/clean_packet' */
  int32_T BKINEtherCATinit1_o1[6];     /* '<S64>/BKIN EtherCATinit1' */
  int32_T BKINEtherCATinit1_o2;        /* '<S64>/BKIN EtherCATinit1' */
  int32_T BKINEtherCATinit1_o3;        /* '<S64>/BKIN EtherCATinit1' */
  int32_T BKINEtherCATinit_o1[6];      /* '<S64>/BKIN EtherCATinit' */
  int32_T BKINEtherCATinit_o2;         /* '<S64>/BKIN EtherCATinit' */
  int32_T BKINEtherCATinit_o3;         /* '<S64>/BKIN EtherCATinit' */
  int32_T Switch_m[8];                 /* '<S64>/Switch' */
  int32_T Unpack_o2_o[6];              /* '<S202>/Unpack' */
  int32_T ByteReversal[6];             /* '<S202>/Byte Reversal' */
  int32_T Unpack1_o2[6];               /* '<S203>/Unpack1' */
  int32_T ByteReversal_o[6];           /* '<S203>/Byte Reversal' */
  int32_T errVal;                      /* '<S80>/split init' */
  int32_T masterState;                 /* '<S80>/split init' */
  int32_T DCErrVal;                    /* '<S80>/split init' */
  int32_T MasterToNetworkClkDiff;      /* '<S80>/split init' */
  int32_T DCInitState;                 /* '<S80>/split init' */
  int32_T NetworkToSlaveClkDiff;       /* '<S80>/split init' */
  int32_T readTrigger;                 /* '<S76>/readTrigger' */
  int32_T Memory_p;                    /* '<S146>/Memory' */
  int32_T RateTransition_bx;           /* '<S146>/Rate Transition' */
  int32_T BKINEtherCATAsyncSDOUpload1_o2;/* '<S187>/BKIN EtherCAT Async SDO Upload1' */
  int32_T Memory_lf;                   /* '<S144>/Memory' */
  int32_T DataTypeConversion2_p;       /* '<S144>/Data Type Conversion2' */
  int32_T DataTypeConversion1_aq;      /* '<S144>/Data Type Conversion1' */
  int32_T BKINEtherCATAsyncSDODownload;/* '<S144>/BKIN EtherCAT Async SDO Download' */
  int32_T DataTypeConversion1_k2;      /* '<S143>/Data Type Conversion1' */
  int32_T DataTypeConversion2_m;       /* '<S143>/Data Type Conversion2' */
  int32_T BKINEtherCATAsyncSDOUpload1_o2_a;/* '<S181>/BKIN EtherCAT Async SDO Upload1' */
  int32_T Memory_pb;                   /* '<S141>/Memory' */
  int32_T Memory1_et[2];               /* '<S141>/Memory1' */
  int32_T BKINEtherCATAsyncSDODownload_g;/* '<S141>/BKIN EtherCAT Async SDO Download' */
  int32_T BKINEtherCATAsyncSDOUpload_o1;/* '<S141>/BKIN EtherCAT Async SDO Upload' */
  int32_T BKINEtherCATAsyncSDOUpload_o2;/* '<S141>/BKIN EtherCAT Async SDO Upload' */
  int32_T Memory_h;                    /* '<S140>/Memory' */
  int32_T Memory1_f[2];                /* '<S140>/Memory1' */
  int32_T BKINEtherCATAsyncSDODownload_g0;/* '<S140>/BKIN EtherCAT Async SDO Download' */
  int32_T BKINEtherCATAsyncSDOUpload_o1_k;/* '<S140>/BKIN EtherCAT Async SDO Upload' */
  int32_T BKINEtherCATAsyncSDOUpload_o2_o;/* '<S140>/BKIN EtherCAT Async SDO Upload' */
  int32_T Memory_f3[2];                /* '<S172>/Memory' */
  int32_T DataTypeConversion_dc;       /* '<S171>/Data Type Conversion' */
  int32_T BKINEtherCATAsyncSDOUpload_o2_i;/* '<S171>/BKIN EtherCAT Async SDO Upload' */
  int32_T BKINEtherCATAsyncSDOUpload_o1_f;/* '<S172>/BKIN EtherCAT Async SDO Upload' */
  int32_T BKINEtherCATAsyncSDOUpload_o2_j;/* '<S172>/BKIN EtherCAT Async SDO Upload' */
  int32_T RateTransition_i[2];         /* '<S172>/Rate Transition' */
  int32_T DataTypeConversion_dh;       /* '<S173>/Data Type Conversion' */
  int32_T BKINEtherCATAsyncSDODownload_gy;/* '<S173>/BKIN EtherCAT Async SDO Download' */
  int32_T positionprimary;             /* '<S164>/BKIN PDO Receive ElmoDrive' */
  int32_T positionsecondary;           /* '<S164>/BKIN PDO Receive ElmoDrive' */
  int32_T velocityprimary;             /* '<S164>/BKIN PDO Receive ElmoDrive' */
  int32_T digitalinput;                /* '<S164>/BKIN PDO Receive ElmoDrive' */
  int32_T DataTypeConversion_bv;       /* '<S164>/Data Type Conversion' */
  int32_T Memory_a[2];                 /* '<S159>/Memory' */
  int32_T DataTypeConversion_b3;       /* '<S158>/Data Type Conversion' */
  int32_T BKINEtherCATAsyncSDOUpload_o2_c;/* '<S158>/BKIN EtherCAT Async SDO Upload' */
  int32_T BKINEtherCATAsyncSDOUpload_o1_d;/* '<S159>/BKIN EtherCAT Async SDO Upload' */
  int32_T BKINEtherCATAsyncSDOUpload_o2_p;/* '<S159>/BKIN EtherCAT Async SDO Upload' */
  int32_T RateTransition_k4[2];        /* '<S159>/Rate Transition' */
  int32_T DataTypeConversion_ek;       /* '<S160>/Data Type Conversion' */
  int32_T BKINEtherCATAsyncSDODownload_c;/* '<S160>/BKIN EtherCAT Async SDO Download' */
  int32_T primaryposition;             /* '<S151>/BKIN PDO Receive ElmoDrive' */
  int32_T secondaryposition;           /* '<S151>/BKIN PDO Receive ElmoDrive' */
  int32_T primaryvelocity;             /* '<S151>/BKIN PDO Receive ElmoDrive' */
  int32_T digitalinput_d;              /* '<S151>/BKIN PDO Receive ElmoDrive' */
  int32_T DataTypeConversion_et;       /* '<S151>/Data Type Conversion' */
  int32_T readTrigger_k;               /* '<S75>/readTrigger' */
  int32_T Memory_d3;                   /* '<S94>/Memory' */
  int32_T RateTransition_bs;           /* '<S94>/Rate Transition' */
  int32_T BKINEtherCATAsyncSDOUpload1_o2_g;/* '<S135>/BKIN EtherCAT Async SDO Upload1' */
  int32_T Memory_nf;                   /* '<S92>/Memory' */
  int32_T DataTypeConversion2_b;       /* '<S92>/Data Type Conversion2' */
  int32_T DataTypeConversion1_d;       /* '<S92>/Data Type Conversion1' */
  int32_T BKINEtherCATAsyncSDODownload_f;/* '<S92>/BKIN EtherCAT Async SDO Download' */
  int32_T DataTypeConversion1_dx;      /* '<S91>/Data Type Conversion1' */
  int32_T DataTypeConversion2_l;       /* '<S91>/Data Type Conversion2' */
  int32_T BKINEtherCATAsyncSDOUpload1_o2_i;/* '<S129>/BKIN EtherCAT Async SDO Upload1' */
  int32_T Memory_n0;                   /* '<S89>/Memory' */
  int32_T Memory1_n[2];                /* '<S89>/Memory1' */
  int32_T BKINEtherCATAsyncSDODownload_ce;/* '<S89>/BKIN EtherCAT Async SDO Download' */
  int32_T BKINEtherCATAsyncSDOUpload_o1_dq;/* '<S89>/BKIN EtherCAT Async SDO Upload' */
  int32_T BKINEtherCATAsyncSDOUpload_o2_m;/* '<S89>/BKIN EtherCAT Async SDO Upload' */
  int32_T Memory_c;                    /* '<S88>/Memory' */
  int32_T Memory1_b[2];                /* '<S88>/Memory1' */
  int32_T BKINEtherCATAsyncSDODownload_i;/* '<S88>/BKIN EtherCAT Async SDO Download' */
  int32_T BKINEtherCATAsyncSDOUpload_o1_p;/* '<S88>/BKIN EtherCAT Async SDO Upload' */
  int32_T BKINEtherCATAsyncSDOUpload_o2_a;/* '<S88>/BKIN EtherCAT Async SDO Upload' */
  int32_T Memory_kw[2];                /* '<S120>/Memory' */
  int32_T DataTypeConversion_n;        /* '<S119>/Data Type Conversion' */
  int32_T BKINEtherCATAsyncSDOUpload_o2_d;/* '<S119>/BKIN EtherCAT Async SDO Upload' */
  int32_T BKINEtherCATAsyncSDOUpload_o1_n;/* '<S120>/BKIN EtherCAT Async SDO Upload' */
  int32_T BKINEtherCATAsyncSDOUpload_o2_k;/* '<S120>/BKIN EtherCAT Async SDO Upload' */
  int32_T RateTransition_o[2];         /* '<S120>/Rate Transition' */
  int32_T DataTypeConversion_gy;       /* '<S121>/Data Type Conversion' */
  int32_T BKINEtherCATAsyncSDODownload_a;/* '<S121>/BKIN EtherCAT Async SDO Download' */
  int32_T triggerCountRead;            /* '<S115>/Read EMCY' */
  int32_T emcyReadTrigger[2];          /* '<S115>/Read EMCY' */
  int32_T countOverwriteTrigger;       /* '<S115>/Read EMCY' */
  int32_T primaryposition_e;           /* '<S112>/BKIN PDO Receive ElmoDrive' */
  int32_T secondaryposition_d;         /* '<S112>/BKIN PDO Receive ElmoDrive' */
  int32_T primaryvelocity_p;           /* '<S112>/BKIN PDO Receive ElmoDrive' */
  int32_T digitalinputs;               /* '<S112>/BKIN PDO Receive ElmoDrive' */
  int32_T DataTypeConversion_em;       /* '<S112>/Data Type Conversion' */
  int32_T Memory_ne[2];                /* '<S107>/Memory' */
  int32_T DataTypeConversion_je;       /* '<S106>/Data Type Conversion' */
  int32_T BKINEtherCATAsyncSDOUpload_o2_db;/* '<S106>/BKIN EtherCAT Async SDO Upload' */
  int32_T BKINEtherCATAsyncSDOUpload_o1_h;/* '<S107>/BKIN EtherCAT Async SDO Upload' */
  int32_T BKINEtherCATAsyncSDOUpload_o2_di;/* '<S107>/BKIN EtherCAT Async SDO Upload' */
  int32_T RateTransition_cg[2];        /* '<S107>/Rate Transition' */
  int32_T DataTypeConversion_mf;       /* '<S108>/Data Type Conversion' */
  int32_T BKINEtherCATAsyncSDODownload_n;/* '<S108>/BKIN EtherCAT Async SDO Download' */
  int32_T triggerCountRead_n;          /* '<S102>/Read EMCY' */
  int32_T emcyReadTrigger_e[2];        /* '<S102>/Read EMCY' */
  int32_T countOverwriteTrigger_n;     /* '<S102>/Read EMCY' */
  int32_T primaryposition_l;           /* '<S99>/BKIN PDO Receive ElmoDrive' */
  int32_T secondaryposition_n;         /* '<S99>/BKIN PDO Receive ElmoDrive' */
  int32_T primaryvelocity_d;           /* '<S99>/BKIN PDO Receive ElmoDrive' */
  int32_T digitalinputs_j;             /* '<S99>/BKIN PDO Receive ElmoDrive' */
  int32_T DataTypeConversion1_j1;      /* '<S99>/Data Type Conversion1' */
  uint32_T Convert19_b;                /* '<S7>/Convert19' */
  uint32_T Convert20;                  /* '<S7>/Convert20' */
  uint32_T Convert21;                  /* '<S7>/Convert21' */
  uint32_T Convert22;                  /* '<S7>/Convert22' */
  uint32_T Convert23;                  /* '<S7>/Convert23' */
  uint32_T Convert24;                  /* '<S7>/Convert24' */
  uint32_T total_trials_in_exam;       /* '<S270>/Data Type Conversion' */
  uint32_T total_trials_in_block;      /* '<S270>/Data Type Conversion1' */
  uint32_T total_blocks_in_exam;       /* '<S270>/Data Type Conversion2' */
  uint32_T Output;                     /* '<S44>/Output' */
  uint32_T Unpack_c;                   /* '<S15>/Unpack' */
  uint32_T touint[6];                  /* '<S29>/touint' */
  uint32_T RateTransition1_n;          /* '<S29>/Rate Transition1' */
  uint32_T FixPtSum1;                  /* '<S46>/FixPt Sum1' */
  uint32_T FixPtSwitch;                /* '<S47>/FixPt Switch' */
  uint32_T readDigitaldiag[4];         /* '<S4>/read Digital diag' */
  uint32_T frame_number;               /* '<S298>/Pack VCodeFrame2' */
  uint32_T Width_j;                    /* '<S269>/Width' */
  uint32_T Subtract_p;                 /* '<S269>/Subtract' */
  uint32_T Width2;                     /* '<S269>/Width2' */
  uint32_T task_status;                /* '<S269>/Task Execution Control Machine' */
  uint32_T tp;                         /* '<S269>/Task Execution Control Machine' */
  uint32_T block;                      /* '<S269>/Task Execution Control Machine' */
  uint32_T trial_in_block;             /* '<S269>/Task Execution Control Machine' */
  uint32_T block_in_set;               /* '<S269>/Task Execution Control Machine' */
  uint32_T trial_in_set;               /* '<S269>/Task Execution Control Machine' */
  uint32_T SFunction_o1_n;             /* '<S35>/S-Function' */
  uint32_T SFunction_o18[3];           /* '<S35>/S-Function' */
  uint32_T TmpRTBAtconverttoseconds2Inport3;
  uint32_T Output_a;                   /* '<S78>/Output' */
  uint32_T FixPtSum1_e;                /* '<S189>/FixPt Sum1' */
  uint32_T FixPtSwitch_m;              /* '<S190>/FixPt Switch' */
  uint32_T ServoRead;                  /* '<S70>/Servo Read' */
  uint32_T DataStoreRead_l;            /* '<S70>/Data Store Read' */
  uint32_T Statusread1_e[8];           /* '<S70>/Status read1' */
  uint32_T Output_h;                   /* '<S235>/Output' */
  uint32_T FixPtSum1_o;                /* '<S240>/FixPt Sum1' */
  uint32_T FixPtSwitch_h;              /* '<S241>/FixPt Switch' */
  uint32_T DataTypeConversion_nq[6];   /* '<S70>/Data Type Conversion' */
  uint32_T Statusread[7];              /* '<S70>/Status read' */
  uint32_T statusInts[4];              /* '<S70>/bitpack' */
  uint32_T outStatus[7];               /* '<S211>/update status format' */
  uint32_T DataTypeConversion1_ju[2];  /* '<S84>/Data Type Conversion1' */
  uint32_T DataTypeConversion_jq[8];   /* '<S84>/Data Type Conversion' */
  uint32_T DataTypeConversion4_j[4];   /* '<S84>/Data Type Conversion4' */
  uint32_T DataTypeConversion2_ir;     /* '<S84>/Data Type Conversion2' */
  uint32_T servoCounterOut;            /* '<S84>/create servo counter' */
  uint32_T TmpSignalConversionAtSFunctionInport5[4];/* '<S84>/create kinematics' */
  uint32_T bitField;                   /* '<S84>/convert to bit field' */
  uint32_T Output_e;                   /* '<S226>/Output' */
  uint32_T FixPtSum1_n;                /* '<S228>/FixPt Sum1' */
  uint32_T FixPtSwitch_d;              /* '<S229>/FixPt Switch' */
  uint32_T Constant;                   /* '<S223>/Constant' */
  uint32_T Constant1[7];               /* '<S223>/Constant1' */
  uint32_T SFunction_o3[2];            /* '<S210>/S-Function' */
  uint32_T SFunction_o7;               /* '<S210>/S-Function' */
  uint32_T SFunction_o8;               /* '<S210>/S-Function' */
  uint32_T SFunction_o9[3];            /* '<S210>/S-Function' */
  uint32_T DataTypeConversion_l;       /* '<S212>/Data Type Conversion' */
  uint32_T Convert2_n[3];              /* '<S210>/Convert2' */
  uint32_T MinMax_b;                   /* '<S210>/MinMax' */
  uint32_T MinMax1;                    /* '<S210>/MinMax1' */
  uint32_T DataTypeConversion_dd;      /* '<S219>/Data Type Conversion' */
  uint32_T DataTypeConversion_pj;      /* '<S217>/Data Type Conversion' */
  uint32_T DataTypeConversion2_pm;     /* '<S217>/Data Type Conversion2' */
  uint32_T Unpack_o1_m[3];             /* '<S202>/Unpack' */
  uint32_T ByteReversal1[3];           /* '<S202>/Byte Reversal1' */
  uint32_T Unpack1_o1[3];              /* '<S203>/Unpack1' */
  uint32_T ByteReversal1_f[3];         /* '<S203>/Byte Reversal1' */
  uint32_T ByteReversal_g;             /* '<S208>/Byte Reversal' */
  uint32_T ByteReversal2;              /* '<S206>/Byte Reversal2' */
  uint32_T drive1;                     /* '<S79>/update digital outputs' */
  uint32_T drive2;                     /* '<S79>/update digital outputs' */
  uint32_T drive3;                     /* '<S79>/update digital outputs' */
  uint32_T drive4;                     /* '<S79>/update digital outputs' */
  uint32_T R2M2_CurrentLimitEnabled;   /* '<S76>/Signal Conversion' */
  uint32_T R2M1_CurrentLimitEnabled;   /* '<S76>/Signal Conversion' */
  uint32_T BKINEtherCATAsyncSDOUpload1_o1;/* '<S187>/BKIN EtherCAT Async SDO Upload1' */
  uint32_T BKINEtherCATAsyncSDOUpload1_o1_f;/* '<S181>/BKIN EtherCAT Async SDO Upload1' */
  uint32_T Memory_kg[2];               /* '<S171>/Memory' */
  uint32_T BKINEtherCATAsyncSDOUpload_o1_m;/* '<S171>/BKIN EtherCAT Async SDO Upload' */
  uint32_T DataTypeConversion1_of;     /* '<S171>/Data Type Conversion1' */
  uint32_T RateTransition_gy[2];       /* '<S171>/Rate Transition' */
  uint32_T motorStatus;                /* '<S138>/Control GDC Whistle State' */
  uint32_T statusregister;             /* '<S164>/BKIN PDO Receive ElmoDrive' */
  uint32_T Memory_c1[2];               /* '<S158>/Memory' */
  uint32_T BKINEtherCATAsyncSDOUpload_o1_l;/* '<S158>/BKIN EtherCAT Async SDO Upload' */
  uint32_T DataTypeConversion1_ij;     /* '<S158>/Data Type Conversion1' */
  uint32_T RateTransition_l[2];        /* '<S158>/Rate Transition' */
  uint32_T statusregister_i;           /* '<S151>/BKIN PDO Receive ElmoDrive' */
  uint32_T R1M2_CurrentLimitEnabled;   /* '<S75>/Signal Conversion' */
  uint32_T R1M1_CurrentLimitEnabled;   /* '<S75>/Signal Conversion' */
  uint32_T BKINEtherCATAsyncSDOUpload1_o1_l;/* '<S135>/BKIN EtherCAT Async SDO Upload1' */
  uint32_T BKINEtherCATAsyncSDOUpload1_o1_p;/* '<S129>/BKIN EtherCAT Async SDO Upload1' */
  uint32_T Memory_d4[2];               /* '<S119>/Memory' */
  uint32_T BKINEtherCATAsyncSDOUpload_o1_ln;/* '<S119>/BKIN EtherCAT Async SDO Upload' */
  uint32_T DataTypeConversion1_ke;     /* '<S119>/Data Type Conversion1' */
  uint32_T RateTransition_m[2];        /* '<S119>/Rate Transition' */
  uint32_T statusregister_c;           /* '<S112>/BKIN PDO Receive ElmoDrive' */
  uint32_T Memory_pr[2];               /* '<S106>/Memory' */
  uint32_T BKINEtherCATAsyncSDOUpload_o1_b;/* '<S106>/BKIN EtherCAT Async SDO Upload' */
  uint32_T DataTypeConversion1_jd;     /* '<S106>/Data Type Conversion1' */
  uint32_T RateTransition_e[2];        /* '<S106>/Rate Transition' */
  uint32_T motorStatus_f;              /* '<S85>/Control GDC Whistle State' */
  uint32_T statusregister_c4;          /* '<S99>/BKIN PDO Receive ElmoDrive' */
  uint32_T DataTypeConversion_cb;      /* '<S50>/Data Type Conversion' */
  uint32_T max_packet_id;              /* '<S32>/max_packet_id' */
  uint32_T Output_n;                   /* '<S54>/Output' */
  uint32_T FixPtSum1_eh;               /* '<S56>/FixPt Sum1' */
  uint32_T FixPtSwitch_dp;             /* '<S57>/FixPt Switch' */
  uint32_T TmpSignalConversionAtSFunctionInport1_m[2];/* '<S42>/MATLAB Function' */
  uint32_T bitfield;                   /* '<S29>/bitfield' */
  int16_T ecatTorques[4];              /* '<S251>/convert torques' */
  int16_T SAMPE_TYPE;                  /* '<S35>/S-Function' */
  int16_T htype;                       /* '<S35>/S-Function' */
  int16_T hdata[8];                    /* '<S35>/S-Function' */
  int16_T torque_k;                    /* '<S164>/BKIN PDO Receive ElmoDrive' */
  int16_T torque_g5;                   /* '<S151>/BKIN PDO Receive ElmoDrive' */
  int16_T torque_h;                    /* '<S112>/BKIN PDO Receive ElmoDrive' */
  int16_T torque_ky;                   /* '<S99>/BKIN PDO Receive ElmoDrive' */
  uint16_T event_code;                 /* '<Root>/Trial_Control' */
  uint16_T ContentFlags;               /* '<S35>/S-Function' */
  uint16_T statusflags;                /* '<S35>/S-Function' */
  uint16_T extrainput;                 /* '<S35>/S-Function' */
  uint16_T buttons;                    /* '<S35>/S-Function' */
  uint16_T Output_b;                   /* '<S216>/Output' */
  uint16_T FixPtSum1_ea;               /* '<S220>/FixPt Sum1' */
  uint16_T FixPtSwitch_j;              /* '<S221>/FixPt Switch' */
  uint16_T ByteReversal1_a;            /* '<S208>/Byte Reversal1' */
  uint16_T Switch_g;                   /* '<S208>/Switch' */
  uint16_T ByteReversal2_g;            /* '<S208>/Byte Reversal2' */
  uint16_T ByteReversal1_m;            /* '<S206>/Byte Reversal1' */
  uint16_T Switch_n;                   /* '<S206>/Switch' */
  uint16_T ByteReversal_n;             /* '<S206>/Byte Reversal' */
  uint16_T ControlWord;                /* '<S138>/Control GDC Whistle State' */
  uint16_T statusword;                 /* '<S164>/BKIN PDO Receive ElmoDrive' */
  uint16_T Statusword;                 /* '<S151>/BKIN PDO Receive ElmoDrive' */
  uint16_T Statusword_b;               /* '<S112>/BKIN PDO Receive ElmoDrive' */
  uint16_T ControlWord_o;              /* '<S85>/Control GDC Whistle State' */
  uint16_T Statusword_k;               /* '<S99>/BKIN PDO Receive ElmoDrive' */
  int8_T inputevents[3];               /* '<Root>/Trial_Control' */
  int8_T inputevents_h[2];             /* '<S269>/Task Execution Control Machine' */
  int8_T TorqueMode;                   /* '<S76>/Torque Mode' */
  int8_T actualmodeofoperation;        /* '<S164>/BKIN PDO Receive ElmoDrive' */
  int8_T actualmodeofoperation_j;      /* '<S151>/BKIN PDO Receive ElmoDrive' */
  int8_T TorqueMode_i;                 /* '<S75>/Torque Mode' */
  int8_T actualmodeofoperation_a;      /* '<S112>/BKIN PDO Receive ElmoDrive' */
  int8_T actualmodeofoperation_g;      /* '<S99>/BKIN PDO Receive ElmoDrive' */
  int8_T inputevents_o[3];             /* '<S32>/Send Control Machine' */
  uint8_T RunCommandReceive_o1;        /* '<S268>/Run Command Receive' */
  uint8_T DataTypeConversion1_gw;      /* '<S268>/Data Type Conversion1' */
  uint8_T Compare;                     /* '<S45>/Compare' */
  uint8_T Receive_o1[4];               /* '<S15>/Receive' */
  uint8_T SFunctionBuilder_o1[27240];  /* '<S296>/S-Function Builder' */
  uint8_T Compare_o;                   /* '<S275>/Compare' */
  uint8_T Receive_o1_i[512];           /* '<S35>/Receive' */
  uint8_T pack_out[512];               /* '<S35>/clean_packet' */
  uint8_T Compare_i;                   /* '<S77>/Compare' */
  uint8_T Receive_o1_n[16];            /* '<S223>/Receive' */
  uint8_T FixPtRelationalOperator;     /* '<S205>/FixPt Relational Operator' */
  uint8_T ReceivefromRobot1ForceSensor_o1[36];/* '<S202>/Receive from Robot 1 Force Sensor' */
  uint8_T FixPtRelationalOperator_i;   /* '<S209>/FixPt Relational Operator' */
  uint8_T ReceivefromRobot2ForceSensor_o1[36];/* '<S203>/Receive from Robot 2 Force Sensor' */
  uint8_T Pack[8];                     /* '<S208>/Pack' */
  uint8_T Pack_f[8];                   /* '<S206>/Pack' */
  uint8_T Convert1_c[34];              /* '<S33>/Convert1' */
  uint8_T TmpRTBAtConvert1Outport1[34];/* '<S33>/Convert1' */
  uint8_T Receive1_o1[64];             /* '<S59>/Receive1' */
  uint8_T Receive_o1_k[64];            /* '<S58>/Receive' */
  uint8_T Data[21];                    /* '<S50>/UDP Receive' */
  uint8_T Data2[21];                   /* '<S50>/UDP Receive' */
  uint8_T Pack_i[1640];                /* '<S51>/Pack' */
  uint8_T Pack_g[40];                  /* '<S31>/Pack' */
  boolean_T Convert25;                 /* '<S7>/Convert25' */
  boolean_T Compare_k;                 /* '<S3>/Compare' */
  boolean_T LogicalOperator;           /* '<S6>/Logical Operator' */
  boolean_T VectorConcatenate1[4];     /* '<Root>/Vector Concatenate1' */
  boolean_T e_Trial_End;               /* '<Root>/Trial_Control' */
  boolean_T Delay;                     /* '<S269>/Delay' */
  boolean_T DataTypeConversion1_m;     /* '<S269>/Data Type Conversion1' */
  boolean_T e_exit_trial;              /* '<S269>/Task Execution Control Machine' */
  boolean_T Compare_b;                 /* '<S253>/Compare' */
  boolean_T Compare_l;                 /* '<S254>/Compare' */
  boolean_T Compare_n;                 /* '<S71>/Compare' */
  boolean_T Compare_a;                 /* '<S225>/Compare' */
  boolean_T Compare_c;                 /* '<S72>/Compare' */
  boolean_T motorEnableState;          /* '<S64>/setState' */
  boolean_T Compare_oe;                /* '<S152>/Compare' */
  boolean_T Compare_oo;                /* '<S165>/Compare' */
  boolean_T Compare_g;                 /* '<S100>/Compare' */
  boolean_T Compare_h;                 /* '<S113>/Compare' */
  boolean_T TmpRTBAtforcestrobeInport1;/* '<S32>/Data Packing Subsystem' */
  boolean_T RelationalOperator;        /* '<S48>/Relational Operator' */
  B_EmbeddedMATLABFunction_gbyk_v4b_T sf_EmbeddedMATLABFunction_i;/* '<S24>/Embedded MATLAB Function' */
  B_EmbeddedMATLABFunction_gbyk_v4b_p_T sf_EmbeddedMATLABFunction_id;/* '<S23>/Embedded MATLAB Function' */
  B_EmbeddedMATLABFunction_gbyk_v4b_p_T sf_EmbeddedMATLABFunction_k;/* '<S22>/Embedded MATLAB Function' */
  B_EmbeddedMATLABFunction_gbyk_v4b_T sf_EmbeddedMATLABFunction_c;/* '<S21>/Embedded MATLAB Function' */
  B_EmbeddedMATLABWhichHand_gbyk_v4b_T sf_EmbeddedMATLABWhichHand;/* '<S11>/Embedded MATLAB WhichHand' */
  B_EmbeddedMATLABWhichHand_gbyk_v4b_T sf_EmbeddedMATLABWhichHand_k;/* '<S10>/Embedded MATLAB WhichHand' */
  B_EmbeddedMATLABWhichHand_gbyk_v4b_T sf_EmbeddedMATLABWhichHand_d;/* '<S9>/Embedded MATLAB WhichHand' */
  B_EmbeddedMATLABFunction_gbyk_v4b_T sf_EmbeddedMATLABFunction_b;/* '<S262>/Embedded MATLAB Function' */
  B_MATLABFunction_gbyk_v4b_T sf_MATLABFunction1;/* '<S259>/MATLAB Function1' */
  B_MATLABFunction_gbyk_v4b_T sf_MATLABFunction_o;/* '<S259>/MATLAB Function' */
  B_split_primary_gbyk_v4b_T sf_split_primary1;/* '<S74>/split_primary1' */
  B_split_primary_gbyk_v4b_T sf_split_primary;/* '<S74>/split_primary' */
  B_decoderobot_gbyk_v4b_T sf_decoderobot_p;/* '<S231>/decode robot' */
  B_decoderobot_gbyk_v4b_T sf_decoderobot;/* '<S230>/decode robot' */
  B_Createtimestamp_gbyk_v4b_T sf_Createtimestamp_b;/* '<S203>/Create timestamp' */
  B_Createtimestamp_gbyk_v4b_T sf_Createtimestamp;/* '<S202>/Create timestamp' */
  B_splitoutconstants1_gbyk_v4b_T sf_splitoutconstants1_o;/* '<S76>/split out constants1' */
  B_size_gbyk_v4b_T sf_size1_e;        /* '<S76>/size1' */
  B_size_gbyk_v4b_T sf_size_d;         /* '<S76>/size' */
  B_converter_gbyk_v4b_T sf_converter_jl;/* '<S187>/converter' */
  B_forceEnableDisable_gbyk_v4b_T sf_forceEnableDisable_k;/* '<S76>/forceEnableDisable' */
  B_convert_gbyk_v4b_T sf_convert_i;   /* '<S144>/convert' */
  B_SDOwritemachine_gbyk_v4b_T sf_SDOwritemachine_j;/* '<S144>/SDO write machine' */
  B_values_gbyk_v4b_T sf_values_n;     /* '<S143>/values' */
  B_SDOreadmachine_gbyk_v4b_n_T sf_SDOreadmachine_g;/* '<S143>/SDO read machine' */
  B_converter_gbyk_v4b_T sf_converter_j;/* '<S181>/converter' */
  B_SDOreadmachine_gbyk_v4b_T sf_SDOreadmachine_h;/* '<S76>/SDO read machine' */
  B_setupvalues_gbyk_v4b_T sf_setupvalues_g;/* '<S141>/set-up values' */
  B_AbsEncodermachine_gbyk_v4b_T sf_AbsEncodermachine_k;/* '<S141>/AbsEncoder machine' */
  B_setupvalues_gbyk_v4b_T sf_setupvalues_k;/* '<S140>/set-up values' */
  B_AbsEncodermachine_gbyk_v4b_T sf_AbsEncodermachine_i;/* '<S140>/AbsEncoder machine' */
  B_FindRobottype_gbyk_v4b_T sf_FindRobottype_d;/* '<S76>/Find Robot type' */
  B_faultmonitor1_gbyk_v4b_T sf_faultmonitor1_h;/* '<S167>/fault monitor1' */
  B_faultmonitor_gbyk_v4b_T sf_faultmonitor_i;/* '<S167>/fault monitor' */
  B_ReadEMCY_gbyk_v4b_T sf_ReadEMCY_p; /* '<S167>/Read EMCY' */
  B_parsestatusregister_gbyk_v4b_T sf_parsestatusregister1_fq;/* '<S164>/parse status register1' */
  B_faultmonitor1_gbyk_v4b_T sf_faultmonitor1_c;/* '<S154>/fault monitor1' */
  B_faultmonitor_gbyk_v4b_T sf_faultmonitor_f;/* '<S154>/fault monitor' */
  B_ReadEMCY_gbyk_v4b_T sf_ReadEMCY_i; /* '<S154>/Read EMCY' */
  B_ControlGDCWhistleState_gbyk_v4b_T sf_ControlGDCWhistleState_p;/* '<S137>/Control GDC Whistle State' */
  B_parsestatusregister_gbyk_v4b_T sf_parsestatusregister1_f;/* '<S151>/parse status register1' */
  B_splitoutconstants1_gbyk_v4b_T sf_splitoutconstants1;/* '<S75>/split out constants1' */
  B_size_gbyk_v4b_T sf_size1;          /* '<S75>/size1' */
  B_size_gbyk_v4b_T sf_size;           /* '<S75>/size' */
  B_converter_gbyk_v4b_T sf_converter_p;/* '<S135>/converter' */
  B_forceEnableDisable_gbyk_v4b_T sf_forceEnableDisable;/* '<S75>/forceEnableDisable' */
  B_convert_gbyk_v4b_T sf_convert;     /* '<S92>/convert' */
  B_SDOwritemachine_gbyk_v4b_T sf_SDOwritemachine;/* '<S92>/SDO write machine' */
  B_values_gbyk_v4b_T sf_values;       /* '<S91>/values' */
  B_SDOreadmachine_gbyk_v4b_n_T sf_SDOreadmachine_p;/* '<S91>/SDO read machine' */
  B_converter_gbyk_v4b_T sf_converter; /* '<S129>/converter' */
  B_SDOreadmachine_gbyk_v4b_T sf_SDOreadmachine;/* '<S75>/SDO read machine' */
  B_setupvalues_gbyk_v4b_T sf_setupvalues_p;/* '<S89>/set-up values' */
  B_AbsEncodermachine_gbyk_v4b_T sf_AbsEncodermachine_b;/* '<S89>/AbsEncoder machine' */
  B_setupvalues_gbyk_v4b_T sf_setupvalues;/* '<S88>/set-up values' */
  B_AbsEncodermachine_gbyk_v4b_T sf_AbsEncodermachine;/* '<S88>/AbsEncoder machine' */
  B_FindRobottype_gbyk_v4b_T sf_FindRobottype;/* '<S75>/Find Robot type' */
  B_faultmonitor1_gbyk_v4b_T sf_faultmonitor1_l;/* '<S115>/fault monitor1' */
  B_faultmonitor_gbyk_v4b_T sf_faultmonitor_k;/* '<S115>/fault monitor' */
  B_ControlGDCWhistleState_gbyk_v4b_T sf_ControlGDCWhistleState_f;/* '<S86>/Control GDC Whistle State' */
  B_parsestatusregister_gbyk_v4b_T sf_parsestatusregister1;/* '<S112>/parse status register1' */
  B_faultmonitor1_gbyk_v4b_T sf_faultmonitor1;/* '<S102>/fault monitor1' */
  B_faultmonitor_gbyk_v4b_T sf_faultmonitor;/* '<S102>/fault monitor' */
  B_parsestatusregister_gbyk_v4b_T sf_parsestatusregister;/* '<S99>/parse status register' */
} B_gbyk_v4b_T;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  sbr0BdzAW6GQX2fQakj4o6C_gbyk_v4b_T robot1Struct;/* '<S210>/Robot_data_builder' */
  sbr0BdzAW6GQX2fQakj4o6C_gbyk_v4b_T robot2Struct;/* '<S210>/Robot_data_builder' */
  sbr0BdzAW6GQX2fQakj4o6C_gbyk_v4b_T robot1StructPrimary;/* '<S210>/Robot_data_builder' */
  sbr0BdzAW6GQX2fQakj4o6C_gbyk_v4b_T robot2StructPrimary;/* '<S210>/Robot_data_builder' */
  shSrZ99dE4twa6ELJRaXlMD_gbyk_v4b_T robot1Struct_a;/* '<S210>/filter_velocities' */
  shSrZ99dE4twa6ELJRaXlMD_gbyk_v4b_T robot2Struct_o;/* '<S210>/filter_velocities' */
  real_T UnitDelay_DSTATE;             /* '<S212>/Unit Delay' */
  real_T UnitDelay1_DSTATE;            /* '<S212>/Unit Delay1' */
  real_T DelayInput1_DSTATE;           /* '<S205>/Delay Input1' */
  real_T DelayInput1_DSTATE_n;         /* '<S209>/Delay Input1' */
  real_T UnitDelay_DSTATE_a;           /* '<S53>/Unit Delay' */
  real_T Memory_PreviousInput[4];      /* '<S4>/Memory' */
  real_T Memory_PreviousInput_c;       /* '<S15>/Memory' */
  real_T TmpRTBAtNumberofEventCodesOutport1_Buffer0;/* synthesized block */
  real_T RateTransition2_Buffer0;      /* '<S27>/Rate Transition2' */
  real_T Memory1_PreviousInput;        /* '<S4>/Memory1' */
  real_T Memory2_1_PreviousInput;      /* '<S4>/Memory2' */
  real_T Memory2_2_PreviousInput;      /* '<S4>/Memory2' */
  real_T Memory2_3_PreviousInput;      /* '<S4>/Memory2' */
  real_T Memory2_4_PreviousInput;      /* '<S4>/Memory2' */
  real_T Memory2_5_PreviousInput;      /* '<S4>/Memory2' */
  real_T Memory2_9_PreviousInput;      /* '<S4>/Memory2' */
  real_T Memory2_18_PreviousInput;     /* '<S4>/Memory2' */
  real_T Memory2_19_PreviousInput;     /* '<S4>/Memory2' */
  real_T Memory2_20_PreviousInput;     /* '<S4>/Memory2' */
  real_T Memory2_21_PreviousInput;     /* '<S4>/Memory2' */
  real_T Memory2_22_PreviousInput;     /* '<S4>/Memory2' */
  real_T Memory2_26_PreviousInput;     /* '<S4>/Memory2' */
  real_T Memory2_10_PreviousInput;     /* '<S4>/Memory2' */
  real_T Memory2_11_PreviousInput;     /* '<S4>/Memory2' */
  real_T Memory2_12_PreviousInput;     /* '<S4>/Memory2' */
  real_T Memory2_13_PreviousInput;     /* '<S4>/Memory2' */
  real_T Memory2_14_PreviousInput;     /* '<S4>/Memory2' */
  real_T Memory2_15_PreviousInput;     /* '<S4>/Memory2' */
  real_T Memory2_16_PreviousInput;     /* '<S4>/Memory2' */
  real_T Memory2_17_PreviousInput;     /* '<S4>/Memory2' */
  real_T Memory2_23_PreviousInput;     /* '<S4>/Memory2' */
  real_T Memory2_24_PreviousInput;     /* '<S4>/Memory2' */
  real_T Memory2_25_PreviousInput;     /* '<S4>/Memory2' */
  real_T Memory2_27_PreviousInput;     /* '<S4>/Memory2' */
  real_T Memory2_28_PreviousInput;     /* '<S4>/Memory2' */
  real_T Memory2_29_PreviousInput;     /* '<S4>/Memory2' */
  real_T Memory2_30_PreviousInput;     /* '<S4>/Memory2' */
  real_T Memory2_31_PreviousInput;     /* '<S4>/Memory2' */
  real_T Memory2_32_PreviousInput;     /* '<S4>/Memory2' */
  real_T Memory2_33_PreviousInput;     /* '<S4>/Memory2' */
  real_T Memory2_34_PreviousInput;     /* '<S4>/Memory2' */
  real_T Memory2_6_PreviousInput;      /* '<S4>/Memory2' */
  real_T Memory2_7_PreviousInput;      /* '<S4>/Memory2' */
  real_T Memory2_8_PreviousInput;      /* '<S4>/Memory2' */
  real_T ECATStatus[8];                /* '<S4>/ECAT Status' */
  real_T ECATHardware[14];             /* '<S4>/ECAT hardware' */
  real_T tickCount;                    /* '<Root>/Trial_Control' */
  real_T tgtdist;                      /* '<Root>/Trial_Control' */
  real_T rwdTgts[2];                   /* '<Root>/Trial_Control' */
  real_T pTgts[2];                     /* '<Root>/Trial_Control' */
  real_T tgt2trig;                     /* '<Root>/Trial_Control' */
  real_T corrTgt;                      /* '<Root>/Trial_Control' */
  real_T incorrTgt;                    /* '<Root>/Trial_Control' */
  real_T boxtrig;                      /* '<Root>/Trial_Control' */
  real_T RateTransition1_Buffer0;      /* '<S298>/Rate Transition1' */
  real_T last_valid_frame_ack;         /* '<S15>/MATLAB Function' */
  real_T last_perm_frame_ack;          /* '<S15>/MATLAB Function' */
  real_T Delay1_PreviousInput;         /* '<S269>/Delay1' */
  real_T Subtract_DWORK1;              /* '<S269>/Subtract' */
  real_T trial_queue[499];             /* '<S269>/Task Execution Control Machine' */
  real_T repeat_list[499];             /* '<S269>/Task Execution Control Machine' */
  real_T EXAM;                         /* '<S269>/Task Execution Control Machine' */
  real_T BLOCK;                        /* '<S269>/Task Execution Control Machine' */
  real_T held_value[8];                /* '<S268>/Hold_to_1Khz' */
  real_T u;                            /* '<S268>/Embedded MATLAB Function' */
  real_T v;                            /* '<S268>/Embedded MATLAB Function' */
  real_T RateTransition_Buffer0[3];    /* '<S35>/Rate Transition' */
  real_T start_time;                   /* '<S35>/Create timestamp' */
  real_T last_time;                    /* '<S35>/Create timestamp' */
  real_T BKINEtherCATinit1_DWORK2;     /* '<S64>/BKIN EtherCATinit1' */
  real_T BKINEtherCATinit1_DWORK4;     /* '<S64>/BKIN EtherCATinit1' */
  real_T BKINEtherCATinit_DWORK2;      /* '<S64>/BKIN EtherCATinit' */
  real_T BKINEtherCATinit_DWORK4;      /* '<S64>/BKIN EtherCATinit' */
  real_T ECATErrMsgs[20];              /* '<S34>/ECAT Err Msgs' */
  real_T ECATExtraData[8];             /* '<S34>/ECATTorque feedback' */
  real_T HardwareSettings[24];         /* '<S34>/HW Settings' */
  real_T Kinematics[20];               /* '<S34>/Kinematics' */
  real_T PrimaryEncoderData[12];       /* '<S34>/PrimaryEnc' */
  real_T RobotCalibrations[16];        /* '<S34>/Robot Calib' */
  real_T RobotRevision[2];             /* '<S34>/RobotRevision' */
  real_T DelayEstimates[4];            /* '<S34>/delays' */
  real_T ArmForceSensors[2];           /* '<S34>/has FT sensors' */
  real_T lastECATMessages[20];         /* '<S70>/record errors' */
  real_T outCount;                     /* '<S70>/record errors' */
  real_T memoryBuffer[300];            /* '<S70>/record errors' */
  real_T waitingMsgCount;              /* '<S70>/record errors' */
  real_T sentCount;                    /* '<S70>/record errors' */
  real_T secondaryPosData_data[400];   /* '<S84>/create kinematics' */
  real_T secondaryVelData_data[400];   /* '<S84>/create kinematics' */
  real_T primaryVelData_data[400];     /* '<S84>/create kinematics' */
  real_T primaryVelDataFiltered_data[400];/* '<S84>/create kinematics' */
  real_T rawVelocities[12];            /* '<S194>/filter_velocities' */
  real_T filtVelocities[12];           /* '<S194>/filter_velocities' */
  real_T r1Sho[4];                     /* '<S223>/MATLAB Function' */
  real_T r1Elb[4];                     /* '<S223>/MATLAB Function' */
  real_T r2Sho[4];                     /* '<S223>/MATLAB Function' */
  real_T r2Elb[4];                     /* '<S223>/MATLAB Function' */
  real_T last_tick[4];                 /* '<S223>/MATLAB Function' */
  real_T servoValuesR1[5];             /* '<S210>/Robot_data_builder' */
  real_T servoValuesR2[5];             /* '<S210>/Robot_data_builder' */
  real_T no_update_count;              /* '<S210>/Monitor_status' */
  real_T latchedErrors[12];            /* '<S64>/latch_errors' */
  real_T latchedDCErrors[12];          /* '<S64>/latch_errors' */
  real_T Memory_PreviousInput_l;       /* '<S137>/Memory' */
  real_T Memory_PreviousInput_h;       /* '<S138>/Memory' */
  real_T Memory1_PreviousInput_c;      /* '<S146>/Memory1' */
  real_T Memory2_PreviousInput;        /* '<S146>/Memory2' */
  real_T Memory2_PreviousInput_n[2];   /* '<S76>/Memory2' */
  real_T Memory3_PreviousInput;        /* '<S76>/Memory3' */
  real_T Memory_PreviousInput_f;       /* '<S143>/Memory' */
  real_T Memory_PreviousInput_m;       /* '<S173>/Memory' */
  real_T permFaulted;                  /* '<S138>/Control GDC Whistle State' */
  real_T countFaultSteps;              /* '<S138>/Control GDC Whistle State' */
  real_T frameCounter;                 /* '<S138>/Control GDC Whistle State' */
  real_T Memory_PreviousInput_p;       /* '<S160>/Memory' */
  real_T Memory_PreviousInput_g;       /* '<S85>/Memory' */
  real_T Memory_PreviousInput_pv;      /* '<S86>/Memory' */
  real_T Memory1_PreviousInput_i;      /* '<S94>/Memory1' */
  real_T Memory2_PreviousInput_p;      /* '<S94>/Memory2' */
  real_T Memory2_PreviousInput_i[2];   /* '<S75>/Memory2' */
  real_T Memory3_PreviousInput_l;      /* '<S75>/Memory3' */
  real_T Memory_PreviousInput_d;       /* '<S91>/Memory' */
  real_T Memory_PreviousInput_h3;      /* '<S121>/Memory' */
  real_T currReadIdx;                  /* '<S115>/Read EMCY' */
  real_T valuesToRead;                 /* '<S115>/Read EMCY' */
  real_T Memory_PreviousInput_lw;      /* '<S108>/Memory' */
  real_T currReadIdx_j;                /* '<S102>/Read EMCY' */
  real_T valuesToRead_b;               /* '<S102>/Read EMCY' */
  real_T permFaulted_l;                /* '<S85>/Control GDC Whistle State' */
  real_T countFaultSteps_d;            /* '<S85>/Control GDC Whistle State' */
  real_T frameCounter_e;               /* '<S85>/Control GDC Whistle State' */
  real_T Memory2_PreviousInput_a;      /* '<S50>/Memory2' */
  real_T RateTransition2_Buffer0_p[3]; /* '<S50>/Rate Transition2' */
  real_T TmpRTBAtforcestrobeOutport1_Buffer0;/* synthesized block */
  real_T counter;                      /* '<S32>/force strobe' */
  real_T packet_queue_sz;              /* '<S32>/Send Control Machine' */
  real_T outstanding_packet_index;     /* '<S32>/Send Control Machine' */
  void *RunCommandReceive_PWORK;       /* '<S268>/Run Command Receive' */
  void *Receive_PWORK;                 /* '<S15>/Receive' */
  void *Send_PWORK;                    /* '<S15>/Send' */
  void *SFunction1_PWORK;              /* '<S252>/S-Function1' */
  void *Receive_PWORK_o;               /* '<S35>/Receive' */
  void *Receive_PWORK_n;               /* '<S223>/Receive' */
  void *SFunction_PWORK;               /* '<S210>/S-Function' */
  void *Write_PWORK;                   /* '<S212>/Write' */
  void *Write_PWORK_i;                 /* '<S219>/Write' */
  void *Read_PWORK;                    /* '<S217>/Read' */
  void *ReceivefromRobot1ForceSensor_PWORK;/* '<S202>/Receive from Robot 1 Force Sensor' */
  void *ReceivefromRobot2ForceSensor_PWORK;/* '<S203>/Receive from Robot 2 Force Sensor' */
  void *Send_PWORK_h;                  /* '<S208>/Send' */
  void *Send_PWORK_f;                  /* '<S206>/Send' */
  void *BKINPDOReceiveElmoDrive_PWORK; /* '<S164>/BKIN PDO Receive ElmoDrive' */
  void *BKINPDOReceiveElmoDrive_PWORK_d;/* '<S151>/BKIN PDO Receive ElmoDrive' */
  void *BKINPDOReceiveElmoDrive_PWORK_b;/* '<S112>/BKIN PDO Receive ElmoDrive' */
  void *BKINPDOReceiveElmoDrive_PWORK_i;/* '<S99>/BKIN PDO Receive ElmoDrive' */
  void *Send1_PWORK;                   /* '<S61>/Send1' */
  void *Send_PWORK_l;                  /* '<S60>/Send' */
  void *Receive1_PWORK;                /* '<S59>/Receive1' */
  void *Receive_PWORK_l;               /* '<S58>/Receive' */
  void *UDPReceive_PWORK;              /* '<S50>/UDP Receive' */
  void *UDPReceivePortReset_PWORK;     /* '<S50>/UDP Receive Port Reset' */
  void *Send_PWORK_hr;                 /* '<S51>/Send' */
  void *Send_PWORK_p;                  /* '<S31>/Send' */
  uint32_T Output_DSTATE;              /* '<S44>/Output' */
  uint32_T Output_DSTATE_c;            /* '<S78>/Output' */
  uint32_T Output_DSTATE_p;            /* '<S235>/Output' */
  uint32_T Output_DSTATE_h;            /* '<S226>/Output' */
  uint32_T Output_DSTATE_h5;           /* '<S54>/Output' */
  real32_T TmpRTBAtSendControlMachineInport1_Buffer0[400];/* synthesized block */
  real32_T packet_queue[20500000];     /* '<S32>/Send Control Machine' */
  real32_T t2_PreviousInput[127];      /* '<S48>/t-2' */
  real32_T t1_PreviousInput[127];      /* '<S48>/t-1' */
  int32_T sfEvent;                     /* '<Root>/Trial_Control' */
  int32_T clockTickCounter;            /* '<S269>/Task Clock' */
  int32_T sfEvent_m;                   /* '<S269>/Task Execution Control Machine' */
  int32_T BKINEtherCATinit1_DWORK1;    /* '<S64>/BKIN EtherCATinit1' */
  int32_T BKINEtherCATinit_DWORK1;     /* '<S64>/BKIN EtherCATinit' */
  int32_T sfEvent_n;                   /* '<S34>/control read write' */
  int32_T secondaryPosData_sizes[2];   /* '<S84>/create kinematics' */
  int32_T secondaryVelData_sizes[2];   /* '<S84>/create kinematics' */
  int32_T primaryVelData_sizes[2];     /* '<S84>/create kinematics' */
  int32_T primaryVelDataFiltered_sizes[2];/* '<S84>/create kinematics' */
  int32_T Memory_PreviousInput_b;      /* '<S146>/Memory' */
  int32_T Memory_PreviousInput_do;     /* '<S144>/Memory' */
  int32_T Memory_PreviousInput_o;      /* '<S141>/Memory' */
  int32_T Memory1_PreviousInput_l[2];  /* '<S141>/Memory1' */
  int32_T Memory_PreviousInput_cs;     /* '<S140>/Memory' */
  int32_T Memory1_PreviousInput_io[2]; /* '<S140>/Memory1' */
  int32_T Memory_PreviousInput_de[2];  /* '<S172>/Memory' */
  int32_T Memory_PreviousInput_dg[2];  /* '<S159>/Memory' */
  int32_T Memory_PreviousInput_pn;     /* '<S94>/Memory' */
  int32_T Memory_PreviousInput_a;      /* '<S92>/Memory' */
  int32_T Memory_PreviousInput_i;      /* '<S89>/Memory' */
  int32_T Memory1_PreviousInput_a[2];  /* '<S89>/Memory1' */
  int32_T Memory_PreviousInput_hw;     /* '<S88>/Memory' */
  int32_T Memory1_PreviousInput_g[2];  /* '<S88>/Memory1' */
  int32_T Memory_PreviousInput_id[2];  /* '<S120>/Memory' */
  int32_T sfEvent_e;                   /* '<S115>/Read EMCY' */
  int32_T Memory_PreviousInput_he[2];  /* '<S107>/Memory' */
  int32_T sfEvent_p;                   /* '<S102>/Read EMCY' */
  int32_T clockTickCounter_e;          /* '<S32>/Task Clock' */
  int32_T sfEvent_mm;                  /* '<S32>/Send Control Machine' */
  int32_T i;                           /* '<S32>/Send Control Machine' */
  int32_T j;                           /* '<S32>/Send Control Machine' */
  uint32_T ECATDigDiagnostic[4];       /* '<S4>/ECAT Dig Diagnostic' */
  uint32_T e_Trial_EndEventCounter;    /* '<Root>/Trial_Control' */
  uint32_T temporalCounter_i1;         /* '<Root>/Trial_Control' */
  uint32_T frame_count;                /* '<S298>/Pack VCodeFrame2' */
  uint32_T e_exit_trialEventCounter;   /* '<S269>/Task Execution Control Machine' */
  uint32_T repeat_list_length;         /* '<S269>/Task Execution Control Machine' */
  uint32_T i_l;                        /* '<S269>/Task Execution Control Machine' */
  uint32_T swap_index;                 /* '<S269>/Task Execution Control Machine' */
  uint32_T temp;                       /* '<S269>/Task Execution Control Machine' */
  uint32_T trial_queue_length;         /* '<S269>/Task Execution Control Machine' */
  uint32_T trial_in_mini_block;        /* '<S269>/Task Execution Control Machine' */
  uint32_T last_timestamp;             /* '<S35>/convert to seconds2' */
  uint32_T ECATDigitalInput[8];        /* '<S34>/ECAT Digital in' */
  uint32_T ServoUpdate;                /* '<S34>/ServoUpdate' */
  uint32_T SystemStatus[7];            /* '<S34>/System status' */
  uint32_T CalibrationButton;          /* '<S34>/calib button' */
  uint32_T servoCounter;               /* '<S84>/create servo counter' */
  uint32_T last_servo_counter;         /* '<S210>/Monitor_status' */
  uint32_T enteredOpStep;              /* '<S64>/latch_errors' */
  uint32_T Memory_PreviousInput_ml[2]; /* '<S171>/Memory' */
  uint32_T lastEStopState;             /* '<S138>/Control GDC Whistle State' */
  uint32_T Memory_PreviousInput_cn[2]; /* '<S158>/Memory' */
  uint32_T Memory_PreviousInput_n[2];  /* '<S119>/Memory' */
  uint32_T Memory_PreviousInput_nh[2]; /* '<S106>/Memory' */
  uint32_T lastEStopState_n;           /* '<S85>/Control GDC Whistle State' */
  uint32_T queue_tail;                 /* '<S32>/Send Control Machine' */
  uint32_T packet_index;               /* '<S32>/Send Control Machine' */
  uint32_T queue_head;                 /* '<S32>/Send Control Machine' */
  int_T ICH7_IWORK[5];                 /* '<S7>/ICH7' */
  int_T RunCommandReceive_IWORK[2];    /* '<S268>/Run Command Receive' */
  int_T Receive_IWORK[2];              /* '<S15>/Receive' */
  int_T Send_IWORK[2];                 /* '<S15>/Send' */
  struct {
    int_T AcquireOK;
  } SFunction_IWORK;                   /* '<S16>/S-Function' */

  struct {
    int_T AcquireOK;
  } SFunction_IWORK_n;                 /* '<S17>/S-Function' */

  struct {
    int_T AcquireOK;
  } SFunction_IWORK_i;                 /* '<S18>/S-Function' */

  struct {
    int_T AcquireOK;
  } SFunction_IWORK_j;                 /* '<S19>/S-Function' */

  struct {
    int_T AcquireOK;
  } SFunction_IWORK_c;                 /* '<S20>/S-Function' */

  int_T BKINEtherCATPDOTransmit1_IWORK[23];/* '<S255>/BKIN EtherCAT PDO Transmit 1' */
  int_T BKINEtherCATPDOTransmit2_IWORK[23];/* '<S255>/BKIN EtherCAT PDO Transmit 2' */
  int_T BKINEtherCATPDOTransmit1_IWORK_c[23];/* '<S256>/BKIN EtherCAT PDO Transmit 1' */
  int_T BKINEtherCATPDOTransmit2_IWORK_g[23];/* '<S256>/BKIN EtherCAT PDO Transmit 2' */
  int_T Receive_IWORK_n[2];            /* '<S35>/Receive' */
  int_T BKINEtherCATPDOTransmit_IWORK[23];/* '<S79>/BKIN EtherCAT PDO Transmit ' */
  int_T BKINEtherCATPDOTransmit1_IWORK_m[23];/* '<S79>/BKIN EtherCAT PDO Transmit 1' */
  int_T BKINEtherCATPDOTransmit2_IWORK_d[23];/* '<S79>/BKIN EtherCAT PDO Transmit 2' */
  int_T BKINEtherCATPDOTransmit3_IWORK[23];/* '<S79>/BKIN EtherCAT PDO Transmit 3' */
  int_T ReceivefromRobot1ForceSensor_IWORK[2];/* '<S202>/Receive from Robot 1 Force Sensor' */
  int_T ReceivefromRobot2ForceSensor_IWORK[2];/* '<S203>/Receive from Robot 2 Force Sensor' */
  int_T Send_IWORK_l[2];               /* '<S208>/Send' */
  int_T Send_IWORK_d[2];               /* '<S206>/Send' */
  int_T BKINEtherCATPDOTransmit_IWORK_p[23];/* '<S76>/BKIN EtherCAT PDO Transmit ' */
  int_T BKINEtherCATPDOTransmit1_IWORK_p[23];/* '<S76>/BKIN EtherCAT PDO Transmit 1' */
  int_T BKINEtherCATPDOTransmit_IWORK_m[23];/* '<S137>/BKIN EtherCAT PDO Transmit ' */
  int_T BKINEtherCATPDOTransmit_IWORK_h[23];/* '<S138>/BKIN EtherCAT PDO Transmit ' */
  int_T BKINEtherCATAsyncSDOUpload1_IWORK[10];/* '<S187>/BKIN EtherCAT Async SDO Upload1' */
  int_T BKINEtherCATAsyncSDODownload_IWORK[9];/* '<S144>/BKIN EtherCAT Async SDO Download' */
  int_T BKINEtherCATAsyncSDOUpload1_IWORK_h[10];/* '<S181>/BKIN EtherCAT Async SDO Upload1' */
  int_T BKINEtherCATAsyncSDODownload_IWORK_k[9];/* '<S141>/BKIN EtherCAT Async SDO Download' */
  int_T BKINEtherCATAsyncSDOUpload_IWORK[10];/* '<S141>/BKIN EtherCAT Async SDO Upload' */
  int_T BKINEtherCATAsyncSDODownload_IWORK_m[9];/* '<S140>/BKIN EtherCAT Async SDO Download' */
  int_T BKINEtherCATAsyncSDOUpload_IWORK_o[10];/* '<S140>/BKIN EtherCAT Async SDO Upload' */
  int_T BKINEtherCATAsyncSDOUpload_IWORK_d[10];/* '<S171>/BKIN EtherCAT Async SDO Upload' */
  int_T BKINEtherCATAsyncSDOUpload_IWORK_p[10];/* '<S172>/BKIN EtherCAT Async SDO Upload' */
  int_T BKINEtherCATAsyncSDODownload_IWORK_a[9];/* '<S173>/BKIN EtherCAT Async SDO Download' */
  int_T BKINPDOReceiveElmoDrive_IWORK[7];/* '<S164>/BKIN PDO Receive ElmoDrive' */
  int_T BKINEtherCATAsyncSDOUpload_IWORK_n[10];/* '<S158>/BKIN EtherCAT Async SDO Upload' */
  int_T BKINEtherCATAsyncSDOUpload_IWORK_i[10];/* '<S159>/BKIN EtherCAT Async SDO Upload' */
  int_T BKINEtherCATAsyncSDODownload_IWORK_o[9];/* '<S160>/BKIN EtherCAT Async SDO Download' */
  int_T BKINPDOReceiveElmoDrive_IWORK_c[7];/* '<S151>/BKIN PDO Receive ElmoDrive' */
  int_T BKINEtherCATPDOTransmit_IWORK_f[23];/* '<S75>/BKIN EtherCAT PDO Transmit ' */
  int_T BKINEtherCATPDOTransmit1_IWORK_j[23];/* '<S75>/BKIN EtherCAT PDO Transmit 1' */
  int_T BKINEtherCATPDOTransmit_IWORK_a[23];/* '<S85>/BKIN EtherCAT PDO Transmit ' */
  int_T BKINEtherCATPDOTransmit_IWORK_p5[23];/* '<S86>/BKIN EtherCAT PDO Transmit ' */
  int_T BKINEtherCATAsyncSDOUpload1_IWORK_p[10];/* '<S135>/BKIN EtherCAT Async SDO Upload1' */
  int_T BKINEtherCATAsyncSDODownload_IWORK_e[9];/* '<S92>/BKIN EtherCAT Async SDO Download' */
  int_T BKINEtherCATAsyncSDOUpload1_IWORK_a[10];/* '<S129>/BKIN EtherCAT Async SDO Upload1' */
  int_T BKINEtherCATAsyncSDODownload_IWORK_a0[9];/* '<S89>/BKIN EtherCAT Async SDO Download' */
  int_T BKINEtherCATAsyncSDOUpload_IWORK_f[10];/* '<S89>/BKIN EtherCAT Async SDO Upload' */
  int_T BKINEtherCATAsyncSDODownload_IWORK_j[9];/* '<S88>/BKIN EtherCAT Async SDO Download' */
  int_T BKINEtherCATAsyncSDOUpload_IWORK_h[10];/* '<S88>/BKIN EtherCAT Async SDO Upload' */
  int_T BKINEtherCATAsyncSDOUpload_IWORK_j[10];/* '<S119>/BKIN EtherCAT Async SDO Upload' */
  int_T BKINEtherCATAsyncSDOUpload_IWORK_a[10];/* '<S120>/BKIN EtherCAT Async SDO Upload' */
  int_T BKINEtherCATAsyncSDODownload_IWORK_g[9];/* '<S121>/BKIN EtherCAT Async SDO Download' */
  int_T BKINPDOReceiveElmoDrive_IWORK_ct[7];/* '<S112>/BKIN PDO Receive ElmoDrive' */
  int_T BKINEtherCATAsyncSDOUpload_IWORK_hj[10];/* '<S106>/BKIN EtherCAT Async SDO Upload' */
  int_T BKINEtherCATAsyncSDOUpload_IWORK_b[10];/* '<S107>/BKIN EtherCAT Async SDO Upload' */
  int_T BKINEtherCATAsyncSDODownload_IWORK_g1[9];/* '<S108>/BKIN EtherCAT Async SDO Download' */
  int_T BKINPDOReceiveElmoDrive_IWORK_f[7];/* '<S99>/BKIN PDO Receive ElmoDrive' */
  int_T UDPReceive_IWORK[3];           /* '<S50>/UDP Receive' */
  int_T UDPReceivePortReset_IWORK[4];  /* '<S50>/UDP Receive Port Reset' */
  real_T data;
  int_T Receive_IWORK_f[2];            /* '<S223>/Receive' */
  int_T Send1_IWORK[2];                /* '<S61>/Send1' */
  int_T Send_IWORK_dv[2];              /* '<S60>/Send' */
  int_T Receive1_IWORK[2];             /* '<S59>/Receive1' */
  int_T Receive_IWORK_d[2];            /* '<S58>/Receive' */
  int_T Send_IWORK_e[2];               /* '<S51>/Send' */
  int_T Send_IWORK_p[2];               /* '<S31>/Send' */
  uint16_T Output_DSTATE_k;            /* '<S216>/Output' */
  uint16_T temporalCounter_i2;         /* '<S32>/Send Control Machine' */
  int8_T Trial_Control_SubsysRanBC;    /* '<Root>/Trial_Control' */
  int8_T TaskExecutionControlMachine_SubsysRanBC;/* '<S269>/Task Execution Control Machine' */
  int8_T EtherCATApplyLoads_SubsysRanBC;/* '<S37>/EtherCAT Apply Loads' */
  int8_T applypmacloads_SubsysRanBC;   /* '<S37>/apply pmac loads' */
  int8_T Arm1_SubsysRanBC;             /* '<S64>/Arm 1' */
  int8_T Arm2_SubsysRanBC;             /* '<S64>/Arm 2' */
  int8_T Datareceive_SubsysRanBC;      /* '<S67>/Data receive' */
  int8_T read_pmac_SubsysRanBC;        /* '<S66>/read_pmac' */
  int8_T Datawrite_SubsysRanBC;        /* '<S67>/Data write' */
  int8_T update_SubsysRanBC;           /* '<S64>/update' */
  int8_T updatesettings_SubsysRanBC;   /* '<S66>/update settings' */
  int8_T createKINData_SubsysRanBC;    /* '<S34>/createKINData' */
  int8_T updateconstantssubsystem_SubsysRanBC;/* '<S68>/update constants subsystem' */
  int8_T ReadDPRAM_SubsysRanBC;        /* '<S212>/Read DPRAM' */
  int8_T WriteDPRAM_SubsysRanBC;       /* '<S212>/Write DPRAM' */
  int8_T IfActionSubsystem_SubsysRanBC;/* '<S202>/If Action Subsystem' */
  int8_T DataTransferStartSubsystem_SubsysRanBC;/* '<S203>/Data Transfer Start Subsystem' */
  int8_T M1AbsEncCalibration_SubsysRanBC;/* '<S76>/M1 AbsEnc Calibration' */
  int8_T M2AbsEncCalibration_SubsysRanBC;/* '<S76>/M2 AbsEnc Calibration' */
  int8_T M1AbsEncCalibration_SubsysRanBC_h;/* '<S75>/M1 AbsEnc Calibration' */
  int8_T M2AbsEncCalibration_SubsysRanBC_h;/* '<S75>/M2 AbsEnc Calibration' */
  int8_T sendpoll1_SubsysRanBC;        /* '<S33>/send poll 1' */
  int8_T sendpoll2_SubsysRanBC;        /* '<S33>/send poll 2' */
  int8_T plate1_SubsysRanBC;           /* '<S33>/plate1' */
  int8_T plate2_SubsysRanBC;           /* '<S33>/plate2' */
  int8_T SendControlMachine_SubsysRanBC;/* '<S32>/Send Control Machine' */
  int8_T UDPSendSubsystem_SubsysRanBC; /* '<S32>/UDP Send Subsystem' */
  uint8_T is_active_c1_gbyk_v4b;       /* '<Root>/Trial_Control' */
  uint8_T is_c1_gbyk_v4b;              /* '<Root>/Trial_Control' */
  uint8_T is_MainTrial;                /* '<Root>/Trial_Control' */
  uint8_T is_active_c42_General;       /* '<S269>/Task Execution Control Machine' */
  uint8_T is_c42_General;              /* '<S269>/Task Execution Control Machine' */
  uint8_T is_InTrial;                  /* '<S269>/Task Execution Control Machine' */
  uint8_T is_active_c38_General;       /* '<S34>/control read write' */
  uint8_T is_c38_General;              /* '<S34>/control read write' */
  uint8_T prevRunStatus;               /* '<S79>/update digital outputs' */
  uint8_T is_active_c101_ethercat;     /* '<S115>/Read EMCY' */
  uint8_T is_c101_ethercat;            /* '<S115>/Read EMCY' */
  uint8_T is_active_c99_ethercat;      /* '<S102>/Read EMCY' */
  uint8_T is_c99_ethercat;             /* '<S102>/Read EMCY' */
  uint8_T is_active_c8_General;        /* '<S32>/Send Control Machine' */
  uint8_T is_UpdatePacketQueue;        /* '<S32>/Send Control Machine' */
  uint8_T is_active_UpdatePacketQueue; /* '<S32>/Send Control Machine' */
  uint8_T is_SendControlMachine;       /* '<S32>/Send Control Machine' */
  uint8_T is_active_SendControlMachine;/* '<S32>/Send Control Machine' */
  uint8_T is_Fixed;                    /* '<S32>/Send Control Machine' */
  uint8_T is_FixMonitor;               /* '<S32>/Send Control Machine' */
  uint8_T is_active_FixMonitor;        /* '<S32>/Send Control Machine' */
  uint8_T temporalCounter_i1_o;        /* '<S32>/Send Control Machine' */
  uint8_T temporalCounter_i3;          /* '<S32>/Send Control Machine' */
  boolean_T isStable;                  /* '<Root>/Trial_Control' */
  boolean_T setup_trial_flag;          /* '<Root>/Trial_Control' */
  boolean_T disttrigy;                 /* '<Root>/Trial_Control' */
  boolean_T Delay_PreviousInput;       /* '<S269>/Delay' */
  boolean_T isStable_h;                /* '<S269>/Task Execution Control Machine' */
  boolean_T BKINEtherCATinit1_DWORK3;  /* '<S64>/BKIN EtherCATinit1' */
  boolean_T BKINEtherCATinit_DWORK3;   /* '<S64>/BKIN EtherCATinit' */
  boolean_T isStable_d;                /* '<S34>/control read write' */
  boolean_T lastECATMessages_not_empty;/* '<S70>/record errors' */
  boolean_T servoCounter_not_empty;    /* '<S84>/create servo counter' */
  boolean_T secondaryPosData_not_empty;/* '<S84>/create kinematics' */
  boolean_T permFaulted_not_empty;     /* '<S138>/Control GDC Whistle State' */
  boolean_T isStable_dj;               /* '<S115>/Read EMCY' */
  boolean_T isStable_n;                /* '<S102>/Read EMCY' */
  boolean_T permFaulted_not_empty_n;   /* '<S85>/Control GDC Whistle State' */
  boolean_T TmpRTBAtforcestrobeInport1_Buffer0;/* synthesized block */
  boolean_T isStable_nq;               /* '<S32>/Send Control Machine' */
  boolean_T Arm1_MODE;                 /* '<S64>/Arm 1' */
  boolean_T Arm2_MODE;                 /* '<S64>/Arm 2' */
  boolean_T M1AbsEncCalibration_MODE;  /* '<S76>/M1 AbsEnc Calibration' */
  boolean_T M2AbsEncCalibration_MODE;  /* '<S76>/M2 AbsEnc Calibration' */
  boolean_T M1AbsEncCalibration_MODE_i;/* '<S75>/M1 AbsEnc Calibration' */
  boolean_T M2AbsEncCalibration_MODE_a;/* '<S75>/M2 AbsEnc Calibration' */
  DW_Createtimestamp_gbyk_v4b_T sf_Createtimestamp_b;/* '<S203>/Create timestamp' */
  DW_Createtimestamp_gbyk_v4b_T sf_Createtimestamp;/* '<S202>/Create timestamp' */
  DW_forceEnableDisable_gbyk_v4b_T sf_forceEnableDisable_k;/* '<S76>/forceEnableDisable' */
  DW_SDOwritemachine_gbyk_v4b_T sf_SDOwritemachine_j;/* '<S144>/SDO write machine' */
  DW_SDOreadmachine_gbyk_v4b_m_T sf_SDOreadmachine_g;/* '<S143>/SDO read machine' */
  DW_SDOreadmachine_gbyk_v4b_T sf_SDOreadmachine_h;/* '<S76>/SDO read machine' */
  DW_AbsEncodermachine_gbyk_v4b_T sf_AbsEncodermachine_k;/* '<S141>/AbsEncoder machine' */
  DW_AbsEncodermachine_gbyk_v4b_T sf_AbsEncodermachine_i;/* '<S140>/AbsEncoder machine' */
  DW_faultmonitor1_gbyk_v4b_T sf_faultmonitor1_h;/* '<S167>/fault monitor1' */
  DW_faultmonitor_gbyk_v4b_T sf_faultmonitor_i;/* '<S167>/fault monitor' */
  DW_ReadEMCY_gbyk_v4b_T sf_ReadEMCY_p;/* '<S167>/Read EMCY' */
  DW_faultmonitor1_gbyk_v4b_T sf_faultmonitor1_c;/* '<S154>/fault monitor1' */
  DW_faultmonitor_gbyk_v4b_T sf_faultmonitor_f;/* '<S154>/fault monitor' */
  DW_ReadEMCY_gbyk_v4b_T sf_ReadEMCY_i;/* '<S154>/Read EMCY' */
  DW_ControlGDCWhistleState_gbyk_v4b_T sf_ControlGDCWhistleState_p;/* '<S137>/Control GDC Whistle State' */
  DW_forceEnableDisable_gbyk_v4b_T sf_forceEnableDisable;/* '<S75>/forceEnableDisable' */
  DW_SDOwritemachine_gbyk_v4b_T sf_SDOwritemachine;/* '<S92>/SDO write machine' */
  DW_SDOreadmachine_gbyk_v4b_m_T sf_SDOreadmachine_p;/* '<S91>/SDO read machine' */
  DW_SDOreadmachine_gbyk_v4b_T sf_SDOreadmachine;/* '<S75>/SDO read machine' */
  DW_AbsEncodermachine_gbyk_v4b_T sf_AbsEncodermachine_b;/* '<S89>/AbsEncoder machine' */
  DW_AbsEncodermachine_gbyk_v4b_T sf_AbsEncodermachine;/* '<S88>/AbsEncoder machine' */
  DW_faultmonitor1_gbyk_v4b_T sf_faultmonitor1_l;/* '<S115>/fault monitor1' */
  DW_faultmonitor_gbyk_v4b_T sf_faultmonitor_k;/* '<S115>/fault monitor' */
  DW_ControlGDCWhistleState_gbyk_v4b_T sf_ControlGDCWhistleState_f;/* '<S86>/Control GDC Whistle State' */
  DW_faultmonitor1_gbyk_v4b_T sf_faultmonitor1;/* '<S102>/fault monitor1' */
  DW_faultmonitor_gbyk_v4b_T sf_faultmonitor;/* '<S102>/fault monitor' */
} DW_gbyk_v4b_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Trial_Control_Trig_ZCE[3];/* '<Root>/Trial_Control' */
  ZCSigState TaskExecutionControlMachine_Trig_ZCE[2];/* '<S269>/Task Execution Control Machine' */
  ZCSigState SendControlMachine_Trig_ZCE[3];/* '<S32>/Send Control Machine' */
} PrevZCX_gbyk_v4b_T;

/* Invariant block signals (auto storage) */
typedef struct {
  const real_T Width;                  /* '<S30>/Width' */
  const real_T Width_d;                /* '<S29>/Width' */
  const real_T Width_a;                /* '<S26>/Width' */
  const real_T Width_g;                /* '<S27>/Width' */
  const real_T Width_c;                /* '<S28>/Width' */
  const uint32_T Width1;               /* '<S269>/Width1' */
} ConstB_gbyk_v4b_T;

/* Backward compatible GRT Identifiers */
#define rtB                            gbyk_v4b_B
#define BlockIO                        B_gbyk_v4b_T
#define rtP                            gbyk_v4b_P
#define Parameters                     P_gbyk_v4b_T
#define rtDWork                        gbyk_v4b_DW
#define D_Work                         DW_gbyk_v4b_T
#define tConstBlockIOType              ConstB_gbyk_v4b_T
#define rtC                            gbyk_v4b_ConstB
#define rtPrevZCSigState               gbyk_v4b_PrevZCX
#define PrevZCSigStates                PrevZCX_gbyk_v4b_T

/* Parameters (auto storage) */
struct P_gbyk_v4b_T_ {
  real_T GUIControl_Lcols;             /* Mask Parameter: GUIControl_Lcols
                                        * Referenced by: '<S267>/L_cols'
                                        */
  real_T GUIControl_Vcols;             /* Mask Parameter: GUIControl_Vcols
                                        * Referenced by: '<S267>/V_cols'
                                        */
  real_T GUIControl_XYcols[2];         /* Mask Parameter: GUIControl_XYcols
                                        * Referenced by: '<S267>/XY_cols'
                                        */
  real_T KINARM_HandInTarget_attribcol1;/* Mask Parameter: KINARM_HandInTarget_attribcol1
                                         * Referenced by: '<S11>/attribcol1'
                                         */
  real_T KINARM_HandInBox_attribcol1[3];/* Mask Parameter: KINARM_HandInBox_attribcol1
                                         * Referenced by: '<S10>/attribcol1'
                                         */
  real_T Show_Target_A_attribcol1[4];  /* Mask Parameter: Show_Target_A_attribcol1
                                        * Referenced by: '<S24>/state1_indices'
                                        */
  real_T Show_TargetB_With_Label_attribcol1[7];/* Mask Parameter: Show_TargetB_With_Label_attribcol1
                                                * Referenced by: '<S22>/state1_indices'
                                                */
  real_T Show_Target_With_Label1_attribcol1[9];/* Mask Parameter: Show_Target_With_Label1_attribcol1
                                                * Referenced by: '<S265>/state1_indices'
                                                */
  real_T Show_Target_attribcol1[6];    /* Mask Parameter: Show_Target_attribcol1
                                        * Referenced by: '<S262>/state1_indices'
                                        */
  real_T Show_TargetC_With_Label_attribcol1[7];/* Mask Parameter: Show_TargetC_With_Label_attribcol1
                                                * Referenced by: '<S23>/state1_indices'
                                                */
  real_T Show_Box_attribcol1[6];       /* Mask Parameter: Show_Box_attribcol1
                                        * Referenced by: '<S21>/state1_indices'
                                        */
  real_T Show_Target_A_attribcol2[4];  /* Mask Parameter: Show_Target_A_attribcol2
                                        * Referenced by: '<S24>/state2_indices'
                                        */
  real_T Show_TargetB_With_Label_attribcol2[7];/* Mask Parameter: Show_TargetB_With_Label_attribcol2
                                                * Referenced by: '<S22>/state2_indices'
                                                */
  real_T Show_TargetC_With_Label_attribcol2[7];/* Mask Parameter: Show_TargetC_With_Label_attribcol2
                                                * Referenced by: '<S23>/state2_indices'
                                                */
  real_T Show_Box_attribcol2[6];       /* Mask Parameter: Show_Box_attribcol2
                                        * Referenced by: '<S21>/state2_indices'
                                        */
  real_T Show_TargetB_With_Label_attribcol3[7];/* Mask Parameter: Show_TargetB_With_Label_attribcol3
                                                * Referenced by: '<S22>/state3_indices'
                                                */
  real_T Show_TargetC_With_Label_attribcol3[7];/* Mask Parameter: Show_TargetC_With_Label_attribcol3
                                                * Referenced by: '<S23>/state3_indices'
                                                */
  real_T isecat_const;                 /* Mask Parameter: isecat_const
                                        * Referenced by: '<S71>/Constant'
                                        */
  real_T ispmac1_const;                /* Mask Parameter: ispmac1_const
                                        * Referenced by: '<S225>/Constant'
                                        */
  real_T ispmac_const;                 /* Mask Parameter: ispmac_const
                                        * Referenced by: '<S72>/Constant'
                                        */
  real_T isecat_const_a;               /* Mask Parameter: isecat_const_a
                                        * Referenced by: '<S253>/Constant'
                                        */
  real_T isecat1_const;                /* Mask Parameter: isecat1_const
                                        * Referenced by: '<S254>/Constant'
                                        */
  real_T CompareToConstant_const;      /* Mask Parameter: CompareToConstant_const
                                        * Referenced by: '<S3>/Constant'
                                        */
  real_T Hand_Feedback_feedback_cntl_src;/* Mask Parameter: Hand_Feedback_feedback_cntl_src
                                          * Referenced by: '<S8>/block_settings'
                                          */
  real_T KINARM_HandInTarget_num_states;/* Mask Parameter: KINARM_HandInTarget_num_states
                                         * Referenced by: '<S11>/num_states'
                                         */
  real_T KINARM_HandInBox_num_states;  /* Mask Parameter: KINARM_HandInBox_num_states
                                        * Referenced by: '<S10>/num_states'
                                        */
  real_T Show_Target_A_num_states;     /* Mask Parameter: Show_Target_A_num_states
                                        * Referenced by: '<S24>/num_states'
                                        */
  real_T Show_TargetB_With_Label_num_states;/* Mask Parameter: Show_TargetB_With_Label_num_states
                                             * Referenced by: '<S22>/num_states'
                                             */
  real_T Show_Target_With_Label1_num_states;/* Mask Parameter: Show_Target_With_Label1_num_states
                                             * Referenced by: '<S265>/num_states'
                                             */
  real_T Show_Target_num_states;       /* Mask Parameter: Show_Target_num_states
                                        * Referenced by: '<S262>/num_states'
                                        */
  real_T Show_TargetC_With_Label_num_states;/* Mask Parameter: Show_TargetC_With_Label_num_states
                                             * Referenced by: '<S23>/num_states'
                                             */
  real_T Show_Box_num_states;          /* Mask Parameter: Show_Box_num_states
                                        * Referenced by: '<S21>/num_states'
                                        */
  real_T Show_Target_A_opacity;        /* Mask Parameter: Show_Target_A_opacity
                                        * Referenced by: '<S24>/Opacity'
                                        */
  real_T Show_TargetB_With_Label_opacity;/* Mask Parameter: Show_TargetB_With_Label_opacity
                                          * Referenced by: '<S22>/Opacity'
                                          */
  real_T Show_Target_With_Label1_opacity;/* Mask Parameter: Show_Target_With_Label1_opacity
                                          * Referenced by: '<S265>/Opacity'
                                          */
  real_T Show_Target_opacity;          /* Mask Parameter: Show_Target_opacity
                                        * Referenced by: '<S262>/Opacity'
                                        */
  real_T Show_TargetC_With_Label_opacity;/* Mask Parameter: Show_TargetC_With_Label_opacity
                                          * Referenced by: '<S23>/Opacity'
                                          */
  real_T Show_Box_opacity;             /* Mask Parameter: Show_Box_opacity
                                        * Referenced by: '<S21>/Opacity'
                                        */
  real_T Show_Target_A_target_display; /* Mask Parameter: Show_Target_A_target_display
                                        * Referenced by: '<S24>/Target_Display'
                                        */
  real_T Show_TargetB_With_Label_target_display;/* Mask Parameter: Show_TargetB_With_Label_target_display
                                                 * Referenced by: '<S22>/Target_Display'
                                                 */
  real_T Show_Target_With_Label1_target_display;/* Mask Parameter: Show_Target_With_Label1_target_display
                                                 * Referenced by: '<S265>/Target_Display'
                                                 */
  real_T Show_Target_target_display;   /* Mask Parameter: Show_Target_target_display
                                        * Referenced by: '<S262>/Target_Display'
                                        */
  real_T Show_TargetC_With_Label_target_display;/* Mask Parameter: Show_TargetC_With_Label_target_display
                                                 * Referenced by: '<S23>/Target_Display'
                                                 */
  real_T Show_Box_target_display;      /* Mask Parameter: Show_Box_target_display
                                        * Referenced by: '<S21>/Target_Display'
                                        */
  real_T KINARM_HandInTarget_target_type;/* Mask Parameter: KINARM_HandInTarget_target_type
                                          * Referenced by: '<S11>/Target_Type'
                                          */
  real_T KINARM_HandInBox_target_type; /* Mask Parameter: KINARM_HandInBox_target_type
                                        * Referenced by: '<S10>/Target_Type'
                                        */
  real_T Show_Target_A_target_type;    /* Mask Parameter: Show_Target_A_target_type
                                        * Referenced by: '<S24>/Target_Type'
                                        */
  real_T Show_TargetB_With_Label_target_type;/* Mask Parameter: Show_TargetB_With_Label_target_type
                                              * Referenced by: '<S22>/Target_Type'
                                              */
  real_T Show_Target_With_Label1_target_type;/* Mask Parameter: Show_Target_With_Label1_target_type
                                              * Referenced by: '<S265>/Target_Type'
                                              */
  real_T Show_Target_target_type;      /* Mask Parameter: Show_Target_target_type
                                        * Referenced by: '<S262>/Target_Type'
                                        */
  real_T Show_TargetC_With_Label_target_type;/* Mask Parameter: Show_TargetC_With_Label_target_type
                                              * Referenced by: '<S23>/Target_Type'
                                              */
  real_T Show_Box_target_type;         /* Mask Parameter: Show_Box_target_type
                                        * Referenced by: '<S21>/Target_Type'
                                        */
  real_T KINARM_HandInTarget_use_dominant_hand;/* Mask Parameter: KINARM_HandInTarget_use_dominant_hand
                                                * Referenced by: '<S11>/Use_Dominant_Hand?'
                                                */
  real_T KINARM_DistanceFromTarget_use_dominant_hand;/* Mask Parameter: KINARM_DistanceFromTarget_use_dominant_hand
                                                      * Referenced by: '<S9>/Use_Dominant_Hand?'
                                                      */
  real_T KINARM_HandInBox_use_dominant_hand;/* Mask Parameter: KINARM_HandInBox_use_dominant_hand
                                             * Referenced by: '<S10>/Use_Dominant_Hand?'
                                             */
  real_T Process_Video_CMD_video_delay;/* Mask Parameter: Process_Video_CMD_video_delay
                                        * Referenced by: '<S15>/Constant'
                                        */
  real_T DetectChange_vinit;           /* Mask Parameter: DetectChange_vinit
                                        * Referenced by: '<S205>/Delay Input1'
                                        */
  real_T DetectChange_vinit_n;         /* Mask Parameter: DetectChange_vinit_n
                                        * Referenced by: '<S209>/Delay Input1'
                                        */
  int32_T CompareToConstant_const_m;   /* Mask Parameter: CompareToConstant_const_m
                                        * Referenced by: '<S100>/Constant'
                                        */
  int32_T Compare_const;               /* Mask Parameter: Compare_const
                                        * Referenced by: '<S113>/Constant'
                                        */
  int32_T Compare_const_b;             /* Mask Parameter: Compare_const_b
                                        * Referenced by: '<S152>/Constant'
                                        */
  int32_T Compare_const_h;             /* Mask Parameter: Compare_const_h
                                        * Referenced by: '<S165>/Constant'
                                        */
  uint32_T WrapToZero_Threshold;       /* Mask Parameter: WrapToZero_Threshold
                                        * Referenced by: '<S57>/FixPt Switch'
                                        */
  uint32_T WrapToZero_Threshold_k;     /* Mask Parameter: WrapToZero_Threshold_k
                                        * Referenced by: '<S229>/FixPt Switch'
                                        */
  uint32_T WrapToZero_Threshold_o;     /* Mask Parameter: WrapToZero_Threshold_o
                                        * Referenced by: '<S241>/FixPt Switch'
                                        */
  uint32_T WrapToZero_Threshold_e;     /* Mask Parameter: WrapToZero_Threshold_e
                                        * Referenced by: '<S190>/FixPt Switch'
                                        */
  uint32_T WrapToZero_Threshold_c;     /* Mask Parameter: WrapToZero_Threshold_c
                                        * Referenced by: '<S47>/FixPt Switch'
                                        */
  uint32_T Compare_const_j;            /* Mask Parameter: Compare_const_j
                                        * Referenced by: '<S77>/Constant'
                                        */
  uint32_T CompareToConstant_const_b;  /* Mask Parameter: CompareToConstant_const_b
                                        * Referenced by: '<S275>/Constant'
                                        */
  uint32_T IfRunning_const;            /* Mask Parameter: IfRunning_const
                                        * Referenced by: '<S45>/Constant'
                                        */
  uint16_T WrapToZero_Threshold_d;     /* Mask Parameter: WrapToZero_Threshold_d
                                        * Referenced by: '<S221>/FixPt Switch'
                                        */
  real_T const_Value[5];               /* Expression: [1 1 1 1 1]
                                        * Referenced by: '<S31>/const'
                                        */
  real_T Send_P1_Size[2];              /* Computed Parameter: Send_P1_Size
                                        * Referenced by: '<S31>/Send'
                                        */
  real_T Send_P1[11];                  /* Computed Parameter: Send_P1
                                        * Referenced by: '<S31>/Send'
                                        */
  real_T Send_P2_Size[2];              /* Computed Parameter: Send_P2_Size
                                        * Referenced by: '<S31>/Send'
                                        */
  real_T Send_P2;                      /* Expression: ipPort
                                        * Referenced by: '<S31>/Send'
                                        */
  real_T Send_P3_Size[2];              /* Computed Parameter: Send_P3_Size
                                        * Referenced by: '<S31>/Send'
                                        */
  real_T Send_P3;                      /* Expression: localPort
                                        * Referenced by: '<S31>/Send'
                                        */
  real_T Send_P4_Size[2];              /* Computed Parameter: Send_P4_Size
                                        * Referenced by: '<S31>/Send'
                                        */
  real_T Send_P4;                      /* Expression: sampletime
                                        * Referenced by: '<S31>/Send'
                                        */
  real_T Send_P5_Size[2];              /* Computed Parameter: Send_P5_Size
                                        * Referenced by: '<S31>/Send'
                                        */
  real_T Send_P5;                      /* Expression: vblLen
                                        * Referenced by: '<S31>/Send'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S48>/Constant1'
                                        */
  real_T Constant_Value;               /* Expression: 1
                                        * Referenced by: '<S53>/Constant'
                                        */
  real_T UnitDelay_InitialCondition;   /* Expression: 0
                                        * Referenced by: '<S53>/Unit Delay'
                                        */
  real_T MaxFramesPerPacket_Value;     /* Expression: 3
                                        * Referenced by: '<S48>/Max Frames Per Packet'
                                        */
  real_T Send_P1_Size_b[2];            /* Computed Parameter: Send_P1_Size_b
                                        * Referenced by: '<S51>/Send'
                                        */
  real_T Send_P1_f[11];                /* Computed Parameter: Send_P1_f
                                        * Referenced by: '<S51>/Send'
                                        */
  real_T Send_P2_Size_i[2];            /* Computed Parameter: Send_P2_Size_i
                                        * Referenced by: '<S51>/Send'
                                        */
  real_T Send_P2_g;                    /* Expression: ipPort
                                        * Referenced by: '<S51>/Send'
                                        */
  real_T Send_P3_Size_g[2];            /* Computed Parameter: Send_P3_Size_g
                                        * Referenced by: '<S51>/Send'
                                        */
  real_T Send_P3_j;                    /* Expression: localPort
                                        * Referenced by: '<S51>/Send'
                                        */
  real_T Send_P4_Size_l[2];            /* Computed Parameter: Send_P4_Size_l
                                        * Referenced by: '<S51>/Send'
                                        */
  real_T Send_P4_k;                    /* Expression: sampletime
                                        * Referenced by: '<S51>/Send'
                                        */
  real_T Send_P5_Size_e[2];            /* Computed Parameter: Send_P5_Size_e
                                        * Referenced by: '<S51>/Send'
                                        */
  real_T Send_P5_k;                    /* Expression: vblLen
                                        * Referenced by: '<S51>/Send'
                                        */
  real_T runID_Value;                  /* Expression: 0
                                        * Referenced by: '<S32>/runID'
                                        */
  real_T Memory2_X0;                   /* Expression: 0
                                        * Referenced by: '<S50>/Memory2'
                                        */
  real_T RateTransition2_X0;           /* Expression: 0
                                        * Referenced by: '<S50>/Rate Transition2'
                                        */
  real_T UDPReceive_P1_Size[2];        /* Computed Parameter: UDPReceive_P1_Size
                                        * Referenced by: '<S50>/UDP Receive'
                                        */
  real_T UDPReceive_P1[15];            /* Computed Parameter: UDPReceive_P1
                                        * Referenced by: '<S50>/UDP Receive'
                                        */
  real_T UDPReceive_P2_Size[2];        /* Computed Parameter: UDPReceive_P2_Size
                                        * Referenced by: '<S50>/UDP Receive'
                                        */
  real_T UDPReceive_P2;                /* Expression: ipPort
                                        * Referenced by: '<S50>/UDP Receive'
                                        */
  real_T UDPReceive_P3_Size[2];        /* Computed Parameter: UDPReceive_P3_Size
                                        * Referenced by: '<S50>/UDP Receive'
                                        */
  real_T UDPReceive_P3;                /* Expression: width
                                        * Referenced by: '<S50>/UDP Receive'
                                        */
  real_T UDPReceive_P4_Size[2];        /* Computed Parameter: UDPReceive_P4_Size
                                        * Referenced by: '<S50>/UDP Receive'
                                        */
  real_T UDPReceive_P4;                /* Expression: sampletime
                                        * Referenced by: '<S50>/UDP Receive'
                                        */
  real_T UDPReceive_P5_Size[2];        /* Computed Parameter: UDPReceive_P5_Size
                                        * Referenced by: '<S50>/UDP Receive'
                                        */
  real_T UDPReceive_P5;                /* Expression: vblLen
                                        * Referenced by: '<S50>/UDP Receive'
                                        */
  real_T TmpRTBAtforcestrobeOutport1_X0;/* Expression: 0
                                         * Referenced by: synthesized block
                                         */
  real_T TaskClock_Amp;                /* Expression: 1
                                        * Referenced by: '<S32>/Task Clock'
                                        */
  real_T TaskClock_Period;             /* Computed Parameter: TaskClock_Period
                                        * Referenced by: '<S32>/Task Clock'
                                        */
  real_T TaskClock_Duty;               /* Computed Parameter: TaskClock_Duty
                                        * Referenced by: '<S32>/Task Clock'
                                        */
  real_T TaskClock_PhaseDelay;         /* Expression: 0
                                        * Referenced by: '<S32>/Task Clock'
                                        */
  real_T UDPReceivePortReset_P1_Size[2];/* Computed Parameter: UDPReceivePortReset_P1_Size
                                         * Referenced by: '<S50>/UDP Receive Port Reset'
                                         */
  real_T UDPReceivePortReset_P1[11];   /* Computed Parameter: UDPReceivePortReset_P1
                                        * Referenced by: '<S50>/UDP Receive Port Reset'
                                        */
  real_T UDPReceivePortReset_P2_Size[2];/* Computed Parameter: UDPReceivePortReset_P2_Size
                                         * Referenced by: '<S50>/UDP Receive Port Reset'
                                         */
  real_T UDPReceivePortReset_P2;       /* Expression: ipPort
                                        * Referenced by: '<S50>/UDP Receive Port Reset'
                                        */
  real_T UDPReceivePortReset_P3_Size[2];/* Computed Parameter: UDPReceivePortReset_P3_Size
                                         * Referenced by: '<S50>/UDP Receive Port Reset'
                                         */
  real_T UDPReceivePortReset_P3;       /* Expression: width
                                        * Referenced by: '<S50>/UDP Receive Port Reset'
                                        */
  real_T UDPReceivePortReset_P4_Size[2];/* Computed Parameter: UDPReceivePortReset_P4_Size
                                         * Referenced by: '<S50>/UDP Receive Port Reset'
                                         */
  real_T UDPReceivePortReset_P4;       /* Expression: sampletime
                                        * Referenced by: '<S50>/UDP Receive Port Reset'
                                        */
  real_T UDPReceivePortReset_P5_Size[2];/* Computed Parameter: UDPReceivePortReset_P5_Size
                                         * Referenced by: '<S50>/UDP Receive Port Reset'
                                         */
  real_T UDPReceivePortReset_P5;       /* Expression: vblLen
                                        * Referenced by: '<S50>/UDP Receive Port Reset'
                                        */
  real_T Receive_P1_Size[2];           /* Computed Parameter: Receive_P1_Size
                                        * Referenced by: '<S58>/Receive'
                                        */
  real_T Receive_P1[13];               /* Computed Parameter: Receive_P1
                                        * Referenced by: '<S58>/Receive'
                                        */
  real_T Receive_P2_Size[2];           /* Computed Parameter: Receive_P2_Size
                                        * Referenced by: '<S58>/Receive'
                                        */
  real_T Receive_P2;                   /* Expression: ipPort
                                        * Referenced by: '<S58>/Receive'
                                        */
  real_T Receive_P3_Size[2];           /* Computed Parameter: Receive_P3_Size
                                        * Referenced by: '<S58>/Receive'
                                        */
  real_T Receive_P3;                   /* Expression: width
                                        * Referenced by: '<S58>/Receive'
                                        */
  real_T Receive_P4_Size[2];           /* Computed Parameter: Receive_P4_Size
                                        * Referenced by: '<S58>/Receive'
                                        */
  real_T Receive_P4;                   /* Expression: sampletime
                                        * Referenced by: '<S58>/Receive'
                                        */
  real_T Receive_P5_Size[2];           /* Computed Parameter: Receive_P5_Size
                                        * Referenced by: '<S58>/Receive'
                                        */
  real_T Receive_P5;                   /* Expression: vblLen
                                        * Referenced by: '<S58>/Receive'
                                        */
  real_T Receive1_P1_Size[2];          /* Computed Parameter: Receive1_P1_Size
                                        * Referenced by: '<S59>/Receive1'
                                        */
  real_T Receive1_P1[13];              /* Computed Parameter: Receive1_P1
                                        * Referenced by: '<S59>/Receive1'
                                        */
  real_T Receive1_P2_Size[2];          /* Computed Parameter: Receive1_P2_Size
                                        * Referenced by: '<S59>/Receive1'
                                        */
  real_T Receive1_P2;                  /* Expression: ipPort
                                        * Referenced by: '<S59>/Receive1'
                                        */
  real_T Receive1_P3_Size[2];          /* Computed Parameter: Receive1_P3_Size
                                        * Referenced by: '<S59>/Receive1'
                                        */
  real_T Receive1_P3;                  /* Expression: width
                                        * Referenced by: '<S59>/Receive1'
                                        */
  real_T Receive1_P4_Size[2];          /* Computed Parameter: Receive1_P4_Size
                                        * Referenced by: '<S59>/Receive1'
                                        */
  real_T Receive1_P4;                  /* Expression: sampletime
                                        * Referenced by: '<S59>/Receive1'
                                        */
  real_T Receive1_P5_Size[2];          /* Computed Parameter: Receive1_P5_Size
                                        * Referenced by: '<S59>/Receive1'
                                        */
  real_T Receive1_P5;                  /* Expression: vblLen
                                        * Referenced by: '<S59>/Receive1'
                                        */
  real_T Send_P1_Size_i[2];            /* Computed Parameter: Send_P1_Size_i
                                        * Referenced by: '<S60>/Send'
                                        */
  real_T Send_P1_e[13];                /* Computed Parameter: Send_P1_e
                                        * Referenced by: '<S60>/Send'
                                        */
  real_T Send_P2_Size_l[2];            /* Computed Parameter: Send_P2_Size_l
                                        * Referenced by: '<S60>/Send'
                                        */
  real_T Send_P2_e;                    /* Expression: ipPort
                                        * Referenced by: '<S60>/Send'
                                        */
  real_T Send_P3_Size_a[2];            /* Computed Parameter: Send_P3_Size_a
                                        * Referenced by: '<S60>/Send'
                                        */
  real_T Send_P3_p;                    /* Expression: localPort
                                        * Referenced by: '<S60>/Send'
                                        */
  real_T Send_P4_Size_h[2];            /* Computed Parameter: Send_P4_Size_h
                                        * Referenced by: '<S60>/Send'
                                        */
  real_T Send_P4_k1;                   /* Expression: sampletime
                                        * Referenced by: '<S60>/Send'
                                        */
  real_T Send_P5_Size_es[2];           /* Computed Parameter: Send_P5_Size_es
                                        * Referenced by: '<S60>/Send'
                                        */
  real_T Send_P5_n;                    /* Expression: vblLen
                                        * Referenced by: '<S60>/Send'
                                        */
  real_T Send1_P1_Size[2];             /* Computed Parameter: Send1_P1_Size
                                        * Referenced by: '<S61>/Send1'
                                        */
  real_T Send1_P1[13];                 /* Computed Parameter: Send1_P1
                                        * Referenced by: '<S61>/Send1'
                                        */
  real_T Send1_P2_Size[2];             /* Computed Parameter: Send1_P2_Size
                                        * Referenced by: '<S61>/Send1'
                                        */
  real_T Send1_P2;                     /* Expression: ipPort
                                        * Referenced by: '<S61>/Send1'
                                        */
  real_T Send1_P3_Size[2];             /* Computed Parameter: Send1_P3_Size
                                        * Referenced by: '<S61>/Send1'
                                        */
  real_T Send1_P3;                     /* Expression: localPort
                                        * Referenced by: '<S61>/Send1'
                                        */
  real_T Send1_P4_Size[2];             /* Computed Parameter: Send1_P4_Size
                                        * Referenced by: '<S61>/Send1'
                                        */
  real_T Send1_P4;                     /* Expression: sampletime
                                        * Referenced by: '<S61>/Send1'
                                        */
  real_T Send1_P5_Size[2];             /* Computed Parameter: Send1_P5_Size
                                        * Referenced by: '<S61>/Send1'
                                        */
  real_T Send1_P5;                     /* Expression: vblLen
                                        * Referenced by: '<S61>/Send1'
                                        */
  real_T enable_plate1_Value;          /* Expression: 0
                                        * Referenced by: '<S33>/enable_plate1'
                                        */
  real_T enable_plate2_Value;          /* Expression: 0
                                        * Referenced by: '<S33>/enable_plate2'
                                        */
  real_T gain_Value;                   /* Expression: 256
                                        * Referenced by: '<S33>/gain'
                                        */
  real_T calibration_matrix1_Value[48];/* Expression: zeros(6,8)
                                        * Referenced by: '<S33>/calibration_matrix1'
                                        */
  real_T ain_slope1_Value;             /* Expression: -1
                                        * Referenced by: '<S33>/ain_slope1'
                                        */
  real_T ain_offset1_Value;            /* Expression: -1
                                        * Referenced by: '<S33>/ain_offset1'
                                        */
  real_T orientation1_Value;           /* Expression: 0
                                        * Referenced by: '<S33>/orientation1'
                                        */
  real_T zero_voltage_Value;           /* Expression: 0
                                        * Referenced by: '<S33>/zero_voltage'
                                        */
  real_T calibration_matrix2_Value[48];/* Expression: zeros(6,8)
                                        * Referenced by: '<S33>/calibration_matrix2'
                                        */
  real_T ain_slope2_Value;             /* Expression: -1
                                        * Referenced by: '<S33>/ain_slope2'
                                        */
  real_T ain_offset2_Value;            /* Expression: -1
                                        * Referenced by: '<S33>/ain_offset2'
                                        */
  real_T orientation2_Value;           /* Expression: 0
                                        * Referenced by: '<S33>/orientation2'
                                        */
  real_T BKINPDOReceiveElmoDrive_P1_Size[2];/* Computed Parameter: BKINPDOReceiveElmoDrive_P1_Size
                                             * Referenced by: '<S99>/BKIN PDO Receive ElmoDrive'
                                             */
  real_T BKINPDOReceiveElmoDrive_P1[39];/* Computed Parameter: BKINPDOReceiveElmoDrive_P1
                                         * Referenced by: '<S99>/BKIN PDO Receive ElmoDrive'
                                         */
  real_T BKINPDOReceiveElmoDrive_P2_Size[2];/* Computed Parameter: BKINPDOReceiveElmoDrive_P2_Size
                                             * Referenced by: '<S99>/BKIN PDO Receive ElmoDrive'
                                             */
  real_T BKINPDOReceiveElmoDrive_P2;   /* Expression: sig_offset
                                        * Referenced by: '<S99>/BKIN PDO Receive ElmoDrive'
                                        */
  real_T BKINPDOReceiveElmoDrive_P3_Size[2];/* Computed Parameter: BKINPDOReceiveElmoDrive_P3_Size
                                             * Referenced by: '<S99>/BKIN PDO Receive ElmoDrive'
                                             */
  real_T BKINPDOReceiveElmoDrive_P3;   /* Expression: sig_type
                                        * Referenced by: '<S99>/BKIN PDO Receive ElmoDrive'
                                        */
  real_T BKINPDOReceiveElmoDrive_P4_Size[2];/* Computed Parameter: BKINPDOReceiveElmoDrive_P4_Size
                                             * Referenced by: '<S99>/BKIN PDO Receive ElmoDrive'
                                             */
  real_T BKINPDOReceiveElmoDrive_P4;   /* Expression: type_size
                                        * Referenced by: '<S99>/BKIN PDO Receive ElmoDrive'
                                        */
  real_T BKINPDOReceiveElmoDrive_P5_Size[2];/* Computed Parameter: BKINPDOReceiveElmoDrive_P5_Size
                                             * Referenced by: '<S99>/BKIN PDO Receive ElmoDrive'
                                             */
  real_T BKINPDOReceiveElmoDrive_P5;   /* Expression: sig_dim
                                        * Referenced by: '<S99>/BKIN PDO Receive ElmoDrive'
                                        */
  real_T BKINPDOReceiveElmoDrive_P6_Size[2];/* Computed Parameter: BKINPDOReceiveElmoDrive_P6_Size
                                             * Referenced by: '<S99>/BKIN PDO Receive ElmoDrive'
                                             */
  real_T BKINPDOReceiveElmoDrive_P6;   /* Expression: device_id
                                        * Referenced by: '<S99>/BKIN PDO Receive ElmoDrive'
                                        */
  real_T BKINPDOReceiveElmoDrive_P7_Size[2];/* Computed Parameter: BKINPDOReceiveElmoDrive_P7_Size
                                             * Referenced by: '<S99>/BKIN PDO Receive ElmoDrive'
                                             */
  real_T BKINPDOReceiveElmoDrive_P7;   /* Expression: sample_time
                                        * Referenced by: '<S99>/BKIN PDO Receive ElmoDrive'
                                        */
  real_T driveID_Value;                /* Expression: 1
                                        * Referenced by: '<S102>/driveID'
                                        */
  real_T Memory_X0;                    /* Expression: 0
                                        * Referenced by: '<S108>/Memory'
                                        */
  real_T BKINPDOReceiveElmoDrive_P1_Size_i[2];/* Computed Parameter: BKINPDOReceiveElmoDrive_P1_Size_i
                                               * Referenced by: '<S112>/BKIN PDO Receive ElmoDrive'
                                               */
  real_T BKINPDOReceiveElmoDrive_P1_o[39];/* Computed Parameter: BKINPDOReceiveElmoDrive_P1_o
                                           * Referenced by: '<S112>/BKIN PDO Receive ElmoDrive'
                                           */
  real_T BKINPDOReceiveElmoDrive_P2_Size_d[2];/* Computed Parameter: BKINPDOReceiveElmoDrive_P2_Size_d
                                               * Referenced by: '<S112>/BKIN PDO Receive ElmoDrive'
                                               */
  real_T BKINPDOReceiveElmoDrive_P2_f; /* Expression: sig_offset
                                        * Referenced by: '<S112>/BKIN PDO Receive ElmoDrive'
                                        */
  real_T BKINPDOReceiveElmoDrive_P3_Size_g[2];/* Computed Parameter: BKINPDOReceiveElmoDrive_P3_Size_g
                                               * Referenced by: '<S112>/BKIN PDO Receive ElmoDrive'
                                               */
  real_T BKINPDOReceiveElmoDrive_P3_n; /* Expression: sig_type
                                        * Referenced by: '<S112>/BKIN PDO Receive ElmoDrive'
                                        */
  real_T BKINPDOReceiveElmoDrive_P4_Size_p[2];/* Computed Parameter: BKINPDOReceiveElmoDrive_P4_Size_p
                                               * Referenced by: '<S112>/BKIN PDO Receive ElmoDrive'
                                               */
  real_T BKINPDOReceiveElmoDrive_P4_d; /* Expression: type_size
                                        * Referenced by: '<S112>/BKIN PDO Receive ElmoDrive'
                                        */
  real_T BKINPDOReceiveElmoDrive_P5_Size_n[2];/* Computed Parameter: BKINPDOReceiveElmoDrive_P5_Size_n
                                               * Referenced by: '<S112>/BKIN PDO Receive ElmoDrive'
                                               */
  real_T BKINPDOReceiveElmoDrive_P5_b; /* Expression: sig_dim
                                        * Referenced by: '<S112>/BKIN PDO Receive ElmoDrive'
                                        */
  real_T BKINPDOReceiveElmoDrive_P6_Size_o[2];/* Computed Parameter: BKINPDOReceiveElmoDrive_P6_Size_o
                                               * Referenced by: '<S112>/BKIN PDO Receive ElmoDrive'
                                               */
  real_T BKINPDOReceiveElmoDrive_P6_m; /* Expression: device_id
                                        * Referenced by: '<S112>/BKIN PDO Receive ElmoDrive'
                                        */
  real_T BKINPDOReceiveElmoDrive_P7_Size_o[2];/* Computed Parameter: BKINPDOReceiveElmoDrive_P7_Size_o
                                               * Referenced by: '<S112>/BKIN PDO Receive ElmoDrive'
                                               */
  real_T BKINPDOReceiveElmoDrive_P7_d; /* Expression: sample_time
                                        * Referenced by: '<S112>/BKIN PDO Receive ElmoDrive'
                                        */
  real_T driveID_Value_c;              /* Expression: 2
                                        * Referenced by: '<S115>/driveID'
                                        */
  real_T Memory_X0_a;                  /* Expression: 0
                                        * Referenced by: '<S121>/Memory'
                                        */
  real_T readAddr_Value[3];            /* Expression: [0, 0, 0]
                                        * Referenced by: '<S91>/readAddr'
                                        */
  real_T Memory_X0_j;                  /* Expression: 0
                                        * Referenced by: '<S91>/Memory'
                                        */
  real_T writeData_Value[5];           /* Expression: [0, 0, 0, 0, 0]
                                        * Referenced by: '<S92>/writeData'
                                        */
  real_T BKINEtherCATPDOTransmit_P1_Size[2];/* Computed Parameter: BKINEtherCATPDOTransmit_P1_Size
                                             * Referenced by: '<S75>/BKIN EtherCAT PDO Transmit '
                                             */
  real_T BKINEtherCATPDOTransmit_P1[48];/* Computed Parameter: BKINEtherCATPDOTransmit_P1
                                         * Referenced by: '<S75>/BKIN EtherCAT PDO Transmit '
                                         */
  real_T BKINEtherCATPDOTransmit_P2_Size[2];/* Computed Parameter: BKINEtherCATPDOTransmit_P2_Size
                                             * Referenced by: '<S75>/BKIN EtherCAT PDO Transmit '
                                             */
  real_T BKINEtherCATPDOTransmit_P2;   /* Expression: sig_offset
                                        * Referenced by: '<S75>/BKIN EtherCAT PDO Transmit '
                                        */
  real_T BKINEtherCATPDOTransmit_P3_Size[2];/* Computed Parameter: BKINEtherCATPDOTransmit_P3_Size
                                             * Referenced by: '<S75>/BKIN EtherCAT PDO Transmit '
                                             */
  real_T BKINEtherCATPDOTransmit_P3;   /* Expression: sig_type
                                        * Referenced by: '<S75>/BKIN EtherCAT PDO Transmit '
                                        */
  real_T BKINEtherCATPDOTransmit_P4_Size[2];/* Computed Parameter: BKINEtherCATPDOTransmit_P4_Size
                                             * Referenced by: '<S75>/BKIN EtherCAT PDO Transmit '
                                             */
  real_T BKINEtherCATPDOTransmit_P4;   /* Expression: type_size
                                        * Referenced by: '<S75>/BKIN EtherCAT PDO Transmit '
                                        */
  real_T BKINEtherCATPDOTransmit_P5_Size[2];/* Computed Parameter: BKINEtherCATPDOTransmit_P5_Size
                                             * Referenced by: '<S75>/BKIN EtherCAT PDO Transmit '
                                             */
  real_T BKINEtherCATPDOTransmit_P5;   /* Expression: sig_dim
                                        * Referenced by: '<S75>/BKIN EtherCAT PDO Transmit '
                                        */
  real_T BKINEtherCATPDOTransmit_P6_Size[2];/* Computed Parameter: BKINEtherCATPDOTransmit_P6_Size
                                             * Referenced by: '<S75>/BKIN EtherCAT PDO Transmit '
                                             */
  real_T BKINEtherCATPDOTransmit_P6;   /* Expression: device_id
                                        * Referenced by: '<S75>/BKIN EtherCAT PDO Transmit '
                                        */
  real_T BKINEtherCATPDOTransmit_P7_Size[2];/* Computed Parameter: BKINEtherCATPDOTransmit_P7_Size
                                             * Referenced by: '<S75>/BKIN EtherCAT PDO Transmit '
                                             */
  real_T BKINEtherCATPDOTransmit_P7;   /* Expression: sample_time
                                        * Referenced by: '<S75>/BKIN EtherCAT PDO Transmit '
                                        */
  real_T BKINEtherCATPDOTransmit1_P1_Size[2];/* Computed Parameter: BKINEtherCATPDOTransmit1_P1_Size
                                              * Referenced by: '<S75>/BKIN EtherCAT PDO Transmit 1'
                                              */
  real_T BKINEtherCATPDOTransmit1_P1[48];/* Computed Parameter: BKINEtherCATPDOTransmit1_P1
                                          * Referenced by: '<S75>/BKIN EtherCAT PDO Transmit 1'
                                          */
  real_T BKINEtherCATPDOTransmit1_P2_Size[2];/* Computed Parameter: BKINEtherCATPDOTransmit1_P2_Size
                                              * Referenced by: '<S75>/BKIN EtherCAT PDO Transmit 1'
                                              */
  real_T BKINEtherCATPDOTransmit1_P2;  /* Expression: sig_offset
                                        * Referenced by: '<S75>/BKIN EtherCAT PDO Transmit 1'
                                        */
  real_T BKINEtherCATPDOTransmit1_P3_Size[2];/* Computed Parameter: BKINEtherCATPDOTransmit1_P3_Size
                                              * Referenced by: '<S75>/BKIN EtherCAT PDO Transmit 1'
                                              */
  real_T BKINEtherCATPDOTransmit1_P3;  /* Expression: sig_type
                                        * Referenced by: '<S75>/BKIN EtherCAT PDO Transmit 1'
                                        */
  real_T BKINEtherCATPDOTransmit1_P4_Size[2];/* Computed Parameter: BKINEtherCATPDOTransmit1_P4_Size
                                              * Referenced by: '<S75>/BKIN EtherCAT PDO Transmit 1'
                                              */
  real_T BKINEtherCATPDOTransmit1_P4;  /* Expression: type_size
                                        * Referenced by: '<S75>/BKIN EtherCAT PDO Transmit 1'
                                        */
  real_T BKINEtherCATPDOTransmit1_P5_Size[2];/* Computed Parameter: BKINEtherCATPDOTransmit1_P5_Size
                                              * Referenced by: '<S75>/BKIN EtherCAT PDO Transmit 1'
                                              */
  real_T BKINEtherCATPDOTransmit1_P5;  /* Expression: sig_dim
                                        * Referenced by: '<S75>/BKIN EtherCAT PDO Transmit 1'
                                        */
  real_T BKINEtherCATPDOTransmit1_P6_Size[2];/* Computed Parameter: BKINEtherCATPDOTransmit1_P6_Size
                                              * Referenced by: '<S75>/BKIN EtherCAT PDO Transmit 1'
                                              */
  real_T BKINEtherCATPDOTransmit1_P6;  /* Expression: device_id
                                        * Referenced by: '<S75>/BKIN EtherCAT PDO Transmit 1'
                                        */
  real_T BKINEtherCATPDOTransmit1_P7_Size[2];/* Computed Parameter: BKINEtherCATPDOTransmit1_P7_Size
                                              * Referenced by: '<S75>/BKIN EtherCAT PDO Transmit 1'
                                              */
  real_T BKINEtherCATPDOTransmit1_P7;  /* Expression: sample_time
                                        * Referenced by: '<S75>/BKIN EtherCAT PDO Transmit 1'
                                        */
  real_T enableMotors_Value;           /* Expression: 1
                                        * Referenced by: '<S75>/enableMotors'
                                        */
  real_T Memory_X0_f;                  /* Expression: 0
                                        * Referenced by: '<S85>/Memory'
                                        */
  real_T Memory_X0_jg;                 /* Expression: 0
                                        * Referenced by: '<S86>/Memory'
                                        */
  real_T BKINEtherCATPDOTransmit_P1_Size_f[2];/* Computed Parameter: BKINEtherCATPDOTransmit_P1_Size_f
                                               * Referenced by: '<S85>/BKIN EtherCAT PDO Transmit '
                                               */
  real_T BKINEtherCATPDOTransmit_P1_d[41];/* Computed Parameter: BKINEtherCATPDOTransmit_P1_d
                                           * Referenced by: '<S85>/BKIN EtherCAT PDO Transmit '
                                           */
  real_T BKINEtherCATPDOTransmit_P2_Size_e[2];/* Computed Parameter: BKINEtherCATPDOTransmit_P2_Size_e
                                               * Referenced by: '<S85>/BKIN EtherCAT PDO Transmit '
                                               */
  real_T BKINEtherCATPDOTransmit_P2_c; /* Expression: sig_offset
                                        * Referenced by: '<S85>/BKIN EtherCAT PDO Transmit '
                                        */
  real_T BKINEtherCATPDOTransmit_P3_Size_i[2];/* Computed Parameter: BKINEtherCATPDOTransmit_P3_Size_i
                                               * Referenced by: '<S85>/BKIN EtherCAT PDO Transmit '
                                               */
  real_T BKINEtherCATPDOTransmit_P3_g; /* Expression: sig_type
                                        * Referenced by: '<S85>/BKIN EtherCAT PDO Transmit '
                                        */
  real_T BKINEtherCATPDOTransmit_P4_Size_l[2];/* Computed Parameter: BKINEtherCATPDOTransmit_P4_Size_l
                                               * Referenced by: '<S85>/BKIN EtherCAT PDO Transmit '
                                               */
  real_T BKINEtherCATPDOTransmit_P4_n; /* Expression: type_size
                                        * Referenced by: '<S85>/BKIN EtherCAT PDO Transmit '
                                        */
  real_T BKINEtherCATPDOTransmit_P5_Size_i[2];/* Computed Parameter: BKINEtherCATPDOTransmit_P5_Size_i
                                               * Referenced by: '<S85>/BKIN EtherCAT PDO Transmit '
                                               */
  real_T BKINEtherCATPDOTransmit_P5_e; /* Expression: sig_dim
                                        * Referenced by: '<S85>/BKIN EtherCAT PDO Transmit '
                                        */
  real_T BKINEtherCATPDOTransmit_P6_Size_i[2];/* Computed Parameter: BKINEtherCATPDOTransmit_P6_Size_i
                                               * Referenced by: '<S85>/BKIN EtherCAT PDO Transmit '
                                               */
  real_T BKINEtherCATPDOTransmit_P6_n; /* Expression: device_id
                                        * Referenced by: '<S85>/BKIN EtherCAT PDO Transmit '
                                        */
  real_T BKINEtherCATPDOTransmit_P7_Size_g[2];/* Computed Parameter: BKINEtherCATPDOTransmit_P7_Size_g
                                               * Referenced by: '<S85>/BKIN EtherCAT PDO Transmit '
                                               */
  real_T BKINEtherCATPDOTransmit_P7_b; /* Expression: sample_time
                                        * Referenced by: '<S85>/BKIN EtherCAT PDO Transmit '
                                        */
  real_T MotorIdx_Value;               /* Expression: 1
                                        * Referenced by: '<S85>/MotorIdx'
                                        */
  real_T Memory1_X0;                   /* Expression: 0
                                        * Referenced by: '<S94>/Memory1'
                                        */
  real_T Memory2_X0_k;                 /* Expression: 0
                                        * Referenced by: '<S94>/Memory2'
                                        */
  real_T Memory2_X0_i;                 /* Expression: 0
                                        * Referenced by: '<S75>/Memory2'
                                        */
  real_T Memory3_X0;                   /* Expression: 0
                                        * Referenced by: '<S75>/Memory3'
                                        */
  real_T BKINEtherCATPDOTransmit_P1_Size_o[2];/* Computed Parameter: BKINEtherCATPDOTransmit_P1_Size_o
                                               * Referenced by: '<S86>/BKIN EtherCAT PDO Transmit '
                                               */
  real_T BKINEtherCATPDOTransmit_P1_i[41];/* Computed Parameter: BKINEtherCATPDOTransmit_P1_i
                                           * Referenced by: '<S86>/BKIN EtherCAT PDO Transmit '
                                           */
  real_T BKINEtherCATPDOTransmit_P2_Size_g[2];/* Computed Parameter: BKINEtherCATPDOTransmit_P2_Size_g
                                               * Referenced by: '<S86>/BKIN EtherCAT PDO Transmit '
                                               */
  real_T BKINEtherCATPDOTransmit_P2_n; /* Expression: sig_offset
                                        * Referenced by: '<S86>/BKIN EtherCAT PDO Transmit '
                                        */
  real_T BKINEtherCATPDOTransmit_P3_Size_n[2];/* Computed Parameter: BKINEtherCATPDOTransmit_P3_Size_n
                                               * Referenced by: '<S86>/BKIN EtherCAT PDO Transmit '
                                               */
  real_T BKINEtherCATPDOTransmit_P3_l; /* Expression: sig_type
                                        * Referenced by: '<S86>/BKIN EtherCAT PDO Transmit '
                                        */
  real_T BKINEtherCATPDOTransmit_P4_Size_k[2];/* Computed Parameter: BKINEtherCATPDOTransmit_P4_Size_k
                                               * Referenced by: '<S86>/BKIN EtherCAT PDO Transmit '
                                               */
  real_T BKINEtherCATPDOTransmit_P4_m; /* Expression: type_size
                                        * Referenced by: '<S86>/BKIN EtherCAT PDO Transmit '
                                        */
  real_T BKINEtherCATPDOTransmit_P5_Size_n[2];/* Computed Parameter: BKINEtherCATPDOTransmit_P5_Size_n
                                               * Referenced by: '<S86>/BKIN EtherCAT PDO Transmit '
                                               */
  real_T BKINEtherCATPDOTransmit_P5_d; /* Expression: sig_dim
                                        * Referenced by: '<S86>/BKIN EtherCAT PDO Transmit '
                                        */
  real_T BKINEtherCATPDOTransmit_P6_Size_j[2];/* Computed Parameter: BKINEtherCATPDOTransmit_P6_Size_j
                                               * Referenced by: '<S86>/BKIN EtherCAT PDO Transmit '
                                               */
  real_T BKINEtherCATPDOTransmit_P6_o; /* Expression: device_id
                                        * Referenced by: '<S86>/BKIN EtherCAT PDO Transmit '
                                        */
  real_T BKINEtherCATPDOTransmit_P7_Size_i[2];/* Computed Parameter: BKINEtherCATPDOTransmit_P7_Size_i
                                               * Referenced by: '<S86>/BKIN EtherCAT PDO Transmit '
                                               */
  real_T BKINEtherCATPDOTransmit_P7_l; /* Expression: sample_time
                                        * Referenced by: '<S86>/BKIN EtherCAT PDO Transmit '
                                        */
  real_T MotorIdx_Value_n;             /* Expression: 2
                                        * Referenced by: '<S86>/MotorIdx'
                                        */
  real_T enableCalibration_Value;      /* Expression: 0
                                        * Referenced by: '<S75>/enableCalibration'
                                        */
  real_T BKINPDOReceiveElmoDrive_P1_Size_g[2];/* Computed Parameter: BKINPDOReceiveElmoDrive_P1_Size_g
                                               * Referenced by: '<S151>/BKIN PDO Receive ElmoDrive'
                                               */
  real_T BKINPDOReceiveElmoDrive_P1_l[39];/* Computed Parameter: BKINPDOReceiveElmoDrive_P1_l
                                           * Referenced by: '<S151>/BKIN PDO Receive ElmoDrive'
                                           */
  real_T BKINPDOReceiveElmoDrive_P2_Size_p[2];/* Computed Parameter: BKINPDOReceiveElmoDrive_P2_Size_p
                                               * Referenced by: '<S151>/BKIN PDO Receive ElmoDrive'
                                               */
  real_T BKINPDOReceiveElmoDrive_P2_c; /* Expression: sig_offset
                                        * Referenced by: '<S151>/BKIN PDO Receive ElmoDrive'
                                        */
  real_T BKINPDOReceiveElmoDrive_P3_Size_c[2];/* Computed Parameter: BKINPDOReceiveElmoDrive_P3_Size_c
                                               * Referenced by: '<S151>/BKIN PDO Receive ElmoDrive'
                                               */
  real_T BKINPDOReceiveElmoDrive_P3_i; /* Expression: sig_type
                                        * Referenced by: '<S151>/BKIN PDO Receive ElmoDrive'
                                        */
  real_T BKINPDOReceiveElmoDrive_P4_Size_n[2];/* Computed Parameter: BKINPDOReceiveElmoDrive_P4_Size_n
                                               * Referenced by: '<S151>/BKIN PDO Receive ElmoDrive'
                                               */
  real_T BKINPDOReceiveElmoDrive_P4_m; /* Expression: type_size
                                        * Referenced by: '<S151>/BKIN PDO Receive ElmoDrive'
                                        */
  real_T BKINPDOReceiveElmoDrive_P5_Size_d[2];/* Computed Parameter: BKINPDOReceiveElmoDrive_P5_Size_d
                                               * Referenced by: '<S151>/BKIN PDO Receive ElmoDrive'
                                               */
  real_T BKINPDOReceiveElmoDrive_P5_g; /* Expression: sig_dim
                                        * Referenced by: '<S151>/BKIN PDO Receive ElmoDrive'
                                        */
  real_T BKINPDOReceiveElmoDrive_P6_Size_g[2];/* Computed Parameter: BKINPDOReceiveElmoDrive_P6_Size_g
                                               * Referenced by: '<S151>/BKIN PDO Receive ElmoDrive'
                                               */
  real_T BKINPDOReceiveElmoDrive_P6_e; /* Expression: device_id
                                        * Referenced by: '<S151>/BKIN PDO Receive ElmoDrive'
                                        */
  real_T BKINPDOReceiveElmoDrive_P7_Size_n[2];/* Computed Parameter: BKINPDOReceiveElmoDrive_P7_Size_n
                                               * Referenced by: '<S151>/BKIN PDO Receive ElmoDrive'
                                               */
  real_T BKINPDOReceiveElmoDrive_P7_n; /* Expression: sample_time
                                        * Referenced by: '<S151>/BKIN PDO Receive ElmoDrive'
                                        */
  real_T driveID_Value_i;              /* Expression: 3
                                        * Referenced by: '<S154>/driveID'
                                        */
  real_T Memory_X0_n;                  /* Expression: 0
                                        * Referenced by: '<S160>/Memory'
                                        */
  real_T BKINPDOReceiveElmoDrive_P1_Size_e[2];/* Computed Parameter: BKINPDOReceiveElmoDrive_P1_Size_e
                                               * Referenced by: '<S164>/BKIN PDO Receive ElmoDrive'
                                               */
  real_T BKINPDOReceiveElmoDrive_P1_h[39];/* Computed Parameter: BKINPDOReceiveElmoDrive_P1_h
                                           * Referenced by: '<S164>/BKIN PDO Receive ElmoDrive'
                                           */
  real_T BKINPDOReceiveElmoDrive_P2_Size_m[2];/* Computed Parameter: BKINPDOReceiveElmoDrive_P2_Size_m
                                               * Referenced by: '<S164>/BKIN PDO Receive ElmoDrive'
                                               */
  real_T BKINPDOReceiveElmoDrive_P2_h; /* Expression: sig_offset
                                        * Referenced by: '<S164>/BKIN PDO Receive ElmoDrive'
                                        */
  real_T BKINPDOReceiveElmoDrive_P3_Size_k[2];/* Computed Parameter: BKINPDOReceiveElmoDrive_P3_Size_k
                                               * Referenced by: '<S164>/BKIN PDO Receive ElmoDrive'
                                               */
  real_T BKINPDOReceiveElmoDrive_P3_k; /* Expression: sig_type
                                        * Referenced by: '<S164>/BKIN PDO Receive ElmoDrive'
                                        */
  real_T BKINPDOReceiveElmoDrive_P4_Size_j[2];/* Computed Parameter: BKINPDOReceiveElmoDrive_P4_Size_j
                                               * Referenced by: '<S164>/BKIN PDO Receive ElmoDrive'
                                               */
  real_T BKINPDOReceiveElmoDrive_P4_g; /* Expression: type_size
                                        * Referenced by: '<S164>/BKIN PDO Receive ElmoDrive'
                                        */
  real_T BKINPDOReceiveElmoDrive_P5_Size_o[2];/* Computed Parameter: BKINPDOReceiveElmoDrive_P5_Size_o
                                               * Referenced by: '<S164>/BKIN PDO Receive ElmoDrive'
                                               */
  real_T BKINPDOReceiveElmoDrive_P5_n; /* Expression: sig_dim
                                        * Referenced by: '<S164>/BKIN PDO Receive ElmoDrive'
                                        */
  real_T BKINPDOReceiveElmoDrive_P6_Size_n[2];/* Computed Parameter: BKINPDOReceiveElmoDrive_P6_Size_n
                                               * Referenced by: '<S164>/BKIN PDO Receive ElmoDrive'
                                               */
  real_T BKINPDOReceiveElmoDrive_P6_n; /* Expression: device_id
                                        * Referenced by: '<S164>/BKIN PDO Receive ElmoDrive'
                                        */
  real_T BKINPDOReceiveElmoDrive_P7_Size_c[2];/* Computed Parameter: BKINPDOReceiveElmoDrive_P7_Size_c
                                               * Referenced by: '<S164>/BKIN PDO Receive ElmoDrive'
                                               */
  real_T BKINPDOReceiveElmoDrive_P7_l; /* Expression: sample_time
                                        * Referenced by: '<S164>/BKIN PDO Receive ElmoDrive'
                                        */
  real_T driveID_Value_p;              /* Expression: 4
                                        * Referenced by: '<S167>/driveID'
                                        */
  real_T Memory_X0_o;                  /* Expression: 0
                                        * Referenced by: '<S173>/Memory'
                                        */
  real_T readAddr_Value_b[3];          /* Expression: [0, 0, 0]
                                        * Referenced by: '<S143>/readAddr'
                                        */
  real_T Memory_X0_i;                  /* Expression: 0
                                        * Referenced by: '<S143>/Memory'
                                        */
  real_T writeData_Value_f[5];         /* Expression: [0, 0, 0, 0, 0]
                                        * Referenced by: '<S144>/writeData'
                                        */
  real_T BKINEtherCATPDOTransmit_P1_Size_f1[2];/* Computed Parameter: BKINEtherCATPDOTransmit_P1_Size_f1
                                                * Referenced by: '<S76>/BKIN EtherCAT PDO Transmit '
                                                */
  real_T BKINEtherCATPDOTransmit_P1_o[48];/* Computed Parameter: BKINEtherCATPDOTransmit_P1_o
                                           * Referenced by: '<S76>/BKIN EtherCAT PDO Transmit '
                                           */
  real_T BKINEtherCATPDOTransmit_P2_Size_o[2];/* Computed Parameter: BKINEtherCATPDOTransmit_P2_Size_o
                                               * Referenced by: '<S76>/BKIN EtherCAT PDO Transmit '
                                               */
  real_T BKINEtherCATPDOTransmit_P2_m; /* Expression: sig_offset
                                        * Referenced by: '<S76>/BKIN EtherCAT PDO Transmit '
                                        */
  real_T BKINEtherCATPDOTransmit_P3_Size_o[2];/* Computed Parameter: BKINEtherCATPDOTransmit_P3_Size_o
                                               * Referenced by: '<S76>/BKIN EtherCAT PDO Transmit '
                                               */
  real_T BKINEtherCATPDOTransmit_P3_n; /* Expression: sig_type
                                        * Referenced by: '<S76>/BKIN EtherCAT PDO Transmit '
                                        */
  real_T BKINEtherCATPDOTransmit_P4_Size_a[2];/* Computed Parameter: BKINEtherCATPDOTransmit_P4_Size_a
                                               * Referenced by: '<S76>/BKIN EtherCAT PDO Transmit '
                                               */
  real_T BKINEtherCATPDOTransmit_P4_l; /* Expression: type_size
                                        * Referenced by: '<S76>/BKIN EtherCAT PDO Transmit '
                                        */
  real_T BKINEtherCATPDOTransmit_P5_Size_e[2];/* Computed Parameter: BKINEtherCATPDOTransmit_P5_Size_e
                                               * Referenced by: '<S76>/BKIN EtherCAT PDO Transmit '
                                               */
  real_T BKINEtherCATPDOTransmit_P5_g; /* Expression: sig_dim
                                        * Referenced by: '<S76>/BKIN EtherCAT PDO Transmit '
                                        */
  real_T BKINEtherCATPDOTransmit_P6_Size_l[2];/* Computed Parameter: BKINEtherCATPDOTransmit_P6_Size_l
                                               * Referenced by: '<S76>/BKIN EtherCAT PDO Transmit '
                                               */
  real_T BKINEtherCATPDOTransmit_P6_d; /* Expression: device_id
                                        * Referenced by: '<S76>/BKIN EtherCAT PDO Transmit '
                                        */
  real_T BKINEtherCATPDOTransmit_P7_Size_d[2];/* Computed Parameter: BKINEtherCATPDOTransmit_P7_Size_d
                                               * Referenced by: '<S76>/BKIN EtherCAT PDO Transmit '
                                               */
  real_T BKINEtherCATPDOTransmit_P7_o; /* Expression: sample_time
                                        * Referenced by: '<S76>/BKIN EtherCAT PDO Transmit '
                                        */
  real_T BKINEtherCATPDOTransmit1_P1_Size_l[2];/* Computed Parameter: BKINEtherCATPDOTransmit1_P1_Size_l
                                                * Referenced by: '<S76>/BKIN EtherCAT PDO Transmit 1'
                                                */
  real_T BKINEtherCATPDOTransmit1_P1_b[48];/* Computed Parameter: BKINEtherCATPDOTransmit1_P1_b
                                            * Referenced by: '<S76>/BKIN EtherCAT PDO Transmit 1'
                                            */
  real_T BKINEtherCATPDOTransmit1_P2_Size_m[2];/* Computed Parameter: BKINEtherCATPDOTransmit1_P2_Size_m
                                                * Referenced by: '<S76>/BKIN EtherCAT PDO Transmit 1'
                                                */
  real_T BKINEtherCATPDOTransmit1_P2_a;/* Expression: sig_offset
                                        * Referenced by: '<S76>/BKIN EtherCAT PDO Transmit 1'
                                        */
  real_T BKINEtherCATPDOTransmit1_P3_Size_a[2];/* Computed Parameter: BKINEtherCATPDOTransmit1_P3_Size_a
                                                * Referenced by: '<S76>/BKIN EtherCAT PDO Transmit 1'
                                                */
  real_T BKINEtherCATPDOTransmit1_P3_m;/* Expression: sig_type
                                        * Referenced by: '<S76>/BKIN EtherCAT PDO Transmit 1'
                                        */
  real_T BKINEtherCATPDOTransmit1_P4_Size_l[2];/* Computed Parameter: BKINEtherCATPDOTransmit1_P4_Size_l
                                                * Referenced by: '<S76>/BKIN EtherCAT PDO Transmit 1'
                                                */
  real_T BKINEtherCATPDOTransmit1_P4_e;/* Expression: type_size
                                        * Referenced by: '<S76>/BKIN EtherCAT PDO Transmit 1'
                                        */
  real_T BKINEtherCATPDOTransmit1_P5_Size_i[2];/* Computed Parameter: BKINEtherCATPDOTransmit1_P5_Size_i
                                                * Referenced by: '<S76>/BKIN EtherCAT PDO Transmit 1'
                                                */
  real_T BKINEtherCATPDOTransmit1_P5_a;/* Expression: sig_dim
                                        * Referenced by: '<S76>/BKIN EtherCAT PDO Transmit 1'
                                        */
  real_T BKINEtherCATPDOTransmit1_P6_Size_h[2];/* Computed Parameter: BKINEtherCATPDOTransmit1_P6_Size_h
                                                * Referenced by: '<S76>/BKIN EtherCAT PDO Transmit 1'
                                                */
  real_T BKINEtherCATPDOTransmit1_P6_j;/* Expression: device_id
                                        * Referenced by: '<S76>/BKIN EtherCAT PDO Transmit 1'
                                        */
  real_T BKINEtherCATPDOTransmit1_P7_Size_i[2];/* Computed Parameter: BKINEtherCATPDOTransmit1_P7_Size_i
                                                * Referenced by: '<S76>/BKIN EtherCAT PDO Transmit 1'
                                                */
  real_T BKINEtherCATPDOTransmit1_P7_n;/* Expression: sample_time
                                        * Referenced by: '<S76>/BKIN EtherCAT PDO Transmit 1'
                                        */
  real_T enableMotors_Value_c;         /* Expression: 1
                                        * Referenced by: '<S76>/enableMotors'
                                        */
  real_T Memory_X0_g;                  /* Expression: 0
                                        * Referenced by: '<S137>/Memory'
                                        */
  real_T Memory_X0_fo;                 /* Expression: 0
                                        * Referenced by: '<S138>/Memory'
                                        */
  real_T BKINEtherCATPDOTransmit_P1_Size_od[2];/* Computed Parameter: BKINEtherCATPDOTransmit_P1_Size_od
                                                * Referenced by: '<S137>/BKIN EtherCAT PDO Transmit '
                                                */
  real_T BKINEtherCATPDOTransmit_P1_k[41];/* Computed Parameter: BKINEtherCATPDOTransmit_P1_k
                                           * Referenced by: '<S137>/BKIN EtherCAT PDO Transmit '
                                           */
  real_T BKINEtherCATPDOTransmit_P2_Size_m[2];/* Computed Parameter: BKINEtherCATPDOTransmit_P2_Size_m
                                               * Referenced by: '<S137>/BKIN EtherCAT PDO Transmit '
                                               */
  real_T BKINEtherCATPDOTransmit_P2_no;/* Expression: sig_offset
                                        * Referenced by: '<S137>/BKIN EtherCAT PDO Transmit '
                                        */
  real_T BKINEtherCATPDOTransmit_P3_Size_g[2];/* Computed Parameter: BKINEtherCATPDOTransmit_P3_Size_g
                                               * Referenced by: '<S137>/BKIN EtherCAT PDO Transmit '
                                               */
  real_T BKINEtherCATPDOTransmit_P3_gf;/* Expression: sig_type
                                        * Referenced by: '<S137>/BKIN EtherCAT PDO Transmit '
                                        */
  real_T BKINEtherCATPDOTransmit_P4_Size_f[2];/* Computed Parameter: BKINEtherCATPDOTransmit_P4_Size_f
                                               * Referenced by: '<S137>/BKIN EtherCAT PDO Transmit '
                                               */
  real_T BKINEtherCATPDOTransmit_P4_d; /* Expression: type_size
                                        * Referenced by: '<S137>/BKIN EtherCAT PDO Transmit '
                                        */
  real_T BKINEtherCATPDOTransmit_P5_Size_f[2];/* Computed Parameter: BKINEtherCATPDOTransmit_P5_Size_f
                                               * Referenced by: '<S137>/BKIN EtherCAT PDO Transmit '
                                               */
  real_T BKINEtherCATPDOTransmit_P5_eg;/* Expression: sig_dim
                                        * Referenced by: '<S137>/BKIN EtherCAT PDO Transmit '
                                        */
  real_T BKINEtherCATPDOTransmit_P6_Size_g[2];/* Computed Parameter: BKINEtherCATPDOTransmit_P6_Size_g
                                               * Referenced by: '<S137>/BKIN EtherCAT PDO Transmit '
                                               */
  real_T BKINEtherCATPDOTransmit_P6_l; /* Expression: device_id
                                        * Referenced by: '<S137>/BKIN EtherCAT PDO Transmit '
                                        */
  real_T BKINEtherCATPDOTransmit_P7_Size_h[2];/* Computed Parameter: BKINEtherCATPDOTransmit_P7_Size_h
                                               * Referenced by: '<S137>/BKIN EtherCAT PDO Transmit '
                                               */
  real_T BKINEtherCATPDOTransmit_P7_m; /* Expression: sample_time
                                        * Referenced by: '<S137>/BKIN EtherCAT PDO Transmit '
                                        */
  real_T MotorIdx_Value_d;             /* Expression: 1
                                        * Referenced by: '<S137>/MotorIdx'
                                        */
  real_T Memory1_X0_f;                 /* Expression: 0
                                        * Referenced by: '<S146>/Memory1'
                                        */
  real_T Memory2_X0_e;                 /* Expression: 0
                                        * Referenced by: '<S146>/Memory2'
                                        */
  real_T Memory2_X0_o;                 /* Expression: 0
                                        * Referenced by: '<S76>/Memory2'
                                        */
  real_T Memory3_X0_i;                 /* Expression: 0
                                        * Referenced by: '<S76>/Memory3'
                                        */
  real_T BKINEtherCATPDOTransmit_P1_Size_e[2];/* Computed Parameter: BKINEtherCATPDOTransmit_P1_Size_e
                                               * Referenced by: '<S138>/BKIN EtherCAT PDO Transmit '
                                               */
  real_T BKINEtherCATPDOTransmit_P1_ib[41];/* Computed Parameter: BKINEtherCATPDOTransmit_P1_ib
                                            * Referenced by: '<S138>/BKIN EtherCAT PDO Transmit '
                                            */
  real_T BKINEtherCATPDOTransmit_P2_Size_mb[2];/* Computed Parameter: BKINEtherCATPDOTransmit_P2_Size_mb
                                                * Referenced by: '<S138>/BKIN EtherCAT PDO Transmit '
                                                */
  real_T BKINEtherCATPDOTransmit_P2_g; /* Expression: sig_offset
                                        * Referenced by: '<S138>/BKIN EtherCAT PDO Transmit '
                                        */
  real_T BKINEtherCATPDOTransmit_P3_Size_h[2];/* Computed Parameter: BKINEtherCATPDOTransmit_P3_Size_h
                                               * Referenced by: '<S138>/BKIN EtherCAT PDO Transmit '
                                               */
  real_T BKINEtherCATPDOTransmit_P3_e; /* Expression: sig_type
                                        * Referenced by: '<S138>/BKIN EtherCAT PDO Transmit '
                                        */
  real_T BKINEtherCATPDOTransmit_P4_Size_m[2];/* Computed Parameter: BKINEtherCATPDOTransmit_P4_Size_m
                                               * Referenced by: '<S138>/BKIN EtherCAT PDO Transmit '
                                               */
  real_T BKINEtherCATPDOTransmit_P4_g; /* Expression: type_size
                                        * Referenced by: '<S138>/BKIN EtherCAT PDO Transmit '
                                        */
  real_T BKINEtherCATPDOTransmit_P5_Size_iz[2];/* Computed Parameter: BKINEtherCATPDOTransmit_P5_Size_iz
                                                * Referenced by: '<S138>/BKIN EtherCAT PDO Transmit '
                                                */
  real_T BKINEtherCATPDOTransmit_P5_f; /* Expression: sig_dim
                                        * Referenced by: '<S138>/BKIN EtherCAT PDO Transmit '
                                        */
  real_T BKINEtherCATPDOTransmit_P6_Size_c[2];/* Computed Parameter: BKINEtherCATPDOTransmit_P6_Size_c
                                               * Referenced by: '<S138>/BKIN EtherCAT PDO Transmit '
                                               */
  real_T BKINEtherCATPDOTransmit_P6_di;/* Expression: device_id
                                        * Referenced by: '<S138>/BKIN EtherCAT PDO Transmit '
                                        */
  real_T BKINEtherCATPDOTransmit_P7_Size_j[2];/* Computed Parameter: BKINEtherCATPDOTransmit_P7_Size_j
                                               * Referenced by: '<S138>/BKIN EtherCAT PDO Transmit '
                                               */
  real_T BKINEtherCATPDOTransmit_P7_c; /* Expression: sample_time
                                        * Referenced by: '<S138>/BKIN EtherCAT PDO Transmit '
                                        */
  real_T MotorIdx_Value_n1;            /* Expression: 2
                                        * Referenced by: '<S138>/MotorIdx'
                                        */
  real_T enableCalibration_Value_h;    /* Expression: 0
                                        * Referenced by: '<S76>/enableCalibration'
                                        */
  real_T Constant_Value_o[7];          /* Expression: zeros(1, 7);
                                        * Referenced by: '<S202>/Constant'
                                        */
  real_T Switch_Threshold;             /* Expression: 0
                                        * Referenced by: '<S206>/Switch'
                                        */
  real_T Send_P1_Size_b4[2];           /* Computed Parameter: Send_P1_Size_b4
                                        * Referenced by: '<S206>/Send'
                                        */
  real_T Send_P1_c[12];                /* Computed Parameter: Send_P1_c
                                        * Referenced by: '<S206>/Send'
                                        */
  real_T Send_P2_Size_b[2];            /* Computed Parameter: Send_P2_Size_b
                                        * Referenced by: '<S206>/Send'
                                        */
  real_T Send_P2_o;                    /* Expression: ipPort
                                        * Referenced by: '<S206>/Send'
                                        */
  real_T Send_P3_Size_d[2];            /* Computed Parameter: Send_P3_Size_d
                                        * Referenced by: '<S206>/Send'
                                        */
  real_T Send_P3_d;                    /* Expression: localPort
                                        * Referenced by: '<S206>/Send'
                                        */
  real_T Send_P4_Size_lq[2];           /* Computed Parameter: Send_P4_Size_lq
                                        * Referenced by: '<S206>/Send'
                                        */
  real_T Send_P4_o;                    /* Expression: sampletime
                                        * Referenced by: '<S206>/Send'
                                        */
  real_T Send_P5_Size_j[2];            /* Computed Parameter: Send_P5_Size_j
                                        * Referenced by: '<S206>/Send'
                                        */
  real_T Send_P5_m;                    /* Expression: vblLen
                                        * Referenced by: '<S206>/Send'
                                        */
  real_T Constant1_Value_a[7];         /* Expression: zeros(1, 7);
                                        * Referenced by: '<S203>/Constant1'
                                        */
  real_T Switch_Threshold_j;           /* Expression: 0
                                        * Referenced by: '<S208>/Switch'
                                        */
  real_T Send_P1_Size_c[2];            /* Computed Parameter: Send_P1_Size_c
                                        * Referenced by: '<S208>/Send'
                                        */
  real_T Send_P1_i[12];                /* Computed Parameter: Send_P1_i
                                        * Referenced by: '<S208>/Send'
                                        */
  real_T Send_P2_Size_m[2];            /* Computed Parameter: Send_P2_Size_m
                                        * Referenced by: '<S208>/Send'
                                        */
  real_T Send_P2_m;                    /* Expression: ipPort
                                        * Referenced by: '<S208>/Send'
                                        */
  real_T Send_P3_Size_p[2];            /* Computed Parameter: Send_P3_Size_p
                                        * Referenced by: '<S208>/Send'
                                        */
  real_T Send_P3_a;                    /* Expression: localPort
                                        * Referenced by: '<S208>/Send'
                                        */
  real_T Send_P4_Size_hn[2];           /* Computed Parameter: Send_P4_Size_hn
                                        * Referenced by: '<S208>/Send'
                                        */
  real_T Send_P4_b;                    /* Expression: sampletime
                                        * Referenced by: '<S208>/Send'
                                        */
  real_T Send_P5_Size_f[2];            /* Computed Parameter: Send_P5_Size_f
                                        * Referenced by: '<S208>/Send'
                                        */
  real_T Send_P5_o;                    /* Expression: vblLen
                                        * Referenced by: '<S208>/Send'
                                        */
  real_T ReceivefromRobot1ForceSensor_P1_Size[2];/* Computed Parameter: ReceivefromRobot1ForceSensor_P1_Size
                                                  * Referenced by: '<S202>/Receive from Robot 1 Force Sensor'
                                                  */
  real_T ReceivefromRobot1ForceSensor_P1[12];/* Computed Parameter: ReceivefromRobot1ForceSensor_P1
                                              * Referenced by: '<S202>/Receive from Robot 1 Force Sensor'
                                              */
  real_T ReceivefromRobot1ForceSensor_P2_Size[2];/* Computed Parameter: ReceivefromRobot1ForceSensor_P2_Size
                                                  * Referenced by: '<S202>/Receive from Robot 1 Force Sensor'
                                                  */
  real_T ReceivefromRobot1ForceSensor_P2;/* Expression: ipPort
                                          * Referenced by: '<S202>/Receive from Robot 1 Force Sensor'
                                          */
  real_T ReceivefromRobot1ForceSensor_P3_Size[2];/* Computed Parameter: ReceivefromRobot1ForceSensor_P3_Size
                                                  * Referenced by: '<S202>/Receive from Robot 1 Force Sensor'
                                                  */
  real_T ReceivefromRobot1ForceSensor_P3;/* Expression: width
                                          * Referenced by: '<S202>/Receive from Robot 1 Force Sensor'
                                          */
  real_T ReceivefromRobot1ForceSensor_P4_Size[2];/* Computed Parameter: ReceivefromRobot1ForceSensor_P4_Size
                                                  * Referenced by: '<S202>/Receive from Robot 1 Force Sensor'
                                                  */
  real_T ReceivefromRobot1ForceSensor_P4;/* Expression: sampletime
                                          * Referenced by: '<S202>/Receive from Robot 1 Force Sensor'
                                          */
  real_T ReceivefromRobot1ForceSensor_P5_Size[2];/* Computed Parameter: ReceivefromRobot1ForceSensor_P5_Size
                                                  * Referenced by: '<S202>/Receive from Robot 1 Force Sensor'
                                                  */
  real_T ReceivefromRobot1ForceSensor_P5;/* Expression: vblLen
                                          * Referenced by: '<S202>/Receive from Robot 1 Force Sensor'
                                          */
  real_T Switch_Threshold_m;           /* Expression: 0
                                        * Referenced by: '<S202>/Switch'
                                        */
  real_T ReceivefromRobot2ForceSensor_P1_Size[2];/* Computed Parameter: ReceivefromRobot2ForceSensor_P1_Size
                                                  * Referenced by: '<S203>/Receive from Robot 2 Force Sensor'
                                                  */
  real_T ReceivefromRobot2ForceSensor_P1[12];/* Computed Parameter: ReceivefromRobot2ForceSensor_P1
                                              * Referenced by: '<S203>/Receive from Robot 2 Force Sensor'
                                              */
  real_T ReceivefromRobot2ForceSensor_P2_Size[2];/* Computed Parameter: ReceivefromRobot2ForceSensor_P2_Size
                                                  * Referenced by: '<S203>/Receive from Robot 2 Force Sensor'
                                                  */
  real_T ReceivefromRobot2ForceSensor_P2;/* Expression: ipPort
                                          * Referenced by: '<S203>/Receive from Robot 2 Force Sensor'
                                          */
  real_T ReceivefromRobot2ForceSensor_P3_Size[2];/* Computed Parameter: ReceivefromRobot2ForceSensor_P3_Size
                                                  * Referenced by: '<S203>/Receive from Robot 2 Force Sensor'
                                                  */
  real_T ReceivefromRobot2ForceSensor_P3;/* Expression: width
                                          * Referenced by: '<S203>/Receive from Robot 2 Force Sensor'
                                          */
  real_T ReceivefromRobot2ForceSensor_P4_Size[2];/* Computed Parameter: ReceivefromRobot2ForceSensor_P4_Size
                                                  * Referenced by: '<S203>/Receive from Robot 2 Force Sensor'
                                                  */
  real_T ReceivefromRobot2ForceSensor_P4;/* Expression: sampletime
                                          * Referenced by: '<S203>/Receive from Robot 2 Force Sensor'
                                          */
  real_T ReceivefromRobot2ForceSensor_P5_Size[2];/* Computed Parameter: ReceivefromRobot2ForceSensor_P5_Size
                                                  * Referenced by: '<S203>/Receive from Robot 2 Force Sensor'
                                                  */
  real_T ReceivefromRobot2ForceSensor_P5;/* Expression: vblLen
                                          * Referenced by: '<S203>/Receive from Robot 2 Force Sensor'
                                          */
  real_T Switch1_Threshold;            /* Expression: 0
                                        * Referenced by: '<S203>/Switch1'
                                        */
  real_T stepduration_Value;           /* Expression: BKIN_STEP_TIME
                                        * Referenced by: '<S210>/step duration'
                                        */
  real_T DPRAMWatchDogoffset_Value;    /* Expression: 627
                                        * Referenced by: '<S212>/DPRAM WatchDog offset'
                                        */
  real_T DPRAMReadOffset_Value;        /* Expression: 534
                                        * Referenced by: '<S212>/DPRAM Read Offset'
                                        */
  real_T UnitDelay_InitialCondition_p; /* Expression: 0
                                        * Referenced by: '<S212>/Unit Delay'
                                        */
  real_T ReadSwitch_Value;             /* Expression: 0
                                        * Referenced by: '<S212>/Read Switch'
                                        */
  real_T ReadasUInt32_Value;           /* Expression: 0
                                        * Referenced by: '<S212>/Read as UInt32'
                                        */
  real_T DPRAMReadValue_Gain;          /* Expression: 1
                                        * Referenced by: '<S212>/DPRAM Read Value'
                                        */
  real_T UnitDelay1_InitialCondition;  /* Expression: 0
                                        * Referenced by: '<S212>/Unit Delay1'
                                        */
  real_T WriteSwitch_Value;            /* Expression: 0
                                        * Referenced by: '<S212>/Write Switch'
                                        */
  real_T DPRAMWriteOffset_Value;       /* Expression: 534
                                        * Referenced by: '<S212>/DPRAM Write Offset'
                                        */
  real_T DPRAMWriteValue_Value;        /* Expression: 1
                                        * Referenced by: '<S212>/DPRAM Write Value'
                                        */
  real_T robot_count_Value;            /* Expression: 1.0
                                        * Referenced by: '<S210>/robot_count'
                                        */
  real_T MATLABFunction_BKIN_STEP_TIME;/* Expression: BKIN_STEP_TIME
                                        * Referenced by: '<S223>/MATLAB Function'
                                        */
  real_T Receive_P1_Size_b[2];         /* Computed Parameter: Receive_P1_Size_b
                                        * Referenced by: '<S223>/Receive'
                                        */
  real_T Receive_P1_m[11];             /* Computed Parameter: Receive_P1_m
                                        * Referenced by: '<S223>/Receive'
                                        */
  real_T Receive_P2_Size_j[2];         /* Computed Parameter: Receive_P2_Size_j
                                        * Referenced by: '<S223>/Receive'
                                        */
  real_T Receive_P2_k;                 /* Expression: ipPort
                                        * Referenced by: '<S223>/Receive'
                                        */
  real_T Receive_P3_Size_k[2];         /* Computed Parameter: Receive_P3_Size_k
                                        * Referenced by: '<S223>/Receive'
                                        */
  real_T Receive_P3_e;                 /* Expression: width
                                        * Referenced by: '<S223>/Receive'
                                        */
  real_T Receive_P4_Size_o[2];         /* Computed Parameter: Receive_P4_Size_o
                                        * Referenced by: '<S223>/Receive'
                                        */
  real_T Receive_P4_h;                 /* Expression: sampletime
                                        * Referenced by: '<S223>/Receive'
                                        */
  real_T Receive_P5_Size_g[2];         /* Computed Parameter: Receive_P5_Size_g
                                        * Referenced by: '<S223>/Receive'
                                        */
  real_T Receive_P5_i;                 /* Expression: vblLen
                                        * Referenced by: '<S223>/Receive'
                                        */
  real_T ArmForceSensors_Value[2];     /* Expression: [0 0]
                                        * Referenced by: '<S232>/Arm Force Sensors'
                                        */
  real_T Constant_Value_l[4];          /* Expression: zeros(4, 1)
                                        * Referenced by: '<S224>/Constant'
                                        */
  real_T Constant_Value_d;             /* Expression: BKIN_STEP_TIME
                                        * Referenced by: '<S84>/Constant'
                                        */
  real_T ndorderbutterworth4Khz10hzcutoff_Value[3];/* Expression: [1.639178228e+04, -0.9780305085, 1.9777864838]
                                                    * Referenced by: '<S194>/2nd order butterworth, 4Khz, 10hz cutoff'
                                                    */
  real_T HandFeedbackStatus_Value;     /* Expression: 3
                                        * Referenced by: '<S238>/Hand Feedback Status'
                                        */
  real_T HandFeedbackSource_Value;     /* Expression: 0
                                        * Referenced by: '<S238>/Hand Feedback Source'
                                        */
  real_T HandFeedbackRadius_Value;     /* Expression: 0.005
                                        * Referenced by: '<S238>/Hand Feedback Radius'
                                        */
  real_T HandFeedbackColour_Value;     /* Expression: 16777215
                                        * Referenced by: '<S238>/Hand Feedback Colour'
                                        */
  real_T HandFeedbackFeedForward_Value;/* Expression: .05
                                        * Referenced by: '<S238>/Hand Feedback Feed Forward'
                                        */
  real_T GazeFeedbackStatus_Value;     /* Expression: 0
                                        * Referenced by: '<S238>/Gaze Feedback Status'
                                        */
  real_T DominantArm_Value;            /* Expression: 1
                                        * Referenced by: '<S70>/Dominant Arm'
                                        */
  real_T steptime_Value;               /* Expression: BKIN_STEP_TIME
                                        * Referenced by: '<S70>/step time'
                                        */
  real_T exopartnums_Value[6];         /* Expression: [13595, 13387, 0, 0, 0, 0]
                                        * Referenced by: '<S64>/exo part nums'
                                        */
  real_T eppartnums_Value[6];          /* Expression: [10212, 10213 ,0, 0,0,0]
                                        * Referenced by: '<S64>/ep part nums'
                                        */
  real_T nhppartnums_Value[6];         /* Expression: [0, 0 ,0,0,0,0]
                                        * Referenced by: '<S64>/nhp part nums'
                                        */
  real_T forceprimaryonly_Value;       /* Expression: 0
                                        * Referenced by: '<S64>/force primary only'
                                        */
  real_T maxerrorstofault_Value;       /* Expression: 40
                                        * Referenced by: '<S64>/max errors to fault'
                                        */
  real_T systemtype_Value;             /* Expression: 1
                                        * Referenced by: '<S34>/system type'
                                        */
  real_T BKINEtherCATPDOTransmit_P1_Size_n[2];/* Computed Parameter: BKINEtherCATPDOTransmit_P1_Size_n
                                               * Referenced by: '<S79>/BKIN EtherCAT PDO Transmit '
                                               */
  real_T BKINEtherCATPDOTransmit_P1_h[46];/* Computed Parameter: BKINEtherCATPDOTransmit_P1_h
                                           * Referenced by: '<S79>/BKIN EtherCAT PDO Transmit '
                                           */
  real_T BKINEtherCATPDOTransmit_P2_Size_b[2];/* Computed Parameter: BKINEtherCATPDOTransmit_P2_Size_b
                                               * Referenced by: '<S79>/BKIN EtherCAT PDO Transmit '
                                               */
  real_T BKINEtherCATPDOTransmit_P2_i; /* Expression: sig_offset
                                        * Referenced by: '<S79>/BKIN EtherCAT PDO Transmit '
                                        */
  real_T BKINEtherCATPDOTransmit_P3_Size_b[2];/* Computed Parameter: BKINEtherCATPDOTransmit_P3_Size_b
                                               * Referenced by: '<S79>/BKIN EtherCAT PDO Transmit '
                                               */
  real_T BKINEtherCATPDOTransmit_P3_k; /* Expression: sig_type
                                        * Referenced by: '<S79>/BKIN EtherCAT PDO Transmit '
                                        */
  real_T BKINEtherCATPDOTransmit_P4_Size_fk[2];/* Computed Parameter: BKINEtherCATPDOTransmit_P4_Size_fk
                                                * Referenced by: '<S79>/BKIN EtherCAT PDO Transmit '
                                                */
  real_T BKINEtherCATPDOTransmit_P4_dw;/* Expression: type_size
                                        * Referenced by: '<S79>/BKIN EtherCAT PDO Transmit '
                                        */
  real_T BKINEtherCATPDOTransmit_P5_Size_g[2];/* Computed Parameter: BKINEtherCATPDOTransmit_P5_Size_g
                                               * Referenced by: '<S79>/BKIN EtherCAT PDO Transmit '
                                               */
  real_T BKINEtherCATPDOTransmit_P5_n; /* Expression: sig_dim
                                        * Referenced by: '<S79>/BKIN EtherCAT PDO Transmit '
                                        */
  real_T BKINEtherCATPDOTransmit_P6_Size_k[2];/* Computed Parameter: BKINEtherCATPDOTransmit_P6_Size_k
                                               * Referenced by: '<S79>/BKIN EtherCAT PDO Transmit '
                                               */
  real_T BKINEtherCATPDOTransmit_P6_oc;/* Expression: device_id
                                        * Referenced by: '<S79>/BKIN EtherCAT PDO Transmit '
                                        */
  real_T BKINEtherCATPDOTransmit_P7_Size_gy[2];/* Computed Parameter: BKINEtherCATPDOTransmit_P7_Size_gy
                                                * Referenced by: '<S79>/BKIN EtherCAT PDO Transmit '
                                                */
  real_T BKINEtherCATPDOTransmit_P7_bj;/* Expression: sample_time
                                        * Referenced by: '<S79>/BKIN EtherCAT PDO Transmit '
                                        */
  real_T BKINEtherCATPDOTransmit1_P1_Size_b[2];/* Computed Parameter: BKINEtherCATPDOTransmit1_P1_Size_b
                                                * Referenced by: '<S79>/BKIN EtherCAT PDO Transmit 1'
                                                */
  real_T BKINEtherCATPDOTransmit1_P1_j[46];/* Computed Parameter: BKINEtherCATPDOTransmit1_P1_j
                                            * Referenced by: '<S79>/BKIN EtherCAT PDO Transmit 1'
                                            */
  real_T BKINEtherCATPDOTransmit1_P2_Size_p[2];/* Computed Parameter: BKINEtherCATPDOTransmit1_P2_Size_p
                                                * Referenced by: '<S79>/BKIN EtherCAT PDO Transmit 1'
                                                */
  real_T BKINEtherCATPDOTransmit1_P2_i;/* Expression: sig_offset
                                        * Referenced by: '<S79>/BKIN EtherCAT PDO Transmit 1'
                                        */
  real_T BKINEtherCATPDOTransmit1_P3_Size_g[2];/* Computed Parameter: BKINEtherCATPDOTransmit1_P3_Size_g
                                                * Referenced by: '<S79>/BKIN EtherCAT PDO Transmit 1'
                                                */
  real_T BKINEtherCATPDOTransmit1_P3_e;/* Expression: sig_type
                                        * Referenced by: '<S79>/BKIN EtherCAT PDO Transmit 1'
                                        */
  real_T BKINEtherCATPDOTransmit1_P4_Size_c[2];/* Computed Parameter: BKINEtherCATPDOTransmit1_P4_Size_c
                                                * Referenced by: '<S79>/BKIN EtherCAT PDO Transmit 1'
                                                */
  real_T BKINEtherCATPDOTransmit1_P4_j;/* Expression: type_size
                                        * Referenced by: '<S79>/BKIN EtherCAT PDO Transmit 1'
                                        */
  real_T BKINEtherCATPDOTransmit1_P5_Size_m[2];/* Computed Parameter: BKINEtherCATPDOTransmit1_P5_Size_m
                                                * Referenced by: '<S79>/BKIN EtherCAT PDO Transmit 1'
                                                */
  real_T BKINEtherCATPDOTransmit1_P5_c;/* Expression: sig_dim
                                        * Referenced by: '<S79>/BKIN EtherCAT PDO Transmit 1'
                                        */
  real_T BKINEtherCATPDOTransmit1_P6_Size_p[2];/* Computed Parameter: BKINEtherCATPDOTransmit1_P6_Size_p
                                                * Referenced by: '<S79>/BKIN EtherCAT PDO Transmit 1'
                                                */
  real_T BKINEtherCATPDOTransmit1_P6_m;/* Expression: device_id
                                        * Referenced by: '<S79>/BKIN EtherCAT PDO Transmit 1'
                                        */
  real_T BKINEtherCATPDOTransmit1_P7_Size_f[2];/* Computed Parameter: BKINEtherCATPDOTransmit1_P7_Size_f
                                                * Referenced by: '<S79>/BKIN EtherCAT PDO Transmit 1'
                                                */
  real_T BKINEtherCATPDOTransmit1_P7_h;/* Expression: sample_time
                                        * Referenced by: '<S79>/BKIN EtherCAT PDO Transmit 1'
                                        */
  real_T BKINEtherCATPDOTransmit2_P1_Size[2];/* Computed Parameter: BKINEtherCATPDOTransmit2_P1_Size
                                              * Referenced by: '<S79>/BKIN EtherCAT PDO Transmit 2'
                                              */
  real_T BKINEtherCATPDOTransmit2_P1[46];/* Computed Parameter: BKINEtherCATPDOTransmit2_P1
                                          * Referenced by: '<S79>/BKIN EtherCAT PDO Transmit 2'
                                          */
  real_T BKINEtherCATPDOTransmit2_P2_Size[2];/* Computed Parameter: BKINEtherCATPDOTransmit2_P2_Size
                                              * Referenced by: '<S79>/BKIN EtherCAT PDO Transmit 2'
                                              */
  real_T BKINEtherCATPDOTransmit2_P2;  /* Expression: sig_offset
                                        * Referenced by: '<S79>/BKIN EtherCAT PDO Transmit 2'
                                        */
  real_T BKINEtherCATPDOTransmit2_P3_Size[2];/* Computed Parameter: BKINEtherCATPDOTransmit2_P3_Size
                                              * Referenced by: '<S79>/BKIN EtherCAT PDO Transmit 2'
                                              */
  real_T BKINEtherCATPDOTransmit2_P3;  /* Expression: sig_type
                                        * Referenced by: '<S79>/BKIN EtherCAT PDO Transmit 2'
                                        */
  real_T BKINEtherCATPDOTransmit2_P4_Size[2];/* Computed Parameter: BKINEtherCATPDOTransmit2_P4_Size
                                              * Referenced by: '<S79>/BKIN EtherCAT PDO Transmit 2'
                                              */
  real_T BKINEtherCATPDOTransmit2_P4;  /* Expression: type_size
                                        * Referenced by: '<S79>/BKIN EtherCAT PDO Transmit 2'
                                        */
  real_T BKINEtherCATPDOTransmit2_P5_Size[2];/* Computed Parameter: BKINEtherCATPDOTransmit2_P5_Size
                                              * Referenced by: '<S79>/BKIN EtherCAT PDO Transmit 2'
                                              */
  real_T BKINEtherCATPDOTransmit2_P5;  /* Expression: sig_dim
                                        * Referenced by: '<S79>/BKIN EtherCAT PDO Transmit 2'
                                        */
  real_T BKINEtherCATPDOTransmit2_P6_Size[2];/* Computed Parameter: BKINEtherCATPDOTransmit2_P6_Size
                                              * Referenced by: '<S79>/BKIN EtherCAT PDO Transmit 2'
                                              */
  real_T BKINEtherCATPDOTransmit2_P6;  /* Expression: device_id
                                        * Referenced by: '<S79>/BKIN EtherCAT PDO Transmit 2'
                                        */
  real_T BKINEtherCATPDOTransmit2_P7_Size[2];/* Computed Parameter: BKINEtherCATPDOTransmit2_P7_Size
                                              * Referenced by: '<S79>/BKIN EtherCAT PDO Transmit 2'
                                              */
  real_T BKINEtherCATPDOTransmit2_P7;  /* Expression: sample_time
                                        * Referenced by: '<S79>/BKIN EtherCAT PDO Transmit 2'
                                        */
  real_T BKINEtherCATPDOTransmit3_P1_Size[2];/* Computed Parameter: BKINEtherCATPDOTransmit3_P1_Size
                                              * Referenced by: '<S79>/BKIN EtherCAT PDO Transmit 3'
                                              */
  real_T BKINEtherCATPDOTransmit3_P1[46];/* Computed Parameter: BKINEtherCATPDOTransmit3_P1
                                          * Referenced by: '<S79>/BKIN EtherCAT PDO Transmit 3'
                                          */
  real_T BKINEtherCATPDOTransmit3_P2_Size[2];/* Computed Parameter: BKINEtherCATPDOTransmit3_P2_Size
                                              * Referenced by: '<S79>/BKIN EtherCAT PDO Transmit 3'
                                              */
  real_T BKINEtherCATPDOTransmit3_P2;  /* Expression: sig_offset
                                        * Referenced by: '<S79>/BKIN EtherCAT PDO Transmit 3'
                                        */
  real_T BKINEtherCATPDOTransmit3_P3_Size[2];/* Computed Parameter: BKINEtherCATPDOTransmit3_P3_Size
                                              * Referenced by: '<S79>/BKIN EtherCAT PDO Transmit 3'
                                              */
  real_T BKINEtherCATPDOTransmit3_P3;  /* Expression: sig_type
                                        * Referenced by: '<S79>/BKIN EtherCAT PDO Transmit 3'
                                        */
  real_T BKINEtherCATPDOTransmit3_P4_Size[2];/* Computed Parameter: BKINEtherCATPDOTransmit3_P4_Size
                                              * Referenced by: '<S79>/BKIN EtherCAT PDO Transmit 3'
                                              */
  real_T BKINEtherCATPDOTransmit3_P4;  /* Expression: type_size
                                        * Referenced by: '<S79>/BKIN EtherCAT PDO Transmit 3'
                                        */
  real_T BKINEtherCATPDOTransmit3_P5_Size[2];/* Computed Parameter: BKINEtherCATPDOTransmit3_P5_Size
                                              * Referenced by: '<S79>/BKIN EtherCAT PDO Transmit 3'
                                              */
  real_T BKINEtherCATPDOTransmit3_P5;  /* Expression: sig_dim
                                        * Referenced by: '<S79>/BKIN EtherCAT PDO Transmit 3'
                                        */
  real_T BKINEtherCATPDOTransmit3_P6_Size[2];/* Computed Parameter: BKINEtherCATPDOTransmit3_P6_Size
                                              * Referenced by: '<S79>/BKIN EtherCAT PDO Transmit 3'
                                              */
  real_T BKINEtherCATPDOTransmit3_P6;  /* Expression: device_id
                                        * Referenced by: '<S79>/BKIN EtherCAT PDO Transmit 3'
                                        */
  real_T BKINEtherCATPDOTransmit3_P7_Size[2];/* Computed Parameter: BKINEtherCATPDOTransmit3_P7_Size
                                              * Referenced by: '<S79>/BKIN EtherCAT PDO Transmit 3'
                                              */
  real_T BKINEtherCATPDOTransmit3_P7;  /* Expression: sample_time
                                        * Referenced by: '<S79>/BKIN EtherCAT PDO Transmit 3'
                                        */
  real_T ArmOrientation_Value;         /* Expression: 1.0
                                        * Referenced by: '<S230>/Arm Orientation'
                                        */
  real_T ArmMotor1Orientation_Value;   /* Expression: -1.0
                                        * Referenced by: '<S230>/Arm Motor1 Orientation'
                                        */
  real_T ArmMotor2Orientation_Value;   /* Expression: -1.0
                                        * Referenced by: '<S230>/Arm Motor2 Orientation'
                                        */
  real_T ArmMotor1GearRatio_Value;     /* Expression: 4.0
                                        * Referenced by: '<S230>/Arm Motor1 Gear Ratio'
                                        */
  real_T ArmMotor2GearRatio_Value;     /* Expression: 4.0
                                        * Referenced by: '<S230>/Arm Motor2 Gear Ratio'
                                        */
  real_T ArmSecondaryEncoders_Value;   /* Expression: 0.0
                                        * Referenced by: '<S230>/Arm Secondary Encoders'
                                        */
  real_T ArmEncoderOrientation1_Value; /* Expression: 1
                                        * Referenced by: '<S230>/Arm Encoder Orientation 1'
                                        */
  real_T ArmEncoderOrientation2_Value; /* Expression: 1
                                        * Referenced by: '<S230>/Arm Encoder Orientation 2'
                                        */
  real_T Armprimaryencodercounts_Value;/* Expression: 20000
                                        * Referenced by: '<S230>/Arm primary encoder counts'
                                        */
  real_T Armsecondaryencodercounts_Value;/* Expression: 655360
                                          * Referenced by: '<S230>/Arm secondary encoder counts'
                                          */
  real_T ArmOrientation_Value_p;       /* Expression: 1.0
                                        * Referenced by: '<S231>/Arm Orientation'
                                        */
  real_T ArmMotor1Orientation_Value_a; /* Expression: -1.0
                                        * Referenced by: '<S231>/Arm Motor1 Orientation'
                                        */
  real_T ArmMotor2Orientation_Value_a; /* Expression: -1.0
                                        * Referenced by: '<S231>/Arm Motor2 Orientation'
                                        */
  real_T ArmMotor1GearRatio_Value_b;   /* Expression: 4.0
                                        * Referenced by: '<S231>/Arm Motor1 Gear Ratio'
                                        */
  real_T ArmMotor2GearRatio_Value_a;   /* Expression: 4.0
                                        * Referenced by: '<S231>/Arm Motor2 Gear Ratio'
                                        */
  real_T ArmSecondaryEncoders_Value_h; /* Expression: 0.0
                                        * Referenced by: '<S231>/Arm Secondary Encoders'
                                        */
  real_T ArmEncoderOrientation1_Value_f;/* Expression: 1
                                         * Referenced by: '<S231>/Arm Encoder Orientation 1'
                                         */
  real_T ArmEncoderOrientation2_Value_i;/* Expression: 1
                                         * Referenced by: '<S231>/Arm Encoder Orientation 2'
                                         */
  real_T Armprimaryencodercounts_Value_j;/* Expression: 20000
                                          * Referenced by: '<S231>/Arm primary encoder counts'
                                          */
  real_T Armsecondaryencodercounts_Value_i;/* Expression: 655360
                                            * Referenced by: '<S231>/Arm secondary encoder counts'
                                            */
  real_T ArmShoulderAngleOffset_Value; /* Expression: 0.0
                                        * Referenced by: '<S230>/Arm Shoulder Angle Offset'
                                        */
  real_T ArmElbowAngleOffset_Value;    /* Expression: 0.0
                                        * Referenced by: '<S230>/Arm Elbow Angle Offset'
                                        */
  real_T ArmShoulderX_Value;           /* Expression: 0.0
                                        * Referenced by: '<S230>/Arm Shoulder X'
                                        */
  real_T ArmShoulderY_Value;           /* Expression: 0.0
                                        * Referenced by: '<S230>/Arm Shoulder Y'
                                        */
  real_T ArmL1_Value;                  /* Expression: 0.0
                                        * Referenced by: '<S230>/Arm L1'
                                        */
  real_T ArmL2_Value;                  /* Expression: 0.0
                                        * Referenced by: '<S230>/Arm L2'
                                        */
  real_T ArmPointerOffset_Value;       /* Expression: 0.0
                                        * Referenced by: '<S230>/Arm Pointer Offset'
                                        */
  real_T ArmL3Error_Value;             /* Expression: 0.0
                                        * Referenced by: '<S230>/Arm L3 Error'
                                        */
  real_T Armrobottype_Value;           /* Expression: 0.0
                                        * Referenced by: '<S230>/Arm robot type'
                                        */
  real_T ArmTorqueConstant_Value;      /* Expression: 3.3
                                        * Referenced by: '<S230>/Arm Torque Constant'
                                        */
  real_T ArmL5_Value;                  /* Expression: 0.0
                                        * Referenced by: '<S230>/Arm L5'
                                        */
  real_T ArmL2L5Angle_Value;           /* Expression: 0.0
                                        * Referenced by: '<S230>/Arm L2 L5 Angle'
                                        */
  real_T ArmForceSensorAngleOffset_Value;/* Expression: 0.0
                                          * Referenced by: '<S230>/Arm Force Sensor Angle Offset'
                                          */
  real_T Armrobotversion_Value;        /* Expression: 1
                                        * Referenced by: '<S230>/Arm robot version'
                                        */
  real_T ArmShoulderAngleOffset_Value_l;/* Expression: 0.0
                                         * Referenced by: '<S231>/Arm Shoulder Angle Offset'
                                         */
  real_T ArmElbowAngleOffset_Value_n;  /* Expression: 0.0
                                        * Referenced by: '<S231>/Arm Elbow Angle Offset'
                                        */
  real_T ArmShoulderX_Value_j;         /* Expression: 0.0
                                        * Referenced by: '<S231>/Arm Shoulder X'
                                        */
  real_T ArmShoulderY_Value_p;         /* Expression: 0.0
                                        * Referenced by: '<S231>/Arm Shoulder Y'
                                        */
  real_T ArmL1_Value_c;                /* Expression: 0.0
                                        * Referenced by: '<S231>/Arm L1'
                                        */
  real_T ArmL2_Value_i;                /* Expression: 0.0
                                        * Referenced by: '<S231>/Arm L2'
                                        */
  real_T ArmPointerOffset_Value_b;     /* Expression: 0.0
                                        * Referenced by: '<S231>/Arm Pointer Offset'
                                        */
  real_T ArmL3Error_Value_l;           /* Expression: 0.0
                                        * Referenced by: '<S231>/Arm L3 Error'
                                        */
  real_T Armrobottype_Value_m;         /* Expression: 0.0
                                        * Referenced by: '<S231>/Arm robot type'
                                        */
  real_T ArmTorqueConstant_Value_a;    /* Expression: 3.3
                                        * Referenced by: '<S231>/Arm Torque Constant'
                                        */
  real_T ArmL5_Value_m;                /* Expression: 0.0
                                        * Referenced by: '<S231>/Arm L5'
                                        */
  real_T ArmL2L5Angle_Value_g;         /* Expression: 0.0
                                        * Referenced by: '<S231>/Arm L2 L5 Angle'
                                        */
  real_T ArmForceSensorAngleOffset_Value_c;/* Expression: 0.0
                                            * Referenced by: '<S231>/Arm Force Sensor Angle Offset'
                                            */
  real_T Armrobotversion_Value_b;      /* Expression: 1
                                        * Referenced by: '<S231>/Arm robot version'
                                        */
  real_T updateconstants_Value;        /* Expression: 1
                                        * Referenced by: '<S68>/update constants'
                                        */
  real_T ECATErrMsgs_InitialValue[20]; /* Expression: zeros(4, 5)
                                        * Referenced by: '<S34>/ECAT Err Msgs'
                                        */
  real_T ECATTorquefeedback_InitialValue[8];/* Expression: [0, 0, 0, 0, 0, 0, 0, 0]
                                             * Referenced by: '<S34>/ECATTorque feedback'
                                             */
  real_T HWSettings_InitialValue[24];  /* Expression: zeros(24, 1)
                                        * Referenced by: '<S34>/HW Settings'
                                        */
  real_T Kinematics_InitialValue[20];  /* Expression: zeros(20, 1)
                                        * Referenced by: '<S34>/Kinematics'
                                        */
  real_T PrimaryEnc_InitialValue[12];  /* Expression: zeros(12, 1)
                                        * Referenced by: '<S34>/PrimaryEnc'
                                        */
  real_T RobotCalib_InitialValue[16];  /* Expression: zeros(16, 1)
                                        * Referenced by: '<S34>/Robot Calib'
                                        */
  real_T RobotRevision_InitialValue[2];/* Expression: [1, 1]
                                        * Referenced by: '<S34>/RobotRevision'
                                        */
  real_T delays_InitialValue[4];       /* Expression: zeros(4, 1)
                                        * Referenced by: '<S34>/delays'
                                        */
  real_T hasFTsensors_InitialValue[2]; /* Expression: [0, 0]
                                        * Referenced by: '<S34>/has FT sensors'
                                        */
  real_T ELTrackingAvailable_Value;    /* Expression: 1
                                        * Referenced by: '<S35>/EL Tracking Available'
                                        */
  real_T ELCameraAngle_Value[2];       /* Expression: [47, -10]
                                        * Referenced by: '<S35>/EL Camera Angle'
                                        */
  real_T ELCameraPosition_Value[3];    /* Expression: [0.10, 0.35, -0.15]
                                        * Referenced by: '<S35>/EL Camera Position'
                                        */
  real_T ELCameraFocalLength_Value;    /* Expression: 0.017
                                        * Referenced by: '<S35>/EL Camera Focal Length'
                                        */
  real_T Gain_Gain;                    /* Expression: -1
                                        * Referenced by: '<S35>/Gain'
                                        */
  real_T RateTransition_X0;            /* Expression: 0
                                        * Referenced by: '<S35>/Rate Transition'
                                        */
  real_T Receive_P1_Size_o[2];         /* Computed Parameter: Receive_P1_Size_o
                                        * Referenced by: '<S35>/Receive'
                                        */
  real_T Receive_P1_i[7];              /* Computed Parameter: Receive_P1_i
                                        * Referenced by: '<S35>/Receive'
                                        */
  real_T Receive_P2_Size_e[2];         /* Computed Parameter: Receive_P2_Size_e
                                        * Referenced by: '<S35>/Receive'
                                        */
  real_T Receive_P2_i;                 /* Expression: ipPort
                                        * Referenced by: '<S35>/Receive'
                                        */
  real_T Receive_P3_Size_ky[2];        /* Computed Parameter: Receive_P3_Size_ky
                                        * Referenced by: '<S35>/Receive'
                                        */
  real_T Receive_P3_l;                 /* Expression: width
                                        * Referenced by: '<S35>/Receive'
                                        */
  real_T Receive_P4_Size_f[2];         /* Computed Parameter: Receive_P4_Size_f
                                        * Referenced by: '<S35>/Receive'
                                        */
  real_T Receive_P4_g;                 /* Expression: sampletime
                                        * Referenced by: '<S35>/Receive'
                                        */
  real_T Receive_P5_Size_k[2];         /* Computed Parameter: Receive_P5_Size_k
                                        * Referenced by: '<S35>/Receive'
                                        */
  real_T Receive_P5_a;                 /* Expression: vblLen
                                        * Referenced by: '<S35>/Receive'
                                        */
  real_T BKINEtherCATPDOTransmit1_P1_Size_m[2];/* Computed Parameter: BKINEtherCATPDOTransmit1_P1_Size_m
                                                * Referenced by: '<S255>/BKIN EtherCAT PDO Transmit 1'
                                                */
  real_T BKINEtherCATPDOTransmit1_P1_d[42];/* Computed Parameter: BKINEtherCATPDOTransmit1_P1_d
                                            * Referenced by: '<S255>/BKIN EtherCAT PDO Transmit 1'
                                            */
  real_T BKINEtherCATPDOTransmit1_P2_Size_g[2];/* Computed Parameter: BKINEtherCATPDOTransmit1_P2_Size_g
                                                * Referenced by: '<S255>/BKIN EtherCAT PDO Transmit 1'
                                                */
  real_T BKINEtherCATPDOTransmit1_P2_e;/* Expression: sig_offset
                                        * Referenced by: '<S255>/BKIN EtherCAT PDO Transmit 1'
                                        */
  real_T BKINEtherCATPDOTransmit1_P3_Size_e[2];/* Computed Parameter: BKINEtherCATPDOTransmit1_P3_Size_e
                                                * Referenced by: '<S255>/BKIN EtherCAT PDO Transmit 1'
                                                */
  real_T BKINEtherCATPDOTransmit1_P3_n;/* Expression: sig_type
                                        * Referenced by: '<S255>/BKIN EtherCAT PDO Transmit 1'
                                        */
  real_T BKINEtherCATPDOTransmit1_P4_Size_i[2];/* Computed Parameter: BKINEtherCATPDOTransmit1_P4_Size_i
                                                * Referenced by: '<S255>/BKIN EtherCAT PDO Transmit 1'
                                                */
  real_T BKINEtherCATPDOTransmit1_P4_f;/* Expression: type_size
                                        * Referenced by: '<S255>/BKIN EtherCAT PDO Transmit 1'
                                        */
  real_T BKINEtherCATPDOTransmit1_P5_Size_l[2];/* Computed Parameter: BKINEtherCATPDOTransmit1_P5_Size_l
                                                * Referenced by: '<S255>/BKIN EtherCAT PDO Transmit 1'
                                                */
  real_T BKINEtherCATPDOTransmit1_P5_e;/* Expression: sig_dim
                                        * Referenced by: '<S255>/BKIN EtherCAT PDO Transmit 1'
                                        */
  real_T BKINEtherCATPDOTransmit1_P6_Size_d[2];/* Computed Parameter: BKINEtherCATPDOTransmit1_P6_Size_d
                                                * Referenced by: '<S255>/BKIN EtherCAT PDO Transmit 1'
                                                */
  real_T BKINEtherCATPDOTransmit1_P6_jb;/* Expression: device_id
                                         * Referenced by: '<S255>/BKIN EtherCAT PDO Transmit 1'
                                         */
  real_T BKINEtherCATPDOTransmit1_P7_Size_a[2];/* Computed Parameter: BKINEtherCATPDOTransmit1_P7_Size_a
                                                * Referenced by: '<S255>/BKIN EtherCAT PDO Transmit 1'
                                                */
  real_T BKINEtherCATPDOTransmit1_P7_i;/* Expression: sample_time
                                        * Referenced by: '<S255>/BKIN EtherCAT PDO Transmit 1'
                                        */
  real_T BKINEtherCATPDOTransmit2_P1_Size_m[2];/* Computed Parameter: BKINEtherCATPDOTransmit2_P1_Size_m
                                                * Referenced by: '<S255>/BKIN EtherCAT PDO Transmit 2'
                                                */
  real_T BKINEtherCATPDOTransmit2_P1_d[42];/* Computed Parameter: BKINEtherCATPDOTransmit2_P1_d
                                            * Referenced by: '<S255>/BKIN EtherCAT PDO Transmit 2'
                                            */
  real_T BKINEtherCATPDOTransmit2_P2_Size_m[2];/* Computed Parameter: BKINEtherCATPDOTransmit2_P2_Size_m
                                                * Referenced by: '<S255>/BKIN EtherCAT PDO Transmit 2'
                                                */
  real_T BKINEtherCATPDOTransmit2_P2_m;/* Expression: sig_offset
                                        * Referenced by: '<S255>/BKIN EtherCAT PDO Transmit 2'
                                        */
  real_T BKINEtherCATPDOTransmit2_P3_Size_e[2];/* Computed Parameter: BKINEtherCATPDOTransmit2_P3_Size_e
                                                * Referenced by: '<S255>/BKIN EtherCAT PDO Transmit 2'
                                                */
  real_T BKINEtherCATPDOTransmit2_P3_a;/* Expression: sig_type
                                        * Referenced by: '<S255>/BKIN EtherCAT PDO Transmit 2'
                                        */
  real_T BKINEtherCATPDOTransmit2_P4_Size_e[2];/* Computed Parameter: BKINEtherCATPDOTransmit2_P4_Size_e
                                                * Referenced by: '<S255>/BKIN EtherCAT PDO Transmit 2'
                                                */
  real_T BKINEtherCATPDOTransmit2_P4_m;/* Expression: type_size
                                        * Referenced by: '<S255>/BKIN EtherCAT PDO Transmit 2'
                                        */
  real_T BKINEtherCATPDOTransmit2_P5_Size_o[2];/* Computed Parameter: BKINEtherCATPDOTransmit2_P5_Size_o
                                                * Referenced by: '<S255>/BKIN EtherCAT PDO Transmit 2'
                                                */
  real_T BKINEtherCATPDOTransmit2_P5_f;/* Expression: sig_dim
                                        * Referenced by: '<S255>/BKIN EtherCAT PDO Transmit 2'
                                        */
  real_T BKINEtherCATPDOTransmit2_P6_Size_g[2];/* Computed Parameter: BKINEtherCATPDOTransmit2_P6_Size_g
                                                * Referenced by: '<S255>/BKIN EtherCAT PDO Transmit 2'
                                                */
  real_T BKINEtherCATPDOTransmit2_P6_m;/* Expression: device_id
                                        * Referenced by: '<S255>/BKIN EtherCAT PDO Transmit 2'
                                        */
  real_T BKINEtherCATPDOTransmit2_P7_Size_j[2];/* Computed Parameter: BKINEtherCATPDOTransmit2_P7_Size_j
                                                * Referenced by: '<S255>/BKIN EtherCAT PDO Transmit 2'
                                                */
  real_T BKINEtherCATPDOTransmit2_P7_f;/* Expression: sample_time
                                        * Referenced by: '<S255>/BKIN EtherCAT PDO Transmit 2'
                                        */
  real_T BKINEtherCATPDOTransmit1_P1_Size_d[2];/* Computed Parameter: BKINEtherCATPDOTransmit1_P1_Size_d
                                                * Referenced by: '<S256>/BKIN EtherCAT PDO Transmit 1'
                                                */
  real_T BKINEtherCATPDOTransmit1_P1_h[42];/* Computed Parameter: BKINEtherCATPDOTransmit1_P1_h
                                            * Referenced by: '<S256>/BKIN EtherCAT PDO Transmit 1'
                                            */
  real_T BKINEtherCATPDOTransmit1_P2_Size_o[2];/* Computed Parameter: BKINEtherCATPDOTransmit1_P2_Size_o
                                                * Referenced by: '<S256>/BKIN EtherCAT PDO Transmit 1'
                                                */
  real_T BKINEtherCATPDOTransmit1_P2_k;/* Expression: sig_offset
                                        * Referenced by: '<S256>/BKIN EtherCAT PDO Transmit 1'
                                        */
  real_T BKINEtherCATPDOTransmit1_P3_Size_f[2];/* Computed Parameter: BKINEtherCATPDOTransmit1_P3_Size_f
                                                * Referenced by: '<S256>/BKIN EtherCAT PDO Transmit 1'
                                                */
  real_T BKINEtherCATPDOTransmit1_P3_p;/* Expression: sig_type
                                        * Referenced by: '<S256>/BKIN EtherCAT PDO Transmit 1'
                                        */
  real_T BKINEtherCATPDOTransmit1_P4_Size_d[2];/* Computed Parameter: BKINEtherCATPDOTransmit1_P4_Size_d
                                                * Referenced by: '<S256>/BKIN EtherCAT PDO Transmit 1'
                                                */
  real_T BKINEtherCATPDOTransmit1_P4_k;/* Expression: type_size
                                        * Referenced by: '<S256>/BKIN EtherCAT PDO Transmit 1'
                                        */
  real_T BKINEtherCATPDOTransmit1_P5_Size_io[2];/* Computed Parameter: BKINEtherCATPDOTransmit1_P5_Size_io
                                                 * Referenced by: '<S256>/BKIN EtherCAT PDO Transmit 1'
                                                 */
  real_T BKINEtherCATPDOTransmit1_P5_g;/* Expression: sig_dim
                                        * Referenced by: '<S256>/BKIN EtherCAT PDO Transmit 1'
                                        */
  real_T BKINEtherCATPDOTransmit1_P6_Size_ht[2];/* Computed Parameter: BKINEtherCATPDOTransmit1_P6_Size_ht
                                                 * Referenced by: '<S256>/BKIN EtherCAT PDO Transmit 1'
                                                 */
  real_T BKINEtherCATPDOTransmit1_P6_jg;/* Expression: device_id
                                         * Referenced by: '<S256>/BKIN EtherCAT PDO Transmit 1'
                                         */
  real_T BKINEtherCATPDOTransmit1_P7_Size_d[2];/* Computed Parameter: BKINEtherCATPDOTransmit1_P7_Size_d
                                                * Referenced by: '<S256>/BKIN EtherCAT PDO Transmit 1'
                                                */
  real_T BKINEtherCATPDOTransmit1_P7_m;/* Expression: sample_time
                                        * Referenced by: '<S256>/BKIN EtherCAT PDO Transmit 1'
                                        */
  real_T BKINEtherCATPDOTransmit2_P1_Size_f[2];/* Computed Parameter: BKINEtherCATPDOTransmit2_P1_Size_f
                                                * Referenced by: '<S256>/BKIN EtherCAT PDO Transmit 2'
                                                */
  real_T BKINEtherCATPDOTransmit2_P1_p[42];/* Computed Parameter: BKINEtherCATPDOTransmit2_P1_p
                                            * Referenced by: '<S256>/BKIN EtherCAT PDO Transmit 2'
                                            */
  real_T BKINEtherCATPDOTransmit2_P2_Size_j[2];/* Computed Parameter: BKINEtherCATPDOTransmit2_P2_Size_j
                                                * Referenced by: '<S256>/BKIN EtherCAT PDO Transmit 2'
                                                */
  real_T BKINEtherCATPDOTransmit2_P2_j;/* Expression: sig_offset
                                        * Referenced by: '<S256>/BKIN EtherCAT PDO Transmit 2'
                                        */
  real_T BKINEtherCATPDOTransmit2_P3_Size_p[2];/* Computed Parameter: BKINEtherCATPDOTransmit2_P3_Size_p
                                                * Referenced by: '<S256>/BKIN EtherCAT PDO Transmit 2'
                                                */
  real_T BKINEtherCATPDOTransmit2_P3_f;/* Expression: sig_type
                                        * Referenced by: '<S256>/BKIN EtherCAT PDO Transmit 2'
                                        */
  real_T BKINEtherCATPDOTransmit2_P4_Size_p[2];/* Computed Parameter: BKINEtherCATPDOTransmit2_P4_Size_p
                                                * Referenced by: '<S256>/BKIN EtherCAT PDO Transmit 2'
                                                */
  real_T BKINEtherCATPDOTransmit2_P4_j;/* Expression: type_size
                                        * Referenced by: '<S256>/BKIN EtherCAT PDO Transmit 2'
                                        */
  real_T BKINEtherCATPDOTransmit2_P5_Size_h[2];/* Computed Parameter: BKINEtherCATPDOTransmit2_P5_Size_h
                                                * Referenced by: '<S256>/BKIN EtherCAT PDO Transmit 2'
                                                */
  real_T BKINEtherCATPDOTransmit2_P5_m;/* Expression: sig_dim
                                        * Referenced by: '<S256>/BKIN EtherCAT PDO Transmit 2'
                                        */
  real_T BKINEtherCATPDOTransmit2_P6_Size_a[2];/* Computed Parameter: BKINEtherCATPDOTransmit2_P6_Size_a
                                                * Referenced by: '<S256>/BKIN EtherCAT PDO Transmit 2'
                                                */
  real_T BKINEtherCATPDOTransmit2_P6_h;/* Expression: device_id
                                        * Referenced by: '<S256>/BKIN EtherCAT PDO Transmit 2'
                                        */
  real_T BKINEtherCATPDOTransmit2_P7_Size_o[2];/* Computed Parameter: BKINEtherCATPDOTransmit2_P7_Size_o
                                                * Referenced by: '<S256>/BKIN EtherCAT PDO Transmit 2'
                                                */
  real_T BKINEtherCATPDOTransmit2_P7_a;/* Expression: sample_time
                                        * Referenced by: '<S256>/BKIN EtherCAT PDO Transmit 2'
                                        */
  real_T indices_padding_Value[8];     /* Expression: indices_padding
                                        * Referenced by: '<S267>/indices_padding'
                                        */
  real_T Target_Type_Value;            /* Expression: Target_Type
                                        * Referenced by: '<S267>/Target_Type'
                                        */
  real_T Hold_to_1Khz_BKIN_STEP_TIME;  /* Expression: BKIN_STEP_TIME
                                        * Referenced by: '<S268>/Hold_to_1Khz'
                                        */
  real_T Delay1_X0;                    /* Expression: 0
                                        * Referenced by: '<S269>/Delay1'
                                        */
  real_T Constant_Value_o1;            /* Expression: 1
                                        * Referenced by: '<S269>/Constant'
                                        */
  real_T TaskClock_Amp_m;              /* Expression: 1
                                        * Referenced by: '<S269>/Task Clock'
                                        */
  real_T TaskClock_Period_n;           /* Computed Parameter: TaskClock_Period_n
                                        * Referenced by: '<S269>/Task Clock'
                                        */
  real_T TaskClock_Duty_e;             /* Computed Parameter: TaskClock_Duty_e
                                        * Referenced by: '<S269>/Task Clock'
                                        */
  real_T TaskClock_PhaseDelay_b;       /* Expression: 0
                                        * Referenced by: '<S269>/Task Clock'
                                        */
  real_T RateTransition1_X0;           /* Expression: 0
                                        * Referenced by: '<S298>/Rate Transition1'
                                        */
  real_T BlockDefinitions_Value[25000];/* Expression: zeros(50, 500);
                                        * Referenced by: '<S7>/Block Definitions'
                                        */
  real_T BlockSequence_Value[2000];    /* Expression: zeros(1000, 2);
                                        * Referenced by: '<S7>/Block Sequence'
                                        */
  real_T Constant_Value_h;             /* Expression: 1
                                        * Referenced by: '<S7>/Constant'
                                        */
  real_T UseRepeatTrialFlag_Value;     /* Expression: 0
                                        * Referenced by: '<S7>/Use Repeat Trial Flag'
                                        */
  real_T RunCommandReceive_P1_Size[2]; /* Computed Parameter: RunCommandReceive_P1_Size
                                        * Referenced by: '<S268>/Run Command Receive'
                                        */
  real_T RunCommandReceive_P1[7];      /* Computed Parameter: RunCommandReceive_P1
                                        * Referenced by: '<S268>/Run Command Receive'
                                        */
  real_T RunCommandReceive_P2_Size[2]; /* Computed Parameter: RunCommandReceive_P2_Size
                                        * Referenced by: '<S268>/Run Command Receive'
                                        */
  real_T RunCommandReceive_P2;         /* Expression: ipPort
                                        * Referenced by: '<S268>/Run Command Receive'
                                        */
  real_T RunCommandReceive_P3_Size[2]; /* Computed Parameter: RunCommandReceive_P3_Size
                                        * Referenced by: '<S268>/Run Command Receive'
                                        */
  real_T RunCommandReceive_P3;         /* Expression: width
                                        * Referenced by: '<S268>/Run Command Receive'
                                        */
  real_T RunCommandReceive_P4_Size[2]; /* Computed Parameter: RunCommandReceive_P4_Size
                                        * Referenced by: '<S268>/Run Command Receive'
                                        */
  real_T RunCommandReceive_P4;         /* Expression: sampletime
                                        * Referenced by: '<S268>/Run Command Receive'
                                        */
  real_T RunCommandReceive_P5_Size[2]; /* Computed Parameter: RunCommandReceive_P5_Size
                                        * Referenced by: '<S268>/Run Command Receive'
                                        */
  real_T RunCommandReceive_P5;         /* Expression: vblLen
                                        * Referenced by: '<S268>/Run Command Receive'
                                        */
  real_T PauseType_Value;              /* Expression: 0
                                        * Referenced by: '<S7>/Pause Type'
                                        */
  real_T Seed_Value;                   /* Expression: 0
                                        * Referenced by: '<S7>/Seed'
                                        */
  real_T UseTaskProtocolBlockSequenceFlag_Value;/* Expression: 1
                                                 * Referenced by: '<S7>/Use Task Protocol Block Sequence Flag'
                                                 */
  real_T NextBlock_Value;              /* Expression: 0
                                        * Referenced by: '<S7>/Next Block'
                                        */
  real_T RunTaskClockFlag_Value;       /* Expression: 1
                                        * Referenced by: '<S7>/Run Task Clock Flag'
                                        */
  real_T TPTable_Value[2500];          /* Expression: zeros(tp_table_rows, 50);
                                        * Referenced by: '<S7>/TP Table'
                                        */
  real_T TargetLabels_Value[5000];     /* Expression: zeros(100, 50);
                                        * Referenced by: '<S7>/Target Labels'
                                        */
  real_T DisplaySizepels_Value[2];     /* Expression: [0, 0]
                                        * Referenced by: '<S7>/Display Size (pels)'
                                        */
  real_T DockingPoints_Value[10];      /* Expression: zeros(5, 2);
                                        * Referenced by: '<S7>/Docking Points'
                                        */
  real_T ELCameraFocalLength_Value_b;  /* Expression: 0
                                        * Referenced by: '<S7>/EL Camera Focal Length'
                                        */
  real_T ELCameraPosition_Value_k[3];  /* Expression: [0, 0, 0]
                                        * Referenced by: '<S7>/EL Camera Position'
                                        */
  real_T ELCameraAngle_Value_h[2];     /* Expression: [0, 0]
                                        * Referenced by: '<S7>/EL Camera Angle'
                                        */
  real_T ELTrackingAvailable_Value_a;  /* Expression: 0
                                        * Referenced by: '<S7>/EL Tracking Available'
                                        */
  real_T SubjectHeight_Value;          /* Expression: 0
                                        * Referenced by: '<S7>/Subject Height'
                                        */
  real_T SubjectWeight_Value;          /* Expression: 0
                                        * Referenced by: '<S7>/Subject Weight'
                                        */
  real_T DisplaySizem_Value[2];        /* Expression: [0.0, 0.0]
                                        * Referenced by: '<S7>/Display Size (m)'
                                        */
  real_T TargetTable_Value[800];       /* Expression: zeros(target_table_rows, 25);
                                        * Referenced by: '<S7>/Target Table'
                                        */
  real_T LoadTable_Value[200];         /* Expression: zeros(load_table_rows, 20);
                                        * Referenced by: '<S7>/Load Table'
                                        */
  real_T Taskwideparam_Value[50];      /* Expression: zeros(50, 1);
                                        * Referenced by: '<S7>/Task wide param'
                                        */
  real_T frame_of_reference_center_Value[2];/* Expression: [0, 0]
                                             * Referenced by: '<S7>/frame_of_reference_center'
                                             */
  real_T LibraryPatchVersion_Value;    /* Expression: 0
                                        * Referenced by: '<S7>/Library Patch Version'
                                        */
  real_T LibraryVersion_Value;         /* Expression: 3.7
                                        * Referenced by: '<S7>/Library Version'
                                        */
  real_T TaskVersion_Value;            /* Expression: 1
                                        * Referenced by: '<S7>/Task Version'
                                        */
  real_T xPCVersion_Value;             /* Expression: 6.2
                                        * Referenced by: '<S7>/xPC Version'
                                        */
  real_T dlmbuildtime_Value;           /* Expression: 738049.62619925931
                                        * Referenced by: '<S7>/dlm build time'
                                        */
  real_T packet_version_Value;         /* Expression: -1
                                        * Referenced by: '<S30>/packet_version'
                                        */
  real_T Memory_X0_gv;                 /* Expression: 0
                                        * Referenced by: '<S4>/Memory'
                                        */
  real_T ZeroDigOut_Value[4];          /* Expression: [0 0 0 0]
                                        * Referenced by: '<S4>/ZeroDigOut'
                                        */
  real_T Memory_X0_c;                  /* Expression: 0
                                        * Referenced by: '<S15>/Memory'
                                        */
  real_T Gain_Gain_a;                  /* Expression: 0.001
                                        * Referenced by: '<S15>/Gain'
                                        */
  real_T attribcol2_Value;             /* Expression: attribcol2
                                        * Referenced by: '<S11>/attribcol2'
                                        */
  real_T attribcol3_Value;             /* Expression: attribcol3
                                        * Referenced by: '<S11>/attribcol3'
                                        */
  real_T attribcol4_Value;             /* Expression: attribcol4
                                        * Referenced by: '<S11>/attribcol4'
                                        */
  real_T attribcol5_Value;             /* Expression: attribcol5
                                        * Referenced by: '<S11>/attribcol5'
                                        */
  real_T SelectedStates_Value;         /* Expression: [1]
                                        * Referenced by: '<S11>/Selected States'
                                        */
  real_T Switch1_Threshold_e;          /* Expression: 1.5
                                        * Referenced by: '<Root>/Switch1'
                                        */
  real_T Switch_Threshold_f;           /* Expression: 1.5
                                        * Referenced by: '<Root>/Switch'
                                        */
  real_T attribcol2_Value_k[3];        /* Expression: attribcol2
                                        * Referenced by: '<S10>/attribcol2'
                                        */
  real_T attribcol3_Value_e[3];        /* Expression: attribcol3
                                        * Referenced by: '<S10>/attribcol3'
                                        */
  real_T attribcol4_Value_l[3];        /* Expression: attribcol4
                                        * Referenced by: '<S10>/attribcol4'
                                        */
  real_T attribcol5_Value_j[3];        /* Expression: attribcol5
                                        * Referenced by: '<S10>/attribcol5'
                                        */
  real_T SelectedStates_Value_j;       /* Expression: [1]
                                        * Referenced by: '<S10>/Selected States'
                                        */
  real_T xpos_index_Value;             /* Expression: 1
                                        * Referenced by: '<S24>/xpos_index'
                                        */
  real_T ypos_index_Value;             /* Expression: 2
                                        * Referenced by: '<S24>/ypos_index'
                                        */
  real_T state3_indices_Value[4];      /* Expression: attribcol3
                                        * Referenced by: '<S24>/state3_indices'
                                        */
  real_T state4_indices_Value[4];      /* Expression: attribcol4
                                        * Referenced by: '<S24>/state4_indices'
                                        */
  real_T state5_indices_Value[4];      /* Expression: attribcol5
                                        * Referenced by: '<S24>/state5_indices'
                                        */
  real_T padder_Value[35];             /* Expression: stateindices_padding
                                        * Referenced by: '<S24>/padder'
                                        */
  real_T xpos_index_Value_d;           /* Expression: 1
                                        * Referenced by: '<S22>/xpos_index'
                                        */
  real_T ypos_index_Value_b;           /* Expression: 2
                                        * Referenced by: '<S22>/ypos_index'
                                        */
  real_T state4_indices_Value_d[7];    /* Expression: attribcol4
                                        * Referenced by: '<S22>/state4_indices'
                                        */
  real_T state5_indices_Value_i[7];    /* Expression: attribcol5
                                        * Referenced by: '<S22>/state5_indices'
                                        */
  real_T padder_Value_b[20];           /* Expression: stateindices_padding
                                        * Referenced by: '<S22>/padder'
                                        */
  real_T Assess_arm_VCODE_Value[70];   /* Expression: [1:70]
                                        * Referenced by: '<S8>/Assess_arm_VCODE'
                                        */
  real_T Contralateral_arm_VCODE_Value[70];/* Expression: [71:140]
                                            * Referenced by: '<S8>/Contralateral_arm_VCODE'
                                            */
  real_T feedback_status_Value;        /* Expression: 1
                                        * Referenced by: '<S8>/feedback_status'
                                        */
  real_T xpos_index_Value_l;           /* Expression: 1
                                        * Referenced by: '<S265>/xpos_index'
                                        */
  real_T ypos_index_Value_d;           /* Expression: 2
                                        * Referenced by: '<S265>/ypos_index'
                                        */
  real_T state2_indices_Value[9];      /* Expression: attribcol2
                                        * Referenced by: '<S265>/state2_indices'
                                        */
  real_T state3_indices_Value_o[9];    /* Expression: attribcol3
                                        * Referenced by: '<S265>/state3_indices'
                                        */
  real_T state4_indices_Value_p[9];    /* Expression: attribcol4
                                        * Referenced by: '<S265>/state4_indices'
                                        */
  real_T state5_indices_Value_l[9];    /* Expression: attribcol5
                                        * Referenced by: '<S265>/state5_indices'
                                        */
  real_T padder_Value_l[10];           /* Expression: stateindices_padding
                                        * Referenced by: '<S265>/padder'
                                        */
  real_T Switch_Threshold_d;           /* Expression: 1.5
                                        * Referenced by: '<S6>/Switch'
                                        */
  real_T Constant_Value_a;             /* Expression: 25
                                        * Referenced by: '<S5>/Constant'
                                        */
  real_T xpos_index_Value_e;           /* Expression: 1
                                        * Referenced by: '<S262>/xpos_index'
                                        */
  real_T ypos_index_Value_bm;          /* Expression: 2
                                        * Referenced by: '<S262>/ypos_index'
                                        */
  real_T state2_indices_Value_j[6];    /* Expression: attribcol2
                                        * Referenced by: '<S262>/state2_indices'
                                        */
  real_T state3_indices_Value_og[6];   /* Expression: attribcol3
                                        * Referenced by: '<S262>/state3_indices'
                                        */
  real_T state4_indices_Value_g[6];    /* Expression: attribcol4
                                        * Referenced by: '<S262>/state4_indices'
                                        */
  real_T state5_indices_Value_im[6];   /* Expression: attribcol5
                                        * Referenced by: '<S262>/state5_indices'
                                        */
  real_T padder_Value_j[25];           /* Expression: stateindices_padding
                                        * Referenced by: '<S262>/padder'
                                        */
  real_T xpos_index_Value_g;           /* Expression: 1
                                        * Referenced by: '<S23>/xpos_index'
                                        */
  real_T ypos_index_Value_f;           /* Expression: 2
                                        * Referenced by: '<S23>/ypos_index'
                                        */
  real_T state4_indices_Value_a[7];    /* Expression: attribcol4
                                        * Referenced by: '<S23>/state4_indices'
                                        */
  real_T state5_indices_Value_j[7];    /* Expression: attribcol5
                                        * Referenced by: '<S23>/state5_indices'
                                        */
  real_T padder_Value_a[20];           /* Expression: stateindices_padding
                                        * Referenced by: '<S23>/padder'
                                        */
  real_T xpos_index_Value_f;           /* Expression: 1
                                        * Referenced by: '<S21>/xpos_index'
                                        */
  real_T ypos_index_Value_l;           /* Expression: 2
                                        * Referenced by: '<S21>/ypos_index'
                                        */
  real_T state3_indices_Value_p[6];    /* Expression: attribcol3
                                        * Referenced by: '<S21>/state3_indices'
                                        */
  real_T state4_indices_Value_o[6];    /* Expression: attribcol4
                                        * Referenced by: '<S21>/state4_indices'
                                        */
  real_T state5_indices_Value_d[6];    /* Expression: attribcol5
                                        * Referenced by: '<S21>/state5_indices'
                                        */
  real_T padder_Value_k[25];           /* Expression: stateindices_padding
                                        * Referenced by: '<S21>/padder'
                                        */
  real_T GUI_VCODE_Value[630];         /* Expression: zeros(70, 9);
                                        * Referenced by: '<S15>/GUI_VCODE'
                                        */
  real_T Receive_P1_Size_g[2];         /* Computed Parameter: Receive_P1_Size_g
                                        * Referenced by: '<S15>/Receive'
                                        */
  real_T Receive_P1_n[11];             /* Computed Parameter: Receive_P1_n
                                        * Referenced by: '<S15>/Receive'
                                        */
  real_T Receive_P2_Size_m[2];         /* Computed Parameter: Receive_P2_Size_m
                                        * Referenced by: '<S15>/Receive'
                                        */
  real_T Receive_P2_n;                 /* Expression: ipPort
                                        * Referenced by: '<S15>/Receive'
                                        */
  real_T Receive_P3_Size_f[2];         /* Computed Parameter: Receive_P3_Size_f
                                        * Referenced by: '<S15>/Receive'
                                        */
  real_T Receive_P3_a;                 /* Expression: width
                                        * Referenced by: '<S15>/Receive'
                                        */
  real_T Receive_P4_Size_d[2];         /* Computed Parameter: Receive_P4_Size_d
                                        * Referenced by: '<S15>/Receive'
                                        */
  real_T Receive_P4_l;                 /* Expression: sampletime
                                        * Referenced by: '<S15>/Receive'
                                        */
  real_T Receive_P5_Size_h[2];         /* Computed Parameter: Receive_P5_Size_h
                                        * Referenced by: '<S15>/Receive'
                                        */
  real_T Receive_P5_g;                 /* Expression: vblLen
                                        * Referenced by: '<S15>/Receive'
                                        */
  real_T TmpRTBAtNumberofEventCodesOutport1_X0;/* Expression: 0
                                                * Referenced by: synthesized block
                                                */
  real_T NotLoggingAnalogInputs_Value; /* Expression: 0
                                        * Referenced by: '<S26>/Not Logging Analog Inputs'
                                        */
  real_T custom_version_Value;         /* Expression: 7
                                        * Referenced by: '<S27>/custom_version'
                                        */
  real_T seconds_remaining_Value;      /* Expression: -1
                                        * Referenced by: '<S4>/seconds_remaining'
                                        */
  real_T RateTransition2_X0_o;         /* Expression: 0
                                        * Referenced by: '<S27>/Rate Transition2'
                                        */
  real_T NotLoggingEventCodes_Value;   /* Expression: 0
                                        * Referenced by: '<S28>/Not Logging Event Codes'
                                        */
  real_T ZeroTorque_Value[4];          /* Expression: [0 0 0 0]
                                        * Referenced by: '<S4>/ZeroTorque'
                                        */
  real_T ZeroEPTorque_Value[4];        /* Expression: [0 0 0 0]
                                        * Referenced by: '<S4>/ZeroEPTorque'
                                        */
  real_T Memory1_X0_b;                 /* Expression: 0
                                        * Referenced by: '<S4>/Memory1'
                                        */
  real_T Memory2_1_X0;                 /* Expression: 0
                                        * Referenced by: '<S4>/Memory2'
                                        */
  real_T Memory2_2_X0;                 /* Expression: 0
                                        * Referenced by: '<S4>/Memory2'
                                        */
  real_T Memory2_3_X0;                 /* Expression: 0
                                        * Referenced by: '<S4>/Memory2'
                                        */
  real_T Memory2_4_X0;                 /* Expression: 0
                                        * Referenced by: '<S4>/Memory2'
                                        */
  real_T Memory2_5_X0;                 /* Expression: 0
                                        * Referenced by: '<S4>/Memory2'
                                        */
  real_T Memory2_9_X0;                 /* Expression: 0
                                        * Referenced by: '<S4>/Memory2'
                                        */
  real_T Memory2_18_X0;                /* Expression: 0
                                        * Referenced by: '<S4>/Memory2'
                                        */
  real_T Memory2_19_X0;                /* Expression: 0
                                        * Referenced by: '<S4>/Memory2'
                                        */
  real_T Memory2_20_X0;                /* Expression: 0
                                        * Referenced by: '<S4>/Memory2'
                                        */
  real_T Memory2_21_X0;                /* Expression: 0
                                        * Referenced by: '<S4>/Memory2'
                                        */
  real_T Memory2_22_X0;                /* Expression: 0
                                        * Referenced by: '<S4>/Memory2'
                                        */
  real_T Memory2_26_X0;                /* Expression: 0
                                        * Referenced by: '<S4>/Memory2'
                                        */
  real_T Memory2_10_X0;                /* Expression: 0
                                        * Referenced by: '<S4>/Memory2'
                                        */
  real_T Memory2_11_X0;                /* Expression: 0
                                        * Referenced by: '<S4>/Memory2'
                                        */
  real_T Memory2_12_X0;                /* Expression: 0
                                        * Referenced by: '<S4>/Memory2'
                                        */
  real_T Memory2_13_X0;                /* Expression: 0
                                        * Referenced by: '<S4>/Memory2'
                                        */
  real_T Memory2_14_X0;                /* Expression: 0
                                        * Referenced by: '<S4>/Memory2'
                                        */
  real_T Memory2_15_X0;                /* Expression: 0
                                        * Referenced by: '<S4>/Memory2'
                                        */
  real_T Memory2_16_X0;                /* Expression: 0
                                        * Referenced by: '<S4>/Memory2'
                                        */
  real_T Memory2_17_X0;                /* Expression: 0
                                        * Referenced by: '<S4>/Memory2'
                                        */
  real_T Memory2_23_X0;                /* Expression: 0
                                        * Referenced by: '<S4>/Memory2'
                                        */
  real_T Memory2_24_X0;                /* Expression: 0
                                        * Referenced by: '<S4>/Memory2'
                                        */
  real_T Memory2_25_X0;                /* Expression: 0
                                        * Referenced by: '<S4>/Memory2'
                                        */
  real_T Memory2_27_X0;                /* Expression: 0
                                        * Referenced by: '<S4>/Memory2'
                                        */
  real_T Memory2_28_X0;                /* Expression: 0
                                        * Referenced by: '<S4>/Memory2'
                                        */
  real_T Memory2_29_X0;                /* Expression: 0
                                        * Referenced by: '<S4>/Memory2'
                                        */
  real_T Memory2_30_X0;                /* Expression: 0
                                        * Referenced by: '<S4>/Memory2'
                                        */
  real_T Memory2_31_X0;                /* Expression: 0
                                        * Referenced by: '<S4>/Memory2'
                                        */
  real_T Memory2_32_X0;                /* Expression: 0
                                        * Referenced by: '<S4>/Memory2'
                                        */
  real_T Memory2_33_X0;                /* Expression: 0
                                        * Referenced by: '<S4>/Memory2'
                                        */
  real_T Memory2_34_X0;                /* Expression: 0
                                        * Referenced by: '<S4>/Memory2'
                                        */
  real_T Memory2_6_X0;                 /* Expression: 0
                                        * Referenced by: '<S4>/Memory2'
                                        */
  real_T Memory2_7_X0;                 /* Expression: 0
                                        * Referenced by: '<S4>/Memory2'
                                        */
  real_T Memory2_8_X0;                 /* Expression: 0
                                        * Referenced by: '<S4>/Memory2'
                                        */
  real_T arm_count_Value;              /* Expression: 0
                                        * Referenced by: '<S39>/arm_count'
                                        */
  real_T fp1_present_Value;            /* Expression: 0
                                        * Referenced by: '<S39>/fp1_present'
                                        */
  real_T fp2_present_Value;            /* Expression: 0
                                        * Referenced by: '<S39>/fp2_present'
                                        */
  real_T gaze_tracker_present_Value;   /* Expression: 0
                                        * Referenced by: '<S39>/gaze_tracker_present'
                                        */
  real_T robot_lift_present_Value;     /* Expression: 0
                                        * Referenced by: '<S39>/robot_lift_present'
                                        */
  real_T ECATStatus_InitialValue[8];   /* Expression: zeros(1,8)
                                        * Referenced by: '<S4>/ECAT Status'
                                        */
  real_T ECAThardware_InitialValue[14];/* Expression: zeros(1,14)
                                        * Referenced by: '<S4>/ECAT hardware'
                                        */
  real_T u0hz_Value;                   /* Expression: 2
                                        * Referenced by: '<S296>/500 hz'
                                        */
  real_T Send_P1_Size_k[2];            /* Computed Parameter: Send_P1_Size_k
                                        * Referenced by: '<S15>/Send'
                                        */
  real_T Send_P1_n[11];                /* Computed Parameter: Send_P1_n
                                        * Referenced by: '<S15>/Send'
                                        */
  real_T Send_P2_Size_mp[2];           /* Computed Parameter: Send_P2_Size_mp
                                        * Referenced by: '<S15>/Send'
                                        */
  real_T Send_P2_d;                    /* Expression: ipPort
                                        * Referenced by: '<S15>/Send'
                                        */
  real_T Send_P3_Size_dr[2];           /* Computed Parameter: Send_P3_Size_dr
                                        * Referenced by: '<S15>/Send'
                                        */
  real_T Send_P3_n;                    /* Expression: localPort
                                        * Referenced by: '<S15>/Send'
                                        */
  real_T Send_P4_Size_o[2];            /* Computed Parameter: Send_P4_Size_o
                                        * Referenced by: '<S15>/Send'
                                        */
  real_T Send_P4_l;                    /* Expression: sampletime
                                        * Referenced by: '<S15>/Send'
                                        */
  real_T Send_P5_Size_n[2];            /* Computed Parameter: Send_P5_Size_n
                                        * Referenced by: '<S15>/Send'
                                        */
  real_T Send_P5_l;                    /* Expression: vblLen
                                        * Referenced by: '<S15>/Send'
                                        */
  real_T B1TargetB1rowfloatB1rowintargettablenone_Value;/* Expression: 10
                                                         * Referenced by: '<S285>/B1;Target B1 row;float;B1 row in target table;;;none;;'
                                                         */
  real_T B2TargetB2rowfloatB2rowintargettablenone_Value;/* Expression: 11
                                                         * Referenced by: '<S285>/B2;Target B2 row;float;B2 row in target table;;;none;;'
                                                         */
  real_T CORR_TGTWhichtargetiscorrectfloatWhichtargetiscorrect1or2none_V;/* Expression: 2
                                                                      * Referenced by: '<S285>/CORR_TGT;Which target is correct;float;Which target is correct (1 or 2) ?;;;none;;'
                                                                      */
  real_T DELAY_POST_TRIALTrialEndDelayintegerTimetowaitattheendofthetria;/* Expression: 8
                                                                      * Referenced by: '<S285>/DELAY_POST_TRIAL;Trial-End Delay;integer;Time to wait at the end of the trial;;;none;;'
                                                                      */
  real_T DISPLAY_TRIAL_COLFlagDisplayintegerDisplayandpausenone_Value;/* Expression: 9
                                                                      * Referenced by: '<S285>/DISPLAY_TRIAL_COL;Flag Display;integer;Display and pause;;;none;;'
                                                                      */
  real_T INCORR_TGTWhichtargetisincorrectfloatWhichtargetisincorrect1or2;/* Expression: 3
                                                                      * Referenced by: '<S285>/INCORR_TGT;Which target is incorrect;float;Which target is incorrect (1 or 2) ?;;;none;;'
                                                                      */
  real_T MAX_REACH_TIME_COLMaximumReachTimeintegerMaximumreachdurational;/* Expression: 7
                                                                      * Referenced by: '<S285>/MAX_REACH_TIME_COL;Maximum Reach Time;integer;Maximum reach duration allowed;;;none;;'
                                                                      */
  real_T RWD_TARGETC1_COLTarget1ValuefloatRewardofferedonTargetC1none_Va;/* Expression: 4
                                                                      * Referenced by: '<S285>/RWD_TARGETC1_COL;Target1 Value;float;Reward offered on Target C1;;;none;;'
                                                                      */
  real_T RWD_TARGETC2_COLTarget2ValuefloatRewardofferedonTargetC2none_Va;/* Expression: 5
                                                                      * Referenced by: '<S285>/RWD_TARGETC2_COL;Target2 Value;float;Reward offered on Target C2;;;none;;'
                                                                      */
  real_T START_TARGET_COLStarttargettargetFirsttargettoappearduringatria;/* Expression: 1
                                                                      * Referenced by: '<S285>/START_TARGET_COL;Start target;target;First target to appear during a trial;;;none;;'
                                                                      */
  real_T TGT_C_RWD_FRACRewardratiobetweenrowCrowBfloatHowmuchmorewilltar;/* Expression: 6
                                                                      * Referenced by: '<S285>/TGT_C_RWD_FRAC;Reward ratio between rowC:rowB;float;How much more will targets B be worth?;;;none;;'
                                                                      */
  real_T INSTRUCT_PAUSE_BTNInstructionResumeButtontocontinuetaskafterdis;/* Expression: 2
                                                                      * Referenced by: '<S286>/INSTRUCT_PAUSE_BTN;Instruction-Resume;;Button to continue task after displaying instructions;25;22;none;;'
                                                                      */
  real_T E_BOX_TRIGGERBoxWasTriggeredBoxtriggreredsosubjectchoserowCnone;/* Expression: 22
                                                                      * Referenced by: '<S287>/E_BOX_TRIGGER;Box Was Triggered;;Box triggrered so subject chose row C;;;none;;'
                                                                      */
  real_T E_CHOSE_ROW_BChoseRowBSubjectchoserowBnone_Value;/* Expression: 21
                                                           * Referenced by: '<S287>/E_CHOSE_ROW_B;Chose Row B;;Subject chose row B ;;;none;;'
                                                           */
  real_T E_HIT_TARGETBHitTargetBHittargetBnone_Value;/* Expression: 23
                                                      * Referenced by: '<S287>/E_HIT_TARGETB;Hit Target B;;Hit target B;;;none;;'
                                                      */
  real_T E_HIT_TARGETCHitTargetCHitTargetCnone_Value;/* Expression: 25
                                                      * Referenced by: '<S287>/E_HIT_TARGETC;Hit Target C;;Hit Target C;;;none;;'
                                                      */
  real_T E_MISS_TARGETBMissTargretBMissTargretBnone_Value;/* Expression: 24
                                                           * Referenced by: '<S287>/E_MISS_TARGETB;Miss Targret B;;Miss Targret B;;;none;;'
                                                           */
  real_T E_MISS_TARGETCMissTargetCMissTargetCnone_Value;/* Expression: 26
                                                         * Referenced by: '<S287>/E_MISS_TARGETC;Miss Target C;;Miss Target C;;;none;;'
                                                         */
  real_T E_NEW_TRIALNewTrialStartNewTrialstartsnone_Value;/* Expression: 1
                                                           * Referenced by: '<S287>/E_NEW_TRIAL;New Trial Start;;New Trial starts;;;none;;'
                                                           */
  real_T E_NO_EVENTnaThisevent_codedoesnotsaveaneventinthedatafileitjust;/* Expression: 0
                                                                      * Referenced by: '<S287>/E_NO_EVENT;n|a;;This event_code does not save an event in the data file, it just clears the event;;;none;;'
                                                                      */
  real_T E_SHOW_INSTRUCTInstructionstateShowinginstructionsnone_Value;/* Expression: 13
                                                                      * Referenced by: '<S287>/E_SHOW_INSTRUCT;Instruction state;;Showing instructions;;;none;;'
                                                                      */
  real_T E_SHOW_SCOREShowScoreShowingscorenone_Value;/* Expression: 14
                                                      * Referenced by: '<S287>/E_SHOW_SCORE;Show Score;;Showing score;;;none;;'
                                                      */
  real_T E_STAY_STARTAtStartSubjectreachedstarttargetnone_Value;/* Expression: 2
                                                                 * Referenced by: '<S287>/E_STAY_START;At Start;;Subject reached start target;;;none;;'
                                                                 */
  real_T E_TARGETS_ONTargetsOnPotentialReachtargetsonnone_Value;/* Expression: 3
                                                                 * Referenced by: '<S287>/E_TARGETS_ON;Targets On;;Potential Reach targets on;;;none;;'
                                                                 */
  real_T E_TOO_SLOWTooSlowMovementistooslowerror_Value;/* Expression: 20
                                                        * Referenced by: '<S287>/E_TOO_SLOW;Too Slow;;Movement is too slow;;;error;;'
                                                        */
  real_T BOX_HEIGHTHeightofBoxfloatHeightofBoxnone_Value;/* Expression: 13
                                                          * Referenced by: '<S288>/BOX_HEIGHT;Height of Box;float;Height of Box;;;none;;'
                                                          */
  real_T HIT_COLORReachedcolorcolourColorwhenthetargetistouchednone_Valu;/* Expression: 6
                                                                      * Referenced by: '<S288>/HIT_COLOR;Reached color;colour;Color when the target is touched;;;none;;'
                                                                      */
  real_T INIT_COLORInitialcolorcolourInitialtargetcolornone_Value;/* Expression: 5
                                                                   * Referenced by: '<S288>/INIT_COLOR;Initial color;colour;Initial target color;;;none;;'
                                                                   */
  real_T LABELLabelTextlabelInitialtextforthelabelnone_Value;/* Expression: 9
                                                              * Referenced by: '<S288>/LABEL;Label Text;label;Initial text for the label;;;none;;'
                                                              */
  real_T LABELONLY_XLabelOnlyXfloatXpositioncmofthetargetrelativetolocal;/* Expression: 11
                                                                      * Referenced by: '<S288>/LABELONLY_X;LabelOnly X;float;X position (cm) of the target relative to local (0,0) when only the label appears;;;none;;'
                                                                      */
  real_T LABELONLY_YLabelOnlyYfloatYpositioncmofthetargetrelativetolocal;/* Expression: 12
                                                                      * Referenced by: '<S288>/LABELONLY_Y;LabelOnly  Y;float;Y position (cm) of the target relative to local (0,0) when only the label appears;;;none;;'
                                                                      */
  real_T LABEL_HEIGHTLabelHeightfloatLabelHeightcmnone_Value;/* Expression: 10
                                                              * Referenced by: '<S288>/LABEL_HEIGHT;Label Height;float;Label Height (cm);;;none;;'
                                                              */
  real_T LOGICAL_RADIUSLogicalradiusfloatRadiusofthetargetusedforhandint;/* Expression: 4
                                                                      * Referenced by: '<S288>/LOGICAL_RADIUS;Logical radius;float;Radius of the target used for 'hand-in-target' logic (cm);;;none;;'
                                                                      */
  real_T ROTATIONRotationofatargetfloatRotationoftargetnone_Value;/* Expression: 14
                                                                   * Referenced by: '<S288>/ROTATION;Rotation of a target;float;Rotation of target;;;none;;'
                                                                   */
  real_T STROKE_WIDTHStrokeWidthfloatStrokewidthnone_Value;/* Expression: 7
                                                            * Referenced by: '<S288>/STROKE_WIDTH;Stroke Width;float;Stroke width;;;none;;'
                                                            */
  real_T TEXT_COLORTextColorcolourTextColornone_Value;/* Expression: 8
                                                       * Referenced by: '<S288>/TEXT_COLOR;Text Color;colour;Text Color;;;none;;'
                                                       */
  real_T col_xXfloatXPositioncmofthetargetrelativetolocal00none_Value;/* Expression: 1
                                                                      * Referenced by: '<S288>/col_x;X;float;X Position (cm) of the target relative to  local (0,0);;;none;;'
                                                                      */
  real_T col_yYfloatYPositioncmofthetargetrelativetolocal00none_Value;/* Expression: 2
                                                                      * Referenced by: '<S288>/col_y;Y;float;Y Position (cm) of the target relative to  local (0,0);;;none;;'
                                                                      */
  real_T VISUAL_RADIUSVisualradiusfloatVisualradiusofthetargetcmorsizeof;/* Expression: 3
                                                                      * Referenced by: '<S288>/VISUAL_RADIUS;Visual radius;float;Visual radius of the target (cm) or size of the sides of the square targets;;;none;;'
                                                                      */
  real_T INSTRUCTIONS_Value;           /* Expression: 1
                                        * Referenced by: '<S289>/INSTRUCTIONS='
                                        */
  real_T LOAD_FOREITHER_Value;         /* Expression: 2
                                        * Referenced by: '<S289>/LOAD_FOR=EITHER'
                                        */
  real_T K_DELAY_FIXEDDelay_MinintegerMinimumholddelaytimeatstarttargetf;/* Expression: 3
                                                                      * Referenced by: '<S290>/K_DELAY_FIXED;Delay_Min;integer;Minimum hold delay time at start target (fixed);;;none;;'
                                                                      */
  real_T K_DELAY_RANDDelay_RandintegerMaximumadditionaldelaytimeatstartt;/* Expression: 4
                                                                      * Referenced by: '<S290>/K_DELAY_RAND;Delay_Rand;integer;Maximum additional delay time at start target (random);;;none;;'
                                                                      */
  real_T K_PRE_REWARD_DELAYDelay_PreRewardCueintegerTimetocuetherewardin;/* Expression: 8
                                                                      * Referenced by: '<S290>/K_PRE_REWARD_DELAY;Delay_PreRewardCue;integer;Time to cue the reward information prior to the trial onset;;;none;;'
                                                                      */
  real_T K_REWARD_VALReward_ValueintegerOneunitofrewardnone_Value;/* Expression: 1
                                                                   * Referenced by: '<S290>/K_REWARD_VAL;Reward_Value;integer;One unit of reward;;;none;;'
                                                                   */
  real_T K_SCORETEXT_ROWFeedback_Text_TgtTable_RowintegerTargetnumbertob;/* Expression: 2
                                                                      * Referenced by: '<S290>/K_SCORETEXT_ROW;Feedback_Text_TgtTable_Row;integer;Target number to be used to set the feedback text;;;none;;'
                                                                      */
  real_T K_THRESH_VELMAXVel_Min_ThreshfloatMinimumvelocitythatmustbeexce;/* Expression: 7
                                                                      * Referenced by: '<S290>/K_THRESH_VELMAX;Vel_Min_Thresh;float;Minimum velocity that must be exceeded for trial to be considered successful;;;none;;'
                                                                      */
  real_T K_TRIGGER_POSTrigger_PosfloatPositionThresholdfortriggeringtarg;/* Expression: 6
                                                                      * Referenced by: '<S290>/K_TRIGGER_POS;Trigger_Pos;float;Position Threshold for triggering target reveal;;;none;;'
                                                                      */
  real_T K_TRIGGER_VELTrigger_VelfloatVelocityThresholdfortriggeringtarg;/* Expression: 5
                                                                      * Referenced by: '<S290>/K_TRIGGER_VEL;Trigger_Vel;float;Velocity Threshold for triggering target reveal;;;none;;'
                                                                      */
  real32_T Constant_Value_g[400];      /* Computed Parameter: Constant_Value_g
                                        * Referenced by: '<S48>/Constant'
                                        */
  real32_T t2_X0;                      /* Computed Parameter: t2_X0
                                        * Referenced by: '<S48>/t-2'
                                        */
  real32_T t1_X0;                      /* Computed Parameter: t1_X0
                                        * Referenced by: '<S48>/t-1'
                                        */
  real32_T TmpRTBAtSendControlMachineInport1_X0;/* Computed Parameter: TmpRTBAtSendControlMachineInport1_X0
                                                 * Referenced by: synthesized block
                                                 */
  int32_T request_packet_Value[34];    /* Expression: zeros(1, 34, 'int32')
                                        * Referenced by: '<S33>/request_packet'
                                        */
  int32_T Memory_X0_m;                 /* Computed Parameter: Memory_X0_m
                                        * Referenced by: '<S107>/Memory'
                                        */
  int32_T Constant_Value_g0;           /* Computed Parameter: Constant_Value_g0
                                        * Referenced by: '<S106>/Constant'
                                        */
  int32_T Constant1_Value_h;           /* Computed Parameter: Constant1_Value_h
                                        * Referenced by: '<S106>/Constant1'
                                        */
  int32_T Constant_Value_n;            /* Computed Parameter: Constant_Value_n
                                        * Referenced by: '<S107>/Constant'
                                        */
  int32_T Constant1_Value_e;           /* Computed Parameter: Constant1_Value_e
                                        * Referenced by: '<S108>/Constant1'
                                        */
  int32_T Memory_X0_fd;                /* Computed Parameter: Memory_X0_fd
                                        * Referenced by: '<S120>/Memory'
                                        */
  int32_T Constant_Value_gd;           /* Computed Parameter: Constant_Value_gd
                                        * Referenced by: '<S119>/Constant'
                                        */
  int32_T Constant1_Value_h4;          /* Computed Parameter: Constant1_Value_h4
                                        * Referenced by: '<S119>/Constant1'
                                        */
  int32_T Constant_Value_i;            /* Computed Parameter: Constant_Value_i
                                        * Referenced by: '<S120>/Constant'
                                        */
  int32_T Constant1_Value_m;           /* Computed Parameter: Constant1_Value_m
                                        * Referenced by: '<S121>/Constant1'
                                        */
  int32_T Memory_X0_e;                 /* Computed Parameter: Memory_X0_e
                                        * Referenced by: '<S88>/Memory'
                                        */
  int32_T Memory1_X0_h;                /* Computed Parameter: Memory1_X0_h
                                        * Referenced by: '<S88>/Memory1'
                                        */
  int32_T Memory_X0_gr;                /* Computed Parameter: Memory_X0_gr
                                        * Referenced by: '<S89>/Memory'
                                        */
  int32_T Memory1_X0_p;                /* Computed Parameter: Memory1_X0_p
                                        * Referenced by: '<S89>/Memory1'
                                        */
  int32_T Memory_X0_h;                 /* Computed Parameter: Memory_X0_h
                                        * Referenced by: '<S92>/Memory'
                                        */
  int32_T readTrigger_Value;           /* Computed Parameter: readTrigger_Value
                                        * Referenced by: '<S75>/readTrigger'
                                        */
  int32_T Memory_X0_hu;                /* Computed Parameter: Memory_X0_hu
                                        * Referenced by: '<S94>/Memory'
                                        */
  int32_T Memory_X0_n5;                /* Computed Parameter: Memory_X0_n5
                                        * Referenced by: '<S159>/Memory'
                                        */
  int32_T Constant_Value_lk;           /* Computed Parameter: Constant_Value_lk
                                        * Referenced by: '<S158>/Constant'
                                        */
  int32_T Constant1_Value_o;           /* Computed Parameter: Constant1_Value_o
                                        * Referenced by: '<S158>/Constant1'
                                        */
  int32_T Constant_Value_k;            /* Computed Parameter: Constant_Value_k
                                        * Referenced by: '<S159>/Constant'
                                        */
  int32_T Constant1_Value_g;           /* Computed Parameter: Constant1_Value_g
                                        * Referenced by: '<S160>/Constant1'
                                        */
  int32_T Memory_X0_ic;                /* Computed Parameter: Memory_X0_ic
                                        * Referenced by: '<S172>/Memory'
                                        */
  int32_T Constant_Value_ik;           /* Computed Parameter: Constant_Value_ik
                                        * Referenced by: '<S171>/Constant'
                                        */
  int32_T Constant1_Value_j;           /* Computed Parameter: Constant1_Value_j
                                        * Referenced by: '<S171>/Constant1'
                                        */
  int32_T Constant_Value_ly;           /* Computed Parameter: Constant_Value_ly
                                        * Referenced by: '<S172>/Constant'
                                        */
  int32_T Constant1_Value_ol;          /* Computed Parameter: Constant1_Value_ol
                                        * Referenced by: '<S173>/Constant1'
                                        */
  int32_T Memory_X0_nj;                /* Computed Parameter: Memory_X0_nj
                                        * Referenced by: '<S140>/Memory'
                                        */
  int32_T Memory1_X0_hb;               /* Computed Parameter: Memory1_X0_hb
                                        * Referenced by: '<S140>/Memory1'
                                        */
  int32_T Memory_X0_id;                /* Computed Parameter: Memory_X0_id
                                        * Referenced by: '<S141>/Memory'
                                        */
  int32_T Memory1_X0_a;                /* Computed Parameter: Memory1_X0_a
                                        * Referenced by: '<S141>/Memory1'
                                        */
  int32_T Memory_X0_cr;                /* Computed Parameter: Memory_X0_cr
                                        * Referenced by: '<S144>/Memory'
                                        */
  int32_T readTrigger_Value_l;         /* Computed Parameter: readTrigger_Value_l
                                        * Referenced by: '<S76>/readTrigger'
                                        */
  int32_T Memory_X0_ge;                /* Computed Parameter: Memory_X0_ge
                                        * Referenced by: '<S146>/Memory'
                                        */
  int32_T activation_Value[2];         /* Computed Parameter: activation_Value
                                        * Referenced by: '<S64>/activation'
                                        */
  int32_T PCIBusSlot_Value[2];         /* Computed Parameter: PCIBusSlot_Value
                                        * Referenced by: '<S64>/PCI Bus Slot'
                                        */
  int32_T Switch_Threshold_b;          /* Computed Parameter: Switch_Threshold_b
                                        * Referenced by: '<S64>/Switch'
                                        */
  uint32_T total_packets_sent_Y0;      /* Computed Parameter: total_packets_sent_Y0
                                        * Referenced by: '<S51>/total_packets_sent'
                                        */
  uint32_T FixPtConstant_Value;        /* Computed Parameter: FixPtConstant_Value
                                        * Referenced by: '<S56>/FixPt Constant'
                                        */
  uint32_T Output_InitialCondition;    /* Computed Parameter: Output_InitialCondition
                                        * Referenced by: '<S54>/Output'
                                        */
  uint32_T Constant_Value_f;           /* Computed Parameter: Constant_Value_f
                                        * Referenced by: '<S57>/Constant'
                                        */
  uint32_T max_packet_id_Value;        /* Computed Parameter: max_packet_id_Value
                                        * Referenced by: '<S32>/max_packet_id'
                                        */
  uint32_T Memory_X0_o2;               /* Computed Parameter: Memory_X0_o2
                                        * Referenced by: '<S106>/Memory'
                                        */
  uint32_T Constant_Value_p;           /* Computed Parameter: Constant_Value_p
                                        * Referenced by: '<S108>/Constant'
                                        */
  uint32_T Memory_X0_hp;               /* Computed Parameter: Memory_X0_hp
                                        * Referenced by: '<S119>/Memory'
                                        */
  uint32_T Constant_Value_nx;          /* Computed Parameter: Constant_Value_nx
                                        * Referenced by: '<S121>/Constant'
                                        */
  uint32_T Memory_X0_co;               /* Computed Parameter: Memory_X0_co
                                        * Referenced by: '<S158>/Memory'
                                        */
  uint32_T Constant_Value_c;           /* Computed Parameter: Constant_Value_c
                                        * Referenced by: '<S160>/Constant'
                                        */
  uint32_T Memory_X0_er;               /* Computed Parameter: Memory_X0_er
                                        * Referenced by: '<S171>/Memory'
                                        */
  uint32_T Constant_Value_pq;          /* Computed Parameter: Constant_Value_pq
                                        * Referenced by: '<S173>/Constant'
                                        */
  uint32_T Constant1_Value_c;          /* Computed Parameter: Constant1_Value_c
                                        * Referenced by: '<S206>/Constant1'
                                        */
  uint32_T Constant1_Value_me;         /* Computed Parameter: Constant1_Value_me
                                        * Referenced by: '<S208>/Constant1'
                                        */
  uint32_T servocounter_Y0;            /* Computed Parameter: servocounter_Y0
                                        * Referenced by: '<S223>/servo counter'
                                        */
  uint32_T EPcalibrationbtn_Y0;        /* Expression: uint32(0)
                                        * Referenced by: '<S223>/EP calibration btn'
                                        */
  uint32_T Statusbits_Y0[7];           /* Expression: zeros(7,1, 'uint32')
                                        * Referenced by: '<S223>/Status bits'
                                        */
  uint32_T FixPtConstant_Value_j;      /* Computed Parameter: FixPtConstant_Value_j
                                        * Referenced by: '<S228>/FixPt Constant'
                                        */
  uint32_T Output_InitialCondition_p;  /* Computed Parameter: Output_InitialCondition_p
                                        * Referenced by: '<S226>/Output'
                                        */
  uint32_T Constant_Value_dz;          /* Computed Parameter: Constant_Value_dz
                                        * Referenced by: '<S229>/Constant'
                                        */
  uint32_T Constant_Value_di;          /* Computed Parameter: Constant_Value_di
                                        * Referenced by: '<S223>/Constant'
                                        */
  uint32_T Constant1_Value_gt[7];      /* Computed Parameter: Constant1_Value_gt
                                        * Referenced by: '<S223>/Constant1'
                                        */
  uint32_T Constant1_Value_k;          /* Computed Parameter: Constant1_Value_k
                                        * Referenced by: '<S84>/Constant1'
                                        */
  uint32_T FixPtConstant_Value_n;      /* Computed Parameter: FixPtConstant_Value_n
                                        * Referenced by: '<S240>/FixPt Constant'
                                        */
  uint32_T Output_InitialCondition_b;  /* Computed Parameter: Output_InitialCondition_b
                                        * Referenced by: '<S235>/Output'
                                        */
  uint32_T Constant_Value_m;           /* Computed Parameter: Constant_Value_m
                                        * Referenced by: '<S241>/Constant'
                                        */
  uint32_T Output_InitialCondition_pe; /* Computed Parameter: Output_InitialCondition_pe
                                        * Referenced by: '<S78>/Output'
                                        */
  uint32_T FixPtConstant_Value_m;      /* Computed Parameter: FixPtConstant_Value_m
                                        * Referenced by: '<S189>/FixPt Constant'
                                        */
  uint32_T Constant_Value_kn;          /* Computed Parameter: Constant_Value_kn
                                        * Referenced by: '<S190>/Constant'
                                        */
  uint32_T ECATDigitalin_InitialValue[8];/* Computed Parameter: ECATDigitalin_InitialValue
                                          * Referenced by: '<S34>/ECAT Digital in'
                                          */
  uint32_T ServoUpdate_InitialValue;   /* Computed Parameter: ServoUpdate_InitialValue
                                        * Referenced by: '<S34>/ServoUpdate'
                                        */
  uint32_T Systemstatus_InitialValue[7];/* Computed Parameter: Systemstatus_InitialValue
                                         * Referenced by: '<S34>/System status'
                                         */
  uint32_T calibbutton_InitialValue;   /* Computed Parameter: calibbutton_InitialValue
                                        * Referenced by: '<S34>/calib button'
                                        */
  uint32_T Output_InitialCondition_a;  /* Computed Parameter: Output_InitialCondition_a
                                        * Referenced by: '<S44>/Output'
                                        */
  uint32_T FixPtConstant_Value_g;      /* Computed Parameter: FixPtConstant_Value_g
                                        * Referenced by: '<S46>/FixPt Constant'
                                        */
  uint32_T Constant_Value_cq;          /* Computed Parameter: Constant_Value_cq
                                        * Referenced by: '<S47>/Constant'
                                        */
  uint32_T ECATDigDiagnostic_InitialValue[4];/* Computed Parameter: ECATDigDiagnostic_InitialValue
                                              * Referenced by: '<S4>/ECAT Dig Diagnostic'
                                              */
  uint16_T Constant2_Value;            /* Computed Parameter: Constant2_Value
                                        * Referenced by: '<S206>/Constant2'
                                        */
  uint16_T Constant3_Value;            /* Computed Parameter: Constant3_Value
                                        * Referenced by: '<S206>/Constant3'
                                        */
  uint16_T Constant_Value_md;          /* Computed Parameter: Constant_Value_md
                                        * Referenced by: '<S206>/Constant'
                                        */
  uint16_T Constant2_Value_o;          /* Computed Parameter: Constant2_Value_o
                                        * Referenced by: '<S208>/Constant2'
                                        */
  uint16_T Constant3_Value_k;          /* Computed Parameter: Constant3_Value_k
                                        * Referenced by: '<S208>/Constant3'
                                        */
  uint16_T Constant_Value_cn;          /* Computed Parameter: Constant_Value_cn
                                        * Referenced by: '<S208>/Constant'
                                        */
  uint16_T Output_InitialCondition_bg; /* Computed Parameter: Output_InitialCondition_bg
                                        * Referenced by: '<S216>/Output'
                                        */
  uint16_T FixPtConstant_Value_c;      /* Computed Parameter: FixPtConstant_Value_c
                                        * Referenced by: '<S220>/FixPt Constant'
                                        */
  uint16_T Constant_Value_j;           /* Computed Parameter: Constant_Value_j
                                        * Referenced by: '<S221>/Constant'
                                        */
  int8_T TorqueMode_Value;             /* Computed Parameter: TorqueMode_Value
                                        * Referenced by: '<S75>/Torque Mode'
                                        */
  int8_T TorqueMode_Value_k;           /* Computed Parameter: TorqueMode_Value_k
                                        * Referenced by: '<S76>/Torque Mode'
                                        */
  boolean_T TmpRTBAtforcestrobeInport1_X0;/* Computed Parameter: TmpRTBAtforcestrobeInport1_X0
                                           * Referenced by: synthesized block
                                           */
  boolean_T Delay_X0;                  /* Computed Parameter: Delay_X0
                                        * Referenced by: '<S269>/Delay'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_gbyk_v4b_T {
  const char_T *path;
  const char_T *modelName;
  struct SimStruct_tag * *childSfunctions;
  const char_T *errorStatus;
  SS_SimMode simMode;
  RTWLogInfo *rtwLogInfo;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  RTWSolverInfo *solverInfoPtr;
  void *sfcnInfo;

  /*
   * NonInlinedSFcns:
   * The following substructure contains information regarding
   * non-inlined s-functions used in the model.
   */
  struct {
    RTWSfcnInfo sfcnInfo;
    time_T *taskTimePtrs[6];
    SimStruct childSFunctions[44];
    SimStruct *childSFunctionPtrs[44];
    struct _ssBlkInfo2 blkInfo2[44];
    struct _ssSFcnModelMethods2 methods2[44];
    struct _ssSFcnModelMethods3 methods3[44];
    struct _ssStatesInfo2 statesInfo2[44];
    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[5];
      mxArray *params[5];
      struct _ssDWorkRecord dWork[2];
      struct _ssDWorkAuxRecord dWorkAux[2];
    } Sfcn0;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[5];
      mxArray *params[5];
      struct _ssDWorkRecord dWork[2];
      struct _ssDWorkAuxRecord dWorkAux[2];
    } Sfcn1;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[2];
      struct _ssPortOutputs outputPortInfo[6];
      uint_T attribs[5];
      mxArray *params[5];
      struct _ssDWorkRecord dWork[2];
      struct _ssDWorkAuxRecord dWorkAux[2];
    } Sfcn2;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      struct _ssPortOutputs outputPortInfo[2];
      uint_T attribs[5];
      mxArray *params[5];
      struct _ssDWorkRecord dWork[2];
      struct _ssDWorkAuxRecord dWorkAux[2];
    } Sfcn3;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[2];
      uint_T attribs[5];
      mxArray *params[5];
      struct _ssDWorkRecord dWork[2];
      struct _ssDWorkAuxRecord dWorkAux[2];
    } Sfcn4;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[2];
      uint_T attribs[5];
      mxArray *params[5];
      struct _ssDWorkRecord dWork[2];
      struct _ssDWorkAuxRecord dWorkAux[2];
    } Sfcn5;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[5];
      mxArray *params[5];
      struct _ssDWorkRecord dWork[2];
      struct _ssDWorkAuxRecord dWorkAux[2];
    } Sfcn6;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[5];
      mxArray *params[5];
      struct _ssDWorkRecord dWork[2];
      struct _ssDWorkAuxRecord dWorkAux[2];
    } Sfcn7;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[8];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[2];
      struct _ssDWorkAuxRecord dWorkAux[2];
    } Sfcn8;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[8];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[2];
      struct _ssDWorkAuxRecord dWorkAux[2];
    } Sfcn9;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn10;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn11;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn12;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn13;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[8];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[2];
      struct _ssDWorkAuxRecord dWorkAux[2];
    } Sfcn14;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[8];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[2];
      struct _ssDWorkAuxRecord dWorkAux[2];
    } Sfcn15;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn16;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn17;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn18;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn19;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[5];
      mxArray *params[5];
      struct _ssDWorkRecord dWork[2];
      struct _ssDWorkAuxRecord dWorkAux[2];
    } Sfcn20;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[5];
      mxArray *params[5];
      struct _ssDWorkRecord dWork[2];
      struct _ssDWorkAuxRecord dWorkAux[2];
    } Sfcn21;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[2];
      uint_T attribs[5];
      mxArray *params[5];
      struct _ssDWorkRecord dWork[2];
      struct _ssDWorkAuxRecord dWorkAux[2];
    } Sfcn22;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[2];
      uint_T attribs[5];
      mxArray *params[5];
      struct _ssDWorkRecord dWork[2];
      struct _ssDWorkAuxRecord dWorkAux[2];
    } Sfcn23;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      real_T const *UPtrs0[2];
      struct _ssPortOutputs outputPortInfo[1];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn24;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[2];
      real_T const *UPtrs0[1];
      real_T const *UPtrs1[1];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn25;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[3];
      real_T const *UPtrs0[10];
      real_T const *UPtrs1[10];
      real_T const *UPtrs2[1];
      struct _ssPortOutputs outputPortInfo[10];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn26;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[2];
      real_T const *UPtrs0[1];
      real_T const *UPtrs1[1];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn27;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[2];
      uint_T attribs[5];
      mxArray *params[5];
      struct _ssDWorkRecord dWork[2];
      struct _ssDWorkAuxRecord dWorkAux[2];
    } Sfcn28;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn29;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn30;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn31;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn32;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[2];
      real_T const *UPtrs0[512];
      real_T const *UPtrs1[1];
      struct _ssPortOutputs outputPortInfo[18];
    } Sfcn33;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[2];
      uint_T attribs[5];
      mxArray *params[5];
      struct _ssDWorkRecord dWork[2];
      struct _ssDWorkAuxRecord dWorkAux[2];
    } Sfcn34;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn35;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn36;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn37;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn38;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[3];
      real_T const *UPtrs0[4];
      real_T const *UPtrs1[6];
      real_T const *UPtrs2[6];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn39;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn40;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[2];
      uint_T attribs[5];
      mxArray *params[5];
      struct _ssDWorkRecord dWork[2];
      struct _ssDWorkAuxRecord dWorkAux[2];
    } Sfcn41;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[2];
      uint_T attribs[5];
      mxArray *params[5];
      struct _ssDWorkRecord dWork[2];
      struct _ssDWorkAuxRecord dWorkAux[2];
    } Sfcn42;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[2];
      uint_T attribs[5];
      mxArray *params[5];
      struct _ssDWorkRecord dWork[2];
      struct _ssDWorkAuxRecord dWorkAux[2];
    } Sfcn43;
  } NonInlinedSFcns;

  /*
   * DataMapInfo:
   * The following substructure contains information regarding
   * structures generated in the model's C API.
   */
  struct {
    rtwCAPI_ModelMappingInfo mmi;
  } DataMapInfo;

  /*
   * ModelData:
   * The following substructure contains information regarding
   * the data used in the model.
   */
  struct {
    void *blockIO;
    const void *constBlockIO;
    void *defaultParam;
    ZCSigState *prevZCSigState;
    real_T *contStates;
    int_T *periodicContStateIndices;
    real_T *periodicContStateRanges;
    real_T *derivs;
    void *zcSignalValues;
    void *inputs;
    void *outputs;
    boolean_T *contStateDisabled;
    boolean_T zCCacheNeedsReset;
    boolean_T derivCacheNeedsReset;
    boolean_T blkStateChange;
    void *dwork;
  } ModelData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    uint32_T options;
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numU;
    int_T numY;
    int_T numSampTimes;
    int_T numBlocks;
    int_T numBlockIO;
    int_T numBlockPrms;
    int_T numDwork;
    int_T numSFcnPrms;
    int_T numSFcns;
    int_T numIports;
    int_T numOports;
    int_T numNonSampZCs;
    int_T sysDirFeedThru;
    int_T rtwGenSfcn;
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
    void *xpcData;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T stepSize1;
    uint32_T clockTick2;
    uint32_T clockTickH2;
    time_T stepSize2;
    uint32_T clockTick3;
    uint32_T clockTickH3;
    time_T stepSize3;
    uint32_T clockTick4;
    uint32_T clockTickH4;
    time_T stepSize4;
    uint32_T clockTick5;
    uint32_T clockTickH5;
    time_T stepSize5;
    struct {
      uint16_T TID[6];
    } TaskCounters;

    struct {
      boolean_T TID1_2;
      boolean_T TID1_3;
      boolean_T TID1_4;
      boolean_T TID2_3;
    } RateInteraction;

    time_T tStart;
    time_T tFinal;
    time_T timeOfLastOutput;
    void *timingData;
    real_T *varNextHitTimesList;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *sampleTimes;
    time_T *offsetTimes;
    int_T *sampleTimeTaskIDPtr;
    int_T *sampleHits;
    int_T *perTaskSampleHits;
    time_T *t;
    time_T sampleTimesArray[6];
    time_T offsetTimesArray[6];
    int_T sampleTimeTaskIDArray[6];
    int_T sampleHitArray[6];
    int_T perTaskSampleHitsArray[36];
    time_T tArray[6];
  } Timing;
};

/* Block parameters (auto storage) */
extern P_gbyk_v4b_T gbyk_v4b_P;

/* Block signals (auto storage) */
extern B_gbyk_v4b_T gbyk_v4b_B;

/* Block states (auto storage) */
extern DW_gbyk_v4b_T gbyk_v4b_DW;
extern const ConstB_gbyk_v4b_T gbyk_v4b_ConstB;/* constant block i/o */

/* External function called from main */
extern time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
  ;

/* External data declarations for dependent source files */

/* Zero-crossing (trigger) state */
extern PrevZCX_gbyk_v4b_T gbyk_v4b_PrevZCX;

/*====================*
 * External functions *
 *====================*/
extern gbyk_v4b_rtModel *gbyk_v4b(void);
extern void MdlInitializeSizes(void);
extern void MdlInitializeSampleTimes(void);
extern void MdlInitialize(void);
extern void MdlStart(void);
extern void MdlOutputs(int_T tid);
extern void MdlUpdate(int_T tid);
extern void MdlTerminate(void);

/* Real-time Model object */
extern RT_MODEL_gbyk_v4b_T *const gbyk_v4b_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'gbyk_v4b'
 * '<S1>'   : 'gbyk_v4b/AddTxt2TgtB'
 * '<S2>'   : 'gbyk_v4b/AddTxt2TgtC'
 * '<S3>'   : 'gbyk_v4b/Compare To Constant'
 * '<S4>'   : 'gbyk_v4b/DataLogging'
 * '<S5>'   : 'gbyk_v4b/DisplayInstruct'
 * '<S6>'   : 'gbyk_v4b/DisplayText'
 * '<S7>'   : 'gbyk_v4b/GUI Control'
 * '<S8>'   : 'gbyk_v4b/Hand_Feedback'
 * '<S9>'   : 'gbyk_v4b/KINARM_DistanceFromTarget'
 * '<S10>'  : 'gbyk_v4b/KINARM_HandInBox'
 * '<S11>'  : 'gbyk_v4b/KINARM_HandInTarget'
 * '<S12>'  : 'gbyk_v4b/MATLAB Function'
 * '<S13>'  : 'gbyk_v4b/Parameter Table Defn'
 * '<S14>'  : 'gbyk_v4b/Play Sound'
 * '<S15>'  : 'gbyk_v4b/Process_Video_CMD'
 * '<S16>'  : 'gbyk_v4b/Scope '
 * '<S17>'  : 'gbyk_v4b/Scope 3'
 * '<S18>'  : 'gbyk_v4b/Scope 4'
 * '<S19>'  : 'gbyk_v4b/Scope 5'
 * '<S20>'  : 'gbyk_v4b/Scope 6'
 * '<S21>'  : 'gbyk_v4b/Show_Box'
 * '<S22>'  : 'gbyk_v4b/Show_TargetB_With_Label'
 * '<S23>'  : 'gbyk_v4b/Show_TargetC_With_Label'
 * '<S24>'  : 'gbyk_v4b/Show_Target_A'
 * '<S25>'  : 'gbyk_v4b/Trial_Control'
 * '<S26>'  : 'gbyk_v4b/DataLogging/Create Analog Inputs Subsystem'
 * '<S27>'  : 'gbyk_v4b/DataLogging/Create Custom Data Subsystem'
 * '<S28>'  : 'gbyk_v4b/DataLogging/Create Event Codes Subsystem'
 * '<S29>'  : 'gbyk_v4b/DataLogging/Create KINARM Data Subsystem'
 * '<S30>'  : 'gbyk_v4b/DataLogging/Create Task State Subsystem'
 * '<S31>'  : 'gbyk_v4b/DataLogging/Keep alive'
 * '<S32>'  : 'gbyk_v4b/DataLogging/Network Transfer Subsystem'
 * '<S33>'  : 'gbyk_v4b/DataLogging/Poll Force Plates'
 * '<S34>'  : 'gbyk_v4b/DataLogging/Poll KINARM'
 * '<S35>'  : 'gbyk_v4b/DataLogging/Receive_Gaze'
 * '<S36>'  : 'gbyk_v4b/DataLogging/Terminators for Gotos'
 * '<S37>'  : 'gbyk_v4b/DataLogging/apply loads'
 * '<S38>'  : 'gbyk_v4b/DataLogging/compare encoders'
 * '<S39>'  : 'gbyk_v4b/DataLogging/create_lab_info'
 * '<S40>'  : 'gbyk_v4b/DataLogging/Create KINARM Data Subsystem/bitfield'
 * '<S41>'  : 'gbyk_v4b/DataLogging/Create KINARM Data Subsystem/gaze_data'
 * '<S42>'  : 'gbyk_v4b/DataLogging/Create KINARM Data Subsystem/select KINData'
 * '<S43>'  : 'gbyk_v4b/DataLogging/Create KINARM Data Subsystem/select KINData/MATLAB Function'
 * '<S44>'  : 'gbyk_v4b/DataLogging/Create Task State Subsystem/Counter Free-Running'
 * '<S45>'  : 'gbyk_v4b/DataLogging/Create Task State Subsystem/If Running'
 * '<S46>'  : 'gbyk_v4b/DataLogging/Create Task State Subsystem/Counter Free-Running/Increment Real World'
 * '<S47>'  : 'gbyk_v4b/DataLogging/Create Task State Subsystem/Counter Free-Running/Wrap To Zero'
 * '<S48>'  : 'gbyk_v4b/DataLogging/Network Transfer Subsystem/Data Packing Subsystem'
 * '<S49>'  : 'gbyk_v4b/DataLogging/Network Transfer Subsystem/Send Control Machine'
 * '<S50>'  : 'gbyk_v4b/DataLogging/Network Transfer Subsystem/UDP Receiver'
 * '<S51>'  : 'gbyk_v4b/DataLogging/Network Transfer Subsystem/UDP Send Subsystem'
 * '<S52>'  : 'gbyk_v4b/DataLogging/Network Transfer Subsystem/force strobe'
 * '<S53>'  : 'gbyk_v4b/DataLogging/Network Transfer Subsystem/Data Packing Subsystem/Counter'
 * '<S54>'  : 'gbyk_v4b/DataLogging/Network Transfer Subsystem/UDP Send Subsystem/Counter Free-Running'
 * '<S55>'  : 'gbyk_v4b/DataLogging/Network Transfer Subsystem/UDP Send Subsystem/MATLAB Function'
 * '<S56>'  : 'gbyk_v4b/DataLogging/Network Transfer Subsystem/UDP Send Subsystem/Counter Free-Running/Increment Real World'
 * '<S57>'  : 'gbyk_v4b/DataLogging/Network Transfer Subsystem/UDP Send Subsystem/Counter Free-Running/Wrap To Zero'
 * '<S58>'  : 'gbyk_v4b/DataLogging/Poll Force Plates/plate1'
 * '<S59>'  : 'gbyk_v4b/DataLogging/Poll Force Plates/plate2'
 * '<S60>'  : 'gbyk_v4b/DataLogging/Poll Force Plates/send poll 1'
 * '<S61>'  : 'gbyk_v4b/DataLogging/Poll Force Plates/send poll 2'
 * '<S62>'  : 'gbyk_v4b/DataLogging/Poll Force Plates/plate1/parse packet 1'
 * '<S63>'  : 'gbyk_v4b/DataLogging/Poll Force Plates/plate2/parse packet 1'
 * '<S64>'  : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem'
 * '<S65>'  : 'gbyk_v4b/DataLogging/Poll KINARM/Force Sensor Control'
 * '<S66>'  : 'gbyk_v4b/DataLogging/Poll KINARM/PMAC Subsystem'
 * '<S67>'  : 'gbyk_v4b/DataLogging/Poll KINARM/bkin_internal_testing'
 * '<S68>'  : 'gbyk_v4b/DataLogging/Poll KINARM/constants'
 * '<S69>'  : 'gbyk_v4b/DataLogging/Poll KINARM/control read write'
 * '<S70>'  : 'gbyk_v4b/DataLogging/Poll KINARM/createKINData'
 * '<S71>'  : 'gbyk_v4b/DataLogging/Poll KINARM/isecat'
 * '<S72>'  : 'gbyk_v4b/DataLogging/Poll KINARM/ispmac'
 * '<S73>'  : 'gbyk_v4b/DataLogging/Poll KINARM/make KINData bus'
 * '<S74>'  : 'gbyk_v4b/DataLogging/Poll KINARM/split_primary'
 * '<S75>'  : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1'
 * '<S76>'  : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2'
 * '<S77>'  : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Compare'
 * '<S78>'  : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Counter Free-Running'
 * '<S79>'  : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Digital output'
 * '<S80>'  : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Init to Bus'
 * '<S81>'  : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/latch_errors'
 * '<S82>'  : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/sdo_addrs'
 * '<S83>'  : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/setState'
 * '<S84>'  : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/update'
 * '<S85>'  : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M1'
 * '<S86>'  : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M2'
 * '<S87>'  : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/Find Robot type'
 * '<S88>'  : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/M1 AbsEnc Calibration'
 * '<S89>'  : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/M2 AbsEnc Calibration'
 * '<S90>'  : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/SDO read machine'
 * '<S91>'  : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/SDO reading'
 * '<S92>'  : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/SDO writing'
 * '<S93>'  : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/forceEnableDisable'
 * '<S94>'  : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/int subsystem'
 * '<S95>'  : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/size'
 * '<S96>'  : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/size1'
 * '<S97>'  : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/split out constants'
 * '<S98>'  : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/split out constants1'
 * '<S99>'  : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M1/A1M1 PDOs'
 * '<S100>' : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M1/Compare To Constant'
 * '<S101>' : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M1/Control GDC Whistle State'
 * '<S102>' : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M1/EMCY Message pump'
 * '<S103>' : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M1/PDO to Angles Subsystem'
 * '<S104>' : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M1/A1M1 PDOs/parse status register'
 * '<S105>' : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M1/EMCY Message pump/Read EMCY'
 * '<S106>' : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M1/EMCY Message pump/Read EMCY Count'
 * '<S107>' : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M1/EMCY Message pump/Read EMCY Value'
 * '<S108>' : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M1/EMCY Message pump/clear errors'
 * '<S109>' : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M1/EMCY Message pump/fault monitor'
 * '<S110>' : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M1/EMCY Message pump/fault monitor1'
 * '<S111>' : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M1/PDO to Angles Subsystem/countsToRads'
 * '<S112>' : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M2/A1M2 PDOs'
 * '<S113>' : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M2/Compare'
 * '<S114>' : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M2/Control GDC Whistle State'
 * '<S115>' : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M2/EMCY Message pump'
 * '<S116>' : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M2/PDO to Angles Subsystem'
 * '<S117>' : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M2/A1M2 PDOs/parse status register1'
 * '<S118>' : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M2/EMCY Message pump/Read EMCY'
 * '<S119>' : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M2/EMCY Message pump/Read EMCY Count'
 * '<S120>' : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M2/EMCY Message pump/Read EMCY Value'
 * '<S121>' : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M2/EMCY Message pump/clear errors'
 * '<S122>' : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M2/EMCY Message pump/fault monitor'
 * '<S123>' : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M2/EMCY Message pump/fault monitor1'
 * '<S124>' : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/A1M2/PDO to Angles Subsystem/countsToRads'
 * '<S125>' : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/M1 AbsEnc Calibration/AbsEncoder machine'
 * '<S126>' : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/M1 AbsEnc Calibration/set-up values'
 * '<S127>' : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/M2 AbsEnc Calibration/AbsEncoder machine'
 * '<S128>' : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/M2 AbsEnc Calibration/set-up values'
 * '<S129>' : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/SDO reading/Read Drive 1 SDO'
 * '<S130>' : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/SDO reading/SDO read machine'
 * '<S131>' : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/SDO reading/values'
 * '<S132>' : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/SDO reading/Read Drive 1 SDO/converter'
 * '<S133>' : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/SDO writing/SDO write machine'
 * '<S134>' : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/SDO writing/convert'
 * '<S135>' : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/int subsystem/Read Drive 1 SDO'
 * '<S136>' : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 1/int subsystem/Read Drive 1 SDO/converter'
 * '<S137>' : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M1'
 * '<S138>' : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M2'
 * '<S139>' : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/Find Robot type'
 * '<S140>' : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/M1 AbsEnc Calibration'
 * '<S141>' : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/M2 AbsEnc Calibration'
 * '<S142>' : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/SDO read machine'
 * '<S143>' : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/SDO reading'
 * '<S144>' : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/SDO writing'
 * '<S145>' : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/forceEnableDisable'
 * '<S146>' : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/int subsystem'
 * '<S147>' : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/size'
 * '<S148>' : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/size1'
 * '<S149>' : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/split out constants'
 * '<S150>' : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/split out constants1'
 * '<S151>' : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M1/A2M1 PDOs'
 * '<S152>' : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M1/Compare'
 * '<S153>' : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M1/Control GDC Whistle State'
 * '<S154>' : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M1/EMCY Message pump'
 * '<S155>' : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M1/PDO to Angles Subsystem'
 * '<S156>' : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M1/A2M1 PDOs/parse status register1'
 * '<S157>' : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M1/EMCY Message pump/Read EMCY'
 * '<S158>' : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M1/EMCY Message pump/Read EMCY Count'
 * '<S159>' : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M1/EMCY Message pump/Read EMCY Value'
 * '<S160>' : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M1/EMCY Message pump/clear errors'
 * '<S161>' : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M1/EMCY Message pump/fault monitor'
 * '<S162>' : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M1/EMCY Message pump/fault monitor1'
 * '<S163>' : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M1/PDO to Angles Subsystem/countsToRads'
 * '<S164>' : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M2/A2M2 PDOs'
 * '<S165>' : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M2/Compare'
 * '<S166>' : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M2/Control GDC Whistle State'
 * '<S167>' : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M2/EMCY Message pump'
 * '<S168>' : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M2/PDO to Angles Subsystem'
 * '<S169>' : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M2/A2M2 PDOs/parse status register1'
 * '<S170>' : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M2/EMCY Message pump/Read EMCY'
 * '<S171>' : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M2/EMCY Message pump/Read EMCY Count'
 * '<S172>' : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M2/EMCY Message pump/Read EMCY Value'
 * '<S173>' : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M2/EMCY Message pump/clear errors'
 * '<S174>' : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M2/EMCY Message pump/fault monitor'
 * '<S175>' : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M2/EMCY Message pump/fault monitor1'
 * '<S176>' : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/A2M2/PDO to Angles Subsystem/countsToRads'
 * '<S177>' : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/M1 AbsEnc Calibration/AbsEncoder machine'
 * '<S178>' : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/M1 AbsEnc Calibration/set-up values'
 * '<S179>' : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/M2 AbsEnc Calibration/AbsEncoder machine'
 * '<S180>' : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/M2 AbsEnc Calibration/set-up values'
 * '<S181>' : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/SDO reading/Read Drive 3 SDO'
 * '<S182>' : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/SDO reading/SDO read machine'
 * '<S183>' : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/SDO reading/values'
 * '<S184>' : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/SDO reading/Read Drive 3 SDO/converter'
 * '<S185>' : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/SDO writing/SDO write machine'
 * '<S186>' : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/SDO writing/convert'
 * '<S187>' : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/int subsystem/Read Drive 3 SDO'
 * '<S188>' : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Arm 2/int subsystem/Read Drive 3 SDO/converter'
 * '<S189>' : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Counter Free-Running/Increment Real World'
 * '<S190>' : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Counter Free-Running/Wrap To Zero'
 * '<S191>' : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Digital output/update digital outputs'
 * '<S192>' : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/Init to Bus/split init'
 * '<S193>' : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/update/convert to bit field'
 * '<S194>' : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/update/create filtered velocities'
 * '<S195>' : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/update/create kinematics'
 * '<S196>' : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/update/create servo counter'
 * '<S197>' : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/update/robottype1'
 * '<S198>' : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/update/update HW settings'
 * '<S199>' : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/update/update calibrations'
 * '<S200>' : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/update/create filtered velocities/filter_velocities'
 * '<S201>' : 'gbyk_v4b/DataLogging/Poll KINARM/EtherCAT Subsystem/update/create filtered velocities/rebuild'
 * '<S202>' : 'gbyk_v4b/DataLogging/Poll KINARM/Force Sensor Control/Force Sensor 1 Subsystem'
 * '<S203>' : 'gbyk_v4b/DataLogging/Poll KINARM/Force Sensor Control/Force Sensor 2 Subsystem'
 * '<S204>' : 'gbyk_v4b/DataLogging/Poll KINARM/Force Sensor Control/Force Sensor 1 Subsystem/Create timestamp'
 * '<S205>' : 'gbyk_v4b/DataLogging/Poll KINARM/Force Sensor Control/Force Sensor 1 Subsystem/Detect Change'
 * '<S206>' : 'gbyk_v4b/DataLogging/Poll KINARM/Force Sensor Control/Force Sensor 1 Subsystem/If Action Subsystem'
 * '<S207>' : 'gbyk_v4b/DataLogging/Poll KINARM/Force Sensor Control/Force Sensor 2 Subsystem/Create timestamp'
 * '<S208>' : 'gbyk_v4b/DataLogging/Poll KINARM/Force Sensor Control/Force Sensor 2 Subsystem/Data Transfer Start Subsystem'
 * '<S209>' : 'gbyk_v4b/DataLogging/Poll KINARM/Force Sensor Control/Force Sensor 2 Subsystem/Detect Change'
 * '<S210>' : 'gbyk_v4b/DataLogging/Poll KINARM/PMAC Subsystem/read_pmac'
 * '<S211>' : 'gbyk_v4b/DataLogging/Poll KINARM/PMAC Subsystem/update settings'
 * '<S212>' : 'gbyk_v4b/DataLogging/Poll KINARM/PMAC Subsystem/read_pmac/DPRAM Access Subsystem'
 * '<S213>' : 'gbyk_v4b/DataLogging/Poll KINARM/PMAC Subsystem/read_pmac/Monitor_status'
 * '<S214>' : 'gbyk_v4b/DataLogging/Poll KINARM/PMAC Subsystem/read_pmac/Robot_data_builder'
 * '<S215>' : 'gbyk_v4b/DataLogging/Poll KINARM/PMAC Subsystem/read_pmac/filter_velocities'
 * '<S216>' : 'gbyk_v4b/DataLogging/Poll KINARM/PMAC Subsystem/read_pmac/DPRAM Access Subsystem/Counter Free-Running'
 * '<S217>' : 'gbyk_v4b/DataLogging/Poll KINARM/PMAC Subsystem/read_pmac/DPRAM Access Subsystem/Read DPRAM'
 * '<S218>' : 'gbyk_v4b/DataLogging/Poll KINARM/PMAC Subsystem/read_pmac/DPRAM Access Subsystem/TypeCast'
 * '<S219>' : 'gbyk_v4b/DataLogging/Poll KINARM/PMAC Subsystem/read_pmac/DPRAM Access Subsystem/Write DPRAM'
 * '<S220>' : 'gbyk_v4b/DataLogging/Poll KINARM/PMAC Subsystem/read_pmac/DPRAM Access Subsystem/Counter Free-Running/Increment Real World'
 * '<S221>' : 'gbyk_v4b/DataLogging/Poll KINARM/PMAC Subsystem/read_pmac/DPRAM Access Subsystem/Counter Free-Running/Wrap To Zero'
 * '<S222>' : 'gbyk_v4b/DataLogging/Poll KINARM/PMAC Subsystem/update settings/update status format'
 * '<S223>' : 'gbyk_v4b/DataLogging/Poll KINARM/bkin_internal_testing/Data receive'
 * '<S224>' : 'gbyk_v4b/DataLogging/Poll KINARM/bkin_internal_testing/Data write'
 * '<S225>' : 'gbyk_v4b/DataLogging/Poll KINARM/bkin_internal_testing/ispmac1'
 * '<S226>' : 'gbyk_v4b/DataLogging/Poll KINARM/bkin_internal_testing/Data receive/Counter Free-Running'
 * '<S227>' : 'gbyk_v4b/DataLogging/Poll KINARM/bkin_internal_testing/Data receive/MATLAB Function'
 * '<S228>' : 'gbyk_v4b/DataLogging/Poll KINARM/bkin_internal_testing/Data receive/Counter Free-Running/Increment Real World'
 * '<S229>' : 'gbyk_v4b/DataLogging/Poll KINARM/bkin_internal_testing/Data receive/Counter Free-Running/Wrap To Zero'
 * '<S230>' : 'gbyk_v4b/DataLogging/Poll KINARM/constants/arm1'
 * '<S231>' : 'gbyk_v4b/DataLogging/Poll KINARM/constants/arm2'
 * '<S232>' : 'gbyk_v4b/DataLogging/Poll KINARM/constants/update constants subsystem'
 * '<S233>' : 'gbyk_v4b/DataLogging/Poll KINARM/constants/arm1/decode robot'
 * '<S234>' : 'gbyk_v4b/DataLogging/Poll KINARM/constants/arm2/decode robot'
 * '<S235>' : 'gbyk_v4b/DataLogging/Poll KINARM/createKINData/Counter Free-Running'
 * '<S236>' : 'gbyk_v4b/DataLogging/Poll KINARM/createKINData/Create KINARM Data Array'
 * '<S237>' : 'gbyk_v4b/DataLogging/Poll KINARM/createKINData/bitpack'
 * '<S238>' : 'gbyk_v4b/DataLogging/Poll KINARM/createKINData/hand feedback'
 * '<S239>' : 'gbyk_v4b/DataLogging/Poll KINARM/createKINData/record errors'
 * '<S240>' : 'gbyk_v4b/DataLogging/Poll KINARM/createKINData/Counter Free-Running/Increment Real World'
 * '<S241>' : 'gbyk_v4b/DataLogging/Poll KINARM/createKINData/Counter Free-Running/Wrap To Zero'
 * '<S242>' : 'gbyk_v4b/DataLogging/Poll KINARM/make KINData bus/splitKINData arm1'
 * '<S243>' : 'gbyk_v4b/DataLogging/Poll KINARM/make KINData bus/splitKINData arm2'
 * '<S244>' : 'gbyk_v4b/DataLogging/Poll KINARM/make KINData bus/splitKINDataGeneral'
 * '<S245>' : 'gbyk_v4b/DataLogging/Poll KINARM/split_primary/split_primary'
 * '<S246>' : 'gbyk_v4b/DataLogging/Poll KINARM/split_primary/split_primary1'
 * '<S247>' : 'gbyk_v4b/DataLogging/Receive_Gaze/Create timestamp'
 * '<S248>' : 'gbyk_v4b/DataLogging/Receive_Gaze/Embedded MATLAB Function1'
 * '<S249>' : 'gbyk_v4b/DataLogging/Receive_Gaze/clean_packet'
 * '<S250>' : 'gbyk_v4b/DataLogging/Receive_Gaze/convert to seconds2'
 * '<S251>' : 'gbyk_v4b/DataLogging/apply loads/EtherCAT Apply Loads'
 * '<S252>' : 'gbyk_v4b/DataLogging/apply loads/apply pmac loads'
 * '<S253>' : 'gbyk_v4b/DataLogging/apply loads/isecat'
 * '<S254>' : 'gbyk_v4b/DataLogging/apply loads/isecat1'
 * '<S255>' : 'gbyk_v4b/DataLogging/apply loads/EtherCAT Apply Loads/A1 Apply torques'
 * '<S256>' : 'gbyk_v4b/DataLogging/apply loads/EtherCAT Apply Loads/A2 Apply torques'
 * '<S257>' : 'gbyk_v4b/DataLogging/apply loads/EtherCAT Apply Loads/convert torques'
 * '<S258>' : 'gbyk_v4b/DataLogging/compare encoders/delta'
 * '<S259>' : 'gbyk_v4b/DataLogging/create_lab_info/Subsystem'
 * '<S260>' : 'gbyk_v4b/DataLogging/create_lab_info/Subsystem/MATLAB Function'
 * '<S261>' : 'gbyk_v4b/DataLogging/create_lab_info/Subsystem/MATLAB Function1'
 * '<S262>' : 'gbyk_v4b/DisplayInstruct/Show_Target'
 * '<S263>' : 'gbyk_v4b/DisplayInstruct/Show_Target/Embedded MATLAB Function'
 * '<S264>' : 'gbyk_v4b/DisplayText/MATLAB Function'
 * '<S265>' : 'gbyk_v4b/DisplayText/Show_Target_With_Label1'
 * '<S266>' : 'gbyk_v4b/DisplayText/Show_Target_With_Label1/Embedded MATLAB Function'
 * '<S267>' : 'gbyk_v4b/GUI Control/Preview Targets Subsystem'
 * '<S268>' : 'gbyk_v4b/GUI Control/Run Command Subsystem'
 * '<S269>' : 'gbyk_v4b/GUI Control/Task Execution Control Subsystem'
 * '<S270>' : 'gbyk_v4b/GUI Control/Task_progress'
 * '<S271>' : 'gbyk_v4b/GUI Control/Unused Gotos Subsystem'
 * '<S272>' : 'gbyk_v4b/GUI Control/Preview Targets Subsystem/Create Target Vector'
 * '<S273>' : 'gbyk_v4b/GUI Control/Run Command Subsystem/Embedded MATLAB Function'
 * '<S274>' : 'gbyk_v4b/GUI Control/Run Command Subsystem/Hold_to_1Khz'
 * '<S275>' : 'gbyk_v4b/GUI Control/Task Execution Control Subsystem/Compare To Constant'
 * '<S276>' : 'gbyk_v4b/GUI Control/Task Execution Control Subsystem/Task Execution Control Machine'
 * '<S277>' : 'gbyk_v4b/GUI Control/Task_progress/MATLAB Function'
 * '<S278>' : 'gbyk_v4b/Hand_Feedback/FeedFwdArm'
 * '<S279>' : 'gbyk_v4b/KINARM_DistanceFromTarget/Embedded MATLAB InsideTarget'
 * '<S280>' : 'gbyk_v4b/KINARM_DistanceFromTarget/Embedded MATLAB WhichHand'
 * '<S281>' : 'gbyk_v4b/KINARM_HandInBox/Embedded MATLAB InsideTarget'
 * '<S282>' : 'gbyk_v4b/KINARM_HandInBox/Embedded MATLAB WhichHand'
 * '<S283>' : 'gbyk_v4b/KINARM_HandInTarget/Embedded MATLAB InsideTarget'
 * '<S284>' : 'gbyk_v4b/KINARM_HandInTarget/Embedded MATLAB WhichHand'
 * '<S285>' : 'gbyk_v4b/Parameter Table Defn/TP_table'
 * '<S286>' : 'gbyk_v4b/Parameter Table Defn/buttons'
 * '<S287>' : 'gbyk_v4b/Parameter Table Defn/events'
 * '<S288>' : 'gbyk_v4b/Parameter Table Defn/target_table'
 * '<S289>' : 'gbyk_v4b/Parameter Table Defn/task_definition'
 * '<S290>' : 'gbyk_v4b/Parameter Table Defn/task_wide'
 * '<S291>' : 'gbyk_v4b/Play Sound/Play sound over and over'
 * '<S292>' : 'gbyk_v4b/Play Sound/Scope '
 * '<S293>' : 'gbyk_v4b/Play Sound/Subsystem2'
 * '<S294>' : 'gbyk_v4b/Play Sound/Subsystem3'
 * '<S295>' : 'gbyk_v4b/Play Sound/Subsystem4'
 * '<S296>' : 'gbyk_v4b/Process_Video_CMD/Add_requested_Delay'
 * '<S297>' : 'gbyk_v4b/Process_Video_CMD/MATLAB Function'
 * '<S298>' : 'gbyk_v4b/Process_Video_CMD/PVC_core'
 * '<S299>' : 'gbyk_v4b/Process_Video_CMD/Add_requested_Delay/MATLAB Function'
 * '<S300>' : 'gbyk_v4b/Process_Video_CMD/PVC_core/Pack VCodeFrame2'
 * '<S301>' : 'gbyk_v4b/Show_Box/Embedded MATLAB Function'
 * '<S302>' : 'gbyk_v4b/Show_TargetB_With_Label/Embedded MATLAB Function'
 * '<S303>' : 'gbyk_v4b/Show_TargetC_With_Label/Embedded MATLAB Function'
 * '<S304>' : 'gbyk_v4b/Show_Target_A/Embedded MATLAB Function'
 */
#endif                                 /* RTW_HEADER_gbyk_v4b_h_ */
