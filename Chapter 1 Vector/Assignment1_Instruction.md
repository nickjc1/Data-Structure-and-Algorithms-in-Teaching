# C++ Assignment: Practicing `vector<T>`

## Learning Objectives

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

## Submission Requirements

Submit the following four files:

```text
practice1.cpp
practice2.cpp
practice3.cpp
practice4.cpp
```

Each program must:

- Compile without warnings or errors.
- Use meaningful variable and function names.
- Include short comments explaining important decisions.
- Produce clearly labeled output.
- Avoid global variables.

## Grading Rubric

| Area                                          |  Points |
| --------------------------------------------- | ------: |
| Correct vector declaration and initialization |      15 |
| Correct use of `push_back()` and `insert()`   |      20 |
| Correct use of `operator[]` and `at()`        |      20 |
| OOP design and encapsulation                  |      20 |
| Correct pointer and memory management         |      15 |
| Readability, output, and comments             |      10 |
| **Total**                                     | **100** |

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
