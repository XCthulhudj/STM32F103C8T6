#include "bsp_tim.h"

#include "stm32f1xx_hal.h"

extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim2;

void bsp_tim_init(void){
  HAL_TIM_Base_Start_IT(&htim1);
  HAL_TIM_Base_Start(&htim1);

  HAL_TIM_Base_Start(&htim2);
  HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);
}

void bsp_tim_pwm_ccr(TIM_HandleTypeDef htim, uint32_t channel, uint32_t ccr){
  __HAL_TIM_SET_COMPARE(&htim, channel, ccr);
}
