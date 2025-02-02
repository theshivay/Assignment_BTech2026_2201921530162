# 101. Symmetric Tree - Leetcode

## Problem Statement
Given the root of a binary tree, check whether it is symmetric around its center.

### Example:
**Input:**
```
    1
   / \
  2   2
 / \ / \
3  4 4  3
```
**Output:** `true`

**Input:**
```
    1
   / \
  2   2
   \   \
   3    3
```
**Output:** `false`

---

## Platform
Solved on **Leetcode**: [Symmetric Tree](https://leetcode.com/problems/symmetric-tree/)

---

## Approach

### Recursive Approach
**Algorithm:**
1. Define a helper function `Symmetric` to compare two subtrees.
2. If both subtrees are `NULL`, return `true`.
3. If one subtree is `NULL` or values do not match, return `false`.
4. Recursively check left subtree of one with right subtree of the other and vice versa.

**Code:**
```cpp
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void Symmetric(TreeNode* root1, TreeNode* root2, bool &res) {
        if (root1 == NULL && root2 == NULL) {
            return;
        }
        if (root1 == NULL || root2 == NULL || root1->val != root2->val) {
            res = false;
            return;
        }
        Symmetric(root1->left, root2->right, res);
        Symmetric(root1->right, root2->left, res);
    }

    bool isSymmetric(TreeNode* root) {
        bool res = true;
        Symmetric(root->left, root->right, res);
        return res;
    }
};
```

**Time Complexity:** O(n) (Traversing each node once)  
**Space Complexity:** O(h) (Recursive call stack, where `h` is tree height)

---
###

# 121. Best Time to Buy and Sell Stock - Leetcode

## Problem Statement
You are given an array `prices` where `prices[i]` is the price of a given stock on the `i`th day. You want to maximize your profit by choosing a single day to buy one stock and a different day to sell it in the future.

### Example:
**Input:**
```
prices = [7,1,5,3,6,4]
```
**Output:** `5`

**Explanation:** Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6 - 1 = 5.

---

## Platform
Solved on **Leetcode**: [Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)

---

## Approach

### Greedy Approach
**Algorithm:**
1. Initialize `minValue` as the first day's price.
2. Iterate through `prices`, keeping track of the minimum price encountered.
3. Compute potential profit at each step and update `ans` if it's the highest seen so far.
4. Return the maximum profit.

**Code:**
```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int minValue = prices[0];
        for(int i = 1; i < prices.size(); i++) {
            int tmpSum = prices[i] - minValue;
            if(tmpSum > ans)
                ans = tmpSum;
            if(prices[i] < minValue)
                minValue = prices[i];
        }
        return ans;
    }
};
```

**Time Complexity:** O(n) (Single pass through the array)  
**Space Complexity:** O(1) (Constant extra space used)

---
###
# 128. Longest Consecutive Sequence - Leetcode

## Problem Statement
Given an unsorted array of integers `nums`, return the length of the longest consecutive elements sequence.

### Example:
**Input:**
```
nums = [100, 4, 200, 1, 3, 2]
```
**Output:** `4`

**Explanation:** The longest consecutive elements sequence is `[1, 2, 3, 4]`. Therefore, its length is `4`.

---

## Platform
Solved on **Leetcode**: [Longest Consecutive Sequence](https://leetcode.com/problems/longest-consecutive-sequence/)

---

## Approach

### Sorting Approach
**Algorithm:**
1. Sort the array.
2. Iterate through `nums`, tracking the length of consecutive sequences.
3. If the current element is consecutive from the previous, increase the sequence count.
4. Otherwise, reset the count.
5. Return the maximum sequence length.

**Code:**
```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        sort(nums.begin(), nums.end());
        int result = 1;
        int prev = 1;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] == nums[i - 1]) continue;
            else if(nums[i] == nums[i - 1] + 1) {
                prev++;
                result = max(result, prev);
            } else {
                prev = 1;
            }
        }
        return result;
    }
};
```

**Time Complexity:** O(n log n) (Due to sorting)
**Space Complexity:** O(1) (In-place sorting used)

---