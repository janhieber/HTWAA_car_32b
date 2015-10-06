/*
 * File: Test_PWM_TIM.c
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
#include "Test_PWM_TIM.h"

/* TIM9 data information*/
TIM_DataLinkTypeDef TIM9_DataLink;

/* TIM9 polling timeout value. Number of Solver loop. (can be changed)*/
uint32_t G_TIM9_PollTimeOut = 10;
uint16_t G_NbTimConf = 0;              /* Number of configured TIMER*/

/* Array of TIMER data information */
TIM_DataLinkTypeDef* G_TIM_Data[6];
TIM_HandleTypeDef* G_TIM_Handler[6];

/*******************************************************************************
 * Function Name  : TIM9_Initialization
 * Description    : Initialization of TIM9
 * Input          : -
 *******************************************************************************/
void TIM9_Initialization(void)
{
  /*Store TIM9 data information and its handler */
  G_TIM_Data[G_NbTimConf] = &TIM9_DataLink;
  G_TIM_Handler[G_NbTimConf] = &htim9;
  G_NbTimConf++;                       /*Inc number of configured TIM */

  /*Store TIM information */
  TIM9_DataLink.TIM_Prescaler = 0;
  TIM9_DataLink.TIM_APBClock = 168000000;
  TIM9_DataLink.TIM_ARR = 168000;
  TIM9_DataLink.TIM_Clock = 1.68E+8;
  TIM9_DataLink.CH1_type = OUTPUT_PWM;
  TIM9_DataLink.CH2_type = UNKNOWN;
  TIM9_DataLink.CH3_type = UNKNOWN;
  TIM9_DataLink.CH4_type = UNKNOWN;
  TIM9_DataLink.ItUpFcn = NULL;
  TIM9_DataLink.ItTrgFcn = NULL;
  TIM9_DataLink.ItComFcn = NULL;
  TIM9_DataLink.ItBrkFcn = NULL;
  TIM9_DataLink.ItCcFcn = NULL;

  /*Update register value with blocset value*/
  /*Prescaler*/
  (&htim9)->Instance->PSC |= 0;

  /*Autoreload: ARR */
  __HAL_TIM_SetAutoreload(&htim9, 168000);

  /*Set CH1 Pulse value*/
  __HAL_TIM_SetCompare(&htim9, TIM_CHANNEL_1, (uint32_t)(168000/2));

  /* Wait for htim9 State READY */
  while ((&htim9)->State == HAL_TIM_STATE_BUSY) {
  }

  HAL_TIM_PWM_Start(&htim9, TIM_CHANNEL_1);
}

/* File trailer for Real-Time Workshop generated code.
 *
 * [EOF] Test_PWM_TIM.c
 */
