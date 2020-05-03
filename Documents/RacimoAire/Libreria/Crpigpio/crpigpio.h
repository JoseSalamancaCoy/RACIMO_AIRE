#ifndef CRPIGPIO_H
#define CRPIGPIO_H

#include "crpigpio_global.h"
#include <QObject>
#include <pigpio.h>
#include <iostream>
#define ADRRSERIAL "/dev/ttyS0"

class CRPIGPIOSHARED_EXPORT Crpigpio : public QObject
{
    Q_OBJECT

public:
    explicit Crpigpio(bool Init=true,QObject *parent=nullptr);

    virtual ~Crpigpio();






    //SPI
    int OpenSPI(unsigned chanel, unsigned baudios, unsigned Flags); //Habilitar pines para SPI
    int CloseSPI(); //Liberar SPI
    int ReadSPI(QByteArray &arr, uint8_t count); //Leer bytes con el protocolo SPI
    int WriteSPI(QByteArray &arr);    //Escribir bytes con el protocolo SPI
    int WriteAndReadSPI(char *tx,char *rx,uint8_t count);  //Escribir y leer bytes con el protocolo SPI

    //Serial GPIO
    int OpenSerialgpio(unsigned gpio, unsigned baud_rate, unsigned packs_bits); //Habilitar gpio para lectura serial a velocidad de baud_rate en paquetes de packs_bits
    int ReadSerialgpioInverter(unsigned gpio, unsigned invert); //invert puede ser 0 o 1
    int ReadSerialgpio(unsigned gpio,char *buf,size_t bufSize);
    int CloseSerialgpio(unsigned gpio);

    //Serial
    int OpenSerial(unsigned baud, unsigned serFlag);
    int CloseSerial();
    int ReadByteSerial(bool show=false);
    int WriteByteSerial(unsigned Val);
    int WriteByteSerial(char Val);
    int WriteSerial(char *buf, unsigned count);
    int ReadSerial(char *buf, unsigned count);
    int AvailableSerial();

    //I2C
    int OpenI2C(unsigned Bus, unsigned Addr, unsigned Flags);
    int CloseI2C();
    int WriteAndReadDeviceI2C(unsigned i2cReg,char *bufi2c, unsigned counti2cWrite);
    int ReadDeviceI2C(char *bufi2c, unsigned counti2c);
    int ReadDeviceI2C(unsigned i2cReg, uint8_t *returnData);
    int ReadDeviceI2C(unsigned i2cReg, uint16_t *returnData);
    int ReadDeviceI2C(unsigned i2cReg, int16_t *returnData);
    int ReadDeviceI2C(unsigned i2cReg, char *bufi2cRead,unsigned count);

    int WriteDeviceI2C(char *bufi2c, unsigned counti2c);
    int WriteDeviceI2C(unsigned i2cReg, uint8_t Wval);
    int WriteDeviceI2C(unsigned i2cReg, uint16_t Wval);




    //PWM
    int PWM(unsigned gpio,unsigned dutycycle);
    int SetPWMfrequency(unsigned gpio, unsigned frequency);

    //Ajustes GPIO
    int SetPinMode(unsigned chanel,unsigned mode);  //Establecer tipo de pin
    int SetPullUpDown(unsigned chanel,unsigned mode);  //Puner PullUp o Pulldown en el pin deseado


    unsigned ReadGpio(int8_t pin); //Lectura de estado del GPIO
    bool WriteGpio(int8_t pin,unsigned val);   //GPIO

    QString GetErrorCode(int err); //obtener tipo de error

    void SetISRgpio(unsigned gpio, unsigned level, uint32_t tick); //Establecer pin como interrupcion

    signals:

        void OnCallBackISR(int gpio, int level,qint32 timeout);  //Senal de alerta de interrupcion
        void OnCallSerial(int numBytesRecive);
    public slots:


    private:

        int8_t InvertirBits(int8_t entero);
        uint8_t InvertirBits(uint8_t entero);
        int16_t InvertirBits(int16_t entero);
        uint16_t InvertirBits(uint16_t entero);
        //int32_t InvertirBits(int32_t entero);
        //uint32_t InvertirBits(uint32_t entero);
        int InvertirBits(int entero);
        char InvertirBits(char entero);

        int HanleSPI; //referencia de puerto SPI
        int HanleSerialgpio; //Referencia de Gpio con lectura serial
        int HandleSerial; //Referencia de puerto serial
        int HanleSerialaux;
        int Handlei2c;
        void callbackISR(uint32_t timeout);
        static  void reciveISR(int gpio, int level, uint32_t tick, void *usr);
        void SendISR(int gpio,int level,quint32 tick);


};

#endif // CRPIGPIO_H
