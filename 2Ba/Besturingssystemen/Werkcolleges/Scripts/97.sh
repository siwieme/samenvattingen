#!/bin/bash

if (($#!=2));then
    echo "Fout aantal parameters" >&2
    exit 1
fi

if [[ ! -d "$1" ]];then
    echo "$1 is geen directory" >&2
    exit 1
fi

if [[ ! "$2" =~ ^[0-9]+$ ]];then
    echo "$2 is geen getal" >&2
    exit 1
fi

total_files=0
total_size=0

while read size name; do
    if ((size>$2));then
        ((total_files++))
        ((total_size+=size))
        echo "$name"
    fi
done < <(find "$1" -type f -printf "%s %p\n")

echo "De totale grootte van de bestanden is $total_size en dat voor $total_files bestanden."