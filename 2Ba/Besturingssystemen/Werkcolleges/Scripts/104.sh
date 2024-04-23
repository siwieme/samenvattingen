#!/bin/bash

: << 'END'

Ontwikkel een script dat (zonder getopt te gebruiken) alle opties die aan het script
worden meegegeven naar standaarduitvoer wegschrijft, één per regel. Je moet dus alle
karakters die voorkomen in parameters die beginnen met een minteken verzamelen, en
deze één voor één verwerken. Bekommer je niet om opties die meerdere keren zouden
voorkomen. Voor de argumentenlijst -Ec -rq /etc/passwd -a moet het script dus als
uitvoer E, c, r, q en a produceren.

END

for arg in "$@"; do
    if [[ $arg == -* ]]; then
        for ((i=1; i<${#arg}; i++)); do
            echo "${arg:$i:1}"
        done
    fi
done