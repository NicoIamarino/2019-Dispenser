/*************************************************************/
/*    PRIMITIVAS PARA EL MANEJO DEL SENSOR DE ULTRASONIDO    */
/*************************************************************/

/************* INCLUDES *************/
#include "PR_HCSR04.h"
/************ V.GLOBALES ************/
/* INDICAN CUÁL DE LOS DOS SENSORES ESTÁ MIDIENDO, NO SE PUEDEN USAR EN SIMULTÁNEO */
uint32_t 	medirCoca				= 0;
uint8_t 	mide					= 0;

/* GUARDA LOS TICKS FINALES CUANDO ECHO SE PONE EN 1 */
uint32_t	finalTicksCoca				= 0;
uint32_t	finalTicksFernet			= 0;

uint8_t 	flagProxInterrupcion 		= ASCENDENTE;
uint8_t 	MdE_HCSR04					= 0;

/* GUARDA LA DISTANCIA MEDIDA */
uint32_t 	distanceCoca 				= 0;
uint8_t 	distanceFernet 				= 0;
/************************************/
/* PARECE FUNCIONAR BIEN */
void InicializarHCSR04(void)
{
	/* TRIGGERS */
	SetPINSEL(COCA_TRIGGER_PORT, COCA_TRIGGER_PIN, 0);
	SetDIR(COCA_TRIGGER_PORT, COCA_TRIGGER_PIN, GPIO_OUTPUT);
	SetPINMODE(COCA_TRIGGER_PORT, COCA_TRIGGER_PIN, PINMODE_NONE);
	SetPIN(COCA_TRIGGER_PORT, COCA_TRIGGER_PIN, OFF);

	SetPINSEL(FERNET_TRIGGER_PORT, FERNET_TRIGGER_PIN, 0);
	SetDIR(FERNET_TRIGGER_PORT, FERNET_TRIGGER_PIN, GPIO_OUTPUT);
	SetPINMODE(FERNET_TRIGGER_PORT, FERNET_TRIGGER_PIN, PINMODE_NONE);
	SetPIN(FERNET_TRIGGER_PORT, FERNET_TRIGGER_PIN, OFF);
}
/************************************/
void MdE_HCSR04_Coca(void)
{
	static uint8_t state 				= INIT;
	static uint32_t finalTimeCoca		= 0;
	static uint32_t finalTimeFernet		= 0;

	if(medirCoca==500){
		Relays(4,ON);
	}

	if(medirCoca == 1000){
		mide=1;
	}

	if(medirCoca==1500){
		Relays(4,OFF);
	}


	if(medirCoca == 2000){
		mide=2;
		medirCoca = 0;
	}


	if(mide==1){
		switch(state)
		{
			case INIT:
						state = FINISH_ECHO;
						//Reconfiguro para que la próxima interrupción sea cuando ECHO se ponga en 1
						flagProxInterrupcion = ASCENDENTE;
						SetEXTMOPO(EXTMODE2_BIT, FLANCO, ASCENDENTE);

						SetPIN(COCA_TRIGGER_PORT, COCA_TRIGGER_PIN, OFF);
						SetPIN(COCA_TRIGGER_PORT, COCA_TRIGGER_PIN, ON);
						TimerStartUs(2, setPinOff, 10);
						break;

			case FINISH_ECHO:
						if(finalTicksCoca)
						{
							finalTimeCoca = convertTicksToMicrosegs(finalTicksCoca);
							finalTicksCoca = 0;
							distanceCoca = (finalTimeCoca / 58);
							state = INIT;
							mide=0;
						}
						break;
		}

	}




	if(mide==2){
		switch(state)
		{
			case INIT:
						state = FINISH_ECHO;
						//Reconfiguro para que la próxima interrupción sea cuando ECHO se ponga en 1
						flagProxInterrupcion = ASCENDENTE;
						SetEXTMOPO(EXTMODE2_BIT, FLANCO, ASCENDENTE);

						SetPIN(FERNET_TRIGGER_PORT, FERNET_TRIGGER_PIN, OFF);
						SetPIN(FERNET_TRIGGER_PORT, FERNET_TRIGGER_PIN, ON);
						TimerStartUs(2, setPinOff, 10);
						break;

			case FINISH_ECHO:
						if(finalTicksCoca)
						{
							finalTimeFernet = convertTicksToMicrosegs(finalTicksCoca);
							finalTicksCoca = 0;
							distanceFernet = (finalTimeFernet / 58);
							state = INIT;
							mide=0;
							medirCoca=0;
						}
						break;
		}

	}




}
/************************************/
uint32_t convertTicksToMicrosegs(uint32_t ticks)
{
	return (ticks/25);
}
/************************************/
void setPinOff(void)
{
	SetPIN(COCA_TRIGGER_PORT, COCA_TRIGGER_PIN, OFF);
	SetPIN(FERNET_TRIGGER_PORT, FERNET_TRIGGER_PIN, OFF);
}
