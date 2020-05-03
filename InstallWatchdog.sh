#!/bin/bash
sudo modprobe bcm2708_wdog
echo "bcm2708_wdog" | sudo tee -a /etc/modules
sudo modprobe bcm2835_wdt
echo "bcm2835_wdt " | sudo tee -a /etc/modules
echo "Intall Watchdog"
sleep 1
sudo apt-get install watchdog chkconfig
echo "\n Watchdog Intalado"
sleep 1
sudo chkconfig watchdog on
sudo cp watchdog.conf /etc/watchdog.conf
sudo systemctl start watchdog
sudo cp watchdog.service /etc/systemd/system/
sudo systemctl daemon-reload
sudo systemctl enable watchdog
sudo systemctl start watchdog
echo "Watchdog Activado !!"
sleep 2
