#!/bin/bash

while IFS=: read naam x uid rest
do
    if (( uid == $1 ))
    then
        echo $naam
    fi
done < /etc/passwd