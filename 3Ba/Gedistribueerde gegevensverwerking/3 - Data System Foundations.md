# DATA SYSTEM FOUNDATIONS

Distributed Data Processing


# RELIABLE, SCALABLE AND MAINTAINABLE APPLICATIONS


## DATA-INTENSIVE APPLICATIONS

* As opposed to compute-intensive applications
* Problems
* Amount of data
* Complexity of data
* Speed at which data is changing
* Typically built from standard building blocks
* Store data so it can be retrieved again later (databases)
* Remember the result of an expensive operation, speeding up reads (cache)
* Allow users to search data by keyword or filter it in various ways (search indexes)
* Send a message to another process, to be handled asynchronously (stream processing)
* Crunch large amount of accumulated data (batch processing)
* We need to figure out which tools and which approaches are most appropriate for task at
hand

## DEFINITIONS: SYSTEMS OF RECORD AND DERIVED DATA

##### Systems that store and process data grouped into two broad categories

* Systems of record
    * A.k.a. source of truth, holds authoritative version of your data
    * When new data comes in → first written here
    * Each fact represented exactly once
    * In case of discrepancy between another system and system of record, value in system of record is correct one
* Derived data systems
    * Result of taking existing data from another system and transforming or processing it in some way
    * If you lose derived data → can recreate it from original source
    * Technically speaking derived data is redundant, however often essential to get good performance on
read queries

## THREE MAIN CONCERNS FOR DATA SYSTEMS

#### Reliability

* The system should continue to work correctly (correct functionality at the desired level of performance) even in the face of adversity (hardware or software faults or even human errors)

#### Scalability

* As the system grows (in data volume, traffic or complexity), there should be reasonable ways of dealing with that growth

#### Maintainability

* Over time many different people will work on the system and they should all be able to work on it productively

## RELIABILITY

##### Continuing to work correctly, even when things go wrong

* Things that can go wrong = faults
* Systems that anticipate faults and can cope with them = fault-tolerant or resilient systems
* Note: not all faults can be tolerated: if planet Earth is swallowed by a black hole, tolerance of that fault would require web hosting in space

##### Faults are not failures

* Fault = one component of the system deviates from its spec
* Failure = system as a whole stops providing the required service to the user

##### Systems can be tested in terms of fault-tolerance by deliberately inducing faults

## SCALABILITY

#### Describing load e.g. Twitter

* Post tweet (4.6k write requests/s on average, 12k write requests/s peak)
* View home timeline (300k read requests/s)

#### Handling 12k writes/s is not that hard

* Difficulty is fan-out: each user follows many people and is followed by many people

#### Two ways of handling this

1) Posting a tweet inserts the new tweet into a global collection of tweets
    * User requesting their home timeline, look up all the people they follow, find all tweets for each of those users and merge them (sorted by time)


## SCALABILITY

2) Maintain a cache for each user’s home timeline

    * When a user posts a tweet, look up all the people who follow that user, and insert the new tweet into each of their home timeline caches

    * Request to read the home timeline is then cheap, because result has been computed ahead of time


## SCALABILITY

* First version of Twitter used approach 1
    * Systems struggled to keep up with load of queries
* Switch to approach 2
    * Downside: posting a tweet requires a lot of extra work
    * On average: a tweet is delivered to 75 followers
        * 4.6k tweets per second becomes 345k writes per second to home timeline caches
    * BUT: some users have over 30 million followers
        * Would result in single tweet → 30 million writes to home timelines
* Thus, for Twitter distribution of followers per user (weighted by how often a user tweets) is a key load parameter for scalability
    * Nowadays Twitter uses a hybrid approach (approach 2 for regular users combined with approach 1 for celebrities)

## SCALABILITY – DESCRIBING PERFORMANCE

##### Mean (given n values, add them up and divide by n)

* Usually not a very good metric if you want to know typical response time, because it does not tell
you how many users actually experienced that delay

##### Percentiles

* Median or 50 th percentile: take sorted list of response times, median is halfway
    * e.g. if median response time is 200ms, half your requests return in less than 200ms, and half your requests take longer than that
* To know how bad outliers are: you can look at 95 th, 99th or 99,9th percentile
    * 950, 990 or 999 out of 1000 requests take less than given time to complete
* Tail latencies are important because they directly affect user experience of service

##### Often used in SLAs (Service Level Agreements), typically both in median and 99th percentile quantifications

## PERCENTILES IN PRACTICE

### When several backend calls are needed to serve a request, it takes a single slow backend request to slow down the entire request

### Add response time percentiles to monitoring dashboards for services

###### Rolling window of response times of requests in the last timeframe (e.g. median,

###### different percentiles over last 10 minutes).

## SCALABILITY – HANDLING LOAD INCREASES

