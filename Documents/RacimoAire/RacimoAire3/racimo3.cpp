#include "racimo3.h"

Racimo3::Racimo3(QObject *parent)
    : QObject(parent)
{
    blinkLed = false;
    AlertRAM = false;
    AlertTemperatura = false;
    NewData = false;
    InitAPP =true;
    AlertWifi =false;
    _timeoutlectura =false;
    AlertPMS=false;
    AlertOPC=false;
    ShutdownManual=false;
    RebootManual=false;
    _CerrarApp=false;

    Delta_muestra_muestra = 10000;
    contReboot_rstApp = 0;
    MetaData._StatusWIFI =false;
    contReboot_rstApp = 0;
    BlinkLeds = new QTimer;
    BlinkLeds->setInterval(250);
    BlinkLeds->start();
    connect(BlinkLeds,&QTimer::timeout,this, &Racimo3::Blink);

    RA_cGPIO1 = new Crpigpio(true,this);
    RA_cGPIO2 = new Crpigpio(false,this);
    RA_cGPIO3 = new Crpigpio(false,this);
    _DataJson2 = new DataJson2("/home/pi/RACIMOAIRE/Configuracion/JsonBase.json","/home/pi/RACIMOAIRE/");


    RA_cGPIO1->SetPinMode(GPIOWiFi,PI_OUTPUT);
    RA_cGPIO1->SetPinMode(GPIOTransmision,PI_OUTPUT);
    RA_cGPIO1->SetPinMode(GPIOButton,PI_INPUT); //Configura como entrada
    RA_cGPIO1->SetPullUpDown(GPIOButton,PI_PUD_DOWN); //Abilita resistencias de positivo
    RA_cGPIO1->SetISRgpio(GPIOButton,2,100000); //Configura la interrupcion (pin,flanco,timeout uS) flanco=0 = rising
    connect(RA_cGPIO1,&Crpigpio::OnCallBackISR, this, &Racimo3::OnISR);

    RA_cPMS = new PMS(RA_cGPIO1,GPIOPMSSet, GPIOPMSReSet, GPIOPMSRX,Delta_muestra_muestra);
    RA_cGPS = new GPS(RA_cGPIO1, GPIOGPSRX, GPIOGPSPPS);
    RA_cOPC = new OPCN2(RA_cGPIO1,0,0);
    RA_cBME280 = new Adafruit_BME280(RA_cGPIO1,0x77);
    RA_cOPC->setFanAndLaserOff();
    RA_cPMS->sleep();


    RA_cGADC = new ADS1115(RA_cGPIO2);
    RA_cGADC->setGain(GAIN_TWOTHIRDS);
    RA_cGADC->setRate(RATE_128);          // 128SPS (default)
    RA_cGADC->setOSMode(OSMODE_SINGLE);   // Set to start a single-conversion
    RA_cCorriente = new Adafruit_INA219(RA_cGPIO3);


    uint32_t MuestraPromedio = (3*60000) + 20000 ;

    RA_cDataParticulado1 = new DataParticulado(RA_cOPC , RA_cPMS ,Delta_muestra_muestra, MuestraPromedio,this);
    RA_cDataParticulado1->Pasivo();



    DateTimer = new CDateTimer("/home/pi/RACIMOAIRE/Configuracion/TimeConfig.txt",this);
    connect(DateTimer,&CDateTimer::timeout, this, &Racimo3::Muestra);
    TimeoutLectura = new QTimer();
    TimeoutLectura->setInterval(250000);
    connect(TimeoutLectura,&QTimer::timeout, this, &Racimo3::setTimeoutlectura);



    TimerAlertWifi = new QTimer;
    TimerAlertWifi->setInterval(60000);
    connect(TimerAlertWifi, &QTimer::timeout, this, &Racimo3::timeoutAlertWifi);
    Timer = new QTimer();
    Timer->setInterval(500);
    Timer->start();

    connect(RA_cDataParticulado1,&DataParticulado::DataOk,this, &Racimo3::DataOk1);
    connect(RA_cDataParticulado1,&DataParticulado::DataOkPMS,this, &Racimo3::DataParticuladoOkPMS1);
    connect(RA_cDataParticulado1,&DataParticulado::DataOkOPC,this, &Racimo3::DataParticuladoOkOPC1);



    connect(Timer, &QTimer::timeout, this, &Racimo3::Show);


    TimeDataLogs =new QTimer;
    TimeDataLogs->setInterval(5000);
    TimeDataLogs->start();

    LogsThread = new LogsSystem(this);
    connect(TimeDataLogs,&QTimer::timeout, this, &Racimo3::DataLogs);
    connect(LogsThread,&LogsSystem::SignalTemperatura,this, &Racimo3::SlotTemperatura);
    connect(LogsThread,&LogsSystem::SignalRAM,this, &Racimo3::SlotRAM);
    connect(LogsThread,&LogsSystem::SignalProcesos,this, &Racimo3::SlotProcesos);
    connect(LogsThread,&LogsSystem::SignalSOCKET,this, &Racimo3::SlotSOCKET);
    connect(LogsThread,&LogsSystem::SignalStatusWIFI,this, &Racimo3::SlotStatusWIFI);
    connect(LogsThread,&LogsSystem::SignalEspacioDisco,this, &Racimo3::SlotEspacioDisco);
    connect(RA_cGPS, &GPS::newData,this, &Racimo3::newDataGPS);

    LogsThread->start(QThread::HighPriority);

    RstData();

    Serial =new NextionRaspberrypi(RA_cGPIO1,9600,15);
    nexInit(Serial);
    txt_temp = new NexText(Serial,0,9,"t7");
    txt_Presion = new NexText(Serial,0,10,"t8");
    txt_hum = new NexText(Serial,0,13,"t11");
    txt_longitud = new NexText(Serial,0,15,"t13");
    txt_latitud = new NexText(Serial,0,18,"t16");
    txt_Altitud = new NexText(Serial,0,19,"t17");
    txt_Fix = new NexText(Serial,0,17,"t15");
    txt_wifi = new NexText(Serial,0,20,"t18");
    txt_PM25_P = new NexText(Serial,0,25,"t23");
    txt_PM25_O = new NexText(Serial,0,29,"t27");
    txt_PM10_P = new NexText(Serial,0,26,"t24");
    txt_PM10_0 = new NexText(Serial,0,30,"t28");

    txt_temp->setText("null");QThread::msleep(10);
    txt_Presion->setText("null");QThread::msleep(10);
    txt_hum->setText("null");QThread::msleep(10);
    txt_longitud->setText("null");QThread::msleep(10);
    txt_latitud->setText("null");QThread::msleep(10);
    txt_Altitud->setText("null");QThread::msleep(10);
    txt_Fix->setText("0");QThread::msleep(10);
    txt_wifi->setText("No");QThread::msleep(10);
    txt_PM25_P->setText("null");QThread::msleep(10);
    txt_PM25_O->setText("null");QThread::msleep(10);
    txt_PM10_P->setText("null");QThread::msleep(10);
    txt_PM10_0->setText("null");QThread::msleep(10);

    QTimer::singleShot(4*1000,this,SLOT(check_InitAPP()));

}

