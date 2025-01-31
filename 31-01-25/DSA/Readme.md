# 14. Longest Common Prefix - Leetcode

## Problem Statement
Given an array of strings `strs`, write a function to find the longest common prefix among all the strings.
If there is no common prefix, return an empty string `""`.

### Example:
**Input:** `strs = ["flower","flow","flight"]`  
**Output:** `"fl"`

---

## Platform
Solved on **Leetcode**: [Longest Common Prefix](https://leetcode.com/problems/longest-common-prefix/)

---

## Approach

### Sorting and Comparison Approach
**Algorithm:**
1. Sort the given array of strings.
2. The common prefix must be between the first and last string in the sorted list.
3. Compare characters of both strings one by one and append matching characters to the result.
4. Stop when a mismatch is found.

**Code:**
```cpp
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        int a = strs.size();
        string n = strs[0], m = strs[a-1], ans = "";
        for(int i = 0; i < n.size(); i++) {
            if(n[i] == m[i]) {
                ans += n[i];
            } else {
                break;
            }
        }
        return ans;
    }
};
```

**Time Complexity:** O(n log n) (Sorting takes O(n log n), and comparison takes O(m), where m is the length of the shortest string)  
**Space Complexity:** O(1) (No extra space used apart from the output string)

---
###

# 26. Remove Duplicates from Sorted Array - Leetcode

## Problem Statement
Given an integer array `nums` sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. Return the new length of the modified array.

### Example:
**Input:** `nums = [1,1,2]`  
**Output:** `2, nums = [1,2,_]`  

---

## Platform
Solved on **Leetcode**: [Remove Duplicates from Sorted Array](https://leetcode.com/problems/remove-duplicates-from-sorted-array/)

---

## Approach

### Two-Pointer Approach
**Algorithm:**
1. Use two pointers: `k` to track the position of unique elements and `i` to iterate over the array.
2. Start iterating from index `1`.
3. If the current element `nums[i]` is different from the previous element `nums[i-1]`, increment `k` and assign `nums[k] = nums[i]`.
4. Finally, return `k+1` as the count of unique elements.

**Code:**
```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] != nums[i - 1]) {
                nums[++k] = nums[i];
            }
        }
        return k + 1;
    }
};
```

**Time Complexity:** O(n) (Single pass through the array)  
**Space Complexity:** O(1) (In-place modification)

---
###
# 189. Rotate Array - Leetcode

## Problem Statement
Given an integer array `nums`, rotate the array to the right by `k` steps, where `k` is non-negative.

### Example:
**Input:** `nums = [1,2,3,4,5,6,7]`, `k = 3`  
**Output:** `[5,6,7,1,2,3,4]`

---

## Platform
Solved on **Leetcode**: [Rotate Array](https://leetcode.com/problems/rotate-array/)

---

## Approach

### Using Extra Array
**Algorithm:**
1. Create a temporary array of the same size as `nums`.
2. Store elements in their new rotated position using `(i + k) % n` formula.
3. Copy the temporary array back to `nums`.

**Code:**
```cpp
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> temp(nums.size());
        for (int i = 0; i < n; i++) {
            temp[(i + k) % n] = nums[i];
        }
        nums = temp;
    }
};
```

**Time Complexity:** O(n) (Iterating through the array once)  
**Space Complexity:** O(n) (Using extra array for storage)

---
