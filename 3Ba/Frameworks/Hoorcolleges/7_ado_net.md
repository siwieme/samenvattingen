# ADO.NET

* Opvolger ADO (Activex Data Objects)
* Toegang vanuit een .NET-programma tot een gegevensbron
    * Ophalen, manipuleren en aanpassen gegevens
* Databronnen
    * Gegevensbanken
    * XML-documenten, XML-streams
* Principes
    * Losse koppeling tussen applicatie en databron is mogelijk
        * Stuk van de gegevens in de applicatie bijhouden en manipuleren zonder telkens terug te koppelen naar de gegevensbron
        * Vlotte overgang naar XML

## Architectuur

<img src="https://img001.prntscr.com/file/img001/L76UssPPRbCu2cmhZVbsCA.png">

## DataSet

### Aanmaak DataSet en DataTable
* Aanmaak DataSet
```cs
DataSet gegevens = new DataSet();
DataSet klantDS = new DataSet("KlantOrders");
```
* Aanmaak DataTable
```cs
DataTable bestellingen = klantDS.Tables.Add("Bestellingen");
bestellingen = klantDS.Tables["Bestellingen"];
bestellingen = klantDS.Tables[0];
```
### Aanmaak Kolommen
* Aanmaak Kolommen
```cs
DataColumn bestelId = bestellingen.Columns.Add("BestelID",typeof(Int32));
bestellingen.Columns.Add("Hoeveelheid", typeof(Int32));
bestellingen.Columns.Add("Firma", typeof(string));
```
* Beperkingen: sleutels
```cs
bestellingen.PrimaryKey = new DataColumn[] {bestelId};
```
### Tabel opvullen
```cs
// nieuwe rij
DataRow rijBestelling = bestellingen.NewRow();
// opvullen rij
rijBestelling[bestelID] = 3145;
rijBestelling["Hoeveelheid"] = 3;
rijBestelling[2] = "Mijn Bedrijf";
// rij toevoegen aan tabel
bestellingen.Rows.Add(rijBestelling);
```

## DataProviders

<img src="https://img001.prntscr.com/file/img001/ef8siC8iRManB5GqLMd30Q.png">

## Sleutelobjecten

* Connection (verbinding te maken)
* Command (opdrachten uit te voeren)
* DataReader (gegevens ophalen)
* DataAdapter (koppeling DataSet en gegevensbank)

## Basiswerking

| .Net Data Provider | JDBC-driver                                     |
|--------------------|-------------------------------------------------|
| DbProviderFactory  | ~= DriverManager                                |
| (I)DbConnection    | Connection                                      |
| (I)DbCommand       | Statement, PreparedStatement, CallableStatement |
| (I)(Db)DataReader  | ResultSet                                       |

* Configuratiegegevens inlezen
    * Configuratiebestand
        * Applicaties
            * App.config
        * Webapplicaties
            * Web.config
    * Klasse ConfigurationManager
        * Ophalen configuratie
        * String opdracht = ConfigurationManager.AppSettings["SELECT_BESTEL"];
        * ConnectionStringSettings connStringSet = ConfigurationManager.ConnectionStrings["bestellingen"];
        * ```xml
            <configuration>
            <appSettings>
                <add key="SELECT_BESTEL" value="select * from Bestellingen"/>
            </appSettings>
            <connectionStrings>
                <add name="bestellingen" providerName="System.Data.SqlClient" connectionString="..."/>
            </connectionStrings>
            </configuration>
            ```
* Factory voor de provider aanmaken 
    * Maakt ADO.NET-objecten voor een bepaalde provider
        * Connecties, commando's, parameters, data-adapters
        * DbProviderFactory factory = DbProviderFactories.GetFactory(connStringSet.ProviderName);
