#! /bin/bash
echo "Compilando libreria NexVariable ..."
qmake
make

echo "Instalando libreria NexVariable ..."
sudo cp libNexVariable.so /usr/lib/
sudo cp libNexVariable.so.1 /usr/lib/
sudo cp libNexVariable.so.1.0 /usr/lib/
sudo cp libNexVariable.so.1.0.0 /usr/lib/
echo "Intalacion Finalizada! "
