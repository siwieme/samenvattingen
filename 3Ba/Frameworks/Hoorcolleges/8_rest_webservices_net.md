# REST Webservices in .NET

# REST Webservices in .NET: Web API

## Web API
* Restful webservices met ASP.NET Core
* Testen: Postman
* Models
    * Maken gebruik van ORM (Entity Framework)
    * Attributen [] ~ annotaties @ (in Java)

### DbContext
* Objecten mappen op Databank
* CRUD-opdrachten
    * Create
    * Read
    * Update
    * Delete
* Houdt verandering aan objecten bij (Change tracking)

### DbSet
* Verzameling entiteiten
* Beheerd door DbContext
* CRUD-opdrachten
    * Create
    * Read
    * Update
    * Delete

### Toevoegen item

<img src="https://img001.prntscr.com/file/img001/TtwPxRy5R0WKG7ovCw7pbA.png">

### Ophalen items

<img src="https://img001.prntscr.com/file/img001/RES5FMHNTceZjVcY4ve_8g.png">

### Aanpassen items

<img src="https://img001.prntscr.com/file/img001/nqQAltt9QpiFypgqUpJLJA.png">

### Configuratie
```cs
var builder = WebApplication.CreateBuilder(args);
builder.Services.AddDbContext<ToDoContext>(opt => opt.UseInMemoryDatabase("TodoList"));
builder.Services.AddControllers();
```

### GET
* [HttpGet] toevoegen
* async-methode
* Return-tyoe ```Task<ActionResult<IEnumerable<ModelClass>>>```
* IEnumerable is enkel bij meerdere items, bij één enkel item mag er gewoon meteen ModelClass gebruikt worden
* Eén item: [HttpGet("{identifier}")]
    * public ... functieNaam(TYPE identifier)

### POST
* [HttpPost] toevoegen
* Item meegeven met functie
* public ... functieNaam(MODELCLASS model)

### PUT
* [HttpPut] toevoegen
* HTTP 400: return BadRequest();
* HTTP 404: return NotFound();
* HTTP 204: return NoContent();
* IActionResult als return-type (ook van een Task)

### DELETE
* Eén item: [HttpDelete("{identifier}")]
* public ... functieNaam(TYPE identifier)

# OpenAPI specificatie

* Formaat op REST-webservices te beschrijven
    * Welke endpoints zijn er?
    * Welke methodes ondersteunen ze?
    * Parameters: input, output?
    * Welke authenticatie-methodes?
    * Informatie: contact, licentie ...
* In JSON of YAML (YAML Ain't Markup Language)

## Waarom OpenAPI?

* Beschrijving interface onafhankelijk van een programmeertaal
* De gebruiker kent de functionaliteit van de service zonder de broncode te kennen
* De gebruiker weet hoe hij kan interageren met de REST-webservice
* Ontkoppelen API en implementatie
* API first approach: consistenter

## Swagger
* Drie tools
    * Swagger Editor: specificatie schrijven
    * Swagger UI: specificatie genereren
    * Swagger Codegen: specificatie wordt code
        * Ondersteunt meerdere talen
* Toevoegen via NuGet

### Swagger UI
* Genereert JSON
    * Formele beschrijving REST-service
* Genereert webpagina
    * Leesbare beschrijving REST-service
* Kan commentaar uit code gebruiken
* Informatie uit data-attributen

### Gegenereerde JSON - components
* Beschrijving datatypes (body HTTP-bericht)
    * Uitbreiding op JSON Schema Specification
    * Leesbaar voor mens & machine
    * Automatisch controleerbaar

## OpenAPI Specificatie
- Info: informatie over beschrijving, licenties, contact ...
- Servers: op welke URL’s beschikbaar, verschillend voor productie, ontwikkeling ...
- Paths: verschillende paden
- Components: beschrijving types objecten
- Security: welke beveiliging is er voorzien
- Tags: groeperen paden in webpagina
- ExternalDocs: verwijzen naar externe documentatie

## Configuratie
* app.UseSwagger();
* app.UseSwaggerUI();