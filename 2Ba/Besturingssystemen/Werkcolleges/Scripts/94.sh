#!/bin/bash

declare -A array

while read lijn ; do
    if [[ "$lijn" =~ ^Pinging ]]; then
        read a comp rest <<< "$lijn"
        array[$comp]=1	
    fi
    if [[ "$lijn" =~ ^Reply ]]; then
        unset array[$comp]
    fi
done < ping.out

for comp in ${!array[@]} ; do
    echo $comp
done|sort