* Vertical scaling = moving to more powerful hardware
* Horizontal scaling = distributing load over more machines
* Elastic systems: detect load increases or decreases and automatically add or remove
resources
* Manual scaling: human analyses capacity and decides upon adding more machines to the
system
* There is no generic magic scaling sauce
    * Volume of reads, volume of writes, volume of data to store, complexity of the data, response time requirements, access patterns, security, etc.
        * 100.000 requests/second, each 1 kB 3 requests/minute, each 2 GB in size
            * Both systems deal with 0.1GB/s data throughput but should look very different

*TOT HIER GECHECKT*

## MAINTAINABILITY

### Operability

###### Make it easy for operations team to keep system running smoothly

### Simplicity

###### Make it easy for new engineers to understand system, removing as much

###### complexity as possible from the system

### Evolvability

###### Make it easy for engineers to make changes to system in the future, adapting it for

###### unanticipated use cases as requirements change


# DATA MODELS AND QUERY

# LANGUAGES


## DATA MODEL LAYERING

### Most applications built layering one data model on top of another

###### For each layer key question: representation in terms of next-lower layer?

‒ App developer: model real world in terms of objects and data structures and APIs that

```
manipulate them
‒ Structures often application-specific
```
```
‒ Storing those data structures: express them in terms of general purpose data models
‒ e.g. JSON or XML documents, tables in a relational DB, graph model
```
‒ Engineers who build DB software represent JSON/XML/relational/graph data in terms of

```
bytes in memory, on disk or on the network
‒ Representation may allow data to be queried, searched, manipulated, processed
```

## SQL – RELATIONAL MODEL

### Data organized in relations (tables in SQL), where each relation is an

### unordered collection of tuples (rows in SQL)

###### Theoretical origins in 1970

###### Boomed in mid-1980’s with RDBMSes (Relational Database Management Systems)

###### and SQL DBs

###### 25 - 30 years of dominance

### Some of the competition from that age was hyped but vanished rapidly:

### object databases, XML databases, etc.


## OBJECT-RELATIONAL MISMATCH

### Most application development nowadays

### is in object-oriented programming

### languages

###### Awkward translation layer needed between

###### objects in application code and the DB model

###### of tables, rows and columns

###### Partially solved through Object-Relational

###### Mapping (ORM) frameworks like ActiveRecord

###### (Ruby) or Hibernate (Java)


## NOSQL

```
* NoSQL = Not Only SQL
* Driving forces
* Need for greater scalability
‒ Very large datasets
‒ Very high write throughput
* Preference for free and open source software over commercial DB products
(e.g. popularity of open source PostgreSQL)
* Specialised query operations (e.g. WITH RECURSIVE) not well supported by the
relational model
* Frustration with restrictiveness of relational schemas and a desire for a more
dynamic and expressive data model
* In the foreseeable future, relational DBs will continue to be used
alongside a broad variety of non-relational datastores
* Different types of NoSQL datastores: document store, graph store, time
series DB, triple/quad store, etc.
```
```
Source: https://scalegrid.io/blog/2019-database-trends-sql-vs-nosql-top-databases-single-vs-multiple-database-use/
```

## LINKEDIN PROFILE IN RELATIONAL SCHEMA

```
* Profile has unique identifier user_id
* First_nameand last_nameoccur exactly once and can be
modelled as columns
* Most people had
* More than one job / position
* Multiple periods of education
* Different number of contact methods
* One-to-many relationship from user to these items and thus
some options to represent this
* Traditional SQL: put positions, education and contact info in
separate tables with foreign key reference to users table
* Later versions of SQL added support for structured datatypes and
XML data
‒ Allows for multi-value data to be stored in a single row, with
support for querying and indexing inside those documents
* Encodejobs, education and contact info as JSON or XML document,
store it on a text column in the DB and let application interpret
structure and content
‒ Typically you cannot use DB to query for values inside that
encoded column
```

## LINKEDIN PROFILE AS A JSON DOCUMENT

```
* Resumé is mostly a self-contained document
* MongoDB, RethinkDB, CouchDB, Espresso, etc. all support JSON
(JSON = JavaScript Object Notation)
* Reduces mismatch between application code and storage
layer
* JSON representation has better locality than multi-table
schema
* Multiple queries or multiway join in relational systems
* JSON: all relevant information in one place, single query sufficient
* JSON representation shows one-to-many relationships
from user profile to user’s positions, educational history
and contact information
* Explicit tree structure
```

## MANY-TO-ONE RELATIONSHIPS

```
* In relational example, region_id and industry_id are IDs, not plain-text
strings. Advantages:
* Consistent style and spelling across profiles
* Avoid ambiguity (e.g. several cities with same name)
* Ease of updating: name stored in only one place, easy to update across the board
* Localization support: standard lists can be localized, so region and industry can be
displayed in viewer’s language
* Better search: can add information making it easier to find search relations
* These denote many-to-one relationships
* Example: many people live in one region, many people work in one industry
* Relational DBs: normal to refer to rows in other tables by ID, because joins are easy
* Document DBs: support for many-to-one relations is weak
‒ Joins are not needed for one-to-many table structures and support for joins is weak
‒ Work of creating join is typically moved to application instead of DB (e.g. in-memory list
of regions or industries)
```

