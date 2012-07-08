/**********************************************************************
* $Id$		ea1788_board.c			2011-11-20
*//**
* @file		ea1788_board.c
* @brief	Board specific functions for the EA1788 board
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

#include "lpc177x_8x_gpio.h"
#include "lpc_board.h"

/* GPIO port used for LED control on the EA1788 board */
#define LED_GPIO_PORT_USED		(1)

/* GPIO bit used for LED control on the EA1788 board */
#define LED_GPIO_PIN_BIT		(1 << 18)

/* Set the EA1788 module red LED to an on or off state */
void led_set(s32_t state)
{
	/* Set inverse GPIO state based on LED drive state */
	if (state)
		GPIO_OutputValue(LED_GPIO_PORT_USED, LED_GPIO_PIN_BIT, DISABLE);
	else
		GPIO_OutputValue(LED_GPIO_PORT_USED, LED_GPIO_PIN_BIT, ENABLE);
}

/* Setup EA1788 board for LWIP examples */
void board_setup(void)
{
	GPIO_Init();

	/* Set LED GPIO to an output */
	GPIO_SetDir(LED_GPIO_PORT_USED, LED_GPIO_PIN_BIT, GPIO_DIRECTION_OUTPUT);

	/* Configure ethernet pin muxing as follows:
	   RMII_TXD0     -> P1.0    -> FUNC1
	   RMII_TXD1     -> P1.1    -> FUNC1
	   RMII_TXEN     -> P1.4    -> FUNC1
	   RMII_RXD0     -> P1.9    -> FUNC1
	   RMII_RXD1     -> P1.10   -> FUNC1
	   RMII_CRS      -> P1.8    -> FUNC1
	   RMII_RXER     -> P1.14   -> FUNC1
	   RMII_MDIO     -> P1.17   -> FUNC1
	   RMII_MCD      -> P1.16   -> FUNC1
	   RMII_CLK      -> P1.15   -> FUNC1
	*/
	PINSEL_ConfigPin(1, 0, 1);
	PINSEL_ConfigPin(1, 1, 1);
	PINSEL_ConfigPin(1, 4, 1);
	PINSEL_ConfigPin(1, 9, 1);
	PINSEL_ConfigPin(1, 10, 1);
	PINSEL_ConfigPin(1, 8, 1);
	PINSEL_ConfigPin(1, 14, 1);
	PINSEL_ConfigPin(1, 17, 1);
	PINSEL_ConfigPin(1, 16, 1);
	PINSEL_ConfigPin(1, 15, 1);
}

/* Populates the MAC address for the board */
void board_get_macaddr(u8_t *macaddr)
{
	macaddr[0] = LPC_EMAC_ADDR0;
	macaddr[1] = LPC_EMAC_ADDR1;
	macaddr[2] = LPC_EMAC_ADDR2;
	macaddr[3] = LPC_EMAC_ADDR3;
	macaddr[4] = LPC_EMAC_ADDR4;
	macaddr[5] = LPC_EMAC_ADDR5;
}

/* --------------------------------- End Of File ------------------------------ */
