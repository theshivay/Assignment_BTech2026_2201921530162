# 1800. Maximum Ascending Subarray Sum - Leetcode

## Problem Statement
Given an array of positive integers `nums`, return the maximum sum of any ascending subarray in `nums`.

A subarray is defined as a contiguous sequence of numbers within an array. An ascending subarray is a subarray where each element is strictly greater than the preceding one.

## Coding Platform
Leetcode

## Approach & Solution Explanation
1. Initialize `result` with the first element of `nums`, as it represents the maximum sum found so far.
2. Use a `sum` variable to keep track of the current ascending subarray sum.
3. Iterate through `nums` from index `1` to `n-1`:
   - If `nums[i]` is greater than `nums[i-1]`, add `nums[i]` to `sum` (extending the ascending subarray).
   - Otherwise, reset `sum` to `nums[i]` (starting a new ascending subarray).
   - Update `result` with the maximum sum found.
4. Return `result`.

## Code Implementation
```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int result = nums[0];
        int sum = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i-1] < nums[i]) {
                sum += nums[i];
            } else {
                sum = nums[i];
            }
            result = max(result, sum);
        }
        return result;
    }
};
```

**Time Complexity:** O(n) (We traverse the array once, making this approach efficient)  
**Space Complexity:** O(1) (Constant space usage)

---
###
# 3105. Longest Strictly Increasing or Strictly Decreasing Subarray - Leetcode

## Problem Statement
Given an array `nums`, return the length of the longest contiguous subarray that is either strictly increasing or strictly decreasing.

### Example:
**Input:**
```
nums = [1, 4, 3, 2, 5, 6]
```
**Output:** 3

**Explanation:** The longest strictly increasing subarray is `[1, 4]` or `[5, 6]`, and the longest strictly decreasing subarray is `[4, 3, 2]`, with a length of 3.

---

## Platform
Solved on **Leetcode**: [Longest Strictly Increasing or Strictly Decreasing Subarray](https://leetcode.com/problems/longest-strictly-increasing-or-strictly-decreasing-subarray/)

---

## Approach

### Iterative Approach
**Algorithm:**
1. Initialize `res` to store the maximum subarray length.
2. Use two counters `low` and `high` to track increasing and decreasing subarrays.
3. Traverse the array, updating counters based on element comparison.
4. Reset counters when consecutive elements are equal.
5. Return the maximum length found.

**Code:**
```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int res = 1, low = 1, high = 1;
        for (int i = 1; i < nums.size(); i++){
            if (nums[i] > nums[i - 1]){
                high++;
                low = 1;
            }
            else if (nums[i] < nums[i - 1]){
                low++;
                high = 1;
            }
            else{
                low = 1;
                high = 1;
            }
            res = max({res, low, high});
        }
        return res;
    }
};
```

**Time Complexity:** O(n) (Single pass through the array)  
**Space Complexity:** O(1) (Constant space usage)

---
###
# 169. Majority Element - Leetcode

## Problem Statement
Given an array `nums` of size `n`, return the majority element. The majority element is the element that appears more than `n / 2` times. You may assume that the majority element always exists in the array.

## Coding Platform
**Platform:** Leetcode

## Approach & Solution Explanation
1. **Sorting Method:**
   - Sort the given array `nums` in ascending order.
   - Since the majority element appears more than `n/2` times, after sorting, it must be located at index `n/2`.
   - Iterate through the sorted array while counting occurrences.
   - If an element’s count exceeds `n/2`, return it as the majority element.

2. **Time Complexity:**
   - Sorting takes **O(n log n)**.
   - The loop runs in **O(n)**.
   - Overall complexity: **O(n log n)**.

## Code Implementation
```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        sort(nums.begin(), nums.end());
        int count = 1, value = 0, n = nums.size();
        for(int i = 1; i < n; ++i){
            if(nums[i] == nums[i - 1]){
                ++count;
                if(count > (n / 2)){
                    value = nums[i];
                    break;
                }
            }
        }
        return value;
    }
};
```



