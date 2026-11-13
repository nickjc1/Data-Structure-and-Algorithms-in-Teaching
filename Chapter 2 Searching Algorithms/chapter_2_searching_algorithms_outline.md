# Chapter 2 — Searching Algorithms in C++

Reference [Searching Algorithms — GeeksforGeeks](https://www.geeksforgeeks.org/dsa/searching-algorithms/)

This chapter explains how to locate values in a collection, how sorted order changes the cost of searching, and how to choose among C++ standard-library search functions. Review vector indexing, `size()`, and iterators from Chapter 1 before starting.

## 1. Decide What the Search Should Return

A search can answer several different questions about the same vector.

| Goal | Example for target 4 in `{2, 4, 4, 7}` |
|---|---|
| Check whether the target exists | `true` |
| Find any matching index | `1` or `2` |
| Find the first and last matching indices | `1` and `2` |
| Count occurrences | `2` |
| Find the insertion boundary before or after existing matches | `1` before the existing matches, or `3` after them |

For the handwritten index searches in this guide, `-1` represents a missing target. Standard-library functions have their own return conventions. Check whether a function returns an index, an iterator, or a boolean before using its result.

## 2. Linear Search

Inspect elements from left to right until one matches. Every earlier element has already been checked, so the first match you encounter is the first occurrence. This works regardless of input order.

The examples use `int` indices and assume vector sizes fit in an `int`.

```text
LINEAR SEARCH(values, target)
    FOR each index from 0 through length(values) − 1
        IF the value at index equals target
            RETURN index
    RETURN −1
```

In `{8, 3, 12, 3, 1}`, searching for `3` examines `8` and then `3`, returning index `1`. Searching for `9` examines all five elements and returns `-1`. The best case takes one inspection. The worst case takes `n` inspections and uses constant extra space.

## 3. Iterative Binary Search

Start with a vector sorted in nondecreasing order. Equal values can appear next to each other. If its middle element is smaller than the target, all elements to its left are also too small. If its middle element is larger than the target, all elements to its right are also too large. Each step keeps only the part where a match could still occur.

Use the half-open range `[left, right)`. The left endpoint is included and the right endpoint is excluded. The number of candidates is `right - left`, so `left == right` means the range is empty.

```text
BINARY SEARCH(values, target)
    left ← 0
    right ← length(values)

    WHILE left < right
        mid ← left + floor((right − left) / 2)
        IF the value at mid equals target
            RETURN mid
        IF the value at mid is less than target
            left ← mid + 1
        ELSE
            right ← mid

    RETURN −1
```

Trace a search for `7` in `{2, 4, 6, 8, 10, 12, 14}`.

| Candidate range | Midpoint index | Value | Next step |
|---|---:|---:|---|
| `[0, 7)` | 3 | 8 | Keep `[0, 3)` |
| `[0, 3)` | 1 | 4 | Keep `[2, 3)` |
| `[2, 3)` | 2 | 6 | Keep `[3, 3)` |
| `[3, 3)` | | | Return `-1` |

For target `12`, the first probe also sees `8`. This time the range becomes `[4, 7)` and the next probe finds `12` at index `5`.

At the start of each iteration, any possible match is inside the current range. This fact is the loop invariant. Each update preserves it and shrinks the range on every miss. For example, setting `left = mid` can leave a one-element range unchanged. An exact-match binary search can return any occurrence of a duplicate. Use range boundaries when you need the first or last occurrence.

## 4. Recursive Binary Search

A recursive function handles a small case directly or calls itself on a smaller input. For binary search, the smaller input is a narrower range of indices into the same vector.

- Start the search with `left = 0` and `right = values.size()`. Each recursive call receives the bounds of the range it should search.
- In the helper, check for an empty range before accessing the midpoint. Return `-1` for an empty range and return the midpoint index on a match.
- For a miss at the midpoint, return the result of one recursive call with either `[mid + 1, right)` or `[left, mid)`.
- Pass the vector by `const` reference so each call searches the same data without copying it.

The trace for target `7` from the previous section becomes `[0, 7) → [0, 3) → [2, 3) → [3, 3)`. The last call returns `-1`, which is returned through the earlier calls.

| Search | Best-case time | Worst-case time | Extra space |
|---|---|---|---|
| Linear | `O(1)` | `O(n)` | `O(1)` |
| Iterative binary | `O(1)` | `O(log n)` | `O(1)` |
| Recursive binary | `O(1)` | `O(log n)` | `O(log n)` call stack |

These costs cover the search itself. In the worst case, each binary search probe leaves at most half as many candidates. Doubling the input size adds one probe to the worst-case count for a nonempty vector.

For one lookup in unsorted data, a linear scan takes at most `O(n)` time. If you sort the data first, include the cost of sorting in the total. On data that stays sorted, each subsequent binary search takes `O(log n)` time.

## 5. Searching with the C++ Standard Library

Include `<algorithm>` for these functions. Pass an iterator range such as `[values.begin(), values.end())`. On a vector, an iterator can be converted to an index by subtracting `values.begin()`. The end iterator marks the position past the last element and must never be dereferenced.

| Function | Result | Input order | Worst-case time on a vector |
|---|---|---|---|
| `std::find` | First matching iterator or `end()` | Any | `O(n)` |
| `std::binary_search` | `true` if the target exists | Ascending in this chapter | `O(log n)` |
| `std::lower_bound` | Iterator to the first value greater than or equal to the target, or `end()` | Ascending in this chapter | `O(log n)` |
| `std::upper_bound` | Iterator to the first value strictly greater than the target, or `end()` | Ascending in this chapter | `O(log n)` |

```text
first ← lower bound of target in the sorted vector
afterLast ← upper bound of target in the sorted vector
count ← distance from first to afterLast

IF count > 0
    firstIndex ← distance from the beginning to first
    lastIndex ← distance from the beginning to afterLast, minus 1
```

The matching range is `[first, afterLast)`. For `{2, 4, 4, 4, 7, 9}`, target `4` gives bounds at indices `1` and `4`, so the last matching index is `3` and the count is `3`. For target `5`, both bounds land on index `4`, so the count is zero. If the target is larger than every element or the vector is empty, both functions return `end()`.

## 6. Understanding Search Boundaries

Exact-match binary search can stop as soon as it finds the target. A boundary search continues narrowing the range until it finds the position where a condition first becomes true. The condition must stay true for all later positions.

For a lower bound, the condition is `values[index] >= target`. On ascending data, all values below the target come first. If the midpoint is below the target, move `left` to `mid + 1`. Otherwise move `right` to `mid`, keeping that index as a possible answer. The elements strictly before `left` are known to be below the target. Any elements from `right` onward satisfy the condition. When the bounds meet, their common index is the boundary. It can equal the vector size if no element satisfies the condition.

An upper bound uses the same idea with `values[index] > target`. The two conditions differ only for values equal to the target. That is why the range between the two boundaries contains exactly the matches.

## 7. Study and Review

- Trace linear search and iterative binary search on the same sorted data for a missing target below the smallest value. Count inspected elements and compare how the counts grow as the vector gets larger.
- Test an empty vector, one element, a match at each endpoint, targets below and above the stored values, and duplicates. State the expected result before running each test.
- On `{1, 3, 3, 3}`, predict both bounds for targets `0`, `3`, and `4`. For each target, identify which iterators can safely be dereferenced.
- Before writing a binary search, state what the current bounds represent, which comparison lets you discard a region, and what guarantees the range shrinks.
- Explain why sorting before a single lookup changes the total cost, and why an already-sorted vector makes repeated binary searches possible.
