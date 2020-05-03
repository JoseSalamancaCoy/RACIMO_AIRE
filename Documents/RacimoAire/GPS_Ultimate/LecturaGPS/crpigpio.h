#ifndef CRPIGPIO_H
#define CRPIGPIO_H

#include "rpigpio_global.h"
#include <QObject>
#include <pigpio.h>


class RPIGPIOSHARED_EXPORT Crpigpio : public QObject
{
    Q_OBJECT

public:
    explicit Crpigpio(QObject *parent = 0);
    virtual ~Crpigpio();

    //SPI
    int OpenSPI(unsigned chanel, unsigned baudios, unsigned Flags); //Habilitar pines para SPI
    int ReadSPI(QByteArray &arr, uint8_t count); //Leer bytes con el protocolo SPI
    int WriteSPI(QByteArray &arr);    //Escribir bytes con el protocolo SPI
    int WriteAndReadSPI(char *tx,char *rx,uint8_t count);  //Escribir y leer bytes con el protocolo SPI

    //Serial GPIO
    int OpenSerialgpio(unsigned gpio, unsigned baud_rate, unsigned packs_bits); //Habilitar gpio para lectura serial a velocidad de baud_rate en paquetes de packs_bits
    int ReadSerialgpioInverter(unsigned gpio, unsigned invert); //invert puede ser 0 o 1
    int ReadSerialgpio(unsigned gpio,char *buf,size_t bufSize);
    int CloseSerialgpio(unsigned gpio);


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

    public slots:


    private:

        int HanleSPI; //referencia de puerto SPI
        int HanleSerialgpio; //Referencia de Gpio con lectura serial
        int HanleSerialPrincipal; //Referencia de puerto serial
        int HanleSerialaux;
        void callbackISR(uint32_t timeout);
        static  void reciveISR(int gpio, int level, uint32_t tick, void *usr);
        void SendISR(int gpio,int level,quint32 tick);


};

#endif // CRPIGPIO_H
