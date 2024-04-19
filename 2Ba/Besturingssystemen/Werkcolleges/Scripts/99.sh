#!/bin/bash

if (($#!=1)); then
    echo "fout aantal argumenten"
    exit
fi

IFS=:

while read -r group_name password group_id group_list; do
    IFS=,
    for user in $group_list; do
        echo "$group_name:$user" >> 99.txt
    done
    IFS=:
done < "/etc/group"

sort -t: -k1 -n 99.txt | uniq -u

IFS=:

while read -r group user; do
    if [[ "$group" == "$1" ]]; then
        echo "$user"
    fi
done < 99.txt