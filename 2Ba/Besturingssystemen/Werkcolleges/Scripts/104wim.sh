#!/bin/bash

while [[ -n "$1" ]]; do
    case "$1" in
        -?*)
            opties=${1#?}
            while read -N 1 optie; do
                [[ $optie != ]]
            done <<< "$opties"
        [^-]?*)

done
