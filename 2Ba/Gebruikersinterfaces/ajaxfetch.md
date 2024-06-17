# Ajax en Fetch API

## Ajax
Asynchronous JavaScript and XML
* Bestaande standaarden anders gebruikern
    * XMLHTTPRequest-object
    * JavaScript en DOM
    * CSS
    * XML

## Essentie Ajax
* Klassieke webpagina
    * HTTP-bericht naar server
    * Browser wacht op antwoord
    * Browser toont HTTP-antwoord
        * Nieuw document vervangt volledig vorig document
* Ajax
    * Delen van het HTML-document kunnen vervangen worden
    * Gebruiker kan verder werken (asynchrone communicatie met de server)

<img src="https://i.ibb.co/s6y3PV4/afbeelding.png">

## XMLHttpRequest-object
* Communicatie met server
    * Verstuurt HTTP-berichten
    * Ontvangt HTTP-berichten
* Oproepen functie indien antwoord ontvangen
* HTTP-antwoordbericht
    * Inhoud
        * Tekst
        * XML
        * JSON 

## Opstellen HTTP-aanvraag
* Methode open
```js
open(aanvraagMethode, URL)
open(aanvraagMethode, URL, asynchroon)
open(aanvraagMethode, URL, asynchroon, gebruikersnaam)
open(aanvraagMethode, URL, asynchroon, gebruikersnaam, wachtwoord)
```
* Asynchroon: default true
* Callbackfunctie: onreadystatechange
    * readyState
        * 0: request not initialized
        * 1: server connection established
        * 2: request received
        * 3: processing request
        * 4: request finished and response is ready
* Aanvraag versturen: send(corpus) -> parameters of null

## Fetch API
* API om bronnen op te halen in een client script
* Vergelijkbaar met XMLHttpRequest
* Gebruikt promises
* Parameters
    * GET: query in de URL
    * POST: in body
* Antwoord: tekst en JSON

## Opmerking cross domain calls
* Webpagina
    * Aanvraag naar bronnen van een ander domein
    * Niet toegelaten
* CORS
    * Server kan toelating geven om geraadpleegd te worden door een ander domein
    * Nieuwe HTTP-headers

## JSONP
    * JSON with padding
    * Browsers laten aanvraag naar ander domein wel toe voor <script>-tag