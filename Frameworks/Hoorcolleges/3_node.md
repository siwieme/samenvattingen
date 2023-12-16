# Node.js

## Wat is Node.js?
* JavaScript buiten de browser
    * Commandolijn programma's
    * Serverside platform   
* Gebouwd op Chromes JavaScript Runtime

## npm
* Node Package Manager
* Pakketbeheerder voor node.js
    * Repository: publiceren open-source Node.js projecten (=packages)
    * Beheren van packages
* Deel van de Node.js-installatie
* Alternatief: yarn

## package.json
* Bevat informatie over het project
    * Naam
    * Versie
    * Beschrijving
    * ...
* In de hoofdmap

## Applicatie maken
* In package.json bij scripts een build-script toevoegen

## Applicatie starten
* In package.json bij scripts een start script toevoegen
* Custom script uitvoeren: npm run "naam"

## Afhankelijkheden / Dependencies
* Opgeven in package.json
    * "naam": "versie"
    * "versie":
        * ~: patch meest recente
        * X.Y.Z
            * X: major
            * Y: minor
            * Z: patch

## Webservers

### Statische pagina's

<img src="https://i.ibb.co/zhqFYNf/afbeelding.png">

### Dynamische webpagina's
* Webpagina's genereren
    * Op server
    * Door programma's
        * Geïnterpreteerd (PHP, Node.js ...)
        * Gecompileerd (Java Spring, ASP.NET Core ...)

### HTTP-server in Node.js

<img src="https://i.ibb.co/PYB49Nv/afbeelding.png">

* Stukken URL opvragen
    * query = url.parse(request.url).query
    * request.url = het volledige gedeelte na het domein
    * Bepaalde delen: querystring.parse(query)["variabele"]
    * url & querystring zijn modules
* Routing
    * Meerdere pagina's
    * Doorsturen naar juiste handler
* HTTP-methode beperken
    * response.end() uitvoeren

## Node.js architectuur

<img src="https://www.vskills.in/lms/wp-content/uploads/2019/07/image080.jpg">

<img src="https://www.simform.com/wp-content/uploads/2020/04/node.js-architecture-1024x513.png">

<img src="https://www.simform.com/wp-content/uploads/2020/04/traditional-vs-node.js-server-thread-1024x1024.png">

* Aandachtspunten
    * Applicatie verantwoordelijk voor "eerlijke" behandeling van de verschillende clients
        * Don't block the Event Loop
            * Callbacks (then) korte uitvoeringstijd
            * Gebruik asynchrone methodes
            * Complexe berekeningen opdelen 

## Express.js
* Framework om snel webapplicaties te ontwikkelen in node.js

<img src="https://i.ibb.co/RD1GgKS/afbeelding.png">

* Voor code best de slides eens bekijken; "redelijk" straightforward tho

* Routing
    * URL leidt tot methode of module
    * Single Page Applications (SPA)
        * URL leidt tot REST call
    * Non-SPA
        * URL leidt tot volledige webpagina
    * Module Express Router
    * app.use("/deel", deelRouter);

* Express Routing
    * URI leidt tot actie
    * Basis routing
    * app.METHOD(PATH, HANDLER)

* Parameters
    * let id = req.params["id"]

* Functie route()
    * Eén route (URL)
        * Verschillende handlers per HTTP-methode
            * GET
            * POST
            * PUT
            * DELETE

<img src="https://i.ibb.co/8sT6Mj1/afbeelding.png">

* Views
    * PUG
        * Template voor HTML
        * Tabs ipv tags