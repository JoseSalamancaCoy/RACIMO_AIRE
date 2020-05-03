#! /bin/bash
echo "Compilando libreria NexTouch ..."
qmake
make

echo "Instalando libreria NexTouch ..."
sudo cp libNexTouch.so /usr/lib/
sudo cp libNexTouch.so.1 /usr/lib/
sudo cp libNexTouch.so.1.0 /usr/lib/
sudo cp libNexTouch.so.1.0.0 /usr/lib/
echo "Intalacion Finalizada! "
