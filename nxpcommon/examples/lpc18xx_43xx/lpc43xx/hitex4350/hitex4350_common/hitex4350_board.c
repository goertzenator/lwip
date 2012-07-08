/**********************************************************************
* $Id$		hitex4350_board.c			2011-11-20
*//**
* @file		hitex4350_board.c
* @brief	Board specific functions for the HITEX4350 board
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

#include "lpc43xx_gpio.h"
#include "lpc43xx_scu.h"
#include "lpc_board.h"
#include "lpc_emac_config.h"

#ifndef LPC_EMAC_RMII
#error LPC_EMAC_RMII is not defined!
#endif

/** @ingroup HITEX1850
 * @{
 */

/* Hitex1850 RMII/MII board setup
RMII mode:
Jumper state    PHY        Chip              CPIN     I/O      FUNC
JP15-1-2        RMII boot
JP5-1-2         X1/50M
JP14-1-2                   ENET_REF_CLK/50M  P1.19    I        0
SV3-15-16 dm               ENET_REF_CLK/50M  P1.19    I        0
SV3-13-14 c     TX_EN      ENET_TX_EN        P0.1     O        6
SV3-11-12 c     TXD0       ENET_TXD0         P1.18    O        3
SV3-9-10  c     TXD1       ENET_TXD1         P1.20    O        3
SV3-7-8   dm    TXD2       ENET_TXD2         P9.4     na
SV3-5-6   dm    TXD3       ENET_TXD3         P9.5     na
SV5-3-4   dm    TXD3       ENET_TXD3         P9.5     na
SV3-3-4   c     MDIO       ENET_MDIO         P1.17    I/O      3
SV3-1-2   c     MDC        ENET_MDC          PC.1     O        3
SV13-1-2  o     MDC        ENET_MDC          PC.1     O        3
SV6-1-2   dm    RX_CLK     ENET_RX_CLK       PC.0     na
SV12-3-4  dm    RX_CLK     ENET_RX_CLK       PC.0     na
SV6-3-4   c     RX_DV      ENET_RX_DV        P1.16    I        7
SV6-5-6   dm    CRS        ENET_CRS          P9.0     na
SV8-7-8   dm    CRS        ENET_CRS          P9.0     na
SV6-7-8   dm    RX_ER      ENET_RX_ERR       P9.1     na
SV8-5-6   dm    RX_ER      ENET_RX_ERR       P9.1     na
SV6-9-10  dm    COL        ENET_COL          P9.6     na
SV5-5-6   dm    COL        ENET_COL          P9.6     na
SV6-11-12 c     RXD0       ENET_RXD0         P1.15    I        3
SV6-13-14 c     RXD1       ENET_RXD1         P0.0     I        2
SV6-15-16 dm    RXD2       ENET_RXD2         P9.3     na
SV8-3-4   dm    RXD2       ENET_RXD2         P9.3     na
SV6-17-18 dm    RXD3       ENET_RXD3         P9.2     na
SV8-1-2   dm    RXD3       ENET_RXD3         P9.2     na

MII mode:
Jumper state    PHY        Chip              CPIN     I/O      FUNC
JP15      o     MII boot
NOTE: JP15 is shown as a 2-pin jumper on the schematics, but is a
NOTE: 3-pin jumper on the board. Make sure the jumper is open and
NOTE: not connected between pins 2-3.
JP5-2-3         X1/25M
JP14-2-3                   ENET_REF_CLK/25M  P1.19    I        0
SV3-15-16 c                ENET_REF_CLK/25M  P1.19    I        0
SV3-13-14 c     TX_EN      ENET_TX_EN        P0.1     O        6
SV3-11-12 c     TXD0       ENET_TXD0         P1.18    O        3
SV3-9-10  c     TXD1       ENET_TXD1         P1.20    O        3
SV3-7-8   c     TXD2       ENET_TXD2         P9.4     O		   5
SV3-5-6   c     TXD3       ENET_TXD3         P9.5     O		   5
SV5-3-4   c     TXD3       ENET_TXD3         P9.5     O        5
SV3-3-4   c     MDIO       ENET_MDIO         P1.17    I/O      3
SV3-1-2   c     MDC        ENET_MDC          PC.1     O        3
SV13-1-2  o     MDC        ENET_MDC          PC.1     O        3
SV6-1-2   c     RX_CLK     ENET_RX_CLK       PC.0     I/O      3
SV12-3-4  dm    RX_CLK     ENET_RX_CLK       PC.0     I/O      3
SV6-3-4   c     RX_DV      ENET_RX_DV        P1.16    I        7
SV6-5-6   c     CRS        ENET_CRS          P9.0     I        5
SV8-7-8   o     CRS        ENET_CRS          P9.0     I        5
SV6-7-8   c     RX_ER      ENET_RX_ER        P9.1     I        5
SV8-5-6   o     RX_ER      ENET_RX_ER        P9.1     I        5
SV6-9-10  c     COL        ENET_COL          P9.6     I		   5
SV5-5-6   o     COL        ENET_COL          P9.6     I        5
SV6-11-12 c     RXD0       ENET_RXD0         P1.15    I        3
SV6-13-14 c     RXD1       ENET_RXD1         P0.0     I        2
SV6-15-16 c     RXD2       ENET_RXD2         P9.3     I        5
SV8-3-4   o     RXD2       ENET_RXD2         P9.3     I		   5
SV6-17-18 c     RXD3       ENET_RXD3         P9.2     I		   5
SV8-1-2   o     RXD3       ENET_RXD3         P9.2     I		   5

o = open, c = closed, dm = doesn't matter
Note: Repeated signals indicate multiple jumpers that need to be set
*/

