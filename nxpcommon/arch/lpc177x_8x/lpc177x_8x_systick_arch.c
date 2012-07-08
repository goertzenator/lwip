/**********************************************************************
* $Id$		lpc177x_8x_systick_arch.c			2011-11-20
*//**
* @file		lpc177x_8x_systick_arch.c
* @brief	Setups up the system tick to generate a reference timebase
* @version	1.0
* @date		20. Nov. 2011
* @author	NXP MCU SW Application Team
* 
* Copyright(C) 2011, NXP Semiconductor
* All rights reserved.
*
***********************************************************************
* Software that is described herein is for illustrative purposes only
* which provides customers with programming information regarding the
* products. This software is supplied "AS IS" without any warranties.
* NXP Semiconductors assumes no responsibility or liability for the
* use of the software, conveys no license or title under any patent,
* copyright, or mask work right to the product. NXP Semiconductors
* reserves the right to make changes in the software without
* notification. NXP Semiconductors also make no representation or
* warranty that such application will be suitable for the specified
* use without further testing or modification.
**********************************************************************/

#include "lwip/opt.h"

#if NO_SYS == 1

#include "lpc177x_8x_systick.h"
#include "lpc_arch.h"

/** @defgroup LPC177x_8x_systick	LPC177x_8x LWIP (standalone) timer base
 * @ingroup LPC177x_8x
 * @{
 */

/* Saved reference period */
 static uint32_t saved_period;
 
/* Saved total time in mS since timer was enabled */
static volatile u32_t systick_timems;

/* Enable systick rate and interrupt */
void SysTick_Enable(uint32_t period)
{
	/* Initialize System Tick with time interval */
	SYSTICK_InternalInit(period);
	saved_period = period;
	systick_timems = 0;

	/* Enable System Tick interrupt */
	SYSTICK_IntCmd(ENABLE);

	/* Enable System Tick Counter */
	SYSTICK_Cmd(ENABLE);
}

/* Disable systick */
void SysTick_Disable(void)
{
	/* Disable System Tick Counter */
	SYSTICK_Cmd(DISABLE);

	/* Disable System Tick interrupt */
	SYSTICK_IntCmd(DISABLE);
}

/** \brief  SysTick IRQ handler and timebase management
 *
 *  This function keeps a timebase for the sysTick that can be
 * used for other functions. It also calls an external function
 * (SysTick_User) that must be defined outside this handler.
 */
void SysTick_Handler(void)
{
	/* Clear System Tick counter flag */
	SYSTICK_ClearCounterFlag();

	/* Increment tick count */
	systick_timems += saved_period;
}

/* Get the current systick time in milliSeconds */
uint32_t SysTick_GetMS(void)
{
	return systick_timems;
}

/* Delay for the specified number of milliSeconds */
void msDelay(uint32_t ms)
{
	uint32_t to = ms + systick_timems;

	while (to > systick_timems);
}
#endif

/**
 * @}
 */

 /* --------------------------------- End Of File ------------------------------ */
