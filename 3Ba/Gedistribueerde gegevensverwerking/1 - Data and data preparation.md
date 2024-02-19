# Data and data preparation

## Data - Distributed data processing

### Setting

#### Large-scale data is everywhere

* Enormous data growth in both commercial and scientific databases
* New mantra
    * Gather whatever data you can whenever and wherever you can
* Expectations
    * Gathered data will have value either for the purpose collected or for some other purpose

### Data Mining

#### Why data mining? Commercial P.O.V.

* Lots of data is being collected and stored
* Computers have become cheaper and more powerful
* Competitive pressure is strong
    * Provide better, customized services for an edge (e.g. personalized marketing)

#### Why data mining? Scientific P.O.V.

* Data collected and stored at enormous speeds
    * Remote sensors on a satellite
    * Telescopes scanning the skies
    * ...
* Data mining helps scientists
    * In automated scientific data analysis
    * In hypothesis formation

#### What is data mining?

* Non-trivial extraction of implicit, previously unknown, and potentially useful information from data
* Exploration & analysis, by automatic or semi-automatic means, of large quantities of data in order to discover meaningful patterns
* Discover models that are:
    * **Valid**: hold on new data with some certainty
    * **Useful**: should be possible to act on
    * **Unexpected**: non-obvious
    * **Understandable**: humans should be able to interpret the pattern

#### Data mining: cultures

* Data mining overlaps with
    * Databases: large-scale data, simple queries
    * Machine learning: *small* data, complex models
    * Computer Science theory: algorithms
* Different cultures
    * To a DB person, data mining is an extreme form of analytic processing - queries that examine large amounts of data
    * To a ML person, data-mining is the interference of models

#### Data mining tasks

* Prediction Methods
    * Use some variables to predict unknown or future values of other variables
* Description Methods
    * Find human-interpretable patterns that describe the data

#### Predictive: classification

* Find a model for class attribute as a function of the values of other attributes

#### Examples of a classification task

* Classifying credit card transactions as legitimate or fraudulent
* Classifying land covers (water bodies, urban areas, forests, etc.) using satellite data
* Categorizing news stories as finance, weather, entertainment, sports, etc.
* Identifying intruders in cyberspace
* Predicting tumor cells as benign or malignant

#### Classification: Fraud Detection

* Goal: predict fraudulent cases in credit card transactions
* Approach:
    * Use credit card transactions and the information on its account-holder as attributes
    * When does a customer buy, what does he buy, how often he pays on time ...
    * Label past transactions as fraudulent or fair transactions
    * Learn a model for the class of the transactions
    * Use this model to detect fraud by observing credit card transactions on an account

#### Classification: Sky Survey Cataloging

* Goal: to predict class of sky objects, especially visually faint ones
* Approach:
    * Segment the image
    * Measure image attributes
    * Model the class based on these futures
    * Succes story: found 16 new high red-shift quasars

#### Predictive: Regression Analysis

* Predict a value of a given continuous valued variable based on the values of other variables, assuming a linear or non-linear model of dependence
* Extensively studied in statistics, neural network fields
* Examples
    * Predicting sales amounts of new products based on advertising expenditure
    * Predicting wind velocities as a function of temperature, humidity, air pressure, etc.

#### Descriptive: Clustering

* Find groups of items that are similar among themselves but are different from the items in other groups

#### Clustering Applications

* Understanding
    * Grouping genes that have similar expression patterns
    * Grouping proteins with similar functionality
    * Custom profiling for target marketing
* Summarization
    * Reducing the size of large data sets


#### Clustering: Market Segmentation

* Goal: subdivide a market into distinct subsets of customers where any subset may conceivably be selected as a market target to be reached with a distinct marketing mix
* Approach:
    * Use customer information to segment the market
    * Use the segments to target the marketing mix

#### Descriptive and Predictive: Association Rules

* Given a set of records each containing a number of items from a collection
* Produce dependency rules predicting occurrence of an item based on occurrences of other items

#### Association Analysis: Applications

* Market basket analysis
    * Rules are used for sales promotion, shelf management and inventory management
