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