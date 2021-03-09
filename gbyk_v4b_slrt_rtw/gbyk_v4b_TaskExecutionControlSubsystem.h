/*
 * Code generation for system system '<S7>/Task Execution Control Subsystem'
 * For more details, see corresponding source file gbyk_v4b_TaskExecutionControlSubsystem.c
 *
 */

#ifndef RTW_HEADER_gbyk_v4b_TaskExecutionControlSubsystem_h_
#define RTW_HEADER_gbyk_v4b_TaskExecutionControlSubsystem_h_
#include <math.h>
#include <stdlib.h>
#include <string.h>
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
#include "rt_zcfcn.h"
#include "rt_nonfinite.h"

extern void gbyk_v4b_TaskExecutionControlSubsystem_Init(void);
extern void gbyk_v4b_TaskExecutionControlSubsystem_Start(void);
extern void gbyk_v4b_TaskExecutionControlSubsystem_Update(void);
extern void gbyk_v4b_TaskExecutionControlSubsystem(void);

#endif                                 /* RTW_HEADER_gbyk_v4b_TaskExecutionControlSubsystem_h_ */
