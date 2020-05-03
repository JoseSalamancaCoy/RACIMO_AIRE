/***********************************
This is our GPS library

Adafruit invests time and resources providing this open source code,
please support Adafruit and open-source hardware by purchasing
products from Adafruit!

Written by Limor Fried/Ladyada for Adafruit Industries.
BSD license, check license.txt for more information
All text above must be included in any redistribution
****************************************/

#include <Adafruit_GPS.h>
#include <QDebug>


Adafruit_GPS::Adafruit_GPS(Crpigpio *ObjectCrPigpio, const uint8_t GPSRx,  const uint8_t GPSPPS)
{
    RA_cGPIOGPS= ObjectCrPigpio;

    common_init();
    qDebug() << RA_cGPIOGPS->OpenSerialgpio(GPIORX,BAUD_RATE,8);
    RA_cGPIOGPS->SetPinMode(GPIOPPS,PI_INPUT);
    RA_cGPIOGPS->SetPullUpDown(GPIOPPS,PI_PUD_UP);
    RA_cGPIOGPS->SetISRgpio(GPIOPPS,0,10000);
   connect(RA_cGPIOGPS,  &Crpigpio::OnCallBackISR, this,  &Adafruit_GPS::OnISR);
}

Adafruit_GPS::~Adafruit_GPS()
{
    RA_cGPIOGPS->CloseSerialgpio(GPIORX);
}

void Adafruit_GPS::common_init(void) {

  hour = minute = seconds = year = month = day =
    fixquality = satellites = 0; // uint8_t
  lat = lon = mag = 0; // char
  fix = false; // boolean
  milliseconds = 0; // uint16_t
  latitude = longitude = geoidheight = altitude =
    speed = angle = magvariation = HDOP = 0.0; // float
}

