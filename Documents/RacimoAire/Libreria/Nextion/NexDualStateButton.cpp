/**
 * @file NexDualStateButton.cpp
 *
 * The implementation of class NexDSButton. 
 *
 * @author  huang xianming (email:<xianming.huang@itead.cc>)
 * @date    2015/11/11
 * @copyright 
 * Copyright (C) 2014-2015 ITEAD Intelligent Systems Co., Ltd. \n
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 */

#include "NexDualStateButton.h"

NexDSButton::NexDSButton(NextionRaspberrypi *Seriall,uint8_t pid, uint8_t cid, const char *name)
    :NexTouch(Seriall,pid, cid, name)
{
    Serial=Seriall;
}

bool NexDSButton::getValue(uint32_t *number)
{
    QString cmd = QString("get ");
    cmd += getObjName();
    cmd += ".val";
    sendCommand(Serial, cmd.toStdString().c_str());
    return recvRetNumber(Serial, number);
}

bool NexDSButton::setValue(uint32_t number)
{
    QString cmd;
    
    cmd += getObjName();
    cmd += ".val=";
    cmd += QString::number(static_cast<ulong>(number));

    sendCommand(Serial, cmd.toStdString().c_str());
    return recvRetCommandFinished(Serial);
}

uint16_t NexDSButton::getText(char *buffer, uint16_t len)
{
    QString cmd;
    cmd += "get ";
    cmd += getObjName();
    cmd += ".txt";
    sendCommand(Serial, cmd.toStdString().c_str());
    return recvRetString(Serial,buffer,len);
}

bool NexDSButton::setText(const char *buffer)
{
    QString cmd;
    cmd += getObjName();
    cmd += ".txt=\"";
    cmd += buffer;
    cmd += "\"";
    sendCommand(Serial, cmd.toStdString().c_str());
    return recvRetCommandFinished(Serial);
}

uint32_t NexDSButton::Get_state0_color_bco0(uint32_t *number)
{
    QString cmd;
    cmd += "get ";
    cmd += getObjName();
    cmd += ".bco0";
    sendCommand(Serial, cmd.toStdString().c_str());
    return recvRetNumber(Serial, number);
}

bool NexDSButton::Set_state0_color_bco0(uint32_t number)
{
    QString cmd;
    
    cmd += getObjName();
    cmd += ".bco0=";
    cmd += QString::number(static_cast<ulong>(number));
    sendCommand(Serial, cmd.toStdString().c_str());

    cmd="";
    cmd += "ref ";
    cmd += getObjName();
    sendCommand(Serial, cmd.toStdString().c_str());
    return recvRetCommandFinished(Serial);
}

uint32_t NexDSButton::Get_state1_color_bco1(uint32_t *number)
{
    QString cmd;
    cmd += "get ";
    cmd += getObjName();
    cmd += ".bco1";
    sendCommand(Serial, cmd.toStdString().c_str());
    return recvRetNumber(Serial, number);
}

bool NexDSButton::Set_state1_color_bco1(uint32_t number)
{
    QString cmd;
    
    cmd += getObjName();
    cmd += ".bco1=";
    cmd += QString::number(static_cast<ulong>(number));
    sendCommand(Serial, cmd.toStdString().c_str());
	
    cmd="";
    cmd += "ref ";
    cmd += getObjName();
    sendCommand(Serial, cmd.toStdString().c_str());
    return recvRetCommandFinished(Serial);
}

uint32_t NexDSButton::Get_font_color_pco(uint32_t *number)
{
    QString cmd;
    cmd += "get ";
    cmd += getObjName();
    cmd += ".pco";
    sendCommand(Serial, cmd.toStdString().c_str());
    return recvRetNumber(Serial, number);
}

bool NexDSButton::Set_font_color_pco(uint32_t number)
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

uint32_t NexDSButton::Get_place_xcen(uint32_t *number)
{
    QString cmd;
    cmd += "get ";
    cmd += getObjName();
    cmd += ".xcen";
    sendCommand(Serial, cmd.toStdString().c_str());
    return recvRetNumber(Serial, number);
}

bool NexDSButton::Set_place_xcen(uint32_t number)
{
    QString cmd;
    
    cmd += getObjName();
    cmd += ".xcen=";
    cmd += QString::number(static_cast<ulong>(number));
    sendCommand(Serial, cmd.toStdString().c_str());
	
    cmd = "";
    cmd += "ref ";
    cmd += getObjName();
    sendCommand(Serial, cmd.toStdString().c_str());
    return recvRetCommandFinished(Serial);
}

