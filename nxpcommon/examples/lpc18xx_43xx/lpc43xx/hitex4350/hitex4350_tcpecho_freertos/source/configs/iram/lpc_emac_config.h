/**********************************************************************
* $Id$		lpc_emac_config.h			2011-11-20
*//**
* @file		lpc_emac_config.h
* @brief	PHY and EMAC configuration file
* @version	1.0
* @date		20 Nov. 2011
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

#ifndef __LPC_EMAC_CONFIG_H
#define __LPC_EMAC_CONFIG_H

#include "lwip/opt.h"

#ifdef __cplusplus
extern "C"
{
#endif

/** @defgroup hitex1850_tcpecho_freertos_iram	LWIP EMAC/PHY configuration
 * @ingroup hitex1850_tcpecho_freertos
 *
 * @{
 */

/** \brief  The PHY address connected the to MII/RMII
 */
#define LPC_PHYDEF_PHYADDR 1    /**< The PHY address on the PHY device. */

/** \brief  Enable autonegotiation mode.
 *          If this is enabled, the PHY will attempt to auto-negotiate the
 *          best link mode if the PHY supports it. If this is not enabled,
 *          the PHY_USE_FULL_DUPLEX and PHY_USE_100MBS defines will be
 *          used to select the link mode. Note that auto-negotiation may
 *          take a few seconds to complete.
 */
#define PHY_USE_AUTONEG 1 /**< Enables auto-negotiation mode. */

/** \brief  Sets up the PHY interface to either full duplex operation or
 *          half duplex operation if PHY_USE_AUTONEG is not enabled.
 */
#define PHY_USE_FULL_DUPLEX 1 /**< Sets duplex mode to full. */

/** \brief  Sets up the PHY interface to either 100MBS operation or 10MBS
 *          operation if PHY_USE_AUTONEG is not enabled.
 */
#define PHY_USE_100MBS 1 /**< Sets data rate to 100Mbps. */

/** \brief  Selects RMII or MII connection type in the EMAC peripheral
 */
#define LPC_EMAC_RMII 0   /**< Use the RMII or MII driver variant */

/** \brief  Defines the number of descriptors used for RX
 */
#define LPC_NUM_BUFF_RXDESCS 13

/** \brief  Defines the number of descriptors used for TX
 */
#define LPC_NUM_BUFF_TXDESCS 13

/** \brief  Enables slow speed memory buffering
 *          Enable this define if you expect to transfer packets directly
 *          from SPI FLASH or any slower memory. This will add a check
 *          before queueing up the transfer pbuf to make sure the packet
 *          is not in slow memoey (defined by the LPC_SLOWMEM_ARRAY). If
 *          the packet does exists in slow memory, a pbuf will be created
 *          in the PBUF_RAM pool, copied to it, and sent from there.
 */
#define LPC_CHECK_SLOWMEM 0

/** \brief  Array of slow memory addresses for LPC_CHECK_SLOWMEM
 *          Define the array - start and ending address - for the slow
 *          memory regions in the system that need pbuf copies.
 *
 *          Not defined since LPC_CHECK_SLOWMEM = 0.
 */
#define LPC_SLOWMEM_ARRAY

/**		  
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif /* __LPC_EMAC_CONFIG_H */

/* --------------------------------- End Of File ------------------------------ */
