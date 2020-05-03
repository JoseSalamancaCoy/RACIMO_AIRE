/**
 * @file NexGpio.cpp
 *
 * The implementation of class NexGpio. 
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
#include "NexGpio.h"
#include "NexHardware.h"

bool NexGpio::pin_mode(NextionRaspberrypi *Seriall,uint32_t port,uint32_t mode,uint32_t control_id)
{
    char buf;
    QString cmd;
    Serial=Seriall;
    cmd += "cfgpio ";
    buf = port + '0';
    cmd += buf;
    cmd += ',';
    buf = mode + '0';
    cmd += buf;
    cmd += ',';
    buf = control_id = '0';
    cmd += buf;

    sendCommand(Serial, cmd.toStdString().c_str());
    return recvRetCommandFinished(Serial);
    
}

bool NexGpio::digital_write(uint32_t port,uint32_t value)
{
    QString cmd;
    char buf;
    
    cmd += "pio";
    buf = port + '0';
    cmd += buf;
    cmd += '=';
    buf = value + '0';
    cmd += buf;
    
    sendCommand(Serial, cmd.toStdString().c_str());
    return recvRetCommandFinished(Serial);
}

uint32_t NexGpio::digital_read(uint32_t port)
{
    uint32_t number;
    char buf;
    
    QString cmd = QString("get ");
    cmd += "pio";
    buf = port + '0';
    cmd += buf;
    
    sendCommand(Serial, cmd.toStdString().c_str());
    recvRetNumber(Serial, &number);
    return number;
}

bool NexGpio::analog_write(uint32_t port,uint32_t value)
{
    char c;
    QString cmd;
    
    cmd += "pwm";
    c = port + '0';
    cmd += c;
    cmd += '=';
    cmd += QString::number(static_cast<long>(value));
    
    //dbSerialPrint(cmd);
    sendCommand(Serial, cmd.toStdString().c_str());
    return recvRetCommandFinished(Serial);
}

bool NexGpio::set_pwmfreq(uint32_t value)
{
    QString cmd;
    
    cmd += "pwmf";
    cmd += '=';
    cmd += QString::number(static_cast<long>(value));
    
    sendCommand(Serial, cmd.toStdString().c_str());
    return recvRetCommandFinished(Serial);
}

uint32_t NexGpio::get_pwmfreq(uint32_t *number)
{
    QString cmd = QString("get pwmf");
    sendCommand(Serial, cmd.toStdString().c_str());
    return recvRetNumber(Serial, number);
}
