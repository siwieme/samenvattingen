#!/bin/bash

: << 'END'
Ontwikkel een script dat een beperkte versie van het commando wc simuleert. Het
script moet het aantal regels en de bestandsnaam afdrukken van elk bestand dat als
parameter meegegeven wordt. Het script mag enkel interne Bash-instructies (if, for,
case, let, while, read, echo enz.) gebruiken en geen externe commando's; het gebruik
van awk, sed, perl en wc in het bijzonder is niet toegelaten. Je zult bijgevolg elk bestand
regel voor regel moeten inlezen en deze tellen. Het script moet bovendien een
samenvattende regel weergeven met het totale aantal regels. Indien geen enkele
parameter meegegeven wordt, neem je alle bestanden in de huidige werkdirectory in
beschouwing. Los dit zo beknopt mogelijk op met de speciale notaties voor shell-
variabelen 
END

if (($#==0)); then
    set -- *
else 
    if [[ ! -d $1 ]]; then
        echo "$1 is geen map"
        exit
    else
        set -- "$1"/*
    fi
fi 

total=0

for file in "$@"; do
    lines=0
    if [[ ! -f $file ]]; then
        echo "$file is geen bestand"
        continue
    fi
    while read -r; do
        ((lines++))
        ((total++))
    done < "$file"
    printf "%6d %s\n" $lines $file
done

printf -- "------ ------\n"
printf "%6d total\n" $total