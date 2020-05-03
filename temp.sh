#!/bin/bash
 #Shell script: temp.sh
 #Autor: Jose Luis Salamanca
 cpu=$(cat /sys/class/thermal/thermal_zone0/temp)
 echo "Temp.CPU => $((cpu/1000))"
