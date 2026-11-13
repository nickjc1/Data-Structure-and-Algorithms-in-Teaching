# Chapter 2 Assignment, Part 1 — Search Fundamentals

Use C++17. All indices are zero-based. A lookup that returns an index must return `-1` when the target is absent. The provided vectors are small enough for their sizes and indices to fit in an `int`.

## Question 1 — Linear Search in an Unsorted Vector

Include `<vector>` for `std::vector<int>` and `<algorithm>` for `std::find`. Write the linear search loop yourself and use `std::find` to check it.

Write a standalone function `int linearSearch(const std::vector<int>& ids, int target)`. Scan from left to right and return the first matching index.

In `main()`, call `std::find(ids.begin(), ids.end(), target)`. If it returns `ids.end()`, the expected index is `-1`. Otherwise, subtract `ids.begin()` from the returned iterator to get the expected index. Compare that result with your function's output.

| Input | Target | Expected index |
|---|---:|---:|
| `{42, 17, 63, 17, 28}` | 17 | 1 |
| `{42, 17, 63, 17, 28}` | 99 | -1 |
| `{}` | 17 | -1 |

Explain why the worst-case running time is `O(n)`.

## Question 2 — Iterative Binary Search in a Sorted Roster

Include `<vector>` for the roster. Create a `StudentRoster` class whose constructor receives an vector of student IDs already sorted in nondecreasing order and stores it in a private member. Implement `int findIterative(int target) const` as a public method using your own binary search loop.

Use the half-open range `[left, right)`. Start with `left = 0` and `right = size`. While the range is nonempty, compute `mid = left + (right - left) / 2` and compare the middle ID with the target. Return on a match, set `left = mid + 1` when the middle ID is too small, or set `right = mid` when it is too large.

For `{10, 20, 30, 40, 50, 60, 70}`, trace `left`, `right`, and `mid` for targets `60` and `35`. Expect indices `5` and `-1`, respectively. Also test empty and single-element vectors, the first and last IDs, and targets below and above the roster's range.

Explain how sorted order lets you discard part of the range. For each size `n` in `{8, 32, 128}`, make a roster containing IDs `1` through `n`. Search for ID `0` with your linear search from Question 1 and your iterative binary search. Count one probe per inspected element, even if the loop compares that element with the target twice. Explain how the probe counts grow.

## Question 3 — Recursive Binary Search in the Same Roster

Reuse the roster’s `std::vector<int>` from Question 2. Write the recursive search yourself.

Add `int findRecursive(int target) const` to `StudentRoster`. The public method passes the full range to a private recursive helper. A recursive function calls itself on a smaller problem. A base case returns a result directly.

- If the range is empty, return `-1` before accessing the vector.
- If the middle ID matches, return its index.
- Otherwise make one recursive call on the remaining half and return that call's result.

Run the Question 2 cases against both methods. Also try a sorted vector with duplicate IDs. Either method may return any index holding the target. Trace the recursive calls for target `35` in the seven-ID example, including the empty range. Explain the `O(log n)` worst-case time of both methods and compare `O(1)` iterative extra space with `O(log n)` recursive call-stack space.

## Question 4 — Searching with the C++ Standard Library

Include `<algorithm>` for `std::find` and `std::binary_search`, and `<vector>` for the input data.

1. Use `std::find` on the unsorted IDs `{31, 52, 14, 52, 8}`. Pass the vector's beginning and end iterators and the target. Report `-1` if the result equals `end()`. Otherwise, subtract `begin()` from the result to get the first matching index.
2. Use `std::binary_search` on the sorted IDs `{10, 20, 30, 40, 50}`. Report whether the target exists using the returned boolean.

| Function | Target | Expected result |
|---|---:|---|
| `std::find` | 52 | Index 1 |
| `std::find` | 99 | -1 |
| `std::binary_search` | 40 | `true` |
| `std::binary_search` | 35 | `false` |

Test both functions with an empty vector. Explain which function you would choose to get the first matching position, which you would choose for a yes-or-no lookup on sorted data, and why input order matters.

## What You Practiced

- Finding the first match in an unsorted vector with linear search and checking the result with `std::find`.
- Using sorted order to narrow a half-open search range in iterative and recursive binary search.
- Tracing search bounds and recursive calls, and testing empty vectors, duplicates, and missing targets.
- Comparing `O(n)` linear search with `O(log n)` binary search, and distinguishing constant extra space from recursive call-stack space.
- Encapsulating sorted data in a class with public `const` search methods and a private recursive helper.
- Choosing a standard-library search function based on input order and whether the caller needs an iterator or a boolean.
