#ifdef __USE_CMSIS
#include "LPC17xx.h"
#endif

#include <cr_section_macros.h>
#include <stdint.h>
#include "defines.h"

//SE PUEDEN BORRAR DESPUÉS
#include "MdE_General.h"
#include "PR_Key.h"
#include "PR_Relays.h"
#include "PR_Inicializacion.h"
#include "PR_LedsRGB.h"
#include "PR_Display.h"
#include "PR_HCSR04.h"
#include "DR_Interrupciones.h"
#include "MdE_Temperatura.h"
#include "DR_Timers.h"
#include "DR_UART.h"


int main(void)
{
	Inicializacion();
	Buzzer(OFF);

	Display("ELIJA PROPORCION", PRIMERA_FILA);
	MdE_HCSR04 = ON;

	while(1)
	{

		RecibirTemperatura();
		MdE_Temperatura();
		MdE_General();
		MdE_HCSR04_Coca();
		TimerEvent();
		EsperarTransmision();

	}
	return 0;
}






