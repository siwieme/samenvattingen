# JavaScript

## Algemeen
* Scripttaal (ECMAScript)
* Ontworpen om HTML pagina's interactiever en dynamischer te maken

## Variabelen
* Geen sterke typering
    * Types worden dynamisch (at runtime) toegekend en eventueel veranderd
* Declaratie
    * let (block scope)
    * const (constante waarde)
    * var (globale/functie scope)

## Datatypes
* Number
* Boolean
* String
* null
* undefined

## Array
Voorbeeld:
let namen = ["Veerle", "Thomas", "Joris"];

## Objecten
Containers voor eigenschappen (properties)
* Sleutel/waarde-paren
* Waarden: primitieve types, andere objecten ...
* Vb: let persoon = {naam: "Janssens", voornaam: "Jan", leeftijd: 20};
* Operatoren: . en []

## Destructuring assignment
* Items uit een array aan verschillende variabelen toekennen
* Vb: let [x, y] = [2.3, 8.4]; console.log(`${x},${y}`)

## Functie - declaratie
```js 
function som(a,b) {
    return a+b;
};
```

 ## Functie - uitdrukkingen
 ```js
 let som = (a,b) => {
    return a+b;
 };
 function pasFunctieToeOpArray(functie, lijst) {
    let resultaat = new Array;
    for (let i=0; i<lijst.length; i++)
        resultaat[i] = functie(lijst[i]);
    return resultaat;
 }
 let resultaat = pasFunctieToeOpArray(x => x * x * x, [0,1,2,5,10]);
 ```

 ## Array - lussen
 ```js
let kleuren = ["rood", "groen", "blauw"];
for (let i = 0; i < kleuren.length; i++)
    console.log(kleuren[i]);
for (let kleur of kleuren)
    console.log(kleur);
function toon(item) {
    console.log(item);
}
kleuren.forEach(toon);
 ```

## Methodes
* .some(item => voorwaarde) // is er één?
* .find(item => voorwaarde) // geeft eerste terug
* .filter(item => voorwaarde) // alle waarden die voldoen
* .map(item => nieuwe waarde) // functie toepassen op alle items in de array
* .reduce(voorwaarde) // overhouden wat aan voorwaarde voldoet

## Closure
* Interne functie: toegang tot alle variabelen en functies huidige scope
* Toegang blijft ook als omringde functie verdwijnt = **Closure**

## Klassen
* Getter: get x() { return ...; }
* Overerven: extends, super() en super.

<div style="page-break-after: always;"></div>

## Modules
* export = beschikbaar stellen
* import = gebruiken
* .mjs-extensie (soms)
* default als het slechts één klasse, functie, variabele bevat
