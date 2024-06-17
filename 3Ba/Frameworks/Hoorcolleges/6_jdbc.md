# JDBC

## Wat is JDBC?

* Toegang tot relationele data vanuit Java
* SQL-compatibele relationele gegevensbanken
* Een API om SQL-statements uit te voeren en de verkregen resultaten te verwerken
* Abstractie van productafhankelijke details
    * Veralgemening meest voorkomende gegevensbankfuncties
    * Applicatie bruikbaar met verschillende gegevensbanken

## JDBC Drivers - Types

<img src="https://i.ibb.co/mtLMx4d/afbeelding.png">

* JDBC Core API: *java.sql*
    * Gegevensbankverbinding via JDBC-drivers
    * Basis SQL-operaties uitvoeren
    * Bij alle versies van Java
* JDBC Optional Package API: *javax.sql*
    * Voor application servers
        * DataSource in plaats van Driver
    * Beheer en pooling van JDBC-connecties, gedistribueerde transacties ...
    * Standaard bij JSDK vanaf V1.4

## Basiswerking

* Configuratiegegevens inlezen
    * .properties-bestand
* Driver laden
    * Laden in JVM + registreren bij DriverManager
    * Niet meer nodig vanaf JDK 1.6
    * Driverklasse implementeert de interface *java.sql.Driver*
* Driverklasse toevoegen aan CLASSPATH
    * Niet meer nodig vanaf JDK 1.6
    * Driverklasse behoort niet tot de standaard Java API
    * Meegeleverd met de gegevensbank
        * .jar-bestand
    * Toevoegen aan CLASSPATH
        * Als omgevingsvariabele
        * Als optie bij het *java*-commando
        * IntelliJ: External Libraries
    * CLASSPATH
        * Standaard: huidige map
* Verbinding aanmaken
    * DriverManager
        * Toegang tot verschillende beschikbare drivers
        ```java
        private Connection geefVerbinding() throws SQLException {
            return DriverManager.getConnection(
                databaseConfig.getString("URL"),
                databaseConfig.getString("LOGIN"),
                databaseConfig.getString("PASWOORD"));
        }
        ```
        * JDBC URL
            * Vorm: ```jdbc:<subprotocol>://<subname>```
            * Subprotocol: identificeert gegevensbankdriver
                * MySql: *mysql*
                * Derby: *derby*
                * PostgreSQL: *postgresql*
            * Subname: afhankelijk van driver
                * MySql, Derby, PostgreSQL:
                    * host:poort/database
* Statement aanmaken
* Statement overlopen

### Statements

* Vuistregels
    * in een try-catch steken
    ```java
    try (Connection conn = ...; Statement stmt = conn.createStatement()) {
        // opdrachten uitvoeren
        // kan ook PreparedStatement of CallableStatement zijn
    } catch (SQLException e) {
        // foutafhandeling
    }
    ```
* "Gewone statements"
    * Select-opdracht uitvoeren
        * in een ResultSet steken
        * .executeQuery("query")
        * Query kan opgehaald worden uit een .properties-bestand
        * ResultSet rs = stmt.executeQuery(...);
    * Resultaten ophalen
        * Interface ResultSet
            * Resultaat één keer van boven naar beneden overlopen
            * **Kolommen tellen vanaf index 1, niet 0**
            * Resultaten worden mogelijks niet allemaal tegelijk opgehaald
            * Conversie SQL-type naar Java-type
            * .getXXX(int kolomnummer) of .getXXX(string kolomnaam)
            * XXX = type: getInt, getDouble, getString ...
    * JDBC Types
        * Java - SQL
            * String - CHAR, VARCHAR
            * double - DOUBLE
            * int - INTEGER
            * float - REAL
            * ...
    * Andere opdrachten uitvoeren
        * .executeUpdate("opdracht")
        * Opdracht kan opgehaald worden uit een .properties-bestand 
