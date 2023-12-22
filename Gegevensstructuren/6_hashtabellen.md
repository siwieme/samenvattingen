# Hashtabellen

## Definitie

Hashtabellen worden gebruikt voor gegevensstructuren die zoek-, toevoeg- en verwijderoperaties moeten ondersteunen, zoals bij de naamtabellen van compilers. Een hashtabel is een efficiënte implementatie van deze structuur en een compromis tussen geheugenruimte en uitvoeringstijd.

## Het opvangen van conflicten

Hashtabellen vereisen twee onafhankelijke keuzes: een geschikte hashfunctie en een conflictbeheersingsmechanisme.

### Chaining

#### Separate chaining

* Alle sleutels met dezelfde tabelindex komen in gelinkte lijsten terecht.
* Zoeken, toevoegen en verwijderen hebben gemiddeld O(1) prestaties, afhankelijk van de kwaliteit van de hashfunctie.
* Bezetting van elke lijst is gemiddeld n/m (bezettingsgraad), en dit beïnvloedt de zoek- en toevoegtijd.

#### Coalesced chaining

* Gebruikt een tabel van lijstknopen in plaats van lijsten.
* Lijsten kunnen samenklitten, maar blijven kort.
* Verschillende varianten zijn mogelijk, waarbij de grootteverhouding tussen adreszone en berging verschillende prestaties oplevert.

### Open adressering

#### Bepalen van zoeksequenties

* Drie technieken: lineair testen, kwadratisch testen en dubbele hashing.
* Dubbele hashing benadert uniforme hashing goed en genereert veel zoeksequenties.

#### Performantie van open adressering

* De performantie wordt bepaald door de bezettingsgraad (nooit groter dan ´e´en).
* Gemiddeld aantal testen voor een afwezige sleutel is 1/(1- ).
* Gemiddeld aantal testen voor toevoegen is hetzelfde als voor een afwezige sleutel.
* Gemiddeld aantal testen voor een aanwezige sleutel is m/(n(1-1/m)).

De keuze van hashfunctie en het beheer van conflicten zijn essentieel bij het implementeren van hashtabellen. De tekst benadrukt dat open adressering beter presteert bij een goed gekozen hashfunctie en dat de bezettingsgraad een cruciale rol speelt in de performantie.

## HASHFUNCTIES

Een goede hashfunctie moet:
* Snel kunnen worden geëvalueerd, afhankelijk van de processor
* Het aantal conflicten minimaliseren, afhankelijk van de sleutels
    * De hashfunctie moet er voor zorgen dat elke tabelindex even waarschijnlijk is voor elke sleutel
    * Onafhankelijk van de indices voor andere sleutels
    * Dit staat bekend als enkelvoudige uniforme hashing

### Vaste hashfuncties

#### Delen:
Deze methode zet een geheel getal s om in een index door de rest te berekenen bij deling door m: $ h(s) = s \mod m $. De grootte m van de hashtabel moet zorgvuldig worden gekozen om conflicten te voorkomen.

#### Vermenigvuldigen:
De sleutel wordt vermenigvuldigd met een constante fractie C en het resultaat wordt afgerond naar beneden: $ h(s) = \lfloor m \cdot (sC - \lfloor sC \rfloor) \rfloor $. De waarde van m is niet kritisch, meestal kiest men $ m = 2^i $.

Voor grote sleutels zijn er mogelijkheden, zoals het optellen of bit-per-bit exclusieve-of operaties voor afzonderlijke woorden.

#### Universele hashing:
Om conflicten te vermijden, wordt voorgesteld om bij ingebruikname van een hashtabel random een hashfunctie te kiezen, wat bekend staat als universele hashing. Dit is een 'randomized' algoritme dat de performantie onafhankelijk maakt van de gebruikte sleutels.

### Universele hashing

Universele hashing betreft het random kiezen van een hashfunctie uit een zorgvuldig ontworpen familie van functies. Deze familie zorgt ervoor dat de kans op conflicten hoogstens \(1/m\) is. Een voorbeeld is het gebruik van een familie van functies van de vorm $h(s) = ((as + b) \mod p) \mod m$, waarbij a en b willekeurige getallen zijn en p een priemgetal groter dan k.

De keuze van p is niet kritisch en kan een priemgetal zijn tussen k en \(2k\). Deze methode maakt gebruik van randomized algoritmes en voorkomt dat een specifieke set sleutels altijd een slechte performantie heeft.