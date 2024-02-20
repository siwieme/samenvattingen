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

* Commando `sync`: synchroniseert het bestandssysteem met de schijf

* Afbeelding maken van een USB-pen:
    * `dd if=/dev/sdb of=usb.img`: maakt een afbeelding van een USB-pen
    * `dd if=usb.img of=/dev/sdb`: schrijft een afbeelding naar een USB-pen

* Commando `dd`:
    * `dd if=<bestand> of=<bestand>`: kopieert een bestand
    * `dd if=<bestand> of=<bestand> bs=<blokgrootte>`: kopieert een bestand met een bepaalde blokgrootte
    * `dd if=<bestand> of=<bestand> bs=<blokgrootte> count=<aantal>`: kopieert een bestand met een bepaalde blokgrootte en een bepaald aantal blokken

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
