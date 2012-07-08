/**********************************************************************
* $Id$		lpc_board.h			2011-11-20
*//**
* @file		lpc_board.h
* @brief	Board specific functions used with the LWIP examples
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

#ifndef __LPC_BOARD_H
#define __LPC_BOARD_H

#include "lwip/opt.h"

/** @ingroup lpc_board
 * @{
 */

#define LPC_EMAC_ADDR0 0x00 /**< Hardware MAC address field 0 */
#define LPC_EMAC_ADDR1 0x60 /**< Hardware MAC address field 1 */
#define LPC_EMAC_ADDR2 0x37 /**< Hardware MAC address field 2 */
#define LPC_EMAC_ADDR3 0x12 /**< Hardware MAC address field 3 */
#define LPC_EMAC_ADDR4 0x34 /**< Hardware MAC address field 4 */
#define LPC_EMAC_ADDR5 0x56 /**< Hardware MAC address field 5 */

/** \brief  Set the EA1788 module red LED to an on or off state
 *
 *  This function sets the LED to an on or off state for the board.
 *  The red LED on the EA1788 CPU module is used.
 *
 *  \param[in]      state  New LED state, 0 = off, !0 = on
 */
void led_set(s32_t state);

/** \brief  Setup EA1788 board for LWIP examples
 *
 *  This function sets up the LED and ethernet pin muxing for the LPC1788
 *  as used on the EA1788 board.
 */
void board_setup(void);

/** \brief  Populates the MAC address for the board.
 *
 *  This function sets the MAC address used for the EA1788 board. Although
 *  this can be replaced with something more capable, it simply uses a
 *  hard-coded MAC address for this example.
 */
void board_get_macaddr(u8_t *macaddr);

/**
 * @}
 */

#endif /* __LPC_BOARD_H */

/* --------------------------------- End Of File ------------------------------ */
