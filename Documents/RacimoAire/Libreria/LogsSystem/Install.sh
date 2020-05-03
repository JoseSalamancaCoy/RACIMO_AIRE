#! /bin/bash
echo "Compilando libreria LogsSystem ..."
qmake
make

echo "Instalando libreria LogsSystem ..."
sudo cp libLogsSystem.so /usr/lib/
sudo cp libLogsSystem.so.1 /usr/lib/
sudo cp libLogsSystem.so.1.0 /usr/lib/
sudo cp libLogsSystem.so.1.0.0 /usr/lib/
echo "Intalacion de LogsSystem Finalizada! "
