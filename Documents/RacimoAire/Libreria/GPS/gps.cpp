#include "gps.h"
#include <QDebug>


GPS::GPS(Crpigpio *ObjectCrPigpio, uint8_t GPIORX, uint8_t GPIOPPS)
{
    RA_cGPIOGPS= ObjectCrPigpio;
    _GPIORX = GPIORX;
    _GPIOPPS = GPIOPPS;
    common_init();
    qDebug() << RA_cGPIOGPS->OpenSerialgpio(_GPIORX,BAUD_RATE,8);
    RA_cGPIOGPS->SetPinMode(_GPIOPPS,PI_INPUT);
    RA_cGPIOGPS->SetPullUpDown(_GPIOPPS,PI_PUD_UP);
    RA_cGPIOGPS->SetISRgpio(_GPIOPPS,0,10000);
   connect(RA_cGPIOGPS,  &Crpigpio::OnCallBackISR, this,  &GPS::OnISR);
}

GPS::~GPS()
{
    RA_cGPIOGPS->CloseSerialgpio(_GPIORX);
}

void GPS::common_init(void) {

  hour = minute = seconds = year = month = day =
    fixquality = satellites = 0; // uint8_t
  lat = lon = mag = 0; // char
  fix = false; // boolean
  milliseconds = 0; // uint16_t
  latitude = longitude = geoidheight = altitude =
    speed = angle = magvariation = HDOP = 0.0; // float
}

bool GPS::parse(char *nmea) {

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
      qDebug() <<"GPS       " <<  fulldate;
      day = fulldate / 10000;
      month = (fulldate % 10000) / 100;
      year = (fulldate % 100);
    }
    // we dont parse the remaining, yet!
    return true;
  }

  return false;
}

uint8_t GPS::parseHex(char c) {
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

void GPS::LecturaGPS()
{
    QString string;
    for(int i = 0;i < 1000;i++) buf[i]=' ';
    RA_cGPIOGPS->ReadSerialgpio(_GPIORX,&buf[0],1000);
    for(int i = 0;i < 1000;i++) string += buf[i];
    if(buf[0] != ' ')
    {
        if(parse(&buf[0]))
        {
         emit  newData( latitude,  longitude, latitudeDegrees, longitudeDegrees, latitude_fixed, longitude_fixed);

        }
    }
}

void GPS::OnISR(int gpio, int level, quint32 timeout)
{
    if(gpio = _GPIOPPS)
    {
        if(level==1)
        {
            //qDebug() << "PPS";
            LecturaGPS();
        }
        else
        {
            if(level==2)
            {
                //qDebug() << timeout;

            }
        }
    }
}
