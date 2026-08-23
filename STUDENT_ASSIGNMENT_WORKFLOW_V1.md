# Student Assignment Workflow

## Public Fork and Pull Request Review

This guide explains how to receive, complete, and submit every coding assignment in this course.

You will:

1. Fork the instructor's course repository once.
2. Keep your fork synchronized with the instructor's repository.
3. Create a new branch for every assignment.
4. Complete and test your code on that branch.
5. Open a pull request for the instructor to review.
6. Correct the same branch when changes are requested.
7. Keep the completed branch after the instructor closes the pull request.

> [!IMPORTANT]
> The instructor reviews your pull request but does **not** merge it. Your completed code remains in the assignment branch of your fork.

---

# 1. Understand the Repository Names

This workflow uses two copies of the course repository.

```text
Instructor repository
INSTRUCTOR-USERNAME/dsa-cpp-course
        │
        │ You fork it once
        ▼
Your repository
STUDENT-USERNAME/dsa-cpp-course
```

In Git commands, the repositories have these names:

| Name | Meaning |
|---|---|
| `origin` | Your fork, where you push your assignment branches |
| `upstream` | The instructor's repository, where new course material is published |
| `main` | The clean courseware branch; do not complete assignments here |
| Assignment branch | The branch where you complete one assignment |

---

# 2. One-Time Setup

Complete this section only once, before your first assignment.

## Step 1: Fork the Course Repository

1. Sign in to GitHub.
2. Open the instructor's course repository:

   ```text
   https://github.com/INSTRUCTOR-USERNAME/dsa-cpp-course
   ```

3. Select **Fork** near the top-right corner.
4. Choose your personal GitHub account as the owner.
5. Keep the suggested repository name.
6. Select **Create fork**.

You now have your own copy:

```text
https://github.com/STUDENT-USERNAME/dsa-cpp-course
```

## Step 2: Clone Your Fork

Open Terminal and run:

```bash
git clone https://github.com/STUDENT-USERNAME/dsa-cpp-course.git
cd dsa-cpp-course
```

Replace `STUDENT-USERNAME` with your actual GitHub username.

## Step 3: Add the Instructor Repository

Your fork is automatically named `origin`. Add the instructor repository as `upstream`:

```bash
git remote add upstream \
https://github.com/INSTRUCTOR-USERNAME/dsa-cpp-course.git
```

Replace `INSTRUCTOR-USERNAME` with the instructor's GitHub username.

## Step 4: Verify the Setup

```bash
git remote -v
```

You should see both repositories:

```text
origin    https://github.com/STUDENT-USERNAME/dsa-cpp-course.git
upstream  https://github.com/INSTRUCTOR-USERNAME/dsa-cpp-course.git
```

If both appear, the one-time setup is complete.

---

# 3. The Assignment Workflow

Repeat this section for every assignment.

```text
Get new course material
        ↓
Create a clean assignment branch
        ↓
Write and test the program
        ↓
Commit and push the branch
        ↓
Open a pull request
        ↓
Respond to instructor feedback
        ↓
Instructor approves and closes the pull request
        ↓
Keep the completed branch
```

---

# 4. Step 1 — Get the Latest Course Material

Before starting an assignment, synchronize your local `main` branch with the instructor's `main` branch.

```bash
git switch main
git fetch upstream
git merge --ff-only upstream/main
git push origin main
```

What these commands do:

1. `git switch main` moves you to your clean courseware branch.
2. `git fetch upstream` downloads the instructor's newest chapters and assignments.
3. `git merge --ff-only upstream/main` safely updates your local `main`.
4. `git push origin main` updates `main` in your GitHub fork.

> [!WARNING]
> Never write assignment code directly on `main`. Your `main` branch must remain a clean copy of the instructor's courseware.

If Git reports that a fast-forward is impossible, stop and ask the instructor for help. Do not force-push or reset the branch unless the instructor guides you.

---

# 5. Step 2 — Create a New Assignment Branch

Create a separate branch for the current assignment.

Use this naming format:

```text
assignment-NN-short-name
```

Example for the vector assignment:

```bash
git fetch upstream
git switch -c assignment-01-vector-practice upstream/main
```

Other examples:

```text
assignment-02-linear-search
assignment-03-sorting-lab
assignment-04-string-analyzer
assignment-10-linked-list
```

Verify the current branch:

```bash
git branch --show-current
```

Expected output:

```text
assignment-01-vector-practice
```

> [!IMPORTANT]
> Always create a new assignment branch from `upstream/main`.

Do not create a new assignment branch from an old assignment branch.

Correct:

```bash
git switch -c assignment-02-linear-search upstream/main
```

Incorrect:

```bash
git switch assignment-01-vector-practice
git switch -c assignment-02-linear-search
```

The incorrect method causes old assignment code to appear in the new pull request.

---

# 6. Step 3 — Complete the Assignment

