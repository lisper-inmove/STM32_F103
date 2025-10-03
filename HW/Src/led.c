#include "stm32f1xx_hal.h"
#include "led.h"

void LED_Init(void) {
    GPIO_InitTypeDef GPIO_InitType;
    // 使能 PCLK2(GPIOB)
    __HAL_RCC_GPIOB_CLK_ENABLE();
    
    // 0引脚配置
    GPIO_InitType.Pin = GPIO_PIN_0;
    // 推挽输出
    GPIO_InitType.Mode = GPIO_MODE_OUTPUT_PP;
    // GPIO_SPEED_FREQ_MEDIUM：中等速度。
    // GPIO_SPEED_FREQ_HIGH：高速。
    // GPIO_SPEED_FREQ_VERY_HIGH：非常高速。
    // 低速，降低电源消耗，响应时间较长
    GPIO_InitType.Speed = GPIO_SPEED_FREQ_LOW;

    HAL_GPIO_Init(GPIOB, &GPIO_InitType);

    // HAL_GPIO_WritePin(GPIOB, GPIO_PIN_0, GPIO_PIN_SET);
}
