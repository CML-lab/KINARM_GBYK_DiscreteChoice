/*
 * Code generation for system system '<S15>/PVC_core'
 * For more details, see corresponding source file gbyk_v4b_PVC_core.c
 *
 */

#ifndef RTW_HEADER_gbyk_v4b_PVC_core_h_
#define RTW_HEADER_gbyk_v4b_PVC_core_h_
#include <float.h>
#include <math.h>
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
#include "rt_nonfinite.h"

extern void gbyk_v4b_PVC_core_Init(void);
extern void gbyk_v4b_PVC_core_Start(void);
extern void gbyk_v4b_PVC_core_UpdateTID4(void);
extern void gbyk_v4b_PVC_coreTID0(void);
extern void gbyk_v4b_PVC_coreTID4(void);

#endif                                 /* RTW_HEADER_gbyk_v4b_PVC_core_h_ */
