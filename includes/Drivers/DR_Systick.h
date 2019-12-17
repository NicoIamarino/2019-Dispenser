/**********************************************/
/*     DRIVERS PARA EL MANEJO DE SYSTICK      */
/**********************************************/

#ifndef _DR_SYSTICK_H_
#define _DR_SYSTICK_H_

/************* INCLUDES *************/
#ifdef __USE_CMSIS
#include "LPC17xx.h"
#endif

#include "PR_UART.h"
#include <stdint.h>
#include <cr_section_macros.h>
#include <stddef.h>
#include "DR_GPIO.h"
#include "DR_Pinsel.h"
#include "PR_Timers.h"
#include "defines.h"
#include "DR_Display.h"
#include "DR_Key.h"
/************* DEFINES *************/
/*  DIRECCIONES DE MEMORIA  */
#define STCTRL		*((volatile uint32_t *) 0xE000E010)
#define STRELOAD 	*((volatile uint32_t *) 0xE000E014)
#define STCURR	 	*((volatile uint32_t *) 0xE000E018)
#define STCALIB   	*((volatile uint32_t *) 0xE000E01C)
/************* TYPEDEF *************/
typedef void (*SystickCallback_t)(void);
/************************************/
//Inicialización de Systick
//Param:	USEG -> Microsegundos
//Return: void
void InicializarSystick(uint32_t useg);

#endif //_DR_SYSTICK_H_
