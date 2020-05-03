#! /bin/bash
echo "Compilando libreria NexButton ..."
qmake
make

echo "Instalando libreria NexButton ..."
sudo cp libNexButton.so /usr/lib/
sudo cp libNexButton.so.1 /usr/lib/
sudo cp libNexButton.so.1.0 /usr/lib/
sudo cp libNexButton.so.1.0.0 /usr/lib/
echo "Intalacion Finalizada! "
