#! /bin/bash
echo "Compilando libreria NexHardware ..."
qmake
make

echo "Instalando libreria NexHardWare ..."
sudo cp libNexHardware.so /usr/lib/
sudo cp libNexHardware.so.1 /usr/lib/
sudo cp libNexHardware.so.1.0 /usr/lib/
sudo cp libNexHardware.so.1.0.0 /usr/lib/
echo "Intalacion Finalizada! "
