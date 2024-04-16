#!/bin/bash

while IFS=: read user x uid gid rest
do
    if [[ -z ${array[$gid]} ]]; then
        array[$gid]=1
    else
        ((array[$gid]++))
    fi
done < /etc/passwd

for i in ${!array[@]}
do
    printf "%d:%5d\n" $i ${array[$i]}
done