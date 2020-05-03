#ifndef OPCN2_H
#define OPCN2_H

#include "opcn2_global.h"
#include "opcn2_data.h"
#include "opcn2_ids.h"
#include "crpigpio.h"
#include <QTimer>
#include <QDebug>

class OPCN2SHARED_EXPORT OPCN2 : public QObject
{
    Q_OBJECT
    public:

        static const unsigned int StartupDelayMs = 2000;
        static const unsigned int SPICmdDelayMs = 10;
        static const unsigned int SPIValDelayUs = 10;

        static const char CmdCheckStatus= 0xcf;
        static const char CmdLaserFanOnOff = 0x03;
        static const char CmdLaserFanSetPower = 0x42;
        static const char CmdReadInfoString = 0x3f;
        static const char CmdReadHistogramData = 0x30;


        static const int InfoMessageSize = 61;        // Number of bytes in SPI response
        static const int InfoStringLength = 26;       // Number of actual values in string
        static const int HistogramMessageSize = 63;   // Number of bytes in SPI response

        OPCN2(Crpigpio *ObjectCrPigpio,uint8_t SpiChan, bool SPIAux);
        virtual ~OPCN2();

        void initialize(uint8_t SpiChan, bool SPIAux);
        bool checkStatus();
        void setFanAndLaserOn(bool *ok=nullptr);
        void setFanAndLaserOff(bool *ok=nullptr);
        OPCN2Data getHistogramData(bool *ok=nullptr);
        void ModeActive(uint16_t miliseconds);
        void ModePassive();
         OPCN2Data Data;

public slots:
    void getData();
    private:


        bool _SPIAux;
        Crpigpio *RA_cGPIOOPC;
        QTimer *timerONLectura;  //Solo valido para modo activo
        enum MODE {MODE_ACTIVE, MODE_PASSIVE, MODE_SLEEP };
        MODE _mode = MODE_PASSIVE;


    signals:
        void newData(float PM1, float PM2_5,  float PM10);


};


#endif // OPCN2_H
