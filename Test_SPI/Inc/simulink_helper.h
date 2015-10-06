#ifndef SIMULINK_HELPER
#define SIMULINK_HELPER

// includes
#include "stm32f4xx_hal.h"
#include "Test_SPI.h"                  /* Model's header file */

// extern vars
extern SPI_HandleTypeDef hspi4;
extern UART_HandleTypeDef huart1;

// prototypes
void beforeStep(void);
void afterStep(void);

#endif // SIMULINK_HELPER
