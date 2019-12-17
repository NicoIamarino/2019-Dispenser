/**********************************************/
/*     DRIVERS PARA EL MANEJO DE SYSTICK      */
/**********************************************/

/************* INCLUDES *************/
#include "DR_Systick.h"

/************************************/
//Inicialización de Systick
//Param:  USEG 		-> Microsegundos
//Return: void
void InicializarSystick(uint32_t useg)
{
	STRELOAD = useg * 100 - 1;
	STCURR = 0;
	STCTRL = 0x00000007;
}
/************************************/
//Seteo la función que llama cuando se genera la interrupción
void SysTick_Handler(void)
{
	TimerCheck();
	DriverTecladoSW();
	if(bufferCount > 0 && bufferCount != BUFFER_TAM)
	{
		EscribirDisplay();
	}
	if(MdE_HCSR04==ON)
		medirCoca ++;

	contadorUART++;
	if(contadorUART == 2000){
		flag_uart=1;
		contadorUART=0;

	}
}
/************************************/
