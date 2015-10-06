/*
 * File: Test_Stateflow.h
 *
 * Code generated for Simulink model :Test_Stateflow.
 *
 * Model version      : 1.24
 * Simulink Coder version    : 8.6 (R2014a) 27-Dec-2013
 * TLC version       : 8.6 (Jan 30 2014)
 * C/C++ source code generated on  : Tue Oct 06 10:23:43 2015
 *
 * Target selection: stm32.tlc
 * Embedded hardware selection: STMicroelectronics->STM32 32-bit Cortex-M
 * Code generation objectives: Unspecified
 * Validation result: Not run
 *
 *
 *
 * ******************************************************************************
 * * attention
 * *
 * * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
 * * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
 * * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
 * * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
 * * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
 * * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
 * *
 * ******************************************************************************
 */

#ifndef RTW_HEADER_Test_Stateflow_h_
#define RTW_HEADER_Test_Stateflow_h_
#include <stddef.h>
#include <string.h>
#include "Test_Stateflow_STM32.h"
#ifndef Test_Stateflow_COMMON_INCLUDES_
# define Test_Stateflow_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Test_Stateflow_COMMON_INCLUDES_ */

#include "Test_Stateflow_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((void*) 0)
#endif

/* Block signals (auto storage) */
typedef struct {
  real_T GPIO_Read;                    /* '<Root>/GPIO_Read' */
  real_T LED1;                         /* '<Root>/Chart' */
  real_T LED2;                         /* '<Root>/Chart' */
  real_T LED3;                         /* '<Root>/Chart' */
} B_Test_Stateflow;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  uint8_T is_active_c3_Test_Stateflow; /* '<Root>/Chart' */
  uint8_T is_c3_Test_Stateflow;        /* '<Root>/Chart' */
  uint8_T temporalCounter_i1;          /* '<Root>/Chart' */
} DW_Test_Stateflow;

/* Parameters (auto storage) */
struct P_Test_Stateflow_ {
  uint8_T Constant1_Value;             /* Computed Parameter: Constant1_Value
                                        * Referenced by: '<Root>/Constant1'
                                        */
  uint8_T Constant2_Value;             /* Computed Parameter: Constant2_Value
                                        * Referenced by: '<Root>/Constant2'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Test_Stateflow {
  const char_T *errorStatus;
};

/* Block parameters (auto storage) */
extern P_Test_Stateflow Test_Stateflow_P;

/* Block signals (auto storage) */
extern B_Test_Stateflow Test_Stateflow_B;

/* Block states (auto storage) */
extern DW_Test_Stateflow Test_Stateflow_DW;

/* Model entry point functions */
extern void Test_Stateflow_initialize(void);
extern void Test_Stateflow_step(void);

/* Real-time Model object */
extern RT_MODEL_Test_Stateflow *const Test_Stateflow_M;

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
 * '<Root>' : 'Test_Stateflow'
 * '<S1>'   : 'Test_Stateflow/Chart'
 */
#endif                                 /* RTW_HEADER_Test_Stateflow_h_ */

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF] Test_Stateflow.h
 */
