#ifndef __SW_H
#define __SW_H

#include <stdint.h>

#define SW8_IN HAL_GPIO_ReadPin(GPIOC, GPIO_PIN_13)

void SW8_Init(void);
uint8_t SW8_Scan_DOWN(void);
uint8_t SW8_Scan_LONG_DOWN(void);
uint8_t SW8_Scan_UP(void);
uint8_t SW8_Scan_UP_DELAY(uint32_t delay);


#endif
