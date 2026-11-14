# Contributing to Personal Expense Tracker

This document describes how the project was developed collaboratively, including
individual contributions, branch usage, pull requests, code reviews, and merge
conflict resolution.

**Repository:** [dhruvnailwal/personal-expense-tracker](https://github.com/dhruvnailwal/personal-expense-tracker)

## Project Members

| Member | Main responsibility |
|---|---|
| **Dhruv Nailwal** | Repository setup, core tracker logic, delete expense, income/budget tracking |
| **Vanshika Goyal** | Case-insensitive search, expense sorting, testing, documentation |

Both members contributed to the shared features, menu handling, input validation,
and final integration.

## Individual Contributions

### Dhruv Nailwal

- Initialized the Git repository and configured the local Git identity.
- Created the `.gitignore` file to exclude build artifacts and editor files.
- Published the project to a public GitHub repository.
- Invited Vanshika Goyal as a collaborator.
- Implemented the **delete expense** feature by ID.
- Implemented the **income and budget tracking** feature.
- Implemented the **budget status report** with a remaining-balance calculation
  and an over-budget warning.
- Created and worked on the `feature-member1` branch.
- Created the `conflict-member1` branch for the merge-conflict demonstration.
- Reviewed Vanshika Goyal's pull request and approved it after testing.
- Contributed to the README documentation.

### Vanshika Goyal

- Accepted the GitHub collaborator invitation and cloned the repository.
- Configured Git locally for the cloned repository.
- Implemented **case-insensitive expense search**, including partial-name matching.
- Implemented **expense sorting** by amount and date in ascending or descending order.
- Added the sorting menu and handled the associated user input.
- Tested input validation, search, sorting, display, and report behaviour.
- Created and worked on the `feature-member2` branch.
- Created the `conflict-member2` branch and resolved the merge conflict.
- Reviewed Dhruv Nailwal's pull request and approved it after testing.
- Contributed to the README documentation.

## Commit Contributions

Each member made at least four meaningful commits on their feature branch.

### Dhruv Nailwal — `feature-member1`

```text
feat: add delete expense method
feat: add delete expense menu option
feat: add income and budget tracking methods
feat: add budget menu and status reporting
```

### Vanshika Goyal — `feature-member2`

```text
feat: make expense search case-insensitive
feat: add expense sorting by amount
feat: add expense sorting by date
feat: add sorting menu and input handling
```

## Branching Strategy

| Branch | Owner | Purpose |
|---|---|---|
| `main` | Both | Stable code containing reviewed and merged features |
| `feature-member1` | Dhruv Nailwal | Delete expense and budget/income tracking |
| `feature-member2` | Vanshika Goyal | Case-insensitive search and expense sorting |
| `conflict-member1` | Dhruv Nailwal | First side of the merge-conflict demonstration |
| `conflict-member2` | Vanshika Goyal | Second side of the merge-conflict demonstration |

Feature work was never committed directly to `main`. Each member created a branch
from the latest `main`:

```bash
git checkout main
git pull origin main
git checkout -b feature-member1
```

After a feature branch was approved and merged, it was deleted. The other member
then updated their local `main` before continuing work.

## Pull Requests

Both members created one pull request for their feature branch.

| Pull Request | Source branch | Author | Reviewer | Purpose |
|---|---|---|---|---|
| PR 1 | `feature-member1` | Dhruv Nailwal | Vanshika Goyal | Delete expense and budget tracking |
| PR 2 | `feature-member2` | Vanshika Goyal | Dhruv Nailwal | Case-insensitive search and expense sorting |

### Pull Request Process

1. Push the feature branch to GitHub:

   ```bash
   git push -u origin feature-member1
   ```

2. Open the repository on GitHub and select **Pull requests** → **New pull request**.
3. Set **base** to `main` and **compare** to the feature branch.
4. Add a descriptive title and explain what changed.
5. Mention the tests performed, such as building with `g++` and running each feature.
6. Request a review from the other member.
7. Merge only after the review is approved.

### Pull Request Descriptions

**PR 1 — Delete expense and budget tracking**

- Added `deleteexp(int id)` to remove an expense by ID.
- Added `setincome`, `setbudget`, and `showbudgetstatus`.
- Added menu options for deleting an expense and managing the budget.
- Verified that invalid IDs and over-budget values produce clear messages.

**PR 2 — Case-insensitive search and expense sorting**

- Updated `searchexp` to compare lowercase names.
- Added partial-name matching.
- Added `sortexp` with amount and date sorting options.
- Added menu handling and validation for the sort option.
- Verified that search and sorting work with multiple records.

## Code Reviews

Each pull request was reviewed by the other member before merging.

### Review Process

1. Open the pull request and select **Files changed**.
2. Read every changed file.
3. Add at least one specific line comment.
4. Check that the project builds successfully.
5. Run the new feature and verify the expected output.
6. Select **Review changes** → **Approve** → **Submit review**.

### Review Checklist

- [ ] The project compiles without errors.
- [ ] The new feature works as described in the pull request.
- [ ] Existing features still work.
- [ ] Invalid input is handled safely.
- [ ] Expense IDs and dates are validated.
- [ ] Naming and formatting are consistent with the existing code.
- [ ] Menu numbering is consistent.
- [ ] No build artifacts such as `.exe` files are committed.
- [ ] Documentation is updated when required.

### Review Outcomes

| Pull Request | Reviewer | Outcome |
|---|---|---|
| PR 1 | Vanshika Goyal | Approved after testing delete and budget features |
| PR 2 | Dhruv Nailwal | Approved after testing search and sorting features |

If a reviewer requests changes, the author pushes additional commits to the same
feature branch. The reviewer then checks the updated pull request before approving.

## Merging

After approval, the pull request was merged into `main` using the GitHub
**Merge pull request** button. Both members then updated their local copies:

```bash
git checkout main
git pull origin main
```

The merged feature branches were deleted locally and remotely.

## Merge Conflict Resolution

A controlled merge conflict was created using `version.txt`.

1. Both members changed the same line in `version.txt` on separate branches.
2. The first branch was merged into `main`.
3. The second branch was updated with `main` and produced a conflict:

   ```bash
   git checkout conflict-member2
   git merge main
   ```

4. Git displayed conflict markers in `version.txt`.
5. Both changes were combined and all conflict markers were removed.
6. The resolved file was staged and committed:

   ```bash
   git add version.txt
   git commit -m "fix: resolve merge conflict in version.txt"
   git push origin conflict-member2
   ```

7. The second pull request was merged after the conflict was resolved.

The final resolved line is:

```text
Version: 1.2 (Member 1 + Member 2 -- conflict resolved)
```

Screenshots of the conflict and its resolution are stored in `docs/screenshots/`
and referenced in `README.md`.

## Commit Message Guidelines

Use clear messages that describe the purpose of the change:

```text
feat: add delete expense method
feat: add budget status report
fix: resolve merge conflict in version.txt
docs: update installation instructions
refactor: simplify expense display
test: verify sorting and search behaviour
```

Avoid vague messages such as `update`, `changes`, or `final`.

## Local Build and Test

Build from the project root:

```powershell
g++ -std=c++11 -Wall -Wextra -Iinclude src/Date.cpp src/PersonalExpenseTracker.cpp src/main.cpp -o expense_tracker.exe
```

Run on Windows:

```powershell
.\expense_tracker.exe
```

Run on Linux or macOS:

```bash
./expense_tracker
```

Before approving a pull request, both the build command and the affected features
should be tested manually.

## Documentation

Update `README.md` whenever a feature, build step, or project structure changes.
Keep this `CONTRIBUTING.md` file updated when branches, pull requests, or review
responsibilities change.
