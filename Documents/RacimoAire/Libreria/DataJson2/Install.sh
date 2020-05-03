#! /bin/bash
echo "Compilando libreria libDataJson2 ..."
qmake
make

echo "Instalando libreria libDataJson2 ..."
sudo cp libDataJson2.so /usr/lib/
sudo cp libDataJson2.so.1 /usr/lib/
sudo cp libDataJson2.so.1.0 /usr/lib/
sudo cp libDataJson2.so.1.0.0 /usr/lib/
echo "Intalacion Finalizada! "