Racimo3::~Racimo3()
{
    RA_cOPC->setFanAndLaserOff();
    RA_cPMS->sleep();
    delete RA_cBME280;
    delete RA_cGPS;
    delete _DataJson2;
    delete RA_cDataParticulado1;
    delete RA_cOPC;
    delete RA_cPMS;
    delete RA_cGADC;
    delete RA_cCorriente;

    delete txt_hum;
    delete txt_Presion;
    delete txt_temp;
    delete txt_longitud;
    delete txt_latitud;
    delete txt_Altitud;
    delete txt_Fix;
    delete txt_wifi;
    delete txt_PM25_P;
    delete txt_PM25_O;
    delete txt_PM10_P;
    delete txt_PM10_0;
    delete Serial;

    delete RA_cGPIO1;

    delete this;
}


bool Racimo3:: POSTHttp(char *charjson)
{

    CURL *hnd = curl_easy_init();
    if(hnd)
    {
        curl_easy_setopt(hnd, CURLOPT_CUSTOMREQUEST, "POST");
        curl_easy_setopt(hnd, CURLOPT_URL, "http://racimo.mpsig.com:3000/racimohub/v013dev/datasets");
        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, "Postman-Token: d75df676-a5e1-448a-8b70-177609f83454");
        headers = curl_slist_append(headers, "Cache-Control: no-cache");
        headers = curl_slist_append(headers, "Content-Type: application/json");
        curl_easy_setopt(hnd, CURLOPT_HTTPHEADER, headers);
        curl_easy_setopt(hnd, CURLOPT_POSTFIELDS, charjson ); //Envio
        CURLcode ret = curl_easy_perform(hnd);
        if(ret != CURLE_OK) return false;
        curl_easy_cleanup(hnd);
        curl_global_cleanup();
        return true;
    }
    return false;
}

