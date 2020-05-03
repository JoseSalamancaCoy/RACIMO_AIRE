/**
 * @file NexNumber.cpp
 *
 * The implementation of class NexNumber. 
 *
 * @author  huang xianming (email:<xianming.huang@itead.cc>)
 * @date    2015/8/13
 * @copyright 
 * Copyright (C) 2014-2015 ITEAD Intelligent Systems Co., Ltd. \n
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 */
#include "NexNumber.h"

NexNumber::NexNumber(uint8_t pid, uint8_t cid, const char *name)
    :NexTouch(pid, cid, name)
{
}

bool NexNumber::getValue(uint32_t *number)
{
    QString cmd = QString("get ");
    cmd += getObjName();
    cmd += ".val";
    sendCommand(cmd.toStdString().c_str());
    return recvRetNumber(number);
}

bool NexNumber::setValue(uint32_t number)
{
    QString cmd;
    
    cmd += getObjName();
    cmd += ".val=";
    cmd += QString::number(static_cast<ulong>(number));

    sendCommand(cmd.toStdString().c_str());
    return recvRetCommandFinished();
}

uint32_t NexNumber::Get_background_color_bco(uint32_t *number)
{
    QString cmd;
    cmd += "get ";
    cmd += getObjName();
    cmd += ".bco";
    sendCommand(cmd.toStdString().c_str());
    return recvRetNumber(number);
}

bool NexNumber::Set_background_color_bco(uint32_t number)
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

uint32_t NexNumber::Get_font_color_pco(uint32_t *number)
{
    QString cmd;
    cmd += "get ";
    cmd += getObjName();
    cmd += ".pco";
    sendCommand(cmd.toStdString().c_str());
    return recvRetNumber(number);
}

bool NexNumber::Set_font_color_pco(uint32_t number)
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

uint32_t NexNumber::Get_place_xcen(uint32_t *number)
{
    QString cmd;
    cmd += "get ";
    cmd += getObjName();
    cmd += ".xcen";
    sendCommand(cmd.toStdString().c_str());
    return recvRetNumber(number);
}

bool NexNumber::Set_place_xcen(uint32_t number)
{
    QString cmd;
    
    cmd += getObjName();
    cmd += ".xcen=";
    cmd += QString::number(static_cast<ulong>(number));
    sendCommand(cmd.toStdString().c_str());
	
    cmd = "";
    cmd += "ref ";
    cmd += getObjName();
    sendCommand(cmd.toStdString().c_str());
    return recvRetCommandFinished();
}

uint32_t NexNumber::Get_place_ycen(uint32_t *number)
{
    QString cmd;
    cmd += "get ";
    cmd += getObjName();
    cmd += ".ycen";
    sendCommand(cmd.toStdString().c_str());
    return recvRetNumber(number);
}

bool NexNumber::Set_place_ycen(uint32_t number)
{
    QString cmd;
    
    cmd += getObjName();
    cmd += ".ycen=";
    cmd += QString::number(static_cast<ulong>(number));
    sendCommand(cmd.toStdString().c_str());
	
    cmd = "";
    cmd += "ref ";
    cmd += getObjName();
    sendCommand(cmd.toStdString().c_str());
    return recvRetCommandFinished();
}

uint32_t NexNumber::getFont(uint32_t *number)
{
    QString cmd;
    cmd += "get ";
    cmd += getObjName();
    cmd += ".font";
    sendCommand(cmd.toStdString().c_str());
    return recvRetNumber(number);
}

bool NexNumber::setFont(uint32_t number)
{
    QString cmd;
    
    cmd += getObjName();
    cmd += ".font=";
    cmd += QString::number(static_cast<ulong>(number));
    sendCommand(cmd.toStdString().c_str());

    cmd = "";
    cmd += "ref ";
    cmd += getObjName();
    sendCommand(cmd.toStdString().c_str());
    return recvRetCommandFinished();
}

uint32_t NexNumber::Get_number_lenth(uint32_t *number)
{
    QString cmd;
    cmd += "get ";
    cmd += getObjName();
    cmd += ".lenth";
    sendCommand(cmd.toStdString().c_str());
    return recvRetNumber(number);
}

bool NexNumber::Set_number_lenth(uint32_t number)
{
    QString cmd;
    
    cmd += getObjName();
    cmd += ".lenth=";
    cmd += QString::number(static_cast<ulong>(number));
    sendCommand(cmd.toStdString().c_str());

    cmd = "";
    cmd += "ref ";
    cmd += getObjName();
    sendCommand(cmd.toStdString().c_str());
    return recvRetCommandFinished();
}

uint32_t NexNumber::Get_background_crop_picc(uint32_t *number)
{
    QString cmd;
    cmd += "get ";
    cmd += getObjName();
    cmd += ".picc";
    sendCommand(cmd.toStdString().c_str());
    return recvRetNumber(number);
}

bool NexNumber::Set_background_crop_picc(uint32_t number)
{
    QString cmd;
    
    cmd += getObjName();
    cmd += ".picc=";
    cmd += QString::number(static_cast<ulong>(number));
    sendCommand(cmd.toStdString().c_str());
	
    cmd = "";
    cmd += "ref ";
    cmd += getObjName();
    sendCommand(cmd.toStdString().c_str());
    return recvRetCommandFinished();
}

uint32_t NexNumber::Get_background_image_pic(uint32_t *number)
{
    QString cmd = QString("get ");
    cmd += getObjName();
    cmd += ".pic";
    sendCommand(cmd.toStdString().c_str());
    return recvRetNumber(number);
}

bool NexNumber::Set_background_image_pic(uint32_t number)
{
    QString cmd;
    
    cmd += getObjName();
    cmd += ".pic=";
    cmd += QString::number(static_cast<ulong>(number));
    sendCommand(cmd.toStdString().c_str());
	
    cmd = "";
    cmd += "ref ";
    cmd += getObjName();
    sendCommand(cmd.toStdString().c_str());
    return recvRetCommandFinished();
}
