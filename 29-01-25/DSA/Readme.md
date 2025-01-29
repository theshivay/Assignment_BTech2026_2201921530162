# 8. String to Integer (atoi) - Leetcode

## Problem Statement
Implement the `myAtoi(string s)` function, which converts a string to a 32-bit signed integer similar to the C/C++ `atoi` function. The function should discard leading whitespace, handle optional signs (`+/-`), and process numerical characters until a non-numeric character is encountered. If the result exceeds the 32-bit signed integer range, clamp the value accordingly.

### Example
**Input:**
```
s = "   -42"
```
**Output:**
```
-42
```

---

## Platform
Solved on **Leetcode**: [String to Integer (atoi)](https://leetcode.com/problems/string-to-integer-atoi/)

---

## Approach

### Step-by-Step Solution:
1. **Trim Whitespace**: Ignore leading whitespace characters.
2. **Handle Sign**: Check if the first non-whitespace character is `+` or `-` to determine the sign.
3. **Convert Digits**: Convert consecutive numerical characters into an integer.
4. **Handle Overflow**: Ensure the result stays within `[-2^31, 2^31 - 1]` range.

### Code Implementation:
```cpp
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        long long n = s.length();
        long long i = 0;
        long long ans = 0;
        int sign = 1;

        // Ignore leading whitespace
        while (i < n && s[i] == ' ')
            i++;
        
        // Check for sign
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') sign = -1;
            i++;
        }
        
        // Convert number and handle overflow
        while (i < n && (s[i] >= '0' && s[i] <= '9')) {
            ans = ans * 10 + (s[i] - '0');
            i++;

            if (ans * sign > INT_MAX) return INT_MAX;
            if (ans * sign < INT_MIN) return INT_MIN;
        }

        return ans * sign;
    }
};
```

**Time Complexity:** O(n) (Linear scan of string)
**Space Complexity:** O(1) (Constant extra space)

---
###

# 24. Swap Nodes in Pairs - Leetcode 

## Problem Statement
Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)

### Example
**Input:**
```
head = [1,2,3,4]
```
**Output:**
```
[2,1,4,3]
```

---

## Platform
Solved on **Leetcode**: [Swap Nodes in Pairs](https://leetcode.com/problems/swap-nodes-in-pairs/)

---

## Approach

### Iterative Approach
**Algorithm:**
1. Initialize a pointer to traverse the linked list.
2. Swap values of adjacent nodes until the end of the list is reached.
3. Return the modified linked list.

**Code:**
```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* ptr = head;
        
        while (ptr != nullptr && ptr->next != nullptr) {
            int temp = ptr->val;
            ptr->val = ptr->next->val;
            ptr->next->val = temp;
            
            ptr = ptr->next->next;
        }
        
        return head;
    }
};
```

**Time Complexity:** O(n) (Each node is visited once)  
**Space Complexity:** O(1) (No extra space used)

---
###
# 29. Divide Two Integers - Leetcode

## Problem Statement
Given two integers `dividend` and `divisor`, divide them without using multiplication, division, and mod operator. Return the quotient after dividing `dividend` by `divisor`. If the division result exceeds the range of a 32-bit signed integer, return `INT_MAX`.

### Example
**Input:**
```
dividend = 10, divisor = 3
```
**Output:**
```
3
```

---

## Platform
Solved on **Leetcode**: [Divide Two Integers](https://leetcode.com/problems/divide-two-integers/)

---

## Approach

### Direct Division Approach
**Algorithm:**
1. Handle edge case where `dividend = INT_MIN` and `divisor = -1` to prevent overflow.
2. Convert both numbers to `long long` to avoid overflow.
3. Perform integer division and return the result as an integer.

**Code:**
```cpp
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        long long ans=(long long)dividend/(long long)divisor;
        return (int)ans;
    }
};
```

**Time Complexity:** O(1) (Constant time division)  
**Space Complexity:** O(1) (No extra space used)

---


