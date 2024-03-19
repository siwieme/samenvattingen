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

* Volgorde van brace expansion bij `echo ~{root, mail}/`:
    * Eerst komt hij de brace expansion tegen, dan pas de tilde expansion
    * `echo ~{root, mail}/` is hetzelfde als `echo ~root/ ~mail/`

* ```bash
    var=7
    echo {0..$var} # toont "{0..7}"
    eval echo {0..$var} # toont "0 1 2 3 4 5 6 7"
    ```

## Redirection, piping, filtering, process substitution en het commando find

* 1 invoerkanaal (stdin), 2 uitvoerkanalen (stdout en stderr)
    * cout/stdout (1): standaarduitvoer, gebufferd (line buffered)
    * cerr/stderr (2): standaardfoutuitvoer, ongebufferd

* Line buffered: buffer wordt geleegd bij een nieuwe lijn

* Programma
```c
#include <stdio.h>

int main() {
    printf("Hello ");
    fprintf(stderr, "Fooooooouuuuuuutttttt!");
    printf("world!");
    return 0;
}
``` 
* Uitvoer
    * `./a.out`: "Fooouuuuuuutttttt!Hello world!"
    * Eerst ongebufferde uitvoer, dan gebufferde uitvoer

* Commando `du`: toont de grootte van bestanden en mappen
    * `du -h <map>`: toont de grootte van bestanden en mappen in een map
    * `du -h <bestand>`: toont de grootte van een bestand
    * `du <bestand> > <bestand2>`: schrijft de grootte van bestand naar bestand2
    * `du <bestand> >> <bestand2>`: schrijft de grootte van bestand naar bestand2, zonder bestand2 te overschrijven
    * `du /<map> > <bestand2>`: schrijft de groottes van bestanden in map naar bestand2
    * `du /<map> >> <bestand2>`: schrijft de groottes van bestanden in map naar bestand2, zonder bestand2 te overschrijven

* Commando `du /etc > /dev/null`: toont niets, want `/dev/null` negeert alle geschreven data
    * `/dev/null`: een speciaal bestand dat alle geschreven data negeert
* Commando `cat /dev/null`: toont niets, want `/dev/null` bevat geen data

* Commando `exec 3> bestand`: opent bestand voor schrijven naar bestandsdescriptornummer 3
    * `echo "Hallo" >&3`: schrijft "Hallo" naar bestand
    * `exec 3>&-`: sluit bestand

* Commando `strace 2>&1 ls -l | less`: toont de systeemaanroepen van het commando `ls -l` in `less`
    * `2>&1`: stderr wordt omgeleid naar stdout (zorgt ervoor dat ongebufferde uitvoer gebufferd wordt)
    * `|`: pipe
    * 2 processen:
        * `strace 2>&1 ls -l`: stderr wordt omgeleid naar stdout
        * `less`: toont de uitvoer van `strace 2>&1 ls -l`
        * Gescheiden door pipe

* Commando `du /etc > tmp.txt 2>&1`: schrijft de grootte van bestanden in `/etc` naar `tmp.txt`
    * `du /etc`: toont de grootte van bestanden in `/etc`
        * 1 -> stdout (buffered) (scherm)
        * 2 -> stderr (unbuffered) (scherm)
    * `> tmp.txt`: schrijft naar `tmp.txt`
    * `2>&1`: stderr wordt omgeleid naar stdout (zorgt ervoor dat ongebufferde uitvoer gebufferd wordt)

* Commando `du /etc 2>&1 1 > tmp.txt`:
    * `du /etc`: toont de grootte van bestanden in `/etc`
        * 1 -> stdout (buffered) (console)
        * 2 -> stderr (unbuffered) (console)
    * `2>&1`: stderr wordt omgeleid naar stdout (zorgt ervoor dat ongebufferde uitvoer gebufferd wordt)
        * 1 -> stdout (console)
        * 2 -> stdout (buffered) (console) 
    * `1 > tmp.txt`: schrijft naar `tmp.txt`

* Commando `exec 3> bestand`: creeërt een bestanddescriptornummer 3 voor schrijven naar bestand

* Commando `du /etc; du /var`: toont de grootte van bestanden in `/etc` en `/var`
    * `;`: sequentiële uitvoering

