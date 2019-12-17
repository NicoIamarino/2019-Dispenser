/**********************************************/
/*      DRIVERS PARA EL MANEJO DEL DISPLAY    */
/**********************************************/

/************* INCLUDES *************/
#include "DR_Display.h"
/*********** VAR. GLOBALES **********/
uint8_t inDsp = 0;
uint8_t outDsp = 0;
uint8_t bufferCount = 0;
DisplayData BufferDsp[BUFFER_TAM];


/************************************/
//Recupera un caracter del buffer del display
//Param: 	void
//Return: 	void
DisplayData Pop(void)
{
	DisplayData retorno;

	retorno.caracter = -1;

	if ( bufferCount > 0 )
	{
		retorno = BufferDsp[outDsp];
		outDsp++;
		bufferCount--;
		outDsp %= BUFFER_TAM;
	}

	return retorno;
}
/************************************/
//Escribe un caracter o instrucción en el display
//Param: 	void
//Return: 	void
void EscribirDisplay(void)
{
	DisplayData bufferCaracter = Pop();

	if(bufferCaracter.caracter != -1 && bufferCaracter.TipoMensaje == CARACTER)
	{
		if(IS_VISIBLE(bufferCaracter.caracter))
		{
			SetPIN(LCD_RS_PORT, LCD_RS_PIN, 1); //1 = "Data Register"
			SetPIN(LCD_ENABLE_PORT, LCD_ENABLE_PIN, 0);

			#ifdef LCD_8BIT
			SetPIN(LCD_DB7_PORT, LCD_DB7_PIN, (bufferCaracter.caracter >> 7) & 0x01);
			SetPIN(LCD_DB6_PORT, LCD_DB6_PIN, (bufferCaracter.caracter >> 6) & 0x01);
			SetPIN(LCD_DB5_PORT, LCD_DB5_PIN, (bufferCaracter.caracter >> 5) & 0x01);
			SetPIN(LCD_DB4_PORT, LCD_DB4_PIN, (bufferCaracter.caracter >> 4) & 0x01);
			SetPIN(LCD_DB3_PORT, LCD_DB3_PIN, (bufferCaracter.caracter >> 3) & 0x01);
			SetPIN(LCD_DB2_PORT, LCD_DB2_PIN, (bufferCaracter.caracter >> 2) & 0x01);
			SetPIN(LCD_DB1_PORT, LCD_DB1_PIN, (bufferCaracter.caracter >> 1) & 0x01);
			SetPIN(LCD_DB0_PORT, LCD_DB0_PIN, (bufferCaracter.caracter >> 0) & 0x01);

			SetPIN(LCD_ENABLE_PORT, LCD_ENABLE_PIN, 1);
			SetPIN(LCD_ENABLE_PORT, LCD_ENABLE_PIN, 0);

			#elif defined(LCD_4BIT)
			SetPIN(LCD_DB7_PORT, LCD_DB7_PIN, (bufferCaracter.caracter >> 7) & 0x01);
			SetPIN(LCD_DB6_PORT, LCD_DB6_PIN, (bufferCaracter.caracter >> 6) & 0x01);
			SetPIN(LCD_DB5_PORT, LCD_DB5_PIN, (bufferCaracter.caracter >> 5) & 0x01);
			SetPIN(LCD_DB4_PORT, LCD_DB4_PIN, (bufferCaracter.caracter >> 4) & 0x01);

			SetPIN(LCD_ENABLE_PORT, LCD_ENABLE_PIN, 1);
			SetPIN(LCD_ENABLE_PORT, LCD_ENABLE_PIN, 0);

			SetPIN(LCD_DB7_PORT, LCD_DB7_PIN, (bufferCaracter.caracter >> 3) & 0x01);
			SetPIN(LCD_DB6_PORT, LCD_DB6_PIN, (bufferCaracter.caracter >> 2) & 0x01);
			SetPIN(LCD_DB5_PORT, LCD_DB5_PIN, (bufferCaracter.caracter >> 1) & 0x01);
			SetPIN(LCD_DB4_PORT, LCD_DB4_PIN, (bufferCaracter.caracter >> 0) & 0x01);

			SetPIN(LCD_ENABLE_PORT, LCD_ENABLE_PIN, 1);
			SetPIN(LCD_ENABLE_PORT, LCD_ENABLE_PIN, 0);
			#endif
		}
	}

	if(bufferCaracter.caracter != -1 && bufferCaracter.TipoMensaje == INSTRUCCION)
	{
		//if(IS_INSTRUCTION(bufferCaracter.caracter))
		//{
			EscribirInstruccion(bufferCaracter.caracter);
		//}
	}

}
/************************************/
//Escribe una instruccion en los pines DB7-DB0, hay que comentar uno de los dos define LCD_8BIT o LCD_4BIT
//Param: data: Instrucción en hexa, ej: 0x28
//Return: Void
void EscribirInstruccion(uint8_t data)
{
  SetPIN(LCD_RS_PORT, LCD_RS_PIN, 0); //0 = "Instruction Register"
  SetPIN(LCD_ENABLE_PORT, LCD_ENABLE_PIN, 0);

  #ifdef LCD_8BIT
  SetPIN(LCD_DB7_PORT, LCD_DB7_PIN, (data >> 7) & 0x01);
  SetPIN(LCD_DB6_PORT, LCD_DB6_PIN, (data >> 6) & 0x01);
  SetPIN(LCD_DB5_PORT, LCD_DB5_PIN, (data >> 5) & 0x01);
  SetPIN(LCD_DB4_PORT, LCD_DB4_PIN, (data >> 4) & 0x01);
  SetPIN(LCD_DB3_PORT, LCD_DB3_PIN, (data >> 3) & 0x01);
  SetPIN(LCD_DB2_PORT, LCD_DB2_PIN, (data >> 2) & 0x01);
  SetPIN(LCD_DB1_PORT, LCD_DB1_PIN, (data >> 1) & 0x01);
  SetPIN(LCD_DB0_PORT, LCD_DB0_PIN, (data >> 0) & 0x01);

  SetPIN(LCD_ENABLE_PORT, LCD_ENABLE_PIN, 1);
  SetPIN(LCD_ENABLE_PORT, LCD_ENABLE_PIN, 0);

  #elif defined(LCD_4BIT)
  SetPIN(LCD_DB7_PORT, LCD_DB7_PIN, (data >> 7) & 0x01);
  SetPIN(LCD_DB6_PORT, LCD_DB6_PIN, (data >> 6) & 0x01);
  SetPIN(LCD_DB5_PORT, LCD_DB5_PIN, (data >> 5) & 0x01);
  SetPIN(LCD_DB4_PORT, LCD_DB4_PIN, (data >> 4) & 0x01);

  SetPIN(LCD_ENABLE_PORT, LCD_ENABLE_PIN, 1);
  SetPIN(LCD_ENABLE_PORT, LCD_ENABLE_PIN, 0);

  SetPIN(LCD_DB7_PORT, LCD_DB7_PIN, (data >> 3) & 0x01);
  SetPIN(LCD_DB6_PORT, LCD_DB6_PIN, (data >> 2) & 0x01);
  SetPIN(LCD_DB5_PORT, LCD_DB5_PIN, (data >> 1) & 0x01);
  SetPIN(LCD_DB4_PORT, LCD_DB4_PIN, (data >> 0) & 0x01);

  SetPIN(LCD_ENABLE_PORT, LCD_ENABLE_PIN, 1);
  SetPIN(LCD_ENABLE_PORT, LCD_ENABLE_PIN, 0);
  #endif
}
/************************************/
