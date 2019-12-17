/**********************************************/
/*     DRIVERS PARA EL MANEJO DE TIMERS       */
/**********************************************/

#ifndef DR_TIMERS_H_
#define DR_TIMERS_H_

/************* INCLUDES *************/
#include <stdint.h>
#include <stddef.h>
#include "DR_Interrupciones.h"
#include "DR_PLL.h"
/************* DEFINES *************/
/* TIMERS EXTERNOS */
#define TIMER_EXT0 0
#define TIMER_EXT1 1
#define TIMER_EXT2 2
#define TIMER_EXT3 3

/*  DIRECCIONES DE MEMORIA  */
//!< 0x40004000UL : Direccion de inicio de los registros del Timer0
#define		TIMER0		((uint32_t *)0x40004000UL)
#define 	TIMER1		((uint32_t *)0x40008000UL)
#define 	TIMER2		((uint32_t *)0x40090000UL)
#define 	TIMER3		((uint32_t *)0x40094000UL)

/* REGISTROS TIMER EXT 1 */
#define		T1IR		TIMER1[0]
#define		T1TCR		TIMER1[1]
#define		T1TC		TIMER1[2]
#define		T1PR		TIMER1[3]
#define		T1PC		TIMER1[4]
#define		T1MCR		TIMER1[5]
#define		T1MR0		TIMER1[6]
#define		T1MR1		TIMER1[7]
#define		T1MR2		TIMER1[8]
#define		T1MR3		TIMER1[9]
#define		T1CCR		TIMER1[10]
#define		T1CR0		TIMER1[11]
#define		T1CR1		TIMER1[12]
#define		T1EMR		TIMER1[15]
#define		T1CTCR		TIMER1[28]

/* REGISTOS TIMER EXT 2 */
#define		T2IR		TIMER2[0]
#define		T2TCR		TIMER2[1]
#define		T2TC		TIMER2[2]
#define		T2PR		TIMER2[3]
#define		T2PC		TIMER2[4]
#define		T2MCR		TIMER2[5]
#define		T2MR0		TIMER2[6]
#define		T2MR1		TIMER2[7]
#define		T2MR2		TIMER2[8]
#define		T2MR3		TIMER2[9]
#define		T2CCR		TIMER2[10]
#define		T2CR0		TIMER2[11]
#define		T2CR1		TIMER2[12]
#define		T2EMR		TIMER2[15]
#define		T2CTCR		TIMER2[28]

/* REGISTOS TIMER EXT 3 */
#define		T3IR		TIMER3[0]
#define		T3TCR		TIMER3[1]
#define		T3TC		TIMER3[2]
#define		T3PR		TIMER3[3]
#define		T3PC		TIMER3[4]
#define		T3MCR		TIMER3[5]
#define		T3MR0		TIMER3[6]
#define		T3MR1		TIMER3[7]
#define		T3MR2		TIMER3[8]
#define		T3MR3		TIMER3[9]
#define		T3CCR		TIMER3[10]
#define		T3CR0		TIMER3[11]
#define		T3CR1		TIMER3[12]
#define		T3EMR		TIMER3[15]
#define		T3CTCR		TIMER3[28]
/************** TYPEDEF *************/
typedef void (*TimerHandler)(void);
/************************************/
void TimerStartUs(uint8_t timer,TimerHandler handler, uint32_t us);
/************************************/


#endif /* DR_TIMERS_H_ */
