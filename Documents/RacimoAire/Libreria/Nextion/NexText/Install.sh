#! /bin/bash
echo "Compilando libreria NexText ..."
qmake
make

echo "Instalando libreria NexText ..."
sudo cp libNexText.so /usr/lib/
sudo cp libNexText.so.1 /usr/lib/
sudo cp libNexText.so.1.0 /usr/lib/
sudo cp libNexText.so.1.0.0 /usr/lib/
echo "Intalacion Finalizada! "
