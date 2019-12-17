/**********************************************/
/*         DRIVERS PARA INTERRUPCIONES        */
/**********************************************/

/************* INCLUDES *************/
#include "DR_Interrupciones.h"
/************************************/
//Configura en ISER0 el bit correspondiente como 0 o 1 para habilitar la interrupción
//Param:  BIT       -> Bit a configurar
//Param:  MODO     	-> ON/OFF
//Return: void
void HabilitarInterrupcion(uint8_t bit, uint8_t mode)
{
	if(mode == ON)
		*ISER0 |= (1<<bit); //EN ISER 0 EXTMODE2_BIT es 20
	else
		*ISER0 &= ~(1<<bit);
}

/************************************/
//Inicializo las interrupciones
//Param:  void
//Return: void
void InicializarInterrupciones(void)
{
	/* LIMPIO LAS INTERRUPCIONES PENDIENTES */
	*EXTINT = (1 << 2);

	/* INICIALIZACIÓN GENERAL */
	SetPINSEL(EINT2_PORT, EINT2_PIN, PINSEL_FUNC1); //Configuro como EINT2
	SetDIR(EINT2_PORT, EINT2_PIN, GPIO_INPUT);
	SetPINMODE(EINT2_PORT, EINT2_PIN, PINMODE_NONE);

	/* CONFIGURACIÓN DE LA INTERRUPCIÓN EINT2 */
	SetEXTMOPO(EXTMODE2_BIT, FLANCO, ALTO);
	HabilitarInterrupcion(20, ON);
}
/************************************/
//Configura EXTMODE y EXTPOLAR para saber cuándo se dispara la interrupción
//Param:  BIT       -> 	0: EXTMODE0
/*						1: EXTMODE1
						2: EXTMODE2
						3: EXTMODE3
 */
//Param:  MODO     	-> 	0: NIVEL
//						1: FLANCO
//Param:  POLAR		-> 	0: BAJO/DESCENDENTE
//						1: ALTO/ASCENDENTE
//Return: void
void SetEXTMOPO(uint8_t bit, uint8_t mode,uint8_t polar)
{
	if(mode)
	{
		*EXTMODE |= (1<<bit);
	}
	else
	{
		*EXTMODE &= ~(1<<bit);
	}

	if(polar)
	{
		*EXTPOLAR |= (1<<bit);
	}
	else
	{
		*EXTPOLAR &= ~(1<<bit);
	}
}
/************************************/
//Interrupción externa
void EINT2_IRQHandler(void)
{
	//Si la interrupcion fue ASCENDENTE, disparo el timer de 10ms y reconfiguro la interrupcion como DESCENDENTE
	if(flagProxInterrupcion == ASCENDENTE)
	{
		TimerStartUs(2,dummyFunction, 10000000); //10 milisegundos
		SetEXTMOPO(EXTMODE2_BIT, FLANCO, DESCENDENTE);
		flagProxInterrupcion = DESCENDENTE;
	}
	else if(flagProxInterrupcion == DESCENDENTE)
	{
		finalTicksCoca = T2TC; 	//Guardo el contador del timer externo 2
    	T2TCR = 0x02;			// Apago y reseteo el timer
	}
	*EXTINT = (1 << 2);

}
/************************************/
void dummyFunction(void)
{

}
/************************************/
