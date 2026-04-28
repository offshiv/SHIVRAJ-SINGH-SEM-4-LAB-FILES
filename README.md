# 🧠 ADA Lab Programs

This repository contains all my **Analysis and Design of Algorithms (ADA)** lab programs.

| | |
|---|---|
| **Name** | Shivraj Singh |
| **Branch** | CSE |
| **Roll No.** | UE243098 |
| **Semester** | 4th |

---

## 🎯 Aim

To implement and understand various algorithms as part of the ADA lab curriculum.

---

## 📋 Index

| S.No. | Lab | Topics | Date |
|-------|-----|--------|------|
| 1 | [Lab 1](#-lab-1) | Tower of Hanoi, Bouncing Ball Simulation, Binary Exponentiation, String Permutation, Linear Search, Horner's Rule, Bubble Sort, Selection Sort, Missing Number Finder, First Duplicate Finder | 28/01/26 |
| 2 | [Lab 2](#-lab-2) | Insertion Sort, Binary Search | 04/02/26 |
| 3 | [Lab 3](#-lab-3) | Quick Sort, Merge Sort | 11/02/26 |
| 4 | [Lab 4](#-lab-4) | Quick Sort (Iterative), Binary Search 1/3, Permutation Generator | 18/02/26 |
| 5 | [Lab 5](#-lab-5) | Fractional Knapsack, Convex Hull, Kth Smallest, Maxmin | 25/02/26 |
| 6 | [Lab 6](#-lab-6) | Dijkstra, Prim's, Activity Selection, Cycle Detection, Kruskal | 10/03/26 |
| 7 | [Lab 7](#-lab-7) | Multistage Graph: Forward & Backward | 17/03/26 |
| 8 | [Lab 8](#-lab-8) | Matrix Chain Multiplication | 08/04/26 |
| 9 | [Lab 9](#-lab-9) | Floyd Warshall, Longest Common Subsequence, Traveling Salesperson, 0/1 Knapsack | 22/04/26 |
| 10 | [Lab 10](#-lab-10) | N-Queens, Subset Sum, Chromatic Number, Hamiltonian Graph | 28/04/26 |

---

## 🔬 Lab 1

> **Date:** 28/01/26 | **Page:** 1

### 1. Tower of Hanoi

**Aim:** To solve the Tower of Hanoi problem using recursion.

**Algorithm:**
1. If n = 1, move the disk directly from source to destination.
2. Move n-1 disks from source to auxiliary peg (recursively).
3. Move the nth (largest) disk from source to destination.
4. Move n-1 disks from auxiliary to destination peg (recursively).

**Time Complexity:** `O(2ⁿ)` — Each call spawns 2 more calls, making this exponential.  
**Space Complexity:** `O(n)` — Recursive call stack depth.

---
```#include<iostream>
#include<iostream>
using namespace std;

void hanoi(int n, char src, char dest, char aux){
    if(n==1){
        cout<<"Move disk 1 from "<<src<<" to "<<dest<<endl;
        return;
    }
    hanoi(n-1, src, aux, dest);
    cout<<"Move disk "<<n<<" from "<<src<<" to "<<dest<<endl;
    hanoi(n-1, aux, dest, src);
}

int main(){
    int n;
    cout<<"Enter number of disks: ";
    cin>>n;
    hanoi(n, 'A', 'C', 'B');
    return 0;
}
```

### 2. Bouncing Ball Simulation

**Aim:** To simulate a bouncing ball and compute the total distance travelled.

**Algorithm:**
1. Accept initial height `h` and rebound factor `r` (0 < r < 1).
2. For each bounce, compute: up distance = `h * r`, then set `h = h * r`.
3. Sum all distances: first drop + (2 × every subsequent bounce height) until `h` is negligible.
4. Return total distance.

**Time Complexity:** `O(n)` where n is the number of bounces simulated.  
**Space Complexity:** `O(1)`

---
```#include<iostream>
using namespace std;

int main(){
    float h, r;
    cout<<"Enter height and rebound factor: ";
    cin>>h>>r;
    float total = h;
    while(h*r > 0.01){
        h = h*r;
        total += 2*h;
    }
    cout<<"Total distance = "<<total<<endl;
    return 0;
}
```

### 3. Binary Exponentiation

**Aim:** To compute `aⁿ` efficiently using fast exponentiation (divide and conquer).

**Algorithm:**
1. If n = 0, return 1.
2. If n is even, return `power(a, n/2) * power(a, n/2)`.
3. If n is odd, return `a * power(a, n-1)`.
4. (Optimised): compute half = `power(a, n/2)` once; if n even return `half*half`, else `a*half*half`.

**Time Complexity:** `O(log n)` — Number of recursive calls halved each step.  
**Space Complexity:** `O(log n)` — Recursion depth.

---
```#include<iostream>
using namespace std;

long long power(long long a, long long n){
    if(n==0) return 1;
    long long half = power(a, n/2);
    if(n%2==0) return half*half;
    return a*half*half;
}

int main(){
    long long a, n;
    cout<<"Enter base and exponent: ";
    cin>>a>>n;
    cout<<a<<"^"<<n<<" = "<<power(a,n)<<endl;
    return 0;
}
```

### 4. String Permutation

**Aim:** To generate all permutations of a given string using backtracking.

**Algorithm:**
1. Fix one character at index `i` (swap with current position).
2. Recursively generate permutations for the remaining substring.
3. Backtrack (swap back) to restore the original string.
4. Repeat until all characters are fixed (base case: i = n-1).

**Time Complexity:** `O(n × n!)` — n! permutations, each of length n to print.  
**Space Complexity:** `O(n)` — Recursion depth.

---
```#include<iostream>
#include<string>
using namespace std;

void permute(string s, int l, int r){
    if(l==r){
        cout<<s<<endl;
        return;
    }
    for(int i=l; i<=r; i++){
        swap(s[l], s[i]);
        permute(s, l+1, r);
        swap(s[l], s[i]);
    }
}

int main(){
    string s;
    cout<<"Enter string: ";
    cin>>s;
    permute(s, 0, s.length()-1);
    return 0;
}
```

### 5. Linear Search

**Aim:** To search for a target element in an unsorted array.

**Algorithm:**
1. Start from the first element (index 0).
2. Compare each element with the target key.
3. If found, return the index.
4. If the end of array is reached without a match, return -1.

**Time Complexity:** `O(n)` worst/average case; `O(1)` best case.  
**Space Complexity:** `O(1)`

---
```#include<iostream>
using namespace std;

int main(){
    int n, key;
    cout<<"Enter size: ";
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    cout<<"Enter key: ";
    cin>>key;
    int pos = -1;
    for(int i=0; i<n; i++){
        if(arr[i]==key){ pos=i; break; }
    }
    if(pos==-1) cout<<"Not found"<<endl;
    else cout<<"Found at index "<<pos<<endl;
    return 0;
}
```

### 6. Horner's Rule

**Aim:** To evaluate a polynomial efficiently using Horner's method.

**Algorithm:**
1. Given polynomial `aₙxⁿ + aₙ₋₁xⁿ⁻¹ + … + a₀`, rewrite as `(…((aₙ)x + aₙ₋₁)x + …)x + a₀`.
2. Start with result = `aₙ`.
3. For i from n-1 down to 0: `result = result * x + aᵢ`.
4. Return result.

**Time Complexity:** `O(n)` — Single pass through all coefficients.  
**Space Complexity:** `O(1)`

---
```#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter degree: ";
    cin>>n;
    float coef[n+1], x;
    cout<<"Enter coefficients (highest to lowest): ";
    for(int i=0; i<=n; i++) cin>>coef[i];
    cout<<"Enter x: ";
    cin>>x;
    float result = coef[0];
    for(int i=1; i<=n; i++)
        result = result*x + coef[i];
    cout<<"Result = "<<result<<endl;
    return 0;
}
```

### 7. Bubble Sort

**Aim:** To sort an array by repeatedly swapping adjacent out-of-order elements.

**Algorithm:**
1. For i = 0 to n-1 (outer pass):
2. For j = 0 to n-i-2 (inner pass):
3. If `arr[j] > arr[j+1]`, swap them.
4. After each outer pass, the largest unsorted element bubbles to its correct position.

**Time Complexity:** `O(n²)` worst/average; `O(n)` best case (already sorted, with flag).  
**Space Complexity:** `O(1)` — In-place.

---
```#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter size: ";
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j]>arr[j+1])
                swap(arr[j], arr[j+1]);
        }
    }
    cout<<"Sorted: ";
    for(int i=0; i<n; i++) cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}
```

### 8. Selection Sort

**Aim:** To sort an array by repeatedly selecting the minimum element.

**Algorithm:**
1. For i = 0 to n-1:
2. Find the minimum element in the subarray `arr[i…n-1]`.
3. Swap it with `arr[i]`.
4. Repeat until the array is sorted.

**Time Complexity:** `O(n²)` — Always (even if sorted).  
**Space Complexity:** `O(1)` — In-place.

---
```
#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter size: ";
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    for(int i=0; i<n-1; i++){
        int minIdx = i;
        for(int j=i+1; j<n; j++)
            if(arr[j]<arr[minIdx]) minIdx=j;
        swap(arr[i], arr[minIdx]);
    }
    cout<<"Sorted: ";
    for(int i=0; i<n; i++) cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}
```

### 9. Missing Number Finder

**Aim:** To find the missing number in an array of integers from 1 to n.

**Algorithm:**
1. Compute expected sum = `n*(n+1)/2`.
2. Compute actual sum of all elements in the array.
3. Missing number = expected sum − actual sum.

**Time Complexity:** `O(n)` — Single pass to compute sum.  
**Space Complexity:** `O(1)`

---
```#include<iostream>
using namespace std;

int main(){
    int n;
    cout<<"Enter n: ";
    cin>>n;
    int arr[n-1];
    for(int i=0; i<n-1; i++) cin>>arr[i];
    int expected = n*(n+1)/2;
    int actual = 0;
    for(int i=0; i<n-1; i++) actual+=arr[i];
    cout<<"Missing number: "<<expected-actual<<endl;
    return 0;
}
```

### 10. First Duplicate Finder

**Aim:** To find the first duplicate element in an array.

**Algorithm:**
1. Use a hash set to track visited elements.
2. For each element in the array:
   - If it already exists in the set, return it (first duplicate).
   - Otherwise, add it to the set.
3. If no duplicate found, return -1.

**Time Complexity:** `O(n)` average case.  
**Space Complexity:** `O(n)` — Hash set storage.

---
```#include<iostream>
#include<unordered_set>
using namespace std;

int main(){
    int n;
    cout<<"Enter size: ";
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];
    unordered_set<int> seen;
    for(int i=0; i<n; i++){
        if(seen.count(arr[i])){
            cout<<"First duplicate: "<<arr[i]<<endl;
            return 0;
        }
        seen.insert(arr[i]);
    }
    cout<<"No duplicate found"<<endl;
    return 0;
}
```

## 🔬 Lab 2

> **Date:** 04/02/26 | **Page:** 20

### 1. Insertion Sort

**Aim:** To sort an array by inserting each element into its correct position.

**Algorithm:**
1. Start from index 1 (first element is trivially sorted).
2. Pick element `key = arr[i]`.
3. Shift all elements greater than `key` one position to the right.
4. Place `key` in its correct position.
5. Repeat for all elements.

**Time Complexity:** `O(n²)` worst/average; `O(n)` best case (already sorted).  
**Space Complexity:** `O(1)` — In-place.

---

### 2. Binary Search

**Aim:** To search for a target element in a **sorted** array using divide and conquer.

**Algorithm:**
1. Set `low = 0`, `high = n-1`.
2. While `low <= high`:
   - Compute `mid = (low + high) / 2`.
   - If `arr[mid] == key`, return `mid`.
   - If `arr[mid] < key`, set `low = mid + 1` (search right half).
   - Else set `high = mid - 1` (search left half).
3. If not found, return -1.

**Time Complexity:** `O(log n)` — Search space halved each iteration.  
**Space Complexity:** `O(1)` iterative; `O(log n)` recursive.

---

## 🔬 Lab 3

> **Date:** 11/02/26 | **Page:** 27

### 1. Quick Sort

**Aim:** To sort an array using the divide-and-conquer Quick Sort algorithm.

**Algorithm:**
1. Choose a pivot element (e.g., last element).
2. Partition the array: place elements smaller than pivot to the left, larger to the right.
3. Recursively apply Quick Sort to the left and right sub-arrays.
4. Base case: array of size 0 or 1 is already sorted.

**Time Complexity:** `O(n log n)` average; `O(n²)` worst case (sorted input with bad pivot).  
**Space Complexity:** `O(log n)` average recursion depth.

---

### 2. Merge Sort

**Aim:** To sort an array using the divide-and-conquer Merge Sort algorithm.

**Algorithm:**
1. If array has 1 or 0 elements, return (base case).
2. Split the array into two equal halves.
3. Recursively sort the left half.
4. Recursively sort the right half.
5. Merge the two sorted halves into one sorted array.

**Time Complexity:** `O(n log n)` — Always (best, average, worst).  
**Space Complexity:** `O(n)` — Auxiliary array for merging.

---

## 🔬 Lab 4

> **Date:** 18/02/26 | **Page:** 34 *(Evaluation Lab)*

### 1. Quick Sort (Iterative)

**Aim:** To implement Quick Sort without recursion using an explicit stack.

**Algorithm:**
1. Push initial low and high indices onto a stack.
2. While stack is not empty:
   - Pop `low` and `high`.
   - Partition the subarray; get pivot index `p`.
   - If `p-1 > low`, push `(low, p-1)`.
   - If `p+1 < high`, push `(p+1, high)`.

**Time Complexity:** `O(n log n)` average; `O(n²)` worst.  
**Space Complexity:** `O(log n)` average stack space.

---

### 2. Binary Search 1/3 (Ternary Search)

**Aim:** To search by dividing the search space into three parts instead of two.

**Algorithm:**
1. Set `low = 0`, `high = n-1`.
2. While `low <= high`:
   - Compute `mid1 = low + (high-low)/3`.
   - Compute `mid2 = high - (high-low)/3`.
   - If `arr[mid1] == key`, return `mid1`.
   - If `arr[mid2] == key`, return `mid2`.
   - If `key < arr[mid1]`, set `high = mid1 - 1`.
   - If `key > arr[mid2]`, set `low = mid2 + 1`.
   - Else `low = mid1 + 1`, `high = mid2 - 1`.
3. Return -1 if not found.

**Time Complexity:** `O(log₃ n)` — Equivalent to `O(log n)`.  
**Space Complexity:** `O(1)`

---

### 3. Permutation Generator

**Aim:** To generate all permutations of a given set of numbers.

**Algorithm:**
1. Use backtracking: fix one element at each recursive level.
2. At each level, swap the current index with each remaining index.
3. Recurse for the next index.
4. Backtrack by swapping back.
5. When index reaches the last element, print the permutation.

**Time Complexity:** `O(n × n!)` — n! permutations, each takes O(n) to output.  
**Space Complexity:** `O(n)` — Recursion depth.

---

## 🔬 Lab 5

> **Date:** 25/02/26 | **Page:** 41

### 1. Fractional Knapsack

**Aim:** To maximise profit by selecting items (fractions allowed) using a greedy approach.

**Algorithm:**
1. Compute value/weight ratio for each item.
2. Sort items in descending order of ratio.
3. Greedily pick items:
   - If item fits fully, add full weight and value.
   - If not, add fraction: `(remaining_capacity / weight) * value`.
4. Return total maximum value.

**Time Complexity:** `O(n log n)` — Dominated by sorting.  
**Space Complexity:** `O(1)` extra (excluding input).

---

### 2. Convex Hull (Graham Scan)

**Aim:** To find the smallest convex polygon enclosing all given points.

**Algorithm:**
1. Find the point with the lowest y-coordinate (leftmost if tie) — the anchor.
2. Sort remaining points by polar angle with respect to anchor.
3. Push first three points onto a stack.
4. For each remaining point, while the top-2 of stack and new point make a non-left turn, pop the stack.
5. Push the new point.
6. Remaining stack points form the convex hull.

**Time Complexity:** `O(n log n)` — Dominated by sorting step.  
**Space Complexity:** `O(n)` — Stack storage.

---

### 3. Kth Smallest Element

**Aim:** To find the Kth smallest element in an unsorted array efficiently.

**Algorithm (QuickSelect):**
1. Choose a pivot and partition the array.
2. If pivot index == k-1, return pivot.
3. If pivot index > k-1, recurse on the left subarray.
4. Else recurse on the right subarray.

**Time Complexity:** `O(n)` average; `O(n²)` worst case.  
**Space Complexity:** `O(log n)` average recursion.

---

### 4. Maxmin (Find Max and Min simultaneously)

**Aim:** To find both maximum and minimum in an array with minimum comparisons.

**Algorithm (Tournament/Pair method):**
1. Compare elements in pairs: pick the larger for max-tracking, smaller for min-tracking.
2. Among the "larger" group, find the maximum.
3. Among the "smaller" group, find the minimum.
4. Total comparisons: ≈ 3n/2 - 2 (vs 2n-2 for naive approach).

**Time Complexity:** `O(n)` — Single pass with pair comparisons.  
**Space Complexity:** `O(1)`

---

## 🔬 Lab 6

> **Date:** 10/03/26 | **Page:** 53

### 1. Dijkstra's Algorithm

**Aim:** To find the shortest path from a source vertex to all other vertices in a weighted graph.

**Algorithm:**
1. Initialize distances: `dist[src] = 0`, all others = ∞.
2. Use a min-heap (priority queue) with `(distance, vertex)`.
3. While heap is not empty:
   - Extract vertex `u` with minimum distance.
   - For each neighbour `v` of `u`: if `dist[u] + weight(u,v) < dist[v]`, update `dist[v]` and push to heap.
4. Return all shortest distances.

**Time Complexity:** `O((V + E) log V)` with binary heap; `O(V²)` with array.  
**Space Complexity:** `O(V)`

---

### 2. Prim's Algorithm (MST)

**Aim:** To find the Minimum Spanning Tree of a weighted undirected graph.

**Algorithm:**
1. Start from any vertex. Mark it visited.
2. Add all edges from visited vertices to a min-heap.
3. Extract the minimum weight edge connecting a visited to an unvisited vertex.
4. Add that edge to MST, mark the new vertex visited.
5. Repeat until V-1 edges are selected.

**Time Complexity:** `O((V + E) log V)` with binary heap.  
**Space Complexity:** `O(V + E)`

---

### 3. Activity Selection (Greedy)

**Aim:** To select the maximum number of non-overlapping activities.

**Algorithm:**
1. Sort activities by their finish time (ascending).
2. Select the first activity.
3. For each subsequent activity: if its start time ≥ finish time of last selected, select it.
4. Return count of selected activities.

**Time Complexity:** `O(n log n)` — Dominated by sorting.  
**Space Complexity:** `O(1)`

---

### 4. Cycle Detection

**Aim:** To detect whether a cycle exists in a directed/undirected graph.

**Algorithm (DFS-based for directed graph):**
1. Use a `visited` array and a `recursion stack` array.
2. For each unvisited vertex, do DFS.
3. During DFS, if a neighbour is in the recursion stack → cycle detected.
4. On backtrack, remove vertex from recursion stack.

**Time Complexity:** `O(V + E)` — DFS traversal.  
**Space Complexity:** `O(V)` — visited + recursion stack arrays.

---

### 5. Kruskal's Algorithm (MST)

**Aim:** To find the Minimum Spanning Tree by sorting edges and using Union-Find.

**Algorithm:**
1. Sort all edges by weight in ascending order.
2. Initialize a Union-Find (Disjoint Set Union) structure.
3. For each edge (u, v, w) in sorted order:
   - If `find(u) != find(v)` (no cycle), add edge to MST and `union(u, v)`.
4. Stop when V-1 edges are selected.

**Time Complexity:** `O(E log E)` — Dominated by sorting edges.  
**Space Complexity:** `O(V)` — Union-Find structure.

---

## 🔬 Lab 7

> **Date:** 17/03/26 | **Page:** 73

### Multistage Graph (Forward & Backward)

**Aim:** To find the shortest path in a multistage graph using dynamic programming.

**Forward Algorithm:**
1. Let `cost[s]` = cost of reaching destination from stage `s`.
2. Process stages from right (destination) to left (source).
3. For each vertex v: `cost[v] = min over all edges(v,u) of { w(v,u) + cost[u] }`.
4. Trace back from source using recorded decisions.

**Backward Algorithm:**
1. Let `bcost[v]` = cost of reaching `v` from source.
2. Process stages from left (source) to right (destination).
3. For each vertex v: `bcost[v] = min over all edges(u,v) of { bcost[u] + w(u,v) }`.
4. Result = `bcost[destination]`.

**Time Complexity:** `O(V + E)` — Each vertex and edge processed once.  
**Space Complexity:** `O(V)` — Cost and decision arrays.

---

## 🔬 Lab 8

> **Date:** 08/04/26 | **Page:** 82

### Matrix Chain Multiplication

**Aim:** To find the optimal parenthesisation of matrix multiplication to minimise scalar multiplications.

**Algorithm (Dynamic Programming):**
1. Let `dp[i][j]` = minimum cost to multiply matrices from `i` to `j`.
2. Base case: `dp[i][i] = 0` (single matrix, no cost).
3. For chain length `l` = 2 to n:
   - For each `i` from 1 to n-l+1, set `j = i+l-1`.
   - For each split `k` from i to j-1:  
     `dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + p[i-1]*p[k]*p[j])`
4. Answer = `dp[1][n]`.

**Time Complexity:** `O(n³)` — Three nested loops.  
**Space Complexity:** `O(n²)` — DP table.

---

## 🔬 Lab 9

> **Date:** 22/04/26 | **Page:** 84

### 1. Floyd Warshall Algorithm

**Aim:** To find shortest paths between **all pairs** of vertices in a weighted graph.

**Algorithm:**
1. Initialize `dist[i][j]` with edge weights; `dist[i][i] = 0`; unreachable pairs = ∞.
2. For each intermediate vertex `k` (0 to n-1):
   - For each pair `(i, j)`:  
     `dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])`
3. Final `dist[i][j]` holds the shortest path between i and j.

**Time Complexity:** `O(V³)` — Three nested loops over all vertices.  
**Space Complexity:** `O(V²)` — Distance matrix.

---

### 2. Longest Common Subsequence (LCS)

**Aim:** To find the length of the longest subsequence common to two strings.

**Algorithm (Dynamic Programming):**
1. Create a 2D table `dp[m+1][n+1]` where m, n are string lengths.
2. Base case: `dp[i][0] = dp[0][j] = 0`.
3. For each `i`, `j`:
   - If `s1[i] == s2[j]`: `dp[i][j] = dp[i-1][j-1] + 1`
   - Else: `dp[i][j] = max(dp[i-1][j], dp[i][j-1])`
4. Answer = `dp[m][n]`.

**Time Complexity:** `O(m × n)` — Filling the DP table.  
**Space Complexity:** `O(m × n)` — DP table (can be optimised to O(min(m,n))).

---

### 3. Traveling Salesperson Problem (TSP)

**Aim:** To find the shortest tour that visits all cities exactly once and returns to start.

**Algorithm (Dynamic Programming / Held-Karp):**
1. Use bitmask DP: `dp[mask][i]` = min cost to visit cities in `mask`, ending at city `i`.
2. Base case: `dp[1][0] = 0` (start at city 0).
3. For each mask, for each city `i` in mask, try going to city `j` not in mask:  
   `dp[mask | (1<<j)][j] = min(..., dp[mask][i] + dist[i][j])`
4. Answer = `min over i of { dp[(1<<n)-1][i] + dist[i][0] }`.

**Time Complexity:** `O(n² × 2ⁿ)` — Exponential in number of cities.  
**Space Complexity:** `O(n × 2ⁿ)` — DP table.

---

### 4. 0/1 Knapsack

**Aim:** To maximise value of items in a knapsack where items cannot be fractioned.

**Algorithm (Dynamic Programming):**
1. Create table `dp[n+1][W+1]` where n = items, W = capacity.
2. For each item `i` and capacity `w`:
   - If `weight[i] > w`: `dp[i][w] = dp[i-1][w]` (can't include)
   - Else: `dp[i][w] = max(dp[i-1][w], dp[i-1][w-weight[i]] + value[i])`
3. Answer = `dp[n][W]`.

**Time Complexity:** `O(n × W)` — Pseudo-polynomial (depends on W).  
**Space Complexity:** `O(n × W)` — DP table (can be optimised to O(W)).

---

## 🔬 Lab 10

> **Date:** 28/04/26 | **Page:** 97

### 1. N-Queens Problem

**Aim:** To place N queens on an N×N chessboard such that no two queens attack each other.

**Algorithm (Backtracking):**
1. Place a queen row by row.
2. For each row, try each column:
   - Check if placement is safe (no conflict in column, diagonal, or anti-diagonal).
   - If safe, place queen and recurse to next row.
   - If all rows filled, record solution.
   - If no valid column found, backtrack (remove queen, try next column).

**Time Complexity:** `O(N!)` — At most N choices in row 1, N-1 in row 2, etc.  
**Space Complexity:** `O(N)` — Board state and recursion depth.

---

### 2. Subset Sum Problem

**Aim:** To determine if a subset of a given set sums to a target value.

**Algorithm (Backtracking / DP):**

*Backtracking:*
1. Include current element and recurse with reduced sum.
2. Exclude current element and recurse.
3. Base case: sum == 0 → found; no elements left and sum != 0 → not found.

*DP:*
1. `dp[i][s]` = true if subset of first i elements can sum to s.
2. `dp[i][s] = dp[i-1][s] OR dp[i-1][s-arr[i]]` (if arr[i] ≤ s).

**Time Complexity:** `O(2ⁿ)` backtracking; `O(n × sum)` DP.  
**Space Complexity:** `O(n)` backtracking; `O(n × sum)` DP.

---

### 3. Graph Colouring / Chromatic Number

**Aim:** To colour a graph using the minimum number of colours such that no two adjacent vertices share the same colour.

**Algorithm (Backtracking):**
1. Assign colours 1 to m to vertices one by one.
2. For each vertex, try each colour:
   - Check if no adjacent vertex has the same colour (safe).
   - If safe, assign colour and recurse to next vertex.
   - If not safe, try next colour.
   - If no colour fits, backtrack.
3. If all vertices coloured, solution found.

**Time Complexity:** `O(mⁿ)` — m colours, n vertices in worst case.  
**Space Complexity:** `O(n)` — Colour assignment array + recursion depth.

---

### 4. Hamiltonian Graph (Hamiltonian Path/Circuit)

**Aim:** To find a path/cycle that visits every vertex exactly once.

**Algorithm (Backtracking):**
1. Start from vertex 0; add to path.
2. Recursively try adding each unvisited adjacent vertex.
3. If path includes all vertices:
   - For Hamiltonian Path: solution found.
   - For Hamiltonian Circuit: check if last vertex connects back to start.
4. If stuck, backtrack (remove last vertex, try next option).

**Time Complexity:** `O(n!)` — Explore all possible vertex orderings.  
**Space Complexity:** `O(n)` — Path array + visited array + recursion depth.

---

## 📊 Time Complexity Summary

| Algorithm | Best | Average | Worst | Space |
|-----------|------|---------|-------|-------|
| Linear Search | O(1) | O(n) | O(n) | O(1) |
| Binary Search | O(1) | O(log n) | O(log n) | O(1) |
| Bubble Sort | O(n) | O(n²) | O(n²) | O(1) |
| Selection Sort | O(n²) | O(n²) | O(n²) | O(1) |
| Insertion Sort | O(n) | O(n²) | O(n²) | O(1) |
| Quick Sort | O(n log n) | O(n log n) | O(n²) | O(log n) |
| Merge Sort | O(n log n) | O(n log n) | O(n log n) | O(n) |
| Tower of Hanoi | O(2ⁿ) | O(2ⁿ) | O(2ⁿ) | O(n) |
| Binary Exponentiation | O(log n) | O(log n) | O(log n) | O(log n) |
| Dijkstra's | - | O((V+E) log V) | O(V²) | O(V) |
| Prim's MST | - | O((V+E) log V) | O(V²) | O(V+E) |
| Kruskal's MST | - | O(E log E) | O(E log E) | O(V) |
| Floyd Warshall | O(V³) | O(V³) | O(V³) | O(V²) |
| LCS | O(mn) | O(mn) | O(mn) | O(mn) |
| 0/1 Knapsack | O(nW) | O(nW) | O(nW) | O(nW) |
| Fractional Knapsack | O(n log n) | O(n log n) | O(n log n) | O(1) |
| TSP (Held-Karp) | O(n²·2ⁿ) | O(n²·2ⁿ) | O(n²·2ⁿ) | O(n·2ⁿ) |
| Matrix Chain Mult. | O(n³) | O(n³) | O(n³) | O(n²) |
| N-Queens | - | O(N!) | O(N!) | O(N) |
| Subset Sum (DP) | O(n·sum) | O(n·sum) | O(n·sum) | O(n·sum) |
| Hamiltonian Path | - | O(n!) | O(n!) | O(n) |

---

## 🛠️ Technologies Used

- **Language:** C / C++ / Python *(as applicable per program)*
- **IDE:** VS Code / GCC compiler
- **Platform:** Linux / Windows

---

## 📁 Repository Structure

```
ADA-Lab/
├── Lab1/
│   ├── tower_of_hanoi.c
│   ├── bouncing_ball.c
│   ├── binary_exponentiation.c
│   ├── string_permutation.c
│   ├── linear_search.c
│   ├── horners_rule.c
│   ├── bubble_sort.c
│   ├── selection_sort.c
│   ├── missing_number.c
│   └── first_duplicate.c
├── Lab2/
│   ├── insertion_sort.c
│   └── binary_search.c
├── Lab3/
│   ├── quick_sort.c
│   └── merge_sort.c
├── Lab4/
│   ├── quick_sort_iterative.c
│   ├── ternary_search.c
│   └── permutation_generator.c
├── Lab5/
│   ├── fractional_knapsack.c
│   ├── convex_hull.c
│   ├── kth_smallest.c
│   └── maxmin.c
├── Lab6/
│   ├── dijkstra.c
│   ├── prims.c
│   ├── activity_selection.c
│   ├── cycle_detection.c
│   └── kruskal.c
├── Lab7/
│   ├── multistage_forward.c
│   └── multistage_backward.c
├── Lab8/
│   └── matrix_chain_multiplication.c
├── Lab9/
│   ├── floyd_warshall.c
│   ├── lcs.c
│   ├── tsp.c
│   └── knapsack_01.c
├── Lab10/
│   ├── n_queens.c
│   ├── subset_sum.c
│   ├── graph_colouring.c
│   └── hamiltonian.c
└── README.md
```

---

*© 2026 Shivraj Singh | UE243098 | CSE 4th Semester*
