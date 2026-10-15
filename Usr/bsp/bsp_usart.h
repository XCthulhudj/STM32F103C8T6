#ifndef BSP_USART_H
#define BSP_USART_H

#include "struct_typedef.h"

void bsp_usart_init(void);
void bsp_DMAusart_init(void);

void bsp_usart_init_hal(void);
void bsp_usart_transmit_hal(uint8_t index);
void bsp_usart_receive_hal(uint8_t index);

void bsp_uart_transmit_blocking(const uint8_t *bufferTx, uint8_t len);
void bsp_uart_transmit_rxBuf_IT(void);

#endif
