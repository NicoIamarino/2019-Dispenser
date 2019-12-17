/**********************************************/
/*                MDE GENERAL                 */
/**********************************************/

#ifndef _PR_MDE_GENERAL_H_
#define _PR_MDE_GENERAL_H_

/************* INCLUDES *************/
#include "PR_Relays.h"
#include "PR_Display.h"
#include "PR_Key.h"
#include "PR_DS18B20.h"
#include "PR_Timers.h"
#include "PR_HCSR04.h"
#include "MdE_Temperatura.h"
/************* DEFINES **************/
#define STAND_BY	0
#define SIRVIENDO	1
#define CONSULTA 	2
#define EMERGENCIA	3

#define COCA 		1
#define FERNET		2

#define TIMER_FERNET 		3
#define TIMER_COCA  		4
#define TIMER_EMERGENCIA 	5
#define TIMER_LIQUIDO		6
/******** VARIABLES GLOBALES ********/
extern uint8_t tecla;
/************************************/
void MdE_General(void);
char* StringProporciones(void);
void servirCoca(void);
void finServir(void);
void emerHandler(void);
void insufHandler(void);
uint8_t Nivel(void);
uint8_t Temperatura(void);
/************************************/

#endif //_PR_MDE_GENERAL_H_


