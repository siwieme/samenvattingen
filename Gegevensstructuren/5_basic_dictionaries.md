# Basic dictionaries

## Container (previous chapters) vs dictionary (this chapter)

* A container simply stores a collection of information without regard for the value of the key
* A dictionary supports dictionary operations that use the key to localize the data
    * Add
    * Find
    * Remove
* Some data structures can be used as both

## Dictionaries

* Often called:
    * "lookup table"
    * "associative array"
* Maps a key to a value

## Directly addressable array

* When we can easily convert keys to indices, it is not needed to store the keys
* Example: frequency table
* O(1) performance for all dictionary operations
* In case of duplicate keys, we can store a linked list instead of a single value

## Unordered array

* Search
    * Linear search
        * O(n) worst and average case
* Add
    * O(1)
* Remove
    * Finding the element is O(n)
    * Moving all sequential elements one place would be O(n)
    * Order does not matter: delete value and replace it with the last value: O(1)
* Optimization
    * Put frequently accessed elements in front
    * Keep track of the frequency and sort elements periodically
    * Swap an element with its predecessor every time it is accessed

## Ordered array

* Search
    * Binary search
        * Compare query with middle element
        * Smaller? Check left part of the array
        * Larger? Check right part of the array
        * Repeat
        * At each step, we reduce the problem's size by half
        * O(lg n)
* Add
    * Find the location
    * Move all sequential elements
    * O(n)
* Remove
    * Finding the element is O(lg n)
    * Moving all sequential elements one place is O(n)

## Linked List

* Unordered linked list
    * Search is O(n)
    * Add and remove is O(1)
* Ordered by search frequency
    * Put each accessed element in front or switch it with its predecessor
    * Putting elements in front was not efficient with an array implementation
* Ordered list
    * Not possible to do binary search
        * Only sequential access
        * O(n)
    * Add
        * Search for the location to insert
        * O(n)
    * Remove:
        * Also involves searching
        * O(n)