/*************************************************************/
/*    PRIMITIVAS PARA EL MANEJO DEL SENSOR DE ULTRASONIDO    */
/*************************************************************/

#ifndef _PR_HCSR04_H_
#define _PR_HCSR04_H_

/************* INCLUDES *************/
#include <stdint.h>
#include <string.h>
#include "DR_GPIO.h"
#include "DR_Pinsel.h"
#include "DR_Timers.h"
#include "PR_Relays.h"
/************* DEFINES *************/
/* PUERTOS */
#define COCA_TRIGGER_PORT 		4
#define FERNET_TRIGGER_PORT 	0

/* PINES */
#define COCA_TRIGGER_PIN		28
#define FERNET_TRIGGER_PIN		19

/* STATES */
#define INIT					0
#define FINISH_ECHO				1

/* SENSORES */
#define HCSR04_COCA 			0
#define HCSR04_FERNET			1
/************ V.GLOBALES ************/
extern uint32_t distanceCoca;
extern uint8_t distanceFernet;
extern uint32_t medirCoca;
extern uint8_t mide;
extern uint8_t flagProxInterrupcion;
extern uint32_t finalTicksCoca;
extern uint32_t	finalTicksFernet;
extern uint8_t MdE_HCSR04;

/*********** PROTOTIPOS *************/
void InicializarHCSR04(void);
void MdE_HCSR04_Coca(void);
uint32_t convertTicksToMicrosegs(uint32_t ticks);
void setPinOff(void);

#endif //_PR_HCSR04_H_
