# 162. Find Peak Element - Leetcode

## Problem Statement
Given an integer array `nums`, find a peak element and return its index. A peak element is an element that is strictly greater than its neighbors.

### Example:
**Input:**
```
nums = [1,2,3,1]
```
**Output:** `2`

**Explanation:** `nums[2] = 3` is a peak element because it is greater than its neighbors `2` and `1`.

---

## Platform
Solved on **Leetcode**: [Find Peak Element](https://leetcode.com/problems/find-peak-element/)

---

## Approach

### Binary Search Approach
**Algorithm:**
1. Use binary search to find a peak element.
2. If `nums[mid] > nums[mid + 1]`, then the peak lies in the left half.
3. Otherwise, move to the right half.
4. Continue until `low` and `high` converge to the peak index.

**Code:**
```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        while (low < high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] > nums[mid + 1]) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
};
```

**Time Complexity:** O(log n) (Binary search reduces the search space in half each time)  
**Space Complexity:** O(1) (No extra space used)

---
###
# 168. Excel Sheet Column Title - Leetcode

## Problem Statement
Given an integer `columnNumber`, return its corresponding column title as it appears in an Excel sheet.

### Example:
**Input:**
```
columnNumber = 28
```
**Output:** "AB"

**Explanation:** The 28th column corresponds to "AB" in Excel sheet notation.

---

## Platform
Solved on **Leetcode**: [Excel Sheet Column Title](https://leetcode.com/problems/excel-sheet-column-title/)

---

## Approach

### Mathematical Conversion Approach
**Algorithm:**
1. Initialize an empty result string.
2. Decrement `columnNumber` by 1 to handle zero-based indexing.
3. Extract the last character using modulo operation (`columnNumber % 26`) and convert it to a character (`A` to `Z`).
4. Append the character to the result.
5. Divide `columnNumber` by 26 to move to the next significant digit.
6. Repeat until `columnNumber` is zero.
7. Reverse the result string to get the final answer.

**Code:**
```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convertToTitle(int columnNumber) {   
        string res = "";

        while(columnNumber) {
            columnNumber--;
            char current = 'A' + columnNumber % 26;
            res += current;
            columnNumber /= 26;
        }

        reverse(res.begin(), res.end());

        return res;
    }
};
```

**Time Complexity:** O(log n) (Each division step reduces `columnNumber` significantly)  
**Space Complexity:** O(1) (Only a string is used for output)

---
###
# 179. Largest Number - Leetcode

## Problem Statement
Given an array of non-negative integers `nums`, arrange them such that they form the largest number and return it as a string.

### Example:
**Input:**
```
nums = [3,30,34,5,9]
```
**Output:** "9534330"

**Explanation:** The largest possible number formed by arranging elements is "9534330".

---

## Platform
Solved on **Leetcode**: [Largest Number](https://leetcode.com/problems/largest-number/)

---

## Approach

### Custom Sorting Approach
**Algorithm:**
1. Convert all integers to strings.
2. Sort the string array with a custom comparator such that concatenation `a + b` is larger than `b + a`.
3. If the largest element is `0`, return "0".
4. Concatenate all elements to form the final result.

**Code:**
```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool cmp(const string &a, const string &b) {
        return a + b > b + a;
    }
    string largestNumber(vector<int>& nums) {
        vector<string> temp;
        for(int num : nums) temp.push_back(to_string(num));
        sort(temp.begin(), temp.end(), cmp);
        if(temp[0] == "0") return "0";
        string result = "";
        for(const string &s : temp) result += s;
        return result;
    }
};
```

**Time Complexity:** O(n log n) (Sorting takes the most time)  
**Space Complexity:** O(n) (Storing numbers as strings)

---

