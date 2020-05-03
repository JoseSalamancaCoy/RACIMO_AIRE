#include "dialog.h"
#include "ui_dialog.h"
#include <QDebug>
#include <QFile>
Dialog::Dialog(QObject *parent) :
    QObject(parent)
{

    Delta_muestra_muestra = 10000;
    NewData = false;

    _DataJson2 = new DataJson2("/home/pi/RACIMOAIRE/Configuracion/JsonBase.json","/home/pi/RACIMOAIRE/");
    DateTimer = new CDateTimer("/home/pi/RACIMOAIRE/Configuracion/TimeConfig.txt",this);
    connect(DateTimer,&CDateTimer::timeout, this, &Dialog::Muestra);
    TimeoutLectura = new QTimer();
    TimeoutLectura->setInterval(250000);
    connect(TimeoutLectura,&QTimer::timeout, this, &Dialog::setTimeoutlectura);

    RA_cGPIO1 = new Crpigpio(true,this);
    RA_cGPIO2 = new Crpigpio(false,this);
    RA_cGPIO3 = new Crpigpio(false,this);
    RA_cGPIO4 = new Crpigpio(false,this);
    RA_cGPIO5 = new Crpigpio(false,this);
    Timer =new QTimer;


    RA_cGPIO2->SetPinMode(GPIOPMSRX2,PI_INPUT);
    RA_cGPIO2->SetPullUpDown(GPIOPMSRX2,PI_PUD_DOWN);
    RA_cPMS1 = new PMS(RA_cGPIO1 , GPIOPMSSet1 , GPIOPMSReSet1 , GPIOPMSRX1 , Delta_muestra_muestra);
    RA_cPMS2 = new PMS(RA_cGPIO2 , GPIOPMSSet2 , GPIOPMSReSet2 , GPIOPMSRX2 , Delta_muestra_muestra);
    RA_cPMS3 = new PMS(RA_cGPIO3 , GPIOPMSSet3 , GPIOPMSReSet3 , GPIOPMSRX3 , Delta_muestra_muestra);
    RA_cPMS4 = new PMS(RA_cGPIO4 , GPIOPMSSet4 , GPIOPMSReSet4 , GPIOPMSRX4 , Delta_muestra_muestra);
    RA_cPMS5 = new PMS(RA_cGPIO5 , GPIOPMSSet5 , GPIOPMSReSet5 , GPIOPMSRX5 , Delta_muestra_muestra);



    RA_cOPC1 = new OPCN2(RA_cGPIO1,0,0);
    RA_cOPC2 = new OPCN2(RA_cGPIO2,1,0);
    RA_cOPC3 = new OPCN2(RA_cGPIO3,0,1);
    RA_cOPC4 = new OPCN2(RA_cGPIO4,1,1);
    RA_cOPC5 = new OPCN2(RA_cGPIO5,2,1);

    uint32_t MuestraPromedio = (3*60000) + 20000 ;

    RA_cDataParticulado1 = new DataParticulado(RA_cOPC1 , RA_cPMS1 ,Delta_muestra_muestra, MuestraPromedio,this);
    RA_cDataParticulado1->Pasivo();
    RA_cDataParticulado2 = new DataParticulado(RA_cOPC2 , RA_cPMS2 , Delta_muestra_muestra, MuestraPromedio,this);
    RA_cDataParticulado2->Pasivo();
    RA_cDataParticulado3 = new DataParticulado(RA_cOPC3 , RA_cPMS3 , Delta_muestra_muestra, MuestraPromedio,this);
    RA_cDataParticulado3->Pasivo();
    RA_cDataParticulado4 = new DataParticulado(RA_cOPC4 , RA_cPMS4 , Delta_muestra_muestra, MuestraPromedio,this);
    RA_cDataParticulado4->Pasivo();
    RA_cDataParticulado5 = new DataParticulado(RA_cOPC5 , RA_cPMS5 , Delta_muestra_muestra, MuestraPromedio,this);
    RA_cDataParticulado5->Pasivo();
    qDebug() << "AjA";
    Timer->setInterval(500);
    Timer->start();

    connect(RA_cDataParticulado1,&DataParticulado::DataOk,this, &Dialog::DataOk1);
    connect(RA_cDataParticulado1,&DataParticulado::DataOkPMS,this, &Dialog::DataParticuladoOkPMS1);
    connect(RA_cDataParticulado1,&DataParticulado::DataOkOPC,this, &Dialog::DataParticuladoOkOPC1);
    connect(RA_cPMS1,&PMS::newData,this, &Dialog::DataOkPMS1);
    connect(RA_cOPC1,&OPCN2::newData,this, &Dialog::DataOkOPC1);


    connect(RA_cDataParticulado2,&DataParticulado::DataOk,this, &Dialog::DataOk2);
    connect(RA_cDataParticulado2,&DataParticulado::DataOkPMS,this, &Dialog::DataParticuladoOkPMS2);
    connect(RA_cDataParticulado2,&DataParticulado::DataOkOPC,this, &Dialog::DataParticuladoOkOPC2);
    connect(RA_cPMS2,&PMS::newData,this, &Dialog::DataOkPMS2);
    connect(RA_cOPC2,&OPCN2::newData,this, &Dialog::DataOkOPC2);

    connect(RA_cDataParticulado3,&DataParticulado::DataOk,this, &Dialog::DataOk3);
    connect(RA_cDataParticulado3,&DataParticulado::DataOkPMS,this, &Dialog::DataParticuladoOkPMS3);
    connect(RA_cDataParticulado3,&DataParticulado::DataOkOPC,this, &Dialog::DataParticuladoOkOPC3);
    connect(RA_cPMS3,&PMS::newData,this, &Dialog::DataOkPMS3);
    connect(RA_cOPC3,&OPCN2::newData,this, &Dialog::DataOkOPC3);

    connect(RA_cDataParticulado4,&DataParticulado::DataOk,this, &Dialog::DataOk4);
    connect(RA_cDataParticulado4,&DataParticulado::DataOkPMS,this, &Dialog::DataParticuladoOkPMS4);
    connect(RA_cDataParticulado4,&DataParticulado::DataOkOPC,this, &Dialog::DataParticuladoOkOPC4);
    connect(RA_cPMS4,&PMS::newData,this, &Dialog::DataOkPMS4);
    connect(RA_cOPC4,&OPCN2::newData,this, &Dialog::DataOkOPC4);

    connect(RA_cDataParticulado5,&DataParticulado::DataOk,this, &Dialog::DataOk5);
    connect(RA_cDataParticulado5,&DataParticulado::DataOkPMS,this, &Dialog::DataParticuladoOkPMS5);
    connect(RA_cDataParticulado5,&DataParticulado::DataOkOPC,this, &Dialog::DataParticuladoOkOPC5);
    connect(RA_cPMS5,&PMS::newData,this, &Dialog::DataOkPMS5);
    connect(RA_cOPC5,&OPCN2::newData,this, &Dialog::DataOkOPC5);


    connect(Timer, &QTimer::timeout, this, &Dialog::Show);


    TimeDataLogs =new QTimer;
    TimeDataLogs->setInterval(2000);
    TimeDataLogs->start();

    LogsThread = new LogsSystem(this);
    connect(TimeDataLogs,&QTimer::timeout, this, &Dialog::DataLogs);
    connect(LogsThread,&LogsSystem::SignalTemperatura,this, &Dialog::SlotTemperatura);
    connect(LogsThread,&LogsSystem::SignalRAM,this, &Dialog::SlotRAM);
    connect(LogsThread,&LogsSystem::SignalProcesos,this, &Dialog::SlotProcesos);
    connect(LogsThread,&LogsSystem::SignalSOCKET,this, &Dialog::SlotSOCKET);
    connect(LogsThread,&LogsSystem::SignalStatusWIFI,this, &Dialog::SlotStatusWIFI);
    connect(LogsThread,&LogsSystem::SignalEspacioDisco,this, &Dialog::SlotEspacioDisco);

    LogsThread->start(QThread::HighPriority);

    RstData();
    DateTimer->StartTimer();
    _timeoutlectura =false;

}

