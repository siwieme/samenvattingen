# Reactive REST Webservices

## Principe

<img src="https://res.cloudinary.com/practicaldev/image/fetch/s--HJ0-5sVo--/c_limit%2Cf_auto%2Cfl_progressive%2Cq_auto%2Cw_880/https://thepracticaldev.s3.amazonaws.com/i/7hevybycq37g57jgugx6.jpg">

<img src="https://res.cloudinary.com/practicaldev/image/fetch/s--SD5lFff5--/c_limit%2Cf_auto%2Cfl_progressive%2Cq_auto%2Cw_880/https://thepracticaldev.s3.amazonaws.com/i/iy4ya5tq9indrx8zuee5.jpg">

<img src="https://engineering.linecorp.com/wp-content/uploads/2020/02/reactivestreams1-10.png">

## Reactor

### Flux

<img src="https://tech.io/servlet/fileservlet?id=79301324353863">

### Mono

<img src="https://tech.io/servlet/fileservlet?id=79301367277255">

## Asynchrone vs synchrone ...

### Client

* Asynchroon werkt sneller en gebruikt minder resources

<img src="https://engineering.linecorp.com/wp-content/uploads/2020/02/reactivestreams1-2.png">

### Server

* Synchroon gebruikt Blocking Request Processing
    * Alles blokkeert als er een request wordt gedaan
* Asynchroon gebruikt Non-Blocking Request Processing
    * Alles gaat mooi door

<img src="https://howtodoinjava.com/wp-content/uploads/2019/02/Blocking-request-processing.png">

<img src="https://howtodoinjava.com/wp-content/uploads/2019/02/Non-blocking-request-processing.png">

## Spring MVC versus Spring WebFlux Architectuur

<img src="https://img001.prntscr.com/file/img001/aIjhiy0HRSa0Y-SC1Tm7Cg.png">

### Spring WebFlux
* Twee programmeermodellen
    * Reactive components met annotaties
        * Zelfde annotaties als Spring MVC
        * Resultaat methodes: Mono of Flux
        * Geen Blocking methodes gebruiken
    * Functional Routing and Handling
        * Klasse met methodes die bepaalde aanvragen afhandelen (Handler)
            * Parameter: request-object
            * Resultaat: Mono met response-object
        * Configuratie: routing
            * Pad ~ methode handler

### Niet blokkerend (non blocking) client
* ClientTestWebFlux()
* WebClient client = WebClient.create("http://localhost:8080");

## Spring Data Reactive
* MongoDB
    * Document-georiënteerde databank (JSON)
* Cassandra
    * Mix tussen key-value store en databank gebruikmakend van tabellen (wide column store)
* Redis
    * In-memory key-value database
* NoSql databases