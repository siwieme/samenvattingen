# Android levensloop
<img src="https://i.ibb.co/sC5TnSM/afbeelding.png">

## Structuur van de activiteitsklasse
* Nooit zelf oproepen!
* onCreate() => activiteit geladen, maar inactief!
* Loggen in Logcat: Log.
    * d: debug
    * e: error
    * w: warn
    * i: info
    * v: verbose
* onStart() => activiteit wordt op zijn minst gedeeltelijk zichtbaar
* onResume() => activiteit wordt volledig zichtbaar en heeft de focus
* onPause() => onderbroken activiteiten kunnen gedurende langere tijd volledig zichtbaar zijn wanneer de gebruiker zich in de modus met meerdere vensters bevindt
    * Maakt elke beweging uit onResume() ongedaan
* onStop() => activiteiten niet meer zichtbaar voor de gebruiker
    * Alles ongedaan maken wat opgezet was in onStart()
* onRestart() => opgeroepen na onStop() en voor onStart()
* onDestroy() => verwijderen activiteit

## rememberSaveable-delegate
* Bewaart waarden in een Bundle-object bij het vernietigen en hermaken van de activiteit

<div style="page-break-after: always;"></div>

## Architecturale principes
- Scheiding van verantwoordelijkheden (separation of concerns)
- Genereer UI op basis van datamodellen
- Eén bron van waarheid (Single Source of Truth)
- Eenrichtingsgegevensstroom (Unidirectional Data Flow)

## UI State
* Onveranderbaar

## StateFlow<T> versus MutableState<T>
* StateFlow
    * Observeerbare objecten
    * Waarde verandert -> observers verwittigd
* MutableState
    * Houdt waarde bij
    * Waarde verandert -> recomposition betrokken componenten
* UI abonneren op status: .collectAsState()

## Kort samengevat
<img src="https://i.ibb.co/D4ZRx46/afbeelding.png" style="width: 50%">

## Tijdelijke navigatie
* Back knop => tijdelijke navigaite (chronologie van de bezochte activiteiten)
* Opwaartse navigatie => ouderactiviteit gedeclareerd in het manifest-bestand van de app

## Verwijderen instanties
* Als het geheugen volloopt, zal het OS activiteiten verwijderen, maar als de activiteit terug aan de top van de backstack komt, wordt ze opnieuw aangemaakt

<div style="page-break-after: always;"></div>

## Navigatie in code 
* Bestemmingen: verschillende schermen
* NavHost: lege container toont bestemming
* Routes: mogelijke paden
* NavController: realiseert navigatie tussen bestemmingen

## Intents
* Actie van een andere app vragen
* Drie types
    * Een andere activiteit starten
    * Een service starten
    * Broadcast: bericht uitsturen dat elke app kan ontvangen