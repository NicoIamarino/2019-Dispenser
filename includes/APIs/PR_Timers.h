/**********************************************/
/*    PRIMITIVAS PARA EL MANEJO DE TIMERS     */
/**********************************************/

#ifndef _PR_TIMERS_H_
#define _PR_TIMERS_H_
/************* INCLUDES *************/
#include <stddef.h>
#include "DR_Timers.h"
/************* DEFINES *************/
#define STOP      1
#define PAUSE     2
#define RUNNING   3
#define OVERFLOW  4
#define TIMERS    16
#define PAUSA     1
#define REANUDAR  0
/************* TYPEDEF *************/
typedef void (*TimerHandler)(void);
/*********** ESTRUCTURAS ***********/
typedef struct {
	uint32_t contador;
	uint8_t  estado;
	TimerHandler handler;
} TimerData;
/************************************/
uint32_t getMilisegundos(void);
void TimerStart(uint8_t event, uint32_t time, TimerHandler handler);
void TimerStop(uint8_t event);
void TimerStopAll(void);
void TimerPause(uint8_t event, uint8_t state);
uint32_t TimerCount(uint8_t event);
void TimerCheck(void);
void TimerEvent(void);
void Delay(uint32_t milis);
void DelayHandler(void);
uint32_t getMicrosecs(void);

/************************************/

#endif //_PR_TIMERS_H_
