# Stream processing

# Distributed Data Processing

# Recap: Data processing system Types

* Services \(online systems\)
  * Service waits for request or instruction from a client to arrive
  * When request is received service tries to handle it as quickly as possible and sends response back
  * Response time usually primary measure of performance of a service
  * Availability often also important
* Batch processing systems \(offline systems\)
  * Take a large amount of input data\, run a job to process it and produce output data
  * Jobs often take a while \(minutes/hours/days\)
  * Often scheduled to run periodically
  * Primary performance measure is usually throughput
    * Time it takes to crunch through an input dataset of a certain size
* __Stream processing systems \(near\-real\-time systems\)__
  * __Between online and offline/batch processing__
  * __Stream processor consumes inputs and produces outputs \(rather than responding to events\)__
    * __A stream job however operates on events shortly after they happen versus batch job operates on fixed set of input data__
  * __Allows stream processing systems to have lower latency than equivalent batch systems__

# Stream processing

* Continuous stream of data
  * High velocity
  * Low latency processing required
  * Typically
    * Unstructured log records
    * Sensor events
* Why streaming?
  * Because store\-first\, process later \(batch\) data processing architectures unable to offer the  <span style="color:#1E64C8">combination of latency and </span>  <span style="color:#1E64C8">throughput</span>  <span style="color:#1E64C8"> </span> requirements
* Scalable\, optimized architecture for near\-zero latency
  * Scalability through distributed execution over multiple servers/cores
  * Designed for 24/7 operation

![](img/Gedistribueerde%20Dataverwerking%20-%2006%20-%20stream%20processing0.jpg)

# Typical stream processing use cases

* IoT / Smart Cities
  * Traffic analysis\, congestion prediction\, travel time
* Oil & Gas
  * Real\-time analytics and automated actions to avert equipment failure
* Security intelligence
  * Fraud detection and cybersecurity alerts
    * Smart Grid consumption issues
    * SIM card misuse
    * SCADA intrusion attacks
* Industrial automation
  * Real\-time analytics and predictive action for manufacturing plan and quality issues
* Telecom
  * Real\-time call rating\, fraud detection\, QoS monitoring
* Cloud infrastructure and web clickstream analysis for IT operation

---

SCADA Supervisory Control And Data Acquisition: remote monitoring and control

# Stream processing vs Batch processing

* Big assumption in batch processing
  * <span style="color:#1E64C8">Input is bounded</span> : known and finite size
    * Batch process knows when it has finished reading its input
    * E\.g\. sort operation in MapReduce must read entire input before producing output
      * Last input record may just be the one with lowest key\, so needs to be the very first output record
* In reality:  <span style="color:#1E64C8">a lot of data is unbounded</span>
  * Batch processors must  <span style="color:#1E64C8">artificially divide data into chunks of fixed duration</span>
    * E\.g\. processing a day’s worth of data at the end of every day
    * Issue: changes in the input are only reflected in the output a day later
* What if we run the processing more frequently?
  * A second worth of data at the end of every second \( <span style="color:#1E64C8">micro\-batch</span> \)
  * Or continuously\, abandoning fixed time slices entirely and  <span style="color:#1E64C8">processing every event as it happens</span>
  * → Stream processing is born

# Transmitting event streams

* <span style="color:#1E64C8">Batch</span> : input and outputs of a job are  <span style="color:#1E64C8">files</span>
* <span style="color:#1E64C8">Streaming</span> : when input is a file first processing step is to  <span style="color:#1E64C8">parse it into a sequence of records</span>  \(called events\)
  * Record / event = small\, self\-contained immutable object
  * Usually contains a  <span style="color:#1E64C8">timestamp</span>  indicating when it happened
  * May be  <span style="color:#1E64C8">encoded</span>  as a text string\, JSON\, binary form\, etc\.
  * This encoding allows you to send event over network to another node to process it
