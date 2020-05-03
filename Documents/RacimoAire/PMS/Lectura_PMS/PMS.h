#ifndef PMS_H
#define PMS_H

#include "crpigpio.h"
#include <QThread>
#include <QTimer>
#include <QObject>


class PMS : public QObject
{    
    Q_OBJECT

    public:
    PMS(Crpigpio *ObjectCrPigpio, const uint8_t _GPIOSet, const uint8_t _GPIOReSet, const uint8_t _GPIORX , uint32_t timeMuestra);
    virtual ~PMS();
   static const uint16_t SINGLE_RESPONSE_TIME = 4000;
   static const uint16_t TOTAL_RESPONSE_TIME = 1000 * 10;
   static const uint16_t STEADY_RESPONSE_TIME = 1000 * 30;
   static const uint16_t BAUD_RATE = 9600;
   uint8_t GPIOSet ;
   uint8_t GPIOReSet ;
   uint8_t GPIORX;

   struct DATA {  //Structura de datos PMS
    // Particulas estandar, CF=1
        uint16_t PM_SP_UG_1_0;
        uint16_t PM_SP_UG_2_5;
        uint16_t PM_SP_UG_10_0;

    // Ambiente atmosferico
        uint16_t PM_AE_UG_1_0;
        uint16_t PM_AE_UG_2_5;
        uint16_t PM_AE_UG_10_0;
  };

  void Reset(); //Funcion para Reincio del sensor
  void sleep(); //Funcion para dormir el sensor
  void wakeUp(); //Funcion para despertar el sensor
  void activeMode(); //Modo activo ....*Deshabilitado
  void passiveMode();//Modo pasivo ....*Deshabilitado

  void requestRead(); //Pedir data en modo pasivo ....*Deshabilitado
  bool read(DATA  *data); //Funcion lectura de datos
  bool readUntil(DATA  *data, uint16_t timeout = SINGLE_RESPONSE_TIME);
  DATA Data;



private:
  enum STATUS { STATUS_WAITING, STATUS_OK };
  enum MODE { MODE_ACTIVE, MODE_PASSIVE }; // Modo de operacion del Sensor

  Crpigpio *RA_cGPIOPMS; //puntero hacia objeto de clase Crpigpio...  RA_cGPIOPMS (RACIMO AIRE clase del PMS)
  uint8_t _payload[12]; //bufer con datos relevantes del serial de lecuraPMS
  DATA *_data;   //Puntero hacia estructura de datos de tipo DATA
  STATUS _status = STATUS_WAITING;
  MODE _mode = MODE_ACTIVE;

  uint8_t _index = 0;
  uint16_t _frameLen;
  uint16_t _checksum;  //Checksum enviado por el sensor
  uint16_t _calculatedChecksum; //Checksum calculado de la trama de bits
  QTimer *timerONLectura; //Objeto de tipo QTimer para el temporizador de lectura
  bool inicio; // bandera de control para rastrear el byte de inicio en la comunicacion


  void loop(); //Funcion adquisicion de datos del Serial
  void descompDATA(uint8_t ch); //Funcion para extraer datos validos enviados por el sensor


private slots:
  void timelecturaPMS(); //Funcion interrupcion


  signals:
    void newData(uint16_t PM_1_0, uint16_t PM_2_5, uint16_t PM_10);
};


#endif