Dialog::~Dialog()
{
    RA_cOPC1->setFanAndLaserOff();
    RA_cOPC2->setFanAndLaserOff();
    RA_cOPC3->setFanAndLaserOff();
    RA_cOPC4->setFanAndLaserOff();
    RA_cOPC5->setFanAndLaserOff();

    RA_cPMS1->sleep();
    RA_cPMS2->sleep();
    RA_cPMS3->sleep();
    RA_cPMS4->sleep();
    RA_cPMS5->sleep();

    delete RA_cOPC1;
    delete RA_cOPC2;
    delete RA_cOPC3;
    delete RA_cOPC4;
    delete RA_cOPC5;


    delete RA_cPMS1;
    delete RA_cPMS2;
    delete RA_cPMS3;
    delete RA_cPMS4;
    delete RA_cPMS5;

    delete RA_cGPIO1;


    delete this;
}

void Dialog::setTimeoutlectura()
{
    _timeoutlectura = true;
}

void Dialog:: POSTHttp(char *charjson)
{

    CURL *hnd = curl_easy_init();
    curl_easy_setopt(hnd, CURLOPT_CUSTOMREQUEST, "POST");
    curl_easy_setopt(hnd, CURLOPT_URL, "http://racimo.mpsig.com:3000/racimohub/v013dev/datasets");
    struct curl_slist *headers = NULL;
    headers = curl_slist_append(headers, "Postman-Token: d75df676-a5e1-448a-8b70-177609f83454");
    headers = curl_slist_append(headers, "Cache-Control: no-cache");
    headers = curl_slist_append(headers, "Content-Type: application/json");
    curl_easy_setopt(hnd, CURLOPT_HTTPHEADER, headers);
    qDebug() << "ok";
    curl_easy_setopt(hnd, CURLOPT_POSTFIELDS, charjson ); //Envio
    qDebug() << "ok";

    CURLcode ret = curl_easy_perform(hnd);
    qDebug() << "ok";
    curl_easy_cleanup(hnd);
    curl_global_cleanup();

}

