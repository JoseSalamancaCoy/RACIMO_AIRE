#! /bin/bash
echo "Compilando libreria DataRacimo ..."
qmake
make

echo "Instalando libreria DataRacimo ..."
sudo cp libDataParticulado.so /usr/lib/
sudo cp libDataParticulado.so.1 /usr/lib/
sudo cp libDataParticulado.so.1.0 /usr/lib/
sudo cp libDataParticulado.so.1.0.0 /usr/lib/
echo "Intalacion Finalizada! "
