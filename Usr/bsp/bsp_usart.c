#include "bsp_usart.h"

#include "stm32f1xx_hal.h"
#include "stm32f1xx_hal_uart.h"
#include "usrDefine.h"

#include <stdio.h>

#define UART1_FIXED_LEN 8u

extern UART_HandleTypeDef huart1;
extern DMA_HandleTypeDef hdma_usart1_rx;
extern DMA_HandleTypeDef hdma_usart1_tx;

static uint8_t uart1_rx_buf[UART1_FIXED_LEN];

void bsp_usart_init(void){
    /* First, enable the receive interrupt */
    __HAL_UART_ENABLE_IT(&huart1, UART_IT_RXNE);
    /* Enable the idle interrupt */
    __HAL_UART_CLEAR_IDLEFLAG(&huart1);
    __HAL_UART_ENABLE_IT(&huart1, UART_IT_IDLE);
}

void bsp_DMAusart_init(void){
    /* Just enable DMA */
    SET_BIT(huart1.Instance->CR3, USART_CR3_DMAR);
    __HAL_DMA_ENABLE(&hdma_usart1_rx);
    __HAL_DMA_ENABLE(&hdma_usart1_tx);

    __HAL_UART_CLEAR_IDLEFLAG(&huart1);
    __HAL_UART_ENABLE_IT(&huart1, UART_IT_IDLE);
}

void bsp_usart_init_hal(void){
    bsp_usart_transmit_hal(1);
    bsp_usart_receive_hal(1);
}

void bsp_usart_transmit_hal(uint8_t index){
    switch(index){
        case 1:
            HAL_UART_Transmit_IT(&huart1, (uint8_t *)"Hello World!\r\n", 14);
            break;
        default:
            break;
    }
}

void bsp_usart_receive_hal(uint8_t index){
    switch(index){
        case 1:
            HAL_UART_Receive_IT(&huart1, (uint8_t *)uart1_rx_buf, 8);
            break;
        default:
            break;
    }
}

void bsp_uart_transmit_blocking(const uint8_t *bufferTx, uint8_t len){
    for(uint8_t i = 0; i < len; i++){
        while((huart1.Instance->SR & UART_FLAG_TC) == 0);
        huart1.Instance->DR = bufferTx[i];
    }
}

void bsp_uart_transmit_rxBuf_IT(void){
    HAL_UART_Transmit_IT(&huart1, uart1_rx_buf, sizeof(uart1_rx_buf));
}

/* "Printf" redirected to USART1 */
int fputc(int ch, FILE *f){
    huart1.Instance->DR = ch;
    while((huart1.Instance->SR & UART_FLAG_TC) == 0);
    return ch;
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
    if(huart->Instance == USART1){
        mainStream.boxFlag[BOF_RX1] = 1;
        bsp_usart_receive_hal(1);
    }
}

void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart){
    if(huart->Instance == USART1){
        mainStream.boxFlag[BOF_TX1] = 1;
        // bsp_usart_transmit_hal(1);
    }
}
