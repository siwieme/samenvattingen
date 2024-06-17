# Binary Search Trees

## General

* Sort in an array?
    * Efficient to support operations on the order of the keys
    * Binary search is efficient to find keys
    * Not efficient to remove or add items: O(n)

* Binary Search Trees implement
    * Efficient dictionary operations (although not as efficient as a hash table)
    * Efficient operations dealing with the order of items

* Recursive definition
    * A BST contains two BSTs
* Given a BST, we can sort everything in O(n)
* No fixed structure

## Retrieving an element

* Just like binary search
* Compare the key with the key in the root node
* Continue the search in either the left or right subtree
* Repeat until the key is found or you end up in an empty subtree
* Efficiency: O(h) with *h* the height of the tree
* Easy to implement recursively

## Retrieving the minimum or maximum value

* The minimal value of a BST can be found in:
    * Left subtree
    * The root (if empty subtrees)
* To find the minimum, keep descending in left subtrees
* To find the maximum, keep descending in right subtrees
* Efficiency: O(h) with *h* the height of the tree

## Adding values

* Recursive procedure
* Compare with the root 
* Decide left or right

## Dealing with duplicate keys

* Option 1: Store items with the same key in the left or right subtree
    * Might end up with a long chain which increases the height of the tree
* Option 2: Store a linked list at each node with all the duplicates
    * Additional linked list pointers needed
* Option 3: Store duplicates in the left and right subtree alternately
    * Additional flag needed
* Option 4: Store duplicates in the left and right subtree randomly
    * Will balance the data well on average

## Deleting itmes

* Lazy deletion
    * Just flag the item as deleted
* Nodes without children can be immediately removed
* Node with one child
    * The child will become a child of the parent node
* Node with two childs:
    * Replace the node with its successor
    * Successor is smallest node of the right subtree
    * 2 options:
        * Copy data
        * Copy nodes
    * O(h)

## Height of the tree

* Worst case: h = O(n)
* Both retrieving and adding involves descending

## Average height of a tree

$f(n+1) < f(n) + 2/(n+1)$

* f(n) is O(lg n)
* D(n) is O(n lg n)

## Threaded trees

* Each node has allocated memory for 2 pointers: 2n pointers in total
* Only n-1 pointers needed -> 2n - (n-1) = n+1 pointers are not used
* Use them to point to the predecessor and successor of the node to make it easy to find them in O(1)
* Store an additional flag to distinguish normal pointers and successor/ predecessor pointers
* No need for pointers to the parent node any more (these were needed to find successor and predecessor nodes)
* Easy to implement in-order traversal without recursion
* Variants: left-threaded tree, right-threaded tree