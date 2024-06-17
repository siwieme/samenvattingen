# Priority Queues

## Priority Queue

* Returns elements based on their priority
* Priority is a number (higher priority = smaller number)
* Supports:
    * Add
    * Remove and return element with highest priority
    * isEmpty()
    * Sometimes also peek() operations
* Trivial implementations:
    * Ordered array: 
        * Retrieving the element with the highest priority is O(1) 
        * Adding an element is O(n)
    * Unordered array: 
        * Retrieving is O(n)
        * Adding is O(1)

## Heap

* Compromise between ordered and unordered array
    * Efficiently stored in an array
    * Not completely (un)ordered
* Complete binary tree where all elements follow the heap property
* Complete binary tree: 
    * All levels are completely filled
    * Except maybe the last level
        * If not completely filled the nodes lie as much to the left as possible
* Heap property:
    * Max heap: 
        * The value of the parent is larger than (or equal to) the value of the children
    * Min heap:
        * The value of the parent is smaller than (or equal to) the value of the children

### Height of a heap

* At level *i*, there are at most $2^i$ nodes
* To store *n* elements we need a tree of height $O(lg(n))$

### Storing a heap

* We can store it in an array
* Node *i* is stored at index *i*
* The parent of *i* is stored at (*i*-1)/2
* The children of *i* are stored at 2*i*+1 and 2*i*+2

### Heap property

* Max heap: 
    * Element of the parent greater than or equal to elements of children
* Min heap: 
    * Element of the parent smaller than or equal to element of children
* There is no fixed order of the children
* Max heap: root contains the largest value
* Min heap: root contains the smallest value
* Every node can be seen as the root of a smaller heap
* The smallest element in a max heap:
    * Stored in a leaf node
    * But not in a fixed location

### Adding an element to a heap

* The element is inserted at index *n+1* (a leaf)
* We restore the heap property by moving the element up as long as it is larger (smaller) than its parent
* In the worst case we have to ascend all the way to the root: **O(lg(n))** comparisons

### Removing the root

* To maintain the structure we can only remove the last element
* We put the last element at the location of the root
* To restore the heap property we swap this element with its largest child as long as the element is not at the correct location
* Worst case: **O(lg n)** operations

### Building a heap

#### Adding elements

* Add all elements one by one to an initially empty heap
* Can be done inplace
* Requires *n-1* add operations, each add operation might require moving to the root of the current tree

#### Merging smaller heaps

* Given two small heaps and a (temporary) root element, we can merge these into a larger heap
* The new root might not be valid
    * We need to restore the heap property of this new heap by rotating the root of this subheap with its largest child
    * We do this level by level, bottom up
* A single element is already a valid heap so we start at the second
    last level (index n/2)

## Merging heaps
* Merge two priority queues
* Binary heap: O(n) merge

## Binomial queues

* Provide O(lg n) merge and O(1) add performance (on average)
* Binomial heap
* Binomial queue is a set of binomial trees
* A binomial tree $B_h$ is defined by its height *h*:
    * There is only a single binomial tree with this height
    * A single node is a binomial tree with height 0
    * $B_h$ consists of two $B_h$ $_-$ $_1$ trees where one is the leftmost child of the other
* Finding the minimum:
    * = find the minimum of the root elements
    * lg n trees: O(lg n) operations
* Adding: O(lg n) trees = O(lg n) operation
* Removing minimum: O(lg n) operation

## Merging heaps

* Binary heap: O(n) merge
* Specialized implementations can do it in O(lg n)
* A priority queue is a special type of queue that returns the elements based on their priority
* Most common implementation: (binary) heap
    * Compromise between sorted and unsorted array
    * A complete binary tree where all elements follow the heap property
    * Most operations are limited by the height of the heap: O(lg n)
    * Can be stored efficiently in an array
    * Can be constructed in O(n)
* Mergeable priority queues:
    * Binomial queues:
        * Set of binomial trees
        * O(lg n) merge, O(lg n) delete min
    * Pairing heap:
        * A general tree structure that follows the heap property
        * O(1) merge, O(lg n) delete min