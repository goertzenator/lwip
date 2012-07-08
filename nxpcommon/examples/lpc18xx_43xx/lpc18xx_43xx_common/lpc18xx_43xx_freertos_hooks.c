/**********************************************************************
* $Id$		lpc4350_freertos_hooks.c			2011-11-20
*//**
* @file		lpc4350_freertos_hooks.c
* @brief	FreeRTOS support hooks for the LPC43xx (and LPC18xx)
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

#include "FreeRTOS.h"
#include "task.h"

#include "lwip/opt.h"
#include "lwip/mem.h"
#include "lwip/sys.h"

#ifdef LPC43XX
#include "lpc43xx.h"
#else
#ifdef LPC43XX
#include "lpc18xx.h"
#else
#error LPC18XX or LPC43XX for target system not defined!
#endif
#endif

#include "lpc_arch.h"

/** @defgroup LPC18xx_43xx_freertos_support	lpc18xx/43xx common FreeRTOS functions
 * @ingroup LPC18xx_43xx
 *
 * @{
 */

/* Delay for the specified number of milliSeconds */
void msDelay(uint32_t ms)
{
	portTickType xDelayTime;

	xDelayTime = xTaskGetTickCount();
	vTaskDelayUntil( &xDelayTime, ms );
}

/** \brief  FreeRTOS malloc fail hook
 *
 *  Called when malloc fails to allocate data.
 */
void vApplicationMallocFailedHook( void )
{
	LWIP_DEBUGF(LWIP_DBG_ON, ("MALLOC failed\n"));
	taskDISABLE_INTERRUPTS();
	for( ;; );
}

/** \brief  FreeRTOS application idle hook
 *
 *  Calls ARM Wait for Interrupt function to idle core
 */
void vApplicationIdleHook( void )
{
	/* Best to sleep here until next systick */
	__WFI;
}

/** \brief  FreeRTOS stack overflow hook
 *
 *  Displats the task name that overflowed the stack.
 *
 *   \param[in] pxTask Task handle that overflowed stack
 *   \param[in] pcTaskName Task name that overflowed stack
 */
void vApplicationStackOverflowHook( xTaskHandle pxTask, signed char *pcTaskName )
{
	( void ) pxTask;

	/* Run time stack overflow checking is performed if
       configCHECK_FOR_STACK_OVERFLOW is defined to 1 or 2.  This hook
	   function is called if a stack overflow is detected. */
	LWIP_DEBUGF(LWIP_DBG_ON, ("App stack overflow on task %s\n", pcTaskName));
	taskDISABLE_INTERRUPTS();
	for( ;; );
}

/** \brief  FreeRTOS application tick hook
 *
 *  Called when a systick occurs
 */
void vApplicationTickHook( void )
{
	;
}

/**
 * @}
 */

/* --------------------------------- End Of File ------------------------------ */