void Dialog::SetHora()
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

void Dialog::Transmision()
{
    QStringList _DataJsonString;
    if(_DataJson2->readJson(&_DataJsonString)) qDebug() << "Se leyeron los archivos Json";
    else qDebug() << "Problemas al leer los archivo Json";

    for(int i=0;i<_DataJsonString.length() ; i++)
    {
        std::string STR = QString(_DataJsonString.operator [](i)).toStdString();
        char *String = new char[STR.length() + 1];
        strcpy(String, STR.c_str());;
        qDebug() << "1";
        POSTHttp(String);
        delete [] String;
    }
}

void Dialog::SabeDataCsv()
{
    QFile file("/home/pi/PMS.csv");
    if(!file.open(QIODevice::Append|QIODevice::Text))
    {
        qDebug() << "Error al abrir el archivo";
        return;
    }
    QString str;
    str="";
    for(int i =0; i<5; i++)
    {
        str += QString::number(List_PMS_PM1[i]) + ";";
        str += QString::number(List_PMS_PM2_5[i]) + ";";
        str += QString::number(List_PMS_PM10[i]) + ";";
    }
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
    for(int i =0; i<5; i++)
    {
        str2 += QString::number(List_OPC_PM1[i]) + ";";
        str2 += QString::number(List_OPC_PM2_5[i]) + ";";
        str2 += QString::number(List_OPC_PM10[i]) + ";";
    }
    str2+= QDateTime::currentDateTimeUtc().toString(Qt::ISODate).replace("Z","."+QString::number(QTime::currentTime().msec())+"Z");

    str2+="\n";
    QTextStream Strem2(&file2);
    Strem2 << str2;
    file2.close();
}

void Dialog::RstData()
{
    for(int i =0; i<5; i++)
    {
        List_PMS_PM1[i] = 0.0; List_PMS_PM2_5[i] = 0.0;  List_PMS_PM10[i] =0.0;
        List_OPC_PM1[i] = 0.0; List_OPC_PM2_5[i] = 0.0;  List_OPC_PM10[i] =0.0;
        List_Check_PMS[i] = false;  List_Check_OPC[i] =false;
    }
}

void Dialog::Muestra()
{
    qDebug() << "INICIO DE MUESTRA";
    RA_cDataParticulado1->Muestra();
    RA_cDataParticulado2->Muestra();
    RA_cDataParticulado3->Muestra();
    RA_cDataParticulado4->Muestra();
    RA_cDataParticulado5->Muestra();
    TimeoutLectura->start();
}



// Sensores 1 ***********************************************
void Dialog::DataOk1()
{

}

void Dialog::DataParticuladoOkPMS1(float PM1Promedio, float PM2_5Promedio, float PM10Promedio)
{
    List_PMS_PM1[0] = PM1Promedio;        List_PMS_PM2_5[0] = PM2_5Promedio;        List_PMS_PM10[0] = PM10Promedio;
    List_Check_PMS[0]=true;
    qDebug() << QString("Data PMS1         PM1 = %1        PM2_5 = %2          PM10 = %3 ").arg(PM1Promedio).arg(PM2_5Promedio).arg(PM10Promedio);
    _DataJson2->SetDato("pms1_pm10",List_PMS_PM10[0]);
    _DataJson2->SetDato("pms1_pm2_5",List_PMS_PM2_5[0]);
    _DataJson2->SetDato("pms1_pm1",List_PMS_PM1[0]);
}

