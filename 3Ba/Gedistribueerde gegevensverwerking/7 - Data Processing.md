# Data processing Architectures

# Distributed Data Processing

# Lambda Architecture

* Designed by Nathan Marz \(2013\)
  * Based on his experiences in working on distributed big data processing systems at Twitter
  * Let’s take advantage of batch ánd stream processing
* Only mentioned for historical reasons\, ideas brought forth newer architectures

![](img/Gedistribueerde%20Dataverwerking%20-%2007%20-%20data%20processing%20architectures0.png)

---

Nathan Marz who also conceived Storm

# Lambda – speed / streaming layer

* Handles all requests that require low latency
* Deals with recent data only\, providing a real\-time view on that data
* Not as accurate and complete as the views produced by the batch layer
  * Technology used e\.g\. Apache Storm or Spark Streaming
* Output usually stored in NoSQL databases \(e\.g\. Cassandra\)

![](img/Gedistribueerde%20Dataverwerking%20-%2007%20-%20data%20processing%20architectures1.png)

# Lambda – batch layer

* Manages master \(all data\) dataset
  * Append\-only set of raw data usually on distributed filesystem
* Computes batch views
  * Technology used e\.g\. Apache Hadoop
* Accuracy → processing  _all_  data when generating views
  * Output usually stored in read\-only database

![](img/Gedistribueerde%20Dataverwerking%20-%2007%20-%20data%20processing%20architectures2.png)

# Lambda – serving layer

Serves output from batch and speed layer for querying

Stored on e\.g\. Hbase \(open\-source non\-relational distributed database modeled after Google BigTable\)

![](img/Gedistribueerde%20Dataverwerking%20-%2007%20-%20data%20processing%20architectures3.png)

# Lambda architecture - The downsides

* Need to maintain two complex distributed systems \(batch and stream\)
* Need to create apps for two different systems
  * Storm / Spark Streaming
  * Hadoop
* Debugging and interaction with products is different

![](img/Gedistribueerde%20Dataverwerking%20-%2007%20-%20data%20processing%20architectures4.png)

![](img/Gedistribueerde%20Dataverwerking%20-%2007%20-%20data%20processing%20architectures5.png)

![](img/Gedistribueerde%20Dataverwerking%20-%2007%20-%20data%20processing%20architectures6.png)

# Spring XD

* Spring XD = eXtreme Data
  * High\-throughput distributed data ingestion
    * Variety of input sources into big data store
  * Real\-time analytics at ingestion time
  * Workflow management via batch jobs
    * Interactions with standard enterprise systems \(RDBMS\)
    * Hadoop operations
  * High throughput data export
    * From HDFS to RDBMS or NoSQL DB
* Lambda approach
* Jul 2017: End\-of\-Life in favor of Spring Cloud Data Flow