void Racimo3::SetHora()
{
    system("GetHttpCurl >/home/pi/RACIMOAIRE/DataIntercambio/FechaHora.json");
    QFile ArchivoFechaHora("/home/pi/RACIMOAIRE/DataIntercambio/FechaHora.json");
    if(!ArchivoFechaHora.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return;
    }
    QJsonObject obj;
    QJsonDocument doc = QJsonDocument::fromJson(QString(ArchivoFechaHora.readAll()).toUtf8());
    // check validity of the document
    if(!doc.isNull())
    {
        if(doc.isObject())
        {
            obj = doc.object();
        }
        else
        {
            qDebug() << "Document is not an object" << endl;
        }
    }
    else
    {
        qDebug() << "Invalid JSON...\n" << QString(ArchivoFechaHora.readAll()) << endl;
    }
    QDateTime DateTime = QDateTime::fromString(obj.value("fechahora").toString(),Qt::DateFormat::ISODate);
    QString StringFechaHora =DateTime.toLocalTime().toString(Qt::DateFormat::ISODate).replace('T',' ');
    char SetHora[38];
    sprintf(SetHora,"sudo date --set \"%s\"",StringFechaHora.toStdString().c_str());
    qDebug() <<"SetHora en "<<StringFechaHora;
    system(SetHora);
}


void Racimo3::check_InitAPP()
{

    if(RA_cBME280->InitOk() < 0)
    {
        _DataJson2->SetDato("alert","Falla al iniciar BME280");
        StateBME280 =false;
        NewData =true;
    }
    else StateBME280 =true;


    if(RA_cCorriente->getInitOK() < 0)
    {
        _DataJson2->SetDato("alert","Falla al iniciar IN219");
        NewData =true;
        StateINA219 =false;
    }
    else StateINA219 =true;

    if(RA_cGADC->getInitOk() < 0)
    {
        _DataJson2->SetDato("alert","Falla al iniciar ADS1115");
        NewData =true;
        StateADS1115 =false;
    }
    else StateADS1115 =true;


    QFile file("/home/pi/RACIMOAIRE/RSTRaspi.txt");
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text))
    {
        _DataJson2->SetDato("alert","Inicio de App por cierre inesperado");
        qDebug() << "Inicio de App por cierre inesperado";
        NewData = true;  //habilita la transmision
    }
    else
    {
        _DataJson2->SetDato("alert","Inicio de App por reboot");
        file.close();
        system("rm /home/pi/RACIMOAIRE/RSTRaspi.txt");
        qDebug() << "Inicio de App por rst inesperado";
        NewData = true;  //habilita la transmision
    }
    _DataJson2->WriteJson(); // genera un .json
    _DataJson2->ClearArray();  //elimino cualquier dato cargado en el buffer
    DateTimer->StartTimer();
}

