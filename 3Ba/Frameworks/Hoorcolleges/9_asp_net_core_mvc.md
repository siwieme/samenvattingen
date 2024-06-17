# ASP.NET Core MVC

## Model-View-Controller-pattern (MVC)

<img src="https://media.geeksforgeeks.org/wp-content/uploads/20230927120218/mvc.png">

### MVC in GUI's

* Oorsprong SmallTalk
* GUI
    * Tabellen
    * Tekstcomponenten
        * M: document
        * V: tonen
        * C: editeermogelijkheden
* Klok
    * Mathematisch model
    * Tonen
    * Aanpassen

### MVC in webapplicaties

* Wordt ook Model2 genoemd
* Principe
    * Scheiding van belangen
        * Opsplitsen programma
        * Gescheiden functionaliteit
        * Modules zoveel mogelijk "op zich"
    * Scheiding van taken
        * Webdesigners
        * Softwareontwikkelaars

* Drie modules
    * Applicatiemodel: gegevensvoorstelling en applicatielogica (**Model**)
    * Presentatie gegevens en gebruikersinput (**View**)
    * Gedrag applicatie (flow) - doorsturen aanvragen (**Controller**)

### Informatie
* ASP.NET Core MVC
    * Webapplicaties
    * REST-webservices (Web API)
        * Kan gecombineerd worden met een Angular-client of React-client
* Kenmerken
    * Windows - Linux - OSX
    * HTML5 - CSS - JavaScript
    * NuGet - npm - Bower - Gulp
    * Microsoft Azure

## Model-View-Controller-pattern (MVC)
* Models
    * Data applicatie
    * Validatie
    * Bewaard in bv. database
* Views
    * UI
    * Toont data model
* Controllers
    * Afhandelen HTTP-aanvragen
    * Data ophalen
    * View template selecteren

### Routing

* Wat vastgelegd?
    * Link tussen URL en Controller+Methode
* Standaard:
    * http://website/{naam controller}/{naam actiemethode}
* Verantwoordelijk voor
    * Bepalen actiemethode
    * Bepalen parameters actiemethode

#### Concept

* URL mapping
    * begrijelijke URL's, handig om te zoeken (zonder bestandsextensies)
* URL's worden afgebeeld op controllers door routing engine
* Waar vastgelegd?
    * Program.cs
        * Standaardroute, gegenereerd bij aanmaak project
    * Registreren routes: volgorde belangrijk
        * Eerste die voldoet wordt toegepast

#### Configuratie

```cs
app.MapControllerRoute(
    name: "default",
    pattern: "{controller=NaamController}/{action=NaamFunctie}/{id?}"
);
```

### Structuur applicatie

* Aparte map voor modellen, views en controllers
* Model
    * Gewone klassen
    * Map Models

#### Controller

* Afgeleid van Microsoft.AspNetCore.Mvc.Controller
* Naam eindigt op "Controller"
* Verantwoordelijk voor
    * Afhandelen fouten tijdens actie
    * Standaardview voorzien
* Kan verschillende actiemethodes hebben
    * Alle publieke methodes
    * Tenzij attribuut: [NonAction]

#### Actiemethode

* (I)ActionResult
<img src="https://img001.prntscr.com/file/img001/pyVKoicHQEON17tXgczfDQ.png">

#### View

* Razor View Engine
* .cshtml-bestanden
    * HTML genereren gebruik makend van C#
* @
    * C#-code
* Parser kent C#-semantiek en kan onderscheid maken tussen code en HTML
* Notatie voor codefragmenten
    * @
* Uitvoer naar HTML
    * @varNaam
    * Schrijft naar uitvoer
    * Encodeert eventueel naar HTML (bescherming tegen HTML-injectie en cross site scripting)
        * alle invoer (mogelijk malafide) die getoond wordt in een pagina omzetten naar tekst

#### Cross Site Scripting (XSS)

* Kwaadaardige code injecteren in een webpagina
* Invoer gebruiker toevoegen in HTML van de webpagina

#### View HTML-helpers
* Methodes om HTML te genereren
    * ~ webcomponenten
* Voorbeeld
    * @Html.DisplayNameFor(model => model.Naam)
        * Genereert een HTML-string voor de naam van de eigenschap
    * @Html.DisplayFor(modelItem => item.Naam)
        * Genereert een HTML-string voor de eigenschap die het resultaat is van de lambda-uitdrukking

#### Tag-helpers
* Extra attributen om HTML-tekst te genereren

#### Layout

##### Sjablonen

* Layout-pagina's
    * Sjabloon voor webpagina's
    * .cshtml-bestand
* Default: _Viewstart.cshtml
* Verschillende (in te vullen) secties in sjablonen

#### Data van Controller naar View

* Via ViewData
    * ~Map
* Via de parameter van de methode View
    * Objecten van modelklassen

#### Gebruik ViewData in Controller
```cs
@ViewData["naam"]
```

#### Informatie voor Controller

