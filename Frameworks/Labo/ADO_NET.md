# ADO.NET

## Configuratie

```xml
<configuration>
	<connectionStrings>
		<add name="classicmodelsDataBase"
			 providerName="System.Data.SqlClient"
			 connectionString="Data Source=(LocalDB)\MSSQLLocalDB;AttachDbFilename=C:\Users\vongenae\Documents\frameworks\serversideframeworks\labo\2021\labo_3\classicmodels.mdf;Integrated Security=True;Connect Timeout=30"/>
	</connectionStrings>
    <appSettings>
        <add key="SELECT_ALL_CUSTOMERS"
            value="select * from customers"/>
        <add key="INSERT_ONE_CUSTOMER"
            value="insert into customers (customerNumber,customerName,contactLastName,contactFirstName,
        phone,addressLine1,addressLine2,city,state,postalCode,country,
        salesRepEmployeeNumber,creditLimit) 
        values(@customerNumber,@customerName,@contactLastName,@contactFirstName,
        @phone,@addressLine1,@addressLine2,@city,@state,@postalCode,@country,
        @salesRepEmployeeNumber,@creditLimit)"/>
        <add key="SELECT_ORDERS_OF_CUSTOMER"
            value="select * from orders where customerNumber = @customerNumber"/>
    </appSettings>
</configuration>    
```

## DataStorage

* Afhankelijk of je met een DataTable of DataReader werkt, best een overkoepelende klasse 
* Bevat:
    * ConnectionStringSettings
    ```cs
    protected ConnectionStringSettings connectionStringSettings;
    connectionStringSettings = ConfigurationManager.ConnectionStrings["classicmodelsDataBase"];
    ```
    * DbProviderFactory
    ```cs
    protected DbProviderFactory dbProviderFactory;
    dbProviderFactory = DbProviderFactories.GetFactory(connectionStringSettings.ProviderName);
    ```
    * DbConnection
    ```cs
    protected DbConnection GetConnection()
    {
        DbConnection connection = dbProviderFactory.CreateConnection();
        connection.ConnectionString = connectionStringSettings.ConnectionString;
        return connection;
    }
    ```
    * Functie om een parameter te maken
    ```cs
    protected DbParameter MaakParameter(string parameternaam, object waarde)
    {
        DbParameter parameter = dbProviderFactory.CreateParameter();
        parameter.ParameterName = parameternaam;
        parameter.Value = waarde;

        // als je het type toch expliciet instelt:
        /*
        if (waarde is double)
        {
            parameter.DbType = DbType.Double;
        }
        else if(waarde is int)
        {
            parameter.DbType = DbType.Int32;
        }
        else if(waarde is String)
        {
            parameter.DbType = DbType.String;
        }
        */
        return parameter;
    }
    ```

## DataReaders

* Gebruikt de methodes van de moederklasse

### GET-methode

* Lijst aanmaken om opgevraagde objecten in op te slaan

```cs
public List<Customer> GetCustomers()
{
    List<Customer> list = new List<Customer>();
    using (DbConnection connection = GetConnection())
    {
        DbCommand command = connection.CreateCommand();
        command.CommandText = ConfigurationManager.AppSettings["SELECT_ALL_CUSTOMERS"];
        connection.Open();
        try
        {
            DbDataReader reader = command.ExecuteReader();
            while (reader.Read())
            {
                // Strings mogen null zijn in de database; dat veroorzaakt
                // geen problemen.
                // Maar int's en double's veroorzaken die wel!
                Customer c = new Customer();
                c.AddressLine1 = reader[ADDRESSLINE1].ToString();
                c.AddressLine2 = reader[ADDRESSLINE2].ToString();
                c.City = reader[CITY].ToString();
                c.ContactFirstName = reader[CONTACTFIRSTNAME].ToString();
                c.ContactLastName = reader[CONTACTLASTNAME].ToString();
                c.Country = reader[COUNTRY].ToString();
                if (!(reader[CREDITLIMIT] is DBNull))
                {
                    c.CreditLimit = (double)reader[CREDITLIMIT]; // double
                }
                c.CustomerName = reader[CUSTOMERNAME].ToString();
                /*if (!(reader[CUSTOMERNUMBER] is DBNull))
                {
                    c.CustomerNumber = (int)reader[CUSTOMERNUMBER]; // int
                }*/
                c.CustomerNumber = (int)reader[CUSTOMERNUMBER]; // int
                c.Phone = reader[PHONE].ToString();
                c.PostalCode = reader[POSTALCODE].ToString();
                if (!(reader[SALESREPEMPLOYEENUMBER] is DBNull))
                {
                    c.SalesRepEmployeeNumber = (int)reader[SALESREPEMPLOYEENUMBER];
                }
                c.State = reader[STATE].ToString();
                list.Add(c);
            }
        }
        catch (Exception e)
        {
            Console.WriteLine(e.StackTrace);
        }
    }
    return list;
}
```

