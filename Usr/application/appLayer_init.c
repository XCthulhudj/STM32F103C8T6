#include "appLayer_init.h"

#include "stm32f1xx_hal.h"

#include "usrDefine.h"

extern ScheduleTask scheduleTaskList[TASK_TIM_NUM];

volatile topLayer_t mainStream;

static void task0(void const *argument);
static void task1(void const *argument);
static void task2(void const *argument);

void appLayer_init(void){
    /* Initialize the GPIO PC13 task */
    scheduleTaskList[TASK_TIM_NUM0].taskFunc = task0;
    scheduleTaskList[TASK_TIM_NUM0].periodMs = 100;
    scheduleTaskList[TASK_TIM_NUM0].lastRunTime = 0;

    /* Initialize the TIM2 PWM task */
    scheduleTaskList[TASK_TIM_NUM1].taskFunc = task1;
    scheduleTaskList[TASK_TIM_NUM1].periodMs = 1;
    scheduleTaskList[TASK_TIM_NUM1].lastRunTime = 0;

    /* Initialize the TX RX task */
    scheduleTaskList[TASK_TIM_NUM2].taskFunc = task2;
    scheduleTaskList[TASK_TIM_NUM2].periodMs = 10;
    scheduleTaskList[TASK_TIM_NUM2].lastRunTime = 0;
}

void taskScheduler_running(void){
    for(uint32_t i = 0; i < TASK_TIM_NUM; i++){
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

static void task1(void const *argument){
    static uint16_t ccr = 0;
    static uint8_t dir = 0;

    if(ccr >= 999) dir = 1;
    else if(ccr <= 0) dir = 0;

    if(dir == 0) ccr++;
    else ccr--;

    TIM2->CCR1 = ccr;
}

static void task2(void const *argument){
    if(mainStream.boxFlag[BOF_RX1] == 1){
        mainStream.boxFlag[BOF_RX1] = 0;
        bsp_uart_transmit_rxBuf_IT();
    }
    if(mainStream.boxFlag[BOF_TX1] == 1){
        mainStream.boxFlag[BOF_TX1] = 0;

    }
}