void Dialog::DataParticuladoOkOPC1(float PM1Promedio, float PM2_5Promedio, float PM10Promedio)
{
    List_OPC_PM1[0] = PM1Promedio;        List_OPC_PM2_5[0] = PM2_5Promedio;        List_OPC_PM10[0] = PM10Promedio;
    qDebug() << QString("Data OPC1         PM1 = %1        PM2_5 = %2          PM10 = %3 ").arg(PM1Promedio).arg(PM2_5Promedio).arg(PM10Promedio);
    List_Check_OPC[0]= true;
    _DataJson2->SetDato("opc1_pm10",List_OPC_PM10[0]);
    _DataJson2->SetDato("opc1_pm2_5",List_OPC_PM2_5[0]);
    _DataJson2->SetDato("opc1_pm1",List_OPC_PM1[0]);
}

void Dialog::DataOkPMS1(float PM1, float PM2_5, float PM10)
{
    //qDebug() << QString("Data PMS1         PM1 = %1        PM2_5 = %2          PM10 = %3 ").arg(PM1).arg(PM2_5).arg(PM10);
}

void Dialog::DataOkOPC1(uint16_t PM1, uint16_t PM2_5, uint16_t PM10)
{
    //qDebug() << QString("Data OPC1         PM1 = %1        PM2_5 = %2          PM10 = %3 ").arg(PM1).arg(PM2_5).arg(PM10);
}



// Sensores 2 ****************************************************************************************************************************************//
void Dialog::DataOk2()
{

}

void Dialog::DataParticuladoOkPMS2(float PM1Promedio, float PM2_5Promedio, float PM10Promedio)
{
    List_PMS_PM1[1] = PM1Promedio;        List_PMS_PM2_5[1] = PM2_5Promedio;        List_PMS_PM10[1] = PM10Promedio;
    qDebug() << QString("Data PMS2         PM1 = %1        PM2_5 = %2          PM10 = %3 ").arg(PM1Promedio).arg(PM2_5Promedio).arg(PM10Promedio);
    List_Check_PMS[1]=true;
    _DataJson2->SetDato("pms2_pm10",List_PMS_PM10[1]);
    _DataJson2->SetDato("pms2_pm2_5",List_PMS_PM2_5[1]);
    _DataJson2->SetDato("pms2_pm1",List_PMS_PM1[1]);
}

void Dialog::DataParticuladoOkOPC2(float PM1Promedio, float PM2_5Promedio, float PM10Promedio)
{
    List_OPC_PM1[1] = PM1Promedio;        List_OPC_PM2_5[1] = PM2_5Promedio;        List_OPC_PM10[1] = PM10Promedio;
    qDebug() << QString("Data OPC2         PM1 = %1        PM2_5 = %2          PM10 = %3 ").arg(PM1Promedio).arg(PM2_5Promedio).arg(PM10Promedio);
    List_Check_OPC[1]=true;
    _DataJson2->SetDato("opc2_pm10",List_OPC_PM10[1]);
    _DataJson2->SetDato("opc2_pm2_5",List_OPC_PM2_5[1]);
    _DataJson2->SetDato("opc2_pm1",List_OPC_PM1[1]);
}

void Dialog::DataOkPMS2(float PM1, float PM2_5, float PM10)
{
    //qDebug() << QString("Data PMS2         PM1 = %1        PM2_5 = %2          PM10 = %3 ").arg(PM1).arg(PM2_5).arg(PM10);
}

void Dialog::DataOkOPC2(uint16_t PM1, uint16_t PM2_5, uint16_t PM10)
{
    //qDebug() << QString("Data OPC2         PM1 = %1        PM2_5 = %2          PM10 = %3 ").arg(PM1).arg(PM2_5).arg(PM10);
}

// Sensores 3 ****************************************************************************************************************************************//
void Dialog::DataOk3()
{
}