bool Racimo3::Transmision()
{\
    QStringList _DataJsonString;
    if(_DataJson2->readJson(&_DataJsonString)) qDebug() << "Se leyeron los archivos Json";
    else qDebug() << "Problemas al leer los archivo Json";

    for(int i=0;i<_DataJsonString.length() ; i++)
    {
        std::string STR = QString(_DataJsonString.operator [](i)).toStdString();
        char *String = new char[STR.length() + 1];
        strcpy(String, STR.c_str());;
        qDebug() << String;
        if(!POSTHttp(String)) return false;
        delete [] String;
    }
    return true;
}

void Racimo3::SabeDataCsv()
{
   /* QFile file("/home/pi/PMS.csv");
    if(!file.open(QIODevice::Append|QIODevice::Text))
    {
        qDebug() << "Error al abrir el archivo";
        return;
    }
    QString str;
    str="";
    str += QString::number(PMS_PM1) + ";";
    str += QString::number(PMS_PM2_5) + ";";
    str += QString::number(PMS_PM10) + ";";

    str+= QDateTime::currentDateTimeUtc().toString(Qt::ISODate).replace("Z","."+QString::number(QTime::currentTime().msec())+"Z");

    str+="\n";
    QTextStream Strem(&file);
    Strem << str;
    file.close();



    QFile file2("/home/pi/OPC.csv");
    if(!file2.open(QIODevice::Append|QIODevice::Text))
    {
        qDebug() << "Error al abrir el archivo";
        return;
    }
    QString str2;
    str2="";
    str2 += QString::number(OPC_PM1) + ";";
    str2 += QString::number(OPC_PM2_5) + ";";
    str2 += QString::number(OPC_PM10) + ";";

    str2+= QDateTime::currentDateTimeUtc().toString(Qt::ISODate).replace("Z","."+QString::number(QTime::currentTime().msec())+"Z");

    str2+="\n";
    QTextStream Strem2(&file2);
    Strem2 << str2;
    file2.close();*/
}

void Racimo3::RstData()
{
    PMS_PM1 = 0.0; PMS_PM2_5 = 0.0;  PMS_PM10 =0.0;
    OPC_PM1 = 0.0; OPC_PM2_5 = 0.0;  OPC_PM10 =0.0;
    Check_PMS = false;  Check_OPC =false;

}














void Racimo3::checkRst_App_Raspi()
{
    if(contReboot_rstApp == 2)
    {
        _CerrarApp = true;
        _DataJson2->SetDato("alert", "Alerta Cerrando app manualmente");
        _DataJson2->WriteJson();
        _DataJson2->ClearArray();
	NewData = true;
        BlinkLeds->stop();
        QTimer::singleShot(20*1000,this,SLOT(CerrarApp()));
        Blink();
    }
    else
    {
        if(contReboot_rstApp == 3)
        {
	    NewData = true;
            BlinkLeds->stop();
            RebootManual=true;
            _DataJson2->SetDato("alert", "Alerta Reboot manual inminente");
            _DataJson2->WriteJson();
            _DataJson2->ClearArray();
            QTimer::singleShot(20*1000,this,SLOT(ReinicioRaspi()));
            Blink();
        }
    }
    contReboot_rstApp = 0;


}


void Racimo3::OnISR(int gpio,int level,quint32 timeout)
{
    switch (gpio)
    {
    case GPIOButton:
    if(level) {
        TimePushButton.start();
        if(contReboot_rstApp == 0) QTimer::singleShot(4*1000,this,SLOT(checkRst_App_Raspi()));
    }
    else {
        int mseconds = TimePushButton.elapsed();
        if(mseconds>=2000 && mseconds<=5000)
        {
            _DataJson2->SetDato("alert", "Alerta apagado manual inminente");
            _DataJson2->WriteJson();
            _DataJson2->ClearArray();
            ShutdownManual =true;
            BlinkLeds->stop();
            NewData = true;
            QTimer::singleShot(20*1000,this,SLOT(ShutdownRaspi()));
            Blink();
        }
        if(mseconds<=1500) contReboot_rstApp++;
	qDebug() << contReboot_rstApp;
    }
        break;

    default:
        break;
    }

    return;
    qDebug()<< timeout;
}