Read the complete assignment instructions before writing code.

For the vector assignment, the required files may be:

```text
practice1.cpp
practice2.cpp
practice3.cpp
practice4.cpp
```

Save the files in the directory specified by the instructor.

While working:

- Follow the assignment requirements.
- Use only the C++ features currently allowed.
- Use meaningful variable, function, and class names.
- Keep each program focused and readable.
- Avoid global variables unless explicitly permitted.
- Add short comments for important decisions.
- Do not copy another student's solution.

Check your progress:

```bash
git status
```

---

# 7. Step 4 — Compile and Test

Compile every required program before submitting it.

Example:

```bash
g++ -std=c++17 -Wall -Wextra -Wpedantic practice1.cpp -o practice1
./practice1
```

Repeat for the remaining programs:

```bash
g++ -std=c++17 -Wall -Wextra -Wpedantic practice2.cpp -o practice2
g++ -std=c++17 -Wall -Wextra -Wpedantic practice3.cpp -o practice3
g++ -std=c++17 -Wall -Wextra -Wpedantic practice4.cpp -o practice4
```

Fix compilation errors and review every warning.

Test relevant cases:

- Normal input
- Minimum reasonable input
- Maximum reasonable input
- Invalid input
- Empty input when applicable
- Duplicate values
- Values not found
- Out-of-range indexes
- Empty containers

Do not commit compiled programs such as `practice1`, `practice1.exe`, or `.out` files.

---

# 8. Step 5 — Commit Your Work

Make small, meaningful commits as you complete parts of the assignment.

Check the changed files:

```bash
git status
```

Add the appropriate source files:

```bash
git add practice1.cpp
```

Commit the change:

```bash
git commit -m "Complete quiz score organizer"
```

Continue with additional meaningful commits:

```bash
git add practice2.cpp
git commit -m "Implement safe product lookup"

git add practice3.cpp
git commit -m "Add student record vector"

git add practice4.cpp
git commit -m "Complete pointer-based device inventory"
```

Good commit messages describe what changed:

```text
Create Student class and constructor
Add vector element bounds checking
Handle invalid product index
Release dynamically allocated devices
Add edge-case tests
```

Avoid unclear messages:

```text
work
changes
update
final
stuff
```

---

# 9. Step 6 — Push the Assignment Branch

For the first push of the branch:

```bash
git push -u origin assignment-01-vector-practice
```

After the first push, later updates require only:

```bash
git push
```

Your assignment branch is now available in your GitHub fork.

---

# 10. Step 7 — Open the Pull Request

The pull request must compare your assignment branch with the instructor's `main` branch.

## On GitHub

1. Open the instructor's original course repository.
2. Select **Pull requests**.
3. Select **New pull request**.
4. Select **compare across forks** if it appears.
5. Configure the pull request:

   ```text
   Base repository: INSTRUCTOR-USERNAME/dsa-cpp-course
   Base branch: main

   Head repository: STUDENT-USERNAME/dsa-cpp-course
   Compare branch: assignment-01-vector-practice
   ```

6. Review **Files changed** before submitting.
7. Confirm that only the current assignment appears.
8. Enter the pull request title:

   ```text
   [STUDENT-USERNAME] Chapter 01 — Vector Practice
   ```

9. Complete every section of the pull request description.
10. Select **Create pull request**.

> [!WARNING]
> Do not merge the pull request. It exists for instructor review only.

---

# 11. Pull Request Description

Use this format if GitHub does not fill in a template automatically:

```markdown
## Student

GitHub username: STUDENT-USERNAME

## Assignment

Chapter 01 — Vector Practice

## What I Implemented

Explain what you completed in your own words.

## Concepts Used

- `vector<T>`
- `push_back()`
- `insert()`
- `operator[]`
- `at()`

## Testing

Describe the normal, edge, and invalid cases tested.

## Questions or Difficulties

Describe anything that was confusing or difficult.

## Checklist

- [ ] My work is on a separate assignment branch.
- [ ] All required programs compile.
- [ ] I reviewed compiler warnings.
- [ ] I tested normal cases.
- [ ] I tested relevant edge cases.
- [ ] I removed compiled executables.
- [ ] I can explain my code.
```

---

# 12. Step 8 — Respond to Instructor Feedback

The instructor may:

- Leave comments
- Ask questions
- Suggest improvements
- Request changes
- Approve the assignment

If changes are requested, continue using the same assignment branch.

Move to the branch if necessary:

```bash
git switch assignment-01-vector-practice
```

Make the correction, compile, and test again.

Then commit and push:

```bash
git add practice2.cpp
git commit -m "Correct product index bounds checking"
git push
```

The existing pull request updates automatically.

Do not:

- Open a second pull request for the correction.
- Create another branch for the correction.
- Delete the original assignment branch.
- Resolve a review comment before addressing it.

Reply to the instructor's comments and briefly explain what you changed.

---

