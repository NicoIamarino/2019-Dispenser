/*************************************************/
/* DRIVERS PARA EL MANEJO DE LOS PINES DEL MICRO */
/*************************************************/

/************* INCLUDES *************/
#include "DR_GPIO.h"
/************************************/
//Setea un pin
//Param:  PORT      -> Puerto a configurar
//Param:  PIN       -> Pin a configurar
//Param:  VALUE     -> Valor del pin GPIO, puede ser 0 o 1
//Return: void
void SetPIN(uint8_t port, uint8_t pin, uint8_t value)
{
	if(value)
	{
	  GPIO[8*port + 5] |= (1<<pin);

	}
	else
	{
	  GPIO[8*port + 5] &= ~(1<<pin);
	}
}
/************************************/
//Lee el valor de un pin
//Param:  PORT      -> Puerto a configurar
//Param:  PIN       -> Pin a configurar
//Return: PIN VALUE -> Valor del pin GPIO, puede ser 0 o 1*/


//lo corro al cero y lo RECOJO
uint32_t GetPIN(uint8_t port, uint8_t pin)
{
  return ((GPIO[8*port + 5] >> pin) & 0x01);
}
/************************************/
