#include "bsp_peripheral.h"
#include "bsp_usart.h"

void bsp_peripheral_init(void){
    bsp_tim_init();
    bsp_usart_init();
}
