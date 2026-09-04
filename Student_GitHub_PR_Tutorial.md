# Student Tutorial: Submitting and Updating Assignments with GitHub Pull Requests

## Purpose

This tutorial explains how to submit a programming assignment to your instructor using a GitHub Pull Request (PR), and how to update the same PR if the instructor requests changes.

The key idea is:

> **One assignment branch -> one Pull Request -> multiple updates if needed.**

Do **not** create a new Pull Request every time you fix your code.

---

## 1. Start from the Correct Repository

Make sure you are inside your local clone of the course repository.

Check your current location:

```bash
pwd
```

Check the repository status:

```bash
git status
```

Check available branches:

```bash
git branch
```

---

## 2. Update Your Local `main` Branch

Before starting a new assignment, switch to `main` and update it.

```bash
git switch main
```

Then:

```bash
git pull origin main
```

This helps ensure that your assignment branch starts from the newest version of the course repository.

---

## 3. Create an Assignment Branch

Create a separate branch for the assignment.

For example, for Chapter 1:

```bash
git switch -c chap1
```

You can verify your current branch with:

```bash
git branch
```

You should see something similar to:

```text
* chap1
  main
```

The `*` indicates your current branch.

---

## 4. Complete Your Assignment

Create or modify the required files.

For example:

```text
assign-stu.cpp
```

Before committing, check what changed:

```bash
git status
```

You may also inspect the changes with:

```bash
git diff
```

Compile and test your program before submitting it.

For example:

```bash
g++ assign-stu.cpp -o assign-stu
./assign-stu
```

Use the compile command required by your instructor if it is different.

---

## 5. Stage and Commit Your Work

Add your assignment files:

```bash
git add .
```

Then commit them:

```bash
git commit -m "Complete Chapter 1 assignment"
```

Check the commit:

```bash
git log --oneline -5
```

---

## 6. Push the Assignment Branch to GitHub

The first time you push the branch, use:

```bash
git push -u origin chap1
```

After this first push, later updates can normally use:

```bash
git push
```

---

## 7. Create the Pull Request on GitHub

Open the course repository on GitHub.

GitHub will usually show a button such as:

```text
Compare & pull request
```

Create a Pull Request from your assignment branch into the instructor's `main` branch.

Conceptually, GitHub may show something like:

```text
student-username:chap1 -> instructor-repository:main
```

Add a clear title, such as:

```text
Chapter 1 Assignment Submission
```

You may also add a short comment, for example:

```text
Assignment completed and ready for review.
```

Then create the Pull Request.

---

## 8. Understand the PR Number

GitHub assigns every Pull Request a number.

For example:

```text
Chapter 1 Assignment Submission #12
```

In this example, the PR number is:

```text
12
```

You can also find it in the URL:

```text
https://github.com/.../pull/12
```

The instructor can use this PR number to review your submission locally.

---

# If the Instructor Requests Changes

The instructor may review your Pull Request and select **Request changes**.

For example, the instructor may write:

```text
Please correct the vector access and fix the memory leak.
```

This does **not** mean you should create another Pull Request.

You should update the **same assignment branch**.

---

## 9. Switch Back to the Same Assignment Branch

For example:

```bash
git switch chap1
```

Check:

```bash
git status
```

---

## 10. Modify and Test Your Code

Make the corrections requested by the instructor.

Then compile and test again.

For example:

```bash
g++ assign-stu.cpp -o assign-stu
./assign-stu
```

Check your changes:

```bash
git diff
```

---

## 11. Commit the Corrections

Stage the updated files:

```bash
git add .
```

Commit them:

```bash
git commit -m "Address instructor review comments"
```

Then verify:

```bash
git log --oneline -5
```

---

## 12. Push the Updated Branch

Push the same branch again:

```bash
git push
```

Because the Pull Request is connected to the `chap1` branch, GitHub automatically adds the new commit to the **existing Pull Request**.

You do **not** need to create a second Pull Request.

The PR history might now look like:

```text
A -- Original assignment submission
B -- Fix instructor review comments
```

Both commits are part of the same PR.

---

## 13. Optional: Leave a Reply for the Instructor

After pushing the corrections, you may leave a comment in the Pull Request such as:

```text
I addressed the requested changes and pushed the updated code for review.
```

This tells the instructor that the assignment is ready to be reviewed again.

---

# Recommended Student Workflow

For a new assignment:

```bash
git switch main
git pull origin main

git switch -c chap1

# Complete and test assignment

git status
git add .
git commit -m "Complete Chapter 1 assignment"
git push -u origin chap1
```

Then create the Pull Request on GitHub.

If changes are requested later:

```bash
git switch chap1

# Modify and test code

git add .
git commit -m "Address instructor review comments"
git push
```

The original Pull Request updates automatically.

---

# Common Mistakes to Avoid

### Mistake 1: Working directly on `main`

Do not complete assignments directly on `main` unless your instructor specifically tells you to.

Use a separate assignment branch:

```bash
git switch -c chap1
```

### Mistake 2: Creating a new PR after every correction

Do not create another Pull Request after the instructor requests changes.

Continue using the same branch and run:

```bash
git push
```

### Mistake 3: Forgetting to commit before pushing

If you changed code but did not commit it, `git push` will not send those changes.

Use:

```bash
git add .
git commit -m "Describe the changes"
git push
```

### Mistake 4: Pushing corrections to the wrong branch

Before committing, check:

```bash
git branch
```

Make sure the assignment branch has `*` next to it.

### Mistake 5: Not testing before submission

Always compile and run your program before pushing your final commit.

---

# Important Rule

For each assignment, remember:

```text
Assignment branch
      |
      v
Pull Request
      |
      +--> Instructor reviews
      |
      +--> Student pushes corrections to SAME branch
      |
      +--> SAME Pull Request automatically updates
      |
      +--> Instructor reviews again
```

Do not create a new Pull Request unless your instructor explicitly asks you to do so.
