# Binaire Zoekbomen

## Definitie

* Hashtabellen zijn efficiënt voor woordenboekoperaties maar ongeschikt voor gegevens die moeten worden gerangschikt
* Bij het opslaan van gegevens in een tabel zijn operaties met betrekking tot volgorde eenvoudig en snel, maar toevoegen/verwijderen is traag
* Binair zoeken is efficiënt voor zoeken in een gesorteerde tabel, maar toevoegen/verwijderen is gemiddeld langzaam omdat de helft van de tabel moet worden verschoven
* Een binaire zoekboom is een geschikte gegevensstructuur voor het efficiënt ondersteunen van woordenboekoperaties en het bijhouden van de volgorde van opgeslagen gegevens
* In een binaire zoekboom zijn sleutels in elke knoop kleiner dan of gelijk aan de sleutel van de knoop in de linkse deelboom en groter dan of gelijk aan de sleutel in de rechtse deelboom
* Bij het in-order doorlopen van een binaire zoekboom worden sleutels in gerangschikte volgorde verkregen
* Een binaire zoekboom biedt een snelle manier om gegevens te rangschikken door vergelijking, maar de constructie van de boom wordt niet meegerekend in de tijdscomplexiteit

## Zoeken

### Zoeken naar een sleutel:
* Recursief zoeken in een binaire zoekboom, vergelijken van sleutels met de knoopwaarden
* Tijdscomplexiteit is O(h), waarbij h de hoogte van de boom is

### Zoeken op volgorde:
* Zoeken naar minimum en maximum: recursief, naar links blijven gaan tot de linkerdeelboom leeg is (minimum), of naar rechts gaan tot de rechterdeelboom leeg is (maximum)
* Zoeken naar opvolger en voorloper: complexer, afhankelijk van de aanwezigheid van linker- en rechterdeelbomen
* Alle opzoekoperaties hebben een tijdscomplexiteit van O(h)

## Toevoegen:
* Toevoegen van een knoop vereist zoeken naar een geschikte plaats in de zoekboom en vervangen van een ledige deelboom door de nieuwe knoop
* Tijdscomplexiteit van toevoegen is O(h)
* Mogelijke aanpak bij gelijke sleutels: gebruik van extra wijzers voor duplicaten, logische waarde in de knoop, of randomgenerator voor balancering van de boom

## Performantie van Zoeken en Toevoegen:
* In het slechtste geval
    * Boom opgebouwd in een ongunstige volgorde
    * Performantie van zoeken en toevoegen O(n)
* In het gemiddelde geval
    * Boom willekeurig opgebouwd
    * Gemiddelde hoogte van de boom O(log n)
    * Resulteert in een gemiddelde tijdscomplexiteit van O(log n) voor zoek- en toevoegoperaties

## Verwijderen:
* Het verwijderen van een knoop in een binaire zoekboom heeft drie gevallen, afhankelijk van het aantal kinderen van de knoop: 
    * geen kinderen
    * één kind 
    * twee kinderen
* Het verwijderen van een knoop is in het algemeen O(h)
    * Waarbij h de hoogte van de boom is

## Threaded Tree:
* Een threaded tree is een binaire zoekboom waarbij nullwijzers verwijzen naar de opvolger (in inorder) of voorloper van een knoop
* Threads elimineren de noodzaak van een stapel bij het inorder overlopen van de boom, waardoor geheugen en tijd worden bespaard
* Toevoegen en verwijderen in threaded trees zijn bijna even efficiënt als in gewone zoekbomen, en het gebruik van threads kan geheugen besparen

De tekst behandelt ook gemiddelde diepte van knopen, inwendige weglengte, en enkele strategieën voor het omgaan met gelijke sleutels tijdens het toevoegen. Het verwijderen van knopen met meerdere kinderen wordt uitgebreid besproken, waarbij wordt benadrukt dat het behoud van de basiseigenschappen van de binaire zoekboom cruciaal is. Ten slotte introduceert het de threaded tree als een efficiënte alternatieve representatie.

## Randomized Search Trees:
* Randomized search trees neutraliseren het effect van de operatievolgorde door gebruik te maken van een random generator
* Een treap combineert een binaire zoekboom met een heap en heeft naast sleutels ook prioriteiten die door een random generator worden toegewezen
* De vorm van een treap is onafhankelijk van de toevoegvolgorde van sleutels, maar hangt af van willekeurig gegenereerde prioriteiten
* Operaties zoals zoeken, toevoegen en verwijderen in een treap hebben een verwachtingswaarde van O(log n), onafhankelijk van de operatievolgorde

## Hashtabel van een Binaire Zoekboom:
* Operaties: Hashtabellen ondersteunen alleen woordenboekoperaties en vereisen geen geordende sleutels. Binaire zoekbomen bieden meer flexibiliteit, inclusief operaties op basis van de volgorde van sleutels
* Performantie: Gemiddeld zijn de woordenboekoperaties op hashtabellen O(1), terwijl die op binaire zoekbomen gemiddeld O(log n) zijn. Binaire zoekbomen kunnen echter O(log n) behouden in het slechtste geval
* Geheugenvereisten: Hashtabellen zijn statisch en vereisen op voorhand geschatte grootte, terwijl binaire zoekbomen dynamisch zijn en minder geheugenfragmentatie hebben

De tekst bespreekt randomized search trees, met de nadruk op treaps als een specifieke implementatie. Het voordeel van treaps is dat ze de performantie van de woordenboekoperaties verbeteren door gebruik te maken van willekeurig gegenereerde prioriteiten, waardoor de verwachtingswaarde van O(log n) wordt bereikt. Daarnaast wordt een vergelijking gemaakt tussen hashtabellen en binaire zoekbomen op basis van operaties, performantie en geheugenvereisten.