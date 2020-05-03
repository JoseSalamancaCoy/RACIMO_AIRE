#! /bin/bash
echo "Compilando libreria Nextion..."
qmake
make

echo "Instalando libreria Nextion ..."
sudo cp libNextion.so /usr/lib/
sudo cp libNextion.so.1 /usr/lib/
sudo cp libNextion.so.1.0 /usr/lib/
sudo cp libNextion.so.1.0.0 /usr/lib/
echo "Intalacion Finalizada! "