* Telecommunication alarm diagnosis
    * Rules are used to find combination of alarms that frequently occur together
* Medical Informatics
    * Rules are used to find associations between diseases and symptoms

#### Descriptive: Deviation / Anomaly / Change Detection

* Find significant deviations from normal behavior
* Examples
    * Detecting credit card fraud
    * Detecting faults in a system
    * Detecting intruders in a computer network

### Attribute Types and Dataset Types

#### Data Definitions

* **Attribute**: a property or characteristic of an object
* **Data object**: a collection of attributes describe one
* **Attribute values**: the set of possible values for an attribute
* **Data**: a collection of data objects and their attributes

#### Types of Attributes

* **Nominal**: values from an unordered set
    * E.g. blood type, eye color
* **Ordinal**: values from an ordered set
    * E.g. grades, job titles
* **Interval**: values from an ordered set of equal-size intervals
    * E.g. temperature in Celsius
* **Ratio**: values from an ordered set of equal-size ratios

#### Properties of Attribute Values

* Mapped to attribute types
    * **Nominal** attribute: distinctness
    * **Ordinal** attribute: distinctness, order
    * **Interval** attribute: distinctness, order, meaningful differences
    * **Ratio** attribute: distinctness, order, meaningful differences and ratios

#### Discrete and Continuous Attributes

* **Discrete**: finite or countably infinite set of values
    * E.g. social security number, zip code, number of cars in a household
* **Continuous**: an interval of real numbers
    * E.g. temperature, height, weight

#### Types of Datasets

* Record
    * Data matrix
    * Document data
    * Transaction data
* Graph
    * World Wide Web
    * Molecular structure
* Ordered
    * Spatial data
    * Temporal data
    * Sequential data
    * Genetic sequence data
* Important characteristics: dimensionality, sparsity, size

#### Record Data

* Data that consists of a collection of records, each of which consists of a fixed set of attributes

#### Record: Data Matrix

* Same fixed set of numeric attributes
* Represented by an m x n matrix
    * m rows: objects
    * n columns: attributes

#### Record: Document Data

* Each document becomes a 'term' vector
    * Each term is a component of the vector
    * The value of the component is the frequency of the term in the document

#### Record: Transaction Data

* Each transaction is a record
* Each transaction consists of a set of items

#### Graph Data

* Data that consists of a collection of records, each of which consists of a collection of nodes and edges

#### Ordered Data

* Data that consists of a collection of records, each of which consists of an ordered set of attributes

### Data Similarity and Dissimilarity Measures

#### Similarity and Dissimilarity Measures

* Similarity measure
    * Numerical measure of how alike two data objects are
    * Higher value means more similar
* Dissimilarity measure
    * Numerical measure of how different two data objects are
    * Lower value means more similar

#### Euclidean Distance

* n is the number of dimensions
* Normalization is necessary, if scales differ

#### Normalization

* Data scaled to fall within a small, specified range
* E.g. [0, 1] or [-1, 1]

#### Min-Max Normalization: Outliers Problematic

* Min-Max Normalization
    * Downside: does not handle outliers well

#### Z-Score Normalization

* Avoids the problem of outliers
* (value - mean) / standard deviation
    * Below mean: negative
    * Above mean: positive

#### Minkowski Distance

* Generalization of Euclidean distance
![alt text](afbeeldingen/image.png)

#### Common Properties of a Distance

* d(x, y) ≥ 0 for all x and y and d(x, y) = 0 only if x = y (positive definiteness)
* d(x, y) = d(y, x) for all x and y (symmetry)
* d(x, z) ≤ d(x, y) + d(y, z) for all points x, y, and z (triangle inequality)

#### Common Properties of a Similarity

* s(x, y) = 1 if x = y 
* s(x, y) = s(y, x) for all x and y (symmetry)

#### Density

* Measures degree to which data objects are close to each other in a specified area
* Notion of density is closely related to that of proximity
* Concept of density is typically used for clustering and anomaly detection
* Examples
    * Eucledian density 
        * Number of points within a given radius
    * Graph-based density
        * Connectivity of a point to its neighbors

#### Euclidean Density: Grid-based

