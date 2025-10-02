#include "stm32f1xx_hal.h"
#include "stdio.h"
#include "sw.h"

void SW_Init(void)
{
	GPIO_InitTypeDef gpio;
	__HAL_RCC_GPIOA_CLK_ENABLE();
	gpio.Pin = SW_GPIO;
	gpio.Mode = GPIO_MODE_INPUT;
	gpio.Pull = GPIO_PULLDOWN;
	HAL_GPIO_Init(GPIOA, &gpio);
}

uint8_t SW_Scan(uint8_t mode)
{
	uint8_t result = SW_IN;
	if (result == 1) {
		result = SW_IN;
		if (result == 1) {
			for (int i = 0; i < 0x7FFF; i++) {
				result = SW_IN;
				if (result == 0) {
					return 0;
				}
			}
		}
		if (mode == 0) {
			return 8;
		}
	}
	return 0;
}
