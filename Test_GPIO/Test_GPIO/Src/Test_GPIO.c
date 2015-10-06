/*
 * File: Test_GPIO.c
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

#include "Test_GPIO.h"
#include "Test_GPIO_private.h"

/* Block signals (auto storage) */
B_Test_GPIO Test_GPIO_B;

/* Real-time model */
RT_MODEL_Test_GPIO Test_GPIO_M_;
RT_MODEL_Test_GPIO *const Test_GPIO_M = &Test_GPIO_M_;

/* Model step function */
void Test_GPIO_step(void)
{
  real_T tmp;

  /* S-Function Block: <Root>/STM32_Config */

  /* S-Function Block: <Root>/GPIO_Read */
  Test_GPIO_B.GPIO_Read_o1 = (boolean_T)HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_11);
  Test_GPIO_B.GPIO_Read_o2 = (boolean_T)HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_12);
  Test_GPIO_B.GPIO_Read_o3 = (boolean_T)HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_13);
  Test_GPIO_B.GPIO_Read_o4 = (boolean_T)HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_14);
  Test_GPIO_B.GPIO_Read_o5 = (boolean_T)HAL_GPIO_ReadPin(GPIOE, GPIO_PIN_15);
  Test_GPIO_B.LogicalOperator1 = ((Test_GPIO_B.GPIO_Read_o2 != 0) &&
    (Test_GPIO_B.GPIO_Read_o3 != 0));
  Test_GPIO_B.LogicalOperator2 = (Test_GPIO_B.GPIO_Read_o2 != 0) ^
    (Test_GPIO_B.GPIO_Read_o3 != 0);
  if (Test_GPIO_B.GPIO_Read_o4 == Test_GPIO_P.CompareToConstant_const) {
    Test_GPIO_B.Switch = Test_GPIO_B.GPIO_Read_o3;
  } else {
    tmp = floor(Test_GPIO_B.GPIO_Read_o5);
    if (rtIsNaN(tmp) || rtIsInf(tmp)) {
      tmp = 0.0;
    } else {
      tmp = fmod(tmp, 256.0);
    }

    Test_GPIO_B.Switch = (uint8_T)(tmp < 0.0 ? (int32_T)(uint8_T)-(int8_T)
      (uint8_T)-tmp : (int32_T)(uint8_T)tmp);
  }

  if (Test_GPIO_B.GPIO_Read_o5 == 1.0) {
    Test_GPIO_B.y = 0.0;
  } else {
    Test_GPIO_B.y = 1.0;
  }

  /* S-Function Block: <Root>/GPIO_Write */
  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_11, Test_GPIO_B.GPIO_Read_o1);
  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, Test_GPIO_B.LogicalOperator1);
  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, Test_GPIO_B.LogicalOperator2);
  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_14, Test_GPIO_B.Switch);
  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_15, Test_GPIO_B.y);

  /* S-Function Block: <Root>/GPIO_Write1 */
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, Test_GPIO_P.Constant1_Value);
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_14, Test_GPIO_P.Constant1_Value);

  /* S-Function Block: <Root>/GPIO_Write2 */
  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_7, Test_GPIO_P.Constant2_Value);
}

/* Model initialize function */
void Test_GPIO_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize error status */
  rtmSetErrorStatus(Test_GPIO_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &Test_GPIO_B), 0,
                sizeof(B_Test_GPIO));
}

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF] Test_GPIO.c
 */
