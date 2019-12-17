#include "DR_UART.h"
#include "DR_Interrupciones.h"
#include "DR_PLL.h"

uint8_t BufferTx[BUFFER_TX_LEN];// = {'A','T','+','R','S','T','\r','\n'};
uint8_t BufferRx[BUFFER_RX_LEN];

uint8_t inTx = 0;
uint8_t inRx = 0;
uint8_t outTx = 0;
uint8_t outRx = 0;
uint8_t bufferCountTx = 0;
uint8_t bufferCountRx = 0;

uint8_t transmitiendo = 0;
uint8_t largoTrama = 0;

uint8_t datoRecepcUART0, datoRecepcUART1;

void InicializarUART0 (void)
{
	PCONP |= 0x01 << 3;

	PCLKSEL0 &= ~(0x03 << 6); //25 mhz

	U0LCR = 0x00000083;

	U0DLM = 0;
	U0DLL = 0xA3;

	SetPINSEL(0, 2, 1);

	SetPINSEL(0, 3, 1);

	U0LCR = 0x03;

	U0IER = 0x03;
	*ISER0 |= (1 << 5);

}


void InicializarUART1 (void)
{
	PCONP |= 0x01 << 4;

	PCLKSEL0 &= ~(0x03 << 8); //25 mhz

	U1LCR = 0x00000083;

	U1DLM = 0;
	U1DLL = 0x0E;

	SetPINSEL(0, 15, 1);

	SetPINSEL(0, 16, 1);

	U1LCR = 0x03;

	U1IER = 0x03;
	*ISER0 |= (1 << 6);

}

void UART0_IRQHandler(void)
{
	uint8_t aux, datoEnvio;
	do{
		aux = U0IIR;

		if (aux & 0x04)
		{
			datoRecepcUART0 = U0RBR;
			PushRx(datoRecepcUART0);
		}
		else if (aux & 0x02) //envia
		{
			datoEnvio = PopTx();
			if (datoEnvio != -1) {
				U1THR = datoEnvio;
			}
		}
	}while(!(aux & 0x01));

}

void UART1_IRQHandler(void)
{

	uint8_t aux, datoEnvio;
	do{
		aux = U1IIR;

		if (aux & 0x04) //recibe
		{
			datoRecepcUART1 = U1RBR;
			PushRx(datoRecepcUART1);

		}
		else if (aux & 0x02) //envia
		{
			if(largoTrama < 10){
				datoEnvio = PopTx();
				if (datoEnvio != -1 )
				{
					U1THR = datoEnvio;
					largoTrama++;
				}

			}
			else
			{
				transmitiendo = 0;
				largoTrama = 0;
			}
		}
	}while(!(aux & 0x01));

}
