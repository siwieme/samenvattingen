#!/bin/bash

read n naam < <(wc -l $1)


index=$((n-$2))
teller=0

while read lijn
do 
    if (($teller >= $index))
    then
        echo $lijn
    fi
    ((teller++))
done < "$1"