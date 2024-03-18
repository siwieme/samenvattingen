# Batch processing

# Distributed data processing

# Data processing system Types

* <span style="color:#1E64C8">Services</span>  \(online systems\)
  * Service waits for request or instruction from a client to arrive
  * When request is received service tries to handle it as quickly as possible and sends response back
  * Response time usually primary measure of performance of a service
  * Availability often also important
* <span style="color:#1E64C8"> __Batch processing systems __ </span>  __\(offline systems\)__
  * __Take a large amount of input data\, run a job to process it and produce output data__
  * __Jobs often take a while \(minutes/hours/days\)__
  * __Often scheduled to run periodically__
  * __Primary performance measure is usually __  <span style="color:#1E64C8"> __throughput__ </span>
    * __Time it takes to crunch through an input dataset of a certain size__
* <span style="color:#1E64C8">Stream processing systems </span> \(near\-real\-time systems\)
  * Between online and offline/batch processing
  * Stream processor consumes inputs and produces outputs \(rather than responding to events\)
    * A stream job however operates on events shortly after they happen versus batch job operates on fixed set of input data
  * Allows stream processing systems to have lower latency than equivalent batch systems

# Batch processing with Unix tools

* Example: web server appends line to log file every time it serves a request
* Definition of log format
* On given date\, server received request for file /css/typography\.css
  * Client IP address 216\.58\.210\.78
  * Not authenticated
  * Response status 200 \(response successful\)
  * 3377 bytes in size
  * Web browser Chrome 40
  * Loaded file because it was referenced in page at URL [http://martin\.kleppman\.com](http://martin.kleppman.com/)

![](img/Gedistribueerde%20Dataverwerking%20-%2005%20-%20batch%20processing0.wmf)

![](img/Gedistribueerde%20Dataverwerking%20-%2005%20-%20batch%20processing1.wmf)

![](img/Gedistribueerde%20Dataverwerking%20-%2005%20-%20batch%20processing2.png)

# Simple log analysis by Unix tools

![](img/Gedistribueerde%20Dataverwerking%20-%2005%20-%20batch%20processing3.wmf)

![](img/Gedistribueerde%20Dataverwerking%20-%2005%20-%20batch%20processing4.wmf)

![](img/Gedistribueerde%20Dataverwerking%20-%2005%20-%20batch%20processing5.wmf)

Note: powerful and concise\!

![](img/Gedistribueerde%20Dataverwerking%20-%2005%20-%20batch%20processing6.png)

# Log analysis by Ruby program

* Sorting versus in\-memory aggregation
  * Ruby script keeps an in\-memory hash table of URLs\, where each URL is mapped to number of times it is seen
  * Unix pipeline has no such hash table but relies on sorting a list of URLs in which multiple occurrences of same URL are simply repeated
* Which is better ?
  * Depends on number of different URLs you have
  * For most small / mid\-sized websites you can probably fit all distinct URLs and a counter for each URL in memory
  * If the job’s working set is larger than the available memory\, sorting approach has the advantage that it can make efficient use of disks
    * Sort in GNU coreutils \(Linux\) automatically handles larger\-than\-memory datasets by spilling to disk and automatically parallelizes across multiple CPU cores
    * Simple chain of Unix commands scales to large datasets
    * Bottleneck likely rate at which input can be read from disk

![](img/Gedistribueerde%20Dataverwerking%20-%2005%20-%20batch%20processing7.wmf)

# Traditional HPC way of doing things

__Lots of __

__communication__

Communication network \(Infiniband\)

![](img/Gedistribueerde%20Dataverwerking%20-%2005%20-%20batch%20processing8.png)

![](img/Gedistribueerde%20Dataverwerking%20-%2005%20-%20batch%20processing9.png)

![](img/Gedistribueerde%20Dataverwerking%20-%2005%20-%20batch%20processing10.png)

![](img/Gedistribueerde%20Dataverwerking%20-%2005%20-%20batch%20processing11.png)

![](img/Gedistribueerde%20Dataverwerking%20-%2005%20-%20batch%20processing12.png)

worker

nodes

\(lots of them\)

__Lots of computations__

![](img/Gedistribueerde%20Dataverwerking%20-%2005%20-%20batch%20processing13.jpg)

input data \(relatively small\)

# Compute-intensive jobs

* Compute\-intensive tasks \(traditional HPC\)
  * Input data is relatively small
  * Data is usually kept in\-memory during job execution
  * Many computations need to be performed per data\-element
  * Runtime is limited by compute or interconnection network capacity

# Data-intensive jobs

Limited

communication

Fast communication network \(Infiniband\)

![](img/Gedistribueerde%20Dataverwerking%20-%2005%20-%20batch%20processing14.png)

![](img/Gedistribueerde%20Dataverwerking%20-%2005%20-%20batch%20processing15.png)

![](img/Gedistribueerde%20Dataverwerking%20-%2005%20-%20batch%20processing16.png)

![](img/Gedistribueerde%20Dataverwerking%20-%2005%20-%20batch%20processing17.png)

![](img/Gedistribueerde%20Dataverwerking%20-%2005%20-%20batch%20processing18.png)

Low compute intensity

![](img/Gedistribueerde%20Dataverwerking%20-%2005%20-%20batch%20processing19.jpg)

__input data \(lots of it\)__

# Compute-intensive vs data-intensive

* Compute\-intensive tasks \(traditional HPC\)
  * Input data is relatively small
  * Data is usually kept in\-memory during job execution
  * Many computations need to be performed per data\-element
  * Runtime is limited by compute or interconnection network capacity
* Data\-intensive tasks \(“big data”\)
  * Input data is \(very\) large
  * Data is usually not kept in\-memory during job execution
  * Few computations need to be performed per data\-element
  * Runtime is limited by data transfer

# Data-intensive jobs

Limited

communication

Communication network

![](img/Gedistribueerde%20Dataverwerking%20-%2005%20-%20batch%20processing20.png)

![](img/Gedistribueerde%20Dataverwerking%20-%2005%20-%20batch%20processing21.png)

![](img/Gedistribueerde%20Dataverwerking%20-%2005%20-%20batch%20processing22.png)

![](img/Gedistribueerde%20Dataverwerking%20-%2005%20-%20batch%20processing23.png)

![](img/Gedistribueerde%20Dataverwerking%20-%2005%20-%20batch%20processing24.png)

Low compute intensity

__input data \(lots of it\)__

Solution: store data on local disks of nodes that perform computations on that data \( <span style="color:#1E64C8">data locality</span> \)

# Apache hadoop

![](img/Gedistribueerde%20Dataverwerking%20-%2005%20-%20batch%20processing25.png)

* Apache Hadoop
  * Open\-source framework written in Java
  * Distributed storage of very large data sets \(Big Data\)
  * Distributed processing of very large data sets
  * [https://hadoop\.apache\.org/](https://hadoop.apache.org/)
* Framework consists of a number of modules
  * Hadoop Common
  * Hadoop Distributed File System \(HDFS\)
  * Hadoop YARN – resource manager
  * Hadoop MapReduce – programming model
  * Hadoop Mahout – scalable machine learning algorithms

# Main Ideas behind hadoop

* Data\-driven philosophy
  * Growing evidence that having more data and simple models outperforms complex features/algorithms with less data
* Scale out instead of up
  * Prefer a larger number of low\-end workstations over a smaller number of high\-end workstations \(for big\-data problems\)
    * Buying low\-end workstations \(“desktop\-like machines”\) is 4\-12x as cost efficient as buying high\-end workstations \(“high\-memory machines with a high number of CPUs / cores”\)
  * Idea is also valid for network interconnects
    * E\.g\. Infiniband versus “commodity” Gigabit Ethernet
* Move processing to where the data resides

# HADOOP: Move processing to data

Communication network

![](img/Gedistribueerde%20Dataverwerking%20-%2005%20-%20batch%20processing26.png)

![](img/Gedistribueerde%20Dataverwerking%20-%2005%20-%20batch%20processing27.png)

![](img/Gedistribueerde%20Dataverwerking%20-%2005%20-%20batch%20processing28.png)

![](img/Gedistribueerde%20Dataverwerking%20-%2005%20-%20batch%20processing29.png)

![](img/Gedistribueerde%20Dataverwerking%20-%2005%20-%20batch%20processing30.png)

I need to run an algorithm on dataset                    \{

  * Works only if the algorithm can be executed independently on part of the data
  * Hadoop assumes system where storage and processing power are co\-located
    * Data is located on local disk of compute node \(requires a distributed file system\)
    * Try to assign computations to nodes that contain all necessary data
  * Otherwise: network communication required

# HADOOP: Assume failures are common

Built\-in redundancy in the Hadoop Distributed File System \(HDFS\)

Communication network

![](img/Gedistribueerde%20Dataverwerking%20-%2005%20-%20batch%20processing31.png)

![](img/Gedistribueerde%20Dataverwerking%20-%2005%20-%20batch%20processing32.png)

![](img/Gedistribueerde%20Dataverwerking%20-%2005%20-%20batch%20processing33.png)

![](img/Gedistribueerde%20Dataverwerking%20-%2005%20-%20batch%20processing34.png)

![](img/Gedistribueerde%20Dataverwerking%20-%2005%20-%20batch%20processing35.png)

* Assume failures are common: data redundancy required
* In case of node failure
  * Only work attributed to that node should be recomputed
  * Remaining work redistributed among other nodes
* In case a node is repaired / replaced
  * Node should be able to rejoin existing job

![](img/Gedistribueerde%20Dataverwerking%20-%2005%20-%20batch%20processing36.png)

# HADOOP: Access data linearly – avoid random access

* Example: 1 Terabyte DB: 1010 100\-byte records
  * Disk latency: ~10 ms
  * Disk throughput: ~100 MByte/s
  * Updating 1% of records using random access
    * 108 records x 10\-2 s/record \(latency only\)
      * = 106 seconds = 11\.57 days
  * Reading and rewriting the entire DB
    * 2 \(r/w\) x 1012 bytes x 10\-8 s/byte
      * = 2\.104 seconds = 5\.55 hours

# HADOOP: Hide system-level details from dev

Parallel programming is difficult

Code runs in unpredictable order

Race conditions\, deadlocks\, etc\.

Main idea is to be able to program the “what” \(i\.e\. functionality of the code\) and hide the “how” \(i\.e\. low\-level details\)

![](img/Gedistribueerde%20Dataverwerking%20-%2005%20-%20batch%20processing37.png)

Responsibilityof the programmer

Responsibilityof the framework

# RDBMS Versus Hadoop MapReduce

MapReduce suits applications where data is  <span style="color:#1E64C8">written once and read many times</span> \, whereas relational DB is good for datasets that are  <span style="color:#1E64C8">continually updated</span>

RDBMs handle  <span style="color:#1E64C8">structured data </span> \(defined format\)\, Hadoop works well on  <span style="color:#1E64C8">unstructured or semi\-structured data</span>  → designed to interpret data at processing time

Relational data often normalized to retain integrity and remove redundancy\. For Hadoop\, normalization poses problems because it makes reading a record a non\-local operation \(requiring joins\)\.

![](img/Gedistribueerde%20Dataverwerking%20-%2005%20-%20batch%20processing38.wmf)

![](img/Gedistribueerde%20Dataverwerking%20-%2005%20-%20batch%20processing39.wmf)

# Mapreduce basics

* MapReduce programming model \(algorithm published in 2004\)
  * Divide & conquer strategy
    * <span style="color:#1E64C8">Divide</span> : partition dataset into smaller\, independent chunks to be processed in parallel \( = “map”\)
    * <span style="color:#1E64C8">Conquer</span> : combine\, merge or otherwise aggregate the results from the previous step \(= “reduce”\)
  * Mappers and reducers
    * <span style="color:#1E64C8">Map</span>  task processes a subset of input \<key\, value> pairs
    * <span style="color:#1E64C8">Reduce</span>  task processes a subset of the intermediate pairs
  * Map function operates on a single input pair and outputs a list of intermediate pairs
  * Reduce function operates on a single key and all of its values and outputs a list of resulting \<key\, value> pairs
  * Sorting of intermediate keys between map and reduce phase
* Input files not modified\, output files created sequentially
* File reads and writes on  <span style="color:#1E64C8">distributed filesystem</span>

![](img/Gedistribueerde%20Dataverwerking%20-%2005%20-%20batch%20processing40.png)

Sortintermediatedata

Process partof the input

Process partof the input

# Example: Weather dataset - map

* Weather dataset with fields packed in one line with no delimiters
  * Want to know max temperature per year

![](img/Gedistribueerde%20Dataverwerking%20-%2005%20-%20batch%20processing41.wmf)

![](img/Gedistribueerde%20Dataverwerking%20-%2005%20-%20batch%20processing42.wmf)

# Weather dataset - Reduce

![](img/Gedistribueerde%20Dataverwerking%20-%2005%20-%20batch%20processing43.wmf)

![](img/Gedistribueerde%20Dataverwerking%20-%2005%20-%20batch%20processing44.wmf)

# Distributed file system - HDFS

* Hadoop’s implementation: Hadoop Distributed File System\, open source implementation of Google File System \(GFS\)
  * Other notable distributed file systems: Amazon S3\, Azure Blob Storage\, OpenStack Swift
* HDFS is based on shared\-nothing principle: commodity hardware connected by conventional datacentre network
  * <span style="color:#1E64C8">Daemon process </span> running on each machine\, exposing a network service that allows other nodes to access files stored on that machine
  * Central server \( <span style="color:#1E64C8">NameNode</span> \) keeps track of which file blocks are stored on which machine
  * Conceptually creates one big filesystem that can use space on disks of all machines running daemons
* To handle machine and disk failures\, file blocks are replicated on multiple machines
* Some HDFS deployments scale to tens of thousands of machines\, combining petabytes of storage

# HDFS workings

* Typical usage pattern
  * Huge files \(100s of GB to TBs\)
  * Data is rarely updated in place
  * Reads and appends are common
* Chunk servers
  * File is split into contiguous chunks
  * Typically each chunk is 16\-64MB
  * Each chunk replicated \(usually 2x or 3x\)
  * Try to keep replicas in different racks
* Master node
  * A\.k\.a\. NameNode in Hadoop’s HDFS
  * Stores metadata about where files are stored
  * May be replicated
* Client library for file access
  * Talks to master to find chunk servers
  * Connects directly to chunk servers to access data

![](img/Gedistribueerde%20Dataverwerking%20-%2005%20-%20batch%20processing45.png)

Bring computation to the data

Chunk servers also serve as compute servers

# Client reading data from HDFS

* Client opens file
* <span style="color:#1E64C8">NameNode</span>  knows location / addresses of blocks in the file
  * Datanodes sorted according to proximity to client
* Client receives an  <span style="color:#1E64C8">inputstream</span>  object which abstracts reading data from HDFS datanodes

![](img/Gedistribueerde%20Dataverwerking%20-%2005%20-%20batch%20processing46.wmf)

# Client writing data to HDFS

* Client creates file by calling  <span style="color:#1E64C8">create</span>
* <span style="color:#1E64C8">NameNode</span>  makes a record of new file
* Client receives an  <span style="color:#1E64C8">outputstream</span>  object abstracting block placement
  * Data is automatically replicated \(default replication level is three\)

![](img/Gedistribueerde%20Dataverwerking%20-%2005%20-%20batch%20processing47.wmf)

# Mapreduce data floW on HDFS

![](img/Gedistribueerde%20Dataverwerking%20-%2005%20-%20batch%20processing48.wmf)

![](img/Gedistribueerde%20Dataverwerking%20-%2005%20-%20batch%20processing49.wmf)

Multiple reduce tasks

Single reduce task

# Mapreduce – fixed steps

* Sequentially read \(a lot of\) data
* Map
  * Extract key\, values you care about
* Group by key: sort and shuffle
* Reduce
  * Aggregate\, summarize\, filter or transform
* Write result

<span style="color:#1E64C8">Outline stays the same</span>  <span style="color:#1E64C8">Only Map and Reduce steps change to fit the problem</span>

# mapReduce framework automation

* MapReduce environment takes care of
  * Partitioning the input data
  * Scheduling the program’s execution across a set of machines
  * Performing the shuffle / group\-by\-key step
  * Handling machine failures
  * Managing required inter\-machine communication

# Example: Building a text index

![](img/Gedistribueerde%20Dataverwerking%20-%2005%20-%20batch%20processing50.png)

![](img/Gedistribueerde%20Dataverwerking%20-%2005%20-%20batch%20processing51.png)

# Example: counting word occurrences

![](img/Gedistribueerde%20Dataverwerking%20-%2005%20-%20batch%20processing52.png)

# Example: k-mers in DNA

Problem: given a number of DNA sequences\, count the occurrences of all “words” of length k \(= k\-mers\)

Example \(with k = 3\)

Now\, assume that we have lots of input sequences

![](img/Gedistribueerde%20Dataverwerking%20-%2005%20-%20batch%20processing53.png)

# Example: Mapreduce k-mers

Sort key/value pairs by key

__map__  __ __ \(k1\, v1\)         list\[k2\, v2\]

Accepts an input key/value pair

Emits intermediate key/value pair\(s\)

  * __reduce__  __ __ \(k2\, list\[v2\]\)          list\[k3\, v3\]
  * Accepts intermediate key and all its associated values
  * Emits output value\(s\)

Sort key/value pairs by key

AAC\, 3

ACA\, 2

ACT\, 2

CAC\, 1

CTG\, 2

TGA\, 1

AACACA

AACTG

AACTGA

# Other relatively common examples

* Collating
  * Problem
    * Given a function f\, save/process all items for which f is equal
  * Solution
    * Mapper reads all items and emits  <span style="color:#1E64C8">\< f\(item\)\, item ></span>
    * Reducer processes all items with same  <span style="color:#1E64C8">f\(item\)</span>
* Filtering \(Grep\)\, Parsing\, Validation
  * Problem
    * Collect all items that meet some condition
  * Solution
    * Mapper: apply filtering\, parsing\, validation to each item \(some items outputted as\-is\, others converted according to rules \(e\.g\. cleaning\)
    * Use no reducer \(data will not be sorted\)
* Sorting
  * Solution
    * Mappers emit all items as value associated with the sorting key  <span style="color:#1E64C8">\< sorting key\, item ></span>
    * Use identity reducer \(does nothing but data will be sorted\)
      * Default reducer\, flushing any key/value pair given as input to output

---

Collating: 

Problem Statement: There is a set of items and some function of one item. It is required to save all items that have the same value of function into one file or perform some other computation that requires all such items to be processed as a group. The most typical example is building of forward indexes.
Solution:
The solution is straightforward. Mapper computes a given function for each item and emits value of the function as a key and item itself as a value. Reducer obtains all items grouped by function value and process or save them. In case of forward indexes, items are terms (words) and function is a document ID where the term was found.

Filtering (“Grepping”), Parsing, and Validation

Problem Statement: There is a set of records and it is required to collect all records that meet some condition or transform each record (independently from other records) into another representation. The later case includes such tasks as text parsing and value extraction, conversion from one format to another.

Solution:  Solution is straightforward – Mapper takes records one by one and emits accepted items or their transformed versions.

# Example: frequently bought together

* Webshop contains a very large log file that consists of a long list of user IDs and items that were bought by this user
  * userA	itemA
  * userB	itemB
  * userC	itemC
  * userA	itemB
  * userA	itemA
  * …
* Each user can occur multiple times \(recurring customer and/or multiple purchases\) and can buy the same item multiple times
* We want to generate for each item\, a list of 5 other items most frequently bought together

* __Solution \(step 1\): sorting and binning by userID__
  * Mapper emits  <span style="color:#1E64C8">\<userID\, item> </span> for all items
  * Identity reducer \(sorting\)

<span style="color:#002060">userA</span>  <span style="color:#002060">	</span>  <span style="color:#002060">itemA</span>

<span style="color:#002060">userA</span>  <span style="color:#002060">	</span>  <span style="color:#002060">itemB</span>

<span style="color:#002060">userA</span>  <span style="color:#002060">	</span>  <span style="color:#002060">itemA</span>

<span style="color:#002060">…</span>

<span style="color:#002060">userB</span>  <span style="color:#002060">	</span>  <span style="color:#002060">itemB</span>

<span style="color:#002060">userB</span>  <span style="color:#002060">	</span>  <span style="color:#002060">itemD</span>

<span style="color:#002060">userB</span>  <span style="color:#002060">	</span>  <span style="color:#002060">itemA</span>

<span style="color:#002060">…</span>

<span style="color:#002060">userC</span>  <span style="color:#002060">	</span>  <span style="color:#002060">itemC</span>

<span style="color:#002060">userC</span>  <span style="color:#002060">	</span>  <span style="color:#002060">itemB</span>

<span style="color:#002060">…</span>

<span style="color:#002060">userA</span>  <span style="color:#002060">	</span>  <span style="color:#002060">itemA</span>

<span style="color:#002060">userB</span>  <span style="color:#002060">	</span>  <span style="color:#002060">itemB</span>

<span style="color:#002060">userC</span>  <span style="color:#002060">	</span>  <span style="color:#002060">itemC</span>

<span style="color:#002060">userA</span>  <span style="color:#002060">	</span>  <span style="color:#002060">itemB</span>

<span style="color:#002060">userA</span>  <span style="color:#002060">	</span>  <span style="color:#002060">itemA</span>

<span style="color:#002060">userB</span>  <span style="color:#002060">    	</span>  <span style="color:#002060">itemD</span>

<span style="color:#002060">userB</span>  <span style="color:#002060">	</span>  <span style="color:#002060">itemA</span>

<span style="color:#002060">userC</span>  <span style="color:#002060">	</span>  <span style="color:#002060">itemB</span>

<span style="color:#002060">…</span>

__output after job 1__

* __Solution \(step 2\): solving the actual question__
  * Mapper emits all  <span style="color:#1E64C8">\<item\, item> </span> pairs that were bought together
  * Reducer counts item pairs and selects top 5

<span style="color:#002060"><</span>  <span style="color:#002060">itemA</span>  <span style="color:#002060">\, </span>  <span style="color:#002060">itemB</span>  <span style="color:#002060">></span>

<span style="color:#002060"><</span>  <span style="color:#002060">itemB</span>  <span style="color:#002060">\, </span>  <span style="color:#002060">itemA</span>  <span style="color:#002060">></span>

<span style="color:#002060">…</span>

<span style="color:#002060"><</span>  <span style="color:#002060">itemB</span>  <span style="color:#002060">\, </span>  <span style="color:#002060">itemD</span>  <span style="color:#002060">></span>

<span style="color:#002060"><</span>  <span style="color:#002060">itemB</span>  <span style="color:#002060">\, </span>  <span style="color:#002060">itemA</span>  <span style="color:#002060">></span>

<span style="color:#002060"><</span>  <span style="color:#002060">itemD</span>  <span style="color:#002060">\, </span>  <span style="color:#002060">itemB</span>  <span style="color:#002060">></span>

<span style="color:#002060"><</span>  <span style="color:#002060">itemD</span>  <span style="color:#002060">\, </span>  <span style="color:#002060">itemA</span>  <span style="color:#002060">></span>

<span style="color:#002060"><</span>  <span style="color:#002060">itemA</span>  <span style="color:#002060">\, </span>  <span style="color:#002060">itemB</span>  <span style="color:#002060">></span>

<span style="color:#002060"><</span>  <span style="color:#002060">itemA</span>  <span style="color:#002060">\, </span>  <span style="color:#002060">itemD</span>  <span style="color:#002060">></span>

<span style="color:#002060">…</span>

<span style="color:#002060"><</span>  <span style="color:#002060">itemC</span>  <span style="color:#002060">\, </span>  <span style="color:#002060">itemB</span>  <span style="color:#002060">></span>

<span style="color:#002060"><</span>  <span style="color:#002060">itemB</span>  <span style="color:#002060">\, </span>  <span style="color:#002060">itemC</span>  <span style="color:#002060">></span>

<span style="color:#002060">…</span>

<span style="color:#002060"><</span>  <span style="color:#002060">itemA</span>  <span style="color:#002060">\, </span>  <span style="color:#002060">itemB</span>  <span style="color:#002060">></span>

<span style="color:#002060"><</span>  <span style="color:#002060">itemA</span>  <span style="color:#002060">\, </span>  <span style="color:#002060">itemB</span>  <span style="color:#002060">></span>

<span style="color:#002060"><</span>  <span style="color:#002060">itemA</span>  <span style="color:#002060">\, </span>  <span style="color:#002060">itemD</span>  <span style="color:#002060">></span>

<span style="color:#002060">…</span>

<span style="color:#002060"><</span>  <span style="color:#002060">itemB</span>  <span style="color:#002060">\, </span>  <span style="color:#002060">itemA</span>  <span style="color:#002060">></span>

<span style="color:#002060"><</span>  <span style="color:#002060">itemB</span>  <span style="color:#002060">\, </span>  <span style="color:#002060">itemD</span>  <span style="color:#002060">></span>

<span style="color:#002060"><</span>  <span style="color:#002060">itemB</span>  <span style="color:#002060">\, </span>  <span style="color:#002060">itemA</span>  <span style="color:#002060">></span>

<span style="color:#002060"><</span>  <span style="color:#002060">itemB</span>  <span style="color:#002060">\, </span>  <span style="color:#002060">itemC</span>  <span style="color:#002060">></span>

<span style="color:#002060">…</span>

<span style="color:#002060"><</span>  <span style="color:#002060">itemC</span>  <span style="color:#002060">	</span>  <span style="color:#002060">itemB</span>  <span style="color:#002060">></span>

<span style="color:#002060">\.\.\.</span>

<span style="color:#002060"><</span>  <span style="color:#002060">itemD</span>  <span style="color:#002060">\, </span>  <span style="color:#002060">itemB</span>  <span style="color:#002060">></span>

<span style="color:#002060"><</span>  <span style="color:#002060">itemD</span>  <span style="color:#002060">\, </span>  <span style="color:#002060">itemA</span>  <span style="color:#002060">></span>

<span style="color:#002060">userA</span>  <span style="color:#002060">	</span>  <span style="color:#002060">itemA</span>

<span style="color:#002060">userA</span>  <span style="color:#002060">	</span>  <span style="color:#002060">itemB</span>

<span style="color:#002060">userA</span>  <span style="color:#002060">	</span>  <span style="color:#002060">itemA</span>

<span style="color:#002060">…</span>

<span style="color:#002060">userB</span>  <span style="color:#002060">	</span>  <span style="color:#002060">itemB</span>

<span style="color:#002060">userB</span>  <span style="color:#002060">	</span>  <span style="color:#002060">itemD</span>

<span style="color:#002060">userB</span>  <span style="color:#002060">	</span>  <span style="color:#002060">itemA</span>

<span style="color:#002060">…</span>

<span style="color:#002060">userC</span>  <span style="color:#002060">	</span>  <span style="color:#002060">itemC</span>

<span style="color:#002060">userC</span>  <span style="color:#002060">	</span>  <span style="color:#002060">itemB</span>

<span style="color:#002060">…</span>

compute top\-5 itemA

compute top\-5 itemB

compute top\-5 itemC

compute top\-5 itemD

__after mapper job2__

__output after job 1__

# Mapreduce workflows

* Previous example showed need for  <span style="color:#1E64C8">two</span>   <span style="color:#1E64C8">MapReduce passes</span>
* Very common for MapReduce jobs to be chained together into  <span style="color:#1E64C8">workflows</span>  so output of job becomes input to next job
  * No inherent workflow support in Hadoop MapReduce\, so usually done by outputting to a designated directory in HDFS and having second job configured to read from that directory
  * Separate workflow scheduler tools have been developed \(e\.g\. Azkaban\)

![](img/Gedistribueerde%20Dataverwerking%20-%2005%20-%20batch%20processing54.png)

# Mapreduce Coordination: master

* Master node takes care of coordination
  * Task status: idle\, in\-progress\, completed
  * Idle tasks get scheduled as workers become available
  * When map task completes\, it sends master: location and sizes of its R intermediate files\, one for each reducer
  * Master pushes info to reducers
* Master pings workers periodically to detect failures
  * Distributed implementation should produce same output as a non\-faulty sequential execution

![](img/Gedistribueerde%20Dataverwerking%20-%2005%20-%20batch%20processing55.png)

# Distributed Processing parallelism

![](img/Gedistribueerde%20Dataverwerking%20-%2005%20-%20batch%20processing56.png)

# How many map and reduce jobs

* M map tasks\, R reduce tasks
* Rule of a thumb
  * Make M much larger than the number of nodes in the cluster
  * One DFS chunk per map is common
  * Improves dynamic load balancing and speeds up recovery from worker failures
* Usually R is smaller than M
  * Because output is spread across R files

![](img/Gedistribueerde%20Dataverwerking%20-%2005%20-%20batch%20processing57.png)

# Advantages and disadvantages

* Advantages
  * Model easy to use\, hides details of parallelization and fault recovery
  * Many problems can be expressed in the MapReduce framework
  * Scales to thousands of machines
* Disadvantages
  * 1\-input\, 2\-stage data flow is rigid\, hard to adapt to other scenarios
  * Custom code is needed for even the most common operations e\.g\. filtering
  * Intransparent nature of map/reduce functions impedes optimization

# Mapreduce advanced features

# backup tasks

* Problem
  * Slow workers \(so\-called stragglers\) significantly lengthen the job completion time
    * Other jobs on machine
    * Bad disks
    * Weird things
* Solution
  * Spawn backup copies of tasks
    * Whichever one finishes first “wins”
* Effect
  * Dramatically shortens job completion time\, but must be able to eliminate redundant results
  * Increases load on cluster

# combiners

* Often a Map task will produce many pairs of form  <span style="color:#1E64C8">\(k\,v</span>  <span style="color:#1E64C8">1</span>  <span style="color:#1E64C8">\)</span> \, <span style="color:#1E64C8"> \(k\,v</span>  <span style="color:#1E64C8">2</span>  <span style="color:#1E64C8">\)</span> \, … for same key k
  * E\.g\.\, popular words in word count example
* Can save network time by pre\-aggregating values in mapper
  * Combine\(k\, list\(v1\)\) → v2
  * Combiner is usually the same as reduce function\, but running after map task on map worker

![](img/Gedistribueerde%20Dataverwerking%20-%2005%20-%20batch%20processing58.png)

# Combiners: example

* Back to word counting example
  * Combiner combines values of all keys of a single mapper \(single machine\)
  * Much less data needs to be copied and shuffled

![](img/Gedistribueerde%20Dataverwerking%20-%2005%20-%20batch%20processing59.png)

# Custom partition function

* Want to control how keys get partitioned over reducers
  * Inputs to map tasks are created by contiguous splits of input file
  * Reduce task requires records with same intermediate key end up at same worker
* System uses a default partition function
  * <span style="color:#1E64C8">hash\(key\) mod R</span> \, with R = number of reducers
* Sometimes useful to override hash function
  * E\.g\.\, hash\(hostname\(URL\)\) mod R ensures URLs from a host end up in same output file
    * URLs \(keys\) like [www\.ugent\.be](http://www.ugent.be/) and [www\.ugent\.be/ea/nl](http://www.ugent.be/ea/nl) would end up at different reducers

# The need for joins

* In many datasets common for one record to have an association with another record
  * Foreign key in relational model
  * Document reference in document model
  * Edge in graph model
* Denormalization can reduce need for joins
* In a DB\, executing query involving small number of records\, DB will use an index to quickly locate records of interest
  * If query involves joins → may require multiple index lookups
  * Issue: MapReduce has no concept of indexes
* When MapReduce job is given set of files as input → reads entire content of those files
  * In DB terms: full table scan
  * Very expensive if you only want to read a small number of records

# Example: analysis of user activity

* Left: log of events describing what logged\-in users did on a website \(a\.k\.a\. clickstream data\)
* Right: DB of users
* Can be considered a star schema
  * Log of events is the fact table
  * User DB is one of the dimensions
* Analytics task may correlate user activity with user profile information e\.g\. determine page popularity according to age group
  * Requires join of activity events with user profile DB
* Implementing this
  * Solution 1: go over activity events one by one and query user DB \(on a remote server\) for every user ID it encounters
    * Very poor performance\, could easily overwhelm the DB
  * Solution 2: dump user DB in file and put it in same distributed filesystem as log of user activity events

![](img/Gedistribueerde%20Dataverwerking%20-%2005%20-%20batch%20processing60.wmf)

# MAP-reduce joins and secondary sort

* Purpose of mapper is to extract a key and value from each input record
  * One set of mappers extracts  <span style="color:#1E64C8">\(user ID\, activity event\)</span>
  * Second set of mappers extracts  <span style="color:#1E64C8">\(user ID\, date of birth\)</span>
* MapReduce framework partitions mapper output by key and sorts key\-value pairs
  * All activity events and user record with same user ID become adjacent to each other in reducer input
  * MapReduce can arrange records to be sorted so reducer sees record from user DB first\, followed by activity events in timestamp order – technique known as  <span style="color:#1E64C8">secondary sort</span>
* Reducer performs actual join: called once for every user ID and thanks to secondary sort\, first value is date\-of\-birth
  * Reducer stores date of birth in local variable and iterates over activity events with same user ID\, outputting pairs of  <span style="color:#1E64C8">\(viewed\-</span>  <span style="color:#1E64C8">url</span>  <span style="color:#1E64C8">\, viewer\-age\-in\-years\)</span>
  * Subsequent map\-reduce jobs could calculate distribution of viewer ages for each URL and cluster by age group
* Known as  <span style="color:#1E64C8">sort\-merge joins</span>
  * Mapper output sorted by key
  * Reducers merge together sorted lists

![](img/Gedistribueerde%20Dataverwerking%20-%2005%20-%20batch%20processing61.wmf)

# Apache Hive and Pig

![](img/Gedistribueerde%20Dataverwerking%20-%2005%20-%20batch%20processing62.png)

![](img/Gedistribueerde%20Dataverwerking%20-%2005%20-%20batch%20processing63.png)

# Apache Hive

* Data warehouse software
* Declarative  <span style="color:#1E64C8">SQL\-like interface </span> to analyse data stored on Hadoop HDFS\, Amazon S3
* Easy data summarization
  * Simple Query language: Hive QL\, very similar to SQL
  * Querying from Hive shell\, Web UI\, applications
* Queries broken down into MapReduce jobs and executed across a Hadoop cluster
* Best used for batch jobs over large sets of immutable data \(e\.g\. log processing\, analytics\, creation of reports\)
  * High latency
  * Read\-based\, inappropriate for transaction processing \(OLTP\)
* Originated at Facebook
  * 2013: need to analyse 500\.000\.000 logs per day\, 75k queries
  * Used at Netflix\, Amazon Elastic MapReduce\, etc\.

[https://hive\.apache\.org/](https://hive.apache.org/)

![](img/Gedistribueerde%20Dataverwerking%20-%2005%20-%20batch%20processing64.png)

_Sample Hive_  _ Query Language statement:_

INSERT OVERWRITE TABLE pv\_users

SELECT pv\.\*\, u\.gender\, u\.age

FROM user u JOIN page\_view pv ON \(pv\.userid = u\.id\)

WHERE pv\.date = '2008\-03\-03';

---

Beeline = command line interface
Thrift = the Apache Thrift software framework, for scalable cross-language services development, combines a software stack with a code generation engine to build services that work efficiently and seamlessly between C++, Java, Python, PHP, Ruby, Erlang, Perl, Haskell, C#, Cocoa, JavaScript, Node.js, Smalltalk, OCaml and Delphi and other languages. 

![](img/Gedistribueerde%20Dataverwerking%20-%2005%20-%20batch%20processing65.png)

# Apache Pig

* Pig Latin procedural scripting language to create programs that run on Apache Hadoop
  * Data model: nested bags of items \->  <span style="color:#1E64C8">\(‘key1'\, 222\, \{\('value1'\)\,\('value2'\)\}\) </span>
  * Provides relational operators
    * JOIN\, GROUP BY\, etc\.
* Compiler produces sequences of MapReduce programs
* Compared to Hive
  * Quite similar\, Pig focusses on programming\, Hive focusses on declarative SQL\-like language
  * Both Pig and Hive operate on top of Hadoop
  * Both have an easier learning curve than MapReduce and can do things in much less code
* Originated @Yahoo\! around 2006

[https://pig\.apache\.org/](https://pig.apache.org/)

---

Nested bags: ('thing1', 222, {('value1'),('value2')}) alike

![](img/Gedistribueerde%20Dataverwerking%20-%2005%20-%20batch%20processing66.png)

# Apache Pig example

* User data in one file
* Visited website data in another
* Need
  * Top 5 most visited pages
  * By users age 18\-25

![](img/Gedistribueerde%20Dataverwerking%20-%2005%20-%20batch%20processing67.png)

# In MapReduce

![](img/Gedistribueerde%20Dataverwerking%20-%2005%20-%20batch%20processing68.jpg)

![](img/Gedistribueerde%20Dataverwerking%20-%2005%20-%20batch%20processing69.png)

# In Pig Latin

<span style="color:#000000">Users = </span>  <span style="color:#FF0000">load</span>  <span style="color:#000000"> </span>  <span style="color:#1E64C8">‘users’ </span>  <span style="color:#FF0000">as</span>  <span style="color:#000000"> \(name\, age\);</span>

<span style="color:#000000">Filtered = </span>  <span style="color:#FF0000">filter</span>  <span style="color:#000000"> Users </span>  <span style="color:#FF0000">by </span>  <span style="color:#000000">age >= 18 </span>  <span style="color:#FF0000">and</span>  <span style="color:#000000"> age <= 25; </span>

<span style="color:#000000">Pages = </span>  <span style="color:#FF0000">load</span>  <span style="color:#000000"> ‘</span>  <span style="color:#1E64C8">pages</span>  <span style="color:#000000">’ </span>  <span style="color:#FF0000">as</span>  <span style="color:#000000"> \(user\, </span>  <span style="color:#000000">url</span>  <span style="color:#000000">\);</span>

<span style="color:#000000">Joined = </span>  <span style="color:#FF0000">join</span>  <span style="color:#000000"> Filtered </span>  <span style="color:#FF0000">by</span>  <span style="color:#000000"> name\, Pages </span>  <span style="color:#FF0000">by</span>  <span style="color:#000000"> user;</span>

<span style="color:#000000">Grouped = </span>  <span style="color:#FF0000">group</span>  <span style="color:#000000"> Joined </span>  <span style="color:#FF0000">by</span>  <span style="color:#000000"> </span>  <span style="color:#000000">url</span>  <span style="color:#000000">;</span>

<span style="color:#000000">Summed = </span>  <span style="color:#FF0000">foreach</span>  <span style="color:#000000"> Grouped </span>  <span style="color:#FF0000">generate</span>  <span style="color:#000000"> group\,</span>  <span style="color:#000000">              </span>  <span style="color:#FF0000">count</span>  <span style="color:#000000">\(Joined\) </span>  <span style="color:#FF0000">as</span>  <span style="color:#000000"> clicks;</span>

<span style="color:#000000">Sorted = </span>  <span style="color:#FF0000">order</span>  <span style="color:#000000"> Summed </span>  <span style="color:#FF0000">by</span>  <span style="color:#000000"> clicks </span>  <span style="color:#FF0000">desc</span>  <span style="color:#000000">;</span>

<span style="color:#000000">Top5 = </span>  <span style="color:#FF0000">limit</span>  <span style="color:#000000"> Sorted 5;</span>

<span style="color:#FF0000">store</span>  <span style="color:#000000"> Top5 </span>  <span style="color:#FF0000">into</span>  <span style="color:#000000"> </span>  <span style="color:#1E64C8">‘top5sites’</span>  <span style="color:#000000">;</span>

![](img/Gedistribueerde%20Dataverwerking%20-%2005%20-%20batch%20processing70.png)

Grouped operation produces one record for each URL e\.g  <span style="color:#1E64C8">\(www\.twitter\.com\, \{\(</span>  <span style="color:#1E64C8">alice</span>  <span style="color:#1E64C8">\, 19\)\, \(bob\, 18\)\}\) \(www\.facebook\.com\, \{\(carol\, 24\)\, \(</span>  <span style="color:#1E64C8">alice</span>  <span style="color:#1E64C8">\, 19\)\, \(bob\, 18\)\}\)</span>

---

Grouped:  one record for each URL e.g (www.twitter.com, {(alice, 15), (bob, 18)}) (www.facebook.com, {(carol, 24), (alice, 14), (bob, 18)})



# Apache Spark

![](img/Gedistribueerde%20Dataverwerking%20-%2005%20-%20batch%20processing71.png)

* MapReduce issue = linear dataflow structure
  * Read → Process → Write
  * Reload data from stable storage on each iteration
* Spark aims for  <span style="color:#1E64C8">in\-memory processing</span> \, dealing with out\-of\-memory can be an issue
* Apache Spark → concept of  <span style="color:#1E64C8">Resilient Distributed Dataset</span>  \(RDD\)
  * __R__ esilient: if data in memory is lost\, it can be recreated
  * __D__ istributed: stored in memory across the cluster
  * __D__ ataset: coming from file\(s\) or created programmatically
* Spark facilitates implementation of
  * Iterative algorithms \(e\.g\. machine learning\)
  * Interactive / explorative data analysis
* 2024: 2006 contributors\, actively maintained / extended

[http://spark\.apache\.org/](http://spark.apache.org/)

![](img/Gedistribueerde%20Dataverwerking%20-%2005%20-%20batch%20processing72.png)

# Apache spark overview

* Apache Spark
  * Spark Core: common libraries / methods \(e\.g\. task scheduling\)
  * Spark SQL: working with structured data\, combining SQL DB queries with algorithm based analytics \(supports Hive\)
  * Spark Streaming: streaming data processing \(integrates with e\.g\. Kafka\)
  * MLlib: machine learning support
  * GraphX: graph support \(vertex / edge\)

![](img/Gedistribueerde%20Dataverwerking%20-%2005%20-%20batch%20processing73.png)

# Apache Spark pillars

* Computing API
  * Scala \(native\)\, Java\, Python\, R\, SQL
* Resource management
  * Stand\-alone\, YARN\, Mesos and Kubernetes
* Data Storage
  * HDFS \(or Cassandra\, etc\.\)
* Spark interaction
  * Spark Shell: interactive shell
  * Spark Context = main entry point to the Spark API
    * sc handle in Spark Shell
  * Spark Applications: for large scale data processing

![](img/Gedistribueerde%20Dataverwerking%20-%2005%20-%20batch%20processing74.png)

---

K8 = Kubernetes (see later)

# Example: file-based RDD

![](img/Gedistribueerde%20Dataverwerking%20-%2005%20-%20batch%20processing75.png)

Source: Cloudera Apache Spark Developer training

---

RDD = Resilient Distributed Dataset

# RDD operations

* Two types
  * Actions – returning values
    * Count
  * Transformations – define new RDDs based on current one
    * Filter
    * Map
    * Reduce

![](img/Gedistribueerde%20Dataverwerking%20-%2005%20-%20batch%20processing76.png)

---

Resilient Distributed Dataset
Filter: transformation returning a new RDD with a subset of the items in the original RDD (matching the filter parameter)

# Example: map and filter

![](img/Gedistribueerde%20Dataverwerking%20-%2005%20-%20batch%20processing77.png)

# RDDs

* RDDs can hold any type of element
  * Primitive types: integers\, characters\, bools\, strings\, etc\.
  * Sequence types: lists\, arrays\, tuples\, etc\.
  * Scala/Java serializable objects
  * Mixed types
* Some types of RDDs have additional functionality
  * Double RDDs: consisting of numeric data\, offering e\.g\. variance\, stdev methods
  * Pair RDDs: RDDs consisting of key\-value pairs
    * For use with map\-reduce algorithms

![](img/Gedistribueerde%20Dataverwerking%20-%2005%20-%20batch%20processing78.png)

# MapReduce example word count

![](img/Gedistribueerde%20Dataverwerking%20-%2005%20-%20batch%20processing79.png)

# Spark Word Count example

![](img/Gedistribueerde%20Dataverwerking%20-%2005%20-%20batch%20processing80.png)

---

Flatmap transforms an RDD into another RDD of potentially  different size (based on function / lambda argument)

![](img/Gedistribueerde%20Dataverwerking%20-%2005%20-%20batch%20processing81.png)

![](img/Gedistribueerde%20Dataverwerking%20-%2005%20-%20batch%20processing82.png)

# ReduceByKey

![](img/Gedistribueerde%20Dataverwerking%20-%2005%20-%20batch%20processing83.png)

# Spark storing back to file

![](img/Gedistribueerde%20Dataverwerking%20-%2005%20-%20batch%20processing84.png)

![](img/Gedistribueerde%20Dataverwerking%20-%2005%20-%20batch%20processing85.png)

# Spark ease-of-use

![](img/Gedistribueerde%20Dataverwerking%20-%2005%20-%20batch%20processing86.png)

# Newer features

* RDD was the first and fundamental data structure of Spark
  * Low\-level
* DataFrame API \(Spark >=v1\.3\)
  * Allows processing  <span style="color:#1E64C8">structured data</span>
  * Data organised into named columns \(e\.g\. relational database\)
  * Why DataFrame over RDD?
    * Memory savings \(binary format stored\)
    * Optimized query execution
* Dataset API \(Spark >= v1\.6\)
  * Builds further on DataFrame API
  * Provides  <span style="color:#1E64C8">type safety </span> and an  <span style="color:#1E64C8">object oriented programming interface</span>
  * More high\-level expressions and queries available

# Apache Zeppelin

![](img/Gedistribueerde%20Dataverwerking%20-%2005%20-%20batch%20processing87.png)

![](img/Gedistribueerde%20Dataverwerking%20-%2005%20-%20batch%20processing88.png)

* Apache project allowing rapid Spark script construction and visualisation of results
  * Web\-based notebook for interactive data analysis
  * Currently Zeppelin supports Scala \(Spark\)\, Python \(Spark\)\, SparkSQL\, Hive and more

[https://zeppelin\.apache\.org/](https://zeppelin.apache.org/)

![](img/Gedistribueerde%20Dataverwerking%20-%2005%20-%20batch%20processing89.png)

![](img/Gedistribueerde%20Dataverwerking%20-%2005%20-%20batch%20processing90.png)

# Spark versus Hadoop MapReduce

* On\-disk versus in\-memory processing
  * Hadoop MapReduce jobs process on\-disk
  * Apache Spark stores and processes data in\-memory
    * RAM access 10\-100 times faster than disk\-based access
    * Memory in the cluster will need to be at least as large as the amount of data to process
    * Memory cost >> disk cost
* Fault\-tolerance
  * In Hadoop MapReduce: intermediate files can be used as checkpoints
  * In Spark: achieved via recomputing RDD for the failed partition
* Type of jobs
  * For one\-pass Big Data jobs MapReduce may be the better choice
  * For iterative jobs Spark is the better choice
* Spark offers strongly reduced coding volume compared to MapReduce
* Spark has streaming capabilities via Spark Streaming \(see streaming section\)
* Spark maturity \(2014\) < MapReduce maturity \(2011\) \(but both are considered mature\)
* Ideally used symbiotic
  * Hadoop for distributed file system and processing of large immutable datasets \(e\.g\. Extract Transform Load\)
  * Spark for real\-time in\-memory processing of datasets that require it

# summary

# Summary

* Batch processing basics
  * Main ideas behind Hadoop
* Hadoop MapReduce
  * Programming model
  * Distributed Filesystem
  * Examples
  * Advanced features
* Hive and Pig
* Apache Spark
  * In\-memory\, RDD

# references

Course “Parallelle en gedistribueerde softwaresystemen” – Jan Fostier\, Filip De Turck\, Ghent University

Hadoop\, the definitive guide\, 4th edition\, Tom White\, O’Reilly

Apache Pig\, UTDallas\, Erik Jonsson School of Engineering & Computer Science

