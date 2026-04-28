ADA Lab Programs
This repository contains all my Analysis and Design of Algorithms (ADA) lab programs.
Name: Shivraj Singh Branch: CSE roll no.- UE243098 Semester: 4th
Aim To implement and understand various algorithms as part of ADA lab.

1. Binary Exponentiation
Aim: To compute aⁿ efficiently using fast exponentiation (divide and conquer).

Algorithm:
If n = 0, return 1.
If n is even, return power(a, n/2) * power(a, n/2).
If n is odd, return a * power(a, n-1).
(Optimised): compute half = power(a, n/2) once; if n even return half*half, else a*half*half.

Time Complexity: O(log n) — Number of recursive calls halved each step.
Space Complexity: O(log n) — Recursion depth.

2. Bouncing Ball Simulation
Aim: To simulate a bouncing ball and compute the total distance travelled.
Algorithm:

Accept initial height h and rebound factor r (0 < r < 1).
For each bounce, compute: up distance = h * r, then set h = h * r.
Sum all distances: first drop + (2 × every subsequent bounce height) until h is negligible.
Return total distance.

Time Complexity: O(n) where n is the number of bounces simulated.
Space Complexity: O(1)

3. Bubble Sort
Aim: To sort an array by repeatedly swapping adjacent out-of-order elements.
Algorithm:

For i = 0 to n-1 (outer pass):
For j = 0 to n-i-2 (inner pass):
If arr[j] > arr[j+1], swap them.
After each outer pass, the largest unsorted element bubbles to its correct position.

Time Complexity: O(n²) worst/average; O(n) best case (already sorted, with flag).
Space Complexity: O(1) — In-place.

4. First Duplicate Finder
Aim: To find the first duplicate element in an array.
Algorithm:

Use a hash set to track visited elements.
For each element in the array:

If it already exists in the set, return it (first duplicate).
Otherwise, add it to the set.


If no duplicate found, return -1.

Time Complexity: O(n) average case.
Space Complexity: O(n) — Hash set storage.

5. Horner's Rule
Aim: To evaluate a polynomial efficiently using Horner's method.
Algorithm:

Given polynomial aₙxⁿ + aₙ₋₁xⁿ⁻¹ + … + a₀, rewrite as (…((aₙ)x + aₙ₋₁)x + …)x + a₀.
Start with result = aₙ.
For i from n-1 down to 0: result = result * x + aᵢ.
Return result.

Time Complexity: O(n) — Single pass through all coefficients.
Space Complexity: O(1)

6. Linear Search
Aim: To search for a target element in an unsorted array.
Algorithm:

Start from the first element (index 0).
Compare each element with the target key.
If found, return the index.
If the end of array is reached without a match, return -1.

Time Complexity: O(n) worst/average case; O(1) best case.
Space Complexity: O(1)

7. Missing Number Finder
Aim: To find the missing number in an array of integers from 1 to n.
Algorithm:

Compute expected sum = n*(n+1)/2.
Compute actual sum of all elements in the array.
Missing number = expected sum − actual sum.

Time Complexity: O(n) — Single pass to compute sum.
Space Complexity: O(1)

8. Selection Sort
Aim: To sort an array by repeatedly selecting the minimum element.
Algorithm:

For i = 0 to n-1:
Find the minimum element in the subarray arr[i…n-1].
Swap it with arr[i].
Repeat until the array is sorted.

Time Complexity: O(n²) — Always (even if sorted).
Space Complexity: O(1) — In-place.

9. String Permutation
Aim: To generate all permutations of a given string using backtracking.
Algorithm:

Fix one character at index i (swap with current position).
Recursively generate permutations for the remaining substring.
Backtrack (swap back) to restore the original string.
Repeat until all characters are fixed (base case: i = n-1).

Time Complexity: O(n × n!) — n! permutations, each of length n to print.
Space Complexity: O(n) — Recursion depth.

10. Tower of Hanoi
Aim: To solve the Tower of Hanoi problem using recursion.
Algorithm:

If n = 1, move the disk directly from source to destination.
Move n-1 disks from source to auxiliary peg (recursively).
Move the nth (largest) disk from source to destination.
Move n-1 disks from auxiliary to destination peg (recursively).

Time Complexity: O(2ⁿ) — Each call spawns 2 more calls, making this exponential.
Space Complexity: O(n) — Recursive call stack depth.
