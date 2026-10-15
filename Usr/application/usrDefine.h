#ifndef USRDEFINE_H
#define USRDEFINE_H

/* Debug definitions */
#ifdef DEBUG

#endif

/* Memory for RAM */

/* mainStream, defined in "appLayer_init.c" */
//boxFlag
enum{
    BOF_RX1 = 0u,
    BOF_TX1 = 1u,
};

/* Task TIM definitions */
#define TASK_TIM_NUM 3u

enum{
    TASK_TIM_GPIO_PC13_INDEX = 0u,
    TASK_TIM_PWM_INDEX = 1u,
    TASK_TIM_TXRX_INDEX = 2u,
};

enum{
    TASK_TIM_NUM0 = TASK_TIM_GPIO_PC13_INDEX,
    TASK_TIM_NUM1 = TASK_TIM_PWM_INDEX,
    TASK_TIM_NUM2 = TASK_TIM_TXRX_INDEX,
};

#include "appLayer_init.h"
#include "timScheduler.h"
#include "bsp_peripheral.h"

#endif