* Connectie-object aanmaken
```cs
DbProviderFactory factory = ... ;
ConnectionStringSettings connStringSet = ... ;
DbConnection connection = factory.CreateConnection();
connection.ConnectionString = connStringSet.ConnectionString;
```
    * Connectiestring
        * Naam/waarde-paren gescheiden door ';'
        * Afhankelijk van databanktype
        * Namen:
            * Server of Data Source
            * Database
            * AttachDbFilename
            * Password of Pwd
            * User ID
            * Integrated Security of Trusted_Connection (false: User ID & Password)
            * Connect Timeout
            * Provider (verplicht bij OleDbConnection)

* Commando-object aanmaken
```cs
DbConnection conn = ... ;
// aanmaken commando-object
DbCommand command = conn.CreateCommand();
// instellen SQL-opdracht
command.CommandText =
ConfigurationManager.AppSettings["SELECT_BESTELLINGEN"];
```
* Commando-object uitvoeren (eventueel DataReader overlopen)
```cs
using (DbConnection conn = ...) {
... // configuratie connectie + aanmaken commando-object
conn.Open(); // Connectie openen
// commando-object uitvoeren
// delete-, insert-, update-opdracht of DDL
int aantRijenAangepast = command.ExecuteNonQuery();
...
// select-opdracht
DbDataReader reader = command.ExecuteReader();
...
} // Connectie sluiten
``` 
* Zoekopdrachten: DataReader
    * Leest gegevens van een databron
    * Eén keer lezen van begin tot einde
    * Afhankelijk van .Net Data Provider
        * SqlDataReader
        * OleDbDataReader
        * ...
    * Resultaat ExecuteReader (Command-object)
    * Voorbeeld: 
    ```cs
    using (DbConnection conn = ...) {
    ... // configuratie connectie + aanmaken commando-object
    conn.Open(); // Connectie openen
    // commando-object uitvoeren
    // delete-, insert-, update-opdracht of DDL
    int aantRijenAangepast = command.ExecuteNonQuery();
    ...
    // select-opdracht
    DbDataReader reader = command.ExecuteReader();
    ...
    } // Connectie sluiten
    ```
    * Methodes
        * Read(): verplaatst de cursor één rij naar beneden
        * GetXxx(int volgnummer)
            * Xxx is een type zoals String, Int ...
            * Haalt de gegevens van de kolom bepaald door volgnummer
        * Close(): sluit reader
    * Indexer
        * Argument: naam of volgnummer kolom

