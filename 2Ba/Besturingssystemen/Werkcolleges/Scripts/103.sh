#!/bin/bash

: << 'END'
Enerzijds kun je met behulp van het commando ps -e informatie opvragen over alle
processen die actief zijn. De vier kolommen in de output tonen respectievelijk het
proces-ID (PID), de TTY device file van de (pseudo-)terminal, de CPU time, en het
commando dat het proces opgestart heeft. Anderzijds kun je met behulp van het
commando kill -KILL pid een proces met willekeurig proces-ID afbreken. Ontwikkel een
script dat alle processen afbreekt waarvan het commando één van de strings bevat die
als parameters bij het oproepen van het script meegegeven wordt. Indien geen enkele
parameter meegegeven wordt, moet het script een gesorteerde lijst weergeven van alle
unieke commandonamen van actieve processen. Behalve de interne instructies (if, for,
case, let, while, read enz.) mag je ook het externe commando sort gebruiken. Om
problemen te vermijden, schrijf je bij het testen de kill-opdracht uit naar
standaarduitvoer i.p.v. deze daadwerkelijk uit te voeren.
END

if (($#==0)); then
    ps -e | awk '{print $4}' | sort | uniq
else
    ps -e | awk '{print $1, $4}' | while read -r pid command; do
        for arg in "$@"; do
            if [[ $command == *$arg* ]]; then
                echo "kill -KILL $pid"
            fi
        done
    done
fi