/**********************************************/
/*      DRIVERS PARA EL MANEJO DE BOTONES     */
/**********************************************/

#ifndef DR_KEY_H_
#define DR_KEY_H_

/************* INCLUDES *************/
#include <stdint.h>
#include <stddef.h>
#include "DR_GPIO.h"
#include "DR_Pinsel.h"
/************* VARIABLES GLOBALES *************/
extern uint8_t Tecla;
/************* DEFINES *************/
/*  BOTONES  */
#define NO_KEY    0
#define BOTON1    1
#define BOTON2    2
#define BOTON3    3
#define BOTON4    4
#define DEBOUNCE_COUNT 100

/*  PUERTOS  */
#define BOTON1_PORT     2
#define BOTON2_PORT     0
#define BOTON3_PORT     0
#define BOTON4_PORT     2

/*  PINES  */
#define BOTON1_PIN      10
#define BOTON2_PIN      18
#define BOTON3_PIN      11
#define BOTON4_PIN      13

uint8_t DriverTecladoHW( void );
void DriverTecladoSW(void);

#endif /* DR_KEY_H_ */
