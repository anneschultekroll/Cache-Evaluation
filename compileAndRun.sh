#!/bin/bash

g++ main.cpp -o main -O0 # compile
lres=$?
if [ $lres -eq 0 ]; then
   echo "### run speedtest"
   N=1
   k=1000
   echo "" > output.csv # create empty file
   while [ $N -le 1000000 ]; do # do as long as $N is less or equal
      echo "###...  N=$N   k=$k"
      ./main $k $N >> output.csv # append measurement behind
      if [ $N -lt 64000 ] && [ $N -ge 1000 ]; then
         N=$(($N + 1000))
      elif [ $N -lt 100000 ]; then
         N=$(($N * 2))
      else
         N=$(($N + 100000))
      fi
   done
   echo "### plotting via python"
   python plot.py # plotting via python
else
   echo "### COMPILE ERROR"
fi
echo "### Now Exit"