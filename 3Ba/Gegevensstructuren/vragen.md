Van Xander:

## Wat is Amortized Efficiency?

Bij amortized efficiency gaan we de worst-case kost van een sequentie operaties gaan bekijken, in plaats van ons te focussen op de worst-case kost van één enkele operatie. We gaan dus eigenlijk een soort "gemiddelde" kost bepalen door de kost van de iets zeldzamere, minder-performante operaties te gaan verspreiden over de meer-performante operaties. Deze methode wordt vaker gebruikt als er in zeldzame gevallen een enkele operatie is die minder-performant is.

Er bestaan verschillende methodes hiervoor:
### Bankers Method
Elke efficiënte operatie zal een meerkost betalen die laterop gebruikt kan worden om de minder efficiënte operaties (die meer kosten) te gaan compenseren.
Vb: een element aan een dynamische array toevoegen kost *1*, tenzij de array vol zit, dan kost het *n*. Als we dus elk element een meerkost van *2* laten "betalen", compenseren we zo de verdubbeling, aangezien *n/2* elementen in totaal *n* moeten betalen voor de verdubbeling.

### Aggregate Method
Deze methode berekent de totale som van een sequentie van *m* operaties, om die totale som dan te delen door *m*.

### Potential Method
Volgens Google: A method implemented to analyze the amortized time and space complexity of a data structure, a measure of its performance over sequences of operations that eliminates the cost of infrequent but expensive operations.

## Wat zijn de soorten collision handling?

### Chaining

#### Seperate Chaining

Op elke locatie wordt een gelinkte lijst opgeslagen. In het slechtste geval worden alle sleutels op dezelfde locatie afgebeeld, waardoor alle data dus in deze ene gelinkte lijst komt te zitten. We streven naar ${a}$ elementen per gelinkte lijst, waarbij ${a}$ gelijk is aan ${n/m}$ met ${n}$ de hoeveelheid elementen en ${m}$ de hoeveelheid beschikbare sloten.

#### Coalesced Chaining

Elk nieuw datapunt wordt in een beschikbaar slot opgeslagen, en bewaart dan een pointer naar dat slot. Hierbij werken we met twee regio's: address & overflow. Address is voor de hashberekende index, overflow is gerbuikt in geval van een botsing. De overflow-regio wordt achterwaarts opgevuld.
 
### Open Adressing

Bereken de locatie van de index in het geval van een botsing. We ruilen de pointers dus om voor berekentijd.

#### Linear Probing

We blijven kijken naar het volgende beschikbare slot, maar dit heeft als gevolg dat dit in een zeer lange keten kan resulteren, wat de performantie niet tegoed komt.

#### Quadratic Probing

Hierbij gaan we niet langer kijken naar het volgende beschikbare slot, maar met behulp van een kwadratische vergelijking de stapgrootte berekenen. <br>
$(h(s) + c_1i + c_2i^2)$ mod $m$ waarbij $c_1$ en $c_2$ onderling priem zijn en i het aantal keer dat we een nieuwe index moeten berekenen. De constanten zijn best onderling priem, omdat anders niet de volledige tabel uitgetest zal worden.

#### Double hashing

