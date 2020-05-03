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


    int OpenSPI(unsigned chanel, unsigned baudios, unsigned Flags); //Habilitar pines para SPI
    int CloseSPI();
    int ReadSPI(QByteArray &arr, uint8_t count); //Leer bytes con el protocolo SPI
    int WriteSPI(QByteArray &arr);    //Escribir bytes con el protocolo SPI
    int WriteAndReadSPI(char *tx,char *rx,uint8_t count);  //Escribir y leer bytes con el protocolo SPI


    int PWM(unsigned gpio,unsigned dutycycle);
    int SetPWMfrequency(unsigned gpio, unsigned frequency);
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

        //SPI
        int HanleSPI;
        void callbackISR(uint32_t timeout);
        static  void reciveISR(int gpio, int level, uint32_t tick, void *usr);
        void SendISR(int gpio,int level,quint32 tick);


};

#endif // CRPIGPIO_H