# 13. Step 9 — Assignment Completion

When the assignment is complete, the instructor will:

1. Approve the pull request.
2. Add a completion comment or label.
3. Close the pull request without merging it.

Closing without merging is intentional.

After the pull request closes:

- Your code remains in your assignment branch.
- Your commits remain available.
- The instructor's review remains available.
- The instructor's `main` branch remains free of student solutions.

> [!IMPORTANT]
> Keep the completed assignment branch. Do not delete it.

---

# 14. Starting the Next Assignment

Return to the clean courseware and repeat the workflow:

```bash
git switch main
git fetch upstream
git merge --ff-only upstream/main
git push origin main
```

Create a fresh branch from `upstream/main`:

```bash
git switch -c assignment-02-linear-search upstream/main
```

Do not continue from the previous assignment branch.

Your fork may eventually contain branches such as:

```text
main
assignment-01-vector-practice
assignment-02-linear-search
assignment-03-sorting-lab
assignment-04-string-analyzer
```

This is expected. Each branch stores one completed assignment.

---

# 15. Essential Rules

Follow these rules for every assignment:

1. Never complete assignments on `main`.
2. Always synchronize from `upstream/main` before starting.
3. Create one new branch for each assignment.
4. Always create the new branch from `upstream/main`.
5. Never create a new assignment branch from an old assignment branch.
6. Push assignment branches to your fork, named `origin`.
7. Open the pull request against the instructor's `main`.
8. Use the same branch and pull request for all corrections.
9. Never merge the review pull request.
10. Keep completed assignment branches after pull requests are closed.

---

# 16. Quick Command Reference

## One-Time Setup

```bash
git clone https://github.com/STUDENT-USERNAME/dsa-cpp-course.git
cd dsa-cpp-course

git remote add upstream \
https://github.com/INSTRUCTOR-USERNAME/dsa-cpp-course.git

git remote -v
```

## Start Every Assignment

```bash
git switch main
git fetch upstream
git merge --ff-only upstream/main
git push origin main

git switch -c assignment-NN-short-name upstream/main
```

## Save and Submit Work

```bash
git status
git add PATH-TO-ASSIGNMENT-FILES
git commit -m "Describe the completed work"
git push -u origin assignment-NN-short-name
```

## Submit Corrections

```bash
git switch assignment-NN-short-name
git add PATH-TO-CORRECTED-FILES
git commit -m "Describe the correction"
git push
```

---

# 17. Troubleshooting

## `upstream` Does Not Exist

Check the remotes:

```bash
git remote -v
```

If `upstream` is missing, add it:

```bash
git remote add upstream \
https://github.com/INSTRUCTOR-USERNAME/dsa-cpp-course.git
```

## New Course Material Is Missing

Update `main`:

```bash
git switch main
git fetch upstream
git merge --ff-only upstream/main
git push origin main
```

## The New Pull Request Contains an Old Assignment

You probably created the new branch from a previous assignment branch.

Stop working and tell the instructor. Create a clean branch from `upstream/main` using a new branch name:

```bash
git fetch upstream
git switch -c assignment-NN-clean-name upstream/main
```

Copy only the current assignment files into the clean branch, commit them, and open the pull request from the clean branch.

## Git Says the Fast-Forward Is Impossible

Your `main` branch may contain changes that do not exist in the instructor's `main`.

Stop and ask the instructor for help. Do not force-push, reset, or delete commits without guidance.

## The Pull Request Was Opened in the Wrong Repository

Close the incorrect pull request and create a new one with:

```text
Base repository: INSTRUCTOR-USERNAME/dsa-cpp-course
Base branch: main
```

## A Compiled Program Was Committed

Remove it from Git tracking while keeping the local file:

```bash
git rm --cached PROGRAM-NAME
git commit -m "Remove compiled program"
git push
```

Confirm that the relevant executable pattern is included in `.gitignore`.

---

# 18. Assignment Submission Checklist

Before opening a pull request:

- [ ] I synchronized the latest courseware.
- [ ] I created a new branch from `upstream/main`.
- [ ] I used the required branch name.
- [ ] I completed every assignment requirement.
- [ ] All required programs compile.
- [ ] I reviewed compiler warnings.
- [ ] I tested normal cases.
- [ ] I tested relevant edge cases.
- [ ] My commit messages describe the work.
- [ ] I pushed the assignment branch to my fork.
- [ ] The pull request targets the instructor's `main`.
- [ ] The pull request contains only the current assignment.
- [ ] I completed the pull request description.
- [ ] I did not commit executables or temporary files.
- [ ] I can explain my solution.

---

# 19. Privacy Reminder

The course repository, your fork, your assignment branches, pull requests, code, and review comments are public.

Never commit or post:

- Passwords
- Access tokens
- Private keys
- Student identification numbers
- Grades
- Personal or sensitive information

Contact the instructor immediately if sensitive information is accidentally published.
