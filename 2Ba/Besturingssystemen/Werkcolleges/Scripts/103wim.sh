#!/bin/bash

eerste=1

declare -A cmds

(($#==0)) && array=1

while read pid tty time cmd; do
    ((eerste==1)) && { 
        eerste=0
        continue
    }
    ((array==1)) && cmds["$cmd"]=1 || {
        for i in "$@"; do
            [[ $cmd == *$i* ]] && echo "kill -KILL $pid"
        done
    }
    echo $cmd
done < <(ps -e)
    
(($array==1)) && printf "%s\n" "${!cmds[@]}" | sort