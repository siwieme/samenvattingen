#!/bin/bash

if (( $# != 1 )); then
    ip="192.168.16.8"
else
    ip=$1
fi
IFS=. read a b c d rest <<< "$ip"
if [ "$a" -ge 0 -a "$a" -le 255 ] && [ "$b" -ge 0 -a "$b" -le 255 ] && [ "$c" -ge 0 -a "$c" -le 255 ] && [ "$d" -ge 0 -a "$d" -le 255 ]; then
  echo "Het ingegeven adres is correct."
else
  echo "Het ingegeven adres is fout."
fi