[http://projects\.spring\.io/spring\-xd/](http://projects.spring.io/spring-xd/)

# Kappa architecture

* Simplification of Lambda architecture \(Kappa origin: LinkedIn\)
  * In short: remove the batch processing system
  * Make the streaming system also deal with historical data
* Data stored in a Kappa architecture is an append\-only immutable log \(e\.g\. Kafka or DistributedLog\)
* Log streams data through stream processing system e\.g\. Apache Storm\, Spark Streaming\, Kafka Streams\, Flink
  * Only one \(streaming\) code set needs to be maintained
* Output stored in auxiliary stores for serving \(any type of DB suffices\)
  * Can be deleted & regenerated from canonical data store \(immutable log\)

![](img/Gedistribueerde%20Dataverwerking%20-%2007%20-%20data%20processing%20architectures7.png)

# Approach

* Use e\.g\. Kafka to store incoming data in an immutable log
  * Retain full log of data you wish to reprocess \(retention interval\)
  * Allows multiple subscribers
* When wishing to reprocess
  * Start second instance of stream processing job
    * Begin processing from beginning of retained data
    * Direct output to a new output table
  * When second job catches up
    * Switch application to read from new table
    * Stop old version of the stream processing job and optionally delete old output table

![](img/Gedistribueerde%20Dataverwerking%20-%2007%20-%20data%20processing%20architectures8.png)

# Kappa Architecture discussion

* Four pillars
  * Data is immutable
  * Everything is a stream
  * Single stream engine is used
  * Data can be replayed
* Only need to do reprocessing when you change the processing code
* Downside: extra temporary storage when reprocessing
* Can be seen as a big data processing design pattern

![](img/Gedistribueerde%20Dataverwerking%20-%2007%20-%20data%20processing%20architectures9.png)

# Apache Samza

![](img/Gedistribueerde%20Dataverwerking%20-%2007%20-%20data%20processing%20architectures10.png)

* Stream processing based on Kappa architecture\, originated at LinkedIn
  * Optimised for fast\, near\-realtime processing
  * Inherent support for state \(locally stored\)
* Scalable
  * LinkedIn has > million messages/s processed
  * Kafka \+ YARN\, experimental: Kubernetes
* APIs: low\-level \+ stream \+ Samza SQL
* Fault tolerant
* Reliable
  * At\-least\-once message guarantees
* Notable deployments
  * LinkedIn \(origin\)\, Slack\, Ebay\, TripAdvisor

[http://samza\.apache\.org/](http://samza.apache.org/)

![](img/Gedistribueerde%20Dataverwerking%20-%2007%20-%20data%20processing%20architectures11.png)

# Apache Samza + and -

\+ Fault tolerant and high performance due to reliance on Kafka

\+ If you already use Yarn and Kafka\, Samza can be a natural choice

\+ Low latency\, high throughput\, mature and tested at scale

Tightly coupled with Kafka and Yarn

At least once guarantees

Lack of advanced streaming features like watermarks\, sessions\, triggers\, etc\.

Not seeing that much activity lately

# Zeta architecture

![](img/Gedistribueerde%20Dataverwerking%20-%2007%20-%20data%20processing%20architectures12.png)

* Zeta = 7 in Greek numericals
* 7 components
  * Enterprise applications
  * Solution architecture
  * Compute model / execution engine
  * Distributed file system
  * Real\-time data storage
  * Container system
  * Global Resource Management
* Google one of the pioneers

# Zeta implications

* All servers
  * Under supervision of global resource management
  * Participate in Distributed File System
* Dynamic allocation of resources
  * Starting more web servers\, business apps\, big data analytics
* Data locality
  * Store and process data where it was created

![](img/Gedistribueerde%20Dataverwerking%20-%2007%20-%20data%20processing%20architectures13.png)

# Simplified architecture

* Better resource utilization
  * Instead of hardwiring resources to e\.g\. stream or batch processing
  * Cost reduction
* Container deployment model
  * Repeatability between environments \(dev\, production\)
* Shared file system
  * Get the data from anywhere in the cluster

![](img/Gedistribueerde%20Dataverwerking%20-%2007%20-%20data%20processing%20architectures14.png)

![](img/Gedistribueerde%20Dataverwerking%20-%2007%20-%20data%20processing%20architectures15.png)

# MapR

[https://mapr\.com/](https://mapr.com/)

* Software company developing and selling Apache Hadoop\-derived software
* Contributors to Pig\, Apache Hive\, Apache ZooKeeper
* Early 2016: release of MapR Data Platform
  * MapR filesystem: HDFS API with native C distributed read\-write file system
  * MapR\-DB: implements the HBase API
  * MapR\-Streams: implements the Kafka API
* Aim: combined support for
  * Batch\, interactive streaming and real\-time applications
* Broke MinuteSort benchmark record on Google Compute Engine in 2013
  * 15 billion 100 byte records sorted in 59 seconds
* Worked on an acquisition deal with Hewlett Packard Enterprise in 2019 but the deal failed and MAPR shut down operations when it failed to secure additional investments

# What are the big companies doing?

# Google Zeta architecture

![](img/Gedistribueerde%20Dataverwerking%20-%2007%20-%20data%20processing%20architectures16.png)

![](img/Gedistribueerde%20Dataverwerking%20-%2007%20-%20data%20processing%20architectures17.png)

# Google Cloud Dataproc

![](img/Gedistribueerde%20Dataverwerking%20-%2007%20-%20data%20processing%20architectures18.png)

[https://cloud\.google\.com/dataproc/](https://cloud.google.com/dataproc/)

* Managed Spark\, Flink\, Presto and Hadoop service \(batch processing\)
* Integrated with Google Cloud Platform
* Ease\-of\-use
  * Create\, monitor\, delete Cloud Dataproc clusters and jobs through Google Developers console
  * Latest stable Spark\, Flink and Hadoop software releases
* Low\-cost
  * 0\.01 $ per virtual CPU in your cluster per hour
* Speed
  * Cluster start and stop operations take 90 seconds or less
* Iterative processing and notebooks
* Allows machine learning with Spark ML

# Google Cloud Dataflow

![](img/Gedistribueerde%20Dataverwerking%20-%2007%20-%20data%20processing%20architectures19.png)

[https://cloud\.google\.com/dataflow/](https://cloud.google.com/dataflow/)

* Unified programming model \(donated to Apache Beam\)
  * For defining / building batch and streaming data processing pipelines
  * Monitor their execution
  * Transform and analyse data
* Dataflow itself is a Google\-proprietary solution\, Integrated with Google Cloud Platform
  * Fully managed service
  * Handles resource lifetime \(serverless\)
  * Dynamically provision resources to reach latency goal or high utilization efficiency
* Competitive pricing \(retrieved 15/04/2023\)

![](img/Gedistribueerde%20Dataverwerking%20-%2007%20-%20data%20processing%20architectures20.png)

![](img/Gedistribueerde%20Dataverwerking%20-%2007%20-%20data%20processing%20architectures21.png)

![](img/Gedistribueerde%20Dataverwerking%20-%2007%20-%20data%20processing%20architectures22.png)

# Microsoft Azure HDInsight

* User\-friendly set up of open source big data solutions \+ cluster
* Managed Hadoop\, Spark service \(PaaS\)
  * Hive\, Kafka\, etc\. available
  * \.NET SDK and Powershell integration
* On top of Microsoft Azure Cloud\, integrating with Data Factory and Data Lake Storage

[https://azure\.microsoft\.com/en\-us/services/hdinsight/](https://azure.microsoft.com/en-us/services/hdinsight/)

![](img/Gedistribueerde%20Dataverwerking%20-%2007%20-%20data%20processing%20architectures23.png)

![](img/Gedistribueerde%20Dataverwerking%20-%2007%20-%20data%20processing%20architectures24.png)

# Microsoft Azure Stream Analytics

* Microsoft Azure based stream processing solution
  * Standalone Microsoft solution
  * SQL\-like language to transform\, enrich and correlate data
  * Pro: Easy to use\, easy to scale\, good integration with Azure\, cheap
  * Con: proprietary / vendor lock\, limited integration with non\-Azure products\, aimed at non\-complex streaming applications

[https://azure\.microsoft\.com/en\-us/services/stream\-analytics/](https://azure.microsoft.com/en-us/services/stream-analytics/)

![](img/Gedistribueerde%20Dataverwerking%20-%2007%20-%20data%20processing%20architectures25.png)

![](img/Gedistribueerde%20Dataverwerking%20-%2007%20-%20data%20processing%20architectures26.png)

# Amazon EMR - Elastic Map Reduce

[https://aws\.amazon\.com/emr/](https://aws.amazon.com/emr/)

Amazon managed Spark\, Hive\, Presto framework

Running on Amazon EC2

Can process data from HDFS\, Amazon S3\, DynamoDB\, Kinesis

CloudWatch monitors performance and can trigger scale\-up / scale down

Notable users: Netflix\, Expedia\, Yelp

![](img/Gedistribueerde%20Dataverwerking%20-%2007%20-%20data%20processing%20architectures27.png)

![](img/Gedistribueerde%20Dataverwerking%20-%2007%20-%20data%20processing%20architectures28.png)

# Amazon KinesiS

* Amazon’s AWS stream processing solution
* Amazon Kinesis Streams: collect and process large streams of data in real time \(proprietary or Spark on EMR\)
  * Thread with care when choosing the proprietary solution

[https://aws\.amazon\.com/kinesis/](https://aws.amazon.com/kinesis/)

![](img/Gedistribueerde%20Dataverwerking%20-%2007%20-%20data%20processing%20architectures29.png)

![](img/Gedistribueerde%20Dataverwerking%20-%2007%20-%20data%20processing%20architectures30.png)

# Amazon Lambda - serverless architecture

[https://aws\.amazon\.com/lambda/](https://aws.amazon.com/lambda/)

Build and run applications without thinking about servers \(function\-as\-a\-service\)

Lets you run your code without provisioning / managing servers\, just provide triggers \(e\.g\. response time\) which will be monitored

All other Cloud vendors soon followed suit and released their own serverless solutions

![](img/Gedistribueerde%20Dataverwerking%20-%2007%20-%20data%20processing%20architectures31.png)

![](img/Gedistribueerde%20Dataverwerking%20-%2007%20-%20data%20processing%20architectures32.png)

# Hortonworks + ClouDera

[https://www\.cloudera\.com/](https://www.cloudera.com/)

* Hortonworks: US\-based company offering enterprise data processing solutions \(Hadoop/Spark\)
* Cloudera: US\-based company focussed on enterprise data cloud solutions \(private \+ public\)
* Merged in January 2019\, considered one of the larger players now in enterprise data solutions
* High focus on open\-source solutions and paid\-for support
  * More than likely surviving due to the big cloud vendors initially not focussing on the on\-premise market \(note: this is changing\!\)

![](img/Gedistribueerde%20Dataverwerking%20-%2007%20-%20data%20processing%20architectures33.gif)

# summary

![](img/Gedistribueerde%20Dataverwerking%20-%2007%20-%20data%20processing%20architectures34.jpg)

# It’s a jungle out there

# summary

* Data processing architectures
  * Lambda architecture: Spring XD
  * Kappa architecture: Apache Samza
  * Zeta architecture: MapR\, Google
* Companies offering Enterprise\-grade products and support
  * Google\, Amazon\, Microsoft\, Cloudera \+ Hortonworks\, IBM\, etc\.

# Choosing a data processing platform

* Runtime programming model
  * Streaming\, micro\-batch\, batch\, etc\.
* Functional primitives
  * Map\, filter\, aggregate\, join
* State management
* Message delivery guarantees
  * At most once\, at least once\, exactly once
* Failure\-handling
* Latency\, throughput\, scalability
* Maturity and adoption
* Ease of development
* Ease of operability
* Roadmap: where is it heading?

![](img/Gedistribueerde%20Dataverwerking%20-%2007%20-%20data%20processing%20architectures35.png)

![](img/Gedistribueerde%20Dataverwerking%20-%2007%20-%20data%20processing%20architectures36.jpg)

# 

Department of Information Technology – Internet Based Communication Networks and Services \(IBCN\)

