/*
 * File: Test_PWM.c
 *
 * Code generated for Simulink model :Test_PWM.
 *
 * Model version      : 1.31
 * Simulink Coder version    : 8.6 (R2014a) 27-Dec-2013
 * TLC version       : 8.6 (Jan 30 2014)
 * C/C++ source code generated on  : Tue Oct 06 10:15:47 2015
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

#include "Test_PWM.h"
#include "Test_PWM_private.h"

/* Named constants for Chart: '<Root>/duty cycle calc' */
#define Test_PWM_IN_NO_ACTIVE_CHILD    ((uint8_T)0U)
#define Test_PWM_IN_S1                 ((uint8_T)1U)
#define Test_PWM_IN_S2                 ((uint8_T)2U)
#define Test_PWM_IN_S3                 ((uint8_T)3U)

/* Block signals (auto storage) */
B_Test_PWM Test_PWM_B;

/* Block states (auto storage) */
DW_Test_PWM Test_PWM_DW;

/* Real-time model */
RT_MODEL_Test_PWM Test_PWM_M_;
RT_MODEL_Test_PWM *const Test_PWM_M = &Test_PWM_M_;

/* Model step function */
void Test_PWM_step(void)
{
  /* S-Function Block: <Root>/STM32_Config */

  /* S-Function Block: <Root>/GPIO_Write2 */
  HAL_GPIO_WritePin(GPIOD, GPIO_PIN_7, Test_PWM_P.Constant1_Value);

  /* S-Function Block: <Root>/GPIO_Write1 */
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, Test_PWM_P.Constant2_Value);
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_14, Test_PWM_P.Constant2_Value);
  if (Test_PWM_DW.temporalCounter_i1 < 15U) {
    Test_PWM_DW.temporalCounter_i1++;
  }

  if (Test_PWM_DW.is_active_c3_Test_PWM == 0U) {
    Test_PWM_DW.is_active_c3_Test_PWM = 1U;
    Test_PWM_DW.is_c3_Test_PWM = Test_PWM_IN_S1;
    Test_PWM_DW.temporalCounter_i1 = 0U;
  } else {
    switch (Test_PWM_DW.is_c3_Test_PWM) {
     case Test_PWM_IN_S1:
      if (Test_PWM_DW.temporalCounter_i1 >= 10U) {
        Test_PWM_DW.is_c3_Test_PWM = Test_PWM_IN_S2;
        Test_PWM_DW.temporalCounter_i1 = 0U;
      } else {
        Test_PWM_B.duty = 5.0;
      }
      break;

     case Test_PWM_IN_S2:
      if (Test_PWM_DW.temporalCounter_i1 >= 10U) {
        Test_PWM_DW.is_c3_Test_PWM = Test_PWM_IN_S3;
        Test_PWM_DW.temporalCounter_i1 = 0U;
      } else {
        Test_PWM_B.duty = 20.0;
      }
      break;

     default:
      if (Test_PWM_DW.temporalCounter_i1 >= 10U) {
        Test_PWM_DW.is_c3_Test_PWM = Test_PWM_IN_S1;
        Test_PWM_DW.temporalCounter_i1 = 0U;
      } else {
        Test_PWM_B.duty = 80.0;
      }
      break;
    }
  }

  if (Test_PWM_B.duty < 0) {
    /* Disable output and complementary output */
    (&htim9)->Instance->BDTR |= TIM_BDTR_MOE;//MOE = 1
    (&htim9)->Instance->BDTR &= ~TIM_BDTR_OSSR;//OSSR = 0
    (&htim9)->Instance->CCER &= ~TIM_CCER_CC1E;//CC1E = 0
    (&htim9)->Instance->CCER &= ~TIM_CCER_CC1NE;//CC1NE = 0
    (&htim9)->Instance->CR2 &= ~TIM_CR2_OIS1;//OIS1 = 0
    (&htim9)->Instance->CR2 &= ~TIM_CR2_OIS1N;//OIS1N = 0
  } else {
    // Enable output and complementary output and update dutyCycle
    (&htim9)->Instance->BDTR |= TIM_BDTR_MOE;//MOE = 1
    (&htim9)->Instance->CCER |= TIM_CCER_CC1E;//CC1E = 1
    (&htim9)->Instance->CCER |= TIM_CCER_CC1NE;//CC1NE = 1

    // Channel1 duty cycle is an input port
    __HAL_TIM_SetCompare(&htim9, TIM_CHANNEL_1, (uint32_t)(Test_PWM_B.duty *
      (&htim9)->Instance->ARR / 100));
  }
}

/* Model initialize function */
void Test_PWM_initialize(void)
{
  /* Registration code */

  /* initialize error status */
  rtmSetErrorStatus(Test_PWM_M, (NULL));

  /* block I/O */
  (void) memset(((void *) &Test_PWM_B), 0,
                sizeof(B_Test_PWM));

  /* states (dwork) */
  (void) memset((void *)&Test_PWM_DW, 0,
                sizeof(DW_Test_PWM));

  /* user code (Start function Body) */

  /* TIM9 initialization */
  TIM9_Initialization();
  ;
  Test_PWM_DW.temporalCounter_i1 = 0U;
  Test_PWM_DW.is_active_c3_Test_PWM = 0U;
  Test_PWM_DW.is_c3_Test_PWM = Test_PWM_IN_NO_ACTIVE_CHILD;
}

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF] Test_PWM.c
 */
