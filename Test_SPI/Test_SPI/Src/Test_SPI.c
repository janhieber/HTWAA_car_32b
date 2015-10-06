/*
 * File: Test_SPI.c
 *
 * Code generated for Simulink model :Test_SPI.
 *
 * Model version      : 1.14
 * Simulink Coder version    : 8.6 (R2014a) 27-Dec-2013
 * TLC version       : 8.6 (Jan 30 2014)
 * C/C++ source code generated on  : Tue Oct 06 10:01:39 2015
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

#include "Test_SPI.h"
#include "Test_SPI_private.h"

/* Block signals (auto storage) */
B_Test_SPI Test_SPI_B;

/* External inputs (root inport signals with auto storage) */
ExtU_Test_SPI Test_SPI_U;

/* Real-time model */
RT_MODEL_Test_SPI Test_SPI_M_;
RT_MODEL_Test_SPI *const Test_SPI_M = &Test_SPI_M_;

/* Model step function */
void Test_SPI_step(void)
{
  /* S-Function Block: <Root>/STM32_Config */
  Test_SPI_B.Compare = (Test_SPI_U.In1 <= Test_SPI_P.CompareToConstant_const);
  Test_SPI_B.Compare_h = (Test_SPI_U.In1 > Test_SPI_P.CompareToConstant1_const);

  /* S-Function Block: <Root>/GPIO_Write */
  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_11, Test_SPI_B.Compare);
  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, Test_SPI_B.Compare_h);

  /* S-Function Block: <Root>/GPIO_Write2 */
  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_7, Test_SPI_P.Constant1_Value);

  /* S-Function Block: <Root>/GPIO_Write1 */
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, Test_SPI_P.Constant2_Value);
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_14, Test_SPI_P.Constant2_Value);
}

/* Model initialize function */
void Test_SPI_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Test_SPI_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &Test_SPI_B), 0,
                sizeof(B_Test_SPI));

  /* external inputs */
  Test_SPI_U.In1 = 0U;
}

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF] Test_SPI.c
 */
