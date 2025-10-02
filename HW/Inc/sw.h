#ifndef __SW_H
#define __SW_H

#include "stm32f1xx_hal.h"

#define SW_GPIO GPIO_PIN_5
#define LED_GPIO GPIO_PIN_12

#define SW_IN HAL_GPIO_ReadPin(GPIOA, SW_GPIO)

void SW_Init(void);
uint8_t SW_Scan(uint8_t mode);
#endif 
