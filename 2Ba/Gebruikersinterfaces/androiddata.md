# Android - data

## Coroutines
* runBlocking blokkeert de huidige thread (spaarzaam gebruiken) tot alle coroutines zijn afgerond
* launch start nieuwe coroutine
* delay suspends een functie
* async: job met resultaat starten
* coroutineScope: meerdere jobs starten
* await: wachten op resultaat job
* cancel: job stoppen
* join: wachten op job
* Foutafhandeling met try – catch – final

## Android Threading Rules
* Blokkeer de UI-Thread niet
* Geen toegang tot de UI toolkit buiten de UI-Thread

## Dispatchers
* Taken die veel tijd vragen in een aparte Thread

## Webservices
* Interface voor service
* voorzie een @GET(pad) met suspend-functie
* serialiseerbare data klasse voorzien @Serializable
* Retrofit Builder voorzien -> addConverter -> baseUrl -> build
* Service gebruiken in ViewModel
* Foutafhandeling voorzien!

## Room - Entity
* Entity-klasse
* Entity-object
* Room is een Singleton
