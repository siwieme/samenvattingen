#!/bin/bash

: << 'END'

Het bestand pagefile.out bevat de uitvoer van een Windows batch file:
dir \\AL005951\c$\pagefile.sys
dir \\AL005952\c$\pagefile.sys
...
Elk van de 2.901 dir-opdrachten werd beantwoord met regels van de vorm:
C:\WINDOWS\system32>dir \\AL005951\c$\pagefile.sys
Volume in drive \\AL005951\c$ is Windows
Volume Serial Number is D0A0-4386
Directory of \\AL005951\c$
02/08/20 02:12 146.800.640 pagefile.sys
1 File(s) 146.800.640 bytes
577.850.880 bytes free
De regel met de woorden bytes free vermeldt de beschikbare ruimte op het volume C:.
Maak een script dat een tekstbestand genereert met de namen van alle toestellen die
minder dan 80 MB vrij hebben op de C: schijf, één per regel.

END

machine=""

while read -r line; do
    if [[ $line == *drive* ]]; then
        machine=$(echo $line | awk '{print $4}')
        # remove backslashes
        machine=${machine//\\/}
        # remove c$
        machine=${machine//c$/}
    fi
    if [[ $line == *bytes*free ]]; then

        free=$(echo $line | awk '{print $1}')
        free=${free//./}
        if (( $((free)) < 80000000 )); then
            echo $machine >> less_than_80MB.txt
        fi
    fi
done < pagefile.out