### POST-methode

```cs
public void AddCustomer(Customer customer)
{
    using (DbConnection connection = GetConnection())
    {
        DbCommand command = connection.CreateCommand();

        command.CommandText = ConfigurationManager.AppSettings["INSERT_ONE_CUSTOMER"];

        // naam, value
        command.Parameters.Add(MaakParameter("@" + CUSTOMERNAME, customer.CustomerName));
        command.Parameters.Add(MaakParameter("@" + ADDRESSLINE1, customer.AddressLine1));
        command.Parameters.Add(MaakParameter("@" + ADDRESSLINE2, customer.AddressLine2));
        command.Parameters.Add(MaakParameter("@" + CUSTOMERNUMBER, customer.CustomerNumber));
        command.Parameters.Add(MaakParameter("@" + CONTACTFIRSTNAME, customer.ContactFirstName));
        command.Parameters.Add(MaakParameter("@" + CONTACTLASTNAME, customer.ContactLastName));
        command.Parameters.Add(MaakParameter("@" + PHONE, customer.Phone));
        command.Parameters.Add(MaakParameter("@" + CITY, customer.City));
        command.Parameters.Add(MaakParameter("@" + STATE, customer.State));
        command.Parameters.Add(MaakParameter("@" + POSTALCODE, customer.PostalCode));
        command.Parameters.Add(MaakParameter("@" + COUNTRY, customer.Country));
        command.Parameters.Add(MaakParameter("@" + SALESREPEMPLOYEENUMBER, customer.SalesRepEmployeeNumber));
        command.Parameters.Add(MaakParameter("@" + CREDITLIMIT, customer.CreditLimit));

        connection.Open(); // niet vergeten!!!
        
        try
        {
            command.ExecuteNonQuery();
        }
        catch (SqlException ex)
        {
            for (int i = 0; i < ex.Errors.Count; i++)
            {
                errorMessages.Append("Index #" + i + "\n" +
                    "Message: " + ex.Errors[i].Message + "\n" +
                    "LineNumber: " + ex.Errors[i].LineNumber + "\n" +
                    "Source: " + ex.Errors[i].Source + "\n" +
                    "Procedure: " + ex.Errors[i].Procedure + "\n");
            }
            Console.WriteLine(errorMessages.ToString());
        }
        catch (Exception ex)
        {
            Console.WriteLine(ex.Message);
        }
    }
}
```

### POST-methode (gebruik makend van een DbTransaction)

