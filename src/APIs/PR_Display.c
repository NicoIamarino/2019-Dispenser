/**********************************************/
/*    PRIMITIVAS PARA EL MANEJO DEL DISPLAY   */
/**********************************************/

/************* INCLUDES *************/
#include "PR_Display.h"
/************************************/
//Limpia la pantalla del display
//Param:	void
//Return:   void
void InicializarDisplay()
{
	uint32_t i;
	for(i=0; i<BUFFER_TAM;i++)
	{
		BufferDsp[i].caracter = '\0';
	}

	ConfiguracionPinesDisplay();
#define INIT_INS1 0x30
#define INIT_INS2 0x20
#define INIT_INS3 0x28
#define INIT_INS4 0x08
#define INIT_INS5 0x06
#define INIT_INS6 0x0C

	Delay(15);
	EscribirInstruccion(INIT_INS1);
	Delay(5);
	EscribirInstruccion(INIT_INS1);
	Delay(1);
	EscribirInstruccion(INIT_INS1);
	Delay(1);
	EscribirInstruccion(INIT_INS2);
	Delay(1);
	EscribirInstruccion(INIT_INS3); //Function Set Instruction: Seteo la interfaz, numero de líneas y fuente
	Delay(1);
	EscribirInstruccion(INIT_INS4); //Display On/Off Control instruction: Apago el display
	Delay(1);
	EscribirInstruccion(INS_CLEAR_DISPLAY); //Clear Display Instruction
	Delay(3);
	EscribirInstruccion(INIT_INS5); //Entry Mode Set instruction (DB6: I/D(1 = Izq a derecha, 0 = Derecha a izq), DB7: Shift).
	//Esta instrucción determina la forma en que el cursor y el display se mueve cuando introduzco un string.
	Delay(1);
	EscribirInstruccion(INIT_INS6); //Display On/Off Control instruction: Enciendo el display
}
/************************************/
//Configura los pines en la inicializacion del display
//Param:
//Return: Void
void ConfiguracionPinesDisplay(void)
{
  //PIN ENABLE
  SetPINSEL(LCD_ENABLE_PORT, LCD_ENABLE_PIN, 0);
  SetDIR(LCD_ENABLE_PORT, LCD_ENABLE_PIN, GPIO_OUTPUT);
  SetPINMODE(LCD_ENABLE_PORT, LCD_ENABLE_PIN, PINMODE_NONE);

  //PIN RS
  SetPINSEL(LCD_RS_PORT, LCD_RS_PIN, 0);
  SetDIR(LCD_RS_PORT, LCD_RS_PIN, GPIO_OUTPUT);
  SetPINMODE(LCD_RS_PORT, LCD_RS_PIN, PINMODE_NONE);

  //PIN DB4
  SetPINSEL(LCD_DB4_PORT, LCD_DB4_PIN, 0);
  SetDIR(LCD_DB4_PORT, LCD_DB4_PIN, GPIO_OUTPUT);
  SetPINMODE(LCD_DB4_PORT, LCD_DB4_PIN, PINMODE_NONE);
  //PIN D5
  SetPINSEL(LCD_DB5_PORT, LCD_DB5_PIN, 0);
  SetDIR(LCD_DB5_PORT, LCD_DB5_PIN, GPIO_OUTPUT);
  SetPINMODE(LCD_DB5_PORT, LCD_DB5_PIN, PINMODE_NONE);
  //PIN D6
  SetPINSEL(LCD_DB6_PORT, LCD_DB6_PIN, 0);
  SetDIR(LCD_DB6_PORT, LCD_DB6_PIN, GPIO_OUTPUT);
  SetPINMODE(LCD_DB6_PORT, LCD_DB6_PIN, PINMODE_NONE);
  //PIN D7
  SetPINSEL(LCD_DB7_PORT, LCD_DB7_PIN, 0);
  SetDIR(LCD_DB7_PORT, LCD_DB7_PIN, GPIO_OUTPUT);
  SetPINMODE(LCD_DB7_PORT, LCD_DB7_PIN, PINMODE_NONE);
}
/************************************/

//Escribe un string en el display
//Param: STRING -> Mensaje a escribir
//Return: Void
void EscribirString(char* string)
{
  uint8_t i;

  for(i=0; i<strlen(string) ; i++)
  {
    Push(string[i], CARACTER);
  }

}
//Limpia la pantalla del display
//Param:
//Return: Void
void ClearDisplay()
{
  SetPIN(LCD_RS_PORT, LCD_RS_PIN, 0); //0 = "Instruction Register"
  SetPIN(LCD_ENABLE_PORT, LCD_ENABLE_PIN, 0);

  Push(INS_CLEAR_DISPLAY, INSTRUCCION);
  Push(INS_RETURN_HOME, INSTRUCCION);

  SetPIN(LCD_ENABLE_PORT, LCD_ENABLE_PIN, 1);
  SetPIN(LCD_ENABLE_PORT, LCD_ENABLE_PIN, 0);
}
/************************************/
//Escribe TEXTO en el display
//Param: STRING -> Texto a imprimir, debe ser más chico que 16 caracteres
//Param: fila -> Fila del display a escribir
//Return: Void
void Display(char* string, uint8_t fila)
{
  if(fila == PRIMERA_FILA && strlen(string) <= 16)
  {
    SetPIN(LCD_ENABLE_PORT, LCD_ENABLE_PIN, 0);
    Push(INS_PRIMER_FILA_POS_UNO, INSTRUCCION);

    EscribirString(MENSAJE_VACIO);

    SetPIN(LCD_ENABLE_PORT, LCD_ENABLE_PIN, 1);
	SetPIN(LCD_ENABLE_PORT, LCD_ENABLE_PIN, 0);

	Push(INS_PRIMER_FILA_POS_UNO, INSTRUCCION);
	EscribirString(string);

    SetPIN(LCD_ENABLE_PORT, LCD_ENABLE_PIN, 1);
    SetPIN(LCD_ENABLE_PORT, LCD_ENABLE_PIN, 0);
  }
  else if(fila == SEGUNDA_FILA && strlen(string) <= 16)
  {
	  SetPIN(LCD_ENABLE_PORT, LCD_ENABLE_PIN, 0);
	  Push(INS_SEGUNDA_FILA_POS_UNO, INSTRUCCION);

	  EscribirString(MENSAJE_VACIO);

	  SetPIN(LCD_ENABLE_PORT, LCD_ENABLE_PIN, 1);
	  SetPIN(LCD_ENABLE_PORT, LCD_ENABLE_PIN, 0);

	  Push(INS_SEGUNDA_FILA_POS_UNO, INSTRUCCION);

	  EscribirString(string);

	  SetPIN(LCD_ENABLE_PORT, LCD_ENABLE_PIN, 1);
	  SetPIN(LCD_ENABLE_PORT, LCD_ENABLE_PIN, 0);
  }
  else
  {
    SetPIN(LCD_ENABLE_PORT, LCD_ENABLE_PIN, 0);
    Push(INS_CLEAR_DISPLAY, INSTRUCCION);
    Push(INS_PRIMER_FILA_POS_UNO, INSTRUCCION);

    EscribirString("ERROR");

    SetPIN(LCD_ENABLE_PORT, LCD_ENABLE_PIN, 1);
    SetPIN(LCD_ENABLE_PORT, LCD_ENABLE_PIN, 0);
  }
}
/************************************/
void Push(char dato, uint8_t msgType)
{
	BufferDsp[inDsp].caracter = dato;
	BufferDsp[inDsp].TipoMensaje = msgType;
	inDsp++;
	bufferCount++;
	inDsp %= BUFFER_TAM;
}
/************************************/


