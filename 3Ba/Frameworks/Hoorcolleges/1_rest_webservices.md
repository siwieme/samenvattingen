# Herhaling HTTP

## HyperText Transfer Protocol (HTTP)
* Client-Server protocol
* Transportprotocol: TCP op poort 80
* Aanvraag-antwoord protocol (Request-Response)
* Web
* Verschillende versies (HTTP 1.0, HTTP 1.1, HTTP/2, HTTP/3)

## HTTP-aanvraag (Request)
* Eerste headerlijn
* Volgende headerlijnen
* Lege lijn
* Optioneel: body (afhankelijk aanvraagmethode)

## Aanvraagmethodes
* GET
* HEAD
* POST
* PUT 
* DELETE
* OPTIONS

## Veelgebruikte statuscodes
* 1??: Informatief
* 2??: Succes
* 3??: Omleiding
* 4??: Fout bij client
* 5??: Fout bij server
* 200 OK, 304 Not Modified, 400 Bad Request
* 403 Forbidden, 404 Not Found, 405 Method Not Allowed
* 500 Internal Server Error, 503 Service Temporarily Unavailable

## HTTPS
* HyperText Transfer Protocol Secure
* Maakt gebruik van SSL (Secure Sockets Layer)
* Standaardpoort: 443

# Algemene Principes

## Webservice
* Service (of dienst) aanbieden via het web (HTTP)
    * Functionaliteit
    * Data
* Endpoints

## REST
* Representation State Transfer
* Principes om webservices te maken

### Architecturale beperkingen
* Client-Server
    * Onafhankelijk
    * Apart evolueren
    * Client kent enkel URI
    * Enkel de interface (API) tussen beiden ligt vast
