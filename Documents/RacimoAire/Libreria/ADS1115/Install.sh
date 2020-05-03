#! /bin/bash
echo "Compilando libreria ADS1115 ..."
qmake
make

echo "Instalando libreria ADS1115 ..."
sudo cp libADS1115.so /usr/lib/
sudo cp libADS1115.so.1 /usr/lib/
sudo cp libADS1115.so.1.0 /usr/lib/
sudo cp libADS1115.so.1.0.0 /usr/lib/
echo "Intalacion Finalizada! "
