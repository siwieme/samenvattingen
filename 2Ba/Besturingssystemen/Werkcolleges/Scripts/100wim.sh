#!/bin/bash

declare -A array

for i in "$@"; do
    ((array["$i"]+=1))
done

for i in "${!array[@]}"; do
    if (( ${array[$i]} >= 2 )); then
        echo "$i komt minstens twee keer voor"
    fi
done