#!/bin/bash

x=/usr/bin/tail
IFS='/'
array=($x)
IFS=' \t\n'

echo "De waardes van array zijn ${array[@]}"
echo "Hun indices zijn ${!array[@]}"

echo ""
echo "Nu maken we een array die met strings gedefinieerd is:"
echo ""

declare -A array2
array2["hallo"]=7

echo "De waardes van array2 zijn ${array2[@]}"
echo "Hun indices zijn ${!array2[@]}"