* HTTP-parameters in QueryString
    * via Request-eigenschap
    * via parameters actiemethode

* Parameters in URL
    * Parameters opgehaald uit URL
        * via parameters actiemethode

#### Methode View
* View()
    * viewengine gebruikt *naammethode*.cshtml
* View("string")
    * viewengine gebruikt string.cshtml
* View(object)
    * object beschikbaar als variabele Model in .*naammethode*.cshtml-pagina
* View("string", object)
    * object beschikbaar als variabele Model in string.cshtml

#### Namenruimten in View
* @using: gebruik namenruimten
* in bestand _ViewImports

#### Controller en formulier
* Zelfde URL
    * GET: leeg formulier tonen
    * POST: info bewaren

#### View en formulier

* @Html.LabelFor(...)
* @Html.EditorFor(...)
* @Html.ValidationMessageFor(...)

## Dependency Injection

* Afhankelijkheden
    * Parameter in constructor (constructor injection)
    * Interface
    * Container (~runtime) levert concrete implementatie
* Transient: telkens nieuw object
* Singleton: één
* Scoped: één per request

## Validatie

### Model - View

* [Display(Name="naam")]
* [Required(ErrorMessage="boodschap")]

### View

* Tag: asp-validation-for

### Met jQuery

* jQuery = JavaScript bibliotheek
* ```html
        <script src="~/lib/jquery-validation/dist/jquery.validate.min.js"></script>
        <script src="~/lib/jquery-validation-unobtrusive/jquery.validate.unobtrusive.min.js">
        </script>```

### Controller
```cs
if (ModelState.IsValid) {
    ...
}
```

### Mogelijke validaties
* Required
* EnumDataType
* CreditCard
* EmailAddress
* MaxLength
* MinLength
* StringLength
* Phone
* Range
* RegularExpression

### Remote Validation
* Linkt een actie aan een variabele

## Cross-site Request Forgery
* Browser stuurt authenticatie token bij elke request
    * Hacker heeft JavaScript-script met call naar zelfde site: cookie meegestuurd
* Preventie
    * Twee tokens
        * In cookie
        * In form
        * Moeten gelinkt zijn op server
    * [ValidateAntiForgeryToken]

## Globalization en Localization
* Globalization
    * Applicaties zo ontwikkelen dat ze verschillende talen en culturen ondersteunen
* Localization
    * Applicatie (die globalization ondersteunt) aanpassen voor één specifieke taal/cultuur
* Drie stappen
    * Maak de inhoud aanpasbaar
    * Voorzie inhoud per taal en cultuur
    * Selecteer de taal en cultuur

### Inhoud aanpasbaar maken

#### Controller

* Toevoegen aan builder
* ```cs
    builder.Services.AddLocalization(options => options.ResourcesPath = "Resources");
    builder.Services.AddControllersWithViews()
        .AddViewLocalization()
        .AddDataAnnotationsLocalization();```

#### View

* @Localizer["naam"] in een tagje toevoegen

#### Voorzie inhoud per taal en cultuur

* .resx-bestanden
    * XML
    * Naam/waarde-paren
    * Culture (US, NL, BE ...)
        * Datums, tijd, munteenheid
    * UICulture (en, nl ...)
        * Taal

#### Middleware ASP.NET Core MVC
* Decorator-pattern

<img src="https://learn.microsoft.com/en-us/aspnet/core/fundamentals/middleware/index/_static/middleware-pipeline.svg?view=aspnetcore-5.0">

#### Endpoint Middleware

<img src="https://learn.microsoft.com/en-us/aspnet/core/fundamentals/middleware/index/_static/mvc-endpoint.svg?view=aspnetcore-5.0">

#### Localization Middleware
* Op basis van instelling browser
* Optioneel: expliciet instellen voor welke taal+cultuur-combinatie de webapp ondersteuning biedt
    * Meegeven via cookies, in de querystring, headers ...

## Beveiliging

* Afschermen delen van een website
* Twee stappen
    * Authenticatie
        * Gebruiker "herkennen"
        * De gebruiker is wie hij zegt te zijn
        * Inloggen
    * Autorisatie
        * Bepaalde rechten (niet) toekennen aan bepaalde gebruikers
            * Leden kunnen meer pagina's bekijken dan niet-lede
            * Administrators kunnen nog andere pagina's raadplegen

### ASP.NET Core Identity
* API
* Ondersteunt inlogfunctionaliteit voor de gebruikersinterface
* Beheert gebruikers, wachtwoorden ...
* Loginfunctionaliteit
    * Login/wachtwoord
        * Databank (SQL Server)
        * Storage in Cloud (Azure Table Storage)
    * Externe login provider: Facebook, Google

### Autorisatie

* Twee opties
    * Rollen
    * Policy

### Controller / Actie: enkel toegankelijk indien ingelogd

* [Authorize] enkel indien ingelogd
* [AllowAnonymous] iedereen kan hier aan
* Rollen: [Authorize(Roles = "rollen")]