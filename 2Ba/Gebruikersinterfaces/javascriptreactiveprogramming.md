# JavaScript - Reactive Programming

## Interactive Programming
* Object A kent de interface van object B

## Reactive Programming
* Object A reageert op veranderingen in object B
    * zonder de interface van B te kennen
    * kent enkel de methode subscribe
* Rxjs: veel gebruikte bibliotheek voor reactive programming

## Programmeerparadigma's
* Imperative Programming
    * Stap voor stap beschrijven wat het programma moet doen
* Functional Programming
    * Het programma beschrijft de data flow
    * Functies gebruiken om op basis van bestaande waarden nieuwe waarden te maken
    * Waarden zijn immutable, onveranderlijk
    * Geen toestandsinformatie - instantievariabelen
* Reactive Programming
    * Een object, functie, stukje code ... luistert en reageert op een veranderlijke data flow

## Observable
* Een collectie van toekomstige waarden of events
    * Er kunnen waarden later toegevoegd worden
* Observer / Consumer
    * Reageert telkens er een waarde toegevoegd wordt (emit)
* Subscription
    * Voegt een observer (= functie) toe die uitgevoerd wordt bij een nieuwe waarde
    * Functie subscribe

## Hot vs Cold Observables
* Cold Observable
    * Data geproduceerd in de "Observable"
* Hot Observable
    * Data geproduceerd buiten de "Observable"