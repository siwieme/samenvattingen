#!/bin/bash

while read -r w1 w2 w3 ; do
    [[ $w1 == "Directory" ]] && {
        #comp=${w3#??}
        #comp=${comp%???}
        IFS=\\ read -r a b comp d <<< "$w3"
    }
    [[ "$w2 $w3" == "bytes free" ]] && {
        ((${w1//./} < 80*1024*1024)) && echo $comp
    }
        
done < pagefile.out