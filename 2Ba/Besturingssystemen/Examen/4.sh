#!/bin/bash

array=()
while IFS=: read getal priemfactoren ; do
    temp=()
    for getal in $priemfactoren ; do
        ((temp[$getal]++))
    done
    for el in ${!temp[@]} ; do
        [[ -z ${array[$el]} ]] && array[$el]=${temp[$el]} || {
            array[$el]="${array[$el]} ${temp[$el]}"
        }
        #echo $el ${array[$el]}
    done
done < <(factor $@)

ggd=1
for i in "${!array[@]}" ; do
    teller=0
    for j in ${array[$i]} ; do
        [[ -z $min ]] && min=$j || (($j<min)) && min=$j
        ((teller+=j))
    done
    ((teller==$#)) && ((ggd*=i**min))
done
echo $ggd