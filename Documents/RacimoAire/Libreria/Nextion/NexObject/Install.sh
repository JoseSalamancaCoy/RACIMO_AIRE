#! /bin/bash
echo "Compilando libreria CrPigpio ..."
qmake
make

echo "Instalando libreria CrPigpio ..."
sudo cp libNexObject.so /usr/lib/
sudo cp libNexObject.so.1 /usr/lib/
sudo cp libNexObject.so.1.0 /usr/lib/
sudo cp libNexObject.so.1.0.0 /usr/lib/
echo "Intalacion Finalizada! "
