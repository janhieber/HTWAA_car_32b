#include "simulink_helper.h"

void beforeStep(void){
	// recv buffer
	uint8_t buf[1] = {0,};
	
	if (HAL_OK == HAL_SPI_Receive(&hspi4, buf, sizeof(buf), 10)) {
		// we only set input if data was received
		Test_SPI_U.In1 = buf[0];
	}
}

void afterStep(void){
	char buf[] = "step!\r\n";
	HAL_UART_Transmit(&huart1, (uint8_t *)buf, sizeof(buf), 10);
}
