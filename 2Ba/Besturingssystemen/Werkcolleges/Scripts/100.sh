#!/bin/bash

declare -A array

ignoreCase=false

if [ "$1" == "-i" -o "$1" == "-I" ]; then
    ignoreCase=true
fi

for i in "$@"; do
    if [ "$i" == "-i" -o "$i" == "-I" ]; then
        continue
    fi
    if [ ignoreCase ] ; then
        ((array[${i,,}]++))
    else
        ((array[$i]++))
    fi
done

for i in ${!array[@]}; do
    if (( ${array[$i]} >= 2 )); then
        printf "%s\n" $i 
    fi
done