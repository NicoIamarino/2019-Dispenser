/**********************************************/
/*             DRIVERS PARA PINSEL            */
/**********************************************/

#ifndef _DR_PINSEL_H_
#define _DR_PINSEL_H_

/************* INCLUDES *************/
#include <stdint.h>
#include "DR_GPIO.h"
#include "defines.h"
/************* DEFINES *************/
/*  DIRECCIONES DE MEMORIA  */
#define PINSEL            ((uint32_t *) 0x4002C000)
#define PINMODE           ((uint32_t *) 0x4002C040)
#define PINMODE_OD		  ((uint32_t *) 0x4002C068)

/*  PINSEL  */
#define PINSEL_GPIO       0x00
#define PINSEL_FUNC1      0x01
#define PINSEL_FUNC2      0x02
#define PINSEL_FUNC3      0x03

/*  GPIO  */
#define GPIO_INPUT        0
#define GPIO_OUTPUT       1

/*  PINMODE  */
#define PINMODE_PULLUP    0x00
#define PINMODE_REPEAT    0x01
#define PINMODE_NONE      0x02
#define PINMODE_PULLDOWN  0x03
/************************************/
//Configura el registro PINSEL correspondiente para configurar el pin con la función requerida
//Param:  PORT      -> Puerto a configurar
//Param:  PIN       -> Pin a configurar
//Param:  VALUE     -> Valor del pin GPIO, puede ser:
/*                        -PINSEL_GPIO:   0x00
-PINSEL_FUNC1:  0x01
-PINSEL_FUNC2:  0x02
-PINSEL_FUNC3:  0x03
*/
//Return: Void
void SetPINSEL(uint8_t port, uint8_t pin, uint8_t mode);
/************************************/
//Configuracion de GPIO como entrada o salida
//Param:  PORT      -> Puerto a configurar
//Param:  PIN       -> Pin a configurar
//Param:  DIR       -> Direccion del GPIO, puede ser GPIO_INPUT(0) o GPIO_OUTPUT(1)
//Return: void
void SetDIR(uint8_t port, uint8_t pin, uint8_t dir);
/************************************/
//Configura el registro PINMODE correspondiente para configurar el pin requerido
//Param:  PORT      -> Puerto a configurar
//Param:  PIN       -> Pin a configurar
//Param:  MODE      -> Función del pin. Puede ser:
/*                      -PINMODE_PULLUP:      0x01
-PINMODE_REPEAT:      0x02
-PINMODE_NONE:        0x03
-PINMODE_PULLDOWN:    0x03
*/
//Return: void
void SetPINMODE(uint8_t port, uint8_t pin, uint8_t mode);
/************************************/
//Configura el registro PINMODE_OD correspondiente para configurar el pin requerido
//Param:  PORT      -> Puerto a configurar
//Param:  PIN       -> Pin a configurar
//Param:  MODE      -> Función del pin. Puede ser:
/*                     -PINMODE_OD_NORMAL:      	 0x00
                       -PINMODE_OD_OPEN_DRAIN:      0x01
*/
//Return: void
void SetPINMODE_OD(uint8_t port, uint8_t pin, uint8_t mode);
/************************************/

#endif //_DR_PINSEL_H_
