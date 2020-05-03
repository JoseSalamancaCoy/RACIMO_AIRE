/**
 * @file NexVariable.cpp
 *
 * The implementation of class NexText. 
 *
 * @author  huang xiaoming (email:<xiaoming.huang@itead.cc>)
 * @date    2016/9/13
 * @copyright 
 * Copyright (C) 2014-2015 ITEAD Intelligent Systems Co., Ltd. \n
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 */
#include "NexVariable.h"
NexVariable::NexVariable(NextionRaspberrypi *Seriall,uint8_t pid, uint8_t cid, const char *name)
    :NexTouch(Seriall,pid, cid, name)
{
    Serial=Seriall;
}

uint32_t NexVariable::getValue(uint32_t *number)
{
    QString cmd = QString("get ");
    cmd += getObjName();
    cmd += ".val";
    sendCommand(Serial, cmd.toStdString().c_str());
    return recvRetNumber(Serial,  number);
}

bool NexVariable::setValue(uint32_t number)
{
    QString cmd;
    
    cmd += getObjName();
    cmd += ".val=";
    cmd += QString::number(static_cast<ulong>(number));

    sendCommand(Serial, cmd.toStdString().c_str());
    return recvRetCommandFinished(Serial);
}

uint32_t NexVariable::getText(char *buffer, uint32_t len)
{
    QString cmd;
    cmd += "get ";
    cmd += getObjName();
    cmd += ".txt";
    sendCommand(Serial, cmd.toStdString().c_str());
    return recvRetString(Serial,buffer,len);
}

bool NexVariable::setText(const char *buffer)
{
    QString cmd;
    cmd += getObjName();
    cmd += ".txt=\"";
    cmd += buffer;
    cmd += "\"";
    sendCommand(Serial, cmd.toStdString().c_str());
    return recvRetCommandFinished(Serial);
}