* <span style="color:#1E64C8">Batch</span> : a file is  <span style="color:#1E64C8">written once</span>  and then potentially  <span style="color:#1E64C8">read by multiple jobs</span>
* <span style="color:#1E64C8">Streaming</span> : an  <span style="color:#1E64C8">event</span>  is generated once by a  <span style="color:#1E64C8">producer</span>  \(a\.k\.a\. publisher or sender\) and then potentially processed by multiple  <span style="color:#1E64C8">consumers</span>  \(a\.k\.a\. subscribers or recipients\)
  * In a streaming system related events are usually grouped into a  <span style="color:#1E64C8">topic</span>  or  <span style="color:#1E64C8">stream</span>

# Messaging systems

* Producer sends a message containing event
* Event is pushed to consumers
* Typically multiple producer nodes send messages to the same topic and allow multiple consumer nodes to receive messages in a topic
  * <span style="color:#1E64C8">Topic</span>  = named logical channel providing a logical grouping of events
* Messaging system implementations differ based on two questions
  * <span style="color:#1E64C8">What happens if producers send messages faster than consumers can process them</span> ?
    * System can  <span style="color:#1E64C8">drop</span>  messages
    * <span style="color:#1E64C8">Buffer</span>  messages in a queue
      * Does the system crash if queue no longer fits in memory? Does it write messages to disk? How does disk access impact performance?
    * Apply  <span style="color:#1E64C8">backpressure</span>  \(a\.k\.a\. flow control\)\, blocking producer from sending more messages
  * <span style="color:#1E64C8">What happens if nodes crash or temporarily go offline – are any messages lost</span> ?
    * Durability may require combination of writing to disk and / or replication
    * If you can afford to sometimes lose messages\, you can probably get higher throughput and lower latency

# Direct messaging systems

* A number of messaging systems use direct network communication between producers and consumers without going via intermediary nodes
  * StatsD and Brubeck use unreliable  <span style="color:#1E64C8">UDP messaging </span> for collecting metrics from machines on the network
  * <span style="color:#1E64C8">UDP multicast </span> is widely used in the financial industry for streams such as stock market feeds
  * Brokerless messaging libraries such as ZeroMQ and nanomsg take a similar approach\, implementing publish / subscribe messaging over  <span style="color:#1E64C8">TCP</span>  or  <span style="color:#1E64C8">IP multicast</span>
  * If the consumer exposes a service on the network\, producers can make a direct HTTP or RPC request to push messages to the consumer
    * <span style="color:#1E64C8">Webhook</span> : pattern in which a callback URL of one service is registered with another service and it makes a request to that URL whenever an event occurs
* Direct messaging systems generally require application code to be aware of possibility of message loss
  * Notable direct messaging protocols: AMQP \(Advanced Message Queuing Protocol\)\, JMS \(Java Message Service\)

# Message brokers

* Alternative to direct messaging: send messages via a message broker \(a\.k\.a\.  <span style="color:#1E64C8">message queue</span> \)
  * Essentially a DB optimized for handling message streams
  * Runs as a server with producers and consumers connecting to it as clients
* By centralizing data in broker
  * Able to more easily  <span style="color:#1E64C8">tolerate clients that come and go </span> \(connect\, disconnect\, crash\)
  * Question of  <span style="color:#1E64C8">durability</span>   <span style="color:#1E64C8">is moved to broker</span>
  * Some message brokers only keep messages in memory\, others write them to disk
* Events are typically  <span style="color:#1E64C8">unbounded queued </span> \(as opposed to dropping messages or backpressure\)
* Consumers are generally asynchronous: when a producer sends a message it only waits for confirmation from the broker

# Logs for message storage

* <span style="color:#1E64C8">Log</span> : append\-only sequence of records on disk
* Can be used to implement a message broker
  * Producer sends message by appending to end of log
  * Consumer receives messages by reading log sequentially
    * If consumer reaches end of log → waits for notification that new message has been appended
* To scale to higher throughput than single disk can offer\,  <span style="color:#1E64C8">log can be partitioned</span>
  * Different partitions can be hosted on different machines → separate log that can be read and written independently from other partitions
  * A  <span style="color:#1E64C8">topic</span>  can be defined as a group of partitions that all carry messages of the same type
