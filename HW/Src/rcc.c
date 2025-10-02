#include "stm32f1xx_hal.h"
#include "rcc.h"

void RccClock_Init(void) {
    /**
     * 使用外部高速时钟源
     */
    RCC_OscInitTypeDef RCC_OscInitType;
    RCC_OscInitType.OscillatorType = RCC_OSCILLATORTYPE_HSE;
    // 启用外部高速时钟源
    RCC_OscInitType.HSEState = RCC_HSE_ON;
    RCC_OscInitType.HSEPredivValue = RCC_HSE_PREDIV_DIV1;

    // PLL倍频器
    // 启用PLL倍频
    RCC_OscInitType.PLL.PLLState = RCC_PLL_ON;
    // 使用外部高速
    RCC_OscInitType.PLL.PLLSource = RCC_PLLSOURCE_HSE;
    // PLLMUL 支持 2~16,SYSCLK最大为72MHz（该开发板外部为8M，所以使用9得到最大支持的72MHz）
    RCC_OscInitType.PLL.PLLMUL = RCC_PLL_MUL9;

    HAL_RCC_OscConfig(&RCC_OscInitType);

    // 总线时钟配置
    RCC_ClkInitTypeDef RCC_ClkInitType;
    // 需要配置哪些时钟
    RCC_ClkInitType.ClockType = RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2;
    // 系统时钟输入源
    RCC_ClkInitType.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
    RCC_ClkInitType.AHBCLKDivider = RCC_SYSCLK_DIV1;
    RCC_ClkInitType.APB1CLKDivider = RCC_HCLK_DIV2;
    RCC_ClkInitType.APB2CLKDivider = RCC_HCLK_DIV1;
    /**
     * 等待周期的作用是为了等待时钟源稳定
     * 0等待周期: 0 < SYSCLK <= 24MHz
     * 1等待周期: 24MHz < SYSCLK <= 48MHz
     * 2等待周期: 48MHz < SYSCLK <= 72MHz
     */
    HAL_RCC_ClockConfig(&RCC_ClkInitType, FLASH_LATENCY_2);
}