* Prepared Statements
    * SQL-opdrachten met parameters
    * Voorgecompileerd in gegevensbank
    * Opdrachten die verschillende keren uitgevoerd moeten worden
    * Reductie uitvoertijd
    * Veililgheid
        * Gegevensconversie
        * Voorkomen SQL-injectie
     ```java
    try (Connection conn = ...; PreparedStatement stmt = conn.prepareStatement("QUERY")) { // kan opgehaald worden uit .properties-bestand
        // opdrachten uitvoeren
        // kan ook PreparedStatement of CallableStatement zijn
    } catch (SQLException e) {
        // foutafhandeling
    }
    ```
    * Parameter
        * Vermijden problemen met aanhalingstekens
        * “select * from studenten where naam = ?”; zal goed werken
        * “select * from studenten where naam = \’” + naam + “\’”; zal minder goed werken met een naam zoals "D’Haese"
        * Waarom werkt het beter?
            * Opdracht wordt gecompileerd met parameter
            * Bij uitvoeren
                * Parameter doorsturen
                * Parameters worden geconverteerd naar juiste type
                * Parameters zijn argumenten voor gecompileerde functie
    * SQL-injectie
        * Meestal in een webapplicatie
        * Gebruiker
            * Parameter ingeven
            * Combineert parameter met SQL-opdracht
                * Injecteert SQL-opdrachten
                    * Niet-toegankelijke gegevens bekijken
                    * Gegevens verwijderen
            * Vb:
                * Opdracht: "select * from studenten where studnr = " + nummer;
                * Malafide ingave:
                    * 200200234 OR 1=1 (alle gegevens opvragen)
                    * 200200234; DROP TABLE Studenten (alle gegevens verwijderen)
                    * 0 UNION SELECT username, password FROM users (gebruikersnamen + wachtwoorden opvragen)
        * Voorkomen: gebruik parameters!
* Callable Statements
    * Nodig
        * Naam procedure (bv. SELECT_BOEKEN)
        * Parameters
    * Aanmaken CallableStatement
    ```java
    String opdracht = “{call SELECT_BOEKEN}”;
    CallableStatement cstmt = conn.prepareCall(opdracht);
    ```
    * Escape-syntax
        * Geen standaard SQL
        * Driver moet interpreteren of omzetten
    * Verwijzing naar procedure in de databank
    * Ook in een try-catch gooien
    * Parameters instellen is zoals bij Prepared
* Uitvoerparameters
    * Corresponderen met uitvoerparameters van de stored procedure
    * Methode
        * ? in de SQL-odpracht
        * Registreren
    * Voorbeeld Opdracht:
        * ? : aantal boeken
    ```java
    String opdracht = “{? = call SELECT_BOEKEN}”;
    String opdracht = “{call SELECT_BOEKEN(?)}”;
    ```
    * Registreren
        * Eerst ResultSet overlopen
        * ? : bepaalt NIET het type parameter (in- of uit-)
        ```java
        CallableStatement cstmt = conn.prepareCall(opdracht);
        cstmt.registerOutParameter(1, java.sql.Types.INTEGER);
        ResultSet rs = cstmt.executeQuery();
        ... // boeken ophalen
        int aantalBoeken = cstmt.getInt(1);```

### Transacties
* Verschillende rijen en/of tabellen tegelijkertijd aanpassen
* Consistente gegevens
* Data Integrity
    * Andere gebruikers zien pas aangepaste waarden als ze *definitief* zijn
* Principe
    * Auto-commit-mode uitschakelen
    * Opdrachten uitvoeren
        * Geslaagd? Commit
        * Gefaald? Rollback
    * Auto-commit-mode inschakelen
* Auto-commit-mode
    * Standaard aan
* Opmerking
    * Connection-object lokaal
    * Verschillende transacties
        * Verschillende Connection-objecten

## JDBC uitgebreid

### DataSource
* *java.sql*
    * Gebruikt Driver
* *javax.sql*
    * Gebruikt DataSource
* DataSource
    * Applicatieservers of frameworks zoals Spring
    * Representeert een DBMS
    * Aangemaakt en ter beschikking gesteld via configuratie
    * Beschikbaar via JNDI (Java Naming and Directory Interface) of Dependency Injection
    * Beter alternatief voor JDBC-driver
        * Geen driverklasse, gebruikersnaam en wachtwoord in code
        * Gebruik connection pool
        * Ondersteunt gedistribueerde transacties
    * Steunt op ofwel
        * JNDI
            * Naming service: naam ~ object
            * Direcotry service uitbreiding naming service
                * Object heeft attributen
                * Zoeken op objecten mogelijk
        * Dependency Injection
* Configuratie
    * In .properties-bestand
        * JDBC-url
        * Login
        * Wachtwoord
    * Nodige drivers ter beschikking stellen via bv. pom.xml
* Gebruik
    * Ophalen iva JNDI of Dependency Injection