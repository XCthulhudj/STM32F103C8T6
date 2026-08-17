#include "bsp_tim.h"

#include "stm32f1xx_hal.h"

extern TIM_HandleTypeDef htim1;
extern TIM_HandleTypeDef htim2;

void bsp_tim_init(void){
  HAL_TIM_Base_Start_IT(&htim1);
  HAL_TIM_Base_Start_IT(&htim2);

  HAL_TIM_Base_Start(&htim1);
  HAL_TIM_Base_Start(&htim2);
}