* Commando `du /etc; du /var > tmp.txt`: toont de grootte van bestanden in `/etc` en schrijft de grootte van bestanden in `/var` naar `tmp.txt`
    * `;`: sequentiële uitvoering
    * `>`: schrijft naar `tmp.txt`

* Commando `( du /etc; du /var; ) > tmp.txt`: schrijft de grootte van bestanden in `/etc` en `/var` naar `tmp.txt`
    * `()`: zorgt er voor dat de commando's binnen de haakjes in een kindproces van de huidige shell uitgevoerd worden
    * `;`: sequentiële uitvoering
    * `>`: schrijft naar `tmp.txt`

* Commando `{ du /etc; du /var; } > tmp.txt`: schrijft de grootte van bestanden in `/etc` en `/var` naar `tmp.txt`
    * `{}`: zorgt er voor dat de commando's binnen de accolades in de huidige shell uitgevoerd worden
    * `;`: sequentiële uitvoering
    * `>`: schrijft naar `tmp.txt`

* Commando `exec 10&-`: sluit bestandsdescriptornummer 

## Process substitution

* Foutboodschappen naar het standaarfoutkanaal sturen:
    * `echo "Foutboodschap" 1>&2`
    * `echo "Foutboodschap" >&2`

* Het aantal foutmeldingen opvragen bij `du /proc`:
    * `du /proc 2>&1 > /dev/null | wc -l`
        * `2>&1`: stderr wordt omgeleid naar stdout (gebufferd)
        * `> /dev/null`: schrijft naar `/dev/null`
        * `| wc -l`: telt het aantal regels

* Commando `head -n 3 /etc/passwd | tail -n 1`: toont de derde lijn van `/etc/passwd`
    * `head -n 3 /etc/passwd`: toont de eerste 3 lijnen van `/etc/passwd`
    * `tail -n 1`: toont de laatste lijn van de uitvoer van `head -n 3 /etc/passwd`

* Commando `head -n 3 /etc/passwd | tail -n 1 | head -c 3 | tail -c 1`: toont het derde karakter van de derde lijn van `/etc/passwd`
    * `head -n 3 /etc/passwd`: toont de eerste 3 lijnen van `/etc/passwd`
    * `tail -n 1`: toont de laatste lijn van de uitvoer van `head -n 3 /etc/passwd`
    * `head -c 3`: toont de eerste 3 karakters van de uitvoer van `tail -n 1`
    * `tail -c 1`: toont het laatste karakter van de uitvoer van `head -c 3`

* Met behulp van de eenvoudige opdracht dos2unix kun je de `<CR><LF>`-sequenties in een bestand dat door een Windowstoepassing is aangemaakt, vervangen door enkele `<LF>`- lijnscheidingstekens, zoals dit op UNIX verwacht wordt. Hoe kun je met behulp van de tr opdracht hetzelfde effect bereiken? Welke zijn de nadelen van deze benadering?
     * `tr -d '\r' < bestand > bestand2`: vervangt de `<CR>`-sequenties door `<LF>`-lijnscheidingstekens
     * Niet lezen en schrijven naar hetzelfde bestand
     * Geen bestandsnaam meegeven als parameter, enkel in- en outputredirectie
     * Nog even volgen door `mv bestand2 bestand`ba

* Commando `uniq -d bestand`: toont de dubbele regels in bestand
    * Kijkt dus enkel naar de opeenvolgende regels
    * Best eerst sorteren met `sort` om alle dubbele regels te vinden
    * `sort bestand | uniq -d`
    * `uniq -d < (sort bestand)`