## EVOLVING THE EXAMPLE: MANY-TO-MANY RELATIONSHIPS

```
* Initial version fits well in a join-free document model
* What if we consider following changes
* Organizations and schools as entities (previously: just strings)
* Recommendations: recommendation itself should have a reference to the author’s profile
* Require many-to-many relationships
* References to organisations / schools / other users need to be represented as references and require joins when queried
* Well-supported by SQL datastores and NoSQL graph stores, not so well by NoSQL document datastores
```

## RELATIONAL VS DOCUMENT DATA MODEL

#### Document data model

```
* Schema flexibility
‒ Most document DBs do not enforce a schema on data in the documents
```
* Better performance due to locality (see JSON example)

* For some applications closer to the data structures used by the application

```
* Concept of foreign key: document reference
‒ Resolved at read time by join or follow-up queries
```
#### Relational data model

* Better support for joins

* Good support for many-to-one and many-to-many relationships


## CHOICE FOR RELATIONAL OR DOCUMENT MODEL

```
* If data in application has document-like structure (tree
of one-to-many relationships, where typically entire tree
is loaded)
* Good idea to use document model
* Shredding / splitting a document-like structure into multiple
tables can lead to cumbersome schemas and complicated app
code
* Limitations
‒ Cannot refer directly to a nested item within a document but
need to say something like “second item in list of positions for
user X251”
‒ If documents are not too deeply nested usually not an issue
```

## CHOICE FOR RELATIONAL OR DOCUMENT MODEL

#### If data in application has many-to-many relationships

* Document model less appealing

* Possible to reduce need for joins by denormalizing, but then app code needs to keep

```
denormalized data consistent
‒ Duplicates data that would otherwise require joins
‒ Denormalization improves read performance but deteriorates write performance
```
* Joins can be emulated by making multiple requests to DB, but complicates application

code and usually slower than join made inside DB

#### Highly interconnected data: graph model may be most appropriate

* See slides later on


## DDB: SCHEMA FLEXIBILITY

```
* Document DBs and JSON support in relational DBs usually do not enforce any schema on data
in documents
* Arbitrary keys and values can be added to a document
* When reading from document DB clients have no guarantees what fields documents contain
* Typically code reading data assumes some kind of structure (implicit schema) but this is not enforced by
DB
* Schema-on-read
* Structure of the data is implicit and only interpreted when the data is read
* Similar to dynamic (runtime) type checking
* Schema-on-write
* Approach of relational DBs with explicit schema
‒ DB ensures all written data conforms to explicit schema
* Similar to static (compile-time) type checking
```

## DDB: SCHEMA FLEXIBILITY

### Difference between approaches noticeable when application wants to

### change format of its data

###### E.g. currently storing full name in one field

###### Want to store first name and last name separately

###### Document DB: start writing new documents with new fields and have application

###### code handle case when old documents are read

###### In statically typed DB schema you would perform a migration like


## DDB: SCHEMA FLEXIBILITY

### Schema-on-read approach is advantageous if items in collection do not

### all have same structure

###### Many different types of objects and impractical to put each type in own table

###### Especially useful when structure of data is determined by external systems over

###### which you have no control and which may change at any time


## DDB: DATA LOCALITY FOR QUERIES

```
* Document usually stored as a single continuous string (JSON, XML or binary variant)
* If application often needs to access entire document → performance advantage to storage locality
* Locality advantage only applies if you need large parts of document at once
‒ DB needs to load entire document
‒ On updates entire document usually needs to be rewritten
* Recommended to keep documents small and avoid writes increasing size
‒ These limitations reduce the set of situations in which document DBs are useful
* Grouping related data for locality is not limited to document model
* Google Cloud Spanner DB offers locality principles in relational data model (so called newSQL)
‒ Note, does not solve everything: expensive, write API is not strictly SQL, no hybrid deployment option
```

## GRAPH-LIKE DATA MODELS

### What if many-to-many relations are very common in your data?

###### More natural to model data as a graph

‒ Vertices (nodes or entities)

‒ Edges (relationships or arcs)

### Examples

###### Social graphs: vertices are people, edges indicate relations

###### Web graph: vertices are web pages, edges indicate HTML links

```
32
Source: https://www.infoq.com/presentations/Data-Modeling-Graphs/
```

## GRAPH MODELS AND QUERY LANGUAGES

### Different ways of structuring data in graphs

###### Property graph model (a.o. Neo4j)

###### Triple-store model (a.o. Datomic and AllegroGraph)

### Different ways of querying data in graphs

###### Cypher, SPARQL and Datalog

```
Example graph structured data^33
```

## PROPERTY GRAPHS

