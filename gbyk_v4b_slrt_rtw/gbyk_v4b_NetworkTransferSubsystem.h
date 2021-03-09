/*
 * Code generation for system system '<S4>/Network Transfer Subsystem'
 * For more details, see corresponding source file gbyk_v4b_NetworkTransferSubsystem.c
 *
 */

#ifndef RTW_HEADER_gbyk_v4b_NetworkTransferSubsystem_h_
#define RTW_HEADER_gbyk_v4b_NetworkTransferSubsystem_h_
#include <stddef.h>
#include <string.h>
#include <float.h>
#include <math.h>
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

extern void gbyk_v4b_UDPSendSubsystem_Init(void);
extern void gbyk_v4b_UDPSendSubsystem_Start(void);
extern void gbyk_v4b_UDPSendSubsystem(void);
extern void gbyk_v4b_NetworkTransferSubsystem_Init(void);
extern void gbyk_v4b_NetworkTransferSubsystem_Start(void);
extern void gbyk_v4b_NetworkTransferSubsystem_UpdateTID0(void);
extern void gbyk_v4b_NetworkTransferSubsystem_UpdateTID2(void);
extern void gbyk_v4b_NetworkTransferSubsystem_UpdateTID3(void);
extern void gbyk_v4b_NetworkTransferSubsystemTID0(void);
extern void gbyk_v4b_NetworkTransferSubsystemTID2(void);
extern void gbyk_v4b_NetworkTransferSubsystemTID3(void);
extern void gbyk_v4b_UDPSendSubsystem_Term(void);
extern void gbyk_v4b_NetworkTransferSubsystem_Term(void);

#endif                                 /* RTW_HEADER_gbyk_v4b_NetworkTransferSubsystem_h_ */