* Simplest approach is to divide region into a number of rectangular cells of equal volume and define density as # of points in the cell

#### Euclidean Density: Center-based

* Density of a point is the number of points within a given radius

### Data Preprocessing

#### Why Data Preprocessing?

* Data in the real world is *dirty*
    * Incomplete: lacking attribute values, lacking certain attributes of interest, or containing only aggregate data
    * Noisy: containing errors or outliers
    * Inconsistent: containing discrepancies in codes or names
* No quality data, no quality mining results
    * Quality decisions must be based on quality data
    * Example: a classification model for detecting people who are loan risks is built using poor data
        * Credit-worthy people may be denied loans
        * Non-credit-worthy people may be given loans

#### Major Tasks in Data Preprocessing

* Data cleaning
    * Fill in missing values, smooth noisy data, identify or remove outliers, and resolve inconsistencies
* Data integration
    * Integration of multiple databases, data cubes, or files
* Data transformation
    * Normalization and aggregation
* Data reduction
    * Reducing the volume but producing the same or similar analytical results

#### Data Cleaning / Cleansing / Scrubbing

* Dirty data examples
    * Presence of dummy values
    * Absence of fields
    * Contradictions in the data
    * Violation of business rules
    * Reused primary keys
* Data cleaning = process of detecting and correcting / removing corrupt or inaccurate records
    * Inconsistencies may be caused by user error, corruption in transmission / storage, etc.
    * Identifying incomplete, incorrect, inaccurate or irrelevant parts of data
    * Replacing, modifying, deleting this dirty data
    * Can be performed interactively with data wrangling tools
    * Can be performed through batch processing / scripting
* After cleansing a data set should be consistent
* Not only used to clean up the data in a DB but also to bring consistency to different sets of data that have been
merged from separate databases
* Differs from data validation where data is rejected from the system at time of entry, instead of afterwards

#### High Data Quality Criteria

* Accuracy
    * Correctness of the data
* Completeness
    * All required data is recorded
* Consistency
    * Data is consistent within the data set
* Uniformity
    * Data is in the same format
* Validity
    * Data conforms to the defined business rules

#### Data Quality

* Noise and outliers
* Missing values
* Duplicate data
* Wrong data

#### Data Cleaning Operations

* Removing typographical errors
* Properly labelling mislabelled data
* Validating / correcting values against a known list of entities
    * Strict validation = rejecting any entry that does not have valid fields
    * Fuzzy validation = correcting entries that are close to valid entries
* Cross-checking with a validated data set
* Data enhancement: data is made more complete by adding new data
* Harmonization: data is made consistent by converting it into a common format

#### Missing Values

* Reasons for missing values
    * Information is not collected
    * Attributes may not be applicable to all cases

#### Handling Missing Data

* Ignore the column / attribute
* Fill in the missing value manually
* Replace missing value with interpolated estimate
* Use a global constant to fill in the missing value
* Use the attribute mean or median to fill in the missing value
* Use the most probable value to fill in the missing value

## DATA NOISE

##### ̶ Data with an amount of meaningless information in it

```
̶ Data = true signal + noise
```
##### ̶ Increases the amount of storage space required

##### ̶ Can affect the results of data analysis

##### ̶ Examples

```
̶ Distortion of a person’s voice when talking on a poor phone
̶ Snow on television screen, artefacts on modern digital TV signals
```

## HANDLING NOISY DATA

```
̶ Binning method
̶ First sort data and partition into (equal-depth) bins
̶ Then smooth by bin means, smooth by bin median, smooth by bin boundaries, etc.
̶ Clustering
̶ Detect and remove outliers
̶ Combined computer and human inspection
̶ Detect suspicious values and check by human
̶ Regression
̶ Smooth by fitting the data into regression functions
```
```
73
Linear regression function versus quadratic regression function on noisy data
```

## OUTLIERS

### ̶ Outliers are data objects with characteristics

### that are considerably different than most

### other data objects in the data set

```
̶ Case 1: Outliers are noise that interferes with data
analysis
̶ Case 2: Outliers are the goal of our analysis
‒ Credit card fraud
‒ Intrusion detection
```

