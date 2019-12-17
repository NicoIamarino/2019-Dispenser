/**********************************************/
/*             MDE TEMPERATURA                */
/**********************************************/

#ifndef _PR_MDE_TEMPERATURA_H_
#define _PR_MDE_TEMPERATURA_H_

/************* INCLUDES *************/
#include "PR_Relays.h"
#include "PR_Display.h"
#include "PR_Key.h"
#include "PR_DS18B20.h"
/************* DEFINES **************/
#define FRIO 		0
#define ENFRIANDO 	1

#define TEMP_MAX			23
#define TEMP_MIN			19

extern uint8_t firstTimeFrio;
extern uint8_t firstTimeEnfriando;


void MdE_Temperatura(void);

#endif //_PR_MDE_TEMPERATURA_H_
