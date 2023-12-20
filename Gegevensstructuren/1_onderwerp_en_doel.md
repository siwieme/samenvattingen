# Onderwerp en doel

## Inleiding

* Algoritmen
    * Methodes om problemen op te lossen
    * Geschikt voor implementatie op een computer
    * Gebruikte gegevens kunnen op veel manieren georganiseerd worden
    * Hoofddoel: efficiëntie (uitvoeringstijd en/of geheugengebruik)
    * Geen volledig afgewerkt programma
    * Kunnen beschreven worden:
        * Menselijke taal
        * Computerprogramma (al dan niet geïmplementeerd)
        * Pseudocode (de enige programmeertaal zonder syntactische fouten)
        * Wiskundig formalisme

* Programma
    * Implementatie
    * Bepaalde programmeertaal
    * Eén of meerdere algoritmen

## Datastructuren

* Efficiënte algoritmen: zeer eenvoudige gegevensstructuren
* Eenvoudige algoritmen: (soms) zeer complexe gegevensstructuren

* Algoritme & gegevens:
    * Nauw verweven
    * Nuttig om conceptueel te scheiden
    * Algoritme expliciet gebruik laten maken van gegevensstructuur

* Apart gedefinieerde gegevensstructuren:
    * Bouwstenen bij meer ingewikkelde algoritmes
    * Makkelijker te vervangen voor betere performantie

* Soort verzamelingen
    * Groeien, krimpen, wijzigen
    * *Dynamische* verzamelingen
    * Gegevens:
        * Identificatie: *sleutel*
        * *Bijhorende informatie*

### Containers en woordenboeken

* Container
    * Sleutel speelt geen rol: louter als opslagplaats
    * Gegevens opvragen:
        * Toevoegvolgorde
        * Aan de gegevens toegekende prioriteit

* Woordenboeken (dictionaries)
    * Zoeken
    * Toevoegen
    * Verwijderen
    * Zoeken + verwijderen gebruiken sleutel om object te lokaliseren
    * Vaak ook operaties op volgorde
        * Moet ordening op sleutels gedefinieerd zijn

### Continue en gelinkte datastructuren

* Continue datastructuren:
    * Array, HashMap, Heap
    * Data fysiek dicht bij elkaar (memory locality)
    * Voordeel:
        * Performantie ten goede: gegevens dicht op elkaar -> efficiënt gebruik snelle processorcache
        * Overlopen: meteen blok data naar cache kopiëren
    * Nadeel:
        * Grootte vastgelegd
        * Uitbreiden?
            * Nieuwe datablok reserveren + alles kopiëren
            * Geen aaneengesloten blok beschikbaar? Uitbreiden **NIET** mogelijk

* Gelinkte datastructuren:
    * Pointers om naar geheugenlocaties te verwijzen
    * Voordeel:
        * Geen aaneengesloten blok data nodig
        * Zolang er ruimte is, uitbreidbaar
        * Eenvoudig dynamisch aan te passen
    * Nadeel:
        * Overhead; naast gegevens ook pointer opslaan

### Lineaire en niet-lineaire datastructuren

* Lineair:
    * Alles op één rij
    * Vb: array of gelinkte lijst
* Niet-lineair
    * Meer dimensionaal
    * Vb: boom of graaf

## Abstract Data Type

* Vaak gebruikte gegevensstructuren
* Beste keuze
    * Toepassing waarvoor je gegevensstructuur wenst te gebruiken
    * Beginnend programmeur: type operaties
    * Ervaren programmeur: zo efficiënt mogelijke implementatie voor deze operaties
    * Als *black-box* behandelen: enkel naar interface kijken: Abstract Data Type
        * Vb: interface *List* voor de implementaties *ArrayList* en *LinkedList*