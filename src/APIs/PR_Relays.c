/**********************************************/
/*    PRIMITIVAS PARA EL MANEJO DE RELAYS     */
/**********************************************/

/************* INCLUDES *************/
#include "PR_Relays.h"
/************************************/
//Prende o apaga un relay.
//Param:  NUM: Número de Relay (1 a 4)
/*Param:  STATE:  - ON: 1
                  - OFF: 0
//Return: void
*/
void Relays(uint8_t num, uint8_t state)
{
  switch(num)
  {
    case RELAY1:
      SetPIN(RELAY1_PORT, RELAY1_PIN, state); //TODO SetPIN(RELAY1_PORT, RELAY1_PIN, state)
      break;
    case RELAY2:
      SetPIN(RELAY2_PORT, RELAY2_PIN, state);
      break;
    case RELAY3:
      SetPIN(RELAY3_PORT, RELAY3_PIN, state);
      break;
    case RELAY4:
      SetPIN(RELAY4_PORT, RELAY4_PIN, state);
      break;
  }
}
/************************************/
//Inicializa todos los relays
//Param:  void
//Return: void
void InicializarRelays(void)
{
	//Relay 1
	SetPINSEL(RELAY1_PORT, RELAY1_PIN, 0);
	SetDIR(RELAY1_PORT, RELAY1_PIN, GPIO_OUTPUT);
	SetPINMODE(RELAY1_PORT, RELAY1_PIN, PINMODE_NONE);
	SetPIN(RELAY1_PORT, RELAY1_PIN,OFF);

	//Relay 2
	SetPINSEL(RELAY2_PORT, RELAY2_PIN,0);
	SetDIR(RELAY2_PORT, RELAY2_PIN, GPIO_OUTPUT);
	SetPINMODE(RELAY2_PORT, RELAY2_PIN, PINMODE_NONE);
	SetPIN(RELAY2_PORT, RELAY2_PIN, OFF);

	//Relay 3
	SetPINSEL(RELAY3_PORT, RELAY3_PIN, 0);
	SetDIR(RELAY3_PORT, RELAY3_PIN, GPIO_OUTPUT);
	SetPINMODE(RELAY3_PORT, RELAY3_PIN, PINMODE_NONE);
	SetPIN(RELAY3_PORT, RELAY3_PIN, OFF);

	//Relay 4
	SetPINSEL(RELAY4_PORT, RELAY4_PIN, 0);
	SetDIR(RELAY4_PORT, RELAY4_PIN, GPIO_OUTPUT);
	SetPINMODE(RELAY4_PORT, RELAY4_PIN, PINMODE_NONE);
	SetPIN(RELAY4_PORT, RELAY4_PIN, OFF);
}
/************************************/
