/**********************************************/
/*    PRIMITIVAS PARA EL MANEJO DE RELAYS     */
/**********************************************/

#ifndef _PR_RELAYS_H_
#define _PR_RELAYS_H_

/************* INCLUDES *************/
#include <stdint.h>
#include "DR_GPIO.h"
#include "DR_Pinsel.h"
/************* DEFINES *************/
/*  RELAYS  */
#define RELAY1 1
#define RELAY2 2
#define RELAY3 3
#define RELAY4 4

/*  PUERTOS  */
#define RELAY1_PORT     2
#define RELAY2_PORT     0
#define RELAY3_PORT     0
#define RELAY4_PORT     0

/*  PINES  */
#define RELAY1_PIN      0
#define RELAY2_PIN      23
#define RELAY3_PIN      21
#define RELAY4_PIN      27
/************************************/
//Prende o apaga un relay.
//Param:  PORT      -> Puerto
//Param:  PIN       -> Pin
/*Param:  STATE     -> ON: 0
OFF: 1
//Return: void
*/
void Relays(uint8_t num, uint8_t state);
/************************************/
//Inicializa todos los relays
//Param:  void
//Return: void
void InicializarRelays(void);
/************************************/



#endif //_PR_RELAYS_H_
