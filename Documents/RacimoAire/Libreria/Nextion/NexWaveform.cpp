/**
 * @file NexWaveform.cpp
 *
 * The implementation of class NexWaveform. 
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
#include "NexWaveform.h"

NexWaveform::NexWaveform(NextionRaspberrypi *Seriall,uint8_t pid, uint8_t cid, const char *name)
    :NexObject(Seriall,pid, cid, name)
{
    Serial=Seriall;
}

bool NexWaveform::addValue(uint8_t ch, uint8_t number)
{
    char buf[15] = {0};
    
    if (ch > 3)
    {
        return false;
    }
    
    sprintf(buf, "add %u,%u,%u", getObjCid(), ch, number);

    sendCommand(Serial, buf);
    return true;
}

uint32_t NexWaveform::Get_background_color_bco(uint32_t *number)
{
    QString cmd;
    cmd += "get ";
    cmd += getObjName();
    cmd += ".bco";
    sendCommand(Serial, cmd.toStdString().c_str());
    return recvRetNumber(Serial, number);
}

bool NexWaveform::Set_background_color_bco(uint32_t number)
{
    QString cmd;
    
    cmd += getObjName();
    cmd += ".bco=";
    cmd += QString::number(static_cast<ulong>(number));;
    sendCommand(Serial, cmd.toStdString().c_str());

    cmd="";
    cmd += "ref ";
    cmd += getObjName();
    sendCommand(Serial, cmd.toStdString().c_str());
    return recvRetCommandFinished(Serial);
}

uint32_t NexWaveform::Get_grid_color_gdc(uint32_t *number)
{
    QString cmd;
    cmd += "get ";
    cmd += getObjName();
    cmd += ".gdc";
    sendCommand(Serial, cmd.toStdString().c_str());
    return recvRetNumber(Serial, number);
}

bool NexWaveform::Set_grid_color_gdc(uint32_t number)
{
    QString cmd;
    
    cmd += getObjName();
    cmd += ".gdc=";
    cmd += QString::number(static_cast<ulong>(number));;
    sendCommand(Serial, cmd.toStdString().c_str());
	
    cmd="";
    cmd += "ref ";
    cmd += getObjName();
    sendCommand(Serial, cmd.toStdString().c_str());
    return recvRetCommandFinished(Serial);
}

uint32_t NexWaveform::Get_grid_width_gdw(uint32_t *number)
{
    QString cmd;
    cmd += "get ";
    cmd += getObjName();
    cmd += ".gdw";
    sendCommand(Serial, cmd.toStdString().c_str());
    return recvRetNumber(Serial, number);
}

bool NexWaveform::Set_grid_width_gdw(uint32_t number)
{
    QString cmd;
    
    cmd += getObjName();
    cmd += ".gdw=";
    cmd += QString::number(static_cast<ulong>(number));;
    sendCommand(Serial, cmd.toStdString().c_str());
	
    cmd="";
    cmd += "ref ";
    cmd += getObjName();
    sendCommand(Serial, cmd.toStdString().c_str());
    return recvRetCommandFinished(Serial);
}

uint32_t NexWaveform::Get_grid_height_gdh(uint32_t *number)
{
    QString cmd;
    cmd += "get ";
    cmd += getObjName();
    cmd += ".gdh";
    sendCommand(Serial, cmd.toStdString().c_str());
    return recvRetNumber(Serial, number);
}

bool NexWaveform::Set_grid_height_gdh(uint32_t number)
{
    QString cmd;
    
    cmd += getObjName();
    cmd += ".gdh=";
    cmd += QString::number(static_cast<ulong>(number));;
    sendCommand(Serial, cmd.toStdString().c_str());
	
    cmd="";
    cmd += "ref ";
    cmd += getObjName();
    sendCommand(Serial, cmd.toStdString().c_str());
    return recvRetCommandFinished(Serial);
}

uint32_t NexWaveform::Get_channel_0_color_pco0(uint32_t *number)
{
    QString cmd;
    cmd += "get ";
    cmd += getObjName();
    cmd += ".pco0";
    sendCommand(Serial, cmd.toStdString().c_str());
    return recvRetNumber(Serial, number);
}

bool NexWaveform::Set_channel_0_color_pco0(uint32_t number)
{    
    QString cmd;
    
    cmd += getObjName();
    cmd += ".pco0=";
    cmd += QString::number(static_cast<ulong>(number));
    sendCommand(Serial, cmd.toStdString().c_str());
	
    cmd="";
    cmd += "ref ";
    cmd += getObjName();
    sendCommand(Serial, cmd.toStdString().c_str());
    return recvRetCommandFinished(Serial);
}
 
