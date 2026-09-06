# C++ `vector` Tutorial Outline

Based on the GeeksforGeeks tutorial:  
https://www.geeksforgeeks.org/cpp/vector-in-cpp-stl/

## 1. Introduction to `vector`

- What a `vector` is
- `vector` as an STL sequence container
- Dynamic resizing
- Contiguous memory storage
- Automatic memory management
- Random access to elements
- Basic example using `vector<int>`

---

## 2. Declaration and Initialization

- Include the `<vector>` header
- Basic syntax:

```cpp
vector<T> v;
```

- Understanding the element type `T`
- Declaring vectors of different data types
- Initializing a vector with values

---

## 3. Operations on a Vector

### 3.1 Insert Elements

#### `push_back()`

- Add an element to the end
- Average complexity: `O(1)`

#### `insert()`

- Insert at a specified location
- Use an iterator such as `begin()`
- Complexity: `O(n)`

Example:

```cpp
v.push_back(value);
v.insert(v.begin() + 1, value);
```

---

### 3.2 Access Elements

- Subscript operator `[]`
- `at()`
- Difference between `[]` and `at()`
  - `[]`: no bounds checking
  - `at()`: bounds checking
- `std::out_of_range` exception
- Both provide `O(1)` random access

---

### 3.3 Update Elements

- Modify an existing element using its index
- Assignment:

```cpp
v[i] = newValue;
```

- Updating with `[]`
- Updating with `at()` if desired

---

### 3.4 Find Vector Size

- `size()`
- Number of currently stored elements

Example:

```cpp
v.size();
```

---

### 3.5 Traverse a Vector

- Index-based `for` loop
- Range-based `for` loop
- Iterator-based traversal
- Traversal complexity: `O(n)`

References in range-based loops:

```cpp
for (int &x : v)
```

Use this form when elements need to be modified.

Read-only traversal with `const` references:

```cpp
for (const int &x : v)
```

Use this form for efficient read-only access.

---

### 3.6 Delete Elements

#### `pop_back()`

- Remove the last element
- Complexity: `O(1)`

#### `erase()`

- Remove a specific element or range
- Usually `O(n)`

- Using `find()` with `erase()`

---

### 3.7 Check Whether a Vector Is Empty

- `empty()`
- Returns `true` when there are no elements
- Returns `false` otherwise

Common pattern:

```cpp
if (v.empty()) {
    // ...
}
```

---

## 4. Multidimensional Vectors

- Vector of vectors
- Basic 2D vector syntax:

```cpp
vector<vector<int>> matrix;
```

- Initializing a 2D vector
- Nested traversal
- Using `auto` and references in nested loops

---

## 5. Advantages of `vector`

- Dynamic size
- `O(1)` random access
- Automatic storage management
- Compatibility with STL iterators
- Compatibility with STL algorithms and other containers

---

# Recommended Teaching Sequence

For a DSA course, the material can be introduced incrementally in the following order.

## Part 1 — Fundamentals

- `vector<T>`
- Declaration
- Initialization

## Part 2 — Adding Elements

- `push_back()`
- `insert()`
- `begin()`

## Part 3 — Accessing Elements

- `[]`
- `at()`
- Bounds checking
- Exceptions

## Part 4 — Modifying and Inspecting

- Update elements
- `size()`

## Part 5 — Traversal

- Index-based loop
- Range-based loop
- References
- `const` references
- Iterators

## Part 6 — Removing Elements

- `pop_back()`
- `erase()`

## Part 7 — Vector State

- `empty()`

## Part 8 — Advanced Structure

- `vector<vector<T>>`

---

## Teaching Note

This progression introduces the `vector` API incrementally so students can become comfortable with basic storage, insertion, and access before moving to traversal, removal, and multidimensional vectors.
