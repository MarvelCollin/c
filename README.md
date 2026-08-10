<a name="readme-top"></a>

# Algorithms and Data Structures in C++

A growing collection of self-contained C++ programs covering classic algorithms, data structures, and small console projects. Every file compiles on its own, depends only on the standard library, and ships with a `main()` that runs a worked example.

Built as study material, kept public so it stays useful to anyone learning the same topics.

## Table of Contents

- [Getting Started](#getting-started)
- [Repository Structure](#repository-structure)
- [Catalog](#catalog)
  - [Sorting](#sorting)
  - [Searching](#searching)
  - [Graph](#graph)
  - [String](#string)
  - [Dynamic Programming](#dynamic-programming)
  - [Backtracking](#backtracking)
  - [Math](#math)
  - [Tree](#tree)
  - [Data Structure](#data-structure)
  - [Linked List](#linked-list)
  - [Console](#console)
  - [Basic](#basic)
  - [Game](#game)
- [Conventions](#conventions)
- [Usage](#usage)
- [License](#license)

## Getting Started

Each program is standalone. Compile the one you want and run it:

```bash
g++ Sorting/QuickSort.cpp -o quicksort && ./quicksort
```

Platform notes:

| Requirement | Files |
| --- | --- |
| `windows.h` / `conio.h` | `Basic/BasicValidation.cpp`, `Basic/EncryptPassword.cpp`, `Console/ClickableCMD.cpp`, `Game/PacMan.cpp`, `Game/Shooter.cpp`, `LinkedList/DictionaryCRUDLinkedList.cpp` |
| `pthread` / `unistd.h`, compile with `-pthread` | `Basic/Thread.cpp`, `Game/PacMan.cpp` |
| ANSI escape support in the terminal | `Console/ColorExample.cpp`, `Console/Style.cpp` |

Everything else is portable standard C++.

## Repository Structure

```
.
├── Backtracking/         maze solving, n queens, sudoku, permutations
├── Basic/                validation, file IO, threads, random
├── Console/              colors, mouse and keyboard input, rendering
├── DataStructure/        stacks, queues, heaps, hash table, cache
├── DynamicProgramming/   knapsack, subsequences, coin change
├── Game/                 console games
├── Graph/                traversal, shortest path, spanning tree, flow
├── LinkedList/           single, double, multiple, CRUD programs
├── Math/                 primes, gcd, exponentiation, base conversion
├── Searching/            linear and binary search
├── Sorting/              comparison and non comparison sorts
├── String/               pattern matching, edit distance, palindromes
└── Tree/                 BST, balanced trees, tries, range queries
```

## Catalog

Complexities describe the implementation in this repository, not the best known variant. Graph programs use an adjacency matrix unless noted, so their bounds are quoted in terms of `V` vertices.

### Sorting

| Program | Time | Space |
| --- | --- | --- |
| [BubbleSort](Sorting/BubbleSort.cpp) | O(n²) | O(1) |
| [SelectionSort](Sorting/SelectionSort.cpp) | O(n²) | O(1) |
| [InsertionSort](Sorting/InsertionSort.cpp) | O(n²) | O(1) |
| [ShellSort](Sorting/ShellSort.cpp) | O(n²) worst, sub-quadratic in practice | O(1) |
| [MergeSort](Sorting/MergeSort.cpp) | O(n log n) | O(n) |
| [QuickSort](Sorting/QuickSort.cpp) | O(n log n) average, O(n²) worst | O(log n) |
| [HeapSort](Sorting/HeapSort.cpp) | O(n log n) | O(1) |
| [CountingSort](Sorting/CountingSort.cpp) | O(n + k) | O(n + k) |
| [RadixSort](Sorting/RadixSort.cpp) | O(d · (n + k)) | O(n + k) |
| [BucketSort](Sorting/BucketSort.cpp) | O(n) average, O(n²) worst | O(n²) |

### Searching

| Program | Time | Space |
| --- | --- | --- |
| [LinearSearch](Searching/LinearSearch.cpp) | O(n) | O(1) |
| [BinarySearch](Searching/BinarySearch.cpp) | O(log n) | O(1) |

### Graph

| Program | Purpose | Time |
| --- | --- | --- |
| [BFS](Graph/BFS.cpp) | Breadth first traversal | O(V²) |
| [DFS](Graph/DFS.cpp) | Depth first traversal | O(V²) |
| [Dijkstra](Graph/Dijkstra.cpp) | Shortest path search across a character grid maze | O(V²) |
| [Astar](Graph/Astar.cpp) | Heuristic path search across a character grid maze | O(V²) |
| [BellmanFord](Graph/BellmanFord.cpp) | Single source shortest path with negative weights and cycle detection | O(V · E) |
| [FloydWarshall](Graph/FloydWarshall.cpp) | All pairs shortest path | O(V³) |
| [Kruskal](Graph/Kruskal.cpp) | Minimum spanning tree by edge sorting | O(E log E) |
| [PrimAlgorithm](Graph/PrimAlgorithm.cpp) | Minimum spanning tree by greedy expansion | O(V²) |
| [TopologicalSort](Graph/TopologicalSort.cpp) | Dependency ordering with Kahn's algorithm | O(V²) |
| [CycleDetection](Graph/CycleDetection.cpp) | Cycle check on a directed graph | O(V²) |
| [UnionFind](Graph/UnionFind.cpp) | Disjoint set with path compression and union by rank | near O(1) amortized |
| [TarjanSCC](Graph/TarjanSCC.cpp) | Strongly connected components | O(V²) |
| [ArticulationPoint](Graph/ArticulationPoint.cpp) | Cut vertices of an undirected graph | O(V²) |
| [FordFulkerson](Graph/FordFulkerson.cpp) | Maximum flow over BFS augmenting paths | O(V · E²) |

### String

| Program | Purpose | Time |
| --- | --- | --- |
| [KMP](String/KMP.cpp) | Pattern matching with a prefix table | O(n + m) |
| [RabinKarp](String/RabinKarp.cpp) | Pattern matching with a rolling hash | O(n + m) average, O(n · m) worst |
| [BoyerMoore](String/BoyerMoore.cpp) | Pattern matching with the bad character rule | O(n / m) best, O(n · m) worst |
| [LevenshteinDistance](String/LevenshteinDistance.cpp) | Edit distance between two words | O(n · m) |
| [Manacher](String/Manacher.cpp) | Longest palindromic substring | O(n) |

### Dynamic Programming

| Program | Purpose | Time |
| --- | --- | --- |
| [Fibonacci](DynamicProgramming/Fibonacci.cpp) | Memoization and tabulation side by side | O(n) |
| [Knapsack](DynamicProgramming/Knapsack.cpp) | 0/1 knapsack maximum value | O(n · W) |
| [LongestCommonSubsequence](DynamicProgramming/LongestCommonSubsequence.cpp) | LCS length and reconstruction | O(n · m) |
| [LongestIncreasingSubsequence](DynamicProgramming/LongestIncreasingSubsequence.cpp) | LIS length | O(n²) |
| [CoinChange](DynamicProgramming/CoinChange.cpp) | Fewest coins for a target amount | O(n · target) |
| [MatrixChainMultiplication](DynamicProgramming/MatrixChainMultiplication.cpp) | Cheapest multiplication order | O(n³) |

### Backtracking

| Program | Purpose | Time |
| --- | --- | --- |
| [NQueens](Backtracking/NQueens.cpp) | Place 8 queens with no conflicts | O(n!) worst |
| [SudokuSolver](Backtracking/SudokuSolver.cpp) | Fill a 9x9 grid | O(9^m) worst, m empty cells |
| [RatInMaze](Backtracking/RatInMaze.cpp) | Find a path through a blocked grid | O(4^(n²)) worst |
| [KnightsTour](Backtracking/KnightsTour.cpp) | Visit every square of a 6x6 board once | O(8^(n²)) worst |
| [Permutation](Backtracking/Permutation.cpp) | Generate every permutation of a string | O(n · n!) |
| [HuntAndKill](Backtracking/HuntAndKill.cpp) | Randomized maze generation | O(n · m) expected |

### Math

| Program | Purpose | Time |
| --- | --- | --- |
| [GCD](Math/GCD.cpp) | Euclidean GCD and LCM | O(log min(a, b)) |
| [SieveOfEratosthenes](Math/SieveOfEratosthenes.cpp) | Every prime up to a limit | O(n log log n) |
| [FastPower](Math/FastPower.cpp) | Binary exponentiation, plain and modular | O(log e) |
| [PrimeFactorization](Math/PrimeFactorization.cpp) | Trial division factorization | O(√n) |
| [BaseConversion](Math/BaseConversion.cpp) | Decimal to any base and back | O(log n) |
| [Collatz](Math/Collatz.cpp) | Collatz sequence and step count | unproven, the conjecture is open |

### Tree

| Program | Purpose | Time |
| --- | --- | --- |
| [BinarySearchTree](Tree/BinarySearchTree.cpp) | Unbalanced BST insert, search, traversal | O(h) |
| [AVL](Tree/AVL.cpp) | Height balanced tree with rotations | O(log n) |
| [RedBlackTree](Tree/RedBlackTree.cpp) | Color balanced tree, insert with fixup | O(log n) |
| [BTree](Tree/BTree.cpp) | Multi-way tree of degree 3, insert and search | O(log n) |
| [TrieAlgorithm](Tree/TrieAlgorithm.cpp) | Prefix tree over words | O(L) per word |
| [SegmentTree](Tree/SegmentTree.cpp) | Range sum with point update | O(log n) per query, O(n) build |
| [FenwickTree](Tree/FenwickTree.cpp) | Binary indexed tree, prefix and range sums | O(log n) per operation |

### Data Structure

| Program | Purpose | Time |
| --- | --- | --- |
| [Stack](DataStructure/Stack.cpp) | LIFO on a linked list | O(1) push, pop, peek |
| [Deque](DataStructure/Deque.cpp) | Double ended queue on a doubly linked list | O(1) per end operation |
| [CircularQueue](DataStructure/CircularQueue.cpp) | Fixed size ring buffer | O(1) enqueue, dequeue |
| [MaxHeap](DataStructure/MaxHeap.cpp) | Binary max heap | O(log n) insert, extract |
| [MinHeap](DataStructure/MinHeap.cpp) | Binary min heap | O(log n) insert, extract |
| [CustomPriorityQueue](DataStructure/CustomPriorityQueue.cpp) | Patient triage queue on a sorted linked list | O(n) insert, O(1) pop |
| [Hashtable](DataStructure/Hashtable.cpp) | Separate chaining with linked lists | O(1) average |
| [LRUCache](DataStructure/LRUCache.cpp) | Doubly linked list plus lookup table | O(1) get, put |

### Linked List

| Program | Purpose |
| --- | --- |
| [SingleLinkedList](LinkedList/SingleLinkedList.cpp) | Single linked list operations |
| [DoubleLinkedlist](LinkedList/DoubleLinkedlist.cpp) | Double linked list operations |
| [DoubleLinkedListProgram](LinkedList/DoubleLinkedListProgram.cpp) | Menu driven double linked list program |
| [MultipleLinkedList](LinkedList/MultipleLinkedList.cpp) | List of lists with parent and child nodes |
| [DictionaryCRUDLinkedList](LinkedList/DictionaryCRUDLinkedList.cpp) | Dictionary CRUD backed by a linked list |

### Console

| Program | Purpose |
| --- | --- |
| [Style](Console/Style.cpp) | ANSI color and style macros |
| [ColorExample](Console/ColorExample.cpp) | Minimal colored output example |
| [ClickableCMD](Console/ClickableCMD.cpp) | Mouse input in the Windows console |
| [ReadKeyboard](Console/ReadKeyboard.cpp) | Raw key reading |
| [DynamicMap](Console/DynamicMap.cpp) | Render a character map of variable size |

### Basic

| Program | Purpose |
| --- | --- |
| [BasicValidation](Basic/BasicValidation.cpp) | Menu flow, input validation, email format check |
| [EncryptPassword](Basic/EncryptPassword.cpp) | Masked password input |
| [FileProgram](Basic/FileProgram.cpp) | File read and write |
| [Random](Basic/Random.cpp) | Seeded random number generation |
| [Thread](Basic/Thread.cpp) | Two pthreads running on separate intervals |

### Game

| Program | Purpose |
| --- | --- |
| [PacMan](Game/PacMan.cpp) | Console Pac-Man |
| [Shooter](Game/Shooter.cpp) | Console shooter |

## Conventions

- One topic per file, one `main()` per file, no cross-file includes.
- C style C++: `stdio.h` over iostream, `malloc` over `new`, plain structs and arrays.
- Demo input is hardcoded, so every program runs with no arguments.
- Older files carry Indonesian comments explaining each step. Newer files are comment free by request.

## Usage

Feel free to copy-paste my code :>

## License

Released under the [MIT License](LICENSE).

<p align="right"><a href="#readme-top">back to top</a></p>