bool Adafruit_GPS::parse(char *nmea) {

  if (!strstr(nmea, "*")) return false;

  int32_t degree;
  long minutes;
  char degreebuff[10];
  // look for a few common sentences
  if (strstr(nmea, "$GPGGA"))
  {
        // found GGA
        char *p = nmea;
        // get time
        p = strchr(p, ',')+1;
        float timef = atof(p);
        uint32_t time = timef;
        hour = time / 10000;
        minute = (time % 10000) / 100;
        seconds = (time % 100);

        milliseconds = fmod(timef, 1.0) * 1000;
        // parse out latitude
        p = strchr(p, ',')+1;
        if (',' != *p)
        {
          strncpy(degreebuff, p, 2);
          p += 2;
          degreebuff[2] = '\0';
          degree = atol(degreebuff) * 10000000;
          strncpy(degreebuff, p, 2); // minutes
          p += 3; // skip decimal point
          strncpy(degreebuff + 2, p, 4);
          degreebuff[6] = '\0';
          minutes = 50 * atol(degreebuff) / 3;
          latitude_fixed = degree + minutes;
          latitude = degree / 100000 + minutes * 0.000006F;
          latitudeDegrees = (latitude-100*int(latitude/100))/60.0;
          latitudeDegrees += int(latitude/100);
        }

        p = strchr(p, ',')+1;
        if (',' != *p)
        {
          if (p[0] == 'S') latitudeDegrees *= -1.0;
          if (p[0] == 'N') lat = 'N';
          else if (p[0] == 'S') lat = 'S';
          else if (p[0] == ',') lat = 0;
          else return false;
        }

        // parse out longitude
        p = strchr(p, ',')+1;
        if (',' != *p)
        {
          strncpy(degreebuff, p, 3);
          p += 3;
          degreebuff[3] = '\0';
          degree = atol(degreebuff) * 10000000;
          strncpy(degreebuff, p, 2); // minutes
          p += 3; // skip decimal point
          strncpy(degreebuff + 2, p, 4);
          degreebuff[6] = '\0';
          minutes = 50 * atol(degreebuff) / 3;
          longitude_fixed = degree + minutes;
          longitude = degree / 100000 + minutes * 0.000006F;
          longitudeDegrees = (longitude-100*int(longitude/100))/60.0;
          longitudeDegrees += int(longitude/100);
        }

        p = strchr(p, ',')+1;
        if (',' != *p)
        {
          if (p[0] == 'W') longitudeDegrees *= -1.0;
          if (p[0] == 'W') lon = 'W';
          else if (p[0] == 'E') lon = 'E';
          else if (p[0] == ',') lon = 0;
          else return false;
        }

        p = strchr(p, ',')+1;
        if (',' != *p)
        {
          fixquality = atoi(p);
        }

        p = strchr(p, ',')+1;
        if (',' != *p)
        {
          satellites = atoi(p);
        }

        p = strchr(p, ',')+1;
        if (',' != *p)
        {
          HDOP = atof(p);
        }

        p = strchr(p, ',')+1;
        if (',' != *p)
        {
          altitude = atof(p);
        }

        p = strchr(p, ',')+1;
        p = strchr(p, ',')+1;
        if (',' != *p)
        {
          geoidheight = atof(p);
        }
        return true;
}
  if (strstr(nmea, "$GPRMC")) {
   // found RMC
    char *p = nmea;

    // get time
    p = strchr(p, ',')+1;
    float timef = atof(p);
    uint32_t time = timef;
    hour = time / 10000;
    minute = (time % 10000) / 100;
    seconds = (time % 100);

    milliseconds = fmod(timef, 1.0) * 1000;

    p = strchr(p, ',')+1;
    // Serial.println(p);
    if (p[0] == 'A') 
      fix = true;
    else if (p[0] == 'V')
      fix = false;
    else
      return false;

    // parse out latitude
    p = strchr(p, ',')+1;
    if (',' != *p)
    {
      strncpy(degreebuff, p, 2);
      p += 2;
      degreebuff[2] = '\0';
      long degree = atol(degreebuff) * 10000000;
      strncpy(degreebuff, p, 2); // minutes
      p += 3; // skip decimal point
      strncpy(degreebuff + 2, p, 4);
      degreebuff[6] = '\0';
      long minutes = 50 * atol(degreebuff) / 3;
      latitude_fixed = degree + minutes;
      latitude = degree / 100000 + minutes * 0.000006F;
      latitudeDegrees = (latitude-100*int(latitude/100))/60.0;
      latitudeDegrees += int(latitude/100);
    }
    
    p = strchr(p, ',')+1;
    if (',' != *p)
    {
      if (p[0] == 'S') latitudeDegrees *= -1.0;
      if (p[0] == 'N') lat = 'N';
      else if (p[0] == 'S') lat = 'S';
      else if (p[0] == ',') lat = 0;
      else return false;
    }
    
    // parse out longitude
    p = strchr(p, ',')+1;
    if (',' != *p)
    {
      strncpy(degreebuff, p, 3);
      p += 3;
      degreebuff[3] = '\0';
      degree = atol(degreebuff) * 10000000;
      strncpy(degreebuff, p, 2); // minutes
      p += 3; // skip decimal point
      strncpy(degreebuff + 2, p, 4);
      degreebuff[6] = '\0';
      minutes = 50 * atol(degreebuff) / 3;
      longitude_fixed = degree + minutes;
      longitude = degree / 100000 + minutes * 0.000006F;
      longitudeDegrees = (longitude-100*int(longitude/100))/60.0;
      longitudeDegrees += int(longitude/100);
    }
    
    p = strchr(p, ',')+1;
    if (',' != *p)
    {
      if (p[0] == 'W') longitudeDegrees *= -1.0;
      if (p[0] == 'W') lon = 'W';
      else if (p[0] == 'E') lon = 'E';
      else if (p[0] == ',') lon = 0;
      else return false;
    }
    // speed
    p = strchr(p, ',')+1;
    if (',' != *p)
    {
      speed = atof(p);
    }
    
    // angle
    p = strchr(p, ',')+1;
    if (',' != *p)
    {
      angle = atof(p);
    }
    
    p = strchr(p, ',')+1;
    if (',' != *p)
    {
      uint32_t fulldate = atof(p);
      day = fulldate / 10000;
      month = (fulldate % 10000) / 100;
      year = (fulldate % 100);
    }
    // we dont parse the remaining, yet!
    return true;
  }

  return false;
}

uint8_t Adafruit_GPS::parseHex(char c) {
    if (c < '0')
      return 0;
    if (c <= '9')
      return c - '0';
    if (c < 'A')
       return 0;
    if (c <= 'F')
       return (c - 'A')+10;
    // if (c > 'F')
    return 0;
}

void Adafruit_GPS::LecturaGPS()
{
    QString string;
    for(int i = 0;i < 500;i++) buf[i]=' ';
    RA_cGPIOGPS->ReadSerialgpio(GPIORX,&buf[0],500);
    for(int i = 0;i < 500;i++) string += buf[i];
    if(buf[0] != ' ')
    {
        if(parse(&buf[0]))
        {
            qDebug() << "entro";
         emit  newData( hour, minute,  seconds, year, month,  day,  milliseconds,  latitude,  longitude);

        }
    }
}

void Adafruit_GPS::OnISR(int gpio, int level, quint32 timeout)
{
    switch (gpio)
    {
        case GPIOPPS:
            if(level==1)
            {
                qDebug() << "PPS";
                LecturaGPS();
            }
            else
            {
                if(level==2)
                {
                    qDebug() << timeout;

                }
            }
        break;

       default:
       break;
    }
}