```cs
public void AddOrder(Order order)
{
    using (DbConnection connection = GetConnection())
    {
        connection.Open();

        DbTransaction transaction = connection.BeginTransaction();

        DbCommand command = connection.CreateCommand();
        command.Transaction = transaction;

        command.CommandText = ConfigurationManager.AppSettings["INSERT_ONE_ORDER"];
        command.Parameters.Add(MaakParameter("@" + ORDERNUMBER, order.Number));
        command.Parameters.Add(MaakParameter("@" + ORDERDATE, order.Ordered));
        command.Parameters.Add(MaakParameter("@" + REQUIREDDATE, order.Required));
        command.Parameters.Add(MaakParameter("@" + SHIPPEDDATE, order.Shipped));
        command.Parameters.Add(MaakParameter("@" + STATUS, order.Status));
        command.Parameters.Add(MaakParameter("@" + COMMENTS, order.Comments));
        command.Parameters.Add(MaakParameter("@" + CUSTOMERNUMBER, "" + order.CustomerNumber));


        try
        {
            command.ExecuteNonQuery();
            int i = 0;
            foreach (OrderDetail detail in order.Details)
            {
                i++;
                DbCommand commandExtra = connection.CreateCommand();
                commandExtra.Transaction = transaction;

                commandExtra.CommandText = ConfigurationManager.AppSettings["INSERT_ORDERDETAILS"];
                commandExtra.Parameters.Add(MaakParameter("@" + ORDERNUMBER, detail.OrderNumber));
                commandExtra.Parameters.Add(MaakParameter("@" + ORDERLINENUMBER, detail.OrderLineNumber));
                commandExtra.Parameters.Add(MaakParameter("@" + PRICEEACH, detail.Price));
                // Hoe controleer je of de foutopvang goed is?
                // ANTWOORD:
                // Ik haal DE REGEL CODE HIERONDER weg, zodat er een fout ontstaat 
                // - controleer dat Order zelf NIET werd toegevoegd!!
                // Of, als het via unit test moet: je voegt een detail toe waarvan productcode in
                // main niet ingevuld is.
                commandExtra.Parameters.Add(MaakParameter("@" + PRODUCTCODE, detail.ProductCode));
                commandExtra.Parameters.Add(MaakParameter("@" + QUANTITYORDERED, detail.Quantity));
                commandExtra.ExecuteNonQuery();
            }
            transaction.Commit();
        }
        catch (SqlException ex)
        {
            transaction.Rollback();
            for (int i = 0; i < ex.Errors.Count; i++)
            {
                Console.WriteLine(ex.Errors[i].Message);
            }
        }
        catch (Exception ex)
        {
            transaction.Rollback();
            Console.WriteLine(ex.Message);
        }
    }
}
```

## DataTable

* DataTable als instantievariabele toevoegen
* (Custom) DataAdapter toevoegen als instantievariabele

### Custom DataAdapter

