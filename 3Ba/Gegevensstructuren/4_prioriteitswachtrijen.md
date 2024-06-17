# Prioriteitswachtrijen

* Het gegeven met de hoogste prioriteit uit de wachtrij halen
* Volgende operaties zijn ondersteund:
    * Toevoegen
    * Verwijderen
    * Testen of ledig
* Twee implementaties liggen voor de hand:
    * Gerangschikte tabel:
        * Toevoegen: O(n)
        * Verwijderen: O(1)
    * Ongeordende tabel:
        * Toevoegen: O(1)
        * Verwijderen: O(n)
        * Handig voor toepassingen waar vaker toegevoegd wordt dan verwijderd
    * Compromis tussen deze twee: (binaire) heap:
        * Toevoegen & verwijderen: O(lg(n))

## Heap

* Boomstructuur
* Kan efficiënt in een tabel opgeslagen worden
* Elementen een betere structuur opleggen
    * Maximum (of minimum) van de gegevens snel te vinden
* Complete binaire boom, voldoet aan heap-voorwaarden:
    * Alle niveau's volledig gevuld
    * Alle knopen hebben twee kinderen
        * Behalve eventueel het laatste
        * Hoogstens één knoop met slechts één kind
    * Stijgende heap:
        * Sleutel ouder minstens zo groot als sleutel(s) bij kind(eren)
* Eenvoudig verband tussen het aantal knopen *n* en zijn hoogte *h*
* Op een volledig gevuld niveau: $2^i$ knopen
* Volledig opgevulde binaire boom van hoogte *h* heeft 2^(h+1)-1 knopen
* Laatste niveau niet volledig gevuld, daardoor: $h=lg(n)$

* Nummering
    * Wortel op plaats 0
        * Diens kinderen op
            * 1
                * Diens kinderen op
                    * 3
                    * 4
            * 2
                * Diens kinderen op
                    * 5
                    * 6
    * Zo verder...
    * Formule
        * Knoop: $0 <= n < i$
        * Ouder: $(i-1)/2$
        * Kinderen $2i+1$ en $2i+2$

### Bewerkingen op heaps

#### Element Toevoegen

* Voeg een nieuw element *g* toe aan een bestaande heap met *n* knopen.
* Creëer een nieuwe knoop op het laagste niveau (tabelindex *n+1*).
* Houd de nieuwe knoop voorlopig vrij.
* Zolang de vrije knoop een ouder heeft en *g* groter is dan het ouderelement, schuif het ouderelement naar beneden in de vrije knoop.
* Wanneer de vrije knoop geen ouder meer heeft of *g* niet groter is dan het ouderelement, sla *g* op in de vrije knoop.
* De langste weg die moet worden afgelegd, is niet groter dan de hoogte van de heap.
* Toevoegen is dus *O(lg n)*.

#### Wortelelement Vervangen

* Vervang het wortelelement van een heap door een nieuw element *g*.
* Houd de wortel voorlopig vrij.
* Zolang de vrije knoop kinderen heeft en *g* kleiner is dan een kindelement, schuif het grootste kindelement naar boven in de vrije knoop.
* Wanneer de vrije knoop geen kinderen meer heeft of *g* groter is dan de kindelementen, sla *g* op in de vrije knoop.
* De weg naar beneden is ingewikkelder dan bij toevoegen, maar de langste weg blijft gelijk aan de hoogte van de heap.
* Deze operatie is ook *O(lg n)*.

#### Wortelelement Verwijderen

* Verwijder het wortelelement van de heap.
* De heap wordt kleiner, en om een complete binaire boom te behouden, moet de knoop met index *n* verdwijnen.
* Het element van die knoop komt voorlopig op de vacante plaats bij de wortel.
* Dit komt neer op het vervangen van het wortelelement.
* Deze operatie is *O(lg n)*.

#### Element van Willekeurige Knoop Vervangen

* Vervang het element van een willekeurige knoop.
* Als het nieuwe element groter is dan het oude, verstoor het enkel de heapvoorwaarde op de weg naar de wortel.
  * Oplossing: analoog aan toevoegen van een element, maar beginnend bij de betrokken knoop.
* Als het nieuwe element kleiner is dan het oude, verstoor het enkel de heapvoorwaarde in de deelheap waarvan die knoop wortel is.
  * Oplossing: analoog aan het vervangen van het wortelelement van de volledige heap, maar nu enkel toegepast op de betrokken deelheap.
* De afgelegde weg is niet langer dan de hoogte van de volledige heap.
* Deze operatie is ook *O(lg n)*.

### Constructie van een Heap

## Constructie van een Heap

#### Door Toevoegen

