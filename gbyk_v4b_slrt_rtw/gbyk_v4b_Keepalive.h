/*
 * Code generation for system system '<S4>/Keep alive'
 * For more details, see corresponding source file gbyk_v4b_Keepalive.c
 *
 */

#ifndef RTW_HEADER_gbyk_v4b_Keepalive_h_
#define RTW_HEADER_gbyk_v4b_Keepalive_h_
#include <stddef.h>
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

extern void gbyk_v4b_Keepalive_Start(void);
extern void gbyk_v4b_Keepalive(void);
extern void gbyk_v4b_Keepalive_Term(void);

#endif                                 /* RTW_HEADER_gbyk_v4b_Keepalive_h_ */
