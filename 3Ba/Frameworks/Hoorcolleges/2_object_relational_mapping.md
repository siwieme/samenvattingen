# Object Relational Mapping (ORM)

## Algemeen
* Applicatie
    * Software
        * Objecttechnologie (Java, C# ...)
    * Data
        * Relationele gegevensbanken
* Afbeelding (mapping) tussen
    * Data in objecten
    * Data in tabellen

## Verschil OO-concepten en relationele databanken: types vs tabellen

### Identiteit
Wanneer zijn twee entiteiten hetzelfde?
* DB: bepaald door primaire sleutel
* OO: Zelfde referentie of resultaat equals-methode
* Geen corresponderende eigenschap in domeinmodel
    * Besmetten domeinmodel met extra attribuut
* Automatisch gegenereerde sleutel
    * Vergelijken objecten enkel mogelijk indien toegevoegd aan DB
* Object-identiteit is moeilijker te mappen naar record-identiteit
* Schaduwinformatie
    * Shadow Information
    * Data
        * Nodig om informatie te bewaren (in DB)
            * Bv. Primaire sleutel
        * Geen deel van business model

### Relaties
* 1-veel
    * Unidirectioneel
        * Met foreign key
        * **@ManyToOne**
        * **@JoinColumn(name="naam")**
        * Verwijssleutel naar geassocieerde entiteit
    * Bidirectioneel
        * Met foreign key
        * De tabel die we koppelen met JoinColumn krijgt volgende annotatie
            * **@OneToMany(mappedBy="naam")**
            * naam altijd bij @OneToMany, niet bij @ManyToOne
* Veel-veel
    * Unidirectioneel
        * **@ManyToMany**
        * **@JoinTable(name="naam_associatie_tabel", joinColumns=@JoinColumn(name="naam_kolom_verwijssleutel_entiteit"), inverseJoinColumns=@JoinColumn(name="naam_kolom_verwijssleutel°element_collectie"))**
    * Bidirectioneel
        * Met foreign key
        * De tabel die we koppelen met JoinColumn krijgt volgende annotatie
            * **@ManyToMany(mappedBy="naam")**
* 1-1
    * Unidirectioneel
        * Beide entiteiten delen dezelfde Primary Key
            * **@OneToOne()**
            * **@MapsId**
            * **@JoinColumn(name="naam")**
        * Een van beide entiteiten heeft een Foreign Key (met unique constraint)
            * **@OneToOne(optional=false)**
            * **@JoinColumn(name="naam", unique=true, nullable=false, updatable=false)**
    * Bidirectioneel
        * Met foreign key
        * De tabel die we koppelen met JoinColumn krijgt volgende annotatie
            * **@OneToOne(mappedBy="naam")**
* Relaties en cascade
    * Actie op entiteit leidt tot actie op entiteit in relatie?
    * Attribuut cascade:
        * ALL
        * DETACH
        * MERGE
        * PERSIST
        * REFRESH
        * REMOVE: ouder weg, kind weg


### Overervering
* Hoe?
    * Volledige hiërarchie naar één tabel
        * Nadelen:
            * Verplichte velden niet mogelijk
            * Moeilijk uitbreidbaar
        * Annotaties:
            * **@Inheritance(strategy=InheritanceType.SINGLE_TABLE)**
            * **@DiscriminatorColumn(name="naam",discriminatorType=DiscriminatorType.TYPE)**
            * Per klasse: **@DiscriminatorValue("WAARDE")**
    * Elke klasse naar een tabel
        * Annotaties:
            * **@Inheritance(strategy=InheritanceType.JOINED)**
            * Per klasse: **@PrimaryKeyJoinColumn(name="naam")**
            * Efficiënter? DiscriminatorColumn & Value toevoegen
    * Elke concrete klasse naar eigen tabel
        * Nadelen:
            * Refactoring moeilijker
        * Annotaties:
            * **@Inheritance(strategy=InheritanceType.TABLE_PER_CLASS)**  

## ORM in Java
* JPA (Java Persistence API)
* Mapping tussen klassen en tabellen met annotaties
* Dataklassen
    * Moeten JavaBeans zijn
        * Defaultconstructor
        * Getters en setters voor eigenschappen
        * **@Entity** en **@Table(name="naam")**
* Entity
    * Entiteit
    * Beheerd door JPA-framework
    * Linkt klasse aan tabel
        * Attribuut name: tabelnaam
        * Optioneel
    * Object wordt gemapt op een record/rij
* ID
    * Vereist
        * Samengestelde sleutels KAN, maar weinig gebruikt
    * **@Id**
    * **@GeneratedValue(strategy=GenerationType.STRATEGY)**
    * STRATEGY
        * AUTO: gebaseerd op het type van het attribuut
        * IDENTITY: soort van auto-increment
        * SEQUENCE: nog een GenericGenerator nodig
        * TABLE: nog een TableGenerator nodig
* Mapping Object op Tabel
    * Eigenschap van een object worden nul of meerdere kolommen
        * Nul: info moet niet bewaard worden
        * Meer dan één?
            * Eigenschap = object
* Mapping Eigenschap op Kolom
    * **@Basic**
        * Primitieve types
        * Optioneel
    * **@Column**
        * Name-attribuut = kolom in een tabel
        * Optioneel
    * **@Transient**
        * Niet bewaren

# JPA

## Configuratie

<img src="https://www.tutorialspoint.com/jpa/images/jpa_class_level_architecture.png">

<img src="https://www.npersistence.org/sites/default/files/image/homePage/jpaarchitecture.jpg">

* in pom.xml de goede dependency toevoegen

## Entiteiten
* Annotaties
    * Boven getter
    * Boven attribuut
    * Consistent (beide werkwijzen NIET combineren)

## Repository
* CRUD-operaties voor entiteiten
* Interface: Spring genereert de implementatie
* JpaRepository

## JpaRepository
* Objecten bewaren: .save(...)
* Alle objecten opvragen: .findAll()
* Een object ophalen op id: .findById(id)
* Aanpassingen doorsturen naar database: .flush()
* Meerdere entiteiten bewaren of aanpassen: .saveAll()
* Aantal entiteiten: .count()
* Eén of meerdere entiteiten verwijderen: .delete() en .deleteAll()
* Bestaat er een entiteit met de gegeven id: .existById()

## Extra zoekmethodes
* Zelf een functie definiëren in de interface

## Werking
* EntityManager
    * Beheert entities in een "persistence context"
        * Container
        * Applicatie

<img src="https://harinathreddyyanamala.files.wordpress.com/2015/03/jpa_entity_lifecycle.gif">

* Objecten persistent maken
    * Methode persist van EntityManager
    * Object toevoegen aan databank
        * Persistent maken
        * Indien transactie uiteraard
    * Indien unieke id niet gegenereerd
        * Toekennen voor persistent maken

* Objecten opvragen
    * Op basis van identifier
        * Methode find van EntityManager
    * Lazy Fetching
        * Geassocieerde objecten niet mee opvragen
        * Opgevraagd indien nodig & enkel indien sessie nog open is
        * Tenzij anders vermeld

* Objecten verwijderen
    * Methode remove van EntityManager
    * Cascade instellen indien gewenst

* Objecten wijzigen
    * Persistente objecten
        * Aangemaakt via persist
        * Opgehaald via find of een zoekopdracht
    * Wijzigen tijdens een transactie
        * Methode flush

* Merge
    * Methode merge van EntityManager
        * Het meegegeven object in de huidige persistentiecontext kopiëren
        * Resultaat = object uit persistentiecontext
    * Enkel nodig bij doorgeven objecten tussen contexten

* Objecten wijzigen
    * Detached objecten
        * Objecten aangemaakt door andere/niet meer bestaande entiteitmanagers
        * Cascade instellen

* Entity Locking/Concurrency
    * Gelijktijdige toegang
        * Dataintegriteit bewaren
    * Standaard
        * Optimistic locking
        * Voor aanpassen kijken of data niet veranderd is aan de hand van versiekolom
    * Pessimistic locking
        * Transactie legt lock op data zolang de transactie loopt

# Associaties
* Richting
    * Unidirectioneel
    * Bidirectioneel (moeilijk om actueel te houden)
    * Multipliciteit
        * 1-op-1
        * 1-op-veel
        * Veel-op-veel

<img src="https://i.ibb.co/s5jZB4Y/afbeelding.png">

* Mapping associaties value-object
    * Annotaties:
        * **@ElementCollection**
        * **@CollectionTable(name="naam",joinColumns=@JoinColumn(name="naam"))**
    * Set, List: **@ElementCollection**
    * **@CollectionTable**
        * Koppeling tabel object en tabel instantievariabele
    * **@AttributesOverrides**
        * Mapping eigenschappen element uit collection op kolommen
        * **@AttributeOverride**
            * Eigenschap element op kolom