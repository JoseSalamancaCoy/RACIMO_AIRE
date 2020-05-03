/**
 * @file NexTimer.cpp
 *
 * The implementation of class NexTimer. 
 *
 * @author  huang xianming (email:<xianming.huang@itead.cc>)
 * @date    2015/8/26
 * @copyright 
 * Copyright (C) 2014-2015 ITEAD Intelligent Systems Co., Ltd. \n
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 */

#include "NexTimer.h"

NexTimer::NexTimer(NextionRaspberrypi *Seriall,uint8_t pid, uint8_t cid, const char *name)
    :NexTouch(Seriall,pid, cid, name)
{
    Serial=Seriall;
}

void NexTimer::attachTimer(NexTouchEventCb timer, void *ptr)
{
    NexTouch::attachPop(timer, ptr);
}

void NexTimer::detachTimer(void)
{
    NexTouch::detachPop();
}

bool NexTimer::getCycle(uint32_t *number)
{
    QString cmd = QString("get ");
    cmd += getObjName();
    cmd += ".tim";
    sendCommand(Serial, cmd.toStdString().c_str());
    return recvRetNumber(Serial, number);
}

bool NexTimer::setCycle(uint32_t number)
{
    QString cmd;
    if (number < 50)
    {
        number = 50;
    }
    cmd += getObjName();
    cmd += ".tim=";
    cmd += QString::number(static_cast<ulong>(number));

    sendCommand(Serial, cmd.toStdString().c_str());
    return recvRetCommandFinished(Serial);
}


bool NexTimer::enable(void)
{

    QString cmd;
    cmd += getObjName();
    cmd += ".en=";
    cmd += QString::number(static_cast<long>(1));

    sendCommand(Serial, cmd.toStdString().c_str());
    return recvRetCommandFinished(Serial);
}

bool NexTimer::disable(void)
{
    QString cmd;
    cmd += getObjName();
    cmd += ".en=";
    cmd += QString::number(static_cast<long>(0));

    sendCommand(Serial, cmd.toStdString().c_str());
    return recvRetCommandFinished(Serial);
}

uint32_t NexTimer::Get_cycle_tim(uint32_t *number)
{
    QString cmd = QString("get ");
    cmd += getObjName();
    cmd += ".tim";
    sendCommand(Serial, cmd.toStdString().c_str());
    return recvRetNumber(Serial, number);
}

bool NexTimer::Set_cycle_tim(uint32_t number)
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

