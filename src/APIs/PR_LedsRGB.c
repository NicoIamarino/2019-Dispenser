/**********************************************/
/*    PRIMITIVAS PARA EL MANEJO DE LOS LEDS   */
/**********************************************/

/************* INCLUDES *************/
#include "PR_LedsRGB.h"
/************************************/
//Inicializa todos los puertos de leds
//Param:  void
//Return: void
void InicializarLeds(void)
{
	/*AZUL*/
	SetPINSEL(PUERTO_LEDS, PIN_AZUL, 0);
	SetDIR(PUERTO_LEDS, PIN_AZUL, GPIO_OUTPUT);
	SetPINMODE(PUERTO_LEDS, PIN_AZUL, PINMODE_PULLUP);
	SetPIN(PUERTO_LEDS, PIN_AZUL, OFF);

	/*ROJO*/
	SetPINSEL(PUERTO_LEDS, PIN_ROJO, 0);
	SetDIR(PUERTO_LEDS, PIN_ROJO, GPIO_OUTPUT);
	SetPINMODE(PUERTO_LEDS, PIN_ROJO, PINMODE_PULLUP);
	SetPIN(PUERTO_LEDS, PIN_ROJO, OFF);

	/*VERDE*/
	SetPINSEL(PUERTO_LEDS, PIN_VERDE, 0);
	SetDIR(PUERTO_LEDS, PIN_VERDE, GPIO_OUTPUT);
	SetPINMODE(PUERTO_LEDS, PIN_VERDE, PINMODE_PULLUP);
	SetPIN(PUERTO_LEDS, PIN_VERDE, OFF);

}

void LedsRGB(uint8_t color, uint8_t modo)
{
	SetPIN(PUERTO_LEDS,color,modo);
}