/* SCR pin definitions for RMII and MII modes */
#define EMAC_HIGHSLEW_INPUT  (MD_EHS | MD_PLN | MD_EZI | MD_ZI)
#define EMAC_HIGHSLEW_OUTPUT (MD_EHS | MD_PLN | MD_ZI)
#define EMAC_INPUT           (MD_PLN | MD_EZI)
#define EMAC_OUTPUT          (MD_PLN)

/** \brief  GPIO port used for LED control on the HITEX1850 board
 */
#define LED_GPIO_PORT_USED		(7)

/** \brief  GPIO bit used for LED control on the HITEX1850 board
 */
#define RED_GPIO_PIN_BIT		(5)
#define GREEN_GPIO_PIN_BIT		(6)
#define BLUE_GPIO_PIN_BIT		(8)
#define DEFAULT_COLOR_PIN_BIT	RED_GPIO_PIN_BIT

/** \brief  Set the HITEX1850 module red LED to an on or off state
 *
 *  This function sets the LED to an on or off state for the board.
 *  See CTOUT2.
 *
 *  \param [in]      state  New LED state, 0 = off, !0 = on
 */
void led_set(s32_t state)
{
	/* Only red component is used, set to input to disable, or
	   output drive low to enable */
	if (state)
		GPIO_SetDir(LED_GPIO_PORT_USED, (1 << DEFAULT_COLOR_PIN_BIT), 1);
	else
		GPIO_SetDir(LED_GPIO_PORT_USED, (1 << DEFAULT_COLOR_PIN_BIT), 0);
}

/** \brief  Setup HITEX1850 board for LWIP examples
 *
 *  This function sets up the LED and ethernet pin muxing for the LPC4350
 *  as used on the HITEX1850 board.
 */
