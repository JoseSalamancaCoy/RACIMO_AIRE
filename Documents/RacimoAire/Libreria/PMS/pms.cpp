#include "pms.h"
#include <QTime>
#include <QDebug>


PMS::PMS(Crpigpio *ObjectCrPigpio, const uint8_t _GPIOSet, const uint8_t _GPIOReSet, const uint8_t _GPIORX, uint32_t timeMuestra)  // Constructor de la clase PMS
{
    GPIOSet = _GPIOSet;
    GPIOReSet = _GPIOReSet;
    GPIORX = _GPIORX;
    _timeMuestra = timeMuestra;

    RA_cGPIOPMS = ObjectCrPigpio;  // inicializador de puntero hacia el objeto
    RA_cGPIOPMS->SetPinMode(GPIORX , PI_INPUT);  //inicializacion de GPIO para set mode
    RA_cGPIOPMS->OpenSerialgpio(GPIORX,BAUD_RATE,8);  //Inicializacion de GPIO RX serial
    RA_cGPIOPMS->SetPinMode(GPIOSet , PI_OUTPUT);  //inicializacion de GPIO para set mode
    RA_cGPIOPMS->SetPinMode(GPIOReSet , PI_OUTPUT); //inicializacion de GPIO para Reset mode

     RA_cGPIOPMS->WriteGpio(GPIOSet,PI_ON); //Establecer en ON el GPIO para set mode en modo normal
    RA_cGPIOPMS->WriteGpio(GPIOReSet,PI_ON); //Establecer en ON el GPIO para reset mode para no reset
    timerONLectura = new QTimer;
    if(_status == STATUS_WAITING)  timerONLectura->setInterval(60000);  //Establecer intervalo de lectura
    else timerONLectura->setInterval(_timeMuestra);
    timerONLectura->start();  //iniciar temporizador

   QObject::connect(timerONLectura, SIGNAL(timeout()),this,SLOT(timelecturaPMS()));  //conectar interrupcion de tiempo con la lectura de datos
   inicio=true; //Se supone que el primer Byte de transmision es de inicio
}

PMS::~PMS()
{
    RA_cGPIOPMS->CloseSerialgpio(GPIORX); //Liberar GPIO RX
    //delete RA_cGPIOPMS; //Libera el objeto de GPIO
}

// Modo para ahorro de energia y prolongar la vida util del sensor
void PMS::sleep()
{
  RA_cGPIOPMS->WriteGpio(GPIOSet,PI_OFF);
  timerONLectura->stop();
  _status = STATUS_WAITING;

  qDebug() << "PMS en bajo consumo";
}

void PMS::SetTimeMuestreo(uint32_t timeMuestra)
{
    _timeMuestra = timeMuestra;
}

// modo activo de operacion, despues de estar dormido se deben esperar 30 segundos antes de tener un dato valido.
void PMS::wakeUp()
{
  _status = STATUS_WAITING;
  RA_cGPIOPMS->WriteGpio(GPIOSet,PI_ON);
  timerONLectura->setInterval(60000);  //Establecer intervalo de lectura
  timerONLectura->start();  //iniciar temporizador
}

//Reinicio del sensor, despues de este el sensor queda en modo activo y
void PMS::Reset()
{
    _status = STATUS_WAITING;
    RA_cGPIOPMS->WriteGpio(GPIOReSet,PI_OFF);
    QThread::msleep(100);
    RA_cGPIOPMS->WriteGpio(GPIOReSet,PI_ON);
    timerONLectura->setInterval(60000);  //Establecer intervalo de lectura
    timerONLectura->start();  //iniciar temporizador

}

// Modo activo, por defecto despues de encendido  ..... *Funcion inhabilitada
void PMS::activeMode()
{
  /*char command[] = { 0x42, 0x4D, 0xE1, 0x00, 0x01, 0x01, 0x71 };
  RA_cGPIOPMS->WriteSerial(&command[0], sizeof(command));
  _mode = MODE_ACTIVE;
  */
}

// Modo pasivo, en este el sensor solo lee cuando se lo pida con requestRead ..... *Funcion inhabilitada
void PMS::passiveMode()
{/*
  char command[] = { 0x42, 0x4D, 0xE1, 0x00, 0x00, 0x01, 0x70 };
  RA_cGPIOPMS->WriteSerial(&command[0], sizeof(command));
  _mode = MODE_PASSIVE;*/
}