void Racimo3::Blink()
{
   if(RebootManual)
    {
	for(int i=0; i<18; i++){
        RA_cGPIO1->WriteGpio(GPIOWiFi,PI_OFF);
        RA_cGPIO1->WriteGpio(GPIOTransmision,PI_ON);
        QThread::msleep(200);
        RA_cGPIO1->WriteGpio(GPIOWiFi,PI_ON);
        RA_cGPIO1->WriteGpio(GPIOTransmision,PI_OFF);
        QThread::msleep(200);
        RA_cGPIO1->WriteGpio(GPIOWiFi,PI_OFF);
        RA_cGPIO1->WriteGpio(GPIOTransmision,PI_OFF);
        QThread::msleep(500);
	}

    }
    if(ShutdownManual)
    {
	for(int i=0; i<50;i++){
        RA_cGPIO1->WriteGpio(GPIOWiFi,PI_ON);
        RA_cGPIO1->WriteGpio(GPIOTransmision,PI_ON);
        QThread::msleep(200);
        RA_cGPIO1->WriteGpio(GPIOWiFi,PI_OFF);
        RA_cGPIO1->WriteGpio(GPIOTransmision,PI_OFF);
        QThread::msleep(200);
	}

    }
    if(_CerrarApp)
    {
	for(int i=0; i <8 ; i++){
        RA_cGPIO1->WriteGpio(GPIOWiFi,PI_OFF);
        RA_cGPIO1->WriteGpio(GPIOTransmision,PI_ON);
        QThread::msleep(200);
        RA_cGPIO1->WriteGpio(GPIOTransmision,PI_OFF);
        QThread::msleep(200);
        RA_cGPIO1->WriteGpio(GPIOTransmision,PI_ON);
        QThread::msleep(200);
        RA_cGPIO1->WriteGpio(GPIOTransmision,PI_OFF);
        QThread::msleep(200);

        RA_cGPIO1->WriteGpio(GPIOWiFi,PI_ON);
        QThread::msleep(200);
        RA_cGPIO1->WriteGpio(GPIOWiFi,PI_OFF);
        QThread::msleep(200);
        RA_cGPIO1->WriteGpio(GPIOTransmision,PI_ON);
        QThread::msleep(200);
        RA_cGPIO1->WriteGpio(GPIOTransmision,PI_OFF);
        QThread::msleep(500);
	}
    }

    blinkLed = !blinkLed;
    if(AlertWifi)  RA_cGPIO1->WriteGpio(GPIOWiFi,PI_OFF);
    else RA_cGPIO1->WriteGpio(GPIOWiFi,blinkLed);
    if(NewData) RA_cGPIO1->WriteGpio(GPIOTransmision,PI_ON);
    else RA_cGPIO1->WriteGpio(GPIOTransmision,PI_OFF);
}



void Racimo3::timeoutAlertWifi()
{
    AlertWifi = true;
    TimerAlertWifi->stop();
    _DataJson2->SetDato("alert", "Alerta sin acceso a internet");
}


void Racimo3::DataOk1()
{

}

