# 2 - Exploratory Data Analysis (EDA)

Distributed Data Processing


## EXPLORATORY DATA ANALYSIS

* Critical first step in analysing data̶
* People are not very good at looking a columns of numbers / spreadsheets and
determining important characteristics of data
* EDA allows to
* Visualise distributions and relationships
* Detect mistakes
* Check assumptions
* EDA methods
* Ordering: Stem-and-leaf plots
* Grouping: frequency displays, distributions, histograms
* Summaries: summary statistics, standard deviation, box-and-whisker plots


## CLASSIFICATION OF EDA


* Graphical or non-graphical methods
* Non-graphical: calculation of summary statistics
* Graphical: summarize data in a diagrammatic or pictorial way
* Univariate or multivariate
* Univariate: investigate one variable (data column) at a time
* Multivariate: investigate two or more variables at a time to explore relationships
(typically bivariate)
* Almost always a good idea to perform univariate EDA on each of the
components of a multivariate EDA before performing this multivariate EDA


# UNIVARIATE NON-GRAPHICAL EDA


## CATEGORICAL DATA


* For categorical data the range of values and the frequency (or relative
frequency) of occurrence for each value are of interest
* Tabulation of the frequency is the best univariate non-graphical EDA for
categorical data
* Example: sample of 20 students enrolled in different courses
* Note: proportion and percent shouldn’t both be needed


## QUANTITATIVE DATA


* Univariate EDA for a quantitative variable is a way to make preliminary
assessments about the population distribution of the variable
* Noteworthy characteristics
* Central tendency
* Spread
* Modality (number of peaks)
* Shape (heaviness of the tails)
* Outliers


## FREQUENCY DISTRIBUTION TABLES


* Show the number of observations for each range of data
* Intervals can be chosen
* Example: age in years (10 observations)
* 25,26,29,32,35,36,38,44,49,


### CUMULATIVE FREQUENCY DISTRIBUTION TABLES

* Show the frequency, the relative frequency and cumulative frequency of
the observations

## CENTRAL TENDENCY

* From the age example the meanis
* Median* If there are an even number of observations take the average of the two middle values
* Median is considered a better measure of central tendency than mean for skewed distributions* From the age example: (35+36)/2 = 35.
* Mode* is more helpful for categorical data E.g. median income of US families is $43.318, while mean is $60.828 (US census Bureau 2004)̶
* Example for quantitative data: the most frequent age interval is 30Unimodal: single peak in distribution vs bimodal / multi-modal (two or more peaks)-39 and it has 4 observations
* Symmetric distributions: mode = mean = medianSkewed distributions: mode is on the other side of the median from the mean (see examples later on)


Most likely or frequently occurring value


## SPREAD: RANGE


* Spread is an indicator how far away from the center we are still likely to
find data values
* Range = max-min
* Difference between maximum and minimum values
* From age example
    * Max = 51, Min = 25
    * Range = 51-25 = 26
* Not a robust measure of spread: outliers heavily influence range


## SPREAD: SAMPLE VARIANCE


* Calculated for a list of numbers (n observations labelled x 1 to xn) based
on their deviation from the mean
* Sample variance = mean of the squares of the individual deviations


* The bigger the deviations from the mean, the bigger the variance
* Sample variance from age example = 82.
* Fairly robust measure of spread


## SPREAD: SAMPLE STANDARD DEVIATION


* Sample standard deviation = square root of the sample variance


* From the age data:
* Note: unit of sample variance is years² while the units of the sample standard
deviation are years
* Interpretation: sample standard deviation gives an idea of how much
observations differ from the mean

## SPREAD: QUARTILES

* Quartiles are the three values which divide the observed data into even fourths* One quarter of the data fall below the first quartile (Q 1 )
* One half fall below the second quartile (QThree fourths fall below the third quartile (Q 2 ) = median 3 )
* From the age data (25,26,29,32,35,36,38,44,49,51 with n = 10)
* Q(^1) = median of lower half of dataExample: third smallest value = 29
* Q (^2) * = medianExample: average of 5thand 6thobservations = (35+36) / 2 = 35.
* Q (^3) * = median of upper half of dataExample: third largest value = 44
* Remember to order your data!IQR= Interquartile range = Q
* Contains 50% of data^3 – Q^1
* If IQR is high the data is more spread outExtreme outliers have little or no effect on the IQR
* Robust measure of spread

## PERCENTILES

* The rth percentile, Pr
* Value that is greater than or equal to r percent of data samples
* Or less than or equal to (100 - r) percent of the data samples

## STEM-AND-LEAF PLOTS

* Substitute for histogram (see graphical EDA)
* Easier to make by hand
* Shows all data values and the shape of the distribution
* Example
* The age interval is the stem
* The observations are the leaves
* Age in years (10 observations)
* 25,26,29,32,35,36,38,44,49,

