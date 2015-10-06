/*
 * File: Test_GPIO.h
 *
 * Code generated for Simulink model :Test_GPIO.
 *
 * Model version      : 1.28
 * Simulink Coder version    : 8.6 (R2014a) 27-Dec-2013
 * TLC version       : 8.6 (Jan 30 2014)
 * C/C++ source code generated on  : Tue Oct 06 09:49:43 2015
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

#ifndef RTW_HEADER_Test_GPIO_h_
#define RTW_HEADER_Test_GPIO_h_
#include <math.h>
#include <stddef.h>
#include <string.h>
#include "Test_GPIO_STM32.h"
#ifndef Test_GPIO_COMMON_INCLUDES_
# define Test_GPIO_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* Test_GPIO_COMMON_INCLUDES_ */

#include "Test_GPIO_types.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"

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
  real_T GPIO_Read_o4;                 /* '<Root>/GPIO_Read' */
  real_T GPIO_Read_o5;                 /* '<Root>/GPIO_Read' */
  real_T y;                            /* '<Root>/MATLAB Function' */
  uint8_T GPIO_Read_o2;                /* '<Root>/GPIO_Read' */
  uint8_T GPIO_Read_o3;                /* '<Root>/GPIO_Read' */
  uint8_T Switch;                      /* '<Root>/Switch' */
  boolean_T GPIO_Read_o1;              /* '<Root>/GPIO_Read' */
  boolean_T LogicalOperator1;          /* '<Root>/Logical Operator 1' */
  boolean_T LogicalOperator2;          /* '<Root>/Logical Operator 2' */
} B_Test_GPIO;

/* Parameters (auto storage) */
struct P_Test_GPIO_ {
  real_T CompareToConstant_const;      /* Mask Parameter: CompareToConstant_const
                                        * Referenced by: '<S1>/Constant'
                                        */
  uint8_T Constant1_Value;             /* Computed Parameter: Constant1_Value
                                        * Referenced by: '<Root>/Constant1'
                                        */
  uint8_T Constant2_Value;             /* Computed Parameter: Constant2_Value
                                        * Referenced by: '<Root>/Constant2'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_Test_GPIO {
  const char_T *errorStatus;
};

/* Block parameters (auto storage) */
extern P_Test_GPIO Test_GPIO_P;

/* Block signals (auto storage) */
extern B_Test_GPIO Test_GPIO_B;

/* Model entry point functions */
extern void Test_GPIO_initialize(void);
extern void Test_GPIO_step(void);

/* Real-time Model object */
extern RT_MODEL_Test_GPIO *const Test_GPIO_M;

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
 * '<Root>' : 'Test_GPIO'
 * '<S1>'   : 'Test_GPIO/Compare To Constant'
 * '<S2>'   : 'Test_GPIO/MATLAB Function'
 */
#endif                                 /* RTW_HEADER_Test_GPIO_h_ */

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF] Test_GPIO.h
 */