void Racimo3::DataParticuladoOkPMS1(float PM1Promedio, float PM2_5Promedio, float PM10Promedio)
{
    PMS_PM1 = PM1Promedio;        PMS_PM2_5 = PM2_5Promedio;        PMS_PM10 = PM10Promedio;
    Check_PMS=true;
    qDebug() << QString("Data PMS1         PM1 = %1        PM2_5 = %2          PM10 = %3 ").arg(PM1Promedio).arg(PM2_5Promedio).arg(PM10Promedio);
    _DataJson2->SetDato(_DataJson2->PM10_A,PMS_PM10);
    _DataJson2->SetDato(_DataJson2->PM2_5_A,PMS_PM2_5);
    _DataJson2->SetDato(_DataJson2->PM1_A,PMS_PM1);
    txt_PM25_P->setText(QString::number(static_cast<int>(PM2_5Promedio)).toStdString().c_str());
    txt_PM10_P->setText(QString::number(static_cast<int>(PM10Promedio)).toStdString().c_str());

}

void Racimo3::DataParticuladoOkOPC1(float PM1Promedio, float PM2_5Promedio, float PM10Promedio)
{
    OPC_PM1 = PM1Promedio;        OPC_PM2_5 = PM2_5Promedio;        OPC_PM10 = PM10Promedio;
    qDebug() << QString("Data OPC1         PM1 = %1        PM2_5 = %2          PM10 = %3 ").arg(PM1Promedio).arg(PM2_5Promedio).arg(PM10Promedio);
    Check_OPC= true;
    _DataJson2->SetDato(_DataJson2->PM10,OPC_PM10);
    _DataJson2->SetDato(_DataJson2->PM2_5, OPC_PM2_5);
    _DataJson2->SetDato(_DataJson2->PM1,OPC_PM1);
    txt_PM25_O->setText(QString::number(PM2_5Promedio).toStdString().c_str());
    txt_PM10_0->setText(QString::number(PM10Promedio).toStdString().c_str());
}


