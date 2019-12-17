#include "PR_UART.h"

extern uint8_t transmitiendo;
uint8_t TramaUART[10];
uint32_t contadorUART=0;
uint8_t flag_uart=0;
extern uint32_t temp;
extern uint32_t distance;
extern uint32_t distanceCoca;
extern uint8_t 	distanceFernet;

void PushTx(uint8_t dato)
{
	BufferTx[inTx] = dato;
	inTx++;
	bufferCountTx++;
	inTx %= BUFFER_TX_LEN;

	if(transmitiendo == 0) {
		U1THR = PopTx();
		transmitiendo = 1;
	}
}

void PushRx(uint8_t dato)
{
	if(dato != 255){
	BufferRx[inRx] = dato;
	inRx++;
	bufferCountRx++;
	inRx %= BUFFER_RX_LEN;
	}
}

uint8_t PopTx(void)
{
	int8_t aux = -1;

	if(bufferCountTx > 0)
	{
		aux = BufferTx[outTx];
		outTx++;
		bufferCountTx--;
		outTx %= BUFFER_TX_LEN;
	}
	return aux;
}

uint8_t PopRx(void)
{
	int8_t aux = - 1;

	if(bufferCountRx > 0)
	{
		aux = BufferRx[outRx];
		outRx++;
		bufferCountRx--;
		outRx %= BUFFER_RX_LEN;
	}
	return aux;
}

void Transmitir()
{

	for(uint8_t i=0; i<10; i++)
	{
		PushTx(TramaUART[i]);
	}

}

void EsperarTransmision()
{
	if(flag_uart==1)
	{
		construirTrama();
		Transmitir();
		flag_uart=0;
	}
}

void construirTrama(void)//,uint8_t temp, uint8_t nivelCoca, uint8_t nivelFernet)
{
	uint8_t i;
	uint8_t trama[10];

	uint8_t nivelCoca = (uint8_t)(20 - distanceCoca) * 100 / 15;
	uint8_t nivelFernet = (20 - distanceFernet) * 100 / 15;

	trama[0] = '#';
	trama[3] = ';';
	trama[6] = ';';
	trama[9] = '%';

	if(temp < 100)
	{
		trama[1] = (temp/10) + '0';
		trama[2] = (temp%10) + '0';
	}
	else
	{
		trama[1] = '9';
		trama[2] = '9';
	}

	if(nivelCoca < 100)
	{
		trama[4] = (nivelCoca/10) + '0';
		trama[5] = (nivelCoca%10) + '0';
	}
	else
	{
		trama[4] = '9';
		trama[5] = '9';
	}

	if(nivelFernet < 100)
	{
		trama[7] = (nivelFernet/10) + '0';
		trama[8] = (nivelFernet%10) + '0';
	}
	else
	{
		trama[7] = '9';
		trama[8] = '9';
	}

	for(i = 0; i < 10; i++)
	{
		TramaUART[i] = trama[i];
	}

	return;
}
