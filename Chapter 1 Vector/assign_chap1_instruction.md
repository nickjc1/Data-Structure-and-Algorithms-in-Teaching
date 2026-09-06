# C++ Assignment: Practicing `vector<T>`

## Practices 1 to 4 Learning Objectives

After completing this assignment, you should be able to:

- Declare and initialize vectors.
- Store primitive values, objects, and pointers in vectors.
- Add elements using `push_back()` and `insert()`.
- Access elements using `operator[]` and `at()`.
- Apply object-oriented programming concepts with vectors.
- Use pointers safely and release dynamically allocated memory.

## Allowed Vector Features

Use only the vector features covered so far:

- Vector declaration and initialization
- `push_back()`
- `insert()`
- `begin()` when required by `insert()`
- `operator[]`
- `at()`

You may also use loops, functions, classes, constructors, getters, setters, pointers, `new`, and `delete`.

Do not use `erase()`, `pop_back()`, `clear()`, sorting algorithms, or other vector operations not yet covered.

---

## Practice 1: Quiz Score Organizer

Write a program that stores quiz scores in a `vector<int>`.

### Requirements

1. Create an empty vector named `scores`.

2. Add the following scores using `push_back()`:

   ```text
   78, 85, 91
   ```

3. Insert `72` at the beginning.

4. Insert `88` immediately before `91`.

5. Print all five scores using index access with `operator[]`.

6. Use `at()` to print:

   - The first score
   - The third score
   - The last score

7. Calculate and print the average score.

### Expected Vector

```text
72 78 85 88 91
```

### Example Output

```text
All scores: 72 78 85 88 91
First score: 72
Third score: 85
Last score: 91
Average: 82.8
```

### Reflection Question

What could happen if the program evaluates `scores[10]`? How would `scores.at(10)` behave differently?

---

## Practice 2: Safe Product Lookup

Create a small product lookup program that combines vectors and pointers.

### Starting Data

```cpp
vector<string> products = {
    "Keyboard",
    "Mouse",
    "Monitor",
    "Webcam",
    "Headphones"
};
```

### Requirements

Write the following function:

```cpp
void showProduct(const vector<string>* products, int index);
```

The function must:

1. Receive a pointer to the vector.
2. Access the vector through the pointer.
3. Use `at(index)` instead of `operator[]`.
4. Print the product at the requested index.
5. Display an error message when the index is invalid.

Your `main()` function must:

1. Create the product vector.
2. Create a pointer that stores the address of the vector.
3. Ask the user for an index.
4. Pass the pointer and index to `showProduct()`.

### Example Interaction

```text
Enter a product index: 2
Product at index 2: Monitor
```

### Invalid Input Example

```text
Enter a product index: 8
Error: product index is out of range.
```

### Hint

`at()` throws an `out_of_range` exception for an invalid index. You may use:

```cpp
try {
    // Access the element.
}
catch (const out_of_range& error) {
    // Print an error message.
}
```

---

## Practice 3: Student Record Book

Create a vector that stores class objects.

### Part A: Create a `Student` Class

Each student must have the following private data members:

```cpp
string name;
int studentId;
double grade;
```

Add the following:

- A constructor that initializes all three members
- Getter methods
- A `display()` method

Example output format:

```text
ID: 102, Name: Maya, Grade: 91.5
```

### Part B: Store Students in a Vector

1. Initialize a `vector<Student>` with the following students:

   ```text
   101, Liam, 84.5
   102, Maya, 91.5
   103, Noah, 78.0
   ```

2. Use `push_back()` to add:

   ```text
   105, Sofia, 95.0
   ```

3. Use `insert()` to place the following student before Noah:

   ```text
   104, Ethan, 88.5
   ```

4. Use `operator[]` to display Liam.

5. Use `at()` to display Ethan.

6. Print all five students by calling each object's `display()` method.

### Expected Order

```text
Liam
Maya
Ethan
Noah
Sofia
```

### Design Requirement

The vector must store `Student` objects, not separate vectors for names, IDs, and grades.

---

## Practice 4: Device Inventory with Object Pointers

Create an inventory that stores pointers to dynamically allocated objects.

### Part A: Create a `Device` Class

