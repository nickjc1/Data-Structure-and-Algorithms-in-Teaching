# Chapter 2 Assignment, Part 2 — Search Boundaries and Applications

Use C++17 and zero-based indices. Keep the vectors owned by your classes private and mark read-only methods `const`. Use the input assumptions given in each question.

## Question 1 — First and Last Positions and Counting 1s

Include `<vector>` for the stored data and `<algorithm>` for `std::lower_bound` and `std::upper_bound`.

Build a `SortedNumbers` class that owns a vector sorted in nondecreasing order, which allows duplicates. Return the first index, last index, and count of a target as a small result type with three named fields.

- Call `std::lower_bound(values.begin(), values.end(), target)` to find the first element greater than or equal to the target.
- Call `std::upper_bound(values.begin(), values.end(), target)` to find the first element strictly greater than the target.
- The target is absent if the lower bound equals `end()` or points to a value different from the target. Check for `end()` first to avoid dereferencing it. For an absent target, return `{-1, -1, 0}`. Otherwise, use the distance from `begin()` to the lower bound for the first index, one position before the upper bound for the last index, and the difference between the bounds for the count.

Add a method that assumes the stored vector contains only zeros and ones. Use `std::lower_bound(values.begin(), values.end(), 1)` to locate where the ones start and subtract that iterator from `end()` to get the count.

| Input | Operation | Expected result |
|---|---|---|
| `{2, 4, 4, 4, 7, 9}` | Find the range of 4 | `{1, 3, 3}` |
| `{2, 4, 4, 4, 7, 9}` | Find the range of 5 | `{-1, -1, 0}` |
| `{2, 4, 4}` | Find the range of 4 | `{1, 2, 2}` |
| `{}` | Find the range of 4 | `{-1, -1, 0}` |
| `{0, 0, 1, 1, 1}` | Count ones | 3 |
| `{0, 0, 0}` | Count ones | 0 |
| `{1, 1, 1}` | Count ones | 3 |
| `{}` | Count ones | 0 |

Explain why subtracting the two bounds gives the number of matches even when the upper bound is `end()`.

## Question 2 — Integer Square Root

Implement the binary search loop yourself using integer arithmetic.

Write a standalone function that takes an integer `n` in the range `0` through `2,147,483,647`. Use binary search over candidate integers to return the greatest `r` satisfying `r² ≤ n`. Handle zero and make the comparison safe for large candidates. For example, for a positive candidate `mid`, test whether `mid <= n / mid` to avoid multiplying two large integers.

Test `0 → 0`, `1 → 1`, `49 → 7`, `50 → 7`, and `2147483647 → 46340`. Explain why all candidates up to the answer pass the test and all larger candidates fail it.

## Question 3 — Minimum and Target Search in a Rotated Sorted Array

Include `<vector>` for the stored data. Implement both searches yourself.

Build a `RotatedNumbers` class for a nonempty vector of distinct integers originally sorted in ascending order. The vector may be rotated or left in its original order.

1. Find the index of the minimum in logarithmic time. Compare the midpoint with the current rightmost value to decide which side still contains the minimum. Keep the midpoint when it could itself be the minimum.
2. Use the minimum index to split the vector into sorted segments. Skip any empty segment before checking endpoints. Select the segment whose endpoints enclose the target and use a private binary search helper there. If neither segment can contain the target, return `-1`. Return its index in the original vector or `-1`.

For `{40, 50, 60, 10, 20, 30}`, expect minimum index `3`, target `50` at index `1`, target `20` at index `4`, and target `35` absent. Also test an unrotated vector and a one-element vector. Explain why the two search steps together take `O(log n)` time.

## Question 4 — Unbounded Binary Search

Include `<vector>` for the reader’s stored data. Implement the probe expansion and binary search yourself.

Build a `SequenceReader` that owns a finite vector of strictly increasing integers. Expose `bool tryGet(int index, int& value) const`. Return `true` and write the element to `value` when the index is valid. Return `false` for an invalid index. The search function receives a reader and a target. Pass the reader by `const` reference and use `tryGet` as the only way to inspect the sequence. Read the output value only when `tryGet` returns `true`. Assume the sequence contains at most 1,000,000 elements so that doubling the probe fits in an `int`.

1. Probe index `0`. Return `-1` if the sequence is empty or the target is smaller than the first value. Return `0` if the first value matches.
2. Probe indices `1, 2, 4, 8, …` until a probe is out of range or its value is at least the target.
3. Binary-search from one past the last index known to hold a smaller value through the final probe, inclusive. Treat an out-of-range midpoint as too far to the right. Return the matching index or `-1`.

For `{2, 5, 8, 12, 16, 23}` and target `23`, the probes visit `0, 1, 2, 4, 8`. Index `4` holds `16` and index `8` is out of range. Searching indices `5` through `8` finds the target at `5`. Also test an empty sequence, a match at index `0`, a match exactly at a doubled probe index, and a target greater than the last element.

## Question 5 — Aggressive Cows

Include `<vector>` for the stall positions. Implement the feasibility check and binary search yourself.

Build a `StallPlanner` that owns an already-sorted vector of distinct stall positions. Place one cow per selected stall and maximize the smallest distance between consecutive placed cows. Assume there are at least two cows and at least as many stalls as cows, with positions between `0` and `1,000,000,000`.

1. Implement a private feasibility method. For a proposed gap, place the first cow at the leftmost stall. Scan left to right and place each remaining cow in the earliest stall at least that far from the last occupied stall.
2. Trace the feasibility check by hand before combining it with binary search. For positions `{1, 2, 4, 8, 9}` and three cows, gap `3` is feasible by placing cows at `1, 4, 8`. Gap `4` allows only two cows with the greedy scan.
3. Binary-search candidate gaps from `1` through the distance between the first and last stalls. Return the largest feasible gap. The example answer is `3`. With the same stalls, expect a gap of `8` for two cows and `1` for five cows. Run both cases through the public method.

Explain why placing each cow as early as possible leaves at least as much room for the remaining cows, and why feasibility at one gap implies feasibility at every smaller positive gap.

## What You Practiced

- Using `std::lower_bound` and `std::upper_bound` to find the first and last occurrences of a target, count duplicates, and count ones in sorted binary data.
- Using the minimum element to identify sorted segments in a rotated vector and search for a target.
- Discovering a search range by doubling probe indices when the sequence length is unknown.
- Searching over candidate answers by identifying where a condition changes from true to false, as in integer square root and stall placement.
- Keeping stored data private and using class methods to separate search logic from data access and feasibility checks.