Hierbij gebruiken we een tweede hashfunctie om de stapgrootte te gaan bepalen. Verschillende elementen zullen een verschillende stapgrootte hebben, voor eenzelfde element zal de stapgrootte steeds constant blijven. <br>
$(h(s) + ih'(s))$ mod $m$ met i het aantal keer dat we een nieuwe index moeten berekenen

## Gegeven: een bepaalde gegevensstructuur. Stel dat X nu er zou toe doen, welke structuur gebruiken we dan beter?

* Array
    * X: geheugen uitbreiden
    * Beter: dynamische array
* Gelinkte lijst
    * X: Cache efficiëntie
    * Beter: (dynamische) array
* Tree
    * X: Pointer efficiëntie
    * Beter: Threaded tree
* Binary Search Tree
    * X: extern & gebalanceerd
    * Beter: B-tree
* B-tree
    * X: geen overhead voor (null)pointers meer
    * Beter: $B^+$-tree

## Gegeven: een hashtabel. Sorteren wordt van belang. Welke boomstructuur (+ O-notatie) ligt voorhanden?

Een Binary Search Tree, aangezien deze bovenop de woordenboekoperaties ook operaties rond het sorteren van sleutels bevat. Dit kan allemaal in O(lg n) efficiëntie. Zolang we niet met extreem veel waardes zitten, valt een B- of $B^+$-tree af te raden.

## Bepaalde Tree Structuur omzetten naar array?

Van in de root beginnen tellen met *i* en dan een pre-, in- of post-order kiezen om de indexen van de kinderen te bepalen.

## bij een bepaalde tree ke iets verwijderen & toevoegen & dan tekenen hoe ie er nadien uitziet

Voorbeelden genoeg in de slides :)

## die van het laatste hoofdstuk durft tie wel keer te vragen

## Heap in Java

### Hoe toevoegen?

Eerst en vooral voegen we de toe te voegen waarde toe op de voor de hand liggende plaats. Indien een level nog niet gevuld is, vul je dit level eerst op. Indien het level gevuld is, begin je op een nieuw level uiterst links. Dan moet er gekeken worden of de Heap property voldaan is, afhankelijk van min of max heap zullen er rotaties moeten gebeuren, opdat de voorwaarden voldaan zijn.

## Geheugen?

Een heap kan opgeslagen worden in een array. Dan zal het dus een continue gegevensstructuur zijn. Knoop *i* bevindt zich op index *i*. De ouder van *i* is opgeslagen op index *(i-1)/2* en dat afronden naar omlaag. De kinderen van *i* zijn opgeslagen op indices *2i+1* en *2i+2*. Indien er geen groot genoege blok geheugen beschikbaar is, kan een heap ook met behulp van pointers opgeslagen worden, dan zal het een gelinkte gegevensstructuur zijn.

## HashMap in Java

### Hoe worden collisions afgehandeld

Met behulp van seperate chaining (gelinkte lijsten)
Op elke locatie wordt een gelinkte lijst opgeslagen. In het slechtste geval worden alle sleutels op dezelfde locatie afgebeeld, waardoor alle data dus in deze ene gelinkte lijst komt te zitten. We streven naar ${a}$ elementen per gelinkte lijst, waarbij ${a}$ gelijk is aan ${n/m}$ met ${n}$ de hoeveelheid elementen en ${m}$ de hoeveelheid beschikbare sloten.

### Hoe wordt index geoptimaliseerd berekend?

Gebruik makende van bit shifts: $index = (n - 1)$ & hash;
Dit kan aangezien de grootte van de array altijd een macht van twee zal zijn door de verdubbeling.

## Een boom

### $B$-Tree

De B-Tree is een uitbreiding van de binaire zoekboom: een externe gebalanceerde zoekboom. Om de diepte van de boom laag te houden, kan een groot aantal sleutels opgeslagen worden in elke knoop. De sleutels zitten gesorteerd. Bij een B-Tree van level *m* heeft elke interne knoop meestens *m* kinderen, minstens *m/2* (naar boven afgerond) kinderen en als een interne knoop *k+1* kinderen heeft, moet deze interne knoop *k* sleutels bezitten.

### $B^+$-Tree

Gelijkaardig aan B-trees, maar de internal nodes worden hier enkel als index om te zoeken gebruikt, alle data zit in de bladeren. De bladeren vormen een gelinkte lijst met stijgende sleutelwaardes.

### Binary Trie

Hierbij gebruiken we de bits van de hashwaarde om in de binaire boom af te dalen. De bladeren slaan referenties naar pagina's op de schijf op. Het is belangrijk te onthouden dat we moeten vermijden om schijfpagina's op te slaan met slechts enkele elementen.