* Uniforme interface
    * Uniforme manier om te communiceren met de server, onafhankelijk van het type client
    * Richtlijnen
        * Bron-georiënteerd
            * Webservice (bron, geïdentificeerd door URI, representatie)
        * Gebruik de HTTP-methodes expliciet
            * Create (Post)
            * Read (Get)
            * Update (Put)
            * Delete (Delete)
        * Links om makkelijk zelf bronnen te ontdekken
            * URI
                * Zelfstandig naamwoord
                * Bron waarop actie toegepast moet worden
                * gebruikers ophalen: /users of /gebruikers
            * Structuur zoals een directory
                * Hiërarchisch
                * Boomstructuur met één startpunt
            * Richtlijnen
                * Zelfstandig naamwoord in meervoud
                * Verberg extensies (URI's blijven bij veranderende technologie)
                * Gebruik kleine letters
                * Vervang spaties door "-"
                * Gebruik Querystrings om te filteren, sorteren ...
                * Vermijd 404 Not Found
* Statusloos
    * Elke aanvraag staat op zichzelf
    * Server houdt geen informatie bij
    * Client moet status bijhouden
    * Voordelen
        * Aanvraag doorgeven aan andere server(s)
        * Load-balancing: verhogen schaalbaarheid
        * Failover: verhogen betrouwbaarheid
* Cacheable
    * Antwoord bevat
        * Cacheable?
        * Hoelang?
    * Een kopie van een bepaalde resource wordt bewaard en teruggeven bij opvraging (kan op server- of client-side gebeuren)
    * Verbetert performantie
* Gelaagd systeem
    * De client weet niet met welke laag hij geconnecteerd is
* Code op aanvraag
    * Optioneel
    * De inhoud van het bericht mag ook code zijn

### Glory of REST
* Level 0: het moeras van pokken
    * HTTP enkel gebruiken als transport
    * Eén endpoint
* Level 1: Bronnen
    * Verschillende endpoints
    * Argumenten in body
* Level 2: HTTP-methoden
    * HTTP-methodes als CRUD
    * HTTP-statuscodes in antwoord
        * Foutcode indien er iets mis ging
* Level 3: Hypermedia Controls
    * HATEOAS (Hypertext As The Engine Of Application State)
    * Links naar andere bronnen in antwoord
    * Selfdocumenting protocol

# Java

## Praktijk
* Client
    * AJAX (XMLHttpRequest)
    * Fetch API
* Service in Java
    * JAX-RS (Java API for RESTful Web Services)
    * Spring REST

## Spring
* Framework Professionele Java-programma's
* JVM (= container voor Java-objecten)
* Verschillende bibliotheken om sneller toepassingen te bouwen

### Springboot
* Sneller projecten maken: templates
* Veel configuratie vermijden
* Makkelijk afhankelijkheden beheren

### Architectuur REST API in Spring

<img src="https://i.ibb.co/6H2sscp/RESTOverview-Application-Constitution-On-Spring-MVC.png">

1. Spring-framework ontvangt een HTTP-aanvraag en bepaalt voor welke methode van welke controller opgeroepen moet worden
2. Optioneel: JSON in de body omzetten naar object
3. Optioneel: Validatie voor de inputwaarden van het object
4. Oproepen methode van controller met object als parameter
5. **In de controller wordt de achterliggende logica opgeroepen**
6. **De logica interageert met de datalaag**
7. Het resultaat van de methode van de controller wordt geserialiseerd naar JSON (of een ander formaat)
8. Het HTTP-antwoord wordt aangemaakt. De (eventuele) body bevat het JSON-antwoord

* Implementatie
    * HTTP-aanvragen afbeelden op methodes RestController
        * Berichten converteren
        * Data wegschrijven naar body HTTP-bericht
        * Klasse annoteren met **@RestController**
        * Optioneel: klasse annoteren met **@RequestMapping("naam")**
            * Alle requests die beginnen met /naam zullen hier naartoe gemapt worden
        * GET: methode annoteren met **@GetMapping** (als klasse RequestMapping heeft)
        * GET: methode annoteren met **@GetMapping("naam")** (als klasse geen RequestMapping heeft)
        * GET: resultaat wordt automatisch naar JSON geconverteerd
    * Dependency Injection
        * Spring
            * De te injecteren klasse annoteren met **@Component**
            * Framework zoekt dan zelf de parameters
* Parameters in pad
    * Deelpad tussen {...}
        * Dient vaak ook als parameter van methode
        * **@PathVariable("...")**
    * Bronnen filteren
        * **@RequestParam(name="naam",required="boolean",defaultValue="waarde")**
* Data uit body HTTP-bericht halen
    * **@RequestBody**
    * Body HTTP-request wordt automatisch naar een Java-object omgezet
* Antwoordstatus bepalen
    * Statuscode koppelen aan exceptie
        * **@ResponseStatus(code = HttpStatus.VARIABELE)**
        * Statuscode koppelen aan methode RestController of Exceptieklasse
    * ResponseEntity = object dat HTTP-antwoord voorstelt
* URI's in antwoord
    * return ResponseEntity.created(uri).build();
    * Als het een created-tag is

# Testen

## Manueel testen
* Tool
    * HTTP-berichten sturen
    * Resultaat bekijken
    * Via PostMan of andere

## UnitTest
* Testen apart onderdeel
* Mockups (dummy's) voor afhankelijkheden
* Vroeg tijdens ontwikkeling
* Snel uitgevoerd wegens weinig afhankelijkheden

* Fixture en fase
    * Fixture
        * Vaste context/begintoestand voor testen
        * Baseline state
    * Vier fases
        * Set up: test fixture klaarzetten
        * Exercise: interageer met het te onderzoeken systeem
        * Verify: controleer of verwacht resultaat bereikt is
        * Tear down: test fixture afbreken naar originele toestand

* Dummy's
    * Relatie tussen componenten
    * Vervang één of meerdere componenten door dummy:
        * Zelfde "interface"
        * Eenvoudiger implementatie, werking
        * Eenvoudiger deployment
    * Ideaal voor Inversion of Control

* Mockup
    * Gegenereerde dummy-klasse
    * Implementeert interface
    * Heel eenvoudige werking

### Test schrijven
* **@SpringBootTest** boven de klasse
* **@Test** boven de methode
* assertEquals om te vergelijken
* Andere asserts beschikbaar
* Voor en na een test
    * @BeforeAll
    * @BeforeEach
    * @AfterAll
    * @AfterEach

## WebTestClient
* **@SpringBootTest(webEnvironment = WebEnvironment.RANDOM_PORT)**
* **@AutoConfigureWebTestClient**
* Dependency Injection:
    * **@Autowired**
    * private WebTestClient webClient
* Profielen
    * **@Component**
    * **@Profile("naam")**
    * In testklasse: **@ActivePRofiles("naam")**

# Beveiligen
* Authenticatie: gebruiker herkennen
    * PasswordEncoder: wachtwoord veilig bewaren
* Autorisatie: rechten instellen
* CSRF: Cross Site Request Forgery
* HTTPS gebruiken

## Authenticatie
* Annotaties voor een beveiligingsklasse
    * **@Configuration**
    * **@EnableWebSecurity**
* Annotaties voor een beveiliginsmethode
    * **@Bean**
    * vb: public SecurityFilterChain naam(HttpSecurity http) { ... }
* Op basis van pad
    * .requestMatchers("pad").hasRole("ROL")
* Beveiliging configureren op methodes
    * **@EnableMethodSecurity(prePostEnabled=boolean, securedEnabled=boolean,jsr250Enabled=boolean)**
    * prePostEnabled: voor- of na uitvoeren methode
    * securedEnabled: beveiliging op basis van rollen
    * jsr250Enabled: beveiliging op basis van specifieke Java-annotaties

## Principe

<img src="https://docs.spring.io/spring-security/reference/_images/servlet/authorization/authorizationfilter.png">

* Methodes webservice beveiligen - rollen
    * **@Secured({ "ROL_1", "ROL_2" })**
* JSR 250
    * **@RolesAllowed({ "ROL_1", "ROL_2" })**
* Conditie
    * **@PreAuthorize("hasRole('ROL')")**

## CSRF
* Synchronizer Token Pattern
* SameSite-attribuut op cookie
* Standaard aan in Spring