```cs
class CustomersTableDao
{
    private DbDataAdapter adapter;

    public CustomersTableDao(DbProviderFactory factory, DbConnection connection)
    {
        adapter = factory.CreateDataAdapter();
        adapter.MissingSchemaAction = MissingSchemaAction.AddWithKey;
        StelSelectCommandIn(connection, factory);
        StelInsertCommandIn(connection, factory);
        StelUpdateCommandIn(connection, factory);
        StelDeleteCommandIn(connection, factory);
        // We willen echt niet alles deleten... 
        // maar van zodra we één rij weghalen, moet het deleteCommand ingesteld zijn!
    }


    private void StelSelectCommandIn(DbConnection connection, DbProviderFactory factory)
    {
        adapter.SelectCommand = connection.CreateCommand();
        adapter.SelectCommand.CommandText = ConfigurationManager.AppSettings["SELECT_ALL_CUSTOMERS"];
    }

    private void StelInsertCommandIn(DbConnection connection, DbProviderFactory factory)
    {
        adapter.InsertCommand = connection.CreateCommand();
        adapter.InsertCommand.CommandText = ConfigurationManager.AppSettings["INSERT_ONE_CUSTOMER"];
        StelGrosVanParametersInVoorCommand(adapter.InsertCommand, factory);
        adapter.InsertCommand.Parameters.Add(CrParam("@" + DataStorage.CUSTOMERNUMBER, DbType.String, DataStorage.CUSTOMERNUMBER, DataRowVersion.Current, factory));
    }

    private void StelDeleteCommandIn(DbConnection connection, DbProviderFactory factory)
    {
        adapter.DeleteCommand = connection.CreateCommand();
        adapter.DeleteCommand.CommandText = ConfigurationManager.AppSettings["DELETE_CUSTOMER_WITH_NUMBER"];
        adapter.DeleteCommand.Parameters.Add(CrParam("@" + DataStorage.CUSTOMERNUMBER, DbType.String, DataStorage.CUSTOMERNUMBER, factory));
    }

    // De tekst van updateCommand includeert ALLE kolommen,
    // ook diegene die in dat specifieke geval niet gewijzigd moeten worden.
    // Maar dan cover je tenminste alle soorten aanvragen. 
    // (Zie DataStorageMetDataTable.ZetWijzigingenKlaarVoorCustomer)
    private void StelUpdateCommandIn(DbConnection connection, DbProviderFactory factory)
    {
        adapter.UpdateCommand = connection.CreateCommand();
        adapter.UpdateCommand.CommandText = ConfigurationManager.AppSettings["UPDATE_CUSTOMER_WITH_NUMBER"];
        StelGrosVanParametersInVoorCommand(adapter.UpdateCommand, factory);
        adapter.UpdateCommand.Parameters.Add(CrParam("@" + DataStorage.CUSTOMERNUMBER, DbType.String, DataStorage.CUSTOMERNUMBER, DataRowVersion.Original, factory));
    }

    private void StelGrosVanParametersInVoorCommand(DbCommand command, DbProviderFactory factory)
    {
        command.Parameters.Add(CrParam("@" + DataStorage.ADDRESSLINE1, DbType.String, DataStorage.ADDRESSLINE1, DataRowVersion.Current, factory));
        command.Parameters.Add(CrParam("@" + DataStorage.ADDRESSLINE2, DbType.String, DataStorage.ADDRESSLINE2, DataRowVersion.Current, factory));
        command.Parameters.Add(CrParam("@" + DataStorage.CITY, DbType.String, DataStorage.CITY, DataRowVersion.Current, factory));
        command.Parameters.Add(CrParam("@" + DataStorage.CONTACTFIRSTNAME, DbType.String, DataStorage.CONTACTFIRSTNAME, DataRowVersion.Current, factory));
        command.Parameters.Add(CrParam("@" + DataStorage.CONTACTLASTNAME, DbType.String, DataStorage.CONTACTLASTNAME, DataRowVersion.Current, factory));
        command.Parameters.Add(CrParam("@" + DataStorage.COUNTRY, DbType.String, DataStorage.COUNTRY, DataRowVersion.Current, factory));
        command.Parameters.Add(CrParam("@" + DataStorage.CREDITLIMIT, DbType.Double, DataStorage.CREDITLIMIT, DataRowVersion.Current, factory));
        command.Parameters.Add(CrParam("@" + DataStorage.CUSTOMERNAME, DbType.String, DataStorage.CUSTOMERNAME, DataRowVersion.Current, factory));
        //command.Parameters.Add(CrParam("@" + DataStorage.CUSTOMERNUMBER, DbType.String, DataStorage.CUSTOMERNUMBER));
        command.Parameters.Add(CrParam("@" + DataStorage.PHONE, DbType.String, DataStorage.PHONE, DataRowVersion.Current, factory));
        command.Parameters.Add(CrParam("@" + DataStorage.POSTALCODE, DbType.String, DataStorage.POSTALCODE, DataRowVersion.Current, factory));
        command.Parameters.Add(CrParam("@" + DataStorage.SALESREPEMPLOYEENUMBER, DbType.Int32, DataStorage.SALESREPEMPLOYEENUMBER, DataRowVersion.Current, factory));
        command.Parameters.Add(CrParam("@" + DataStorage.STATE, DbType.String, DataStorage.STATE, DataRowVersion.Current, factory));

    }

    private DbParameter CrParam(string parameterName, DbType type, string column, DbProviderFactory factory)
    {
        DbParameter parameter = factory.CreateParameter();
        parameter.ParameterName = parameterName;
        parameter.DbType = type;
        parameter.SourceColumn = column;
        return parameter;
    }
    private DbParameter CrParam(string parameterName, DbType type, string column, DataRowVersion version, DbProviderFactory factory)
    {
        DbParameter parameter = CrParam(parameterName, type, column, factory);
        parameter.SourceVersion = version;
        return parameter;
    }

    // haalt enkel uit de databank, zonder te updaten
    public DataTable GetCustomersWithoutUpdate()
    {
        DataTable table = new DataTable();
        adapter.Fill(table);
        return table;
    }

    public void Update(DataTable table)
    {
        adapter.Update(table);
    }
}
```

