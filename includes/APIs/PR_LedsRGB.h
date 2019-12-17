/**********************************************/
/*    PRIMITIVAS PARA EL MANEJO DE LOS LEDS   */
/**********************************************/

#ifndef _PR_LEDSRGB_H_
#define _PR_LEDSRGB_H_
/************* INCLUDES *************/
#include "DR_Pinsel.h"

/************* DEFINES *************/
/*  PUERTOS  */
#define PUERTO_LEDS 2

/*  PINES  */
#define PIN_AZUL 	1
#define PIN_VERDE	2
#define PIN_ROJO	3

/* COLORES */
#define AZUL 		1
#define VERDE		2
#define ROJO		3


/************************************/
//Inicializa los leds
//Param:  void
//Return: void
void InicializarLeds(void);
/************************************/
//PRENDE O APAGA LOS LEDS
//Param: MODO: ON/OFF
//		 COLOR: AZUL/ROJO/VERDE
//Return: Void
void LedsRGB(uint8_t color, uint8_t modo);
/************************************/

#endif //_PR_LEDSRGB_H_
