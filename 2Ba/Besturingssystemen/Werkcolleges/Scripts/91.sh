#!/bin/bash

while IFS=: read -a array
do
    if (( ${array[2]} == $1 ))
    then
        echo ${array[0]}
    fi
done < /etc/passwd