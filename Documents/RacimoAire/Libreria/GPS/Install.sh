#! /bin/bash
echo "Compilando libreria GPS ..."
qmake
make

echo "Instalando libreria GPS ..."
sudo cp libGPS.so /usr/lib/
sudo cp libGPS.so.1 /usr/lib/
sudo cp libGPS.so.1.0 /usr/lib/
sudo cp libGPS.so.1.0.0 /usr/lib/
echo "Intalacion Finalizada! "