Each device must contain:

```cpp
int id;
string name;
double price;
```

Add the following:

- A constructor
- Getter methods
- A `setPrice()` method
- A `display()` method

### Part B: Create the Inventory

Declare the following vector:

```cpp
vector<Device*> inventory;
```

Dynamically create and add these devices using `push_back()`:

```text
1, Laptop, 899.99
2, Tablet, 499.99
3, Printer, 249.99
```

Then dynamically create and insert the following device at index `1`:

```text
4, Monitor, 329.99
```

### Part C: Access the Objects

1. Access the first device using `operator[]`.
2. Access the device at index `1` using `at()`.
3. Use the pointer operator `->` to call `display()`.
4. Ask the user for an index and display the corresponding device safely.
5. Access the Tablet through the vector and change its price to `449.99`.
6. Display the complete inventory.

### Expected Order

```text
Laptop
Monitor
Tablet
Printer
```

### Memory-Management Requirement

Before the program finishes, call `delete` on every dynamically allocated `Device`.

Remember that destroying a `vector<Device*>` does not automatically delete the objects its pointers reference.

---

# Practices 5 and 6

The first four practices focus on vector declaration, initialization, insertion, element access, exceptions, objects, pointers, and manual memory management. The following two practices extend the assignment to the remaining topics in the vector tutorial outline.

## Additional Vector Features Allowed for Practices 5 and 6

For **Practice 5** and **Practice 6 only**, students may additionally use:

- Element assignment to update an existing vector element
- `size()`
- Index-based traversal
- Range-based `for` loops
- References in range-based loops
- `const` references in range-based loops
- Iterators
- `pop_back()`
- `erase()`
- `empty()`
- `vector<vector<T>>`
- Nested loops
- `auto` when working with iterators or nested vectors

The original restrictions for Practices 1–4 remain unchanged.

---

## Practice 5: Inventory List Maintenance and Traversal

Create a program that stores item quantities in a `vector<int>` and demonstrates how to inspect, update, traverse, and remove elements from a vector.

### Starting Data

Initialize the vector as follows:

```cpp
vector<int> quantities = {12, 8, 15, 6, 20};
```

The five values represent the quantities of five inventory items.

### Part A: Inspect the Vector

1. Print the number of elements using `size()`.
2. Print every quantity using an index-based `for` loop.
3. The loop condition must use `quantities.size()` rather than a hard-coded number.

Example format:

```text
Number of items: 5
Quantities: 12 8 15 6 20
```

### Part B: Update Elements

Use element assignment to make the following changes:

1. Change the quantity at index `1` from `8` to `10` using `operator[]`.
2. Change the quantity at index `3` from `6` to `9` using `at()`.
3. Print the updated vector.

Expected values:

```text
12 10 15 9 20
```

### Part C: Traverse with a Range-Based Loop

Use a range-based `for` loop with a reference:

```cpp
for (int &quantity : quantities)
```

Inside the loop, increase every quantity by `1`.

Then use a second range-based loop with a `const` reference:

```cpp
for (const int &quantity : quantities)
```

Use this loop only to print the values. Do not modify them.

Expected values after the increase:

```text
13 11 16 10 21
```

### Part D: Traverse with an Iterator

Use an iterator to print all vector elements.

Declare the iterator explicitly:

```cpp
vector<int>::iterator it;
```

Traverse from `begin()` to `end()`.

The purpose of this part is to practice understanding that an iterator refers to a position in the vector rather than directly representing an integer index.

### Part E: Remove Elements

1. Use `pop_back()` to remove the final quantity.
2. Use `erase()` to remove the element currently at index `1`.
3. Print the remaining values and the new vector size.

Expected remaining values:

```text
13 16 10
```

Expected size:

```text
3
```

### Part F: Check Whether the Vector Is Empty

Use `empty()` to determine whether the vector contains any elements.

Print one of the following messages:

```text
The inventory vector is empty.
```

or

```text
The inventory vector is not empty.
```

For the required program, the vector should not be empty at this point.

### Reflection Questions

1. Why is `quantities.size()` better than hard-coding `5` as the loop limit?
2. What is the difference between these two loops?

   ```cpp
   for (int quantity : quantities)
   ```

   ```cpp
   for (int &quantity : quantities)
   ```