## STEM-AND-LEAF PLOTS

* Some statistical programs print output like below, where 2* means 20-29
* Others show it like below, where 3* means 30-34 and 3. means 35- 39

# UNIVARIATE GRAPHICAL EDA

## HISTOGRAMS

* Graphs are generally better to use in presentations than tables as they
allow rapid identification of a trend
* Histogram = barplot of frequency or relative frequency distribution

## BOXPLOTS A.K.A. BOX-AND-WHISKER PLOTS

* Box-and-whisker plots display
* Upper hinge = Q 3 = third quartile
* Lower hinge = Q 1 = first quartile
* Interquartile range ‒ Contains middle 50% of data(IQR) = Q 3 – Q 1
* Upper fence: upper hinge + 1.5*(IQR)
* Lower fence: lower hinge – 1.5*(IQR)
* Outliers: data values beyond the fences, typically individually plotted
* Lower and upper whisker ends are drawn to the smallest and
largest observations within the fences
* Boxplots provide robust measures of center and spread as
well as providing information about symmetry and outliers


## BOXPLOTS EXAMPLE


* Example
* Age in years (10 observations)
‒ 25,26,29,32,35,36,38,44,49,51
* IQR
* 44 - 29 = 15
* Upper fence
* 44 + 15*1.5 = 66.5
* Lower fence
* 29 – 15*1.5 = 6.5


# MULTI-VARIATE NON- GRAPHICAL

# EDA


## PAIRWISE EDA OVERVIEW


* 2 categorical variables
* Frequency table
* 1 categorical, 1 quantitative variable
* Stratified stem-and-leaf plots
* Side-by-side boxplots
* 2 quantitative variables
* Scatterplot


## 2 CATEGORICAL VARIABLES


* Frequency table


## 1 CATEGORICAL AND 1 QUANTITATIVE VARIABLE


* Stratified stem-and-leaf plots


## 2 QUANTITATIVE VARIABLES


* Basic statistics of interest
* Covariance
‒ Cov(X,X) = Var(X)
* Correlation
‒ Sx is standard deviation of x
‒ Sy is standard deviation of y
‒ Number that runs from -1 through 0 to +1 and indicates a
strong inverse relationship, no relationship and a strong
direct relationship respectively


## COVARIANCE / CORRELATION EXAMPLE


* For each subject we observe age and strength
* Mean age: 50
* Mean strength: 19
* Calculate deviation for age as age – 50
* Calculate deviation for strength as strength – 19
* Calculate product of deviations and add them up: - 1106
* N = 11, so covariance of x and y is -1106/10 = -110,6
* Covariance is negative ‒ indicating that as age goes up strength goes down (and vice versa)
* Sx= 18.96
* Sy= 6.39
* Correlation = ‒ Strong negative correlation-110.6 / ( 18.96 * 6.39 ) = -0.913


## COVARIANCE AND CORRELATION MATRIX


* When there are many quantitative variables the most common non-
graphical EDA is to calculate all the pairwise covariances and/or
correlations and assemble them in a matrix
* Covariance of X with X = variance X
* Correlation of X with X is 1


Covariance matrix Correlation matrix 28


# MULTI-VARIATE GRAPHICAL EDA


## 1 CATEGORICAL AND 1 QUANTITATIVE VARIABLE


* Side-by-side box plots
* Allows to compare the distribution of the continuous variable (age) across values
of the categorical variable (gender)


## 2 QUANTITATIVE VARIABLES


* Scatterplot
* Visually display the relationship between two continuous variables


## COMMON DISTRIBUTION SHAPES


* Symmetric distribution: mean and median coincide


## SYMMETRIC


* Right and left sides are mirror images
* Left tail looks like right tail
* Mean = Median = Mode


## SKEWNESS


* Positively skewed
* Longer tail in the high values
* Mean > Median > Mode


## SKEWNESS


* Negatively skewed
* Longer tail in the low values
* Mode > Median > Mean


# SUMMARY


## SUMMARY


* Exploratory Data Analysis
* Univariate non-graphical
‒ Frequency tables, central tendency, spread (range, quartiles, percentiles), stem-and-leaf
plots
* Univariate graphical
‒ Histograms, box-and-whisker plots
* Multivariate non-graphical
‒ Frequency table, stratified stem-and-leaf plots, covariance and correlation matrices
* Multivariate graphical
‒ Side-by-side box-and-whisker plots, scatterplot


## REFERENCES


* Exploratory Data Analysis, Sandy Eckel, Johns Hopkins University,
Baltimore USA
* Experimental Design and Analysis course, Howard J. Seltman, Carnegie
Mellon University
