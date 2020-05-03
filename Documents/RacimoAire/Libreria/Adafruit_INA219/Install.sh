#! /bin/bash
echo "Compilando libreria AdafruitINA_219 ..."
qmake
make

echo "Instalando libreria AdafruitINA_219 ..."
sudo cp libAdafruit_INA219.so /usr/lib/
sudo cp libAdafruit_INA219.so.1 /usr/lib/
sudo cp libAdafruit_INA219.so.1.0 /usr/lib/
sudo cp libAdafruit_INA219.so.1.0.0 /usr/lib/
echo "Intalacion Finalizada! "
