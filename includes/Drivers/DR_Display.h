/**********************************************/
/*      DRIVERS PARA EL MANEJO DEL DISPLAY    */
/**********************************************/

#ifndef _DR_DISPLAY_H_
#define _DR_DISPLAY_H_
/************* INCLUDES *************/
#include <stdint.h>
#include <string.h>
#include "DR_GPIO.h"
#include "DR_Pinsel.h"
/************* DEFINES *************/
/* BIT (definir solamente uno de los dos) */
//#define LCD_8BIT
#define LCD_4BIT

/*  PUERTOS  */
#define LCD_ENABLE_PORT   0
#define LCD_RS_PORT       2
#define LCD_DB4_PORT      0
#define LCD_DB5_PORT      0
#define LCD_DB6_PORT      2
#define LCD_DB7_PORT      2

/*  PINES  */
#define LCD_ENABLE_PIN    4
#define LCD_RS_PIN        6
#define LCD_DB4_PIN       5
#define LCD_DB5_PIN       10
#define LCD_DB6_PIN       4
#define LCD_DB7_PIN       5

/* BUFFER CIRCULAR */
#define BUFFER_TAM 		  1024

/* INSTRUCCIONES */
#define INIT_INS1 0x30
#define INIT_INS2 0x20
#define INIT_INS3 0x28
#define INIT_INS4 0x08
#define INIT_INS5 0x06
#define INIT_INS6 0x0C
#define INS_CLEAR_DISPLAY         0x01  /* Limpia el display */
#define INS_RETURN_HOME           0x02  /* Vuelve el cursor al principio y mueve la pantalla al inicio si fue shifteada */
#define INS_PRIMER_FILA_POS_UNO   0x80  /* Vuelve el cursor al principio de la primer fila */
#define INS_SEGUNDA_FILA_POS_UNO  0xC0  /* Vuelve el cursor al principio de la segunda fila */

/*								       LETRAS MAYUSCULAS          ||  SIGNO PREGUNTA   ||      ESPACIO      ||      DIVISOR      ||    PORCENTAJE     ||       NUMEROS Y DOS PUNTOS         ||    	     LETRAS MINUSCULAS           */
#define IS_VISIBLE(caracter) ((caracter >= 65 && caracter <= 90 ) || (caracter == 63 ) || (caracter == 32 ) || (caracter == 47 ) || (caracter == 37 ) || (caracter >= 48 && caracter <= 58) || (caracter >= 97 && caracter <= 122 ))
/* TIPO DE MENSAJE */
#define INSTRUCCION 	  0
#define CARACTER 	  	  1
/*********** ESTRUCTURAS ***********/
typedef struct {
	char caracter;				//Instrucción o texto
	uint8_t TipoMensaje;		//1 = Texto, 0 = Instrucción.
} DisplayData;
/*********** VAR. GLOBALES **********/
extern uint8_t inDsp;
extern uint8_t outDsp;
extern uint8_t bufferCount;
extern DisplayData BufferDsp[BUFFER_TAM];
/************************************/
DisplayData Pop(void);
void EscribirDisplay(void);
void EscribirInstruccion(uint8_t data);


#endif //_DR_DISPLAY_H_
