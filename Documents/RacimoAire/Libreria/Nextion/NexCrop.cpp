/**
 * @file NexCrop.cpp
 *
 * The implementation of class NexCrop. 
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

#include "NexCrop.h"

NexCrop::NexCrop(NextionRaspberrypi *Seriall,uint8_t pid, uint8_t cid, const char *name)
    :NexTouch(Seriall,pid, cid, name)
{
    Serial =Seriall;
}

bool NexCrop::Get_background_crop_picc(uint32_t *number)
{
    QString cmd = QString("get ");
    cmd += getObjName();
    cmd += ".picc";
    sendCommand(Serial, cmd.toStdString().c_str());
    return recvRetNumber(Serial,  number);
}

bool NexCrop::Set_background_crop_picc(uint32_t number)
{
    QString cmd;
    
    cmd += getObjName();
    cmd += ".picc=";
    cmd += QString::number(static_cast<ulong>(number));

    sendCommand(Serial, cmd.toStdString().c_str());
    return recvRetCommandFinished(Serial);
}

bool NexCrop::getPic(uint32_t *number)
{
    QString cmd = QString("get ");
    cmd += getObjName();
    cmd += ".picc";
    sendCommand(Serial, cmd.toStdString().c_str());
    return recvRetNumber(Serial,  number);
}

bool NexCrop::setPic(uint32_t number)
{
    QString cmd;
    
    cmd += getObjName();
    cmd += ".picc=";
    cmd += QString::number(static_cast<ulong>(number));

    sendCommand(Serial, cmd.toStdString().c_str());
    return recvRetCommandFinished(Serial);
}