// Obtener lectura, exclusivo para el modo pasivo ..... *Funcion inhabilitada
void PMS::requestRead()
{
    /*
  if (_mode == MODE_PASSIVE)
  {
    char command[] = { 0x42, 0x4D, 0xE2, 0x00, 0x00, 0x01, 0x71 };
    RA_cGPIOPMS->WriteSerial(&command[0], sizeof(command));
  }*/
}

// Lectura de datos
bool PMS::read(DATA *data)
{
  _data = data;
  QString datastr;
  int Idata;
  size_t TamanoBufer=64*_timeMuestra/1000;
  char buf[TamanoBufer];
  uint8_t dataa[TamanoBufer];
  for(unsigned i = 0;i < TamanoBufer;i++)buf[i]=' ';
  Idata = RA_cGPIOPMS->ReadSerialgpio(GPIORX,&buf[0],TamanoBufer);
 /* for(unsigned i=0;i < TamanoBufer;i++)
  {
    if(buf[i] == ' ') // busca el ultimo dato
    {
        if(i<64) return false;
        Idata=i; //asigna posicion del ultimo dato
        i=TamanoBufer+1; //saca del if
    }
  }*/
  //qDebug() << "Idata = " << Idata;
  for(int i = Idata-64;i < Idata;i++)
  {
      datastr +=buf[i];
      dataa[i]=buf[i];
      descompDATA(dataa[i]);
  }
  _status = STATUS_OK;
  return true;
}

//Extrae los datos de particulas de los bytes recibidos por la comunicacion serial
void PMS::descompDATA(uint8_t ch)
{
        switch (_index)
        {
        case 0:

          if (ch != 0x42) //Rastrea byte de inicio
          {
              inicio=false;
          }
          else
          {
              inicio=true;
              _calculatedChecksum = ch;
          }
          break;

        case 1:

          if (ch != 0x4D)
          {
            _index = 0;
            return;
          }
          else    _calculatedChecksum += ch;
          break;

        case 2:
          _calculatedChecksum += ch;
          _frameLen = ch << 8;
          break;

        case 3:

          _frameLen |= ch;
          if (_frameLen != 2 * 9 + 2 &&  _frameLen != 2 * 13 + 2)
          {
            _index = 0;
            return;
          }
          else _calculatedChecksum += ch;
          break;

        default:

          if (_index == _frameLen + 2)
          {
            _checksum = ch << 8;
          }
          else if (_index == _frameLen + 2 + 1)
          {
            _checksum |= ch;

            if (_calculatedChecksum == _checksum)
            {

              // Standard Particles, CF=1.
              _data->PM_SP_UG_1_0 = (_payload[0] << 8 | _payload[1]);
              _data->PM_SP_UG_2_5 = (_payload[2] << 8 | _payload[3]);
              _data->PM_SP_UG_10_0 = (_payload[4] << 8 | _payload[5]);

              // Atmospheric Environment.
              _data->PM_AE_UG_1_0 = (_payload[6] << 8 | _payload[7]);
              _data->PM_AE_UG_2_5 = (_payload[8] << 8 | _payload[9]);
              _data->PM_AE_UG_10_0 = (_payload[10] << 8 | _payload[11]);
              emit newData(_data->PM_AE_UG_1_0, _data->PM_AE_UG_2_5, _data->PM_AE_UG_10_0);  //emite senal con datos de PM1,PM2.5, PM10
            }

            _index = 0;
            return;
          }
          else
          {
            _calculatedChecksum += ch;
            uint8_t payloadIndex = _index - 4;

            // Payload is common to all sensors (first 2x6 bytes).
            if (payloadIndex < sizeof(_payload))
            {
              _payload[payloadIndex] = ch;
            }
          }
          break;
        }
         if(inicio) _index++;
         else _index=0;

}

//Interrupcion de tiempo para lectura del sensor
void PMS::timelecturaPMS()
{
    if(_status == STATUS_WAITING)
    {
        char buf[2000];
        RA_cGPIOPMS->ReadSerialgpio(GPIORX,&buf[0],2000); //Limpiar buffer
        emit InitMuestras();
    }
    _status = STATUS_OK;
    timerONLectura->setInterval(_timeMuestra);  //Establecer intervalo de lectura
    timerONLectura->start();  //iniciar temporizador
    read(&Data);
}
