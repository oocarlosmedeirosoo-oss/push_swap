*This project has been created as part of the 42 curriculum by mifranci, cbarbosa.*

## Description

The **push_swap** project focuses on sorting a list of integers using a restricted set of stack operations.  
The program must generate the smallest possible sequence of instructions to sort the data in ascending order.  
Two stacks are used:

* **Stack A**: initially contains the input values
* **Stack B**: initially empty

The challenge is not just to sort, but to do so efficiently under strict constraints. This project emphasizes algorithmic thinking, complexity analysis, and data structure manipulation using linked lists.

---

## Instructions

### Compilation

```bash
make
```

This will generate the executable:

```bash
./push_swap
```

---

### Usage

```bash
./push_swap [strategy] <list of integers>
```

Examples:

```bash
./push_swap 3 2 1
./push_swap --simple 5 4 3 2 1
./push_swap --medium 100 3 50 2 90
./push_swap --complex 4 67 3 87 23
./push_swap --adaptive 4 67 3 87 23
```

---

### Available Strategies

* `--simple` → O(n²)
* `--medium` → O(n√n)
* `--complex` → O(n log n)
* `--adaptive` → automatically selects strategy based on disorder (default)

---

### Output

The program prints a sequence of operations:

```text
sa
pb
ra
...
```

Each instruction corresponds to a valid stack operation.

---

## Technical Choices

### Data Structures

* Singly linked lists were used to represent stacks
* Each node contains:

  * `value` → original number
  * `index` → normalized rank (0 to n-1)

This allows efficient manipulation and simplifies advanced algorithms like radix sort.

---

### Indexing Strategy

Before sorting, all values are converted into normalized indices based on their sorted order.

Example:

```text
Values: 42, -3, 100, 7
Indices: 2, 0, 3, 1
```

This transformation simplifies comparisons and enables efficient bitwise sorting.

---

## Algorithms

### 1. Simple Algorithm (O(n²)) — Insertion Sort

This strategy repeatedly:

* Finds the smallest element in stack A
* Rotates it to the top
* Pushes it to stack B

After all elements are moved, they are pushed back to A in sorted order.

**Justification:**

* Easy to implement and understand
* Efficient for small inputs or nearly sorted data
* Matches the required O(n²) complexity

---

### 2. Medium Algorithm (O(n√n)) — Chunk-Based Sorting

The input is divided into chunks of size approximately √n.

Process:

* Push elements from A to B based on chunk ranges
* Organize elements in B
* Push them back to A in order

**Justification:**

* Reduces unnecessary rotations
* More efficient than simple extraction for medium-sized inputs
* Matches O(n√n) complexity requirement

---

### 3. Complex Algorithm (O(n log n)) — Radix Sort

This algorithm uses binary representation of indices.

Process:

* Iterate over each bit
* Push elements with bit = 0 to B
* Rotate elements with bit = 1
* Restore all elements to A

**Justification:**

* Deterministic and efficient
* Scales well for large inputs
* Meets O(n log n) requirement in operation model

---

### 4. Adaptive Algorithm

This strategy selects the most appropriate algorithm based on the **disorder metric**.

#### Disorder Definition

Disorder measures how far the stack is from being sorted:

```text
disorder = number of inverted pairs / total pairs
```

#### Strategy Selection

* disorder < 0.2 → Simple (O(n²))
* 0.2 ≤ disorder < 0.5 → Medium (O(n√n))
* disorder ≥ 0.5 → Complex (O(n log n))

**Justification:**

* Adapts to input characteristics
* Avoids unnecessary complexity
* Optimizes performance dynamically

---

## Error Handling

The program outputs:

```text
Error
```

In the following cases:

* Non-integer input
* Integer overflow
* Duplicate values
* Invalid format

---

## Resources

* https://en.wikipedia.org/wiki/Sorting_algorithm
* https://en.wikipedia.org/wiki/Radix_sort
* https://en.wikipedia.org/wiki/Insertion_sort
* https://en.wikipedia.org/wiki/Time_complexity
* 42 subject documentation
* AI for a better understanding of concepts

---

## AI Usage

We started developing the project on our own. However, we weren't very precise, as we lacked concepts such as Insertion, Chunk Sort, Radix Sort, Algorithmic Complexity, etc. Therefore, to develop this project, we used AI tools to:

* Clarify algorithmic concepts (radix, chunking, complexity)
* Review code structure and correctness
* Provide step-by-step explanations of pointer manipulation

All generated content was:

* Fully reviewed
* Understood before integration
* Tested manually and through debugging

No code was blindly copied; all implementations were adapted and validated.

---
