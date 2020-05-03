#! /bin/bash
echo "Compilando libreria NexProgressbar ..."
qmake
make

echo "Instalando libreria NexProgressbar ..."
sudo cp libNexProgressBar.so /usr/lib/
sudo cp libNexProgressBar.so.1 /usr/lib/
sudo cp libNexProgressBar.so.1.0 /usr/lib/
sudo cp libNexProgressBar.so.1.0.0 /usr/lib/
echo "Intalacion Finalizada! "
