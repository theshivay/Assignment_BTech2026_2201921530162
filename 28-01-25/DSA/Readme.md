# 2658. Maximum Number of Fish in a Grid - Leetcode 

## Problem Statement
You are given a grid where each cell contains a non-negative integer representing the number of fish in that cell. You can move up, down, left, or right, and you can only move to cells containing a positive number of fish. Find the maximum number of fish you can collect by traversing connected cells.

### Example
**Input:**
```
grid = [
  [1, 0, 0],
  [0, 0, 0],
  [0, 0, 1]
]
```
**Output:**
```
1
```

---

## Platform
Solved on **Leetcode**: [Maximum Number of Fish in a Grid](https://leetcode.com/problems/maximum-number-of-fish-in-a-grid/)

---

## Approach

### Depth-First Search (DFS) Approach
**Algorithm:**
1. Use DFS to explore connected cells in the grid.
2. For each unvisited cell containing fish, calculate the total fish collected from all connected cells.
3. Maintain a visited array to avoid revisiting cells.
4. Update the maximum fish collected after each DFS.

**Code:**
```cpp
class Solution {
public:
    int dfs(vector<vector<int>>& grid, int i, int j, int m, int n, vector<vector<bool>>& vis) {
        // Base case: Out of bounds or invalid cell
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0 || vis[i][j]) {
            return 0;
        }

        // Mark the cell as visited
        vis[i][j] = true;

        // Start with the current cell's fish count
        int total = grid[i][j];

        // Explore all 4 directions
        total += dfs(grid, i - 1, j, m, n, vis); // Up
        total += dfs(grid, i + 1, j, m, n, vis); // Down
        total += dfs(grid, i, j - 1, m, n, vis); // Left
        total += dfs(grid, i, j + 1, m, n, vis); // Right

        return total;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int ans = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> vis(m, vector<bool>(n, false)); // Visited array

        // Iterate over all cells in the grid
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0 && !vis[i][j]) { // Start DFS for each new component
                    ans = max(ans, dfs(grid, i, j, m, n, vis));
                }
            }
        }

        return ans;
    }
};
```

**Time Complexity:** O(m * n) (Each cell is visited once)  
**Space Complexity:** O(m * n) (Visited array and recursive stack)

---
### 

# 7. Reverse Integer - Leetcode

## Problem Statement
Given a signed 32-bit integer `x`, return `x` with its digits reversed. If reversing `x` causes the value to exceed the signed 32-bit integer range `[-2^31, 2^31 - 1]`, return `0`.

**Note:** The environment does not allow storing 64-bit integers.

### Example
**Input:**
```
x = 123
```
**Output:**
```
321
```

**Input:**
```
x = -123
```
**Output:**
```
-321
```

**Input:**
```
x = 1534236469
```
**Output:**
```
0
```

---

## Platform
Solved on **Leetcode**: [Reverse Integer](https://leetcode.com/problems/reverse-integer/)

---

## Approach

### Iterative Approach
**Algorithm:**
1. Initialize `result` to `0`.
2. While `x` is not `0`:
   - Extract the last digit of `x` using `x % 10`.
   - Append the digit to `result` by updating `result = result * 10 + digit`.
   - Check for overflow or underflow:
     - If `result > INT_MAX` or `result < INT_MIN`, return `0`.
   - Remove the last digit from `x` using integer division (`x /= 10`).
3. Return `result`.

**Code:**
```cpp
class Solution {
public:
    int reverse(int x) {
        long long result = 0;
        while (x != 0) {
            result = result * 10 + (x % 10);
            if (result > INT_MAX || result < INT_MIN) return 0;
            x /= 10;
        }
        return result;
    }
};
```

**Time Complexity:** O(log(x)) (Proportional to the number of digits in `x`)  
**Space Complexity:** O(1) (In-place computation)

---
###

# 73. Set Matrix Zeroes - Leetcode

## Problem Statement
Given an `m x n` integer matrix, if an element is `0`, set its entire row and column to `0`. Do it in-place.

### Example
**Input:**
```
matrix = [
  [1, 1, 1],
  [1, 0, 1],
  [1, 1, 1]
]
```
**Output:**
```
matrix = [
  [1, 0, 1],
  [0, 0, 0],
  [1, 0, 1]
]
```

**Input:**
```
matrix = [
  [0, 1, 2, 0],
  [3, 4, 5, 2],
  [1, 3, 1, 5]
]
```
**Output:**
```
matrix = [
  [0, 0, 0, 0],
  [0, 4, 5, 0],
  [0, 3, 1, 0]
]
```

---

## Platform
Solved on **Leetcode**: [Set Matrix Zeroes](https://leetcode.com/problems/set-matrix-zeroes/)

---

## Approach

### Using Two Sets
**Algorithm:**
1. Use two sets to store the rows and columns that need to be set to zero.
2. Traverse the matrix and identify the rows and columns containing zeros.
3. Iterate over the identified rows and set all elements in those rows to zero.
4. Iterate over the identified columns and set all elements in those columns to zero.

**Code:**
```cpp
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> zeroRows;
        set<int> zeroCols;

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (matrix[i][j] == 0) {
                    zeroRows.insert(i);
                    zeroCols.insert(j);
                }
            }
        }

        for (int row : zeroRows) {
            for (int j = 0; j < matrix[0].size(); j++) {
                matrix[row][j] = 0;
            }
        }

        for (int col : zeroCols) {
            for (int i = 0; i < matrix.size(); i++) {
                matrix[i][col] = 0;
            }
        }
    }
};
```

**Time Complexity:** O(m * n) (Two passes over the matrix)  
**Space Complexity:** O(m + n) (Using two sets to track rows and columns)

---




