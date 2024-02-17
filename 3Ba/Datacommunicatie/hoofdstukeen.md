# Hoofdstuk 1: Inleiding

## Situering

* Evolutie - revolutie?

* Doel van communicatie
    * Uitwisselen van gegevens tussen twee of meer gebruikers die verbonden zijn via een geschikt transmissiesysteem
    * Transparant, efficiënt (in één keer), veilig, foutloos

* Kanaal brengt info of boodschap over
    * Zintuigelijk: horen, zien, voelen, ruiken, proeven
    * Mechanisch: pen, schrijfmachine ...
    * Elektronisch: telefoon, radio, TV, computer ...

* Ruis
    * Extern: lawaaierige discotheek
    * Intern: geëmotioneerd of zonder voorkennis
    * Overkill of information overload: te veel info

## Historiek

* Communicare (Latijn)
    * = iets met iemand delen
* telos (Grieks)
    * = einde, doel, afstand
* Data (Latijn)
    * = gegeven zijnde
* Telecommunicatie
    * = het op afstand iets delen met iemand
* Datacommunicatie
    * = iets gegeven zijnde met iemand delen
* Digitale communicatie
    * 1834: EMtelegraaf (Gauss, Weber): vanop afstand magnetiseren, ferromagneet
    * 1838: gecommercialiseerd door Cooke en Wheatstone (Londen)
    * 1844: telegraaflijn (Morse)
        * Aan- en uitschakelen van stroom in bepaald patroon
    * 1919: teletype of 'verreschrijver' (Krum)
        * Nu telex (Teletyping Exchange) genaamd
        * Uitwisselen van getypte teksen a rato van 50 bit/s
* Analoge communicatie
    * 1876: telefoon (Bell)
    * Jaren '20 vorige eeuw: telefooncentrales
* Draadloze communicatie
    * 1900: trans-Atlantisch (Marconi)
    * 1905: spraak & muziek via radio (Fessenden)
    * 1920: commerciële AM-radio
    * 1927: commerciële FM-radio
    * 1962: Telstar 1
        * 60 telefoongesprekken of 1 TV-programma (B&W)

## Communicatiesysteem

* Betekenisvol voor minstens 1 gebruiker
    * Onvoorspelbaar, hangt af van belangstelling of intentie
    * 1 bit: kleinste hoeveelheid info die verstuurd kan worden
* Overgedragen info: tekst, spraak, muziek, beeld, data ...
* Overdracht door elektromagnetische signalen
    * Geleid: koper, coax, glasvezel
    * Niet-geleid: draadloos
* Hoeveel IP-verkeer in de wereld?
    * 2018: 1.6 zetta (10^21) bytes
    * 2024: 4.8 zetta bytes
        * Meer trafiek dan in 32 jaar internetgeschiedenis

Informatiebron -> Zender -> Transmissiekanaal -> Ontvanger -> Informatiebestemming

* Storingsbron kan overal optreden
* Bron = leverancier van info
* Zender
    * Datareductie: elimineren van niet-relevante info = **transparant**
    * Broncodering/datacompressie: redundantie verwijderen = **efficiënt**
    * Vercijfering of beveiliging = **veilig**
    * Kanaalcodering: extra info -> nadien verwijderen fouten = **foutloos**

Informatiebron -> *Datareductie -> Broncodering -> Vercijfering -> Kanaalcodering* -> **Modulatie -> Continu kanaal -> Demodulatie** -> ***Kanaaldecodering -> Ontcijfering -> Brondecodering -> Datareconstructie*** -> Informatiebestemming

* *Zender* en **Discreet kanaal** en ***Ontvanger***

## Types communicatie

* Geografische spreiding
    * Peer-to-peer: van 1 punt naar ander punt
        * Telefonie
    * Broadcasting: van 1 punt naar alle andere punten
        * Radio, TV (massamedia)
    * Multicasting: van 1 punt naar een beperkt aantal andere punten
        * Via abonnementen
* Communicatierichting
    * Simplex: 1 richting
        * Radio, TV
    * Half-duplex: 2 richtingen, maar niet tegelijk
        * Walkie-talkie
    * Full-duplex: 2 richtingen tegelijk
        * Telefoon
* Manier van schakelen
    * Circuit: telefonie (manueel -> mechanisch -> elektronisch)
        * Fysisch pad tussen zender en ontvanger
        * Schakeltijd = verloren (trans-Atlantisch: +/- 10 s)
        * Nadien enkel propagatietijd
    * Bericht: telegram
        * Tussendoor stockeren (opslagcapaciteit !)
        * wachten tot volledig, alvorens verder te verzenden
    * Packet: internet
        * Bovengrens aan berichten: splitsen
        * 2e pakket al zenden alvorens 1e ontvangen
* Topologie: verbinden meerdere punten
    * Ster
    * Boom
    * Ring
    * Bus
    * Maas (mesh)
    * Mengvormen !!

## OSI-referentiemodel

* Ontwerpen & opzetten communicatiesysteem niet simpel
    * Referentiemodel: 7-lagenmodel
    * OSI (Open Systems Interconnect)
    * ISO (International Standards Organization)

* Laag 1: Fysische laag
    * Elektromagnetische signalen
    * Kabels, connectoren, ...
* Laag 2: Datalinklaag
    * Hoe data op fysische laag
    * Bitpatroon
* Laag 3: Netwerklaag
    * Routing
    * IP
    * Bericht van juiste zender naar juiste ontvanger
* Laag 4: Transportlaag
    * Hoe info over netwerk
    * Juiste volgorde pakketten
* Laag 5: Sessielaag
    * Start, beheert & stopt communicatie
* Laag 6: Presentatielaag
    * (De)coderen van data
* Laag 7: Applicatielaag
    * Link met applicatie

* Op elk niveau (abstracte) verbinding
    * Gateway op transportlaag
    * Router op netwerklaag
    * Bridge op datalinklaag
    * Repeater op fysische laag
* Niet altijd volledig gevolgd
    * TCP/IP-model: 4 lagen
        * Geen aparte presentatielaag & sessielaag
        * Internetlaag ipv netwerklaag
    * Functieblokken op hoger niveau: OSI-laag 8
        * Hoe toepassing juist implementeren?