uint32_t NexDSButton::Get_place_ycen(uint32_t *number)
{
    QString cmd;
    cmd += "get ";
    cmd += getObjName();
    cmd += ".ycen";
    sendCommand(Serial, cmd.toStdString().c_str());
    return recvRetNumber(Serial, number);
}

bool NexDSButton::Set_place_ycen(uint32_t number)
{
    QString cmd;
    
    cmd += getObjName();
    cmd += ".ycen=";
    cmd += QString::number(static_cast<ulong>(number));
    sendCommand(Serial, cmd.toStdString().c_str());
	
    cmd = "";
    cmd += "ref ";
    cmd += getObjName();
    sendCommand(Serial, cmd.toStdString().c_str());
    return recvRetCommandFinished(Serial);
}

uint32_t NexDSButton::getFont(uint32_t *number)
{
    QString cmd;
    cmd += "get ";
    cmd += getObjName();
    cmd += ".font";
    sendCommand(Serial, cmd.toStdString().c_str());
    return recvRetNumber(Serial, number);
}

bool NexDSButton::setFont(uint32_t number)
{
    QString cmd;
    
    cmd += getObjName();
    cmd += ".font=";
    cmd += QString::number(static_cast<ulong>(number));
    sendCommand(Serial, cmd.toStdString().c_str());

    cmd = "";
    cmd += "ref ";
    cmd += getObjName();
    sendCommand(Serial, cmd.toStdString().c_str());
    return recvRetCommandFinished(Serial);
}

uint32_t NexDSButton::Get_state0_crop_picc0(uint32_t *number)
{
    QString cmd;
    cmd += "get ";
    cmd += getObjName();
    cmd += ".picc0";
    sendCommand(Serial, cmd.toStdString().c_str());
    return recvRetNumber(Serial, number);
}

bool NexDSButton::Set_state0_crop_picc0(uint32_t number)
{
    QString cmd;
    
    cmd += getObjName();
    cmd += ".picc0=";
    cmd += QString::number(static_cast<ulong>(number));
    sendCommand(Serial, cmd.toStdString().c_str());
	
    cmd = "";
    cmd += "ref ";
    cmd += getObjName();
    sendCommand(Serial, cmd.toStdString().c_str());
    return recvRetCommandFinished(Serial);
}

uint32_t NexDSButton::Get_state1_crop_picc1(uint32_t *number)
{
    QString cmd;
    cmd += "get ";
    cmd += getObjName();
    cmd += ".picc1";
    sendCommand(Serial, cmd.toStdString().c_str());
    return recvRetNumber(Serial, number);
}

bool NexDSButton::Set_state1_crop_picc1(uint32_t number)
{
    QString cmd;
    
    cmd += getObjName();
    cmd += ".picc1=";
    cmd += QString::number(static_cast<ulong>(number));
    sendCommand(Serial, cmd.toStdString().c_str());
	
    cmd = "";
    cmd += "ref ";
    cmd += getObjName();
    sendCommand(Serial, cmd.toStdString().c_str());
    return recvRetCommandFinished(Serial);
}

uint32_t NexDSButton::Get_state0_image_pic0(uint32_t *number)
{
    QString cmd;
    cmd += "get ";
    cmd += getObjName();
    cmd += ".pic0";
    sendCommand(Serial, cmd.toStdString().c_str());
    return recvRetNumber(Serial, number);
}

bool NexDSButton::Set_state0_image_pic0(uint32_t number)
{
    QString cmd;
    
    cmd += getObjName();
    cmd += ".pic0=";
    cmd += QString::number(static_cast<ulong>(number));
    sendCommand(Serial, cmd.toStdString().c_str());
	
    cmd = "";
    cmd += "ref ";
    cmd += getObjName();
    sendCommand(Serial, cmd.toStdString().c_str());
    return recvRetCommandFinished(Serial);
}

uint32_t NexDSButton::Get_state1_image_pic1(uint32_t *number)
{
    QString cmd;
    cmd += "get ";
    cmd += getObjName();
    cmd += ".pic1";
    sendCommand(Serial, cmd.toStdString().c_str());
    return recvRetNumber(Serial, number);
}

bool NexDSButton::Set_state1_image_pic1(uint32_t number)
{
    QString cmd;
    
    cmd += getObjName();
    cmd += ".pic1=";
    cmd += QString::number(static_cast<ulong>(number));
    sendCommand(Serial, cmd.toStdString().c_str());
	
    cmd = "";
    cmd += "ref ";
    cmd += getObjName();
    sendCommand(Serial, cmd.toStdString().c_str());
    return recvRetCommandFinished(Serial);
}


