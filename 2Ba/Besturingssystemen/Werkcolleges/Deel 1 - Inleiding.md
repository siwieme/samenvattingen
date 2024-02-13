# Deel 1 - Inleiding

## Terminal

* Runnend programma onderbreken: `Ctrl + C`
* Runnend programma pauzeren: `Ctrl + Z`
* Runnend programma hervatten: `fg 1` of `bg 1`
* Toetsencombinatie om invoer te stoppen: `Ctrl + D`
* Toetsencombinatie om laatste woord te verwijderen: `Ctrl + W`
* Automatisch aanvullen van commando's: `Tab`
    * Geldt ook voor opties en bestandsnamen

## Eenvoudige opdrachten

* `man <commando>`: toont de handleiding van een commando
* `-i` optie: maakt commando's hoofdletterongevoelig
* `strace <commando>`: toont systeemaanroepen van een commando
    * `2>&1`: stuurt foutmeldingen naar standaarduitvoer
* `printf "<tekst>"`: toont tekst op het scherm
* `help read`: toont de handleiding van de `read`-opdracht in plaats van `man read`
* `help read | less`: toont de handleiding van de `read`-opdracht in een paginaweergave
* `ls`: toont de inhoud van de huidige map
    * `-l` optie: toont de inhoud van de huidige map in een lijst
    * `-h` optie: toont de grootte van bestanden in een leesbare vorm
    * Bij color=auto: directories zijn blauw, uitvoerbare bestanden zijn groen
    * Kleurloos: `ls --color=never`
* `cd <map>`: verandert de huidige map
    * `cd -`: verandert de huidige map naar de vorige map
    * `cd`: verandert de huidige map naar de thuismap
* `mkdir <map>`: maakt een nieuwe map
* `cp <bestand> <map>`: kopieert een bestand naar een map
    * `-i` optie: vraagt bevestiging voor het overschrijven van bestanden
    * `-r` optie: kopieert mappen en hun inhoud
* `mv <bestand> <map>`: verplaatst een bestand naar een map
    * `-i` optie: vraagt bevestiging voor het overschrijven van bestanden

### Aliassen

* `alias`: toont alle aliassen
* Opsomming:
    * `alias ..='cd ..'`
    * `alias ...='cd ../..'`
    * `alias cp='cp -i'`
    * `alias egrep='egrep --color=auto'`
    * `alias fgrep='fgrep --color=auto'`
    * `alias grep='grep --color=auto'`
    * `alias la='ls -a'`
    * `alias l='ls -CF'`
    * `alias ll='ls -l'`
    * `alias mv='mv -i'`
    * `alias rm='rm -i'`
    * Nog veel meer...