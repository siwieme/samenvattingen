# Eenvoudige woordenboeken

* Gebruiken sleutels om gegevens op te zoeken en op te slaan
    * Geschikte plaats
    * Snel teruggevonden worden
    * Veronderstelling: verschillende sleutels

## Tabel

### Rechtstreeks adresseerbare tabel

* Een-eenduidig + eenvoudig verband sleutels <-> tabelindices
    * Niet nodig zelf op te slaan
    * Tabelindex kan afgeleid worden uit de sleutel
    * Rechtstreeks adresseerbare tabel
* Bijhorende info
    * Indien vaste grootte + niet veel plaats benodigd
        * In tabel zelf opgeslagen worden
    * Anders pointer voorzien
        * Tabel niet te groot laten worden
        * Enkel plaats gereserveerd voor aanwezige elementen
* Alle woordenboekoperaties zijn hier O(1)
* Dubbel voorkomende sleutels
    * Gelinkte lijst voorzien naar alle bijhorende informatie
* Zie hoofdstuk 6

### Ongeordende tabel

* Zoeken
    * Elementen overlopen tot sleutel gevonden
    * Sequentieel of lineair zoeken
    * Afwezige sleutel: *n* vergelijkingen
    * Aanwezige sleutel: $(n+1)/2$ vergelijkingen
    * O(n)
* Toevoegen
    * Gebeurt achteraan
    * O(1)
* Verwijderen
    * Nadat de sleutel gevonden werd
    * Element overschrijven
    * O(1)

### Tabel geordend volgens zoekkans

* Indien op voorhand geweten dat sommige sleutels vaker voorkomen
* Sequentiële methode sneller maken door deze sleutels vooraan toe te voegen
* Vorige methode enigzins benaderen indien frequentie niet geweten
    * Optie 1:
        * Frequentie bijhouden waarmee elk element gezocht wordt
        * Gegevens rangschikken volgens dalende periode
    * Optie 2:
        * Gevonden element verwisselen met voorganger
        * Dynamische verbetering volgorde
        * Enkel mogelijk voor tijdsinvariante waarschijnlijkheidsverdelingen

### Gerangschikte tabel

* Zoeken
    * Lineair zoeken: O(n)
    * Gegevens gesorteerd: O(lg(n))
        * Gezochte sleutel vergelijken met middelste element
        * Verder zoeken in linkse of rechtse halve deeltabel
        * Aantal elementen telkens gehalveerd
        * Maximaal *lg(n) + 1* vergelijkingen
* Toevoegen
    * Nadat de plaats voor de nieuwe sleutel gelokaliseerd wordt
    * Gemiddeld de helft van de tabel opgeschoven worden
    * Slechtste geval: hele tabel opschuiven
    * O(n)
* Verwijderen
    * Zelfde als toevoegen
    * O(n)

## Lijst

* Gelinkte lijst kan ook als woordenboek dienen

### Ongeordende lijst

* Zoeken
    * Sequentieel: O(n)
* Toevoegen
    * Vooraan: O(1)
* Verwijderen
    * Na zoeken is verwijderen nog O(1)
    * Enkelvoudig gelinkte lijst: voorloper nodig

### Lijst geordend volgens zoekkans

* Dalende zoekwaarschijnlijkheid is best
* Niet gekend?
    * Dynamische methode
        * Transpose (omwisselen met voorganger)
        * Move-to-front (helemaal vooraan plaatsen ipv omwisselen)
            * Past zich sneller aan
            * Niet efficiënt bij tabellen

### Gerangschikte lijst

* Zoeken
    * Rechtstreekse toegang ontbreekt
    * O(n)
* Toevoegen
    * Sequentieel overlopen
    * O(n)
* Verwijderen   
    * Analoog aan toevoegen
    * O(n)