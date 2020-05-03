#! /bin/bash
echo "Instalando Racimo ..."
sleep 3
sudo apt-get update -y
sudo apt-get upgrade -y
cd Libreria/Crpigpio && sudo sh Install.sh && cd ..
cd OPCN2 && sudo sh Install.sh && cd ..
cd PMS && sudo sh Install.sh && cd ..
cd GPS && sudo sh Install.sh && cd ..
cd ADS1115 && sh Install.sh && cd ..
cd Adafruit_BME280 && sudo sh Install.sh && cd ..
cd Adafruit_INA219 && sudo sh Install.sh && cd ..
cd DataJson && sudo sh Install.sh && cd ..
cd DataJson2 && sudo sh Install.sh && cd ..
cd DataParticulado && sudo sh Install.sh && cd ..
cd LogsSystem && sudo sh Install.sh && cd ..
cd NextionRaspberrypi && sudo sh Install.sh && cd ..
cd Nextion && sudo sh Install.sh && cd ..
cd CDateTimer && sudo sh Install.sh && cd ..
sudo apt-get install curl
sudo apt-get install libcurl4-openssl-dev
sudo apt-get update -y
sudo apt-get upgrade -y
sudo apt-get install curl
sudo apt-get install libcurl4-openssl-dev


cd RacimoHttp && sudo sh Install.sh && cd ..
cd .. && cd RacimoAire3 && qmake && make clean && make
sudo cp RacimoAire3 /bin/ && sudo cp RacimoAire3 /root/ && cd ..
cd /home/pi/Documents/RacimoAire/DaemonRacimo/Daemon && qmake && make clean && make && sudo cp Daemon /root/

echo "Instalacion de Racimo Aire Finalizada ..."


cd /home/pi && cd RACIMOAIRE/Comunicacion/GetHttpCurl && qmake && make clean && make && cp GetHttpCurl /bin/