void Dialog::DataParticuladoOkPMS3(float PM1Promedio, float PM2_5Promedio, float PM10Promedio)
{
    List_PMS_PM1[2] = PM1Promedio;        List_PMS_PM2_5[2] = PM2_5Promedio;        List_PMS_PM10[2] = PM10Promedio;
    qDebug() << QString("Data PMS3         PM1 = %1        PM2_5 = %2          PM10 = %3 ").arg(PM1Promedio).arg(PM2_5Promedio).arg(PM10Promedio);
    List_Check_PMS[2]=true;

    _DataJson2->SetDato("pms3_pm10",List_PMS_PM10[2]);
    _DataJson2->SetDato("pms3_pm2_5",List_PMS_PM2_5[2]);
    _DataJson2->SetDato("pms3_pm1",List_PMS_PM1[2]);
}

void Dialog::DataParticuladoOkOPC3(float PM1Promedio, float PM2_5Promedio, float PM10Promedio)
{
    List_OPC_PM1[2] = PM1Promedio;        List_OPC_PM2_5[2] = PM2_5Promedio;        List_OPC_PM10[2] = PM10Promedio;
    qDebug() << QString("Data OPC3         PM1 = %1        PM2_5 = %2          PM10 = %3 ").arg(PM1Promedio).arg(PM2_5Promedio).arg(PM10Promedio);

}

void Dialog::DataOkPMS3(float PM1, float PM2_5, float PM10)
{
    //qDebug() << QString("Data PMS3         PM1 = %1        PM2_5 = %2          PM10 = %3 ").arg(PM1).arg(PM2_5).arg(PM10);

}

void Dialog::DataOkOPC3(uint16_t PM1, uint16_t PM2_5, uint16_t PM10)
{
    //qDebug() << QString("Data OPC3        PM1 = %1        PM2_5 = %2          PM10 = %3 ").arg(PM1).arg(PM2_5).arg(PM10);

}

// Sensores 4 ****************************************************************************************************************************************//
void Dialog::DataOk4()
{
}

void Dialog::DataParticuladoOkPMS4(float PM1Promedio, float PM2_5Promedio, float PM10Promedio)
{
    List_PMS_PM1[3] = PM1Promedio;        List_PMS_PM2_5[3] = PM2_5Promedio;        List_PMS_PM10[3] = PM10Promedio;
    qDebug() << QString("Data PMS4         PM1 = %1        PM2_5 = %2          PM10 = %3 ").arg(PM1Promedio).arg(PM2_5Promedio).arg(PM10Promedio);
    List_Check_PMS[3]=true;

    _DataJson2->SetDato("pms4_pm10",List_PMS_PM10[3]);
    _DataJson2->SetDato("pms4_pm2_5",List_PMS_PM2_5[3]);
    _DataJson2->SetDato("pms4_pm1",List_PMS_PM1[3]);
}

void Dialog::DataParticuladoOkOPC4(float PM1Promedio, float PM2_5Promedio, float PM10Promedio)
{
    List_OPC_PM1[3] = PM1Promedio;        List_OPC_PM2_5[3] = PM2_5Promedio;        List_OPC_PM10[3] = PM10Promedio;
    qDebug() << QString("Data OPC4         PM1 = %1        PM2_5 = %2          PM10 = %3 ").arg(PM1Promedio).arg(PM2_5Promedio).arg(PM10Promedio);

}

void Dialog::DataOkPMS4(float PM1, float PM2_5, float PM10)
{
    //qDebug() << QString("Data PMS4         PM1 = %1        PM2_5 = %2          PM10 = %3 ").arg(PM1).arg(PM2_5).arg(PM10);
}

void Dialog::DataOkOPC4(uint16_t PM1, uint16_t PM2_5, uint16_t PM10)
{
    //qDebug() << QString("Data OPC4         PM1 = %1        PM2_5 = %2          PM10 = %3 ").arg(PM1).arg(PM2_5).arg(PM10);
}

// Sensores 5 ****************************************************************************************************************************************//
void Dialog::DataOk5()
{
}

void Dialog::DataParticuladoOkPMS5(float PM1Promedio, float PM2_5Promedio, float PM10Promedio)
{
    List_PMS_PM1[4] = PM1Promedio;        List_PMS_PM2_5[4] = PM2_5Promedio;        List_PMS_PM10[4] = PM10Promedio;
    qDebug() << QString("Data PMS5         PM1 = %1        PM2_5 = %2          PM10 = %3 ").arg(PM1Promedio).arg(PM2_5Promedio).arg(PM10Promedio);
    List_Check_PMS[4]=true;

    _DataJson2->SetDato("pms5_pm10",List_PMS_PM10[4]);
    _DataJson2->SetDato("pms5_pm2_5",List_PMS_PM2_5[4]);
    _DataJson2->SetDato("pms5_pm1",List_PMS_PM1[4]);

}