```
* Each vertex
* Unique identifier
* Set of outgoing edges
* Set of incoming edges
* Collection of properties (key-value pairs)
* Each edge
* Unique identifier
* Vertex at which edge starts (tail vertex)
* Vertex at which edge ends (head vertex)
* Label to describe type of relationship between two vertices
* Collection of properties (key-value pairs)
* Graph store can be thought of as consisting of two relational tables (vertices and edges)
```
```
want the set of incoming or outgoing edges for a vertex →
query edges table by head_vertex or tail_vertex
```

## PROPERTY GRAPHS

#### Important aspects

```
* Any vertex can have an edge connecting it with any other vertex
‒ No schema restricting which kind of things can or cannot be associated
* Given any vertex, efficiently find both incoming and outgoing edges and thus traverse
graph
‒ Indexes on both tail_vertex and head_vertex
* By using different labels for different kinds of relationships, you can store several
different kinds of information in a single graph, while maintaining a clean data model
```

## DIFFICULTIES FOR THE RELATIONAL MODEL

```
* Noteworthy difficulties for relational models
* Different kinds of regional structures in different
countries
‒ France: départementsand régions
‒ US: countries and states
* Quirks of history: country within a country
* Varying granularity of data
‒ Current residence is city
‒ Place of birth specified as state
* Graphs good for evolvability
* As you add features you can easily extend the graph
to accommodate changes in your application’s data
structures
```

## CYPHER QUERY LANGUAGE

##### Declarative query language for property graphs

* Created for Neo4j graph DB

##### Cypher query to insert subset of data of example

##### Wish to find names of all people who emigrated

##### from US to Europe → query as follows

```
Find any vertex (call it person) that meets both following conditions
```
1. Person has an outgoing BORN_IN edge to some vertex. From that vertex you can follow a chain of outgoing WITHIN edges until eventually you reach a vertex
    of type Location, whose name property = United States
2. That same person vertex also has an outgoing LIVES_IN edge. Following that edge, and a chain of outgoing WITHIN edges, you can eventually reach a vertex
    of type Location, whose name property = Europe


## GRAPH QUERIES IN SQL

#### As graph data can be put in relational tables can it be queried using SQL?

```
* Yes but
‒ In relational DB usually known in advance which joins are needed in query
‒ In graph DB query may need to traverse a variable number of edges before finding vertex you are
looking for
‒ Number of joins is not fixed in advance
```
#### Variable-length traversal in SQL = recursive common table expressions (WITH

#### RECURSIVE)

* See example next slide


## EXAMPLE: GRAPH QUERIES IN SQL

1. Find vertex whose name property has value “United States”
    and make it first element of set of vertices in_usa
2. Follow all incoming within edges from vertices in in_usa and
    add them to same set
3. Do same for in_europe
4. For each of the vertices in set in_usa, follow incoming born_in
    edges to find people who were born in same place within US
5. For each of the vertices in the set in_europe, follow incoming
    lives_inedges to find people who live in Europe
6. Finally intersect set of people born in USA with set of people
    living in Europe by joining them

```
* Note: 4 lines in Cypher, 29 lines in SQL
* Different data models are designed to satisfy different use cases
```

## TRIPLE-STORES

##### Triple-store model mostly equivalent to property graph model

* Different words for same ideas

##### All information stored in form of three-part statements (subject, predicate, object)

* E.g. (Jim, likes, bananas)

##### Subject of a triple is equivalent to a vertex in a graph

##### Object is either

```
* A value in a primitive datatype
‒ E.g. (lucy, age, 33) is like a vertex lucy with properties {“age”:33}
* Another vertex in the graph
‒ In that case predicate is edge in graph, subject is tail vertex and object is head vertex
‒ E.g. (lucy, marriedTo, alain): subject and object lucy and alain are both vertices, and predicate
marriedTo is label of edge that connects them
```

# DATA WAREHOUSING


## TRANSACTION PROCESSING OR ANALYTICS?

```
* In early days writes to DB typically corresponded to commercial transactions (e.g. making a sale, placing an order, paying a salary)
* DBs started being used for many different kinds of data
* E.g. comments on posts, actions in a game, contacts in an address book
* Basic access pattern remained similar to processing business transactions
‒ App looks up small number of records by some key, using an index
‒ Records are inserted or updated based on user input
* Because these apps are interactive, access pattern became known as Online Transaction Processing (OLTP)
* DBs also started being used for data analytics with very different access patterns
* Analytic query scans over huge number of records, reading few columns per record and calculating aggregate statistics rather than returning raw data
to user
‒ E.g. what was total revenue of each of the stores in January?
‒ E.g. how many more products than usual were sold during our last promotion?
* Analytic queries often written by business analysts
* Query results feed reports to help management make informed decisions → business intelligence
* Access pattern became known as Online Analytic Processing (OLAP)
* At first same DBs were used for OLTP and OLAP queries
* Early 1990s however OLAP queries started being run on a separate DB called the data warehouse
```

## DATA WAREHOUSING AND ETL

