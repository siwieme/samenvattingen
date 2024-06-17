# Introduction and goal

## Algorithm

* A set of instructions to solve a computional problem
* Receives a set of inputs
* Produces output
* We seek algorithms that are:
    * Efficient
    * Correct
    * Easy to implement
* Typical problems:
    * Sorting
    * Data storage
    * Searching
    * Path finding
    * ...
* Algorithms are not a finished product
    * Can be implemented in every programming language on every machine

## Data structure

* A data organization, management, and storage format
* Enables efficient access and modification
* Examples:
    * Arrays
    * ArrayList
    * LinkedList
    * trees
    * graphs
    * ...
* Depending on the structure
    * Very efficient operations
    * More time-consuming operations
* Used to keep data in memory
* Closely related to algorithms
    * Many algorithms are only efficient when a suitable data structure is used

### Containers vs dicitionaries

* Container
    * Stores a collection of information
* Dictionary
    * Supports dictionary operations
        * Find
        * Add
        * Remove
    * Uses a **key** to localize the **value**
* Some structures can be used as both (an array)

### Linked vs continuous

* Continuous
    * Stores all data in a continuous region in memory
    * Examples:
        * Array
        * HashTable
        * Heap
    * Advantage:
        * Memory locality: efficient use of caching
    * Disadvantage:
        * Size is typically fixed
            * If we want to expand:
                * Copy all the old data to the new reserved space
                * Space has to be twice the size of the old space
                * Space has to be one continuous region
                * If there is enough space left, but it's not a continuous region, it won't work
        
* Linked
    * Uses **pointers** to refer to different memory locations
    * Examples:
        * Binary Search Trees
        * Linked lists
    * Advantage:
        * No continuous block of memoery needed
        * We can keep expanding the structure as long as there is some memory left
        * Enables dynamic adjustions
    * Disadvantages
        * The use of pointers results in *overhead*
            * *Overhead* is when you use more memory than the fields you created

### Linear vs non-linear

* Linear
    * Can be visualised along one dimension
    * Examples:
        * Array
        * Linked List
* Non-linear
    * More complicated organization
        * Tree        

## Linear vs continuous

* Continuous vs linked
    * Based on memory layout
* Linear vs non-linear
    * Based on conceptual layout

* Continuous structure
    * Can be linear or non-linear
    * Vice versa

## Memory hierarchy and locality

* Memory access is very slow compared to the CPU speed
* Caches
    * Located between the main memory and the CPU
    * Compared to the main memory
        * Much faster
        * Much smaller
* When a program requests data from the memory
    * Loaded into the cache
    * Subsequent reads use this cached value
* Caching allow us to exploit locality
    * Temporal:
        * Recently used data
        * Higher chance of being needed again soon
    * Spatial:
        * Data "close" to the recently used data
        * Higher chance of being needed soon (looping over an array)

## Abstract Data Types

* Modern programming languages
* Good implementations of most common data structures
* Distinguish the implementation from its interface
* Understanding is needed to pick the best suitable