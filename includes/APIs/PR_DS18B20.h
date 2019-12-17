/*************************************************************/
/*    INCLUDES PARA EL MANEJO DEL SENSOR DE TEMPERATURA DS18B20    */
/*************************************************************/

#ifndef _PR_DS18B20_H_
#define _PR_DS18B20_H_

/************* INCLUDES *************/
#include <stdint.h>
#include "DR_GPIO.h"
#include "DR_Pinsel.h"
#include "DR_Timers.h"
/************* DEFINES *************/
/* PUERTOS */
#define PUERTO_SENSOR 1

/* PINES */
#define PIN_SENSOR_SALIDA 	23
#define PIN_SENSOR_ENTRADA 	20

/* STATES */
#define SKIPROM			 0
#define CONVERT    		 1
#define READSCRATCH 	 2
#define RESET  			 0
#define ROM 			 1
#define ESPERANDO 		 3
#define FUNCION 		 4
#define RECEPCION 		 5


/************ V.GLOBALES ************/
extern uint32_t temp;
/************************************/

void Handler_Low(void);
uint8_t PonerLow(uint32_t );
uint8_t Comando( uint8_t );
void Esperar(uint32_t );
void Handler_Esperar(void);
uint8_t Leer(uint32_t);
uint32_t Conversor(void);
uint8_t * RecibirDatos(void);
void InicializacionDS18B20(void);
uint8_t Reset (void);
void RecibirTemperatura(void);

#endif //_PR_DS18B20_H_