```
* OLTP systems usually expected to be highly available and to process transactions with low latency as they are
critical to business
* Reluctance to let business analysts run ad hoc analytic queries on OLTP databases (queries usually expensive, harming performance)
* Introduction of data warehouse, allowing queries without affecting OLTP operations
* Contains read-only copy of datain various OLTP systems
‒ Extracted from OLTP systems by periodic data dump or stream of updates
‒ Transformed into analysis friendly schema
‒ Cleaned up
‒ Loaded into data warehouse
* Process of getting data into warehouse is known as Extract-Transform-Load (ETL)
```

## DATA WAREHOUSE VERSUS DATA MART

```
* Data warehouse
* Centralised location for data
* Holds multiple subject areas / very detailed information
* Works to integrate all data sources
* Source of data for reporting, analytics and offline operational processes
* Typically employs expensive DB technology
* Data mart
* DBs used to provide fast, independent access to a subset of warehouse data
* Often created for departments, projects, users
* Compared to data warehouse
‒ Similar technology, subset of data, relieves pressure on enterprise data warehouse, provides sandbox for analysis
```

## DATA FLOW IN THE DATA WAREHOUSE

```
* DQ: Data Quality Tools
* Defining quality rules, applying those rules to data to detect violations/exceptions and fixing those exceptions
* Data profiling automatically gathers statistics about data to ascertain its quality e.g. how many values are empty, minimum and
maximum values, most frequent values, etc.
* ETL: Extract Transform Load
* MDM: Master Data Management systems
* Creation of master lists of various entities: customers, products, suppliers, etc. and detecting multiple records that apply to the same
entity and fixing ambiguities
* OLAP: Online Analytical Processing Tools (technology behind BI)
* BI: Business Intelligence
```

## DATA WAREHOUSE METADATA FLOW

```
* Metadata repositories
* Contain technical metadata across the data assets
* Three main use cases
‒ Finding data assets
‒ Tracking lineage (provenance): where data came from and how it was generated/transformed a.k.a. data trail auditing
‒ Impact analysis: allows developers to see all data assets that rely on a particular field or integration job before making a
change
```

## DATA WAREHOUSE DATA MODEL

```
* DB at the heart of a data warehouse
* Usually relational DB optimized for analytics-type processing
‒ Large, long queries, aggregation and multi-table joins
* DB usually heavily indexed and tuned to ensure optimal performance for most common queries
* When relational DBs are used to support operational systems and applications (OLTP) data is usually
stored in highly normalized data models
* Create tables with minimum redundancy and smallest possible number of fields
* Makes updates (writes) very fast
* Data warehouses however favour denormalized data models (for OLAP)
* Each table contains as many related attributes as possible
* Typically contains data from many sources and applications each with their own schema
‒ Data from those sources has to be converted to a single schema
* Typically uses a star schema (dimensions / fact tables)
‒ Many DBs include specialized query optimizations for handling star schema-like joins
```

## DATA WAREHOUSE STAR SCHEMA

```
* Data warehouses use star schemas a.k.a. dimensional modelling
* Centre of schema is fact table
‒ Each row represents an event occurring at a particular time
‒ Fact tables can get very large
‒ Some columns are attributes
‒ Price at which product was sold
‒ Cost of buying it from supplier
‒ Other columns foreign key references to other tables: dimension tables
* Example
* One dimension is product that was sold (dim_product)
* Date and time often represented using dimension tables, as it allows
extra information to be encoded, allowing queries to differentiate
between sales on holidays and non-holidays
* Why is it called star schema?
* When table relationships are visualized, fact table is in middle
surrounded by dimension tables
* Typical data warehouses often have fact tables that have over
100 columns, up to several 100s
```

## SLOWLY CHANGING DIMENSIONS

```
* To allow accurate data analysis sometimes needed to keep track of e.g. a person’s state over time
* Ensures each transaction corresponds to person’s state at time of transaction
* Most common type of slowly changing dimension tracks historical data by creating multiple records
* Example
* Keep track of customer purchases along with customer demographics (single, married, parent, divorced, etc.)
* Without slowly changing dimensions we would have one single record for a customer reflecting only current
demographic state
‒ Difficult to analyse how many people with children spend money on specific items
* Add complexity to ETL jobs and analytic queries
```
```
52
Example source: https://www.nuwavesolutions.com/slowly-changing-dimensions/
```
```
Original record
```
```
Updated record
```
```
Original record
```
```
Updated record
```

## COLUMN-ORIENTED

#### Typical data warehouse query only accesses 4 or 5 columns at one time

#### Example

* Are people more inclined to buy fresh fruit or candy, depending on day of the week?

* Accesses large number of rows (everyone buying fruit or candy during a specific year) but

only needs to access three columns of fact_sales table: date_key, product_sk and quantity


## COLUMN-ORIENTED STORAGE

