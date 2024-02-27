# Deel IV - Programmeren in Bash

* Vlug een aantal (lege) bestanden aanmaken:
    * `touch <bestand>`: maakt een bestand aan
    * `touch <bestand1> <bestand2> ...`: maakt meerdere bestanden aan
    * `mkdir <map>`: maakt een map aan

* Commando `head /etc/passwd`:
    * `head <bestand>`: toont de eerste 10 lijnen van een bestand
    * `head -n <aantal> <bestand>`: toont de eerste `<aantal>` lijnen van een bestand

* Commando `tail /etc/passwd`:
    * `tail <bestand>`: toont de laatste 10 lijnen van een bestand
    * `tail -n <aantal> <bestand>`: toont de laatste `<aantal>` lijnen van een bestand

* Commando `rm <bestand>`:
    * `rm <bestand>`: verwijdert een bestand
    * `rm -r <map>`: verwijdert een map en al zijn inhoud
    * `rm -f <bestand>`: forceert het verwijderen van een bestand
    * `rm -rf <bestand>`: forceert het verwijderen van een map en al zijn inhoud
    * Bestand met naam "-rf" verwijderen: `rm -- -rf`

* Commando `wc`:
    * `wc <bestand>`: toont het aantal regels, woorden en karakters in een bestand
    * `wc -l <bestand>`: toont het aantal regels in een bestand
    * `wc -w <bestand>`: toont het aantal woorden in een bestand
    * `wc -c <bestand>`: toont het aantal karakters in een bestand
    * `wc -c < <bestand>`: toont het aantal karakters in een bestand zonder de bestandsnaam

* Commando `man builtin`: toont de handleiding van een ingebouwd commando
    * `cp`: kopieert bestanden
    * `dd`: kopieert en converteert bestanden
    * `ln`: maakt een harde of symbolische link
    * `mktemp`: maakt een tijdelijk bestand of map, met unieke naam binnen een directory
        * Aantal letters in de naam van een tijdelijk bestand: `mktemp XXXXX`
    * `cd`: verander van map
    * `pwd`: toont de huidige map
    * `set`: toont de waarden van alle variabelen	
    * `exec`: voert een commando uit in de huidige shell
    * `printf`: toont een opgemaakte string
    * `:`: doet niets

* Commando `sync`: buffers flushen naar schijf

* Afbeelding maken van een USB-pen:
    * `dd if=/dev/sdb of=usb.img`: maakt een afbeelding van een USB-pen
    * `dd if=usb.img of=/dev/sdb`: schrijft een afbeelding naar een USB-pen

* Commando `dd`:
    * `dd if=<bestand> of=<bestand>`: kopieert een bestand
    * `dd if=<bestand> of=<bestand> bs=<blokgrootte>`: kopieert een bestand met een bepaalde blokgrootte
    * `dd if=<bestand> of=<bestand> bs=<blokgrootte> count=<aantal>`: kopieert een bestand met een bepaalde blokgrootte en een bepaald aantal blokken

* Commando `head`:
    * `head -c <aantal> <bestand> > <bestand2>` : door middel van output redirection kan je een bepaald aantal karakters van een bestand naar een ander bestand schrijven

* Commando `find`:
    * `find <map> -name <patroon>`: zoekt bestanden in een map met een bepaald patroon
    * `find` : toont alle bestanden in de huidige map 
    * `find . -mtime -1`: toont bestanden die de afgelopen 24 uur werden aangepast

* Commando `fdisk -l`: toont de partities van een schijf
    * `fdisk -l /dev/sda`: toont de partities van schijf `/dev/sda`

* Commando `wodim`:
    * `wodim -v -eject -data <bestand>`: brandt een bestand op een CD
    * `wodim -v -eject -data <bestand> dev=/dev/sr0`: brandt een bestand op een CD in de CD/DVD-brander `/dev/sr0`	

* Commando `genisoimage`:
    * `genisoimage -o <bestand>.iso <map>`: maakt een ISO-bestand van een map
    * `genisoimage -o <bestand>.iso -J <map>`: maakt een ISO-bestand van een map met Joliet-uitbreiding
    * `genisoimage -o root.iso -J /root`: maakt een ISO-bestand van de map `/root` met Joliet-uitbreiding
    * Joliet: vermijdt naamsveranderingen van bestanden bij het branden van een CD/DVD/image

## Patterns, expansions en het opzoeken van hulp

## Pathname expansion

* Commando `dir a*`: toont alle bestanden die beginnen met een "a"
* Commando `dir *a`: toont alle bestanden die eindigen met een "a"
* Commando `dir *a*`: toont alle bestanden die een "a" bevatten
* Commando `dir a?`: toont alle bestanden die beginnen met een "a" en gevolgd worden door één karakter
* Commando `dir a\*`: toont alle bestanden die beginnen met een "a" en een "*"

* Commando `printf "%s\n" *`: toont alle bestanden in de huidige map
* Commando `printf "%s\n" [abcd]`: toont alle bestanden die beginnen met een "a", "b", "c" of "d"
* Commando `printf "%s\n" [a-d]`: toont alle bestanden die beginnen met een "a", "b", "c" of "d"
* Commando `printf "%s\n" [!abcd]`: toont alle bestanden die niet beginnen met een "a", "b", "c" of "d"

* Verschil `ls abc*` en `printf "%s\n" abc*` indien er geen bestand is dat begint met "abc":
    * `ls abc*`: toont een foutmelding
    * `printf "%s\n" abc*`: toont "abc*"

## Brace expansion

* Commando `echo <opties>`:
    * `echo {a,b,c}`: toont "a b c"
    * `echo {1..5}`: toont "1 2 3 4 5"
    * `echo {a..z}`: toont "a b c ... z"
    * `echo {a..z..2}`: toont "a c e ... y"
    * `echo M{4..7}`: toont "M4 M5 M6 M7"
* Commando `mkdir {a,b,c}`: maakt mappen "a", "b" en "c" aan
* Commando `touch {a,b,c}.txt`: maakt bestanden "a.txt", "b.txt" en "c.txt" aan
* Commando `rm {a,b,c}.txt`: verwijdert bestanden "a.txt", "b.txt" en "c.txt"
* Commando `printf "%s\n" {a,b,c}.txt`: toont "a.txt b.txt c.txt" elk op een nieuwe lijn

* Alle hexadecimale getallen kleiner dan 256 die even zijn:
    * `echo {{0..9},{a..f}}{{0..9..2},{a..f..2}}`