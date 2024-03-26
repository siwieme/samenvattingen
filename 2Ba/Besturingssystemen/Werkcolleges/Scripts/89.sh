#!/bin/bash

read -a array <<< $(wc $1)

# read -a array < <(wc $1)

echo ${array[0]}

echo ""

echo "De inhoud van de array is ${array[@]}"

echo ""

echo "De indices van de array zijn ${!array[@]}"