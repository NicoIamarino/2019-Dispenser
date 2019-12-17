/**********************************************/
/*         DRIVERS PARA INTERRUPCIONES        */
/**********************************************/

#ifndef _DR_INTERRUPCIONES_H_
#define _DR_INTERRUPCIONES_H_

/************* INCLUDES *************/
#include <stdint.h>
#include "DR_GPIO.h"
#include "DR_Pinsel.h"
#include "PR_HCSR04.h"
#include "DR_Timers.h"
#include "defines.h"
/************* DEFINES *************/
#define EINT0_PORT		2
#define EINT1_PORT		2
#define EINT2_PORT		2
#define EINT0_PIN 		10
#define EINT1_PIN		11
#define EINT2_PIN		12
#define EXTMODE0_BIT	0
#define EXTMODE1_BIT	1
#define EXTMODE2_BIT	2
#define EXTMODE3_BIT	3
#define NIVEL		 	0
#define FLANCO			1
#define ALTO			1
#define ASCENDENTE 		1
#define BAJO			0
#define DESCENDENTE 	0
/*  DIRECCIONES DE MEMORIA  */
#define ISER0 			((uint32_t*)0xE000E100)
#define EXTINT			((uint32_t*)0x400FC140)
#define EXTMODE 		((uint32_t*)0x400FC148)
#define EXTPOLAR		((uint32_t*)0x400FC14C)
/************************************/
void HabilitarInterrupcion(uint8_t bit, uint8_t mode);
void InicializarInterrupciones(void);
void SetEXTMOPO(uint8_t bit, uint8_t mode, uint8_t polar);
void dummyFunction(void);

#endif //_DR_INTERRUPCIONES_H_