```
* In most OLTP DBs storage is laid out in row-oriented fashion
* All values from one row of a table are stored next to each other
* Document DBs are similar: entire document is stored as one continuous sequence of bytes
* Performance issues when loading all these rows from disk into memory, parsing them and filtering out those that
don’t meet required conditions
* Column-oriented storage: do not store all values from one row together, but store all values from each column
together instead
* If each column is stored in a separate file, a query needs only read and parse those columns used in the query
* Example
* Customers table with 300 columns, average of 5 bytes per attribute stored
‒ 1.5KB for each user
‒ 1 million customers
* Relational
‒ 1.5TB storage for DB
* Columnar
‒ If age takes 2 bytes and a record identifier 6 bytes, DB needs 8 bytes per field, or 8GB for 1 mil customers
‒ Queries like: “how many customers are under 30?” can be answered very fast
```

## EXAMPLE: COLUMN-ORIENTED STORAGE


## DATA INTEGRATION TOOLS: ETL

### Job of an ETL tool is to convert various representations into a common

### dimension table

###### Make sure same record from different systems is used to create or update a single

###### record in the dimension

###### Such a dimension is called a conforming dimension

‒ Same ID identified across various records in different systems


## ETL VERSUS ELT

### Extract Transform Load (ETL)

###### Data is extracted, transformed and loaded into data warehouse

### Extract Load Transform (ELT)

###### Data is extracted, loaded into data warehouse and transformed


## VIRTUALISED DATA WAREHOUSE

```
* Data warehouse approach is to bring all data together in one place, integrate it into a
single conforming schema and use it for analytics queries
* Alternative
* Create logical or virtual schema across multiple systems and issue queries against that schema
‒ A.k.a. Federation, Enterprise Information Integration (EII) and data virtualisation
* Approach is more appropriate than using a data warehouse when
‒ Data must be kept fresh in the face of changes: execute queries against original sources, results always
up to date
‒ Data access is infrequent: building very expensive data warehouses for data infrequently used is not
cost-effective
‒ Compliance and data residency clauses constrain data from being copied to a data warehouse
* Drawbacks
‒ Labor-intensive manual process: virtual tables must be manually defined across disparate systems
‒ Schema and logic changes: schema change can break queries and make all data unavailable until
queries are fixed
‒ Performance: queries that span multiple systems (federated queries) have significant performance
challenges
‒ Frequency: if there are a lot of queries against virtual schema, it becomes more advantageous to
extract data once, store it in a data warehouse and query it there: lowers load on source systems
```

# DATA LAKE


## DATA LAKE

```
* Self-service is taking over from carefully crafted and labor-intensive approaches of the past
* IT professionals created well-governed data warehouses and data marts but took months to make changes
* Data lake focusses on self-service
* First definition (James Dixon, 2010)
* “If you think of a data mart as a store of bottled water –cleansed and packaged and structured for easy consumption –the data
lake is a large body of water in a more natural state. The contents of the data lake stream in from a source to fill the lake, and
various users of the lake can come to examine, dive in, or take samples”
* Take-aways: data in original form and format and used by various users
* Allow analysts to analyse data without having to get help from IT
* Data preparation tools that help analysts shape data for analytics
* Catalogtools that help analysts find the data they need
* Data science tools that help perform advanced analytics
* Challenge with self-service is governanceand data security
* Many industries: prescribed data security policies that have to be implemented
‒ Illegal to give analysts access to all data
* How to make data available to analysts without violating internal and external data compliance regulations?
‒ A.k.a. data democratization
```

## DATA WAREHOUSE VERSUS DATA LAKE


## DATA LAKE MATURITY

```
* Data puddle
* Single purpose or single project data mart built using big data / cost-
efficient technology
* Data pond
* Collection of data puddles
* Focus on scalable / cost-efficient technology compared to data
warehouse / mart
* Data lake
* Supports self-service: business users able to find and use data sets that
they want to use without having to rely on help from IT department
* Aims to contain data that business users may possibly want even if
there is no project requiring it at the time
* Data ocean
* Expands self-service data and data-driven decision making to all
enterprise data, wherever it may be
```
```
62
```
```
high-touch = requiring
high interaction
```

## DATA LAKE SUCCESS FACTORS: PLATFORM

```
* Big data technologies like Hadoop, cloud solutions like AWS, Azure and Google Cloud Platform
* Volume: designed to scale out
* Cost: ability to store and process huge volumes of data inexpensively
‒ Usually at one-tenth to one-hundredth the cost of a commercial relational DB
* Variety: filesystems or object stores that allow to store all sorts of files e.g. Hadoop HDFS, MAPR FS, AWS S3
‒ Unlike relational DB requiring schema on write, a filesystem or object store does not care what you write
(schema on read)
* Future-proofing
‒ If data is stored in a relational DB it can only be accessed by that relational DB
‒ Hadoop and big data platforms very modular: Hive can provide a SQL interface to Hadoop files, to Pig scripts, to
Spark, to MapReduce, etc. (seen in later slidedecks)
```

## DATA LAKE SUCCESS FACTORS: DATA

#### Most data collected by enterprises today is thrown away

* Small percentage of data aggregated and kept in data warehouse for a few years

