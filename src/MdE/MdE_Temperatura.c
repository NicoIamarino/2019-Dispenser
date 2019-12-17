/**********************************************/
/*             MDE TEMPERATURA                */
/**********************************************/

/************* INCLUDES *************/
#include "MdE_Temperatura.h"

uint8_t firstTimeFrio = 1;
uint8_t firstTimeEnfriando = 1;
/************************************/
void MdE_Temperatura(void)
{
  static uint8_t estado = ENFRIANDO;

	switch (estado)
	{
		case ENFRIANDO:
			if(firstTimeEnfriando)
			{
				Relays(3, ON);
				firstTimeEnfriando = 0;
			}
			if(temp < TEMP_MIN)
			{
				Relays(3,OFF);
				estado = FRIO;
			}
			break;

		case FRIO:
			if(firstTimeFrio)
			{
				Relays(3, OFF);
				firstTimeFrio = 0;
			}
			if(temp >= TEMP_MAX)
			{
				Relays(3, ON);
				estado = ENFRIANDO;
			}
			break;
	}
}
/************************************/
