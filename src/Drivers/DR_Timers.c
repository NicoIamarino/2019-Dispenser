
/**********************************************/
/*     DRIVERS PARA EL MANEJO DE TIMERS       */
/**********************************************/


/************* INCLUDES *************/
#include "DR_Timers.h"
/*********** VAR. GLOBALES **********/
TimerHandler g_Timer1Handler = NULL;
TimerHandler g_Timer2Handler = NULL;
TimerHandler g_Timer3Handler = NULL;
/************************************/
//Inicializacion de timer externo
//Param:  tiempo en microsegs con el que va a interrumpir
//Return: void
void TimerStartUs(uint8_t timer,TimerHandler handler, uint32_t us)
{
	if(timer == TIMER_EXT1)
	{
		g_Timer1Handler = handler;

		PCONP |= 1 << 2; 				// Habilitar Timer 1

		PCLKSEL0 &= ~(0x03 << 4);		// PCLK = CCLK/4

		T1MR0 = 25*us;					// Configuro el tiempo del match 1

		T1MCR = 0x03;					// Match 0 resetea e interrumpe

		T1PR = 0;						// Prescaler en 0

		T1CTCR = 0;						// Funcionamiento como timer

		T1TCR = 0x02;					// Apago y reseteo el timer
		T1TCR = 0x01;					// Enciendo el timer

		T1IR |= 0x01;

		*ISER0 |= (1<<2); 				// Habilito interrupcion del Timer1 en el vector de interrupciones.
	}
	if(timer == TIMER_EXT2)
	{
		g_Timer2Handler = handler;

		PCONP |= 1 << 22; 				// Habilitar Timer 0

		PCLKSEL1 &= ~(0x03 << 12);		// PCLK = CCLK/4

		T2MR0 = 25*us;					// Configuro el tiempo del match 1

		T2MCR = 0x03;					// Match 0 resetea e interrumpe

		T2PR = 0;						// Prescaler en 0

		T2CTCR = 0;						// Funcionamiento como timer

		T2TCR = 0x02;					// Apago y reseteo el timer
		T2TCR = 0x01;					// Enciendo el timer

		T2IR |= 0x01;

		*ISER0 |= (1<<3); 					// Habilito interrupcion del Timer0 en el vector de interrupciones.

	}
	if(timer == TIMER_EXT3)
	{
		g_Timer3Handler = handler;

		PCONP |= 1 << 23; 				// Habilitar Timer 0

		PCLKSEL1 &= ~(0x03 << 14);		// PCLK = CCLK/4

		T3MR0 = 25*us;					// Configuro el tiempo del match 1

		T3MCR = 0x03;					// Match 0 resetea e interrumpe

		T3PR = 0;						// Prescaler en 0

		T3CTCR = 0;						// Funcionamiento como timer

		T3TCR = 0x02;					// Apago y reseteo el timer
		T3TCR = 0x01;					// Enciendo el timer

		T3IR |= 0x01;

		*ISER0 |= (1<<4); 					// Habilito interrupcion del Timer0 en el vector de interrupciones.
	}
}
/************************************/
void TIMER1_IRQHandler(void)
{
    if(T1IR & 0x01)					// Si interrumpio match 0
    {
    	T1IR |= 0x01;
    	g_Timer1Handler();
    	T1TCR = 0x02;              // Apago y reseteo el timer
    }
}
/************************************/
void TIMER2_IRQHandler(void)
{
    if(T2IR & 0x01)					// Si interrumpio match 0
    {
    	T2IR |= 0x01;
    	g_Timer2Handler();
    	T2TCR = 0x02;				// Apago y reseteo el timer
    }
}
/************************************/
void TIMER3_IRQHandler(void)
{
    if(T3IR & 0x01)					// Si interrumpio match 0
    {
    	T3IR |= 0x01;
    	g_Timer3Handler();
    	T3TCR = 0x02;				// Apago y reseteo el timer
    }
}
/************************************/
