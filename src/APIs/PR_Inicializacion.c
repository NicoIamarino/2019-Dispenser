/**********************************************/
/*		PRIMITIVAS DE INICIALIZACION	      */
/**********************************************/

/************* INCLUDES *************/
#include "PR_Inicializacion.h"
/************************************/
//Función que setea todos los pines de la placa base
//Param:  void
//Return: void
void Inicializacion(void)
{
	/*  PLL  */
	InicializarPLL();

	/*  SYSTICK  */
	InicializarSystick(1000);
	
	/*  BUZZER  */
	InicializarBuzzer();

	/*  RELAYS  */
	InicializarRelays();

	/*  BOTONES  */
	InicializarBotones();

	/*  LEDS     */
	InicializarLeds();

	/* DISPLAY */
	InicializarDisplay();

	/* HCSR04 */
	InicializarHCSR04();

	/* INTERRUPCIÓN EXT HCSR04 */
	InicializarInterrupciones();

	/* DS18B20 */
	InicializacionDS18B20();

	/* UART1 */
	InicializarUART1();


}
/************************************/
