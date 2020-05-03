#! /bin/bash
echo "Compilando libreria PMS ..."
qmake
make

echo "Instalando libreria PMS ..."
sudo cp libPMS.so /usr/lib/
sudo cp libPMS.so.1 /usr/lib/
sudo cp libPMS.so.1.0 /usr/lib/
sudo cp libPMS.so.1.0.0 /usr/lib/
echo "Intalacion Finalizada! "