void board_setup(void)
{

	/* Port mux and GPIO output direction */
	scu_pinmux(0xE, 5, MD_PDN, FUNC4);
	scu_pinmux(0xE, 6, MD_PDN, FUNC4);
	scu_pinmux(0xE, 8, MD_PDN, FUNC4);
	GPIO_SetDir(LED_GPIO_PORT_USED, (1 << DEFAULT_COLOR_PIN_BIT), 1);
	GPIO_ClearValue(LED_GPIO_PORT_USED,(1 << DEFAULT_COLOR_PIN_BIT));

	/* Green and blue not used, but float the ports so they don't
	   turn on. If you change the default color, be sure to set
	   the GPIO dir to output instead of input */
	GPIO_SetDir(LED_GPIO_PORT_USED, (1 << GREEN_GPIO_PIN_BIT), 0);
	GPIO_SetDir(LED_GPIO_PORT_USED, (1 << BLUE_GPIO_PIN_BIT), 0);
	GPIO_ClearValue(LED_GPIO_PORT_USED,(1 << GREEN_GPIO_PIN_BIT));
	GPIO_ClearValue(LED_GPIO_PORT_USED,(1 << BLUE_GPIO_PIN_BIT));

	/* EMAC clocking is handled in the EMAC driver, but make sure
	   the board has the correct jumper setup for RMII or MII mode.
	   See the specific RMII/MII jumper settings in the table in this
	   file. */

	LPC_CREG->CREG6 &= ~0x7;

#if LPC_EMAC_RMII == 1
	/* RMII mode setup only */
	LPC_CREG->CREG6 |= 0x4;
#if 1
	scu_pinmux(1,   19, EMAC_HIGHSLEW_INPUT,  FUNC0);
	scu_pinmux(0,   1,  EMAC_HIGHSLEW_OUTPUT, FUNC6);
	scu_pinmux(1,   18, EMAC_HIGHSLEW_OUTPUT, FUNC3);
	scu_pinmux(1,   20, EMAC_HIGHSLEW_OUTPUT, FUNC3);
	scu_pinmux(1,   17, EMAC_HIGHSLEW_INPUT,  FUNC3);
	scu_pinmux(0xC, 1,  EMAC_HIGHSLEW_OUTPUT, FUNC3);
	scu_pinmux(1,   16, EMAC_HIGHSLEW_INPUT,  FUNC7);
	scu_pinmux(1,   15, EMAC_HIGHSLEW_INPUT,  FUNC3);
	scu_pinmux(0,   0,  EMAC_HIGHSLEW_INPUT,  FUNC2);
#else
	scu_pinmux(0,   1,  (MD_PLN | MD_EHS),          FUNC6);
	scu_pinmux(1,   18, (MD_PLN | MD_EHS),          FUNC3);
	scu_pinmux(1,   20, (MD_PLN | MD_EHS),          FUNC3);
	scu_pinmux(1,   17, (MD_PLN | MD_EHS | MD_EZI), FUNC3);
	scu_pinmux(0xC, 1,  (MD_PLN | MD_EHS),          FUNC3);
	scu_pinmux(1,   15, (MD_PLN | MD_EHS | MD_EZI), FUNC3);
	scu_pinmux(0,   0,  (MD_PLN | MD_EHS | MD_EZI), FUNC2);
	scu_pinmux(1,   16, (MD_PLN | MD_EHS | MD_EZI), FUNC7);
	scu_pinmux(1,   19, (MD_PLN | MD_EHS | MD_EZI), FUNC0);
#endif
#else
	/* MII setup mode only */
	scu_pinmux(1,   19, EMAC_INPUT,  FUNC0);
	scu_pinmux(0,   1,  EMAC_OUTPUT, FUNC6);
	scu_pinmux(1,   18, EMAC_OUTPUT, FUNC3);
	scu_pinmux(1,   20, EMAC_OUTPUT, FUNC3);
	scu_pinmux(1,   17, EMAC_INPUT,  FUNC3);
	scu_pinmux(0xC, 1,  EMAC_OUTPUT, FUNC3);
	scu_pinmux(1,   16, EMAC_INPUT,  FUNC7);
	scu_pinmux(1,   15, EMAC_INPUT,  FUNC3);
	scu_pinmux(0,   0,  EMAC_INPUT,  FUNC2);
	scu_pinmux(9,   4,  EMAC_OUTPUT, FUNC5);
	scu_pinmux(9,   5,  EMAC_OUTPUT, FUNC5);
	scu_pinmux(0xC, 0,  EMAC_INPUT,  FUNC3);
	scu_pinmux(9,   0,  EMAC_INPUT,  FUNC5);
	scu_pinmux(9,   1,  EMAC_INPUT,  FUNC5);
	scu_pinmux(9,   6,  EMAC_INPUT,  FUNC5);
	scu_pinmux(9,   3,  EMAC_INPUT,  FUNC5);
	scu_pinmux(9,   2,  EMAC_INPUT,  FUNC5);
	scu_pinmux(0xC, 8,  EMAC_INPUT,  FUNC4); // fixme - this line can probably be safely deleted
#endif
}

/** \brief  Populates the MAC address for the board.
 *
 *  This function sets the MAC address used for the HITEX1850 board.
 *  Although this can be replaced with something more capable, it simply
 *  uses a hard-coded MAC address for this example.
 */
void board_get_macaddr(u8_t *macaddr)
{
	macaddr[0] = LPC_EMAC_ADDR0;
	macaddr[1] = LPC_EMAC_ADDR1;
	macaddr[2] = LPC_EMAC_ADDR2;
	macaddr[3] = LPC_EMAC_ADDR3;
	macaddr[4] = LPC_EMAC_ADDR4;
	macaddr[5] = LPC_EMAC_ADDR5;
}

/**
 * @}
 */

/* --------------------------------- End Of File ------------------------------ */
