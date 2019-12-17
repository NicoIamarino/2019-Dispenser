/**********************************************/
/*    PRIMITIVAS PARA EL MANEJO DE BOTONES    */
/**********************************************/

#ifndef _PR_KEY_H_
#define _PR_KEY_H_


/************* INCLUDES *************/
#include <stdint.h>
#include "DR_Key.h"
/******** VARIABLES GLOBALES ********/
extern uint8_t Tecla;
/************************************/
//Devuelve el botón que fue presionado
//Param:  void
/*Return:   - NO_KEY:  0 -> No encontró ningún botón apretado
- BOTON1:  1
- BOTON2:  2
- BOTON3:  3
- BOTON4:  4
*/
uint8_t GetKey(void);
/************************************/
//Inicializa todos los botones
//Param:  void
//Return: void
void InicializarBotones(void);
/************************************/

#endif //_PR_KEY_H_
