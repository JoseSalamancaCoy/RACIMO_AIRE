/**
 * @file NexRadio.cpp
 *
 * The implementation of class NexRadio. 
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
#include "NexRadio.h"

NexRadio::NexRadio(uint8_t pid, uint8_t cid, const char *name)
    :NexTouch(pid, cid, name)
{
}

uint32_t NexRadio::getValue(uint32_t *number)
{
    QString cmd = QString("get ");
    cmd += getObjName();
    cmd += ".val";
    sendCommand(cmd.toStdString().c_str());
    return recvRetNumber(number);
}

bool NexRadio::setValue(uint32_t number)
{
    QString cmd;
    
    cmd += getObjName();
    cmd += ".val=";
    cmd += QString::number(static_cast<ulong>(number));

    sendCommand(cmd.toStdString().c_str());
    return recvRetCommandFinished();
}

uint32_t NexRadio::Get_background_color_bco(uint32_t *number)
{
    QString cmd;
    cmd += "get ";
    cmd += getObjName();
    cmd += ".bco";
    sendCommand(cmd.toStdString().c_str());
    return recvRetNumber(number);
}

bool NexRadio::Set_background_color_bco(uint32_t number)
{
    QString cmd;
    
    cmd += getObjName();
    cmd += ".bco=";
    cmd += QString::number(static_cast<ulong>(number));
    sendCommand(cmd.toStdString().c_str());
	
    cmd="";
    cmd += "ref ";
    cmd += getObjName();
    sendCommand(cmd.toStdString().c_str());
    return recvRetCommandFinished();
}

uint32_t NexRadio::Get_font_color_pco(uint32_t *number)
{
    QString cmd;
    cmd += "get ";
    cmd += getObjName();
    cmd += ".pco";
    sendCommand(cmd.toStdString().c_str());
    return recvRetNumber(number);
}

bool NexRadio::Set_font_color_pco(uint32_t number)
{
    QString cmd;
    
    cmd += getObjName();
    cmd += ".pco=";
    cmd += QString::number(static_cast<ulong>(number));
    sendCommand(cmd.toStdString().c_str());
	
    cmd = "";
    cmd += "ref ";
    cmd += getObjName();
    sendCommand(cmd.toStdString().c_str());
    return recvRetCommandFinished();
}