void Racimo3::setTimeoutlectura()
{
    _timeoutlectura = true;
}
void Racimo3::Muestra()
{

    RA_cDataParticulado1->Muestra();
    TimeoutLectura->start();
    QThread::msleep(300);
    uint16_t CH1 = RA_cGADC->Measure_SingleEnded(0);
    uint16_t CH2 = RA_cGADC->Measure_SingleEnded(1);
    uint16_t CH3 = RA_cGADC->Measure_SingleEnded(2);
    uint16_t CH4 = RA_cGADC->Measure_SingleEnded(3);
    int16_t Corriente =RA_cCorriente->getCurrent_mA();
    qDebug() << "Corriente"  << Corriente;
    if(RA_cCorriente->getInitOK() >= 0)
    {
        _DataJson2->SetDato("c",Corriente*-1);
        if(!StateINA219)
        {
            _DataJson2->SetDato("alert", "Alerta INA219 Reconectado");
            StateINA219 =true;
        }
    }
    else
    {
        if(StateINA219)
        {
            _DataJson2->SetDato("alert", "Alerta INA219 Desconectado");
            StateINA219 =false;
        }

        if(RA_cCorriente->getInitOK() >= 0) _DataJson2->SetDato("alert", "INA219 Reconectado");
    }

    if(RA_cGADC->getInitOk()>= 0)
    {
        _DataJson2->SetDato("v_O",CH1*(6.144/32767)*1.6666);
        _DataJson2->SetDato("v_P",CH2*(6.144/32767)*1.6666);
        _DataJson2->SetDato("v_B",CH3*(6.144/32767));
        _DataJson2->SetDato("v_G",CH4*(6.144/32767));
        if(!StateADS1115)
        {
            _DataJson2->SetDato("alert", "Alerta ADS115 Reconectado");
            StateADS1115 =true;
        }


    }
    else
    {
        if(StateADS1115)
        {
            _DataJson2->SetDato("alert", "Alerta ADS1115 Desconectado");
            StateADS1115 =false;
        }
    }
}
//Despliegue de datos
void Racimo3::Show()
{
    if( _timeoutlectura || (Check_PMS && Check_OPC))
    {
        if(_timeoutlectura)
        {
            if(!Check_PMS){
                if(!AlertPMS) _DataJson2->SetDato("alert", "Fallo PMS no responde");
                AlertPMS = true;
            }
            else {
                if(AlertPMS) _DataJson2->SetDato("alert", "Alerta PMS activo");
                AlertPMS = false;
            }

            if(!Check_OPC){
                if(!AlertOPC) _DataJson2->SetDato("alert", "Fallo OPC no responde");
                AlertOPC = true;
            }
            else {
                if(AlertOPC) _DataJson2->SetDato("alert", "Alerta OPC activo");
                AlertOPC = false;
            }
        }
        TimeoutLectura->stop();
        _timeoutlectura= false;
        RA_cBME280->takeForcedMeasurement();
        float Humedad = RA_cBME280->readHumidity();
        RA_cBME280->takeForcedMeasurement();
        float Temperatura =  RA_cBME280->readTemperature();
        RA_cBME280->takeForcedMeasurement();
        float Presion = RA_cBME280->readPressure()/100.0F;
        RA_cBME280->takeForcedMeasurement();
        float Altura = RA_cBME280->readAltitude(1013.25);

        if(Humedad!=0 && Temperatura!=0 && Presion!=0 && (RA_cBME280->InitOk() >= 0) )
        {
            _DataJson2->SetDato(_DataJson2->Temperatura,Temperatura);
            _DataJson2->SetDato(_DataJson2->Humedad, Humedad);
            _DataJson2->SetDato(_DataJson2->Presion, Presion);
            _DataJson2->SetDato("a_BME", Altura);
            txt_temp->setText(QString::number(Temperatura).toStdString().c_str());
            txt_Presion->setText(QString::number(Presion).toStdString().c_str());
            txt_hum->setText(QString::number(Humedad).toStdString().c_str());
            if(!StateBME280)
            {
                _DataJson2->SetDato("alert", "Alerta BME280 Reconectado");
                StateBME280 =true;
            }
        }
        else
        {
            txt_temp->setText("null");
            txt_Presion->setText("null");
            txt_hum->setText("null");

            if(StateBME280)
            {
                _DataJson2->SetDato("alert", "Alerta BME280 Desconectado");
                StateBME280 =false;
            }

        }
        if(_DataGPS.fix !=0)
        {
            _DataGPS.fix = 0;
            _DataJson2->SetDato(_DataJson2->longitud, _DataGPS.longitud);
            _DataJson2->SetDato(_DataJson2->latitud, _DataGPS.latitud);
            _DataJson2->SetDato("a_GPS", _DataGPS.altura);
            _DataJson2->SetDato("fixgps", _DataGPS.fix);
        }
        else txt_Fix->setText("null");


        _DataJson2->SetDato("l_t",MetaData._Temperatura);
        _DataJson2->SetDato("l_r",MetaData._RAM);
        _DataJson2->SetDato("l_s",MetaData._SOCKET);
        _DataJson2->SetDato("l_p",MetaData._Procesos);
        _DataJson2->SetDato("l_e",MetaData._EspacioDisco);

        if(_DataJson2->WriteJson()) {
            qDebug() << "Escribio archivo Json \n";
        }
        else qDebug() << "Problemas al escribir archivo JSon \n";
        _DataJson2->ClearArray();
        NewData=true;
        SabeDataCsv();
        RstData();
        DateTimer->StartTimer();

    }

}



