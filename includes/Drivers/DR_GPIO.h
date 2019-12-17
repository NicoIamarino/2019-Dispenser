/*************************************************/
/* DRIVERS PARA EL MANEJO DE LOS PINES DEL MICRO */
/*************************************************/

#ifndef _DR_GPIO_H_
#define _DR_GPIO_H_

/************* INCLUDES *************/
#include <stdint.h>
#include "defines.h"
/************* DEFINES *************/
/*  DIRECCIONES DE MEMORIA  */
#define GPIO          ((uint32_t*)0x2009C000)
/************************************/
//Setea un pin
//Param:  PORT      -> Puerto a configurar
//Param:  PIN       -> Pin a configurar
//Param:  VALUE     -> Valor del pin GPIO, puede ser 0 o 1
//Return: Void
void SetPIN(uint8_t port, uint8_t pin, uint8_t value);
/************************************/
//Lee el valor de un pin
//Param:  PORT      -> Puerto a configurar
//Param:  PIN       -> Pin a configurar
//Return: PIN VALUE -> Valor del pin GPIO, puede ser 0 o 1
uint32_t GetPIN(uint8_t port, uint8_t pin);
/************************************/

#endif  //_DR_GPIO_H_
