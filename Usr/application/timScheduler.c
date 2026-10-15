#include "timScheduler.h"

#include "stm32f1xx_hal.h"

#include "usrDefine.h"

ScheduleTask scheduleTaskList[TASK_TIM_NUM] ={0};

static vuint32_t sysTickCounter = 0;

static void taskScheduler(void){
    sysTickCounter++;
    for(uint32_t i = 0; i < TASK_TIM_NUM; i++){
        if(scheduleTaskList[i].taskFunc == NULL) continue;
        if(sysTickCounter - scheduleTaskList[i].lastRunTime >= scheduleTaskList[i].periodMs){
            scheduleTaskList[i].lastRunTime = sysTickCounter;
            scheduleTaskList[i].flagIRQ = 1;
            // scheduleTaskList[i].taskFunc(NULL);
        }
    }
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim){
  if(htim->Instance == TIM1){
    /* 10ms interval */
    taskScheduler();
  }
}