3. Why is a `const` reference useful when you only want to read vector elements?
4. What happens to the vector size after `pop_back()` or `erase()`?
5. What does `empty()` return when `size()` is zero?

---

## Practice 6: Classroom Grade Table with a 2D Vector

Create a two-dimensional grade table using a `vector<vector<int>>`.

Each inner vector represents one student, and each integer represents one quiz score.

### Part A: Create the Grade Table

Initialize the following 2D vector:

```cpp
vector<vector<int>> grades = {
    {85, 90, 88},
    {72, 81, 79},
    {94, 91, 96}
};
```

Interpret the data as:

```text
Student 1: 85 90 88
Student 2: 72 81 79
Student 3: 94 91 96
```

### Part B: Access Individual Elements

Print the following values:

1. Student 1's second quiz score using `operator[]`.
2. Student 2's third quiz score using `at()`.
3. Student 3's first quiz score.

Remember that accessing one value requires two positions:

```cpp
grades[row][column]
```

or

```cpp
grades.at(row).at(column)
```

### Part C: Inspect the Dimensions

Use `size()` to print:

1. The number of students.
2. The number of quiz scores stored for Student 1.

Do not hard-code these values in the output calculations.

Expected result:

```text
Number of students: 3
Quizzes for Student 1: 3
```

### Part D: Print the Complete Table with Nested Loops

Use nested loops to print the complete grade table.

First, use index-based nested loops.

Example output:

```text
Student 1: 85 90 88
Student 2: 72 81 79
Student 3: 94 91 96
```

The outer loop should traverse the students, and the inner loop should traverse the quiz scores for the current student.

### Part E: Traverse with `auto` and References

Print the grade table a second time using nested range-based loops.

Use a `const` reference for each row and each score so the program does not copy the inner vectors unnecessarily:

```cpp
for (const auto &studentGrades : grades) {
    for (const int &score : studentGrades) {
        // Print score.
    }
}
```

### Part F: Update a Score

Student 2's first quiz score was entered incorrectly.

Change it from:

```text
72
```

to:

```text
77
```

Then print Student 2's updated scores.

Expected result:

```text
Student 2: 77 81 79
```

### Part G: Calculate Each Student's Average

Use nested loops to calculate and print the average quiz score for each student.

Example format:

```text
Student 1 average: 87.67
Student 2 average: 79.00
Student 3 average: 93.67
```

Your calculation should use the size of each inner vector rather than assuming that every row contains exactly three values.

### Reflection Questions

1. In `vector<vector<int>>`, what type of object is stored in the outer vector?
2. Why are two indices needed to access a single quiz score?
3. What does `grades.size()` represent?
4. What does `grades[0].size()` represent?
5. Why might `const auto &studentGrades` be preferable to `auto studentGrades` when traversing a 2D vector?
---

## Submission Requirements

Submit the following four files:

```text
practice1.cpp
practice2.cpp
practice3.cpp
practice4.cpp
practice5.cpp
practice6.cpp
```

Each program must:

- Compile without warnings or errors.
- Use meaningful variable and function names.
- Include short comments explaining important decisions.
- Produce clearly labeled output.
- Avoid global variables.

## Topic Coverage After Practices 1–6

The complete assignment now provides practice with:

- Vector declaration and initialization
- `push_back()`
- `insert()` and `begin()`
- `operator[]`
- `at()` and `out_of_range`
- Updating existing elements
- `size()`
- Index-based traversal
- Range-based traversal
- References and `const` references
- Iterator-based traversal
- `pop_back()`
- `erase()`
- `empty()`
- Vectors of objects
- Vectors of pointers
- Dynamic allocation and `delete`
- Two-dimensional `vector<vector<T>>`
- Nested traversal of multidimensional vectors
## Grading Rubric
- To be continued...

## Optional Challenge

Write the following function template:

```cpp
template <typename T>
void showElement(const vector<T>* values, int index);
```

The function should safely display the element at the requested index using `at()`.

Test it with:

- `vector<int>`
- `vector<string>`

Explain why the same function works with both vector types.

---
