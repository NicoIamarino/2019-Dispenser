/**********************************************/
/*    PRIMITIVAS PARA EL MANEJO DEL DISPLAY   */
/**********************************************/

#ifndef _PR_DISPLAY_H_
#define _PR_DISPLAY_H_

/************* INCLUDES *************/
#include <stdint.h>
#include <string.h>
#include "DR_GPIO.h"
#include "DR_Pinsel.h"
#include "PR_Timers.h"
#include "DR_Display.h"
/************* DEFINES *************/
#define MENSAJE_VACIO			  "                "
/* FILAS */
#define PRIMERA_FILA      0
#define SEGUNDA_FILA      1
/************************************/
void InicializarDisplay();
void ConfiguracionPinesDisplay(void);
void EscribirString(char* string);
void ClearDisplay();
void Display(char* string, uint8_t fila);
void Push(char dato, uint8_t msgType);

#endif //_PR_DISPLAY_H_