* In het bestand /etc/passwd worden de velden gescheiden door een :-teken. Het eerste veld bevat de gebruikersnaam en het derde veld het gebruikersID, terwijl het vierde veld het nummer van de primaire groep is waartoe de gebruiker behoort. Sorteer het passwd-bestand met behulp van het sort commando, met het nummer van de primaire groep als sleutel. Zorg ervoor dat het sort commando enkel sorteert op het veld met de primaire groep (en niet op het restant van de lijn), en dit veld alfabetisch (niet-numeriek) sorteert. Bij deze sortering moet bijvoorbeeld gelden: 1 < 100 < 12. Geef de volledige commandolijn waarmee je deze opdracht hebt uitgevoerd. Voer dit commando vervolgens uit, waarbij je de uitvoer omleidt naar het bestand ~/passwd. Doe nu hetzelfde met het group-bestand. Dit bestand bevat onder meer als eerste veld de groepsnaam, terwijl het nummer van de groep nu in het derde veld staat. Sorteer opnieuw volgens dezelfde criteria, met het nummer van de groep als sleutel. Leid de uitvoer nu om naar het bestand ~/group.
    * `sort -t : -k 4,4 /etc/passwd > ~/passwd`
    * `sort -t : -k 3,3 /etc/group > ~/group`
    * Wat als het vierde veld gelijk is? Dan sorteren op het eerste veld?
        * `sort -t : -k4n,4n -k1,1 /etc/passwd > ~/passwd`

* Commando `cut -d : -f 1,3 /etc/passwd`: toont de eerste en derde velden van `/etc/passwd`
    * `-d :`: veldseparator is `:`
    * `-f 1,3`: toont de eerste en derde velden

* Sorteer het /etc/passwd bestand, met behulp van het sort commando. Gebruik als primaire sleutel het vierde veld van het bestand. Zorg ervoor dat je in numerieke volgorde sorteert (12 < 100). Regels met gelijke numerieke waarden voor het vierde veld moeten gesorteerd worden met het vijfde veld als secundaire sleutel, waarbij geen onderscheid mag gemaakt worden tussen hoofdletters en kleine letters, en voor de sorteervolgorde nu de omgekeerd alfabetische volgorde moet genomen worden. Geef de volledige commandolijn waarmee je deze opdracht hebt uitgevoerd
    * `sort -t : -k 4,4n -k 5,5fr /etc/passwd`

* Commando `find`: 
    * `find <map> -name <patroon>`: zoekt bestanden in een map met een bepaald patroon
    * `find` : toont alle bestanden in de huidige map
    * Attribuut `-type`:
        * `f`: gewoon bestand
        * `d`: map
        * `l`: symbolische link
    * Zoek alle bestanden in een map die beginnen met "pass":
        * `find /etc -type f -name "pass*"`
    * Attribuut `printf`:
        * `%p`: volledig pad
        * `%y`: bestandstype
        * `%s`: bestandsgrootte
        * `%Tc`: datum van laatste wijziging
    
* Geef alle bestanden in /usr die groter zijn dan 1MB, sorteer ze numeriek op grootte en toon enkel de naam van het bestand:
    * `find /usr -type f -size +1M -printf "%s %p\n" | sort -t " " -k1,1n | cut -d " " -f2`
        * `find /usr -type f -size +1M -printf "%s %p\n"` : toont alle bestanden in /usr die groter zijn dan 1MB
        * `sort -t " " -k1,1n`: sorteert de bestanden numeriek op grootte
        * `cut -d " " -f2`: toont enkel de naam van het bestand
        * Alles doorpipen

* Gebruik het find-commando om een lijst te bekomen van alle bestanden in je persoonlijke map, die gedurende de laatste twee weken gewijzigd werden. Bij het uitprinten (één lijn per bestand) moet je het volledig pad van de gevonden bestanden laten voorafgaan door het tijdstip van de laatste wijziging. Geef de volledige commandolijn waarmee je deze opdracht hebt uitgevoerd. Let er ook op dat je enkel bestanden in de lijst opneemt en geen directory's.
    * `find ~ -type f -mtime -$((14*24)) -printf "%Tc %p\n"`
    * `find ~ -type f -mtime -$((14*24)) -printf "%t %p\n"`
    * Voor werwerking: `find ~ -type f -mtime -$((14*24)) -printf "%t:%p\n"`

*  Gebruik het find-commando om een lijst te bekomen van alle subdirectory's van /usr waarin zich C- of C++-headerbestanden (bestanden met suffix .h) bevinden. Gebruik een commandolijn van de gedaante Gebruik het find-commando om een lijst te bekomen van alle subdirectory's van /usr waarin zich C- of C++-headerbestanden (bestanden met suffix .h) bevinden. Gebruik een commandolijn van de gedaante "find ... | sort | uniq"
    * `find /usr -type f -name "*.h" -printf "%h\n" | sort | uniq -d`
        * `find /usr -type f -name "*.h" -printf "%h\n"`: toont alle subdirectory's van /usr waarin zich C- of C++-headerbestanden bevinden
        * `sort`: sorteert de uitvoer
        * `uniq -d`: toont enkel de dubbele regels
    * Indien we het toch met een andere commando willen doen:
        * `find /usr -type f -name "*.h" -exec ls -l {} \;`

