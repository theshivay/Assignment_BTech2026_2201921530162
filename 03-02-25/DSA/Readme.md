# 1752. Check if Array Is Sorted and Rotated - Leetcode

## Problem Statement
Given an array `nums`, check if it can be sorted in non-decreasing order by performing at most one **rotation**. A rotation means taking some elements from the front and moving them to the back while maintaining order.

### Example:
**Input:**
```
nums = [3,4,5,1,2]
```
**Output:** `true`

**Explanation:** Rotating `[1,2,3,4,5]` to the right gives `[3,4,5,1,2]`, which is a valid rotation.

---

## Platform
Solved on **Leetcode**: [Check if Array Is Sorted and Rotated](https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/)

---

## Approach

### Counting Violations
**Algorithm:**
1. Iterate through the array and count the number of times a value is greater than the next one.
2. If the count is more than 1, return `false` as it cannot be a rotated sorted array.
3. Verify rotation correctness using modular indexing.

**Code:**
```cpp
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        int count  = 0;
        for(int i = 0; i < nums.size() - 1; i++) {
            if(nums[i] > nums[i+1]) {
                count = i + 1;
            }
        }

        int n = nums.size() - 1;
        while(n--) {
            if(nums[(count) % nums.size()] > nums[(count+1) % nums.size()]) 
                return false;
            count++;
        }
        return true;
    }
};
```

**Time Complexity:** O(n) (Single pass through the array)  
**Space Complexity:** O(1) (Constant extra space used)

---
###
# 136. Single Number - Leetcode

## Problem Statement
Given a **non-empty** array of integers `nums`, every element appears **twice** except for one. Find that single number.

### Example:
**Input:**
```
nums = [4,1,2,1,2]
```
**Output:** `4`

**Explanation:** Only `4` appears once, while others appear twice.

---

## Platform
Solved on **Leetcode**: [Single Number](https://leetcode.com/problems/single-number/)

---

## Approach

### Bit Manipulation (XOR)
**Algorithm:**
1. Initialize a variable `result = 0`.
2. Iterate through the array and perform `result ^= num` for each element.
3. Since `x ^ x = 0` and `x ^ 0 = x`, all duplicate numbers cancel out, leaving the unique number.

**Code:**
```cpp
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for (int num : nums) {
            result ^= num;
        }
        return result;
    }
};
```

**Time Complexity:** O(n) (Single pass through the array)  
**Space Complexity:** O(1) (No extra space used)

---
###
# 141. Linked List Cycle - Leetcode

## Problem Statement
Given a linked list, determine if it contains a cycle. A cycle occurs when a node's `next` pointer links back to a previous node in the list, forming a loop.

### Example:
**Input:**
```
head = [3,2,0,-4], pos = 1
```
**Output:** `true`

**Explanation:** The tail node links back to the node at position 1, creating a cycle.

---

## Platform
Solved on **Leetcode**: [Linked List Cycle](https://leetcode.com/problems/linked-list-cycle/)

---

## Approach

### Floyd’s Cycle Detection Algorithm (Tortoise and Hare Algorithm)
**Algorithm:**
1. Use two pointers: `slow` moves one step at a time, `fast` moves two steps.
2. If `fast` ever meets `slow`, a cycle exists.
3. If `fast` reaches `NULL`, no cycle exists.

**Code:**
```cpp
#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) return true;
        }
        return false;
    }
};
```

**Time Complexity:** O(n) (Each node is visited at most twice)  
**Space Complexity:** O(1) (No extra space used)

---


