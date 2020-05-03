#! /bin/bash
echo "DesInstalando Racimo ..."
sleep 3
cd Libreria/Crpigpio && qmake && sudo sh UnInstall.sh && cd ..
cd OPCN2 && qmake && sudo sh UnInstall.sh && cd ..
cd PMS && qmake && sudo sh UnInstall.sh && cd ..
cd GPS && qmake && sudo sh UnInstall.sh && cd ..
cd ADS1115 && qmake && sh UnInstall.sh && cd ..
cd Adafruit_BME280 && qmake && sudo sh UnInstall.sh && cd ..
cd Adafruit_INA219 && qmake && sudo sh UnInstall.sh && cd ..
cd DataJson && qmake && sudo sh UnInstall.sh && cd ..
cd DataJson2 && qmake && sudo sh UnInstall.sh && cd ..
cd DataParticulado && qmake && sudo sh UnInstall.sh && cd ..
cd LogsSystem && qmake && sudo sh UnInstall.sh && cd ..
cd NextionRaspberrypi && qmake && sudo sh UnInstall.sh && cd ..
cd Nextion && qmake && sudo sh UnInstall.sh && cd ..
cd CDateTimer && qmake && sudo sh UnInstall.sh && cd ..
cd RacimoHttp && qmake && sudo sh UnInstall.sh && cd ..

echo "DesInstalacion de Racimo Aire Finalizada ..."