* DataAdapter
    * Alternatieve wijze om om te gaan met gegevensbanken in een applicatie: lossere koppeling
        * Ophalen nodige gegevens en bewaren in DataSet
        * Manipuleren DataSet
        * Wijzigingen doorvoeren op gegevensbank
    * DataAdapter: brug tussen DataSet en gegevensbank
        * Opvullen DataSet
        * Wijzigen onderliggende databron    
    * Object aanmaken
        * Openen verbinding gegevensbank
        * Query uitvoeren en resultaat bewaren als een tabel van de DataSet (met opgegeven naam)
        * Sluiten verbinding gegevensbank
        * ```cs // adapter aanmaken
            DbDataAdapter adapter = factory.CreateDataAdapter();
            // select-opdracht instellen: opvullen dataset
            DbCommand command = ...
            adapter.SelectCommand = command;
            // dataset opvullen
            DataSet klantDS = new DataSet(DS_ORDERS);
            adapter.Fill(klantDS,TABEL_BESTELLING);```
    * Verschil DataReader en DataSet + DataAdapter
        * DataReader
            * Enkel resultaten tonen
            * Performanter
            * Wijzigingen worden onmiddellijk doorgevoerd in de gegevensbank
        * DataSet
            * Lokaal data bijhouden en bewerken
            * Handig in gebruik (bv. ASP.NET-pagina's)
            * Wijzigingen worden pas later doorgevoerd in de gegevensbank

## Zoekopdracht met parameter
* SQL-opdracht met parameter
    * Plaats parameter in SQL-opdracht aangeven
        * Met @naamParameter
        * Soms ook : of ?
* Parameter aanmaken en toevoegen aan commando
```cs
// aanmaken parameter
DbParameter parameter = factory.CreateParameter();
// eigenschappen parameter instellen
parameter.ParameterName = MIN;
parameter.DbType = DbType.Int32;
// toevoegen aan commando-object
opdracht.Parameters.Add(parameter);
// waarde instellen
int minimumAantal = ... ;
opdracht.Parameters[MIN].Value = minimumAantal;
```
* Parameter
    * SQL-opdracht met parameter uitvoeren
    * Herhaaldelijk uitvoer van dezelfde opdracht met andere waarden
    * Gegevensconversie
    * Voorkomen SQL-injectie
    * DbType
* Gegevensconversie
    * Zelfde als bij JDBC
* SQL-injectie
    * Zelfde als bij JDBC

## DataAdapter
### Principe
* Tabel toont gegevens van DataTable
* DataTable wordt veranderd in de loop van het programma
    * Deze veranderingen zijn niet definitief
        * Methode RejectChanges van DataRow
        * Oorspronkelijke rij wordt bijgehouden
    * De rij wordt gemarkeerd
        * Verwijderd
        * Aangepast
        * ...
        * Opsomming verschillende statussen: DataRowState
* DataAdapter
    * Opvullen DataTable
    * Aanpassingen DataTable doorvoeren in gegevensbank
        * Voor elke gemarkeerde rij wordt een opdracht uitgevoerd
    * Heeft 4 Command-objecten
        * SelectCommand, InsertCommand, UpdateCommand en DeleteCommand (eigenschappen)
        * Bepalen hoe wijzigingen aan de DataTable vertaald worden in de gegevensbank
    * Aanmaken DataAdapter
    * ```cs
        DbProviderFactory factory = ...;
        DbConnection conn = ...;
        DbDataAdapter adapter = factory.CreateDataAdapter();
        adapter.SelectCommand = MaakSelectCommand(conn);
        adapter.MissingSchemaAction = MissingSchemaAction.AddWithKey;
        adapter.InsertCommand = MaakInsertCommand(factory, conn);
        adapter.UpdateCommand = MaakUpdateCommand(factory, conn);
        adapter.DeleteCommand = MaakDeleteCommand(factory, conn);```
    * Aanmaken Command-Object
        * Naam
        * Type
        * Verbinden met een kolom in de DataTable
        * Aangeven welke versie gebruikt moet worden bij uitvoeren opdracht
        * ```cs
            param.ParameterName = "@naam";
            param.DbType = DbType.String;
            param.SourceColumn = "naam";
            param.SourceVersion = DataRowVersion.Current;```
    * Wijzigingen doorvoeren
        * Markeren van elke rij die toegevoegd, gewijzigd of verwijderd wordt
        * Ongedaan maken wijzigingen
            * Methode RejectChanges van DataRow
        * De methode Update van de DataAdapter past alle gemarkeerde rijen uit de DataTable aan in de gegevensbank
        * adapter.Update(*DataSet*);
    * Zoeken van een rij in een DataSet
        * De sleutels moeten ook opgehaald worden
            * Instellen in DataAdapter
        * DataRowCollection
            * Methode Find
                * Argument: object of tabel van objecten die de primaire sleutel voorstellen
                * Resultaat: DataRow horende bij de opgegeven primaire sleutel

## Transaction

* Verschillende gegevensbankopdrachten moeten samen uitgevoerd worden
* Verschillende stappen
    * Starten transactie: transactie-object
    * Transactie-object toekennen aan Command-objecten
    * Uitvoeren opdrachten
    * Commit - Rollback
* ```cs
    DbProviderFactory factory = ...;
    // verbinding met gegevensbank; transactie starten
    using (DbConnection conn = ...) {
        ...
        conn.Open();
        DbTransaction trans = conn.BeginTransaction();
        ...
        // commando aanmaken en toevoegen aan transactie
        DbCommand opdracht = conn.CreateCommand();
        opdracht.Transaction = trans;
        opdracht.CommandText = "insert into Region (RegionID, RegionDescription) VALUES (@id, @description)";
        ...
    }
    ```