# 50. Pow(x, n) - Leetcode

## Problem Statement
Implement `pow(x, n)`, which calculates `x` raised to the power `n` (i.e., `x^n`).

### Example:
**Input:** `x = 2.00000, n = 10`  
**Output:** `1024.00000`

---

## Platform
Solved on **Leetcode**: [Pow(x, n)](https://leetcode.com/problems/powx-n/)

---

## Approach

### Recursive Approach
**Algorithm:**
1. Base Case: If `n == 0`, return `1`. If `x == 1`, return `1`.
2. Recursively calculate `myPow(x, n/2)`, store the result.
3. Multiply the stored result by itself to handle even power cases.
4. If `n` is odd, multiply by `x` (or `1/x` if `n` is negative).

**Code:**
```cpp
class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0 || x == 1)
            return 1;
        
        double val = myPow(x, n / 2);
        val *= val;
        
        if (n % 2 == 0)
            return val;
        
        return (n < 0) ? val * (1 / x) : val * x;
    }
};
```

**Time Complexity:** O(log n) (Recursive calls reduce `n` exponentially)  
**Space Complexity:** O(log n) (Recursive call stack)

---
###
# 35. Search Insert Position - Leetcode 

## Problem Statement
Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be inserted in order.

### Example:
**Input:** `nums = [1,3,5,6], target = 5`  
**Output:** `2`

---

## Platform
Solved on **Leetcode**: [Search Insert Position](https://leetcode.com/problems/search-insert-position/)

---

## Approach

### Iterative Approach
**Algorithm:**
1. Iterate through the array.
2. If `nums[i] == target`, return `i`.
3. If `nums[i] > target`, return `i`.
4. If `target` is greater than the last element, return `nums.size()`.

**Code:**
```cpp
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                return i;
            }
            if (nums[i] > target) {
                return i;
            }
            if (nums[nums.size() - 1] < target) {
                return nums.size();
            }
        }
        return 0;
    }
};
```

**Time Complexity:** O(n) (Iterating through the array)  
**Space Complexity:** O(1) (Constant extra space)

---
###
# 54. Spiral Matrix - Leetcode

## Problem Statement
Given an `m x n` matrix, return all elements of the matrix in spiral order.

### Example:
**Input:** `matrix = [[1,2,3],[4,5,6],[7,8,9]]`  
**Output:** `[1,2,3,6,9,8,7,4,5]`

---

## Platform
Solved on **Leetcode**: [Spiral Matrix](https://leetcode.com/problems/spiral-matrix/)

---

## Approach

### Simulation Approach
**Algorithm:**
1. Initialize `left`, `right`, `top`, and `bottom` pointers.
2. Traverse from `left` to `right` and increment `top`.
3. Traverse from `top` to `bottom` and decrement `right`.
4. Traverse from `right` to `left` and decrement `bottom` (if still valid).
5. Traverse from `bottom` to `top` and increment `left` (if still valid).
6. Repeat the process until all elements are visited.

**Code:**
```cpp
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int m = matrix[0].size();
        int n = matrix.size();
        int total = m * n;
        int count = 0;

        int left = 0, right = m - 1;
        int top = 0, bottom = n - 1;
        while (count < total) {
            // left -> right
            for (int i = left; i <= right; i++) {
                result.push_back(matrix[top][i]);
                count++;
            }
            top++;
            // top -> bottom
            for (int i = top; i <= bottom; i++) {
                result.push_back(matrix[i][right]);
                count++;
            }
            right--;
            if (top <= bottom) {
                // right -> left
                for (int i = right; i >= left; i--) {
                    result.push_back(matrix[bottom][i]);
                    count++;
                }
                bottom--;
            }
            if (left <= right) {
                // bottom -> top
                for (int i = bottom; i >= top; i--) {
                    result.push_back(matrix[i][left]);
                    count++;
                }
                left++;
            }
        }
        return result;
    }
};
```

**Time Complexity:** O(m * n) (Each element is visited once)  
**Space Complexity:** O(1) (Only output storage is used)

---