* Een heap kan worden opgebouwd door de elementen een voor een toe te voegen aan een oorspronkelijk ledige heap.
* De heaptabel hoeft niet oorspronkelijk ledig te zijn; een ingevulde tabel kan ter plaatse getransformeerd worden tot een heap.
* Een nieuw element kan toegevoegd worden aan de bestaande heap door het tijdelijk uit de tabel te halen.
* Deze heapconstructie vereist *n - 1* keer toevoegen, en de performantie van toevoegen wordt begrensd door de hoogte van de (groeiende) heap.
* Het toegevoegde element moet mogelijk helemaal tot boven in de (voorlopige) heap stijgen.
* De uitvoeringstijd is maximaal gegeven door: 

  $(T(n) \leq 2 \cdot (2^1 - 1) + 4 \cdot (2^2 - 1) + 8 \cdot (2^3 - 1) + \ldots + 2h^{2} + 2h^{2 - 1} + 2h^{1})$

  Vereenvoudigd wordt dit $(T(n) \leq 2n \lg n)$, zodat het opbouwen van een heap in het slechtste geval $(O(n \lg n))$ wordt.

#### Door Samenvoegen van Deelheaps

* Een efficiëntere methode bouwt de heap van onder naar boven op door deelheaps samen te voegen (Floyd, 1964).
* Samenvoegen van deelheaps betekent een knoop waarvan beide deelbomen reeds deelheaps zijn, tot wortel maken van een grotere deelheap.
* Alleen het wortelelement kan de heapvoorwaarde verstoren, en deze moet alleen gelden in de nieuwe deelheap.
* Beginnend bij het voorlaatste niveau, waar knopen met kinderen worden behandeld, en werkend van rechts naar links, kunnen deelheaps samengevoegd worden.
* Het totale werk om de heap op te bouwen, gegeven een complete binaire boom met hoogte \(h\), wordt gegeven door:

  $(T(n) = \sum_{i=0}^{h} 2^{i}(h - i))$

* Vereenvoudigd wordt $(T(n) = -h + \sum_{i=1}^{h} 2^{i} = -h - 1 + 2(h + 1) - 1)$.
* Met $(h = \lg n)$ is $(T(n) = O(n))$, wat aantoont dat een heap in lineaire tijd opgebouwd kan worden.

## Samenvoegbare Heaps

### Prioriteitswachtrij en Heapimplementaties

* Standaardoperaties ondersteund door een prioriteitswachtrij:
    * Toevoegen
    * Minimum (element met hoogste prioriteit) verwijderen
    * Testen of de prioriteitswachtrij ledig is
* Bijkomende operaties op een willekeurig element mogelijk, zoals:
    * Prioriteit verminderen
    * Verwijderen (na lokaliseren van het element)
* Sommige algoritmen vereisen samenvoegen van twee prioriteitswachtrijen.

### Implementatie van een Prioriteitswachtrij

* Gebruikelijke implementatie: Binaire heap (of d-heap), opgeslagen in een tabel.
* Performantie van operaties (behalve samenvoegen) is O(lg n).
* Samenvoegen is O(n), omdat een van de tabellen moet worden gekopieerd.

### Alternatieve Heapimplementaties

#### Leftist Heaps

* Binaire bomen met de heapvoorwaarde.
* Niet compleet, trachten onevenwichtig te zijn.
* Operaties zijn efficiënt door werk voornamelijk in de rechterkant te laten gebeuren.
* Constructie uit n elementen: O(n).

#### Skew Heaps

* Zelforganiserende versies van leftist heaps.
* Binaire bomen zonder vormbeperkingen.
* Operaties in het slechtste geval O(n), maar geamortiseerde efficiëntie is O(lg n).

#### Binomial Queues

* Bestaan uit een bos van binomiaalbomen.
* Samenvoegen, toevoegen, minimum verwijderen: O(lg n) in het slechtste geval.
* Geamortiseerd is toevoegen O(1).
* Ondersteunt bijkomende operaties op een willekeurig element.

#### Fibonacci Heaps

* Veralgemening van binomial queues.
* 'Lazy merging' van binomiaalbomen.
* Performantie: O(1) voor samenvoegen, toevoegen, en prioriteit verminderen.
* Minimum verwijderen: O(lg n) geamortiseerd.

#### Pairing Heaps

* Zelforganiserende, gestroomlijnde versie van een binomial queue.
* Sneller voor verminderen van de prioriteit.
* Geamortiseerde performantie: O(lg n) voor samenvoegen, toevoegen, minimum verwijderen, en prioriteit verminderen.

#### Relaxed Heaps

* Veralgemeningsvarianten van binomial queues.
* 'Rank-relaxed heap' vergelijkbaar met Fibonacci heap.
* 'Run-relaxed heap' laat overtredingen van de heapvoorwaarde toe, met performantie in het slechtste geval.

## Binbomial Queues

Bij leftist en skew heaps zijn de basisoperaties samenvoegen, toevoegen, en het minimum verwijderen allemaal O(lg n). Bij binaire heaps is toevoegen gemiddeld O(1). De vraag is of een heap die samenvoegen toelaat ook O(1) performantie voor toevoegen kan behalen.

### Structuur van Binomial Queue

* Binomial queue (Vuillemin, 1978) bestaat uit een bos van binomiaalbomen met de heapvoorwaarde.
* Binomiaalboom Bh met hoogte h bestaat uit een wortel en twee Bh-1 bomen als kinderen.
* Binomiaalboom Bh heeft 2h knopen.
* Een prioriteitswachtrij kan worden voorgesteld door een bos binomiaalbomen, elk met hoogte overeenkomstig een macht van 2.

