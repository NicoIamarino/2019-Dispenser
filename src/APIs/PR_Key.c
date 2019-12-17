/**********************************************/
/*    PRIMITIVAS PARA EL MANEJO DE BOTONES    */
/**********************************************/

/************* INCLUDES *************/
#include "PR_Key.h"
/************************************/
//Devuelve el botón que fue presionado
//Param:  void
/*Return:   - NO_KEY:  0 -> No encontró ningún botón apretado
            - BOTON1:  1
            - BOTON2:  2
            - BOTON3:  3
            - BOTON4:  4
*/
uint8_t GetKey(void)
{
	uint8_t aux = NO_KEY;

	if (Tecla != NO_KEY )
	{
		aux = Tecla;
		Tecla = NO_KEY;
	}
	return aux;
}
/************************************/
//Inicializa todos los botones
//Param:  void
//Return: void
void InicializarBotones(void)
{
	//Boton 1
	SetPINSEL(BOTON1_PORT, BOTON1_PIN, 0);
	SetDIR(BOTON1_PORT, BOTON1_PIN, GPIO_INPUT);
	SetPINMODE(BOTON1_PORT, BOTON1_PIN, PINMODE_PULLUP);
	//Boton 2
	SetPINSEL(BOTON2_PORT, BOTON2_PIN, 0);
	SetDIR(BOTON2_PORT, BOTON2_PIN, GPIO_INPUT);
	SetPINMODE(BOTON2_PORT, BOTON2_PIN, PINMODE_PULLUP);
	//Boton 3
	SetPINSEL(BOTON3_PORT, BOTON3_PIN, 0);
	SetDIR(BOTON3_PORT, BOTON3_PIN, GPIO_INPUT);
	SetPINMODE(BOTON3_PORT, BOTON3_PIN, PINMODE_PULLUP);
	//Boton 4
	SetPINSEL(BOTON4_PORT, BOTON4_PIN,0);
	SetDIR(BOTON4_PORT, BOTON4_PIN,GPIO_INPUT);
	SetPINMODE(BOTON4_PORT, BOTON4_PIN,PINMODE_NONE);
}
/************************************/
