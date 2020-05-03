#ifndef GPS_H
#define GPS_H

#include "gps_global.h"
#include <stdint.h>
#include <QObject>
#include "crpigpio.h"
#include <stdio.h>
#include <math.h>
class GPS  : public QObject
{
    Q_OBJECT
 public:
    explicit GPS(Crpigpio *ObjectCrPigpio, uint8_t GPIORX, uint8_t GPIOPPS);
    virtual ~GPS();

  static const uint16_t BAUD_RATE = 9600;



  void begin(uint32_t baud);

  //Adafruit_GPS(HardwareSerial *ser); // Constructor when using HardwareSerial

  void common_init(void);
  bool parseNMEA(char *response);
  uint8_t parseHex(char c);


  char read(void);
  bool parse(char *nmea);

  uint8_t hour, minute, seconds, year, month, day;
  uint16_t milliseconds;
  // Floating point latitude and longitude value in degrees.
  float latitude, longitude;
  // Fixed point latitude and longitude value with degrees stored in units of 1/100000 degrees,
  // and minutes stored in units of 1/100000 degrees.  See pull #13 for more details:
  //   https://github.com/adafruit/Adafruit-GPS-Library/pull/13
  int32_t latitude_fixed, longitude_fixed;
  float latitudeDegrees, longitudeDegrees;
  float geoidheight, altitude;
  float speed, angle, magvariation, HDOP;
  char lat, lon, mag;
  bool fix;
  uint8_t fixquality, satellites;


 private:

  Crpigpio *RA_cGPIOGPS;
  void LecturaGPS();

  char buf[1000];
  uint8_t _GPIORX=18;
  uint8_t _GPIOPPS=17;

private slots:
  void OnISR(int gpio, int level, quint32 timeout);

signals:
  void newData( float  latitude, float longitude, float latitudeDegrees, float longitudeDegrees, int32_t latitude_fixe , int32_t longitude_fixed);

};

#endif
