# NP-Complete Problemen

## Het belang van NP-Complete problemen

* Als je niet kan bewijzen dat een probleem NP-Compleet is, dan moet je allicht verder zoeken naar een efficiënt algoritme
* Als je kan bewijzen dat een probleem NP-Compleet is, dan hoef je geen moeite meer te doen om een efficiënt algoritme te vinden

## Beslissingsproblemen

* Een beslissingsprobleem is een probleem waarbij het antwoord ja of nee is

# Complexiteitsklassen

## De klassen P en NP

* **P** = de klasse van beslissingsproblemen die in polynomiale tijd **opgelost** kunnen worden (Polynomial time)
* **NP** = de klasse van beslissingsproblemen waarvan de oplossing in polynomiale tijd **geverifieerd** kan worden (Non-deterministic Polynomial time)

## Waarom leggen we de grens bij polynomiaal?

1. Als de uitvoeringstijd niet kan begrensd worden door een veelterm is het zeker niet efficiënt oplosbaar.
2. Veeltermen vormen de kleinste klasse functies die kunnen gecombineerd worden: som, product of veelterm van veelterm geven opnieuw een veelterm. Elke combinatie van algoritmen met polynomiale uitvoeringstijd resulteert in een algoritme met polynomiale uitvoeringstijd
3. De efficiëntiemaat blijft onafhankelijk van het computermodel en van de voorstelling van de invoer, zolang beide een polynomiale bovengrens
hebben.

# Reductie

## Reducties van algoritmes

* Vertaal een probleem dat je *wil* oplossen naar een probleem dat je *kan* oplossen

## Complexiteitsanalyse op basis van reductie

Complexiteit van dit algoritme is de som van:
* de complexiteit van het gebruikte sorteeralgoritme $O(P_{sorteren}(n))$ én
* de complexiteit van omvormen
    * het originele probleem omvormen naar een sorteerprobleem $O(1)$
  * De oplossing van het sorteerprobleem om te vormen naar een oplossing voor het originele probleem $O(1)$
$=> O(1) + O(P_{sorteren}(n)) + O(1)$

![alt text](afbeeldingen/PNP/image.png)