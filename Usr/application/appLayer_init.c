#include "appLayer_init.h"

#include "stm32f1xx_hal.h"

#include "timScheduler.h"
#include "usrDefine.h"

extern ScheduleTask scheduleTaskList[TASK_NUM];

static void task0(void const *argument);

void appLayer_init(void){
    /* Initialize the TIM task */
    scheduleTaskList[0].taskFunc = task0;
    scheduleTaskList[0].periodMs = 500;
    scheduleTaskList[0].lastRunTime = 0;
}

void taskScheduler_running(void){
    for(uint32_t i = 0; i < TASK_NUM; i++){
        if(scheduleTaskList[i].taskFunc == NULL) continue;
        if(scheduleTaskList[i].flagIRQ){
            scheduleTaskList[i].flagIRQ = 0;
            scheduleTaskList[i].taskFunc(NULL);
        }
    }
}

static void task0(void const *argument){
    HAL_GPIO_TogglePin(GPIOC, GPIO_PIN_13);
}