### Operaties

* **Minimum Vinden:**
    * Alle wortels van bomen overlopen, O(lg n).
    * Met bijhouden van de plaats van het minimum kan het worden gereduceerd tot O(1).

* **Samenvoegen:**
    * Bomen van dezelfde hoogte worden bij elkaar opgeteld.
    * O(1) per binomiaalboom, omdat ze gerangschikt zijn op hoogte.
    * O(lg n) voor het samenvoegen van twee binomial queues.

* **Toevoegen:**
    * Speciaal geval van samenvoegen: een knoop met het toe te voegen element wordt een triviale binomial queue.
    * Performantie: O(lg n).
    * Geamortiseerd O(1) voor n toevoegoperaties op een ledige binomial heap.

* **Minimum Verwijderen:**
    * Zoek de binomiaalboom Bk met het kleinste wortelelement.
    * Verwijder Bk en verwijder de wortel in Bk.
    * Performantie: O(lg n).

* **Bijkomende Operaties:**
    * Prioriteit verminderen: O(lg n).
    * Verwijderen (combinatie van prioriteit verminderen en minimum verwijderen): O(lg n).

### Implementatie

* Binomial queue wordt voorgesteld als een tabel van binomiaalbomen.
* Binomiaalbomen gebruiken standaard binaire boomvoorstelling met wijzers naar linkerkind en rechterbroer.
* Gelinkte lijst van kinderen is gerangschikt op dalend aantal knopen voor eenvoudiger samenvoegen van binomiaalbomen.

## Pairing Heaps

Een pairing heap is een algemene boom waarvan de sleutels voldoen aan de heapvoorwaarde. Voor de boom gebruikt men de standaard binaire boomvoorstelling: elke knoop bevat een wijzer naar zijn linkerkind, en een naar zijn rechterbroer. Wanneer verminderen van de prioriteit moet ondersteund worden, heeft elke knoop een extra wijzer nodig: een linkerkind naar zijn ouder, een rechterbroer naar zijn linkerbroer. (We blijven echter de terminologie van de algemene boom gebruiken.)

### Operaties

* **Samenvoegen:**
    * Vergelijkt de wortelelementen van beide heaps.
    * De wortel met het grootste element wordt het linkerkind van de wortel met het kleinste element.
    * Waarom het linkerkind? (niet verder gespecificeerd)

* **Toevoegen:**
    * Speciaal geval van samenvoegen.
    * Geeft een wijzer terug naar de nieuwe knoop, die later kan gebruikt worden als de prioriteit van die knoop moet verminderen.

* **Prioriteit Verminderen:**
    * Wanneer men de prioriteit van een (gelokaliseerde) knoop vermindert, wordt nagegaan of de heapvoorwaarde ten opzichte van de ouder (als die bestaat) nog steeds voldaan is.
    * De knoop wordt losgekoppeld van zijn ouder en wordt de wortel van een nieuwe heap.
    * Deze wordt samengevoegd met de oorspronkelijke (gewijzigde) heap.

* **Minimum Verwijderen:**
    * Verwijder de wortel, wat een collectie van c heaps oplevert.
    * Daaruit kan een nieuwe heap gemaakt worden door c - 1 keer samen te voegen.
    * In het slechtste geval is deze operatie O(n), omdat c = O(n).
    * Door echter de volgorde van samenvoegen zorgvuldig te kiezen, kan men een geamortiseerde performantie van O(lg n) bekomen.

* **Willekeurige Knoop Verwijderen:**
    * Knoop loskoppelen van zijn ouder, zodat hij wortel wordt van een nieuwe heap.
    * Het minimum van die nieuwe heap wordt verwijderd, en de rest van die heap wordt samengevoegd met de oorspronkelijke (gewijzigde) heap.

### Performantie

* De geamortiseerde performantie van de operaties is meestal O(lg n).
* Het verwijderen van het minimum kan geamortiseerd O(lg n) zijn als de volgorde van samenvoegen zorgvuldig wordt gekozen.

## Toepassing: Discrete Event Simulation

Prioriteitswachtrijen spelen een cruciale rol in **Discrete Event Simulation (DES)**
* Een methode voor het simuleren van systemen waarin processen onafhankelijk verlopen maar op bepaalde punten interageren
* Een typisch voorbeeld is een productiesysteem met verschillende machines die individuele werkstukken verwerken
    * De simulatie helpt bij het nemen van beslissingen
    * Zoals het aanschaffen van extra machines en het implementeren van efficiënte beleidsstrategieën

## Discrete Event Simulation (DES)

* **Werkingsprincipe:** DES werkt met discrete gebeurtenissen die plaatsvinden op specifieke momenten in de tijd.
* **Prioriteitswachtrij:** Gebeurtenissen worden afgehandeld via een prioriteitswachtrij, waarbij de hoogste prioriteit wordt bepaald door het vroegste tijdstip.
* **Simulatieprocedure:** De simulatie begint met gebeurtenissen die onafhankelijk zijn van andere.
* **Oplossen van conflicten:** Problemen met gelijktijdige gebeurtenissen worden opgelost door enigszins verschillende prioriteiten toe te kennen.