* Commando `find /etc -name "pass*" -exec ln -s {} \;`: maakt een symbolische link naar alle bestanden in /etc die beginnen met "pass"

## Shellvariabelen

* Definieer een eigen variabele
    * `variabele=waarde`
    * `echo $variabele`: toont de waarde van variabele
    * `echo ${variabele}`: toont de waarde van variabele
    * `echo $(variabele)`: toont de waarde van variabele in een subshell (dus niets want variabele is uniek voor de huidige shell)
* Voorbeeld
    * `een=M7`
    * `twee="een"`
    * `echo $een`: toont "M7"
    * `echo $twee`: toont "een"
    * `echo ${!een}`: toont "M7"
    * `echo ${!twee}`: toont "M7"
    * `eval echo \$$twee`: toont "M7" (evalueert eerst de waarde van $twee, en dan de waarde van $een, oude versie van shell)

*  Bekijk de inhoud van de shellvariabelen PS1, PS2, SHLVL, RANDOM, SECONDS en PWD, en zoek de betekenis ervan op in info bash of man bash, sectie Shell Variables. Vraag de inhoud van deze variabelen eerst interactief op (met echo) en schrijf vervolgens een script om de inhoud van deze variabelen op het scherm te tonen. Kan je de verschillen verklaren?
    * `echo $PS1`: toont de waarde van PS1
    * `echo $PS2`: toont de waarde van PS2
    * `echo $SHLVL`: toont de waarde van SHLVL
    * `echo $RANDOM`: toont de waarde van RANDOM
    * `echo $SECONDS`: toont de waarde van SECONDS
    * `echo $PWD`: toont de waarde van PWD
    * `echo $PS1 $PS2 $SHLVL $RANDOM $SECONDS $PWD`: toont de waarde van PS1, PS2, SHLVL, RANDOM, SECONDS en PWD
    * `echo $PS1; echo $PS2; echo $SHLVL; echo $RANDOM; echo $SECONDS; echo $PWD`: toont de waarde van PS1, PS2, SHLVL, RANDOM, SECONDS en PWD elk op een nieuwe lijn

* Hoe commentaar toevoegen in een script:
    * `#`: commentaar op één lijn
    * `: << COMMENT`: commentaar op meerdere lijnen tot aan `COMMENT`

*  Hoe kun je de variabele PATH zodanig wijzigen dat je bij het aanroepen van een shellscript (dat zich in de actieve directory bevindt), niet steeds naar de actieve directory moet verwijzen? Zorg ervoor dat je oplossing werkt in eender welke directory. Het script moet dus steeds gezocht worden in de werkdirectory, zonder telkens de waarde van PATH aan te passen.
    * `export PATH=$PATH:.`
    * `export PATH=$PATH:$(pwd)`

* Hoe kun je ervoor zorgen dat wanneer bij de cd-opdracht een relatieve padnaam (dus niet beginnend met /) als argument opgegeven wordt, niet alleen de huidige werkdirectory als prefix uitgeprobeerd wordt, maar ook een aantal vaste directory's?
    * `export CDPATH=.:$HOME:/usr/local`

* Hoe kun je met eenzelfde opdracht regelmatig heen en terug schakelen tussen twee mappen als actieve directory?
    * `cd -`

* Je kunt met het commando read tegelijkertijd meerdere variabelen inlezen via het standaard invoerkanaal. Test dit uit met: read a b c d. Kan je dit aanpassen zodat de gegevens uit een bestand gelezen worden? Probeer dit ook eens met een script op te lossen, en merk op dat de variabelen enkel in het script bestaan!
    * `read a b c d < bestand`
    * `read a b c d < <(cat bestand)`

* Inputstreamseperator veranderen:
    * `IFS=:`: verandert de inputstreamseperator naar `:`
    * `read a b c d`: leest de eerste 4 velden van een lijn in, gescheiden door `:`

* Waarom werkt `. ls` niet?
  * Er is geen kindproces