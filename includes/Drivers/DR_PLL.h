/*************************************************/
/*          DRIVERS PARA EL SETEO DE PLL         */
/*************************************************/

#ifndef _DR_PLL_H_
#define _DR_PLL_H_

/************* INCLUDES *************/
#include <stdint.h>
#include "defines.h"
/************* DEFINES *************/
/*  DIRECCIONES DE MEMORIA  */
#define SCS               (*((volatile uint32_t*)0x400FC1A0))
#define CCLKCFG           (*((volatile uint32_t*)0x400FC104))
#define PCLKSEL0          (*((volatile uint32_t*)0x400FC1A8))
#define PCLKSEL1          (*((volatile uint32_t*)0x400FC1AC))
#define CLKSRCSEL         (*((volatile uint32_t*)0x400FC10C))

#define PLL0CON           (*((volatile uint32_t*)0x400FC080))
#define PLL0CFG           (*((volatile uint32_t*)0x400FC084))
#define PLL0STAT          (*((volatile uint32_t*)0x400FC088))
#define PLL0FEED          (*((volatile uint32_t*)0x400FC08C))

#define PLL1CON           (*((volatile uint32_t*)0x400FC0A0))
#define PLL1CFG           (*((volatile uint32_t*)0x400FC0A4))
#define PLL1STAT          (*((volatile uint32_t*)0x400FC0A8))
#define PLL1FEED          (*((volatile uint32_t*)0x400FC0AC))

#define PCONP             (*((volatile uint32_t*)0x400FC0C4))
#define CLKOUTCFG         (*((volatile uint32_t*)0x400FC1C8))
#define FLASHCFG          (*((volatile uint32_t*)0x400FC000))
/************************************/
void InicializarPLL(void);
/************************************/

#endif  //_DR_PLL_H_
