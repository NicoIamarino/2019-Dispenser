/**********************************************/
/*    PRIMITIVAS PARA EL MANEJO DE TIMERS     */
/**********************************************/

/************* INCLUDES *************/
#include "PR_Timers.h"
/************ V.GLOBALES ************/
static TimerData  g_Timers[TIMERS];
static uint32_t   g_Milisegundos = 0;
static uint8_t    flagFinish = 0;
/************************************/
//Obtengo la cantidad de milisegundos desde que empezó el programa.
//Param:  void
//Return: Cantidad de milisegundos.
uint32_t getMilisegundos(void)
{
  return g_Milisegundos;
}
/************************************/
//Inicializa un timer (event) para que luego de (time) llame a (handler)
//Param:  EVENT   -> Número de timer [0-30]
//Param:  TIME    -> Tiempo para que venza el timer (en milisegundos).
//Param:  HANDLER -> Función a llamar cuando se venza el timer.
//Return: void
void TimerStart(uint8_t event, uint32_t time, TimerHandler handler)
{
  if(time)   //Si el tiempo no es cero
  {
    g_Timers[event].contador = time;

    g_Timers[event].estado = RUNNING;
  }
  else      //Si el tiempo pasado como parámetro es cero, no espero y llamo al handler directamente.
  {
    g_Timers[event].contador = 0;
    g_Timers[event].estado = OVERFLOW;
  }
  g_Timers[event].handler = handler;
}
/************************************/
//Finaliza un timer.
//Param:  EVENT   -> Número de timer [0-30]
//Return: void
void TimerStop(uint8_t event)
{
  g_Timers[event].contador = 0;
  g_Timers[event].estado = STOP;
  g_Timers[event].handler = NULL;
}
/************************************/
//Finaliza todos los timers.
//Param:  void
//Return: void
void TimerStopAll(void)
{
  uint8_t i;

  for(i=0; i<TIMERS; i++)
  {
    g_Timers[i].contador = 0;
    g_Timers[i].estado = STOP;
    g_Timers[i].handler = NULL;
  }
}
/************************************/
//Pausa un timer.
//Param:  EVENT   -> Número de timer [0-30]
//Param:  STATE   -> 1: Pausar
//                   0: Reanudar
//Return: void
void TimerPause(uint8_t event, uint8_t state)
{
  if(state)
  {
    g_Timers[event].estado = PAUSE;
  }
  else
  {
    g_Timers[event].estado = RUNNING;
  }
}
/************************************/
//Devuelve el tiempo restante de un timer
//Param:  EVENT   -> Número de timer [0-30]
//Return: void
uint32_t TimerCount(uint8_t event)
{
  return g_Timers[event].contador;
}
/************************************/
//Decremento periodico de los contadores
//Param:  void
//Return: void
void TimerCheck(void)
{
	uint32_t i;

	g_Milisegundos++;
	for(i=0;i<TIMERS;i++)
	{
		if(g_Timers[i].estado == RUNNING)
		{
			g_Timers[i].contador--;
			if(g_Timers[i].contador == 0)
				g_Timers[i].estado = OVERFLOW;
		}
	}
}
/************************************/
//Función a llamar en el main para que revise ciclicamente si se venció un timer
//Param:  void
//Return: void
void TimerEvent(void)
{
  uint8_t i;

  for(i=0;i<TIMERS;i++)
  {
    if(g_Timers[i].estado == OVERFLOW)
    {
      g_Timers[i].estado = STOP;
      g_Timers[i].handler();
    }
  }
}
/************************************/
//Función para hacer un delay bloqueante.
//Param:  void
//Return: void
void Delay(uint32_t milis)
{
  TimerStart(15, milis, DelayHandler);
  while(flagFinish != 1)
  {
    TimerEvent();
  }
  flagFinish = 0;
}
/************************************/
//Handler de la función Delay
//Param:  void
//Return: void
void DelayHandler(void)
{
  flagFinish = 1;
}

/************************************/