### POST-methode

```cs
public void AddCustomer(Customer customer)
{
    DataRow row = table.NewRow();

    row[ADDRESSLINE1] = customer.AddressLine1;
    row[ADDRESSLINE2] = customer.AddressLine2;
    row[CITY] = customer.City;
    row[CONTACTFIRSTNAME] = customer.ContactFirstName;
    row[CONTACTLASTNAME] = customer.ContactLastName;
    row[COUNTRY] = customer.Country;
    row[CREDITLIMIT] = customer.CreditLimit;
    row[CUSTOMERNAME] = customer.CustomerName;
    row[CUSTOMERNUMBER] = customer.CustomerNumber;
    row[PHONE] = customer.Phone;
    row[POSTALCODE] = customer.PostalCode;
    row[SALESREPEMPLOYEENUMBER] = customer.SalesRepEmployeeNumber;
    row[STATE] = customer.State;

    table.Rows.Add(row);
}
```

### GET-methode

```cs
// Wat hieronder staat is enkel een hulpmethode om makkelijk te kunnen controleren 
// wat er in een gegeven DataTable zit.
// (Gezien het een HULPmethode is, geven we hier bewust een parameter mee.
//  Zo kun je deze hulpmethode voor elke datatable gebruiken; niet enkel voor de instantievariabele.)
private List<Customer> GetCustomersFromTable(DataTable table)
{
    List<Customer> list = new List<Customer>();
    foreach (DataRow row in table.Rows)
    {
        Customer customer = new Customer();
        customer.AddressLine1 = row[ADDRESSLINE1].ToString(); customer.AddressLine2 = row[ADDRESSLINE2].ToString();
        customer.City = row[CITY].ToString();
        customer.ContactFirstName = row[CONTACTFIRSTNAME].ToString();
        customer.ContactLastName = row[CONTACTLASTNAME].ToString();
        customer.Country = row[COUNTRY].ToString();
        customer.CreditLimit = (double)row[CREDITLIMIT];
        customer.CustomerName = row[CUSTOMERNAME].ToString();
        customer.CustomerNumber = (int)row[CUSTOMERNUMBER];
        customer.Phone = row[PHONE].ToString();
        customer.PostalCode = row[POSTALCODE].ToString();
        if (!(row[SALESREPEMPLOYEENUMBER] is System.DBNull))
        {
            customer.SalesRepEmployeeNumber = (int)row[SALESREPEMPLOYEENUMBER];
        }
        // foutmelding: conversie niet geldig -> als DBNull niet getest werd!
        customer.State = row[STATE].ToString();

        list.Add(customer);

    }

    return list;
}

public List<Customer> GetCustomersFromDataBase_WithoutDataTableUpdate()
{
    return GetCustomersFromTable(adapter.GetCustomersWithoutUpdate());
}

public List<Customer> GetCustomersFromDataTable_NotCertainTheyAreInDataBase()
{
    // Je vraagt de instantievariabele "DataTable table" op; 
    // maar als die nog niet overgezet is naar
    // de databank, heb je niet de echte info uit de databank.
    // Als je dat wil, zal je eerst moeten updaten (zie andere methode in deze klasse).
    return GetCustomersFromTable(table);
}
```