void Racimo3::DataLogs()
{
    LogsThread->CheckESpacioDisco();
    LogsThread->CheckProcesos();
    LogsThread->CheckRAM();
    LogsThread->CheckSOCKET();
    LogsThread->CheckStatusWIFI();
    LogsThread->CheckTemperatura();
    if(MetaData._StatusWIFI)
    {
        txt_wifi->setText("Si");
        if(InitAPP){  SetHora();  InitAPP =false;        DateTimer->StartTimer(); }
        TimerAlertWifi->stop();
        if(AlertWifi) _DataJson2->SetDato("alert", "Alerta con acceso a internet");
        AlertWifi =false;
        if(NewData)
        {
            if(Transmision())
            {
                _DataJson2->ClearJson();
                RA_cGPIO1->WriteGpio(GPIOTransmision,PI_OFF);
                NewData=false;
            }
            else _DataJson2->SetDato("alert", "Falla al transmitir datos");
        }
    }
    else
    {
        txt_wifi->setText("No");
        if(!AlertWifi && !TimerAlertWifi->isActive()) TimerAlertWifi->start(); // solo se inicia una vez cada que se queda sin internet por mas de 1 minuto
    }
}

void Racimo3::newDataGPS()
{

    txt_longitud->setText(QString::number(RA_cGPS->longitudeDegrees).toStdString().c_str());
    txt_latitud->setText(QString::number(RA_cGPS->latitudeDegrees).toStdString().c_str());
    txt_Altitud->setText(QString::number(RA_cGPS->altitude).toStdString().c_str());
    txt_Fix->setText(QString::number(static_cast<int>(RA_cGPS->fixquality)).toStdString().c_str());
        _DataGPS.fix = RA_cGPS->fixquality;
        _DataGPS.longitud = QString::number(RA_cGPS->longitudeDegrees);
        _DataGPS.longitud = QString::number(RA_cGPS->longitudeDegrees);
        _DataGPS.altura = RA_cGPS->altitude;

}

void Racimo3::SlotTemperatura(float temperatura)
{
    //qDebug() << "temperatura =" << temperatura;

    MetaData._Temperatura =temperatura;

    if(temperatura > 75){
        if(!AlertTemperatura)QTimer::singleShot(40*1000,this,SLOT(check_AlertTemperatura()));
        AlertTemperatura = true;
    }
}

void Racimo3::SlotRAM(float RAM)
{
    //qDebug() << "RAM =" << RAM;
   MetaData._RAM =RAM;
   if(RAM > 60){
       if(!AlertRAM)QTimer::singleShot(4*1000,this,SLOT(check_AlertRAM()));
       AlertRAM = true;
   }
}

void Racimo3::SlotSOCKET(int SOCKET)
{
    //qDebug() << "SOCKET =" << SOCKET;
    MetaData._SOCKET =SOCKET;
}

void Racimo3::SlotProcesos(int Procesos)
{
    //qDebug() << "Procesos =" << Procesos;
    MetaData._Procesos = Procesos;
}

void Racimo3::SlotStatusWIFI(bool StatusWIFI)
{
    //qDebug() << "StatusWIFI =" << StatusWIFI;
    MetaData._StatusWIFI =StatusWIFI;
}

void Racimo3::SlotEspacioDisco(int EspacioDisco)
{
    //qDebug() << "EspacioDisco =" << EspacioDisco;
    MetaData._EspacioDisco =EspacioDisco;
}

void Racimo3::check_AlertRAM()
{
    if(MetaData._RAM > 60)
    {
        _DataJson2->SetDato("alert", "Alerta excesivo consumo de RAM reinicio inminente!");
        _DataJson2->WriteJson();
        NewData= true;
        QTimer::singleShot(30*1000,this,SLOT(ReinicioRaspi()));
    }
    else AlertRAM =false;
}

void Racimo3::check_AlertTemperatura()
{
    if(MetaData._Temperatura > 75 )
    {
        _DataJson2->SetDato("alert", "Alerta temperatura muy alta reinicio inminente!");
        _DataJson2->WriteJson();
        NewData= true;
        QTimer::singleShot(30*1000,this,SLOT(ReinicioRaspi()));
    }
    else AlertTemperatura =false;
}

void Racimo3::ReinicioRaspi()
{
    system("sudo reboot now");
}

void Racimo3::ShutdownRaspi()
{
    system("sudo shutdown now");
}

void Racimo3::CerrarApp()
{
    this->~Racimo3();

}
