/**
 * @file NexRtc.cpp
 *
 * The implementation of class NexRtc. 
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
#include "NexRtc.h"

NexRtc::NexRtc(NextionRaspberrypi *Seriall)
{
    Serial=Seriall;
}

bool NexRtc::write_rtc_time(char *time)
{
    char year[5],mon[3],day[3],hour[3],min[3],sec[3];
    QString cmd = QString("rtc");
    int i;
    
    if(strlen(time) >= 19)
    {
        year[0]=time[0];year[1]=time[1];year[2]=time[2];year[3]=time[3];year[4]='\0';
        mon[0]=time[5];mon[1]=time[6];mon[2]='\0';
        day[0]=time[8];day[1]=time[9];day[2]='\0';
        hour[0]=time[11];hour[1]=time[12];hour[2]='\0';
        min[0]=time[14];min[1]=time[15];min[2]='\0';
        sec[0]=time[17];sec[1]=time[18];sec[2]='\0';
        
        cmd += "0=";
        cmd += year;
        sendCommand(Serial, cmd.toStdString().c_str());
        recvRetCommandFinished(Serial);
        
        cmd = "";
        cmd += "rtc1=";
        cmd += mon;
        sendCommand(Serial, cmd.toStdString().c_str());
        recvRetCommandFinished(Serial);
        
        cmd = "";
        cmd += "rtc2=";
        cmd += day;
        sendCommand(Serial, cmd.toStdString().c_str());
        recvRetCommandFinished(Serial);
        
        cmd = "";
        cmd += "rtc3=";
        cmd += hour;
        sendCommand(Serial, cmd.toStdString().c_str());
        recvRetCommandFinished(Serial);
        
        cmd = "";
        cmd += "rtc4=";
        cmd += min;
        sendCommand(Serial, cmd.toStdString().c_str());
        recvRetCommandFinished(Serial);
        
        cmd = "";
        cmd += "rtc5=";
        cmd += sec;
        sendCommand(Serial, cmd.toStdString().c_str());
        recvRetCommandFinished(Serial);
        
    }
    else
    {
        return false;
    }
}

bool NexRtc::write_rtc_time(uint32_t *time)
{
    QString cmd = QString("rtc");
    
    QString year,mon,day,hour,min,sec;
    year = QString::number(static_cast<long>(time[0]));
    mon = QString::number(static_cast<long>(time[1]));
    day = QString::number(static_cast<long>(time[2]));
    hour = QString::number(static_cast<long>(time[3]));
    min = QString::number(static_cast<long>(time[4]));
    sec = QString::number(static_cast<long>(time[5]));

        
     cmd += "0=";
     cmd += year;
     sendCommand(Serial, cmd.toStdString().c_str());
     recvRetCommandFinished(Serial);
        
     cmd = "";
     cmd += "rtc1=";
     cmd += mon;
     sendCommand(Serial, cmd.toStdString().c_str());
     recvRetCommandFinished(Serial);
        
     cmd = "";
     cmd += "rtc2=";
     cmd += day;
     sendCommand(Serial, cmd.toStdString().c_str());
     recvRetCommandFinished(Serial);
        
     cmd = "";
     cmd += "rtc3=";
     cmd += hour;
     sendCommand(Serial, cmd.toStdString().c_str());
     recvRetCommandFinished(Serial);
        
     cmd = "";
     cmd += "rtc4=";
     cmd += min;
     sendCommand(Serial, cmd.toStdString().c_str());
     recvRetCommandFinished(Serial);
        
     cmd = "";
     cmd += "rtc5=";
     cmd += sec;
     sendCommand(Serial, cmd.toStdString().c_str());
     recvRetCommandFinished(Serial);
 
}

bool NexRtc::write_rtc_time(char *time_type,uint32_t number)
{
    QString cmd = QString("rtc");
    
    if(strstr(time_type,"year"))
    {
        cmd += "0=";
        cmd += QString::number(static_cast<ulong>(number));;
    }
    if(strstr(time_type,"mon"))
    {
        cmd += "1=";
        cmd += QString::number(static_cast<ulong>(number));;
    }
    if(strstr(time_type,"day"))
    {
        cmd += "2=";
        cmd += QString::number(static_cast<ulong>(number));;
    }
    if(strstr(time_type,"hour"))
    {
        cmd += "3=";
        cmd += QString::number(static_cast<ulong>(number));;
    }
    if(strstr(time_type,"min"))
    {
        cmd += "4=";
        cmd += QString::number(static_cast<ulong>(number));;
    }
    if(strstr(time_type,"sec"))
    {
        cmd += "5=";
        cmd += QString::number(static_cast<ulong>(number));;
    }
    
    sendCommand(Serial, cmd.toStdString().c_str());
    return recvRetCommandFinished(Serial);
}

uint32_t NexRtc::read_rtc_time(char *time,uint32_t len)
{
    char time_buf[22] = {"0000/00/00 00:00:00 0"};
    uint32_t year,mon,day,hour,min,sec,week;
    QString cmd;
    
    cmd = "get rtc0";
    sendCommand(Serial, cmd.toStdString().c_str());
    recvRetNumber(Serial, &year);
    
    cmd = "";
    cmd = "get rtc1";
    sendCommand(Serial, cmd.toStdString().c_str());
    recvRetNumber(Serial, &mon);
    
    cmd = "";
    cmd = "get rtc2";
    sendCommand(Serial, cmd.toStdString().c_str());
    recvRetNumber(Serial, &day);
    
    cmd = "";
    cmd = "get rtc3";
    sendCommand(Serial, cmd.toStdString().c_str());
    recvRetNumber(Serial, &hour);
    
    cmd = "";
    cmd = "get rtc4";
    sendCommand(Serial, cmd.toStdString().c_str());
    recvRetNumber(Serial, &min);
    
    cmd = "";
    cmd = "get rtc5";
    sendCommand(Serial, cmd.toStdString().c_str());
    recvRetNumber(Serial, &sec);
    
    cmd = "";
    cmd = "get rtc6";
    sendCommand(Serial, cmd.toStdString().c_str());
    recvRetNumber(Serial, &week);
    
    time_buf[0] = year/1000 + '0';
    time_buf[1] = (year/100)%10 + '0';
    time_buf[2] = (year/10)%10 + '0';
    time_buf[3] = year%10 + '0';
    time_buf[5] = mon/10 + '0';
    time_buf[6] = mon%10 + '0';
    time_buf[8] = day/10 + '0';
    time_buf[9] = day%10 + '0';
    time_buf[11] = hour/10 + '0';
    time_buf[12] = hour%10 + '0';
    time_buf[14] = min/10 + '0';
    time_buf[15] = min%10 + '0';
    time_buf[17] = sec/10 + '0';
    time_buf[18] = sec%10 + '0';
    time_buf[20] = week + '0';
    time_buf[21] = '\0';
    
    
    if(len >= 22)
    {
        for(uint i=0;i<22;i++)
        {
            time[i] = time_buf[i];
        }
    }
    else{
        for(uint i=0;i<len;i++)
        {
            time[i] = time_buf[i];
        }
    }   
  
}

uint32_t NexRtc::read_rtc_time(uint32_t *time,uint32_t len)
{
    uint32_t time_buf[7] = {0};
    QString cmd;
    
    cmd = "get rtc0";
    sendCommand(Serial, cmd.toStdString().c_str());
    recvRetNumber(Serial, &time_buf[0]);
    
    cmd = "";
    cmd = "get rtc1";
    sendCommand(Serial, cmd.toStdString().c_str());
    recvRetNumber(Serial, &time_buf[1]);
    
    cmd = "";
    cmd = "get rtc2";
    sendCommand(Serial, cmd.toStdString().c_str());
    recvRetNumber(Serial, &time_buf[2]);
    
    cmd = "";
    cmd = "get rtc3";
    sendCommand(Serial, cmd.toStdString().c_str());
    recvRetNumber(Serial, &time_buf[3]);
    
    cmd = "";
    cmd = "get rtc4";
    sendCommand(Serial, cmd.toStdString().c_str());
    recvRetNumber(Serial, &time_buf[4]);
    
    cmd = "";
    cmd = "get rtc5";
    sendCommand(Serial, cmd.toStdString().c_str());
    recvRetNumber(Serial, &time_buf[5]);
    
    cmd = "";
    cmd = "get rtc6";
    sendCommand(Serial, cmd.toStdString().c_str());
    recvRetNumber(Serial, &time_buf[6]);
    

    for(uint16_t i=0;i<len;i++)
    {
       time[i] = time_buf[i];
    }
 
}


uint32_t NexRtc::read_rtc_time(char *time_type,uint32_t *number)
{
    QString cmd = QString("get rtc");
    
    if(strstr(time_type,"year"))
    {
        cmd += '0';
    }
    else if(strstr(time_type,"mon"))
    {
        cmd += '1';
    }
    else if(strstr(time_type,"day"))
    {
        cmd += '2';
    }
    else if(strstr(time_type,"hour"))
    {
        cmd += '3';
    }
    else if(strstr(time_type,"min"))
    {
        cmd += '4';       
    }
    else if(strstr(time_type,"sec"))
    {
        cmd += '5';
    }
    else if(strstr(time_type,"week"))
    {
        cmd += '6';
    }
    else{
        return false;
    }
    
    sendCommand(Serial, cmd.toStdString().c_str());
    return recvRetNumber(Serial, number);
}
