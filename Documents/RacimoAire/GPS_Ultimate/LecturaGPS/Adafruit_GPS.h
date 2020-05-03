/***********************************
This is the Adafruit GPS library - the ultimate GPS library
for the ultimate GPS module!

Tested and works great with the Adafruit Ultimate GPS module
using MTK33x9 chipset
    ------> http://www.adafruit.com/products/746
Pick one up today at the Adafruit electronics shop 
and help support open source hardware & software! -ada

Adafruit invests time and resources providing this open source code, 
please support Adafruit and open-source hardware by purchasing 
products from Adafruit!

Written by Limor Fried/Ladyada  for Adafruit Industries.  
BSD license, check license.txt for more information
All text above must be included in any redistribution
****************************************/
// Fllybob added lines 34,35 and 40,41 to add 100mHz logging capability 


#ifndef _ADAFRUIT_GPS_H
#define _ADAFRUIT_GPS_H

#include <QMainWindow>
#include "crpigpio.h"
class Adafruit_GPS  : public QObject
{
    Q_OBJECT
 public:
    explicit Adafruit_GPS(Crpigpio *ObjectCrPigpio, const uint8_t GPSRx, const uint8_t GPSPPS);
    virtual ~Adafruit_GPS();

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

  char buf[500];
  static const uint8_t GPIORX=18;
  static const uint8_t GPIOPPS=17;

private slots:
  void OnISR(int gpio, int level, quint32 timeout);

signals:
  void newData( uint8_t hour, uint8_t minute,  uint8_t seconds, uint8_t year, uint8_t month,  uint8_t day,  uint16_t milliseconds,  float latitude, float longitude);

};

#endif
