# Uitwendige gegevensstructuren

## B-Trees
1. **Definitie**
   - Een B-tree van orde m, waarbij m > 2, wordt gedefinieerd als volgt:
     - Elke inwendige knoop heeft hoogstens m kinderen.
     - Elke inwendige knoop, behalve de wortel, heeft minstens dm=2e kinderen. De wortel heeft minstens twee kinderen, tenzij hij een blad is.
     - Elke inwendige knoop met k+1 kinderen bevat k sleutels. De bladeren bevatten hoogstens m􀀀1 en minstens dm=2e􀀀1 sleutels.
     - Alle bladeren bevinden zich op hetzelfde niveau.
     
2. **Eigenschappen**
   - Een B-tree is een uitwendige evenwichtige zoekboom met zeer lage hoogte.
   - De hoogte van de boom is O(logdm=2e n), waarbij m groot is.
   - Gemiddeld gebruikt een B-tree n=(mln 2) schijfpagina’s.

### Woordenboekoperaties
1. **Zoeken**
   - Zoeken gebeurt langs een weg vanuit de wortel naar een blad.
   - Elke knoop op de weg moet eerst in het geheugen ingelezen worden.
   - Het aantal schijfoperaties is O(logdm=2e n), met processortijd per knoop van O(m).

2. **Toevoegen**
   - Toevoegen gebeurt altijd aan een blad.
   - Bij overschrijding van het aantal sleutels in een blad, wordt de knoop gesplitst en de sleutel naar de ouder verplaatst.
   - In het slechtste geval worden h+1 knopen gesplitst, waarbij h de hoogte van de boom is.
   - Het totaal aantal schijfoperaties is O(logdm=2e n), met processortijd per knoop van O(m).

3. **Verwijderen**
   - Verwijderen gebeurt altijd in een blad.
   - Bij te weinig sleutels in een blad kan een sleutel worden ontleend aan de ouder, mogelijk tot aan de wortel.
   - Inwendige knopen worden zo min mogelijk gewijzigd.
   - In het slechtste geval worden h+1 knopen gesplitst of samengevoegd.
   - Het totaal aantal schijfoperaties is O(logdm=2e n), met processortijd per knoop van O(m).

### Varianten van B-trees
1. **B+-tree**
   - Opslag van alle gegevens (sleutels en informatie) in de bladeren.
   - Inwendige knopen dienen enkel als index.
   - B+-trees zijn efficiënt voor zowel random als sequentiële operaties.
   - Zoeken naar de opvolger van een sleutel vereist hoogstens één schijfoperatie.

Natuurlijk, hier is een samenvatting van de tekst in opsommingstekens:

## Uitwendige Hashing

### Extendible Hashing

- Biedt efficiënte alternatieven voor B-trees wanneer de volgorde van sleutels niet cruciaal is.
- Gebruikt een trie-structuur om data in schijfpagina's te organiseren.
- Elke trie-knoop bevat sleutels met een gemeenschappelijk voorvoegsel.
- Pagina's worden gesplitst wanneer ze vol zijn, waarbij sleutels worden verdeeld op basis van het volgende bit in hun hash.
- Vereist een goede hashfunctie voor gebalanceerde trie-structuren.
- Behaalt O(1) schijfoperaties voor woordenboekoperaties.
- Geen afhankelijkheid van de volgorde van sleutelinsertie.
- Operaties:
  - **Zoeken**: Gemiddeld O(1), omvat hashberekening, tabelopzoeking en sequentiële sleutelzoektocht in de pagina.
  - **Toevoegen**: Gemiddeld O(1), eenvoudig als de pagina niet vol is; zo niet, wordt de pagina gesplitst.
  - **Verwijderen**: Complex, omvat het lokaliseren van de pagina, het verwijderen van de sleutel en mogelijk het samenvoegen van pagina's.

### Linear Hashing

- Elimineert de noodzaak van een trie-structuur en hashtabel.
- Gebruikt pagina's met opeenvolgende adressen.
- Splits pagina's sequentieel, zelfs als ze niet vol zijn, en kent overflowpagina's toe.
- Adressen worden gevormd uit een aantal bits, passen dynamisch aan op basis van splitsingen.
- Operaties:
  - **Zoeken**: Gemiddeld O(1), omvat hashberekening en vergelijken van bits met het paginadres.
  - **Toevoegen**: Gemiddeld O(1), omvat het lokaliseren van de pagina en het toevoegen van de sleutel aan de gesorteerde tabel. Splits als de pagina vol is.
  - **Verwijderen**: Complex, omvat het lokaliseren van de pagina, het verwijderen van de sleutel en mogelijk het samenvoegen van pagina's.

### Opmerkingen:

- Beide methoden streven naar minimalisatie van schijfoperaties voor woordenboekoperaties.
- Goede hashfuncties zijn cruciaal voor efficiënte prestaties.
- Extendible hashing kan gebruikmaken van tweelaagse implementaties of het aantal gegevensvermeldingen per pagina verhogen.
- Linear hashing biedt een dynamische structuur zonder de noodzaak van een afzonderlijke hashtabel.
- Prestatievergelijkingen tussen extendible en linear hashing zijn afhankelijk van factoren zoals de aanwezigheid van overflowpagina's en de efficiëntie van hashfuncties.