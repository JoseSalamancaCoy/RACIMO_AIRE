/**
 * @file NexConfig.h
 *
 * Options for user can be found here. 
 *
 * @author  Wu Pengfei (email:<pengfei.wu@itead.cc>)
 * @date    2015/8/13
 * @copyright 
 * Copyright (C) 2014-2015 ITEAD Intelligent Systems Co., Ltd. \n
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 */
#ifndef __NEXCONFIG_H__
#define __NEXCONFIG_H__

/**
 * @addtogroup Configuration 
 * @{ 
 */

/** 
 * Define DEBUG_SERIAL_ENABLE to enable debug serial. 
 * Comment it to disable debug serial. 
 */
#define DEBUG_SERIAL_ENABLE

/**
 * Define dbSerial for the output of debug messages. 
 */
//#define dbSerial NextionRaspberrypi

/**
 * Define nexSerial for communicate with Nextion touch panel. 
 */
//#define nexSerial NextionRaspberrypi



//#ifdef DEBUG_SERIAL_ENABLE
/*void dbSerialPrint(uint32_t a);
void dbSerialPrint(uint32_t *a);
void dbSerialPrintln(uint32_t a);
void dbSerialPrintln(uint32_t *a);


void dbSerialPrint(QString a);
void dbSerialPrintln(QString a);

*/

/**
 * @}
 */

#endif /* #ifndef __NEXCONFIG_H__ */
