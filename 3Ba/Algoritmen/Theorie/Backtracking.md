# Combinatorische problemen

## Combintorisch probleem

* De oplossing heeft de vorm $v = (v_1, v_2, \ldots, v_n)$

### Soorten problemen

1. Genereer **alle** mogelijke oplossingen (of tel ze)
2. Genereer **één** oplossing, of bewijs dat er een oplossing bestaat
3. Zoek de **beste** oplossing voor een probleem op basis van een scorefunctie $f(v)$

## Permutaties

* De oplossing heeft de vorm $v = (v_1, v_2, \ldots, v_k)$ waarbij elke $v_i$ een element is uit een domein $V_i$ en $v$ eventueel voldoet aan enkele voorwaarden

## Deelverzamelingen

* De oplossing heeft de vorm $v = (v_1, v_2, \ldots, v_k)$ waarbij elke $v_i$ een element is uit een domein $V_i$ en $v$ eventueel voldoet aan enkele voorwaarden

## Backtracking

### Principe

* Bouw oplossing stapsgewijs op
* Indien ongeldige oplossing, kies andere waarde voor laatste component
* Indien alle waarden zijn uitgetest: keer terug en kies andere waarde voor voorlaatste component

### Implementatie

* Bouw veel verschillende oplossingen op door meervoudige recursie in elke stap
* Recursieve methode krijgt **deeloplossing** mee als argument
  * De initiële recursieve oproep start met een lege oplossing
* In elk basisgeval heb je een mogelijke oplossing

# Backtracking voor enumeratie

* Exhaustief overlopen van vele mogelijke oplossingen
* Weeg kostprijs voor test af tegen snelheidswinst van snoeien
* Twee manieren om te implementeren:
  * Copy - edit - explore
    * Pass-by-value
    * Impliciete "undo" stap
  * Choose - explore - undo
    * Voor grote datastructuren
    * Pass-by-reference + index in originele collectie
    * Expliciete "undo" stap

## Zoekboom

* Een niveau klimmen in de boom = je laatste keuze ongedaan maken
* Elk basisgeval levert een oplossing op

## Zoekboom voor enumeratie van permutaties

* **Beslissing** in elke stap (elk boomniveau): wat is de volgende letter die we toevoegen aan de permutatie?
* **Opties** bij elke beslissing (takken vanuit de node): een optie voor elke letter die nog niet werd geselecteerd

**Bij te houden informatie** tijdens afdalen:
* De permutatie die we tot nu toe hebben opgebouwd
* De letters uit de invoer die nog niet zijn gebruikt

| **Divide-and-X met recursie**                                                  | **Backtracking recursie**                                                           |
|--------------------------------------------------------------------------------|-------------------------------------------------------------------------------------|
| Herhaald oplossen van een kleiner probleem                                     | Bouw oplossing stapsgewijs op                                                       |
| Oplossing wordt opgebouwd bij het **opklimmen** in de recursieboom             | Bouw veel mogelijke oplossingen op door meervoudige recursie                        |
| Het basisgeval bevat de aanzet tot de oplossing                                | De aanzet tot de oplossing is de "lege" oplossing meegegeven aan de initiële oproep |
| De eindoplossing is het resultaat van de initiële oproep (wortel recursieboom) | Elk basisgeval levert je een potentiële oplossing                                   |

## Enumeratie met voorwaarden

### Choose-Explore-Undo

* Choose: wie is de volgende kandidaat? (opgelet: harde kopie)
* Explore:
  * Vind alle deelverzamelingen zonder gekozen kandidaat
  * Vind alle deelverzaemlingen met gekozen kandidaat
* Undo: Herstel de waarde van de argumenten zodat andere deelboom kan worden geëxploreerd

# Backtracking voor optimalisatie

## Knapsack probleem

* = zoeken van **beste** geldige combinatie (max. waarde)

## Zoekboom voor optimalisatieprobleem

* **Beslissing** in elke stap (elk boomniveau):
  * Voegen we een gegeven element toe aan onze combinatie?
* **Opties** bij elke beslissing (takken vanuit de node):
  * Voeg het element toe
  * Voeg het element niet toe

* **Bij te houden informatie** tijdens afdalen:
  * De reeds gekozen items
  * De totale waarde van de reeds gekozen items
  * De beschikbare capaciteit in de rugzak
  * De items waarover nog geen keuze werd gemaakt

# Optimaliseer backtracking

## Snoeien (EN: pruning)

* Probeer effectief aantal uitgevoerde recursieve oproepen te beperken:
  * Probleemsymmetrie
  * Domeinkennis (kies enkel geldige volgende opties)
  * Vroegdetectie van gedoemde paden
  * Indien slechts 1 oplossing nodig: maak keuzes in "slimme" volgorde

### Domeinkennis

* Kies enkel geldige volgende opties
* Vb. bij permutaties: kies enkel letters die nog niet zijn gebruikt
* Vb. bij deelverzamelingen: kies enkel elementen die nog niet zijn gekozen
* Vb. bij knapsack: kies enkel elementen die nog in de rugzak passen

### Probleemsymmetrie

* Horizontaal gespiegelde oplossingen
* Verticaal gespiegelde oplossingen
* Rotaties van oplossingen (90°, 180°, 270°)

# Branching strategies

* Least constraining value: kies de waarde die de minste beperkingen oplegt aan de rest van de oplossing
* Intuïtie:
  * Slecht pad? Maakt de volgorde niet uit
  * Goed pad? Kies de minst beperkende waarde

* Least remaining values == most constraining variable: kies de variabele met het minste aantal geldige waarden
* Intuïtie:
  * Minder opties betekent grotere kans dat je de juiste kiest
  * Kiezen we de foute, dan zullen we dit sneller detecteren omdat deze variabele sneller vastloopt

# Branch-and-bound

* = optimalisatie van backtracking