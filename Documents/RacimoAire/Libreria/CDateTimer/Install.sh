#! /bin/bash
echo "Compilando libreria AdafruitINA_219 ..."
qmake
make

echo "Instalando libreria AdafruitINA_219 ..."
sudo cp libCDateTimer.so /usr/lib/
sudo cp libCDateTimer.so.1 /usr/lib/
sudo cp libCDateTimer.so.1.0 /usr/lib/
sudo cp libCDateTimer.so.1.0.0 /usr/lib/
echo "Intalacion Finalizada! "
