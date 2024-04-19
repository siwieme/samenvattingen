#!/bin/bash

declare -A array

if (($# > 2)); then
    if [[ ! -f "$1" ]]; then
        echo "$1 is geen geldig bestand"
    else
        while IFS= read -r lijn; do
            array["${lijn,,}"]=1
        done < "$1"

        for i in "$@"; do
            lowercase_i="${i,,}"
            if [[ -v array["$lowercase_i"] ]]; then
                echo "$i is gevonden in het bestand."
            fi
        done
    fi
else 
    echo "onvoldoende strings meegegeven"
fi
