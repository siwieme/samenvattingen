#!/bin/bash

conv=( 0 1 2 3 4 5 6 7 8 9 a b c d e f )

while read -N1 kar ; do
    echo $kar
    byte=$(printf "%d" "'$kar")
    cijfer1=$((byte/16))
    cijfer2=$((byte%16))
    echo -n ${conv[$cijfer1]}${conv[$cijfer2]}
done < "$1"