#### Issue with data silos: different departments hoard their data, making it

#### difficult to use data cross-groups

#### Data lake: store as much data as possible for future use

* Typically no known reason for storing the data, but do so in case data is needed one day

* Makes no sense to convert or treat data prematurely → save data in its native format

* Consumes raw data and prevents data silos


## DATA LAKE SUCCESS FACTORS: INTERFACE

##### To gain wide adoption and reap benefits of helping business users make data driven

##### decisions, solutions companies provide must be self-service

```
* Users must be able to find, understand and use data without help from IT department
‒ IT unable to scale support to such a large user community and such a large variety of data
```
##### Interface at the right level of expertise

```
* Analysts
‒ Often do not possess skills to use raw data: too much detail, too granular, too many quality issues
‒ Data has to be harmonized: put in same schema with same field names and units of measure
‒ They want “cooked” data, not raw data
* Data scientists
‒ Want access to raw data, not the cooked data
* Possible by setting up multiple zones / areas that meet particular needs
```

## DATA LAKE GONE WRONG: THE DATA SWAMP

```
* Data pond that has grown to size of a data lake but failed to attract a wide
analyst community
* Usually due to lack of self-service and governance facilities
* Figure
* Various teams use small areas of lake for projects (white data pond area)
* Majority of data is dark, undocumented / unusable
* Historically a lot of companies rushed to buy Hadoop clusters and filled
them with raw data
* Millions of files containing petabytes of data and no way to make sense of that data
* No one could tell where the sensitive data was, so users could not be given access
and data remained largely unusable and unused
* Example: company built a data lake, encrypted all data in lake to protect it,
required data scientists to prove that data they wanted was not sensitive
before it would unencrypt it and let them use it
* Because everything was encrypted, data scientists could not find anything, much
less prove it was not sensitive
* Noone used the data lake / swamp
```

## SETTING UP A DATA LAKE

### 1. Set up the infrastructure

###### E.g. get the Hadoop cluster up and running

### 2. Organize the data lake

###### Create zones for use by various user communities and ingest data

### 3. Set the data lake up for self-service

###### Create catalogue of data assets, set up permissions and provide tools for analysts

###### to use

### 4. Open data lake up to users


## SET UP THE DATA LAKE INFRASTRUCTURE

```
* Initially data lakes were built mostly on-premise using open-source or commercial Hadoop
distributions
* Later cloud-based data lakes or hybrid cloud/on-prem data lakes started being used
* Latest evolution: logical data lake: a virtual data lake layer across multiple heterogeneous
systems
* Hadoop, relational, NoSQL DBs, on-premise and in the cloud
* All use a catalogue to find data assets
```

## ZONES: ORGANIZING THE DATA LAKE

##### Raw or landing zone where data is ingested and kept as close as possible to the

##### original state

##### Gold or production zone where clean, processed data is kept

##### Dev or work zone where more technical users (data scientists / engineers) work

```
* Can be organised by user, by project, by subject, etc.
* Once analytics performed in work zone get productized → moved into gold zone
```
##### Sensitive zone that contains sensitive data


## MULTI-MODAL DATA GOVERNANCE

#### Governance should reflect data usage and user community requirements

#### Different zones have different levels of governance and SLAs

```
* Data in the gold zone is strongly governed, well curated, well documented, carries quality
and freshness SLAs
* Data in the work area has minimal governance (mostly making sure there is no sensitive
data) and SLAs that vary from project to project
```

## SETTING UP FOR SELF-SERVICE

### Analysts typically go through four steps to do their job

###### 1. Find and understand

###### 2. Provision (get access to the data)

###### 3. Prepare (clean and convert)

###### 4. Analyse (answer questions, create visualisations and report)

### First three steps typically take 80% of an analyst’s time

###### 60% is in the first step of finding and understanding data


## 1. FINDING AND UNDERSTANDING DATA

##### Variety and complexity of available data far exceeds human ability to remember it

```
* Typical companies have 1000s of DBs, with typically many 100s of tables with each table having
many 100s of fields
```
##### Typical project

1. Ask around to see whether anyone has ever used a particular type of data
2. Stumble onto data set that someone has already used
3. Once decided to use that data set spend a lot of time deciphering what the data it contains
    means
‒ Knowledge about what data means is usually spread throughout the company
‒ Analyst crowdsourcing tools collect this information to document data sets using simple descriptions
composed of business terms and builds a search index to help them find what they are looking for
‒ Adopted by data-driven companies like Google, LinkedIn
‒ Situation much worse in traditional companies with millions of existing data sets that will never get documented


## 2. ACCESSING AND PROVISIONING THE DATA

