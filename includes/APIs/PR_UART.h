#ifndef PR_UART_H_
#define PR_UART_H_

#include "DR_UART.h"

extern uint8_t BufferTx[BUFFER_TX_LEN];// = {'A','T','+','R','S','T','\r','\n'};
extern uint8_t BufferRx[BUFFER_RX_LEN];

extern uint8_t inTx;
extern uint8_t inRx;
extern uint8_t outTx;
extern uint8_t outRx;
extern uint8_t bufferCountTx;
extern uint8_t bufferCountRx;
extern uint8_t flag_uart;
extern uint32_t contadorUART;

void Transmitir(void);
void construirTrama(void);



#endif /* PR_UART_H_ */
