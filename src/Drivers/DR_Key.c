/**********************************************/
/*      DRIVERS PARA EL MANEJO DE BOTONES     */
/**********************************************/

/************* INCLUDES *************/
#include "DR_Key.h"
/******** VARIABLES GLOBALES ********/
uint8_t Tecla;
/************************************/
//Funcion anti rebote (Software)
//Param:  void
//Return: void
void DriverTecladoSW(void)
{
	static uint8_t lastKey = NO_KEY;
	static uint8_t count = 0;
	uint8_t key;

	key = DriverTecladoHW();

	if( key == lastKey && count <= DEBOUNCE_COUNT)
	{
		if(count == DEBOUNCE_COUNT)
		{
			Tecla = key;
			count = 0;
		}
		count++;
	}
	else if(lastKey != key)
	{
		count = 0;
	}
	lastKey = key;
}
/************************************/
//Funcion anti rebote (Hardware)
//Param:  void
//Return: void
uint8_t DriverTecladoHW( void )
{
	if( !GetPIN( BOTON1_PORT , BOTON1_PIN ) )
		return BOTON1;

	if( !GetPIN( BOTON2_PORT , BOTON2_PIN ) )
		return BOTON2;

	if( !GetPIN( BOTON3_PORT , BOTON3_PIN ) )
		return BOTON3;

	if( !GetPIN( BOTON4_PORT , BOTON4_PIN ) )
		return BOTON4;

	return NO_KEY;
}
