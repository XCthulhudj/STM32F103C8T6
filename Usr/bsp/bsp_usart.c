#include "bsp_usart.h"

#include "stm32f103xb.h"
#include "stm32f1xx_hal.h"
#include "stm32f1xx_hal_dma.h"
#include "stm32f1xx_hal_uart.h"

extern UART_HandleTypeDef huart1;
extern DMA_HandleTypeDef hdma_usart1_rx;
extern DMA_HandleTypeDef hdma_usart1_tx;

void bsp_usart_init(void){
    __HAL_UART_ENABLE_IT(&huart1, UART_IT_RXNE);

    __HAL_UART_CLEAR_IDLEFLAG(&huart1);
    __HAL_UART_ENABLE_IT(&huart1, UART_IT_IDLE);
}

void bsp_DMAusart_init(void){
    SET_BIT(huart1.Instance->CR3, USART_CR3_DMAR);
    __HAL_DMA_ENABLE(&hdma_usart1_rx);
    __HAL_DMA_ENABLE(&hdma_usart1_tx);

    __HAL_UART_CLEAR_IDLEFLAG(&huart1);
    __HAL_UART_ENABLE_IT(&huart1, UART_IT_IDLE);
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
    
}

void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart){

}
