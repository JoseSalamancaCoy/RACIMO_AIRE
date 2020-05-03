/**
 * @file NexGauge.cpp
 *
 * The implementation of class NexGauge. 
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

#include "NexGauge.h"

NexGauge::NexGauge(NextionRaspberrypi *Seriall,uint8_t pid, uint8_t cid, const char *name)
    :NexObject(Seriall,pid, cid, name)
{
    Serial=Seriall;
}

bool NexGauge::getValue(uint32_t *number)
{
    QString cmd = QString("get ");
    cmd += getObjName();
    cmd += ".val";
    sendCommand(Serial, cmd.toStdString().c_str());
    return recvRetNumber(Serial, number);
}

bool NexGauge::setValue(uint32_t number)
{
    QString cmd;
    
    cmd += getObjName();
    cmd += ".val=";
    cmd += QString::number(static_cast<ulong>(number));

    sendCommand(Serial, cmd.toStdString().c_str());
    return recvRetCommandFinished(Serial);
}

uint32_t NexGauge::Get_background_color_bco(uint32_t *number)
{
    QString cmd;
    cmd += "get ";
    cmd += getObjName();
    cmd += ".bco";
    sendCommand(Serial, cmd.toStdString().c_str());
    return recvRetNumber(Serial, number);
}

bool NexGauge::Set_background_color_bco(uint32_t number)
{
    QString cmd;
    
    cmd += getObjName();
    cmd += ".bco=";
    cmd += QString::number(static_cast<ulong>(number));
    sendCommand(Serial, cmd.toStdString().c_str());
	
    cmd="";
    cmd += "ref ";
    cmd += getObjName();
    sendCommand(Serial, cmd.toStdString().c_str());
    return recvRetCommandFinished(Serial);
}

uint32_t NexGauge::Get_font_color_pco(uint32_t *number)
{
    QString cmd;
    cmd += "get ";
    cmd += getObjName();
    cmd += ".pco";
    sendCommand(Serial, cmd.toStdString().c_str());
    return recvRetNumber(Serial, number);
}

bool NexGauge::Set_font_color_pco(uint32_t number)
{
    QString cmd;
    
    cmd += getObjName();
    cmd += ".pco=";
    cmd += QString::number(static_cast<ulong>(number));
    sendCommand(Serial, cmd.toStdString().c_str());
	
    cmd = "";
    cmd += "ref ";
    cmd += getObjName();
    sendCommand(Serial, cmd.toStdString().c_str());
    return recvRetCommandFinished(Serial);
}

uint32_t NexGauge::Get_pointer_thickness_wid(uint32_t *number)
{
    QString cmd;
    cmd += "get ";
    cmd += getObjName();
    cmd += ".wid";
    sendCommand(Serial, cmd.toStdString().c_str());
    return recvRetNumber(Serial, number);
}

bool NexGauge::Set_pointer_thickness_wid(uint32_t number)
{
    QString cmd;
    
    cmd += getObjName();
    cmd += ".wid=";
    cmd += QString::number(static_cast<ulong>(number));
    sendCommand(Serial, cmd.toStdString().c_str());
	
    cmd = "";
    cmd += "ref ";
    cmd += getObjName();
    sendCommand(Serial, cmd.toStdString().c_str());
    return recvRetCommandFinished(Serial);
}

uint32_t NexGauge::Get_background_cropi_picc(uint32_t *number)
{
    QString cmd;
    cmd += "get ";
    cmd += getObjName();
    cmd += ".picc";
    sendCommand(Serial, cmd.toStdString().c_str());
    return recvRetNumber(Serial, number);
}

bool NexGauge::Set_background_crop_picc(uint32_t number)
{
    QString cmd;
    
    cmd += getObjName();
    cmd += ".picc=";
    cmd += QString::number(static_cast<ulong>(number));
    sendCommand(Serial, cmd.toStdString().c_str());
	
    cmd = "";
    cmd += "ref ";
    cmd += getObjName();
    sendCommand(Serial, cmd.toStdString().c_str());
    return recvRetCommandFinished(Serial);
}

 
