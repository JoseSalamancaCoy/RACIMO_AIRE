/**
 * @file NexButton.cpp
 *
 * The implementation of class NexButton.
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

#include "nexbutton.h"

NexButton::NexButton(uint8_t pid, uint8_t cid, const char *name)
    :NexTouch(pid, cid, name)
{
}

uint16_t NexButton::getText(char *buffer, uint16_t len)
{
    QString cmd;
    cmd += "get ";
    cmd += getObjName();
    cmd += ".txt";
    sendCommand(cmd.toStdString().c_str());
    return recvRetString(buffer,len);
}

bool NexButton::setText(const char *buffer)
{
    QString cmd;
    cmd += getObjName();
    cmd += ".txt=\"";
    cmd += buffer;
    cmd += "\"";
    sendCommand(cmd.toStdString().c_str());
    return recvRetCommandFinished();
}


uint32_t NexButton::Get_background_color_bco(uint32_t *number)
{
    QString cmd;
    cmd += "get ";
    cmd += getObjName();
    cmd += ".bco";
    sendCommand(cmd.toStdString().c_str());
    return recvRetNumber(number);
}

bool NexButton::Set_background_color_bco(uint32_t number)
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

uint32_t NexButton::Get_press_background_color_bco2(uint32_t *number)
{
    QString cmd;
    cmd += "get ";
    cmd += getObjName();
    cmd += ".bco2";
    sendCommand(cmd.toStdString().c_str());
    return recvRetNumber(number);
}

bool NexButton::Set_press_background_color_bco2(uint32_t number)
{
    QString cmd;

    cmd += getObjName();
    cmd += ".bco2=";
    cmd += QString::number(static_cast<ulong>(number));
    sendCommand(cmd.toStdString().c_str());

    cmd="";
    cmd += "ref ";
    cmd += getObjName();
    sendCommand(cmd.toStdString().c_str());
    return recvRetCommandFinished();
}

uint32_t NexButton::Get_font_color_pco(uint32_t *number)
{
    QString cmd;
    cmd += "get ";
    cmd += getObjName();
    cmd += ".pco";
    sendCommand(cmd.toStdString().c_str());
    return recvRetNumber(number);
}

bool NexButton::Set_font_color_pco(uint32_t number)
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

uint32_t NexButton::Get_press_font_color_pco2(uint32_t *number)
{
    QString cmd;
    cmd += "get ";
    cmd += getObjName();
    cmd += ".pco2";
    sendCommand(cmd.toStdString().c_str());
    return recvRetNumber(number);
}

bool NexButton::Set_press_font_color_pco2(uint32_t number)
{
    QString cmd;

    cmd += getObjName();
    cmd += ".pco2=";
    cmd += QString::number(static_cast<ulong>(number));
    sendCommand(cmd.toStdString().c_str());

    cmd = "";
    cmd += "ref ";
    cmd += getObjName();
    sendCommand(cmd.toStdString().c_str());
    return recvRetCommandFinished();
}

uint32_t NexButton::Get_place_xcen(uint32_t *number)
{
    QString cmd;
    cmd += "get ";
    cmd += getObjName();
    cmd += ".xcen";
    sendCommand(cmd.toStdString().c_str());
    return recvRetNumber(number);
}

bool NexButton::Set_place_xcen(uint32_t number)
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

uint32_t NexButton::Get_place_ycen(uint32_t *number)
{
    QString cmd;
    cmd += "get ";
    cmd += getObjName();
    cmd += ".ycen";
    sendCommand(cmd.toStdString().c_str());
    return recvRetNumber(number);
}

bool NexButton::Set_place_ycen(uint32_t number)
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

uint32_t NexButton::getFont(uint32_t *number)
{
    QString cmd;
    cmd += "get ";
    cmd += getObjName();
    cmd += ".font";
    sendCommand(cmd.toStdString().c_str());
    return recvRetNumber(number);
}

bool NexButton::setFont(uint32_t number)
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

uint32_t NexButton::Get_background_cropi_picc(uint32_t *number)
{
    QString cmd;
    cmd += "get ";
    cmd += getObjName();
    cmd += ".picc";
    sendCommand(cmd.toStdString().c_str());
    return recvRetNumber(number);
}

bool NexButton::Set_background_crop_picc(uint32_t number)
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

uint32_t NexButton::Get_press_background_crop_picc2(uint32_t *number)
{
    QString cmd;
    cmd += "get ";
    cmd += getObjName();
    cmd += ".picc2";
    sendCommand(cmd.toStdString().c_str());
    return recvRetNumber(number);
}

bool NexButton::Set_press_background_crop_picc2(uint32_t number)
{
    QString cmd;

    cmd += getObjName();
    cmd += ".picc2=";
    cmd += QString::number(static_cast<ulong>(number));
    sendCommand(cmd.toStdString().c_str());

    cmd = "";
    cmd += "ref ";
    cmd += getObjName();
    sendCommand(cmd.toStdString().c_str());
    return recvRetCommandFinished();
}

uint32_t NexButton::Get_background_image_pic(uint32_t *number)
{
    QString cmd;
    cmd += "get ";
    cmd += getObjName();
    cmd += ".pic";
    sendCommand(cmd.toStdString().c_str());
    return recvRetNumber(number);
}

bool NexButton::Set_background_image_pic(uint32_t number)
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

uint32_t NexButton::Get_press_background_image_pic2(uint32_t *number)
{
    QString cmd;
    cmd += "get ";
    cmd += getObjName();
    cmd += ".pic2";
    sendCommand(cmd.toStdString().c_str());
    return recvRetNumber(number);
}

bool NexButton::Set_press_background_image_pic2(uint32_t number)
{
    QString cmd;

    cmd += getObjName();
    cmd += ".pic2=";
    cmd += QString::number(static_cast<ulong>(number));
    sendCommand(cmd.toStdString().c_str());

    cmd = "";
    cmd += "ref ";
    cmd += getObjName();
    sendCommand(cmd.toStdString().c_str());
    return recvRetCommandFinished();
}
