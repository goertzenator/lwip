/**********************************************************************
* $Id$		lpc_lwip_doxygen.h			2011-11-20
*//**
* @file		lpc_lwip_doxygen.h
* @brief	Doxygen structure file
* @version	1.0
* @date		20 Nov. 2011
* @author	NXP MCU SW Application Team
*
* @note     This file is not used in the code. It only provides a
*           high level group architecture for Doxygen that is used a
*           a basis for all other in-code documentation.
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

#ifndef __LPC_LWIP_DOXYGEN_H
#define __LPC_LWIP_DOXYGEN_H

/* Documentation grouping structure
 * lwip_lpc(X)--XXX
 *  lwip_emac(X)--XXX
 *   lwip17xx_emac_DRIVER --XXX <Needs cleanup, remove zemac file, other changes for FreeRTOS, kill extra thread
 *   lwip18xx_43xx_emac_DRIVER--XXX
 *  lwip_phy(X)--XXX
 *   dp83848_phy--XXX
 *   lan8720_phy--XXX
 *  lpc_board(X)--XXX
 *   EA1788(X)--XXX
 *    ea1788_tcpecho_sa
 *     ea1788_tcpecho_sa_iram
 *     ea1788_tcpecho_sa_flash
 *     ea1788_tcpecho_sa_dram
 *    ea1788_httpraw_sa
 *     ea1788_httpraw_sa_iram
 *     ea1788_httpraw_sa_flash
 *     ea1788_httpraw_sa_dram
 *    ea1788_tcpecho_freertos
 *     ea1788_tcpecho_freertos_iram
 *     ea1788_tcpecho_freertos_flash
 *     ea1788_tcpecho_freertos_dram
 *   HITEX4350(X)--XXX
 *    hitex1850_tcpecho_freertos--XXX
 *     hitex1850_tcpecho_freertos_iram--XXX
 *     hitex1850_tcpecho_freertos_flash
 *     hitex1850_tcpecho_freertos_dram
 *  lpc_arch(X)--XXX
 *   lpc_debug(X)--XXX
 *   LPC177x_8x(X)--XXX
 *    LPC177x_8x_systick--XXX
 *    LPC177x_8x_freertos_support--XXX
 *   LPC18xx_43xx(X)--XXX
 *    LPC18xx_43xx_freertos_support--XXX
 */

 /** @mainpage lwip_lpc	NXP LPC LWIP library port
 *
 * Welcome to the NXP LPC LWIP port for NXP devices. This NXP supported
 * port of LWIP provides support for various NXP devices with built-in
 * MAC controllers. The port is maintained by NXP and will be updated
 * and improved over time. The port is based on LWIP v1.4.0.
 * @{
 */
 
/** @defgroup lwip_lpc	NXP LPC LWIP library port.
 *
 * This package provides a LWIP port to NXP LPC devices. The port
 * supports both standalone and RTOS based applications as well as
 * link monitoring, zero-copy buffers, and more.
 * @{
 */

/**		  
 * @}
 */

/** @defgroup lwip_emac	LPC EMAC driver.
 * @ingroup lwip_lpc
 *
 * The NXP LPC EMAC drivers supoprt the ethernet MAC controller in
 * some of NXP's devices. Currently, the EMAC in the LPC17xx
 * series of devices and the LPC18xx/43xx are supported. The driver
 * supports standalone and RTOS based applications with  zero-copy
 * buffers for both receive and transmit. The driver depends on an
 * external PHY driver that handles link status via the MII link
 * interface.
 * @{
 */

/**		  
 * @}
 */

/** @defgroup lwip_phy	LPC PHY driver.
 * @ingroup lwip_lpc
 *
 * The PHY driver is needed by the EMAC driver and handles the basic
 * PHY management functions such as link status, speed, and duplex.
 * @{
 */

/**		  
 * @}
 */

/** @defgroup lpc_board  NXP LPC board specific port files for LWIP
 * @ingroup lwip_lpc
 *
 * Some functions for the NXP LPC port are board specific. Each board
 * has a specific set of functions that is used to setup or control
 * a capability for that board. The functions may setup up board muxing
 * or select a GPIO used to toggle an LED. Common functions are used in
 * the lwip applications to setup board specific capabilities.
 * @{
 */

/** @defgroup EA1788	Embedded Artists LPC1788 (EA1788) board
 * @ingroup lpc_board
 * @{
 */

/**		  
 * @}
 */

/** @defgroup HITEX4350	Hitex LPC4350 (HITEX4350) board
 * @ingroup lpc_board
 * @{
 */

/**		  
 * @}
 */

/**		  
 * @}
 */

/** @defgroup lpc_arch  NXP LPC architecture specific port files for LWIP
 * @ingroup lwip_lpc
 *
 * Some functions for the NXP LPC port are architecture specific. For
 * example, the timebase on one architecture may be different than
 * another. Common functions are used in the lwip applications to setup
 * architecture specific capabilities.
 * @{
 */

/** @defgroup lpc_debug	LPC debug support
 * @ingroup lpc_arch
 * @{
 */

/**		  
 * @}
 */

/** @defgroup LPC177x_8x	NXP LPC177x_8x devices
 * @ingroup lpc_arch
 * @{
 */

/**		  
 * @}
 */

/** @defgroup LPC18xx_43xx	NXP LPC18xx/43xx devices
 * @ingroup lpc_arch
 * @{
 */

/**		  
 * @}
 */

 /**		  
 * @}
 */

#endif /* __LPC_LWIP_DOXYGEN_H */

/* --------------------------------- End Of File ------------------------------ */
