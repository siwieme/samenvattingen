# Efficiëntie van algoritmen

## Analyse van algoritmen

* Uitvoeringstijd van algoritmen en operaties op datastructuren centraal
* Performantie van verschillende algoritmen vergelijken, zonder ze te implementeren

* Uitvoeringstijd kan niet gemeten worden zonder uit te voeren
    * Bepalen via analyse
    * Exacte tijdsduur = illusie
    * Hangt niet enkel af van algoritme, maar ook van:
        * Programmeertaal
        * Bekwaamheid programmeur
        * Efficiëntie van de compiler
        * Processorarchitectuur

* Bestuderen onafhankelijk van particuliere implementaties
    * Aantal *primitieve operaties* bepalen
        * Elke implementatie zou deze moeten uitvoeren
        * Op een typische sequentiële processor (RAM-model)
    * Tijden in berekening vervangen door niet nader bepaalde constanten

* Uitvoeringstijd afhankelijk van:
    * Aantal verwerkte gegevens *n*
    * Oorspronkelijke volgorde van gegevens
    * Statistische verdeling gegevens

* Beperken tot **drie** gevallen:
    * Beste geval
    * Slechte geval:
        * Meestal belangrijkste
        * Algoritme zal gegarandeerd nooit slechter performeren
    * Gemiddeld geval:
        * Dikwijls zeer moeilijk te bepalen
        * Soms zeer goed
        * Kans dat het mis gaat klein genoeg? Soms risico nemen
            * *Las Vegas*-algoritme

* Uitvoeringstijd bepaalt in elk van deze drie gevallen
    * Resultaat afhankelijk van *n*
    * Trachten te vereenvoudigen
    * Voldoende te weten dat we *constanten* hebben
        * Voorstellen met symbolische naam

### Voorbeeld

#### Code

```cpp
void insertion_sort(vector<T> &v) {
    // Stijgend rangschikken
    for (int i = 1; i < v.size(); i++) {
        // De eerste i getallen staan reeds in volgorde
        T h = move(v[i]);
        int j = i-1;
        while (j >= 0 && h < v[j]) {
            v[j+1] = move(v[j]);
            j--;
        }
        v [j+1] = move(h);
    }
}
```

#### Analyse

* Beste geval:
    * Oorspronkelijke vector stijgend gerangschikt
    * Instructies in de while nooit uitgevoerd
    * $ c_1*n + c_0 $ is de bekomen functie
* Slechtste geval:
    * Oorspronkelijke vector dalend gerangschikt
    * Elke *while* wordt *i* keer herhaald
    * $ c'_2*n^2 + c'_1*n + c'_0 $ is de bekomen functie
* Gemiddelde geval:
    * Zelfde waarschijnlijkheid om op elke mogelijke positie terecht te komen
    * Gemiddeld: helft gerangschikte deeltabel opgeschoven worden
    * *while* half zoveel keer uitgevoerd

* Nieuw ingevoerde constanten: functies eenvoudiger
* Niet geïnteresseerd in waarde uitvoeringstijd voor verschillende *n*
* Voor voldoende grote *n* is die toename bepaald door de belangrijkste term
    * Constante factor doet niet terzake

* Twee algoritmen voor hetzelfde probleem
    * Algoritme waar uitvoeringstijd voor slechts mogelijke geval het minst snel stijgt: meest efficiënt

## Asymptotische benadering van functies

* Vanaf voldoende grote waarden voor n, kan men de uitvoeringstijd benaderen
* Voor bepaalde algoritmen
    * Moeilijk of zelfs (voorlopig) onmogelijk om op de voorgaande manier te werken
    * In dat geval: functie van *n* vinden die uitvoeringstijd zo goed mogelijk begrenst

* Beide gevallen: begrenzende functie
* Benaderingen worden, bij gebrek aan beter, gebruikt om algoritmen onderling te vergelijken

* Functie *f(n)* groeit niet sneller dan een andere functie *g(n)*
    * *g(n)* vormt een bovengrens, we gebruiken de *O-notatie*
    * *f(n) = O(g(n))*, als er positieve constanten $c$ en $n_0$ bestaan
    * Asymptotische bovengrens: *f(n) = O(g(n))*
    * Voor elke c > |$c_k$| kan een gepaste $n_0$
        * Voor de O-notatie is dit echter van geen belang

* Men kan *f(n)* ook karakteriseren met een ondergrens
    * De Ω-notatie
    * *f(n) = Ω(g(n))* als er positieve constanten $c$ en $n_0$ bestaan

* Dezelfde functie *g(n)* zowel een boven- als een ondergrens vormt voor *f(n)*
    * De θ-notatie
    * *f(n) = θ(g(n))* als er positieve constanten $c_1$, $c_2$ en $n_0$ bestaan

## Moeilijke problemen

* Nadenken over best mogelijke performantie voor een oplossing voor dit probleem
* Verzameling P
    * Verzameling van alle problemen opblosbaar in polynomiale tijd: *O($n^\alpha$)*
* Verzameling NP
    * Voor geen enkel van deze problemen is er een algoritme bekend dat deze kan oplossing in polynomiale tijd
    * Aantal mogelijke oplossingen stijgt exponentieel
    * Brute, force techniek; enkel mogelijk voor heel kleine problemen

## Andere criteria

* Programma slechts een paar keer gaat gebruikt worden
    * Best algoritme kiezen dat snel geïmplementeerd kan worden
* Asymptotische benadering: met voorzichtheid gebruiken
    * Constante factoren spelen geen rol
    * Twee algoritmen met hetzelfde asymptotische gedrag zijn niet noodzakelijk even snel
    * Benaderingen enkel voor voldoende grote *n*
    * Asymptotische bovengrens van het slechtste geval kan soms te pessimistisch zijn; bepaling niet altijd realistisch
    * Data distributie: elke mogelijke input even waarschijnlijk is
* Soms gebruiken snelle algoritmen teveel geheugen
    * Doet hun voordeel teniet
* Klassieke RAM-model houdt geen rekening met de geheugenhiërarchie van de computer
    * Meer ingewikkelde modellen bedacht
    * Hoe realistischer het model, des te lastiger de analyses
* Parallelle verwerking met meerdere processoren kan de werking versnellen
    * Beïnvloedt onze asymptotische afschattingen niet
        * Aantal processoren constant
    * Beïnvloedt onze asymptotische afschattingen niet
        * Samen groeit met *n*
* Toegang tot het geheugen is een relatief trage operatie