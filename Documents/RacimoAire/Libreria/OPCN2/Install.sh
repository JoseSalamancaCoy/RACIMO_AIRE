#! /bin/bash
echo "Compilando libreria OPCN2 ..."
qmake
make

echo "Instalando libreria OPCN2 ..."
sudo cp libOPCN2.so /usr/lib/
sudo cp libOPCN2.so.1 /usr/lib/
sudo cp libOPCN2.so.1.0 /usr/lib/
sudo cp libOPCN2.so.1.0.0 /usr/lib/
echo "Intalacion Finalizada! "
