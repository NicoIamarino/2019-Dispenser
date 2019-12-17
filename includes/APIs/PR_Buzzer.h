/**********************************************/
/*    PRIMITIVAS PARA EL MANEJO DEL BUZZER    */
/**********************************************/

#ifndef _PR_BUZZER_H_
#define _PR_BUZZER_H_
/************* INCLUDES *************/
#include "DR_Pinsel.h"
#include <stdint.h>
/************* DEFINES *************/
/*  PUERTOS  */
#define BUZZER_PORT     0

/*  PINES  */
#define BUZZER_PIN      28
/************************************/
//PRENDE O APAGA EL BUZZER
//Param: STATE: ON/OFF
//Return: Void
void Buzzer(uint8_t state);
/************************************/
//Inicializa el buzzer
//Param:  void
//Return: void
void InicializarBuzzer(void);
/************************************/

#endif //_PR_BUZZER_H_