## SIMPLE DISCRETIZATION METHODS: BINNING

##### ̶ Equal-width (distance) partitioning

```
̶ Divides the range into N intervals of equal size: uniform grid
̶ if A and B are the lowest and highest values of the attribute, the width of intervals will
be: W = (B-A)/N.
̶ Most straightforward but outliers may dominate presentation
̶ Skewed data is not handled well
```
##### ̶ Example

```
̶ Data: 0, 4, 12, 16, 16, 18, 24, 26, 28
‒ Equal width binning
‒ Bin 1: 0,4 [-,10[
‒ Bin 2: 12, 16, 16, 18 [10, 20[
‒ Bin 3: 24, 26, 28 [20, +[
```

## SIMPLE DISCRETIZATION METHODS: BINNING

### ̶ Equal-depth (frequency) partitioning

```
̶ Divides the range into N intervals, each containing approximately same number of
samples
̶ Good data scaling
```
### ̶ Example

```
̶ Data: 0, 4, 12, 16, 16, 18, 24, 26, 28
‒ Equal frequency binning
‒ Bin 1: 0,4, 12 [-,14[
‒ Bin 2: 16, 16, 18 [14, 21[
‒ Bin 3: 24, 26, 28 [21, +[
```

## DATA SMOOTHING BY MEANS OF BINNING

```
̶ Sorted data for price: 4, 8, 9, 15, 21, 21, 24, 25, 26, 28, 29, 34
̶ Partition into (equal-depth) bins
̶ Bin 1: 4, 8, 9, 15
̶ Bin 2: 21, 21, 24, 25
̶ Bin 3: 26, 28, 29, 34
̶ Smoothing by bin means
̶ Bin 1: 9, 9, 9, 9
̶ Bin 2: 23, 23, 23, 23
̶ Bin 3: 29, 29, 29, 29
̶ Smoothing by bin boundaries
̶ Bin 1: 4, 4, 4, 15
̶ Bin 2: 21, 21, 25, 25
̶ Bin 3: 26, 26, 26, 34
```

## DATA CLEANSING EXAMPLE: PARSING

### ̶ Parsing locates and identifies individual data elements in the source

### files and isolates these data elements in the target files


## DATA CLEANSING EXAMPLE: CORRECTING

### ̶ Corrects parsed individual data components using algorithms and

### secondary data sources


## DATA CLEANSING EXAMPLE: TYPOS / INCONSISTENCIES

### ̶ “Composition” equals “composition”

### ̶ “Asphalt” equals “asphalt”

### ̶ “shake-single” should be “Shake Single”

### ̶ “asphalt, shake-single” should be “Shake Single”


## DATA CLEANSING EXAMPLE: STANDARDIZING

### ̶ Applies conversion routines to transform data into its preferred

### (consistent) format using both standard and custom business rules


## DATA CLEANSING EXAMPLE: MATCHING

### ̶ Searching and matching records within and across the parsed, corrected

### and standardized data based on predefined business rules to eliminate

### duplications


## DATA CLEANSING EXAMPLE: CONSOLIDATING

### ̶ Analyzing and identifying relationships between matched records and

### consolidating / merging them into one representation


## DATA INTEGRATION ISSUES

```
̶ Data integration: combine data from multiple sources
̶ Schema integration
̶ Integrate metadata from different sources
̶ Entity identification problem: identify real world entities from multiple data sources e.g. A.cust-id ≡ B.cust-#
̶ Detecting and resolving data value conflicts
̶ For the same real-world entity, attribute values from different sources are different
̶ Possible reasons: different representations, different scales, e.g. metric vs. British units
̶ Redundant data occurs often when integrating multiple DBs
̶ Same attribute may have different names in different DBs
̶ Careful integration of the data from multiple sources may help reduce/avoid redundancies and
inconsistencies and improve mining speed and quality
```

## DATA REDUCTION STEPS

### ̶ Sampling

### ̶ Dimensionality reduction

### ̶ Feature subset selection

### ̶ Feature creation

### ̶ Discretization


## DATA REDUCTION: SAMPLING

### ̶ Sampling is a technique employed for data reduction

̶ Often used for both preliminary investigation of data and final data analysis

