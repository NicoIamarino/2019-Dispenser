#include "MdE_General.h"

/******** VARIABLES GLOBALES ********/
char* StringProporciones(void);
char StringFinal[6] = {0};
char nivelFernet = 3;
char nivelCoca = 7;
uint8_t tecla;
uint8_t state = STAND_BY;
uint8_t tiempoCoca;
uint8_t tiempoFernet;
/************************************/
void MdE_General(void)
{
	static uint8_t firstTime = 0;
	tecla = GetKey();

	switch(state)
	{
		case STAND_BY:
			/* SUBIR PROPORCION*/
			if(tecla == BOTON1)
			{
				if(nivelFernet <= 4)
				{
					nivelFernet += 1;
					nivelCoca = 10 - nivelFernet;
					Display(StringProporciones(), SEGUNDA_FILA);
				}
				else
				{
					Display("MAXIMO PERMITIDO", SEGUNDA_FILA);
				}
			}
			/* BAJAR PROPORCION*/
			if(tecla == BOTON2)
			{
				if(nivelFernet >= 2)
				{
					nivelFernet -= 1;
					nivelCoca = 10 - nivelFernet;
					Display(StringProporciones(), SEGUNDA_FILA);
				}
				else
				{
					Display("MINIMO PERMITIDO", SEGUNDA_FILA);
				}

			}
			/* SERVIR*/
			if(tecla == BOTON3)
			{
				if(Nivel())
				{
					if(Temperatura())
					{
						state = SIRVIENDO;
						firstTime = 1;
						Display("SIRVIENDO", PRIMERA_FILA);
						Display(MENSAJE_VACIO, SEGUNDA_FILA);
					}
					else
					{
						state = CONSULTA;
						Display("BEBIDA CALIENTE", PRIMERA_FILA);
						Display("CONTINUAR?", SEGUNDA_FILA);
					}
				}
				else
				{
					TimerStart(TIMER_LIQUIDO, 3000, insufHandler);
					Display("LIQUIDO", PRIMERA_FILA);
					Display("INSUFICIENTE", SEGUNDA_FILA);
					Relays(1,OFF);
					Relays(2,OFF);
				}
			}
			/* EMERGENCIA */
			if(tecla == BOTON4)
			{
				state = EMERGENCIA;
				TimerStart(TIMER_EMERGENCIA, 3000, emerHandler);
				Display("EMERGENCIA", PRIMERA_FILA);
				Display(MENSAJE_VACIO, SEGUNDA_FILA);
			}
			break;
		case SIRVIENDO:
			if(firstTime)
			{
				tiempoCoca = (50 * nivelCoca) / 10;
				tiempoFernet = 50 - tiempoCoca;

				Relays(RELAY1, ON);
				TimerStart(TIMER_FERNET, tiempoFernet * 1000, servirCoca);
				firstTime = 0;
			}

			if(tecla == BOTON4)
			{
				state = EMERGENCIA;
				TimerStart(TIMER_EMERGENCIA, 3000, emerHandler);
				Display("EMERGENCIA", PRIMERA_FILA);
				Display(MENSAJE_VACIO, SEGUNDA_FILA);
			}

			break;
		case CONSULTA:
			if(tecla == BOTON1)
			{
				state = SIRVIENDO;
				firstTime = 1;
				Display("SIRVIENDO", PRIMERA_FILA);
				Display(MENSAJE_VACIO, SEGUNDA_FILA);
			}
			if(tecla == BOTON2)
			{
				Display("ELIJA PROPORCION", PRIMERA_FILA);
				Display(MENSAJE_VACIO, SEGUNDA_FILA);
				Relays(1,OFF);
				Relays(2,OFF);
				state = STAND_BY;
				TimerStopAll();
			}
			if(tecla == BOTON4)
			{
				state = EMERGENCIA;
				TimerStart(TIMER_EMERGENCIA, 3000, emerHandler);
				Display("EMERGENCIA", PRIMERA_FILA);
				Display(MENSAJE_VACIO, SEGUNDA_FILA);
			}
			break;
		case EMERGENCIA:
			MdE_HCSR04 = OFF;
			Relays(1, OFF);
			Relays(2, OFF);
			Relays(3, OFF);
			Relays(4, OFF);
			break;
	}
}
/************************************/
void insufHandler(void)
{
	Display("ELIJA PROPORCION", PRIMERA_FILA);
	Display(MENSAJE_VACIO, SEGUNDA_FILA);
	TimerStopAll();
}
/************************************/
void emerHandler(void)
{
	Display("ELIJA PROPORCION", PRIMERA_FILA);
	state = STAND_BY;
	MdE_HCSR04 = ON;
	medirCoca = 0;
	firstTimeFrio = 1;
	firstTimeEnfriando = 1;
	TimerStopAll();
}
/************************************/
void servirCoca(void)
{
	Relays(RELAY1, OFF);
	Relays(RELAY2, ON);
	TimerStart(TIMER_COCA, tiempoCoca * 1500, finServir);
}
/************************************/
void finServir(void)
{
	Relays(RELAY2, OFF);
	Display("ELIJA PROPORCION", PRIMERA_FILA);
	state = STAND_BY;
	TimerStopAll();
}
/************************************/
uint8_t Nivel(void)
{
	int8_t distanciaCoca = distanceCoca;
	int8_t distanciaFernet = distanceFernet;
	int8_t nivelsitoCoca = nivelCoca;
	int8_t nivelsitoFernet = nivelFernet;

	int8_t aux1 = ((20-distanciaCoca)*10 - (nivelsitoCoca * 5));
	int8_t aux2 = ((20-distanciaFernet)*10 - (nivelsitoFernet * 5));
	if( aux1 > 0 && aux1 <= 200 && aux2 > 0 && aux2 <= 200)
		return 1;
	else
		return 0;
}
/************************************/
uint8_t Temperatura(void)
{
	if(temp <= TEMP_MAX && temp >= 0)
		return 1;
	else
		return 0;
}
/************************************/
char* StringProporciones(void)
{
	StringFinal[4] = StringFinal[1] = '0';
	StringFinal[2] = '/';
	StringFinal[0] = nivelFernet + 48;
	StringFinal[3] = nivelCoca + 48;
	StringFinal[5] = '\0';

	return StringFinal;
}
/************************************/

