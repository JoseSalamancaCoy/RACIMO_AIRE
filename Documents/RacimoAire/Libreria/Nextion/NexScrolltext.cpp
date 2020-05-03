/**
 * @file NexScrolltext.cpp
 *
 * The implementation of class NexScrolltext. 
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
#include "NexScrolltext.h"

NexScrolltext::NexScrolltext(NextionRaspberrypi *Seriall,uint8_t pid, uint8_t cid, const char *name)
    :NexTouch(Seriall,pid, cid, name)
{
    Serial=Seriall;
}

uint16_t NexScrolltext::getText(char *buffer, uint16_t len)
{
    QString cmd;
    cmd += "get ";
    cmd += getObjName();
    cmd += ".txt";
    sendCommand(Serial, cmd.toStdString().c_str());
    return recvRetString(Serial,buffer,len);
}

bool NexScrolltext::setText(const char *buffer)
{
    QString cmd;
    cmd += getObjName();
    cmd += ".txt=\"";
    cmd += buffer;
    cmd += "\"";
    sendCommand(Serial, cmd.toStdString().c_str());
    return recvRetCommandFinished(Serial);
}

uint32_t NexScrolltext::Get_background_color_bco(uint32_t *number)
{
    QString cmd;
    cmd += "get ";
    cmd += getObjName();
    cmd += ".bco";
    sendCommand(Serial, cmd.toStdString().c_str());
    return recvRetNumber(Serial, number);
}

bool NexScrolltext::Set_background_color_bco(uint32_t number)
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

uint32_t NexScrolltext::Get_font_color_pco(uint32_t *number)
{
    QString cmd;
    cmd += "get ";
    cmd += getObjName();
    cmd += ".pco";
    sendCommand(Serial, cmd.toStdString().c_str());
    return recvRetNumber(Serial, number);
}

bool NexScrolltext::Set_font_color_pco(uint32_t number)
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

uint32_t NexScrolltext::Get_place_xcen(uint32_t *number)
{
    QString cmd;
    cmd += "get ";
    cmd += getObjName();
    cmd += ".xcen";
    sendCommand(Serial, cmd.toStdString().c_str());
    return recvRetNumber(Serial, number);
}

bool NexScrolltext::Set_place_xcen(uint32_t number)
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

uint32_t NexScrolltext::Get_place_ycen(uint32_t *number)
{
    QString cmd;
    cmd += "get ";
    cmd += getObjName();
    cmd += ".ycen";
    sendCommand(Serial, cmd.toStdString().c_str());
    return recvRetNumber(Serial, number);
}

bool NexScrolltext::Set_place_ycen(uint32_t number)
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

uint32_t NexScrolltext::getFont(uint32_t *number)
{
    QString cmd;
    cmd += "get ";
    cmd += getObjName();
    cmd += ".font";
    sendCommand(Serial, cmd.toStdString().c_str());
    return recvRetNumber(Serial, number);
}

bool NexScrolltext::setFont(uint32_t number)
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

uint32_t NexScrolltext::Get_background_crop_picc(uint32_t *number)
{
    QString cmd;
    cmd += "get ";
    cmd += getObjName();
    cmd += ".picc";
    sendCommand(Serial, cmd.toStdString().c_str());
    return recvRetNumber(Serial, number);
}

bool NexScrolltext::Set_background_crop_picc(uint32_t number)
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

uint32_t NexScrolltext::Get_background_image_pic(uint32_t *number)
{
    QString cmd = QString("get ");
    cmd += getObjName();
    cmd += ".pic";
    sendCommand(Serial, cmd.toStdString().c_str());
    return recvRetNumber(Serial, number);
}

bool NexScrolltext::Set_background_image_pic(uint32_t number)
{
    QString cmd;
    
    cmd += getObjName();
    cmd += ".pic=";
    cmd += QString::number(static_cast<ulong>(number));
    sendCommand(Serial, cmd.toStdString().c_str());
	
    cmd = "";
    cmd += "ref ";
    cmd += getObjName();
    sendCommand(Serial, cmd.toStdString().c_str());
    return recvRetCommandFinished(Serial);
}

uint32_t NexScrolltext::Get_scroll_dir(uint32_t *number)
{
    QString cmd = QString("get ");
    cmd += getObjName();
    cmd += ".dir";
    sendCommand(Serial, cmd.toStdString().c_str());
    return recvRetNumber(Serial, number);
}

bool NexScrolltext::Set_scroll_dir(uint32_t number)
{
    QString cmd;
    
    cmd += getObjName();
    cmd += ".dir=";
    cmd += QString::number(static_cast<ulong>(number));
    sendCommand(Serial, cmd.toStdString().c_str());
	
    cmd = "";
    cmd += "ref ";
    cmd += getObjName();
    sendCommand(Serial, cmd.toStdString().c_str());
    return recvRetCommandFinished(Serial);
}

uint32_t NexScrolltext::Get_scroll_distance(uint32_t *number)
{
    QString cmd = QString("get ");
    cmd += getObjName();
    cmd += ".dis";
    sendCommand(Serial, cmd.toStdString().c_str());
    return recvRetNumber(Serial, number);
}

bool NexScrolltext::Set_scroll_distance(uint32_t number)
{
    QString cmd;
    
    if (number < 2)
    {
        number = 2;
    }
    cmd += getObjName();
    cmd += ".dis=";
    cmd += QString::number(static_cast<ulong>(number));
    sendCommand(Serial, cmd.toStdString().c_str());
	
    cmd = "";
    cmd += "ref ";
    cmd += getObjName();
    sendCommand(Serial, cmd.toStdString().c_str());
    return recvRetCommandFinished(Serial);
}

uint32_t NexScrolltext::Get_cycle_tim(uint32_t *number)
{
    QString cmd = QString("get ");
    cmd += getObjName();
    cmd += ".tim";
    sendCommand(Serial, cmd.toStdString().c_str());
    return recvRetNumber(Serial, number);
}

bool NexScrolltext::Set_cycle_tim(uint32_t number)
{
    QString cmd;
    if (number < 8)
    {
        number = 8;
    }
    cmd += getObjName();
    cmd += ".tim=";
    cmd += QString::number(static_cast<ulong>(number));
    sendCommand(Serial, cmd.toStdString().c_str());
	
    cmd = "";
    cmd += "ref ";
    cmd += getObjName();
    sendCommand(Serial, cmd.toStdString().c_str());
    return recvRetCommandFinished(Serial);
}


bool NexScrolltext::enable(void)
{
    QString cmd;
    cmd += getObjName();
    cmd += ".en=";
    cmd += QString::number(static_cast<long>(1));

    sendCommand(Serial, cmd.toStdString().c_str());
    return recvRetCommandFinished(Serial);
}

bool NexScrolltext::disable(void)
{
    QString cmd;
    cmd += getObjName();
    cmd += ".en=";
    cmd += QString::number(static_cast<long>(0));

    sendCommand(Serial, cmd.toStdString().c_str());
    return recvRetCommandFinished(Serial);
}
