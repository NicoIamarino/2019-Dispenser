/**********************************************/
/*    PRIMITIVAS PARA EL MANEJO DEL BUZZER    */
/**********************************************/

/************* INCLUDES *************/
#include "PR_Buzzer.h"
/************************************/
//PRENDE O APAGA EL BUZZER
//Param: STATE: ON/OFF
//Return: Void
void Buzzer(uint8_t state)
{
  if(!state)
  {
    SetPIN(BUZZER_PORT,BUZZER_PIN,ON);
  }
  else
  {
    SetPIN(BUZZER_PORT,BUZZER_PIN,OFF);
  }
}
/************************************/
//Inicializa el buzzer
//Param:  void
//Return: void
void InicializarBuzzer(void)
{
	SetPINSEL(BUZZER_PORT, BUZZER_PIN, 0);
	SetDIR(BUZZER_PORT, BUZZER_PIN, GPIO_OUTPUT);
	SetPINMODE(BUZZER_PORT, BUZZER_PIN, PINMODE_PULLUP);
	SetPIN(BUZZER_PORT, BUZZER_PIN, OFF);
}
/************************************/
