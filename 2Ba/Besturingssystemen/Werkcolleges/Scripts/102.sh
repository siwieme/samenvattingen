#!/bin/bash

: << 'END'
Ontwikkel een script dat een directory maakt waarvan het pad als (enige) parameter
aan het script meegegeven wordt. Indien tussenliggende directory's ook nog niet zouden
bestaan, moeten deze eveneens gecreëerd worden. Het script simuleert bijgevolg mkdir
-p. Het mag enkel interne Bash-instructies (if, for, case, let, while, read enz.) gebruiken,
en bovendien het commando mkdir, zij het zonder de optie -p. Zorg ervoor dat zowel
absolute als relatieve (t.o.v. de huidige directory) padnamen worden ondersteund.
Tip: gebruik / als scheidingsteken.
END

if (($#!=1)); then
    echo "fout aantal argumenten"
    exit
fi

IFS=/

for dir in $1; do
    if [[ ! -d $dir ]]; then
        mkdir "$dir"
    fi
    cd "$dir"
done