# Efficiency of algorithms

## Algorithm analysis

* Different algorithms/data structures can reach the same result
* Comparing them without implementing them
* Comparison indepent of:
    * Implementation
    * Programming language
    * Compiler
    * Machine
* Theoretical analysis of the required number of **primitive operations** as a function of the input size
    * In the best case
    * In the worst case
    * In the average case
* No exact number
* Indication of the **complexity** as function of the **input size**

## RAM model of computation

* Measure the performance on a simplified, hypothetical computer
* **R**andom **A**ccess **M**emory
    * Each simple operation (+, -, *, /, =, if ...) takes one time step
    * Loops are **NOT** simple operations, they **REPEAT** simple operations
    * Memory access takes one timestep

## Example: insertion sort

```java
void insertion_sort(int[] v) {
    for (int i=1; i < v.size(); i++) {
        int h = v[i];
        int j = i-1;
        while (j >= 0 && h < v[j]) {
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = h;
    }
}
```
* We'll go through the for-loop *n-1* times
* The while-loop depends:   
    * How sorted is the list already?

* Table

| Operation         | Time            | Best case   | Worst case            |
|-------------------|-----------------|-------------|-----------------------|
| int i=1           | $t_1$           | 1           | 1                     |
| i < v.size()      | $t_2$           | 2           | n                     |
| i++               | $t_3$           | 3           | n-1                   |
| int h = v[i]      | $t_4$           | n-1         | n-1                   |
| int j = i-1       | $t_5$           | n-1         | n-1                   |
| j >= 0            | $t_6$           | n-1         | (n-1)(n+2)/2          |
| && h < v[j]       | $t_7$           | n-1         | (n-1)n/2              |
| v[j+1] = v[j]     | $t_8$           | 0           | (n-1)n/2              |
| j--               | $t_9$           | 0           | (n-1)n/2              |
| v[j+1] = h        | $t_10$          | n-1         | n-1                   |


* Best case: $c_1n+c_0$ -> $O(n)$
* Worst case: $c_2n^2+c_1n+c_0$ -> $O(n^2)$
* Average case:
    * All permutations are equally likely
    * On average: we have to move half of the already processed numbers
    * Second order polynomial
* Not interested in the actual execution time (c-values)
    * Interested in the **scales** with increasing *n*
* Order of magnitude is determined by the largest order of the polynomial
    * Best case: insertion sort scales **linearly**
    * Worst and average case: insertion sort scales **quadratically**

## Growth of functions (Bachmann-Landau)

* A function $f(n)$ is $O(g(n))$ if $g(n)$ is an upper bound for $f(n)$ *(Oh)*
    * -> There exist constant values $c$ and $n_0$ for which $0 ≤ f(n) ≤ c*g(n)$ for every $n ≥ n_0$
* A function $f(n)$ is $Ω(g(n))$ if $g(n)$ is a lower bound for $f(n)$ *(Omega)*
    * -> There exist constant values $c$ and $n_0$ for which $0 ≤ c*g(n) ≤ f(n)$ for every $n ≥ n_0$
* A function $f(n)$ is $Ө(g(n))$ if $g(n)$ is both a lower and upper bound for $f(n)$ *(Theta)*
    * -> There exist constant values $c_1$ , $c_2$ and $n_0$ for which $0 ≤ c_1*g(n) ≤ f(n) ≤ c_2*g(n)$ for every $n ≥ n_0$

* Not concerned about small input sizes ($n < n_0$)
* Not concerned about constant factors
    * If one algorithm is ten times slower than the other
    * They both scale linearly
    * They are both $O(n)$
* Mostly interested in the upper bound $(O)$
* Common functions
    * Constant: $O(1)$ : constant time, regardless of the input size
    * Logarithmic: $O(log(n))$ : we typically use $O(lg n)$ to indicate the logarithm with base 2
    * Linear: $O(n)$
    * LogLinear: $O(n*log(n))$
    * Quadratic: $O(n^2)$
    * Exponential: $O(c^n)$
    * Factorial: $O(n!)$

## Some properties of the Big Oh

* $O(f(n)) + O(g(n)) = O(max(f(n), g(n)))$
* $O(c*f(n)) = O(f(n))$
* $f(n) = O(g(n))$ and $g(n) = O(h(n))$: $f(n) = O(h(n))$
* $f(n) = O(f(n))$

## Best, worst, average case

* O, Ω, Ө notations denote asymptotic bounds on functions
* The definitions are independent
    * We can formulate asymptotic bounds on runtime functions: 
        * Upper (𝑂) 
        * Lower (Ω)
        * Or both (Ө)
    * We can do either for worst-, best- or any other case
* Most interested in the O notation (upper bound)
* Lower bound (Ω) is often specified for a certain problem
    * Any algorithm that solves it, needs at least this amount of operations

## Hard problems: P vs NP
* P: set of problems that can be solved in polynomial time $O(n^k)$
* NP: problems we can verify a solution in polynomial time
* P = NP?
    * Not proven, scientists expect that P != NP

## Remarks

* Performance is not the only important factor
    * Execution time
    * Memory consumption
    * Correctness
    * Programmer time