* Within each partition the broker assigns an increasing sequence number \(a\.k\.a\.  <span style="color:#1E64C8">offset</span> \) to every message
  * Within a partition: messages are totally ordered
  * Across different partitions: no ordering guarantees

![](img/Gedistribueerde%20Dataverwerking%20-%2006%20-%20stream%20processing1.wmf)

* Notable implementations: Apache Kafka\, Amazon Kinesis Streams and Twitter’s DistributedLog
  * Able to achieve throughputs of millions of messages per second by partitioning across multiple machines
  * Fault tolerance by replicating topics

<span style="color:#1E64C8">Replication to achieve reliability</span>

<span style="color:#1E64C8">Partitioning to achieve performance goals</span>

![](img/Gedistribueerde%20Dataverwerking%20-%2006%20-%20stream%20processing2.jpg)

![](img/Gedistribueerde%20Dataverwerking%20-%2006%20-%20stream%20processing3.wmf)

Source: [https://www\.confluent\.io/blog/hands\-free\-kafka\-replication\-a\-lesson\-in\-operational\-simplicity/](https://www.confluent.io/blog/hands-free-kafka-replication-a-lesson-in-operational-simplicity/)

# Streaming technologies / frameworks

# Apache KAFKA

# Data pipelines

Start out easy

But tend to become gradually more complex

![](img/Gedistribueerde%20Dataverwerking%20-%2006%20-%20stream%20processing4.png)

![](img/Gedistribueerde%20Dataverwerking%20-%2006%20-%20stream%20processing5.png)

Until they become something like this

![](img/Gedistribueerde%20Dataverwerking%20-%2006%20-%20stream%20processing6.png)

![](img/Gedistribueerde%20Dataverwerking%20-%2006%20-%20stream%20processing7.png)

# Apache KafkA

[https://kafka\.apache\.org/](https://kafka.apache.org/)

Distributed streaming platform

Decouples data pipelines

Originated at LinkedIn\, Open\-sourced through Apache\, commercially exploited by Confluent

![](img/Gedistribueerde%20Dataverwerking%20-%2006%20-%20stream%20processing8.png)

# Apache Kafka concepts

* __Topics__ : categories that maintain streams of records \(key\, value\, timestamp\)
* __Producers__ : message\-generators that publish stream of records to topics
* __Consumers__ : message\-processers subscribe to topics
* __Connectors: __ connect topics to existing applications or systems \(e\.g\. connector to relational database capturing every change\)
* __Stream processors__ : consume input stream from one or more topics and produce output stream to one or more topics
* Kafka itself is run as a cluster on one or more servers \( __brokers\)__
* __High performance __ \(throughput & latency\)
  * Binary communication over TCP
  * Batching individual messages to lower network overhead
  * I/O optimization through Linux PageCache
    * Batch physical writes
    * Minimizing movement of disk head
    * Utilizing all free memory of machine
  * Single Kafka broker: hundreds of megabytes of reads and writes per second from thousands of clients
* __Fault\-tolerant __ and durable by design

![](img/Gedistribueerde%20Dataverwerking%20-%2006%20-%20stream%20processing9.png)

# Kafka topic partitions

* Topics broken into ordered commit logs called partitions
  * Records in a partition get a sequential ID \(offset\)
  * Data retained for configurable period of time\, whether or not they have been consumed e\.g\. two days
* Ordering only guaranteed within a partition
  * Group messages in partition by key \(e\.g\. producer\)
  * Configure one consumer instance per partition
* Guarantees
  * Messages sent by a producer to a topic appended in the order they are sent
  * For a topic with replication factor N\, Kafka tolerates N\-1 server failures without losing any messages committed to the log
  * In\-sync partition replicas = not too far \(configurable distance\) from partition leader

![](img/Gedistribueerde%20Dataverwerking%20-%2006%20-%20stream%20processing10.png)

![](img/Gedistribueerde%20Dataverwerking%20-%2006%20-%20stream%20processing11.png)

---

Topics should be replicated and partition is the unit of replication.

# Kafka producers

* Producers
  * Publish \(push\) to a topic of their choosing
  * Load distribution over topic partitions
    * Round\-robin
    * Based on key in the message

![](img/Gedistribueerde%20Dataverwerking%20-%2006%20-%20stream%20processing12.png)

![](img/Gedistribueerde%20Dataverwerking%20-%2006%20-%20stream%20processing13.png)

# Kafka consumers

Multiple consumers can read from the same topic

Each consumer manages own offset in topic

Messages stay on Kafka for a configured retention period

![](img/Gedistribueerde%20Dataverwerking%20-%2006%20-%20stream%20processing14.png)

# Kafka streams

* Newer Kafka feature \(introduced mid 2016\)
* Lightweight Java library for building streaming applications
* No external dependencies on systems other than Kafka
* Handles load balancing multiple instances of the streaming application
  * Uses partitioning model to scale horizontally
* Supports fault\-tolerant local application state
* Supports one\-record\-at\-a\-time processing \(ms latency\) and event\-time based windowing operations

![](img/Gedistribueerde%20Dataverwerking%20-%2006%20-%20stream%20processing15.jpg)

# Kafka stream concepts

* <span style="color:#1E64C8">Stream</span> : unbounded continuously updating data set\. Ordered\, replayable and fault\-tolerant sequence of immutable data records \(key/value pairs\)
* <span style="color:#1E64C8">Stream processing application: </span> defines computational logic through one or more processor topologies \(graph of stream processors \(nodes\) connected by streams \(edges\)
* <span style="color:#1E64C8">Stream processor: </span> node in the processor topology\, processing step that transforms data by receiving one input record at a time from upstream processors in the topology\, applying its operation to it\, and producing one or more output records to downstream processors
  * <span style="color:#1E64C8">Source processor</span> : special type that does not have any upstream processors \(consumes records from Kafka topics and forwards them to down\-stream processors\)
  * <span style="color:#1E64C8">Sink processor</span> : special type that does not have downstream processors \(processed results can be streamed back into Kafka or written to an external system\)
* Operations like map\, filter\, join\, aggregations supported out of the box
* A processor topology is an abstraction of your stream processing code
  * At runtime\, topology is instantiated and replicated for parallel processing

![](img/Gedistribueerde%20Dataverwerking%20-%2006%20-%20stream%20processing16.jpg)

# Kafka streams + and -

\+ Very light weight library\, good for microservices\, IoT

\+ Exactly once

\+ Inherits all good properties of Kafka

\+ Supports Stream joins and can maintain state

\-  Tightly coupled with Kafka

Not for heavy data processing work like Spark Streaming\, Flink

---

Other options next to exactly once: at least once, at most once

# Apache STORM

# Apache Storm

![](img/Gedistribueerde%20Dataverwerking%20-%2006%20-%20stream%20processing17.png)

* Created by Nathan Marz in 2010\, originated at Twitter \(Twitter itself moved to Heron\)
* Fast
  * Operates on tuples: named list of values\, each value of any type
  * Million 100\-byte tuples processed per second per node \(on 2x Intel E5645@2\.4Ghz\, 24GB RAM\)
* Scalable
  * Thousands of workers per cluster supported
  * On\-the\-fly topology changes supported
* Fault tolerant: Failure expected and taken into account
  * When workers die\, Storm will automatically restart them
  * If a node dies\, the worker will be restarted on another node
* Reliable
  * Guaranteed message delivery
  * Every tuple will be fully processed \(at\-least\-once\)
* Notable deployments
  * Twitter\*\, Yahoo\, Microsoft\, Alibaba\, Spotify\, Yelp\, Groupon
* Developed in Clojure \(Lisp dialect\) and Java

[http://storm\.apache\.org/](http://storm.apache.org/)

![](img/Gedistribueerde%20Dataverwerking%20-%2006%20-%20stream%20processing18.png)

---

/


# Storm concepts

* Works on Tuples
  * Named list of values\, each value of any type
* Streams = sequence of tuples
* Spout = source of streams \(e\.g\. Kafka\, RabbitMQ\, Amazon Kinesis\, Twitter streaming API\, Redis\)

![](img/Gedistribueerde%20Dataverwerking%20-%2006%20-%20stream%20processing19.png)

Public interface ISpout extends Serializable \{

void open\(Map conf\, TopologyContext context\,

SpoutOutputCollector collector\);

void close\(\);

void activate\(\);

void deactivate\(\);

void nextTuple\(\);

void ack\(Object msgId\);

void fail\(Object msgId\);

\}

<span style="color:#0070C0">Lifecycle management</span>

---

Amazon Kinesis = streaming data on Amazon EC2 (Elastic Cloud)
Redis = in-memory data store

# Storm - bolts

* Core function of a streaming computation
* Receive tuple and process it
  * Optionally: emit additional tuples
* Can
  * Read from a data store \(MongoDB\, Cassandra\, RDBM\, etc\.\)
  * Write to a data store \(MongoDB\, Cassandra\, RDBM\, etc\.\)
  * Perform computation

![](img/Gedistribueerde%20Dataverwerking%20-%2006%20-%20stream%20processing20.png)

Public interface IBolt extends Serializable \{

void prepare\(Map stormConf\, TopologyContext context\,

OutputCollector collector\);

void cleanup\(\);

void execute\(Tuple input\);

\}

<span style="color:#0070C0">Lifecycle management</span>

# Storm topologies

* Directed Acyclic Graph \(DAG\) representing data flow
  * Spouts and bolts are individual  __tasks__  and can run on multiple machines in parallel

![](img/Gedistribueerde%20Dataverwerking%20-%2006%20-%20stream%20processing21.png)

# Storm reliability

![](img/Gedistribueerde%20Dataverwerking%20-%2006%20-%20stream%20processing22.png)

Storm automatically adds reliability measures

If any tuple of the tree is not marked as processed within a time\-out\, Storm will replay the tuple starting from the spout: at\-least\-once processing

![](img/Gedistribueerde%20Dataverwerking%20-%2006%20-%20stream%20processing23.png)

# Apache Storm Trident

* Higher level micro\-batch system built on Storm \(also developed by Twitter\)
  * Simplifies DAG topology building
  * Adds windowing\, aggregations\, state management \(on top of database or persistent store\)
  * Adds ‘exactly once’ processing as opposed to ‘at least once’ in Storm
    * Very useful when dealing with state \(e\.g\. Tuple processed by bolt that increments a value in a database\)
  * Due to micro\-batching and state → latency higher than pure Storm
  * Java\, Clojure and Scala APIs

![](img/Gedistribueerde%20Dataverwerking%20-%2006%20-%20stream%20processing24.png)

# Storm + and -

\+ Very low latency\, true streaming\, mature and high throughput

\+ Excellent for non\-complicated streaming use cases

No implicit support for state management

No advanced features like event time processing\, aggregation\, windowing\, sessions\, etc\.

At least once guarantees only

Started to lag behind more modern options like Apache Spark / Apache Flink

# Apache HERON

![](img/Gedistribueerde%20Dataverwerking%20-%2006%20-%20stream%20processing25.png)

* Aimed to be the successor to Apache Storm developed by Twitter
  * But unsuccessful at gaining traction and was abandoned in 2023
* Performance sensitive components written in C\+\+
* Easier debugging / profiling
* Efficiency: reduced resource consumption
  * For Twitter: 3x reduction in cores and memory\, >10x reduction in production incidents
* Support for
  * Different workloads: throughput versus latency sensitive
  * Task execution model of choice: at most once\, at least once\, exactly once
  * Back pressure \(topologies self\-adjust when system is incapable of processing all incoming data\)
* Uses containers \(on top of e\.g\. Kubernetes\)

![](img/Gedistribueerde%20Dataverwerking%20-%2006%20-%20stream%20processing26.png)

# Apache SPARK Streaming

![](img/Gedistribueerde%20Dataverwerking%20-%2006%20-%20stream%20processing27.png)

# Spark Streaming

* Part of the Apache Spark ecosystem
* Divides live stream into microbatches
  * Pre\-defined interval \( __N__  seconds\)
  * Treats each minibatch as a Spark RDD \(Resilient Distributed Dataset\)
* Can use all Spark batch functionality on microbatches
* In\-use by a\.o\.
  * Uber \(real\-time telemetry analytics\)
  * Netflix \(real\-time online movie recommendation and data monitoring solution\)

[http://spark\.apache\.org/streaming/](http://spark.apache.org/streaming/)

![](img/Gedistribueerde%20Dataverwerking%20-%2006%20-%20stream%20processing28.png)

![](img/Gedistribueerde%20Dataverwerking%20-%2006%20-%20stream%20processing29.png)

# Spark Streaming compared to Storm

| Spark Streaming | Apache Storm |
| :-: | :-: |
| Micro-batch approach, events grouped based on pre-defined interval. True streaming was impossible until Spark introduced structured streaming (see lab) | Streaming approach, per-event handling. Micro-batch is possible in Storm via Trident API |
| Language model: Java, Scala, Python | Language model: Java, Clojure, Scala, Python, Ruby |
| Reliability model: exactly onceSpecific failure scenarios may introduce data loss | Reliability model: at least onceStorm Trident supports Exactly once |
| Performance measurements depend on use-case<br />e.g. one paper had Spark Streaming at 400.000 msg/sec, while Storm was handling 10.000 msg/sec Latency in seconds when micro-batching, 10s of ms when using structured streaming | Performance measurements depend on use-case<br />Example on low-power hardware with 3 nodes<br />Storm: ~150k msg. /sec with 80ms latencyTrident:~300k msg./sec with 250ms latency<br />Latency in the order of 10s of ms possible |
| Can be deployed stand-alone, on YARN, Mesos and Kubernetes | Can be deployed stand-alone or on YARN and Mesos. Kubernetes possible but strongly advise considering Spark or Flink if aiming for Kubernetes deployment |

---

At least once delivery means that for each message handed to the mechanism potentially multiple attempts are made at delivering it, such that at least one succeeds. Messages may be duplicated but not lost. 
Exactly once delivery means that for each message handed to the mechanism exactly one delivery is made to the recipient, the message can neither be lost nor duplicated.

# Apache Spark Streaming + And -

\+ High throughput\, good for many use cases where ms\-latency is not required

\+ Fault tolerance

\+ High level APIs

\+ Big community and rapidly being extended

\+ Exactly once

Lots of parameters to tune

Lags a bit behind Apache Flink in advanced features

# Apache Flink

![](img/Gedistribueerde%20Dataverwerking%20-%2006%20-%20stream%20processing30.png)

* Distributed streaming dataflow engine written in Java and Scala
  * Support for batch and stream processing programs \(in\-memory\, with disk spillover if needed\)
* Streams and transformations
  * Stream: potentially never ending flow of data records\, highly flexible windowing
    * Unbounded stream: start but no defined end
    * Bounded stream: defined start and end \(batches\)
  * Transformation: takes one or more streams as input and produces one or more output streams
* Reliability model: exactly once
  * Results are accurate\, even in case of out\-of\-order or late\-arriving data
* Stateful
* Fault tolerance: lightweight distributed checkpoints
* Data source and sink connectors to Amazon Kinesis\, Kafka\, HDFS\, Cassandra\, etc\.
* Runs as a distributed system on most cluster\-types
  * Standalone mode\, YARN\, Mesos\, Kubernetes
* Notable deployments: Alibaba\, Huawei\, Ebay\, Ericsson\, Zalando

[https://flink\.apache\.org/](https://flink.apache.org/)

![](img/Gedistribueerde%20Dataverwerking%20-%2006%20-%20stream%20processing31.png)

![](img/Gedistribueerde%20Dataverwerking%20-%2006%20-%20stream%20processing32.png)

![](img/Gedistribueerde%20Dataverwerking%20-%2006%20-%20stream%20processing33.png)

# Apache FLINK typical usage

![](img/Gedistribueerde%20Dataverwerking%20-%2006%20-%20stream%20processing34.png)

# Apache Flink + and -

\+ Leader of innovation in open\-source streaming

\+ True streaming framework with advanced features \(event time processing\, watermarks\, etc\)\.

\+ Low latency with high throughput\, configurable to meet demands

\+ Auto\-adjusting and not too many parameters to tune

\+ Exactly once

\+ Getting large operational deployments \(Uber\, Alibaba\)

Later than Spark\, lack of adoption initially

Smaller community than Spark

# SPRING Cloud Data Flow

# Spring Cloud Data Flow

![](img/Gedistribueerde%20Dataverwerking%20-%2006%20-%20stream%20processing35.png)

* Data processing pipeline that uses Spring Boot microservices
  * Each microservice takes in a message and produces a message\, containing the data that you are processing
* Spring Boot = JVM framework for building microservices
* Open\-source\, Java\-based

[http://cloud\.spring\.io/spring\-cloud\-dataflow/](http://cloud.spring.io/spring-cloud-dataflow/)

![](img/Gedistribueerde%20Dataverwerking%20-%2006%20-%20stream%20processing36.png)

# Designing a data processing pipeline

* Understand source data
  * What does an invididual message contain? → a single tweet
* Understand the function of your pipeline
  * What do you want to filter? → a set of hash tags in the body of a Tweet
* Understand what you want to measure
  * Trending analytics in real time
* Understand the output
  * The velocity of hash tag counts from specific tweets every second
* What is the result of our measurements
  * Real time streaming analytics to make informed decisions
  * A graph showing the velocity of each tweet and its hash tags over time

# Data processing pipeline example

![](img/Gedistribueerde%20Dataverwerking%20-%2006%20-%20stream%20processing37.png)

# Input and output channels

Spring Boot Microservice

![](img/Gedistribueerde%20Dataverwerking%20-%2006%20-%20stream%20processing38.png)

# Tweet source module

![](img/Gedistribueerde%20Dataverwerking%20-%2006%20-%20stream%20processing39.png)

* Source module responsibilities
  * Ingest data from multiple sources
    * Streaming REST API
    * HDFS
  * Transform a stream into discrete messages
    * E\.g\. Individual Tweets
  * Output those messages to an output channel for next service to process

![](img/Gedistribueerde%20Dataverwerking%20-%2006%20-%20stream%20processing40.png)

# Filter module

![](img/Gedistribueerde%20Dataverwerking%20-%2006%20-%20stream%20processing41.png)

* Filter module responsibilities
  * Filter messages from source module
  * Filter noise to increase quality of measurements in downstream modules

![](img/Gedistribueerde%20Dataverwerking%20-%2006%20-%20stream%20processing42.png)

# Processor module

![](img/Gedistribueerde%20Dataverwerking%20-%2006%20-%20stream%20processing43.png)

* Processor module responsibilities
  * Take filtered stream of messages
    * Produce multiple output messages by transforming the payload into multiple dimensions of attributes
  * Example: take \#java2days tweet and parse other hash tags\, output one message per hash tag
    * \#java2days \-> \#Java\, \#SpringBoot\, \#JavaEE

![](img/Gedistribueerde%20Dataverwerking%20-%2006%20-%20stream%20processing44.png)

# Counter module

![](img/Gedistribueerde%20Dataverwerking%20-%2006%20-%20stream%20processing45.png)

* Counter module responsibilities
  * Take messages from input channel
    * Output an increment to multiple buckets that count message attributes over time
  * Save the results to a sink \(e\.g\. database\)

![](img/Gedistribueerde%20Dataverwerking%20-%2006%20-%20stream%20processing46.png)

# Scaling the pipeline

* Services in the pipeline can be scaled up and down automatically to handle the load
  * Can be deployed on YARN\, Kubernetes\, Mesos\, Pivotal Cloud Foundry\, etc\.

![](img/Gedistribueerde%20Dataverwerking%20-%2006%20-%20stream%20processing47.png)

# Real-time analytics on Twitter data

![](img/Gedistribueerde%20Dataverwerking%20-%2006%20-%20stream%20processing48.png)

# Apache Beam

![](img/Gedistribueerde%20Dataverwerking%20-%2006%20-%20stream%20processing49.png)

[https://beam\.apache\.org/](https://beam.apache.org/)

* Attempts to avoid platform lock\-in
* Use a single programming model for both batch and streaming use cases \(Java\, Python or Go\)
* Execute pipelines as runners on multiple execution environments
  * Apache Flink\, Apache Spark\, Apache Samza\, Google Cloud Dataflow\, etc\.

![](img/Gedistribueerde%20Dataverwerking%20-%2006%20-%20stream%20processing50.png)

# Visual dataflow Management

# Apache NiFi

![](img/Gedistribueerde%20Dataverwerking%20-%2006%20-%20stream%20processing51.png)

[https://nifi\.apache\.org/](https://nifi.apache.org/)

* Web\-based visual management of \(IoT\) data flows
* Helps move and track data \(focus on performance\)
  * Data itself processed by Hadoop\, Storm\, etc\.
* Originated at NSA intelligence gathering

![](img/Gedistribueerde%20Dataverwerking%20-%2006%20-%20stream%20processing52.png)

![](img/Gedistribueerde%20Dataverwerking%20-%2006%20-%20stream%20processing53.png)

# StreamSets

[https://streamsets\.com/](https://streamsets.com/)

Web\-based visual management of data flow performance

![](img/Gedistribueerde%20Dataverwerking%20-%2006%20-%20stream%20processing54.png)

# So many CHOICEs!

![](img/Gedistribueerde%20Dataverwerking%20-%2006%20-%20stream%20processing55.png)

# Streaming frameworks overview by Databaseline (2016)

![](img/Gedistribueerde%20Dataverwerking%20-%2006%20-%20stream%20processing56.png)

[https://databaseline\.bitbucket\.io/an\-overview\-of\-apache\-streaming\-technologies/](https://databaseline.bitbucket.io/an-overview-of-apache-streaming-technologies/)

![](img/Gedistribueerde%20Dataverwerking%20-%2006%20-%20stream%20processing57.png)

# Comparison of top streaming frameworks (2018)

![](img/Gedistribueerde%20Dataverwerking%20-%2006%20-%20stream%20processing58.jpg)

[https://opensourceforu\.com/2018/03/a\-quick\-comparison\-of\-the\-five\-best\-big\-data\-frameworks/](https://opensourceforu.com/2018/03/a-quick-comparison-of-the-five-best-big-data-frameworks/)

![](img/Gedistribueerde%20Dataverwerking%20-%2006%20-%20stream%20processing59.png)

# Apache software foundation

[https://projects\.apache\.org/projects\.html?category](https://projects.apache.org/projects.html?category)

Keep track of relevant Big Data projects from Apache

![](img/Gedistribueerde%20Dataverwerking%20-%2006%20-%20stream%20processing60.png)

# How to choose your best streaming framework

* Depends on use case
  * If simple\, no need to go for the latest / greatest framework if complicated to learn or deploy
    * Kafka Streams
* Future considerations
  * Potential need for advanced features \(event time processing\, aggregation\, stream joins\)?
    * Storm has no notion of state
    * Spark Streaming or Apache Flink
* Existing technology stack
  * Do you already use Kafka? Kafka Streams or Samza may be an easy fit
  * Do you already use Spark? Spark Streaming may be a natural fit

# Summary

# summary

* Stream processing concepts
  * Message brokering: traditional versus log\-based
* Stream processing technologies / frameworks
  * Kafka
  * Apache Storm\, Apache Heron
  * Apache Spark Streaming
  * Apache Flink
  * Spring Cloud Data Flow
  * Apache Beam
* Visual dataflow management
* Handling choice