void Dialog::DataParticuladoOkOPC5(float PM1Promedio, float PM2_5Promedio, float PM10Promedio)
{
    List_OPC_PM1[4] = PM1Promedio;        List_OPC_PM2_5[4] = PM2_5Promedio;        List_OPC_PM10[4] = PM10Promedio;
    qDebug() << QString("Data OPC5         PM1 = %1        PM2_5 = %2          PM10 = %3 ").arg(PM1Promedio).arg(PM2_5Promedio).arg(PM10Promedio);

}

void Dialog::DataOkPMS5(float PM1, float PM2_5, float PM10)
{
    //qDebug() << QString("Data PMS5         PM1 = %1        PM2_5 = %2          PM10 = %3 ").arg(PM1).arg(PM2_5).arg(PM10);
}

void Dialog::DataOkOPC5(uint16_t PM1, uint16_t PM2_5, uint16_t PM10)
{
    //qDebug() << QString("Data OPC5         PM1 = %1        PM2_5 = %2          PM10 = %3 ").arg(PM1).arg(PM2_5).arg(PM10);
}


//Despliegue de datos
void Dialog::Show()
{
    if( _timeoutlectura || (List_Check_PMS[0] && List_Check_PMS[1] && List_Check_PMS[2] && List_Check_PMS[3] && List_Check_PMS[4] && List_Check_OPC[0]  && List_Check_PMS[1]))
    {
        TimeoutLectura->stop();
        _timeoutlectura= false;
        QString comando= "clear";
        system(qPrintable(comando));
        qDebug() << "Sensor                 PM1               PM2.5                   PM10";
        for(int i =0; i<5; i++)
        {
            qDebug() << QString(" PMS%1                    %2                          %3                      %4     ").arg(i).arg(List_PMS_PM1[i]).arg(List_PMS_PM2_5[i]).arg(List_PMS_PM10[i]);
        }
        qDebug() << "\n\n";
        for(int i=0; i<5; i++)
        {
            qDebug() << QString("OPC%1                         %2                        %3                        %4     ").arg(i).arg(List_OPC_PM1[i]).arg(List_OPC_PM2_5[i]).arg(List_OPC_PM10[i]);
        }
        qDebug() << "\n\n";
        _DataJson2->SetDato("log_temperatura",MetaData._Temperatura);
        _DataJson2->SetDato("log_ram",MetaData._RAM);
        _DataJson2->SetDato("log_socket",MetaData._SOCKET);
        _DataJson2->SetDato("log_procesos",MetaData._Procesos);
        _DataJson2->SetDato("log_espaciodisco",MetaData._EspacioDisco);

        if(_DataJson2->WriteJson()) qDebug() << "Escribio archivo Json \n";
        else qDebug() << "Problemas al escribir archivo JSon \n";
        _DataJson2->ClearArray();
        NewData=true;
        SabeDataCsv();
        RstData();
        DateTimer->StartTimer();

    }

}



void Dialog::DataLogs()
{
    LogsThread->CheckESpacioDisco();
    LogsThread->CheckProcesos();
    LogsThread->CheckRAM();
    LogsThread->CheckSOCKET();
    LogsThread->CheckStatusWIFI();
    LogsThread->CheckTemperatura();
    if(MetaData._StatusWIFI && NewData)
    {
        Transmision();
        NewData=false;
    }
}

void Dialog::SlotTemperatura(float temperatura)
{
    //qDebug() << "temperatura =" << temperatura;

    MetaData._Temperatura =temperatura;
}

void Dialog::SlotRAM(float RAM)
{
    //qDebug() << "RAM =" << RAM;
   MetaData._RAM =RAM;
}

void Dialog::SlotSOCKET(int SOCKET)
{
    //qDebug() << "SOCKET =" << SOCKET;
    MetaData._SOCKET =SOCKET;
}

void Dialog::SlotProcesos(int Procesos)
{
    //qDebug() << "Procesos =" << Procesos;
    MetaData._Procesos = Procesos;
}

void Dialog::SlotStatusWIFI(bool StatusWIFI)
{
    //qDebug() << "StatusWIFI =" << StatusWIFI;
    MetaData._StatusWIFI =StatusWIFI;
}

void Dialog::SlotEspacioDisco(int EspacioDisco)
{
    //qDebug() << "EspacioDisco =" << EspacioDisco;
    MetaData._EspacioDisco =EspacioDisco;
}
