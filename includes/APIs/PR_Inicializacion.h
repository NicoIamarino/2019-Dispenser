/**********************************************/
/*		PRIMITIVAS DE INICIALIZACION	      */
/**********************************************/

#ifndef _PR_INICIALIZACION_H_
#define _PR_INICIALIZACION_H_

/************* INCLUDES *************/
#include <stdint.h>
#include "DR_Pinsel.h"
#include "DR_GPIO.h"
#include "DR_PLL.h"
#include "DR_Systick.h"
#include "PR_Buzzer.h"
#include "PR_Key.h"
#include "PR_Relays.h"
#include "PR_LedsRGB.h"
#include "PR_Display.h"
#include "DR_Timers.h"
#include "PR_HCSR04.h"
#include "PR_DS18B20.h"
#include "defines.h"
/************* DEFINES *************/

/************************************/
//Función que setea todos los pines de la placa base
//Param:  void
//Return: void
void Inicializacion(void);
/************************************/

#endif //_PR_INICIALIZACION_H_
