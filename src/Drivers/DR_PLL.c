/*************************************************/
/*          DRIVERS PARA EL SETEO DE PLL         */
/*************************************************/

/************* INCLUDES *************/
#include "DR_PLL.h"
/************************************/
//Inicializo PLL
//Param:  void
//Return: void
void InicializarPLL(void)
{
  SCS = 0x00000020;

  if (SCS & (1 << 5))           // Si el osciolador principal está activo
  	while ((SCS & (1<<6)) == 0);// Espero a que esté listo

  CCLKCFG = 0x00000003;         // Setup Clock Divider

  PCLKSEL0 = 0x00000000;        // Peripheral Clock Selection
  PCLKSEL1 = 0x00000000;

  CLKSRCSEL = 0x00000001;       // Selecciono ClockSource para PLL0

  PLL0CFG = 0x00050063;         // Configuro PLL0
  PLL0FEED = 0xAA;
  PLL0FEED = 0x55;

  PLL0CON = 0x01;               // Activo PLL0
  PLL0FEED = 0xAA;
  PLL0FEED = 0x55;

  while (!(PLL0STAT & (1<<26)));// Espero a PLOCK0

  PLL0CON = 0x03;              // Activo y conecto PLL0
  PLL0FEED = 0xAA;
  PLL0FEED = 0x55;

  while (!(PLL0STAT & ((1<<25) | (1<<24))));// Espero PLLC0_STAT y PLLE0_STAT

  PLL1CFG = 0x00000023;
  PLL1FEED = 0xAA;
  PLL1FEED = 0x55;

  PLL1CON = 0x01;               // Activo PLL1
  PLL1FEED = 0xAA;
  PLL1FEED = 0x55;

  while (!(PLL1STAT & (1<<10)));//Espero PLOCK1

  PLL1CON = 0x03;               // Activo y conecto PLL1
  PLL1FEED = 0xAA;
  PLL1FEED = 0x55;

  while (!(PLL1STAT & ((1<< 9) | (1<< 8))));// Espero PLLC1_STAT y PLLE1_STAT

  PCONP = 0x042887DE;           // Power Control para periféricos

  CLKOUTCFG = 0x00000000;       // Configuración Clock Output

  FLASHCFG  = (FLASHCFG & ~0x0000F000) | 0x00004000;
}
/************************************/
