/*
 * File: Test_Stateflow.c
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

#include "Test_Stateflow.h"
#include "Test_Stateflow_private.h"

/* Named constants for Chart: '<Root>/Chart' */
#define Test_Stateflow_IN_NO_ACTIVE_CHILD ((uint8_T)0U)
#define Test_Stateflow_IN_S1           ((uint8_T)1U)
#define Test_Stateflow_IN_S2           ((uint8_T)2U)
#define Test_Stateflow_IN_S3           ((uint8_T)3U)

/* Block signals (auto storage) */
B_Test_Stateflow Test_Stateflow_B;

/* Block states (auto storage) */
DW_Test_Stateflow Test_Stateflow_DW;

/* Real-time model */
RT_MODEL_Test_Stateflow Test_Stateflow_M_;
RT_MODEL_Test_Stateflow *const Test_Stateflow_M = &Test_Stateflow_M_;

/* Model step function */
void Test_Stateflow_step(void)
{
  /* S-Function Block: <Root>/STM32_Config */

  /* S-Function Block: <Root>/GPIO_Read */
  Test_Stateflow_B.GPIO_Read = (boolean_T)HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_8);
  if (Test_Stateflow_DW.temporalCounter_i1 < 7U) {
    Test_Stateflow_DW.temporalCounter_i1++;
  }

  if (Test_Stateflow_DW.is_active_c3_Test_Stateflow == 0U) {
    Test_Stateflow_DW.is_active_c3_Test_Stateflow = 1U;
    Test_Stateflow_DW.is_c3_Test_Stateflow = Test_Stateflow_IN_S1;
    Test_Stateflow_B.LED1 = 1.0;
    Test_Stateflow_B.LED2 = 0.0;
    Test_Stateflow_B.LED3 = 0.0;
  } else {
    switch (Test_Stateflow_DW.is_c3_Test_Stateflow) {
     case Test_Stateflow_IN_S1:
      if (Test_Stateflow_B.GPIO_Read == 1.0) {
        Test_Stateflow_DW.is_c3_Test_Stateflow = Test_Stateflow_IN_S2;
        Test_Stateflow_B.LED1 = 0.0;
        Test_Stateflow_B.LED2 = 1.0;
        Test_Stateflow_B.LED3 = 0.0;
      }
      break;

     case Test_Stateflow_IN_S2:
      if (Test_Stateflow_B.GPIO_Read == 0.0) {
        Test_Stateflow_DW.is_c3_Test_Stateflow = Test_Stateflow_IN_S3;
        Test_Stateflow_DW.temporalCounter_i1 = 0U;
        Test_Stateflow_B.LED1 = 0.0;
        Test_Stateflow_B.LED2 = 0.0;
        Test_Stateflow_B.LED3 = 1.0;
      }
      break;

     default:
      if (Test_Stateflow_DW.temporalCounter_i1 >= 4U) {
        Test_Stateflow_DW.is_c3_Test_Stateflow = Test_Stateflow_IN_S1;
        Test_Stateflow_B.LED1 = 1.0;
        Test_Stateflow_B.LED2 = 0.0;
        Test_Stateflow_B.LED3 = 0.0;
      }
      break;
    }
  }

  /* S-Function Block: <Root>/GPIO_Write */
  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_11, Test_Stateflow_B.LED1);
  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, Test_Stateflow_B.LED2);
  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, Test_Stateflow_B.LED3);

  /* S-Function Block: <Root>/GPIO_Write2 */
  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_7, Test_Stateflow_P.Constant1_Value);

  /* S-Function Block: <Root>/GPIO_Write1 */
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, Test_Stateflow_P.Constant2_Value);
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_14, Test_Stateflow_P.Constant2_Value);
}

/* Model initialize function */
void Test_Stateflow_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Test_Stateflow_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &Test_Stateflow_B), 0,
                sizeof(B_Test_Stateflow));

  /* states (dwork) */
  (void) memset((void *)&Test_Stateflow_DW, 0,
                sizeof(DW_Test_Stateflow));
  Test_Stateflow_DW.temporalCounter_i1 = 0U;
  Test_Stateflow_DW.is_active_c3_Test_Stateflow = 0U;
  Test_Stateflow_DW.is_c3_Test_Stateflow = Test_Stateflow_IN_NO_ACTIVE_CHILD;
}

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF] Test_Stateflow.c
 */