### ̶ Sampling is typically used in data mining because processing the entire

### set of data of interest is too expensive or time consuming

### ̶ Key principle for effective sampling

```
̶ Using a sample will work almost as well as using the entire data set, if the sample
is representative
̶ A sample is representative if it has approximately the same properties (of
interest) as the original set of data
```

## DATA REDUCTION: SAMPLE SIZE

```
8000 points 2000 Points 500 Points
```

## DATA REDUCTION: TYPES OF SAMPLING

##### ̶ Simple Random Sampling

```
̶ Equal probability of selecting any particular item
̶ Sampling without replacement
‒ As each item is selected, it is removed from the population
̶ Sampling with replacement
‒ Objects are not removed from the population as they are selected for the sample
‒ Same object can be picked up more than once
```
##### ̶ Stratified sampling

```
̶ Split the data into several partitions
̶ Draw random samples from each partition
```

## DATA REDUCTION: DIMENSIONALITY REDUCTION

### ̶ Purpose

```
̶ Reduce amount of time and memory required by data mining algorithms
̶ Allow data to be more easily visualized
̶ May help to eliminate irrelevant features or reduce noise
```
### ̶ Techniques

```
̶ Principal Components Analysis (PCA)
̶ Singular Value Decomposition
̶ Others: supervised and non-linear techniques
```

## DATA REDUCTION: FEATURE SUBSET SELECTION

##### ̶ A way to reduce dimensionality of data

```
̶ Compared to dimensionality reduction: feature subset selection is simply selecting which
features to use, while dimensionality reduction techniques typically transform features
```
##### ̶ Redundant features

```
̶ Duplicate much or all of the information contained in one or more other attributes
̶ Example: purchase price of a product and the amount of sales tax paid
```
##### ̶ Irrelevant features

```
̶ Contain no information that is useful for the data mining task at hand
̶ Example: students' ID is often irrelevant to the task of predicting students’ grade points
```
##### ̶ Many different techniques developed


## DATA REDUCTION: FEATURE CREATION

### ̶ Create new attributes that can capture the important information in a

### data set much more efficiently than the original attributes

### ̶ Three general methods

```
̶ Feature extraction
‒ Example: extracting edges from images
̶ Feature construction
‒ Example: dividing mass by volume to get density
̶ Mapping data to new space
‒ Example: Fourier and wavelet analysis
```

## DATA REDUCTION: DISCRETIZATION

### ̶ Discretization is the process of converting a continuous attribute into an

### ordinal attribute

```
̶ A potentially infinite number of values are mapped into a small number of
categories
̶ Commonly used in classification
```

## IRIS SAMPLE DATA SET

### ̶ Iris Plant data set

```
̶ Three flower types (classes)
‒ Setosa
‒ Versicolour
‒ Virginica
̶ Four (non-class) attributes
‒ Sepal width and length
‒ Petal width and length
```
```
Virginica. Robert H.
Mohlenbrock. USDA NRCS. 1995.
Northeast wetland flora: Field
office guide to plant species.
Northeast National Technical
Center, Chester, PA. Courtesy of
USDA NRCS Wetland Science
Institute.
```

## DISCRETIZATION: IRIS EXAMPLE

```
Petal width low or petal length low → Setosa
Petal width medium or petal length medium → Versicolour
Petal width high or petal length high → Virginica
```

# SUMMARY


## SUMMARY

```
̶ Setting
̶ Enormous amounts of data being generated
̶ No longer possible to process this data in a non-distributed manner
̶ Data Mining
̶ Distilling knowledge from all this data
̶ Attribute types and dataset types
̶ Records, attributes, distances and densities
̶ Data pre-processing
̶ Data cleaning: parsing, correcting, standardizing, matching and consolidating
̶ Noise and outliers
̶ Data reduction: sampling, dimensionality reduction, feature selection, feature creation, discretization
```

## REFERENCES

### ̶ Introduction to Data Mining, 2nd edition, Pang-Ning Tan, Michael

### Steinbach, Anuj Karpatne, Vipin Kumar

### ̶ https://elitedatascience.com/data-cleaning
