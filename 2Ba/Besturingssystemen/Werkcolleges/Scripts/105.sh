#!/bin/bash

: << 'END'

Ontwikkel een script dat als eerste parameter een bestandsnaam heeft, en als
tweede parameter de naam van een HTML-tag (em, strong, code enz.). Geef een
overzicht van alle strings in het bestand die tussen de opgegeven tag staan. Je mag ervan
uitgaan dat de tag maximaal één keer voorkomt per regel (zowel de open- als sluittag) en
dat de sluittag op dezelfde regel staat als de opentag. Zorg er ook voor dat elke string
slechts één keer wordt weergegeven

Een for-lus kan ook gebruikt worden om de elementen van een array op te vragen. Met for i
in ${a[@]} doorloopt de variabele i alle waarden die in de array a zijn opgeslagen. Vanaf
Bash v3 kun je ook de indices(of sleutels) opvragen met for i in ${!a[@]}.

END

if (($#!=2)); then
    echo "fout aantal argumenten"
    exit
fi

if [[ ! -f $1 ]]; then
    echo "$1 is geen bestand"
    exit
fi

tag=0

while read -r line; do
    if [[ $line == *"<$2>"* ]]; then
        tag=1
        continue
    fi
    if [[ $line == *"</$2>"* ]]; then
        tag=0
        continue
    fi
    if (($tag==1)); then
        echo "$line"
    fi
done < "$1"