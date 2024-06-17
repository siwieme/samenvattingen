# Containers

## Container vs dictionary

* Container
    * Stores a collection of information
* Dictionary
    * Supports dictionary operations
        * Find
        * Add
        * Remove
    * Uses a **key** to localize the **value**
* Some structures can be used as both (an array)

## Array

* Stores data by explicitly assigning a slot to place the data in
* Continuous area in the computer memory
* All elements are efficiently addressable: O(1)
* Fixed size
    * Defined before use

## Dynamic Array

* Array that keeps track of its size
* Automatically increases in size when full
* Implementations
    * Java: ArrayList
    * Python: list
    * C++: Vector
* Adding an element:
    * Available slots: O(1)
    * No available slots?
        * Create a new array
        * Copy all the data
        * Add the new item
        * O(n)
* Efficiency?
    * Every time the array is full, we double the size
    * Amortized efficiency: looking at a sequence of add operations

## Amortized analysis

* Consider worst-case cost of a sequence of operations, rather than worst-case individual cost
* Every expensive operation (doubling) guarantees that the next operations will be efficient
* Calculate an "average" cost by spreading the cost of the rare, expensive operations over the less expensive ones
* Different methods:
    * Aggregate method
    * Bankers method
    * Potential method

### Aggregate method

* Idea  
    * Calculate the total cost of a sequence
    * *m* operations
    * Divide by *m*

* What is the total cost of adding *n* items
    * *n* insertions cost O(n), a single insertion has an amortized efficiency of O(1)

### Bankers method

* Idea
    * Let the efficient operations pay some additional cost (credit)
    * Can be used later to pay for the costly operation

* Adding an element
    * Cost of 1
    * Unless the array is full: cost of *n*
* Letting each element pay part of the cost of the next doubling operation
* n/2 elements have to pay *n* in total for the doubling
    * Each element has to pay an additional 2
* Each addition operation costs 2+1=3: O(1) amortized efficiency

## Dynamic Array

* Most implementations have a (quite) large initial size
* Growth factor depends on implementation
* If you know beforehand how many items you will store, you can avoid most copies

## Linked List

* Chain of nodes
* Each node
    * Some data
    * Pointer to the next node (and/or previous)
* Recursive
    * Head + smaller list
* Retrieving the first element: O(1)
* Retrieving other elements: O(n)
* Easy to insert or delete nodes: O(1) (after they're located)
* Overhead for the pointer in each node
* Not continuous

## Stack

* LIFO (Last In, First Out)
* Supports:
    * Push (add to the top)
    * Pop (remove from the top of the stack)
    * Check if empty
* Might support:
    * Peek
    * Duplicate top element
    * Swap
* Easy to implement with an array or linked list
* Push and pop are O(1)

## Queue

* FIFO (First In, First Out)
* Supports:
    * Add (enqueue)
    * Remove (dequeue)
    * Check if empty
* Easy to implement with an array or linked list
* Array implementation needs two pointers
* Indexing is $d \% n$ (circular array)
* Add and remove are O(1)

## Deque

* Double ended queue
* Can be used as stack and queue
* Add/remove supported on **BOTH** sides
* Easy to implement with an array or linked list
* Add and remove are O(1)

## Tree

* Collection of nodes that store the data
* Connected with edges
* No loops (cycles)
* Every node can be reached from every other node
* Recursively defined
    * Every node is the root of a subtree
* Collection of trees = forest
* Degree of a node = number of children
* Ordered tree = order of the children matters
* Multiway tree
    * Children have fixed index
    * Certain children might be missing

### Storing a tree

* Arbitrary dynamic trees have to be implemented with pointers
* Depending on the application, we might need pointers
    * To the children
    * To the parent
    * Both
* Missing children for leaf nodes:
    * Null pointer: wastes space
    * Threaded tree: use these pointers to quickly find the *in-order predecessor* or *in-order successor*
* Binary tree
    * Just store two pointers
* Multiway trees:
    * Array of pointers to point to the children
* Wastes space if the average number of children is low
    * Alternative: linked list
* Every node is an element in a linked list
    * Pointer to the next element
    * Pointer to the children list

### Tree traversal

* Iterate (walk) over the data in the tree in a certain order
* Multiple possible orderings:
    * Depth-first (all the way down)
    * Breadth-first (every node on a level first)
    * Best first (priority)

#### Depth-first Search

* Each subtree has a root and multiple subtrees
* Explore the search as far as possible from the root node
* When do we process the root of the subtree?
    * Pre-order: root - left - right
        * Polish notation
    * In-order: left - root - right
    * Reverse in-order: right - root - left
    * Post-order: left - right - root
        * Reverse polish notation
        * Used on a stack machine
* Implement in a recursive way
    * Alternative: stack

#### Breadth-first search

* Process each level from left to right before moving on to the next
* Does not use the recursive definition of the tree
* Use a queue:
    * Add the children to the back of the queue
    * Process the items in the front of the queue

## Recursion

* Divide the problem in subproblems
* Function that calls itself
* Watch out for infinite loop

### ... in data structures

* Linked list:
    * Head element + smaller linked list
* Tree:
    * Root + sub trees

### Advantages

* Recursive solutions are elegant and easy to implement

### Disadvantages

* Typically slower than an implementation using loops
* Uses more memory
* Will not work for very large problems
* Difficult to debug

## Graph

* Collection of *n* nodes (=vertices) connected with *m* edges
* Nodes are numbered, edges are defined by the two end nodes
* Multi-graph: more than one edge between two nodes possible
* Edges can be directed or undirected
* We can distinguish the indegree and outdegree
* Edges might have weights

### Storing a graph

* Adjacency matrix:
    * N x N matrix
    * Each element indicates the weight or presence of a connection between two nodes
    * Efficient to retrieve the weight of an edge and to retrieve all neighbors of a node
    * Not efficient to store
* Adjacency lists:
    * Matrix representation is not efficient for sparse graphs
    * Store for each node a list with identification of the neighbor