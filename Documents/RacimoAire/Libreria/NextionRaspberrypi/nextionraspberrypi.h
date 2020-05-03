#ifndef NEXTIONRASPBERRYPI_H
#define NEXTIONRASPBERRYPI_H

#include "nextionraspberrypi_global.h"
#include <crpigpio.h>
#include <QTime>
#include <QThread>
#include <stdio.h>
#include <stdlib.h>
class NEXTIONRASPBERRYPISHARED_EXPORT NextionRaspberrypi
{
public:
    NextionRaspberrypi(Crpigpio *_GPIO,unsigned baud,unsigned _GPIORX);
    virtual ~NextionRaspberrypi();
    Crpigpio *GPIO;

    ulong timeout;


    void begin(unsigned baud);

    void setTimeout(long time);
    int available();
    uint8_t read();
    int read(char *buffer,unsigned size);

    size_t readBytes(char *buffer,size_t length);
    int readBytesnuf(char *buffer, size_t length);

    int timeRead();


    void write(char c);
    void write(uint8_t c);
    void write(uint16_t c);
    void write(uint32_t c);
    void write(uint64_t c);
    void write(int8_t c);
    void write(int16_t c);
    void write(int32_t c);
    void write(int64_t c);



    void print(QString String);
    void print(const char *String);
    void print(uint8_t val);
    void print(uint16_t val);
    void print(uint32_t val);
    void print(uint32_t *val);
    void print(int8_t val);
    void print(int16_t val);
    void print(int32_t val);
    void print(int32_t *val);



    void println(QString String);
    void println(const char *String);
    void println(uint8_t val);
    void println(uint16_t val);
    void println(uint32_t val);
    void println(uint32_t *val);

    void println(int8_t val);
    void println(int16_t val);
    void println(int32_t val);
    void println(int32_t *val);


    int GPIO_RX;
    ulong millis();

};

#endif // NEXTIONRASPBERRYPI_H
