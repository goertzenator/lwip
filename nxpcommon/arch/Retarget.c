#include "debug_frmwrk.h"

#if   defined ( __CC_ARM )
/******************************************************************************/
/* RETARGET.C: 'Retarget' layer for target-dependent low level functions      */
/******************************************************************************/
/* This file is part of the uVision/ARM development tools.                    */
/* Copyright (c) 2005-2006 Keil Software. All rights reserved.                */
/* This software may only be used under the terms of a valid, current,        */
/* end user licence from KEIL for a compatible version of KEIL software       */
/* development tools. Nothing else gives you the right to use this software.  */
/******************************************************************************/

#include <stdio.h>
#include <rt_misc.h>

#pragma import(__use_no_semihosting_swi)

struct __FILE { int handle; /* Add whatever you need here */ };
FILE __stdout;

int fputc(int ch, FILE *f) {
	UARTPutChar(DEBUG_UART_PORT, (uint8_t) ch);
	return ch;
}

int fgetc(FILE *f) {
	return (int) UARTGetChar (DEBUG_UART_PORT);
}

int ferror(FILE *f) {
  return EOF;
}

void _ttywrch(int ch) {
	UARTPutChar(DEBUG_UART_PORT, (uint8_t) ch);
}

void _sys_exit(int return_code) {
label:  goto label;  /* endless loop */
}

#elif defined ( __ICCARM__ )
/*******************
 *
 * Copyright 1998-2003 IAR Systems.  All rights reserved.
 *
 * $Revision: 30870 $
 *
 * This is a template implementation of the "__write" function used by
 * the standard library.  Replace it with a system-specific
 * implementation.
 *
 * The "__write" function should output "size" number of bytes from
 * "buffer" in some application-specific way.  It should return the
 * number of characters written, or _LLIO_ERROR on failure.
 *
 * If "buffer" is zero then __write should perform flushing of
 * internal buffers, if any.  In this case "handle" can be -1 to
 * indicate that all handles should be flushed.
 *
 * The template implementation below assumes that the application
 * provides the function "MyLowLevelPutchar".  It should return the
 * character written, or -1 on failure.
 *
 ********************/

#include <yfuns.h>

_STD_BEGIN

#pragma module_name = "?__write"

int sendchar (int ch);

/*
 * If the __write implementation uses internal buffering, uncomment
 * the following line to ensure that we are called with "buffer" as 0
 * (i.e. flush) when the application terminates.
 */

size_t __write(int handle, const unsigned char * buffer, size_t size)
{
  size_t nChars = 0;

  if (buffer == 0)
  {
    /*
     * This means that we should flush internal buffers.  Since we
     * don't we just return.  (Remember, "handle" == -1 means that all
     * handles should be flushed.)
     */
    return 0;
  }

  /* This template only writes to "standard out" and "standard err",
   * for all other file handles it returns failure. */
  if (handle != _LLIO_STDOUT && handle != _LLIO_STDERR)
  {
    return _LLIO_ERROR;
  }

  for (/* Empty */; size != 0; --size)
  {
	UARTPutChar(DEBUG_UART_PORT, (uint8_t) *buffer++);

    ++nChars;
  }

  return nChars;
}

_STD_END

#elif defined ( __GNUC__ )
#include <stdio.h>

int _read (int file, char *ptr, int len)
{
	/* Can be implemented to getc(), but not used */
	return 1;
}
	
int _write (int file, char *ptr, int len)
{
	int i;

	/* Send characters on the serial port */
	for (i = 0; i < len; i++)
	{
		UARTPutChar(DEBUG_UART_PORT, (uint8_t) *ptr);
		ptr++;
	}

	return len;
}
#endif
