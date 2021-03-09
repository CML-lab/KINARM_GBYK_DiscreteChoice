/*
 * Code generation for system system '<S34>/Force Sensor Control'
 * For more details, see corresponding source file gbyk_v4b_ForceSensorControl.c
 *
 */

#ifndef RTW_HEADER_gbyk_v4b_ForceSensorControl_h_
#define RTW_HEADER_gbyk_v4b_ForceSensorControl_h_
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

/* Block signals for system '<S202>/Create timestamp' */
typedef struct {
  real_T timestamp_out;                /* '<S202>/Create timestamp' */
} B_Createtimestamp_gbyk_v4b_T;

/* Block states (auto storage) for system '<S202>/Create timestamp' */
typedef struct {
  uint32_T start_time;                 /* '<S202>/Create timestamp' */
  uint32_T last_time;                  /* '<S202>/Create timestamp' */
} DW_Createtimestamp_gbyk_v4b_T;

extern void gbyk_v4b_Createtimestamp_Init(DW_Createtimestamp_gbyk_v4b_T *localDW);
extern void gbyk_v4b_Createtimestamp(const uint32_T rtu_times_in[3],
  B_Createtimestamp_gbyk_v4b_T *localB, DW_Createtimestamp_gbyk_v4b_T *localDW);
extern void gbyk_v4b_ForceSensorControl_Init(void);
extern void gbyk_v4b_ForceSensorControl_Start(void);
extern void gbyk_v4b_ForceSensorControl_Update(void);
extern void gbyk_v4b_ForceSensorControl(void);
extern void gbyk_v4b_ForceSensorControl_Term(void);

#endif                                 /* RTW_HEADER_gbyk_v4b_ForceSensorControl_h_ */
