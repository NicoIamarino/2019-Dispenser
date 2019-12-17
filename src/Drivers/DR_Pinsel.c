/**********************************************/
/*             DRIVERS PARA PINSEL            */
/**********************************************/

/************* INCLUDES *************/
#include "DR_Pinsel.h"
/************************************/
//Configura el registro PINSEL correspondiente para configurar el pin con la función requerida
//Param:  PORT      -> Puerto a configurar
//Param:  PIN       -> Pin a configurar
//Param:  VALUE     -> Valor del pin GPIO, puede ser:
/*                        -PINSEL_GPIO:   0x00
                          -PINSEL_FUNC1:  0x01
                          -PINSEL_FUNC2   0x02
                          -PINSEL_FUNC3   0x03
*/
//Return: Void
void SetPINSEL(uint8_t port, uint8_t pin, uint8_t mode)
{
  uint8_t pinselIndex;

  pinselIndex = port*2;

  if(pin >= 16)
  {
    pinselIndex++;
    pin-=16;
  }

  //Seteo los dos pines en 0, luego pongo en 1 el que necesite.
  PINSEL[pinselIndex] &= ~(0x03 << pin*2);
  PINSEL[pinselIndex] |= (mode << pin*2);
}
/************************************/
//Configuracion de GPIO como entrada o salida
//Param:  PORT      -> Puerto a configurar
//Param:  PIN       -> Pin a configurar
//Param:  DIR       -> Direccion del GPIO, puede ser GPIO_INPUT(0) o GPIO_OUTPUT(1)
//Return: void
void SetDIR(uint8_t port, uint8_t pin, uint8_t dir)
{
  uint32_t *dirPort = &GPIO[8*port];
  uint32_t mascara = 1<<pin;

  if(dir == GPIO_OUTPUT)
  {
    *dirPort |= mascara;
  }
  else
  {
    *dirPort &= ~(mascara);
  }
}
/************************************/
//Configura el registro PINMODE correspondiente para configurar el pin requerido
//Param:  PORT      -> Puerto a configurar
//Param:  PIN       -> Pin a configurar
//Param:  MODE      -> Función del pin. Puede ser:
/*                      -PINMODE_PULLUP:      0x00
                        -PINMODE_REPEAT:      0x01
                        -PINMODE_NONE:        0x02
                        -PINMODE_PULLDOWN:    0x03
*/
//Return: void
void SetPINMODE(uint8_t port, uint8_t pin, uint8_t mode)
{
  uint8_t pinmodeIndex;

  if(pin < 16)
  {
    pinmodeIndex = port*2;
  }
  else
  {
    pinmodeIndex = port*2 + 1;
    pin = pin - 16;
  }

  //Seteo los dos pines en 0, luego pongo en 1 el que necesite.
  PINMODE[pinmodeIndex] &= ~(0x03 << pin*2);
  PINMODE[pinmodeIndex] |= (mode << pin*2);
}

/************************************/
//Configura el registro PINMODE_OD correspondiente para configurar el pin requerido
//Param:  PORT      -> Puerto a configurar
//Param:  PIN       -> Pin a configurar
//Param:  MODE      -> Función del pin. Puede ser:
/*                      -PINMODE_OD_NORMAL:      	 0x00
                        -PINMODE_OD_OPEN_DRAIN:      0x01

*/
//Return: void
void SetPINMODE_OD(uint8_t port, uint8_t pin, uint8_t mode)
{
	  uint32_t *dirPort = PINMODE_OD + port;
	  uint32_t mascara = 1<<pin;

	  if(mode == 1)
	  {
	    *dirPort |= mascara;
	  }
	  else
	  {
	    *dirPort &= ~(mascara);
	  }
}
