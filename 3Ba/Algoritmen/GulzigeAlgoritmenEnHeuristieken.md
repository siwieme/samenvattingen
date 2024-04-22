# Gulzige Ontwerptechniek

## Combinatorisch Optimalisatieprobleem

* Oplossing heeft de vorm $v = (v_1, v_2, \ldots, v_k)$ waarbij elke $v_i$ waarden aanneemt uit een domein $V_i$ en $v$ eventueel voldoet aan enkele voorwaarden
* Elke geldige oplossing krijgt een score $f(v)$
* We zoeken *een* geldige oplossing met de hoogste score

## Gulzige Ontwerptechniek

* Gebruikt voor ontwerp van heuristieken en algoritmen voor optimalisatieproblemen
* Stapsgewijs deeloplossing uitbreiden met nieuwe component (zoals backtracking)
* In elke stap wordt een keuze gemaakt
  * geldig
  * lokaal optimaal: keuze die je het meest vooruithelpt ("neem wat je kan")
  * onherroepelijk: keuze kan niet meer ongedaan gemaakt worden in een volgende stap (!= backtracking)

## Gulzige Heuristieken

### Knapzakprobleem

* Gegeven een verzameling van $n$ objecten met afmetingen $s_1, \ldots, s_n$ en een waarde $v_1, \ldots, v_n$ en een rugzak met capaciteit $S$
* Vul de rugzak met objecten zodat een hun totale waarde zo groot mogelijk is, zonder de capaciteit van de rugzak te overschrijden

## Gulzige Algoritmen

* Enkel te gebruiken in twee gevallen

### Processorscheduling

* In welke volgorde moet je de taken uitvoeren om de gemiddelde eindtijd te minimaliseren?

* Bewijs(jes) via PPT

## Metaheuristieken

### Heuristiek vs. Metaheuristiek

* Een **heuristiek** is een vuistregel of weloverwogen gok voor een specifiek probleem dat je niet exact kan oplossen. Er is geen garantie dat deze methode steeds een oplossing vindt, of steeds de beste oplossing vindt, maar de methode levert vaak wel aanvaardbare oplossingen voor praktische doeleinden
* Een **metaheuristiek** is een eerder *algemene procedure* om een heuristiek te vinden of genereren voor een bepaald probleem

### Indeling

* We vertrekken steeds van een volledige kandidaatoplossing $v=(v_1, v_2, \ldots, v_k)$
* Zoekstrategie: lokaal vs. globaal
* Opbouw van nieuwe kandidaatoplossing: random, kleine wijziging, combinatie van meerdere kandidaten, ...
* Deze methoden geven je nooit een garantie op een optimaal resultaat

### Globaal zoeken = telkens volledig nieuwe individuen

* Wanneer goede methode?
  * Veel aanvaardbare oplossingen in de zoekruimte
  * Geen enkele intuïtie over de structuur van de zoekruimte

### Lokaal zoeken

* Enkel betere oplossingen worden aanvaard
* Wanneer goede methode?
  * Bij coonvexe oplossingsruimte: slechts één globaal maximum (of minimum)
  * Je zit snel vast in lokale maxima/minima
  * Zelfs meerdere malen herhalen werkt niet goed als je veel lokale maxima/minima hebt

### Simulated Annealing

* Geïnspireerd door het proces van afkoelen van metalen
* Als onze huidige beste oplossing het individu $s$ is met een kost $f(s)$, dan aanvaarden we toch een naburig individu $s'$ met een slechtere (hogere) kost $f(s')$ met een probabiliteit $P(T,f(s), f(s')) = e^{(f(s) - f(s'))/T}$

### Boltzmann-verdeling

* De kans dat een systeem in een bepaalde toestand $i$ zit, is evenredig met $e^{-E_i/kT}$ waarbij $E_i$ de energie van de toestand $i$ is, $k$ de constante van Boltzmann en $T$ de temperatuur van het systeem

### Genetische Algoritmen

* Geïnspireerd door de evolutietheorie
* Een populatie van individuen wordt gecreëerd
* Individuen worden gecombineerd en gemuteerd
* De beste individuen worden geselecteerd voor de volgende generatie
* Herhaal dit proces

#### Crossover

* Twee individuen worden gecombineerd om een nieuw individu te creëren
* De nieuwe individu erft eigenschappen van beide ouders

#### Mutatie

* Een individu verandert op een willekeurige manier
* Dit zorgt voor diversiteit in de populatie

#### Beperkingen

* Combinatie oplossingen moet met vrij grote kans een geldige oplossing opleveren
* Moeilijk om cross-over en mutatie te definiëren
* Schaalt niet goed met aantal genen
* Tijdrovende evaluatie van fitnessfunctie op elk element in populatie