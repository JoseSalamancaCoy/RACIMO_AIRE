/**
 * @file NexSlider.cpp
 *
 * The implementation of class NexSlider. 
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
#include "NexSlider.h"

NexSlider::NexSlider(uint8_t pid, uint8_t cid, const char *name)
    :NexTouch(pid, cid, name)
{
}

bool NexSlider::getValue(uint32_t *number)
{
    QString cmd = QString("get ");
    cmd += getObjName();
    cmd += ".val";
    sendCommand(cmd.toStdString().c_str());
    return recvRetNumber(number);
}

bool NexSlider::setValue(uint32_t number)
{
    QString cmd;
    
    cmd += getObjName();
    cmd += ".val=";
    cmd += QString::number(static_cast<ulong>(number));

    sendCommand(cmd.toStdString().c_str());
    return recvRetCommandFinished();
}

uint32_t NexSlider::Get_background_color_bco(uint32_t *number)
{
    QString cmd;
    cmd += "get ";
    cmd += getObjName();
    cmd += ".bco";
    sendCommand(cmd.toStdString().c_str());
    return recvRetNumber(number);
}

bool NexSlider::Set_background_color_bco(uint32_t number)
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

uint32_t NexSlider::Get_font_color_pco(uint32_t *number)
{
    QString cmd;
    cmd += "get ";
    cmd += getObjName();
    cmd += ".pco";
    sendCommand(cmd.toStdString().c_str());
    return recvRetNumber(number);
}

bool NexSlider::Set_font_color_pco(uint32_t number)
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

uint32_t NexSlider::Get_pointer_thickness_wid(uint32_t *number)
{
    QString cmd;
    cmd += "get ";
    cmd += getObjName();
    cmd += ".wid";
    sendCommand(cmd.toStdString().c_str());
    return recvRetNumber(number);
}

bool NexSlider::Set_pointer_thickness_wid(uint32_t number)
{
    QString cmd;
    
    cmd += getObjName();
    cmd += ".wid=";
    cmd += QString::number(static_cast<ulong>(number));
    sendCommand(cmd.toStdString().c_str());
	
    cmd = "";
    cmd += "ref ";
    cmd += getObjName();
    sendCommand(cmd.toStdString().c_str());
    return recvRetCommandFinished();
}

uint32_t NexSlider::Get_cursor_height_hig(uint32_t *number)
{
    QString cmd;
    cmd += "get ";
    cmd += getObjName();
    cmd += ".hig";
    sendCommand(cmd.toStdString().c_str());
    return recvRetNumber(number);
}

bool NexSlider::Set_cursor_height_hig(uint32_t number)
{
    QString cmd;
    
    cmd += getObjName();
    cmd += ".hig=";
    cmd += QString::number(static_cast<ulong>(number));
    sendCommand(cmd.toStdString().c_str());
	
    cmd = "";
    cmd += "ref ";
    cmd += getObjName();
    sendCommand(cmd.toStdString().c_str());
    return recvRetCommandFinished();
}

uint32_t NexSlider::getMaxval(uint32_t *number)
{
    QString cmd;
    cmd += "get ";
    cmd += getObjName();
    cmd += ".maxval";
    sendCommand(cmd.toStdString().c_str());
    return recvRetNumber(number);
}

bool NexSlider::setMaxval(uint32_t number)
{
    QString cmd;
    
    cmd += getObjName();
    cmd += ".maxval=";
    cmd += QString::number(static_cast<ulong>(number));
    sendCommand(cmd.toStdString().c_str());
	
    cmd = "";
    cmd += "ref ";
    cmd += getObjName();
    sendCommand(cmd.toStdString().c_str());
    return recvRetCommandFinished();
}

uint32_t NexSlider::getMinval(uint32_t *number)
{
    QString cmd;
    cmd += "get ";
    cmd += getObjName();
    cmd += ".minval";
    sendCommand(cmd.toStdString().c_str());
    return recvRetNumber(number);
}

bool NexSlider::setMinval(uint32_t number)
{
    QString cmd;
    
    cmd += getObjName();
    cmd += ".minval=";
    cmd += QString::number(static_cast<ulong>(number));
    sendCommand(cmd.toStdString().c_str());
	
    cmd = "";
    cmd += "ref ";
    cmd += getObjName();
    sendCommand(cmd.toStdString().c_str());
    return recvRetCommandFinished();
}