```
* Once right data sets identified → analysts need to be able to use them
* Publish information about all data sets in a metadata catalogue so analysts can find useful
data sets and request access as needed
* Requests include justification for access, project that requires the data and duration of access required
* Incoming request may trigger work to deidentify sensitive data
* Provisioning or physical access can be granted in a number of ways
* Users can be granted read access to the entire data set
* If only partial access should be granted, a copy of the file containing just the data appropriate to the user
can be created (and kept up to date) or a table or view can be created that contains only the fields and
rows that the analyst should see
* If needed, a deidentified version of the data set can be generated that replaces sensitive information with
randomly generated equivalent information, so all applications still work, but no sensitive data is leaked
```

## 3. PREPARING THE DATA

#### Most of the time data needs work to render it appropriate for analysts. This

#### generally involves the following operations

```
* Shaping
‒ Selecting a subset of fields and rows to work on, combining multiple files and tables into one
(joining), transforming and aggregating, converting variables to features (e.g. converting age
into a feature that has a value of 0 if a person is over 65 and 1 if not)
* Cleaning
‒ Filling in missing values, correcting bad values, resolving conflicting data, normalizing units of
measure and codes to common units
* Blending
‒ Harmonizing different data sets to the same schema, same units of measure, same codes, etc.
```

## DATA LAKE ARCHITECTURES

#### Initially thought one huge on-premise data lake would contain all their data

#### Not ideal, multiple data lakes typically proven to be a better solution

* Different data sovereignty regulations

* Organizational pressures

* Frustration at finding experienced administrators for setting up and maintaining complex

Hadoop (and other big data technologies) cluster

#### High interest in Cloud-based data lakes where most hardware and platform

#### components are managed by experts that work for Amazon, Microsoft, Google

#### and others


## DATA LAKES IN THE PUBLIC CLOUD

##### Access to big data technology expertise

##### Short deployment times

##### Low cost of storage and elastic nature of cloud computing make it an attractive

##### option for implementing a data lake

```
* A lot of data is being stored for future use, so makes sense to store it as inexpensively as possible
‒ Cost optimization possible through various storage tiers offered by public cloud vendors: from high-
speed to glacial, with slower-access media being significantly cheaper
* Elasticity of cloud computing allows a very large cluster to be spun up on demand when needed
‒ Compared to on-premise: as nodes fill up with data, new nodes need to be added just for storage
‒ If analytic loads are CPU-heavy and need more compute power, you need to add even more nodes, even though you may only
use them for a short time
‒ In the cloud you pay for the storage and processing that you need
```

## LOGICAL DATA LAKES

```
* Instead of loading all data into the data lake in case someone may actually need it, it is made available to analysts
through a central catalogue or through data virtualization software
* Address the issues of completeness and redundancy
* Completeness
‒ If analysts can find only data that is already in the data lake other data that has not been ingested into the data lake won’t be found
* Redundancy
‒ If we ingest all data into the data lake, we will have redundancy between the sources of data and the data lake
‒ With multiple data lakes, to achieve completeness we would need to ingest the same data into each data lake
‒ Already a lot of redundancy in the enterprise
‒ When new project is started, fastest approach is for project team to spin up new data mart, copy data from other sources intoit, and add own unique data
‒ Much easier than studying existing data marts and negotiating shared usage with current owners and users
‒ Result: proliferation of data marts that are mostly the same
```

## MANAGING DATA IN THE LOGICAL DATA LAKE

##### Handling complenetess

```
* Create a catalog of all the data assets so the analysts can find and request any data set that is
available in the enterprise
```
##### Handling redundancy

```
* Store data that is not stored anywhere else in the data lake
* Bring data that is stored in other systems into the data lake if and when it is needed, and keep it
in sync while it is needed
* Bring each data set in only once for all users
```

## VIRTUALISATION VERSUS CATALOG BASED DATA LAKE

```
* Virtualization a.k.a. federation or EII (Enterprise Information Integration)
* Technology developed in 1980s improved into the 2010s
* Creates virtual view or table that hides location and implementation of the physical tables
‒ E.g. view created by joining two tables from different DBs
* For logical data lake: would require every data set to be published as a virtual table and kept up to date as underlying table schemas
change
* Views present significant problems
‒ Creating a virtual view does not make data any easier to find
‒ Joining data from multiple heterogeneous systems is complex and compute-intensive, causing massive loads on the systems and long
execution cycles
‒ Distributed joins of tables that don’t fit into memory are notoriously resource-intensive
* By contrast: in catalog-driven approach only metadata about each data set is published in order to make it findable
* Datasets then provisioned to the same system (e.g. Hadoop cluster) to be processed locally
```

## CATALOG-BASED LOGICAL DATA LAKE

### Makes all data findable and accessible to analysts

### Can serve as a single point of access, governance and auditing


# SUMMARY


## SUMMARY

##### ̶Important aspects for data applications

* Reliability, scalability and maintainability

##### ̶Data models and query languages

```
* Relational model (SQL)
* Document model / No-SQL
* Graph model
‒ Property graph + Cypher
‒ Triple store + SPARQL
```
##### ̶Data warehousing

* Data mart, ETL, star schema, column-oriented storage, virtualised data warehouse

##### ̶Data lake

* Success factors, setting up a data lake, logical data lakes