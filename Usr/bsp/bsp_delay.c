#include "bsp_delay.h"

#include "stm32f1xx_hal.h"
    
uint8_t bsp_delayNonBlocking_ms(uint32_t ms){
    static uint32_t sysTick = 0;
    if(uwTick - sysTick < ms) return 0;
    sysTick = uwTick;
    return 1;
}
