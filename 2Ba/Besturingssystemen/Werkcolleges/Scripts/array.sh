#!/bin/bash

array=( 7 "hallo" 15)

echo "De waardes van array zijn ${array[@]}"
echo "Hun indices zijn ${!array[@]}"

echo ""

array2=( [0]=7 [12]="hallo" [20]=15)

echo "De waardes van array2 zijn ${array2[@]}"
echo "Hun indices zijn ${!array2[@]}"

echo ""

echo "Nu verwijderen we de waarde op index 20 van array2 met het commando unset array2[20]"

unset array2[20]

echo ""

echo "De waardes van array2 zijn ${array2[@]}"
echo "Hun indices zijn ${!array2[@]}"