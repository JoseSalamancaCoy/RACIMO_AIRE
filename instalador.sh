#!/bin/bash

echo Abriendo instalador!

sudo apt-get update -y

echo Update Terminado!

sudo apt-get upgrade -y

echo Upgrade Terminado!

sleep 2s

echo Instalando Qt ...

sudo apt-get install qt5-default -y

echo Instalando QtCreator ...

sudo apt-get install qtcreator -y

echo Instalando Php-Curl ...

sudo apt-get install php5-curl -y

echo Instalando Essensials ...

sudo apt-get install build-essential -y

echo Actualizando

sleep 2s

sudo apt-get update -y

sudo sh InstallWatchdog.sh 

cd Documents/RacimoAire && sudo sh DesinstaladorLibrerias.sh && sudo sh InstaladorLibrerias.sh
echo TAREAS TERMINADAS.
cd 

sudo cp RST.sh /root/
