#ifndef BSP_TIM_H
#define BSP_TIM_H

#include "struct_typedef.h"

#include "stm32f1xx_hal.h"

void bsp_tim_init(void);
void bsp_tim_pwm_ccr(TIM_HandleTypeDef htim, uint32_t channel, uint32_t ccr);

#endif
