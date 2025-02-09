# 2364. Count Number of Bad Pairs - Leetcode

## Problem Statement
Given an integer array `nums`, a pair `(i, j)` is considered **good** if `i < j` and `nums[j] - nums[i] == j - i`. Otherwise, it is a **bad** pair. Return the number of bad pairs in the array.

## Coding Platform
- Leetcode

## Approach & Solution
1. Define a hash map to store the frequency of values `nums[i] - i`.
2. Traverse the array while counting the number of occurrences of `nums[i] - i`.
3. Calculate the total number of pairs `n * (n - 1) / 2`.
4. Compute the number of good pairs using the frequency values from the hash map.
5. Subtract the good pairs from the total pairs to get the bad pairs.

**Code:**
```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        long long countBadPairs(vector<int>& nums) {
            unordered_map<long, int> hs;
            long long n = nums.size();
            
            for (long i = 0; i < n; i++) {
                hs[nums[i] - i]++;
            }
            
            long long goodPairs = 0;
            for (auto &i : hs) {
                long long s = i.second;
                goodPairs += (s - 1) * s / 2;
            }
            
            return n * (n - 1) / 2 - goodPairs;
        }
    };
```

## Complexity Analysis
- **Time Complexity**: O(n) (single pass through the array and hash map lookup)
- **Space Complexity**: O(n) (hash map storage for `nums[i] - i` values)

---
###
# 3. Longest Substring Without Repeating Characters - Leetcode

## Problem Statement
Given a string `s`, find the length of the longest substring without repeating characters.

## Coding Platform
- Leetcode

## Approach & Solution
1. Use a vector `alpha` of size 128 (for ASCII characters) initialized to -1 to track the last seen index of each character.
2. Maintain two pointers, `start` and `end`, to represent the window of unique characters.
3. Iterate through the string:
   - If the character is not seen before (`alpha[s[i]] == -1`), update `end`, store the character’s index, and update `result`.
   - If the character is seen before, update `start` to `alpha[s[i]] + 1`, and reset the indices of all characters before `start`.
4. Return the maximum length of the unique substring found.

**Code:**
```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> alpha(128, -1);
        int start = 0, result = 0;

        for (int i = 0; i < s.size(); i++) {
            if (alpha[s[i]] >= start) {
                start = alpha[s[i]] + 1; 
            }
            alpha[s[i]] = i; 
            result = max(result, i - start + 1); 
        }
        return result;
    }
};
```

## Complexity Analysis
- **Time Complexity**: O(n) (Single pass through the string with auxiliary space for character tracking)
- **Space Complexity**: O(1) (Fixed size array of 128 for character storage)
---
###
# 11. Container With Most Water - Leetcode

## Problem Statement
Given an integer array `height` of length `n`, where each element represents the height of a vertical line drawn at position `i`, find two lines that, together with the x-axis, form a container such that it contains the most water.

## Coding Platform
- Leetcode

## Approach & Solution
1. Use two pointers, one at the leftmost and one at the rightmost end of the array.
2. Calculate the area formed by the two pointers and update the maximum area if the new area is greater.
3. Move the pointer pointing to the smaller height towards the other pointer, since moving the taller height won't increase the area.
4. Repeat until both pointers meet.

**Code:**
```cpp
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int maxArea = 0;
        while ( l < r ){
            int area = height[l] < height[r] ? height[l] * (r-l) : height[r] * (r-l);
            if ( area > maxArea ){
                maxArea = area;
            }
        
            if ( height[l] < height[r]) l++;
            else r--;
            }
        return maxArea;
    }
};
```

## Complexity Analysis
- **Time Complexity**: O(n) (since we iterate through the array once using two pointers)
- **Space Complexity**: O(1) (no extra space used)

